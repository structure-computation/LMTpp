//
// C++ Interface: point
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_point_HEADER
#define LMT_point_HEADER

#include "geometricentity.h"

namespace LMT {

template<class Carac>
class Point : public GeometricEntity<Carac,0> {
public:
    typedef typename GeometricEntity<Carac,0>::T T;
    typedef typename GeometricEntity<Carac,0>::Pvec Pvec;

    const Pvec &get_pos() const { return pos; }
protected:
    virtual void update_repr_(T angular_prec_in_degrees) {
        this->repr.add_element(NodalElement(),DefaultBehavior(),this->repr.add_node(pos));
    }
    virtual void read_xml_data_(const XmlNode &sn) throw(IoException) { sn.get_attribute_with_unit("pos","m",pos); }
    Pvec pos;
};

///
template<class Carac>
void register_std_geom_ent(const Number<0> &n) {
    factory.reg<Point<Carac>,GeomSet<Carac>,void>("point","point");
}

};

#endif // LMT_point_HEADER
