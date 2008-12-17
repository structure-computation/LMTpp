#include <iostream>
#include <string>
#include <vector>
//#include <stdio>
#include <map>
using namespace std ;
// pour parcourir, manipuler les fichier sur linux
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>   // pour avoir des infos sur les fichiers : par exemple le type
#include <stdio.h>
#include <cerrno>

#include "token.h"
#include "op.h"
#include "documentation.h"
#include "pagecomment.h"
#include "opallgenericcomment.h"
#include "listtargetcommentitem.h"
#include "listtarget.h"
#include "listtargetbytype.h"
#include "target.h"
#include "util2html.h"
#include "opwebpage_exists.h"
#include "opget_listkeyword.h"
#include "opinternal.h"
//#include "opgettype_for_principalname.h"
//#include "arbre.h"
//#include "noeud.h"
//#include "visitorbloc_namebaseclass.h"

Documentation :: ~Documentation() {

    for(int i=0;i<listPageComment.size() ; i++)
        delete listPageComment[i] ;
}

void Documentation :: add_source( const char* name_dir, vector<const char*>& list_excluded_directories ) {

    vector<string> list_source ;
    string stmp, stmp2 ;
    int i,j,n,m ;

    addDirSource( name_dir,list_source,&list_excluded_directories ) ;
    n = list_source.size() ;
    m = listPageComment.size() ;

//     for(i=0;i<n;i++)
//         cerr << " lll <<<<<< " << list_source[i] << endl ;

    for(i=0;i<n;i++) {
        stmp = enleve_suffix( list_source[i] ) ;
        for(j=0;j<m;j++) {
            if (stmp == listPageComment[j]->nameWithoutSuffix) {
                stmp2 = suffix( list_source[i] ) ;
                listPageComment[j]->suffix_source = stmp2 ;
                break ;
            }
        }
    }
//     cerr << " >>>>>>>>>>>>> "  << endl ;
}

void Documentation :: addFileSource( const char* file ) {

    PageComment* ptr_pc = NULL ;

    ptr_pc = new PageComment( file ) ;
    if (ptr_pc != NULL ) {
        listPageComment.push_back( ptr_pc ) ;
//         cerr << " on ajoute " << ptr_pc->nameFile << endl;
    }
}

void Documentation :: addDirSource( const char* name_dir,vector<string>& listsource, vector<const char*>* ptr_list_excluded_directories ) {

    string stmp ;
    string path ;
    string stmp2 ;
    int err ;
    DIR* dir;
    struct dirent* dp;
    struct stat st ;

    //cout << "------------- départ ----------------" << name_dir << endl ;
    dir = opendir(name_dir) ;
    if (dir==NULL)
        return ;
    //cout << "++++++++++++++++++++++++++++++++++++++ je parcours " << name_dir << endl ;
    path = name_dir  ;
    path += "/" ;
    dp = readdir(dir) ;
    while(dp != NULL) {
        //cout << dp->d_name << endl ; //<< " : " << dp->d_reclen << endl ;
        stmp = path + dp->d_name ;
        //cout << " new dp->d_name = " << stmp << endl ; 
        if ( (err = lstat(stmp.c_str(),&st)) != -1) {
            if ((S_ISDIR(st.st_mode)) && (dp->d_name[0] != '.')) { 
                /// dp->d_name est le nom d'un répertoire qui ne commence pas un point
                cout << " fichier = |" << dp->d_name << "| est un répertoire" << endl ;
                /// on teste si ce répertoire n'est pas un répertoire à exclure.
                if (ptr_list_excluded_directories != NULL) {
                    bool on_le_parse = true;
                    for(int i=0;i<(*ptr_list_excluded_directories).size();i++) {
                        cout << " (*ptr_list_excluded_directories)[i] = |" << (*ptr_list_excluded_directories)[i] << "|" << endl ;
                        if (strcmp(dp->d_name,(*ptr_list_excluded_directories)[i]) == 0) {
                            on_le_parse = false;
                            break;
                        }
                    }
                    if (on_le_parse)
                        addDirSource( stmp.c_str(),listsource ) ;      // addDirSource(dp->d_name) ;
                }else
                    addDirSource( stmp.c_str(),listsource ) ;      // addDirSource(dp->d_name) ;
            } else
            if (S_ISREG(st.st_mode)) {
                // c'est un fichier
                //stmp = dp->d_name ;
                //cout << " fichier = |" << dp->d_name << "|" ;
                stmp2 = suffix( stmp ) ;
                //cout << " suffix = |" << stmp2 << "|" << endl ;
                if ((stmp2=="h") || (stmp2=="txt")) {
                    addFileSource(stmp.c_str()) ; 
                //cout << "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[ ajoutons " << stmp  << endl ;//addFileSource(stmp.c_str()) ;
                }
                if ((stmp2=="c") || (stmp2=="cpp") || (stmp2=="cc"))
                    listsource.push_back( stmp ) ;
            } else
            if (S_ISLNK(st.st_mode)) {
                //cout << " fichier = |" << stmp << "| est un lien" << endl ;
            } else
            if (S_ISCHR(st.st_mode)) {
                //cout << " fichier = |" << stmp << "| est un fichier spécial caractère" << endl ;
            } else
            if (S_ISBLK(st.st_mode)) {
                //cout << " fichier = |" << stmp << "| est un fichier spécial bloc" << endl ;
            } else
            if (S_ISFIFO(st.st_mode)) {
                //cout << " fichier = |" << stmp << "| est un tube nommé" << endl ;
            } else
            if (S_ISSOCK(st.st_mode)) {
                //cout << " fichier = |" << stmp << "| est un socket" << endl ;
            } else
                ;//cout << " fichier = |" << stmp << "| est d'un format inconnu..." << endl ;

        }
        else {
            cerr << "lstat échoue avec la réponse = " << err << "   errno = " ;
            switch(errno) {
                case EBADF : cout << "EBADF" << endl ; break ;
                case EFAULT : cout << "EFAULT" << endl ; break ;
                case ENAMETOOLONG : cout << "ENAMETOOLONG" << endl ; break ;
                case ENOENT : cout << "ENOENT" << endl ; break ;
                case ENOMEM : cout << "ENOMEM" << endl ; break ;
                case ENOTDIR : cout << "ENOTDIR" << endl ; break ;
                default : cout << "ERREUR INCONNUE" << endl ; break ;
            }
        }
        dp = readdir(dir) ;
    }
    //cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  << endl ;
    closedir(dir) ;
}

