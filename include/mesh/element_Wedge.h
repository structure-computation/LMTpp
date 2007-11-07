#ifndef LMT_WEDGE
#define LMT_WEDGE
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Wedge &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 25, 50, 75, 108, 181, 266, 351, 436, 521, }; // fonction de lordre du poly
    static const double values[] = {
        0.0833333333333,0.0,0.211324865405,0.5,
        0.0833333333333,0.5,0.211324865405,0.5,
        0.0833333333333,0.5,0.211324865405,0.0,
        0.0833333333333,0.0,0.788675134595,0.5,
        0.0833333333333,0.5,0.788675134595,0.5,
        0.0833333333333,0.5,0.788675134595,0.0,
        0.0,
        0.0833333333333,0.0,0.211324865405,0.5,
        0.0833333333333,0.5,0.211324865405,0.5,
        0.0833333333333,0.5,0.211324865405,0.0,
        0.0833333333333,0.0,0.788675134595,0.5,
        0.0833333333333,0.5,0.788675134595,0.5,
        0.0833333333333,0.5,0.788675134595,0.0,
        0.0,
        0.0833333333333,0.0,0.211324865405,0.5,
        0.0833333333333,0.5,0.211324865405,0.5,
        0.0833333333333,0.5,0.211324865405,0.0,
        0.0833333333333,0.0,0.788675134595,0.5,
        0.0833333333333,0.5,0.788675134595,0.5,
        0.0833333333333,0.5,0.788675134595,0.0,
        0.0,
        -0.140625,0.333333333333,0.211324865405,0.333333333333,
        0.130208333333,0.2,0.211324865405,0.2,
        0.130208333333,0.6,0.211324865405,0.2,
        0.130208333333,0.2,0.211324865405,0.6,
        -0.140625,0.333333333333,0.788675134595,0.333333333333,
        0.130208333333,0.2,0.788675134595,0.2,
        0.130208333333,0.6,0.788675134595,0.2,
        0.130208333333,0.2,0.788675134595,0.6,
        0.0,
        0.04964035326178,0.44594849091596499999,0.5,0.44594849091596499999,
        0.04964035326178,0.44594849091596499999,0.5,0.10810301816807000002,
        0.04964035326178,0.10810301816807000002,0.5,0.44594849091596499999,
        0.024433720812293777778,0.091576213509771,0.5,0.091576213509771,
        0.024433720812293777778,0.091576213509771,0.5,0.81684757298045800001,
        0.024433720812293777778,0.81684757298045800001,0.5,0.091576213509771,
        0.031025220788612500002,0.44594849091596499999,0.112701665379,0.44594849091596499999,
        0.031025220788612500002,0.44594849091596499999,0.112701665379,0.10810301816807000002,
        0.031025220788612500002,0.10810301816807000002,0.112701665379,0.44594849091596499999,
        0.015271075507683611111,0.091576213509771,0.112701665379,0.091576213509771,
        0.015271075507683611111,0.091576213509771,0.112701665379,0.81684757298045800001,
        0.015271075507683611111,0.81684757298045800001,0.112701665379,0.091576213509771,
        0.031025220788612500002,0.44594849091596499999,0.887298334621,0.44594849091596499999,
        0.031025220788612500002,0.44594849091596499999,0.887298334621,0.10810301816807000002,
        0.031025220788612500002,0.10810301816807000002,0.887298334621,0.44594849091596499999,
        0.015271075507683611111,0.091576213509771,0.887298334621,0.091576213509771,
        0.015271075507683611111,0.091576213509771,0.887298334621,0.81684757298045800001,
        0.015271075507683611111,0.81684757298045800001,0.887298334621,0.091576213509771,
        0.0,
        0.05,0.333333333333,0.5,0.333333333333,
        0.0294209228419,0.470142064105,0.5,0.470142064105,
        0.0294209228419,0.470142064105,0.5,0.0597158717898,
        0.0294209228419,0.0597158717898,0.5,0.470142064105,
        0.0279864845655,0.101286507323,0.5,0.101286507323,
        0.0279864845655,0.101286507323,0.5,0.797426985353,
        0.0279864845655,0.797426985353,0.5,0.101286507323,
        0.03125,0.333333333333,0.112701665379,0.333333333333,
        0.0183880767762,0.470142064105,0.112701665379,0.470142064105,
        0.0183880767762,0.470142064105,0.112701665379,0.0597158717898,
        0.0183880767762,0.0597158717898,0.112701665379,0.470142064105,
        0.0174915528534,0.101286507323,0.112701665379,0.101286507323,
        0.0174915528534,0.101286507323,0.112701665379,0.797426985353,
        0.0174915528534,0.797426985353,0.112701665379,0.101286507323,
        0.03125,0.333333333333,0.887298334621,0.333333333333,
        0.0183880767762,0.470142064105,0.887298334621,0.470142064105,
        0.0183880767762,0.470142064105,0.887298334621,0.0597158717898,
        0.0183880767762,0.0597158717898,0.887298334621,0.470142064105,
        0.0174915528534,0.101286507323,0.887298334621,0.101286507323,
        0.0174915528534,0.101286507323,0.887298334621,0.797426985353,
        0.0174915528534,0.797426985353,0.887298334621,0.101286507323,
        0.0,
        0.05,0.333333333333,0.5,0.333333333333,
        0.0294209228419,0.470142064105,0.5,0.470142064105,
        0.0294209228419,0.470142064105,0.5,0.0597158717898,
        0.0294209228419,0.0597158717898,0.5,0.470142064105,
        0.0279864845655,0.101286507323,0.5,0.101286507323,
        0.0279864845655,0.101286507323,0.5,0.797426985353,
        0.0279864845655,0.797426985353,0.5,0.101286507323,
        0.03125,0.333333333333,0.112701665379,0.333333333333,
        0.0183880767762,0.470142064105,0.112701665379,0.470142064105,
        0.0183880767762,0.470142064105,0.112701665379,0.0597158717898,
        0.0183880767762,0.0597158717898,0.112701665379,0.470142064105,
        0.0174915528534,0.101286507323,0.112701665379,0.101286507323,
        0.0174915528534,0.101286507323,0.112701665379,0.797426985353,
        0.0174915528534,0.797426985353,0.112701665379,0.101286507323,
        0.03125,0.333333333333,0.887298334621,0.333333333333,
        0.0183880767762,0.470142064105,0.887298334621,0.470142064105,
        0.0183880767762,0.470142064105,0.887298334621,0.0597158717898,
        0.0183880767762,0.0597158717898,0.887298334621,0.470142064105,
        0.0174915528534,0.101286507323,0.887298334621,0.101286507323,
        0.0174915528534,0.101286507323,0.887298334621,0.797426985353,
        0.0174915528534,0.797426985353,0.887298334621,0.101286507323,
        0.0,
        0.05,0.333333333333,0.5,0.333333333333,
        0.0294209228419,0.470142064105,0.5,0.470142064105,
        0.0294209228419,0.470142064105,0.5,0.0597158717898,
        0.0294209228419,0.0597158717898,0.5,0.470142064105,
        0.0279864845655,0.101286507323,0.5,0.101286507323,
        0.0279864845655,0.101286507323,0.5,0.797426985353,
        0.0279864845655,0.797426985353,0.5,0.101286507323,
        0.03125,0.333333333333,0.112701665379,0.333333333333,
        0.0183880767762,0.470142064105,0.112701665379,0.470142064105,
        0.0183880767762,0.470142064105,0.112701665379,0.0597158717898,
        0.0183880767762,0.0597158717898,0.112701665379,0.470142064105,
        0.0174915528534,0.101286507323,0.112701665379,0.101286507323,
        0.0174915528534,0.101286507323,0.112701665379,0.797426985353,
        0.0174915528534,0.797426985353,0.112701665379,0.101286507323,
        0.03125,0.333333333333,0.887298334621,0.333333333333,
        0.0183880767762,0.470142064105,0.887298334621,0.470142064105,
        0.0183880767762,0.470142064105,0.887298334621,0.0597158717898,
        0.0183880767762,0.0597158717898,0.887298334621,0.470142064105,
        0.0174915528534,0.101286507323,0.887298334621,0.101286507323,
        0.0174915528534,0.101286507323,0.887298334621,0.797426985353,
        0.0174915528534,0.797426985353,0.887298334621,0.101286507323,
        0.0,
        0.05,0.333333333333,0.5,0.333333333333,
        0.0294209228419,0.470142064105,0.5,0.470142064105,
        0.0294209228419,0.470142064105,0.5,0.0597158717898,
        0.0294209228419,0.0597158717898,0.5,0.470142064105,
        0.0279864845655,0.101286507323,0.5,0.101286507323,
        0.0279864845655,0.101286507323,0.5,0.797426985353,
        0.0279864845655,0.797426985353,0.5,0.101286507323,
        0.03125,0.333333333333,0.112701665379,0.333333333333,
        0.0183880767762,0.470142064105,0.112701665379,0.470142064105,
        0.0183880767762,0.470142064105,0.112701665379,0.0597158717898,
        0.0183880767762,0.0597158717898,0.112701665379,0.470142064105,
        0.0174915528534,0.101286507323,0.112701665379,0.101286507323,
        0.0174915528534,0.101286507323,0.112701665379,0.797426985353,
        0.0174915528534,0.797426985353,0.112701665379,0.101286507323,
        0.03125,0.333333333333,0.887298334621,0.333333333333,
        0.0183880767762,0.470142064105,0.887298334621,0.470142064105,
        0.0183880767762,0.470142064105,0.887298334621,0.0597158717898,
        0.0183880767762,0.0597158717898,0.887298334621,0.470142064105,
        0.0174915528534,0.101286507323,0.887298334621,0.101286507323,
        0.0174915528534,0.101286507323,0.887298334621,0.797426985353,
        0.0174915528534,0.797426985353,0.887298334621,0.101286507323,
        0.0,
        0.05,0.333333333333,0.5,0.333333333333,
        0.0294209228419,0.470142064105,0.5,0.470142064105,
        0.0294209228419,0.470142064105,0.5,0.0597158717898,
        0.0294209228419,0.0597158717898,0.5,0.470142064105,
        0.0279864845655,0.101286507323,0.5,0.101286507323,
        0.0279864845655,0.101286507323,0.5,0.797426985353,
        0.0279864845655,0.797426985353,0.5,0.101286507323,
        0.03125,0.333333333333,0.112701665379,0.333333333333,
        0.0183880767762,0.470142064105,0.112701665379,0.470142064105,
        0.0183880767762,0.470142064105,0.112701665379,0.0597158717898,
        0.0183880767762,0.0597158717898,0.112701665379,0.470142064105,
        0.0174915528534,0.101286507323,0.112701665379,0.101286507323,
        0.0174915528534,0.101286507323,0.112701665379,0.797426985353,
        0.0174915528534,0.797426985353,0.112701665379,0.101286507323,
        0.03125,0.333333333333,0.887298334621,0.333333333333,
        0.0183880767762,0.470142064105,0.887298334621,0.470142064105,
        0.0183880767762,0.470142064105,0.887298334621,0.0597158717898,
        0.0183880767762,0.0597158717898,0.887298334621,0.470142064105,
        0.0174915528534,0.101286507323,0.887298334621,0.101286507323,
        0.0174915528534,0.101286507323,0.887298334621,0.797426985353,
        0.0174915528534,0.797426985353,0.887298334621,0.101286507323,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Wedge &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=0.5*nodes[2]->pos[1]; T reg1=0.5*nodes[0]->pos[1]; T reg2=0.5*nodes[1]->pos[2]; T reg3=0.5*nodes[2]->pos[2]; T reg4=0.5*nodes[0]->pos[2];
    T reg5=0.5*nodes[1]->pos[1]; T reg6=reg3-reg4; T reg7=0.5*nodes[4]->pos[2]; reg3=reg2+reg3; T reg8=0.5*nodes[3]->pos[2];
    T reg9=0.5*nodes[4]->pos[1]; T reg10=0.5*nodes[3]->pos[1]; T reg11=reg0-reg1; reg0=reg0+reg5; reg4=reg2-reg4;
    reg1=reg5-reg1; reg11=reg11-reg10; reg2=0.5*nodes[2]->pos[0]; reg5=0.5*nodes[5]->pos[2]; T reg12=0.5*nodes[0]->pos[0];
    T reg13=0.5*nodes[1]->pos[0]; reg10=reg1-reg10; reg1=reg7-reg3; T reg14=0.5*nodes[5]->pos[1]; T reg15=reg9-reg0;
    reg4=reg4-reg8; reg8=reg6-reg8; reg6=reg2-reg12; reg4=reg7+reg4; reg15=reg14+reg15;
    reg10=reg9+reg10; reg12=reg13-reg12; reg7=0.5*nodes[3]->pos[0]; reg11=reg14+reg11; reg1=reg5+reg1;
    reg8=reg5+reg8; reg5=0.5*nodes[5]->pos[0]; reg2=reg13+reg2; reg6=reg6-reg7; reg9=0.5*nodes[4]->pos[0];
    reg7=reg12-reg7; reg12=reg8*reg15; reg13=reg1*reg10; reg1=reg11*reg1; reg15=reg15*reg4;
    reg14=reg9-reg2; reg10=reg8*reg10; reg4=reg11*reg4; reg15=reg13-reg15; reg6=reg5+reg6;
    reg9=reg7+reg9; reg12=reg1-reg12; reg4=reg10-reg4; reg14=reg5+reg14; reg15=reg6*reg15;
    reg12=reg9*reg12; reg15=reg12-reg15; reg4=reg14*reg4; T det_jac=reg15+reg4;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1],nodes[3],nodes[5],nodes[4]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[1][2]*var_inter[0]; T reg2=pos_nodes[1][1]*var_inter[0]; T reg3=pos_nodes[0][1]*reg0;
    T reg4=pos_nodes[1][0]*var_inter[0]; T reg5=pos_nodes[0][0]*reg0; T reg6=1-var_inter[2]; T reg7=pos_nodes[0][2]*reg0; reg4=reg5+reg4;
    reg5=pos_nodes[2][0]*var_inter[1]; T reg8=pos_nodes[2][1]*var_inter[1]; reg2=reg3+reg2; reg3=pos_nodes[2][2]*var_inter[1]; reg1=reg7+reg1;
    reg7=var_inter[0]*reg6; T reg9=reg0*reg6; T reg10=pos_nodes[3][1]*reg0; reg5=reg4+reg5; reg4=pos_nodes[0][0]*reg9;
    T reg11=pos_nodes[1][0]*reg7; T reg12=pos_nodes[2][1]*reg6; T reg13=pos_nodes[0][1]*reg6; T reg14=pos_nodes[3][0]*reg0; reg8=reg2+reg8;
    reg2=pos_nodes[0][1]*reg9; T reg15=pos_nodes[3][2]*reg0; T reg16=var_inter[1]*reg6; T reg17=pos_nodes[2][2]*reg6; reg3=reg1+reg3;
    reg1=pos_nodes[0][2]*reg6; T reg18=pos_nodes[0][0]*reg6; T reg19=pos_nodes[1][1]*reg7; T reg20=pos_nodes[2][0]*reg6; reg3=reg15-reg3;
    reg15=pos_nodes[4][2]*var_inter[0]; T reg21=pos_nodes[3][2]*var_inter[2]; T reg22=pos_nodes[2][1]*reg16; reg19=reg2+reg19; reg8=reg10-reg8;
    reg2=pos_nodes[4][1]*var_inter[0]; reg12=reg12-reg13; reg17=reg17-reg1; reg10=pos_nodes[0][2]*reg9; T reg23=pos_nodes[1][2]*reg7;
    T reg24=pos_nodes[3][1]*var_inter[2]; T reg25=pos_nodes[4][0]*var_inter[0]; reg5=reg14-reg5; reg14=var_inter[2]*reg0; reg11=reg4+reg11;
    reg4=pos_nodes[2][0]*reg16; reg20=reg20-reg18; T reg26=pos_nodes[3][0]*var_inter[2]; T reg27=pos_nodes[1][0]*reg6; T reg28=pos_nodes[5][1]*var_inter[1];
    reg22=reg19+reg22; reg19=pos_nodes[3][1]*reg14; reg15=reg3+reg15; reg2=reg8+reg2; reg20=reg20-reg26;
    reg3=pos_nodes[5][2]*var_inter[1]; reg8=pos_nodes[5][0]*var_inter[2]; reg25=reg5+reg25; reg5=pos_nodes[5][0]*var_inter[1]; T reg29=var_inter[0]*var_inter[2];
    T reg30=pos_nodes[5][1]*var_inter[2]; reg12=reg12-reg24; reg4=reg11+reg4; reg11=pos_nodes[3][0]*reg14; reg17=reg17-reg21;
    T reg31=pos_nodes[5][2]*var_inter[2]; T reg32=pos_nodes[1][1]*reg6; reg23=reg10+reg23; reg10=pos_nodes[2][2]*reg16; T reg33=var_inter[1]*var_inter[2];
    T reg34=pos_nodes[1][2]*reg6; reg18=reg27-reg18; reg31=reg17+reg31; reg17=pos_nodes[3][2]*reg14; reg10=reg23+reg10;
    reg23=pos_nodes[4][0]*reg29; reg13=reg32-reg13; reg11=reg4+reg11; reg3=reg15+reg3; reg30=reg12+reg30;
    reg5=reg25+reg5; reg8=reg20+reg8; reg28=reg2+reg28; reg19=reg22+reg19; reg2=pos_nodes[4][1]*reg29;
    reg4=reg5*reg31; reg12=reg8*reg3; reg15=reg28*reg31; reg17=reg10+reg17; reg10=pos_nodes[4][2]*reg29;
    reg20=reg30*reg3; reg26=reg18-reg26; reg18=pos_nodes[4][0]*var_inter[2]; reg23=reg11+reg23; reg11=pos_nodes[5][0]*reg33;
    reg24=reg13-reg24; reg13=pos_nodes[4][1]*var_inter[2]; reg2=reg19+reg2; reg19=pos_nodes[5][1]*reg33; reg1=reg34-reg1;
    reg15=reg20-reg15; reg22=reg8*reg28; reg25=pos_nodes[5][2]*reg33; reg10=reg17+reg10; reg17=pos_nodes[4][2]*var_inter[2];
    reg18=reg26+reg18; reg21=reg1-reg21; reg11=reg23+reg11; reg4=reg12-reg4; reg1=reg5*reg30;
    reg19=reg2+reg19; reg13=reg24+reg13; reg2=reg13*reg4; reg23=reg18*reg15; reg1=reg22-reg1;
    reg24=var_inter[0]*reg13; reg17=reg21+reg17; reg19=pos[1]-reg19; reg11=pos[0]-reg11; reg25=reg10+reg25;
    reg10=var_inter[0]*reg18; reg21=reg13*reg31; reg26=reg28*reg17; reg27=reg13*reg3; reg32=reg30*reg17;
    reg34=reg17*reg1; reg23=reg2-reg23; reg25=pos[2]-reg25; reg2=var_inter[1]*reg8; reg10=reg11+reg10;
    reg11=reg18*reg3; T reg35=reg5*reg17; T reg36=reg18*reg31; T reg37=reg8*reg17; T reg38=var_inter[0]*reg17;
    reg24=reg19+reg24; reg19=var_inter[1]*reg30; reg32=reg21-reg32; reg35=reg11-reg35; reg37=reg36-reg37;
    T reg39=reg18*reg28; T reg40=reg5*reg13; T reg41=reg18*reg30; reg26=reg27-reg26; T reg42=reg8*reg13;
    reg24=reg19+reg24; reg19=var_inter[1]*reg31; reg38=reg25+reg38; reg10=reg2+reg10; reg2=var_inter[2]*reg28;
    reg25=var_inter[2]*reg5; reg34=reg23-reg34; reg4=reg4/reg34; reg35=reg35/reg34; reg38=reg19+reg38;
    reg32=reg32/reg34; reg15=reg15/reg34; reg42=reg41-reg42; reg26=reg26/reg34; reg37=reg37/reg34;
    reg24=reg2+reg24; reg2=var_inter[2]*reg3; reg40=reg39-reg40; reg10=reg25+reg10; reg4=reg24*reg4;
    reg26=reg10*reg26; reg35=reg24*reg35; reg32=reg10*reg32; reg37=reg24*reg37; reg15=reg10*reg15;
    reg42=reg42/reg34; reg40=reg40/reg34; reg34=reg1/reg34; reg38=reg2+reg38; reg34=reg38*reg34;
    reg15=reg4-reg15; reg40=reg38*reg40; reg35=reg26-reg35; reg42=reg38*reg42; reg32=reg37-reg32;
    var_inter[0]=reg15-reg34; var_inter[1]=reg40+reg35; var_inter[2]=reg32-reg42;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[1][2]*var_inter[0]; T reg2=pos_nodes[1][1]*var_inter[0]; T reg3=pos_nodes[0][1]*reg0;
    T reg4=pos_nodes[1][0]*var_inter[0]; T reg5=pos_nodes[0][0]*reg0; T reg6=1-var_inter[2]; T reg7=pos_nodes[0][2]*reg0; reg4=reg5+reg4;
    reg5=pos_nodes[2][0]*var_inter[1]; T reg8=pos_nodes[2][1]*var_inter[1]; reg2=reg3+reg2; reg3=pos_nodes[2][2]*var_inter[1]; reg1=reg7+reg1;
    reg7=var_inter[0]*reg6; T reg9=reg0*reg6; T reg10=pos_nodes[3][1]*reg0; reg5=reg4+reg5; reg4=pos_nodes[0][0]*reg9;
    T reg11=pos_nodes[1][0]*reg7; T reg12=pos_nodes[2][1]*reg6; T reg13=pos_nodes[0][1]*reg6; T reg14=pos_nodes[3][0]*reg0; reg8=reg2+reg8;
    reg2=pos_nodes[0][1]*reg9; T reg15=pos_nodes[3][2]*reg0; T reg16=var_inter[1]*reg6; T reg17=pos_nodes[2][2]*reg6; reg3=reg1+reg3;
    reg1=pos_nodes[0][2]*reg6; T reg18=pos_nodes[0][0]*reg6; T reg19=pos_nodes[1][1]*reg7; T reg20=pos_nodes[2][0]*reg6; reg3=reg15-reg3;
    reg15=pos_nodes[4][2]*var_inter[0]; T reg21=pos_nodes[3][2]*var_inter[2]; T reg22=pos_nodes[2][1]*reg16; reg19=reg2+reg19; reg8=reg10-reg8;
    reg2=pos_nodes[4][1]*var_inter[0]; reg12=reg12-reg13; reg17=reg17-reg1; reg10=pos_nodes[0][2]*reg9; T reg23=pos_nodes[1][2]*reg7;
    T reg24=pos_nodes[3][1]*var_inter[2]; T reg25=pos_nodes[4][0]*var_inter[0]; reg5=reg14-reg5; reg14=var_inter[2]*reg0; reg11=reg4+reg11;
    reg4=pos_nodes[2][0]*reg16; reg20=reg20-reg18; T reg26=pos_nodes[3][0]*var_inter[2]; T reg27=pos_nodes[1][0]*reg6; T reg28=pos_nodes[5][1]*var_inter[1];
    reg22=reg19+reg22; reg19=pos_nodes[3][1]*reg14; reg15=reg3+reg15; reg2=reg8+reg2; reg20=reg20-reg26;
    reg3=pos_nodes[5][2]*var_inter[1]; reg8=pos_nodes[5][0]*var_inter[2]; reg25=reg5+reg25; reg5=pos_nodes[5][0]*var_inter[1]; T reg29=var_inter[0]*var_inter[2];
    T reg30=pos_nodes[5][1]*var_inter[2]; reg12=reg12-reg24; reg4=reg11+reg4; reg11=pos_nodes[3][0]*reg14; reg17=reg17-reg21;
    T reg31=pos_nodes[5][2]*var_inter[2]; T reg32=pos_nodes[1][1]*reg6; reg23=reg10+reg23; reg10=pos_nodes[2][2]*reg16; T reg33=var_inter[1]*var_inter[2];
    T reg34=pos_nodes[1][2]*reg6; reg18=reg27-reg18; reg31=reg17+reg31; reg17=pos_nodes[3][2]*reg14; reg10=reg23+reg10;
    reg23=pos_nodes[4][0]*reg29; reg13=reg32-reg13; reg11=reg4+reg11; reg3=reg15+reg3; reg30=reg12+reg30;
    reg5=reg25+reg5; reg8=reg20+reg8; reg28=reg2+reg28; reg19=reg22+reg19; reg2=pos_nodes[4][1]*reg29;
    reg4=reg5*reg31; reg12=reg8*reg3; reg15=reg28*reg31; reg17=reg10+reg17; reg10=pos_nodes[4][2]*reg29;
    reg20=reg30*reg3; reg26=reg18-reg26; reg18=pos_nodes[4][0]*var_inter[2]; reg23=reg11+reg23; reg11=pos_nodes[5][0]*reg33;
    reg24=reg13-reg24; reg13=pos_nodes[4][1]*var_inter[2]; reg2=reg19+reg2; reg19=pos_nodes[5][1]*reg33; reg1=reg34-reg1;
    reg15=reg20-reg15; reg22=reg8*reg28; reg25=pos_nodes[5][2]*reg33; reg10=reg17+reg10; reg17=pos_nodes[4][2]*var_inter[2];
    reg18=reg26+reg18; reg21=reg1-reg21; reg11=reg23+reg11; reg4=reg12-reg4; reg1=reg5*reg30;
    reg19=reg2+reg19; reg13=reg24+reg13; reg2=reg13*reg4; reg23=reg18*reg15; reg1=reg22-reg1;
    reg24=var_inter[0]*reg13; reg17=reg21+reg17; reg19=pos[1]-reg19; reg11=pos[0]-reg11; reg25=reg10+reg25;
    reg10=var_inter[0]*reg18; reg21=reg13*reg31; reg26=reg28*reg17; reg27=reg13*reg3; reg32=reg30*reg17;
    reg34=reg17*reg1; reg23=reg2-reg23; reg25=pos[2]-reg25; reg2=var_inter[1]*reg8; reg10=reg11+reg10;
    reg11=reg18*reg3; T reg35=reg5*reg17; T reg36=reg18*reg31; T reg37=reg8*reg17; T reg38=var_inter[0]*reg17;
    reg24=reg19+reg24; reg19=var_inter[1]*reg30; reg32=reg21-reg32; reg35=reg11-reg35; reg37=reg36-reg37;
    T reg39=reg18*reg28; T reg40=reg5*reg13; T reg41=reg18*reg30; reg26=reg27-reg26; T reg42=reg8*reg13;
    reg34=reg23-reg34; reg23=var_inter[2]*reg5; T reg43=var_inter[2]*reg28; reg24=reg19+reg24; reg10=reg2+reg10;
    reg2=var_inter[1]*reg31; reg38=reg25+reg38; reg10=reg23+reg10; reg40=reg39-reg40; reg19=var_inter[2]*reg3;
    reg24=reg43+reg24; reg37=reg37/reg34; reg42=reg41-reg42; reg38=reg2+reg38; reg35=reg35/reg34;
    reg4=reg4/reg34; reg32=reg32/reg34; reg15=reg15/reg34; reg26=reg26/reg34; reg4=reg24*reg4;
    reg26=reg10*reg26; reg35=reg24*reg35; reg32=reg10*reg32; reg37=reg24*reg37; reg15=reg10*reg15;
    reg42=reg42/reg34; reg40=reg40/reg34; reg34=reg1/reg34; reg38=reg19+reg38; reg34=reg38*reg34;
    reg15=reg4-reg15; reg40=reg38*reg40; reg35=reg26-reg35; reg42=reg38*reg42; reg32=reg37-reg32;
    var_inter[0]+=reg15-reg34; var_inter[1]+=reg40+reg35; var_inter[2]+=reg32-reg42;

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
    reg1=var_inter[1]*reg1; reg2=val[1]*reg2; reg3=val[0]*reg3; reg2=reg3+reg2; reg1=val[2]*reg1;
    reg0=var_inter[2]*reg0; reg1=reg2+reg1; reg0=val[3]*reg0; reg2=var_inter[0]*var_inter[2]; reg0=reg1+reg0;
    reg2=val[4]*reg2; reg1=var_inter[1]*var_inter[2]; reg1=val[5]*reg1; reg2=reg0+reg2; res=reg1+reg2;

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
