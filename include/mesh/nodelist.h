//
// C++ Interface: %{MODULE}
//
// Description: 
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_NODE_LIST_HEADER
#define LMT_NODE_LIST_HEADER

namespace LMT {

template<class CaracName> class Mesh;
template<class CaracName,unsigned nvi_to_subs,unsigned skin,unsigned end_nvi_to_subs> class MeshGeneric;
template<class CaracName,unsigned skin,unsigned end_nvi_to_subs> class MeshGenericBis;

template<class TNode,bool use_ptr> class VecNodeList;
template<class TNode,bool use_ptr> struct IsVecOp<VecNodeList<TNode,use_ptr> > { typedef int T; };

/// stores nodes in a SplittedVector. nodes can be added/removed... only from Mesh<>
template<class TNode>
class Vec<VecNodeList<TNode,false>,-1,int> {
public:
    template<unsigned n,unsigned inner=0> struct SubType { typedef TNode T; };
    template<unsigned inner> struct SubType<1,inner> { typedef void T; };
    static const unsigned nb_sub_type = 1;
    static const int sparsity_rate = 1;

    /// number of nodes
    unsigned size() const { return hp.size(); }
    
    ///
    TNode &operator[](unsigned i) { return hp[i]; }
    const TNode &operator[](unsigned i) const { return hp[i]; }
    
    ///
    unsigned number(const TNode &node) const { return node.number; }
    
    
    /// registering a DynamicData field can be pertinent when functions like mesh.filter_nodes(...) are used :
    ///  data in dda will automatically be re-ordered.
    template<class T> void reg_dyn(DynamicData<T,0> *dda) { dyn_data.push_back(dda); synchronize_dyn(dda); }
    /// 
    template<class T> void unreg_dyn(DynamicData<T,0> *dda) { dyn_data.erase_first(dda); }
    ///
    void synchronize_dyn(DynamicDataAncestor *dda) const { dda->resize(0,size()); }
    /// autmatically called by signal_connectivity_change() in Mesh<>. call synchronize_dyn() with all dda registered using reg_dyn
    void synchronize_all_dyn() const { for(unsigned i=0;i<dyn_data.size();++i) synchronize_dyn(dyn_data[i]); }
    ///
    unsigned nb_dyn_data() const { return dyn_data.size(); }
    ///
    DynamicDataAncestor *get_dyn_data(unsigned i) { return dyn_data[i]; }
    ///
    const DynamicDataAncestor *get_dyn_data(unsigned i) const { return dyn_data[i]; }
    
    /// uniform interface for static and dynamic data.
    template<class T> T &get_data(DynamicData<T,0> &dda,const TNode &n) { return dda.get_data(n.number); }
    template<class T> const T &get_data(const DynamicData<T,0> &dda,const TNode &n) const { return dda.get_data(n.number); }
    template<class NDM> typename TNode::template SubTypeByName0<NDM>::TT &get_data(const NDM &ndm,TNode &n) { return n.member_named(ndm); }
    template<class NDM> const typename TNode::template SubTypeByName0<NDM>::TT &get_data(const NDM &ndm,const TNode &n) const { return n.member_named(ndm); }
    
    ///
    Vec<Splitted<TNode,16> > hp;
    ///
    void pop_back(unsigned nb_val) { hp.pop_back(nb_val); for(unsigned i=0;i<dyn_data.size();++i) dyn_data[i]->pop_back(nb_val); }
protected:
    ///
    void free() { hp.free(); for(unsigned i=0;i<dyn_data.size();++i) dyn_data[i]->free(); }
    ///
    void is_a_ref_of(Vec &nl) { hp.is_a_ref_of(nl.hp); }
    ///
    Vec<DynamicDataAncestor *> dyn_data;
    ///
    template<class CaracName> friend class Mesh;
    template<class CN,unsigned NV,unsigned SK,unsigned MSK> friend class MeshGeneric;
    template<class CN,unsigned SK,unsigned MSK> friend class MeshGenericBis;
};


/// With pointer
template<class TNode>
class Vec<VecNodeList<TNode,true>,-1,int> {
public:
    template<unsigned n,unsigned inner=0> struct SubType { typedef TNode* T; };
    template<unsigned inner> struct SubType<1,inner> { typedef void T; };
    static const int sparsity_rate = 1;
    
    /// number of nodes
    unsigned size() const { return hp.size(); }
    
    ///
    TNode &operator[](unsigned i) { return *hp[i]; }
    const TNode &operator[](unsigned i) const { return *hp[i]; }
    
    ///
    unsigned number(const TNode &node) const { return nb[node.number]; }
    
    
    /// registering a DynamicData field can be pertinent when functions like mesh.filter_nodes(...) are used :
    ///  data in dda will automatically be re-ordered.
    template<class T> void reg_dyn(DynamicData<T,0> *dda) { dyn_data.push_back(dda); synchronize_dyn(dda); }
    /// 
    template<class T> void unreg_dyn(DynamicData<T,0> *dda) { dyn_data.erase_first(dda); }
    ///
    void synchronize_dyn(DynamicDataAncestor *dda) const { dda->resize(0,size()); }
    /// autmatically called by signal_connectivity_change() in Mesh<>. call synchronize_dyn() with all dda registered using reg_dyn
    void synchronize_all_dyn() const { for(unsigned i=0;i<dyn_data.size();++i) synchronize_dyn(dyn_data[i]); }
    ///
    unsigned nb_dyn_data() const { return dyn_data.size(); }
    ///
    DynamicDataAncestor *get_dyn_data(unsigned i) { return dyn_data[i]; }
    ///
    const DynamicDataAncestor *get_dyn_data(unsigned i) const { return dyn_data[i]; }
    
    /// uniform interface for static and dynamic data.
    template<class T> T &get_data(DynamicData<T,0> &dda,const TNode &n) { return dda.get_data(nb[n.number]); }
    template<class T> const T &get_data(const DynamicData<T,0> &dda,const TNode &n) const { return dda.get_data(nb[n.number]); }
    template<class NDM> typename NDM::template SubTypeByName0<NDM>::TT &get_data(const NDM &ndm,TNode &n) { return n.member_named(ndm); }
    template<class NDM> const typename NDM::template SubTypeByName0<NDM>::TT &get_data(const NDM &ndm,const TNode &n) const { return n.member_named(ndm); }

    ///
    Vec<Splitted<TNode *,256> > hp;
protected:
    ///
    void free() { nb.free(); hp.free(); for(unsigned i=0;i<dyn_data.size();++i) dyn_data[i]->free(); }
    ///
    void is_a_ref_of(Vec &nl) { hp.is_a_ref_of(nl.hp); nb.is_a_ref_of(nl.nb); }
    /// correspondance number in original mesh -> number in this mesh
    Vec<Splitted<unsigned,256> > nb;
    ///
    Vec<DynamicDataAncestor *> dyn_data;
    ///
    template<class CaracName> friend class Mesh;
    template<class CN,unsigned NV,unsigned SK,unsigned MSK> friend class MeshGeneric;
    template<class CN,unsigned SK,unsigned MSK> friend class MeshGenericBis;
};

};

#include "nodelistapply.h"

#endif // LMT_NODE_LIST_HEADER

