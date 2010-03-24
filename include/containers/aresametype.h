//
// C++ Interface: aresametype
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_aresametype_HEADER
#define LMT_aresametype_HEADER

namespace LMT {

template<class T1,class T2>
struct AreSameType {
    static const bool res = false;
};

template<class T>
struct AreSameType<T,T> {
    static const bool res = true;
};

};

#endif // LMT_aresametype_HEADER
