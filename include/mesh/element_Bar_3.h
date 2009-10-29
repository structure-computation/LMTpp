#ifndef LMT_BAR_3
#define LMT_BAR_3
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Bar_3 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 5, 10, 15, 20, 27, 34, 41, 48, 55, }; // fonction de lordre du poly
    static const double values[] = {
        0.5,0.211324865405,
        0.5,0.788675134595,
        0.0,
        0.5,0.211324865405,
        0.5,0.788675134595,
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
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Bar_3 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T det_jac=nodes[1]->pos[0]-nodes[0]->pos[0];

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[1],nodes[0],nodes[2]};
        for(unsigned i=0;i<3;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Bar_3 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=var_inter[0]-0.5; T reg1=0.5-var_inter[0]; T reg2=1-var_inter[0]; T reg3=2*var_inter[0]; T reg4=2*reg0;
    T reg5=2*reg1; T reg6=2*reg2; reg1=reg6*reg1; T reg7=4*reg2; reg0=reg3*reg0;
    reg3=reg4+reg3; reg6=reg5+reg6; reg4=4*var_inter[0]; reg5=pos_nodes[0][0]*reg6; T reg8=reg3*pos_nodes[1][0];
    reg4=reg7-reg4; reg7=var_inter[0]*reg7; T reg9=pos_nodes[1][0]*reg0; T reg10=pos_nodes[0][0]*reg1; T reg11=pos_nodes[2][0]*reg7;
    reg10=reg9+reg10; reg9=pos_nodes[2][0]*reg4; reg5=reg8-reg5; reg11=reg10+reg11; reg9=reg5+reg9;
    reg11=pos[0]-reg11; reg5=1.0/reg9; reg5=reg11*reg5; var_inter[0]=reg5;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Bar_3 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.5-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=1-var_inter[0]; T reg3=2*reg2; T reg4=2*var_inter[0];
    T reg5=2*reg0; T reg6=2*reg1; T reg7=4*reg2; reg5=reg5+reg3; reg6=reg6+reg4;
    T reg8=4*var_inter[0]; reg1=reg4*reg1; reg0=reg3*reg0; reg3=var_inter[0]*reg7; reg8=reg7-reg8;
    reg4=pos_nodes[1][0]*reg6; reg7=pos_nodes[0][0]*reg5; T reg9=pos_nodes[0][0]*reg0; T reg10=pos_nodes[1][0]*reg1; T reg11=pos_nodes[2][0]*reg8;
    reg7=reg4-reg7; reg4=pos_nodes[2][0]*reg3; reg10=reg9+reg10; reg11=reg7+reg11; reg4=reg10+reg4;
    reg7=1.0/reg11; reg4=pos[0]-reg4; reg7=reg4*reg7; var_inter[0]+=reg7;

}
template<> struct ElemVarInterFromPosNonLinear<Bar_3> { static const bool res = 1; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal_2
#define STRUCT_Nodal_2
struct Nodal_2 {};
#endif // STRUCT_Nodal_2
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Nodal_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=val[0]*reg0; T reg2=val[1]*var_inter[0]; res=reg1+reg2;

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=2*reg0; T reg3=var_inter[0]-0.5; T reg4=2*var_inter[0];
    reg1=reg2*reg1; reg3=reg4*reg3; reg2=4*reg0; reg1=val[0]*reg1; reg3=val[1]*reg3;
    reg2=var_inter[0]*reg2; reg3=reg1+reg3; reg2=val[2]*reg2; res=reg3+reg2;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Bar_3 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=2*var_inter[0]; T reg2=var_inter[0]-0.5; T reg3=2*reg0; T reg4=0.5-var_inter[0];
    T reg5=4*reg0; reg4=reg3*reg4; res[0]=reg4; reg2=reg1*reg2; res[1]=reg2;
    reg5=var_inter[0]*reg5; res[2]=reg5;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Bar_3> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

}
#endif // LMT_BAR_3
