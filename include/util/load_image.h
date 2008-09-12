//
// C++ Interface: load_image
//
// Description:
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_load_image_HEADER
#define LMT_load_image_HEADER

#include "containers/mat.h"

namespace LMT {

template<class Mat>
void load_image_pgm( std::string file, Mat &m, int ceil_size = 1 ) {
    std::ifstream f( file.c_str() );
    if (!f) {
        std::cerr << "Impossible to open " << file << std::endl;
        return;
    }
    std::string PT, toto;
    getline(f,PT  ); // P5...
    getline(f,toto);
    while ( toto[0]=='#' )
        getline(f,toto);
    unsigned cpt_jump = 1 + 2 * ( PT == "P6" );

    unsigned r,c;
    std::istringstream is(toto);
    is >> c >> r;
    
    int depth = 2;
    if ( PT != "P4" )
        f >> depth;
    getline(f,toto);
    
    if ( depth <= 2 ) {
        unsigned char *pen = new unsigned char[ ( r * c + 7 ) / 8 ];
        f.read( (char *)pen, ( r * c + 7 ) / 8 );
        
        m.resize( r, ceil( c, ceil_size ) );
        for(unsigned i=0,cpt=0;i<r;++i)
            for(unsigned j=0;j<c;++j,++cpt)
                m(i,j) = bool( pen[ cpt / 8 ] & ( 1 << (cpt&7) ) );
        delete [] pen;
    } else if ( depth <= 255 ) {
        unsigned char *pen = new unsigned char[ r * c * cpt_jump ];
        f.read( (char *)pen, sizeof(unsigned char) * r * c * cpt_jump );
    
        m.resize( r, ceil( c, ceil_size ) );
        for(unsigned i=0,cpt=0;i<r;++i)
            for(unsigned j=0;j<c;++j,cpt+=cpt_jump)
                m(i,j) = pen[cpt];
        delete [] pen;
    } else if ( depth <= 65535 ) {
        unsigned short *pen = new unsigned short[ r * c ];
        f.read( (char *)pen, sizeof(unsigned short) * r * c );
    
        for(unsigned i=0;i<r*c;++i)
            swap( *( (char *)pen + 2 * i + 0 ), *( (char *)pen + 2 * i + 1 ) );
            
        m.resize( r, ceil( c, ceil_size ) );
        for(unsigned i=0,cpt=0;i<r;++i)
            for(unsigned j=0;j<c;++j,++cpt)
                m(i,j) = pen[cpt];
        delete [] pen;
    } else {
        PRINT( depth );
        assert( 0 );
    }
}


/*!
  Read PNM images only
*/
template<class Mat>
void load_image( std::string file, Mat &m, int ceil_size = 1 ) {
    if ( std::string(file.end()-4,file.end()) == ".pgm" or std::string(file.end()-4,file.end()) == ".pnm" ) {
        load_image_pgm( file, m, ceil_size );
        return;
    }
    //
    std::ostringstream s,s2;
    s << "convert -colorspace gray -depth 8 " << file << " " << "toto.pnm";
    system(s.str().c_str());
    load_image_pgm( "toto.pnm", m, ceil_size );
}

/*!
    Cette fonction convertit la matrice passée en paramètre en une image. Plus précisément, chaque élément de la matrice est convertit en un nombre entier compris entre 0 et 255 et codant un niveau de gris.


    \keyword Utilitaires
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \keyword Mathématiques/Algèbre linéaire/Opération   
    \keyword Algorithme/Affichage  
*/
template<class T,class Str,class Sto,class IO>
void display_image(const Mat<T,Str,Sto,IO> &mat, const std::string &name_file="toto") {
    typedef typename Mat<T,Str,Sto,IO>::T TT;
    using namespace std;
    
    ofstream f( name_file.c_str() );
        
    for(unsigned l=0;l<mat.nb_rows();++l)
        for(unsigned c=0;c<mat.nb_cols();++c)
            f.put( (unsigned char)mat(l,c) );
        
    f.close();
    
    ostringstream s2;
    s2 << "convert -depth 8 -size " << mat.nb_cols() << "x" << mat.nb_rows() << " gray:" << name_file << " " << name_file << ".png";
    system(s2.str().c_str());
}

};

#endif // LMT_load_image_HEADER
