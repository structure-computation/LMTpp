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
#include "opget_listkeyword.h"

#include "visitorcommentitem_is_extuge.h"
//#include "visitorbloc_what_type.h"
#include "visitorcommentitem_getkeyword_of_extuge.h"
#include "visitorbloc_get_listkeyword.h"
#include "listtargetbytype.h"

#include "util2html.h"
#include "target.h"
#include "token.h"

OpGet_listKeyword :: ~OpGet_listKeyword() {
/*
    int i,n ;

    n = list_keyword.size() ;
    for(i=0;i<n;i++)
        delete list_keyword[i] ;
*/
}

void OpGet_listKeyword :: operator()( PageComment* page ) {

    VisitorCommentItem_getKeyword_of_ExTuGe visi ;
    VisitorBloc_getListKeyword viso ;
    int i,n,j,m,t,S ;

    //  on parcourt tous les commentaires à la recherche de keyword dans les exemples, les tutoriels et les commentaires génériques

    n = page->listComment.size() ;
    for(i=0;i<n;i++) {
        m = page->listComment[i]->items.size() ;
        for(j=0;j<m;j++) {
            visi.init() ;
            page->listComment[i]->items[j]->execute_function( &visi ) ;

            if (visi.isExtuge >0) {
                S = visi.listNameKeyword.size() ;
                for(t=0;t<S;t++) {
                    switch(visi.isExtuge) {
                            case 1 : // exemple
                                    list_keyword[visi.listNameKeyword[t]].list_example.push_back( page->listComment[i]->items[j] ) ;
                                    break ;
                            case 2 : // tutoriel
                                    list_keyword[visi.listNameKeyword[t]].list_tutorial.push_back( page->listComment[i]->items[j] ) ;
                                    break ;
                            case 3 : // commentaire générique
                                    ///list_keyword[visi.listNameKeyword[t]].list_generic_comment.push_back( page->listComment[i]->items[j] ) ;
                                    if (page->listComment[i]->items[j]->ancestor != NULL) {
                                        if (page->listComment[i]->items[j]->ancestor->of_class_or_struct())
                                            list_keyword[visi.listNameKeyword[t]].list_class_struct.push_back( page->listComment[i]->items[j] ) ;
                                        if (page->listComment[i]->items[j]->ancestor->of_function())
                                            list_keyword[visi.listNameKeyword[t]].list_function.push_back( page->listComment[i]->items[j] ) ;
                                        if (page->listComment[i]->items[j]->ancestor->of_example())
                                            list_keyword[visi.listNameKeyword[t]].list_example.push_back( page->listComment[i]->items[j] ) ;
                                        if (page->listComment[i]->items[j]->ancestor->of_tutorial())
                                            list_keyword[visi.listNameKeyword[t]].list_tutorial.push_back( page->listComment[i]->items[j] ) ;
                                    } else {
                                        cerr << "<><><><><> ATTENTION : ancestor == NULL !" << endl ;
                                        cerr << *(page->listComment[i]->items[j]) << endl ;
                                        cerr << "<><><><><>" << endl ;
                                    }
                                    break ;
                    }
                }
            }
        }
    }


    // Ensuite on cherche les mot-clés dans les commentaires de classes, et de fonctions en excluant les commentaires génériques.
    n = page->code.list_subType_function.size() ;
    for(i=0;i<n;i++) {
        viso.init() ;
        page->code.list_subType_function[i]->execute_function( &viso ) ;
        
        m = viso.listkeyword_of_class_struct.size() ;
        for(j=0;j<m;j++) {
            list_keyword[viso.listkeyword_of_class_struct[j]].list_class_struct.push_back( page->code.list_subType_function[i] ) ;
        }
        m = viso.listkeyword_of_function.size() ;
        for(j=0;j<m;j++) {
            list_keyword[viso.listkeyword_of_function[j]].list_function.push_back( page->code.list_subType_function[i] ) ;
        }
    }

}













