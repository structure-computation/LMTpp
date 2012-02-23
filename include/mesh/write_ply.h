//
// C++ Interface: write_ply
//
// Description:
//
//
// Author: Raphaël Pasquier <pasquier@lmt.ens-cachan.fr>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_WRITE_PLY_HEADER
#define LMT_WRITE_PLY_HEADER

#include <fstream>

#include <string>
#include "mesh.h"

namespace LMT {

/*!
\internal
*/
template< bool binary >
struct Write_ply_buffer {
    Write_ply_buffer( ostream & os_ ) : os( os_ ) {} 
    
    template<class TE>
    void operator() ( const TE & e ) {
        if ( binary ) {
            os.write( (char*)(&TE::NameElem::nb_nodes), sizeof( unsigned ) );
            for( unsigned i = 0 ; i < TE::nb_nodes; ++i )
                os.write( (char*)&( e.node( i )->number ), sizeof( unsigned ) );
        } else {
            os << TE::nb_nodes;
            for( unsigned i = 0 ; i < TE::nb_nodes; ++i )
                os << " " << e.node( i )->number;
            os << std::endl;
        }
    }
    
    ostream &os;
};

/*!

*/
template<bool binary,class TM>
void write_ply( std::ostream &os, const TM &m ) {
    typedef typename TM::TNode::T T;
    
    T zero = 0.;
    //std::string appended;
    os << "ply" << std::endl; //
    os << "format ";
    if ( binary ) 
        os << "binary_little_endian 1.0" << std::endl;
    else
        os << "ascii 1.0" << std::endl;
    os << "comment file created by LMTpp::write_ply()" << std::endl;
    os << "comment " ; 
    time_t rawtime;
    time( &rawtime );
    struct tm * timeinfo;
    timeinfo = localtime( &rawtime );
    os << asctime( timeinfo );
    os << "element vertex " << m.skin.node_list.size() << std::endl;
    os << "property float x" << std::endl;
    os << "property float y" << std::endl;
    os << "property float z" << std::endl;
    os << "element face " << m.skin.elem_list.size() << std::endl;
    os << "property list uchar int vertex_index" << std::endl;
    os << "end_header" << std::endl;

    for( unsigned i = 0; i < m.node_list.size(); ++i )
        if ( binary ) {
            os.write( (char*) &m.node_list[ i ].pos, TM::dim * sizeof( T ) );
            if ( TM::dim == 2 )
                os.write( (char*) &zero, sizeof( T ) );
        } else {
            os << m.node_list[ i ].pos << std::endl;
            if ( TM::dim == 2 )
                os << " " << 0 << std::endl;
        }
         
    Write_ply_buffer<binary> wpb( os );
    apply( m.skin.elem_list, wpb ); 
}

/*!
\generic_comment write_ply
    Objectif :
        Exporter la peau d'un maillage au format ply
        
    Paramètre :
        * filename est le nom du fichier ( e.g. example.ply )
        * m est un maillage 2D ou 3D. Si le maillage est 2D, il sera défini dans le plan xy.
        
    Remarque  : le format ply pourrait contenir toutes les propriétés du maillage.
    Remarque2 : le format binaire ne fut pas testé car blender ne le comprend pas. D'ailleurs le lecteur de blender ne connaît pas non plus les quad...
       
    Exemple de code :
    \code C/C++
        write_ply<false>( "test.ply", m ); /// sauvegarde en ascii
        write_ply<true>( "test.ply", m ); /// sauvegarde en binaire

*/

/*!
    Objectif :
        Exporter la peau d'un maillage au format ply
        
    Paramètre :
        * filename est le nom du fichier ( e.g. example.ply )
        * m est un maillage 2D ou 3D. Si le maillage est 2D, il sera défini dans le plan xy.
        
    Remarque  : le format ply pourrait contenir toutes les propriétés du maillage.
    Remarque2 : le format binaire ne fut pas testé car blender ne le comprend pas. D'ailleurs le lecteur de blender ne connaît pas non plus les quad...
       
    Exemple de code :
    \code C/C++
        write_ply<false>( "test.ply", m ); /// sauvegarde en ascii
        write_ply<true>( "test.ply", m ); /// sauvegarde en binaire

*/
template<bool binary,class TM>
void write_ply( const char* filename, const TM &m ) {

    std::ofstream f( filename );
    write_ply<binary>( f, m );
    f.close();
}

}

#endif // LMT_WRITE_PLY_HEADER
