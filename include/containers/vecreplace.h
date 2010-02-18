
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


    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,true >,s2> operator[](const Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,true>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2> operator[](const Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2> operator[](Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2> operator[](Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2>(*this,v2); }
    

    const TV &v;
    TR _old_;
    TR _new_;
};

template<class TT,int s,class TR> Vec<Replace<Vec<TT,s>,TR>,s> replace(const Vec<TT,s> &v,const TR &_old_, const TR &_new_) {
    return Vec<Replace<Vec<TT,s>,TR>,s>( v, _old_, _new_ );
}

}

