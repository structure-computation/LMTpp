//
// C++ Interface: pair_termination
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_pair_termination_HEADER
#define LMT_pair_termination_HEADER

#include <algorithm>

namespace LMT {

template<class T1,class T2> const T1 &pair_termination(const std::pair<const T2 &,const T1 &> &p) { return p.second; }
template<class T1,class T2,class T3> const T1 &pair_termination(const std::pair<const T3 &,const std::pair<const T2 &,const T1 &>&>&p) { return p.second.second; }
template<class T1,class T2,class T3,class T4> const T1 &pair_termination(
    const std::pair<const T4 &,
        const std::pair<const T3 &,
            const std::pair<const T2 &,
                const T1 &
            >&
        >&
    >& p) {
    return p.second.second.second;
}

template<class T1,class T2> T1 pair_termination(const std::pair<T2,T1> &p) { return p.second; }
template<class T1,class T2,class T3> T1 pair_termination(const std::pair<T3,std::pair<T2,T1> >&p) { return p.second.second; }
template<class T1,class T2,class T3,class T4> T1 pair_termination(
    const std::pair<T4,
        std::pair<T3,
            std::pair<T2,
                T1
            >
        >
    >& p) {
    return p.second.second.second;
}

};

#endif // LMT_pair_termination_HEADER
