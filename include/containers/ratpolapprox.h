#ifndef RATPOLAPPROX_H
#define RATPOLAPPROX_H

#include <iostream>
#include "containers/polapprox.h"

namespace LMT {

template<unsigned p_order_,unsigned q_order_,class T=double>
struct RatPolApprox {
    static const unsigned p_order = p_order_;
    static const unsigned q_order = q_order_;
    
    RatPolApprox( const T &v = 0.0 ) {
        P = v;
        Q = T(1.0);
    }
    T operator[](const T &x) const {
        return P[x] / Q[x];
    }
    template<class TO,int static_size,class IVO> Vec<T> operator()(const Vec<TO,static_size,IVO> &x) const {
        Vec<T> res;
        for(unsigned i=0;i<x.size();++i)
            res.push_back( operator[](x[i]) );
        return res;
    }
    
    RatPolApprox<p_order,q_order,T> &operator+=(const RatPolApprox<p_order,q_order,T> &p) { *this = *this + p; return *this; }
    RatPolApprox<p_order,q_order,T> &operator-=(const RatPolApprox<p_order,q_order,T> &p) { *this = *this - p; return *this; }
    RatPolApprox<p_order,q_order,T> &operator*=(const RatPolApprox<p_order,q_order,T> &p) { *this = *this * p; return *this; }
    RatPolApprox<p_order,q_order,T> &operator/=(const RatPolApprox<p_order,q_order,T> &p) { *this = *this / p; return *this; }
    
    RatPolApprox &reduced() {
//         while ( LMT::abs(P.val[0]) < LMT::abs(P.get_max_coeff()) * 1e-9 and LMT::abs(Q.val[0]) < LMT::abs(Q.get_max_coeff()) * 1e-9 ) {
//             P.shift_coeffs();
//             Q.shift_coeffs();
//         }
        T c = Q.val[0];
        for(unsigned i=0;i<p_order;++i) P.val[i] /= c;
        for(unsigned i=0;i<q_order;++i) Q.val[i] /= c;
        return *this;
    }
    
    PolApprox<p_order,T> P;
    PolApprox<q_order,T> Q;
};

template<unsigned p_order,unsigned q_order,class T>
std::ostream &operator<<(std::ostream &os,const RatPolApprox<p_order,q_order,T> &p) {
    os << p.P << "/(" << p.Q << ")";
    return os;
}

template<unsigned p_order,unsigned q_order,class T>
RatPolApprox<p_order,q_order,T> operator+(const RatPolApprox<p_order,q_order,T> &p1,const RatPolApprox<p_order,q_order,T> &p2) {
    RatPolApprox<p_order,q_order,T> res;
    res.P = p1.P * p2.Q + p2.P * p1.Q;
    res.Q = p1.Q * p2.Q;
    return res.reduced();
}

template<unsigned p_order,unsigned q_order,class T>
RatPolApprox<p_order,q_order,T> operator-(const RatPolApprox<p_order,q_order,T> &p1,const RatPolApprox<p_order,q_order,T> &p2) {
    RatPolApprox<p_order,q_order,T> res;
    res.P = p1.P * p2.Q - p2.P * p1.Q;
    res.Q = p1.Q * p2.Q;
    return res.reduced();
}

template<unsigned p_order,unsigned q_order,class T>
RatPolApprox<p_order,q_order,T> operator*(const RatPolApprox<p_order,q_order,T> &p1,const RatPolApprox<p_order,q_order,T> &p2) {
    RatPolApprox<p_order,q_order,T> res;
    res.P = p1.P * p2.P;
    res.Q = p1.Q * p2.Q;
    return res.reduced();
}

template<unsigned p_order,unsigned q_order,class T>
RatPolApprox<p_order,q_order,T> operator/(const RatPolApprox<p_order,q_order,T> &p1,const RatPolApprox<p_order,q_order,T> &p2) {
    RatPolApprox<p_order,q_order,T> res;
    res.P = p1.P * p2.Q;
    res.Q = p1.Q * p2.P;
    return res.reduced();
}

template<unsigned p_order,unsigned q_order,class T>
inline T abs_indication(const RatPolApprox<p_order,q_order,T> &p) { return LMT::abs( p[0] ); } // if val is a function, return abs( something_close_to_mean(val) )

template<unsigned p_order,unsigned q_order,class T>
inline T abs_indication(const RatPolApprox<p_order,q_order,std::complex<T> > &p) { return LMT::abs( p[0] ); } // if val is a function, return abs( something_close_to_mean(val) )


}

#endif // RATPOLAPPROX_H
