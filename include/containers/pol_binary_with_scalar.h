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

}
