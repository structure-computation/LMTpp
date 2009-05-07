#ifndef VISITOR_BLOC_ALL_CLASS_TO_HTML_H
#define VISITOR_BLOC_ALL_CLASS_TO_HTML_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>
#include<map>

using namespace std;

//struct CommentItem;
//struct LangRef;

struct Bloc;
struct Classe;
struct ClasseMetil;
struct Function;
struct Struct;
struct VisitorBloc;
struct VisitorBloc_NameBaseClass;
struct ListTarget;
struct Target;

struct VisitorBloc_AllClass_toHTML : public VisitorBloc {
    VisitorBloc_AllClass_toHTML( ListTarget* plt,map<string,string>* pt  ) { ptr_list_target = plt; ptr_tree = pt; }
    virtual ~VisitorBloc_AllClass_toHTML() {}
    virtual void exec( Bloc* b ) {}
    virtual void exec( Classe* c );
    virtual void exec( ClasseMetil* c );
    virtual void exec( Struct* s );
    virtual void exec( Function* f );
    
    void setParent( Target* pp) { ptr_parent= pp; }
    
    void generate_page_HTML_for_class_or_struct( const string& type_block, Bloc* b );
    void generate_stream_HTML_for_inheritance( ofstream* f, Bloc* b );
    void generate_stream_HTML_for_template( ofstream* f, Bloc* b );
    void generate_stream_HTML_for_typedef( ofstream* f, Bloc* b, bool sommary );
    void generate_stream_HTML_for_class_or_struct( ofstream* f, Bloc* b, bool sommary );
    void generate_stream_HTML_for_classMetil( ofstream* f, Bloc* b, bool sommary );
    void generate_stream_HTML_for_method( ofstream* f, Bloc* b, bool sommary );
    void generate_stream_HTML_for_attribut( ofstream* f, Bloc* b, bool sommary );
    void generate_stream_HTML_for_property( ofstream* f, ClasseMetil* b, bool sommary );

    ListTarget* ptr_list_target;
    Target* ptr_parent;
    map<string,string>* ptr_tree;
};


#endif

