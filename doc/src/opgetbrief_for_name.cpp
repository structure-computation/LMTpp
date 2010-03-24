#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std ;

//#include "visitorcommentitem_is_extuge.h"

#include "pagecomment.h"
#include "opgetbrief_for_name.h"
#include "listtargetcommentitem.h"
#include "visitorcommentitem_getbrief.h"
#include "visitorcommentitem_getbrief_of_extuge.h"
#include "visitorcommentitem_is_extuge.h"
//#include "visitorcommentitem_setpath_html.h"
#include "listtargetcommentitem.h"
#include "util2html.h"
#include "target.h"
#include "token.h"


/*
 cette fonction a pour objet de créer une "liste" des objets ayant le nom principal principal_name avec leurs briefs,
 un objet étant soit une classe, soit une structure, soit une fonction, soit un exemple, un tutorial ou un generic_comment.
*/

OpGetBrief_for_Name :: ~OpGetBrief_for_Name() {

}

void OpGetBrief_for_Name :: operator()( PageComment* page ) {

    VisitorCommentItem_getBrief getbrief ;
    VisitorCommentItem_getBrief_of_ExTuGe getbrief_of_extuge ;
    VisitorCommentItem_isExTuGe is_estuge ;
    int i,n,j,m,N,k ;
    Target_CommentItem<CommentItemKeyword,void>* ptci ;



    // on parcourt le bloc de la page page à la recherche d'objet ayant le nom name et on récupère ses briefs.
    n = page->code.list_subType_function.size() ;
    for(i=0;i<n;i++) {
        if (page->code.list_subType_function[i]->name.name == name ) {
            m = page->code.list_subType_function[i]->listTag.size() ;
            getbrief.clear() ;
            for(j=0;j<m;j++) {
                N = page->code.list_subType_function[i]->listTag[j]->items.size() ;
                for(k=0;k<N;k++) {
                     page->code.list_subType_function[i]->listTag[j]->items[k]->execute_function( &getbrief ) ;
                }
            }
            ptci = new Target_CommentItem<CommentItemKeyword,void>() ;
            ptci->pt = page->code.list_subType_function[i] ;
            ptci->listCommentItem = getbrief.list_commentItemKeyword ;
            list.target_items.push_back( ptci ) ;
        }
    }
    // ensuite on parcourt les exemples, tutoriaux mais surtout PAS les generic_comment.

    n = page->listComment.size() ;
    for(i=0;i<n;i++) {
        m = page->listComment[i]->items.size() ;
        for(j=0;j<m;j++) {
            page->listComment[i]->items[j]->execute_function( &is_estuge ) ;
            //cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAh" << is_estuge.extuge << endl ; 
            if ((is_estuge.extuge >= 0) && (is_estuge.extuge < 2)  && (page->listComment[i]->items[j]->name.name == name)) {
                // c'est donc un item du type exemple, tutoriel
                getbrief_of_extuge.clear() ;
                page->listComment[i]->items[j]->execute_function( &getbrief_of_extuge ) ;
                ptci = new Target_CommentItem<CommentItemKeyword,void>() ;
                ptci->pt = page->listComment[i]->items[j] ;
                ptci->listCommentItem = getbrief_of_extuge.list_commentItemKeyword ;
                list.target_items.push_back( ptci ) ;
            }
        }
    }

}













