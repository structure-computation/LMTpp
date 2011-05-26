#ifndef VISITOR_BLOC_NAME_BASE_CLASS_H
#define VISITOR_BLOC_NAME_BASE_CLASS_H

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
struct Struct;
struct VisitorBloc;
struct ListLink;


struct VisitorBloc_NameBaseClass : public VisitorBloc {
    VisitorBloc_NameBaseClass( ListLink* plink ) { ptr_listLink = plink; }
    virtual ~VisitorBloc_NameBaseClass();
    virtual void exec( Bloc* b );
    virtual void exec( Classe* c );
    virtual void exec( ClasseMetil* c );
    virtual void exec( Struct* s );
    virtual void exec( Function* f );
    //bool isNameBaseClass( string& n );
    //bool isPrincipalNameBaseClass( string& n );

    ListLink* ptr_listLink;
};


#endif

