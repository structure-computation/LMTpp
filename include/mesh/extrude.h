#ifndef LMT_extrude_HEADER
#define LMT_extrude_HEADER

#include "make_rect.h"

namespace LMT {

struct Bar;
struct Bar_3;
struct Triangle_6;
struct Triangle;
struct Quad;
struct Quad_8;
struct Quad_9;
struct Quad_6;
struct Quad_42;
struct Hexa;
struct Tetra;
struct DefaultBehavior;
struct Wedge;
struct Hexa_20;
struct Tetra_10;
struct Wedge_15;

template< class Pvec_, class TNode_ >
struct GetNormal {
    typedef Pvec_ Pvec;
    typedef std::map< TNode_*, Pvec_ > MapPvec;
    
    template< class TE >
    void operator() ( const TE & e) {
        Pvec nor = sample_normal( e );
        typename MapPvec::iterator it;
        //PRINT( nor );
        for( unsigned i = 0; i < TE::nb_nodes; ++i ) {
            it = map_normal.find( e.nodes[ i ] );
            if ( it != map_normal.end() )
                it->second += nor;
            else
                map_normal[ e.nodes[ i ] ] = nor;
        } 
    }
    
    void normalize() {
        typename MapPvec::iterator it;
        for( it = map_normal.begin(); it != map_normal.end(); it++ )
            if ( length( it->second ) >  0 )
                it->second /= length( it->second );
    }
    
    void display_normal() const {
        typename MapPvec::const_iterator it;
        for( it = map_normal.begin(); it != map_normal.end(); it++ )
            PRINT( it->second );    
    }
    
    //Vec< Pvec > list_normal;
    MapPvec map_normal;
};

template< class TM, class MV3, class T, bool sameDirection >
struct Extruder {
    typedef typename TM::Pvec Pvec;
    typedef Vec< typename TM::TNode * > VN;
    
    Extruder( TM &m_, MV3& map_normal_, T thickness_, unsigned nb_layer_, T prec_ = 1e-5 ) : m( m_), map_normal( map_normal_ ), nb_layer( nb_layer_ ) { 
        ba.prec = prec_;
        ba.m = &m_;
        thickness_by_layer = thickness_ / nb_layer_;
    }
    
    template < class TE >
    void init_vnode( const TE &e, VN &vn ) {
        vn.resize( ( nb_layer + 1 ) * TE::nb_nodes );
        Vec< Pvec > vp;
        vp.resize( TE::nb_nodes );
        vp.set( 0 );/// si le maillage est défini dans le plan, on s'assure que la composante en z vaut zéro.
        for( unsigned i = 0; i < TE::nb_nodes; ++i ) {
            vp[ i ] = e.pos( i );
            vn[ i ] = ba.get_node( vp[ i ] );
        }
        for( unsigned z = 1; z <= nb_layer; ++z )
            for( unsigned i = 0; i < TE::nb_nodes; ++i )
                if ( sameDirection )
                    vn[ z * TE::nb_nodes + i ] = ba.get_node( vp[ i ] + z * thickness_by_layer * map_normal[ NULL ] ); 
                else
                    vn[ z * TE::nb_nodes + i ] = ba.get_node( vp[ i ] + z * thickness_by_layer * map_normal[ e.nodes[ i ] ] ); 
    }
    
    /// Triangle
    template< class NameBehavior, class TNode_, class TData, unsigned num_in_elem_list_ >
    void operator() ( const Element< Triangle, NameBehavior, TNode_, TData, num_in_elem_list_ > &e ) {
    
        typedef Element< Triangle, NameBehavior, TNode_, TData, num_in_elem_list_ > TE;
        VN vn;
        
        init_vnode( e, vn );
        for( unsigned z = 0; z < nb_layer; ++z ) {
            permutation_if_jac_neg( Wedge(), vn.ptr() + z * TE::nb_nodes );
            m.add_element( Wedge(), DefaultBehavior(), vn.ptr() + z * TE::nb_nodes );
        }
    }
    
    /// Quad
    template< class NameBehavior, class TNode_, class TData, unsigned num_in_elem_list_ >
    void operator() ( const Element< Quad, NameBehavior, TNode_, TData, num_in_elem_list_ > &e ) {
    
        typedef Element< Quad, NameBehavior, TNode_, TData, num_in_elem_list_ > TE;
        VN vn;
        
        init_vnode( e, vn );
        for( unsigned z = 0; z < nb_layer; ++z ) {
            permutation_if_jac_neg( Hexa(), vn.ptr() + z * TE::nb_nodes );
            m.add_element( Hexa(), DefaultBehavior(), vn.ptr() + z * TE::nb_nodes );
        }
    }
    
    template< class TE >
    void operator() ( const TE &e ) {
        std::cerr << "Error struct Extruder : " <<  e.name() << " is not extruded. TODO. " << std::endl;
    }
    
    TM &m;
    MV3 &map_normal;
    T thickness_by_layer;
    unsigned nb_layer;
    BestialNodeAdder<TM> ba;
};

template < class TM_RES, class TM_SCR, class T >
void extrude( TM_RES &res, const TM_SCR &m, T thickness, unsigned nb_layer = 1 ) {
    typedef typename TM_RES::MA::Pvec Pvec;
    typedef GetNormal< Pvec, typename TM_SCR::TNode > GN;

    GN gn;

    /// maillage 2D
    if ( TM_SCR::MA::dim == 2 ) {
        /// la directon d'extrusion est toujours (Oz) => 1 vecteur
        //PRINT( "coucou" );
        gn.map_normal[ NULL ] = Pvec( 0., 0., 1. );
        Extruder< TM_RES, typename GN::MapPvec, T, true > extruder( res, gn.map_normal, thickness, nb_layer );
        apply( m.elem_list, extruder );
        return;
    }
    
    /// maillage 3D
    if ( TM_SCR::MA::dim == 3 ) {
        /// maillage surfacique
        if ( TM_SCR::MA::nvi == 2 ) {
            /// on calcule la somme des normales des éléments adjacents à chaque noeud
            apply( m.elem_list, gn );
            /// on normalise les normales
            gn.normalize();
            /// on extrude suivant la direction des normales
            Extruder< TM_RES, typename GN::MapPvec, T, false > extruder( res, gn.map_normal, thickness, nb_layer );
            apply( m.elem_list, extruder );
            return;
        }
        /// maillage volumique dont la peau sera extrudée
        if ( TM_SCR::MA::nvi == 3 ) {
            /// on calcule la somme des normales des éléments adjacents à chaque noeud
            apply( m.skin.elem_list, gn );
            /// on normalise les normales
            gn.normalize();
            /// on extrude suivant la direction des normales
            Extruder< TM_RES, typename GN::MapPvec, T, false > extruder( res, gn.map_normal, thickness, nb_layer );
            apply( m.skin.elem_list, extruder );
            return;
        }
    }
    
    std::cerr << "Error extrude() : nothing has been done." << std::endl;
}

}

#endif // LMT_extrude_HEADER
