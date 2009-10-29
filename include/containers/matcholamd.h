#ifndef MATCHOLAMD_H
#define MATCHOLAMD_H
#ifdef WITH_CHOLMOD

#include "mat.h"
extern "C" {
    #include <cholmod.h>
}

namespace LMT {

struct SparseCholMod {
    typedef Col TO;
    static const bool col_oriented = true;
    static std::string name() { std::ostringstream os; os << "SparseCholMod col_oriented=" << col_oriented;  return os.str(); }
    static const bool dense = false;
    static const bool sparse = true;
    static const bool skyline = false;

    typedef SparseCholMod Trans;
};

/// Sparse matrix
template <>
class Mat<double, Sym<>, SparseCholMod, void> {
public:
    static const int sr = -1;
    static const int sc = -1;
    static const int static_rows = sr;
    static const int static_cols = sc;
    typedef double T;

    ///
    Mat() : factorized( false ) {
        A = NULL;
        L = NULL;
    }
    /// indices must be ordered and lower part...
    void allocate( const Vec<Vec<unsigned> > &indices ) {
        // start CHOLMOD
        cholmod_start ( &c );
        unsigned nz = 0;
        for ( unsigned i = 0;i < indices.size();++i )
            nz += indices[ i ].size();

        // allocate
        A = cholmod_allocate_sparse (
                indices.size(),     // # of rows of A
                indices.size(),     // # of columns of A
                nz,                 // max # of nonzeros of A
                1,              // TRUE if columns of A sorted, FALSE otherwise
                1,              // TRUE if A will be packed, FALSE otherwise
                1,                  // upper part
                CHOLMOD_REAL,       // CHOLMOD_PATTERN, _REAL, _COMPLEX, or _ZOMPLEX
                &c
        );

        beg_row = ( unsigned * ) A->p;
        row_ind = ( unsigned * ) A->i;
        x = ( double * ) A->x;
        //unsigned *nz_per_row = (unsigned *)A->nz;
        beg_row[ 0 ] = 0;
        for ( unsigned i = 0, cpt = 0; i < indices.size(); ++i ) {
            for ( unsigned j = 0;j < indices[ i ].size() and indices[i][j]<=i; ++j, ++cpt ) {
                row_ind[ cpt ] = indices[ i ][ j ];
                x[ cpt ] = 0.0;
            }
            //nz_per_row[i] = indices[i].size();
            beg_row[ i + 1 ] = cpt;
        }
    }
    /// indices must be ordered and lower part...
    Mat( const Vec<Vec<unsigned> > &indices ) {
        L = NULL;
        allocate( indices );
    }
    ///
    template<class T2>
    Mat( const Mat<T2,Sym<>,SparseLine<> > &mat ) {
        init_from_mat( mat );
    }
private:
    ///
    template<class T2>
    void init_from_mat( const Mat<T2,Sym<>,SparseLine<> > &mat ) {
        Vec<Vec<unsigned> > indices;
        indices.resize( mat.nb_rows() );
        for(unsigned i=0;i<mat.nb_rows();++i)
            indices[i] = mat.data[i].indices;
        //
        L = NULL;
        allocate( indices );
        //
        for(unsigned i=0;i<mat.nb_rows();++i)
            for(unsigned k=0;k<mat.data[i].indices.size();++k)
                operator()( i, mat.data[i].indices[k] ) = mat.data[i].data[k];
    }
public:
    ///
    template<class T2>
    Mat &operator=( const Mat<T2,Sym<>,SparseLine<> > &mat ) {
        free_data();
        init_from_mat( mat );
        return *this;
    }
    ///
    void free_data() {
        if ( A ) {
            cholmod_free_factor ( &L, &c );
            cholmod_free_sparse ( &A, &c );
            cholmod_finish ( &c );
            A = NULL;
            L = NULL;
        }
    }
    ///
    ~Mat() {
        free_data();
    }
    ///
    void clear() {
        for(unsigned i=0;i<beg_row[A->nrow];++i)
            x[i] = 0.0;
        if ( L )
            cholmod_free_factor ( &L, &c );
        L = NULL;
    }

