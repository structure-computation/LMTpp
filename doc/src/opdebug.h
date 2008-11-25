#ifndef OP_DEBUG_H
#define OP_DEBUG_H

struct PageComment ;
//#include "pagecomment.h"
#include "op.h"

struct OpDebug : Op {
    OpDebug() {} 
    virtual ~OpDebug() {}
    virtual void operator()( PageComment* page ) ;
  



};

#endif

