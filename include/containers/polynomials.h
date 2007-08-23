////////////////////////////////////
//  Author : Camille GOUTTEBROZE  //
//  gouttebroze@lmt.ens-cachan.fr //
////////////////////////////////////
#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include <vector>
#include <limits>
#include <complex>
#include "gnuplot.h"
#include "mat.h"
#include "algo.h"

// using namespace std;
namespace LMT {

// template <int nx>
// bool operator== (const Vec<int,nx> &v1, const Vec<int,nx> &v2) {
//     for (int i=0;i<nx;i++)
//         if (v1[i]!=v2[i])
//             return 0;
//     return 1;
// }


struct TriVecInt {
    template <int nx>
    static bool vec_inf(const Vec<int,nx> &v1, const Vec<int,nx> &v2) {
        for (int i=0;i<nx;i++) {
            if (v1[i]<v2[i])
                return 1;
            if (v1[i]>v2[i])
                return 0;
        }
        return 0;
    }
    template <int nx>
    static bool vec_inf_eq(const Vec<int,nx> &v1, const Vec<int,nx> &v2) {
        for (int i=0;i<nx;i++)
            if (v1[i]>v2[i])
                return 0;
        return 1;
    }
    template <int nx>
    bool operator() (const Vec<int,nx> &v1, const Vec<int,nx> &v2) const { return vec_inf( v1, v2 ); }
};

Vec<int> polynomial_next_power(const Vec<int> &v, int nd) {
    Vec<int> res=v;
    int tmp=res[0];
    for (unsigned i=1;i<res.size();i++)
        tmp+=res[i];
    if (tmp<nd) {
        res[res.size()-1]++;
    }
    else {
        Vec<int> r=range(unsigned(0),res.size()-1);
        res[r]=polynomial_next_power(res[r],nd);
        res[res.size()-1]=0;
    }
    return res;
}

//////////////////////////////////////////////////////////////////
// DEFINITION DE LA CLASSE POLYNOME ET DE SES FONCTIONS MEMBRES //
//////////////////////////////////////////////////////////////////

/**
  @author Gouttebroze
*/
template <int nd=1, int nx=1, typename T=double>
class Pol {
private:
    Vec<T> coefs;
    Vec<Vec<int,nx> > puissances;
public:
    Pol() {};
    Pol(const Vec<T> &V, const Vec<Vec<int,nx> > &W);                           ///Construit un polynome a partir de ses coeficients
    template <int nd2, typename T2> Pol(const Pol<nd2,nx,T2> &P2); /// Contructeur de copie conversion
    Pol(const T &t); ///Construit un polynome constant
    Pol(const T &t1, const T &t2, int p); ///Construit le polynome t1+t2*Xp
    const Vec<T> &Coefs() const {return coefs;}
    const Vec<Vec<int,nx> > &Powers() const {return puissances;}
    template <typename T2>
    typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,nx> &V) const; /// Renvoie la valeur du polynome V
    Pol<nd,nx,T> operator-() const {return Pol<nd,nx,T>(-coefs,puissances);}    ///Renvoie le polynome oppose;
    Vec<Pol<nd,nx,T>,nx> derivative() const;                            ///Renvoie les polynomes derives
    operator bool() const { return true; };
    //     bool operator==(const T &t) const ;              //Verifie si le polynome est egal a t
    //     template <typename T1> bool operator==(const T1 &d) const;  ///Regarde si le polynome est different de d
    //     template <typename T1> bool operator!=(const T1 &d) const;  ///Regarde si le polynome est different de d
    template <typename T2> void operator+=(const T2 &t);        ///Ajoute t au polynome
    template <typename T2> void operator-=(const T2 &t);        ///Retranche t au polynome
    template <int nd2, typename T2> void operator+=(const Pol<nd2,nx,T2> &Q);        ///Ajoute Q au polynome
    template <int nd2, typename T2> void operator-=(const Pol<nd2,nx,T2> &Q);        ///Retranche Q au polynome
    void operator*=(const T &t) {coefs*=t;};                    ///Divise le polynome par T
    void operator/=(const T &t) {coefs/=t;};                    ///Divise le polynome par T
};

template <int nd, int nx, typename T>
Pol<nd,nx,T>::Pol(const Vec<T> &V, const Vec<Vec<int,nx> > &W) { ///Construit un polynome a partir de ses coeficients
    coefs=V;
    puissances=W;
}

template <int nd, int nx, typename T>
template <int nd2, typename T2>
Pol<nd,nx,T>::Pol(const Pol<nd2,nx,T2> &P2) {
    coefs=P2.Coefs();
    puissances=P2.Powers();
    for (int i=puissances.size()-1;i>=0;i--) {
        int tmp=puissances[i][0];
        for (int j=1;j<nx;j++)
            tmp+=puissances[i][j];
        if (tmp>nd) {
            puissances.erase_elem_nb(i);
            coefs.erase_elem_nb(i);
        }
    }
}

template <int nd, int nx, typename T>
Pol<nd,nx,T>::Pol(const T &t) { 
    coefs.resize(1,t);
    Vec<int,nx> tmp;
    tmp.set(0);
    puissances.resize(1,tmp);
}

template <int nd, int nx, typename T>
Pol<nd,nx,T>::Pol(const T &t1, const T &t2, int p) {
    coefs=Vec<T>(t1,t2);
    Vec<int,nx> tmp;
    tmp.set(0);
    Vec<int,nx> tmp2=tmp;
    tmp2[p]=1;
    puissances=Vec<Vec<int> >(tmp,tmp2);
}

template <int nd, int nx, typename T>
template <typename T2>
typename TypePromote<Multiplies,T,T2>::T Pol<nd,nx,T>::operator() (const Vec<T2,nx> &V) const {
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    using namespace std;
    TR res = coefs[0];
    for(unsigned i=1;i<coefs.size();i++) {
        TR tmp = TR(coefs[i]);
        for (int j=0;j<nx;j++)
            tmp *= ::pow(TR(V[j]),puissances[i][j]);
        res += tmp;
    }
    return res;
}

