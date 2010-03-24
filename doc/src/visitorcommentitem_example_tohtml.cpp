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
#include "visitorcommentitem_example_tohtml.h"
#include "visitorcommentitem_tohtml.h"
#include "commentitemkeyword.h"
#include "commentitemtxt.h"
#include "commentitemtable.h"
#include "commentitemsection.h"
#include "commentitemcode.h"
#include "commentitemlist.h"
#include "commentitemwebpage.h"
#include "commentitemgenericcomment.h"
#include "commentitemexample.h"
#include "commentitemtutorial.h"
#include "commentitem.h"
#include "listtarget.h"
#include "comment.h"
#include "util2html.h"



void VisitorCommentItem_example_toHTML :: function_at_CommentItemExample( CommentItemExample* c ) {

    string stmp ;
    int i,n ;


    stmp = c->reference() ;
    ofstream pageWeb( stmp.c_str() ,ios::out);
    VisitorCommentItem_toHTML vivi( &pageWeb, ptr_list_target,c ) ;
    stmp = "example " + french2HTML( c->name.name ) ;

    generate_header( c,(*ptr_tree)["root"],pageWeb, stmp ) ;


    pageWeb << "<p class=\"example\">" << std::endl ;
    n = c->items.size() ;
    for(i=0;i<n;i++) {
        c->items[i]->execute_function( &vivi ) ;
    }
    pageWeb << "</p>" << std::endl ;
    // remarque : comme j'utilise un objet VisitorCommentItem_toHTML les éventuels exemples contenu dans l'exemple *c ne seront pas affichés.

    pageWeb << "<p class=\"reference_fichier_source\">" << std::endl ;
    pageWeb << linkHTML( c->reference(),c->source_file,c->source_file ) ;
    pageWeb << "</p>" << std::endl ;
    feetPage(pageWeb);
}









