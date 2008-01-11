//
// C++ Interface: %{MODULE}
//
// Description: 
//
//
// Author: %{AUTHOR} <hugo_lec@club-internet.fr>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef CODEGENOP_H
#define CODEGENOP_H

#include <string>
#include <set>
#include "codegen_vector.h"

namespace Codegen {

class Ex;

/**
Base node class for Codegen. Can represent a symbol, a number, a multiplication, ...

@author LECLERC Hugo
*/
class Op {
public:
    typedef long double T;
    typedef enum {
        Number  = 0,
        Symbol  = 1,
        Nothing = 2,
        
        // functions with 1 variable
        Abs = 10,
        Heavyside = 11,
        Eqz = 12,
        Sin = 13,
        Cos = 14,
        Sgn = 15,
        Tan = 16,
        Log = 17,
        Neg = 18,
        Asin = 19,
        Acos = 20,
        Atan = 21,
        Exp = 22,
        Heavyside_if = 23,
        
        // functions with 2 variables
        Add = 50,
        Sub = 51,
        Mul = 52,
        Div = 53,
        Pow = 54,
        Atan2 = 55,
        
        Max = 60,
        Min = 61
    } TypeEx;

    Op();
    ~Op();
    
    static bool is_a_function_1(TypeEx type) { return ( type>=Abs && type<Add ); }
    static bool is_a_function_2(TypeEx type) { return ( type>=Add && type<=Min ); }
    static TypeEx getType(const std::string &type);
    bool is_a_function_1() const { return is_a_function_1(type); }
    bool is_a_function_2() const { return is_a_function_2(type); }
    float priority() const;
    std::string to_string() const;
    std::string graphviz_repr() const;
    
    
//private:
    mutable long unsigned id;
    mutable const Op *res_op;
    
    void depends_on_rec(long unsigned current_id) const;
    void find_discontinuities( long unsigned current_id, std::vector<const Op *> &lst ) const;
    bool mustPrecede(const Op *b) const;
    void decreaseCptUse() const;
    const Op *makeChildUsing(const Op *c);
    void removeFromParents(const Op *par) const;
    void set_val_should_be_updated() const;
    void update_val() const;
    static T operation(TypeEx type,T a);
    static T operation(TypeEx type,T a,T b);
    static bool fun_2_is_sym_var_1(Op::TypeEx t,const Op *a,const Op *b);
    static bool fun_2_is_sym_var_2(Op::TypeEx t,const Op *a,const Op *b);
    static bool fun_2_is_unsym_var_1(Op::TypeEx t,const Op *a,const Op *b);
    static bool fun_2_is_unsym_var_2(Op::TypeEx t,const Op *a,const Op *b);
    /// used for symbols, function 1 and 2.
    union Value {
        const Op *children[2];
        char *names[2];
    };
    Value data;
    TypeEx type;
    void *additional_data; /// only for symbols
    int movability_level; /// only for symbols
    mutable Cvector<const Op *> parents;
    mutable unsigned cptUse;
    mutable T val; /// available for all kind of ops
    mutable bool val_should_be_updated; /// available for all kind of ops

    
    friend const Op *op_number(T v);
    friend const Op *op_symbol(const char *std_name,const char *latex_name=NULL,void *additional_data=NULL,int movability_level=0);
    friend const Op *make_function_2(TypeEx t,const Op *a,const Op *b);
    friend const Op *make_function_1(TypeEx t,const Op *a);
    
    friend std::ostream &operator<<(std::ostream &os,const Op &op);
    friend bool operator==(const Op &a,const Op &b);
    friend class Ex;
};

const Op *op_number(Op::T v);
const Op *op_symbol(const char *std_name,const char *latex_name,void *additional_data,int movability_level);
const Op *make_function_2(Op::TypeEx t,const Op *a,const Op *b);
const Op *make_function_1(Op::TypeEx t,const Op *a);
unsigned nb_children_op(const Op *op);

std::ostream &operator<<(std::ostream &os,const Op &op);
bool operator==(const Op &a,const Op &b);


};

#endif // CODEGENOP_H
