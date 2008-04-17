import string, sys


print """// generated file from simd.h.py. Do not modify
#ifndef LMT_simd_HEADER
#define LMT_simd_HEADER

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
    SimdVec(const T &v) { for(unsigned i=0;i<s;++i) val[i] = v; }
    SimdVec(const T &v0,const T &v1,const T &v2,const T &v3) { val[0] = v0; val[1] = v1; val[2] = v2; val[3] = v3; }
    template<class T2> SimdVec(const SimdVec<T2,s> &v) { for(unsigned i=0;i<s;++i) val[i] = (T)v[i]; }
    static const unsigned nb_elem = s;
    const T &operator[](unsigned i) const { return val[i]; }
    T &operator[](unsigned i) { return val[i]; }
    
    T val[s];
};

template<class TT,unsigned s> struct TypeInformation<SimdVec<TT,s> > {
    static const int res = TypeInformation<TT>::res;
    static const int englobing = 1 + TypeInformation<TT>::englobing;
    typedef TT SubType;
    template<class TV> struct Variant { typedef SimdVec<TV,s> T; };
    template<class TV> struct DeepVariant { typedef SimdVec<typename TypeInformation<TT>::template DeepVariant<TV>::T,s> T; };
    static std::string type() { return "SimdVec<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};

"""

for TS,t,n,ts,tset,tset0,tsetn in [
            ('SSE' ,'float' ,4,'__v4sf','_mm_set1_ps','_mm_setzero_ps()','_mm_set_ps'),
            ('SSE2','double',2,'__v2df','_mm_set1_pd','_mm_setzero_pd()','_mm_set_pd')
            # ('SSE','int',4,'__v4hi','__v4hi','_mm_setzero_pd()','_mm_set_pd')
        ]:
    tp = 'SimdVec<'+t+','+str(n)+'>'
    print """
#ifdef __"""+TS+"""__
    template<> struct SimdSize<"""+t+"""> { static const unsigned res = """+str(n)+"""; };
    
    template<>
    struct """+tp+""" {
        SimdVec() {}
        SimdVec(const """+t+""" &v) { val = """+tset+"""(v); }
        SimdVec(const """+ts+""" &v) { val = v; }
        SimdVec(const SimdVec &v) { val = v.val; }
        template<class T2> SimdVec(const SimdVec<T2,"""+str(n)+"""> &v) { val = """+tsetn+"""("""+string.join(['v[%i]'%i for i in range(n)],',')+"""); }
        SimdVec("""+string.join(['const '+t+' &v%i'%i for i in range(n)],',')+""") { val = """+tsetn+"""("""+string.join(['v%i'%i for i in range(n)],',')+"""); }
        static """+ts+""" zero() { return """+tset0+"""; }
        static const unsigned nb_elem = """+str(n)+""";
        const """+t+""" &operator[](unsigned i) const { return ((const """+t+""" *)&val)[i]; }
        """+t+""" &operator[](unsigned i) { return (("""+t+""" *)&val)[i]; }
        
        """+ts+""" val;
    };
#endif // __"""+TS+"""__
    """


# --------------------------- unary operations ---------------------------

