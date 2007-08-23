#include "write_code_language_cpp.h"
#include <sstream>
#include <iostream>

using namespace std;

namespace Codegen {

Write_code_language_cpp::Write_code_language_cpp(const std::string tmp_type_,unsigned nb_spaces_):
          tmp_type(tmp_type_) {
    nb_spaces = nb_spaces_;
    nb_registers = 0;
    nb_written_lines = 0;
    nb_exp_to_end_line = 5;
}

void Write_code_language_cpp::write_ex(std::ostream &os,const Ex &ex,unsigned nb_times_ex_will_be_used) {
    
    // we don't store symbols and number in registers
    if ( ex.nb_children()==0 ) {
        write_var(os,ex,ex.to_string()+";");
        return;
    }
        
    // free preceding registers assigned to child will not be used anymore
    int freed_reg = -1;
    unsigned num_reg_children[2];
    for(unsigned i=0;i<ex.nb_children();++i) {
        if ( ex.child(i).nb_children()==0 )
            continue;
        std::map<Ex,Reg,Ex::ExMapCmp>::iterator iter = registers.find(ex.child(i));
        num_reg_children[i] = iter->second.number;
        if ( --iter->second.nb_times_ex_will_be_used == 0 ) {
            freed_reg = iter->second.number;
            free_registers.insert( freed_reg );
            registers.erase( iter );
        }
    }

    // if it will be reused, we will need to choose or allocate a register to store the var
    if ( nb_times_ex_will_be_used ) {
        write_beg_spaces(os);
        // get new register
        Reg reg;
        reg.nb_times_ex_will_be_used = nb_times_ex_will_be_used;
        if ( free_registers.empty() ) {
            reg.number = nb_registers++;
            os << tmp_type << ' ';
        }
        else {
            if ( freed_reg >= 0 ) {
                reg.number = freed_reg;
                free_registers.erase( freed_reg );
            }
            else {
                reg.number = *free_registers.begin();
                free_registers.erase( free_registers.begin() );
            }
        }
        registers[ex] = reg;
    
        // write
        os << "reg" << reg.number;
        os << "=";
        write_end_line(os,ex,num_reg_children);
        write_endl(os);
        
        ostringstream ss;
        ss << "reg" << reg.number << ";";
        write_var(os,ex,ss.str());
    }
    else {
        ostringstream ss;
        write_end_line(ss,ex,num_reg_children);
        write_var(os,ex,ss.str());
    }

}

void Write_code_language_cpp::write_end_line(std::ostream &os,const Ex &ex,unsigned *num_reg_children) {
    if ( ex.nb_children()==0 ) // hum
        os << ex.graphviz_repr() << "";
    else if ( ex.nb_children()==1 ) {
        std::string gr( ex.graphviz_repr() );
        
        std::ostringstream c;
        if ( ex.child(0).nb_children()==0 ) c << ex.child(0).to_string();
        else                                c << "reg" << num_reg_children[0];
        
        if ( gr=="-" )
            os << "-" << c.str() << "";
        else if ( gr=="heavyside" )
            os << "(" << c.str() << ">=0)";
        else
            os << gr << "(" << c.str() << ")";
    }
    else if ( ex.nb_children()==2 ) {
        std::string gr( ex.graphviz_repr() );
        std::ostringstream c1,c2;
        if ( ex.child(0).nb_children()==0 ) c1 << ex.child(0).to_string();
        else                                c1 << "reg" << num_reg_children[0];
        if ( ex.child(1).nb_children()==0 ) c2 << ex.child(1).to_string();
        else                                c2 << "reg" << num_reg_children[1];
        
        if ( gr=="+" || gr=="*" || gr=="-" || gr=="/" )
            os << c1.str() << gr << c2.str() << "";
        else if ( gr=="**" ) {
            if ( ex.child(1) == -1 )
                os << "1.0/" << c1.str() << "";
            else
                os << "pow(" << c1.str() << "," << c2.str() << ")";
        }
        else
            os << gr << "(" << c1.str() << "," << c2.str() << ")";
    }
    os << ";";
}

void Write_code_language_cpp::write_beg_spaces(std::ostream &os) {
    if ( ( nb_written_lines % nb_exp_to_end_line ) == 0 )
        for(unsigned j=0;j<nb_spaces;++j)
            os << ' ';
    else
        os << ' ';
}
void Write_code_language_cpp::write_endl(std::ostream &os) {
    if ( ( nb_written_lines++ % nb_exp_to_end_line ) == nb_exp_to_end_line-1 )
        os << "\n";
}
bool Write_code_language_cpp::has_put_endl() const {
    return ( ( nb_written_lines % nb_exp_to_end_line ) == 0 );
}

void Write_code_language_cpp::write_var(std::ostream &os,const Ex &ex,const std::string &end) {
    for(unsigned i=0;i<lst_var->size();++i) {
        if ( (*lst_var)[i].ex == ex ) {
            write_beg_spaces(os);
            switch ( (*lst_var)[i].method ) {
                case Write_code::Declare:
                    os << tmp_type << ' ' << (*lst_var)[i].name << "=" << end; break;
                case Write_code::Set:
                    os << (*lst_var)[i].name << "=" << end; break;
                case Write_code::Add:
                    os << (*lst_var)[i].name << "+=" << end; break;
                case Write_code::Sub:
                    os << (*lst_var)[i].name << "-=" << end; break;
                case Write_code::Return:
                    os << "return " << end; break;
            }
            write_endl(os);
        }
    }
}

};
