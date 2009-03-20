#ifndef pol_tables_HEADER
#define pol_tables_HEADER

#include "pol_dimension.h"

namespace LMT {

template <int nx, class TT>
struct ScalarTypeIfOne {typedef Vec<TT,nx> T;};
template <class TT>
struct ScalarTypeIfOne<1,TT> {typedef TT T;};

//--------------Powers table for a polynomial of nd degree in nx variables -------------

template <int nd, int nx>
struct PolPowers {

    typedef PolPowers<(nd>0?nd-1:nd),nx> Derivative;

    static bool init_puissances;
    static Vec<Vec<unsigned,nx>,DimPol<nd,nx>::valeur> puissances;

    static void initialize_puissances() {
        init_puissances=0;
        puissances[0].set(0);
        for (int i=1;i<DimPol<nd,nx>::valeur;i++)
        puissances[i]=PolPowers<nd,nx>::next_power(puissances[i-1]);
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

    template <class T, class T1, class T2> static void evaluates (T &res, const Vec<T1,DimPol<nd,nx>::valeur> &coefs, const Vec<T2,nx> &x){
        res=coefs[0];
        for (unsigned i=1;i<DimPol<nd,nx>::valeur;i++) {
            T1 tmp=coefs[i];
            for (int k=0;k<nx;k++)
                tmp*=pow(x[k],int(puissances[i][k]));
            res+=tmp;
        }
    }

};

template <int nd, int nx>
bool PolPowers<nd,nx>::init_puissances=1;

template <int nd, int nx>
Vec<Vec<unsigned,nx>,DimPol<nd,nx>::valeur> PolPowers<nd,nx>::puissances;

template <int nd>
struct PolPowers<nd,1> {

    static bool init_puissances;
    static Vec<Vec<unsigned,1>,DimPol<nd,1>::valeur> puissances;

    static void initialize_puissances() {
        for (int i=0;i<DimPol<nd,1>::valeur;i++)
            puissances[i][0]=i;
    }

    template <class T, class T1, class T2> static void evaluates (T &res, const Vec<T1,DimPol<nd,1>::valeur> &coefs, const Vec<T2,1> &x){
        res=coefs[0];
        for (unsigned i=1;i<DimPol<nd,1>::valeur;i++)
            res += coefs[i] * ::pow(x[0],i);
    }

    typedef PolPowers<(nd>0?nd-1:nd),1> Derivative;
};

template <int nd>
bool PolPowers<nd,1>::init_puissances=0;

template <int nd>
Vec<Vec<unsigned,1>,DimPol<nd,1>::valeur> PolPowers<nd,1>::puissances;

//--------------Derivative table for a polynomial of nd degree in nx variables-------------

template <int nd, int nx>
struct PolDerivative {

    static bool init_deriv;
    static Vec<Vec<unsigned,DimPol<(nd>0?nd-1:nd),nx>::valeur>,nx> deriv;

    static void initialize_deriv() {
        if (PolPowers<nd,nx>::init_puissances)
            PolPowers<nd,nx>::initialize_puissances();
        if (PolPowers<nd,nx>::Derivative::init_puissances)
            PolPowers<nd,nx>::Derivative::initialize_puissances();
        init_deriv=0;
        for (unsigned i=0;i<nx;i++)
            for (int j=0;j<DimPol<(nd>0?nd-1:nd),nx>::valeur;j++) {
                Vec<unsigned,nx> puissance_input=PolPowers<(nd>0?nd-1:nd),nx>::puissances[j];
                puissance_input[i]++;
                for (int k=0;k<DimPol<nd,nx>::valeur;k++)
                    if (puissance_input==PolPowers<nd,nx>::puissances[k]) {
                        deriv[i][j]=k;
                        break;
                }
            }
    }

