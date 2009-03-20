// file generated from polynomials.h.py. Do not modify

#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include <containers/vec.h>
#include <containers/algo.h>

#include "pol_dimension.h"
#include "pol_tables.h"
#include "vec_if_static_size_is_one_and_scalar_if_not.h"

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

template <int nd=4,int nx=1,class T=double>
class Pol {

public:

    static const int degree=nd;
    static const int variables_number=nx;
    static const int dim=DimPol<nd,nx>::valeur;
      
    Pol () {}

    Pol(const T &a) {
        coefs.set(T(0));
        coefs[0]=a;
    }

    Pol(const T &a, const T &b, unsigned q) {
        coefs.set(T(0));
        coefs[0]=a;
        if (PolPowers<nd,nx>::init_puissances)
            PolPowers<nd,nx>::initialize_puissances();
        for (int i=0;i<dim;i++)
            if (PolPowers<nd,nx>::puissances[i][q]==1) {
                coefs[i]=b;
                break;
            }
    }

    template <class T2, int nd2>
    Pol(const Vec<T2,nd2> &V) {
        for(unsigned i=0; i<min(V.size(),dim); ++i)
            coefs[i] = T(V[i]);
        for(unsigned i=V.size(); i<dim; ++i)
            coefs[i] = T(0);
    }

    template <class T2>
    Pol (const Pol<nd,nx,T2> &P) {
        coefs=P.coefficients();
    }

    template <int nd2, class T2>
    Pol (const Pol<nd2,nx,T2> &P) {
        if (PolTroncates<(nd<nd2?nd2:nd),(nd>nd2?nd2:nd),nx>::init_troncates)
            PolTroncates<(nd<nd2?nd2:nd),(nd>nd2?nd2:nd),nx>::initialize_tronc();
        PolTroncates<(nd<nd2?nd2:nd),(nd>nd2?nd2:nd),nx>::troncates(coefs,P.coefficients());
    }

    template <int nx2, class T2>
    Pol (const Pol<nd,nx2,T2> &P, const Vec<unsigned,nx2> &v_ind) {
        int rest=0;
        for (int i=0;i<nx2;i++) {
            int tmp=1;
            for (int j=0;j<v_ind[i];j++)
                tmp*=2;
            rest+=tmp;
        }
        if (PolRestriction<nd,nx,nx2>::init_restriction[rest])
            PolRestriction<nd,nx,nx2>::initialize_restriction(v_ind);
        coefs.set(T(0));
        for (int i=0;i<DimPol<nd,nx2>::valeur;i++)
            coefs[PolRestriction<nd,nx,nx2>::restriction[rest][i]]=P.coefficients()[i];
    }

    template <int nx2, class T2>
    Pol (const Pol<nd,nx2,T2> &P, const Vec<unsigned,nx> &v_ind) {
        int rest=0;
        for (int i=0;i<nx;i++) {
            int tmp=1;
            for (int j=0;j<v_ind[i];j++)
                tmp*=2;
            rest+=tmp;
        }
        if (PolRestriction<nd,nx2,nx>::init_restriction[rest])
            PolRestriction<nd,nx2,nx>::initialize_restriction(v_ind);
        for (int i=0;i<dim;i++)
            coefs[i]=P.coefficients()[PolRestriction<nd,nx2,nx>::restriction[rest][i]];
    }

    template <class T2>
    Pol<nd,nx,T> &operator= (const Pol<nd,nx,T2> &P) {
        coefs=P.coefficients();
        return *this;
    }

    operator bool() const {return true;}

    template <class T2>
    bool operator== (const Pol<nd,nx,T2> &P) const { return coefs==P.coefficients(); }

    template <class T2>
    bool operator!= (const Pol<nd,nx,T2> &P) const { return !(coefs==P.coefficients()); }


    Pol<nd,nx,T> operator-() const { return Pol<nd,nx,T>(-coefs); }

    template <class T2>
    void operator+= (const Pol<nd,nx,T2> &P) { coefs+=P.coefficients(); }

    template <class T2>
    void operator-= (const Pol<nd,nx,T2> &P) { coefs-=P.coefficients(); }

    template <class T2>
    void operator*= (const Pol<nd,nx,T2> &P) {
        Vec<T,dim> old_coefs=coefs;
        coefs.set(T(0));
        if (PolMultiplies<nd,nx>::init_mult)
            PolMultiplies<nd,nx>::initialize_mult();
        for (int i=0;i<dim;i++)
            PolMultiplies<nd,nx>::multiplies(coefs,i,old_coefs,P.coefficients());
    }    

