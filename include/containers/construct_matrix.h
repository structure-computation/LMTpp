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
 * Opérateur générique. Aucune optimisation
*/
template<class T0,class Str0,class Sto0,class T1,class Str1,class Sto1>
void construct_matrix( Mat<T0,Str0,Sto0> &res, const Mat<T1,Str1,Sto1> &src ) {
    res.resize( src.nb_rows(), src.nb_cols() );
    //PRINT( " conversion Mat< >" );
    Str0::apply( Private::CopyConstructMat(), res, src );
}

template<class T0,class Str0,class Orientation0,class T1,class Str1>
void construct_matrix( Mat<T0,Str0,Dense<Orientation0>,void> &res, const Mat<T1,Str1,SparseLine<Col>,void> &src ) {
    res.resize( src.nb_rows(), src.nb_cols() );
    res.clear();
    //PRINT( " conversion Mat< Str1, SparseLine<Col> > hhhhhhhhhhhhhhh" );
    //res.push_back( 2 ); /// pour tester Str1
    Str1::apply_sparse_line( Private::CopyConstructMatWithValidPosition(), res, src );
//     for( unsigned r = 0; r < src.nb_rows(); ++r )
//         for( unsigned i = 0; i < src.data[ r ].indices.size(); ++i )
//             res( r, src.data[ r ].indices[ i ] ) = src.data[ r ].data[ i ];
}

template<class T0,class Str0,class O0,class T1,class Str1,class O1>
void construct_matrix( Mat<T0,Str0,SparseLine<O0>,void> &res, const Mat<T1,Str1,SparseLine<O1>,void> &src ) {
    res.resize( src.nb_rows(), src.nb_cols() );
    //PRINT( " conversion Mat< Str0, SparseLine<Col> >" );
    Str1::apply_sparse_line( Private::CopyConstructMatWithValidPosition(), res, src );
}

