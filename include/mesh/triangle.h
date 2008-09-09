#ifndef LMTTRIANGLE_H
#define LMTTRIANGLE_H

#include "containers/staticassert.h"
#include "containers/basicops.h"
#include "bar.h"

namespace LMT {

/*!
    \verbatim
                            2
                            |\
                            | \
                            |  \
                            |   \
                            0----1

    \relates Mesh
    \keyword Maillage/Elément 
    \author Hugo LECLERC
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr
*/

// --------------------------------------------------------------------------------------------------------
struct Triangle {
    static const unsigned nb_var_inter = 2;
    static const unsigned nb_nodes = 3;
    static const char *name() { return "Triangle"; }
    static const char *can_directly_be_represented_by() { return "Triangle"; }
};

// --------------------------------------------------------------------------------------------------------
template<> struct NbChildrenElement<Triangle,0> { static const unsigned res = 1; };
template<> struct NbChildrenElement<Triangle,1> { static const unsigned res = 3; };
template<> struct NbChildrenElement<Triangle,2> { static const unsigned res = 3; };

template<unsigned n> struct TypeChildrenElement<Triangle,0,n> { typedef Triangle T; };
template<unsigned n> struct TypeChildrenElement<Triangle,1,n> { typedef Bar T; };
template<unsigned n> struct TypeChildrenElement<Triangle,2,n> { typedef NodalElement T; };

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Triangle,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<0> nvi_to_subs) {
   het.add_element(e,ch,Triangle(),e.node(0),e.node(1),e.node(2));
}

template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Triangle,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<1> nvi_to_subs) {
    het.add_element(e,ch,Bar(),e.node(0),e.node(1));
    het.add_element(e,ch,Bar(),e.node(1),e.node(2));
    het.add_element(e,ch,Bar(),e.node(2),e.node(0));
}
template<class TN,class TNG,class TD,unsigned NET,class TC,class HET>
void append_skin_elements(Element<Triangle,TN,TNG,TD,NET> &e,TC &ch,HET &het,Number<2> nvi_to_subs) {
    het.add_element(e,ch,NodalElement(),e.node(0));
    het.add_element(e,ch,NodalElement(),e.node(1));
    het.add_element(e,ch,NodalElement(),e.node(2));
}

// --------------------------------------------------------------------------------------------------------
template<class TN,class TNG,class TD,unsigned NET,class Pvec,class T>
void update_circum_center(const Element<Triangle,TN,TNG,TD,NET> &e,Pvec &C,T &R) {
    C = getCenterOfCircumCircle( e.node(0)->pos, e.node(1)->pos, e.node(2)->pos );
    R = length( e.node(0)->pos - C );
}

template<class TN,class TNG,class TD,unsigned NET,class Pvec,class T>
void intersection(const Element<Triangle,TN,TNG,TD,NET> &e,Pvec P1,Pvec P2,T &numP1P2,T &dist_ext) {
    DEBUGASSERT( (TNG::dim==3) );
    
    Pvec T0(e.node(0)->pos), T1(e.node(1)->pos), T2(e.node(2)->pos);
    Pvec N = vect_prod(T1-T0,T2-T0);
    numP1P2 = dot(T0-P1,N) / dot(P2-P1,N);
    
    Pvec pres = P1 + (P2-P1) * numP1P2;
    T dist0 = dot(vect_prod(T0-T1,T2-T1),vect_prod(pres-T1,T2-T1));
    T dist1 = dot(vect_prod(T1-T2,T0-T2),vect_prod(pres-T2,T0-T2));
    T dist2 = dot(vect_prod(T2-T0,T1-T0),vect_prod(pres-T0,T1-T0));
    if ( dist0>=0 && dist1>=0 && dist2>=0 ) // interior
        dist_ext = -min(min(fabs(dist0),fabs(dist1)),fabs(dist2));
    else  // exterior
        dist_ext = min(min(fabs(dist0),fabs(dist1)),fabs(dist2));
}
template<class TN,class TNG,class TD,unsigned NET>
typename TNG::Pvec sample_normal(const Element<Triangle,TN,TNG,TD,NET> &e) {
    DEBUGASSERT( (TNG::dim==3) );
    typename TNG::Pvec res = vect_prod( e.node(1)->pos-e.node(0)->pos, e.node(2)->pos-e.node(0)->pos );
    return res / length( res );
}

