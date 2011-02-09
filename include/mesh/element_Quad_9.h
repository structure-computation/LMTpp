#ifndef LMT_QUAD_9
#define LMT_QUAD_9
#include "node.h"
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_9 &elem) { /// order -> degre du polynome a integrer exactement
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
template<class TNode> void permutation_if_jac_neg(const Quad_9 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=nodes[5]->pos[0]-nodes[7]->pos[0]; T reg1=nodes[6]->pos[1]-nodes[4]->pos[1]; T reg2=nodes[5]->pos[1]-nodes[7]->pos[1]; T reg3=nodes[6]->pos[0]-nodes[4]->pos[0]; reg1=reg0*reg1;
    reg3=reg2*reg3; T det_jac=reg1-reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[7],nodes[3],nodes[6],nodes[2],nodes[5],nodes[1],nodes[4],nodes[8]};
        for(unsigned i=0;i<9;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad_9 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=0.5-var_inter[0]; T reg3=4*reg1; T reg4=4*reg2;
    T reg5=4*var_inter[0]; T reg6=4*reg0; reg3=reg5+reg3; T reg7=0.5-var_inter[1]; reg4=reg6+reg4;
    T reg8=8*var_inter[0]; T reg9=1-var_inter[1]; reg6=reg6*reg2; reg5=reg5*reg1; T reg10=8*reg0;
    T reg11=reg10-reg8; T reg12=reg5*reg7; T reg13=reg6*reg7; T reg14=reg9*reg4; T reg15=reg6*reg9;
    T reg16=reg5*reg9; T reg17=reg9*reg3; T reg18=reg10*var_inter[0]; reg17=reg7*reg17; T reg19=reg7*reg14;
    T reg20=reg9*reg11; T reg21=reg18*reg9; reg12=reg16+reg12; reg13=reg15+reg13; T reg22=var_inter[1]-0.5;
    T reg23=reg18*reg7; T reg24=pos_nodes[0][1]*reg19; T reg25=pos_nodes[0][1]*reg13; T reg26=pos_nodes[1][1]*reg17; T reg27=pos_nodes[0][0]*reg13;
    T reg28=pos_nodes[1][0]*reg12; T reg29=reg6*reg22; reg23=reg21+reg23; T reg30=pos_nodes[1][1]*reg12; T reg31=pos_nodes[0][0]*reg19;
    T reg32=pos_nodes[1][0]*reg17; reg20=reg7*reg20; T reg33=var_inter[1]*reg4; T reg34=var_inter[1]*reg6; T reg35=pos_nodes[4][0]*reg20;
    reg31=reg32-reg31; reg29=reg34+reg29; reg32=reg5*reg22; T reg36=pos_nodes[4][1]*reg23; reg25=reg30+reg25;
    reg16=reg16*reg7; reg30=8*reg2; reg3=var_inter[1]*reg3; T reg37=reg22*reg33; reg15=reg15*reg7;
    T reg38=pos_nodes[4][0]*reg23; T reg39=var_inter[1]*reg5; reg24=reg26-reg24; reg26=pos_nodes[4][1]*reg20; reg27=reg28+reg27;
    reg28=reg18*reg22; reg32=reg39+reg32; T reg40=pos_nodes[3][0]*reg29; T reg41=var_inter[1]*reg18; reg35=reg31+reg35;
    reg31=pos_nodes[3][0]*reg37; reg2=reg2*reg10; T reg42=pos_nodes[0][0]*reg15; T reg43=pos_nodes[1][0]*reg16; reg36=reg25+reg36;
    reg25=pos_nodes[0][1]*reg15; T reg44=reg16*pos_nodes[1][1]; reg38=reg27+reg38; reg27=pos_nodes[3][1]*reg29; reg7=reg21*reg7;
    reg3=reg22*reg3; reg11=var_inter[1]*reg11; reg30=reg10+reg30; reg26=reg24+reg26; reg10=8*reg1;
    reg21=pos_nodes[3][1]*reg37; reg34=reg34*reg22; reg24=pos_nodes[2][0]*reg32; T reg45=var_inter[1]*reg2; T reg46=reg9*reg2;
    reg1=reg1*reg8; reg38=reg40-reg38; reg28=reg41+reg28; reg40=pos_nodes[2][1]*reg32; T reg47=pos_nodes[2][1]*reg3;
    reg21=reg26-reg21; reg0=16*reg0; reg11=reg22*reg11; reg26=reg9*reg30; reg10=reg8+reg10;
    reg8=16*var_inter[0]; T reg48=reg7*pos_nodes[4][1]; T reg49=reg7*pos_nodes[4][0]; reg31=reg35-reg31; reg35=pos_nodes[2][0]*reg3;
    reg42=reg43+reg42; reg25=reg44+reg25; reg36=reg27-reg36; reg49=reg42+reg49; reg27=reg34*pos_nodes[3][0];
    reg42=pos_nodes[6][0]*reg28; reg43=pos_nodes[6][1]*reg28; reg24=reg38+reg24; reg38=pos_nodes[6][1]*reg11; reg40=reg36+reg40;
    reg47=reg21+reg47; reg21=var_inter[1]*reg1; reg45=reg46-reg45; reg39=reg22*reg39; reg10=reg9*reg10;
    reg36=var_inter[1]*reg26; reg8=reg0-reg8; reg44=reg34*pos_nodes[3][1]; reg48=reg25+reg48; reg25=reg9*reg1;
    reg35=reg31+reg35; reg0=reg0*var_inter[0]; reg31=pos_nodes[6][0]*reg11; reg10=var_inter[1]*reg10; T reg50=pos_nodes[7][1]*reg36;
    reg38=reg47+reg38; reg47=reg9*reg0; reg44=reg48+reg44; reg48=reg39*pos_nodes[2][1]; reg43=reg40+reg43;
    reg40=var_inter[1]*reg0; reg21=reg25-reg21; reg42=reg24+reg42; reg24=pos_nodes[7][0]*reg45; reg41=reg22*reg41;
    reg22=pos_nodes[7][1]*reg45; T reg51=pos_nodes[7][0]*reg36; reg31=reg35+reg31; reg27=reg49+reg27; reg35=reg39*pos_nodes[2][0];
    reg8=reg9*reg8; reg9=pos_nodes[5][1]*reg21; reg22=reg43+reg22; reg50=reg38-reg50; reg38=pos_nodes[5][1]*reg10;
    reg48=reg44+reg48; reg43=reg41*pos_nodes[6][1]; reg8=var_inter[1]*reg8; reg51=reg31-reg51; reg31=pos_nodes[5][0]*reg10;
    reg46=var_inter[1]*reg46; reg40=reg47-reg40; reg24=reg42+reg24; reg42=pos_nodes[5][0]*reg21; reg35=reg27+reg35;
    reg27=reg41*pos_nodes[6][0]; reg25=var_inter[1]*reg25; reg44=reg46*pos_nodes[7][1]; reg31=reg51+reg31; reg49=pos_nodes[8][1]*reg40;
    reg9=reg22+reg9; reg22=pos_nodes[8][0]*reg8; reg38=reg50+reg38; reg50=pos_nodes[8][1]*reg8; reg43=reg48+reg43;
    reg42=reg24+reg42; reg24=pos_nodes[8][0]*reg40; reg48=reg46*pos_nodes[7][0]; reg27=reg35+reg27; reg50=reg38+reg50;
    reg22=reg31+reg22; reg24=reg42+reg24; reg49=reg9+reg49; reg48=reg27+reg48; reg9=reg25*pos_nodes[5][0];
    reg44=reg43+reg44; reg47=var_inter[1]*reg47; reg27=reg25*pos_nodes[5][1]; reg27=reg44+reg27; reg31=reg47*pos_nodes[8][1];
    reg35=reg22*reg49; reg9=reg48+reg9; reg38=reg47*pos_nodes[8][0]; reg42=reg24*reg50; reg31=reg27+reg31;
    reg42=reg35-reg42; reg38=reg9+reg38; reg9=reg24/reg42; reg27=reg50/reg42; reg43=reg22/reg42;
    reg42=reg49/reg42; reg31=pos[1]-reg31; reg38=pos[0]-reg38; reg42=reg38*reg42; reg9=reg31*reg9;
    reg27=reg38*reg27; reg43=reg31*reg43; var_inter[0]=reg42-reg9; var_inter[1]=reg43-reg27;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_9 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=var_inter[0]-0.5; T reg1=0.5-var_inter[0]; T reg2=1-var_inter[0]; T reg3=4*var_inter[0]; T reg4=4*reg1;
    T reg5=4*reg0; T reg6=4*reg2; T reg7=reg3*reg0; T reg8=0.5-var_inter[1]; reg5=reg3+reg5;
    reg4=reg6+reg4; reg3=8*reg2; T reg9=8*var_inter[0]; T reg10=1-var_inter[1]; reg6=reg6*reg1;
    T reg11=reg8*reg7; T reg12=reg6*reg10; T reg13=reg10*reg7; T reg14=reg3*var_inter[0]; T reg15=reg3-reg9;
    T reg16=reg10*reg4; T reg17=reg10*reg5; T reg18=reg6*reg8; T reg19=reg10*reg15; reg11=reg13+reg11;
    T reg20=reg10*reg14; T reg21=reg8*reg16; reg18=reg12+reg18; reg17=reg8*reg17; T reg22=reg8*reg14;
    T reg23=var_inter[1]-0.5; T reg24=pos_nodes[0][1]*reg21; T reg25=pos_nodes[1][1]*reg17; reg19=reg8*reg19; T reg26=var_inter[1]*reg4;
    T reg27=pos_nodes[0][1]*reg18; T reg28=pos_nodes[1][1]*reg11; T reg29=pos_nodes[1][0]*reg11; T reg30=pos_nodes[0][0]*reg18; reg22=reg20+reg22;
    T reg31=pos_nodes[1][0]*reg17; T reg32=reg6*var_inter[1]; T reg33=pos_nodes[0][0]*reg21; T reg34=reg6*reg23; T reg35=pos_nodes[4][1]*reg19;
    T reg36=reg7*var_inter[1]; T reg37=reg23*reg26; reg5=var_inter[1]*reg5; T reg38=8*reg1; reg29=reg30+reg29;
    reg34=reg32+reg34; reg30=reg23*reg7; reg33=reg31-reg33; reg31=pos_nodes[4][0]*reg22; T reg39=pos_nodes[4][0]*reg19;
    reg12=reg12*reg8; reg13=reg8*reg13; reg28=reg27+reg28; reg27=pos_nodes[4][1]*reg22; reg24=reg25-reg24;
    reg1=reg1*reg3; reg20=reg8*reg20; reg30=reg36+reg30; reg8=reg23*reg14; reg25=pos_nodes[3][0]*reg34;
    T reg40=pos_nodes[3][0]*reg37; reg33=reg39+reg33; reg39=pos_nodes[1][1]*reg13; T reg41=reg12*pos_nodes[0][1]; reg28=reg27+reg28;
    reg27=reg14*var_inter[1]; reg24=reg35+reg24; reg29=reg31+reg29; reg31=pos_nodes[3][1]*reg37; reg5=reg23*reg5;
    reg15=var_inter[1]*reg15; reg35=8*reg0; T reg42=reg13*pos_nodes[1][0]; reg38=reg3+reg38; reg3=pos_nodes[3][1]*reg34;
    T reg43=reg12*pos_nodes[0][0]; reg31=reg24-reg31; reg24=pos_nodes[2][1]*reg5; reg39=reg41+reg39; reg8=reg27+reg8;
    reg41=reg1*var_inter[1]; T reg44=pos_nodes[4][0]*reg20; T reg45=pos_nodes[2][0]*reg30; reg29=reg25-reg29; reg25=reg20*pos_nodes[4][1];
    T reg46=pos_nodes[2][1]*reg30; reg28=reg3-reg28; reg42=reg43+reg42; reg32=reg32*reg23; reg35=reg9+reg35;
    reg0=reg9*reg0; reg3=reg10*reg1; reg2=16*reg2; reg9=16*var_inter[0]; reg43=pos_nodes[2][0]*reg5;
    T reg47=reg10*reg38; reg15=reg23*reg15; reg40=reg33-reg40; reg33=pos_nodes[6][0]*reg8; T reg48=reg2*var_inter[0];
    T reg49=var_inter[1]*reg47; reg36=reg23*reg36; reg42=reg44+reg42; reg44=reg32*pos_nodes[3][0]; T reg50=pos_nodes[6][1]*reg8;
    reg46=reg28+reg46; reg28=reg10*reg0; reg24=reg31+reg24; reg31=pos_nodes[6][1]*reg15; T reg51=reg32*pos_nodes[3][1];
    T reg52=pos_nodes[6][0]*reg15; reg43=reg40+reg43; reg41=reg3-reg41; reg40=reg0*var_inter[1]; reg39=reg25+reg39;
    reg9=reg2-reg9; reg45=reg29+reg45; reg35=reg10*reg35; reg31=reg24+reg31; reg2=pos_nodes[7][1]*reg49;
    reg24=reg36*pos_nodes[2][1]; reg51=reg39+reg51; reg27=reg23*reg27; reg23=pos_nodes[7][0]*reg49; reg52=reg43+reg52;
    reg33=reg45+reg33; reg25=pos_nodes[7][0]*reg41; reg35=var_inter[1]*reg35; reg50=reg46+reg50; reg29=reg36*pos_nodes[2][0];
    reg44=reg42+reg44; reg40=reg28-reg40; reg39=reg48*var_inter[1]; reg42=pos_nodes[7][1]*reg41; reg43=reg10*reg48;
    reg9=reg10*reg9; reg10=reg27*pos_nodes[6][1]; reg24=reg51+reg24; reg2=reg31-reg2; reg42=reg50+reg42;
    reg31=pos_nodes[5][1]*reg35; reg45=pos_nodes[5][1]*reg40; reg46=pos_nodes[5][0]*reg35; reg23=reg52-reg23; reg39=reg43-reg39;
    reg9=var_inter[1]*reg9; reg25=reg33+reg25; reg33=pos_nodes[5][0]*reg40; reg29=reg44+reg29; reg44=reg27*pos_nodes[6][0];
    reg3=reg3*var_inter[1]; reg46=reg23+reg46; reg23=pos_nodes[8][0]*reg9; reg31=reg2+reg31; reg2=pos_nodes[8][1]*reg9;
    reg50=pos_nodes[8][1]*reg39; reg45=reg42+reg45; reg33=reg25+reg33; reg25=pos_nodes[8][0]*reg39; reg10=reg24+reg10;
    reg44=reg29+reg44; reg28=reg28*var_inter[1]; reg24=reg3*pos_nodes[7][0]; reg29=reg3*pos_nodes[7][1]; reg2=reg31+reg2;
    reg25=reg33+reg25; reg50=reg45+reg50; reg24=reg44+reg24; reg31=reg28*pos_nodes[5][0]; reg43=reg43*var_inter[1];
    reg23=reg46+reg23; reg29=reg10+reg29; reg10=reg28*pos_nodes[5][1]; reg10=reg29+reg10; reg29=reg43*pos_nodes[8][1];
    reg33=reg25*reg2; reg31=reg24+reg31; reg24=reg43*pos_nodes[8][0]; reg42=reg23*reg50; reg29=reg10+reg29;
    reg33=reg42-reg33; reg24=reg31+reg24; reg10=reg25/reg33; reg31=reg2/reg33; reg44=reg23/reg33;
    reg33=reg50/reg33; reg29=pos[1]-reg29; reg24=pos[0]-reg24; reg33=reg24*reg33; reg10=reg29*reg10;
    reg31=reg24*reg31; reg44=reg29*reg44; var_inter[0]+=reg33-reg10; var_inter[1]+=reg44-reg31;

}
template<> struct ElemVarInterFromPosNonLinear<Quad_9> { static const bool res = 2; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=4*reg0; T reg2=0.5-var_inter[0]; T reg3=4*var_inter[0]; T reg4=var_inter[0]-0.5;
    T reg5=8*reg0; reg3=reg3*reg4; reg1=reg2*reg1; T reg6=1-var_inter[1]; T reg7=var_inter[0]*reg5;
    T reg8=reg6*reg3; T reg9=reg1*reg6; T reg10=0.5-var_inter[1]; reg9=reg9*reg10; reg8=reg10*reg8;
    T reg11=reg6*reg7; reg8=val[1]*reg8; reg11=reg10*reg11; reg1=var_inter[1]*reg1; reg10=var_inter[1]-0.5;
    reg9=val[0]*reg9; reg8=reg9+reg8; reg3=var_inter[1]*reg3; reg11=val[4]*reg11; reg1=reg1*reg10;
    reg1=val[3]*reg1; reg3=reg10*reg3; reg5=reg2*reg5; reg7=var_inter[1]*reg7; reg11=reg8+reg11;
    reg2=8*var_inter[0]; reg5=reg6*reg5; reg2=reg4*reg2; reg7=reg10*reg7; reg0=16*reg0;
    reg3=val[2]*reg3; reg1=reg11+reg1; reg0=var_inter[0]*reg0; reg2=reg6*reg2; reg5=var_inter[1]*reg5;
    reg7=val[6]*reg7; reg3=reg1+reg3; reg5=val[7]*reg5; reg2=var_inter[1]*reg2; reg7=reg3+reg7;
    reg0=reg6*reg0; reg5=reg7+reg5; reg2=val[5]*reg2; reg0=var_inter[1]*reg0; reg2=reg5+reg2;
    reg0=val[8]*reg0; res=reg2+reg0;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Quad_9 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=8*var_inter[0]; T reg2=8*reg0; T reg3=var_inter[0]-0.5; T reg4=4*var_inter[0];
    T reg5=16*reg0; reg0=4*reg0; T reg6=0.5-var_inter[0]; reg5=var_inter[0]*reg5; reg4=reg4*reg3;
    T reg7=1-var_inter[1]; reg0=reg6*reg0; T reg8=var_inter[0]*reg2; reg1=reg3*reg1; reg2=reg6*reg2;
    reg5=reg7*reg5; reg1=reg7*reg1; reg2=reg7*reg2; reg3=var_inter[1]*reg8; reg6=var_inter[1]*reg4;
    T reg9=var_inter[1]-0.5; T reg10=var_inter[1]*reg0; reg8=reg7*reg8; reg4=reg7*reg4; T reg11=0.5-var_inter[1];
    reg7=reg0*reg7; reg6=reg9*reg6; res[2]=reg6; reg10=reg10*reg9; res[3]=reg10;
    reg3=reg9*reg3; res[6]=reg3; reg2=var_inter[1]*reg2; res[7]=reg2; reg8=reg11*reg8;
    res[4]=reg8; reg4=reg11*reg4; res[1]=reg4; reg1=var_inter[1]*reg1; res[5]=reg1;
    reg11=reg7*reg11; res[0]=reg11; reg5=var_inter[1]*reg5; res[8]=reg5;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Quad_9> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Quad_9,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=0.5-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=1-var_inter[0]; T reg3=4*reg2; T reg4=4*var_inter[0];
    T reg5=4*reg1; T reg6=4*reg0; reg6=reg3+reg6; T reg7=1-var_inter[1]; T reg8=8*reg2;
    T reg9=8*var_inter[0]; reg5=reg4+reg5; T reg10=reg7*reg6; T reg11=reg8-reg9; T reg12=0.5-var_inter[1];
    T reg13=reg7*reg5; T reg14=reg12*reg10; T reg15=reg7*reg11; reg13=reg12*reg13; reg15=reg12*reg15;
    T reg16=var_inter[1]-0.5; T reg17=elem.pos(1)[0]*reg13; T reg18=elem.pos(0)[1]*reg14; T reg19=elem.pos(1)[1]*reg13; T reg20=var_inter[1]*reg6;
    T reg21=elem.pos(0)[0]*reg14; T reg22=8*reg0; T reg23=elem.pos(4)[1]*reg15; T reg24=elem.pos(4)[0]*reg15; reg13=elem.pos(1)[2]*reg13;
    reg19=reg19-reg18; reg17=reg17-reg21; T reg25=reg16*reg20; T reg26=elem.pos(0)[2]*reg14; reg5=var_inter[1]*reg5;
    reg17=reg24+reg17; reg5=reg16*reg5; reg24=elem.pos(3)[1]*reg25; reg19=reg23+reg19; reg15=elem.pos(4)[2]*reg15;
    reg13=reg13-reg26; reg23=elem.pos(3)[0]*reg25; reg22=reg8+reg22; reg3=reg0*reg3; T reg27=8*reg1;
    reg4=reg4*reg1; reg11=var_inter[1]*reg11; reg11=reg16*reg11; reg17=reg17-reg23; reg27=reg9+reg27;
    T reg28=reg7*reg22; T reg29=reg3*reg12; reg15=reg13+reg15; reg19=reg19-reg24; reg13=elem.pos(2)[1]*reg5;
    reg2=16*reg2; T reg30=elem.pos(3)[2]*reg25; T reg31=16*var_inter[0]; T reg32=var_inter[0]*reg8; T reg33=elem.pos(2)[0]*reg5;
    T reg34=reg7*reg4; T reg35=reg3*reg7; T reg36=reg12*reg4; reg36=reg34+reg36; reg17=reg33+reg17;
    reg29=reg35+reg29; reg27=reg7*reg27; reg31=reg2-reg31; reg33=elem.pos(6)[1]*reg11; T reg37=var_inter[1]*reg28;
    reg13=reg19+reg13; reg19=reg12*reg32; T reg38=elem.pos(6)[0]*reg11; reg5=elem.pos(2)[2]*reg5; reg15=reg15-reg30;
    T reg39=reg7*reg32; T reg40=elem.pos(0)[1]*reg29; reg31=reg7*reg31; T reg41=elem.pos(1)[1]*reg36; T reg42=elem.pos(7)[1]*reg37;
    reg38=reg17+reg38; reg17=reg3*reg16; reg19=reg39+reg19; T reg43=elem.pos(1)[0]*reg36; T reg44=var_inter[1]*reg3;
    reg11=elem.pos(6)[2]*reg11; reg5=reg15+reg5; reg33=reg13+reg33; reg27=var_inter[1]*reg27; reg13=elem.pos(0)[0]*reg29;
    reg15=elem.pos(7)[0]*reg37; T reg45=var_inter[1]*reg4; T reg46=elem.pos(0)[2]*reg29; T reg47=elem.pos(1)[2]*reg36; T reg48=reg4*reg16;
    T reg49=reg41+reg40; T reg50=elem.pos(5)[0]*reg27; T reg51=elem.pos(5)[1]*reg27; reg33=reg33-reg42; reg38=reg38-reg15;
    T reg52=elem.pos(7)[2]*reg37; reg11=reg5+reg11; reg31=var_inter[1]*reg31; reg5=reg13+reg43; reg17=reg44+reg17;
    T reg53=elem.pos(4)[1]*reg19; T reg54=elem.pos(4)[0]*reg19; reg48=reg45+reg48; T reg55=elem.pos(3)[1]*reg17; T reg56=reg32*reg16;
    T reg57=elem.pos(8)[0]*reg31; T reg58=reg49+reg53; T reg59=var_inter[1]*reg32; T reg60=elem.pos(4)[2]*reg19; T reg61=elem.pos(8)[1]*reg31;
    reg33=reg51+reg33; reg51=elem.pos(3)[0]*reg17; reg27=elem.pos(5)[2]*reg27; T reg62=reg46+reg47; T reg63=reg54+reg5;
    reg11=reg11-reg52; reg8=reg0*reg8; reg50=reg38+reg50; reg0=reg60+reg62; reg27=reg11+reg27;
    reg11=elem.pos(2)[1]*reg48; reg38=var_inter[1]*reg8; reg56=reg59+reg56; reg61=reg33+reg61; reg31=elem.pos(8)[2]*reg31;
    reg9=reg1*reg9; reg1=reg7*reg8; reg17=elem.pos(3)[2]*reg17; reg51=reg51-reg63; reg55=reg55-reg58;
    reg33=elem.pos(2)[0]*reg48; reg57=reg50+reg57; reg50=pow(reg61,2); T reg64=var_inter[1]*reg9; T reg65=elem.pos(6)[0]*reg56;
    T reg66=elem.pos(6)[1]*reg56; reg11=reg55+reg11; reg55=pow(reg57,2); reg17=reg17-reg0; reg48=elem.pos(2)[2]*reg48;
    reg38=reg1-reg38; reg27=reg31+reg27; reg31=reg7*reg9; reg2=var_inter[0]*reg2; reg51=reg33+reg51;
    reg33=elem.pos(7)[0]*reg38; reg51=reg65+reg51; reg65=elem.pos(7)[1]*reg38; reg64=reg31-reg64; reg48=reg17+reg48;
    reg50=reg55+reg50; reg17=pow(reg27,2); reg56=elem.pos(6)[2]*reg56; reg66=reg11+reg66; reg11=var_inter[1]*reg2;
    reg7=reg7*reg2; reg17=reg50+reg17; reg50=elem.pos(5)[0]*reg64; reg55=elem.pos(5)[1]*reg64; reg38=elem.pos(7)[2]*reg38;
    reg51=reg33+reg51; reg11=reg7-reg11; reg65=reg66+reg65; reg48=reg56+reg48; reg64=elem.pos(5)[2]*reg64;
    reg33=elem.pos(8)[1]*reg11; reg17=pow(reg17,0.5); reg55=reg65+reg55; reg56=elem.pos(8)[0]*reg11; reg48=reg38+reg48;
    reg50=reg51+reg50; reg38=reg57/reg17; reg51=reg61/reg17; reg33=reg55+reg33; reg50=reg56+reg50;
    reg48=reg64+reg48; reg11=elem.pos(8)[2]*reg11; reg55=reg51*reg33; reg56=reg50*reg38; reg11=reg48+reg11;
    reg17=reg27/reg17; reg55=reg56+reg55; reg48=reg17*reg11; reg55=reg48+reg55; reg48=reg51*reg55;
    reg56=reg55*reg38; reg64=reg17*reg55; reg56=reg50-reg56; reg48=reg33-reg48; reg64=reg11-reg64;
    reg65=pow(reg56,2); reg66=pow(reg48,2); T reg67=pow(reg64,2); reg66=reg65+reg66; reg67=reg66+reg67;
    reg67=pow(reg67,0.5); reg56=reg56/reg67; reg48=reg48/reg67; reg67=reg64/reg67; reg64=reg57*reg56;
    reg65=reg61*reg48; reg38=reg57*reg38; reg48=reg33*reg48; reg56=reg50*reg56; reg51=reg61*reg51;
    reg17=reg27*reg17; reg38=reg51+reg38; reg11=reg11*reg67; reg48=reg56+reg48; reg65=reg64+reg65;
    reg67=reg27*reg67; reg17=reg38+reg17; reg67=reg65+reg67; reg48=reg11+reg48; reg11=reg67*reg55;
    reg27=reg48*reg17; reg11=reg27-reg11; return reg11;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Quad_9,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.018874775675311855147*elem.pos(0)[1]; T reg1=0.070441621801729003199*elem.pos(1)[1]; T reg2=0.26289171153160429149*elem.pos(1)[1]; T reg3=0.070441621801729003199*elem.pos(0)[0]; T reg4=0.26289171153160429149*elem.pos(0)[0];
    T reg5=0.018874775675311855147*elem.pos(1)[0]; T reg6=0.26289171153160429149*elem.pos(0)[1]; T reg7=0.070441621801729003199*elem.pos(0)[1]; T reg8=0.018874775675311855147*elem.pos(1)[1]; T reg9=0.070441621801729003199*elem.pos(1)[0];
    T reg10=0.018874775675311855147*elem.pos(0)[0]; T reg11=0.26289171153160429149*elem.pos(1)[0]; T reg12=0.070441621801729003213*elem.pos(0)[0]; T reg13=0.28176648720691614664*elem.pos(4)[0]; T reg14=reg11+reg10;
    T reg15=reg5-reg3; T reg16=0.10313369225283431404*elem.pos(4)[1]; T reg17=0.981125224324688029*elem.pos(1)[0]; T reg18=0.98112522432468802895*elem.pos(1)[0]; T reg19=reg8-reg7;
    T reg20=0.981125224324688029*elem.pos(1)[1]; reg10=reg10-reg9; T reg21=0.10313369225283431404*elem.pos(4)[0]; T reg22=reg0+reg2; T reg23=0.28176648720691614664*elem.pos(4)[1];
    reg0=reg0-reg1; T reg24=0.98112522432468802895*elem.pos(1)[1]; reg5=reg5+reg4; T reg25=0.070441621801729003213*elem.pos(0)[1]; reg8=reg8+reg6;
    T reg26=0.26289171153160429149*elem.pos(3)[1]; T reg27=0.070441621801729003213*elem.pos(1)[0]; reg0=reg0-reg16; reg18=reg18+reg12; T reg28=1.0515668461264170322*elem.pos(4)[0];
    T reg29=1.4364670255861677246*elem.pos(4)[0]; reg17=reg17-reg4; reg24=reg24+reg25; T reg30=1.0515668461264170322*elem.pos(4)[1]; T reg31=reg23-reg22;
    T reg32=0.070441621801729003213*elem.pos(3)[1]; reg10=reg10-reg21; T reg33=1.4364670255861677246*elem.pos(4)[1]; reg20=reg20-reg6; T reg34=0.26289171153160429149*elem.pos(3)[0];
    T reg35=0.981125224324688029*elem.pos(3)[1]; reg19=reg19-reg16; T reg36=0.014886066246173484324*elem.pos(0)[0]; T reg37=0.055555555555555552339*elem.pos(1)[0]; T reg38=0.98112522432468802895*elem.pos(3)[0];
    reg5=reg5-reg13; T reg39=0.014886066246173484324*elem.pos(1)[1]; T reg40=0.055555555555555552339*elem.pos(0)[1]; T reg41=0.055555555555555552339*elem.pos(1)[1]; T reg42=0.014886066246173484324*elem.pos(0)[1];
    reg8=reg8-reg23; T reg43=0.98112522432468802895*elem.pos(3)[1]; T reg44=0.98112522432468802895*elem.pos(0)[0]; reg15=reg15-reg21; T reg45=0.055555555555555552339*elem.pos(0)[0];
    T reg46=0.981125224324688029*elem.pos(0)[1]; T reg47=0.014886066246173484324*elem.pos(1)[0]; T reg48=0.070441621801729003213*elem.pos(1)[1]; T reg49=0.070441621801729003213*elem.pos(3)[0]; T reg50=0.981125224324688029*elem.pos(0)[0];
    T reg51=0.981125224324688029*elem.pos(3)[0]; T reg52=0.98112522432468802895*elem.pos(0)[1]; T reg53=reg13-reg14; T reg54=0.018874775675311855147*elem.pos(3)[0]; reg47=reg47-reg45;
    reg18=reg18-reg28; T reg55=0.070441621801729003213*elem.pos(2)[1]; reg43=reg8-reg43; reg8=0.981125224324688029*elem.pos(2)[0]; reg10=reg34+reg10;
    reg38=reg5-reg38; reg5=0.20733615597604870572*elem.pos(1)[0]; T reg56=0.26289171153160429149*elem.pos(2)[0]; T reg57=0.070441621801729003213*elem.pos(2)[0]; T reg58=0.26289171153160429149*elem.pos(2)[1];
    reg19=reg35-reg19; reg15=reg51-reg15; reg35=0.20733615597604870572*elem.pos(1)[1]; reg39=reg39-reg40; reg36=reg36-reg37;
    reg51=0.081338978618764150166*elem.pos(4)[0]; T reg59=0.081338978618764150166*elem.pos(4)[1]; reg42=reg42-reg41; reg50=reg50-reg11; reg52=reg48+reg52;
    reg53=reg53+reg49; T reg60=0.98112522432468802895*elem.pos(2)[0]; reg46=reg46-reg2; reg44=reg27+reg44; reg24=reg24-reg30;
    reg31=reg31+reg32; reg17=reg17+reg29; T reg61=0.98112522432468802895*elem.pos(2)[1]; T reg62=0.981125224324688029*elem.pos(2)[1]; reg0=reg26+reg0;
    reg20=reg20+reg33; T reg63=0.018874775675311855147*elem.pos(3)[1]; reg39=reg39-reg59; T reg64=0.20733615597604870572*elem.pos(3)[1]; reg20=reg63-reg20;
    T reg65=0.070441621801729003199*elem.pos(2)[1]; reg35=reg35-reg40; T reg66=0.055555555555555552339*elem.pos(3)[1]; T reg67=0.30356120084098635952*elem.pos(4)[1]; reg42=reg42-reg59;
    T reg68=0.20733615597604870572*elem.pos(0)[1]; reg18=reg18-reg54; reg19=reg19-reg58; reg63=reg24-reg63; reg50=reg29+reg50;
    reg24=0.070441621801729003199*elem.pos(3)[0]; reg29=reg30-reg52; reg43=reg43-reg55; reg17=reg54-reg17; reg46=reg33+reg46;
    reg33=0.30356120084098635952*elem.pos(4)[0]; reg54=0.070441621801729003199*elem.pos(3)[1]; T reg69=reg28-reg44; reg5=reg5-reg45; T reg70=0.20733615597604870572*elem.pos(0)[0];
    reg15=reg15-reg56; T reg71=0.070441621801729003199*elem.pos(2)[0]; reg61=reg31+reg61; reg31=1.0515668461264170322*elem.pos(6)[1]; T reg72=1.4364670255861677246*elem.pos(6)[1];
    reg62=reg62-reg0; T reg73=1.0515668461264170322*elem.pos(6)[0]; T reg74=0.20733615597604870572*elem.pos(3)[0]; T reg75=0.055555555555555552339*elem.pos(3)[0]; reg36=reg36-reg51;
    reg47=reg47-reg51; reg38=reg38-reg57; reg60=reg53+reg60; reg53=1.4364670255861677246*elem.pos(6)[0]; reg8=reg8-reg10;
    reg46=reg54+reg46; T reg76=0.018874775675311855147*elem.pos(2)[1]; reg60=reg60-reg73; T reg77=0.28176648720691614667*elem.pos(7)[1]; reg29=reg26+reg29;
    T reg78=0.10313369225283431406*elem.pos(7)[0]; T reg79=0.018874775675311855147*elem.pos(2)[0]; reg5=reg5+reg33; T reg80=0.014886066246173484324*elem.pos(3)[0]; reg69=reg34+reg69;
    reg62=reg62+reg72; reg17=reg17-reg71; reg70=reg70-reg37; reg68=reg68-reg41; T reg81=0.28176648720691614664*elem.pos(6)[0];
    reg18=reg18-reg56; T reg82=0.28176648720691614667*elem.pos(7)[0]; reg8=reg8+reg53; T reg83=0.10313369225283431404*elem.pos(6)[0]; T reg84=0.055555555555555552339*elem.pos(2)[1];
    reg64=reg39+reg64; reg39=1.4364670255861677246*elem.pos(7)[0]; reg38=reg73+reg38; reg19=reg72+reg19; reg72=1.0515668461264170322*elem.pos(7)[1];
    reg63=reg63-reg58; T reg85=0.20733615597604870572*elem.pos(2)[1]; reg42=reg42-reg66; reg36=reg36-reg75; T reg86=0.20733615597604870572*elem.pos(2)[0];
    T reg87=0.28176648720691614664*elem.pos(6)[1]; T reg88=0.10313369225283431404*elem.pos(6)[1]; reg20=reg20-reg65; T reg89=0.055555555555555552339*elem.pos(2)[0]; reg43=reg31+reg43;
    T reg90=1.4364670255861677246*elem.pos(7)[1]; reg35=reg35+reg67; reg74=reg47+reg74; reg47=0.014886066246173484324*elem.pos(3)[1]; reg61=reg61-reg31;
    T reg91=0.10313369225283431406*elem.pos(7)[1]; reg50=reg24+reg50; reg15=reg53+reg15; reg53=1.0515668461264170322*elem.pos(7)[0]; reg62=reg62+reg77;
    reg63=reg63+reg87; T reg92=1.0515668461264170322*elem.pos(5)[1]; reg64=reg64-reg84; T reg93=0.30356120084098635952*elem.pos(6)[1]; reg85=reg42+reg85;
    reg86=reg36+reg86; reg36=0.30356120084098635952*elem.pos(6)[0]; reg47=reg35+reg47; reg35=reg79-reg50; reg29=reg76+reg29;
    reg76=reg76-reg46; reg79=reg69+reg79; reg60=reg60+reg78; reg42=1.4364670255861677246*elem.pos(5)[0]; reg70=reg33+reg70;
    reg68=reg67+reg68; reg17=reg17-reg83; reg15=reg15-reg53; reg18=reg18+reg81; reg33=0.28176648720691614667*elem.pos(5)[0];
    reg8=reg8+reg82; reg19=reg19-reg72; reg80=reg5+reg80; reg5=1.4364670255861677246*elem.pos(5)[1]; reg74=reg74-reg89;
    reg67=1.0515668461264170322*elem.pos(5)[0]; reg61=reg61+reg91; reg20=reg20-reg88; reg69=0.28176648720691614667*elem.pos(5)[1]; T reg94=0.10313369225283431406*elem.pos(5)[0];
    reg38=reg38-reg39; reg43=reg43-reg90; T reg95=0.10313369225283431406*elem.pos(5)[1]; reg86=reg86+reg36; reg29=reg29-reg87;
    reg64=reg93+reg64; T reg96=0.014886066246173484324*elem.pos(2)[0]; reg70=reg70-reg75; reg60=reg60+reg42; T reg97=0.081338978618764150166*elem.pos(6)[0];
    reg80=reg80-reg89; reg8=reg8-reg67; reg79=reg79-reg81; reg43=reg43-reg95; reg15=reg15+reg33;
    T reg98=0.014886066246173484324*elem.pos(2)[1]; reg19=reg19+reg69; T reg99=0.30356120084098635952*elem.pos(7)[1]; reg76=reg76-reg88; T reg100=1.5396007178390020388*elem.pos(8)[1];
    T reg101=0.081338978618764150166*elem.pos(6)[1]; reg63=reg91+reg63; T reg102=0.081338978618764150159*elem.pos(7)[0]; reg61=reg61+reg5; reg20=reg20-reg77;
    reg62=reg62-reg92; reg18=reg78+reg18; reg47=reg47-reg84; T reg103=0.081338978618764150159*elem.pos(7)[1]; reg17=reg17-reg82;
    reg93=reg85+reg93; reg85=0.30356120084098635952*elem.pos(7)[0]; reg38=reg38-reg94; reg68=reg68-reg66; T reg104=1.5396007178390020388*elem.pos(8)[0];
    reg74=reg36+reg74; reg35=reg35-reg83; reg35=reg53+reg35; reg64=reg64+reg99; reg47=reg47-reg101;
    reg93=reg93-reg103; reg36=0.081338978618764150166*elem.pos(7)[1]; T reg105=0.30356120084098635952*elem.pos(5)[1]; reg43=reg100+reg43; reg86=reg86-reg102;
    T reg106=0.30356120084098635952*elem.pos(5)[0]; reg90=reg29-reg90; reg38=reg104+reg38; reg62=reg62-reg100; reg20=reg92+reg20;
    reg63=reg5+reg63; reg5=0.081338978618764150159*elem.pos(5)[0]; reg74=reg74+reg85; reg18=reg42+reg18; reg60=reg60-reg104;
    reg61=reg61-reg100; reg17=reg67+reg17; reg29=0.081338978618764150166*elem.pos(7)[0]; reg96=reg70+reg96; reg42=0.081338978618764150159*elem.pos(5)[1];
    reg80=reg80-reg97; reg8=reg8-reg104; reg39=reg79-reg39; reg19=reg19-reg100; reg98=reg68+reg98;
    reg15=reg15-reg104; reg76=reg72+reg76; reg64=reg64-reg42; reg74=reg74-reg5; reg19=reg38*reg19;
    reg62=reg60*reg62; reg20=reg100+reg20; reg63=reg63-reg100; reg18=reg18-reg104; reg17=reg104+reg17;
    reg80=reg80-reg29; reg96=reg96-reg97; reg47=reg47-reg36; reg39=reg39-reg94; reg8=reg61*reg8;
    reg98=reg98-reg101; reg15=reg43*reg15; reg76=reg76-reg69; reg38=0.44444444444444449594*elem.pos(8)[0]; reg90=reg90-reg95;
    reg43=0.44444444444444449594*elem.pos(8)[1]; reg86=reg86+reg106; reg93=reg93+reg105; reg35=reg35-reg33; reg74=reg38+reg74;
    reg93=reg93+reg43; reg20=reg18*reg20; reg17=reg63*reg17; reg80=reg106+reg80; reg96=reg85+reg96;
    reg18=0.081338978618764150166*elem.pos(5)[0]; reg47=reg105+reg47; reg39=reg104+reg39; reg15=reg19-reg15; reg76=reg100+reg76;
    reg86=reg86+reg38; reg90=reg100+reg90; reg8=reg62-reg8; reg98=reg99+reg98; reg35=reg104+reg35;
    reg19=0.081338978618764150166*elem.pos(5)[1]; reg64=reg43+reg64; reg47=reg43+reg47; reg98=reg98-reg19; reg64=reg15*reg64;
    reg93=reg8*reg93; reg86=reg86*reg8; reg74=reg74*reg15; reg80=reg38+reg80; reg17=reg20-reg17;
    reg96=reg96-reg18; reg76=reg39*reg76; reg35=reg90*reg35; reg98=reg43+reg98; reg86=0.25*reg86;
    reg74=0.25*reg74; reg80=reg80*reg17; reg47=reg17*reg47; reg96=reg38+reg96; reg35=reg76-reg35;
    reg8=0.25*reg8; reg93=0.25*reg93; reg15=0.25*reg15; reg64=0.25*reg64; reg98=reg35*reg98;
    reg74=reg86+reg74; reg64=reg93+reg64; reg80=0.25*reg80; reg47=0.25*reg47; reg17=0.25*reg17;
    reg15=reg8+reg15; reg96=reg96*reg35; reg47=reg64+reg47; reg17=reg15+reg17; reg80=reg74+reg80;
    reg35=0.25*reg35; reg96=0.25*reg96; reg98=0.25*reg98; reg35=reg17+reg35; reg96=reg80+reg96;
    reg98=reg47+reg98; res[0]=reg96/reg35; res[1]=reg98/reg35;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Quad_9,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.018874775675311855147*elem.pos(1)[1]; T reg1=0.26289171153160429149*elem.pos(0)[1]; T reg2=0.018874775675311855147*elem.pos(1)[0]; T reg3=0.26289171153160429149*elem.pos(0)[0]; T reg4=0.018874775675311855147*elem.pos(0)[1];
    T reg5=0.26289171153160429149*elem.pos(1)[1]; T reg6=0.26289171153160429149*elem.pos(1)[0]; T reg7=0.018874775675311855147*elem.pos(0)[0]; T reg8=0.98112522432468802895*elem.pos(1)[0]; T reg9=0.070441621801729003213*elem.pos(0)[0];
    T reg10=0.018874775675311855147*elem.pos(0)[2]; T reg11=0.26289171153160429149*elem.pos(1)[2]; T reg12=reg0+reg1; T reg13=0.26289171153160429149*elem.pos(0)[2]; T reg14=0.28176648720691614664*elem.pos(4)[1];
    T reg15=reg5+reg4; T reg16=0.018874775675311855147*elem.pos(1)[2]; T reg17=reg6+reg7; T reg18=0.28176648720691614664*elem.pos(4)[0]; T reg19=reg2+reg3;
    T reg20=0.070441621801729003213*elem.pos(0)[1]; T reg21=0.98112522432468802895*elem.pos(1)[1]; T reg22=0.98112522432468802895*elem.pos(3)[1]; T reg23=0.070441621801729003213*elem.pos(3)[1]; T reg24=0.98112522432468802895*elem.pos(0)[1];
    T reg25=0.070441621801729003213*elem.pos(1)[1]; T reg26=reg14-reg15; reg19=reg19-reg18; T reg27=0.070441621801729003213*elem.pos(1)[0]; T reg28=0.98112522432468802895*elem.pos(0)[0];
    reg21=reg21+reg20; T reg29=0.98112522432468802895*elem.pos(3)[0]; T reg30=reg18-reg17; T reg31=0.070441621801729003213*elem.pos(3)[0]; T reg32=0.070441621801729003213*elem.pos(0)[2];
    T reg33=1.0515668461264170322*elem.pos(4)[0]; reg8=reg8+reg9; T reg34=0.98112522432468802895*elem.pos(1)[2]; T reg35=0.28176648720691614664*elem.pos(4)[2]; T reg36=reg11+reg10;
    T reg37=1.0515668461264170322*elem.pos(4)[1]; T reg38=reg16+reg13; reg12=reg12-reg14; reg38=reg38-reg35; T reg39=0.98112522432468802895*elem.pos(3)[2];
    T reg40=0.018874775675311855147*elem.pos(3)[1]; T reg41=0.018874775675311855147*elem.pos(3)[0]; reg21=reg21-reg37; T reg42=reg35-reg36; T reg43=0.070441621801729003213*elem.pos(3)[2];
    reg8=reg8-reg33; T reg44=0.98112522432468802895*elem.pos(2)[0]; reg26=reg26+reg23; T reg45=0.98112522432468802895*elem.pos(2)[1]; T reg46=1.0515668461264170322*elem.pos(4)[2];
    reg34=reg34+reg32; reg29=reg19-reg29; reg19=0.070441621801729003213*elem.pos(2)[0]; T reg47=0.98112522432468802895*elem.pos(0)[2]; T reg48=0.070441621801729003213*elem.pos(1)[2];
    reg24=reg25+reg24; reg22=reg12-reg22; reg12=0.070441621801729003213*elem.pos(2)[1]; reg30=reg30+reg31; reg28=reg27+reg28;
    reg42=reg42+reg43; T reg49=0.98112522432468802895*elem.pos(2)[2]; T reg50=0.26289171153160429149*elem.pos(2)[0]; T reg51=0.26289171153160429149*elem.pos(2)[1]; reg47=reg48+reg47;
    T reg52=0.018874775675311855147*elem.pos(3)[2]; reg34=reg34-reg46; T reg53=0.26289171153160429149*elem.pos(3)[0]; reg8=reg8-reg41; reg21=reg21-reg40;
    reg29=reg29-reg19; reg44=reg30+reg44; reg30=0.26289171153160429149*elem.pos(3)[1]; T reg54=1.0515668461264170322*elem.pos(6)[0]; T reg55=reg33-reg28;
    T reg56=1.0515668461264170322*elem.pos(6)[1]; reg22=reg22-reg12; T reg57=reg37-reg24; reg45=reg26+reg45; reg39=reg38-reg39;
    reg26=0.070441621801729003213*elem.pos(2)[2]; reg38=0.10313369225283431406*elem.pos(7)[1]; T reg58=0.070441621801729003199*elem.pos(1)[0]; T reg59=0.26289171153160429149*elem.pos(3)[2]; reg45=reg45-reg56;
    T reg60=1.4364670255861677246*elem.pos(7)[0]; reg57=reg30+reg57; T reg61=reg46-reg47; T reg62=0.10313369225283431406*elem.pos(7)[0]; reg8=reg8-reg50;
    reg21=reg21-reg51; reg29=reg54+reg29; reg22=reg56+reg22; T reg63=0.018874775675311855147*elem.pos(2)[0]; T reg64=0.070441621801729003199*elem.pos(1)[1];
    T reg65=0.28176648720691614664*elem.pos(6)[1]; reg55=reg53+reg55; T reg66=1.0515668461264170322*elem.pos(6)[2]; reg39=reg39-reg26; reg49=reg42+reg49;
    reg42=0.070441621801729003199*elem.pos(0)[0]; T reg67=0.070441621801729003199*elem.pos(0)[1]; T reg68=0.26289171153160429149*elem.pos(2)[2]; T reg69=0.28176648720691614664*elem.pos(6)[0]; reg44=reg44-reg54;
    T reg70=0.018874775675311855147*elem.pos(2)[1]; T reg71=1.4364670255861677246*elem.pos(7)[1]; reg34=reg34-reg52; reg39=reg66+reg39; T reg72=1.4364670255861677246*elem.pos(7)[2];
    reg8=reg69+reg8; reg2=reg2-reg42; T reg73=0.10313369225283431406*elem.pos(5)[1]; T reg74=0.070441621801729003199*elem.pos(1)[2]; reg22=reg22-reg71;
    reg0=reg0-reg67; T reg75=0.10313369225283431406*elem.pos(5)[0]; T reg76=0.070441621801729003199*elem.pos(0)[2]; reg29=reg29-reg60; reg44=reg44+reg62;
    reg55=reg55+reg63; T reg77=1.4364670255861677246*elem.pos(5)[1]; reg57=reg57+reg70; T reg78=1.4364670255861677246*elem.pos(5)[0]; reg45=reg45+reg38;
    T reg79=0.981125224324688029*elem.pos(1)[0]; T reg80=0.981125224324688029*elem.pos(1)[1]; reg34=reg34-reg68; reg7=reg7-reg58; T reg81=0.10313369225283431404*elem.pos(4)[0];
    T reg82=0.28176648720691614664*elem.pos(6)[2]; reg61=reg59+reg61; T reg83=0.018874775675311855147*elem.pos(2)[2]; reg21=reg65+reg21; reg4=reg4-reg64;
    reg49=reg49-reg66; T reg84=0.10313369225283431406*elem.pos(7)[2]; T reg85=0.10313369225283431404*elem.pos(4)[1]; reg22=reg22-reg73; reg45=reg45+reg77;
    T reg86=1.5396007178390020388*elem.pos(8)[1]; T reg87=0.981125224324688029*elem.pos(1)[2]; reg39=reg39-reg72; T reg88=1.5396007178390020388*elem.pos(8)[0]; reg44=reg44+reg78;
    reg55=reg55-reg69; reg57=reg57-reg65; reg29=reg29-reg75; reg61=reg61+reg83; T reg89=0.981125224324688029*elem.pos(0)[0];
    T reg90=0.981125224324688029*elem.pos(0)[1]; reg34=reg82+reg34; reg79=reg79-reg3; T reg91=0.10313369225283431404*elem.pos(4)[2]; reg10=reg10-reg74;
    reg16=reg16-reg76; reg7=reg7-reg81; T reg92=1.4364670255861677246*elem.pos(4)[0]; reg21=reg38+reg21; reg8=reg62+reg8;
    reg0=reg0-reg85; reg80=reg80-reg1; T reg93=0.981125224324688029*elem.pos(3)[1]; T reg94=1.4364670255861677246*elem.pos(4)[1]; reg2=reg2-reg81;
    T reg95=1.4364670255861677246*elem.pos(5)[2]; reg4=reg4-reg85; reg49=reg49+reg84; T reg96=0.981125224324688029*elem.pos(3)[0]; T reg97=0.10313369225283431406*elem.pos(5)[2];
    reg61=reg61-reg82; reg8=reg78+reg8; reg89=reg89-reg6; reg21=reg77+reg21; reg90=reg90-reg5;
    reg77=0.981125224324688029*elem.pos(0)[2]; reg29=reg88+reg29; reg34=reg84+reg34; reg71=reg57-reg71; reg16=reg16-reg91;
    reg60=reg55-reg60; reg55=0.981125224324688029*elem.pos(3)[2]; reg79=reg79+reg92; reg0=reg93-reg0; reg22=reg86+reg22;
    reg57=1.4364670255861677246*elem.pos(4)[2]; reg2=reg96-reg2; reg87=reg87-reg13; reg80=reg80+reg94; reg39=reg39-reg97;
    reg49=reg49+reg95; reg44=reg44-reg88; reg78=1.5396007178390020388*elem.pos(8)[2]; reg10=reg10-reg91; reg93=0.981125224324688029*elem.pos(2)[1];
    reg4=reg30+reg4; reg45=reg45-reg86; reg7=reg53+reg7; reg96=0.981125224324688029*elem.pos(2)[0]; T reg98=0.981125224324688029*elem.pos(2)[2];
    reg72=reg61-reg72; reg61=pow(reg45,2); T reg99=0.070441621801729003199*elem.pos(3)[0]; reg89=reg92+reg89; reg92=0.070441621801729003199*elem.pos(3)[1];
    reg90=reg94+reg90; reg94=pow(reg44,2); reg87=reg87+reg57; reg16=reg55-reg16; reg0=reg0-reg51;
    reg2=reg2-reg50; reg39=reg78+reg39; reg10=reg59+reg10; reg8=reg8-reg88; reg93=reg93-reg4;
    reg55=1.4364670255861677246*elem.pos(6)[1]; reg21=reg21-reg86; reg96=reg96-reg7; T reg100=1.4364670255861677246*elem.pos(6)[0]; reg34=reg95+reg34;
    reg95=0.070441621801729003199*elem.pos(2)[1]; reg71=reg71-reg73; reg79=reg41-reg79; reg41=0.070441621801729003199*elem.pos(2)[0]; reg49=reg49-reg78;
    reg80=reg40-reg80; reg40=pow(reg29,2); reg77=reg77-reg11; T reg101=pow(reg22,2); reg60=reg60-reg75;
    reg60=reg88+reg60; reg0=reg55+reg0; T reg102=1.0515668461264170322*elem.pos(7)[1]; reg16=reg16-reg68; T reg103=0.10313369225283431404*elem.pos(6)[1];
    reg90=reg92+reg90; reg89=reg99+reg89; reg101=reg40+reg101; reg72=reg72-reg97; reg98=reg98-reg10;
    reg40=1.4364670255861677246*elem.pos(6)[2]; T reg104=0.28176648720691614667*elem.pos(7)[1]; reg79=reg79-reg41; T reg105=pow(reg8,2); reg93=reg55+reg93;
    reg55=0.28176648720691614667*elem.pos(7)[0]; reg96=reg100+reg96; T reg106=pow(reg21,2); T reg107=pow(reg49,2); reg80=reg80-reg95;
    T reg108=0.10313369225283431404*elem.pos(6)[0]; reg34=reg34-reg78; reg71=reg86+reg71; reg2=reg100+reg2; reg100=pow(reg39,2);
    reg77=reg57+reg77; reg61=reg94+reg61; reg57=0.070441621801729003199*elem.pos(3)[2]; reg94=0.070441621801729003199*elem.pos(2)[2]; T reg109=1.0515668461264170322*elem.pos(7)[0];
    reg87=reg52-reg87; reg16=reg40+reg16; reg52=1.0515668461264170322*elem.pos(7)[2]; reg63=reg63-reg89; T reg110=pow(reg34,2);
    reg107=reg61+reg107; reg70=reg70-reg90; reg100=reg101+reg100; reg61=1.0515668461264170322*elem.pos(5)[0]; reg96=reg96+reg55;
    reg2=reg2-reg109; reg80=reg80-reg103; reg101=pow(reg60,2); reg106=reg105+reg106; reg105=pow(reg71,2);
    reg79=reg79-reg108; reg87=reg87-reg94; reg77=reg57+reg77; T reg111=1.0515668461264170322*elem.pos(5)[1]; reg93=reg93+reg104;
    reg0=reg0-reg102; T reg112=0.28176648720691614667*elem.pos(5)[1]; reg72=reg78+reg72; T reg113=0.10313369225283431404*elem.pos(6)[2]; T reg114=0.28176648720691614667*elem.pos(7)[2];
    reg98=reg40+reg98; reg40=0.28176648720691614667*elem.pos(5)[0]; T reg115=pow(reg72,2); reg96=reg96-reg61; reg79=reg79-reg55;
    reg63=reg63-reg108; reg93=reg93-reg111; reg87=reg87-reg113; reg70=reg70-reg103; T reg116=1.0515668461264170322*elem.pos(5)[2];
    reg105=reg101+reg105; reg107=pow(reg107,0.5); reg98=reg98+reg114; reg80=reg80-reg104; reg2=reg2+reg40;
    reg0=reg0+reg112; reg100=pow(reg100,0.5); reg83=reg83-reg77; reg16=reg16-reg52; reg101=0.28176648720691614667*elem.pos(5)[2];
    reg110=reg106+reg110; reg98=reg98-reg116; reg115=reg105+reg115; reg110=pow(reg110,0.5); reg0=reg0-reg86;
    reg2=reg2-reg88; reg93=reg93-reg86; reg87=reg87-reg114; reg96=reg96-reg88; reg79=reg61+reg79;
    reg16=reg16+reg101; reg70=reg102+reg70; reg63=reg109+reg63; reg105=reg44/reg107; reg106=reg45/reg107;
    T reg117=reg29/reg100; T reg118=reg22/reg100; reg83=reg83-reg113; reg80=reg111+reg80; T reg119=reg106*reg93;
    T reg120=reg21/reg110; T reg121=reg8/reg110; reg107=reg49/reg107; reg100=reg39/reg100; T reg122=reg105*reg96;
    reg70=reg70-reg112; reg83=reg52+reg83; reg79=reg88+reg79; reg63=reg63-reg40; reg16=reg16-reg78;
    T reg123=reg118*reg0; reg115=pow(reg115,0.5); reg98=reg98-reg78; T reg124=reg117*reg2; reg80=reg86+reg80;
    reg87=reg116+reg87; reg83=reg83-reg101; T reg125=reg60/reg115; reg119=reg122+reg119; reg122=reg121*reg79;
    reg63=reg88+reg63; reg110=reg34/reg110; T reg126=reg100*reg16; T reg127=reg71/reg115; reg123=reg124+reg123;
    reg87=reg78+reg87; reg124=reg120*reg80; T reg128=reg107*reg98; reg70=reg86+reg70; reg126=reg123+reg126;
    reg128=reg119+reg128; reg83=reg78+reg83; reg119=reg125*reg63; reg115=reg72/reg115; reg124=reg122+reg124;
    reg122=reg110*reg87; reg123=reg127*reg70; T reg129=reg115*reg83; reg123=reg119+reg123; reg119=reg118*reg126;
    T reg130=reg105*reg128; T reg131=reg117*reg126; T reg132=reg106*reg128; reg122=reg124+reg122; reg124=reg107*reg128;
    reg132=reg93-reg132; reg130=reg96-reg130; T reg133=reg121*reg122; reg129=reg123+reg129; reg131=reg2-reg131;
    reg119=reg0-reg119; reg123=reg100*reg126; T reg134=reg120*reg122; reg124=reg98-reg124; T reg135=reg110*reg122;
    reg134=reg80-reg134; T reg136=pow(reg132,2); T reg137=pow(reg130,2); reg133=reg79-reg133; T reg138=reg127*reg129;
    T reg139=reg125*reg129; reg123=reg16-reg123; T reg140=pow(reg119,2); T reg141=pow(reg131,2); T reg142=0.014886066246173484324*elem.pos(0)[2];
    T reg143=0.055555555555555552339*elem.pos(1)[2]; T reg144=0.014886066246173484324*elem.pos(0)[0]; T reg145=pow(reg133,2); T reg146=pow(reg134,2); reg135=reg87-reg135;
    T reg147=0.055555555555555552339*elem.pos(1)[0]; T reg148=0.014886066246173484324*elem.pos(0)[1]; T reg149=0.055555555555555552339*elem.pos(1)[1]; T reg150=0.055555555555555552339*elem.pos(0)[1]; T reg151=0.014886066246173484324*elem.pos(1)[1];
    T reg152=0.055555555555555552339*elem.pos(0)[0]; T reg153=0.014886066246173484324*elem.pos(1)[0]; T reg154=reg115*reg129; reg138=reg70-reg138; reg139=reg63-reg139;
    T reg155=pow(reg124,2); reg136=reg137+reg136; reg140=reg141+reg140; reg137=pow(reg123,2); reg141=0.014886066246173484324*elem.pos(1)[2];
    T reg156=0.055555555555555552339*elem.pos(0)[2]; reg142=reg142-reg143; T reg157=0.081338978618764150166*elem.pos(4)[2]; reg148=reg148-reg149; T reg158=0.081338978618764150166*elem.pos(4)[1];
    T reg159=0.081338978618764150166*elem.pos(4)[0]; reg144=reg144-reg147; T reg160=pow(reg135,2); reg151=reg151-reg150; reg146=reg145+reg146;
    reg137=reg140+reg137; reg153=reg153-reg152; reg154=reg83-reg154; reg140=pow(reg138,2); reg141=reg141-reg156;
    reg145=pow(reg139,2); T reg161=0.20733615597604870572*elem.pos(1)[1]; T reg162=0.20733615597604870572*elem.pos(1)[0]; reg155=reg136+reg155; reg136=0.20733615597604870572*elem.pos(1)[2];
    T reg163=0.30356120084098635952*elem.pos(4)[1]; reg161=reg161-reg150; T reg164=0.20733615597604870572*elem.pos(0)[0]; T reg165=0.20733615597604870572*elem.pos(0)[1]; reg148=reg148-reg158;
    T reg166=0.055555555555555552339*elem.pos(3)[1]; T reg167=0.055555555555555552339*elem.pos(3)[0]; reg144=reg144-reg159; reg151=reg151-reg158; T reg168=pow(reg154,2);
    T reg169=0.20733615597604870572*elem.pos(3)[1]; T reg170=0.20733615597604870572*elem.pos(3)[0]; T reg171=0.055555555555555552339*elem.pos(3)[2]; reg140=reg145+reg140; reg160=reg146+reg160;
    reg142=reg142-reg157; reg145=0.20733615597604870572*elem.pos(3)[2]; reg141=reg141-reg157; reg136=reg136-reg156; reg146=0.30356120084098635952*elem.pos(4)[2];
    reg137=pow(reg137,0.5); reg155=pow(reg155,0.5); reg153=reg153-reg159; reg162=reg162-reg152; T reg172=0.20733615597604870572*elem.pos(0)[2];
    T reg173=0.30356120084098635952*elem.pos(4)[0]; reg144=reg144-reg167; reg162=reg162+reg173; reg169=reg151+reg169; reg151=0.055555555555555552339*elem.pos(2)[1];
    T reg174=0.014886066246173484324*elem.pos(3)[0]; reg160=pow(reg160,0.5); T reg175=0.20733615597604870572*elem.pos(2)[2]; T reg176=0.055555555555555552339*elem.pos(2)[2]; reg161=reg161+reg163;
    reg145=reg141+reg145; reg141=0.014886066246173484324*elem.pos(3)[2]; reg168=reg140+reg168; reg136=reg136+reg146; reg172=reg172-reg143;
    reg130=reg130/reg155; reg164=reg164-reg147; reg132=reg132/reg155; reg148=reg148-reg166; reg140=0.20733615597604870572*elem.pos(2)[1];
    reg131=reg131/reg137; reg165=reg165-reg149; reg119=reg119/reg137; T reg177=0.20733615597604870572*elem.pos(2)[0]; reg142=reg142-reg171;
    reg170=reg153+reg170; reg153=0.014886066246173484324*elem.pos(3)[1]; T reg178=0.055555555555555552339*elem.pos(2)[0]; reg0=reg0*reg119; T reg179=reg44*reg130;
    reg2=reg2*reg131; reg137=reg123/reg137; reg93=reg93*reg132; reg119=reg22*reg119; reg145=reg145-reg176;
    reg131=reg29*reg131; reg130=reg96*reg130; reg155=reg124/reg155; reg132=reg45*reg132; reg118=reg22*reg118;
    reg117=reg29*reg117; reg22=0.30356120084098635952*elem.pos(6)[2]; reg172=reg146+reg172; reg29=0.30356120084098635952*elem.pos(6)[1]; reg164=reg173+reg164;
    reg165=reg163+reg165; reg140=reg148+reg140; reg170=reg170-reg178; reg153=reg161+reg153; reg177=reg144+reg177;
    reg134=reg134/reg160; reg133=reg133/reg160; reg96=0.30356120084098635952*elem.pos(6)[0]; reg174=reg162+reg174; reg141=reg136+reg141;
    reg168=pow(reg168,0.5); reg106=reg45*reg106; reg105=reg44*reg105; reg169=reg169-reg151; reg175=reg142+reg175;
    reg98=reg98*reg155; reg93=reg130+reg93; reg169=reg29+reg169; reg132=reg179+reg132; reg44=0.081338978618764150159*elem.pos(7)[1];
    reg140=reg29+reg140; reg155=reg49*reg155; reg138=reg138/reg168; reg170=reg96+reg170; reg29=0.30356120084098635952*elem.pos(7)[0];
    reg139=reg139/reg168; reg141=reg141-reg176; reg45=0.081338978618764150166*elem.pos(6)[2]; reg107=reg49*reg107; reg106=reg105+reg106;
    reg121=reg8*reg121; reg120=reg21*reg120; reg175=reg22+reg175; reg79=reg79*reg133; reg80=reg80*reg134;
    reg160=reg135/reg160; reg177=reg96+reg177; reg49=0.081338978618764150159*elem.pos(7)[0]; reg153=reg153-reg151; reg96=0.014886066246173484324*elem.pos(2)[2];
    reg133=reg8*reg133; reg165=reg165-reg166; reg8=0.014886066246173484324*elem.pos(2)[1]; reg105=0.014886066246173484324*elem.pos(2)[0]; reg164=reg164-reg167;
    reg134=reg21*reg134; reg172=reg172-reg171; reg16=reg16*reg137; reg21=0.30356120084098635952*elem.pos(7)[2]; reg119=reg131+reg119;
    reg0=reg2+reg0; reg100=reg39*reg100; reg137=reg39*reg137; reg145=reg22+reg145; reg2=0.30356120084098635952*elem.pos(7)[1];
    reg22=0.081338978618764150166*elem.pos(6)[0]; reg39=0.081338978618764150166*elem.pos(6)[1]; reg174=reg174-reg178; reg118=reg117+reg118; reg117=0.081338978618764150159*elem.pos(7)[2];
    reg123=0.081338978618764150166*elem.pos(7)[2]; reg8=reg165+reg8; reg141=reg141-reg45; reg124=0.081338978618764150159*elem.pos(5)[2]; reg96=reg172+reg96;
    reg145=reg145+reg21; reg130=0.081338978618764150166*elem.pos(7)[1]; reg140=reg140-reg44; reg131=0.30356120084098635952*elem.pos(5)[1]; reg153=reg153-reg39;
    reg169=reg169+reg2; reg135=0.081338978618764150159*elem.pos(5)[1]; reg136=0.30356120084098635952*elem.pos(5)[2]; reg175=reg175-reg117; reg127=reg71*reg127;
    reg142=0.081338978618764150166*elem.pos(7)[0]; reg174=reg174-reg22; reg125=reg125*reg60; reg177=reg177-reg49; reg144=0.30356120084098635952*elem.pos(5)[0];
    reg63=reg63*reg139; reg70=reg70*reg138; reg168=reg154/reg168; reg137=reg119+reg137; reg139=reg60*reg139;
    reg138=reg71*reg138; reg16=reg0+reg16; reg100=reg118+reg100; reg107=reg106+reg107; reg120=reg121+reg120;
    reg110=reg34*reg110; reg34=reg34*reg160; reg80=reg79+reg80; reg98=reg93+reg98; reg134=reg133+reg134;
    reg160=reg87*reg160; reg155=reg132+reg155; reg105=reg164+reg105; reg0=0.081338978618764150159*elem.pos(5)[0]; reg170=reg170+reg29;
    reg34=reg134+reg34; reg8=reg8-reg39; reg60=0.44444444444444449594*elem.pos(8)[2]; reg105=reg105-reg22; reg160=reg80+reg160;
    reg177=reg177+reg144; reg71=0.44444444444444449594*elem.pos(8)[0]; reg175=reg175+reg136; reg110=reg120+reg110; reg153=reg153-reg130;
    reg96=reg96-reg45; reg141=reg141-reg123; reg170=reg170-reg0; reg155=reg128*reg155; reg98=reg107*reg98;
    reg79=reg72*reg168; reg138=reg139+reg138; reg140=reg140+reg131; reg80=0.44444444444444449594*elem.pos(8)[1]; reg145=reg145-reg124;
    reg16=reg100*reg16; reg168=reg83*reg168; reg70=reg63+reg70; reg137=reg126*reg137; reg115=reg72*reg115;
    reg174=reg174-reg142; reg127=reg125+reg127; reg169=reg169-reg135; reg34=reg122*reg34; reg170=reg71+reg170;
    reg141=reg136+reg141; reg137=reg16-reg137; reg160=reg110*reg160; reg155=reg98-reg155; reg175=reg175+reg60;
    reg145=reg60+reg145; reg174=reg144+reg174; reg169=reg80+reg169; reg177=reg177+reg71; reg153=reg131+reg153;
    reg115=reg127+reg115; reg168=reg70+reg168; reg140=reg140+reg80; reg79=reg138+reg79; reg16=0.081338978618764150166*elem.pos(5)[0];
    reg105=reg29+reg105; reg8=reg2+reg8; reg2=0.081338978618764150166*elem.pos(5)[1]; reg29=0.081338978618764150166*elem.pos(5)[2]; reg96=reg21+reg96;
    reg145=reg137*reg145; reg79=reg129*reg79; reg140=reg155*reg140; reg168=reg115*reg168; reg177=reg177*reg155;
    reg96=reg96-reg29; reg141=reg60+reg141; reg170=reg170*reg137; reg169=reg137*reg169; reg175=reg155*reg175;
    reg34=reg160-reg34; reg174=reg71+reg174; reg153=reg80+reg153; reg8=reg8-reg2; reg105=reg105-reg16;
    reg137=0.25*reg137; reg177=0.25*reg177; reg8=reg80+reg8; reg96=reg60+reg96; reg79=reg168-reg79;
    reg174=reg174*reg34; reg145=0.25*reg145; reg105=reg71+reg105; reg141=reg34*reg141; reg140=0.25*reg140;
    reg153=reg34*reg153; reg155=0.25*reg155; reg170=0.25*reg170; reg169=0.25*reg169; reg175=0.25*reg175;
    reg174=0.25*reg174; reg34=0.25*reg34; reg141=0.25*reg141; reg8=reg79*reg8; reg137=reg155+reg137;
    reg96=reg79*reg96; reg105=reg105*reg79; reg145=reg175+reg145; reg153=0.25*reg153; reg170=reg177+reg170;
    reg169=reg140+reg169; reg96=0.25*reg96; reg141=reg145+reg141; reg8=0.25*reg8; reg153=reg169+reg153;
    reg79=0.25*reg79; reg34=reg137+reg34; reg105=0.25*reg105; reg174=reg170+reg174; reg8=reg153+reg8;
    reg79=reg34+reg79; reg105=reg174+reg105; reg96=reg141+reg96; res[2]=reg96/reg79; res[1]=reg8/reg79;
    res[0]=reg105/reg79;

    return res;
}
}
#endif // LMT_QUAD_9
