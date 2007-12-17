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
#ifndef LMT_READ_GID2_HEADER
#define LMT_READ_GID2_HEADER

#include "mesh/hexa.h"
#include "mesh/tetra.h"
#include "mesh/wedge.h"

#include <fstream>
#include <map>
#include <sstream>
#include <vector>
#include <stdexcept>

namespace LMT {

///
template<class TE,class VarTag,unsigned n,unsigned m>
void assign_tag_values( TE *e, const Vec<double> &tag_values, const VarTag &vt, Number<n>, Number<m> ) {
    ExtractDM<typename VarTag::template SubType<n>::T> ev;
    ev( *e ) = tag_values[ n ];
    assign_tag_values( e, tag_values, vt, Number<n+1>(), Number<m>() );
}
template<class TE,class VarTag,unsigned n           > void assign_tag_values( TE   *e, const Vec<double> &tag_values, const VarTag &vt, Number<n>, Number<n> ) { }
template<         class VarTag,unsigned n,unsigned m> void assign_tag_values( void *e, const Vec<double> &tag_values, const VarTag &vt, Number<n>, Number<m> ) { }
template<         class VarTag,unsigned n           > void assign_tag_values( void *e, const Vec<double> &tag_values, const VarTag &vt, Number<n>, Number<n> ) { }

/// put gmsh mesh in m
template<class TM,class VarTag>
void read_msh_2( TM &m,std::istream &is, unsigned nvi, const VarTag &vt ) throw ( std::runtime_error ) {
    using namespace std;
    typedef typename TM::Pvec Pvec;
    typedef typename TM::TNode TNode;
    static const int dim = TM::dim;

    if ( not nvi )
        nvi = TM::dim;
    //
    int ctxte=0;

    // correspondance between number in file -> ref in mesh
    map<int,TNode *> map_num_node;
    string type_element;
    Vec<double> tag_values;
    //
    while ( 1 ) {
        if ( ! is )
            throw std::runtime_error ( "msh file is corrupted : mark 'end elements' is absent" );

        string str;
        getline ( is,str );

        // �aluation du contexte
        if ( str.find ( "$EndNodes" ) < str.size() ) {
            ctxte=0;
            continue;
        }
        if ( str.find ( "$EndElements" ) < str.size() ) {
            break;
        }
        if ( str.find ( "$Nodes" ) < str.size() ) {
            getline( is,str );
            ctxte = 1;
            continue;
        }
        if ( str.find ( "$Elements" ) < str.size() ) {
            getline( is,str );
            ctxte = 2;
            continue;
        }

        // utilisation du contexte
        if ( ctxte==1 ) {
            istringstream s( str );
            int number;
            s >> number;
            Pvec vec;
            for ( int di=0;di<dim;di++ )
                s >> vec[di];
            // we add the node and we retain is ref
            map_num_node[number] = m.add_node( vec );
            continue;
        }
        if ( ctxte==2 ) {
            istringstream s ( str );
            unsigned number;
            s >> number;
            unsigned type_elem;
            s >> type_elem;
            unsigned nb_nodes_elem[] = { 2, 3, 4, 4, 8, 6, 5, 3, 6, 9, 10, 27, 18, 14, 1, 8, 20, 15, 13 };
            unsigned nb_nodes;
            nb_nodes = nb_nodes_elem[type_elem-1];
            unsigned nb_tags;
            s >> nb_tags;
            tag_values.resize( nb_tags );
            for ( unsigned k = 0; k<nb_tags; k++ )
                s >> tag_values[k];

            LMT::Vec<TNode *> vn;
            vn.resize ( nb_nodes );
            for ( unsigned i=0;i<nb_nodes;i++ ) {
                s >> number;
                vn[i] = map_num_node[number];
            }

            if ( type_elem == 1 ) { //TODO
                if ( nvi == 1 )
                    assign_tag_values( m.add_element( Bar(),DefaultBehavior(),vn.ptr() ), tag_values, vt, Number<0>(), Number<NbSubTypes<VarTag>::res>() );
            } else if ( type_elem == 2 ) { //TODO
                if ( nvi == 2 ) {
                    permutation_if_jac_neg ( Triangle(),vn.ptr() );
                    assign_tag_values( m.add_element( Triangle(),DefaultBehavior(),vn.ptr() ), tag_values, vt, Number<0>(), Number<NbSubTypes<VarTag>::res>() );
                }
            } else if ( type_elem == 3 ) { //TODO
                if ( nvi == 2 ) {
                    permutation_if_jac_neg ( Quad(),vn.ptr() );
                    assign_tag_values( m.add_element( Quad(),DefaultBehavior(),vn.ptr() ), tag_values, vt, Number<0>(), Number<NbSubTypes<VarTag>::res>() );
                }
            } else if ( type_elem == 4 ) { //TODO
                if ( nvi == 3 ) {
                    permutation_if_jac_neg ( Tetra(),vn.ptr() );
                    assign_tag_values( m.add_element( Tetra(),DefaultBehavior(),vn.ptr() ), tag_values, vt, Number<0>(), Number<NbSubTypes<VarTag>::res>() );
                }
            } else if ( type_elem == 5 ) { //TODO
                if ( nvi == 3 ) {
                    permutation_if_jac_neg ( Hexa(),vn.ptr() );
                    assign_tag_values( m.add_element( Hexa(),DefaultBehavior(),vn.ptr() ), tag_values, vt, Number<0>(), Number<NbSubTypes<VarTag>::res>() );
                }
            } else if ( type_elem == 6 ) { //TODO
                if ( nvi == 3 ) {
                    permutation_if_jac_neg ( Wedge(),vn.ptr() );
                    assign_tag_values( m.add_element( Wedge(),DefaultBehavior(),vn.ptr() ), tag_values, vt, Number<0>(), Number<NbSubTypes<VarTag>::res>() );
                }
            } else if ( type_elem == 15 ) { //TODO
            } else {
                std::cout << "unknown type elem." << std::endl;
                assert ( 0 );
            }

            continue;
        }
    }
}


/// put gid mesh in m
template<class TM>
void read_msh_2( TM &m,const std::string &fic_name, unsigned nvi = 0 ) throw ( std::runtime_error ) {
    // ouverture du fichier
    std::ifstream my_file( fic_name.c_str() );
    if ( ! my_file.is_open() )
        throw std::runtime_error( "opening of "+fic_name+" has failed." );
    read_msh_2( m, my_file, nvi, HeteroExplPack<>() );
}

/// put gid mesh in m
template<class TM,class VarTag>
void read_msh_2( TM &m,const std::string &fic_name, unsigned nvi, const VarTag &vt  ) throw ( std::runtime_error ) {
    // ouverture du fichier
    std::ifstream my_file( fic_name.c_str() );
    if ( ! my_file.is_open() )
        throw std::runtime_error( "opening of "+fic_name+" has failed." );
    read_msh_2( m, my_file, nvi, vt );
}


};

#endif // LMT_READ_GID_HEADER

