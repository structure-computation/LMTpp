#ifndef VISITOR_COMMENT_ITEM_GET_BRIEF_OF_EXTUGE_H
#define VISITOR_COMMENT_ITEM_GET_BRIEF_OF_EXTUGE_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

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

/*
Cette classe a pour objectif de récupérer tous les briefs d'un exemple, ou d'un tutorial ou encore d'un generic_coment.

*/

struct VisitorCommentItem_getBrief_of_ExTuGe : public VisitorCommentItem  {
    VisitorCommentItem_getBrief_of_ExTuGe ( ) { }
    virtual ~VisitorCommentItem_getBrief_of_ExTuGe () {}
    virtual void function_at_CommentItem( CommentItem* c ) { }
    virtual void function_at_CommentItemCode( CommentItemCode* c ) { }
    virtual void function_at_CommentItemKeyword( CommentItemKeyword* c ) {}
    virtual void function_at_CommentItemList( CommentItemList* c ) {}
    virtual void function_at_CommentItemSection( CommentItemSection* c ) {}
    virtual void function_at_CommentItemTable( CommentItemTable* c ) {}
    virtual void function_at_CommentItemTxt( CommentItemTxt* c ) {}
    virtual void function_at_CommentItemWebPage( CommentItemWebPage* c ) {}
    virtual void function_at_CommentItemGenericComment( CommentItemGenericComment* c ) ;
    virtual void function_at_CommentItemExample( CommentItemExample* c ) ;
    virtual void function_at_CommentItemTutorial( CommentItemTutorial* c ) ;
    virtual void function_at_CommentItemLaTex( CommentItemLaTex* c ) {}
    virtual void function_at_CommentItemVerbatim( CommentItemVerbatim* c ) {}
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;
    void clear() ;

    vector<CommentItemKeyword* > list_commentItemKeyword ;
} ;


#endif

