#ifndef OP_ALL_TUTORIAL_H
#define OP_ALL_TUTORIAL_H

#include <map>
#include <string>

//#include "pagecomment.h"
#include "op.h"

struct PageComment ;
struct VisitorBloc_NameBaseClass ;
struct ListTarget ;



struct OpAllTutorial : Op {
    OpAllTutorial( ListTarget* pllink, map<string,string>* pt  ) { ptr_list_target = pllink ; ptr_tree = pt ; }
    virtual ~OpAllTutorial() {}
    virtual void operator()( PageComment* page ) ;

  


    ListTarget* ptr_list_target ;
    map<string,string>* ptr_tree ;
};

#endif

