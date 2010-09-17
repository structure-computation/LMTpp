//
// C++ Interface: mesh
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMTMESH_H
#define LMTMESH_H

#include "meshgenericbis.h"

namespace LMT {

template<class Carac,unsigned max_sub_meshes>
struct MeshNbSubMeshes { enum { res = max_sub_meshes ? MIN( Carac::dim+1, max_sub_meshes ) : Carac::dim+1 }; };

/*!
    Cette classe représente un maillage du plan ou de l'espace. Ces paramètres sont :
        * une classe <strong> Carac </strong> qui contient les caractériques du maillage pour une formulation variationnelle.
        * un entier positif <strong> max_sub_meshes </strong> nul par défaut qui indique le nombre maximum de maillages enfants que possédera le maillage. si on ne connait pas le nombre de maillages enfants nécessaires, on laisse la valeur par défaut.
    Que représentent les maillages enfants ?
    Si un maillage se compose d'éléments E, le premier maillage enfant distinct du maillage sera le maillage composé par les sous-éléments de E; Ppar exemple, si E est un tétraèdre (classe \a Tetra ) alors les sous-éléments sont des tiangles ( classes \a Triangle , \a Triangle_6 ) et ce maillage enfant sera un maillage de triangles. Et ainsi de suite le deuxième maillage enfant sera un maillage de barres (classes \a Bar , \a Bar_3 ).
    REMARQUE : la notion de maillage enfant ne doit pas être confondue avec celle de maillage peau. Si le maillage peau est un maillage de sous-éléments, il ne contient que ceux se trouvant sur le bord.

    La classe Mesh hérite de \a MeshGenericBis qui hérite à son tour de \a MeshGeneric . Elle hérite donc de leurs méthodes (e.g. sub_mesh() ).
    Pour un exemple complet utilisant la classe Mesh et une formulation, consultez l'exemple \a Comment resoudre un probleme element fini de façon générale .

    A finir

    \relates MeshGenericBis
    \relates MeshGeneric
    \relates MeshAncestor

    The entry class for all type of meshes. If you want to add elements, nodes, ... you must use Mesh<>
    \author Hugo LECLERC
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \keyword Maillage
    \keyword Algorithme/Conteneur
    \friend raphael.pasquier@lmt.ens-cachan.fr
 */

template<class Carac,unsigned max_sub_meshes=0>
class Mesh : public MeshGenericBis< Carac, false, MeshNbSubMeshes<Carac,max_sub_meshes>::res > {
public:
    enum { nb_sub_meshes = MeshNbSubMeshes<Carac,max_sub_meshes>::res };
    typedef MeshGenericBis< Carac, false, nb_sub_meshes > MGB;
    typedef MeshAncestor<Carac,0,false> MA;
    typedef typename MA::TNode TNode;
    typedef typename MA::TElemList TElemList;
    typedef MeshGenericBis< Carac, true, nb_sub_meshes > TSkin;
    template<class NE,class BE=DefaultBehavior> struct TElem { typedef typename TElemList::template TElem<NE,BE>::TE TE; };
    /*!
    Type utilisé seulement pour add_element().
    Il ne fait pas que transformer TE en TE*. lorsque l'utilisateur de add_element() souhaite ajouter un élément dont ne nom n'est pas dans le MeshCarac du maillage, add_element() ne renvoie pas un void* mais un ElementAncestor<TNode>* (mais la valeur reste NULL ).
    */
    template<class NE,class BE=DefaultBehavior> struct TElemPtr { 
        typedef typename TElem<NE,BE>::TE TE_;
        typedef typename AlternativeOnType< AreSameType<void, TE_>::res, TE_, typename MA::EA >::T* TE;
    };
    
    ///
    Mesh() {
        //PRINT( nb_sub_meshes );
        cpt_nodes = 0;
        date_last_skin_update = 0;
    }
    /// add a node using default constructor
    TNode *add_node() { TNode *res = this->node_list.hp.new_elem(); res->number = cpt_nodes++; return res; }
    /// helper function : call add_node() and set pos
    template<class Pvec> TNode *add_node(const Pvec &pos) { TNode *res = add_node(); res->pos = pos; return res; }
    
    Mesh &operator=(const Mesh &m) {
        free();
        append(m);
        return *this;
    }

