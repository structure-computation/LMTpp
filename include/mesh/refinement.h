//
// C++ Interface: refinement
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_refinement_HEADER
#define LMT_refinement_HEADER

#include "mesh.h"
#include "tetra.h"

namespace LMT {

namespace LMTPRIVATE {
    template<class TM,class TMParent,unsigned num_sub_mesh,unsigned max_num_sub_mesh>
    struct Refinment {
        typedef typename TM::TNode TNode;
        typedef Refinment<typename TM::TNext,TMParent,num_sub_mesh+1,max_num_sub_mesh> RNext;
        typedef typename TM::Tpos T;
        typedef DynamicData<TNode *,TM::TElemList::nb_elem_type> TDN;
        
        ///
        Refinment(TMParent *mp):m_parent(mp),cut("cut"),next(mp) {}
        ///
        template<class Op> struct RefineBars {
            template<class TE> void operator()(const TE &e) const {}
            template<class NB,class TN,class TD,unsigned nl> void operator()(Element<Bar,NB,TN,TD,nl> &e) const {
                T val = (*op)(e);
                if ( val == 1 )
                    val = 0.5;
                //
                if ( val > 0 and val < 1 ) {
                    typename TMParent::TNode *nn = m_parent->add_node();
                    m->elem_list.get_data(*cut,e) = nn;
                    
                    std::pair<typename TM::Tpos,const TN *> pond_list[] = {
                        std::pair<typename TM::Tpos,const TN *>( 1-val, e.node(0) ),
                        std::pair<typename TM::Tpos,const TN *>( val  , e.node(1) )
                    };
                    DM::get_ponderation( pond_list, 2, *nn );
                }
                else
                    m->elem_list.get_data(*cut,e) = (TNode *)NULL;
            }
            Op *op;
            TDN *cut;
            TM *m;
            TMParent *m_parent;
        };
        ///
        template<class Op> void update_cut(TM &m,Op &op) {
            // create nodes on center of Bar elements which are considered to be too long
            next.update_cut(m.next,op);
            
            RefineBars<Op> rb;
            rb.op = &op;
            rb.cut = &cut;
            rb.m = &m;
            rb.m_parent = m_parent;

            m.elem_list.synchronize_dyn(&cut);
            apply( m.elem_list, rb );
        }
        ///
        template<class TE> bool div(TE &e,const Number<0> &nnn) { return false; }
        template<class TE> bool div(TE &e,const Number<1> &nnn) {
            TNode *nn[] = { m_parent->elem_list.get_data(cut,e) };
            return divide_element( e, *m_parent, nn );
        }
        template<class TE> bool div(TE &e,const Number<2> &nnn) {
            static const unsigned nb_children = NbChildrenElement<typename TE::NE,1>::res;
            TNode *nn[nb_children];
            for(unsigned i=0;i<nb_children;++i)
                nn[i] = m_parent->template sub_mesh<1>().elem_list.get_data(next.cut, *m_parent->get_children_of(e,Number<1>())[i] );
            return divide_element( e, *m_parent, nn );
        }
        template<class TE> bool div(TE &e,const Number<3> &nnn) {
            static const unsigned nb_children = NbChildrenElement<typename TE::NE,2>::res;
            TNode *nn[nb_children];
            for(unsigned i=0;i<nb_children;++i)
                nn[i] = m_parent->template sub_mesh<2>().elem_list.get_data(next.next.cut, *m_parent->get_children_of(e,Number<2>())[i] );
            return divide_element( e, *m_parent, nn );
        }
        /// 
        template<class TE> bool operator()(TE &e) { return div(e,Number<TE::nb_var_inter>()); }
        
        TMParent *m_parent;
        TDN cut;
        RNext next;
    };
    template<class TM,class TMParent,unsigned max_num_sub_mesh>
    struct Refinment<TM,TMParent,max_num_sub_mesh,max_num_sub_mesh> {
        Refinment(TMParent *mp) {}
        template<class T> void update_cut(const TM &m,T max_length) const {}
    };
};

// struct DispNumber {
//     template<class TE> void operator()(const TE &e) const {
//         for(unsigned i=0;i<TE::nb_nodes;++i)
//             std::cout << e.node(i)->number_in_original_mesh() << " ";
//         std::cout << std::endl;
//     }
// };

/// subdivide each element bar e contained in mesh or sub_meshes such as op(e)==true (true means subdivision). Subdivide parents
template<class TM,class Op>
bool refinement(TM &m,Op &op) {
    // m.update_elem_children();
    m.update_elem_children( Number<TM::nvi-1>() );
    LMTPRIVATE::Refinment<TM,TM,0,TM::dim+1> r(&m);
    r.update_cut(m,op);

    m.elem_list.reg_dyn( &r.cut );
    bool res = m.remove_elements_if( r );
    m.elem_list.unreg_dyn( &r.cut );
    
    m.signal_connectivity_change();
    return res;
}

template<class T>
struct RafinementOpBasedOnLength {
    template<class TE> bool operator()(const TE &e) const { return length(e.node(1)->pos-e.node(0)->pos) > max_length; }
    T max_length;
};

/// subdivide each element bar e such as length(e)>max_length (true means subdivision).
template<class TM,class T>
bool refinement_if_length_sup(TM &m,T max_length) {
    RafinementOpBasedOnLength<T> rl;
    rl.max_length = max_length;
    return refinement(m,rl);
}


};

#endif // LMT_refinement_HEADER
