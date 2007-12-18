////////////////////////////////////
//  Author : Camille GOUTTEBROZE  //
//  gouttebroze@lmt.ens-cachan.fr //
////////////////////////////////////

#ifndef RATIONAL_FONCTIONS_H
#define RATIONAL_FONCTIONS_H

#include <complex>
#include <containers/mat.h>
#include <containers/polynomials.h>

namespace LMT {

/**
  @author Gouttebroze
*/

template <int nd=4, int nx=1, class T=double>
class Rat {
private:
    Vec<T> num;
    Vec<T> den;
    template <int nx_> Vec<unsigned,nx_> next_power(const Vec<unsigned,nx_> &v, int dmaxi);
    Vec<unsigned,1> next_power(const Vec<unsigned,1> &v, int dmaxi);
    static bool init;
    void initialize();
public:
    static Vec<Vec<unsigned,nx> > puissances;
    static Vec<Vec<Vec<unsigned,2> > > mult;
    static Vec<Vec<Vec<unsigned,2> > > mult_comp;
    static Vec<Vec<unsigned> > deriv_var;
    static Vec<Vec<unsigned> > deriv_ind;
    static Vec<Vec<T> > deriv_coef;
public:
    Rat ();
//     template <class T2> Rat (const T2 &a); //Construit la fonction rationnelle constant egal a a
    Rat (const T &a); ///Construit la fonction rationnelle constant egal a a
    Rat (int a); ///Construit la fonction rationnelle constant egal a a
    Rat (unsigned int a); ///Construit la fonction rationnelle constant egal a a
    Rat (const Vec<T> &V, const Vec<T> &W); ///Construit la fonction rationnelle a partir de ses coefficients
    Rat (const Pol<nd,nx,T> &P); ///Construit la fonction rationnelle a partir d'un polynome
    template <class T2> Rat (const Rat<nd,nx,T2> &P); ///Construit une fonction rationnelle a partir d'une autre fonction rationnelle de meme degre
//     template <int nd2> Rat (const Rat<nd2,nx,T> &P); Construit une fonction rationnelle a partir d'une fonction rationnelle de degre maximal different
    template <class T2> Rat<nd,nx,T> &operator= (const Rat<nd,nx,T2> &P); ///Renvoie une fonction rationnelle egal a P
    const Vec<T> &numerator() const {return num;} ///Renvoie les coefficients de la fonction rationnelle
    const Vec<T> &denominator() const {return den;} ///Renvoie les coefficients de la fonction rationnelle
    const Vec<Vec<unsigned,nx> > &powers() const {return puissances;} ///Renvoie les puissances de la fonction rationnelle
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,nx> &V) const; /// Renvoie la valeur de la fonction rationnelle en V
    Vec<Rat<2*nd,nx,T>,nx> derivative() const; ///Renvoie les polynomes derives
    operator bool() const {return true;};
    Rat<nd,nx,T> operator-() const; ///Renvoie la fonction rationnelle oppose;
    template <class T2> bool operator== (const Rat<nd,nx,T2> &P) const; /// Verifie si la fonction rationnelle est egal a P
    template <class T2> bool operator!= (const Rat<nd,nx,T2> &P) const; /// Verifie si la fonction rationnelle est different de P
    template <class T2> void operator+= (const Rat<nd,nx,T2> &Q); /// Ajoute Q au polynome
    template <class T2> void operator-= (const Rat<nd,nx,T2> &Q); /// Retranche Q au polynome
};

template <int nd, int nx, class T>
bool Rat<nd,nx,T>::init=1;

template <int nd, int nx, class T>
Vec<Vec<unsigned,nx> > Rat<nd,nx,T>::puissances;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned,2> > > Rat<nd,nx,T>::mult;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned,2> > > Rat<nd,nx,T>::mult_comp;

template <int nd, int nx, class T>
Vec<Vec<unsigned> > Rat<nd,nx,T>::deriv_var;

template <int nd, int nx, class T>
Vec<Vec<unsigned> > Rat<nd,nx,T>::deriv_ind;

template <int nd, int nx, class T>
Vec<Vec<T> > Rat<nd,nx,T>::deriv_coef;

