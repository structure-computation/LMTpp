//
// C++ Interface: geometricentity
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_geometricentity_HEADER
#define LMT_geometricentity_HEADER

#include "mesh/mesh.h"
#include "geometry/meshcaracforgeomset.h"
#include <string>

namespace LMT {

template<class Carac> class GeomSet;

template<class Carac>
class GeometricEntityAncestor {
public:
};

/*!
    Cette classe sert à faire de la CAO, par exemple coupe de sphère ou définir des surfaces paramétriques.

    \keyword Visualisation/3D
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/
template<class Carac,unsigned _nb_var_inter_>
class GeometricEntity : public GeometricEntityAncestor<Carac> {
public:
    static const unsigned nb_var_inter = _nb_var_inter_;
    static const unsigned dim = Carac::dim;
    typedef typename Carac::T T;
    typedef typename Carac::template TData<nb_var_inter> TData;
    typedef Mesh<Meshcaracforgeomset<dim,nb_var_inter,T> > TM;
    typedef typename TM::TNode TNode;
    typedef Vec<T,dim> Pvec;
    typedef Vec<T,nb_var_inter> VecNVI;
    typedef Vec<Pvec,dim> DerCoords;
    typedef Mat<T,Sym<nb_var_inter> > MNVI;

    GeometricEntity() {
        repr_should_be_updated = true;
    }
    virtual ~GeometricEntity() {}
private:
    struct UpdateRepr { template<class TC> void operator()(TC &child,T ang_prec) const { child.ge->update_repr(ang_prec); } };
public:
    /**
        assert if repr_should_be_updated. clear repr. call update_repr for each children
    */
    virtual void update_repr(T angular_prec_in_degrees) {
        if ( repr_should_be_updated ) {
            repr.free();
            apply( children, UpdateRepr(), angular_prec_in_degrees );
            update_repr_( angular_prec_in_degrees );
            repr_should_be_updated = false;
        }
    }
    virtual void read_xml_data(const XmlNode &sn,GeomSet<Carac> *gs) throw(IoException) {
        ref = sn.get_attribute("ref");
        // children
        if ( sn.has_attribute("children") ) {
            std::istringstream is( sn.get_attribute("children") );
            std::string t;
            while ( is >> t ) {
                if ( ! append_child_with_ref(t,gs,Number<0>()) )
                    throw IoException(t+" is not a valid point.");
            }
        }
        //
        read_xml_data_(sn);
        repr_should_be_updated = true;
    }
    
    ///
    template<unsigned nvi_to_subs_m1> struct Child {
        GeometricEntity<Carac,nb_var_inter-nvi_to_subs_m1-1> *ge;
        unsigned num_this;
    };
    ///
    struct ChildName {
        template<unsigned nvi_to_subs_m1,unsigned inner=0> struct SubType { typedef Splitted<Child<nvi_to_subs_m1>,8> T; };
        template<unsigned inner> struct SubType<(int)nb_var_inter,inner> { typedef void T; };
    };
    ///
    template<unsigned nvi_to_add_m1> struct Parent {
        typedef GeometricEntity<Carac,nb_var_inter+nvi_to_add_m1+1> GE;
        GE *ge;
        /// proj_nodes[node in this] = node in child (allowing to get projection data)
        Vec<typename Mesh<Meshcaracforgeomset<dim,nb_var_inter+nvi_to_add_m1+1,T> >::TNode *> proj_nodes;
        unsigned num_this;
    };
    ///
    struct ParentName {
        template<unsigned nvi_to_add_m1,unsigned inner=0> struct SubType { typedef Parent<nvi_to_add_m1> T; };
        template<unsigned inner> struct SubType<(int)(dim-nb_var_inter),inner> { typedef void T; };
    };
    ///
    TM repr;
    ///
    std::string ref;
    ///
    Vec<Heterogeneous<ChildName> > children;
    ///
    Vec<Heterogeneous<ParentName> > parents;
    ///
    TData data;

