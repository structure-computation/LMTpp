////////////////////////////////////
//  Author : Camille GOUTTEBROZE  //
//  gouttebroze@lmt.ens-cachan.fr //
////////////////////////////////////

#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include <vector>
#include <limits>
#include <complex>
#include <containers/gnuplot.h>
#include <containers/mat.h>
#include <containers/algo.h>

namespace LMT {

/**
  @author Gouttebroze
*/

template <int nd=4, int nx=1, class T=double>
class Pol {
private:
    Vec<T> coefs;
    template <int nx_> Vec<unsigned,nx_> next_power(const Vec<unsigned,nx_> &v, int dmaxi);
    Vec<unsigned,1> next_power(const Vec<unsigned,1> &v, int dmaxi);
    static bool init;
    void initialize();
public:
    static Vec<Vec<unsigned,nx> > puissances;
    static Vec<Vec<Vec<unsigned,2> > > mult;
    static Vec<Vec<Vec<unsigned,2> > > inv_ind;
    static Vec<Vec<T> > inv_coef;
    static Vec<Vec<unsigned> > deriv_var;
    static Vec<Vec<unsigned> > deriv_ind;
    static Vec<Vec<T> > deriv_coef;
public:
    Pol ();
    template<class ScalarType> Pol(const ScalarType &a); ///Construit le polynome constant egal a a
    Pol(const Vec<T> &V); ///Construit le polynome a partir de ses coefficients
    template <class T2> Pol(const Pol<nd,nx,T2> &P); ///Construit un polynome a partir d'un autre polynome de meme degre
//     template <int nd2> Pol (const Pol<nd2,nx,T> &P); Construit un polynome a partir d'un polynome de degre maximal different
    Pol (const T &a, const T &b, unsigned q); ///Construit le polynome a + b*Xq;
    template <class T2> Pol<nd,nx,T> &operator= (const Pol<nd,nx,T2> &P); ///Renvoie un polynome egal a P
    const Vec<T> &coefficients() const {return coefs;} ///Renvoie les coefficients du polynome
    const Vec<Vec<unsigned,nx> > &powers() const {return puissances;} ///Renvoie les puissances du polynome
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,nx> &V) const; /// Renvoie la valeur du polynome en V
    Vec<Pol<nd-1,nx,T>,nx> derivative() const; ///Renvoie les polynomes derives
    operator bool() const {return true;};
    Pol<nd,nx,T> operator-() const; ///Renvoie le polynome oppose;
    template <class T2> bool operator== (const Pol<nd,nx,T2> &P) const; /// Verifie si le polynome est egal a P
    template <class T2> bool operator!= (const Pol<nd,nx,T2> &P) const; /// Verifie si le polynome est different de P
    template <class T2> void operator+= (const Pol<nd,nx,T2> &P); /// Ajoute P au polynome
    template <class T2> void operator-= (const Pol<nd,nx,T2> &P); /// Retranche P au polynome
};

template <int nd, int nx, class T>
bool Pol<nd,nx,T>::init=1;

template <int nd, int nx, class T>
Vec<Vec<unsigned,nx> > Pol<nd,nx,T>::puissances;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned,2> > > Pol<nd,nx,T>::mult;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned,2> > > Pol<nd,nx,T>::inv_ind;

template <int nd, int nx, class T>
Vec<Vec<T> > Pol<nd,nx,T>::inv_coef;

template <int nd, int nx, class T>
Vec<Vec<unsigned> > Pol<nd,nx,T>::deriv_var;

template <int nd, int nx, class T>
Vec<Vec<unsigned> > Pol<nd,nx,T>::deriv_ind;

template <int nd, int nx, class T>
Vec<Vec<T> > Pol<nd,nx,T>::deriv_coef;

template <int nd, int nx, class T>
template <int nx_>
Vec<unsigned,nx_> Pol<nd,nx,T>::next_power(const Vec<unsigned,nx_> &v, int dmaxi=nd) {
    Vec<unsigned,nx_> res=v;
    unsigned tmp=res[0];
    for (unsigned i=1;i<res.size();i++)
        tmp+=res[i];
    if ((int)tmp<dmaxi) {
        res[0]++;
    }
    else {
        Vec<unsigned,nx_-1> tmp=res[range(unsigned(1),res.size())];
        res[range(unsigned(1),res.size())]=next_power(tmp,dmaxi);
        res[0]=0;
    }
    return res;
}

template <int nd, int nx, class T>
Vec<unsigned,1> Pol<nd,nx,T>::next_power(const Vec<unsigned,1> &v, int dmaxi=nd) {
    Vec<unsigned,1> res=v;
    res[0]++;
    return res;
}

template <int nd, int nx, class T>
void Pol<nd,nx,T>::initialize() {

    //Falsification du boolen init
    init=0;

    //Calcul des puissances
    puissances.resize(1);
    puissances[0].set(0);
    while (puissances[puissances.size()-1][nx-1]<nd) {
        puissances.resize(puissances.size()+1);
        puissances[puissances.size()-1]=next_power(puissances[puissances.size()-2]);
//         puissances.append(next_power(puissances[puissances.size()-1]));
    }

    //Calcul intermediaire des puissances pour la derivation
    Vec<Vec<unsigned,nx> > puissances_derivee;
    puissances_derivee.resize(1);
    puissances_derivee[0].set(0);
    while ((int)puissances_derivee[puissances_derivee.size()-1][nx-1]<max(nd-1,0)) {
        puissances_derivee.resize(puissances_derivee.size()+1);
        puissances_derivee[puissances_derivee.size()-1]=next_power(puissances_derivee[puissances_derivee.size()-2],nd-1);
//         puissances_derivee.append(next_power(puissances_derivee[puissances_derivee.size()-1],nd-1));
    }

    //Calcul des indices intermediaires pour la multiplication et la division
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

    //Calcul des indices pour le terme constant
    mult.resize(puissances.size());
    inv_ind.resize(puissances.size());
    inv_coef.resize(puissances.size());
    deriv_var.resize(puissances.size());
    deriv_ind.resize(puissances.size());
    deriv_coef.resize(puissances.size());
    mult[0].resize(1);
    mult[0][0][0]=0;
    mult[0][0][1]=0;

    //Calcul des indices et coefficients pour les termes non constant
    for (unsigned i=1;i<puissances.size();i++) {
        Vec<unsigned,nx> ind_div_maxi=puissances[i];
        int p;
        for (int j=0;j<nx;j++)
            if (ind_div_maxi[j]>0) {
                ind_div_maxi[j]--;
                p=j;
                break;
            }

        //Calcul des indices et coefficients pour la derivation
        for (int j=0;j<nx;j++)
            if (puissances[i][j]>0) {
                Vec<unsigned,nx> puissances_deriv_j=puissances[i];
                puissances_deriv_j[j]--;
                for (unsigned alphas=0;alphas<puissances_derivee.size();alphas++)
                    if (min(puissances_derivee[alphas]==puissances_deriv_j)) {
                        deriv_var[i].push_back(j);
                        deriv_ind[i].push_back(alphas);
                        deriv_coef[i].push_back(T(puissances[i][j]));
                        break;
                    }
            }

        for (unsigned alphas=0;alphas<puissances.size();alphas++) {

            // Calcul des indices et coefficients pour la division
            if (min(puissances[alphas]<=ind_div_maxi)) {
                unsigned c1=0;
                unsigned c2=0;
                for (unsigned a=0;a<nx;a++) {
                    unsigned aux1=0;
                    unsigned aux2=0;
                    for (unsigned gamma=a+1;gamma<nx;gamma++) {
                        aux1+=puissances[i][gamma]-puissances[alphas][gamma];
                        aux2+=puissances[alphas][gamma];
                    }
                    c1+=tmp[a][nd-aux1][puissances[i][a]-puissances[alphas][a]];
                    c2+=tmp[a][nd-aux2][puissances[alphas][a]];
                }
                Vec<unsigned,2> aux;
                aux[0]=c1;
                aux[1]=c2;
                inv_ind[i].resize(inv_ind[i].size()+1);
                inv_ind[i][inv_ind[i].size()-1]=aux;
                inv_coef[i].push_back(T(puissances[i][p]-puissances[alphas][p])/T(puissances[i][p]));
            }

            // Calcul des indices pour la multiplication
            if (min(puissances[alphas]<=puissances[i])) {
                unsigned c1=0;
                unsigned c2=0;
                for (unsigned a=0;a<nx;a++) {
                    unsigned aux1=0;
                    unsigned aux2=0;
                    for (unsigned gamma=a+1;gamma<nx;gamma++) {
                        aux1+=puissances[i][gamma]-puissances[alphas][gamma];
                        aux2+=puissances[alphas][gamma];
                    }
                    c1+=tmp[a][nd-aux1][puissances[i][a]-puissances[alphas][a]];
                    c2+=tmp[a][nd-aux2][puissances[alphas][a]];
                }
                Vec<unsigned,2> aux;
                aux[0]=c1;
                aux[1]=c2;
                mult[i].resize(mult[i].size()+1);
                mult[i][mult[i].size()-1]=aux;
            }
        }
    }
}

