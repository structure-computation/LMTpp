namespace LMT {

template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<Plus,T1,T2>::T> operator+ (const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q) {
    PolBinOp<Plus,nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<Plus,T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T> operator+(const Pol<nd,nx,T1> &p, const T2 &q) {
    PolBinOp<Plus,nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,typename IsScalar<T1>::T,T2>::T> operator+(const T1 &p, const Pol<nd,nx,T2> &q) {
    PolBinOp<Plus,nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}


template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<Minus,T1,T2>::T> operator- (const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q) {
    PolBinOp<Minus,nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<Minus,T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T> operator-(const Pol<nd,nx,T1> &p, const T2 &q) {
    PolBinOp<Minus,nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,typename IsScalar<T1>::T,T2>::T> operator-(const T1 &p, const Pol<nd,nx,T2> &q) {
    PolBinOp<Minus,nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}


template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<Multiplies,T1,T2>::T> operator* (const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q) {
    PolBinOp<Multiplies,nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<Multiplies,T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T> operator*(const Pol<nd,nx,T1> &p, const T2 &q) {
    PolBinOp<Multiplies,nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,typename IsScalar<T1>::T,T2>::T> operator*(const T1 &p, const Pol<nd,nx,T2> &q) {
    PolBinOp<Multiplies,nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}


template <int nd, int ne, int nx, class T1, class T2>
Pol<MIN(nd,ne),nx,typename TypePromote<Divides,T1,T2>::T> operator/ (const Pol<nd,nx,T1> &p, const Pol<ne,nx,T2> &q) {
    PolBinOp<Divides,nd,ne,nx> op;
    return Pol<MIN(nd,ne),nx,typename TypePromote<Divides,T1,T2>::T>( op(p.coefficients(),q.coefficients()) );
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> operator/(const Pol<nd,nx,T1> &p, const T2 &q) {
    PolBinOp<Divides,nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T>(op(p.coefficients(),q));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,typename IsScalar<T1>::T,T2>::T> operator/(const T1 &p, const Pol<nd,nx,T2> &q) {
    PolBinOp<Divides,nd,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T>(op(p,q.coefficients()));
}

}

