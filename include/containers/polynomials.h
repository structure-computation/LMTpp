#ifndef POLYNOMIALS_H
#define POLYNOMIALS_H

#include <complex>
#include<iomanip>
#include <string.h> /// memset
using namespace std;


#include "vec.h"
#include "algo.h"



#include "pol_dimension.h"
#include "pol_tables.h"
#include "pol_unop.h"
#include "pol_binop.h"
#include "vec_if_static_size_is_one_and_scalar_if_not.h"

extern "C" {
    int dgeev_(char *jobvl, char *jobvr, int *n, double *a, int *lda, double *wr, double *wi, double *vl, int *ldvl, double *vr, int *ldvr, double *work, int *lwork, int *info);
}
                 
                 
namespace LMT {

template<class T>
bool is_real( const complex<T> z, T tolerance = 16*std::numeric_limits<T>::epsilon()) {
    if (std::abs(z.imag()) < tolerance)
        return true;
    else
        return false;       
}
             
/*!
    provisoire.
    retourne les racines de l'éqation x^2+a_1 x + a_2 = 0 où a1 et a2 sont des nombres complexes.
*/
template <class T>
Vec<complex<T> > root_of_second_degree_equation(complex<T> a1, complex<T> a2) {
    typedef complex<T> C;
    Vec<C> res;
    C delta,n1,n2;

    delta = a1*a1-complex<T>(4,0)*a2;
    if (std::abs(delta) < 16*std::numeric_limits<T>::epsilon()) {
        res.push_back(-0.5*a1);
        return res;
    }
    delta = sqrt(delta);
    n1 = a1-delta;
    n2 = a1+delta;
    /// objectif du if suivant est de gérer le cas ou delta et proche de a1 ou -a1.
    if (abs(n1)<abs(n2)) {
        res.push_back(C(-2)*a2/n2);
        res.push_back(-0.5*n2);
    } else {
        res.push_back(C(-2)*a2/n1);
        res.push_back(-0.5*n1);        
    }
    return res;
}

/*!
    provisoire.
    retourne les racines de l'éqation x^2+a_1 x + a_2 = 0 où a1 et a2 sont des nombres complexes.
 */
template <class T>
Vec<complex<T> > root_of_second_degree_equation( T a1, T a2) {
    typedef complex<T> C;
    T delta;
    Vec<C> res;
    C n1,n2;

    delta = a1*a1-4*a2;
    if (std::abs(delta) < 16*std::numeric_limits<T>::epsilon()) {
        res.push_back(-0.5*a1);
        return res;
    }
    if (delta > 0 ) {
        delta = sqrt(delta);
        n1 = a1-delta;
        n2 = a1+delta;
    } else {
        C te(0, sqrt(-delta));
        n1 = a1-te;
        n2 = a1+te;        
    }
    /// objectif du if suivant est de gérer le cas ou delta et proche de a1 ou -a1.
    if (abs(n1)<abs(n2)) {
        res.push_back(C(-2*a2)/n2);
        res.push_back(-0.5*n2);
    } else {
        res.push_back(C(-2*a2)/n1);
        res.push_back(-0.5*n1);        
    }
    return res;
}

/// code extrait de numerical recipes (un peu modifié)
template <class T>
complex<T> laguerre( const Vec< complex<T> >& a, int m, complex<T> x0, bool& rootFound, int maxIter = 100) {
    typedef complex<T> C;
    int iter,j;
    T abx,abp,abm,err;
    C dx,x1,b,d,f,g,h,sq,gp,gm,g2;
    static T frac[9] = {0.0,0.5,0.25,0.75,0.13,0.38,0.62,0.88,1.0};
    static T EPSS = 1.0e-7;

    rootFound = false;
    for (iter=1;iter<=maxIter;iter++) {
        b=a[m];
        err=abs(b);
        d = f = C(0,0);
        abx=abs(x0);
        for (j=m-1;j>=0;j--) {
            f = x0*f+d;
            d = x0*d+b;
            b = x0*b+a[j];
            err=abs(b)+abx*err;
        }
        err *= EPSS;
        if (abs(b) <= err) { rootFound = true; return x0; }
        g  = d/b;
        g2 =g*g;
        h = g2-C(2,0)*f/b;
        sq = sqrt(C(m-1,0)*(C(m,0)*h-g2));
        gp = g+sq;
        gm = g-sq;
        abp = abs(gp);
        abm = abs(gm);
        if (abp < abm) 
            gp=gm;
        //if (max(abp,abm) > (T)0)
        if (max(abp,abm) > (T)0)
            dx = C(m,0)/gp;
        else
            dx = C(exp(log(1+abx)),0) * C(cos(iter),sin(iter));
        x1 = x0-dx;
        if (x0 == x1) { rootFound = true; return x1; }
        //cout << " x1 = " << x1 << endl;
        if (iter % 10)
            x0 = x1;
        else 
            x0 = x0 - C(frac[iter%9],0)*dx;//*x=Csub(*x,RCmul(frac[iter/MT],dx));
    }
    std::cerr << "too many iterations in laguerre" << endl;
}

template <class T, int s>
complex<T> laguerre( const Vec<T,s>& a, int m, complex<T>& x0, bool& rootFound, int maxIter = 100) {
    typedef complex<T> C;
    int iter,j;
    T abx,abp,abm,err;
    C dx,x1,b,d,f,g,h,sq,gp,gm,g2;
    static T frac[9] = {0.0,0.5,0.25,0.75,0.13,0.38,0.62,0.88,1.0};
    static T EPSS = 1.0e-7;

    rootFound = false;
    for (iter=1;iter<=maxIter;iter++) {
        b=a[m];
        err=abs(b);
        d = f = C(0,0);
        abx=abs(x0);
        for (j=m-1;j>=0;j--) {
            f = x0*f+d;
            d = x0*d+b;
            b = x0*b+a[j];
            err=abs(b)+abx*err;
        }
        err *= EPSS;
        if (abs(b) <= err) { rootFound = true; return x0; }
        g  = d/b;
        g2 =g*g;
        h = g2-C(2,0)*f/b;
        sq = sqrt(C(m-1,0)*(C(m,0)*h-g2));
        gp = g+sq;
        gm = g-sq;
        abp = abs(gp);
        abm = abs(gm);
        if (abp < abm) 
            gp=gm;
        //if (max(abp,abm) > (T)0)
        if (max(abp,abm) > (T)0)
            dx = C(m,0)/gp;
        else
            dx = C(exp(log(1+abx)),0) * C(cos(iter),sin(iter));
        x1 = x0-dx;
        if (x0 == x1) { rootFound = true; return x1; }
        //cout << " x1 = " << x1 << endl;
        if (iter % 10)
            x0 = x1;
        else 
            x0 = x0 - C(frac[iter%9],0)*dx;//*x=Csub(*x,RCmul(frac[iter/MT],dx));
    }
    std::cerr << "too many iterations in laguerre" << endl;
}

/*!
    résout le polynôme a_0 + a_1 X + a_2 X^2 + ... + a_m X^m grâce à sa matrice compagnon.
    m est donc le degré.
    Si tout ce passe bien, la fonction renvoie zéro avec les racines dans root sinon elle renvoie une valeur non nul et la liste root vide.
    
    Rem : la valeur non nulle est le retour de la fonction DGEEV de LaPack sauf sans le cas où la valeur absolue du terme dominant est inférieure à l'epsilon du type T. 
*/
template <class T, int s>
int ret_roots_by_companion_matrix( const Vec<T,s>& a, int m, Vec< complex<T> >& root) {
    root.resize( 0 );
    if (abs ( a[m] ) < 16*std::numeric_limits<T>::epsilon())
        return std::numeric_limits<int>::max();
    int ldvl = 1;
    int ldvr = 1;
    int lwork = 20*m;
    int lda = m;
    int info;
    double* zone = new double[m*m+22*m];
    
    double* A = zone;
    double* wr = zone + (m*m);
    double* wi = zone + (m*m)+m;
    double* work = zone + (m*m)+2*m;
    double iam = 1. / a[m];
    
    memset( A, 0, m*m*sizeof(double) );
    A[m-1] = -a[0] * iam;
    for( unsigned i=1;i<m;++i) {
        A[m*i+i-1] = 1;
        A[m*i+m-1] = -a[i] * iam;
    }

    dgeev_("N","N",&m,A,&lda,wr,wi,NULL,&ldvl,NULL,&ldvr,work,&lwork,&info);
    if ( not( info )) {
        for( unsigned i=0;i<m;++i)
            root.push_back( std::complex<T>( wr[i], wi[i] ) );
    }
    delete[] zone;
    return info;
}

/*!
function [defl,pz,p1z,p2z,error] = mc02afy(p,dx); 
Evaluate a polynomial, its first derivative 
and half of its second derivatives at a point. 
Compute error in polynomial value at point. 

    Entrées :
        n : degré du polynôme

*/
/*
template <class T, int s>
void mc02afy( const Vec<T,s>& a, int n, T dx, Vec<T>& defl, T* pz, T* p1z, T* p2z ) {
    T deps = 1.11e-16; 
    T absx = abs(dx); 
    defl = zeros(1,length(p)); 
    dv = p(1); 
    w = 0;
    defl(1) = p(1); 
    defl(2) = p(2) + dx*defl(1); 
    for i=3:n+1 
    w = dv + dx*w; 
    dv = defl(i-1) + dx*dv; 
    defl(i) = p(i) + dx*defl(i-1); 
    end 
    error = (2/3)*abs(p(1)); 
    for i = 2:n+1 
    error = abs(defl(i)) + absx*error; 
    end 
    error = 16*deps*abs(defl(n+1))+3*absx*error; 
    pz = polyval(p, dx); 
    df = (n:-1:1).*p(1:end-1); 
    d2f = (n-1:-1:1).*df(1:end-1); 
    p1z = polyval(df, dx); 
    p2z = 0.5*polyval(d2f,dx);
}
*/
/*!
    A MATLAB version of the NAG subroutine C02AFZ 
    for computing the zeros of polynomials using 
    Laguerre’s method.

    résout le polynôme a_0 + a_1 X + a_2 X^2 + ... + a_m X^m grâce à sa matrice compagnon.
    m est donc le degré.

*/
/*
template <class T, int s>
void ret_roots_by_Matlab_code( const Vec<T,s>& a, int ndeg, Vec< complex<T> >& root)  {
    Vec<T,s> DU = f; 
    int n = ndeg; 
    int N = n+1; 
    int ihalf = 0; 
    int ispir=0; 
    int iter = 0; 
    int cauchy = 0; ///Region containing smallest zero has not been computed 
    while (n>2) {
        T small = 1e-3; T bigone=1.0001;
        T smlone=0.99999; T rconst=1.445;
        T onepqt=1.25; T gama=1; T theta=2;
        if (not(cauchy)) { 
            T rtn = sqrt(n);
            T G = exp((log(abs(DU(N)))-log(abs(DU(1))))/n+small);
            T cr = DU(N-1)/DU(N);
            ctemp = 2*DU(N-2)/(n*(n-1));
            cf2 = DU(N-1)*2/n;
            tmp = roots([ctemp cf2 DU(N)]);
            c = tmp(2); cf1 = tmp(1);
            cr = cr*(n-2)/n;
            ctemp = cr*c + n-1;
            cdiro = c/ctemp;
            abdiro = abs(cdiro);
            G = min(G,bigone*min(abs(c),rtn*abdiro)); G = G(1);
            R = G; 
            S = bigone*G; ///upper bound for magnitude of smallest zero 
            deflat(1:N) = abs(DU(1:N));
            while (R < S) { 
                T = real(deflat(1));
                S = 0;
                for(int i=1; i<n; ++i) { 
                    S = R*S + T;
                    T = R*T + real(deflat(i+1)); 
                }
                S = R*S + T;
                T = (R*T - real(deflat(N)))/S;
                S = R;
                R = R - T; 
            }
            cauchy = 1;
            upperb = min(rconst*n*R, G);
            lowerb = smlone*S;
        } 
        T fejer = upperb;
        G = upperb;
        T cdir = cdiro; T abdir = abdiro; T ratio = abdir/G;
        dzn = 0;
        fn = abs(DU(N));
        f0 = fn;
        spiral = 0; startd=0; contin= 1;
        while (contin) { 
            iter = iter + 1;
            if (ratio > theta) { 
                if (startd) {
                    ihalf = ihalf + 1;
                    abscl = abscl*0.5;
                    cl = cl*0.5;
                    dx = abs(real(dzn))+abs(imag(dzn));
                    if (dx+abscl ~= dx) 
                        dzn = dz0 + cl; 
                    else { 
                        if (fn >= err*n^2) 
                            std::cerr << "Contact Wankere \n **Unlikely Failure" << std::endl; 
                        contin = 0;
                    }
                } else {
                    ispir = ispir + 1; 
                    if (spiral) 
                        c = cspir*dzn; 
                    else { 
                        spiral = 1; 
                        cspir = -onepqt/n + 1i; 
                        abscl = lowerb/n^2; 
                        ctemp = cdir/abdir; 
                        c = ctemp*lowerb; 
                    }
                    dzn = c; 
                } 
            } else { 
                startd = 1; 
                if ((ratio > gama) and (startd or spiral or (lowerb <= G))) { 
                    ratio = gama/ratio; 
                    cdir = cdir*ratio; 
                    abdir = abdir*ratio; 
                }
                G = fejer; cl = cdir; 
                abscl = abdir; 
                f0 = fn; dz0 = dzn;
                dzn = dz0 + cl; 
            }
            [deflat,cf,cf1,cf2,err] = mc02afy(DU,dzn); 
            fn = abs(cf); 
            if (cf == 0) /// A root has been found 
                contin = 0; /// Exit iteration loop 
            else 
                if ((fn >= f0) and startd) 
                    ratio = theta*bigone; 
            else { 
                cr = cf1/cf;
                cf2 = cf2*2/((n-1)*n);
                ctemp = cf1*2/n;
                tmp = roots([cf2 ctemp cf]);
                c = tmp(2);
                cf1 = tmp(1);
                fejer = abs(c);
                cr = cr*(n-2)/n;
                ctemp = c*cr + n-1;
                cdir = c/ctemp;
                abdir = abs(cdir);
                ratio = abdir/G;
                fejer = min(rtn*abdir, fejer);
                dx = abs(real(dzn))+abs(imag(dzn));
                if (abdir <= 1e-15)
                    contin = 0; 
            } 
        } 
        DU = deflat; 
        z(n) = dzn;
        N = N-1; n = n-1; 
        cauchy = 0;
    } 
    if (n==2) { 
        tmp = roots([DU(1) DU(2) DU(3)]); 
        z(1) = tmp(1); 
        z(2) = tmp(2); 
    } else { 
        if (n==1) 
            z(1) = -DU(2)/DU(1); 
        else 
            R = Inf; 
    }
    z = z(:);
}
*/

/*!
Entrées :
 * coefs sont les coefficients du polynôme; coefs[0] est le terme constant.
 * degree es le degré du polynôme ( degree <= si + 1 ).
 * initial[0] = m doit être une approximation du milieu de deux racines.
 * initial[1] = e doit être une approximation de la demi-différence des racines.
        i.e. r1 = m - e
             r2 = m + e
Sortie :
 * res[0] est une approximation du milieu de deux racines.
 * res[1] est une approximation de la demi-différence des racines.
 * rootFound indique si l'algorithme a réussi ou échoué.

 */
template<class T, int si>
Vec<T,2> bairstow( const Vec<T, si>& coefs, int degree,  Vec<T,2> initial, bool& rootFound, int maxIter = 30, T prec = 1e-4 ) {
    T b, ba, baa, S, Sa, Saa, Saaa, s, p, R0, dp, err, err_r, dete, ds;
    int c;
    bool problem = false;

    s = initial[0];
    p = initial[1];
    err_r = numeric_limits<T>::max();
    //PRINT( s ); PRINT( p ); 

    for( c = 0; c < maxIter; ++c ) {
        baa = coefs[degree];
        ba  = coefs[degree-1] + s * baa;
        Saa = 0;
        Sa  = coefs[degree];
        for( int i = 2 ; i<= degree; ++i ) {
            b = coefs[degree-i] + s * ba - p * baa;
            S = ba + s * Sa - p * Saa;
            baa = ba;
            ba  = b;
            Saaa = Saa; 
            Saa  = Sa;
            Sa   = S;
        }
        R0  = ba - s * baa; /// terme constant du reste
        /// R1  = baa == coeff du x du reste
        dete = Sa * Saaa - pow( Saa, 2 ); /// déterminant de la dérivée
        if (dete == 0) { problem = true; break; }
        dete = 1 / dete;
        ds = ( baa * Saa - ba * Saaa ) * dete; /// Newton-Raphson
        dp = ( baa * Sa  - ba * Saa ) * dete;
        s += ds;
        p += dp;
        //PRINT( c+1 );PRINT( ds ); PRINT( dp ); PRINT( baa ); PRINT( R0 ); 
        err = (abs(ds) + abs(dp))/ ( (s==0) + (p==0) + abs(s) + abs(p) );
        err_r = abs(baa) + abs(R0); 
        if ((err  < prec ) or (err_r < 2 * numeric_limits<T>::epsilon() )) 
            break;
    }
    if ((problem) or (c == maxIter)) {
        rootFound = false;
        return initial;
    }
    rootFound = true;
    return Vec<T,2>(s,p); 
}

/*!
Entrées :
    * coefs sont les coefficients du polynôme; coefs[0] est le terme constant.
    * degree es le degré du polynôme ( degree <= si + 1 ).
    * initial[0] = m doit être une approximation du milieu de deux racines.
    * initial[1] = e doit être une approximation de la demi-différence des racines.
        i.e. r1 = m - e
             r2 = m + e
Sortie :
    * res[0] est une approximation du milieu de deux racines.
    * res[1] est une approximation de la demi-différence des racines.
    * rootFound indique si l'algorithme a réussi ou échoué.

*/
template<class T, int si>
Vec<T,2> bairstow_modified( const Vec<T, si>& coefs, int degree,  Vec<T,2> initial, bool& rootFound, int maxIter = 30, T prec = 1e-4 ) {
     T b, ba, baa, S, Sa, Saa, E, Ea, Eaa, e, dete, ds, de, s, p, R0, J21, J22, err, err_r;
     int c;
     bool problem = false;
    
     s = 2*initial[0];
     e = initial[1]; //e = pow(0.5*initial[1],2);
     err_r = numeric_limits<T>::max();
     //PRINT( s ); PRINT( e ); 
     
     for( c = 0; c < maxIter; ++c ) {
        p = 0.25*s*s-e*e; //p = 0.25*s*s-e;
        baa = 0;
        ba  = coefs[degree];
        Saa = 0;
        Sa  = 0;
        Eaa = 0;
        Ea  = 0;
        for( int i = 1 ; i<= degree; ++i ) {
            b = coefs[degree-i] + s * ba - p * baa;
            S = ba -0.5 * s * baa + s * Sa - p * Saa;
            E = 2 * e * baa + s * Ea - p * Eaa; //E = baa + s * Ea - p * Eaa;
            baa = ba;
            ba  = b;
            Saa = Sa;
            Sa  = S;
            Eaa = Ea;
            Ea  = E; 
        }
        J21 = Sa - s * Saa - baa;
        J22 = Ea - s * Eaa;
        R0  = ba - s * baa; /// terme constant du reste
        /// R1  = baa == coeff du x du reste
        dete = Saa * J22 - Eaa * J21; /// déterminant de la dérivée
        if (dete == 0) { problem = true; break; }
        dete = 1 / dete;
        ds = (  J22 * baa - Eaa * R0 ) * dete; /// Newton-Raphson
        de = ( -J21 * baa + Saa * R0 ) * dete;
        s -= ds;
        e -= de;
        //PRINT( c+1 );PRINT( ds ); PRINT( de ); PRINT( baa ); PRINT( R0 ); 
        err = (abs(ds) + abs(de))/ ( (s==0) + (e==0) + abs(s) + abs(e) );
        err_r = abs(baa) + abs(R0); 
        if ((err  < prec ) or (err_r < 2 * numeric_limits<T>::epsilon() )) 
            break;
    }
    if ((problem) or (c == maxIter)) {
        rootFound = false;
        return initial;
    }
    rootFound = true;
    /*return Vec<T,2>(0.5*s,sqrt(abs(e))); */return Vec<T,2>(0.5*s,e); 
}


/// méthode de Newton pour un polynôme de degré 3 pour une racine simple réelle
template <class T, int s, class T2 >
T2 ret_newton_degree_3_simple_one_step( const Vec<T, s>& coefs, T2 x0) {
    return x0 - (coefs[0]+coefs[1]*x0+coefs[2]*x0*x0+coefs[3]*x0*x0*x0)/(coefs[1]+2*coefs[2]*x0+3*coefs[3]*x0*x0);
}

/// méthode de Newton pour un polynôme de degré 3 pour une racine simple réelle
template <class T, int s, class T2>
T2 ret_newton_degree_3_simple( const Vec<T, s>& coefs, T2 x0, unsigned nb_step, T tolerance = 16*std::numeric_limits<T>::epsilon()) {
    T2 x1;
    unsigned i = 0;
    while( true) {
        x1 = ret_newton_degree_3_simple_one_step( coefs, x0 );
        //PRINT( x1 );
        if ( std::abs( x0 - x1 ) / ( 1 + std::abs( x0 ) + std::abs( x1 ) ) < tolerance  )
            break;
        if ( i == nb_step )
            break;
        i++;
        x0 = x1;  
    }
    return x1;
}

/// méthode de Newton pour un polynôme de degré 3 pour une racine double réelle
template <class T, int s>
T ret_newton_degree_3_double_one_step( const Vec<T, s>& coefs, T x0) {
    return (-coefs[1]*x0+coefs[3]*x0*x0*x0-2*coefs[0])/(coefs[1]+2*coefs[2]*x0+3*coefs[3]*x0*x0);
}

/// méthode de Haley pour un polynôme de degré 3
template <class T, int s>
T ret_haley_degree_3_one_step( const Vec<T, s>& coefs, T x0) {
    T x02 = x0*x0;
    T x03 = x0*x0*x0;
    T x04 = x02*x02;
    T d0  = coefs[1]*coefs[1]-2*coefs[0]*coefs[2];
    T d1  = 2*coefs[1]*coefs[2]-6*coefs[0]*coefs[3];
    T d2  = 2*coefs[2]*coefs[2];
    T d3  = 4*coefs[2]*coefs[3];
    T d4  = 3*coefs[3]*coefs[3];
    return x0 - (coefs[0]+coefs[1]*x0+coefs[2]*x02+coefs[3]*x03)*(coefs[1]+2*coefs[2]*x0+3*coefs[3]*x02)/ (d0+d1*x0+d2*x02+d3*x03+d4*x04);
}

/// méthode de Haley pour un polynôme de degré 4
template <class T, int s, class T2>
T2 ret_haley_degree_4_one_step( const Vec<T, s>& coefs, T2 x0) {
    T2 x02 = x0*x0;
    T2 x03 = x0*x0*x0;
    T2 x04 = x02*x02;
    T2 x05 = x02*x03;
    T2 x06 = x03*x03;
    T2 d0  = coefs[1]*coefs[1]-2*coefs[0]*coefs[2];
    T2 d1  = 2*coefs[1]*coefs[2]-6*coefs[0]*coefs[3];
    T2 d2  = 2*coefs[2]*coefs[2]-12*coefs[0]*coefs[4];
    T2 d3  = -4*coefs[1]*coefs[4]+4*coefs[2]*coefs[3];
    T2 d4  = 2*coefs[2]*coefs[4]+3*coefs[3]*coefs[3];
    T2 d5  = 6*coefs[3]*coefs[4];
    T2 d6  = 4*coefs[4]*coefs[4];
    return x0 - (coefs[0]+coefs[1]*x0+coefs[2]*x02+coefs[3]*x03+coefs[4]*x04)*(coefs[1]+2*coefs[2]*x0+3*coefs[3]*x02+4*coefs[4]*x03) / (d0+d1*x0+d2*x02+d3*x03+d4*x04+d5*x05+d6*x06);
}

/// méthode de Newton pour un polynôme de degré 3 pour une racine simple réelle
template <class T, int s, class T2>
T2 ret_haley_degree_4( const Vec<T, s>& coefs, T2 x0, unsigned nb_step, T tolerance = 16*std::numeric_limits<T>::epsilon()) {
    T2 x1;
    unsigned i = 0;
    while( true) {
        x1 = ret_haley_degree_4_one_step( coefs, x0 );
//PRINT( x1 );
        if ( std::abs( x0 - x1 ) / ( 1 + std::abs( x0 ) + std::abs( x1 ) ) < tolerance  )
            break;
        if ( i == nb_step )
            break;
        i++;
        x0 = x1;  
    }
    return x1;
}

template <class T, int s>
void ret_roots_degree_3( const Vec<T, s>& coefs, Vec< complex<T> >& res) {
    /// méthode de Cardan. Source : http://fr.wikipedia.org/wiki/Méthode_de_Cardan
    typedef complex<T> C;
    res.resize(0);
    unsigned nb_step = 5;

    T tmp = T(1) / coefs[3];
    T b = coefs[2]*tmp;
    T c = coefs[1]*tmp;
    T d = coefs[0]*tmp;
    T del = -b/(T)3;
    T p = c - b*b/(T)3;;
    T q = b*(2*b*b-9*c)/(T)27 + d;
    T delta = 4/(T)27*p*p*p+q*q;
    //PRINT( tmp ); PRINT( b ); PRINT( c ); PRINT( d ); PRINT( p ); PRINT( q ); PRINT(  delta );
    if (std::abs(delta)<16*std::numeric_limits<T>::epsilon()) {
                /// deux racines réelles
        T tmp2 = 3*q/p;
        res.push_back( ret_haley_degree_3_one_step( coefs, tmp2+del ) );
        tmp2 = -0.5*tmp2+del;
        tmp2 = ret_haley_degree_3_one_step( coefs, tmp2 );
        res.push_back(tmp2);
        res.push_back(tmp2);
        return;
    }
    T ji = 0.5*sqrt(3);
    if (delta>=0) {
                /// une racine réelle et deux racines complexes conjuguées
        delta = sqrt(delta);
        T u=0.5*(-q+delta);
        T v=0.5*(-q-delta);
        u = sgn(u)*std::pow(std::abs(u),1/T(3));
        v = sgn(v)*std::pow(std::abs(v),1/T(3));
        res.push_back( ret_newton_degree_3_simple( coefs, u+v+del, nb_step ) );
        res.push_back( ret_newton_degree_3_simple( coefs, C( -0.5*(u+v)+del, ji*(u-v) ), nb_step ) );
        res.push_back( ret_newton_degree_3_simple( coefs, C( -0.5*(u+v)+del, ji*(v-u) ), nb_step ) );
    } else {
                /// trois racines réelles
        C u(std::pow(C(-0.5*q,0.5*sqrt(-delta)),1/(T)3));
        C j(-0.5,ji);
        //PRINT( del );
        //PRINT( 2*u.real()+del );
        res.push_back( ret_newton_degree_3_simple( coefs, 2*u.real()+del, nb_step ) );
        u *= j;
        //PRINT( 2*u.real()+del );
        res.push_back( ret_newton_degree_3_simple( coefs, 2*u.real()+del, nb_step ) );
        u *= j;
        //PRINT( 2*u.real()+del );
        res.push_back( ret_newton_degree_3_simple( coefs, 2*u.real()+del, nb_step ) );
                /// pas optimisé ...
    }
}

template <class T, int s>
void ret_roots_degree_4( const Vec<T, s>& coefs, Vec< complex<T> >& res) {
    /// méthode de Ferrari. Source : http://fr.wikipedia.org/wiki/Méthode_de_Ferrari
    /// pas de lien avec la speakrine
    typedef complex<T> C;
    C racine;
    unsigned i, nb_step = 5;
    T tmp = 1/ (T) coefs[4];
    T b = coefs[3]*tmp;
    T c = coefs[2]*tmp;
    T d = coefs[1]*tmp;
    T e = coefs[0]*tmp;
    //PRINT(b);PRINT(c);PRINT(d);PRINT(e);
    T del = 0.25*b;
    T b2 = b*b;
    T b3 = b*b*b;
    T p = -3*b2/(T)8+c;
    T q = b3/(T)8 - 0.5*b*c + d;
    T r = -3*b2*b2/(T)256 + c*del*del - del*d + e;
    Vec<T,4> disc(4*r*p-q*q,-8*r,-4*p,8);
    //PRINT(disc);
    Vec<C> r_disc;
    ret_roots_degree_3( disc, r_disc );
    //PRINT( r_disc );
    for(i=0;i<r_disc.size();++i)
        if (is_real( r_disc[i]))
            break;
    C a0 = -sqrt(C(2*r_disc[i].real()-p,0));
    C b0 = -0.5*q/a0;
    Vec<C> z1 = root_of_second_degree_equation(a0,b0+r_disc[i]);
    Vec<C> z2 = root_of_second_degree_equation(-a0,r_disc[i]-b0);
    for(int j=0;j<z1.size();++j) {
        racine = z1[j]-del;
        if ( is_real( racine ) )
            res.push_back( ret_haley_degree_4( coefs, racine.real(), nb_step ) );
        else
            res.push_back( ret_haley_degree_4( coefs, racine, nb_step ) );
    }
    for(int j=0;j<z2.size();++j) {
        C racine = z2[j]-del;
        if ( is_real( racine ) )
            res.push_back( ret_haley_degree_4( coefs, racine.real(), nb_step ) );
        else
            res.push_back( ret_haley_degree_4( coefs, racine, nb_step ) );
    }
    /// pas optimisé ...
}

/**
  @author Gouttebroze
*/

/*!
    = Remarque générale
        Pour pouvoir manipuler des polynômes (mono et multivariables), il faut utiliser le fichier polynomials.h

        \relates PolApprox
        \relates RatApprox
        \relates Rat

    = Parametres templates pour les polynômes 
        Il y a trois parametres templates pour définir un polynome : Pol<nd,nx,T>
    
        * nd est le degré maximal du polynome (valeur par défaut : 4)
        * nx est le nombre de variables du polynome (valeur par défaut : 1)
        * T est le type des coefficients du polynomes (valeur par défaut : double)
    
        Pour diminuer les temps de calculs, il y a une spécialisation de la classe Pol pour les polynomes monovariables (nx=1). Ils s'utilisent donc légèrement différement que les polynomes multivariables. 

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

        * \anchor 1 Pour créer un polynome constant égal a 4 :
            \code C/C++
                Pol<nd,nx,T> P(4);
        
        * \anchor 2 Pour afficher le polynome P :
            \code C/C++
                cout << P << endl;
                OU
                PRINT(P);
        * \anchor 3 Pour récupérer les coefficients du polynome P :
            \code C/C++
                Vec<T> V=P.coefficients();
        * \anchor 4 Pour récupérer les puissances du polynome P :
            \code C/C++
                Vec<Vec<unsigned,nx> > V=P.powers();
        * \anchor 5 Pour évaluer le polynome de 3 variables P au point (4,-2,1) :
            \code C/C++
                Pol<nd,3,T> P = ... blabla ...
                Vec<T,3> V(4,-2,1);
                Vec<T> W=P(V);
        * \anchor 6 Pour évaluer le polynome monovariable P au point 4 :
            \code C/C++
                Pol<nd,1,T> P = ... blabla ...
                T s=P(V);
        * \anchor 7 Pour obtenir les dérivées du polynome multivariables P :
            \code C/C++
                Vec<Pol<nd-1,nx,T>,nx> V=P.derivative();
        * \anchor 8 Pour obtenir la dérivée du polynome monovariable P :
            \code C/C++
                Pol<nd-1,nx,T> Q=P.derivative();
        * \anchor 9 Pour obtenir la primitive du polynome monovariable P qui s'annule en a:
            \code C/C++
                T a; Pol<nd-1,nx,T> Q=P.integral(a);
        * \anchor 10 Pour effectuer des opérations algébriques sur des polynomes P et Q :
            \code C/C++
                Pol<nd,nx,T> R=P+Q;
                Pol<nd,nx,T> R=P-Q;
                Pol<nd,nx,T> R=P*Q;
                Pol<nd,nx,T> R=P/Q;
        * \anchor 11 Pour obtenir les racines du polynome monovariable P :
            \code C/C++
                Vec<complex<T> > V=P.roots(); 

    \friend camille.gouttebroze@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr

    \brief polynômes à une ou plusieurs indéterminées et de degré quelconque bornés

    \keyword Mathématiques/Objet

    \author Camille Gouttebroze
*/

template <int nd=4,int nx=1,class T=double>
class Pol {
  public:
    static const int degree=nd;
    static const int variables_number=nx;
    static const int dim=DimPol<nd,nx>::valeur;  
    typedef complex<T> C;
      
