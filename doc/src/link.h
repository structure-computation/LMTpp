#ifndef LINK_H
#define LINK_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

#include "names.h"



struct Link {
    Link( ) { }
    ~Link() {} 
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;

    //string findKeyword( int*t,int* posistion,int* positionAfter, string& s) ; 


    Names name ;
    string path ;
    string name_file ;
} ;


#endif

