#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std ;

#include "documentation.h"
#include "opgetbrief_for_principalname.h"
#include "opgettype_for_principalname.h"
//#include "visitorcommentitem_is_extuge.h"
#include "visitorcommentitem_genericcomment_tohtml.h"
#include "opallgenericcomment.h"
//#include "visitorcommentitem_setpath_html.h"
#include "listtarget.h"
#include "util2html.h"
#include "target.h"
#include "token.h"
#include "commentitemkeyword.h"
//struct CommentItemKeyword ;
#include "pagecomment.h"

/*
 cette fonction a pour objet de créer la page web de chaque generic_comment qu'il proviennent d'un commentItem du type generic_comment ou
 qu'il soit créer au besoin dans le cas où il n'y ait pas de commentItem du type generic_comment ayant le nom principal de la structure ou de la fonction 
 générique ou dérivée... ouf! pas simple à expliquer.

*/
void OpAllGenericComment :: operator()( PageComment* page ) {

    // on génère les pages web des commentaitres generaux generic comment de ce PageComment.

    string stmp ;
    int i,k,n,N;
    VisitorCommentItem_GenericComment_toHTML g_toHTML( pproject ) ;


    N = page->listComment.size() ;
    for(k=0;k<N;k++) {
        n = page->listComment[k]->items.size() ;
        for(i=0;i<n;i++) {
            page->listComment[k]->items[i]->execute_function( &g_toHTML ) ;
            if (g_toHTML.isGenericcomment)
                list_principalName_with_genericComment.push_back(g_toHTML.principal_name);
        }
    }

}













