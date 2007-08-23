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
#ifndef LMTQUAD_42_H
#define LMTQUAD_42_H

#include "containers/basicops.h"
#include "bar.h"
#include "bar_4.h"

namespace LMT {

/*
#
#  3 .. 7 .. 6 .. 2
#  .              .
#  0 .. 4 .. 5 .. 1
#
*/

// --------------------------------------------------------------------------------------------------------
struct Quad_42 {
    static const unsigned nb_var_inter = 2;
    static const unsigned nb_nodes = 8;
    static const char *name() { return "Quad_42"; }
    static const char *can_directly_be_represented_by() { return "Quad"; }
};

// --------------------------------------------------------------------------------------------------------
template<> struct NbChildrenElement<Quad_42,1> { static const unsigned res = 4; };
template<> struct NbChildrenElement<Quad_42,2> { static const unsigned res = 8; };

template<> struct TypeChildrenElement<Quad_42,1,0> { typedef Bar_4 T; };
template<> struct TypeChildrenElement<Quad_42,1,1> { typedef Bar_4 T; };
template<> struct TypeChildrenElement<Quad_42,1,2> { typedef Bar T; };
template<> struct TypeChildrenElement<Quad_42,1,3> { typedef Bar T; };
template<unsigned n> struct TypeChildrenElement<Quad_42,2,n> { typedef NodalElement T; };

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Quad_42,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<1> nvi_to_subs) {
    het.add_element(e,ch,Bar_4(),e.node(0),e.node(4),e.node(5),e.node(1));
    het.add_element(e,ch,Bar_4(),e.node(2),e.node(6),e.node(7),e.node(3));
    het.add_element(e,ch,Bar(),e.node(1),e.node(2));
    het.add_element(e,ch,Bar(),e.node(3),e.node(0));
}
template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Quad_42,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<2> nvi_to_subs) {
    het.add_element(e,ch,NodalElement(),e.node(0));
    het.add_element(e,ch,NodalElement(),e.node(1));
    het.add_element(e,ch,NodalElement(),e.node(2));
    het.add_element(e,ch,NodalElement(),e.node(3));
    het.add_element(e,ch,NodalElement(),e.node(4));
    het.add_element(e,ch,NodalElement(),e.node(5));
    het.add_element(e,ch,NodalElement(),e.node(6));
    het.add_element(e,ch,NodalElement(),e.node(7));
}

};

#include "element_Quad_42.h"

#endif // LMTQUAD_42_H
