#ifndef DOCUMENTATION_H
#define DOCUMENTATION_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<string>
#include<map>

using namespace std;

//struct CommentItem;
//struct LangRef;
//struct  Op;
#include "op.h"
#include "visitorbloc.h"
#include "listtarget.h"
#include "searchindex.h"

struct PageComment;
struct ListTargetByType;

struct Parameter;

/*
    Cette classe est très importante pour le projet.
    \relates Op
    \friend pasquier@lmt.ens-cachan.fr

*/
struct Documentation {
    Documentation( ) { name_software = "LMT++";}
    ~Documentation();
    void add_source( const char* name_dir, vector<const char*>& list_excluded_directories );
    void addDirSource( const char* name_dir,vector<string>& listsource, vector<const char*>* ptr_list_excluded_directories=NULL );
    void addFileSource( const char* file );
    void generate_ListTarget();
    void display_ListTarget();
    void generate_ListPrincipalName();
    void display_ListPrincipalName();
    void setHeaderSuffix(vector<const char*> l);
    void setBodySuffix(vector<const char*> l);
    /*
    Cette methode génère les pages web de description des objets génériqes puis le résumé par ordre alphabétique des fonctions, puis des structures, des exemples et tutoriaux.
    IMPORTANT : On suppose que les méthodes generate_ListTarget() et generate_ListPrincipalName() furent déjà appelés pour générer la liste des pages web potentielles et la
    liste des noms génériques.
    */
    void generate_webpage_of_summary();
    void generate_webpage_of_main_object(); // génére la page web des fonctions principales et la page web des classes/struct principaux.


    void generate_webpage_list( vector<Target*>& v, const string& name_of_path, const string& suffix,const string& nom, bool incrementID);
    Target* generate_webpage_list_by_type( const ListTargetByType& m, const string& name_of_path, const string& suffix,const string& nom, bool incrementID);
    void generate_webpage_multi_list( map<string,Target*>& m, const string& name_of_path, const string& suffix,const string& nom, bool incrementID);
    void generate_webpage_vacuum( const string& name_of_path, const string& suffix,const string& nom, const string& titre, bool incrementID);
    void generate_file_for_webpage( const string& titre, const string& nom_web );
    void generate_index();
    void generate_file_css();
    void generate_file_for_search_engine();
    void parse(); // cette fonction parse le code c++ de tout le projet ainsi que tous les commentaires.
    void scan( Op& op ); // cette fonction permet d'appliquer un opérateur/fonction op sur tous les objets PageComment du projet.

    vector<PageComment*> listPageComment;
    ListTarget listTarget;
    string name_software;
    map<string,string> tree;
    vector<string> listHeaderSuffix;
    vector<string> listBodySuffix;
    /**
        temporaire : c'est un objet qui génère le fichier search.idx contenant la table de correspondance servant à la recherche par mot clés.
        Cette classe fur récupérée et adaptée du programme doxygen.
    */
    SearchIndex searchIndex;
    static const char text_search_php[];
};













#endif

