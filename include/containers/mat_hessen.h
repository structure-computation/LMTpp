#ifndef LMTHESSEN_H
#define LMTHESSEN_H

#include "containers/vec.h"

namespace LMT {

template<class TT,bool upper> struct DelayedAssignementHessenSource {
    typedef TT T;
    DelayedAssignementHessenSource( unsigned i, unsigned j, Vec<T> &values_ ) : values(values_) {
        if ( not upper )
            swap( i, j );
        this->i = i;
        this->j = j;
    }
    static unsigned index( unsigned i, unsigned j ) {
        return ( j + 1 ) * ( j + 2 ) / 2 + i - 1;
    }
    TT get() const {
        if ( i > j + 1 )
            return 0;
        return values[ index( i, j ) ];
    }
    template<class Op,class T2> void apply( const Op &op, const T2 &v ) {
        if ( i > j + 1 )
            assert( op(T(0),v) == T(0) );
        values[ index( i, j ) ] = op( values[ index( i, j ) ], v );
    }
    Vec<T> &values;
    unsigned i, j;
};


template<bool upper=true> struct Hessen {
    static const int static_nb_rows = -1;
    static const int static_nb_cols = -1;
};

template<class TT,bool upper>
class Mat<TT,Hessen<upper>,Dense<> > {
public:
    typedef TT T;
    typedef DelayedAssignementHessenSource<T,upper> DA;
    
    Mat() : size_( 0 ) {  }
    
    Mat( unsigned nb_rows ) {
        resize( nb_rows );
    }
    
    void resize( unsigned n ) {
        values.resize( DA::index( n-1, n-1 ) + 1 );
        size_ = n;
    }
    
    //     Vec<T> &diag() { return diag_; }
    //     const Vec<T> &diag() const { return diag_; }
    
    typedef T RetOpConst;
    T operator()(unsigned i,unsigned j) const {
        if ( not upper )
            swap( i, j );
        if ( i > j + 1 )
            return 0;
        return values[ DA::index( i, j ) ];
    }
    
    typedef DelayedAssignement<DA> RetOp;
    RetOp operator()(unsigned line,unsigned column) {
        return RetOp( DA( line, column, values ) );
    }

    Vec<VecSubMat<Mat,false,ExtractRow>,-1> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,-1>(*this,i); }
    Vec<VecSubMat<Mat,true,ExtractRow>,-1> row(unsigned i) const { return Vec<VecSubMat<Mat,true,ExtractRow>,-1>(*this,i); }
    
    Vec<VecSubMat<Mat,false,ExtractCol>,-1> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,-1>(*this,i); }
    Vec<VecSubMat<Mat,true,ExtractCol>,-1> col(unsigned i) const { return Vec<VecSubMat<Mat,true,ExtractCol>,-1>(*this,i); }
    
    unsigned nb_rows() const { return size_; }
    unsigned nb_cols() const { return size_; }
    
    Vec<T> values;
    unsigned size_;
};


};

#endif
