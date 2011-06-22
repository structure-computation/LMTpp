#ifndef OP_ALL_EXAMPLE_H
#define OP_ALL_EXAMPLE_H


//#include "pagecomment.h"
#include "op.h"

struct PageComment ;
struct VisitorBloc_NameBaseClass ;
struct ListTarget ;



struct OpAllExample : Op {
    OpAllExample( ListTarget* pllink  ) { ptr_list_target = pllink ; }
    virtual ~OpAllExample() {}
    virtual void operator()( PageComment* page ) ;

  


    ListTarget* ptr_list_target ;
};

#endif

