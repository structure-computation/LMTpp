//
// C++ Interface: %{MODULE}
//
// Description: 
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_BASICOPS_HEADER
#define LMT_BASICOPS_HEADER

#include "typepromote.h"
#include <cmath>
#include <assert.h>
#include <iostream>

namespace LMT {

#ifdef DEBUG
    #ifdef MATLAB_MEX_FILE
        #define DEBUGASSERT(cond) if ( cond==false ) { printf( "Error : %s is not verified ( in file %s, line %i )\n", __STRING(cond), __FILE__, __LINE__ ); throw __STRING(cond); }
    #else
        #define DEBUGASSERT(cond) assert(cond)
    #endif
#else
    #define DEBUGASSERT(cond) 
#endif
#define DEBUGASSERTWC(cond,comm) DEBUGASSERT(cond)

#define PRINT( A ) \
    std::cout << "  " << __STRING(A) << std::flush << " -> " << (A) << std::endl
#define PRINTN( A ) \
    std::cout << "  " << __STRING(A) << std::flush << " ->\n" << (A) << std::endl
#define PRINTUCSTR( A ) { \
    std::ostringstream os; \
    os << "  " << __STRING(A) << std::flush << " -> " << (A); \
    printf("%s\n",os.str().c_str()); \
}
#define PRINTTYPE( A ) \
    std::cout << "  " << __STRING(A) << " -> " << (A).name() << std::endl;
//     system( ("c++filt "+std::string( (A).name() )).c_str() )

class Min;
class Max;
class Divides;

/*!
\generic_comment min

    Fonction clasique à deux ou trois paramètres.
    \keyword Mathématiques/Fonctions classiques
*/
/// min
template<class T1,class T2> typename TypePromote<Min,T1,T2>::T min(T1 a,T2 b) {
    typedef typename TypePromote<Min,T1,T2>::T T;
    return ( a<b ? static_cast<T>(a): static_cast<T>(b) );
}

/*!
\generic_comment max

    Fonction clasique à deux ou trois paramètres.
    \keyword Mathématiques/Fonctions classiques
*/
/// max
template<class T1,class T2> typename TypePromote<Max,T1,T2>::T max(T1 a,T2 b) {
    typedef typename TypePromote<Max,T1,T2>::T T;
    return ( a>b ? static_cast<T>(a): static_cast<T>(b) );
}

#define MIN(x,y) ( (x)<(y) ? (x) : (y) )
#define MAX(x,y) ( (x)>(y) ? (x) : (y) )
#define ABS(x) ( (x)>=0 ? (x) : (-(x)) )
#define SGNPLUS1(x) ( (x)>=0 + (x)>0 )

/// min ternaire
template<class T1,class T2,class T3> typename TypePromote<Min,T1,typename TypePromote<Min,T2,T3>::T>::T min(T1 a,T2 b,T3 c) {
    return min( a, min(b,c) );
}
/*! 
    maximum ternaire
    
*/
template<class T1,class T2,class T3> typename TypePromote<Max,T1,typename TypePromote<Max,T2,T3>::T>::T max(T1 a,T2 b,T3 c) {
    return max( a, max(b,c) );
}

/*! 
    fonction puissance
    
*/
template<class T1,class T2>
typename TypePromote<Pow,T1,T2>::T pow( const T1 &a, const T2 &b ) {
    return std::pow( a, b );
}

/*!
\generic_comment ceil
    
    Excepté la fonction à deux paramètres, la fonction ceil de la LMT++ correspond à celle de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques
*/
/// identité.
inline int ceil(int a) { return a; }
/// identité.
inline unsigned ceil(unsigned a) { return a; }
/// fonction ceil de la std.
template<class T> T ceil(T a) { return std::ceil(a); }

/*! 
Dans le cas où a et m sont positifs, la fonction renvoie a si a est un multiple de m sinon elle renvoie le plus petit multiple de m supérieur à a.
*/
inline int ceil( int a, int m ) { return ( ( a + m - 1 ) / m ) * m; }
/*!
Dans le cas où a et m sont positifs, la fonction renvoie le plus grand multiple de m inférieur ou égal à a.
\keyword Mathématiques/Fonctions classiques 
*/
inline int floor( int a, int m ) { return a - a % m; }

