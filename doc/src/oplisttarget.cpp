#include <iostream>
#include <string>
#include <vector>


using namespace std ;

#include "pagecomment.h"
#include "oplisttarget.h"
#include "listtarget.h"


// cette fonction a pour objet de générer une page web à partir de la page "page" dans un futur proche
void OpListTarget :: operator()( PageComment* page ) {

    int i,n ;

    // on définit la liste des éléments pointables : cad les éléments qui héritent de la classe Target.
    n = page->code.list_subType_function.size() ;
    for(i=0;i<n;i++)
        ptr_list_target->push_back( page->code.list_subType_function[i],true,false ) ;
    n= page->listComment.size() ;
    for(i=0;i<n;i++) {
        page->listComment[i]->add_tutorial_example_genericComment_webpage_image( ptr_list_target ) ;
    }
}













