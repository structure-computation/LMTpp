//
// C++ Interface: meshgeneric
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_meshgeneric_HEADER
#define LMT_meshgeneric_HEADER

#include "meshancestor.h"

namespace LMT {

template<class CN,unsigned max_sub_meshes> class Mesh;
template<class CN,unsigned SK,unsigned MN> class MeshGenericBis;

// ---------------------------------------------------------------------------------------------------
namespace LMTPRIVATE {
    template<class TM> struct AddElemWith1Parent;
    /// sub mesh type extractor
    template<class TMG,unsigned nvi_to_subs> struct SubMesh { typedef typename SubMesh<typename TMG::TNext,nvi_to_subs-1>::T T; };
    template<class TMG> struct SubMesh<TMG,0> { typedef TMG T; };
};

/*!
\generic_comment MeshGeneric

    Cette classe sert à la construction des classes \a MeshGeneric et \a MeshGenericBis .
    La méthode très utile de cette classe est sub_mesh( Number<n> ) pour accéder à un maillage enfant d'un maillage. Plus précisement, sub_mesh( Number<n> ) retourne une référence vers le maillage enfant de dimension dim-n où dim est la dimension du maillage appelant la méthode.
    Par exemple, si on a un maillage de tétraèdre (classe \a Tetra ) alors
        * sub_mesh( Number<0> ) renvoie le maillage appelant.
        * sub_mesh( Number<1> ) renvoie le maillage enfant composé de triangles (classe \a Triangle par exemple).
        * sub_mesh( Number<2> ) renvoie le maillage enfant composé de barres (classe \a Bar_3 par exemple).

*/ 

/*!
    Used to define sub_meshes
    
    \author Hugo LECLERC
*/
template<class Carac,unsigned nvi_to_subs_,unsigned skin,unsigned end_nvi_to_subs>
class MeshGeneric : public MeshAncestor<Carac,nvi_to_subs_,skin> {
public:
    typedef MeshAncestor<Carac,nvi_to_subs_,skin> MA;
    typedef typename MA::TElemList TElemList;
    typedef typename MA::TNode TNode;
    typedef ElementAncestor<TNode> EA;
    static const unsigned nvi_to_subs = nvi_to_subs_;
    typedef MeshGeneric<Carac,nvi_to_subs+1,skin,end_nvi_to_subs> TNext;
    template<class NE,class BE=DefaultBehavior> struct TElem { typedef typename TElemList::template TElem<NE,BE>::TE TE; };
    template<unsigned addnvitosubs> struct SubMesh { typedef typename LMTPRIVATE::SubMesh<MeshGeneric,addnvitosubs>::T T; };

    MeshGeneric() {
        date_last_elem_chidren_update = 0;
        date_last_elem_parents_update = 0;
    }
    ////
    template<unsigned addnvisubs> typename SubMesh<addnvisubs>::T &sub_mesh(const Number<addnvisubs> &nnn) { return next.sub_mesh(Number<addnvisubs-1>()); }
    ///
    MeshGeneric &sub_mesh(const Number<0> &nnn) { return *this; }
    ///
    template<unsigned addnvisubs> const typename SubMesh<addnvisubs>::T &sub_mesh(const Number<addnvisubs> &nnn) const { return next.sub_mesh(Number<addnvisubs-1>()); }
    ///
    const MeshGeneric &sub_mesh(const Number<0> &nnn) const { return *this; }
    /// helper
    template<unsigned addnvisubs> typename SubMesh<addnvisubs>::T &sub_mesh() { return sub_mesh(Number<addnvisubs>()); }
    /// helper
    template<unsigned addnvisubs> const typename SubMesh<addnvisubs>::T &sub_mesh() const { return sub_mesh(Number<addnvisubs>()); }
    
