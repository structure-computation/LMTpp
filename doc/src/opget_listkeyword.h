#ifndef OP_GET_LIST_KEYWORD_H
#define OP_GET_LIST_KEYWORD_H

#include <map>

#include "op.h"
#include "listtargetcommentitem.h"
#include "listmultitarget.h"
struct PageComment;
struct ListTargetByType;

/*!

Cette classe permet d'avoir la liste des mot-clés des commentaires.

*/

struct OpGet_listKeyword : Op {
    OpGet_listKeyword() {}
    virtual ~OpGet_listKeyword();
    virtual void operator()( PageComment* page );

    map<string,ListTargetByType> list_keyword;
};

#endif

