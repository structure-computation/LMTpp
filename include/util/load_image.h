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

/**
  Read PNM images only
*/
template<class Mat>
void load_image(std::string file,Mat &m) {
    if ( std::string(file.end()-4,file.end()) != ".pnm" ) {
        std::ostringstream s,s2;
        s << "convert -colorspace gray -depth 8 " << file << " " << "toto.pnm";
        system(s.str().c_str());
        file = "toto.pnm";
    }

    std::ifstream f(file.c_str());
    if (!f) {
        std::cerr << "Impossible to open " << file << std::endl;
        return;
    }
    std::string toto;
    getline(f,toto);
    getline(f,toto);
    while ( toto[0]=='#' )
        getline(f,toto);

    unsigned r,c;
    std::istringstream is(toto);
    is >> r >> c;
    
    int depth;
    f >> depth;
    assert(depth=255);
    std::cout << r << std::endl;
    std::cout << c << std::endl;

    unsigned char *pen = new unsigned char[ r*c ];
    f.read( (char *)pen, sizeof(unsigned char)*r*c );

    m.resize( r, c );
    for(unsigned i=0,cpt=0;i<r;++i)
        for(unsigned j=0;j<c;++j,++cpt)
            m(i,j) = pen[cpt];
    delete pen;
}
/// ostream interface
template<class T,class Str,class Sto,class IO>
void display_image(const Mat<T,Str,Sto,IO> &mat,const char *name_file="toto") {
    typedef typename Mat<T,Str,Sto,IO>::T TT;
    using namespace std;
    
    ofstream f(name_file);
    
    T m = 0.0;
    for(unsigned l=0;l<mat.nb_rows();++l)
        for(unsigned c=0;c<mat.nb_cols();++c)
            m = max( m, (TT)mat(l,c) );
        
    for(unsigned l=0;l<mat.nb_rows();++l)
        for(unsigned c=0;c<mat.nb_cols();++c)
            f.put( (unsigned char)mat(l,c) );
        
    f.close();
    
    ostringstream s2;
    //s << "display -depth 8 -size " << mat.nb_rows() << "x" << mat.nb_cols() << " gray:" << name_file;
    //system(s.str().c_str());
    
    s2 << "convert -depth 8 -size " << mat.nb_rows() << "x" << mat.nb_cols() << " gray:" << name_file << " " << name_file << ".png";
    system(s2.str().c_str());
}

};

#endif // LMT_load_image_HEADER
