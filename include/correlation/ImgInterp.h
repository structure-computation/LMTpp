#ifndef LMT_IMG_INTERP_H
#define LMT_IMG_INTERP_H

#include <containers/mat.h>
#include <QtGui/QImage>
#include <assert.h>
#include <fstream>
#include <sstream>
#include <util/rectilinear_iterator.h>

namespace LMT {

/** kernel exemple for ImgInterp */
struct ImgInterpBilinearKernel {
    static std::string name() { return "ImgInterpBilinearKernel"; }
    
    // 2D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y ) const {
        int xi = int( x );
        int yi = int( y );
        PT xf = x - xi;
        PT yf = y - yi;
        return f.tex_int( xi + 0, yi + 0 ) * ( 1 - xf ) * ( 1 - yf ) + 
               f.tex_int( xi + 1, yi + 0 ) * ( 0 + xf ) * ( 1 - yf ) + 
               f.tex_int( xi + 0, yi + 1 ) * ( 1 - xf ) * ( 0 + yf ) + 
               f.tex_int( xi + 1, yi + 1 ) * ( 0 + xf ) * ( 0 + yf );
    }
    // 3D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y, PT z ) const {
        int xi = int( x );
        int yi = int( y );
        int zi = int( z );
        PT xf = x - xi;
        PT yf = y - yi;
        PT zf = z - zi;
        return f.tex_int( xi + 0, yi + 0, zi + 0 ) * ( 1 - xf ) * ( 1 - yf ) * ( 1 - zf ) + 
               f.tex_int( xi + 1, yi + 0, zi + 0 ) * ( 0 + xf ) * ( 1 - yf ) * ( 1 - zf ) + 
               f.tex_int( xi + 0, yi + 1, zi + 0 ) * ( 1 - xf ) * ( 0 + yf ) * ( 1 - zf ) + 
               f.tex_int( xi + 1, yi + 1, zi + 0 ) * ( 0 + xf ) * ( 0 + yf ) * ( 1 - zf ) +
               f.tex_int( xi + 0, yi + 0, zi + 1 ) * ( 1 - xf ) * ( 1 - yf ) * ( 0 + zf ) + 
               f.tex_int( xi + 1, yi + 0, zi + 1 ) * ( 0 + xf ) * ( 1 - yf ) * ( 0 + zf ) + 
               f.tex_int( xi + 0, yi + 1, zi + 1 ) * ( 1 - xf ) * ( 0 + yf ) * ( 0 + zf ) + 
               f.tex_int( xi + 1, yi + 1, zi + 1 ) * ( 0 + xf ) * ( 0 + yf ) * ( 0 + zf );
    }

    //     template<class T,class Img,class PT>
    //     Vec<T,2> grad( StructForType<T>, const Img &f, Vec<PT,2> p ) const {
    //         int xi = int( p[0] );
    //         int yi = int( p[1] );
    //         PT xf = p[0] - xi;
    //         PT yf = p[1] - yi;
    //         return Vec<T,2>(
    //             ( f.tex_int( xi + 1, yi + 0 ) - f.tex_int( xi + 0, yi + 0 ) ) * ( 1 - yf ) + 
    //             ( f.tex_int( xi + 1, yi + 1 ) - f.tex_int( xi + 0, yi + 1 ) ) * ( 0 + yf ),
    //             ( f.tex_int( xi + 0, yi + 1 ) - f.tex_int( xi + 0, yi + 0 ) ) * ( 1 - xf ) + 
    //             ( f.tex_int( xi + 1, yi + 1 ) - f.tex_int( xi + 1, yi + 0 ) ) * ( 0 + xf )
    //         );
    //     }
    
    template<class T,class Img,class PT,int dim>
    Vec<T,dim> grad( StructForType<T>, const Img &f, Vec<PT,dim> p ) const {
        Vec<T,dim> res;
        const double d = 0.05;
        for(int i=0;i<dim;++i)
            res[ i ] = ( f( Vec<PT,dim>( p + static_dirac_vec<dim>( d, i ) ) ) - f( p - static_dirac_vec<dim>( d, i ) ) ) / ( 2 * d );
        return res;
    }
};

/** kernel exemple for ImgInterp */
struct ImgInterpOrder3_Kernel {
    static std::string name() { return "ImgInterpOrder3_Kernel"; }
    
    template<class T>
    T interp( T vm, T v0, T v1, T v2, T xf ) const {
        return 
            vm * ( 0 - xf ) * ( 1 - xf ) * ( 2 - xf ) / 6 + 
            v0 * ( 1 + xf ) * ( 1 - xf ) * ( 2 - xf ) / 2 + 
            v1 * ( 1 + xf ) * ( 0 + xf ) * ( 2 - xf ) / 2 + 
            v2 * ( 1 + xf ) * ( 0 + xf ) * ( xf - 1 ) / 6;
    }
    
