#ifndef COMMENT_ITEM_EXAMPLE_H
#define COMMENT_ITEM_EXAMPLE_H

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

struct CommentItemExample : public CommentItem { 
    CommentItemExample( string& ref);
    virtual void print( std::ostream &os ) const { /*os << txt << endl;*/ }
    virtual void display( std::ostream &os );
    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItemExample( this );  }
    //void addTabulation_String( int t,string& s );
    virtual ~CommentItemExample();

    // méthode virtuelle de target
    virtual bool of_example() { return true; }

    std::vector<CommentItem*> items;
};

#endif



