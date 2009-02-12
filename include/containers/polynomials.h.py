# -*- coding: utf-8 -*-
print """// file generated from polynomials.h.py. Do not modify

////////////////////////////////////
//  Author : Camille GOUTTEBROZE  //
//  gouttebroze@lmt.ens-cachan.fr //
////////////////////////////////////

#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include <containers/gnuplot.h>
#include <containers/vec.h>
#include <containers/algo.h>

namespace LMT {

/**
  @author Gouttebroze
*/

/*!
\\generic_comment Pol 
    \\brief polynômes à plusieurs indéterminées et de degré quelconque bornés

    Pol est une classe qui représente les polynômes à plusieurs indéterminés et de degré quelconque mais on fixe à la compilation le nombre d'indéterminés (paramètre template nx) ainsi que le même degré partiel maximum de chaque indéterminé (paramètre template nd). 
    Attention : Le stockage est de type dense ; cad on stocke la valeur de tous les monômes donc la taille augmente très vite avec le nombre d'indéterminées...

    \\relates PolApprox
    \\relates RatApprox
    \\relates Rat
    \\friend camille.gouttebroze@lmt.ens-cachan.fr
    \\friend raphael.pasquier@lmt.ens-cachan.fr
    \\friend hugo.leclerc@lmt.ens-cachan.fr

    \\keyword Mathématiques/Objet

    \\author Camille Gouttebroze
*/

template <unsigned nd, unsigned nx>
struct SommeDimPol;

template <unsigned nd, unsigned nx>
struct DimPol {
    static const unsigned valeur = SommeDimPol<nd,nx-1>::valeur;
};

template <unsigned nd>
struct DimPol<nd,1> {
    static const unsigned valeur = nd+1;
};

template <unsigned nd, unsigned nx>
struct SommeDimPol {
    static const unsigned valeur = DimPol<nd,nx>::valeur + SommeDimPol<nd-1,nx>::valeur;
};

template <unsigned nx>
struct SommeDimPol <0,nx> {
    static const unsigned valeur = 1 ;
};

template <unsigned N>
struct Deux_Puissance {
    static const unsigned valeur = 2 * Deux_Puissance<N-1>::valeur;
};

template <>
struct Deux_Puissance<0> {
    static const unsigned valeur = 1;
};
"""

lst = [
    ('int nx, ','nx','Vec<',',nx>'),
    ('','1','',''),
]

for temp,nx,vd,vf in lst :
    if nx=='nx':
        print 'template <int nd=4,int nx=1,class T=double>'
        print 'class Pol {'
    else :
        print 'template <int nd, class T>'
        print 'class Pol<nd,1,T> {'
    print """public:
    static const int degree=nd;
    static const int variables_number="""+nx+""";
    static const int dim=DimPol<nd,"""+nx+""">::valeur;
private :
    Vec<T,dim> coefs;
public:
    static bool init_puissances;
    static void initialize_puissances();
    static Vec<Vec<unsigned,"""+nx+""">,Pol<nd,"""+nx+""",T>::dim> puissances;
    Pol () {}
    template <class T2> Pol (const Vec<T2> &V); ///Construit le polynome a partir de ses coefficients
    template <class T2> Pol (const Vec<T2,Pol<nd,"""+nx+""",T2>::dim> &V); ///Construit le polynome a partir de ses coefficients
    template <int nd2, class T2> Pol (const Pol<nd2,"""+nx+""",T2> &P); ///Construit un polynome a partir d'un autre polynome avec """+nx+""" variable(s)
    template <int nx2, class T2, class T3> Pol (const Pol<nd,nx2,T2> &P, const """+vd+"""int"""+vf+""" &vq, const Vec<T3,nx2-"""+nx+"""> &vx); ///Construit un polynome a partir d'un autre polynome avec plus de variables
    template <int nx2, class T2> Pol (const Pol<nd,nx2,T2> &P, const """+vd+"""int"""+vf+""" &vq); ///Construit un polynome a partir d'un autre polynome avec plus de variables
    Pol (const T &a); ///Construit le polynome constant egal a a
    Pol (const T &a, const T &b, unsigned q); ///Construit le polynome a + b*Xq;
    template <class T2> Pol<nd,"""+nx+""",T> &operator= (const Pol<nd,"""+nx+""",T2> &P); ///Renvoie un polynome egal a P
    const Vec<T,dim> &coefficients() const {return coefs;} ///Renvoie les coefficients du polynome
    const Vec<Vec<unsigned,"""+nx+""">,Pol<nd,"""+nx+""",T>::dim> &powers(); ///Renvoie les puissances du polynome
    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const """+vd+"""T2"""+vf+"""&x) const; /// Renvoie la valeur du polynome en x
    typedef Pol<(nd>0?nd-1:nd),"""+nx+""",T> Derivative;
    """+vd+"""Derivative"""+vf+""" derivative() const; ///Renvoie les polynomes derives
    operator bool() const {return true;}
    Pol<nd,"""+nx+""",T> operator-() const; ///Renvoie le polynome oppose;
    template <class T2> bool operator== (const Pol<nd,"""+nx+""",T2> &P) const; /// Verifie si le polynome est egal a P
    template <class T2> bool operator!= (const Pol<nd,"""+nx+""",T2> &P) const; /// Verifie si le polynome est different de P
    template <class T2> void operator+= (const Pol<nd,"""+nx+""",T2> &P); /// Ajoute P au polynome
    template <class T2> void operator-= (const Pol<nd,"""+nx+""",T2> &P); /// Retranche P au polynome
    template <class T2> void operator*= (const Pol<nd,"""+nx+""",T2> &P); /// Multiplie le polynome par P
    template <class T2> void operator/= (const Pol<nd,"""+nx+""",T2> &P); /// Divise le polynome par P
    """
    if nx=='nx':
        print 'private:'
        print '    template <int nx_> static Vec<unsigned,nx_> next_power(const Vec<unsigned,nx_> &v);'
        print '    static Vec<unsigned,1> next_power(const Vec<unsigned,1> &v);'
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
bool Pol<nd,"""+nx+""",T>::init_puissances=1;

