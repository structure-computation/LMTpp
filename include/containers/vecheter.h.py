import string
from vecgenhelp import *

print """
namespace LMT {
template<class Carac,unsigned nt=0,class T=typename Carac::template SubType<nt>::T> struct Heterogeneous {};

template<class Carac,unsigned nt,class TT> struct IsVecOp<Heterogeneous<Carac,nt,TT> > { typedef int T; };

/// heterogeneous vector. static_size is the number of elements
template<class Carac,unsigned nt,class TT,int static_size_>
class Vec<Heterogeneous<Carac,nt,TT>,static_size_,int> {
public:
    typedef Vec<TT,static_size_> TV;
    typedef Vec<Heterogeneous<Carac,nt+1>,static_size_,int> TNext;
    typedef typename Vec<TT,static_size_>::template SubType<0>::T T;
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = TV::sparsity_rate;
    template<unsigned n> struct SubVec { typedef Vec<typename Carac::template SubType<n>::T,static_size_> TS; };

    template<unsigned n> struct SubType { typedef typename Vec<typename Carac::template SubType<n>::T>::template SubType<0>::T T; };
    //template<unsigned n> struct SubType { typedef typename Carac::template SubType<n>::T T; };
    static const unsigned nb_sub_type = TNext::nb_sub_type;
    
    void push_back(const T &val) { vec.push_back(val); } ///
    template<class TO> void push_back(const TO &val) { next.push_back(val); } ///
    
    T operator[](unsigned i) const { DEBUGASSERTWC(nb_sub_type==1,operator is available only if nb_sub_type==1); return vec[i]; }
    T &operator[](unsigned i) { DEBUGASSERTWC(nb_sub_type==1,operator is available only if nb_sub_type==1); return vec[i]; }
    
    void *get_ptr(unsigned num) { if ( num<vec.size() ) return reinterpret_cast<void *>(&vec[num]); return next.get_ptr(num-vec.size()); }
    const void *get_ptr(unsigned num) const { if ( num<vec.size() ) return reinterpret_cast<const void *>(&vec[num]); return next.get_ptr(num-vec.size()); }
    
    T *new_elem(const StructForType<T> st) { return vec.new_elem(); } ///
    template<class TO> TO *new_elem(const StructForType<TO> st) { return next.new_elem(st); } ///

    void free() { vec.free(); next.free(); }
    
    void resize(const unsigned *s) { vec.resize(s[nt]); next.resize(s); }
    
    unsigned size() const { return vec.size() + next.size(); } /// total number of elements
    template<unsigned n> unsigned size(const Number<n> &nn) const { return next.size(nn); }
    unsigned size(const Number<nt> &nn) const { return vec.size(); }
    void get_sizes(unsigned *s) const { s[nt] = vec.size(); next.get_sizes(s); }

    template<unsigned n> typename SubVec<n>::TS &sub_vec(const Number<n> &nn) { return next.sub_vec(nn); } ///
    template<unsigned n> const typename SubVec<n>::TS &sub_vec(const Number<n> &nn) const { return next.sub_vec(nn); } ///

    const TV &sub_vec(const Number<nt> &nn) const { return vec; } ///
    TV &sub_vec(const Number<nt> &nn) { return vec; } ///

    template<unsigned n> typename SubType<n>::T &data(unsigned i,const Number<n> &nn=Number<n>()) { return next.data(i,nn); } ///
    template<unsigned n> const typename SubType<n>::T &data(unsigned i,const Number<n> &nn=Number<n>()) const { return next.data(i,nn); } ///
    
    T &data(unsigned i,const Number<nt> &nn=Number<nt>()) { return vec[i]; } ///
    const T &data(unsigned i,const Number<nt> &nn=Number<nt>()) const { return vec[i]; } ///
    
    template<class EA> unsigned index_of_down_cast(const EA *ea) const { if (typeid(*ea)==typeid(T)) return nt; return next.index_of_down_cast(ea); } /// return index of type of EA which can be an ancestor of an element in the list
    
    void remove_nb(unsigned num_list,unsigned num_in_sub_list) { if ( num_list==nt ) vec.erase_elem_nb(num_in_sub_list); else next.remove_nb(num_list,num_in_sub_list); } /// remove num_in_sub_list^th element in num_list^th list


    template<class EA,class Op> static void apply_on_down_cast(const EA *ea,const Op& op) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op); else op(static_cast<const T&>(*ea)); }
    template<class EA,class Op> static void apply_on_down_cast(EA *ea,const Op& op) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op); else op(static_cast<T&>(*ea)); }
    template<class EA,class Op> static void apply_on_down_cast(const EA *ea,Op& op) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op); else op(static_cast<const T&>(*ea)); }
    template<class EA,class Op> static void apply_on_down_cast(EA *ea,Op& op) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op); else op(static_cast<T&>(*ea)); }
    template<class EA,class Op,class TP0> static void apply_on_down_cast(const EA *ea,const Op& op,const TP0 &p0) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0); else op(static_cast<const T&>(*ea),p0); }
    template<class EA,class Op,class TP0> static void apply_on_down_cast(EA *ea,const Op& op,const TP0 &p0) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0); else op(static_cast<T&>(*ea),p0); }
    template<class EA,class Op,class TP0> static void apply_on_down_cast(const EA *ea,Op& op,const TP0 &p0) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0); else op(static_cast<const T&>(*ea),p0); }
    template<class EA,class Op,class TP0> static void apply_on_down_cast(EA *ea,Op& op,const TP0 &p0) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0); else op(static_cast<T&>(*ea),p0); }
    template<class EA,class Op,class TP0> static void apply_on_down_cast(const EA *ea,const Op& op,TP0 &p0) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0); else op(static_cast<const T&>(*ea),p0); }
    template<class EA,class Op,class TP0> static void apply_on_down_cast(EA *ea,const Op& op,TP0 &p0) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0); else op(static_cast<T&>(*ea),p0); }
    template<class EA,class Op,class TP0> static void apply_on_down_cast(const EA *ea,Op& op,TP0 &p0) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0); else op(static_cast<const T&>(*ea),p0); }
    template<class EA,class Op,class TP0> static void apply_on_down_cast(EA *ea,Op& op,TP0 &p0) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0); else op(static_cast<T&>(*ea),p0); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(const EA *ea,const Op& op,const TP0 &p0,const TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<const T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(EA *ea,const Op& op,const TP0 &p0,const TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(const EA *ea,Op& op,const TP0 &p0,const TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<const T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(EA *ea,Op& op,const TP0 &p0,const TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(const EA *ea,const Op& op,TP0 &p0,const TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<const T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(EA *ea,const Op& op,TP0 &p0,const TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(const EA *ea,Op& op,TP0 &p0,const TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<const T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(EA *ea,Op& op,TP0 &p0,const TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(const EA *ea,const Op& op,const TP0 &p0,TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<const T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(EA *ea,const Op& op,const TP0 &p0,TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(const EA *ea,Op& op,const TP0 &p0,TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<const T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(EA *ea,Op& op,const TP0 &p0,TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(const EA *ea,const Op& op,TP0 &p0,TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<const T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(EA *ea,const Op& op,TP0 &p0,TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(const EA *ea,Op& op,TP0 &p0,TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<const T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(EA *ea,Op& op,TP0 &p0,TP1 &p1) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1); else op(static_cast<T&>(*ea),p0,p1); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<const T&>(*ea),p0,p1,p2); }
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(EA *ea,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { if (typeid(*ea)!=typeid(T)) TNext::apply_on_down_cast(ea,op,p0,p1,p2); else op(static_cast<T&>(*ea),p0,p1,p2); }


    template<class Op> static void apply_static(const Op& op) { op(StructForType<T>()); TNext::apply_static(op); }
    template<class Op> static void apply_static(Op& op) { op(StructForType<T>()); TNext::apply_static(op); }
    template<class Op,class TP0> static void apply_static(const Op& op,const TP0 &p0) { op(StructForType<T>(),p0); TNext::apply_static(op,p0); }
    template<class Op,class TP0> static void apply_static(Op& op,const TP0 &p0) { op(StructForType<T>(),p0); TNext::apply_static(op,p0); }
    template<class Op,class TP0> static void apply_static(const Op& op,TP0 &p0) { op(StructForType<T>(),p0); TNext::apply_static(op,p0); }
    template<class Op,class TP0> static void apply_static(Op& op,TP0 &p0) { op(StructForType<T>(),p0); TNext::apply_static(op,p0); }
    template<class Op,class TP0,class TP1> static void apply_static(const Op& op,const TP0 &p0,const TP1 &p1) { op(StructForType<T>(),p0,p1); TNext::apply_static(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static(Op& op,const TP0 &p0,const TP1 &p1) { op(StructForType<T>(),p0,p1); TNext::apply_static(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static(const Op& op,TP0 &p0,const TP1 &p1) { op(StructForType<T>(),p0,p1); TNext::apply_static(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static(Op& op,TP0 &p0,const TP1 &p1) { op(StructForType<T>(),p0,p1); TNext::apply_static(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static(const Op& op,const TP0 &p0,TP1 &p1) { op(StructForType<T>(),p0,p1); TNext::apply_static(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static(Op& op,const TP0 &p0,TP1 &p1) { op(StructForType<T>(),p0,p1); TNext::apply_static(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static(const Op& op,TP0 &p0,TP1 &p1) { op(StructForType<T>(),p0,p1); TNext::apply_static(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static(Op& op,TP0 &p0,TP1 &p1) { op(StructForType<T>(),p0,p1); TNext::apply_static(op,p0,p1); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { op(StructForType<T>(),p0,p1,p2); TNext::apply_static(op,p0,p1,p2); }

    template<class Op> static void apply_static_with_n(const Op& op) { op(StructForType<T>(),Number<nt>()); TNext::apply_static_with_n(op); }
    template<class Op> static void apply_static_with_n(Op& op) { op(StructForType<T>(),Number<nt>()); TNext::apply_static_with_n(op); }
    template<class Op,class TP0> static void apply_static_with_n(const Op& op,const TP0 &p0) { op(StructForType<T>(),Number<nt>(),p0); TNext::apply_static_with_n(op,p0); }
    template<class Op,class TP0> static void apply_static_with_n(Op& op,const TP0 &p0) { op(StructForType<T>(),Number<nt>(),p0); TNext::apply_static_with_n(op,p0); }
    template<class Op,class TP0> static void apply_static_with_n(const Op& op,TP0 &p0) { op(StructForType<T>(),Number<nt>(),p0); TNext::apply_static_with_n(op,p0); }
    template<class Op,class TP0> static void apply_static_with_n(Op& op,TP0 &p0) { op(StructForType<T>(),Number<nt>(),p0); TNext::apply_static_with_n(op,p0); }
    template<class Op,class TP0,class TP1> static void apply_static_with_n(const Op& op,const TP0 &p0,const TP1 &p1) { op(StructForType<T>(),Number<nt>(),p0,p1); TNext::apply_static_with_n(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static_with_n(Op& op,const TP0 &p0,const TP1 &p1) { op(StructForType<T>(),Number<nt>(),p0,p1); TNext::apply_static_with_n(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static_with_n(const Op& op,TP0 &p0,const TP1 &p1) { op(StructForType<T>(),Number<nt>(),p0,p1); TNext::apply_static_with_n(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static_with_n(Op& op,TP0 &p0,const TP1 &p1) { op(StructForType<T>(),Number<nt>(),p0,p1); TNext::apply_static_with_n(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static_with_n(const Op& op,const TP0 &p0,TP1 &p1) { op(StructForType<T>(),Number<nt>(),p0,p1); TNext::apply_static_with_n(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static_with_n(Op& op,const TP0 &p0,TP1 &p1) { op(StructForType<T>(),Number<nt>(),p0,p1); TNext::apply_static_with_n(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static_with_n(const Op& op,TP0 &p0,TP1 &p1) { op(StructForType<T>(),Number<nt>(),p0,p1); TNext::apply_static_with_n(op,p0,p1); }
    template<class Op,class TP0,class TP1> static void apply_static_with_n(Op& op,TP0 &p0,TP1 &p1) { op(StructForType<T>(),Number<nt>(),p0,p1); TNext::apply_static_with_n(op,p0,p1); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { op(StructForType<T>(),Number<nt>(),p0,p1,p2); TNext::apply_static_with_n(op,p0,p1,p2); }

    TV vec;
    TNext next;
};

template<class Carac,unsigned nt,int static_size_>
class Vec<Heterogeneous<Carac,nt,void>,static_size_,int> {
public:
    typedef void T;
    static const int static_size = 0;
    static const bool fixed_size = true;
    static const int sparsity_rate = 1000000;
    static const unsigned nb_sub_type = nt;

    void *get_ptr(unsigned num) { return NULL; }
    const void *get_ptr(unsigned num) const { return NULL; }
    
    unsigned size() const { return 0; } /// total number of elements
    template<unsigned n> unsigned size(const Number<n> &nn) const { return 0; }
    void get_sizes(unsigned *s) const {}
    
    void free() const {}
    void resize(const unsigned *s) const {}
    
    template<class TO> void push_back(const TO &val) { DEBUGASSERTWC(0,type TO is not a registered subtype); } ///
    template<class TO> TO *new_elem(const StructForType<TO> st=StructForType<TO>()) { DEBUGASSERTWC(0,type TO is not a registered subtype); } ///
    
    void remove_nb(unsigned num_list,unsigned num_in_sub_list) const { DEBUGASSERTWC(0,num_list is greater than number of sub list); } ///
    
    template<class EA> unsigned index_of_down_cast(const EA *ea) const { return nt; }
    
    template<class Op> static void apply_static(const Op& op) {}
    template<class Op,class TP0> static void apply_static(const Op& op,const TP0 &p0) {}
    template<class Op,class TP0,class TP1> static void apply_static(const Op& op,const TP0 &p0,const TP1 &p1) {}
    template<class Op,class TP0,class TP1,class TP2> static void apply_static(const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {}
    
    template<class Op> static void apply_static_with_n(const Op& op) {}
    template<class Op,class TP0> static void apply_static_with_n(const Op& op,const TP0 &p0) {}
    template<class Op,class TP0,class TP1> static void apply_static_with_n(const Op& op,const TP0 &p0,const TP1 &p1) {}
    template<class Op,class TP0,class TP1,class TP2> static void apply_static_with_n(const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {}
    
    template<class EA,class Op> static void apply_on_down_cast(const EA *ea,const Op& op) {}
    template<class EA,class Op,class TP0> static void apply_on_down_cast(const EA *ea,const Op& op,const TP0 &p0) {}
    template<class EA,class Op,class TP0,class TP1> static void apply_on_down_cast(const EA *ea,const Op& op,const TP0 &p0,const TP1 &p1) {}
    template<class EA,class Op,class TP0,class TP1,class TP2> static void apply_on_down_cast(const EA *ea,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {}
};
"""

