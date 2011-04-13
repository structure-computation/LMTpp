#ifndef LMTPP_MKL_COMMON_H
#define LMTPP_MKL_COMMON_H

#ifdef WITH_MKL

#ifdef METIL_COMP_DIRECTIVE

#pragma inc_path /opt/intel/Compiler/11.1/064/mkl/include/

#endif

#include <cmath>
#include "mkl_pardiso.h"
#include "mkl_types.h"

#endif

#include "containers/mat.h"

#ifdef WITH_MKL

namespace LMT {

/*!
    on confond le type de stockage CSR et la matrice mais comme on ne gère qu'un seul type de stockage, cela ne pose,pas d eproblème

*/
struct MKL_CSR_matrix {

    MKL_CSR_matrix() : ia( NULL ), ja( NULL ), a( NULL ), n( 0 ), is_one_based_indexing( 1 ) {
        for( unsigned i = 0; i < s_matdes; ++i ) 
            matdes[ i ] = '\0';
    }
    
    ~MKL_CSR_matrix() {
        if ( n )
            free();
    }
    
    template<class TM>
    int init( const TM &mat ) { /// type de matrice inconnue !
         assert( 0 );
         return 0;
    }
    
    template<int sr, int sc>
    int init( const Mat<double, Gen<sr,sc>, SparseLine<Col> > &mat ) {
        
        if ( n )
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
 
            //return 11;  /// matrice quelconque réelle  
          
    }
    
    template<int s>
    int init( const Mat<double, Sym<s,true>, SparseLine<Col> > &mat ) {
    
        if ( n )
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
        //  return -2;
    }
    
    /// Mat<TT,Sym<sr,0>,SparseLine<Col>,void>
    template<int s>
    int init(  const Mat<double, Sym<s,false>, SparseLine<Col> > &mat ) {    
    
        if ( n )
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
            //return -2;
    }    
    
    template<class TM>
    MKL_CSR_matrix( const TM &mat ) { init( mat ); }
    
//     template<int sr, int sc>
//     MKL_CSR_matrix( const Mat<double, Gen<sr,sc>, SparseLine<Col> > &mat ) {
//         init( mat );
//     }
//     
//     template<int s>
//     MKL_CSR_matrix( const Mat<double, Sym<s,true>, SparseLine<Col> > &mat ) {
//         init( mat );
//     }
//     
//     /// Mat<TT,Sym<sr,0>,SparseLine<Col>,void>
//     template<int s>
//     MKL_CSR_matrix(  const Mat<double, Sym<s,false>, SparseLine<Col> > &mat ) {    
//         init( mat );
//     }
    
    /// renvoie le type de la matrice pour le solver PARDISO
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
    virtual void apply_as_conditioner( ) const {}
    
    void free() {
        delete[] ia;
        delete[] ja;
        delete[] a;
        n = 0;
    }

    int *ia;
    int *ja;
    double *a;
    static const unsigned s_matdes = 6;
    char matdes[ s_matdes ];
    int n;
    int is_one_based_indexing; /// 0 <-> faux   ,   1 <-> vrai
};

template<class TM>
int MKL_load_matrix( MKL_CSR_matrix &m, const TM &mat ) {

    assert( 0 );
    return 0;
}

template<int sr, int sc>
int MKL_load_matrix( int **ia, int **ja, double **a, int &n, const Mat<double, Gen<sr,sc>, SparseLine<Col> > &mat ) {

    n = mat.nb_rows();
    unsigned nz = 0;
    for( int i = 0; i < n; ++i )
        nz += mat.data[ i ].indices.size();
    *ia = new int[ n + 1 ];
    *ja = new int[ nz ];
    *a  = new double[ nz ];
    for( int i = 0, index = 0; i < n; ++i ) {
        for( int j = 0; j < mat.data[ i ].indices.size(); ++j, index++ ) {
            (*ja)[ index ] = mat.data[ i ].indices[ j ] + 1; /// + 1 -> convention Fortran
            (*a)[ index ] = mat.data[ i ].data[ j ];
        }    
    }
    
    for( int i = 0, inz = 0; i < n; ++i ) {
        (*ia)[ i ] = inz + 1; /// + 1 -> convention Fortran
        inz += mat.data[ i ].indices.size();
    }
    
    (*ia)[ n ] = nz + 1; /// + 1 -> convention Fortran

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
 
    return 11;  /// matrice quelconque réelle
}    

template<int s>
int MKL_load_matrix( int **ia, int **ja, double **a, int &n, const Mat<double, Sym<s,true>, SparseLine<Col> > &mat ) {

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
    
    *ia = new int[ n + 1 ];
    *ja = new int[ nz ];
    *a  = new double[ nz ];
    for( int i = 0, index = 0; i < n; ++i ) {
        for( int j = 0; j < mat.data[ i ].indices.size(); ++j, index++ ) {
            unsigned p = add_zero_in_diag.find( i );
            if ( p < add_zero_in_diag.size() ) {
                (*ja)[ index ] = i + 1; /// + 1 -> convention Fortran
                (*a)[  index ] = 0;
                add_zero_in_diag.erase_elem_nb( p );
            } else {
                (*ja)[ index ] = mat.data[ i ].indices[ j ] + 1; /// + 1 -> convention Fortran
                (*a)[ index ] = mat.data[ i ].data[ j ];
            }
        }    
    }
    
    for( int i = 0, inz = 0; i < n; ++i ) {
        (*ia)[ i ] = inz + 1; /// + 1 -> convention Fortran
        inz += mat.data[ i ].indices.size();
    }
    
    (*ia)[ n ] = nz + 1; /// + 1 -> convention Fortran
    
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
    return -2;
}

/// Mat<TT,Sym<sr,0>,SparseLine<Col>,void>
template<int s>
int MKL_load_matrix( int **ia, int **ja, double **a, int &n, const Mat<double, Sym<s,false>, SparseLine<Col> > &mat ) {

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

    *ia = new int[ n + 1 ];
    for( int i = 0; i < n; ++i )
        (*ia)[ i ] = offsets[ i ] + 1;
    (*ia)[ n ] = acc + 1; /// + 1 -> convention Fortran
    
    *ja = new int[ acc ];
    *a  = new double[ acc ];
        
    for( int i = 0; i < offsets.size(); ++i ) {
        int d = add_zero_in_diag.find( i );
        if ( d  < add_zero_in_diag.size() ) {
            int pos = offsets[ i ]++;
            (*ja)[ pos ] = i + 1; /// + 1 -> convention Fortran
            (*a)[ pos ] = 0;
            add_zero_in_diag.erase_elem_nb( d );            
        }
        for( int j = 0; j < mat.data[ i ].indices.size(); ++j ) {
            int pos = offsets[ mat.data[ i ].indices[ j ] ]++;
            (*ja)[ pos ] = i + 1; /// + 1 -> convention Fortran
            (*a)[ pos ] = mat.data[ i ].data[ j ];
        }
    }

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
    return -2;
}

};

#endif /// ifdef WITH_MKL

#endif /// LMTPP_MKL_COMMON_H

