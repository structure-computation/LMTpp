//
// C++ Interface: matlabhelp
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matlabhelp_HEADER
#define LMT_matlabhelp_HEADER

#ifdef MATLAB_MEX_FILE
    extern "C"{
        #include "mex.h"
    }
    #include <stdexcept>
    #define PRINTM(A) { \
        std::ostringstream os; \
        os << A; \
        printf( "%s\n", os.str().c_str() ); \
    }
    template<class T> struct mxArrayGoodtype;
    template<> struct mxArrayGoodtype<double> {
        static bool res(const mxArray *variable) { return mxIsDouble(variable); }
        typedef double needed;
    };
    template<> struct mxArrayGoodtype<float> {
	    static bool res(const mxArray *variable) { return mxIsDouble(variable); }
	    typedef double needed;
    };
    template<> struct mxArrayGoodtype<int> {
	    static bool res(const mxArray *variable) { return mxIsDouble(variable); }
	    typedef double needed;
    };
    template<> struct mxArrayGoodtype<unsigned> {
	    static bool res(const mxArray *variable) { return mxIsDouble(variable); }
	    typedef double needed;
    };
    template<> struct mxArrayGoodtype<std::complex<float> > {
        static bool res(const mxArray *variable) { return mxIsComplex(variable) || mxIsDouble(variable); }
        typedef double needed;
    };
    template<> struct mxArrayGoodtype<std::complex<double> > {
        static bool res(const mxArray *variable) { return mxIsComplex(variable) || mxIsDouble(variable); }
        typedef double needed;
    };
    template<class T> void printm(const T &val) {
        std::ostringstream os;
        os << val;
        printf( "%s\n", os.str().c_str() );
    }
#endif


#endif // LMT_matlabhelp_HEADER
