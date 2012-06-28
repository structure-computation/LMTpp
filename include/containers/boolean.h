#ifndef BOOLEAN_LMTPP_H
#define BOOLEAN_LMTPP_H

#include <complex>

namespace LMT {

template<int nd, int nx, class T> class Pol;

template<class T> 
inline bool boolean_( const T &val ) { return bool( val ); }

template<class T> 
inline bool boolean_( const std::complex<T> &val ) { return boolean_( real( val ) ) or boolean_( imag( val ) ); }

template<int nd, int nx, class T> 
inline bool boolean_( const Pol<nd,nx,T> &val ) { return boolean_( abs_indication( val ) ) ; }

}

#endif   /// BOOLEAN_LMTPP_H

