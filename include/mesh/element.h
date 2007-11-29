//
// C++ Interface: element
//
// Description:
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMTELEMENT_H
#define LMTELEMENT_H

#include "meshdata.h"
#include "nbchildrenelement.h"

namespace LMT {

///
template<class TNode_>
class ElementAncestor {
public:
    typedef TNode_ TNode;
    typedef typename TNode_::T T;
    static const unsigned dim = TNode::dim;
    
    virtual unsigned nb_nodes_virtual() const = 0;
    virtual unsigned nb_var_inter_virtual() const = 0;
    virtual TNode *node_virtual(unsigned i) = 0;
    virtual const TNode *node_virtual(unsigned i) const = 0;
    virtual void set_node_virtual(unsigned i,TNode *n) = 0;
    virtual const char *name_virtual() const = 0;
    virtual const char *can_directly_be_represented_by_virtual() = 0;
    virtual unsigned num_in_elem_list_virtual() const = 0;
    virtual T measure_virtual() const = 0;

    virtual typename TNode::Pvec sample_normal_virtual() const = 0;
    virtual typename TNode::Pvec sample_tangent_virtual() const = 0;
    
    virtual void set_field( const std::string field_name, T value ) = 0;
    virtual void set_field( const std::string field_name, Vec<T,3> value ) = 0;

    unsigned number;
    
    virtual ~ElementAncestor() {}
};

template<class TNode>
std::ostream &operator<<(std::ostream &os,const ElementAncestor<TNode> &ea) {
    os << ea.name_virtual();
    for(unsigned i=0;i<ea.nb_nodes_virtual();++i)
        os << " " << ea.node_virtual(i)->number_in_original_mesh();
    return os;
}

///
template<class NameElem_,class NameBehavior,class TNode_,class TData,unsigned num_in_elem_list_>
class Element : public TData, public ElementAncestor<TNode_> {
public:
    typedef NameElem_ NameElem;
    typedef TNode_ TNode;
    typedef typename TNode::T T;
    typedef typename TNode::Pvec Pvec;
    typedef ElementAncestor<TNode> EA;
    typedef Element TClass;
    typedef Element* TClassPtr;
    static const unsigned nb_nodes = NameElem::nb_nodes;
    static const unsigned nb_var_inter = NameElem::nb_var_inter;
    static const char *name() {
        return NameElem::name();
    }
    static const char *can_directly_be_represented_by() {
        return NameElem::can_directly_be_represented_by();
    }
    typedef NameElem NE;
    typedef NameBehavior BE;
    typedef TData TD;
    static const unsigned num_in_elem_list = num_in_elem_list_;

    TNode *node(unsigned i) {
        return nodes[i];
    }
    const TNode *node(unsigned i) const {
        return nodes[i];
    }
    virtual void set_node_virtual(unsigned i,TNode *n) {
        nodes[i] = n;
    }
    
    Pvec pos(unsigned i) const { return nodes[i]->pos; }

    TNode *nodes[nb_nodes];

    /// nb fields
    static const unsigned nb_params = DM::NbFields<TData>::res;

    // virtual
    virtual unsigned nb_nodes_virtual() const {
        return nb_nodes;
    }
    virtual unsigned nb_var_inter_virtual() const {
        return nb_var_inter;
    }
    virtual TNode *node_virtual(unsigned i) {
        return node(i);
    }
    virtual const TNode *node_virtual(unsigned i) const {
        return node(i);
    }
    virtual const char *name_virtual() const {
        return name();
    }
    virtual const char *can_directly_be_represented_by_virtual() {
        return can_directly_be_represented_by();
    }
    virtual unsigned num_in_elem_list_virtual() const {
        return num_in_elem_list;
    }

    virtual typename TNode::Pvec sample_normal_virtual() const {
        return sample_normal(*this);
    }
    virtual typename TNode::Pvec sample_tangent_virtual() const {
        return sample_tangent(*this);
    }
    virtual T measure_virtual() const { return measure( *this ); }
    