    ///
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode **n) { 
    
    
    return MA::add_element_(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode *n0) { TNode *n[] = {n0}; return add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1) { TNode *n[] = {n0,n1}; return add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2) { TNode *n[] = {n0,n1,n2}; return add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3) { TNode *n[] = {n0,n1,n2,n3}; return this->add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4) { TNode *n[] = {n0,n1,n2,n3,n4}; return this->add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4,TNode *n5) { TNode *n[] = {n0,n1,n2,n3,n4,n5}; return this->add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4,TNode *n5,TNode *n6) { TNode *n[] = {n0,n1,n2,n3,n4,n5,n6}; return this->add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4,TNode *n5,TNode *n6,TNode *n7) { TNode *n[] = {n0,n1,n2,n3,n4,n5,n6,n7}; return this->add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4,TNode *n5,TNode *n6,TNode *n7, TNode *n8) { TNode *n[] = {n0,n1,n2,n3,n4,n5,n6,n7,n8}; return this->add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4,TNode *n5,TNode *n6,TNode *n7, TNode *n8,TNode *n9) { TNode *n[] = {n0,n1,n2,n3,n4,n5,n6,n7,n8,n9}; return this->add_element(ne,be,n); }
    
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,unsigned *n) { TNode *np[NE::nb_nodes]; for(unsigned i=0;i<NE::nb_nodes;++i) np[i] = &this->node_list[n[i]]; return MA::add_element_(ne,be,np); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,unsigned n0) { unsigned n[] = {n0}; return add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1) { unsigned n[] = {n0,n1}; return add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2) { unsigned n[] = {n0,n1,n2}; return add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3) { unsigned n[] = {n0,n1,n2,n3}; return add_element(ne,be,n); }
    
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3,unsigned n4,unsigned n5) { unsigned n[] = {n0,n1,n2,n3,n4,n5}; return add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3,unsigned n4,unsigned n5,unsigned n6) { unsigned n[] = {n0,n1,n2,n3,n4,n5,n6}; return add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3,unsigned n4,unsigned n5,unsigned n6,unsigned n7) { unsigned n[] = {n0,n1,n2,n3,n4,n5,n6,n7}; return add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3,unsigned n4,unsigned n5,unsigned n6,unsigned n7,unsigned n8) { unsigned n[] = {n0,n1,n2,n3,n4,n5,n6,n7,n8}; return add_element(ne,be,n); }
    template<class NE,class BE> typename TElemPtr<NE,BE>::TE add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3,unsigned n4,unsigned n5,unsigned n6,unsigned n7,unsigned n8,unsigned n9) { unsigned n[] = {n0,n1,n2,n3,n4,n5,n6,n7,n8,n9}; return add_element(ne,be,n); }


    ///
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode **n) { return MA::add_element_(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode *n0) { TNode *n[] = {n0}; return add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1) { TNode *n[] = {n0,n1}; return add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2) { TNode *n[] = {n0,n1,n2}; return add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3) { TNode *n[] = {n0,n1,n2,n3}; return this->add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4) { TNode *n[] = {n0,n1,n2,n3,n4}; return this->add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4,TNode *n5) { TNode *n[] = {n0,n1,n2,n3,n4,n5}; return this->add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4,TNode *n5,TNode *n6) { TNode *n[] = {n0,n1,n2,n3,n4,n5,n6}; return this->add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4,TNode *n5,TNode *n6,TNode *n7) { TNode *n[] = {n0,n1,n2,n3,n4,n5,n6,n7}; return this->add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4,TNode *n5,TNode *n6,TNode *n7, TNode *n8) { TNode *n[] = {n0,n1,n2,n3,n4,n5,n6,n7,n8}; return this->add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,TNode *n0,TNode *n1,TNode *n2,TNode *n3,TNode *n4,TNode *n5,TNode *n6,TNode *n7, TNode *n8,TNode *n9) { TNode *n[] = {n0,n1,n2,n3,n4,n5,n6,n7,n8,n9}; return this->add_element(ne,be,n); }
//     
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,unsigned *n) { TNode *np[NE::nb_nodes]; for(unsigned i=0;i<NE::nb_nodes;++i) np[i] = &this->node_list[n[i]]; return MA::add_element_(ne,be,np); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,unsigned n0) { unsigned n[] = {n0}; return add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1) { unsigned n[] = {n0,n1}; return add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2) { unsigned n[] = {n0,n1,n2}; return add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3) { unsigned n[] = {n0,n1,n2,n3}; return add_element(ne,be,n); }
//     
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3,unsigned n4,unsigned n5) { unsigned n[] = {n0,n1,n2,n3,n4,n5}; return add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3,unsigned n4,unsigned n5,unsigned n6) { unsigned n[] = {n0,n1,n2,n3,n4,n5,n6}; return add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3,unsigned n4,unsigned n5,unsigned n6,unsigned n7) { unsigned n[] = {n0,n1,n2,n3,n4,n5,n6,n7}; return add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3,unsigned n4,unsigned n5,unsigned n6,unsigned n7,unsigned n8) { unsigned n[] = {n0,n1,n2,n3,n4,n5,n6,n7,n8}; return add_element(ne,be,n); }
//     template<class NE,class BE> typename TElem<NE,BE>::TE *add_element(const NE &ne,const BE &be,unsigned n0,unsigned n1,unsigned n2,unsigned n3,unsigned n4,unsigned n5,unsigned n6,unsigned n7,unsigned n8,unsigned n9) { unsigned n[] = {n0,n1,n2,n3,n4,n5,n6,n7,n8,n9}; return add_element(ne,be,n); }
    
    
    /// to be called after add_element or add_node to say that update_... should recalculate (but it's not necessary the first time updates are called).
    void signal_connectivity_change() {
        this->signal_connectivity_change_rec(this->node_list);
        skin.signal_connectivity_change_rec(skin.node_list);
    }
    /// fonction à créer ou à mettre à jour le maillage de la peau. Pour accéder à la peau, on écrit m.skin().
    void update_skin( bool rm_intermediate_data = false ) { update_skin_( rm_intermediate_data, Number<MA::dim>() ); }
    /// Ne fait rien
    void update_skin_( bool rm_intermediate_data, Number<0> ) { }
    /// A faire
    template<unsigned inner>
    void update_skin_( bool rm_intermediate_data, Number<inner> ) {
        if ( date_last_skin_update == this->date_last_connectivity_change )
            return;
        date_last_skin_update = this->date_last_connectivity_change;
        //
        
        this->update_elem_parents(Number<1>());
        LMTPRIVATE::AddElemWith1Parent<Mesh> ae;
        ae.m = this;
        ae.marqued.resize( this->node_list.size(), 0 );
        this->skin.free();
        this->skin.node_list.nb.free();
        // elements
        apply( this->sub_mesh(Number<1>()).elem_list, ae );
        // nodes
        // skin.node_list.nb.reserve( this->node_list.size() );
        for(unsigned i=0,cpt=0;i<this->node_list.size();++i) {
            if ( ae.marqued[i] ) {
                this->skin.node_list.hp.push_back( &this->node_list[i] );
                this->skin.node_list.nb.push_back( cpt++ );
            }
            else
                this->skin.node_list.nb.push_back( 0 );
        }
        // parents
        for(unsigned i=0;i<TSkin::TElemList::nb_elem_type;++i)
            this->skin.elem_parents[i] = ae.parents[i];
    
    
        // 
        if ( rm_intermediate_data ) {
            this->clear_elem_children();
            this->sub_mesh(Number<1>()).free();
        }
    
    }
    /// 
    void free() {
        MGB::free();
        skin.free();
        cpt_nodes = 0;
    }
