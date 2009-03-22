#ifndef pol_tables_HEADER
#define pol_tables_HEADER

#include "pol_dimension.h"
#include "vec_if_static_size_is_one_and_scalar_if_not.h"

namespace LMT {

template <int nx, class TT>
struct ScalarTypeIfOne {typedef Vec<TT,nx> T;};
template <class TT>
struct ScalarTypeIfOne<1,TT> {typedef TT T;};

//--------------Powers table-------------

template <int nd, int nx>
struct PolPowers {

    static bool needs_initialization;
    static Vec<Vec<unsigned,nx>,DimPol<nd,nx>::valeur> table;

    static void initialize() {
        needs_initialization=0;
        table[0].set(0);
        for (int i=1;i<DimPol<nd,nx>::valeur;i++)
            table[i]=PolPowers<nd,nx>::next_power(table[i-1]);
    }

    template <int nx_> static Vec<unsigned,nx_> next_power(const Vec<unsigned,nx_> &v) {
        Vec<unsigned,nx_> res=v;
        unsigned tmp=res[0];
        for (unsigned i=1;i<nx_;i++)
            tmp+=res[i];
        if (tmp<nd) {
            res[0]++;
        }
        else {
            Vec<unsigned,nx_-1> tmp=res[range(1,nx_)];
            res[range(1,nx_)]=next_power(tmp);
            res[0]=0;
        }
        return res;
    }

    static Vec<unsigned,1> next_power(const Vec<unsigned,1> &v) {
        Vec<unsigned,1> res=v;
        res[0]++;
        return res;
    }

    const Vec<Vec<unsigned,nx>,DimPol<nd,nx>::valeur> &operator()() const { return table; }
    unsigned operator() (unsigned i, unsigned j) const { return table[i][j]; }
    template <class T1, class T2>
    typename TypePromote<Multiplies,T1,T2>::T operator() (const T1 init, const Vec<T2,nx> &x, unsigned i) const {
        typename TypePromote<Multiplies,T1,T2>::T res=init;
        for (int k=0;k<nx;k++)
            res*=pow(x[k],int(table[i][k]));
        return res;
    }

    template <class T1, class T2>
    typename TypePromote<Multiplies,T1,T2>::T operator() (const Vec<T1,DimPol<nd,nx>::valeur> &coefs, const Vec<T2,nx> &x) const {
        typename TypePromote<Multiplies,T1,T2>::T res=coefs[0];
        for (unsigned i=1;i<DimPol<nd,nx>::valeur;i++) 
            res+=operator()(coefs[i],x,i);
        return res;
    }
};

template <int nd, int nx>
bool PolPowers<nd,nx>::needs_initialization = 1;

template <int nd, int nx>
Vec<Vec<unsigned,nx>,DimPol<nd,nx>::valeur> PolPowers<nd,nx>::table;

template <int nd>
struct PolPowers<nd,1> {

    static const bool needs_initialization=0;
    static void initialize() {}

    Vec<unsigned,DimPol<nd,1>::valeur> operator()() const { return range(0,nd+1); }
    unsigned operator() (unsigned i, unsigned j) const { return i; }
    template <class T1, class T2>
    typename TypePromote<Multiplies,T1,T2>::T operator() (const Vec<T1,DimPol<nd,1>::valeur> &coefs, const T2 &x) const {
        typename TypePromote<Multiplies,T1,T2>::T res;
        res=coefs[0];
        for (unsigned k=1;k<DimPol<nd,1>::valeur;k++)
            res += coefs[k] * ::pow(x,k);
        return res;
    }
    template <class T1, class T2>
    typename TypePromote<Multiplies,T1,T2>::T operator() (const Vec<T1,DimPol<nd,1>::valeur> &coefs, const Vec<T2,1> &x) const { return operator()(coefs,x[0]); }
};

//--------------Troncature table------------------

template <int nd, int ne, int nx>
struct PolTroncates {

