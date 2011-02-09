#ifndef LMT_WEDGE
#define LMT_WEDGE
#include "node.h"
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Wedge &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 5, 10, 35, 68, 141, 226, 311, 396, 481, }; // fonction de lordre du poly
    static const double values[] = {
        0.5,0.333333333333,0.333333333333,0.5,
        0.0,
        0.5,0.333333333333,0.333333333333,0.5,
        0.0,
        0.0833333333333,0.5,0.0,0.211324865405,
        0.0833333333333,0.5,0.5,0.211324865405,
        0.0833333333333,0.0,0.5,0.211324865405,
        0.0833333333333,0.5,0.0,0.788675134595,
        0.0833333333333,0.5,0.5,0.788675134595,
        0.0833333333333,0.0,0.5,0.788675134595,
        0.0,
        -0.140625,0.333333333333,0.333333333333,0.211324865405,
        0.130208333333,0.2,0.2,0.211324865405,
        0.130208333333,0.2,0.6,0.211324865405,
        0.130208333333,0.6,0.2,0.211324865405,
        -0.140625,0.333333333333,0.333333333333,0.788675134595,
        0.130208333333,0.2,0.2,0.788675134595,
        0.130208333333,0.2,0.6,0.788675134595,
        0.130208333333,0.6,0.2,0.788675134595,
        0.0,
        0.04964035326178,0.44594849091596499999,0.44594849091596499999,0.5,
        0.04964035326178,0.10810301816807000002,0.44594849091596499999,0.5,
        0.04964035326178,0.44594849091596499999,0.10810301816807000002,0.5,
        0.024433720812293777778,0.091576213509771,0.091576213509771,0.5,
        0.024433720812293777778,0.81684757298045800001,0.091576213509771,0.5,
        0.024433720812293777778,0.091576213509771,0.81684757298045800001,0.5,
        0.031025220788612500002,0.44594849091596499999,0.44594849091596499999,0.112701665379,
        0.031025220788612500002,0.10810301816807000002,0.44594849091596499999,0.112701665379,
        0.031025220788612500002,0.44594849091596499999,0.10810301816807000002,0.112701665379,
        0.015271075507683611111,0.091576213509771,0.091576213509771,0.112701665379,
        0.015271075507683611111,0.81684757298045800001,0.091576213509771,0.112701665379,
        0.015271075507683611111,0.091576213509771,0.81684757298045800001,0.112701665379,
        0.031025220788612500002,0.44594849091596499999,0.44594849091596499999,0.887298334621,
        0.031025220788612500002,0.10810301816807000002,0.44594849091596499999,0.887298334621,
        0.031025220788612500002,0.44594849091596499999,0.10810301816807000002,0.887298334621,
        0.015271075507683611111,0.091576213509771,0.091576213509771,0.887298334621,
        0.015271075507683611111,0.81684757298045800001,0.091576213509771,0.887298334621,
        0.015271075507683611111,0.091576213509771,0.81684757298045800001,0.887298334621,
        0.0,
        0.05,0.333333333333,0.333333333333,0.5,
        0.0294209228419,0.470142064105,0.470142064105,0.5,
        0.0294209228419,0.0597158717898,0.470142064105,0.5,
        0.0294209228419,0.470142064105,0.0597158717898,0.5,
        0.0279864845655,0.101286507323,0.101286507323,0.5,
        0.0279864845655,0.797426985353,0.101286507323,0.5,
        0.0279864845655,0.101286507323,0.797426985353,0.5,
        0.03125,0.333333333333,0.333333333333,0.112701665379,
        0.0183880767762,0.470142064105,0.470142064105,0.112701665379,
        0.0183880767762,0.0597158717898,0.470142064105,0.112701665379,
        0.0183880767762,0.470142064105,0.0597158717898,0.112701665379,
        0.0174915528534,0.101286507323,0.101286507323,0.112701665379,
        0.0174915528534,0.797426985353,0.101286507323,0.112701665379,
        0.0174915528534,0.101286507323,0.797426985353,0.112701665379,
        0.03125,0.333333333333,0.333333333333,0.887298334621,
        0.0183880767762,0.470142064105,0.470142064105,0.887298334621,
        0.0183880767762,0.0597158717898,0.470142064105,0.887298334621,
        0.0183880767762,0.470142064105,0.0597158717898,0.887298334621,
        0.0174915528534,0.101286507323,0.101286507323,0.887298334621,
        0.0174915528534,0.797426985353,0.101286507323,0.887298334621,
        0.0174915528534,0.101286507323,0.797426985353,0.887298334621,
        0.0,
        0.05,0.333333333333,0.333333333333,0.5,
        0.0294209228419,0.470142064105,0.470142064105,0.5,
        0.0294209228419,0.0597158717898,0.470142064105,0.5,
        0.0294209228419,0.470142064105,0.0597158717898,0.5,
        0.0279864845655,0.101286507323,0.101286507323,0.5,
        0.0279864845655,0.797426985353,0.101286507323,0.5,
        0.0279864845655,0.101286507323,0.797426985353,0.5,
        0.03125,0.333333333333,0.333333333333,0.112701665379,
        0.0183880767762,0.470142064105,0.470142064105,0.112701665379,
        0.0183880767762,0.0597158717898,0.470142064105,0.112701665379,
        0.0183880767762,0.470142064105,0.0597158717898,0.112701665379,
        0.0174915528534,0.101286507323,0.101286507323,0.112701665379,
        0.0174915528534,0.797426985353,0.101286507323,0.112701665379,
        0.0174915528534,0.101286507323,0.797426985353,0.112701665379,
        0.03125,0.333333333333,0.333333333333,0.887298334621,
        0.0183880767762,0.470142064105,0.470142064105,0.887298334621,
        0.0183880767762,0.0597158717898,0.470142064105,0.887298334621,
        0.0183880767762,0.470142064105,0.0597158717898,0.887298334621,
        0.0174915528534,0.101286507323,0.101286507323,0.887298334621,
        0.0174915528534,0.797426985353,0.101286507323,0.887298334621,
        0.0174915528534,0.101286507323,0.797426985353,0.887298334621,
        0.0,
        0.05,0.333333333333,0.333333333333,0.5,
        0.0294209228419,0.470142064105,0.470142064105,0.5,
        0.0294209228419,0.0597158717898,0.470142064105,0.5,
        0.0294209228419,0.470142064105,0.0597158717898,0.5,
        0.0279864845655,0.101286507323,0.101286507323,0.5,
        0.0279864845655,0.797426985353,0.101286507323,0.5,
        0.0279864845655,0.101286507323,0.797426985353,0.5,
        0.03125,0.333333333333,0.333333333333,0.112701665379,
        0.0183880767762,0.470142064105,0.470142064105,0.112701665379,
        0.0183880767762,0.0597158717898,0.470142064105,0.112701665379,
        0.0183880767762,0.470142064105,0.0597158717898,0.112701665379,
        0.0174915528534,0.101286507323,0.101286507323,0.112701665379,
        0.0174915528534,0.797426985353,0.101286507323,0.112701665379,
        0.0174915528534,0.101286507323,0.797426985353,0.112701665379,
        0.03125,0.333333333333,0.333333333333,0.887298334621,
        0.0183880767762,0.470142064105,0.470142064105,0.887298334621,
        0.0183880767762,0.0597158717898,0.470142064105,0.887298334621,
        0.0183880767762,0.470142064105,0.0597158717898,0.887298334621,
        0.0174915528534,0.101286507323,0.101286507323,0.887298334621,
        0.0174915528534,0.797426985353,0.101286507323,0.887298334621,
        0.0174915528534,0.101286507323,0.797426985353,0.887298334621,
        0.0,
        0.05,0.333333333333,0.333333333333,0.5,
        0.0294209228419,0.470142064105,0.470142064105,0.5,
        0.0294209228419,0.0597158717898,0.470142064105,0.5,
        0.0294209228419,0.470142064105,0.0597158717898,0.5,
        0.0279864845655,0.101286507323,0.101286507323,0.5,
        0.0279864845655,0.797426985353,0.101286507323,0.5,
        0.0279864845655,0.101286507323,0.797426985353,0.5,
        0.03125,0.333333333333,0.333333333333,0.112701665379,
        0.0183880767762,0.470142064105,0.470142064105,0.112701665379,
        0.0183880767762,0.0597158717898,0.470142064105,0.112701665379,
        0.0183880767762,0.470142064105,0.0597158717898,0.112701665379,
        0.0174915528534,0.101286507323,0.101286507323,0.112701665379,
        0.0174915528534,0.797426985353,0.101286507323,0.112701665379,
        0.0174915528534,0.101286507323,0.797426985353,0.112701665379,
        0.03125,0.333333333333,0.333333333333,0.887298334621,
        0.0183880767762,0.470142064105,0.470142064105,0.887298334621,
        0.0183880767762,0.0597158717898,0.470142064105,0.887298334621,
        0.0183880767762,0.470142064105,0.0597158717898,0.887298334621,
        0.0174915528534,0.101286507323,0.101286507323,0.887298334621,
        0.0174915528534,0.797426985353,0.101286507323,0.887298334621,
        0.0174915528534,0.101286507323,0.797426985353,0.887298334621,
        0.0,
        0.05,0.333333333333,0.333333333333,0.5,
        0.0294209228419,0.470142064105,0.470142064105,0.5,
        0.0294209228419,0.0597158717898,0.470142064105,0.5,
        0.0294209228419,0.470142064105,0.0597158717898,0.5,
        0.0279864845655,0.101286507323,0.101286507323,0.5,
        0.0279864845655,0.797426985353,0.101286507323,0.5,
        0.0279864845655,0.101286507323,0.797426985353,0.5,
        0.03125,0.333333333333,0.333333333333,0.112701665379,
        0.0183880767762,0.470142064105,0.470142064105,0.112701665379,
        0.0183880767762,0.0597158717898,0.470142064105,0.112701665379,
        0.0183880767762,0.470142064105,0.0597158717898,0.112701665379,
        0.0174915528534,0.101286507323,0.101286507323,0.112701665379,
        0.0174915528534,0.797426985353,0.101286507323,0.112701665379,
        0.0174915528534,0.101286507323,0.797426985353,0.112701665379,
        0.03125,0.333333333333,0.333333333333,0.887298334621,
        0.0183880767762,0.470142064105,0.470142064105,0.887298334621,
        0.0183880767762,0.0597158717898,0.470142064105,0.887298334621,
        0.0183880767762,0.470142064105,0.0597158717898,0.887298334621,
        0.0174915528534,0.101286507323,0.101286507323,0.887298334621,
        0.0174915528534,0.797426985353,0.101286507323,0.887298334621,
        0.0174915528534,0.101286507323,0.797426985353,0.887298334621,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Wedge &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=0.5*nodes[0]->pos[1]; T reg1=0.5*nodes[2]->pos[1]; T reg2=0.5*nodes[1]->pos[2]; T reg3=0.5*nodes[2]->pos[2]; T reg4=0.5*nodes[0]->pos[2];
    T reg5=0.5*nodes[1]->pos[1]; T reg6=0.5*nodes[4]->pos[1]; T reg7=reg1+reg5; T reg8=0.5*nodes[3]->pos[2]; T reg9=reg3-reg4;
    reg5=reg5-reg0; T reg10=0.5*nodes[4]->pos[2]; reg3=reg2+reg3; reg4=reg2-reg4; reg2=0.5*nodes[3]->pos[1];
    reg0=reg1-reg0; reg1=reg6-reg7; T reg11=0.5*nodes[5]->pos[1]; reg4=reg4-reg8; reg8=reg9-reg8;
    reg9=0.5*nodes[1]->pos[0]; T reg12=0.5*nodes[0]->pos[0]; T reg13=0.5*nodes[2]->pos[0]; T reg14=0.5*nodes[5]->pos[2]; T reg15=reg10-reg3;
    reg5=reg5-reg2; reg2=reg0-reg2; reg0=reg13-reg12; reg5=reg6+reg5; reg4=reg10+reg4;
    reg1=reg11+reg1; reg11=reg2+reg11; reg8=reg14+reg8; reg12=reg9-reg12; reg14=reg15+reg14;
    reg2=0.5*nodes[3]->pos[0]; reg6=reg1*reg4; reg10=reg14*reg5; reg13=reg9+reg13; reg9=0.5*nodes[5]->pos[0];
    reg0=reg0-reg2; reg15=0.5*nodes[4]->pos[0]; reg1=reg8*reg1; reg14=reg11*reg14; reg2=reg12-reg2;
    reg2=reg2+reg15; reg4=reg11*reg4; reg5=reg8*reg5; reg15=reg15-reg13; reg6=reg10-reg6;
    reg1=reg14-reg1; reg0=reg0+reg9; reg6=reg0*reg6; reg15=reg9+reg15; reg4=reg5-reg4;
    reg1=reg2*reg1; reg6=reg1-reg6; reg4=reg15*reg4; T det_jac=reg6+reg4;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1],nodes[3],nodes[5],nodes[4]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[1][0]*var_inter[0]; T reg2=reg0*pos_nodes[0][0]; T reg3=pos_nodes[1][1]*var_inter[0];
    T reg4=reg0*pos_nodes[0][1]; T reg5=pos_nodes[1][2]*var_inter[0]; T reg6=pos_nodes[0][2]*reg0; T reg7=pos_nodes[2][0]*var_inter[1]; reg3=reg4+reg3;
    reg1=reg2+reg1; reg2=pos_nodes[2][1]*var_inter[1]; reg5=reg6+reg5; reg4=pos_nodes[2][2]*var_inter[1]; reg6=1-var_inter[2];
    T reg8=pos_nodes[2][1]*reg6; T reg9=pos_nodes[0][2]*reg6; T reg10=pos_nodes[3][0]*reg0; T reg11=pos_nodes[3][1]*reg0; T reg12=pos_nodes[2][2]*reg6;
    T reg13=pos_nodes[2][0]*reg6; reg3=reg2+reg3; reg1=reg7+reg1; reg2=reg6*pos_nodes[0][0]; reg7=pos_nodes[3][2]*reg0;
    reg5=reg4+reg5; reg4=reg6*pos_nodes[0][1]; T reg14=pos_nodes[4][0]*var_inter[0]; reg1=reg10-reg1; reg5=reg7-reg5;
    reg7=pos_nodes[4][2]*var_inter[0]; reg8=reg8-reg4; reg10=var_inter[2]*pos_nodes[3][1]; T reg15=var_inter[2]*pos_nodes[3][2]; reg12=reg12-reg9;
    T reg16=var_inter[2]*pos_nodes[3][0]; T reg17=pos_nodes[4][1]*var_inter[0]; reg3=reg11-reg3; reg13=reg13-reg2; reg11=pos_nodes[5][1]*var_inter[1];
    reg12=reg12-reg15; T reg18=var_inter[2]*pos_nodes[5][1]; reg8=reg8-reg10; reg17=reg3+reg17; reg3=var_inter[2]*pos_nodes[5][2];
    T reg19=pos_nodes[5][2]*var_inter[1]; T reg20=pos_nodes[1][1]*reg6; reg7=reg5+reg7; reg5=pos_nodes[1][0]*reg6; T reg21=var_inter[2]*pos_nodes[5][0];
    T reg22=pos_nodes[5][0]*var_inter[1]; T reg23=reg0*reg6; T reg24=reg6*var_inter[0]; reg13=reg13-reg16; reg14=reg1+reg14;
    reg12=reg3+reg12; reg1=pos_nodes[1][1]*reg24; reg3=pos_nodes[0][1]*reg23; reg11=reg17+reg11; reg17=reg6*var_inter[1];
    reg2=reg5-reg2; reg13=reg21+reg13; reg14=reg22+reg14; reg5=pos_nodes[1][2]*reg6; reg7=reg19+reg7;
    reg4=reg20-reg4; reg18=reg8+reg18; reg8=pos_nodes[0][0]*reg23; reg19=pos_nodes[1][0]*reg24; reg20=reg13*reg7;
    reg21=reg14*reg12; reg9=reg5-reg9; reg10=reg4-reg10; reg4=reg11*reg12; reg5=var_inter[2]*reg0;
    reg22=reg18*reg7; T reg25=var_inter[2]*pos_nodes[4][1]; T reg26=pos_nodes[0][2]*reg23; reg1=reg3+reg1; reg3=pos_nodes[1][2]*reg24;
    reg19=reg8+reg19; reg16=reg2-reg16; reg2=var_inter[2]*pos_nodes[4][0]; reg8=pos_nodes[2][0]*reg17; T reg27=pos_nodes[2][1]*reg17;
    reg4=reg22-reg4; T reg28=pos_nodes[2][2]*reg17; reg3=reg26+reg3; reg26=reg13*reg11; reg21=reg20-reg21;
    T reg29=reg14*reg18; reg2=reg16+reg2; reg19=reg8+reg19; reg8=pos_nodes[3][0]*reg5; reg25=reg10+reg25;
    reg1=reg27+reg1; reg10=pos_nodes[3][1]*reg5; reg15=reg9-reg15; reg9=var_inter[2]*pos_nodes[4][2]; reg16=var_inter[2]*var_inter[0];
    reg29=reg26-reg29; reg27=pos_nodes[4][1]*reg16; reg10=reg1+reg10; reg1=reg2*reg4; T reg30=var_inter[2]*var_inter[1];
    T reg31=reg25*reg21; T reg32=pos_nodes[3][2]*reg5; T reg33=pos_nodes[4][0]*reg16; reg8=reg19+reg8; reg9=reg15+reg9;
    reg3=reg28+reg3; reg15=pos_nodes[5][0]*reg30; reg19=reg14*reg9; reg28=reg2*reg7; reg1=reg31-reg1;
    reg31=reg9*reg29; T reg34=reg18*reg9; T reg35=reg25*reg7; T reg36=reg11*reg9; T reg37=reg25*reg12;
    T reg38=reg2*reg12; T reg39=reg13*reg9; T reg40=pos_nodes[4][2]*reg16; reg32=reg3+reg32; reg33=reg8+reg33;
    reg27=reg10+reg27; reg3=pos_nodes[5][1]*reg30; reg19=reg28-reg19; reg39=reg38-reg39; reg34=reg37-reg34;
    reg8=reg2*reg11; reg36=reg35-reg36; reg10=reg14*reg25; T reg41=reg2*reg18; T reg42=reg13*reg25;
    T reg43=pos_nodes[5][2]*reg30; reg3=reg27+reg3; reg33=reg15+reg33; reg40=reg32+reg40; reg31=reg1-reg31;
    reg21=reg21/reg31; reg19=reg19/reg31; reg40=reg43+reg40; reg34=reg34/reg31; reg42=reg41-reg42;
    reg4=reg4/reg31; reg39=reg39/reg31; reg33=pos[0]-reg33; reg36=reg36/reg31; reg3=pos[1]-reg3;
    reg10=reg8-reg10; reg21=reg3*reg21; reg36=reg33*reg36; reg19=reg3*reg19; reg34=reg33*reg34;
    reg39=reg3*reg39; reg4=reg33*reg4; reg42=reg42/reg31; reg10=reg10/reg31; reg31=reg29/reg31;
    reg40=pos[2]-reg40; reg31=reg40*reg31; reg4=reg21-reg4; reg10=reg40*reg10; reg19=reg36-reg19;
    reg42=reg40*reg42; reg34=reg39-reg34; var_inter[0]=reg4-reg31; var_inter[1]=reg10+reg19; var_inter[2]=reg34-reg42;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[1][2]*var_inter[0]; T reg2=reg0*pos_nodes[0][2]; T reg3=pos_nodes[1][1]*var_inter[0];
    T reg4=pos_nodes[0][1]*reg0; T reg5=pos_nodes[1][0]*var_inter[0]; T reg6=reg0*pos_nodes[0][0]; reg6=reg5+reg6; reg5=var_inter[1]*pos_nodes[2][0];
    T reg7=var_inter[1]*pos_nodes[2][2]; reg2=reg1+reg2; reg4=reg3+reg4; reg1=var_inter[1]*pos_nodes[2][1]; reg3=1-var_inter[2];
    T reg8=reg0*pos_nodes[3][2]; T reg9=reg3*pos_nodes[0][1]; T reg10=reg3*pos_nodes[2][2]; reg7=reg2+reg7; reg2=reg0*pos_nodes[3][1];
    reg1=reg4+reg1; reg4=reg3*pos_nodes[0][2]; T reg11=reg3*pos_nodes[2][1]; reg5=reg6+reg5; reg6=reg3*pos_nodes[2][0];
    T reg12=reg3*pos_nodes[0][0]; T reg13=reg0*pos_nodes[3][0]; reg7=reg8-reg7; reg8=var_inter[0]*pos_nodes[4][2]; T reg14=var_inter[2]*pos_nodes[3][1];
    reg10=reg10-reg4; T reg15=var_inter[2]*pos_nodes[3][2]; reg11=reg11-reg9; T reg16=var_inter[0]*pos_nodes[4][0]; reg5=reg13-reg5;
    reg1=reg2-reg1; reg6=reg6-reg12; reg2=var_inter[0]*pos_nodes[4][1]; reg13=var_inter[2]*pos_nodes[3][0]; reg11=reg11-reg14;
    T reg17=var_inter[2]*pos_nodes[5][1]; T reg18=reg3*var_inter[0]; reg10=reg10-reg15; T reg19=var_inter[2]*pos_nodes[5][2]; reg2=reg1+reg2;
    reg1=var_inter[1]*pos_nodes[5][1]; T reg20=reg3*reg0; T reg21=var_inter[1]*pos_nodes[5][2]; reg8=reg7+reg8; reg6=reg6-reg13;
    reg7=reg3*pos_nodes[1][0]; T reg22=reg3*pos_nodes[1][1]; T reg23=var_inter[2]*pos_nodes[5][0]; T reg24=var_inter[1]*pos_nodes[5][0]; reg16=reg5+reg16;
    reg21=reg8+reg21; reg5=reg3*var_inter[1]; reg1=reg2+reg1; reg2=pos_nodes[1][1]*reg18; reg8=reg3*pos_nodes[1][2];
    reg17=reg11+reg17; reg23=reg6+reg23; reg24=reg16+reg24; reg6=pos_nodes[1][0]*reg18; reg9=reg22-reg9;
    reg11=reg20*pos_nodes[0][1]; reg16=reg20*pos_nodes[0][0]; reg19=reg10+reg19; reg12=reg7-reg12; reg4=reg8-reg4;
    reg7=reg24*reg19; reg8=reg23*reg21; reg10=reg1*reg19; reg22=pos_nodes[1][2]*reg18; T reg25=reg20*pos_nodes[0][2];
    T reg26=reg17*reg21; T reg27=reg5*pos_nodes[2][0]; reg14=reg9-reg14; reg9=var_inter[2]*pos_nodes[4][1]; T reg28=var_inter[2]*reg0;
    reg16=reg6+reg16; reg6=reg5*pos_nodes[2][1]; reg11=reg2+reg11; reg13=reg12-reg13; reg2=var_inter[2]*pos_nodes[4][0];
    reg12=reg28*pos_nodes[3][0]; reg27=reg16+reg27; reg2=reg13+reg2; reg25=reg22+reg25; reg13=reg5*pos_nodes[2][2];
    reg10=reg26-reg10; reg16=reg23*reg1; reg22=var_inter[2]*var_inter[0]; reg7=reg8-reg7; T reg29=reg24*reg17;
    T reg30=reg28*pos_nodes[3][1]; reg6=reg11+reg6; reg11=var_inter[2]*pos_nodes[4][2]; reg15=reg4-reg15; reg9=reg14+reg9;
    reg4=reg2*reg10; reg14=reg22*pos_nodes[4][1]; T reg31=var_inter[1]*var_inter[2]; reg30=reg6+reg30; reg6=reg9*reg7;
    T reg32=reg28*pos_nodes[3][2]; reg13=reg25+reg13; reg29=reg16-reg29; reg11=reg15+reg11; reg12=reg27+reg12;
    reg15=reg22*pos_nodes[4][0]; reg25=reg9*reg21; reg27=reg11*reg29; T reg33=reg1*reg11; T reg34=reg9*reg19;
    reg4=reg6-reg4; reg6=reg17*reg11; T reg35=reg24*reg11; T reg36=reg2*reg19; reg14=reg30+reg14;
    reg30=reg23*reg11; T reg37=reg31*pos_nodes[5][1]; T reg38=reg22*pos_nodes[4][2]; reg32=reg13+reg32; reg15=reg12+reg15;
    reg12=reg31*pos_nodes[5][0]; reg13=reg2*reg21; T reg39=reg23*reg9; T reg40=reg2*reg17; T reg41=reg24*reg9;
    T reg42=reg2*reg1; reg30=reg36-reg30; reg35=reg13-reg35; reg12=reg15+reg12; reg6=reg34-reg6;
    reg33=reg25-reg33; reg15=reg31*pos_nodes[5][2]; reg38=reg32+reg38; reg37=reg14+reg37; reg27=reg4-reg27;
    reg7=reg7/reg27; reg35=reg35/reg27; reg10=reg10/reg27; reg37=pos[1]-reg37; reg6=reg6/reg27;
    reg12=pos[0]-reg12; reg30=reg30/reg27; reg33=reg33/reg27; reg15=reg38+reg15; reg39=reg40-reg39;
    reg41=reg42-reg41; reg7=reg37*reg7; reg33=reg12*reg33; reg35=reg37*reg35; reg30=reg37*reg30;
    reg6=reg12*reg6; reg10=reg12*reg10; reg39=reg39/reg27; reg41=reg41/reg27; reg27=reg29/reg27;
    reg15=pos[2]-reg15; reg27=reg15*reg27; reg10=reg7-reg10; reg41=reg15*reg41; reg35=reg33-reg35;
    reg39=reg15*reg39; reg6=reg30-reg6; var_inter[0]+=reg10-reg27; var_inter[1]+=reg41+reg35; var_inter[2]+=reg6-reg39;

}
template<> struct ElemVarInterFromPosNonLinear<Wedge> { static const bool res = 3; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=1-var_inter[2]; reg0=reg0-var_inter[1]; T reg2=var_inter[0]*reg1; T reg3=reg0*reg1;
    reg3=val[0]*reg3; reg2=val[1]*reg2; T reg4=var_inter[1]*reg1; reg2=reg3+reg2; reg4=val[2]*reg4;
    reg0=var_inter[2]*reg0; reg3=var_inter[0]*var_inter[2]; reg0=val[3]*reg0; reg4=reg2+reg4; reg0=reg4+reg0;
    reg3=val[4]*reg3; reg2=var_inter[1]*var_inter[2]; reg3=reg0+reg3; reg2=val[5]*reg2; res=reg3+reg2;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[0]; T reg1=var_inter[2]-0.21132486540518707896; T reg2=2*var_inter[1]; reg1=reg1/0.57735026918962573106; T reg3=1-var_inter[2];
    T reg4=reg2+reg0; reg1=1-reg1; T reg5=reg3-0.21132486540518707896; reg4=reg4-1; T reg6=1-reg2;
    T reg7=1-reg0; T reg8=reg1*reg4; T reg9=reg1*reg6; reg5=reg5/0.57735026918962573106; reg9=val[0]*reg9;
    reg5=1-reg5; reg8=val[1]*reg8; reg1=reg1*reg7; T reg10=reg6*reg5; reg1=val[2]*reg1;
    reg8=reg9+reg8; reg1=reg8+reg1; reg10=val[3]*reg10; reg4=reg4*reg5; reg10=reg1+reg10;
    reg4=val[4]*reg4; reg5=reg7*reg5; reg4=reg10+reg4; reg5=val[5]*reg5; res=reg4+reg5;

}
#ifndef STRUCT_Gauss_2
#define STRUCT_Gauss_2
struct Gauss_2 {};
#endif // STRUCT_Gauss_2
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Gauss_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[0]; T reg1=var_inter[2]-0.21132486540518707896; T reg2=2*var_inter[1]; reg1=reg1/0.57735026918962573106; T reg3=1-var_inter[2];
    T reg4=reg2+reg0; reg1=1-reg1; T reg5=reg3-0.21132486540518707896; reg4=reg4-1; T reg6=1-reg2;
    T reg7=1-reg0; T reg8=reg1*reg4; T reg9=reg1*reg6; reg5=reg5/0.57735026918962573106; reg9=val[0]*reg9;
    reg5=1-reg5; reg8=val[1]*reg8; reg1=reg1*reg7; T reg10=reg6*reg5; reg1=val[2]*reg1;
    reg8=reg9+reg8; reg1=reg8+reg1; reg10=val[3]*reg10; reg4=reg4*reg5; reg10=reg1+reg10;
    reg4=val[4]*reg4; reg5=reg7*reg5; reg4=reg10+reg4; reg5=val[5]*reg5; res=reg4+reg5;

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; T reg2=reg0-1; T reg3=1-reg1; reg2=reg1+reg2;
    T reg4=1-reg0; T reg5=val[0]*reg3; reg2=val[1]*reg2; reg2=reg5+reg2; reg5=val[2]*reg4;
    res=reg2+reg5;

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Wedge &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=1-var_inter[2]; T reg2=reg0*reg1; res[0]=reg2;
    T reg3=var_inter[0]*reg1; res[1]=reg3; T reg4=var_inter[1]*reg1; res[2]=reg4; reg0=var_inter[2]*reg0;
    res[3]=reg0; T reg5=var_inter[0]*var_inter[2]; res[4]=reg5; T reg6=var_inter[1]*var_inter[2]; res[5]=reg6;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Wedge> {
    static const unsigned nb_permutations = 5;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
        if ( nb_perm == 0 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[5],e.nodes[4],e.nodes[0],e.nodes[2],e.nodes[1]};
            for(unsigned i=0;i<6;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 1 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[2],e.nodes[0],e.nodes[4],e.nodes[5],e.nodes[3]};
            for(unsigned i=0;i<6;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 2 ) {
            typename TE::TNode *tmp[] = {e.nodes[5],e.nodes[4],e.nodes[3],e.nodes[2],e.nodes[1],e.nodes[0]};
            for(unsigned i=0;i<6;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 3 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[0],e.nodes[1],e.nodes[5],e.nodes[3],e.nodes[4]};
            for(unsigned i=0;i<6;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 4 ) {
            typename TE::TNode *tmp[] = {e.nodes[4],e.nodes[3],e.nodes[5],e.nodes[1],e.nodes[0],e.nodes[2]};
            for(unsigned i=0;i<6;++i) e.nodes[i] = tmp[i];
            return;
        }
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
        if ( nb_perm == 0 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[5],e.nodes[4],e.nodes[0],e.nodes[2],e.nodes[1]};
            for(unsigned i=0;i<6;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 1 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[0],e.nodes[1],e.nodes[5],e.nodes[3],e.nodes[4]};
            for(unsigned i=0;i<6;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 2 ) {
            typename TE::TNode *tmp[] = {e.nodes[5],e.nodes[4],e.nodes[3],e.nodes[2],e.nodes[1],e.nodes[0]};
            for(unsigned i=0;i<6;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 3 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[2],e.nodes[0],e.nodes[4],e.nodes[5],e.nodes[3]};
            for(unsigned i=0;i<6;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 4 ) {
            typename TE::TNode *tmp[] = {e.nodes[4],e.nodes[3],e.nodes[5],e.nodes[1],e.nodes[0],e.nodes[2]};
            for(unsigned i=0;i<6;++i) e.nodes[i] = tmp[i];
            return;
        }
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Wedge,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=reg0*elem.pos(0)[1]; T reg2=var_inter[0]*elem.pos(1)[1]; T reg3=elem.pos(0)[2]*reg0;
    T reg4=var_inter[0]*elem.pos(1)[2]; T reg5=reg1+reg2; T reg6=var_inter[1]*elem.pos(2)[1]; T reg7=1-var_inter[2]; T reg8=var_inter[1]*elem.pos(2)[2];
    T reg9=reg4+reg3; T reg10=reg7*elem.pos(0)[1]; T reg11=reg7*elem.pos(2)[1]; T reg12=elem.pos(0)[2]*reg7; T reg13=elem.pos(1)[2]*reg7;
    T reg14=elem.pos(1)[1]*reg7; T reg15=reg6+reg5; T reg16=reg0*elem.pos(3)[1]; T reg17=reg8+reg9; T reg18=reg7*elem.pos(2)[2];
    T reg19=reg0*elem.pos(3)[2]; reg16=reg16-reg15; T reg20=var_inter[0]*elem.pos(4)[2]; T reg21=var_inter[2]*elem.pos(3)[1]; T reg22=var_inter[2]*elem.pos(3)[2];
    reg13=reg13-reg12; reg14=reg14-reg10; reg19=reg19-reg17; reg11=reg11-reg10; reg18=reg18-reg12;
    T reg23=var_inter[0]*elem.pos(1)[0]; T reg24=var_inter[0]*elem.pos(4)[1]; T reg25=reg0*elem.pos(0)[0]; T reg26=var_inter[1]*elem.pos(5)[2]; T reg27=reg25+reg23;
    T reg28=elem.pos(1)[0]*reg7; reg19=reg20+reg19; reg20=var_inter[2]*elem.pos(5)[1]; T reg29=var_inter[1]*elem.pos(5)[1]; T reg30=reg7*elem.pos(0)[0];
    reg11=reg11-reg21; T reg31=var_inter[2]*elem.pos(4)[1]; reg14=reg14-reg21; T reg32=elem.pos(2)[0]*reg7; T reg33=var_inter[2]*elem.pos(5)[2];
    reg13=reg13-reg22; reg18=reg18-reg22; T reg34=var_inter[2]*elem.pos(4)[2]; T reg35=var_inter[1]*elem.pos(2)[0]; reg16=reg24+reg16;
    reg24=reg35+reg27; reg29=reg16+reg29; reg32=reg32-reg30; reg34=reg13+reg34; reg13=var_inter[2]*elem.pos(3)[0];
    reg16=reg0*elem.pos(3)[0]; reg18=reg33+reg18; reg26=reg19+reg26; reg11=reg20+reg11; reg28=reg28-reg30;
    reg14=reg31+reg14; reg16=reg16-reg24; reg28=reg28-reg13; reg19=var_inter[2]*elem.pos(4)[0]; reg20=var_inter[2]*elem.pos(5)[0];
    reg31=reg34*reg29; reg32=reg32-reg13; reg33=reg11*reg26; T reg36=reg18*reg29; T reg37=reg14*reg26;
    T reg38=var_inter[0]*elem.pos(4)[0]; reg32=reg20+reg32; reg31=reg37-reg31; reg20=var_inter[1]*elem.pos(5)[0]; reg36=reg33-reg36;
    reg33=reg18*reg14; reg19=reg28+reg19; reg38=reg16+reg38; reg16=reg34*reg11; reg28=reg19*reg36;
    reg37=reg32*reg31; reg20=reg38+reg20; reg16=reg33-reg16; reg33=reg16*reg20; reg37=reg28-reg37;
    reg33=reg37+reg33; return reg33;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Wedge,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=elem.pos(0)[2]-elem.pos(1)[2]; T reg1=elem.pos(0)[1]-elem.pos(1)[1]; T reg2=elem.pos(0)[2]-elem.pos(2)[2]; T reg3=elem.pos(0)[1]-elem.pos(2)[1]; T reg4=elem.pos(1)[2]-elem.pos(0)[2];
    T reg5=elem.pos(1)[1]-elem.pos(0)[1]; T reg6=elem.pos(2)[2]-elem.pos(0)[2]; T reg7=elem.pos(2)[1]-elem.pos(0)[1]; reg2=reg2-elem.pos(3)[2]; reg1=reg1-elem.pos(3)[1];
    reg3=reg3-elem.pos(3)[1]; T reg8=elem.pos(3)[1]+reg5; T reg9=elem.pos(3)[1]+reg7; reg0=reg0-elem.pos(3)[2]; T reg10=elem.pos(3)[2]+reg4;
    T reg11=elem.pos(3)[2]+reg6; T reg12=elem.pos(5)[1]-reg9; T reg13=elem.pos(3)[2]-elem.pos(0)[2]; T reg14=elem.pos(4)[2]-reg10; reg0=elem.pos(4)[2]+reg0;
    reg1=elem.pos(4)[1]+reg1; T reg15=elem.pos(3)[1]-elem.pos(0)[1]; T reg16=elem.pos(0)[0]-elem.pos(2)[0]; reg2=elem.pos(5)[2]+reg2; reg3=elem.pos(5)[1]+reg3;
    T reg17=elem.pos(0)[0]-elem.pos(1)[0]; T reg18=elem.pos(5)[2]-reg11; T reg19=elem.pos(4)[1]-reg8; T reg20=reg7*reg14; T reg21=reg6*reg19;
    T reg22=reg0*reg15; T reg23=reg4*reg12; T reg24=reg5*reg18; T reg25=reg6*reg12; T reg26=reg7*reg13;
    T reg27=reg6*reg15; T reg28=reg5*reg13; T reg29=reg4*reg15; T reg30=reg7*reg18; T reg31=reg0*reg12;
    reg17=reg17-elem.pos(3)[0]; T reg32=reg1*reg18; reg16=reg16-elem.pos(3)[0]; T reg33=reg3*reg13; T reg34=reg0*reg19;
    T reg35=reg1*reg14; T reg36=reg2*reg15; T reg37=reg2*reg19; T reg38=reg3*reg14; T reg39=reg2*reg12;
    T reg40=reg3*reg18; T reg41=reg4*reg19; T reg42=reg5*reg14; T reg43=reg1*reg13; reg36=reg33-reg36;
    reg25=reg30-reg25; reg23=reg24-reg23; reg22=reg43-reg22; reg39=reg40-reg39; reg31=reg32-reg31;
    reg29=reg28-reg29; reg24=elem.pos(1)[0]-elem.pos(0)[0]; reg28=elem.pos(2)[0]-elem.pos(0)[0]; reg17=elem.pos(4)[0]+reg17; reg34=reg35-reg34;
    reg16=elem.pos(5)[0]+reg16; reg37=reg38-reg37; reg30=reg5*reg2; reg32=reg6*reg1; reg41=reg42-reg41;
    reg21=reg20-reg21; reg20=reg4*reg3; reg33=reg7*reg0; reg35=reg2*reg1; reg27=reg26-reg27;
    reg26=reg3*reg0; reg38=reg16*reg31; reg40=reg17*reg39; reg42=reg16*reg23; reg31=reg28*reg31;
    reg26=2*reg26; reg35=2*reg35; reg43=reg17*reg25; reg39=reg24*reg39; reg33=reg20+reg33;
    reg20=elem.pos(3)[0]+reg28; reg32=reg30+reg32; reg30=reg17*reg27; T reg44=reg24*reg36; T reg45=elem.pos(3)[0]+reg24;
    T reg46=reg24*reg37; T reg47=reg17*reg21; T reg48=reg16*reg22; T reg49=reg28*reg34; T reg50=reg16*reg41;
    reg37=reg17*reg37; reg22=reg28*reg22; reg34=reg16*reg34; reg36=reg17*reg36; T reg51=reg16*reg29;
    reg36=2*reg36; reg48=2*reg48; reg26=reg35-reg26; reg51=reg22+reg51; reg33=reg32-reg33;
    reg22=elem.pos(4)[0]-reg45; reg47=reg46+reg47; reg50=reg49+reg50; reg37=2*reg37; reg34=2*reg34;
    reg32=reg7*reg4; reg35=reg6*reg5; reg30=reg44+reg30; reg38=2*reg38; reg40=2*reg40;
    reg43=reg39+reg43; reg39=elem.pos(5)[0]-reg20; reg44=elem.pos(3)[0]-elem.pos(0)[0]; reg42=reg31+reg42; reg21=reg24*reg21;
    reg41=reg28*reg41; reg29=reg28*reg29; reg31=reg26*reg39; reg50=reg47-reg50; reg46=reg33*reg22;
    reg42=reg43-reg42; reg43=reg33*reg39; reg38=reg40-reg38; reg34=reg37-reg34; reg32=reg35-reg32;
    reg35=reg26*reg22; reg48=reg36-reg48; reg36=reg26*reg44; reg37=reg33*reg44; reg25=reg24*reg25;
    reg27=reg24*reg27; reg51=reg30-reg51; reg23=reg28*reg23; reg23=reg25-reg23; reg43=reg42+reg43;
    reg25=reg32*reg39; reg37=reg51+reg37; reg46=reg50+reg46; reg36=reg48+reg36; reg31=reg38+reg31;
    reg35=reg34+reg35; reg29=reg27-reg29; reg27=reg32*reg22; reg30=reg32*reg44; reg41=reg21-reg41;
    reg21=reg6*reg36; reg34=reg43*reg22; reg38=reg39*reg46; reg40=reg24*reg31; reg42=reg28*reg35;
    reg47=reg43*reg14; reg48=reg18*reg46; reg49=reg6*reg35; reg50=reg43*reg19; reg51=reg12*reg46;
    T reg52=reg4*reg31; T reg53=reg5*reg31; T reg54=reg7*reg35; T reg55=reg39*reg37; T reg56=elem.pos(0)[0]*reg31;
    T reg57=reg28*reg36; reg30=reg29+reg30; reg29=reg43*reg44; T reg58=reg13*reg43; T reg59=reg18*reg37;
    reg27=reg41+reg27; reg25=reg23+reg25; reg23=reg7*reg36; reg41=elem.pos(0)[1]*reg31; T reg60=reg12*reg37;
    T reg61=elem.pos(0)[2]*reg31; T reg62=reg15*reg43; T reg63=elem.pos(0)[2]*reg43; T reg64=reg6*reg37; reg48=reg47+reg48;
    reg47=reg13*reg25; T reg65=reg18*reg30; T reg66=reg18*reg27; T reg67=reg25*reg14; T reg68=reg6*reg46;
    T reg69=reg4*reg43; reg59=reg58+reg59; reg21=reg61+reg21; reg58=reg18*reg36; reg61=reg13*reg31;
    reg55=reg29+reg55; reg57=reg56+reg57; reg29=reg31*reg44; reg56=reg39*reg36; T reg70=reg39*reg30;
    T reg71=reg25*reg44; T reg72=reg28*reg37; T reg73=elem.pos(0)[0]*reg43; T reg74=reg24*reg43; T reg75=reg28*reg46;
    T reg76=reg25*reg22; T reg77=reg39*reg27; reg38=reg34+reg38; reg42=reg40+reg42; reg34=reg31*reg22;
    reg40=reg39*reg35; T reg78=reg18*reg35; T reg79=reg31*reg14; reg49=reg52+reg49; reg52=reg12*reg35;
    T reg80=reg31*reg19; T reg81=reg12*reg27; T reg82=reg25*reg19; T reg83=reg7*reg46; T reg84=reg5*reg43;
    T reg85=reg12*reg36; T reg86=reg15*reg31; reg23=reg41+reg23; reg60=reg62+reg60; reg41=reg12*reg30;
    reg62=reg15*reg25; T reg87=reg7*reg37; T reg88=elem.pos(0)[1]*reg43; reg54=reg53+reg54; reg51=reg50+reg51;
    reg56=reg29+reg56; reg64=reg63+reg64; reg29=reg24*reg35; reg50=reg22*reg46; reg65=reg47+reg65;
    reg47=reg5*reg35; reg53=reg19*reg46; reg63=elem.pos(0)[2]*reg35; T reg89=reg37*reg14; T reg90=reg13*reg46;
    reg57=reg55+reg57; T reg91=reg14*reg46; reg70=reg71+reg70; reg72=reg73+reg72; reg71=reg4*reg35;
    reg83=reg84+reg83; reg87=reg88+reg87; reg85=reg86+reg85; reg41=reg62+reg41; reg23=reg60+reg23;
    reg62=reg4*reg36; reg49=reg48+reg49; reg73=reg24*reg36; reg84=elem.pos(0)[0]*reg35; reg54=reg51+reg54;
    reg86=reg15*reg46; reg88=reg37*reg19; T reg92=elem.pos(0)[1]*reg35; T reg93=reg5*reg36; T reg94=reg37*reg22;
    T reg95=reg44*reg46; reg81=reg82+reg81; reg66=reg67+reg66; reg78=reg79+reg78; reg68=reg69+reg68;
    reg40=reg34+reg40; reg21=reg59+reg21; reg75=reg74+reg75; reg52=reg80+reg52; reg58=reg61+reg58;
    reg77=reg76+reg77; reg42=reg38+reg42; reg34=reg5*reg25; reg61=2*reg85; reg67=reg13*reg35;
    reg69=reg13*reg27; reg81=reg83+reg81; reg23=reg60+reg23; reg63=reg62+reg63; reg60=reg6*reg31;
    reg62=reg30*reg14; reg74=reg18*reg43; reg54=reg51+reg54; reg41=reg87+reg41; reg89=reg90+reg89;
    reg21=reg59+reg21; reg51=2*reg52; reg49=reg48+reg49; reg48=2*reg58; reg59=elem.pos(0)[1]*reg46;
    reg76=reg5*reg37; reg79=reg4*reg46; reg80=reg6*reg30; reg82=reg4*reg37; reg83=elem.pos(0)[2]*reg25;
    reg87=reg14*reg27; reg90=reg4*reg25; reg91=2*reg91; T reg96=reg6*reg27; T reg97=elem.pos(0)[2]*reg46;
    T reg98=reg36*reg14; reg71=2*reg71; T reg99=2*reg78; reg66=reg68+reg66; reg65=reg64+reg65;
    reg64=reg7*reg27; reg68=reg39*reg43; T reg100=reg24*reg37; T reg101=elem.pos(0)[0]*reg46; T reg102=reg28*reg31;
    reg50=2*reg50; T reg103=2*reg40; T reg104=reg28*reg27; reg29=2*reg29; T reg105=elem.pos(0)[0]*reg25;
    reg42=reg38+reg42; reg38=reg44*reg35; T reg106=reg28*reg30; T reg107=reg36*reg22; reg70=reg72+reg70;
    reg72=reg19*reg27; reg57=reg55+reg57; reg77=reg75+reg77; reg55=reg5*reg46; reg75=2*reg56;
    reg53=2*reg53; T reg108=reg7*reg30; T reg109=elem.pos(0)[1]*reg25; T reg110=reg15*reg27; T reg111=reg24*reg46;
    T reg112=reg30*reg19; reg73=reg84+reg73; reg94=reg95+reg94; reg84=reg7*reg31; reg88=reg86+reg88;
    reg86=reg12*reg43; reg93=reg92+reg93; reg47=2*reg47; reg92=reg30*reg22; reg95=reg44*reg27;
    T reg113=reg15*reg35; T reg114=reg36*reg19; T reg115=reg22*reg27; T reg116=reg24*reg25; reg104=reg116+reg104;
    reg62=reg69+reg62; reg77=reg77/2; reg107=reg38+reg107; reg82=reg97+reg82; reg42=0.5*reg42;
    reg103=reg40+reg103; reg99=reg78+reg99; reg100=reg101+reg100; reg92=reg95+reg92; reg49=0.5*reg49;
    reg73=reg94+reg73; reg64=reg34+reg64; reg68=2*reg68; reg61=reg85+reg61; reg34=reg39*reg25;
    reg38=reg28*reg43; reg40=reg15*reg37; reg69=elem.pos(0)[1]*reg36; reg23=0.5*reg23; reg78=reg7*reg43;
    reg85=reg12*reg25; reg86=2*reg86; reg84=2*reg84; reg41=reg41/2; reg108=reg109+reg108;
    reg111=2*reg111; reg63=reg89+reg63; reg115=2*reg115; reg98=reg67+reg98; reg29=reg50+reg29;
    reg67=reg22*reg35; reg75=reg56+reg75; reg57=0.5*reg57; reg79=2*reg79; reg87=2*reg87;
    reg70=reg70/2; reg106=reg105+reg106; reg71=reg91+reg71; reg56=reg14*reg35; reg95=elem.pos(0)[0]*reg36;
    reg97=reg44*reg37; reg48=reg58+reg48; reg102=2*reg102; reg21=0.5*reg21; reg51=reg52+reg51;
    reg65=reg65/2; reg80=reg83+reg80; reg60=2*reg60; reg74=2*reg74; reg52=reg18*reg25;
    reg58=reg6*reg43; reg83=elem.pos(0)[2]*reg36; reg101=reg13*reg37; reg105=reg19*reg35; reg47=reg53+reg47;
    reg72=2*reg72; reg55=2*reg55; reg114=reg113+reg114; reg93=reg88+reg93; reg112=reg110+reg112;
    reg76=reg59+reg76; reg81=reg81/2; reg54=0.5*reg54; reg66=reg66/2; reg96=reg90+reg96;
    reg34=2*reg34; reg102=reg68+reg102; reg59=reg39*reg31; reg48=0.16666666666666666667*reg48; reg90=elem.pos(0)[0]*reg37;
    reg109=reg44*reg30; reg95=reg97+reg95; reg44=reg44*reg36; reg70=reg106+reg70; reg57=reg57/3;
    reg75=0.16666666666666666667*reg75; reg106=4*reg67; reg67=2*reg67; reg110=4*reg105; reg29=reg50+reg29;
    reg105=2*reg105; reg50=4*reg56; reg56=2*reg56; reg54=reg54/3; reg115=reg111+reg115;
    reg58=2*reg58; reg52=2*reg52; reg83=reg101+reg83; reg99=0.16666666666666666667*reg99; reg41=reg108+reg41;
    reg108=elem.pos(0)[2]*reg27; reg111=reg4*reg30; reg60=reg74+reg60; reg23=reg23/3; reg113=reg15*reg36;
    reg69=reg40+reg69; reg116=reg18*reg31; T reg117=elem.pos(0)[2]*reg37; reg61=0.16666666666666666667*reg61; T reg118=reg12*reg31;
    reg84=reg86+reg84; T reg119=reg13*reg30; reg85=2*reg85; reg78=2*reg78; reg15=reg15*reg30;
    T reg120=elem.pos(0)[1]*reg37; reg38=2*reg38; reg77=reg104+reg77; reg104=2*reg107; reg42=reg42/3;
    reg73=reg94+reg73; reg103=0.16666666666666666667*reg103; reg94=elem.pos(0)[0]*reg27; T reg121=reg24*reg30; T reg122=2*reg98;
    T reg123=2*reg114; T reg124=reg5*reg30; reg92=reg100+reg92; reg63=reg89+reg63; reg65=reg80+reg65;
    reg80=elem.pos(0)[1]*reg27; reg93=reg88+reg93; reg51=0.16666666666666666667*reg51; reg49=reg49/3; reg112=reg76+reg112;
    reg62=reg82+reg62; reg81=reg64+reg81; reg21=reg21/3; reg66=reg96+reg66; reg87=reg79+reg87;
    reg72=reg55+reg72; reg55=reg24*reg27; reg13=reg13*reg36; reg71=reg91+reg71; reg64=reg5*reg27;
    reg47=reg53+reg47; reg53=reg4*reg27; reg84=reg86+reg84; reg49=reg66+reg49; reg66=2*reg118;
    reg118=4*reg118; reg93=0.5*reg93; reg76=reg6*reg25; reg29=0.5*reg29; reg119=reg117+reg119;
    reg69=reg40+reg69; reg92=reg92/2; reg40=2*reg113; reg55=2*reg55; reg72=reg72/2;
    reg54=reg81+reg54; reg112=reg112/2; reg47=0.5*reg47; reg115=reg115/2; reg79=2*reg44;
    reg95=reg97+reg95; reg109=reg90+reg109; reg42=reg77+reg42; reg73=0.5*reg73; reg48=reg48/4;
    reg77=4*reg59; reg59=2*reg59; reg57=reg70+reg57; reg102=reg68+reg102; reg110=reg105+reg110;
    reg34=reg38+reg34; reg103=reg103/4; reg104=reg107+reg104; reg38=reg28*reg25; reg75=reg75/4;
    reg121=reg94+reg121; reg15=reg120+reg15; reg68=reg7*reg25; reg123=reg114+reg123; reg106=reg67+reg106;
    reg85=reg78+reg85; reg64=2*reg64; reg21=reg65+reg21; reg62=reg62/2; reg51=reg51/4;
    reg63=0.5*reg63; reg124=reg80+reg124; reg122=reg98+reg122; reg53=2*reg53; reg111=reg108+reg111;
    reg87=reg87/2; reg65=2*reg13; reg71=0.5*reg71; reg50=reg56+reg50; reg83=reg101+reg83;
    reg56=4*reg116; reg61=reg61/4; reg116=2*reg116; reg60=reg74+reg60; reg23=reg41+reg23;
    reg52=reg58+reg52; reg99=reg99/4; reg68=2*reg68; reg104=0.16666666666666666667*reg104; reg15=reg15/2;
    reg87=reg53+reg87; reg65=reg13+reg65; reg13=elem.pos(0)[1]*reg30; reg40=reg113+reg40; reg72=reg64+reg72;
    reg71=reg71/3; reg115=reg55+reg115; reg47=reg47/3; reg41=elem.pos(0)[2]*reg30; reg38=2*reg38;
    reg83=0.5*reg83; reg21=reg48+reg21; reg50=0.16666666666666666667*reg50; reg29=reg29/3; reg34=reg34/2;
    reg106=0.16666666666666666667*reg106; reg75=reg57+reg75; reg48=elem.pos(0)[0]*reg30; reg110=0.16666666666666666667*reg110; reg102=0.5*reg102;
    reg79=reg44+reg79; reg77=reg59+reg77; reg95=0.5*reg95; reg109=reg109/2; reg60=0.5*reg60;
    reg76=2*reg76; reg62=reg111+reg62; reg119=reg119/2; reg112=reg124+reg112; reg99=reg49+reg99;
    reg92=reg121+reg92; reg51=reg54+reg51; reg118=reg66+reg118; reg63=reg63/3; reg69=0.5*reg69;
    reg61=reg23+reg61; reg93=reg93/3; reg84=0.5*reg84; reg52=reg52/2; reg56=reg116+reg56;
    reg85=reg85/2; reg123=0.16666666666666666667*reg123; reg103=reg42+reg103; reg73=reg73/3; reg122=0.16666666666666666667*reg122;
    reg109=reg48+reg109; reg104=reg104/4; reg65=0.16666666666666666667*reg65; reg40=0.16666666666666666667*reg40; reg95=reg95/3;
    reg23=2*reg61; reg79=0.16666666666666666667*reg79; reg42=2*reg51; reg110=reg110/4; reg92=reg73+reg92;
    reg44=2*reg75; reg123=reg123/4; reg48=2*reg103; reg106=reg106/4; reg49=2*reg99;
    reg29=reg115+reg29; reg53=2*reg21; reg50=reg50/4; reg83=reg83/3; reg93=reg112+reg93;
    reg63=reg62+reg63; reg122=reg122/4; reg47=reg72+reg47; reg52=reg76+reg52; reg71=reg87+reg71;
    reg77=0.16666666666666666667*reg77; reg102=reg102/3; reg34=reg38+reg34; reg15=reg13+reg15; reg56=0.16666666666666666667*reg56;
    reg69=reg69/3; reg85=reg68+reg85; reg41=reg119+reg41; reg84=reg84/3; reg118=0.16666666666666666667*reg118;
    reg60=reg60/3; reg95=reg109+reg95; reg79=reg79/4; reg13=reg42-reg23; reg102=reg34+reg102;
    reg110=reg47+reg110; reg34=reg49-reg53; reg38=reg48-reg44; reg106=reg29+reg106; reg50=reg71+reg50;
    reg60=reg52+reg60; reg69=reg15+reg69; reg83=reg41+reg83; reg118=reg118/4; reg65=reg65/4;
    reg104=reg92+reg104; reg56=reg56/4; reg40=reg40/4; reg123=reg93+reg123; reg84=reg85+reg84;
    reg122=reg63+reg122; reg15=0.5*reg31; reg77=reg77/4; reg29=reg43/2; reg79=reg95+reg79;
    reg44=reg103-reg44; reg41=4*reg103; reg13=reg42+reg13; reg47=reg110-reg123; reg23=reg51-reg23;
    reg34=reg49+reg34; reg29=reg29+reg25; reg36=0.5*reg36; reg53=reg99-reg53; reg38=reg48+reg38;
    reg52=reg106-reg104; reg15=reg15/3; reg54=4*reg51; reg55=reg50-reg122; reg37=reg37/2;
    reg40=reg69+reg40; reg118=reg84+reg118; reg65=reg83+reg65; reg57=reg46/2; reg77=reg102+reg77;
    reg58=0.5*reg35; reg59=4*reg99; reg56=reg60+reg56; reg38=reg38/2; reg60=2*reg50;
    reg62=1.5*reg56; reg34=reg34/2; reg44=reg44/2; reg36=reg36/3; reg53=reg53/2;
    reg57=reg57+reg27; reg63=reg122-reg65; reg64=3*reg118; reg52=reg52-reg104; reg30=reg37+reg30;
    reg37=reg42+reg54; reg15=reg29+reg15; reg122=reg55-reg122; reg29=reg48+reg41; reg13=reg13/2;
    reg55=reg49+reg59; reg66=1.5*reg77; reg67=2*reg106; reg68=1.5*reg118; reg23=reg23/2;
    reg69=3*reg77; reg47=reg47-reg123; reg104=reg104-reg79; reg70=2*reg110; reg71=3*reg56;
    reg58=reg58/3; reg123=reg123-reg40; reg53=reg63+reg53; reg23=reg123+reg23; reg44=reg104+reg44;
    reg57=reg58+reg57; reg77=0.5*reg77; reg56=0.5*reg56; reg66=reg66/3; reg68=reg68/3;
    reg62=reg62/3; reg13=reg47-reg13; reg47=reg29/2; reg58=reg55/2; reg63=reg71/3;
    reg72=reg64/3; reg73=reg106+reg67; reg21=reg21/2; reg74=reg69/3; reg34=reg122-reg34;
    reg38=reg52-reg38; reg61=reg61/2; reg52=2*reg15; reg75=reg75/2; reg76=reg50+reg60;
    reg36=reg30+reg36; reg118=0.5*reg118; reg30=reg110+reg70; reg78=reg37/2; reg34=reg34+reg63;
    reg62=reg53-reg62; reg65=reg21+reg65; reg13=reg13+reg72; reg68=reg23-reg68; reg21=reg56/3;
    reg23=reg47-reg73; reg66=reg44-reg66; reg61=reg40+reg61; reg38=reg38+reg74; reg40=reg118/3;
    reg44=2*reg57; reg53=reg52/2; reg75=reg79+reg75; reg79=reg57-reg36; reg80=reg77/3;
    reg81=reg78-reg30; reg82=reg58-reg76; reg40=reg61+reg40; reg21=reg65+reg21; reg82=reg82-reg63;
    reg13=0.5*reg13; reg66=reg66/2; reg23=reg23-reg74; reg34=0.5*reg34; reg62=reg62/2;
    reg38=0.5*reg38; reg80=reg75+reg80; reg61=reg15/2; reg81=reg81-reg72; reg79=reg79-reg53;
    reg68=reg68/2; reg65=reg53-reg44; reg38=reg38/3; reg80=reg66+reg80; reg81=0.16666666666666666667*reg81;
    reg23=0.16666666666666666667*reg23; reg82=0.16666666666666666667*reg82; reg79=reg79/2; reg62=reg21+reg62; reg68=reg40+reg68;
    reg34=reg34/3; reg65=0.5*reg65; reg36=reg61+reg36; reg13=reg13/3; reg34=reg62+reg34;
    reg23=reg23/4; reg81=reg81/4; reg65=reg65/3; reg38=reg80+reg38; reg13=reg68+reg13;
    reg79=reg36+reg79; reg82=reg82/4; reg82=reg34+reg82; reg65=reg79+reg65; reg23=reg38+reg23;
    reg81=reg13+reg81; res[2]=reg82/reg65; res[0]=reg23/reg65; res[1]=reg81/reg65;

    return res;
}
}
#endif // LMT_WEDGE