void Documentation :: generate_ListTarget() {

    string stmp ;
    int i,n,j,m ;
    Target* pt ;

    listTarget.clear() ;
    // on définit la liste des éléments pointables : cad les éléments qui héritent de la classe Target.
    m = listPageComment.size() ;
    for(j=0;j<m;j++) {
        n = listPageComment[j]->code.list_subType_function.size() ;
        for(i=0;i<n;i++)
            listTarget.push_back( listPageComment[j]->code.list_subType_function[i],true ) ; // vrai car il faut incrémenter l'ID du target listPageComment[j]->code.list_subType_function[i] et false car ce n'est pas un generic_comment
        n= listPageComment[j]->listComment.size() ;
        for(i=0;i<n;i++) {
            listPageComment[j]->listComment[i]->add_tutorial_example_genericComment_webpage_image( &listTarget ) ;
        }
    }

    // on détermine le type référencé par les generic_comment déjà rencontré dans le code et dont les indices dans list sont stockés dans listPrincipalName


    // un certain nombre d'objets génériques n'ont pas de commentaires génériques (cad \generic_comment). On crée ici un target pour chacun d'eux dans la foncton suivante et on crée aussi une sous-liste les contenant :
    listTarget.generate_listPrincipalName( tree["generic_comment"] );

    // détermination des types commentés par les generic_comment
    listTarget.set_type_of_listPrincipalName();
}

void Documentation :: display_ListTarget() {

    int i,n ;

    cout << "============== liste de Targets ===========================" << endl;
    cout << listTarget << endl ;
    cout << "============== fin de la liste de Targets =================" << endl;
}

void Documentation :: display_ListPrincipalName() {

    int i,n ;

    n = listTarget.listPrincipalName.size() ; //  listPrincipalName.size() ;
    for(i=0;i<n;i++)
        cout << " nom principal = " << listTarget.list[listTarget.listPrincipalName[i]].pt->name.principalName << " avec un commentaire générique : " << listTarget.list[listTarget.listPrincipalName[i]].pt->ancestor << endl ;
}

void Documentation :: scan( Op& op ) {

    //for_each(listPageComment.begin(),listPageComment.end(), op ) ;
    int i ;
    for(i=0;i<listPageComment.size(); i++)
        op( listPageComment[i] ) ;
}

void Documentation :: parse() {

    //VisitorBloc_NameBaseClass visitorbloc_name_all_base_class( &listLink  ) ;
    //VisitorBloc_NameBaseIsoledFunction visitorbloc_name_all_base_isoled_function( &listLink  ) ;
    int i,m ;

    m = listPageComment.size() ;
    for(i=0;i<m;i++) {
        listPageComment[i]->parse();
        cout << listPageComment[i]->nameFile <<" is parsing" << endl ;
    }
}

