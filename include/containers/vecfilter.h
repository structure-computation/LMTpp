
#ifndef VEC_SELECT_H
#define VEC_SELECT_H

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
    
                                                          
    template<class T2> Vec &operator+=(const T2 &val) { apply( *this, AssignSelfOp(), Plus() , val ); return *this; }
    template<class T2> Vec &operator-=(const T2 &val) { apply( *this, AssignSelfOp(), Minus(), val ); return *this; }
    template<class T2> Vec &operator^=(const T2 &val) { apply( *this, AssignSelfOp(), Xor()  , val ); return *this; }
    template<class T2> Vec &operator|=(const T2 &val) { apply( *this, AssignSelfOp(), Or()   , val ); return *this; }

    template<class T2,int s2,class INNER> Vec &operator+=(const Vec<T2,s2,INNER> &val) { apply_wi( *this, AssignSelfOp(), Plus() , val ); return *this; }
    template<class T2,int s2,class INNER> Vec &operator-=(const Vec<T2,s2,INNER> &val) { apply_wi( *this, AssignSelfOp(), Minus(), val ); return *this; }
    template<class T2,int s2,class INNER> Vec &operator^=(const Vec<T2,s2,INNER> &val) { apply_wi( *this, AssignSelfOp(), Xor()  , val ); return *this; }
    template<class T2,int s2,class INNER> Vec &operator|=(const Vec<T2,s2,INNER> &val) { apply_wi( *this, AssignSelfOp(), Or()   , val ); return *this; }
    
    template<class T2> Vec &operator*=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Multiplies(),va); return *this; }
    template<class T2> Vec &operator/=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Divides   (),va); return *this; }
    template<class T2> Vec &operator%=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Modulus   (),va); return *this; }
    template<class T2> Vec &operator&=(const T2 &va) { apply_nz(*this,AssignSelfOp(),And       (),va); return *this; }
    
    template<class T2,int s2,class INNER> Vec &operator*=(const Vec<T2,s2,INNER> &va) { apply_nz_wi(*this,AssignSelfOp(),Multiplies(),va); return *this; }
    template<class T2,int s2,class INNER> Vec &operator/=(const Vec<T2,s2,INNER> &va) { apply_nz_wi(*this,AssignSelfOp(),Divides   (),va); return *this; }
    template<class T2,int s2,class INNER> Vec &operator%=(const Vec<T2,s2,INNER> &va) { apply_nz_wi(*this,AssignSelfOp(),Modulus   (),va); return *this; }
    template<class T2,int s2,class INNER> Vec &operator&=(const Vec<T2,s2,INNER> &va) { apply_nz_wi(*this,AssignSelfOp(),And       (),va); return *this; }
    
    
    PtrConstIf<V0,const_v0> v0;
    const V1 &v1;
};

/**
    Return a vector containing v0[i] if v1[1]!=False
    \relates Vec
*/
template<class V0,class V1> Vec<VecSelect<V0,V1,true > > select(const V0 &v0,const V1 &v1) { return Vec<VecSelect<V0,V1,true > >(v0,v1); }
/**
    Return a vector containing v0[i] if v1[1]!=False
    \relates Vec
*/
template<class V0,class V1> Vec<VecSelect<V0,V1,false> > select(V0 &v0,const V1 &v1) { return Vec<VecSelect<V0,V1,false> >(v0,v1); }


  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,1> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<VecSelect<V0,V1,const_v0>,s,int>::template FilterI<Op,0> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,p0,p1,p2); }

  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op) { OpWithIncrement<Op,1> opi(op); apply(v,opi); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op) { OpWithIncrement<Op,1> opi(op); apply(v,opi); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op) { OpWithIncrement<Op,0> opi(op); apply(v,opi); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op) { OpWithIncrement<Op,0> opi(op); apply(v,opi); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecSelect<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }

} // namespace LMT
#endif // VEC_SELECT_H
