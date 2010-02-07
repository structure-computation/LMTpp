#ifndef VISITOR_COMMENT_ITEM_IS_GE_H
#define VISITOR_COMMENT_ITEM_IS_GE_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

//using namespace std ;

//struct CommentItem ;
//struct LangRef ;

#include "visitorcommentitem.h"

struct CommentItem ;
struct CommentItemCode ;
struct CommentItemKeyword ;
struct CommentItemList ;
struct CommentItemSection ;
struct CommentItemTable ;
struct CommentItemTxt ;
struct CommentItemWebPage ;
struct CommentItemTutorial ;
struct CommentItemExample ;
struct CommentItemLaTex ;
struct CommentItemVerbatim ;

/// cette classe permet de savoir si un commentaire est du type generic_comment.

struct VisitorCommentItem_isGe : public VisitorCommentItem  {
    VisitorCommentItem_isGe( ) { ge = false ; }
    virtual ~VisitorCommentItem_isGe() {}
    virtual void function_at_CommentItem( CommentItem* c ) { ge = false ; }
    virtual void function_at_CommentItemCode( CommentItemCode* c ) { ge = false ; }
    virtual void function_at_CommentItemKeyword( CommentItemKeyword* c ) { ge = false ; }
    virtual void function_at_CommentItemList( CommentItemList* c ) { ge = false ; }
    virtual void function_at_CommentItemSection( CommentItemSection* c ) { ge = false ; }
    virtual void function_at_CommentItemTable( CommentItemTable* c ) { ge = false ; }
    virtual void function_at_CommentItemTxt( CommentItemTxt* c ) { ge = false ; }
    virtual void function_at_CommentItemWebPage( CommentItemWebPage* c ) { ge = false ; }
    virtual void function_at_CommentItemGenericComment( CommentItemGenericComment* c ) { ge = true ; }
    virtual void function_at_CommentItemExample( CommentItemExample* c ) { ge = false ; }
    virtual void function_at_CommentItemTutorial( CommentItemTutorial* c ) { ge = false ; }
    virtual void function_at_CommentItemLaTex( CommentItemLaTex* c ) { ge = false ; }
    virtual void function_at_CommentItemVerbatim( CommentItemVerbatim* c ) { ge = false ; }
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;
    //void reset() { ge = false ; }

    bool ge ;
} ;


#endif

