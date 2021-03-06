#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "op.h"
#include "visitorcommentitem_listtarget.h"
#include "commentitemexample.h"
#include "commentitemtutorial.h"
#include "commentitemgenericcomment.h"
#include "commentitemwebpage.h"
#include "commentitemlatex.h"
#include "comment.h"
#include "listtarget.h"

void VisitorCommentItem_listTarget :: function_at_CommentItemWebPage( CommentItemWebPage* c ) {

    VisitorCommentItem_listTarget visi(ptr_list_target);
    int i,n;

    ptr_list_target->push_back( c,false ) ; // le premier false signifie le Target n'a pas d'dentifiant id.
    n = c->items.size();
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi ) ;

}

void VisitorCommentItem_listTarget :: function_at_CommentItemExample( CommentItemExample* c ) {

    VisitorCommentItem_listTarget visi(ptr_list_target);
    int i,n;

    ptr_list_target->push_back( c,true ) ;
    n = c->items.size();
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi ) ;
}

void VisitorCommentItem_listTarget :: function_at_CommentItemTutorial( CommentItemTutorial* c ) {

    VisitorCommentItem_listTarget visi(ptr_list_target);
    int i,n;

    ptr_list_target->push_back( c,true ) ;
    n = c->items.size();
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi ) ;
}

void VisitorCommentItem_listTarget :: function_at_CommentItemGenericComment( CommentItemGenericComment* c ) {

    VisitorCommentItem_listTarget visi(ptr_list_target);
    int i,n;

    ptr_list_target->push_back( c,true ) ;
    n = c->items.size();
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi ) ;
}

void VisitorCommentItem_listTarget :: function_at_CommentItemLaTex( CommentItemLaTex* c ) {

    ptr_list_target->push_back( c,true ) ;
}




