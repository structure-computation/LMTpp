#ifndef BLOC_H
#define BLOC_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

#include "visitorbloc.h"
//struct VisitorBloc;
//struct Parameter;
//struct TemplateParameter;
#include "parameter.h"
#include "templateparameter.h"
#include "names.h"
#include "target.h"
#include "listparameter.h"

typedef std::vector<TemplateParameter*> ListTemplateParameter;
//typedef std::vector<Parameter*> ListParameter;

struct Bloc : public TagComment, public Target  {
    Bloc() { }
    virtual ~Bloc();
    virtual void display( std::ostream &os );
    friend std::ostream &operator<<( std::ostream &os, Bloc &b );
    virtual void exec( VisitorBloc *v ) { v->exec( this );  }

    string _namespace;
    string portee;
    ListTemplateParameter listTemplateParameter;
    vector<Bloc*> list_subType_function;
    ListParameter listTypedef; // avec dans l'ordre le nom du type puis le synonyme
    ListParameter listMember;
};

#endif

