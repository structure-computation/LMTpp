#ifndef NEWTON_FOR_ELEMENT_H
#define NEWTON_FOR_ELEMENT_H

#include "system_Poly_common.h"
#include "mat.h"
#include "determinant.h"
#include "../mesh/Hexa.h"
#include "../mesh/Wedge.h"
namespace LMT {

template<class T, int s, int sr, class NE >
void newton_for_element( const NE &ne, const Vec< Vec<T,s>, 3> &f, Vec<T,sr> &vi, const Vec<T,sr> &residu, unsigned iter = 2 ) {
    assert( 0 );
}

template<class T>
void newton_for_element( const Hexa &ne, const Vec< Vec<T,20>, 3> &f, Vec<T,3> &vi, const Vec<T,3> &residu, unsigned iter = 2 ) {
    typedef Vec<T, 3> V3;
    
    V3 res = 0;
    V3 residul = residu;
    Mat<T, Gen<3,3>, Dense<> > J;
    //PRINT( residul );
    
    for( unsigned i = 0; i < 3; i++ ) {
        J( i, 0 ) = f[i][1]+f[i][5]*vi[1]+f[i][6]*vi[2]+f[i][14]*vi[1]*vi[2];
        J( i, 1 ) = f[i][2]+f[i][5]*vi[0]+f[i][8]*vi[2]+f[i][14]*vi[0]*vi[2];
        J( i, 2 ) = f[i][3]+f[i][6]*vi[0]+f[i][8]*vi[1]+f[i][14]*vi[0]*vi[1];
    }
    
    if ( std::abs( determinant( J ) ) > std::ldexp( 1, 4 - ( std::numeric_limits<T>::digits >> 2 ) ) ) {
         
        for( unsigned it = 0; it  < iter - 1; ++it ) {
            vi -= inv( J ) * residul;
            for( unsigned i = 0; i < 3; i++ ) {
                    J( i, 0 ) = f[i][1]+f[i][5]*vi[1]+f[i][6]*vi[2]+f[i][14]*vi[1]*vi[2];
                    J( i, 1 ) = f[i][2]+f[i][5]*vi[0]+f[i][8]*vi[2]+f[i][14]*vi[0]*vi[2];
                    J( i, 2 ) = f[i][3]+f[i][6]*vi[0]+f[i][8]*vi[1]+f[i][14]*vi[0]*vi[1];           
            }
            residul = V3( polyres( f[0], vi ), polyres( f[1], vi ), polyres( f[2], vi ) );
            //PRINT( residul );
        }
        vi -= inv( J ) * residul;
    }
}

template<class T>
void newton_for_element( const Wedge &ne, const Vec< Vec<T,10>, 3> &f, Vec<T,3> &vi, const Vec<T,3> &residu, unsigned iter = 2 ) {
    typedef Vec<T, 3> V3;
    
    V3 res = 0;
    V3 residul = residu;
    Mat<T, Gen<3,3>, Dense<> > J;
    //PRINT( residul );
    
    for( unsigned i = 0; i < 3; i++ ) {
        J( i, 0 ) = f[i][1]+f[i][6]*vi[2];
        J( i, 1 ) = f[i][2]+f[i][8]*vi[2];
        J( i, 2 ) = f[i][3]+f[i][6]*vi[0]+f[i][8]*vi[1];
    }
    
    if ( std::abs( determinant( J ) ) > std::ldexp( 1, 4 - ( std::numeric_limits<T>::digits >> 2 ) ) ) {
         
        for( unsigned it = 0; it  < iter - 1; ++it ) {
            vi -= inv( J ) * residul;
            for( unsigned i = 0; i < 3; i++ ) {
                J( i, 0 ) = f[i][1]+f[i][6]*vi[2];
                J( i, 1 ) = f[i][2]+f[i][8]*vi[2];
                J( i, 2 ) = f[i][3]+f[i][6]*vi[0]+f[i][8]*vi[1];           
            }
            residul = V3( polyres( f[0], vi ), polyres( f[1], vi ), polyres( f[2], vi ) );
            //PRINT( residul );
        }
        vi -= inv( J ) * residul;
    }
}

}

#endif /// NEWTON_FOR_ELEMENT_H
