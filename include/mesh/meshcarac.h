//
// C++ Interface: meshcaracstd
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMTMESHCARAC_H
#define LMTMESHCARAC_H

#include "element.h"

namespace LMT {

///
struct DefaultBehavior {};

#ifndef IFNDEF_pos_DM
#define IFNDEF_pos_DM
    struct pos_DM {};
#endif // IFNDEF_pos_DM

/** Example of data that can be contained in a child
    typedef double Tpos;
    static const unsigned dim = 3;
    template<unsigned nvi_to_subs,unsigned skin,unsigned inner> struct ElementChoice<0,false,0,inner> {
        typedef Triangle NE;
        typedef DefaultBehavior BE;
    };
    ...
*/ 
template<unsigned d,class T>
struct MeshCarac {
    /// type used to store positions
    typedef T Tpos;
    /// nb dim of the space
    static const unsigned dim = d;
    /// used to define pos type
    typedef Vec<T,d> Pvec;
    /// inner is a workaround. NE can be Triangle, Tetra, ... end of elements<nvi_to_subs,skin> is marked by NE=void
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef void NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    ///
    //template<class NE,class BE,unsigned nvi_to_subs,unsigned skin,unsigned inner=0>
    //struct ElementaryStaticData {
    //    VOIDDMSET;
    //};
    ///
    struct NodalStaticData {
        CARACDMEXTNAME(0,Pvec,pos,"mm");
    };
    ///
    typedef VoidDMSet GlobalStaticData;
};

#define MESHCARACINHERITSFROM(PARENT) \
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0> struct ElementChoice : \
            public PARENT::template ElementChoice<nvi_to_subs,skin,num_sub_element,inner> {};
    
};

#endif
