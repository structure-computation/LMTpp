#ifndef MAKE_MESH_FROM_MASK_H
#define MAKE_MESH_FROM_MASK_H

#include "calculate_normals.h"
#include "make_rect.h"
#include <util/load_image.h>

namespace LMT {

template<class TM>
struct MakeMeshFromMaskFindCorners {
    typedef typename TM::Pvec Pvec;
    typedef typename TM::Tpos T;
    MakeMeshFromMaskFindCorners( const TM &m ) {
        normals.resize( m.node_list.size(), Pvec( 0.0 ) );
        break_out.resize( m.node_list.size(), false );
        dot_prod.resize( m.node_list.size() );
        apply( m.skin.elem_list, *this );
    }
    template<class TE> void operator()( const TE &e ) {
        Pvec N = sample_normal( e );
        assert( TE::nb_nodes == 2 /*TODO*/ );
        for(unsigned i=0;i<2;++i) {
            unsigned n = e.node(i)->number_in_original_mesh();
            if ( all( normals[ n ] == 0.0 ) ) {
                normals[ n ] = N;
            } else {
                dot_prod[ n ] = abs( dot( normals[ n ], N ) );
                break_out[ n ] = dot_prod[ n ] < 0.7;
            }
        }
    }
    Vec<Pvec> normals;
    Vec<T   > dot_prod;
    Vec<bool> break_out;
};

template<class TM>
struct MakeMeshFromMaskNbParents {
    typedef typename TM::Pvec Pvec;
    typedef typename TM::Tpos T;
    MakeMeshFromMaskNbParents( const TM &m ) {
        nb_parents.resize( m.node_list.size(), 0 );
        apply( m.elem_list, *this );
    }
    template<class TE> void operator()( const TE &e ) {
        for(unsigned i=0;i<TE::nb_nodes;++i)
            nb_parents[ e.node(i)->number_in_original_mesh() ]++;
    }
    template<class TE> void operator()( const TE &e, const Vec<T> &dot_prod, Vec<bool> &break_out ) {
        unsigned nb_breaks = 0;
        for(unsigned i=0;i<TE::nb_nodes;++i)
            nb_breaks += break_out[ e.node(i)->number_in_original_mesh() ];
        if ( nb_breaks >= 2 ) {
            int best_node = e.node(0)->number_in_original_mesh();
            for(unsigned i=0;i<TE::nb_nodes;++i) {
                unsigned n = e.node(i)->number_in_original_mesh();
                if ( nb_parents[ n ] == 1 ) {
                    best_node = n;
                    break;
                }
                if ( dot_prod[ n ] < dot_prod[ best_node ] )
                    best_node = n;
            }
            for(unsigned i=0;i<TE::nb_nodes;++i) {
                unsigned n = e.node(i)->number_in_original_mesh();
                if ( n != best_node ) 
                    break_out[ n ] = false;
            }
        }
    }
    Vec<unsigned> nb_parents;
};

template<class TM>
void make_mesh_from_mask( const std::string &filename, TM &m, typename TM::Tpos elem_size ) {
    typedef typename TM::Pvec Pvec;
    typedef typename TM::Tpos T;

    Mat<float> M;
    load_image( filename, M );
    
    T sx = elem_size;
    T sy = sqrt(3.0/4.0) * elem_size;
    int nb_x = int( M.nb_cols() / sx );
    int nb_y = int( M.nb_rows() / sy );
    Pvec tdim_min( 0.0 );
    
    int nb_points = nb_x * nb_y;
    if ( nb_points==0 )
        return;
    
    Vec<Pvec> pos; pos.resize( nb_points );
    Vec<bool> out; out.resize( nb_points );
    for (int yi=0,cpt=0;yi<nb_y;++yi) {
        for (int xi=0;xi<nb_x;++xi,++cpt) {
            Pvec p( tdim_min[0] + ( xi - 0.5 * ( yi & 1 ) ) * sx, tdim_min[1] + yi * sy );
            pos[ cpt ] = p;
            out[ cpt ] = ( p[1] >= M.nb_rows() or p[0] >= M.nb_cols() or p[1] < 0 or p[0] < 0 or M( int(p[1]), int(p[0]) ) >= 128 );
        }
    }
    
    // nodes
    Vec<int> ref; ref.resize( nb_points, -1 );
    Vec<Vec<unsigned,3> > connectivity;
    for (int yi=0;yi<nb_y-1;++yi) {
        for (int xi=0;xi<nb_x-1;++xi) {
            int o = xi + yi * nb_x;
            for (int num_x=0;num_x<2;++num_x) {
                Vec<unsigned,3> indices;
                if ( yi&1 ) {
                    if ( num_x&1 ) {
                        indices[0] = o + 1;
                        indices[1] = o + nb_x + 1;
                        indices[2] = o + nb_x;
                    } else {
                        indices[0] = o;
                        indices[1] = o + 1;
                        indices[2] = o + nb_x;
                    }
                } else {
                    if ( num_x&1 ) {
                        indices[0] = o;
                        indices[1] = o + 1;
                        indices[2] = o + nb_x + 1;
                    } else {
                        indices[0] = o;
                        indices[1] = o + 1 + nb_x;
                        indices[2] = o + nb_x;
                    }
                }
                for (int i=0;;++i) {
                    if ( i==3 ) {
                        connectivity.push_back( indices );
                        break;
                    }
                    if ( out[indices[i]] )
                        break;
                    if ( ref[ indices[i] ] == -1 ) {
                        ref[indices[i]] = m.node_list.size();
                        m.add_node( pos[ indices[i] ] );
                    }
                    indices[i] = ref[indices[i]];
                }
            }
        }
    }
    
    // elements
    for(unsigned i=0;i<connectivity.size();++i)
        m.add_element( Triangle(), DefaultBehavior(), connectivity[i].ptr() );

    // projection
    m.update_skin();
    while ( true ) {
        bool can_break = true;
        calculate_normals( m.skin );
        for(unsigned i=0;i<m.skin.node_list.size();++i) {
            Pvec &p = m.skin.node_list[i].pos;
            const Pvec &n = m.skin.node_list[i].normal;
            T l, step = 1.0;
            for( l = step; l <= elem_size / 3; l += step ) {
                Pvec t = p + l * n;
                if ( t[1] >= M.nb_rows() or t[0] >= M.nb_cols() or t[1] < 0 or t[0] < 0 or M( int(t[1]), int(t[0]) ) >= 128 ) {
                    l -= step;
                    can_break &= ( l == 0 );
                    break;
                }
            }
            p += l * n;
        }
        if ( can_break )
            break;
    }
    
    // find corners
    MakeMeshFromMaskFindCorners<TM> fc( m );
    MakeMeshFromMaskNbParents  <TM> np( m );
    apply( m.skin.elem_list, np, fc.dot_prod, fc.break_out );
    
    for(unsigned i=0;i<m.node_list.size();++i) {
        if ( fc.break_out[ i ] ) {
            Pvec p = m.node_list[i].pos;
            Pvec n = m.node_list[i].normal;
            Pvec t = ortho( n );
            for( T y = elem_size; y >= 0; y-- ) {
                for( T x = -elem_size; x <= elem_size; x += 1 ) {
                    Pvec np = p + t * x + n * y;
                    if ( np[0] >= 0 and np[1] >= 0 and np[0] < M.nb_cols() and np[1] < M.nb_rows() and M( int(t[1]), int(t[0]) ) < 128 ) {
                        PRINT( np );
                        PRINT( m.node_list[i].pos );
                        PRINT( y );
                        m.node_list[i].pos = np;
                        y = -1;
                        break;
                    }
                }
            }
        }
    }
}


}

#endif // MAKE_MESH_FROM_MASK_H