private:
    struct AppendDataFrom {
        template<class TE,class TM2> void operator()(const TE &e,const TM2 &m,Mesh *th,const Vec<TNode *> &new_nodes) const {
            TNode *nn[ TE::nb_nodes ];
            for(unsigned i=0;i<TE::nb_nodes;++i)
                nn[i] = new_nodes[ m.node_list.number(*e.node(i)) ];
            typename TElemList::template TElem<typename TE::NE,typename TE::BE>::TE *ne = th->add_element( typename TE::NE(), typename TE::BE(), nn );
            DM::copy( e, *ne );
        }
        template<class TN> void operator()(const TN &node,Mesh *th,Vec<TNode *> &new_nodes) const {
            TNode *n = th->add_node();
            DM::copy( node, *n );
            new_nodes.push_back( n );
        }
    };
public:
    /*! Append nodes of m to *this. addresses of new nodes are appended to new_nodes. Data of nodes is copied using DM::copy()
        Used in append().
    */
    template<class TM2> void append_nodes_of(const TM2 &m,Vec<TNode *> &new_nodes) {
        new_nodes.reserve( new_nodes.size() + m.node_list.size() );
        apply( m.node_list, AppendDataFrom(), this, new_nodes );
    }
    /*!
        Append data, nodes and elements of a mesh m to this. 
    */
    template<class TM2> void append(const TM2 &m) {
        Vec<TNode *> new_nodes;
        append_nodes_of( m, new_nodes );
        
        apply( m.elem_list, AppendDataFrom(), m, this, new_nodes );
        
        DM::copy( m, *this );
    }
private:
    template<class Op> struct RemoveElementIf {
        template<class TE> bool operator()(TE &e) {
            if ( (*op)(e)==false ) return false;
            --m->cpt_elem[ TE::num_in_elem_list ];
            m->move_elem_children_data_rec( e, m->cpt_elem[ TE::num_in_elem_list ], e.number );
            res = true;
            return true;
        }
        Mesh *m;
        Op *op;
        bool res;
    };
    template<class Op> friend struct FilterElements;
