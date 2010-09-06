#include <util/unit_test.h> /// pour la macro UNIT_TEST( )
#include <containers/vec.h>
#include <mesh/pyramid.h>
using namespace LMT;

#ifdef METIL_COMP_DIRECTIVE
#pragma lib_name xml2
#endif

int var_inter_is_inside_Pyramid_0() {
    return not( var_inter_is_inside( Pyramid(), Vec<double,3>( 0, 0, 0 ), 1e-20 ) );
};

int var_inter_is_inside_Pyramid_1() {
    return not( var_inter_is_inside( Pyramid(), Vec<double,3>( 0.5, 0.5, 0.5 ), 1e-20 ) );
};

int var_inter_is_inside_Pyramid_2() {
    return var_inter_is_inside( Pyramid(), Vec<double,3>( 1, 1, 1 ), 1e-20 ) ;
};

int main() {
    UNIT_TEST( var_inter_is_inside_Pyramid_0() );
    UNIT_TEST( var_inter_is_inside_Pyramid_1() );
    UNIT_TEST( var_inter_is_inside_Pyramid_2() );
    return 0;
}



