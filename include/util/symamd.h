//
// C++ Interface: symamd
//
// Description:
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_symamd_HEADER
#define LMT_symamd_HEADER

#include "containers/vec.h"
#include <algorithm>

namespace LMT {

/**
    perform amd ordering on graph indices
 */
Vec<unsigned> symamd(const Vec<Vec<unsigned> > &indices);

namespace LMT_PRIVATE {
    struct GetLink {
        template<class TE,class TM> void operator()(const TE &e,const TM &m,Vec<Vec<unsigned> > &v) const {
            for(unsigned i=0;i<TE::nb_nodes;++i) {
                unsigned a = m.node_list.number(*e.node(i));
                for(unsigned j=0;j<TE::nb_nodes;++j) {
                    unsigned b = m.node_list.number(*e.node(j));
                    if ( std::find(v[a].begin(),v[a].end(),b)==v[a].end() )
                        v[a].push_back( b );
                }
            }
        }
    };
}

/**
    perform amd ordering on nodes of m (return node numbers)
*/
template<class TM>
Vec<unsigned> symamd( const TM &m ) {
    Vec<Vec<unsigned> > ind; ind.resize( m.node_list.size() );
    apply( m.elem_list, LMT_PRIVATE::GetLink(), m, ind );
    for(unsigned i=0;i<ind.size();++i)
        std::sort( ind[i].begin(), ind[i].end() );
    //
    Vec<unsigned> perm = symamd( ind );
    Vec<unsigned> inv_perm; inv_perm.resize(perm.size());
    for(unsigned i=0;i<perm.size();++i)
        inv_perm[perm[i]] = i;
    return inv_perm;
}


}

#endif
