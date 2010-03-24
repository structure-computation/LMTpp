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
#ifndef LMT_MAKE_PROJ_PERIODIC_HEADER
#define LMT_MAKE_PROJ_PERIODIC_HEADER

#include <algorithm>

namespace LMT {

namespace LMTPRIVATE {
    /**
     @see make_proj_periodic()
     */
    template<class TM> struct Filter_perio_lines {
        typedef typename TM::Pvec Pvec;
        typedef typename TM::TNode TNode;
        template<class TE> bool operator()(TE &e) { return false; }
        template<class BE,class TN,class TD,unsigned nnn> bool operator()(Element<Bar,BE,TN,TD,nnn> &l) {
            Pvec p0( l.node(0)->pos ), p1( l.node(1)->pos );
            if ( fabs( p0[axis] - p1[axis] ) <= 0.5 )
                return false;
            unsigned num_in_edge = 0;
            if ( p0[axis] > p1[axis] ) {
                std::swap(p0,p1);
                num_in_edge = 1;
            }
            p1[axis] -= 1.0;
            Pvec new_pos;
            for(unsigned i=0;i<TM::dim;++i)
                if ( i!=axis )
                    new_pos[i] = p1[i] + (p0[i]-p1[i]) * p1[axis] / ( p1[axis]-p0[axis]+(p1[axis]==p0[axis]) );
            new_pos[axis] = 0.0;
            TNode *n0 = m->add_node( new_pos );
            new_pos[axis] = 1.0;
            TNode *n1 = m->add_node( new_pos );
    
            m->add_element( Bar(), BE(), n0, l.node(num_in_edge) );
            m->add_element( Bar(), BE(), l.node(1-num_in_edge), n1 );
    
            new_nodes_0.push_back(n0);
            new_nodes_1.push_back(n1);
            return true;
        }
        Vec<TNode *> new_nodes_0,new_nodes_1;
        unsigned axis;
        TM *m;
    };
    /**
     @see make_proj_periodic()
     */
    struct Sort_points {
        template<class TN> bool operator()(const TN *p0,const TN *p1) const { return ( p0->pos[axis] < p1->pos[axis] ); }
        unsigned axis;
    };
};
/// used by periodic surfaces : m is a 2d proj. o and y are used to define bound lines
template<class TM>
void make_proj_periodic(TM &m,unsigned axis) {
    typedef typename TM::TNode TNode;
    
    LMTPRIVATE::Filter_perio_lines<TM> fpl;
    fpl.m = &m;
    fpl.axis = axis;
    m.remove_elements_if(fpl);
    
    // sort new points
    LMTPRIVATE::Sort_points sp;
    sp.axis = 1-axis;
    //using namespace std;
    std::sort(fpl.new_nodes_0.begin(),fpl.new_nodes_0.end(),sp);
    std::sort(fpl.new_nodes_1.begin(),fpl.new_nodes_1.end(),sp);
    // adding edges
    TNode *op0 = NULL;
    TNode *op1 = NULL; // because we don't like warnings from the compiler
    for(unsigned i=0;i<fpl.new_nodes_0.size();++i) {
        if ( i & 1 ) {
            m.add_element( Bar(), DefaultBehavior(), op0, fpl.new_nodes_0[i] );
            m.add_element( Bar(), DefaultBehavior(), op1, fpl.new_nodes_1[i] );
        }
        op0 = fpl.new_nodes_0[i];
        op1 = fpl.new_nodes_1[i];
    }
    
}

};

#endif // LMT_MAKE_PROJ_PERIODIC_HEADER

