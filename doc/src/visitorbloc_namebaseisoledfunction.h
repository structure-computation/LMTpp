#ifndef VISITOR_BLOC_NAME_BASE_ISOLED_FUNCTION_H
#define VISITOR_BLOC_NAME_BASE_ISOLED_FUNCTION_H

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
struct ListLink ;

struct VisitorBloc_NameBaseIsoledFunction : public VisitorBloc {
    VisitorBloc_NameBaseIsoledFunction( ListLink* plink ) { ptr_listLink = plink ; }
    virtual ~VisitorBloc_NameBaseIsoledFunction() ;
    virtual void function_at_Bloc( Bloc* b ) ;
    virtual void function_at_Classe( Classe* c ) ;
    virtual void function_at_Struct( Struct* s ) ;
    virtual void function_at_Function( Function* f ) ;

    //bool isNameBaseIsoledFunction( string& nom ) ;
    //bool isPrincipalNameBaseIsoledFunction( string& nom ) ;

    ListLink* ptr_listLink ;
    //vector<Names> list_NameBaseIsoledFunction ;
} ;


#endif

