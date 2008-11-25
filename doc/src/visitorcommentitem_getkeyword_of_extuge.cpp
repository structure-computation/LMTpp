#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "op.h"
#include "visitorcommentitem_getkeyword_of_extuge.h"
#include "commentitemkeyword.h"
#include "commentitemexample.h"
#include "commentitemtutorial.h"
#include "commentitemgenericcomment.h"
#include "comment.h"


void VisitorCommentItem_getKeyword_of_ExTuGe :: function_at_CommentItemKeyword( CommentItemKeyword* c ) {

    //cerr << " io " << endl ;
    if (c->name.name == "keyword") {
        listNameKeyword.push_back(c->parametres) ;
    }
}

void VisitorCommentItem_getKeyword_of_ExTuGe :: function_at_CommentItemExample( CommentItemExample* c ) {

    int i,n ;
    VisitorCommentItem_getKeyword_of_ExTuGe visi ;

    isExtuge = 1 ;
    n = c->items.size() ;
    visi.init() ;
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi ) ;

    listNameKeyword = visi.listNameKeyword ;
}

void VisitorCommentItem_getKeyword_of_ExTuGe :: function_at_CommentItemTutorial( CommentItemTutorial* c ) {

    int i,n ;
    VisitorCommentItem_getKeyword_of_ExTuGe visi ;

    isExtuge = 2 ;
    n = c->items.size() ;
    visi.init() ;
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi ) ;
    listNameKeyword = visi.listNameKeyword ;
}

void VisitorCommentItem_getKeyword_of_ExTuGe :: function_at_CommentItemGenericComment( CommentItemGenericComment* c ) {

    int i,n ;
    VisitorCommentItem_getKeyword_of_ExTuGe visi ;

    isExtuge = 3 ;
    n = c->items.size() ;
    visi.init() ;
    for(i=0;i<n;i++)
        c->items[i]->execute_function( &visi ) ;
    listNameKeyword = visi.listNameKeyword ;
}






