#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std ;

#include "pagecomment.h"
#include "opstructure_site.h"
#include "visitorbloc_setpath_html.h"
#include "visitorcommentitem_setpath_html.h"
                 
/// pour parcourir, manipuler les fichiers avec Boost
#include "boost/filesystem.hpp"    // includes all needed Boost.Filesystem declarations
using namespace boost::filesystem; //  a namespace alias is preferred practice in real code

void OpStructure_site :: initialize() {

    (*ptr_tree)["root"] = "doc/html/" ;
    (*ptr_tree)["function"] = (*ptr_tree)["root"] + "function/" ;
    (*ptr_tree)["structure"] = (*ptr_tree)["root"] + "structure/" ;
    (*ptr_tree)["example"] = (*ptr_tree)["root"] + "example/" ;
    (*ptr_tree)["tutorial"] = (*ptr_tree)["root"] + "tutorial/" ;
    (*ptr_tree)["generic_comment"] = (*ptr_tree)["root"] + "generic_comment/" ;
    (*ptr_tree)["image"] = (*ptr_tree)["root"] + "image/" ;
    (*ptr_tree)["keyword"] = (*ptr_tree)["root"] + "keyword/" ;
    /// on crée ici le repertoire html, html/function/ html/structure/ html/example/ et html/tutorial html/image/ par exemple
//     create_directory( "doc" ); /// inutile à priori
    remove_all( (*ptr_tree)["root"] );
    create_directory( (*ptr_tree)["root"] );
    create_directory( (*ptr_tree)["function"] );
    create_directory( (*ptr_tree)["structure"] );
    create_directory( (*ptr_tree)["example"] );
    create_directory( (*ptr_tree)["tutorial"] );
    create_directory( (*ptr_tree)["generic_comment"] );
    create_directory( (*ptr_tree)["image"] );
    create_directory( (*ptr_tree)["keyword"] );
    /// code Linux
//     if (mkdir("doc",S_IRWXU | S_IRWXG | S_IRWXO ) == -1 )
//         cerr << "doc" <<" existe déjà"<< endl ;
//     if (mkdir((*ptr_tree)["root"].c_str(),S_IRWXU | S_IRWXG | S_IRWXO ) == -1 )
//         cerr << (*ptr_tree)["root"] <<" existe déjà"<< endl ;
//     if (mkdir((*ptr_tree)["function"].c_str(),S_IRWXU | S_IRWXG | S_IRWXO ) == -1 )
//         cerr << (*ptr_tree)["function"] <<" existe déjà"<< endl ;
//     if (mkdir((*ptr_tree)["structure"].c_str(),S_IRWXU | S_IRWXG | S_IRWXO ) == -1 )
//         cerr << (*ptr_tree)["structure"] <<" existe déjà"<< endl ;
//     if (mkdir((*ptr_tree)["example"].c_str(),S_IRWXU | S_IRWXG | S_IRWXO ) == -1 )
//         cerr << (*ptr_tree)["example"] << " existe déjà"<< endl ;
//     if (mkdir((*ptr_tree)["tutorial"].c_str(),S_IRWXU | S_IRWXG | S_IRWXO ) == -1 )
//         cerr << (*ptr_tree)["tutorial"] << " existe déjà"<< endl ;
//     if (mkdir((*ptr_tree)["generic_comment"].c_str(),S_IRWXU | S_IRWXG | S_IRWXO ) == -1 )
//         cerr << (*ptr_tree)["generic_comment"] << " existe déjà"<< endl ;
//     if (mkdir((*ptr_tree)["image"].c_str(),S_IRWXU | S_IRWXG | S_IRWXO ) == -1 )
//         cerr << (*ptr_tree)["image"] << " existe déjà"<< endl ;
//     if (mkdir((*ptr_tree)["keyword"].c_str(),S_IRWXU | S_IRWXG | S_IRWXO ) == -1 )
//         cerr << (*ptr_tree)["keyword"] << " existe déjà"<< endl ;
    /// on génère ici le patron d'en tête pour toutes les pages web.
#warning à faire ici le patron d'en tête pour toutes les pages web.
}

// cette fonction a pour objet de générer une page web à partir de la page "page" dans un futur proche
void OpStructure_site :: operator()( PageComment* page ) {

    VisitorBloc_SetPath_HTML visi ;
    VisitorCommentItem_setPath_HTML visor ;
    int i,N,n,k ;



    // ensuite on donne les chemins des pages web des classes, structs et fonctions...
    visi.setRepertory_function( (*ptr_tree)["function"] ) ;
    visi.setRepertory_class( (*ptr_tree)["structure"] ) ;
    visi.setRepertory_struct( (*ptr_tree)["structure"] ) ;
    // on détermine le chemin des différents bloc|target sachant qu'un bloc est en fait soit une classe, soit une struc soit une fonction.
    n = page->code.list_subType_function.size() ;
    for(i=0;i<n;i++)
        page->code.list_subType_function[i]->exec( &visi ) ;

    // ... puis des exemples, tutorials et "commentaires génériques"
    visor.setRepertory_example( (*ptr_tree)["example"] ) ;
    visor.setRepertory_genericComment( (*ptr_tree)["generic_comment"] ) ;
    visor.setRepertory_tutorial( (*ptr_tree)["tutorial"] ) ;
    visor.setRepertory_webpage( (*ptr_tree)["root"] ) ;
    visor.setRepertory_image( (*ptr_tree)["image"] ) ;
    N = page->listComment.size() ;
    for(k=0;k<N;k++) {
        n = page->listComment[k]->items.size() ;
        for(i=0;i<n;i++)
            page->listComment[k]->items[i]->execute_function( &visor ) ;
    }
}