    /*
        vm := symbol("vm")
        v0 := symbol("v0")
        v1 := symbol("v1")
        v2 := symbol("v2")
        xf := symbol("xf")
        
        d := vm * ( xf * ( 1 - xf ) - ( 2 - xf ) * ( 1 - 2 * xf ) ) / 6 + 
                    v0 * ( - ( 1 - xf ) * ( 1 + xf ) - 2 * xf * ( 2 - xf ) ) / 2 + 
                    v1 * ( ( 2 - xf ) * ( 1 + 2 * xf ) - xf * ( 1 + xf ) ) / 2 + 
                    v2 * ( xf * ( 1 + xf ) + ( xf - 1 ) * ( 1 + 2 * xf ) ) / 6
    */
    template<class T>
    T grad( T vm, T v0, T v1, T v2, T xf ) const {
        return 
            vm * ( xf * ( 1 - xf ) - ( 2 - xf ) * ( 1 - 2 * xf ) ) / 6 + 
            v0 * ( - ( 1 - xf ) * ( 1 + xf ) - 2 * xf * ( 2 - xf ) ) / 2 + 
            v1 * ( ( 2 - xf ) * ( 1 + 2 * xf ) - xf * ( 1 + xf ) ) / 2 + 
            v2 * ( xf * ( 1 + xf ) + ( xf - 1 ) * ( 1 + 2 * xf ) ) / 6;
    }
    
    // 2D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y ) const {
        int xi = int( x );
        int yi = int( y );
        PT xf = x - xi;
        PT yf = y - yi;
        return interp( 
            interp( f.tex_int( xi - 1, yi - 1 ), f.tex_int( xi + 0, yi - 1 ), f.tex_int( xi + 1, yi - 1 ), f.tex_int( xi + 2, yi - 1 ), xf ),
            interp( f.tex_int( xi - 1, yi + 0 ), f.tex_int( xi + 0, yi + 0 ), f.tex_int( xi + 1, yi + 0 ), f.tex_int( xi + 2, yi + 0 ), xf ),
            interp( f.tex_int( xi - 1, yi + 1 ), f.tex_int( xi + 0, yi + 1 ), f.tex_int( xi + 1, yi + 1 ), f.tex_int( xi + 2, yi + 1 ), xf ),
            interp( f.tex_int( xi - 1, yi + 2 ), f.tex_int( xi + 0, yi + 2 ), f.tex_int( xi + 1, yi + 2 ), f.tex_int( xi + 2, yi + 2 ), xf ),
            yf
        );
    }
    // 3D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y, PT z ) const {
        assert( 0 /*TODO*/ );
    }

    template<class T,class Img,class PT,int dim>
    Vec<T,dim> grad( StructForType<T>, const Img &f, Vec<PT,dim> p ) const {
        Vec<T,dim> res;
        const double d = 0.5;
        for(int i=0;i<dim;++i)
            res[ i ] = ( f( Vec<PT,dim>( p + static_dirac_vec<dim>( d, i ) ) ) - f( p - static_dirac_vec<dim>( d, i ) ) ) / ( 2 * d );
        return res;
        //         int xi = int( p[0] );
        //         int yi = int( p[1] );
        //         PT xf = p[0] - xi;
        //         PT yf = p[1] - yi;
        //         return Vec<T,dim>( 
        //             grad(
        //                 interp( f.tex_int( xi - 1, yi - 1 ), f.tex_int( xi - 1, yi + 0 ), f.tex_int( xi - 1, yi + 1 ), f.tex_int( xi - 1, yi + 2 ), yf ),
        //                 interp( f.tex_int( xi + 0, yi - 1 ), f.tex_int( xi + 0, yi + 0 ), f.tex_int( xi + 0, yi + 1 ), f.tex_int( xi + 0, yi + 2 ), yf ),
        //                 interp( f.tex_int( xi + 1, yi - 1 ), f.tex_int( xi + 1, yi + 0 ), f.tex_int( xi + 1, yi + 1 ), f.tex_int( xi + 1, yi + 2 ), yf ),
        //                 interp( f.tex_int( xi + 2, yi - 1 ), f.tex_int( xi + 2, yi + 0 ), f.tex_int( xi + 2, yi + 1 ), f.tex_int( xi + 2, yi + 2 ), yf ),
        //                 xf 
        //             ),
        //             grad(
        //                 interp( f.tex_int( xi - 1, yi - 1 ), f.tex_int( xi + 0, yi - 1 ), f.tex_int( xi + 1, yi - 1 ), f.tex_int( xi + 2, yi - 1 ), xf ),
        //                 interp( f.tex_int( xi - 1, yi + 0 ), f.tex_int( xi + 0, yi + 0 ), f.tex_int( xi + 1, yi + 0 ), f.tex_int( xi + 2, yi + 0 ), xf ),
        //                 interp( f.tex_int( xi - 1, yi + 1 ), f.tex_int( xi + 0, yi + 1 ), f.tex_int( xi + 1, yi + 1 ), f.tex_int( xi + 2, yi + 1 ), xf ),
        //                 interp( f.tex_int( xi - 1, yi + 2 ), f.tex_int( xi + 0, yi + 2 ), f.tex_int( xi + 1, yi + 2 ), f.tex_int( xi + 2, yi + 2 ), xf ),
        //                 yf 
        //             )
        //         );
    }
};

