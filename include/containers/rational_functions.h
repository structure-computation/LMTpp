// file generated from rational_functions.h.py. Do not modify

////////////////////////////////////
//  Author : Camille GOUTTEBROZE  //
//  gouttebroze@lmt.ens-cachan.fr //
////////////////////////////////////

#ifndef RATIONAL_FUNCTIONS_H
#define RATIONAL_FUNCTIONS_H

#include <containers/gnuplot.h>
#include <containers/vec.h>
#include <containers/algo.h>

namespace LMT {

/**
  @author Gouttebroze
*/

/*!
\generic_comment Rat 
    \brief fonctions rationnelles à plusieurs indéterminées et de degré quelconque bornés

    = Remarque générale

        Rat est une classe qui représente les fonctions rationnelles à plusieurs indéterminés et de degré quelconque mais on fixe à la compilation le nombre d'indéterminés (paramètre template nx) ainsi que le même degré partiel maximum de chaque indéterminé (paramètre template nd) du numérateur et dénominateur. 
        Pour pouvoir manipuler des fonctions rationnelles (monovariables seulement), il faut utiliser le fichier rational_functions.h 
        Attention : Le stockage est de type dense ; cad on stocke la valeur de tous les monômes donc la taille augmente très vite avec le nombre d'indéterminées...

            \relates PolApprox
            \relates RatApprox
            \relates Pol

    =  Parametres templates pour les fonctions rationnelles

        Il y a trois parametres templates pour définir une fonction rationnelle : Rat<nd,nx,T>
        
            * nd est le degré maximal du numérateur et du dénominateur de la fonction rationnelle (valeur par défaut : 4)
            * nx est le nombre de variables de la fonction rationnelle (valeur par défaut : 1)
            * T est le type des coefficients de la fonction rationnelle (valeur par défaut : double)
        
        Il n'y a pas encore de spécialisation de la classe Rat pour les fonctions rationnelles monovariables (nx=1). Si vos calculs sont trop lents pour des fonctions rationnelles monovariables, demandez (gentiment) à Camille Gouttebroze de faire une spécialisation. 

    = Foire aux questions pour les fonctions rationnelles

        [[#1| Comment créer une fonction rationnelle constante ?]]
        [[#2| Comment afficher une fonction rationnelle ?]]
        [[#3| Comment récupérer les coefficients du numérateur d'une fonction rationnelle ?]]
        [[#4| Comment récupérer les puissances du dénominateur d'une fonction rationnelle ?]]
        [[#5| Comment évaluer une fonction rationnelle en un point ?]]
        [[#6| Comment dériver une fonction rationnelle ?]]
        [[#7| Comment effectuer des opérations algébriques sur des fonctions rationnelles ?]] 

    = Réponses :

        * \anchor 1 Pour afficher la fonction rationnelle F :
            \code C/C++
                cout << F << endl;
                OU
                PRINT(F);
        
        * \anchor 2 Pour récupérer les du numérateur de la fonction rationnelle F:
            \code C/C++
                Vec<T> V=P.numerator();
        * \anchor 3 Pour récupérer les du dénominateur de la fonction rationnelle F:
            \code C/C++
                Vec<T> V=P.denominator();
        * \anchor 4 Pour évaluer la fonction rationnelle de 3 variables F au point (4,-2,1) :
            \code C/C++
                Rat<nd,3,T> F = ... blabla ...
                Vec<T,3> V(4,-2,1);
                Vec<T> W=F(V);
        * \anchor 5 Pour obtenir les dérivées de la fonction rationnelle F :
            \code C/C++
                Vec<Rat<2*nd,nx,T>,nx> V=F.derivative();
        * \anchor 6 Pour obtenir la dérivée du polynome monovariable P :
            \code C/C++
                Pol<nd-1,nx,T> Q=P.derivative();
        * \anchor 7 Pour obtenir la primitive du polynome monovariable P qui s'annule en a:
            \code C/C++
                T a; 
                Pol<nd-1,nx,T> Q=P.integral(a);
        * \anchor 8 Pour effectuer des opérations algébriques sur des fonctions rationnelles P et Q :
            \code C/C++
                Rat<nd,nx,T> R=P+Q;
                Rat<nd,nx,T> R=P-Q;
                Rat<nd,nx,T> R=P*Q;
                Rat<nd,nx,T> R=P/Q; 

    \friend camille.gouttebroze@lmt.ens-cachan.fr
    \friend samir.amrouche@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr

    \keyword Mathématiques/Objet

    \author Camille Gouttebroze
*/

template <unsigned nd, unsigned nx>
struct SommeDimRat;

template <unsigned nd, unsigned nx>
struct DimRat {
    static const unsigned valeur = SommeDimRat<nd,nx-1>::valeur;
};

template <unsigned nd>
struct DimRat<nd,1> {
    static const unsigned valeur = nd+1;
};

template <unsigned nd, unsigned nx>
struct SommeDimRat {
    static const unsigned valeur = DimRat<nd,nx>::valeur + SommeDimRat<nd-1,nx>::valeur;
};

template <unsigned nx>
struct SommeDimRat <0,nx> {
    static const unsigned valeur = 1 ;
};

template <int nd=4,int nx=1,class T=double>
class Rat {
public:
    static const int dim=DimRat<nd,nx>::valeur;
private :
    Vec<T,dim> num;
    Vec<T,dim> den;
public:
    static bool init_puissances;
    static void initialize_puissances();
    static Vec<Vec<unsigned,nx>,Rat<nd,nx,T>::dim> puissances;
    Rat () {}
    template <class T2, int s2, class T3, int s3> Rat (const Vec<T2,s2> &V, const Vec<T3,s3> &W); ///Construit le polynome a partir de ses numerator
    template <class T2,int s> Rat (const Vec<T2,s> &V); ///Construit le polynome a partir de ses numerator
    template <int nd2, class T2> Rat (const Rat<nd2,nx,T2> &P); ///Construit un polynome a partir d'un autre polynome avec nx variable(s)
    template <int nx2, class T2, class T3> Rat (const Rat<nd,nx2,T2> &P, const Vec<int,nx> &vq, const Vec<T3,nx2-nx> &vx); ///Construit un polynome a partir d'un autre polynome avec plus de variables
    template <int nx2, class T2> Rat (const Rat<nd,nx2,T2> &P, const Vec<int,nx> &vq); ///Construit un polynome a partir d'un autre polynome avec plus de variables
    Rat (const T &a); ///Construit le polynome constant egal a a
    Rat (const T &a, const T &b, unsigned q); ///Construit le polynome a + b*Xq;
    template <class T2> Rat<nd,nx,T> &operator= (const Rat<nd,nx,T2> &P); ///Renvoie un polynome egal a P
    const Vec<T,dim> &numerator() const {return num;} ///Renvoie les numerator du polynome
    const Vec<T,dim> &denominator() const {return den;} ///Renvoie les numerator du polynome
    const Vec<Vec<unsigned,nx>,Rat<nd,nx,T>::dim> &powers(); ///Renvoie les puissances du polynome
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,nx>&x) const; /// Renvoie la valeur du polynome en x
    typedef Rat<2*nd,nx,T> Derivative;
    Vec<Derivative,nx> derivative() const; ///Renvoie les polynomes derives
    operator bool() const {return true;}
    Rat<nd,nx,T> operator-() const; ///Renvoie le polynome oppose;
    template <class T2> bool operator== (const Rat<nd,nx,T2> &P) const; /// Verifie si le polynome est egal a P
    template <class T2> bool operator!= (const Rat<nd,nx,T2> &P) const; /// Verifie si le polynome est different de P
    template <class T2> void operator+= (const Rat<nd,nx,T2> &P); /// Ajoute P au polynome
    template <class T2> void operator-= (const Rat<nd,nx,T2> &P); /// Retranche P au polynome
    template <class T2> void operator*= (const Rat<nd,nx,T2> &P); /// Multiplie le polynome par P;
    template <class T2> void operator/= (const Rat<nd,nx,T2> &P); /// Divise le polynome par P;
    
private:
    template <int nx_> static Vec<unsigned,nx_> next_power(const Vec<unsigned,nx_> &v);
    static Vec<unsigned,1> next_power(const Vec<unsigned,1> &v);
    static bool init_deriv;
    static void initialize_deriv();
    static Vec<Vec<unsigned>,Rat<nd,nx,T>::dim> deriv_var;
    static Vec<Vec<unsigned>,Rat<nd,nx,T>::dim> deriv_ind;
    static Vec<Vec<T>,Rat<nd,nx,T>::dim> deriv_coef;
public:
    static bool init_mult;
    static void initialize_mult();
    static Vec<Vec<Vec<unsigned,2> >,Rat<nd,nx,T>::dim> mult;
    static Vec<bool,nd> init_tronc;
    template <unsigned ne> static void initialize_tronc (Number<ne>);
    static Vec<Vec<unsigned>,nd> tronc;
    static Vec<bool,Deux_Puissance<nx>::valeur> init_restriction;
    template <int ny> static void initialize_restriction (const Vec<int,ny> &vq);
    static Vec<Vec<Vec<unsigned> >,Deux_Puissance<nx>::valeur> restriction;
    template <int nx2, class T2> Rat (const Rat<nd,nx2,T2> &P, const Vec<int,nx2> &vq); ///Construit un polynome a partir d un autre polynome
    template <int ny, class T2> Rat<nd,nx-ny,typename TypePromote<Multiplies,T,T2>::T> operator() (const Vec<T2,ny> &V, const Vec<int,ny> &Vq) const; /// Renvoie un polynome extrait

};

