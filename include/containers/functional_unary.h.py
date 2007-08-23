import string

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
    I = string.capitalize(i)
    if i=='-': I = 'Negate'
    
    print '/// \\InGroup Lambda'
    print 'struct '+I+' {'
    print '    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef '+ret+' T; };'
    print '    template<class P1> '+ret+' operator()(const P1 &p1) const {' + ('using LMT::%s;'%i) * (i!='-') + 'return '+'LMT::'*(i!='-')+i+'(p1); }'
    print '};'
    if conserve_sp=='true':
        print 'template<> struct ConserveZeroes<'+I+'> { static const unsigned res = '+conserve_sp+'; };'

    print '/// \\InGroup Lambda'
    print 'template<class O1,class O2,class O3,class O4,class O5>'
    if i=='-': i = 'operator-'
    print 'Function<ALGOCompose1,'+I+',Function<O1,O2,O3,O4,O5>,void,void> '+i+'(const Function<O1,O2,O3,O4,O5> &f) {'
    print '    return Function<ALGOCompose1,'+I+',Function<O1,O2,O3,O4,O5>,void,void>( '+I+'(), f );'
    print '}'
    print ''

