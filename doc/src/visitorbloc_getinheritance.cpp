#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>

#include<cmath>
#include"time.h"

using namespace std ;

#include "op.h"
#include "parameter.h"
#include "classe.h"
#include "function.h"
#include "functionmetil.h"
#include "classemetil.h"
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_getinheritance.h"
#include "visitorbloc_namebaseclass.h"
#include "util2html.h"
#include "token.h"
#include "templateparameter.h"

void VisitorBloc_GetInheritance::exec( Bloc* b ) {

    ptr_listHerited = NULL;
}

void VisitorBloc_GetInheritance::exec( Classe* c ) {

    ptr_listHerited = &c->listHerited ;
}

void VisitorBloc_GetInheritance::exec( Struct* s ) { 

    ptr_listHerited = &s->listHerited;
}

void VisitorBloc_GetInheritance::exec( Function* f ) {

    ptr_listHerited = NULL;
}

void VisitorBloc_GetInheritance::exec( FunctionMetil* f ) {

    ptr_listHerited = NULL;
}

void VisitorBloc_GetInheritance::exec( ClasseMetil* c ) {

    ptr_listHerited = &c->listHerited ;
}













