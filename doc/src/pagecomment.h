#ifndef PAGE_COMMENT_H
#define PAGE_COMMENT_H

#include<deque>
//struct Op;
//struct Comment;
#include "op.h"
#include "comment.h"
#include "templateparameter.h"
#include "bloc.h"// pour listParameter
#include "classe.h"
#include "struct.h"
#include "function.h"
#include "language_id.h"

class LexemDefinition;
class Lexem;

//struct ListTemplateParameter;

enum TYPE_PART_ID {
    PART_CODE_ID = 0 ,
    PART_TRUE_COMMENT_ID = 1,
    PART_COMMENT_ID = 2 
};

enum STATE_ID {
    NOT_STATE_ID = -1,
    OPEN_STATE_ID =0,
    TEMPLATE_STATE_ID = 1,
    CLASS_STATE_ID = 2,
    STRUCT_STATE_ID = 3,
    FUNCTION_STATE_ID = 4,
    TYPEDEF_STATE_ID = 5,
    NAMESPACE_STATE_ID = 6,
    TAG_STATE_ID = 7,
    PORTED_STATE_ID = 8,
    EXTERN_STATE_ID = 9,
    PREPROCESSOR_STATE_ID = 10
};

struct PageComment {
    PageComment( const char* file);
    ~PageComment();
    void parse(Language_id id); // cette fonction parse le code c/c++ ou metil et aussi les commentaires.
    void parse_language_Cpp(string& textOfCode);
    void parse_language_Metil(string& textOfCode);
    string getName();
    string getNameFile();
    void apply_on_related_to( const std::string &s, Op *op );
    friend std::ostream &operator<<( std::ostream &os, PageComment &c );
    void addComment( Comment* c );


    /// juste pour l'analyse de Metil
    //Lexem* research_containerType(Lexem* _le);
    Lexem* research_if_assign_reassign(Lexem* _le);
    void parse_language_Metil_rec( Bloc* code, Lexem* le);
    void append_function( Bloc* code, const Lexem* le);
    void append_class( Bloc* code, const Lexem* le);
    void append_member( Bloc* code, Lexem* start, Lexem* le);
    void append_property( Bloc* code, const Lexem* le);
    /// juste pour l'analyse de C++
    void parse_language_Cpp_rec( Bloc* code, string& textOfCode, int end, int start );
    int state( string& t ,int end, int start );
    string state_namespace( int* suivant, string& t ,int end, int start ); // renvoie le nom du namespace
    bool state_extern( int* suivant, string& t ,int end, int start );
    void state_preprocessor( int* suivant, string& t ,int end, int start );
    void state_template( int* suivant, ListTemplateParameter& listeParam, string& t ,int end, int start );
    void state_typedef( int* suivant, Names& type, string& synonyme, string& t ,int end, int start );
    //void state_function( int* suivant, Function* f, string& t ,int end, int start );
    void extract_ported( int* suivant, string& name, string& t ,int end, int start );
    void extract_name_heritedClass( int* suivant, Names& name, ListParameter& lp ,  char* delim, string& t ,int end, int start );
    int index_begin_signature( string& t ,int end, int start );
    void extract_returnType_name( int* suivant ,const string& name_structure, Names& returnType, Names& name, string& t ,int end, int start );
    void extract_parametersFunction( int* suivant, ListParameter& listeParam, string& t ,int end, int start );
    void extract_FinalAttributFunction( int* suivant, string& attrib, char* delim, string& t ,int end, int start );
    //void get_block(int* suivant, string& t ,int end, int start );
    void get_declaration( Parameter& p, string& t,int end, int start );
    //void extract_list_lexem( int* suivant, deque<int>& listeIndex,char* delim,const char* ldelim, string& t ,int end, int start );
    void copy_listTemplateParameter( ListTemplateParameter& res, ListTemplateParameter& src );
    bool code_before_comment(string& t ,int start );
    bool comment_of_code( string& s); // pour savoir si c'est un commentaire de code ou un commentaire example ou tutorial
    string principal_type_of( string& n); // renvoie N pour pour le type de la forme A N(<X>)(*&) où A, et X sont quelconques 
    
    
    string nameWithoutSuffix;
    string nameFile;
    string suffix_source;
    std::vector<Comment*> listComment; /// liste des commentaires de la page
    Bloc code;  /// bloc contenant tout le code de la page
    
    static const char* prefixTag[]; 
};


#endif

