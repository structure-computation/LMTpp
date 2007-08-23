//
// C++ Interface: %{MODULE}
//
// Description:
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_SHAPE_DECLARATION_HEADER
#define LMT_SHAPE_DECLARATION_HEADER

#include "containers/vec.h"

namespace LMT {

template<unsigned dim,class T> class Shape;

///
template<int dim,class T>
class Penetration {
public:
    T dist;
    Vec<T,dim> normal;
    const Shape<dim,T> *nearest_shape;
};

/**
 */
template<unsigned dim,class T=double>
class Shape {
public:
    typedef Vec<T,dim> Pvec;
    typedef Penetration<dim,T> TPen;

    virtual ~Shape() {}
    
    /// offset will be used only for shapes in the leaves
    virtual void get_penetration(const Pvec *points,TPen *res,unsigned nb_points,T offset=0.0) const = 0;
    
    ///
    virtual void get_dim_min_max(Pvec &dim_min,Pvec &dim_max) const = 0;

/*    /// point proj will be projeted to the surface. pen must have been calculated by get_penetration
    void get_projection(Pvec &proj,TPen &pen,T convergence_criterium=1e-6,T offset=0.0) const {
        using namespace std;
        Pvec old_proj = proj;

        get_penetration(proj,pen,offset);
        pen.dist += offset;
        proj -= pen.normal*pen.dist;
        T old_dist = pen.dist;
        int cpt = 0;
        while (true) {
            if (++cpt>10)
                return;
            get_penetration(proj,pen,offset);
            pen.dist += offset;
            if ( abs(old_dist) < abs(pen.dist) ) {
                proj = (proj+old_proj)/2.0;
                continue;
            }
            proj -= pen.normal*pen.dist;
            if ( abs(pen.dist-old_dist)<convergence_criterium )
                break;
            old_proj = proj;
            old_dist = pen.dist;
        }
    }*/
    ///
    virtual std::string name() const = 0;
    ///
    virtual unsigned nb_children() const = 0;
    ///
    virtual Shape *children(unsigned i) = 0;
    ///
    virtual const Shape *children(unsigned i) const = 0;
};

/// convenience
template<unsigned dim,class T=double>
class ShapeNoChild : public Shape<dim,T> {
    virtual unsigned nb_children() const { return 0; }
    virtual Shape<dim,T> *children(unsigned i) { return (Shape<dim,T> *)NULL; }
    virtual const Shape<dim,T> *children(unsigned i) const { return (const Shape<dim,T> *)NULL; }
};

/// 
template<unsigned dim,class T>
struct CaracMeshShape {
};

};

#endif // LMT_SHAPE_DECLARATION_HEADER

