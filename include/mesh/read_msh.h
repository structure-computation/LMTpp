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
#ifndef LMT_READ_GID_HEADER
#define LMT_READ_GID_HEADER

#include "mesh/hexa.h"
#include "mesh/tetra.h"

#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <stdexcept>

namespace LMT {

/// put gmsh mesh in m
template<class TM>
void read_msh(TM &m,std::istream &is) throw(std::runtime_error) {
    using namespace std;
    typedef typename TM::Pvec Pvec;
    typedef typename TM::TNode TNode;
    static const int dim = TM::dim;

    //
    int ctxte=0;

    // correspondance between number in file -> ref in mesh
    map<int,TNode *> map_num_node;
    string type_element;
    //
    while (1) {
        if (! is )
            throw std::runtime_error("msh file is corrupted : mark 'end elements' is absent");

        string str;
        getline(is,str);

        // �aluation du contexte
        if (str.find("$ENDNOD")<str.size()) {
            ctxte=0;
            continue;
        }
        if (str.find("$ENDELM")<str.size()) {
            break;
        }
        if (str.find("$NOD")<str.size()) {
            getline(is,str);
            ctxte=1;
            continue;
        }
        if (str.find("$ELM")<str.size()) {
            getline(is,str);
            ctxte=2;
            continue;
        }

        // utilisation du contexte
        if (ctxte==1) {
            istringstream s(str);
            int number;
            s >> number;
            Pvec vec;
            for(int di=0;di<dim;di++)
                s >> vec[di];
            // we add the node and we retain is ref
            map_num_node[number] = m.add_node(vec);
            continue;
        }
        if (ctxte==2) {
            istringstream s(str);
            int number;
            s >> number;
            int nb_nodes, type_elem;
            s >> type_elem >> nb_nodes >> nb_nodes >> nb_nodes;
            
            LMT::Vec<TNode *> vn; vn.resize(nb_nodes);
            for(int i=0;i<nb_nodes;i++) {
                s >> number;
                vn[i] = map_num_node[number];
            }
            
            if ( type_elem == 1 ) { // TODO
                if ( TM::dim == 1 )
                    m.add_element(Bar(),DefaultBehavior(),vn.ptr());
            }
            else if ( type_elem == 2 ) {
                permutation_if_jac_neg(Triangle(),vn.ptr());
                m.add_element(Triangle(),DefaultBehavior(),vn.ptr());
            }
            else {
                std::cout << "unknown type elem." << std::endl;
                assert(0);
            }

            continue;
        }
    }
}


/// put gid mesh in m
template<class TM>
void read_msh(TM &m,const std::string &fic_name) throw(std::runtime_error) {
    // ouverture du fichier
    std::ifstream my_file( fic_name.c_str() );
    if ( ! my_file.is_open() )
        throw std::runtime_error( "opening of "+fic_name+" has failed.");
    return read_msh(m,my_file);
}


};

#endif // LMT_READ_GID_HEADER

