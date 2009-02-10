#ifndef VISITOR_BLOC_GET_SIGNATURE_H
#define VISITOR_BLOC_GET_SIGNATURE_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>

using namespace std ;

//struct CommentItem ;
//struct LangRef ;

struct Bloc ;
struct Classe ;
struct Function ;
struct Struct ;
struct VisitorBloc ;
struct Names ;
struct ListParameter ;


struct VisitorBloc_getSignature : public VisitorBloc {
    VisitorBloc_getSignature() { }
    virtual ~VisitorBloc_getSignature() ;
    virtual void function_at_Bloc( Bloc* b ) ;
    virtual void function_at_Classe( Classe* c ) ;
    virtual void function_at_Struct( Struct* s ) ;
    virtual void function_at_Function( Function* f ) ;

    ListParameter* ptr_listParameter ;
} ;


#endif

