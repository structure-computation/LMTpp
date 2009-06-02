#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>

#include<cmath>
#include"time.h"

using namespace std;

#include "parameter.h"
#include "classe.h"
#include "classemetil.h"
#include "struct.h"
#include "bloc.h"
#include "function.h"
#include "functionmetil.h"
#include "visitorbloc.h"
#include "visitorbloc_setpath_html.h"
#include "util2html.h"
#include "token.h"
#include "templateparameter.h"

void VisitorBloc_SetPath_HTML::setRepertory_function( const string& s ) {

    repertory_function = s;
}

void VisitorBloc_SetPath_HTML::setRepertory_struct( const string& s ) {

    repertory_struct = s;
}

void VisitorBloc_SetPath_HTML::setRepertory_class( const string& s ) {

    repertory_class = s;
}


void VisitorBloc_SetPath_HTML::exec( Bloc* b ) {

    // les blocs n'ont pas de page web : on ne fait donc rien
}

void VisitorBloc_SetPath_HTML::exec( Classe* c ) {

    c->path = repertory_class;
}

void VisitorBloc_SetPath_HTML::exec( ClasseMetil* c ) {
    
    c->path = repertory_class;
}

void VisitorBloc_SetPath_HTML::exec( Struct* s ) { 

    s->path = repertory_struct;
}

void VisitorBloc_SetPath_HTML::exec( Function* f ) {

    f->path = repertory_function;
}

void VisitorBloc_SetPath_HTML::exec( FunctionMetil* f ) {

    f->path = repertory_function;
}









