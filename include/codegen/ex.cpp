
//
// C++ Implementation: %{MODULE}
//
// Description:
//
//
// Author: %{AUTHOR} <hugo_lec@club-internet.fr>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "ex.h"
#include "op.h"
#include "read_ex.h"
#include "write_graphviz.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <math.h>
#include <assert.h>

namespace Codegen {

long unsigned Ex::current_id = 0;

Ex::Ex() {
    op = op_number(0);
    ++op->cptUse;
}
Ex::Ex(const Ex &ex) {
    op = ex.op;
    ++op->cptUse;
}
Ex::Ex(const Op *ex) {
    op = ex;
    ++op->cptUse;
   
}
Ex::Ex(T v) { op = op_number(v); ++op->cptUse; }
Ex::Ex(double v) { op = op_number(v); ++op->cptUse; }
Ex::Ex(int v) { op = op_number(v); ++op->cptUse; }
Ex::Ex(unsigned v) { op = op_number(v); ++op->cptUse; }
Ex::Ex(const char *std_name,const char *latex_name,void *additional_data,int movability_level) {
    op = op_symbol(std_name,latex_name,additional_data,movability_level);
    ++op->cptUse;
}
void Ex::operator=(const Ex &c) {
    ++c.op->cptUse;
    op->decreaseCptUse();
    op = c.op;
}

Ex number(Ex::T v) { return Ex(v); }
Ex number(const char *v) {
    Ex::T vn;
    std::istringstream ss(v);
    ss >> vn;
    return Ex(vn);
}
Ex symbol(const char *std_name,const char *latex_name,void *additional_data,int movability_level) {
    return Ex(std_name,latex_name,additional_data,movability_level);
}

Ex::~Ex() {
    op->decreaseCptUse();
}

void Ex::display_graphviz(const char *filename) const {
    std::ofstream f( filename );
    write_graphviz( *this, f );
    std::string fi( filename );
    std::string com( "dot -Tps "+fi+" > "+fi+".eps && gv "+fi+".eps" );
    system( com.c_str() );
    
}

std::string Ex::to_string() const {
    std::ostringstream ss;
    ss << *this;
    return ss.str();
}
std::string Ex::graphviz_repr() const { return op->graphviz_repr(); }

bool Ex::is_a_symbol() const { return op->type==Op::Symbol; }
bool Ex::is_a_number() const { return op->type==Op::Number; }
void *Ex::get_additional_symbol_data() const { return op->additional_data; }
bool Ex::is_a_function_1() const { return op->is_a_function_1(); }
bool Ex::is_a_function_2() const { return op->is_a_function_2(); }

Ex Ex::subs(const Ex &a,const Ex &b) const {
    std::map<Ex,Ex,Ex::ExMapCmp> m;
    m[a] = b;
    return subs(m);
}
Ex Ex::subs_with_test(const Ex &a,const Ex &b) const {
    std::map<Ex,Ex,Ex::ExMapCmp> m;
    m[a] = b;
    return subs_with_test(m);
}
Ex Ex::subs(std::map<Ex,Ex,Ex::ExMapCmp> &m) const {
    ++current_id;
    for( std::map<Ex,Ex,Ex::ExMapCmp>::const_iterator iter = m.begin(); iter != m.end(); ++iter ) {
        iter->second.op->cptUse++;
        iter->first.op->res_op = iter->second.op;
        iter->first.op->id = current_id;
    }
    subs_rec();
    return op->res_op;
}
void Ex::subs_rec() const {
    if ( op->id != current_id ) {
        op->id = current_id;
        if ( is_a_function_1() ) {
            Ex c1( op->data.children[0] );
            c1.subs_rec();
            Ex s1( c1.op->res_op );
            if ( s1==c1 ) {
                op->res_op = op;
                return;
            }
            Ex tmp( make_function_1( op->type, s1.op ) ); ++tmp.op->cptUse;
            op->res_op = tmp.op;
        }
        else if ( is_a_function_2() ) {
            Ex c1( op->data.children[0] ), c2( op->data.children[1] );
            c1.subs_rec(); c2.subs_rec();
            Ex s1( c1.op->res_op ), s2( c2.op->res_op );
            if ( s1==c1 && s2==c2 ) {
                op->res_op = op;
                return;
            }
            Ex tmp( make_function_2( op->type, s1.op , s2.op ) ); ++tmp.op->cptUse;
            op->res_op = tmp.op;
        }
        else
            op->res_op = op;
    }
}


Ex Ex::subs_with_test(const MapEx &m_) const {
    MapEx m = m_;
    return subs( m );
//     ++current_id;
//     for( std::map<Ex,Ex,Ex::ExMapCmp>::const_iterator iter = m.begin(); iter != m.end(); ++iter ) {
//         iter->first.op->res_op = iter->second.op;
//         iter->first.op->id = current_id;
//     }
//     subs_with_test_rec();
//     return op->res_op;
}    

void Ex::subs_with_test_rec(const MapEx &m_) const {
    if ( m_.size()==0 )
        return;
    
//     const long double eps = 1e-12;
//     std::vector<int> pos( m_.size(), 0 );
//     while ( true ) {
//         MapEx m;
//         unsigned cpt = 0;
//         for( MapEx::const_iterator iter = m_.begin(); iter!=m_.end(); ++iter, ++cpt )
//             m[iter->first] = iter->second + ( pos[cpt] ? (pos[cpt]==1 ? eps : -eps ) : 0.0 ); //
//         Ex res = subs(m);
//         if( not res.contain_nan_or_inf() )
//             return res;
// 
//         // else, increment pos
//         ++pos[0];
//         for(int d=0;;d++) {
//             if ( pos[d]>2 ) {
//                 if ( d == int(m_.size()-1) ) {
//                     std::cerr << "Unable to find epsilon to avoid nan or inf." << std::endl;
//                     return Ex(666);
//                 }
//                 pos[d] = 0;
//                 ++pos[d+1];
//             }
//             else
//                 break;
//         }
//     }
    return;
}
bool Ex::contain_nan_or_inf() const {
    SetEx sub_nodes;
    get_sub_nodes(sub_nodes);
    for(SetEx::const_iterator iter = sub_nodes.begin(); iter!=sub_nodes.end(); ++iter) {
        if ( iter->is_a_number() and ( isnan( iter->get_val() ) or isinf( iter->get_val() ) ) )
            return true;
    }
    return false;
}

Ex::T Ex::subs_numerical(std::map<Ex,Ex::T,Ex::ExMapCmp> &m) const throw(Subs_numerical_error) {
    std::map<Ex,T,Ex::ExMapCmp>::const_iterator iter = m.find(*this);
    if ( iter != m.end() )
        return iter->second;
    if ( is_a_number() )
        return get_val();
    if ( is_a_function_1() ) {
        T tmp = Op::operation( op->type, Ex(op->data.children[0]).subs_numerical(m) );
        m[ *this ] = tmp;
        return tmp;
    }
    if ( is_a_function_2() ) {
        T tmp = Op::operation( op->type, Ex(op->data.children[0]).subs_numerical(m), Ex(op->data.children[1]).subs_numerical(m) );
        m[ *this ] = tmp;
        return tmp;
    }
    throw Subs_numerical_error( to_string() );
}

void Ex::get_sub_symbols(SetEx &sub_symbols) const {
    SetEx lst;
    get_sub_nodes(lst);
    for(SetEx::const_iterator iter=lst.begin();iter!=lst.end();++iter)
        if ( iter->is_a_symbol() )
            sub_symbols.insert( *iter );
}
void Ex::get_sub_nodes(SetEx &lst) const {
    if ( find( lst.begin(), lst.end(), *this ) != lst.end() )
        return;
    lst.insert( *this );
    if ( is_a_function_1() ) Ex(op->data.children[0]).get_sub_nodes(lst);
    else if ( is_a_function_2() ) {
        Ex(op->data.children[0]).get_sub_nodes(lst);
        Ex(op->data.children[1]).get_sub_nodes(lst);
    }
}

Ex Ex::diff(const Ex &a) const {
    std::map<Ex,Ex,Ex::ExMapCmp> m;
    m[a] = 1;
    return diff(m);
}
Ex Ex::diff(std::map<Ex,Ex,Ex::ExMapCmp> &m) const {
    ++current_id;
    for( std::map<Ex,Ex,Ex::ExMapCmp>::const_iterator iter = m.begin(); iter != m.end(); ++iter ) {
        iter->first.op->res_op = iter->second.op;
        iter->first.op->id = current_id;
    }
    diff_rec();
    return op->res_op;
}
void Ex::diff_rec() const {
    if ( op->id != current_id ) {
        op->id = current_id;
        if ( is_a_function_1() ) {
            Ex c1( op->data.children[0] ); c1.diff_rec();
            Ex res( diff( op, c1, c1.op->res_op ) ); ++res.op->cptUse;
            op->res_op = res.op;
        }
        else if ( is_a_function_2() ) {
            Ex c1( op->data.children[0] ), c2( op->data.children[1] ); c1.diff_rec(); c2.diff_rec();
            Ex res( diff( op, c1, c1.op->res_op, c2, c2.op->res_op ) ); ++res.op->cptUse;
            op->res_op = res.op;
        }
        else
            op->res_op = op_number(0);
    }
}

Ex Ex::diff(const Op *op,const Ex &a,const Ex &da) {
    using namespace std;
    switch (op->type) {
        case Op::Abs:       return da*sgn(a);
        case Op::Heavyside: return number(0.0);
        case Op::Heavyside_if: return number(0.0);
        case Op::Eqz:       return number(0.0);
        case Op::Log:       return da/a;
        case Op::Exp:       return da*exp(a);
        case Op::Sin:       return da*cos(a);
        case Op::Cos:       return -da*sin(a);
        case Op::Sgn:       return number(0.0);
        case Op::Tan:       return da*(1+pow(tan(a),2));
        case Op::Neg:       return -da;
        case Op::Asin:      return da*pow(1-pow(a,2),-(T)0.5);
        case Op::Acos:      return -da*pow(1-pow(a,2),-(T)0.5);
        case Op::Atan:      return da/(1+pow(a,2));
        default:            assert( 0 );
    }
    return 0;
}

Ex Ex::diff(const Op *op,const Ex &a,const Ex &da,const Ex &b,const Ex &db) {
    using namespace std;
    switch (op->type) {
        case Op::Add:       return da + db;
        case Op::Sub:       return da - db;
        case Op::Mul:       return da * b + a * db;
        case Op::Div:       return da / b - db * a / pow(b,2);
        case Op::Pow:       return b*da*pow(a,b-1) + db*log(a)*Ex(op);
        case Op::Max:       return heavyside(b-a)*db + (1-heavyside(b-a))*da;
        case Op::Atan2:     return ( db/a - da*b/(a*a) ) / ( 1+pow(b/a,2) );
        default:            assert( 0 );
    }
    return 0;
}


bool operator==(const Ex &a,int b) {
    return (a==(Ex::T)b);
}
bool operator==(const Ex &a,Ex::T b) {
    return ( a.is_a_number() && a.get_val()==b );
}

bool operator==(const Ex &a,const Ex &b) {
    return ( a.op == b.op );
}

std::ostream &operator<<(std::ostream &os,const Ex &ex) {
    os << *ex.op;
    return os;
}

Ex operator+(const Ex &a,const Ex &b) { return make_function_2(Op::Add,a.op,b.op); }
Ex operator-(const Ex &a,const Ex &b) { return make_function_2(Op::Sub,a.op,b.op); }
Ex operator*(const Ex &a,const Ex &b) { return make_function_2(Op::Mul,a.op,b.op); }
Ex operator/(const Ex &a,const Ex &b) { return make_function_2(Op::Div,a.op,b.op); }
Ex Ex::operator-() const { return make_function_1(Op::Neg,op); }
Ex Ex::operator+=(const Ex &a) { *this = *this + a; return *this; }
Ex Ex::operator-=(const Ex &a) { *this = *this - a; return *this; }
Ex Ex::operator*=(const Ex &a) { *this = *this * a; return *this; }
Ex Ex::operator/=(const Ex &a) { *this = *this / a; return *this; }

Ex sqrt(const Ex &a) { return pow(a.op,0.5); }
Ex abs(const Ex &a) { return make_function_1(Op::Abs,a.op); }
Ex heavyside(const Ex &a) { return make_function_1(Op::Heavyside,a.op); }
Ex heavyside_if(const Ex &a) { return make_function_1(Op::Heavyside_if,a.op); }
Ex eqz(const Ex &a) { return make_function_1(Op::Eqz,a.op); }
Ex sin(const Ex &a) { return make_function_1(Op::Sin,a.op); }
Ex cos(const Ex &a) { return make_function_1(Op::Cos,a.op); }
Ex sgn(const Ex &a) { return make_function_1(Op::Sgn,a.op); }
Ex tan(const Ex &a) { return make_function_1(Op::Tan,a.op); }
Ex log(const Ex &a) { return make_function_1(Op::Log,a.op); }
Ex exp(const Ex &a) { return make_function_1(Op::Exp,a.op); }
Ex neg(const Ex &a) { return make_function_1(Op::Neg,a.op); }
Ex asin(const Ex &a) { return make_function_1(Op::Asin,a.op); }
Ex acos(const Ex &a) { return make_function_1(Op::Acos,a.op); }
Ex atan(const Ex &a) { return make_function_1(Op::Atan,a.op); }

Ex pow(const Ex &a,const Ex &b) { return make_function_2(Op::Pow,a.op,b.op); }
Ex max(const Ex &a,const Ex &b) { return make_function_2(Op::Max,a.op,b.op); }
Ex atan2(const Ex &a,const Ex &b) { return make_function_2(Op::Atan2,a.op,b.op); }

Ex::T Ex::get_val() const {
    op->update_val();
    return op->val;
}
int Ex::get_movability_level() const { return op->movability_level; }
void Ex::set_val(T v) {
    assert( op->type == Op::Symbol );
    op->val = v;
    for(unsigned i=0;i<op->parents.size();++i)
        op->parents[i]->set_val_should_be_updated();
}

bool is_a_function_1(const std::string &f) {
    return Op::is_a_function_1( Op::getType(f) );
}
bool is_a_function_2(const std::string &f) {
    return Op::is_a_function_2( Op::getType(f) );
}
bool is_a_function(const std::string &f) {
    Op::TypeEx type = Op::getType(f);
    return ( Op::is_a_function_1(type) || Op::is_a_function_2(type) );
}
Ex new_function_1(const std::string &f,const Ex &a) {
    Op::TypeEx type = Op::getType(f);
    return make_function_1(type,a.op);
}
Ex new_function_2(const std::string &f,const Ex &a,const Ex &b) {
    Op::TypeEx type = Op::getType(f);
    return make_function_2(type,a.op,b.op);
}

Ex Ex::from_string(const std::string &str,std::vector<Ex> &symbols) throw(Read_ex_error) {
    return read_ex(str,symbols);
}

unsigned Ex::nb_children() const { return is_a_function_1() + 2*is_a_function_2(); }
Ex Ex::child(unsigned i) const { return op->data.children[i]; }
unsigned Ex::nb_parents() const { return op->parents.size(); }
Ex Ex::parent(unsigned i) const { return op->parents[i]; }

bool Ex::depends_on(const Ex &ex) const {
    ++current_id;
    
    ex.op->id = current_id;
    ex.op->res_op = ex.op;
    op->depends_on_rec( current_id );
    return op->res_op;
}
    
Ex Ex::find_discontinuity( const Ex &v ) const {
    ++current_id;
    
    std::vector<const Op *> lst;
    op->find_discontinuities( current_id, lst );
    for(int i=lst.size()-1;i>=0;--i)
        if ( Ex( lst[i] ).depends_on( v ) )
            return Ex( lst[i] );
    return 0;
}

bool Ex::is_zero() const { return op->type == Op::Number and op->val == 0.0; }

/*
def get_taylor_expansion( expr, beg, var, deg_poly_max ):
    res = ExVector()
    r = 1.0
    for i in range( deg_poly_max + 1 ):
        res.push_back( r * expr.subs( var, beg ) )
        if i < deg_poly_max:
            expr = expr.diff( var )
            r /= i + 1
    return res

def integration( expr, var, beg, end, deg_poly_max = 5 ):
    disc = expr.find_discontinuity( var )
    #if not disc.is_zero():
        
    taylor_expansion =  get_taylor_expansion( expr, beg, var, deg_poly_max )
    #
    res = 0
    for i in range( taylor_expansion.size() ):
        res += taylor_expansion[i] * ( end - beg ) ** ( i + 1 ) / ( i + 1 )
    return res;

*/
std::vector<Ex> taylor_expansion( Ex expr, const Ex &var, unsigned max_poly_order, const Ex &beg = 0 ) {
    std::vector<Ex> res;
    Ex::T r = 1;
    for(unsigned i=0;i<=max_poly_order;++i) {
        res.push_back( r * expr.subs( var, beg ) );
        if ( i < max_poly_order ) {
            expr = expr.diff( var );
            r /= i + 1;
        }
    }
    return res;
}

Ex polynomial_integration(const Ex &expr,const Ex &v,const Ex &beg,const Ex &end,unsigned max_poly_order) {
    std::vector<Ex> te = taylor_expansion( expr, v, max_poly_order, beg );
    Ex res( 0 );
    for(unsigned i=0;i<te.size();++i)
        res += te[i] * pow( end - beg, i + 1 ) / ( i + 1 );
    return res;
}

Ex integration(const Ex &expr,const Ex &v,const Ex &beg,const Ex &end,unsigned deg_poly_max) {
    Ex disc = expr.find_discontinuity( v );
    if ( disc.op->type != Op::Number ) {
        Ex ch = disc.op->data.children[0];
        //
        Ex subs_n;
        Ex subs_p;
        switch ( disc.op->type ) {
            case Op::Heavyside:
            case Op::Heavyside_if:
                subs_n = expr.subs( disc, 0 );
                subs_p = expr.subs( disc, 1 );
                break;
            case Op::Abs:
                subs_n = expr.subs( disc, - ch );
                subs_p = expr.subs( disc,   ch );
                break; 
            case Op::Sgn:
                subs_n = expr.subs( disc, -1 );
                subs_p = expr.subs( disc,  1 );
                break;
            default:
                assert( 0 );
        }
        //
        Ex mid = ( beg + end ) / 2;
        std::vector<Ex> expansion_ = taylor_expansion( ch, v, 2, mid );
        Ex cut = mid - expansion_[0] / ( expansion_[1] + eqz( expansion_[1] ) );
        
        
        Ex p_beg = heaviside( ch.subs( v, beg ) );
        Ex p_end = heaviside( ch.subs( v, end ) );
        Ex n_beg = 1 - p_beg;
        Ex n_end = 1 - p_end;
        //
        //
        Ex nb = beg + ( cut - beg ) * p_beg * n_end;
        Ex ne = end + ( beg - end + ( cut - beg ) * n_beg ) * p_end;
        Ex pb = beg + ( end - beg + ( cut - end ) * p_end ) * n_beg;
        Ex pe = end + ( cut - end ) * p_beg * n_end;
        
        Ex int_n = integration( subs_n, v, nb, ne, deg_poly_max );
        Ex int_p = integration( subs_p, v, pb, pe, deg_poly_max );
        return int_n + int_p;
    }
    //
    return polynomial_integration( expr, v, beg, end, deg_poly_max );
}


};