template <int nd, int nx, class T>
Pol<nd,nx,T>::Pol() {
    if (init)
        initialize();
}

template <int nd, int nx, class T>
template<class ScalarType>
Pol<nd,nx,T>::Pol(const ScalarType &a) {
    if (init)
        initialize();
    coefs.resize(puissances.size(),T(0));
    coefs[0] = a;
}

template <int nd, int nx, class T>
Pol<nd,nx,T>::Pol(const Vec<T> &V) {
    if (init)
        initialize();
    coefs=V;
}

template <int nd, int nx, class T>
template <class T2>
Pol<nd,nx,T>::Pol(const Pol<nd,nx,T2> &P) {
    if (init)
        initialize();
    coefs=P.coefficients();
}

// template <int nd, int nx, class T>
// template <int nd2>
// Pol<nd,nx,T>::Pol(const Pol<nd2,nx,T> &P) {
//     assert(0);
// }

template <int nd, int nx, class T>
Pol<nd,nx,T>::Pol(const T &a, const T &b, unsigned q) {
    if (init)
        initialize();
    coefs.resize(puissances.size(),T(0));
    coefs[0]=a;
    for (int i=0;i<puissances.size();i++)
        if (puissances[i][q]==1) {
            coefs[i]=b;
            break;
        }
}

template <int nd, int nx, class T>
template <class T2>
Pol<nd,nx,T> &Pol<nd,nx,T>::operator= (const Pol<nd,nx,T2> &P) {
    coefs=P.coefficients();
    return *this;
}


template <int nd, int nx, class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Pol<nd,nx,T>::operator() (const Vec<T2,nx> &V) const {
    typedef typename TypePromote<Multiplies,T,T2>::T T_;
    T_ res=coefs[0];
    for (unsigned i=1;i<coefs.size();i++) {
        T_ tmp=coefs[i];
        for (int k=0;k<nx;k++)
            tmp*=pow(V[k],int(puissances[i][k]));
        res+=tmp;
    }
    return res;
}

template <int nd, int nx, class T>
Vec<Pol<nd-1,nx,T>,nx> Pol<nd,nx,T>::derivative() const {
    Vec<Pol<nd-1,nx,T>,nx> res;
    Vec<Vec<T>,nx> res_vec;
    for (int i=0;i<nx;i++)
        res_vec[i].resize(res[i].puissances.size());
    for (int i=1;i<deriv_ind.size();i++) {
        for (int j=0;j<deriv_ind[i].size();j++)
            res_vec[deriv_var[i][j]][deriv_ind[i][j]]=deriv_coef[i][j]*coefs[i];
    }
    for (int i=0;i<nx;i++)
        res[i]=Pol<nd-1,nx,T>(res_vec[i]);
    return res;
}

template <int nd, int nx, class T>
Pol<nd,nx,T> Pol<nd,nx,T>::operator-() const {
return Pol<nd,nx,T>(-coefs);
}

template <int nd, int nx, class T>
template <class T2>
bool Pol<nd,nx,T>::operator== (const Pol<nd,nx,T2> &P) const {
    return coefs==P.coefficients();
}

template <int nd, int nx, class T>
template <class T2>
bool Pol<nd,nx,T>::operator!= (const Pol<nd,nx,T2> &P) const {
    return not ( coefs == P.coefficients() );
}

template <int nd, int nx, class T>
template <class T2>
void Pol<nd,nx,T>::operator+= (const Pol<nd,nx,T2> &P) {
    coefs+=P.coefficients();
}

template <int nd, int nx, class T>
template <class T2>
void Pol<nd,nx,T>::operator-= (const Pol<nd,nx,T2> &P) {
    coefs-=P.coefficients();
}

/////////////////////////////////////////////////////////////////////
// DEFINITION DES FONCTIONS GLOBALES EN RAPPORT AVEC DES POLYNOMES //
/////////////////////////////////////////////////////////////////////

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator+(const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    return Pol<nd,nx,typename TypePromote<Plus,T1,T2>::T>(Vec<typename TypePromote<Plus,T1,T2>::T >(P.coefficients()+Q.coefficients()));
}

// template <int nx, int nd1, class T1, int nd2, class T2>
// Pol<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Plus,T1,T2>::T> operator+(const Pol<nd1,nx,T1> &P, const Pol<nd2,nx,T2> &Q) {
//     return (nd1>nd2?Pol<nd2,nx,T1>(P)+Q:P+Pol<nd1,nx,T1>(Q));
// }

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator-(const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    return Pol<nd,nx,typename TypePromote<Plus,T1,T2>::T>(Vec<typename TypePromote<Plus,T1,T2>::T >(P.coefficients()-Q.coefficients()));
}

// template <int nx, int nd1, class T1, int nd2, class T2>
// Pol<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Plus,T1,T2>::T> operator-(const Pol<nd1,nx,T1> &P, const Pol<nd2,nx,T2> &Q) {
//     return (nd1>nd2?Pol<nd2,nx,T1>(P)-Q:P-Pol<nd1,nx,T1>(Q));
// }

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator*(const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    typedef typename TypePromote<Plus,T1,T2>::T T;
    Vec<T> res_vec;
    res_vec.resize(P.puissances.size(),T(0));
    for (unsigned i=0;i<res_vec.size();i++) {
        for (unsigned j=0;j<P.mult[i].size();j++)
            res_vec[i]+=P.coefficients()[P.mult[i][j][0]]*Q.coefficients()[P.mult[i][j][1]];
    }
    return Pol<nd,nx,T>(res_vec);
}

