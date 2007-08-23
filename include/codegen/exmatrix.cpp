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
#include "exmatrix.h"
#include <sstream>
#include <iostream>
#include <assert.h>
#include "exvector.h"

namespace Codegen {

ExMatrix::ExMatrix(unsigned nb_rows,unsigned nb_cols):_nb_rows(nb_rows),_nb_cols(nb_cols) {
    vec.resize( _nb_rows * _nb_cols );
}

std::string ExMatrix::to_string(unsigned nb_spaces) const {
    std::ostringstream os;
    for(unsigned i=0;i<nb_rows();++i) {
        for(unsigned j=0;j<nb_spaces;++j)
            os << ' ';
        for(unsigned j=0;j<nb_cols();++j)
            os << operator()(i,j) << ' ';
        os << std::endl;
    }
    return os.str();
}

ExMatrix ExMatrix::subs(const Ex &a,const Ex &b) const {
    std::map<Ex,Ex,Ex::ExMapCmp> m;
    m[a] = b;
    return subs(m);
}
ExMatrix ExMatrix::subs(std::map<Ex,Ex,Ex::ExMapCmp> &m) const {
    ExMatrix res( nb_rows(), nb_cols() );
    for(unsigned i=0;i<nb_rows();++i)
        for(unsigned j=0;j<nb_cols();++j)
            res(i,j) = operator()(i,j).subs(m);
    return res;
}
std::vector<Ex::T> ExMatrix::subs_numerical(std::map<Ex,Ex::T,Ex::ExMapCmp> &m) const throw(Ex::Subs_numerical_error) {
    std::vector<Ex::T> res( nb_rows() * nb_cols() );
    for(unsigned i=0,cpt=0;i<nb_rows();++i)
        for(unsigned j=0;j<nb_cols();++j,++cpt)
            res[cpt] = operator()(i,j).subs_numerical(m);
    return res;
}
ExMatrix ExMatrix::diff(const Ex &a) const {
    std::map<Ex,Ex,Ex::ExMapCmp> m;
    m[a] = 1.0;
    return diff(m);
}
ExMatrix ExMatrix::diff(std::map<Ex,Ex,Ex::ExMapCmp> &m) const {
    ExMatrix res( nb_rows(), nb_cols() );
    for(unsigned i=0;i<nb_rows();++i)
        for(unsigned j=0;j<nb_cols();++j)
            res(i,j) = operator()(i,j).diff(m);
    return res;
}
ExVector operator*(const ExMatrix &mat,const ExVector &vec) {
    assert( mat.nb_cols()==vec.size() );
    unsigned nr = mat.nb_rows();
    unsigned nc = std::min( mat.nb_cols(), vec.size() );
    ExVector res(nr);
    for(unsigned i=0;i<nr;++i)
        for(unsigned j=0;j<nc;++j)
            res(i) += mat(i,j) * vec(j);
    return res;
}

Ex ExMatrix::max() const {
    if ( vec.size()==0 )
        return 0;
    Ex res = vec[0];
    for(unsigned i=1;i<vec.size();++i)
        res = Codegen::max( res, vec[i] );
    return res;
}
Ex ExMatrix::trace() const {
    Ex res;
    for(unsigned i=0;i<std::min(nb_rows(),nb_cols());++i)
        res += operator()(i,i);
    return res;
}
Ex ExMatrix::determinant() const {
    assert( nb_rows()==nb_cols() );
    unsigned nr = nb_rows();
    if ( nr==0 ) return 1;
    if ( nr==1 ) return operator()(0,0);
    Ex res;
    ExMatrix Ac( without_col(0) );
    for(unsigned l=0;l<nr;++l)
        res += (1.0-2.0*(l&1)) * operator()(l,0) * Ac.without_row(l).determinant();
    return res;
}
ExMatrix ExMatrix::without_col(unsigned col) const {
    ExMatrix res( nb_rows(), nb_cols()-1 );
    for(unsigned i=0;i<nb_rows();++i) {
        for(unsigned j=0;j<col;++j)
            res(i,j) = operator()(i,j);
        for(unsigned j=col+1;j<nb_cols();++j)
            res(i,j-1) = operator()(i,j);
    }
    return res;
}
ExMatrix ExMatrix::without_row(unsigned row) const {
    ExMatrix res( nb_rows()-1, nb_cols() );
    for(unsigned i=0;i<row;++i)
        for(unsigned j=0;j<nb_cols();++j)
            res(i,j) = operator()(i,j);
    for(unsigned i=row+1;i<nb_rows();++i)
        for(unsigned j=0;j<nb_cols();++j)
            res(i-1,j) = operator()(i,j);
    return res;
}

ExVector ExMatrix::col(unsigned c) const {
   ExVector res( nb_rows() );
   for(unsigned i=0;i<nb_rows();++i) {
         res[i] = operator()(i,c);
   }
   return res;
}
ExVector ExMatrix::row(unsigned c) const {
   ExVector res( nb_cols() );
   for(unsigned i=0;i<nb_cols();++i) {
      res[i] = operator()(c,i);
   }
   return res;
}



ExMatrix ExMatrix::inverse() const {
    assert( nb_rows()==nb_cols() );
    unsigned nr = nb_rows();
    ExMatrix res(nr,nr);
    if ( nb_rows()==1 ) {
        res(0,0) = 1.0 / operator()(0,0);
        return res;
    }
    Ex det = determinant();
    for(unsigned i=0;i<nb_rows();++i) {
        ExMatrix Ac( without_row(i) );
        for(unsigned j=0;j<nb_cols();++j)
            res(j,i) = (1.0-2.0*((i+j)&1)) * Ac.without_col(j).determinant() / det;
    }
    return res;
}
ExMatrix ExMatrix::transpose() const {
    ExMatrix res( nb_cols(), nb_rows() );
    for(unsigned i=0;i<nb_cols();++i)
        for(unsigned j=0;j<nb_rows();++j)
            res(i,j) = operator()(j,i);
    return res;
}
ExMatrix ExMatrix::operator-() const {
    ExMatrix res( nb_rows(), nb_cols() );
    for(unsigned i=0;i<nb_rows();++i)
        for(unsigned j=0;j<nb_cols();++j)
            res(i,j) = -operator()(i,j);
    return res;
}
ExMatrix ExMatrix::differentiate(const ExVector &ex,const ExVector &symbols) {
    ExMatrix res( ex.size(), symbols.size() );
    for(unsigned j=0;j<symbols.size();++j) {
        std::map<Ex,Ex,Ex::ExMapCmp> m;
        m[symbols(j)] = 1.0;
        for(unsigned i=0;i<ex.size();++i)
            res(i,j) = ex(i).diff(m);
    }
    return res;
}
bool ExMatrix::is_null() const {
    for(unsigned i=0;i<vec.size();++i)
        if ( (not vec[i].is_a_number()) or vec[i].get_val()!=0.0 )
            return false;
    return true;
}
bool ExMatrix::depends_on(const Ex &ex) const {
    for(unsigned i=0;i<vec.size();++i)
        if ( vec[i].depends_on(ex) )
            return true;
    return false;

}

Ex dot(const ExMatrix &a,const ExVector &b) {
    Ex res;
    assert( b.size() == a.nb_cols()*a.nb_rows() );
    assert( a.nb_cols() == 1 or a.nb_rows() == 1 );
    for(unsigned i=0;i<b.size();++i)
        res += a.vec[i] * b[i];
    return res;
}

Ex dot(const ExVector &a,const ExMatrix &b) { return dot(b,a); }

Ex dot(const ExMatrix &a,const ExMatrix &b) {
    Ex res;
    assert( (a.nb_cols()== b.nb_cols()) and (a.nb_rows()==b.nb_rows()) );
    for(unsigned i=0;i<b.nb_rows();++i){
        for(unsigned j=0;j<b.nb_cols();++j)
            res += a.operator()(i,j) * b.operator()(i,j);
    }
    return res;
//     Ex res;
//     assert( a.nb_cols()*a.nb_rows() == b.nb_cols()*b.nb_rows() );
//     for(unsigned i=0;i<b.nb_cols()*b.nb_rows();++i)
//         res += a.vec[i] * b.vec[i];
//     return res;
}

#define BOP(V) \
ExMatrix operator V(const ExMatrix &a,const ExMatrix &b) { \
    ExMatrix res(std::min(a.nb_rows(),b.nb_rows()),std::min(a.nb_cols(),b.nb_cols())); \
    for(unsigned i=0;i<res.nb_rows();++i) \
        for(unsigned j=0;j<res.nb_cols();++j) \
            res(i,j) = a(i,j) V b(i,j); \
    return res; \
} \
ExMatrix operator V(const ExMatrix &a,const Ex &b) { \
    ExMatrix res(a.nb_rows(),a.nb_cols()); \
    for(unsigned i=0;i<res.nb_rows();++i) \
        for(unsigned j=0;j<res.nb_cols();++j) \
           res(i,j) = a(i,j) V b; \
    return res; \
} \
ExMatrix operator V(const Ex &a,const ExMatrix &b) { \
    ExMatrix res(b.nb_rows(),b.nb_cols()); \
    for(unsigned i=0;i<res.nb_rows();++i) \
        for(unsigned j=0;j<res.nb_cols();++j) \
            res(i,j) = a V b(i,j); \
    return res; \
}
BOP(+)
BOP(-)
BOP(*)
BOP(/)
#undef BOP    

#define BOP(V) \
ExMatrix V(const ExMatrix &a) { \
    ExMatrix res(a.nb_rows(),a.nb_cols()); \
    for(unsigned i=0;i<res.nb_rows();++i) \
        for(unsigned j=0;j<res.nb_cols();++j) \
            res(i,j) = V(a(i,j)); \
    return res; \
}
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
ExMatrix V(const ExMatrix &a,const ExMatrix &b) { \
    ExMatrix res(std::min(a.nb_rows(),b.nb_rows()),std::min(a.nb_cols(),b.nb_cols())); \
    for(unsigned i=0;i<res.nb_rows();++i) \
        for(unsigned j=0;j<res.nb_cols();++j) \
            res(i,j) = V(a(i,j),b(i,j)); \
    return res; \
} \
ExMatrix V(const ExMatrix &a,const Ex &b) { \
    ExMatrix res(a.nb_rows(),a.nb_cols()); \
    for(unsigned i=0;i<res.nb_rows();++i) \
        for(unsigned j=0;j<res.nb_cols();++j) \
            res(i,j) = V(a(i,j),b); \
    return res; \
} \
ExMatrix V(const Ex &a,const ExMatrix &b) { \
    ExMatrix res(b.nb_rows(),b.nb_cols()); \
    for(unsigned i=0;i<res.nb_rows();++i) \
        for(unsigned j=0;j<res.nb_cols();++j) \
            res(i,j) = V(a,b(i,j)); \
    return res; \
}
BOP(pow)
BOP(max)
#undef BOP    

std::ostream &operator<<(std::ostream &os,const ExMatrix &mat) {
    for(unsigned i=0;i<mat.nb_rows();++i) {
        for(unsigned j=0;j<mat.nb_cols();++j)
            os << mat(i,j) << ( j==mat.nb_cols()-1 ? ' ' : ',' );
        os << std::endl;
    }
    return os;
}

};

