print """// file generated from poynomials.h.py. Do not modify

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
#include <containers/vec.h>
#include <containers/algo.h>

namespace LMT {

/**
  @author Gouttebroze
*/

template <unsigned int nd, unsigned int nf>
struct Factorielle {
   enum { valeur = nf * Factorielle<nd,nf-1>::valeur };
};

template <unsigned int nd>
struct Factorielle<nd,nd> {
   enum { valeur = nd };
};

template <unsigned int N>
struct Deux_Puissance {
   enum { valeur = 2 * Deux_Puissance<N-1>::valeur };
};

template <>
struct Deux_Puissance<0> {
   enum { valeur = 1 };
};

/////////////////////////////////////////////////////////////////////////////////
// DEFINITION DE LA CLASSE POLYNOME MULTIVARIABLES ET DE SES FONCTIONS MEMBRES //
/////////////////////////////////////////////////////////////////////////////////

template <int nd=4,int nx=1,class T=double>
class Pol {
public:
    static const int degree=nd;
    static const int dim=Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur;
private:
    Vec<T,dim> coefs;
    template <int nx_> static Vec<unsigned,nx_> next_power(const Vec<unsigned,nx_> &v, int dmaxi);
    static Vec<unsigned,1> next_power(const Vec<unsigned,1> &v, int dmaxi);
    static bool init_deriv;
    static void initialize_deriv();
    static Vec<Vec<unsigned>,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> deriv_var;
    static Vec<Vec<unsigned>,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> deriv_ind;
    static Vec<Vec<T>,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> deriv_coef;
public:
    static bool init_puissances;
    static void initialize_puissances();
    static Vec<Vec<unsigned,nx>,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> puissances;
    static bool init_mult;
    static void initialize_mult();
    static Vec<Vec<Vec<unsigned,2> >,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> mult;
    static bool init_inv;
    static void initialize_inv();
    static Vec<Vec<Vec<unsigned,2> >,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> inv_ind;
    static Vec<Vec<T>,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> inv_coef;
    static Vec<bool,nd> init_tronc;
    template <unsigned ne> static void initialize_tronc (Number<ne>);
    static Vec<Vec<unsigned>,nd> tronc;
    static Vec<bool,Deux_Puissance<nx>::valeur> init_restriction;
    template <int ny> static void initialize_restriction (const Vec<int,ny> &vq);
    static Vec<Vec<Vec<unsigned> >,Deux_Puissance<nx>::valeur> restriction;
public:
    Pol () {}
    Pol (const T &a0); ///Construit le polynome constant egal a a
    Pol (const Vec<T> &V); ///Construit le polynome a partir de ses coefficients
    template <int nd2, class T2> Pol (const Pol<nd2,nx,T2> &P); ///Construit un polynome a partir d'un autre polynome
    template <int nx2, class T2, class T3> Pol (const Pol<nd,nx2,T2> &P, const Vec<int,nx> &vq, const Vec<T3,nx2-nx> &vx); ///Construit un polynome a partir d'un autre polynome
    template <int nx2, class T2> Pol (const Pol<nd,nx2,T2> &P, const Vec<int,nx> &vq); ///Construit un polynome a partir d'un autre polynome
    template <int nx2, class T2> Pol (const Pol<nd,nx2,T2> &P, const Vec<int,nx2> &vq); ///Construit un polynome a partir d'un autre polynome
    template <class T2> Pol (const Pol<nd,nx,T2> &P); ///Construit un polynome a partir d'un autre polynome
    Pol (const T &a, const T &b, unsigned q); ///Construit le polynome a + b*Xq;
    template <class T2> Pol<nd,nx,T> &operator= (const Pol<nd,nx,T2> &P); ///Renvoie un polynome egal a P
    const Vec<T,dim> &coefficients() const {return coefs;} ///Renvoie les coefficients du polynome
    const Vec<Vec<unsigned,nx> > &powers() const {return puissances;} ///Renvoie les puissances du polynome
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,nx> &V) const; /// Renvoie la valeur du polynome en V
    template <int ny, class T2> Pol<nd,nx-ny,typename TypePromote<Multiplies,T,T2>::T> operator() (const Vec<T2,ny> &V, const Vec<int,ny> &Vq) const; /// Renvoie un polynome extrait
    typedef Pol<nd-1,nx,T> Derivative;
    Vec<Derivative,nx> derivative() const; ///Renvoie les polynomes derives
    operator bool() const {return true;}
    Pol<nd,nx,T> operator-() const; ///Renvoie le polynome oppose;
    template <class T2> bool operator== (const Pol<nd,nx,T2> &P) const; /// Verifie si le polynome est egal a P
    template <class T2> bool operator!= (const Pol<nd,nx,T2> &P) const; /// Verifie si le polynome est different de P
    template <class T2> void operator+= (const Pol<nd,nx,T2> &P); /// Ajoute P au polynome
    template <class T2> void operator-= (const Pol<nd,nx,T2> &P); /// Retranche P au polynome
};

template <int nd, int nx, class T>
bool Pol<nd,nx,T>::init_puissances=1;

template <int nd, int nx, class T>
bool Pol<nd,nx,T>::init_deriv=1;

template <int nd, int nx, class T>
bool Pol<nd,nx,T>::init_mult=1;

template <int nd, int nx, class T>
bool Pol<nd,nx,T>::init_inv=1;

template <int nd, int nx, class T>
Vec<bool,nd> Pol<nd,nx,T>::init_tronc=1;

template <int nd, int nx, class T>
Vec<bool,Deux_Puissance<nx>::valeur> Pol<nd,nx,T>::init_restriction=1;

template <int nd, int nx, class T>
Vec<Vec<unsigned,nx>,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> Pol<nd,nx,T>::puissances;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned,2> >,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> Pol<nd,nx,T>::mult;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned,2> >,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> Pol<nd,nx,T>::inv_ind;

template <int nd, int nx, class T>
Vec<Vec<T>,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> Pol<nd,nx,T>::inv_coef;

template <int nd, int nx, class T>
Vec<Vec<unsigned>,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> Pol<nd,nx,T>::deriv_var;

template <int nd, int nx, class T>
Vec<Vec<unsigned>,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> Pol<nd,nx,T>::deriv_ind;

template <int nd, int nx, class T>
Vec<Vec<T>,Factorielle<nd+1,nd+nx>::valeur/Factorielle<1,nx>::valeur> Pol<nd,nx,T>::deriv_coef;

template <int nd, int nx, class T>
Vec<Vec<unsigned>,nd> Pol<nd,nx,T>::tronc;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned> >,Deux_Puissance<nx>::valeur> Pol<nd,nx,T>::restriction;

template <int nd, int nx, class T>
template <int nx_>
Vec<unsigned,nx_> Pol<nd,nx,T>::next_power(const Vec<unsigned,nx_> &v, int dmaxi=nd) {
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
Vec<unsigned,1> Pol<nd,nx,T>::next_power(const Vec<unsigned,1> &v, int dmaxi=nd) {
    Vec<unsigned,1> res=v;
    res[0]++;
    return res;
}

template <int nd, int nx, class T>
void Pol<nd,nx,T>::initialize_deriv() {
    if (init_puissances)
        initialize_puissances();
    if (Derivative::init_puissances)
        Derivative::initialize_puissances();
    init_deriv=0;
    for (unsigned i=1;i<dim;i++)
        for (int j=0;j<nx;j++)
            if (puissances[i][j]>0) {
                Vec<unsigned,nx> puissances_deriv_j=puissances[i];
                puissances_deriv_j[j]--;
                for (unsigned alphas=0;alphas<Derivative::dim;alphas++)
                    if (min(Derivative::puissances[alphas]==puissances_deriv_j)) {
                        deriv_var[i].push_back(j);
                        deriv_ind[i].push_back(alphas);
                        deriv_coef[i].push_back(T(puissances[i][j]));
                        break;
                    }
            }
}

template <int nd, int nx, class T>
void Pol<nd,nx,T>::initialize_puissances() {
    init_puissances=0;
    puissances[0].set(0);
    for (int i=1;i<dim;i++)
        puissances[i]=next_power(puissances[i-1]);
}

template <int nd, int nx, class T>
void Pol<nd,nx,T>::initialize_mult() {
    if (init_puissances)
        initialize_puissances();
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
    for (unsigned i=0;i<dim;i++)
        for (unsigned alphas=0;alphas<dim;alphas++)
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

template <int nd, int nx, class T>
void Pol<nd,nx,T>::initialize_inv() {
    if (init_puissances)
        initialize_puissances();
    init_inv=0;
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
    for (unsigned i=1;i<dim;i++) {
        Vec<unsigned,nx> ind_div_maxi=puissances[i];
        int p;
        for (int j=0;j<nx;j++)
            if (ind_div_maxi[j]>0) {
                ind_div_maxi[j]--;
                p=j;
                break;
            }
        for (unsigned alphas=0;alphas<dim;alphas++)
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
    }
}

template <int nd, int nx, class T>
template <unsigned ne>
void Pol<nd,nx,T>::initialize_tronc(Number<ne>) {
    if (init_puissances)
        initialize_puissances();
    if (Pol<ne,nx,T>::init_puissances)
        Pol<ne,nx,T>::initialize_puissances();
    init_tronc[ne]=0;
        tronc[ne].resize(Pol<ne,nx,T>::dim);
    for (unsigned i=0;i<tronc[ne].size();i++)
        for (int j=0;j<dim;j++)
            if (Pol<ne,nx,T>::puissances[i]==puissances[j]) {
                tronc[ne][i]=j;
                break;
            }
}

template <int nd, int nx, class T>
template <int ny>
void Pol<nd,nx,T>::initialize_restriction(const Vec<int,ny> &vq) {
    if (init_puissances)
        initialize_puissances();
    if (Pol<nd,ny,T>::init_puissances)
        Pol<nd,ny,T>::initialize_puissances();
    int rest=0;
    for (int i=0;i<ny;i++) {
        int tmp=1;
        for (int j=0;j<vq[i];j++)
            tmp*=2;
        rest+=tmp;
    }
    init_restriction[rest]=0;
        restriction[rest].resize(Pol<nd,ny,T>::dim);
    for (unsigned i=0;i<restriction[rest].size();i++) {
        for (int j=0;j<dim;j++)
            if (Pol<nd,ny,T>::puissances[i]==puissances[j][vq])
                restriction[rest][i].push_back(j);
    }
}

template <int nd, int nx, class T>
Pol<nd,nx,T>::Pol(const T &a0) {
    coefs.set(T(0));
    coefs[0]=a0;
}

template <int nd, int nx, class T>
Pol<nd,nx,T>::Pol(const Vec<T> &V) {
    coefs=V;
}

template <int nd, int nx, class T>
template <int nd2, class T2>
Pol<nd,nx,T>::Pol(const Pol<nd2,nx,T2> &P) {
    if (Pol<(nd<nd2?nd2:nd),nx,T>::init_tronc[(nd>nd2?nd2:nd)])
        Pol<(nd<nd2?nd2:nd),nx,T>::initialize_tronc(Number<(nd>nd2?nd2:nd)>());
    if (nd2>nd) {
        for (int i=0;i<coefs.size();i++)
            coefs[i]=P.coefficients()[Pol<nd2,nx,T>::tronc[nd][i]];
    }
    else {
        coefs.set(T(0));
        for (int i=0;i<P.coefficients().size();i++)
            coefs[tronc[nd2][i]]=P.coefficients()[i];
    }
}

template <int nd, int nx, class T>
template <int nx2, class T2, class T3>
Pol<nd,nx,T>::Pol(const Pol<nd,nx2,T2> &P, const Vec<int,nx> &vq, const Vec<T3,nx2-nx> &vx) {
    int rest=0;
    for (int i=0;i<nx;i++) {
        int tmp=1;
        for (int j=0;j<vq[i];j++)
            tmp*=2;
        rest+=tmp;
    }
    Vec<int,nx2-nx> vr=range(0,nx2-nx);
    for (int i=0;i<nx;i++)
        for (int j=0;j<nx2-nx;j++)
            if (vr[j]>=vq[i])
                vr[j]++;
    if (Pol<nd,nx2,T>::init_restriction[rest])
        Pol<nd,nx2,T>::initialize_restriction(vq);
    coefs.set(T(0));
    for (int i=0;i<coefs.size();i++)
        for (int j=0;j<Pol<nd,nx2,T>::restriction[rest][i].size();j++) {
            T tmp=P.coefficients()[Pol<nd,nx2,T>::restriction[rest][i][j]];
            for (int k=0;k<nx2-nx;k++)
                tmp*=pow(vx[k],int(Pol<nd,nx2,T>::puissances[Pol<nd,nx2,T>::restriction[rest][i][j]][vr[k]]));
            coefs[i]+=tmp;
        }
}

template <int nd, int nx, class T>
template <int nx2, class T2>
Pol<nd,nx,T>::Pol(const Pol<nd,nx2,T2> &P, const Vec<int,nx> &vq) {
    Vec<T,nx2-nx> vx;
    vx.set(T(0));
    *this=Pol(P,vq,vx);
}

template <int nd, int nx, class T>
template <int nx2, class T2>
Pol<nd,nx,T>::Pol(const Pol<nd,nx2,T2> &P, const Vec<int,nx2> &vq) {
    int rest=0;
    for (int i=0;i<nx2;i++) {
        int tmp=1;
        for (int j=0;j<vq[i];j++)
            tmp*=2;
        rest+=tmp;
    }
    if (Pol<nd,nx,T>::init_restriction[rest])
        Pol<nd,nx,T>::initialize_restriction(vq);
    coefs.set(T(0));
    for (int i=0;i<P.coefficients().size();i++)
        coefs[restriction[rest][i][0]]=P.coefficients()[i];
}

template <int nd, int nx, class T>
template <class T2>
Pol<nd,nx,T>::Pol(const Pol<nd,nx,T2> &P) {
    coefs=P.coefficients();
}


template <int nd, int nx, class T>
Pol<nd,nx,T>::Pol(const T &a, const T &b, unsigned q) {
    if (init_puissances)
        initialize_puissances();
    coefs.set(T(0));
    coefs[0]=a;
    for (int i=0;i<dim;i++)
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
    if (init_puissances)
        initialize_puissances();
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
Vec<typename Pol<nd,nx,T>::Derivative,nx> Pol<nd,nx,T>::derivative() const {
    if (init_deriv)
        initialize_deriv();
    Vec<Derivative,nx> res;
    Vec<Vec<T,Derivative::dim>,nx> res_vec;
    for (int i=1;i<deriv_ind.size();i++)
        for (int j=0;j<deriv_ind[i].size();j++)
            res_vec[deriv_var[i][j]][deriv_ind[i][j]]=deriv_coef[i][j]*coefs[i];
    for (int i=0;i<nx;i++)
        res[i]=Derivative(res_vec[i]);
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
    return !(coefs==P.coefficients());
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

////////////////////////////////////////////////////////////////////////////////////
// DEFINITION DES FONCTIONS GLOBALES EN RAPPORT AVEC DES POLYNOMES MULTIVARIABLES //
////////////////////////////////////////////////////////////////////////////////////
"""

