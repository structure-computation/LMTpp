#ifndef pol_tables_HEADER
#define pol_tables_HEADER

#include "pol_dimension.h"

namespace LMT {

//--------------Powers table for a polynomial of nd degree in nx variables -------------

template <int nd, int nx>
struct PolPowers {

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

    typedef PolPowers<(nd>0?nd-1:nd),nx> Derivative;
};

template <int nd, int nx>
bool PolPowers<nd,nx>::init_puissances=1;

template <int nd, int nx>
Vec<Vec<unsigned,nx>,DimPol<nd,nx>::valeur> PolPowers<nd,nx>::puissances;

//--------------Derivative table for a polynomial of nd degree in nx variables-------------

template <int nd, int nx>
struct PolDerivative {

    static bool init_deriv;
    static Vec<Vec<unsigned>,DimPol<nd,nx>::valeur> deriv_var;
    static Vec<Vec<unsigned>,DimPol<nd,nx>::valeur> deriv_ind;
    static Vec<Vec<unsigned>,DimPol<nd,nx>::valeur> deriv_coef;

    static void initialize_deriv() {
        if (PolPowers<nd,nx>::init_puissances)
            PolPowers<nd,nx>::initialize_puissances();
        if (PolPowers<nd,nx>::Derivative::init_puissances)
            PolPowers<nd,nx>::Derivative::initialize_puissances();
        init_deriv=0;
        for (unsigned i=1;i<DimPol<nd,nx>::valeur;i++)
            for (int j=0;j<nx;j++)
                if (PolPowers<nd,nx>::puissances[i][j]>0) {
                    Vec<unsigned,nx> puissances_deriv_j=PolPowers<nd,nx>::puissances[i];
                    puissances_deriv_j[j]--;
                    for (unsigned alphas=0;alphas<PolPowers<nd,nx>::Derivative::puissances.size();alphas++)
                        if (min(PolPowers<nd,nx>::Derivative::puissances[alphas]==puissances_deriv_j)) {
                            deriv_var[i].push_back(j);
                            deriv_ind[i].push_back(alphas);
                            deriv_coef[i].push_back(PolPowers<nd,nx>::puissances[i][j]);
                            break;
                        }
                }
    }

};

template <int nd, int nx>
bool PolDerivative<nd,nx>::init_deriv=1;

template <int nd, int nx>
Vec<Vec<unsigned>,DimPol<nd,nx>::valeur> PolDerivative<nd,nx>::deriv_var;

template <int nd, int nx>
Vec<Vec<unsigned>,DimPol<nd,nx>::valeur> PolDerivative<nd,nx>::deriv_ind;

template <int nd, int nx>
Vec<Vec<unsigned>,DimPol<nd,nx>::valeur> PolDerivative<nd,nx>::deriv_coef;

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

};

template <int nd, int nx>
bool PolMultiplies<nd,nx>::init_mult=1;

template <int nd, int nx>
Vec<Vec<Vec<unsigned,2> >,DimPol<nd,nx>::valeur> PolMultiplies<nd,nx>::mult;

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

};

template <int nd, int ne, int nx>
bool PolTroncates<nd,ne,nx>::init_troncates=1;

template <int nd, int ne, int nx>
Vec<unsigned,DimPol<ne,nx>::valeur> PolTroncates<nd,ne,nx>::troncature;

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
