#ifndef LMT_IMG_INTERP_H
#define LMT_IMG_INTERP_H

#include <containers/mat.h>
#include <QtGui/QImage>
#include <assert.h>

namespace LMT {

/** */
template<class T_,unsigned dim_,class PT_=T_>
struct ImgInterp {
    typedef T_ T;
    static const unsigned dim = dim_;
    typedef PT_ PT;
    typedef ImgInterp T_NewImg;
    
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
        if ( img.depth() == 0 )
            throw "Failed to load img" + s;
        
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
            PRINT( sizes );
            PRINT( img.depth() );
            throw "img.depth() not supported " + to_string( img.depth() );
        }
    }
    
    template<class TB>
    void load_binary( const std::string &filename, Vec<int,dim> S, Vec<int,dim> X0 = 0, Vec<int,dim> X1 = -1 ) {
        assert( dim >= 2 );
        
        for(unsigned i=0;i<dim;++i)
            if ( X1[i] < 0 )
                X1[i] = S[i];
        
        sizes = X1 - X0;
        
        // data in tmp
        data.resize( product( sizes ) );
        std::ifstream f( filename.c_str() );
        Vec<TB> tmp;
        tmp.resize( sizes[0] );
        if ( dim == 2 ) {
            f.seekg( S[0] * X0[1] * sizeof(TB), std::ios::beg );
            for(unsigned y=0,od=0;y<sizes[1];++y) {
                f.seekg( X0[0] * sizeof(TB), std::ios::cur );
                f.read( (char *)tmp.ptr(), sizes[0] * sizeof(TB) );
                for(unsigned x=0;x<sizes[0];++x,++od)
                    data[ od ] = tmp[ x ];
                f.seekg( ( S[0] - X1[0] ) * sizeof(TB), std::ios::cur );
            }
        } else if ( dim == 3 ) {
            f.seekg( S[0] * S[1] * X0[2] * sizeof(TB), std::ios::beg );
            for(unsigned z=0,od=0;z<sizes[2];++z) {
                f.seekg( S[0] * X0[1] * sizeof(TB), std::ios::cur );
                for(unsigned y=0;y<sizes[1];++y) {
                    f.seekg( X0[0] * sizeof(TB), std::ios::cur );
                    f.read( (char *)tmp.ptr(), sizes[0] * sizeof(TB) );
                    for(unsigned x=0;x<sizes[0];++x,++od)
                        data[ od ] = tmp[ x ];
                    f.seekg( ( S[0] - X1[0] ) * sizeof(TB), std::ios::cur );
                }
            }
        } else
            assert( 0 /* TODO */ );
    }
    
    ///
    QImage to_QImage( bool normalize = false ) const {
        T o = 0.0, m = 1.0;
        if ( normalize ) {
            T mi = min( data );
            T ma = max( data );
            o = mi;
            m = 255 / ( ma - mi );
        }
            
        //
        QImage img( sizes[0], sizes[1], QImage::Format_ARGB32 );
        uchar *ptr = img.bits();
        int total_size = sizes[0] * sizes[1];
        for(int i=0;i<total_size;++i,ptr+=4) {
            ptr[ 0 ] = m * ( data[ i ] - o );
            ptr[ 1 ] = m * ( data[ i ] - o );
            ptr[ 2 ] = m * ( data[ i ] - o );
            ptr[ 3 ] = 255 * ( data[ i ] >= 0 );
        }
        return img;
    }
    
    ///
    void save( std::string filename, bool normalize = false ) const {
        QImage img = to_QImage( normalize );
        img.save( filename.c_str() );
    }
    
    ///
    int display( bool normalize = false ) {
        save( "pouet.png", normalize );
        return system( "display pouet.png &" );
    }
    
    ///
    inline T &tex_int( int x, int y ) {
        return data[ sizes[0] * y + x ];
    }
    
    ///
    inline T tex_int( int x, int y ) const {
        return data[ sizes[0] * y + x ];
    }
    
    ///
    inline T &tex_int( int x, int y, int z ) {
        return data[ sizes[1] * sizes[0] * z + sizes[0] * y + x ];
    }
    
    ///
    inline T tex_int( int x, int y, int z ) const {
        return data[ sizes[1] * sizes[0] * z + sizes[0] * y + x ];
    }
    
    ///
    inline T &tex_int( Vec<int,dim> p ) {
        int o = p[0];
        for(int i=1, m=sizes[0]; i<dim; m*=sizes[i], ++i )
            o += m * p[i];
        return data[ o ];
    }
    
    ///
    inline T tex_int( Vec<int,dim> p ) const {
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
        return tex_int( xi + 0, yi + 0 ) * ( 1 - xf ) * ( 1 - yf ) + 
               tex_int( xi + 1, yi + 0 ) * ( 0 + xf ) * ( 1 - yf ) + 
               tex_int( xi + 0, yi + 1 ) * ( 1 - xf ) * ( 0 + yf ) + 
               tex_int( xi + 1, yi + 1 ) * ( 0 + xf ) * ( 0 + yf );
    }
    
    ///
    inline T operator()( PT x, PT y, PT z ) const {
        int xi = int( x );
        int yi = int( y );
        int zi = int( z );
        PT xf = x - xi;
        PT yf = y - yi;
        PT zf = z - zi;
        return tex_int( xi + 0, yi + 0, zi + 0 ) * ( 1 - xf ) * ( 1 - yf ) * ( 1 - zf ) + 
               tex_int( xi + 1, yi + 0, zi + 0 ) * ( 0 + xf ) * ( 1 - yf ) * ( 1 - zf ) + 
               tex_int( xi + 0, yi + 1, zi + 0 ) * ( 1 - xf ) * ( 0 + yf ) * ( 1 - zf ) + 
               tex_int( xi + 1, yi + 1, zi + 0 ) * ( 0 + xf ) * ( 0 + yf ) * ( 1 - zf ) +
               tex_int( xi + 0, yi + 0, zi + 1 ) * ( 1 - xf ) * ( 1 - yf ) * ( 0 + zf ) + 
               tex_int( xi + 1, yi + 0, zi + 1 ) * ( 0 + xf ) * ( 1 - yf ) * ( 0 + zf ) + 
               tex_int( xi + 0, yi + 1, zi + 1 ) * ( 1 - xf ) * ( 0 + yf ) * ( 0 + zf ) + 
               tex_int( xi + 1, yi + 1, zi + 1 ) * ( 0 + xf ) * ( 0 + yf ) * ( 0 + zf );
    }
    
    
    ///
    template<class PTT>
    inline T operator()( Vec<PTT,2> p ) const {
        return operator()( p[0], p[1] );
    }
    
    ///
    template<class PTT>
    inline T operator()( Vec<PTT,3> p ) const {
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
    void load_if_necessary( Vec<int,dim> MI, Vec<int,dim> MA, bool may_be_modified = false ) const {}
    
    ///
    Vec<T> data;
    Vec<int,dim> sizes;
};


