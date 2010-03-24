//
// C++ Interface: stdsurfaces
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_stdsurfaces_HEADER
#define LMT_stdsurfaces_HEADER

#include <algorithm>
#include "surface.h"

namespace LMT {

/**
    A planar surface delimited by curves.
*/
template<class Carac>
class Plane : public Surface<Carac> {
public:
    static const unsigned dim = Carac::dim;
    typedef typename GeometricEntity<Carac,2>::Pvec Pvec;
    typedef typename GeometricEntity<Carac,2>::MNVI MNVI;
    typedef typename Surface<Carac>::T T;
    virtual void get_2d_proj(Pvec &p) const { p -= O; p.assign_and_complete_with_last( dot(p,X), dot(p,Y), 0.0 ); }
    virtual void get_nd_proj(Pvec &p) const { p = O + X * p[0] + Y * p[1] + Z * p[2*(dim>=3)] * (dim>=3); }
    virtual void get_curvature_and_axes(const Pvec &p,MNVI &curvature,LMT::Vec<LMT::Vec<T,dim>,dim> &der_coords) const {
        curvature.set(0.0);
        der_coords[0] = X;
        der_coords[1] = Y;
        der_coords[dim-1] = Z;
    }
protected:
    virtual void read_xml_data_(const XmlNode &sn) throw(IoException) {
        if ( this->children.size()==0 ) return;
        Vec<Pvec> some_points;
        for(unsigned i=0;i<this->template nb_children<1>();++i)
            for(unsigned j=0;j<this->template get_child<1>(i).ge->template nb_children<1>();++j)
                some_points.push_back( static_cast<const Point<Carac> *>(this->template get_child<1>(i).ge->template get_child<1>(j).ge)->get_pos() );
        
        O = mean( some_points );
        for(unsigned i=0;i<some_points.size();++i)
            some_points[i] -= O;
        
        X = max_element( some_points, LengthOp() );
        X /= length(X);
        Y = min_element( some_points, AbsDotNormalizedOp<2>(), X );
        Y -= dot(X,Y) * X;
        Y /= length(Y);
        Z = vect_prod(X,Y);
    }
    Pvec O,X,Y,Z;
};

/**
    A conical surface delimited by curves. Assumed to be in 3D space
*/
template<class Carac>
class Cone : public Surface<Carac> {
public:
    static const unsigned dim = Carac::dim;
    typedef typename GeometricEntity<Carac,2>::Pvec Pvec;
    typedef typename GeometricEntity<Carac,2>::MNVI MNVI;
    typedef typename Carac::T T;
    virtual void get_2d_proj(Pvec &p) const {
        p -= O;
        Vec<T,2> rc( dot(p,X), dot(p,Y) );
        T a = acos( rc[0]/length(rc,1e-40) ) / (2.0*M_PI);
        if ( rc[1]<0.0 ) a = 1.0 - a;
        if ( a > 1.0-1e-10 ) a = 0.0;
        p.assign_and_complete_with_last( dot(p,Z), a, 0.0 );
    }
    virtual void get_nd_proj(Pvec &p) const {
        T r = R + draft * p[0];
        T a = 2.0 * M_PI * p[1];
        p = O + Z * p[0] + r * ( X * cos(a) + Y * sin(a) ); 
    }
    virtual void set_2d_proj_in_metric_space(Pvec &p) const {
        p[1] *= 2.0 * M_PI * R;
    }
    virtual bool y_periodic() const { return true; }
    virtual void get_curvature_and_axes(const Pvec &p,MNVI &curvature,LMT::Vec<LMT::Vec<T,dim>,dim> &der_coords) const {
        curvature(0,0) = 1.0/( (R + draft * dot( p-O, Z )) * (1.0+draft*draft) );
        curvature(0,1) = 0; curvature(1,1) = 0; 
        der_coords[0] = X;
        der_coords[1] = Y;
        der_coords[2] = p-O - dot(p-O,Z)*Z;
        der_coords[2] /= length(der_coords[2]);
    }
protected:
    virtual void read_xml_data_(const XmlNode &sn) throw(IoException) {
        sn.get_attribute_with_unit("O","m",O);
        sn.get_attribute_with_unit("X","1",X); X /= length(X);
        sn.get_attribute_with_unit("Y","1",Y); Y /= length(Y);
        Z = vect_prod(X,Y); Z /= length(Z);
        sn.get_attribute_with_unit("draft","1",draft,0.0);
        sn.get_attribute_with_unit("R","m",R);
    }
    typename Curve<Carac>::Pvec O,X,Y,Z;
    double draft,R;
};


/**
    \relates LMT::GeomSet
*/
template<class Carac>
void register_std_geom_ent(const Number<2> &n) {
    factory.reg<Plane<Carac>,GeomSet<Carac>,void>("plane","surface");
    factory.reg<Cone<Carac>,GeomSet<Carac>,void>("cone","surface");
}

};

#endif // LMT_stdsurfaces_HEADER
