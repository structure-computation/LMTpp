#ifndef POLAPPROX_H
#define POLAPPROX_H

#include <iostream>
#include "containers/vec.h"

namespace LMT {

template<unsigned order,class T=double>
struct PolApprox {
    PolApprox( const T &v = 0.0 ) {
        val[0] = v;
        for(unsigned i=1;i<order;++i)
            val[i] = T(0.0);
    }
    T operator[](const T &x) const {
        T res = val[0];
        T m = x;
        for( unsigned i=1; i<order; ++i, m *= x )
            res += val[i] * m;
        return res;
    }
    template<class TO,int static_size,class IVO> Vec<T> operator()(const Vec<TO,static_size,IVO> &x) const {
        Vec<T> res;
        for(unsigned i=0;i<x.size();++i)
            res.push_back( operator[](x[i]) );
        return res;
    }
    
    T get_max_coeff() {
        T res = val[0];
        for(unsigned i=1;i<order;++i)
            if ( LMT::abs( val[i] ) > LMT::abs( res ) )
                res = val[i];
        return res;
    }
    
    void shift_coeffs() {
        for(unsigned i=0;i<order-1;++i)
            val[i] = val[i+1];
        val[order-1] = T(0);
    }
    
    PolApprox &operator+=(const PolApprox &p) { *this = *this + p; return *this; }
    PolApprox &operator-=(const PolApprox &p) { *this = *this - p; return *this; }
    PolApprox &operator*=(const PolApprox &p) { *this = *this * p; return *this; }
    PolApprox &operator/=(const PolApprox &p) { *this = *this / p; return *this; }
    
    T val[ order ];
};

template<unsigned order,class T>
std::ostream &operator<<(std::ostream &os,const PolApprox<order,T> &p) {
    os << p.val[0];
    if ( order >= 1 )
        os << "+" << p.val[1] << "*x";
    for(unsigned i=2;i<order;++i)
        os << "+" << p.val[i] << "*x^" << i;
    return os;
}

template<unsigned order,class T>
PolApprox<order,T> operator+(const PolApprox<order,T> &p1,const PolApprox<order,T> &p2) {
    PolApprox<order,T> res;
    for(unsigned i=0;i<order;++i) res.val[i] = p1.val[i] + p2.val[i];
    return res;
}

template<unsigned order,class T>
PolApprox<order,T> operator-(const PolApprox<order,T> &p1,const PolApprox<order,T> &p2) {
    PolApprox<order,T> res;
    for(unsigned i=0;i<order;++i) res.val[i] = p1.val[i] - p2.val[i];
    return res;
}

template<unsigned order,class T>
PolApprox<order,T> operator*(const PolApprox<order,T> &p1,const PolApprox<order,T> &p2) {
    PolApprox<order,T> res;
    for(unsigned i=0;i<order;++i)
        for(unsigned j=0;j<=i;++j)
            res.val[i] += p1.val[j] * p2.val[i-j];
    return res;
}

template<unsigned order,class T>
PolApprox<order,T> operator/(const PolApprox<order,T> &p1,const PolApprox<order,T> &p2) {
    PolApprox<order,T> res;
    for(unsigned i=0;i<order;++i) {
        res.val[i] = p1.val[i];
        for(unsigned j=0;j<i;++j)
            res.val[i] -= res.val[j] * p2.val[i-j];
        res.val[i] /= p2.val[0];
    }
    return res;
}

template<unsigned p_order,class T>
inline T abs_indication(const PolApprox<p_order,T> &p) { return LMT::abs( p[0] ); } // if val is a function, return abs( something_close_to_mean(val) )

template<unsigned p_order,class T>
inline T abs_indication(const PolApprox<p_order,std::complex<T> > &p) { return LMT::abs( p[0] ); } // if val is a function, return abs( something_close_to_mean(val) )


}

#endif //POLAPPROX_H