print """
template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator+ (const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    typedef typename TypePromote<Plus,T1,T2>::T T;
    typedef Pol<nd,nx,T> PdxT;
    return PdxT(Vec<T,PdxT::dim>(P.coefficients()+Q.coefficients()));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,T1,T2>::T> operator- (const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    typedef typename TypePromote<Minus,T1,T2>::T T;
    typedef Pol<nd,nx,T> PdxT;
    return PdxT(Vec<T,PdxT::dim>(P.coefficients()-Q.coefficients()));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,T1,T2>::T> operator* (const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    typedef typename TypePromote<Multiplies,T1,T2>::T T;
    typedef Pol<nd,nx,T> PdxT;
    if (PdxT::init_mult)
        PdxT::initialize_mult();
    Vec<T,PdxT::dim> res_vec;
    res_vec.set(T(0));
    for (int i=0;i<res_vec.size();i++) {
        for (int j=0;j<PdxT::mult[i].size();j++)
            res_vec[i]+=P.coefficients()[PdxT::mult[i][j][0]]*Q.coefficients()[PdxT::mult[i][j][1]];
    }
    return PdxT(res_vec);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,T2>::T> operator/ (const Pol<nd,nx,T1> &P, const Pol<nd,nx,T2> &Q) {
    typedef typename TypePromote<Divides,T1,T2>::T T;
    typedef Pol<nd,nx,T> PdxT;
    if (PdxT::init_inv)
        PdxT::initialize_inv();
    if (PdxT::init_mult)
        PdxT::initialize_mult();
    Vec<T,PdxT::dim> a,b,res_vec;
    a.set(T(0));
    a[0]=T2(1)/Q.coefficients()[0];
    b.set(T(0));
    b[0]=a[0]*a[0];
    res_vec.set(T(0));
    res_vec[0]=P.coefficients()[0]/Q.coefficients()[0];
    for (int i=1;i<res_vec.size();i++) {
        for (int j=0;j<PdxT::inv_ind[i].size();j++)
            a[i]-=PdxT::inv_coef[i][j]*Q.coefficients()[PdxT::inv_ind[i][j][0]]*b[PdxT::inv_ind[i][j][1]];
        for (int j=0;j<PdxT::mult[i].size();j++)
            b[i]+=a[PdxT::mult[i][j][0]]*a[PdxT::mult[i][j][1]];
        for (int j=0;j<PdxT::mult[i].size();j++)
            res_vec[i]+=P.coefficients()[PdxT::mult[i][j][0]]*a[PdxT::mult[i][j][1]];
    }
    return PdxT(res_vec);
}

template <int nd, int nx, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,nx,T> &P) {
    if (Pol<nd,nx,T>::init_puissances)
        Pol<nd,nx,T>::initialize_puissances();
    if (P.coefficients().size()) {
        if (P.coefficients()[0])
            os << " " << P.coefficients()[0] << " ";
        for (unsigned i=1;i<P.coefficients().size();i++) {
            if (P.coefficients()[i]>0) {
                os << "+" << P.coefficients()[i];
                for (int j=0;j<nx;j++)
                    if(Pol<nd,nx,T>::puissances[i][j]>0)
                        os << "*X" << j << "^" << Pol<nd,nx,T>::puissances[i][j];
                os << " ";
            }
            if (P.coefficients()[i]<0) {
                os << "-" << -P.coefficients()[i];
                for (int j=0;j<nx;j++)
                    if(Pol<nd,nx,T>::puissances[i][j]>0)
                        os << "*X" << j << "^" << Pol<nd,nx,T>::puissances[i][j];
                os << " ";
            }
        }
        os << " ";
    }
    return os;
}

template <int nd, int nx, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,nx,std::complex<T> > &P) {
    if (Pol<nd,nx,T>::init_puissances)
        Pol<nd,nx,T>::initialize_puissances();
    if (P.coefficients().size()) {
        os << " " << P.coefficients()[0] << " ";
        for (unsigned i=1;i<P.coefficients().size();i++) {
            if (P.coefficients()[i]!=std::complex<T>(0)) {
                os << "+" << P.coefficients()[i];
                for (int j=0;j<nx;j++)
                    if(Pol<nd,nx,T>::puissances[i][j]>0)
                        os << "*X" << j << "^" << Pol<nd,nx,T>::puissances[i][j];
                os << " ";
            }
        }
        os << " ";
    }
    return os;
}

///////////////////////////////////////////////////////////////////////////////
// DEFINITION DE LA CLASSE POLYNOME MONOVARIABLE ET DE SES FONCTIONS MEMBRES //
///////////////////////////////////////////////////////////////////////////////

template <int nd, class T>
class Pol<nd,1,T> {
public :
    static const int degree=nd;
    static const int dim=nd+1;
private:
    Vec<T> coefs;
public:
    static bool init_puissances;
    static void initialize_puissances();
    static Vec<Vec<unsigned,1>,nd+1> puissances;
public:
    Pol () {}"""
