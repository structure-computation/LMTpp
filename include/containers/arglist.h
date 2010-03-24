#ifndef LMT_arglist_HEADER
#define LMT_arglist_HEADER

namespace LMT {

/*!
  \internal
 */
template<class T0> struct ArgList1_0 { ArgList1_0(const T0 &A0):a0(A0) {} const T0 &a0; };
/*!
  \internal
 */
template<class T0> struct ArgList1_1 { ArgList1_1(T0 &A0):a0(A0) {} T0 &a0; };
/*!
  \internal
 */
template<class T0,class T1> struct ArgList2_0 { ArgList2_0(const T0 &A0,const T1 &A1):a0(A0),a1(A1) {} const T0 &a0; const T1 &a1; };
/*!
  \internal
 */
template<class T0,class T1> struct ArgList2_1 { ArgList2_1(T0 &A0,const T1 &A1):a0(A0),a1(A1) {} T0 &a0; const T1 &a1; };
/*!
  \internal
 */
template<class T0,class T1> struct ArgList2_2 { ArgList2_2(const T0 &A0,T1 &A1):a0(A0),a1(A1) {} const T0 &a0; T1 &a1; };
/*!
  \internal
 */
template<class T0,class T1> struct ArgList2_3 { ArgList2_3(T0 &A0,T1 &A1):a0(A0),a1(A1) {} T0 &a0; T1 &a1; };
/*!
  \internal
 */
template<class T0,class T1,class T2> struct ArgList3_0 { ArgList3_0(const T0 &A0,const T1 &A1,const T2 &A2):a0(A0),a1(A1),a2(A2) {} const T0 &a0; const T1 &a1; const T2 &a2; };
/*!
  \internal
 */
template<class T0,class T1,class T2> struct ArgList3_1 { ArgList3_1(T0 &A0,const T1 &A1,const T2 &A2):a0(A0),a1(A1),a2(A2) {} T0 &a0; const T1 &a1; const T2 &a2; };
/*!
  \internal
 */
template<class T0,class T1,class T2> struct ArgList3_2 { ArgList3_2(const T0 &A0,T1 &A1,const T2 &A2):a0(A0),a1(A1),a2(A2) {} const T0 &a0; T1 &a1; const T2 &a2; };
/*!
  \internal
 */
template<class T0,class T1,class T2> struct ArgList3_3 { ArgList3_3(T0 &A0,T1 &A1,const T2 &A2):a0(A0),a1(A1),a2(A2) {} T0 &a0; T1 &a1; const T2 &a2; };
/*!
  \internal
 */
template<class T0,class T1,class T2> struct ArgList3_4 { ArgList3_4(const T0 &A0,const T1 &A1,T2 &A2):a0(A0),a1(A1),a2(A2) {} const T0 &a0; const T1 &a1; T2 &a2; };
/*!
  \internal
 */
template<class T0,class T1,class T2> struct ArgList3_5 { ArgList3_5(T0 &A0,const T1 &A1,T2 &A2):a0(A0),a1(A1),a2(A2) {} T0 &a0; const T1 &a1; T2 &a2; };
/*!
  \internal
 */
template<class T0,class T1,class T2> struct ArgList3_6 { ArgList3_6(const T0 &A0,T1 &A1,T2 &A2):a0(A0),a1(A1),a2(A2) {} const T0 &a0; T1 &a1; T2 &a2; };
/*!
  \internal
 */
template<class T0,class T1,class T2> struct ArgList3_7 { ArgList3_7(T0 &A0,T1 &A1,T2 &A2):a0(A0),a1(A1),a2(A2) {} T0 &a0; T1 &a1; T2 &a2; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_0 { ArgList4_0(const T0 &A0,const T1 &A1,const T2 &A2,const T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} const T0 &a0; const T1 &a1; const T2 &a2; const T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_1 { ArgList4_1(T0 &A0,const T1 &A1,const T2 &A2,const T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} T0 &a0; const T1 &a1; const T2 &a2; const T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_2 { ArgList4_2(const T0 &A0,T1 &A1,const T2 &A2,const T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} const T0 &a0; T1 &a1; const T2 &a2; const T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_3 { ArgList4_3(T0 &A0,T1 &A1,const T2 &A2,const T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} T0 &a0; T1 &a1; const T2 &a2; const T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_4 { ArgList4_4(const T0 &A0,const T1 &A1,T2 &A2,const T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} const T0 &a0; const T1 &a1; T2 &a2; const T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_5 { ArgList4_5(T0 &A0,const T1 &A1,T2 &A2,const T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} T0 &a0; const T1 &a1; T2 &a2; const T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_6 { ArgList4_6(const T0 &A0,T1 &A1,T2 &A2,const T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} const T0 &a0; T1 &a1; T2 &a2; const T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_7 { ArgList4_7(T0 &A0,T1 &A1,T2 &A2,const T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} T0 &a0; T1 &a1; T2 &a2; const T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_8 { ArgList4_8(const T0 &A0,const T1 &A1,const T2 &A2,T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} const T0 &a0; const T1 &a1; const T2 &a2; T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_9 { ArgList4_9(T0 &A0,const T1 &A1,const T2 &A2,T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} T0 &a0; const T1 &a1; const T2 &a2; T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_10 { ArgList4_10(const T0 &A0,T1 &A1,const T2 &A2,T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} const T0 &a0; T1 &a1; const T2 &a2; T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_11 { ArgList4_11(T0 &A0,T1 &A1,const T2 &A2,T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} T0 &a0; T1 &a1; const T2 &a2; T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_12 { ArgList4_12(const T0 &A0,const T1 &A1,T2 &A2,T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} const T0 &a0; const T1 &a1; T2 &a2; T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_13 { ArgList4_13(T0 &A0,const T1 &A1,T2 &A2,T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} T0 &a0; const T1 &a1; T2 &a2; T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_14 { ArgList4_14(const T0 &A0,T1 &A1,T2 &A2,T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} const T0 &a0; T1 &a1; T2 &a2; T3 &a3; };
/*!
  \internal
 */
template<class T0,class T1,class T2,class T3> struct ArgList4_15 { ArgList4_15(T0 &A0,T1 &A1,T2 &A2,T3 &A3):a0(A0),a1(A1),a2(A2),a3(A3) {} T0 &a0; T1 &a1; T2 &a2; T3 &a3; };


/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0> ArgList1_0<T0> arglist(const T0 &A0) { return ArgList1_0<T0>(A0); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0> ArgList1_1<T0> arglist(T0 &A0) { return ArgList1_1<T0>(A0); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1> ArgList2_0<T0,T1> arglist(const T0 &A0,const T1 &A1) { return ArgList2_0<T0,T1>(A0,A1); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1> ArgList2_1<T0,T1> arglist(T0 &A0,const T1 &A1) { return ArgList2_1<T0,T1>(A0,A1); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1> ArgList2_2<T0,T1> arglist(const T0 &A0,T1 &A1) { return ArgList2_2<T0,T1>(A0,A1); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1> ArgList2_3<T0,T1> arglist(T0 &A0,T1 &A1) { return ArgList2_3<T0,T1>(A0,A1); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2> ArgList3_0<T0,T1,T2> arglist(const T0 &A0,const T1 &A1,const T2 &A2) { return ArgList3_0<T0,T1,T2>(A0,A1,A2); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2> ArgList3_1<T0,T1,T2> arglist(T0 &A0,const T1 &A1,const T2 &A2) { return ArgList3_1<T0,T1,T2>(A0,A1,A2); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2> ArgList3_2<T0,T1,T2> arglist(const T0 &A0,T1 &A1,const T2 &A2) { return ArgList3_2<T0,T1,T2>(A0,A1,A2); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2> ArgList3_3<T0,T1,T2> arglist(T0 &A0,T1 &A1,const T2 &A2) { return ArgList3_3<T0,T1,T2>(A0,A1,A2); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2> ArgList3_4<T0,T1,T2> arglist(const T0 &A0,const T1 &A1,T2 &A2) { return ArgList3_4<T0,T1,T2>(A0,A1,A2); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2> ArgList3_5<T0,T1,T2> arglist(T0 &A0,const T1 &A1,T2 &A2) { return ArgList3_5<T0,T1,T2>(A0,A1,A2); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2> ArgList3_6<T0,T1,T2> arglist(const T0 &A0,T1 &A1,T2 &A2) { return ArgList3_6<T0,T1,T2>(A0,A1,A2); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2> ArgList3_7<T0,T1,T2> arglist(T0 &A0,T1 &A1,T2 &A2) { return ArgList3_7<T0,T1,T2>(A0,A1,A2); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_0<T0,T1,T2,T3> arglist(const T0 &A0,const T1 &A1,const T2 &A2,const T3 &A3) { return ArgList4_0<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_1<T0,T1,T2,T3> arglist(T0 &A0,const T1 &A1,const T2 &A2,const T3 &A3) { return ArgList4_1<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_2<T0,T1,T2,T3> arglist(const T0 &A0,T1 &A1,const T2 &A2,const T3 &A3) { return ArgList4_2<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_3<T0,T1,T2,T3> arglist(T0 &A0,T1 &A1,const T2 &A2,const T3 &A3) { return ArgList4_3<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_4<T0,T1,T2,T3> arglist(const T0 &A0,const T1 &A1,T2 &A2,const T3 &A3) { return ArgList4_4<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_5<T0,T1,T2,T3> arglist(T0 &A0,const T1 &A1,T2 &A2,const T3 &A3) { return ArgList4_5<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_6<T0,T1,T2,T3> arglist(const T0 &A0,T1 &A1,T2 &A2,const T3 &A3) { return ArgList4_6<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_7<T0,T1,T2,T3> arglist(T0 &A0,T1 &A1,T2 &A2,const T3 &A3) { return ArgList4_7<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_8<T0,T1,T2,T3> arglist(const T0 &A0,const T1 &A1,const T2 &A2,T3 &A3) { return ArgList4_8<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_9<T0,T1,T2,T3> arglist(T0 &A0,const T1 &A1,const T2 &A2,T3 &A3) { return ArgList4_9<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_10<T0,T1,T2,T3> arglist(const T0 &A0,T1 &A1,const T2 &A2,T3 &A3) { return ArgList4_10<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_11<T0,T1,T2,T3> arglist(T0 &A0,T1 &A1,const T2 &A2,T3 &A3) { return ArgList4_11<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_12<T0,T1,T2,T3> arglist(const T0 &A0,const T1 &A1,T2 &A2,T3 &A3) { return ArgList4_12<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_13<T0,T1,T2,T3> arglist(T0 &A0,const T1 &A1,T2 &A2,T3 &A3) { return ArgList4_13<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_14<T0,T1,T2,T3> arglist(const T0 &A0,T1 &A1,T2 &A2,T3 &A3) { return ArgList4_14<T0,T1,T2,T3>(A0,A1,A2,A3); }
/*!
 \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
 */
template<class T0,class T1,class T2,class T3> ArgList4_15<T0,T1,T2,T3> arglist(T0 &A0,T1 &A1,T2 &A2,T3 &A3) { return ArgList4_15<T0,T1,T2,T3>(A0,A1,A2,A3); }

/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1> ArgList2_0<T0,T1> append_to_arglist(ArgList1_0<T0> al,const T1 &n) { return ArgList2_0<T0,T1>(al.a0,n); }
template<class T0,class T1> ArgList2_1<T0,T1> append_to_arglist(ArgList1_0<T0> al,      T1 &n) { return ArgList2_0<T0,T1>(al.a0,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1> ArgList2_2<T0,T1> append_to_arglist(ArgList1_1<T0> al,const T1 &n) { return ArgList2_1<T0,T1>(al.a0,n); }
template<class T0,class T1> ArgList2_3<T0,T1> append_to_arglist(ArgList1_1<T0> al,      T1 &n) { return ArgList2_1<T0,T1>(al.a0,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2> ArgList3_0<T0,T1,T2> append_to_arglist(ArgList2_0<T0,T1> al,const T2 &n) { return ArgList3_0<T0,T1,T2>(al.a0,al.a1,n); }
template<class T0,class T1,class T2> ArgList3_1<T0,T1,T2> append_to_arglist(ArgList2_0<T0,T1> al,      T2 &n) { return ArgList3_0<T0,T1,T2>(al.a0,al.a1,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2> ArgList3_2<T0,T1,T2> append_to_arglist(ArgList2_1<T0,T1> al,const T2 &n) { return ArgList3_1<T0,T1,T2>(al.a0,al.a1,n); }
template<class T0,class T1,class T2> ArgList3_3<T0,T1,T2> append_to_arglist(ArgList2_1<T0,T1> al,      T2 &n) { return ArgList3_1<T0,T1,T2>(al.a0,al.a1,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2> ArgList3_4<T0,T1,T2> append_to_arglist(ArgList2_2<T0,T1> al,const T2 &n) { return ArgList3_2<T0,T1,T2>(al.a0,al.a1,n); }
template<class T0,class T1,class T2> ArgList3_5<T0,T1,T2> append_to_arglist(ArgList2_2<T0,T1> al,      T2 &n) { return ArgList3_2<T0,T1,T2>(al.a0,al.a1,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2> ArgList3_6<T0,T1,T2> append_to_arglist(ArgList2_3<T0,T1> al,const T2 &n) { return ArgList3_3<T0,T1,T2>(al.a0,al.a1,n); }
template<class T0,class T1,class T2> ArgList3_7<T0,T1,T2> append_to_arglist(ArgList2_3<T0,T1> al,      T2 &n) { return ArgList3_3<T0,T1,T2>(al.a0,al.a1,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2,class T3> ArgList4_0<T0,T1,T2,T3> append_to_arglist(ArgList3_0<T0,T1,T2> al,const T3 &n) { return ArgList4_0<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
template<class T0,class T1,class T2,class T3> ArgList4_1<T0,T1,T2,T3> append_to_arglist(ArgList3_0<T0,T1,T2> al,      T3 &n) { return ArgList4_0<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2,class T3> ArgList4_2<T0,T1,T2,T3> append_to_arglist(ArgList3_1<T0,T1,T2> al,const T3 &n) { return ArgList4_1<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
template<class T0,class T1,class T2,class T3> ArgList4_3<T0,T1,T2,T3> append_to_arglist(ArgList3_1<T0,T1,T2> al,      T3 &n) { return ArgList4_1<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2,class T3> ArgList4_4<T0,T1,T2,T3> append_to_arglist(ArgList3_2<T0,T1,T2> al,const T3 &n) { return ArgList4_2<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
template<class T0,class T1,class T2,class T3> ArgList4_5<T0,T1,T2,T3> append_to_arglist(ArgList3_2<T0,T1,T2> al,      T3 &n) { return ArgList4_2<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2,class T3> ArgList4_6<T0,T1,T2,T3> append_to_arglist(ArgList3_3<T0,T1,T2> al,const T3 &n) { return ArgList4_3<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
template<class T0,class T1,class T2,class T3> ArgList4_7<T0,T1,T2,T3> append_to_arglist(ArgList3_3<T0,T1,T2> al,      T3 &n) { return ArgList4_3<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2,class T3> ArgList4_8<T0,T1,T2,T3> append_to_arglist(ArgList3_4<T0,T1,T2> al,const T3 &n) { return ArgList4_4<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
template<class T0,class T1,class T2,class T3> ArgList4_9<T0,T1,T2,T3> append_to_arglist(ArgList3_4<T0,T1,T2> al,      T3 &n) { return ArgList4_4<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2,class T3> ArgList4_10<T0,T1,T2,T3> append_to_arglist(ArgList3_5<T0,T1,T2> al,const T3 &n) { return ArgList4_5<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
template<class T0,class T1,class T2,class T3> ArgList4_11<T0,T1,T2,T3> append_to_arglist(ArgList3_5<T0,T1,T2> al,      T3 &n) { return ArgList4_5<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2,class T3> ArgList4_12<T0,T1,T2,T3> append_to_arglist(ArgList3_6<T0,T1,T2> al,const T3 &n) { return ArgList4_6<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
template<class T0,class T1,class T2,class T3> ArgList4_13<T0,T1,T2,T3> append_to_arglist(ArgList3_6<T0,T1,T2> al,      T3 &n) { return ArgList4_6<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
/*! \relates arglist
  Convenience function to pass multiple parameters to apply
 \internal
   */

template<class T0,class T1,class T2,class T3> ArgList4_14<T0,T1,T2,T3> append_to_arglist(ArgList3_7<T0,T1,T2> al,const T3 &n) { return ArgList4_7<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
template<class T0,class T1,class T2,class T3> ArgList4_15<T0,T1,T2,T3> append_to_arglist(ArgList3_7<T0,T1,T2> al,      T3 &n) { return ArgList4_7<T0,T1,T2,T3>(al.a0,al.a1,al.a2,n); }
};

#endif // LMT_arglist_HEADER
