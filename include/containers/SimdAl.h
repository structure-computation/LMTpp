#ifndef LMT_SIMD_AL_H
#define LMT_SIMD_AL_H

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

// #include "containers/basic_type_info.h"
// #include "containers/n.h"

namespace LMT {
    template<class T,unsigned s> struct SimdVecAl {
        SimdVecAl() {}
        SimdVecAl(const T &v) { for(unsigned i=0;i<s;++i) val[i] = v; }
        SimdVecAl(const T &v0,const T &v1) { val[0] = v0; val[1] = v1; }
        SimdVecAl(const T &v0,const T &v1,const T &v2,const T &v3) { val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3; }
        template<class T2> SimdVecAl(const SimdVecAl<T2,s> &v) { for(unsigned i=0;i<s;++i) val[i] = (T)v[i]; }
        static const unsigned nb_elem = s;
        static SimdVecAl zero() { return SimdVecAl( T(0) ); }
        const T &operator[](unsigned i) const { return val[i]; }
        T &operator[](unsigned i) { return val[i]; }
        T sum() const { T res = val[0]; for(unsigned i=1;i<s;++i) res += val[i]; return res; }
        
        T val[s];
    };
    template<class T> struct SimdSizeAl;
    
    class Plus;
    class Minus;
    class Multiplies;
    class Divides;
    class And;
    class Or;
    class Xor;
    class Min;
    class Max;
    
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Plus      ,P1,P2>::T,s> operator+(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Minus     ,P1,P2>::T,s> operator-(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Multiplies,P1,P2>::T,s> operator*(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Divides   ,P1,P2>::T,s> operator/(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<And       ,P1,P2>::T,s> operator&(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b)  __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Or        ,P1,P2>::T,s> operator|(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Xor       ,P1,P2>::T,s> operator^(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b)  __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Min       ,P1,P2>::T,s> min(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b)  __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Max       ,P1,P2>::T,s> max(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b)  __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Plus      ,P1,P2>::T,s> operator+=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b)  __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Minus     ,P1,P2>::T,s> operator-=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Multiplies,P1,P2>::T,s> operator*=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Divides   ,P1,P2>::T,s> operator/=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<And       ,P1,P2>::T,s> operator&=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Or        ,P1,P2>::T,s> operator|=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b)  __attribute__((always_inline));
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Xor       ,P1,P2>::T,s> operator^=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) __attribute__((always_inline));
    
    template<class T,unsigned s> SimdVecAl<T,s> operator-(const SimdVecAl<T,s> &a) __attribute__((always_inline));
    template<class T,unsigned s> SimdVecAl<T,s> neg      (const SimdVecAl<T,s> &a) __attribute__((always_inline));
    template<class T,unsigned s> SimdVecAl<T,s> conj     (const SimdVecAl<T,s> &a) __attribute__((always_inline));
    
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Plus      ,P1,P2>::T,s> operator+(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { SimdVecAl<typename TypePromote<Plus,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] + b[i]; return res; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Minus     ,P1,P2>::T,s> operator-(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { SimdVecAl<typename TypePromote<Minus,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] - b[i]; return res; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Multiplies,P1,P2>::T,s> operator*(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { SimdVecAl<typename TypePromote<Multiplies,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] * b[i]; return res; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Divides   ,P1,P2>::T,s> operator/(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { SimdVecAl<typename TypePromote<Divides,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] / b[i]; return res; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<And       ,P1,P2>::T,s> operator&(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { SimdVecAl<typename TypePromote<And,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] & b[i]; return res; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Or        ,P1,P2>::T,s> operator|(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { SimdVecAl<typename TypePromote<Or,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] | b[i]; return res; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Xor       ,P1,P2>::T,s> operator^(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { SimdVecAl<typename TypePromote<Xor,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = a[i] ^ b[i]; return res; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Min       ,P1,P2>::T,s> min(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { SimdVecAl<typename TypePromote<Min,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = min(a[i],b[i]); return res; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Max       ,P1,P2>::T,s> max(const SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { SimdVecAl<typename TypePromote<Max,P1,P2>::T,s> res; for(unsigned i=0;i<s;++i) res[i] = max(a[i],b[i]); return res; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Plus      ,P1,P2>::T,s> operator+=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] + b[i]; return a; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Minus     ,P1,P2>::T,s> operator-=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] - b[i]; return a; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Multiplies,P1,P2>::T,s> operator*=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] * b[i]; return a; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Divides   ,P1,P2>::T,s> operator/=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] / b[i]; return a; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<And       ,P1,P2>::T,s> operator&=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] & b[i]; return a; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Or        ,P1,P2>::T,s> operator|=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] | b[i]; return a; }
    template<class P1,class P2,unsigned s> SimdVecAl<typename TypePromote<Xor       ,P1,P2>::T,s> operator^=(SimdVecAl<P1,s> &a,const SimdVecAl<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = a[i] ^ b[i]; return a; }
    
    template<class T,unsigned s> SimdVecAl<T,s> operator-(const SimdVecAl<T,s> &a) { SimdVecAl<T,s> res; for(unsigned i=0;i<s;++i) res[i] =    - a[i] ; return res; }
    template<class T,unsigned s> SimdVecAl<T,s> neg      (const SimdVecAl<T,s> &a) { SimdVecAl<T,s> res; for(unsigned i=0;i<s;++i) res[i] =    - a[i] ; return res; }
    template<class T,unsigned s> SimdVecAl<T,s> conj     (const SimdVecAl<T,s> &a) { SimdVecAl<T,s> res; for(unsigned i=0;i<s;++i) res[i] = conj(a[i]); return res; }
    
    template<class T,unsigned s> SimdVecAl<T,s> floor    (const SimdVecAl<T,s> &a) { SimdVecAl<T,s> res; for(unsigned i=0;i<s;++i) res[i] = floor(a[i]); return res; }
    template<class T,unsigned s> SimdVecAl<T,s> heaviside(const SimdVecAl<T,s> &a) { SimdVecAl<T,s> res; for(unsigned i=0;i<s;++i) res[i] = (a[i]>=0)  ; return res; }
    
    
    #ifdef __SSE__
    template<> struct SimdSizeAl<float> { static const unsigned res = 4; };
    
    template<> struct SimdVecAl<float,4> {
        SimdVecAl() {}
        SimdVecAl(const float &v) { val = _mm_set1_ps(v); }
        SimdVecAl(const __v4sf &v) { val = v; }
        SimdVecAl(const SimdVecAl &v) { val = v.val; }
        template<class T2> SimdVecAl(const SimdVecAl<T2,4> &v) { val = _mm_set_ps(v[0],v[1],v[2],v[3]); }
        SimdVecAl(const float &v0,const float &v1,const float &v2,const float &v3) { val = _mm_set_ps(v3,v2,v1,v0); }
        static __v4sf zero() { return _mm_setzero_ps(); }
        static const unsigned nb_elem = 4;
        const float &operator[](unsigned i) const { return ((const float *)&val)[i]; }
        float &operator[](unsigned i) { return ((float *)&val)[i]; }
        float sum() const { float res = ((const float *)&val)[0]; for(unsigned i=1;i<4;++i) res += ((const float *)&val)[i]; return res; }
        
        __v4sf val;
    };
    inline SimdVecAl<float,4> operator+(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline SimdVecAl<float,4> operator-(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline SimdVecAl<float,4> operator*(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline SimdVecAl<float,4> operator/(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline SimdVecAl<float,4> operator&(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline SimdVecAl<float,4> operator|(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline SimdVecAl<float,4> operator^(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline SimdVecAl<float,4> min(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline SimdVecAl<float,4> max(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline void operator+=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline void operator-=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline void operator*=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline void operator/=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline void operator&=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline void operator|=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    inline void operator^=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) __attribute__((always_inline));
    
    inline SimdVecAl<float,4> operator+(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { return _mm_add_ps(a.val,b.val); }
    inline SimdVecAl<float,4> operator-(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { return _mm_sub_ps(a.val,b.val); }
    inline SimdVecAl<float,4> operator*(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { return _mm_mul_ps(a.val,b.val); }
    inline SimdVecAl<float,4> operator/(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { return _mm_div_ps(a.val,b.val); }
    inline SimdVecAl<float,4> operator&(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { return _mm_and_ps(a.val,b.val); }
    inline SimdVecAl<float,4> operator|(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { return _mm_or_ps(a.val,b.val); }
    inline SimdVecAl<float,4> operator^(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { return _mm_xor_ps(a.val,b.val); }
    inline SimdVecAl<float,4> min(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { return _mm_min_ps(a.val,b.val); }
    inline SimdVecAl<float,4> max(const SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { return _mm_max_ps(a.val,b.val); }
    inline void operator+=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { a.val = _mm_add_ps(a.val,b.val); }
    inline void operator-=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { a.val = _mm_sub_ps(a.val,b.val); }
    inline void operator*=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { a.val = _mm_mul_ps(a.val,b.val); }
    inline void operator/=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { a.val = _mm_div_ps(a.val,b.val); }
    inline void operator&=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { a.val = _mm_and_ps(a.val,b.val); }
    inline void operator|=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { a.val = _mm_or_ps(a.val,b.val); }
    inline void operator^=(SimdVecAl<float,4> &a,const SimdVecAl<float,4> &b) { a.val = _mm_xor_ps(a.val,b.val); }
    #endif // __SSE__
    

    #ifdef __SSE2__
    template<> struct SimdSizeAl<double> { static const unsigned res = 2; };
    
    template<> struct SimdVecAl<double,2> {
        SimdVecAl() {}
        SimdVecAl(double v) { val = _mm_set1_pd(v); }
        inline SimdVecAl(const __v2df &v) { val = v; }
        //         inline SimdVecAl(const SimdVecAl &v) { val = v.val; }
        //         inline SimdVecAl &operator=(const SimdVecAl &v) { val = v.val; return *this; }
        template<class T2> SimdVecAl(const SimdVecAl<T2,2> &v) { val = _mm_set_pd(v[0],v[1]); }
        SimdVecAl(double v0,double v1) { val = _mm_set_pd(v1,v0); }
        static __v2df zero() { return _mm_setzero_pd(); }
        static const unsigned nb_elem = 2;
        const double &operator[](unsigned i) const { return ((const double *)&val)[i]; }
        double &operator[](unsigned i) { return ((double *)&val)[i]; }
        double sum() const { double res = ((const double *)&val)[0]; for(unsigned i=1;i<2;++i) res += ((const double *)&val)[i]; return res; }
         
        __v2df val;
    };
    inline SimdVecAl<double,2> operator+(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline SimdVecAl<double,2> operator-(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline SimdVecAl<double,2> operator*(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline SimdVecAl<double,2> operator/(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline SimdVecAl<double,2> operator&(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline SimdVecAl<double,2> operator|(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline SimdVecAl<double,2> operator^(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline SimdVecAl<double,2> min(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline SimdVecAl<double,2> max(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline void operator+=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline void operator-=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline void operator*=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline void operator/=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline void operator&=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline void operator|=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    inline void operator^=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) __attribute__((always_inline));
    
    inline SimdVecAl<double,2> operator+(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { return _mm_add_pd(a.val,b.val); }
    inline SimdVecAl<double,2> operator-(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { return _mm_sub_pd(a.val,b.val); }
    inline SimdVecAl<double,2> operator*(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { return _mm_mul_pd(a.val,b.val); }
    inline SimdVecAl<double,2> operator/(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { return _mm_div_pd(a.val,b.val); }
    inline SimdVecAl<double,2> operator&(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { return _mm_and_pd(a.val,b.val); }
    inline SimdVecAl<double,2> operator|(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { return _mm_or_pd(a.val,b.val); }
    inline SimdVecAl<double,2> operator^(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { return _mm_xor_pd(a.val,b.val); }
    inline SimdVecAl<double,2> min(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { return _mm_min_pd(a.val,b.val); }
    inline SimdVecAl<double,2> max(const SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { return _mm_max_pd(a.val,b.val); }
    inline void operator+=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { a.val = _mm_add_pd(a.val,b.val); }
    inline void operator-=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { a.val = _mm_sub_pd(a.val,b.val); }
    inline void operator*=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { a.val = _mm_mul_pd(a.val,b.val); }
    inline void operator/=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { a.val = _mm_div_pd(a.val,b.val); }
    inline void operator&=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { a.val = _mm_and_pd(a.val,b.val); }
    inline void operator|=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { a.val = _mm_or_pd(a.val,b.val); }
    inline void operator^=(SimdVecAl<double,2> &a,const SimdVecAl<double,2> &b) { a.val = _mm_xor_pd(a.val,b.val); }
    #endif // __SSE2__

}

#endif // LMT_SIMD_AL_H