    /// TE must be an element of this
    template<class TE> SimpleConstIterator<const EA *> get_parents_of(const TE &e) const {
         return elem_parents[e.num_in_elem_list_virtual()][e.number]; 
    }
    /// TE must be an element of this !
    template<class TE> SimpleConstIterator<EA *> get_parents_of(const TE &e) {
         return elem_parents[e.num_in_elem_list_virtual()][e.number]; 
    }
    
    /// TE must be an element of this
    SimpleConstIterator<const EA *> get_parents_of(const EA *e) const {return elem_parents[e->num_in_elem_list_virtual()][e.number];}
    /// TE must be an element of this !
    SimpleConstIterator<EA *> get_parents_of(const EA *e) { return elem_parents[e->num_in_elem_list_virtual()][e.number]; }
    
    ///
    void free() {
        MA::free();
        this->clear_elem_parents_g();
        this->clear_elem_children_g();
        this->node_list.free();
        
        //
        next.free();
    }
    
    ///
    TNext next;
protected:
    ///
    template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode **n) {
        return MA::add_element_(ne,be,n);
    }
    ///
    void signal_connectivity_change_rec(typename MA::TNodeList &nl) {
        if ( nvi_to_subs > skin )
            this->node_list.is_a_ref_of(nl);
        ++this->date_last_connectivity_change;
        next.signal_connectivity_change_rec(nl);
        this->node_list.synchronize_all_dyn();
        this->elem_list.synchronize_all_dyn();
    }

