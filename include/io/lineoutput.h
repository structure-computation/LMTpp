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

/// goal : display data on one line (to be redefined for matrices, ...)
template<class T>
std::ostream &line_output( std::ostream &s, const T &v ) {
    s << v;
    return s;
}

/// goal : get data from one line (to be redefined for matrices, ...)
template<class T>
std::istream &line_input( std::istream &s, T &v ) {
    s >> v;
    return s;
}


/// for complex
template<class T>
std::ostream &line_output( std::ostream &s, const std::complex<T> &v ) {
    s << v.real() << " " << v.imag();
    return s;
}
/// for complex
template<class T>
std::istream &line_input( std::istream &s, std::complex<T> &v ) {
    T r,i;
    s >> r >> i;
    v = std::complex<T>(r,i);
    return s;
}


};

#endif // LMT_lineoutput_HEADER