    static bool needs_initialization;
    static Vec<unsigned,DimPol<ne,nx>::valeur> table;

    static void initialize() {
        if (PolPowers<nd,nx>::needs_initialization)
            PolPowers<nd,nx>::initialize();
        if (PolPowers<ne,nx>::needs_initialization)
            PolPowers<ne,nx>::initialize();
        needs_initialization=0;
        for (unsigned i=0;i<DimPol<ne,nx>::valeur;i++)
            for (int j=0;j<DimPol<nd,nx>::valeur;j++)
                if (PolPowers<ne,nx>::table[i]==PolPowers<nd,nx>::table[j]) {
                    table[i]=j;
                    break;
                }
    }

    template <class T>
    Vec<T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<ne,nx>::valeur> &p) {
        if (needs_initialization)
            initialize();
        Vec<T,DimPol<nd,nx>::valeur> res(T(0));
        for (unsigned i=0;i<DimPol<ne,nx>::valeur;i++)
            res[table[i]] = p[i];
        return res;
    }

    template <class T>
    Vec<T,DimPol<ne,nx>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) {
        if (needs_initialization)
            initialize();
        Vec<T,DimPol<ne,nx>::valeur> res;
        for (unsigned i=0;i<DimPol<ne,nx>::valeur;i++)
            res[i] = p[table[i]];
        return res;
    }
};

template <int nd, int ne, int nx>
bool PolTroncates<nd,ne,nx>::needs_initialization = 1;

template <int nd, int ne, int nx>
Vec<unsigned,DimPol<ne,nx>::valeur> PolTroncates<nd,ne,nx>::table;

template <int nd, int ne>
struct PolTroncates<nd,ne,1> {
    static const bool needs_initialization = 0;
    static void initialize() {}
    template <class T>
    Vec<T,DimPol<nd,1>::valeur> operator() (const Vec<T,DimPol<ne,1>::valeur> &p) {
        Vec<T,DimPol<nd,1>::valeur> res;
        for(unsigned i=0;i<DimPol<ne,1>::valeur;++i)
            res[i] = p[i];
        for(unsigned i=DimPol<ne,1>::valeur;i<DimPol<nd,1>::valeur;++i)
            res[i] = T(0);
        return res;
    }
    template <class T>
    Vec<T,DimPol<ne,1>::valeur> operator() (const Vec<T,DimPol<nd,1>::valeur> &p) {
        Vec<T,DimPol<ne,1>::valeur> res;
        for(unsigned i=0;i<DimPol<ne,1>::valeur;++i)
            res[i] = p[i];
        return res;
    }
};

template <int nd,int nx>
struct PolTroncates<nd,nd,nx> {
    static const bool needs_initialization = 0;
    static void initialize() {}
    template <class T>
    const Vec<T,DimPol<nd,nx>::valeur> &operator() (const Vec<T,DimPol<nd,nx>::valeur> &p) { return p; }
};

template <int nd>
struct PolTroncates<nd,nd,1> {
    static const bool needs_initialization = 0;
    static void initialize() {}
    template <class T>
    const Vec<T,DimPol<nd,1>::valeur> &operator() (const Vec<T,DimPol<nd,1>::valeur> &p) { return p; }
};

//--------------Derivative table-------------------

template <int nd, int nx>
struct PolDerivative {

    static bool needs_initialization;
    static Vec<Vec<unsigned,DimPol<(nd>0?nd-1:nd),nx>::valeur>,nx> table;

    static void initialize() {
        if (PolPowers<nd,nx>::needs_initialization)
            PolPowers<nd,nx>::initialize();
        if (PolPowers<(nd>0?nd-1:nd),nx>::needs_initialization)
            PolPowers<(nd>0?nd-1:nd),nx>::initialize();
        needs_initialization=0;
        for (unsigned i=0;i<nx;i++)
            for (int j=0;j<DimPol<(nd>0?nd-1:nd),nx>::valeur;j++) {
                Vec<unsigned,nx> puissance_input=PolPowers<(nd>0?nd-1:nd),nx>::table[j];
                puissance_input[i]++;
                for (int k=0;k<DimPol<nd,nx>::valeur;k++)
                    if (puissance_input==PolPowers<nd,nx>::table[k]) {
                        table[i][j]=k;
                        break;
                }
            }
    }