imax = 9
for i in range(1,imax):
    tp = ''
    for j in range(0,i):
        tp = tp+'const T &a'+str(j)
        if j<i-1 :
            tp = tp+', '
    print '    Pol ('+tp+');'
print """
    Pol (const Vec<T> &V); ///Construit un polynome a partir de ses coefficients
    template <int nd2, class T2> Pol(const Pol<nd2,1,T2> &P2);
    template <class T2> Pol (const T2 &a, const T2 &b, int c);
    template <int nx2, class T2, class T3> Pol (const Pol<nd,nx2,T2> &P, int q, const Vec<T3,nx2-1> &vx); ///Construit un polynome a partir d'un autre polynome
    template <int nx2, class T2> Pol (const Pol<nd,nx2,T2> &P, int q); ///Construit un polynome a partir d'un autre polynome
    template <class T2> Pol (const Pol<nd,1,T2> &P, const Vec<int,1> &vq); ///Construit un polynome a partir d'un autre polynome
    template <int nd2, class T2> Pol<nd,1,T> &operator= (const Pol<nd2,1,T2> &P); ///Renvoie un polynome egal a P
    const Vec<T> &coefficients() const {return coefs;} ///Renvoie les coefficients du polynome
    Vec<Vec<unsigned,1> > powers() const; ///Renvoie les puissances du polynome
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const T2 &x) const;  ///Renvoie la valeur du polynome en x
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,1> &V) const; ///Renvoie le vecteur des valeurs du polynome en toutes les valeurs de V
    template <class T2> Vec<typename TypePromote<Multiplies,T,T2>::T> operator() (const Vec<T2> &V) const; ///Renvoie le vecteur des valeurs du polynome en toutes les valeurs de V
    Pol<nd,1,T> operator-() const {return Pol<nd,1,T>(-coefs);} ///Renvoie le polynome oppose;
    typedef Pol<nd-1,1,T> Derivative;
    Derivative derivative() const; ///Renvoie le polynome derivee
    Pol<nd,1,T> integral (const T &a) const; ///Renvoie le polynome integrale qui prend a comme valeur en 0
    int MaxPositivesRoots() const; ///Renvoie le nombre maximal de racines positives
    int MaxNegativesRoots() const; ///Renvoie le nombre maximal de racines negatives
    T RootsUpperBound() const; ///Renvoie un majorant des racines
    T RootsLowerBound() const; ///Renvoie un minorant des racines
    Pol<nd,1,T> remainder(const Pol<nd,1,T> &P) const; ///Renvoie le reste de la division par un polynome
    T dichotomy (const T &a, const T &b) const; ///Cherche une racine par dichotomie entre a et b
    T newton(const T &d, bool b, int imax) const; ///Cherche une racine par l'algorithme de Newton en partant de d
    T householder(const T &d, bool b, int imax) const; ///Cherche une racine par l'algorithme de Householder en partant de d
    Vec<T> roots() const; ///Renvoie les racines du polynome
    operator bool() const {return bool(coefs.size()>1) or bool(coefs[0]!=T(0));}
    template <int nd2, class T2> void operator+=(const Pol<nd2,1,T2> &Q); ///Ajoute Q au polynome
    template <int nd2, class T2> void operator-=(const Pol<nd2,1,T2> &Q); ///Retranche Q au polynome
};

template <int nd, class T>
bool Pol<nd,1,T>::init_puissances=1;

template <int nd, class T>
Vec<Vec<unsigned,1>,nd+1> Pol<nd,1,T>::puissances;

template <int nd, class T>
void Pol<nd,1,T>::initialize_puissances() {
    init_puissances=0;
    for (int i=0;i<puissances.size();i++)
        puissances[i][0]=i;
}

"""

