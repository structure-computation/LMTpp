
#ifndef LMTPentaPrism_H
#define LMTPentaPrism_H

#include "quad.h"
#include "penta.h"

namespace LMT {

//     9 ---------8
//    /|         /|
//   / |        / |
//  /  |       /  |
// 5---|6-----7   |
// |   |      |   |
// |   4------|-- 3
// |  /       |  /
// | /        | /
// |/         |/
// 0----1---- 2

// --------------------------------------------------------------------------------------------------------
struct PentaPrism {
    static const unsigned nb_var_inter = 3;
    static const unsigned nb_nodes = 10;
    static const char *name() { return "PentaPrism"; }
    static const char *can_directly_be_represented_by() { return "PentaPrism"; }
};

// --------------------------------------------------------------------------------------------------------
template<> struct NbChildrenElement<PentaPrism,0> { static const unsigned res = 1; };
template<> struct NbChildrenElement<PentaPrism,1> { static const unsigned res = 7; };
template<> struct NbChildrenElement<PentaPrism,2> { static const unsigned res = 15; };
template<> struct NbChildrenElement<PentaPrism,3> { static const unsigned res = 10; };

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<PentaPrism,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<1> nvi_to_subs) {
    het.add_element(e,ch,Penta(),e.node(0),e.node(1),e.node(2),e.node(3),e.node(4));
    het.add_element(e,ch,Penta(),e.node(5),e.node(6),e.node(7),e.node(8),e.node(9));
    het.add_element(e,ch,Quad(),e.node(0),e.node(1),e.node(6),e.node(5));
    het.add_element(e,ch,Quad(),e.node(1),e.node(2),e.node(7),e.node(6));
    het.add_element(e,ch,Quad(),e.node(2),e.node(3),e.node(8),e.node(7));
    het.add_element(e,ch,Quad(),e.node(3),e.node(4),e.node(9),e.node(8));
    het.add_element(e,ch,Quad(),e.node(4),e.node(0),e.node(5),e.node(9));
}

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<PentaPrism,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<2> nvi_to_subs) {
    het.add_element(e,ch,Bar(),e.node(0),e.node(1));
    het.add_element(e,ch,Bar(),e.node(1),e.node(2));
    het.add_element(e,ch,Bar(),e.node(2),e.node(3));
    het.add_element(e,ch,Bar(),e.node(3),e.node(4));
    het.add_element(e,ch,Bar(),e.node(4),e.node(0));
    het.add_element(e,ch,Bar(),e.node(5),e.node(6));
    het.add_element(e,ch,Bar(),e.node(6),e.node(7));
    het.add_element(e,ch,Bar(),e.node(7),e.node(8));    
    het.add_element(e,ch,Bar(),e.node(8),e.node(9));       
    het.add_element(e,ch,Bar(),e.node(9),e.node(5));       
    het.add_element(e,ch,Bar(),e.node(0),e.node(5));
    het.add_element(e,ch,Bar(),e.node(1),e.node(6));
    het.add_element(e,ch,Bar(),e.node(2),e.node(7));
    het.add_element(e,ch,Bar(),e.node(3),e.node(8));
    het.add_element(e,ch,Bar(),e.node(4),e.node(9));
}
template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<PentaPrism,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<3> nvi_to_subs) {
    het.add_element(e,ch,NodalElement(),e.node(0));
    het.add_element(e,ch,NodalElement(),e.node(1));
    het.add_element(e,ch,NodalElement(),e.node(2));
    het.add_element(e,ch,NodalElement(),e.node(3));
    het.add_element(e,ch,NodalElement(),e.node(4));
    het.add_element(e,ch,NodalElement(),e.node(5));
    het.add_element(e,ch,NodalElement(),e.node(6));
    het.add_element(e,ch,NodalElement(),e.node(7));
    het.add_element(e,ch,NodalElement(),e.node(8));
    het.add_element(e,ch,NodalElement(),e.node(9));
}


template<class TN,class TNG,class TD,unsigned NET,class TM>
bool divide_element_using_elem_children(Element<PentaPrism,TN,TNG,TD,NET> &e,TM &m,TNG **nnodes) {
std::cout << "Surdiscretisation non implementee pour les PentaPrism" << std::endl;
return false;
};

template<class TN,class TNG,class TD,unsigned NET>
typename TNG::T measure( const Element<PentaPrism,TN,TNG,TD,NET> &e ) {
    typedef typename TNG::T P_T_pos;
    typename TNG::Pvec P0 = e.node(0)->pos, P1 = e.node(1)->pos, P2 = e.node(2)->pos, P3 = e.node(3)->pos;
    P_T_pos D0=0.12;
   cout << " measureNon impl�ment� pour le pentaprism"<< endl;assert(0);
 return D0;
}

};

//#include "element_PentaPrism.h"

#endif //LMTPentaPrism_H