template <int nd, """+temp+"""class T>
Vec<Vec<unsigned,"""+nx+""">,Pol<nd,"""+nx+""",T>::dim> Pol<nd,"""+nx+""",T>::puissances;

template <int nd, """+temp+"""class T>
void Pol<nd,"""+nx+""",T>::initialize_puissances() {
    init_puissances=0;
    puissances[0].set(0);
    for (int i=1;i<dim;i++)"""
    if nx=='nx' :
        print '        puissances[i]=next_power(puissances[i-1]);'
    else :
        print '        puissances[i][0]=i;'
    print """
}

template <int nd, """+temp+"""class T>
template <class T2>
Pol<nd,"""+nx+""",T>::Pol(const Vec<T2> &V) {
    for(unsigned i=0; i<min(V.size(),coefs.size()); ++i)
        coefs[i] = T(V[i]);
    for(unsigned i=V.size(); i<coefs.size(); ++i)
        coefs[i] = T(0);
}

template <int nd, """+temp+"""class T>
template <class T2>
Pol<nd,"""+nx+""",T>::Pol(const Vec<T2,Pol<nd,"""+nx+""",T2>::dim> &V) {
    for(unsigned i=0; i<min(V.size(),coefs.size()); ++i)
        coefs[i] = T(V[i]);
    for(unsigned i=V.size(); i<coefs.size(); ++i)
        coefs[i] = T(0);
}

