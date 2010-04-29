//
// C++ Interface: fft
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_fft_HEADER
#define LMT_fft_HEADER

extern "C" {
    #include <fftw3.h>
}
#include "vec.h"
#include <correlation/ImgInterp.h>

#ifdef METIL_COMP_DIRECTIVE
#pragma lib_name fftw3
#endif

namespace LMT {

/*!
    Cette classe encapsule les fonctions de la librairie fftw \a http://www.fftw.org/ .

    \relates Vec
    \friend raphael.pasquier@lmt.ens-cachan.fr
*/
class FFT {
public:
    ///
    FFT():init(false) {
    }
    ///
    void clear_plan() {
        init = false;
    }
    ///
    template<int s> Vec<std::complex<double>,s> fft(const Vec<double,s> &v) {
        Vec<std::complex<double>,s> res; res.resize(v.size());
        const double *in = v.ptr();
        fftw_complex *out = (fftw_complex *)res.ptr();
        if ( init==false ) {
            p = fftw_plan_dft_r2c_1d(v.size(), const_cast<double *>(in), out, FFTW_ESTIMATE);
            fftw_execute(p);
        }
        else {
            fftw_execute_dft_r2c(p,const_cast<double *>(in),out);
        }
        return res;
    }
    ///
    template<int s> Vec<std::complex<double>,s> fft(const Vec<std::complex<double>,s> &v) {
        Vec<std::complex<double>,s> res; res.resize(v.size());
        const fftw_complex *in = (const fftw_complex *)v.ptr();
        fftw_complex *out = (fftw_complex *)res.ptr();
        if ( init==false ) {
            p = fftw_plan_dft_1d(v.size(), const_cast<fftw_complex *>(in), out, FFTW_FORWARD, FFTW_ESTIMATE);
            fftw_execute(p);
        }
        else {
            fftw_execute_dft(p,const_cast<fftw_complex *>(in),out);
        }
        return res;
    }
    
    template<int s> Vec<std::complex<double>,s> ffti(const Vec<std::complex<double>,s> &v) {
        //Vec<std::complex<double>,s> res = fft( v );
        Vec<std::complex<double>,s> res; res.resize(v.size());
        const fftw_complex *in = (const fftw_complex *)v.ptr();
        fftw_complex *out = (fftw_complex *)res.ptr();
        if ( init==false ) {
            p = fftw_plan_dft_1d(v.size(), const_cast<fftw_complex *>(in), out, FFTW_BACKWARD, FFTW_ESTIMATE);
            fftw_execute(p);
        }
        else {
            fftw_execute_dft(p,const_cast<fftw_complex *>(in),out);
        }        
        return res / (double)v.size();
    }
 

    /*!
        Cette fonction calcule Y[k1,k2] = somme pour j1=0..n1-1 pour j2=0..n2-1 de w1^(-j1*k1) w2^(-j2*k2)
        
        pour tous les k1 variant dans [[0..n1-1]] et k2 dans [[0..n2-1]]
        avec w1 := exp(sqrt(-1) 2 pi / n1)
             w2 := exp(sqrt(-1) 2 pi / n2)

        Le nombre complexe Y[k1,k2] est stocké à l'addresse k2+n2*k1 dans le tableau ImgInterp<T,dim,Kernel,PT>::data

        WARNING : les performances sont excellentes lorsque n1 et n2 sont des puissances de 2 (cf algorithme de la transformée de Fourier rapide FFT)
                  sinon elles sont moins bonnes en général, voire très mauvaises si n1 ou n2 n'est pas un multiple de petits nombres premiers.
    */
    template<int dim,class Kernel_,class PT_>
    ImgInterp<std::complex<double>,dim,Kernel_,PT_> fft(const ImgInterp<std::complex<double>,dim,Kernel_,PT_> &i) {
        ImgInterp<std::complex<double>,dim,Kernel_,PT_> res;
        res.resize(i.size());
        const fftw_complex *in = (const fftw_complex *)i.data.ptr();
        fftw_complex *out = (fftw_complex *) res.data.ptr();
        if ( init==false ) {
            Vec<int,dim> s = i.sizes; //[ dim - 1 - range( dim ) ];
            p = fftw_plan_dft( dim, s.ptr(), const_cast<fftw_complex *>(in), out, FFTW_FORWARD, FFTW_ESTIMATE );
            fftw_execute( p );
        } else {
            fftw_execute_dft( p, const_cast<fftw_complex *>( in ), out );
        }
        return res;
    }

