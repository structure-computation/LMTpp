#ifndef COMMENT_ITEM_VERBATIM_H
#define COMMENT_ITEM_VERBATIM_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

//struct CommentItem ;
#include "commentitem.h"
#include "visitorcommentitem.h"

struct CommentItemVerbatim : public CommentItem { 
    CommentItemVerbatim() {}
    virtual void print( std::ostream &os ) const { /*os << txt << endl ;*/ }
    virtual void display( std::ostream &os ) ;
    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItemVerbatim( this ) ;  }
    void addTabulation_String( int t,string& s ) ;

    virtual ~CommentItemVerbatim() {} ;

    vector<string> txt ;
    vector<int> tabulation ;
};

#endif



