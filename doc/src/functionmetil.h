#ifndef FUNCTION_METIL_H
#define FUNCTION_METIL_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

#include "tagcomment.h"
#include "visitorbloc.h"

#include "function.h"

struct FunctionMetil : public Function {
    FunctionMetil( ) { }
    ~FunctionMetil();
    virtual void display( std::ostream &os );
    virtual void exec( VisitorBloc *v ) { v->exec( this );  }
    //void apply_on_related_to( const std::string &s, Op *op );
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c );
    /// méthode virtuelle de target
    virtual bool of_function() { return true; }


    string condition; /// when
    double default_pertinence;
    //string referencement;
};


#endif

