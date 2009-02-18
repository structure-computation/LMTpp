#ifndef pol_every_degree_HEADER
#define pol_every_degree_HEADER

#include "pol_dimension.h"

namespace LMT {

template <int nd=4,int nx=1,class T=double>
class PolEveryDegree {

public:
    static const int degree=nd;
    static const int variables_number=nx;
    static const int dim=DimPol<nd,nx>::valeur;

protected:
    Vec<T,dim> coefs;

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

public:
    static bool init_puissances;
    static Vec<Vec<unsigned,nx>,PolEveryDegree<nd,nx,T>::dim> puissances;

    static void initialize_puissances() {
        init_puissances=0;
        puissances[0].set(0);
        for (int i=1;i<dim;i++)
        puissances[i]=next_power(puissances[i-1]);
    }

    PolEveryDegree () {}

    template <class T2, int nd2>
    PolEveryDegree(const Vec<T2,nd2> &V) { ///Construit le polynome a partir de ses coefficients
        for(unsigned i=0; i<min(V.size(),dim); ++i)
            coefs[i] = T(V[i]);
        for(unsigned i=V.size(); i<dim; ++i)
            coefs[i] = T(0);
    }

    PolEveryDegree(const T &a0) { ///Construit le polynome constant egal a a
        coefs.set(T(0));
        coefs[0]=a0;
    }

    PolEveryDegree(const T &a, const T &b, unsigned q) { ///Construit le polynome a + b*Xq;
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

    template <class T2>
    PolEveryDegree<nd,nx,T> &operator= (const PolEveryDegree<nd,nx,T2> &P) { ///Renvoie un polynome egal a P
        coefs=P.coefficients();
        return *this;
    }

    const Vec<T,dim> &coefficients() const { ///Renvoie les coefficients du polynome
        return coefs;
    }

    const Vec<Vec<unsigned,nx>,dim> &powers() { ///Renvoie les puissances du polynome
        if (init_puissances)
            initialize_puissances();
        return puissances;
    }

    operator bool() const {return true;}

    template <class T2>
    bool operator== (const PolEveryDegree<nd,nx,T2> &P) const { ///Verifie si le polynome est egal a P
        return coefs==P.coefficients();
    }

    template <class T2>
    bool operator!= (const PolEveryDegree<nd,nx,T2> &P) const { ///Verifie si le polynome est different de P
        return !(coefs==P.coefficients());
    }

    template <class T2>
    void operator+= (const PolEveryDegree<nd,nx,T2> &P) {
        coefs+=P.coefficients();
    }
    
    template <class T2>
    void operator-= (const PolEveryDegree<nd,nx,T2> &P) {
        coefs-=P.coefficients();
    }
    
};


template <int nd, int nx, class T>
bool PolEveryDegree<nd,nx,T>::init_puissances=1;

template <int nd, int nx, class T>
Vec<Vec<unsigned,nx>,PolEveryDegree<nd,nx,T>::dim> PolEveryDegree<nd,nx,T>::puissances;

}

#endif // pol_every_degree_HEADER
