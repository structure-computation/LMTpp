#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <iostream>
#include <exception>

#define UNIT_TEST_WITH_LABEL( name_proc, proc ) \
    try { std::cout << "\n" << __FILE__ << ":" << __LINE__ << ": __UNIT_TESTING_REPORT__ @@ " << name_proc << " @@ " << std::flush; bool res = ( proc );  std::cerr << std::flush; std::cout << ( res ? " >=>=>=> OK" : " >=>=>=> FAIL" ) << std::endl; } catch ( int e ) { std::cout << " >=>=>=> FAIL" << std::endl; }

#define UNIT_TEST( proc ) \
    UNIT_TEST_WITH_LABEL( #proc, proc )

#define UNIT_TEST_CMP_STRING( EXPR, VAL ) UNIT_TEST_WITH_LABEL( std::string( #EXPR ) + " = " + #VAL, String( EXPR ) == #VAL )

#define UNIT_TEST_CMP_STRING_WITH_TEXT( TEXT, EXPR, VAL ) UNIT_TEST_WITH_LABEL( TEXT, String( EXPR ) == #VAL )

#define ERROR_UNIT_TEST( a , b ) std::abs( (a) - (b) ) / ( 1e-20 + std::abs( a ) + std::abs( b ) )


#endif // UNIT_TEST_H