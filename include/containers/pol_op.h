#ifndef pol_op_HEADER
#define pol_op_HEADER

namespace LMT {

template <class Op, int nd, int ne, int nx>
struct PolOp;

//--------------Plus Op------------------

template <int nd, int ne, int nx>
struct PolOp<Plus,nd,ne,nx> {

    template <class T1, class T2>
    Vec<typename TypePromote<Plus,T1,T2>::T,DimPol<MIN(nd,ne),nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        if (PolTroncates<nd,MIN(nd,ne),nx>::needs_initialization)
            PolTroncates<nd,MIN(nd,ne),nx>::initialize();
        if (PolTroncates<ne,MIN(nd,ne),nx>::needs_initialization)
            PolTroncates<ne,MIN(nd,ne),nx>::initialize();
        PolTroncates<nd,MIN(nd,ne),nx> op;
        PolTroncates<ne,MIN(nd,ne),nx> oq;
        return op(p)+oq(q);
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const T2 &q) {
        Vec<typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T,DimPol<nd,nx>::valeur> res=p;
        res[0]+=q;
        return res;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T,DimPol<ne,nx>::valeur> operator() (const T1 &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        Vec<typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T,DimPol<ne,nx>::valeur> res=q;
        res[0]+=p;
        return res;
    }

};

//--------------Minus Op-----------------

template <int nd, int ne, int nx>
struct PolOp<Minus,nd,ne,nx> {

    template <class T1, class T2>
    Vec<typename TypePromote<Minus,T1,T2>::T,DimPol<MIN(nd,ne),nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        if (PolTroncates<nd,MIN(nd,ne),nx>::needs_initialization)
            PolTroncates<nd,MIN(nd,ne),nx>::initialize();
        if (PolTroncates<ne,MIN(nd,ne),nx>::needs_initialization)
            PolTroncates<ne,MIN(nd,ne),nx>::initialize();
        PolTroncates<nd,MIN(nd,ne),nx> op;
        PolTroncates<ne,MIN(nd,ne),nx> oq;
        return op(p)-oq(q);
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const T2 &q) {
        Vec<typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T,DimPol<nd,nx>::valeur> res=p;
        res[0]-=q;
        return res;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T,DimPol<ne,nx>::valeur> operator() (const T1 &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        Vec<typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T,DimPol<ne,nx>::valeur> res=-q;
        res[0]+=p;
        return res;
    }
};

}

#endif // pol_tables_HEADER
