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
    Parameter( ) { }
    ~Parameter() {} 

    string listAttribut ;
    Names type ;
    string nameVariable ;
    string defaultType ;
} ;


#endif

