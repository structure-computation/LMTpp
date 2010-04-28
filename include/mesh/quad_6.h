//
// C++ Interface: node
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMTQUAD_6_H
#define LMTQUAD_6_H

#include "containers/basicops.h"
#include "bar.h"
#include "bar_3.h"

namespace LMT {

// --------------------------------------------------------------------------------------------------------
/*!
    A faire

    \keyword Maillage/Elément
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/
struct Quad_6 {
    static const unsigned nb_var_inter = 2;
    static const unsigned nb_nodes = 6;
    static const char *name() { return "Quad_6"; }
    static const char *can_directly_be_represented_by() { return "Quad"; }
};

// --------------------------------------------------------------------------------------------------------
template<> struct NbChildrenElement<Quad_6,1> { static const unsigned res = 4; };
template<> struct NbChildrenElement<Quad_6,2> { static const unsigned res = 6; };

template<> struct TypeChildrenElement<Quad_6,1,0> { typedef Bar_3 T; };
template<> struct TypeChildrenElement<Quad_6,1,1> { typedef Bar_3 T; };
template<> struct TypeChildrenElement<Quad_6,1,2> { typedef Bar T; };
template<> struct TypeChildrenElement<Quad_6,1,3> { typedef Bar T; };
template<unsigned n> struct TypeChildrenElement<Quad_6,2,n> { typedef NodalElement T; };

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Quad_6,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<1> nvi_to_subs) {
    het.add_element(e,ch,Bar_3(),e.node(0),e.node(4),e.node(1));
    het.add_element(e,ch,Bar_3(),e.node(2),e.node(5),e.node(3));
    het.add_element(e,ch,Bar(),e.node(1),e.node(2));
    het.add_element(e,ch,Bar(),e.node(3),e.node(0));
}
template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Quad_6,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<2> nvi_to_subs) {
    het.add_element(e,ch,NodalElement(),e.node(0));
    het.add_element(e,ch,NodalElement(),e.node(1));
    het.add_element(e,ch,NodalElement(),e.node(2));
    het.add_element(e,ch,NodalElement(),e.node(3));
    het.add_element(e,ch,NodalElement(),e.node(4));
    het.add_element(e,ch,NodalElement(),e.node(5));
}

template<class TN,class TNG,class TD,unsigned NET>
typename TNG::T measure( const Element<Quad_6,TN,TNG,TD,NET> &e ) {
    std::cerr << "measure pour Quad_6 n'est pas implémentée" << std::endl;
    assert(0);
    return (typename TNG::T) -1;
}

template<class TV,class T>
bool var_inter_is_inside( const Quad_6 &, const TV &var_inter, T tol = 0 ) {
    return heaviside( var_inter[0] + tol ) * heaviside( var_inter[1] + tol ) * heaviside( 1 - var_inter[0] + tol ) * heaviside( 1 - var_inter[1] + tol );
}

/// >= 0 -> inside, < 0 -> outside
template<class T,class TV>
T var_inter_insideness( const Quad_6 &e, const TV &var_inter ) {
    return min( min( min( var_inter[0], var_inter[1] ), 1 - var_inter[0] ), 1 - var_inter[1] );
}

};

#include "element_Quad_6.h"

#endif // LMTQUAD_6_H
