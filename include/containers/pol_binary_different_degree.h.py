lst=[
    ('Plus','+'),
    ('Minus','-'),
    ('Multiplies','*'),
    ('Divides','/'),
]

print 'namespace LMT {\n'

print 'template <int nd1, int nd2, int nx, class T1, class T2>'
print 'Pol<nd1,nx,T1> converter (const Pol<nd2,nx,T2> &P, Relative_Number<nd1>, Relative_Number<nx>, const T1 &t) {return P;};\n'

print 'template <int nd, int nx, class T>'
print 'const Pol<nd,nx,T> &converter (const Pol<nd,nx,T> &P, Relative_Number<nd>, Relative_Number<nx>, const T &t) {return P;};\n'

for c,s in lst:
    print 'template <int nd1, int nd2, int nx, class T1, class T2>'
    print 'Pol<(nd1>nd2?nd2:nd1),nx,typename TypePromote<'+c+',T1,T2>::T> operator'+s+'(const Pol<nd1,nx,T1> &P, const Pol<nd2,nx,T2> &Q) {'
    print '    const int nd=(nd1>nd2?nd2:nd1);'
    print '    typedef typename TypePromote<'+c+',T1,T2>::T T;'
    print '    return converter(P,Relative_Number<nd>(),Relative_Number<nx>(),T()) '+s+' converter(Q,Relative_Number<nd>(),Relative_Number<nx>(),T());'
    print '}\n'

print '}\n'
