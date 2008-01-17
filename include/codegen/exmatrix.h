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
#ifndef CODEGENEXMATRIX_H
#define CODEGENEXMATRIX_H

#include "exvector.h"

namespace Codegen {

/**

@author LECLERC Hugo
*/
class ExMatrix {
public:
    explicit ExMatrix(unsigned nb_rows=0,unsigned nb_cols=0);
    ExMatrix copy() const { return *this; }
    
    Ex &operator()(unsigned i,unsigned j) { assert(i<_nb_rows and j<_nb_cols); return vec[j+i*_nb_cols]; }
    const Ex &operator()(unsigned i,unsigned j) const { assert(i<_nb_rows and j<_nb_cols); return vec[j+i*_nb_cols]; }
    unsigned nb_rows() const { return _nb_rows; }
    unsigned nb_cols() const { return _nb_cols; }
    std::string to_string(unsigned nb_spaces=0) const;
    std::string graphviz_repr() const { return "[[]]"; }
    
    ExMatrix subs(const Ex &a,const Ex &b) const;
    ExMatrix subs(std::map<Ex,Ex,Ex::ExMapCmp> &m) const;
    /// vector is row ordered : m(0,0), m(0,1), ... m(1,0), m(1,1), ...
    std::vector<Ex::T> subs_numerical(std::map<Ex,Ex::T,Ex::ExMapCmp> &m) const throw(Ex::Subs_numerical_error);
    ExMatrix diff(const Ex &a) const;
    ExMatrix diff(std::map<Ex,Ex,Ex::ExMapCmp> &m) const;
    
    void resize( unsigned r, unsigned c );
    
    
    bool is_null() const;
    bool depends_on(const Ex &ex) const;
    
    Ex max() const;
    Ex trace() const;
    //ExMatrix transpose() const;
    Ex determinant() const;
    ExVector solve( const ExVector &b ) const;
    ExVector solve( const ExVector &b, const Ex &det ) const;
    ExVector solve_regular_or_not( const ExVector &b ) const; // if matrix is singular, give a non null "solution" if b in Im(m). If not singular, give the unique solution
    ExVector solve_with_one_at( unsigned index, const ExVector &b ) const; // solve with imposed solution[index]=1
    ExVector find_eigen_values_sym() const; // assuming matrix is symetric
    Ex       find_one_eigen_value_sym() const; // assuming matrix is symetric
    ExMatrix find_eigen_vectors_sym( const ExVector &eigen_values ) const;
    ExMatrix find_eigen_vectors_sym_bis() const;
    ExMatrix without_col(unsigned col) const;
    ExMatrix without_row(unsigned row) const;
    ExVector col(unsigned col) const;
    ExVector row(unsigned row) const;
    ExMatrix inverse() const;
    ExMatrix transpose() const;
    ExMatrix operator-() const;
    void add_col( const ExVector &v );
    void add_row( const ExVector &v );
    
    static ExMatrix differentiate(const ExVector &ex,const ExVector &symbols);
private:
    std::vector<Ex> vec;
    unsigned _nb_rows,_nb_cols;

    friend Ex dot(const ExMatrix &a,const ExVector &b);
    friend Ex dot(const ExVector &a,const ExMatrix &b);
    friend Ex dot(const ExMatrix &a,const ExMatrix &b);
};
    
ExVector mul( const ExMatrix &a, const ExVector &b );
ExMatrix mul( const ExMatrix &a, const ExMatrix &b );

// if mat.size()=vec.size()+1, do it the OpenGL way
ExVector operator*(const ExMatrix &mat,const ExVector &vec);

ExMatrix operator+(const ExMatrix &a,const ExMatrix &b);
ExMatrix operator-(const ExMatrix &a,const ExMatrix &b);
// ExMatrix operator*(const ExMatrix &a,const ExMatrix &b);
ExMatrix operator/(const ExMatrix &a,const ExMatrix &b);
ExMatrix operator+(const ExMatrix &a,const Ex &b);
ExMatrix operator-(const ExMatrix &a,const Ex &b);
ExMatrix operator*(const ExMatrix &a,const Ex &b);
ExMatrix operator/(const ExMatrix &a,const Ex &b);
ExMatrix operator+(const Ex &a,const ExMatrix &b);
ExMatrix operator-(const Ex &a,const ExMatrix &b);
ExMatrix operator*(const Ex &a,const ExMatrix &b);
ExMatrix operator/(const Ex &a,const ExMatrix &b);
    
ExMatrix abs(const ExMatrix &a);
ExMatrix heavyside(const ExMatrix &a);
ExMatrix heavyside_if(const ExMatrix &a);
inline ExMatrix heaviside(const ExMatrix &a) { return heavyside(a); }
inline ExMatrix heaviside_if(const ExMatrix &a) { return heavyside_if(a); }
ExMatrix eqz(const ExMatrix &a);
ExMatrix sin(const ExMatrix &a);
ExMatrix cos(const ExMatrix &a);
ExMatrix sgn(const ExMatrix &a);
ExMatrix tan(const ExMatrix &a);
ExMatrix log(const ExMatrix &a);
ExMatrix exp(const ExMatrix &a);
ExMatrix neg(const ExMatrix &a);
ExMatrix asin(const ExMatrix &a);
ExMatrix acos(const ExMatrix &a);
ExMatrix atan(const ExMatrix &a);
    
    
Ex dot(const ExMatrix &a,const ExVector &b);
Ex dot(const ExVector &a,const ExMatrix &b);
Ex dot(const ExMatrix &a,const ExMatrix &b);
    
ExMatrix pow(const ExMatrix &a,const ExMatrix &b);
ExMatrix max(const ExMatrix &a,const ExMatrix &b);
ExMatrix pow(const ExMatrix &a,const Ex &b);
ExMatrix max(const ExMatrix &a,const Ex &b);
ExMatrix pow(const Ex &a,const ExMatrix &b);
ExMatrix max(const Ex &a,const ExMatrix &b);


std::ostream &operator<<(std::ostream &os,const ExMatrix &mat);

};

#endif // CODEGENEXMATRIX_H
