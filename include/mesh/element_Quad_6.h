#ifndef LMT_QUAD_6
#define LMT_QUAD_6
#include "node.h"
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
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=reg0-var_inter[0]; T reg3=reg0+reg1; T reg4=var_inter[0]-0.5;
    reg2=4*reg2; T reg5=2*reg3; T reg6=reg4+var_inter[0]; T reg7=reg0*var_inter[0]; reg1=reg0*reg1;
    reg0=1-var_inter[1]; reg6=2*reg6; reg1=2*reg1; T reg8=reg0*reg2; reg7=4*reg7;
    reg4=reg4*var_inter[0]; T reg9=reg0*reg5; T reg10=reg7*pos_nodes[4][0]; T reg11=pos_nodes[0][0]*reg1; T reg12=pos_nodes[4][1]*reg8;
    T reg13=pos_nodes[0][1]*reg9; T reg14=reg0*reg6; T reg15=pos_nodes[4][0]*reg8; T reg16=pos_nodes[0][0]*reg9; T reg17=reg7*pos_nodes[4][1];
    T reg18=pos_nodes[0][1]*reg1; reg4=2*reg4; reg11=reg10+reg11; reg10=pos_nodes[1][0]*reg4; T reg19=pos_nodes[1][0]*reg14;
    reg16=reg15-reg16; reg15=reg0*reg7; reg13=reg12-reg13; reg12=pos_nodes[1][1]*reg14; T reg20=var_inter[1]*reg5;
    T reg21=pos_nodes[1][1]*reg4; reg18=reg17+reg18; reg17=reg0*reg1; reg21=reg18+reg21; reg18=reg15*pos_nodes[4][1];
    T reg22=pos_nodes[0][1]*reg17; T reg23=pos_nodes[0][0]*reg17; T reg24=reg15*pos_nodes[4][0]; reg10=reg11+reg10; reg11=reg1*pos_nodes[3][1];
    reg12=reg13+reg12; reg13=pos_nodes[3][1]*reg20; T reg25=reg1*pos_nodes[3][0]; reg0=reg0*reg4; T reg26=pos_nodes[3][0]*reg20;
    reg2=var_inter[1]*reg2; reg19=reg16+reg19; reg16=pos_nodes[1][1]*reg0; reg22=reg18+reg22; reg6=var_inter[1]*reg6;
    reg13=reg12-reg13; reg12=pos_nodes[5][1]*reg2; reg18=reg7*pos_nodes[5][1]; T reg27=var_inter[1]*reg1; reg21=reg11-reg21;
    reg10=reg25-reg10; reg11=pos_nodes[1][0]*reg0; reg23=reg24+reg23; reg26=reg19-reg26; reg19=pos_nodes[5][0]*reg2;
    reg24=reg7*pos_nodes[5][0]; reg25=pos_nodes[2][0]*reg6; reg19=reg26+reg19; reg26=var_inter[1]*reg7; reg24=reg10+reg24;
    reg18=reg21+reg18; reg10=pos_nodes[2][1]*reg6; reg12=reg13+reg12; reg13=pos_nodes[2][0]*reg4; reg21=pos_nodes[2][1]*reg4;
    reg11=reg23+reg11; reg23=reg27*pos_nodes[3][0]; T reg28=reg27*pos_nodes[3][1]; reg16=reg22+reg16; reg28=reg16+reg28;
    reg21=reg18+reg21; reg16=reg26*pos_nodes[5][1]; reg18=var_inter[1]*reg4; reg10=reg12+reg10; reg12=reg26*pos_nodes[5][0];
    reg23=reg11+reg23; reg13=reg24+reg13; reg25=reg19+reg25; reg11=reg13*reg10; reg19=reg25*reg21;
    reg22=pos_nodes[2][0]*reg18; reg12=reg23+reg12; reg16=reg28+reg16; reg23=pos_nodes[2][1]*reg18; reg11=reg19-reg11;
    reg23=reg16+reg23; reg22=reg12+reg22; reg23=pos[1]-reg23; reg22=pos[0]-reg22; reg12=reg21/reg11;
    reg16=reg10/reg11; reg24=reg13/reg11; reg11=reg25/reg11; reg12=reg22*reg12; reg24=reg23*reg24;
    reg16=reg22*reg16; reg11=reg23*reg11; var_inter[0]=reg12-reg24; var_inter[1]=reg11-reg16;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=reg0-var_inter[0]; T reg3=reg1+reg0; T reg4=var_inter[0]-0.5;
    reg2=4*reg2; T reg5=2*reg3; reg1=reg1*reg0; T reg6=reg4+var_inter[0]; T reg7=1-var_inter[1];
    reg0=reg0*var_inter[0]; T reg8=reg7*reg2; T reg9=reg7*reg5; reg1=2*reg1; reg6=2*reg6;
    reg4=reg4*var_inter[0]; reg0=4*reg0; T reg10=reg7*reg6; T reg11=pos_nodes[4][0]*reg8; T reg12=pos_nodes[0][0]*reg9;
    T reg13=pos_nodes[0][1]*reg9; T reg14=pos_nodes[4][1]*reg8; T reg15=pos_nodes[0][0]*reg1; T reg16=pos_nodes[4][0]*reg0; T reg17=pos_nodes[4][1]*reg0;
    T reg18=pos_nodes[0][1]*reg1; reg4=2*reg4; T reg19=reg4*pos_nodes[1][1]; T reg20=pos_nodes[1][0]*reg10; reg12=reg11-reg12;
    reg13=reg14-reg13; reg11=pos_nodes[1][1]*reg10; reg14=var_inter[1]*reg5; T reg21=reg7*reg1; reg18=reg17+reg18;
    reg17=reg0*reg7; reg15=reg16+reg15; reg16=pos_nodes[1][0]*reg4; reg16=reg15+reg16; reg15=pos_nodes[4][1]*reg17;
    T reg22=pos_nodes[0][1]*reg21; T reg23=pos_nodes[4][0]*reg17; T reg24=pos_nodes[0][0]*reg21; reg19=reg18+reg19; reg18=pos_nodes[3][1]*reg1;
    reg11=reg13+reg11; reg13=pos_nodes[3][1]*reg14; T reg25=pos_nodes[3][0]*reg14; reg20=reg12+reg20; reg2=var_inter[1]*reg2;
    reg7=reg4*reg7; reg12=pos_nodes[3][0]*reg1; T reg26=reg0*pos_nodes[5][1]; reg19=reg18-reg19; reg18=reg1*var_inter[1];
    T reg27=pos_nodes[5][1]*reg2; reg13=reg11-reg13; reg22=reg15+reg22; reg6=var_inter[1]*reg6; reg11=reg7*pos_nodes[1][1];
    reg16=reg12-reg16; reg12=reg0*pos_nodes[5][0]; reg15=reg7*pos_nodes[1][0]; reg24=reg23+reg24; reg23=pos_nodes[5][0]*reg2;
    reg25=reg20-reg25; reg20=reg18*pos_nodes[3][1]; reg11=reg22+reg11; reg22=pos_nodes[2][0]*reg6; reg23=reg25+reg23;
    reg25=reg4*pos_nodes[2][1]; reg26=reg19+reg26; reg12=reg16+reg12; reg16=reg0*var_inter[1]; reg19=reg4*pos_nodes[2][0];
    T reg28=pos_nodes[2][1]*reg6; reg27=reg13+reg27; reg13=reg18*pos_nodes[3][0]; reg15=reg24+reg15; reg22=reg23+reg22;
    reg23=reg16*pos_nodes[5][0]; reg25=reg26+reg25; reg13=reg15+reg13; reg15=reg16*pos_nodes[5][1]; reg20=reg11+reg20;
    reg11=reg4*var_inter[1]; reg19=reg12+reg19; reg28=reg27+reg28; reg15=reg20+reg15; reg12=reg11*pos_nodes[2][1];
    reg20=reg22*reg25; reg24=reg19*reg28; reg23=reg13+reg23; reg13=reg11*pos_nodes[2][0]; reg24=reg20-reg24;
    reg12=reg15+reg12; reg13=reg23+reg13; reg12=pos[1]-reg12; reg13=pos[0]-reg13; reg15=reg25/reg24;
    reg23=reg28/reg24; reg26=reg19/reg24; reg24=reg22/reg24; reg15=reg13*reg15; reg26=reg12*reg26;
    reg23=reg13*reg23; reg24=reg12*reg24; var_inter[0]+=reg15-reg26; var_inter[1]+=reg24-reg23;

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
    T reg0=0.5-var_inter[0]; T reg1=1-var_inter[0]; T reg2=var_inter[0]-0.5; T reg3=var_inter[0]*reg1; reg0=reg1*reg0;
    reg0=2*reg0; reg3=4*reg3; reg2=var_inter[0]*reg2; reg1=1-var_inter[1]; T reg4=reg0*reg1;
    T reg5=reg3*reg1; reg2=2*reg2; reg4=val[0]*reg4; reg1=reg2*reg1; reg5=val[4]*reg5;
    reg0=var_inter[1]*reg0; reg1=val[1]*reg1; reg5=reg4+reg5; reg0=val[3]*reg0; reg3=var_inter[1]*reg3;
    reg1=reg5+reg1; reg0=reg1+reg0; reg3=val[5]*reg3; reg2=var_inter[1]*reg2; reg3=reg0+reg3;
    reg2=val[2]*reg2; res=reg3+reg2;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    T reg4=reg3*reg1; res[4]=reg4; T reg5=reg2*reg1; res[0]=reg5; reg1=reg0*reg1;
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

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Quad_6,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=0.5-var_inter[0]; T reg1=1-var_inter[0]; T reg2=reg1+reg0; T reg3=reg1-var_inter[0]; T reg4=var_inter[0]-0.5;
    reg3=4*reg3; T reg5=2*reg2; T reg6=1-var_inter[1]; T reg7=var_inter[0]+reg4; T reg8=reg6*reg3;
    T reg9=reg6*reg5; reg7=2*reg7; T reg10=elem.pos(0)[1]*reg9; T reg11=elem.pos(4)[1]*reg8; T reg12=elem.pos(0)[0]*reg9;
    T reg13=elem.pos(4)[0]*reg8; T reg14=reg6*reg7; reg13=reg13-reg12; T reg15=var_inter[1]*reg5; T reg16=elem.pos(1)[0]*reg14;
    T reg17=elem.pos(1)[1]*reg14; T reg18=elem.pos(0)[2]*reg9; reg11=reg11-reg10; reg8=elem.pos(4)[2]*reg8; reg14=elem.pos(1)[2]*reg14;
    reg8=reg8-reg18; reg3=var_inter[1]*reg3; T reg19=elem.pos(3)[0]*reg15; T reg20=elem.pos(3)[1]*reg15; reg16=reg13+reg16;
    reg11=reg17+reg11; reg11=reg11-reg20; reg14=reg8+reg14; reg8=elem.pos(3)[2]*reg15; reg13=elem.pos(5)[0]*reg3;
    reg16=reg16-reg19; reg7=var_inter[1]*reg7; reg0=reg1*reg0; reg17=elem.pos(5)[1]*reg3; reg1=var_inter[0]*reg1;
    reg11=reg17+reg11; reg3=elem.pos(5)[2]*reg3; reg14=reg14-reg8; reg4=var_inter[0]*reg4; reg1=4*reg1;
    reg0=2*reg0; reg17=elem.pos(2)[1]*reg7; reg13=reg16+reg13; reg16=elem.pos(2)[0]*reg7; reg7=elem.pos(2)[2]*reg7;
    T reg21=elem.pos(0)[0]*reg0; T reg22=elem.pos(4)[1]*reg1; T reg23=elem.pos(4)[0]*reg1; reg17=reg11+reg17; reg13=reg16+reg13;
    reg4=2*reg4; reg11=elem.pos(0)[1]*reg0; reg14=reg3+reg14; reg3=elem.pos(1)[0]*reg4; reg16=elem.pos(0)[2]*reg0;
    T reg24=reg23+reg21; T reg25=pow(reg17,2); T reg26=elem.pos(4)[2]*reg1; T reg27=pow(reg13,2); T reg28=reg11+reg22;
    reg7=reg14+reg7; reg14=elem.pos(1)[1]*reg4; T reg29=pow(reg7,2); T reg30=elem.pos(3)[1]*reg0; reg25=reg27+reg25;
    reg27=reg24+reg3; T reg31=elem.pos(3)[0]*reg0; T reg32=reg14+reg28; T reg33=elem.pos(1)[2]*reg4; T reg34=reg26+reg16;
    T reg35=reg34+reg33; reg30=reg30-reg32; T reg36=reg1*elem.pos(5)[1]; T reg37=reg1*elem.pos(5)[0]; reg31=reg31-reg27;
    reg25=reg29+reg25; reg29=elem.pos(3)[2]*reg0; reg36=reg30+reg36; reg30=elem.pos(2)[0]*reg4; reg37=reg31+reg37;
    reg31=reg1*elem.pos(5)[2]; reg25=pow(reg25,0.5); reg29=reg29-reg35; T reg38=elem.pos(2)[1]*reg4; reg30=reg37+reg30;
    reg37=elem.pos(2)[2]*reg4; T reg39=reg13/reg25; T reg40=reg17/reg25; reg36=reg38+reg36; reg31=reg29+reg31;
    reg29=reg40*reg36; reg25=reg7/reg25; reg37=reg31+reg37; reg31=reg39*reg30; reg31=reg29+reg31;
    reg29=reg25*reg37; reg29=reg31+reg29; reg31=reg40*reg29; reg38=reg39*reg29; T reg41=reg25*reg29;
    reg38=reg30-reg38; reg31=reg36-reg31; reg41=reg37-reg41; T reg42=pow(reg38,2); T reg43=pow(reg31,2);
    T reg44=pow(reg41,2); reg43=reg42+reg43; reg44=reg43+reg44; reg44=pow(reg44,0.5); reg31=reg31/reg44;
    reg38=reg38/reg44; reg40=reg40*reg17; reg17=reg31*reg17; reg42=reg38*reg13; reg36=reg31*reg36;
    reg38=reg30*reg38; reg13=reg39*reg13; reg44=reg41/reg44; reg40=reg13+reg40; reg25=reg7*reg25;
    reg37=reg44*reg37; reg44=reg7*reg44; reg17=reg42+reg17; reg36=reg38+reg36; reg37=reg36+reg37;
    reg25=reg40+reg25; reg44=reg17+reg44; reg7=reg29*reg44; reg13=reg25*reg37; reg7=reg13-reg7;
    return reg7;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Quad_6,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.48803387171258487271*elem.pos(4)[0]; T reg1=0.032692070451105301881*elem.pos(0)[0]; T reg2=0.66666666666666670528*elem.pos(4)[1]; T reg3=0.12200846792814621818*elem.pos(0)[1]; T reg4=0.48803387171258487271*elem.pos(4)[1];
    T reg5=0.032692070451105301881*elem.pos(0)[1]; T reg6=0.12200846792814621818*elem.pos(0)[0]; T reg7=0.66666666666666670528*elem.pos(4)[0]; T reg8=0.45534180126147951289*elem.pos(0)[0]; T reg9=0.45534180126147957081*elem.pos(0)[0];
    T reg10=0.45534180126147957081*elem.pos(0)[1]; T reg11=0.45534180126147951289*elem.pos(0)[1]; reg8=reg7+reg8; T reg12=0.12200846792814621818*elem.pos(1)[0]; reg10=reg4-reg10;
    T reg13=0.032692070451105301881*elem.pos(1)[1]; T reg14=0.45534180126147951289*elem.pos(1)[1]; T reg15=0.12200846792814621818*elem.pos(1)[1]; T reg16=reg2-reg3; T reg17=0.45534180126147957081*elem.pos(1)[1];
    T reg18=0.032692070451105301881*elem.pos(1)[0]; reg9=reg0-reg9; T reg19=reg5-reg4; T reg20=1.8213672050459180516*elem.pos(4)[0]; reg7=reg7-reg6;
    T reg21=0.12200846792814616024*elem.pos(0)[0]; T reg22=0.45534180126147951289*elem.pos(1)[0]; T reg23=0.12200846792814616024*elem.pos(0)[1]; T reg24=1.8213672050459180516*elem.pos(4)[1]; T reg25=0.45534180126147957081*elem.pos(1)[0];
    T reg26=reg1-reg0; reg11=reg2+reg11; reg2=0.025783423063208590757*elem.pos(0)[0]; T reg27=1.6993587371177718913*elem.pos(0)[1]; T reg28=0.096225044864937627422*elem.pos(0)[0];
    T reg29=0.14088324360345809781*elem.pos(4)[0]; T reg30=reg21-reg20; T reg31=1.6993587371177718913*elem.pos(1)[0]; reg22=reg7+reg22; reg7=0.12200846792814621818*elem.pos(3)[0];
    reg9=reg9-reg18; T reg32=1.6993587371177718913*elem.pos(3)[0]; T reg33=1.6993587371177718913*elem.pos(0)[0]; T reg34=0.45534180126147951289*elem.pos(3)[1]; reg11=reg11-reg15;
    reg10=reg10-reg13; T reg35=1.6993587371177718913*elem.pos(3)[1]; reg8=reg8-reg12; T reg36=0.45534180126147951289*elem.pos(3)[0]; T reg37=reg23-reg24;
    T reg38=0.096225044864937627422*elem.pos(0)[1]; reg16=reg14+reg16; reg14=0.025783423063208590757*elem.pos(0)[1]; T reg39=0.14088324360345809781*elem.pos(4)[1]; T reg40=0.12200846792814621818*elem.pos(3)[1];
    T reg41=1.6993587371177718913*elem.pos(1)[1]; reg19=reg17+reg19; reg17=0.12200846792814616024*elem.pos(3)[1]; T reg42=0.12200846792814616024*elem.pos(3)[0]; reg25=reg26+reg25;
    reg26=0.66666666666666670528*elem.pos(5)[1]; reg16=reg40+reg16; reg32=reg9-reg32; reg9=0.52578342306320860749*elem.pos(4)[1]; T reg43=reg39-reg14;
    reg25=reg25+reg42; T reg44=0.12200846792814616024*elem.pos(1)[0]; reg11=reg34-reg11; reg33=reg20-reg33; reg8=reg36-reg8;
    reg35=reg10-reg35; reg10=0.096225044864937627422*elem.pos(1)[1]; reg34=1.8213672050459180516*elem.pos(5)[0]; reg36=0.66666666666666670528*elem.pos(5)[0]; reg37=reg41+reg37;
    reg22=reg7+reg22; reg41=reg29-reg2; reg19=reg19+reg17; T reg45=0.032692070451105301881*elem.pos(3)[1]; reg29=reg29+reg28;
    T reg46=0.025783423063208590757*elem.pos(1)[0]; T reg47=0.52578342306320860749*elem.pos(4)[0]; T reg48=0.096225044864937627422*elem.pos(1)[0]; T reg49=1.8213672050459180516*elem.pos(5)[1]; T reg50=0.032692070451105301881*elem.pos(3)[0];
    reg27=reg24-reg27; T reg51=0.12200846792814616024*elem.pos(1)[1]; T reg52=0.025783423063208590757*elem.pos(1)[1]; reg39=reg39+reg38; reg31=reg30+reg31;
    reg37=reg37+reg45; reg30=0.48803387171258487271*elem.pos(5)[1]; T reg53=0.35911675639654188548*elem.pos(0)[0]; reg8=reg36+reg8; T reg54=0.12200846792814621818*elem.pos(2)[0];
    T reg55=0.35911675639654188548*elem.pos(1)[0]; T reg56=reg47-reg28; T reg57=reg9-reg38; T reg58=0.35911675639654188548*elem.pos(1)[1]; T reg59=0.35911675639654188548*elem.pos(0)[1];
    T reg60=0.48803387171258487271*elem.pos(5)[0]; reg31=reg31+reg50; T reg61=reg26-reg16; T reg62=0.45534180126147951289*elem.pos(2)[1]; reg19=reg19-reg49;
    T reg63=1.6993587371177718913*elem.pos(2)[1]; reg36=reg36-reg22; T reg64=0.45534180126147951289*elem.pos(2)[0]; reg39=reg39-reg52; T reg65=0.35911675639654188548*elem.pos(3)[1];
    T reg66=1.6993587371177718913*elem.pos(2)[0]; reg25=reg25-reg34; reg43=reg10+reg43; T reg67=0.096225044864937627422*elem.pos(3)[1]; T reg68=0.096225044864937627422*elem.pos(3)[0];
    reg41=reg41+reg48; T reg69=0.45534180126147957081*elem.pos(3)[1]; reg29=reg29-reg46; T reg70=0.35911675639654188548*elem.pos(3)[0]; reg27=reg27-reg51;
    reg32=reg34+reg32; T reg71=0.12200846792814616024*elem.pos(2)[0]; reg11=reg26+reg11; reg26=0.12200846792814621818*elem.pos(2)[1]; T reg72=0.45534180126147957081*elem.pos(3)[0];
    reg33=reg33-reg44; reg35=reg49+reg35; T reg73=0.12200846792814616024*elem.pos(2)[1]; reg43=reg43-reg67; T reg74=0.52578342306320860749*elem.pos(5)[1];
    reg37=reg37-reg30; T reg75=0.45534180126147957081*elem.pos(2)[1]; T reg76=0.025783423063208590757*elem.pos(3)[1]; reg57=reg58+reg57; reg65=reg39+reg65;
    reg53=reg47+reg53; reg69=reg27-reg69; reg72=reg33-reg72; reg64=reg36+reg64; reg63=reg19+reg63;
    reg70=reg29+reg70; reg62=reg61+reg62; reg32=reg32-reg71; reg11=reg11-reg26; reg35=reg35-reg73;
    reg8=reg8-reg54; reg59=reg9+reg59; reg66=reg25+reg66; reg55=reg56+reg55; reg9=0.025783423063208590757*elem.pos(3)[0];
    reg41=reg41-reg68; reg19=0.45534180126147957081*elem.pos(2)[0]; reg25=0.52578342306320860749*elem.pos(5)[0]; reg31=reg31-reg60; reg63=reg63*reg64;
    reg65=reg74+reg65; reg27=0.096225044864937627422*elem.pos(2)[1]; reg19=reg31+reg19; reg29=0.032692070451105301881*elem.pos(2)[1]; reg69=reg30+reg69;
    reg66=reg66*reg62; reg59=reg59-reg10; reg70=reg25+reg70; reg31=0.096225044864937627422*elem.pos(2)[0]; reg33=0.35911675639654188548*elem.pos(2)[1];
    reg36=0.032692070451105301881*elem.pos(2)[0]; reg72=reg60+reg72; reg25=reg41+reg25; reg32=reg32*reg11; reg75=reg37+reg75;
    reg37=0.35911675639654188548*elem.pos(2)[0]; reg35=reg35*reg8; reg74=reg43+reg74; reg39=0.14088324360345809781*elem.pos(5)[1]; reg57=reg57-reg76;
    reg53=reg53-reg48; reg41=0.14088324360345809781*elem.pos(5)[0]; reg55=reg55-reg9; reg33=reg74+reg33; reg37=reg25+reg37;
    reg19=reg62*reg19; reg57=reg57+reg39; reg55=reg55+reg41; reg75=reg64*reg75; reg53=reg68+reg53;
    reg35=reg32-reg35; reg72=reg72-reg36; reg70=reg70-reg31; reg59=reg67+reg59; reg69=reg69-reg29;
    reg65=reg65-reg27; reg63=reg66-reg63; reg65=reg35*reg65; reg33=reg63*reg33; reg57=reg27+reg57;
    reg59=reg39+reg59; reg25=0.025783423063208590757*elem.pos(2)[1]; reg37=reg37*reg63; reg70=reg70*reg35; reg55=reg31+reg55;
    reg75=reg19-reg75; reg53=reg41+reg53; reg19=0.025783423063208590757*elem.pos(2)[0]; reg69=reg8*reg69; reg72=reg11*reg72;
    reg63=0.25*reg63; reg37=0.25*reg37; reg70=0.25*reg70; reg57=reg75*reg57; reg55=reg55*reg75;
    reg53=reg53-reg19; reg65=0.25*reg65; reg69=reg72-reg69; reg33=0.25*reg33; reg59=reg59-reg25;
    reg35=0.25*reg35; reg59=reg69*reg59; reg57=0.25*reg57; reg75=0.25*reg75; reg70=reg37+reg70;
    reg35=reg63+reg35; reg55=0.25*reg55; reg53=reg53*reg69; reg65=reg33+reg65; reg55=reg70+reg55;
    reg53=0.25*reg53; reg57=reg65+reg57; reg75=reg35+reg75; reg69=0.25*reg69; reg59=0.25*reg59;
    reg59=reg57+reg59; reg53=reg55+reg53; reg69=reg75+reg69; res[0]=reg53/reg69; res[1]=reg59/reg69;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Quad_6,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.48803387171258487271*elem.pos(4)[1]; T reg1=0.032692070451105301881*elem.pos(0)[1]; T reg2=0.032692070451105301881*elem.pos(0)[0]; T reg3=0.48803387171258487271*elem.pos(4)[0]; T reg4=0.45534180126147957081*elem.pos(0)[0];
    T reg5=0.45534180126147957081*elem.pos(0)[1]; reg4=reg3-reg4; T reg6=reg1-reg0; T reg7=0.45534180126147957081*elem.pos(1)[0]; T reg8=reg2-reg3;
    T reg9=0.032692070451105301881*elem.pos(1)[0]; T reg10=0.45534180126147957081*elem.pos(1)[1]; T reg11=0.48803387171258487271*elem.pos(4)[2]; T reg12=0.032692070451105301881*elem.pos(0)[2]; T reg13=0.12200846792814616024*elem.pos(0)[1];
    T reg14=1.8213672050459180516*elem.pos(4)[1]; T reg15=0.032692070451105301881*elem.pos(1)[1]; T reg16=0.45534180126147957081*elem.pos(0)[2]; T reg17=1.8213672050459180516*elem.pos(4)[0]; reg5=reg0-reg5;
    T reg18=0.12200846792814616024*elem.pos(0)[0]; T reg19=1.6993587371177718913*elem.pos(3)[0]; reg5=reg5-reg15; T reg20=1.6993587371177718913*elem.pos(3)[1]; reg4=reg4-reg9;
    reg16=reg11-reg16; T reg21=0.032692070451105301881*elem.pos(1)[2]; T reg22=reg18-reg17; reg10=reg6+reg10; reg6=0.12200846792814616024*elem.pos(3)[1];
    T reg23=0.12200846792814616024*elem.pos(0)[2]; T reg24=1.8213672050459180516*elem.pos(4)[2]; T reg25=1.6993587371177718913*elem.pos(1)[0]; T reg26=reg13-reg14; T reg27=reg12-reg11;
    T reg28=0.45534180126147957081*elem.pos(1)[2]; T reg29=1.6993587371177718913*elem.pos(1)[1]; T reg30=1.6993587371177718913*elem.pos(0)[0]; T reg31=0.12200846792814616024*elem.pos(3)[0]; reg7=reg8+reg7;
    reg8=1.6993587371177718913*elem.pos(0)[1]; T reg32=1.6993587371177718913*elem.pos(0)[2]; reg28=reg27+reg28; reg27=0.12200846792814616024*elem.pos(3)[2]; reg20=reg5-reg20;
    reg16=reg16-reg21; reg5=0.032692070451105301881*elem.pos(3)[1]; reg29=reg26+reg29; reg26=1.6993587371177718913*elem.pos(3)[2]; T reg33=0.12200846792814616024*elem.pos(1)[1];
    reg8=reg14-reg8; T reg34=0.032692070451105301881*elem.pos(3)[0]; reg25=reg22+reg25; reg22=1.8213672050459180516*elem.pos(5)[0]; T reg35=0.12200846792814616024*elem.pos(1)[0];
    T reg36=1.6993587371177718913*elem.pos(1)[2]; reg7=reg7+reg31; reg19=reg4-reg19; reg10=reg10+reg6; reg4=1.8213672050459180516*elem.pos(5)[1];
    T reg37=reg23-reg24; reg30=reg17-reg30; reg19=reg22+reg19; T reg38=0.12200846792814616024*elem.pos(2)[0]; T reg39=0.12200846792814616024*elem.pos(2)[1];
    reg26=reg16-reg26; reg20=reg4+reg20; reg16=0.45534180126147957081*elem.pos(3)[0]; reg30=reg30-reg35; reg7=reg7-reg22;
    T reg40=1.6993587371177718913*elem.pos(2)[0]; reg36=reg37+reg36; reg37=0.032692070451105301881*elem.pos(3)[2]; reg10=reg10-reg4; T reg41=1.6993587371177718913*elem.pos(2)[1];
    T reg42=0.12200846792814616024*elem.pos(1)[2]; reg32=reg24-reg32; reg28=reg28+reg27; T reg43=1.8213672050459180516*elem.pos(5)[2]; T reg44=0.48803387171258487271*elem.pos(5)[1];
    reg25=reg25+reg34; T reg45=0.48803387171258487271*elem.pos(5)[0]; reg8=reg8-reg33; T reg46=0.45534180126147957081*elem.pos(3)[1]; reg29=reg29+reg5;
    reg16=reg30-reg16; reg25=reg25-reg45; reg30=0.45534180126147957081*elem.pos(2)[0]; reg36=reg36+reg37; T reg47=0.48803387171258487271*elem.pos(5)[2];
    T reg48=0.45534180126147951289*elem.pos(0)[1]; T reg49=0.45534180126147951289*elem.pos(0)[0]; reg19=reg19-reg38; T reg50=0.45534180126147957081*elem.pos(3)[2]; reg32=reg32-reg42;
    T reg51=0.12200846792814616024*elem.pos(2)[2]; reg26=reg43+reg26; reg46=reg8-reg46; reg29=reg29-reg44; reg20=reg20-reg39;
    reg8=0.45534180126147957081*elem.pos(2)[1]; reg41=reg10+reg41; reg40=reg7+reg40; reg28=reg28-reg43; reg7=1.6993587371177718913*elem.pos(2)[2];
    reg10=0.66666666666666670528*elem.pos(4)[0]; T reg52=0.12200846792814621818*elem.pos(0)[0]; T reg53=0.66666666666666670528*elem.pos(4)[1]; T reg54=0.12200846792814621818*elem.pos(0)[1]; reg8=reg29+reg8;
    reg29=0.12200846792814621818*elem.pos(1)[1]; reg48=reg53+reg48; T reg55=0.12200846792814621818*elem.pos(1)[0]; reg7=reg28+reg7; reg30=reg25+reg30;
    reg49=reg10+reg49; reg25=0.45534180126147951289*elem.pos(0)[2]; reg28=0.66666666666666670528*elem.pos(4)[2]; T reg56=0.12200846792814621818*elem.pos(0)[2]; T reg57=pow(reg19,2);
    reg10=reg10-reg52; T reg58=0.45534180126147951289*elem.pos(1)[0]; T reg59=0.45534180126147951289*elem.pos(1)[1]; T reg60=pow(reg20,2); reg53=reg53-reg54;
    reg26=reg26-reg51; T reg61=pow(reg41,2); reg16=reg45+reg16; T reg62=pow(reg40,2); reg36=reg36-reg47;
    T reg63=0.45534180126147957081*elem.pos(2)[2]; T reg64=0.032692070451105301881*elem.pos(2)[0]; reg50=reg32-reg50; reg32=0.032692070451105301881*elem.pos(2)[1]; reg46=reg44+reg46;
    T reg65=0.032692070451105301881*elem.pos(2)[2]; reg50=reg47+reg50; reg58=reg10+reg58; reg59=reg53+reg59; reg60=reg57+reg60;
    reg46=reg46-reg32; reg10=0.12200846792814621818*elem.pos(3)[1]; reg53=pow(reg26,2); reg57=0.12200846792814621818*elem.pos(1)[2]; reg25=reg28+reg25;
    T reg66=0.45534180126147951289*elem.pos(3)[0]; reg16=reg16-reg64; reg49=reg49-reg55; T reg67=0.45534180126147951289*elem.pos(3)[1]; reg48=reg48-reg29;
    T reg68=pow(reg30,2); T reg69=0.12200846792814621818*elem.pos(3)[0]; T reg70=pow(reg7,2); reg63=reg36+reg63; reg36=pow(reg8,2);
    T reg71=0.45534180126147951289*elem.pos(1)[2]; reg28=reg28-reg56; reg61=reg62+reg61; reg48=reg67-reg48; reg49=reg66-reg49;
    reg58=reg69+reg58; reg36=reg68+reg36; reg70=reg61+reg70; reg61=0.66666666666666670528*elem.pos(5)[0]; reg62=0.45534180126147951289*elem.pos(3)[2];
    reg66=pow(reg16,2); reg25=reg25-reg57; reg53=reg60+reg53; reg60=pow(reg63,2); reg67=0.12200846792814621818*elem.pos(3)[2];
    reg50=reg50-reg65; reg68=0.66666666666666670528*elem.pos(5)[1]; reg59=reg10+reg59; T reg72=pow(reg46,2); reg71=reg28+reg71;
    reg28=pow(reg50,2); T reg73=0.45534180126147951289*elem.pos(2)[1]; T reg74=reg68-reg59; reg48=reg68+reg48; reg68=0.12200846792814621818*elem.pos(2)[0];
    reg49=reg61+reg49; reg71=reg67+reg71; reg72=reg66+reg72; reg70=pow(reg70,0.5); reg66=0.12200846792814621818*elem.pos(2)[1];
    T reg75=0.66666666666666670528*elem.pos(5)[2]; reg25=reg62-reg25; reg53=pow(reg53,0.5); reg60=reg36+reg60; reg61=reg61-reg58;
    reg36=0.45534180126147951289*elem.pos(2)[0]; reg48=reg48-reg66; reg62=reg40/reg70; T reg76=reg41/reg70; reg60=pow(reg60,0.5);
    T reg77=0.12200846792814621818*elem.pos(2)[2]; reg28=reg72+reg28; reg25=reg75+reg25; reg72=0.45534180126147951289*elem.pos(2)[2]; reg49=reg49-reg68;
    reg75=reg75-reg71; T reg78=reg20/reg53; reg73=reg74+reg73; reg74=reg19/reg53; reg36=reg61+reg36;
    reg72=reg75+reg72; reg61=reg8/reg60; reg28=pow(reg28,0.5); reg75=reg30/reg60; reg70=reg7/reg70;
    T reg79=reg76*reg73; reg25=reg25-reg77; T reg80=reg74*reg49; T reg81=reg78*reg48; reg53=reg26/reg53;
    T reg82=reg62*reg36; T reg83=reg46/reg28; T reg84=reg16/reg28; reg79=reg82+reg79; reg81=reg80+reg81;
    reg80=reg53*reg25; reg60=reg63/reg60; reg82=reg36*reg75; T reg85=reg73*reg61; T reg86=reg70*reg72;
    reg85=reg82+reg85; reg82=reg72*reg60; reg80=reg81+reg80; reg86=reg79+reg86; reg28=reg50/reg28;
    reg79=reg49*reg84; reg81=reg48*reg83; reg82=reg85+reg82; reg85=reg76*reg86; T reg87=reg62*reg86;
    reg81=reg79+reg81; reg79=reg25*reg28; T reg88=reg74*reg80; T reg89=reg78*reg80; T reg90=reg53*reg80;
    reg89=reg48-reg89; reg85=reg73-reg85; T reg91=reg70*reg86; T reg92=reg75*reg82; reg79=reg81+reg79;
    reg87=reg36-reg87; reg81=reg61*reg82; reg88=reg49-reg88; T reg93=pow(reg87,2); T reg94=pow(reg85,2);
    reg91=reg72-reg91; T reg95=reg60*reg82; T reg96=pow(reg88,2); reg81=reg73-reg81; reg92=reg36-reg92;
    T reg97=reg84*reg79; T reg98=pow(reg89,2); T reg99=reg83*reg79; reg90=reg25-reg90; T reg100=pow(reg81,2);
    T reg101=pow(reg92,2); reg95=reg72-reg95; T reg102=pow(reg91,2); reg94=reg93+reg94; reg93=pow(reg90,2);
    reg98=reg96+reg98; reg97=reg49-reg97; reg99=reg48-reg99; reg96=reg28*reg79; T reg103=pow(reg99,2);
    T reg104=pow(reg97,2); reg102=reg94+reg102; reg93=reg98+reg93; reg96=reg25-reg96; reg94=pow(reg95,2);
    reg100=reg101+reg100; reg103=reg104+reg103; reg102=pow(reg102,0.5); reg93=pow(reg93,0.5); reg98=pow(reg96,2);
    reg94=reg100+reg94; reg100=0.025783423063208590757*elem.pos(0)[0]; reg101=0.14088324360345809781*elem.pos(4)[0]; reg104=0.096225044864937627422*elem.pos(0)[1]; T reg105=0.096225044864937627422*elem.pos(0)[0];
    reg87=reg87/reg102; reg88=reg88/reg93; T reg106=0.14088324360345809781*elem.pos(4)[1]; reg85=reg85/reg102; reg94=pow(reg94,0.5);
    T reg107=0.14088324360345809781*elem.pos(4)[2]; reg98=reg103+reg98; reg103=0.025783423063208590757*elem.pos(0)[1]; T reg108=0.096225044864937627422*elem.pos(0)[2]; T reg109=0.025783423063208590757*elem.pos(0)[2];
    reg89=reg89/reg93; reg92=reg92/reg94; reg81=reg81/reg94; T reg110=0.52578342306320860749*elem.pos(4)[2]; T reg111=0.096225044864937627422*elem.pos(1)[0];
    T reg112=reg101-reg100; T reg113=reg20*reg89; T reg114=0.52578342306320860749*elem.pos(4)[0]; T reg115=reg19*reg88; reg93=reg90/reg93;
    reg98=pow(reg98,0.5); reg89=reg48*reg89; reg74=reg19*reg74; reg78=reg20*reg78; reg19=reg106-reg103;
    reg20=0.096225044864937627422*elem.pos(1)[2]; reg88=reg49*reg88; reg90=0.096225044864937627422*elem.pos(1)[1]; reg76=reg41*reg76; reg62=reg40*reg62;
    T reg116=0.025783423063208590757*elem.pos(1)[0]; reg101=reg101+reg105; reg106=reg106+reg104; T reg117=0.025783423063208590757*elem.pos(1)[1]; T reg118=reg36*reg87;
    T reg119=reg73*reg85; T reg120=reg107-reg109; T reg121=0.52578342306320860749*elem.pos(4)[1]; reg102=reg91/reg102; reg91=0.025783423063208590757*elem.pos(1)[2];
    reg107=reg107+reg108; reg87=reg40*reg87; reg85=reg41*reg85; reg99=reg99/reg98; reg97=reg97/reg98;
    reg40=0.35911675639654188548*elem.pos(0)[2]; reg41=0.35911675639654188548*elem.pos(0)[1]; T reg122=0.35911675639654188548*elem.pos(1)[2]; reg120=reg120+reg20; T reg123=0.35911675639654188548*elem.pos(1)[1];
    T reg124=0.096225044864937627422*elem.pos(3)[2]; T reg125=reg121-reg104; reg19=reg19+reg90; T reg126=0.096225044864937627422*elem.pos(3)[1]; T reg127=0.35911675639654188548*elem.pos(3)[1];
    reg106=reg106-reg117; T reg128=reg110-reg108; T reg129=0.35911675639654188548*elem.pos(3)[2]; reg107=reg107-reg91; reg101=reg101-reg116;
    reg78=reg74+reg78; reg94=reg95/reg94; reg73=reg73*reg81; reg36=reg36*reg92; reg85=reg87+reg85;
    reg53=reg26*reg53; reg61=reg8*reg61; reg75=reg30*reg75; reg74=reg7*reg102; reg89=reg88+reg89;
    reg87=reg25*reg93; reg113=reg115+reg113; reg93=reg26*reg93; reg26=0.35911675639654188548*elem.pos(1)[0]; reg88=reg114-reg105;
    reg95=0.35911675639654188548*elem.pos(3)[0]; reg76=reg62+reg76; reg92=reg30*reg92; reg81=reg8*reg81; reg70=reg7*reg70;
    reg119=reg118+reg119; reg7=0.096225044864937627422*elem.pos(3)[0]; reg112=reg112+reg111; reg102=reg72*reg102; reg8=0.35911675639654188548*elem.pos(0)[0];
    reg123=reg125+reg123; reg95=reg101+reg95; reg30=0.52578342306320860749*elem.pos(5)[0]; reg93=reg113+reg93; reg62=0.025783423063208590757*elem.pos(3)[1];
    reg87=reg89+reg87; reg89=0.025783423063208590757*elem.pos(3)[2]; reg53=reg78+reg53; reg49=reg49*reg97; reg122=reg128+reg122;
    reg48=reg48*reg99; reg78=0.52578342306320860749*elem.pos(5)[2]; reg99=reg46*reg99; reg97=reg16*reg97; reg98=reg96/reg98;
    reg129=reg107+reg129; reg112=reg112-reg7; reg127=reg106+reg127; reg120=reg120-reg124; reg96=reg63*reg94;
    reg81=reg92+reg81; reg94=reg72*reg94; reg73=reg36+reg73; reg102=reg119+reg102; reg60=reg63*reg60;
    reg61=reg75+reg61; reg74=reg85+reg74; reg84=reg16*reg84; reg83=reg46*reg83; reg8=reg114+reg8;
    reg70=reg76+reg70; reg16=0.52578342306320860749*elem.pos(5)[1]; reg41=reg121+reg41; reg19=reg19-reg126; reg36=0.025783423063208590757*elem.pos(3)[0];
    reg26=reg88+reg26; reg40=reg110+reg40; reg127=reg16+reg127; reg120=reg120+reg78; reg122=reg122-reg89;
    reg74=reg86*reg74; reg46=0.096225044864937627422*elem.pos(2)[1]; reg63=0.096225044864937627422*elem.pos(2)[2]; reg129=reg78+reg129; reg72=0.35911675639654188548*elem.pos(2)[1];
    reg16=reg19+reg16; reg19=0.096225044864937627422*elem.pos(2)[0]; reg95=reg30+reg95; reg8=reg8-reg111; reg75=0.35911675639654188548*elem.pos(2)[0];
    reg96=reg81+reg96; reg30=reg112+reg30; reg94=reg73+reg94; reg60=reg61+reg60; reg41=reg41-reg90;
    reg83=reg84+reg83; reg61=0.14088324360345809781*elem.pos(5)[0]; reg28=reg50*reg28; reg26=reg26-reg36; reg40=reg40-reg20;
    reg102=reg70*reg102; reg93=reg80*reg93; reg87=reg53*reg87; reg48=reg49+reg48; reg25=reg25*reg98;
    reg99=reg97+reg99; reg98=reg50*reg98; reg49=0.14088324360345809781*elem.pos(5)[1]; reg123=reg123-reg62; reg50=0.35911675639654188548*elem.pos(2)[2];
    reg53=0.14088324360345809781*elem.pos(5)[2]; reg41=reg126+reg41; reg123=reg123+reg49; reg127=reg127-reg46; reg75=reg30+reg75;
    reg50=reg120+reg50; reg8=reg7+reg8; reg40=reg124+reg40; reg96=reg82*reg96; reg94=reg60*reg94;
    reg26=reg26+reg61; reg28=reg83+reg28; reg93=reg87-reg93; reg25=reg48+reg25; reg98=reg99+reg98;
    reg74=reg102-reg74; reg122=reg122+reg53; reg95=reg95-reg19; reg72=reg16+reg72; reg129=reg129-reg63;
    reg16=0.025783423063208590757*elem.pos(2)[0]; reg8=reg61+reg8; reg75=reg75*reg74; reg30=0.025783423063208590757*elem.pos(2)[2]; reg40=reg53+reg40;
    reg50=reg74*reg50; reg127=reg93*reg127; reg96=reg94-reg96; reg129=reg93*reg129; reg48=0.025783423063208590757*elem.pos(2)[1];
    reg41=reg49+reg41; reg26=reg19+reg26; reg72=reg74*reg72; reg95=reg95*reg93; reg25=reg28*reg25;
    reg123=reg46+reg123; reg122=reg63+reg122; reg98=reg79*reg98; reg50=0.25*reg50; reg129=0.25*reg129;
    reg74=0.25*reg74; reg122=reg96*reg122; reg40=reg40-reg30; reg93=0.25*reg93; reg8=reg8-reg16;
    reg72=0.25*reg72; reg75=0.25*reg75; reg127=0.25*reg127; reg123=reg96*reg123; reg98=reg25-reg98;
    reg41=reg41-reg48; reg95=0.25*reg95; reg26=reg26*reg96; reg123=0.25*reg123; reg127=reg72+reg127;
    reg41=reg98*reg41; reg40=reg98*reg40; reg129=reg50+reg129; reg95=reg75+reg95; reg122=0.25*reg122;
    reg8=reg8*reg98; reg96=0.25*reg96; reg93=reg74+reg93; reg26=0.25*reg26; reg122=reg129+reg122;
    reg8=0.25*reg8; reg96=reg93+reg96; reg98=0.25*reg98; reg26=reg95+reg26; reg123=reg127+reg123;
    reg41=0.25*reg41; reg40=0.25*reg40; reg40=reg122+reg40; reg8=reg26+reg8; reg98=reg96+reg98;
    reg41=reg123+reg41; res[0]=reg8/reg98; res[1]=reg41/reg98; res[2]=reg40/reg98;

    return res;
}
}
#endif // LMT_QUAD_6
