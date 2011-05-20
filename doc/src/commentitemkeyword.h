#ifndef COMMENT_ITEM_KEYWORD_H
#define COMMENT_ITEM_KEYWORD_H

//struct CommentItem;
#include "commentitem.h"
#include "visitorcommentitem.h"

struct CommentItemKeyword : public CommentItem { 
    CommentItemKeyword( const char* s ) { name.name = s; name.principalName = s; }
    virtual void print( std::ostream &os ) const { os << " name =" << name.name  << " :  " << parametres << endl; }
    virtual void display( std::ostream &os );
    void addParameter( string& s );
    //virtual void apply_on_related_to( const std::string &s, Op *op ) { op->apply( parametres ); };
    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItemKeyword( this );  }
    virtual ~CommentItemKeyword() {};

    //string name;
    string parametres;
};


#endif


