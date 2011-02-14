#ifndef SEP_MESH_H
#define SEP_MESH_H

#include <containers/vec.h>

namespace LMT {

template<class TM>
struct SepMesh {
    SepMesh( TM &m ) {
        created_nodes.resize( m.node_list.size(), 0 );
    }

    template<class TE0,class TL1,class TL2>
    void operator()( TE0 &e0, TM &m, const TL1 &ls_crack, const TL2 &ls_front ) {
        if ( ls_crack( center( e0 ) ) >= 0 )
            return;
        SimpleConstIterator<typename TM::EA *> iter = m.get_elem_neighbours( e0 );
        for( unsigned num_nei = 0; num_nei < iter.size(); ++num_nei ) {
            typename TM::EA &e1 = *iter[ num_nei ];
            if ( ls_front( center( e1 ) ) >= 0 or ls_crack( center( e1 ) ) < 0 )
                continue;
            for(unsigned num_n0=0;num_n0<TE0::nb_nodes;++num_n0) {
                for(unsigned num_n1=0;num_n1<e1.nb_nodes_virtual();++num_n1) {
                    if ( e0.node( num_n0 ) == e1.node_virtual( num_n1 ) ) {
                        unsigned n = e0.node( num_n0 )->number;
                        if ( not created_nodes[ n ] )
                            created_nodes[ n ] = m.add_node( e0.node( num_n0 )->pos );
                        e0.nodes[ num_n0 ] = created_nodes[ n ];
                        break;
                    }
                }
            }
        }
    }

    template<class TE0,class TL1 >
    void operator()( TE0 &e0, TM &m, const TL1 &ls_crack ) {
        if ( ls_crack( center( e0 ) ) >= 0 )
            return;
        SimpleConstIterator<typename TM::EA *> iter = m.get_elem_neighbours( e0 );
        for( unsigned num_nei = 0; num_nei < iter.size(); ++num_nei ) {
            typename TM::EA &e1 = *iter[ num_nei ];
            if ( ls_crack( center( e1 ) ) < 0 )
                continue;
            for(unsigned num_n0=0;num_n0<TE0::nb_nodes;++num_n0) {
                for(unsigned num_n1=0;num_n1<e1.nb_nodes_virtual();++num_n1) {
                    if ( e0.node( num_n0 ) == e1.node_virtual( num_n1 ) ) {
                        unsigned n = e0.node( num_n0 )->number;
                        if ( not created_nodes[ n ] )
                            created_nodes[ n ] = m.add_node( e0.node( num_n0 )->pos );
                        e0.nodes[ num_n0 ] = created_nodes[ n ];
                        break;
                    }
                }
            }
        }
    }

    Vec<typename TM::TNode *> created_nodes;
};

template<class TM,class TL1,class TL2>
void sep_mesh( TM &m, const TL1 &ls_crack, const TL2 &ls_front ) {
    m.update_elem_neighbours();
    SepMesh<TM> sm( m );
    apply( m.elem_list, sm, m, ls_crack, ls_front );
    m.signal_connectivity_change();
}

template<class TM,class TL1 >
void sep_mesh( TM &m, const TL1 &ls_crack ) {
    m.update_elem_neighbours();
    SepMesh<TM> sm( m );
    apply( m.elem_list, sm, m, ls_crack );
    m.signal_connectivity_change();
}

} 

#endif // SEP_MESH_H