    template <class T2>
    void operator/= (const Pol<nd,nx,T2> &P) {
        Vec<T,dim> a,old_coefs;
        old_coefs=coefs;
        a.set(T(0));
        a[0]=T2(1)/P.coefficients()[0];
        coefs.set(T(0));
        coefs[0]=old_coefs[0]/P.coefficients()[0];
        if (PolMultiplies<nd,nx>::init_mult)
            PolMultiplies<nd,nx>::initialize_mult();
        for (int i=1;i<dim;i++) {
            PolMultiplies<nd,nx>::multiplies(a,i,-P.coefficients(),a,1);
            a[i]/=P.coefficients()[0];
            PolMultiplies<nd,nx>::multiplies(coefs,i,old_coefs,a);
        }
    }

    template <class T2>
    typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,nx> &x) const {
        if (PolPowers<nd,nx>::init_puissances)
            PolPowers<nd,nx>::initialize_puissances();
        typename TypePromote<Multiplies,T,T2>::T res;
        PolPowers<nd,nx>::evaluates(res,coefs,x);
        return res;
    }

    typedef Pol<(nd>0?nd-1:nd),nx,T> Derivative;

    typename VecIfStaticSizeIsOneAndScalarIfNot<Derivative,nx>::T   derivative() const {
        if (PolDerivative<nd,nx>::init_deriv)
            PolDerivative<nd,nx>::initialize_deriv();
        typename VecIfStaticSizeIsOneAndScalarIfNot<Vec<T,DimPol<(nd>0?nd-1:nd),nx>::valeur>,nx>::T derivee;
        PolDerivative<nd,nx>::derivates(derivee,coefs);
        return typename VecIfStaticSizeIsOneAndScalarIfNot<Derivative,nx>::T(derivee);
    }

    const Vec<T,DimPol<nd,nx>::valeur> &coefficients() const { return coefs; };

    const Vec<Vec<unsigned,nx>,dim> &powers() {
        if (PolPowers<nd,nx>::init_puissances)
            PolPowers<nd,nx>::initialize_puissances();
        return PolPowers<nd,nx>::puissances;
    }

    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const T2 &x) const {
        assert(nx==1);
        typename TypePromote<Multiplies,T,T2>::T res = coefs[0];
        for (unsigned i=1;i<dim;i++)
            res += coefs[i] * ::pow(x,i);
        return res;
    }

    Pol<nd+1,nx,T> integral (const T &a) const {
        assert(nx==1);
        Vec<T,DimPol<nd+1,nx>::valeur> coefficientsintegrale;
        coefficientsintegrale[0]=a;
        for (int i=1;i<DimPol<nd+1,nx>::valeur;i++)
            coefficientsintegrale[i]=coefs[i-1]/i;
        return Pol<nd+1,nx,T> (coefficientsintegrale);
    }

    int MaxPositivesRoots() const {
        assert(nx==1);
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

    int MaxNegativesRoots() const {
        assert(nx==1);
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

    T RootsUpperBound() const {
        assert(nx==1);
        typename TypePromote<Abs,T>::T titi=abs(coefs[dim-1]);
        for (int i=dim-2; i>0 && titi==T(0); i--)
            if (abs(coefs[i]))
                titi==coefs[i];
        Vec<T,dim> tutu=coefs/titi;
        typename TypePromote<Abs,T>::T toto=norm_inf(tutu);
        return typename TypePromote<Abs,T>::T(1)+toto;
    }

    T RootsLowerBound() const {
        assert(nx==1);
        typename TypePromote<Abs,T>::T titi=abs(coefs[dim-1]);
        for (int i=dim-2; i>0 && titi==T(0); i--)
            if (abs(coefs[i]))
                titi==coefs[i];
        Vec<T,dim> tutu=coefs/titi;
        typename TypePromote<Abs,T>::T toto=norm_inf(tutu);
        return typename TypePromote<Abs,T>::T(-1)-toto;
    }

    Pol<nd,nx,T> remainder(const Pol<nd,nx,T> &D) const {
        assert(nx==1);
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
        return Pol<nd,nx,T>(r);
    }

    T dichotomy (const T &a, const T &b) const {
        assert(nx==1);
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

    T newton(const T &d, bool c, int imax = 100) const{
        assert(nx==1);
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
            c=1;
        return a;
    }

    T householder(const T &d, bool c, int imax = 100) const {
        assert(nx==1);
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
            c=1;
        return a;
    }

    Vec<T> roots() const{
        assert(nx==1);
        Vec<T> res;
        int taille=dim;
        for (int i=dim-1;coefs[i]==T(0);i--)
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
                Vec<Pol<nd,nx,T> > Sturm(*this,derivative());
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
                Vec<T> r=Pol<nd,nx,T>(aux).roots();
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

private :

    Vec<T,DimPol<nd,nx>::valeur> coefs;

};

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

#endif // POLYNOMIALS_H
