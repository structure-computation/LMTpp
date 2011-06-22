#include <iostream>
#include <string>
#include <vector>


using namespace std;
#include "token.h"
#include "op.h"
#include "bloc.h"
#include "functionmetil.h"
#include "parameter.h"
#include "templateparameter.h"
#include "op.h"

FunctionMetil::~FunctionMetil() {
 
//     int i;
//     
//     for(i=0;i<listParameter.size();i++) {
//         delete listParameter[i];
//     }
 
}
 
void FunctionMetil::display( std::ostream &os ) {

    int i,n;
    
    os << "### FONCTION METIL ### "  << endl;
    os << " namespace            = " << _namespace << endl;
    os << " name                 = " << name.name << endl;
    os << " name principal       = " << name.principalName << endl;
    //os << " hash                 = " << name.hash << endl; 
    os << " returnType           = " << returnType.name << endl;
    os << " returnType principal = " << returnType.principalName << endl;
    os << " attribut             = " << listAttribut << endl;
    os << " portee               = " << portee << endl;
    os << " path = " << path << endl;
    os << " id = " << id << endl;
    os << " reference() = " << reference() << endl;
    n = listTag.size();
    if (n>0) {
        for(i=0;i<n;i++) {
        os << " tag n° " << listTag[i] << endl;
        }
    }
    n = listTemplateParameter.size();
    if (n>0) {
        os << "        liste des paramètres template de la fonction " << name.name << endl;
        for(i=0;i<n;i++) {
            os << "        paramètre no " << i << endl;
            os << "        - type           = " << listTemplateParameter[i]->type << endl;
            os << "        - name           = " << listTemplateParameter[i]->name << endl;
            os << "        - defaut         = " << listTemplateParameter[i]->defaultType << endl;
        }
    }
    n = listParameter.size();
    if (n>0) {
        os << "        liste des paramètres de la fonction " << name.name << endl;
        for(i=0;i<n;i++) {
            os << "        paramètre no " << i << endl;
            os << "        - attribut       = " << listParameter[i].listAttribut << endl;
            os << "        - type           = " << listParameter[i].type.name << endl;
            os << "        - type principal = " << listParameter[i].type.principalName << endl;
            os << "        - name           = " << listParameter[i].nameVariable << endl;
            os << "        - defaultType    = " << listParameter[i].defaultType << endl;
        }
    }
    
}


 
 
 
 
 
 
