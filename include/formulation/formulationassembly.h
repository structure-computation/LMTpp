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
            Vec<unsigned> indice_noda;
            Vec<unsigned> local_ddl_to_global_ones;
            unsigned num_formulation;
        };
        // 
        void set_nb_vectors(unsigned nb){
            nb_vectors = nb;
            vectors.resize(nb);
            time_steps.resize(nb);
        }
        //
        FormulationAssembly() {
            set_nb_vectors(unsigned (1));
            time = T(0);
            time_steps[0] = T(1e40);
            mat_already_allocated = false;
            connectivity_calculated =false;
            tol = T(0.000001);
        }
        //
        ~FormulationAssembly() {
            for(unsigned i=0;i<formulations.size();++i)
                delete formulations[i].pb;
        }
        //
        bool add( TM &m, std::string name ) {
            MeshAndForm *maf = formulations.new_elem();
            maf->pb = new PB( m );
            maf->m = &m;
            for(unsigned i=0;;++i) {
                if ( i == maf->pb->nb_formulations() ) {
                    std::cerr << "Error : unknown formulation " << name << std::endl;
                    return false;
                }
                if ( maf->pb->formulation_nb(i)->get_name() == name ) {
                    maf->num_formulation = i;
                    set_nb_vectors( max(nb_vectors, maf->pb->formulation_nb(i)->get_nb_vectors()));
                    formulation(formulations.size()-1)->set_vectors_assembly(vectors);
                    formulation(formulations.size()-1)->set_indice_noda_assembly(maf->indice_noda);
                    return true;
                }
            }
        }
        //
        FormulationAncestor<T> *formulation(unsigned i) {
            return formulations[i].pb->formulation_nb( formulations[i].num_formulation );
        }
        //
        bool solve(T iterative_criterium=T(0)) {
            allocate_matrices();
            assemble();
            solve_system();
            call_after_solve();
            update_variables();
            return true;
        }
        //
        void set_initial_time_step(T ts=T(1)) {
            for (unsigned i=0; i<time_steps.size(); ++i) {
                time_steps[i] = ts;
            }
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->set_initial_time_step(ts);
        }
        //
        T get_next_time_step() const { return time_steps[0]; }
        //
        T get_time() const { return time; }
        //
        void set_time( T ts ) { time = ts; }/// Attention, pilotage a faire soi-meme si utilisation de cette fonction....
        //
        void shift(int nb=1) {
            while (nb--) {
                time += time_steps[0];
                for(unsigned i=nb_vectors-1;i>0;--i) {
                    time_steps[i] = time_steps[i-1];
                    vectors[i] = vectors[i-1];
                }
                time_steps[0] = time_steps[1];
            }
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->set_time( time );
        }
        //
        void unshift(int nb=1) {
            while (nb--) {
                time -= time_steps[1];
                for(unsigned i=0;i<nb_vectors-2;++i) {
                    time_steps[i] = time_steps[i+1];
                    vectors[i] = vectors[i+1];
                }
                time_steps[nb_vectors-1]=time_steps[nb_vectors-2];
                vectors[nb_vectors-1]=vectors[nb_vectors-2];
            }
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->set_time( time );
        }
        //
        void allocate_matrices(bool amd=false) {
            if ( mat_already_allocated )
                return;
            mat_already_allocated = true;
            //
            update_connectivity();
            unsigned nb_ddl_per_node = formulations[0].pb->formulation_nb(formulations[0].num_formulation)->get_nb_nodal_unknowns();
            for(unsigned i=0;i<vectors.size();++i)
                vectors[i].resize( pos.size() * nb_ddl_per_node );
            K.clear();
            K.resize( pos.size() * nb_ddl_per_node );
            K_before_constraints.clear();
            K_before_constraints.resize( pos.size() * nb_ddl_per_node );
            F.resize( pos.size() * nb_ddl_per_node, 0.0 );
            F_before_contraints.resize( pos.size() * nb_ddl_per_node, 0.0 );
            f_reaction.resize( pos.size() * nb_ddl_per_node, 0.0 );
            f_reaction.set(0);
            X_before_contraints.resize( pos.size() * nb_ddl_per_node, 0.0 );
            diag_before_contraints.resize( pos.size() * nb_ddl_per_node, 0.0 );
//            X.resize( pos.size() * nb_ddl_per_node, 0.0 );
        }
        //
        void assemble(bool assemble_mat=true,bool assemble_vec=true) {
            allocate_matrices();
            K.clear();
            K.resize(vectors[0].size());
            F.set(0.0);
            for(unsigned i=0;i<formulations.size();++i) {
                formulation(i)->assemble_clean_mat(K, F, vectors, formulations[i].indice_noda, assemble_mat, assemble_vec );
            }
            F_before_contraints  = F;
            K_before_constraints = K;
            if (K.nb_rows() == 0 )
                M = 0;
            else
                M = max(abs(K.diag()));
            assemble_constraints(K, F, M);
            assemble_sollicitations(K, F);
        }
        //
        void assemble_constraints( Mat<T,Sym<>,SparseLine<> > &K , Vec<T> &F,T M,  bool assemble_mat=true,bool assemble_vec=true) {
            for(unsigned i=0;i<formulations.size();++i) {
                formulation(i)->assemble_constraints(K, F, vectors, formulations[i].local_ddl_to_global_ones, M, assemble_mat, assemble_vec );
            }
        }
        //
        void assemble_sollicitations( Mat<T,Sym<>,SparseLine<> > &K , Vec<T> &F, bool assemble_mat=true,bool assemble_vec=true) {
            for(unsigned i=0;i<formulations.size();++i) {
                formulation(i)->assemble_sollicitations(K, F, vectors, formulations[i].local_ddl_to_global_ones, assemble_mat, assemble_vec );
            }
        }
        //
        void dispatch_results() { ///push result in each f.result
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->get_result() = vectors[0][ formulations[i].local_ddl_to_global_ones ];
            f_reaction = K_before_constraints * vectors[0] - F_before_contraints;

            for(unsigned i=0;i<formulations.size();++i){
                MeshAndForm &maf = formulations[i];
                for(unsigned j=0;j<maf.m->node_list.size();++j)
                    for(unsigned k=0;k<3;++k)
                        maf.m->node_list[j].f_nodal_2[k] = f_reaction[maf.local_ddl_to_global_ones][j*3+k];
                }
        }
        //
        bool solve_system(T iterative_criterium=0.0) {
            vectors[0] = inv(K) * F;
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
            for(unsigned i=0;i<formulations.size();++i){
                formulation(i)->update_variables(vectors, formulations[i].indice_noda);
            }
        }
        //
        void update_variables(T partial_ts) {
            for(unsigned i=0;i<formulations.size();++i){
                formulation(i)->update_variables(partial_ts);
            }
        }
        //
        void get_initial_conditions() {
            for(unsigned i=0;i<formulations.size();++i)
                formulation(i)->get_initial_conditions();
        }
        //
        bool is_unknown(const std::string &s) {
            for(unsigned i=0;i<formulations.size();++i)
                if (formulation(i)->is_unknow(s))
                    return true;
            return false;
        }
        //
        void update_connectivity(){
            if ( connectivity_calculated )
                return;
            connectivity_calculated = true;
            unsigned nb_ddl_per_node = formulations[0].pb->formulation_nb(formulations[0].num_formulation)->get_nb_nodal_unknowns();
            pos.resize( 0 );
            pos.reserve( formulations[0].m->node_list.size());
            Vec<Pvec> pos_skin;
            Vec<unsigned> j_skin;
            pos_skin.resize( 0 );
            pos_skin.reserve( formulations[0].m->node_list.size());
            j_skin.resize( 0 );
            j_skin.reserve( formulations[0].m->node_list.size());
            formulation(0)->update_connectivity();
            MeshAndForm &maf = formulations[0];
            maf.local_unknowns_to_global_ones.resize(0);
            maf.local_unknowns_to_global_ones.resize( maf.m->node_list.size() );
            for(unsigned num_node=0;num_node < maf.m->node_list.size();++num_node) {
                if(maf.m->node_list[num_node].is_on_skin ){
                    pos_skin.push_back( maf.m->node_list[num_node].pos );
                    j_skin.push_back( pos.size() );
                }
                maf.local_unknowns_to_global_ones[num_node] = pos.size() ;
                pos.push_back( maf.m->node_list[num_node].pos );
            }
            maf.local_ddl_to_global_ones.resize(0);
            maf.local_ddl_to_global_ones.reserve( maf.local_unknowns_to_global_ones.size() * nb_ddl_per_node );
            maf.indice_noda = formulations[0].local_unknowns_to_global_ones * formulation(0)->get_nb_nodal_unknowns();
            for(unsigned i=0;i<maf.local_unknowns_to_global_ones.size();++i)
                for(unsigned d=0;d<nb_ddl_per_node;++d)
                    maf.local_ddl_to_global_ones.push_back( maf.local_unknowns_to_global_ones[i] * nb_ddl_per_node + d );
            for(unsigned i=1;i<formulations.size();++i) {
                formulation(i)->update_connectivity();
                MeshAndForm &maf = formulations[i];
                maf.local_unknowns_to_global_ones.resize( maf.m->node_list.size() );
                pos.reserve(pos.size() + maf.m->node_list.size() );
                pos_skin.reserve(pos_skin.size() + maf.m->node_list.size() );
                j_skin.reserve(j_skin.size() + maf.m->node_list.size() );
                for(unsigned num_node=0;num_node < maf.m->node_list.size();++num_node) {
                    const Vec<T,dim>* node_pos = &(maf.m->node_list[num_node].pos);
                    if(maf.m->node_list[num_node].is_on_skin ){
                        for(unsigned j=0;;++j) {
                            if ( j == pos_skin.size() ) { // not found
                                maf.local_unknowns_to_global_ones[num_node]= pos.size();
                                pos_skin.push_back( maf.m->node_list[num_node].pos );
                                j_skin.push_back( pos.size() );
                                pos.push_back( *node_pos );
                                break;
                            }
                            if ( norm_2(pos_skin[j] - *node_pos)< tol ) {
                               maf.local_unknowns_to_global_ones[num_node] = j_skin[j] ;
                                break;
                                }
                            }
                        } else {
                            maf.local_unknowns_to_global_ones[num_node] = pos.size();
                            pos.push_back( *node_pos );
                        }
                    }
                //
                maf.indice_noda = formulations[i].local_unknowns_to_global_ones * formulation(i)->get_nb_nodal_unknowns();
                maf.local_ddl_to_global_ones.resize(maf.local_unknowns_to_global_ones.size() * nb_ddl_per_node );
                for(unsigned j=0;j<maf.local_unknowns_to_global_ones.size();++j)
                    for(unsigned d=0;d<nb_ddl_per_node;++d){
                        maf.local_ddl_to_global_ones[j*nb_ddl_per_node+d] = maf.local_unknowns_to_global_ones[j] * nb_ddl_per_node + d ;
                    }
            }
            pos.fit_memory();
            for(unsigned i=0;i<vectors.size();++i) {
                vectors[i].resize( pos.size() * nb_ddl_per_node );
                vectors[i].set(0);
            }
        }
        //
        Vec<Splitted<MeshAndForm,2> > formulations;
        Mat<T,Sym<>,SparseLine<> > K, K_before_constraints;
        Vec<T> F, F_before_contraints, diag_before_contraints, X_before_contraints, f_reaction;
        unsigned nb_vectors; 
        Vec<Vec<T> > vectors;
        Vec<T> time_steps;
        T M;                                ///< Factor de penalisation
        T time;                             ///< at end of current step
        bool mat_already_allocated;
        bool connectivity_calculated;
        Vec<Pvec > pos;
        double tol;
    };
    
}

#endif // FORMULATION_ASSEMBLY_H