template <int nd, int nx, class T>
bool Rat<nd,nx,T>::init_puissances=1;

template <int nd, int nx, class T>
Vec<Vec<unsigned,nx>,Rat<nd,nx,T>::dim> Rat<nd,nx,T>::puissances;

template <int nd, int nx, class T>
void Rat<nd,nx,T>::initialize_puissances() {
    init_puissances=0;
    puissances[0].set(0);
    for (int i=1;i<dim;i++)
        puissances[i]=next_power(puissances[i-1]);

}

template <int nd, int nx, class T>
template <class T2, int s2, class T3, int s3>
Rat<nd,nx,T>::Rat(const Vec<T2,s2> &V, const Vec<T3,s3> &W) {
    num.set(T(0));
    num=V;
    den.set(T(0));
    den=W;
}

template <int nd, int nx, class T>
template <class T2, int s>
Rat<nd,nx,T>::Rat(const Vec<T2,s> &V) {
    num.set(T(0));
    num=V;
    den.set(T(0));
    den[0]=T(1);
}

template <int nd, int nx, class T>
template <int nd2, class T2>
Rat<nd,nx,T>::Rat(const Rat<nd2,nx,T2> &P) {

    if (Rat<(nd<nd2?nd2:nd),nx,T>::init_tronc[(nd>nd2?nd2:nd)])
        Rat<(nd<nd2?nd2:nd),nx,T>::initialize_tronc(Number<(nd>nd2?nd2:nd)>());
    if (nd2>nd) {
        for (int i=0;i<dim;i++)
            num[i]=P.numerator()[Rat<nd2,nx,T>::tronc[nd][i]];
    }
    else if(nd2<nd) {
        num.set(T(0));
        for (int i=0;i<Rat<nd2,nx,T2>::dim;i++)
            num[tronc[nd2][i]]=P.numerator()[i];
    }
    else
        num=P.numerator();

}

template <int nd, int nx, class T>
template <int nx2, class T2, class T3>
Rat<nd,nx,T>::Rat(const Rat<nd,nx2,T2> &P, const Vec<int,nx> &vq, const Vec<T3,nx2-nx> &vx) {

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
    if (Rat<nd,nx2,T>::init_restriction[rest])
        Rat<nd,nx2,T>::initialize_restriction(vq);
    num.set(T(0));
    for (int i=0;i<dim;i++)
        for (int j=0;j<Rat<nd,nx2,T>::restriction[rest][i].size();j++) {
            T tmp=P.numerator()[Rat<nd,nx2,T>::restriction[rest][i][j]];
            for (int k=0;k<nx2-nx;k++)
                tmp*=pow(vx[k],int(Rat<nd,nx2,T>::puissances[Rat<nd,nx2,T>::restriction[rest][i][j]][vr[k]]));
            num[i]+=tmp;
        }
}

template <int nd, int nx, class T>
template <int nx2, class T2>
Rat<nd,nx,T>::Rat(const Rat<nd,nx2,T2> &P, const Vec<int,nx> &vq) {
    Vec<T,nx2-nx> vx;
    vx.set(T(0));
    *this=Rat(P,vq,vx);
}

template <int nd, int nx, class T>
Rat<nd,nx,T>::Rat(const T &a0) {
    num.set(T(0));
    num[0]=a0;
    den.set(T(0));
    den[0]=1;
}

template <int nd, int nx, class T>
Rat<nd,nx,T>::Rat(const T &a, const T &b, unsigned q) {
    num.set(T(0));
    num[0]=a;
    if (init_puissances)
        initialize_puissances();
    for (int i=0;i<dim;i++)
        if (puissances[i][q]==1) {
            num[i]=b;
            break;
        }
    den.set(T(0));
    den[0]=T(1);
}