template <int nd, int nx, class T>
template <int nx_>
Vec<unsigned,nx_> Rat<nd,nx,T>::next_power(const Vec<unsigned,nx_> &v, int dmaxi=nd) {
    Vec<unsigned,nx_> res=v;
    unsigned tmp=res[0];
    for (unsigned i=1;i<res.size();i++)
        tmp+=res[i];
    if (tmp<dmaxi) {
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
Vec<unsigned,1> Rat<nd,nx,T>::next_power(const Vec<unsigned,1> &v, int dmaxi=nd) {
    Vec<unsigned,1> res=v;
    res[0]++;
    return res;
}

template <int nd, int nx, class T>
void Rat<nd,nx,T>::initialize() {

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
    while (puissances_derivee[puissances_derivee.size()-1][nx-1]<max(nd-1,0)) {
        puissances_derivee.resize(puissances_derivee.size()+1);
        puissances_derivee[puissances_derivee.size()-1]=next_power(puissances_derivee[puissances_derivee.size()-2],nd-1);
//         puissances_derivee.append(next_power(puissances_derivee[puissances_derivee.size()-1],nd-1));
    }

    //Calcul intermediaire des puissances pour la multiplication complete
    Vec<Vec<unsigned,nx> > puissances_mult_comp;
    puissances_mult_comp.resize(1);
    puissances_mult_comp[0].set(0);
    while (puissances_mult_comp[puissances_mult_comp.size()-1][nx-1]<max(2*nd,0)) {
        puissances_mult_comp.resize(puissances_mult_comp.size()+1);
        puissances_mult_comp[puissances_mult_comp.size()-1]=next_power(puissances_mult_comp[puissances_mult_comp.size()-2],nd-1);
//         puissances_mult_comp.append(next_power(puissances_mult_comp[puissances_mult_comp.size()-1],nd-1));
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

    //Calcul des indices intermediaires pour la multiplication complete
    Vec<Vec<Vec<unsigned,2*nd+1>,2*nd+1>,nx> tmp_mult_comp;
    for (unsigned j=0;j<=2*nd;j++)
        for (unsigned k=0;k<=2*nd;k++)
            tmp_mult_comp[0][j][k]=k;
    for (unsigned i=1;i<nx;i++)
        for (unsigned j=0;j<=2*nd;j++)
            for (unsigned k=0;k<=2*nd;k++) {
                tmp_mult_comp[i][j][k]=k;
                for (unsigned s=j+1-k;s<=j;s++)
                    tmp_mult_comp[i][j][k]+=tmp_mult_comp[i-1][s][s];
            }

    //Calcul des indices pour le terme constant
    mult.resize(puissances.size());
    mult_comp.resize(puissances_mult_comp.size());
    deriv_var.resize(puissances.size());
    deriv_ind.resize(puissances.size());
    deriv_coef.resize(puissances.size());
    mult[0].resize(1);
    mult[0][0][0]=0;
    mult[0][0][1]=0;

    //Calcul des indices et coefficients pour les termes non constant
    for (unsigned i=1;i<puissances.size();i++) {

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

    //Calcul des indices pour la multiplication complete
    for (unsigned i=0;i<puissances_mult_comp.size();i++) {
        for (unsigned alphas=0;alphas<puissances_mult_comp.size();alphas++) {
            if (min(puissances_mult_comp[alphas]<=puissances_mult_comp[i])) {
                unsigned c1=0;
                unsigned c2=0;
                for (unsigned a=0;a<nx;a++) {
                    unsigned aux1=0;
                    unsigned aux2=0;
                    for (unsigned gamma=a+1;gamma<nx;gamma++) {
                        aux1+=puissances_mult_comp[i][gamma]-puissances_mult_comp[alphas][gamma];
                        aux2+=puissances_mult_comp[alphas][gamma];
                    }
                    c1+=tmp_mult_comp[a][2*nd-aux1][puissances_mult_comp[i][a]-puissances_mult_comp[alphas][a]];
                    c2+=tmp_mult_comp[a][2*nd-aux2][puissances_mult_comp[alphas][a]];
                }
                Vec<unsigned,2> aux;
                aux[0]=c1;
                aux[1]=c2;
                mult_comp[i].resize(mult_comp[i].size()+1);
                mult_comp[i][mult_comp[i].size()-1]=aux;
            }
        }
    }

}

template <int nd, int nx, class T>
Rat<nd,nx,T>::Rat() {
    if (init)
        initialize();
}

// template <int nd, int nx, class T>
// template <class T2>
// Rat<nd,nx,T>::Rat(const T2 &a) {
//     if (init)
//         initialize();
//     coefs.resize(puissances.size(),T(0));
//     coefs[0]=a;
// }

template <int nd, int nx, class T>
Rat<nd,nx,T>::Rat(const T &a) {
    if (init)
        initialize();
    num.resize(puissances.size(),T(0));
    den.resize(puissances.size(),T(0));
    num[0]=a;
    den[0]=1;
}

template <int nd, int nx, class T>
Rat<nd,nx,T>::Rat(int a) {
    if (init)
        initialize();
    num.resize(puissances.size(),T(0));
    den.resize(puissances.size(),T(0));
    num[0]=a;
    den[0]=1;
}

template <int nd, int nx, class T>
Rat<nd,nx,T>::Rat(unsigned int a) {
    if (init)
        initialize();
    num.resize(puissances.size(),T(0));
    den.resize(puissances.size(),T(0));
    num[0]=a;
    den[0]=1;
}

template <int nd, int nx, class T>
Rat<nd,nx,T>::Rat(const Vec<T> &V, const Vec<T> &W) {
    if (init)
        initialize();
    num=V;
    den=W;
}

template <int nd, int nx, class T>
Rat<nd,nx,T>::Rat(const Pol<nd,nx,T> &P) {
    if (init)
        initialize();
    num.resize(puissances.size(),T(0));
    Vec<int> r=range(0,int(P.coefficients().size()));
    num[r]=P.coefficients();
    den.resize(puissances.size(),T(0));
    den[0]=1;
}


template <int nd, int nx, class T>
template <class T2>
Rat<nd,nx,T>::Rat(const Rat<nd,nx,T2> &P) {
    if (init)
        initialize();
    num=P.numerator();
    den=P.denominator();
}

// template <int nd, int nx, class T>
// template <int nd2>
// Rat<nd,nx,T>::Rat(const Rat<nd2,nx,T> &P) {
//     assert(0);
// }

template <int nd, int nx, class T>
template <class T2>
Rat<nd,nx,T> &Rat<nd,nx,T>::operator= (const Rat<nd,nx,T2> &P) {
    num=P.numerator();
    den=P.denominator();
    return *this;
}


template <int nd, int nx, class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Rat<nd,nx,T>::operator() (const Vec<T2,nx> &V) const {
//     typedef typename TypePromote<Multiplies,T,T2>::T T_;
//     T_ res=num[0];
//     for (unsigned i=1;i<num.size();i++) {
//         T_ tmp=num[i];
//         for (int k=0;k<nx;k++)
//             tmp*=pow(V[k],int(puissances[i][k]));
//         res+=tmp;
//     }
//     return res;
    typedef typename TypePromote<Multiplies,T,T2>::T T_;
    T_ res_num=num[0];
    T_ res_den=den[0];
    for (unsigned i=1;i<puissances.size();i++) {
        T_ tmp_num=num[i];
        T_ tmp_den=den[i];
        for (int k=0;k<nx;k++) {
            tmp_num*=std::pow(V[k],int(puissances[i][k]));
            tmp_den*=std::pow(V[k],int(puissances[i][k]));
        }
        res_num+=tmp_num;
        res_den+=tmp_den;
    }
    return res_num/res_den;
}

template <int nd, int nx, class T>
Vec<Rat<2*nd,nx,T>,nx> Rat<nd,nx,T>::derivative() const {
PRINT("VERSION NON OPTIMISEE DE LA DERIVATION DES FONCTIONS RATIONNELLES");
    Vec<Rat<2*nd,nx,T>,nx> res;
    Vec<Vec<T>,nx> res_num;
    Vec<Vec<T>,nx> deriv_num;
    Vec<Vec<T>,nx> deriv_den;
    Vec<T> res_den;
    Vec<T> long_num=num;
    Vec<T> long_den=den;
    for (int i=0;i<nx;i++) {
        res_num[i].resize(res[i].puissances.size(),T(0));
        deriv_num[i].resize(res[i].puissances.size(),T(0));
        deriv_den[i].resize(res[i].puissances.size(),T(0));
    }
    res_den.resize(mult_comp.size(),T(0));
    long_num.resize(mult_comp.size(),T(0));
    long_den.resize(mult_comp.size(),T(0));
    for (int i=1;i<deriv_ind.size();i++)
        for (int j=0;j<deriv_ind[i].size();j++) {
            deriv_num[deriv_var[i][j]][deriv_ind[i][j]]=deriv_coef[i][j]*num[i];
            deriv_den[deriv_var[i][j]][deriv_ind[i][j]]=deriv_coef[i][j]*den[i];
        }
    for (int i=0;i<res_den.size();i++) 
        for (int j=0;j<mult_comp[i].size();j++)
            res_den[i]+=long_den[mult_comp[i][j][0]]*long_den[mult_comp[i][j][1]];
    for (int k=0;k<nx;k++) {
        for (int i=0;i<res_num[k].size();i++) 
            for (int j=0;j<mult_comp[i].size();j++)
                res_num[k][i]+=deriv_num[k][mult_comp[i][j][0]]*long_den[mult_comp[i][j][1]]-long_num[mult_comp[i][j][0]]*deriv_den[k][mult_comp[i][j][1]];
        res[k]=Rat<2*nd,nx,T>(res_num[k],res_den);
        }
    return res;
}

template <int nd, int nx, class T>
Rat<nd,nx,T> Rat<nd,nx,T>::operator-() const {
    return Rat<nd,nx,T>(-num,den);
}

template <int nd, int nx, class T>
template <class T2>
bool Rat<nd,nx,T>::operator== (const Rat<nd,nx,T2> &P) const {
    return bool(num==P.numerator())&&bool(den==P.denominator());
}

template <int nd, int nx, class T>
template <class T2>
bool Rat<nd,nx,T>::operator!= (const Rat<nd,nx,T2> &P) const {
    return bool(num!=P.numerator())||bool(den!=P.denominator());
}

template <int nd, int nx, class T>
template <class T2>
void Rat<nd,nx,T>::operator+= (const Rat<nd,nx,T2> &Q) {
    Vec<T> oldnum=num;
    Vec<T> oldden=den;
    num.set(T(0));
    den.set(T(0));
    for (int i=0;i<num.size();i++) {
        for (int j=0;j<mult[i].size();j++) {
            num[i]+=oldnum[mult[i][j][0]]*Q.denominator()[mult[i][j][1]]+oldden[mult[i][j][0]]*Q.numerator()[mult[i][j][1]];
            den[i]+=oldden[mult[i][j][0]]*Q.denominator()[mult[i][j][1]];
        }
    }
    num/=den[0];
    den/=den[0];
}

template <int nd, int nx, class T>
template <class T2>
void Rat<nd,nx,T>::operator-= (const Rat<nd,nx,T2> &Q) {
    Vec<T> oldnum=num;
    Vec<T> oldden=den;
    num.set(T(0));
    den.set(T(0));
    for (int i=0;i<num.size();i++) 
        for (int j=0;j<mult[i].size();j++) {
            num[i]+=oldnum[mult[i][j][0]]*Q.denominator()[mult[i][j][1]]-oldden[mult[i][j][0]]*Q.numerator()[mult[i][j][1]];
            den[i]+=oldden[mult[i][j][0]]*Q.denominator()[mult[i][j][1]];
        }
    num/=den[0];
    den/=den[0];
}

/////////////////////////////////////////////////////////////////////
// DEFINITION DES FONCTIONS GLOBALES EN RAPPORT AVEC DES POLYNOMES //
/////////////////////////////////////////////////////////////////////

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator+(const Rat<nd,nx,T1> &P, const Rat<nd,nx,T2> &Q) {
    typedef typename TypePromote<Plus,T1,T2>::T T;
    Vec<T> res_num;
    Vec<T> res_den;
    res_num.resize(P.puissances.size(),T(0));
    res_den.resize(P.puissances.size(),T(0));
    for (int i=0;i<res_num.size();i++) 
        for (int j=0;j<P.mult[i].size();j++) {
            res_num[i]+=P.numerator()[P.mult[i][j][0]]*Q.denominator()[P.mult[i][j][1]]+Q.numerator()[P.mult[i][j][0]]*P.denominator()[P.mult[i][j][1]];
            res_den[i]+=P.denominator()[P.mult[i][j][0]]*Q.denominator()[P.mult[i][j][1]];
        }
    return Rat<nd,nx,T>(res_num/res_den[0],res_den/res_den[0]);
}

// template <int nx, int nd1, class T1, int nd2, class T2>
// Rat<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Plus,T1,T2>::T> operator+(const Rat<nd1,nx,T1> &P, const Rat<nd2,nx,T2> &Q) {
//     return (nd1>nd2?Rat<nd2,nx,T1>(P)+Q:P+Rat<nd1,nx,T1>(Q));
// }

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator-(const Rat<nd,nx,T1> &P, const Rat<nd,nx,T2> &Q) {
    typedef typename TypePromote<Plus,T1,T2>::T T;
    Vec<T> res_num;
    Vec<T> res_den;
    res_num.resize(P.puissances.size(),T(0));
    res_den.resize(P.puissances.size(),T(0));
    for (int i=0;i<res_num.size();i++) 
        for (int j=0;j<P.mult[i].size();j++) {
            res_num[i]+=P.numerator()[P.mult[i][j][0]]*Q.denominator()[P.mult[i][j][1]]-Q.numerator()[P.mult[i][j][0]]*P.denominator()[P.mult[i][j][1]];
            res_den[i]+=P.denominator()[P.mult[i][j][0]]*Q.denominator()[P.mult[i][j][1]];
        }
    return Rat<nd,nx,T>(res_num/res_den[0],res_den/res_den[0]);
}

// template <int nx, int nd1, class T1, int nd2, class T2>
// Rat<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Plus,T1,T2>::T> operator-(const Rat<nd1,nx,T1> &P, const Rat<nd2,nx,T2> &Q) {
//     return (nd1>nd2?Rat<nd2,nx,T1>(P)-Q:P-Rat<nd1,nx,T1>(Q));
// }

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator*(const Rat<nd,nx,T1> &P, const Rat<nd,nx,T2> &Q) {
    typedef typename TypePromote<Plus,T1,T2>::T T;
    Vec<T> res_num;
    Vec<T> res_den;
    res_num.resize(P.puissances.size(),T(0));
    res_den.resize(P.puissances.size(),T(0));
    for (int i=0;i<res_num.size();i++) 
        for (int j=0;j<P.mult[i].size();j++) {
            res_num[i]+=P.numerator()[P.mult[i][j][0]]*Q.numerator()[P.mult[i][j][1]];
            res_den[i]+=P.denominator()[P.mult[i][j][0]]*Q.denominator()[P.mult[i][j][1]];
        }
    return Rat<nd,nx,T>(res_num/res_den[0],res_den/res_den[0]);
}

// template <int nx, int nd1, class T1, int nd2, class T2>
// Rat<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Plus,T1,T2>::T> operator*(const Rat<nd1,nx,T1> &P, const Rat<nd2,nx,T2> &Q) {
//     return (nd1>nd2?Rat<nd2,nx,T1>(P)*Q:P*Rat<nd1,nx,T1>(Q));
// }

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator/(const Rat<nd,nx,T1> &P, const Rat<nd,nx,T2> &Q) {
    typedef typename TypePromote<Plus,T1,T2>::T T;
    Vec<T> res_num;
    Vec<T> res_den;
    res_num.resize(P.puissances.size(),T(0));
    res_den.resize(P.puissances.size(),T(0));
    for (int i=0;i<res_num.size();i++) 
        for (int j=0;j<P.mult[i].size();j++) {
            res_num[i]+=P.numerator()[P.mult[i][j][0]]*Q.denominator()[P.mult[i][j][1]];
            res_den[i]+=P.denominator()[P.mult[i][j][0]]*Q.numerator()[P.mult[i][j][1]];
        }
    return Rat<nd,nx,T>(res_num/res_den[0],res_den/res_den[0]);
}

// template <int nx, int nd1, class T1, int nd2, class T2>
// Rat<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Plus,T1,T2>::T> operator/(const Rat<nd1,nx,T1> &P, const Rat<nd2,nx,T2> &Q) {
//     return (nd1>nd2?Rat<nd2,nx,T1>(P)/Q:P/Rat<nd1,nx,T1>(Q));
// }

template <int nd, int nx, class T>
Rat<nd,nx,T> operator*(const Rat<nd,nx,T> &P, const T &t) {
    return Rat<nd,nx,T> (Vec<T>(P.coefficients()*t));
}

template <int nd, int nx, class T>
Rat<nd,nx,T> operator*(const T &t, const Rat<nd,nx,T> &P) {
    return Rat<nd,nx,T> (Vec<T>(t*P.numerator()),P.denominator());
}

template <int nd, int nx, class T>
typename TypePromote<Abs,T>::T abs_indication(const Rat<nd,nx,T> &P) {
    return abs_indication(P.numerator()[0]);
}

template <int nd, int nx, class T>
Rat<nd,nx,typename TypePromote<Conj,T>::T> conj( const Rat<nd,nx,T> &P ) {
    return Rat<nd,nx,typename TypePromote<Conj,T>::T>( conj(P.coefficients()) );
}

template <int nd, int nx, class T>
Rat<nd,nx,typename TypePromote<Real,T>::T> real(const Rat<nd,nx,T> &P) {
    return Rat<nd,nx,typename TypePromote<Real,T>::T>( real(P.coefficients()) );
}

template <int nd, int nx, class T>
Rat<nd,nx,typename TypePromote<Imag,T>::T> imag(const Rat<nd,nx,T> &P) {
    return Rat<nd,nx,typename TypePromote<Imag,T>::T>( imag(P.coefficients()) );
}

template <int nd, int nx, class T>
std::ostream &operator<<(std::ostream &os, const Rat<nd,nx,T> &P) {
    os << " " << P.numerator()[0] << " ";
    for (unsigned i=1;i<P.numerator().size();i++) {
        if (P.numerator()[i]>0) {
            os << "+" << P.numerator()[i];
            for (int j=0;j<nx;j++)
                if(P.puissances[i][j]>0)
                    os << "*X" << j << "^" << P.puissances[i][j];
            os << " ";
        }
        if (P.numerator()[i]<0) {
            os << "-" << -P.numerator()[i];
            for (int j=0;j<nx;j++)
                if(P.puissances[i][j]>0)
                    os << "*X" << j << "^" << P.puissances[i][j];
            os << " ";
        }
    }
    os << "/ " << P.denominator()[0] << " ";
    for (unsigned i=1;i<P.denominator().size();i++) {
        if (P.denominator()[i]>0) {
            os << "+" << P.denominator()[i];
            for (int j=0;j<nx;j++)
                if(P.puissances[i][j]>0)
                    os << "*X" << j << "^" << P.puissances[i][j];
            os << " ";
        }
        if (P.denominator()[i]<0) {
            os << "-" << -P.denominator()[i];
            for (int j=0;j<nx;j++)
                if(P.puissances[i][j]>0)
                    os << "*X" << j << "^" << P.puissances[i][j];
            os << " ";
        }
    }
    os << " ";
    return os;
}

template <int nd, int nx, class T>
std::ostream &operator<<(std::ostream &os, const Rat<nd,nx,std::complex<T> > &P) {
    os << " " << P.numerator()[0] << " ";
    for (unsigned i=1;i<P.numerator().size();i++) {
        if (P.numerator()[i]!=std::complex<T>(0)) {
            os << "+" << P.numerator()[i];
            for (int j=0;j<nx;j++)
                if(P.puissances[i][j]>0)
                    os << "*X" << j << "^" << P.puissances[i][j];
            os << " ";
        }
    }
    os << "/ " << P.denominator()[0] << " ";
    for (unsigned i=1;i<P.denominator().size();i++) {
        if (P.denominator()[i]!=std::complex<T>(0)) {
            os << "+" << P.denominator()[i];
            for (int j=0;j<nx;j++)
                if(P.puissances[i][j]>0)
                    os << "*X" << j << "^" << P.puissances[i][j];
            os << " ";
        }
    }
    os << " ";
    return os;
}

template<int m, int n,class TT> struct TypeInformation<Rat<m,n,TT> > {
    static const int res = TypeInformation<TT>::res;
    static const int englobing = 1 + TypeInformation<TT>::englobing;
    typedef TT SubType;
    template<class TV> struct Variant { typedef Rat<m,n,TV> T; };
    template<class TV> struct DeepVariant { typedef Rat<m,n,class TypeInformation<TT>::template DeepVariant<TV>::T> T; };
    static std::string type() { return "Rat<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};

template<int m, int n,class TT> struct HasTypeInformation<Rat<m,n,TT> > { static const bool res = true; };

}

#endif // RATIONAL_FONCTIONS_H
