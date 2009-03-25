namespace LMT {

template <int nd, int nx, class T>
std::istream &operator>>(std::istream &is, Pol<nd,nx,T> &P) { /// Definit un polynome grace à operator>>
    Vec<T> coefs;
    is >> coefs;
    P=Pol<nd,nx,T>(coefs);
    return is;
}

template <int nd, int nx, class T>
std::istream &line_input(std::istream &is, Pol<nd,nx,T> &P) { /// Definit un polynome grace à line_input
    Vec<T> coefs;
    line_input ( is, coefs);
    P=Pol<nd,nx,T>(coefs);
    return is;
}

template <int nd, int nx>
std::ostream &power_stream(std::ostream &os, Relative_Number<nd> nd_, Relative_Number<nx> nx_, unsigned i ) {
    for (int j=0;j<nx;j++)
        if(PolPowers<nd,nx>::table[i][j]>0)
            os << "*X" << j << "^" << PolPowers<nd,nx>::table[i][j];
    os << " ";
    return os;
}

template <int nd>
std::ostream &power_stream(std::ostream &os, Relative_Number<nd> nd_, Relative_Number<1> nx_, unsigned i ) {
    os << "*X^" << i << " ";
    return os;
}

template <int nd, int nx, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,nx,T> &P) { /// Convertit un polynome non complexe en flux de sortie
    if (PolPowers<nd,nx>::needs_initialization)
        PolPowers<nd,nx>::initialize();
    os << " " << P.coefficients()[0] << " ";
    for (unsigned i=1;i<Pol<nd,nx,T>::dim;i++) {
        if (P.coefficients()[i]>T(0))
            os << "+" << P.coefficients()[i];
        if (P.coefficients()[i]<T(0))
            os << "-" << -P.coefficients()[i];
        if (P.coefficients()[i]!=T(0))
            power_stream(os,Relative_Number<nd>(),Relative_Number<nx>(),i);
    }
    os << " ";
    return os;
}

template <int nd, int nx, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,nx,std::complex<T> > &P) { /// Convertit un polynome multivariables complexe en flux de sortie
    if (PolPowers<nd,nx>::needs_initialization)
        PolPowers<nd,nx>::initialize();
    os << " " << P.coefficients()[0] << " ";
    for (unsigned i=1;i<Pol<nd,nx,T>::dim;i++) {
        if (P.coefficients()[i]!=std::complex<T>(0)) {
            os << "+" << P.coefficients()[i];
            power_stream(os,Relative_Number<nd>(),Relative_Number<nx>(),i);
        }
    }
    os << " ";
    return os;
}

}