    ///
    template<class TE> void register_element_in_hash_table( TE *e ) { 
        if ( this->elem_list.nb_hash_val != this->wanted_hash_size )
            this->elem_list.change_hash_size( *this, this->wanted_hash_size );
        this->elem_list.register_element_in_hash_table( e, *this );
    }
    ///
    template<class PEL> struct AppendChildrenElem {
        ///
        template<class TE,class TSubMesh> void operator()(TE &e,TSubMesh *m) {
            cpt = 0;
            append_skin_elements(e,m,*this,Number<nvi_to_subs>());
        }
        template<class TE,class TSubMesh,class NE,class TN> void add_element_(TE &e,TSubMesh *m,const NE &ne,TN **n) {
            typedef typename TSubMesh::template TElem<NE,DefaultBehavior>::TE NTE;
            
            if ( m->elem_list.nb_hash_val != m->wanted_hash_size )
                m->elem_list.change_hash_size( *m, m->wanted_hash_size );

            NTE *new_elem = m->elem_list.find(ne,DefaultBehavior(),*m,n);
            if ( ! new_elem ) {
                new_elem = m->add_element( ne, DefaultBehavior(), n );
                m->register_element_in_hash_table( new_elem );
            }
            static const unsigned nb_children = NbChildrenElement<typename TE::NE,nvi_to_subs>::res;
            // register as child
            m->elem_children[e.num_in_elem_list][ e.number * nb_children + (cpt++) ] = new_elem;
        }
        template<class TE,class TS,class NE,class TN> void add_element(TE &e,TS &m,const NE &ne,TN *n0,TN *n1,TN *n2,TN *n3,TN *n4,TN *n5,TN *n6,TN *n7) {
            TN *n[]={n0,n1,n2,n3,n4,n5,n6,n7}; add_element_(e,m,ne,n);
        }
        template<class TE,class TS,class NE,class TN> void add_element(TE &e,TS &m,const NE &ne,TN *n0,TN *n1,TN *n2,TN *n3,TN *n4,TN *n5,TN *n6) {
            TN *n[]={n0,n1,n2,n3,n4,n5,n6}; add_element_(e,m,ne,n);
        }
        template<class TE,class TS,class NE,class TN> void add_element(TE &e,TS &m,const NE &ne,TN *n0,TN *n1,TN *n2,TN *n3,TN *n4,TN *n5) {
            TN *n[]={n0,n1,n2,n3,n4,n5}; add_element_(e,m,ne,n);
        }
        template<class TE,class TS,class NE,class TN> void add_element(TE &e,TS &m,const NE &ne,TN *n0,TN *n1,TN *n2,TN *n3,TN *n4) {
            TN *n[]={n0,n1,n2,n3,n4}; add_element_(e,m,ne,n);
        }
        template<class TE,class TS,class NE,class TN> void add_element(TE &e,TS &m,const NE &ne,TN *n0,TN *n1,TN *n2,TN *n3) {
            TN *n[]={n0,n1,n2,n3}; add_element_(e,m,ne,n);
        }
        template<class TE,class TS,class NE,class TN> void add_element(TE &e,TS &m,const NE &ne,TN *n0,TN *n1,TN *n2) {
            TN *n[]={n0,n1,n2}; add_element_(e,m,ne,n);
        }
        template<class TE,class TS,class NE,class TN> void add_element(TE &e,TS &m,const NE &ne,TN *n0,TN *n1) {
            TN *n[]={n0,n1}; add_element_(e,m,ne,n);
        }
        template<class TE,class TS,class NE,class TN> void add_element(TE &e,TS &m,const NE &ne,TN *n0) {
            TN *n[]={n0}; add_element_(e,m,ne,n);
        }
        unsigned cpt;
    };
    ///
    template<class PEL,unsigned total_n>
    void resize_elem_children_rec(PEL &pel,const unsigned *s,const Number<total_n> &nn,const Number<total_n> &ntn) {}
    template<class PEL,unsigned num_sub_type_par,unsigned total_n>
    void resize_elem_children_rec(PEL &pel,const unsigned *s,const Number<num_sub_type_par> &nn,const Number<total_n> &ntn) {
        typedef typename Carac::template ElementChoice<skin,skin,num_sub_type_par,0>::NE NE;
        static const unsigned nb_children = NbChildrenElement<NE,nvi_to_subs>::res;
        elem_children[num_sub_type_par].resize( s[num_sub_type_par] * nb_children );
        resize_elem_children_rec(pel,s,Number<num_sub_type_par+1>(),ntn);
    }
    ///
    template<class PEL,class PNL> void update_elem_children_g(PEL &parent_elem_list,PNL &parent_node_list) {
        if ( date_last_elem_chidren_update == this->date_last_connectivity_change )
            return;
        date_last_elem_chidren_update = this->date_last_connectivity_change;
        
        this->node_list.is_a_ref_of(parent_node_list);
        this->clear_elements();
            
        unsigned s[PEL::nb_elem_type];
        parent_elem_list.get_sizes(s);
        resize_elem_children_rec(parent_elem_list,s,Number<0>(),Number<PEL::nb_elem_type>());
        
        AppendChildrenElem<PEL> ace;
        
        apply( parent_elem_list, ace , this );
    }
    ///
    template<class PEL,class PNL> void update_elem_children_rec(PEL &parent_elem_list,PNL &parent_node_list) {
        update_elem_children_g(parent_elem_list,parent_node_list);
        next.update_elem_children_rec(parent_elem_list,parent_node_list);
    }
    ///
    template<class TE> void move_elem_children_data_rec(const TE &e,unsigned old_place,unsigned new_place) {
        static const unsigned nb_ch = NbChildrenElement<typename TE::NE,nvi_to_subs>::res;
        if ( elem_children[TE::num_in_elem_list].size() >= (old_place+1)*nb_ch && elem_children[TE::num_in_elem_list].size() > (new_place+1)*nb_ch ) {
            for(unsigned i=0;i<nb_ch;++i)
                elem_children[TE::num_in_elem_list][ new_place*nb_ch+i ] = elem_children[TE::num_in_elem_list][ old_place*nb_ch+i ];
        }
        next.move_elem_children_data_rec(e,old_place,new_place);
    }

