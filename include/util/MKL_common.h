#ifndef LMTPP_MKL_COMMON_H
#define LMTPP_MKL_COMMON_H

#ifdef WITH_MKL

#ifdef METIL_COMP_DIRECTIVE

#pragma inc_path /opt/intel/Compiler/11.1/064/mkl/include/

#endif

#include <cmath>
#include "mkl_types.h"

#include "mkl_rci.h"
#include "mkl_blas.h"
#include "mkl_spblas.h"
#include "mkl_service.h"

#endif

#include "containers/mat.h"

#ifdef WITH_MKL

namespace LMT {

/*!
    on confond le type de stockage CSR et la matrice mais comme on ne gère qu'un seul type de stockage, cela ne pose pas de problème

*/
struct MKL_CSR_matrix {

    MKL_CSR_matrix() : ia( NULL ), ja( NULL ), a( NULL ), n( 0 ), is_one_based_indexing( 1 ) {
        for( unsigned i = 0; i < s_matdes; ++i ) 
            matdes[ i ] = '\0';
    }
    
    virtual ~MKL_CSR_matrix() {
        free();
    }
    
    template<class TM>
    int init( const TM &mat ) { /// type de matrice inconnue !
         assert( 0 );
         return 0;
    }
    
    template<int sr, int sc>
    int init( const Mat<double, Gen<sr,sc>, SparseLine<Col> > &mat ) {
        
        free();
    
        n = mat.nb_rows();
        unsigned nz = 0;
        for( int i = 0; i < n; ++i )
            nz += mat.data[ i ].indices.size();
        ia = new int[ n + 1 ];
        ja = new int[ nz ];
        a  = new double[ nz ];
        for( int i = 0, index = 0; i < n; ++i ) {
            for( int j = 0; j < mat.data[ i ].indices.size(); ++j, index++ ) {
                ja[ index ] = mat.data[ i ].indices[ j ] + is_one_based_indexing; /// + 1 -> convention Fortran
                a[ index ] = mat.data[ i ].data[ j ];
            }    
        }
        
        for( int i = 0, inz = 0; i < n; ++i ) {
            ia[ i ] = inz + is_one_based_indexing; /// + 1 -> convention Fortran
            inz += mat.data[ i ].indices.size();
        }
        
        ia[ n ] = nz + is_one_based_indexing; /// + 1 -> convention Fortran
    
        matdes[ 0 ] = 'g'; /// general
        matdes[ 1 ] = 'u'; /// upper
        matdes[ 2 ] = 'n'; /// non unit
        if ( is_one_based_indexing ) 
            matdes[ 3 ] = 'f'; /// fortran
        else
            matdes[ 3 ] = 'c'; /// c
        
        return get_mtype();
        //         std::cout << " ia = " ;
        //         for( int i = 0; i <= n; ++i )
        //             std::cout << ia[ i ] << " ";
        //         std::cout << std::endl;
        //         std::cout << " ja = " ;
        //         for( int i = 0; i < nz; ++i )
        //             std::cout << ja[ i ] << " ";
        //         std::cout << std::endl;
        //         std::cout << " a = " ;
        //         for( int i = 0; i < nz; ++i )
        //             std::cout << a[ i ] << " ";
        //         std::cout << std::endl;  
    }
    
