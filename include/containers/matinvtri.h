//
// C++ Interface: matinvtri
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matinvtri_HEADER
#define LMT_matinvtri_HEADER

namespace LMT {

/** \relates Mat
*/
template<class T,int s,class Sto,class IO,class TF>
bool get_factorization( const Mat<T,TriUpper<s>,Sto,IO> &m, TF &fact ) {
    return false;
}

/** \relates Mat
*/
template<class T,int s,class Sto,class IO,class TF>
bool get_factorization( const Mat<T,TriLower<s>,Sto,IO> &m, TF &fact ) {
    return false;
}


/** \relates Mat
    \todo OPTIMIZE
*/
template<class TT,int s,class Sto,class IO,class TF,class T3,int s3>
Vec<
    typename TypePromote<
        Multiplies,
        typename Mat<TT,TriUpper<s>,Sto,IO>::T,
        typename Vec<T3,s3>::template SubType<0>::T
    >::T,
    TriUpper<s>::static_nb_rows
>
 solve_using_factorization( const Mat<TT,TriUpper<s>,Sto,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    typedef typename TypePromote< Multiplies, typename Mat<TT,TriUpper<s>,Sto,IO>::T, typename Vec<T3,s3>::template SubType<0>::T>::T TR;
    Vec<TR> res; res.resize( mat.nb_rows() );
    for(int i=mat.nb_rows()-1;i>=0;--i) {
        TR tmp = b[i];
        for(unsigned j=i+1;j<mat.nb_rows();++j)
            tmp -= mat(i,j) * res[j];
        res[i] = tmp / mat(i,i);
    }
    return res;
}


/** \relates Mat
    \todo OPTIMIZE
*/
template<class TT,int s,class Sto,class IO,class TF,class T3,int s3>
 Vec<typename TypePromote< Multiplies, typename Mat<TT,TriLower<s>,Sto,IO>::T, typename Vec<T3,s3>::template SubType<0>::T>::T,s>
 solve_using_factorization( const Mat<TT,TriLower<s>,Sto,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    typedef typename TypePromote< Multiplies, typename Mat<TT,TriLower<s>,Sto,IO>::T, typename Vec<T3,s3>::template SubType<0>::T>::T TR;
    Vec<TR> res; res.resize( mat.nb_rows() );
    for(unsigned i=0;i<mat.nb_rows();++i) {
        TR tmp = b[i];
        for(unsigned j=0;j<i;++j)
            tmp -= mat(i,j) * res[j];
        res[i] = tmp / mat(i,i);
    }
    return res;
}



};

#endif // LMT_matinvtri_HEADER
