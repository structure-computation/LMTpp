#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "token.h"
#include "op.h"
#include "names.h"
#include "target.h"
#include "listtarget.h"
#include "target_type_without_genericcomment.h"

ListTarget :: ~ListTarget() {

    int i,n ;

    n = list.size();
    for(i=0;i<n;i++)
        if (list[i].realTarget)
            delete list[i].pt ;
}

void ListTarget::update_property_of_generic_comment() {

    int i,n,j,m ;
    Target* pt;

    m = listPrincipalName.size();
    n = list.size();
    for(i=0;i<n;i++)
        if (list[i].pt->property != 0) {
            pt = list[i].pt;
            if (!pt->of_generic_comment() && !pt->of_type_without_generic_comment() ) {
                for(j=0;j<m;j++) {
                    if (list[listPrincipalName[j]].pt->name.principalName == pt->name.principalName) {
                        list[listPrincipalName[j]].pt->property = pt->property;
                        break ;
                    }
                }
            }
        }
}

void ListTarget :: init_property() {

    int i,n ;

    n = list.size();
    for(i=0;i<n;i++)
        list[i].pt->property = 0;
}

/*
 indice contient l'indice du premier target possédant le nom principal name ou bien l'indice du generic_comment de nom principal name ou encore -1 s'il la fonction n'a rien trouvé.
*/
int ListTarget :: nb_principalName(int* indice, string& name) {
    int i,n,c,in ;

    c = 0 ;
    in = -1 ;
    n = list.size() ;
    for(i=0;i<n;i++) {
        if (list[i].pt->name.principalName == name ) {
            c++ ;
            if ((list[i].pt->of_generic_comment()) || (in == -1))
                in = i ;
        }
    }
    *indice = in;
    return c ;
}

/*
Cette fonction ajoute un target dans la liste des targets.
*/
void ListTarget :: push_back( Target* pt, bool incrementID ) {

    TargetIntel targetintel ;

    targetintel.pt = pt ;
    targetintel.realTarget = false ;
    //targetintel.verify = false;
    list.push_back(targetintel);

//     if (is_generic_comment)
//         listPrincipalName.push_back(m) ;

    if (incrementID)
        pt->id = list.size()-1 ;
    // sinon c'est -1 par défaut
}

void ListTarget :: push_back_RealTarget( Target* pt, bool incrementID ) {

    TargetIntel targetintel ;

    targetintel.pt = pt ;
    targetintel.realTarget = true ;
    //targetintel.verify = false;
    list.push_back(targetintel);
//     m = list.size()-1 ;
//     if (is_generic_comment)
//         listPrincipalName.push_back(m) ;

    if (incrementID)
        pt->id = list.size()-1 ; // sinon c'est -1 par défaut
}

void ListTarget :: clear() {

    int i,n ;

    n = list.size();
    for(i=0;i<n;i++)
        if (list[i].realTarget)
            delete list[i].pt ;
    list.clear() ;
    listPrincipalName.clear() ;
}

/*inline*/ std::ostream &operator<<( std::ostream &os, ListTarget& t ) { 

    int i,n ;

    n = t.list.size() ;
    for(i=0;i<n;i++) {
        os << "+++++++++ TARGET ++++++++++++" << endl ;
        os << " name = |" << t.list[i].pt->name.name << "|" << std::endl ;
        os << " name principal = |" << t.list[i].pt->name.principalName << "|" << std::endl ;
        os << " adresse target = " << t.list[i].pt << std::endl ;
        //os << " verify = " << t.list[i].verify << std::endl ;
    }
    return os ;
} ;

int ListTarget :: isPrincipalName0( string& nom ) {

    int i,n ;

    n = listPrincipalName.size() ;
    for(i=0;i<n;i++)
        if (nom == list[listPrincipalName[i]].pt->name.principalName ) {
            return listPrincipalName[i] ;
        }
    return -1 ;
}

void ListTarget :: generate_listPrincipalName( string& path_generic_comment ) {

    vector<string> list_string_principalName;
    string stmp,tmp_type;
    int i,n,j,m,nb,indice;
    Target_type_without_genericComment* pt_without_gc ;
    Target* pttmp ;

//     cerr << "================" << endl ;
//     cerr << *this ;
//     cerr << "================" << endl ;


    n = list.size();
    for(i=0;i<n;i++) {
        stmp = list[i].pt->name.principalName;
        // je teste si ce nom n'est pas déjà traité.
        m = list_string_principalName.size();
        for(j=0;j<m;j++)
            if (list_string_principalName[j] == stmp)
                break;
        if (j<m) 
            continue;
        list_string_principalName.push_back(stmp);
        nb = nb_principalName(&indice,stmp);
        if (nb == 1)
            listPrincipalName.push_back(indice); // objet unique ! donc on le considère en quelque sorte générique ou principal
        if (nb > 1) {
            // Dans ce cas, plusieurs objets ont le même nom principal.
            // Soit il possède un commentaire générique, soit il n'en possède pas et dans ce cas il faudra lui en créer un d'office.
            pttmp = list[indice].pt;
            if (pttmp->of_generic_comment())
                listPrincipalName.push_back(indice);
            else {
                // on crée un target
                pt_without_gc = new Target_type_without_genericComment(path_generic_comment) ;
                pt_without_gc->name.principalName = stmp ;
                tmp_type = "unknow_type" ;
                if (pttmp->of_class())
                    tmp_type = "class";
                if (pttmp->of_struct())
                    tmp_type = "struct";
                if (pttmp->of_function())
                    tmp_type = "function";
                if (pttmp->of_tutorial())
                    tmp_type = "tutorial";
                if (pttmp->of_example())
                    tmp_type = "example";
                pt_without_gc->name.name = tmp_type + "_generic_comment_"+ stmp ;
                push_back_RealTarget( pt_without_gc,true);
                listPrincipalName.push_back(list.size()-1);
            }
        }
    }
}

void ListTarget :: set_type_of_listPrincipalName() {

    string stmp;
    int i,j,m,n;
    Target* pt;

    m = listPrincipalName.size() ;
    n = list.size() ;
    for(j=0;j<m;j++) {
        pt = list[listPrincipalName[j]].pt;
        if(pt->of_generic_comment() || pt->of_type_without_generic_comment()) {
            for(i=0;i<n;i++) {
                stmp = list[listPrincipalName[j]].pt->name.principalName ;
                if (list[i].pt->name.principalName == stmp) {
                    if (!list[i].pt->of_generic_comment()) {
                        list[listPrincipalName[j]].pt->ancestor = list[i].pt ;// list[listPrincipalName[j].pt contient donc le type de list[i].pt.
                        break;
                    }
                }
            }
        }
    }
}

Target* ListTarget :: isName( string& nom ) {

    int i,n,indice ;
    Target* ptr_t ;

    indice = isPrincipalName0( nom ) ;
    if (indice >=0)
        return list[indice].pt ;

    n = list.size() ;
    for(i=0;i<n;i++)
        if (nom == list[i].pt->name.name )  return list[i].pt ;
    return NULL ;
}

// void ListTarget :: setID() {
// 
//     int i,n,c ;
// 
//     n = list.size() ;
//     c = 0 ;
//     for(i=0;i<n;i++)
//         if (list[i].pt->id != NOT_ID) {
//             list[i].pt->id = c ;
//             c++ ;
//         }
// 
// }