TP = ['class Carac','unsigned nt','class TT']
TV = 'Vec<Heterogeneous<Carac,nt,TT>,s,int>'
# with data
print_apply_ext('apply',TP,TV,'apply(v.vec,op,PARALIST); apply(v.next,op,PARALIST);')
# beware : i will be number in sub_vec
print_apply_ext('apply_wi',TP,TV,'apply_wi(v.vec,op,PARALIST); apply_wi(v.next,op,PARALIST);')
print_apply_ext('find' ,TP,TV,'if (find(v.vec,op,PARALIST)) return true; return find(v.next,op,PARALIST);',ret='bool')
print_apply_ext(
    'apply_range',TP,TV,
    'apply_range(v.vec,from,min(to,v.vec.size()),op,PARALIST); from -= min(from,v.size()); to -= min(to,v.size()); apply_range(v.next,from,to,op,PARALIST);',
    suppar=['unsigned from','unsigned to']
)

print_apply_ext('apply_ptr',TP,TV,'apply_ptr(v.vec,op,PARALIST); apply_ptr(v.next,op,PARALIST);')
print_apply_ext('find_ptr' ,TP,TV,'if (find_ptr(v.vec,op,PARALIST)) return true; return find_ptr(v.next,op,PARALIST);',ret='bool')
print_apply_ext(
    'apply_range_ptr',TP,TV,
    'apply_range_ptr(v.vec,from,min(to,v.vec.size()),op,PARALIST); from -= min(from,v.size()); to -= min(to,v.size()); apply_range_ptr(v.next,from,to,op,PARALIST);',
    suppar=['unsigned from','unsigned to']
)
print_apply_ext('remove_if' ,TP,TV,'remove_if(v.vec,op,PARALIST); remove_if(v.next,op,PARALIST);',onlyfornonconstvec=True)

# without data
TP = ['class Carac','unsigned nt']
TV = 'Vec<Heterogeneous<Carac,nt,void>,s,int>'
print_apply_ext('apply',TP,TV,'')
print_apply_ext('apply_wi',TP,TV,'')
print_apply_ext('find' ,TP,TV,'return false;',ret='bool')
print_apply_ext('apply_range',TP,TV,'',suppar=['unsigned from','unsigned to'])
print_apply_ext('remove_if' ,TP,TV,'',onlyfornonconstvec=True)

print '} // namespace LMT'


