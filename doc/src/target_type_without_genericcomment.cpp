#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "target_type_without_genericcomment.h"

void Target_type_without_genericComment :: display( std::ostream &os ) {


//     int i,n,m,j ;
    
    os << "### Target_type_without_genericComment ### "<< endl ;
//     os << " namespace = " << _namespace << endl ;
    os << " name = " << name.name << endl ;
    os << " name principal = " << name.principalName << endl ;
//     os << " portee = " << portee << endl ;


}

/*inline*/ std::ostream &operator<<( std::ostream &os, Target_type_without_genericComment &b ) { 
    b.display( os ) ;
    return os ;
} ;


