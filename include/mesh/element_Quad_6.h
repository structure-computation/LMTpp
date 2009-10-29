#ifndef LMT_QUAD_6
#define LMT_QUAD_6
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_6 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 13, 26, 39, 52, 65, 78, 91, 104, 117, }; // fonction de lordre du poly
    static const double values[] = {
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Quad_6 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=0.5*nodes[1]->pos[1]; T reg1=0.5*nodes[0]->pos[1]; T reg2=0.5*nodes[0]->pos[0]; T reg3=0.5*nodes[1]->pos[0]; T reg4=0.5*nodes[3]->pos[1];
    reg0=reg0-reg1; T reg5=0.5*nodes[3]->pos[0]; reg3=reg3-reg2; T reg6=0.5*nodes[2]->pos[1]; reg4=reg0-reg4;
    reg0=0.5*nodes[2]->pos[0]; reg5=reg3-reg5; reg3=nodes[5]->pos[1]-nodes[4]->pos[1]; reg0=reg5+reg0; reg6=reg4+reg6;
    reg4=nodes[5]->pos[0]-nodes[4]->pos[0]; reg3=reg0*reg3; reg4=reg6*reg4; T det_jac=reg3-reg4;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[3],nodes[2],nodes[1],nodes[0],nodes[5],nodes[4]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=reg1+reg0; T reg3=reg0-var_inter[0]; T reg4=var_inter[0]-0.5;
    reg3=4*reg3; T reg5=2*reg2; reg1=reg1*reg0; T reg6=reg4+var_inter[0]; reg0=reg0*var_inter[0];
    T reg7=1-var_inter[1]; reg0=4*reg0; reg6=2*reg6; T reg8=reg7*reg5; T reg9=reg7*reg3;
    reg1=2*reg1; reg4=reg4*var_inter[0]; T reg10=pos_nodes[4][1]*reg9; T reg11=reg0*pos_nodes[4][0]; T reg12=pos_nodes[0][1]*reg8;
    T reg13=pos_nodes[0][0]*reg1; T reg14=reg7*reg6; T reg15=pos_nodes[4][0]*reg9; T reg16=pos_nodes[0][0]*reg8; reg4=2*reg4;
    T reg17=reg0*pos_nodes[4][1]; T reg18=pos_nodes[0][1]*reg1; T reg19=reg7*reg1; reg13=reg11+reg13; reg11=pos_nodes[1][0]*reg4;
    T reg20=pos_nodes[1][0]*reg14; reg16=reg15-reg16; reg15=reg0*reg7; reg12=reg10-reg12; reg10=pos_nodes[1][1]*reg14;
    T reg21=var_inter[1]*reg5; T reg22=reg4*pos_nodes[1][1]; reg18=reg17+reg18; reg22=reg18+reg22; reg17=reg15*pos_nodes[4][1];
    reg18=pos_nodes[0][1]*reg19; T reg23=pos_nodes[0][0]*reg19; T reg24=reg15*pos_nodes[4][0]; reg11=reg13+reg11; reg13=reg1*pos_nodes[3][1];
    reg10=reg12+reg10; reg12=pos_nodes[3][1]*reg21; T reg25=reg1*pos_nodes[3][0]; reg7=reg4*reg7; T reg26=pos_nodes[3][0]*reg21;
    reg3=var_inter[1]*reg3; reg20=reg16+reg20; reg16=pos_nodes[1][1]*reg7; reg18=reg17+reg18; reg6=var_inter[1]*reg6;
    reg12=reg10-reg12; reg10=pos_nodes[5][1]*reg3; reg17=reg0*pos_nodes[5][1]; T reg27=var_inter[1]*reg1; reg22=reg13-reg22;
    reg11=reg25-reg11; reg13=pos_nodes[1][0]*reg7; reg23=reg24+reg23; reg26=reg20-reg26; reg20=pos_nodes[5][0]*reg3;
    reg24=reg0*pos_nodes[5][0]; reg25=pos_nodes[2][0]*reg6; reg20=reg26+reg20; reg26=var_inter[1]*reg0; reg24=reg11+reg24;
    reg17=reg22+reg17; reg11=pos_nodes[2][1]*reg6; reg10=reg12+reg10; reg12=reg4*pos_nodes[2][0]; reg22=reg4*pos_nodes[2][1];
    reg13=reg23+reg13; reg23=reg27*pos_nodes[3][0]; T reg28=reg27*pos_nodes[3][1]; reg16=reg18+reg16; reg28=reg16+reg28;
    reg22=reg17+reg22; reg16=reg26*pos_nodes[5][1]; reg17=var_inter[1]*reg4; reg11=reg10+reg11; reg10=reg26*pos_nodes[5][0];
    reg23=reg13+reg23; reg12=reg24+reg12; reg25=reg20+reg25; reg13=reg12*reg11; reg18=reg25*reg22;
    reg20=pos_nodes[2][0]*reg17; reg10=reg23+reg10; reg16=reg28+reg16; reg23=pos_nodes[2][1]*reg17; reg13=reg18-reg13;
    reg23=reg16+reg23; reg20=reg10+reg20; reg23=pos[1]-reg23; reg20=pos[0]-reg20; reg10=reg22/reg13;
    reg16=reg11/reg13; reg24=reg12/reg13; reg13=reg25/reg13; reg10=reg20*reg10; reg24=reg23*reg24;
    reg16=reg20*reg16; reg13=reg23*reg13; var_inter[0]=reg10-reg24; var_inter[1]=reg13-reg16;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.5-var_inter[0]; T reg1=1-var_inter[0]; T reg2=var_inter[0]-0.5; T reg3=reg1-var_inter[0]; T reg4=reg1+reg0;
    T reg5=2*reg4; T reg6=reg2+var_inter[0]; reg3=4*reg3; reg0=reg1*reg0; T reg7=1-var_inter[1];
    reg1=reg1*var_inter[0]; T reg8=reg7*reg3; T reg9=reg7*reg5; reg6=2*reg6; reg2=reg2*var_inter[0];
    reg1=4*reg1; reg0=2*reg0; T reg10=pos_nodes[4][0]*reg8; T reg11=reg7*reg6; T reg12=pos_nodes[0][1]*reg0;
    T reg13=reg1*pos_nodes[4][1]; T reg14=pos_nodes[0][0]*reg9; T reg15=reg1*pos_nodes[4][0]; T reg16=pos_nodes[0][0]*reg0; T reg17=pos_nodes[0][1]*reg9;
    T reg18=pos_nodes[4][1]*reg8; reg2=2*reg2; T reg19=pos_nodes[1][0]*reg11; reg14=reg10-reg14; reg17=reg18-reg17;
    reg10=pos_nodes[1][1]*reg11; reg16=reg15+reg16; reg15=pos_nodes[1][0]*reg2; reg12=reg13+reg12; reg13=pos_nodes[1][1]*reg2;
    reg18=var_inter[1]*reg5; T reg20=reg1*reg7; T reg21=reg0*reg7; T reg22=pos_nodes[0][1]*reg21; reg13=reg12+reg13;
    reg12=pos_nodes[3][1]*reg0; T reg23=pos_nodes[3][1]*reg18; reg10=reg17+reg10; reg17=pos_nodes[0][0]*reg21; T reg24=reg20*pos_nodes[4][0];
    reg15=reg16+reg15; reg7=reg2*reg7; reg16=reg20*pos_nodes[4][1]; T reg25=pos_nodes[3][0]*reg0; reg19=reg14+reg19;
    reg14=pos_nodes[3][0]*reg18; reg3=var_inter[1]*reg3; T reg26=pos_nodes[5][1]*reg3; reg23=reg10-reg23; reg14=reg19-reg14;
    reg10=var_inter[1]*reg0; reg6=var_inter[1]*reg6; reg13=reg12-reg13; reg12=reg1*pos_nodes[5][1]; reg19=pos_nodes[1][0]*reg7;
    reg17=reg24+reg17; reg24=pos_nodes[5][0]*reg3; reg22=reg16+reg22; reg16=pos_nodes[1][1]*reg7; T reg27=reg1*pos_nodes[5][0];
    reg15=reg25-reg15; reg12=reg13+reg12; reg13=var_inter[1]*reg1; reg25=pos_nodes[2][1]*reg6; T reg28=pos_nodes[2][1]*reg2;
    reg26=reg23+reg26; reg16=reg22+reg16; reg22=pos_nodes[3][1]*reg10; reg23=pos_nodes[2][0]*reg6; reg27=reg15+reg27;
    reg15=pos_nodes[2][0]*reg2; reg24=reg14+reg24; reg19=reg17+reg19; reg14=pos_nodes[3][0]*reg10; reg17=reg13*pos_nodes[5][1];
    reg22=reg16+reg22; reg23=reg24+reg23; reg15=reg27+reg15; reg28=reg12+reg28; reg12=var_inter[1]*reg2;
    reg25=reg26+reg25; reg16=reg13*pos_nodes[5][0]; reg14=reg19+reg14; reg16=reg14+reg16; reg14=reg12*pos_nodes[2][0];
    reg17=reg22+reg17; reg19=reg12*pos_nodes[2][1]; reg22=reg23*reg28; reg24=reg15*reg25; reg14=reg16+reg14;
    reg19=reg17+reg19; reg24=reg22-reg24; reg16=reg23/reg24; reg17=reg15/reg24; reg26=reg25/reg24;
    reg24=reg28/reg24; reg19=pos[1]-reg19; reg14=pos[0]-reg14; reg24=reg14*reg24; reg17=reg19*reg17;
    reg26=reg14*reg26; reg16=reg19*reg16; var_inter[0]+=reg24-reg17; var_inter[1]+=reg16-reg26;

}
template<> struct ElemVarInterFromPosNonLinear<Quad_6> { static const bool res = 2; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=var_inter[0]-0.5; T reg3=var_inter[0]*reg0; reg1=reg0*reg1;
    reg0=1-var_inter[1]; reg2=var_inter[0]*reg2; reg3=4*reg3; reg1=2*reg1; T reg4=reg1*reg0;
    reg2=2*reg2; T reg5=reg3*reg0; reg4=val[0]*reg4; reg5=val[4]*reg5; reg0=reg2*reg0;
    reg5=reg4+reg5; reg0=val[1]*reg0; reg1=var_inter[1]*reg1; reg3=var_inter[1]*reg3; reg1=val[3]*reg1;
    reg0=reg5+reg0; reg1=reg0+reg1; reg3=val[5]*reg3; reg2=var_inter[1]*reg2; reg3=reg1+reg3;
    reg2=val[2]*reg2; res=reg3+reg2;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Quad_6 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=var_inter[0]-0.5; T reg1=1-var_inter[0]; T reg2=0.5-var_inter[0]; reg0=var_inter[0]*reg0; T reg3=var_inter[0]*reg1;
    reg2=reg1*reg2; reg2=2*reg2; reg3=4*reg3; reg0=2*reg0; reg1=1-var_inter[1];
    T reg4=reg2*reg1; res[0]=reg4; T reg5=reg3*reg1; res[4]=reg5; reg1=reg0*reg1;
    res[1]=reg1; reg2=var_inter[1]*reg2; res[3]=reg2; reg3=var_inter[1]*reg3; res[5]=reg3;
    reg0=var_inter[1]*reg0; res[2]=reg0;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Quad_6> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

}
#endif // LMT_QUAD_6