/** kernel exemple for ImgInterp */
struct ImgInterpIntegralKernel {
    // 2D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y ) const {
        int xi = int( x );
        int yi = int( y );
        PT xf = x - xi;
        PT yf = y - yi;
        return f.tex_int( xi + 0, yi + 0 ) * ( 1 - xf ) * ( 1 - yf ) + 
               f.tex_int( xi + 1, yi + 0 ) * ( 0 + xf ) * ( 1 - yf ) + 
               f.tex_int( xi + 0, yi + 1 ) * ( 1 - xf ) * ( 0 + yf ) + 
               f.tex_int( xi + 1, yi + 1 ) * ( 0 + xf ) * ( 0 + yf );
    }
    // 3D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y, PT z ) const {
        assert( 0 /*TODO*/ );
        return 0;
    }
};

/** kernel exemple for ImgInterp */
template<unsigned nb_div>
struct ImgInterpDivKernel {
    // 2D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y ) const {
        int xi = int( x );
        int yi = int( y );
        PT xf = x - xi;
        PT yf = y - yi;
        int xfi = int( xf * 20 );
        int yfi = int( yf * 20 );
        PT xff = xf * 20 - xfi;
        PT yff = yf * 20 - yfi;
        return f.tex_int( xi + 0, yi + 0 ) * ( 1 - xf ) * ( 1 - yf ) + 
               f.tex_int( xi + 1, yi + 0 ) * ( 0 + xf ) * ( 1 - yf ) + 
               f.tex_int( xi + 0, yi + 1 ) * ( 1 - xf ) * ( 0 + yf ) + 
               f.tex_int( xi + 1, yi + 1 ) * ( 0 + xf ) * ( 0 + yf );
    }
    // 3D
    template<class T,class Img,class PT>
    T operator()( StructForType<T>, const Img &f, PT x, PT y, PT z ) const {
        assert( 0 /*TODO*/ );
        return 0;
    }
    Vec<double,nb_div> interp;
};


/** */
template<class T_,unsigned dim_,class Kernel_=ImgInterpBilinearKernel,class PT_=T_>
struct ImgInterp {
    typedef T_ T;
    static const unsigned dim = dim_;
    typedef Kernel_ Kernel;
    typedef PT_ PT;
    typedef ImgInterp T_NewImg;
    
    ///
    ImgInterp() : sizes( 1 ), div_2( NULL ) {}
    
