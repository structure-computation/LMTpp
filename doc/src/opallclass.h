#ifndef OP_ALL_CLASS_H
#define OP_ALL_CLASS_H

#include <map>
#include <string>

//#include "pagecomment.h"
#include "op.h"

struct PageComment ;
struct VisitorBloc_NameBaseClass ;
struct ListTarget ;



struct OpAllClass : Op {
    OpAllClass( ListTarget* pllink, map<string,string>* pt  ) { ptr_list_target = pllink ; ptr_tree = pt ; }
    virtual ~OpAllClass() {}
    virtual void operator()( PageComment* page ) ;

  


    ListTarget* ptr_list_target ;
    map<string,string>* ptr_tree ;
};

#endif

