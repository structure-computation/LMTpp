#ifndef LMTPP_MKL_ITERATIVE_SOLVER_H
#define LMTPP_MKL_ITERATIVE_SOLVER_H

#ifdef WITH_MKL

#include <cmath>

#include "mkl_rci.h"
#include "mkl_blas.h"
#include "mkl_spblas.h"
#include "mkl_service.h"

#endif

#include "containers/mat.h"

/*!
    Cette classe encapsule la décomposition LDL ou Cholesky d'une matrice symétrique ou la décomposition LU d'une matrice carré quelconque à l'aide de la librairie MKL d'intel .
    On l'utilise comme \a LDL_solver ou \a MUMPS_solver :
        
    Pour se servir de cette classe, le plus délicat est la compilation et surtout l'édition des liens.
    
    * Il faut aussi l'option de compilation -DWITH_MKL .
    
    REMARQUE : pour l'instant la classe ne gère pas le calcul sur plusieurs noeuds.
        
    
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/

#ifdef WITH_MKL


namespace LMT {

enum MKL_precondioner {
    MKL_unknown_precondioner = -1,
    MKL_no_precondioner = 0,
    MKL_Jacobi_precondioner  = 1,
    //LMTpp_precondioner = 100
};

struct MKL_iterative_solver {

    template< class TM>
    MKL_iterative_solver( TM &mat, bool want_free = true ) {
        assert( 0 );
        if ( want_free )
            mat.free();    
    }
    
    template<int sr, bool stored_in_upper_part_>
    MKL_iterative_solver( Mat<double, Sym< sr, stored_in_upper_part_>, SparseLine<> > &mat, bool want_free = true, bool is_positive_definite = false ) {
        
        //precond_id = MKL_no_precondioner;
        m_cond = NULL;
        
        mtype = m.init( mat );
        if ( is_positive_definite )
            mtype = 2;
        if ( want_free )
            mat.free(); 
    }
    
    template<int sr, int sc>
    MKL_iterative_solver( Mat<double, Gen<sr,sc>, SparseLine<> > &mat, bool want_free = true ) {
    
        //precond_id = MKL_no_precondioner;
        m_cond = NULL;
    
        mtype = MKL_load_matrix( &ia, &ja, &a, n, mat );
        if ( want_free )
            mat.free();     
    }

    ~MKL_iterative_solver() {
        free();
        delete m_cond;
    }

    /// permet de libérer la mémoire avant la destruction de l'objet
    void free() {
        m.free();
        if ( m_cond )
            m_cond->free();
    }
    
    void set_no_precondioner() {
        delete m_cond;
    }
    
        
    template<class TPreCond >
    void set_precondioner( MKL_precondioner p, const TPreCond &precond ) {
        //precond_id = p;
        switch( p ) {
            case MKL_unknown_precondioner : 
                ipar[ 10 ] = 0; /// pas de pré-conditionneur
                delete m_cond;
                break;
            case MKL_no_precondioner :  /// pas de pré-conditionneur
                ipar[ 10 ] = 0;
                delete m_cond;
                break;
            case MKL_Jacobi_precondioner :
                ipar[ 10 ] = 1;
                delete m_cond;
                m_cond = new MKL_Jacobi_matrix( precond );
                break;
        }    
    }
    
    /// résout le sytème de second membre b et renvoie le résultat dans b
    template<int s, class CritOperator>
    unsigned solve( const Vec<double, s> &b, Vec<double, s> &x, const CritOperator &crit_op, unsigned max_iter ) {
        
        if ( m.n == 0 ) {
            std::cerr << "Warning Mkl_iterative_solver.solve() : not matrix" << std::endl;
            return 0;
        }
        
        int rci_request;
        double* tmp = new double[ 4 * m.n ];
        /// au cours des calculs,
        /// tmp[0:n-1] est la direction courante
        /// tmp[n:2n-1] est le produit de la matrice et de la direction courante
        /// tmp[2n:3n-1] est le résidu courant
        /// tmp[3n:4n-1] contient l'inverse du pré-conditionneur appliqué au résidu courant ( voir page 2547 de la doc de la MKL )  
        double *temp = new double[ m.n ];
        
        /// initialisation du solver pour matrice symétrique définie positive
        dcg_init( &m.n, x.ptr(), const_cast<double*>( b.ptr() ), &rci_request, ipar, dpar, tmp );
        if ( rci_request ) {
            free_internal_buffer( tmp, temp );
            std::cerr << "Error MKL_iterative_solver.solve() : bad initialization"<< std::endl;
            return 0;
        }

        ipar[4] = max_iter;
        ipar[8] = 1; /// test d'arrêt interne à MKL activé
        ipar[9] = 0; /// pas de test d'arrêt de l'utilisateur
        if ( m_cond )
            ipar[ 10 ] = 1; /// pré-conditionneur activé
            
        dpar[0] = 1e-5; /// precision relative
        /**---------------------------------------------------------------------------*/
        /** Check the correctness and consistency of the newly set parameters         */
        /**---------------------------------------------------------------------------*/
        dcg_check( &m.n, x.ptr(), const_cast<double*>( b.ptr() ), &rci_request, ipar, dpar, tmp );
        if ( rci_request ) {
            free_internal_buffer( tmp, temp );
            std::cerr << "Error MKL_iterative_solver.solve() : bad correctness of parameters of solver"<< std::endl;
            return 0;        
        }
        
        while( true ) {
            dcg( &m.n, x.ptr(), const_cast<double*>( b.ptr() ), &rci_request, ipar, dpar, tmp );
            PRINT( rci_request );
            switch( rci_request ) {
                case 0 :
                    return get_internal_solution( x.ptr(), const_cast<double*>( b.ptr() ), tmp, temp );
                case 1 : { /// compute the vector A*tmp[0] and put the result in vector tmp[n]
                    char tr = 'u';
                    mkl_dcsrsymv( &tr, &m.n, m.a, m.ia, m.ja, tmp, &tmp[m.n] );
                } break;
                case 2 : { /// calcul du résidu 
                    char tr = 'u';
                    mkl_dcsrsymv( &tr, &m.n, m.a, m.ia, m.ja, x.ptr(), temp );  /// temp = A x
                    double a = -1;
                    int incr = 1;
                    daxpy( &m.n, m.a, const_cast<double*>( b.ptr() ), &incr, temp, &incr ); /// temp = temp + (-1) * b 
                    double euclidean_norm = dnrm2( &m.n, temp, &incr );
                    if ( euclidean_norm < dpar[1] )
                        return get_internal_solution( x.ptr(), const_cast<double*>( b.ptr() ), tmp, temp );
                } break;
                case 3 : { /// applique le pré-conditionneur à tmp[2n:3n-1], le résidu courant,  et retourne le résultat dans tmp[3n:4n-1]
                    if ( m_cond )
                        m_cond->apply_as_conditioner( m, tmp + ( 2 * m.n ), tmp + ( 3 * m.n ) );
                    else
                        std::cerr << "WARNING : Mkl_iterative_solver.solve() : you want to apply a precondioner but it's not defined" << std::endl;
                } break;
                default :
                    free_internal_buffer( tmp, temp );
                    std::cerr << "Error MKL_iterative_solver.solve() : dcg() bugs..."<< std::endl;
                    return 0; 
            }
        }
        
        free_internal_buffer( tmp, temp );
        return 0;
    }
    
    /// résout le sytème de second membre b et renvoie le résultat dans b
//     template<int s, class TPreCond, class CritOperator>
//     unsigned solve( const TPreCond &precond, const Vec<double, s> &b, Vec<double, s> &x, const CritOperator &crit_op, unsigned max_iter ) {
// 
//     }
    
    void free_internal_buffer( double *b, double *b2 ) {
        delete[] b;
        delete[] b2;
        MKL_FreeBuffers();    
    }
    
    unsigned get_internal_solution( double *b, double *x, double *tempon, double *tempon2 ) {
        int itercount, rci_request;
        
        dcg_get( &m.n, x, b, &rci_request, ipar, dpar, tempon, &itercount );
        free_internal_buffer( tempon, tempon2 );
        return (unsigned) itercount;
    }
    
    /// *** attributs *** ///
    int ipar[128];
    double dpar[128];
    int mtype;
    //MKL_precondioner precond_id;
    MKL_CSR_matrix m, *m_cond;
};

};

#endif /// ifdef WITH_MKL

#endif /// LMTPP_MKL_ITERATIVE_SOLVER_H

