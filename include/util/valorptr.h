//
// C++ Interface: valorptr
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_valorptr_HEADER
#define LMT_valorptr_HEADER

#include <assert.h>

namespace LMT {

template<class TN,unsigned use_ptr> struct ValOrPtr;

template<> struct ValOrPtr<void,0> { typedef void T; };
template<> struct ValOrPtr<void,1> { typedef void T; };
template<> struct ValOrPtr<void,2> { typedef void T; };
template<> struct ValOrPtr<void,3> { typedef void T; };

template<class TN> struct ValOrPtr<TN,0> {
     typedef TN T;
     static const unsigned ptr_level = 0;
     
     ValOrPtr &operator=( TN *v ) { assert(0); }
     
     TN *operator->() { return &val; }
     const TN *operator->() const { return &val; }
     
     TN *ptr() { return &val; }
     const TN *ptr() const { return &val; }
     
     TN &operator*() { return val; }
     const TN &operator*() const { return val; }
     
     T val;
};

template<class TN> struct ValOrPtr<TN,1> {
    typedef TN* T;
    static const unsigned ptr_level = 1;
    
    ValOrPtr( TN *v = NULL ):val(v) {}
    ValOrPtr &operator=( TN *v ) { val = v; return *this; }
     
    TN *operator->() { return val; }
    const TN *operator->() const { return val; }
     
    TN &operator*() { return *val; }
    const TN &operator*() const { return *val; }
     
    TN *ptr() { return val; }
    const TN *ptr() const { return val; }
    
    T val;
};

template<class TN> struct ValOrPtr<TN,2> {
     typedef TN** T;
};

template<class TN> struct ValOrPtr<TN,3> {
     typedef TN*** T;
};




};

#endif // LMT_valorptr_HEADER
