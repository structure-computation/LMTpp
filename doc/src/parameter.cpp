#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "token.h"
#include "op.h"
#include "parameter.h"

// Parameter::Parameter(const Parameter& p){
//     listAttribut = p.listAttribut;
//     type = p.type;
//     nameVariable = p.nameVariable;
//     op = p.op;
//     defaultType = p.defaultType;
// }

std::ostream &operator<<( std::ostream &os, Parameter& p ) { 

    os << " type listAttribut   = |" << p.listAttribut << "|" << std::endl ;
    os << " type name           = |" << p.type.name << "|" << std::endl ;
    os << " type name principal = |" << p.type.principalName << "|" << std::endl ;
    os << " op                  = |" << p.op << "|" << std::endl ;
    os << " name of variable    = |" << p.nameVariable << "|" << std::endl ;
    os << " defaultType         = |" << p.defaultType << "|" << std::endl ;
    return os ;
} ;


