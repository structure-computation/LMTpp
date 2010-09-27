
//
// C++ Interface: matelem
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matelem_HEADER
#define LMT_matelem_HEADER

namespace LMT {

/**
*/
template<class TM,class Structure,class Storage,unsigned alignement=1,int nr=0>
struct MatElem;

template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Conj,typename TV::template SubType<0>::T>::T conj(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return conj((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Abs,typename TV::template SubType<0>::T>::T abs(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return abs((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Acos,typename TV::template SubType<0>::T>::T acos(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return acos((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Asin,typename TV::template SubType<0>::T>::T asin(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return asin((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Atan,typename TV::template SubType<0>::T>::T atan(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return atan((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Cos,typename TV::template SubType<0>::T>::T cos(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return cos((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Cosh,typename TV::template SubType<0>::T>::T cosh(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return cosh((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Exp,typename TV::template SubType<0>::T>::T exp(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return exp((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Log,typename TV::template SubType<0>::T>::T log(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return log((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Log10,typename TV::template SubType<0>::T>::T log10(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return log10((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Sin,typename TV::template SubType<0>::T>::T sin(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return sin((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Sinh,typename TV::template SubType<0>::T>::T sinh(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return sinh((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Sqrt,typename TV::template SubType<0>::T>::T sqrt(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return sqrt((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Tan,typename TV::template SubType<0>::T>::T tan(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return tan((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Tanh,typename TV::template SubType<0>::T>::T tanh(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return tanh((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Real,typename TV::template SubType<0>::T>::T real(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return real((typename TV::template SubType<0>::T)me);
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename TypePromote<Imag,typename TV::template SubType<0>::T>::T imag(const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return imag((typename TV::template SubType<0>::T)me);
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Plus::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator+(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v + me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Plus::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator+(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() + v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Plus::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator+(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() + m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Minus::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator-(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v - me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Minus::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator-(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() - v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Minus::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator-(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() - m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Modulus::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator%(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v % me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Modulus::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator%(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() % v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Modulus::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator%(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() % m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Multiplies::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator*(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v * me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Multiplies::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator*(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() * v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Multiplies::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator*(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() * m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Divides::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator/(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v / me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Divides::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator/(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() / v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Divides::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator/(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() / m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Equal::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator==(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v == me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Equal::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator==(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() == v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Equal::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator==(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() == m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename NotEqual::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator!=(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v != me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename NotEqual::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator!=(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() != v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename NotEqual::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator!=(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() != m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Less::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator<(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v < me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Less::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator<(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() < v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Less::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator<(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() < m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Greater::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator>(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v > me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Greater::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator>(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() > v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Greater::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator>(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() > m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename LessEq::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator<=(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v <= me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename LessEq::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator<=(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() <= v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename LessEq::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator<=(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() <= m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename GreaterEq::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator>=(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v >= me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename GreaterEq::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator>=(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() >= v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename GreaterEq::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator>=(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() >= m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename And::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator&(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v & me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename And::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator&(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() & v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename And::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator&(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() & m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Or::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator|(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v | me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Or::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator|(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() | v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Or::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator|(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() | m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Xor::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator^(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v ^ me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Xor::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator^(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() ^ v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Xor::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator^(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() ^ m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename AndAnd::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator&&(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v && me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename AndAnd::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator&&(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() && v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename AndAnd::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator&&(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() && m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename OrOr::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator||(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return v || me.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename OrOr::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator||(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return me.conv() || v;
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename OrOr::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator||(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return m1.conv() || m2.conv();
}
template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Pow::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T pow(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {
    return pow( v, me.conv() );
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr,class T1>
typename Pow::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T pow(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {
    return pow( me.conv(), v );
}
template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>
typename Pow::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operatorpow(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {
    return pow( m1.conv(), m2.conv() );
}
template<class TV,class Structure,class Storage,unsigned alignement,int nr>
typename Pow::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,int>::T pow(const MatElem<TV,Structure,Storage,alignement,nr> &me,int v) {
    return pow( me.conv(), v );
}

};

#endif // LMT_matelem_HEADER