// template <int nx, int nd1, class T1, int nd2, class T2>
// Pol<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Plus,T1,T2>::T> operator*(const Pol<nd1,nx,T1> &P, const Pol<nd2,nx,T2> &Q) {
//     return (nd1>nd2?Pol<nd2,nx,T1>(P)*Q:P*Pol<nd1,nx,T1>(Q));
// }

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator/(const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    typedef typename TypePromote<Plus,T1,T2>::T T;
    Vec<T> a,b,res_vec;
    a.resize(Q.puissances.size(),T(0));
    a[0]=T2(1)/Q.coefficients()[0];
    b.resize(Q.puissances.size(),T(0));
    b[0]=a[0]*a[0];
    res_vec.resize(P.puissances.size(),T(0));
    res_vec[0]=P.coefficients()[0]/Q.coefficients()[0];
    for (int i=1;i<res_vec.size();i++) {
        for (int j=0;j<Q.inv_ind[i].size();j++) {
            a[i]-=Q.inv_coef[i][j]*Q.coefficients()[Q.inv_ind[i][j][0]]*b[Q.inv_ind[i][j][1]];
        }
        for (int j=0;j<Q.mult[i].size();j++)
            b[i]+=a[Q.mult[i][j][0]]*a[Q.mult[i][j][1]];
        for (int j=0;j<P.mult[i].size();j++)
            res_vec[i]+=P.coefficients()[P.mult[i][j][0]]*a[Q.mult[i][j][1]];
    }
    return Pol<nd,nx,T>(res_vec);
}

// template <int nx, int nd1, class T1, int nd2, class T2>
// Pol<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Plus,T1,T2>::T> operator/(const Pol<nd1,nx,T1> &P, const Pol<nd2,nx,T2> &Q) {
//     return (nd1>nd2?Pol<nd2,nx,T1>(P)/Q:P/Pol<nd1,nx,T1>(Q));
// }

template <int nd, int nx, class T>
Pol<nd,nx,T> operator*(const Pol<nd,nx,T> &P, const T &t) {
    return Pol<nd,nx,T> (Vec<T>(P.coefficients()*t));
}

template <int nd, int nx, class T>
Pol<nd,nx,T> operator*(const T &t, const Pol<nd,nx,T> &P) {
    return Pol<nd,nx,T> (Vec<T>(t*P.coefficients()));
}

// template <int nd, int nx, class T>
// inline T abs(const Pol<nd,nx,T> &P) {
//     PRINT("titi");
//     return LMT::abs(P.coefficients()[0]);
// }

template <int nd, int nx, class T>
inline typename TypePromote<Abs,T>::T abs_indication(const Pol<nd,nx,T> &P) {
    return abs_indication(P.coefficients()[0]);
}

template <int nd, int nx, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,nx,T> &P) {
    os << " " << P.coefficients()[0] << " ";
    for (unsigned i=1;i<P.coefficients().size();i++) {
        if (P.coefficients()[i]>0) {
            os << "+" << P.coefficients()[i];
            for (int j=0;j<nx;j++)
                if(P.puissances[i][j]>0)
                    os << "*X" << j << "^" << P.puissances[i][j];
            os << " ";
        }
        if (P.coefficients()[i]<0) {
            os << "-" << -P.coefficients()[i];
            for (int j=0;j<nx;j++)
                if(P.puissances[i][j]>0)
                    os << "*X" << j << "^" << P.puissances[i][j];
            os << " ";
        }
    }
    os << " ";
    return os;
}

///////////////////////////////////////////////////////////////////////////////
// DEFINITION DE LA CLASSE POLYNOME MONOVARIABLE ET DE SES FONCTIONS MEMBRES //
///////////////////////////////////////////////////////////////////////////////

template <int nd, class T>
class Pol<nd,1,T> {
private:
    Vec<T> coefs;
public:
    Pol () {};
    Pol (const Vec<T> &V); ///Construit un polynome a partir de ses coeficients
    Pol (T a) {coefs.resize(1,a);} ///Construit un polynome constant
    Pol (T a,T b); ///Construit un polynome du 1er degre
    Pol (T a,T b,T c); ///Construit un polynome du 2eme degre
    Pol (T a,T b,T c,T d); ///Construit un polynome du 3eme degre
    Pol (T a,T b,T c,T d,T e); ///Construit un polynome du 4eme degre
    Pol (T a,T b,T c,T d,T e,T f);///Construit un polynome du 5eme degre
    Pol (T a,T b,T c,T d,T e,T f,T g); ///Construit un polynome du 6eme degre
    Pol (T a,T b,T c,T d,T e,T f,T g,T h); ///Construit un polynome du 7eme degre
    template <int nd2, class T2> Pol(const Pol<nd2,1,T2> &P2);
    template <int nd_, class T_> Pol<nd,1,T> &operator= (const Pol<nd_,1,T_> &P); ///Renvoie un polynome egal a P
    const Vec<T> &coefficients() const {return coefs;} ///Renvoie les coefficients du polynome
    Vec<Vec<unsigned,1> > powers() const; ///Renvoie les puissances du polynome
    int degree() const {return coefs.size()-1;} ///Renvoie le degre du polynome
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (T2 x) const;  ///Renvoie la valeur du polynome en x
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,1> &V) const; ///Renvoie le vecteur des valeurs du polynome en toutes les valeurs de V
    template <class T2> Vec<typename TypePromote<Multiplies,T,T2>::T> operator() (const Vec<T2> &V) const; ///Renvoie le vecteur des valeurs du polynome en toutes les valeurs de V
    T coef_max() const; ///Renvoie le plus grand coefficient en valeur absolue
    Pol<nd,1,T> operator-() const {return Pol<nd,1,T>(-coefs);} ///Renvoie le polynome oppose;
    Pol<nd-1,1,T> derivative() const; ///Renvoie le polynome derivee
    Pol<nd,1,T> integral (const T &a) const; ///Renvoie le polynome integrale qui prend a comme valeur en 0
    int MaxPositivesRoots() const; ///Renvoie le nombre maximal de racines positives
    int MaxNegativesRoots() const; ///Renvoie le nombre maximal de racines negatives
    T RootsUpperBound() const; ///Renvoie un majorant des racines
    T RootsLowerBound() const; ///Renvoie un minorant des racines
    Pol<nd,1,T> remainder(const Pol<nd,1,T> &P) const; ///Renvoie le reste de la division par un polynome
    T root_dichotomy (T a,T b) const; ///Cherche une racine par dichotomie entre a et b
    Vec<T> roots() const; ///Renvoie les racines du polynome
    T Newton(T d) const; ///Cherche une racine par l'algorithme de Newton en partant de d
    operator bool() const {return true;};
    bool constant() const {return coefs.size()==1;}; ///Indique si le polynome est constant
    bool operator==(const T &t) const ; ///Indique si le polynome est egal a t
    bool operator!=(const T &t) const ; ///Indique si le polynome est different de t
    template <class T1> bool operator==(const T1 &d) const; ///Regarde si le polynome est different de d
    template <class T1> bool operator!=(const T1 &d) const; ///Regarde si le polynome est different de d
    template <class T2> void operator+=(const T2 &t); ///Ajoute t au polynome
    template <class T2> void operator-=(const T2 &t); ///Retranche t au polynome
    template <int nd2, class T2> void operator+=(const Pol<nd2,1,T2> &Q); ///Ajoute Q au polynome
    template <int nd2, class T2> void operator-=(const Pol<nd2,1,T2> &Q); ///Retranche Q au polynome
    template <class T2> void operator*=(const T2 &t); ///Multiplie le polynome par t
    void operator/=(const T &t) {coefs/=t;}; ///Divise le polynome par t
    template <class T2> T2 troncate(const T2 &c, const T2 &d, const T2 &r, int nmax); ///Tronque le polynome autour de c pour avec un residu inferieur a r sur un intervalle de taille 2d
};

template <int nd, class T>
Pol<nd,1,T>::Pol(const Vec<T> &V) {
    coefs=V;
}

template <int nd, class T>
Pol<nd,1,T>::Pol (T a,T b) {
    coefs.resize(min(2,nd+1));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
}

template <int nd, class T>
Pol<nd,1,T>::Pol (T a,T b,T c) {
    coefs.resize(min(3,nd+1));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
}

