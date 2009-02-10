#ifndef OP_INTERNAL_H
#define OP_INTERNAL_H

#include <map>
#include <string>

//#include "pagecomment.h"
#include "op.h"

struct PageComment ;
struct VisitorBloc_NameBaseClass ;
struct ListTarget ;



struct OpInternal : Op {
    OpInternal( ) { }
    virtual ~OpInternal() {}
    virtual void operator()( PageComment* page ) ;
};

#endif