    Pol () {}

    Pol(const T &a) {
        coefs.set(T(0));
        coefs[0]=a;
    }

    Pol(const T &a, const T &b, unsigned q) {
        coefs.set(T(0));
        coefs[0]=a;
        if (PolPowers<nd,nx>::needs_initialization)
            PolPowers<nd,nx>::initialize();
        PolPowers<nd,nx> op;
        for (unsigned i=0;i<dim;i++)
           if (op(i,q)) {
                coefs[i]=b;
                break;
            }
    }

    template <class T2, int nd2>
    void init(const Vec<T2,nd2> &V) {
        for(unsigned i=0; i<min(V.size(),dim); ++i)
            coefs[i] = T(V[i]);
        for(unsigned i=V.size(); i<dim; ++i)
            coefs[i] = T(0);
    }

    template <class T2, int nd2>
    Pol(const Vec<T2,nd2> &V) {
        init(V);
    }

    template <int nd2, class T2>
    Pol (const Pol<nd2,nx,T2> &P) {
        PolTroncates<MAX(nd,nd2),MIN(nd,nd2),nx> op;
        coefs = op(P.coefficients());
    }

    template <int nx2, class T2>
    Pol (const Pol<nd,nx2,T2> &P, const Vec<unsigned,nx2> &v_ind) {
        unsigned rest = PolRestriction<nd,nx,nx2>::get_index(v_ind);
        if (PolRestriction<nd,nx,nx2>::needs_initialization[rest])
            PolRestriction<nd,nx,nx2>::initialize(v_ind,rest);
        PolRestriction<nd,nx,nx2> op;
        coefs = op(P.coefficients(),rest);
    }

