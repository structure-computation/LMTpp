#ifndef MAKEASM_H
#define MAKEASM_H

#include "SimpleSplittedVec.h"
#include <set>
#include <cmath>

namespace Codegen {

struct MakeAsm {
    struct Wop {
        enum {
            Sqr   = -10,  // ^2
            Sqrt  = -11,  // ^0.5
            Rsqrt = -12   // ^-0.5
        };
        
        Wop() : ordering( -1 ), reg( -1 ), pos_in_lst_var( -1 ), pos_in_stack( -1 ), to_write( -1 ) {
            nb_children = 0;
        }
        
        bool already_computed() const { return reg >= 0 or pos_in_lst_var >= 0 or pos_in_stack >= 0; }
        
        int type;
        Op::T val;
        Wop *children[2];
        unsigned nb_children;
        
        int ordering;
        std::vector<Wop *> parents;
        
        int reg;
        int pos_in_lst_var;
        int pos_in_stack;
        int to_write;
    };
    
    MakeAsm( bool x86_64 = false ) : x86_64( x86_64 ), tmp_value_size( 3 /* because of ~(1<<63), 0 and 1 */ ) {
        base_type_size = 8; // double
        registers.resize( 8 + 8 * x86_64, NULL );
        stack.resize( registers.size(), NULL );
        // ~ ( 1 << 63 ) -> aligned
        sgn_wop = wop_buffer.new_elem();
        sgn_wop->type = Op::Number;
        sgn_wop->val  = ~ ( (long long)1 << 63 );
        sgn_wop->pos_in_lst_var = 0;
        // 0
        zero_wop = wop_buffer.new_elem();
        zero_wop->type = Op::Number;
        zero_wop->val  = 0;
        zero_wop->pos_in_lst_var = 1;
        // 1 -> aligned
        one_wop  = wop_buffer.new_elem();
        one_wop ->type = Op::Number;
        one_wop ->val  = 1;
        one_wop ->pos_in_lst_var = 2;
    }
    
    void add_op_to_write( const Op *op ) {
        Wop *wop = make_wop_rec( op );
        //
        if ( op->leave()==false and wop->to_write < 0 ) {
            wop->to_write = tmp_value_size++;
            wop_to_write.push_back( wop );
        }
    }
    
    std::string write_asm() {
        ordering.free();
        for(unsigned i=0;i<wop_to_write.size();++i)
            make_ordering( wop_to_write[i], ordering );
        
        // main block
        std::ostringstream os;
        for(unsigned i=0;i<ordering.size();++i)
            write_asm_instr( os, ordering[i] );
        
        // stack management
        std::ostringstream res;
        if ( not x86_64 ) {
            res << "%define rax eax\n";
            res << "%define rsp esp\n";
        }
        res << "    sub  rsp, " << base_type_size << '*' << stack.size() << "\n";
        for(unsigned i=0;i<registers.size();++i)
            res << "    movsd [ rsp + " << base_type_size << '*' << i << " ], xmm" << i << "\n";
        res << os.str();
        for(unsigned i=0;i<registers.size();++i)
            res << "    movsd xmm" << i << ", [ rsp + " << base_type_size << '*' << i << " ]\n";
        res << "    add  rsp, " << base_type_size << '*' << stack.size() << "\n";
        res << "    ret\n";
        return res.str();
    }
    
    
    bool x86_64;
    int tmp_value_size, base_type_size;
    SimpleSplittedVec<Wop> wop_buffer;
    SimpleSplittedVec<Wop *> ordering;
    SimpleSplittedVec<Wop *> wop_to_write;
    std::vector<Wop *> registers;
    std::vector<Wop *> stack;
    Wop *sgn_wop;
    Wop *zero_wop;
    Wop *one_wop;
    
private:
    Wop *make_wop_rec( const Op *op ) {
        if ( op->id == Ex::current_id )
            return reinterpret_cast<Wop *>( op->additional_data );
        op->id = Ex::current_id;
        Wop *wop = NULL;
        // - a -> 0 - a
        if ( op->type == Op::Neg ) {
            wop = wop_buffer.new_elem();
            wop->type = Op::Sub;
            wop->nb_children = 2;
            wop->children[0] = zero_wop;
            wop->children[0]->parents.push_back( wop );
            wop->children[1] = make_wop_rec( op->data.children[0] );
            wop->children[1]->parents.push_back( wop );
        }
        // a ^ n
        else if ( op->type == Op::Pow and op->data.children[1]->type == Op::Number ) { // 
            wop = make_wop_pow( op->data.children[0], op->data.children[1]->val );
            make_wop_rec( op->data.children[1] ); // to update tmp_value_size if necessary
        }
        //
        else {
            wop = wop_buffer.new_elem();
            wop->type = op->type;
            wop->val = op->val;
            wop->nb_children = op->nb_children();
            //
            if ( op->leave() )
                wop->pos_in_lst_var = tmp_value_size++;
            else {
                for(unsigned i=0;i<wop->nb_children;++i) {
                    wop->children[i] = make_wop_rec( op->data.children[i] );
                    wop->children[i]->parents.push_back( wop );
                }
            }
        }
        
        op->additional_data = reinterpret_cast<void *>( wop );
        return wop;
    }
    
