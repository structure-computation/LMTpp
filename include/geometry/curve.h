//
// C++ Interface: curve
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_curve_HEADER
#define LMT_curve_HEADER

#include "point.h"

namespace LMT {

template<class Carac>
class Curve : public GeometricEntity<Carac,1> {
public:
    typedef typename GeometricEntity<Carac,1>::T T;
    typedef typename GeometricEntity<Carac,1>::Pvec Pvec;
protected:
    Pvec pos_child(unsigned num_child) const {
        return static_cast<const Point<Carac> *>(this->template get_child<1>(num_child).ge)->get_pos();
    }
};

};

#endif // LMT_curve_HEADER
