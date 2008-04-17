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
#ifndef LMT_formulation_HEADER
#define LMT_formulation_HEADER

#include "mesh/mesh.h"
#include "containers/heterogeneouspack.h"
#include "convergence_criteria.h"
#include "constraint.h"
#include "sollicitation.h"
#include "util/symamd.h"
#include "util/solveLDL.h"
#include "formulation/formulation_ancestor.h"
#include "containers/matcholamd.h"
#include "containers/matumfpack.h"

namespace LMT {

/**
*/
template<class NameFormulation,unsigned dim,class T,class NameVariant=DefaultBehavior>
class CaracFormulation {
public:
    static const unsigned nb_nodal_unknowns = 0; /// number of nodal unknowns
    static const unsigned nb_global_unknowns = 0; /// number of global unknowns
    static const int nb_vectors = 2; /// if -1, nb is dynamic
    static const int nb_matrices = 2; /// if -1, nb is dynamic
    static const bool matrix_will_be_definite_positive = true; /// in order to choose resolution algorithm (but if lagrange constraints,
                                                               /// matrix will not be definite_positive).
    static const bool all_vector_should_be_cleared = false; /// 

    template<unsigned num_mat,unsigned inner=0> struct NodalMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
    };
    template<unsigned num_mat,unsigned inner=0> struct GlobalMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
    };
};
/**
*/
template<class NameFormulation,class TElem,class NameVariant,class T>
class CaracFormulationForElement {
public:
    static const unsigned nb_elementary_unknowns = 0; /// number of unknowns associated to this element
    template<unsigned num_mat,unsigned inner=0> struct ElemMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
    };
};

/**

*/
template<class TM,class NameFormulation,class NameVariant=DefaultBehavior,class ScalarType_=typename TM::Tpos,bool wont_add_nz=false>
class Formulation : public FormulationAncestor<ScalarType_> {
public:
    typedef ScalarType_ ScalarType;
    typedef CaracFormulation<NameFormulation,TM::dim,ScalarType,NameVariant> Carac;
    static const unsigned nb_nodal_unknowns = Carac::nb_nodal_unknowns;
    static const unsigned nb_global_unknowns = Carac::nb_global_unknowns;
    static const unsigned nb_vectors = Carac::nb_vectors + 16;
    static const unsigned nb_der_var = Carac::nb_der_var;
    typedef TM TMESH;
    typedef typename FormulationAncestor<ScalarType>::LinearizedConstraint LinearizedConstraint;
    
    Formulation(TM &mm) {
        m = &mm;
        mat_def_pos_if_sym = Carac::matrix_will_be_definite_positive;
        time = 0.0;
        time_steps = 1e40;
        initialized = false;
        user_want_pierre_precond = true;
        this->order_integration_when_integration_totale = Carac::order_integration;
    
        max_diag = 0;
        time_symbol = Codegen::symbol("time");
        symbols.push_back( time_symbol );
        
        want_amd = false;
    }
    virtual std::string get_name() const { return Carac::name(); }
    virtual void set_mesh( void *m_ ) { m = reinterpret_cast<TM *>( m_ ); }

private:
    template<unsigned nm,unsigned n,unsigned tne> struct MatCaracElem {
        typedef typename TM::TElemList::template SubType<n>::T TE;
        typedef CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType> CFE;
        static const bool symm = ((CFE::nb_elementary_unknowns+nb_nodal_unknowns)==0 || CFE::template ElemMatricesCarac<nm>::symm) && MatCaracElem<nm,n+1,tne>::symm;
        static const bool herm = ((CFE::nb_elementary_unknowns+nb_nodal_unknowns)==0 || CFE::template ElemMatricesCarac<nm>::herm) && MatCaracElem<nm,n+1,tne>::herm;
        static const bool diag = ((CFE::nb_elementary_unknowns+nb_nodal_unknowns)==0 || CFE::template ElemMatricesCarac<nm>::diag) && MatCaracElem<nm,n+1,tne>::diag;
    };
    template<unsigned nm,unsigned tne> struct MatCaracElem<nm,tne,tne> {
        static const bool symm = true;
        static const bool herm = true;
        static const bool diag = true;
    };
public:
    template<unsigned num_mat> struct MatCarac {
        static const bool symm = 
            (nb_nodal_unknowns==0 || Carac::template NodalMatricesCarac<num_mat>::symm) &&
            (nb_global_unknowns==0 || Carac::template GlobalMatricesCarac<num_mat>::symm) &&
            MatCaracElem<num_mat,0,TM::TElemList::nb_sub_type>::symm;
        static const bool herm = 
            (nb_nodal_unknowns==0 || Carac::template NodalMatricesCarac<num_mat>::herm) &&
            (nb_global_unknowns==0 || Carac::template GlobalMatricesCarac<num_mat>::herm) &&
            MatCaracElem<num_mat,0,TM::TElemList::nb_sub_type>::herm;
        static const bool diag = 
            (nb_nodal_unknowns==0 || Carac::template NodalMatricesCarac<num_mat>::diag) &&
            (nb_global_unknowns==0 || Carac::template GlobalMatricesCarac<num_mat>::diag) &&
            MatCaracElem<num_mat,0,TM::TElemList::nb_sub_type>::diag;
    };
private:
    struct GetNbUnknownByElement {
        template<class TE,unsigned nt> void operator()(const StructForType<TE> &se,const Number<nt> &nv,unsigned *nb_elem_of_type,
                unsigned &size,unsigned *nb_unknowns_for_type) const {
            nb_unknowns_for_type[nt] = CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::nb_elementary_unknowns;
            size += nb_elem_of_type[nt] * nb_unknowns_for_type[nt];
        }
    };
    struct ResizeMat {
        struct GetNZ {
            template<class TE> void operator()(const TE &e,Formulation &f,Vec<Vec<unsigned> > &v) const {
                assert( (CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::nb_elementary_unknowns) == 0 );
                if ( nb_nodal_unknowns ) {
                    for(unsigned i=0;i<TE::nb_nodes;++i) {
                        unsigned a = f.indice_noda[ f.m->node_list.number(*e.node(i)) ];
                        for(unsigned j=0;j<TE::nb_nodes;++j) {
                            unsigned b = f.indice_noda[ f.m->node_list.number(*e.node(j)) ];
                            if ( std::find(v[a].begin(),v[a].end(),b)==v[a].end() ) {
                                for(unsigned k=0;k<nb_nodal_unknowns;++k)
                                    for(unsigned l=0;l<nb_nodal_unknowns;++l)
                                        v[a+k].push_back( b+l );
                            }
                        }
                    }
                }
            }
        };
        
