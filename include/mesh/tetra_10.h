#ifndef LMTTETRA_10_H
#define LMTTETRA_10_H

#include "triangle_6.h"

namespace LMT {

/**

       3
      /|\
     / |9\
   7/  |  \8
   /  /2\  \
  / /6   5\ \
 0/--- 4----\1

*/

// --------------------------------------------------------------------------------------------------------
struct Tetra_10 {
    static const unsigned nb_var_inter = 3;
    static const unsigned nb_nodes = 10;
    static const char *name() { return "Tetra_10"; }
    static const char *can_directly_be_represented_by() { return "Tetra_10"; }
};

// --------------------------------------------------------------------------------------------------------
template<> struct NbChildrenElement<Tetra_10,1> { static const unsigned res = 4; };
template<> struct NbChildrenElement<Tetra_10,2> { static const unsigned res = 6; };
template<> struct NbChildrenElement<Tetra_10,3> { static const unsigned res = 10; };

template<unsigned n> struct TypeChildrenElement<Tetra_10,0,n> { typedef Tetra_10 T; };
template<unsigned n> struct TypeChildrenElement<Tetra_10,1,n> { typedef Triangle_6 T; };
template<unsigned n> struct TypeChildrenElement<Tetra_10,2,n> { typedef Bar_3 T; };
template<unsigned n> struct TypeChildrenElement<Tetra_10,3,n> { typedef NodalElement T; };

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Tetra_10,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<1> nvi_to_subs) {
    het.add_element(e,ch,Triangle_6(),e.node(0),e.node(1),e.node(2),e.node(4),e.node(5),e.node(6));
    het.add_element(e,ch,Triangle_6(),e.node(0),e.node(1),e.node(3),e.node(4),e.node(8),e.node(7));
    het.add_element(e,ch,Triangle_6(),e.node(0),e.node(3),e.node(2),e.node(7),e.node(9),e.node(6));
    het.add_element(e,ch,Triangle_6(),e.node(1),e.node(2),e.node(3),e.node(5),e.node(9),e.node(8));
}

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Tetra_10,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<2> nvi_to_subs) {
    het.add_element(e,ch,Bar_3(),e.node(0),e.node(4),e.node(1));
    het.add_element(e,ch,Bar_3(),e.node(1),e.node(5),e.node(2));
    het.add_element(e,ch,Bar_3(),e.node(2),e.node(6),e.node(0));
    het.add_element(e,ch,Bar_3(),e.node(0),e.node(7),e.node(3));
    het.add_element(e,ch,Bar_3(),e.node(1),e.node(8),e.node(3));
    het.add_element(e,ch,Bar_3(),e.node(2),e.node(9),e.node(3));
}

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Tetra_10,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<3> nvi_to_subs) {
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

// --------------------------------------------------------------------------------------------------------
template<class TN,class TNG,class TD,unsigned NET,class Pvec,class T>
void update_circum_center(const Element<Tetra_10,TN,TNG,TD,NET> &e,Pvec &C,T &R) {
    C = getCenterOfCircumSphere( e.node(0)->pos, e.node(1)->pos, e.node(2)->pos, e.node(3)->pos );
    R = length( e.node(0)->pos - C );
}


template<class TN,class TNG,class TD,unsigned NET,class TM>
bool divide_element(Element<Tetra_10,TN,TNG,TD,NET> &e,TM &m,TNG **nodes) {
 std::cout << "Divide elem non implemente pour les Tetra_10" <<std::endl; assert(0);
return false;
}

template<class TN,class TNG,class TD,unsigned NET,class TM>
bool divide_element_using_elem_children(Element<Tetra_10,TN,TNG,TD,NET> &e,TM &m,TNG **nnodes) {
    std::cout << "Divide elem non implemente pour les Tetra_10" <<std::endl; assert(0);
    return false;
}

/** new_nodes are independant nodes created to make a fine grid for integration. Used in TvrcFormulation
    \relates Tetra_10
    \todo actually, we divide element n times, with n = max(edge length) / max_dist. For flat elements, it's far from optimallity
*/
template<class TN,class TNG,class TD,unsigned NET,class T>
bool subdivision_element(const Element<Tetra_10,TN,TNG,TD,NET> &e,Vec<TNG> &new_nodes,T max_dist) {
    T max_l = max(
            max( length( e.node(0)->pos - e.node(1)->pos ), length( e.node(0)->pos - e.node(2)->pos ), length( e.node(0)->pos - e.node(3)->pos ) ),
            max( length( e.node(1)->pos - e.node(2)->pos ), length( e.node(1)->pos - e.node(3)->pos ) ),
            length( e.node(2)->pos - e.node(3)->pos )
    );
    if ( max_l <= max_dist )
        return false;
    unsigned n = (unsigned)(max_l / max_dist);
    for(unsigned i=0;i<n;++i) {
        for(unsigned j=0;j<=i;++j) {
            for(unsigned k=0;k<=j;++k) {
                TNG *nn = new_nodes.new_elem();
                T f1 = (i+1.0)/(n+1.0);
                T f2 = (j+1.0)/(n+1.0);
                T f3 = (k+1.0)/(n+1.0);
                T f4 = 1.0-f1-f2-f3;
                std::pair<T,const TNG *> pond_list[] = {
                    std::pair<T,const TNG *>( f1, e.node(0) ),
                    std::pair<T,const TNG *>( f2, e.node(1) ),
                    std::pair<T,const TNG *>( f3, e.node(2) ),
                    std::pair<T,const TNG *>( f4, e.node(3) )
                };
                DM::get_ponderation( pond_list, 4, *nn );
            }
        }
    }
    return true;
}

template<class TN,class TNG,class TD,unsigned NET>
typename TNG::T measure( const Element<Tetra_10,TN,TNG,TD,NET> &e ) {
    typedef typename TNG::T P_T_pos;
    typename TNG::Pvec P0 = e.node(0)->pos, P1 = e.node(1)->pos, P2 = e.node(2)->pos, P3 = e.node(3)->pos;
    P_T_pos D0 = P1[0]-P0[0]; P_T_pos D1 = P2[0]-P0[0]; P_T_pos D2 = P3[0]-P0[0]; P_T_pos D3 = P2[1]-P0[1]; 
    P_T_pos D4 = P3[1]-P0[1]; P_T_pos D5 = P1[1]-P0[1]; P_T_pos D6 = P2[2]-P0[2]; P_T_pos D7 = D4*D6; 
    P_T_pos D8 = P3[2]-P0[2]; P_T_pos D9 = D3*D8; D7 = D9-D7; D0 = D0*D7; D7 = D8*D5; D8 = P1[2]-P0[2]; 
    D4 = D4*D8; D4 = D7-D4; D1 = D1*D4; D0 = D0-D1; D1 = D6*D5; D3 = D3*D8; D1 = D1-D3; D1 = D1*D2; D0 = D0+D1; D1 = 0.075*D0; 
    D0 = 0.133333*D0; D0 = D1-D0; D0 = D0+D1; D0 = D0+D1; D0 = D0+D1; D0 = abs(D0); return D0; 
}

};

#include "element_Tetra_10.h"

#endif
