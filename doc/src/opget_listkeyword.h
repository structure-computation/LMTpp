#ifndef OP_GET_LIST_KEYWORD_H
#define OP_GET_LIST_KEYWORD_H

#include <map>
//#include "pagecomment.h"
#include "op.h"
#include "listtargetcommentitem.h"
#include "listmultitarget.h"
struct PageComment ;
//struct VisitorBloc_NameBaseClass ;
//struct CommentItemKeyword ;
//struct ListTargetcommentitem ;
struct ListTargetByType ;

/*!

Cette classe permet d'avoir la liste des mot-clés des commentaires.

*/

/*
struct List_type_target{

    string keyword ;
    vector<Target*> list_example ;
    vector<Target*> list_tutorial ;
    vector<Target*> list_generic_comment ;
    vector<Target*> list_class_struct ;
    vector<Target*> list_function ;
} ;
*/

struct OpGet_listKeyword : Op {
    OpGet_listKeyword() {}
    virtual ~OpGet_listKeyword() ;
    virtual void operator()( PageComment* page ) ;

    //vector<ListMultiTarget<string>* > list_keyword ;
    //vector<List_type_target*> list_keyword ;
    map<string,ListTargetByType> list_keyword ;
};

#endif

