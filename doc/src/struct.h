#ifndef STRUCT_H
#define STRUCT_H

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
#include "tagcomment.h"
#include "visitorbloc.h"
#include "listparameter.h"

struct Struct : public Bloc {
    Struct( ) { }
    virtual ~Struct() ;
    virtual void display( std::ostream &os ) ;
    virtual void execute_function( VisitorBloc *v ) { v->function_at_Struct( this ) ;  }
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;

    // méthode virtuelle de target
    virtual bool of_class_or_struct() { return true; }
    virtual bool of_struct() { return true; }

    ListParameter listHerited ;
} ;


#endif

