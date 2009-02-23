# -*- coding: utf-8 -*-
print """// file generated from polynomials.h.py. Do not modify

#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include <containers/vec.h>
#include <containers/algo.h>

#include "pol_every_degree.h"

namespace LMT {

/**
  @author Gouttebroze
*/

/*!
\\generic_comment Pol 
    \\brief polynômes à une ou plusieurs indéterminées et de degré quelconque bornés

     = Remarque générale
        Pour pouvoir manipuler des polynômes (mono et multivariables), il faut utiliser le fichier polynomials.h

        \\relates PolApprox
        \\relates RatApprox
        \\relates Rat

    = Parametres templates pour les polynômes 
        Il y a trois parametres templates pour définir un polynome : Pol<nd,nx,T>
    
        * nd est le degré maximal du polynome (valeur par défaut : 4)
        * nx est le nombre de variables du polynome (valeur par défaut : 1)
        * T est le type des coefficients du polynomes (valeur par défaut : double)
    
        Pour diminuer les temps de calcus, il y a une spécialisation de la classe Pol pour les polynomes monovariables (nx=1). Ils s'utilisent donc légèrement différement que les polynomes multivariables. 

    = Foire aux questions pour les polynômes :
    
        * [[#1| Comment créer un polynome constant ?]]
        * [[#2| Comment afficher un polynome ?]]
        * [[#3| Comment récupérer les coefficients d'un polynome ?]]
        * [[#4| Comment récupérer les puissances d'un polynome ?]]
        * [[#5| Comment évaluer un polynome multivariables en un point ?]]
        * [[#6| Comment évaluer un polynome monovariable en un point ?]]
        * [[#7| Comment dériver un polynome multivariables ?]]
        * [[#8| Comment dériver un polynome monovariable ?]]
        * [[#9| Comment intégrer un polynome monovariable ?]]
        * [[#10| Comment effectuer des opérations algébriques sur des polynomes ?]]
        * [[#11| Comment obtenir les racines d'un polynome monovariable ?]]

    = Réponses :

        * \\anchor 1 Pour créer un polynome constant égal a 4 :
            \\code C/C++
                Pol<nd,nx,T> P(4);
        
        * \\anchor 2 Pour afficher le polynome P :
            \\code C/C++
                cout << P << endl;
                OU
                PRINT(P);
        * \\anchor 3 Pour récupérer les coefficients du polynome P :
            \\code C/C++
                Vec<T> V=P.coefficients();
        * \\anchor 4 Pour récupérer les puissances du polynome P :
            \\code C/C++
                Vec<Vec<unsigned,nx> > V=P.powers();
        * \\anchor 5 Pour évaluer le polynome de 3 variables P au point (4,-2,1) :
            \\code C/C++
                Pol<nd,3,T> P = ... blabla ...
                Vec<T,3> V(4,-2,1);
                Vec<T> W=P(V);
        * \\anchor 6 Pour évaluer le polynome monovariable P au point 4 :
            \\code C/C++
                Pol<nd,1,T> P = ... blabla ...
                T s=P(V);
        * \\anchor 7 Pour obtenir les dérivées du polynome multivariables P :
            \\code C/C++
                Vec<Pol<nd-1,nx,T>,nx> V=P.derivative();
        * \\anchor 8 Pour obtenir la dérivée du polynome monovariable P :
            \\code C/C++
                Pol<nd-1,nx,T> Q=P.derivative();
        * \\anchor 9 Pour obtenir la primitive du polynome monovariable P qui s'annule en a:
            \\code C/C++
                T a; Pol<nd-1,nx,T> Q=P.integral(a);
        * \\anchor 10 Pour effectuer des opérations algébriques sur des polynomes P et Q :
            \\code C/C++
                Pol<nd,nx,T> R=P+Q;
                Pol<nd,nx,T> R=P-Q;
                Pol<nd,nx,T> R=P*Q;
                Pol<nd,nx,T> R=P/Q; (pour la division, un développement de Taylor est effectué autour de 0)
        * \\anchor 11 Pour obtenir les racines du polynome monovariable P :
            \\code C/C++
                Vec<T> V=P.roots(); 

    \\friend camille.gouttebroze@lmt.ens-cachan.fr
    \\friend raphael.pasquier@lmt.ens-cachan.fr
    \\friend hugo.leclerc@lmt.ens-cachan.fr

    \\keyword Mathématiques/Objet

    \\author Camille Gouttebroze
*/
"""

