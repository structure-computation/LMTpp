#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>

#include<cmath>
#include"time.h"

using namespace std;

#include "op.h"
#include "parameter.h"
#include "classemetil.h"
#include "classe.h"
#include "struct.h"
#include "function.h"
#include "functionmetil.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_what_type.h"

#include "util2html.h"
#include "token.h"
#include "templateparameter.h"

void VisitorBloc_what_type::exec( Struct* s ) {

    type = "struct";
}

void VisitorBloc_what_type::exec( Function* f ) {

    type = "function";
}

void VisitorBloc_what_type::exec( FunctionMetil* f ) {

    type = "function";
}

void VisitorBloc_what_type::exec( Classe* c ) {

    type = "class";
}

void VisitorBloc_what_type::exec( ClasseMetil* c ) {

    type = "class";
}

void VisitorBloc_what_type::exec( Bloc* b ) {

    type = "bloc"; // ne devrait jamais être utilisée.
}







