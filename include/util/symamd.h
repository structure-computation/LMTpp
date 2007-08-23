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

namespace LMT {

/**
    ...
 */
Vec<unsigned> symamd(const Vec<Vec<unsigned> > &indices);

}

#endif
