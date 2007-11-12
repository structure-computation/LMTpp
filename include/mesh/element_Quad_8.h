#ifndef LMT_QUAD_8
#define LMT_QUAD_8
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_8 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 13, 26, 39, 52, 74, 96, 118, 140, 162, }; // fonction de lordre du poly
    static const double values[] = {
        0.25,0.788675134595,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.788675134595,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.788675134595,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.788675134595,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.788675134595,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
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
<<<<<<< HEAD:include/mesh/element_Quad_8.h
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; reg0=reg0-1; T reg2=1-reg0; reg1=reg1-1;
    T reg3=1+reg0; T reg4=0.25*reg2; T reg5=reg0-reg1; T reg6=1-reg1; T reg7=0.25*reg3;
    T reg8=reg0+reg1; T reg9=reg4*reg6; T reg10=1+reg8; T reg11=0.5*reg3; T reg12=0.5*reg6;
    T reg13=1+reg1; T reg14=reg6*reg7; reg5=reg5-1; T reg15=0.5*reg2; T reg16=reg10*reg15;
    reg7=reg13*reg7; reg8=reg8-1; T reg17=reg5*reg11; T reg18=2*reg14; T reg19=reg5*reg12;
    T reg20=2*reg9; T reg21=reg10*reg12; T reg22=reg1-reg0; T reg23=0.5*reg13; T reg24=reg8*reg23;
    reg17=reg18+reg17; reg19=reg18+reg19; reg21=reg20-reg21; reg18=2*reg7; T reg25=pow(reg0,2);
    reg22=reg22-1; reg5=reg14*reg5; reg10=reg9*reg10; reg16=reg20-reg16; reg9=reg8*reg11;
    reg4=reg4*reg13; reg14=pos_nodes[1][0]*reg17; reg25=1-reg25; reg8=reg7*reg8; reg24=reg18+reg24;
    reg7=2*reg4; reg20=reg22*reg23; T reg26=pos_nodes[1][1]*reg19; T reg27=pos_nodes[0][1]*reg21; T reg28=pos_nodes[1][0]*reg19;
    T reg29=pos_nodes[0][0]*reg21; T reg30=pow(reg1,2); T reg31=reg22*reg15; T reg32=reg10*pos_nodes[0][0]; T reg33=reg5*pos_nodes[1][0];
    T reg34=pos_nodes[0][0]*reg16; T reg35=pos_nodes[1][1]*reg17; T reg36=pos_nodes[0][1]*reg16; reg9=reg18+reg9; reg18=reg5*pos_nodes[1][1];
    T reg37=reg10*pos_nodes[0][1]; T reg38=pos_nodes[2][0]*reg24; T reg39=reg8*pos_nodes[2][0]; reg32=reg33-reg32; reg34=reg14+reg34;
    reg14=pos_nodes[2][0]*reg9; reg31=reg7+reg31; reg22=reg4*reg22; reg4=0.5*reg25; reg30=1-reg30;
    reg33=reg8*pos_nodes[2][1]; reg37=reg18-reg37; reg36=reg35+reg36; reg18=pos_nodes[2][1]*reg9; reg35=pos_nodes[2][1]*reg24;
    reg20=reg7+reg20; reg7=2*reg0; reg27=reg26-reg27; reg29=reg28-reg29; reg34=reg14-reg34;
    reg14=pos_nodes[3][1]*reg20; reg26=pos_nodes[3][0]*reg31; reg35=reg27+reg35; reg36=reg18-reg36; reg18=pos_nodes[3][1]*reg31;
    reg39=reg32+reg39; reg33=reg37+reg33; reg27=reg22*pos_nodes[3][0]; reg28=reg22*pos_nodes[3][1]; reg32=2*reg1;
    reg37=pos_nodes[3][0]*reg20; reg38=reg29+reg38; reg29=reg6*reg7; reg6=reg4*reg6; T reg40=0.5*reg30;
    T reg41=reg6*pos_nodes[4][0]; reg27=reg39+reg27; reg37=reg38-reg37; reg38=pos_nodes[4][0]*reg29; reg39=reg25*pos_nodes[4][1];
    T reg42=reg40*reg3; reg28=reg33+reg28; reg18=reg36+reg18; reg33=reg25*pos_nodes[4][0]; reg26=reg34+reg26;
    reg34=reg6*pos_nodes[4][1]; reg14=reg35-reg14; reg35=pos_nodes[4][1]*reg29; reg3=reg3*reg32; reg36=reg13*reg7;
    reg39=reg18-reg39; reg18=pos_nodes[5][1]*reg3; reg35=reg14-reg35; reg14=reg30*pos_nodes[5][1]; T reg43=reg42*pos_nodes[5][0];
    reg41=reg27+reg41; reg38=reg37-reg38; reg27=reg30*pos_nodes[5][0]; reg13=reg4*reg13; reg4=pos_nodes[5][0]*reg3;
    reg33=reg26-reg33; reg34=reg28+reg34; reg26=reg42*pos_nodes[5][1]; reg18=reg39-reg18; reg28=reg25*pos_nodes[6][1];
    reg40=reg40*reg2; reg26=reg34+reg26; reg34=reg13*pos_nodes[6][1]; reg37=pos_nodes[6][0]*reg36; reg4=reg33-reg4;
    reg33=reg25*pos_nodes[6][0]; reg27=reg38+reg27; reg43=reg41+reg43; reg38=reg13*pos_nodes[6][0]; reg2=reg2*reg32;
    reg39=pos_nodes[6][1]*reg36; reg14=reg35+reg14; reg35=reg30*pos_nodes[7][1]; reg39=reg14-reg39; reg33=reg4+reg33;
    reg4=pos_nodes[7][0]*reg2; reg37=reg27-reg37; reg14=reg30*pos_nodes[7][0]; reg27=pos_nodes[7][1]*reg2; reg28=reg18+reg28;
    reg38=reg43+reg38; reg18=reg40*pos_nodes[7][0]; reg41=reg40*pos_nodes[7][1]; reg34=reg26+reg34; reg14=reg37-reg14;
    reg41=reg34+reg41; reg4=reg33-reg4; reg27=reg28-reg27; reg18=reg38+reg18; reg35=reg39-reg35;
    reg18=pos[0]-reg18; reg41=pos[1]-reg41; reg26=var_inter[0]*reg14; reg28=reg4*reg35; reg33=var_inter[0]*reg35;
    reg34=reg14*reg27; reg28=reg34-reg28; reg33=reg41+reg33; reg37=var_inter[1]*reg27; reg26=reg18+reg26;
    reg18=var_inter[1]*reg4; reg26=reg18+reg26; reg33=reg37+reg33; reg18=reg27/reg28; reg37=reg35/reg28;
    reg38=reg4/reg28; reg28=reg14/reg28; reg18=reg26*reg18; reg38=reg33*reg38; reg37=reg26*reg37;
    reg28=reg33*reg28; var_inter[0]=reg18-reg38; var_inter[1]=reg28-reg37;
=======
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; reg0=reg0-1; reg1=reg1-1; T reg2=1-reg0;
    T reg3=1+reg0; T reg4=reg1+reg0; T reg5=reg0-reg1; T reg6=0.25*reg3; T reg7=1-reg1;
    T reg8=0.25*reg2; reg5=reg5-1; T reg9=0.5*reg2; T reg10=0.5*reg3; T reg11=reg7*reg6;
    T reg12=0.5*reg7; T reg13=1+reg4; T reg14=reg8*reg7; T reg15=1+reg1; T reg16=0.5*reg15;
    T reg17=reg13*reg12; T reg18=2*reg14; T reg19=reg12*reg5; T reg20=2*reg11; reg6=reg15*reg6;
    reg4=reg4-1; T reg21=reg1-reg0; T reg22=reg13*reg9; T reg23=reg5*reg10; reg21=reg21-1;
    reg8=reg8*reg15; T reg24=pow(reg0,2); T reg25=reg4*reg10; reg5=reg11*reg5; reg22=reg18-reg22;
    reg11=reg16*reg4; T reg26=2*reg6; reg23=reg20+reg23; reg13=reg14*reg13; reg17=reg18-reg17;
    reg19=reg20+reg19; reg14=pos_nodes[0][0]*reg17; reg18=pos_nodes[1][0]*reg19; reg20=pos_nodes[0][1]*reg13; T reg27=pos_nodes[1][1]*reg5;
    reg25=reg26+reg25; T reg28=reg21*reg9; T reg29=pow(reg1,2); T reg30=pos_nodes[1][0]*reg23; reg24=1-reg24;
    T reg31=pos_nodes[0][0]*reg22; T reg32=pos_nodes[0][1]*reg22; reg11=reg26+reg11; reg26=2*reg8; T reg33=reg16*reg21;
    T reg34=pos_nodes[0][0]*reg13; T reg35=pos_nodes[1][0]*reg5; reg4=reg6*reg4; reg6=pos_nodes[1][1]*reg19; T reg36=pos_nodes[0][1]*reg17;
    T reg37=pos_nodes[1][1]*reg23; T reg38=pos_nodes[2][0]*reg25; reg28=reg26+reg28; T reg39=reg4*pos_nodes[2][0]; reg31=reg30+reg31;
    reg36=reg6-reg36; reg32=reg37+reg32; reg34=reg35-reg34; reg20=reg27-reg20; reg6=reg4*pos_nodes[2][1];
    reg27=pos_nodes[2][1]*reg11; reg30=pos_nodes[2][1]*reg25; reg35=0.5*reg24; reg29=1-reg29; reg21=reg8*reg21;
    reg33=reg26+reg33; reg8=2*reg0; reg14=reg18-reg14; reg18=pos_nodes[2][0]*reg11; reg26=reg7*reg35;
    reg31=reg38-reg31; reg37=pos_nodes[3][0]*reg28; reg38=pos_nodes[3][1]*reg28; reg32=reg30-reg32; reg7=reg7*reg8;
    reg30=2*reg1; reg39=reg34+reg39; reg34=pos_nodes[3][0]*reg21; T reg40=pos_nodes[3][1]*reg33; reg27=reg36+reg27;
    reg36=0.5*reg29; T reg41=pos_nodes[3][1]*reg21; reg18=reg14+reg18; reg14=pos_nodes[3][0]*reg33; reg6=reg20+reg6;
    reg20=pos_nodes[4][0]*reg7; reg40=reg27-reg40; reg27=pos_nodes[4][1]*reg7; T reg42=pos_nodes[4][0]*reg26; reg34=reg39+reg34;
    reg39=pos_nodes[4][1]*reg26; reg41=reg6+reg41; reg14=reg18-reg14; reg38=reg32+reg38; reg6=pos_nodes[4][1]*reg24;
    reg18=pos_nodes[4][0]*reg24; reg37=reg31+reg37; reg31=reg3*reg36; reg3=reg3*reg30; reg6=reg38-reg6;
    reg39=reg41+reg39; reg32=pos_nodes[5][1]*reg29; reg27=reg40-reg27; reg38=pos_nodes[5][1]*reg3; reg40=pos_nodes[5][1]*reg31;
    reg41=reg15*reg8; reg18=reg37-reg18; reg37=pos_nodes[5][0]*reg3; T reg43=pos_nodes[5][0]*reg29; reg20=reg14-reg20;
    reg42=reg34+reg42; reg14=pos_nodes[5][0]*reg31; reg35=reg15*reg35; reg15=pos_nodes[6][1]*reg24; reg38=reg6-reg38;
    reg37=reg18-reg37; reg6=pos_nodes[6][0]*reg24; reg40=reg39+reg40; reg18=reg2*reg30; reg34=pos_nodes[6][1]*reg41;
    reg32=reg27+reg32; reg14=reg42+reg14; reg27=pos_nodes[6][0]*reg35; reg36=reg2*reg36; reg43=reg20+reg43;
    reg2=pos_nodes[6][1]*reg35; reg20=pos_nodes[6][0]*reg41; reg39=pos_nodes[7][1]*reg18; reg42=pos_nodes[7][0]*reg29; reg20=reg43-reg20;
    reg15=reg38+reg15; reg6=reg37+reg6; reg37=pos_nodes[7][0]*reg18; reg38=pos_nodes[7][1]*reg29; reg34=reg32-reg34;
    reg27=reg14+reg27; reg14=pos_nodes[7][0]*reg36; reg2=reg40+reg2; reg32=pos_nodes[7][1]*reg36; reg32=reg2+reg32;
    reg42=reg20-reg42; reg39=reg15-reg39; reg37=reg6-reg37; reg38=reg34-reg38; reg14=reg27+reg14;
    reg14=pos[0]-reg14; reg32=pos[1]-reg32; reg2=var_inter[0]*reg42; reg6=reg37*reg38; reg15=var_inter[0]*reg38;
    reg20=reg42*reg39; reg6=reg20-reg6; reg15=reg32+reg15; reg27=var_inter[1]*reg39; reg2=reg14+reg2;
    reg14=var_inter[1]*reg37; reg2=reg14+reg2; reg15=reg27+reg15; reg14=reg39/reg6; reg27=reg38/reg6;
    reg32=reg37/reg6; reg6=reg42/reg6; reg14=reg2*reg14; reg32=reg15*reg32; reg27=reg2*reg27;
    reg6=reg15*reg6; var_inter[0]=reg14-reg32; var_inter[1]=reg6-reg27;
>>>>>>> 512dc2050926bfccc64f86a01cb2ce23c8050af9:include/mesh/element_Quad_8.h

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_8 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; reg1=reg1-1; T reg2=1-reg0;
<<<<<<< HEAD:include/mesh/element_Quad_8.h
    T reg3=1+reg0; T reg4=reg0-reg1; T reg5=0.25*reg3; T reg6=reg0+reg1; T reg7=1-reg1;
    T reg8=0.25*reg2; T reg9=0.5*reg3; T reg10=0.5*reg2; T reg11=0.5*reg7; reg4=reg4-1;
    T reg12=reg7*reg5; T reg13=1+reg1; T reg14=1+reg6; T reg15=reg8*reg7; T reg16=0.5*reg13;
    T reg17=reg14*reg10; T reg18=reg14*reg11; T reg19=reg4*reg9; T reg20=2*reg15; T reg21=reg1-reg0;
    T reg22=reg4*reg11; T reg23=2*reg12; reg6=reg6-1; reg5=reg13*reg5; reg22=reg23+reg22;
    reg19=reg23+reg19; reg14=reg15*reg14; reg18=reg20-reg18; reg4=reg12*reg4; reg8=reg8*reg13;
    reg21=reg21-1; reg12=pow(reg0,2); reg15=reg6*reg16; reg23=reg6*reg9; reg17=reg20-reg17;
    reg20=2*reg5; reg15=reg20+reg15; T reg24=2*reg8; T reg25=reg21*reg16; T reg26=pos_nodes[1][1]*reg22;
    T reg27=pos_nodes[0][1]*reg18; T reg28=pos_nodes[1][0]*reg22; T reg29=pos_nodes[0][0]*reg18; reg6=reg5*reg6; reg12=1-reg12;
    reg5=pos_nodes[1][0]*reg19; T reg30=pow(reg1,2); T reg31=reg21*reg10; reg23=reg20+reg23; reg20=reg14*pos_nodes[0][1];
    T reg32=reg4*pos_nodes[1][1]; T reg33=pos_nodes[0][1]*reg17; T reg34=pos_nodes[1][1]*reg19; T reg35=pos_nodes[0][0]*reg17; T reg36=reg4*pos_nodes[1][0];
    T reg37=pos_nodes[0][0]*reg14; reg31=reg24+reg31; reg37=reg36-reg37; reg36=reg6*pos_nodes[2][0]; reg35=reg5+reg35;
    reg5=pos_nodes[2][0]*reg23; T reg38=pos_nodes[2][0]*reg15; reg21=reg8*reg21; reg8=0.5*reg12; reg30=1-reg30;
    T reg39=reg6*pos_nodes[2][1]; reg20=reg32-reg20; reg33=reg34+reg33; reg32=pos_nodes[2][1]*reg23; reg34=pos_nodes[2][1]*reg15;
    reg25=reg24+reg25; reg24=2*reg0; reg27=reg26-reg27; reg29=reg28-reg29; reg35=reg5-reg35;
    reg5=pos_nodes[3][1]*reg25; reg26=pos_nodes[3][0]*reg31; reg34=reg27+reg34; reg33=reg32-reg33; reg27=pos_nodes[3][1]*reg31;
    reg36=reg37+reg36; reg39=reg20+reg39; reg20=reg21*pos_nodes[3][0]; reg28=reg21*pos_nodes[3][1]; reg32=2*reg1;
    reg37=pos_nodes[3][0]*reg25; reg38=reg29+reg38; reg29=reg7*reg24; reg7=reg7*reg8; T reg40=0.5*reg30;
    T reg41=reg7*pos_nodes[4][0]; reg20=reg36+reg20; reg37=reg38-reg37; reg36=pos_nodes[4][0]*reg29; reg38=reg12*pos_nodes[4][1];
    T reg42=reg3*reg40; reg28=reg39+reg28; reg27=reg33+reg27; reg33=reg12*pos_nodes[4][0]; reg26=reg35+reg26;
    reg35=reg7*pos_nodes[4][1]; reg5=reg34-reg5; reg34=pos_nodes[4][1]*reg29; reg3=reg3*reg32; reg39=reg13*reg24;
    reg38=reg27-reg38; reg27=pos_nodes[5][1]*reg3; reg34=reg5-reg34; reg5=reg30*pos_nodes[5][1]; T reg43=reg42*pos_nodes[5][0];
    reg41=reg20+reg41; reg36=reg37-reg36; reg20=reg30*pos_nodes[5][0]; reg8=reg13*reg8; reg13=pos_nodes[5][0]*reg3;
    reg33=reg26-reg33; reg35=reg28+reg35; reg26=reg42*pos_nodes[5][1]; reg27=reg38-reg27; reg28=reg12*pos_nodes[6][1];
    reg40=reg2*reg40; reg26=reg35+reg26; reg35=reg8*pos_nodes[6][1]; reg37=pos_nodes[6][0]*reg39; reg13=reg33-reg13;
    reg33=reg12*pos_nodes[6][0]; reg20=reg36+reg20; reg43=reg41+reg43; reg36=reg8*pos_nodes[6][0]; reg2=reg2*reg32;
    reg38=pos_nodes[6][1]*reg39; reg5=reg34+reg5; reg34=reg30*pos_nodes[7][1]; reg38=reg5-reg38; reg33=reg13+reg33;
    reg5=pos_nodes[7][0]*reg2; reg37=reg20-reg37; reg13=reg30*pos_nodes[7][0]; reg20=pos_nodes[7][1]*reg2; reg28=reg27+reg28;
    reg36=reg43+reg36; reg27=reg40*pos_nodes[7][0]; reg41=reg40*pos_nodes[7][1]; reg35=reg26+reg35; reg13=reg37-reg13;
    reg41=reg35+reg41; reg5=reg33-reg5; reg20=reg28-reg20; reg27=reg36+reg27; reg34=reg38-reg34;
    reg27=pos[0]-reg27; reg41=pos[1]-reg41; reg26=var_inter[0]*reg13; reg28=reg5*reg34; reg33=var_inter[0]*reg34;
    reg35=reg13*reg20; reg28=reg35-reg28; reg33=reg41+reg33; reg36=var_inter[1]*reg20; reg26=reg27+reg26;
    reg27=var_inter[1]*reg5; reg26=reg27+reg26; reg33=reg36+reg33; reg27=reg20/reg28; reg36=reg34/reg28;
    reg37=reg5/reg28; reg28=reg13/reg28; reg27=reg26*reg27; reg37=reg33*reg37; reg36=reg26*reg36;
    reg28=reg33*reg28; var_inter[0]+=reg27-reg37; var_inter[1]+=reg28-reg36;
=======
    T reg3=1+reg0; T reg4=0.25*reg3; T reg5=reg0-reg1; T reg6=reg1+reg0; T reg7=1-reg1;
    T reg8=0.25*reg2; T reg9=0.5*reg3; T reg10=0.5*reg2; T reg11=0.5*reg7; reg5=reg5-1;
    T reg12=1+reg1; T reg13=reg7*reg4; T reg14=1+reg6; T reg15=reg8*reg7; T reg16=reg14*reg11;
    T reg17=2*reg15; T reg18=reg11*reg5; T reg19=2*reg13; T reg20=0.5*reg12; T reg21=reg14*reg10;
    T reg22=reg5*reg9; T reg23=reg1-reg0; reg6=reg6-1; reg4=reg12*reg4; T reg24=pow(reg0,2);
    reg22=reg19+reg22; reg23=reg23-1; T reg25=reg20*reg6; reg8=reg8*reg12; T reg26=2*reg4;
    reg5=reg13*reg5; reg14=reg15*reg14; reg16=reg17-reg16; reg18=reg19+reg18; reg21=reg17-reg21;
    reg13=reg6*reg9; reg15=pos_nodes[1][0]*reg22; reg17=pos_nodes[0][0]*reg21; reg19=pow(reg1,2); reg24=1-reg24;
    T reg27=pos_nodes[1][0]*reg5; T reg28=pos_nodes[0][0]*reg14; T reg29=pos_nodes[1][1]*reg18; T reg30=pos_nodes[0][1]*reg16; reg6=reg4*reg6;
    reg4=pos_nodes[1][1]*reg22; T reg31=pos_nodes[0][1]*reg21; T reg32=pos_nodes[1][1]*reg5; T reg33=pos_nodes[0][1]*reg14; T reg34=reg23*reg10;
    reg13=reg26+reg13; T reg35=reg20*reg23; T reg36=2*reg8; reg25=reg26+reg25; reg26=pos_nodes[1][0]*reg18;
    T reg37=pos_nodes[0][0]*reg16; reg19=1-reg19; T reg38=pos_nodes[2][1]*reg25; T reg39=2*reg0; reg35=reg36+reg35;
    T reg40=pos_nodes[2][1]*reg6; reg33=reg32-reg33; reg34=reg36+reg34; reg32=pos_nodes[2][0]*reg13; reg30=reg29-reg30;
    reg17=reg15+reg17; reg31=reg4+reg31; reg28=reg27-reg28; reg4=pos_nodes[2][0]*reg6; reg15=pos_nodes[2][1]*reg13;
    reg27=0.5*reg24; reg23=reg8*reg23; reg37=reg26-reg37; reg8=pos_nodes[2][0]*reg25; reg26=pos_nodes[3][0]*reg23;
    reg4=reg28+reg4; reg28=pos_nodes[3][1]*reg34; reg31=reg15-reg31; reg15=pos_nodes[3][0]*reg34; reg17=reg32-reg17;
    reg29=pos_nodes[3][1]*reg35; reg32=pos_nodes[3][0]*reg35; reg8=reg37+reg8; reg40=reg33+reg40; reg33=pos_nodes[3][1]*reg23;
    reg36=2*reg1; reg37=reg7*reg39; reg38=reg30+reg38; reg30=0.5*reg19; reg7=reg7*reg27;
    T reg41=pos_nodes[4][1]*reg24; reg28=reg31+reg28; reg31=pos_nodes[4][0]*reg7; reg26=reg4+reg26; reg4=reg3*reg30;
    T reg42=pos_nodes[4][1]*reg7; reg33=reg40+reg33; reg40=pos_nodes[4][1]*reg37; reg29=reg38-reg29; reg38=pos_nodes[4][0]*reg24;
    reg15=reg17+reg15; reg3=reg3*reg36; reg17=pos_nodes[4][0]*reg37; reg32=reg8-reg32; reg40=reg29-reg40;
    reg8=pos_nodes[5][1]*reg19; reg29=pos_nodes[5][1]*reg4; reg42=reg33+reg42; reg33=pos_nodes[5][0]*reg19; reg17=reg32-reg17;
    reg32=reg12*reg39; reg27=reg12*reg27; reg38=reg15-reg38; reg12=pos_nodes[5][0]*reg3; reg15=pos_nodes[5][1]*reg3;
    reg41=reg28-reg41; reg31=reg26+reg31; reg26=pos_nodes[5][0]*reg4; reg28=pos_nodes[6][1]*reg24; reg15=reg41-reg15;
    reg29=reg42+reg29; reg41=pos_nodes[6][1]*reg27; reg30=reg2*reg30; reg42=pos_nodes[6][1]*reg32; reg40=reg8+reg40;
    reg2=reg2*reg36; reg12=reg38-reg12; reg8=pos_nodes[6][0]*reg27; reg26=reg31+reg26; reg33=reg17+reg33;
    reg17=pos_nodes[6][0]*reg32; reg31=pos_nodes[6][0]*reg24; reg38=pos_nodes[7][0]*reg19; reg17=reg33-reg17; reg33=pos_nodes[7][1]*reg2;
    reg28=reg15+reg28; reg31=reg12+reg31; reg12=pos_nodes[7][0]*reg2; reg8=reg26+reg8; reg15=pos_nodes[7][0]*reg30;
    reg41=reg29+reg41; reg26=pos_nodes[7][1]*reg30; reg29=pos_nodes[7][1]*reg19; reg42=reg40-reg42; reg26=reg41+reg26;
    reg38=reg17-reg38; reg33=reg28-reg33; reg12=reg31-reg12; reg15=reg8+reg15; reg29=reg42-reg29;
    reg8=reg12*reg29; reg17=reg38*reg33; reg28=var_inter[0]*reg29; reg15=pos[0]-reg15; reg31=var_inter[0]*reg38;
    reg26=pos[1]-reg26; reg8=reg17-reg8; reg28=reg26+reg28; reg26=var_inter[1]*reg33; reg31=reg15+reg31;
    reg15=var_inter[1]*reg12; reg31=reg15+reg31; reg28=reg26+reg28; reg15=reg33/reg8; reg26=reg29/reg8;
    reg40=reg12/reg8; reg8=reg38/reg8; reg15=reg31*reg15; reg40=reg28*reg40; reg26=reg31*reg26;
    reg8=reg28*reg8; var_inter[0]+=reg15-reg40; var_inter[1]+=reg8-reg26;
>>>>>>> 512dc2050926bfccc64f86a01cb2ce23c8050af9:include/mesh/element_Quad_8.h

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
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
<<<<<<< HEAD:include/mesh/element_Quad_8.h
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; reg0=reg0-1; reg1=reg1-1; T reg2=1-reg0;
    T reg3=1+reg0; T reg4=reg0+reg1; T reg5=0.25*reg2; T reg6=0.25*reg3; T reg7=1-reg1;
    T reg8=reg0-reg1; T reg9=reg5*reg7; T reg10=1+reg4; T reg11=1+reg1; T reg12=reg7*reg6;
    reg8=reg8-1; reg10=reg9*reg10; reg8=reg12*reg8; reg6=reg11*reg6; reg9=pow(reg0,2);
    reg4=reg4-1; reg0=reg1-reg0; reg8=val[1]*reg8; reg4=reg6*reg4; reg0=reg0-1;
    reg5=reg5*reg11; reg10=val[0]*reg10; reg9=1-reg9; reg1=pow(reg1,2); reg0=reg5*reg0;
    reg9=0.5*reg9; reg1=1-reg1; reg4=val[2]*reg4; reg10=reg8-reg10; reg1=0.5*reg1;
    reg7=reg7*reg9; reg0=val[3]*reg0; reg4=reg10+reg4; reg7=val[4]*reg7; reg3=reg3*reg1;
    reg0=reg4+reg0; reg9=reg11*reg9; reg3=val[5]*reg3; reg7=reg0+reg7; reg3=reg7+reg3;
    reg9=val[6]*reg9; reg1=reg2*reg1; reg9=reg3+reg9; reg1=val[7]*reg1; res=reg9+reg1;
=======
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; reg0=reg0-1; T reg2=1+reg0; T reg3=1-reg0;
    reg1=reg1-1; T reg4=reg0-reg1; T reg5=0.25*reg3; T reg6=1-reg1; T reg7=reg0+reg1;
    T reg8=0.25*reg2; T reg9=reg6*reg8; reg4=reg4-1; T reg10=reg5*reg6; T reg11=1+reg7;
    T reg12=1+reg1; reg4=reg9*reg4; reg8=reg12*reg8; reg7=reg7-1; reg9=reg1-reg0;
    reg0=pow(reg0,2); reg11=reg10*reg11; reg0=1-reg0; reg9=reg9-1; reg5=reg5*reg12;
    reg7=reg8*reg7; reg1=pow(reg1,2); reg4=val[1]*reg4; reg11=val[0]*reg11; reg11=reg4-reg11;
    reg7=val[2]*reg7; reg0=0.5*reg0; reg1=1-reg1; reg9=reg5*reg9; reg6=reg6*reg0;
    reg1=0.5*reg1; reg9=val[3]*reg9; reg7=reg11+reg7; reg9=reg7+reg9; reg6=val[4]*reg6;
    reg2=reg2*reg1; reg2=val[5]*reg2; reg0=reg12*reg0; reg6=reg9+reg6; reg2=reg6+reg2;
    reg0=val[6]*reg0; reg1=reg3*reg1; reg0=reg2+reg0; reg1=val[7]*reg1; res=reg0+reg1;
>>>>>>> 512dc2050926bfccc64f86a01cb2ce23c8050af9:include/mesh/element_Quad_8.h

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
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

}
#endif // LMT_QUAD_8
