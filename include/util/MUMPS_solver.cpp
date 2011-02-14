
#ifdef WITH_MUMPS

#include "mpi.h"

#include "MUMPS_solver.h"

#define ICNTL(I) icntl[(I)-1] /*! macro s.t. indices match documentation */

MUMPS_solver::MUMPS_solver() {
    MPI_is_initialized = false;
    id.n   = 0; /// dimension ou ordre de la matrice
    id.nz  = 0; /// nombre d'éléments non nuls = taille de irn = taille de jcn = taille de a
    id.irn = NULL; /// ligne des éléments non nuls
    id.jcn = NULL;  /// colonne des éléments non nuls
    id.a   = NULL; /// valeur des éléments non nuls 
    id.rhs = NULL; /// valeur des éléments non nuls du vecteur second membre
    myid = -1;
    already_factorized = false;
}

MUMPS_solver::~MUMPS_solver() {
    if ( MPI_is_initialized ) {
        id.job = job_end;
        dmumps_c( &id ); /** Terminate instance */
        ierr = MPI_Finalize();
        //std::cerr << "MPI_Finalize() = " << ierr << std::endl;
    }
}

void MUMPS_solver::free() {
    if ( id.n ) {
        delete[] id.irn;
        delete[] id.jcn;
        delete[] id.a;
        id.n  = 0;
        id.nz = 0;
    }
}

void MUMPS_solver::init_MPI( int argc, char* argv[] ) {

    if ( not( MPI_is_initialized ) ) {
        ierr = MPI_Init(&argc, &argv);
        //std::cerr << "MPI_Init() = " << ierr << std::endl; 
        ierr = MPI_Comm_rank( MPI_COMM_WORLD, &myid );
        //std::cerr << "MPI_Comm_rank() = " << ierr << std::endl; 
        MPI_is_initialized = true;
    }
}

void MUMPS_solver::get_factorization( Mat<double, Sym<>, SparseLine<> > &mat, bool want_free, bool is_definite_positive ) {
//     PRINT(already_factorized);
    if ( already_factorized ) return;
    else already_factorized = true;
    
    init_MPI();
    
    /// initialisation de MUMPS pour un seul processeur
    id.job = job_init; 
    id.par = 1; /// le maître participe à la factorisation
    if ( is_definite_positive )
        id.sym = 1; /// matrice symétrique définie positive
    else
        id.sym = 2; /// matrice symétrique générale
    id.comm_fortran = use_comm_word; /// communicator de MPI
    id.job = job_init;
    dmumps_c( &id );    
    /*! Define the problem on the host */
    if ( myid == 0 ) {
        free();
        /// construction des données nécessaires à la factorisation (excepté a qui peut ne pas être nécessaire )
        load_matrix( mat );
        /*! No outputs */
        id.ICNTL( 1 ) = -1;
        id.ICNTL( 2 ) = -1;
        id.ICNTL( 3 ) = -1;
        id.ICNTL( 4 ) =  0;     
    
        id.job = job_analyse;
        dmumps_c( &id );
        
        id.job = job_factorize;
        dmumps_c( &id );  
          
        if ( want_free )
            mat.free();
    }
}

void MUMPS_solver::get_factorization( Mat<double, Gen<>, SparseLine<> > &mat, bool want_free ) {
    if ( already_factorized ) return;
    else already_factorized = true;

    init_MPI();
    
    /// initialisation de MUMPS pour un seul processeur
    id.par = 1; /// le maître participe à la factorisation
    id.sym = 0; /// matrice générale
    id.comm_fortran = use_comm_word; /// communicator de MPI 
    id.job = job_init;
    dmumps_c( &id );
    /*! Define the problem on the host */
    if ( myid == 0 ) {
        free();
        /// construction des données nécessaires à la factorisation (excepté a qui peut ne pas être nécessaire )
        load_matrix( mat );
        /*! No outputs */
        id.ICNTL( 1 ) = -1;
        id.ICNTL( 2 ) = -1;
        id.ICNTL( 3 ) = -1;
        id.ICNTL( 4 ) =  0;     
    
        id.job = job_analyse;
        dmumps_c( &id );
        
        id.job = job_factorize;
        dmumps_c( &id );    
        
        if ( want_free )
            mat.free();
        
    }
}

#endif
