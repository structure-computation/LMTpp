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
#include "listparameter.h"
#include "classe.h"
#include "classemetil.h"
#include "struct.h"
#include "bloc.h"
#include "function.h"
#include "functionmetil.h"
#include "visitorbloc.h"
#include "visitorbloc_getsignature.h"
#include "visitorbloc_namebaseclass.h"




VisitorBloc_getSignature::~VisitorBloc_getSignature() {

}

void VisitorBloc_getSignature::exec( Bloc* b ) {

    ptr_listParameter = NULL ;
}

void VisitorBloc_getSignature::exec( Classe* c ) {

    ptr_listParameter = NULL ;
}

void VisitorBloc_getSignature::exec( ClasseMetil* c ) {

    ptr_listParameter = NULL ;
}

void VisitorBloc_getSignature::exec( Struct* s ) { 

    ptr_listParameter = NULL ;
}

void VisitorBloc_getSignature::exec( Function* f ) {

    ptr_listParameter = &f->listParameter ;
}

void VisitorBloc_getSignature::exec( FunctionMetil* f ) {

    ptr_listParameter = &f->listParameter ;
}









