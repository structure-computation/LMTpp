#ifndef PARAMETER_H
#define PARAMETER_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

#include "tagcomment.h"
//struct Names ;
#include "names.h"

/*
cette structure hérite de TagComment car elle peut être commentable.
cette structure hérite de Target car elle peut être la cible d'un lien.
*/

struct Parameter : public TagComment {
    //Parameter(const Parameter& p);
    Parameter( ) { }
    ~Parameter() {} 
    void clear() { listAttribut.clear();nameVariable.clear();defaultType.clear();type.clear(); } 
    friend std::ostream &operator<<( std::ostream &os, Parameter& p ) ;
    
    string listAttribut ;
    Names type ;
    string nameVariable ;
    string op; /// op vaut soit rien soit = soit := soit ...
    string defaultType ;
} ;


#endif

