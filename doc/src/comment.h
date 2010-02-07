#ifndef COMMENT_H
#define COMMENT_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

//struct CommentItem;
//struct LangRef;
//struct  Op;
#include "op.h"
#include "commentitem.h"
struct ListTarget;
struct Target;

#define COMMENT__RELATES 0 
#define COMMENT__FRIEND 1
#define COMMENT__STRUCT 2
#define COMMENT__LATEX 3
#define COMMENT__GENERIC_COMMENT 4
#define COMMENT__AUTHOR 5
#define COMMENT__EXAMPLE 6
#define COMMENT__TUTORIAL 7
#define COMMENT__BRIEF 8
#define COMMENT__PROPERTY 9
#define COMMENT__MAINCLASS 10
#define COMMENT__KEYWORD 11
#define COMMENT__PARAM 12
#define COMMENT__RETURN 13
#define COMMENT__INTERNAL 14
#define COMMENT__CODE 15
#define COMMENT__TABLE 16
#define COMMENT__WEBPAGE 17
#define COMMENT__MAIN 18
#define COMMENT__VERBATIM 19
#define COMMENT__A 20
#define COMMENT__ANCHOR 21
#define COMMENT__UNDEFINED 22

struct Comment {
    Comment( string& namefile ) { source_file = namefile; }
    ~Comment();
    void apply_on_related_to( const std::string &s, Op *op );
    friend std::ostream &operator<<( std::ostream &os, const Comment &c );

    void add_tutorial_example_genericComment_webpage_image( ListTarget* ptr_lt  );
    void parse( vector<CommentItem*>& listItems, string& file,int end, int start );
    void parse( vector<CommentItem*>& listItems, const char* start, int size );
    void generate_pageHTML( ofstream* ptr_ofstream, ListTarget* plt,Target* parent );


    string source_file;
    vector<CommentItem*> items;
    //LangRef *lang_ref;

    // private
    int findKeyword( int* position,int* positionAfter, string& s,int end,int start=0);
    bool chercher_section( int* nb, string& s, int end,int start );
    bool chercher_liste( int* nb, char* type, string& s, int end,int start );

    static const char* keyword[22];
};

int findKeyword_( int* position,int* positionAfter, const char* s, int end, int start=0);
bool chercher_section_( int* nb, const char* s, int end, int start );
bool chercher_liste_( int* nb, char* type, const char* s, int end, int start );

#endif

