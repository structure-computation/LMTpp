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
#include "function.h"
#include "functionmetil.h"
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_getstructclassfunction.h"
#include "util2html.h"
#include "token.h"
#include "templateparameter.h"


VisitorBloc_getStruct_Class_Function::~VisitorBloc_getStruct_Class_Function() { }

void VisitorBloc_getStruct_Class_Function::exec( Bloc* b ) {

    //isClass = false; isStruct = false; isFunction = false;
    pc = NULL; ps = NULL; pf = NULL; pcm = NULL; pfm = NULL;
}

void VisitorBloc_getStruct_Class_Function::exec( Classe* c ) {

    //isClass = true; isStruct = false; isFunction = false;
    pc = c; ps = NULL; pf = NULL; pcm = NULL; pfm = NULL;
}

void VisitorBloc_getStruct_Class_Function::exec( ClasseMetil* c ) {

    //isClass = true; isStruct = false; isFunction = false;
    pc = NULL; ps = NULL; pf = NULL; pcm = c; pfm = NULL;
}

void VisitorBloc_getStruct_Class_Function::exec( Struct* s ) { 

    //isClass = false; isStruct = true; isFunction = false;
    pc = NULL; ps = s; pf = NULL; pcm = NULL; pfm = NULL;
}

void VisitorBloc_getStruct_Class_Function::exec( Function* f ) {

    //isClass = false; isStruct = false; isFunction = true;
    pc = NULL; ps = NULL; pf = f; pcm = NULL; pfm = NULL;
}

void VisitorBloc_getStruct_Class_Function::exec( FunctionMetil* f ) {

    //isClass = false; isStruct = false; isFunction = true;
    pc = NULL; ps = NULL; pf = NULL; pcm = NULL; pfm = f;
}










