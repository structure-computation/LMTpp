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
    T reg5=0.5*nodes[1]->pos[1]; T reg6=reg3-reg4; T reg7=0.5*nodes[4]->pos[2]; reg3=reg2+reg3; T reg8=0.5*nodes[3]->pos[2];
    T reg9=0.5*nodes[4]->pos[1]; T reg10=0.5*nodes[3]->pos[1]; T reg11=reg0-reg1; reg0=reg0+reg5; reg4=reg2-reg4;
    reg1=reg5-reg1; reg11=reg11-reg10; reg2=0.5*nodes[5]->pos[1]; reg5=0.5*nodes[2]->pos[0]; T reg12=0.5*nodes[0]->pos[0];
    T reg13=0.5*nodes[1]->pos[0]; T reg14=reg7-reg3; T reg15=0.5*nodes[5]->pos[2]; T reg16=reg9-reg0; reg4=reg4-reg8;
    reg10=reg1-reg10; reg8=reg6-reg8; reg1=reg5-reg12; reg4=reg7+reg4; reg16=reg2+reg16;
    reg10=reg9+reg10; reg12=reg13-reg12; reg6=0.5*nodes[3]->pos[0]; reg2=reg11+reg2; reg14=reg14+reg15;
    reg8=reg15+reg8; reg5=reg13+reg5; reg1=reg1-reg6; reg7=0.5*nodes[5]->pos[0]; reg9=0.5*nodes[4]->pos[0];
    reg6=reg12-reg6; reg11=reg8*reg16; reg12=reg14*reg10; reg14=reg2*reg14; reg16=reg16*reg4;
    reg13=reg9-reg5; reg10=reg8*reg10; reg4=reg2*reg4; reg16=reg12-reg16; reg1=reg1+reg7;
    reg9=reg6+reg9; reg11=reg14-reg11; reg4=reg10-reg4; reg13=reg7+reg13; reg16=reg1*reg16;
    reg11=reg9*reg11; reg16=reg11-reg16; reg4=reg13*reg4; T det_jac=reg16+reg4;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1],nodes[3],nodes[5],nodes[4]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=var_inter[0]*pos_nodes[1][2]; T reg2=pos_nodes[0][2]*reg0; T reg3=pos_nodes[1][1]*var_inter[0];
    T reg4=pos_nodes[0][1]*reg0; T reg5=pos_nodes[1][0]*var_inter[0]; T reg6=pos_nodes[0][0]*reg0; T reg7=1-var_inter[2]; T reg8=var_inter[1]*pos_nodes[2][1];
    reg3=reg4+reg3; reg4=var_inter[1]*pos_nodes[2][2]; reg1=reg2+reg1; reg5=reg6+reg5; reg2=var_inter[0]*reg7;
    reg6=reg0*reg7; T reg9=var_inter[1]*pos_nodes[2][0]; reg8=reg3+reg8; reg3=pos_nodes[3][1]*reg0; T reg10=pos_nodes[2][1]*reg7;
    T reg11=pos_nodes[0][1]*reg7; T reg12=pos_nodes[0][0]*reg7; T reg13=var_inter[1]*reg7; T reg14=pos_nodes[0][0]*reg6; T reg15=pos_nodes[1][0]*reg2;
    T reg16=pos_nodes[3][0]*reg0; reg4=reg1+reg4; reg1=pos_nodes[3][2]*reg0; T reg17=pos_nodes[2][2]*reg7; T reg18=pos_nodes[0][2]*reg7;
    T reg19=pos_nodes[1][1]*reg2; reg9=reg5+reg9; reg5=pos_nodes[0][1]*reg6; T reg20=pos_nodes[2][0]*reg7; reg15=reg14+reg15;
    reg14=pos_nodes[2][0]*reg13; T reg21=var_inter[0]*pos_nodes[4][2]; reg4=reg1-reg4; reg1=var_inter[0]*pos_nodes[4][1]; T reg22=pos_nodes[0][2]*reg6;
    T reg23=pos_nodes[1][2]*reg2; reg8=reg3-reg8; reg3=var_inter[2]*reg0; reg17=reg17-reg18; T reg24=var_inter[2]*pos_nodes[3][2];
    reg20=reg20-reg12; T reg25=var_inter[2]*pos_nodes[3][1]; T reg26=pos_nodes[2][1]*reg13; reg10=reg10-reg11; T reg27=var_inter[2]*pos_nodes[3][0];
    reg19=reg5+reg19; reg5=var_inter[0]*pos_nodes[4][0]; reg9=reg16-reg9; reg5=reg9+reg5; reg9=var_inter[1]*pos_nodes[5][0];
    reg16=var_inter[0]*var_inter[2]; reg14=reg15+reg14; reg15=pos_nodes[3][0]*reg3; T reg28=pos_nodes[1][1]*reg7; reg10=reg10-reg25;
    T reg29=var_inter[2]*pos_nodes[5][1]; T reg30=pos_nodes[2][2]*reg13; reg23=reg22+reg23; reg1=reg8+reg1; reg8=var_inter[1]*pos_nodes[5][1];
    reg26=reg19+reg26; reg19=pos_nodes[3][1]*reg3; reg17=reg17-reg24; reg22=var_inter[2]*pos_nodes[5][2]; reg21=reg4+reg21;
    reg4=var_inter[1]*pos_nodes[5][2]; T reg31=var_inter[2]*pos_nodes[5][0]; reg20=reg20-reg27; T reg32=pos_nodes[1][0]*reg7; reg8=reg1+reg8;
    reg19=reg26+reg19; reg1=pos_nodes[4][1]*reg16; reg26=pos_nodes[1][2]*reg7; reg29=reg10+reg29; reg22=reg17+reg22;
    reg4=reg21+reg4; reg30=reg23+reg30; reg10=pos_nodes[3][2]*reg3; reg11=reg28-reg11; reg17=pos_nodes[4][0]*reg16;
    reg15=reg14+reg15; reg31=reg20+reg31; reg14=var_inter[1]*var_inter[2]; reg12=reg32-reg12; reg9=reg5+reg9;
    reg18=reg26-reg18; reg27=reg12-reg27; reg5=pos_nodes[5][1]*reg14; reg12=reg31*reg4; reg20=reg9*reg22;
    reg21=var_inter[2]*pos_nodes[4][1]; reg25=reg11-reg25; reg10=reg30+reg10; reg1=reg19+reg1; reg11=pos_nodes[4][2]*reg16;
    reg19=var_inter[2]*pos_nodes[4][0]; reg23=reg8*reg22; reg26=reg29*reg4; reg28=pos_nodes[5][0]*reg14; reg17=reg15+reg17;
    reg5=reg1+reg5; reg24=reg18-reg24; reg1=var_inter[2]*pos_nodes[4][2]; reg23=reg26-reg23; reg15=reg9*reg29;
    reg20=reg12-reg20; reg11=reg10+reg11; reg10=pos_nodes[5][2]*reg14; reg18=reg31*reg8; reg28=reg17+reg28;
    reg21=reg25+reg21; reg19=reg27+reg19; reg17=var_inter[0]*reg19; reg15=reg18-reg15; reg10=reg11+reg10;
    reg1=reg24+reg1; reg11=var_inter[0]*reg21; reg24=reg20*reg21; reg5=pos[1]-reg5; reg25=reg23*reg19;
    reg28=pos[0]-reg28; reg10=pos[2]-reg10; reg27=reg21*reg4; reg30=reg8*reg1; reg32=reg21*reg22;
    T reg33=var_inter[1]*reg31; T reg34=reg29*reg1; reg17=reg28+reg17; reg28=reg15*reg1; T reg35=reg19*reg22;
    T reg36=reg31*reg1; T reg37=var_inter[0]*reg1; T reg38=var_inter[1]*reg29; reg25=reg24-reg25; reg11=reg5+reg11;
    reg5=reg19*reg4; reg24=reg9*reg1; T reg39=var_inter[1]*reg22; reg37=reg10+reg37; reg11=reg38+reg11;
    reg10=var_inter[2]*reg9; reg28=reg25-reg28; reg30=reg27-reg30; reg34=reg32-reg34; reg25=var_inter[2]*reg8;
    reg17=reg33+reg17; reg24=reg5-reg24; reg36=reg35-reg36; reg33=reg19*reg8; reg38=reg9*reg21;
    T reg40=reg19*reg29; T reg41=reg31*reg21; reg17=reg10+reg17; reg10=var_inter[2]*reg4; reg11=reg25+reg11;
    reg23=reg23/reg28; reg30=reg30/reg28; reg34=reg34/reg28; reg24=reg24/reg28; reg37=reg39+reg37;
    reg36=reg36/reg28; reg20=reg20/reg28; reg41=reg40-reg41; reg38=reg33-reg38; reg37=reg10+reg37;
    reg41=reg41/reg28; reg38=reg38/reg28; reg23=reg23*reg17; reg20=reg20*reg11; reg30=reg30*reg17;
    reg24=reg24*reg11; reg28=reg15/reg28; reg34=reg34*reg17; reg36=reg36*reg11; reg24=reg30-reg24;
    reg38=reg37*reg38; reg23=reg20-reg23; reg41=reg37*reg41; reg28=reg37*reg28; reg34=reg36-reg34;
    var_inter[1]=reg38+reg24; var_inter[0]=reg23-reg28; var_inter[2]=reg34-reg41;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=var_inter[0]*pos_nodes[1][2]; T reg2=pos_nodes[0][2]*reg0; T reg3=1-var_inter[2];
    T reg4=var_inter[0]*pos_nodes[1][1]; T reg5=pos_nodes[0][1]*reg0; T reg6=reg0*pos_nodes[0][0]; T reg7=var_inter[0]*pos_nodes[1][0]; reg7=reg6+reg7;
    reg6=var_inter[1]*pos_nodes[2][0]; reg4=reg5+reg4; reg5=var_inter[1]*pos_nodes[2][1]; T reg8=var_inter[0]*reg3; T reg9=reg0*reg3;
    T reg10=var_inter[1]*pos_nodes[2][2]; reg1=reg2+reg1; reg5=reg4+reg5; reg2=pos_nodes[0][1]*reg9; reg10=reg1+reg10;
    reg1=pos_nodes[1][1]*reg8; reg4=pos_nodes[0][2]*reg3; T reg11=var_inter[1]*reg3; T reg12=pos_nodes[2][2]*reg3; T reg13=pos_nodes[3][2]*reg0;
    T reg14=pos_nodes[3][1]*reg0; T reg15=pos_nodes[2][1]*reg3; T reg16=pos_nodes[0][1]*reg3; T reg17=pos_nodes[1][0]*reg8; T reg18=reg9*pos_nodes[0][0];
    T reg19=pos_nodes[2][0]*reg3; T reg20=pos_nodes[3][0]*reg0; reg6=reg7+reg6; reg7=reg3*pos_nodes[0][0]; T reg21=pos_nodes[2][1]*reg11;
    reg19=reg19-reg7; T reg22=pos_nodes[1][2]*reg8; reg5=reg14-reg5; reg14=var_inter[0]*pos_nodes[4][1]; T reg23=var_inter[0]*pos_nodes[4][2];
    reg1=reg2+reg1; reg10=reg13-reg10; reg15=reg15-reg16; reg6=reg20-reg6; reg2=pos_nodes[0][2]*reg9;
    reg12=reg12-reg4; reg17=reg18+reg17; reg13=pos_nodes[2][0]*reg11; reg18=var_inter[2]*pos_nodes[3][2]; reg20=var_inter[2]*pos_nodes[3][0];
    T reg24=var_inter[2]*reg0; T reg25=var_inter[0]*pos_nodes[4][0]; T reg26=var_inter[2]*pos_nodes[3][1]; reg23=reg10+reg23; reg10=pos_nodes[3][1]*reg24;
    reg21=reg1+reg21; reg1=pos_nodes[1][0]*reg3; T reg27=var_inter[2]*pos_nodes[5][2]; reg12=reg12-reg18; T reg28=var_inter[1]*pos_nodes[5][2];
    T reg29=var_inter[1]*pos_nodes[5][1]; reg14=reg5+reg14; reg19=reg19-reg20; reg5=var_inter[2]*pos_nodes[5][0]; reg22=reg2+reg22;
    reg2=pos_nodes[2][2]*reg11; T reg30=var_inter[2]*pos_nodes[5][1]; reg15=reg15-reg26; T reg31=var_inter[1]*pos_nodes[5][0]; reg25=reg6+reg25;
    reg6=pos_nodes[1][1]*reg3; T reg32=var_inter[0]*var_inter[2]; T reg33=pos_nodes[3][0]*reg24; reg13=reg17+reg13; reg17=var_inter[1]*var_inter[2];
    reg27=reg12+reg27; reg12=pos_nodes[3][2]*reg24; reg2=reg22+reg2; reg28=reg23+reg28; reg31=reg25+reg31;
    reg33=reg13+reg33; reg13=pos_nodes[4][0]*reg32; reg16=reg6-reg16; reg30=reg15+reg30; reg5=reg19+reg5;
    reg29=reg14+reg29; reg10=reg21+reg10; reg6=pos_nodes[4][1]*reg32; reg7=reg1-reg7; reg1=pos_nodes[1][2]*reg3;
    reg14=reg30*reg28; reg15=reg29*reg27; reg19=reg5*reg28; reg21=reg31*reg27; reg26=reg16-reg26;
    reg16=pos_nodes[5][0]*reg17; reg13=reg33+reg13; reg22=pos_nodes[4][2]*reg32; reg12=reg2+reg12; reg2=var_inter[2]*pos_nodes[4][1];
    reg4=reg1-reg4; reg6=reg10+reg6; reg1=pos_nodes[5][1]*reg17; reg10=var_inter[2]*pos_nodes[4][0]; reg20=reg7-reg20;
    reg15=reg14-reg15; reg7=reg5*reg29; reg1=reg6+reg1; reg21=reg19-reg21; reg6=reg31*reg30;
    reg18=reg4-reg18; reg16=reg13+reg16; reg4=var_inter[2]*pos_nodes[4][2]; reg13=pos_nodes[5][2]*reg17; reg22=reg12+reg22;
    reg10=reg20+reg10; reg2=reg26+reg2; reg6=reg7-reg6; reg16=pos[0]-reg16; reg12=reg2*reg21;
    reg4=reg18+reg4; reg18=reg10*reg15; reg1=pos[1]-reg1; reg13=reg22+reg13; reg20=var_inter[0]*reg2;
    reg22=var_inter[0]*reg10; reg23=reg5*reg4; reg25=reg10*reg27; reg26=reg31*reg4; reg33=reg10*reg28;
    reg22=reg16+reg22; reg16=reg30*reg4; T reg34=var_inter[1]*reg5; T reg35=reg2*reg27; T reg36=reg29*reg4;
    T reg37=reg2*reg28; T reg38=reg4*reg6; reg18=reg12-reg18; reg12=var_inter[1]*reg30; reg20=reg1+reg20;
    reg13=pos[2]-reg13; reg1=var_inter[0]*reg4; T reg39=reg10*reg30; T reg40=reg31*reg2; T reg41=reg10*reg29;
    T reg42=reg5*reg2; reg23=reg25-reg23; reg1=reg13+reg1; reg13=var_inter[1]*reg27; reg26=reg33-reg26;
    reg22=reg34+reg22; reg34=var_inter[2]*reg29; reg20=reg12+reg20; reg16=reg35-reg16; reg36=reg37-reg36;
    reg12=var_inter[2]*reg31; reg38=reg18-reg38; reg42=reg39-reg42; reg1=reg13+reg1; reg20=reg34+reg20;
    reg13=var_inter[2]*reg28; reg22=reg12+reg22; reg15=reg15/reg38; reg36=reg36/reg38; reg16=reg16/reg38;
    reg21=reg21/reg38; reg26=reg26/reg38; reg40=reg41-reg40; reg23=reg23/reg38; reg1=reg13+reg1;
    reg40=reg40/reg38; reg42=reg42/reg38; reg38=reg6/reg38; reg15=reg22*reg15; reg21=reg20*reg21;
    reg23=reg20*reg23; reg16=reg22*reg16; reg26=reg20*reg26; reg36=reg22*reg36; reg16=reg23-reg16;
    reg15=reg21-reg15; reg42=reg1*reg42; reg38=reg1*reg38; reg26=reg36-reg26; reg40=reg1*reg40;
    var_inter[2]+=reg16-reg42; var_inter[1]+=reg40+reg26; var_inter[0]+=reg15-reg38;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    reg3=val[0]*reg3; reg2=val[1]*reg2; reg1=var_inter[1]*reg1; reg0=var_inter[2]*reg0; reg1=val[2]*reg1;
    reg2=reg3+reg2; reg1=reg2+reg1; reg0=val[3]*reg0; reg2=var_inter[0]*var_inter[2]; reg0=reg1+reg0;
    reg2=val[4]*reg2; reg1=var_inter[1]*var_inter[2]; reg2=reg0+reg2; reg1=val[5]*reg1; res=reg2+reg1;

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

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
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Wedge> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

}
#endif // LMT_WEDGE
