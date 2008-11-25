#ifndef OP_GET_BRIEF_FOR_NAME_H
#define OP_GET_BRIEF_FOR_NAME_H


//#include "pagecomment.h"
#include "op.h"
#include "listtargetcommentitem.h"

struct PageComment ;
//struct VisitorBloc_NameBaseClass ;
//struct CommentItemKeyword ;
//struct ListTargetcommentitem ;
struct CommentItemKeyword ;


struct OpGetBrief_for_Name : Op {
    OpGetBrief_for_Name( ) {  }
    virtual ~OpGetBrief_for_Name() ;
    virtual void operator()( PageComment* page ) ;
    void setName( const string p ) { name = p ; }


    string name ;

    ListTargetCommentItem<CommentItemKeyword> list ;
};

#endif

