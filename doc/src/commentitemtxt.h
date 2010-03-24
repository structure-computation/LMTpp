#ifndef COMMENT_ITEM_TXT_H
#define COMMENT_ITEM_TXT_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

//struct CommentItem ;
#include "commentitem.h"
#include "visitorcommentitem.h"

struct CommentItemTxt : public CommentItem { 
    CommentItemTxt() ;
    virtual void print( std::ostream &os ) const { /*os << txt << endl ;*/ }
    virtual void display( std::ostream &os ) ;
    //virtual void apply_on_related_to( const std::string &s, Op *op ) { op->apply( txt ); } ;
    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItemTxt( this ) ;  }
    void addString( string& s ) ;
    virtual ~CommentItemTxt() {} ;
    //std::string name ;
    vector<string> txt ;
};

#endif



