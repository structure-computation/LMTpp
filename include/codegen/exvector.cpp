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
#include "exvector.h"
#include "op.h"
#include <sstream>
#include <iostream>
#include <assert.h>
#include <algorithm>

namespace Codegen {

ExVector::ExVector(unsigned size) {
    vec.resize( size );
}
ExVector::ExVector(const Ex &e1) {
    vec.resize( 1 );
    vec[0] = e1;
}
ExVector::ExVector(const Ex &e1,const Ex &e2) {
    vec.resize( 2 );
    vec[0] = e1;
    vec[1] = e2;
}
ExVector::ExVector(const Ex &e1,const Ex &e2,const Ex &e3) {
    vec.resize( 3 );
    vec[0] = e1;
    vec[1] = e2;
    vec[2] = e3;
}
ExVector::ExVector(const Ex &e1,const Ex &e2,const Ex &e3,const Ex &e4) {
    vec.resize( 4 );
    vec[0] = e1;
    vec[1] = e2;
    vec[2] = e3;
    vec[3] = e4;
}
ExVector::ExVector(const Ex &e1,const Ex &e2,const Ex &e3,const Ex &e4,const Ex &e5) {
    vec.resize( 5 );
    vec[0] = e1;
    vec[1] = e2;
    vec[2] = e3;
    vec[3] = e4;
    vec[4] = e5;
}
ExVector::ExVector(const Ex &e1,const Ex &e2,const Ex &e3,const Ex &e4,const Ex &e5,const Ex &e6) {
    vec.resize( 6 );
    vec[0] = e1;
    vec[1] = e2;
    vec[2] = e3;
    vec[3] = e4;
    vec[4] = e5;
    vec[5] = e6;
}
    
ExVector &ExVector::operator/=(const Ex &a) { *this = *this / a; return *this; }

bool ExVector::has(const Ex &ex) const {
    return ( std::find(vec.begin(),vec.end(),ex) != vec.end() );
}
std::string ExVector::to_string() const {
    std::ostringstream ss;
    ss << *this;
    return ss.str();
}

ExVector ExVector::subs(const Ex &a,const Ex &b) const {
    std::map<Ex,Ex,Ex::ExMapCmp> m;
    m[a] = b;
    return subs(m);
}
ExVector ExVector::subs(std::map<Ex,Ex,Ex::ExMapCmp> &m) const {
    ExVector res( size() );
    for(unsigned i=0;i<size();++i)
        res(i) = vec[i].subs(m);
    return res;
}
std::vector<Ex::T> ExVector::subs_numerical(std::map<Ex,Ex::T,Ex::ExMapCmp> &m) const throw(Ex::Subs_numerical_error) {
    std::vector<Ex::T> res( size() );
    for(unsigned i=0;i<size();++i)
        res[i] = vec[i].subs_numerical(m);
    return res;
}
ExVector ExVector::diff(const Ex &a) const {
    std::map<Ex,Ex,Ex::ExMapCmp> m;
    m[a] = 1.0;
    return diff(m);
}
ExVector ExVector::diff(std::map<Ex,Ex,Ex::ExMapCmp> &m) const {
    ExVector res( size() );
    for(unsigned i=0;i<size();++i)
        res(i) = vec[i].diff(m);
    return res;
}
void ExVector::get_sub_symbols(std::set<Ex,Ex::ExMapCmp> &sub_symbols) const {
    for(unsigned i=0;i<size();++i)
        vec[i].get_sub_symbols(sub_symbols);
}
Ex ExVector::max() const {
    if ( size()==0 )
        return 0;
    Ex res = vec[0];
    for(unsigned i=1;i<size();++i)
        res = Codegen::max( res, vec[i] );
    return res;
}
Ex ExVector::sum() const {
    Ex res;
    for(unsigned i=0;i<size();++i)
        res += vec[i];
    return res;
}
ExVector ExVector::operator-() const {
    ExVector res( size() );
    for(unsigned i=0;i<size();++i)
        res(i) = -vec[i];
    return res;
}
ExVector ExVector::differentiate(const Ex &ex,const ExVector &symbols) {
    ExVector res( symbols.size() );
    for(unsigned i=0;i<res.size();++i)
        res(i) = ex.diff(symbols(i));
    return res;
}
bool ExVector::is_null() const {
    for(unsigned i=0;i<vec.size();++i)
        if ( (not vec[i].is_a_number()) or vec[i].get_val()!=0.0 )
            return false;
    return true;
}
bool ExVector::depends_on(const Ex &ex) const {
    for(unsigned i=0;i<vec.size();++i)
        if ( vec[i].depends_on(ex) )
            return true;
    return false;

}

#define BOP(V,CV) \
ExVector operator V(const ExVector &a,const ExVector &b) { \
    ExVector res(std::min(a.size(),b.size())); \
    for(unsigned i=0;i<res.size();++i) \
        res(i) = a(i) V b(i); \
    return res; \
} \
ExVector operator V(const ExVector &a,const Ex &b) { \
    ExVector res(a.size()); \
    for(unsigned i=0;i<res.size();++i) \
        res(i) = a(i) V b; \
    return res; \
} \
ExVector operator V(const Ex &a,const ExVector &b) { \
    ExVector res(b.size()); \
    for(unsigned i=0;i<res.size();++i) \
        res(i) = a V b(i); \
    return res; \
} \
ExVector ExVector::CV(const ExVector &a) { \
    unsigned s = std::min(a.size(),size()); \
    ExVector res(s); \
    for(unsigned i=0;i<s;++i) \
        res[i] = vec[i] V a(i); \
    *this = res; \
    return *this; \
}
BOP(+,operator+=)
BOP(-,operator-=)
BOP(*,operator*=)
BOP(/,operator/=)
#undef BOP    

#define BOP(V) \
ExVector V(const ExVector &a) { \
    ExVector res(a.size()); \
    for(unsigned i=0;i<a.size();++i) \
        res(i) = V(a(i)); \
    return res; \
}
BOP(sqrt)
BOP(abs)
BOP(heavyside)
BOP(heavyside_if)
BOP(eqz)
BOP(sin)
BOP(cos)
BOP(sgn)
BOP(tan)
BOP(log)
BOP(exp)
BOP(neg)
BOP(asin)
BOP(acos)
BOP(atan)
#undef BOP    
    
#define BOP(V) \
ExVector V(const ExVector &a,const ExVector &b) { \
    ExVector res(std::min(a.size(),b.size())); \
    for(unsigned i=0;i<res.size();++i) \
        res(i) = V(a(i),b(i)); \
    return res; \
} \
ExVector V(const ExVector &a,const Ex &b) { \
    ExVector res(a.size()); \
    for(unsigned i=0;i<res.size();++i) \
        res(i) = V(a(i),b); \
    return res; \
} \
ExVector V(const Ex &a,const ExVector &b) { \
    ExVector res(b.size()); \
    for(unsigned i=0;i<res.size();++i) \
        res(i) = V(a,b(i)); \
    return res; \
}
BOP(pow)
BOP(mini)
BOP(max)
#undef BOP    

Ex dot(const ExVector &a,const ExVector &b) {
    Ex res;
    for(unsigned i=0;i<std::min(a.size(),b.size());++i)
        res += a(i) * b(i);
    return res;
}

Ex norm(const ExVector &a,Ex::T additional_val) {
    Ex res;
    for(unsigned i=0;i<a.size();++i)
        res += pow(a(i),2);
    return sqrt(res+additional_val);
}

Ex norm_2(const ExVector &a,Ex::T additional_val) {
    Ex res;
    for(unsigned i=0;i<a.size();++i)
        res += pow(a(i),2);
    return sqrt(res+additional_val);
}

ExVector vect_prod(const ExVector &v1,const ExVector &v2) {
    assert( v1.size()==v2.size() );
    if ( v2.size()==3 )
        return ExVector(
            v1(1)*v2(2) - v1(2)*v2(1),
            v1(2)*v2(0) - v1(0)*v2(2),
            v1(0)*v2(1) - v1(1)*v2(0)
        );
    return ExVector( v1(0)*v2(1) - v1(1)*v2(0) );
}

ExVector solve( const ExVector &eqs, const ExVector &unk, const ExVector &beg, const Ex &precision ) {
    //
    Op *sol = new Op;
    sol->type = Op::Solver;
    sol->p_data = new Op *[ eqs.size() + unk.size() + beg.size() + 4 ];
    int o = 0;
    for( int i = 0; i < eqs.size(); ++i )
        sol->p_data[ o++ ] = inc_ref( eqs[ i ].op );
    sol->p_data[ o++ ] = 0;
    for( int i = 0; i < unk.size(); ++i )
        sol->p_data[ o++ ] = inc_ref( unk[ i ].op );
    sol->p_data[ o++ ] = 0;
    for( int i = 0; i < beg.size(); ++i )
        sol->p_data[ o++ ] = inc_ref( beg[ i ].op );
    sol->p_data[ o++ ] = 0;
    sol->p_data[ o++ ] = inc_ref( precision.op );

    //
    ExVector res( unk.size() );
    for( int i = 0; i < unk.size(); ++i )
        res[ i ] = make_sub_sol( sol, i );
    return res;
}


std::ostream &operator<<(std::ostream &os,const Codegen::ExVector &vec) {
    for(unsigned i=0;i<vec.size();++i)
        os << vec(i) << ( i==vec.size()-1 ? ' ' : ',' );
    return os;
}

ExVector pos_part(const ExVector &a) {
    return a * heaviside( a );
}

ExVector neg_part(const ExVector &a) {
    return a * heaviside( - a );
}

};

