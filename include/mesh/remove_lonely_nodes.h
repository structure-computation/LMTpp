//
// C++ Implementation: remove_lonely_nodes
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_REMOVE_LONELY_NODES_H
#define LMT_REMOVE_LONELY_NODES_H

#include <mesh/mesh.h>

namespace LMT {

struct GetLonelyNodes {
    template<class TE> void operator()(const TE &e) {
        for(unsigned i=0;i<TE::nb_nodes;++i)
            lonely[ e.node(i)->number ] = false;
    }
    Vec<int> lonely;
};

/// return true if some points have been removed
template<class Carac>
bool remove_lonely_nodes(Mesh<Carac> &m) {
    typedef Mesh<Carac> TM;
    typedef typename TM::TNode TNode;

    // fill lonely vec
    int nn = m.node_list.size(), old_nn = nn;
    GetLonelyNodes gln; gln.lonely.resize( m.node_list.size(), true );
    apply( m.elem_list, gln );
    for(int i=0;i<(int)m.node_list.size();++i) {
        if ( gln.lonely[i] )
            gln.lonely[i] = -1;
        else
            gln.lonely[i] = i;
    }
    
    // round 2 : 
    for(int i=0;i<nn;++i) {
        if ( gln.lonely[i] != i ) {
            while( nn && gln.lonely[nn-1]!=nn-1 ) --nn;
            for(int j=nn;j<old_nn;++j) if ( gln.lonely[j]==nn-1 ) gln.lonely[j]=i;
            if ( i>=nn ) break;
            gln.lonely[ nn-1 ] = i;
            //std::cout << "Copy " << i << " " << nn-1 << std::endl;
            DM::copy( m.node_list[nn-1], m.node_list[i] );
        }
    }
    
    int new_size = max( gln.lonely )+1;
    
    Vec<TNode *> ncor; ncor.resize( old_nn );
    for(int i=0;i<old_nn;++i)
        if ( gln.lonely[i]>=0 ) 
            ncor[i] = &m.node_list[ gln.lonely[i] ];
    
    if ( new_size!=old_nn ) {
        m.change_node_ptr_in_elements(ncor.begin());
        m.node_list.pop_back(old_nn-new_size);
        m.signal_connectivity_change();
        return true;
    }
    return false;
}

};

#endif // LMT_REMOVE_LONELY_NODES_H
