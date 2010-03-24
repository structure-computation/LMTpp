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
#ifndef CODEGENExVector_H
#define CODEGENExVector_H

#include "ex.h"
#include <assert.h>

#ifdef METIL_COMP_DIRECTIVE
#pragma src_file exvector.cpp
#endif

namespace Codegen {

/*!
    Cette classe sert pour le calcul symbolique des formulations écrites en Python.

    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \author LECLERC Hugo
*/
class ExVector {
public:
    explicit ExVector(unsigned size=0);
    explicit ExVector(const Ex &e1);
    explicit ExVector(const Ex &e1,const Ex &e2);
    explicit ExVector(const Ex &e1,const Ex &e2,const Ex &e3);
    explicit ExVector(const Ex &e1,const Ex &e2,const Ex &e3,const Ex &e4);
    explicit ExVector(const Ex &e1,const Ex &e2,const Ex &e3,const Ex &e4,const Ex &e5);
    explicit ExVector(const Ex &e1,const Ex &e2,const Ex &e3,const Ex &e4,const Ex &e5,const Ex &e6);
    Ex &operator()(unsigned i) { assert(i<vec.size()); return vec[i]; }
    const Ex &operator()(unsigned i) const { assert(i<vec.size()); return vec[i]; }
    Ex &operator[](unsigned i) { assert(i<vec.size()); return vec[i]; }
    const Ex &operator[](unsigned i) const { assert(i<vec.size()); return vec[i]; }
    void push_back(const Ex &ex) { vec.push_back(ex); }
    void clear() { vec.clear(); }
    bool has(const Ex &ex) const;
    void resize(unsigned s) { vec.resize(s); }
    unsigned size() const { return vec.size(); }
    std::string to_string() const;
    std::string graphviz_repr() const { return "[]"; }
    
    bool is_null() const;
    bool depends_on(const Ex &ex) const;
    
    ExVector subs(const Ex &a,const Ex &b) const;
    ExVector subs(std::map<Ex,Ex,Ex::ExMapCmp> &m) const;
    std::vector<Ex::T> subs_numerical(std::map<Ex,Ex::T,Ex::ExMapCmp> &m) const throw(Ex::Subs_numerical_error);
    ExVector diff(const Ex &a) const;
    ExVector diff(std::map<Ex,Ex,Ex::ExMapCmp> &m) const;
    void get_sub_symbols(std::set<Ex,Ex::ExMapCmp> &sub_symbols) const;
    
    Ex max() const;
    Ex sum() const;
    
    ExVector operator-() const;
    ExVector operator+=(const ExVector &a);
    ExVector operator-=(const ExVector &a);
    ExVector operator*=(const ExVector &a);
    ExVector operator/=(const ExVector &a);
    
    ExVector &operator/=(const Ex &a);
    
    static ExVector differentiate(const Ex &ex,const ExVector &symbols);
private:
    std::vector<Ex> vec;
};
    
ExVector operator+(const ExVector &a,const ExVector &b);
ExVector operator-(const ExVector &a,const ExVector &b);
ExVector operator*(const ExVector &a,const ExVector &b);
ExVector operator/(const ExVector &a,const ExVector &b);
ExVector operator+(const ExVector &a,const Ex &b);
ExVector operator-(const ExVector &a,const Ex &b);
ExVector operator*(const ExVector &a,const Ex &b);
ExVector operator/(const ExVector &a,const Ex &b);
ExVector operator+(const Ex &a,const ExVector &b);
ExVector operator-(const Ex &a,const ExVector &b);
ExVector operator*(const Ex &a,const ExVector &b);
ExVector operator/(const Ex &a,const ExVector &b);
    
ExVector sqrt(const ExVector &a);
ExVector abs(const ExVector &a);
ExVector heavyside(const ExVector &a);
ExVector heavyside_if(const ExVector &a);
inline ExVector heaviside(const ExVector &a) { return heavyside(a); }
inline ExVector heaviside_if(const ExVector &a) { return heavyside_if(a); }
ExVector eqz(const ExVector &a);
ExVector sin(const ExVector &a);
ExVector cos(const ExVector &a);
ExVector sgn(const ExVector &a);
ExVector tan(const ExVector &a);
ExVector log(const ExVector &a);
ExVector exp(const ExVector &a);
ExVector neg(const ExVector &a);
ExVector asin(const ExVector &a);
ExVector acos(const ExVector &a);
ExVector atan(const ExVector &a);
    
ExVector pow(const ExVector &a,const ExVector &b);
ExVector max(const ExVector &a,const ExVector &b);
ExVector mini(const ExVector &a,const ExVector &b);
ExVector pow(const ExVector &a,const Ex &b);
ExVector max(const ExVector &a,const Ex &b);
ExVector mini(const ExVector &a,const Ex &b);
ExVector pow(const Ex &a,const ExVector &b);
ExVector max(const Ex &a,const ExVector &b);
ExVector mini(const Ex &a,const ExVector &b);

ExVector pos_part(const ExVector &a);
ExVector neg_part(const ExVector &a);

Ex dot(const ExVector &a,const ExVector &b);
/// sqrt(dot(a,a)+additional_val)
Ex norm(const ExVector &a,Ex::T additional_val=0.0);
/// sqrt(dot(a,a)+additional_val)
Ex norm_2(const ExVector &a,Ex::T additional_val=0.0);
/// dot( a, a )
inline Ex norm_2_squared( const ExVector &a ) { return dot( a, a ); }
/// defined only in 3D
ExVector vect_prod(const ExVector &v1,const ExVector &v2);

std::ostream &operator<<(std::ostream &os,const Codegen::ExVector &vec);

};


#endif // CODEGENExVectorVector_H
