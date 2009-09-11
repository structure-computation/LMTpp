#ifndef BOOLEAN_H
#define BOOLEAN_H

namespace LMT {

template<class T> inline bool boolean_(const T &val) { return bool(val); }
template<class T> inline bool boolean_(const std::complex<T> &val) { return bool(real(val)) or bool(imag(val)); }

}

#endif