for i in range(1,imax):
    tp = ''
    for j in range(0,i):
        tp = tp+'const T &a'+str(j)
        if j<i-1 :
            tp = tp+', '
    print 'template <int nd, class T>'
    print 'Pol<nd,1,T>::Pol ('+tp+') {'
    print '    coefs.resize(min('+str(i)+',nd+1));'
    print '    coefs[0]=a0;'
    for j in range(1,i):
        print '    if(nd>'+str(j-1)+') coefs['+str(j)+']=a'+str(j)+';'
    print """    while(coefs.size()>1 and coefs[coefs.size()-1]==T(0))
        coefs.pop_back();
}\n"""

print """
template <int nd, class T>
Pol<nd,1,T>::Pol(const Vec<T> &V) {
    if (V.size()<=nd+1)
            coefs=V;
    else
        coefs=V[range(1,nd+2)];
    while(coefs.size()>1 and coefs[coefs.size()-1]==T(0))
        coefs.pop_back();
}

template <int nd, class T>
template <class T2>
Pol<nd,1,T>::Pol (const T2 &a, const T2 &b, int c) {
    coefs.resize(2);
    coefs[0]=a;
    coefs[1]=b;
    while(coefs.size()>1 and coefs[coefs.size()-1]==T(0))
        coefs.pop_back();
}

template <int nd, class T>
template <int nd2, class T2>
Pol<nd,1,T>::Pol (const Pol<nd2,1,T2> &P2) {
    coefs=P2.coefficients();
    if (coefs.size()>nd+1)
        coefs.resize(nd+1);
    while(coefs.size()>1 and coefs[coefs.size()-1]==T(0))
        coefs.pop_back();
}

template <int nd, class T>
template <int nx2, class T2, class T3>
Pol<nd,1,T>::Pol(const Pol<nd,nx2,T2> &P, int q, const Vec<T3,nx2-1> &vx) {
    int rest=1;
    for (int j=0;j<q;j++)
        rest*=2;
    Vec<int,nx2-1> vr=range(0,nx2-1);
    for (int j=q;j<nx2-1;j++)
        vr[j]++;
    if (Pol<nd,nx2,T>::init_restriction[rest])
        Pol<nd,nx2,T>::initialize_restriction(Vec<int,1>(q));
    coefs.resize(nd+1,T(0));
    for (int i=0;i<coefs.size();i++)
        for (int j=0;j<Pol<nd,nx2,T>::restriction[rest][i].size();j++) {
            T tmp=P.coefficients()[Pol<nd,nx2,T>::restriction[rest][i][j]];
            for (int k=0;k<nx2-1;k++)
                tmp*=pow(vx[k],int(Pol<nd,nx2,T>::puissances[Pol<nd,nx2,T>::restriction[rest][i][j]][vr[k]]));
            coefs[i]+=tmp;
        }
}

template <int nd, class T>
template <int nx2, class T2>
Pol<nd,1,T>::Pol(const Pol<nd,nx2,T2> &P, int q) {
    Vec<T,nx2-1> vx;
    vx.set(T(0));
    *this=Pol(P,q,vx);
}

template <int nd, class T>
template <class T2> Pol<nd,1,T>::Pol (const Pol<nd,1,T2> &P, const Vec<int,1> &vq) {
    coefs=P.coefficients();
}

template <int nd, class T>
template <int nd2, class T2>
Pol<nd,1,T> &Pol<nd,1,T>::operator= (const Pol<nd2,1,T2> &P) {
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
typename TypePromote<Multiplies,T,T2>::T Pol<nd,1,T>::operator() (const T2 &x) const {
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
typename Pol<nd,1,T>::Derivative Pol<nd,1,T>::derivative() const {
    if (coefs.size()==1)
        return Derivative(T(0));
    Vec<T> coefficientsDerivee;
    coefficientsDerivee.resize(coefs.size()-1);
    for (unsigned i=0;i<coefficientsDerivee.size();i++)
        coefficientsDerivee[i]=coefs[i+1]*(i+1);
    return Derivative(coefficientsDerivee);
}

template <int nd, class T>
Pol<nd,1,T> Pol<nd,1,T>::integral(const T &a) const {
    Vec<T> coefficientsintegrale;
    coefficientsintegrale.resize(coefs.size()+1);
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
        if (coefficients[i]==T(0)) {
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
        if (coefficients[i]==T(0)) {
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
    typename TypePromote<Abs,T>::T titi=abs(coefs[coefs.size()-1]);
    Vec<T> tutu=coefs/titi;
    typename TypePromote<Abs,T>::T toto=norm_inf(tutu);
    return typename TypePromote<Abs,T>::T(1)+toto;
}

template <int nd, class T>
T Pol<nd,1,T>::RootsLowerBound() const {
    typename TypePromote<Abs,T>::T titi=abs(coefs[coefs.size()-1]);
    Vec<T> tutu=coefs/titi;
    typename TypePromote<Abs,T>::T toto=norm_inf(tutu);
    return typename TypePromote<Abs,T>::T(-1)-toto;
}

template <int nd, class T>
T Pol<nd,1,T>::dichotomy (const T &a, const T &b) const {
    if (sgn(operator()(a))==sgn(operator()(b))) {
        std::cout << "Dichotomy root research can me made only if P(a) and P(b) have opposite signs" << std::endl;
        exit(0);
    }
    T c=min(a,b);
    T e=max(a,b);
    while ((e-c)/(abs(e)+abs(c))>5*coefs.size()*std::numeric_limits<T>::epsilon()) {
        T d=(c+e)/2;
        if (sgn(operator()(d))==sgn(operator()(c)))
            c=d;
        else
            e=d;
    }
    return (c+e)/2;
}

template <int nd, class T>
T Pol<nd,1,T>::newton (const T &d, bool c=0, int imax=100) const {
    T a=d;
    T b=d-1;
    Derivative Q=derivative();
    int compteur=0;
    while (abs(a-b)/max(abs(a),abs(b))>10*coefs.size()*std::numeric_limits<T>::epsilon()&&compteur<imax) {
        b=a;
        a-=operator()(a)/Q(a);
        compteur++;
    }
    if (compteur==imax)
        bool c=1;
    return a;
}

template <int nd, class T>
T Pol<nd,1,T>::householder (const T &d, bool c=0, int imax=100) const {
    T a=d;
    T b=d-1;
    Derivative Q=derivative();
    typename Derivative::Derivative R=Q.derivative();
    int compteur=0;
    while (abs(a-b)/max(abs(a),abs(b))>10*coefs.size()*std::numeric_limits<T>::epsilon()&&compteur<imax) {
        b=a;
        T pa=operator()(a);
        T qa=Q(a);
        a-=(pa/qa)*(1+(pa*R(a))/(2*std::pow(qa,2)));
        compteur++;
    }
    if (compteur==imax)
        bool c=1;
    return a;
}

template <int nd, class T>
Pol<nd,1,T> Pol<nd,1,T>::remainder(const Pol<nd,1,T> &D) const {
    Vec<T> r=coefs;
    if (D.coefficients().size()<=coefs.size()) {
        Vec<T> d=D.coefficients();
        for (unsigned i=1;i<=coefs.size()-d.size()+1;i++) {
            T aux=r[r.size()-1]/d[d.size()-1];
            r.pop_back();
            for (unsigned j=0;j<d.size()-1;j++)
                r[r.size()-d.size()+j+1]-=aux*d[j];
        }
    }
    T norm=norm_inf(coefs);
    while (r.size()>1 and abs(r[r.size()-1])/norm<std::numeric_limits<T>::epsilon())
        r.pop_back();
    return Pol<nd,1,T>(r);
}

template <int nd, class T>
Vec<T> Pol<nd,1,T>::roots () const {
    Vec<T> res;
    if (coefs.size()==2)
        res.push_back(-coefs[0]/coefs[1]);
    else if (coefs.size()==3) {
        T delta=coefs[1]*coefs[1]-4*coefs[0]*coefs[2];
        if (delta==0)
            res.push_back(-0.5*coefs[1]/coefs[2]);
        if (delta>0) {
            res.push_back(-0.5*(coefs[1]+sqrt(delta))/coefs[2]);
            res.push_back(-0.5*(coefs[1]-sqrt(delta))/coefs[2]);
        }
    }
    else if (coefs.size()==4) {
        T a=coefs[2]/coefs[3];
        T b=coefs[1]/coefs[3];
        T c=coefs[0]/coefs[3];
        T p = b - std::pow(a,2)/3.;
        T q = std::pow(a,3)/13.5 - a*b/3 + c;
        T delta = 4.*std::pow(p,T(3))+27.*std::pow(q,T(2));
        if (delta>=0) {
            T u=(-13.5*q+sqrt(6.75*delta));
            T v=(-13.5*q-sqrt(6.75*delta));
            res.push_back((sgn(u)*std::pow(std::abs(u),T(1)/T(3))+sgn(v)*std::pow(std::abs(v),T(1)/T(3))-a)/3.);
        }
        if (delta<0) {
            complex<T> j(-0.5,sqrt(3.)/2.);
            complex<T> v(-13.5*q,sqrt(-6.75*delta));
            complex<T> u=std::pow(v,T(1)/T(3));
            res.push_back((2.*std::real(u)-a)/3.);
            res.push_back((2.*std::real(j*u)-a)/3.);
            res.push_back((2.*std::real(j*j*u)-a)/3.);
            sort(res);
        }
    }
    else if (coefs.size()>4) {
        if (coefs[0]!=0) {
            Vec<Pol<nd,1,T> > Sturm(*this,derivative());
            while (Sturm[Sturm.size()-1].coefficients().size()>1)
                Sturm.push_back(-Sturm[Sturm.size()-2].remainder(Sturm[Sturm.size()-1]));
            Vec<T> X(RootsLowerBound(),RootsUpperBound());
            int diffmax=2;
            while(diffmax>1) {
                Vec<int> deltas;
                deltas.resize(X.size(),0);
                for (unsigned i=0;i<X.size();i++){
                    for (unsigned j=1;j<Sturm.size();j++) {
                        if (sgn(Sturm[j-1](X[i]))!=sgn(Sturm[j](X[i])))
                            deltas[i]++;
                    }
                }
                Vec<int> diffs;
                diffs.resize(deltas.size()/2,0);
                Vec<T> X2;
                for (unsigned i=0;i<diffs.size();i++) {
                    diffs[i]=abs(deltas[2*i]-deltas[2*i+1]);
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
                bool b=0;
                T r=newton((X[2*i]+X[2*i+1])/2,b);
                if ((r<X[2*i] or r>X[2*i+1]) or b) {
                    b=0;
                    r=householder((X[2*i]+X[2*i+1])/2,b);
                }
                if ((r<X[2*i] or r>X[2*i+1]) or b)
                    r=dichotomy(X[2*i],X[2*i+1]);
                res.push_back(r);
            }
        }
        else {
            Vec<T> aux=coefs;
            while (aux[0]==T(0))
                aux.erase_elem_nb(0);
            Vec<T> r=Pol<nd,1,T>(aux).roots();
            while (r.size()>0 and r[0]<0) {
                res.push_back(r[0]);
                r.erase_elem_nb(0);
            }
            res.push_back(0);
            res.append(r);
        }
    }
    return res;
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
    typename TypePromote<Abs,T>::T m=norm_inf(coefs);
    while(coefs.size()>1 and abs(coefs[coefs.size()-1])/m<std::numeric_limits<typename TypePromote<Abs,T>::T>::epsilon())
        coefs.pop_back();
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
    typename TypePromote<Abs,T>::T m=norm_inf(coefs);
    while(coefs.size()>1 and abs(coefs[coefs.size()-1])/m<std::numeric_limits<typename TypePromote<Abs,T>::T>::epsilon())
        coefs.pop_back();
}

///////////////////////////////////////////////////////////////////////////////////
// DEFINITION DES FONCTIONS GLOBALES EN RAPPORT AVEC DES POLYNOMES MONOVARIABLES //
///////////////////////////////////////////////////////////////////////////////////

template <int nd, class T1, class T2>
Pol<nd,1,typename TypePromote<Plus,T1,T2>::T> operator+(const Pol<nd,1,T1> &P, const Pol<nd,1,T2> &Q) {
    if (!bool(P))
        return Q;
    else if (!bool(Q))
        return P;
    else {
        typedef typename TypePromote<Plus,T1,T2>::T T;
        const Vec<T> &p = P.coefficients();
        const Vec<T> &q = Q.coefficients();
        Vec<T> r;
        r.resize(max(q.size(),p.size()));
        for (int i=0;i<min(q.size(),p.size());i++)
            r[i]=p[i]+q[i];
        if (q.size()>p.size())
            for (int i=p.size();i<r.size();i++)
                r[i]=q[i];
        else if (p.size()>q.size())
            for (int i=q.size();i<r.size();i++)
                r[i]=p[i];
        typename TypePromote<Abs,T>::T m=norm_inf(r);
        while(r.size()>1 and abs(r[r.size()-1])/m<std::numeric_limits<typename TypePromote<Abs,T>::T>::epsilon())
            r.pop_back();
        Pol<nd,1,T> res(r);
        return res;
    }
}

template <int nd, class T1, class T2>
Pol<nd,1,typename TypePromote<Minus,T1,T2>::T> operator-(const Pol<nd,1,T1> &P, const Pol<nd,1,T2> &Q) {
    if (!bool(P))
        return -Q;
    else if (!bool(Q))
        return P;
    else {
        typedef typename TypePromote<Plus,T1,T2>::T T;
        const Vec<T> &p = P.coefficients();
        const Vec<T> &q = Q.coefficients();
        Vec<T> r;
        r.resize(max(q.size(),p.size()));
        for (int i=0;i<min(q.size(),p.size());i++)
            r[i]=p[i]-q[i];
        if (q.size()>p.size())
            for (int i=p.size();i<r.size();i++)
                r[i]=-q[i];
        else if (p.size()>q.size())
            for (int i=q.size();i<r.size();i++)
                r[i]=p[i];
        typename TypePromote<Abs,T>::T m=norm_inf(r);
        while(r.size()>1 and abs(r[r.size()-1])/m<std::numeric_limits<typename TypePromote<Abs,T>::T>::epsilon())
            r.pop_back();
        Pol<nd,1,T> res(r);
        return res;
    }
}

template <int nd, class T1, class T2>
Pol<nd,1,typename TypePromote<Multiplies,T1,T2>::T> operator*(const Pol<nd,1,T1> &P, const Pol<nd,1,T2> &Q) {
    if (!bool(P))
        return P;
    else if (!bool(Q))
        return Q;
    else {
        typedef typename TypePromote<Plus,T1,T2>::T T;
        Vec<T> r;
        const Vec<T> &p = P.coefficients();
        const Vec<T> &q = Q.coefficients();
        r.resize(min(p.size()+q.size()-1,nd+1),T(0));
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
        }
        if (p.size()>q.size()) {
            for (int i=q.size();i<p.size();i++)
                for (int j=0;j<q.size();j++)
                    r[i]+=q[j]*p[i-j];
            for (int i=p.size();i<r.size();i++)
                for (int j=i-p.size()+1;j<q.size();j++)
                    r[i]+=q[j]*p[i-j];
        }
        typename TypePromote<Abs,T>::T m=norm_inf(r);
        while(r.size()>1 and abs(r[r.size()-1])/m<std::numeric_limits<typename TypePromote<Abs,T>::T>::epsilon())
            r.pop_back();
        return Pol<nd,1,T>(r);
    }
}

template <int nd, class T1, class T2>
Pol<nd,1,typename TypePromote<Divides,T1,T2>::T> operator/(const Pol<nd,1,T1> &P, const Pol<nd,1,T2> &Q) {
    if (!bool(P))
        return P;
    else {
        typedef typename TypePromote<Plus,T1,T2>::T T;
        Vec<T> r,a,b;
        r.resize(nd+1,T(0));
        a.resize(nd+1,T(0));
        b.resize(nd,T(0));
        const Vec<T> &p=P.coefficients();
        const Vec<T> &q=Q.coefficients();
        a[0]=T(1)/q[0];
        for (int k=1;k<a.size();k++) {
            for (int s=0;s<k;s++)
                b[k-1]+=a[s]*a[k-1-s];
            for (int i=max(k-int(q.size())+1,0);i<k;i++)
                a[k]+=(T(i-k)/T(k))*q[k-i]*b[i];
        }
        for (int i=0;i<p.size();i++)
            for (int j=0;j<=i;j++)
                r[i]+=p[j]*a[i-j];
        for (int i=p.size();i<a.size();i++)
            for (int j=0;j<p.size();j++)
                r[i]+=p[j]*a[i-j];
        typename TypePromote<Abs,T>::T m=norm_inf(r);
        while(r.size()>1 and abs(r[r.size()-1])/m<std::numeric_limits<typename TypePromote<Abs,T>::T>::epsilon())
            r.pop_back();
        return Pol<nd,1,T>(r);
    }
}

template <int nd, class T>
void plot(const Pol<nd,1,T> &P, std::string s="w l") {
    T A = P.RootsLowerBound();
    T B = P.RootsUpperBound();
    Vec<T> V = range(A,(B-A)/500,B);
    GnuPlot gp;
    gp.plot(V,P(V),s.c_str());
    gp.wait();
}

template <int nd, class T>
void plot(const Pol<nd,1,T> &P, const Vec<T> &V, const std::string &s="w l") {
    //Affiche la fonction
    GnuPlot gp;
    gp.plot(V,P(V),s.c_str());
    gp.wait();
}

template <int nd, class T>
void plot(const Pol<nd,1,T> &P, const Pol<nd,1,T> &Q, const Vec<T> &V, const std::string &s="w l") {
    //Affiche la fonction
    GnuPlot gp;
    gp.plot(V,P(V),Q(V),s.c_str());
    gp.wait();
}

template <int nd, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,1,T> &P) {
    if (P.coefficients().size()) {
        if (P.coefficients()[0])
            os << " " << P.coefficients()[0] << " ";
        for (unsigned j=1;j<P.coefficients().size();j++) {
            if (P.coefficients()[j]>0)
                os << "+" << P.coefficients()[j] << "*X^" << j << " ";
            if (P.coefficients()[j]<0)
                os << "-" << -P.coefficients()[j] << "*X^" << j << " ";
        }
        os << " ";
    }
    return os;
}

template <int nd, class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,1,std::complex<T> > &P) {
    if (P.coefficients().size()) {
        os << " " << P.coefficients()[0] << " ";
        for (unsigned j=1;j<P.coefficients().size();j++)
            if (P.coefficients()[j]!=std::complex<T>(0))
                os << "+" << P.coefficients()[j] << "*X^" << j << " ";
        os << " ";
    }
    return os;
}

/////////////////////////////////////////////////////////////////////
// DEFINITION DES FONCTIONS GLOBALES EN RAPPORT AVEC DES POLYNOMES //
/////////////////////////////////////////////////////////////////////

template <int nd1, int nd2, int nx, class T1, class T2>
Pol<nd1,nx,T1> converter (const Pol<nd2,nx,T2> &P, Relative_Number<nd1>, Relative_Number<nx>, const T1 &t) {return P;};

template <int nd, int nx, class T>
const Pol<nd,nx,T> &converter (const Pol<nd,nx,T> &P, Relative_Number<nd>, Relative_Number<nx>, const T &t) {return P;};
"""

