#ifndef MAT_DETERMINANT_H
#define MAT_DETERMINANT_H

namespace LMT {

/**
    Attention : c'est bourrin. Sur des petites matrices uniquement
*/
template<class T>
T determinant( const Mat<T> &m ) {
    assert( m.nb_rows() == m.nb_cols() );
    if ( m.nb_rows()==0 ) return 1;
    if ( m.nb_rows()==1 ) return m(0,0);
    //
    T res = 0.0;
    Mat<T> Ac = m( range(0,m.nb_rows()), range(1,m.nb_cols()) );
    for(unsigned l=0;l<m.nb_rows();++l) {
        Mat<T> Ar = Ac( 
            appended( range(0,l), range(l+1,Ac.nb_rows()) ),
            range(0,Ac.nb_cols()) 
        );
        res += ( 1.0 - 2.0 * ( l & 1 ) ) * m( l, 0 ) * determinant( Ar );
    }
    return res;
    
}

}


#endif // MAT_DETERMINANT_H
