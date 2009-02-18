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

template <int nd, int nx, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,nx,T> &P) { /// Convertit un polynome multivariables non complexe en flux de sortie
    if (Pol<nd,nx,T>::init_puissances)
        Pol<nd,nx,T>::initialize_puissances();
    os << " " << P.coefficients()[0] << " ";
    for (unsigned i=1;i<Pol<nd,nx,T>::dim;i++) {
        if (P.coefficients()[i]>T(0))
            os << "+" << P.coefficients()[i];
        if (P.coefficients()[i]<T(0))
            os << "-" << -P.coefficients()[i];
        if (P.coefficients()[i]!=T(0)) {
            for (int j=0;j<nx;j++)
                if(Pol<nd,nx,T>::puissances[i][j]>0)
                    os << "*X" << j << "^" << Pol<nd,nx,T>::puissances[i][j];
            os << " ";
            }
    }
    os << " ";
    return os;
}

template <int nd, int nx, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,nx,std::complex<T> > &P) { /// Convertit un polynome multivariables complexe en flux de sortie
    if (Pol<nd,nx,T>::init_puissances)
        Pol<nd,nx,T>::initialize_puissances();
    os << " " << P.coefficients()[0] << " ";
    for (unsigned i=1;i<Pol<nd,nx,T>::dim;i++) {
        if (P.coefficients()[i]!=std::complex<T>(0)) {
            os << "+" << P.coefficients()[i];
            for (int j=0;j<nx;j++)
                if(Pol<nd,nx,T>::puissances[i][j]>0)
                    os << "*X" << j << "^" << Pol<nd,nx,T>::puissances[i][j];
            os << " ";
        }
    }
    os << " ";
    return os;
}

template <int nd, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,1,T> &P) { /// Convertit un polynome monovariable non complexe en flux de sortie
    os << " " << P.coefficients()[0] << " ";
    for (unsigned i=1;i<Pol<nd,1,T>::dim;i++) {
        if (P.coefficients()[i]>T(0))
            os << "+" << P.coefficients()[i];
        if (P.coefficients()[i]<T(0))
            os << "-" << -P.coefficients()[i];
        if (P.coefficients()[i]!=T(0)) {
            os << "*X^" << i << " ";
            }
    }
    os << " ";
    return os;
}

template <int nd, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,1,std::complex<T> > &P) { /// Convertit un polynome monovariable complexe en flux de sortie
    os << " " << P.coefficients()[0] << " ";
    for (unsigned i=1;i<Pol<nd,1,T>::dim;i++) {
        if (P.coefficients()[i]!=std::complex<T>(0)) {
            os << "+" << P.coefficients()[i];
            os << "*X^" << i << " ";
        }
    }
    os << " ";
    return os;
}

}
