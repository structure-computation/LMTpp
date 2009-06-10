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
#include "classemetil.h"
#include "functionmetil.h"
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_getproperty.h"

void VisitorBloc_getProperty::exec( Bloc* b ) {
    ptr_listProperty = NULL;
}

void VisitorBloc_getProperty::exec( Classe* c ) {
    ptr_listProperty = NULL ;
}

void VisitorBloc_getProperty::exec( Struct* s ) { 
    ptr_listProperty = NULL;
}

void VisitorBloc_getProperty::exec( Function* f ) {
    ptr_listProperty = NULL;
}

void VisitorBloc_getProperty::exec( FunctionMetil* f ) {
    ptr_listProperty = NULL;
}

void VisitorBloc_getProperty::exec( ClasseMetil* c ) { 
    ptr_listProperty = &c->listProperty ;
}













