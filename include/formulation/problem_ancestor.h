//
// C++ Interface: formulation
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_formulation_problem_HEADER
#define LMT_formulation_problem_HEADER

#include "formulation_ancestor.h"

namespace LMT {

/**
 * contain several formulations. Goal : automatic management of several time steps
 */
template<class ScalarType>
class ProblemAncestor {
public:
    typedef ScalarType T;
    virtual unsigned nb_formulations() const { return 0; }
    virtual FormulationAncestor<ScalarType> *formulation_nb(unsigned i) { return NULL; }

    ProblemAncestor() {
        time = T(0);
        has_been_initialised = false;
        verbose = true;
    }
    virtual ~ProblemAncestor() {
        for(unsigned i=0;i<nb_formulations();++i)
            delete formulation_nb(i);
    }
    /**
        cherche les formulations à mettre 
     */
    void iteration() {
        Vec<unsigned> formulations_to_update; formulations_to_update.resize( nb_formulations(), 1 );
        
        if ( not has_been_initialised ) {
            for(unsigned i=0;i<nb_formulations();++i) {
                formulation_nb(i)->allocate_matrices();
                formulation_nb(i)->shift();
                formulation_nb(i)->assemble();
                if ( formulation_nb(i)->assume_constant_matrix ) {
                    if ( formulation_nb(i)->default_iterative_criterium  )
                        formulation_nb(i)->get_precond();
                    else
                        formulation_nb(i)->get_factorization_matrix();
                }
            }
            
            has_been_initialised = true;
        }
        else {
            // quelles formulations mettre à jour ? Si pas de mise à jour, update_variables partielle
            for(unsigned i=0;i<nb_formulations();++i)
                if ( formulation_nb(i)->get_time() != time )
                    formulations_to_update[i] = 0;
                    
            // assemble la matrice uniquement si elle n'est pas supposée constante. assemble le vecteur dans tous les cas
            for(unsigned i=0;i<nb_formulations();++i) {
                if ( formulations_to_update[i] ) {
                    if ( verbose )
                        std::cout << "# Assemble " << formulation_nb(i)->get_name() << std::endl;
                    formulation_nb(i)->shift();
                    formulation_nb(i)->assemble( formulation_nb(i)->assume_constant_matrix==false );
                }
            }
        }
        
        // resoud Ax = B
        for(unsigned i=0;i<nb_formulations();++i) {
            if ( formulations_to_update[i]==0 )
                continue;
            if ( verbose )
                std::cout << "# Solve formulation " << formulation_nb(i)->get_name() << std::endl;
            
            if ( formulation_nb(i)->assume_constant_matrix ) {
                if ( formulation_nb(i)->default_iterative_criterium  )
                    formulation_nb(i)->solve_system_using_precond( formulation_nb(i)->default_iterative_criterium );
                else
                    formulation_nb(i)->solve_system_using_factorization_matrix();
            }
            else {
                //formulation_nb(i)->shift();
                //formulation_nb(i)->assemble( formulation_nb(i)->assume_constant_matrix==false );
                Vec<T> old_vec; 
                if ( formulation_nb(i)->non_linear_iterative_criterium )
                    old_vec.resize( formulation_nb(i)->get_result().size(), T(0) );
                unsigned nb_iterations = 0;
                while ( true ) {
                    formulation_nb(i)->solve_system( formulation_nb(i)->default_iterative_criterium );
                    if ( formulation_nb(i)->non_linear_iterative_criterium == 0 or norm_2( old_vec - formulation_nb(i)->get_result() ) <= formulation_nb(i)->non_linear_iterative_criterium )
                        break;
                    if ( nb_iterations++ >= formulation_nb(i)->max_non_linear_iteration )
                        throw SolveException();
                    old_vec = formulation_nb(i)->get_result();
                    formulation_nb(i)->assemble( formulation_nb(i)->assume_constant_matrix==false );
                }
            }
        }
        
        // mise a jour des variables
        for(unsigned i=0;i<nb_formulations();++i) {
            if ( formulations_to_update[i]==0 ) {
                formulation_nb(i)->update_variables( formulation_nb(i)->get_time() - time );
                formulation_nb(i)->call_after_solve();
            }
            else {
                if ( verbose )
                    std::cout << "# Update formulation " << formulation_nb(i)->get_name() << std::endl;
                formulation_nb(i)->update_variables();
                //formulation_nb(i)->call_after_solve();
            }
        }

        // update this->time
        time = std::numeric_limits<ScalarType>::max();
        for(unsigned i=0;i<nb_formulations();++i)
            time = min( time, formulation_nb(i)->get_time() );
    }

    /// for each formulation, call call_after_solve()
    void call_after_solve() {
        for(unsigned i=0;i<nb_formulations();++i)
            formulation_nb(i)->call_after_solve();
    }
    
    T time;
    bool has_been_initialised, verbose;
};

}

#endif // LMT_formulation_problem_HEADER
