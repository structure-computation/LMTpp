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
#ifndef CODEGENEX_H
#define CODEGENEX_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include "read_ex_error.h"

namespace Codegen {

class Op;
unsigned nb_children_op(const Op *op);

/**
Base node class for Codegen. Can represent a symbol, a number, a multiplication, ...
basic constructor Ex ex(); gives ex=0 by default

Symbols can contain a name, a latex_name, (void *)additional_data and a value.
Thus, all operations between several Ex calculate a number.
Ex : cout << (symbol("a",1) + symbol("b",3)).get_val(); gives 4 as result.

@author LECLERC Hugo
*/
class Ex {
public:
    typedef long double T;
    //struct ExMapCmp { bool operator()(const Ex &e1,const Ex &e2) const { return (e1.op<e2.op); } };
    typedef std::less<Ex> ExMapCmp;
    typedef std::map<Ex,Ex,Ex::ExMapCmp> MapEx;
    
    Ex();
    Ex(const Op *ex);
    Ex(const Ex &ex);
    Ex(T v);
    Ex(double v);
    Ex(int v);
    Ex(unsigned v);
    Ex(const char *std_name,const char *latex_name=NULL,void *additional_data=NULL,int movability_level=0);
    void operator=(const Ex &c);
    ~Ex();
    
    static Ex from_string(const std::string &str,std::vector<Ex> &symbols) throw(Read_ex_error);
    std::string to_string() const;
    std::string graphviz_repr() const;
    
    bool is_a_symbol() const;
    bool is_a_number() const;
    /// available for all kinds of Ex
    T get_val() const;
    /// only for symbols. Beware : val of parents will not be automatically updated
    void set_val(T v);
    void *get_additional_symbol_data() const; /// only for symbols
    int get_movability_level() const; /// only for symbols
    bool is_a_function_1() const;
    bool is_a_function_2() const;
    void display_graphviz(const char *filename="tmp.dot") const;
    
    bool depends_on(const Ex &ex) const;
    
    Ex operator-() const;
    Ex operator+=(const Ex &a);
    Ex operator-=(const Ex &a);
    Ex operator*=(const Ex &a);
    Ex operator/=(const Ex &a);
    
    
    Ex subs(const Ex &a,const Ex &b) const;
    Ex subs_with_test(const Ex &a,const Ex &b) const;
    Ex subs(MapEx &m) const; /// beware : m will be modified, adding new elements
    Ex subs_with_test(const MapEx &m) const; /// beware : m will be modified, adding new elements
    
    
    /// assumes that all sub symbols has a correspondance in m
    struct Subs_numerical_error {
        Subs_numerical_error(const std::string &e):ex(e) {}
        std::string ex;
    };
    /// beware : m will be modified, adding new elements
    typedef std::map<Ex,T,Ex::ExMapCmp> MapExNum;
    T subs_numerical(MapExNum &m) const throw(Subs_numerical_error);
    T subs_numerical(const Ex &a,const T &b) const throw(Subs_numerical_error) {
        MapExNum m; m[a] = b;
        return subs_numerical(m);
    }
    
    
    Ex diff(const Ex &a) const;
    Ex diff(std::map<Ex,Ex,Ex::ExMapCmp> &m) const; /// beware : m will be modified, adding new elements
    
    
    typedef std::set<Ex,Ex::ExMapCmp> SetEx;
    void get_sub_symbols(SetEx &sub_symbols) const;
    void get_sub_nodes(SetEx &sub_nodes) const;
    unsigned nb_children_rec() const { return nb_children_op(op); }
    
    bool contain_nan_or_inf() const;
    
    unsigned nb_children() const;
    Ex child(unsigned i) const;
    unsigned nb_parents() const;
    Ex parent(unsigned i) const;
    /// an unique values for each different ops
    long id() const { return (long)op; }
    
    bool operator<(const Ex &e) const { return ( op < e.op ); }
    
    const Op *op;
private:
    static long unsigned current_id;
    
    void diff_rec() const;
    void subs_rec() const;
    void subs_with_test_rec(const MapEx &m_) const;
    
    static Ex diff(const Op *op,const Ex &a,const Ex &da);
    static Ex diff(const Op *op,const Ex &a,const Ex &da,const Ex &b,const Ex &db);
    
    friend Ex number(T v);
    friend Ex number(const char *v);
    friend Ex symbol(const char *std_name,const char *latex_name=NULL,void *additional_data=NULL,int movability_level=0);
    
    friend std::ostream &operator<<(std::ostream &os,const Ex &ex);
    friend bool operator==(const Ex &a,const Ex &b);
    friend bool operator==(const Ex &a,int b);
    friend bool operator==(const Ex &a,T b);
    friend Ex operator+(const Ex &a,const Ex &b);
    friend Ex operator-(const Ex &a,const Ex &b);
    friend Ex operator*(const Ex &a,const Ex &b);
    friend Ex operator/(const Ex &a,const Ex &b);
    
    friend Ex sqrt(const Ex &a);
    
    friend Ex abs(const Ex &a);
    friend Ex heavyside(const Ex &a);
    friend Ex heavyside_if(const Ex &a);
    friend Ex eqz(const Ex &a);
    friend Ex sin(const Ex &a);
    friend Ex cos(const Ex &a);
    friend Ex sgn(const Ex &a);
    friend Ex tan(const Ex &a);
    friend Ex log(const Ex &a);
    friend Ex exp(const Ex &a);
    friend Ex neg(const Ex &a);
    friend Ex asin(const Ex &a);
    friend Ex acos(const Ex &a);
    friend Ex atan(const Ex &a);
    
    friend Ex pow(const Ex &a,const Ex &b);
    friend Ex max(const Ex &a,const Ex &b);
    friend Ex atan2(const Ex &a,const Ex &b);

    friend Ex new_function_1(const std::string &f,const Ex &a);
    friend Ex new_function_2(const std::string &f,const Ex &a,const Ex &b);
};
    
bool is_a_function_1(const std::string &f);
bool is_a_function_2(const std::string &f);
bool is_a_function(const std::string &f);





Ex number(Ex::T v);
Ex number(const char *v);
Ex symbol(const char *std_name,const char *latex_name,void *additional_data,int movability_level);

std::ostream &operator<<(std::ostream &os,const Ex &ex);
bool operator==(const Ex &a,const Ex &b);
bool operator==(const Ex &a,int b);
bool operator==(const Ex &a,Ex::T b);
Ex operator+(const Ex &a,const Ex &b);
Ex operator-(const Ex &a,const Ex &b);
Ex operator*(const Ex &a,const Ex &b);
Ex operator/(const Ex &a,const Ex &b);
                            
Ex sqrt(const Ex &a);       
                            
Ex abs(const Ex &a);        
Ex heavyside(const Ex &a);  
Ex heavyside_if(const Ex &a);  
Ex eqz(const Ex &a);        
Ex sin(const Ex &a);        
Ex cos(const Ex &a);        
Ex sgn(const Ex &a);        
Ex tan(const Ex &a);        
Ex log(const Ex &a);        
Ex exp(const Ex &a);        
Ex neg(const Ex &a);        
Ex asin(const Ex &a);       
Ex acos(const Ex &a);       
Ex atan(const Ex &a);       
                            
Ex pow(const Ex &a,const Ex &b);
Ex max(const Ex &a,const Ex &b);
Ex atan2(const Ex &a,const Ex &b);
                            
Ex new_function_1(const std::string &f,const Ex &a);
Ex new_function_2(const std::string &f,const Ex &a,const Ex &b);
                            
                            
                            
                            
};
                            
#endif                      
