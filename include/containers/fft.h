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
 
    ///
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

struct SymmectricPadding { 
    bool div_2; 
    SymmectricPadding():div_2(false) {}
    SymmectricPadding(bool d2):div_2(d2) {}
};
struct ZeroPadding {};

template<class T_, unsigned dim_, class Kernel_, class PT_, class TPadding> 
ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft(ImgInterp<T_, dim_, Kernel_, PT_ > &img, Vec<int,2> topleft, Vec<int,2> bottomright, TPadding padding) {
    fft( img, topleft[0], bottomright[0], topleft[1], bottomright[1], padding);
}
    
template<class T_,unsigned dim_,class Kernel_,class PT_,class TPadding> 
ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( ImgInterp<T_, dim_, Kernel_, PT_ > &img, int xmin, int xmax, int ymin, int ymax, TPadding padding) {
    assert(0);
    return ImgInterp<std::complex<double>,dim_,Kernel_,PT_>();
}
    
template<class T_,unsigned dim_,class Kernel_,class PT_> 
ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( ImgInterp<T_, dim_, Kernel_, PT_ > &img, int xmin, int xmax, int ymin, int ymax, SymmectricPadding padding) {
    int x_in_max = (xmax-xmin+1)*2-1 , y_in_max = (ymax-ymin+1)*2-1,i,j;
    ImgInterp<std::complex<double>,dim_,Kernel_,PT_> in, out;//,tem;
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

    PRINT(in.sizes);
    out = p.fft(in);
    PRINT(out.sizes);
    return out;
}

template<class T_,unsigned dim_,class Kernel_,class PT_> 
ImgInterp<std::complex<double>,dim_,Kernel_,PT_> fft( ImgInterp<T_, dim_, Kernel_, PT_ > &img, Vec<int,2> topleft, Vec<int,2> bottomright, SymmectricPadding padding) {
    fft( img, topleft[0], bottomright[0], topleft[1], bottomright[1], padding);
}



};

#endif // LMT_fft_HEADER