/*!
\generic_comment heavyside

    C'est la fonction de Heavyside qui renvoie un si son argument est supérieur ou égal à zéro et zéro sinon.
    \keyword Mathématiques/Fonctions classiques 
*/
/// 1 if equal 0
template<class T> bool heavyside(const T &val) { return (val>=0); }
/*!
     1 if equal 0
    \keyword Mathématiques/Fonctions classiques
*/
template<class T> bool heaviside(const T &val) { return (val>=0); }
/*! 
    true if equal 0
    \keyword Mathématiques/Fonctions classiques
*/
template<class T> bool eqz(const T &val) { return heavyside(val)*heavyside(-val); }
/*! 
    renvoie 1 si val > 0 et -1 sinon
    \keyword Mathématiques/Fonctions classiques
*/
template<class T> int sgn(const T &val) { return ( val>0 ? 1 : -1 ); }

/*!
\generic_comment length

    La syntaxe de cette fonction est :
    \code
        length( nombre )
        length( vecteur )
        length( vecteur, nombre )

    * La première synatxe calcule la valeur absolue du nombre.
    * La deuxième calcule la norme L2
    * la dernière calcule sqrt( norme du vecteur + nombre )
    
    \relates abs_indication
    \keyword Mathématiques/Fonctions classiques 
    \keyword Algorithme/Extraire
*/
/// retourne abs(val)
template<class T> T length(const T &val) { return abs(val); }

/*
lst = [
    'conj',
    'abs',
    'acos',
    'asin',
    'atan',
    'cos',
    'cosh',
    'exp',
    'log',
    'log10',
    'sin',
    'sinh',
    'sqrt',
    'tan',
    'tanh',
]
for op in lst:
    print 'template<class T> T '+op+'(const T &val) { return std::'+op+'(val); }'
*/
#ifndef WITHOUTCOMPLEX
    //     template<class T> inline std::complex<T> conj(const std::complex<T> &val) { return std::conj(val); }
    inline std::complex<double> conj(const std::complex<double> &val) { return std::conj(val); }
    inline std::complex<long double> conj(const std::complex<long double> &val) { return std::conj(val); }
    
    
    //     template<class T> inline T real(const std::complex<T> &val) { return std::real(val); }
    inline double real(const std::complex<double> &val) { return std::real(val); }
    inline long double real(const std::complex<long double> &val) { return std::real(val); }
    
    //     template<class T> inline T imag(const std::complex<T> &val) { return std::imag(val); }
    inline double imag(const std::complex<double> &val) { return std::imag(val); }
    inline long double imag(const std::complex<long double> &val) { return std::imag(val); }
    
    inline double abs(const std::complex<double> &val) { return std::abs(val); }
    inline long double abs(const std::complex<long double> &val) { return std::abs(val); }

/*!
\generic_comment abs_indication

    Cette fonction retourne la "distance" entre l'objet et zéro.

    \relates abs
    \relates abs_indication
*/

/// abs
    inline double abs_indication(const std::complex<double> &val) { return LMT::abs(val); }
    inline long double abs_indication(const std::complex<long double> &val) { return LMT::abs(val); } /// abs
    
    template<class T> inline T conj(const T &val) { return val; } /// renvoie le paramètre
    template<class T> inline T real(const T &val) { return val; } /// renvoie le paramètre
    template<class T> inline T imag(const T &val) { return 0; } /// renvoie toujours zéro
    
    template<class T,class T2> inline void set_imag(std::complex<T> &val,const T2 &v) { val = std::complex<T>(std::real(val),v); }
    template<class T,class T2> inline void set_imag(const T &val,const T2 &v) {}
    
#endif
struct Abs;
/*!
    \keyword Mathématiques/Fonctions classiques 

    \relates abs_indication
    \relates length
*/
template<class T> inline typename TypePromote<Abs,T>::T abs(const T &val) { return typename TypePromote<Abs,T>::T(std::abs(val)); }
template<class T> inline typename TypePromote<Abs,T>::T abs_indication(const T &val) { return LMT::abs(val); } // if val is a function, return abs( something_close_to_mean(val) )
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
    \relates asin
    \relates atan
*/
template<class T> inline typename FloatType<T>::T acos(const T &val) { return std::acos(val); }
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
    \relates acos
    \relates atan
*/
template<class T> inline typename FloatType<T>::T asin(const T &val) { return std::asin(val); }
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
    \relates asin 
    \relates acos
*/
template<class T> inline typename FloatType<T>::T atan(const T &val) { return std::atan(val); }
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T cos(const T &val) { return std::cos(val); }
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T cosh(const T &val) { return std::cosh(val); } /// cosinus hyperbolique
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T exp(const T &val) { return std::exp(val); }
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T log(const T &val) { return std::log(val); }
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T log10(const T &val) { return std::log10(val); }
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T sin(const T &val) { return std::sin(val); }
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T sinh(const T &val) { return std::sinh(val); }
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T sqrt(const T &val) { return std::sqrt(val); }
/*!
    c'est la fonction x -> 1/sqrt(x) ou x -> x^(-0.5)
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T rsqrt(const T &val) { return pow(val,-0.5); }
/*!
    C'est la fonction de la librairie standard du C.
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T tan(const T &val) { return std::tan(val); }
/*!
    C'est la fonction de la librairie standard du C++.
    \keyword Mathématiques/Fonctions classiques 
*/
template<class T> inline typename FloatType<T>::T tanh(const T &val) { return std::tanh(val); }

