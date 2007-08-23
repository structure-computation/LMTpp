#ifndef CODEGEN_READ_OP_H
#define CODEGEN_READ_OP_H

#include "ex.h"
#include "read_ex_error.h"

namespace Codegen {

/// offsetCol is used to get real column in Read_ex_error
Ex read_ex(const std::string &str,std::vector<Ex> &symbols,unsigned offsetCol=0) throw(Read_ex_error);

};

#endif // CODEGEN_READ_OP_H
