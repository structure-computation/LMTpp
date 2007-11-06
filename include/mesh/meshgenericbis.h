//
// C++ Interface: meshgenericbis
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_meshgenericbis_HEADER
#define LMT_meshgenericbis_HEADER

#include "meshgeneric.h"

namespace LMT {

/**
    Used to define Mesh<> and Mesh<>::skin
    
    \author Hugo LECLERC
*/
template<class CaracName,unsigned skin,unsigned end_nvi_to_subs>
class MeshGenericBis : public MeshGeneric<CaracName,skin,skin,end_nvi_to_subs> {
public:
    typedef MeshGeneric<CaracName,skin,skin,end_nvi_to_subs> MG;
    typedef typename MG::TNode TNode;
    typedef ElementAncestor<TNode> EA;
    
    MeshGenericBis() {}
    /// only for Mesh<> or skin
    void update_elem_children() { this->next.update_elem_children_rec(this->elem_list,this->node_list); }
    /// only for Mesh<> or skin
    template<unsigned nvi_to_subs> void update_elem_children(const Number<nvi_to_subs> &n) { this->sub_mesh(n).update_elem_children_rec(this->elem_list,this->node_list); }
    /// free memory
    void clear_elem_children() { this->clear_elem_children_rec(); }
    /// free memory of children / nvi_to_subs
    template<unsigned nvi_to_subs> void clear_elem_children(const Number<nvi_to_subs> &n) { this->sub_mesh(n).clear_elem_children_g(); }
    ///
    
    template<class TE,unsigned nvisubs> EA * const *get_children_of(const TE &e,const Number<nvisubs> &nnn) {
        DEBUGASSERTWC( sub_mesh(nnn).date_last_elem_chidren_update == sub_mesh(nnn).date_last_connectivity_change, "update_elem_children should have been called before get_children_of" );
        static const unsigned nb_children = NbChildrenElement<typename TE::NE,nvisubs>::res;
        return &sub_mesh(nnn).elem_children[TE::num_in_elem_list][ e.number * nb_children ];
    }
    template<class TE,unsigned nvisubs> const EA * const *get_children_of(const TE &e,const Number<nvisubs> &nnn) const {
        DEBUGASSERTWC( sub_mesh(nnn).date_last_elem_chidren_update == sub_mesh(nnn).date_last_connectivity_change, "update_elem_children should have been called before get_children_of" );
        static const unsigned nb_children = NbChildrenElement<typename TE::NE,nvisubs>::res;
        return &sub_mesh(nnn).elem_children[TE::num_in_elem_list][ e.number * nb_children ];
    }
    
    //     template<class TE> EA * const *get_children_of(const TE &e,const Number<0> &nnn) {
    //       return e; 
    //     }
    //     template<class TE> const EA * const *get_children_of(const TE &e,const Number<0> &nnn) {
    //        return e; 
    //     }
    //    
    
    /// only for Mesh<> or skin. Automatically call update_elem_children() (you'll have to free it manually if yo want to).
    void update_elem_parents() { update_elem_children(); this->next.update_elem_parents_rec( this->elem_list ); }
    /// only for Mesh<> or skin. Automatically call update_elem_children() (you'll have to free it manually if yo want to).
    template<unsigned nvi_to_subs> void update_elem_parents(const Number<nvi_to_subs> &n) {
        update_elem_children(n);
        this->sub_mesh(n).update_elem_parents_g( this->elem_list );
    }
    ///
    void clear_elem_parents() { this->clear_elem_parents_rec(); }
};

///
template<class CaracName,unsigned skin>
class MeshGenericBis<CaracName,skin,skin> {
public:
};

};

#endif // LMT_meshgenericbis_HEADER
