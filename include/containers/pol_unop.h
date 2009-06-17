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
        assert(0);
        typedef typename TypePromote<Sqrt,T>::T TT;
        Vec<TT,DimPol<nd,nx>::valeur> res(TT(0));
        return res;
    }
};

template <int nd, int nx>
struct PolUnOp<Abs,nd,nx> {
    template <class T>
    Vec<typename TypePromote<Abs,T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) { return abs(p); }
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
