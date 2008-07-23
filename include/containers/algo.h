//
// C++ Interface: algo
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_algo_HEADER
#define LMT_algo_HEADER

#include "vec.h"

namespace LMT {

// -------------------------------------------------------------------- sort --------------------------------------------------------------------
namespace ALGOPRIVATE {

/*!
Structure interne à la LMT++
*/
    struct Sort {
        template<class T1,class T2,class Op> void operator()(T1 &val1,T2 &val2,const Op &op) const {
            if ( op(val1,val2) ) swap( val1, val2 );
        }
        template<class T,class TL,class Op> void operator()(T &val,unsigned cpt,TL &l,const Op &op) const {
            apply_range( l, cpt, l.size(), *this, val, op );
        }
    };
};
/*! 
    sort elements of l in ascending order, according to op::operator()(v1,v2) as comparison operator
   assuming swap is possible between all elements of l
    \relates Vec
    \relates apply
    \relates apply_wi
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr
*/
template<class TL,class Op> void sort(TL &l,const Op &op) {
    apply_wi( l, ALGOPRIVATE::Sort(), l, op );
}
/*!
     sort elements of l in ascending order, assuming swap is possible between all elements of l
    \relates Vec
        \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr
*/
template<class TL> void sort(TL &l) { sort(l,Less()); }

// -------------------------------------------------------------------- sort --------------------------------------------------------------------
namespace ALGOPRIVATE {
    struct SortWithIndex {
        template<class T1,class T2,class Op> void operator()(T1 &val1,unsigned i,T2 &val2,const Op &op,unsigned cpt) {
            if ( op(val1,val2) ) {
                swap( val1, val2 );
                swap( index[cpt], index[i] );
            }
        }
        template<class T,class TL,class Op> void operator()(T &val,unsigned cpt,TL &l,const Op &op) {
            apply_range_wi( l, cpt, l.size(), *this, val, op, cpt );
        }
        Vec<unsigned> index;
    };
};
/*!
    sort elements of l in ascending order, assuming swap is possible between all elements of l
    \relates Vec
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr
*/
template<class TL,class Op> Vec<unsigned> sort_with_index(TL &l,const Op &op) {
    ALGOPRIVATE::SortWithIndex s;
    s.index = range( l.size() );
    apply_wi( l, s, l, op );
    return s.index;
}
/*!
     sort elements of l in ascending order, assuming swap is possible between all elements of l
    \relates Vec
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr
*/
template<class TL> Vec<unsigned> sort_with_index(TL &l) { return sort_with_index(l,Less()); }

// ----------------------------------------------------------------- remove_doubles -----------------------------------------------------------------
namespace ALGOPRIVATE {
    template<class Op> struct RemoveDoubles {
        struct RemoveDoublesBis {
            template<class T1,class T2> void operator()(T1 &val2,T2 &val1) {
                res = res || (*op)(val1,val2);
            }
            bool res;
            const Op *op;
        };
        template<class T,class TL> bool operator()(T &val,TL &l) {
            RemoveDoublesBis rb; rb.op = op; rb.res = false;
            apply_range(l, 0, j, rb, val );
            if ( rb.res == false ) ++j;
            return rb.res;
        }
        const Op *op;
        unsigned j;
    };
};
/*! 
    remove elements which are considered to be equal using Op(v1,v2). Keeps the first ones.
    l has not to be sorted
    <strong> this procedure does not keep order of elements </strong>
    \relates Vec
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr
*/
template<class TL,class Op> void remove_doubles(TL &l,const Op &op) {
    ALGOPRIVATE::RemoveDoubles<Op> s; s.op = &op; s.j = 0;
    remove_if(l, s, l );
}

struct ExactlyEqual {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef bool T; };
    template<class P1,class P2> bool operator()(const P1 &p1,const P2 &p2) const { return p1 == p2; }
};
template<class NameDM> struct ExactlyEqualDM {
    template<class P1,class P2,class P3=void,class P4=void> struct ReturnType { typedef bool T; };
    template<class P1,class P2> bool operator()(const P1 &p1,const P2 &p2) const { return p1.member_named(NameDM()) == p2.member_named(NameDM()); }
};

