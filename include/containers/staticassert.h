//
// C++ Interface: staticassert
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_staticassert_HEADER
#define LMT_staticassert_HEADER

#include "number.h"

namespace LMT {

/// if you are here, it means that a static assert has thrown an error
template<unsigned n> struct OperationNotAllowed {};

template<> struct OperationNotAllowed<true> {
    void pouet() {}
};

#define STATICASSERT( cond ) { OperationNotAllowed<bool(cond)> IT_SEEMS_THAT_YOU_MADE_A_MISTAKE___please_look_in_your_source; \
    IT_SEEMS_THAT_YOU_MADE_A_MISTAKE___please_look_in_your_source.pouet(); }

// #define STATICASSERT(cond) DEBUGASSERT( cond )

#define STATICASSERTWC(cond,comm) STATICASSERT(cond)

}

#endif // LMT_staticassert_HEADER
