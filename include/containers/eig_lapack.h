#ifndef EIG_LAPACK_H
#define EIG_LAPACK_H

#include "mat.h"

#ifdef METIL_COMP_DIRECTIVE
#pragma lib_name lapack
#endif

extern "C" {
    int dsyev_(
    char *jobz, char *uplo, int *n, double *a,
    int *lda, double *w, double *work, int *lwork,
    int *info );
    int dsygv_(
    int *itype, char *jobz, char *uplo, int *n, double *a, int *lda, double *b, int *ldb, 
    double *w, double *work, int *lwork,
    int *info );
}

namespace LMT {

/*!
    Get eigen values (eig_val) and, optionally, vectors (eig_vec) of a real symetric matrix (m) using lapack ( the real symmetric eigen problem being m*(eig_vec) = (eig_val)*(eig_vec) ).
    m will be converted to a dense matrix (compatible with lapack).
    you will need to add gfortran and lapack in libraries.
    eig_vec.row( i ) to get the i-th eigen vector.

    example:
    \code C/C++
        typedef double T;

        Mat< T, Sym<> > ms( 3, 3, 0. );
        Vec<T> eig_val, v, r;
        ms.diag() = 5.;
        ms( 1, 0 ) = 2.; 
        ms( 2, 0 ) = 1.;
        ms( 2, 1 ) = -0.3;
        
        Mat<T> m( ms ), eig_vec;
        
        PRINTN( m );
        
        get_eig_sym( m, eig_val, eig_vec );
        
        PRINT( eig_val );
        PRINTN( eig_vec );
        
        v = eig_vec.row( 0 );
        PRINT( v );
        r = m * v - eig_val[ 0 ] * v;
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

        PRINT( eig_val );
        PRINTN( eig_vec );

        m.set( 0.0 );
        m.diag() = eig_val;
        PRINTN( trans( eig_vec ) * m * eig_vec );

    \keyword Mathématiques/Algèbre linéaire/Vecteurs et valeurs propres

    \author Hugo Leclerc
*/
template<class TM>
void get_eig_val_sym( const TM &m, Vec<double> &eig_val ) {
    char jobz = 'U'; // Compute eigenvalues only.
    char uplo = 'L'; // Lower triangle of m is stored.
    int n = m.nb_rows();
    Vec<double> A; A.resize( n * n );
    for(unsigned j=0,c=0;j<m.nb_cols();++j)
        for(unsigned i=0;i<m.nb_rows();++i,++c)
            A[ c ] = m( i, j );
    eig_val.resize( n );
    int lwork = 3*n-1;
    Vec<double> work; work.resize( lwork );
    int info;
    dsyev_( &jobz, &uplo, &n, A.ptr(), &n, eig_val.ptr(), work.ptr(), &lwork, &info );
    if ( info ) {
        std::cout << "info =  " << info << std::endl;
        throw "pb with eig sym using lapack";
    }
}

template<class TM>
void get_eig_sym( const TM &m, Vec<double> &eig_val, Mat<double> &eig_vec ) {
    char jobz = 'V'; // Compute eigenvalues and eigenvectors.
    char uplo = 'L'; // Lower triangle of m is stored.
    int n = m.nb_rows();
    Vec<double> A; A.resize( n * n );
    for(unsigned j=0,c=0;j<m.nb_cols();++j)
        for(unsigned i=0;i<m.nb_rows();++i,++c)
            A[ c ] = m( i, j );
    eig_val.resize( n );
    int lwork = 3*n-1;
    Vec<double> work; work.resize( lwork );
    int info;
    dsyev_( &jobz, &uplo, &n, A.ptr(), &n, eig_val.ptr(), work.ptr(), &lwork, &info );
    if ( info ) {
        std::cout << "info =  " << info << std::endl;
        throw "pb with eig sym using lapack";
    }
    //
    eig_vec.resize( n, n );
    for(int i=0,c=0;i<n;++i)
        for(int j=0;j<n;++j,++c)
            eig_vec( i, j ) = A[ c ];
}

template<class TM,class T>
Vec<T> solve_using_eig_sym( const TM &m, const Vec<T> &v, T rm_eig_if_inf_rel = 1e-5 ) {
    Vec<T> eig_val;
    Mat<T> eig_vec;
    get_eig_sym( m, eig_val, eig_vec );

    Vec<T> valid = ( abs( eig_val ) > rm_eig_if_inf_rel * norm_inf( eig_val ) );
    Mat<T, Sym<>, SparseLine<> > t( m.nb_rows() );
    t.diag() = valid / ( eig_val + 1 - valid );
    return trans( eig_vec ) * Vec<T>( t * Vec<T>( eig_vec * v ) );
}


/*!
    Get generalized eigen values (eig_val) and, optionally, vectors (eig_vec) of a real generalized symmetric-definite eigenproblem ( of the form A*(eig_vec) = (eig_val)*B*(eig_vec) ) using lapack.
    A and B are assumed to be symmetric and B is also positive definite.
    you will need to add gfortran and lapack in libraries.
    eig_vec.row( i ) to get the i-th generalized eigen vector.
*/
template<class TM1, class TM2> void get_eig_val_gen( const TM1 &A, const TM2 &B, Vec<double> &eig_val ) {
    char jobz = 'N'; // Compute eigenvalues only.
    char uplo = 'L'; // Lower triangles of A and B are stored.
    int n = A.nb_rows();
    Vec<double> A_data; A_data.resize( n * n );
    for(unsigned j=0,c=0;j<A.nb_cols();++j)
        for(unsigned i=0;i<A.nb_rows();++i,++c)
            A_data[ c ] = A( i, j );
    Vec<double> B_data; B_data.resize( n * n );
    for(unsigned j=0,c=0;j<B.nb_cols();++j)
        for(unsigned i=0;i<B.nb_rows();++i,++c)
            B_data[ c ] = B( i, j );
    eig_val.resize( n );
    int lwork = 3*n-1;
    Vec<double> work; work.resize(lwork);
    int info;
    int itype = 1; // Problem type to be solved:
                   // = 1:  A*(eig_vec) = (eig_val)*B*(eig_vec)
                   // = 2:  A*B*(eig_vec) = (eig_val)*(eig_vec)
                   // = 3:  B*A*(eig_vec) = (eig_val)*(eig_vec)
    dsygv_( &itype, &jobz, &uplo, &n, A_data.ptr(), &n, B_data.ptr(), &n, eig_val.ptr(), work.ptr(), &lwork, &info );
    if ( info ) {
        std::cout << "info =  " << info << std::endl;
        throw "pb with eig gen using lapack";
    }
}

template<class TM1, class TM2> void get_eig_gen( const TM1 &A, const TM2 &B, Vec<double> &eig_val, Mat<double> &eig_vec ) {
    char jobz = 'V'; // Compute eigenvalues and eigenvectors.
    char uplo = 'L'; // Lower triangles of A and B are stored.
    int n = A.nb_rows();
    Vec<double> A_data; A_data.resize( n * n );
    for(unsigned j=0,c=0;j<A.nb_cols();++j)
        for(unsigned i=0;i<A.nb_rows();++i,++c)
            A_data[ c ] = A( i, j );
    Vec<double> B_data; B_data.resize( n * n );
    for(unsigned j=0,c=0;j<B.nb_cols();++j)
        for(unsigned i=0;i<B.nb_rows();++i,++c)
            B_data[ c ] = B( i, j );
    eig_val.resize( n );
    int lwork = 3*n-1;
    Vec<double> work; work.resize(lwork);
    int info;
    int itype = 1; // Problem type to be solved:
                   // = 1:  A*(eig_vec) = (eig_val)*B*(eig_vec)
                   // = 2:  A*B*(eig_vec) = (eig_val)*(eig_vec)
                   // = 3:  B*A*(eig_vec) = (eig_val)*(eig_vec)
    dsygv_( &itype, &jobz, &uplo, &n, A_data.ptr(), &n, B_data.ptr(), &n, eig_val.ptr(), work.ptr(), &lwork, &info );
    if ( info ) {
        std::cout << "info =  " << info << std::endl;
        throw "pb with eig gen using lapack";
    }
    //
    eig_vec.resize( n, n );
    for(int i=0,c=0;i<n;++i)
        for(int j=0;j<n;++j,++c)
            eig_vec( i, j ) = A_data[ c ];
}

}
#endif // EIG_LAPACK_H

