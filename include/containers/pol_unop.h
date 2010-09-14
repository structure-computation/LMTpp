#ifndef pol_unop_HEADER
#define pol_unop_HEADER

namespace LMT {

template <class Op, int nd, int ne, int nx> struct PolBinOp;

template <class Op, int nd, int nx>
struct PolUnOp{
    template <class T>
    Vec<typename TypePromote<Op,T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) { assert(0); }
};

template <int nd, int nx>
struct PolUnOp<Sqrt,nd,nx> {
    template <class T>
    Vec<typename TypePromote<Sqrt,T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) {
        typedef typename TypePromote<Sqrt,T>::T TC;
        if (PolMultiplies<nd,nd,nx>::needs_initialization)
            PolMultiplies<nd,nd,nx>::initialize();
        Vec<TC,DimPol<nd,nx>::valeur> res;
        res[0]=sqrt(p[0]);
        for (int i=1;i<DimPol<nd,nx>::valeur;i++) {
            res[i]=p[i];
            for (int j=1;j<PolMultiplies<nd,nd,nx>::table0[i].size()-1;j++)
                res[i]-=res[PolMultiplies<nd,nd,nx>::table0[i][j]]*res[PolMultiplies<nd,nd,nx>::table1[i][j]];
            res[i]/=TC(2)*res[0];
        }
        return res;
    }
};

template <int nd, int nx>
struct PolUnOp<Exp,nd,nx> {
    template <class T>
    Vec<typename TypePromote<Exp,T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) {
        typedef typename TypePromote<Exp,T>::T TC;
        PolBinOp<Multiplies,nd,nd,nx> opmul;
        Vec<TC,DimPol<nd,nx>::valeur> res(TC(0));
        Vec<TC,DimPol<nd,nx>::valeur> puissance(TC(0));
        TC factorielle = TC(1);
        res[0]=TC(1);
        puissance[0]=TC(1);
        Vec<TC,DimPol<nd,nx>::valeur> element_somme = res;
        for (int i=1;max(abs(element_somme))>DimPol<nd,nx>::valeur*std::numeric_limits<TC>::epsilon();i++) {
            factorielle *= TC(i);
            puissance = opmul(puissance,p);
            element_somme = puissance/factorielle;
            res+=element_somme;
        }
        return res;
    }
};


template <int nd, int nx>
struct PolUnOp<Log,nd,nx> {
    template <class T>
    Vec<typename TypePromote<Log,T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) {
        typedef typename TypePromote<Log,T>::T TC;
        PolBinOp<Multiplies,nd,nd,nx> opmultiplies;
        PolBinOp<Divides,nd,nd,nx> opdivides;
        Vec<TC,DimPol<nd,nx>::valeur> numerateur = p;
        numerateur[0]--;
        Vec<TC,DimPol<nd,nx>::valeur> denominateur = p;
        denominateur[0]++;
        Vec<TC,DimPol<nd,nx>::valeur> fraction = opdivides(numerateur,denominateur);
        Vec<TC,DimPol<nd,nx>::valeur> puissance = fraction;
        Vec<TC,DimPol<nd,nx>::valeur> fraction_carre = opmultiplies(fraction,fraction);
        Vec<TC,DimPol<nd,nx>::valeur> res = puissance;
        Vec<TC,DimPol<nd,nx>::valeur> element_somme = res;
        for (int i=1;max(abs(element_somme))>DimPol<nd,nx>::valeur*std::numeric_limits<TC>::epsilon();i++) {
            puissance = opmultiplies(puissance,fraction_carre);
            element_somme = puissance/TC(2*i+1);
            res+=element_somme;
        }
        return TC(2)*res;
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
