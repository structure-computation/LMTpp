#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "token.h"
#include "op.h"
#include "classe.h"
#include "parameter.h"
#include "templateparameter.h"
#include "names.h"


Classe :: ~Classe() /*: ~Bloc()*/ {

//     int i ;
//     
//     for(i=0;i< listHerited.size() ;i++) {
//         delete listHerited[i] ;
//     }
}

void Classe :: display( std::ostream &os ) {

    int i,n,m,j ;
    
    os << "### CLASSE ### "<< endl ;
    os << " namespace = " << _namespace << endl ;
    os << " name = " << name.name << endl ;
    os << " name principal = " << name.principalName << endl ;
    os << " portee = " << portee << endl ;
    os << " path = " << path << endl ;
    os << " id = " << id << endl ;
    os << " reference() = " << reference() << endl ;
    n = listTag.size() ;
    if (n>0) {
        for(i=0;i<n;i++) {
        os << " tag n° " << listTag[i] << endl ;
        }
    }
    n = listTemplateParameter.size() ;
    if (n>0) {
        os << "* liste des paramètres template" << endl ;
        for(i=0;i<n;i++) {
            os << "    paramètre n° " << i << endl ;
            os << "    - type = " << listTemplateParameter[i]->type << endl ;
            os << "    - name = " << listTemplateParameter[i]->name << endl ;
            os << "    - defa = " << listTemplateParameter[i]->defaultType << endl ;
        }
    }
    n = listHerited.size() ;
    if (n>0) {
        os << "* liste des héritages" << endl ;
        for(i=0;i<n;i++) {
            os << "    membre n° " << i << endl ;
            os << "    - attribut       = " << listHerited[i].listAttribut << endl ;
            os << "    - type           = " << listHerited[i].type.name << endl ;
            os << "    - type principal = " << listHerited[i].type.principalName << endl ;
        }
    }
    n = listTypedef.size() ;
    if (n>0) {
        os << "* liste des typedef" << endl ;
        for(i=0;i<n;i++) {
            os << "    typedef no " << i << endl ;
            os << "    - type           = " << listTypedef[i].type.name << endl ;
            os << "    - type principal = " << listTypedef[i].type.principalName << endl ;
            os << "    - synonyme       = " << listTypedef[i].nameVariable << endl ;
        }
    }
    n = listMember.size() ;
    if (n>0) {
        os << "* liste des membres" << endl ;
        for(i=0;i<n;i++) {
            os << "    membre no " << i << endl ;
            os << "    - attribut       = " << listMember[i].listAttribut << endl ;
            os << "    - type           = " << listMember[i].type.name << endl ;
            os << "    - type principal = " << listMember[i].type.principalName << endl ;
            os << "    - name           = " << listMember[i].nameVariable << endl ;
            os << "    - defaultType    = " << listMember[i].defaultType << endl ;
            m = listMember[i].listTag.size() ;
            if (m>0) {
                for(j=0;j<m;j++) {
                    os << " tag n° " << listMember[i].listTag[j] << endl ;
                }
            }
        }
    }
    n = list_subType_function.size() ;
    if (n>0) {
        os << "* liste des structures ou des fonctions membres" << endl ;
        for(i=0;i<n;i++) {
            os << "    n° " << i << endl ;
            os << *list_subType_function[i] << endl ;
        }
    }

}














