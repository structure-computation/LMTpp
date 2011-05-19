#ifndef OP_HTML_H
#define OP_HTML_H

struct PageComment ;
//#include "pagecomment.h"
#include "op.h"

struct OpHtml : Op {
    OpHtml() {} 
    virtual ~OpHtml() {}
    virtual void operator()( PageComment* page ) ;
  



};

#endif

