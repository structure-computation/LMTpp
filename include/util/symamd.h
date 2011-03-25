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

#include "GetLinkForOrdering.h"

namespace LMT {

/**
    perform amd ordering on graph indices
 */
Vec<unsigned> symamd( const Vec<Vec<unsigned> > &indices );

/**
    perform amd ordering on nodes of m (return node numbers)
*/
template<class TM>
Vec<unsigned> symamd( const TM &m ) {
    Vec<Vec<unsigned> > ind;
    get_link_for_ordering( ind, m );
    //
    Vec<unsigned> perm = symamd( ind );
    Vec<unsigned> inv_perm; inv_perm.resize(perm.size());
    for(unsigned i=0;i<perm.size();++i)
        inv_perm[perm[i]] = i;
    return inv_perm;
}


}

#endif
