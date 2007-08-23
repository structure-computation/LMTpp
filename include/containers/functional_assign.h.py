lst = [
    ('Plus','+'),
    ('Minus','-'),
    ('Modulus','%'),
    ('Multiplies','*'),
    ('Divides','/'),
    ('And','&'),
    ('Or','|'),
    ('Xor','^'),
    ('ShiftLeft','<<'),
    ('ShiftRight','>>'),
]
for op,sop in lst:
    print '/// \InGroup Lambda'
    print 'struct '+op+'Equ { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 '+sop+'= p2; } };'
    print ''
    print '/// \InGroup Lambda'
    print 'template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, '+op+'Equ >'
    print 'operator'+sop+'=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, '+op+'Equ >( a, f ); }'
    print '/// \InGroup Lambda'
    print 'template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,'+op+'Equ> operator'+sop+'=(Function<C_1> &f,const T &val) {'
    print '    return Function<ALGOAssign1,Function<ALGOCst,T>,'+op+'Equ>( Function<ALGOCst,T>(val) );'
    print '}'
    print '/// \InGroup Lambda'
    print 'template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,'+op+'Equ>'
    print 'operator'+sop+'=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {'
    print '    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,'+op+'Equ>( val );'
    print '}'
    print ''
    
