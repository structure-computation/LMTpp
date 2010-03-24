
namespace LMT {
/// full vector, version with no memory management
template<class T,bool const_val=false,class OpIndex=Function<C_1> > struct Ref {};

template<class TT,bool const_val,class OpIndex> struct IsVecOp<Ref<TT,const_val,OpIndex> > { typedef int T; };
template<class TT,bool const_val,int s> struct VecSupportSIMD<Vec<Ref<TT,const_val,Function<C_1> >,s,int> > { static const unsigned res = true; };

/// full vector, version with no memory management
template<class TT,bool const_val,class OpIndex,int static_size_>
class Vec<Ref<TT,const_val,OpIndex>,static_size_,int> {
public:
    template<unsigned n> struct SubType { typedef TT T; };
    static const unsigned nb_sub_type = 1;
    
    typedef TT T0;
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 0;

    typedef TT* inc_index_access; /// non zero incrementing iterator
    typedef const TT* inc_index_access_const; /// non zero incrementing const iterator
    TT *begin_inc_index_access() { return val.val; } /// iter[i] gives the i-th element
    const TT *begin_inc_index_access_const() const { return val.val; } /// iter[i] gives the i-th element

    Vec() { si.set( fixed_size * static_size ); }
    Vec(const TT *begin,unsigned size=static_size_) { si.set(size); val.val = begin; }
    Vec(TT *begin,unsigned size=static_size_) { si.set(size); val.val = begin; }

    Vec( const Vec<Ref<TT,false,OpIndex>,static_size_,int> &v ):si(v.si) { val.val=v.val.val; opindex=v.opindex; }
    template<class T2,bool c2> Vec( const Vec<Ref<T2,c2,OpIndex>,static_size_,int> &v ):si(v.si) { val.val=(const TT*)v.val.val; opindex=v.opindex; }
    
    template<class T2,int s1> Vec &operator=(const Vec<T2,s1> &vec) { VECASSERTSAMESIZETHAN(vec,s1); for(unsigned i=0;i<size();++i) val[opindex(i)] = (TT)vec[i]; return *this; }
    
    template<unsigned nne> SimdVec<TT,nne> &simd(unsigned i,const Number<nne> &ne) { return reinterpret_cast<SimdVec<TT,nne> &>(val.val[i]); }
    template<unsigned nne> const SimdVec<TT,nne> &simd(unsigned i,const Number<nne> &ne) const { return reinterpret_cast<const SimdVec<TT,nne> &>(val.val[i]); }

    TT &operator[](unsigned i) { DEBUGASSERT(i<size()); return val[opindex(i)]; } /// access to element i
    const TT &operator[](unsigned i) const { DEBUGASSERT(i<size()); return val[opindex(i)]; } /// access to element i
    const TT &get(unsigned i) const { DEBUGASSERT(i<size()); return val[opindex(i)]; } /// calling get ensure that the const version is called (useful for SparseVec)
    void set(unsigned i,const TT v) { DEBUGASSERT(i<size()); val[opindex(i)] = v; } /// set element i
    unsigned size() const { return si.val; }
                                                          
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
    

    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,true >,s2> operator[](const Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,true>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2> operator[](const Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2> operator[](Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2> operator[](Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2>(*this,v2); }
    

    TT &first() { return val[opindex(0)]; } /// first element
    const TT &first() const { return val[opindex(0)]; } /// first element
    TT &back() { return val[opindex(size()-1)]; } /// last element
    const TT &back() const { return val[opindex(size()-1)]; } /// last element
    const TT *ptr() const { return val.val; }
    TT *ptr() { return val.val; }

    void pop_back() { --si.val; }

    void resize(unsigned i) { si.set(i); }

    PtrConstIf<TT,const_val> val;
    StaticValIf<unsigned,(static_size_>=0),static_size_> si;
    OpIndex opindex;
};

} // namespace LMT