void Documentation :: generate_webpage_list( vector<Target*>& v, const string& name_of_path, const string& suffix,const string& nom, bool incrementID) {

    string stmp ;
    string stmp2 ;
    int i,n,nb_col,m,j ;
    bool genre_first_cell ;
    Target* pt ;

    pt = new Target() ;
    stmp = french2webID( nom ) ;
    pt->name.principalName = stmp ;
    pt->name.name = suffix + '_' + stmp ;
    pt->path = tree[name_of_path] ;
    listTarget.push_back_RealTarget( pt,incrementID ) ; // utile pour pt->reference( ) : i.e. incrémente le nombre id
    stmp = pt->reference() ;
    //cout << " -------------->>>>>>>>>>>  CommentItemTutorial->reference() " << stmp << endl ;
    ofstream pageWeb( stmp.c_str() ,ios::out);
    //VisitorCommentItem_toHTML vivi( &pageWeb, ptr_list_target ) ;
    stmp = french2HTML( nom ) ;

    //cout << "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII" << pt->reference() << endl ;
    //cout << "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII" << tree["root"] << endl ;

    generate_header( pt,tree["root"],pageWeb, stmp ) ;


    pageWeb << "<p class=\"resume\">" << std::endl ;

    /// on génère le tableau 
    nb_col = 5 ;
    n = v.size() ;
    if (n>0) {
        pageWeb << "<table cellspacing=\"2\">" << std::endl ;
        for(i=0;i<n;i+=nb_col) {
            if( ((i/nb_col) % 2) == 0)
                genre_first_cell = true;
            else
                genre_first_cell = false;
            pageWeb << "<tr>" << std::endl ;
            m = min(i+nb_col,n);
            for(j=i;j<m;j++) {
                stmp = v[j]->name.principalName ;
                stmp2 = linkHTML( pt->reference(), v[j]->reference(),stmp ) ;
                if (genre_first_cell)
                    pageWeb << "    <td class=\"pair\">" << stmp2 << "</td>" << std::endl ;
                else
                    pageWeb << "    <td>" << stmp2 << "</td>" << std::endl ;
                genre_first_cell = !genre_first_cell;
            }
            pageWeb << "</tr>" << std::endl ;
        }
        pageWeb << "</table>" << std::endl ;
    }

    pageWeb << "</p>" << std::endl ;
    pageWeb << "<hr />" << std::endl ;
    for(i=0;i<NB_FINAL_LINE;i++)
        pageWeb << "<br>" << std::endl ;
    pageWeb << "</body>" << std::endl ;
    pageWeb << "</html>" << std::endl ;
    pageWeb <<std::endl;
}

typedef map<string,Target*>::const_iterator const_iter ;

void display_multi_list( map<string,Target*>& ma, int level, const_iter first, const_iter end, ofstream& pageWeb, Target* pt ) {

    string stmp,stmp2 ;
    const_iter iter, iter2 ;

    // liste vide
    if (first == end)
        return ;
    pageWeb << "<ul>" << std::endl ;
    for(iter = first;iter != end; ) {
        if (extract_name_of_path( stmp,iter->first,level)) {
            // au niveau level, on a une feuille
            pageWeb << "<li>" << linkHTML( pt->reference(), iter->second->reference(),stmp ) << "</li>" << std::endl ;
            iter++ ;
        } else {
            // au niveau level, on a un "sous-répertoire"
            pageWeb << "<li>" << french2HTML( stmp ) << "</li>" << std::endl ;
            for( iter2 = iter ; iter2 != end; iter2++ ) {
                extract_name_of_path( stmp2,iter2->first,level) ;
                if (stmp2 != stmp)
                    break ;
            }
            display_multi_list( ma,level+1,iter,iter2,pageWeb,pt ) ;
            iter = iter2 ;
        }
    }
    pageWeb << "</ul>" << std::endl ;
}

void Documentation :: generate_webpage_multi_list( map<string,Target*>& ma, const string& name_of_path, const string& suffix,const string& nom, bool incrementID) {

    string cur_dir,stmp ;
    string dir ;
    deque<int> list_index ;
    int i,j,ii,next,n ;
    Target* pt ;
    //map<string,Target*>::const_iterator iter ;
    bool leaf ;

    pt = new Target() ;
    stmp = french2webID( nom ) ;
    pt->name.principalName = stmp ;
    pt->name.name = suffix + '_' + stmp ;
    pt->path = tree[name_of_path] ;
    listTarget.push_back_RealTarget( pt,incrementID ) ; // utile pour pt->reference( ) : i.e. incrémente le nombre id
    stmp = pt->reference() ;

    ofstream pageWeb( stmp.c_str() ,ios::out);
    stmp = french2HTML( nom ) ;

    generate_header( pt,tree["root"],pageWeb, stmp ) ;

    pageWeb << "<p class=\"resume\">" << std::endl ;

    display_multi_list( ma,0,ma.begin(),ma.end(),pageWeb,pt) ;

    pageWeb << "</p>" << std::endl ;
    pageWeb << "<hr />" << std::endl ;
    for(i=0;i<NB_FINAL_LINE;i++)
        pageWeb << "<br>" << std::endl ;
    pageWeb << "</body>" << std::endl ;
    pageWeb << "</html>" << std::endl ;
    pageWeb <<std::endl;
}

