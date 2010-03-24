namespace LMT {

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Abs,T>::T> abs(const Pol<nd,nx,T> &p) {
    PolUnOp<Abs,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Abs,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Conj,T>::T> conj(const Pol<nd,nx,T> &p) {
    PolUnOp<Conj,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Conj,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Real,T>::T> real(const Pol<nd,nx,T> &p) {
    PolUnOp<Real,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Real,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Imag,T>::T> imag(const Pol<nd,nx,T> &p) {
    PolUnOp<Imag,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Imag,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Acos,T>::T> acos(const Pol<nd,nx,T> &p) {
    PolUnOp<Acos,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Acos,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Asin,T>::T> asin(const Pol<nd,nx,T> &p) {
    PolUnOp<Asin,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Asin,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Atan,T>::T> atan(const Pol<nd,nx,T> &p) {
    PolUnOp<Atan,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Atan,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Cos,T>::T> cos(const Pol<nd,nx,T> &p) {
    PolUnOp<Cos,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Cos,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Cosh,T>::T> cosh(const Pol<nd,nx,T> &p) {
    PolUnOp<Cosh,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Cosh,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Exp,T>::T> exp(const Pol<nd,nx,T> &p) {
    PolUnOp<Exp,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Exp,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Log,T>::T> log(const Pol<nd,nx,T> &p) {
    PolUnOp<Log,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Log,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Log10,T>::T> log10(const Pol<nd,nx,T> &p) {
    PolUnOp<Log10,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Log10,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Sin,T>::T> sin(const Pol<nd,nx,T> &p) {
    PolUnOp<Sin,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Sin,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Sinh,T>::T> sinh(const Pol<nd,nx,T> &p) {
    PolUnOp<Sinh,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Sinh,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Sqrt,T>::T> sqrt(const Pol<nd,nx,T> &p) {
    PolUnOp<Sqrt,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Sqrt,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Tan,T>::T> tan(const Pol<nd,nx,T> &p) {
    PolUnOp<Tan,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Tan,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<Tanh,T>::T> tanh(const Pol<nd,nx,T> &p) {
    PolUnOp<Tanh,nd,nx> op;
    return Pol<nd,nx,typename TypePromote<Tanh,T>::T>( op(p.coefficients()) );
}

template <int nd, int nx, class T>
typename TypePromote<Abs,T>::T abs_indication(const Pol<nd,nx,T> &P) {
    return abs(P.coefficients()[0]);
}

}
