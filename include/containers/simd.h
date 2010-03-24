// generated file from simd.h.py. Do not modify
#ifndef LMT_simd_HEADER
#define LMT_simd_HEADER

#include "allocator.h"

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __INTEL_COMPILER
        typedef __m128 __v4sf;
    #endif
#endif
#ifdef __SSE2__
    #include <emmintrin.h>
    #ifdef __INTEL_COMPILER
        typedef __m128d __v2df;
    #endif
#endif

#include "typepromote.h"
#include <limits>

namespace LMT {

/**
    To be redefined for operators
*/
template<class OP> struct OpSupportSIMD {
    static const unsigned res = false;
};

/**  */
template<class T> struct SimdSize { static const unsigned res = 1; };
/**  */
template<class T,unsigned s = SimdSize<T>::res>
struct SimdVec {
    SimdVec() {}
    template<class T2> SimdVec(const T2 &v) { for(unsigned i=0;i<s;++i) val[i] = v; }
    template<class T2> SimdVec(const T2 &v0,const T2 &v1) { val[0] = v0; val[1] = v1; }
    template<class T2> SimdVec(const T2 &v0,const T2 &v1,const T2 &v2,const T2 &v3) { val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3; }
    template<class T2> SimdVec(const SimdVec<T2,s> &v) { for(unsigned i=0;i<s;++i) val[i] = (T)v[i]; }
    static const unsigned nb_elem = s;
    const T &operator[](unsigned i) const { return val[i]; }
    T &operator[](unsigned i) { return val[i]; }
    
