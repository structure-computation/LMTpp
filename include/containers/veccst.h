
namespace LMT {
template<class T=int> struct VecCst {};

template<class T,int s> struct VecSupportSIMD<Vec<VecCst<T>,s,int> > { static const unsigned res = ( SimdVec<T>::nb_elem > 1 ); };

template<class TT> struct IsVecOp<VecCst<TT> > { typedef int T; };


/// range
template<class TT,int static_size_>
class Vec<VecCst<TT>,static_size_,int> {
public:
    template<unsigned n> struct SubType { typedef TT T; };
    static const unsigned nb_sub_type = 1;

    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 0;
    
    typedef SimdVec<TT> ST;

    Vec(const TT &cst_val,unsigned s=static_size_):val(cst_val) { si.set(s); }
    
    const TT &operator[](unsigned i) const { return val; } /// access to element i
    TT &operator[](unsigned i) { return val; } /// access to element i
    TT get(unsigned i) const { return val; } ///
    template<unsigned ne> SimdVec<TT,ne> simd(unsigned i,const Number<ne> &nne) const { return SimdVec<TT,ne>(val); } /// access to element i
    unsigned size() const { return si.val; }
    void clear() { si.set(0); }

    template<class T2> Vec &operator+=(const T2 &v) { val += v; return *this; }
    template<class T2> Vec &operator-=(const T2 &v) { val -= v; return *this; }
    template<class T2> Vec &operator^=(const T2 &v) { val ^= v; return *this; }
    template<class T2> Vec &operator|=(const T2 &v) { val |= v; return *this; }
    
    template<class T2> Vec &operator*=(const T2 &v) { val *= v; return *this; }
    template<class T2> Vec &operator/=(const T2 &v) { val /= v; return *this; }
    template<class T2> Vec &operator%=(const T2 &v) { val %= v; return *this; }
    template<class T2> Vec &operator&=(const T2 &v) { val &= v; return *this; }
    
    template<class TST,int s2> Vec<VecCst<TT>,s2> operator[](const Vec<TST,s2> &v2) const { return Vec<VecCst<TT>,s2>(val,v2.size()); }

    void resize(unsigned s) { si.set(s); }

    TT val;
private:
    StaticValIf<unsigned,fixed_size,static_size_> si;
};

/*!
 Create a constant vec of size $size 
\relates Vec 
\relates static_cst_vec
*/
template<class T> Vec<VecCst<T>,-1> cst_vec(const T &val,unsigned size) { return Vec<VecCst<T>,-1>(val,size); }
/*! 
Crée un vecteur constant de taille s à la compilaion
\relates Vec 
\relates cst_vec
*/
template<int s,class T> Vec<VecCst<T>,s> static_cst_vec(const T &val) { return Vec<VecCst<T>,s>(val); }

} // namespace LMT

