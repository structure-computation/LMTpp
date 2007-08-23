# operators
lst = [
    ('Plus'      , '+'  , '(T)0'                              , '' ),
    ('Minus'     , '-'  , '(T)0'                              , '' ),
    ('Modulus'   , '%'  , ''                                  , '1' ),
    ('Multiplies', '*'  , '(T)1'                              , '1' ),
    ('Divides'   , '/'  , '(T)1'                              , '1' ),
    ('Equal'     , '==' , ''                                  , '' ),
    ('NotEqual'  , '!=' , ''                                  , '' ),
    ('Less'      , '<'  , ''                                  , '' ),
    ('Greater'   , '>'  , ''                                  , '' ),
    ('LessEq'    , '<=' , ''                                  , '' ),
    ('GreaterEq' , '>=' , ''                                  , '' ),
    ('And'       , '&'  , '(T)1'                              , '1' ),
    ('Or'        , '|'  , '(T)0'                              , '' ),
    ('Xor'       , '^'  , '(T)0'                              , '' ),
    ('AndAnd'    , '&&' , ''                                  , '1' ),
    ('OrOr'      , '||' , ''                                  , '' ),
#    ('ShiftLeft' , '<<' , ''                                  , '' ),
#    ('ShiftRight', '>>' , ''                                  , '' ),
    ('Min'       , 'min', 'std::numeric_limits<T>::max()' , '' ),
    ('Max'       , 'max', '-std::numeric_limits<T>::max()', '' ),
]
for op,sop,dr,conserve_sp in lst:
    ret = 'typename TypePromote<'+op+',P1,P2>::T'
    
    csop = 'p1 '+sop+' p2'
    if sop=='min' or sop=='max':
        csop = sop+'(p1,p2)'
    
    print '/// \\relates Lambda'
    print 'struct '+op+' {'
    print '    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef '+ret+' T; };'
    print '    template<class P1,class P2> '+ret+' operator()(const P1 &p1,const P2 &p2) const { return '+csop+'; }'
    if dr: print '    template<class T> inline void init_reduction(T &p) const { p = '+dr+'; }'
    print '};'
    if conserve_sp:
        print 'template<> struct ConserveZeroes<'+op+'> { static const unsigned res = '+conserve_sp+'; };'

    print '/// \\relates Lambda'
    print 'template<class O1,class O2,class O3,class O4,class O5,class T>'
    print 'Function< ALGOBinary, '+op+', Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator'+sop+'(const Function<O1,O2,O3,O4,O5> &f,const T &t) {'
    print '    return Function< ALGOBinary, '+op+', Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( '+op+'(), f, Function<ALGOCst,T>(t) );'
    print '}'
    print '/// \\relates Lambda'
    print 'template<class O1,class O2,class O3,class O4,class O5,class T>'
    print 'Function< ALGOBinary, '+op+', Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator'+sop+'(const T &t,const Function<O1,O2,O3,O4,O5> &f) {'
    print '    return Function< ALGOBinary, '+op+', Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( '+op+'(), Function<ALGOCst,T>(t), f );'
    print '}'

    print '/// \\relates Lambda'
    print 'template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>'
    print 'Function<ALGOBinary,'+op+',Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator'+sop+'(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {'
    print '    return Function<ALGOBinary,'+op+',Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( '+op+'(), f1, f2 );'
    print '}'
    print ''

