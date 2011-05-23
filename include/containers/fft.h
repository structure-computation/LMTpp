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
//#include "dic/correlation/ImgInterp.h" /// du dépot dic 

#ifdef METIL_COMP_DIRECTIVE
#pragma lib_name fftw3
#endif

namespace LMT {

template<class T_,unsigned dim_,class Kernel_,class PT_> struct ImgInterp;

/*!
    Cette classe encapsule les fonctions de la librairie fftw \a http://www.fftw.org/ .
    
    Voici un exemple où on calcule la transformée de Fourier d'un vecteur puis la transformée de Fourier inverse. remarquez qu'on ne revient pas au vecteur initial. Il faut diviser par la longueur du vecteur pour s'y ramener.
    \Code C/C++
        #include <complex>
        #include "containers/fft.h"
        
        using namespace LMT;
        using namespace std;
    
        int main() {
            FFT t;
            
            Vec< double > v;
            Vec< complex< double > > vc, vc2;
            
            v.resize( 10 );
            for( unsigned i = 0; i < v.size(); i++ )
                v[ i ] = 1 + i;
            
            vc  = t.fft(  v );
            vc2 = t.ffti( vc );
            PRINT( v  );
            PRINT( vc );
        
            return 0;
        }
        

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
    template<int s> 
    Vec< std::complex< double >, s > fft( const Vec< double, s > &v ) {
        Vec<std::complex<double>,s> res; res.resize( v.size() );
        const double *in = v.ptr();
        fftw_complex *out = (fftw_complex *) res.ptr();
        if ( init == false ) {
            p = fftw_plan_dft_r2c_1d( v.size(), const_cast<double *>(in), out, FFTW_ESTIMATE );
            fftw_execute( p );
        }
        else {
            fftw_execute_dft_r2c(p,const_cast<double *>(in),out);
        }
        for( unsigned i = 1; i <= v.size() / 2; ++i ) 
            res[ v.size() - i ] = std::conj( res[ i ] );
        return res;
    }
    ///
    template<int s> 
    Vec<std::complex<double>,s> fft(const Vec<std::complex<double>,s> &v) {
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
    
    template<int s> 
    Vec< std::complex< double >, s > ffti( const Vec< std::complex< double >, s > &v ) {
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
            fftw_destroy_plan( p );
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
            fftw_destroy_plan( p );
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

}
#endif // LMT_fft_HEADER
