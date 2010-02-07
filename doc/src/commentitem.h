#ifndef COMMENT_ITEM_H
#define COMMENT_ITEM_H

#include "visitorcommentitem.h"
#include "target.h"
//struct Target ;

struct CommentItem : public Target {
    CommentItem() {}
    virtual void display( std::ostream &os ) ;
    //friend std::ostream &operator<<( std::ostream &os, const CommentItem &c ) { return display( os,c ) ; } ;
    virtual void print( std::ostream &os ) const { } ;

    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItem( this ) ;  }
    virtual ~CommentItem() {} ;
} ;

inline std::ostream &operator<<( std::ostream &os, CommentItem &c ) { c.display( os ) ; return os ; } ;

#endif

