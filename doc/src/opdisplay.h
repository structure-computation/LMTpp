#ifndef OP_DISPLAY_H
#define OP_DISPLAY_H

//struct Op ;
#include "op.h"

struct OpDisplay : public Op {
    virtual void apply( std::string s ) { std::cout << s << std::endl; }
    virtual ~OpDisplay() {}
} ;


#endif

