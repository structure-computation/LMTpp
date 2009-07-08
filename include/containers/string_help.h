//
// C++ Interface: string_help
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_string_help_HEADER
#define LMT_string_help_HEADER

namespace LMT {

template<class T>
std::string to_string( const T &val, int precision ) {
    std::ostringstream os;
    os.precision( precision );
    os << val;
    return os.str();
}

template<class T>
std::string to_string( const T &val ) {
    std::ostringstream os;
    os << val;
    return os.str();
}

template<int val>
std::string to_string() {
    std::ostringstream os;
    os << val;
    return os.str();
}

inline void rm_commas( std::string &str ) {
    for(unsigned i=0;i<str.size();++i)
        if ( str[i] == ',' )
            str[i] = ' ';
}

inline std::string read_until_sp( const std::string &str, int off ) {
    std::string res; res.reserve( str.size() - off );
    while( off<str.size() and str[off]!=' ' )
        res += str[off++];
    return res;
}


};

#endif // LMT_string_help_HEADER
