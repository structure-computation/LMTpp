#ifndef MAT_TRUE_INV_H
#define MAT_TRUE_INV_H

namespace LMT {

/**
Renvoie le vrai inverse d'une matrice (couteux)
*/
template<class T,class P,class S>
Mat<T,P,S> true_inv( const Mat<T,P,S> &m ) {
    assert( m.nb_rows() == m.nb_cols() );
    Mat<T,P,S> res; res.resize( m.nb_rows() );
    Inv<T,P,S> in( m );
    for(unsigned i=0;i<m.nb_rows();++i) {
        Vec<T> v; v.resize( m.nb_rows(), 0 ); v[i] = 1;
        res.col( i ) = in * v;
    }
    return res;
}

}


#endif // MAT_TRUE_INV_H