template <int nd, class T>
Pol<nd,1,T>::Pol (T a,T b,T c,T d) {
    coefs.resize(min(4,nd+1));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
    if(nd>2) coefs[3]=d;
}

template <int nd, class T>
Pol<nd,1,T>::Pol (T a,T b,T c,T d,T e) {
    coefs.resize(min(5,nd+1));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
    if(nd>2) coefs[3]=d;
    if(nd>3) coefs[4]=e;
}

template <int nd, class T>
Pol<nd,1,T>::Pol (T a,T b,T c,T d,T e,T f) {
    coefs.resize(min(6,nd+1));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
    if(nd>2) coefs[3]=d;
    if(nd>3) coefs[4]=e;
    if(nd>4) coefs[5]=f;
}

template <int nd, class T>
Pol<nd,1,T>::Pol (T a,T b,T c,T d,T e,T f,T g) {
    coefs.resize(min(7,nd+1));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
    if(nd>2) coefs[3]=d;
    if(nd>3) coefs[4]=e;
    if(nd>4) coefs[5]=f;
    if(nd>5) coefs[6]=g;
}

template <int nd, class T>
Pol<nd,1,T>::Pol (T a,T b,T c,T d,T e,T f,T g,T h) {
    coefs.resize(min(8,nd+1));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
    if(nd>2) coefs[3]=d;
    if(nd>3) coefs[4]=e;// template <int nd, int nx, class T>
// Vec<Vec<unsigned,nx> > Pol<nd,nx,T>::puissances;
    if(nd>4) coefs[5]=f;
    if(nd>5) coefs[6]=g;
    if(nd>6) coefs[7]=h;
}

template <int nd, class T>
template <int nd2, class T2>
Pol<nd,1,T>::Pol (const Pol<nd2,1,T2> &P2) {
    coefs=P2.coefficients();
    if (coefs.size()>nd+1)
        coefs.resize(nd+1);
}

template <int nd, class T>
template <int nd_, class T_>
Pol<nd,1,T> &Pol<nd,1,T>::operator= (const Pol<nd_,1,T_> &P) {
    coefs=P.coefficients();
    return *this;
}

template <int nd, class T>
Vec<Vec<unsigned,1> > Pol<nd,1,T>::powers() const{
    Vec<Vec<unsigned,1> > res;
    res.resize(nd+1);
    for (int i=0;i<res.size();i++)
        res[i]=Vec<unsigned,1>(i);
    return res;
}

template <int nd, class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Pol<nd,1,T>::operator() (T2 x) const {
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    using namespace std;
    TR res = coefs[0];
    for(unsigned i=1;i<coefs.size();i++)
        res += TR(coefs[i]) * ::pow(TR(x),i);
    return res;
}

template <int nd, class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Pol<nd,1,T>::operator() (const Vec<T2,1> &x) const {
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    using namespace std;
    TR res = coefs[0];
    for(unsigned i=1;i<coefs.size();i++)
        res += TR(coefs[i]) * ::pow(TR(x[0]),i);
    return res;
}

template <int nd, class T>
template <class T2>
Vec<typename TypePromote<Multiplies,T,T2>::T> Pol<nd,1,T>::operator() (const Vec<T2> &V) const {
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    Vec<TR> res;
    res.resize(V.size());
    for (unsigned i=0;i<V.size();i++)
        res[i]=operator()(V[i]);
    return res;
}

template <int nd, class T>
T Pol<nd,1,T>::coef_max () const {
    T res=abs(coefs[0]);
    for (int i=1;i<=degree();i++)
        if (res<abs(coefs[i]))
            res=abs(coefs[i]);
    return res;
}

template <int nd, class T>
Pol<nd-1,1,T> Pol<nd,1,T>::derivative() const {
    Vec<T> coefficientsDerivee;
    if (degree()==0)
        coefficientsDerivee.resize(1,0);
    if (degree()>0) {
        coefficientsDerivee.resize(degree());
        for (unsigned i=0;i<coefficientsDerivee.size();i++)
            coefficientsDerivee[i]=coefs[i+1]*(i+1);
    };
    Pol<nd,1,T> res(coefficientsDerivee);
    return res;
};

template <int nd, class T>
Pol<nd,1,T> Pol<nd,1,T>::integral(const T &a) const {
    Vec<T> coefficientsintegrale;
    coefficientsintegrale.resize(degree()+2);
    coefficientsintegrale[0]=a;
    for (int i=1;i<coefficientsintegrale.size();i++)
        coefficientsintegrale[i]=coefs[i-1]/i;
    Pol<nd,1,T> res(coefficientsintegrale);
    return res;
}

template <int nd, class T>
int Pol<nd,1,T>::MaxPositivesRoots() const {
    int res=0;
    Vec<T> coefficients=coefs;
    for (unsigned i=1;i<coefficients.size();i++)
        if (coefficients[i]==0) {
            coefficients.erase_elem_nb(i);
            i--;
        }
    for (unsigned i=1;i<coefficients.size();i++)
        if (sgn(coefficients[i])!=sgn(coefficients[i-1]))
            res++;
    return res;
}

template <int nd, class T>
int Pol<nd,1,T>::MaxNegativesRoots() const {
    int res=0;
    Vec<T> coefficients=coefs;
    for (unsigned i=1;i<coefficients.size();i+=2)
        coefficients[i]=-coefficients[i];
    for (unsigned i=1;i<coefficients.size();i++)
        if (coefficients[i]==0) {
            coefficients.erase_elem_nb(i);
            i--;
        }
    for (unsigned i=1;i<coefficients.size();i++)
        if (sgn(coefficients[i])!=sgn(coefficients[i-1]))
            res++;
    return res;
}

template <int nd, class T>
T Pol<nd,1,T>::RootsUpperBound() const {
    T res=0;
    T L=1+abs(coef_max());
    Pol<nd,1,T> P=*this;
    const Vec<T> &p=P.coefficients();
    while (P.MaxPositivesRoots()>0) {
        Vec<T> q=p;
        for (int i=p.size()-2;i>=0;i--)
            q[i]=p[i]+L*q[i+1];
        Pol<nd,1,T> Q(q);
        P=Q;
        if (P.MaxPositivesRoots()==0)
            res=L;
        L=2*L;
    }
    return res;
}

template <int nd, class T>
T Pol<nd,1,T>::RootsLowerBound() const {
    T res=0;
    T L=-1-abs(coef_max());
    Pol<nd,1,T> P=*this;
    const Vec<T> &p=P.coefficients();
    while (P.MaxNegativesRoots()>0) {
        Vec<T> q=p;
        for (int i=p.size()-2;i>=0;i--)
            q[i]=p[i]+L*q[i+1];
        Pol<nd,1,T> Q(q);
        P=Q;
        if (P.MaxNegativesRoots()==0)
            res=L;
        L=2*L;
    }
    return res;
}

template <int nd, class T>
T Pol<nd,1,T>::root_dichotomy (T a,T b) const {
    if (sgn(operator()(a))==sgn(operator()(b))) {
        std::cout << "Dichotomy root research can me made only if P(a) and P(b) have opposite signs" << std::endl;
        assert(0);
    }
    T c=min(a,b);
    T e=max(a,b);
    while ((e-c)/(abs(e)+abs(c))>5*std::numeric_limits<T>::epsilon()) {
        T d=(c+e)/2;
        // cout << "e vaut " << e << endl;
        // cout << "c vaut " << c << endl;
        if (sgn(operator()(d))==sgn(operator()(c)))
            c=d;
        else
            e=d;
    }
    return (c+e)/2;
}