template <int nd, int nx, typename T>
Vec<Pol<nd,nx,T>,nx> Pol<nd,nx,T>::derivative() const {
    ///Renvoie le polynome derivee
    Vec<Vec<T>,nx> coefsd;
    Vec<Vec<Vec<int,nx> >,nx> puissancesd;
    for (int i=0;i<puissances.size();i++)
        for (int j=0;j<nx;j++)
            if (puissances[i][j]>0) {
                puissancesd[j].push_back(puissances[i]);
                puissancesd[j][puissancesd[j].size()-1][j]--;
                coefsd[j].push_back(puissances[i][j]*coefs[i]);
            }
    Vec<Pol<nd,nx,T>,nx> res;
    for (int j=0;j<nx;j++) {
        if (coefsd[j].size()==0) {
            coefsd[j].resize(1,0.);
            puissancesd[j].resize(1);
            puissancesd[j][0].set(0);
        }
        res[j]=Pol<nd,nx,T>(coefsd[j],puissancesd[j]);
    }
    return res;
}

// template <int nd, typename T>
// bool Pol<nd,1,T>::operator== (const T &t) const {
//     return bool(coefs.size()==1 and coefs[0]==t);
// }
// 
// template <int nd, typename T>
// template <typename T1>
// bool Pol<nd,1,T>::operator== (const T1 &t) const {
//     Pol<nd,1,T> G(t);
//     bool b=coefs.size()==G.Coefs().size();
//     bool c=coefs==G.Coefs();
//     return b and c;
// }
// 
// // template <int nd, typename T>
// // bool Pol<nd,1,T>::operator!=(const T &t) {
// //     return bool(coefs.size()!=1 or coefs[0]!=t);
// // }
// 
// template <int nd, typename T>
// template <typename T1>
// bool Pol<nd,1,T>::operator!= (const T1 &t) const {
//     Pol<nd,1,T> G(t);
//     bool b=coefs.size()!=G.Coefs().size();
//     bool c=coefs!=G.Coefs();
//     return b or c;
// }

template <int nd, int nx, typename T>
template <typename T2>
void Pol<nd,nx,T>::operator+=(const T2 &t) {
    Pol<nd,nx,T> Q(t);
    *this = *this - Q;
}

template <int nd, int nx, typename T>
template <typename T2>
void Pol<nd,nx,T>::operator-=(const T2 &t) {
    Pol<nd,nx,T> Q(t);
    *this = *this + Q;
}

template <int nd, int nx, typename T>
template <int nd2, typename T2>
void Pol<nd,nx,T>::operator+=(const Pol<nd2,nx,T2> &Q) {
    *this = *this + Q;
}

template <int nd, int nx, typename T>
template <int nd2, typename T2>
void Pol<nd,nx,T>::operator-=(const Pol<nd2,nx,T2> &Q) {
    *this = *this - Q;
}

// /////////////////////////////////////////////////////////////////////
// // DEFINITION DES FONCTIONS GLOBALES EN RAPPORT AVEC DES POLYNOMES //
// /////////////////////////////////////////////////////////////////////
// 
// template <int nd1, typename T1, int nd2, typename T2>
// const bool operator==(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
//     bool res=0;
//     if (P.Coefs().size()==Q.Coefs().size())
//         if (P.Coefs()==Q.Coefs())
//             res=1;
//     return res;
// }
// 
// template <int nd1, typename T1, int nd2, typename T2>
// bool operator!=(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
//     bool res = 1;
//     if (P.Coefs().size()==Q.Coefs().size())
//         if (P.Coefs()==Q.Coefs())
//             res=0;
//     return res;
// }

template <int nx, int nd1, typename T1, int nd2, typename T2>
Pol<(nd1>nd2?nd1:nd2),nx,typename TypePromote<Plus,T1,T2>::T> operator+(const Pol<nd1,nx,T1> &P, const Pol<nd2,nx,T2> &Q) {
    Vec<typename TypePromote<Multiplies,T1,T2>::T> r;
    Vec<Vec<int,nx> > puis;
    r.resize(P.Coefs().size()+Q.Coefs().size());
    puis.resize(r.size());
    int rs=-1;
    if (P.Powers()[0]<Q.Powers()[0]) {
        int q=0;
        for (int i=0;i<P.Powers().size()-1;i++) {
            if (q<Q.Powers().size() and Q.Powers()[q]==P.Powers()[i]) {
                rs++;
                puis[rs]=Q.Powers()[q];
                r[rs]=P.Coefs()[i]+Q.Coefs()[q];
                q++;
            }
            else {
                rs++;
                puis[rs]=P.Powers()[i];
                r[rs]=P.Coefs()[i];
            }
            for (;q<Q.Powers().size() and Q.Powers()[q]<P.Powers()[i+1];) {
                rs++;
                puis[rs]=Q.Powers()[q];
                r[rs]=Q.Coefs()[q];
                q++;
            }
        }
        if (q<Q.Powers().size() and Q.Powers()[q]==P.Powers()[P.Powers().size()-1]) {
            rs++;
            puis[rs]=Q.Powers()[Q.Powers().size()-1];
            r[rs]=P.Coefs()[P.Powers().size()-1]+Q.Coefs()[q];
            q++;
        }
        else {
            rs++;
            puis[rs]=P.Powers()[P.Powers().size()-1];
            r[rs]=P.Coefs()[P.Powers().size()-1];
        }
        for (;q<Q.Powers().size();) {
            rs++;
            puis[rs]=Q.Powers()[q];
            r[rs]=Q.Coefs()[q];
            q++;
        }
    }
    else {
        int p=0;
        for (int i=0;i<Q.Powers().size()-1;i++) {
            if (p<P.Powers().size() and P.Powers()[p]==Q.Powers()[i]) {
                rs++;
                puis[rs]=P.Powers()[p];
                r[rs]=Q.Coefs()[i]+P.Coefs()[p];
                p++;
            }
            else {
                rs++;
                puis[rs]=Q.Powers()[i];
                r[rs]=Q.Coefs()[i];
            }
            for (;p<P.Powers().size() and P.Powers()[p]<Q.Powers()[i+1];) {
                rs++;
                puis[rs]=P.Powers()[p];
                r[rs]=P.Coefs()[p];
                p++;
            }
        }
        if (p<P.Powers().size() and P.Powers()[p]==Q.Powers()[Q.Powers().size()-1]) {
            rs++;
            puis[rs]=P.Powers()[p];
            r[rs]=Q.Coefs()[Q.Powers().size()-1]+P.Coefs()[p];
            p++;
        }
        else {
            rs++;
            puis[rs]=Q.Powers()[Q.Powers().size()-1];
            r[rs]=Q.Coefs()[Q.Powers().size()-1];
        }
        for (;p<P.Powers().size();) {
            rs++;
            puis[rs]=P.Powers()[p];
            r[rs]=P.Coefs()[p];
            p++;
        }
    }
    r.resize(rs+1);
    puis.resize(r.size());
    Pol<nd1+nd2,nx,typename TypePromote<Multiplies,T1,T2>::T> res(r,puis);
    return res;
}

