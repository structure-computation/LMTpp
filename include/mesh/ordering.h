//
// C++ Interface: ordering
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_ordering_HEADER
#define LMT_ordering_HEADER

namespace LMT {

struct Sort_xyz_ordering {
    template<class Pvec> bool operator()(const Pvec &v1,const Pvec &v2) const {
        for(int i=Pvec::static_size-1;i>=0;--i) {
            if ( v1[best_axes[i]] > v2[best_axes[i]] ) return true;
            if ( v1[best_axes[i]] < v2[best_axes[i]] ) return false;
        }
        return false;
    }
    Vec<unsigned> best_axes;
};

/*!
 * Simple nodal reordering of m using sort using axis x,y,z
 * @param  
 */
template<class TM>
void xyz_ordering(TM &m) {
    typedef typename TM::Pvec Pvec;
    
    Vec<Pvec> p = generate( m.node_list, ExtractDM<pos_DM>() );
    
    Pvec xmin, xmax;
    get_min_max( m.node_list, ExtractDM<pos_DM>(), xmin, xmax );
    xmax -= xmin;
    
    Sort_xyz_ordering sx;
    sx.best_axes = sort_with_index( xmax );
    
    //PRINT( best_axes );
    Vec<unsigned> sn = sort_with_index( p, sx );
    //apply( p, Display(), std::cout, "\t" );
    Vec<typename TM::TNode *> perm; perm.resize( sn.size() );
    Vec<typename TM::TNode> nn; nn.resize( sn.size() );
    for(unsigned i=0;i<sn.size();++i) {
        perm[ sn[i] ] = &m.node_list[ i ];
        nn[ i ] = m.node_list[ sn[i] ];
    }
    m.change_node_ptr_in_elements( perm.ptr() );
    
    for(unsigned i=0;i<sn.size();++i) {
        m.node_list[i] = nn[i];
        m.node_list[i].number = i;
    }
    
    m.signal_connectivity_change();
}


};

#endif // LMT_ordering_HEADER