template <int nd, """+temp+"""class T>
template <int nd2, class T2>
Pol<nd,"""+nx+""",T>::Pol(const Pol<nd2,"""+nx+""",T2> &P) {"""
    if nx=='nx' :
        print """
    if (Pol<(nd<nd2?nd2:nd),nx,T>::init_tronc[(nd>nd2?nd2:nd)])
        Pol<(nd<nd2?nd2:nd),nx,T>::initialize_tronc(Number<(nd>nd2?nd2:nd)>());
    if (nd2>nd) {
        for (int i=0;i<dim;i++)
            coefs[i]=P.coefficients()[Pol<nd2,nx,T>::tronc[nd][i]];
    }
    else if(nd2<nd) {
        coefs.set(T(0));
        for (int i=0;i<Pol<nd2,nx,T2>::dim;i++)
            coefs[tronc[nd2][i]]=P.coefficients()[i];
    }
    else
        coefs=P.coefficients();"""
    else :
        print """
    for(unsigned i=0;i<=min(nd,nd2);++i)
        coefs[ i ] = P.coefficients()[i];
    for(unsigned i=nd2+1;i<=nd;++i)
        coefs[ i ] = 0;"""
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
    coefs.set(T(0));"""
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
    print """    for (int i=0;i<dim;i++)
        for (int j=0;j<Pol<nd,nx2,T>::restriction[rest][i].size();j++) {
            T tmp=P.coefficients()[Pol<nd,nx2,T>::restriction[rest][i][j]];
            for (int k=0;k<nx2-"""+nx+""";k++)
                tmp*=pow(vx[k],int(Pol<nd,nx2,T>::puissances[Pol<nd,nx2,T>::restriction[rest][i][j]][vr[k]]));
            coefs[i]+=tmp;
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
Pol<nd,"""+nx+""",T>::Pol(const T &a0) {
    coefs.set(T(0));
    coefs[0]=a0;
}

template <int nd, """+temp+"""class T>
Pol<nd,"""+nx+""",T>::Pol(const T &a, const T &b, unsigned q) {
    coefs.set(T(0));
    coefs[0]=a;
    if (init_puissances)
        initialize_puissances();
    for (int i=0;i<dim;i++)
        if (puissances[i][q]==1) {
            coefs[i]=b;
            break;
        }
}

template <int nd, """+temp+"""class T>
template <class T2>
Pol<nd,"""+nx+""",T> &Pol<nd,"""+nx+""",T>::operator= (const Pol<nd,"""+nx+""",T2> &P) {
    coefs=P.coefficients();
    return *this;
}

template <int nd, """+temp+"""class T>
const Vec<Vec<unsigned,"""+nx+""">,Pol<nd,"""+nx+""",T>::dim> &Pol<nd,"""+nx+""",T>::powers() {
    if (init_puissances)
        initialize_puissances();
    return puissances;
}

template <int nd, """+temp+"""class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Pol<nd,"""+nx+""",T>::operator() (const """+vd+"""T2"""+vf+"""&x) const {"""
    if nx=='nx' :
        print '    if (init_puissances)'
        print '        initialize_puissances();'
    print """
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    TR res = coefs[0];
    for (unsigned i=1;i<dim;i++) {"""
    if nx=='nx' :
        print '        TR tmp=coefs[i];'
        print '        for (int k=0;k<nx;k++)'
        print '            tmp*=pow(x[k],int(puissances[i][k]));'
        print '        res+=tmp;'
    else :
        print '        res += TR(coefs[i]) * ::pow(TR(x),i);'
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
    for (int i=1;i<dim;i++)
        for (int j=0;j<deriv_ind[i].size();j++)
            res_vec[deriv_var[i][j]][deriv_ind[i][j]]=deriv_coef[i][j]*coefs[i];
    for (int i=0;i<nx;i++)
        res[i]=Derivative(res_vec[i]);
    return res;"""
    else :
        print """
    Vec<T,Derivative::dim> coefficientsDerivee;
    for (unsigned i=0;i<Derivative::dim;i++)
        coefficientsDerivee[i]=coefs[i+1]*(i+1);
    return Derivative(coefficientsDerivee);"""
    print """
}

template <int nd, """+temp+"""class T>
Pol<nd,"""+nx+""",T> Pol<nd,"""+nx+""",T>::operator-() const {
    return Pol<nd,"""+nx+""",T>(-coefs);
}

template <int nd, """+temp+"""class T>
template <class T2>
bool Pol<nd,"""+nx+""",T>::operator== (const Pol<nd,"""+nx+""",T2> &P) const {
    return coefs==P.coefficients();
}

template <int nd, """+temp+"""class T>
template <class T2>
bool Pol<nd,"""+nx+""",T>::operator!= (const Pol<nd,"""+nx+""",T2> &P) const {
    return !(coefs==P.coefficients());
}

template <int nd, """+temp+"""class T>
template <class T2>
void Pol<nd,"""+nx+""",T>::operator+= (const Pol<nd,"""+nx+""",T2> &P) {
    coefs+=P.coefficients();
}

template <int nd, """+temp+"""class T>
template <class T2>
void Pol<nd,"""+nx+""",T>::operator-= (const Pol<nd,"""+nx+""",T2> &P) {
    coefs-=P.coefficients();
}

template <int nd, """+temp+"""class T>
template <class T2>
void Pol<nd,"""+nx+""",T>::operator*= (const Pol<nd,"""+nx+""",T2> &P) {
    coefs=(*this*P).coefficients();
}