    ///
    bool get_factorization() {
        if ( L )
            return true;
        // analyze
        //c.nmethods = 1;
        //c.method[0].ordering = CHOLMOD_NATURAL;
        //c.postorder = false;

        L = cholmod_analyze( A, &c );
        return cholmod_factorize ( A, L, &c );
    }
    /// ...
    LMT::Vec<double> solve( const LMT::Vec<double> &vec ) {
        get_factorization();

        // allocate
        cholmod_dense * b = cholmod_allocate_dense (
                                vec.size(),    // # of rows of matrix
                                1,             // # of columns of matrix
                                vec.size(),    // leading dimension
                                CHOLMOD_REAL,  // CHOLMOD_REAL, _COMPLEX, or _ZOMPLEX
                                &c );
        // solve
        for ( unsigned i = 0;i < vec.size();++i )
            ( ( double * ) b->x ) [ i ] = vec[ i ];
        cholmod_dense *x = cholmod_solve( CHOLMOD_A, L, b, &c ) ;       /* solve Ax=b */
        LMT::Vec<double> res;
        res.resize( vec.size() );
        for ( unsigned i = 0;i < vec.size();++i )
            res[ i ] = ( ( double * ) x->x ) [ i ];

        // free
        cholmod_free_dense ( &b, &c ) ;
        cholmod_free_dense ( &x, &c ) ;

        return res;
    }
    void print() {
        cholmod_print_sparse( A, const_cast<char *>("A"), &c ) ;         /* print the matrix */
    }

    ///
    struct DelayedAssignementCholMod {
        typedef double T;
        DelayedAssignementCholMod( Mat &mat_, unsigned line_, unsigned col_ ) : mat(mat_), line(line_), col(col_) { }
        T get() const {
            for ( unsigned i = mat.beg_row[ line ];i < mat.beg_row[ line + 1 ];++i )
                if ( mat.row_ind[ i ] == (unsigned)col )
                    return mat.x[i];
            return T(0);
        }
        template <class Op, class TT> void apply( const Op &op, const TT &v ) {
            if ( mat.L ) {
                cholmod_free_factor( &mat.L, &mat.c );
                mat.L = NULL;
            }
            //
            unsigned i;
            for ( i = mat.beg_row[ line ];;++i ) {
                if ( i == mat.beg_row[ line + 1 ] or mat.row_ind[ i ] > col ) {
                    size_t &nz = mat.A->nzmax;
                    // offset
                    cholmod_reallocate_sparse ( nz+1, mat.A, &mat.c ) ;

                    mat.row_ind = ( unsigned * ) mat.A->i;
                    mat.x = ( double * ) mat.A->x;
                    for(unsigned j=line+1;j<=mat.A->nrow;++j) ++mat.beg_row[j];
                    for(int j=nz-2;j>=(int)i;--j) { mat.row_ind[j+1] = mat.row_ind[j]; mat.x[j+1] = mat.x[j]; }
                    // assign
                    mat.row_ind[ i ] = col;
                    mat.x[ i ] = op( 0, v );
                    return;
                }
                if ( mat.row_ind[ i ] == col ) {
                    mat.x[i] = op( mat.x[i], v );
                    return;
                }
            }
        }
        Mat &mat;
        unsigned line, col;
    };
    typedef DelayedAssignement<DelayedAssignementCholMod> RetOp;
    typedef T RetOpConst;

    RetOp operator() ( unsigned line,unsigned column ) {
        if ( line < column )
            return operator() ( column,line );
        return DelayedAssignementCholMod( *this, line, column );
    }
    RetOpConst operator() ( unsigned line,unsigned column ) const {
        if ( line < column )
            return operator() ( column,line );
        for ( unsigned i = beg_row[ line ];i < beg_row[ line + 1 ];++i )
            if ( row_ind[ i ] == column )
                return x[ i ];
        return 0.0;
    }
    unsigned nb_rows() const {
        if ( A )
            return A->nrow;
        return 0;
    }
    unsigned nb_cols() const {
        if ( A )
            return A->ncol;
        return 0;
    }
    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Sym<>,SparseCholMod,int> operator[](const TVEC &v) const {
       return Mat<SubMat<Mat,true ,TVEC>,Sym<>,SparseCholMod,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Sym<>,SparseCholMod,int> operator[](const TVEC &v) {
       return Mat<SubMat<Mat,false,TVEC>,Sym<>,SparseCholMod,int>( *this, v );
    }


    cholmod_common c;
    cholmod_sparse *A;
    cholmod_factor *L;

    unsigned *beg_row;
    unsigned *row_ind;
    double *x;
    bool factorized;
};

}

#endif

#endif // MATCHOLAMD_H