    // ----------------------------------------------------------------------------------------
    ///
    struct AppendToParents {
        template<class TE> void operator()(TE &e) {
            static const unsigned nb_children = NbChildrenElement<typename TE::NE,nvi_to_subs>::res;
            if ( nb_children==0 ) return;
            EA **children = &th->elem_children[TE::num_in_elem_list][e.number*nb_children];
            for(unsigned i=0;i<nb_children;++i) {
                unsigned index_in_sub_mesh = th->elem_list.index_of_down_cast(children[i]);
                parents[index_in_sub_mesh][children[i]->number].push_back( &e );
            }
        }
        MeshGeneric *th;
        Vec<Vec<EA *> > parents[TElemList::nb_elem_type+(TElemList::nb_elem_type==0)];
    };
    ///
    template<class ParList> void update_elem_parents_g(ParList &par_list) {
        if ( date_last_elem_parents_update == this->date_last_connectivity_change )
            return;
        date_last_elem_parents_update = this->date_last_connectivity_change;
        
        clear_elem_parents_g();
        
        AppendToParents ap;
        ap.th = this;
        unsigned s[TElemList::nb_elem_type+(TElemList::nb_elem_type==0)];
        this->elem_list.get_sizes(s);
        for(unsigned i=0;i<TElemList::nb_elem_type;++i)
            ap.parents[i].resize(s[i]);
        
        apply(par_list, ap);
        
        for(unsigned i=0;i<TElemList::nb_elem_type;++i)
            elem_parents[i] = ap.parents[i];
    }
    ///
    template<class ParList> void update_elem_parents_rec(ParList &par_list) {
        update_elem_parents_g(par_list);
        next.update_elem_parents_rec(par_list);
    }
    
    template<unsigned is_skin> struct NbElemType {
        template<unsigned n,unsigned inner=0> struct SubType { typedef typename Carac::template ElementChoice<is_skin,is_skin,n,inner>::NE T; };
    };
    void clear_elem_parents_g() { for(unsigned i=0;i<TElemList::nb_elem_type;++i) elem_parents[i].free(); --date_last_elem_parents_update; }
    void clear_elem_parents_rec() { clear_elem_parents_g(); next.clear_elem_parents_rec(); }
    void clear_elem_children_g() { for(unsigned i=0;i<NbSubTypes<NbElemType<skin> >::res;++i) elem_children[i].free(); --date_last_elem_chidren_update; }
    void clear_elem_children_rec() { clear_elem_children_g(); next.clear_elem_children_rec(); }
    
    /// can be accessed only from MeshGenericBis<> 
    Vec<EA *> elem_children[NbSubTypes<NbElemType<skin> >::res+(NbSubTypes<NbElemType<skin> >::res==0)];
    ///
    PackedVectorOfVector<EA *> elem_parents[TElemList::nb_elem_type+(TElemList::nb_elem_type==0)];
    ///
    unsigned date_last_elem_chidren_update, date_last_elem_parents_update;
        
    template<class CN,unsigned max_sub_meshes> friend class Mesh;
    template<class CN,unsigned NV,unsigned SK,unsigned MN> friend class MeshGeneric;
    template<class CN,unsigned SK,unsigned MN> friend class MeshGenericBis;
    template<class PEL> friend struct AppendChildrenElem;
    template<class TM> friend struct LMTPRIVATE::AddElemWith1Parent;
};

// ------------------------------------------------------------------------------------------------------------------------

/// break condition
template<class Carac,unsigned skin,unsigned end_nvi_to_subs>
class MeshGeneric<Carac,end_nvi_to_subs,skin,end_nvi_to_subs> {
public:
    template<class TEL,class PNL> void update_elem_children_rec(const TEL &parents,const PNL &parent_node_list) const {}
    template<class ParList> void update_elem_parents_rec(const ParList &par_list) const {}
    void clear_elem_parents_rec() const {}
    void clear_elem_children_rec() const {}
    template<class TE> void move_elem_children_data_rec(const TE &e,unsigned old_place,unsigned new_place) const {}
    template<class TNL> void signal_connectivity_change_rec(TNL &nl) {}
    void free() {}
};

};

#endif // LMT_meshgeneric_HEADER
