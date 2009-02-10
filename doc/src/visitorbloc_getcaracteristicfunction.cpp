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
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_getcaracteristicfunction.h"
#include "visitorbloc_namebaseclass.h"
#include "util2html.h"
#include "token.h"
#include "templateparameter.h"


VisitorBloc_GetCaracteristicFunction :: ~VisitorBloc_GetCaracteristicFunction() {

}

void VisitorBloc_GetCaracteristicFunction :: function_at_Bloc( Bloc* b ) {

    enphase = false ;
}

void VisitorBloc_GetCaracteristicFunction :: function_at_Classe( Classe* c ) {

    enphase = false ;
}

void VisitorBloc_GetCaracteristicFunction :: function_at_Struct( Struct* s ) { 

    enphase = false ;
}

void VisitorBloc_GetCaracteristicFunction :: function_at_Function( Function* f ) {

    enphase = true ;
    ptr_listAttribut = &f->listAttribut ;
    ptr_listParameter = &f->listParameter ;
    ptr_returnType = &f->returnType ;
}











