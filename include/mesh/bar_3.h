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
#ifndef LMTBAR3_H
#define LMTBAR3_H

#include "../containers/staticassert.h"
#include "nodalelement.h"

namespace LMT {

// --------------------------------------------------------------------------------------------------------
/*!
    Bar_3 représente une barre sans dimension ou segment avec trois noeuds dessus.  
    \verbatim
    .                    0--2--1
    \relates Mesh
    \relates Element
    \keyword Maillage/Elément
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \keyword Maillage/Elément
*/

struct Bar_3 {
    static const unsigned nb_var_inter = 1;
    static const unsigned nb_nodes = 3;
    static const char *name() { return "Bar_3"; }
    static const char *can_directly_be_represented_by() { return "Bar_3"; }
};

// --------------------------------------------------------------------------------------------------------
template<> struct NbChildrenElement<Bar_3,1> { static const unsigned res = 2; };

template<unsigned n> struct TypeChildrenElement<Bar_3,1,n> { typedef NodalElement T; };

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Bar_3,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<1> nvi_to_subs) {
    het.add_element(e,ch,NodalElement(),e.node(0));
    het.add_element(e,ch,NodalElement(),e.node(1));
//     het.add_element(e,ch,NodalElement(),e.node(2));
}
//template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
//void append_skin_elements(Element<Bar_3,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<1> nvi_to_subs) {}

// --------------------------------------------------------------------------------------------------------

template<class TN,class TNG,class TD,unsigned NET>
typename TNG::Pvec sample_normal(const Element<Bar_3,TN,TNG,TD,NET> &e) {
    DEBUGASSERT( (TNG::dim==2) );
    typename TNG::Pvec res;
    res.assign_and_complete_with_last( e.pos(1)[1]-e.pos(0)[1], e.pos(0)[0]-e.pos(1)[0] );
    res /= length(res);
    return res;
}


/* TODO : exact computation */
template<class TN,class TNG,class TD,unsigned NET>
typename TypePromote<Abs,typename TNG::T>::T measure( const Element<Bar_3,TN,TNG,TD,NET> &e ) {
    return abs( length( e.node(1)->pos - e.node(0)->pos ) );
}

inline unsigned vtk_num( StructForType<Bar_3> ) { return 21; }

};

#include "element_Bar_3.h"

#endif // LMTBAR3_H
