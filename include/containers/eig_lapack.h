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
    eig_vec.row( i ) to get the i-th eigen vector.

    example:
    \code C/C++
        typedef double T;

        Mat< T, Sym<> > ms( 3, 3, 0. );
        Vec<T> eig_values, v, r;
        ms.diag() = 5.;
        ms( 1, 0 ) = 2.; 
        ms( 2, 0 ) = 1.;
        ms( 2, 1 ) = -0.3;
        
        Mat<T> m( ms ), eigen_vectors;
        
        PRINTN( m );
        
        get_eig_sym( m, eig_values, eigen_vectors );
        
        PRINT( eig_values );
        PRINTN( eigen_vectors );
        
        v = eigen_vectors.row( 0 );
        PRINT( v );
        r = m * v - eig_values[ 0 ] * v;
        PRINT( r );
    
    
    le vecteur r de l'exemple précédent est proche de zéro.
    On aurait pu créer une matrice Mat<T,Sym<> > ms pour la définition puis la convertir en matrice dense en faisant par exemple :
    \code C/C++
        Mat<T> m( ms );
    
    et 
    
    \code C/C++
        Mat<double, Sym<> > m( 10, 10 );
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

template<class TM,class T>
Vec<T> solve_using_eig_val( const TM &m, const Vec<T> &v, T rm_eig_if_inf_rel = 1e-5 ) {
    Vec<T> eig_val;
    Mat<T> eig_vec;
    get_eig_sym( m, eig_val, eig_vec );
    // PRINT( eig_val );

    Vec<T> valid = ( abs( eig_val ) > rm_eig_if_inf_rel * norm_inf( eig_val ) );
    Mat<T, Sym<>, SparseLine<> > t( m.nb_rows() );
    t.diag() = valid / ( eig_val + 1 - valid );
    return trans( eig_vec ) * Vec<T>( t * Vec<T>( eig_vec * v ) );
}

}
#endif // EIG_LAPACK_H

