#ifndef LMT_NODALELEMENT
#define LMT_NODALELEMENT
#include "node.h"
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const NodalElement &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, }; // fonction de lordre du poly
    static const double values[] = {
        1.0,0,
        0.0,
        1.0,0,
        0.0,
        1.0,0,
        0.0,
        1.0,0,
        0.0,
        1.0,0,
        0.0,
        1.0,0,
        0.0,
        1.0,0,
        0.0,
        1.0,0,
        0.0,
        1.0,0,
        0.0,
        1.0,0,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const NodalElement &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T det_jac=1;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0]};
        for(unsigned i=0;i<1;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const NodalElement &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const NodalElement &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;

}
template<> struct ElemVarInterFromPosNonLinear<NodalElement> { static const bool res = 0; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const NodalElement &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const NodalElement &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const NodalElement &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const NodalElement &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const NodalElement &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const NodalElement &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const NodalElement &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const NodalElement &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Bubble
#define STRUCT_Bubble
struct Bubble {};
#endif // STRUCT_Bubble
template<class TVI,class TVAL,class T> void get_interp(const NodalElement &ne,const Bubble &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const NodalElement &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const NodalElement &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    res[0]=1;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<NodalElement> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<NodalElement,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    return 1;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,0> barycenter( const Element<NodalElement,TN,Node<0,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,0> res;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,1> barycenter( const Element<NodalElement,TN,Node<1,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,1> res;
    res[0]=elem.pos(0)[0];

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<NodalElement,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    res[0]=elem.pos(0)[0]; res[1]=elem.pos(0)[1];

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<NodalElement,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    res[2]=elem.pos(0)[2]; res[0]=elem.pos(0)[0]; res[1]=elem.pos(0)[1];

    return res;
}
}
#endif // LMT_NODALELEMENT
