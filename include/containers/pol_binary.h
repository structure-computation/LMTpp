namespace LMT {


template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<Plus,T1,T2>::T> operator+ (const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q) {
    if (PolPlus<nd,ne,nx>::needs_initialization)
        PolPlus<nd,ne,nx>::initialize();
    PolPlus<nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<Plus,T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T> operator+(const Pol<nd,nx,T1> &p, const T2 &q) {
    PolPlus<nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,typename IsScalar<T1>::T,T2>::T> operator+(const T1 &p, const Pol<nd,nx,T2> &q) {
    PolPlus<nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}


template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<Minus,T1,T2>::T> operator- (const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q) {
    if (PolMinus<nd,ne,nx>::needs_initialization)
        PolMinus<nd,ne,nx>::initialize();
    PolMinus<nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<Minus,T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T> operator-(const Pol<nd,nx,T1> &p, const T2 &q) {
    PolMinus<nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,typename IsScalar<T1>::T,T2>::T> operator-(const T1 &p, const Pol<nd,nx,T2> &q) {
    PolMinus<nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}


template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<Multiplies,T1,T2>::T> operator* (const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q) {
    if (PolMultiplies<nd,ne,nx>::needs_initialization)
        PolMultiplies<nd,ne,nx>::initialize();
    PolMultiplies<nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<Multiplies,T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T> operator*(const Pol<nd,nx,T1> &p, const T2 &q) {
    PolMultiplies<nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,typename IsScalar<T1>::T,T2>::T> operator*(const T1 &p, const Pol<nd,nx,T2> &q) {
    PolMultiplies<nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}


template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<Divides,T1,T2>::T> operator/ (const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q) {
    if (PolDivides<nd,ne,nx>::needs_initialization)
        PolDivides<nd,ne,nx>::initialize();
    PolDivides<nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<Divides,T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> operator/(const Pol<nd,nx,T1> &p, const T2 &q) {
    PolDivides<nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,typename IsScalar<T1>::T,T2>::T> operator/(const T1 &p, const Pol<nd,nx,T2> &q) {
    PolDivides<nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}

}

