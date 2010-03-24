#ifndef VEC_POINTED_VALUES
#define VEC_POINTED_VALUES

#include "containers/vec.h"

namespace LMT {

template<class T=int> struct VecPointedValues {};

template<class TT> struct IsVecOp<VecPointedValues<TT> > { typedef int T; };

/// Dirac vector
template<class TT,int static_size_>
class Vec<VecPointedValues<TT>,static_size_,int> {
public:
    template<unsigned n> struct SubType { typedef TT T; };
    static const unsigned nb_sub_type = 1;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 3;

    unsigned size() const { return data.size(); }
    void push_back(TT *val) { data.push_back(val); }
    
    const TT &operator[](unsigned i) const { return *data[i]; } /// access to element i
    TT &operator[](unsigned i) { return *data[i]; } /// access to element i
    
    Vec<TT *,static_size_> data;
};


}
#endif //VEC_POINTED_VALUES
