#ifndef COMMENT_H
#define COMMENT_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

//struct CommentItem ;
//struct LangRef ;
//struct  Op ;
#include "op.h"
#include "commentitem.h"


enum typeCommentID
{
//-------- types
 UNKNOWN_ID = 0 ,
 CLASS_ID = 1 ,
 STRUCT_ID = 2 ,
 FUNCTION_ID = 3 ,
 ENUM_ID = 4 ,
 METHOD_ID = 5 ,
 EXAMPLE_ID = 6 ,
 TUTORIAL_ID = 7,
//-------- caratéristiques
 BRIEF_ID = 32,
 PROPERTY_ID = 33,
 MAINCLASS_ID = 34,
 RELATEDTO_ID = 35,
 INCATEGORY_ID = 36,
 PARAM_ID = 37,
 RETURN_ID = 38,
 MEMBER_ID = 39,
//-------- caratéristiques spécifiques au commentaires "texte"
 CODE_ID = 64 ,
 ENDCODE_ID = 65,
 TABLE_ID = 66,
 HEADER_ID = 67,
 ENDTALBE_ID = 68
 } ;

struct Comment {
    Comment( /* const char *name_str*/  ) {
        // -> parser ( -> keyword )
        //items.push_back( new CommentItemTxt( std::string( b, e ) ) );
	//name = name_str ;
	//type = UNKNOWN_ID ;
    }
    ~Comment() ;
    void apply_on_related_to( const std::string &s, Op *op ) ;
    friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;
    //void setType( unsigned t) { type = t ; } ;
    void addCommentItem( CommentItem* ) ;
    void parse( vector<string>& file ) ;
    void generateHTML( string& name ) ;
    //string findKeyword( int*t,int* posistion,int* positionAfter, string& s) ; 
    //int type ;
    std::vector<CommentItem*> items;
    //LangRef *lang_ref;

    string findKeyword( int* t,int* posistion,int* positionAfter, string& s) ;
    static char* keyword[] ; 
} ;


#endif