    ///
    ImgInterp( const std::string &s ) : sizes( 1 ), div_2( NULL ) {
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
    ImgInterp &pyramidal_filter() const {
        if ( div_2 )
            return *div_2;
        div_2 = new ImgInterp;
        div_2->resize( sizes / 2 );
        for( Rectilinear_iterator<int,dim> p( 0, Vec<int,dim>(sizes-1), 2 ); p; ++p )
            div_2->tex_int( p.pos / 2 ) = operator()( p.pos + 0.5  );
        return *div_2;
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
                f.seekg( S[0] * ( S[1] - X1[1] ) * sizeof(TB), std::ios::cur );
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
    void load_ascii_mat_file( std::string filename ) {
        using namespace std;
        
        // sizes
        sizes = 0;
        ifstream f( filename.c_str() );
        string line;
        if ( getline( f, line ) ) {
            istringstream is( line );
            T val;
            while ( is >> val )
                sizes[0]++;
            sizes[1] = 1;
            while ( getline( f, line ) )
                sizes[1]++;
        }
            
        // data
        data.resize( product( sizes ) );
        f.clear();
        f.seekg( 0, ios::beg );
        for(unsigned i=0;i<data.size();++i)
            f >> data[ i ];
    }
    
    ///
    ImgInterp<T,dim> simple_blur() {
        ImgInterp<T,dim> res;
        res.resize( sizes - 2 );
        if ( dim == 3 ) {
            for(int z=1;z<sizes[2]-1;++z)
                for(int y=1;y<sizes[1]-1;++y)
                    for(int x=1;x<sizes[0]-1;++x)
                        res.tex_int( x-1, y-1, z-1 ) = ( tex_int( x, y, z ) + tex_int( x+1, y, z ) + tex_int( x-1, y, z ) + tex_int( x, y+1, z ) + tex_int( x, y-1, z ) + tex_int( x, y, z+1 ) + tex_int( x, y, z-1 ) ) / 7.0;
        } else if ( dim == 2 ) {
            for(int y=1;y<sizes[1]-1;++y)
                for(int x=1;x<sizes[0]-1;++x)
                    res.tex_int( x-1, y-1 ) = ( tex_int( x, y ) + tex_int( x+1, y ) + tex_int( x-1, y ) + tex_int( x, y+1 ) + tex_int( x, y-1 ) ) / 5.0;
        }
        return res;
    }
    
    ///
    void save( std::string filename, bool normalize = false ) const {
        QImage img = to_QImage( normalize );
        img.save( filename.c_str() );
    }
    
    ///
    void save_binary( std::string filename ) const {
        std::ofstream f( filename.c_str() );
        f.write( (char *)data.ptr(), sizeof(T) * data.size() );
    }
    
    ///
    int display( bool normalize = false ) {
        save( "pouet.png", normalize );
        return system( "display pouet.png &" );
    }
    
    ///
    inline T &tex_int( int x, int y ) {
        return data[ sizes[0] * max( 0, min( sizes[1]-1, y ) ) + max( 0, min( sizes[0]-1, x ) ) ];
    }
    
    ///
    inline T tex_int( int x, int y ) const {
        return data[ sizes[0] * max( 0, min( sizes[1]-1, y ) ) + max( 0, min( sizes[0]-1, x ) ) ];
    }
    
    ///
    inline T &tex_int( int x, int y, int z ) {
        x = max( 0, min( x, sizes[0]-1 ) );
        y = max( 0, min( y, sizes[1]-1 ) );
        z = max( 0, min( z, sizes[2]-1 ) );
        return data[ sizes[1] * sizes[0] * z + sizes[0] * y + x ];
    }
    
    ///
    inline T tex_int( int x, int y, int z ) const {
        x = max( 0, min( x, sizes[0]-1 ) );
        y = max( 0, min( y, sizes[1]-1 ) );
        z = max( 0, min( z, sizes[2]-1 ) );
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
        return kernel( StructForType<T>(), *this, x, y );
    }
    
    ///
    inline T operator()( PT x, PT y, PT z ) const {
        return kernel( StructForType<T>(), *this, x, y, z );
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
        return kernel.grad( StructForType<T>(), *this, p );
    }
    
    ///
    //     inline Vec<T,dim> grad( Vec<PT,dim> p, PT dec ) const {
    //         Vec<T,dim> res;
    //         for(int i=0;i<dim;++i)
    //             res[ i ] = ( operator()( Vec<PT,dim>( p + static_dirac_vec<dim>( dec / 2, i ) ) ) - operator()( p - static_dirac_vec<dim>( dec / 2, i ) ) ) / dec;
    //         return res;
    //     }
    
    ///
    void load_if_necessary( Vec<int,dim> MI, Vec<int,dim> MA, bool may_be_modified = false ) const {}
    
    ///
    Vec<T> data;
    Vec<int,dim> sizes;
    Kernel kernel;
    mutable ImgInterp<T,dim,Kernel> *div_2;
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



/*!
    \keyword Traitement_dimages
    
*/
template<class TT>
ImgInterp<TT,3> img_dist_from_front( const ImgInterp<TT,3> &mat, int max_dist, double diff_pix ) {
    typedef TT T;
    typedef Vec<int,3> P;
    
    ImgInterp<TT,3> dist;
    dist.resize( mat.sizes );
    dist.set( max_dist );
    
    Vec<P> front;
    for(int z=1;z<mat.sizes[2];++z) {
        for(int y=1;y<mat.sizes[1];++y) {
            for(int x=1;x<mat.sizes[0];++x) {
                if ( mat.tex_int(x,y,z) >= diff_pix ) {
                    if ( mat.tex_int(x-1,y,z) < diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x-1,y,z ) = 0.0; }
                    if ( mat.tex_int(x,y-1,z) < diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x,y-1,z ) = 0.0; }
                    if ( mat.tex_int(x,y,z-1) < diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x,y,z-1 ) = 0.0; }
                } else {
                    if ( mat.tex_int(x-1,y,z) >= diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x-1,y,z ) = 0.0; }
                    if ( mat.tex_int(x,y-1,z) >= diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x,y-1,z ) = 0.0; }
                    if ( mat.tex_int(x,y,z-1) >= diff_pix ) { front.push_back( P( x, y, z ) ); dist.tex_int( x, y, z ) = 0.0; dist.tex_int( x,y,z-1 ) = 0.0; }
                }
            }
        }
    }
    
    //
    unsigned of_front = 0;
    while ( of_front < front.size() ) {
        P p = front[ of_front++ ];
        int x = p[0];
        int y = p[1];
        int z = p[2];
        for(int oz=-1;oz<=1;++oz) {
            for(int oy=-1;oy<=1;++oy) {
                for(int ox=-1;ox<=1;++ox) {
                    if ( ox == 0 and oy == 0 and oz == 0 )
                        continue;
                    if ( x+ox >= 0 and y+oy >= 0 and z+oz >= 0 and x+ox < mat.sizes[0] and y+oy < mat.sizes[1] and z+oz < mat.sizes[2] ) {
                        T ndist = dist.tex_int( x, y, z ) + sqrt( ox * ox + oy * oy + oz * oz );
                        if ( ndist < dist.tex_int( x+ox, y+oy, z+oz ) ) {
                            front.push_back( P( x+ox, y+oy, z+oz ) );
                            dist.tex_int( x+ox, y+oy, z+oz ) = ndist;
                        }
                    }
                }
            }
        }
    }
    
    //
    for(int z=0;z<mat.sizes[2];++z)
        for(int y=0;y<mat.sizes[1];++y)
            for(int x=0;x<mat.sizes[0];++x)
                dist.tex_int( x, y, z ) *= ( mat.tex_int(x,y,z) >= diff_pix ? 1 : -1 );
            
    return dist;
}


