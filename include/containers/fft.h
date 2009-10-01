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
// #include "containers/vec.h"
#include "vec.h"
// #include "vecfull.h"
#include <correlation/ImgInterp.h>

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
    template<unsigned dim_,class Kernel_,class PT_> 
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_>  fft(const ImgInterp<std::complex<double>,dim_,Kernel_,PT_> &i) {
        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> res;
        res.resize(i.size());
        const fftw_complex *in = (const fftw_complex *)i.data.ptr();
        fftw_complex *out = (fftw_complex *) res.data.ptr();
        if ( init==false ) {
            p = fftw_plan_dft_2d( i.sizes[1], i.sizes[0], const_cast<fftw_complex *>(in), out, FFTW_FORWARD, FFTW_ESTIMATE);
            fftw_execute(p);
        }
        else {
            fftw_execute_dft(p,const_cast<fftw_complex *>(in),out);
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
    template<unsigned dim_,class Kernel_,class PT_>
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> ffti(const ImgInterp<std::complex<double>,dim_,Kernel_,PT_> &i) {
        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> res;
        res.resize(i.size());
        const fftw_complex *in = (const fftw_complex *)i.data.ptr();
        fftw_complex *out = (fftw_complex *) res.data.ptr();
        if ( init==false ) {
            p = fftw_plan_dft_2d( i.sizes[1], i.sizes[0], const_cast<fftw_complex *>(in), out, FFTW_BACKWARD, FFTW_ESTIMATE);
            fftw_execute(p);
        }
        else {
            fftw_execute_dft(p,const_cast<fftw_complex *>(in),out);
        }
        //res.data /= product(i.sizes);
        //res.data = res.data / (i.sizes[0] * i.sizes[1]);
        int total_size = i.sizes[0] * i.sizes[1];
        double inv_total_size = double(1.0 /(i.sizes[0] * i.sizes[1]));
        for(int i=0;i<total_size;++i)
            res.data[i] *= inv_total_size;
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
    Cette classe sert à faire un padding qui met des zéros autour de l'image avant de la transformée de Fourier , TF.
    Du coup Le résultat est une image de taille augmentée de deux pixels suivant chaque dimension. 

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
template<class T_, unsigned dim_, class Kernel_, class PT_, class TPadding> 
ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, Vec<int,2> topleft, Vec<int,2> bottomright, const TPadding padding) {
    fft( img, topleft[0], bottomright[0], topleft[1], bottomright[1], padding);
}
    
template<class T_,unsigned dim_,class Kernel_,class PT_,class TPadding> 
ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, int xmin, int xmax, int ymin, int ymax, const TPadding padding) {
    assert(0);
    return ImgInterp<std::complex<double>,dim_,Kernel_,PT_>();
}
  
template<class T_, unsigned dim_, class Kernel_, class PT_, class TPadding> 
        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> ffti( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, Vec<int,2> topleft, Vec<int,2> bottomright, const TPadding padding) {
    ffti( img, topleft[0], bottomright[0], topleft[1], bottomright[1], padding);
}
    
template<class T_,unsigned dim_,class Kernel_,class PT_,class TPadding> 
        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> ffti( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, int xmin, int xmax, int ymin, int ymax, const TPadding padding) {
    assert(0);
    return ImgInterp<std::complex<double>,dim_,Kernel_,PT_>();
}
  
template<class T_,unsigned dim_,class Kernel_,class PT_> 
        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, int xmin, int xmax, int ymin, int ymax, const SymmetricPadding padding) {
    int x_in_max = (xmax-xmin+1)*2-1 , y_in_max = (ymax-ymin+1)*2-1,i,j;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> in;//,tem;
    FFT p;

    in.resize(Vec<int,2>(x_in_max+1,y_in_max+1));
    for(int jj=xmin;jj<=xmax;++jj) {
        j = jj-xmin;
        for(int ii=ymin;ii<=ymax;++ii) {
            i = ii-ymin;
            std::complex<double> tmp = img(jj,ii);
            in.tex_int(j,i) = tmp;
            in.tex_int(x_in_max-j,i) = tmp;
            in.tex_int(j,y_in_max-i) = tmp;
            in.tex_int(x_in_max-j,y_in_max-i) = tmp;
        }
    }
    
    if (padding.div_2)
        in = in.pyramidal_filter();

    return p.fft(in);
}

template<class T_,unsigned dim_,class Kernel_,class PT_> 
        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> ffti( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, const SymmetricPadding padding) {

    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> in,tem;
    FFT p;
    
    tem = p.ffti(img);
    in.resize(Vec<int,2>(img.sizes[0]/2,img.sizes[1]/2));
    for(int i=0;i<in.sizes[1];++i)
        for(int j=0;j<in.sizes[0];++j)
            in.tex_int(j,i) = tem(j,i);
    return in;
}

