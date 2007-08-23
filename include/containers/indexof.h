//
// C++ Interface: indexof
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_indexof_HEADER
#define LMT_indexof_HEADER

namespace LMT {

/// parent class for Carac. Deriving is not mandatory but is a convenient way to get a SubType definition
struct HetName { template<unsigned n,unsigned inner=0> struct SubType { typedef void T; }; };
///
struct IndexOfMagicValue { static const unsigned res = 123456; };

///
namespace LMTPRIVATE {
    template<class Carac,class TE,class T,unsigned n>
    struct IndexOf { static const unsigned res = IndexOf<Carac,TE,typename Carac::template SubType<n+1>::T,n+1>::res; };
    template<class Carac,class TE,unsigned n>
    struct IndexOf<Carac,TE,void,n> {
        /** IT SEEMS THAT TE IS NOT INCLUDED IN HeterogeneousVector<Carac> */
        static const unsigned res = IndexOfMagicValue::res;
    };
    template<class Carac,class T,unsigned n>
    struct IndexOf<Carac,T,T,n> { static const unsigned res = n; };
    
    template<class Carac,class T,unsigned n>
    struct NbSubTypes { static const unsigned res = NbSubTypes<Carac,typename Carac::template SubType<n+1>::T,n+1>::res; };
    template<class Carac,unsigned n>
    struct NbSubTypes<Carac,void,n> { static const unsigned res = n; };
    
    template<class Carac,class SOP,class T,unsigned n>
    struct MaxStaticP {
        static const unsigned val_curr = SOP::template Val<T>::res;
        static const unsigned val_next = MaxStaticP<Carac,SOP,typename Carac::template SubType<n+1>::T,n+1>::res;
        static const unsigned res = ( val_curr > val_next ? val_curr : val_next );
    };
    template<class Carac,class SOP,unsigned n>
    struct MaxStaticP<Carac,SOP,void,n> { static const unsigned res = 0; };
};


/** index of subtype TE in Carac (with template<unsigned n,unsigned inner> struct SubType { typedef ... T; })
    \relates LMT::HeterogeneousVector
    \relates LMT::HeterogeneousPack
 */
template<class Carac,class TE> struct IndexOf {
    static const unsigned res = LMTPRIVATE::IndexOf<Carac,TE,typename Carac::template SubType<0>::T,0>::res;
};

/** index of subtype TE in Carac (with template<unsigned n,unsigned inner> struct SubType { typedef ... T; })
    \relates LMT::HeterogeneousVector
    \relates LMT::HeterogeneousPack
 */
template<class Carac> struct NbSubTypes {
    static const unsigned res = LMTPRIVATE::NbSubTypes<Carac,typename Carac::template SubType<0>::T,0>::res;
};

/** Max of SOP<SubElemType>::val.
    \relates LMT::HeterogeneousVector
    \relates LMT::HeterogeneousPack
 */
template<class Carac,class SOP> struct MaxStatic {
    static const unsigned res = LMTPRIVATE::MaxStaticP<Carac,SOP,typename Carac::template SubType<0>::T,0>::res;
};

};

#endif // LMT_indexof_HEADER
