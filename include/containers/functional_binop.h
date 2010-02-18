/// \relates Lambda
struct Plus {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Plus,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Plus,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Plus,P1,P2>::T(p1 + p2); }
    template<class T> inline void init_reduction(T &p) const { p = (T)0; }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Plus, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator+(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Plus, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Plus(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Plus, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator+(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Plus, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Plus(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Plus,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator+(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Plus,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Plus(), f1, f2 );
}

/// \relates Lambda
struct Minus {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Minus,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Minus,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Minus,P1,P2>::T(p1 - p2); }
    template<class T> inline void init_reduction(T &p) const { p = (T)0; }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Minus, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator-(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Minus, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Minus(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Minus, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator-(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Minus, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Minus(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Minus,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator-(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Minus,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Minus(), f1, f2 );
}

/// \relates Lambda
struct Modulus {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Modulus,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Modulus,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Modulus,P1,P2>::T(p1 % p2); }
};
template<> struct ConserveZeroes<Modulus> { static const unsigned res = 1; };
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Modulus, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator%(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Modulus, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Modulus(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Modulus, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator%(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Modulus, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Modulus(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Modulus,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator%(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Modulus,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Modulus(), f1, f2 );
}

/// \relates Lambda
struct Multiplies {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Multiplies,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Multiplies,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Multiplies,P1,P2>::T(p1 * p2); }
    template<class T> inline void init_reduction(T &p) const { p = (T)1; }
};
template<> struct ConserveZeroes<Multiplies> { static const unsigned res = 1; };
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Multiplies, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator*(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Multiplies, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Multiplies(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Multiplies, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator*(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Multiplies, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Multiplies(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Multiplies,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator*(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Multiplies,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Multiplies(), f1, f2 );
}

/// \relates Lambda
struct Divides {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Divides,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Divides,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Divides,P1,P2>::T(p1 / p2); }
    template<class T> inline void init_reduction(T &p) const { p = (T)1; }
};
template<> struct ConserveZeroes<Divides> { static const unsigned res = 1; };
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Divides, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator/(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Divides, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Divides(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Divides, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator/(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Divides, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Divides(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Divides,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator/(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Divides,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Divides(), f1, f2 );
}

/// \relates Lambda
struct Equal {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Equal,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Equal,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Equal,P1,P2>::T(p1 == p2); }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Equal, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator==(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Equal, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Equal(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Equal, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator==(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Equal, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Equal(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Equal,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator==(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Equal,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Equal(), f1, f2 );
}

/// \relates Lambda
struct NotEqual {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<NotEqual,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<NotEqual,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<NotEqual,P1,P2>::T(p1 != p2); }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, NotEqual, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator!=(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, NotEqual, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( NotEqual(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, NotEqual, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator!=(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, NotEqual, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( NotEqual(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,NotEqual,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator!=(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,NotEqual,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( NotEqual(), f1, f2 );
}

/// \relates Lambda
struct Less {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Less,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Less,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Less,P1,P2>::T(p1 < p2); }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Less, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator<(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Less, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Less(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Less, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator<(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Less, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Less(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Less,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator<(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Less,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Less(), f1, f2 );
}

/// \relates Lambda
struct Greater {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Greater,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Greater,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Greater,P1,P2>::T(p1 > p2); }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Greater, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator>(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Greater, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Greater(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Greater, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator>(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Greater, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Greater(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Greater,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator>(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Greater,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Greater(), f1, f2 );
}

/// \relates Lambda
struct LessEq {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<LessEq,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<LessEq,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<LessEq,P1,P2>::T(p1 <= p2); }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, LessEq, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator<=(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, LessEq, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( LessEq(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, LessEq, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator<=(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, LessEq, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( LessEq(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,LessEq,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator<=(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,LessEq,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( LessEq(), f1, f2 );
}

/// \relates Lambda
struct GreaterEq {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<GreaterEq,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<GreaterEq,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<GreaterEq,P1,P2>::T(p1 >= p2); }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, GreaterEq, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator>=(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, GreaterEq, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( GreaterEq(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, GreaterEq, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator>=(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, GreaterEq, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( GreaterEq(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,GreaterEq,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator>=(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,GreaterEq,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( GreaterEq(), f1, f2 );
}

/// \relates Lambda
struct And {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<And,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<And,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<And,P1,P2>::T(p1 & p2); }
    template<class T> inline void init_reduction(T &p) const { p = (T)1; }
};
template<> struct ConserveZeroes<And> { static const unsigned res = 1; };
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, And, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator&(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, And, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( And(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, And, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator&(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, And, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( And(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,And,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator&(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,And,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( And(), f1, f2 );
}

/// \relates Lambda
struct Or {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Or,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Or,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Or,P1,P2>::T(p1 | p2); }
    template<class T> inline void init_reduction(T &p) const { p = (T)0; }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Or, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator|(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Or, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Or(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Or, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator|(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Or, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Or(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Or,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator|(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Or,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Or(), f1, f2 );
}

/// \relates Lambda
struct Xor {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Xor,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Xor,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Xor,P1,P2>::T(p1 ^ p2); }
    template<class T> inline void init_reduction(T &p) const { p = (T)0; }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Xor, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator^(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Xor, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Xor(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Xor, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator^(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Xor, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Xor(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Xor,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator^(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Xor,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Xor(), f1, f2 );
}

/// \relates Lambda
struct AndAnd {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<AndAnd,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<AndAnd,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<AndAnd,P1,P2>::T(p1 && p2); }
};
template<> struct ConserveZeroes<AndAnd> { static const unsigned res = 1; };
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, AndAnd, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator&&(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, AndAnd, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( AndAnd(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, AndAnd, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator&&(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, AndAnd, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( AndAnd(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,AndAnd,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator&&(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,AndAnd,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( AndAnd(), f1, f2 );
}

/// \relates Lambda
struct OrOr {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<OrOr,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<OrOr,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<OrOr,P1,P2>::T(p1 || p2); }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, OrOr, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operator||(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, OrOr, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( OrOr(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, OrOr, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operator||(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, OrOr, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( OrOr(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,OrOr,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operator||(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,OrOr,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( OrOr(), f1, f2 );
}

/// \relates Lambda
struct Min {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Min,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Min,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Min,P1,P2>::T(min(p1,p2)); }
    template<class T> inline void init_reduction(T &p) const { p = std::numeric_limits<T>::max(); }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Min, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operatormin(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Min, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Min(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Min, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operatormin(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Min, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Min(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Min,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operatormin(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Min,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Min(), f1, f2 );
}

/// \relates Lambda
struct Max {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Max,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Max,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Max,P1,P2>::T(max(p1,p2)); }
    template<class T> inline void init_reduction(T &p) const { p = -std::numeric_limits<T>::max(); }
};
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Max, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operatormax(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Max, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Max(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Max, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operatormax(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Max, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Max(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Max,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operatormax(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Max,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Max(), f1, f2 );
}

/// \relates Lambda
struct Pow {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef typename TypePromote<Pow,P1,P2>::T T; };
    template<class P1,class P2> typename TypePromote<Pow,P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return typename TypePromote<Pow,P1,P2>::T(pow(p1,p2)); }
    template<class T> inline void init_reduction(T &p) const { p = 1; }
};
template<> struct ConserveZeroes<Pow> { static const unsigned res = 1; };
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Pow, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> > operatorpow(const Function<O1,O2,O3,O4,O5> &f,const T &t) {
    return Function< ALGOBinary, Pow, Function<O1,O2,O3,O4,O5>, Function<ALGOCst,T> >( Pow(), f, Function<ALGOCst,T>(t) );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class T>
Function< ALGOBinary, Pow, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> > operatorpow(const T &t,const Function<O1,O2,O3,O4,O5> &f) {
    return Function< ALGOBinary, Pow, Function<ALGOCst,T>, Function<O1,O2,O3,O4,O5> >( Pow(), Function<ALGOCst,T>(t), f );
}
/// \relates Lambda
template<class O1,class O2,class O3,class O4,class O5,class P1,class P2,class P3,class P4,class P5>
Function<ALGOBinary,Pow,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> > operatorpow(const Function<O1,O2,O3,O4,O5> &f1,const Function<P1,P2,P3,P4,P5> &f2) {
    return Function<ALGOBinary,Pow,Function<O1,O2,O3,O4,O5>,Function<P1,P2,P3,P4,P5> >( Pow(), f1, f2 );
}