/*!
    \keyword Traitement_dimages
    
*/
template<class TT>
ImgInterp<TT,2> img_dist_from_front( const ImgInterp<TT,2> &mat, int max_dist, TT diff_pix ) {
    typedef TT T;
    typedef Vec<int,2> P;
    
    ImgInterp<double,2> dist;
    dist.resize( mat.sizes );
    dist.set( max_dist );
    
    Vec<P> front;
    for(int y=1;y<mat.sizes[1];++y) {
        for(int x=1;x<mat.sizes[0];++x) {
            if ( mat.tex_int(x,y) >= diff_pix ) {
                if ( mat.tex_int(x-1,y) < diff_pix ) { front.push_back( P( x, y ) ); dist.tex_int( x, y ) = 0.0; dist.tex_int( x-1,y ) = 0.0; }
                if ( mat.tex_int(x,y-1) < diff_pix ) { front.push_back( P( x, y ) ); dist.tex_int( x, y ) = 0.0; dist.tex_int( x,y-1 ) = 0.0; }
            } else {
                if ( mat.tex_int(x-1,y) >= diff_pix ) { front.push_back( P( x, y ) ); dist.tex_int( x, y ) = 0.0; dist.tex_int( x-1,y ) = 0.0; }
                if ( mat.tex_int(x,y-1) >= diff_pix ) { front.push_back( P( x, y ) ); dist.tex_int( x, y ) = 0.0; dist.tex_int( x,y-1 ) = 0.0; }
            }
        }
    }
    
    //
    unsigned of_front = 0;
    while ( of_front < front.size() ) {
        P p = front[ of_front++ ];
        int x = p[0];
        int y = p[1];
        for(int oy=-1;oy<=1;++oy) {
            for(int ox=-1;ox<=1;++ox) {
                if ( ox == 0 and oy == 0 )
                    continue;
                if ( x+ox >= 0 and y+oy >= 0 and x+ox < mat.sizes[0] and y+oy < mat.sizes[1] ) {
                    T ndist = dist.tex_int( x, y ) + sqrt( ox * ox + oy * oy );
                    if ( ndist < dist.tex_int( x+ox, y+oy ) ) {
                        front.push_back( P( x+ox, y+oy ) );
                        dist.tex_int( x+ox, y+oy ) = ndist;
                    }
                }
            }
        }
    }
    
    //
    for(int y=0;y<mat.sizes[1];++y)
        for(int x=0;x<mat.sizes[0];++x)
            dist.tex_int( x, y ) *= ( mat.tex_int(x,y) >= diff_pix ? 1 : -1 );
            
    return dist;
}


}

#endif // LMT_IMG_INTERP_H

