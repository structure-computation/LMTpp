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

};

#endif // LMT_string_help_HEADER
