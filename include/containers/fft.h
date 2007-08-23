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
#include "mat.h"

namespace LMT {

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
    
    bool init; /// true if at least one FFT has been queried.
    fftw_plan p;
};

};

#endif // LMT_fft_HEADER
