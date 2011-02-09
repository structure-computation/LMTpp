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
    T reg0=0.5*nodes[1]->pos[1]; T reg1=0.5*nodes[0]->pos[2]; T reg2=0.5*nodes[0]->pos[1]; T reg3=0.5*nodes[2]->pos[1]; T reg4=0.5*nodes[2]->pos[2];
    T reg5=0.5*nodes[1]->pos[2]; T reg6=reg3+reg0; T reg7=0.5*nodes[3]->pos[2]; T reg8=reg4-reg1; T reg9=0.5*nodes[4]->pos[1];
    reg0=reg0-reg2; T reg10=0.5*nodes[3]->pos[1]; reg2=reg3-reg2; reg1=reg5-reg1; reg3=0.5*nodes[4]->pos[2];
    reg4=reg5+reg4; reg1=reg1-reg7; reg0=reg0-reg10; reg5=0.5*nodes[2]->pos[0]; T reg11=reg9-reg6;
    T reg12=0.5*nodes[5]->pos[2]; reg7=reg8-reg7; reg8=reg3-reg4; T reg13=0.5*nodes[0]->pos[0]; T reg14=0.5*nodes[5]->pos[1];
    reg10=reg2-reg10; reg2=0.5*nodes[1]->pos[0]; T reg15=reg5-reg13; reg8=reg8+reg12; reg1=reg3+reg1;
    reg13=reg2-reg13; reg0=reg9+reg0; reg3=0.5*nodes[3]->pos[0]; reg11=reg14+reg11; reg14=reg10+reg14;
    reg7=reg12+reg7; reg9=0.5*nodes[4]->pos[0]; reg13=reg13-reg3; reg5=reg2+reg5; reg2=reg8*reg14;
    reg10=reg7*reg11; reg8=reg8*reg0; reg11=reg11*reg1; reg12=0.5*nodes[5]->pos[0]; reg3=reg15-reg3;
    reg10=reg2-reg10; reg13=reg13+reg9; reg11=reg8-reg11; reg9=reg9-reg5; reg1=reg14*reg1;
    reg0=reg7*reg0; reg3=reg3+reg12; reg9=reg12+reg9; reg1=reg0-reg1; reg10=reg13*reg10;
    reg3=reg11*reg3; reg9=reg1*reg9; reg3=reg10-reg3; T det_jac=reg3+reg9;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1],nodes[3],nodes[5],nodes[4]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[0][0]*reg0; T reg2=pos_nodes[1][0]*var_inter[0]; T reg3=pos_nodes[0][1]*reg0;
    T reg4=pos_nodes[1][1]*var_inter[0]; T reg5=pos_nodes[0][2]*reg0; T reg6=var_inter[0]*pos_nodes[1][2]; T reg7=var_inter[1]*pos_nodes[2][0]; reg4=reg3+reg4;
    reg3=var_inter[1]*pos_nodes[2][1]; reg5=reg6+reg5; reg6=var_inter[1]*pos_nodes[2][2]; T reg8=1-var_inter[2]; reg1=reg2+reg1;
    reg2=pos_nodes[0][0]*reg8; reg6=reg5+reg6; reg5=reg8*pos_nodes[2][0]; T reg9=reg0*pos_nodes[3][2]; T reg10=reg8*pos_nodes[2][2];
    T reg11=pos_nodes[0][2]*reg8; reg3=reg4+reg3; reg4=reg0*pos_nodes[3][0]; T reg12=reg0*pos_nodes[3][1]; T reg13=reg8*pos_nodes[2][1];
    T reg14=pos_nodes[0][1]*reg8; reg7=reg1+reg7; reg1=var_inter[0]*pos_nodes[4][1]; reg3=reg12-reg3; reg10=reg10-reg11;
    reg12=var_inter[2]*pos_nodes[3][0]; reg5=reg5-reg2; reg6=reg9-reg6; reg9=var_inter[0]*pos_nodes[4][2]; reg13=reg13-reg14;
    T reg15=var_inter[0]*pos_nodes[4][0]; reg7=reg4-reg7; reg4=var_inter[2]*pos_nodes[3][1]; T reg16=var_inter[2]*pos_nodes[3][2]; T reg17=var_inter[1]*pos_nodes[5][2];
    reg9=reg6+reg9; reg6=reg8*var_inter[0]; T reg18=reg8*reg0; reg10=reg10-reg16; T reg19=var_inter[2]*pos_nodes[5][2];
    T reg20=var_inter[1]*pos_nodes[5][1]; reg1=reg3+reg1; reg5=reg5-reg12; reg3=var_inter[2]*pos_nodes[5][0]; T reg21=var_inter[1]*pos_nodes[5][0];
    T reg22=var_inter[2]*pos_nodes[5][1]; reg13=reg13-reg4; T reg23=pos_nodes[1][0]*reg8; reg15=reg7+reg15; reg7=pos_nodes[1][1]*reg8;
    reg19=reg10+reg19; reg10=pos_nodes[0][0]*reg18; T reg24=pos_nodes[1][0]*reg6; reg21=reg15+reg21; reg17=reg9+reg17;
    reg9=reg8*pos_nodes[1][2]; reg15=var_inter[1]*reg8; T reg25=pos_nodes[1][1]*reg6; T reg26=pos_nodes[0][1]*reg18; reg20=reg1+reg20;
    reg2=reg23-reg2; reg3=reg5+reg3; reg22=reg13+reg22; reg14=reg7-reg14; reg1=pos_nodes[0][2]*reg18;
    reg5=reg6*pos_nodes[1][2]; reg12=reg2-reg12; reg2=var_inter[2]*reg0; reg7=reg22*reg17; reg13=reg20*reg19;
    reg23=reg21*reg19; T reg27=reg3*reg17; T reg28=var_inter[2]*pos_nodes[4][0]; T reg29=reg15*pos_nodes[2][1]; reg10=reg24+reg10;
    reg25=reg26+reg25; reg24=var_inter[2]*pos_nodes[4][1]; reg11=reg9-reg11; reg9=reg15*pos_nodes[2][0]; reg4=reg14-reg4;
    reg14=reg3*reg20; reg26=reg2*pos_nodes[3][0]; reg9=reg10+reg9; reg10=var_inter[2]*var_inter[0]; T reg30=reg2*pos_nodes[3][1];
    reg13=reg7-reg13; reg29=reg25+reg29; reg23=reg27-reg23; reg25=reg21*reg22; reg24=reg4+reg24;
    reg28=reg12+reg28; reg4=var_inter[2]*pos_nodes[4][2]; reg16=reg11-reg16; reg1=reg5+reg1; reg5=reg15*pos_nodes[2][2];
    reg25=reg14-reg25; reg4=reg16+reg4; reg11=reg24*reg23; reg12=reg28*reg13; reg30=reg29+reg30;
    reg16=var_inter[1]*var_inter[2]; reg5=reg1+reg5; reg1=reg10*pos_nodes[4][1]; reg29=reg2*pos_nodes[3][2]; reg26=reg9+reg26;
    reg9=reg10*pos_nodes[4][0]; T reg31=reg28*reg17; T reg32=reg22*reg4; T reg33=reg21*reg4; T reg34=reg28*reg19;
    T reg35=reg3*reg4; T reg36=reg16*pos_nodes[5][0]; reg9=reg26+reg9; reg26=reg4*reg25; reg12=reg11-reg12;
    reg1=reg30+reg1; reg11=reg16*pos_nodes[5][1]; reg30=reg10*pos_nodes[4][2]; reg29=reg5+reg29; reg5=reg24*reg17;
    T reg37=reg24*reg19; T reg38=reg20*reg4; reg38=reg5-reg38; reg11=reg1+reg11; reg1=reg16*pos_nodes[5][2];
    T reg39=reg3*reg24; reg30=reg29+reg30; reg32=reg37-reg32; reg29=reg28*reg22; T reg40=reg21*reg24;
    T reg41=reg28*reg20; reg35=reg34-reg35; reg36=reg9+reg36; reg26=reg12-reg26; reg33=reg31-reg33;
    reg36=pos[0]-reg36; reg1=reg30+reg1; reg11=pos[1]-reg11; reg39=reg29-reg39; reg40=reg41-reg40;
    reg35=reg35/reg26; reg13=reg13/reg26; reg33=reg33/reg26; reg23=reg23/reg26; reg32=reg32/reg26;
    reg38=reg38/reg26; reg32=reg36*reg32; reg35=reg11*reg35; reg25=reg25/reg26; reg38=reg36*reg38;
    reg33=reg11*reg33; reg23=reg11*reg23; reg40=reg40/reg26; reg13=reg36*reg13; reg1=pos[2]-reg1;
    reg26=reg39/reg26; reg25=reg1*reg25; reg13=reg23-reg13; reg32=reg35-reg32; reg26=reg1*reg26;
    reg33=reg38-reg33; reg40=reg1*reg40; var_inter[2]=reg32-reg26; var_inter[1]=reg40+reg33; var_inter[0]=reg13-reg25;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[0][2]*reg0; T reg2=var_inter[0]*pos_nodes[1][2]; T reg3=pos_nodes[0][1]*reg0;
    T reg4=pos_nodes[1][1]*var_inter[0]; T reg5=pos_nodes[0][0]*reg0; T reg6=pos_nodes[1][0]*var_inter[0]; reg1=reg2+reg1; reg2=var_inter[1]*pos_nodes[2][2];
    reg5=reg6+reg5; reg6=var_inter[1]*pos_nodes[2][0]; T reg7=var_inter[1]*pos_nodes[2][1]; reg3=reg4+reg3; reg4=1-var_inter[2];
    T reg8=reg0*pos_nodes[3][1]; T reg9=reg4*pos_nodes[2][1]; reg7=reg3+reg7; reg6=reg5+reg6; reg3=pos_nodes[0][1]*reg4;
    reg5=reg0*pos_nodes[3][0]; reg2=reg1+reg2; reg1=reg4*pos_nodes[2][0]; T reg10=reg4*pos_nodes[2][2]; T reg11=pos_nodes[0][0]*reg4;
    T reg12=reg0*pos_nodes[3][2]; T reg13=pos_nodes[0][2]*reg4; reg7=reg8-reg7; reg8=var_inter[0]*pos_nodes[4][1]; reg9=reg9-reg3;
    T reg14=var_inter[0]*pos_nodes[4][0]; reg6=reg5-reg6; reg10=reg10-reg13; reg1=reg1-reg11; reg5=var_inter[2]*pos_nodes[3][1];
    T reg15=var_inter[0]*pos_nodes[4][2]; reg2=reg12-reg2; reg12=var_inter[2]*pos_nodes[3][2]; T reg16=var_inter[2]*pos_nodes[3][0]; T reg17=var_inter[1]*pos_nodes[5][2];
    reg9=reg9-reg5; T reg18=var_inter[2]*pos_nodes[5][1]; reg10=reg10-reg12; reg8=reg7+reg8; reg7=var_inter[1]*pos_nodes[5][1];
    reg15=reg2+reg15; reg2=var_inter[2]*pos_nodes[5][2]; T reg19=reg4*var_inter[0]; T reg20=pos_nodes[1][0]*reg4; T reg21=pos_nodes[1][1]*reg4;
    T reg22=var_inter[1]*pos_nodes[5][0]; reg1=reg1-reg16; T reg23=var_inter[2]*pos_nodes[5][0]; T reg24=reg0*reg4; reg14=reg6+reg14;
    reg6=pos_nodes[1][0]*reg19; reg22=reg14+reg22; reg7=reg8+reg7; reg8=pos_nodes[1][1]*reg19; reg14=pos_nodes[0][1]*reg24;
    reg23=reg1+reg23; reg1=reg4*var_inter[1]; T reg25=reg4*pos_nodes[1][2]; reg11=reg20-reg11; reg2=reg10+reg2;
    reg10=pos_nodes[0][0]*reg24; reg3=reg21-reg3; reg17=reg15+reg17; reg18=reg9+reg18; reg9=reg22*reg2;
    reg5=reg3-reg5; reg3=var_inter[2]*pos_nodes[4][1]; reg16=reg11-reg16; reg13=reg25-reg13; reg11=var_inter[2]*pos_nodes[4][0];
    reg15=reg19*pos_nodes[1][2]; reg20=reg23*reg17; reg21=pos_nodes[0][2]*reg24; reg25=reg18*reg17; T reg26=reg1*pos_nodes[2][1];
    reg14=reg8+reg14; reg8=reg7*reg2; T reg27=var_inter[2]*reg0; T reg28=reg1*pos_nodes[2][0]; reg10=reg6+reg10;
    reg21=reg15+reg21; reg6=reg1*pos_nodes[2][2]; reg15=reg23*reg7; reg8=reg25-reg8; reg9=reg20-reg9;
    T reg29=reg22*reg18; T reg30=var_inter[2]*pos_nodes[4][2]; reg12=reg13-reg12; reg11=reg16+reg11; reg13=var_inter[2]*var_inter[0];
    reg28=reg10+reg28; reg10=reg27*pos_nodes[3][1]; reg26=reg14+reg26; reg3=reg5+reg3; reg5=reg27*pos_nodes[3][0];
    reg14=var_inter[2]*var_inter[1]; reg29=reg15-reg29; reg16=reg3*reg9; T reg31=reg11*reg8; reg5=reg28+reg5;
    reg28=reg27*pos_nodes[3][2]; reg6=reg21+reg6; reg30=reg12+reg30; reg12=reg13*pos_nodes[4][1]; reg10=reg26+reg10;
    reg21=reg13*pos_nodes[4][0]; reg26=reg23*reg30; T reg32=reg11*reg2; T reg33=reg22*reg30; T reg34=reg11*reg17;
    T reg35=reg18*reg30; T reg36=reg3*reg2; T reg37=reg7*reg30; T reg38=reg3*reg17; T reg39=reg30*reg29;
    reg31=reg16-reg31; reg28=reg6+reg28; reg6=reg13*pos_nodes[4][2]; reg16=reg14*pos_nodes[5][0]; reg21=reg5+reg21;
    reg5=reg14*pos_nodes[5][1]; reg12=reg10+reg12; reg10=reg23*reg3; T reg40=reg11*reg18; T reg41=reg22*reg3;
    T reg42=reg11*reg7; reg26=reg32-reg26; reg6=reg28+reg6; reg33=reg34-reg33; reg28=reg14*pos_nodes[5][2];
    reg35=reg36-reg35; reg39=reg31-reg39; reg5=reg12+reg5; reg16=reg21+reg16; reg37=reg38-reg37;
    reg10=reg40-reg10; reg35=reg35/reg39; reg41=reg42-reg41; reg5=pos[1]-reg5; reg8=reg8/reg39;
    reg37=reg37/reg39; reg26=reg26/reg39; reg28=reg6+reg28; reg16=pos[0]-reg16; reg9=reg9/reg39;
    reg33=reg33/reg39; reg28=pos[2]-reg28; reg26=reg5*reg26; reg35=reg16*reg35; reg33=reg5*reg33;
    reg37=reg16*reg37; reg9=reg5*reg9; reg8=reg16*reg8; reg10=reg10/reg39; reg41=reg41/reg39;
    reg39=reg29/reg39; reg8=reg9-reg8; reg39=reg28*reg39; reg41=reg28*reg41; reg33=reg37-reg33;
    reg10=reg28*reg10; reg35=reg26-reg35; var_inter[0]+=reg8-reg39; var_inter[1]+=reg41+reg33; var_inter[2]+=reg35-reg10;

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
    T reg0=1-var_inter[0]; T reg1=1-var_inter[2]; reg0=reg0-var_inter[1]; T reg2=reg0*reg1; T reg3=var_inter[0]*reg1;
    reg2=val[0]*reg2; reg3=val[1]*reg3; T reg4=var_inter[1]*reg1; reg3=reg2+reg3; reg4=val[2]*reg4;
    reg0=var_inter[2]*reg0; reg2=var_inter[0]*var_inter[2]; reg0=val[3]*reg0; reg4=reg3+reg4; reg0=reg4+reg0;
    reg2=val[4]*reg2; reg3=var_inter[1]*var_inter[2]; reg2=reg0+reg2; reg3=val[5]*reg3; res=reg2+reg3;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=var_inter[0]*elem.pos(1)[1]; T reg2=var_inter[0]*elem.pos(1)[2]; T reg3=elem.pos(0)[2]*reg0;
    T reg4=reg0*elem.pos(0)[1]; T reg5=var_inter[1]*elem.pos(2)[2]; T reg6=1-var_inter[2]; T reg7=var_inter[1]*elem.pos(2)[1]; T reg8=reg2+reg3;
    T reg9=reg1+reg4; T reg10=elem.pos(1)[1]*reg6; T reg11=reg6*elem.pos(2)[1]; T reg12=reg7+reg9; T reg13=reg6*elem.pos(0)[1];
    T reg14=reg5+reg8; T reg15=reg6*elem.pos(2)[2]; T reg16=reg0*elem.pos(3)[2]; T reg17=elem.pos(0)[2]*reg6; T reg18=elem.pos(1)[2]*reg6;
    T reg19=reg0*elem.pos(3)[1]; T reg20=var_inter[0]*elem.pos(4)[1]; reg15=reg15-reg17; T reg21=var_inter[2]*elem.pos(3)[2]; reg18=reg18-reg17;
    T reg22=reg0*elem.pos(0)[0]; reg10=reg10-reg13; T reg23=var_inter[0]*elem.pos(1)[0]; reg16=reg16-reg14; T reg24=var_inter[0]*elem.pos(4)[2];
    T reg25=var_inter[2]*elem.pos(3)[1]; reg19=reg19-reg12; reg11=reg11-reg13; T reg26=var_inter[1]*elem.pos(2)[0]; reg11=reg11-reg25;
    T reg27=reg6*elem.pos(0)[0]; reg24=reg16+reg24; reg16=var_inter[1]*elem.pos(5)[2]; T reg28=elem.pos(1)[0]*reg6; T reg29=var_inter[2]*elem.pos(4)[1];
    reg19=reg20+reg19; reg20=elem.pos(2)[0]*reg6; T reg30=var_inter[2]*elem.pos(5)[1]; T reg31=reg23+reg22; T reg32=var_inter[2]*elem.pos(4)[2];
    T reg33=var_inter[1]*elem.pos(5)[1]; reg10=reg10-reg25; reg15=reg15-reg21; reg18=reg18-reg21; T reg34=var_inter[2]*elem.pos(5)[2];
    T reg35=reg0*elem.pos(3)[0]; reg16=reg24+reg16; reg19=reg33+reg19; reg10=reg29+reg10; reg24=reg31+reg26;
    reg20=reg20-reg27; reg32=reg18+reg32; reg34=reg15+reg34; reg15=var_inter[2]*elem.pos(3)[0]; reg11=reg30+reg11;
    reg28=reg28-reg27; reg18=var_inter[2]*elem.pos(4)[0]; reg28=reg28-reg15; reg29=var_inter[0]*elem.pos(4)[0]; reg30=reg19*reg34;
    reg33=reg11*reg16; T reg36=reg19*reg32; T reg37=var_inter[2]*elem.pos(5)[0]; reg35=reg35-reg24; reg20=reg20-reg15;
    T reg38=reg10*reg16; reg36=reg38-reg36; reg20=reg37+reg20; reg18=reg28+reg18; reg28=reg10*reg34;
    reg37=reg11*reg32; reg30=reg33-reg30; reg29=reg35+reg29; reg33=var_inter[1]*elem.pos(5)[0]; reg35=reg20*reg36;
    reg33=reg29+reg33; reg29=reg30*reg18; reg37=reg28-reg37; reg35=reg29-reg35; reg28=reg33*reg37;
    reg28=reg35+reg28; return reg28;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Wedge,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.78867513459481286553*elem.pos(2)[2]; T reg1=0.5*elem.pos(1)[2]; T reg2=0.78867513459481286553*elem.pos(0)[2]; T reg3=0.5*elem.pos(1)[1]; T reg4=0.5*elem.pos(0)[1];
    T reg5=0.78867513459481286553*elem.pos(0)[1]; T reg6=0.78867513459481286553*elem.pos(2)[1]; T reg7=0.78867513459481286553*elem.pos(1)[1]; T reg8=0.5*elem.pos(0)[2]; T reg9=0.78867513459481286553*elem.pos(1)[2];
    T reg10=0.5*elem.pos(2)[2]; T reg11=0.5*elem.pos(2)[1]; reg6=reg6-reg5; T reg12=0.21132486540518713447*elem.pos(3)[1]; T reg13=0.5*elem.pos(3)[2];
    T reg14=reg1+reg8; T reg15=0.5*elem.pos(4)[2]; reg0=reg0-reg2; T reg16=0.21132486540518713447*elem.pos(3)[2]; T reg17=0.5*elem.pos(3)[1];
    T reg18=reg3+reg4; T reg19=0.5*elem.pos(4)[1]; reg5=reg7-reg5; reg2=reg9-reg2; reg1=reg1+reg10;
    reg3=reg3+reg11; reg7=0.78867513459481286553*elem.pos(0)[0]; reg9=0.21132486540518713447*elem.pos(1)[2]; reg6=reg6-reg12; T reg20=0.21132486540518713447*elem.pos(5)[1];
    reg14=reg13-reg14; reg0=reg0-reg16; T reg21=0.21132486540518713447*elem.pos(5)[2]; reg18=reg17-reg18; T reg22=0.78867513459481286553*elem.pos(2)[0];
    reg12=reg5-reg12; reg5=0.21132486540518713447*elem.pos(4)[1]; reg16=reg2-reg16; reg2=0.21132486540518713447*elem.pos(4)[2]; T reg23=0.21132486540518713447*elem.pos(0)[1];
    T reg24=0.21132486540518713447*elem.pos(2)[1]; T reg25=reg15-reg1; T reg26=0.5*elem.pos(5)[2]; T reg27=reg19-reg3; T reg28=0.5*elem.pos(5)[1];
    reg11=reg4+reg11; reg10=reg8+reg10; reg4=0.21132486540518713447*elem.pos(1)[1]; reg8=0.21132486540518713447*elem.pos(0)[2]; T reg29=0.21132486540518713447*elem.pos(2)[2];
    T reg30=0.78867513459481286553*elem.pos(1)[0]; reg5=reg12+reg5; reg12=0.78867513459481286553*elem.pos(3)[2]; reg2=reg16+reg2; reg22=reg22-reg7;
    reg16=0.78867513459481286553*elem.pos(3)[1]; reg19=reg18+reg19; reg18=0.5*elem.pos(0)[0]; T reg31=0.5*elem.pos(1)[0]; reg24=reg24-reg23;
    reg21=reg0+reg21; reg29=reg29-reg8; reg23=reg4-reg23; reg15=reg14+reg15; reg10=reg13-reg10;
    reg11=reg17-reg11; reg8=reg9-reg8; reg0=0.5*elem.pos(2)[0]; reg4=0.21132486540518713447*elem.pos(3)[0]; reg20=reg6+reg20;
    reg27=reg27+reg28; reg25=reg25+reg26; reg7=reg30-reg7; reg6=reg15*reg5; reg10=reg26+reg10;
    reg9=0.78867513459481286553*elem.pos(4)[1]; reg11=reg28+reg11; reg13=0.78867513459481286553*elem.pos(5)[2]; reg14=reg19*reg2; reg24=reg24-reg16;
    reg29=reg29-reg12; reg17=0.5*elem.pos(3)[0]; reg26=reg2*reg27; reg28=reg20*reg25; reg30=0.21132486540518713447*elem.pos(1)[0];
    T reg32=reg18+reg31; T reg33=0.5*elem.pos(4)[0]; T reg34=reg5*reg25; reg16=reg23-reg16; reg23=reg21*reg27;
    T reg35=0.21132486540518713447*elem.pos(0)[0]; T reg36=0.21132486540518713447*elem.pos(2)[0]; T reg37=0.78867513459481286553*elem.pos(4)[2]; reg31=reg31+reg0; reg12=reg8-reg12;
    reg8=reg21*reg19; T reg38=0.78867513459481286553*elem.pos(5)[1]; reg22=reg22-reg4; T reg39=0.21132486540518713447*elem.pos(5)[0]; T reg40=reg20*reg15;
    T reg41=0.21132486540518713447*elem.pos(4)[0]; reg4=reg7-reg4; reg13=reg29+reg13; reg7=0.39433756729740643276*elem.pos(0)[1]; reg0=reg18+reg0;
    reg18=0.39433756729740643276*elem.pos(1)[1]; reg29=0.39433756729740643276*elem.pos(2)[1]; reg36=reg36-reg35; reg37=reg12+reg37; reg23=reg28-reg23;
    reg26=reg34-reg26; reg12=reg2*reg11; reg28=reg5*reg10; reg34=reg33-reg31; T reg42=0.5*elem.pos(5)[0];
    T reg43=reg21*reg11; reg38=reg24+reg38; reg24=reg20*reg10; reg41=reg4+reg41; reg9=reg16+reg9;
    reg4=0.39433756729740643276*elem.pos(2)[2]; reg39=reg22+reg39; reg16=0.39433756729740643276*elem.pos(0)[0]; reg14=reg6-reg14; reg8=reg40-reg8;
    reg6=0.39433756729740643276*elem.pos(1)[0]; reg32=reg17-reg32; reg22=0.39433756729740643276*elem.pos(0)[2]; reg40=0.39433756729740643276*elem.pos(1)[2]; reg5=reg21*reg5;
    reg2=reg20*reg2; reg20=0.39433756729740643276*elem.pos(2)[0]; reg35=reg30-reg35; reg21=0.78867513459481286553*elem.pos(3)[0]; reg30=0.10566243270259356724*elem.pos(4)[1];
    T reg44=reg40+reg4; T reg45=0.10566243270259356724*elem.pos(4)[2]; T reg46=0.78867513459481286553*elem.pos(5)[0]; T reg47=reg15*reg9; reg0=reg17-reg0;
    reg43=reg24-reg43; reg17=0.10566243270259356724*elem.pos(3)[1]; reg24=reg18+reg7; T reg48=0.10566243270259356724*elem.pos(3)[2]; reg40=reg40+reg22;
    reg35=reg35-reg21; reg15=reg15*reg38; T reg49=0.78867513459481286553*elem.pos(4)[0]; reg12=reg28-reg12; reg28=reg19*reg13;
    reg19=reg19*reg37; reg21=reg36-reg21; reg18=reg18+reg29; reg36=reg16+reg6; T reg50=0.10566243270259356724*elem.pos(3)[0];
    reg23=reg41*reg23; reg26=reg39*reg26; T reg51=0.10566243270259356724*elem.pos(4)[0]; reg34=reg34+reg42; reg8=reg41*reg8;
    reg14=reg39*reg14; reg33=reg32+reg33; reg2=reg5-reg2; reg6=reg6+reg20; reg14=reg8-reg14;
    reg36=reg36+reg50; reg5=reg33*reg2; reg49=reg35+reg49; reg8=0.10566243270259356724*elem.pos(0)[1]; reg32=0.10566243270259356724*elem.pos(1)[1];
    reg28=reg15-reg28; reg29=reg7+reg29; reg46=reg21+reg46; reg7=0.10566243270259356724*elem.pos(5)[1]; reg18=reg30+reg18;
    reg24=reg24+reg17; reg15=0.10566243270259356724*elem.pos(1)[2]; reg21=0.10566243270259356724*elem.pos(0)[2]; reg19=reg47-reg19; reg35=reg13*reg9;
    reg47=reg38*reg37; T reg52=reg27*reg37; T reg53=reg25*reg9; reg25=reg25*reg38; reg27=reg27*reg13;
    T reg54=0.10566243270259356724*elem.pos(5)[2]; reg20=reg16+reg20; reg44=reg45+reg44; reg16=reg2*reg34; reg43=reg41*reg43;
    reg26=reg23-reg26; reg12=reg39*reg12; reg23=0.10566243270259356724*elem.pos(5)[0]; reg0=reg42+reg0; reg40=reg40+reg48;
    reg4=reg22+reg4; reg22=0.10566243270259356724*elem.pos(0)[0]; reg39=0.10566243270259356724*elem.pos(1)[0]; reg6=reg51+reg6; reg41=0.10566243270259356724*elem.pos(2)[2];
    reg5=reg14+reg5; reg14=reg15+reg21; reg42=0.39433756729740643276*elem.pos(3)[2]; reg37=reg11*reg37; reg16=reg26+reg16;
    reg19=reg46*reg19; reg9=reg10*reg9; reg44=reg44+reg54; reg47=reg35-reg47; reg13=reg11*reg13;
    reg38=reg10*reg38; reg52=reg53-reg52; reg10=0.10566243270259356724*elem.pos(2)[0]; reg27=reg25-reg27; reg20=reg50+reg20;
    reg11=0.10566243270259356724*elem.pos(2)[1]; reg51=reg36+reg51; reg25=reg22+reg39; reg45=reg40+reg45; reg26=0.39433756729740643276*elem.pos(3)[1];
    reg35=reg32+reg8; reg2=reg2*reg0; reg36=0.39433756729740643276*elem.pos(3)[0]; reg28=reg49*reg28; reg29=reg17+reg29;
    reg30=reg24+reg30; reg12=reg43-reg12; reg6=reg6+reg23; reg18=reg18+reg7; reg48=reg4+reg48;
    reg44=reg44*reg16; reg29=reg7+reg29; reg13=reg38-reg13; reg37=reg9-reg37; reg45=reg5*reg45;
    reg52=reg46*reg52; reg18=reg16*reg18; reg54=reg48+reg54; reg35=reg35+reg26; reg4=0.39433756729740643276*elem.pos(4)[1];
    reg27=reg49*reg27; reg30=reg5*reg30; reg32=reg32+reg11; reg15=reg15+reg41; reg7=0.39433756729740643276*elem.pos(4)[2];
    reg14=reg14+reg42; reg19=reg28-reg19; reg51=reg51*reg5; reg33=reg33*reg47; reg9=0.39433756729740643276*elem.pos(4)[0];
    reg20=reg23+reg20; reg6=reg6*reg16; reg39=reg39+reg10; reg2=reg12+reg2; reg25=reg25+reg36;
    reg14=reg14+reg7; reg15=reg7+reg15; reg7=0.39433756729740643276*elem.pos(5)[2]; reg30=0.083333333333333328707*reg30; reg54=reg54*reg2;
    reg18=0.083333333333333328707*reg18; reg41=reg21+reg41; reg29=reg2*reg29; reg5=0.083333333333333328707*reg5; reg6=0.083333333333333328707*reg6;
    reg44=0.083333333333333328707*reg44; reg11=reg8+reg11; reg45=0.083333333333333328707*reg45; reg8=0.39433756729740643276*elem.pos(5)[1]; reg20=reg20*reg2;
    reg35=reg35+reg4; reg51=0.083333333333333328707*reg51; reg25=reg25+reg9; reg32=reg4+reg32; reg4=0.39433756729740643276*elem.pos(5)[0];
    reg39=reg9+reg39; reg52=reg27-reg52; reg34=reg34*reg47; reg37=reg46*reg37; reg13=reg49*reg13;
    reg10=reg22+reg10; reg33=reg19+reg33; reg16=0.083333333333333328707*reg16; reg18=reg30+reg18; reg47=reg0*reg47;
    reg41=reg42+reg41; reg37=reg13-reg37; reg29=0.083333333333333328707*reg29; reg25=reg25*reg33; reg35=reg33*reg35;
    reg10=reg36+reg10; reg32=reg32+reg8; reg11=reg26+reg11; reg34=reg52+reg34; reg45=reg44+reg45;
    reg20=0.083333333333333328707*reg20; reg6=reg51+reg6; reg39=reg39+reg4; reg15=reg15+reg7; reg2=0.083333333333333328707*reg2;
    reg14=reg14*reg33; reg54=0.083333333333333328707*reg54; reg16=reg5+reg16; reg2=reg16+reg2; reg33=0.083333333333333328707*reg33;
    reg25=0.083333333333333328707*reg25; reg20=reg6+reg20; reg39=reg39*reg34; reg11=reg8+reg11; reg32=reg34*reg32;
    reg14=0.083333333333333328707*reg14; reg10=reg4+reg10; reg35=0.083333333333333328707*reg35; reg47=reg37+reg47; reg15=reg15*reg34;
    reg41=reg7+reg41; reg29=reg18+reg29; reg54=reg45+reg54; reg33=reg2+reg33; reg34=0.083333333333333328707*reg34;
    reg25=reg20+reg25; reg15=0.083333333333333328707*reg15; reg35=reg29+reg35; reg11=reg47*reg11; reg10=reg10*reg47;
    reg14=reg54+reg14; reg39=0.083333333333333328707*reg39; reg41=reg41*reg47; reg32=0.083333333333333328707*reg32; reg15=reg14+reg15;
    reg39=reg25+reg39; reg41=0.083333333333333328707*reg41; reg34=reg33+reg34; reg47=0.083333333333333328707*reg47; reg11=0.083333333333333328707*reg11;
    reg32=reg35+reg32; reg10=0.083333333333333328707*reg10; reg47=reg34+reg47; reg10=reg39+reg10; reg11=reg32+reg11;
    reg41=reg15+reg41; res[0]=reg10/reg47; res[1]=reg11/reg47; res[2]=reg41/reg47;

    return res;
}
}
#endif // LMT_WEDGE
