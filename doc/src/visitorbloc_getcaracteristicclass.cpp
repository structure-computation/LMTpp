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
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_getcaracteristicclass.h"
#include "visitorbloc_namebaseclass.h"
#include "util2html.h"
#include "token.h"
#include "templateparameter.h"


VisitorBloc_GetCaracteristicClass::~VisitorBloc_GetCaracteristicClass() {

}

void VisitorBloc_GetCaracteristicClass::exec( Bloc* b ) {

    ptr_listHerited = NULL;
}

void VisitorBloc_GetCaracteristicClass::exec( Classe* c ) {

    ptr_listHerited = &c->listHerited ;
}

void VisitorBloc_GetCaracteristicClass::exec( Struct* s ) { 

    ptr_listHerited = NULL;
}

void VisitorBloc_GetCaracteristicClass::exec( Function* f ) {

    ptr_listHerited = NULL;
}

void VisitorBloc_GetCaracteristicClass::exec( ClasseMetil* c ) {
    
    ptr_listHerited = &c->listHerited ;
}













