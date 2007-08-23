#ifndef LMTDISPLAYPARAVIEW_H
#define LMTDISPLAYPARAVIEW_H

#include "containers/vec.h"

extern "C" {
void dstev_( const char &jobz, const int &n, double *diag, double *extradiag, double *Z, const int &LDZ, double *WORK, int &INFO );
}

namespace LMT {

template<class TT> struct DelayedAssignementSymTriDiagSource {
    typedef TT T;
    DelayedAssignementSymTriDiagSource( unsigned i, unsigned j, Vec<T> &diag_, Vec<T> &extra_diag_ ) : diag(diag_), extra_diag(extra_diag_) {
        if ( i > j ) swap( i, j );
        this->i = i;
        this->j = j;
    }
    TT get() const {
        if ( i == j )
            return diag[i];
        if ( j - i == 1 )
            return extra_diag[i];
        return TT(0);
    }
    template<class Op,class T2> void apply(const Op &op,const T2 &v) {
        if ( i == j )
            diag[i] = op( diag[i], v );
        else if ( j - i == 1 )
            extra_diag[i] = op( extra_diag[i], v );
        else
            assert( op(T(0),v) == T(0) );
    }
    Vec<T> &diag;
    Vec<T> &extra_diag;
    unsigned i, j;
};


struct TriDiag { };

template<class T>
class Mat<T,Sym<>,TriDiag,void> {
public:
    Mat() {  }
    
    void resize( unsigned n ) {
        diag_.resize(n);
        extra_diag_.resize(n-1);
    }
    
    Vec<T> &diag() { return diag_; }
    const Vec<T> &diag() const { return diag_; }
    
    typedef T RetOpConst;
    T operator()(unsigned i,unsigned j) const {
        if ( i == j ) return diag_[i];
        if ( i > j ) return operator()(j,i);
        if ( j - i > 1 ) return T(0);
        return extra_diag_[i];
    }
    
    typedef DelayedAssignement<DelayedAssignementSymTriDiagSource<T> > RetOp;
    RetOp operator()(unsigned line,unsigned column) {
        return RetOp( DelayedAssignementSymTriDiagSource<T>( line, column, diag_, extra_diag_ ) );
    }

    
    unsigned nb_rows() const { return diag_.size(); }
    unsigned nb_cols() const { return diag_.size(); }
    
    Vec<T> diag_;
    Vec<T> extra_diag_;
};

void get_eigen_values_and_vectors( const Mat<double,Sym<>,TriDiag,void> &m, Vec<double> &eigenvalues, Vec<Vec<double> > &eigenvectors ) {
    //void dstev_( const char &jobz, const int &n, double *diag, double *extradiag, double *Z, const int &LDZ, double *WORK, int &INFO );

    unsigned n = m.nb_rows();
    
    eigenvalues = m.diag_;
    Vec<double> extradiag = m.extra_diag_; extradiag.push_back(0);
    Vec<double> WORK; WORK.resize( 2 * n - 2 );
    Vec<double> Z; Z.resize( n * n );
    
    int INFO;
    dstev_( 'V', n, eigenvalues.ptr(), extradiag.ptr(), Z.ptr(), n, WORK.ptr(), INFO );
    
    eigenvectors.resize(n);
    for(unsigned i=0,cpt=0;i<n;++i) {
        eigenvectors[i].resize(n);
        for(unsigned j=0;j<n;++j)
            eigenvectors[i][j] = Z[cpt++];
    }
}


};

#endif
