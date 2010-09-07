namespace LMT {

template <int nd, int nx, class T>
typename TypePromote<Abs,Pol<nd,nx,T> >::T abs(const Pol<nd,nx,T> &p) {
    PolUnOp<Abs,nd,nx> op;
    return typename TypePromote<Abs,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Conj,Pol<nd,nx,T> >::T conj(const Pol<nd,nx,T> &p) {
    PolUnOp<Conj,nd,nx> op;
    return typename TypePromote<Conj,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Real,Pol<nd,nx,T> >::T real(const Pol<nd,nx,T> &p) {
    PolUnOp<Real,nd,nx> op;
    return typename TypePromote<Real,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Imag,Pol<nd,nx,T> >::T imag(const Pol<nd,nx,T> &p) {
    PolUnOp<Imag,nd,nx> op;
    return typename TypePromote<Imag,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Acos,Pol<nd,nx,T> >::T acos(const Pol<nd,nx,T> &p) {
    PolUnOp<Acos,nd,nx> op;
    return typename TypePromote<Acos,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Asin,Pol<nd,nx,T> >::T asin(const Pol<nd,nx,T> &p) {
    PolUnOp<Asin,nd,nx> op;
    return typename TypePromote<Asin,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Atan,Pol<nd,nx,T> >::T atan(const Pol<nd,nx,T> &p) {
    PolUnOp<Atan,nd,nx> op;
    return typename TypePromote<Atan,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Cos,Pol<nd,nx,T> >::T cos(const Pol<nd,nx,T> &p) {
    PolUnOp<Cos,nd,nx> op;
    return typename TypePromote<Cos,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Cosh,Pol<nd,nx,T> >::T cosh(const Pol<nd,nx,T> &p) {
    PolUnOp<Cosh,nd,nx> op;
    return typename TypePromote<Cosh,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Exp,Pol<nd,nx,T> >::T exp(const Pol<nd,nx,T> &p) {
    PolUnOp<Exp,nd,nx> op;
    return typename TypePromote<Exp,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Log,Pol<nd,nx,T> >::T log(const Pol<nd,nx,T> &p) {
    PolUnOp<Log,nd,nx> op;
    return typename TypePromote<Log,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Log10,Pol<nd,nx,T> >::T log10(const Pol<nd,nx,T> &p) {
    PolUnOp<Log10,nd,nx> op;
    return typename TypePromote<Log10,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Sin,Pol<nd,nx,T> >::T sin(const Pol<nd,nx,T> &p) {
    PolUnOp<Sin,nd,nx> op;
    return typename TypePromote<Sin,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Sinh,Pol<nd,nx,T> >::T sinh(const Pol<nd,nx,T> &p) {
    PolUnOp<Sinh,nd,nx> op;
    return typename TypePromote<Sinh,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Sqrt,Pol<nd,nx,T> >::T sqrt(const Pol<nd,nx,T> &p) {
    PolUnOp<Sqrt,nd,nx> op;
    return typename TypePromote<Sqrt,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Tan,Pol<nd,nx,T> >::T tan(const Pol<nd,nx,T> &p) {
    PolUnOp<Tan,nd,nx> op;
    return typename TypePromote<Tan,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Tanh,Pol<nd,nx,T> >::T tanh(const Pol<nd,nx,T> &p) {
    PolUnOp<Tanh,nd,nx> op;
    return typename TypePromote<Tanh,Pol<nd,nx,T> >::T( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Abs,T>::T abs_indication(const Pol<nd,nx,T> &P) {
    return abs(P.coefficients()[0]);
}

}