    virtual ~Element() {}
    
    virtual void set_field( const std::string field_name, T value ) { TData::dm_data_set_field( field_name, value ); }
    virtual void set_field( const std::string field_name, Vec<T,3> value ) { TData::dm_data_set_field( field_name, value ); }
};

///
template<class NameBehavior,class TN,class TData,unsigned num_in_elem_list>
class Element<void,NameBehavior,TN,TData,num_in_elem_list> {
public:
    typedef void TClass;
    typedef void TClassPtr;
    typedef void NE;
};

/// to be specialized for each geometric element
template<class T1,class T2,class T3,unsigned nvi_to_subs>
void append_skin_elements(const T1 &,const T2 &,const T3 &,const Number<nvi_to_subs> &n) {}

/// isobarycenter of nodes
template<class NameElem,class NameBehavior,class TNode,class TData,unsigned num_in_elem_list>
typename TNode::Pvec center(const Element<NameElem,NameBehavior,TNode,TData,num_in_elem_list> &e) {
    typename TNode::Pvec res = 0.0;
    for(unsigned i=0;i<NameElem::nb_nodes;++i)
        res += e.node(i)->pos;
    return res / NameElem::nb_nodes;
}
template<class TNode>
typename TNode::Pvec center(const ElementAncestor<TNode> &e) {
    typename TNode::Pvec res = 0.0;
    for(unsigned i=0;i<e.nb_nodes_virtual();++i)
        res += e.node_virtual(i)->pos;
    return res / e.nb_nodes_virtual();
}

template<class TE>
typename TE::Pvec sample_normal(const TE &e) {
    assert(0); // not implemented
}

struct EquElem {
    template<class TE1,class TE2>
    bool operator()(const TE1 &e1,const TE2 &e2) const {
        if ( AreSameType<typename TE1::NE,typename TE2::NE>::res == false )
            return false;
        unsigned nb_eq = 0;
        for(unsigned i=0;i<TE1::nb_nodes;++i)
            for(unsigned j=0;j<TE2::nb_nodes;++j)
                nb_eq += ( length( e1.node(i)->pos - e2.node(j)->pos ) < 1e-6 );
        return ( nb_eq==TE1::nb_nodes );
    }
};

struct DistBetweenElemCenter {
    template<class P1,class P2,class T3=void,class T4=void> struct ReturnType { typedef typename TypePromote<Plus,typename P1::T,typename P2::T>::T T; };
    template<class P1,class P2> typename TypePromote<Plus,typename P1::T,typename P2::T>::T operator()(const P1 &n1,const P2 &n2) const {
        return length(center(n2)-center(n1));
    }
};

/**
    Trouve les veriables d'interpolation correspondant à la position pos.
    On suppose que var_inter n'est pas initialisé.
  */
template<class TE,class Pvec,class TVI> void get_var_inter(const TE &elem,const Pvec &pos,TVI &var_inter,typename TE::T criterium) {
    Vec<Vec<typename TE::T,TE::dim>,TE::nb_nodes> pos_nodes;
    for(unsigned i=0;i<TE::nb_nodes;++i)
        pos_nodes[i] = elem.pos(i);
    
    get_var_inter_linear( typename TE::NE(), pos_nodes, pos, var_inter );
//     Vec<typename TE::T,TE::nb_var_inter> old_var_inter = var_inter;
//     while ( true ) {
//         get_var_inter( typename TE::NE(), pos_nodes, pos, var_inter );
//         get_var_inter( typename TE::NE(), pos_nodes, pos, var_inter );
//         get_var_inter( typename TE::NE(), pos_nodes, pos, var_inter );
//         if ( length( old_var_inter - var_inter ) < criterium )
//             break;
//         old_var_inter = var_inter;
//     }
}

template<class TE> typename TE::Pvec sample_tangent( const TE &e ) {
    assert( 0 ); // non défini
    return typename TE::Pvec(0);
}

};

#endif