Target* Documentation :: generate_webpage_list_by_type( const ListTargetByType& li, const string& name_of_path, const string& suffix,const string& nom, bool incrementID) {

    string stmp ;
    string stmp2 ;
    int i,n,m,j ;
    bool ouvrant ;
    Target* pt ;

    pt = new Target() ;
    //stmp = replace_delimitateur( nom,'/','.') ;
    stmp = french2webID( nom ) ;
    pt->name.principalName = stmp ;
    //stmp = french2webID( replace_delimitateur( nom,'/','_') ) ;
    pt->name.name = suffix + '_' + stmp ;
    pt->path = tree[name_of_path] ;
    listTarget.push_back_RealTarget( pt,incrementID ) ; // utile pour pt->reference( ) : i.e. incrémente le nombre id
    stmp = pt->reference() ;
    //cout << " -------------->>>>>>>>>>>  CommentItemTutorial->reference() " << stmp << endl ;
    ofstream pageWeb( stmp.c_str() ,ios::out);
    //VisitorCommentItem_toHTML vivi( &pageWeb, ptr_list_target ) ;
    stmp = french2HTML( extract_last_name_of_path(nom) ) ;

    //cout << "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII" << pt->reference() << endl ;
    //cout << "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII" << tree["root"] << endl ;
    //cout << "IIIIIIIIIIIIIIIIIIIIIIIIIIIIIII" << tree[name_of_path] << endl ;

    generate_header( pt,tree["root"],pageWeb, stmp ) ;

    n = li.list_class_struct.size() ;
    if (n > 0) {
        pageWeb << "<h2> Classes </h2>" << std::endl ;
        pageWeb << "<ul>" << std::endl ;
        for(i=0;i<n;i++) {
            if (li.list_class_struct[i]->of_class_or_struct())
                stmp = li.list_class_struct[i]->name.name ;
            else 
                stmp = li.list_class_struct[i]->name.principalName ;
            stmp2 = linkHTML( pt->reference(), li.list_class_struct[i]->reference(),stmp ) ;
            pageWeb << "<li>" << stmp2 << "</li>" << std::endl ;
        }
        pageWeb << "</ul>" << std::endl ;
    }

    n = li.list_function.size() ;
    if (n > 0) {
        pageWeb << "<h2> Fonctions </h2>" << std::endl ;
        pageWeb << "<ul>" << std::endl ;
        for(i=0;i<n;i++) {
            if (li.list_function[i]->of_function())
                stmp = li.list_function[i]->name.name ;
            else 
                stmp = li.list_function[i]->name.principalName ;
            stmp2 = linkHTML( pt->reference(), li.list_function[i]->reference(),stmp ) ;
            pageWeb << "<li>" << stmp2 << "</li>" << std::endl ;
        }
        pageWeb << "</ul>" << std::endl ;
    }

    n = li.list_example.size() ;
    if (n>0) {
        pageWeb << "<h2> Exemples </h2>" << std::endl ;
        pageWeb << "<ul>" << std::endl ;
        for(i=0;i<n;i++) {
            if(li.list_example[i]->of_example())
                stmp = li.list_example[i]->name.name ;
            else
                stmp = li.list_example[i]->name.principalName ;
            stmp2 = linkHTML( pt->reference(), li.list_example[i]->reference(),stmp ) ;
            pageWeb << "<li>" << stmp2 << "</li>" << std::endl ;
        }
        pageWeb << "</ul>" << std::endl ;
    }

    n = li.list_tutorial.size() ;
    if (n>0) {
        pageWeb << "<h2> Tutoriels </h2>" << std::endl ;
        pageWeb << "<ul>" << std::endl ;
        for(i=0;i<n;i++) {
            if (li.list_tutorial[i]->of_tutorial())
                stmp = li.list_tutorial[i]->name.name ;
            else
                stmp = li.list_tutorial[i]->name.principalName ;
            stmp2 = linkHTML( pt->reference(), li.list_tutorial[i]->reference(),stmp ) ;
            pageWeb << "<li>" << stmp2 << "</li>" << std::endl ;
        }
        pageWeb << "</ul>" << std::endl ;
    }

    pageWeb << "<hr />" << std::endl ;
    for(i=0;i<NB_FINAL_LINE;i++)
        pageWeb << "<br>" << std::endl ;
    pageWeb << "</body>" << std::endl ;
    pageWeb << "</html>" << std::endl ;
    pageWeb <<std::endl;

    return pt ;
}

void Documentation :: generate_webpage_vacuum( const string& name_of_path, const string& suffix,const string& nom, const string& titre,bool incrementID) {

    string stmp ;
    string stmp2 ;
    int i,n,m,j ;
    Target* pt ;

    pt = new Target() ;
    stmp = french2webID( nom ) ;
    //pt->name.principalName = stmp ;
    pt->name.principalName = titre ;
    pt->name.name = suffix + '_' + stmp ;
    //pt->name.name = suffix + '_' + nom ;
    pt->path = tree[name_of_path] ;
    listTarget.push_back_RealTarget( pt,incrementID ) ; // utile pour pt->reference( ) : i.e. incrémente le nombre id
    stmp = pt->reference() ;

    ofstream pageWeb( stmp.c_str() ,ios::out);

    stmp = french2HTML( titre ) ;

    generate_header( pt,tree["root"],pageWeb, stmp ) ;

    pageWeb << "<p>" << std::endl ;
    pageWeb << "Compl&eacute;ter le fichier "<< nom << " dans le r&eacute;pertoire des sources du programme." << std::endl ;
    pageWeb << "</p>" << std::endl ;

    pageWeb << "<hr />" << std::endl ;
    for(i=0;i<NB_FINAL_LINE;i++)
        pageWeb << "<br>" << std::endl ;
    pageWeb << "</body>" << std::endl ;
    pageWeb << "</html>" << std::endl ;
    pageWeb <<std::endl;

}

    /*
    génère la pages web des objets génériques (i.e. lorsque plusieurs Target ont le même nom principal).
    Il y a deux cas à traités; Celui où l'objet générique a un commentaire générique et l'autre où il n' en a pas.
    s'il y a un commentaire générique, on parcourt la structure pour faire la page, sinon on fait directement la page !
    */