    Wop *make_wop_pow( const Op *mant, Op::T expo ) {
        // a ^ 1
        if ( std::abs( expo - 1 ) < 1e-6 )
            return make_wop_rec( mant );
        // a ^ n  with n no int N but in N / 4
        if ( expo > 0 and is_int( expo ) == false and is_int( expo * 4 ) ) {
            Wop *wop = wop_buffer.new_elem();
            // wop->type = ( expo > 0 ? Wop::Sqrt : Wop::Rsqrt );
            wop->type = Wop::Sqrt;
            wop->nb_children = 1;
            wop->children[0] = make_wop_pow( mant, 2 * std::abs( expo ) );
            wop->children[0]->parents.push_back( wop );
            return wop;
        }
        // a ^ n with n < 0
        if ( expo < 0 ) {
            Wop *wop = wop_buffer.new_elem();
            wop->type = Op::Div;
            wop->nb_children = 2;
            wop->children[0] = one_wop;
            wop->children[0]->parents.push_back( wop );
            wop->children[1] = make_wop_pow( mant, - expo );
            wop->children[1]->parents.push_back( wop );
            return wop;
        }
        // a ^ n with n in 2 * N
        if ( is_int( expo / 2 ) ) {
            Wop *wop = wop_buffer.new_elem();
            wop->type = Wop::Sqr;
            wop->nb_children = 1;
            wop->children[0] = make_wop_pow( mant, expo / 2 );
            wop->children[0]->parents.push_back( wop );
            return wop;
        }
        // a ^ n with n in N ( but not in 2 * N )
        if ( is_int( expo ) ) {
            Wop *wop = wop_buffer.new_elem();
            wop->type = Op::Mul;
            wop->nb_children = 2;
            wop->children[0] = make_wop_pow( mant,        1 );
            wop->children[0]->parents.push_back( wop );
            wop->children[1] = make_wop_pow( mant, expo - 1 );
            wop->children[1]->parents.push_back( wop );
            return wop;
        }
        // generic case -> exp( log( n ) * a )
        assert( 0 ); // TODO
        //         Wop *log_n = wop_buffer.new_elem();
        //         wop->type = Op::Number;
        //         
        //         wop->nb_children = 0;
        //         
        //         
        //         Wop *exp_ = wop_buffer.new_elem();
        //         wop->type = Op::Mul;
        //         wop->nb_children = 2;
        //         wop->children[0] = make_wop_pow( mant,        1 );
        //         wop->children[0]->parents.push_back( wop );
        //         wop->children[1] = make_wop_pow( mant, expo - 1 );
        //         wop->children[1]->parents.push_back( wop );
        //         return wop;
    }
    
    static bool is_int( Op::T val, Op::T crit = 1e-6 ) {
        return std::abs( std::floor( val + 0.5 ) - val ) < crit;
    }
    
    void make_ordering( Wop *wop, SimpleSplittedVec<Wop *> &ordering ) { // hum
        if ( wop->ordering >= 0 or wop->already_computed() )
            return;
        //
        for(unsigned i=0;i<wop->nb_children;++i)
            make_ordering( wop->children[i], ordering );
            
        wop->ordering = ordering.size();
        ordering.push_back( wop );
    }
    
