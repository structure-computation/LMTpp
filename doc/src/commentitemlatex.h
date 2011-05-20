#ifndef COMMENT_ITEM_LATEX_H
#define COMMENT_ITEM_LATEX_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

//struct CommentItem;
//struct VisitorCommentItem;
#include "commentitem.h"
#include "visitorcommentitem.h"
//#include "target.h"

struct CommentItemLaTex : public CommentItem { 
    CommentItemLaTex( string& option );
    virtual void print( std::ostream &os ) const { /*os << txt << endl;*/ }
    virtual void display( std::ostream &os );
    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItemLaTex( this );  }
    void addTxt(string& s,int end,int start );
    void addTxt(const char* s,int size );

    virtual ~CommentItemLaTex();

    string multipage;
    string txt;
};

#endif



