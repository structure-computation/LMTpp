#ifndef COMMENT_ITEM_SECTION_H
#define COMMENT_ITEM_SECTION_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

//struct CommentItem ;
#include "commentitem.h"
#include "visitorcommentitem.h"

struct CommentItemSection : public CommentItem { 
    CommentItemSection(string& t, int d) ;
    virtual void print( std::ostream &os ) const { /*os << txt << endl ;*/ }
    virtual void display( std::ostream &os ) ;
    //virtual void apply_on_related_to( const std::string &s, Op *op ) { op->apply( txt ); } ;
    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItemSection( this ) ;  }
    virtual ~CommentItemSection() {} ;

    //std::string name ;
    int order ;
    string titre ;
};

#endif