template <int nx, int nd1, typename T1, typename T2>
Pol<nd1,nx,typename TypePromote<Plus,T1,T2>::T> operator+(const Pol<nd1,nx,T1> &P, T2 t) {
    Pol<nd1,nx,T2> Q(t);
    return P+Q;
}

template <int nx, int nd1, typename T1, typename T2>
Pol<nd1,nx,typename TypePromote<Plus,T1,T2>::T> operator+(T2 t, const Pol<nd1,nx,T1> &P) {
    Pol<nd1,nx,T2> Q(t);
    return Q+P;
}

template <int nx, int nd1, typename T1, int nd2, typename T2>
Pol<(nd1>nd2?nd1:nd2),nx,typename TypePromote<Plus,T1,T2>::T> operator-(const Pol<nd1,nx,T1> &P, const Pol<nd2,nx,T2> &Q) {
    Vec<typename TypePromote<Multiplies,T1,T2>::T> r;
    Vec<Vec<int,nx> > puis;
    r.resize(P.Coefs().size()+Q.Coefs().size());
    puis.resize(r.size());
    int rs=-1;
    if (P.Powers()[0]<Q.Powers()[0]) {
        int q=0;
        for (int i=0;i<P.Powers().size()-1;i++) {
            if (q<Q.Powers().size() and Q.Powers()[q]==P.Powers()[i]) {
                rs++;
                puis[rs]=Q.Powers()[q];
                r[rs]=P.Coefs()[i]-Q.Coefs()[q];
                q++;
            }
            else {
                rs++;
                puis[rs]=P.Powers()[i];
                r[rs]=P.Coefs()[i];
            }
            for (;q<Q.Powers().size() and Q.Powers()[q]<P.Powers()[i+1];) {
                rs++;
                puis[rs]=Q.Powers()[q];
                r[rs]=-Q.Coefs()[q];
                q++;
            }
        }
        if (q<Q.Powers().size() and Q.Powers()[q]==P.Powers()[P.Powers().size()-1]) {
            rs++;
            puis[rs]=Q.Powers()[Q.Powers().size()-1];
            r[rs]=P.Coefs()[P.Powers().size()-1]-Q.Coefs()[q];
            q++;
        }
        else {
            rs++;
            puis[rs]=P.Powers()[P.Powers().size()-1];
            r[rs]=P.Coefs()[P.Powers().size()-1];
        }
        for (;q<Q.Powers().size();) {
            rs++;
            puis[rs]=Q.Powers()[q];
            r[rs]=-Q.Coefs()[q];
            q++;
        }
    }
    else {
        int p=0;
        for (int i=0;i<Q.Powers().size()-1;i++) {
// PRINT(P);
// PRINT(p);
            if (p<P.Powers().size() and P.Powers()[p]==Q.Powers()[i]) {
                rs++;
                puis[rs]=P.Powers()[p];
                r[rs]=P.Coefs()[p]-Q.Coefs()[i];
                p++;
            }
            else {
                rs++;
                puis[rs]=Q.Powers()[i];
                r[rs]=-Q.Coefs()[i];
            }
            for (;p<P.Powers().size() and P.Powers()[p]<Q.Powers()[i+1];) {
                rs++;
                puis[rs]=P.Powers()[p];
                r[rs]=P.Coefs()[p];
                p++;
            }
        }
        if (p<P.Powers().size() and P.Powers()[p]==Q.Powers()[Q.Powers().size()-1]) {
            rs++;
            puis[rs]=P.Powers()[p];
            r[rs]=P.Coefs()[p]-Q.Coefs()[Q.Powers().size()-1];
            p++;
        }
        else {
            rs++;
            puis[rs]=Q.Powers()[Q.Powers().size()-1];
            r[rs]=-Q.Coefs()[Q.Powers().size()-1];
        }
        for (;p<P.Powers().size();) {
            rs++;
            puis[rs]=P.Powers()[p];
            r[rs]=P.Coefs()[p];
            p++;
        }
    }
    r.resize(rs+1);
    puis.resize(r.size());
    Pol<nd1+nd2,nx,typename TypePromote<Multiplies,T1,T2>::T> res(r,puis);
    return res;
}

template <int nx, int nd1, typename T1, typename T2>
Pol<nd1,nx,typename TypePromote<Plus,T1,T2>::T> operator-(const Pol<nd1,nx,T1> &P, T2 t) {
    Pol<nd1,nx,T2> Q(t);
    return P-Q;
}

template <int nx, int nd1, typename T1, typename T2>
Pol<nd1,nx,typename TypePromote<Plus,T1,T2>::T> operator-(T2 t, const Pol<nd1,nx,T1> &P) {
    Pol<nd1,nx,T2> Q(t);
    return Q-P;
}

