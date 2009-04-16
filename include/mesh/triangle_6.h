#ifndef LMTTRIANGLE6_H
#define LMTTRIANGLE6_H

#include "containers/staticassert.h"
#include "containers/basicops.h"
#include "bar_3.h"

namespace LMT {

/*!
    \verbatim
            2
            | \
            |  \
            5   4
            |    \
            |     \
            0__3___1


    \relates Mesh
    \keyword Maillage/Elément 
    \author Hugo LECLERC
    \friend rapahel.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/

// --------------------------------------------------------------------------------------------------------
struct Triangle_6 {
    static const unsigned nb_var_inter = 2;
    static const unsigned nb_nodes = 6;
    static const char *name() { return "Triangle_6"; }
    static const char *can_directly_be_represented_by() { return "Triangle_6"; }
};

// --------------------------------------------------------------------------------------------------------
template<> struct NbChildrenElement<Triangle_6,0> { static const unsigned res = 1; };
template<> struct NbChildrenElement<Triangle_6,1> { static const unsigned res = 3; };
template<> struct NbChildrenElement<Triangle_6,2> { static const unsigned res = 6; };

template<unsigned n> struct TypeChildrenElement<Triangle_6,0,n> { typedef Triangle_6 T; };
template<unsigned n> struct TypeChildrenElement<Triangle_6,1,n> { typedef Bar_3 T; };
template<unsigned n> struct TypeChildrenElement<Triangle_6,2,n> { typedef NodalElement T; };

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Triangle_6,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<0> nvi_to_subs) {
    het.add_element(e,ch,Triangle_6(),e.node(0),e.node(1),e.node(2),e.node(3),e.node(4),e.node(5));
}

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Triangle_6,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<1> nvi_to_subs) {
    het.add_element(e,ch,Bar_3(),e.node(0),e.node(1),e.node(3));
    het.add_element(e,ch,Bar_3(),e.node(1),e.node(2),e.node(4));
    het.add_element(e,ch,Bar_3(),e.node(2),e.node(0),e.node(5));
}
template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Triangle_6,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<2> nvi_to_subs) {
    het.add_element(e,ch,NodalElement(),e.node(0));
    het.add_element(e,ch,NodalElement(),e.node(1));
    het.add_element(e,ch,NodalElement(),e.node(2));
    het.add_element(e,ch,NodalElement(),e.node(3));
    het.add_element(e,ch,NodalElement(),e.node(4));
    het.add_element(e,ch,NodalElement(),e.node(5));
}

template<class TN,class TNG,class TD,unsigned NET,class TM>
bool divide_element(Element<Triangle_6,TN,TNG,TD,NET> &e,TM &m,TNG **nnodes) {
   std::cout << "divide_element not implemented for Triangle_6" << std::endl;
   assert(0);
   return false;
}

template<class TN,class TNG,class TD,unsigned NET,class TM>
bool divide_element_using_elem_children(Element<Triangle_6,TN,TNG,TD,NET> &e,TM &m,TNG **nnodes) {
    return divide_element(e,m,nnodes);
}

// --------------------------------------------------------------------------------------------------------
template<class TN,class TNG,class TD,unsigned NET>
typename TNG::Pvec sample_normal(const Element<Triangle_6,TN,TNG,TD,NET> &e) {
    DEBUGASSERT( (TNG::dim==3) );
    typename TNG::Pvec res = vect_prod( e.node(1)->pos-e.node(0)->pos, e.node(2)->pos-e.node(0)->pos );
    return res / length( res );
}
template<class TN,class TNG,class TD,unsigned NET>
typename TNG::T measure( const Element<Triangle_6,TN,TNG,TD,NET> &e ) {
    typename TNG::Pvec P0 = e.node(0)->pos, P1 = e.node(1)->pos, P2 = e.node(2)->pos, N = normalized(P1-P0);
    P2 -= dot(P2-P0,N)*N;
    return 0.5 * length( P1-P0 ) * length( P2-P0 );
}

/*!
    Cette fonction retourne l'isobarycentre des sommets du triangle.

    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/
template<class TN,class TNG,class TD,unsigned NET>
typename TNG::Pvec center(const Element<Triangle_6,TN,TNG,TD,NET> &e) {
    typename TNG::Pvec res = 0.0;
    for(unsigned i=0;i<3;++i)
        res += e.node(i)->pos;
    return res / 3;
}

template<class TV,class T>
bool var_inter_is_inside( const Triangle_6 &e, const TV &var_inter, T tol = 0 ) {
    return heaviside( var_inter[0] + tol ) * heaviside( var_inter[1] + tol ) * heaviside( 1 - var_inter[0] - var_inter[1] + tol );
}

};
#include "element_Triangle_6.h"

#endif
