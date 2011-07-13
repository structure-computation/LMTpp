#ifndef MAT_DETERMINANT_H
#define MAT_DETERMINANT_H

#include "mat.h"

extern "C" {
    int dgeev_(char *jobvl, char *jobvr, int *n, double *a, int *lda, double *wr, double *wi, double *vl, int *ldvl, double *vr, int *ldvr, double *work, int *lwork, int *info);
}

namespace LMT {

/*!
    Objectif :
        Calculer le déterminant d'une matrice.
        
    Paramètres :
        * m est une matrice quelconque

    Remarque : pour les matrices de taille > 5, on utilise la librairie LapacK. Il faut donc ajouter -llapack ou -lcholmod aux paramètres de g++.

    \relates Mat

    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend rapahel.pasquier@lmt.ens-cachan.fr
    \friend camille.gouttebroze@lmt.ens-cachan.fr

    \author Camille Gouttebroze puis Raphaël Pasquier qui se sert de LapacK. 
*/
template< class T, class Structure, class Storage, class ismatop >
T determinant( const Mat<T, Structure, Storage, ismatop > &m ) {

    typedef Mat<T, Structure, Storage, ismatop > TMATRIX;
    assert( m.nb_rows() == m.nb_cols() );
    if ( m.nb_rows() == 1 ) return m(0, 0);
    
    if ( m.nb_rows() == 2 ) return m(1, 1)*m(0, 0)-m(0, 1)*m(1, 0);
    
    if ( m.nb_rows() == 3 ) return m(0, 0)*m(1, 1)*m(2, 2)-m(0, 0)*m(1, 2)*m(2, 1)+m(1, 0)*m(2, 1)*m(0, 2)-m(1, 0)*m(0, 1)*m(2, 2)+m(2, 0)*m(0, 1)*m(1, 2)-m(2, 0)*m(1, 1)*m(0, 2);
    
    if ( m.nb_rows() == 4 ) return m(0, 0)*m(1, 1)*m(2, 2)*m(3, 3)-m(0, 0)*m(1, 1)*m(2, 3)*m(3, 2)+m(0, 0)*m(2, 1)*m(3, 2)*m(1, 3)-m(0, 0)*m(2, 1)*m(1, 2)*m(3, 3)+m(0, 0)*m(3, 1)*m(1, 2)*m(2, 3)-m(0, 0)*m(3, 1)*m(2, 2)*m(1, 3)-m(1, 0)*m(0, 1)*m(2, 2)*m(3, 3)+m(1, 0)*m(0, 1)*m(2, 3)*m(3, 2)-m(1, 0)*m(2, 1)*m(3, 2)*m(0, 3)+m(1, 0)*m(2, 1)*m(0, 2)*m(3, 3)-m(1, 0)*m(3, 1)*m(0, 2)*m(2, 3)+m(1, 0)*m(3, 1)*m(2, 2)*m(0, 3)+m(2, 0)*m(0, 1)*m(1, 2)*m(3, 3)-m(2, 0)*m(0, 1)*m(3, 2)*m(1, 3)+m(2, 0)*m(1, 1)*m(3, 2)*m(0, 3)-m(2, 0)*m(1, 1)*m(0, 2)*m(3, 3)+m(2, 0)*m(3, 1)*m(0, 2)*m(1, 3)-m(2, 0)*m(3, 1)*m(1, 2)*m(0, 3)-m(3, 0)*m(0, 1)*m(1, 2)*m(2, 3)+m(3, 0)*m(0, 1)*m(2, 2)*m(1, 3)-m(3, 0)*m(1, 1)*m(2, 2)*m(0, 3)+m(3, 0)*m(1, 1)*m(0, 2)*m(2, 3)-m(3, 0)*m(2, 1)*m(0, 2)*m(1, 3)+m(3, 0)*m(2, 1)*m(1, 2)*m(0, 3);

    if ( m.nb_rows() == 5 ) return m(0, 0)*m(1, 1)*m(2, 2)*m(3, 3)*m(4, 4)-m(0, 0)*m(1, 1)*m(2, 2)*m(3, 4)*m(4, 3)+m(0, 0)*m(1, 1)*m(3, 2)*m(4, 3)*m(2, 4)-m(0, 0)*m(1, 1)*m(3, 2)*m(2, 3)*m(4, 4)+m(0, 0)*m(1, 1)*m(4, 2)*m(2, 3)*m(3, 4)-m(0, 0)*m(1, 1)*m(4, 2)*m(3, 3)*m(2, 4)-m(0, 0)*m(2, 1)*m(1, 2)*m(3, 3)*m(4, 4)+m(0, 0)*m(2, 1)*m(1, 2)*m(3, 4)*m(4, 3)-m(0, 0)*m(2, 1)*m(3, 2)*m(4, 3)*m(1, 4)+m(0, 0)*m(2, 1)*m(3, 2)*m(1, 3)*m(4, 4)-m(0, 0)*m(2, 1)*m(4, 2)*m(1, 3)*m(3, 4)+m(0, 0)*m(2, 1)*m(4, 2)*m(3, 3)*m(1, 4)+m(0, 0)*m(3, 1)*m(1, 2)*m(2, 3)*m(4, 4)-m(0, 0)*m(3, 1)*m(1, 2)*m(4, 3)*m(2, 4)+m(0, 0)*m(3, 1)*m(2, 2)*m(4, 3)*m(1, 4)-m(0, 0)*m(3, 1)*m(2, 2)*m(1, 3)*m(4, 4)+m(0, 0)*m(3, 1)*m(4, 2)*m(1, 3)*m(2, 4)-m(0, 0)*m(3, 1)*m(4, 2)*m(2, 3)*m(1, 4)-m(0, 0)*m(4, 1)*m(1, 2)*m(2, 3)*m(3, 4)+m(0, 0)*m(4, 1)*m(1, 2)*m(3, 3)*m(2, 4)-m(0, 0)*m(4, 1)*m(2, 2)*m(3, 3)*m(1, 4)+m(0, 0)*m(4, 1)*m(2, 2)*m(1, 3)*m(3, 4)-m(0, 0)*m(4, 1)*m(3, 2)*m(1, 3)*m(2, 4)+m(0, 0)*m(4, 1)*m(3, 2)*m(2, 3)*m(1, 4)-m(1, 0)*m(0, 1)*m(2, 2)*m(3, 3)*m(4, 4)+m(1, 0)*m(0, 1)*m(2, 2)*m(3, 4)*m(4, 3)-m(1, 0)*m(0, 1)*m(3, 2)*m(4, 3)*m(2, 4)+m(1, 0)*m(0, 1)*m(3, 2)*m(2, 3)*m(4, 4)-m(1, 0)*m(0, 1)*m(4, 2)*m(2, 3)*m(3, 4)+m(1, 0)*m(0, 1)*m(4, 2)*m(3, 3)*m(2, 4)+m(1, 0)*m(2, 1)*m(0, 2)*m(3, 3)*m(4, 4)-m(1, 0)*m(2, 1)*m(0, 2)*m(3, 4)*m(4, 3)+m(1, 0)*m(2, 1)*m(3, 2)*m(4, 3)*m(0, 4)-m(1, 0)*m(2, 1)*m(3, 2)*m(0, 3)*m(4, 4)+m(1, 0)*m(2, 1)*m(4, 2)*m(0, 3)*m(3, 4)-m(1, 0)*m(2, 1)*m(4, 2)*m(3, 3)*m(0, 4)-m(1, 0)*m(3, 1)*m(0, 2)*m(2, 3)*m(4, 4)+m(1, 0)*m(3, 1)*m(0, 2)*m(4, 3)*m(2, 4)-m(1, 0)*m(3, 1)*m(2, 2)*m(4, 3)*m(0, 4)+m(1, 0)*m(3, 1)*m(2, 2)*m(0, 3)*m(4, 4)-m(1, 0)*m(3, 1)*m(4, 2)*m(0, 3)*m(2, 4)+m(1, 0)*m(3, 1)*m(4, 2)*m(2, 3)*m(0, 4)+m(1, 0)*m(4, 1)*m(0, 2)*m(2, 3)*m(3, 4)-m(1, 0)*m(4, 1)*m(0, 2)*m(3, 3)*m(2, 4)+m(1, 0)*m(4, 1)*m(2, 2)*m(3, 3)*m(0, 4)-m(1, 0)*m(4, 1)*m(2, 2)*m(0, 3)*m(3, 4)+m(1, 0)*m(4, 1)*m(3, 2)*m(0, 3)*m(2, 4)-m(1, 0)*m(4, 1)*m(3, 2)*m(2, 3)*m(0, 4)+m(2, 0)*m(0, 1)*m(1, 2)*m(3, 3)*m(4, 4)-m(2, 0)*m(0, 1)*m(1, 2)*m(3, 4)*m(4, 3)+m(2, 0)*m(0, 1)*m(3, 2)*m(4, 3)*m(1, 4)-m(2, 0)*m(0, 1)*m(3, 2)*m(1, 3)*m(4, 4)+m(2, 0)*m(0, 1)*m(4, 2)*m(1, 3)*m(3, 4)-m(2, 0)*m(0, 1)*m(4, 2)*m(3, 3)*m(1, 4)-m(2, 0)*m(1, 1)*m(0, 2)*m(3, 3)*m(4, 4)+m(2, 0)*m(1, 1)*m(0, 2)*m(3, 4)*m(4, 3)-m(2, 0)*m(1, 1)*m(3, 2)*m(4, 3)*m(0, 4)+m(2, 0)*m(1, 1)*m(3, 2)*m(0, 3)*m(4, 4)-m(2, 0)*m(1, 1)*m(4, 2)*m(0, 3)*m(3, 4)+m(2, 0)*m(1, 1)*m(4, 2)*m(3, 3)*m(0, 4)+m(2, 0)*m(3, 1)*m(0, 2)*m(1, 3)*m(4, 4)-m(2, 0)*m(3, 1)*m(0, 2)*m(4, 3)*m(1, 4)+m(2, 0)*m(3, 1)*m(1, 2)*m(4, 3)*m(0, 4)-m(2, 0)*m(3, 1)*m(1, 2)*m(0, 3)*m(4, 4)+m(2, 0)*m(3, 1)*m(4, 2)*m(0, 3)*m(1, 4)-m(2, 0)*m(3, 1)*m(4, 2)*m(1, 3)*m(0, 4)-m(2, 0)*m(4, 1)*m(0, 2)*m(1, 3)*m(3, 4)+m(2, 0)*m(4, 1)*m(0, 2)*m(3, 3)*m(1, 4)-m(2, 0)*m(4, 1)*m(1, 2)*m(3, 3)*m(0, 4)+m(2, 0)*m(4, 1)*m(1, 2)*m(0, 3)*m(3, 4)-m(2, 0)*m(4, 1)*m(3, 2)*m(0, 3)*m(1, 4)+m(2, 0)*m(4, 1)*m(3, 2)*m(1, 3)*m(0, 4)-m(3, 0)*m(0, 1)*m(1, 2)*m(2, 3)*m(4, 4)+m(3, 0)*m(0, 1)*m(1, 2)*m(4, 3)*m(2, 4)-m(3, 0)*m(0, 1)*m(2, 2)*m(4, 3)*m(1, 4)+m(3, 0)*m(0, 1)*m(2, 2)*m(1, 3)*m(4, 4)-m(3, 0)*m(0, 1)*m(4, 2)*m(1, 3)*m(2, 4)+m(3, 0)*m(0, 1)*m(4, 2)*m(2, 3)*m(1, 4)+m(3, 0)*m(1, 1)*m(0, 2)*m(2, 3)*m(4, 4)-m(3, 0)*m(1, 1)*m(0, 2)*m(4, 3)*m(2, 4)+m(3, 0)*m(1, 1)*m(2, 2)*m(4, 3)*m(0, 4)-m(3, 0)*m(1, 1)*m(2, 2)*m(0, 3)*m(4, 4)+m(3, 0)*m(1, 1)*m(4, 2)*m(0, 3)*m(2, 4)-m(3, 0)*m(1, 1)*m(4, 2)*m(2, 3)*m(0, 4)-m(3, 0)*m(2, 1)*m(0, 2)*m(1, 3)*m(4, 4)+m(3, 0)*m(2, 1)*m(0, 2)*m(4, 3)*m(1, 4)-m(3, 0)*m(2, 1)*m(1, 2)*m(4, 3)*m(0, 4)+m(3, 0)*m(2, 1)*m(1, 2)*m(0, 3)*m(4, 4)-m(3, 0)*m(2, 1)*m(4, 2)*m(0, 3)*m(1, 4)+m(3, 0)*m(2, 1)*m(4, 2)*m(1, 3)*m(0, 4)+m(3, 0)*m(4, 1)*m(0, 2)*m(1, 3)*m(2, 4)-m(3, 0)*m(4, 1)*m(0, 2)*m(2, 3)*m(1, 4)+m(3, 0)*m(4, 1)*m(1, 2)*m(2, 3)*m(0, 4)-m(3, 0)*m(4, 1)*m(1, 2)*m(0, 3)*m(2, 4)+m(3, 0)*m(4, 1)*m(2, 2)*m(0, 3)*m(1, 4)-m(3, 0)*m(4, 1)*m(2, 2)*m(1, 3)*m(0, 4)+m(4, 0)*m(0, 1)*m(1, 2)*m(2, 3)*m(3, 4)-m(4, 0)*m(0, 1)*m(1, 2)*m(3, 3)*m(2, 4)+m(4, 0)*m(0, 1)*m(2, 2)*m(3, 3)*m(1, 4)-m(4, 0)*m(0, 1)*m(2, 2)*m(1, 3)*m(3, 4)+m(4, 0)*m(0, 1)*m(3, 2)*m(1, 3)*m(2, 4)-m(4, 0)*m(0, 1)*m(3, 2)*m(2, 3)*m(1, 4)-m(4, 0)*m(1, 1)*m(0, 2)*m(2, 3)*m(3, 4)+m(4, 0)*m(1, 1)*m(0, 2)*m(3, 3)*m(2, 4)-m(4, 0)*m(1, 1)*m(2, 2)*m(3, 3)*m(0, 4)+m(4, 0)*m(1, 1)*m(2, 2)*m(0, 3)*m(3, 4)-m(4, 0)*m(1, 1)*m(3, 2)*m(0, 3)*m(2, 4)+m(4, 0)*m(1, 1)*m(3, 2)*m(2, 3)*m(0, 4)+m(4, 0)*m(2, 1)*m(0, 2)*m(1, 3)*m(3, 4)-m(4, 0)*m(2, 1)*m(0, 2)*m(3, 3)*m(1, 4)+m(4, 0)*m(2, 1)*m(1, 2)*m(3, 3)*m(0, 4)-m(4, 0)*m(2, 1)*m(1, 2)*m(0, 3)*m(3, 4)+m(4, 0)*m(2, 1)*m(3, 2)*m(0, 3)*m(1, 4)-m(4, 0)*m(2, 1)*m(3, 2)*m(1, 3)*m(0, 4)-m(4, 0)*m(3, 1)*m(0, 2)*m(1, 3)*m(2, 4)+m(4, 0)*m(3, 1)*m(0, 2)*m(2, 3)*m(1, 4)-m(4, 0)*m(3, 1)*m(1, 2)*m(2, 3)*m(0, 4)+m(4, 0)*m(3, 1)*m(1, 2)*m(0, 3)*m(2, 4)-m(4, 0)*m(3, 1)*m(2, 2)*m(0, 3)*m(1, 4)+m(4, 0)*m(3, 1)*m(2, 2)*m(1, 3)*m(0, 4);

    int n = m.nb_rows(), info, lwork = -1, lda = n, ldvl = n, ldvr = n;
    const char *pp = "N";
    double wkopt;
    double* work;
    /* Local arrays */
    double *wr = new double[ n ];
    double *wi = new double[ n ];
    double *a  = new double[ n * n ];
    for( int i = 0; i < n; ++i )
        for( int j = 0; j < n; ++j )
            a[ i * n + j ] = m( i, j );
    /** Query and allocate the optimal workspace */
    dgeev_( const_cast<char*>( pp ), const_cast<char*>( pp ), &n, a, &lda, wr, wi, NULL, &ldvl, NULL, &ldvr, &wkopt, &lwork, &info );
    lwork = (int) wkopt;
    work = new double[ lwork ];
    /** Solve eigenproblem */
    dgeev_( const_cast<char*>( pp ), const_cast<char*>( pp ), &n, a, &lda, wr, wi, NULL, &ldvl, NULL, &ldvr, work, &lwork, &info );    
    if( info > 0 ) {
            std::cerr <<  "Error determinant()." << std::endl;
            delete[] wr;
            delete[] wi;
            delete[] a; 
            delete[] work;
            return 0;
    }
    T res = 1.;
    for( int i = 0; i < n ; ++i ) {
        if ( wi[ i ] == 0. )
            res *= wr[ i ];
        else {
            T module2 = std::pow( wr[ i ], 2 ) + std::pow( wi[ i ], 2 );
            res *= module2; 
            ++i;  
        }
    }
    
    delete[] wr;
    delete[] wi;
    delete[] a; 
    delete[] work;
    
    return res;
    //
//     T res = T(0);
//     TMATRIX Ac = m( range(0,m.nb_rows()), range(1,m.nb_cols()) );
//     for(unsigned l=0;l<m.nb_rows();++l) {
//          TMATRIX Ar = Ac( 
//             appended( range(0,l), range(l+1,Ac.nb_rows()) ),
//             range(0,Ac.nb_cols()) 
//         );
//         res += ( 1.0 - 2.0 * ( l & 1 ) ) * m( l, 0 ) * determinant( Ar );
//     }
//     return res;
    
}

}


#endif // MAT_DETERMINANT_H
