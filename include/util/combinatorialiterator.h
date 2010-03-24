//
// C++ Interface: combinatorialiterator
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_combinatorialiterator_HEADER
#define LMT_combinatorialiterator_HEADER

#include "containers/vec.h"

namespace LMT {

/** it is assumed that nb_sub <= nb_tot
    Exemple : <pre>
    for(CombinatorialIterator<4,2> ci;ci;++ci)
        PRINT( *ci );</pre>

    produces
    <pre>
  *ci -> 0 1
  *ci -> 0 2
  *ci -> 0 3
  *ci -> 1 2
  *ci -> 1 3
  *ci -> 2 3
    </pre>
*/
template<unsigned nb_tot,unsigned nb_sub>
class CombinatorialIterator {
public:
    CombinatorialIterator() { pos = nb_sub-1; }
    void operator++() {
        if ( ++pos >= nb_tot ) {
            ++next;
            pos = next.pos+1;
        }
    }
    void get_iter(unsigned *res) const { res[nb_sub-1] = pos; next.get_iter(res); }
    Vec<unsigned,nb_sub> operator*() const { Vec<unsigned,nb_sub> res; get_iter(res.ptr()); return res; }
    
    operator bool() const { return ( pos < nb_tot ); }

    unsigned pos;
    CombinatorialIterator<nb_tot-1,nb_sub-1> next;
};
/**
*/
template<unsigned nb_tot>
class CombinatorialIterator<nb_tot,1> {
public:
    CombinatorialIterator() { pos = 0; }
    void operator++() { ++pos; }
    void get_iter(unsigned *res) const { res[0] = pos; }
    Vec<unsigned,1> operator*() const { return Vec<unsigned,1>(pos); }
    
    operator bool() const { return ( pos < nb_tot ); }

    unsigned pos;
};


};

#endif // LMT_combinatorialiterator_HEADER
