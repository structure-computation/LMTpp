//
// C++ Interface: matinvdiag
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matinvdiag_HEADER
#define LMT_matinvdiag_HEADER

namespace LMT {

/** \relates Mat
*/
template<class T,int s,class Sto,class IO,class TF>
bool get_factorization( const Mat<T,Diag<s>,Sto,IO> &m, TF &fact ) {
    return false;
}

/** \relates Mat
*/
template<class TT,int s,class Sto,class IO,class TF,class T3,int s3>
 Vec<typename TypePromote< Divides, typename Mat<TT,Diag<s>,Sto,IO>::T, typename Vec<T3,s3>::template SubType<0>::T>::T>
 solve_using_factorization( const Mat<TT,Diag<s>,Sto,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    return solve( mat.diag(), b );
}


};

#endif // LMT_matinvdiag_HEADER
