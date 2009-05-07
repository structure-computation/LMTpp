#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "op.h"
#include "classe.h"
#include "classemetil.h"
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"


VisitorBloc::~VisitorBloc() {

}

void VisitorBloc::exec( Bloc* b ) { }

void VisitorBloc::exec( Classe* c ) { }

void VisitorBloc::exec( ClasseMetil* c ) { } 

void VisitorBloc::exec( Struct* s ) { }

void VisitorBloc::exec( Function* f ) { }











