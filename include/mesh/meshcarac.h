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

template<class T,unsigned dim>
struct NodalStaticDataStd {
    typedef Vec<T,dim> Pvec;
    CARACDMEXTNAME(0,Pvec,pos,"mm");
};

namespace LMT_DOCUMENTATION {

/*!
    Ce type qui est défini dans un type \a MeshCarac précise les éléments possibles du maillage ainsi que ses sous-mailllage et maillage peau.
    Le premier argument <strong> nvi_to_subs </strong> est la valeur qu'on doit retrancher à la dimension du maillage pour tomber sur la dimension de l'élément ElementChoice::NE (NE signifie Nom Element, i.e. Quad, Bar,...). Par exemple, si le maillage est un maillage de l'espace et si ElementChoice::NE est de type \a Triangle_6 alors nvi_to_subs vaudra 1.
    Le second argument <strong> skin </strong> précise si l'élément est un élément de peau (skin=1) ou non (skin=0).
    Le troisième argument <strong> num_sub_element </strong> est le numéro de l'élément par les éléments de même dimension. Par exemple si on a deux éléments possibles pour un maillage 2D, \a Quad et \a Quad_9 , on aura :
    \code 
        ...
        ...
        template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,0,inner> {
            typedef Quad NE;
            typedef DefaultBehavior BE;
            typedef TCDM0 TData;
        };
        template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,1,inner> {
            typedef Triangle NE;
            typedef DefaultBehavior BE;
            typedef TCDM0 TData;
        };
        ...
        ...
    Le dernier argument sert d'identifiant pour les différents sous-maillages.

    Pour exemple, on peut consulter [[include/mesh/exemple_meshcarac.tar.gz|cet exemple]] , ou  voir le code de \a MeshCaracStd , \a MeshCarac .

    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/
template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0>
struct ElementChoice {
    typedef void NE;
    typedef DefaultBehavior BE;
    typedef VoidDMSet TData;
};
};

/*! 

    Modèle de classe qui sert de paramètre à la classe \a Mesh . On peut aussi consulter  \a MeshCaracStd pour un exemple exploitable de ce modèle et aussi tous les exemples dans le dossier formulation. 

    Example of data that can be contained in a child
    \code C/C++
        typedef double Tpos;
        static const unsigned dim = 3;
        template<unsigned nvi_to_subs,unsigned skin,unsigned inner> struct ElementChoice<0,false,0,inner> {
            typedef Triangle NE;
            typedef DefaultBehavior BE;
        };
        ...

    Il y a aussi un autre exemple de MeshCarac dans [[include/mesh/exemple_meshcarac.tar.gz|cet exemple]] .

    \relates Mesh
    \relates MeshCaracStd
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
    typedef NodalStaticDataStd<T,dim> NodalStaticData;
    ///
    typedef VoidDMSet GlobalStaticData;
};

#define MESHCARACINHERITSFROM(PARENT) \
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0> struct ElementChoice : \
            public PARENT::template ElementChoice<nvi_to_subs,skin,num_sub_element,inner> {};
    
};

#endif
