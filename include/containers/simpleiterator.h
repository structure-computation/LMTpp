//
// C++ Interface: simpleiterator
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_simpleiterator_HEADER
#define LMT_simpleiterator_HEADER

namespace LMT {

template<class T> class SimpleConstIterator;

template<class T>
class SimpleIterator {
public:
    SimpleIterator(T *b_,T *e_):b(b_),e(e_) {}
    void operator++() { ++b; }
    void operator--() { --b; }
    operator bool() const { return b!=e; }
    T &operator*() { return *b; }
    const T &operator*() const { return *b; }
    T *begin() { return b; }
    T *end() { return e; }
    const T *begin() const { return b; }
    const T *end() const { return e; }
    unsigned size() const { return e-b; }
private:
    T *b;
    T *e;
    template<class T2> friend class SimpleConstIterator;
};

/**
   for( SimpleConstIterator<...> iter = ...; iter; iter++ ) {
      ... *iter
   }
*/
template<class T>
class SimpleConstIterator {
public:
    SimpleConstIterator(const T *b_,const T *e_):b(b_),e(e_) {}
    template<class T2> SimpleConstIterator(const SimpleConstIterator<T2> &si) { b = si.b; e = si.e; }
    template<class T2> SimpleConstIterator(const SimpleIterator<T2> &si) { b = si.b; e = si.e; }
    void operator++() { ++b; }
    void operator--() { --b; }
    operator bool() const { return b!=e; }
    const T &operator*() const { return *b; }
    const T *begin() const { return b; }
    const T *end() const { return e; }
    unsigned size() const { return e-b; }
    
    const T &operator[](unsigned i) const { return b[i]; }
private:
    const T *b;
    const T *e;
    template<class T2> friend class SimpleConstIterator;
};

};

#endif // LMT_simpleiterator_HEADER