void Documentation::generate_webpage_of_summary() {

    string stmp ;
    OpGet_listKeyword op_get_list_keyword ;
    vector<Target*> list_example ;
    vector<Target*> list_tutorial ;
    vector<Target*> list_function ;
    vector<Target*> list_struct_class ;
    int i,n,end,pos ;
    map<string,ListTargetByType>::const_iterator iter ;
    map<string,Target*> map_keyword_Target ;
    Target* pt;

     /*
     On génére les pages web de résumé de toutes les fonctions, toutes les structures, tous les tutoriaux, tous les exemples.
     On commence par récupérer les brief des fonctions, structures, classes, exemples, et exemples qui ne sont pas génériques.
     Puis avec ces données, on créera les pages web recapitulatives des structures/classes, des fonctions, des exemples et des tutoriaux.
    */
    // tout compte fait, on ne récupère pas les briefs !!!!!!!!!!!!!!!!!!!!

    n = listTarget.listPrincipalName.size();
    for(i=0;i<n;i++) {
        pt = listTarget.list[listTarget.listPrincipalName[i]].pt ;
        if (pt->of_generic_comment() || pt->of_type_without_generic_comment() ) {
            if (pt->ancestor != NULL) {
                if (pt->ancestor->of_class_or_struct())
                    list_struct_class.push_back(pt);
                if (pt->ancestor->of_tutorial() )
                    list_tutorial.push_back(pt);
                if (pt->ancestor->of_example())
                    list_example.push_back(pt);
                if (pt->ancestor->of_function())
                    list_function.push_back(pt);
            } else {
                cerr << "**** ATTENION : ancestor == NULL !" << endl ;
                cerr << *pt << endl ;
                cerr << "****" << endl ;
            }
        } else {
            if (pt->of_class_or_struct())
                list_struct_class.push_back(pt);
            if (pt->of_tutorial() )
                list_tutorial.push_back(pt);
            if (pt->of_example())
                list_example.push_back(pt);
            if (pt->of_function())
                list_function.push_back(pt);
        }
    }

    // ensuite on trie les 4 listes.
    stable_sort( list_example.begin(),list_example.end(), inferior ) ;
    stable_sort( list_tutorial.begin(),list_tutorial.end(), inferior ) ;
    stable_sort( list_function.begin(),list_function.end(), inferior ) ;
    stable_sort( list_struct_class.begin(),list_struct_class.end(), inferior ) ;
    // on crée les pages web.
    generate_webpage_list( list_example,"root","list", "Tous les exemples", false ) ; // false signifie que l'id d target n'est pas incrémenté
    generate_webpage_list( list_tutorial,"root","list", "Tous les tutoriels", false ) ; // false signifie que l'id d target n'est pas incrémenté
    generate_webpage_list( list_function,"root","list", "Toutes les  fonctions", false ) ; // false signifie que l'id d target n'est pas incrémenté
    generate_webpage_list( list_struct_class,"root","list", "Toutes les classes", false ) ; // false signifie que l'id d target n'est pas incrémenté

    /*
     On crée ensuite la page web affichant la liste des mots clés .
     on récupère tous les mots clés avec les pages web associées dans op_get_list_keyword.
    
    */
    scan( op_get_list_keyword ) ;
    for(iter = op_get_list_keyword.list_keyword.begin();iter != op_get_list_keyword.list_keyword.end(); ++iter) {
        stmp = extract_path( iter->first ) ;
        stmp = "keyword_" + replace_delimitateur( stmp,'/','_') ;
        map_keyword_Target[iter->first] = generate_webpage_list_by_type(iter->second,"keyword",stmp,extract_last_name_of_path(iter->first),false) ;
        //cerr << " iter->first = " << iter->first << endl ;
        //cerr << " extract_last_name_of_path(iter->first) = " << extract_last_name_of_path(iter->first) << endl ;
        //cerr << " replace_delimitateur(iter->first,'/','_') = " << replace_delimitateur(iter->first,'/','_') << endl ;
    }
    generate_webpage_multi_list( map_keyword_Target,"root","list", "Tous les mot-clés", false ) ; // false signifie que l'id d target n'est pas incrémenté

}

