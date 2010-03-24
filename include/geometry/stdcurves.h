//
// C++ Interface: stdcurves
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_stdcurves_HEADER
#define LMT_stdcurves_HEADER

#include "curve.h"

namespace LMT {

/**
    Line defined by two points
*/
template<class Carac>
class Line : public Curve<Carac> {
public:
    typedef typename Curve<Carac>::T T;
    typedef typename Curve<Carac>::Pvec Pvec;
    typedef Vec<T,2> T2;
    typedef typename Curve<Carac>::TNode TNode;
    static const unsigned dim = Carac::dim;
    
    typedef typename Curve<Carac>::VecNVI VecNVI;
    typedef typename Curve<Carac>::DerCoords DerCoords;
    typedef typename Curve<Carac>::MNVI MNVI;
    
    Line() {}
protected:
    virtual void update_repr_(T ang_prec) {
        update_line_data();
        
        // add nodes
        TNode *nnodes[2];
        add_no( &nnodes[0], P[0], 0.0, Number<dim>() );
        add_no( &nnodes[1], P[1],   l, Number<dim>() );
            
        // add element
        this->repr.add_element( Bar(), DefaultBehavior(), nnodes[0], nnodes[1] );
            
        // node correspondance
        Vec<TNode *> *node_cor[] = {
            &this->template get_child<1>(0).ge->template get_parent<1>( this->template get_child<1>(0).num_this ).proj_nodes,
            &this->template get_child<1>(1).ge->template get_parent<1>( this->template get_child<1>(1).num_this ).proj_nodes,
        };
        node_cor[0]->resize(1); node_cor[1]->resize(1);
        (*node_cor[0])[0] = nnodes[0];
        (*node_cor[1])[0] = nnodes[1];
    }
    virtual void read_xml_data_(const XmlNode &sn) throw(IoException) {
        if ( this->template nb_children<1>()!=2 ) throw IoException("A line must be defined by exactly 2 points.");
    }
private:
    void add_no(TNode **nnode,const Pvec &pos,T lc,const Number<1> &mm) {
        *nnode = this->repr.add_node( pos );
    }
    template<unsigned n> void add_no(TNode **nnode,const Pvec &pos,T lc,const Number<n> &nn) {
        *nnode = this->repr.add_node( pos );
        
        DerCoords der_coords;
        
        der_coords[0] = X;
        if ( dim == 3 ) der_coords[1] = Y;
        der_coords[dim-1] = Z;
        MNVI mn; mn.set(0.0);
        set_local_coords( *nnode, VecNVI(lc), der_coords, mn );
    }
    void update_line_data() {
        DEBUGASSERTWC( this->template nb_children<1>()==2,"A line must be defined by exactly 2 points." );
        P[0] = this->pos_child(0); P[1] = this->pos_child(1);
        Z = P[1]-P[0];
        l = length(Z);
        
        Y = find_orthonormal(Z);
        X = vect_prod(Z,Y);
        Z /= l;
        X /= length(X);
    }
    Pvec P[2],X,Y,Z;
    T l;
};

/**

*/
template<class Carac>
class Circle : public Curve<Carac> {
public:
    typedef typename Curve<Carac>::T T;
    typedef typename Curve<Carac>::Pvec Pvec;
    typedef Vec<T,2> T2;
    typedef typename Curve<Carac>::TNode TNode;
    static const unsigned dim = Carac::dim;
    
    typedef typename Curve<Carac>::VecNVI VecNVI;
    typedef typename Curve<Carac>::DerCoords DerCoords;
    typedef typename Curve<Carac>::MNVI MNVI;
    
    Circle():closed(false) {}
    