template <int nd, int nx, class T>
template <class T2>
Rat<nd,nx,T> &Rat<nd,nx,T>::operator= (const Rat<nd,nx,T2> &P) {
    num=P.numerator();
    den=P.denominator();
    return *this;
}

template <int nd, int nx, class T>
const Vec<Vec<unsigned,nx>,Rat<nd,nx,T>::dim> &Rat<nd,nx,T>::powers() {
    if (init_puissances)
        initialize_puissances();
    return puissances;
}

template <int nd, int nx, class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Rat<nd,nx,T>::operator() (const Vec<T2,nx>&x) const {
    if (init_puissances)
        initialize_puissances();

    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    TR res_num = num[0];
    TR res_den = den[0];
    for (unsigned i=1;i<dim;i++) {
        TR tmp_num=num[i];
        TR tmp_den=den[i];
        for (int k=0;k<nx;k++) {
            tmp_num*=::pow(x[k],int(puissances[i][k]));
            tmp_den*=::pow(x[k],int(puissances[i][k]));
        }
        res_num+=tmp_num;
        res_den+=tmp_den;
    }
    return res_num/res_den;
}

template <int nd, int nx, class T>
Vec<typename Rat<nd,nx,T>::Derivative,nx> Rat<nd,nx,T>::derivative() const {
    if (init_deriv)
        initialize_deriv();
    Vec<Derivative,nx> res;
    Vec<Vec<T,Derivative::dim>,nx> res_vec;
    for (int i=1;i<dim;i++)
        for (int j=0;j<deriv_ind[i].size();j++)
            res_vec[deriv_var[i][j]][deriv_ind[i][j]]=deriv_coef[i][j]*num[i];
    for (int i=0;i<nx;i++)
        res[i]=Derivative(res_vec[i]);
    return res;

}

template <int nd, int nx, class T>
Rat<nd,nx,T> Rat<nd,nx,T>::operator-() const {
    return Rat<nd,nx,T>(-num,den);
}

template <int nd, int nx, class T>
template <class T2>
bool Rat<nd,nx,T>::operator== (const Rat<nd,nx,T2> &P) const {
    return ( bool(num==P.numerator()) && bool(den == P.denominator()) ) ;
}

template <int nd, int nx, class T>
template <class T2>
bool Rat<nd,nx,T>::operator!= (const Rat<nd,nx,T2> &P) const {
    return ( !(bool(num==P.numerator())) || !(bool(den == P.denominator())) );
}

template <int nd, int nx, class T>
template <class T2>
void Rat<nd,nx,T>::operator+= (const Rat<nd,nx,T2> &P) {
    *this=*this+P;
}

template <int nd, int nx, class T>
template <class T2>
void Rat<nd,nx,T>::operator-= (const Rat<nd,nx,T2> &P) {
    *this=*this-P;
}

template <int nd, int nx, class T>
template <class T2>
void Rat<nd,nx,T>::operator*= (const Rat<nd,nx,T2> &P) {
    *this=*this*P;
}

template <int nd, int nx, class T>
template <class T2>
void Rat<nd,nx,T>::operator/= (const Rat<nd,nx,T2> &P) {
    *this=*this/P;
}



template <int nd, int nx, class T>
bool Rat<nd,nx,T>::init_deriv=1;

template <int nd, int nx, class T>
bool Rat<nd,nx,T>::init_mult=1;

template <int nd, int nx, class T>
Vec<bool,nd> Rat<nd,nx,T>::init_tronc=1;

template <int nd, int nx, class T>
Vec<bool,Deux_Puissance<nx>::valeur> Rat<nd,nx,T>::init_restriction=1;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned,2> >,Rat<nd,nx,T>::dim> Rat<nd,nx,T>::mult;

template <int nd, int nx, class T>
Vec<Vec<unsigned>,Rat<nd,nx,T>::dim> Rat<nd,nx,T>::deriv_var;

template <int nd, int nx, class T>
Vec<Vec<unsigned>,Rat<nd,nx,T>::dim> Rat<nd,nx,T>::deriv_ind;

template <int nd, int nx, class T>
Vec<Vec<T>,Rat<nd,nx,T>::dim> Rat<nd,nx,T>::deriv_coef;

template <int nd, int nx, class T>
Vec<Vec<unsigned>,nd> Rat<nd,nx,T>::tronc;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned> >,Deux_Puissance<nx>::valeur> Rat<nd,nx,T>::restriction;