    /*!
        Cette fonction calcule Y[k1,k2] = somme pour j1=0..n1-1 pour j2=0..n2-1 de w1^(j1*k1) w2^(j2*k2)
        
        pour tous les k1 variant dans [[0..n1-1]] et k2 dans [[0..n2-1]]
        avec w1 := exp(sqrt(-1) 2 pi / n1)
             w2 := exp(sqrt(-1) 2 pi / n2)

        Le nombre complexe Y[k1,k2] est stocké à l'addresse k2+n2*k1 dans le tableau ImgInterp<T,dim,Kernel,PT>::data

        WARNING : les performances sont excellentes lorsque n1 et n2 sont des puissances de 2 (cf algorithme de la transformée de Fourier rapide FFT)
                  sinon elles sont moins bonnes en général, voire très mauvaises si n1 ou n2 n'est pas un multiple de petits nombres premiers.
    */
    template<int dim,class Kernel_,class PT_>
    ImgInterp<std::complex<double>,dim,Kernel_,PT_> ffti(const ImgInterp<std::complex<double>,dim,Kernel_,PT_> &i) {
        ImgInterp<std::complex<double>,dim,Kernel_,PT_> res;
        res.resize( i.size() );
        const fftw_complex *in = (const fftw_complex *)i.data.ptr();
        fftw_complex *out = (fftw_complex *) res.data.ptr();
        if ( init==false ) {
            if ( dim == 2 )
                p = fftw_plan_dft_2d( i.sizes[1], i.sizes[0], const_cast<fftw_complex *>(in), out, FFTW_BACKWARD, FFTW_ESTIMATE);
            else
                p = fftw_plan_dft_3d( i.sizes[2], i.sizes[1], i.sizes[0], const_cast<fftw_complex *>(in), out, FFTW_BACKWARD, FFTW_ESTIMATE);
            fftw_execute(p);
        }
        else {
            fftw_execute_dft(p,const_cast<fftw_complex *>(in),out);
        }
        res.data /= std::complex<double>( res.data.size() );
        return res;
    }

    bool init; /// true if at least one FFT has been queried.
    fftw_plan p;
};

/*!
    Cette classe sert à faire un padding symétrique BBBB.
    Si div_2 est false, la transformée de Fourier , TF, est calculée sur toute l'image BBBB : i.e. sur une image 4 fois plus grande que l'image initiale.
    Sinon une moyenne "mobile" étendue sur 4 pixels en carré est faite sur l'image BBBB avant de faire la TF. Du coup Le résultat est une image de même taille que l'image initiale. 

*/
struct SymmetricPadding { 
    bool div_2; 
    SymmetricPadding():div_2(false) {}
    SymmetricPadding(bool d2):div_2(d2) {}
};

/*!
    Cette classe sert à faire un padding qui met à zéro les pixels des bors de l'image avant de faire la transformée de Fourier , TF.
     
*/
struct ZeroPadding {};

/*!
    \generic_comment fft

    Cette fonction calcule la transformée de Fourier d'une image après lui avoir appliqué un "padding".

*/
/*!
    \generic_comment ffti

    Cette fonction calcule la transformée de Fourier inverse d'une image sur laquelle un "padding" a été appliqué.

*/
//template<class T_, unsigned dim_, class Kernel_, class PT_, class TPadding>
//ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, Vec<int,dim_> topleft, Vec<int,dim_> bottomright, const TPadding padding) {
//    fft( img, topleft[0], bottomright[0], topleft[1], bottomright[1], padding);
//}
    
//template<class T_,unsigned dim_,class Kernel_,class PT_,class TPadding>
//ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, int xmin, int xmax, int ymin, int ymax, const TPadding padding) {
//    assert(0);
//    return ImgInterp<std::complex<double>,dim_,Kernel_,PT_>();
//}
  
//template<class T_, unsigned dim_, class Kernel_, class PT_, class TPadding>
//        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> ffti( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, Vec<int,2> topleft, Vec<int,2> bottomright, const TPadding padding) {
//    ffti( img, topleft[0], bottomright[0], topleft[1], bottomright[1], padding);
//}
    
//template<class T_,unsigned dim_,class Kernel_,class PT_,class TPadding>
//        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> ffti( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, int xmin, int xmax, int ymin, int ymax, const TPadding padding) {
//    assert(0);
//    return ImgInterp<std::complex<double>,dim_,Kernel_,PT_>();
//}
  
template<class T_,unsigned dim_,class Kernel_,class PT_> 
ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, Vec<int,dim_> xmin, Vec<int,dim_> xmax, const SymmetricPadding padding ) {
    Vec<int,dim_> x_in_max = ( xmax - xmin + 1 ) * 2 - 1;

    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> in;
    in.resize( x_in_max + 1 );
    assert( dim_ == 2 /*TODO*/ );
    for(int jj=xmin[0];jj<=xmax[0];++jj) {
        int j = jj - xmin[ 0 ];
        for(int ii=xmin[1];ii<=xmax[1];++ii) {
            int i = ii - xmin[ 1 ];
            std::complex<double> tmp = img(jj,ii);
            in.tex_int(j,i) = tmp;
            in.tex_int(x_in_max[0]-j,i) = tmp;
            in.tex_int(j,x_in_max[1]-i) = tmp;
            in.tex_int(x_in_max[0]-j,x_in_max[1]-i) = tmp;
        }
    }
    
    if ( padding.div_2 )
        in = in.pyramidal_filter();

    FFT p;
    return p.fft(in);
}

