#ifndef MAKE_SUB_MESH_H
#define MAKE_SUB_MESH_H

#include <mesh/mesh.h>

namespace LMT {

namespace Private {
template<class TM_dst,class TM_src>
struct MakeSubMesh {
    typedef typename TM_dst::TNode TN_dst;

    MakeSubMesh( int nb_node_in_src_mesh ) { nodes.resize( nb_node_in_src_mesh, 0 ); }

    template<class TE>
    void operator()( const TE &elem, TM_dst &dst, const TM_src &src ) {
        TN_dst *elem_node_list[ TE::nb_nodes ];
        for( int i = 0; i < TE::nb_nodes; ++i ) {
            TN_dst *&n = nodes[ elem.node( i )->number ];
            if ( not n )
                n = dst.add_node( elem.node( i )->pos );
            elem_node_list[ i ] = n;
        }

        dst.add_element( typename TE::NE(), typename TE::BE(), elem_node_list );
    }

    Vec<TN_dst *> nodes;
};
}

/**
*/
template<class TM_dst,class TM_src>
void make_sub_mesh( TM_dst &dst, const TM_src &src, const Vec<typename TM_src::EA *> &l ) {
    Private::MakeSubMesh<TM_dst,TM_src> funktor( src.node_list.size() );
    for( int i = 0; i < l.size(); ++i )
        src.elem_list.apply_on_down_cast( l[ i ], funktor, dst, src );
}

} // namespace LMT

#endif // MAKE_SUB_MESH_H
