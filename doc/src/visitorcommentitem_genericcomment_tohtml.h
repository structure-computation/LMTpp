#ifndef VISITOR_COMMENT_ITEM_GENERIC_COMMENT_TO_HTML_H
#define VISITOR_COMMENT_ITEM_GENERIC_COMMENT_TO_HTML_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<map>
#include<string>

using namespace std ;

//struct CommentItem ;
//struct LangRef ;

#include "visitorcommentitem.h"
//#include "visitorbloc_namebaseclass.h"
//struct VisitorCommentItem ;
struct CommentItem ;
struct CommentItemCode ;
struct CommentItemKeyword ;
struct CommentItemList ;
struct CommentItemSection ;
struct CommentItemTable ;
struct CommentItemTxt ;
struct CommentItemWebPage ;
struct CommentItemGenericComment ;
struct CommentItemTutorial ;
struct CommentItemExample ;
struct CommentItemLaTex ;
struct CommentItemVerbatim ;
struct ListTarget ;
struct Documentation ;
template<class COMMENT_ITEM> struct ListTargetCommentItem ;

/*
cette classe va générer un flux au format HTML  des items
    * GenericComment

*/

struct VisitorCommentItem_GenericComment_toHTML : public VisitorCommentItem  {
    VisitorCommentItem_GenericComment_toHTML( Documentation* pp ) { pproject = pp ; }
    virtual ~VisitorCommentItem_GenericComment_toHTML() {}
    virtual void function_at_CommentItem( CommentItem* c ) { }
    virtual void function_at_CommentItemCode( CommentItemCode* c ) {  }
    virtual void function_at_CommentItemKeyword( CommentItemKeyword* c ) {  }
    virtual void function_at_CommentItemList( CommentItemList* c ) {  }
    virtual void function_at_CommentItemSection( CommentItemSection* c ) {  }
    virtual void function_at_CommentItemTable( CommentItemTable* c ) {  }
    virtual void function_at_CommentItemTxt( CommentItemTxt* c ) {  }
    virtual void function_at_CommentItemWebPage( CommentItemWebPage* c ) { }
    virtual void function_at_CommentItemGenericComment( CommentItemGenericComment* c ) ;
    virtual void function_at_CommentItemExample( CommentItemExample* c ) {  }
    virtual void function_at_CommentItemTutorial( CommentItemTutorial* c ) {  }
    virtual void function_at_CommentItemLaTex( CommentItemLaTex* c ) {  }
    virtual void function_at_CommentItemVerbatim( CommentItemVerbatim* c ) { }
    //void apply_on_related_to( const std::string &s, Op *op ) ;
    //friend std::ostream &operator<<( std::ostream &os, const Comment &c ) ;

    //ListTargetCommentItem<CommentItemKeyword>* ptr_ListTargetCommentItem ;
    Documentation* pproject ;
    //bool isGenericcomment ;
    //string principal_name ;
} ;


#endif

