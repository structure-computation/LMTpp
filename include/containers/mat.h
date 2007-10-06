//
// C++ Interface: mat
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_mat_HEADER
#define LMT_mat_HEADER

#include "vec.h"
#include "structure.h"
#include "storage.h"
#include "matelem.h"
#include <iomanip>
#include <fstream>
#include "containers/evaluate_nb_cycles.h"

namespace LMT {

template<class MATOP> struct IsMatOp { typedef void T; };

/**
    \todo SIMD alignement for Row on Lower and Col on Upper
*/
template<class T=double,class Structure=Gen<-1,-1>,class Storage=Dense<Col>,class ismatop=typename IsMatOp<T>::T>
class Mat;

template<class TM,bool const_tm,class TV1,class TV2=void> struct SubMat;

/**
    \relates Mat
*/
template<class T,class Structure,class Storage,class OP>
std::ostream &operator<<(std::ostream &os,const Mat<T,Structure,Storage,OP> &m) {
    for(unsigned i=0;i<m.nb_rows();++i) {
        for(unsigned j=0;j<m.nb_cols();++j)
            os << std::setw(8) << m(i,j) << " ";
        os << "\n";
    }
    return os;
}
/**
    \relates Mat
*/
template<class T,class Structure,class Storage,class OP>
std::istream &operator>>(std::istream &is,Mat<T,Structure,Storage,OP> &m) {
    for(unsigned i=0;i<m.nb_rows();++i) {
        for(unsigned j=0;j<m.nb_cols();++j) {
            T v;
            is >> v;
            if ( v )
                m(i,j) = v;
        }
    }
    return is;
}

template<class TT,class Structure,class Storage,class OP>
std::istream &line_input( std::istream &s, Mat<TT,Structure,Storage,OP> &m ) {
    typename Mat<TT,Structure,Storage,OP>::T t;
    for(unsigned i=0;i<m.nb_rows();++i)
        for(unsigned j=(i+(!Structure::need_diag))*(1-Structure::need_lower);
                j<m.nb_cols()*Structure::need_upper+(i+Structure::need_diag)*(!Structure::need_upper);++j) {
            s >> t;
            m(i,j) = t;
        }
    return s;
}


template<class TTV,class Structure,class Storage,class OP>
struct TypeInformation<Mat<TTV,Structure,Storage,OP> > {
    typedef typename Mat<TTV,Structure,Storage,OP>::T TT;
    static const int res = TypeInformation<TT>::res;
    static const int englobing = 20 + TypeInformation<TT>::englobing;
    typedef TT SubType;
    template<class TV> struct Variant { typedef Mat<TV,Structure,Storage,OP> T; };
    template<class TV> struct DeepVariant { typedef Mat<typename TypeInformation<TT>::template DeepVariant<TV>::T,Structure,Storage,OP> T; };
    static std::string type() { return "Mat<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};

/**
*/
template<class STR,class Op> struct StructureTypeWithOp { typedef Gen<> T; };

template<int s,class Op> struct StructureTypeWithOp<AntiSym<s>,Op> {
    typedef typename AlternativeOnType< ConserveZeroes<Op>::res,
        Gen<s,s>,
        AntiSym<s>
    >::T T;
};
template<int s,class Op> struct StructureTypeWithOp<Diag<s>,Op> {
    typedef typename AlternativeOnType< ConserveZeroes<Op>::res,
        Gen<s,s>,
        Diag<s>
    >::T T;
};
template<int s1,int s2,class Op> struct StructureTypeWithOp<TriUpper<s1,s2>,Op> {
    typedef typename AlternativeOnType< ConserveZeroes<Op>::res,
        Gen<s1,s2>,
        TriUpper<s1,s2>
    >::T T;
};
template<int s1,int s2,class Op> struct StructureTypeWithOp<TriLower<s1,s2>,Op> {
    typedef typename AlternativeOnType< ConserveZeroes<Op>::res,
        Gen<s1,s2>,
        TriLower<s1,s2>
    >::T T;
};
template<int s,class Op> struct StructureTypeWithOp<Herm<s>,Op> {
    typedef typename AlternativeOnType< ConserveZeroes<Op>::res,
        Gen<s,s>,
        Herm<s>
    >::T T;
};

///
template<class T,class STR,class STO,class IO>
T mean(const Mat<T,STR,STO,IO> &m) {
    T res = 0.0;
    for(unsigned i=0;i<m.nb_rows();++i)
        res += sum( m.row(i) );
    return res / T( m.nb_rows() * m.nb_cols() );
}

///
template<class T,class STR,class STO,class IO>
T max(const Mat<T,STR,STO,IO> &m) {
    T res = -std::numeric_limits<T>::max();
    for(unsigned i=0;i<m.nb_rows();++i)
        res = max( res, max( m.row(i) ) );
    return res;
}

///
template<class T,class STR,class STO,class IO>
T min(const Mat<T,STR,STO,IO> &m) {
    T res = std::numeric_limits<T>::max();
    for(unsigned i=0;i<m.nb_rows();++i)
        res = min( res, min( m.row(i) ) );
    return res;
}

};

#include "vecsubmat.h"
#include "matdense.h"
#include "matsparse.h"
#include "matskyline.h"
#include "mattrans.h"
#include "matop.h"
#include "matunary.h"
#include "matbinary.h"
#include "matsubmat.h"
#include "matmult.h"
#include "matinv.h"
#include "matparticularcases.h"
#include "matpointed.h"
#include "matsparselu.h"
#include "MatWithTinyBlocks.h"

namespace LMT {

template<class TV,int s>
Mat<TV,Diag<s> > diag(const Vec<TV,s> &vec) {
    return Mat<TV,Diag<s> >(vec.size(),vec.size(),vec);
}


#ifdef MATLAB_MEX_FILE
    /** Convert a LMT::Mat to a matlab one
        \relates Mat
    */
    template<class TT,class STR,class O,class IO>
    mxArray *to_matlab(const Mat<TT,STR,Dense<O>,IO> &mat) {
        typedef typename Mat<TT,STR,Dense<O>,IO>::T TV;
        /* Test if double (mxReal) or complex<double> (mxComplex)*/
        if ( CanBeConvertedTo<TV,double>::res==false && CanBeConvertedTo<TV,std::complex<double> >::res==false ) {
            printf("error : in Mat -> mxArray, mat must be be convertible to Mat<double> or Mat<complex<double> >\n");
            return NULL;
        }
        /* Create the ouput matrix */
        mxArray *res = mxCreateDoubleMatrix(
                        mat.nb_rows(),
                        mat.nb_cols(),
                        ( CanBeConvertedTo<TV,double>::res ? mxREAL : mxCOMPLEX )
                    );
        /* Pointer to the real part*/
        double *pr = mxGetPr(res);
        for(unsigned int i=0;i<mat.nb_rows();++i) {
            for(unsigned int j=0;j<mat.nb_cols();++j) {
                pr[(mat.nb_rows()*j)+i]=LMT::real(mat(i,j));
            }
        }
        /* Pointer to the imaginary part if necessary*/
        if ( CanBeConvertedTo<TV,double>::res==false ) {
    
            double *pi = mxGetPi(res);
            for(unsigned int i=0;i<mat.nb_rows();++i) {
                for(unsigned int j=0;j<mat.nb_cols();++j) {
                    pi[(mat.nb_rows()*j)+i]=LMT::imag(mat(i,j));
                }
            }
        }
        return res;
    }
#endif

/// ostream interface
template<class T,class Str,class Sto,class IO>
void display_structure(const Mat<T,Str,Sto,IO> &mat,const char *name_file="res") {
    typedef typename Mat<T,Str,Sto,IO>::T TT;
    using namespace std;
    
    ofstream f(name_file);
    
    double m = 0.0;
    for(unsigned l=0;l<mat.nb_rows();++l)
        for(unsigned c=0;c<mat.nb_cols();++c)
            m = max( m, std::abs((TT)mat(l,c)) );
        
    for(unsigned l=0;l<mat.nb_rows();++l)
        for(unsigned c=0;c<mat.nb_cols();++c)
            f.put(  255 - ((TT)mat(l,c)!=0.0) * 200 - (std::abs((TT)mat(l,c))>1e-6*m) * 55 );
        
    f.close();
    
    ostringstream s,s2;
    s << "display -depth 8 -size " << mat.nb_cols() << "x" << mat.nb_rows() << " gray:" << name_file;
    system(s.str().c_str());
    
    s2 << "convert -depth 8 -size " << mat.nb_cols() << "x" << mat.nb_rows() << " gray:" << name_file << " " << name_file << ".png";
    system(s2.str().c_str());
}


};

#endif // LMT_mat_HEADER