    /// TCH is assumed to be a geometric entity
    template<unsigned nvi_child> void append_child(GeometricEntity<Carac,nvi_child> *child) {
        static const unsigned nvi_to_subs_m1 = nb_var_inter - nvi_child - 1;
        Child<nvi_to_subs_m1> ch;
        ch.ge = child;
        ch.num_this = child->append_parent(this);
        children.push_back(ch);
    }
    ///
    template<unsigned nvi_to_subs> unsigned nb_children() const { return children.size(Number<nvi_to_subs-1>()); }
    ///
    template<unsigned nvi_to_subs> Child<nvi_to_subs-1> &get_child(unsigned i) { return children.data(i,Number<nvi_to_subs-1>()); }
    template<unsigned nvi_to_subs> const Child<nvi_to_subs-1> &get_child(unsigned i) const { return children.data(i,Number<nvi_to_subs-1>()); }
    ///
    template<unsigned nvi_to_add> unsigned nb_parents() const { return parents.size(Number<nvi_to_add-1>()); }
    ///
    template<unsigned nvi_to_add> Parent<nvi_to_add-1> &get_parent(unsigned i) { return parents.data(i,Number<nvi_to_add-1>()); }
    template<unsigned nvi_to_add> const Parent<nvi_to_add-1> &get_parent(unsigned i) const { return parents.data(i,Number<nvi_to_add-1>()); }
    ///
    std::string get_ref() const { return ref; }
protected:
    virtual void update_repr_(T angular_prec_in_degrees) = 0;
    virtual void read_xml_data_(const XmlNode &sn) throw(IoException) = 0;
    /// put data in node if nb_var_inter != dim
    void set_local_coords( TNode *node, const VecNVI &a, const DerCoords &der_coords, const MNVI &c ) {
        set_local_coords_( node, a, der_coords, c, Number<dim-nb_var_inter>() );
    }
    /// basic node correspondance
    template<unsigned nvi> void make_node_correspondance(unsigned &cpt,Vec<TNode *> &new_nodes) {
        for(unsigned i=0;i<this->template nb_children<nvi>();++i) {
            Vec<TNode *> &pr = this->template get_child<nvi>(i).ge->template get_parent<nvi>( this->template get_child<nvi>(i).num_this ).proj_nodes;
            pr.free();
            for( unsigned j=0;j<this->template get_child<nvi>(i).ge->repr.node_list.size();++j,++cpt)
                pr.push_back( new_nodes[cpt] );
        }
    }
private:    
    void set_local_coords_( TNode *node, const VecNVI &a, const DerCoords &der_coords, const MNVI &c, const Number<0> &nn ) {}
    template<unsigned n> void set_local_coords_( TNode *node, const VecNVI &a, const DerCoords &der_coords, const MNVI &c, const Number<n> &nn ) {
        node->local_coords = a;
        node->der_coords = der_coords;
        node->curvature = c;
    }
    template<unsigned nvi_parent> unsigned append_parent(GeometricEntity<Carac,nvi_parent> *parent) {
        static const unsigned nvi_to_add_m1 = nvi_parent-nb_var_inter-1;
        unsigned res = parents.size(Number<nvi_to_add_m1>());
        Parent<nvi_to_add_m1> par;
        par.ge = parent;
        par.num_this = parent->template nb_children<nvi_parent-nb_var_inter>();
        parents.push_back(par);
        return res;
    };
    template<unsigned n> bool append_child_with_ref(const std::string &t,GeomSet<Carac> *gs,const Number<n> &nn) {
        GeometricEntity<Carac,n> *p = gs->template get_geom_ent_with_ref<n>(t);
        if ( p ) {
            append_child( p );
            return true;
        }
        return append_child_with_ref(t,gs,Number<n+1>());
    }
    bool append_child_with_ref(const std::string &t,GeomSet<Carac> *gs,const Number<nb_var_inter> &nn) { return false; }
    bool repr_should_be_updated;
    template<class C,unsigned nvi> friend class GeometricEntity;
};

};

#endif // LMT_geometricentity_HEADER
