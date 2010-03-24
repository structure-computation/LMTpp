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
#include "visitorbloc_getcaracteristicstruct.h"
#include "visitorbloc_namebaseclass.h"
#include "util2html.h"
#include "token.h"
#include "templateparameter.h"


VisitorBloc_GetCaracteristicStruct::~VisitorBloc_GetCaracteristicStruct() {

}

void VisitorBloc_GetCaracteristicStruct::exec( Bloc* b ) {

    ptr_listHerited = NULL;
}

void VisitorBloc_GetCaracteristicStruct::exec( Classe* c ) {

    ptr_listHerited = NULL;
}

void VisitorBloc_GetCaracteristicStruct::exec( ClasseMetil* c ) {

    ptr_listHerited = NULL;
}

void VisitorBloc_GetCaracteristicStruct::exec( Struct* s ) { 

    ptr_listHerited = &s->listHerited ;
}

void VisitorBloc_GetCaracteristicStruct::exec( Function* f ) {

    ptr_listHerited = NULL;
}












