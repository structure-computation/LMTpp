#ifndef VISITOR_BLOC_GET_CARACTERISTIC_FUNCTION_H
#define VISITOR_BLOC_GET_CARACTERISTIC_FUNCTION_H

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


struct VisitorBloc_GetCaracteristicFunction : public VisitorBloc {
    VisitorBloc_GetCaracteristicFunction( ) { }
    virtual ~VisitorBloc_GetCaracteristicFunction() ;
    virtual void function_at_Bloc( Bloc* b ) ;
    virtual void function_at_Classe( Classe* c ) ;
    virtual void function_at_Struct( Struct* s ) ;
    virtual void function_at_Function( Function* f ) ;

    bool enphase ;
    string* ptr_listAttribut ; // static, const, ...
    ListParameter* ptr_listParameter ;
    Names* ptr_returnType ;
} ;


#endif

