#ifndef LMT_IMG_INTERP_H
#define LMT_IMG_INTERP_H

#include <containers/vec.h>
#include <QtGui/QImage>
#include <assert.h>

namespace LMT {

/** */
template<class T,unsigned dim,class PT=T>
struct ImgInterp {
    ///
    ImgInterp() : sizes( 1 ) {}
    
    ///
    ImgInterp( const std::string &s ) : sizes( 1 ) {
        load( s );
    }
    
    ///
    void resize( Vec<int,dim> s ) {
        sizes = s;
        data.resize( product( s ) );
    }
    
    ///
    void set( T default_val ) {
        data.set( default_val );
    }
    
    ///
    void load( const std::string &s ) {
        //
        QImage img( QString( s.c_str() ) );
        
        sizes.set( 1 );
        assert( dim >= 2 );
        sizes[ 0 ] = img.width();
        sizes[ 1 ] = img.height();
        
        data.resize( product( sizes ) );
        const uchar *ptr = img.bits();
        if ( img.depth() == 8 ) {
            for(int i=0;i<data.size();++i,++ptr)
                data[ i ] = *ptr;
        } else if ( img.depth() == 32 ) {
            for(int i=0;i<data.size();++i,ptr+=4)
                data[ i ] = ( ptr[0] + ptr[1] + ptr[2] ) / 3.0;
        } else {
            throw "img.depth() not supported " + to_string( img.depth() );
        }
    }
    
    ///
    operator QImage() const {
        QImage img( sizes[0], sizes[1], QImage::Format_ARGB32 );
        uchar *ptr = img.bits();
        int total_size = product( sizes );
        for(int i=0;i<total_size;++i,ptr+=4) {
            ptr[ 0 ] = data[ i ];
            ptr[ 1 ] = data[ i ];
            ptr[ 2 ] = data[ i ];
            ptr[ 3 ] = 255 * ( data[ i ] >= 0 );
        }
        return img;
    }
    
    ///
    void save( std::string filename ) const {
        if ( dim == 2 ) {
            QImage img( *this );
            img.save( filename.c_str() );
        }
    }
    
    ///
    int display() {
        save( "pouet.png" );
        return system( "display pouet.png" );
    }
    
    ///
    inline T &operator()( int x, int y ) {
        return data[ sizes[0] * y + x ];
    }
    
    ///
    inline T operator()( int x, int y ) const {
        return data[ sizes[0] * y + x ];
    }
    
    ///
    inline T &operator()( int x, int y, int z ) {
        return data[ sizes[1] * sizes[0] * z + sizes[0] * y + x ];
    }
    
    ///
    inline T operator()( int x, int y, int z ) const {
        return data[ sizes[1] * sizes[0] * z + sizes[0] * y + x ];
    }
    
    ///
    inline T &operator()( Vec<int,dim> p ) {
        int o = p[0];
        for(int i=1, m=sizes[0]; i<dim; m*=sizes[i], ++i )
            o += m * p[i];
        return data[ o ];
    }
    
    ///
    inline T operator()( Vec<int,dim> p ) const {
        int o = p[0];
        for(int i=1, m=sizes[0]; i<dim; m*=sizes[i], ++i )
            o += m * p[i];
        return data[ o ];
    }
    
    ///
    inline T operator()( PT x, PT y ) const {
        int xi = int( x );
        int yi = int( y );
        PT xf = x - xi;
        PT yf = y - yi;
        return operator()( xi + 0, yi + 0 ) * ( 1 - xf ) * ( 1 - yf ) + 
               operator()( xi + 1, yi + 0 ) * ( 0 + xf ) * ( 1 - yf ) + 
               operator()( xi + 0, yi + 1 ) * ( 1 - xf ) * ( 0 + yf ) + 
               operator()( xi + 1, yi + 1 ) * ( 0 + xf ) * ( 0 + yf );
    }
    
    ///
    inline T operator()( PT x, PT y, PT z ) const {
        int xi = int( x );
        int yi = int( y );
        int zi = int( z );
        PT xf = x - xi;
        PT yf = y - yi;
        PT zf = z - zi;
        return operator()( xi + 0, yi + 0, zi + 0 ) * ( 1 - xf ) * ( 1 - yf ) * ( 1 - zf ) + 
               operator()( xi + 1, yi + 0, zi + 0 ) * ( 0 + xf ) * ( 1 - yf ) * ( 1 - zf ) + 
               operator()( xi + 0, yi + 1, zi + 0 ) * ( 1 - xf ) * ( 0 + yf ) * ( 1 - zf ) + 
               operator()( xi + 1, yi + 1, zi + 0 ) * ( 0 + xf ) * ( 0 + yf ) * ( 1 - zf ) +
               operator()( xi + 0, yi + 0, zi + 1 ) * ( 1 - xf ) * ( 1 - yf ) * ( 0 + zf ) + 
               operator()( xi + 1, yi + 0, zi + 1 ) * ( 0 + xf ) * ( 1 - yf ) * ( 0 + zf ) + 
               operator()( xi + 0, yi + 1, zi + 1 ) * ( 1 - xf ) * ( 0 + yf ) * ( 0 + zf ) + 
               operator()( xi + 1, yi + 1, zi + 1 ) * ( 0 + xf ) * ( 0 + yf ) * ( 0 + zf );
    }
    
    ///
    inline T operator()( Vec<PT,2> p ) const {
        return operator()( p[0], p[1] );
    }
    
    ///
    inline T operator()( Vec<PT,3> p ) const {
        return operator()( p[0], p[1], p[2] );
    }
    
    ///
    inline Vec<T,dim> grad( Vec<PT,dim> p ) const {
        Vec<T,dim> res;
        for(int i=0;i<dim;++i)
            res[ i ] = operator()( Vec<PT,dim>( p + static_dirac_vec<dim>( 1, i ) ) ) - operator()( p );
        return res;
    }
    
    ///
    Vec<T> data;
    Vec<int,dim> sizes;
};




}

#endif // LMT_IMG_INTERP_H