/** */
template<class T,unsigned dim,class PT=T>
struct ImgInterByBlock {
    typedef long long Int64;
    typedef ImgInterp<T,dim,PT> Img;
    
    ImgInterByBlock() {
        allowed_memory_size = 2 << 31;
        PRINT( allowed_memory_size );
    }
    
    void load( const std::string &filename ) {
        int n = 0;
        int m = 0;
        blocks.resize( n, m );
        blocks.set( (Img *)NULL );
    }
    
    ///
    inline void load_if_necessary( Vec<int,dim> MI, Vec<int,dim> MA, bool may_be_modified = false ) const {}
    
    Mat<Img *> blocks;
    Int64 allowed_memory_size;
};


template<class TIMG>
struct ImgInterpDec {
    typedef typename TIMG::T T;
    static const unsigned dim = TIMG::dim;
    typedef typename TIMG::PT PT;
    typedef TIMG T_NewImg;

    ImgInterpDec( TIMG *orig, Vec<PT,dim> offset ) : orig( orig ), offset( offset ) {}
    
    inline void load_if_necessary( Vec<int,dim> MI, Vec<int,dim> MA, bool may_be_modified = false ) const {
        orig->load_if_necessary( MI-offset, MA-offset, may_be_modified );
    }
    
    inline T &tex_int( int x, int y ) { return orig->tex_int( x - offset[0], y - offset[1] ); }
    inline T tex_int( int x, int y ) const { return orig->tex_int( x - offset[0], y - offset[1] ); }
    inline T &tex_int( int x, int y, int z ) { return orig->tex_int( x - offset[0], y - offset[1], z - offset[2] ); }
    inline T tex_int( int x, int y, int z ) const { return orig->tex_int( x - offset[0], y - offset[1], z - offset[2] ); }
    inline T &tex_int( Vec<int,dim> p ) { return orig->tex_int( p - offset ); }
    inline T tex_int( Vec<int,dim> p ) const { return orig->tex_int( p - offset ); }
    
    inline T operator()( PT x, PT y ) const { return orig->operator()( x - offset[0], y - offset[1] ); }
    inline T operator()( PT x, PT y, PT z ) const { return orig->operator()( x - offset[0], y - offset[1], z - offset[2] ); }
    template<class PTT> inline T operator()( Vec<PTT,dim> p ) const { return orig->operator()( p - offset ); }
    
    inline Vec<T,dim> grad( Vec<PT,dim> p ) const { return orig->grad( p - offset ); }
    
    
    TIMG *orig;
    Vec<PT,dim> offset;
};


}

#endif // LMT_IMG_INTERP_H

