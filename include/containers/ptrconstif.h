//
// C++ Interface: ptrconstif
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_ptrconstif_HEADER
#define LMT_ptrconstif_HEADER

namespace LMT {

template<class T,bool want_const>
struct PtrConstIf;

template<class TT>
struct PtrConstIf<TT,true> {
    typedef const TT *T;
    inline const TT &operator[](unsigned i) const { return val[i]; } /// access to element i
    const TT *val;
};

template<class TT>
struct PtrConstIf<TT,false> {
    typedef TT* T;
    inline TT &operator[](unsigned i) { return val[i]; } /// access to element i
    inline const TT &operator[](unsigned i) const { return val[i]; } /// access to element i
    TT *val;
};


}

#endif // LMT_ptrconstif_HEADER
