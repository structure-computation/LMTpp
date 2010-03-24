//
// C++ Interface: opwithincrement
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_opwithincrement_HEADER
#define LMT_opwithincrement_HEADER

namespace LMT {

template<class Op,bool const_op=true>
struct OpWithIncrement {
    OpWithIncrement():i(0) {}
    OpWithIncrement(const Op &o):i(0) { op.val = &o; }
    OpWithIncrement(Op &o):i(0) { op.val = &o; }

    template<class T> void operator()(const T &val0) { (*op.val)( val0, i++ ); }
    template<class T> void operator()(      T &val0) { (*op.val)( val0, i++ ); }

    template<class T,class P0> void operator()(const T &val0,const P0 &p0) { (*op.val)( val0, i++, p0 ); }
    template<class T,class P0> void operator()(const T &val0,      P0 &p0) { (*op.val)( val0, i++, p0 ); }
    template<class T,class P0> void operator()(      T &val0,const P0 &p0) { (*op.val)( val0, i++, p0 ); }
    template<class T,class P0> void operator()(      T &val0,      P0 &p0) { (*op.val)( val0, i++, p0 ); }

    template<class T,class P0,class P1> void operator()(const T &val0,const P0 &p0,const P1 &p1) { (*op.val)( val0, i++, p0, p1 ); }
    template<class T,class P0,class P1> void operator()(const T &val0,const P0 &p0,      P1 &p1) { (*op.val)( val0, i++, p0, p1 ); }
    template<class T,class P0,class P1> void operator()(const T &val0,      P0 &p0,const P1 &p1) { (*op.val)( val0, i++, p0, p1 ); }
    template<class T,class P0,class P1> void operator()(const T &val0,      P0 &p0,      P1 &p1) { (*op.val)( val0, i++, p0, p1 ); }
    template<class T,class P0,class P1> void operator()(      T &val0,const P0 &p0,const P1 &p1) { (*op.val)( val0, i++, p0, p1 ); }
    template<class T,class P0,class P1> void operator()(      T &val0,const P0 &p0,      P1 &p1) { (*op.val)( val0, i++, p0, p1 ); }
    template<class T,class P0,class P1> void operator()(      T &val0,      P0 &p0,const P1 &p1) { (*op.val)( val0, i++, p0, p1 ); }
    template<class T,class P0,class P1> void operator()(      T &val0,      P0 &p0,      P1 &p1) { (*op.val)( val0, i++, p0, p1 ); }

    template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,const P1 &p1,const P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,const P1 &p1,      P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,      P1 &p1,const P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(const T &val0,const P0 &p0,      P1 &p1,      P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,const P1 &p1,const P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,const P1 &p1,      P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,      P1 &p1,const P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(const T &val0,      P0 &p0,      P1 &p1,      P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,const P1 &p1,const P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,const P1 &p1,      P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,      P1 &p1,const P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(      T &val0,const P0 &p0,      P1 &p1,      P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,const P1 &p1,const P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,const P1 &p1,      P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,      P1 &p1,const P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }
    template<class T,class P0,class P1,class P2> void operator()(      T &val0,      P0 &p0,      P1 &p1,      P2 &p2) { (*op.val)( val0, i++, p0, p1, p2 ); }

    PtrConstIf<Op,const_op> op;
    unsigned i;
};

};

#endif // LMT_opwithincrement_HEADER
