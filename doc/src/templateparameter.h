#ifndef TEMPLATEPARAMETER_H
#define TEMPLATEPARAMETER_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;


#include "op.h"

/*
enum TypeTemplateID {
    UNKNOW_TYPE_TEMPLATE_ID = 0,
    CLASS_ID = 1,
    TYPENMAE_ID = 2,
    BOOL_ID = 3,
    INT_ID = 4,
    UNSIGNED_ID = 5,
    LONG_ID = 6,
    UNSIGNED_LONG_ID = 7,
    SHORT_ID = 8,
    UNSIGNED_SHORT_ID = 9
} ;*/


struct TemplateParameter {
    TemplateParameter() { }
    TemplateParameter( string& t, string& n, string& d ) { type = t ; name = n ; defaultType = d ; }
    ~TemplateParameter() ;
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;

    //int type ;
    string type ;
    string name ;
    string defaultType ;
} ;


#endif