template <int nx, int nd1, typename T1, int nd2, typename T2>
Pol<nd1+nd2,nx,typename TypePromote<Multiplies,T1,T2>::T> operator*(const Pol<nd1,nx,T1> &P, const Pol<nd2,nx,T2> &Q) {
    Vec<typename TypePromote<Multiplies,T1,T2>::T> r;
    Vec<Vec<int,nx> > puis;
    if (P.Powers().size()==1) {
        r=P.Coefs()[0]*Q.Coefs();
        puis.resize(r.size());
        for (int i=0;i<puis.size();i++)
            puis[i]=Q.Powers()[i]+P.Powers()[0];
        Pol<nd1+nd2,nx,typename TypePromote<Multiplies,T1,T2>::T> res(r,puis);
        return res;
    }
    else if (Q.Powers().size()==1) {
        r=Q.Coefs()[0]*P.Coefs();
        puis.resize(r.size());
        for (int i=0;i<puis.size();i++)
            puis[i]=P.Powers()[i]+Q.Powers()[0];
        Pol<nd1+nd2,nx,typename TypePromote<Multiplies,T1,T2>::T> res(r,puis);
        return res;
    }
    else {
        r.resize(P.Powers().size()*Q.Powers().size());
        puis.resize(r.size());
        Vec<Vec<Vec<int,nx> > > auxp;
        Vec<Vec<typename TypePromote<Multiplies,T1,T2>::T> > auxc;
        auxp.resize(P.Powers().size());
        auxc.resize(auxp.size());
        for (int s=0;s<auxp.size();s++) {
            auxp[s].resize(Q.Powers().size());
            auxc[s].resize(auxp[s].size());
            for (int i=0;i<auxp[s].size();i++) {
                auxp[s][i]=P.Powers()[s]+Q.Powers()[i];
                auxc[s][i]=P.Coefs()[s]*Q.Coefs()[i];
            }
        }
        puis[0]=auxp[0][0];
        r[0]=auxc[0][0];
        Vec<int> cour;
        cour.resize(P.Powers().size(),0);
        cour[0]=1;
        int rs=0;
        int smini=0;
        int smaxi=1;
        for (;smini<P.Powers().size();) {
            rs++;
            Vec<int,nx> min=auxp[smini][cour[smini]];
            Vec<int> stock(smini);
            for (int j=smini+1;j<=smaxi;j++) {
                if (auxp[j][cour[j]]<min) {
                    min=auxp[j][cour[j]];
                    stock=Vec<int>(j);
                }
                else if (auxp[j][cour[j]]==min)
                    stock.push_back(j);
            }
            puis[rs]=min;
            r[rs]=auxc[stock[0]][cour[stock[0]]];
            cour[stock[0]]++;
            for (int i=1;i<stock.size();i++) {
                r[rs]+=auxc[stock[i]][cour[stock[i]]];
                cour[stock[i]]++;
            }
            if (cour[smini]==Q.Powers().size())
                smini++;
            if (smaxi<P.Powers().size()-1 and cour[smaxi]>0)
                smaxi++;
        }
        r.resize(rs+1);
        puis.resize(rs+1);
        Pol<nd1+nd2,nx,typename TypePromote<Multiplies,T1,T2>::T> res(r,puis);
        return res;
    };
}

// template <int nd1, typename T1, typename T2>
// Pol<1,typename TypePromote<Multiplies,T1,T2>::T> operator*(const Pol<nd1,nx,T1> &P, T2 t) {
//     Pol<nd2,nx,T2> Q(t);
//     return P*Q;
// }

template <int nd1, int nx, typename T1, typename T2>
Pol<nd1,nx,typename TypePromote<Multiplies,T1,T2>::T> operator*(T2 t, const Pol<nd1,nx,T1> &P) {
    Pol<nd1,nx,T2> Q(t);
    return Q*P;
}

// template <int nd1, typename T1, int nd2, typename T2>
// Pol<nd1,nx,typename TypePromote<Multiplies,T1,T2>::T> operator*(T2 t, const Pol<nd1,nx,T1> &P) {
// PRINT(__LINE__);
//     Pol<nd1,nx,T2> Q(t);
//     return Q*P;
// }

template <int nx, int nd1, typename T1, int nd2, typename T2>
Pol<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Divides,T1,T2>::T> operator/(const Pol<nd1,nx,T1> &P, const Pol<nd2,nx,T2> &Q) {
    Vec<typename TypePromote<Divides,T1,T2>::T> a,b;
    Vec<Vec<int,nx> > puis;
    if (Q.Powers().size()==1) {
        a.resize(1,1/Q.Coefs()[0]);
        puis.resize(1);
        puis[0].set(0);
    }
    else {
        Vec<bool,nx> vb;
        vb.set(0);
        Vec<int> vn;
        for (int i=0;i<Q.Powers().size();i++)
            for (int j=0;j<nx;j++)
                if (Q.Powers()[i][j]>0)
                    vb[j]=1;
        for (int j=0;j<nx;j++)
            if (vb[j])
                vn.push_back(j);
        int ndplus=(nd1>nd2?nd2:nd1)+1;
        int atot=ndplus;
        for (int i=1;i<vn.size();i++)
            atot*=ndplus+i;
        for (int i=2;i<=vn.size();i++)
            atot/=i;
        a.resize(atot,0.);
        puis.resize(a.size());
        b.resize(a.size(),0.);
        a[0]=1/Q.Coefs()[0];
        puis[0].set(0);
        for (int k=1;k<a.size();k++) {
            for (int s=0;s<k;s++)
                if (puis[s]<=puis[k-1]) {
                    int t;
                    Vec<int,nx> comp=puis[k-1]-puis[s];
                    for (int u=0;u<k;u++)
                        if (puis[u]==comp) {
                            t=u;
                            break;
                        }
                    b[k-1]+=a[s]*a[t];
                }
            puis[k].set(0);
            puis[k][vn]=polynomial_next_power(puis[k-1][vn],ndplus-1);
            int p;
            for (int j=0;;j++)
                if (puis[k][j]>0) {
                    p=j;
                    break;
                }
            Vec<int,nx> nup=puis[k];
            nup[p]--;
            int limiteq=min(k+1,Q.Powers().size());
            for (int i=0;i<k;i++)
                if (puis[i]<=nup) {
                    int t=-1;
                    Vec<int,nx> comp=puis[k]-puis[i];
                    for (int u=0;u<limiteq;u++)
                        if (Q.Powers()[u]==comp) {
                            t=u;
                            break;
                        }
                    if (t>=0)
                        a[k]+=((puis[i][p]-puis[k][p])/T2(puis[k][p]))*Q.Coefs()[t]*b[i];
                }
        }
    }
    Pol<(nd1>nd2?nd2:nd1),nx,typename TypePromote<Divides,T1,T2>::T> A(a,puis);
    return P*A;
}

// template <int nd1, typename T1, int nd2, typename T2>
// Pol<nd1,1,typename TypePromote<Divides,T1,T2>::T> operator/(const Pol<nd1,1,T1> &P, T2 t) {
//     Pol<nd1,1,T2> Q(t);
//     return P/Q;
// }

template <int nd1, int nx, typename T1, typename T2>
Pol<nd1,nx,typename TypePromote<Divides,T1,T2>::T> operator/(T2 t, const Pol<nd1,nx,T1> &P) {
    Pol<nd1,nx,T2> Q(t);
    return Q/P;
}

template <int nd, int nx, typename T>
Pol<nd,nx,T> pow(const Pol<nd,nx,T> &P, int a) {
    assert( a > 0 );
    Pol<nd,nx,T> res=P;
    for (int i=1;i<a;i++)
        res=res*P;
    return res;
}

