
namespace LMT {
template<class T=int> struct VecHeavyside {};

template<class TT> struct IsVecOp<VecHeavyside<TT> > { typedef int T; };

/// range
template<class TT,int static_size_>
class Vec<VecHeavyside<TT>,static_size_,int> {
public:
    template<unsigned n> struct SubType { typedef TT T; };
    static const unsigned nb_sub_type = 1;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 1;

    struct inc_index_access_const {
        inline const TT &operator[](unsigned i) const { return (i>=nn) * *val; }
        const TT *val;
        unsigned nn;
    };
    inc_index_access_const begin_inc_index_access_const() const { inc_index_access_const res; res.val=&val; res.nn=nn; return res; }
    
    Vec(const TT &cst_val,unsigned nnn,unsigned s=static_size_):val(cst_val),nn(nnn) { si.set(s); }
    
    TT operator[](unsigned i) const { return (i>=nn)*val; } /// access to element i
    TT get(unsigned i) const { return (i>=nn)*val; } ///
    unsigned size() const { return si.val; }
    void clear() { si.set(0); }

    template<class T2> Vec &operator*=(const T2 &v) { val *= v; return *this; }
    template<class T2> Vec &operator/=(const T2 &v) { val /= v; return *this; }
    template<class T2> Vec &operator%=(const T2 &v) { val %= v; return *this; }
    template<class T2> Vec &operator&=(const T2 &v) { val &= v; return *this; }


    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,true >,s2> operator[](const Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,true>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2> operator[](const Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2> operator[](Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2> operator[](Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2>(*this,v2); }
    

    TT val;
    unsigned nn;
private:
    StaticValIf<unsigned,fixed_size,static_size_> si;
};

/** Create a constant vec of size $size \relates Vec */
template<class T> Vec<VecHeavyside<T>,-1> heavyside_vec(const T &val,unsigned nn,unsigned size) { return Vec<VecHeavyside<T>,-1>(val,nn,size); }
/** Create a constant vec of size $s \relates Vec */
template<int s,class T> Vec<VecHeavyside<T>,s> static_heavyside_vec(const T &val,unsigned nn) { return Vec<VecHeavyside<T>,s>(val,nn); }


  template<class TT,int s,class Op> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op) { for(unsigned i=0;i<v.nn;op((TT)0),++i); for(unsigned i=v.nn;i<v.size();op(v.val),++i); }
  template<class TT,int s,class Op> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op) { for(unsigned i=0;i<v.nn;op((TT)0),++i); for(unsigned i=v.nn;i<v.size();op(v.val),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0) { for(unsigned i=0;i<v.nn;op((TT)0,p0),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0) { for(unsigned i=0;i<v.nn;op((TT)0,p0),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0) { for(unsigned i=0;i<v.nn;op((TT)0,p0),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0) { for(unsigned i=0;i<v.nn;op((TT)0,p0),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op((TT)0,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }

  template<class TT,int s,class Op> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op) { for(unsigned i=v.nn;i<v.size();op(v.val),++i); }
  template<class TT,int s,class Op> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op) { for(unsigned i=v.nn;i<v.size();op(v.val),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0) { for(unsigned i=v.nn;i<v.size();op(v.val,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0) { for(unsigned i=v.nn;i<v.size();op(v.val,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0) { for(unsigned i=v.nn;i<v.size();op(v.val,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0) { for(unsigned i=v.nn;i<v.size();op(v.val,p0),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,p0,p1,p2),++i); }

  template<class TT,int s,class Op> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op) { op(v.val); }
  template<class TT,int s,class Op> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op) { op(v.val); }
  template<class TT,int s,class Op> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op) { op(v.val); }
  template<class TT,int s,class Op> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op) { op(v.val); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0) { op(v.val,p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0) { op(v.val,p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0) { op(v.val,p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0) { op(v.val,p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0) { op(v.val,p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0) { op(v.val,p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0) { op(v.val,p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0) { op(v.val,p0); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_unique(Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { op(v.val,p0,p1,p2); }

  template<class TT,int s,class Op> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0),++i); for(unsigned i=v.nn;i<to;op((TT)0), ++i); }
  template<class TT,int s,class Op> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0),++i); for(unsigned i=v.nn;i<to;op((TT)0), ++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0), ++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0), ++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0), ++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,p0,p1,p2), ++i); }

  template<class TT,int s,class Op> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op) { for(unsigned i=0;i<v.nn;op(0,i),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i),++i); }
  template<class TT,int s,class Op> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op) { for(unsigned i=0;i<v.nn;op(0,i),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0) { for(unsigned i=0;i<v.nn;op(0,i,p0),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0) { for(unsigned i=0;i<v.nn;op(0,i,p0),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0) { for(unsigned i=0;i<v.nn;op(0,i,p0),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0) { for(unsigned i=0;i<v.nn;op(0,i,p0),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,p0,p1,p2),++i); }

  template<class TT,int s,class Op> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op) { for(unsigned i=v.nn;i<v.size();op(v.val,i),++i); }
  template<class TT,int s,class Op> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op) { for(unsigned i=v.nn;i<v.size();op(v.val,i),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0),++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=v.nn;i<v.size();op(v.val,i,p0,p1,p2),++i); }

  template<class TT,int s,class Op> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i),++i); for(unsigned i=v.nn;i<to;op((TT)0,i), ++i); }
  template<class TT,int s,class Op> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i),++i); for(unsigned i=v.nn;i<to;op((TT)0,i), ++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0), ++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0), ++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0), ++i); }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<VecHeavyside<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,p0,p1,p2),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,p0,p1,p2), ++i); }

  template<class TT,int s,class Op> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op) { return (v.nn>=1 && op((TT)0)) || op(v.val); }
  template<class TT,int s,class Op> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op) { return (v.nn>=1 && op((TT)0)) || op(v.val); }
  template<class TT,int s,class Op,class TP0> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0) { return (v.nn>=1 && op((TT)0,p0)) || op(v.val,p0); }
  template<class TT,int s,class Op,class TP0> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0) { return (v.nn>=1 && op((TT)0,p0)) || op(v.val,p0); }
  template<class TT,int s,class Op,class TP0> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0) { return (v.nn>=1 && op((TT)0,p0)) || op(v.val,p0); }
  template<class TT,int s,class Op,class TP0> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0) { return (v.nn>=1 && op((TT)0,p0)) || op(v.val,p0); }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { return (v.nn>=1 && op((TT)0,p0,p1)) || op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { return (v.nn>=1 && op((TT)0,p0,p1)) || op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { return (v.nn>=1 && op((TT)0,p0,p1)) || op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { return (v.nn>=1 && op((TT)0,p0,p1)) || op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { return (v.nn>=1 && op((TT)0,p0,p1)) || op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { return (v.nn>=1 && op((TT)0,p0,p1)) || op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { return (v.nn>=1 && op((TT)0,p0,p1)) || op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { return (v.nn>=1 && op((TT)0,p0,p1)) || op(v.val,p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<VecHeavyside<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { return (v.nn>=1 && op((TT)0,p0,p1,p2)) || op(v.val,p0,p1,p2); }

} // namespace LMT