template<class TT> struct ExactlyEqualTo {
    ExactlyEqualTo(const TT &v):val(v) {}
    template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef bool T; };
    template<class P1> bool operator()(const P1 &p1) const { return p1 == val; }
    const TT &val;
};
template<class T> ExactlyEqualTo<T> exactly_equal(const T &val) { return ExactlyEqualTo<T>(val); }

//
// template<class TT> struct ExactlyEqualTo {
//     ExactlyEqualTo(const TT &v):val(v) {}
//     template<class P1,class P2=void,class P3=void,class P4=void> struct ReturnType { typedef bool T; };
//     template<class P1> bool operator()(const P1 &p1) const { return p1 == val; }
//     const TT &val;
// };
// //
// template<class T> ApproxEqualTo<T> approx_equal(const T &val,const T ) { return ApproxEqualTo<T>(val); }


/*!
    remove elements which are considered to be equal. Keeps the first ones.
    l has not to be sorted
    <strong> this procedure does not keep order of elements </strong>
    \relates Vec
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr
*/
template<class TL> void remove_doubles(TL &l) { remove_doubles(l,ExactlyEqual()); }

// ----------------------------------------------------------------- minmax -----------------------------------------------------------------
struct MinMax {
    template<class T2,class T> void operator()(const T2 &val,T &mi,T &ma) const {
        mi = min(mi,val);
        ma = max(ma,val);
    }
    template<class T2,class Op,class T> void operator()(const T2 &val,const Op &op,T &mi,T &ma) const {
        mi = min(mi,op(val));
        ma = max(ma,op(val));
    }
};
template<class TL,class T> void get_min_max(const TL &l,T &mi,T &ma) {
    mi = std::numeric_limits<T>::max();
    ma = -mi;
    apply( l, MinMax(), mi, ma );
}

template<class TL,class T> void get_min_max(const TL &l,Vec<T,-1> &mi,Vec<T,-1> &ma) {
    mi.set( std::numeric_limits<T>::max() );
    ma.set( -std::numeric_limits<T>::max() );
    apply( l, MinMax(), mi, ma );
}

template<class TL,class Op,class T> void get_min_max(const TL &l,const Op &op,T &mi,T &ma) {
    mi = std::numeric_limits<T>::max();
    ma = -mi;
    apply( l, MinMax(), op, mi, ma );
}

template<class TL,class Op,class T> void get_min_max(const TL &l,const Op &op,Vec<T,-1> &mi,Vec<T,-1> &ma) {
    mi.set( std::numeric_limits<T>::max() );
    ma.set( -std::numeric_limits<T>::max() );
    apply( l, MinMax(), op, mi, ma );
}

// ----------------------------------------------------------------- intersection -----------------------------------------------------------------
template<class TL1,class TL2=TL1> struct IntersectionCarac {
    static const unsigned nb_s1 = TL1::nb_sub_type;
    static const unsigned nb_s2 = TL2::nb_sub_type;
    struct PUET {
        template<unsigned n,unsigned inner=0> struct SubType {
            typedef typename AlternativeOnType<
                ( n >= nb_s1 * nb_s2 ),
                std::pair<typename TL1::template SubType<n%nb_s1>::T *,typename TL2::template SubType<n/nb_s1>::T *>,
                void
            >::T T;
        };
    };
    typedef typename AlternativeOnType<
        ( nb_s1==1 and nb_s2==1 ),
        Vec<Heterogeneous<PUET> >,
        Vec<std::pair<typename TL1::template SubType<0>::T *,typename TL2::template SubType<0>::T *> >
    >::T T;
};
template<class Op,bool full=false>
struct FillIntersectionPtr {
    template<class T1,class T2,class TR> bool operator()(T2 &t2,T1 &t1,TR &res,unsigned inner) const {
        if ( (*op)(t1,t2) ) {
            res.push_back( std::pair<T1 *,T2 *>( &t1, &t2 ) );
            return true;
        }
        return false; 
    }
    template<class T1,class TL2,class TR> void operator()(T1 &t1,TL2 &l2,TR &res) const {
        if ( full )
            apply( l2, *this, t1, res, 0 );
        else
            find( l2, *this, t1, res, 0 );
    }
    const Op *op;
};

