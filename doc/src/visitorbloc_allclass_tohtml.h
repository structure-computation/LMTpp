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
struct FunctionMetil;
struct Struct;
struct VisitorBloc;
struct VisitorBloc_NameBaseClass;
struct ListTarget;
struct Target;

typedef enum {
    Normal = 0,
    Link = 1,
    Anchor = 2
} TypeDisplayName;

/*!
    Cette classe très importante convertit les objets Bloc et ses enfants en fragment de code  HTML

*/
struct VisitorBloc_AllClass_toHTML : public VisitorBloc {
    VisitorBloc_AllClass_toHTML( ListTarget* plt,map<string,string>* pt  ) { ptr_list_target = plt; ptr_tree = pt; }
    virtual ~VisitorBloc_AllClass_toHTML() {}
    virtual void exec( Bloc* b ) {}
    virtual void exec( Classe* c );
    virtual void exec( ClasseMetil* c );
    virtual void exec( Struct* s );
    virtual void exec( Function* f );
    virtual void exec( FunctionMetil* f );
    void setParent( Target* pp) { ptr_parent= pp; }


    void generate_page_HTML_for_class_or_struct( const string& type_block, Bloc* b );

    void generate_stream_HTML_for_inheritance( ofstream* f, Bloc* b );
    void generate_stream_HTML_for_template_cpp( ofstream* f, Bloc* b );
    void generate_stream_HTML_for_typedef( ofstream* f, Bloc* b, bool sommary );
    void generate_stream_HTML_for_sub_class_struct_function( ofstream* f, Bloc* b, TypeDisplayName t );/// pour du code C++
//     void generate_stream_HTML_for_classMetil( ofstream* f, Bloc* b, bool sommary );
    void generate_stream_HTML_for_sub_classMetil_functionMetil( ofstream* f, Bloc* b, TypeDisplayName t );
    void generate_stream_HTML_for_function( ofstream* o, Function* f, TypeDisplayName t );
    void generate_stream_HTML_for_functionMetil( ofstream* o, FunctionMetil* f, TypeDisplayName t );
    void generate_stream_HTML_for_attribut( ofstream* f, Bloc* b, bool sommary );
    void generate_stream_HTML_for_property( ofstream* f, ClasseMetil* b, bool sommary );

    ListTarget* ptr_list_target;
    Target* ptr_parent;
    map<string,string>* ptr_tree;
};


#endif

