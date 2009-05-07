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
#include "bloc.h"  // pour le type ListParameter
#include "function.h"
#include "tagcomment.h"
#include "visitorbloc.h"
#include "listparameter.h"

struct Parameter ;

struct Classe : public Bloc {
    Classe( ) { }
    virtual ~Classe() ;
    virtual void display( std::ostream &os ) ;
    virtual void exec( VisitorBloc *v ) { v->exec( this ) ;  }
    //void apply_on_related_to( const std::string &s, Op *op ) ;

    /// méthode virtuelle de target
    virtual bool of_class_or_struct() { return true; }
    virtual bool of_class() { return true; }

    ListParameter listHerited ;
} ;


#endif

