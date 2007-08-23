//
// C++ Interface: heteroexplpack
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_heteroexplpack_HEADER
#define LMT_heteroexplpack_HEADER

namespace LMT {

template<
    class T0=void, class T1=void, class T2=void, class T3=void,
    class T4=void, class T5=void, class T6=void, class T7=void
> struct HeteroExplPack {
    template<unsigned n,unsigned inner=0> struct SubType { typedef void T; };
    template<unsigned inner> struct SubType<0,inner> { typedef T0 T; };
    template<unsigned inner> struct SubType<1,inner> { typedef T1 T; };
    template<unsigned inner> struct SubType<2,inner> { typedef T2 T; };
    template<unsigned inner> struct SubType<3,inner> { typedef T3 T; };
    template<unsigned inner> struct SubType<4,inner> { typedef T4 T; };
    template<unsigned inner> struct SubType<5,inner> { typedef T5 T; };
    template<unsigned inner> struct SubType<6,inner> { typedef T6 T; };
    template<unsigned inner> struct SubType<7,inner> { typedef T7 T; };
};

};

#endif // LMT_heteroexplpack_HEADER
