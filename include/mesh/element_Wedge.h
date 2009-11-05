#ifndef LMT_WEDGE
#define LMT_WEDGE
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Wedge &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 25, 50, 75, 108, 181, 266, 351, 436, 521, }; // fonction de lordre du poly
    static const double values[] = {
        0.0833333333333,0.0,0.5,0.211324865405,
        0.0833333333333,0.5,0.5,0.211324865405,
        0.0833333333333,0.5,0.0,0.211324865405,
        0.0833333333333,0.0,0.5,0.788675134595,
        0.0833333333333,0.5,0.5,0.788675134595,
        0.0833333333333,0.5,0.0,0.788675134595,
        0.0,
        0.0833333333333,0.0,0.5,0.211324865405,
        0.0833333333333,0.5,0.5,0.211324865405,
        0.0833333333333,0.5,0.0,0.211324865405,
        0.0833333333333,0.0,0.5,0.788675134595,
        0.0833333333333,0.5,0.5,0.788675134595,
        0.0833333333333,0.5,0.0,0.788675134595,
        0.0,
        0.0833333333333,0.0,0.5,0.211324865405,
        0.0833333333333,0.5,0.5,0.211324865405,
        0.0833333333333,0.5,0.0,0.211324865405,
        0.0833333333333,0.0,0.5,0.788675134595,
        0.0833333333333,0.5,0.5,0.788675134595,
        0.0833333333333,0.5,0.0,0.788675134595,
        0.0,
        -0.140625,0.333333333333,0.333333333333,0.211324865405,
        0.130208333333,0.2,0.2,0.211324865405,
        0.130208333333,0.6,0.2,0.211324865405,
        0.130208333333,0.2,0.6,0.211324865405,
        -0.140625,0.333333333333,0.333333333333,0.788675134595,
        0.130208333333,0.2,0.2,0.788675134595,
        0.130208333333,0.6,0.2,0.788675134595,
        0.130208333333,0.2,0.6,0.788675134595,
        0.0,
        0.04964035326178,0.44594849091596499999,0.44594849091596499999,0.5,
        0.04964035326178,0.44594849091596499999,0.10810301816807000002,0.5,
        0.04964035326178,0.10810301816807000002,0.44594849091596499999,0.5,
        0.024433720812293777778,0.091576213509771,0.091576213509771,0.5,
        0.024433720812293777778,0.091576213509771,0.81684757298045800001,0.5,
        0.024433720812293777778,0.81684757298045800001,0.091576213509771,0.5,
        0.031025220788612500002,0.44594849091596499999,0.44594849091596499999,0.112701665379,
        0.031025220788612500002,0.44594849091596499999,0.10810301816807000002,0.112701665379,
        0.031025220788612500002,0.10810301816807000002,0.44594849091596499999,0.112701665379,
        0.015271075507683611111,0.091576213509771,0.091576213509771,0.112701665379,
        0.015271075507683611111,0.091576213509771,0.81684757298045800001,0.112701665379,
        0.015271075507683611111,0.81684757298045800001,0.091576213509771,0.112701665379,
        0.031025220788612500002,0.44594849091596499999,0.44594849091596499999,0.887298334621,
        0.031025220788612500002,0.44594849091596499999,0.10810301816807000002,0.887298334621,
        0.031025220788612500002,0.10810301816807000002,0.44594849091596499999,0.887298334621,
        0.015271075507683611111,0.091576213509771,0.091576213509771,0.887298334621,
        0.015271075507683611111,0.091576213509771,0.81684757298045800001,0.887298334621,
        0.015271075507683611111,0.81684757298045800001,0.091576213509771,0.887298334621,
        0.0,
        0.05,0.333333333333,0.333333333333,0.5,
        0.0294209228419,0.470142064105,0.470142064105,0.5,
        0.0294209228419,0.470142064105,0.0597158717898,0.5,
        0.0294209228419,0.0597158717898,0.470142064105,0.5,
        0.0279864845655,0.101286507323,0.101286507323,0.5,
        0.0279864845655,0.101286507323,0.797426985353,0.5,
        0.0279864845655,0.797426985353,0.101286507323,0.5,
        0.03125,0.333333333333,0.333333333333,0.112701665379,
        0.0183880767762,0.470142064105,0.470142064105,0.112701665379,
        0.0183880767762,0.470142064105,0.0597158717898,0.112701665379,
        0.0183880767762,0.0597158717898,0.470142064105,0.112701665379,
        0.0174915528534,0.101286507323,0.101286507323,0.112701665379,
        0.0174915528534,0.101286507323,0.797426985353,0.112701665379,
        0.0174915528534,0.797426985353,0.101286507323,0.112701665379,
        0.03125,0.333333333333,0.333333333333,0.887298334621,
        0.0183880767762,0.470142064105,0.470142064105,0.887298334621,
        0.0183880767762,0.470142064105,0.0597158717898,0.887298334621,
        0.0183880767762,0.0597158717898,0.470142064105,0.887298334621,
        0.0174915528534,0.101286507323,0.101286507323,0.887298334621,
        0.0174915528534,0.101286507323,0.797426985353,0.887298334621,
        0.0174915528534,0.797426985353,0.101286507323,0.887298334621,
        0.0,
        0.05,0.333333333333,0.333333333333,0.5,
        0.0294209228419,0.470142064105,0.470142064105,0.5,
        0.0294209228419,0.470142064105,0.0597158717898,0.5,
        0.0294209228419,0.0597158717898,0.470142064105,0.5,
        0.0279864845655,0.101286507323,0.101286507323,0.5,
        0.0279864845655,0.101286507323,0.797426985353,0.5,
        0.0279864845655,0.797426985353,0.101286507323,0.5,
        0.03125,0.333333333333,0.333333333333,0.112701665379,
        0.0183880767762,0.470142064105,0.470142064105,0.112701665379,
        0.0183880767762,0.470142064105,0.0597158717898,0.112701665379,
        0.0183880767762,0.0597158717898,0.470142064105,0.112701665379,
        0.0174915528534,0.101286507323,0.101286507323,0.112701665379,
        0.0174915528534,0.101286507323,0.797426985353,0.112701665379,
        0.0174915528534,0.797426985353,0.101286507323,0.112701665379,
        0.03125,0.333333333333,0.333333333333,0.887298334621,
        0.0183880767762,0.470142064105,0.470142064105,0.887298334621,
        0.0183880767762,0.470142064105,0.0597158717898,0.887298334621,
        0.0183880767762,0.0597158717898,0.470142064105,0.887298334621,
        0.0174915528534,0.101286507323,0.101286507323,0.887298334621,
        0.0174915528534,0.101286507323,0.797426985353,0.887298334621,
        0.0174915528534,0.797426985353,0.101286507323,0.887298334621,
        0.0,
        0.05,0.333333333333,0.333333333333,0.5,
        0.0294209228419,0.470142064105,0.470142064105,0.5,
        0.0294209228419,0.470142064105,0.0597158717898,0.5,
        0.0294209228419,0.0597158717898,0.470142064105,0.5,
        0.0279864845655,0.101286507323,0.101286507323,0.5,
        0.0279864845655,0.101286507323,0.797426985353,0.5,
        0.0279864845655,0.797426985353,0.101286507323,0.5,
        0.03125,0.333333333333,0.333333333333,0.112701665379,
        0.0183880767762,0.470142064105,0.470142064105,0.112701665379,
        0.0183880767762,0.470142064105,0.0597158717898,0.112701665379,
        0.0183880767762,0.0597158717898,0.470142064105,0.112701665379,
        0.0174915528534,0.101286507323,0.101286507323,0.112701665379,
        0.0174915528534,0.101286507323,0.797426985353,0.112701665379,
        0.0174915528534,0.797426985353,0.101286507323,0.112701665379,
        0.03125,0.333333333333,0.333333333333,0.887298334621,
        0.0183880767762,0.470142064105,0.470142064105,0.887298334621,
        0.0183880767762,0.470142064105,0.0597158717898,0.887298334621,
        0.0183880767762,0.0597158717898,0.470142064105,0.887298334621,
        0.0174915528534,0.101286507323,0.101286507323,0.887298334621,
        0.0174915528534,0.101286507323,0.797426985353,0.887298334621,
        0.0174915528534,0.797426985353,0.101286507323,0.887298334621,
        0.0,
        0.05,0.333333333333,0.333333333333,0.5,
        0.0294209228419,0.470142064105,0.470142064105,0.5,
        0.0294209228419,0.470142064105,0.0597158717898,0.5,
        0.0294209228419,0.0597158717898,0.470142064105,0.5,
        0.0279864845655,0.101286507323,0.101286507323,0.5,
        0.0279864845655,0.101286507323,0.797426985353,0.5,
        0.0279864845655,0.797426985353,0.101286507323,0.5,
        0.03125,0.333333333333,0.333333333333,0.112701665379,
        0.0183880767762,0.470142064105,0.470142064105,0.112701665379,
        0.0183880767762,0.470142064105,0.0597158717898,0.112701665379,
        0.0183880767762,0.0597158717898,0.470142064105,0.112701665379,
        0.0174915528534,0.101286507323,0.101286507323,0.112701665379,
        0.0174915528534,0.101286507323,0.797426985353,0.112701665379,
        0.0174915528534,0.797426985353,0.101286507323,0.112701665379,
        0.03125,0.333333333333,0.333333333333,0.887298334621,
        0.0183880767762,0.470142064105,0.470142064105,0.887298334621,
        0.0183880767762,0.470142064105,0.0597158717898,0.887298334621,
        0.0183880767762,0.0597158717898,0.470142064105,0.887298334621,
        0.0174915528534,0.101286507323,0.101286507323,0.887298334621,
        0.0174915528534,0.101286507323,0.797426985353,0.887298334621,
        0.0174915528534,0.797426985353,0.101286507323,0.887298334621,
        0.0,
        0.05,0.333333333333,0.333333333333,0.5,
        0.0294209228419,0.470142064105,0.470142064105,0.5,
        0.0294209228419,0.470142064105,0.0597158717898,0.5,
        0.0294209228419,0.0597158717898,0.470142064105,0.5,
        0.0279864845655,0.101286507323,0.101286507323,0.5,
        0.0279864845655,0.101286507323,0.797426985353,0.5,
        0.0279864845655,0.797426985353,0.101286507323,0.5,
        0.03125,0.333333333333,0.333333333333,0.112701665379,
        0.0183880767762,0.470142064105,0.470142064105,0.112701665379,
        0.0183880767762,0.470142064105,0.0597158717898,0.112701665379,
        0.0183880767762,0.0597158717898,0.470142064105,0.112701665379,
        0.0174915528534,0.101286507323,0.101286507323,0.112701665379,
        0.0174915528534,0.101286507323,0.797426985353,0.112701665379,
        0.0174915528534,0.797426985353,0.101286507323,0.112701665379,
        0.03125,0.333333333333,0.333333333333,0.887298334621,
        0.0183880767762,0.470142064105,0.470142064105,0.887298334621,
        0.0183880767762,0.470142064105,0.0597158717898,0.887298334621,
        0.0183880767762,0.0597158717898,0.470142064105,0.887298334621,
        0.0174915528534,0.101286507323,0.101286507323,0.887298334621,
        0.0174915528534,0.101286507323,0.797426985353,0.887298334621,
        0.0174915528534,0.797426985353,0.101286507323,0.887298334621,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Wedge &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=0.5*nodes[2]->pos[1]; T reg1=0.5*nodes[0]->pos[1]; T reg2=0.5*nodes[1]->pos[2]; T reg3=0.5*nodes[2]->pos[2]; T reg4=0.5*nodes[0]->pos[2];
    T reg5=0.5*nodes[1]->pos[1]; T reg6=reg3-reg4; T reg7=0.5*nodes[3]->pos[2]; T reg8=0.5*nodes[4]->pos[2]; reg3=reg2+reg3;
    T reg9=0.5*nodes[4]->pos[1]; T reg10=0.5*nodes[3]->pos[1]; T reg11=reg0-reg1; reg0=reg0+reg5; reg4=reg2-reg4;
    reg1=reg5-reg1; reg11=reg11-reg10; reg2=0.5*nodes[5]->pos[1]; reg5=0.5*nodes[2]->pos[0]; T reg12=0.5*nodes[0]->pos[0];
    T reg13=0.5*nodes[1]->pos[0]; T reg14=reg8-reg3; T reg15=0.5*nodes[5]->pos[2]; T reg16=reg9-reg0; reg10=reg1-reg10;
    reg4=reg4-reg7; reg7=reg6-reg7; reg1=reg5-reg12; reg4=reg8+reg4; reg16=reg2+reg16;
    reg10=reg9+reg10; reg12=reg13-reg12; reg6=0.5*nodes[3]->pos[0]; reg2=reg11+reg2; reg14=reg14+reg15;
    reg7=reg15+reg7; reg5=reg13+reg5; reg1=reg1-reg6; reg8=0.5*nodes[5]->pos[0]; reg9=0.5*nodes[4]->pos[0];
    reg6=reg12-reg6; reg11=reg7*reg16; reg12=reg14*reg10; reg14=reg2*reg14; reg16=reg16*reg4;
    reg13=reg9-reg5; reg10=reg7*reg10; reg4=reg2*reg4; reg16=reg12-reg16; reg1=reg1+reg8;
    reg9=reg6+reg9; reg11=reg14-reg11; reg4=reg10-reg4; reg13=reg8+reg13; reg16=reg1*reg16;
    reg11=reg9*reg11; reg16=reg11-reg16; reg4=reg13*reg4; T det_jac=reg16+reg4;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1],nodes[3],nodes[5],nodes[4]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[0][0]*reg0; T reg2=reg0*pos_nodes[0][2]; T reg3=var_inter[0]*pos_nodes[1][2];
    T reg4=var_inter[0]*pos_nodes[1][0]; T reg5=pos_nodes[0][1]*reg0; T reg6=var_inter[0]*pos_nodes[1][1]; reg4=reg1+reg4; reg1=var_inter[1]*pos_nodes[2][0];
    T reg7=1-var_inter[2]; T reg8=var_inter[1]*pos_nodes[2][1]; reg6=reg5+reg6; reg5=var_inter[1]*pos_nodes[2][2]; reg3=reg2+reg3;
    reg2=pos_nodes[3][0]*reg0; T reg9=reg7*pos_nodes[2][0]; reg8=reg6+reg8; reg1=reg4+reg1; reg5=reg3+reg5;
    reg3=pos_nodes[3][1]*reg0; reg4=reg7*pos_nodes[2][1]; reg6=pos_nodes[3][2]*reg0; T reg10=pos_nodes[0][1]*reg7; T reg11=reg7*pos_nodes[2][2];
    T reg12=reg7*pos_nodes[0][2]; T reg13=pos_nodes[0][0]*reg7; T reg14=pos_nodes[3][1]*var_inter[2]; T reg15=pos_nodes[3][2]*var_inter[2]; reg4=reg4-reg10;
    reg11=reg11-reg12; T reg16=pos_nodes[4][0]*var_inter[0]; reg1=reg2-reg1; reg8=reg3-reg8; reg2=pos_nodes[4][1]*var_inter[0];
    reg9=reg9-reg13; reg3=pos_nodes[3][0]*var_inter[2]; reg5=reg6-reg5; reg6=pos_nodes[4][2]*var_inter[0]; reg11=reg11-reg15;
    T reg17=pos_nodes[5][2]*var_inter[2]; T reg18=reg7*pos_nodes[1][1]; reg4=reg4-reg14; T reg19=pos_nodes[5][1]*var_inter[2]; reg2=reg8+reg2;
    reg8=pos_nodes[5][1]*var_inter[1]; reg6=reg5+reg6; reg9=reg9-reg3; reg5=pos_nodes[5][0]*var_inter[2]; T reg20=reg0*reg7;
    T reg21=reg7*pos_nodes[1][0]; T reg22=pos_nodes[5][2]*var_inter[1]; T reg23=var_inter[0]*reg7; reg16=reg1+reg16; reg1=pos_nodes[5][0]*var_inter[1];
    T reg24=reg23*pos_nodes[1][1]; T reg25=pos_nodes[0][1]*reg20; reg8=reg2+reg8; reg5=reg9+reg5; reg13=reg21-reg13;
    reg2=var_inter[1]*reg7; reg19=reg4+reg19; reg1=reg16+reg1; reg4=pos_nodes[0][0]*reg20; reg9=reg23*pos_nodes[1][0];
    reg10=reg18-reg10; reg22=reg6+reg22; reg6=reg7*pos_nodes[1][2]; reg17=reg11+reg17; reg11=reg1*reg17;
    reg16=reg19*reg22; reg18=reg5*reg22; reg21=reg8*reg17; T reg26=reg20*pos_nodes[0][2]; T reg27=reg23*pos_nodes[1][2];
    T reg28=reg2*pos_nodes[2][1]; reg3=reg13-reg3; reg13=pos_nodes[4][0]*var_inter[2]; reg9=reg4+reg9; reg4=reg2*pos_nodes[2][0];
    T reg29=var_inter[2]*reg0; reg12=reg6-reg12; reg14=reg10-reg14; reg6=pos_nodes[4][1]*var_inter[2]; reg24=reg25+reg24;
    reg10=var_inter[0]*var_inter[2]; reg28=reg24+reg28; reg13=reg3+reg13; reg3=pos_nodes[3][1]*reg29; reg4=reg9+reg4;
    reg9=pos_nodes[3][0]*reg29; reg24=reg1*reg19; reg11=reg18-reg11; reg27=reg26+reg27; reg25=reg2*pos_nodes[2][2];
    reg26=reg5*reg8; T reg30=pos_nodes[4][2]*var_inter[2]; reg15=reg12-reg15; reg6=reg14+reg6; reg21=reg16-reg21;
    reg25=reg27+reg25; reg12=pos_nodes[3][2]*reg29; reg14=reg6*reg11; reg24=reg26-reg24; reg27=reg13*reg21;
    T reg31=var_inter[1]*var_inter[2]; reg9=reg4+reg9; reg4=pos_nodes[4][0]*reg10; reg3=reg28+reg3; reg28=pos_nodes[4][1]*reg10;
    reg30=reg15+reg30; reg15=reg6*reg17; T reg32=reg8*reg30; T reg33=reg6*reg22; T reg34=reg19*reg30;
    T reg35=reg30*reg24; reg27=reg14-reg27; reg28=reg3+reg28; reg3=pos_nodes[5][1]*reg31; reg14=reg13*reg22;
    T reg36=reg1*reg30; T reg37=reg13*reg17; T reg38=reg5*reg30; T reg39=pos_nodes[4][2]*reg10; reg12=reg25+reg12;
    reg25=pos_nodes[5][0]*reg31; reg4=reg9+reg4; reg36=reg14-reg36; reg34=reg15-reg34; reg38=reg37-reg38;
    reg9=reg13*reg8; T reg40=reg1*reg6; T reg41=reg13*reg19; reg32=reg33-reg32; T reg42=reg5*reg6;
    reg25=reg4+reg25; reg39=reg12+reg39; reg4=pos_nodes[5][2]*reg31; reg3=reg28+reg3; reg35=reg27-reg35;
    reg11=reg11/reg35; reg34=reg34/reg35; reg36=reg36/reg35; reg3=pos[1]-reg3; reg42=reg41-reg42;
    reg4=reg39+reg4; reg38=reg38/reg35; reg21=reg21/reg35; reg32=reg32/reg35; reg25=pos[0]-reg25;
    reg40=reg9-reg40; reg11=reg3*reg11; reg32=reg25*reg32; reg36=reg3*reg36; reg34=reg25*reg34;
    reg38=reg3*reg38; reg21=reg25*reg21; reg42=reg42/reg35; reg40=reg40/reg35; reg35=reg24/reg35;
    reg4=pos[2]-reg4; reg35=reg4*reg35; reg21=reg11-reg21; reg40=reg4*reg40; reg36=reg32-reg36;
    reg42=reg4*reg42; reg34=reg38-reg34; var_inter[0]=reg21-reg35; var_inter[1]=reg40+reg36; var_inter[2]=reg34-reg42;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=var_inter[0]*pos_nodes[1][2]; T reg2=var_inter[0]*pos_nodes[1][0]; T reg3=pos_nodes[0][0]*reg0;
    T reg4=reg0*pos_nodes[0][2]; T reg5=var_inter[0]*pos_nodes[1][1]; T reg6=reg0*pos_nodes[0][1]; T reg7=var_inter[1]*pos_nodes[2][2]; reg1=reg4+reg1;
    reg4=var_inter[1]*pos_nodes[2][0]; reg2=reg3+reg2; reg3=1-var_inter[2]; reg5=reg6+reg5; reg6=var_inter[1]*pos_nodes[2][1];
    T reg8=reg0*pos_nodes[3][0]; reg4=reg2+reg4; reg7=reg1+reg7; reg1=reg3*pos_nodes[2][0]; reg2=reg0*pos_nodes[3][2];
    T reg9=reg3*pos_nodes[0][1]; T reg10=reg3*pos_nodes[2][2]; T reg11=reg3*pos_nodes[2][1]; reg6=reg5+reg6; reg5=reg3*pos_nodes[0][2];
    T reg12=reg0*pos_nodes[3][1]; T reg13=pos_nodes[0][0]*reg3; T reg14=var_inter[2]*pos_nodes[3][1]; reg10=reg10-reg5; reg7=reg2-reg7;
    reg11=reg11-reg9; reg2=var_inter[0]*pos_nodes[4][2]; T reg15=var_inter[2]*pos_nodes[3][2]; T reg16=var_inter[0]*pos_nodes[4][0]; reg4=reg8-reg4;
    reg8=var_inter[2]*pos_nodes[3][0]; reg6=reg12-reg6; reg12=var_inter[0]*pos_nodes[4][1]; reg1=reg1-reg13; T reg17=reg3*var_inter[0];
    T reg18=var_inter[2]*pos_nodes[5][1]; reg11=reg11-reg14; reg12=reg6+reg12; reg10=reg10-reg15; reg6=var_inter[1]*pos_nodes[5][1];
    T reg19=reg3*pos_nodes[1][1]; T reg20=var_inter[2]*pos_nodes[5][2]; reg2=reg7+reg2; reg7=var_inter[1]*pos_nodes[5][2]; reg1=reg1-reg8;
    T reg21=var_inter[2]*pos_nodes[5][0]; reg16=reg4+reg16; reg4=var_inter[1]*pos_nodes[5][0]; T reg22=reg3*pos_nodes[1][0]; T reg23=reg0*reg3;
    reg20=reg10+reg20; reg10=reg17*pos_nodes[1][1]; T reg24=reg23*pos_nodes[0][1]; reg6=reg12+reg6; reg9=reg19-reg9;
    reg21=reg1+reg21; reg7=reg2+reg7; reg13=reg22-reg13; reg1=reg3*var_inter[1]; reg18=reg11+reg18;
    reg4=reg16+reg4; reg2=pos_nodes[0][0]*reg23; reg11=reg17*pos_nodes[1][0]; reg12=reg3*pos_nodes[1][2]; reg16=reg23*pos_nodes[0][2];
    reg19=reg4*reg20; reg22=reg21*reg7; T reg25=reg18*reg7; T reg26=reg17*pos_nodes[1][2]; reg5=reg12-reg5;
    reg12=reg6*reg20; reg8=reg13-reg8; reg13=var_inter[2]*pos_nodes[4][0]; reg11=reg2+reg11; reg2=pos_nodes[2][0]*reg1;
    reg14=reg9-reg14; reg9=var_inter[2]*pos_nodes[4][1]; T reg27=reg0*var_inter[2]; reg10=reg24+reg10; reg24=pos_nodes[2][1]*reg1;
    reg24=reg10+reg24; reg13=reg8+reg13; reg8=pos_nodes[3][0]*reg27; reg10=reg4*reg18; reg19=reg22-reg19;
    reg2=reg11+reg2; reg11=pos_nodes[3][1]*reg27; reg26=reg16+reg26; reg16=pos_nodes[2][2]*reg1; reg12=reg25-reg12;
    T reg28=var_inter[0]*var_inter[2]; reg9=reg14+reg9; reg14=reg21*reg6; T reg29=var_inter[2]*pos_nodes[4][2]; reg15=reg5-reg15;
    reg16=reg26+reg16; reg5=reg13*reg12; reg26=reg9*reg19; reg10=reg14-reg10; T reg30=var_inter[1]*var_inter[2];
    T reg31=pos_nodes[3][2]*reg27; reg2=reg8+reg2; reg8=reg28*pos_nodes[4][0]; reg24=reg11+reg24; reg11=reg28*pos_nodes[4][1];
    reg29=reg15+reg29; reg15=reg9*reg20; T reg32=reg6*reg29; T reg33=reg9*reg7; T reg34=reg18*reg29;
    T reg35=reg29*reg10; reg5=reg26-reg5; reg11=reg24+reg11; reg24=reg30*pos_nodes[5][1]; reg26=reg13*reg7;
    T reg36=reg4*reg29; T reg37=reg13*reg20; T reg38=reg21*reg29; T reg39=reg28*pos_nodes[4][2]; reg16=reg31+reg16;
    reg31=reg30*pos_nodes[5][0]; reg8=reg2+reg8; reg36=reg26-reg36; reg34=reg15-reg34; reg38=reg37-reg38;
    reg2=reg13*reg6; T reg40=reg4*reg9; T reg41=reg13*reg18; reg32=reg33-reg32; T reg42=reg21*reg9;
    reg39=reg16+reg39; reg16=reg30*pos_nodes[5][2]; reg31=reg8+reg31; reg24=reg11+reg24; reg35=reg5-reg35;
    reg24=pos[1]-reg24; reg19=reg19/reg35; reg31=pos[0]-reg31; reg36=reg36/reg35; reg34=reg34/reg35;
    reg12=reg12/reg35; reg42=reg41-reg42; reg38=reg38/reg35; reg16=reg39+reg16; reg32=reg32/reg35;
    reg40=reg2-reg40; reg19=reg24*reg19; reg32=reg31*reg32; reg36=reg24*reg36; reg34=reg31*reg34;
    reg38=reg24*reg38; reg12=reg31*reg12; reg42=reg42/reg35; reg40=reg40/reg35; reg16=pos[2]-reg16;
    reg35=reg10/reg35; reg35=reg16*reg35; reg12=reg19-reg12; reg40=reg16*reg40; reg36=reg32-reg36;
    reg42=reg16*reg42; reg34=reg38-reg34; var_inter[0]+=reg12-reg35; var_inter[1]+=reg40+reg36; var_inter[2]+=reg34-reg42;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=1-var_inter[2]; T reg2=var_inter[0]*reg1; T reg3=reg0*reg1;
    reg2=val[1]*reg2; reg3=val[0]*reg3; T reg4=var_inter[1]*reg1; reg4=val[2]*reg4; reg0=var_inter[2]*reg0;
    reg2=reg3+reg2; reg0=val[3]*reg0; reg3=var_inter[0]*var_inter[2]; reg4=reg2+reg4; reg3=val[4]*reg3;
    reg2=var_inter[1]*var_inter[2]; reg0=reg4+reg0; reg3=reg0+reg3; reg2=val[5]*reg2; res=reg3+reg2;

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
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; T reg2=var_inter[2]-0.21132486540518707896; reg2=reg2/0.57735026918962573106; T reg3=reg1+reg0;
    T reg4=1-var_inter[2]; reg2=1-reg2; reg1=1-reg1; T reg5=reg4-0.21132486540518707896; reg3=reg3-1;
    T reg6=reg1*reg2; T reg7=reg2*reg3; reg0=1-reg0; reg5=reg5/0.57735026918962573106; reg2=reg2*reg0;
    reg5=1-reg5; reg7=val[1]*reg7; reg6=val[0]*reg6; reg7=reg6+reg7; reg2=val[2]*reg2;
    reg6=reg1*reg5; reg6=val[3]*reg6; T reg8=reg3*reg5; reg2=reg7+reg2; reg8=val[4]*reg8;
    reg5=reg0*reg5; reg6=reg2+reg6; reg8=reg6+reg8; reg5=val[5]*reg5; res=reg8+reg5;

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[1]; T reg1=2*var_inter[0]; T reg2=reg0+reg1; reg1=1-reg1; reg2=reg2-1;
    reg0=1-reg0; T reg3=val[0]*reg2; T reg4=val[1]*reg1; reg4=reg3+reg4; reg3=val[2]*reg0;
    res=reg4+reg3;

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
