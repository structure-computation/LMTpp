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
    int findKeyword( int* posistion,int* positionAfter, string& s,int end,int start=0);
    bool chercher_section( int* nb, string& s, int end,int start );
    bool chercher_liste( int* nb, char* type, string& s, int end,int start );
    static const char* keyword[22];
};

#endif

