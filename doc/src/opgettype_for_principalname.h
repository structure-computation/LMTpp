#ifndef OP_GET_TYPE_FOR_PRINCIPAL_NAME_H
#define OP_GET_TYPE_FOR_PRINCIPAL_NAME_H


//#include "pagecomment.h"
#include "op.h"
#include "listtargetcommentitem.h"

struct PageComment ;
//struct VisitorBloc_NameBaseClass ;
//struct CommentItemKeyword ;
//struct ListTargetcommentitem ;


/*

    cette classe permet de déterminer le type de l'objet générique de nom principal principal_name.
    Cela peut être :
     * un exemple;
     * un tutoriel;
     * une fonction;
     * une classe ou structure.

*/

struct OpGetType_for_principalName : Op {
    OpGetType_for_principalName() {}
    OpGetType_for_principalName( string& p ) { principal_name = p ; }
    virtual ~OpGetType_for_principalName() ;
    virtual void operator()( PageComment* page ) ;
    void setPrincipalName( string& p ) { principal_name = p ; }


    string principal_name ;

    /*
    type aura pour valeur :
        * example
        * tutorial
        * function
        * structure
        * bloc
        * unknown_type
    */
    string type ;
};

#endif

