#ifndef OP_GET_BRIEF_FOR_PRINCIPAL_NAME_H
#define OP_GET_BRIEF_FOR_PRINCIPAL_NAME_H


//#include "pagecomment.h"
#include "op.h"
#include "listtargetcommentitem.h"

struct PageComment ;
struct ListParameter ;
//struct VisitorBloc_NameBaseClass ;
//struct CommentItemKeyword ;
//struct ListTargetcommentitem ;


struct OpGetBrief_for_principalName : Op {
    OpGetBrief_for_principalName( const string& p ) { principal_name = p ; }
    virtual ~OpGetBrief_for_principalName() ;
    virtual void operator()( PageComment* page ) ;
    void setPrincipalName( const string& p ) { principal_name = p ; }


    string principal_name ;

    ListTargetCommentItemInfo<CommentItemKeyword,ListParameter> list ;
};

#endif

