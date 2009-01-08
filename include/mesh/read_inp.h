//
// C++ Interface: %{MODULE}
//
// Description:
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_READ_INP_HEADER
#define LMT_READ_INP_HEADER

#include "mesh/hexa.h"
#include "mesh/tetra.h"
#include "mesh/wedge.h"
#include "mesh/tetra_10.h"
#include "containers/indexof.h"

#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>

namespace LMT {

/// remplace dans str les caractères c par subs.
void replace( std::string& str, char c, char subs) {

    int i=0,i2,n=str.size();
    while ( (i2=str.find(c,i)) != std::string::npos) {
        str[i2] = subs;
        i = i2;
    }
}


/*!
    Cette fonction lit un fichier ABAQUS puis construit le maillage m.
    <strong> ATTENTION </strong> : pour l'instant on ne traite que les noeuds et les éléments de type C3D4.

    \friend raphael.pasquier@lmt.ens-cachan.fr
*/
template<class TM> void read_inp( TM &m, const std::string &fic_name ) {
    using namespace std;
    typedef typename TM::Pvec Pvec;
    typedef typename TM::TNode TNode;
    static const int dim = TM::dim;
    string str;
    int number,nb_nodes;
    Pvec vec;
    LMT::Vec<TNode *> vn;
    // correspondance between number in file -> ref in mesh
    map<int,TNode *> map_num_node;

    str.reserve(512);
    // ouverture du fichier
    std::ifstream is( fic_name.c_str() );
    if ( ! is.is_open() )
        throw std::runtime_error( "opening of "+fic_name+" has failed." );

    // état de l'automate
    int ctxte=0;

    while ( true ) {

        str.clear();
        getline ( is,str );
        if ( !is.good() )
            break;

        // évaluation du contexte
        if (str[0] == '*') {
            if ( str.find ( "Node" ) < str.size() ) {
                ctxte = 1;
                continue;
            }
            if ( str.find ( "Element" ) < str.size() ) {
                ctxte = 2;
                nb_nodes = 4; /// ATTENTION : pour l'instant on ne parse que les éléments de type C3D4 i.e. probablement de type tétraèdre
                vn.resize ( nb_nodes );
                continue;
            } else {
                ctxte = 0; // on ignorera ce bloc
                continue;
            }
        }

        // utilisation du contexte
        if ( ctxte==1 ) { /// node
            replace(str,',',' ');
            istringstream s( str );
            s >> number;
            for ( int di=0;di<dim;di++ )
                s >> vec[di];
            // we add the node and we retain is ref
            map_num_node[number] = m.add_node( vec );
            continue;
        }
        if ( ctxte==2 ) { /// seulement les éléments de type C3D4
            replace(str,',',' ');
            istringstream s( str );
            s >> number;
            for ( unsigned i=0;i<nb_nodes;i++ ) {
                s >> number;
                vn[i] = map_num_node[number];
            }
            permutation_if_jac_neg ( Tetra(), vn.ptr() );
            m.add_element( Tetra(),DefaultBehavior(),vn.ptr() );
            continue;
        }
    }
}

}
#endif // LMT_READ_INP_HEADER

