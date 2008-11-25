#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>

#include<cmath>
#include"time.h"


using namespace std ;


#include "visitorcommentitem.h"
#include "visitorcommentitem_tutorial_tohtml.h"
#include "visitorcommentitem_tohtml.h"
#include "commentitemkeyword.h"
#include "commentitemtxt.h"
#include "commentitemtable.h"
#include "commentitemsection.h"
#include "commentitemcode.h"
#include "commentitemlist.h"
#include "commentitemwebpage.h"
#include "commentitemgenericcomment.h"
#include "commentitemtutorial.h"
#include "commentitemtutorial.h"
#include "commentitem.h"
#include "listtarget.h"
#include "comment.h"
#include "util2html.h"



void VisitorCommentItem_tutorial_toHTML :: function_at_CommentItemTutorial( CommentItemTutorial* c ) {


    //VisitorCommentItem_toHTML vivi( web,ptr_list_target ) ;
    string stmp ;
    int i,n ;


    stmp = c->reference() ;
    //cout << " -------------->>>>>>>>>>>  CommentItemTutorial->reference() " << stmp << endl ;
    ofstream pageWeb( stmp.c_str() ,ios::out);
    VisitorCommentItem_toHTML vivi( &pageWeb, ptr_list_target,c ) ;
    stmp = "tutorial " + french2HTML( c->name.name ) ;

    generate_header(c,(*ptr_tree)["root"],pageWeb, stmp ) ;


    pageWeb << "<p class=\"tutorial\">" << std::endl ;
    n = c->items.size() ;
    for(i=0;i<n;i++) {
        c->items[i]->execute_function( &vivi ) ;
    }
    pageWeb << "</p>" << std::endl ;
    // remarque : comme j'utilise un objet VisitorCommentItem_toHTML les éventuels tutoriaux,exemples contenu dans CommentItemTutorial *c ne seront pas affichés.

    pageWeb << "<p class=\"reference_fichier_source\">" << std::endl ;
    pageWeb << linkHTML( c->reference(),c->source_file,c->source_file ) ;
    pageWeb << "</p>" << std::endl ;

    pageWeb << "<hr />" << std::endl ;
    for(i=0;i<NB_FINAL_LINE;i++)
        pageWeb << "<br>" << std::endl ;
    pageWeb << "</body>" << std::endl ;
    pageWeb << "</html>" << std::endl ;
    pageWeb <<std::endl;
}