    template <int nx2, class T2>
    Pol (const Pol<nd,nx2,T2> &P, const Vec<unsigned,nx> &v_ind) {
        unsigned rest = PolRestriction<nd,nx2,nx>::get_index(v_ind);
        if (PolRestriction<nd,nx2,nx>::needs_initialization[rest])
            PolRestriction<nd,nx2,nx>::initialize(v_ind,rest);
        PolRestriction<nd,nx2,nx> op;
        coefs = op(P.coefficients(),rest);
    }

    template <int nx2, class T2, class T3>
    Pol (const Pol<nd,nx2,T2> &P, const Vec<unsigned,nx> &v_ind, const Vec<T3,nx2-nx> &x) {
        unsigned rest = PolRestriction<nd,nx2,nx>::get_index(v_ind);
        if (PolPartialEvaluates<nd,nx2,nx>::needs_initialization[rest])
            PolPartialEvaluates<nd,nx2,nx>::initialize(v_ind,rest);
        PolPartialEvaluates<nd,nx2,nx> op;
        coefs = op(P.coefficients(),x,v_ind,rest);
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
        PolBinOp<Multiplies,nd,nd,nx> op;
        coefs = op(coefs,P.coefficients());
    }

    template <class T2>
    void operator/= (const Pol<nd,nx,T2> &P) {
        PolBinOp<Divides,nd,nd,nx> op;
        coefs = op(coefs,P.coefficients());
    }

