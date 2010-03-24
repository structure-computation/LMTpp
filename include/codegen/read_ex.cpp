#include "read_ex.h"
#include <sstream>
#include <assert.h>
#include <iostream>

using namespace std;

namespace Codegen {

bool is_space(char v) { return ( v==' ' || v=='\n' || v=='\t' || v=='\r' ); }
bool is_opera(char v) { return ( v=='+' || v=='*' || v=='-' || v=='/' || v=='^' ); }

struct Read_ex_atom {
    Read_ex_atom():ch(0),initialized(false) {}
    char ch;
    Ex op;
    string fu;
    unsigned column;
    bool initialized;
};

/// assumes that str.size()!=0
Read_ex_atom read_ex_look_for_symbol_or_number(const string &str,vector<Ex> &symbols,unsigned col) {
    if ( ( str[0]>='0' && str[0]<='9' ) || str[0]=='.' ) {
        Read_ex_atom res;
        istringstream ss( str );
        Ex::T tmp;
        ss >> tmp;
        res.op = number( tmp );
        res.column = col;
        res.initialized = true;
        return res;
    } 

    // look in function
    if ( is_a_function(str) && !is_opera(str[0]) ) {
        Read_ex_atom res;
        res.fu = str;
        res.column = col;
        res.initialized = true;
        return res;
    }

    // look in symbols
    for(unsigned i=0;i<symbols.size();++i) {
        if ( symbols[i].to_string() == str ) {
            Read_ex_atom res;
            res.op = symbols[i];
            res.column = col;
            res.initialized = true;
            return res;
        }
    }
    Read_ex_atom res;
    res.op = Codegen::symbol(str.c_str());
    res.column = col;
    res.initialized = true;
    symbols.push_back( res.op );
    return res;
}

void read_ex_strip_func(vector<Read_ex_atom> &strlist) {
    for(unsigned i=0;i<strlist.size();++i) {
        if ( strlist[i].fu.size()==0 )
            continue;
        if ( i+1==strlist.size() )
            throw Read_ex_error( "Function "+strlist[i].fu+"() is not followed by any expression.", strlist[i].column );
        Ex o = strlist[i+1].op;
        if ( ! strlist[i+1].initialized )
            throw Read_ex_error( "Function "+strlist[i].fu+"() is not followed by a valid expression.", strlist[i].column );
        if ( is_a_function_1(strlist[i].fu) ) {
            strlist[i].op = new_function_1(strlist[i].fu,o);
            strlist.erase( strlist.begin()+i+1, strlist.begin()+i+2 );
        }
        else if ( is_a_function_2(strlist[i].fu) ) {
            Ex o2 = strlist[i+2].op;
            if ( ! strlist[i+2].initialized )
                throw Read_ex_error( "Function "+strlist[i].fu+"() is not followed by enough valid expressions.", strlist[i].column );
            strlist[i].op = new_function_2(strlist[i].fu,o,o2);
            strlist.erase( strlist.begin()+i+1, strlist.begin()+i+3 );
        }
    }
}

/// Take the next op and replace current by neg(next_op).
/// it works because (-x)*y == -x*y and (-x)/y == -x/y and ...
void read_ex_strip_neg(vector<Read_ex_atom> &strlist) throw(Read_ex_error) {
    for(unsigned i=strlist.size()-1;i>0;--i) {
        if ( strlist[i].ch!='-' || strlist[i-1].ch==0 )
            continue;
        if ( i==strlist.size()-1 )
            throw Read_ex_error( string("Lonely operator of type -"), strlist[i].column );
        Ex o = strlist[i+1].op;
        if ( ! strlist[i+1].initialized )
            throw Read_ex_error( string("A - operator must be followed by at least one expression."), strlist[i].column );
        strlist[i].op = neg( o );
        strlist.erase( strlist.begin()+i+1, strlist.begin()+i+2 );
    }
}

void read_ex_strip_op(vector<Read_ex_atom> &strlist,char t) throw(Read_ex_error) {
    for(unsigned i=0;i<strlist.size();++i) {
        if ( strlist[i].ch!=t )
            continue;
        if ( i==strlist.size()-1 )
            throw Read_ex_error( string("Lonely operator of type ")+t, strlist[i].column );
        if ( i==0 ) {
            if ( t!='-' )
                throw Read_ex_error( string("Lonely operator of type ")+t, strlist[i].column );
            Ex o = strlist[i+1].op;
            if ( ! strlist[i+1].initialized )
                throw Read_ex_error( string("A - operator must be followed by at least one expression."), strlist[i].column );
            strlist[i].op = neg( o );
            strlist.erase( strlist.begin()+i+1, strlist.begin()+i+2 );
            continue;
        }
        Ex o1 = strlist[i-1].op;
        Ex o2 = strlist[i+1].op;
        if ( strlist[i-1].initialized==false || strlist[i+1].initialized==false )
            throw Read_ex_error( string("An operator must be between two expressions."), strlist[i].column );
        switch ( t ) {
            case '^':
                strlist[i-1].op = pow(o1,o2);
                strlist.erase( strlist.begin()+i, strlist.begin()+i+2 );
                --i;
                break;
            #define ROSO(T,O)                                                 \
                case T:                                                       \
                    strlist[i-1].op = o1 O o2;                                \
                    strlist.erase( strlist.begin()+i, strlist.begin()+i+2 );  \
                    --i;                                                      \
                    break;
            ROSO('/',/)
            ROSO('*',*)
            ROSO('+',+)
            ROSO('-',-)
            #undef ROSO
        }
    }
}

Ex read_ex(const string &str,vector<Ex> &symbols,unsigned offsetCol) throw(Read_ex_error) {
    string tmp;
    vector<Read_ex_atom> strlist;
    for(unsigned i=0;;++i) {
        if ( str[i]==')' )
            throw Read_ex_error( ") without (.", i );
        if ( i==str.size() || is_space(str[i]) || (is_opera(str[i]) and (i==0 or str[i-1]!='e' or str[i]!='-')) || str[i]=='(' ) {
            if ( tmp.size() ) {
                //std::cout << " -> " << tmp << std::endl;
                strlist.push_back( read_ex_look_for_symbol_or_number(tmp,symbols,i+offsetCol) );
                tmp.clear();
            }
            if ( i==str.size() )
                break;
            if ( is_opera(str[i]) ) {
                Read_ex_atom res;
                if ( str[i+1]=='*' ) {
                    res.ch = '^';
                    ++i;
                }
                else
                    res.ch = str[i];
                res.initialized = true;
                strlist.push_back( res );
            }
            else if ( str[i]=='(' ) {
                unsigned nb_par = 1;
                unsigned beg_e = i+1;
                while ( nb_par ) {
                    ++i;
                    if ( i==str.size() )
                        throw Read_ex_error( "too much ( -- i.e too few ).", beg_e );
                    if ( str[i]==',' && nb_par==1 ) {
                        string nstr( str.begin()+beg_e,str.begin()+i );
                        Read_ex_atom res;
                        res.op = read_ex(nstr,symbols,beg_e);
                        res.initialized = true;
                        strlist.push_back( res );
                        beg_e = i+1;
                    }
                    else {
                        nb_par -= (str[i]==')');
                        nb_par += (str[i]=='(');
                    }
                }
                string nstr( str.begin()+beg_e,str.begin()+i );
                Read_ex_atom res;
                res.op = read_ex(nstr,symbols,beg_e);
                res.initialized = true;
                strlist.push_back( res );
            }
        }
        else {
            tmp += str[i];
        }
    }
    read_ex_strip_func(strlist);
    
    read_ex_strip_neg(strlist);
    
    read_ex_strip_op(strlist,'^');
    read_ex_strip_op(strlist,'/');
    read_ex_strip_op(strlist,'*');
    read_ex_strip_op(strlist,'-');
    read_ex_strip_op(strlist,'+');
    
    if ( strlist.size()>=2 ) {
        ostringstream ss;
        ss << "superfluous symbol at column " << strlist[1].column;
        throw Read_ex_error( ss.str(), strlist[1].column );
    }
    if ( strlist.size()==0 || strlist[0].initialized==false )
        throw Read_ex_error( "need at least one symbol or one number", 0 );
    return strlist[0].op;
}

};


