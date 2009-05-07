#ifndef VISITOR_BLOC_H
#define VISITOR_BLOC_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

//struct CommentItem;
//struct LangRef;

struct Bloc;
struct Classe;
struct ClasseMetil;
struct Function;
struct Struct;

struct VisitorBloc {
    VisitorBloc( ) { }
    virtual ~VisitorBloc();
    virtual void exec( Bloc* b );
    virtual void exec( Classe* c );
    virtual void exec( ClasseMetil* c );
    virtual void exec( Struct* s );
    virtual void exec( Function* f );
    //void apply_on_related_to( const std::string &s, Op *op );
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c );
};


#endif

