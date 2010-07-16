namespace LMT {
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Plus,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator+( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Plus,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Plus, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator+( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Plus, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Plus, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator+( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Plus, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Minus,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator-( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Minus,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Minus, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator-( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Minus, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Minus, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator-( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Minus, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Modulus,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator%( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Modulus,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Modulus, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator%( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Modulus, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Modulus, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator%( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Modulus, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Multiplies,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator*( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Multiplies,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Multiplies, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator*( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Multiplies, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Multiplies, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator*( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Multiplies, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Divides,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator/( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Divides,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Divides, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator/( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Divides, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Divides, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator/( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Divides, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Equal,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator==( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Equal,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Equal, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator==( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Equal, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Equal, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator==( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Equal, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<NotEqual,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator!=( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<NotEqual,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< NotEqual, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator!=( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< NotEqual, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< NotEqual, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator!=( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< NotEqual, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Less,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator<( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Less,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Less, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator<( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Less, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Less, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator<( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Less, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Greater,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator>( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Greater,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Greater, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator>( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Greater, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Greater, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator>( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Greater, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<LessEq,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator<=( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<LessEq,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< LessEq, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator<=( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< LessEq, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< LessEq, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator<=( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< LessEq, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<GreaterEq,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator>=( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<GreaterEq,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< GreaterEq, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator>=( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< GreaterEq, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< GreaterEq, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator>=( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< GreaterEq, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<And,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator&( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<And,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< And, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator&( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< And, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< And, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator&( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< And, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Or,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator|( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Or,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Or, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator|( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Or, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Or, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator|( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Or, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Xor,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator^( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Xor,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Xor, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator^( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Xor, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Xor, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator^( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Xor, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<AndAnd,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator&&( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<AndAnd,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< AndAnd, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator&&( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< AndAnd, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< AndAnd, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator&&( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< AndAnd, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<OrOr,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> operator||( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<OrOr,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< OrOr, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> operator||( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< OrOr, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< OrOr, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> operator||( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< OrOr, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Min,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> min( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Min,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Min, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> min( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Min, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Min, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> min( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Min, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Max,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> max( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Max,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Max, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> max( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Max, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Max, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> max( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Max, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}


/*! \relates Vec */
template<class T1,int s1,class TO1,class T2,int s2,class TO2>
Vec<VecOp<Pow,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)> pow( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {
    VECASSERTSAMESIZE(v1,v2); return Vec<VecOp<Pow,2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>(v1,v2);
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Pow, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1> pow( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {
    return Vec<VecOp< Pow, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));
}
/*! \relates Vec */
template<class T1,int s1,class TO1,class T2>
Vec<VecOp< Pow, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1> pow( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {
    return Vec<VecOp< Pow, 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);
}



/*! 
    version pour puissance entière
    \relates Vec
*/
template<class T1,int s1,class TO1>
Vec<VecOp< Pow, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<int>,s1>,false>,s1> pow( const Vec<T1,s1,TO1> &v1, int v2 ) {
    return Vec<VecOp< Pow, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<int>,s1>,false>,s1>(v1, Vec<VecCst<int>,s1>(v2,v1.size()));
}

};
