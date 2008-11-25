#ifndef COMMENT_ITEM_LATEX_H
#define COMMENT_ITEM_LATEX_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

//struct CommentItem ;
//struct VisitorCommentItem ;
#include "commentitem.h"
#include "visitorcommentitem.h"
//#include "target.h"

struct CommentItemLaTex : public CommentItem /*, public Target*/ { 
    CommentItemLaTex() ;
    virtual void print( std::ostream &os ) const { /*os << txt << endl ;*/ }
    virtual void display( std::ostream &os ) ;
    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItemLaTex( this ) ;  }
    void addTxt(string& s,int end,int start ) ;

    virtual ~CommentItemLaTex() ;

    //string reference ;
    string txt ;
};

#endif