template <int nd, class T>
Pol<nd,1,T> Pol<nd,1,T>::remainder(const Pol<nd,1,T> &D) const {
    Vec<T> r=coefs;
    if (D.degree()<=degree()) {
        Vec<T> d=D.coefficients();
        for (unsigned i=1;i<=coefs.size()-d.size()+1;i++) {
            T aux=r[r.size()-1]/d[d.size()-1];
            r.erase_elem_nb(r.size()-1);
            for (unsigned j=0;j<d.size()-1;j++)
                r[r.size()-d.size()+j+1]-=aux*d[j];
        }
    }
    while (r.size()>1 and r[r.size()-1]==0)
        r.erase_elem_nb(r.size()-1);
    return Pol<nd,1,T>(r);
}

template <int nd, class T>
Vec<T> Pol<nd,1,T>::roots () const {
    using namespace std;
    Vec<T> res;
    res.resize(0);
    if (degree()==1)
        res.push_back(-coefs[0]/coefs[1]);
    if (degree()==2) {
        T delta=coefs[1]*coefs[1]-4*coefs[0]*coefs[2];
        if (delta==0)
            res.push_back(-0.5*coefs[1]/coefs[2]);
        if (delta>0) {
            res.push_back(-0.5*(coefs[1]+sqrt(delta))/coefs[2]);
            res.push_back(-0.5*(coefs[1]-sqrt(delta))/coefs[2]);
        };
    };
    if (degree()==3) {
        T a=coefs[2]/coefs[3];
        T b=coefs[1]/coefs[3];
        T c=coefs[0]/coefs[3];
        T p = b - ::pow(a,2)/3;
        T q = ::pow(a,3)/13.5 - a*b/3 + c;
        T delta = 4*::pow(p,3)+27*::pow(q,2);
        T trois=3;
        if (delta>=0) {
            T u=(-27*q+sqrt(27*delta))/2;
            T v=(-27*q-sqrt(27*delta))/2;
            res.push_back((sgn(u)*::pow(std::abs(u),1.0/trois)+sgn(v)*::pow(std::abs(v),1.0/trois)-a)/3);
        };
        if (delta<0) {
            complex<T> j(-1/2.,sqrt(3.)/2.);
            complex<T> v(-27.*q/2.,sqrt(-27*delta)/2.);
            complex<T> u=pow(v,1/trois);
            res.push_back((2*std::real(u)-a)/3);
            res.push_back((2*std::real(j*u)-a)/3);
            res.push_back((2*std::real(j*j*u)-a)/3);
            sort(res);
        };
    };
    if (degree()>3) {
        if (coefs[0]!=0) {
            Vec<Pol<nd-1,1,T> > Sturm(*this,derivative());
            while (Sturm[Sturm.size()-1].degree()>0)
                Sturm.push_back(-Sturm[Sturm.size()-2].remainder(Sturm[Sturm.size()-1]));
            Vec<T> X(RootsLowerBound(),RootsUpperBound());
            int diffmax=2;
            while(diffmax>1) {
                Vec<int> deltas;
                deltas.resize(X.size(),0);
                for (unsigned i=0;i<X.size();i++)
                    for (unsigned j=1;j<Sturm.size();j++)
                        if (sgn(Sturm[j-1](X[i]))!=sgn(Sturm[j](X[i])))
                            deltas[i]++;
                Vec<int> diffs;
                diffs.resize(deltas.size()/2,0);
                Vec<T> X2;
                for (unsigned i=0;i<diffs.size();i++) {
                    diffs[i]=deltas[2*i]-deltas[2*i+1];
                    if (diffs[i]==1) {
                        X2.push_back(X[2*i]);
                        X2.push_back(X[2*i+1]);
                    }
                    if (diffs[i]>1) {
                        X2.push_back(X[2*i]);
                        X2.push_back((X[2*i]+X[2*i+1])/2);
                        X2.push_back((X[2*i]+X[2*i+1])/2);
                        X2.push_back(X[2*i+1]);
                    }
                }
                diffmax=max(diffs);
                X=X2;
            }
            for (unsigned i=0;i<X.size()/2;i++) {
                T r=Newton((X[2*i]+X[2*i+1])/2);
                if (r<X[2*i] or r>X[2*i+1])
                    r=root_dichotomy(X[2*i],X[2*i+1]);
                res.push_back(r);
            };
        }
        else {
            Vec<T> aux=coefs;
            while (aux[0]==0)
                aux.erase_elem_nb(0);
            Vec<T> r=Pol<nd,1,T>(aux).roots();
            while (r.size()>0 and r[0]<0) {
                res.push_back(r[0]);
                r.erase_elem_nb(0);
            }
            res.push_back(0);
            res.append(r);
        }
    };
    return res;
}

template <int nd, class T>
T Pol<nd,1,T>::Newton (T d) const {
    T a=d;
    T b=d-1;
    Pol<nd-1,1,T> Q=derivative();
    while (abs(a-b)/max(abs(a),abs(b))>100*std::numeric_limits<T>::epsilon()) {
        T aux=a;
        b=aux;
        a=b-operator()(b)/Q(b);
    };
    return a;
}

template <int nd, class T>
bool Pol<nd,1,T>::operator== (const T &t) const {
    return bool(coefs.size()==1 and coefs[0]==t);
}

template <int nd, class T>
bool Pol<nd,1,T>::operator!= (const T &t) const {
    return bool(coefs.size()!=1 or coefs[0]!=t);
}

template <int nd, class T>
template <class T1>
bool Pol<nd,1,T>::operator== (const T1 &t) const {
    Pol<nd,1,T> G(t);
    bool b=coefs.size()==G.coefficients().size();
    bool c=coefs==G.coefficients();
    return b and c;
}

template <int nd, class T>
template <class T1>
bool Pol<nd,1,T>::operator!= (const T1 &t) const {
    Pol<nd,1,T> G(t);
    bool b=coefs.size()!=G.coefficients().size();
    bool c=coefs!=G.coefficients();
    return b or c;
}

template <int nd, class T>
template <class T2>
void Pol<nd,1,T>::operator+=(const T2 &t) {
    Pol<nd,1,T> Q(t);
    Vec<T> q=Q.coefficients();
    int tmp=coefs.size();
    coefs.resize(max(q.size(),coefs.size()));
    for (int i=0;i<tmp;i++)
        coefs[i]+=q[i];
    for (int i=tmp;i<q.size();i++)
        coefs[i]=q[i];
    while(coefs.size()>1 and coefs[coefs.size()-1]==0)
        coefs.erase_elem_nb(coefs.size()-1);
}

template <int nd, class T>
template <class T2>
void Pol<nd,1,T>::operator-=(const T2 &t) {
    Pol<nd,1,T> Q(t);
    int tmp=coefs.size();
    coefs.resize(max(Q.coefficients().size(),coefs.size()));
    for (int i=0;i<tmp;i++)
        coefs[i]-=Q.coefficients()[i];
    for (int i=tmp;i<Q.coefficients().size();i++)
        coefs[i]=-Q.coefficients()[i];
    while(coefs.size()>1 and coefs[coefs.size()-1]==0)
        coefs.erase_elem_nb(coefs.size()-1);
}

template <int nd, class T>
template <int nd2, class T2>
void Pol<nd,1,T>::operator+=(const Pol<nd2,1,T2> &Q) {
    int n1=min(Q.coefficients().size(),coefs.size());
    for (int i=0;i<n1;i++)
        coefs[i]+=Q.coefficients()[i];
    if (coefs.size()<Q.coefficients().size()) {
        coefs.resize(min(nd+1,Q.coefficients().size()));
        for (int i=n1;i<coefs.size();i++)
            coefs[i]=Q.coefficients()[i];
    }
    while(coefs.size()>1 and coefs[coefs.size()-1]==0)
        coefs.erase_elem_nb(coefs.size()-1);
}

