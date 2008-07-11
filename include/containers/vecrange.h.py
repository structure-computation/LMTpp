import string
from vecgenhelp import *

print """
namespace LMT {
template<class T=int,int static_begin=-1,int static_step=-1> struct Range {};

template<class TT,int static_begin,int static_step> struct IsVecOp<Range<TT,static_begin,static_step> > { typedef int T; };

/// range
template<class TT,int static_begin,int static_step,int static_size_>
class Vec<Range<TT,static_begin,static_step>,static_size_,int> {
public:
    template<unsigned n> struct SubType { typedef TT T; };
    static const unsigned nb_sub_type = 1;
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 0;
    static const unsigned ne = SimdVec<TT>::nb_elem;

    Vec() { si.set( fixed_size * static_size_ ); }
    Vec(TT begin,TT step,TT end=static_begin+static_step*static_size_) { typedef typename FloatType<TT>::T TF; b.set(begin); s.set(step); si.set( unsigned( ceil((end-b.val)/TF(s.val)) ) ); }
    
    TT operator[](unsigned i) const { return b.val+s.val*i; } /// access to element i
    TT get(unsigned i) const { return b.val+s.val*i; } ///
    unsigned size() const { return si.val; }
    void clear() { si.set(0); }
    void resize(unsigned ns) { si.val = ns; }

"""+GETRANGE+"""

private:
    StaticValIf<unsigned,fixed_size,static_size_> si;
    StaticValIf<TT,static_begin>=0,static_begin> b;
    StaticValIf<TT,static_step>=0,static_step> s;
};

/** Create a [0:1:e] range \\relates Vec */
template<class TT> Vec<Range<TT,0,1> > range(const TT &e) { DEBUGASSERT( e>=0 ); return Vec<Range<TT,0,1> >(0,1,e); }
/** Create a [0:1:e] range \\relates Vec */
template<class TT,class T2> Vec<Range<TT,-1,1> > range(const TT &b,const T2 &e) { DEBUGASSERT( (TT)e>=b ); return Vec<Range<TT,-1,1> >(b,1,e); }
/** Create a [0:1:e] range \\relates Vec */
template<class TT> Vec<Range<TT> > range(const TT &b,const TT &step,const TT &e) { DEBUGASSERT( (step>0 xor b>e) or b==e ); return Vec<Range<TT> >(b,step,e); }


/** Create a [0:1:e] range with fised size \relates Vec */
template<int s,class TT> Vec<Range<TT>,s> static_range() { return Vec<Range<TT>,s>(0,1,s); }
/** Create a [0:1:e] range with fised size \relates Vec */
template<int s,class TT> Vec<Range<TT>,s> static_range(const TT &b) { return Vec<Range<TT>,s>(b,1,s); }
/** Create a [0:1:e] range with fised size \relates Vec */
template<int s,class TT> Vec<Range<TT>,s> static_range(const TT &b,const TT &step) { return Vec<Range<TT>,s>(b,step,s); }

}
"""
