//
// C++ Interface: typeifnotvoid
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_typeifnotvoid_HEADER
#define LMT_typeifnotvoid_HEADER

namespace LMT {

template<class T1,class T2>
struct TypeIfNotVoid { typedef T1 T; };

template<class T1>
struct TypeIfNotVoid<T1,void> { typedef void T; };

};

#endif // LMT_typeifnotvoid_HEADER
