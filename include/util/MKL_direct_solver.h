#ifndef LMTPP_MKL_DIRECT_SOLVER_H
#define LMTPP_MKL_DIRECT_SOLVER_H

#ifdef WITH_MKL

#include <cmath>
#include "mkl_pardiso.h"
#include "mkl_types.h"

#endif

#include "containers/mat.h"

using namespace LMT;

/*!
    Cette classe encapsule la décomposition LDL ou Cholesky d'une matrice symétrique ou la décomposition LU d'une matrice carré quelconque à l'aide de la librairie MKL d'intel .
    On l'utilise comme \a LDL_solver ou \a MUMPS_solver :
        
    Pour se servir de cette classe, le plus délicat est la compilation et surtout l'édition des liens.
    
    * Il faut aussi l'option de compilation -DWITH_MUMPS .
    
    REMARQUE : pour l'instant la classe ne gère pas le calcul sur plusieurs noeuds.
        
    
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/

#ifdef WITH_MKL

struct MKL_direct_solver {
    typedef double T;

    MKL_direct_solver();

    ~MKL_direct_solver() {
        free();
    }

    void get_factorization_general() {
        int nrhs, maxfct, mnum, phase, error, msglvl;
        
        maxfct = 1; /** Maximum number of numerical factorizations. */
        mnum = 1; /** Which factorization to use. */
        msglvl = 0; /** No print statistical information in file */
        error = 0; /** Initialize error flag */
        nrhs = 1; /** number of right hand side */
        
        /** -------------------------------------------------------------------- */
        /** .. Reordering and Symbolic Factorization. This step also allocates */
        /** all memory that is necessary for the factorization. */
        /** -------------------------------------------------------------------- */
        phase = 11;
        PARDISO( pt, &maxfct, &mnum, &mtype, &phase, &n, a, ia, ja, &idum, &nrhs, iparm, &msglvl, &ddum, &ddum, &error);
        if ( error ) {
            std::cerr << "\nERROR during symbolic factorization: " <<  error << std::endl;
            free();
            return;
        }
        
        /** -------------------------------------------------------------------- */
        /** .. Numerical factorization. */
        /** -------------------------------------------------------------------- */
        phase = 22;
        PARDISO( pt, &maxfct, &mnum, &mtype, &phase, &n, a, ia, ja, &idum, &nrhs, iparm, &msglvl, &ddum, &ddum, &error );
        if ( error ) {
            std::cerr << "\nERROR during numerical factorization: %d" << error << std::endl;
            free();
            return;
        }
    }
    
    /// factorise la matrice passée en paramètre et libère sa mémoire si want_free == true.
    template<int sr, bool stored_in_upper_part_ >
    void get_factorization( Mat<double, Sym< sr, stored_in_upper_part_>, SparseLine<> > &mat, bool want_free = true, bool is_positive_definite = false ) {
        free();
        load_matrix( mat );
        if ( is_positive_definite )
            mtype = 2;
        get_factorization_general();
        if ( want_free )
            mat.free();
    }
    
    /// factorise la matrice passée en paramètre et libère sa mémoire si want_free == true.
    template<int sr, int sc>
    void get_factorization( Mat<double, Gen<sr,sc>, SparseLine<> > &mat, bool want_free = true ) {
        free();
        load_matrix( mat );
        get_factorization_general();
        if ( want_free )
            mat.free();
    }
    
    /// résout le sytème de second membre b et renvoie le résultat dans b
    template<int s>
    void solve( Vec<double, s> &b, int numbers_of_iterative_refinement = 2 ) {
        double *x;
        int nrhs, maxfct, mnum, phase, error, msglvl;;
        
        maxfct = 1; /** Maximum number of numerical factorizations. */
        mnum = 1; /** Which factorization to use. */
        msglvl = 0; /** No print statistical information in file */
        error = 0; /** Initialize error flag */
        nrhs = 1; /** number of right hand side */
        
        if ( n )
            x = new double[ n ];
        else {
            std::cerr << "\nERROR during solution" << std::endl;
            return;
        }
        phase = 33;
        iparm[7] = numbers_of_iterative_refinement; /** Max numbers of iterative refinement steps. */

        PARDISO( pt, &maxfct, &mnum, &mtype, &phase, &n, a, ia, ja, &idum, &nrhs, iparm, &msglvl, b.ptr(), x, &error );
        if ( error ) {
            std::cerr << "\nERROR during solution: " << error << std::endl;
            delete[] x;
            return;
        }
        
        delete[] x;
    }
    
    void free() {
        if ( n ) {
            delete[] ja;
            delete[] ia;
            delete[] a;
            n = 0;
            
            int nrhs, maxfct, mnum, phase, error, msglvl;
            
            maxfct = 1; /** Maximum number of numerical factorizations. */
            mnum = 1; /** Which factorization to use. */
            msglvl = 0; /** No print statistical information in file */
            error = 0; /** Initialize error flag */
            nrhs = 1; /** number of right hand side */
    
            phase = -1; /** Release internal memory. */
            PARDISO( pt, &maxfct, &mnum, &mtype, &phase, &n, &ddum, ia, ja, &idum, &nrhs, iparm, &msglvl, &ddum, &ddum, &error );
        }
    }

    /// attributs:   ///
    int iparm[64];
    int mtype, n, *ia, *ja;
    void *pt[64];
    double *a;
    double ddum; /** Double dummy */
    int idum; /** Integer dummy. */
    
  //private:
    
    template<class TM>
    void load_matrix( const TM &mat ) {
        assert( 0 );
    }
    
    template<int sr, int sc>
    void load_matrix( const Mat<double, Gen<sr,sc>, SparseLine<Col> > &mat ) {
 
        mtype = 11;  /// matrice quelconque réelle
//         PRINT( "matrice quelconque réelle" );
        n = mat.nb_rows();
        unsigned nz = 0;
        for( int i = 0; i < n; ++i )
            nz += mat.data[ i ].indices.size();
        ia = new int[ n + 1 ];
        ja = new int[ nz ];
        a  = new double[ nz ];
        for( int i = 0, index = 0; i < n; ++i ) {
            for( int j = 0; j < mat.data[ i ].indices.size(); ++j, index++ ) {
                ja[ index ] = mat.data[ i ].indices[ j ];
                a[ index ] = mat.data[ i ].data[ j ];
            }    
        }
        
        for( int i = 0, inz = 0; i < n; ++i ) {
            ia[ i ] = inz;
            inz += mat.data[ i ].indices.size();
        }
        
        ia[ n ] = nz;
        
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
//         std::cout << " mtype = " << mtype << std::endl;    
    }    
    
    template<int s>
    void load_matrix( const Mat<double, Sym<s,true>, SparseLine<Col> > &mat ) {
        mtype == -2;
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
                    ja[ index ] = i;
                    a[  index ] = 0;
                    add_zero_in_diag.erase_elem_nb( p );
                } else {
                    ja[ index ] = mat.data[ i ].indices[ j ];
                    a[ index ] = mat.data[ i ].data[ j ];
                }
            }    
        }
        
        for( int i = 0, inz = 0; i < n; ++i ) {
            ia[ i ] = inz;
            inz += mat.data[ i ].indices.size();
        }
        
        ia[ n ] = nz;
        
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
    void load_matrix( const Mat<double, Sym<s,false>, SparseLine<Col> > &mat ) {
        
        mtype == -2;
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
            ia[ i ] = offsets[ i ];
        ia[ n ] = acc;
        
        ja = new int[ acc ];
        a  = new double[ acc ];
            
        for( int i = 0; i < offsets.size(); ++i ) {
            int d = add_zero_in_diag.find( i );
            if ( d  < add_zero_in_diag.size() ) {
                int pos = offsets[ i ]++;
                ja[ pos ] = i;
                a[ pos ] = 0;
                add_zero_in_diag.erase_elem_nb( d );            
            }
            for( int j = 0; j < mat.data[ i ].indices.size(); ++j ) {
                int pos = offsets[ mat.data[ i ].indices[ j ] ]++;
                ja[ pos ] = i;
                a[ pos ] = mat.data[ i ].data[ j ];
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
    }

};
#endif /// ifdef WITH_MKL

#endif /// LMTPP_MKL_DIRECT_SOLVER_H

