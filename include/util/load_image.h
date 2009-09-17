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
void load_image_pgm( std::string file, Mat &m, int ceil_size = 1, int border_size = 0, typename Mat::T border_color = 0 ) {
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
        
        m.resize( r + 2 * border_size, ceil( c, ceil_size ) + 2 * border_size );
        m.set( border_color );
        for(unsigned i=0,cpt=0;i<r;++i)
            for(unsigned j=0;j<c;++j,++cpt)
                m(i+border_size,j+border_size) = bool( pen[ cpt / 8 ] & ( 1 << (cpt&7) ) );
        delete [] pen;
    } else if ( depth <= 255 ) {
        unsigned char *pen = new unsigned char[ r * c * cpt_jump ];
        f.read( (char *)pen, sizeof(unsigned char) * r * c * cpt_jump );
    
        m.resize( r + 2 * border_size, ceil( c, ceil_size ) + 2 * border_size );
        m.set( border_color );
        for(unsigned i=0,cpt=0;i<r;++i)
            for(unsigned j=0;j<c;++j,cpt+=cpt_jump)
                m(i+border_size,j+border_size) = pen[cpt];
        delete [] pen;
    } else if ( depth <= 65535 ) {
        unsigned short *pen = new unsigned short[ r * c ];
        f.read( (char *)pen, sizeof(unsigned short) * r * c );
    
        for(unsigned i=0;i<r*c;++i)
            swap( *( (char *)pen + 2 * i + 0 ), *( (char *)pen + 2 * i + 1 ) );
            
        m.resize( r + 2 * border_size, ceil( c, ceil_size ) + 2 * border_size );
        m.set( border_color );
        for(unsigned i=0,cpt=0;i<r;++i)
            for(unsigned j=0;j<c;++j,++cpt)
                m(i+border_size,j+border_size) = pen[cpt];
        delete [] pen;
    } else {
        PRINT( depth );
        assert( 0 );
    }
}


/*!
    m.nb_rows() = img_nb_rows + 2 * border_size
    m.nb_cols() = ceil( img_nb_cols, ceil_size ) + 2 * border_size
*/
template<class Mat>
int load_image( std::string file, Mat &m, int ceil_size = 1, int border_size = 0, typename Mat::T border_color = 0 ) {
    if ( std::string(file.end()-4,file.end()) == ".pgm" or std::string(file.end()-4,file.end()) == ".pnm" ) {
        load_image_pgm( file, m, ceil_size, border_size, border_color );
        return 0;
    }
    //
    std::ostringstream s,s2;
    s << "convert -colorspace gray -depth 8 " << file << " " << "toto.pnm";
    int res = system(s.str().c_str());
    load_image_pgm( "toto.pnm", m, ceil_size, border_size, border_color );
    return res;
}

/*!
    Cette fonction convertit la matrice passée en paramètre en une image. Plus précisément, chaque élément de la matrice est convertit en un nombre entier (le nombre original doit être compris entre 0 et 255 et codant un niveau de gris, sauf si on met l'option, auto_grey_level_scaling).


    \keyword Utilitaires
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \keyword Mathématiques/Algèbre linéaire/Opération   
    \keyword Algorithme/Affichage  
*/
template<class T,class Str,class Sto,class IO>
void display_image(const Mat<T,Str,Sto,IO> &mat, const std::string &name_file="toto", bool disp_screen = false, bool auto_grey_level_scaling = false ) {
    typedef typename Mat<T,Str,Sto,IO>::T TT;
    using namespace std;
    
    ofstream f( name_file.c_str() );
        
    T mi = 0, ma = 1;
    if ( auto_grey_level_scaling ) {
        mi = min( mat );
        ma = max( mat );
    }
        
    for(unsigned l=0;l<mat.nb_rows();++l)
        for(unsigned c=0;c<mat.nb_cols();++c)
            f.put( (unsigned char)( 255 * ( mat(l,c) - mi ) / ( ma - mi ) ) );
        
    f.close();
    
    ostringstream s2;
    s2 << "convert -depth 8 -size " << mat.nb_cols() << "x" << mat.nb_rows() << " gray:" << name_file << " " << name_file << ".png; rm " << name_file;
    if ( disp_screen )
        s2 << "; display " << name_file << ".png";
    system(s2.str().c_str());
}

/** @see display_image */
template<class T>
struct EchelleCouleurExemple {
    Vec<T,3> operator()( T grey ) const {
        return Vec<T,3>( exp( - grey*grey*2 ), exp( - (grey-0.5)*(grey-0.5)*2 ), exp( - (grey-1)*(grey-1) )*2 ) / ( 1 + exp( -1 ) + exp( -2 ) );
    }
};

/** display_image( m, EchelleCouleurExemple(), ... ); */
template<class TM,class Op>
        void display_image(const TM &mat, const Op &grey_to_rgb, const std::string &name_file="toto", bool disp_screen = false, bool auto_grey_level_scaling = false ) {
    typedef typename TM::T T;
    using namespace std;
    
    ofstream f( name_file.c_str() );
        
    T mi = 0, ma = 1;
    if ( auto_grey_level_scaling ) {
        mi = min( mat );
        ma = max( mat );
    }
        
    for(unsigned l=0;l<mat.nb_rows();++l) {
        for(unsigned c=0;c<mat.nb_cols();++c) {
            Vec<T,3> rgb;// = grey_to_rgb( ( mat(l,c) - mi ) / ( ma - mi ) );
            f.put( (unsigned char)( 255 * rgb[0] ) );
            f.put( (unsigned char)( 255 * rgb[1] ) );
            f.put( (unsigned char)( 255 * rgb[2] ) );
        }
    }
        
    f.close();
    
    ostringstream s2;
    s2 << "convert -depth 8 -size " << mat.nb_cols() << "x" << mat.nb_rows() << " rgb:" << name_file << " " << name_file << ".png; rm " << name_file;
    if ( disp_screen )
        s2 << "; display " << name_file << ".png";
    system(s2.str().c_str());
}

};

#endif // LMT_load_image_HEADER