    template <class T> Vec<Vec<T,DimPol<(nd>0?nd-1:nd),nx>::valeur>,nx> operator() (const Vec<T,DimPol<nd,nx>::valeur> &coefs) {
        Vec<Vec<T,DimPol<(nd>0?nd-1:nd),nx>::valeur>,nx> res;
        for (int i=0;i<nx;i++)
            for (int j=0;j<DimPol<(nd>0?nd-1:nd),nx>::valeur;j++)
                res[i][j]=coefs[table[i][j]]*PolPowers<nd,nx>::table[table[i][j]][i];
        return res;
    }
};

template <int nd, int nx>
bool PolDerivative<nd,nx>::needs_initialization = 1;

template <int nd, int nx>
Vec<Vec<unsigned,DimPol<(nd>0?nd-1:nd),nx>::valeur>,nx> PolDerivative<nd,nx>::table;

template <int nd>
struct PolDerivative<nd,1> {
    static const bool needs_initialization = 0;
    static void initialize() {}
    template <class T>
    Vec<T,DimPol<(nd>0?nd-1:nd),1>::valeur> operator() (const Vec<T,DimPol<nd,1>::valeur> &coefs) {
        Vec<T,DimPol<(nd>0?nd-1:nd),1>::valeur> res;
        for (unsigned j=0;j<DimPol<(nd>0?nd-1:nd),1>::valeur;j++)
            res[j]=coefs[j+1]*(j+1);
        return res;
    }
};

template <>
struct PolDerivative<0,1> {
    static const bool needs_initialization = 0;
    static void initialize() {}
    template <class T> Vec<T,1> operator() (const Vec<T,1> &coefs) { return Vec<T,1>(T(0)); }
};

//--------------Plus table------------------

template <int nd, int ne, int nx>
struct PolPlus {

