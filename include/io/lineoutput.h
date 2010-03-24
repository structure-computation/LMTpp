//
// C++ Interface: lineoutput
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_lineoutput_HEADER
#define LMT_lineoutput_HEADER

#include <iostream>
#include <complex>

namespace LMT {

/*!
\generic_comment line_output
    goal : display data on one line (to be redefined for matrices, ...)

    \relates line_input
    \keyword entrées sorties
*/
template<class T>
std::ostream &line_output( std::ostream &s, const T &v ) {
    s << v;
    return s;
}

/*!
\generic_comment line_input
    goal : get data from one line (to be redefined for matrices, ...)

    \relates line_output
    \keyword entrées sorties
*/
template<class T>
std::istream &line_input( std::istream &s, T &v ) {
    s >> v;
    return s;
}


/*!
    Cette fonction renvoie dans une ligne la partie réelle et la partie imaginaire de v séparés par un blanc.
    Voir le commentaire de \a line_input dans le cas des complexes pour connaître la différence avec <<.

    \relates line_input
*/
template<class T>
std::ostream &line_output( std::ostream &s, const std::complex<T> &v ) {
    s << v.real() << " " << v.imag();
    return s;
}

/*!
    Cette fonction extrait d'une ligne les deux premiers nombres et forme un nombre complexe mis dans v.
    <strong> Remarque importante : </strong> son comportement est différent de l'opérateur >> pour lequel les deux nombres doivent se présenter sous la forme (a,b).
    Voici quelques exemples illustratifs :
    \code C/C++
        td::istringstream iss0 ("(1,2)"); 
        std::complex<double> complex0; 
        iss0 >> complex0; 
        PRINT(complex0); // complex0 -> (1,2)

        std::istringstream iss1 ("(1,2)"); 
        std::complex<double> complex1; 
        line_input ( iss1 , complex1); 
        PRINT(complex1); // complex1 -> (0,0)  MAUVAISE UTILISATION

        std::istringstream iss2 ("1 2"); 
        std::complex<double> complex2; 
        line_input ( iss2 , complex2); 
        PRINT(complex2); // complex2 -> (1,2)

        std::istringstream iss3 ("1 2"); 
        std::complex<double> complex3; 
        iss3 >> complex3; 
        PRINT(complex3); // complex3 -> (1,0)   MAUVAISE UTILISATION

    \relates line_output
*/
template<class T>
std::istream &line_input( std::istream &s, std::complex<T> &v ) {
    T r,i;
    s >> r >> i;
    v = std::complex<T>(r,i);
    return s;
}


};

#endif // LMT_lineoutput_HEADER
