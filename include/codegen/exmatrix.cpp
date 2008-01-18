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
#include <complex>
#include <set>
#include "exvector.h"
#define PRINT( A ) \
    std::cout << "  " << __STRING(A) << std::flush << " -> " << (A) << std::endl
#define PRINTN( A ) \
    std::cout << "  " << __STRING(A) << std::flush << " ->\n" << (A) << std::endl

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

ExVector ExMatrix::solve( const ExVector &v ) const {
    Ex d = determinant();
    return solve( v, d + eqz(d) );
}

ExVector ExMatrix::solve( const ExVector &v, const Ex &det ) const {
    unsigned s = nb_rows();
    ExVector r( s );
    for(unsigned i=0;i<s;++i) {
        ExMatrix m = *this;
        for(unsigned j=0;j<s;++j)
            m(i,j) = v[j];
        r[i] = m.determinant() / det;
    }
    return r;
}

ExMatrix mul( const ExMatrix &a, const ExMatrix &b ) {
    assert( a.nb_cols() == b.nb_rows() );
    ExMatrix res( a.nb_rows(), b.nb_cols() );
    for(unsigned i=0;i<a.nb_rows();++i)
        for(unsigned j=0;j<b.nb_cols();++j)
            for(unsigned k=0;k<a.nb_cols();++k)
                res( i, j ) += a( i, k ) * b( k, j );
    return res;
}

ExVector mul( const ExMatrix &mat, const ExVector &vec ) {
    assert( mat.nb_cols() == vec.size() );
    unsigned nr = mat.nb_rows(), nc = mat.nb_cols();
    ExVector res(nr);
    for(unsigned i=0;i<nr;++i)
        for(unsigned j=0;j<nc;++j)
            res(i) += mat(i,j) * vec(j);
    return res;
}

ExVector ExMatrix::solve_with_one_at( unsigned index, const ExVector &b, bool zero_at_the_beginning ) const {
    ExMatrix m = without_col( index );
    //
    if ( zero_at_the_beginning )
        for(unsigned i=0;i<index;++i)
            m = m.without_col( 0 );
    
    ExVector v = b - col( index );
    ExMatrix a = mul( m.transpose(), m );
    ExVector r = mul( m.transpose(), v );
    ExVector tmp = a.solve_regular_or_not( r );
    //
    unsigned s = nb_cols();
    ExVector res( s );
    if ( zero_at_the_beginning ) {
        res[index] = 1;
        for(unsigned i=index+1,cpt=0;i<s;++i)
            res[i] = tmp[cpt++];
    }
    else {
        for(unsigned i=0;i<index;++i)
            res[i] = tmp[i];
        res[index] = 1;
        for(unsigned i=index+1;i<s;++i)
            res[i] = tmp[i-1];
    }
    return res;
}

template<class T>
T find_prop_that_minimize_error( const std::vector<T> &propositions, const std::vector<Ex> &errors ) {
    T res = propositions[0];
    Ex mi = errors[0];
    for(unsigned i=1;i<propositions.size();++i) {
        Ex want = 1 - heaviside( errors[i] - mi );
        mi = want * errors[i] + ( 1 - want ) * mi;
        res = want * propositions[i] + ( 1 - want ) * res;
    }
    return res;
}

ExVector ExMatrix::solve_regular_or_not( const ExVector &b ) const {
    //
    if ( nb_cols() == 1 ) {
        ExVector r(1); Ex d = operator()(0,0);
        r[0] = b[0] / ( d + eqz(d) ) * ( 1 - eqz(d) ) + eqz(d);
        return r;
    }
    //
    std::vector<ExVector> propositions;
    std::vector<Ex> errors;
    // cramer
    ExVector X = solve( b );
    propositions.push_back( X );
    errors.push_back( norm_2_squared( mul( *this, X ) - b ) );
    // with imposed values
    for(unsigned i=0;i<nb_rows();++i) {
        X = solve_with_one_at( i, b );
        propositions.push_back( X );
        errors.push_back( norm_2_squared( mul( *this, X ) - b ) );
    }
    return find_prop_that_minimize_error( propositions, errors );
}

