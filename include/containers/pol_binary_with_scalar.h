namespace LMT {

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T> operator+(const Pol<nd,nx,T1> &P, const T2 &t) {
    typedef typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T,Pol<nd,nx,T>::dim> aux=P.coefficients();
    aux[0]+=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T> operator+(const T2 &t, const Pol<nd,nx,T1> &P) {
    typedef typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T,Pol<nd,nx,T>::dim> aux=P.coefficients();
    aux[0]+=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T> operator-(const Pol<nd,nx,T1> &P, const T2 &t) {
    typedef typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T,Pol<nd,nx,T>::dim> aux=P.coefficients();
    aux[0]-=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T> operator-(const T2 &t, const Pol<nd,nx,T1> &P) {
    typedef typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T,Pol<nd,nx,T>::dim> aux=-P.coefficients();
    aux[0]+=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T> operator*(const T2 &t, const Pol<nd,nx,T1> &P) {
    return Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(t*P.coefficients());
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T> operator*(const Pol<nd,nx,T1> &P, const T2 &t) {
    return Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(P.coefficients()*t);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> operator/(const T2 &t, const Pol<nd,nx,T1> &P) {
    return Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T>(t) / P;
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> operator/(const Pol<nd,nx,T1> &P, const T2 &t) {
    return Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> ( Vec<typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T,Pol<nd,nx,T1>::dim>(P.coefficients()) / typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T(t) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Pow,T1,T2>::T> pow(const Pol<nd,nx,T1> &p, const T2 &t) {
    return exp(t*log(p));
}

template <int nd, int nx, class T>
Pol<nd,nx,T> pow(const Pol<nd,nx,T> &p, unsigned t) {
    Pol<nd,nx,T> res = T(1);
    while (t--)
        res *= p;
    return res;
}

template <int nd, int nx, class T>
Pol<nd,nx,T> pow(const Pol<nd,nx,T> &p_, int t) {
    typedef Pol<nd,nx,T> P;
    P res = P(1);
    if ( t < 0 ) {
        P p = T(1) / p_;
        while (t++)
            res *= p;
    } else {
        while (t--)
            res *= p_;
    }
    return res;
}

}