template <int nd, int nx, typename T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,nx,T> &P) {
    os << " " ;
    for (unsigned i=0;i<P.Coefs().size();i++) {
        if (P.Coefs()[i]>=0)
            os << "+" << P.Coefs()[i];
        if (P.Coefs()[i]<0)
            os << "-" << -P.Coefs()[i];
        for (int j=0;j<nx;j++)
            if(P.Powers()[i][j]>0)
                os << "*X" << j << "^" << P.Powers()[i][j];
        os << " ";
    }
    os << " ";
    return os;
}

///////////////////////////////////////////////////////////////////////////////
// DEFINITION DE LA CLASSE POLYNOME MONOVARIABLE ET DE SES FONCTIONS MEMBRES //
///////////////////////////////////////////////////////////////////////////////

template <int nd, typename T>
class Pol<nd,1,T> {
private:
    Vec<T> coefs;
public:
    Pol () {}
    Pol (const Vec<T> &V);                           ///Construit un polynome a partir de ses coeficients
    Pol (T a) { ///Construit un polynome constant
        coefs.resize(1,a);
    }
    Pol (T a,T b, int p);                            ///Construit un polynome du 1er degre
    Pol (T a,T b,T c);                               ///Construit un polynome du 2eme degre
    Pol (T a,T b,T c,T d);                           ///Construit un polynome du 3eme degre
    Pol (T a,T b,T c,T d,T e);                       ///Construit un polynome du 4eme degre
    Pol (T a,T b,T c,T d,T e,T f);                   ///Construit un polynome du 5eme degre
    Pol (T a,T b,T c,T d,T e,T f,T g);               ///Construit un polynome du 6eme degre
    Pol (T a,T b,T c,T d,T e,T f,T g,T h);           ///Construit un polynome du 7eme degre
    template <int nd2, typename T2> Pol(const Pol<nd2,1,T2> &P2);

    const Vec<T> &Coefs() const {
        return coefs;
    }

    int degree() const {
        return coefs.size()-1;
    }    ///Renvoie le degre du polynome
    template <class T2>
    typename TypePromote<Multiplies,T,T2>::T operator() (T2 x) const;  ///Renvoie la valeur du polynome en x
    template <typename T2>
    typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,1> &V) const; ///Renvoie le vecteur des valeurs du polynome en toutes les valeurs de V
    template <typename T2>
    Vec<typename TypePromote<Multiplies,T,T2>::T> operator() (const Vec<T2> &V) const; ///Renvoie le vecteur des valeurs du polynome en toutes les valeurs de V
    T coef_max() const;                                     ///Renvoie le plus grand coefficient en valeur absolue
    Pol<nd,1,T> operator-() const {
        return Pol<nd,1,T>(-coefs);
    }    ///Renvoie le polynome oppose;
    Pol<nd,1,T> derivative() const;                       ///Renvoie le polynome derivee
    Pol<nd,1,T> integral (T a) const;                     ///Renvoie le polynome integrale qui prend a comme valeur en 0
    int MaxPositivesRoots() const;                        ///Renvoie le nombre maximal de racines positives
    int MaxNegativesRoots() const;                        ///Renvoie le nombre maximal de racines negatives
    T RootsUpperBound() const;                            ///Renvoie un majorant des racines
    T RootsLowerBound() const;                            ///Renvoie un minorant des racines
    Pol<nd,1,T> remainder(const Pol<nd,1,T> &P) const;    ///Renvoie le reste de la division par un polynome
    T root_dichotomy (T a,T b) const;                     ///Cherche une racine par dichotomie entre a et b
    Vec<T> roots() const;                                 ///Renvoie les racines du polynome
    T Newton(T d) const;                                  ///Cherche une racine par l'algorithme de Newton en partant de d
    operator bool() const {return true;};
    bool constant() const {return coefs.size()==1;};
    bool operator==(const T &t) const ;                 //Verifie si le polynome est egal a t
    bool operator!=(const T &t) const ;                 //Verifie si le polynome est different de t
    template <typename T1> bool operator==(const T1 &d) const; ///Regarde si le polynome est different de d
    template <typename T1> bool operator!=(const T1 &d) const; ///Regarde si le polynome est different de d
    template <typename T2> void operator+=(const T2 &t);       //Ajoute t au polynome
    template <typename T2> void operator-=(const T2 &t);       ///Retranche t au polynome
    template <int nd2, typename T2> void operator+=(const Pol<nd2,1,T2> &Q);        //Ajoute Q au polynome
    template <int nd2, typename T2> void operator-=(const Pol<nd2,1,T2> &Q);        ///Retranche Q au polynome
    template <typename T2> void operator*=(const T2 &t);       //Multiplie le polynome par t
    void operator/=(const T &t) {coefs/=t;};                        //Divise le polynome par T
    //     void operator*(const Vec<int,1> &V);
    template <typename T2> T2 troncate(const T2 &c, const T2 &d, const T2 &r, const int &nmax);//Tronque le polynome autour de c pour avec un residu inferieur a r sur un intervalle de taille 2d
};

template <int nd, typename T>
Pol<nd,1,T>::Pol(const Vec<T> &V) {
    ///Construit un polynome a partir de ses coeficients
    //     if (V.size()<1) {
    //         std::cerr << "The vector with the coeficients of the polynom is empty (size=0)" << std::endl;
    //         assert(0);
    //     }
    coefs=V;
}

template <int nd, typename T>
Pol<nd,1,T>::Pol (T a,T b,int p=0) {
    ///Construit un polynome du 1er degre
    coefs.resize(max(2,nd));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
}

template <int nd, typename T>
Pol<nd,1,T>::Pol (T a,T b,T c) {
    ///Construit un polynome du 2eme degre
    coefs.resize(max(3,nd));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
}

template <int nd, typename T>
Pol<nd,1,T>::Pol (T a,T b,T c,T d) {
    ///Construit un polynome du 3eme degre
    coefs.resize(max(4,nd));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
    if(nd>2) coefs[3]=d;
}

template <int nd, typename T>
Pol<nd,1,T>::Pol (T a,T b,T c,T d,T e) {
    ///Construit un polynome du 4eme degre
    coefs.resize(max(5,nd));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
    if(nd>2) coefs[3]=d;
    if(nd>3) coefs[4]=e;
}

template <int nd, typename T>
Pol<nd,1,T>::Pol (T a,T b,T c,T d,T e,T f) {
    ///Construit un polynome du 4eme degre
    coefs.resize(max(6,nd));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
    if(nd>2) coefs[3]=d;
    if(nd>3) coefs[4]=e;
    if(nd>4) coefs[5]=f;
}

