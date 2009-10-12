#ifndef MAKE_MESH_FROM_MASK_H
#define MAKE_MESH_FROM_MASK_H

#include "calculate_normals.h"
#include "make_rect.h"
#include <util/load_image.h>
#include <util/img_dist_from_front.h>
#include <mesh/remove_lonely_nodes.h>

namespace LMT {

template<class TM>
struct MakeMeshFromMask {
    typedef typename TM::Pvec Pvec;
    typedef typename TM::Tpos T;

    struct MakeMeshFromMaskFindCorners {
        MakeMeshFromMaskFindCorners( const TM &m ) {
            normals.resize( m.node_list.size(), Pvec( 0.0 ) );
            centers.resize( m.node_list.size(), Pvec( 0.0 ) );
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
                    centers[ n ] = center( e );
                } else {
                    dot_prod[ n ] = abs( dot( normals[ n ], N ) );
                    break_out[ n ] = false;
                    if ( dot_prod[ n ] < 0.5 ) {
                        T a = length( center(e) - centers[n] );
                        T b = length( center(e) + a * N - ( centers[n] + a * normals[n] ) );
                        break_out[ n ] = ( b >= a );
                    }
                }
            }
        }
        Vec<Pvec> normals;
        Vec<Pvec> centers;
        Vec<T   > dot_prod;
        Vec<bool> break_out;
    };
    
    struct MakeMeshFromMaskNbParents {
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

    struct GetMaxElemSize {
        template<class TE> void operator()( const TE &e, T &max_elem_size ) const {
            max_elem_size = max( max_elem_size, pow( measure( e ), 1.0 / TE::dim ) );
        }
    };

    MakeMeshFromMask( TM &m, T max_elem_size = 0 ) : m( m ), elem_size( max_elem_size ) {
        if ( not elem_size )
            apply( m.elem_list, GetMaxElemSize(), elem_size );
        assert( elem_size );
        //
        border_size = int( elem_size * 2 );
        //
        for(unsigned i=0;i<m.node_list.size();++i)
            m.node_list[i].pos += border_size;
    }
    
    void set_img( const std::string &mask_filename, int border_color = 255 ) {
        load_image( mask_filename, M, /*ceil_size*/1, border_size, border_color );
        // display_image( M, "tmp/dist", true, true );
        
        dist = img_dist_from_front( M, border_size, /*gray level*/ mean( M ) );
        // display_image( Mat<int>( dist * 255 / max( dist ) ), "tmp/dist", true );
    }
    
    void add_elements() {
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
                out[ cpt ] = ( p[1] >= M.nb_rows() or p[0] >= M.nb_cols() or p[1] < 0 or p[0] < 0 or 
                    //( M( M.nb_rows() - 1 - int(p[1]), int(p[0]) ) >= 128 and dist( M.nb_rows() - 1 - int(p[1]), int(p[0]) ) > elem_size / 3 )
                    ( M( int(p[1]), int(p[0]) ) >= 128 and dist( int(p[1]), int(p[0]) ) > elem_size / 3 )
                );
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
                    bool ok = true;
                    for (int i=0;i<3;++i)
                        ok &= ( out[indices[i]] == false );
                    //
                    if ( ok ) {
                        for (int i=0;i<3;++i) {
                            if ( ref[ indices[i] ] == -1 ) {
                                ref[indices[i]] = m.node_list.size();
                                m.add_node( pos[ indices[i] ] );
                            }
                            indices[i] = ref[indices[i]];
                        }
                        connectivity.push_back( indices );
                    }
                }
            }
        }
        
        // elements
        for(unsigned i=0;i<connectivity.size();++i)
            m.add_element( Triangle(), DefaultBehavior(), connectivity[i].ptr() );
    }

    struct RemoveElementIfExt {
        RemoveElementIfExt( Mat<float> &M, Mat<float> &dist, T tol ) : M( M ), dist( dist ), tol( tol ) {}
        template<class TE> bool operator()( const TE &e ) const {
            Pvec c = center( e );
            return M( int(c[1]), int(c[0]) ) > 128 and dist( int(c[1]), int(c[0]) ) > tol;
        }
        Mat<float> &M;
        Mat<float> &dist;
        T tol;
    };

    void remove_ext_center_elements( T tol = 0 ) {
        RemoveElementIfExt re( M, dist, tol );
        m.remove_elements_if( re );
        remove_lonely_nodes( m );
    }
    
    struct RemoveElementIfNodesExt {
        RemoveElementIfNodesExt( Mat<float> &M, Mat<float> &dist, T tol ) : M( M ), dist( dist ), tol( tol ) {}
        template<class TE> bool operator()( const TE &e ) const {
            bool ext = false;
            for(unsigned i=0;i<TE::nb_nodes;++i)
                ext |= M( int(e.pos(i)[1]), int(e.pos(i)[0]) ) > 128 and dist( int(e.pos(i)[1]), int(e.pos(i)[0]) ) > tol;
            return ext;
        }
        Mat<float> &M;
        Mat<float> &dist;
        T tol;
    };
    
    void remove_ext_nodes_elements( T tol = 0 ) {
        RemoveElementIfNodesExt re( M, dist, tol );
        m.remove_elements_if( re );
        remove_lonely_nodes( m );
    }

    void projection() {
        m.update_skin();
        for(unsigned k=0;k<2;++k) {
            for(unsigned i=0;i<m.skin.node_list.size();++i) {
                Pvec P = m.skin.node_list[i].pos;
                // int y = dist.nb_rows() - 1 - int(P[1]);
                int y = int(P[1]);
                int x = int(P[0]);
                T d = dist( y, x );
                T grad_x = dist( y, x + 1 ) - dist( y, x - 1 );
                T grad_y = dist( y + 1, x ) - dist( y - 1, x );
                Pvec grad = normalized( Pvec( grad_x, grad_y ) );
                m.skin.node_list[i].pos -= grad * d;
            }
        }
        
        //     m.skin.update_node_neighbours();
        //     while ( true ) {
        //         bool can_break = true;
        //         
        //         //
        //         calculate_normals( m.skin );
        //             
        //         // for(unsigned i=0;i<m.skin.node_list.size();++i) {
        //         //     assert( m.skin.get_node_neighbours(i).size() == 2 );
        //         //     Pvec P0 = m.skin.get_node_neighbours(i)[0]->pos;
        //         //     Pvec P1 = m.skin.get_node_neighbours(i)[1]->pos;
        //         //     Pvec OR = ortho( Pvec( P1 - P0 ) );
        //         //     OR *= ( dot( OR, m.skin.node_list[i].normal ) >= 0 ? 1 : -1 );
        //         //     Pvec P2 = 0.5 * ( P0 + P1 ) + 4 * OR - m.skin.node_list[i].pos;
        //         //     m.skin.node_list[i].normal = P2 / length( P2 );
        //         // }
        //         
        //         //
        //         for(unsigned i=0;i<m.skin.node_list.size();++i) {
        //             Pvec &p = m.skin.node_list[i].pos;
        //             const Pvec &n = m.skin.node_list[i].normal;
        //             T l, step = 0.5;
        //             for( l = step; l <= elem_size / 8; l += step ) {
        //                 Pvec t = p + l * n;
        //                 if ( t[1] >= M.nb_rows() or t[0] >= M.nb_cols() or t[1] < 0 or t[0] < 0 or M( M.nb_rows() - 1 - int(t[1]), int(t[0]) ) >= 128 ) {
        //                     l -= step;
        //                     can_break &= ( l <= step / 2 );
        //                     break;
        //                 }
        //             }
        //             p += l * n;
        //         }
        //         // break;
        //         //   static int z = 0;
        //         //   dp.add_mesh( m, "tmp/toto", Vec<std::string>("all"), z++ );
        //         if ( can_break )
        //             break;
        //     }
        
        // find corners
        calculate_normals( m.skin );
        
        MakeMeshFromMaskFindCorners fc( m );
        MakeMeshFromMaskNbParents   np( m );
        apply( m.skin.elem_list, np, fc.dot_prod, fc.break_out );
        
        for(unsigned i=0;i<m.node_list.size();++i) {
            if ( fc.break_out[ i ] ) {
                m.node_list[i].is_on_skin = true;
                Pvec p = m.node_list[i].pos;
                Pvec n = m.node_list[i].normal;
                Pvec t( -n[1], n[0] ); // = ortho( n );
                T d = elem_size;
                for( T y = d; y >= -d; y-- ) {
                    for( T x = -d; x <= d; x += 1 ) {
                        Pvec np = p + t * x + n * y;
                        //if ( np[0] >= 0 and np[1] >= 0 and np[0] < M.nb_cols() and np[1] < M.nb_rows() and M( M.nb_rows() - 1 - int(np[1]), int(np[0]) ) < 128 ) {
                        if ( np[0] >= 0 and np[1] >= 0 and np[0] < M.nb_cols() and np[1] < M.nb_rows() and M( int(np[1]), int(np[0]) ) < 128 ) {
                            m.node_list[i].pos = np;
                            y = - d - 1;
                            break;
                        }
                    }
                }
            }
        }
    
    }

    void smooth() {
    }

    void finish() {
        for(unsigned i=0;i<m.node_list.size();++i)
            m.node_list[i].pos -= border_size;
    }

    TM &m;
    Mat<float> M, dist;
    int border_size;
    T elem_size;
};


template<class TM>
void make_mesh_from_mask( const std::string &filename, TM &m, typename TM::Tpos elem_size, bool want_smoothing = true ) {
    MakeMeshFromMask<TM> make_mesh( m, elem_size );
    make_mesh.set_img( filename );
    make_mesh.add_elements();
    make_mesh.projection();
    if ( want_smoothing )
        make_mesh.smooth();
    make_mesh.finish();
}


}

#endif // MAKE_MESH_FROM_MASK_H

