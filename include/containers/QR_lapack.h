#ifndef QR_LAPACK_H
#define QR_LAPACK_H

#include "mat.h"

#ifdef METIL_COMP_DIRECTIVE
#pragma lib_name lapack
#endif

extern "C" {
    int dgeqrf_( int* m, int *n, double* a,
    int * lda, double *tau, double *work, int *lwork,
    int *info );
}

namespace LMT {

/*!
    Compute a QR factorization of a real rectangular matrix A.
*/
template<class TM>
void get_QR( const TM &A, Mat<double> &Q, Mat<double> &R ) {
    int m = A.nb_rows();
    int n = A.nb_cols();
    Vec<double> A_data; A_data.resize( m * n );
    for(unsigned j=0,c=0;j<A.nb_cols();++j)
        for(unsigned i=0;i<A.nb_rows();++i,++c)
            A_data[ c ] = A( i, j );
    Vec<double> tau; tau.resize( min(m,n) );
    int lwork = n;
    Vec<double> work; work.resize( lwork );
    int info;
    dgeqrf_( &m, &n, A_data.ptr(), &m, tau.ptr(), work.ptr(), &lwork, &info );
    if ( info ) {
        std::cout << "info =  " << info << std::endl;
        throw "pb with QR using lapack";
    }
    Mat<double> res;
    res.resize( m, n );
    for(int j=0,c=0;j<n;++j)
        for(int i=0;i<m;++i,++c)
            res( i, j ) = A_data[ c ];
    Q.resize( m, m );
    R.resize( min(m,n), n );
    R.set( 0. );
    for(int i=0;i<min(m,n);++i)
        for(int j=i;j<n;++j)
            R( i, j ) = res( i, j );
    Mat<double,Diag<> > I;
    I.resize( m );
    I.set( 1. );
    Q = I;
    for(unsigned i=0;i<min(m,n);++i) {
        Vec<double> v;
        v.resize( m );
        v.set( 0. );
        v[ i ] = 1.;
        for(unsigned j=i+1;j<m;++j)
            v[ j ] = res( j, i );
        Mat<double> H = I - tau[ i ] * vec2matsym( v );
        Q *= H;
    }
    Q.resize( m, min(m,n) );
}

}
#endif // QR_LAPACK_H

