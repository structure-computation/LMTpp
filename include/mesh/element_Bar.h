#ifndef LMT_BAR
#define LMT_BAR
#include "node.h"
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Bar &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 3, 6, 11, 16, 23, 30, 39, 48, 59, }; // fonction de lordre du poly
    static const double values[] = {
        1.0,0.5,
        0.0,
        1.0,0.5,
        0.0,
        0.5,0.211324865405,
        0.5,0.788675134595,
        0.0,
        0.5,0.211324865405,
        0.5,0.788675134595,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
        0.326072577431,0.669990521792,
        0.326072577431,0.330009478208,
        0.173927422569,0.930568155797,
        0.173927422569,0.069431844203,
        0.0,
        0.326072577431,0.669990521792,
        0.326072577431,0.330009478208,
        0.173927422569,0.930568155797,
        0.173927422569,0.069431844203,
        0.0,
        0.568888888889,0.5,
        0.239314335249683234,0.76923465505284149997,
        0.239314335249683234,0.2307653449471585,
        0.1184634425280945,0.95308992296933200001,
        0.1184634425280945,0.046910077030667999989,
        0.0,
        0.568888888889,0.5,
        0.239314335249683234,0.76923465505284149997,
        0.239314335249683234,0.2307653449471585,
        0.1184634425280945,0.95308992296933200001,
        0.1184634425280945,0.046910077030667999989,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Bar &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T det_jac=nodes[1]->pos[0]-nodes[0]->pos[0];

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[1],nodes[0]};
        for(unsigned i=0;i<2;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Bar &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=pos_nodes[1][0]-pos_nodes[0][0]; T reg1=pos[0]-pos_nodes[0][0]; T reg2=1.0/reg0; reg2=reg1*reg2; var_inter[0]=reg2;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Bar &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=pos_nodes[0][0]*reg0; T reg2=pos_nodes[1][0]*var_inter[0]; T reg3=pos_nodes[1][0]-pos_nodes[0][0]; reg2=reg1+reg2;
    reg1=1.0/reg3; reg2=pos[0]-reg2; reg1=reg1*reg2; var_inter[0]+=reg1;

}
template<> struct ElemVarInterFromPosNonLinear<Bar> { static const bool res = 0; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=val[0]*reg0; T reg2=val[1]*var_inter[0]; res=reg1+reg2;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Bubble
#define STRUCT_Bubble
struct Bubble {};
#endif // STRUCT_Bubble
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Bubble &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=var_inter[0]*reg0; reg1=4*reg1; T reg2=1-reg1; T reg3=var_inter[0]*reg2;
    reg2=reg0*reg2; reg3=val[1]*reg3; reg2=val[0]*reg2; reg2=reg3+reg2; reg1=val[2]*reg1;
    res=reg2+reg1;

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Bar &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Bar &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    res[1]=var_inter[0]; T reg0=1-var_inter[0]; res[0]=reg0;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Bar> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Bar,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); T reg4=elem.pos(1)[2]-elem.pos(0)[2];
    T reg5=pow(reg4,2); reg3=reg2+reg3; reg5=reg3+reg5; reg5=pow(reg5,0.5); reg2=reg0/reg5;
    reg3=reg1/reg5; reg5=reg4/reg5; reg0=reg2*reg0; reg3=reg1*reg3; reg4=reg5*reg4;
    reg3=reg0+reg3; reg3=reg4+reg3; return reg3;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,1> barycenter( const Element<Bar,TN,Node<1,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,1> res;
    T reg0=elem.pos(1)[0]-elem.pos(0)[0]; T reg1=pow(reg0,2); T reg2=elem.pos(0)[0]*reg0; reg1=reg1/2; reg1=reg2+reg1;
    res[0]=reg1/reg0;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Bar,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=elem.pos(1)[1]-elem.pos(0)[1]; T reg1=elem.pos(1)[0]-elem.pos(0)[0]; T reg2=pow(reg0,2); T reg3=pow(reg1,2); reg2=reg3+reg2;
    reg2=pow(reg2,0.5); reg3=reg1/reg2; reg2=reg0/reg2; reg3=reg3*reg1; reg2=reg2*reg0;
    reg2=reg3+reg2; reg0=reg2*reg0; reg1=reg2*reg1; reg3=elem.pos(0)[1]*reg2; reg0=reg0/2;
    reg1=reg1/2; T reg4=reg2*elem.pos(0)[0]; reg1=reg4+reg1; reg3=reg0+reg3; res[1]=reg3/reg2;
    res[0]=reg1/reg2;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Bar,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=elem.pos(1)[1]-elem.pos(0)[1]; T reg1=elem.pos(1)[0]-elem.pos(0)[0]; T reg2=elem.pos(1)[2]-elem.pos(0)[2]; T reg3=pow(reg1,2); T reg4=pow(reg0,2);
    reg4=reg3+reg4; reg3=pow(reg2,2); reg3=reg4+reg3; reg3=pow(reg3,0.5); reg4=reg1/reg3;
    T reg5=reg0/reg3; reg3=reg2/reg3; reg4=reg4*reg1; reg5=reg5*reg0; reg5=reg4+reg5;
    reg3=reg2*reg3; reg3=reg5+reg3; reg2=reg2*reg3; reg0=reg3*reg0; reg1=reg3*reg1;
    reg4=reg3*elem.pos(0)[2]; reg2=reg2/2; reg0=reg0/2; reg5=reg3*elem.pos(0)[1]; reg1=reg1/2;
    T reg6=reg3*elem.pos(0)[0]; reg0=reg5+reg0; reg2=reg4+reg2; reg1=reg6+reg1; res[2]=reg2/reg3;
    res[0]=reg1/reg3; res[1]=reg0/reg3;

    return res;
}
}
#endif // LMT_BAR
