import string
from vecgenhelp import *

print """
namespace LMT {
template<class TV,class TR> struct Replace {};

template<class TV,class TR> struct IsVecOp<Replace<TV,TR> > { typedef int T; };

/// range
template<class TV,class TR,int static_size_>
class Vec<Replace<TV,TR>,static_size_,int> {
public:
    template<unsigned n> struct SubType { typedef typename TV::template SubType<n>::T T; };
    static const unsigned nb_sub_type = TV::nb_sub_type;
    typedef typename SubType<0>::T T0;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = TV::sparsity_rate;

    Vec(const TV &vv,const TR &o,const TR &n):v(vv),_old_(o),_new_(n) {}
    
    T0 operator[](unsigned i) const { if (v[i]!=_old_) return v[i];  return _new_; } /// access to element i
    
    unsigned size() const { return v.size(); }

"""+GETRANGE+"""

    const TV &v;
    TR _old_;
    TR _new_;
};

template<class TT,int s,class TR> Vec<Replace<Vec<TT,s>,TR>,s> replace(const Vec<TT,s> &v,const TR &_old_, const TR &_new_) {
    return Vec<Replace<Vec<TT,s>,TR>,s>( v, _old_, _new_ );
}

}
"""

# TT = ['class V0','class V1','bool const_v0']
# TV = 'Vec<VecSelect<V0,V1,const_v0>,s,int>'
# 
# print_apply_ext('apply',TT,TV,'typename '+TV+'::template FilterI<Op,ONEIFCONSTOP> i; i.op.val=&op; i.v1=&v.v1; i.i = 0; apply(*v.v0.val,i,PARALIST);')
# print_apply_ext('apply_wi',TT,TV,'OpWithIncrement<Op,ONEIFCONSTOP> opi(op); apply(v,opi,PARALIST);')
# 
# print '} // namespace LMT'
