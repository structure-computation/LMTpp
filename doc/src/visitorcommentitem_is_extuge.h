#ifndef VISITOR_COMMENT_ITEM_IS_EXTUGE_H
#define VISITOR_COMMENT_ITEM_IS_EXTUGE_H

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

struct VisitorCommentItem_isExTuGe : public VisitorCommentItem  {
    VisitorCommentItem_isExTuGe( ) { extuge = -1 ; }
    virtual ~VisitorCommentItem_isExTuGe() {}
    virtual void function_at_CommentItem( CommentItem* c ) { extuge = -1 ; }
    virtual void function_at_CommentItemCode( CommentItemCode* c ) { extuge = -1 ; }
    virtual void function_at_CommentItemKeyword( CommentItemKeyword* c ) { extuge = -1 ; }
    virtual void function_at_CommentItemList( CommentItemList* c ) { extuge = -1 ; }
    virtual void function_at_CommentItemSection( CommentItemSection* c ) { extuge = -1 ; }
    virtual void function_at_CommentItemTable( CommentItemTable* c ) { extuge = -1 ; }
    virtual void function_at_CommentItemTxt( CommentItemTxt* c ) { extuge = -1 ; }
    virtual void function_at_CommentItemWebPage( CommentItemWebPage* c ) { extuge = -1 ; }
    virtual void function_at_CommentItemGenericComment( CommentItemGenericComment* c ) { extuge = 2 ; }
    virtual void function_at_CommentItemExample( CommentItemExample* c ) { extuge = 0 ; }
    virtual void function_at_CommentItemTutorial( CommentItemTutorial* c ) { extuge = 1 ; }
    virtual void function_at_CommentItemLaTex( CommentItemLaTex* c ) { extuge = -1 ; }
    virtual void function_at_CommentItemVerbatim( CommentItemVerbatim* c ) { extuge = -1 ; }
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;

    void initialize( int i ) { extuge = i ; } 
    void reset() { extuge = -1 ; }

    int extuge ;
} ;


#endif

