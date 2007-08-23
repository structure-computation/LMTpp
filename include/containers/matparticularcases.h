//
// C++ Interface: matparticularcases
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matparticularcases_HEADER
#define LMT_matparticularcases_HEADER

namespace LMT {

/** \todo remove this function and code operator* with row oriented matrices
    \relates Mat
 */
// template<class TT,class STR,class P,class IO> Mat<TT,typename StructureTrans<STR>::T,SparseLine<Col,P>,IO>
//  trans(const Mat<TT,STR,SparseLine<Col,P>,IO> &m) {
//     Mat<TT,typename StructureTrans<STR>::T,SparseLine<Col,P>,IO> res( m.nb_cols(), m.nb_rows() );
//     unsigned max_size = 0;
//     for(unsigned i=0;i<m.nb_rows();++i)
//         max_size = max( max_size, m.data[i].indices.size() );
//     for(unsigned i=0;i<m.nb_cols();++i) {
//         res.data[i].data.reserve( max_size );
//         res.data[i].indices.reserve( max_size );
//     }
//     for(unsigned i=0;i<m.nb_rows();++i) {
//         for(unsigned j=0;j<m.data[i].nb_non_zeroes();++j) {
//             res.data[ m.data[i].indices[j] ].data.push_back( m.data[i].data[j] );
//             res.data[ m.data[i].indices[j] ].indices.push_back( i );
//         }
//     }
//     for(unsigned i=0;i<m.nb_cols();++i) {
//         res.data[i].data.fit_memory();
//         res.data[i].indices.fit_memory();
//     }
//     return res;
// }

/** \todo remove this function and code operator* with row oriented matrices
    \relates Mat
 */
// template<class TT,class STR,class P,class IO> Mat<TT,typename StructureTrans<STR>::T,SparseLine<Col,P>,IO>
//  trans(Mat<TT,STR,SparseLine<Col,P>,IO> &m) { return trans( (const Mat<TT,STR,SparseLine<Col,P>,IO> &)m ); }





/** \relates Mat
    \todo OPTIMIZE
*/
template<class TT,int s,class O,class IO,class TF,class T3,int s3>
Vec<
    typename TypePromote<
        Multiplies,
        typename Mat<TT,TriUpper<s>,SparseLine<O>,IO>::T,
        typename Vec<T3,s3>::template SubType<0>::T
    >::T,
    s
>
 solve_using_factorization( const Mat<TT,TriUpper<s>,SparseLine<O>,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    typedef typename TypePromote< Multiplies, typename Mat<TT,TriUpper<s>,SparseLine<O>,IO>::T, typename Vec<T3,s3>::template SubType<0>::T>::T TR;
    Vec<TR> res;
    if ( O::col_oriented ) {
        res.resize( mat.nb_rows() );
        for(int i=mat.nb_rows()-1;i>=0;--i) {
            DEBUGASSERT( i == mat.data[i].indices.front() );
            
            TR tmp0 = b[i];
            for(unsigned j=1;j<mat.data[i].indices.size();++j)
                tmp0 -= mat.data[i].data[j] * res[ mat.data[i].indices[j] ];
            res[i] = tmp0 / mat.data[i].data.front();
        }
    }
    else {
        res = b;
        for(int i=mat.nb_rows()-1;i>=0;--i) {
            DEBUGASSERT( i == mat.data[i].indices.back() );
            TR ondiag = mat.data[i].data.back();
            
            TR tmp = res[i] / ondiag;
            res[i] = tmp;
            for(unsigned j=0;j<mat.data[i].indices.size()-1;++j)
                res[ mat.data[i].indices[j] ] -= mat.data[i].data[j] * tmp;
        }
    }
    
    return res;
    
}


/** \relates Mat
    \todo OPTIMIZE
*/
template<class TT,int s,class O,class IO,class TF,class T3,int s3>
Vec<
    typename TypePromote<
        Multiplies,
        typename Mat<TT,TriLower<s>,SparseLine<O>,IO>::T,
        typename Vec<T3,s3>::template SubType<0>::T>::T
    ,s
>
 solve_using_factorization( const Mat<TT,TriLower<s>,SparseLine<O>,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    typedef typename TypePromote< Multiplies, typename Mat<TT,TriLower<s>,SparseLine<O>,IO>::T, typename Vec<T3,s3>::template SubType<0>::T>::T TR;
    Vec<TR> res; res.resize( mat.nb_rows() );

    if ( O::col_oriented ) {
        res.resize( mat.nb_rows() );
        for(unsigned i=0;i<mat.nb_rows();++i) {
            DEBUGASSERT( i == mat.data[i].indices.back() );
            TR ondiag = mat.data[i].data.back();
        
            TR tmp = b[i];
            for(unsigned j=0;j<mat.data[i].indices.size()-1;++j)
                tmp -= mat.data[i].data[j] * res[ mat.data[i].indices[j] ];
            res[i] = tmp / ondiag;
        }
    }
    else {
        res = b;
        for(unsigned i=0;i<mat.nb_rows();++i) {
            DEBUGASSERT( i == mat.data[i].indices.front() );
            TR ondiag = mat.data[i].data.front();
            
            TR tmp = res[i] / ondiag;
            res[i] = tmp;
            for(unsigned j=1;j<mat.data[i].indices.size();++j)
                res[ mat.data[i].indices[j] ] -= mat.data[i].data[j] * tmp;
        }
    }
    
    return res;
}


/** \relates Mat
    TRANS version
    \todo OPTIMIZE
*/
template<class TM,bool ctm,int s,class O,class IO,class TF,class T3,int s3>
Vec<
    typename TypePromote<
        Multiplies,
        typename TM::T,
        typename Vec<T3,s3>::template SubType<0>::T>::T
    ,s
>
 solve_using_factorization( const Mat<MatTrans<TM,ctm>,TriLower<s>,SparseLine<O>,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    return solve_using_factorization( *reinterpret_cast<const Mat<typename TM::T,TriLower<s>,SparseLine<O> >*>(mat.ptr.val), fact, b );
}

/** \relates Mat
    TRANS version
    \todo OPTIMIZE
*/
template<class TM,bool ctm,int s,class O,class IO,class TF,class T3,int s3>
Vec<
    typename TypePromote<
        Multiplies,
        typename TM::T,
        typename Vec<T3,s3>::template SubType<0>::T>::T
    ,s
>
 solve_using_factorization( const Mat<MatTrans<TM,ctm>,TriUpper<s>,SparseLine<O>,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    return solve_using_factorization( *reinterpret_cast<const Mat<typename TM::T,TriUpper<s>,SparseLine<O> >*>(mat.ptr.val), fact, b );
}


};

#endif // LMT_matparticularcases_HEADER
