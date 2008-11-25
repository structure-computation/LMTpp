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
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_getsignature.h"
#include "visitorbloc_namebaseclass.h"




VisitorBloc_getSignature :: ~VisitorBloc_getSignature() {

}

void VisitorBloc_getSignature :: function_at_Bloc( Bloc* b ) {

    ptr_listParameter = NULL ;
}

void VisitorBloc_getSignature :: function_at_Classe( Classe* c ) {

    ptr_listParameter = NULL ;
}

void VisitorBloc_getSignature :: function_at_Struct( Struct* s ) { 

    ptr_listParameter = NULL ;
}

void VisitorBloc_getSignature :: function_at_Function( Function* f ) {

    ptr_listParameter = &f->listParameter ;
}











