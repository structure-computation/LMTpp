#ifndef VISITOR_BLOC_WHAT_TYPE_H
#define VISITOR_BLOC_WHAT_TYPE_H

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
struct VisitorBloc_NameBaseClass ;
struct ListTarget ;

/*!
    cette classe permet d savoir si l'objet un bloc, une classe, ou une fonction

*/

struct VisitorBloc_what_type : public VisitorBloc {
    VisitorBloc_what_type( ) { type = "unkown_type" ; }
    virtual ~VisitorBloc_what_type() {}
    virtual void function_at_Bloc( Bloc* b ) ;
    virtual void function_at_Classe( Classe* c ) ;
    virtual void function_at_Struct( Struct* s ) ;
    virtual void function_at_Function( Function* f ) ;

    /*!
    type peut prendre comme valeur :
        * bloc
        * struct
        * class
        * function
    */
    string type ;
} ;


#endif