        template<class TM2> void operator()(TM2 &m,unsigned s,Formulation &f) const {
            Vec<Vec<unsigned> > v; v.resize( s );
            for(unsigned i=0;i<s;++i) v[i].reserve( 32 );
            apply( f.m->elem_list, GetNZ(), f, v ); // loop on all elements to find non zero terms
            for(unsigned i=0;i<s;++i) std::sort( v[i].begin(), v[i].end() );

            //             std::cout << "size -> " << s << std::endl;
            m.allocate(v);
            // m.resize(s,s);
        }
        // /// this kind of matrice need pre-allocation
        //         void operator()(Mat<double, Sym<>, SparseCholMod> &m,unsigned s,Formulation &f) const {
        //             Vec<Vec<unsigned> > v; v.resize( s );
        //             for(unsigned i=0;i<s;++i) v[i].reserve( 32 );
        //             apply( f.m->elem_list, GetNZ(), f, v ); // loop on all elements to find non zero terms
        //             for(unsigned i=0;i<s;++i) std::sort( v[i].begin(), v[i].end() );
        // 
        //             m.allocate(v);
        //             //m.print();
        //         }
    };
    
    struct ClearMat { template<class TM2> void operator()(TM2 &m) const { m.clear(); } };
    struct GetLink {
        template<class TE> void operator()(const TE &e,const TM &m,Vec<Vec<unsigned> > &v) const {
            for(unsigned i=0;i<TE::nb_nodes;++i) {
                unsigned a = m.node_list.number(*e.node(i));
                for(unsigned j=0;j<TE::nb_nodes;++j) {
                    unsigned b = m.node_list.number(*e.node(j));
                    if ( std::find(v[a].begin(),v[a].end(),b)==v[a].end() )
                        v[a].push_back( b );
                }
            }
        }
    };
public:
    struct PackMatrices {
        template<unsigned n> struct SubType {
            typedef typename AlternativeOnType< (n<Carac::nb_matrices),
                void,
                Mat<
                    ScalarType,
                    typename AlternativeOnType< MatCarac<n>::diag,
                        typename AlternativeOnType< MatCarac<n>::symm + 2 * MatCarac<n>::herm,
                            Gen<>,
                            Sym<>,
                            Herm<>
                        >::T,
                        Diag<>
                    >::T,
                    typename AlternativeOnType< MatCarac<n>::symm,
                        typename AlternativeOnType< wont_add_nz, SparseLU,
                            #ifdef WITH_UMFPACK
                            SparseUMFPACK
                            #else
                            SparseLU
                            #endif
                        >::T,
                        typename AlternativeOnType< wont_add_nz, SparseLine<>,
                            #ifdef WITH_CHOLMOD
                            SparseCholMod
                            #else
                            SparseLine<>
                            #endif
                        >::T
                    >::T
                >
            >::T T;
        };
    };
    typedef typename PackMatrices::template SubType<0>::T TMAT0;
    /**
     * Set matrix and vector sizes...
     * if amd, use a permutation able to minimize fill-in sparse mat... in this case, use chol_factorize and solve_using_chol_factorize
     */
    virtual void allocate_matrices() {
        mat_has_been_allocated_with_symamd = want_amd;
        
        unsigned size = 0;
        // global unknowns
        unsigned ng = nb_global_unknowns;
        size += ng;
        // nodal unknowns
        unsigned nn = m->node_list.size() * nb_nodal_unknowns;
        size += nn;
        // elem unknowns. nb_elem_of_type will = nb_unknowns
        unsigned nb_elem_of_type[ TM::TElemList::nb_sub_type ];
        unsigned nb_unknowns_for_type[ TM::TElemList::nb_sub_type ];
        m->elem_list.get_sizes(nb_elem_of_type);
        TM::TElemList::apply_static_with_n( GetNbUnknownByElement(), nb_elem_of_type, size, nb_unknowns_for_type );
        
        for(unsigned i=0;i<vectors.size();++i) vectors[i].resize( size );
        sollicitation.resize( size );

        
        // indices
        indice_glob = 0;
        unsigned nnu = nb_nodal_unknowns;
        unsigned ngu = nb_global_unknowns;
        indice_noda = range( m->node_list.size() ) * nnu + ngu;
        unsigned ind = m->node_list.size() * nnu + ngu;
        unsigned nb_unk_elem = 0;
        
        for(unsigned i=0,ne=0;i<TM::TElemList::nb_sub_type;++i) {
            indice_elem[i] = range( ne, ne + nb_elem_of_type[i] ) * nb_unknowns_for_type[i] + ind;
            ne += nb_elem_of_type[i];
            ind += nb_unknowns_for_type[i] * nb_elem_of_type[i];
            nb_unk_elem += nb_unknowns_for_type[i];
        }
        
        if ( want_amd ) {
            assert( indice_glob==0 ); // not managed
            assert( nb_unk_elem==0 ); // not managed
            Vec<Vec<unsigned> > ind; ind.resize( m->node_list.size() );
            apply( m->elem_list, GetLink(), *m, ind );
            for(unsigned i=0;i<ind.size();++i)
                std::sort( ind[i].begin(), ind[i].end() );
            Vec<unsigned> perm = symamd( ind );
            Vec<unsigned> inv_perm; inv_perm.resize(perm.size());
            for(unsigned i=0;i<perm.size();++i)
                inv_perm[perm[i]] = i;
            indice_noda = inv_perm * nnu;
        }

        // matrice allocation
        matrices.apply( ResizeMat(), size, *this );

    }
    virtual void shift(int nb=1) {
        while (nb--) {
            time += time_steps[0];
            for(unsigned i=nb_vectors-1;i>0;--i) {
                time_steps[i] = time_steps[i-1];
                vectors[i] = vectors[i-1];
            }
            time_steps[0] = time_steps[1];
        }
    }
    virtual void unshift(int nb=1) {
        while (nb--) {
            time -= time_steps[1];
            for(unsigned i=0;i<nb_vectors-2;++i) {
                time_steps[i] = time_steps[i+1];
                vectors[i] = vectors[i+1];
            }
            time_steps[nb_vectors-1]=time_steps[nb_vectors-2];
            vectors[nb_vectors-1]=vectors[nb_vectors-2];
        }
    }
private:
    template<bool assemble_mat,bool assemble_vec>
    struct AssembleNode {
        template<class TN> void operator()(const TN &n,const Vec<unsigned> &indice_noda,Formulation &f) const {
            if ( nb_global_unknowns ) {
                if ( nb_nodal_unknowns ) {
                    unsigned ind[ 2 ] = { indice_noda[f.m->node_list.number(n)], f.indice_glob };
                    add_nodal_matrix( f, n, Number<MatCarac<0>::symm>(), Number<assemble_mat>(), Number<assemble_vec>(), ind );
                }
                else
                    add_nodal_matrix( f, n, Number<MatCarac<0>::symm>(), Number<assemble_mat>(), Number<assemble_vec>(), &f.indice_glob );
            }
            else
                add_nodal_matrix( f, n, Number<MatCarac<0>::symm>(), Number<assemble_mat>(), Number<assemble_vec>(), &indice_noda[f.m->node_list.number(n)] );
        }
    };
    template<bool assemble_mat,bool assemble_vec>
    struct AssembleElem {
        //         template<class TE,unsigned n> void adsem(Formulation &f,const Number<true> &n1,const Number<false> &n2,
        //                 const TE &e,void *, const Number<n> &nn,unsigned *in) const {
        //                     std::cout << n << std::endl;
        //         }
        template<class TE,class TCE,unsigned n> void adsem(Formulation &f,const Number<true> &n1,const Number<false> &n2,
                const TE &e,const TCE *ce, const Number<n> &nn,unsigned *in) const {
            //               #warning
             add_skin_elem_matrix( f, Number<MatCarac<0>::symm>(), Number<assemble_mat>(), Number<assemble_vec>(), e, *ce, nn, in );
        }
        template<class TE,unsigned n,unsigned n2> void ass_skin_elem(const TE &e,unsigned *in,Formulation &f,
                    const Number<n> &nn,const Number<n2> &nn2) const { // sub_mesh(Number<1>()).
            ass_skin_elem( e, in, f, Number<n+1>(), nn2 );
            if ( f.m->sub_mesh(Number<1>()).get_parents_of( *f.m->get_children_of(e,Number<1>())[n] ).size()!=1 )
                return;
            //PRINTTYPE( typeid( typename TypeChildrenElement<typename TE::NE,1,n>::T ) );
            //typedef typename TM::TSkin::template TElem<typename TypeChildrenElement<typename TE::NE,1,n>::T>::TE TCH;
            //PRINT( n );
            //PRINTTYPE( typeid( typename TE::NE ) );
            
            typedef typename TM::template SubMesh<1>::T TSubMesh;
            typedef typename TSubMesh::template TElem<typename TypeChildrenElement<typename TE::NE,1,n>::T>::TE TCH;
            TCH *child_elem = static_cast<TCH *>( f.m->get_children_of(e,Number<1>())[n] );
            adsem( f, Number<true>(),Number<false>(), e, child_elem, nn, in );
        }
        template<class TE,unsigned n> void ass_skin_elem(const TE &e,unsigned *in,Formulation &f,const Number<n> &nn,const Number<n> &nn2) const {}
        template<class TE> void operator()(const TE &e,const Vec<unsigned> &indice_noda,const Vec<unsigned> *indice_elem,Formulation &f ) const {
            unsigned in[ TE::nb_nodes + 1 + nb_global_unknowns ];
            
            if ( nb_nodal_unknowns ) 
                for(unsigned i=0;i<TE::nb_nodes;++i)
                    in[i] = indice_noda[ f.m->node_list.number(*e.node(i)) ];
            
            typedef CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType> CFE;
            if ( CFE::nb_elementary_unknowns ) 
                in[ TE::nb_nodes * (nb_nodal_unknowns!=0) ] = indice_elem[TE::num_in_elem_list][e.number];
            
            if ( nb_global_unknowns )
                in[ TE::nb_nodes * (nb_nodal_unknowns!=0) + (CFE::nb_elementary_unknowns!=0) ] = f.indice_glob;

            add_elem_matrix( f, Number<MatCarac<0>::symm>(), Number<assemble_mat>(), Number<assemble_vec>(), e, in );
            
            // skin elements
            if ( not f.assume_skin_not_needed )
                ass_skin_elem( e, in, f, Number<0>() , Number<NbChildrenElement<typename TE::NE,1>::res>() );
        }
    };
public:
    Codegen::Ex::MapExNum val_sub_sym( const Codegen::Ex::SetEx &sub_symbols ) const {
        using namespace Codegen;
        Ex::MapExNum res;
        for(Ex::SetEx::const_iterator iter=sub_symbols.begin();iter!=sub_symbols.end();++iter) {
            std::string str = iter->to_string();
            if ( str=="time" )
                res[ *iter ] = time;
            else
                std::cout << "Unknown symbol : " << str << std::endl;
        }
        return res;
    }
    ///
    virtual void assemble_clean_mat(bool assemble_mat=true,bool assemble_vec=true) {
        if ( not initialized ) { // old_vectors
            get_initial_conditions();
        }

        if ( assemble_vec ) // preinitialisation
            sollicitation.set(0.0);
        if ( not this->assume_skin_not_needed )
            m->update_skin();

        if ( assemble_mat ) {
            matrices.apply( ClearMat() );
            if ( assemble_vec ) {
                add_global_matrix( *this, Number<true>(), Number<true>(), indice_glob ); // global
                apply( m->node_list, AssembleNode<true,true >(), indice_noda, *this ); // nodal
                apply( m->elem_list, AssembleElem<true,true >(), indice_noda, indice_elem, *this ); // element (and skin elements)
            }
            else {
                add_global_matrix( *this, Number<true>(), Number<false>(), indice_glob ); // global
                apply( m->node_list, AssembleNode<true,false>(), indice_noda, *this ); // nodal
                apply( m->elem_list, AssembleElem<true,false>(), indice_noda, indice_elem, *this); // element (and skin elements)
            }
        }
        else {
            if ( assemble_vec ) {
                add_global_matrix( *this, Number<false>(), Number<true>(), indice_glob ); // global
                apply( m->node_list, AssembleNode<false,true >(), indice_noda, *this ); // nodal
                apply( m->elem_list, AssembleElem<false,true >(), indice_noda, indice_elem, *this ); // element (and skin elements)
            }
            else {
                add_global_matrix( *this, Number<false>(), Number<false>(), indice_glob ); // global
                apply( m->node_list, AssembleNode<false,false>(), indice_noda, *this ); // nodal
                apply( m->elem_list, AssembleElem<false,false>(), indice_noda, indice_elem, *this ); // element (and skin elements)
            }
        }
    }
    ///
    virtual Vec<LinearizedConstraint> get_linearized_constraints() {
        Vec<LinearizedConstraint> linearized_constraints; linearized_constraints.resize( constraints.size() );
        for(unsigned nc=0;nc<constraints.size();++nc) {
            LinearizedConstraint &lc = linearized_constraints[nc];
            // calculation of res
            using namespace Codegen;
            Ex res = constraints[nc].res;
            Ex::SetEx sub_symbols; res.get_sub_symbols(sub_symbols);
            Codegen::Ex::MapExNum vss = val_sub_sym(sub_symbols);
            lc.val = (ScalarType)res.subs_numerical( vss );
            // calculation of coeffs
            lc.coeffs.resize( constraints[nc].coeffs.size() );
            // Vec<unsigned> num_in_fmat; num_in_fmat.resize( constraints[nc].coeffs.size() );
            for(unsigned j=0;j<constraints[nc].coeffs.size();++j) {
                lc.coeffs[j].num_in_vec = constraints[nc].coeffs[j].num_in_fmat(*this);
                Ex coeff = constraints[nc].coeffs[j].val;
                Ex::SetEx sub_symbols; res.get_sub_symbols(sub_symbols);
                Codegen::Ex::MapExNum vss = val_sub_sym(sub_symbols);
                lc.coeffs[j].val = (ScalarType)coeff.subs_numerical( vss );
            }
        }
        return linearized_constraints;
    }
    ///
    virtual void assemble_constraints(bool assemble_mat=true,bool assemble_vec=true) {
        // constraints
        if ( constraints.size() ) {
            if ( assemble_mat )
                max_diag = max(abs(matrices(Number<0>()).diag()));
            for(unsigned i=0;i<constraints.size();++i) {
                // calculation of res
                using namespace Codegen;
                Ex res = constraints[i].res;
                Ex::SetEx sub_symbols;
                res.get_sub_symbols(sub_symbols);
                Codegen::Ex::MapExNum vss = val_sub_sym(sub_symbols);
                ScalarType ress = (ScalarType)res.subs_numerical( vss );
                // calculation of coeffs
                Vec<ScalarType> coeffs; coeffs.resize( constraints[i].coeffs.size() );
                Vec<unsigned> num_in_fmat; num_in_fmat.resize( constraints[i].coeffs.size() );
                for(unsigned j=0;j<constraints[i].coeffs.size();++j) {
                    num_in_fmat[j] = constraints[i].coeffs[j].num_in_fmat(*this);
                    Ex coeff = constraints[i].coeffs[j].val;
                    Ex::SetEx sub_symbols;
                    res.get_sub_symbols(sub_symbols);
                    Codegen::Ex::MapExNum vss = val_sub_sym(sub_symbols);
                    coeffs[j] = (ScalarType)coeff.subs_numerical( vss );
                }
                // add to vec and mat
                for(unsigned j=0;j<coeffs.size();++j) {
                    ScalarType C = coeffs[j] * max_diag * constraints[i].penalty_value;
                    if ( assemble_vec )
                        sollicitation[num_in_fmat[j]] += C * ress;
                    if ( assemble_mat ) {
                        if ( MatCarac<0>::symm or MatCarac<0>::herm )
                            for(unsigned k=0;k<=j;++k)
                                matrices(Number<0>())(num_in_fmat[j],num_in_fmat[k]) += C * coeffs[k];
                        else
                            for(unsigned k=0;k<coeffs.size();++k)
                                matrices(Number<0>())(num_in_fmat[j],num_in_fmat[k]) += C * coeffs[k];
                    }
                }
            }
        }
    }
    ///
    virtual void assemble_sollicitations(bool assemble_mat=true,bool assemble_vec=true) {
        // sollicitations
        if ( sollicitations.size() ) {
            for(unsigned i=0;i<sollicitations.size();++i) {
                // calculation of res
                using namespace Codegen;
                Ex res = sollicitations[i].val;
                Ex::SetEx sub_symbols;
                res.get_sub_symbols(sub_symbols);
                Codegen::Ex::MapExNum vss = val_sub_sym(sub_symbols);
                ScalarType ress = (ScalarType)res.subs_numerical( vss );
                // add to vec and mat
                unsigned num_in_fmat = sollicitations[i].num_in_fmat(*this);
                if ( assemble_vec )
                    sollicitation[num_in_fmat] += ress;
            }
            
        }
    }
    /// ...
    virtual void assemble(bool assemble_mat=true,bool assemble_vec=true) {
        // assemble_mat
        assemble_clean_mat(assemble_mat,assemble_vec);
        // constraints
        assemble_constraints(assemble_mat,assemble_vec);
        // sollicitations
        assemble_sollicitations(assemble_mat,assemble_vec);

        if ( user_want_pierre_precond )
            precond();
    }        
    ///
    bool solve_system_(ScalarType iterative_criterium, const Number<1> &n_wont_add_nz, const Number<0> &sym) {
        //matrices(Number<0>()).get_factorization();
        #if LDL
        //          std::cout << "Resolution LDL " << std::endl;
        vectors[0] = sollicitation;
        LDL_solver l;
        l.get_factorization(matrices(Number<0>()),false);
        l.solve( vectors[0] );
        #elif WITH_CHOLMOD
      	if ( not matrices(Number<0>()).get_factorization() ) {
            std::cout << "Bing. Inversion error" << std::endl;
            return false;
        }
        vectors[0] = matrices(Number<0>()).solve( sollicitation );
        #else
      	try {
            //             std::cout << "Resolution autre " << std::endl;
            vectors[0] = inv(matrices(Number<0>())) * sollicitation;
        } catch(const SolveException &e) { std::cerr << "system not inversible" << std::endl; return false; }
        #endif
        return true;
    }
    ///
    bool solve_system_(ScalarType iterative_criterium, const Number<1> &n_wont_add_nz, const Number<1> &sym) {
        #if WITH_CHOLMOD
        if ( not matrices(Number<0>()).get_factorization() ) {
            std::cout << "Bing. Inversion error" << std::endl;
            return false;
        }
        vectors[0] = matrices(Number<0>()).solve( sollicitation );
        #else
        if ( iterative_criterium ) {
            Mat<ScalarType,Sym<>,SparseLine<> > mm = matrices(Number<0>());
            incomplete_chol_factorize( mm );
            solve_using_incomplete_chol_factorize( mm, matrices(Number<0>()), sollicitation, vectors[0], iterative_criterium );
            return true;
        }
        try {
            vectors[0] = inv(matrices(Number<0>())) * sollicitation;
        } catch(const SolveException &e) { std::cerr << "system not inversible" << std::endl; return false; }
        #endif
        return true;
    }
    