template<class TL1,class TL2,class Op> typename IntersectionCarac<TL1,TL2>::T intersection_ptr(TL1 &l1,TL2 &l2,const Op &op) {
    typename IntersectionCarac<TL1,TL2>::T res;
    FillIntersectionPtr<Op> fi; fi.op = &op;
    apply( l1, fi, l2, res );
    return res;
}

template<class TL1,class TL2> typename IntersectionCarac<TL1,TL2>::T intersection_ptr(TL1 &l1,TL2 &l2) {
    return intersection_ptr(l1,l2,ExactlyEqual());
}


template<class TL1,class TL2,class Op> typename IntersectionCarac<TL1,TL2>::T intersection_ptr_full(TL1 &l1,TL2 &l2,const Op &op) {
    typename IntersectionCarac<TL1,TL2>::T res;
    FillIntersectionPtr<Op,true> fi; fi.op = &op;
    apply( l1, fi, l2, res );
    return res;
}

template<class TL1,class TL2> typename IntersectionCarac<TL1,TL2>::T intersection_ptr_full(TL1 &l1,TL2 &l2) {
    return intersection_ptr_full(l1,l2,ExactlyEqual());
}


// ---------------------------------------------------------------------------------------------------------------------------------------------------
namespace ALGOPRIVATE {
    template<class TResOp> struct GetResOp {
        template<class T,class TR,class Op> void operator()(const T &e,TR &res,const Op &op) { val = op(e); res = static_cast<TR>(e); }
        template<class T,class TR,class Op,class TP> void operator()(const T &e,TR &res,const Op &op,const TP &param) { val = op(e,param); res = static_cast<TR>(e); }
        TResOp val;
    };
    template<class TResOp> struct MaxElement {
        template<class T,class TR,class Op> void operator()(const T &e,TR &res,const Op &op) {
            TResOp nval = op(e);
            if ( nval > val ) {
                val = nval;
                res = static_cast<TR>(e);
            }
        }
        template<class T,class TR,class Op,class TP> void operator()(const T &e,TR &res,const Op &op,const TP &param) {
            TResOp nval = op(e,param);
            if ( nval > val ) {
                val = nval;
                res = static_cast<TR>(e);
            }
        }
        TResOp val;
    };
    template<class TResOp> struct MinElement {
        template<class T,class TR,class Op> void operator()(const T &e,TR &res,const Op &op) {
            TResOp nval = op(e);
            if ( nval < val ) {
                val = nval;
                res = static_cast<TR>(e);
            }
        }
        template<class T,class TR,class Op,class TP> void operator()(const T &e,TR &res,const Op &op,const TP &param) {
            TResOp nval = op(e,param);
            if ( nval < val ) {
                val = nval;
                res = static_cast<TR>(e);
            }
        }
        TResOp val;
    };
};
/*!
    return a copy on the first element e such as op(e) >= op(i) for all i in l. In other words, look up for first e which maximize op(e)
    This procedure may not be optimal for lists with little size
    \keyword Algorithme
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr 
*/
template<class TL,class Op> typename TypeReduction<Plus,TL>::T max_element(const TL &l,const Op &op) {
    typedef typename TypeReduction<Plus,TL>::T TR;
    typedef typename TypeReduction<Plus,Vec<VecOp<Op,1,TL,true> > >::T TResOp;
    ALGOPRIVATE::MaxElement<TResOp> me;
    ALGOPRIVATE::GetResOp<TResOp> meg;
    TR res;
    unsigned n = 1;
    apply_range( l, 0, n, meg, res, op);
    me.val = meg.val;
    apply( l, me, res, op );
    return res;
}
/*!
    return a copy on the first element e such as op(e,param) >= op(i,param) for all i in l. In other words, look up for first e which maximize op(e,param).
    This procedure may not be optimal for lists with little size
    \keyword Algorithme
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr 
*/
template<class TL,class Op,class TP> typename TypeReduction<Plus,TL>::T max_element(const TL &l,const Op &op,const TP &param) {
    typedef typename TypeReduction<Plus,TL>::T TR;
    typedef typename TypeReduction<Plus,Vec<VecOp<Op,2,TL,true,Vec<VecCst<TP> >,true> > >::T TResOp;
    ALGOPRIVATE::MaxElement<TResOp> me;
    ALGOPRIVATE::GetResOp<TResOp> meg;
    TR res;
    unsigned n = 1;
    apply_range(l, 0, n, meg, res, op, param);
    me.val = meg.val;
    apply(l, me, res, op, param );
    return res;
}
/*!
    return a copy on the first element e such as (e >= i) for all i in l. In other words, look up for first e which maximize op(e)
    \keyword Algorithme
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr 
*/
template<class TL> typename TypeReduction<Plus,TL>::T max_element(const TL &l) { return max_element(l,C_1()); }


