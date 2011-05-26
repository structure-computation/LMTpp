#ifndef COMMENT_ITEM_TUTORIAL_H
#define COMMENT_ITEM_TUTORIAL_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

//struct CommentItem ;
#include "commentitem.h"
#include "visitorcommentitem.h"
#include "target.h"

struct CommentItemTutorial : public CommentItem /*, public Target*/ { 
    CommentItemTutorial( string& ref) ;
    virtual void print( std::ostream &os ) const { /*os << txt << endl ;*/ }
    virtual void display( std::ostream &os ) ;
    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItemTutorial( this ) ;  }
    //void addTabulation_String( int t,string& s ) ;
    virtual ~CommentItemTutorial() ;

    /// méthode virtuelle de target
    virtual bool of_tutorial() { return true; }

    //string reference ;
    std::vector<CommentItem*> items;
};

#endif



