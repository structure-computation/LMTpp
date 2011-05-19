#ifndef VISITOR_BLOC_GET_PROPERTY_H
#define VISITOR_BLOC_GET_PROPERTY_H

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


struct VisitorBloc_getProperty : public VisitorBloc {
    VisitorBloc_getProperty( ) { }
    virtual ~VisitorBloc_getProperty() {}
    virtual void exec( Bloc* b );
    virtual void exec( ClasseMetil* c );
    virtual void exec( Classe* c );
    virtual void exec( Struct* s );
    virtual void exec( Function* f );
    virtual void exec( FunctionMetil* f );
    
    vector<Parameter>* ptr_listProperty;
};


#endif

