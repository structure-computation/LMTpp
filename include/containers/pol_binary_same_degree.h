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
    typedef Pol<nd,nx,T> PdxT;
    Vec<T,PdxT::dim> res_vec;
    res_vec.set(T(0));
    if (PdxT::init_mult)
         PdxT::initialize_mult();
     for (int i=0;i<PdxT::dim;i++)
         for (int j=0;j<PdxT::mult[i].size();j++)
             res_vec[i]+=P.coefficients()[PdxT::mult[i][j][0]]*Q.coefficients()[PdxT::mult[i][j][1]];
    return PdxT(res_vec);
}

template <int nd, class T1, class T2>
Pol<nd,1,typename TypePromote<Multiplies,T1,T2>::T> operator* (const Pol<nd,1,T1> &P, const Pol<nd,1,T2> &Q) {
    typedef typename TypePromote<Multiplies,T1,T2>::T T;
    typedef Pol<nd,1,T> PdxT;
    Vec<T,PdxT::dim> res_vec;
    res_vec.set(T(0));
    for (int i=0;i<Pol<nd,1,T>::dim;i++)
        for (int j=0;j<=i;j++)
            res_vec[i]+=P.coefficients()[j]*Q.coefficients()[i-j];
    return PdxT(res_vec);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,T2>::T> operator/ (const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    typedef typename TypePromote<Divides,T1,T2>::T T;
    typedef Pol<nd,nx,T> PdxT;
    Vec<T,PdxT::dim> a,res_vec;
    a.set(T(0));
    a[0]=T2(1)/Q.coefficients()[0];
    res_vec.set(T(0));
    res_vec[0]=P.coefficients()[0]/Q.coefficients()[0];
    if (PdxT::init_mult)
        PdxT::initialize_mult();
    for (int i=1;i<PdxT::dim;i++) {
        for (int j=0;j<PdxT::mult[i].size()-1;j++)
            a[i]-=Q.coefficients()[PdxT::mult[i][j][0]]*a[PdxT::mult[i][j][1]];
        a[i]/=Q.coefficients()[0];
        for (int j=0;j<PdxT::mult[i].size();j++)
            res_vec[i]+=P.coefficients()[PdxT::mult[i][j][0]]*a[PdxT::mult[i][j][1]];
   }
    return PdxT(res_vec);
}

template <int nd, class T1, class T2>
Pol<nd,1,typename TypePromote<Divides,T1,T2>::T> operator/ (const Pol<nd,1,T1> &P, const Pol<nd,1,T2> &Q) {
    typedef typename TypePromote<Divides,T1,T2>::T T;
    typedef Pol<nd,1,T> PdxT;
    Vec<T,PdxT::dim> a,res_vec;
    a.set(T(0));
    a[0]=T2(1)/Q.coefficients()[0];
    res_vec.set(T(0));
    res_vec[0]=P.coefficients()[0]/Q.coefficients()[0];
    for (int i=1;i<PdxT::dim;i++) {
        for (int j=0;j<i;j++)
            a[i]-=Q.coefficients()[i-j]*a[j];
        a[i]/=Q.coefficients()[0];
        for (int j=0;j<=i;j++)
            res_vec[i]+=P.coefficients()[j]*a[i-j];
   }
    return PdxT(res_vec);
}

}