template <int nd, class T>
template <int nd2, class T2>
void Pol<nd,1,T>::operator-=(const Pol<nd2,1,T2> &Q) {
    int n1=min(Q.coefficients().size(),coefs.size());
    for (int i=0;i<n1;i++)
        coefs[i]-=Q.coefficients()[i];
    if (coefs.size()<Q.coefficients().size()) {
        coefs.resize(min(nd+1,Q.coefficients().size()));
        for (int i=n1;i<coefs.size();i++)
            coefs[i]=-Q.coefficients()[i];
    }
    while(coefs.size()>1 and coefs[coefs.size()-1]==0)
        coefs.erase_elem_nb(coefs.size()-1);
}

template <int nd, class T>
template <class T2>
T2 Pol<nd,1,T>::troncate(const T2 &c, const T2 &d, const T2 &r, int nmax) {
    int n=0;
    T res;
    if (c==0) {
        T resplus=operator()(d)-coefs[0];
        T resmoins=operator()(-d)-coefs[0];
        res=max(abs(resplus),abs(resmoins));
        while (res>=r and n<nmax) {
            n++;
            resplus-=coefs[n]*std::pow(d,n);
            resmoins-=coefs[n]*std::pow(-d,n);
            res=max(abs(resplus),abs(resmoins));
        }
        coefs.resize(n+1);
    }
    else {
        Pol<nd,1,T> P(operator()(c));
        Pol<nd,1,T> Q=*this;
        Pol<nd,1,T> M(T(1));
        int f=1;
        res=max(abs(operator()(c+d)-operator()(c)),operator()(c-d)-operator()(c));
        while (res>=r and n<nmax) {
            n++;
            M*=Pol<nd,1,T>(-c,T(1));
            Q=(1./n)*Q.derivative();
            P+=Q(c)*M;
            res=max(abs((operator()(c+d)-P(c+d))/operator()(c+d)),abs((operator()(c-d)-P(c-d))/operator()(c-d)));
        }
        coefs=P.coefficients();
    }
    return res;
}

template <int nd, class T>
template <class T2>
void Pol<nd,1,T>::operator*=(const T2 &t) {
    Vec<T> r;
    Pol<nd,1,T> Q(t);
    Vec<T> q=Q.coefficients();
    if ((coefs.size()==1 and coefs[0]==0) or (q.size()==1 and q[0]==0))
        r.resize(1,0);
    else {
        r.resize(coefs.size()+q.size()-1,0);
        for (int i=0;i<min(q.size(),coefs.size());i++)
            for (int j=0;j<=i;j++)
                r[i]+=coefs[j]*q[i-j];
        if (q.size()>=coefs.size()) {
            for (int i=coefs.size();i<q.size();i++)
                for (int j=0;j<coefs.size();j++)
                    r[i]+=coefs[j]*q[i-j];
            for (int i=q.size();i<r.size();i++)
                for (int j=i-q.size()+1;j<coefs.size();j++)
                    r[i]+=coefs[j]*q[i-j];
        };
        if (coefs.size()>q.size()) {
            for (int i=q.size();i<coefs.size();i++)
                for (int j=0;j<q.size();j++)
                    r[i]+=q[j]*coefs[i-j];
            for (int i=coefs.size();i<r.size();i++)
                for (int j=i-coefs.size()+1;j<q.size();j++)
                    r[i]+=q[j]*coefs[i-j];
        };
    };
    coefs=r;
}

///////////////////////////////////////////////////////////////////////////////////
// DEFINITION DES FONCTIONS GLOBALES EN RAPPORT AVEC DES POLYNOMES MONOVARIABLES //
///////////////////////////////////////////////////////////////////////////////////

template <int nd1, class T1, int nd2, class T2>
bool operator==(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    bool res=0;
    if (P.coefficients().size()==Q.coefficients().size())
        if (P.coefficients()==Q.coefficients())
            res=1;
    return res;
}

template <int nd1, class T1, int nd2, class T2>
bool operator!=(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    bool res = 1;
    if (P.coefficients().size()==Q.coefficients().size())
        if (P.coefficients()==Q.coefficients())
            res=0;
    return res;
}

template <int nd1, class T1, int nd2, class T2>
Pol<(nd1>nd2?nd2:nd1),1,typename TypePromote<Plus,T1,T2>::T> operator+(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    const Vec<T1> &p=P.coefficients();
    const Vec<T2> &q=Q.coefficients();
    Vec<typename TypePromote<Plus,T1,T2>::T> r;
    r.resize(max(q.size(),p.size()));
    for (unsigned i=0;i<min(q.size(),p.size());i++)
        r[i]=p[i]+q[i];
    if (q.size()>p.size())
        for (unsigned i=p.size();i<r.size();i++)
            r[i]=q[i];
    if (p.size()>q.size())
        for (unsigned i=q.size();i<r.size();i++)
            r[i]=p[i];
    while(r.size()>1 and r[r.size()-1]==0)
        r.erase_elem_nb(r.size()-1);
    Pol<(nd1>nd2?nd2:nd1),1,typename TypePromote<Plus,T1,T2>::T> res(r);
    return res;
}

template <int nd1, int nd2, class T>
Pol<(nd1>nd2?nd2:nd1),1,T> operator+(const Pol<nd1,1,T> &P, const Pol<nd2,1,T> &Q) {
    const Vec<T> &p=P.coefficients();
    const Vec<T> &q=Q.coefficients();
    Vec<T> r;
    r.resize(max(q.size(),p.size()));
    for (unsigned i=0;i<min(q.size(),p.size());i++)
        r[i]=p[i]+q[i];
    if (q.size()>p.size())
        for (unsigned i=p.size();i<r.size();i++)
            r[i]=q[i];
    if (p.size()>q.size())
        for (unsigned i=q.size();i<r.size();i++)
            r[i]=p[i];
    while(r.size()>1 and r[r.size()-1]==0)
        r.erase_elem_nb(r.size()-1);
    Pol<(nd1>nd2?nd2:nd1),1,T> res(r);
    return res;
}

template <int nd, class T>
Pol<nd,1,T> operator+(const Pol<nd,1,T> &P, const Pol<nd,1,T> &Q) {
    const Vec<T> &p=P.coefficients();
    const Vec<T> &q=Q.coefficients();
    Vec<T> r;
    r.resize(max(q.size(),p.size()));
    for (unsigned i=0;i<min(q.size(),p.size());i++)
        r[i]=p[i]+q[i];
    if (q.size()>p.size())
        for (unsigned i=p.size();i<r.size();i++)
            r[i]=q[i];
    if (p.size()>q.size())
        for (unsigned i=q.size();i<r.size();i++)
            r[i]=p[i];
    while(r.size()>1 and r[r.size()-1]==0)
        r.erase_elem_nb(r.size()-1);
    Pol<nd,1,T> res(r);
    return res;
}

template <int nd1, class T1, class T2>
Pol<nd1,1,typename TypePromote<Plus,T1,T2>::T> operator+(const Pol<nd1,1,T1> &P, T2 t) {
    return P + Pol<nd1,1,typename TypePromote<Plus,T1,T2>::T>(t);
}

template <int nd1, class T1, class T2>
Pol<nd1,1,typename TypePromote<Plus,T1,T2>::T> operator+(T2 t, const Pol<nd1,1,T1> &P) {
    return Pol<nd1,1,typename TypePromote<Plus,T1,T2>::T>(t) + P;
}