lst=[
    ('Plus','+'),
    ('Minus','-'),
    ('Multiplies','*'),
    ('Divides','/'),
]

for c,s in lst:
    print """
template <int nd1, int nd2, int nx, class T1, class T2>
Pol<(nd1>nd2?nd2:nd1),nx,typename TypePromote<"""+c+""",T1,T2>::T> operator"""+s+"""(const Pol<nd1,nx,T1> &P, const Pol<nd2,nx,T2> &Q) {
    const int nd=(nd1>nd2?nd2:nd1);
    typedef typename TypePromote<"""+c+""",T1,T2>::T T;
    return converter(P,Relative_Number<nd>(),Relative_Number<nx>(),T()) """+s+""" converter(Q,Relative_Number<nd>(),Relative_Number<nx>(),T());
}\n"""

print """template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T> operator+(const Pol<nd,nx,T1> &P, const T2 &t) {
    typedef typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T> aux=P.coefficients();
    aux[0]+=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T> operator+(const T2 &t, const Pol<nd,nx,T1> &P) {
    typedef typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T> aux=P.coefficients();
    aux[0]+=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T> operator-(const Pol<nd,nx,T1> &P, const T2 &t) {
    typedef typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T> aux=P.coefficients();
    aux[0]-=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T> operator-(const T2 &t, const Pol<nd,nx,T1> &P) {
    typedef typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T> aux=-P.coefficients();
    aux[0]+=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T> operator*(const T2 &t, const Pol<nd,nx,T1> &P) {
    typedef typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T T;
    return Pol<nd,nx,T>(Vec<T>(t*P.coefficients()));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T> operator*(const Pol<nd,nx,T1> &P, const T2 &t) {
    typedef typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T T;
    return Pol<nd,nx,T>(Vec<T>(P.coefficients()*t));
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> operator/(const T2 &t, const Pol<nd,nx,T1> &P) {
    typedef typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T T;
    return Pol<nd,nx,T2>(t) / P;
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> operator/(const Pol<nd,nx,T1> &P, const T2 &t) {
    typedef typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T T;
    return Pol<nd,nx,T>(Vec<T>(P.coefficients()/t));
}

template <int nd, int nx, class T>
Pol<nd,nx,T> pow(const Pol<nd,1,T> &P, int a) {
    Pol<nd,nx,T> res = P;
    for (int i=1;i<a;i++)
        res = res * P;
    return res;
}

template <int nd, int nx, class T>
typename TypePromote<Abs,T>::T abs_indication(const Pol<nd,nx,T> &P) {
    return abs_indication(P.coefficients()[0]);
}"""

lst=[
    ('Abs','abs'),
    ('Conj','conj'),
    ('Real','real'),
    ('Imag','imag'),
]

for t,f in lst:
    print """
template <int nd, int nx, class T>
Pol<nd,nx,typename TypePromote<"""+t+""",T>::T> """+f+"""(const Pol<nd,nx,T> &P) {
    return Pol<nd,nx,typename TypePromote<"""+t+""",T>::T>(Vec<typename TypePromote<"""+t+""",T>::T>("""+f+"""(P.coefficients())));
}"""

print """
template<int m, int n,class TT> struct TypeInformation<Pol<m,n,TT> > {
    static const int res = TypeInformation<TT>::res;
    static const int englobing = 1 + TypeInformation<TT>::englobing;
    static const bool is_scalar = true;
    typedef TT SubType;
    template<class TV> struct Variant { typedef Pol<m,n,TV> T; };
    template<class TV> struct DeepVariant { typedef Pol<m,n,class TypeInformation<TT>::template DeepVariant<TV>::T> T; };
    static std::string type() { return "Pol<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};

template<int m, int n,class TT> struct HasTypeInformation<Pol<m,n,TT> > { static const bool res = true; };

}

#endif // POLYNOMIALS_H
"""