template <int nd, typename T>
Pol<nd,1,T>::Pol (T a,T b,T c,T d,T e,T f,T g) {
    ///Construit un polynome du 4eme degre
    coefs.resize(max(7,nd));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
    if(nd>2) coefs[3]=d;
    if(nd>3) coefs[4]=e;
    if(nd>4) coefs[5]=f;
    if(nd>5) coefs[6]=g;
}

template <int nd, typename T>
Pol<nd,1,T>::Pol (T a,T b,T c,T d,T e,T f,T g,T h) {
    ///Construit un polynome du 4eme degre
    coefs.resize(max(8,nd));
    coefs[0]=a;
    if(nd>0) coefs[1]=b;
    if(nd>1) coefs[2]=c;
    if(nd>2) coefs[3]=d;
    if(nd>3) coefs[4]=e;
    if(nd>4) coefs[5]=f;
    if(nd>5) coefs[6]=g;
    if(nd>6) coefs[7]=h;
}

template <int nd, typename T>
template <int nd2, typename T2>
Pol<nd,1,T>::Pol (const Pol<nd2,1,T2> &P2) {
    ///Construit un polynome du 4eme degre
    coefs=P2.Coefs();
    if (coefs.size()>nd+1)
        coefs.resize(nd+1);
}

template <int nd, typename T>
template <typename T2>
typename TypePromote<Multiplies,T,T2>::T Pol<nd,1,T>::operator() (T2 x) const { /// Renvoie la valeur du polynome en x
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    using namespace std;
    TR res = coefs[0];
    for(unsigned i=1;i<coefs.size();i++)
        res += TR(coefs[i]) * ::pow(TR(x),i);
    return res;
}

template <int nd, typename T>
template <typename T2>
typename TypePromote<Multiplies,T,T2>::T Pol<nd,1,T>::operator() (const Vec<T2,1> &x) const { /// Renvoie la valeur du polynome en x
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    using namespace std;
    TR res = coefs[0];
    for(unsigned i=1;i<coefs.size();i++)
        res += TR(coefs[i]) * ::pow(TR(x[0]),i);
    return res;
}

template <int nd, typename T>
template <typename T2>
Vec<typename TypePromote<Multiplies,T,T2>::T> Pol<nd,1,T>::operator() (const Vec<T2> &V) const { /// Renvoie le vecteur des valeurs du polynome en toutes les valeurs de V
    typedef typename TypePromote<Multiplies,T,T2>::T TR;
    Vec<TR> res;
    res.resize(V.size());
    for (unsigned i=0;i<V.size();i++)
        res[i]=operator()(V[i]);
    return res;
}

template <int nd, typename T>
T Pol<nd,1,T>::coef_max () const {
    T res=abs(coefs[0]);
    for (int i=1;i<=degree();i++)
        if (res<abs(coefs[i]))
            res=abs(coefs[i]);
    return res;
}

template <int nd, typename T>
Pol<nd,1,T> Pol<nd,1,T>::derivative() const {
    ///Renvoie le polynome derivee
    Vec<T> CoefsDerivee;
    if (degree()==0)
        CoefsDerivee.resize(1,0);
    if (degree()>0) {
        CoefsDerivee.resize(degree());
        for (unsigned i=0;i<CoefsDerivee.size();i++)
            CoefsDerivee[i]=coefs[i+1]*(i+1);
    };
    Pol<nd,1,T> res(CoefsDerivee);
    return res;
};

template <int nd, typename T>
Pol<nd,1,T> Pol<nd,1,T>::integral(T a) const {
    ///Renvoie le polynome integrale qui prend a comme valeur en 0
    Vec<T> Coefsintegrale;
    Coefsintegrale.resize(degree()+2);
    Coefsintegrale[0]=a;
    for (int i=1;i<Coefsintegrale.size();i++)
        Coefsintegrale[i]=coefs[i-1]/i;
    Pol<nd,1,T> res(Coefsintegrale);
    return res;
};

template <int nd, typename T>
int Pol<nd,1,T>::MaxPositivesRoots() const {
    ///Renvoie  le nombre maximal de racines positives
    int res=0;
    Vec<T> Coefs=coefs;
    for (unsigned i=1;i<Coefs.size();i++)
        if (Coefs[i]==0) {
            Coefs.erase_elem_nb(i);
            i--;
        }
    for (unsigned i=1;i<Coefs.size();i++)
        if (sgn(Coefs[i])!=sgn(Coefs[i-1]))
            res++;
    return res;
};

template <int nd, typename T>
int Pol<nd,1,T>::MaxNegativesRoots() const {
    ///Renvoie  le nombre maximal de racines negatives
    int res=0;
    Vec<T> Coefs=coefs;
    for (unsigned i=1;i<Coefs.size();i+=2)
        Coefs[i]=-Coefs[i];
    for (unsigned i=1;i<Coefs.size();i++)
        if (Coefs[i]==0) {
            Coefs.erase_elem_nb(i);
            i--;
        }
    for (unsigned i=1;i<Coefs.size();i++)
        if (sgn(Coefs[i])!=sgn(Coefs[i-1]))
            res++;
    return res;
};

template <int nd, typename T>
T Pol<nd,1,T>::RootsUpperBound() const {
    ///Renvoie un majorant des racines
    T res=0;
    T L=1+abs(coef_max());
    Pol<nd,1,T> P=*this;
    Vec<T> p=P.Coefs();
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
};

template <int nd, typename T>
T Pol<nd,1,T>::RootsLowerBound() const {
    ///Renvoie un minorant des racines
    T res=0;
    T L=-1-abs(coef_max());
    Pol<nd,1,T> P=*this;
    Vec<T> p=P.Coefs();
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
};

template <int nd, typename T>
T Pol<nd,1,T>::root_dichotomy (T a,T b) const {
    ///Cherche une racine par dichotomie entre a et b
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
};

