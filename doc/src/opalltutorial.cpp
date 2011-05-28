#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>


using namespace std ;

//#include "visitorcommentitem_is_extuge.h"
#include "visitorcommentitem_tutorial_tohtml.h"
#include "pagecomment.h"
#include "opalltutorial.h"
//#include "visitorcommentitem_setpath_html.h"
#include "listtarget.h"
#include "util2html.h"

// cette fonction a pour objet de déterminer la page de chaque tutorial
void OpAllTutorial :: operator()( PageComment* page ) {

    // on génère les pages web des exemples de ce PageComment.
    int i,k,n,N ;
    //VisitorCommentItem_isExTuGe is_extuge ;
    VisitorCommentItem_tutorial_toHTML tutorial_toHTML( ptr_list_target,ptr_tree ) ;

    N = page->listComment.size() ;
    for(k=0;k<N;k++) {
        n = page->listComment[k]->items.size() ;
        for(i=0;i<n;i++)
            page->listComment[k]->items[i]->execute_function( &tutorial_toHTML ) ;
    }
}













