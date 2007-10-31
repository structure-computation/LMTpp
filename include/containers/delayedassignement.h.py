from string import *

print """// file generated from delayedassignement.h.py. do not modify
#ifndef LMT_delayedassignement_HEADER
#define LMT_delayedassignement_HEADER


namespace LMT {

template<class Source>
class DelayedAssignement {
public:
    DelayedAssignement(const Source &s=Source()):source(s) {}
    template<class T> operator T() const { return source.get(); }"""
    

lst = [
    ('Function<C_2>',''),
    ('Plus','+'),
    ('Minus','-'),
    ('Modulus','%'),
    ('Multiplies','*'),
    ('Divides','/'),
    ('And','&'),
    ('Or','|'),
    ('Xor','^'),
#    ('ShiftLeft','<<'),
#    ('ShiftRight','>>'),
]
for op,sop in lst:
    print '    template<class T> DelayedAssignement &operator'+sop+'=(const T &val) { source.apply('+op+'(),val); return *this; }'
print """    Source source;
};

/**
    \relates Mat
*/
template<class Source>
std::ostream &operator<<(std::ostream &os,const DelayedAssignement<Source> &da) {
    os << (typename Source::T)da;
    return os;
}

template<class Source> struct TypeInformation<DelayedAssignement<Source> > {
    typedef typename Source::T TS;
    static const int res = TypeInformation<TS>::res;
    static const int englobing = TypeInformation<TS>::englobing;
    static std::string type() { return TypeInformation<TS>::type(); }
    static const bool float_type = TypeInformation<TS>::float_type;
    template<class TV> struct DeepVariant { typedef typename TypeInformation<TS>::template DeepVariant<TV>::T T; };
};
"""

lst = [
    ('conj' ,'P1'                        , 'true'  ),
    ('abs' , 'P1'                        , 'true'  ),
    ('acos' ,'typename FloatType<P1>::T' , 'false' ),
    ('asin' ,'typename FloatType<P1>::T' , 'true'  ),
    ('atan' ,'typename FloatType<P1>::T' , 'true'  ),
    ('cos'  ,'typename FloatType<P1>::T' , 'false' ),
    ('cosh' ,'typename FloatType<P1>::T' , 'false' ),
    ('exp'  ,'typename FloatType<P1>::T' , 'false' ),
    ('log'  ,'typename FloatType<P1>::T' , 'true'  ),
    ('log10','typename FloatType<P1>::T' , 'true'  ),
    ('sin'  ,'typename FloatType<P1>::T' , 'true'  ),
    ('sinh' ,'typename FloatType<P1>::T' , 'true'  ),
    ('sqrt' ,'typename FloatType<P1>::T' , 'true'  ),
    ('tan'  ,'typename FloatType<P1>::T' , 'true'  ),
    ('tanh' ,'typename FloatType<P1>::T' , 'true'  ),
    ('real' ,'typename SubComplex<P1>::T', 'true'  ),
    ('imag' ,'typename SubComplex<P1>::T', 'true'  ),
    ('-'    ,'P1'                        , 'true'  ),
]
for i,ret,conserve_sp in lst:
    ret = replace( ret, 'P1', 'typename Source::T' )
    I = i
    if i=='-': I = 'operator-'
    else:      i = 'LMT::' + i
    print 'template<class Source> '+ret+' '+I+'(const DelayedAssignement<Source> &da) { return '+i+'( da.source.get() ); }'

lst = [
    ('Plus'      , '+'   ),
    ('Minus'     , '-'   ),
    ('Modulus'   , '%'   ),
    ('Multiplies', '*'   ),
    ('Divides'   , '/'   ),
    ('Equal'     , '=='  ),
    ('NotEqual'  , '!='  ),
    ('Less'      , '<'   ),
    ('Greater'   , '>'   ),
    ('LessEq'    , '<='  ),
    ('GreaterEq' , '>='  ),
    ('And'       , '&'   ),
    ('Or'        , '|'   ),
    ('Xor'       , '^'   ),
    ('AndAnd'    , '&&'  ),
    ('OrOr'      , '||'  ),
    #('ShiftLeft' , '<<'  ),
    #('ShiftRight', '>>'  ),
    ('Min'       , 'min' ),
    ('Max'       , 'max' ),
]
for op,sop in lst:
    if op in ['Min','Max']:
        I = sop
        print 'template<class Source,class T> typename TypePromote<'+op+',typename Source::T,T>::T '+I+'(const DelayedAssignement<Source> &a,const T &b) { return '+sop+'(a.source.get(),b); }'
        print 'template<class T,class Source> typename TypePromote<'+op+',T,typename Source::T>::T '+I+'(const T &a,const DelayedAssignement<Source> &b) { return '+sop+'(a,b.source.get()); }'
        print 'template<class S1,class S2> typename TypePromote<'+op+',typename S1::T,typename S2::T>::T '+I+'(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return '+sop+'(a.source.get(),b.source.get()); }'
    else:
        I = 'operator'+sop
        print 'template<class Source,class T> typename TypePromote<'+op+',typename Source::T,T>::T '+I+'(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() '+sop+' b; }'
        print 'template<class T,class Source> typename TypePromote<'+op+',T,typename Source::T>::T '+I+'(const T &a,const DelayedAssignement<Source> &b) { return a '+sop+' b.source.get(); }'
        print 'template<class S1,class S2> typename TypePromote<'+op+',typename S1::T,typename S2::T>::T '+I+'(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() '+sop+' b.source.get(); }'
    print
    
print """
};

#endif // LMT_delayedassignement_HEADER
"""