    bool closed;
protected:
    virtual void update_repr_(T ang_prec) {
        update_circle_data();

        unsigned nb_nodes[3];
        nb_nodes[0] = (unsigned)( (a1)*180.0/M_PI / ang_prec + 1.0 );
        nb_nodes[1] = (unsigned)( (a2-a1)*180.0/M_PI / ang_prec + 1.0 );
        nb_nodes[2] = (unsigned)( (2.0*M_PI-a2)*180.0/M_PI / ang_prec + 1.0 );
        unsigned tot_nb_nodes = nb_nodes[0] + nb_nodes[1] + closed * nb_nodes[2] + (closed==false);
        
        // add nodes
        Vec<TNode *> nnodes; nnodes.resize( tot_nb_nodes );
        unsigned cpt = 0;
        for(unsigned i=0;i<nb_nodes[0];++i)
            add_no( nnodes, cpt, i * a1 / nb_nodes[0], Number<dim>() );
        for(unsigned i=0;i<nb_nodes[1];++i)
            add_no( nnodes, cpt, a1 + i * (a2-a1) / nb_nodes[1], Number<dim>() );
        if ( closed==false )
            add_no( nnodes, cpt, a2, Number<dim>() );
        else
            for(unsigned i=0;i<nb_nodes[2];++i)
                add_no( nnodes, cpt, a2 + i * (2.0*M_PI-a2) / nb_nodes[2], Number<dim>() );
        // add element
        for(unsigned i=1;i<tot_nb_nodes;++i)
            this->repr.add_element( Bar(), DefaultBehavior(), nnodes[i], nnodes[i-1] );
        if ( closed )
            this->repr.add_element( Bar(), DefaultBehavior(), nnodes[tot_nb_nodes-1], nnodes[0] );
            
        // node correspondance
        unsigned num_par_of_this_in_children[] = {
            this->template get_child<1>(0).num_this,
            this->template get_child<1>(1).num_this,
            this->template get_child<1>(2).num_this
        };
        Vec<TNode *> *node_cor[] = {
            &this->template get_child<1>(0).ge->template get_parent<1>(num_par_of_this_in_children[0]).proj_nodes,
            &this->template get_child<1>(1).ge->template get_parent<1>(num_par_of_this_in_children[1]).proj_nodes,
            &this->template get_child<1>(2).ge->template get_parent<1>(num_par_of_this_in_children[2]).proj_nodes
        };
        node_cor[0]->resize(1); node_cor[1]->resize(1); node_cor[2]->resize(1);
        (*node_cor[0])[0] = nnodes[0];
        (*node_cor[1])[0] = nnodes[nb_nodes[0]];
        (*node_cor[2])[0] = nnodes[nb_nodes[0]+nb_nodes[1]];
    }
    virtual void read_xml_data_(const XmlNode &sn) throw(IoException) {
        if ( this->template nb_children<1>()!=3 ) throw IoException("A circle must be defined by exactly 3 points.");
        sn.get_attribute("closed",closed,1);
    }
private:
    void add_no(Vec<TNode *> &nnodes,unsigned &cpt,T a,const Number<1> &mm) {
        nnodes[cpt++] = this->repr.add_node( C+R*X*cos(a)+R*Y*sin(a) );
    }
    template<unsigned n> void add_no(Vec<TNode *> &nnodes,unsigned &cpt,T a,const Number<n> &nn) {
        nnodes[cpt] = this->repr.add_node( C+R*X*cos(a)+R*Y*sin(a) );
        
        DerCoords der_coords;
        der_coords[0] = X*cos(a) + Y*sin(a);
        der_coords[dim-1] = -X*sin(a) + Y*cos(a);
        if ( dim == 3 ) {
            der_coords[1] = vect_prod(der_coords[dim-1],der_coords[0]);
            der_coords[1] /= length(der_coords[1]);
        }
        MNVI mn; mn.set(1.0/R);
        set_local_coords( nnodes[cpt], VecNVI(a*R), der_coords, mn );
        
        ++cpt;
    }
    void update_circle_data() {
        DEBUGASSERT( this->template nb_children<1>()==3 );
        P[0] = this->pos_child(0); P[1] = this->pos_child(1); P[2] = this->pos_child(2);
        C = getCenterOfCircumCircle(P[0],P[1],P[2]);
        X = P[0]-C;
        R = length(X);
        X /= R;
        if ( std::abs(dot(X,P[1]-C))<std::abs(dot(X,P[2]-C)) ) Y = P[1]-C;
        else                                                   Y = P[2]-C;
        Y -= dot(Y,X) * X;
        Y /= length(Y);
        
        T2 p1( dot(P[1]-C, X), dot(P[1]-C, Y) );
        T2 p2( dot(P[2]-C, X), dot(P[2]-C, Y) );
        a1 = acos( p1[0]/length(p1,1e-40) );
        if ( p1[1]<0.0 ) a1 = 2.0 * M_PI - a1; // a1 \in [-pi,pi]
        a2 = acos( p2[0]/length(p2,1e-40) );
        if ( p2[1]<0.0 ) a2 = 2.0 * M_PI - a2;
        if ( a1 > a2 ) {
            Y = -Y;
            a1 = 2.0 * M_PI - a1;
            a2 = 2.0 * M_PI - a2;
        }
    }
    Pvec P[3],C,X,Y;
    T R,a1,a2;
};

/**
    \relates LMT::GeomSet
*/
template<class Carac>
void register_std_geom_ent(const Number<1> &n) {
    factory.reg<Circle<Carac>,GeomSet<Carac>,void>("circle","curve");
    factory.reg<Line<Carac>,GeomSet<Carac>,void>("line","curve");
}

};

#endif // LMT_stdcurves_HEADER