template <int nd, typename T>
Pol<nd,1,T> Pol<nd,1,T>::remainder(const Pol<nd,1,T> &D) const {
    ///Renvoie le reste de la division du polynome par D
    Vec<T> r=coefs;
    if (D.degree()<=degree()) {
        Vec<T> d=D.Coefs();
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
};

template <int nd, typename T>
Vec<T> Pol<nd,1,T>::roots () const {
    ///Renvoie les racines du polynome
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
            Vec<Pol<nd,1,T> > Sturm(*this,derivative());
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
};

template <int nd, typename T>
T Pol<nd,1,T>::Newton (T d) const {
    ///Cherche une racine par l'algorithme de Newton en partant de d
    T a=d;
    T b=d-1;
    Pol<nd,1,T> Q=derivative();
    while (abs(a-b)/max(abs(a),abs(b))>100*std::numeric_limits<T>::epsilon()) {
        T aux=a;
        b=aux;
        a=b-operator()(b)/Q(b);
    };
    return a;
}

template <int nd, typename T>
bool Pol<nd,1,T>::operator== (const T &t) const {
    return bool(coefs.size()==1 and coefs[0]==t);
}

template <int nd, typename T>
bool Pol<nd,1,T>::operator!= (const T &t) const {
    return bool(coefs.size()!=1 or coefs[0]!=t);
}

template <int nd, typename T>
template <typename T1>
bool Pol<nd,1,T>::operator== (const T1 &t) const {
    Pol<nd,1,T> G(t);
    bool b=coefs.size()==G.Coefs().size();
    bool c=coefs==G.Coefs();
    return b and c;
}

template <int nd, typename T>
template <typename T1>
bool Pol<nd,1,T>::operator!= (const T1 &t) const {
    Pol<nd,1,T> G(t);
    bool b=coefs.size()!=G.Coefs().size();
    bool c=coefs!=G.Coefs();
    return b or c;
}

template <int nd, typename T>
template <typename T2>
void Pol<nd,1,T>::operator+=(const T2 &t) {
    Pol<nd,1,T> Q(t);
    Vec<T> q=Q.Coefs();
    int tmp=coefs.size();
    coefs.resize(max(q.size(),coefs.size()));
    for (int i=0;i<tmp;i++)
        coefs[i]+=q[i];
    for (int i=tmp;i<q.size();i++)
        coefs[i]=q[i];
    while(coefs.size()>1 and coefs[coefs.size()-1]==0)
        coefs.erase_elem_nb(coefs.size()-1);
}

template <int nd, typename T>
template <typename T2>
void Pol<nd,1,T>::operator-=(const T2 &t) {
    Pol<nd,1,T> Q(t);
    int tmp=coefs.size();
    coefs.resize(max(Q.Coefs().size(),coefs.size()));
    for (int i=0;i<tmp;i++)
        coefs[i]-=Q.Coefs()[i];
    for (int i=tmp;i<Q.Coefs().size();i++)
        coefs[i]=-Q.Coefs()[i];
    while(coefs.size()>1 and coefs[coefs.size()-1]==0)
        coefs.erase_elem_nb(coefs.size()-1);
}

template <int nd, typename T>
template <int nd2, typename T2>
void Pol<nd,1,T>::operator+=(const Pol<nd2,1,T2> &Q) {
// PRINT("nouveau-=");
// PRINT(coefs);
// PRINT(Q);
    int n1=min(Q.Coefs().size(),coefs.size());
    for (int i=0;i<n1;i++)
        coefs[i]+=Q.Coefs()[i];
    if (coefs.size()<Q.Coefs().size()) {
        coefs.resize(min(nd+1,Q.Coefs().size()));
        for (int i=n1;i<coefs.size();i++)
            coefs[i]=Q.Coefs()[i];
    }
    while(coefs.size()>1 and coefs[coefs.size()-1]==0)
        coefs.erase_elem_nb(coefs.size()-1);
// PRINT(coefs);
}

template <int nd, typename T>
template <int nd2, typename T2>
void Pol<nd,1,T>::operator-=(const Pol<nd2,1,T2> &Q) {
// PRINT("nouveau-=");
// PRINT(coefs);
// PRINT(Q);
    int n1=min(Q.Coefs().size(),coefs.size());
    for (int i=0;i<n1;i++)
        coefs[i]-=Q.Coefs()[i];
    if (coefs.size()<Q.Coefs().size()) {
        coefs.resize(min(nd+1,Q.Coefs().size()));
        for (int i=n1;i<coefs.size();i++)
            coefs[i]=-Q.Coefs()[i];
    }
    while(coefs.size()>1 and coefs[coefs.size()-1]==0)
        coefs.erase_elem_nb(coefs.size()-1);
// PRINT(coefs);
}

template <int nd, typename T>
template <typename T2>
T2 Pol<nd,1,T>::troncate(const T2 &c, const T2 &d, const T2 &r, const int &nmax) {  //Tronque le polynome autour de c pour avec un residu inferieur a r sur un intervalle de taille 2d
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
        coefs=P.Coefs();
    }
    return res;
}