void Documentation::generate_webpage_of_main_object() {

    int i,n;
    OpInternal opinternal;
    vector<Target*> list_function ;
    vector<Target*> list_struct_class ;
    Target* pt ;


    listTarget.init_property();
    scan( opinternal ) ;
    listTarget.update_property_of_generic_comment();

    n = listTarget.listPrincipalName.size();
    for(i=0;i<n;i++) {
        pt = listTarget.list[listTarget.listPrincipalName[i]].pt ;
        if (pt->of_generic_comment() || pt->of_type_without_generic_comment() ) {
            if (pt->ancestor != NULL) {
                if (pt->ancestor->of_class_or_struct() && (pt->property == 0))
                    list_struct_class.push_back(pt);
                if (pt->ancestor->of_function() && (pt->property == 0))
                    list_function.push_back(pt);
            } else {
                cerr << "**** ATTENION : ancestor == NULL !" << endl ;
                cerr << *pt << endl ;
                cerr << "****" << endl ;
            }
        } else {
            if (pt->of_class_or_struct() && (pt->property == 0))
                list_struct_class.push_back(pt);
            if (pt->of_function() && (pt->property == 0))
                list_function.push_back(pt);
        }
    }

    // ensuite on trie les 4 listes.
    stable_sort( list_function.begin(),list_function.end(), inferior ) ;
    stable_sort( list_struct_class.begin(),list_struct_class.end(), inferior ) ;
    // on crée les pages web.
    generate_webpage_list( list_function,"root","list", "Les fonctions principales", false ) ; // false signifie que l'id d target n'est pas incrémenté
    generate_webpage_list( list_struct_class,"root","list", "Les classes principales", false ) ; // false signifie que l'id d target n'est pas incrémenté
}

void Documentation :: generate_file_for_webpage( const string& titre, const string& nom_web ) {

    string stmp ;

    stmp = french2webID( titre ) + ".txt" ;
    ofstream page( stmp.c_str() ,ios::out);
    page << "/*!" << std::endl ;
    page << "\\webpage " << nom_web <<  " " << titre << std::endl ;
    page << std::endl ;
    page << "    à compléter (ne pas effacer la ligne ci dessus et indenter le texte)." << std::endl ;
    page << std::endl ;
    page << std::endl ;
    page << std::endl ;
    page << std::endl ;
    page << std::endl ;
    page << std::endl ;
    page << std::endl ;
    page << std::endl ;
    page << std::endl ;
    page << std::endl ;
    page << "*/" << std::endl ;
}