    T val[s];
};

template<class T> T sum_if_simd( const T &v ) { return v; }
template<class T,unsigned s> T sum_if_simd( const SimdVec<T,s> &v ) { T r = v[0]; for(unsigned i=1;i<s;++i) r += v[i]; return r; }

template<class TT,unsigned s> struct TypeInformation<SimdVec<TT,s> > {
    static const int res = TypeInformation<TT>::res;
    static const int englobing = 1 + TypeInformation<TT>::englobing;
    typedef TT SubType;
    template<class TV> struct Variant { typedef SimdVec<TV,s> T; };
    template<class TV> struct DeepVariant { typedef SimdVec<typename TypeInformation<TT>::template DeepVariant<TV>::T,s> T; };
    static std::string type() { return "SimdVec<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};

template<class Op,class T1,class T2,unsigned s> struct TypePromote<Op,SimdVec<T1,s>,SimdVec<T2,s> > {
    typedef SimdVec<typename TypePromote<Op,T1,T2 >::T,s> T;
};




#ifdef __SSE__
    template<> struct SimdSize<float> { static const unsigned res = 4; };
    
    template<>
    struct SimdVec<float,4> {
        SimdVec() {}
        SimdVec(const float &v) { val = _mm_set1_ps(v); }
        SimdVec(const __v4sf &v) { val = v; }
        SimdVec(const SimdVec &v) { val = v.val; }
        template<class T2> SimdVec(const SimdVec<T2,4> &v) { val = _mm_set_ps(v[0],v[1],v[2],v[3]); }
        SimdVec(const float &v0,const float &v1,const float &v2,const float &v3) { val = _mm_set_ps(v0,v1,v2,v3); }
        static __v4sf zero() { return _mm_setzero_ps(); }
        static const unsigned nb_elem = 4;
        const float &operator[](unsigned i) const { return ((const float *)&val)[i]; }
        float &operator[](unsigned i) { return ((float *)&val)[i]; }
        
        __v4sf val;
    };
    template<> struct PreferredAllocator<SimdVec<float,4> > { typedef Allocator<SimdVec<float,4>,2,AllocateWithMalloc> T; static const unsigned align=2; };

#endif // __SSE__
    

#ifdef __SSE2__
    template<> struct SimdSize<double> { static const unsigned res = 2; };
    
    template<>
    struct SimdVec<double,2> {
        SimdVec() {}
        SimdVec(const double &v) { val = _mm_set1_pd(v); }
        SimdVec(const __v2df &v) { val = v; }
        SimdVec(const SimdVec &v) { val = v.val; }
        template<class T2> SimdVec(const SimdVec<T2,2> &v) { val = _mm_set_pd(v[0],v[1]); }
        SimdVec(const double &v0,const double &v1) { val = _mm_set_pd(v0,v1); }
        static __v2df zero() { return _mm_setzero_pd(); }
        static const unsigned nb_elem = 2;
        const double &operator[](unsigned i) const { return ((const double *)&val)[i]; }
        double &operator[](unsigned i) { return ((double *)&val)[i]; }
        
        __v2df val;
    };
    template<> struct PreferredAllocator<SimdVec<double,2> > { typedef Allocator<SimdVec<double,2>,2,AllocateWithMalloc> T; static const unsigned align=2; };

#endif // __SSE2__
    
class Conj;
class Abs;
class Acos;
class Asin;
class Atan;
class Cos;
class Cosh;
class Exp;
class Log;
class Log10;
class Sin;
class Sinh;
class Sqrt;
class Tan;
class Tanh;
class Real;
class Imag;
class Arg;
class Negate;
template<class P1,unsigned s> SimdVec<P1,s> conj(const SimdVec<P1,s> &a) { SimdVec<P1,s> res; using LMT::conj; for(unsigned i=0;i<s;++i) res[i] = conj(a[i]); return res; }
template<> struct OpSupportSIMD<Conj> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename SubComplex<P1>::T,s> abs(const SimdVec<P1,s> &a) { SimdVec<typename SubComplex<P1>::T,s> res; using LMT::abs; for(unsigned i=0;i<s;++i) res[i] = abs(a[i]); return res; }
template<> struct OpSupportSIMD<Abs> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> acos(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = acos(a[i]); return res; }
template<> struct OpSupportSIMD<Acos> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> asin(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = asin(a[i]); return res; }
template<> struct OpSupportSIMD<Asin> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> atan(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = atan(a[i]); return res; }
template<> struct OpSupportSIMD<Atan> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> cos(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = cos(a[i]); return res; }
template<> struct OpSupportSIMD<Cos> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> cosh(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = cosh(a[i]); return res; }
template<> struct OpSupportSIMD<Cosh> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> exp(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = exp(a[i]); return res; }
template<> struct OpSupportSIMD<Exp> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> log(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = log(a[i]); return res; }
template<> struct OpSupportSIMD<Log> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> log10(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = log10(a[i]); return res; }
template<> struct OpSupportSIMD<Log10> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> sin(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = sin(a[i]); return res; }
template<> struct OpSupportSIMD<Sin> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> sinh(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = sinh(a[i]); return res; }
template<> struct OpSupportSIMD<Sinh> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> sqrt(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = sqrt(a[i]); return res; }
template<> struct OpSupportSIMD<Sqrt> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> tan(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = tan(a[i]); return res; }
template<> struct OpSupportSIMD<Tan> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename FloatType<P1>::T,s> tanh(const SimdVec<P1,s> &a) { SimdVec<typename FloatType<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = tanh(a[i]); return res; }
template<> struct OpSupportSIMD<Tanh> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename SubComplex<P1>::T,s> real(const SimdVec<P1,s> &a) { SimdVec<typename SubComplex<P1>::T,s> res; using LMT::real; for(unsigned i=0;i<s;++i) res[i] = real(a[i]); return res; }
template<> struct OpSupportSIMD<Real> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename SubComplex<P1>::T,s> imag(const SimdVec<P1,s> &a) { SimdVec<typename SubComplex<P1>::T,s> res; using LMT::imag; for(unsigned i=0;i<s;++i) res[i] = imag(a[i]); return res; }
template<> struct OpSupportSIMD<Imag> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<typename SubComplex<P1>::T,s> arg(const SimdVec<P1,s> &a) { SimdVec<typename SubComplex<P1>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = arg(a[i]); return res; }
template<> struct OpSupportSIMD<Arg> { static const unsigned res = true; };
template<class P1,unsigned s> SimdVec<P1,s> operator-(const SimdVec<P1,s> &a) { SimdVec<P1,s> res; for(unsigned i=0;i<s;++i) res[i] = -(a[i]); return res; }
template<> struct OpSupportSIMD<Negate> { static const unsigned res = true; };
#ifdef __SSE__
    inline SimdVec<float,4> sqrt(const SimdVec<float,4> &a) { return _mm_sqrt_ps(a.val); }
#endif // __SSE__

#ifdef __SSE2__
    inline SimdVec<double,2> sqrt(const SimdVec<double,2> &a) { return _mm_sqrt_pd(a.val); }
#endif // __SSE2__


class Plus;
class Minus;
class Modulus;
class Multiplies;
class Divides;
class Equal;
class NotEqual;
class Less;
class Greater;
class LessEq;
class GreaterEq;
class And;
class Or;
class Xor;
class AndAnd;
class OrOr;
class Min;
class Max;
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Plus,P1,P2>::T,s> operator+(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Plus,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] + b[i]; return res; }
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Plus,P1,P2>::T,s> operator+=(SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] + b[i]; return a; }
template<> struct OpSupportSIMD<Plus> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Minus,P1,P2>::T,s> operator-(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Minus,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] - b[i]; return res; }
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Minus,P1,P2>::T,s> operator-=(SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] - b[i]; return a; }
template<> struct OpSupportSIMD<Minus> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Modulus,P1,P2>::T,s> operator%(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Modulus,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] % b[i]; return res; }
template<> struct OpSupportSIMD<Modulus> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Multiplies,P1,P2>::T,s> operator*(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Multiplies,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] * b[i]; return res; }
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Multiplies,P1,P2>::T,s> operator*=(SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] * b[i]; return a; }
template<> struct OpSupportSIMD<Multiplies> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Divides,P1,P2>::T,s> operator/(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Divides,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] / b[i]; return res; }
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Divides,P1,P2>::T,s> operator/=(SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] / b[i]; return a; }
template<> struct OpSupportSIMD<Divides> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Equal,P1,P2>::T,s> operator==(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Equal,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] == b[i]; return res; }
template<> struct OpSupportSIMD<Equal> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<NotEqual,P1,P2>::T,s> operator!=(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<NotEqual,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] != b[i]; return res; }
template<> struct OpSupportSIMD<NotEqual> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Less,P1,P2>::T,s> operator<(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Less,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] < b[i]; return res; }
template<> struct OpSupportSIMD<Less> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Greater,P1,P2>::T,s> operator>(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Greater,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] > b[i]; return res; }
template<> struct OpSupportSIMD<Greater> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<LessEq,P1,P2>::T,s> operator<=(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<LessEq,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] <= b[i]; return res; }
template<> struct OpSupportSIMD<LessEq> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<GreaterEq,P1,P2>::T,s> operator>=(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<GreaterEq,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] >= b[i]; return res; }
template<> struct OpSupportSIMD<GreaterEq> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<And,P1,P2>::T,s> operator&(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<And,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] & b[i]; return res; }
template<> struct OpSupportSIMD<And> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Or,P1,P2>::T,s> operator|(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Or,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] | b[i]; return res; }
template<> struct OpSupportSIMD<Or> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Xor,P1,P2>::T,s> operator^(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Xor,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] ^ b[i]; return res; }
template<> struct OpSupportSIMD<Xor> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<AndAnd,P1,P2>::T,s> operator&&(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<AndAnd,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] && b[i]; return res; }
template<> struct OpSupportSIMD<AndAnd> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<OrOr,P1,P2>::T,s> operator||(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<OrOr,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] || b[i]; return res; }
template<> struct OpSupportSIMD<OrOr> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Min,P1,P2>::T,s> min(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Min,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = min(a[i],b[i]); return res; }
template<> struct OpSupportSIMD<Min> { static const unsigned res = true; };
template<class P1,class P2,unsigned s> SimdVec<typename TypePromote<Max,P1,P2>::T,s> max(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { SimdVec<typename TypePromote<Max,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = max(a[i],b[i]); return res; }
template<> struct OpSupportSIMD<Max> { static const unsigned res = true; };
#ifdef __SSE__
    inline SimdVec<float,4> operator+(const SimdVec<float,4> &a,const SimdVec<float,4> &b) { return _mm_add_ps(a.val,b.val); }
    inline SimdVec<float,4> operator+=(SimdVec<float,4> &a,const SimdVec<float,4> &b) { a.val = _mm_add_ps(a.val,b.val); return a; }
    inline SimdVec<float,4> operator-(const SimdVec<float,4> &a,const SimdVec<float,4> &b) { return _mm_sub_ps(a.val,b.val); }
    inline SimdVec<float,4> operator-=(SimdVec<float,4> &a,const SimdVec<float,4> &b) { a.val = _mm_sub_ps(a.val,b.val); return a; }
    inline SimdVec<float,4> operator*(const SimdVec<float,4> &a,const SimdVec<float,4> &b) { return _mm_mul_ps(a.val,b.val); }
    inline SimdVec<float,4> operator*=(SimdVec<float,4> &a,const SimdVec<float,4> &b) { a.val = _mm_mul_ps(a.val,b.val); return a; }
    inline SimdVec<float,4> operator/(const SimdVec<float,4> &a,const SimdVec<float,4> &b) { return _mm_div_ps(a.val,b.val); }
    inline SimdVec<float,4> operator/=(SimdVec<float,4> &a,const SimdVec<float,4> &b) { a.val = _mm_div_ps(a.val,b.val); return a; }
    inline SimdVec<float,4> operator&(const SimdVec<float,4> &a,const SimdVec<float,4> &b) { return _mm_and_ps(a.val,b.val); }
    inline SimdVec<float,4> operator&=(SimdVec<float,4> &a,const SimdVec<float,4> &b) { a.val = _mm_and_ps(a.val,b.val); return a; }
    inline SimdVec<float,4> operator|(const SimdVec<float,4> &a,const SimdVec<float,4> &b) { return _mm_or_ps(a.val,b.val); }
    inline SimdVec<float,4> operator|=(SimdVec<float,4> &a,const SimdVec<float,4> &b) { a.val = _mm_or_ps(a.val,b.val); return a; }
    inline SimdVec<float,4> operator^(const SimdVec<float,4> &a,const SimdVec<float,4> &b) { return _mm_xor_ps(a.val,b.val); }
    inline SimdVec<float,4> operator^=(SimdVec<float,4> &a,const SimdVec<float,4> &b) { a.val = _mm_xor_ps(a.val,b.val); return a; }
    inline SimdVec<float,4> min(const SimdVec<float,4> &a,const SimdVec<float,4> &b) { return _mm_min_ps(a.val,b.val); }
    inline SimdVec<float,4> max(const SimdVec<float,4> &a,const SimdVec<float,4> &b) { return _mm_max_ps(a.val,b.val); }
#endif // __SSE__

#ifdef __SSE2__
    inline SimdVec<double,2> operator+(const SimdVec<double,2> &a,const SimdVec<double,2> &b) { return _mm_add_pd(a.val,b.val); }
    inline SimdVec<double,2> operator+=(SimdVec<double,2> &a,const SimdVec<double,2> &b) { a.val = _mm_add_pd(a.val,b.val); return a; }
    inline SimdVec<double,2> operator-(const SimdVec<double,2> &a,const SimdVec<double,2> &b) { return _mm_sub_pd(a.val,b.val); }
    inline SimdVec<double,2> operator-=(SimdVec<double,2> &a,const SimdVec<double,2> &b) { a.val = _mm_sub_pd(a.val,b.val); return a; }
    inline SimdVec<double,2> operator*(const SimdVec<double,2> &a,const SimdVec<double,2> &b) { return _mm_mul_pd(a.val,b.val); }
    inline SimdVec<double,2> operator*=(SimdVec<double,2> &a,const SimdVec<double,2> &b) { a.val = _mm_mul_pd(a.val,b.val); return a; }
    inline SimdVec<double,2> operator/(const SimdVec<double,2> &a,const SimdVec<double,2> &b) { return _mm_div_pd(a.val,b.val); }
    inline SimdVec<double,2> operator/=(SimdVec<double,2> &a,const SimdVec<double,2> &b) { a.val = _mm_div_pd(a.val,b.val); return a; }
    inline SimdVec<double,2> operator&(const SimdVec<double,2> &a,const SimdVec<double,2> &b) { return _mm_and_pd(a.val,b.val); }
    inline SimdVec<double,2> operator&=(SimdVec<double,2> &a,const SimdVec<double,2> &b) { a.val = _mm_and_pd(a.val,b.val); return a; }
    inline SimdVec<double,2> operator|(const SimdVec<double,2> &a,const SimdVec<double,2> &b) { return _mm_or_pd(a.val,b.val); }
    inline SimdVec<double,2> operator|=(SimdVec<double,2> &a,const SimdVec<double,2> &b) { a.val = _mm_or_pd(a.val,b.val); return a; }
    inline SimdVec<double,2> operator^(const SimdVec<double,2> &a,const SimdVec<double,2> &b) { return _mm_xor_pd(a.val,b.val); }
    inline SimdVec<double,2> operator^=(SimdVec<double,2> &a,const SimdVec<double,2> &b) { a.val = _mm_xor_pd(a.val,b.val); return a; }
    inline SimdVec<double,2> min(const SimdVec<double,2> &a,const SimdVec<double,2> &b) { return _mm_min_pd(a.val,b.val); }
    inline SimdVec<double,2> max(const SimdVec<double,2> &a,const SimdVec<double,2> &b) { return _mm_max_pd(a.val,b.val); }
#endif // __SSE2__


template<class T,unsigned s> std::ostream &operator<<(std::ostream &os,const SimdVec<T,s> &v) {
    for(unsigned i=0;i<s;++i) os << v[i] << (i<s-1?" ":"");
    return os;
}

}

namespace std {
    template<class T,unsigned n> struct numeric_limits<LMT::SimdVec<T,n> > {
        static LMT::SimdVec<T,n> max() { return numeric_limits<T>::max(); }
    };
}
#ifndef WITHOUTCOMPLEX
namespace LMT {
    template<class TT,unsigned n> struct SubComplex<LMT::SimdVec<std::complex<TT>,n> > {
        typedef LMT::SimdVec<TT,n> T;
    };
}
#endif

#endif // LMT_simd_HEADER
