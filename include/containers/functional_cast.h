/*
lst = [
    'int',
    'unsigned',
    'bool',
    'double',
    'float',
]
for i in lst:
    print '/// \\ingroup Lambda'
    I = 'Cast_'+i
    print 'struct '+I+' {'
    print '    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef '+i+' T; };'
    print '    template<class P1> '+i+' operator()(const P1 &p1) const { return '+i+'(p1); }'
    print '};'
    
    print 'template<class O1,class O2,class O3,class O4,class O5>'
    print 'Function<ALGOCompose1,'+I+',Function<O1,O2,O3,O4,O5>,void,void> cast_'+i+'(const Function<O1,O2,O3,O4,O5> &f) {'
    print '    return Function<ALGOCompose1,'+I+',Function<O1,O2,O3,O4,O5>,void,void>( '+I+'(), f );'
    print '}'
    print ''
*/
/// \ingroup Lambda
struct Cast_int {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef int T; };
    template<class P1> int operator()(const P1 &p1) const { return int(p1); }
};
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Cast_int,Function<O1,O2,O3,O4,O5>,void,void> cast_int(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Cast_int,Function<O1,O2,O3,O4,O5>,void,void>( Cast_int(), f );
}

/// \ingroup Lambda
struct Cast_unsigned {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef unsigned T; };
    template<class P1> unsigned operator()(const P1 &p1) const { return unsigned(p1); }
};
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Cast_unsigned,Function<O1,O2,O3,O4,O5>,void,void> cast_unsigned(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Cast_unsigned,Function<O1,O2,O3,O4,O5>,void,void>( Cast_unsigned(), f );
}

/// \ingroup Lambda
struct Cast_bool {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef bool T; };
    template<class P1> bool operator()(const P1 &p1) const { return bool(p1); }
};
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Cast_bool,Function<O1,O2,O3,O4,O5>,void,void> cast_bool(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Cast_bool,Function<O1,O2,O3,O4,O5>,void,void>( Cast_bool(), f );
}

/// \ingroup Lambda
struct Cast_double {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef double T; };
    template<class P1> double operator()(const P1 &p1) const { return double(p1); }
};
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Cast_double,Function<O1,O2,O3,O4,O5>,void,void> cast_double(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Cast_double,Function<O1,O2,O3,O4,O5>,void,void>( Cast_double(), f );
}

/// \ingroup Lambda
struct Cast_float {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef float T; };
    template<class P1> float operator()(const P1 &p1) const { return float(p1); }
};
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Cast_float,Function<O1,O2,O3,O4,O5>,void,void> cast_float(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Cast_float,Function<O1,O2,O3,O4,O5>,void,void>( Cast_float(), f );
}