// génère la page d'accueil du site (avec des a priori...)
void Documentation :: generate_index() {

    OpWebPage_exists op_webpage_exists ;
    vector<string> list_webpage;
    vector<string> list_titre_of_webpage;
    string stmp ;
    string stmp2 ;
    int i,n ;
    Target* pt ;

    pt = new Target() ;
    pt->name.principalName = "index_software" ;
    pt->name.name = "index" ;
    pt->path = tree["root"] ;
    listTarget.push_back_RealTarget( pt,false ) ; // false signifie que l'id target n'est pas incrémenté donc le nom du fichier html ne sera pas indexé
    stmp = pt->reference() ;
    //cout << " -------------->>>>>>>>>>>  CommentItemTutorial->reference() " << stmp << endl ;
    ofstream pageWeb( stmp.c_str() ,ios::out);

    pageWeb<<"<?xml version=\"1.0\" encoding=\"iso-8859-1\"?>"<<std::endl;
    pageWeb<<"<!DOCTYPE html"<<std::endl;
    pageWeb<<"   PUBLIC \"-//W3C//DTDXHTML 1.0 Strict//EN\" \"DTD/xhtml1-strict.dtd\">"<<std::endl;
    pageWeb<<"<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"fr\" lang=\"fr\">"<<std::endl;
    pageWeb<<"<head>"<<std::endl;
    pageWeb<<"<title> Documentation de " << name_software <<  " </title>"<<std::endl;
    pageWeb<<"<link href=\"classic.css\" rel=\"stylesheet\" type=\"text/css\" />"<<std::endl;
    pageWeb<<"</head>"<<std::endl;
    pageWeb<<"<body text=\"#000000\" bgcolor=\"#fcfcdf\" link=\"#0000cc\" vlink=\"#551a8b\"  >"<<std::endl;
    

    pageWeb<< "<h1 align=\"center\"> Documentation de " << name_software << "<br/><small></small></h1>" << std::endl;

    pageWeb<< "<table cellspacing=\"2\">" << std::endl;
    pageWeb<< " <tr>"  << std::endl;
    pageWeb<< "<td class=\"pseudo_en-tete_index\"> Pour commencer </td>"  << std::endl;
    pageWeb<< "<td class=\"pseudo_en-tete_index\"> Description </td>"  << std::endl;
    pageWeb<< "<td class=\"pseudo_en-tete_index\"> Outils </td>"  << std::endl;
    pageWeb<< " </tr>"  << std::endl;

    pageWeb<< " <tr>"  << std::endl;
    stmp = "introduction";
    list_webpage.push_back(stmp);
    list_titre_of_webpage.push_back("Introduction");
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\">Quest-ce que c'est ?</a></td>" << std::endl;
    pageWeb<< "<td><a href=\"list_touslesmot-cles.html\">Tous les MOT-CL&Eacute;S</a></td>" << std::endl;
    stmp = "git";
    list_webpage.push_back(stmp);
    stmp2 = "Git";
    list_titre_of_webpage.push_back(stmp2);
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\"> " << stmp2 << " </a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    pageWeb<< " </tr>"  << std::endl;

    pageWeb<< " <tr>"  << std::endl;
    stmp = "installation";
    stmp2 = "Installation";
    list_webpage.push_back(stmp);
    list_titre_of_webpage.push_back(stmp2);
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\">" << stmp2 << " </a></td>" << std::endl;
    pageWeb<< "<td><a href=\"list_lesclassesprincipales.html\">Les classes principales</a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    stmp = "scons";
    list_webpage.push_back(stmp);
    stmp2 = "Scons";
    list_titre_of_webpage.push_back(stmp2);
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\"> " << stmp2 << " </a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    pageWeb<< " </tr>"  << std::endl;

    pageWeb<< " <tr>"  << std::endl;
    stmp = "quickstart";
    list_webpage.push_back(stmp);
    list_titre_of_webpage.push_back("Bien commencer avec la LMT++");
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\">D&eacute;part rapide</a> (quick start) </td>" << std::endl;
    pageWeb<< "<td><a href=\"list_lesfonctionsprincipales.html\">Les fonctions principales</a></td>" << std::endl;
    stmp = "python";
    list_webpage.push_back(stmp);
    stmp2 = "Python";
    list_titre_of_webpage.push_back(stmp2);
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\"> " << stmp2 << " </a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    pageWeb<< " </tr>"  << std::endl;

    pageWeb<< " <tr>"  << std::endl;
    pageWeb<< "<td><a href=\"list_touslestutoriels.html\">Tutoriels</a></td>" << std::endl; // ********* CODAGE en DUR -> pas bien
    pageWeb<< "<td><a href=\"list_touteslesclasses.html\">Toutes les classes</a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    stmp = "metil";
    list_webpage.push_back(stmp);
    stmp2 = "Metil";
    list_titre_of_webpage.push_back(stmp2);
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\"> " << stmp2 << " </a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    pageWeb<< " </tr>"  << std::endl;

    pageWeb<< " <tr>"  << std::endl;
    pageWeb<< "<td><a href=\"list_touslesexemples.html\">Exemples</a></td>" << std::endl;
    pageWeb<< "<td><a href=\"list_touteslesfonctions.html\">Toutes les fonctions</a></td>" << std::endl;
    pageWeb<< "<td></td>" << std::endl;
    pageWeb<< " </tr>"  << std::endl;

    pageWeb<< " <tr>"  << std::endl;
    stmp = "faq";
    list_webpage.push_back(stmp);
    stmp2 = "FAQ";
    list_titre_of_webpage.push_back(stmp2);
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\"> " << stmp2 << " </a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    pageWeb<< "<td></td>" << std::endl;
    pageWeb<< "<td></td>" << std::endl;
    pageWeb<< " </tr>"  << std::endl;

    pageWeb<< " <tr>"  << std::endl;
    pageWeb<< "<td class=\"pseudo_en-tete_index\"> Liens externes </td>"  << std::endl;
    pageWeb<< "<td class=\"pseudo_en-tete_index\"> Communaut&eacute; </td>" << std::endl;
    pageWeb<< "<td class=\"pseudo_en-tete_index\"> G&eacute;n&eacute;ralit&eacute;s </td>" << std::endl;
    pageWeb<< " </tr>"  << std::endl;

    pageWeb<< " <tr>"  << std::endl;
    pageWeb<< "<td></td>" << std::endl;
    stmp = "contribution";
    list_webpage.push_back(stmp);
    stmp2 = "Comment contribuer";
    list_titre_of_webpage.push_back(stmp2);
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\"> " << stmp2 << " </a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    stmp = "philosophie";
    list_webpage.push_back(stmp);
    stmp2 = "Philosophie de la librairie";
    list_titre_of_webpage.push_back(stmp2);
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\"> " << stmp2 << " </a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    pageWeb<< " </tr>"  << std::endl;

    pageWeb<< " <tr>"  << std::endl;
    pageWeb<< "<td></td>" << std::endl;
    stmp = "rappportdebug";
    list_webpage.push_back(stmp);
    stmp2 = "Rapporter un bug";
    list_titre_of_webpage.push_back(stmp2);
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\"> " << stmp2 << " </a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    stmp = "licence";
    list_webpage.push_back(stmp);
    stmp2 = "Licence de la librairie";
    list_titre_of_webpage.push_back(stmp2);
    pageWeb<< "<td><a href=\"" << "webpage_"+stmp <<".html\"> " << stmp2 << " </a></td>" << std::endl; // CODAGE en DUR   -> pas bien
    pageWeb<< " </tr>"  << std::endl;
    pageWeb<< " </table>"  << std::endl;
    pageWeb<< "<hr/>" << std::endl;
    pageWeb<< "</body>" << std::endl;
    pageWeb<< "</html>" << std::endl;

    /*
         cet endroit, il faut parcourir le répertoire du programme pour trouver les fichiers txt correspondants aux pages web intro, installation, 
    */
    n = list_webpage.size();
    for(i=0;i<n;i++) {
        op_webpage_exists.init("webpage_"+list_webpage[i]) ;
        scan( op_webpage_exists ) ;
        if (!op_webpage_exists.exists) {
            generate_webpage_vacuum("root","webpage",list_webpage[i],list_titre_of_webpage[i],false ) ; // cela crée une page web vide : c'est mieux que rien
            generate_file_for_webpage( list_webpage[i],list_titre_of_webpage[i]) ;
        }
    }
}

