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
#include "op.h"

#include <string.h>
#include <sstream>
#include <iostream>
#include <map>
#include <math.h>
#include <cmath>
#include <assert.h>
#include <assert.h>
#include <iomanip>

namespace Codegen {


// static Pool<Op> pool_ex;
static std::map<Op::T,Op> pool_numbers;

Op::Op():id(0),type(Nothing),cptUse(0) {
}

void Op::removeFromParents(const Op *par) const {
    parents.erase_first( par );
    decreaseCptUse();
}

/// delete from pools if there's no use anymore
void Op::decreaseCptUse() const {
    if ( --cptUse == 0 ) {
        if ( type==Number ) {
            //pool_numbers.erase( val );
            
        }
        else {
            if ( type==Symbol ) {
                free( data.names[0] );
                free( data.names[1] );
            }
            else if ( is_a_function_1() ) {
                data.children[0]->removeFromParents( this );
            }
            else if ( is_a_function_2() ) {
                data.children[0]->removeFromParents( this );
                data.children[1]->removeFromParents( this );
            }
            //pool_ex.deleteSlot( this );
            delete this;
        }
    }
}

Op::~Op() {
}

const Op *op_number(Op::T v) {
    //if( isnan(v)==false and isinf(v)==false ) {
    //}
    // look if number has not been registered
    std::map<Op::T,Op>::iterator iter = pool_numbers.find(v);
    if ( std::isnan(v) or std::isinf(v) or iter == pool_numbers.end() ) {
        Op *res;
        if ( std::isnan(v) or std::isinf(v) )
            res = &pool_numbers[ 643216874.16871 ];
        else
            res = &pool_numbers[v];
        res->type = Op::Number;
        res->val = v;
        res->val_should_be_updated = false;
        return res;
    }
    ++iter->second.cptUse;
    return &iter->second;
}


const Op *op_symbol(const char *std_name,const char *latex_name,void *additional_d,int movability_level) {
    //Op *res = pool_ex.newSlot();
    Op *res = new Op;
    res->type = Op::Symbol;
    res->additional_data = additional_d;
    res->movability_level = movability_level;
    res->val_should_be_updated = false;
    
    // copy of names
    unsigned len_std = strlen(std_name)+1;
    res->data.names[0] = (char *)malloc( len_std );
    strcpy(res->data.names[0],std_name);
    if ( latex_name ) {
        res->data.names[1] = (char *)malloc( strlen(latex_name)+1 );
        strcpy(res->data.names[1],latex_name);
    }
    else {
        res->data.names[1] = (char *)malloc( len_std );
        strcpy(res->data.names[1],std_name);
    }
    return res;
}

/// declare c as a child of *this
const Op *Op::makeChildUsing(const Op *c) {
    c->parents.push_back( this );
    ++c->cptUse;
    return c;
}

Op::T Op::operation(Op::TypeEx type,Op::T a) {
    using namespace std;
    switch (type) {
        case Abs:       return std::abs(a);
        case Heavyside: return (a>=0);
        case Heavyside_if: return (a>=0);
        case Eqz:       return (a==0);
        case Sin:       return sin(a);
        case Cos:       return cos(a);
        case Sgn:       return (a>0)-(a<0);
        case Tan:       return tan(a);
        case Neg:       return -a;
        case Asin:      return asin(a);
        case Acos:      return acos(a);
        case Atan:      return atan(a);
        case Log:       return log(a);
        case Exp:       return exp(a);
        default:    cout << "with type " << type << endl;  assert( 0 );
    }
    return 0;
}
Op::T Op::operation(Op::TypeEx type,Op::T a,Op::T b) {
    using namespace std;
    switch (type) {
        case Add:       return a + b;
        case Sub:       return a - b;
        case Mul:       return a * b;
        case Div:       return a / b; // ( b==0.0 && a==0.0 ? (T)0.0 : a / b );
        case Pow:       return ( b==0.0 ? (T)1.0 : pow(a,b) );
        case Atan2:     return atan2(a,b);
        case Max:       return ( a>b ? a : b );
        case Min:       return ( a<b ? a : b );
        default:        assert( 0 );
    }
    return 0;
}

bool makeAbsVal(Op::TypeEx t) { return ( t==Op::Abs || t==Op::Cos || t==Op::Eqz ); }
bool makeSymVal(Op::TypeEx t) { return ( t==Op::Sin || t==Op::Tan || t==Op::Sgn || t==Op::Asin || t==Op::Atan ); }

void Op::set_val_should_be_updated() const {
    if ( val_should_be_updated )
        return;
    val_should_be_updated = true;
    for(unsigned i=0;i<parents.size();++i)
        parents[i]->set_val_should_be_updated();
}
void Op::update_val() const {
    if ( ! val_should_be_updated )
        return;
    if ( is_a_function_1() ) {
        data.children[0]->update_val();
        val = operation(type,data.children[0]->val);
    }
    else if ( is_a_function_2() ) {
        data.children[0]->update_val();
        data.children[1]->update_val();
        val = operation(type,data.children[0]->val,data.children[1]->val);
    }
    val_should_be_updated = false;
}

//
const Op *make_function_1(Op::TypeEx t,const Op *a) {
    // if a is a number
    if ( a->type == Op::Number )
        return op_number( Op::operation( t, a->val ) );
    // -(2), -(-a)
    if ( t==Op::Neg ) {
        if ( a->type==Op::Number ) return op_number(-a->val);
        if ( a->type==Op::Neg ) return a->data.children[0];
    }
    // symmetricFuntion(-a) -> -symmetricFuntion(a)
    if ( a->type==Op::Neg && makeSymVal(t) ) return make_function_1(Op::Neg,make_function_1(t,a->data.children[0]));
    // abs(-...), cos(-...), abs(abs(...)), cos(abs(...))
    if ( makeAbsVal(t) ) {
        if ( a->type==Op::Abs ) return make_function_1(t,a->data.children[0]);
        if ( a->type==Op::Neg ) return make_function_1(t,a->data.children[0]);
    }
    // look for similar function_1
    for(unsigned i=0;i<a->parents.size();++i) {
        if ( a->parents[i]->type==t ) {
            return a->parents[i];
        }
    }
    // create
    //Op *res = pool_ex.newSlot();
    Op *res = new Op;
    res->type = t;
    res->data.children[0] = res->makeChildUsing(a);
    res->val_should_be_updated = true;
    return res;
}

bool commutative(Op::TypeEx t) {
    return ( t==Op::Add || t==Op::Mul );
}

bool Op::mustPrecede(const Op *b) const {
    if ( type==Number ) return true;
    if ( b->type==Number ) return false;
    return ( this < b );
}

bool Op::fun_2_is_sym_var_1(Op::TypeEx t,const Op *a,const Op *b) {
    return ( t==Op::Mul || t==Op::Div || ( t==Op::Pow && b->type==Op::Number && b->val == int(b->val) && (int(b->val)&1)==1 ) );
}
bool Op::fun_2_is_sym_var_2(Op::TypeEx t,const Op *a,const Op *b) {
    return ( t==Op::Mul || t==Op::Div );
}
bool Op::fun_2_is_unsym_var_1(Op::TypeEx t,const Op *a,const Op *b) {
    return ( t==Op::Pow && b->type==Op::Number && b->val == int(b->val) && (int(b->val)&1)==0 );
}
bool Op::fun_2_is_unsym_var_2(Op::TypeEx t,const Op *a,const Op *b) {
    return false;
}

const Op *make_function_2(Op::TypeEx t,const Op *a,const Op *b) {
    // if a and b are numbers
    if ( a->type == Op::Number && b->type == Op::Number ) {
        //std::cout << "a " << a->to_string() << std::endl;
        return op_number( Op::operation( t, a->val, b->val ) );
    }
    // reorder
    if ( commutative(t) && b->mustPrecede(a) )
        std::swap(a,b);
    // a*(-b), ...
    if ( a->type==Op::Neg ) {
        if ( Op::fun_2_is_sym_var_1(t,a,b) )   return make_function_1(Op::Neg, make_function_2(t,a->data.children[0],b) );
        if ( Op::fun_2_is_unsym_var_1(t,a,b) ) return make_function_2(t,a->data.children[0],b);
    }
    if ( b->type==Op::Neg ) {
        if ( Op::fun_2_is_sym_var_2(t,a,b) )   return make_function_1(Op::Neg, make_function_2(t,a,b->data.children[0]) );
        if ( Op::fun_2_is_unsym_var_2(t,a,b) ) return make_function_2(t,a,b->data.children[0]);
    }
    if ( a->type==Op::Number && a->val<0.0 ) {
        if ( Op::fun_2_is_sym_var_1(t,a,b) )   return make_function_1(Op::Neg, make_function_2(t,op_number(-a->val),b) );
        if ( Op::fun_2_is_unsym_var_1(t,a,b) ) return make_function_2(t,op_number(-a->val),b);
    }
    if ( b->type==Op::Number && b->val<0.0 ) {
        if ( Op::fun_2_is_sym_var_2(t,a,b) )   return make_function_1(Op::Neg, make_function_2(t,a,op_number(-b->val)) );
        if ( Op::fun_2_is_unsym_var_2(t,a,b) ) return make_function_2(t,a,op_number(-b->val));
    }
    // a+(-b), (-a)+b, a+(-5)
    if ( t==Op::Add ) {
        if ( a==b ) return make_function_2(Op::Mul,op_number(2),a);
        if ( a->type==Op::Neg ) return make_function_2(Op::Sub,b,a->data.children[0]);
        if ( b->type==Op::Neg ) return make_function_2(Op::Sub,a,b->data.children[0]);
        if ( a->type==Op::Number ) {
            if ( a->val<0.0 )  return make_function_2(Op::Sub,b,op_number(-a->val));
            if ( a->val==0.0 ) return b;
        }
        //if ( b->type==Op::Number && b->val<0.0 ) return make_function_2(Op::Sub,a,op_number(-b->val));
    }
    // a-(-b), (-a)-b, a-(-5), -5-b
    if ( t==Op::Sub ) {
        if ( a==b ) return op_number(0);
        if ( b->type==Op::Neg ) return make_function_2(Op::Add,a,b->data.children[0]);
        if ( a->type==Op::Neg ) return make_function_1(Op::Neg,make_function_2(Op::Add,a->data.children[0],b));
        if ( a->type==Op::Number ) {
            if ( a->val<0.0 )  return make_function_1(Op::Neg,make_function_2(Op::Add,b,op_number(-a->val)));
            if ( a->val==0.0 ) return make_function_1(Op::Neg,b);
        }
        if ( b->type==Op::Number ) {
            if ( b->val<0.0 ) return make_function_2(Op::Add,a,op_number(-b->val));
            if ( b->val==0.0 ) return a;
        }
    }
    //
    if ( t==Op::Mul ) {
        if ( a==b ) return make_function_2(Op::Pow,a,op_number(2));
        if ( a->type==Op::Number ) {
            if ( a->val==1 ) return b;
            if ( a->val==0 ) return op_number(0);
            // 2*(3*a)
            if ( b->type==Op::Mul && b->data.children[0]->type==Op::Number )
                return make_function_2( Op::Mul, op_number(a->val*b->data.children[0]->val), b->data.children[1] );
            //2*(3/a)
            //if ( b->type==Op::Div && b->data.children[0]->type==Op::Number )
            //return make_function_2( Op::Div, op_number(a->val*b->data.children[0]->val), b->data.children[1] );
        }
    }
    if ( t==Op::Div ) {
        if ( a==b ) return op_number(1);
        if ( a->type==Op::Number && a->val==1 ) return make_function_2(Op::Pow,b,op_number(-1));
        if ( a->type==Op::Number && a->val==0 ) return op_number(0);
        if ( b->type==Op::Number && b->val==1 ) return a;
    }
    // a**1, a**0, 0**b, 1**b, (-a)**2, (-a)**3
    if ( t==Op::Pow ) {
        if ( b->type==Op::Number ) {
            if ( b->val == 1.0 ) return a;
            if ( b->val == 0.0 ) return op_number(1.0);
        }
        if ( a->type==Op::Number ) {
            if ( a->val == 1 ) return a;
            if ( a->val == 0 ) return a;
        }
    }
    // 
    // look for similar function_2
    for(unsigned i=0;i<a->parents.size();++i)
        if ( a->parents[i]->type==t && a->parents[i]->data.children[0]==a && a->parents[i]->data.children[1]==b ) {
            return a->parents[i];
        }
    // create
    //Op *res = pool_ex.newSlot();
    Op *res = new Op;
    res->type = t;
    res->data.children[0] = res->makeChildUsing(a);
    res->data.children[1] = res->makeChildUsing(b);
    res->val_should_be_updated = true;
    return res;
}

float Op::priority() const {
    switch ( type ) {
        case Add: return 50;
        case Sub: return 60;
        case Neg: return 65;
        case Mul: return 70;
        case Div: return 80;
        case Pow: return 90;
        default: ;
    }
    return 1000;
}

void displaySeq(std::ostream &os,const Op *op,const char *t,const Op *c1,const Op *c2) {
    float tp = op->priority();
    float c1p = c1->priority();
    float c2p = c2->priority();
    if ( tp > c1p or (tp == c1p and strcmp(t,"**")==0) ) os << '(';
    os << *c1;
    if ( tp > c1p or (tp == c1p and strcmp(t,"**")==0) ) os << ')';
    os << t;
    if ( tp > c2p or (strcmp(t,"-")==0 and tp==c2p) ) os << '(';
    os << *c2;
    if ( tp > c2p or (strcmp(t,"-")==0 and tp==c2p ) ) os << ')';
}
void displayNeg(std::ostream &os,const Op *op,const Op *c1) {
    float tp = op->priority();
    float c1p = c1->priority();
    os << '-';
    if ( tp > c1p ) os << '(';
    os << *c1;
    if ( tp > c1p ) os << ')';
}

std::ostream &operator<<(std::ostream &os,const Op &op) {
    switch (op.type) {
        case Op::Number: os << std::setprecision(20) << op.val; break;
        case Op::Symbol: os << op.data.names[0]; break;
        
        case Op::Add: displaySeq(os,&op,"+", op.data.children[0],op.data.children[1]); break;
        case Op::Sub: displaySeq(os,&op,"-", op.data.children[0],op.data.children[1]); break;
        case Op::Mul: displaySeq(os,&op,"*", op.data.children[0],op.data.children[1]); break;
        case Op::Div: displaySeq(os,&op,"/", op.data.children[0],op.data.children[1]); break;
        case Op::Pow: displaySeq(os,&op,"**",op.data.children[0],op.data.children[1]); break;
        
        case Op::Neg: displayNeg(os,&op,op.data.children[0]); break;
        
        default:
            if ( op.is_a_function_1() )
                os << op.graphviz_repr() << '(' << *op.data.children[0] << ')';
            else if ( op.is_a_function_2() )
                os << op.graphviz_repr() << '(' << *op.data.children[0] << ',' << *op.data.children[1] << ')';
            else
                os << "Error : type not managed in operator<<.";
    }
    return os;
}

std::string Op::to_string() const {
    std::ostringstream ss;
    ss << *this;
    return ss.str();
}

std::string Op::graphviz_repr() const {
    switch (type) {
        case Number:    return to_string();
        case Symbol:    return data.names[0];
        
        case Add:       return "+";
        case Sub:       return "-";
        case Mul:       return "*";
        case Div:       return "/";
        case Pow:       return "**";
        
        case Abs:       return "abs";
        case Heavyside: return "heavyside";
        case Heavyside_if: return "heavyside_if";
        case Eqz:       return "eqz";
        case Sin:       return "sin";
        case Cos:       return "cos";
        case Sgn:       return "sgn";
        case Tan:       return "tan";
        case Log:       return "log";
        case Exp:       return "exp";
        case Neg:       return "-";
        case Asin:      return "asin";
        case Acos:      return "acos";
        case Atan:      return "atan";
        case Atan2:     return "atan2";
        
        case Max:       return "max";
        case Min:       return "min";
        default: ;
    }
    return "Error : type not managed in graphviz_repr.";
}
Op::TypeEx Op::getType(const std::string &type) {
    if ( type=="abs" ) return Abs;
    if ( type=="heavyside" ) return Heavyside;
    if ( type=="heavyside_if" ) return Heavyside_if;
    if ( type=="eqz" ) return Eqz;
    if ( type=="sin" ) return Sin;
    if ( type=="cos" ) return Cos;
    if ( type=="sgn" ) return Sgn;
    if ( type=="tan" ) return Tan;
    if ( type=="log" ) return Log;
    if ( type=="exp" ) return Exp;
    if ( type=="neg" ) return Neg;
    if ( type=="asin" ) return Asin;
    if ( type=="acos" ) return Acos;
    if ( type=="atan" ) return Atan;
    
    if ( type=="pow" )   return Pow;
    if ( type=="Atan2" ) return Atan2;
    if ( type=="max" )   return Max;
    if ( type=="min" )   return Min;
    if ( ( type[0]>='0' && type[0]<='9' ) || type[0]=='.' )
        return Number;
    return Symbol;
}

unsigned nb_children_op(const Op *op) {
    if ( op->is_a_function_1() )
        return 1 + nb_children_op(op->data.children[0]);
    if ( op->is_a_function_2() )
        return 1 + nb_children_op(op->data.children[0]) + nb_children_op(op->data.children[1]);
    return 1;
}

void Op::depends_on_rec(long unsigned current_id) const {
    if ( id != current_id ) {
        id = current_id;
        if ( is_a_function_1() ) {
            data.children[0]->depends_on_rec(current_id);
            res_op = data.children[0]->res_op;
        }
        else if ( is_a_function_2() ) {
            data.children[0]->depends_on_rec(current_id);
            data.children[1]->depends_on_rec(current_id);
            res_op = ( data.children[0]->res_op or data.children[1]->res_op ? this : NULL );
        }
        else
            res_op = NULL;
    }
    // else -> already done
}

void Op::find_discontinuities( long unsigned current_id, std::vector<const Op *> &lst ) const {
    if ( id != current_id ) {
        id = current_id;
        if ( is_a_function_1() ) {
            if ( type == Heavyside or type == Heavyside_if or type == Abs or type == Sgn )
                lst.push_back( this ); 
            //
            data.children[0]->find_discontinuities( current_id, lst );
        }
        else if ( is_a_function_2() ) {
            data.children[0]->find_discontinuities( current_id, lst );
            data.children[1]->find_discontinuities( current_id, lst );
        }
    }
    // else -> already done
}


};
