
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

/** return elements of V0 which are also in v1
    elate Vec
*/
template<class V0,class V1> Vec<Intersection<V0,V1,true > > intersection(const V0 &v0,const V1 &v1) { return Vec<Intersection<V0,V1,true> >(v0,v1); }

/** return elements of V0 which are also in v1
    elate Vec
*/
template<class V0,class V1> Vec<Intersection<V0,V1,false> > intersection(V0 &v0,const V1 &v1) { return Vec<Intersection<V0,V1,false> >(v0,v1); }


  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,1> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { typename Vec<Intersection<V0,V1,const_v0>,s,int>::template Inter<Op,0> i; i.op.val=&op; i.v1=&v.v1; apply(*v.v0.val,i,p0,p1,p2); }

  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op) { OpWithIncrement<Op,1> opi(op); apply(v,opi); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op) { OpWithIncrement<Op,1> opi(op); apply(v,opi); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op) { OpWithIncrement<Op,0> opi(op); apply(v,opi); }
  template<class V0,class V1,bool const_v0,int s,class Op> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op) { OpWithIncrement<Op,0> opi(op); apply(v,opi); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class V0,class V1,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<Intersection<V0,V1,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }

} // namespace LMT