    ///
    bool solve_system_(ScalarType iterative_criterium, const Number<0> &n_wont_add_nz, const Number<0> &sym) {
        try {
            //if ( MatCarac<0>::symm and matrices(Number<0>()).nb_rows() > 1000000 ) {
            //    LDL_solver ls;
            //    ls.get_factorization( matrices(Number<0>()) );
            //    ls.solve( vectors[0] );
            //}
            //else
                vectors[0] = inv(matrices(Number<0>())) * sollicitation;
        } catch(const SolveException &e) { std::cerr << "system not inversible" << std::endl; return false; }
        return true;
    }
    bool solve_system_(ScalarType iterative_criterium, const Number<0> &n_wont_add_nz, const Number<1> &sym) {
        try {
            if ( iterative_criterium ) {
                Mat<ScalarType,Sym<>,SparseLine<> > mm = matrices(Number<0>());
                incomplete_chol_factorize( mm );
                solve_using_incomplete_chol_factorize( mm, matrices(Number<0>()), sollicitation, vectors[0], iterative_criterium );
            }
            else {
                //if ( MatCarac<0>::symm and matrices(Number<0>()).nb_rows() > 1000000 ) {
                #if LDL
                   std::cout << "solveur LDL" << std::endl;
                   LDL_solver ls;
                   ls.get_factorization( matrices(Number<0>()), false );
                   vectors[0] = sollicitation;
                   ls.solve( vectors[0] );
                #else
                //}
                //else
                    vectors[0] = inv(matrices(Number<0>())) * sollicitation;
                #endif
            }
            //PRINT( vectors[0] );
        } catch(const SolveException &e) { std::cerr << "system not inversible" << std::endl; return false; }
        return true;
    }
    ///
    template<unsigned nddl,unsigned sym,class TTT,unsigned wna> bool solve_system_iterative_block(ScalarType iterative_criterium, Number<nddl>/*nb_nodal_unknowns*/, Number<sym>/*sym*/,StructForType<TTT>, Number<wna>) {
        assert( 0 );
        return false;
    }
    ///
    bool solve_system_iterative_block(ScalarType iterative_criterium, Number<3>/*nb_nodal_unknowns*/, Number<true>/*sym*/,StructForType<double>, Number<false>/*wont_add_nz*/ ) {
        MatWithTinyBlocks<ScalarType,Sym<3> > M( matrices(Number<0>()) );
        MatWithTinyBlocks<ScalarType,Sym<3> > F = M; F.chol_incomp();
        solve_using_incomplete_chol_factorize( F, M, sollicitation, vectors[0], iterative_criterium );
        return true;
    }
    ///
    bool solve_system(ScalarType iterative_criterium=0.0,bool disp_timing=false) {
        bool res;
        double t0 = time_of_day_in_sec();
        if ( iterative_criterium and nb_nodal_unknowns==3 and sollicitation.size() % 3 == 0 and TypeInformation<ScalarType>::type()=="double" and wont_add_nz == false )
            res = solve_system_iterative_block( iterative_criterium, Number<nb_nodal_unknowns>(), Number<MatCarac<0>::symm>(), StructForType<ScalarType>(), Number<wont_add_nz>() );
        else
            res = solve_system_( iterative_criterium, Number<wont_add_nz>(), Number<MatCarac<0>::symm>() );
        if ( disp_timing )
            std::cout << time_of_day_in_sec() - t0 << std::endl;
        return res;
    }
    /**
     * call all functions to get solution...
     * @return 
     */
    bool solve( ScalarType iterative_criterium=0.0, bool disp_timing=false ) {
        allocate_matrices();
        shift();
        assemble();
        if (solve_system(iterative_criterium,disp_timing) == false )
            return false;
        update_variables();
        call_after_solve();
        return true;
    }
    virtual void get_precond() { get_precond( Number<MatCarac<0>::symm>() ); }
    virtual void solve_system_using_precond(ScalarType iterative_criterium) { solve_system_using_precond( iterative_criterium, Number<MatCarac<0>::symm>() ); }
    virtual void get_factorization_matrix() { get_factorization_matrix( Number<MatCarac<0>::symm>() ); }
    virtual void solve_system_using_factorization_matrix() { solve_system_using_factorization_matrix( Number<MatCarac<0>::symm>() ); }
    
    
    
    
private:
    template<unsigned num_der_var>
    struct AssembleNodeDerVar {
        template<class TN> void operator()( const TN &n, const Vec<unsigned> &indice_noda, Formulation &f ) const {
            if ( nb_global_unknowns ) {
                if ( nb_nodal_unknowns ) {
                    unsigned ind[ 2 ] = { indice_noda[f.m->node_list.number(n)], f.indice_glob };
                    add_nodal_vector_der_var( f, n, ind, Number<num_der_var>() );
                }
                else
                    add_nodal_vector_der_var( f, n, &f.indice_glob, Number<num_der_var>() );
            }
            else
                add_nodal_vector_der_var( f, n, &indice_noda[f.m->node_list.number(n)], Number<num_der_var>() );
        }
    };
    template<unsigned num_der_var>
    struct AssembleElemDerVar {
        template<class TE,class TCE,unsigned n> void adsem(Formulation &f,const Number<true> &n1,const Number<false> &n2,
                const TE &e,const TCE *ce, const Number<n> &nn,unsigned *in) const {
             add_skin_elem_vector_der_var( f, e, *ce, nn, in, Number<num_der_var>() );
        }
        template<class TE,unsigned n,unsigned n2> void ass_skin_elem(const TE &e,unsigned *in,Formulation &f,
                    const Number<n> &nn,const Number<n2> &nn2) const { // sub_mesh(Number<1>()).
            ass_skin_elem( e, in, f, Number<n+1>(), nn2 );
            if ( f.m->sub_mesh(Number<1>()).get_parents_of( *f.m->get_children_of(e,Number<1>())[n] ).size()!=1 )
                return;
            //PRINTTYPE( typeid( typename TypeChildrenElement<typename TE::NE,1,n>::T ) );
            
            typedef typename TM::template SubMesh<1>::T TSubMesh;
            typedef typename TSubMesh::template TElem<typename TypeChildrenElement<typename TE::NE,1,n>::T>::TE TCH;
            TCH *child_elem = static_cast<TCH *>( f.m->get_children_of(e,Number<1>())[n] );
            adsem( f, Number<true>(),Number<false>(), e, child_elem, nn, in );
        }
        template<class TE,unsigned n> void ass_skin_elem( const TE &e, unsigned *in, Formulation &f, const Number<n> &nn, const Number<n> &nn2 ) const {}
        template<class TE> void operator()( const TE &e, const Vec<unsigned> &indice_noda, const Vec<unsigned> *indice_elem, Formulation &f ) const {
            unsigned in[ TE::nb_nodes + 1 + nb_global_unknowns ];
            
            if ( nb_nodal_unknowns ) 
                for(unsigned i=0;i<TE::nb_nodes;++i)
                    in[i] = indice_noda[ f.m->node_list.number(*e.node(i)) ];
            
            typedef CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType> CFE;
            if ( CFE::nb_elementary_unknowns ) 
                in[ TE::nb_nodes * (nb_nodal_unknowns!=0) ] = indice_elem[TE::num_in_elem_list][e.number];
            
            if ( nb_global_unknowns )
                in[ TE::nb_nodes * (nb_nodal_unknowns!=0) + (CFE::nb_elementary_unknowns!=0) ] = f.indice_glob;

            add_elem_vector_der_var( f, e, in, Number<num_der_var>() );
            
            // skin elements
            if ( not f.assume_skin_not_needed )
                ass_skin_elem( e, in, f, Number<0>() , Number<NbChildrenElement<typename TE::NE,1>::res>() );
        }
    };
public:
    ///
    template<unsigned num_der_var>
    void assemble_clean_vector_der_var( Number<num_der_var>, unsigned n ) {
        if ( num_der_var == n ) {
            sollicitation.set(0.0);
    
            add_global_vector_der_var( *this, indice_glob, Number<num_der_var>() ); // global
            apply( m->node_list, AssembleNodeDerVar<num_der_var>(), indice_noda, *this ); // nodal
            apply( m->elem_list, AssembleElemDerVar<num_der_var>(), indice_noda, indice_elem, *this ); // element (and skin elements)
        } else
            assemble_clean_vector_der_var( Number<num_der_var+1>(), n );
    }
    ///
    void assemble_clean_vector_der_var( Number<nb_der_var>, unsigned n ) {}
    
