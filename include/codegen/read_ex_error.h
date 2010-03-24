#ifndef CODEGEN_READ_EX_ERROR_H
#define CODEGEN_READ_EX_ERROR_H

#include <string>

namespace Codegen {

struct Read_ex_error {
    Read_ex_error(const std::string &err_,unsigned column_) : err(err_),column(column_) {}
    std::string what() const { return err; }
    std::string err;
    unsigned column;
};

};

#endif // CODEGEN_READ_EX_ERROR_H