template <int nd, typename T>
template <typename T2>
void Pol<nd,1,T>::operator*=(const T2 &t) {
    Vec<T> r;
    Pol<nd,1,T> Q(t);
    Vec<T> q=Q.Coefs();
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

template <int nd1, typename T1, int nd2, typename T2>
bool operator==(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    bool res=0;
    if (P.Coefs().size()==Q.Coefs().size())
        if (P.Coefs()==Q.Coefs())
            res=1;
    return res;
}

template <int nd1, typename T1, int nd2, typename T2>
bool operator!=(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    bool res = 1;
    if (P.Coefs().size()==Q.Coefs().size())
        if (P.Coefs()==Q.Coefs())
            res=0;
    return res;
}

template <int nd1, typename T1, int nd2, typename T2>
Pol<(nd1>nd2?nd1:nd2),1,typename TypePromote<Plus,T1,T2>::T> operator+(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    Vec<T1> p=P.Coefs();
    Vec<T2> q=Q.Coefs();
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
    Pol<(nd1>nd2?nd1:nd2),1,typename TypePromote<Plus,T1,T2>::T> res(r);
    return res;
}

template <int nd1, typename T1, typename T2>
Pol<nd1,1,typename TypePromote<Plus,T1,T2>::T> operator+(const Pol<nd1,1,T1> &P, T2 t) {
    return P + Pol<nd1,1,typename TypePromote<Plus,T1,T2>::T>(t);
}

template <int nd1, typename T1, typename T2>
Pol<nd1,1,typename TypePromote<Plus,T1,T2>::T> operator+(T2 t, const Pol<nd1,1,T1> &P) {
    return Pol<nd1,1,typename TypePromote<Plus,T1,T2>::T>(t) + P;
}

template <int nd1, typename T1, int nd2, typename T2>
Pol<(nd1>nd2?nd1:nd2),1,typename TypePromote<Minus,T1,T2>::T> operator-(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
// PRINT("nouveau-");
// PRINT(P.Coefs());
// PRINT(Q.Coefs());
    const Vec<T1> &p = P.Coefs();
    const Vec<T2> &q = Q.Coefs();
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
    Pol<(nd1>nd2?nd1:nd2),1,typename TypePromote<Minus,T1,T2>::T> res(r);
    // PRINT(res.Coefs());
    return res;
}

template <int nd1, typename T1, typename T2>
Pol<nd1,1,typename TypePromote<Minus,T1,T2>::T> operator-(const Pol<nd1,1,T1> &P, T2 t) {
    return P - Pol<nd1,1,typename TypePromote<Minus,T1,T2>::T>(t);
}

template <int nd1, typename T1, typename T2>
Pol<nd1,1,typename TypePromote<Minus,T1,T2>::T> operator-(T2 t, const Pol<nd1,1,T1> &P) {
    return Pol<nd1,1,typename TypePromote<Minus,T1,T2>::T>(t) - P;
}

template <int nd1, typename T1, int nd2, typename T2>
Pol<nd1+nd2,1,typename TypePromote<Multiplies,T1,T2>::T> operator*(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    if (P==T1(0))
        return P;
    else if (Q==T2(0))
        return Q;
    else {
        // PRINT("nouveau*");
        // PRINT(P.Coefs());
        // PRINT(Q.Coefs());
        Vec<typename TypePromote<Multiplies,T1,T2>::T> r;
        const Vec<T1> &p = P.Coefs();
        const Vec<T2> &q = Q.Coefs();
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
        return Pol<nd1+nd2,1,typename TypePromote<Multiplies,T1,T2>::T>( r );
    };
}

// template <int nd1, typename T1, typename T2>
// Pol<1,typename TypePromote<Multiplies,T1,T2>::T> operator*(const Pol<nd1,1,T1> &P, T2 t) {
//     Pol<nd2,1,T2> Q(t);
//     return P*Q;
// }

template <int nd1, typename T1, typename T2>
Pol<nd1,1,typename TypePromote<Multiplies,T1,T2>::T> operator*(T2 t, const Pol<nd1,1,T1> &P) {
    return Pol<nd1,1,typename TypePromote<Multiplies,T1,T2>::T>(t) * P;
}

// template <int nd1, typename T1, int nd2, typename T2>
// Pol<nd1,1,typename TypePromote<Multiplies,T1,T2>::T> operator*(T2 t, const Pol<nd1,1,T1> &P) {
// PRINT(__LINE__);
//     Pol<nd1,1,T2> Q(t);
//     return Q*P;
// }

template <int nd1, typename T1, int nd2, typename T2>
Pol<(nd1>nd2?nd2:nd1),1,typename TypePromote<Divides,T1,T2>::T> operator/(const Pol<nd1,1,T1> &P, const Pol<nd2,1,T2> &Q) {
    if (P==T1(0))
        return P;
    else {
// PRINT("nouveau/");
// PRINT(P.Coefs());
// PRINT(Q.Coefs());
        Vec<typename TypePromote<Divides,T1,T2>::T> r,a,b;
        r.resize((nd1>nd2?nd2:nd1)+1,0.);
        a.resize((nd1>nd2?nd2:nd1)+1,0.);
        b.resize((nd1>nd2?nd2:nd1),0.);
        Vec<T1> p=P.Coefs();
        Vec<T2> q=Q.Coefs();

        a[0]=1/q[0];
// PRINT(a[0]);
        for (int k=1;k<a.size();k++) {
            for (int s=0;s<k;s++) {
// PRINT(s);
// PRINT(k-1-s);
                b[k-1]+=a[s]*a[k-1-s];
// assert(0);
        }
// assert(0);
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

// template <int nd1, typename T1, int nd2, typename T2>
// Pol<nd1,1,typename TypePromote<Divides,T1,T2>::T> operator/(const Pol<nd1,1,T1> &P, T2 t) {
//     Pol<nd1,1,T2> Q(t);
//     return P/Q;
// }

template <int nd1, typename T1, typename T2>
Pol<nd1,1,typename TypePromote<Divides,T1,T2>::T> operator/( T2 t, const Pol<nd1,1,T1> &P ) {
    return Pol<nd1,1,typename TypePromote<Divides,T1,T2>::T>( t ) / P;
}

template <int nd, typename T>
Pol<nd,1,T> pow(const Pol<nd,1,T> &P, int a) {
    Pol<nd,1,T> res = P;
    for (int i=1;i<a;i++)
        res = res * P;
    return res;
}

template <int nd, typename T>
void plot (const Pol<nd,1,T> &P, std::string s="w l") {
    T A = P.RootsLowerBound();
    T B = P.RootsUpperBound();
    Vec<T> V = range(A,(B-A)/500,B);
    GnuPlot gp;
    gp.plot(V,P(V),s.c_str());
    gp.wait();
}

template <int nd, typename T>
void plot (const Pol<nd,1,T> &P, const Vec<T> &V, const std::string &s="w l") {
    //Affiche la fonction
    GnuPlot gp;
    gp.plot(V,P(V),s.c_str());
    gp.wait();
}

template <int nd, typename T>
void plot (const Pol<nd,1,T> &P, const Pol<nd,1,T> &Q, const Vec<T> &V, const std::string &s="w l") {
    //Affiche la fonction
    GnuPlot gp;
    gp.plot(V,P(V),Q(V),s.c_str());
    gp.wait();
}

template <int nd, typename T>
std::ostream &operator<<(std::ostream &os, const Pol<nd,1,T> &P) {
    os << " " << P.Coefs()[0] << " ";
    for (unsigned j=1;j<P.Coefs().size();j++) {
        if (P.Coefs()[j]>=0)
            os << "+" << P.Coefs()[j] << "*X^" << j << " ";
        if (P.Coefs()[j]<0)
            os << "-" << -P.Coefs()[j] << "*X^" << j << " ";
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
    template<class TV> struct DeepVariant { typedef Pol<m,n,typename TypeInformation<TT>::template DeepVariant<TV>::T> T; };
    static std::string type() { return "Pol<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};

template<int m, int n,class TT> struct HasTypeInformation<Pol<m,n,TT> > { static const bool res = true; };

}

#endif // POLYNOMIALS_H
