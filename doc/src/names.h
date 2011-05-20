#ifndef NAMES_H
#define NAMES_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

//#include "tagcomment.h"


struct Names {
    //Names( const Names& n) { name = n.name; principalName = n.principalName; }
    Names( ) { }
    ~Names() {} 
    void clear() { name.clear();principalName.clear(); }
    //void apply_on_related_to( const std::string &s, Op *op );
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c );

    //string findKeyword( int*t,int* posistion,int* positionAfter, string& s); 


    string principalName;
    string name;
    //unsigned hash;
};


#endif

