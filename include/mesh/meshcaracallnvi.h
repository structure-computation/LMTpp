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
#ifndef LMT_MESH_CARAC_ALL_NVI_HEADER
#define LMT_MESH_CARAC_ALL_NVI_HEADER

#include "meshcaracstd.h"

namespace LMT {

/**
MeshCarac with Tetras(>=3D), Triangles(>=2D), Bars(>=1D) and NodalElements

@author Hugo LECLERC
*/
template<unsigned d,class T=double>
struct MeshCaracAllNvi {
    typedef T Tpos;
    static const unsigned dim = d;
    typedef Vec<T,dim> Pvec;
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
    struct ElementChoice {
        typedef typename ElementChoiceMeshCaracStd<d-(int)nvi_to_subs-(int)num_sub_element>::NE NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
    //template<class NE,class BE,unsigned nvi_to_subs,unsigned skin,unsigned inner=0>
    //struct ElementaryStaticData { VOIDDMSET; };
    struct NodalStaticData {
        CARACDMEXTNAME(0,Pvec,pos,"mm");
    };
    typedef VoidDMSet GlobalStaticData;
};


};

#endif // LMT_MESH_CARAC_ALL_NVI_HEADER

