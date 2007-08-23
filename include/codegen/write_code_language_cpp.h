#ifndef WRITE_CODE_LANGUAGE_CPP_H
#define WRITE_CODE_LANGUAGE_CPP_H

#include "write_code_language.h"

namespace Codegen {

/**
*/
class Write_code_language_cpp : public Write_code_language {
public:
    Write_code_language_cpp(const std::string tmp_type_="T",unsigned nb_spaces_=4);
    virtual ~Write_code_language_cpp() {}
    virtual void write_ex(std::ostream &os,const Ex &ex,unsigned nb_times_ex_will_be_used);
    virtual bool has_put_endl() const;
    virtual Write_code_language *copy( unsigned nb_space_sup, Write_code &par ) const {
        Write_code_language_cpp *res = new Write_code_language_cpp;
        res->nb_spaces = nb_spaces + nb_space_sup;
        res->tmp_type = tmp_type;
        res->lst_var = &par.lst_var;
        return res;
    }
    virtual std::string write_declaration( const std::string &name ) const {
        return tmp_type + " " + name + ";";
    }
private:
    struct Reg {
        int number;
        unsigned nb_times_ex_will_be_used;
    };
    std::set<int> free_registers;
    std::map<Ex,Reg,Ex::ExMapCmp> registers;
    unsigned nb_written_lines;
    
    std::string tmp_type;
    unsigned nb_registers;
    unsigned nb_exp_to_end_line;
    
    void write_end_line(std::ostream &os,const Ex &ex,unsigned *num_reg_children);
    void write_var(std::ostream &os,const Ex &ex,const std::string &end);
    void write_beg_spaces(std::ostream &os);
    void write_endl(std::ostream &os);
};

};

#endif // WRITE_CODE_LANGUAGE_CPP_H
