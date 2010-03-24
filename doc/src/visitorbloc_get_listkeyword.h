#ifndef VISITOR_BLOC_GET_LIST_KEYWORD_H
#define VISITOR_BLOC_GET_LIST_KEYWORD_H

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


    struct VisitorBloc_getListKeyword : public VisitorBloc {
    VisitorBloc_getListKeyword( ) { }
    virtual ~VisitorBloc_getListKeyword() {}
    virtual void exec( Bloc* b ) {}
    virtual void exec( Classe* c );
    virtual void exec( ClasseMetil* c );
    virtual void exec( Struct* s );
    virtual void exec( Function* f );
    virtual void exec( FunctionMetil* f );
    void init() { listkeyword_of_class_struct.clear(); listkeyword_of_function.clear(); }

    vector<string> listkeyword_of_class_struct;
    vector<string> listkeyword_of_function;
};


#endif

