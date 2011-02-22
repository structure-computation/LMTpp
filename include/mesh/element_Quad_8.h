#ifndef LMT_QUAD_8
#define LMT_QUAD_8
#include "node.h"
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_8 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 13, 26, 39, 52, 74, 96, 118, 140, 162, }; // fonction de lordre du poly
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
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Quad_8 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=nodes[5]->pos[0]-nodes[7]->pos[0]; T reg1=nodes[6]->pos[1]-nodes[4]->pos[1]; T reg2=nodes[5]->pos[1]-nodes[7]->pos[1]; T reg3=nodes[6]->pos[0]-nodes[4]->pos[0]; reg1=reg0*reg1;
    reg3=reg2*reg3; T det_jac=reg1-reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[7],nodes[3],nodes[6],nodes[2],nodes[5],nodes[1],nodes[4]};
        for(unsigned i=0;i<8;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad_8 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; reg1=reg1-1; T reg2=1-reg0;
    T reg3=1+reg0; T reg4=reg0-reg1; T reg5=0.25*reg3; T reg6=0.25*reg2; T reg7=1-reg1;
    T reg8=reg0+reg1; T reg9=0.5*reg2; T reg10=0.5*reg7; T reg11=0.5*reg3; T reg12=1+reg1;
    T reg13=reg6*reg7; T reg14=reg7*reg5; T reg15=1+reg8; reg4=reg4-1; T reg16=reg15*reg9;
    reg5=reg12*reg5; T reg17=2*reg14; T reg18=reg4*reg10; T reg19=2*reg13; T reg20=reg15*reg10;
    T reg21=0.5*reg12; T reg22=reg1-reg0; reg8=reg8-1; T reg23=reg4*reg11; reg20=reg19-reg20;
    reg18=reg17+reg18; T reg24=2*reg5; T reg25=reg8*reg21; reg23=reg17+reg23; reg16=reg19-reg16;
    reg17=reg8*reg11; reg6=reg6*reg12; reg22=reg22-1; reg25=reg24+reg25; reg19=2*reg6;
    T reg26=reg22*reg21; T reg27=pos_nodes[1][0]*reg18; T reg28=pos_nodes[0][0]*reg20; T reg29=pos_nodes[0][1]*reg16; T reg30=pos_nodes[1][1]*reg23;
    reg17=reg24+reg17; reg24=reg22*reg9; T reg31=pos_nodes[1][0]*reg23; T reg32=pos_nodes[0][0]*reg16; T reg33=pos_nodes[1][1]*reg18;
    T reg34=pos_nodes[0][1]*reg20; reg34=reg33-reg34; reg33=pos_nodes[2][1]*reg25; reg32=reg31+reg32; reg31=pos_nodes[2][0]*reg17;
    reg24=reg19+reg24; reg15=reg13*reg15; reg4=reg14*reg4; reg13=pos_nodes[2][1]*reg17; reg29=reg30+reg29;
    reg14=pos_nodes[2][0]*reg25; reg28=reg27-reg28; reg27=pow(reg0,2); reg30=2*reg0; reg26=reg19+reg26;
    reg27=1-reg27; reg19=reg4*pos_nodes[1][1]; reg8=reg5*reg8; reg5=2*reg1; T reg35=pos_nodes[3][1]*reg24;
    reg32=reg31-reg32; reg31=pos_nodes[3][0]*reg24; T reg36=pow(reg1,2); reg33=reg34+reg33; reg34=pos_nodes[3][1]*reg26;
    reg29=reg13-reg29; reg13=pos_nodes[1][0]*reg4; T reg37=pos_nodes[3][0]*reg26; reg14=reg28+reg14; reg28=reg7*reg30;
    T reg38=pos_nodes[0][1]*reg15; T reg39=pos_nodes[0][0]*reg15; T reg40=reg27*pos_nodes[4][0]; reg31=reg32+reg31; reg34=reg33-reg34;
    reg32=pos_nodes[2][0]*reg8; reg33=pos_nodes[4][1]*reg28; T reg41=0.5*reg27; reg39=reg13-reg39; reg13=reg3*reg5;
    reg22=reg6*reg22; reg35=reg29+reg35; reg6=reg27*pos_nodes[4][1]; reg36=1-reg36; reg37=reg14-reg37;
    reg14=pos_nodes[2][1]*reg8; reg29=pos_nodes[4][0]*reg28; reg38=reg19-reg38; reg19=0.5*reg36; reg32=reg39+reg32;
    reg39=reg22*pos_nodes[3][0]; reg14=reg38+reg14; reg38=reg22*pos_nodes[3][1]; reg7=reg7*reg41; reg33=reg34-reg33;
    reg34=reg36*pos_nodes[5][1]; T reg42=pos_nodes[5][0]*reg13; reg40=reg31-reg40; reg31=reg36*pos_nodes[5][0]; reg29=reg37-reg29;
    reg37=reg12*reg30; T reg43=pos_nodes[5][1]*reg13; reg6=reg35-reg6; reg34=reg33+reg34; reg33=pos_nodes[6][1]*reg37;
    reg35=reg27*pos_nodes[6][1]; reg43=reg6-reg43; reg38=reg14+reg38; reg6=reg7*pos_nodes[4][0]; reg39=reg32+reg39;
    reg14=reg7*pos_nodes[4][1]; reg32=reg27*pos_nodes[6][0]; reg42=reg40-reg42; reg40=reg2*reg5; reg3=reg3*reg19;
    reg31=reg29+reg31; reg29=pos_nodes[6][0]*reg37; T reg44=pos_nodes[7][1]*reg40; reg35=reg43+reg35; reg43=reg3*pos_nodes[5][1];
    reg41=reg12*reg41; reg29=reg31-reg29; reg12=reg36*pos_nodes[7][0]; reg14=reg38+reg14; reg31=reg36*pos_nodes[7][1];
    reg33=reg34-reg33; reg32=reg42+reg32; reg34=pos_nodes[7][0]*reg40; reg6=reg39+reg6; reg38=reg3*pos_nodes[5][0];
    reg43=reg14+reg43; reg14=reg41*pos_nodes[6][1]; reg44=reg35-reg44; reg31=reg33-reg31; reg33=reg41*pos_nodes[6][0];
    reg38=reg6+reg38; reg34=reg32-reg34; reg12=reg29-reg12; reg19=reg2*reg19; reg2=reg34*reg31;
    reg6=reg19*pos_nodes[7][0]; reg33=reg38+reg33; reg29=reg12*reg44; reg14=reg43+reg14; reg32=reg19*pos_nodes[7][1];
    reg2=reg29-reg2; reg32=reg14+reg32; reg6=reg33+reg6; reg32=pos[1]-reg32; reg14=reg44/reg2;
    reg6=pos[0]-reg6; reg33=reg31/reg2; reg35=reg34/reg2; reg2=reg12/reg2; reg14=reg6*reg14;
    reg35=reg32*reg35; reg33=reg6*reg33; reg2=reg32*reg2; var_inter[0]=reg14-reg35; var_inter[1]=reg2-reg33;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_8 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; T reg2=1+reg0; reg1=reg1-1;
    T reg3=1-reg0; T reg4=0.25*reg2; T reg5=reg0+reg1; T reg6=reg0-reg1; T reg7=1-reg1;
    T reg8=0.25*reg3; T reg9=0.5*reg2; T reg10=0.5*reg7; T reg11=reg8*reg7; T reg12=1+reg5;
    T reg13=1+reg1; T reg14=reg4*reg7; reg6=reg6-1; T reg15=0.5*reg3; reg4=reg13*reg4;
    reg5=reg5-1; T reg16=reg12*reg15; T reg17=2*reg14; T reg18=reg6*reg10; T reg19=2*reg11;
    T reg20=reg12*reg10; T reg21=0.5*reg13; T reg22=reg1-reg0; T reg23=reg6*reg9; reg18=reg17+reg18;
    reg20=reg19-reg20; reg16=reg19-reg16; reg19=2*reg4; T reg24=reg5*reg21; T reg25=reg5*reg9;
    reg23=reg17+reg23; reg8=reg13*reg8; reg22=reg22-1; reg24=reg19+reg24; reg17=2*reg8;
    T reg26=reg22*reg21; T reg27=pos_nodes[1][0]*reg18; T reg28=pos_nodes[0][0]*reg20; T reg29=pos_nodes[0][1]*reg16; T reg30=pos_nodes[1][1]*reg23;
    reg25=reg19+reg25; reg19=reg22*reg15; T reg31=pos_nodes[1][0]*reg23; T reg32=pos_nodes[0][0]*reg16; T reg33=pos_nodes[1][1]*reg18;
    T reg34=pos_nodes[0][1]*reg20; T reg35=pos_nodes[2][1]*reg25; T reg36=pow(reg0,2); reg29=reg30+reg29; reg6=reg14*reg6;
    reg19=reg17+reg19; reg14=pos_nodes[2][0]*reg25; reg30=pos_nodes[2][0]*reg24; reg28=reg27-reg28; reg32=reg31+reg32;
    reg12=reg11*reg12; reg34=reg33-reg34; reg11=pos_nodes[2][1]*reg24; reg26=reg17+reg26; reg17=2*reg0;
    reg27=reg6*pos_nodes[1][0]; reg31=pos_nodes[0][0]*reg12; reg33=pos_nodes[3][1]*reg26; reg11=reg34+reg11; reg34=reg6*pos_nodes[1][1];
    T reg37=2*reg1; reg32=reg14-reg32; reg14=pos_nodes[0][1]*reg12; reg5=reg4*reg5; reg4=pos_nodes[3][0]*reg19;
    T reg38=reg7*reg17; reg30=reg28+reg30; reg28=pos_nodes[3][0]*reg26; T reg39=pow(reg1,2); reg29=reg35-reg29;
    reg35=pos_nodes[3][1]*reg19; reg36=1-reg36; T reg40=reg5*pos_nodes[2][1]; reg14=reg34-reg14; reg39=1-reg39;
    reg33=reg11-reg33; reg11=reg5*pos_nodes[2][0]; reg31=reg27-reg31; reg27=0.5*reg36; reg35=reg29+reg35;
    reg29=reg36*pos_nodes[4][1]; reg34=pos_nodes[4][1]*reg38; T reg41=reg36*pos_nodes[4][0]; reg4=reg32+reg4; reg22=reg8*reg22;
    reg28=reg30-reg28; reg8=reg2*reg37; reg30=pos_nodes[4][0]*reg38; reg40=reg14+reg40; reg14=reg22*pos_nodes[3][1];
    reg32=0.5*reg39; T reg42=reg39*pos_nodes[5][0]; reg7=reg27*reg7; reg30=reg28-reg30; reg28=reg22*pos_nodes[3][0];
    reg11=reg31+reg11; reg29=reg35-reg29; reg34=reg33-reg34; reg31=reg39*pos_nodes[5][1]; reg33=pos_nodes[5][0]*reg8;
    reg41=reg4-reg41; reg4=pos_nodes[5][1]*reg8; reg35=reg13*reg17; reg4=reg29-reg4; reg31=reg34+reg31;
    reg29=pos_nodes[6][1]*reg35; reg34=reg36*pos_nodes[6][1]; reg14=reg40+reg14; reg40=reg7*pos_nodes[4][0]; reg28=reg11+reg28;
    reg11=reg7*pos_nodes[4][1]; T reg43=reg36*pos_nodes[6][0]; reg33=reg41-reg33; reg41=reg3*reg37; reg2=reg2*reg32;
    reg42=reg30+reg42; reg30=pos_nodes[6][0]*reg35; T reg44=pos_nodes[7][1]*reg41; reg34=reg4+reg34; reg4=reg2*pos_nodes[5][1];
    reg27=reg13*reg27; reg30=reg42-reg30; reg13=reg39*pos_nodes[7][0]; reg11=reg14+reg11; reg14=reg39*pos_nodes[7][1];
    reg29=reg31-reg29; reg43=reg33+reg43; reg31=pos_nodes[7][0]*reg41; reg40=reg28+reg40; reg28=reg2*pos_nodes[5][0];
    reg44=reg34-reg44; reg4=reg11+reg4; reg11=reg27*pos_nodes[6][1]; reg14=reg29-reg14; reg3=reg32*reg3;
    reg13=reg30-reg13; reg29=reg27*pos_nodes[6][0]; reg28=reg40+reg28; reg31=reg43-reg31; reg30=reg31*reg14;
    reg32=reg3*pos_nodes[7][1]; reg11=reg4+reg11; reg29=reg28+reg29; reg4=reg3*pos_nodes[7][0]; reg28=reg13*reg44;
    reg30=reg28-reg30; reg32=reg11+reg32; reg4=reg29+reg4; reg4=pos[0]-reg4; reg32=pos[1]-reg32;
    reg11=reg44/reg30; reg29=reg14/reg30; reg33=reg31/reg30; reg30=reg13/reg30; reg11=reg4*reg11;
    reg33=reg32*reg33; reg29=reg4*reg29; reg30=reg32*reg30; var_inter[0]+=reg11-reg33; var_inter[1]+=reg30-reg29;

}
template<> struct ElemVarInterFromPosNonLinear<Quad_8> { static const bool res = 2; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; reg0=reg0-1; T reg2=1+reg0; T reg3=1-reg0;
    reg1=reg1-1; T reg4=reg0-reg1; T reg5=0.25*reg2; T reg6=0.25*reg3; T reg7=1-reg1;
    T reg8=reg0+reg1; reg4=reg4-1; T reg9=reg7*reg5; T reg10=1+reg1; T reg11=reg6*reg7;
    T reg12=1+reg8; reg5=reg10*reg5; reg8=reg8-1; reg4=reg9*reg4; reg12=reg11*reg12;
    reg9=pow(reg0,2); reg0=reg1-reg0; reg1=pow(reg1,2); reg6=reg6*reg10; reg9=1-reg9;
    reg8=reg5*reg8; reg0=reg0-1; reg4=val[1]*reg4; reg12=val[0]*reg12; reg12=reg4-reg12;
    reg8=val[2]*reg8; reg1=1-reg1; reg0=reg6*reg0; reg9=0.5*reg9; reg1=0.5*reg1;
    reg7=reg7*reg9; reg0=val[3]*reg0; reg8=reg12+reg8; reg2=reg2*reg1; reg7=val[4]*reg7;
    reg0=reg8+reg0; reg7=reg0+reg7; reg2=val[5]*reg2; reg9=reg10*reg9; reg2=reg7+reg2;
    reg9=val[6]*reg9; reg1=reg3*reg1; reg9=reg2+reg9; reg1=val[7]*reg1; res=reg9+reg1;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Quad_8 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; reg1=reg1-1; T reg2=1-reg0;
    T reg3=pow(reg1,2); T reg4=1+reg0; T reg5=reg0+reg1; T reg6=pow(reg0,2); T reg7=1-reg1;
    T reg8=0.25*reg2; T reg9=reg1-reg0; reg6=1-reg6; reg0=reg0-reg1; reg3=1-reg3;
    T reg10=0.25*reg4; reg1=1+reg1; T reg11=1+reg5; T reg12=reg8*reg7; reg6=0.5*reg6;
    reg3=0.5*reg3; reg9=reg9-1; reg8=reg8*reg1; reg5=reg5-1; T reg13=reg1*reg10;
    reg0=reg0-1; reg10=reg7*reg10; reg11=reg12*reg11; reg9=reg8*reg9; res[3]=reg9;
    reg5=reg13*reg5; res[2]=reg5; reg0=reg10*reg0; res[1]=reg0; reg7=reg7*reg6;
    res[4]=reg7; reg4=reg4*reg3; res[5]=reg4; reg6=reg1*reg6; res[6]=reg6;
    reg3=reg2*reg3; res[7]=reg3; res[0]=-reg11;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Quad_8> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Quad_8,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; reg0=reg0-1; T reg2=1+reg0; T reg3=1-reg0;
    reg1=reg1-1; T reg4=reg0-reg1; T reg5=0.25*reg2; T reg6=reg0+reg1; T reg7=1-reg1;
    T reg8=0.25*reg3; T reg9=reg8*reg7; reg4=reg4-1; T reg10=reg7*reg5; T reg11=1+reg1;
    T reg12=1+reg6; T reg13=0.5*reg7; T reg14=reg4*reg13; T reg15=reg12*reg13; T reg16=2*reg10;
    T reg17=2*reg9; T reg18=reg1-reg0; T reg19=0.5*reg11; reg5=reg11*reg5; reg6=reg6-1;
    T reg20=reg6*reg19; reg18=reg18-1; reg8=reg8*reg11; reg15=reg17-reg15; T reg21=2*reg5;
    reg14=reg16+reg14; T reg22=elem.pos(1)[0]*reg14; reg20=reg21+reg20; T reg23=elem.pos(0)[0]*reg15; T reg24=2*reg8;
    T reg25=reg18*reg19; T reg26=elem.pos(0)[1]*reg15; T reg27=elem.pos(1)[1]*reg14; reg25=reg24+reg25; T reg28=2*reg0;
    T reg29=elem.pos(2)[0]*reg20; reg15=elem.pos(0)[2]*reg15; reg23=reg22-reg23; reg14=elem.pos(1)[2]*reg14; reg22=elem.pos(2)[1]*reg20;
    reg26=reg27-reg26; reg27=0.5*reg2; T reg30=elem.pos(3)[1]*reg25; T reg31=elem.pos(3)[0]*reg25; reg22=reg26+reg22;
    reg26=0.5*reg3; reg29=reg23+reg29; reg20=elem.pos(2)[2]*reg20; reg23=pow(reg1,2); reg15=reg14-reg15;
    reg14=reg7*reg28; T reg32=elem.pos(4)[1]*reg14; reg22=reg22-reg30; T reg33=elem.pos(4)[0]*reg14; reg29=reg29-reg31;
    T reg34=elem.pos(3)[2]*reg25; T reg35=reg4*reg27; T reg36=reg12*reg26; reg20=reg15+reg20; reg23=1-reg23;
    reg35=reg16+reg35; reg15=elem.pos(4)[2]*reg14; reg16=reg11*reg28; T reg37=reg6*reg27; T reg38=elem.pos(5)[0]*reg23;
    T reg39=elem.pos(5)[1]*reg23; reg20=reg20-reg34; reg22=reg22-reg32; reg36=reg17-reg36; reg29=reg29-reg33;
    reg17=reg18*reg26; reg39=reg22+reg39; reg22=elem.pos(1)[0]*reg35; reg21=reg37+reg21; reg37=elem.pos(5)[2]*reg23;
    reg20=reg20-reg15; T reg40=elem.pos(6)[0]*reg16; T reg41=elem.pos(1)[1]*reg35; T reg42=elem.pos(0)[1]*reg36; T reg43=elem.pos(6)[1]*reg16;
    reg38=reg29+reg38; reg29=elem.pos(0)[0]*reg36; T reg44=elem.pos(7)[1]*reg23; reg29=reg22+reg29; reg37=reg20+reg37;
    reg36=elem.pos(0)[2]*reg36; reg20=elem.pos(1)[2]*reg35; T reg45=elem.pos(6)[2]*reg16; reg38=reg38-reg40; reg17=reg24+reg17;
    reg24=pow(reg0,2); reg39=reg39-reg43; T reg46=elem.pos(7)[0]*reg23; reg42=reg41+reg42; T reg47=elem.pos(2)[1]*reg21;
    T reg48=elem.pos(2)[0]*reg21; reg38=reg38-reg46; reg48=reg48-reg29; reg24=1-reg24; reg21=elem.pos(2)[2]*reg21;
    T reg49=2*reg1; reg36=reg36+reg20; reg37=reg37-reg45; T reg50=elem.pos(3)[0]*reg17; reg39=reg39-reg44;
    reg47=reg47-reg42; T reg51=elem.pos(3)[1]*reg17; T reg52=elem.pos(7)[2]*reg23; T reg53=elem.pos(4)[1]*reg24; reg48=reg50+reg48;
    reg50=reg2*reg49; T reg54=elem.pos(4)[0]*reg24; reg17=elem.pos(3)[2]*reg17; T reg55=pow(reg39,2); reg21=reg21-reg36;
    reg51=reg47+reg51; reg37=reg37-reg52; reg47=pow(reg38,2); T reg56=elem.pos(5)[0]*reg50; reg47=reg55+reg47;
    reg51=reg51-reg53; reg55=elem.pos(5)[1]*reg50; reg48=reg48-reg54; T reg57=pow(reg37,2); reg17=reg21+reg17;
    reg21=elem.pos(4)[2]*reg24; T reg58=reg3*reg49; T reg59=elem.pos(5)[2]*reg50; T reg60=elem.pos(6)[0]*reg24; reg17=reg17-reg21;
    reg51=reg51-reg55; T reg61=elem.pos(6)[1]*reg24; reg48=reg48-reg56; reg47=reg57+reg47; reg47=pow(reg47,0.5);
    reg57=elem.pos(7)[0]*reg58; reg61=reg51+reg61; reg17=reg17-reg59; reg60=reg48+reg60; reg48=elem.pos(6)[2]*reg24;
    reg51=elem.pos(7)[1]*reg58; T reg62=reg38/reg47; reg61=reg61-reg51; reg48=reg17+reg48; reg17=reg39/reg47;
    T reg63=elem.pos(7)[2]*reg58; reg60=reg60-reg57; reg48=reg48-reg63; reg47=reg37/reg47; T reg64=reg62*reg60;
    T reg65=reg17*reg61; T reg66=reg47*reg48; reg65=reg64+reg65; reg66=reg65+reg66; reg64=reg62*reg66;
    reg65=reg17*reg66; reg64=reg60-reg64; T reg67=reg47*reg66; reg65=reg61-reg65; T reg68=pow(reg64,2);
    reg67=reg48-reg67; T reg69=pow(reg65,2); T reg70=pow(reg67,2); reg68=reg69+reg68; reg70=reg68+reg70;
    reg70=pow(reg70,0.5); reg64=reg64/reg70; reg65=reg65/reg70; reg62=reg62*reg38; reg70=reg67/reg70;
    reg38=reg38*reg64; reg67=reg39*reg65; reg64=reg60*reg64; reg65=reg61*reg65; reg39=reg17*reg39;
    reg17=reg37*reg70; reg67=reg38+reg67; reg65=reg64+reg65; reg70=reg48*reg70; reg37=reg47*reg37;
    reg62=reg39+reg62; reg65=reg70+reg65; reg37=reg62+reg37; reg17=reg67+reg17; reg38=reg37*reg65;
    reg39=reg66*reg17; reg39=reg38-reg39; return reg39;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Quad_8,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.45534180126147951289*elem.pos(0)[0]; T reg1=0.12200846792814621817*elem.pos(1)[0]; T reg2=0.36602540378443865451*elem.pos(0)[0]; T reg3=0.45534180126147951289*elem.pos(1)[1]; T reg4=0.36602540378443865451*elem.pos(0)[1];
    T reg5=0.12200846792814621817*elem.pos(0)[1]; T reg6=0.12200846792814621817*elem.pos(1)[1]; T reg7=0.45534180126147951289*elem.pos(1)[0]; T reg8=0.45534180126147951289*elem.pos(0)[1]; T reg9=0.12200846792814621817*elem.pos(0)[0];
    T reg10=0.36602540378443865451*elem.pos(1)[1]; T reg11=0.36602540378443865451*elem.pos(1)[0]; T reg12=0.45534180126147951289*elem.pos(2)[0]; T reg13=0.12200846792814621817*elem.pos(2)[0]; T reg14=reg11+reg9;
    T reg15=reg1+reg2; T reg16=1.3660254037844385386*elem.pos(2)[0]; T reg17=1.3660254037844385386*elem.pos(1)[1]; T reg18=1.3660254037844385386*elem.pos(2)[1]; T reg19=0.12200846792814621817*elem.pos(2)[1];
    T reg20=reg3+reg4; T reg21=0.45534180126147951289*elem.pos(2)[1]; T reg22=reg10+reg5; T reg23=1.3660254037844385386*elem.pos(1)[0]; T reg24=reg10+reg8;
    T reg25=reg4+reg6; T reg26=reg2+reg7; T reg27=reg11+reg0; T reg28=0.09622504486493763966*elem.pos(1)[0]; T reg29=reg18+reg20;
    T reg30=0.12200846792814621817*elem.pos(3)[1]; T reg31=0.09622504486493763966*elem.pos(0)[0]; T reg32=0.16666666666666667632*elem.pos(1)[1]; T reg33=0.09622504486493763966*elem.pos(0)[1]; T reg34=0.16666666666666667632*elem.pos(1)[0];
    T reg35=reg0+reg23; reg23=reg9+reg23; reg9=reg16+reg26; reg25=reg18+reg25; reg18=0.45534180126147951289*elem.pos(3)[1];
    T reg36=reg19+reg24; T reg37=1.3660254037844385386*elem.pos(3)[1]; T reg38=0.12200846792814621817*elem.pos(3)[0]; T reg39=0.16666666666666667632*elem.pos(0)[1]; T reg40=1.3660254037844385386*elem.pos(0)[1];
    T reg41=reg13+reg27; reg5=reg5+reg17; reg16=reg15+reg16; reg15=0.45534180126147951289*elem.pos(3)[0]; T reg42=reg14+reg12;
    T reg43=1.3660254037844385386*elem.pos(3)[0]; T reg44=0.09622504486493763966*elem.pos(1)[1]; T reg45=0.16666666666666667632*elem.pos(0)[0]; T reg46=reg22+reg21; T reg47=1.3660254037844385386*elem.pos(0)[0];
    reg17=reg8+reg17; reg1=reg1+reg47; T reg48=reg44+reg39; T reg49=0.096225044864937581723*elem.pos(1)[1]; reg23=reg12+reg23;
    T reg50=0.36602540378443865451*elem.pos(3)[1]; T reg51=0.16666666666666667632*elem.pos(2)[0]; T reg52=reg42+reg43; reg5=reg21+reg5; T reg53=reg28+reg45;
    T reg54=0.16666666666666667632*elem.pos(2)[1]; T reg55=0.66666666666666670528*elem.pos(4)[0]; reg9=reg9+reg38; reg17=reg19+reg17; reg19=0.48803387171258487271*elem.pos(4)[0];
    reg16=reg16+reg15; T reg56=0.36602540378443865451*elem.pos(2)[0]; reg47=reg7+reg47; T reg57=reg37+reg46; reg41=reg43+reg41;
    reg43=reg3+reg40; T reg58=0.096225044864937581723*elem.pos(2)[0]; reg29=reg29+reg30; T reg59=0.66666666666666670528*elem.pos(4)[1]; reg31=reg34+reg31;
    reg33=reg32+reg33; T reg60=0.096225044864937581723*elem.pos(1)[0]; reg25=reg25+reg18; T reg61=0.48803387171258487271*elem.pos(4)[1]; reg35=reg13+reg35;
    reg13=0.36602540378443865451*elem.pos(3)[0]; T reg62=0.096225044864937581723*elem.pos(2)[1]; reg40=reg6+reg40; reg6=0.36602540378443865451*elem.pos(2)[1]; reg37=reg36+reg37;
    reg36=0.096225044864937581723*elem.pos(3)[1]; reg41=reg41-reg55; T reg63=reg48+reg54; T reg64=reg61-reg57; T reg65=reg19-reg52;
    T reg66=0.48803387171258487271*elem.pos(5)[0]; reg45=reg60-reg45; reg60=1.8213672050459180516*elem.pos(4)[0]; reg35=reg35+reg13; T reg67=0.48803387171258487271*elem.pos(5)[1];
    reg37=reg37-reg59; T reg68=0.66666666666666670528*elem.pos(5)[1]; reg25=reg25-reg61; T reg69=0.096225044864937581723*elem.pos(0)[0]; T reg70=1.8213672050459180516*elem.pos(5)[1];
    reg29=reg29-reg59; T reg71=0.096225044864937581723*elem.pos(0)[1]; T reg72=0.66666666666666670528*elem.pos(5)[0]; reg16=reg16-reg19; T reg73=reg47+reg56;
    reg40=reg6+reg40; T reg74=reg6+reg43; T reg75=0.16666666666666667632*elem.pos(3)[0]; reg58=reg58-reg31; reg1=reg56+reg1;
    reg62=reg62-reg33; T reg76=0.16666666666666667632*elem.pos(3)[1]; T reg77=reg5+reg50; T reg78=0.096225044864937581723*elem.pos(3)[0]; reg9=reg9-reg55;
    T reg79=1.8213672050459180516*elem.pos(5)[0]; T reg80=reg53+reg51; T reg81=reg13+reg23; reg17=reg50+reg17; reg39=reg49-reg39;
    reg49=1.8213672050459180516*elem.pos(4)[1]; T reg82=reg15+reg1; T reg83=reg59+reg77; reg30=reg30+reg74; reg45=reg45-reg51;
    reg35=reg35-reg60; T reg84=reg18+reg40; T reg85=0.09622504486493763966*elem.pos(2)[1]; reg38=reg38+reg73; T reg86=0.09622504486493763966*elem.pos(3)[0];
    reg17=reg17-reg49; T reg87=reg55+reg81; T reg88=reg71-reg32; T reg89=0.14088324360345809781*elem.pos(4)[1]; T reg90=0.09622504486493763966*elem.pos(2)[0];
    T reg91=reg69-reg34; reg62=reg62-reg76; reg65=reg72+reg65; reg78=reg78-reg80; reg39=reg39-reg54;
    T reg92=0.66666666666666670528*elem.pos(6)[0]; reg9=reg9-reg79; T reg93=1.8213672050459180516*elem.pos(6)[1]; reg25=reg25+reg68; T reg94=0.09622504486493763966*elem.pos(3)[1];
    T reg95=0.66666666666666670528*elem.pos(6)[1]; reg29=reg29-reg70; T reg96=1.8213672050459180516*elem.pos(6)[0]; reg16=reg16+reg72; T reg97=0.14088324360345809781*elem.pos(4)[0];
    reg58=reg58-reg75; reg37=reg37-reg67; reg36=reg36-reg63; reg41=reg41-reg66; reg64=reg68+reg64;
    reg62=reg62+reg89; T reg98=0.48803387171258487271*elem.pos(7)[0]; reg9=reg9+reg92; reg36=reg89+reg36; reg89=reg79-reg87;
    T reg99=0.52578342306320860749*elem.pos(5)[0]; T reg100=0.66666666666666670528*elem.pos(7)[1]; reg25=reg25-reg93; reg64=reg93+reg64; reg88=reg88-reg85;
    T reg101=0.48803387171258487271*elem.pos(7)[1]; reg29=reg29+reg95; reg91=reg91-reg90; T reg102=0.52578342306320860749*elem.pos(4)[0]; T reg103=reg60-reg38;
    T reg104=0.66666666666666670528*elem.pos(7)[0]; reg16=reg16-reg96; reg45=reg45-reg86; T reg105=0.52578342306320860749*elem.pos(4)[1]; reg39=reg39-reg94;
    reg65=reg96+reg65; reg35=reg72+reg35; T reg106=0.48803387171258487271*elem.pos(6)[0]; reg55=reg55+reg82; reg37=reg95+reg37;
    T reg107=0.14088324360345809781*elem.pos(5)[1]; T reg108=reg49-reg30; T reg109=0.14088324360345809781*elem.pos(5)[0]; T reg110=reg70-reg83; T reg111=1.8213672050459180516*elem.pos(7)[0];
    reg58=reg58+reg97; T reg112=0.48803387171258487271*elem.pos(6)[1]; reg17=reg68+reg17; reg59=reg59+reg84; T reg113=1.8213672050459180516*elem.pos(7)[1];
    reg78=reg97+reg78; reg97=0.52578342306320860749*elem.pos(5)[1]; reg41=reg92+reg41; reg108=reg68+reg108; reg68=reg66-reg55;
    reg39=reg39+reg105; reg103=reg72+reg103; reg88=reg88-reg76; reg72=reg67-reg59; reg58=reg58+reg99;
    reg41=reg41-reg111; T reg114=0.52578342306320860749*elem.pos(6)[0]; reg78=reg78+reg109; reg110=reg95+reg110; reg62=reg62+reg97;
    reg36=reg36+reg107; T reg115=0.52578342306320860749*elem.pos(6)[1]; reg35=reg35-reg106; reg37=reg37-reg113; reg9=reg9-reg98;
    reg17=reg17-reg112; reg65=reg65-reg104; reg89=reg92+reg89; reg25=reg25-reg100; reg29=reg29-reg101;
    reg91=reg91-reg75; reg45=reg45+reg102; reg16=reg16-reg104; reg64=reg64-reg100; T reg116=0.14088324360345809781*elem.pos(6)[1];
    reg36=reg115+reg36; reg39=reg97+reg39; reg68=reg92+reg68; reg88=reg105+reg88; reg92=0.52578342306320860749*elem.pos(7)[1];
    reg115=reg62+reg115; reg62=0.14088324360345809781*elem.pos(7)[1]; reg97=0.52578342306320860749*elem.pos(7)[0]; reg78=reg114+reg78; reg45=reg99+reg45;
    reg91=reg102+reg91; reg89=reg98+reg89; reg17=reg17-reg100; reg110=reg101+reg110; reg9=reg25*reg9;
    reg29=reg16*reg29; reg103=reg106+reg103; reg35=reg35-reg104; reg72=reg95+reg72; reg16=0.14088324360345809781*elem.pos(7)[0];
    reg114=reg58+reg114; reg37=reg65*reg37; reg41=reg64*reg41; reg108=reg112+reg108; reg25=0.14088324360345809781*elem.pos(6)[0];
    reg78=reg78+reg97; reg45=reg45+reg25; reg115=reg115+reg62; reg110=reg35*reg110; reg89=reg17*reg89;
    reg36=reg36+reg92; reg91=reg109+reg91; reg39=reg39+reg116; reg41=reg37-reg41; reg9=reg29-reg9;
    reg104=reg103-reg104; reg114=reg114+reg16; reg72=reg113+reg72; reg88=reg107+reg88; reg68=reg111+reg68;
    reg100=reg108-reg100; reg78=reg78*reg41; reg36=reg41*reg36; reg114=reg114*reg9; reg72=reg104*reg72;
    reg68=reg100*reg68; reg115=reg9*reg115; reg45=reg16+reg45; reg89=reg110-reg89; reg88=reg116+reg88;
    reg91=reg25+reg91; reg39=reg62+reg39; reg9=0.25*reg9; reg68=reg72-reg68; reg41=0.25*reg41;
    reg91=reg97+reg91; reg39=reg89*reg39; reg36=0.25*reg36; reg88=reg92+reg88; reg114=0.25*reg114;
    reg45=reg45*reg89; reg115=0.25*reg115; reg78=0.25*reg78; reg39=0.25*reg39; reg88=reg68*reg88;
    reg78=reg114+reg78; reg45=0.25*reg45; reg91=reg91*reg68; reg41=reg9+reg41; reg89=0.25*reg89;
    reg36=reg115+reg36; reg68=0.25*reg68; reg89=reg41+reg89; reg39=reg36+reg39; reg91=0.25*reg91;
    reg45=reg78+reg45; reg88=0.25*reg88; reg68=reg89+reg68; reg91=reg45+reg91; reg88=reg39+reg88;
    res[0]=reg91/reg68; res[1]=reg88/reg68;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Quad_8,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.12200846792814621817*elem.pos(1)[0]; T reg1=0.36602540378443865451*elem.pos(0)[0]; T reg2=0.12200846792814621817*elem.pos(0)[1]; T reg3=0.36602540378443865451*elem.pos(0)[1]; T reg4=0.36602540378443865451*elem.pos(1)[1];
    T reg5=0.12200846792814621817*elem.pos(0)[0]; T reg6=0.36602540378443865451*elem.pos(1)[0]; T reg7=0.12200846792814621817*elem.pos(1)[1]; T reg8=reg4+reg2; T reg9=0.12200846792814621817*elem.pos(1)[2];
    T reg10=1.3660254037844385386*elem.pos(1)[1]; T reg11=0.45534180126147951289*elem.pos(2)[1]; T reg12=0.36602540378443865451*elem.pos(1)[2]; T reg13=0.12200846792814621817*elem.pos(0)[2]; T reg14=1.3660254037844385386*elem.pos(2)[0];
    T reg15=reg0+reg1; T reg16=0.45534180126147951289*elem.pos(0)[0]; T reg17=0.45534180126147951289*elem.pos(0)[1]; T reg18=reg7+reg3; T reg19=1.3660254037844385386*elem.pos(1)[0];
    T reg20=1.3660254037844385386*elem.pos(2)[1]; T reg21=0.45534180126147951289*elem.pos(2)[0]; T reg22=reg6+reg5; T reg23=0.36602540378443865451*elem.pos(0)[2]; T reg24=reg9+reg23;
    T reg25=0.45534180126147951289*elem.pos(0)[2]; T reg26=0.45534180126147951289*elem.pos(1)[1]; T reg27=reg11+reg8; T reg28=reg21+reg22; T reg29=0.12200846792814621817*elem.pos(2)[1];
    reg18=reg20+reg18; T reg30=0.45534180126147951289*elem.pos(3)[1]; T reg31=0.45534180126147951289*elem.pos(3)[0]; reg15=reg14+reg15; T reg32=1.3660254037844385386*elem.pos(3)[0];
    T reg33=1.3660254037844385386*elem.pos(1)[2]; T reg34=0.12200846792814621817*elem.pos(2)[0]; T reg35=1.3660254037844385386*elem.pos(3)[1]; T reg36=1.3660254037844385386*elem.pos(2)[2]; T reg37=reg17+reg10;
    T reg38=1.3660254037844385386*elem.pos(0)[1]; T reg39=0.45534180126147951289*elem.pos(2)[2]; T reg40=reg12+reg13; T reg41=0.45534180126147951289*elem.pos(1)[0]; T reg42=1.3660254037844385386*elem.pos(0)[0];
    T reg43=reg16+reg19; T reg44=reg25+reg33; T reg45=0.45534180126147951289*elem.pos(3)[2]; T reg46=0.36602540378443865451*elem.pos(3)[0]; reg43=reg34+reg43;
    T reg47=0.36602540378443865451*elem.pos(3)[1]; reg37=reg29+reg37; reg24=reg36+reg24; reg18=reg18+reg30; T reg48=0.48803387171258487271*elem.pos(4)[1];
    T reg49=1.3660254037844385386*elem.pos(0)[2]; T reg50=reg28+reg32; T reg51=reg27+reg35; T reg52=reg26+reg38; T reg53=0.36602540378443865451*elem.pos(2)[1];
    T reg54=reg41+reg42; T reg55=0.36602540378443865451*elem.pos(2)[0]; T reg56=reg39+reg40; T reg57=1.3660254037844385386*elem.pos(3)[2]; T reg58=0.45534180126147951289*elem.pos(1)[2];
    reg15=reg15+reg31; T reg59=0.48803387171258487271*elem.pos(4)[0]; T reg60=0.12200846792814621817*elem.pos(2)[2]; T reg61=0.12200846792814621817*elem.pos(3)[0]; T reg62=1.8213672050459180516*elem.pos(4)[0];
    reg43=reg43+reg46; T reg63=reg48-reg51; T reg64=reg56+reg57; T reg65=reg59-reg50; reg37=reg37+reg47;
    T reg66=1.8213672050459180516*elem.pos(4)[1]; T reg67=0.12200846792814621817*elem.pos(3)[1]; T reg68=reg53+reg52; T reg69=0.36602540378443865451*elem.pos(3)[2]; reg44=reg60+reg44;
    reg24=reg24+reg45; T reg70=0.48803387171258487271*elem.pos(4)[2]; reg15=reg15-reg59; T reg71=0.36602540378443865451*elem.pos(2)[2]; T reg72=0.66666666666666670528*elem.pos(5)[0];
    T reg73=reg58+reg49; T reg74=reg55+reg54; reg18=reg18-reg48; T reg75=0.66666666666666670528*elem.pos(5)[1]; T reg76=1.8213672050459180516*elem.pos(4)[2];
    T reg77=reg67+reg68; reg63=reg75+reg63; T reg78=1.8213672050459180516*elem.pos(6)[0]; reg15=reg72+reg15; T reg79=reg61+reg74;
    T reg80=0.12200846792814621817*elem.pos(3)[2]; T reg81=reg70-reg64; T reg82=reg71+reg73; reg37=reg37-reg66; reg24=reg24-reg70;
    T reg83=0.66666666666666670528*elem.pos(5)[2]; reg65=reg72+reg65; reg44=reg44+reg69; reg43=reg43-reg62; T reg84=1.8213672050459180516*elem.pos(6)[1];
    reg18=reg75+reg18; reg65=reg78+reg65; reg63=reg84+reg63; T reg85=reg66-reg77; T reg86=reg62-reg79;
    T reg87=reg80+reg82; reg43=reg72+reg43; T reg88=0.66666666666666670528*elem.pos(7)[1]; reg18=reg18-reg84; T reg89=reg1+reg41;
    reg44=reg44-reg76; T reg90=0.66666666666666670528*elem.pos(7)[0]; T reg91=reg3+reg26; T reg92=0.48803387171258487271*elem.pos(6)[0]; reg15=reg15-reg78;
    T reg93=reg4+reg17; reg24=reg83+reg24; T reg94=reg6+reg16; reg37=reg75+reg37; reg81=reg83+reg81;
    T reg95=0.48803387171258487271*elem.pos(6)[1]; T reg96=1.8213672050459180516*elem.pos(6)[2]; reg43=reg43-reg92; reg85=reg75+reg85; reg37=reg37-reg95;
    reg75=reg76-reg87; reg65=reg65-reg90; T reg97=reg12+reg25; reg29=reg29+reg93; reg63=reg63-reg88;
    reg86=reg72+reg86; reg34=reg34+reg94; reg81=reg96+reg81; reg10=reg2+reg10; reg19=reg5+reg19;
    reg2=0.48803387171258487271*elem.pos(6)[2]; reg44=reg83+reg44; reg15=reg15-reg90; reg5=0.66666666666666670528*elem.pos(7)[2]; reg72=reg23+reg58;
    reg18=reg18-reg88; reg14=reg14+reg89; reg24=reg24-reg96; reg20=reg20+reg91; T reg98=pow(reg63,2);
    reg44=reg44-reg2; reg38=reg7+reg38; reg61=reg14+reg61; reg37=reg37-reg88; reg42=reg0+reg42;
    reg19=reg21+reg19; reg10=reg11+reg10; reg0=0.66666666666666670528*elem.pos(4)[0]; reg24=reg24-reg5; reg34=reg32+reg34;
    reg7=pow(reg65,2); reg14=pow(reg15,2); reg43=reg43-reg90; reg36=reg36+reg72; reg60=reg60+reg97;
    reg33=reg13+reg33; reg85=reg95+reg85; reg29=reg35+reg29; reg13=pow(reg18,2); reg75=reg83+reg75;
    reg81=reg81-reg5; reg86=reg92+reg86; reg32=0.66666666666666670528*elem.pos(4)[1]; reg67=reg20+reg67; reg38=reg53+reg38;
    reg20=pow(reg37,2); reg42=reg55+reg42; reg60=reg57+reg60; reg98=reg7+reg98; reg7=0.66666666666666670528*elem.pos(4)[2];
    reg80=reg36+reg80; reg35=pow(reg24,2); reg13=reg14+reg13; reg14=pow(reg81,2); reg90=reg86-reg90;
    reg67=reg67-reg32; reg75=reg2+reg75; reg33=reg39+reg33; reg88=reg85-reg88; reg36=pow(reg43,2);
    reg29=reg29-reg32; reg57=0.48803387171258487271*elem.pos(5)[1]; reg83=reg47+reg10; reg49=reg9+reg49; reg9=0.48803387171258487271*elem.pos(5)[0];
    reg34=reg34-reg0; reg85=reg46+reg19; reg44=reg44-reg5; reg61=reg61-reg0; reg86=1.8213672050459180516*elem.pos(5)[0];
    T reg99=1.8213672050459180516*elem.pos(5)[1]; reg34=reg34-reg9; reg67=reg67-reg99; reg20=reg36+reg20; reg36=0.66666666666666670528*elem.pos(6)[1];
    reg29=reg29-reg57; reg5=reg75-reg5; reg75=pow(reg90,2); reg35=reg13+reg35; reg13=reg69+reg33;
    T reg100=pow(reg88,2); reg49=reg71+reg49; T reg101=reg32+reg83; T reg102=reg0+reg85; reg61=reg61-reg86;
    T reg103=0.66666666666666670528*elem.pos(6)[0]; T reg104=pow(reg44,2); T reg105=reg30+reg38; T reg106=reg31+reg42; T reg107=0.48803387171258487271*elem.pos(5)[2];
    reg60=reg60-reg7; T reg108=1.8213672050459180516*elem.pos(5)[2]; reg80=reg80-reg7; reg14=reg98+reg14; reg32=reg32+reg105;
    reg60=reg60-reg107; reg29=reg36+reg29; reg98=1.8213672050459180516*elem.pos(7)[1]; T reg109=0.48803387171258487271*elem.pos(7)[0]; T reg110=pow(reg5,2);
    T reg111=reg45+reg49; T reg112=reg86-reg102; T reg113=reg99-reg101; T reg114=0.66666666666666670528*elem.pos(6)[2]; reg80=reg80-reg108;
    reg100=reg75+reg100; reg75=reg7+reg13; T reg115=0.48803387171258487271*elem.pos(7)[1]; reg14=pow(reg14,0.5); reg0=reg0+reg106;
    reg61=reg61+reg103; reg104=reg20+reg104; reg35=pow(reg35,0.5); reg67=reg67+reg36; reg34=reg103+reg34;
    reg20=1.8213672050459180516*elem.pos(7)[0]; reg110=reg100+reg110; reg104=pow(reg104,0.5); reg112=reg103+reg112; reg113=reg36+reg113;
    reg100=reg108-reg75; T reg116=reg18/reg35; reg7=reg7+reg111; T reg117=reg15/reg35; T reg118=reg57-reg32;
    T reg119=1.8213672050459180516*elem.pos(7)[2]; reg60=reg114+reg60; T reg120=0.48803387171258487271*elem.pos(7)[2]; reg80=reg80+reg114; T reg121=reg9-reg0;
    reg67=reg67-reg115; reg61=reg61-reg109; T reg122=reg65/reg14; reg29=reg29-reg98; T reg123=reg63/reg14;
    reg34=reg34-reg20; reg118=reg36+reg118; reg35=reg24/reg35; reg121=reg103+reg121; reg36=reg116*reg67;
    reg80=reg80-reg120; reg103=reg43/reg104; reg14=reg81/reg14; T reg124=reg107-reg7; T reg125=reg122*reg34;
    T reg126=reg123*reg29; reg110=pow(reg110,0.5); T reg127=reg117*reg61; reg60=reg60-reg119; T reg128=reg37/reg104;
    reg112=reg109+reg112; reg113=reg115+reg113; reg100=reg114+reg100; reg104=reg44/reg104; T reg129=reg103*reg112;
    T reg130=reg128*reg113; T reg131=reg35*reg80; T reg132=reg88/reg110; reg36=reg127+reg36; reg100=reg120+reg100;
    reg121=reg20+reg121; reg127=reg90/reg110; reg124=reg114+reg124; reg126=reg125+reg126; reg114=reg14*reg60;
    reg118=reg98+reg118; reg125=reg127*reg121; reg124=reg119+reg124; reg131=reg36+reg131; reg36=reg104*reg100;
    reg114=reg126+reg114; reg130=reg129+reg130; reg126=reg132*reg118; reg110=reg5/reg110; reg36=reg130+reg36;
    reg126=reg125+reg126; reg125=reg123*reg114; reg129=reg122*reg114; reg130=reg116*reg131; T reg133=reg117*reg131;
    T reg134=reg110*reg124; T reg135=reg103*reg36; T reg136=reg128*reg36; reg134=reg126+reg134; reg126=reg35*reg131;
    reg130=reg67-reg130; reg133=reg61-reg133; reg129=reg34-reg129; reg125=reg29-reg125; T reg137=reg14*reg114;
    T reg138=reg132*reg134; T reg139=reg127*reg134; reg135=reg112-reg135; reg126=reg80-reg126; T reg140=pow(reg130,2);
    T reg141=pow(reg133,2); T reg142=pow(reg129,2); T reg143=pow(reg125,2); reg137=reg60-reg137; reg136=reg113-reg136;
    T reg144=reg104*reg36; reg143=reg142+reg143; reg142=pow(reg137,2); T reg145=reg110*reg134; reg138=reg118-reg138;
    reg144=reg100-reg144; reg139=reg121-reg139; reg140=reg141+reg140; reg141=pow(reg135,2); T reg146=pow(reg136,2);
    T reg147=pow(reg126,2); T reg148=0.16666666666666667632*elem.pos(1)[1]; T reg149=0.16666666666666667632*elem.pos(0)[0]; T reg150=0.09622504486493763966*elem.pos(1)[0]; T reg151=0.09622504486493763966*elem.pos(0)[1];
    T reg152=0.09622504486493763966*elem.pos(0)[0]; T reg153=0.16666666666666667632*elem.pos(1)[0]; reg145=reg124-reg145; T reg154=pow(reg138,2); T reg155=pow(reg139,2);
    T reg156=0.16666666666666667632*elem.pos(0)[1]; reg147=reg140+reg147; reg140=0.16666666666666667632*elem.pos(1)[2]; T reg157=0.09622504486493763966*elem.pos(0)[2]; reg142=reg143+reg142;
    reg143=pow(reg144,2); T reg158=0.16666666666666667632*elem.pos(0)[2]; T reg159=0.09622504486493763966*elem.pos(1)[2]; reg146=reg141+reg146; reg141=0.09622504486493763966*elem.pos(1)[1];
    reg143=reg146+reg143; reg146=reg141+reg156; T reg160=0.096225044864937581723*elem.pos(2)[0]; T reg161=0.096225044864937581723*elem.pos(1)[1]; reg152=reg153+reg152;
    T reg162=0.096225044864937581723*elem.pos(2)[1]; reg151=reg148+reg151; T reg163=pow(reg145,2); reg154=reg155+reg154; reg155=0.16666666666666667632*elem.pos(2)[0];
    T reg164=reg150+reg149; reg147=pow(reg147,0.5); T reg165=0.096225044864937581723*elem.pos(1)[2]; reg142=pow(reg142,0.5); T reg166=0.16666666666666667632*elem.pos(2)[1];
    T reg167=0.096225044864937581723*elem.pos(2)[2]; T reg168=0.16666666666666667632*elem.pos(2)[2]; T reg169=reg159+reg158; T reg170=0.096225044864937581723*elem.pos(1)[0]; reg157=reg140+reg157;
    reg167=reg167-reg157; reg156=reg161-reg156; reg163=reg154+reg163; reg154=0.096225044864937581723*elem.pos(0)[0]; reg161=0.16666666666666667632*elem.pos(3)[1];
    reg162=reg162-reg151; T reg171=0.096225044864937581723*elem.pos(3)[1]; T reg172=reg166+reg146; reg160=reg160-reg152; T reg173=0.16666666666666667632*elem.pos(3)[0];
    T reg174=reg168+reg169; T reg175=0.096225044864937581723*elem.pos(3)[2]; reg143=pow(reg143,0.5); reg125=reg125/reg142; reg129=reg129/reg142;
    reg149=reg170-reg149; reg133=reg133/reg147; reg130=reg130/reg147; reg158=reg165-reg158; reg165=0.096225044864937581723*elem.pos(3)[0];
    reg170=reg155+reg164; T reg176=0.096225044864937581723*elem.pos(0)[1]; T reg177=0.16666666666666667632*elem.pos(3)[2]; T reg178=0.096225044864937581723*elem.pos(0)[2]; T reg179=0.14088324360345809781*elem.pos(4)[1];
    reg162=reg162-reg161; reg163=pow(reg163,0.5); T reg180=reg178-reg140; T reg181=0.09622504486493763966*elem.pos(2)[2]; reg136=reg136/reg143;
    reg135=reg135/reg143; reg165=reg165-reg170; reg167=reg167-reg177; reg117=reg15*reg117; reg116=reg18*reg116;
    T reg182=0.09622504486493763966*elem.pos(3)[2]; reg158=reg158-reg168; reg61=reg61*reg133; T reg183=0.14088324360345809781*elem.pos(4)[2]; reg122=reg65*reg122;
    reg123=reg63*reg123; reg34=reg34*reg129; reg29=reg29*reg125; T reg184=0.09622504486493763966*elem.pos(3)[0]; reg149=reg149-reg155;
    reg175=reg175-reg174; reg142=reg137/reg142; reg125=reg63*reg125; reg129=reg65*reg129; reg63=0.09622504486493763966*elem.pos(2)[0];
    reg156=reg156-reg166; reg65=0.09622504486493763966*elem.pos(3)[1]; reg137=reg154-reg153; reg133=reg15*reg133; reg147=reg126/reg147;
    reg18=reg18*reg130; reg15=0.09622504486493763966*elem.pos(2)[1]; reg130=reg67*reg130; reg171=reg171-reg172; reg67=reg176-reg148;
    reg126=0.14088324360345809781*elem.pos(4)[0]; reg160=reg160-reg173; reg130=reg61+reg130; reg29=reg34+reg29; reg34=0.52578342306320860749*elem.pos(5)[1];
    reg14=reg81*reg14; reg60=reg60*reg142; reg123=reg122+reg123; reg80=reg80*reg147; reg180=reg180-reg181;
    reg158=reg158-reg182; reg165=reg126+reg165; reg138=reg138/reg163; reg162=reg162+reg179; reg61=0.14088324360345809781*elem.pos(5)[0];
    reg122=0.52578342306320860749*elem.pos(4)[2]; reg139=reg139/reg163; reg18=reg133+reg18; reg147=reg24*reg147; reg126=reg160+reg126;
    reg171=reg179+reg171; reg137=reg137-reg63; reg133=0.52578342306320860749*elem.pos(5)[0]; reg156=reg156-reg65; reg160=0.52578342306320860749*elem.pos(4)[1];
    reg179=reg37*reg136; T reg185=reg43*reg135; reg67=reg67-reg15; reg143=reg144/reg143; reg144=0.52578342306320860749*elem.pos(5)[2];
    reg136=reg113*reg136; reg135=reg112*reg135; reg128=reg37*reg128; reg103=reg43*reg103; reg175=reg183+reg175;
    reg125=reg129+reg125; reg142=reg81*reg142; reg149=reg149-reg184; reg37=0.52578342306320860749*elem.pos(4)[0]; reg43=0.14088324360345809781*elem.pos(5)[2];
    reg183=reg167+reg183; reg35=reg24*reg35; reg24=0.14088324360345809781*elem.pos(5)[1]; reg116=reg117+reg116; reg67=reg67-reg161;
    reg183=reg144+reg183; reg81=0.52578342306320860749*elem.pos(6)[2]; reg162=reg34+reg162; reg156=reg156+reg160; reg112=0.52578342306320860749*elem.pos(6)[1];
    reg158=reg158+reg122; reg180=reg180-reg177; reg171=reg24+reg171; reg175=reg43+reg175; reg113=reg90*reg139;
    reg149=reg149+reg37; reg163=reg145/reg163; reg118=reg118*reg138; reg139=reg121*reg139; reg35=reg116+reg35;
    reg128=reg103+reg128; reg104=reg44*reg104; reg132=reg88*reg132; reg127=reg90*reg127; reg90=0.52578342306320860749*elem.pos(6)[0];
    reg136=reg135+reg136; reg126=reg133+reg126; reg100=reg100*reg143; reg179=reg185+reg179; reg143=reg44*reg143;
    reg137=reg137-reg173; reg165=reg61+reg165; reg14=reg123+reg14; reg147=reg18+reg147; reg80=reg130+reg80;
    reg60=reg29+reg60; reg142=reg125+reg142; reg138=reg88*reg138; reg18=0.14088324360345809781*elem.pos(6)[1]; reg156=reg34+reg156;
    reg143=reg179+reg143; reg80=reg35*reg80; reg100=reg136+reg100; reg67=reg160+reg67; reg180=reg122+reg180;
    reg147=reg131*reg147; reg29=0.14088324360345809781*elem.pos(6)[2]; reg158=reg144+reg158; reg165=reg90+reg165; reg90=reg126+reg90;
    reg104=reg128+reg104; reg34=0.52578342306320860749*elem.pos(7)[0]; reg35=0.14088324360345809781*elem.pos(7)[0]; reg44=0.52578342306320860749*elem.pos(7)[2]; reg88=0.14088324360345809781*elem.pos(6)[0];
    reg183=reg183+reg81; reg175=reg81+reg175; reg81=0.14088324360345809781*elem.pos(7)[2]; reg60=reg14*reg60; reg149=reg133+reg149;
    reg142=reg114*reg142; reg118=reg139+reg118; reg137=reg37+reg137; reg171=reg112+reg171; reg14=reg5*reg163;
    reg110=reg5*reg110; reg5=0.52578342306320860749*elem.pos(7)[1]; reg112=reg162+reg112; reg163=reg124*reg163; reg132=reg127+reg132;
    reg138=reg113+reg138; reg37=0.14088324360345809781*elem.pos(7)[1]; reg158=reg158+reg29; reg149=reg149+reg88; reg14=reg138+reg14;
    reg175=reg175+reg44; reg90=reg90+reg35; reg67=reg24+reg67; reg110=reg132+reg110; reg112=reg112+reg37;
    reg137=reg61+reg137; reg100=reg104*reg100; reg180=reg43+reg180; reg183=reg183+reg81; reg156=reg156+reg18;
    reg171=reg171+reg5; reg143=reg36*reg143; reg163=reg118+reg163; reg147=reg80-reg147; reg142=reg60-reg142;
    reg165=reg165+reg34; reg183=reg147*reg183; reg163=reg110*reg163; reg149=reg35+reg149; reg165=reg165*reg142;
    reg112=reg147*reg112; reg158=reg81+reg158; reg14=reg134*reg14; reg67=reg18+reg67; reg175=reg142*reg175;
    reg137=reg88+reg137; reg156=reg37+reg156; reg171=reg142*reg171; reg143=reg100-reg143; reg90=reg90*reg147;
    reg180=reg29+reg180; reg158=reg143*reg158; reg175=0.25*reg175; reg90=0.25*reg90; reg142=0.25*reg142;
    reg165=0.25*reg165; reg183=0.25*reg183; reg112=0.25*reg112; reg147=0.25*reg147; reg14=reg163-reg14;
    reg67=reg5+reg67; reg137=reg34+reg137; reg156=reg143*reg156; reg149=reg149*reg143; reg180=reg44+reg180;
    reg171=0.25*reg171; reg158=0.25*reg158; reg137=reg137*reg14; reg180=reg14*reg180; reg171=reg112+reg171;
    reg149=0.25*reg149; reg156=0.25*reg156; reg67=reg14*reg67; reg165=reg90+reg165; reg142=reg147+reg142;
    reg143=0.25*reg143; reg175=reg183+reg175; reg180=0.25*reg180; reg149=reg165+reg149; reg143=reg142+reg143;
    reg156=reg171+reg156; reg67=0.25*reg67; reg158=reg175+reg158; reg14=0.25*reg14; reg137=0.25*reg137;
    reg67=reg156+reg67; reg137=reg149+reg137; reg14=reg143+reg14; reg180=reg158+reg180; res[2]=reg180/reg14;
    res[1]=reg67/reg14; res[0]=reg137/reg14;

    return res;
}
}
#endif // LMT_QUAD_8
