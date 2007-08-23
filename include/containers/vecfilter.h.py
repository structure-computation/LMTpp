import string
from vecgenhelp import *

print """
namespace LMT {
/** Works only for linear vectors */
template<class V0,class V1,bool const_v0=true> struct VecSelect {};

template<class V0,class V1,bool const_v0> struct IsVecOp<VecSelect<V0,V1,const_v0> > { typedef int T; };
template<class V0,class V1,bool const_v0> struct HasIndexAccess<VecSelect<V0,V1,const_v0> > { static const bool res = false; };

template<class V0,class V1,bool const_v0>
class Vec<VecSelect<V0,V1,const_v0>,-1,int> {
public:
    template<unsigned n> struct SubType { typedef typename V0::template SubType<n>::T T; };
    static const unsigned nb_sub_type = V0::nb_sub_type;
    
    static const int static_size = -1;
    static const bool fixed_size = false;
    static const int sparsity_rate = 0;

    Vec(const V0 &vv0,const V1 &vv1):v1(vv1) { v0.val = &vv0; }
    Vec(V0 &vv0,const V1 &vv1):v1(vv1) { v0.val = &vv0; }
    
    template<class Op,bool const_op> struct FilterI {
        template<class T> void operator()(const T &val0) { if ( (*v1)[i++] ) (*op.val)( val0 ); }
        template<class T> void operator()(      T &val0) { if ( (*v1)[i++] ) (*op.val)( val0 ); }

        template<class T,class P0> void operator()(const T &val0,const P0 &p0) { if ( (*v1)[i++] ) (*op.val)( val0, p0 ); }
        template<class T,class P0> void operator()(const T &val0,      P0 &p0) { if ( (*v1)[i++] ) (*op.val)( val0, p0 ); }
        template<class T,class P0> void operator()(      T &val0,const P0 &p0) { if ( (*v1)[i++] ) (*op.val)( val0, p0 ); }
        template<class T,class P0> void operator()(      T &val0,      P0 &p0) { if ( (*v1)[i++] ) (*op.val)( val0, p0 ); }

        template<class T,class P0,class P1> void operator()(const T &val0,const P0 &p0,const P1 &p1) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(const T &val0,const P0 &p0,      P1 &p1) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(const T &val0,      P0 &p0,const P1 &p1) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(const T &val0,      P0 &p0,      P1 &p1) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(      T &val0,const P0 &p0,const P1 &p1) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(      T &val0,const P0 &p0,      P1 &p1) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(      T &val0,      P0 &p0,const P1 &p1) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(      T &val0,      P0 &p0,      P1 &p1) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1 ); }

        template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,const P1 &p1,const P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,const P1 &p1,      P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,      P1 &p1,const P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,      P1 &p1,      P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,const P1 &p1,const P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,const P1 &p1,      P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,      P1 &p1,const P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,      P1 &p1,      P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,const P1 &p1,const P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,const P1 &p1,      P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,      P1 &p1,const P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,      P1 &p1,      P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,const P1 &p1,const P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,const P1 &p1,      P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,      P1 &p1,const P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,      P1 &p1,      P2 &p2) { if ( (*v1)[i++] ) (*op.val)( val0, p0, p1, p2 ); }
        
        PtrConstIf<Op,const_op> op;
        const V1 *v1;
        unsigned i;
    };

    struct GetNb { template<class TTT> void operator()(const TTT &v,const V1 &v1,unsigned &res) const { res += bool(v1(v)); } };
    unsigned size() const {
        unsigned res = 0;
        apply(*v0.val,GetNb(),v1,res);
        return res;
    }
    
"""+SELFOP+"""
    
    PtrConstIf<V0,const_v0> v0;
    const V1 &v1;
};

/**
    Return a vector containing v0[i] if v1[1]!=False
    \\relates Vec
*/
template<class V0,class V1> Vec<VecSelect<V0,V1,true > > select(const V0 &v0,const V1 &v1) { return Vec<VecSelect<V0,V1,true > >(v0,v1); }
/**
    Return a vector containing v0[i] if v1[1]!=False
    \\relates Vec
*/
template<class V0,class V1> Vec<VecSelect<V0,V1,false> > select(V0 &v0,const V1 &v1) { return Vec<VecSelect<V0,V1,false> >(v0,v1); }

"""

TT = ['class V0','class V1','bool const_v0']
TV = 'Vec<VecSelect<V0,V1,const_v0>,s,int>'

print_apply_ext('apply',TT,TV,'typename '+TV+'::template FilterI<Op,ONEIFCONSTOP> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,PARALIST);')
print_apply_ext('apply_wi',TT,TV,'OpWithIncrement<Op,ONEIFCONSTOP> opi(op); apply(v,opi,PARALIST);')

print '} // namespace LMT'
