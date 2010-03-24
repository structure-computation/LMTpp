//
// C++ Interface: isinteriorofmesh
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_isinteriorofmesh_HEADER
#define LMT_isinteriorofmesh_HEADER

#include <limits>

namespace LMT {

template<unsigned nvi_to_use,class Pvec,class T>
struct GetClosestInter {
    template<class TE,unsigned n> void f(const TE &e,const Number<n> &nn) {}
    template<class TE> void f(const TE &e,const Number<0> &nn) {
        if ( ambiguity ) return;

        T dist_ext, ndist;
        intersection( e, P1, P2, ndist, dist_ext );
        if ( fabs(dist_ext) <= std::numeric_limits<T>::epsilon()*8.0 )
            ambiguity = true;
        nb_inter += ( ndist>0 && dist_ext<=0 );
    }
    template<class TE> void operator()(const TE &e) { f(e,Number<nvi_to_use-TE::nb_var_inter>()); }
    bool ambiguity;
    unsigned nb_inter;
    Pvec P1,P2;
};

/** test if a point is in m which is assumed to be a closed surface in 3d and a closed curve in 2d.
    The precision problem is treated using a kind of dichotomy sweeping if ambiguity (along a line in 2d and a curve in 3d)
    \relates LMT::Mesh
 */
template<unsigned nvi_to_use,class TM>
bool is_in_interior_of_mesh(const TM &m,const typename TM::Pvec &p) {
    // return true;
    typedef typename TM::Pvec Pvec;
    typedef typename TM::Tpos T;
    
    GetClosestInter<nvi_to_use,Pvec,T> gni;
    gni.P1 = p;
    unsigned cpt = 0;
    do {
        for(unsigned i=0;i<TM::dim;++i)
            gni.P2[i] = p[i] + rand()*2.0/RAND_MAX - 1.0;
        gni.nb_inter = 0;
        gni.ambiguity = false;
        apply(m.elem_list, gni);
        if ( cpt++ == 50 )
            return true;
        //            assert(0 /* bad luck */ );
    } while( gni.ambiguity );
    
    return (gni.nb_inter&1);
}

};

#endif // LMT_isinteriorofmesh_HEADER