    ///
    virtual void assemble_vector_der_var( unsigned num_der_var ) {
        assemble_clean_vector_der_var( Number<0>(), num_der_var );
    }
    
    
    void precond() { } /// normalization of the matrix
private:
    void get_precond(const Number<0> &sym) {
        #ifndef WITH_UMFPACK
        precond_matrix = matrices(Number<0>()); incomplete_lu_factorize( precond_matrix );
        #endif
    }
    void get_precond(const Number<1> &sym) {
        #ifndef WITH_UMFPACK
        precond_matrix = matrices(Number<0>());
        incomplete_chol_factorize( precond_matrix );
        #endif
    }
    void solve_system_using_precond(ScalarType iterative_criterium,const Number<0> &sym) {
        #ifndef WITH_UMFPACK
        solve_using_incomplete_lu_factorize( precond_matrix, matrices(Number<0>()), sollicitation, vectors[0], iterative_criterium );
        #endif
    }
    void solve_system_using_precond(ScalarType iterative_criterium,const Number<1> &sym) {
        #ifndef WITH_UMFPACK
        solve_using_incomplete_chol_factorize( precond_matrix, matrices(Number<0>()), sollicitation, vectors[0], iterative_criterium );
        #endif
    }
    
    void get_factorization_matrix(const Number<0> &sym) {
        #ifndef LDL
        #ifndef WITH_UMFPACK
        precond_matrix = matrices(Number<0>()); lu_factorize( precond_matrix );
        #endif
        #endif
    }
    void get_factorization_matrix(const Number<1> &sym) {
        #ifndef LDL
        #ifndef WITH_UMFPACK
        precond_matrix = matrices(Number<0>());
        chol_factorize( precond_matrix );
        #endif
        #endif
    }
    void solve_system_using_factorization_matrix(const Number<0> &sym) {
        #ifndef LDL
        #ifndef WITH_UMFPACK
        solve_using_lu_factorize( precond_matrix, sollicitation, vectors[0] );
        #endif
        #else
        std::cout << "solveur LDL dans solve_system_using_factorization_matrix" << std::endl;
        LDL_solver ls;
        ls.get_factorization( matrices(Number<0>()), false );
        vectors[0] = sollicitation;
        ls.solve( vectors[0] );
        #endif
    }
    void solve_system_using_factorization_matrix(const Number<1> &sym) {
        #ifndef LDL
        #ifndef WITH_UMFPACK
        solve_using_chol_factorize( precond_matrix, sollicitation, vectors[0] );
        #endif
        #else
        std::cout << "solveur LDL dans solve_system_using_factorization_matrix" << std::endl;
        LDL_solver ls;
        ls.get_factorization( matrices(Number<0>()), false );
        vectors[0] = sollicitation;
        ls.solve( vectors[0] );
        #endif
    }

