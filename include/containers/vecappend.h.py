import string
from vecgenhelp import *

print """
namespace LMT {

/**
    Used to concatenate 2 vectors
*/
template<class V0,bool v0_const=true,class V1=void,bool v1_const=true,class V2=void,bool v2_const=true,class V3=void,bool v3_const=true> struct VecAppend {};

template<class V0,bool v0_const,class V1,bool v1_const> struct IsVecOp<VecAppend<V0,v0_const,V1,v1_const> > { typedef int T; };


template<class V0,bool v0_const,class V1,bool v1_const,int ss>
class Vec<VecAppend<V0,v0_const,V1,v1_const>,ss,int> {
public:
    template<unsigned n> struct SubType {
        typedef typename AlternativeOnType< (n >= V0::nb_sub_type),
            typename V0::template SubType<n>::T,
            typename V1::template SubType<n-V0::nb_sub_type>::T
        >::T T;
    };
    static const unsigned nb_sub_type = (
        V0::nb_sub_type==1 && V1::nb_sub_type==1 ?
        2-AreSameType<typename V0::template SubType<0>::T,typename V1::template SubType<0>::T>::res : V0::nb_sub_type==1+V1::nb_sub_type
    );
    static const unsigned static_size = V0::static_size + V1::static_size;
    static const bool fixed_size = V0::fixed_size && V1::fixed_size;
    typedef typename V0::template SubType<0>::T T0;
    
    Vec(const V0 &vv0,const V1 &vv1) { v0.val=&vv0; v1.val=&vv1; }
    Vec(const V0 &vv0,      V1 &vv1) { v0.val=&vv0; v1.val=&vv1; }
    Vec(      V0 &vv0,const V1 &vv1) { v0.val=&vv0; v1.val=&vv1; }
    Vec(      V0 &vv0,      V1 &vv1) { v0.val=&vv0; v1.val=&vv1; }

    unsigned size() const { return v0.val->size() + v1.val->size(); }

    T0 operator[](unsigned i) const { if (i<v0.val->size()) return (*v0.val)[i]; return (*v1.val)[i-v0.val->size()]; }
    T0 &operator[](unsigned i) { if (i<v0.val->size()) return (*v0.val)[i]; return (*v1.val)[i-v0.val->size()]; }
    
    PtrConstIf<V0,v0_const> v0;
    PtrConstIf<V1,v1_const> v1;
};

template<class V0,class V1> Vec<VecAppend<V0,true ,V1,true > > appended( const V0 &v0, const V1 &v1 ) { return Vec<VecAppend<V0,true ,V1,true > >(v0,v1); }
template<class V0,class V1> Vec<VecAppend<V0,true ,V1,false> > appended( const V0 &v0,       V1 &v1 ) { return Vec<VecAppend<V0,true ,V1,false> >(v0,v1); }
template<class V0,class V1> Vec<VecAppend<V0,false,V1,true > > appended(       V0 &v0, const V1 &v1 ) { return Vec<VecAppend<V0,false,V1,true > >(v0,v1); }
template<class V0,class V1> Vec<VecAppend<V0,false,V1,false> > appended(       V0 &v0,       V1 &v1 ) { return Vec<VecAppend<V0,false,V1,false> >(v0,v1); }

"""

TT = ['class V0','bool const_v0','class V1','bool const_v1']
TV = 'Vec<VecAppend<V0,const_v0,V1,const_v1>,s,int>'

print_apply_ext('apply',TT,TV,'apply(*v.v0.val,op,PARALIST); apply(*v.v1.val,op,PARALIST);')
print_apply_ext('apply_wi',TT,TV,'OpWithIncrement<Op,ONEIFCONSTOP> opi(op); apply(*v.v0.val,opi,PARALIST); apply(*v.v1.val,opi,PARALIST);')
print_apply_ext('find',TT,TV,'return find(*v.v0.val,op,PARALIST) || find(*v.v1.val,op,PARALIST);',ret='bool')
print_apply_ext('apply_range',TT,TV,'apply_range(*v.v0.val,op,from,to); from-=min(from,v.v0.val->size()); to-=min(to,v.v0.val->size()); apply_range(*v.v1.val,op,from,to);',suppar=['unsigned from','unsigned to'])

print '} // namespace LMT'
