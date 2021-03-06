#ifndef VISITOR_BLOC_ALL_CLASS_H
#define VISITOR_BLOC_ALL_CLASS_H

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

struct VisitorBloc_AllClass : public VisitorBloc {
    VisitorBloc_AllClass( ListTarget* plt  ) { ptr_list_target = plt ; }
    virtual ~VisitorBloc_AllClass() ;
    virtual void function_at_Bloc( Bloc* b ) ;
    virtual void function_at_Classe( Classe* c ) ;
    virtual void function_at_Struct( Struct* s ) ;
    virtual void function_at_Function( Function* f ) ;
    
    void generate_page_HTML_for_class_or_struct( const string& type_block, Bloc* b, const string& path, const string& name_file ) ;
    void generate_stream_HTML_for_typedef( ofstream* f, Bloc* b, bool sommary ) ;
    void generate_stream_HTML_for_class_or_struct( ofstream* f, Bloc* b, bool sommary ) ;
    void generate_stream_HTML_for_method( ofstream* f, Bloc* b, bool sommary ) ;
    void generate_stream_HTML_for_attribut( ofstream* f, Bloc* b, bool sommary ) ;

    ListTarget* ptr_list_target ;
} ;


#endif

