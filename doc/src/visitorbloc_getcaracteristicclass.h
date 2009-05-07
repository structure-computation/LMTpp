#ifndef VISITOR_BLOC_GET_CARACTERISTIC_CLASS_H
#define VISITOR_BLOC_GET_CARACTERISTIC_CLASS_H

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
struct ClasseMetil ;
struct Function ;
struct Struct ;
struct VisitorBloc ;


    struct VisitorBloc_GetCaracteristicClass : public VisitorBloc {
    VisitorBloc_GetCaracteristicClass( ) { }
    virtual ~VisitorBloc_GetCaracteristicClass() ;
    virtual void exec( Bloc* b ) ;
    virtual void exec( Classe* c ) ;
    virtual void exec( ClasseMetil* c ) ;
    virtual void exec( Struct* s ) ;
    virtual void exec( Function* f ) ;

    ListParameter* ptr_listHerited ;
} ;


#endif

