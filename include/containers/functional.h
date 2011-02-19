//
// C++ Interface: functional
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_functional_HEADER
#define LMT_functional_HEADER

#include "basicops.h"
#include "simd.h"
#include "ptrconstif.h"

namespace LMT {

/*!
    By default, simple function

    \friend hugo.leclerc@lmt.ens-cachan.fr
    \keyword Fonctionalité
    \author Leclerc
*/
template<class Op,class O2=void,class O3=void,class O4=void,class O5=void>
struct Function {
    explicit Function(const Op &ope = Op()):op(ope) {}
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename Op::template ReturnType<P1,P2,P3,P4>::T T; };
    template<class P1> typename ReturnType<P1>::T operator()(const P1 &p1) const { return op(p1); }
    template<class P1,class P2> typename ReturnType<P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return op(p1,p2); }
    template<class P1,class P2,class P3> typename ReturnType<P1,P2,P3>::T operator()(const P1 &p1,const P2 &p2,const P3 &p3) const { return op(p1,p2,p3); }
    template<class P1,class P2,class P3,class P4> typename ReturnType<P1,P2,P3,P4>::T operator()(const P1 &p1,const P2 &p2,const P3 &p3,const P4 &p4) const {
        return op(p1,p2,p3,p4);
    }
    Op op;
};

/*!
    \internal
*/
struct ALGOCompose1 { };

/*!
    \internal
*/
template<class O1,class O2>
struct Function<ALGOCompose1,O1,O2,void,void> {
    explicit Function(const O1 &o1_ = O1(),const O2 &o2_ = O2()):o1(o1_),o2(o2_) {}
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType {
        typedef typename O1::template ReturnType<typename O2::template ReturnType<P1>::T,P2,P3,P4>::T T;
    };
    
    template<class P1> typename ReturnType<P1>::T operator()(const P1 &p1) const { return o1(o2(p1)); }
    template<class P1,class P2> typename ReturnType<P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return o1(o2(p1),p2); }
    template<class P1,class P2,class P3> typename ReturnType<P1,P2,P3>::T operator()(const P1 &p1,const P2 &p2,const P3 &p3) const { return o1(o2(p1),p2,p3); }
    template<class P1,class P2,class P3,class P4> typename ReturnType<P1,P2,P3,P4>::T operator()(const P1 &p1,const P2 &p2,const P3 &p3,const P4 &p4) const {
        return o1(o2(p1),p2,p3,p4);
    }
    
    O1 o1;
    O2 o2;
};

