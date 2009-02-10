#ifndef OP_H
#define OP_H

struct PageComment ;
//#include "pagecomment.h"

struct Op {
    Op() {} 
    virtual ~Op() {}
    virtual void operator()( PageComment* page ) {}
  



};

#endif

