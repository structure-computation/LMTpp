//
// C++ Interface: typereduction
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_typereduction_HEADER
#define LMT_typereduction_HEADER

namespace LMT {

/**
    TV is supposed to contain a struct SubType<n>::T and a static const unsigned nb_sub_type
*/
template<class Op,class TV,unsigned n=TV::nb_sub_type>
struct TypeReduction {
    typedef typename TypePromote<Op,
        typename TV::template SubType<n-1>::T,
        typename TypeReduction<Op,TV,n-1>::T
    >::T T;
};

template<class Op,class TV>
struct TypeReduction<Op,TV,1> {
    typedef typename TypePromote<Op,typename TV::template SubType<0>::T,typename TV::template SubType<0>::T>::T T;
};

template<class Op,class TV>
struct TypeReduction<Op,TV,0> {
    typedef void T;
};

};

#endif // LMT_typereduction_HEADER
