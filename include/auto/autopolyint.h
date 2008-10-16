#ifndef AUTODIFF_H
#define AUTODIFF_H

#include <containers/mat.h>

namespace LMT {
/**
    \defgroup Toto

    Description du groupe Toto...
 */

/**
    \ingroup Toto
    AutoPolyInt
 */
template<class T,int num_unk=-1> struct AutoPolyInt {
    AutoPolyInt(T v=T(0)) {
        val = v;
        if ( num_unk >= 0 ) {
            der_1 = T(0);
            der_2.set( T(0) );
        }
    }
    T val;
    Vec<T,num_unk> der_1;
    Mat<T,Gen<num_unk,num_unk> > der_2;
};

template<class TT,int n> struct TypeInformation<AutoPolyInt<TT,n> > {
    static const int res = TypeInformation<TT>::res;
    static const int englobing = 1 + TypeInformation<TT>::englobing;
    typedef TT SubType;
    template<class TV> struct Variant { typedef AutoPolyInt<TV,n> T; };
    template<class TV> struct DeepVariant { typedef AutoPolyInt<typename TypeInformation<TT>::template DeepVariant<TV>::T,n> T; };
    static std::string type() { return "AutoPolyInt<"+TypeInformation<TT>::type()+"> "; }
    static const bool float_type = TypeInformation<TT>::float_type;
};
template<class TT,int n> struct HasTypeInformation<AutoPolyInt<TT,n> > { static const bool res = true; };


template<class T,int n> AutoPolyInt<T,n> operator-(const AutoPolyInt<T,n> &a,const AutoPolyInt<T,n> &b) {
    AutoPolyInt<T,n> res;
    res.val = a.val - b.val;
    res.der_1 = a.der_1 - b.der_1;
    res.der_2 = a.der_2 - b.der_2;
    return res;
}

template<class T,int n> AutoPolyInt<T,n> operator+(const AutoPolyInt<T,n> &a,const AutoPolyInt<T,n> &b) {
    AutoPolyInt<T,n> res;
    res.val = a.val + b.val;
    res.der_1 = a.der_1 + b.der_1;
    res.der_2 = a.der_2 + b.der_2;
    return res;
}

template<class T,int n> AutoPolyInt<T,n> operator*(const AutoPolyInt<T,n> &a,const AutoPolyInt<T,n> &b) {
    AutoPolyInt<T,n> res;
    res.val = a.val * b.val;
    res.der_1 = a.val * b.der_1 + a.der_1 * b.val;
    for(unsigned i=0;i<n;++i)
        for(unsigned j=0;j<n;++j)
            res.der_2(i,j) = a.der_2(i,j)*b.val + a.der_1[i]*b.der_1[j] + a.der_1[j]*b.der_1[i] + a.val*b.der_2(i,j);
    return res;
}

template<class T,int n> AutoPolyInt<T,n> sqrt(const AutoPolyInt<T,n> &a) {
    AutoPolyInt<T,n> res;
    res.val = sqrt(a.val);
    res.der_1 = 0.5 * a.der_1 / sqrt(a.val);
    for(unsigned i=0;i<n;++i)
        for(unsigned j=0;j<n;++j)
            res.der_2(i,j) = 0.5 * a.der_2(i,j) / sqrt(a.val) - 0.25 * a.der_1[i]*a.der_1[j] / sqrt(a.val) / a.val;
    return res;
}


template<class T,int n> std::ostream &operator<<(std::ostream &os,const AutoPolyInt<T,n> &a) {
    os << "v = " << a.val << "\nder_1 =\n" << a.der_1 << "\nder_2 =\n" << a.der_2;
    return os;
}

}

#endif
