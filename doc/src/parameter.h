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
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;

    //string findKeyword( int*t,int* posistion,int* positionAfter, string& s) ; 

    //std::vector<string> listAttribut ;
    //int numberFlag ;
    string listAttribut ;
    Names type ;
    string nameVariable ;
    string defaultType ;
    //string referencement ;
} ;


#endif

