//
// C++ Interface: volume
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_volume_HEADER
#define LMT_volume_HEADER

#include "surface.h"

namespace LMT {

template<class Carac>
class Volume : public GeometricEntity<Carac,3> {
public:
    typedef typename GeometricEntity<Carac,3>::T T;
    typedef typename GeometricEntity<Carac,3>::Pvec Pvec;
    typedef typename GeometricEntity<Carac,3>::MNVI MNVI;
    typedef typename GeometricEntity<Carac,3>::TNode TNode;
    static const unsigned dim = Carac::dim;
 
    // Pvec pos_child(unsigned num_child) const { return static_cast<const Point<Carac> *>(this->template get_child<1>(num_child).ge)->pos; }
protected:
    virtual void read_xml_data_(const XmlNode &sn) throw(IoException) {}
    virtual void update_repr_(T ang_prec) {
        // children data
        Mesh<MeshCaracAllNvi<dim,T> > skin;

        for(unsigned i=0;i<this->template nb_children<1>();++i) skin.append( this->template get_child<1>(i).ge->repr );
        for(unsigned i=0;i<this->template nb_children<2>();++i) skin.append( this->template get_child<2>(i).ge->repr );
        for(unsigned i=0;i<this->template nb_children<3>();++i) skin.append( this->template get_child<3>(i).ge->repr );
        
        //DisplayParaview dp;
        //dp.add_mesh(skin);
        //dp.exec();
        
        // delaunay
        Vec<TNode *> new_nodes;
        make_delaunay_triangulation<3>( this->repr, skin, new_nodes );

        // node correspondance    
        unsigned cpt = 0;
        this->template make_node_correspondance<1>(cpt,new_nodes);
        this->template make_node_correspondance<2>(cpt,new_nodes);
        this->template make_node_correspondance<3>(cpt,new_nodes);
    }
};

///
template<class Carac>
void register_std_geom_ent(const Number<3> &n) {
    factory.reg<Volume<Carac>,GeomSet<Carac>,void>("volume","volume");
}

};

#endif // LMT_volume_HEADER
