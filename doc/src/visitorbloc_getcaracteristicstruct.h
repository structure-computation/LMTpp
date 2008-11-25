#ifndef VISITOR_BLOC_GET_CARACTERISTIC_STRUCT_H
#define VISITOR_BLOC_GET_CARACTERISTIC_STRUCT_H

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


struct VisitorBloc_GetCaracteristicStruct : public VisitorBloc {
    VisitorBloc_GetCaracteristicStruct( ) { }
    virtual ~VisitorBloc_GetCaracteristicStruct() ;
    virtual void function_at_Bloc( Bloc* b ) ;
    virtual void function_at_Classe( Classe* c ) ;
    virtual void function_at_Struct( Struct* s ) ;
    virtual void function_at_Function( Function* f ) ;


    bool enphase ;
    ListParameter* ptr_listHerited ;
} ;


#endif

