#ifndef COMMENT_ITEM_CODE_H
#define COMMENT_ITEM_CODE_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

//struct CommentItem ;
#include "commentitem.h"
#include "visitorcommentitem.h"

struct CommentItemExampleTutorial : public CommentItem { 
    CommentItemCode( string& langue) ;
    virtual void print( std::ostream &os ) const { /*os << txt << endl ;*/ }
    virtual void display( std::ostream &os ) ;
    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItemCode( this ) ;  }
    void addTabulation_String( int t,string& s ) ;

    virtual ~CommentItemCode() {} ;

    string reference ;
    std::vector<CommentItem*> items;
};

#endif