template<class T_,unsigned dim_,class Kernel_,class PT_> 
        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, Vec<int,2> topleft, Vec<int,2> bottomright, SymmetricPadding padding) {
    fft( img, topleft[0], bottomright[0], topleft[1], bottomright[1], padding);
}

template<class T_,unsigned dim_,class Kernel_,class PT_> 
        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, int xmin, int xmax, int ymin, int ymax, ZeroPadding padding) {
    int x_in_max = xmax-xmin , y_in_max = ymax-ymin, i, j;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> in;
    FFT p;

    in.resize(Vec<int,2>(x_in_max+1,y_in_max+1));
    for(int jj=xmin+1;jj<xmax;++jj) {
        j = jj-xmin;
        for(int ii=ymin+1;ii<ymax;++ii) {
            i = ii-ymin;
            in.tex_int(j,i) = img(jj,ii);
        }
    }
    for(i=0;i<=y_in_max;++i)
        in.tex_int(0,i) = 0;
    for(i=0;i<=y_in_max;++i)
        in.tex_int(x_in_max,i) = 0;    
    for(j=0;j<=x_in_max;++j)
        in.tex_int(j,0) = 0; 
    for(j=0;j<=x_in_max;++j)
        in.tex_int(j,y_in_max) = 0; 
    return p.fft(in);
}

template<class T_,unsigned dim_,class Kernel_,class PT_> 
        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, Vec<int,2> topleft, Vec<int,2> bottomright, ZeroPadding padding) {
    fft( img, topleft[0], bottomright[0], topleft[1], bottomright[1], padding);
}

template<class T_,unsigned dim_,class Kernel_,class PT_> 
        ImgInterp<std::complex<double>,dim_,Kernel_,PT_> ffti( const ImgInterp<std::complex<T_>, dim_, Kernel_, PT_ > &img, const ZeroPadding padding) {

    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> tem, in;
    FFT p;
    int i,j;

    tem = p.ffti(img);
    in.resize(Vec<int,2>(img.sizes[0]-2,img.sizes[1]-2));
    for(j=0;j<in.sizes[0];++j)
        for(i=0;i<in.sizes[1];++i)
            in.tex_int(j,i) = tem(j+1,i+1);
    return in;
}

/*!
    Cette fonction retourne une approximation de la corrélation entre les deux images i et i2 dans le rectangle [xmin, xmax]x[ymin, ymax].

    Réf : http://pixel-shaker.fr/

*/
template<class T_,unsigned dim_,class Kernel_,class PT_>
Vec<int,2> rigid_body_translation( const ImgInterp<T_,dim_,Kernel_,PT_> &i, const ImgInterp<T_,dim_,Kernel_,PT_> &i2, int xmin, int xmax, int ymin, int ymax ) {
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> _i;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> _i2;
    _i.resize(i.size());
    _i2.resize(i2.size());
    _i.data = i.data;
    _i2.data = i2.data;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> img  = fft(_i,  xmin, xmax, ymin, ymax, ZeroPadding());
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> img2 = fft(_i2, xmin, xmax, ymin, ymax, ZeroPadding());
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> img3 = abs(img);
    img.data  /= img3.data;
    img2.data /= img3.data;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> img4 = img * conj(img2);
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> img5 = ffti( img4, ZeroPadding() );
    ImgInterp<double,dim_,Kernel_,PT_> img6;
    img6.data = real(img5.data);
    img6.resize(img5.size());
    double maxi = max(img6.data);
    Vec<unsigned int> indices = find_with_index( generate( img6.data, _1 == maxi ) );
    
    if (indices.size()) {
        int sx = img6.sizes[0];
        int sy = img6.sizes[1];
        int x = indices[0] % sx;
        int y = (indices[0] - x) / sx;
        x = ((x+sx/2) % (sx)) - sx/2;
        y = ((y+sy/2) % (sy)) - sy/2;
        if (x)
            x += sgn(x);
        if (y)
            y += sgn(y);
        if (abs(x)+abs(y) < 4)
            std::cerr << "WARNING rigid_body_translation : do you really need to use the function ? because abs(x)+abs(y) = " << abs(x)+abs(y) << std::endl;
        return Vec<int,2>(x,y);
    } else {
        std::cerr << "ERROR rigid_body_translation : there is not maximum." << std::endl;
        return Vec<int,2>(0,0);
    }
}

};

#endif // LMT_fft_HEADER