/*!
    return a copy on the first element e such as op(e) >= op(i) for all i in l. In other words, look up for first e which maximize op(e)
    This procedure may not be optimal for lists with little size
    \keyword Algorithme
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr 
*/
template<class TL,class Op> typename TypeReduction<Plus,TL>::T min_element(const TL &l,const Op &op) {
    typedef typename TypeReduction<Plus,TL>::T TR;
    typedef typename TypeReduction<Plus,Vec<VecOp<Op,1,TL,true> > >::T TResOp;
    ALGOPRIVATE::MinElement<TResOp> me;
    ALGOPRIVATE::GetResOp<TResOp> meg;
    TR res;
    unsigned n = 1;
    apply_range( l, 0, n, meg, res, op);
    me.val = meg.val;
    apply( l, me, res, op );
    return res;
}
/*! 
    return a copy on the first element e such as op(e,param) >= op(i,param) for all i in l. In other words, look up for first e which minimize op(e,param).
    This procedure may not be optimal for lists with little size
    \keyword Algorithme
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr 
*/
template<class TL,class Op,class TP> typename TypeReduction<Plus,TL>::T min_element(const TL &l,const Op &op,const TP &param) {
    typedef typename TypeReduction<Plus,TL>::T TR;
    typedef typename TypeReduction<Plus,Vec<VecOp<Op,2,TL,true,Vec<VecCst<TP> >,true> > >::T TResOp;
    ALGOPRIVATE::MinElement<TResOp> me;
    ALGOPRIVATE::GetResOp<TResOp> meg;
    TR res;
    unsigned n = 1;
    apply_range(l, 0, n, meg, res, op, param);
    me.val = meg.val;
    apply(l, me, res, op, param );
    return res;
}
/*! 
    return a copy on the first element e such as (e >= i) for all i in l. In other words, look up for first e which minimize op(e)
    \keyword Algorithme
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr 
*/
template<class TL> typename TypeReduction<Plus,TL>::T min_element(const TL &l) { return min_element(l,C_1()); }

/*!

    Cette fonction prend en paramètre un vecteur de booléens to_check et retourne le vecteur contenant l' indice des éléments vrais.
    \relates apply
    \relates Vec

    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend raphael.pasquier@lmt.ens-cachan.fr 
 */
template<class VB> Vec<unsigned> find_with_index(const VB &to_check) {
    Vec<unsigned> res; res.reserve( to_check.size() );
    for(unsigned i=0;i<to_check.size();++i)
        if ( to_check[i] )
            res.push_back( i );
    return res;
}

};

#endif // LMT_algo_HEADER
