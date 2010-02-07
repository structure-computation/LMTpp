#ifndef VISITOR_BLOC_SET_PATH_HTML_H
#define VISITOR_BLOC_SET_PATH_HTML_H

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


// l'objectif de cette structure est de définir les les chemins des pages web de chaque bloc dans pour pouvoir constuire les liens HTML.

struct VisitorBloc_SetPath_HTML : public VisitorBloc {
    VisitorBloc_SetPath_HTML( ) { }
    virtual ~VisitorBloc_SetPath_HTML() {}
    virtual void exec( Bloc* b );
    virtual void exec( ClasseMetil* c );
    virtual void exec( Classe* c );
    virtual void exec( Struct* s );
    virtual void exec( Function* f );
    virtual void exec( FunctionMetil* f );
    void setRepertory_function( const string& s );
    void setRepertory_struct( const string& s );
    void setRepertory_class( const string& s );

    string repertory_function;
    string repertory_struct;
    string repertory_class;
};


#endif

