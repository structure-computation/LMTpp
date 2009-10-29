#ifndef LMT_WEDGE
#define LMT_WEDGE
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Wedge &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 25, 50, 75, 108, 181, 266, 351, 436, 521, }; // fonction de lordre du poly
    static const double values[] = {
        0.0833333333333,0.5,0.0,0.211324865405,
        0.0833333333333,0.5,0.5,0.211324865405,
        0.0833333333333,0.0,0.5,0.211324865405,
        0.0833333333333,0.5,0.0,0.788675134595,
        0.0833333333333,0.5,0.5,0.788675134595,
        0.0833333333333,0.0,0.5,0.788675134595,
        0.0,
        0.0833333333333,0.5,0.0,0.211324865405,
        0.0833333333333,0.5,0.5,0.211324865405,
        0.0833333333333,0.0,0.5,0.211324865405,
        0.0833333333333,0.5,0.0,0.788675134595,
        0.0833333333333,0.5,0.5,0.788675134595,
        0.0833333333333,0.0,0.5,0.788675134595,
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
    T reg0=0.5*nodes[0]->pos[1]; T reg1=0.5*nodes[2]->pos[1]; T reg2=0.5*nodes[0]->pos[2]; T reg3=0.5*nodes[2]->pos[2]; T reg4=0.5*nodes[1]->pos[2];
    T reg5=0.5*nodes[1]->pos[1]; T reg6=reg1+reg5; T reg7=0.5*nodes[4]->pos[1]; reg5=reg5-reg0; T reg8=reg4-reg2;
    T reg9=0.5*nodes[3]->pos[2]; reg2=reg3-reg2; T reg10=0.5*nodes[3]->pos[1]; reg0=reg1-reg0; reg1=0.5*nodes[4]->pos[2];
    reg3=reg4+reg3; reg4=0.5*nodes[2]->pos[0]; reg8=reg8-reg9; reg5=reg5-reg10; T reg11=0.5*nodes[0]->pos[0];
    T reg12=0.5*nodes[1]->pos[0]; T reg13=reg7-reg6; reg9=reg2-reg9; reg2=reg1-reg3; T reg14=0.5*nodes[5]->pos[2];
    reg10=reg0-reg10; reg0=0.5*nodes[5]->pos[1]; reg2=reg14+reg2; T reg15=reg4-reg11; reg8=reg1+reg8;
    reg5=reg7+reg5; reg10=reg10+reg0; reg9=reg14+reg9; reg13=reg0+reg13; reg0=0.5*nodes[3]->pos[0];
    reg11=reg12-reg11; reg4=reg12+reg4; reg1=0.5*nodes[5]->pos[0]; reg15=reg15-reg0; reg7=reg9*reg13;
    reg13=reg13*reg8; reg12=reg2*reg10; reg2=reg2*reg5; reg0=reg11-reg0; reg11=0.5*nodes[4]->pos[0];
    reg0=reg0+reg11; reg11=reg11-reg4; reg8=reg10*reg8; reg5=reg9*reg5; reg15=reg15+reg1;
    reg7=reg12-reg7; reg13=reg2-reg13; reg15=reg13*reg15; reg8=reg5-reg8; reg11=reg1+reg11;
    reg0=reg7*reg0; reg15=reg0-reg15; reg11=reg8*reg11; T det_jac=reg15+reg11;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1],nodes[3],nodes[5],nodes[4]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=var_inter[0]*pos_nodes[1][1]; T reg2=pos_nodes[0][1]*reg0; T reg3=reg0*pos_nodes[0][2];
    T reg4=var_inter[0]*pos_nodes[1][2]; T reg5=pos_nodes[0][0]*reg0; T reg6=var_inter[0]*pos_nodes[1][0]; T reg7=1-var_inter[2]; reg6=reg5+reg6;
    reg5=var_inter[1]*pos_nodes[2][2]; reg4=reg3+reg4; reg3=var_inter[1]*pos_nodes[2][1]; reg2=reg1+reg2; reg1=var_inter[1]*pos_nodes[2][0];
    T reg8=reg7*pos_nodes[0][2]; T reg9=reg7*pos_nodes[2][2]; T reg10=reg0*pos_nodes[3][2]; T reg11=pos_nodes[0][1]*reg7; reg5=reg4+reg5;
    reg4=pos_nodes[0][0]*reg7; T reg12=reg7*pos_nodes[2][0]; T reg13=reg0*pos_nodes[3][0]; reg1=reg6+reg1; reg3=reg2+reg3;
    reg2=reg7*pos_nodes[2][1]; reg6=reg0*pos_nodes[3][1]; T reg14=var_inter[2]*pos_nodes[3][2]; reg9=reg9-reg8; T reg15=var_inter[2]*pos_nodes[3][1];
    reg5=reg10-reg5; reg10=var_inter[0]*pos_nodes[4][2]; T reg16=var_inter[2]*pos_nodes[3][0]; reg12=reg12-reg4; T reg17=var_inter[0]*pos_nodes[4][0];
    reg1=reg13-reg1; reg2=reg2-reg11; reg3=reg6-reg3; reg6=var_inter[0]*pos_nodes[4][1]; reg13=reg0*reg7;
    T reg18=reg7*pos_nodes[1][0]; reg12=reg12-reg16; T reg19=var_inter[2]*pos_nodes[5][0]; T reg20=var_inter[1]*pos_nodes[5][2]; reg10=reg5+reg10;
    reg5=var_inter[1]*pos_nodes[5][1]; T reg21=reg7*pos_nodes[1][1]; T reg22=var_inter[0]*reg7; reg2=reg2-reg15; T reg23=var_inter[2]*pos_nodes[5][1];
    reg6=reg3+reg6; reg17=reg1+reg17; reg9=reg9-reg14; reg1=var_inter[2]*pos_nodes[5][2]; reg3=var_inter[1]*pos_nodes[5][0];
    reg19=reg12+reg19; reg12=var_inter[1]*reg7; reg3=reg17+reg3; reg23=reg2+reg23; reg5=reg6+reg5;
    reg2=reg22*pos_nodes[1][1]; reg6=pos_nodes[0][1]*reg13; reg4=reg18-reg4; reg17=reg22*pos_nodes[1][0]; reg18=pos_nodes[0][0]*reg13;
    reg20=reg10+reg20; reg11=reg21-reg11; reg1=reg9+reg1; reg9=reg7*pos_nodes[1][2]; reg17=reg18+reg17;
    reg8=reg9-reg8; reg9=var_inter[2]*reg0; reg10=reg12*pos_nodes[2][0]; reg18=reg12*pos_nodes[2][1]; reg21=reg13*pos_nodes[0][2];
    T reg24=reg22*pos_nodes[1][2]; reg15=reg11-reg15; reg11=reg3*reg1; T reg25=reg20*reg19; T reg26=var_inter[2]*pos_nodes[4][0];
    reg16=reg4-reg16; reg4=reg5*reg1; T reg27=reg23*reg20; T reg28=var_inter[2]*pos_nodes[4][1]; reg6=reg2+reg6;
    reg26=reg16+reg26; reg24=reg21+reg24; reg2=reg12*pos_nodes[2][2]; reg18=reg6+reg18; reg6=reg9*pos_nodes[3][0];
    reg10=reg17+reg10; reg16=reg9*pos_nodes[3][1]; reg28=reg15+reg28; reg4=reg27-reg4; reg15=reg5*reg19;
    reg11=reg25-reg11; reg17=reg3*reg23; reg21=var_inter[2]*pos_nodes[4][2]; reg14=reg8-reg14; reg8=var_inter[2]*var_inter[0];
    T reg29=var_inter[1]*var_inter[2]; T reg30=reg8*pos_nodes[4][0]; reg6=reg10+reg6; reg10=reg9*pos_nodes[3][2]; reg2=reg24+reg2;
    reg24=reg4*reg26; reg16=reg18+reg16; reg18=reg8*pos_nodes[4][1]; T reg31=reg28*reg11; reg17=reg15-reg17;
    reg21=reg14+reg21; reg18=reg16+reg18; reg10=reg2+reg10; reg2=reg29*pos_nodes[5][1]; reg30=reg6+reg30;
    reg6=reg29*pos_nodes[5][0]; reg14=reg1*reg26; reg16=reg21*reg19; T reg32=reg3*reg21; T reg33=reg20*reg26;
    T reg34=reg23*reg21; T reg35=reg28*reg1; T reg36=reg5*reg21; T reg37=reg28*reg20; T reg38=reg8*pos_nodes[4][2];
    T reg39=reg21*reg17; reg24=reg31-reg24; reg38=reg10+reg38; reg32=reg33-reg32; reg16=reg14-reg16;
    reg10=reg5*reg26; reg31=reg3*reg28; T reg40=reg23*reg26; T reg41=reg28*reg19; T reg42=reg29*pos_nodes[5][2];
    reg34=reg35-reg34; reg36=reg37-reg36; reg6=reg30+reg6; reg39=reg24-reg39; reg2=reg18+reg2;
    reg34=reg34/reg39; reg11=reg11/reg39; reg2=pos[1]-reg2; reg42=reg38+reg42; reg36=reg36/reg39;
    reg32=reg32/reg39; reg4=reg4/reg39; reg16=reg16/reg39; reg31=reg10-reg31; reg41=reg40-reg41;
    reg6=pos[0]-reg6; reg32=reg2*reg32; reg42=pos[2]-reg42; reg34=reg6*reg34; reg16=reg2*reg16;
    reg36=reg6*reg36; reg11=reg2*reg11; reg4=reg6*reg4; reg41=reg41/reg39; reg31=reg31/reg39;
    reg39=reg17/reg39; reg4=reg11-reg4; reg39=reg42*reg39; reg34=reg16-reg34; reg41=reg42*reg41;
    reg32=reg36-reg32; reg31=reg42*reg31; var_inter[2]=reg34-reg41; var_inter[1]=reg31+reg32; var_inter[0]=reg4-reg39;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[0][2]*reg0; T reg2=pos_nodes[0][1]*reg0; T reg3=pos_nodes[1][1]*var_inter[0];
    T reg4=pos_nodes[1][2]*var_inter[0]; T reg5=pos_nodes[1][0]*var_inter[0]; T reg6=pos_nodes[0][0]*reg0; T reg7=pos_nodes[2][1]*var_inter[1]; T reg8=1-var_inter[2];
    reg2=reg3+reg2; reg3=pos_nodes[2][2]*var_inter[1]; reg1=reg4+reg1; reg4=pos_nodes[2][0]*var_inter[1]; reg6=reg5+reg6;
    reg5=pos_nodes[2][0]*reg8; T reg9=pos_nodes[3][2]*reg0; T reg10=pos_nodes[0][1]*reg8; T reg11=pos_nodes[3][0]*reg0; reg6=reg4+reg6;
    reg1=reg3+reg1; reg3=pos_nodes[2][1]*reg8; reg4=pos_nodes[0][0]*reg8; T reg12=pos_nodes[0][2]*reg8; T reg13=pos_nodes[3][1]*reg0;
    reg2=reg7+reg2; reg7=pos_nodes[2][2]*reg8; T reg14=pos_nodes[4][2]*var_inter[0]; reg1=reg9-reg1; reg9=var_inter[2]*pos_nodes[3][2];
    T reg15=pos_nodes[4][1]*var_inter[0]; reg2=reg13-reg2; reg3=reg3-reg10; reg7=reg7-reg12; reg13=var_inter[2]*pos_nodes[3][1];
    T reg16=pos_nodes[4][0]*var_inter[0]; reg6=reg11-reg6; reg5=reg5-reg4; reg11=var_inter[2]*pos_nodes[3][0]; T reg17=pos_nodes[5][1]*var_inter[1];
    reg15=reg2+reg15; reg2=pos_nodes[1][0]*reg8; T reg18=reg8*reg0; T reg19=var_inter[0]*reg8; T reg20=pos_nodes[5][1]*var_inter[2];
    reg3=reg3-reg13; reg7=reg7-reg9; T reg21=pos_nodes[5][2]*var_inter[2]; T reg22=pos_nodes[5][0]*var_inter[1]; T reg23=pos_nodes[1][1]*reg8;
    T reg24=pos_nodes[5][2]*var_inter[1]; reg5=reg5-reg11; T reg25=pos_nodes[5][0]*var_inter[2]; reg14=reg1+reg14; reg16=reg6+reg16;
    reg1=pos_nodes[1][2]*reg8; reg6=reg18*pos_nodes[0][1]; T reg26=pos_nodes[1][1]*reg19; reg17=reg15+reg17; reg22=reg16+reg22;
    reg15=pos_nodes[1][0]*reg19; reg16=reg18*pos_nodes[0][0]; reg25=reg5+reg25; reg5=reg8*var_inter[1]; reg20=reg3+reg20;
    reg4=reg2-reg4; reg21=reg7+reg21; reg24=reg14+reg24; reg10=reg23-reg10; reg2=reg25*reg24;
    reg3=reg22*reg21; reg7=pos_nodes[0][2]*reg18; reg14=reg20*reg24; reg23=reg17*reg21; reg12=reg1-reg12;
    reg1=pos_nodes[1][2]*reg19; T reg27=var_inter[2]*reg0; reg16=reg15+reg16; reg13=reg10-reg13; reg10=var_inter[2]*pos_nodes[4][1];
    reg15=pos_nodes[2][0]*reg5; reg11=reg4-reg11; reg6=reg26+reg6; reg4=pos_nodes[2][1]*reg5; reg26=var_inter[2]*pos_nodes[4][0];
    T reg28=pos_nodes[3][0]*reg27; reg16=reg15+reg16; reg26=reg11+reg26; reg11=pos_nodes[2][2]*reg5; reg7=reg1+reg7;
    reg1=reg22*reg20; reg3=reg2-reg3; reg15=var_inter[2]*var_inter[0]; reg23=reg14-reg23; T reg29=reg25*reg17;
    reg10=reg13+reg10; reg13=var_inter[2]*pos_nodes[4][2]; reg9=reg12-reg9; reg6=reg4+reg6; reg4=pos_nodes[3][1]*reg27;
    reg12=pos_nodes[4][1]*reg15; T reg30=reg26*reg23; reg1=reg29-reg1; T reg31=reg10*reg3; reg4=reg6+reg4;
    reg6=pos_nodes[3][2]*reg27; reg7=reg11+reg7; reg11=var_inter[2]*var_inter[1]; reg13=reg9+reg13; reg28=reg16+reg28;
    reg9=pos_nodes[4][0]*reg15; reg16=reg10*reg21; T reg32=reg20*reg13; reg30=reg31-reg30; reg31=reg13*reg1;
    T reg33=reg26*reg24; T reg34=reg10*reg24; T reg35=reg26*reg21; T reg36=reg25*reg13; T reg37=reg17*reg13;
    T reg38=reg22*reg13; T reg39=pos_nodes[4][2]*reg15; reg6=reg7+reg6; reg7=pos_nodes[5][1]*reg11; reg12=reg4+reg12;
    reg9=reg28+reg9; reg4=pos_nodes[5][0]*reg11; reg28=reg25*reg10; T reg40=reg26*reg20; T reg41=reg22*reg10;
    T reg42=reg26*reg17; reg36=reg35-reg36; reg38=reg33-reg38; reg32=reg16-reg32; reg4=reg9+reg4;
    reg37=reg34-reg37; reg9=pos_nodes[5][2]*reg11; reg39=reg6+reg39; reg31=reg30-reg31; reg7=reg12+reg7;
    reg28=reg40-reg28; reg9=reg39+reg9; reg41=reg42-reg41; reg7=pos[1]-reg7; reg36=reg36/reg31;
    reg23=reg23/reg31; reg38=reg38/reg31; reg4=pos[0]-reg4; reg3=reg3/reg31; reg37=reg37/reg31;
    reg32=reg32/reg31; reg9=pos[2]-reg9; reg36=reg7*reg36; reg32=reg4*reg32; reg38=reg7*reg38;
    reg37=reg4*reg37; reg3=reg7*reg3; reg23=reg4*reg23; reg28=reg28/reg31; reg41=reg41/reg31;
    reg31=reg1/reg31; reg23=reg3-reg23; reg31=reg9*reg31; reg41=reg9*reg41; reg38=reg37-reg38;
    reg28=reg9*reg28; reg32=reg36-reg32; var_inter[0]+=reg23-reg31; var_inter[1]+=reg41+reg38; var_inter[2]+=reg32-reg28;

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
    reg0=var_inter[2]*reg0; reg4=reg2+reg4; reg0=val[3]*reg0; reg2=var_inter[0]*var_inter[2]; reg3=var_inter[1]*var_inter[2];
    reg2=val[4]*reg2; reg0=reg4+reg0; reg2=reg0+reg2; reg3=val[5]*reg3; res=reg2+reg3;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[0]; T reg1=var_inter[2]-0.21132486540518707896; T reg2=2*var_inter[1]; T reg3=reg2+reg0; T reg4=1-var_inter[2];
    reg1=reg1/0.57735026918962573106; reg3=reg3-1; reg1=1-reg1; T reg5=reg4-0.21132486540518707896; reg2=1-reg2;
    T reg6=reg1*reg3; T reg7=reg2*reg1; reg0=1-reg0; reg5=reg5/0.57735026918962573106; reg1=reg1*reg0;
    reg6=val[1]*reg6; reg5=1-reg5; reg7=val[0]*reg7; reg6=reg7+reg6; reg7=reg5*reg2;
    reg1=val[2]*reg1; reg6=reg1+reg6; reg7=val[3]*reg7; reg1=reg5*reg3; reg7=reg6+reg7;
    reg5=reg5*reg0; reg1=val[4]*reg1; reg5=val[5]*reg5; reg1=reg7+reg1; res=reg1+reg5;

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[1]; T reg1=2*var_inter[0]; T reg2=reg0+reg1; reg1=1-reg1; reg2=reg2-1;
    T reg3=val[1]*reg1; T reg4=val[0]*reg2; reg0=1-reg0; T reg5=val[2]*reg0; reg3=reg4+reg3;
    res=reg3+reg5;

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

}
#endif // LMT_WEDGE