    template<int s>
    int init( const Mat<double, Sym<s,true>, SparseLine<Col> > &mat ) {
    
        free();
    
        n = mat.nb_rows();
        
        Vec<int> add_zero_in_diag;
        unsigned nz = 0;
        for( int i = 0; i < n; ++i ) {
            nz += mat.data[ i ].indices.size();
            if ( mat.data[ i ].indices.size() ) {
                if ( mat.data[ i ].indices[ 0 ] != i ) {
                    add_zero_in_diag.push_back( i );
                    nz++;
                }
            } else {
                add_zero_in_diag.push_back( i );
                nz++;            
            }
        }
        
        ia = new int[ n + 1 ];
        ja = new int[ nz ];
        a  = new double[ nz ];
        for( int i = 0, index = 0; i < n; ++i ) {
            for( int j = 0; j < mat.data[ i ].indices.size(); ++j, index++ ) {
                unsigned p = add_zero_in_diag.find( i );
                if ( p < add_zero_in_diag.size() ) {
                    ja[ index ] = i + is_one_based_indexing; /// + 1 -> convention Fortran
                    a[  index ] = 0;
                    add_zero_in_diag.erase_elem_nb( p );
                } else {
                    ja[ index ] = mat.data[ i ].indices[ j ] + is_one_based_indexing; /// + 1 -> convention Fortran
                    a[ index ] = mat.data[ i ].data[ j ];
                }
            }    
        }
        
        for( int i = 0, inz = 0; i < n; ++i ) {
            ia[ i ] = inz + is_one_based_indexing; /// + 1 -> convention Fortran
            inz += mat.data[ i ].indices.size();
        }
        
        ia[ n ] = nz + is_one_based_indexing; /// + 1 -> convention Fortran

        matdes[ 0 ] = 's'; /// symetric
        matdes[ 1 ] = 'u'; /// upper
        matdes[ 2 ] = 'n'; /// non unit
        if ( is_one_based_indexing ) 
            matdes[ 3 ] = 'f'; /// fortran
        else
            matdes[ 3 ] = 'c'; /// c
            
        return get_mtype();
        //         std::cout << " ia = " ;
        //         for( int i = 0; i <= n; ++i )
        //             std::cout << ia[ i ] << " ";
        //         std::cout << std::endl;
        //         std::cout << " ja = " ;
        //         for( int i = 0; i < nz; ++i )
        //             std::cout << ja[ i ] << " ";
        //         std::cout << std::endl;
        //         std::cout << " a = " ;
        //         for( int i = 0; i < nz; ++i )
        //             std::cout << a[ i ] << " ";
        //         std::cout << std::endl;
    }
    
    /// Mat<TT,Sym<sr,0>,SparseLine<Col>,void>
    template<int s>
    int init(  const Mat<double, Sym<s,false>, SparseLine<Col> > &mat ) {    
    
        free();
            
        n = mat.nb_rows();        
        Vec<int> offsets, add_zero_in_diag; 
        offsets.resize( n, 0 );
        
        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < mat.data[ i ].indices.size(); ++j )
                ++offsets[ mat.data[ i ].indices[ j ] ];
            
            if ( mat.data[ i ].indices.size() ) {    
                if ( mat.data[ i ].indices.back() != i ) {
                    ++offsets[ i ];
                    add_zero_in_diag.push_back( i );
                }
            } else {
                ++offsets[ i ];
                add_zero_in_diag.push_back( i );
            }
        }
        
        int acc = 0;
        for( int i = 0; i < offsets.size(); ++i ) {
            int val = offsets[ i ];
            offsets[ i ] = acc;
            acc += val;
        }
    
        ia = new int[ n + 1 ];
        for( int i = 0; i < n; ++i )
            ia[ i ] = offsets[ i ] + 1;
        ia[ n ] = acc + is_one_based_indexing; /// + 1 -> convention Fortran
        
        ja = new int[ acc ];
        a  = new double[ acc ];
            
        for( int i = 0; i < offsets.size(); ++i ) {
            int d = add_zero_in_diag.find( i );
            if ( d  < add_zero_in_diag.size() ) {
                int pos = offsets[ i ]++;
                ja[ pos ] = i + is_one_based_indexing; /// + 1 -> convention Fortran
                a[ pos ] = 0;
                add_zero_in_diag.erase_elem_nb( d );            
            }
            for( int j = 0; j < mat.data[ i ].indices.size(); ++j ) {
                int pos = offsets[ mat.data[ i ].indices[ j ] ]++;
                ja[ pos ] = i + is_one_based_indexing; /// + 1 -> convention Fortran
                a[ pos ] = mat.data[ i ].data[ j ];
            }
        }
        
        matdes[ 0 ] = 's'; /// symetric
        matdes[ 1 ] = 'u'; /// upper
        matdes[ 2 ] = 'n'; /// non unit
        if ( is_one_based_indexing ) 
            matdes[ 3 ] = 'f'; /// fortran
        else
            matdes[ 3 ] = 'c'; /// c
            
