#ifndef MATUMFPACK_H
#define MATUMFPACK_H

#include "mat.h"
#ifdef WITH_UMFPACK
extern "C" {
#include <umfpack.h>
}
#endif

namespace LMT {

struct SparseUMFPACK {
    static const bool col_oriented = true;
};

/// Sparse matrix
template <>
class Mat<double, Gen<>, SparseUMFPACK, void> {
public:
    static const int sr = -1;
    static const int sc = -1;
    static const int static_rows = sr;
    static const int static_cols = sc;
    typedef double T;

    ///
    Mat() {
        Numeric = NULL;
        r = 0;
    }

    /// creation of a diagonal matrix from a vector
    Mat(const Vec<double> &diag) {
        Numeric = NULL;
        r = diag.size();
        Ap = range(diag.size()+1);
        Ai = range(diag.size());
        Ax=diag;
    }

    /// creation of a matrix from a matrix
    template<class TT,class STU,class STO,class INNER> Mat(const Mat<TT,STU,STO,INNER> &mat) {
        assert( mat.nb_rows() == mat.nb_cols() );

        r = mat.nb_rows();
        Numeric = NULL;
        
        Ax.reserve( r ); Ap.resize( r+1 );
        Ap[0] = 0;
        for(unsigned i=0;i<mat.nb_rows();++i) {
            for(unsigned j=0;j<mat.nb_rows();++j) {
                T val = mat( i, j );
                if ( val ) {
                    Ai.push_back( j );
                    Ax.push_back( val );
                }
            }
            Ap[i+1] = Ai.size();
        }
    }

    /// creation of a matrix from a SparseLine matrix
    template<class TT> Mat(const Mat<TT,Gen<>,SparseLine<>,void> &mat) {
        Vec<Vec<unsigned> > indices;
        indices.resize(mat.data.size());
        for (unsigned i=0; i<indices.size(); ++i)
            indices[i]=mat.data[i].indices;
        allocate(indices);
        unsigned repi =0;
        for (unsigned i=0; i<mat.data.size(); ++i) {
            for (unsigned j=0; j<mat.data[i].data.size(); ++j ){
                Ax[repi+j]= mat.data[i].data[j];
            }
            repi += mat.data[i].data.size();
        }
        Numeric = NULL;
    }


    /// creation of a matrix from a SparseUMFPACK matrix
    template<class TT> Mat(const Mat<TT,Gen<>,SparseUMFPACK,void> &mat) {
        Ap = mat.Ap;
        Ai = mat.Ai;
        Ax = mat.Ax;
        r = mat.r;
        Numeric = NULL; // mat.Numeric;
    }

    /// creation of a matrix from a SparseUMFPACK matrix
    template<class TT> void operator=(const Mat<TT,Gen<>,SparseUMFPACK,void> &mat) {
        Ap = mat.Ap;
        Ai = mat.Ai;
        Ax = mat.Ax;
        r = mat.r;
        Numeric = NULL; // mat.Numeric;
    }
    
    /// creation of a matrix from a matrix
    Mat(const Mat &mat) {
        Ap = mat.Ap;
        Ai = mat.Ai;
        Ax = mat.Ax;
        r = mat.r;
        Numeric = NULL; // mat.Numeric;
    }

    /// creation of a matrix from a matrix
    void operator=(const Mat &mat) {
        Ap = mat.Ap;
        Ai = mat.Ai;
        Ax = mat.Ax;
        r = mat.r;
        Numeric = NULL; // mat.Numeric;
    }
    
    /// indices must be ordered and lower part...
    void allocate( const Vec<Vec<unsigned> > &indices ) {
        r = indices.size();
        
        unsigned nz = 0;
        for(unsigned i=0;i<indices.size();++i)
            nz += indices[i].size();
        
        Ap.resize( indices.size()+1 );
        Ai.resize( nz );
        Ax.resize( nz, 0.0 );
        for(unsigned i=0,cpt=0;i<indices.size();++i) {
            Ap[i] = cpt;
            for(unsigned j=0;j<indices[i].size();++j,++cpt) {
                Ai[cpt] = indices[i][j];
            }
        }
        Ap[ indices.size() ] = nz;
    }
    /// indices must be ordered and lower part...
    Mat( const Vec<Vec<unsigned> > &indices ) {
        Numeric = NULL;
        allocate( indices );
    }


    void resize( const unsigned &size ) {
        // modifie la taille d'une matrice vide
        Ap.resize( size+1, 0 );
        r = size;
    }


    ///
    #ifdef WITH_UMFPACK
    ~Mat() {
        if ( Numeric )
            umfpack_di_free_numeric( &Numeric );
    }
    #endif
    ///
    void clear() { Ax.set( 0.0 ); }

    ///
    #ifdef WITH_UMFPACK
    bool get_factorization() {
        if ( Numeric )
            umfpack_di_free_numeric( &Numeric );
        void *Symbolic;
        umfpack_di_symbolic(r, r, Ap.ptr(), Ai.ptr(), Ax.ptr(), &Symbolic, NULL, NULL) ;
        umfpack_di_numeric(Ap.ptr(), Ai.ptr(), Ax.ptr(), Symbolic, &Numeric, NULL, NULL) ;
        umfpack_di_free_symbolic(&Symbolic);
        return true;
    }
    /// ...
    LMT::Vec<double> solve( const LMT::Vec<double> &vec ) {
        LMT::Vec<double> res;
        res.resize( vec.size() );

        umfpack_di_solve(UMFPACK_At, Ap.ptr(), Ai.ptr(), Ax.ptr(), res.ptr(), vec.ptr(), Numeric, NULL, NULL);
        
        return res;
    }
    void print() {
        umfpack_di_report_matrix (r, r, Ap.ptr(), Ai.ptr(), Ax.ptr(), 1, Control);
    }
    #endif