lst = [
    ('conj' ,'P1'                        , ''           , ''            ),
    ('abs' , 'typename SubComplex<P1>::T', ''           , ''            ),
    ('acos' ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('asin' ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('atan' ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('cos'  ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('cosh' ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('exp'  ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('log'  ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('log10','typename FloatType<P1>::T' , ''           , ''            ),
    ('sin'  ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('sinh' ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('sqrt' ,'typename FloatType<P1>::T' , '_mm_sqrt_ps', '_mm_sqrt_pd' ),
    ('tan'  ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('tanh' ,'typename FloatType<P1>::T' , ''           , ''            ),
    ('real' ,'typename SubComplex<P1>::T', ''           , ''            ),
    ('imag' ,'typename SubComplex<P1>::T', ''           , ''            ),
    ('-'    ,'P1'                        , ''           , ''            ),
]
# generic case
for op,tp,sseop,sse2op in lst:
    Op = string.capitalize(op)
    if op=='-': Op = 'Negate'
    print 'class '+Op+';'
    
for op,tp,sseop,sse2op in lst:
    tp = 'SimdVec<'+tp+',s>'
    
    Op = string.capitalize(op)
    if op=='-': Op = 'Negate'
    
    fsop = op
    if op=='-': fsop = 'operator'+op
    
    u = ""
    if op in ["conj","abs","real","imag"]: u = "using LMT::"+op+"; "
    #if op in ["conj","abs","real","imag"]: op = "LMT::"+op
    
    print 'template<class P1,unsigned s> '+tp+' '+fsop+'(const SimdVec<P1,s> &a) { '+tp \
        +' res; ' + u + 'for(unsigned i=0;i<s;++i) res[i] = '+op+'(a[i]); return res; }'
    print 'template<> struct OpSupportSIMD<'+Op+'> { static const unsigned res = true; };'

# simd case
for TS,ti in [ ('SSE','float,4'), ('SSE2','double,2') ]:
    print '#ifdef __'+TS+'__'
    for op,tp2,sseop,sse2op in lst:
        tp = 'SimdVec<'+ti+'>'
        if TS=='SSE':  vecop = sseop
        if TS=='SSE2': vecop = sse2op
        fsop = op
        if op=='-': fsop = 'operator'+op
        if sseop: print '    inline '+tp+' '+fsop+'(const '+tp+' &a) { return '+vecop+'(a.val); }'
    print '#endif // __'+TS+'__'
    print ''

# ---------------------- binary operations ---------------------- 
print

lst = [
    ('Plus'      , '+'  , '_mm_add_ps', '_mm_add_pd' ),
    ('Minus'     , '-'  , '_mm_sub_ps', '_mm_sub_pd' ),
    ('Modulus'   , '%'  , ''          , ''           ),
    ('Multiplies', '*'  , '_mm_mul_ps', '_mm_mul_pd' ),
    ('Divides'   , '/'  , '_mm_div_ps', '_mm_div_pd' ),
    ('Equal'     , '==' , ''          , ''           ),
    ('NotEqual'  , '!=' , ''          , ''           ),
    ('Less'      , '<'  , ''          , ''           ),
    ('Greater'   , '>'  , ''          , ''           ),
    ('LessEq'    , '<=' , ''          , ''           ),
    ('GreaterEq' , '>=' , ''          , ''           ),
    ('And'       , '&'  , '_mm_and_ps', '_mm_and_pd' ),
    ('Or'        , '|'  , '_mm_or_ps' , '_mm_or_pd'  ),
    ('Xor'       , '^'  , '_mm_xor_ps', '_mm_xor_pd' ),
    ('AndAnd'    , '&&' , ''          , ''           ),
    ('OrOr'      , '||' , ''          , ''           ),
#    ('ShiftLeft' , '<<' , ''          , ''           ),
#    ('ShiftRight', '>>' , ''          , ''           ),
    ('Min'       , 'min', '_mm_min_ps', '_mm_min_pd' ),
    ('Max'       , 'max', '_mm_max_ps', '_mm_max_pd' ),
]
# generic case
for op,sop,sseop,sse2op in lst:
    print 'class '+op+';'
for op,sop,sseop,sse2op in lst:
    tp = 'SimdVec<typename TypePromote<'+op+',P1,P2>::T,s>'
    csop = 'a[i] '+sop+' b[i]'
    fsop = 'operator'+sop
    if sop=='min' or sop=='max':
        csop = sop+'(a[i],b[i])'
        fsop = sop
    print 'template<class P1,class P2,unsigned s> '+tp+' '+fsop+'(const SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { '+tp+' res; for(unsigned i=0;i<s;++i) res[i] = '+csop+'; return res; }'
    if sop in ['+','-','*','/']:
        print 'template<class P1,class P2,unsigned s> '+tp+' '+fsop+'=(SimdVec<P1,s> &a,const SimdVec<P2,s> &b) { for(unsigned i=0;i<s;++i) a[i] = '+csop+'; return a; }'
    print 'template<> struct OpSupportSIMD<'+op+'> { static const unsigned res = true; };'
    
# simd case
for TS,ti in [ ('SSE','float,4'), ('SSE2','double,2') ]:
    print '#ifdef __'+TS+'__'
    for op,sop,sseop,sse2op in lst:
        tp = 'SimdVec<'+ti+'>'
        if TS=='SSE':  vecop = sseop
        if TS=='SSE2': vecop = sse2op
        fsop = 'operator'+sop
        if sop=='min' or sop=='max': fsop = sop
        if sseop:
            print '    inline '+tp+' '+fsop+'(const '+tp+' &a,const '+tp+' &b) { return '+vecop+'(a.val,b.val); }'
            if fsop != sop:
                print '    inline '+tp+' '+fsop+'=('+tp+' &a,const '+tp+' &b) { a.val = '+vecop+'(a.val,b.val); return a; }'
    print '#endif // __'+TS+'__'
    print ''



# ---------------------- display ---------------------- 
print """
template<class T,unsigned s> std::ostream &operator<<(std::ostream &os,const SimdVec<T,s> &v) {
    for(unsigned i=0;i<s;++i) os << v[i] << (i<s-1?" ":"");
    return os;
}
"""


print '}'

print """
namespace std {
    template<class T,unsigned n> struct numeric_limits<LMT::SimdVec<T,n> > {
        static LMT::SimdVec<T,n> max() { return numeric_limits<T>::max(); }
    };
}
namespace LMT {
    template<class TT,unsigned n> struct SubComplex<LMT::SimdVec<std::complex<TT>,n> > {
        typedef LMT::SimdVec<TT,n> T;
    };
}
"""

print '#endif // LMT_simd_HEADER'

        