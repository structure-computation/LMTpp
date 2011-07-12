#ifndef REDUCTION_RESULTANT_FOR_ELEMENT_H
#define REDUCTION_RESULTANT_FOR_ELEMENT_H

#include "vec.h"
#include "../mesh/Hexa.h"
#include "../mesh/Wedge.h"
#include "../mesh/pyramid.h"

namespace LMT {

template<class T, int s, int sr, class NE >
Vec<T,sr> reduction_resultant_for_element( const NE &ne, const Vec<T,s> &f, const Vec<T,s> &h ) {
    return Vec<T,sr>( 0 );
}

template<class T>
Vec<T,15> reduction_resultant_for_element( const Hexa &ne, const Vec<T,20> &f, const Vec<T,20> &h ) {
    Vec<T,15> res;
    
    res[0]  = f[0]*h[3]-f[3]*h[0];
    res[1]  = f[0]*h[6]-f[3]*h[1]+f[1]*h[3]-f[6]*h[0];
    res[2]  = f[0]*h[8]-f[8]*h[0]-f[3]*h[2]+f[2]*h[3];
    res[3]  = -f[6]*h[1]+f[1]*h[6];
    res[4]  = f[0]*h[14]+f[1]*h[8]+f[2]*h[6]-f[3]*h[5]+f[5]*h[3]-f[6]*h[2]-f[8]*h[1]-f[14]*h[0];
    res[5]  = f[2]*h[8]-f[8]*h[2];
    res[6]  = 0; /// U^3
    res[7]  = f[1]*h[14]+f[5]*h[6]-f[6]*h[5]-f[14]*h[1];
    res[8]  = f[2]*h[14]+f[5]*h[8]-f[8]*h[5]-f[14]*h[2];
    res[9]  = 0; /// V^3
    res[10] = 0; /// U^4
    res[11] = 0; /// U^3 * V
    res[12] = f[5]*h[14]-f[14]*h[5]; /// U^2 * V^2 
    res[13] = 0; /// U * V^3 
    res[14] = 0; /// V^4
    return res;
}

template<class T>
Vec<T,6> reduction_resultant_for_element( const Wedge &ne, const Vec<T,10> &f, const Vec<T,10> &g ) {
    Vec<T,6> res;
    
    res[0] = g[0]*f[3]-f[0]*g[3];
    res[1] = g[0]*f[6]+g[1]*f[3]-f[0]*g[6]-f[1]*g[3];
    res[2] = g[0]*f[8]+f[3]*g[2]-f[0]*g[8]-g[3]*f[2];
    res[3] = g[1]*f[6]-f[1]*g[6];
    res[4] = g[1]*f[8]+f[6]*g[2]-f[1]*g[8]-g[6]*f[2];
    res[5] = g[2]*f[8]-f[2]*g[8];
    return res;
}

template<class T>
Vec<T,6> reduction_resultant_for_element( const Pyramid &ne, const Vec<T,10> &f, const Vec<T,10> &g ) {
    Vec<T,6> res;
    
    res[0] = g[0]*f[3]-f[0]*g[3];
    res[1] = g[1]*f[3]-f[1]*g[3];
    res[2] = g[0]*f[8]+f[3]*g[2]-f[0]*g[8]-g[3]*f[2];
    res[3] = 0;
    res[4] = g[1]*f[8]-f[1]*g[8];
    res[5] = g[2]*f[8]-f[2]*g[8];
    return res;
}

}

#endif /// REDUCTION_RESULTANT_FOR_ELEMENT_H
