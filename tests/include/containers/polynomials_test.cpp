#include <tests.h> /// pour la macro UNIT_TEST( )
#include <complex>
#include <iostream>
#include <containers/polynomials.h>

#ifdef METIL_COMP_DIRECTIVE
#pragma lib_name lapack
#endif

using namespace LMT;

int pol_degree_4_double_univariable_0() {
    typedef complex<double> C;
    Pol<4,1,double> P(Vec<double,5>(0.089772384592798626, -0.60532420499754847, -1.0755986070143191, -0.66382385694473234, -3.6694483295694546e-08) );
    double prec = 1e-4;
    
    Vec< C > sol = P.roots();
    std::cout << " racines => .120557492003962, -.870432417520779+.603404119273391*I, -18090561.2470167, -.870432417520779-.603404119273391*I" << std::endl;
    std::cout << sol << std::endl;
    bool r0 = ERROR_UNIT_TEST( sol[1] ,C( .120557492003962 ) ) < prec;
    bool r1 = ERROR_UNIT_TEST( sol[2] ,C( -.870432417520779, .603404119273391 ) ) < prec;
    bool r2 = ERROR_UNIT_TEST( sol[3] ,C( -.870432417520779,-.603404119273391 ) ) < prec;
    bool r3 = ERROR_UNIT_TEST( sol[0] ,C( -18090561.2470167 ) ) < prec;
    
    return not(r0) or not(r1) or not(r2) or not(r3);
};

int main() {
    UNIT_TEST( pol_degree_4_double_univariable_0() );
    
    return 0;
}



