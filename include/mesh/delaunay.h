//
// C++ Interface: delaunay
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_delaunay_HEADER
#define LMT_delaunay_HEADER

#include "mesh.h"
#include "isinteriorofmesh.h"

namespace LMT {

namespace LMTPRIVATE {
    template<unsigned nvi> struct TypeElemForNvi {};
    template<> struct TypeElemForNvi<2> { typedef Triangle TE; };
    template<> struct TypeElemForNvi<3> { typedef Tetra TE; };
    
    template<class TM>
    void make_box(const Number<2> &n,TM &m,const typename TM::Pvec &xmin,const typename TM::Pvec &xmax) {
        typedef typename TM::Pvec Pvec;
        unsigned nn = m.node_list.size();
        for(unsigned i=0;i<4;++i)
            m.add_node( xmin + (xmax-xmin) * Pvec::binary_decomp(i) );
        
        m.add_element(Triangle(),DefaultBehavior(),nn+0,nn+1,nn+2);
        m.add_element(Triangle(),DefaultBehavior(),nn+1,nn+3,nn+2);
    }
    template<class TM>
    void make_box(const Number<3> &n,TM &m,const typename TM::Pvec &xmin,const typename TM::Pvec &xmax) {
        typedef typename TM::Pvec Pvec;
        unsigned nn = m.node_list.size();
        for(unsigned i=0;i<8;++i)
            m.add_node( xmin + (xmax-xmin) * Pvec::binary_decomp(i) );
        
        m.add_element(Tetra(),DefaultBehavior(),nn+3,nn+5,nn+6,nn+7);
        m.add_element(Tetra(),DefaultBehavior(),nn+0,nn+4,nn+5,nn+6);
        m.add_element(Tetra(),DefaultBehavior(),nn+0,nn+3,nn+5,nn+6);
        m.add_element(Tetra(),DefaultBehavior(),nn+0,nn+1,nn+3,nn+5);
        m.add_element(Tetra(),DefaultBehavior(),nn+0,nn+2,nn+3,nn+6);
    }
    template<class TM,class CDC,class RDC,unsigned nvi>
    struct RemoveEnglobingElements {
        typedef typename TM::TNode TNode;
        typedef typename TNode::Pvec Pvec;
        struct Face {
            bool operator==(const Face &f) const {
                for(unsigned i=0;i<nvi;++i)
                    if ( nodes[i] != f.nodes[i] )
                        return false;
                return true;
            }
            TNode *nodes[nvi+1];
        };
        template<class TE> bool operator()(TE &e) {
            bool res = ( length(pos-m->elem_list.get_data(*C,e)) > m->elem_list.get_data(*R,e)*(1.0-1.0e-6) );
            if ( res==false ) {
                for(unsigned i=0;i<nvi+1;++i) { // the number of node we do not take for this face
                    Face f;
                    for(unsigned j=0,cpt=0;j<nvi+1;++j)
                        if ( j!=i )
                            f.nodes[cpt++] = e.node(j);
                    std::sort( f.nodes, f.nodes+nvi );
                    surrounding_faces.push_back( f );
                }
            }
            return not res;
        }
        Pvec pos;
        Vec<Face> surrounding_faces;
        TM *m;
        const CDC *C;
        const RDC *R;
    };
    template<class TMSkin,unsigned nvi_to_use>
    struct RemoveExtTri {
        typedef typename TMSkin::Pvec Pvec;
        template<class TE> bool operator()(const TE &e) const {
            for(unsigned i=0;i<TE::nb_var_inter;++i)
                for(unsigned j=0;j<TE::nb_nodes;++j)
                    if ( xmin[i]==e.node(j)->pos[i] || xmax[i]==e.node(j)->pos[i] )
                        return true;
            if ( remove_ext==false )
                return false;
            Pvec C = center(e);
            return not is_in_interior_of_mesh<nvi_to_use>(*skin,C);
        }
        const TMSkin *skin;
        typename TMSkin::Pvec xmin,xmax;
        bool remove_ext;
    };
    struct SetCC {
        template<class TE,class TM,class C,class R> void operator()(const TE &e,TM &m,C &c,R &r) const {
            update_circum_center( e, m.elem_list.get_data(c,e), m.elem_list.get_data(r,e) );
        }
    };
};
/*!
    Add delaunay points to mesh already constitued
*/
template<unsigned nvi,class TM,class Pvec>
void add_delaunay_points(TM &m,const Vec<Pvec> &new_points) {
    typedef typename TM::TNode TNode;
    
    // preparation of circum_center and circum_radius lists
    typedef DynamicData<typename TM::Pvec,TM::TElemList::nb_elem_type> CDC;
    typedef DynamicData<double,TM::TElemList::nb_elem_type> RDC;
    CDC C("circum_center");
    RDC R("circum_radius");
    m.elem_list.reg_dyn(&C);
    m.elem_list.reg_dyn(&R);
    
    apply( m.elem_list, LMTPRIVATE::SetCC(), m, C, R );
    
    Vec<typename TM::TNode *> new_nodes;
    for(unsigned i=0;i<new_points.size();++i)
        new_nodes.push_back( m.add_node(new_points[i]) );
    
    // make basic delaunay triangulation    
    LMTPRIVATE::RemoveEnglobingElements<TM,CDC,RDC,nvi> fee;
    fee.m = &m;
    fee.C = &C;
    fee.R = &R;

    for(unsigned ni=0;ni<new_points.size();++ni) {
        fee.surrounding_faces.resize( 0 );
        fee.pos = new_points[ni];
        m.remove_elements_if(fee);
        TNode *nn = new_nodes[ ni ];
        for(unsigned i=0,j;i<fee.surrounding_faces.size();++i) {
            for(j=0;j<fee.surrounding_faces.size();++j)
                if ( i!=j && fee.surrounding_faces[i] == fee.surrounding_faces[j] )
                    break;
            if ( j==fee.surrounding_faces.size() ) { // this face is unique
                fee.surrounding_faces[i].nodes[nvi] = nn;
                if ( length( vect_prod(
                        fee.surrounding_faces[i].nodes[1]->pos - fee.surrounding_faces[i].nodes[0]->pos,
                        fee.surrounding_faces[i].nodes[2]->pos - fee.surrounding_faces[i].nodes[0]->pos
                        ) ) < 1e-1 * length( fee.surrounding_faces[i].nodes[1]->pos - fee.surrounding_faces[i].nodes[0]->pos )
                   )
                    continue;
                typename TM::template TElem<typename LMTPRIVATE::TypeElemForNvi<nvi>::TE,DefaultBehavior>::TE *ne =
                    m.add_element(
                        typename LMTPRIVATE::TypeElemForNvi<nvi>::TE(),
                        DefaultBehavior(),
                        fee.surrounding_faces[i].nodes
                    );
                m.elem_list.synchronize_all_dyn();
                update_circum_center( *ne, m.elem_list.get_data(C,*ne), m.elem_list.get_data(R,*ne) );
            }
        }
    }
    
    // constraints
    m.elem_list.unreg_dyn(&C);
    m.elem_list.unreg_dyn(&R);
    //m.remove_unused_nodes();
    
    m.signal_connectivity_change();
}

/*!
   Append to m a delaunay triangulation using NodalElements, Bar and Triangles (if nvi==3) of skin.
   nvi==2 -> uses triangles
   nvi==3 -> uses tetrahedra.
   Data of nodes in skin is transfered in m.
   
   If dim>nvi, pos[i] such as i>nvi is assumed to be constant.
   
   \relates Mesh
*/
template<unsigned nvi,class TM,class TMskin>
void make_delaunay_triangulation(TM &m,const TMskin &skin,Vec<typename TM::TNode *> &new_nodes,bool remove_ext=true) {
    typedef typename TMskin::Pvec Pvec;
    typedef typename TM::TNode TNode;
    
    // get nodes of skin
    unsigned nb_new_nodes = 0;
    new_nodes.free();
    for(unsigned i=0;i<skin.node_list.size();++i) {
        unsigned j=0;
        for(;j<i && length(skin.node_list[j].pos-skin.node_list[i].pos)>1e-9;++j);
        if ( j == i ) {
            TNode *n = m.add_node();
            DM::copy( skin.node_list[i], *n );
            new_nodes.push_back( n );
            ++nb_new_nodes;
        }
        else {
            new_nodes.push_back( new_nodes[j] );
        }
    }
    //m.append_nodes_of( skin, new_nodes );

    // get surrounding coords    
    Pvec tmxmin,tmxmax;
    //get_min_max( m.node_list, ExtractDM<pos_DM>(), tmxmin, tmxmax );
    get_min_max( skin.node_list, ExtractDM<pos_DM>(), tmxmin, tmxmax );
    
    Pvec difx = 5.0*max( tmxmax - tmxmin ) * Pvec::binary_decomp( (int)pow(2,nvi)-1 );
    Pvec xmin = tmxmin - difx, xmax = tmxmax + difx;
    LMTPRIVATE::make_box(Number<nvi>(),m,xmin,xmax);

    // preparation of circum_center and circum_radius lists
    typedef DynamicData<Pvec,TM::TElemList::nb_elem_type> CDC;
    typedef DynamicData<double,TM::TElemList::nb_elem_type> RDC;
    CDC C("circum_center");
    RDC R("circum_radius");
    m.elem_list.reg_dyn(&C);
    m.elem_list.reg_dyn(&R);

    apply( m.elem_list, LMTPRIVATE::SetCC(), m, C, R );

    // make basic delaunay triangulation    
    LMTPRIVATE::RemoveEnglobingElements<TM,CDC,RDC,nvi> fee;
    fee.m = &m;
    fee.C = &C;
    fee.R = &R;

    for(unsigned ni=0;ni<nb_new_nodes;++ni) {
        fee.surrounding_faces.resize( 0 );
        fee.pos = m.node_list[ni].pos;
        m.remove_elements_if(fee);
        for(unsigned i=0,j;i<fee.surrounding_faces.size();++i) {
            for(j=0;j<fee.surrounding_faces.size();++j)
                if ( i!=j && fee.surrounding_faces[i] == fee.surrounding_faces[j] )
                    break;
            if ( j==fee.surrounding_faces.size() ) { // this face is unique
                fee.surrounding_faces[i].nodes[nvi] = &m.node_list[ni];
                typename TM::template TElem<typename LMTPRIVATE::TypeElemForNvi<nvi>::TE,DefaultBehavior>::TE *ne =
                    m.add_element(
                        typename LMTPRIVATE::TypeElemForNvi<nvi>::TE(),
                        DefaultBehavior(),
                        fee.surrounding_faces[i].nodes
                    );
                m.elem_list.synchronize_all_dyn();
                update_circum_center( *ne, m.elem_list.get_data(C,*ne), m.elem_list.get_data(R,*ne) );
            }
        }
    }
    
    // constraints
    //m.signal_connectivity_change();
    //m.update_node_neighbours();
    
    // remove exterior triangles
    LMTPRIVATE::RemoveExtTri<TMskin,nvi-1> ret;
    ret.skin = &skin; ret.xmin = xmin; ret.xmax = xmax; ret.remove_ext = remove_ext;
    m.remove_elements_if(ret);
    m.remove_unused_nodes();
    
    m.elem_list.unreg_dyn(&C);
    m.elem_list.unreg_dyn(&R);
    
    m.signal_connectivity_change();
}

};

#endif // LMT_delaunay_HEADER
