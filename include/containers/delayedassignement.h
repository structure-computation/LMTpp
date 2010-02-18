// file generated from delayedassignement.h.py. do not modify
#ifndef LMT_delayedassignement_HEADER
#define LMT_delayedassignement_HEADER


namespace LMT {

template<class Source>
class DelayedAssignement {
public:
    DelayedAssignement(const Source &s=Source()):source(s) {}
    template<class T> operator T() const { return source.get(); }
    template<class T> DelayedAssignement &operator=(const T &val) { source.apply(Function<C_2>(),val); return *this; }
    template<class T> DelayedAssignement &operator+=(const T &val) { source.apply(Plus(),val); return *this; }
    template<class T> DelayedAssignement &operator-=(const T &val) { source.apply(Minus(),val); return *this; }
    template<class T> DelayedAssignement &operator%=(const T &val) { source.apply(Modulus(),val); return *this; }
    template<class T> DelayedAssignement &operator*=(const T &val) { source.apply(Multiplies(),val); return *this; }
    template<class T> DelayedAssignement &operator/=(const T &val) { source.apply(Divides(),val); return *this; }
    template<class T> DelayedAssignement &operator&=(const T &val) { source.apply(And(),val); return *this; }
    template<class T> DelayedAssignement &operator|=(const T &val) { source.apply(Or(),val); return *this; }
    template<class T> DelayedAssignement &operator^=(const T &val) { source.apply(Xor(),val); return *this; }
    Source source;
};

/**
    elates Mat
*/
template<class Source>
std::ostream &operator<<(std::ostream &os,const DelayedAssignement<Source> &da) {
    os << (typename Source::T)da;
    return os;
}

template<class Source> struct TypeInformation<DelayedAssignement<Source> > {
    typedef typename Source::T TS;
    static const int res = TypeInformation<TS>::res;
    static const int englobing = TypeInformation<TS>::englobing;
    static std::string type() { return TypeInformation<TS>::type(); }
    static const bool float_type = TypeInformation<TS>::float_type;
    template<class TV> struct DeepVariant { typedef typename TypeInformation<TS>::template DeepVariant<TV>::T T; };
};

template<class Source> typename Source::T conj(const DelayedAssignement<Source> &da) { return LMT::conj( da.source.get() ); }
template<class Source> typename Source::T abs(const DelayedAssignement<Source> &da) { return LMT::abs( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T acos(const DelayedAssignement<Source> &da) { return LMT::acos( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T asin(const DelayedAssignement<Source> &da) { return LMT::asin( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T atan(const DelayedAssignement<Source> &da) { return LMT::atan( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T cos(const DelayedAssignement<Source> &da) { return LMT::cos( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T cosh(const DelayedAssignement<Source> &da) { return LMT::cosh( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T exp(const DelayedAssignement<Source> &da) { return LMT::exp( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T log(const DelayedAssignement<Source> &da) { return LMT::log( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T log10(const DelayedAssignement<Source> &da) { return LMT::log10( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T sin(const DelayedAssignement<Source> &da) { return LMT::sin( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T sinh(const DelayedAssignement<Source> &da) { return LMT::sinh( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T sqrt(const DelayedAssignement<Source> &da) { return LMT::sqrt( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T tan(const DelayedAssignement<Source> &da) { return LMT::tan( da.source.get() ); }
template<class Source> typename FloatType<typename Source::T>::T tanh(const DelayedAssignement<Source> &da) { return LMT::tanh( da.source.get() ); }
template<class Source> typename SubComplex<typename Source::T>::T real(const DelayedAssignement<Source> &da) { return LMT::real( da.source.get() ); }
template<class Source> typename SubComplex<typename Source::T>::T imag(const DelayedAssignement<Source> &da) { return LMT::imag( da.source.get() ); }
template<class Source> typename Source::T operator-(const DelayedAssignement<Source> &da) { return -( da.source.get() ); }
template<class Source,class T> typename TypePromote<Plus,typename Source::T,T>::T operator+(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() + b; }
template<class T,class Source> typename TypePromote<Plus,T,typename Source::T>::T operator+(const T &a,const DelayedAssignement<Source> &b) { return a + b.source.get(); }
template<class S1,class S2> typename TypePromote<Plus,typename S1::T,typename S2::T>::T operator+(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() + b.source.get(); }

template<class Source,class T> typename TypePromote<Minus,typename Source::T,T>::T operator-(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() - b; }
template<class T,class Source> typename TypePromote<Minus,T,typename Source::T>::T operator-(const T &a,const DelayedAssignement<Source> &b) { return a - b.source.get(); }
template<class S1,class S2> typename TypePromote<Minus,typename S1::T,typename S2::T>::T operator-(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() - b.source.get(); }

template<class Source,class T> typename TypePromote<Modulus,typename Source::T,T>::T operator%(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() % b; }
template<class T,class Source> typename TypePromote<Modulus,T,typename Source::T>::T operator%(const T &a,const DelayedAssignement<Source> &b) { return a % b.source.get(); }
template<class S1,class S2> typename TypePromote<Modulus,typename S1::T,typename S2::T>::T operator%(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() % b.source.get(); }

template<class Source,class T> typename TypePromote<Multiplies,typename Source::T,T>::T operator*(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() * b; }
template<class T,class Source> typename TypePromote<Multiplies,T,typename Source::T>::T operator*(const T &a,const DelayedAssignement<Source> &b) { return a * b.source.get(); }
template<class S1,class S2> typename TypePromote<Multiplies,typename S1::T,typename S2::T>::T operator*(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() * b.source.get(); }

template<class Source,class T> typename TypePromote<Divides,typename Source::T,T>::T operator/(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() / b; }
template<class T,class Source> typename TypePromote<Divides,T,typename Source::T>::T operator/(const T &a,const DelayedAssignement<Source> &b) { return a / b.source.get(); }
template<class S1,class S2> typename TypePromote<Divides,typename S1::T,typename S2::T>::T operator/(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() / b.source.get(); }

template<class Source,class T> typename TypePromote<Equal,typename Source::T,T>::T operator==(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() == b; }
template<class T,class Source> typename TypePromote<Equal,T,typename Source::T>::T operator==(const T &a,const DelayedAssignement<Source> &b) { return a == b.source.get(); }
template<class S1,class S2> typename TypePromote<Equal,typename S1::T,typename S2::T>::T operator==(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() == b.source.get(); }

template<class Source,class T> typename TypePromote<NotEqual,typename Source::T,T>::T operator!=(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() != b; }
template<class T,class Source> typename TypePromote<NotEqual,T,typename Source::T>::T operator!=(const T &a,const DelayedAssignement<Source> &b) { return a != b.source.get(); }
template<class S1,class S2> typename TypePromote<NotEqual,typename S1::T,typename S2::T>::T operator!=(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() != b.source.get(); }

template<class Source,class T> typename TypePromote<Less,typename Source::T,T>::T operator<(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() < b; }
template<class T,class Source> typename TypePromote<Less,T,typename Source::T>::T operator<(const T &a,const DelayedAssignement<Source> &b) { return a < b.source.get(); }
template<class S1,class S2> typename TypePromote<Less,typename S1::T,typename S2::T>::T operator<(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() < b.source.get(); }

template<class Source,class T> typename TypePromote<Greater,typename Source::T,T>::T operator>(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() > b; }
template<class T,class Source> typename TypePromote<Greater,T,typename Source::T>::T operator>(const T &a,const DelayedAssignement<Source> &b) { return a > b.source.get(); }
template<class S1,class S2> typename TypePromote<Greater,typename S1::T,typename S2::T>::T operator>(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() > b.source.get(); }

template<class Source,class T> typename TypePromote<LessEq,typename Source::T,T>::T operator<=(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() <= b; }
template<class T,class Source> typename TypePromote<LessEq,T,typename Source::T>::T operator<=(const T &a,const DelayedAssignement<Source> &b) { return a <= b.source.get(); }
template<class S1,class S2> typename TypePromote<LessEq,typename S1::T,typename S2::T>::T operator<=(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() <= b.source.get(); }

template<class Source,class T> typename TypePromote<GreaterEq,typename Source::T,T>::T operator>=(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() >= b; }
template<class T,class Source> typename TypePromote<GreaterEq,T,typename Source::T>::T operator>=(const T &a,const DelayedAssignement<Source> &b) { return a >= b.source.get(); }
template<class S1,class S2> typename TypePromote<GreaterEq,typename S1::T,typename S2::T>::T operator>=(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() >= b.source.get(); }

template<class Source,class T> typename TypePromote<And,typename Source::T,T>::T operator&(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() & b; }
template<class T,class Source> typename TypePromote<And,T,typename Source::T>::T operator&(const T &a,const DelayedAssignement<Source> &b) { return a & b.source.get(); }
template<class S1,class S2> typename TypePromote<And,typename S1::T,typename S2::T>::T operator&(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() & b.source.get(); }

template<class Source,class T> typename TypePromote<Or,typename Source::T,T>::T operator|(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() | b; }
template<class T,class Source> typename TypePromote<Or,T,typename Source::T>::T operator|(const T &a,const DelayedAssignement<Source> &b) { return a | b.source.get(); }
template<class S1,class S2> typename TypePromote<Or,typename S1::T,typename S2::T>::T operator|(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() | b.source.get(); }

template<class Source,class T> typename TypePromote<Xor,typename Source::T,T>::T operator^(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() ^ b; }
template<class T,class Source> typename TypePromote<Xor,T,typename Source::T>::T operator^(const T &a,const DelayedAssignement<Source> &b) { return a ^ b.source.get(); }
template<class S1,class S2> typename TypePromote<Xor,typename S1::T,typename S2::T>::T operator^(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() ^ b.source.get(); }

template<class Source,class T> typename TypePromote<AndAnd,typename Source::T,T>::T operator&&(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() && b; }
template<class T,class Source> typename TypePromote<AndAnd,T,typename Source::T>::T operator&&(const T &a,const DelayedAssignement<Source> &b) { return a && b.source.get(); }
template<class S1,class S2> typename TypePromote<AndAnd,typename S1::T,typename S2::T>::T operator&&(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() && b.source.get(); }

template<class Source,class T> typename TypePromote<OrOr,typename Source::T,T>::T operator||(const DelayedAssignement<Source> &a,const T &b) { return a.source.get() || b; }
template<class T,class Source> typename TypePromote<OrOr,T,typename Source::T>::T operator||(const T &a,const DelayedAssignement<Source> &b) { return a || b.source.get(); }
template<class S1,class S2> typename TypePromote<OrOr,typename S1::T,typename S2::T>::T operator||(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return a.source.get() || b.source.get(); }

template<class Source,class T> typename TypePromote<Min,typename Source::T,T>::T min(const DelayedAssignement<Source> &a,const T &b) { return min(a.source.get(),b); }
template<class T,class Source> typename TypePromote<Min,T,typename Source::T>::T min(const T &a,const DelayedAssignement<Source> &b) { return min(a,b.source.get()); }
template<class S1,class S2> typename TypePromote<Min,typename S1::T,typename S2::T>::T min(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return min(a.source.get(),b.source.get()); }

template<class Source,class T> typename TypePromote<Max,typename Source::T,T>::T max(const DelayedAssignement<Source> &a,const T &b) { return max(a.source.get(),b); }
template<class T,class Source> typename TypePromote<Max,T,typename Source::T>::T max(const T &a,const DelayedAssignement<Source> &b) { return max(a,b.source.get()); }
template<class S1,class S2> typename TypePromote<Max,typename S1::T,typename S2::T>::T max(const DelayedAssignement<S1> &a,const DelayedAssignement<S2> &b) { return max(a.source.get(),b.source.get()); }


};

#endif // LMT_delayedassignement_HEADER

