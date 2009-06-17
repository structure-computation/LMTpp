#ifndef pol_op_HEADER
#define pol_op_HEADER

namespace LMT {

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

//--------------Multiplication Op---------------------

template <int nd, int ne, int nx>
struct PolOp<Multiplies,nd,ne,nx> {

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<MIN(nd,ne),nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        if (PolMultiplies<nd,ne,nx>::needs_initialization)
            PolMultiplies<nd,ne,nx>::initialize();
        Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<nd,nx>::valeur> res( typename TypePromote<Multiplies,T1,T2>::T(0) );
        for (int i=0;i<DimPol<MIN(nd,ne),nx>::valeur;i++)
            for (int j=0;j<PolMultiplies<nd,ne,nx>::table0[i].size();j++)
                res[i]+=p[PolMultiplies<nd,ne,nx>::table0[i][j]]*q[PolMultiplies<nd,ne,nx>::table1[i][j]];
        return res;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const T2 &q) {
        return p*q;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T,DimPol<ne,nx>::valeur> operator() (const T1 &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        return p*q;
    }

};

template <int nd, int ne>
struct PolOp<Multiplies,nd,ne,1> {

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<MIN(nd,ne),1>::valeur> operator() (const Vec<T1,DimPol<nd,1>::valeur> &p, const Vec<T2,DimPol<ne,1>::valeur> &q) {
        Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<MIN(nd,ne),1>::valeur> res( typename TypePromote<Multiplies,T1,T2>::T(0) );
        for (int i=0;i<DimPol<MIN(nd,ne),1>::valeur;i++)
            for (int j=0;j<=i;j++)
                res[i]+=p[i-j]*q[j];
        return res;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T,DimPol<nd,1>::valeur> operator() (const Vec<T1,DimPol<nd,1>::valeur> &p, const T2 &q) {
        return p*q;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T,DimPol<ne,1>::valeur> operator() (const T1 &p, const Vec<T2,DimPol<ne,1>::valeur> &q) {
        return p*q;
    }

};

//--------------Division Op----------------------

template <int nd, int ne, int nx>
struct PolOp<Divides,nd,ne,nx> {

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,T2>::T,DimPol<MIN(nd,ne),nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        if (PolMultiplies<ne,ne,nx>::needs_initialization)
            PolMultiplies<ne,ne,nx>::initialize();
        Vec<T2,DimPol<ne,nx>::valeur> invq(T2(0));
        invq[0]=T2(1)/q[0];
        for (int i=1;i<DimPol<ne,nx>::valeur;i++) {
            for (int j=0;j<PolMultiplies<ne,ne,nx>::table0[i].size()-1;j++)
                invq[i]-=q[PolMultiplies<ne,ne,nx>::table0[i][j]]*invq[PolMultiplies<ne,ne,nx>::table1[i][j]];
            invq[i]/=q[0];
        }
        PolOp<Multiplies,nd,ne,nx> op;
        return op(p,invq);
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const T2 &q) { return p/q; }

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T,DimPol<ne,nx>::valeur> operator() (const T1 &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        Vec<T1,DimPol<ne,nx>::valeur> vecp(T1(0));
        vecp[0]=p;
        return operator()(vecp,q);
    }

};

template <int nd, int ne>
struct PolOp<Divides,nd,ne,1> {

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,T2>::T,DimPol<MIN(nd,ne),1>::valeur> operator() (const Vec<T1,DimPol<nd,1>::valeur> &p, const Vec<T2,DimPol<ne,1>::valeur> &q) {
        Vec<T1,DimPol<ne,1>::valeur> invq(T1(0));
        invq[0]=T1(1)/q[0];
        for (int i=1;i<DimPol<ne,1>::valeur;i++) {
            for (int j=0;j<i;j++)
                invq[i]-=q[i-j]*invq[j];
            invq[i]/=q[0];
        }
        PolOp<Multiplies,nd,ne,1> op;
        return op(p,invq);
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T,DimPol<nd,1>::valeur> operator() (const Vec<T1,DimPol<nd,1>::valeur> &p, const T2 &q) { return p/q; }

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T,DimPol<ne,1>::valeur> operator() (const T1 &p, const Vec<T2,DimPol<ne,1>::valeur> &q) {
        Vec<T1,DimPol<ne,1>::valeur> vecp(T1(0));
        vecp[0]=p;
        return operator()(vecp,q);
    }
};

}

#endif // pol_tables_HEADER
