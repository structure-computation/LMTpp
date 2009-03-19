#include "op.h"
#include "ex.h"
#include "write_code.h"
#include "write_code_language_cpp.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>

#include "MakeAsm.h"

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

    return *this;
}

unsigned Write_code::node_count() const {
    ++Ex::current_id;
    unsigned res = 0;
    for(unsigned i=0;i<lst_var.size();++i)
        res += lst_var[i].ex.op->node_count_rec( Ex::current_id );
    return res;
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
    
    std::cout << "pouet!!!!!!!!" << std::endl;
    
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

/// return Non NULL value if contains an Heaviside_if
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

int Write_code::display_graphviz() {
    const char *filename = "tmq.dot";
    std::ofstream f( filename );
    write_graphviz( f );
    std::string fi( filename );
    std::string com( "dot -Tps "+fi+" > "+fi+".eps && gv "+fi+".eps" );
    return system( com.c_str() );
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

void get_sub_symbols_and_numbers_rec( const Op *op, std::map<const Op *,int,std::less<const Op *> > &tmp_ops, int &tmp_value_size ) {
    if ( op->id == Ex::current_id )
        return;
    op->id = Ex::current_id;
    //
    if ( op->leave() and tmp_ops.find( op ) == tmp_ops.end() )
        tmp_ops[ op ] = tmp_value_size++;
    else
        for(unsigned i=0;i<op->nb_children();++i)
            get_sub_symbols_and_numbers_rec( op->data.children[i], tmp_ops, tmp_value_size );
}

/*
    tmp_values contains
        1 << 63
        numbers + symbols + results ( apparition order )
        
*/
std::string Write_code::asm_caller( std::string asm_function_name ) {
    typedef std::map<const Op *,int,std::less<const Op *> > MapOp;
    
    //
    MapOp tmp_ops; // value -> pos in [ EAX + ... ]
    int tmp_value_size = 3;
    
    ++Ex::current_id;
    for(unsigned i=0;i<lst_var.size();++i) {
        const Op *op = lst_var[i].ex.op;
        get_sub_symbols_and_numbers_rec( op, tmp_ops, tmp_value_size );
        if ( tmp_ops.find( op ) == tmp_ops.end() )
            tmp_ops[ op ] = tmp_value_size++;
    }
    
    //
    std::ostringstream os;
    os << std::string( wcl->nb_spaces, ' ' ) << "double tmp_values_[ " << tmp_value_size << " + 1 ];\n";
    os << std::string( wcl->nb_spaces, ' ' ) << "double *tmp_values = tmp_values_ + bool( (long long)tmp_values_ & 8 );\n";
    os << std::string( wcl->nb_spaces, ' ' ) << "long long tmp_bm = ~( (long long)1 << 63 );\n";
    os << std::string( wcl->nb_spaces, ' ' ) << "tmp_values[ 0 ] = reinterpret_cast<double &>( tmp_bm );\n";
    os << std::string( wcl->nb_spaces, ' ' ) << "tmp_values[ 1 ] = 0.0;\n";
    os << std::string( wcl->nb_spaces, ' ' ) << "tmp_values[ 2 ] = 1.0;\n";
    for( MapOp::iterator iter=tmp_ops.begin(); iter!=tmp_ops.end(); ++iter )
        if ( iter->first->leave() ) 
            os << std::string( wcl->nb_spaces, ' ' ) << "tmp_values[ " << iter->second << " ] = " << Ex( iter->first ) << ";\n";
    
    // call
    os << std::string( wcl->nb_spaces, ' ' ) << asm_function_name << "( tmp_values );\n";
    
    //
    for(unsigned i=0;i<lst_var.size();++i) {
        os << std::string( wcl->nb_spaces, ' ' );
        switch ( lst_var[i].method ) {
            case Write_code::Declare: os << "double " << lst_var[i].name << " = " ; break;
            case Write_code::Set:     os <<              lst_var[i].name << " = " ; break;
            case Write_code::Add:     os <<              lst_var[i].name << " += "; break;
            case Write_code::Sub:     os <<              lst_var[i].name << " -= "; break;
            case Write_code::Return:  os << "return "; break;
        }
        os << "tmp_values[ " << tmp_ops[ lst_var[i].ex.op ] << " ];\n";
    }
    
    //
    return os.str();
}

std::string Write_code::to_asm( std::string function_name ) {
    typedef std::map<const Op *,int,std::less<const Op *> > MapOp;
    
    
    //
    MakeAsm ma;
    ++Ex::current_id;
    for(unsigned i=0;i<lst_var.size();++i)
        ma.add_op_to_write( lst_var[i].ex.op );
    
    //
    std::string res;
    if ( function_name.size() ) {
        res += "global " + function_name + "\n";
        res += function_name + ":\n";
    }
    res += ma.write_asm();
    return res;
}

// -----------------------------------------------------------------------------------------------------------------------------

/*
struct WriteAsmInfo {
    static const unsigned NOWHERE = 0;
    static const unsigned STACK   = 1;
    static const unsigned REG     = 2;
    static const unsigned EAX     = 3;
    
    WriteAsmInfo() : reg(-1), pos_in_lst_var(-1), nb_parents(0), storage( NOWHERE ) {}
    int reg;
    int pos_in_lst_var;
    unsigned nb_parents;
    unsigned ordering;
    unsigned storage;
};


unsigned storage_time( const Op *reg, const Op *current_parent ) {
    unsigned res = std::numeric_limits<unsigned>::max();
    for(unsigned i=0;i<reg->parents.size();++i) {
        if ( reg->parents[i]->id == Ex::current_id ) {
            unsigned p = reinterpret_cast<WriteAsmInfo *>( reg->parents[i]->additional_data )->ordering;
            unsigned c = reinterpret_cast<WriteAsmInfo *>( reg->            additional_data )->ordering;
            if ( p > c )
                res = std::min( res, p - c );
        }
    }
    return res;
}

// bestial
void make_ordering_rec( const Op *op, std::vector<const Op *> &ordering ) {
    if ( op->id == Ex::current_id )
        return;
    op->id == Ex::current_id;
    //
    if ( op->is_a_function_1() ) {
        make_ordering_rec( op->data.children[0], ordering );
        ordering.push_back( op );
    }
    else if ( op->is_a_function_2() ) {
        make_ordering_rec( op->data.children[0], ordering );
        make_ordering_rec( op->data.children[1], ordering );
        ordering.push_back( op );
    }
    
}

struct MakeAsm {
    MakeAsm() : stack_size( 0 ) {}
    
    std::string get_val( const WriteAsmInfo *chw ) {
        std::ostringstream ss;
        if ( chw->pos_in_lst_var >= 0 )
            ss << "[ eax + " << chw->pos_in_lst_var << " ]";
        else if ( chw->storage == WriteAsmInfo::EAX )
            ss << "[ eax + " << chw->reg << " ]";
        else if ( chw->storage == WriteAsmInfo::STACK )
            ss << "[ esp + " << stack_size - chw->reg << " ]";
        else {
            std::cout << chw->storage << std::endl;
            assert( chw->storage == WriteAsmInfo::REG );
            ss << "xmm" << chw->reg;
        }
        return ss.str();
    }
    
    void write_binary_commutative_asm_instr( std::ostream &os, const Op *op, int reg, const char *n ) {
        const Op *ch_0 = op->data.children[0];
        const Op *ch_1 = op->data.children[1];
        const WriteAsmInfo *chw_0 = reinterpret_cast<const WriteAsmInfo *>( ch_0->additional_data );
        const WriteAsmInfo *chw_1 = reinterpret_cast<const WriteAsmInfo *>( ch_1->additional_data );
        
        if ( chw_0->storage == WriteAsmInfo::REG ) { // REG + ...
            if ( chw_1->storage == WriteAsmInfo::REG ) { // REG + REG
                if ( reg == chw_0->reg )
                    os << "    " << n << "  xmm" << reg << ", xmm" << chw_1->reg << "\n";
                else if ( reg == chw_1->reg )
                    os << "    " << n << "  xmm" << reg << ", xmm" << chw_0->reg << "\n";
                else {
                    os << "    movapd  xmm" << reg << ", xmm" << chw_0->reg << "\n";
                    os << "    " << n << "  xmm" << reg << ", xmm" << chw_1->reg << "\n";
                }
            }
            else { // REG + ( EAX or STACk )
                if ( reg == chw_0->reg )
                    os << "    " << n << "  xmm" << reg << ", " << get_val( chw_1 ) << "\n";
                else {
                    os << "    movapd  xmm" << reg << ", " << get_val( chw_1 ) << "\n";
                    os << "    " << n << "  xmm" << reg << ", xmm" << chw_0->reg << "\n";
                }
            }
        }
        else { // EAX + ...
            if ( chw_1->storage == WriteAsmInfo::REG ) { // EAX + REG
                if ( reg == chw_1->reg )
                    os << "    " << n << "  xmm" << reg << ", " << get_val( chw_0 ) << "\n";
                else {
                    os << "    movapd  xmm" << reg << ", " << get_val( chw_0 ) << "\n";
                    os << "    " << n << "  xmm" << reg << ", xmm" << chw_1->reg << "\n";
                }
            }
            else { // EAX + EAX
                os << "    movapd  xmm" << reg << ", " << get_val( chw_0 ) << "\n";
                os << "    " << n << "  xmm" << reg << ", " << get_val( chw_1 ) << "\n";
            }
        }
    }
    
    void write_asm_instr( std::ostream &os, const Op *op, int reg ) {
        switch ( op->type ) {
            case Op::Number:       assert( 0 ); break;
            case Op::Symbol:       assert( 0 ); break;
            
            case Op::Abs: {
                long long tmp = (long long)1 << 63;
                os << "    andps  xmm" << reg << ", [ eax + 8 * " << map_numbers[ reinterpret_cast<double &>( tmp ) ] << " ]\n";
                break;
            }
            case Op::Heavyside:    
            case Op::Heavyside_if: 
            case Op::Eqz:          
            case Op::Log:          
            case Op::Exp:          
            case Op::Sin:          
            case Op::Cos:          
            case Op::Sgn:          
            case Op::Tan:          
            case Op::Neg:          
            case Op::Asin:         
            case Op::Acos:         
            case Op::Atan:         
            case Op::Dirac:        
            
            case Op::Add:          write_binary_commutative_asm_instr( os, op, reg, "addsd" ); break;
            case Op::Sub:          
            case Op::Mul:          write_binary_commutative_asm_instr( os, op, reg, "mulsd" ); break;
            case Op::Div:          
            case Op::Pow:          
            case Op::Max:          write_binary_commutative_asm_instr( os, op, reg, "maxsd" ); break;
            case Op::Min:          write_binary_commutative_asm_instr( os, op, reg, "minsd" ); break;
            case Op::Atan2:        
            
            default:            assert( 0 );
        }
    
    }
    
    void write_asm( std::ostream &os, const std::vector<Write_code::Var> &lst_var ) {
        // ordering (basic) + simple cases
        ++Ex::current_id;
        std::vector<const Op *> ordering;
        for(unsigned i=0;i<lst_var.size();++i) {
            const Op *op = lst_var[i].ex.op;
            if ( op->type == Op::Number ) {
                os << "    movsd  xmm0, [ eax + 8 * " << map_numbers[ op->val ] << " ]\n";
                os << "    movsd  [ eax + 8 * " << i << " ], xmm0\n";
            }
            else if ( op->type == Op::Symbol ) {
                os << "    movsd  xmm0, [ eax + 8 * " << op->movability_level   << " ]\n";
                os << "    movsd  [ eax + 8 * " << i << " ], xmm0\n";
            }
            else
                make_ordering_rec( op, ordering );
        }
            
        // WriteAsmInfo
        std::vector<WriteAsmInfo> wa_info( ordering.size() );
        std::list<WriteAsmInfo> additional_wa_info;
        for(unsigned i=0;i<ordering.size();++i) {
            WriteAsmInfo *n = &wa_info[ i ];
            n->ordering = i;
            ordering[i]->additional_data = reinterpret_cast<void *>( n );
            for(unsigned j=0;j<ordering[i]->nb_children();++j) {
                const Op *ch = ordering[i]->data.children[j];
                if ( ch->id != Ex::current_id ) {
                    ch->id = Ex::current_id;
                    //
                    WriteAsmInfo wa;
                    if ( ch->type == Op::Number or ch->type == Op::Symbol ) {
                        wa->storage = WriteAsmInfo::EAX;
                        wa->reg     = ( op->type == Op::Number ? map_numbers[ op->val ] : op->movability_level );
                    }
                    //
                    additional_wa_info.push_front( wa );
                    ordering[i]->data.children[j]->additional_data = reinterpret_cast<void *>( &additional_wa_info.front() );
                }
                reinterpret_cast<WriteAsmInfo *>( ordering[i]->data.children[j]->additional_data )->nb_parents ++;
            }
        }
        for(unsigned i=0;i<lst_var.size();++i) {
            const Op *op = lst_var[i].ex.op;
            WriteAsmInfo *wa = reinterpret_cast<WriteAsmInfo *>( ordering[i]->additional_data );
        }
        for(unsigned i=0;i<lst_var.size();++i)
            reinterpret_cast<WriteAsmInfo *>( lst_var[i].ex.op->additional_data )->pos_in_lst_var = i;
        
        // write
        unsigned nb_registers = 8;
        registers.resize( nb_registers, NULL );
        unsigned stack_pos = 0;
        for(unsigned i=0;i<ordering.size();++i) {
            int reg = -1;
            // free reg update
            for(unsigned j=0;j<ordering[i]->nb_children();++j) {
                const Op *ch = ordering[i]->data.children[j];
                WriteAsmInfo *chw = reinterpret_cast<WriteAsmInfo *>( ch->additional_data );
                if ( --chw->nb_parents == 0 and chw->storage == WriteAsmInfo::REG ) {
                    reg = chw->reg;
                    registers[ reg ] = NULL;
                }
            }
            // register choice
            if ( reg < 0 ) {
                reg = 0;
                for(unsigned j=0;j<registers.size();++j) {
                    if ( registers[j] == NULL ) {
                        reg = j;
                        break;
                    }
                    if ( storage_time( registers[j], ordering[i] ) < storage_time( registers[reg], ordering[i] ) )
                        reg = j;
                }
            }
            
            // asm instr
            save_reg_if_necessary( os, reg );
            write_asm_instr( os, ordering[i], reg );
            
            // register management
            registers[ reg ] = ordering[i];
            reinterpret_cast<WriteAsmInfo *>( ordering[i]->additional_data )->storage = WriteAsmInfo::REG;
            reinterpret_cast<WriteAsmInfo *>( ordering[i]->additional_data )->reg     = reg;
            
            // inf lst_var ?
            if ( reinterpret_cast<WriteAsmInfo *>(ordering[i]->additional_data)->pos_in_lst_var >= 0 )
                os << "    movsd  [ eax + 8 * " << reinterpret_cast<WriteAsmInfo *>(ordering[i]->additional_data)->pos_in_lst_var << " ], xmm" << reg << "\n";
        }
        os << "    ret\n";
    }
    
    void save_reg_if_necessary( std::ostream &os, int reg ) {
        if ( not registers[ reg ] )
            return;
        WriteAsmInfo *wa = reinterpret_cast<WriteAsmInfo *>( registers[ reg ]->additional_data );
        if ( wa->pos_in_lst_var >= 0 )
            return;
        os << "    push  xmm" << reg << "\n";
        //
        wa->storage = WriteAsmInfo::STACK;
        wa->reg     = --stack_size;
    }
    
    std::vector<const Op *> registers;
    unsigned stack_size;
};
*/



};



