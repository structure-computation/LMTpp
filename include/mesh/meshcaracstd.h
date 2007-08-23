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
#ifndef LMTMESHCARACSTD_H
#define LMTMESHCARACSTD_H

#include "element.h"
#include "tetra.h"
#include "hexa.h"

namespace LMT {

template<int nb_var_inter,bool want_cubic=false> struct ElementChoiceMeshCaracStd { typedef void NE; };
template<> struct ElementChoiceMeshCaracStd<3,false> { typedef Tetra NE; };
template<> struct ElementChoiceMeshCaracStd<2,false> { typedef Triangle NE; };
template<> struct ElementChoiceMeshCaracStd<1,false> { typedef Bar NE; };
template<> struct ElementChoiceMeshCaracStd<0,false> { typedef NodalElement NE; };

template<> struct ElementChoiceMeshCaracStd<3,true> { typedef Hexa NE; };
template<> struct ElementChoiceMeshCaracStd<2,true> { typedef Quad NE; };
template<> struct ElementChoiceMeshCaracStd<1,true> { typedef Bar NE; };
template<> struct ElementChoiceMeshCaracStd<0,true> { typedef NodalElement NE; };

/// MeshCarac class (usable as Mesh<MeshCaracStd<...> > to instantiate a mesh) with
/// Tetras if nb_var_inter==3
/// Triangles if nb_var_inter==2
/// Bars if nb_var_inter==1
/// NodalElements if nb_var_inter==0
template<unsigned dim,unsigned nb_var_inter,bool want_cubic=false,class T=double>
struct MeshCaracStd : public MeshCarac<dim,T> {
    typedef MeshCarac<dim,T> MA;
    MESHCARACINHERITSFROM(MA);
    template<unsigned nvi_to_subs,unsigned skin,unsigned inner>
    struct ElementChoice<nvi_to_subs,skin,0,inner> {
        typedef typename ElementChoiceMeshCaracStd<nb_var_inter-(int)nvi_to_subs,want_cubic>::NE NE;
        typedef DefaultBehavior BE;
        typedef VoidDMSet TData;
    };
};


};

#endif
