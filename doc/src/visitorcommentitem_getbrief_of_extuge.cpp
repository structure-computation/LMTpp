#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "op.h"
#include "visitorcommentitem_getbrief_of_extuge.h"
#include "commentitemexample.h"
#include "commentitemtutorial.h"
#include "commentitemgenericcomment.h"
#include "comment.h"
#include "visitorcommentitem_getbrief.h"

void VisitorCommentItem_getBrief_of_ExTuGe :: clear() {

    list_commentItemKeyword.clear() ;
}

void VisitorCommentItem_getBrief_of_ExTuGe :: function_at_CommentItemExample( CommentItemExample* c ) {

    int i,n ;
    VisitorCommentItem_getBrief visi ;

    n = c->items.size() ;
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi ) ;

    list_commentItemKeyword = visi.list_commentItemKeyword ;

}

void VisitorCommentItem_getBrief_of_ExTuGe :: function_at_CommentItemTutorial( CommentItemTutorial* c ) {

    int i,n ;
    VisitorCommentItem_getBrief visi ;

    n = c->items.size() ;
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi ) ;

    list_commentItemKeyword = visi.list_commentItemKeyword ;
}

void VisitorCommentItem_getBrief_of_ExTuGe :: function_at_CommentItemGenericComment( CommentItemGenericComment* c ) {

    int i,n ;
    VisitorCommentItem_getBrief visi ;

    n = c->items.size() ;
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi ) ;

    list_commentItemKeyword = visi.list_commentItemKeyword ;
}