    template <class T2>
    typename TypePromote<Multiplies,T,T2>::T operator() (const Vec<T2,nx> &x) const {
        if (PolPowers<nd,nx>::needs_initialization)
            PolPowers<nd,nx>::initialize();
        PolPowers<nd,nx> op;
        return op(coefs,x);
    }

    typedef Pol<(nd>0?nd-1:nd),nx,T> Derivative;

    typename VecIfStaticSizeIsOneAndScalarIfNot<Derivative,nx>::T derivative() const {
        if (PolDerivative<nd,nx>::needs_initialization)
            PolDerivative<nd,nx>::initialize();
        PolDerivative<nd,nx> op;
        return typename VecIfStaticSizeIsOneAndScalarIfNot<Derivative,nx>::T(op(coefs));
    }

    const Vec<T,DimPol<nd,nx>::valeur> &coefficients() const { return coefs; };

    Vec<typename VecIfStaticSizeIsOneAndScalarIfNot<unsigned,nx>::T,dim> powers() {
        if (PolPowers<nd,nx>::needs_initialization)
            PolPowers<nd,nx>::initialize();
        PolPowers<nd,nx> op;
        return op();
    }

    template <class T2> typename TypePromote<Multiplies,T,T2>::T operator() (const T2 &x) const {
        PolPowers<nd,nx> op;
        return op(coefs,x);
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

    /// utilisation du critère de Descartes
    int bound_positive_roots() {
        return nb_changed_signe(coefs);
    }

    Pol<nd,nx,T> remainder( /** const */  Pol<nd,nx,T> &D) /**const*/ {
        assert(nx==1);
        if (D.is_zero()) {
            std::cerr << "Warning : division by polynom zero !" << endl;
            assert(0);
            return Pol<nd,nx,T>();
        }
        Vec<T> r=coefs;
        //T norm=norm_inf(r);
        //while (r.size()>0 and abs(r.back())/norm < 16*std::numeric_limits<T>::epsilon())
        //    r.pop_back();
        while ((r.size()) and abs(r.back()) < 16*std::numeric_limits<T>::epsilon())
           r.pop_back();

        Vec<T> d=D.coefficients();
        //norm=norm_inf(d);
        while (abs(d.back()) < 16*std::numeric_limits<T>::epsilon())
            d.pop_back();
        
        if (d.size()<=r.size()) {
            /// méthode naïve
            /// on commence par normaliser le diviseur puis on retire le dernier terme (inutile).
            T dominant = d.pop_back();
            for(int i=0;i<r.size();++i)
                r[i] /= dominant;
            for(int i=0;i<d.size();++i)
                d[i] /= dominant;
            while(r.size() >= 1+d.size()) { /// tant que deg(r) >= deg(d) on divise. Rappel deg(r) = r.size()+1 et deg(d) = d.size()+2
                T aux = r.pop_back(); /// terme dominant de r
                for (int j=0;j<d.size();j++)
                    r[r.size()-d.size()+j] -= aux*d[j];
            }
/*            for (unsigned i=1;i<=coefs.size()-d.size()+1;i++) {
                T aux=r[r.size()-1]/d[d.size()-1];
                r.pop_back();
                for (unsigned j=0;j<d.size()-1;j++)
                    r[r.size()-d.size()+j+1]-=aux*d[j];
            }*/
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
        while ((e-c)/(abs(e)+abs(c))>16*dim*std::numeric_limits<T>::epsilon()) {
            T d=(c+e)/2;
            if (sgn(operator()(d))==sgn(operator()(c)))
                c=d;
            else
                e=d;
        }
        return (c+e)/2;
    }

    T newton(const T &d, bool& notFound, int imax = 100) const{
        assert(nx==1);
        T a=d;
        T b=d-1;
        Derivative Q=derivative();
        int compteur=0;
        while (abs(a-b)/max(abs(a),abs(b))>16*dim*std::numeric_limits<T>::epsilon() && compteur<imax) {
            b=a;
            a-=operator()(a)/Q(a);
            compteur++;
        }
        if (compteur==imax)
            notFound = true;
        else
            notFound = false;
        return a;
    }

    /*!
    Méthode de Newton avec un germe complexe, d, proche d'une racine du polynôme
    */
    C newton(const C &d, bool& notFound, int imax = 100) const{
        assert(nx==1);
        C a=d, p , p1;
        C b=d-C(1);
        int deg = degrees[0];
        int compteur=0;
        while (abs(a-b)/max(abs(a),abs(b))>16*dim*std::numeric_limits<T>::epsilon() && compteur<imax) {
            b=a;
            /// code de numerical recipes page 376
            p  = coefs[deg]*d+coefs[deg-1];
            p1 = coefs[deg];
            for(int i = deg-2;i>=0;--i) {
                p1 = p + p1*d;
                p  = coefs[i]+p*d;   
            }
            a -= p/p1;
            //a-=operator()(a)/Q(a);
            compteur++;
        }
        if (compteur==imax)
            notFound = true;
        else
            notFound = false;
        return a;
    }
    
    T householder(const T &d, bool& c, int imax = 100) const {
        assert(nx==1);
        T a=d;
        T b=d-1;
        Derivative Q=derivative();
        typename Derivative::Derivative R=Q.derivative();
        int compteur=0;
        while (abs(a-b)/max(abs(a),abs(b))>16*dim*std::numeric_limits<T>::epsilon() && compteur<imax) {
            b=a;
            T pa=operator()(a);
            T qa=Q(a);
            a-=(pa/qa)*(1+(pa*R(a))/(2*std::pow(qa,2)));
            compteur++;
        }
        if (compteur==imax)
            c = true;
        return a;
    }

    /// source : http://fr.wikipedia.org/wiki/Racine_d'un_polynôme
    /// il faut que x0, x1 et x2 soient différents 2 à 2.
    T muller_real( T x0, T x1, T x2, bool& rootFound, int imax = 100) const {
        assert(nx==1);
        T a,b,r,d,f01,f12,y0,y1,c;
        int i=0;
        y0 = (*this)(x0);
        y1 = (*this)(x1);
       rootFound = false;
        
       while (i<imax) {
            c   = (*this)(x2);
            if (abs(c) < 16*dim*std::numeric_limits<T>::epsilon()) {
                rootFound = true;
                return x2;
            }
            f01 = (y1-y0)/(x1-x0);
            f12 = (c -y1)/(x2-x1);
            a   = (f12-f01)/(x2-x0);
            b   = f12+a*(x2-x1);
            d = b*b-4*a*c;
            if (d<0)
                return 0;
            r   = sqrt(d);
            if (abs(b+r) < abs(b-r))
                d = 2*c/(r-b);
            else
                d = -2*c/(r+b);
            if (abs(d/(1+abs(x2))) < 16*dim*std::numeric_limits<T>::epsilon()) {
                rootFound = true;
                return x2;
            }
            f01 = x2;
            f12 = x1;
            x2 += d;
            x1 = f01;
            x0 = f12;
            if (abs(x0-x2) < 16*dim*std::numeric_limits<T>::epsilon()) 
                return 0;
            i++;
            f01 = c;
            f12 = y1;
            y1  = f01;
            y0  = f12;
        }
    }
    
    /** 
        renvoie le degré du polynôme pour chaque indéterminée.
        Si l'indéterminée n'apparaît pas, le degré est -1.
    */
    Vec<int,nx> get_degrees() /**const*/ {
        assert(nx==1);
        update_degrees();
        return degrees;
    }
    
    /// renvoie vrai si c'est le polynôme nul et faux sinon.
    /// code à améliorer
    bool is_zero() /**const*/ {
        update_degrees();
        for(int i=0;i<nx;++i)
            if (degrees[i]>=0)
                return false;
        return true;
    }
    
    void update_degrees() {
        assert(nx==1);
        int taille = degree; /** VERSION ORIGINALE : int taille = dim ??? */; 
        while ((abs(coefs[taille])<16*numeric_limits<T>::epsilon()) and (taille>=0))
            taille--;
        degrees[0] = taille;
        /** TODO : les opérations + - += -= *  etc / peuvent modifier le degré  */   
    }
    
    /// problème si T est du type complex<X> ... à régler. On fera l'hypothèse que T est soit entier, soit float, double, long double.
    Vec<C> roots() /**const*/ {
        assert(nx==1);
        Vec<C> res;
        update_degrees(); /// PROVISOIRE : cela ne devrait pas être fait ici.
        int taille = degrees[0]+1;
        if (taille==2)
            res.push_back(-coefs[0]/coefs[1]);
        else if (taille==3) {/// degré 2
            T tmp = (T)1 / coefs[2];
            T b = coefs[1]*tmp;
            T c = coefs[0]*tmp;
            T delta = b*b-4*c;
            if (std::abs(delta)<16*std::numeric_limits<T>::epsilon()) {
                res.push_back(-0.5*b);
                return res;
            }
            if (delta>0) {
                delta = sqrt(delta);
                res.push_back(-0.5*(b+delta));
                res.push_back(-0.5*(b-delta));
            } else {
                delta = sqrt(-delta);
                res.push_back(C(-0.5*b,0.5*delta));
                res.push_back(C(-0.5*b,-0.5*delta));
            }
        }
        else if (taille==4) { /// degré 3
            if ( abs(coefs[3]) > abs(coefs[0]) )
                ret_roots_degree_3(coefs, res );
            else {
                Vec<T,4> icoefs;
                icoefs[0] = coefs[3]; icoefs[1] = coefs[2]; icoefs[2] = coefs[1]; icoefs[3] = coefs[0];
                ret_roots_degree_3( icoefs, res );
                for( unsigned t =0; t<3; ++t)
                    res[t] = 1. /res[t]; 
            }
        }
        else if (taille==5) { /// degré 4
            if ( abs(coefs[4]) > abs(coefs[0]) )
                ret_roots_degree_4(coefs, res );
            else {
                Vec<T,5> icoefs;
                icoefs[0] = coefs[4]; icoefs[1] = coefs[3]; icoefs[2] = coefs[2]; icoefs[3] = coefs[1]; icoefs[4] = coefs[0];
                ret_roots_degree_4( icoefs, res );
                for( unsigned t =0; t<4; ++t)
                    res[t] = 1. /res[t]; 
            }
            ///ret_roots_by_companion_matrix( coefs, taille-1, res );
        } else if (taille>5) { /// degré >= 4
            ret_roots_by_companion_matrix( coefs, taille-1, res );
            /**
            Pour certaines racines voisines, on obtient des solutions complexes proches de l'axe des abscisses.
            Dans ce cas, on lance un baristow pour essayer de corriger le tir
            */
            for ( int t = 0; t< res.size(); ++t ) {
                T absimage = abs(res[t].imag());
                if (not(is_real(res[t])) and (absimage < 1e-4)) {
                    bool rootFound;
                    //Vec<double,2> resbair = bairstow( coefs, taille-1, Vec<T,2>(2 * res[t].real(), 0.01*absimage ), rootFound, 30, 1e-15/*2*std::numeric_limits<T>::epsilon()*/ );
                    Vec<double,2> resbair = bairstow_modified( coefs, taille-1, Vec<T,2>( res[t].real(), absimage ), rootFound, 30, 2*std::numeric_limits<T>::epsilon() );
                    if (rootFound) {
                        res[t]   = resbair[0]-resbair[1];
                        res[t+1] = resbair[0]+resbair[1];
                    }
                    t++; /// on passe la racine conjuguée qui suivait
                }
            }
            /*
            /// code de la fonction zroots de numerical recipes
            /// les erreurs deviennent importantes avec des racines multiples.
            int j,jj;
            C x,b,c;
            Vec<C> ad;
            bool rootFound;

            ad.resize(taille);
            res.resize(taille-1);
            for (j=0;j<taille;j++) 
                ad[j] = coefs[j];
            for (j=taille-1;j>=1;j--) {
                x=C(0.5,0.0);
                x = laguerre(ad,j,x,rootFound);
                if (abs(x.imag()) <= 2.0*2e-6*abs(x.real()))
                    x.imag() = 0.0;
                res[j-1]=x;
                //cout << " x = " << x << "  rootFound = " << rootFound << endl;
                b=ad[j];
                for (jj=j-1;jj>=0;jj--) {
                    c=ad[jj];
                    ad[jj]=b;
                    b = x*b+c;//b=Cadd(Cmul(x,b),c);
                }
            }
            for (j=0;j<taille;j++) 
                ad[j] = coefs[j];
            for (j=0;j<taille-1;j++)
                res[j] = laguerre(ad,taille-1,res[j],rootFound);
            */
        }
        return res;
    }

    Vec<T> real_roots() /**const*/{
        assert(nx==1);
        Vec<T> res;
        update_degrees(); /// PROVISOIRE : cela ne devrait pas être fait ici.
        int taille = degrees[0]+1;
        //cout << setprecision(16);
        //cout << " real roots :  taille = " << taille << "   degree = " << degree << "  coefs " << coefs << endl;
        if (taille == 0) {
            res.push_back(0);
        } else if (taille == 1) {
            /// pas de solution
        }else if (taille==2)
            res.push_back(-coefs[0]/coefs[1]);
        else if (taille==3) {
            T b=coefs[1]/coefs[2];
            T c=coefs[0]/coefs[2];
            T delta=b*b-4*c;
            if (std::abs(delta) < 16*std::numeric_limits<T>::epsilon())
                res.push_back(-0.5*b);
            else if (delta >= 16*std::numeric_limits<T>::epsilon()) {
                T rd = sqrt(delta);
                if (std::abs(b+rd)> 0.5)
                    res.push_back(-0.5*(b+rd));
                else
                    res.push_back(-2*c/(b-rd));
                if (std::abs(b-rd)> 0.5)
                    res.push_back(-0.5*(b-rd));
                else
                    res.push_back(-2*c/(b+rd));
            }
        }
        else if (taille==4) { /// degré 3
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
                C j(-0.5,sqrt(3.)/2.);
                C v(-13.5*q,sqrt(-6.75*delta));
                C u=std::pow(v,T(1)/T(3));
                res.push_back((2.*std::real(u)-a)/3.);
                res.push_back((2.*std::real(j*u)-a)/3.);
                res.push_back((2.*std::real(j*j*u)-a)/3.);
                sort(res);
            }
        }
        else if (taille ==5) { /// degré = 4
            Vec<C> solutions_complexes = roots();
            T racine;
            bool notFound;
            for( int i=0;i<solutions_complexes.size();++i)
                if ( is_real( solutions_complexes[i] ) ) {
                    racine = newton( solutions_complexes[i].real(), notFound );
                    //PRINT( notFound );
                    if (notFound)
                        res.push_back( solutions_complexes[i].real());
                    else
                        res.push_back( racine );
                }
            } else {
            //if (coefs[0]!=0) {
                Vec<C> solutions_complexes = roots();
                T racine;
                bool notFound;
                for( int i=0;i<solutions_complexes.size();++i)
                    if ( is_real( solutions_complexes[i] )) {
                        racine = newton( solutions_complexes[i].real(), notFound );
                        //PRINT( notFound );
                        if (notFound)
                            res.push_back( solutions_complexes[i].real());
                        else
                            res.push_back( racine );
                    }     
            /*if (abs(coefs[0]) > 16*numeric_limits<T>::epsilon()) {
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
                Vec<T> r=Pol<nd,nx,T>(aux).real_roots();
                while (r.size()>0 and r[0]<0) {
                    res.push_back(r[0]);
                    r.erase_elem_nb(0);
                }
                res.push_back(0);
                res.append(r);
                }*/
            }
        return res;
    }

//  private :

    Vec<T,DimPol<nd,nx>::valeur> coefs;
    Vec<int,nx> degrees;
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

template<class T,int static_size_>
int nb_changed_signe(Vec<T,static_size_>& v) {
    int ret = 0,i;
    T s1,s2;
    for(i=0;i<static_size_;++i)
        if (abs(v[i]) > 16*numeric_limits<T>::epsilon()) {
        s1 = v[i];
        break;
        }
        for(++i;i<static_size_;++i) {
            while ((abs(v[i]) < 16*numeric_limits<T>::epsilon()) and (i<static_size_))
                i++;   
            if (i<static_size_) {
                s2 = v[i];
                if (s1*s2<0)
                    ret++;
                s1 = s2;
            }
        }
        return ret;
        }

template<class T>
int nb_changed_signe(Vec<T,-1>& v) {
    int ret = 0,i;
    T s1,s2;
    for(i=0;i<v.size();++i)
        if (abs(v[i]) > 16*numeric_limits<T>::epsilon()) {
            s1 = v[i];
            break;
        }
    for(++i;i<v.size();++i) {
        while ((abs(v[i]) < 16*numeric_limits<T>::epsilon()) and (i<v.size()))
            i++;   
        if (i<v.size()) {
            s2 = v[i];
            if (s1*s2<0)
                ret++;
            s1 = s2;
        }
    }
    return ret;
}

/**
    Cette classe calcule les "polynômes de Sturm" de P. 
    Un appel à la méthode nb_roots_in_intervall(a,b) renvoie le nombres de racines réelles distinctes dans l'intervalle [a;b] (i.e. sans compter leur ordre de multiplicité).
    Un appel à la méthode polynom_of_multiple_roots() renvoie le polynôme dont les racines sont toutes les racines multiples de P. 

    Le nombre de racines n'est pas fiable pour des polynômes de degré >= 3
 */
template <int nd=4, class T=double>
struct Sturm {
    Sturm(const Pol<nd,1,T>& P) { init(P); }
    void init( const Pol<nd,1,T>& P) {
        Pol<nd,1,T> f0,f1,f2;
        //polys.free();
        if (not(P.is_zero()))
            polys.push_back(P);
        else
            return;
        f0 = P;
        f1 = P.derivative();
        Vec<int,1> deg = P.degrees();
        
        for(int i = deg[0]-2;i>=0;--i) {
            if (not(f1.is_zero())) {
                polys.push_back(f1);
                f2 = f0.remainder(f1);
                f0 = f1;
                f1 = -f2;     
            } else
                break;
        }
//         cout << " ##### suite des polys ##### " << endl;
//         for(int i =0;i<polys.size();++i)
//             cout << polys[i] << endl;
//         cout << " ########## " << endl;
    }
    int nb_roots_in_intervall(T a, T b) {
        Vec<T> fa,fb;
        
        for(int i=0;i<polys.size();++i)
            fa.push_back(polys[i](a));
        for(int i=0;i<polys.size();++i)
            fb.push_back(polys[i](b));
//         cout << " fa = " << fa << endl;
//         cout << " fb = " << fb << endl; 
        return nb_changed_signe(fa)-nb_changed_signe(fb);
    }
    Pol<nd,1,T> polynom_of_multiple_roots() { 
        if (polys.size())
            return polys.back();
        else
            return Pol<nd,1,T>();
    }
    
    
    Vec< Pol<nd,1,T> > polys;/// les polynômes sont rangés par degré décroissant.
};

}


#include "pol_unary.h"
#include "pol_binary.h"
#include "pol_input_output.h"

#endif // POLYNOMIALS_H