template <int nd, """+temp+"""class T>
template <class T2>
void Pol<nd,"""+nx+""",T>::operator/= (const Pol<nd,"""+nx+""",T2> &P) {
    coefs-=(*this/P).coefficients();
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
template <int nx_>
Vec<unsigned,nx_> Pol<nd,nx,T>::next_power(const Vec<unsigned,nx_> &v) {
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
Vec<unsigned,1> Pol<nd,nx,T>::next_power(const Vec<unsigned,1> &v) {
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
                mult[i].push_back(aux);
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
    for (int i=0;i<Pol<nd,nx2,T2>::dim;i++)
        coefs[restriction[rest][i][0]]=P.coefficients()[i];
}"""

    else :
        print """
template <int nd, class T>
template <class T2> Pol<nd,1,T>::Pol (const Pol<nd,1,T2> &P, const Vec<int,1> &vq) {
    coefs=P.coefficients();
}

template <int nd, class T>
template <class T2>
typename TypePromote<Multiplies,T,T2>::T Pol<nd,1,T>::operator() (const Vec<T2,1> &x) const {
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    using namespace std;
    TR res = coefs[0];
    for(unsigned i=1;i<dim;i++)
        res += TR(coefs[i]) * ::pow(TR(x[0]),i);
    return res;
}

template <int nd, class T>
Pol<nd+1,1,T> Pol<nd,1,T>::integral(const T &a) const {
    Vec<T,dim+1> coefficientsintegrale;
    coefficientsintegrale.set(T(0));
    coefficientsintegrale[0]=a;
    for (int i=1;i<dim+1;i++)
        coefficientsintegrale[i]=coefs[i-1]/i;
    return Pol<nd+1,1,T> (coefficientsintegrale);
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
    typename TypePromote<Abs,T>::T titi=abs(coefs[dim-1]);
    for (int i=dim-2; i>0 && titi==T(0); i--)
        if (abs(coefs[i]))
            titi==coefs[i];
    Vec<T,dim> tutu=coefs/titi;
    typename TypePromote<Abs,T>::T toto=norm_inf(tutu);
    return typename TypePromote<Abs,T>::T(1)+toto;
}

template <int nd, class T>
T Pol<nd,1,T>::RootsLowerBound() const {
    typename TypePromote<Abs,T>::T titi=abs(coefs[dim-1]);
    for (int i=dim-2; i>0 && titi==T(0); i--)
        if (abs(coefs[i]))
            titi==coefs[i];
    Vec<T,dim> tutu=coefs/titi;
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
T Pol<nd,1,T>::newton (const T &d, bool c=0, int imax=100) const {
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
T Pol<nd,1,T>::householder (const T &d, bool c=0, int imax=100) const {
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
Pol<nd,1,T> Pol<nd,1,T>::remainder(const Pol<nd,1,T> &D) const {
    Vec<T> r=coefs;
    T norm=norm_inf(r);
    while (r.size()>1 and abs(r[r.size()-1])/norm<std::numeric_limits<T>::epsilon())
        r.pop_back();
    Vec<T> d=D.coefficients();
    norm=norm_inf(d);
    while (d.size()>1 and abs(d[d.size()-1])/norm<std::numeric_limits<T>::epsilon())
        d.pop_back();
        if (d.size()<=r.size()) {
        for (unsigned i=1;i<=coefs.size()-d.size()+1;i++) {
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
    int taille=dim;
    for (int i=dim-1;coefs[i]==T(0);i--);
        taille--;
    if (taille==2)
        res.push_back(-coefs[0]/coefs[1]);
    else if (taille==3) {
        T delta=coefs[1]*coefs[1]-4*coefs[0]*coefs[2];
        if (delta==0)
            res.push_back(-0.5*coefs[1]/coefs[2]);
        if (delta>0) {
            res.push_back(-0.5*(coefs[1]+sqrt(delta))/coefs[2]);
            res.push_back(-0.5*(coefs[1]-sqrt(delta))/coefs[2]);
        }
    }
    else if (taille==4) {
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
}"""

    print """
template <int nd, """+temp+"""class T1, class T2>
Pol<nd,"""+nx+""",typename TypePromote<Plus,T1,T2>::T> operator+ (const Pol<nd,"""+nx+""",T1> &P, const Pol<nd,"""+nx+""",T2> &Q) {
    return Pol<nd,"""+nx+""",typename TypePromote<Plus,T1,T2>::T>(P.coefficients()+Q.coefficients());
}

template <int nd, """+temp+"""class T1, class T2>
Pol<nd,"""+nx+""",typename TypePromote<Minus,T1,T2>::T> operator- (const Pol<nd,"""+nx+""",T1> &P, const Pol<nd,"""+nx+""",T2> &Q) {
    return Pol<nd,"""+nx+""",typename TypePromote<Minus,T1,T2>::T>(P.coefficients()-Q.coefficients());
}

template <int nd, """+temp+"""class T1, class T2>
Pol<nd,"""+nx+""",typename TypePromote<Multiplies,T1,T2>::T> operator* (const Pol<nd,"""+nx+""",T1> &P, const Pol<nd,"""+nx+""",T2> &Q) {
    typedef typename TypePromote<Multiplies,T1,T2>::T T;
    typedef Pol<nd,"""+nx+""",T> PdxT;
    Vec<T,PdxT::dim> res_vec;
    res_vec.set(T(0));"""
    if nx=='nx':
        print '    if (PdxT::init_mult)'
        print '         PdxT::initialize_mult();'
        print '     for (int i=0;i<PdxT::dim;i++)'
        print '         for (int j=0;j<PdxT::mult[i].size();j++)'
        print '             res_vec[i]+=P.coefficients()[PdxT::mult[i][j][0]]*Q.coefficients()[PdxT::mult[i][j][1]];'
    else :
        print '    for (int i=0;i<Pol<nd,1,T>::dim;i++)'
        print '        for (int j=0;j<=i;j++)'
        print '            res_vec[i]+=P.coefficients()[j]*Q.coefficients()[i-j];'
    print """    return PdxT(res_vec);
}

template <int nd1, int nd2, """+temp+"""class T1, class T2>
Pol<(nd1>nd2?nd1:nd2),"""+nx+""",typename TypePromote<Multiplies,T1,T2>::T> operator* (const Pol<nd1,"""+nx+""",T1> &P, const Pol<nd2,"""+nx+""",T2> &Q) {
    static const int nd = ( nd1 > nd2 ? nd1 : nd2 );
    typedef Pol<nd,"""+nx+""",typename TypePromote<Multiplies,T1,T2>::T> TP;
    return TP( P ) * TP( Q );
}

template <int nd, """+temp+"""class T1, class T2>
Pol<nd,"""+nx+""",typename TypePromote<Divides,T1,T2>::T> operator/ (const Pol<nd,"""+nx+""",T1> &P, const Pol<nd,"""+nx+""",T2> &Q) {
    typedef typename TypePromote<Divides,T1,T2>::T T;
    typedef Pol<nd,"""+nx+""",T> PdxT;
    Vec<T,PdxT::dim> a,res_vec;
    a.set(T(0));
    a[0]=T2(1)/Q.coefficients()[0];
    res_vec.set(T(0));
    res_vec[0]=P.coefficients()[0]/Q.coefficients()[0];"""
    if nx=='nx':
        print '    if (PdxT::init_mult)'
        print '        PdxT::initialize_mult();'
        print '    for (int i=1;i<PdxT::dim;i++) {'
        print '        for (int j=0;j<PdxT::mult[i].size()-1;j++)'
        print '            a[i]-=Q.coefficients()[PdxT::mult[i][j][0]]*a[PdxT::mult[i][j][1]];'
        print '        a[i]/=Q.coefficients()[0];'
        print '        for (int j=0;j<PdxT::mult[i].size();j++)'
        print '            res_vec[i]+=P.coefficients()[PdxT::mult[i][j][0]]*a[PdxT::mult[i][j][1]];'
    else :
        print '    for (int i=1;i<PdxT::dim;i++) {'
        print '        for (int j=0;j<i;j++)'
        print '            a[i]-=Q.coefficients()[i-j]*a[j];'
        print '        a[i]/=Q.coefficients()[0];'
        print '        for (int j=0;j<=i;j++)'
        print '            res_vec[i]+=P.coefficients()[j]*a[i-j];'
    print """   }
    return PdxT(res_vec);
}

template <int nd, """+temp+"""class T>
Pol<nd,"""+nx+""",T> sqrt (const Pol<nd,"""+nx+""",T> &P) {
    assert(0);
    /* TODO */
}

template <int nd, """+temp+"""class T>
std::istream &operator>>(std::istream &is, Pol<nd,"""+nx+""",T> &P) {
    Vec<T> coefs;
    is >> coefs;
    P=Pol<nd,"""+nx+""",T>(coefs);
    return is;
}

template <int nd, """+temp+"""class T>
std::istream &line_input(std::istream &is, Pol<nd,"""+nx+""",T> &P) {
    Vec<T> coefs;
    line_input ( is, coefs);
    P=Pol<nd,"""+nx+""",T>(coefs);
    return is;
}

template <int nd, """+temp+"""class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,"""+nx+""",T> &P) {"""
    if nx=='nx':
        print '    if (Pol<nd,nx,T>::init_puissances)'
        print '        Pol<nd,nx,T>::initialize_puissances();'
    print """    os << " " << P.coefficients()[0] << " ";
    for (unsigned i=1;i<Pol<nd,"""+nx+""",T>::dim;i++) {
        if (P.coefficients()[i]>T(0))
            os << "+" << P.coefficients()[i];
        if (P.coefficients()[i]<T(0))
            os << "-" << -P.coefficients()[i];
        if (P.coefficients()[i]!=T(0)) {"""
    if nx=='nx':
        print '            for (int j=0;j<nx;j++)'
        print '                if(Pol<nd,nx,T>::puissances[i][j]>0)'
        print '                    os << "*X" << j << "^" << Pol<nd,nx,T>::puissances[i][j];'
        print '            os << " ";'
    else :
        print '            os << "*X^" << i << " ";'
    print """            }
    }
    os << " ";
    return os;
}

template <int nd, """+temp+"""class T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,"""+nx+""",std::complex<T> > &P) {"""
    if nx=='nx':
        print '    if (Pol<nd,nx,T>::init_puissances)'
        print '        Pol<nd,nx,T>::initialize_puissances();'
    print """    os << " " << P.coefficients()[0] << " ";
    for (unsigned i=1;i<Pol<nd,"""+nx+""",T>::dim;i++) {
        if (P.coefficients()[i]!=std::complex<T>(0)) {
            os << "+" << P.coefficients()[i];"""
    if nx=='nx':
        print '            for (int j=0;j<nx;j++)'
        print '                if(Pol<nd,nx,T>::puissances[i][j]>0)'
        print '                    os << "*X" << j << "^" << Pol<nd,nx,T>::puissances[i][j];'
        print '            os << " ";'
    else :
        print '            os << "*X^" << i << " ";'
    print """        }
    }
    os << " ";
    return os;
}
"""

    if nx=='1':
        print """
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
"""

print """
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
    Vec<T,Pol<nd,nx,T>::dim> aux=P.coefficients();
    aux[0]+=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T> operator+(const T2 &t, const Pol<nd,nx,T1> &P) {
    typedef typename TypePromote<Plus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T,Pol<nd,nx,T>::dim> aux=P.coefficients();
    aux[0]+=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T> operator-(const Pol<nd,nx,T1> &P, const T2 &t) {
    typedef typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T,Pol<nd,nx,T>::dim> aux=P.coefficients();
    aux[0]-=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T> operator-(const T2 &t, const Pol<nd,nx,T1> &P) {
    typedef typename TypePromote<Minus,T1,typename IsScalar<T2>::T>::T T;
    Vec<T,Pol<nd,nx,T>::dim> aux=-P.coefficients();
    aux[0]+=t;
    return Pol<nd,nx,T>(aux);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T> operator*(const T2 &t, const Pol<nd,nx,T1> &P) {
    return Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(t*P.coefficients());
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T> operator*(const Pol<nd,nx,T1> &P, const T2 &t) {
    return Pol<nd,nx,typename TypePromote<Multiplies,T1,typename IsScalar<T2>::T>::T>(P.coefficients()*t);
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> operator/(const T2 &t, const Pol<nd,nx,T1> &P) {
    return Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T>(t) / P;
}

template <int nd, int nx, class T1, class T2>
Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> operator/(const Pol<nd,nx,T1> &P, const T2 &t) {
    return Pol<nd,nx,typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T> ( Vec<typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T,Pol<nd,nx,T1>::dim>(P.coefficients()) / typename TypePromote<Divides,T1,typename IsScalar<T2>::T>::T(t) );
}

template <int nd, int nx, class T>
Pol<nd,nx,T> pow(const Pol<nd,nx,T> &P, int a) {
    Pol<nd,nx,T> res = P;
    for (int i=1;i<a;i++)
        res = res * P;
    return res;
}

template <int nd, int nx, class T>
Pol<nd,nx,T> pow(const Pol<nd,nx,T> &P, const double &a) {
    assert(0);
    /*TODO*/
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
    return Pol<nd,nx,typename TypePromote<"""+t+""",T>::T>("""+f+"""(P.coefficients()));
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

}

#endif // POLYNOMIALS_H"""
