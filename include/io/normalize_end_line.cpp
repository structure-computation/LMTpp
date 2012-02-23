//
// C++ Interface: lineoutput
//
// Description: 
//
//
// Author: Jérémie Bellec <j.bellec@structure-computation.com>, (C) 2012
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "normalize_end_line.h"

namespace LMT {

void normalize_end_line( std::string& str ) {
    size_t pos = str.size() - 1;
    while( ( pos >= 1 ) and ( ( str[ pos ] == 13 ) or ( str[ pos ] == ' ' ) ) ) pos--;
    str.resize( pos + 1 );
}


};

