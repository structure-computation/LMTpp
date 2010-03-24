#ifndef EIG_LAPACK_H
#define EIG_LAPACK_H

#include "mat.h"

#ifdef METIL_COMP_DIRECTIVE
#pragma lib_name lapack
#endif

extern "C" int dsyev_(
    char *jobz, char *uplo, int *n, double *a,
    int *lda, double *w, double *work, int *lwork,
    int *info );

namespace LMT {

/*!
    Get eigen values and vector of a symetric matrix using lapack.
    m will be converted to a dense matrix (compatible with lapack).
    you will need to add gfortran and lapack in libraries.

    example:
    \code
        Mat<double,Sym<> > m( 10, 10 );
        m.diag() = range(10);
        m(4,2) = 1.0;

        PRINTN( m );
        Vec<double> eig_val;
        Mat<double> eig_vec;
        get_eig_sym( m, eig_val, eig_vec );

        PRINT( eig_vec );
        PRINT( eig_val );

        m.set( 0.0 );
        m.diag() = eig_val;
        PRINTN( trans( eig_vec ) * m * eig_vec );

    eig_vec.row( i ) to get the i-th eigen vector

    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr

    \keyword Mathématiques/Algèbre linéaire/Vecteurs et valeurs propres

    \author Hugo Leclerc
*/
template<class TM>
void get_eig_sym( const TM &m, Vec<double> &eig_val, Mat<double> &eig_vec ) {
    char jobz = 'V'; // Compute eigenvalues and eigenvectors.
    char uplo = 'L'; // lower
    int n = m.nb_rows();
    Vec<double> A; A.resize( n * n );
    for(unsigned i=0,c=0;i<m.nb_rows();++i)
        for(unsigned j=0;j<m.nb_cols();++j,++c)
            A[ c ] = m( i, j );
    eig_val.resize( n );
    int lwork = 3*n;
    Vec<double> work; work.resize( lwork );
    int info;
    dsyev_( &jobz, &uplo, &n, A.ptr(), &n, eig_val.ptr(), work.ptr(), &lwork, &info );
    if ( info )
        throw "pb with eig with lapack";
    //
    eig_vec.resize( n, n );
    for(int i=0,c=0;i<n;++i)
        for(int j=0;j<n;++j,++c)
            eig_vec( i, j ) = A[ c ];
}

}
#endif // EIG_LAPACK_H

