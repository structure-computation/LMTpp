#ifndef VISITOR_BLOC_WHAT_TYPE_H
#define VISITOR_BLOC_WHAT_TYPE_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

//struct CommentItem;
//struct LangRef;

struct Bloc;
struct Classe;
struct ClasseMetil;
struct Function;
struct FunctionMetil;
struct Struct;
struct VisitorBloc;
struct VisitorBloc_NameBaseClass;
struct ListTarget;

/*!
    cette classe permet d savoir si l'objet un bloc, une classe, ou une fonction

*/

struct VisitorBloc_what_type : public VisitorBloc {
    VisitorBloc_what_type( ) { type = "unkown_type"; }
    virtual ~VisitorBloc_what_type() {}
    virtual void exec( Bloc* b );
    virtual void exec( ClasseMetil* c );
    virtual void exec( Classe* c );
    virtual void exec( Struct* s );
    virtual void exec( Function* f );
    virtual void exec( FunctionMetil* f );
    
    /*!
    type peut prendre comme valeur :
        * bloc
        * struct
        * class
        * function
    */
    string type;
};


#endif