template<class TN,class TNG,class TD,unsigned NET,class TM>
bool divide_element(Element<Triangle,TN,TNG,TD,NET> &e,TM &m,TNG **nnodes) {
    typedef Element<Triangle,TN,TNG,TD,NET> TE;
    if ( nnodes[0] && nnodes[1] && nnodes[2] ) {
        DM::copy( e, *m.add_element( Triangle(), TN(), e.node(0), nnodes[0], nnodes[2] ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[2], nnodes[0], nnodes[1] ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[1], nnodes[0], e.node(1) ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), e.node(2), nnodes[2], nnodes[1] ) );
    }
    else if ( nnodes[0] && nnodes[1] ) {
        DM::copy( e, *m.add_element( Triangle(), TN(), e.node(0), nnodes[0], nnodes[1] ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[0], e.node(1), nnodes[1] ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), e.node(0), nnodes[1], e.node(2) ) );
    }
    else if ( nnodes[0] && nnodes[2] ) {
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[2], e.node(0), nnodes[0] ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[2], nnodes[0], e.node(1) ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[2], e.node(1), e.node(2) ) );
    }
    else if ( nnodes[1] && nnodes[2] ) {
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[2], e.node(0), e.node(1) ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[2], e.node(1), nnodes[1] ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[2], nnodes[1], e.node(2) ) );
    }
    else if ( nnodes[0] ) {
        DM::copy( e, *m.add_element( Triangle(), TN(), e.node(0), nnodes[0], e.node(2) ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[0], e.node(1), e.node(2) ) );
    }
    else if ( nnodes[1] ) {
        DM::copy( e, *m.add_element( Triangle(), TN(), e.node(0), e.node(1), nnodes[1] ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), e.node(0), nnodes[1], e.node(2) ) );
    }
    else if ( nnodes[2] ) {
        DM::copy( e, *m.add_element( Triangle(), TN(), e.node(0), e.node(1), nnodes[2] ) );
        DM::copy( e, *m.add_element( Triangle(), TN(), nnodes[2], e.node(1), e.node(2) ) );
    }
    
    return ( nnodes[0] || nnodes[1] || nnodes[2] );
}
template<class TN,class TNG,class TD,unsigned NET,class TM>
bool divide_element_using_elem_children(Element<Triangle,TN,TNG,TD,NET> &e,TM &m,TNG **nnodes) {
    return divide_element(e,m,nnodes);
}

/** new_nodes are independant nodes created to make a fine grid for integration. Used in TvrcFormulation
    \relates Triangle
    \todo actually, we divide element n times, with n = max(edge length) / max_dist. For flat elements, it's far from optimallity
*/
template<class TN,class TNG,class TD,unsigned NET,class T>
bool subdivision_element(const Element<Triangle,TN,TNG,TD,NET> &e,Vec<TNG> &new_nodes,T max_dist) {
    T max_l = max( length( e.node(1)->pos - e.node(0)->pos ), length( e.node(2)->pos - e.node(1)->pos ), length( e.node(0)->pos - e.node(2)->pos ) );
    if ( max_l <= max_dist )
        return false;
    unsigned n = (unsigned)(max_l / max_dist);
    for(unsigned i=0;i<n;++i) {
        for(unsigned j=0;j<=i;++j) {
            TNG *nn = new_nodes.new_elem();
            T f1 = (i+1.0)/(n+1.0);
            T f2 = (j+1.0)/(n+1.0);
            T f3 = 1.0 - f1 - f2;
            std::pair<T,const TNG *> pond_list[] = {
                std::pair<T,const TNG *>( f1, e.node(0) ),
                std::pair<T,const TNG *>( f2, e.node(1) ),
                std::pair<T,const TNG *>( f3, e.node(2) )
            };
            DM::get_ponderation( pond_list, 3, *nn );
        }
    }
    return true;
}

template<class TN,class TNG,class TD,unsigned NET>
typename TNG::T measure( const Element<Triangle,TN,TNG,TD,NET> &e ) {
    typename TNG::Pvec P0 = e.node(0)->pos, P1 = e.node(1)->pos, P2 = e.node(2)->pos, N = normalized(P1-P0);
    P2 -= dot(P2-P0,N)*N;
    return 0.5 * length( P1-P0 ) * length( P2-P0 );
}


template<class TV,class T>
bool var_inter_is_inside( const Triangle &e, const TV &var_inter, T tol = 0 ) {
    return heaviside( var_inter[0] + tol ) * heaviside( var_inter[1] + tol ) * heaviside( 1 - var_inter[0] - var_inter[1] + tol );
}

}

#include "element_Triangle.h"

#endif
