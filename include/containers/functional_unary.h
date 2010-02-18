/// \keyword Lambda
struct Conj {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef P1 T; };
    template<class P1> P1 operator()(const P1 &p1) const {using LMT::conj;return conj(p1); }
};
template<> struct ConserveZeroes<Conj> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Conj,Function<O1,O2,O3,O4,O5>,void,void> conj(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Conj,Function<O1,O2,O3,O4,O5>,void,void>( Conj(), f );
}

/// \keyword Lambda
struct Abs {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename SubComplex<P1>::T T; };
    template<class P1> typename SubComplex<P1>::T operator()(const P1 &p1) const {using LMT::abs;return abs(p1); }
};
template<> struct ConserveZeroes<Abs> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Abs,Function<O1,O2,O3,O4,O5>,void,void> abs(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Abs,Function<O1,O2,O3,O4,O5>,void,void>( Abs(), f );
}

/// \keyword Lambda
struct Acos {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::acos;return acos(p1); }
};
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Acos,Function<O1,O2,O3,O4,O5>,void,void> acos(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Acos,Function<O1,O2,O3,O4,O5>,void,void>( Acos(), f );
}

/// \keyword Lambda
struct Asin {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::asin;return asin(p1); }
};
template<> struct ConserveZeroes<Asin> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Asin,Function<O1,O2,O3,O4,O5>,void,void> asin(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Asin,Function<O1,O2,O3,O4,O5>,void,void>( Asin(), f );
}

/// \keyword Lambda
struct Atan {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::atan;return atan(p1); }
};
template<> struct ConserveZeroes<Atan> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Atan,Function<O1,O2,O3,O4,O5>,void,void> atan(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Atan,Function<O1,O2,O3,O4,O5>,void,void>( Atan(), f );
}

/// \keyword Lambda
struct Cos {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::cos;return cos(p1); }
};
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Cos,Function<O1,O2,O3,O4,O5>,void,void> cos(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Cos,Function<O1,O2,O3,O4,O5>,void,void>( Cos(), f );
}

/// \keyword Lambda
struct Cosh {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::cosh;return cosh(p1); }
};
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Cosh,Function<O1,O2,O3,O4,O5>,void,void> cosh(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Cosh,Function<O1,O2,O3,O4,O5>,void,void>( Cosh(), f );
}

/// \keyword Lambda
struct Exp {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::exp;return exp(p1); }
};
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Exp,Function<O1,O2,O3,O4,O5>,void,void> exp(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Exp,Function<O1,O2,O3,O4,O5>,void,void>( Exp(), f );
}

/// \keyword Lambda
struct Log {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::log;return log(p1); }
};
template<> struct ConserveZeroes<Log> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Log,Function<O1,O2,O3,O4,O5>,void,void> log(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Log,Function<O1,O2,O3,O4,O5>,void,void>( Log(), f );
}

/// \keyword Lambda
struct Log10 {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::log10;return log10(p1); }
};
template<> struct ConserveZeroes<Log10> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Log10,Function<O1,O2,O3,O4,O5>,void,void> log10(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Log10,Function<O1,O2,O3,O4,O5>,void,void>( Log10(), f );
}

/// \keyword Lambda
struct Sin {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::sin;return sin(p1); }
};
template<> struct ConserveZeroes<Sin> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Sin,Function<O1,O2,O3,O4,O5>,void,void> sin(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Sin,Function<O1,O2,O3,O4,O5>,void,void>( Sin(), f );
}

/// \keyword Lambda
struct Sinh {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::sinh;return sinh(p1); }
};
template<> struct ConserveZeroes<Sinh> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Sinh,Function<O1,O2,O3,O4,O5>,void,void> sinh(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Sinh,Function<O1,O2,O3,O4,O5>,void,void>( Sinh(), f );
}

/// \keyword Lambda
struct Sqrt {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::sqrt;return sqrt(p1); }
};
template<> struct ConserveZeroes<Sqrt> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Sqrt,Function<O1,O2,O3,O4,O5>,void,void> sqrt(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Sqrt,Function<O1,O2,O3,O4,O5>,void,void>( Sqrt(), f );
}

/// \keyword Lambda
struct Tan {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::tan;return tan(p1); }
};
template<> struct ConserveZeroes<Tan> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Tan,Function<O1,O2,O3,O4,O5>,void,void> tan(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Tan,Function<O1,O2,O3,O4,O5>,void,void>( Tan(), f );
}

/// \keyword Lambda
struct Tanh {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename FloatType<P1>::T T; };
    template<class P1> typename FloatType<P1>::T operator()(const P1 &p1) const {using LMT::tanh;return tanh(p1); }
};
template<> struct ConserveZeroes<Tanh> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Tanh,Function<O1,O2,O3,O4,O5>,void,void> tanh(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Tanh,Function<O1,O2,O3,O4,O5>,void,void>( Tanh(), f );
}

/// \keyword Lambda
struct Real {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename SubComplex<P1>::T T; };
    template<class P1> typename SubComplex<P1>::T operator()(const P1 &p1) const {using LMT::real;return real(p1); }
};
template<> struct ConserveZeroes<Real> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Real,Function<O1,O2,O3,O4,O5>,void,void> real(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Real,Function<O1,O2,O3,O4,O5>,void,void>( Real(), f );
}

/// \keyword Lambda
struct Imag {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename SubComplex<P1>::T T; };
    template<class P1> typename SubComplex<P1>::T operator()(const P1 &p1) const {using LMT::imag;return imag(p1); }
};
template<> struct ConserveZeroes<Imag> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Imag,Function<O1,O2,O3,O4,O5>,void,void> imag(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Imag,Function<O1,O2,O3,O4,O5>,void,void>( Imag(), f );
}

/// \keyword Lambda
struct Arg {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename SubComplex<P1>::T T; };
    template<class P1> typename SubComplex<P1>::T operator()(const P1 &p1) const {using LMT::arg;return arg(p1); }
};
template<> struct ConserveZeroes<Arg> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Arg,Function<O1,O2,O3,O4,O5>,void,void> arg(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Arg,Function<O1,O2,O3,O4,O5>,void,void>( Arg(), f );
}

/// \keyword Lambda
struct Negate {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef P1 T; };
    template<class P1> P1 operator()(const P1 &p1) const {return -(p1); }
};
template<> struct ConserveZeroes<Negate> { static const unsigned res = true; };
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5>
Function<ALGOCompose1,Negate,Function<O1,O2,O3,O4,O5>,void,void> operator-(const Function<O1,O2,O3,O4,O5> &f) {
    return Function<ALGOCompose1,Negate,Function<O1,O2,O3,O4,O5>,void,void>( Negate(), f );
}

