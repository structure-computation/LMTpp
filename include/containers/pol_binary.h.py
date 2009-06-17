import string
lst=[
    ('Plus','+'),
    ('Minus','-'),
    #('Multiplies','*'),
    #('Divides','/'),
]

print 'namespace LMT {'

for op,sop in lst :

    print """
template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<"""+op+""",T1,T2>::T> operator"""+sop+""" (const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q) {
    PolOp<"""+op+""",nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<"""+op+""",T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<"""+op+""",T1,typename IsScalar<T2>::T>::T> operator"""+sop+"""(const Pol<nd,nx,T1> &p, const T2 &q) {
    PolOp<"""+op+""",nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<"""+op+""",T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<"""+op+""",typename IsScalar<T1>::T,T2>::T> operator"""+sop+"""(const T1 &p, const Pol<nd,nx,T2> &q) {
    PolOp<"""+op+""",nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<"""+op+""",T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}
"""

lst=[
    ('Multiplies','*'),
    ('Divides','/'),
]

for op,sop in lst :

    print """
template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<"""+op+""",T1,T2>::T> operator"""+sop+""" (const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q) {
    if (Pol"""+op+"""<nd,ne,nx>::needs_initialization)
        Pol"""+op+"""<nd,ne,nx>::initialize();
    Pol"""+op+"""<nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<"""+op+""",T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<"""+op+""",T1,typename IsScalar<T2>::T>::T> operator"""+sop+"""(const Pol<nd,nx,T1> &p, const T2 &q) {
    Pol"""+op+"""<nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<"""+op+""",T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<"""+op+""",typename IsScalar<T1>::T,T2>::T> operator"""+sop+"""(const T1 &p, const Pol<nd,nx,T2> &q) {
    Pol"""+op+"""<nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<"""+op+""",T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}
"""

print '}\n'