// inline unsigned pow(unsigned x,unsigned y) { unsigned res = 1; while(y--) res *= x; return res; }

/*!
    La fonction résout l'équation Ax=b 
    \keyword Mathématiques/Fonctions classiques
*/
template<class T1,class T2> typename TypePromote< Divides, T2, T1>::T
 solve(const T1 &A,const T2 &b) { return b/A; }

/*!
    swap : permute les deux arguments
    \keyword Utilitaires
*/
template<class T1,class T2> void swap(T1 &v1,T2 &v2) {
    T2 tmp = v1;
    v1 = v2;
    v2 = tmp;
}

/*!
    Example : apply( vec, Display(), std::cout );
    Example : apply( vec, Display(), std::cout, ' ' );
    \keyword Algorithme/Affichage
    \relates Vec
    \relates apply
*/
struct Display {
    template<class T1,class OS=std::ostream,class SEP=void,class T4=void> struct ReturnType { typedef void T; };
    template<class T> void operator()(const T &t) const { std::cout << t << " "; }
    template<class T,class OS> void operator()(const T &t,OS &os) const { os << t << " "; }
    template<class T,class OS,class SEP> void operator()(const T &t,OS &os,const SEP &sep) const { os << t; os << sep; }
    
    template<class T> void operator()(const T &t0,const T &t1,const T &t2,const T &t3) const { std::cout << t3 << " " << t2 << " " << t1 << " " << t0 << " "; }
    template<class T,class OS> void operator()(const T &t0,const T &t1,const T &t2,const T &t3,OS &os) const { os << t3 << " " << t2 << " " << t1 << " " << t0 << " "; }
    template<class T,class OS,class SEP> void operator()(const T &t0,const T &t1,const T &t2,const T &t3,OS &os,const SEP &sep) const { os << t3 << sep << t2 << sep << t1 << sep << t0 << sep; }
};

/*!
    Example : vec.apply_nz( DisplayWithIndex(), std::cout );
    Example : vec.apply_nz( DisplayWithIndex(), std::cout, ' ' );
*/
struct DisplayWithIndex {
    template<class T1,class UNSI,class OS=std::ostream,class SEP=void> struct ReturnType { typedef void T; };
    template<class T> void operator()(const T &t,unsigned i) const { std::cout << '[' << i << ']' << t << " "; }
    template<class T,class OS> void operator()(const T &t,unsigned i,OS &os) const { os << '[' << i << ']' << t << " "; }
    template<class T,class OS,class SEP> void operator()(const T &t,unsigned i,OS &os,const SEP &sep) const { os << '[' << i << ']' << t << sep; }
};

/*!
    Example : vec.apply( GetFromStream(), std::cin );
*/
struct GetFromStream {
    template<class T1,class IS> struct ReturnType { typedef IS T; };
    template<class T,class IS> IS &operator()(T &t,IS &is) const {
        // std::cout << "GetFromStream" << std::endl;
        is >> t;
        return is;
    }
};

/*!

    \keyword Utilitaires
*/
struct DoNothing {
    template<class T1,class T2=void,class T3=void,class T4=void> struct ReturnType { typedef void T; };
    template<class T> void operator()(const T &t) const {}
    template<class T,class T2> void operator()(const T &t,const T2 &t2) const {}
    template<class T,class T2,class T3> void operator()(const T &t,const T2 &t2,const T3 &t3) const {}
    template<class T,class T2,class T3,class T4> void operator()(const T &t,const T2 &t2,const T3 &t3,const T4 &t4) const {}
};

// template<class T> std::string to_string(const T &val) {
//     std::ostringstream os;
//     os << val;
//     return os.str();
// }

//return 1 if all the vector component are equal to 1 otherwise 0
/*!
    L'argument de bool_vec() doit être un vecteur de types scalaires ou bouléens. Elle renvoie vrai si tous les éléments sont non nuls ou vrais et faux sinon.
    \keyword Utilitaires
    \keyword Algorithme/Extraire
*/
template<class TV> bool bool_vec(const TV &v){
   bool res=1;
   for(unsigned i=0;i<v.size();++i){
      if(v[i]==0){
         res=0;
         break;
      }
   }
   return res;
}


}

#endif // LMT_BASICOPS_HEADER

