#ifndef vec_if_static_size_is_one_and_scalar_if_not_HEADER
#define vec_if_static_size_is_one_and_scalar_if_not_HEADER

namespace LMT {

template<class TT, int nx> struct VecIfStaticSizeIsOneAndScalarIfNot { typedef Vec<TT,nx> T; };
template<class TT> struct VecIfStaticSizeIsOneAndScalarIfNot<TT,1> { typedef TT T; };

};

#endif // vec_if_static_size_is_one_and_scalar_if_not_HEADER