    struct UpdateVarElem {
        template<class TE> void operator()(TE &e,Formulation &f) const {
            CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::set_elementary_unknowns(e,f,f.vectors,f.indice_elem[TE::num_in_elem_list][e.number]);
        }
        template<class TE> void operator()(TE &e,Formulation &f,const ScalarType &partial_ts) const {
            CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::set_elementary_unknowns(e,f,f.vectors,f.indice_elem[TE::num_in_elem_list][e.number],partial_ts);
        }
    };
    struct GetInitialCond {
        template<class TE> void operator()(const TE &e,Formulation &f) const {
            CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::get_elementary_initial_conditions(e,f,f.vectors,f.indice_elem[TE::num_in_elem_list][e.number]);
        }
    };
    struct CallAfterSolve {
        template<class TE> void operator()(TE &e,Formulation &f) const {
            unsigned in[ TE::nb_nodes+1 ];
            for(unsigned i=0;i<TE::nb_nodes;++i)
                in[i] = f.indice_noda[ f.m->node_list.number(*e.node(i)) ];
            in[ TE::nb_nodes ] = f.indice_elem[TE::num_in_elem_list][e.number];
            CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::after_solve(e,f,in);
        }
    };
    struct CallAfterSolve_2 {
        template<class TE> void operator()(TE &e,Formulation &f) const {
            unsigned in[ TE::nb_nodes+1 ];
            for(unsigned i=0;i<TE::nb_nodes;++i)
                in[i] = f.indice_noda[ f.m->node_list.number(*e.node(i)) ];
            in[ TE::nb_nodes ] = f.indice_elem[TE::num_in_elem_list][e.number];
            CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::after_solve_2(e,f,in);
        }
    };
    struct CallAfterSolve_3 {
        template<class TE> void operator()(TE &e,Formulation &f) const {
            unsigned in[ TE::nb_nodes+1 ];
            for(unsigned i=0;i<TE::nb_nodes;++i)
                in[i] = f.indice_noda[ f.m->node_list.number(*e.node(i)) ];
            in[ TE::nb_nodes ] = f.indice_elem[TE::num_in_elem_list][e.number];
            CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::after_solve_3(e,f,in);
        }
    };
    struct CallAfterSolve_4 {
        template<class TE> void operator()(TE &e,Formulation &f) const {
            unsigned in[ TE::nb_nodes+1 ];
            for(unsigned i=0;i<TE::nb_nodes;++i)
                in[i] = f.indice_noda[ f.m->node_list.number(*e.node(i)) ];
            in[ TE::nb_nodes ] = f.indice_elem[TE::num_in_elem_list][e.number];
            CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::after_solve_4(e,f,in);
        }
    };
    struct CallAfterSolve_5 {
        template<class TE> void operator()(TE &e,Formulation &f) const {
            unsigned in[ TE::nb_nodes+1 ];
            for(unsigned i=0;i<TE::nb_nodes;++i)
                in[i] = f.indice_noda[ f.m->node_list.number(*e.node(i)) ];
            in[ TE::nb_nodes ] = f.indice_elem[TE::num_in_elem_list][e.number];
            CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::after_solve_5(e,f,in);
        }
    };
    struct CallAfterSolve_6 {
        template<class TE> void operator()(TE &e,Formulation &f) const {
            unsigned in[ TE::nb_nodes+1 ];
            for(unsigned i=0;i<TE::nb_nodes;++i)
                in[i] = f.indice_noda[ f.m->node_list.number(*e.node(i)) ];
            in[ TE::nb_nodes ] = f.indice_elem[TE::num_in_elem_list][e.number];
            CaracFormulationForElement<NameFormulation,TE,NameVariant,ScalarType>::after_solve_6(e,f,in);
        }
    };

public:
    /**
     * call all after_solve in carac elem ( generated by apply_on_elements_after_solve() in formulation_...py )
     */
    virtual void call_after_solve() {
        apply( m->elem_list, CallAfterSolve(), *this );
    }
    virtual void call_after_solve_2() {
        apply( m->elem_list, CallAfterSolve_2(), *this );
    }
    virtual void call_after_solve_3() {
        apply( m->elem_list, CallAfterSolve_3(), *this );
    }
    virtual void call_after_solve_4() {
        apply( m->elem_list, CallAfterSolve_4(), *this );
    }
    virtual void call_after_solve_5() {
        apply( m->elem_list, CallAfterSolve_5(), *this );
    }
    virtual void call_after_solve_6() {
        apply( m->elem_list, CallAfterSolve_6(), *this );
    }