template<class T0,class Str,class O,class T1>
void construct_matrix( Mat<T0,Str,SparseLine<O>,void> &res, const Mat<T1,Str,SparseLine<O>,void> &src ) {
    res.resize( src.nb_rows(), src.nb_cols() );
    //PRINT( " conversion Mat< Str, SparseLine<Col> >" );
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
    //PRINT( " conversion Mat< Gen, sparseLine<Col> > * Mat< Gen, SparseLine<Col> >" );
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

/// conversion de Mat< Sym<s,false>, Dense<Col> > * Mat< Gen, Dense<Col> >
template<class T0,class Str0,class Sto0,class T0_,int s0_,class T1_,int s_r1_,int s_c1_, class Str2,class Sto2>
void construct_matrix( Mat<T0,Str0,Sto0> &res, const Mat< MatMultMat< Mat<T0_,Sym<s0_,false>,Dense<Col>,void >, Mat<T1_,Gen<s_r1_,s_c1_>,Dense<Col>,void > >,Str2,Sto2> &src ) {
    typedef typename TypePromote<Multiplies,T0_,T1_>::T T;
    const Mat< T0_,Sym<s0_,false>,Dense<Col>,void >   &A = src.m1;
    const Mat< T1_,Gen<s_r1_,s_c1_>,Dense<Col>,void > &B = src.m2;
    //PRINT( "conversion  Mat< Sym<s,false>, Dense<Col> > * Mat< Gen, Dense<Col> >" );
    res.resize( A.nb_rows(), B.nb_cols() );
    Vec<T> tmp; tmp.resize( B.nb_cols() );
    for( unsigned ra = 0; ra < A.nb_rows(); ++ra ) {
        tmp.set( 0 );
        for( unsigned ca = 0; ca <= ra; ca++ )
            tmp += A( ra, ca ) * B.row( ca );
        for( unsigned ca = ra + 1; ca < A.nb_cols(); ca++ ) 
            tmp += A( ca, ra ) * B.row( ca );
        res.row( ra ) = tmp;
    }
}

/// conversion de Mat< Sym<s,false>, Dense<Col> > * Mat< Gen, SparseLine<Col> >
template<class T0,class Str0,class Sto0,class T0_,int s0_,class T1_,int s_r1_,int s_c1_, class Str2,class Sto2>
void construct_matrix( Mat<T0,Str0,Sto0> &res, 
                       const Mat< MatMultMat< Mat<T0_,Sym<s0_,false>,Dense<Col>,void >, Mat<T1_,Gen<s_r1_,s_c1_>,SparseLine<Col>,void> >, Str2,Sto2> &src ) {
    typedef typename TypePromote<Multiplies,T0_,T1_>::T T;
    const Mat< T0_,Sym<s0_,false>,Dense<Col>,void >   &A = src.m1;
    const Mat< T1_,Gen<s_r1_,s_c1_>,SparseLine<Col>,void > &B = src.m2;
    
    res.resize( A.nb_rows(), B.nb_cols() );
    Vec<T> tmp; tmp.resize( B.nb_cols() );
    //PRINT( "Mat< Sym<s,false>, Dense<Col> > * Mat< Gen, SparseLine<Col> >" );
    for( unsigned ra = 0; ra < A.nb_rows(); ++ra ) {
        tmp.set( 0 );
        for( unsigned ca = 0; ca <= ra; ca++ )
            for( unsigned ib = 0; ib < B.data[ ca ].indices.size(); ++ib )
                tmp[ B.data[ ca ].indices[ ib ] ] += A( ra , ca ) * B.data[ ca ].data[ ib ];
        for( unsigned ca = ra + 1; ca < A.nb_cols(); ca++ )
            for( unsigned ib = 0; ib < B.data[ ca ].indices.size(); ++ib )
                tmp[ B.data[ ca ].indices[ ib ] ] += A( ca , ra ) * B.data[ ca ].data[ ib ];
        //
        res.row( ra ) = tmp;
    }
}

/// conversion de Mat< Sym, SparseLine<Col> > * Mat< Gen, Dense<Col> >
/// ou
/// conversion de Mat< Sym, SparseLine<Col> > * Mat< Gen, SparseLine<Col> >
template<class T0,class Str0,class Sto0,class T0_,int s0_,class T1_,int s_r1_,int s_c1_, class Sto1, class Str2,class Sto2>
void construct_matrix( Mat<T0,Str0,Sto0> &res, 
                       const Mat< MatMultMat< Mat<T0_,Sym<s0_,false>,SparseLine<Col>,void >, Mat<T1_,Gen<s_r1_,s_c1_>,Sto1,void> >, Str2,Sto2> &src ) {
    typedef typename TypePromote<Multiplies,T0_,T1_>::T T;
    const Mat< T0_,Sym<s0_,false>,SparseLine<Col>,void >   &A = src.m1;
    const Mat< T1_,Gen<s_r1_,s_c1_>,Sto1,void > &B = src.m2;
    res.resize( A.nb_rows(), B.nb_cols() );
    Vec<T> tmp; tmp.resize( B.nb_cols() );

    for( unsigned ra = 0; ra < A.nb_rows(); ++ra ) {
        tmp.set( 0 );
        for( unsigned ca = 0; ca < A.data[ ra ].indices.size(); ca++ )
            tmp += A.data[ ra ].data[ ca ] * B.row( A.data[ ra ].indices[ ca ] );
        for( unsigned ca = ra + 1; ca < A.nb_rows(); ca++ ) {
            /// comme les données sont rangées par indice croissant dans une matrice creuse, on peut gagner un peu de temps pour chercher l'indice ra
            /// une recherche dichotomique serait meilleure...
            for( unsigned i = 0; i < A.data[ ca ].indices.size(); ++i )
                if ( A.data[ ca ].indices[ i ] == ra )
                    tmp += A.data[ ca ].data[ i ] * B.row( ca );
                else
                    if ( A.data[ ca ].indices[ i ] > ra )
                        break;
        }
        res.row( ra ) = tmp;
    }
}















/// conversion de  Mat< Gen, Dense<Col> > * Mat< Sym<s,false>, Dense<Col> >
// template<class T0,class Str0,class Sto0,class T0_,int s0_,class T1_,int s_r1_,int s_c1_, class Str2,class Sto2>
// void construct_matrix( Mat<T0,Str0,Sto0> &res, const Mat< MatMultMat< Mat<T1_,Gen<s_r1_,s_c1_>,Dense<Col>,void >, Mat<T0_,Sym<s0_,false>,Dense<Col>,void > >,Str2,Sto2> &src ) {
//     typedef typename TypePromote<Multiplies,T0_,T1_>::T T;
//     const Mat< T1_,Gen<s_r1_,s_c1_>,Dense<Col>,void > &A = src.m1;
//     const Mat< T0_,Sym<s0_,false>,Dense<Col>,void >   &B = src.m2;
//     PRINT( "conversion  Mat< Gen, Dense<Col> > * Mat< Sym<s,false>, Dense<Col> >" );
//     res.resize( A.nb_rows(), B.nb_cols() );
//     Vec<T> tmp; tmp.resize( B.nb_cols() );
//     for( unsigned ra = 0; ra < A.nb_rows(); ++ra ) {
//         tmp.set( 0 );
//         for( unsigned ca = 0; ca <= ra; ca++ )
//             tmp += A( ra, ca ) * B.row( ca );
//         for( unsigned ca = ra + 1; ca < A.nb_cols(); ca++ ) 
//             tmp += A( ca, ra ) * B.row( ca );
//         res.row( ra ) = tmp;
//     }
// }
/*
/// conversion de Mat< Gen, SparseLine<Col> > * Mat< Sym<s,false>, Dense<Col> >
template<class T0,class Str0,class Sto0,class T0_,int s0_,class T1_,int s_r1_,int s_c1_, class Str2,class Sto2>
void construct_matrix( Mat<T0,Str0,Sto0> &res, 
                       const Mat< MatMultMat< Mat<T0_,Sym<s0_,false>,Dense<Col>,void >, Mat<T1_,Gen<s_r1_,s_c1_>,SparseLine<Col>,void> >, Str2,Sto2> &src ) {
    typedef typename TypePromote<Multiplies,T0_,T1_>::T T;
    const Mat< T0_,Sym<s0_,false>,Dense<Col>,void >   &A = src.m1;
    const Mat< T1_,Gen<s_r1_,s_c1_>,SparseLine<Col>,void > &B = src.m2;
    
    res.resize( A.nb_rows(), B.nb_cols() );
    Vec<T> tmp; tmp.resize( B.nb_cols() );
    PRINT( "Mat< Sym<s,false>, Dense<Col> > * Mat< Gen, SparseLine<Col> >" );
    for( unsigned ra = 0; ra < A.nb_rows(); ++ra ) {
        tmp.set( 0 );
        for( unsigned ca = 0; ca <= ra; ca++ )
            for( unsigned ib = 0; ib < B.data[ ca ].indices.size(); ++ib )
                tmp[ B.data[ ca ].indices[ ib ] ] += A( ra , ca ) * B.data[ ca ].data[ ib ];
        for( unsigned ca = ra + 1; ca < A.nb_cols(); ca++ )
            for( unsigned ib = 0; ib < B.data[ ca ].indices.size(); ++ib )
                tmp[ B.data[ ca ].indices[ ib ] ] += A( ca , ra ) * B.data[ ca ].data[ ib ];
        //
        res.row( ra ) = tmp;
    }
}

/// conversion de Mat< Gen, Dense<Col> > * Mat< Sym, SparseLine<Col> >
/// ou
/// conversion de Mat< Gen, SparseLine<Col> > * Mat< Sym, SparseLine<Col> >
template<class T0,class Str0,class Sto0,class T0_,int s0_,class T1_,int s_r1_,int s_c1_, class Sto1, class Str2,class Sto2>
void construct_matrix( Mat<T0,Str0,Sto0> &res, 
                       const Mat< MatMultMat< Mat<T0_,Sym<s0_,false>,SparseLine<Col>,void >, Mat<T1_,Gen<s_r1_,s_c1_>,Sto1,void> >, Str2,Sto2> &src ) {
    typedef typename TypePromote<Multiplies,T0_,T1_>::T T;
    const Mat< T0_,Sym<s0_,false>,SparseLine<Col>,void >   &A = src.m1;
    const Mat< T1_,Gen<s_r1_,s_c1_>,Sto1,void > &B = src.m2;
    res.resize( A.nb_rows(), B.nb_cols() );
    Vec<T> tmp; tmp.resize( B.nb_cols() );

    for( unsigned ra = 0; ra < A.nb_rows(); ++ra ) {
        tmp.set( 0 );
        for( unsigned ca = 0; ca < A.data[ ra ].indices.size(); ca++ )
            tmp += A.data[ ra ].data[ ca ] * B.row( A.data[ ra ].indices[ ca ] );
        for( unsigned ca = ra + 1; ca < A.nb_rows(); ca++ ) {
            /// comme les données sont rangées par indice croissant dans une matrice creuse, on peut gagner un peu de temps pour chercher l'indice ra
            /// une recherche dichotomique serait meilleure...
            for( unsigned i = 0; i < A.data[ ca ].indices.size(); ++i )
                if ( A.data[ ca ].indices[ i ] == ra )
                    tmp += A.data[ ca ].data[ i ] * B.row( ca );
                else
                    if ( A.data[ ca ].indices[ i ] > ra )
                        break;
        }
        res.row( ra ) = tmp;
    }
}
*/

/// conversion de A * B * C
template<class T0,class Str0,class Sto0,class M0, class M1,  class Str1,class Sto1, class M2, class Str2,class Sto2>
void construct_matrix( Mat<T0,Str0,Sto0> &res, const Mat< MatMultMat< Mat< MatMultMat< M0, M1 >,Str1,Sto1 >, M2 >, Str2, Sto2 > &src ) {
    construct_matrix( res, Mat<T0,Str0,Sto0>( src.m1 ) * src.m2 ); 
}

}

#endif // CONSTRUCT_MATRIX_H

