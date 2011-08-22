#ifndef MESHCOULOUR_H
#define MESHCOULOUR_H

#include "../containers/vec.h"

namespace LMT {

/**
  assign a colour to each element such as nodes of elem of same colour do not touch
*/
template<class TM>
struct MeshColour {
    MeshColour( const TM &m ) {
        res.resize( m.elem_list.size(), -1 );
        node_col.resize( m.node_list.size() );

        for( num_colour = 0; at_least_one( res == -1 ); ++num_colour ) {
            node_col.set( -1 );
            apply_wi( m.elem_list, GetColour(), num_colour, node_col, res );
            // PRINT( sum( generate( res == num_colour, Cast_int() ) ) );
        }
    }

    struct GetColour {
        template<class TE>
        void operator()( const TE &e, int n, int num_colour, Vec<int> &node_col, Vec<int> &res ) const {
            if ( res[ n ] >= 0 )
                return;
            for( int i = 0; i < e.nb_nodes; ++i )
                if ( node_col[ e.node( i )->number ] == num_colour )
                    return;
            //
            for( int i = 0; i < e.nb_nodes; ++i )
                node_col[ e.node( i )->number ] = num_colour;
            res[ n ] = num_colour;
        };
    };

    int num_colour;
    Vec<int> node_col;
    Vec<int> res;
};

}

#endif // MESHCOULOUR_H