    void write_asm_instr( std::ostream &os, Wop *wop ) {
        switch ( wop->type ) {
            case Op::Number:       assert( 0 ); /*weird*/                               break;
            case Op::Symbol:       assert( 0 ); /*weird*/                               break;
            
            case Op::Abs:          write_abs( os, wop );                                break; /*assert( wop->children[0]->parents.size() == 0 ); os << "    andps  xmm" << reg << ", [ eax + 8 * 0 ]\n";*/ 
            case Op::Heavyside:    write_cmp_z( os, wop, 5 );                           break;
            case Op::Heavyside_if: assert( 0 );                                         break;
            case Op::Eqz:          write_cmp_z( os, wop, 0 );                           break;
            case Op::Log:          assert( 0 );                                         break;
            case Op::Exp:          assert( 0 );                                         break;
            case Op::Sin:          assert( 0 );                                         break;
            case Op::Cos:          assert( 0 );                                         break;
            case Op::Sgn:          assert( 0 );                                         break;
            case Op::Tan:          assert( 0 );                                         break;
            case Op::Neg:          assert( 0 ); /*weird*/                               break;
            case Op::Asin:         assert( 0 );                                         break;
            case Op::Acos:         assert( 0 );                                         break;
            case Op::Atan:         assert( 0 );                                         break;
            case Op::Dirac:        assert( 0 );                                         break;
            
            case Op::Add:          write_binary_asm_instr<true >( os, wop, "addsd"   ); break;
            case Op::Sub:          write_binary_asm_instr<false>( os, wop, "subsd"   ); break;
            case Op::Mul:          write_binary_asm_instr<true >( os, wop, "mulsd"   ); break;
            case Op::Div:          write_binary_asm_instr<false>( os, wop, "divsd"   ); break;
            case Op::Pow:          assert( 0 );                                         break;
            case Op::Max:          write_binary_asm_instr<true >( os, wop, "maxsd"   ); break;
            case Op::Min:          write_binary_asm_instr<true >( os, wop, "minsd"   ); break;
            case Op::Atan2:        assert( 0 );                                         break;
            
            case Wop::Sqrt:        write_sqrt_or_rsqrt          ( os, wop, "sqrtsd"  ); break;
            // case Wop::Rsqrt:       write_sqrt_or_rsqrt          ( os, wop, "rsqrtsd" ); break;
            case Wop::Sqr:         write_sqr                    ( os, wop            ); break;
            
            default:            assert( 0 );
        }
        
        //
        if ( wop->to_write >= 0 ) {
            wop->pos_in_lst_var = wop->to_write;
            os << "    movsd [ rax + " << base_type_size << '*' << wop->to_write << " ], xmm" << wop->reg << "\n";
            if ( wop->parents.size() == 0 )
                registers[ wop->reg ] = NULL;
        }
    }
    
    void write_cmp_z( std::ostream &os, Wop *wop, int compare_operation ) {
        Wop *c0 = wop->children[0];
        
        if ( c0->reg >= 0 ) {
            int c0_reg = c0->reg;
            if ( c0->parents.size() > 1 )
                save_wop( os, c0, c0->reg, -1 );
            // operation
            os << "    cmpsd xmm" << c0_reg << ", "; write_wop_as_lhs( os, zero_wop ); os << ", " << compare_operation << "\n";
            os << "    andpd xmm" << c0_reg << ", "; write_wop_as_lhs( os, one_wop  ); os << "\n";
            //
            wop->reg = c0_reg;
            registers[ c0_reg ] = wop;
        }
        else {
            int reg = find_free_reg( os );
            // operation
            os << "    movsd xmm" << reg << ", "; write_wop_as_lhs( os, c0 ); os << "\n";
            os << "    cmpsd xmm" << reg << ", "; write_wop_as_lhs( os, zero_wop ); os << ", " << compare_operation << "\n";
            os << "    andpd xmm" << reg << ", "; write_wop_as_lhs( os, one_wop  ); os << "\n";
            //
            wop->reg = reg;
            registers[ reg ] = wop;
        }
        
        // parents
        c0->parents.erase( std::find( c0->parents.begin(), c0->parents.end(), wop ) );
    }
    
    template<bool commutative>
    void write_binary_asm_instr( std::ostream &os, Wop *wop, const char *op_name ) {
        Wop *c0 = wop->children[0];
        Wop *c1 = wop->children[1];
        if ( commutative ) {
            if ( c0->parents.size() > 1 and c1->parents.size() == 1 )
                std::swap( c0, c1 );
            else if ( c0->reg < 0 and c1->reg >= 0 )
                std::swap( c0, c1 );
        }
        
        if ( c0->reg >= 0 ) { // we will use c0->reg as a result
            int c0_reg = c0->reg;
            if ( c0->parents.size() > 1 ) // c0 has to be saved ?
                save_wop( os, c0, c0->reg, c1->reg );
            // operation
            os << "    " << op_name << " xmm" << c0_reg << ", "; write_wop_as_lhs( os, c1 ); os << "\n";
            //
            wop->reg = c0_reg;
            registers[ c0_reg ] = wop;
        }
        else { // c0 is not in a reg
            int reg = find_free_reg( os );
            // operation
            os << "    movsd xmm" << reg << ", "; write_wop_as_lhs( os, c0 ); os << "\n";
            os << "    " << op_name << " xmm" << reg << ", "; write_wop_as_lhs( os, c1 ); os << "\n";
            //
            wop->reg = reg;
            registers[ reg ] = wop;
        }
        
        // parents
        c0->parents.erase( std::find( c0->parents.begin(), c0->parents.end(), wop ) );
        c1->parents.erase( std::find( c1->parents.begin(), c1->parents.end(), wop ) );
    }
    