public:
    /// Rq : dyn_data and child elements are automatically adjusted (but nor neighbours neitheir parents).
    /// return true if some elements have been removed
    template<class Op> bool remove_elements_if(Op &op) {
        RemoveElementIf<Op> nop;
        nop.op = &op; nop.m = this; nop.res = false;
        this->elem_list.remove_if(nop); 
        if ( nop.res )
            signal_connectivity_change();
        return nop.res;
    }
    /*!
        num_sub_list -> type of element
        num_in_sub_list -> number of element in sub_vec<num_sub_list>()
    */
    void remove_element_nb(unsigned num_sub_list,unsigned num_in_sub_list) {
        this->elem_list.remove_nb(num_sub_list,num_in_sub_list); 
        signal_connectivity_change();
    }
private:
    struct RemoveNodesIf {
        template<class TE> bool operator()(TE &e) {
            for(unsigned i=0;i<TE::nb_nodes;++i)
                if ( keep_nodes[e.node(i)->number_in_original_mesh()] == false )
                    return true;
            for(unsigned i=0;i<TE::nb_nodes;++i)
                e.nodes[i] = new_node_list[ e.nodes[i]->number_in_original_mesh() ];
            return false;
        }
        bool operator()(TNode &node) {
            bool res = keep_nodes[ node.number_in_original_mesh() ];
            if ( res ) return false;
            at_least_one_rm = true;
            return true;
            
        }
        bool *keep_nodes;
        Vec<TNode *> new_node_list;
        unsigned cpt;
        bool at_least_one_rm;
    };
public:
    /// Rq : dyn_data is automatically adjusted.
    /// elements which contain nodes to remove will be removed
    void keep_nodes_if(bool *keep_nodes) {
        RemoveNodesIf rc;
        rc.keep_nodes = keep_nodes;
        rc.at_least_one_rm = false;
        rc.new_node_list.resize(this->node_list.size());
        for(unsigned i=0,j=this->node_list.size();i<j;++i) {
            if ( keep_nodes[i] )
                rc.new_node_list[i] = &this->node_list[i];
            else {
                while( j>i && keep_nodes[--j]==false );
                rc.new_node_list[j] = &this->node_list[i];
            }
        }
        
        remove_elements_if(rc);
        
        remove_if(this->node_list.hp, rc);

        //if ( rc.at_least_one_rm ) {
            for(unsigned i=0;i<this->node_list.size();++i)
                this->node_list[i].number = i;
            signal_connectivity_change();
        //}
    }
private:
    struct MarkUsedNodes {
        template<class TE> void operator()(TE &e) {
            for(unsigned i=0;i<TE::nb_nodes;++i)
                used_nodes[e.node(i)->number_in_original_mesh()] = true;
        }
        Vec<bool> used_nodes;
    };
public:
    ///
    void remove_unused_nodes() {
        MarkUsedNodes mun;
        mun.used_nodes.resize(this->node_list.size(),false);
        apply( this->elem_list, mun );
        keep_nodes_if(mun.used_nodes.begin());
        cpt_nodes = this->node_list.size();
    }
    
    ///
    TSkin skin;
private:
    unsigned cpt_nodes;
    unsigned date_last_skin_update;
};

namespace LMTPRIVATE {
    template<class TM> struct AddElemWith1Parent {
        template<class TSE> void operator()(TSE &pse) {
            if ( m->sub_mesh(Number<1>()).get_parents_of(pse).size()==1 ) {
                typedef typename TM::TSkin::template TElem<typename TSE::NE,typename TSE::BE>::TE NTE;
                m->skin.add_element( typename TSE::NE(), typename TSE::BE(), pse.nodes ); // NTE *nte = 
                for(unsigned i=0;i<TSE::nb_nodes;++i) marqued[m->node_list.number(*pse.node(i))] = true;
                parents[ NTE::num_in_elem_list ].push_back( *m->sub_mesh(Number<1>()).get_parents_of(pse) );
            }
        }
        TM *m;
        Vec<unsigned> marqued;
        Vec<Vec<typename TM::EA *,1> > parents[TM::TSkin::TElemList::nb_elem_type+(TM::TSkin::TElemList::nb_elem_type==0)];
    };
};

//
// struct Copy_data_from_sub_mesh_to_skin {
//     template<class TE,class TM> void operator()( TE &e, TM &m ) const {
//         typename TM::TEA p
//     }
// };
//
// template<class TM> copy_data_from_sub_mesh_to_skin( TM &m ) {
//     apply( m.skin.elem_list, Copy_data_from_sub_mesh_to_skin(), m );
// }


};

#endif
