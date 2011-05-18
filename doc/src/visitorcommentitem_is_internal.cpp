#include <iostream>
#include <string>
#include <vector>


using namespace std ;

#include "visitorcommentitem_is_internal.h"
#include "commentitemkeyword.h"
//#include "commentitemtutorial.h"
//#include "comment.h"

void VisitorCommentItem_isInternal::function_at_CommentItemKeyword( CommentItemKeyword* c ) {

    if (c->name.principalName == "internal")
        if (parent != NULL)
            parent->property = 1; 
}





