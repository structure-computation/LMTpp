#include<iostream>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<cmath>
#include"string.h"
#include"time.h"
#include<vector>
using namespace std;

#include "opdisplay.h"
#include "ophtml.h"
#include "opdebug.h"
#include "opallclass.h"
//#include "oplisttarget.h"
#include "opstructure_site.h"
#include "opallexample.h"
#include "opalltutorial.h"
#include "opallitemwebpage.h"
#include "opallgenericcomment2html.h"
#include "opallgenericcomment2html.h"
#include "listtargetcommentitem.h"
#include "documentation.h"

int main(int argc, char* argv[]) {

    if (argc == 1) {
        cout << " usage : ./main name_of_directory language name_of_excluded_directories" << endl;
        return 1;
    }

    const char* header_cpp[3] = {"txt","h","hpp"};
    const char* body_cpp[2] = {"cc","cpp"};
    const char* header_metil[1] = {"met"};
    const char* body_metil[1] = {"met"};

    vector<const char*> list_excluded_directories;
    Documentation docProject ;
    OpDebug opdebug ;
    OpAllClass opallclass( &docProject.listTarget,&docProject.tree ) ;
    OpAllExample opallexample( &docProject.listTarget,&docProject.tree ) ;
    OpAllGenericComment2HTML opallgenericcomment2html(&docProject);
    OpAllTutorial opalltutorial( &docProject.listTarget,&docProject.tree ) ;
    OpAllItemWebPage opallitemwebpage(&docProject.listTarget,&docProject.tree ) ;
    OpStructure_site opstructure_site( &docProject.tree ) ;

    if (strstr(argv[2],"c++") or (strcmp(argv[2],"c")==0)) {
        /// on indique les fichiers que l'on veut analyser :
        docProject.setHeaderSuffix(header_cpp,3);
        docProject.setBodySuffix(body_cpp,2);
        docProject.setLanguage_Cpp();
    } else
        if (strstr(argv[2],"metil")) {
        /// on indique les fichiers que l'on veut analyser :
            docProject.setHeaderSuffix(header_metil,1);
            docProject.setBodySuffix(body_metil,1);
            docProject.setLanguage_Metil();
        } else {
            cerr << " error : unknown language" << endl;
            return 1;
        }

    for(int i=3;i<argc;i++) {
        list_excluded_directories.push_back(argv[i]);
        cerr << " exclu = " << argv[i] << endl;
    }

    /// on lit tous les fichiers du dossier du projet. argv[1] doit contenir le nom du dossier
    docProject.add_source( argv[1],list_excluded_directories ) ;
    // Ensuite on les "parse".
    docProject.parse() ;

    /// puis on définit la structure du site web.
    /// remarque : si le projet ne contient pas de fichier nommé index.txt pour générer une page d'accueil, il faudra prévoir une page d'accueil par défaut.Pas encore fait.
    opstructure_site.initialize() ;
    docProject.scan( opstructure_site ) ; /// assigne le path des targets déjà créé à cet endroit


    /// on crée la liste des objets Target. Si certains objets génériques n'ont pas de commentaires \generic_comment, on crée ici leur instance Target
    docProject.generate_ListTarget() ;

    
    docProject.generate_webpage_of_summary() ;/// génère les pages web contenant respetivement tous les liens vers les classes, les fonctions, les exemples, les tutoriels, et les mot-clés.
    docProject.generate_webpage_of_main_object() ;/// génère les pages web contenant respetivement tous les liens vers les classes principales, les fonctions principales.

    //docProject.scan( opdebug ) ;/// log de "debbugage"
    //cout << "-------------------  liste des targets  -------------------------------- " << endl ;
    //docProject.display_ListTarget() ;/// "debugage"
    //cout << "-------------------  liste des targets principaux -------------------------------- " << endl ;
    //docProject.display_ListPrincipalName() ;/// "debugage"

    docProject.scan( opallclass ) ; /// génère les pages web des classes, structures, fonctions
    docProject.scan( opallexample ) ; /// génère les pages web des exemples
    docProject.scan( opalltutorial ) ; /// génère les pages web des tutoriaux.
    docProject.scan( opallitemwebpage ) ; /// génère les pages web des items du type webpage.
    docProject.scan( opallgenericcomment2html ) ; /// génère les pages web des objets génériques ayant un commentaire \generic_comment
    opallgenericcomment2html.generate_webPage_of_generic_object_without_generic_comment() ;
    docProject.generate_index() ;/// génère la page d'accueil du site
    //for_each(listPageComment.begin(),listPageComment.end(), ophtml() ) ;
    docProject.generate_file_css() ; /// génère le fichier css du site.
    //docProject.generate_file_for_search_engine(); /// génère le fichier search.idx

    //docProject.listTarget.write_listPrincipalName("list_nom_generique.txt");
    
    return 0 ;
}

