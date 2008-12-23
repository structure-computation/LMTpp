#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include<cstdlib>

#include<cmath>
#include"time.h"


using namespace std ;

#include "documentation.h"
#include "opgetbrief_for_principalname.h"
#include "opgettype_for_principalname.h"

#include "visitorcommentitem.h"
#include "visitorcommentitem_genericcomment_tohtml.h"
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
#include "listparameter.h"
#include "comment.h"
#include "util2html.h"
#include "token.h"
#include "listtargetcommentitem.h"

void VisitorCommentItem_GenericComment_toHTML :: function_at_CommentItemGenericComment( CommentItemGenericComment* c ) {

    string stmp ;
    string stmp2 ;
    int i,n,pos,end,m,j ;
    OpGetBrief_for_principalName op_get_brief_for_principalName( c->name.principalName ) ;
    //OpGetType_for_principalName op_get_type_for_principalName( c->name.principalName ) ;


    //principal_name = c->name.principalName ;
    pproject->scan(op_get_brief_for_principalName) ;
    //pproject->scan(op_get_type_for_principalName) ;
    //c->name.name = op_get_type_for_principalName.type + "_" + c->name.name ;
    stmp = c->reference() ;
    //cout << " -------------->>>>>>>>>>>  CommentItemTutorial->reference() " << stmp << endl ;
    ofstream pageWeb( stmp.c_str() ,ios::out);
    VisitorCommentItem_toHTML vivi( &pageWeb, &pproject->listTarget,c ) ;
    stmp = french2HTML( c->name.principalName ) ;

    //generate_header(c,(*ptr_tree)["root"], pageWeb, stmp ) ;
    generate_header(c,pproject->tree["root"], pageWeb, stmp ) ;

    pageWeb << "<p class=\"commentaire_generique\">" << std::endl ;
    n = c->items.size() ;
    for(i=0;i<n;i++) {
        c->items[i]->execute_function( &vivi ) ;
    }
    pageWeb << "</p>" << std::endl ;

    pageWeb << "<hr />" << std::endl ;
    pageWeb <<  "<h3> liste des diff&eacute;rentes sp&eacute;cialisations" << " </h3> " << std::endl ;
    pageWeb << "<div class=\"list_specialisation\">" << std::endl ;
    n = op_get_brief_for_principalName.list.size() ;
    if (n>0) {
        pageWeb << "<ul>" << std::endl ;
        for(i=0;i<n;i++) {
            stmp = op_get_brief_for_principalName.list[i]->pt->name.name ;
            if (!chercher_motif( stmp,"generic_comment_",&pos,end,0)) {
                stmp2 = linkHTML( c->reference(), op_get_brief_for_principalName.list[i]->pt->reference(),stmp ) ;
                if (op_get_brief_for_principalName.list[i]->ptr_info == NULL)
                    pageWeb << "<li> " << stmp2 << " </li>" << std::endl ;
                else {
                    pageWeb << "<li> " << stmp2 << "(" ;
                    op_get_brief_for_principalName.list[i]->ptr_info->display_parameter_to_HTML(&pageWeb,&(pproject->listTarget),c);
                    pageWeb << " ) </li>" << std::endl ;
                }
                m = op_get_brief_for_principalName.list[i]->listCommentItem.size() ;
                if (m>0) {
                    pageWeb << "<ul>" << std::endl ;
                    for(j=0;j<m;j++) {
                        pageWeb << "<li> " << op_get_brief_for_principalName.list[i]->listCommentItem[j]->parametres << " </li>" << std::endl ;
                    }
                pageWeb << "</ul>" << std::endl ;
                }
                else {
                    pageWeb << "<div class=\"avertissement\">" << std::endl ;
                    //pageWeb << "<strong>" << std::endl ;
                    //pageWeb << "pas de mot cl&eacute; brief dans la documentation" << std::endl ;
                    //pageWeb << "<strong>" << std::endl ;
                    pageWeb << "</div>" << std::endl ;
                }
            }
        }
        pageWeb << "</ul>" << std::endl ;
    }
    pageWeb << "</div>" << std::endl ;

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









