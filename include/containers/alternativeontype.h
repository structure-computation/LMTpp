//
// C++ Interface: alternativeontype
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_alternativeontype_HEADER
#define LMT_alternativeontype_HEADER

namespace LMT {

template<unsigned choice,class T0,class T1=void,class T2=void,class T3=void>
struct AlternativeOnType {
    typedef T0 T;
};

template<class T0,class T1,class T2,class T3>
struct AlternativeOnType<1,T0,T1,T2,T3> {
    typedef T1 T;
};

template<class T0,class T1,class T2,class T3>
struct AlternativeOnType<2,T0,T1,T2,T3> {
    typedef T2 T;
};

template<class T0,class T1,class T2,class T3>
struct AlternativeOnType<3,T0,T1,T2,T3> {
    typedef T3 T;
};

}

#endif // LMT_alternativeontype_HEADER
