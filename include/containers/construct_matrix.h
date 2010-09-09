#ifndef CONSTRUCT_MATRIX_H
#define CONSTRUCT_MATRIX_H

#include "mat.h"

namespace LMT {

namespace Private {
    struct CopyConstructMat {
        template<class T0,class STR0,class STO0,class T1> void operator()( unsigned r, unsigned c, Mat<T0,STR0,STO0> &res, const T1 &val ) const {
            res( r, c ) = val;
        }
    };
    struct CopyConstructMatWithValidPosition {
        template<class T0,class STR0,class STO0,class T1> void operator()( unsigned r, unsigned c, Mat<T0,STR0,STO0> &res, const T1 &val ) const {
            if ( STR0::valid_position( r, c ) )
                res( r, c ) = val;
        }
    };
} // namespace Private
    
/**
 * Opératue rgénérique. Aucune optimisation
*/
template<class T0,class Str0,class Sto0,class T1,class Str1,class Sto1>
void construct_matrix( Mat<T0,Str0,Sto0> &res, const Mat<T1,Str1,Sto1> &src ) {
    res.resize( src.nb_rows(), src.nb_cols() );
    Str0::apply( Private::CopyConstructMat(), res, src );
}

template<class T0,class Str0,class Orientation0,class T1,class Str1>
void construct_matrix( Mat<T0,Str0,Dense<Orientation0>,void> &res, const Mat<T1,Str1,SparseLine<Col>,void> &src ) {
    res.resize( src.nb_rows(), src.nb_cols() );
    res.clear();
    for( unsigned r = 0; r < src.nb_rows(); ++r )
        for( unsigned i = 0; i < src.data[ r ].indices.size(); ++i )
            res( r, src.data[ r ].indices[ i ] ) = src.data[ r ].data[ i ];
}

template<class T0,class Str0,class O0,class T1,class Str1,class O1>
void construct_matrix( Mat<T0,Str0,SparseLine<O0>,void> &res, const Mat<T1,Str1,SparseLine<O1>,void> &src ) {
    res.resize( src.nb_rows(), src.nb_cols() );
    Str1::apply_sparse_line( Private::CopyConstructMatWithValidPosition(), res, src );
}

template<class T0,class Str,class O,class T1>
void construct_matrix( Mat<T0,Str,SparseLine<O>,void> &res, const Mat<T1,Str,SparseLine<O>,void> &src ) {
    res.resize( src.nb_rows(), src.nb_cols() );
    for( unsigned r = 0; r < src.nb_rows(); ++r ) {
        res.data[ r ].indices = src.data[ r ].indices;
        res.data[ r ].data    = src.data[ r ].data   ;
    }
}

// MatMult.........
template<class T0,class Str0,class Sto0,class T0_,class T1_,class Str2,class Sto2>
void construct_matrix( Mat<T0,Str0,Sto0> &res, const Mat<MatMultMat<Mat<T0_,Gen<>,SparseLine<Col> >,Mat<T1_,Gen<>,SparseLine<Col> > >,Str2,Sto2> &src ) {
    typedef typename TypePromote<Multiplies,T0_,T1_>::T T;
    const Mat<T0_,Gen<>,SparseLine<Col> > &A = src.m1;
    const Mat<T1_,Gen<>,SparseLine<Col> > &B = src.m2;
    
    res.resize( A.nb_rows(), B.nb_cols() );
    Vec<T> tmp; tmp.resize( B.nb_cols() );
    for( unsigned ra = 0; ra < A.nb_rows(); ++ra ) {
        tmp.set( 0 );
        for( unsigned ia = 0; ia < A.data[ ra ].indices.size(); ++ia ) {
            unsigned ca = A.data[ ra ].indices[ ia ];
            for( unsigned ib = 0; ib < B.data[ ca ].indices.size(); ++ib )
                tmp[ B.data[ ca ].indices[ ib ] ] += A.data[ ra ].data[ ia ] * B.data[ ca ].data[ ib ];
        }
        //
        res.row( ra ) = tmp;
    }
}

template<class T0,class Str0,class Sto0,class M0, class M1,  class Str1,class Sto1, class M2, class Str2,class Sto2>
void construct_matrix( Mat<T0,Str0,Sto0> &res, const Mat< MatMultMat< Mat< MatMultMat< M0, M1 >,Str1,Sto1 >, M2 >, Str2, Sto2 > &src ) {
    construct_matrix( res, Mat<T0,Str0,Sto0>( src.m1 ) * src.m2 ); 
}

}

#endif // CONSTRUCT_MATRIX_H

