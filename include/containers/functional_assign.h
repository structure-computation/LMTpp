/// \keyword Lambda
struct PlusEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 += p2; } };

/// \keyword Lambda
template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, PlusEqu >
operator+=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, PlusEqu >( a, f ); }
/// \keyword Lambda
template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,PlusEqu> operator+=(Function<C_1> &f,const T &val) {
    return Function<ALGOAssign1,Function<ALGOCst,T>,PlusEqu>( Function<ALGOCst,T>(val) );
}
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,PlusEqu>
operator+=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {
    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,PlusEqu>( val );
}

/// \keyword Lambda
struct MinusEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 -= p2; } };

/// \keyword Lambda
template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, MinusEqu >
operator-=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, MinusEqu >( a, f ); }
/// \keyword Lambda
template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,MinusEqu> operator-=(Function<C_1> &f,const T &val) {
    return Function<ALGOAssign1,Function<ALGOCst,T>,MinusEqu>( Function<ALGOCst,T>(val) );
}
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,MinusEqu>
operator-=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {
    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,MinusEqu>( val );
}

/// \keyword Lambda
struct ModulusEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 %= p2; } };

/// \keyword Lambda
template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, ModulusEqu >
operator%=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, ModulusEqu >( a, f ); }
/// \keyword Lambda
template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,ModulusEqu> operator%=(Function<C_1> &f,const T &val) {
    return Function<ALGOAssign1,Function<ALGOCst,T>,ModulusEqu>( Function<ALGOCst,T>(val) );
}
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,ModulusEqu>
operator%=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {
    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,ModulusEqu>( val );
}

/// \keyword Lambda
struct MultipliesEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 *= p2; } };

/// \keyword Lambda
template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, MultipliesEqu >
operator*=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, MultipliesEqu >( a, f ); }
/// \keyword Lambda
template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,MultipliesEqu> operator*=(Function<C_1> &f,const T &val) {
    return Function<ALGOAssign1,Function<ALGOCst,T>,MultipliesEqu>( Function<ALGOCst,T>(val) );
}
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,MultipliesEqu>
operator*=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {
    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,MultipliesEqu>( val );
}

/// \keyword Lambda
struct DividesEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 /= p2; } };

/// \keyword Lambda
template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, DividesEqu >
operator/=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, DividesEqu >( a, f ); }
/// \keyword Lambda
template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,DividesEqu> operator/=(Function<C_1> &f,const T &val) {
    return Function<ALGOAssign1,Function<ALGOCst,T>,DividesEqu>( Function<ALGOCst,T>(val) );
}
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,DividesEqu>
operator/=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {
    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,DividesEqu>( val );
}

/// \keyword Lambda
struct AndEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 &= p2; } };

/// \keyword Lambda
template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, AndEqu >
operator&=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, AndEqu >( a, f ); }
/// \keyword Lambda
template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,AndEqu> operator&=(Function<C_1> &f,const T &val) {
    return Function<ALGOAssign1,Function<ALGOCst,T>,AndEqu>( Function<ALGOCst,T>(val) );
}
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,AndEqu>
operator&=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {
    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,AndEqu>( val );
}

/// \keyword Lambda
struct OrEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 |= p2; } };

/// \keyword Lambda
template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, OrEqu >
operator|=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, OrEqu >( a, f ); }
/// \keyword Lambda
template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,OrEqu> operator|=(Function<C_1> &f,const T &val) {
    return Function<ALGOAssign1,Function<ALGOCst,T>,OrEqu>( Function<ALGOCst,T>(val) );
}
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,OrEqu>
operator|=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {
    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,OrEqu>( val );
}

/// \keyword Lambda
struct XorEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 ^= p2; } };

/// \keyword Lambda
template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, XorEqu >
operator^=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, XorEqu >( a, f ); }
/// \keyword Lambda
template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,XorEqu> operator^=(Function<C_1> &f,const T &val) {
    return Function<ALGOAssign1,Function<ALGOCst,T>,XorEqu>( Function<ALGOCst,T>(val) );
}
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,XorEqu>
operator^=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {
    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,XorEqu>( val );
}

/// \keyword Lambda
struct ShiftLeftEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 <<= p2; } };

/// \keyword Lambda
template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, ShiftLeftEqu >
operator<<=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, ShiftLeftEqu >( a, f ); }
/// \keyword Lambda
template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,ShiftLeftEqu> operator<<=(Function<C_1> &f,const T &val) {
    return Function<ALGOAssign1,Function<ALGOCst,T>,ShiftLeftEqu>( Function<ALGOCst,T>(val) );
}
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,ShiftLeftEqu>
operator<<=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {
    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,ShiftLeftEqu>( val );
}

/// \keyword Lambda
struct ShiftRightEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 >>= p2; } };

/// \keyword Lambda
template<class T,class O1,class O2,class O3,class O4,class O5> Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, ShiftRightEqu >
operator>>=(T &a,const Function<O1,O2,O3,O4,O5> &f) { return Function< ALGOAssignExt, Function<O1,O2,O3,O4,O5>, T, ShiftRightEqu >( a, f ); }
/// \keyword Lambda
template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,ShiftRightEqu> operator>>=(Function<C_1> &f,const T &val) {
    return Function<ALGOAssign1,Function<ALGOCst,T>,ShiftRightEqu>( Function<ALGOCst,T>(val) );
}
/// \keyword Lambda
template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,ShiftRightEqu>
operator>>=(Function<C_1> &f,const Function<O1,O2,O3,O4,O5> &val) {
    return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,ShiftRightEqu>( val );
}

