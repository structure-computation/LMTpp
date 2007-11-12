//
// C++ Interface: node
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMTNODE_H
#define LMTNODE_H

namespace LMT {

template<class CaracName,unsigned max_sub_meshes> class Mesh;
template<class Carac,unsigned nvi_to_subs,unsigned skin> class MeshAncestor;

/**
@author Hugo LECLERC
*/
template<unsigned _dim_,class _T_,class TNodalStaticData>
class Node : public TNodalStaticData {
public:
    typedef _T_ T;
    static const unsigned dim = _dim_;
    typedef TNodalStaticData NodalData;
    typedef Vec<_T_,_dim_> Pvec;
    
    static const unsigned nb_params = DM::NbFields<TNodalStaticData>::res;

    unsigned number_in_original_mesh() const { return number; }
//private:
    /// 
    unsigned number;
    template<class TT,int s,class O> friend class Vec;
    template<class CaracName,unsigned max_sub_meshes> friend class Mesh;
    template<class Carac,unsigned nvi_to_subs,unsigned skin> friend class MeshAncestor;
};

struct DispNode {
    template<class TD> void operator()(unsigned i,const char *name,const TD &d) { *os << name << ": " << d << " "; }
    std::ostream *os;
};

template<unsigned d,class T,class TN> std::ostream &operator<<(std::ostream &os,const Node<d,T,TN> &n) {
    DispNode dn; dn.os = &os;
    DM::apply_with_names( n, dn );
    return os;
}

struct DistBetweenNodes {
    template<class P1,class P2,class T3=void,class T4=void> struct ReturnType { typedef typename TypePromote<Plus,typename P1::T,typename P2::T>::T T; };
    template<class P1,class P2> typename TypePromote<Plus,typename P1::T,typename P2::T>::T operator()(const P1 &n1,const P2 &n2) const {
        return length(n2.pos-n1.pos);
    }
};

};

#endif