    template <class T>
    static void derivates (Vec<Vec<T,DimPol<(nd>0?nd-1:nd),nx>::valeur>,nx> &derivee, const Vec<T,DimPol<nd,nx>::valeur> &coefs) {
        for (int i=0;i<nx;i++)
            for (int j=0;j<DimPol<(nd>0?nd-1:nd),nx>::valeur;j++)
                derivee[i][j]=coefs[deriv[i][j]]*PolPowers<nd,nx>::puissances[deriv[i][j]][i];
    }
};

template <int nd, int nx>
bool PolDerivative<nd,nx>::init_deriv=1;

template <int nd, int nx>
Vec<Vec<unsigned,DimPol<(nd>0?nd-1:nd),nx>::valeur>,nx> PolDerivative<nd,nx>::deriv;

template <int nd>
struct PolDerivative<nd,1> {
    static bool init_deriv;
    static void initialize_deriv() {}
    template <class T>
    static void derivates (Vec<T,DimPol<(nd>0?nd-1:nd),1>::valeur> &derivee, const Vec<T,DimPol<nd,1>::valeur> &coefs) {
        for (unsigned j=0;j<DimPol<(nd>0?nd-1:nd),1>::valeur;j++)
            derivee[j]=coefs[j+1]*(j+1);
    }
};

template <int nd>
bool PolDerivative<nd,1>::init_deriv=0;

//--------------Multiplication table for a two polynomials of nd degree in nx variables-------------

template <int nd, int nx>
struct PolMultiplies {

    static bool init_mult;
    static Vec<Vec<Vec<unsigned,2> >,DimPol<nd,nx>::valeur> mult;

    static void initialize_mult() {
        if (PolPowers<nd,nx>::init_puissances)
            PolPowers<nd,nx>::initialize_puissances();
        init_mult=0;
        Vec<Vec<Vec<unsigned,nd+1>,nd+1>,nx> tmp;
        for (unsigned j=0;j<=nd;j++)
            for (unsigned k=0;k<=nd;k++)
                tmp[0][j][k]=k;
        for (unsigned i=1;i<nx;i++)
            for (unsigned j=0;j<=nd;j++)
                for (unsigned k=0;k<=nd;k++) {
                    tmp[i][j][k]=k;
                    for (unsigned s=j+1-k;s<=j;s++)
                        tmp[i][j][k]+=tmp[i-1][s][s];
                }
        for (unsigned i=0;i<DimPol<nd,nx>::valeur;i++)
            for (unsigned alphas=0;alphas<DimPol<nd,nx>::valeur;alphas++)
                if (min(PolPowers<nd,nx>::puissances[alphas]<=PolPowers<nd,nx>::puissances[i])) {
                    unsigned c1=0;
                    unsigned c2=0;
                    for (unsigned a=0;a<nx;a++) {
                        unsigned aux1=0;
                        unsigned aux2=0;
                        for (unsigned gamma=a+1;gamma<nx;gamma++) {
                            aux1+=PolPowers<nd,nx>::puissances[i][gamma]-PolPowers<nd,nx>::puissances[alphas][gamma];
                            aux2+=PolPowers<nd,nx>::puissances[alphas][gamma];
                        }
                        c1+=tmp[a][nd-aux1][PolPowers<nd,nx>::puissances[i][a]-PolPowers<nd,nx>::puissances[alphas][a]];
                        c2+=tmp[a][nd-aux2][PolPowers<nd,nx>::puissances[alphas][a]];
                    }
                    Vec<unsigned,2> aux;
                    aux[0]=c1;
                    aux[1]=c2;
                    mult[i].push_back(aux);
                }
    }

    template <class T, class T1, class T2>
    static void multiplies(Vec<T,DimPol<nd,nx>::valeur> &coef, unsigned i, const Vec<T1,DimPol<nd,nx>::valeur> &p, const Vec<T2,DimPol<nd,nx>::valeur> &q, int decalage = 0) {
         for (int j=0;j<PolMultiplies<nd,nx>::mult[i].size()-decalage;j++)
             coef[i]+=p[mult[i][j][0]]*q[mult[i][j][1]];
    }
};

template <int nd, int nx>
bool PolMultiplies<nd,nx>::init_mult=1;

template <int nd, int nx>
Vec<Vec<Vec<unsigned,2> >,DimPol<nd,nx>::valeur> PolMultiplies<nd,nx>::mult;

template <int nd>
struct PolMultiplies<nd,1> {
    static bool init_mult;
    static void initialize_mult() {}
    template <class T, class T1, class T2> static void multiplies(Vec<T,DimPol<nd,1>::valeur> &coef, unsigned i, const Vec<T1,DimPol<nd,1>::valeur> &p, const Vec<T2,DimPol<nd,1>::valeur> &q, int decalage = 0) {
        for (int j=0;j<=i-decalage;j++)
            coef[i]+=p[i-j]*q[j];
    }
};

template <int nd>
bool PolMultiplies<nd,1>::init_mult=0;

//--------------Troncature table in order to make a polynomial of ne degree in nx variables---------------------
//-------------------------------------------from a polynomial of nd degree in nx variables with (nd>ne)--------

template <int nd, int ne, int nx>
struct PolTroncates {