ExVector get_eig_poly( const ExMatrix &self ) {
    unsigned s = self.nb_cols();
    if ( s == 0 )
        return ExVector( 0 );
    if ( s == 1 )
        return ExVector( self(0,0), -1 );
    if ( s == 2 )
        return ExVector( self(0,0) * self(1,1) - self(1,0) * self(0,1), - self(1,1) - self(0,0), 1 );
    if ( s == 3 )
        return ExVector(
            self(0,0)*(self(1,1)*self(2,2)-self(2,1)*self(1,2))-self(1,0)*(self(0,1)*self(2,2)-self(2,1)*self(0,2))+self(2,0)*(self(0,1)*self(1,2)-self(1,1)*self(0,2)),
            self(2,1) * self(1,2) + self(1,0)*self(0,1) + self(2,0)*self(0,2) - self(0,0)*(self(2,2)+self(1,1)) - self(1,1)*self(2,2),
            self(2,2) + self(1,1) + self(0,0),
            Ex( -1 )
        );
    // else -> generic case
    Ex lambda("lambda");
    ExMatrix md = self;
    for(unsigned i=0;i<s;++i)
        md(i,i) -= lambda;
    assert( 0 /*TODO*/ );
    ExVector res;
    return res;
}

std::complex<Ex> powc( const std::complex<Ex> &v, double p ) {
    Ex m = log( abs( v ) ), a = arg( v );
    return std::exp( Ex( p ) * std::complex<Ex>( m, a ) );
    //     return v * pow( m, p ) / ( m + eqz( m ) ) * ( 1 - eqz( m ) );
}

ExVector roots_of_poly_assumed_real( const ExVector &pol ) {
    if ( pol.size() <= 1 )
        return ExVector( 0 );
    if ( pol.size() == 2 )
        return ExVector( - pol[0] / ( pol[1] + eqz(pol[1]) ) );
    if ( pol.size() == 3 ) {
        Ex a = pol[2], b = pol[1], c = pol[0];
        Ex delta = pow( b, 2 ) - 4 * a * c;
        return ExVector(
            ( - b - sqrt( delta ) ) / ( 2 * a ),
            ( - b + sqrt( delta ) ) / ( 2 * a )
        );
    }
    if ( pol.size() == 4 ) {
        Ex a = pol[2] / pol[3];
        Ex b = pol[1] / pol[3];
        Ex c = pol[0] / pol[3];
        Ex p = b - pow(a,2) / 3;
        Ex q = pow(a,3) / 13.5 - a * b / 3 + c;
        Ex delta = 4 * pow(p,3) + 27 * pow(q,2);
        Ex trois = 3;
        //delta >= 0
        //         Ex u = (-27*q+sqrt(27*delta))/2;
        //         Ex v = (-27*q-sqrt(27*delta))/2;
        //         res += heaviside( delta ) * ExVector(
        //             sgn(u)*pow(abs(u),1.0/3.0)+sgn(v)*pow(abs(v),1.0/3.0)-a)/3.0
        //         );
        //delta < 0
        std::complex<Ex> j( -1.0/2.0, sqrt(3.0)/2.0 );
        std::complex<Ex> v( -27.0*q/2.0, sqrt(-27.0*delta)/2.0 );
        std::complex<Ex> u( powc( v, 1.0/3.0 ) );
        ExVector res;
        res.push_back( ( 2.0 * std::real(    u)-a ) / 3.0 );
        res.push_back( ( 2.0 * std::real(  j*u)-a ) / 3.0 );
        res.push_back( ( 2.0 * std::real(j*j*u)-a ) / 3.0 );
        return res;
    }
    
    assert( 0 /*TODO*/ );
    return ExVector();
}

Ex one_root_of_poly_assumed_real( const ExVector &pol ) {
    if ( pol.size() <= 1 )
        return 0;
    if ( pol.size() == 2 )
        return - pol[0] / ( pol[1] + eqz(pol[1]) );
    if ( pol.size() == 3 ) {
        Ex a = pol[2], b = pol[1], c = pol[0];
        Ex delta = pow( b, 2 ) - 4 * a * c;
        return ( - b + sqrt( delta ) ) / ( 2 * a );
    }
    if ( pol.size() == 4 ) {
        Ex a = pol[2] / pol[3];
        Ex b = pol[1] / pol[3];
        Ex c = pol[0] / pol[3];
        Ex p = b - pow(a,2) / 3;
        Ex q = pow(a,3) / 13.5 - a * b / 3 + c;
        Ex delta = 4 * pow(p,3) + 27 * pow(q,2);
        Ex trois = 3;
        //delta >= 0
        //         Ex u = (-27*q+sqrt(27*delta))/2;
        //         Ex v = (-27*q-sqrt(27*delta))/2;
        //         res += heaviside( delta ) * ExVector(
        //             sgn(u)*pow(abs(u),1.0/3.0)+sgn(v)*pow(abs(v),1.0/3.0)-a)/3.0
        //         );
        //delta < 0
        std::complex<Ex> v( -27.0*q/2.0, sqrt(-27.0*delta)/2.0 );
        std::complex<Ex> u( powc( v, 1.0/3.0 ) );
        return ( 2.0 * std::real(u)-a ) / 3.0;
    }
    
    assert( 0 /*TODO*/ );
    return 0;
}

