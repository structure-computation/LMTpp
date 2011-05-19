#ifndef VISITOR_BLOC_GET_INHERITANCE_H
#define VISITOR_BLOC_GET_INHERITANCE_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>

using namespace std ;

struct Bloc ;
struct Classe ;
struct ClasseMetil ;
struct Function ;
struct FunctionMetil ;
struct Struct ;
struct VisitorBloc ;

struct ListParameter;

struct VisitorBloc_GetInheritance : public VisitorBloc {
    VisitorBloc_GetInheritance( ) { }
    virtual ~VisitorBloc_GetInheritance() {}
    virtual void exec( Bloc* b ) ;
    virtual void exec( Classe* c ) ;
    virtual void exec( ClasseMetil* c ) ;
    virtual void exec( Struct* s ) ;
    virtual void exec( Function* f ) ;
    virtual void exec( FunctionMetil* f ) ;

    ListParameter* ptr_listHerited ;
} ;


#endif