    virtual void call_after_solve(const Vec<void *> &elem_list) {
        for(unsigned i=0;i<elem_list.size();++i)
            TM::TElemList::apply_on_down_cast( reinterpret_cast<typename TM::EA *>(elem_list[i]), CallAfterSolve(), *this );
    }
    virtual void call_after_solve_2(const Vec<void *> &elem_list) {
        for(unsigned i=0;i<elem_list.size();++i)
            TM::TElemList::apply_on_down_cast( reinterpret_cast<typename TM::EA *>(elem_list[i]), CallAfterSolve_2(), *this );
    }
    virtual void call_after_solve_3(const Vec<void *> &elem_list) {
        for(unsigned i=0;i<elem_list.size();++i)
            TM::TElemList::apply_on_down_cast( reinterpret_cast<typename TM::EA *>(elem_list[i]), CallAfterSolve_3(), *this );
    }
    virtual void call_after_solve_4(const Vec<void *> &elem_list) {
        for(unsigned i=0;i<elem_list.size();++i)
            TM::TElemList::apply_on_down_cast( reinterpret_cast<typename TM::EA *>(elem_list[i]), CallAfterSolve_4(), *this );
    }
    virtual void call_after_solve_5(const Vec<void *> &elem_list) {
        for(unsigned i=0;i<elem_list.size();++i)
            TM::TElemList::apply_on_down_cast( reinterpret_cast<typename TM::EA *>(elem_list[i]), CallAfterSolve_5(), *this );
    }
    virtual void call_after_solve_6(const Vec<void *> &elem_list) {
        for(unsigned i=0;i<elem_list.size();++i)
            TM::TElemList::apply_on_down_cast( reinterpret_cast<typename TM::EA *>(elem_list[i]), CallAfterSolve_6(), *this );
    }