        return get_mtype();
        //         PRINT( offsets );
        //         
        //         std::cout << " ia = " ;
        //         for( int i = 0; i <= n; ++i )
        //             std::cout << ia[ i ] << " ";
        //         std::cout << std::endl;
        //         std::cout << " ja = " ;
        //         for( int i = 0; i < acc; ++i )
        //             std::cout << ja[ i ] << " ";
        //         std::cout << std::endl;
        //         std::cout << " a = " ;
        //         for( int i = 0; i < acc; ++i )
        //             std::cout << a[ i ] << " ";
        //         std::cout << std::endl;
    }    
    
    template<class TM>
    MKL_CSR_matrix( const TM &mat ) { init( mat ); }
    
    /*! 
        renvoie le type de la matrice pour le solver PARDISO
        La structure matdes ne peut contenir l'information : matrice symmétrique définie positive. Attention. 
    */
    int get_mtype() const {
        
        char c = matdes[ 0 ];
        if ( c == 'g' ) {
            return 11;  /// matrice quelconque réelle
        } else {
            if ( c == 's' )
                return -2; /// matrice symmétrique
            else
                return 11; /// retour par défaut
        }
    }
    
    /// applique la matrice vue comme un conditionneur
    /// par défaut je ne fais rien
    virtual void apply_as_conditioner( double *x, double *y ) const {}
    
    void free() {
        if ( n ) {
            delete[] ia;
            delete[] ja;
            delete[] a;
            n = 0;
        }
    }

    int *ia;
    int *ja;
    double *a;
    static const unsigned s_matdes = 6;
    char matdes[ s_matdes ];
    int n;
    int is_one_based_indexing; /// 0 <-> faux   ,   1 <-> vrai
    /// sur certaines versions de la MKL, l'indéxation C ne marche pas donc on reste toujours en indexation Fortran
    /// si on change d'avis, les fonctions MKL seront préfixées par mkl_cspblas au lieu mkl_  ( c.f. page 204 de la doc de MKL )
};

/*!
    Ce cas est très particulier. On stocke dans a l'inverse de la diagonale de la matrice passée en paramètre

*/
struct MKL_Jacobi_matrix : public MKL_CSR_matrix {

    template<class TM>
    int init( const TM &mat ) {
         
        n  = mat.nb_rows();
        PRINT( n );
        PRINT( mat );
        a  = new double[ n ];
        for( int i = 0; i < n; ++i ) { 
            double t = mat( i, i );
            if ( t ) 
                a[ i ] = 1 / t;
            else {
                a[ i ] = 0;
                std::cerr << "WARNING MKL_Jacobi_matrix.init() : element " << i << " of diagonal is zero." << std::endl;
            }
        }
        ia = NULL;
        ja = NULL;
        is_one_based_indexing = true;
        matdes[ 0 ] = 'd'; /// diagonal
        matdes[ 1 ] = 'u'; /// upper
        matdes[ 2 ] = 'n'; /// non unit
        if ( is_one_based_indexing ) 
            matdes[ 3 ] = 'f'; /// fortran
        else
            matdes[ 3 ] = 'c'; /// c
         
         return get_mtype();
    }

    template<class TM>
    MKL_Jacobi_matrix( const TM &mat ) { init( mat ); }
    
    virtual void apply_as_conditioner( double *x, double *y ) const {
        for( int i = 0; i < n; ++i )
            y[ i ] = a[ i ] * x[ i ];
    }
};

struct MKL_incomplete_chol_matrix : public MKL_CSR_matrix {

    template<class TM>
    MKL_incomplete_chol_matrix( const TM &mat ) {
        MKL_CSR_matrix::init( mat );
        tmp = new double[ n ]; 
        //std::cout << " constructeur de MKL_incomplete_chol_matrix et n = " << n << std::endl;
    }
    
    virtual ~MKL_incomplete_chol_matrix() {
        delete[] tmp;
    }

    virtual void apply_as_conditioner( double *x, double *y ) const {
        //char tr = 'u'; /// upper storage
        //mkl_dcsrsymv( &tr, const_cast<int*>( &n ), a, ia, ja, x, y ); /// perform y <- Sx where S is symetric
        char uplo = 'u';
        char transa = 't';
        char diag = 'n';
        mkl_dcsrtrsv( &uplo, &transa, &diag, const_cast<int*>( &n ), a, ia, ja, x, tmp );
        transa = 'n';
        mkl_dcsrtrsv( &uplo, &transa, &diag, const_cast<int*>( &n ), a, ia, ja, tmp, y );
    }
    
    double *tmp;
};

};

#endif /// ifdef WITH_MKL

#endif /// LMTPP_MKL_COMMON_H