template <int nd1, class T1, int nd2, class T2>
Pol<(nd1>nd2?nd2:nd1),1,typename TypePromote<Minus,T1,T2>::T> operator-(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    const Vec<T1> &p = P.coefficients();
    const Vec<T2> &q = Q.coefficients();
    Vec<typename TypePromote<Minus,T1,T2>::T> r;
    r.resize(max(q.size(),p.size()));
    for (int i=0;i<min(q.size(),p.size());i++)
        r[i]=p[i]-q[i];
    if (q.size()>p.size())
        for (int i=p.size();i<r.size();i++)
            r[i]=-q[i];
    if (p.size()>q.size())
        for (int i=q.size();i<r.size();i++)
            r[i]=p[i];
    while(r.size()>1 and r[r.size()-1]==0)
        r.erase_elem_nb(r.size()-1);
    Pol<(nd1>nd2?nd2:nd1),1,typename TypePromote<Minus,T1,T2>::T> res(r);
    return res;
}

template <int nd1, int nd2, class T>
Pol<(nd1>nd2?nd2:nd1),1,T> operator-(const Pol<nd1,1,T> &P, const Pol<nd2,1,T> &Q) {
    const Vec<T> &p = P.coefficients();
    const Vec<T> &q = Q.coefficients();
    Vec<T> r;
    r.resize(max(q.size(),p.size()));
    for (int i=0;i<min(q.size(),p.size());i++)
        r[i]=p[i]-q[i];
    if (q.size()>p.size())
        for (int i=p.size();i<r.size();i++)
            r[i]=-q[i];
    if (p.size()>q.size())
        for (int i=q.size();i<r.size();i++)
            r[i]=p[i];
    while(r.size()>1 and r[r.size()-1]==0)
        r.erase_elem_nb(r.size()-1);
    Pol<(nd1>nd2?nd2:nd1),1,T> res(r);
    return res;
}

template <int nd, class T>
Pol<nd,1,T> operator-(const Pol<nd,1,T> &P, const Pol<nd,1,T> &Q) {
    const Vec<T> &p = P.coefficients();
    const Vec<T> &q = Q.coefficients();
    Vec<T> r;
    r.resize(max(q.size(),p.size()));
    for (int i=0;i<min(q.size(),p.size());i++)
        r[i]=p[i]-q[i];
    if (q.size()>p.size())
        for (int i=p.size();i<r.size();i++)
            r[i]=-q[i];
    if (p.size()>q.size())
        for (int i=q.size();i<r.size();i++)
            r[i]=p[i];
    while(r.size()>1 and r[r.size()-1]==0)
        r.erase_elem_nb(r.size()-1);
    Pol<nd,1,T> res(r);
    return res;
}

template <int nd1, class T1, class T2>
Pol<nd1,1,typename TypePromote<Minus,T1,T2>::T> operator-(const Pol<nd1,1,T1> &P, T2 t) {
    return P - Pol<nd1,1,typename TypePromote<Minus,T1,T2>::T>(t);
}

template <int nd1, class T1, class T2>
Pol<nd1,1,typename TypePromote<Minus,T1,T2>::T> operator-(T2 t, const Pol<nd1,1,T1> &P) {
    return Pol<nd1,1,typename TypePromote<Minus,T1,T2>::T>(t) - P;
}

template <int nd1, class T1, int nd2, class T2>
Pol<(nd1>nd2?nd2:nd1),1,typename TypePromote<Multiplies,T1,T2>::T> operator*(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    if (P==T1(0))
        return P;
    else if (Q==T2(0))
        return Q;
    else {
        Vec<typename TypePromote<Multiplies,T1,T2>::T> r;
        const Vec<T1> &p = P.coefficients();
        const Vec<T2> &q = Q.coefficients();
        r.resize(p.size()+q.size()-1,0);
        for (int i=0;i<min(q.size(),p.size());i++)
            for (int j=0;j<=i;j++)
                r[i]+=p[j]*q[i-j];
        if (q.size()>=p.size()) {
            for (int i=p.size();i<q.size();i++)
                for (int j=0;j<p.size();j++)
                    r[i]+=p[j]*q[i-j];
            for (int i=q.size();i<r.size();i++)
                for (int j=i-q.size()+1;j<p.size();j++)
                    r[i]+=p[j]*q[i-j];
        };
        if (p.size()>q.size()) {
            for (int i=q.size();i<p.size();i++)
                for (int j=0;j<q.size();j++)
                    r[i]+=q[j]*p[i-j];
            for (int i=p.size();i<r.size();i++)
                for (int j=i-p.size()+1;j<q.size();j++)
                    r[i]+=q[j]*p[i-j];
        };
        return Pol<(nd1>nd2?nd2:nd1),1,typename TypePromote<Multiplies,T1,T2>::T>( r );
    };
}

template <int nd1, int nd2, class T>
Pol<(nd1>nd2?nd2:nd1),1,T> operator*(const Pol<nd1,1,T> &P, const Pol<nd2,1,T> &Q) {
    if (P==T(0))
        return P;
    else if (Q==T(0))
        return Q;
    else {
        Vec<T> r;
        const Vec<T> &p = P.coefficients();
        const Vec<T> &q = Q.coefficients();
        r.resize(p.size()+q.size()-1,0);
        for (int i=0;i<min(q.size(),p.size());i++)
            for (int j=0;j<=i;j++)
                r[i]+=p[j]*q[i-j];
        if (q.size()>=p.size()) {
            for (int i=p.size();i<q.size();i++)
                for (int j=0;j<p.size();j++)
                    r[i]+=p[j]*q[i-j];
            for (int i=q.size();i<r.size();i++)
                for (int j=i-q.size()+1;j<p.size();j++)
                    r[i]+=p[j]*q[i-j];
        };
        if (p.size()>q.size()) {
            for (int i=q.size();i<p.size();i++)
                for (int j=0;j<q.size();j++)
                    r[i]+=q[j]*p[i-j];
            for (int i=p.size();i<r.size();i++)
                for (int j=i-p.size()+1;j<q.size();j++)
                    r[i]+=q[j]*p[i-j];
        };
        return Pol<nd1+nd2,1,T>( r );
    };
}

template <int nd, class T>
Pol<nd,1,T> operator*(const Pol<nd,1,T> &P, const Pol<nd,1,T> &Q) {
    if (P==T(0))
        return P;
    else if (Q==T(0))
        return Q;
    else {
        Vec<T> r;
        const Vec<T> &p = P.coefficients();
        const Vec<T> &q = Q.coefficients();
        r.resize(p.size()+q.size()-1,0);
        for (int i=0;i<min(q.size(),p.size());i++)
            for (int j=0;j<=i;j++)
                r[i]+=p[j]*q[i-j];
        if (q.size()>=p.size()) {
            for (int i=p.size();i<q.size();i++)
                for (int j=0;j<p.size();j++)
                    r[i]+=p[j]*q[i-j];
            for (int i=q.size();i<r.size();i++)
                for (int j=i-q.size()+1;j<p.size();j++)
                    r[i]+=p[j]*q[i-j];
        };
        if (p.size()>q.size()) {
            for (int i=q.size();i<p.size();i++)
                for (int j=0;j<q.size();j++)
                    r[i]+=q[j]*p[i-j];
            for (int i=p.size();i<r.size();i++)
                for (int j=i-p.size()+1;j<q.size();j++)
                    r[i]+=q[j]*p[i-j];
        };
        return Pol<nd,1,T>( r );
    };
}

// template <int nd1, class T1, class T2>
// Pol<1,typename TypePromote<Multiplies,T1,T2>::T> operator*(const Pol<nd1,1,T1> &P, T2 t) {
//     Pol<nd2,1,T2> Q(t);
//     return P*Q;
// }

