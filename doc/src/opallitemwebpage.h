#ifndef OP_ALL_WEBPAGE_H
#define OP_ALL_WEBPAGE_H

#include<map>
#include<string>

#include "op.h"
#include "listtargetcommentitem.h"
#include "listtarget.h"
//struct ListTargetCommentItem ;
struct Target ;

/// REMARQUE IMPORTANTE : cette classe augmente la liste ListTarget du projet.


struct OpAllItemWebPage : Op {
    OpAllItemWebPage( ListTarget* plt,map<string,string>* pt ) { ptr_list_Target = plt ; ptr_tree = pt ; }
    virtual ~OpAllItemWebPage() {}
    virtual void operator()( PageComment* page ) ;
    //void setListTarget_commentItem( ListTargetCommentItem<CommentItemKeyword>* pltci ) { ptr_list_Target_CommentItem = pltci ; } 
    //void setType (string& t) { type = t ; }
    //void generate_webPage_of_generic_object_without_generic_comment() ;
    //void generate_web_page_of_created_generic_comment( Target* pt ) ;

    ListTarget* ptr_list_Target ;
    map<string,string>* ptr_tree ;
};

#endif