template<class T_,int dim_,class Kernel_,class PT_>
ImgInterp<std::complex<double>,dim_,Kernel_,PT_> ffti( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, const SymmetricPadding padding ) {

    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> in,tem;
    FFT p;
    
    tem = p.ffti(img);
    in.resize( img.sizes / 2 );
    for( Rectilinear_iterator<int,dim_> iter( 0, in.sizes ); iter; ++iter )
        in.tex_int( iter.pos ) = tem( iter.pos );
    return in;
}

//template<class T_,unsigned dim_,class Kernel_,class PT_>
//        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, Vec<int,2> topleft, Vec<int,2> bottomright, SymmetricPadding padding) {
//    fft( img, topleft[0], bottomright[0], topleft[1], bottomright[1], padding);
//}

template<int dim_,class T_,class Kernel_,class PT_>
ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, Vec<int,dim_> xmin, Vec<int,dim_> xmax, ZeroPadding ) {

    Vec<int,dim_> x_in_max = xmax - xmin + 1;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> in;

    in.resize( x_in_max + 1 );
    in.data.set( 0 );
    for( Rectilinear_iterator<int,dim_> iter( 0, x_in_max ); iter; ++iter )
        in.tex_int( iter.pos ) = img( iter.pos + xmin );

    FFT p;
    return p.fft<dim_>( in );
}

//template<class T_,unsigned dim_,class Kernel_,class PT_>
//        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, Vec<int,2> topleft, Vec<int,2> bottomright, ZeroPadding padding) {
//    fft( img, topleft[0], bottomright[0], topleft[1], bottomright[1], padding);
//}

template<class T_,unsigned dim_,class Kernel_,class PT_>
ImgInterp<std::complex<double>,dim_,Kernel_,PT_> ffti( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, const ZeroPadding padding ) {
    FFT p;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> tem = p.ffti<dim_>( img );
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> in; in.resize( img.sizes - 1 );
    for( Rectilinear_iterator<int,dim_> iter( 0, in.sizes ); iter; ++iter )
            in.tex_int( iter.pos ) = tem( iter.pos );
    return in;
}

/*!
    Cette fonction retourne une approximation de la corrélation entre les deux images i et i2 dans le rectangle [xmin, xmax]x[ymin, ymax].

    Réf : http://pixel-shaker.fr/

*/
template< int dim_, class T_, class Kernel_,class PT_>
Vec<int,dim_> rigid_body_translation( const ImgInterp<T_,dim_,Kernel_,PT_> &i, const ImgInterp<T_,dim_,Kernel_,PT_> &i2, Vec<int,dim_> xmin, Vec<int,dim_> xmax ) {
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> _i ; _i .resize( i .size() ); _i .data = i .data;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> _i2; _i2.resize( i2.size() ); _i2.data = i2.data;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> img  = fft<dim_>( _i , xmin, xmax, ZeroPadding());
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> img2 = fft<dim_>( _i2, xmin, xmax, ZeroPadding());
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> img3 = abs(img);
    img.data  /= img3.data;
    img2.data /= img3.data;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> img4 = img * conj(img2);
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> img5 = ffti( img4, ZeroPadding() );
    double maxi = std::numeric_limits<double>::max();
    Vec<int,dim_> res( 0 );
    for( Rectilinear_iterator<int,dim_> iter( 0, img5.sizes ); iter; ++iter ) {
        if ( maxi > real( img5( iter.pos ) ) ) {
            maxi = real( img5( iter.pos ) );
            res = iter.pos;
        }
    }

    res = ( ( res + img5.sizes / 2 ) % img5.sizes ) - img5.sizes / 2;
    res += ( 2 * ( res > 0 ) - 1 ) * ( res != 0 );
    return res;
}

}

#endif // LMT_fft_HEADER
