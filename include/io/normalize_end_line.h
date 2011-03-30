//
// C++ Interface: lineoutput
//
// Description: 
//
//
// Author: raphaël Pasquier <pasquier@lmt.ens-cachan.fr>, (C) 2011
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_normalize_end_line_HEADER
#define LMT_normalize_end_line_HEADER

#include <string>

namespace LMT {

/*!
    lorsque une ligne d'un fichier texte DOS est lue, il reste le caractère CR Carriage Return ( code ASCII 13 ) qui gène la récupèration des nombres de la ligne. Il est donc nécessaire de le retirer. On supprime aussi les espaces pour une meilleure lecture.
*/
void normalize_end_line( std::string& str ) {
    size_t pos = str.size() - 1;
    while( ( pos >= 1 ) and ( ( str[ pos ] == 13 ) or ( str[ pos ] == ' ' ) ) ) pos--;
    str.resize( pos + 1 );
}


};

#endif // LMT_normalize_end_line_HEADER