    /**
     * update variable at end of the time step
     */
    virtual void update_variables() {
        for(unsigned i=0;i<m->node_list.size();++i)
            carac.set_nodal_unknowns(m->node_list[i],*this,vectors,indice_noda[i]);
        apply( m->elem_list, UpdateVarElem(), *this );
        carac.set_global_unknowns(m,*this,vectors,indice_glob);
    }
    /**
     * update variable at time t_n + partial_ts
     */
    virtual void update_variables(ScalarType partial_ts) {
        for(unsigned i=0;i<m->node_list.size();++i)
            carac.set_nodal_unknowns(m->node_list[i],*this,vectors,indice_noda[i],partial_ts);
        apply( m->elem_list, UpdateVarElem(), *this, partial_ts );
        carac.set_global_unknowns(m,*this,vectors,indice_glob,partial_ts);
    }
    /**
     * fill vectors[x] using dern_unknown
     */
    virtual void get_initial_conditions() {
        for(unsigned i=0;i<m->node_list.size();++i)
            carac.get_nodal_initial_conditions(m->node_list[i],*this,vectors,indice_noda[i]);
        apply( m->elem_list, GetInitialCond(), *this );
        carac.get_global_initial_conditions(m,*this,vectors,indice_glob);
        initialized = true;
    }
    /**
     * add a constraint which will be added to system during assembly
     * @param txt constraint in analytic form. Example : "node[0].temperature + time**2 - 10"
     * @param penalty_value constraint will be * by max(abs(diag))*penalty_value
     * @return number of constraint (usefull in order to remove it...)
     */
    virtual unsigned add_constraint(const std::string &txt,const ScalarType &penalty_value) { return add_constraint( Constraint<Formulation>(txt,penalty_value,*this) ); }
    virtual unsigned add_constraint(const Constraint<Formulation> &c) { constraints.push_back( c ); return constraints.size()-1; }
    
    virtual void add_sollicitation(int type_var,const std::string &val,unsigned nb_in_type,unsigned num_in_vec=0) {
        sollicitations.push_back( Sollicitation<Formulation>(type_var,val,nb_in_type,num_in_vec) );
    }
    virtual void set_initial_time_step( ScalarType ts ) { time_steps = ts; }
    virtual ScalarType get_next_time_step() const { return time_steps[0]; }
    virtual ScalarType get_time() const { return time; }
    virtual void set_time( ScalarType ts ) { time = ts; } /// Attention, pilotage a faire soi-meme si utilisation de cette fonction....
private:
    template<class TMAT> void get_mat_( TMAT *&mat, const Number<0> &n ) {
        std::cerr << "Wrong matrix type. We expected a " << std::endl;
        PRINTTYPE( typeid(matrices(Number<0>())) );
        assert(0);
        mat = NULL;
    }
    template<class TMAT> void get_mat_( TMAT *&mat, const Number<1> &n ) { mat = &matrices(Number<0>()); }
    template<class TMAT> void get_mat_( TMAT *&mat ) { get_mat_( mat, Number< AreSameType< TMAT, TMAT0 >::res >() ); }
public:
    #ifdef WITH_UMFPACK
    virtual void get_mat( Mat<ScalarType,Gen<>,SparseUMFPACK> *&mat ) { get_mat_( mat ); }
    #endif
    virtual void get_mat( Mat<ScalarType,Gen<>,SparseLU> *&mat ) { get_mat_( mat ); }
    #ifdef WITH_CHOLMOD
    virtual void get_mat( Mat<ScalarType,Sym<>,SparseCholMod> *&mat ) { get_mat_( mat ); }
    #endif
    virtual void get_mat( Mat<ScalarType,Sym<>,SparseLine<> > *&mat ) { get_mat_( mat ); }