ExVector ExMatrix::find_eigen_values_sym() const {
    assert( nb_rows() == nb_cols() );
    unsigned s = nb_rows();
    ExVector res( s );
    //
    ExVector pol = get_eig_poly( *this );
    return roots_of_poly_assumed_real( pol );
}

Ex ExMatrix::find_one_eigen_value_sym() const {
    ExVector pol = get_eig_poly( *this );
    return one_root_of_poly_assumed_real( pol );
}

/*
    return 
*/
ExMatrix ExMatrix::find_eigen_vectors_sym( const ExVector &eigen_values ) const {
    unsigned s = nb_rows(); assert( nb_rows() == nb_cols() );
        
    ExMatrix eigen_vectors( s, 0 );
    ExVector sum_of_want_vector( s );
    for(unsigned num_eig_val=0;num_eig_val < std::min( eigen_values.size(), s-1 );++num_eig_val) {
        //
        Ex eig_val = eigen_values[ num_eig_val ];
    
        // m - lambda * Id
        ExMatrix md = *this;
        for(unsigned i=0;i<s;++i)
            md(i,i) -= eig_val;
        // orthogonality
        for(unsigned num_old=0;num_old<eigen_vectors.nb_cols();++num_old)
            md.add_row( eigen_vectors.col(num_old) );
    
        //
        std::vector<ExVector> propositions;
        std::vector<Ex> errors;
        ExVector so( md.nb_rows() );
        ExVector best_eig_vec( s );
        Ex min_error;
        ExVector want_vector( s );
        for(unsigned num_trial=0;num_trial<s;++num_trial) {
            ExVector eig_vec_proposition = md.solve_with_one_at( num_trial, so, true );
            //
            Ex error = norm_2_squared( mul( md, eig_vec_proposition ) - so );
            Ex want = ( num_trial == 0 ? 1 : 1 - heaviside( error - min_error ) );
            min_error = min_error + want * ( error - min_error );
            best_eig_vec = best_eig_vec + want * ( eig_vec_proposition - best_eig_vec );
            //
            ExVector one_at_num_trial( s ); one_at_num_trial[ num_trial ] = 1;
            want_vector = want_vector + want * ( one_at_num_trial - want_vector );
        }
        sum_of_want_vector += want_vector;
        best_eig_vec /= norm_2( best_eig_vec );
        eigen_vectors.add_col( best_eig_vec );
    }
    
    // last eig vec
    if ( eigen_values.size() == s ) {
        if ( s == 1 )
            eigen_vectors.add_col( ExVector( Ex(1) ) );
        else if ( s == 2 )
            eigen_vectors.add_col( ExVector( -eigen_vectors(1,0), eigen_vectors(0,0) ) );
        else if ( s == 3 )
            eigen_vectors.add_col( vect_prod( eigen_vectors.col(0), eigen_vectors.col(1) ) );
        else {
            ExVector eig_vec_proposition = 1 - sum_of_want_vector;
            for(unsigned num_old=0;num_old<eigen_vectors.nb_cols();++num_old)
                eig_vec_proposition -= dot( eig_vec_proposition, eigen_vectors.col(num_old) ) * eigen_vectors.col(num_old);
            eig_vec_proposition /= norm_2( eig_vec_proposition );
            eigen_vectors.add_col( eig_vec_proposition );
        }
    }
        
    return eigen_vectors;
}

