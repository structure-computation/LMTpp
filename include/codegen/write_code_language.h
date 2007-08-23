#ifndef WRITE_CODE_LANGUAGE_H
#define WRITE_CODE_LANGUAGE_H

#include "write_code.h"

namespace Codegen {

/**
    Base class to specify how to get specific code for particular language (c++, python, ...).
*/
class Write_code_language {
public:
    typedef Write_code::Method Method;
    typedef Write_code::Var Var;
    
    virtual ~Write_code_language() {}
    virtual void write_ex(std::ostream &os,const Ex &ex,unsigned nb_times_ex_will_be_used) = 0;
    // return true if after write_ex, *this has put an endline
    virtual bool has_put_endl() const { return true; }
    
    virtual Write_code_language *copy( unsigned nb_space_sup, Write_code &par ) const = 0;
    virtual std::string write_declaration( const std::string &name ) const = 0;
    
    std::vector<Var> *lst_var;
    unsigned nb_spaces;
};

};

#endif // WRITE_CODE_LANGUAGE_H