    static bool init_troncates;
    static Vec<unsigned,DimPol<ne,nx>::valeur> troncature;

    static void initialize_tronc () {
        if (PolPowers<nd,nx>::init_puissances)
            PolPowers<nd,nx>::initialize_puissances();
        if (PolPowers<ne,nx>::init_puissances)
            PolPowers<ne,nx>::initialize_puissances();
        init_troncates=0;
        for (unsigned i=0;i<DimPol<ne,nx>::valeur;i++)
            for (int j=0;j<DimPol<nd,nx>::valeur;j++)
                if (PolPowers<ne,nx>::puissances[i]==PolPowers<nd,nx>::puissances[j]) {
                    troncature[i]=j;
                    break;
                }
    }

    template <class T1, class T2>
    static void troncates(Vec<T1,DimPol<nd,nx>::valeur> &coef, const Vec<T2,DimPol<ne,nx>::valeur> &p) {
        coef.set(T1(0));
        for (unsigned i=0;i<DimPol<ne,nx>::valeur;i++)
            coef[troncature[i]] = p[i];
    }

    template <class T1, class T2>
    static void troncates(Vec<T1,DimPol<ne,nx>::valeur> &coef, const Vec<T2,DimPol<nd,nx>::valeur> &p) {
        for (unsigned i=0;i<DimPol<nd,nx>::valeur;i++)
            coef[i] = p[troncature[i]];
    }
};

template <int nd, int ne, int nx>
bool PolTroncates<nd,ne,nx>::init_troncates=1;

template <int nd, int ne, int nx>
Vec<unsigned,DimPol<ne,nx>::valeur> PolTroncates<nd,ne,nx>::troncature;

template <int nd, int ne>
struct PolTroncates<nd,ne,1> {

    static bool init_troncates;
    static void initialize_tronc () {}

    template <class T1, class T2>
    static void troncates(Vec<T1,DimPol<nd,1>::valeur> &coef, const Vec<T2,DimPol<ne,1>::valeur> &p) {
        for(unsigned i=0;i<DimPol<ne,1>::valeur;++i)
            coef[i] = p[i];
        for(unsigned i=DimPol<ne,1>::valeur;i<DimPol<nd,1>::valeur;++i)
            coef[i] = T1(0);
    }

    template <class T1, class T2>
    static void troncates(Vec<T1,DimPol<ne,1>::valeur> &coef, const Vec<T2,DimPol<nd,1>::valeur> &p) {
        for(unsigned i=0;i<DimPol<nd,1>::valeur;++i)
            coef[i] = p[i];
    }
};

template <int nd, int ne>
bool PolTroncates<nd,ne,1>::init_troncates=0;

//--------------Restriction tables in order to make a polynomial of nd degree in nx variables---------------------
//---------------------------------------------from a polynomial of nd degree in ny variables with (nx>ny)--------

template <int nd, int nx, int ny>
struct PolRestriction {

    static Vec<bool,Deux_Puissance<nx>::valeur> init_restriction;
    static Vec<Vec<unsigned,DimPol<nd,ny>::valeur>,Deux_Puissance<nx>::valeur> restriction;

    static void initialize_restriction (const Vec<unsigned,ny> &vq) {
        if (PolPowers<nd,nx>::init_puissances)
            PolPowers<nd,nx>::initialize_puissances();
        if (PolPowers<nd,ny>::init_puissances)
            PolPowers<nd,ny>::initialize_puissances();
        int rest=0;
        for (int i=0;i<ny;i++) {
            int tmp=1;
            for (int j=0;j<vq[i];j++)
                tmp*=2;
            rest+=tmp;
        }
        init_restriction[rest]=0;
        for (unsigned i=0;i<DimPol<nd,ny>::valeur;i++)
            for (int j=0;j<DimPol<nd,nx>::valeur;j++)
                if (PolPowers<nd,ny>::puissances[i]==PolPowers<nd,nx>::puissances[j][vq]) {
                    restriction[rest][i]=j;
                    break;
                }
    }

};


template <int nd, int nx, int ny>
Vec<bool,Deux_Puissance<nx>::valeur> PolRestriction<nd,nx,ny>::init_restriction=1;

template <int nd, int nx, int ny>
Vec<Vec<unsigned,DimPol<nd,ny>::valeur>,Deux_Puissance<nx>::valeur> PolRestriction<nd,nx,ny>::restriction;

}

#endif // pol_tables_HEADER
