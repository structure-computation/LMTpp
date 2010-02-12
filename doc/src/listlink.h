#ifndef LIST_LINK_H
#define LIST_LINK_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

#include "names.h"
#include "link.h"



struct ListLink {
    ListLink( ) { }
    ~ListLink() ;
    Link* isName( string& nom ) ;
    Link* isName_Hash( string& nom,unsigned h ) ;
    Link* isPrincipalName( string& nom ) ;
    void setPath( const string& p ) ;
    int number_of_principalName( string& n ) ;
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;

    //string findKeyword( int*t,int* posistion,int* positionAfter, string& s) ; 


    vector<Link*> list ;
} ;


#endif

