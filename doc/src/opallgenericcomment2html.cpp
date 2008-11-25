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
#include "opallgenericcomment2html.h"
//#include "visitorcommentitem_setpath_html.h"
#include "listtarget.h"
#include "util2html.h"
#include "target.h"
#include "token.h"
#include "commentitemkeyword.h"
//struct CommentItemKeyword ;
#include "pagecomment.h"

// cette fonction génère toutes les pages web d'un objet/fonction générique ou hérité qui n'ont pas d'item generic_comment
void OpAllGenericComment2HTML :: generate_webPage_of_generic_object_without_generic_comment() {

    int i,n ;
    Target* pt;

    n = pproject->listTarget.listPrincipalName.size() ;
    for(i=0;i<n;i++) {
        pt = pproject->listTarget.list[pproject->listTarget.listPrincipalName[i]].pt;
        if (pt->of_type_without_generic_comment()) 
            generate_webPage_of_generic_object_without_generic_comment( pt ) ;
        else {
            //cerr << "problème avec le type générique = " << pt->name.principalName << endl ;
        }
    }
}


// cette fonction génère la page web d'un objet/fonction générique ou hérité qui n'a pas d'item generic_comment et dont le nom générique est principal_name
void OpAllGenericComment2HTML :: generate_webPage_of_generic_object_without_generic_comment( Target* pt) {

    string stmp ;
    string stmp2 ;
    string stmp3 ;
    string principal_name = pt->name.principalName ;
    int i,n,m,j,pos,end ;
    OpGetBrief_for_principalName op_get_brief_for_principalName( principal_name ) ;


    pproject->scan(op_get_brief_for_principalName) ;

    stmp = pt->reference() ;
    //cout << " -------------->>>>>>>>>>>  CommentItemTutorial->reference() " << stmp << endl ;
    ofstream pageWeb( stmp.c_str() ,ios::out);
    //VisitorCommentItem_toHTML vivi( &pageWeb, ptr_list_target ) ;
    stmp = french2HTML( principal_name ) ;

    generate_header(pt,pproject->tree["root"], pageWeb, principal_name ) ;


    pageWeb << "<p class=\"commentaire_generique\">" << std::endl ;

    pageWeb << "<div class=\"avertissement\">" << std::endl ;
    pageWeb << "<strong>" << std::endl ;
    pageWeb << "Cet objet n' a pas de description g&eacute;n&eacute;rale." << std::endl ;
    pageWeb << "<br> Pour cr&eacute;er une description g&eacute;n&eacute;rale, veuillez consulter la documentation." << std::endl ;
    pageWeb << "<br> " << std::endl ;
    pageWeb << "<strong>" << std::endl ;
    pageWeb << "</div>" << std::endl ;

    pageWeb << "</p>" << std::endl ;

    pageWeb << "<hr />" << std::endl ;
    pageWeb <<  "<h3> liste des diff&eacute;rentes sp&eacute;cialisations" << " </h3> " << std::endl ;
    pageWeb << "<div class=\"list_specialisation\">" << std::endl ;

    n = op_get_brief_for_principalName.list.size() ;
    if (n>0) {
        pageWeb << "<ul>" << std::endl ;
        for(i=0;i<n;i++) {
            stmp = op_get_brief_for_principalName.list[i]->pt->name.name ;
            end = stmp.size();
            if (!chercher_motif( stmp,"generic_comment_",&pos,end,0)) {
                stmp2 = linkHTML( pt->reference(), op_get_brief_for_principalName.list[i]->pt->reference(),stmp ) ;
                if (op_get_brief_for_principalName.list[i]->ptr_info == NULL)
                    pageWeb << "<li> " << stmp2 << " </li>" << std::endl ;
                else {
                    pageWeb << "<li> " << stmp2 << "(" ;
                    op_get_brief_for_principalName.list[i]->ptr_info->display_parameter_to_HTML(&pageWeb,&(pproject->listTarget),pt);
                    pageWeb << " ) </li>" << std::endl ;
                }
//                 pageWeb << "<li> " << stmp2 << " </li>" << std::endl ;
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
                    pageWeb << "pas de mot cl&eacute brief dans la documentation" << std::endl ;
                    //pageWeb << "<strong>" << std::endl ;
                    pageWeb << "</div>" << std::endl ;
                }
            }
        }
        pageWeb << "</ul>" << std::endl ;
    }
    pageWeb << "</div>" << std::endl ;

    pageWeb << "<hr />" << std::endl ;
    for(i=0;i<NB_FINAL_LINE;i++)
        pageWeb << "<br>" << std::endl ;
    pageWeb << "</body>" << std::endl ;
    pageWeb << "</html>" << std::endl ;
    pageWeb <<std::endl;
}



/*
 cette fonction a pour objet de créer la page web de chaque generic_comment qu'il proviennent d'un commentItem du type generic_comment ou
 qu'il soit créer au besoin dans le cas où il n'y ait pas de commentItem du type generic_comment ayant le nom principal de la structure ou de la fonction 
 générique ou dérivée... ouf! pas simple à expliquer.

*/
void OpAllGenericComment2HTML :: operator()( PageComment* page ) {

    // on génère les pages web des commentaitres generaux generic comment de ce PageComment.

    string stmp ;
    int i,k,n,N;
    VisitorCommentItem_GenericComment_toHTML g_toHTML( pproject ) ;


    N = page->listComment.size() ;
    for(k=0;k<N;k++) {
        n = page->listComment[k]->items.size() ;
        for(i=0;i<n;i++) {
            page->listComment[k]->items[i]->execute_function( &g_toHTML ) ;
            //if (g_toHTML.isGenericcomment)
            //    list_principalName_with_genericComment.push_back(g_toHTML.principal_name);
        }
    }

}













