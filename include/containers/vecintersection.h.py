import string
from vecgenhelp import *

print """
namespace LMT {
/** Return elements of V0 which are also in V1 */
template<class V0,class V1,bool const_v0=true,bool v0_is_sorted=false,bool v1_is_sorted=false> struct Intersection {};

template<class V0,class V1,bool const_v0,bool v0_is_sorted,bool v1_is_sorted> struct IsVecOp<Intersection<V0,V1,const_v0,v0_is_sorted,v1_is_sorted> > { typedef int T; };
template<class V0,class V1,bool const_v0,bool v0_is_sorted,bool v1_is_sorted> struct HasIndexAccess<Intersection<V0,V1,const_v0,v0_is_sorted,v1_is_sorted> > { static const bool res = false; };

template<class V0,class V1,bool const_v0>
class Vec<Intersection<V0,V1,const_v0,false,false>,-1,int> {
public:
    template<unsigned n> struct SubType { typedef typename V0::template SubType<n>::T T; };
    static const unsigned nb_sub_type = V0::nb_sub_type;
    
    static const int static_size = -1;
    static const bool fixed_size = false;
    static const int sparsity_rate = 0;

    Vec(const V0 &vv0,const V1 &vv1):v1(vv1) { v0.val = &vv0; }
    Vec(V0 &vv0,const V1 &vv1):v1(vv1) { v0.val = &vv0; }
    
    template<class Op,bool const_op> struct Inter {
        template<class T> void operator()(const T &val0) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0 ); }
        template<class T> void operator()(      T &val0) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0 ); }

        template<class T,class P0> void operator()(const T &val0,const P0 &p0) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0 ); }
        template<class T,class P0> void operator()(const T &val0,      P0 &p0) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0 ); }
        template<class T,class P0> void operator()(      T &val0,const P0 &p0) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0 ); }
        template<class T,class P0> void operator()(      T &val0,      P0 &p0) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0 ); }

        template<class T,class P0,class P1> void operator()(const T &val0,const P0 &p0,const P1 &p1) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(const T &val0,const P0 &p0,      P1 &p1) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(const T &val0,      P0 &p0,const P1 &p1) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(const T &val0,      P0 &p0,      P1 &p1) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(      T &val0,const P0 &p0,const P1 &p1) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(      T &val0,const P0 &p0,      P1 &p1) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(      T &val0,      P0 &p0,const P1 &p1) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1 ); }
        template<class T,class P0,class P1> void operator()(      T &val0,      P0 &p0,      P1 &p1) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1 ); }

        template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,const P1 &p1,const P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,const P1 &p1,      P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,      P1 &p1,const P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,      P1 &p1,      P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,const P1 &p1,const P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,const P1 &p1,      P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,      P1 &p1,const P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,      P1 &p1,      P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,const P1 &p1,const P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,const P1 &p1,      P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,      P1 &p1,const P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,      P1 &p1,      P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,const P1 &p1,const P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,const P1 &p1,      P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,      P1 &p1,const P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,      P1 &p1,      P2 &p2) const { if ( find( *v1,  Equal(), val0 ) ) (*op.val)( val0, p0, p1, p2 ); }
        
        PtrConstIf<Op,const_op> op;
        const V1 *v1;
    };
"""+SELFOP+"""
    PtrConstIf<V0,const_v0> v0;
    const V1 &v1;
};

/** return elements of V0 which are also in v1
    \relate Vec
*/
template<class V0,class V1> Vec<Intersection<V0,V1,true > > intersection(const V0 &v0,const V1 &v1) { return Vec<Intersection<V0,V1,true> >(v0,v1); }

/** return elements of V0 which are also in v1
    \relate Vec
*/
template<class V0,class V1> Vec<Intersection<V0,V1,false> > intersection(V0 &v0,const V1 &v1) { return Vec<Intersection<V0,V1,false> >(v0,v1); }

"""

TT = ['class V0','class V1','bool const_v0']
TV = 'Vec<Intersection<V0,V1,const_v0>,s,int>'
print_apply_ext('apply',TT,TV,'typename '+TV+'::template Inter<Op,ONEIFCONSTOP> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,PARALIST);')
print_apply_ext('apply_wi',TT,TV,'OpWithIncrement<Op,ONEIFCONSTOP> opi(op); apply(v,opi,PARALIST);')

print '} // namespace LMT'