template <int nd, int nx, class T>
template <int nx_>
Vec<unsigned,nx_> Rat<nd,nx,T>::next_power(const Vec<unsigned,nx_> &v) {
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

template <int nd, int nx, class T>
Vec<unsigned,1> Rat<nd,nx,T>::next_power(const Vec<unsigned,1> &v) {
    Vec<unsigned,1> res=v;
    res[0]++;
    return res;
}

template <int nd, int nx, class T>
void Rat<nd,nx,T>::initialize_deriv() {
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
void Rat<nd,nx,T>::initialize_mult() {
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
                mult[i].push_back(aux);
            }
}

template <int nd, int nx, class T>
template <unsigned ne>
void Rat<nd,nx,T>::initialize_tronc(Number<ne>) {
    if (init_puissances)
        initialize_puissances();
    if (Rat<ne,nx,T>::init_puissances)
        Rat<ne,nx,T>::initialize_puissances();
    init_tronc[ne]=0;
        tronc[ne].resize(Rat<ne,nx,T>::dim);
    for (unsigned i=0;i<tronc[ne].size();i++)
        for (int j=0;j<dim;j++)
            if (Rat<ne,nx,T>::puissances[i]==puissances[j]) {
                tronc[ne][i]=j;
                break;
            }
}

template <int nd, int nx, class T>
template <int ny>
void Rat<nd,nx,T>::initialize_restriction(const Vec<int,ny> &vq) {
    if (init_puissances)
        initialize_puissances();
    if (Rat<nd,ny,T>::init_puissances)
        Rat<nd,ny,T>::initialize_puissances();
    int rest=0;
    for (int i=0;i<ny;i++) {
        int tmp=1;
        for (int j=0;j<vq[i];j++)
            tmp*=2;
        rest+=tmp;
    }
    init_restriction[rest]=0;
        restriction[rest].resize(Rat<nd,ny,T>::dim);
    for (unsigned i=0;i<restriction[rest].size();i++) {
        for (int j=0;j<dim;j++)
            if (Rat<nd,ny,T>::puissances[i]==puissances[j][vq])
                restriction[rest][i].push_back(j);
    }
}

template <int nd, int nx, class T>
template <int nx2, class T2>
Rat<nd,nx,T>::Rat(const Rat<nd,nx2,T2> &P, const Vec<int,nx2> &vq) {
    int rest=0;
    for (int i=0;i<nx2;i++) {
        int tmp=1;
        for (int j=0;j<vq[i];j++)
            tmp*=2;
        rest+=tmp;
    }
    if (Rat<nd,nx,T>::init_restriction[rest])
        Rat<nd,nx,T>::initialize_restriction(vq);
    num.set(T(0));
    for (int i=0;i<Rat<nd,nx2,T2>::dim;i++)
        num[restriction[rest][i][0]]=P.numerator()[i];
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Plus,T1,T2>::T> operator+ (const Rat<nd,nx,T1> &P, const Rat<nd,nx,T2> &Q) {
    typedef typename TypePromote<Plus,T1,T2>::T T;
    typedef Rat<nd,nx,T> RdxT;
    typedef Pol<2*nd,nx,T> P2dxT;
        Vec<T> X;Vec<unsigned> ry,rz;
    return RdxT(X[ry],X[rz]);
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Minus,T1,T2>::T> operator- (const Rat<nd,nx,T1> &P, const Rat<nd,nx,T2> &Q) {
    typedef typename TypePromote<Minus,T1,T2>::T T;
    typedef Rat<nd,nx,T> RdxT;
    typedef Pol<2*nd,nx,T> P2dxT;
        Vec<T> X;Vec<unsigned> ry,rz;
    return RdxT(X[ry],X[rz]);
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Multiplies,T1,T2>::T> operator* (const Rat<nd,nx,T1> &P, const Rat<nd,nx,T2> &Q) {
    typedef typename TypePromote<Multiplies,T1,T2>::T T;
    typedef Rat<nd,nx,T> RdxT;
    typedef Pol<2*nd,nx,T> P2dxT;
        Vec<T> X;Vec<unsigned> ry,rz;
    return RdxT(X[ry],X[rz]);
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Divides,T1,T2>::T> operator/ (const Rat<nd,nx,T1> &P, const Rat<nd,nx,T2> &Q) {
    typedef typename TypePromote<Multiplies,T1,T2>::T T;
    typedef Rat<nd,nx,T> RdxT;
    typedef Pol<2*nd,nx,T> P2dxT;
        Vec<T> X;Vec<unsigned> ry,rz;
    return RdxT(X[ry],X[rz]);
}

template <int nd, int nx, class T>
std::ostream &operator<<(std::ostream &os, const Rat<nd,nx,T> &P) {
    os << Pol<nd,nx,T>(P.numerator()) << "/" << Pol<nd,nx,T>(P.denominator());
//    os << P.derivative().numerator()[0] ;
    return os;
}


template <int nd, class T>
class Rat<nd,1,T> {
public:
    static const int dim=DimRat<nd,1>::valeur;
private :
    Vec<T,dim> num;
    Vec<T,dim> den;
public:
    static bool init_puissances;
    static void initialize_puissances();
    static Vec<Vec<unsigned,1>,Rat<nd,1,T>::dim> puissances;
    Rat () {}
    template <class T2, int s2, class T3, int s3> Rat (const Vec<T2,s2> &V, const Vec<T3,s3> &W); ///Construit le polynome a partir de ses numerator
    template <class T2,int s> Rat (const Vec<T2,s> &V); ///Construit le polynome a partir de ses numerator
    template <int nd2, class T2> Rat (const Rat<nd2,1,T2> &P); ///Construit un polynome a partir d'un autre polynome avec 1 variable(s)
    template <int nx2, class T2, class T3> Rat (const Rat<nd,nx2,T2> &P, const int &vq, const Vec<T3,nx2-1> &vx); ///Construit un polynome a partir d'un autre polynome avec plus de variables
    template <int nx2, class T2> Rat (const Rat<nd,nx2,T2> &P, const int &vq); ///Construit un polynome a partir d'un autre polynome avec plus de variables
    Rat (const T &a); ///Construit le polynome constant egal a a
    Rat (const T &a, const T &b, unsigned q); ///Construit le polynome a + b*Xq;
    template <class T2> Rat<nd,1,T> &operator= (const Rat<nd,1,T2> &P); ///Renvoie un polynome egal a P
    const Vec<T,dim> &numerator() const {return num;} ///Renvoie les numerator du polynome
    const Vec<T,dim> &denominator() const {return den;} ///Renvoie les numerator du polynome
    const Vec<Vec<unsigned,1>,Rat<nd,1,T>::dim> &powers(); ///Renvoie les puissances du polynome
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const T2&x) const; /// Renvoie la valeur du polynome en x
    typedef Rat<2*nd,1,T> Derivative;
    Derivative derivative() const; ///Renvoie les polynomes derives
    operator bool() const {return true;}
    Rat<nd,1,T> operator-() const; ///Renvoie le polynome oppose;
    template <class T2> bool operator== (const Rat<nd,1,T2> &P) const; /// Verifie si le polynome est egal a P
    template <class T2> bool operator!= (const Rat<nd,1,T2> &P) const; /// Verifie si le polynome est different de P
    template <class T2> void operator+= (const Rat<nd,1,T2> &P); /// Ajoute P au polynome
    template <class T2> void operator-= (const Rat<nd,1,T2> &P); /// Retranche P au polynome
    template <class T2> void operator*= (const Rat<nd,1,T2> &P); /// Multiplie le polynome par P;
    template <class T2> void operator/= (const Rat<nd,1,T2> &P); /// Divise le polynome par P;
    
public :
    template <class T2> Rat (const Rat<nd,1,T2> &P, const Vec<int,1> &vq); ///Construit un polynome a partir d un autre polynome
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,1> &V) const; ///Renvoie le vecteur des valeurs du polynome en toutes les valeurs de V
    int MaxPositivesRoots() const; ///Renvoie le nombre maximal de racines positives
    int MaxNegativesRoots() const; ///Renvoie le nombre maximal de racines negatives
    T RootsUpperBound() const; ///Renvoie un majorant des racines
    T RootsLowerBound() const; ///Renvoie un minorant des racines
    Rat<nd,1,T> remainder(const Rat<nd,1,T> &P) const; ///Renvoie le reste de la division par un polynome
    T dichotomy (const T &a, const T &b) const; ///Cherche une racine par dichotomie entre a et b
    T newton(const T &d, bool b, int imax) const; ///Cherche une racine par l algorithme de Newton en partant de d
    T householder(const T &d, bool b, int imax) const; ///Cherche une racine par l algorithme de Householder en partant de d
    Vec<T> roots() const; ///Renvoie les racines du polynome

};

template <int nd, class T>
bool Rat<nd,1,T>::init_puissances=1;

template <int nd, class T>
Vec<Vec<unsigned,1>,Rat<nd,1,T>::dim> Rat<nd,1,T>::puissances;

template <int nd, class T>
void Rat<nd,1,T>::initialize_puissances() {
    init_puissances=0;
    puissances[0].set(0);
    for (int i=1;i<dim;i++)
        puissances[i][0]=i;

}

template <int nd, class T>
template <class T2, int s2, class T3, int s3>
Rat<nd,1,T>::Rat(const Vec<T2,s2> &V, const Vec<T3,s3> &W) {
    num.set(T(0));
    num=V;
    den.set(T(0));
    den=W;
}

template <int nd, class T>
template <class T2, int s>
Rat<nd,1,T>::Rat(const Vec<T2,s> &V) {
    num.set(T(0));
    num=V;
    den.set(T(0));
    den[0]=T(1);
}

template <int nd, class T>
template <int nd2, class T2>
Rat<nd,1,T>::Rat(const Rat<nd2,1,T2> &P) {

    if (nd2>nd) {
        num.set(T(0));
        num=P.numerator()[range(0,nd)];
        den.set(T(0));
        den=P.denominator()[range(0,nd)];
    }
    else if(nd2<nd) {
        num[range(0,nd2)]=P.numerator();
        den[range(0,nd2)]=P.denominator();
    }
    else {
        num=P.numerator();
        den=P.denominator();
    }

}

template <int nd, class T>
template <int nx2, class T2, class T3>
Rat<nd,1,T>::Rat(const Rat<nd,nx2,T2> &P, const int &vq, const Vec<T3,nx2-1> &vx) {

    int rest=1;
    for (int j=0;j<vq;j++)
        rest*=2;
    Vec<int,nx2-1> vr=range(0,nx2-1);
    for (int j=vq;j<nx2-1;j++)
        vr[j]++;
    if (Rat<nd,nx2,T>::init_restriction[rest])
        Rat<nd,nx2,T>::initialize_restriction(Vec<int,1>(vq));
    for (int i=0;i<dim;i++)
        for (int j=0;j<Rat<nd,nx2,T>::restriction[rest][i].size();j++) {
            T tmp=P.numerator()[Rat<nd,nx2,T>::restriction[rest][i][j]];
            for (int k=0;k<nx2-1;k++)
                tmp*=pow(vx[k],int(Rat<nd,nx2,T>::puissances[Rat<nd,nx2,T>::restriction[rest][i][j]][vr[k]]));
            num[i]+=tmp;
        }
}

template <int nd, class T>
template <int nx2, class T2>
Rat<nd,1,T>::Rat(const Rat<nd,nx2,T2> &P, const int &vq) {
    Vec<T,nx2-1> vx;
    vx.set(T(0));
    *this=Rat(P,vq,vx);
}

template <int nd, class T>
Rat<nd,1,T>::Rat(const T &a0) {
    num.set(T(0));
    num[0]=a0;
    den.set(T(0));
    den[0]=1;
}

template <int nd, class T>
Rat<nd,1,T>::Rat(const T &a, const T &b, unsigned q) {
    num.set(T(0));
    num[0]=a;
    if (init_puissances)
        initialize_puissances();
    for (int i=0;i<dim;i++)
        if (puissances[i][q]==1) {
            num[i]=b;
            break;
        }
    den.set(T(0));
    den[0]=T(1);
}

template <int nd, class T>
template <class T2>
Rat<nd,1,T> &Rat<nd,1,T>::operator= (const Rat<nd,1,T2> &P) {
    num=P.numerator();
    den=P.denominator();
    return *this;
}

template <int nd, class T>
const Vec<Vec<unsigned,1>,Rat<nd,1,T>::dim> &Rat<nd,1,T>::powers() {
    if (init_puissances)
        initialize_puissances();
    return puissances;
}

template <int nd, class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Rat<nd,1,T>::operator() (const T2&x) const {

    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    TR res_num = num[0];
    TR res_den = den[0];
    for (unsigned i=1;i<dim;i++) {
        res_num += TR(num[i]) * ::pow(TR(x),i);
        res_den += TR(den[i]) * ::pow(TR(x),i);
    }
    return res_num/res_den;
}

template <int nd, class T>
typename Rat<nd,1,T>::Derivative Rat<nd,1,T>::derivative() const {
    Pol<2*nd,1,T> N(num);
    Pol<2*nd,1,T> D(den);
    return Derivative((N.derivative()*D-D.derivative()*N).coefficients(),(D*D).coefficients());

}

template <int nd, class T>
Rat<nd,1,T> Rat<nd,1,T>::operator-() const {
    return Rat<nd,1,T>(-num,den);
}

template <int nd, class T>
template <class T2>
bool Rat<nd,1,T>::operator== (const Rat<nd,1,T2> &P) const {
    return ( bool(num==P.numerator()) && bool(den == P.denominator()) ) ;
}

template <int nd, class T>
template <class T2>
bool Rat<nd,1,T>::operator!= (const Rat<nd,1,T2> &P) const {
    return ( !(bool(num==P.numerator())) || !(bool(den == P.denominator())) );
}

template <int nd, class T>
template <class T2>
void Rat<nd,1,T>::operator+= (const Rat<nd,1,T2> &P) {
    *this=*this+P;
}

template <int nd, class T>
template <class T2>
void Rat<nd,1,T>::operator-= (const Rat<nd,1,T2> &P) {
    *this=*this-P;
}

template <int nd, class T>
template <class T2>
void Rat<nd,1,T>::operator*= (const Rat<nd,1,T2> &P) {
    *this=*this*P;
}

template <int nd, class T>
template <class T2>
void Rat<nd,1,T>::operator/= (const Rat<nd,1,T2> &P) {
    *this=*this/P;
}



template <int nd, class T>
template <class T2> Rat<nd,1,T>::Rat (const Rat<nd,1,T2> &P, const Vec<int,1> &vq) {
    num=P.numerator();
    den=P.denominator();
}

template <int nd, class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Rat<nd,1,T>::operator() (const Vec<T2,1> &x) const {
    return operator()(x[0]);
}

template <int nd, class T>
int Rat<nd,1,T>::MaxPositivesRoots() const {
    int res=0;
    Vec<T> numerator=num;
    for (unsigned i=1;i<numerator.size();i++)
        if (numerator[i]==T(0)) {
            numerator.erase_elem_nb(i);
            i--;
        }
    for (unsigned i=1;i<numerator.size();i++)
        if (sgn(numerator[i])!=sgn(numerator[i-1]))
            res++;
    return res;
}

template <int nd, class T>
int Rat<nd,1,T>::MaxNegativesRoots() const {
    int res=0;
    Vec<T> numerator=num;
    for (unsigned i=1;i<numerator.size();i+=2)
        numerator[i]=-numerator[i];
    for (unsigned i=1;i<numerator.size();i++)
        if (numerator[i]==T(0)) {
            numerator.erase_elem_nb(i);
            i--;
        }
    for (unsigned i=1;i<numerator.size();i++)
        if (sgn(numerator[i])!=sgn(numerator[i-1]))
            res++;
    return res;
}

template <int nd, class T>
T Rat<nd,1,T>::RootsUpperBound() const {
    typename TypePromote<Abs,T>::T titi=abs(num[dim-1]);
    for (int i=dim-2; i>0 && titi==T(0); i--)
        if (abs(num[i]))
            titi==num[i];
    Vec<T,dim> tutu=num/titi;
    typename TypePromote<Abs,T>::T toto=norm_inf(tutu);
    return typename TypePromote<Abs,T>::T(1)+toto;
}

template <int nd, class T>
T Rat<nd,1,T>::RootsLowerBound() const {
    typename TypePromote<Abs,T>::T titi=abs(num[dim-1]);
    for (int i=dim-2; i>0 && titi==T(0); i--)
        if (abs(num[i]))
            titi==num[i];
    Vec<T,dim> tutu=num/titi;
    typename TypePromote<Abs,T>::T toto=norm_inf(tutu);
    return typename TypePromote<Abs,T>::T(-1)-toto;
}

template <int nd, class T>
T Rat<nd,1,T>::dichotomy (const T &a, const T &b) const {
    if (sgn(operator()(a))==sgn(operator()(b))) {
        std::cout << "Dichotomy root research can me made only if P(a) and P(b) have opposite signs" << std::endl;
        exit(0);
    }
    T c=min(a,b);
    T e=max(a,b);
    while ((e-c)/(abs(e)+abs(c))>5*dim*std::numeric_limits<T>::epsilon()) {
        T d=(c+e)/2;
        if (sgn(operator()(d))==sgn(operator()(c)))
            c=d;
        else
            e=d;
    }
    return (c+e)/2;
}

template <int nd, class T>
T Rat<nd,1,T>::newton (const T &d, bool c=0, int imax=100) const {
    T a=d;
    T b=d-1;
    Derivative Q=derivative();
    int compteur=0;
    while (abs(a-b)/max(abs(a),abs(b))>10*dim*std::numeric_limits<T>::epsilon()&&compteur<imax) {
        b=a;
        a-=operator()(a)/Q(a);
        compteur++;
    }
    if (compteur==imax)
        bool c=1;
    return a;
}

template <int nd, class T>
T Rat<nd,1,T>::householder (const T &d, bool c=0, int imax=100) const {
    T a=d;
    T b=d-1;
    Derivative Q=derivative();
    typename Derivative::Derivative R=Q.derivative();
    int compteur=0;
    while (abs(a-b)/max(abs(a),abs(b))>10*dim*std::numeric_limits<T>::epsilon()&&compteur<imax) {
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
Rat<nd,1,T> Rat<nd,1,T>::remainder(const Rat<nd,1,T> &D) const {
    Vec<T> r=num;
    T norm=norm_inf(r);
    while (r.size()>1 and abs(r[r.size()-1])/norm<std::numeric_limits<T>::epsilon())
        r.pop_back();
    Vec<T> d=D.numerator();
    norm=norm_inf(d);
    while (d.size()>1 and abs(d[d.size()-1])/norm<std::numeric_limits<T>::epsilon())
        d.pop_back();
        if (d.size()<=r.size()) {
        for (unsigned i=1;i<=num.size()-d.size()+1;i++) {
            T aux=r[r.size()-1]/d[d.size()-1];
            r.pop_back();
            for (unsigned j=0;j<d.size()-1;j++)
                r[r.size()-d.size()+j+1]-=aux*d[j];
        }
    }
    return Rat<nd,1,T>(r);
}

template <int nd, class T>
Vec<T> Rat<nd,1,T>::roots () const {
    return Pol<nd,1,T>(num).roots();;
}

template <int nd, class T1, class T2>
Rat<nd,1,typename TypePromote<Plus,T1,T2>::T> operator+ (const Rat<nd,1,T1> &P, const Rat<nd,1,T2> &Q) {
    typedef typename TypePromote<Plus,T1,T2>::T T;
    typedef Rat<nd,1,T> RdxT;
    typedef Pol<2*nd,1,T> P2dxT;
    Pol<2*nd,1,T> Pn(P.numerator());
    Pol<2*nd,1,T> Pd(P.denominator());
    Pol<2*nd,1,T> Qn(Q.numerator());
    Pol<2*nd,1,T> Qd(Q.denominator());
    Pol<2*nd,1,T> Y=Pn*Qd+Pd*Qn;
    Pol<2*nd,1,T> Z=Pd*Qd;
    Mat<T,Gen<> > A(2*RdxT::dim,2*RdxT::dim,T(0));
    A(0,0)=T(1);
    A(1,0)=Y.coefficients()[0];
    A(1,1)=-Z.coefficients()[0];
    for (int i=2;i<A.nb_rows();i++) {
        A(i,0)=Y.coefficients()[i-1];
        A(i,1)=-Z.coefficients()[i-1];
        for (int j=1;2*j+1<A.nb_cols();j++) { //AMELIORER CONDITION D'ARRET
            A(i,2*j)=A(i-1,2*j-2);
            A(i,2*j+1)=A(i-1,2*j-1);
        }
    }
    Vec<Sparse<T> > zeros;
    zeros[0]=T(1);
    Vec<T> X;
    bool b;
    do {
        b=false;
        try {
            X=inv(A)*zeros;
        } catch (const SolveException &e) {
            b=true;
            A.resize(A.nb_rows()-2,A.nb_cols()-2);
            zeros.resize(zeros.size()-2);
        };
    } while (b);
    X[0]=T(1);
    Vec<unsigned> ry=range(1u,2u,A.nb_rows());
    Vec<unsigned> rz=range(0u,2u,A.nb_rows());
    return RdxT(X[ry],X[rz]);
}

template <int nd, class T1, class T2>
Rat<nd,1,typename TypePromote<Minus,T1,T2>::T> operator- (const Rat<nd,1,T1> &P, const Rat<nd,1,T2> &Q) {
    typedef typename TypePromote<Minus,T1,T2>::T T;
    typedef Rat<nd,1,T> RdxT;
    typedef Pol<2*nd,1,T> P2dxT;
    Pol<2*nd,1,T> Pn(P.numerator());
    Pol<2*nd,1,T> Pd(P.denominator());
    Pol<2*nd,1,T> Qn(Q.numerator());
    Pol<2*nd,1,T> Qd(Q.denominator());
    Pol<2*nd,1,T> Y=Pn*Qd-Pd*Qn;
    Pol<2*nd,1,T> Z=Pd*Qd;
    Mat<T,Gen<> > A(2*RdxT::dim,2*RdxT::dim,T(0));
    A(0,0)=T(1);
    A(1,0)=Y.coefficients()[0];
    A(1,1)=-Z.coefficients()[0];
    for (int i=2;i<A.nb_rows();i++) {
        A(i,0)=Y.coefficients()[i-1];
        A(i,1)=-Z.coefficients()[i-1];
        for (int j=1;2*j+1<A.nb_cols();j++) { //AMELIORER CONDITION D'ARRET
            A(i,2*j)=A(i-1,2*j-2);
            A(i,2*j+1)=A(i-1,2*j-1);
        }
    }
    Vec<Sparse<T> > zeros;
    zeros[0]=T(1);
    Vec<T> X;
    bool b;
    do {
        b=false;
        try {
            X=inv(A)*zeros;
        } catch (const SolveException &e) {
            b=true;
            A.resize(A.nb_rows()-2,A.nb_cols()-2);
            zeros.resize(zeros.size()-2);
        };
    } while (b);
    X[0]=T(1);
    Vec<unsigned> ry=range(1u,2u,A.nb_rows());
    Vec<unsigned> rz=range(0u,2u,A.nb_rows());
    return RdxT(X[ry],X[rz]);
}

template <int nd, class T1, class T2>
Rat<nd,1,typename TypePromote<Multiplies,T1,T2>::T> operator* (const Rat<nd,1,T1> &P, const Rat<nd,1,T2> &Q) {
    typedef typename TypePromote<Multiplies,T1,T2>::T T;
    typedef Rat<nd,1,T> RdxT;
    typedef Pol<2*nd,1,T> P2dxT;
    Pol<2*nd,1,T> Pn(P.numerator());
    Pol<2*nd,1,T> Pd(P.denominator());
    Pol<2*nd,1,T> Qn(Q.numerator());
    Pol<2*nd,1,T> Qd(Q.denominator());
    Pol<2*nd,1,T> Y=Pn*Qn;
    Pol<2*nd,1,T> Z=Pd*Qd;
    Mat<T,Gen<> > A(2*RdxT::dim,2*RdxT::dim,T(0));
    A(0,0)=T(1);
    A(1,0)=Y.coefficients()[0];
    A(1,1)=-Z.coefficients()[0];
    for (int i=2;i<A.nb_rows();i++) {
        A(i,0)=Y.coefficients()[i-1];
        A(i,1)=-Z.coefficients()[i-1];
        for (int j=1;2*j+1<A.nb_cols();j++) { //AMELIORER CONDITION D'ARRET
            A(i,2*j)=A(i-1,2*j-2);
            A(i,2*j+1)=A(i-1,2*j-1);
        }
    }
    Vec<Sparse<T> > zeros;
    zeros[0]=T(1);
    Vec<T> X;
    bool b;
    do {
        b=false;
        try {
            X=inv(A)*zeros;
        } catch (const SolveException &e) {
            b=true;
            A.resize(A.nb_rows()-2,A.nb_cols()-2);
            zeros.resize(zeros.size()-2);
        };
    } while (b);
    X[0]=T(1);
    Vec<unsigned> ry=range(1u,2u,A.nb_rows());
    Vec<unsigned> rz=range(0u,2u,A.nb_rows());
    return RdxT(X[ry],X[rz]);
}

template <int nd, class T1, class T2>
Rat<nd,1,typename TypePromote<Divides,T1,T2>::T> operator/ (const Rat<nd,1,T1> &P, const Rat<nd,1,T2> &Q) {
    typedef typename TypePromote<Multiplies,T1,T2>::T T;
    typedef Rat<nd,1,T> RdxT;
    typedef Pol<2*nd,1,T> P2dxT;
    Pol<2*nd,1,T> Pn(P.numerator());
    Pol<2*nd,1,T> Pd(P.denominator());
    Pol<2*nd,1,T> Qn(Q.numerator());
    Pol<2*nd,1,T> Qd(Q.denominator());
    Pol<2*nd,1,T> Y=Pn*Qd;
    Pol<2*nd,1,T> Z=Pd*Qn;
    Mat<T,Gen<> > A(2*RdxT::dim,2*RdxT::dim,T(0));
    A(0,0)=T(1);
    A(1,0)=Y.coefficients()[0];
    A(1,1)=-Z.coefficients()[0];
    for (int i=2;i<A.nb_rows();i++) {
        A(i,0)=Y.coefficients()[i-1];
        A(i,1)=-Z.coefficients()[i-1];
        for (int j=1;2*j+1<A.nb_cols();j++) { //AMELIORER CONDITION D'ARRET
            A(i,2*j)=A(i-1,2*j-2);
            A(i,2*j+1)=A(i-1,2*j-1);
        }
    }
    Vec<Sparse<T> > zeros;
    zeros[0]=T(1);
    Vec<T> X;
    bool b;
    do {
        b=false;
        try {
            X=inv(A)*zeros;
        } catch (const SolveException &e) {
            b=true;
            A.resize(A.nb_rows()-2,A.nb_cols()-2);
            zeros.resize(zeros.size()-2);
        };
    } while (b);
    X[0]=T(1);
    Vec<unsigned> ry=range(1u,2u,A.nb_rows());
    Vec<unsigned> rz=range(0u,2u,A.nb_rows());
    return RdxT(X[ry],X[rz]);
}

template <int nd, class T>
std::ostream &operator<<(std::ostream &os, const Rat<nd,1,T> &P) {
    os << Pol<nd,1,T>(P.numerator()) << "/" << Pol<nd,1,T>(P.denominator());
//    os << P.derivative().numerator()[0] ;
    return os;
}



template <int nd, class T>
void plot(const Rat<nd,1,T> &P, std::string s="w l") {
    T A = P.RootsLowerBound();
    T B = P.RootsUpperBound();
    Vec<T> V = range(A,(B-A)/500,B);
    GnuPlot gp;
    gp.plot(V,P(V),s.c_str());
    gp.wait();
}

template <int nd, class T>
void plot(const Rat<nd,1,T> &P, const Vec<T> &V, const std::string &s="w l") {
    //Affiche la fonction
    GnuPlot gp;
    gp.plot(V,P(V),s.c_str());
    gp.wait();
}

template <int nd, class T>
void plot(const Rat<nd,1,T> &P, const Rat<nd,1,T> &Q, const Vec<T> &V, const std::string &s="w l") {
    //Affiche la fonction
    GnuPlot gp;
    gp.plot(V,P(V),Q(V),s.c_str());
    gp.wait();
}


template <int nd1, int nd2, int nx, class T1, class T2>
Rat<nd1,nx,T1> converter (const Rat<nd2,nx,T2> &P, Relative_Number<nd1>, Relative_Number<nx>, const T1 &t) {return P;};

template <int nd, int nx, class T>
const Rat<nd,nx,T> &converter (const Rat<nd,nx,T> &P, Relative_Number<nd>, Relative_Number<nx>, const T &t) {return P;};


template <int nd1, int nd2, int nx, class T1, class T2>
Rat<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Plus,T1,T2>::T> operator+(const Rat<nd1,nx,T1> &P, const Rat<nd2,nx,T2> &Q) {
    const int nd=(nd1>nd2?nd2:nd1);
    typedef typename TypePromote<Plus,T1,T2>::T T;
    return converter(P,Relative_Number<nd>(),Relative_Number<nx>(),T()) + converter(Q,Relative_Number<nd>(),Relative_Number<nx>(),T());
}


template <int nd1, int nd2, int nx, class T1, class T2>
Rat<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Minus,T1,T2>::T> operator-(const Rat<nd1,nx,T1> &P, const Rat<nd2,nx,T2> &Q) {
    const int nd=(nd1>nd2?nd2:nd1);
    typedef typename TypePromote<Minus,T1,T2>::T T;
    return converter(P,Relative_Number<nd>(),Relative_Number<nx>(),T()) - converter(Q,Relative_Number<nd>(),Relative_Number<nx>(),T());
}


template <int nd1, int nd2, int nx, class T1, class T2>
Rat<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Multiplies,T1,T2>::T> operator*(const Rat<nd1,nx,T1> &P, const Rat<nd2,nx,T2> &Q) {
    const int nd=(nd1>nd2?nd2:nd1);
    typedef typename TypePromote<Multiplies,T1,T2>::T T;
    return converter(P,Relative_Number<nd>(),Relative_Number<nx>(),T()) * converter(Q,Relative_Number<nd>(),Relative_Number<nx>(),T());
}


template <int nd1, int nd2, int nx, class T1, class T2>
Rat<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Divides,T1,T2>::T> operator/(const Rat<nd1,nx,T1> &P, const Rat<nd2,nx,T2> &Q) {
    const int nd=(nd1>nd2?nd2:nd1);
    typedef typename TypePromote<Divides,T1,T2>::T T;
    return converter(P,Relative_Number<nd>(),Relative_Number<nx>(),T()) / converter(Q,Relative_Number<nd>(),Relative_Number<nx>(),T());
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T> operator+(const Rat<nd,nx,T1> &P, const T2 &t) {
    return P+Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T>(t);
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T> operator+(const T2 &t, const Rat<nd,nx,T1> &P) {
    return Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T>(t)+P;
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T> operator-(const Rat<nd,nx,T1> &P, const T2 &t) {
    return P-Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T>(t);
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T> operator-(const T2 &t, const Rat<nd,nx,T1> &P) {
    return Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T>(t)-P;
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T> operator*(const T2 &t, const Rat<nd,nx,T1> &P) {
    return Rat<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(t*P.numerator(),P.denominator());
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T> operator*(const Rat<nd,nx,T1> &P, const T2 &t) {
    return Rat<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(P.numerator()*t,P.denominator());
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> operator/(const T2 &t, const Rat<nd,nx,T1> &P) {
    T1 div=P.numerator()[0];
    return Rat<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(P.denominator()*(t/div),P.numerator()/div);
}

template <int nd, int nx, class T1, class T2>
Rat<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> operator/(const Rat<nd,nx,T1> &P, const T2 &t) {
    return Rat<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T>(P.numerator()/t,P.denominator());
}

template <int nd, int nx, class T>
Rat<nd,nx,T> pow(const Rat<nd,1,T> &P, int a) {
    Rat<nd,nx,T> res = P;
    for (int i=1;i<a;i++)
        res = res * P;
    return res;
}

template <int nd, int nx, class T>
typename TypePromote<Abs,T>::T abs_indication(const Rat<nd,nx,T> &P) {
    return abs_indication(P.numerator()[0]);
}

template <int nd, int nx, class T>
Rat<nd,nx,typename TypePromote<Abs,T>::T> abs(const Rat<nd,nx,T> &P) {
    return Rat<nd,nx,typename TypePromote<Abs,T>::T>(abs(P.numerator()),abs(P.denominator()));
}

template <int nd, int nx, class T>
Rat<nd,nx,typename TypePromote<Conj,T>::T> conj(const Rat<nd,nx,T> &P) {
    return Rat<nd,nx,typename TypePromote<Conj,T>::T>(conj(P.numerator()),conj(P.denominator()));
}

template <int nd, int nx, class T>
Rat<nd,nx,typename TypePromote<Real,T>::T> real(const Rat<nd,nx,T> &P) {
    return Rat<nd,nx,typename TypePromote<Real,T>::T>(real(P.numerator()),real(P.denominator()));
}

template <int nd, int nx, class T>
Rat<nd,nx,typename TypePromote<Imag,T>::T> imag(const Rat<nd,nx,T> &P) {
    return Rat<nd,nx,typename TypePromote<Imag,T>::T>(imag(P.numerator()),imag(P.denominator()));
}

template<int m, int n,class TT> struct TypeInformation<Rat<m,n,TT> > {
    static const int res = TypeInformation<TT>::res;
    static const int englobing = 1 + TypeInformation<TT>::englobing;
    static const bool is_scalar = true;
    typedef TT SubType;
    template<class TV> struct Variant { typedef Rat<m,n,TV> T; };
    template<class TV> struct DeepVariant { typedef Rat<m,n,class TypeInformation<TT>::template DeepVariant<TV>::T> T; };
    static std::string type() { return "Rat<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};

template<int m, int n,class TT> struct HasTypeInformation<Rat<m,n,TT> > { static const bool res = true; };

}

#endif // RATIONAL_FUNCTIONS_H