/*!
    \internal
*/
template<class O1,bool const_O1,class O2,bool const_O2>
struct ALGOCompose1WithoutReturn {
    explicit ALGOCompose1WithoutReturn(const O1 &o1_ = O1(),const O2 &o2_ = O2()) { o1.val = &o1_; o2.val = &o2_; }
    explicit ALGOCompose1WithoutReturn(const O1 &o1_,O2 &o2_) { o1.val = &o1_; o2.val = &o2_; }
    explicit ALGOCompose1WithoutReturn(O1 &o1_,const O2 &o2_) { o1.val = &o1_; o2.val = &o2_; }
    explicit ALGOCompose1WithoutReturn(O1 &o1_,O2 &o2_) { o1.val = &o1_; o2.val = &o2_; }
    
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef void T; };
    
    template<class P1> void operator()(const P1 &p1) const { (*o1.val)((*o2.val)(p1)); }
    template<class P1> void operator()(      P1 &p1) const { (*o1.val)((*o2.val)(p1)); }
    template<class P1,class P2> void operator()(const P1 &p1,const P2 &p2) const { (*o1.val)((*o2.val)(p1),p2); }
    template<class P1,class P2> void operator()(const P1 &p1,      P2 &p2) const { (*o1.val)((*o2.val)(p1),p2); }
    template<class P1,class P2> void operator()(      P1 &p1,const P2 &p2) const { (*o1.val)((*o2.val)(p1),p2); }
    template<class P1,class P2> void operator()(      P1 &p1,      P2 &p2) const { (*o1.val)((*o2.val)(p1),p2); }
    template<class P1,class P2,class P3> void operator()(const P1 &p1,const P2 &p2,const P3 &p3) const { (*o1.val)((*o2.val)(p1),p2,p3); }
    template<class P1,class P2,class P3> void operator()(const P1 &p1,const P2 &p2,      P3 &p3) const { (*o1.val)((*o2.val)(p1),p2,p3); }
    template<class P1,class P2,class P3> void operator()(const P1 &p1,      P2 &p2,const P3 &p3) const { (*o1.val)((*o2.val)(p1),p2,p3); }
    template<class P1,class P2,class P3> void operator()(const P1 &p1,      P2 &p2,      P3 &p3) const { (*o1.val)((*o2.val)(p1),p2,p3); }
    template<class P1,class P2,class P3> void operator()(      P1 &p1,const P2 &p2,const P3 &p3) const { (*o1.val)((*o2.val)(p1),p2,p3); }
    template<class P1,class P2,class P3> void operator()(      P1 &p1,const P2 &p2,      P3 &p3) const { (*o1.val)((*o2.val)(p1),p2,p3); }
    template<class P1,class P2,class P3> void operator()(      P1 &p1,      P2 &p2,const P3 &p3) const { (*o1.val)((*o2.val)(p1),p2,p3); }
    template<class P1,class P2,class P3> void operator()(      P1 &p1,      P2 &p2,      P3 &p3) const { (*o1.val)((*o2.val)(p1),p2,p3); }
    template<class P1,class P2,class P3,class P4> void operator()(const P1 &p1,const P2 &p2,const P3 &p3,const P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(const P1 &p1,const P2 &p2,const P3 &p3,      P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(const P1 &p1,const P2 &p2,      P3 &p3,const P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(const P1 &p1,const P2 &p2,      P3 &p3,      P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(const P1 &p1,      P2 &p2,const P3 &p3,const P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(const P1 &p1,      P2 &p2,const P3 &p3,      P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(const P1 &p1,      P2 &p2,      P3 &p3,const P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(const P1 &p1,      P2 &p2,      P3 &p3,      P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(      P1 &p1,const P2 &p2,const P3 &p3,const P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(      P1 &p1,const P2 &p2,const P3 &p3,      P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(      P1 &p1,const P2 &p2,      P3 &p3,const P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(      P1 &p1,const P2 &p2,      P3 &p3,      P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(      P1 &p1,      P2 &p2,const P3 &p3,const P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(      P1 &p1,      P2 &p2,const P3 &p3,      P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(      P1 &p1,      P2 &p2,      P3 &p3,const P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    template<class P1,class P2,class P3,class P4> void operator()(      P1 &p1,      P2 &p2,      P3 &p3,      P4 &p4) const { (*o1.val)((*o2.val)(p1),p2,p3,p4); }
    
    PtrConstIf<O1,const_O1> o1;
    PtrConstIf<O2,const_O2> o2;
};

/*!
    \internal
*/
struct ALGOCompose2 { };


/*!
    \internal
*/
template<class O1,class O2>                                                                      
struct Function<ALGOCompose2,O1,O2,void,void> {
    explicit Function(const O1 &o1_ = O1(),const O2 &o2_ = O2()):o1(o1_),o2(o2_) {}
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType {
        typedef typename O1::template ReturnType<P1,typename O2::template ReturnType<P2>::T,P3,P4>::T T;
    };
    template<class P1,class P2> typename ReturnType<P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return o1(p1,o2(p2)); }
    template<class P1,class P2,class P3> typename ReturnType<P1,P2,P3>::T operator()(const P1 &p1,const P2 &p2,const P3 &p3) const { return o1(p1,o2(p2),p3); }
    template<class P1,class P2,class P3,class P4> typename ReturnType<P1,P2,P3,P4>::T operator()(const P1 &p1,const P2 &p2,const P3 &p3,const P4 &p4) const {
        return o1(p1,o2(p2),p3,p4);
    }
    
    O1 o1;
    O2 o2;
};

/*!
    \internal
*/
struct ALGOBinary { };


/*!
    \internal
*/
template<class Op,class O1,class O2>
struct Function<ALGOBinary,Op,O1,O2,void> {
    explicit Function(const Op &op_ = Op(),const O1 &o1_ = O1(),const O2 &o2_ = O2()):op(op_),o1(o1_),o2(o2_) {}
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType {
        typedef typename Op::template ReturnType<typename O1::template ReturnType<P1,P2,P3,P4>::T,typename O2::template ReturnType<P1,P2,P3,P4>::T>::T T;
    };
    template<class P1> typename ReturnType<P1>::T operator()(const P1 &p1) const { return op(o1(p1),o2(p1)); }
    template<class P1,class P2> typename ReturnType<P1,P2>::T operator()(const P1 &p1,const P2 &p2) const { return op(o1(p1,p2),o2(p1,p2)); }
    template<class P1,class P2,class P3> typename ReturnType<P1,P2,P3>::T operator()(const P1 &p1,const P2 &p2,const P3 &p3) const {
        return op(o1(p1,p2,p3),o2(p1,p2,p3));
    }
    template<class P1,class P2,class P3,class P4> typename ReturnType<P1,P2,P3,P4>::T operator()(const P1 &p1,const P2 &p2,const P3 &p3,const P4 &p4) const {
        return op(o1(p1,p2,p3,p4),o2(p1,p2,p3,p4));
    }
    Op op;
    O1 o1;
    O2 o2;
};

/*!
    \internal
*/
struct ALGOAssignExt { };

/*!
    \internal
*/
template<class Op,class TB,class AssOp>
struct Function<ALGOAssignExt,Op,TB,AssOp,void> {
    explicit Function(TB &tt,const Op &ope = Op(),const AssOp &ao=AssOp()):t(tt),op(ope),assop(ao) {}
    template<class P1,class P2=void,class P3=void> struct ReturnType { typedef TB T; };
    template<class P1> void operator()(const P1 &p1) const { assop.op(t, op(p1)); }
    template<class P1,class P2> void operator()(const P1 &p1,const P2 &p2) const { assop.op(t, op(p1,p2)); }
    template<class P1,class P2,class P3> void operator()(const P1 &p1,const P2 &p2,const P3 &p3) const { assop.op(t, op(p1,p2,p3)); }
    
    mutable TB &t;
    Op op;
    AssOp assop;
};

/*!
    \internal
*/
struct ALGOAssign1 { };

/*!
    \internal
*/
template<class Op,class AssOp>
struct Function<ALGOAssign1,Op,AssOp,void,void> {
    explicit Function(const Op &ope,const AssOp &ao=AssOp()):op(ope),assop(ao) {}
    template<class P1,class P2=void,class P3=void> struct ReturnType { typedef P1 T; };
    template<class P1> void operator()(P1 &p1) const { assop.op(p1,op(p1)); }
    template<class P1,class P2> void operator()(P1 &p1,const P2 &p2) const { assop.op(p1, op(p1,p2)); }
    template<class P1,class P2,class P3> void operator()(P1 &p1,const P2 &p2,const P3 &p3) const { assop.op(p1, op(p1,p2,p3)); }
    Op op;
    AssOp assop;
};

/*!
    \internal
*/
struct ALGOCst { };

/*!
    \internal
*/
template<class TT>
struct Function<ALGOCst,TT,void,void,void> {
    explicit Function(const TT &tt):t(tt) {}
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef TT T; };
    template<class P1> TT operator()(P1 &p1) const { return t; }
    template<class P1,class P2> TT operator()(P1 &p1,const P2 &p2) const { return t; }
    template<class P1,class P2,class P3> TT operator()(P1 &p1,const P2 &p2,const P3 &p3) const { return t; }
    template<class P1,class P2,class P3,class P4> TT operator()(P1 &p1,const P2 &p2,const P3 &p3,const P4 &p4) const { return t; }
    const TT &t;
};

// ----------------------------------------------------------------------------------------------------------------------------
/// \keyword Lambda
struct EquEqu { template<class P1,class P2> void op(P1 &p1,const P2 &p2) const { p1 = p2; } };

struct C_1 {};
struct C_2 {};
struct C_3 {};
struct C_4 {};

template<class Op> struct ConserveZeroes { static const unsigned res = false; };

#include "functional_unary.h"
#include "functional_binop.h"
#include "functional_cast.h"
#include "functional_assign.h"

struct PointedData1 {};
struct PointedData2 {};
struct PointedData3 {};
struct PointedData4 {};

/*!
    \relates Vec
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \keyword Mathématiques/Fonction
    \author Hugo Leclerc

*/
template<> struct Function<PointedData1> {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef void T; };
    template<class P1,class P2,class P3,class P4> struct ReturnType<P1 *,P2,P3,P4> { typedef P1& T; };
    
    template<class P1> const P1& operator()(const P1 *p1) const { return *p1; }
    template<class P1,class P2> const P1& operator()(const P1 *p1,const P2 &p2) const { return *p1; }
    template<class P1,class P2,class P3> const P1& operator()(const P1 *p1,const P2 &p2,const P3 &p3) const { return *p1; }
    template<class P1,class P2,class P3,class P4> const P1& operator()(const P1 *p1,const P2 &p2,const P3 &p3,const P4 &p4) const { return *p1; }
};

/*!
    \relates Vec
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \keyword Mathématiques/Fonction
    \author Hugo Leclerc

*/
template<> struct Function<PointedData2> {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef void T; };
    template<class P1,class P2,class P3,class P4> struct ReturnType<P1,P2 *,P3,P4> { typedef P2& T; };
    
    template<class P1,class P2> const P2& operator()(const P1 &p1,const P2 *p2) const { return *p2; }
    template<class P1,class P2,class P3> const P2& operator()(const P1 &p1,const P2 *p2,const P3 &p3) const { return *p2; }
    template<class P1,class P2,class P3,class P4> const P2& operator()(const P1 &p1,const P2 *p2,const P3 &p3,const P4 &p4) const { return *p2; }
};

/*!
    \relates Vec
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \keyword Mathématiques/Fonction
    \author Hugo Leclerc

*/
template<> struct Function<PointedData3> {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef void T; };
    template<class P1,class P2,class P3,class P4> struct ReturnType<P1,P2,P3 *,P4> { typedef P3& T; };
    
    template<class P1,class P2,class P3> const P3& operator()(const P1 &p1,const P2 &p2,const P3 *p3) const { return *p2; }
    template<class P1,class P2,class P3,class P4> const P3& operator()(const P1 &p1,const P2 &p2,const P3 *p3,const P4 &p4) const { return *p3; }
};

/*!
    \relates Vec
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \keyword Mathématiques/Fonction
    \author Hugo Leclerc

*/
template<> struct Function<PointedData4> {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef void T; };
    template<class P1,class P2,class P3,class P4> struct ReturnType<P1,P2,P3,P4 *> { typedef P4& T; };
    
    template<class P1,class P2,class P3,class P4> const P4& operator()(const P1 &p1,const P2 &p2,const P3 &p3,const P4 *p4) const { return *p4; }
};

// ----------------------------------------------------------------------------------------------------------------------------
template<> struct Function<C_1> {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef P1 T; };
    template<class P1> P1 operator()(const P1 &p1) const { return p1; }
    template<class P1,class P2> P1 operator()(const P1 &p1,const P2 &p2) const { return p1; }
    template<class P1,class P2,class P3> P1 operator()(const P1 &p1,const P2 &p2,const P3 &p3) const { return p1; }
    template<class P1,class P2,class P3,class P4> P1 operator()(const P1 &p1,const P2 &p2,const P3 &p3,const P4 &p4) const { return p1; }
    

    template<class T> Function<ALGOAssign1,Function<ALGOCst,T>,EquEqu> operator=(const T &val) const {
        return Function<ALGOAssign1,Function<ALGOCst,T>,EquEqu>( Function<ALGOCst,T>(val) );
    }
    template<class O1,class O2,class O3,class O4,class O5> Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,EquEqu>
    operator=(const Function<O1,O2,O3,O4,O5> &val) const { return Function<ALGOAssign1,Function<O1,O2,O3,O4,O5>,EquEqu>( val ); }
    
    Function<ALGOAssign1,Function<ALGOCst,int>,PlusEqu> operator++() const {
        return Function<ALGOAssign1,Function<ALGOCst,int>,PlusEqu>( Function<ALGOCst,int>(1) );
    }
    Function<ALGOAssign1,Function<ALGOCst,int>,MinusEqu> operator--() const {
        return Function<ALGOAssign1,Function<ALGOCst,int>,MinusEqu>( Function<ALGOCst,int>(1) );
    }
    Function<PointedData1> operator*() const {
        return Function<PointedData1>();
    }
};

template<> struct Function<C_2> {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef P2 T; };
    template<class P1,class P2> P2 operator()(const P1 &,const P2 &p2) const { return p2; }
    template<class P1,class P2,class P3> P2 operator()(const P1 &,const P2 &p2,const P3 &) const { return p2; }
    template<class P1,class P2,class P3,class P4> P2 operator()(const P1 &,const P2 &p2,const P3 &,const P4 &) const { return p2; }

    Function<PointedData2> operator*() const {
        return Function<PointedData2>();
    }
};

template<> struct Function<C_3> {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef P3 T; };
    template<class P1,class P2,class P3> P3 operator()(const P1 &,const P2 &,const P3 &p3) const { return p3; }
    template<class P1,class P2,class P3,class P4> P3 operator()(const P1 &,const P2 &,const P3 &p3,const P4 &) const { return p3; }

    Function<PointedData3> operator*() const {
        return Function<PointedData3>();
    }
};

template<> struct Function<C_4> {
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef P4 T; };
    template<class P1,class P2,class P3,class P4> P4 operator()(const P1 &,const P2 &,const P3 &,const P4 &p4) const { return p4; }

    Function<PointedData4> operator*() const {
        return Function<PointedData4>();
    }
};

static Function<C_1> _1;
static Function<C_2> _2;
static Function<C_3> _3;
static Function<C_4> _4;


// because we don't want the compiler to complain about unused static variables
/*!
    \internal
*/
inline void pouet_function() { _1 + _2 + _3 + _4; }


// ------------------------------------------------ AbsIndication ---------------------------------------------------------
/// \keyword Lambda
struct AbsIndication {
    //template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef typename SubComplex<P1>::T T; };
    template<class P1> typename SubComplex<P1>::T operator()(const P1 &p1) const { return abs_indication(p1); }
};
template<> struct ConserveZeroes<AbsIndication> { static const unsigned res = true; };

/*!
    \internal
*/
template<bool is_scalar,class TT> struct TypePromoteAbsIndicationWithIsScalarBool;
template<class TT> struct TypePromoteAbsIndicationWithIsScalarBool<true,TT> {
    typedef typename SubComplex<TT>::T T;
};

template<class TT>
struct TypePromote<AbsIndication,TT> {
    static const bool is_scalar = TypeInformation<TT>::is_scalar;
    typedef typename TypePromoteAbsIndicationWithIsScalarBool<is_scalar,TT>::T T;
};


}


#endif // LMT_functional_HEADER