template <int nd1, class T>
Pol<nd1,1,T> operator*(const T &t, const Pol<nd1,1,T> &P) {
    return Pol<nd1,1,T>(Vec<T>(t*P.coefficients()));
}

template <int nd1, class T1, class T2>
Pol<nd1,1,typename TypePromote<Multiplies,T1,T2>::T> operator*(const T2 &t, const Pol<nd1,1,T1> &P) {
    return Pol<nd1,1,typename TypePromote<Multiplies,T1,T2>::T>(t) * P;
}

// template <int nd1, class T1, int nd2, class T2>
// Pol<nd1,1,typename TypePromote<Multiplies,T1,T2>::T> operator*(T2 t, const Pol<nd1,1,T1> &P) {
// PRINT(__LINE__);
//     Pol<nd1,1,T2> Q(t);
//     return Q*P;
// }

template <int nd1, class T1, int nd2, class T2>
Pol<(nd1>nd2?nd2:nd1),1,typename TypePromote<Divides,T1,T2>::T> operator/(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    if (P==T1(0))
        return P;
    else {
        Vec<typename TypePromote<Divides,T1,T2>::T> r,a,b;
        r.resize((nd1>nd2?nd2:nd1)+1,0.);
        a.resize((nd1>nd2?nd2:nd1)+1,0.);
        b.resize((nd1>nd2?nd2:nd1),0.);
        const Vec<T1> &p=P.coefficients();
        const Vec<T2> &q=Q.coefficients();
        a[0]=1/q[0];
        for (int k=1;k<a.size();k++) {
            for (int s=0;s<k;s++)
                b[k-1]+=a[s]*a[k-1-s];
            for (int i=max(k-int(q.size())+1,0);i<k;i++)
                a[k]+=((i-k)/T2(k))*q[k-i]*b[i];
        }
        for (int i=0;i<p.size();i++)
            for (int j=0;j<=i;j++)
                r[i]+=p[j]*a[i-j];
        for (int i=p.size();i<a.size();i++)
            for (int j=0;j<p.size();j++)
                r[i]+=p[j]*a[i-j];
        return Pol<(nd1>nd2?nd2:nd1),1,typename TypePromote<Divides,T1,T2>::T>(r);
    }
}

template <int nd1, int nd2, class T>
Pol<(nd1>nd2?nd2:nd1),1,T> operator/(const Pol<nd1,1,T> &P, const Pol<nd2,1,T> &Q) {
    if (P==T(0))
        return P;
    else {
        Vec<T> r,a,b;
        r.resize((nd1>nd2?nd2:nd1)+1,0.);
        a.resize((nd1>nd2?nd2:nd1)+1,0.);
        b.resize((nd1>nd2?nd2:nd1),0.);
        const Vec<T> &p=P.coefficients();
        const Vec<T> &q=Q.coefficients();
        a[0]=1/q[0];
        for (int k=1;k<a.size();k++) {
            for (int s=0;s<k;s++)
                b[k-1]+=a[s]*a[k-1-s];
            for (int i=max(k-int(q.size())+1,0);i<k;i++)
                a[k]+=((i-k)/T(k))*q[k-i]*b[i];
        }
        for (int i=0;i<p.size();i++)
            for (int j=0;j<=i;j++)
                r[i]+=p[j]*a[i-j];
        for (int i=p.size();i<a.size();i++)
            for (int j=0;j<p.size();j++)
                r[i]+=p[j]*a[i-j];
        return Pol<(nd1>nd2?nd2:nd1),1,T>(r);
    }
}

template <int nd, class T>
Pol<nd,1,T> operator/(const Pol<nd,1,T> &P, const Pol<nd,1,T> &Q) {
    if (P==T(0))
        return P;
    else {
        Vec<T> r,a,b;
        r.resize(nd+1,0.);
        a.resize(nd+1,0.);
        b.resize(nd,0.);
        const Vec<T> &p=P.coefficients();
        const Vec<T> &q=Q.coefficients();
        a[0]=1/q[0];
        for (int k=1;k<a.size();k++) {
            for (int s=0;s<k;s++)
                b[k-1]+=a[s]*a[k-1-s];
            for (int i=max(k-int(q.size())+1,0);i<k;i++)
                a[k]+=((i-k)/T(k))*q[k-i]*b[i];
        }
        for (int i=0;i<p.size();i++)
            for (int j=0;j<=i;j++)
                r[i]+=p[j]*a[i-j];
        for (int i=p.size();i<a.size();i++)
            for (int j=0;j<p.size();j++)
                r[i]+=p[j]*a[i-j];
        return Pol<nd,1,T>(r);
    }
}

// template <int nd1, class T1, int nd2, class T2>
// Pol<nd1,1,typename TypePromote<Divides,T1,T2>::T> operator/(const Pol<nd1,1,T1> &P, T2 t) {
//     Pol<nd1,1,T2> Q(t);
//     return P/Q;
// }

template <int nd1, class T1, class T2>
Pol<nd1,1,typename TypePromote<Divides,T1,T2>::T> operator/( T2 t, const Pol<nd1,1,T1> &P ) {
    return Pol<nd1,1,typename TypePromote<Divides,T1,T2>::T>( t ) / P;
}

template <int nd, class T>
Pol<nd,1,T> pow(const Pol<nd,1,T> &P, int a) {
    Pol<nd,1,T> res = P;
    for (int i=1;i<a;i++)
        res = res * P;
    return res;
}

template <int nd, class T>
void plot (const Pol<nd,1,T> &P, std::string s="w l") {
    T A = P.RootsLowerBound();
    T B = P.RootsUpperBound();
    Vec<T> V = range(A,(B-A)/500,B);
    GnuPlot gp;
    gp.plot(V,P(V),s.c_str());
    gp.wait();
}

template <int nd, class T>
void plot (const Pol<nd,1,T> &P, const Vec<T> &V, const std::string &s="w l") {
    //Affiche la fonction
    GnuPlot gp;
    gp.plot(V,P(V),s.c_str());
    gp.wait();
}

template <int nd, class T>
void plot (const Pol<nd,1,T> &P, const Pol<nd,1,T> &Q, const Vec<T> &V, const std::string &s="w l") {
    //Affiche la fonction
    GnuPlot gp;
    gp.plot(V,P(V),Q(V),s.c_str());
    gp.wait();
}

template <int nd, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,1,T> &P) {
    os << " " << P.coefficients()[0] << " ";
    for (unsigned j=1;j<P.coefficients().size();j++) {
        if (P.coefficients()[j]>=0)
            os << "+" << P.coefficients()[j] << "*X^" << j << " ";
        if (P.coefficients()[j]<0)
            os << "-" << -P.coefficients()[j] << "*X^" << j << " ";
    }
    os << " ";
    return os;
}

/////////////////////////////////////////
// LE TRUC QU'HUGO M'A DIT DE RAJOUTER //
/////////////////////////////////////////

template<int m, int n,class TT> struct TypeInformation<Pol<m,n,TT> > {
    static const int res = TypeInformation<TT>::res;
    static const int englobing = 1 + TypeInformation<TT>::englobing;
    typedef TT SubType;
    template<class TV> struct Variant { typedef Pol<m,n,TV> T; };
    template<class TV> struct DeepVariant { typedef Pol<m,n,class TypeInformation<TT>::template DeepVariant<TV>::T> T; };
    static std::string type() { return "Pol<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};

template<int m, int n,class TT> struct HasTypeInformation<Pol<m,n,TT> > { static const bool res = true; };

}

#endif // POLYNOMIALS_H
