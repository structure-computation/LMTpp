//
// C++ Interface: %{MODULE}
//
// Description: 
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_TYPEPROMOTE_HEADER
#define LMT_TYPEPROMOTE_HEADER

#include <string>
#include "alternativeontype.h"
#ifndef WITHOUTCOMPLEX
    #include <complex>
#endif

namespace LMT {

/// contain a static double dexcibing "how many" information can be stored. Used in TypePromote
template<class TT> struct TypeInformation {
    static const int res = 0;
    static const int englobing = 0;
    static std::string type() { return "unknown"; }
    static const bool float_type = false;
    template<class TV> struct DeepVariant { typedef TV T; };
};

/// contain a static double dexcibing "how many" information can be stored. Used in TypePromote
template<class T> struct HasTypeInformation { static const bool res = false; };

template<> struct TypeInformation<void> {
    static const int res = 0;
    static const int englobing = 0;
    static std::string type() { return "void"; }
    static const bool float_type = false;
    template<class TV> struct DeepVariant { typedef TV T; };
};

/*!
m = [
    ('bool',0),
    ('unsigned',1),
    ('int',2),
    ('float',3),
    ('double',4),
    ('long double',5),
]
for i,vi in m:
    print 'template<> struct TypeInformation<'+i+'> {'
    print '    static const int res = %i;' % vi
    print '    static const int englobing = 0;'
    print '    static std::string type() { return "'+i+'"; }'
    print '    static const bool float_type = '+['false','true'][vi>=3]+';'
    print '    template<class TV> struct DeepVariant { typedef TV T; };'
    print '};'
*/
template<> struct TypeInformation<bool> {
    static const int res = 0;
    static const int englobing = 0;
    static const bool is_scalar = true;
    static std::string type() { return "bool"; }
    static const bool float_type = false;
    typedef bool SubType;
    template<class TV> struct DeepVariant { typedef TV T; };
};
template<> struct TypeInformation<unsigned> {
    static const int res = 1;
    static const int englobing = 0;
    static const bool is_scalar = true;
    static std::string type() { return "unsigned"; }
    static const bool float_type = false;
    typedef unsigned SubType;
    template<class TV> struct DeepVariant { typedef TV T; };
};
template<> struct TypeInformation<int> {
    static const int res = 2;
    static const int englobing = 0;
    static const bool is_scalar = true;
    static std::string type() { return "int"; }
    static const bool float_type = false;
    typedef int SubType;
    template<class TV> struct DeepVariant { typedef TV T; };
};
template<> struct TypeInformation<float> {
    static const int res = 3;
    static const int englobing = 0;
    static const bool is_scalar = true;
    static std::string type() { return "float"; }
    static const bool float_type = true;
    typedef float SubType;
    template<class TV> struct DeepVariant { typedef TV T; };
};
template<> struct TypeInformation<double> {
    static const int res = 4;
    static const int englobing = 0;
    static const bool is_scalar = true;
    static std::string type() { return "double"; }
    static const bool float_type = true;
    typedef double SubType;
    template<class TV> struct DeepVariant { typedef TV T; };
};
template<> struct TypeInformation<long double> {
    static const int res = 5;
    static const int englobing = 0;
    static const bool is_scalar = true;
    static std::string type() { return "long double"; }
    static const bool float_type = true;
    typedef long double SubType;
    template<class TV> struct DeepVariant { typedef TV T; };
};


template<class TT> struct SubComplex {
    typedef TT T;
};
#ifndef WITHOUTCOMPLEX
    template<class TT> struct TypeInformation<std::complex<TT> > {
        static const int res = TypeInformation<TT>::res;
        static const int englobing = 1 + TypeInformation<TT>::englobing;
        static const bool is_scalar = true;
        typedef TT SubType;
        template<class TV> struct Variant { typedef std::complex<TV> T; };
        template<class TV> struct DeepVariant { typedef std::complex<typename TypeInformation<TT>::template DeepVariant<TV>::T> T; };
        static std::string type() { return "complex<"+TypeInformation<TT>::type()+"> "; }
        static const bool float_type = TypeInformation<TT>::float_type;
    };
    template<class TT> struct SubComplex<std::complex<TT> > {
        typedef TT T;
    };
#endif

/**
*/
template<class T1,class T2> struct CanBeConvertedTo { static const bool res = false; };

template<class T1> struct CanBeConvertedTo<T1,T1> { static const bool res = true; };

template<> struct CanBeConvertedTo<unsigned,double> { static const bool res = true; };
template<> struct CanBeConvertedTo<int,double> { static const bool res = true; };
template<> struct CanBeConvertedTo<float,double> { static const bool res = true; };
template<> struct CanBeConvertedTo<double,double> { static const bool res = true; };
template<> struct CanBeConvertedTo<long double,double> { static const bool res = true; };

#ifndef WITHOUTCOMPLEX
    template<class T1,class T2> struct CanBeConvertedTo<T1,std::complex<T2> > { static const bool res = CanBeConvertedTo<T1,T2>::res; };
    template<> struct CanBeConvertedTo<std::complex<float>,std::complex<float> > { static const bool res = true; };
    template<> struct CanBeConvertedTo<std::complex<double>,std::complex<double> > { static const bool res = true; };
#endif

// --------------------------------------------------------------------------------------------------------------------

template<class Op,class T1,class T2=void,class T3=void> struct TypePromote {};

template<class Op,bool eng_t1_sup_t2,bool eng_t2_sup_t1,class T1,class T2,unsigned englobing> struct TypePromoteWithSubType;

template<class Op,class T1,class T2,unsigned englobing> struct TypePromoteWithSubType<Op,false,false,T1,T2,englobing> {
    typedef typename AlternativeOnType< (TypeInformation<T2>::res>TypeInformation<T1>::res), T1, T2 >::T T;
};
template<class Op,class T1,class T2,unsigned englobing> struct TypePromoteWithSubType<Op,false,true,T1,T2,englobing> {
    typedef typename TypeInformation<T2>::SubType ST;
    typedef typename TypePromote<Op,T1,ST>::T BT;
    typedef typename TypeInformation<T2>::template Variant<BT>::T T;
};
template<class Op,class T1,class T2,unsigned englobing> struct TypePromoteWithSubType<Op,true,false,T1,T2,englobing> {
    typedef typename TypeInformation<T1>::SubType ST;
    typedef typename TypePromote<Op,ST,T2>::T BT;
    typedef typename TypeInformation<T1>::template Variant<BT>::T T;
};

template<class Op,class T1> struct TypePromote<Op,T1,void,void> {
    typedef typename Op::template ReturnType<T1>::T T;
};


// --------------------------------------------------------------------------------------------------------------------
/*! gives the best type for result of op(A,B) where A is of type T1 and B is of type T2.
  Example :
    \code
        TypePromote<Plus,bool,double>::T -> double
    say that double contains more informations than bool. TypePromote works for Vec, Mat, ...
*/
template<class Op,class T1,class T2>
struct TypePromote<Op,T1,T2,void> {
    typedef typename TypePromoteWithSubType<
        Op,
        ( TypeInformation<T1>::englobing > TypeInformation<T2>::englobing ),
        ( TypeInformation<T1>::englobing < TypeInformation<T2>::englobing ),
        T1, T2,
        TypeInformation<T1>::englobing
    >::T T;
};


struct Equal;
struct NotEqual;
struct Less;
struct Greater;
struct LessEq;
struct GreaterEq;
template<class T1,class T2> struct TypePromoteWithSubType<Equal    ,false,false,T1,T2,0> { typedef bool T; };
template<class T1,class T2> struct TypePromoteWithSubType<NotEqual ,false,false,T1,T2,0> { typedef bool T; };
template<class T1,class T2> struct TypePromoteWithSubType<Less     ,false,false,T1,T2,0> { typedef bool T; };
template<class T1,class T2> struct TypePromoteWithSubType<Greater  ,false,false,T1,T2,0> { typedef bool T; };
template<class T1,class T2> struct TypePromoteWithSubType<LessEq   ,false,false,T1,T2,0> { typedef bool T; };
template<class T1,class T2> struct TypePromoteWithSubType<GreaterEq,false,false,T1,T2,0> { typedef bool T; };

#ifndef WITHOUTCOMPLEX
    template<class T1,class T2>
    struct TypePromote<Equal,std::complex<T1>,std::complex<T2> > {
        typedef bool T;
    };
    template<class T1,class T2>
    struct TypePromote<NotEqual,std::complex<T1>,std::complex<T2> > {
        typedef bool T;
    };
#endif

// ------------------------------------------------ scalar type ---------------------------------------------------------
template<class TV,class Prefered=double> struct FloatType {
    typedef typename AlternativeOnType< TypeInformation<TV>::float_type,
        typename TypeInformation<TV>::template DeepVariant<Prefered>::T,
        TV
    >::T T;
};

template<class T> struct IsComplex { static const bool res = false; };
#ifndef WITHOUTCOMPLEX
template<class T> struct IsComplex<std::complex<T> > { static const bool res = true; };
#endif

template<class TT, bool is_scalar=TypeInformation<TT>::is_scalar> struct IsScalar {};
template<class TT> struct IsScalar<TT,true> {typedef TT T;};

template<class T> void display_type( std::ostream &os, const T & ) {
    os << TypeInformation<T>::type();
}

}

#endif // LMT_TYPEPROMOTE_HEADER

