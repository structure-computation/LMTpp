#include "op.h"
#include "write_code.h"
#include "write_code_language_cpp.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;

namespace Codegen {

Write_code::Write_code(const char *default_type,unsigned nb_spaces) {
    wcl = new Write_code_language_cpp(default_type,nb_spaces);
    wcl->lst_var = &lst_var;
}
Write_code::~Write_code() {
    delete wcl;
}

Write_code &Write_code::add( const Ex &ex, const std::string &name, Method method ) {
    Var var;
    var.ex = ex;
    var.name = name;
    var.method = method;
    lst_var.push_back( var );

//     std::cerr << "set_depth_rec" << std::endl;
//     std::cerr << "end set_depth_rec" << std::endl;

    //std::cerr << "add " << ex.op << std::endl;
    return *this;
}

void Write_code::set_node_order() {
    node_order.resize( nodes.size() );
    unsigned i = 0;
    for(Tnodes::iterator iter=nodes.begin();iter!=nodes.end();++iter,++i) node_order[i] = &iter->second;
    std::sort( node_order.begin(), node_order.end(), SortNode() );
    
//     while ( ! leaves.empty() ) {
//         // next node
//         Tleaves::iterator iter = get_next_node();
//         Node *next_node = *iter;
//         leaves.erase( iter );
// 
//         //
//         static unsigned cpt = 0;
//         next_node->reg = cpt++;
//         node_order.push_back(next_node);
// 
//         // we add elligible parents to @leaves
//         for(unsigned i=0;i<next_node->ex.nb_parents();++i) {
//             Ex p = next_node->ex.parent(i);
//             if ( nodes.find(p)==nodes.end() ) // we calculate parents in node set only...
//                 continue;
//             for(unsigned j=0;;++j) {
//                 if ( j == p.nb_children() ) {
//                     leaves.insert( &nodes[p] );
//                     break;
//                 }
//                 assert( nodes.find( p.child(j) ) != nodes.end() );
//                 if ( nodes[ p.child(j) ].reg < 0 ) // this node has not been calculated and registered
//                     break;
//             }
//         }
//     }
}

std::string Write_code::to_string() {
//     std::cerr << "to_string" << std::endl;
    for(unsigned i=0;i<lst_var.size();++i) {
        const Op *h = set_depth_rec(lst_var[i].ex,0);
        // if found an heavyside
        if ( h ) {
            std::string res;
            //
            for(unsigned i=0;i<lst_var.size();++i)
                if ( lst_var[i].method == Declare )
                    res += std::string( wcl->nb_spaces, ' ' ) + wcl->write_declaration( lst_var[i].name ) + "\n";
            //
            std::ostringstream name_h;
            name_h << "val_heaviside_if_" << h->data.children[0];
            //
            {
                Write_code wc_cond;
                wc_cond.wcl = wcl->copy( 0, wc_cond );
                wc_cond.add( h->data.children[0], name_h.str(), Declare );
                res += wc_cond.to_string();
            }
            // h = 1
            res += std::string( wcl->nb_spaces, ' ' ) + "if ( " + name_h.str() + " >= 0 ) {\n";
            {
                Write_code wc_1;
                wc_1.wcl = wcl->copy( 4, wc_1 );
                for(unsigned j=0;j<lst_var.size();++j)
                    wc_1.add( lst_var[j].ex.subs( h, number(1.0) ), lst_var[j].name, lst_var[j].method == Declare ? Set : lst_var[j].method );
                res += wc_1.to_string();
            }
            // h = 0
            res += std::string( wcl->nb_spaces, ' ' ) + "} else {\n";
            {
                Write_code wc_0;
                wc_0.wcl = wcl->copy( 4, wc_0 );
                for(unsigned j=0;j<lst_var.size();++j)
                    wc_0.add( lst_var[j].ex.subs( h, number(0.0) ), lst_var[j].name, lst_var[j].method == Declare ? Set : lst_var[j].method );
                res += wc_0.to_string();
            }
            res += std::string( wcl->nb_spaces, ' ' ) + "}\n";
            return res;
        }
    }
    
    // do not depend on language (only on processor).
    set_node_order();

    //for(Tnodes::const_iterator iter=nodes.begin();iter!=nodes.end();++iter) {
    //    Ex ex = iter->second.ex;
    //    for(unsigned i=0;i<ex.nb_children();++i)
    //        assert( ex.child(i).op->parents.find(ex.op)  );
    //}
    assert( node_order.size() == nodes.size() );
    //display_graphviz();
    //assert(0);
    //for(unsigned i=0;i<node_order.size();++i)
    //    std::cerr << node_order[i]->ex.op << " ";
    

    std::ostringstream res;
    for(unsigned i=0;i<node_order.size();++i) {
        unsigned nb_times_ex_will_be_used = 0;
        Ex ex = node_order[i]->ex;
        for(unsigned i=0;i<ex.nb_parents();++i)
            nb_times_ex_will_be_used += ( nodes.find(ex)!=nodes.end() );
        wcl->write_ex( res, ex, nb_times_ex_will_be_used );
    }
    if ( wcl->has_put_endl() == false )
        res << "\n";
    
    lst_var.clear();
    
//     std::cerr << "end to_string" << std::endl;
    return res.str();
}

Write_code::Tleaves::iterator Write_code::get_next_node() {
    // the first node will be the one with largest depth
    if ( node_order.size()<=2 ) {
        unsigned max_depth = 0;
        Tleaves::iterator res = leaves.begin();
        for(Tleaves::iterator iter=leaves.begin();iter!=leaves.end();++iter) {
            if ( (*iter)->depth > max_depth ) {
                max_depth = (*iter)->depth;
                res = iter;
            }
        }
        return res;
    }
    return leaves.begin();
}

const Op *Write_code::set_depth_rec(const Ex &ex,unsigned depth) {
    if ( ex.op->type == Op::Heavyside_if )
        return ex.op;
        
    std::map<Ex,Node,Ex::ExMapCmp>::iterator iter_ex = nodes.find(ex);
    if ( iter_ex != nodes.end() ) {
        if ( depth < iter_ex->second.depth )
            return NULL;
        iter_ex->second.depth = depth;
    } else {
        nodes[ex].reg = -1;
        nodes[ex].ex = ex;
        nodes[ex].depth = depth;
        nodes[ex].nb_times_to_be_used = 0;
        if ( ex.nb_children()==0 )
            leaves.insert( & nodes[ex] );
    }
    for(unsigned i=0;i<ex.nb_children();++i) {
        const Op *h = set_depth_rec( ex.child(i), depth + 1 );
        if ( h )
            return h;
    }
    return NULL;
}

void Write_code::display_graphviz() {
    const char *filename = "tmq.dot";
    std::ofstream f( filename );
    write_graphviz( f );
    std::string fi( filename );
    std::string com( "dot -Tps "+fi+" > "+fi+".eps && gv "+fi+".eps" );
    system( com.c_str() );
}

void Write_code::write_graphviz(ostream &os) {
    os << "digraph popo {" << endl;
    for(Tnodes::const_iterator iter=nodes.begin();iter!=nodes.end();++iter) {
        const Node &node = iter->second;
        
        os << "  node" << node.ex.id() << " [ label=\"" << node.ex.graphviz_repr() << " " << node.reg << "\"";
        for(unsigned i=0;i<node.ex.nb_parents();++i)
            if ( nodes.find( node.ex.parent(i) )!=nodes.end() and nodes[node.ex.parent(i)].reg < 0 ) {
                os << ",style=filled,color=\".7 .3 1.0\"";
                break;
            }
        os << " ];" << endl;
        for(unsigned i=0;i<node.ex.nb_children();++i)
            os << "  node" << node.ex.id() << " -> node" << node.ex.child(i).id() << endl;
        for(unsigned i=0;i<node.ex.nb_parents();++i)
            if ( nodes.find( node.ex.parent(i) )!=nodes.end() ) // we calculate parents in node set only...
                os << "  node" << node.ex.parent(i).id() << " -> node" << node.ex.id() << " [color=\"red\"]" << endl;
    }
    os << "}" << endl;
}

};
