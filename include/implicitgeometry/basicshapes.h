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
#ifndef LMT_BASIC_SHAPES_HEADER
#define LMT_BASIC_SHAPES_HEADER

#include "shapedeclaration.h"
#include "common/simplevector.h"
#include "common/smartptr.h"

namespace LMT {


///
template<unsigned dim,class T=double>
class Sphere : public ShapeNoChild<dim,T> {
public:
    typedef typename Shape<dim,T>::Pvec Pvec;
    typedef typename Shape<dim,T>::TPen TPen;
    Sphere() {}
    Sphere(Pvec c,T r) { C = c; R = r; }
    virtual void get_penetration(const Pvec *points,TPen *res,unsigned nb_points,T offset=0.0) const {
        for(unsigned i=0;i<nb_points;++i) {
            Pvec CP( points[i] - C );
            T l = length(CP);
            res->dist = l - R - offset;
            res->normal = CP/l;
            ++res;
        }
    }
    virtual void get_dim_min_max(Pvec &dim_min,Pvec &dim_max) const { dim_min = C - R; dim_max = C + R; }
    virtual std::string name() const { return std::string("Sphere_")+(char)('0'+dim); }
protected:
    Pvec C;
    T R;
};

///
template<unsigned dim,class T=double>
class Intersection : public Shape<dim,T> {
public:
    typedef typename Shape<dim,T>::Pvec Pvec;
    typedef typename Shape<dim,T>::TPen TPen;
    
    Intersection() {}
    Intersection(SmartPtr<Shape<dim,T> > f1,SmartPtr<Shape<dim,T> > f2) { lst[0] = f1; lst[1] = f2; }
    
    virtual void get_penetration(const Pvec *points,TPen *res,unsigned nb_points,T offset=0.0) const {
        Vec<TPen> pen[2];
        pen[0].resize(nb_points); pen[1].resize(nb_points);
        lst[0]->get_penetration(points,pen[0].begin(),nb_points,offset);
        lst[1]->get_penetration(points,pen[1].begin(),nb_points,offset);
        for(unsigned i=0;i<nb_points;++i) {
            T h0 = heavyside(-pen[0][i].dist), h1 = heavyside(-pen[1][i].dist);
            T mdi = heavyside(pen[0][i].dist-pen[1][i].dist);
            res->dist = 
                h0*h1*(mdi*pen[0][i].dist+(1-mdi)*pen[1][i].dist) +
                h0*(1-h1)*pen[1][i].dist +
                (1-h0)*h1*pen[0][i].dist +
                (1-h0)*(1-h1)*sqrt(pow(pen[0][i].dist,2)+pow(pen[1][i].dist,2));
            Pvec sn = pen[0][i].normal+pen[1][i].normal;
            sn /= length(sn);
            res->normal =
                h0*h1*(mdi*pen[0][i].normal+(1-mdi)*pen[1][i].normal) +
                h0*(1-h1)*pen[1][i].normal +
                (1-h0)*h1*pen[0][i].normal +
                (1-h0)*(1-h1)*sn;
            ++res;
        }
    }
    virtual void get_dim_min_max(Pvec &dim_min,Pvec &dim_max) const {
        lst[0]->get_dim_min_max(dim_min,dim_max);
        Pvec dm,dM;
        lst[1]->get_dim_min_max(dm,dM);
        dim_min = min(dim_min,dm); dim_max = max(dim_max,dM);
    }
    void set_param(Pvec c,T r) { C = c; R = r; }
    virtual std::string name() const { return std::string("Intersection_")+(char)('0'+dim); }
    virtual unsigned nb_children() const { return 2; }
    virtual Shape<dim,T> *children(unsigned i) { return lst[i].ptr(); }
    virtual const Shape<dim,T> *children(unsigned i) const { return lst[i].ptr(); }
protected:
    SmartPtr<Shape<dim,T> > lst[2];
};

};

#endif // LMT_BASIC_SHAPES_HEADER

