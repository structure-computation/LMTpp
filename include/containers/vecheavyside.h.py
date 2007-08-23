import string
from vecgenhelp import *

print """
namespace LMT {
template<class T=int> struct VecHeavyside {};

template<class TT> struct IsVecOp<VecHeavyside<TT> > { typedef int T; };

/// range
template<class TT,int static_size_>
class Vec<VecHeavyside<TT>,static_size_,int> {
public:
    template<unsigned n> struct SubType { typedef TT T; };
    static const unsigned nb_sub_type = 1;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 1;

    struct inc_index_access_const {
        inline const TT &operator[](unsigned i) const { return (i>=nn) * *val; }
        const TT *val;
        unsigned nn;
    };
    inc_index_access_const begin_inc_index_access_const() const { inc_index_access_const res; res.val=&val; res.nn=nn; return res; }
    
    Vec(const TT &cst_val,unsigned nnn,unsigned s=static_size_):val(cst_val),nn(nnn) { si.set(s); }
    
    TT operator[](unsigned i) const { return (i>=nn)*val; } /// access to element i
    TT get(unsigned i) const { return (i>=nn)*val; } ///
    unsigned size() const { return si.val; }
    void clear() { si.set(0); }

    template<class T2> Vec &operator*=(const T2 &v) { val *= v; return *this; }
    template<class T2> Vec &operator/=(const T2 &v) { val /= v; return *this; }
    template<class T2> Vec &operator%=(const T2 &v) { val %= v; return *this; }
    template<class T2> Vec &operator&=(const T2 &v) { val &= v; return *this; }

"""+GETRANGE+"""

    TT val;
    unsigned nn;
private:
    StaticValIf<unsigned,fixed_size,static_size_> si;
};

/** Create a constant vec of size $size \\relates Vec */
template<class T> Vec<VecHeavyside<T>,-1> heavyside_vec(const T &val,unsigned nn,unsigned size) { return Vec<VecHeavyside<T>,-1>(val,nn,size); }
/** Create a constant vec of size $s \\relates Vec */
template<int s,class T> Vec<VecHeavyside<T>,s> static_heavyside_vec(const T &val,unsigned nn) { return Vec<VecHeavyside<T>,s>(val,nn); }

"""

TT = ['class TT']
TV = 'Vec<VecHeavyside<TT>,s,int>'
print_apply_ext('apply'          ,TT,TV,'for(unsigned i=0;i<v.nn;op((TT)0,PARALIST),++i); for(unsigned i=v.nn;i<v.size();op(v.val,PARALIST),++i);',onlyforconstvec=True)

print_apply_ext('apply_nz'       ,TT,TV,'for(unsigned i=v.nn;i<v.size();op(v.val,PARALIST),++i);',onlyforconstvec=True)
print_apply_ext('apply_nz_unique',TT,TV,'op(v.val,PARALIST);')
print_apply_ext('apply_range'    ,TT,TV,'DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,PARALIST),++i); for(unsigned i=v.nn;i<to;op((TT)0,PARALIST), ++i);',suppar=['unsigned from','unsigned to'],onlyforconstvec=True)

print_apply_ext('apply_wi'       ,TT,TV,'for(unsigned i=0;i<v.nn;op(0,i,PARALIST),++i); for(unsigned i=v.nn;i<v.size();op((TT)0,i,PARALIST),++i);',onlyforconstvec=True)
print_apply_ext('apply_nz_wi'    ,TT,TV,'for(unsigned i=v.nn;i<v.size();op(v.val,i,PARALIST),++i);',onlyforconstvec=True)
print_apply_ext('apply_range_wi' ,TT,TV,'DEBUGASSERT(to<=v.size()); for(unsigned i=from;i<v.nn;op(0,i,PARALIST),++i); for(unsigned i=v.nn;i<to;op((TT)0,i,PARALIST), ++i);',suppar=['unsigned from','unsigned to'],onlyforconstvec=True)

print_apply_ext('find'           ,TT,TV,'return (v.nn>=1 && op((TT)0,PARALIST)) || op(v.val,PARALIST);',ret='bool',onlyforconstvec=True)

print '} // namespace LMT'