void Documentation :: generate_file_css() {

    string stmp ;

    stmp = tree["root"] + "classic.css" ;
    ofstream pageWeb( stmp.c_str() ,ios::out);

    pageWeb << std::endl;

//     pageWeb << "ul {" << std::endl;
//     pageWeb << "\tlist-style-image: url(Kurodai-icon.gif);"  << std::endl;
//     pageWeb << "}"  << std::endl;
    pageWeb << std::endl;
    pageWeb << "ul.navigation{"  << std::endl;
    pageWeb << "\tlist-style-image: url(Kurodai-icon.gif);"  << std::endl;
    pageWeb << "\tlist-style-type: none;"  << std::endl;
    pageWeb << "\tmargin: 4px;"  << std::endl;
    pageWeb << "\tpadding: 4px;"  << std::endl;
    pageWeb << "}"  << std::endl;
    pageWeb << std::endl;
    pageWeb << "ul.navigation li {" << std::endl;
    pageWeb << "\tdisplay: inline;" << std::endl;
    pageWeb << "}"  << std::endl;
    pageWeb << std::endl;
    pageWeb <<  "ul.navigation li a {" << std::endl;
    pageWeb <<  "\tpadding: 5px 20px;" << std::endl;
    pageWeb << "\tmargin: 0px 2px;" << std::endl;
    pageWeb << "\tborder: 1px solid #666;" << std::endl;
    pageWeb << "\tbackground-color: #f4d9ab;" << std::endl;
    pageWeb << "\ttext-decoration: none;" << std::endl;
    pageWeb << "\ttext-align: center;" << std::endl;
    pageWeb << "}" << std::endl;
    pageWeb << std::endl;
    pageWeb << "ul.en_tete_tableau_3colonnes {" << std::endl;
    pageWeb << "\tlist-style-image: url(Kurodai-icon.gif);" << std::endl;
    pageWeb << "\tpadding: 5px 5px;" << std::endl;
    pageWeb << "}" << std::endl;
    pageWeb << "td.pseudo_en-tete_index {\n\tbackground-color: #6fadea;\n\twidth: 400px;\n\tmargin: 1px;\n\ttext-align: center;\n\t}\n" << std::endl;
//     pageWeb << "ul.en_tete_tableau_3colonnes li {" << std::endl;
//     pageWeb << "\tdisplay: inline;" << std::endl;
//     pageWeb << "\tfloat: left;" << std::endl;
//     pageWeb << "\twidth: 33%;" << std::endl;
//     pageWeb << "\tmargin: 1px;" << std::endl;
//     pageWeb << "\tbackground-color: #6fadea;" << std::endl;
//     pageWeb << "\ttext-align: center;" << std::endl;
//     pageWeb << "}" << std::endl;
    pageWeb << std::endl;
    pageWeb << "p.bloc {" << std::endl;
    pageWeb << "}" << std::endl;
    pageWeb << std::endl;
//     pageWeb << "ul.ligne_tableau_3colonnes {\n    list-style-image: url(Kurodai-icon.gif);\n    list-style-type: disc;\n    padding: 5px 5px;\n    width: 100%;\n   height: 100px;\n}\n" << std::endl;
    pageWeb << std::endl;
    pageWeb << "ul.ligne_tableau_3colonnes li {\n	display: inline;\n	float: left;\n	width: 33%;\n	margin: 1px;\n	text-align: left;\n}\n" << std::endl;
    pageWeb << std::endl;
    pageWeb << "ul.cellule {\n	list-style-type: disc;\n}\n" << std::endl;
    pageWeb << std::endl;
    pageWeb << "ul.cellule li {\n	width: 100%;\n}\n" << std::endl;
    pageWeb << std::endl;
    pageWeb << "div.code {\n	background-color: #fde1e7;\n	padding: 0px 85px;\n	width: 83%;\n}\n" << std::endl;
    pageWeb << std::endl;
    pageWeb << "div.verbatim {\n	background-color: #c7dad7;\n	padding: 0px 85px;\n	width: 83%;\n}\n" << std::endl;
    pageWeb << std::endl;
    pageWeb << "td.pair {\n    background-color: #eaeacf;#cbcbb4;\n}\n" << std::endl;
    pageWeb << std::endl;
    pageWeb << "a:link {\n    text-decoration: none;\n}\n" << std::endl;
    pageWeb << "a:visited {\n    text-decoration: none;\n}\n" << std::endl;
    pageWeb << std::endl;
    pageWeb << "a:hover {\n    text-decoration: underline;\n}\n" << std::endl;
//     pageWeb << "ul.parameter_template li {" << std::endl;
//     pageWeb << "\tdisplay: inline;" << std::endl;
//     pageWeb << "}"  << std::endl;
//     pageWeb << std::endl;

    pageWeb << std::endl;
    pageWeb << std::endl;
    pageWeb << std::endl;
    pageWeb << std::endl;
    pageWeb << std::endl;
    pageWeb << std::endl;
    pageWeb << std::endl;
    pageWeb << std::endl;
    pageWeb << std::endl;
    pageWeb << std::endl;
    pageWeb << std::endl;
    pageWeb << std::endl;
}














