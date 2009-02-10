#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "op.h"
#include "classe.h"
#include "struct.h"
#include "bloc.h"
#include "visitorbloc.h"
#include "visitorbloc_namebaseclass.h"
#include "link.h"
#include "listlink.h"
#include "util2html.h"


VisitorBloc_NameBaseClass :: ~VisitorBloc_NameBaseClass() {

}

void VisitorBloc_NameBaseClass :: function_at_Bloc( Bloc* b ) {

}

void VisitorBloc_NameBaseClass :: function_at_Classe( Classe* c ) {

    Link* ptr_link ;

    ptr_link = new Link() ;
    ptr_link->name = c->name ;
    ptr_link->path = "structure/" ;
    ptr_link->name_file = french2webID( c->name.name ) + ".html" ;
    ptr_listLink->list.push_back( ptr_link ) ;
    //list_NameBaseClass.push_back( c->name ) ;
}

void VisitorBloc_NameBaseClass :: function_at_Struct( Struct* s ) { 

    Link* ptr_link ;

    ptr_link = new Link() ;
    ptr_link->name = s->name ;
    ptr_link->path = "structure/" ;
    ptr_link->name_file = french2webID( s->name.name ) + ".html" ;
    ptr_listLink->list.push_back( ptr_link ) ;
}

void VisitorBloc_NameBaseClass :: function_at_Function( Function* f ) {
}

/*
bool VisitorBloc_NameBaseClass :: isNameBaseClass( string& nom ) {

    int i,n ;
    
    n = list_NameBaseClass.size() ;
    for(i=0;i<n;i++) 
        if (nom == list_NameBaseClass[i].name )  return true ;
    return false ;
}

bool VisitorBloc_NameBaseClass :: isPrincipalNameBaseClass( string& nom ) {

    int i,n ;
    
    n = list_NameBaseClass.size() ;
    for(i=0;i<n;i++) 
        if (nom == list_NameBaseClass[i].principalName )  return true ;
    return false ;
}
*/









