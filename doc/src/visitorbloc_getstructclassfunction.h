#ifndef VISITOR_BLOC_GET_CARACTERISTIC_STRUCT_CLASS_FUNCTION_H
#define VISITOR_BLOC_GET_CARACTERISTIC_STRUCT_CLASS_FUNCTION_H

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


struct VisitorBloc_getStruct_Class_Function : public VisitorBloc {
    VisitorBloc_getStruct_Class_Function( ) { }
    virtual ~VisitorBloc_getStruct_Class_Function();
    virtual void exec( Bloc* b );
    virtual void exec( Classe* c );
    virtual void exec( ClasseMetil* c );
    virtual void exec( Struct* s );
    virtual void exec( Function* f );
    virtual void exec( FunctionMetil* f );

    bool isClass, isStruct, isFunction;
    Classe* pc;
    Struct* ps;
    Function* pf;
    FunctionMetil* pfm;
    ClasseMetil* pcm;
};


#endif

