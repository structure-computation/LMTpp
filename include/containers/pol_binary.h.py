import string

print 'namespace LMT {'

lst=[
    ('Plus','operator+'),
    ('Minus','operator-'),
    ('Multiplies','operator*'),
    ('Divides','operator/'),
    ('Pow','pow'),
]

for op,sop in lst :

    print """
template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<"""+op+""",T1,T2>::T> """+sop+"""( const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q ) {
    PolBinOp<"""+op+""",nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<"""+op+""",T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<"""+op+""",T1,typename IsScalar<T2>::T>::T> """+sop+"""( const Pol<nd,nx,T1> &p, const T2 &q ) {
    PolBinOp<"""+op+""",nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<"""+op+""",T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<"""+op+""",typename IsScalar<T1>::T,T2>::T> """+sop+"""( const T1 &p, const Pol<nd,nx,T2> &q ) {
    PolBinOp<"""+op+""",nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<"""+op+""",T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}
"""


lst=["<",">","<=",">="]

for op in lst :

    print """
template <int nd, int ne, int nx, class T1, class T2>
bool operator"""+op+"""( const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q ) {
    return p.coefficients()[0]"""+op+"""q.coefficients()[0];
}

template <int nd, int nx, class T1, class T2>
bool operator"""+op+"""( const Pol<nd,nx,T1> &p, const T2 &q ) {
    return p.coefficients()[0]"""+op+"""q;
}

template <int nd, int nx, class T1, class T2>
bool operator"""+op+"""( const T1 &p, const Pol<nd,nx,T2> &q ) {
    return p"""+op+"""q.coefficients()[0];
}
"""

print """
template <int nd, int nx, class T>
Pol<nd,nx,T> pow(const Pol<nd,nx,T> &p, const int q) {
    if (q>0) {
        PolBinOp<Multiplies,nd,nd,nx> opmultiplies;
        Vec<T,DimPol<nd,nx>::valeur> res = p.coefficients();
        for (int i=1;i<q;i++)
            res=opmultiplies(res,p.coefficients());
        return Pol<nd,nx,T>(res);
    }
    else if (q<0) {
        PolBinOp<Divides,nd,nd,nx> opdivides;
        Vec<T,DimPol<nd,nx>::valeur> one(T(0));
        one[0] = T(1);
        return opdivides(one,pow(p,-q).coefficients());
    }    
    else
        return (Pol<nd,nx,T>(T(1)));
}
"""

print '}\n'