lst = [
    ('int nx, ','nx','Vec<',',nx>'),
    ('','1','',''),
]

for temp,nx,vd,vf in lst :
    if nx=='nx':
        print 'template <int nd=4,int nx=1,class T=double>'
        print 'class Pol : public PolEveryDegree<nd,nx,T> {'
    else :
        print 'template <int nd, class T>'
        print 'class Pol<nd,1,T> : public PolEveryDegree<nd,1,T>  {'
    print """
public:
      
    Pol ():PolEveryDegree<nd,"""+nx+""",T>() {}
    template <class T2, int nd2> Pol (const Vec<T2,nd2> &V):PolEveryDegree<nd,"""+nx+""",T>(V) {} ///Construit le polynome a partir de ses coefficients
    Pol (const T &a):PolEveryDegree<nd,"""+nx+""",T>(a) {} ///Construit le polynome constant egal a a
    Pol (const T &a, const T &b, unsigned q):PolEveryDegree<nd,"""+nx+""",T>(a,b,q) {} ///Construit le polynome a + b*Xq;
    
    template <int nd2, class T2> Pol (const Pol<nd2,"""+nx+""",T2> &P); ///Construit un polynome a partir d'un autre polynome avec """+nx+""" variable(s)
    template <int nx2, class T2, class T3> Pol (const Pol<nd,nx2,T2> &P, const """+vd+"""int"""+vf+""" &vq, const Vec<T3,nx2-"""+nx+"""> &vx); ///Construit un polynome a partir d'un autre polynome avec plus de variables
    template <int nx2, class T2> Pol (const Pol<nd,nx2,T2> &P, const """+vd+"""int"""+vf+""" &vq); ///Construit un polynome a partir d'un autre polynome avec plus de variables

    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const """+vd+"""T2"""+vf+"""&x) const; /// Renvoie la valeur du polynome en x
    typedef Pol<(nd>0?nd-1:nd),"""+nx+""",T> Derivative;
    """+vd+"""Derivative"""+vf+""" derivative() const; ///Renvoie les polynomes derives

    Pol<nd,"""+nx+""",T> operator-() const; ///Renvoie le polynome oppose
    template <class T2> void operator*= (const Pol<nd,"""+nx+""",T2> &P); /// Multiplie le polynome par P
    template <class T2> void operator/= (const Pol<nd,"""+nx+""",T2> &P); /// Divise le polynome par P
    """
    if nx=='nx':
        print 'private:'
        print '    static bool init_deriv;'
        print '    static void initialize_deriv();'
        print '    static Vec<Vec<unsigned>,Pol<nd,nx,T>::dim> deriv_var;'
        print '    static Vec<Vec<unsigned>,Pol<nd,nx,T>::dim> deriv_ind;'
        print '    static Vec<Vec<T>,Pol<nd,nx,T>::dim> deriv_coef;'
        print 'public:'
        print '    static bool init_mult;'
        print '    static void initialize_mult();'
        print '    static Vec<Vec<Vec<unsigned,2> >,Pol<nd,nx,T>::dim> mult;'
        print '    static Vec<bool,nd> init_tronc;'
        print '    template <unsigned ne> static void initialize_tronc (Number<ne>);'
        print '    static Vec<Vec<unsigned>,nd> tronc;'
        print '    static Vec<bool,Deux_Puissance<nx>::valeur> init_restriction;'
        print '    template <int ny> static void initialize_restriction (const Vec<int,ny> &vq);'
        print '    static Vec<Vec<Vec<unsigned> >,Deux_Puissance<nx>::valeur> restriction;'
        print '    template <int nx2, class T2> Pol (const Pol<nd,nx2,T2> &P, const Vec<int,nx2> &vq); ///Construit un polynome a partir d un autre polynome'
        print '    template <int ny, class T2> Pol<nd,nx-ny,typename TypePromote<Multiplies,T,T2>::T> operator() (const Vec<T2,ny> &V, const Vec<int,ny> &Vq) const; /// Renvoie un polynome extrait'
    else :
        print 'public :'
        print '    template <class T2> Pol (const Pol<nd,1,T2> &P, const Vec<int,1> &vq); ///Construit un polynome a partir d un autre polynome'
        print '    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,1> &V) const; ///Renvoie le vecteur des valeurs du polynome en toutes les valeurs de V'
        print '    Pol<nd+1,1,T> integral (const T &a) const; ///Renvoie le polynome integrale qui prend a comme valeur en 0'
        print '    int MaxPositivesRoots() const; ///Renvoie le nombre maximal de racines positives'
        print '    int MaxNegativesRoots() const; ///Renvoie le nombre maximal de racines negatives'
        print '    T RootsUpperBound() const; ///Renvoie un majorant des racines'
        print '    T RootsLowerBound() const; ///Renvoie un minorant des racines'
        print '    Pol<nd,1,T> remainder(const Pol<nd,1,T> &P) const; ///Renvoie le reste de la division par un polynome'
        print '    T dichotomy (const T &a, const T &b) const; ///Cherche une racine par dichotomie entre a et b'
        print '    T newton(const T &d, bool b, int imax) const; ///Cherche une racine par l algorithme de Newton en partant de d'
        print '    T householder(const T &d, bool b, int imax) const; ///Cherche une racine par l algorithme de Householder en partant de d'
        print '    Vec<T> roots() const; ///Renvoie les racines du polynome'
    print """
};

template <int nd, """+temp+"""class T>
template <int nd2, class T2>
Pol<nd,"""+nx+""",T>::Pol(const Pol<nd2,"""+nx+""",T2> &P) {"""
    if nx=='nx' :
        print """
    if (Pol<(nd<nd2?nd2:nd),nx,T>::init_tronc[(nd>nd2?nd2:nd)])
        Pol<(nd<nd2?nd2:nd),nx,T>::initialize_tronc(Number<(nd>nd2?nd2:nd)>());
    if (nd2>nd) {
        for (int i=0;i<PolEveryDegree<nd,"""+nx+""",T>::dim;i++)
            PolEveryDegree<nd,"""+nx+""",T>::coefs[i]=P.coefficients()[Pol<nd2,nx,T>::tronc[nd][i]];
    }
    else if(nd2<nd) {
        PolEveryDegree<nd,"""+nx+""",T>::coefs.set(T(0));
        for (int i=0;i<Pol<nd2,nx,T2>::dim;i++)
            PolEveryDegree<nd,"""+nx+""",T>::coefs[tronc[nd2][i]]=P.coefficients()[i];
    }
    else
        PolEveryDegree<nd,"""+nx+""",T>::coefs=P.coefficients();"""
    else :
        print """
    for(unsigned i=0;i<=min(nd,nd2);++i)
        PolEveryDegree<nd,"""+nx+""",T>::coefs[ i ] = P.coefficients()[i];
    for(unsigned i=nd2+1;i<=nd;++i)
        PolEveryDegree<nd,"""+nx+""",T>::coefs[ i ] = 0;"""
    print """
}

template <int nd, """+temp+"""class T>
template <int nx2, class T2, class T3>
Pol<nd,"""+nx+""",T>::Pol(const Pol<nd,nx2,T2> &P, const """+vd+"""int"""+vf+""" &vq, const Vec<T3,nx2-"""+nx+"""> &vx) {"""
    if nx=='nx' :
        print """
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
    PolEveryDegree<nd,"""+nx+""",T>::coefs.set(T(0));"""
    else :
        print """
    int rest=1;
    for (int j=0;j<vq;j++)
        rest*=2;
    Vec<int,nx2-1> vr=range(0,nx2-1);
    for (int j=vq;j<nx2-1;j++)
        vr[j]++;
    if (Pol<nd,nx2,T>::init_restriction[rest])
        Pol<nd,nx2,T>::initialize_restriction(Vec<int,1>(vq));"""
    print """    for (int i=0;i<PolEveryDegree<nd,"""+nx+""",T>::dim;i++)
        for (int j=0;j<Pol<nd,nx2,T>::restriction[rest][i].size();j++) {
            T tmp=P.coefficients()[Pol<nd,nx2,T>::restriction[rest][i][j]];
            for (int k=0;k<nx2-"""+nx+""";k++)
                tmp*=pow(vx[k],int(Pol<nd,nx2,T>::puissances[Pol<nd,nx2,T>::restriction[rest][i][j]][vr[k]]));
            PolEveryDegree<nd,"""+nx+""",T>::coefs[i]+=tmp;
        }
}

template <int nd, """+temp+"""class T>
template <int nx2, class T2>
Pol<nd,"""+nx+""",T>::Pol(const Pol<nd,nx2,T2> &P, const """+vd+"""int"""+vf+""" &vq) {
    Vec<T,nx2-"""+nx+"""> vx;
    vx.set(T(0));
    *this=Pol(P,vq,vx);
}

template <int nd, """+temp+"""class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Pol<nd,"""+nx+""",T>::operator() (const """+vd+"""T2"""+vf+"""&x) const {"""
    if nx=='nx' :
        print '    if (PolEveryDegree<nd,'+nx+',T>::init_puissances)'
        print '        PolEveryDegree<nd,'+nx+',T>::initialize_puissances();'
    print """
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    TR res = PolEveryDegree<nd,"""+nx+""",T>::coefs[0];
    for (unsigned i=1;i<PolEveryDegree<nd,"""+nx+""",T>::dim;i++) {"""
    if nx=='nx' :
        print '        TR tmp=PolEveryDegree<nd,'+nx+',T>::coefs[i];'
        print '        for (int k=0;k<nx;k++)'
        print '            tmp*=pow(x[k],int(PolEveryDegree<nd,'+nx+',T>::puissances[i][k]));'
        print '        res+=tmp;'
    else :
        print '        res += TR(PolEveryDegree<nd,'+nx+',T>::coefs[i]) * ::pow(TR(x),i);'
    print """    }
    return res;
}

template <int nd, """+temp+"""class T>
"""+vd+"""typename Pol<nd,"""+nx+""",T>::Derivative"""+vf+""" Pol<nd,"""+nx+""",T>::derivative() const {"""
    if nx=='nx' :
        print """    if (init_deriv)
        initialize_deriv();
    Vec<Derivative,nx> res;
    Vec<Vec<T,Derivative::dim>,nx> res_vec;
    for (int i=1;i<PolEveryDegree<nd,"""+nx+""",T>::dim;i++)
        for (int j=0;j<deriv_ind[i].size();j++)
            res_vec[deriv_var[i][j]][deriv_ind[i][j]]=deriv_coef[i][j]*PolEveryDegree<nd,"""+nx+""",T>::coefs[i];
    for (int i=0;i<nx;i++)
        res[i]=Derivative(res_vec[i]);
    return res;"""
    else :
        print """
    Vec<T,Derivative::dim> coefficientsDerivee;
    for (unsigned i=0;i<Derivative::dim;i++)
        coefficientsDerivee[i]=PolEveryDegree<nd,"""+nx+""",T>::coefs[i+1]*(i+1);
    return Derivative(coefficientsDerivee);"""
    print """
}

template <int nd, """+temp+"""class T>
Pol<nd,"""+nx+""",T> Pol<nd,"""+nx+""",T>::operator-() const {
    return Pol<nd,"""+nx+""",T>(-PolEveryDegree<nd,"""+nx+""",T>::coefs);
}

template <int nd, """+temp+"""class T>
template <class T2>
void Pol<nd,"""+nx+""",T>::operator*= (const Pol<nd,"""+nx+""",T2> &P) {
    PolEveryDegree<nd,"""+nx+""",T>::coefs=(*this*P).coefficients();
}

template <int nd, """+temp+"""class T>
template <class T2>
void Pol<nd,"""+nx+""",T>::operator/= (const Pol<nd,"""+nx+""",T2> &P) {
    PolEveryDegree<nd,"""+nx+""",T>::coefs-=(*this/P).coefficients();
}

"""

    if nx=='nx':
        print """
template <int nd, int nx, class T>
bool Pol<nd,nx,T>::init_deriv=1;

template <int nd, int nx, class T>
bool Pol<nd,nx,T>::init_mult=1;

template <int nd, int nx, class T>
Vec<bool,nd> Pol<nd,nx,T>::init_tronc=1;

template <int nd, int nx, class T>
Vec<bool,Deux_Puissance<nx>::valeur> Pol<nd,nx,T>::init_restriction=1;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned,2> >,Pol<nd,nx,T>::dim> Pol<nd,nx,T>::mult;

template <int nd, int nx, class T>
Vec<Vec<unsigned>,Pol<nd,nx,T>::dim> Pol<nd,nx,T>::deriv_var;

template <int nd, int nx, class T>
Vec<Vec<unsigned>,Pol<nd,nx,T>::dim> Pol<nd,nx,T>::deriv_ind;

template <int nd, int nx, class T>
Vec<Vec<T>,Pol<nd,nx,T>::dim> Pol<nd,nx,T>::deriv_coef;

template <int nd, int nx, class T>
Vec<Vec<unsigned>,nd> Pol<nd,nx,T>::tronc;

template <int nd, int nx, class T>
Vec<Vec<Vec<unsigned> >,Deux_Puissance<nx>::valeur> Pol<nd,nx,T>::restriction;

template <int nd, int nx, class T>
void Pol<nd,nx,T>::initialize_deriv() {
    if (PolEveryDegree<nd,"""+nx+""",T>::init_puissances)
        PolEveryDegree<nd,"""+nx+""",T>::initialize_puissances();
    if (Derivative::init_puissances)
        Derivative::initialize_puissances();
    init_deriv=0;
    for (unsigned i=1;i<PolEveryDegree<nd,"""+nx+""",T>::dim;i++)
        for (int j=0;j<nx;j++)
            if (PolEveryDegree<nd,"""+nx+""",T>::puissances[i][j]>0) {
                Vec<unsigned,nx> puissances_deriv_j=PolEveryDegree<nd,"""+nx+""",T>::puissances[i];
                puissances_deriv_j[j]--;
                for (unsigned alphas=0;alphas<Derivative::dim;alphas++)
                    if (min(Derivative::puissances[alphas]==puissances_deriv_j)) {
                        deriv_var[i].push_back(j);
                        deriv_ind[i].push_back(alphas);
                        deriv_coef[i].push_back(T(PolEveryDegree<nd,"""+nx+""",T>::puissances[i][j]));
                        break;
                    }
            }
}

template <int nd, int nx, class T>
void Pol<nd,nx,T>::initialize_mult() {
    if (PolEveryDegree<nd,"""+nx+""",T>::init_puissances)
        PolEveryDegree<nd,"""+nx+""",T>::initialize_puissances();
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
    for (unsigned i=0;i<PolEveryDegree<nd,"""+nx+""",T>::dim;i++)
        for (unsigned alphas=0;alphas<PolEveryDegree<nd,"""+nx+""",T>::dim;alphas++)
            if (min(PolEveryDegree<nd,"""+nx+""",T>::puissances[alphas]<=PolEveryDegree<nd,"""+nx+""",T>::puissances[i])) {
                unsigned c1=0;
                unsigned c2=0;
                for (unsigned a=0;a<nx;a++) {
                    unsigned aux1=0;
                    unsigned aux2=0;
                    for (unsigned gamma=a+1;gamma<nx;gamma++) {
                        aux1+=PolEveryDegree<nd,"""+nx+""",T>::puissances[i][gamma]-PolEveryDegree<nd,"""+nx+""",T>::puissances[alphas][gamma];
                        aux2+=PolEveryDegree<nd,"""+nx+""",T>::puissances[alphas][gamma];
                    }
                    c1+=tmp[a][nd-aux1][PolEveryDegree<nd,"""+nx+""",T>::puissances[i][a]-PolEveryDegree<nd,"""+nx+""",T>::puissances[alphas][a]];
                    c2+=tmp[a][nd-aux2][PolEveryDegree<nd,"""+nx+""",T>::puissances[alphas][a]];
                }
                Vec<unsigned,2> aux;
                aux[0]=c1;
                aux[1]=c2;
                mult[i].push_back(aux);
            }
}

template <int nd, int nx, class T>
template <unsigned ne>
void Pol<nd,nx,T>::initialize_tronc(Number<ne>) {
    if (PolEveryDegree<nd,"""+nx+""",T>::init_puissances)
        PolEveryDegree<nd,"""+nx+""",T>::initialize_puissances();
    if (Pol<ne,nx,T>::init_puissances)
        Pol<ne,nx,T>::initialize_puissances();
    init_tronc[ne]=0;
        tronc[ne].resize(Pol<ne,nx,T>::dim);
    for (unsigned i=0;i<tronc[ne].size();i++)
        for (int j=0;j<PolEveryDegree<nd,"""+nx+""",T>::dim;j++)
            if (Pol<ne,nx,T>::puissances[i]==PolEveryDegree<nd,"""+nx+""",T>::puissances[j]) {
                tronc[ne][i]=j;
                break;
            }
}

template <int nd, int nx, class T>
template <int ny>
void Pol<nd,nx,T>::initialize_restriction(const Vec<int,ny> &vq) {
    if (PolEveryDegree<nd,"""+nx+""",T>::init_puissances)
        PolEveryDegree<nd,"""+nx+""",T>::initialize_puissances();
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
        for (int j=0;j<PolEveryDegree<nd,"""+nx+""",T>::dim;j++)
            if (Pol<nd,ny,T>::puissances[i]==PolEveryDegree<nd,"""+nx+""",T>::puissances[j][vq])
                restriction[rest][i].push_back(j);
    }
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
    PolEveryDegree<nd,"""+nx+""",T>::coefs.set(T(0));
    for (int i=0;i<Pol<nd,nx2,T2>::dim;i++)
        PolEveryDegree<nd,"""+nx+""",T>::coefs[restriction[rest][i][0]]=P.coefficients()[i];
}"""

    else :
        print """
template <int nd, class T>
template <class T2> Pol<nd,1,T>::Pol (const Pol<nd,1,T2> &P, const Vec<int,1> &vq) {
    PolEveryDegree<nd,"""+nx+""",T>::coefs=P.coefficients();
}

template <int nd, class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Pol<nd,1,T>::operator() (const Vec<T2,1> &x) const {
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    using namespace std;
    TR res = PolEveryDegree<nd,"""+nx+""",T>::coefs[0];
    for(unsigned i=1;i<PolEveryDegree<nd,"""+nx+""",T>::dim;i++)
        res += TR(PolEveryDegree<nd,"""+nx+""",T>::coefs[i]) * ::pow(TR(x[0]),i);
    return res;
}

template <int nd, class T>
Pol<nd+1,1,T> Pol<nd,1,T>::integral(const T &a) const {
    Vec<T,PolEveryDegree<nd,"""+nx+""",T>::dim+1> coefficientsintegrale;
    coefficientsintegrale.set(T(0));
    coefficientsintegrale[0]=a;
    for (int i=1;i<PolEveryDegree<nd,"""+nx+""",T>::dim+1;i++)
        coefficientsintegrale[i]=PolEveryDegree<nd,"""+nx+""",T>::coefs[i-1]/i;
    return Pol<nd+1,1,T> (coefficientsintegrale);
}

template <int nd, class T>
int Pol<nd,1,T>::MaxPositivesRoots() const {
    int res=0;
    Vec<T> coefficients=PolEveryDegree<nd,"""+nx+""",T>::coefs;
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
    Vec<T> coefficients=PolEveryDegree<nd,"""+nx+""",T>::coefs;
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
    typename TypePromote<Abs,T>::T titi=abs(PolEveryDegree<nd,"""+nx+""",T>::coefs[PolEveryDegree<nd,"""+nx+""",T>::dim-1]);
    for (int i=PolEveryDegree<nd,"""+nx+""",T>::dim-2; i>0 && titi==T(0); i--)
        if (abs(PolEveryDegree<nd,"""+nx+""",T>::coefs[i]))
            titi==PolEveryDegree<nd,"""+nx+""",T>::coefs[i];
    Vec<T,PolEveryDegree<nd,"""+nx+""",T>::dim> tutu=PolEveryDegree<nd,"""+nx+""",T>::coefs/titi;
    typename TypePromote<Abs,T>::T toto=norm_inf(tutu);
    return typename TypePromote<Abs,T>::T(1)+toto;
}

template <int nd, class T>
T Pol<nd,1,T>::RootsLowerBound() const {
    typename TypePromote<Abs,T>::T titi=abs(PolEveryDegree<nd,"""+nx+""",T>::coefs[PolEveryDegree<nd,"""+nx+""",T>::dim-1]);
    for (int i=PolEveryDegree<nd,"""+nx+""",T>::dim-2; i>0 && titi==T(0); i--)
        if (abs(PolEveryDegree<nd,"""+nx+""",T>::coefs[i]))
            titi==PolEveryDegree<nd,"""+nx+""",T>::coefs[i];
    Vec<T,PolEveryDegree<nd,"""+nx+""",T>::dim> tutu=PolEveryDegree<nd,"""+nx+""",T>::coefs/titi;
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
    while ((e-c)/(abs(e)+abs(c))>5*PolEveryDegree<nd,"""+nx+""",T>::dim*std::numeric_limits<T>::epsilon()) {
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
    while (abs(a-b)/max(abs(a),abs(b))>10*PolEveryDegree<nd,"""+nx+""",T>::dim*std::numeric_limits<T>::epsilon()&&compteur<imax) {
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
    while (abs(a-b)/max(abs(a),abs(b))>10*PolEveryDegree<nd,"""+nx+""",T>::dim*std::numeric_limits<T>::epsilon()&&compteur<imax) {
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
    Vec<T> r=PolEveryDegree<nd,"""+nx+""",T>::coefs;
    T norm=norm_inf(r);
    while (r.size()>1 and abs(r[r.size()-1])/norm<std::numeric_limits<T>::epsilon())
        r.pop_back();
    Vec<T> d=D.coefficients();
    norm=norm_inf(d);
    while (d.size()>1 and abs(d[d.size()-1])/norm<std::numeric_limits<T>::epsilon())
        d.pop_back();
        if (d.size()<=r.size()) {
        for (unsigned i=1;i<=PolEveryDegree<nd,"""+nx+""",T>::coefs.size()-d.size()+1;i++) {
            T aux=r[r.size()-1]/d[d.size()-1];
            r.pop_back();
            for (unsigned j=0;j<d.size()-1;j++)
                r[r.size()-d.size()+j+1]-=aux*d[j];
        }
    }
    return Pol<nd,1,T>(r);
}

template <int nd, class T>
Vec<T> Pol<nd,1,T>::roots () const {
    Vec<T> res;
    int taille=PolEveryDegree<nd,"""+nx+""",T>::dim;
    for (int i=PolEveryDegree<nd,"""+nx+""",T>::dim-1;PolEveryDegree<nd,"""+nx+""",T>::coefs[i]==T(0);i--)
        taille--;
    if (taille==2)
        res.push_back(-PolEveryDegree<nd,"""+nx+""",T>::coefs[0]/PolEveryDegree<nd,"""+nx+""",T>::coefs[1]);
    else if (taille==3) {
        T delta=PolEveryDegree<nd,"""+nx+""",T>::coefs[1]*PolEveryDegree<nd,"""+nx+""",T>::coefs[1]-4*PolEveryDegree<nd,"""+nx+""",T>::coefs[0]*PolEveryDegree<nd,"""+nx+""",T>::coefs[2];
        if (delta==0)
            res.push_back(-0.5*PolEveryDegree<nd,"""+nx+""",T>::coefs[1]/PolEveryDegree<nd,"""+nx+""",T>::coefs[2]);
        if (delta>0) {
            res.push_back(-0.5*(PolEveryDegree<nd,"""+nx+""",T>::coefs[1]+sqrt(delta))/PolEveryDegree<nd,"""+nx+""",T>::coefs[2]);
            res.push_back(-0.5*(PolEveryDegree<nd,"""+nx+""",T>::coefs[1]-sqrt(delta))/PolEveryDegree<nd,"""+nx+""",T>::coefs[2]);
        }
    }
    else if (taille==4) {
        T a=PolEveryDegree<nd,"""+nx+""",T>::coefs[2]/PolEveryDegree<nd,"""+nx+""",T>::coefs[3];
        T b=PolEveryDegree<nd,"""+nx+""",T>::coefs[1]/PolEveryDegree<nd,"""+nx+""",T>::coefs[3];
        T c=PolEveryDegree<nd,"""+nx+""",T>::coefs[0]/PolEveryDegree<nd,"""+nx+""",T>::coefs[3];
        T p = b - std::pow(a,2)/3.;
        T q = std::pow(a,3)/13.5 - a*b/3 + c;
        T delta = 4.*std::pow(p,T(3))+27.*std::pow(q,T(2));
        if (delta>=0) {
            T u=(-13.5*q+sqrt(6.75*delta));
            T v=(-13.5*q-sqrt(6.75*delta));
            res.push_back((sgn(u)*std::pow(std::abs(u),T(1)/T(3))+sgn(v)*std::pow(std::abs(v),T(1)/T(3))-a)/3.);
        }
        if (delta<0) {
            std::complex<T> j(-0.5,sqrt(3.)/2.);
            std::complex<T> v(-13.5*q,sqrt(-6.75*delta));
            std::complex<T> u=std::pow(v,T(1)/T(3));
            res.push_back((2.*std::real(u)-a)/3.);
            res.push_back((2.*std::real(j*u)-a)/3.);
            res.push_back((2.*std::real(j*j*u)-a)/3.);
            sort(res);
        }
    }
    else if (taille>4) {
        if (PolEveryDegree<nd,"""+nx+""",T>::coefs[0]!=0) {
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
            Vec<T> aux=PolEveryDegree<nd,"""+nx+""",T>::coefs;
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
}"""

print """
template<int m, int n,class TT> struct TypeInformation<Pol<m,n,TT> > {
    static const int res = TypeInformation<TT>::res;
    static const int englobing = 1 + TypeInformation<TT>::englobing;
    static const bool is_scalar = true;
    typedef TT SubType;
    template<class TV> struct Variant { typedef Pol<m,n,TV> T; };
    template<class TV> struct DeepVariant { typedef Pol<m,n,typename TypeInformation<TT>::template DeepVariant<TV>::T> T; };
    static std::string type() { return "Pol<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};

template<int m, int n,class TT> struct HasTypeInformation<Pol<m,n,TT> > { static const bool res = true; };

template<int m, int n,class TT> struct SubComplex<Pol<m,n,TT> > {
    typedef Pol<m,n,TT> TP;
    typedef typename TypeInformation<TP>::template Variant<typename SubComplex<typename TypeInformation<TP>::SubType>::T>::T T;
};

}

#include "pol_unary.h"
#include "pol_binary_with_scalar.h"
#include "pol_binary_same_degree.h"
#include "pol_binary_different_degree.h"
#include "pol_input_output.h"

#endif // POLYNOMIALS_H"""