    static bool needs_initialization;
    static void initialize() {
        if (PolTroncates<nd,MIN(nd,ne),nx>::needs_initialization)
            PolTroncates<nd,MIN(nd,ne),nx>::initialize();
        if (PolTroncates<ne,MIN(nd,ne),nx>::needs_initialization)
            PolTroncates<ne,MIN(nd,ne),nx>::initialize();
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Plus,T1,T2>::T,DimPol<MIN(nd,ne),nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
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

template <int nd, int ne, int nx>
bool PolPlus<nd,ne,nx>::needs_initialization = 1;

//--------------Minus table-----------------

template <int nd, int ne, int nx>
struct PolMinus {

    static bool needs_initialization;
    static void initialize() {
        if (PolTroncates<nd,MIN(nd,ne),nx>::needs_initialization)
            PolTroncates<nd,MIN(nd,ne),nx>::initialize();
        if (PolTroncates<ne,MIN(nd,ne),nx>::needs_initialization)
            PolTroncates<ne,MIN(nd,ne),nx>::initialize();
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Minus,T1,T2>::T,DimPol<MIN(nd,ne),nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
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

template <int nd, int ne, int nx>
bool PolMinus<nd,ne,nx>::needs_initialization = 1;

//--------------Multiplication table---------------------

template <int nd, int ne, int nx>
struct PolMultiplies {

    static bool needs_initialization;
    static Vec<Vec<unsigned>,DimPol<MIN(nd,ne),nx>::valeur> table0;
    static Vec<Vec<unsigned>,DimPol<MIN(nd,ne),nx>::valeur> table1;

    static void initialize() {
        if (PolPowers<nd,nx>::needs_initialization)
            PolPowers<nd,nx>::initialize();
        if (PolPowers<ne,nx>::needs_initialization)
            PolPowers<ne,nx>::initialize();
        needs_initialization=0;
        for (unsigned i=0;i<DimPol<MIN(nd,ne),nx>::valeur;i++)
            for (unsigned j=0;j<DimPol<ne,nx>::valeur;j++)
                if (min(PolPowers<ne,nx>::table[j]<=PolPowers<MIN(nd,ne),nx>::table[i]))
                    for (unsigned k=0;k<DimPol<nd,nx>::valeur;k++)
                        if (PolPowers<ne,nx>::table[j]+PolPowers<nd,nx>::table[k]==PolPowers<MIN(nd,ne),nx>::table[i]) {
                            table0[i].push_back(k);
                            table1[i].push_back(j);
                            break;
                        }
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<MIN(nd,ne),nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<nd,nx>::valeur> res( typename TypePromote<Multiplies,T1,T2>::T(0) );
        for (int i=0;i<DimPol<MIN(nd,ne),nx>::valeur;i++)
            for (int j=0;j<table0[i].size();j++)
                res[i]+=p[table0[i][j]]*q[table1[i][j]];
        return res;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const T2 &q) { return p*q; }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T,DimPol<ne,nx>::valeur> operator() (const T1 &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) { return p*q; }

};

template <int nd, int ne, int nx>
bool PolMultiplies<nd,ne,nx>::needs_initialization = 1;

template <int nd, int ne, int nx>
Vec<Vec<unsigned>,DimPol<MIN(nd,ne),nx>::valeur> PolMultiplies<nd,ne,nx>::table0;

template <int nd, int ne, int nx>
Vec<Vec<unsigned>,DimPol<MIN(nd,ne),nx>::valeur> PolMultiplies<nd,ne,nx>::table1;

template <int nd, int ne>
struct PolMultiplies<nd,ne,1> {

    static const bool needs_initialization = 0;
    static void initialize() {}

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<MIN(nd,ne),1>::valeur> operator() (const Vec<T1,DimPol<nd,1>::valeur> &p, const Vec<T2,DimPol<ne,1>::valeur> &q) {
        Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<MIN(nd,ne),1>::valeur> res( typename TypePromote<Multiplies,T1,T2>::T(0) );
        for (int i=0;i<DimPol<MIN(nd,ne),1>::valeur;i++)
            for (int j=0;j<=i;j++)
                res[i]+=p[i-j]*q[j];
        return res;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T,DimPol<nd,1>::valeur> operator() (const Vec<T1,DimPol<nd,1>::valeur> &p, const T2 &q) { return p*q; }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T,DimPol<ne,1>::valeur> operator() (const T1 &p, const Vec<T2,DimPol<ne,1>::valeur> &q) { return p*q; }
};

//--------------Division table----------------------

template <int nd, int ne, int nx>
struct PolDivides {

    static bool needs_initialization;
    static void initialize() {
        if (PolMultiplies<ne,ne,nx>::needs_initialization)
            PolMultiplies<ne,ne,nx>::initialize();
    }

    template <class T>
    Vec<T,DimPol<ne,nx>::valeur> operator() (const Vec<T,DimPol<ne,nx>::valeur> &p) {
        Vec<T,DimPol<ne,nx>::valeur> res(T(0));
        res[0]=T(1)/p[0];
        for (int i=1;i<DimPol<ne,nx>::valeur;i++) {
            for (int j=0;j<PolMultiplies<ne,ne,nx>::table0[i].size()-1;j++)
                res[i]-=p[PolMultiplies<ne,ne,nx>::table0[i][j]]*res[PolMultiplies<ne,ne,nx>::table1[i][j]];
            res[i]/=p[0];
        }
        return res;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,T2>::T,DimPol<MIN(nd,ne),nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        if (PolMultiplies<nd,ne,nx>::needs_initialization)
            PolMultiplies<nd,ne,nx>::initialize();
        PolMultiplies<nd,ne,nx> op;
        return op(p,operator()(q));
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T,DimPol<nd,nx>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &p, const T2 &q) { return p/q; }

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T,DimPol<ne,nx>::valeur> operator() (const T1 &p, const Vec<T2,DimPol<ne,nx>::valeur> &q) {
        if (needs_initialization)
            initialize();
        PolMultiplies<nd,ne,nx> op;
        return op(p,operator()(q));
    }

};

template <int nd, int ne, int nx>
bool PolDivides<nd,ne,nx>::needs_initialization = 1;

template <int nd, int ne>
struct PolDivides<nd,ne,1> {

    static const bool needs_initialization = 0;
    static void initialize() {}

    template <class T>
    Vec<T,DimPol<ne,1>::valeur> operator() (const Vec<T,DimPol<ne,1>::valeur> &p) {
        Vec<T,DimPol<ne,1>::valeur> res(T(0));
        res[0]=T(1)/p[0];
        for (int i=1;i<DimPol<ne,1>::valeur;i++) {
            for (int j=0;j<i;j++)
                res[i]-=p[i-j]*res[j];
            res[i]/=p[0];
        }
        return res;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,T2>::T,DimPol<MIN(nd,ne),1>::valeur> operator() (const Vec<T1,DimPol<nd,1>::valeur> &p, const Vec<T2,DimPol<ne,1>::valeur> &q) {
        PolDivides<nd,ne,1> op;
        return op(p,operator()(q));
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T,DimPol<nd,1>::valeur> operator() (const Vec<T1,DimPol<nd,1>::valeur> &p, const T2 &q) { return p/q; }

    template <class T1, class T2>
    Vec<typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T,DimPol<ne,1>::valeur> operator() (const T1 &p, const Vec<T2,DimPol<ne,1>::valeur> &q) {
        if (needs_initialization)
            initialize();
        return (operator()(Vec<T1,DimPol<nd,1>::valeur>(p),q));
    }
};

//--------------Restriction tables---------------------------------------

template <int nd, int nx, int ny>
struct PolRestriction {

    static Vec<bool,Deux_Puissance<nx>::valeur> needs_initialization;
    static Vec<Vec<unsigned,DimPol<nd,ny>::valeur>,Deux_Puissance<nx>::valeur> table;

    static unsigned get_index (const Vec<unsigned,ny> &vq) {
        unsigned res=0;
        for (unsigned i=0;i<ny;i++) {
            unsigned tmp=1;
            for (unsigned j=0;j<vq[i];j++)
                tmp*=2;
            res+=tmp;
        }
        return res;
    }

    static void initialize (const Vec<unsigned,ny> &vq, unsigned index) {
        if (PolPowers<nd,nx>::needs_initialization)
            PolPowers<nd,nx>::initialize();
        if (PolPowers<nd,ny>::needs_initialization)
            PolPowers<nd,ny>::initialize();
        needs_initialization[index]=0;
        for (unsigned i=0;i<DimPol<nd,ny>::valeur;i++)
            for (unsigned j=0;j<DimPol<nd,nx>::valeur;j++)
                if (PolPowers<nd,ny>::table[i]==PolPowers<nd,nx>::table[j][vq]) {
                    table[index][i]=j;
                    break;
                }
    }

    template <class T>
    Vec<T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,ny>::valeur> &p, unsigned index) {
        Vec<T,DimPol<nd,nx>::valeur> res(T(0));
        for (unsigned i=0;i<DimPol<nd,ny>::valeur;i++)
            res[table[index][i]] = p[i];
        return res;
    }

    template <class T>
    Vec<T,DimPol<nd,ny>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p, unsigned index) {
        Vec<T,DimPol<nd,ny>::valeur> res;
        for (unsigned i=0;i<DimPol<nd,ny>::valeur;i++)
            res[i] = p[table[index][i]];
        return res;
    }

};

template <int nd, int nx, int ny>
Vec<bool,Deux_Puissance<nx>::valeur> PolRestriction<nd,nx,ny>::needs_initialization = 1;

template <int nd, int nx, int ny>
Vec<Vec<unsigned,DimPol<nd,ny>::valeur>,Deux_Puissance<nx>::valeur> PolRestriction<nd,nx,ny>::table;

template <int nd, int nx>
struct PolRestriction<nd,nx,1> {

    static Vec<bool,Deux_Puissance<nx>::valeur> needs_initialization;
    static Vec<Vec<unsigned,DimPol<nd,1>::valeur>,Deux_Puissance<nx>::valeur> table;

    static unsigned get_index (const Vec<unsigned,1> &vq) {
        unsigned res=1;
        for (unsigned j=0;j<vq[0];j++)
            res*=2;
        return res;
    }

    static void initialize (const Vec<unsigned,1> &vq, unsigned index) {
        if (PolPowers<nd,nx>::needs_initialization)
            PolPowers<nd,nx>::initialize();
        needs_initialization[index]=0;
        for (unsigned i=0;i<DimPol<nd,1>::valeur;i++)
            for (unsigned j=0;j<DimPol<nd,nx>::valeur;j++)
                if (i==PolPowers<nd,nx>::table[j][vq][0]) {
                    table[index][i]=j;
                    break;
                }
    }

    template <class T>
    Vec<T,DimPol<nd,nx>::valeur> operator() (const Vec<T,DimPol<nd,1>::valeur> &p, unsigned index) {
        Vec<T,DimPol<nd,nx>::valeur> res(T(0));
        for (unsigned i=0;i<DimPol<nd,1>::valeur;i++)
            res[table[index][i]] = p[i];
        return res;
    }

    template <class T>
    Vec<T,DimPol<nd,1>::valeur> operator() (const Vec<T,DimPol<nd,nx>::valeur> &p, unsigned index) {
        Vec<T,DimPol<nd,1>::valeur> res;
        for (unsigned i=0;i<DimPol<nd,1>::valeur;i++)
            res[i] = p[table[index][i]];
        return res;
    }

};


template <int nd, int nx>
Vec<bool,Deux_Puissance<nx>::valeur> PolRestriction<nd,nx,1>::needs_initialization = 1;

template <int nd, int nx>
Vec<Vec<unsigned,DimPol<nd,1>::valeur>,Deux_Puissance<nx>::valeur> PolRestriction<nd,nx,1>::table;

//--------------PartialEvaluation tables---------------------------------------

template <int nd, int nx, int ny>
struct PolPartialEvaluates {

    static Vec<bool,Deux_Puissance<nx>::valeur> needs_initialization;
    static Vec<Vec<unsigned,DimPol<nd,nx>::valeur>,Deux_Puissance<nx>::valeur> table;

    static unsigned get_index (const Vec<unsigned,ny> &vq) {
        unsigned res=0;
        for (unsigned i=0;i<ny;i++) {
            unsigned tmp=1;
            for (unsigned j=0;j<vq[i];j++)
                tmp*=2;
            res+=tmp;
        }
        return res;
    }

    static void initialize (const Vec<unsigned,ny> &vq, unsigned index) {
        if (PolPowers<nd,nx>::needs_initialization)
            PolPowers<nd,nx>::initialize();
        if (PolPowers<nd,ny>::needs_initialization)
            PolPowers<nd,ny>::initialize();
        needs_initialization[index]=0;
        for (unsigned i=0;i<DimPol<nd,nx>::valeur;i++)
            for (unsigned j=0;j<DimPol<nd,ny>::valeur;j++)
                if (PolPowers<nd,nx>::table[i][vq]==PolPowers<nd,ny>::table[j]) {
                    table[index][i]=j;
                    break;
                }
    }

    template <class T1, class T2>
    typename TypePromote<Multiplies,T1,T2>::T operator() (const T1 init, const Vec<T2,nx-ny> &x, unsigned i, const Vec<unsigned> &vi) const {
        typename TypePromote<Multiplies,T1,T2>::T res=init;
        for (int k=0;k<nx-ny;k++)
            res*=pow(x[k],unsigned(PolPowers<nd,nx>::table[i][vi[k]]));
        return res;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<nd,ny>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &coefs, const Vec<T2,nx-ny> &x, const Vec<unsigned,ny> &vq, unsigned index) const {
        Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<nd,ny>::valeur> res( typename TypePromote<Multiplies,T1,T2>::T(0) );
        Vec<unsigned> vi=range(0,nx);
        for (int i=ny-1;i>=0;i--)
            vi.erase_elem_nb(vq[i]);
        for (unsigned i=0;i<DimPol<nd,nx>::valeur;i++)
            res[table[index][i]]+=operator()(coefs[i],x,i,vi);
        return res;
    }

};

template <int nd, int nx, int ny>
Vec<bool,Deux_Puissance<nx>::valeur> PolPartialEvaluates<nd,nx,ny>::needs_initialization = 1;

template <int nd, int nx, int ny>
Vec<Vec<unsigned,DimPol<nd,nx>::valeur>,Deux_Puissance<nx>::valeur> PolPartialEvaluates<nd,nx,ny>::table;

template <int nd, int nx>
struct PolPartialEvaluates<nd,nx,1> {

    static Vec<bool,Deux_Puissance<nx>::valeur> needs_initialization;
    static Vec<Vec<unsigned,DimPol<nd,nx>::valeur>,Deux_Puissance<nx>::valeur> table;

    static unsigned get_index (const Vec<unsigned,1> &vq) {
        unsigned res=1;
        for (unsigned j=0;j<vq[0];j++)
            res*=2;
        return res;
    }

    static void initialize (const Vec<unsigned,1> &vq, unsigned index) {
        if (PolPowers<nd,nx>::needs_initialization)
            PolPowers<nd,nx>::initialize();
        needs_initialization[index]=0;
        for (unsigned i=0;i<DimPol<nd,nx>::valeur;i++)
            for (unsigned j=0;j<DimPol<nd,1>::valeur;j++)
                if (PolPowers<nd,nx>::table[i][vq]==j) {
                    table[index][i]=j;
                    break;
                }
    }

    template <class T1, class T2>
    typename TypePromote<Multiplies,T1,T2>::T operator() (const T1 init, const Vec<T2,nx-1> &x, unsigned i, const Vec<unsigned> &vi) const {
        typename TypePromote<Multiplies,T1,T2>::T res=init;
        for (int k=0;k<nx-1;k++)
            res*=pow(x[k],unsigned(PolPowers<nd,nx>::table[i][vi[k]]));
        return res;
    }

    template <class T1, class T2>
    Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<nd,1>::valeur> operator() (const Vec<T1,DimPol<nd,nx>::valeur> &coefs, const Vec<T2,nx-1> &x, const Vec<unsigned,1> &vq, unsigned index) const {
        Vec<typename TypePromote<Multiplies,T1,T2>::T,DimPol<nd,1>::valeur> res( typename TypePromote<Multiplies,T1,T2>::T(0) );
        Vec<unsigned> vi=range(0,nx);
        vi.erase_elem_nb(vq[0]);
        for (unsigned i=0;i<DimPol<nd,nx>::valeur;i++)
            res[table[index][i]]+=operator()(coefs[i],x,i,vi);
        return res;
    }

};

template <int nd, int nx>
Vec<bool,Deux_Puissance<nx>::valeur> PolPartialEvaluates<nd,nx,1>::needs_initialization = 1;

template <int nd, int nx>
Vec<Vec<unsigned,DimPol<nd,nx>::valeur>,Deux_Puissance<nx>::valeur> PolPartialEvaluates<nd,nx,1>::table;

}

#endif // pol_tables_HEADER
