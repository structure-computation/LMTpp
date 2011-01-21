#ifndef LMTPP_MUMPS_SOLVER_H
#define LMTPP_MUMPS_SOLVER_H

#include "dmumps_c.h"

#include "containers/mat.h"

using namespace LMT;

/*!
    Cette classe encapsule la décomposition LDL d'une matrice symétrique ou la décomposition LU d'une matrice carré quelconque.
    On l'utilise ainsi :
    
    
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/
struct MUMPS_solver {
    typedef double T;

    MUMPS_solver();

    ~MUMPS_solver();

    /// after that, data in mat won't be used anymore.
    void get_factorization( Mat<double, Sym<>, SparseLine<> > &mat, bool want_free = true, bool is_definite_positive = false );
    /// after that, data in mat won't be used anymore.
    void get_factorization( Mat<double, Gen<>, SparseLine<> > &mat, bool want_free = true );

    /// ...
    template<class TM> 
    void get_factorization( const TM &mat ) { assert(0); /*! TODO */ }
    /// ...
    template<int s>
    void solve( Vec<double, s> &b ) {
    
        if ( myid == 0 ) {
            id.rhs = b.ptr();
            
            id.job = job_solve;
            dmumps_c( &id );
        }
    }

    void free();

    /// attributs:
    DMUMPS_STRUC_C id;
    int myid, ierr; /// MPI
    bool MPI_is_initialized;

  private:
    void init_MPI( int argc = 0, char* argv[] = NULL );
    
    template<class TM>
    void load_matrix( const TM &mat ) {
        assert( 0 );
    }
    
    template<class STR>
    void load_matrix( const Mat<double, STR, SparseLine<> > &mat ) {
        id.n = mat.nb_rows();
        for( int i = 0; i < mat.nb_rows(); ++i )
            id.nz += mat.data[ i ].indices.size();
        id.irn = new int[ id.nz ];
        id.jcn = new int[ id.nz ];
        id.a   = new double[ id.nz ];
        for( int i = 0, index = 0; i < mat.nb_rows(); ++i ) {
            for( int j = 0; j < mat.data[ i ].indices.size(); ++j, index++ ) {
                id.irn[ index ] = i + 1; /// + 1 -> convention Fortran
                id.jcn[ index ] = mat.data[ i ].indices[ j ] + 1;  /// + 1 -> convention Fortran
                id.a[ index ] = mat.data[ i ].data[ j ];
            }    
        }
    }    

    static const int job_init = -1;
    static const int job_end  = -2;
    static const int job_analyse = 1;
    static const int job_factorize = 2;
    static const int job_solve = 3;
    static const int use_comm_word = -987654;
};


#endif // LMTPP_MUMPS_SOLVER_H