    ///
    struct DelayedAssignementCholMod {
        typedef double T;
        DelayedAssignementCholMod( Mat &mat_, int line_, int col_ ) : mat(mat_), line(line_), col(col_) { }
        T get() const {
            int i;
            for ( i = mat.Ap[ line ];i < mat.Ap[ line + 1 ];++i )
                if ( mat.Ai[ i ] == col )
                    return mat.Ax[i];
            return 0.0;
        }
        template <class Op, class TT>
        void apply( const Op &op, const TT &v ) {
            TT to_assign = op( 0, v );
            int i;
            for ( i = mat.Ap[ line ];;++i ) {
                if ( i == mat.Ap[ line + 1 ] or mat.Ai[ i ] > col ) { // pas d'elements a cet endroit
                    if ( to_assign == 0 )
                        return;
                    // offset
                    mat.Ai.resize( mat.Ai.size() + 1 );
                    mat.Ax.resize( mat.Ai.size() );
                    for(int j=line+1;j<(int)mat.Ap.size();++j) ++mat.Ap[j];
                    for(int j=mat.Ai.size()-2;j>=i;--j) { mat.Ai[j+1] = mat.Ai[j]; mat.Ax[j+1] = mat.Ax[j]; }
                    // assign
                    mat.Ai[ i ] = col;
                    mat.Ax[ i ] = to_assign;
                    return;
                }
                if ( mat.Ai[ i ] == col ) {
                    mat.Ax[i] = op( mat.Ax[i], v );
                    return;
                }
            }
        }
        Mat &mat;
        int line, col;
    };
    typedef DelayedAssignement<DelayedAssignementCholMod> RetOp;
    typedef T RetOpConst;

    RetOp operator() ( int line, int column ) { return DelayedAssignementCholMod( *this, line, column ); }
    RetOpConst operator() ( int line, int column ) const {
        for ( int i = Ap[ line ];i < Ap[ line + 1 ];++i )
            if ( Ai[ i ] == column )
                return Ax[ i ];
        return 0.0;
    }


    unsigned nb_rows() const { return r; }
    unsigned nb_cols() const { return r; }
    typedef Vec<VecSubMat<Mat, false, ExtractDiag>, MIN( sr, sc ) > RetDiag;
    typedef Vec<VecSubMat<Mat, true , ExtractDiag>, MIN( sr, sc ) > RetDiagConst;
    typedef Vec<VecSubMat<Mat, true , ExtractCol>, sr> RetColConst;
    typedef Vec<VecSubMat<Mat, false, ExtractCol>, sr> RetCol;
    typedef Vec<VecSubMat<Mat, true , ExtractRow>, sc> RetRowConst;
    typedef Vec<VecSubMat<Mat, false, ExtractRow>, sc> RetRow;

    Vec<VecSubMat<Mat, false, ExtractDiag>, MIN( sr, sc ) > diag() { return Vec < VecSubMat<Mat, false, ExtractDiag>, MIN( sr, sc ) > ( *this ); }
    Vec<VecSubMat<Mat, true , ExtractDiag>, MIN( sr, sc ) > diag() const { return Vec < VecSubMat<Mat, true , ExtractDiag>, MIN( sr, sc ) > ( *this ); }
    Vec<VecSubMat<Mat, false, ExtractCol>, sr> col( unsigned i ) { return Vec<VecSubMat<Mat, false, ExtractCol>, sr>( *this, i ); }
    Vec<VecSubMat<Mat, true , ExtractCol>, sr> col( unsigned i ) const { return Vec<VecSubMat<Mat, true , ExtractCol>, sr>( *this, i ); }
    Vec<VecSubMat<Mat, false, ExtractRow>, sc> row( unsigned i ) { return Vec<VecSubMat<Mat, false, ExtractRow>, sr>( *this, i ); }
    Vec<VecSubMat<Mat, true , ExtractRow>, sc> row( unsigned i ) const { return Vec<VecSubMat<Mat, true , ExtractRow>, sr>( *this, i ); }


    template<class T2> Mat &operator*=(const T2 &val) { Ax *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { Ax /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }




    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Gen<sr,sc>,SparseUMFPACK,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Gen<sr,sc>,SparseUMFPACK,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Gen<sr,sc>,SparseUMFPACK,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Gen<sr,sc>,SparseUMFPACK,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }



    Vec<int> Ap, Ai;
    Vec<double> Ax;
    unsigned r;
    void *Numeric;
    #ifdef WITH_UMFPACK
    double Info [UMFPACK_INFO], Control [UMFPACK_CONTROL];
    #endif
};

template<class T> LMT::Vec<T> mul(const Mat<double,Gen<>,SparseUMFPACK> &m,const LMT::Vec<T> &v) {
    LMT::Vec<T> res;
    res.resize( v.size(), 0.0 );

    for(unsigned line=0;line<m.r;++line) {
        for(int j=m.Ap[line];j<m.Ap[line+1];++j)
            res[ line ] += m.Ax[j] * v[ m.Ai[j] ];
    }
    
    return res;
}


}

#endif // MATUMFPACK_H
