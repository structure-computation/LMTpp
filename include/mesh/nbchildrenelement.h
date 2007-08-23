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
#ifndef LMT_NBCHILDRENELEMENT_HEADER
#define LMT_NBCHILDRENELEMENT_HEADER

namespace LMT {

/// to be redefined for each element names (Bar, Triangle, ...)
template<class NE,unsigned nvi_to_subs>
struct NbChildrenElement {
    static const unsigned res = 0;
};

/// to be redefined for each element names (Bar, Triangle, ...)
template<class NE,unsigned nvi_to_subs,unsigned num_child>
struct TypeChildrenElement {
    typedef void T;
};




};

#endif // LMT_NBCHILDRENELEMENT_HEADER

