
#include <vector>

#include "get_var_inter_common.h"

namespace LMT {

void display_poly_2X( unsigned N ) {
    unsigned l0;
    unsigned l0_bound[2], i[2]; 

    l0 = 0;
    l0_bound[0] = ind_2( 0 ); /// 0 = l0
    l0_bound[1] = ind_2( 1 ); /// 1 = l0 + 1
    for (unsigned n=0; n< N; ++n) {
        PRINT( n );// PRINT( l0_bound[0] ); PRINT( l0_bound[1] ); 
        if (n < l0_bound[1]) {
            i[1] = n-l0_bound[0];
            i[0] = l0 - i[1]; 
            std::cout << " i = " << i[0] << " , j = " << i[1] << std::endl;         
        } else {
            l0++;
            l0_bound[0] = l0_bound[1];
            l0_bound[1] = ind_2( l0+1 );
            i[0] = l0;
            i[1] = 0;
            std::cout << " i = " << i[0] << " , j = " << i[1] << std::endl;
        }
    }
}
    
    
void difference( std::vector<unsigned>& v, const std::vector<unsigned>& cut ) {
    unsigned j;
    for( unsigned i = 0 ; i < cut.size(); ++i ) {
        j = 0;
        while (j< v.size()) {
            if (v[j] == cut[i])
                v.erase( v.begin() + j );
            else
                j++;   
        }
    }
}

void display_poly_3X( unsigned N ) {
    unsigned l0, l1;
    unsigned l0_bound[2], l1_bound[2], i[3]; 

    l0 = 0;
    l0_bound[0] = 0; /// ind_3( l0 );
    l0_bound[1] = ind_3( 1 ); /// 1 = l0 + 1
    l1 = 0;
    l1_bound[0] = 0; /// ind_2( 0 );
    l1_bound[1] = ind_2( 1 ); /// 1 = l1 + 1
    for (unsigned n=0; n< N; ++n) {
        PRINT( n );// PRINT( l0_bound[0] ); PRINT( l0_bound[1] ); PRINT( l1_bound[0] ); PRINT( l1_bound[1] ); PRINT( l0 ); PRINT( l1 );
        if (n < l0_bound[1]) {
            if (n-l0_bound[0] < l1_bound[1] ) {
                i[2] = n - l0_bound[0] - l1_bound[0];
                i[1] = l1 - i[2];
                i[0] = l0 - i[1] - i[2];
                std::cout << " i = " << i[0] << " , j = " << i[1] << " , k = " << i[2] << std::endl;
            } else {
                l1++;
                i[2] = 0;
                i[1] = l1;
                i[0] = l0 - i[1];
                std::cout << " i = " << i[0] << " , j = " << i[1] << " , k = " << i[2] << std::endl;
                l1_bound[0] = l1_bound[1];
                l1_bound[1] = ind_2( l1+1 ); 
                //PRINT( l1_bound[0] ); PRINT( l1_bound[1] );     
            }
        } else {
        /// j=k=0 et i = l0
            l0++;
            i[0] = l0;
            i[1] = 0;
            i[2] = 0;
            std::cout << " i = " << i[0] << " , j = " << i[1] << " , k = " << i[2] << std::endl;
            l0_bound[0] = l0_bound[1];
            l0_bound[1] = ind_3( l0+1 );
            l1 = 0;
            l1_bound[0] = 0; /// ind_2( 0 );
            l1_bound[1] = ind_2( 1 ); /// 1 = l1 + 1 
        }
    
    }
}


}