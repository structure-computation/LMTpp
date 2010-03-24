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
#ifndef LMT_STATICVALIF_HEADER
#define LMT_STATICVALIF_HEADER

#include "basicops.h"

namespace LMT {

/** contain static const unsigned val = static_val if want_static_val==true. Contain unsigned val else. */
template<class T,bool want_static_val,int static_val> struct StaticValIf;

/** contain static const unsigned val = static_val if want_static_val==true. Contain unsigned val else. */
template<class T,int static_val>
struct StaticValIf<T,true,static_val> {
    void set(T v) { DEBUGASSERT(static_val==v); }
    void throw_val_and_clear( StaticValIf &res ) {}
    static const int val = static_val;
};

template<class T,int static_val>
struct StaticValIf<T,false,static_val> {
    void set(T v) { val = v; }
    StaticValIf():val(0) {}
    void throw_val_and_clear( StaticValIf &res ) { res.val = val; val = 0; }
    T val;
};


}

#endif // LMT_STATICVALIFTP_HEADER

