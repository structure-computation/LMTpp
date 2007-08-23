#ifndef AUTODIFF_H
#define AUTODIFF_H

#include <containers/mat.h>

namespace LMT {

/**
    \ingroup Toto
    AutoDiff
 */
template<class T,int num_unk=-1> struct AutoDiff {
    AutoDiff(T v=0.0) {
        val = v;
        if ( num_unk >= 0 ) {
            der_1 = 0.0;
            der_2.set( 0.0 );
        }
    }
    T val;
    Vec<T,num_unk> der_1;
    Mat<T,Gen<num_unk,num_unk> > der_2;
};

template<class TT,int n> struct TypeInformation<AutoDiff<TT,n> > {
    static const int res = TypeInformation<TT>::res;
    static const int englobing = 1 + TypeInformation<TT>::englobing;
    typedef TT SubType;
    template<class TV> struct Variant { typedef AutoDiff<TV,n> T; };
    template<class TV> struct DeepVariant { typedef AutoDiff<typename TypeInformation<TT>::template DeepVariant<TV>::T,n> T; };
    static std::string type() { return "AutoDiff<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};
template<class TT,int n> struct HasTypeInformation<AutoDiff<TT,n> > { static const bool res = true; };


template<class T,int n> AutoDiff<T,n> operator-(const AutoDiff<T,n> &a,const AutoDiff<T,n> &b) {
    AutoDiff<T,n> res;
    res.val = a.val - b.val;
    res.der_1 = a.der_1 - b.der_1;
    res.der_2 = a.der_2 - b.der_2;
    return res;
}

template<class T,int n> AutoDiff<T,n> operator+(const AutoDiff<T,n> &a,const AutoDiff<T,n> &b) {
    AutoDiff<T,n> res;
    res.val = a.val + b.val;
    res.der_1 = a.der_1 + b.der_1;
    res.der_2 = a.der_2 + b.der_2;
    return res;
}

template<class T,int n> AutoDiff<T,n> operator*(const AutoDiff<T,n> &a,const AutoDiff<T,n> &b) {
    AutoDiff<T,n> res;
    res.val = a.val * b.val;
    res.der_1 = a.val * b.der_1 + a.der_1 * b.val;
    for(unsigned i=0;i<n;++i)
        for(unsigned j=0;j<n;++j)
            res.der_2(i,j) = a.der_2(i,j)*b.val + a.der_1[i]*b.der_1[j] + a.der_1[j]*b.der_1[i] + a.val*b.der_2(i,j);
    return res;
}

template<class T,int n> AutoDiff<T,n> sqrt(const AutoDiff<T,n> &a) {
    AutoDiff<T,n> res;
    res.val = sqrt(a.val);
    res.der_1 = 0.5 * a.der_1 / sqrt(a.val);
    for(unsigned i=0;i<n;++i)
        for(unsigned j=0;j<n;++j)
            res.der_2(i,j) = 0.5 * a.der_2(i,j) / sqrt(a.val) - 0.25 * a.der_1[i]*a.der_1[j] / sqrt(a.val) / a.val;
    return res;
}


template<class T,int n> std::ostream &operator<<(std::ostream &os,const AutoDiff<T,n> &a) {
    os << "v = " << a.val << "\nder_1 =\n" << a.der_1 << "\nder_2 =\n" << a.der_2;
    return os;
}

}

#endif




