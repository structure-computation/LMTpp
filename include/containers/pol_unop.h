#ifndef pol_unop_HEADER
#define pol_unop_HEADER

namespace LMT {

template <class Op, int nd, int nx>
struct PolUnOp{
    template <class T>
    Vec<typename TypePromote<Sqrt,T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) { assert(0); }
};

template <int nd, int nx>
struct PolUnOp<Sqrt,nd,nx> {
    template <class T>
    Vec<typename TypePromote<Sqrt,T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) {
        if (PolMultiplies<nd,nd,nx>::needs_initialization)
            PolMultiplies<nd,nd,nx>::initialize();
        Vec<typename TypePromote<Sqrt,T>::T,DimPol<nd,nx>::valeur> res;
        res[0]=sqrt(p[0]);
        for (int i=1;i<DimPol<nd,nx>::valeur;i++) {
            res[i]=p[i];
            for (int j=1;j<PolMultiplies<nd,nd,nx>::table0[i].size()-1;j++)
                res[i]-=res[PolMultiplies<nd,nd,nx>::table0[i][j]]*res[PolMultiplies<nd,nd,nx>::table1[i][j]];
            res[i]/=typename TypePromote<Sqrt,T>::T(2)*res[0];
        }
        return res;
    }
};

template <int nd, int nx>
struct PolUnOp<Abs,nd,nx> {
    template <class T>
    typename TypePromote<Abs,T>::T operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) { return abs(p[0]); }
};

template <int nd, int nx>
struct PolUnOp<Conj,nd,nx> {
    template <class T>
    Vec<typename TypePromote<Conj,T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) { return conj(p); }
};

template <int nd, int nx>
struct PolUnOp<Real,nd,nx> {
    template <class T>
    Vec<typename TypePromote<Real,T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) { return real(p); }
};

template <int nd, int nx>
struct PolUnOp<Imag,nd,nx> {
    template <class T>
    Vec<typename TypePromote<Imag,T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) { return imag(p); }
};


}

#endif // pol_tables_HEADER
