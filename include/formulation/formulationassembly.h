#ifndef FORMULATION_ASSEMBLY_H
#define FORMULATION_ASSEMBLY_H
#include "containers/mat.h"

namespace LMT {
    
    template<class PB>
    struct FormulationAssembly {
        typedef typename PB::TM TM;
        typedef typename PB::T T;
        typedef typename TM::Pvec Pvec;
        static const unsigned dim = TM::dim;
        
        struct MeshAndForm {
            PB *pb;
            TM *m;
            Vec<unsigned> local_unknowns_to_global_ones;
            Vec<unsigned> local_ddl_to_global_ones;
            unsigned num_formulation;
        };
        //
        FormulationAssembly() {
            mat_already_allocated = false;
            tol = 0.000001;
        }
        //
        ~FormulationAssembly() {
            for(unsigned i=0;i<formulations.size();++i)
                delete formulations[i].pb;
        }
        //
        void add( TM &m, std::string name ) {
            MeshAndForm *maf = formulations.new_elem();
            maf->pb = new PB( m );
            maf->m = &m;
            for(unsigned i=0;;++i) {
                if ( i == maf->pb->nb_formulations() ) {
                    std::cerr << "Error : unknown formulation " << name << std::endl;
                    break;
                }
                if ( maf->pb->formulation_nb(i)->get_name() == name ) {
                    maf->num_formulation = i;
                    break;
                }
            }
        }
        //
        FormulationAncestor<T> *formulation(unsigned i) {
            return formulations[i].pb->formulation_nb( formulations[i].num_formulation );
        }
        //
        bool solve(T iterative_criterium=0.0) {
            allocate_matrices();
            assemble();
            solve_system();
            call_after_solve();
            update_variables();
            return true;
        }
        //
        void allocate_matrices(bool amd=false) {
            if ( mat_already_allocated )
                return;
            mat_already_allocated = true;
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->allocate_matrices(amd);
            //
            pos.resize( 0 );
            unsigned nb_ddl_per_node = unsigned nb_ddl_per_node = formulations[0].pb->formulation_nb(formulations[0].num_formulation)->get_nb_nodal_unknowns();
            for(unsigned i=0;i<formulations.size();++i) {
                MeshAndForm &maf = formulations[i];
                maf.local_unknowns_to_global_ones.reserve( maf.m->node_list.size() );
                for(unsigned num_node=0;num_node < maf.m->node_list.size();++num_node) {
                    for(unsigned j=0;;++j) {
                        if ( j == pos.size() ) { // not found
                            maf.local_unknowns_to_global_ones.push_back( j );
                            pos.push_back( maf.m->node_list[num_node].pos );
                            break;
                        }
                        if ( norm_2(pos[j] - maf.m->node_list[num_node].pos)< tol ) {
                            maf.local_unknowns_to_global_ones.push_back( j );
                            break;
                        }
                    }
                }
                //
                maf.local_ddl_to_global_ones.reserve( maf.local_unknowns_to_global_ones.size() * nb_ddl_per_node );
                for(unsigned i=0;i<maf.local_unknowns_to_global_ones.size();++i)
                    for(unsigned d=0;d<nb_ddl_per_node;++d)
                        maf.local_ddl_to_global_ones.push_back( maf.local_unknowns_to_global_ones[i] * nb_ddl_per_node + d );
            }
            //
            K.resize( pos.size() * nb_ddl_per_node );
        }
        //
        void set_initial_time_step(double time=1) {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->set_initial_time_step(time);
        }
        //
        void shift(int nb=1) {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->shift( nb );
        }
        //
        void unshift(int nb=1) {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->unshift( nb );
        }
        //
        void assemble(bool assemble_mat=true,bool assemble_vec=true) {
            K.clear();
            F.set(0.0);
            F_before_contraints.set(0.0);
            X_before_contraints.set(0.0);
            diag_before_contraints.set(0.0);
            F.resize( pos.size() * dim, 0 );
            F_before_contraints.resize( pos.size() * dim, 0 );
            X_before_contraints.resize( pos.size() * dim, 0 );
            diag_before_contraints.resize( pos.size() * dim, 0 );
            X.resize( pos.size() * dim, 0 );
            X.set(0,0);
            for(unsigned i=0;i<formulations.size();++i) {
                formulation(i)->assemble_clean_mat( assemble_mat, assemble_vec );
                
                Mat<T,Sym<>,SparseLine<> > *K_;
                formulation(i)->get_mat( K_ );
                //
                F_before_contraints[ formulations[i].local_ddl_to_global_ones ] += formulation(i)->get_sollicitation();
                X_before_contraints[ formulations[i].local_ddl_to_global_ones ] += formulation(i)->get_result();
                diag_before_contraints[ formulations[i].local_ddl_to_global_ones ] += K_->diag();
            }
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->assemble_constraints( assemble_mat, assemble_vec );
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->assemble_sollicitations( assemble_mat, assemble_vec );
            for(unsigned i=0;i<formulations.size();++i) {
                Mat<T,Sym<>,SparseLine<> > *K_;
                formulation(i)->get_mat( K_ );
                //
                F[ formulations[i].local_ddl_to_global_ones ] += formulation(i)->get_sollicitation();
                K[ formulations[i].local_ddl_to_global_ones ] += *K_;
            }
            for(unsigned i=0;i<formulations.size();++i) {
                Vec<FormulationAncestor<double>::LinearizedConstraint> data;
                data = formulation(i)->get_linearized_constraints();
                Vec<double> u = formulation(i)->get_result();
                for(unsigned j=0;j<data.size();++j)
                    if ( data[j].coeffs.size() == 1 )
                        u[data[j].coeffs[0].num_in_vec] = data[j].val;
                X[ formulations[i].local_ddl_to_global_ones ] = u;
            }
        }
        //
        void dispatch_results() { ///push result in each f.result
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->get_result() = X[ formulations[i].local_ddl_to_global_ones ];
            Mat<T,Sym<>,SparseLine<> > mat;
            mat = K;
            mat.diag() = diag_before_contraints;
            f_reaction = mat * X;
        }
        //
        bool solve_system(T iterative_criterium=0.0) {
            X = inv(K) * F;
            dispatch_results();
            return false;
        }
        //
        void call_after_solve() {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->call_after_solve();
        }
        //
        void update_skin() {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->update_skin();
        }
        //
        void call_after_solve_2() {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->call_after_solve_2();
        }
        //
        void call_after_solve_3() {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->call_after_solve_3();
        }
        //
        void call_after_solve(const Vec<void *> &elem_list) {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->call_after_solve(elem_list);
        }
        //
        void call_after_solve_2(const Vec<void *> &elem_list) {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->call_after_solve_2(elem_list);
        }
        //
        void call_after_solve_3(const Vec<void *> &elem_list) {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->call_after_solve_3(elem_list);
        }
        //
        void update_variables() {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->update_variables();
        }
        //
        void update_variables(T partial_ts) {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->update_variables(partial_ts);
        }
        //
        void get_initial_conditions() {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->get_initial_conditions();
        }
        //
        Vec<MeshAndForm> formulations;
        Mat<T,Sym<>,SparseLine<> > K;
        Vec<T> F, X, F_before_contraints, diag_before_contraints, X_before_contraints, f_reaction;
        bool mat_already_allocated;
        Vec<Pvec> pos;
        double tol;
    };
    
}

#endif // FORMULATION_ASSEMBLY_H