    virtual Vec<ScalarType> &get_sollicitation() { return sollicitation; }
    virtual Vec<ScalarType> &get_result(unsigned num=0) { return vectors[num]; }
    
    virtual unsigned nb_constraints() const { return constraints.size(); }
    virtual void erase_constraints_from(unsigned number) { constraints.resize(number); }
    
    virtual unsigned get_indice_noda(unsigned num_node) const { return indice_noda[num_node]; }
    
    virtual void display_mat( std::ostream &os ) const {
        os << matrices( Number<0>() );
    }
    
    Vec<ScalarType> fit( const Mat<ScalarType,Sym<>,SparseLine<> > &exp_mat, const Vec<ScalarType> &exp_val, ScalarType exp_mat_coeff, const Vec<ScalarType> &conv ) {
        allocate_matrices();
        shift();
        Vec<ScalarType> history;
        for(unsigned num_iter=0;num_iter<15;++num_iter) {
            assemble();
            
            //matrices(Number<0>()) += exp_mat_coeff * exp_mat;
            //sollicitation += exp_mat_coeff * exp_mat * exp_val;
            
            Inv<ScalarType,Sym<>,SparseLine<> > I( matrices(Number<0>()) );
            vectors[ 0 ] = I * sollicitation;
            
            update_variables();
            call_after_solve();
            //
            Vec<Vec<ScalarType> > der_U; der_U.resize( nb_der_var );
            for(unsigned i=0;i<nb_der_var;++i) {
                assemble_vector_der_var( i );
                der_U[ i ] = I * sollicitation;
            }
            //
            Mat<ScalarType> M( nb_der_var );
            Vec<ScalarType> V; V.resize( nb_der_var );
            for(unsigned i=0;i<nb_der_var;++i) {
                Vec<ScalarType> dUi = exp_mat * der_U[i];
                V[ i ] = dot( dUi, exp_val - vectors[0] );
                for(unsigned j=0;j<nb_der_var;++j)
                    M( i, j ) = dot( dUi, der_U[j] );
            }
            M.diag() += max( abs( M.diag() ) ) * 1e-9; // HUM
            //
            Vec<ScalarType> dD = inv( M ) * V;
            PRINT( dD );
            history.push_back( norm_2( dD ) );
            Carac::add_to_der_vars( *this, dD );
            if ( all( abs( dD ) < conv ) )
                break;
        }
        return history;
    }
    
    Vec<ScalarType> fit( const Vec<ScalarType> &exp_val, ScalarType conv ) {
        Vec<ScalarType> conv_vec; conv_vec.resize( nb_der_var, conv );
        Mat<ScalarType,Sym<>,SparseLine<> > exp_mat( exp_val.size() );
        exp_mat.diag() = 1.0;
        return fit( exp_mat, exp_val, 0.0, conv_vec );
    }
    
    void get_der_var_on_mesh( unsigned num_der_var ) {
        allocate_matrices();
        shift();
        assemble();
        assemble_vector_der_var( num_der_var );
        vectors[ 0 ] = inv( matrices(Number<0>()) ) * sollicitation;
        update_variables();
    }
    
    
    TM *m;
    Carac carac;
    ScalarType max_diag;
    
    HeterogeneousPack<PackMatrices> matrices;
    TMAT0 precond_matrix; /// in case user has called get_precond()
    Vec<Vec<ScalarType>,nb_vectors> vectors;
    Vec<ScalarType> sollicitation;
    Vec<ScalarType,nb_vectors> time_steps;
    ScalarType time; /// at end of current step
    Vec<ScalarType> old_vec;

    Vec<Constraint<Formulation> > constraints;
    Vec<Sollicitation<Formulation> > sollicitations;
    
    Vec<unsigned> indice_elem[ TM::TElemList::nb_sub_type ];
    Vec<unsigned> indice_noda;
    unsigned indice_glob;
    bool mat_def_pos_if_sym, initialized, user_want_pierre_precond, mat_has_been_allocated_with_symamd;
    bool want_amd;
    
    std::vector<Codegen::Ex> symbols;
    Codegen::Ex time_symbol;
};

/** To be redefined for each new formulations
*/
template<class TM,class NameFormulation,class NameVariant,unsigned assemble_mat,unsigned assemble_vec,class T,bool wont_add_nz>
void add_global_matrix(Formulation<TM,NameFormulation,NameVariant,T,wont_add_nz> &f,const Number<assemble_mat> &nnm,const Number<assemble_vec> &nnv,unsigned indice) {
}

/** To be redefined for each new formulations
*/
template<class TF,unsigned _ms,unsigned _am,unsigned _av,class TE>
void add_elem_matrix(
        TF &f,
        const Number<_ms> &matrix_is_sym,
        const Number<_am> &assemble_mat,
        const Number<_av> &assemble_vec,
        const TE &elem,
        const unsigned *indices ) {
    typedef typename TF::ScalarType T;

    for( const double *gp = gauss_point_for_order( f.order_integration_when_integration_totale, typename TE::NameElem() ); *gp!=0.0; gp += elem.nb_var_inter + 1 )
        add_local_elem_matrix( *gp, gp+1, f, matrix_is_sym, assemble_mat, assemble_vec, elem, indices );
        
}


/** To be redefined for each new formulations
*/
template<class TM,class NameFormulation,class NameVariant,class T,bool wont_add_nz,class TN,unsigned num_der_var>
void add_nodal_vector_der_var( Formulation<TM,NameFormulation,NameVariant,T,wont_add_nz> &f, const TN &node, const unsigned *indice, Number<num_der_var> ) {
}

/** To be redefined for each new formulations
*/
template<class TM,class NameFormulation,class NameVariant,class T,bool wont_add_nz,unsigned num_der_var>
void add_global_vector_der_var( Formulation<TM,NameFormulation,NameVariant,T,wont_add_nz> &f, unsigned indice, Number<num_der_var> ) {
}

/** To be redefined for each new formulations
*/
template<class TF,class TE,unsigned num_der_var>
void add_elem_vector_der_var(
        TF &f,
        const TE &elem,
        const unsigned *indices,
        Number<num_der_var> ) {
    typedef typename TF::ScalarType T;

    for( const double *gp = gauss_point_for_order( f.order_integration_when_integration_totale, typename TE::NameElem() ); *gp!=0.0; gp += elem.nb_var_inter + 1 )
        add_local_elem_vector_der_var( *gp, gp+1, f, elem, indices );
        
}

};

#endif // LMT_formulation_HEADER
