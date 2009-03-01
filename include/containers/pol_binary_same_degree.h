namespace LMT {

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator+ (const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    return Pol<nd,nx,typename TypePromote<Plus,T1,T2>::T>(P.coefficients()+Q.coefficients());
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,T1,T2>::T> operator- (const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    return Pol<nd,nx,typename TypePromote<Minus,T1,T2>::T>(P.coefficients()-Q.coefficients());
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,T1,T2>::T> operator* (const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    typedef typename TypePromote<Multiplies,T1,T2>::T T;
    Vec<T,DimPol<nd,nx>::valeur> res_vec;
    res_vec.set(T(0));
    if (PolMultiplies<nd,nx>::init_mult)
        PolMultiplies<nd,nx>::initialize_mult();
    for (int i=0;i<DimPol<nd,nx>::valeur;i++)
        PolMultiplies<nd,nx>::multiplies(res_vec,i,P.coefficients(),Q.coefficients());
    return Pol<nd,nx,T>(res_vec);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,T2>::T> operator/ (const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    typedef typename TypePromote<Divides,T1,T2>::T T;
    Vec<T,DimPol<nd,nx>::valeur> a,res_vec;
    a.set(T(0));
    a[0]=T2(1)/Q.coefficients()[0];
    res_vec.set(T(0));
    res_vec[0]=P.coefficients()[0]/Q.coefficients()[0];
    if (PolMultiplies<nd,nx>::init_mult)
        PolMultiplies<nd,nx>::initialize_mult();
    for (int i=1;i<DimPol<nd,nx>::valeur;i++) {
        PolMultiplies<nd,nx>::multiplies(a,i,-Q.coefficients(),a,1);
        a[i]/=Q.coefficients()[0];
        PolMultiplies<nd,nx>::multiplies(res_vec,i,P.coefficients(),a);
    }
    return Pol<nd,nx,T>(res_vec);
}

}

