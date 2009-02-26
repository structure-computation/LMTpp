#ifndef pol_every_degree_HEADER
#define pol_every_degree_HEADER

#include "pol_dimension.h"
#include "pol_tables.h"

namespace LMT {

template <int nd=4,int nx=1,class T=double>
class PolEveryDegree {

public:
    static const int degree=nd;
    static const int variables_number=nx;
    static const int dim=DimPol<nd,nx>::valeur;

protected:
    Vec<T,dim> coefs;

public:

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
        if (PolPowers<nd,nx>::init_puissances)
            PolPowers<nd,nx>::initialize_puissances();
        for (int i=0;i<dim;i++)
            if (PolPowers<nd,nx>::puissances[i][q]==1) {
                coefs[i]=b;
                break;
            }
    }

    template <class T2>
    PolEveryDegree(const PolEveryDegree<nd,nx,T2> &P) { ///Construit le polynome egal a P
        coefs=P.coefficients();
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
        if (PolPowers<nd,nx>::init_puissances)
            PolPowers<nd,nx>::initialize_puissances();
        return PolPowers<nd,nx>::puissances;
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

}

#endif // pol_every_degree_HEADER
