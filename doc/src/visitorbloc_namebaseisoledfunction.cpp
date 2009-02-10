#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "op.h"
#include "classe.h"
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_namebaseisoledfunction.h"
#include "link.h"
#include "listlink.h"
#include "util2html.h"


VisitorBloc_NameBaseIsoledFunction :: ~VisitorBloc_NameBaseIsoledFunction() {

}

void VisitorBloc_NameBaseIsoledFunction :: function_at_Bloc( Bloc* b ) {

}

void VisitorBloc_NameBaseIsoledFunction :: function_at_Classe( Classe* c ) {
}

void VisitorBloc_NameBaseIsoledFunction :: function_at_Struct( Struct* s ) { 

}

void VisitorBloc_NameBaseIsoledFunction :: function_at_Function( Function* f ) {

    //string h ;
    Link* ptr_link ;

    ptr_link = new Link() ;
    ptr_link->name = f->name ;
    ptr_link->path = "function/" ;
    //if ( f->name.hash != 0)
    //    h = hash2string( f->name.hash ) ;
    //else
    //    h = "" ;
    ptr_link->name_file = french2webID( f->name.name ) + '_' + hash2string( f->name.hash ) + ".html" ;
    ptr_listLink->list.push_back( ptr_link ) ;

    //list_NameBaseIsoledFunction.push_back( f->name ) ;
}




