    void write_sqr( std::ostream &os, Wop *wop ) { // a**2
        Wop *c0 = wop->children[0];
        
        if ( c0->reg >= 0 ) {
            int c0_reg = c0->reg;
            if ( c0->parents.size() > 1 )
                save_wop( os, c0, c0->reg, -1 );
            // operation
            os << "    mulsd xmm" << c0_reg << ", xmm" << c0_reg << "\n";
            //
            wop->reg = c0_reg;
            registers[ c0_reg ] = wop;
        }
        else {
            int reg = find_free_reg( os );
            // operation
            os << "    movsd xmm" << reg << ", "; write_wop_as_lhs( os, c0 ); os << "\n";
            os << "    mulsd xmm" << reg << ", xmm" << reg << "\n";
            //
            wop->reg = reg;
            registers[ reg ] = wop;
        }
        
        // parents
        c0->parents.erase( std::find( c0->parents.begin(), c0->parents.end(), wop ) );
    }
    
    void write_sqrt_or_rsqrt( std::ostream &os, Wop *wop, const char *op_name ) {
        Wop *c0 = wop->children[0];
        
        if ( c0->reg >= 0 ) {
            int c0_reg = c0->reg;
            int reg = ( c0->parents.size() == 1 ? c0_reg : find_free_reg( os ) );
            //
            os << "    " << op_name << " xmm" << reg << ", xmm" << c0_reg << "\n";
            wop->reg = reg;
            registers[ reg ] = wop;
        }
        else {
            int reg = find_free_reg( os );
            os << "    " << op_name << " xmm" << reg << ", "; write_wop_as_lhs( os, c0 ); os << "\n";
            wop->reg = reg;
            registers[ reg ] = wop;
        }
        
        // parents
        c0->parents.erase( std::find( c0->parents.begin(), c0->parents.end(), wop ) );
    }
    
    void write_abs( std::ostream &os, Wop *wop ) {
        Wop *c0 = wop->children[0];
        
        if ( c0->reg >= 0 ) {
            int c0_reg = c0->reg;
            if ( c0->parents.size() > 1 )
                save_wop( os, c0, c0->reg, -1 );
            // operation
            os << "    andpd xmm" << c0_reg << ", "; write_wop_as_lhs( os, sgn_wop ); os << "\n";
            //
            wop->reg = c0_reg;
            registers[ c0_reg ] = wop;
        }
        else {
            int reg = find_free_reg( os );
            // operation
            os << "    movsd xmm" << reg << ", "; write_wop_as_lhs( os, c0 ); os << "\n";
            os << "    andpd xmm" << reg << ", "; write_wop_as_lhs( os, sgn_wop ); os << "\n";
            //
            wop->reg = reg;
            registers[ reg ] = wop;
        }
        
        // parents
        c0->parents.erase( std::find( c0->parents.begin(), c0->parents.end(), wop ) );
    }
    
    void save_wop( std::ostream &os, Wop *wop, int reg0_to_avoid, int reg1_to_avoid ) {
        save_wop_in_stack( os, wop );
    }
    
    void save_wop_in_stack( std::ostream &os, Wop *wop ) {
        for(unsigned i=registers.size();i<stack.size();++i) {
            if ( stack[i]==NULL or stack[i]->parents.size() == 0 ) {
                os << "    movsd [ rsp + " << base_type_size << '*' << i << " ], "; write_wop_as_lhs( os, wop ); os << "\n";
                wop->pos_in_stack = i;
                wop->reg = -1;
                stack[i] = wop;
                return;
            }
        }
        //
        os << "    movsd [ rsp + " << base_type_size << '*' << stack.size() << " ], "; write_wop_as_lhs( os, wop ); os << "\n";
        wop->pos_in_stack = stack.size();
        wop->reg = -1;
        stack.push_back( wop );
    }
    
    int find_free_reg( std::ostream &os ) {
        int res = 0;
        for(unsigned i=0;i<registers.size();++i) {
            if ( registers[i] == NULL or registers[i]->parents.size() == 0 )
                return i;
            if ( storage_time( registers[res] ) < storage_time( registers[i] ) )
                res = i;
        }
        // no free registers -> need to save old reg
        save_wop_in_stack( os, registers[ res ] );
        return res;
    }
    
    int storage_time( Wop *wop ) {
        int res = std::numeric_limits<int>::max();
        for(unsigned i=0;i<wop->parents.size();++i)
            res = std::min( res, wop->parents[i]->ordering );
        return res;
    }

    
    void write_wop_as_lhs( std::ostream &os, const Wop *wop ) const {
        if ( wop->reg >= 0 )
            os << "xmm" << wop->reg;
        else if ( wop->pos_in_lst_var >= 0 )
            os << "[ rax + " << base_type_size << '*' << wop->pos_in_lst_var << " ]";
        else if ( wop->pos_in_stack >= 0 )
            os << "[ rsp + " << base_type_size << '*' << wop->pos_in_stack   << " ]";
        else
            assert( 0 );
    }
            
};

}

#endif // MAKEASM_H

