#ifndef CLASS_H
#define CLASS_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

//struct CommentItem ;
//struct LangRef ;
//struct  Op ;
#include "op.h"
#include "bloc.h"
#include "function.h"

// je fais ce cas particulier des typdef 

struct Typedef : public Bloc {
    Typedef( ) { }
    virtual ~Typedef() ;
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;

    string synonyme ;
} ;


#endif