ExMatrix ExMatrix::ldl() const {
    assert( nb_rows() == nb_cols() );
    unsigned s = nb_rows();
    ExMatrix fact = *this;
    for(unsigned j=0;j<s;++j) {
        ExVector v( s );
        for(unsigned i=0;i<j;++i)
            v[i] = fact( j, i ) * fact( i, i );
        for(unsigned i=0;i<j;++i)
            v[j] = fact( j, i ) * v[i];
        fact( j, j ) = v[ j ];
        //
        for(unsigned k=j+1;k<s;++k) {
            for(unsigned i=0;i<j;++i)
                fact( k, j ) -= fact( k, i ) * v[i];
            fact( k, j ) /= v[j];
        }
        //         Ex d = fact( row, row );
        //         fact( row, row ) = 1 / ( d + eqz( d ) ) * ( 1 - eqz( d ) );
    }
    return fact;
}

ExVector ExMatrix::solve_using_ldl( const ExVector &b ) const {
    unsigned s = nb_rows();
    // L
    ExVector res = b;
    for(unsigned r=0;r<s;++r)
        for(unsigned c=0;c<r;++c)
            res[r] -= operator()(r,c) * res[c];
    // D
    for(unsigned r=0;r<s;++r)
        res[r] *= operator()(r,r);
    // L^T
    for(int c=s-1;c>=0;--c)
        for(unsigned r=0;r<c;++r)
            res[r] -= operator()(c,r) * res[c];
    return res;
}

ExMatrix ExMatrix::find_eigen_vectors_sym_bis() const {
    if ( nb_rows() != 3 ) {
        ExVector eigen_values = find_eigen_values_sym();
        return find_eigen_vectors_sym( eigen_values );
    }
    Ex val_1 = find_one_eigen_value_sym();
    unsigned s = nb_cols();
    // m - lambda * Id
    ExMatrix md = *this;
    for(unsigned i=0;i<s;++i)
        md(i,i) -= val_1;
        
    //
    std::vector<ExMatrix> propositions;
    std::vector<Ex> errors;
    ExVector so( md.nb_rows() );
    for(unsigned num_trial=0;num_trial<s;++num_trial) {
        ExVector u1 = md.solve_with_one_at( num_trial, so );
        u1 /= norm_2( u1 );
        //
        ExVector v2( s ), v3( s );
        v2[ ( num_trial + 1 ) % s ] = 1;
        v3[ ( num_trial + 2 ) % s ] = 1;
        v2 -= dot( v2, u1 ) * u1;
        v2 /= norm_2( v2 );
        v3 -= dot( v3, u1 ) * u1;
        v3 -= dot( v3, v2 ) * v2;
        v3 /= norm_2( v3 );
        //
        Ex a = dot( v2, mul( *this, v2 ) );
        Ex b = dot( v2, mul( *this, v3 ) );
        Ex c = dot( v3, mul( *this, v3 ) );
        Ex t = atan2( 2 * b, a - c ) / 2;
        Ex co = cos( t );
        Ex si = sin( t );
        ExVector u2 =  co * v2 + si * v3;
        ExVector u3 = -si * v2 + co * v3;
        //
        ExMatrix P( s, 0 );
        P.add_col( u1 );
        P.add_col( u2 );
        P.add_col( u3 );
        propositions.push_back( P );
        errors.push_back( norm_2_squared( mul( md, u1 ) - so ) );
    }
    return find_prop_that_minimize_error( propositions, errors );
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
   for(unsigned i=0;i<nb_rows();++i)
         res[i] = operator()(i,c);
   return res;
}
ExVector ExMatrix::row(unsigned c) const {
   ExVector res( nb_cols() );
   for(unsigned i=0;i<nb_cols();++i)
      res[i] = operator()(c,i);
   return res;
}

ExVector ExMatrix::diag() const {
   ExVector res( nb_cols() );
   for(unsigned i=0;i<nb_cols();++i)
      res[i] = operator()(i,i);
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

void ExMatrix::resize( unsigned r, unsigned c ) {
    ExMatrix tmp( r, c );
    for(unsigned i=0;i<std::min( r, _nb_rows );++i)
        for(unsigned j=0;j<std::min( c, _nb_cols );++j)
            tmp( i, j ) = operator()( i, j );
    *this = tmp;
}

void ExMatrix::add_col( const ExVector &v ) {
    resize( _nb_rows, _nb_cols + 1 );
    for(unsigned i=0;i<std::min( v.size(), _nb_rows );++i)
        operator()( i, _nb_cols-1 ) = v[i];
}

void ExMatrix::add_row( const ExVector &v ) {
    resize( _nb_rows + 1, _nb_cols );
    for(unsigned j=0;j<std::min( v.size(), _nb_cols );++j)
        operator()( _nb_rows-1, j ) = v[j];
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

