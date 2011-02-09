#ifndef LMT_WEDGE
#define LMT_WEDGE
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[1][2]*var_inter[0]; T reg2=pos_nodes[0][2]*reg0; T reg3=reg0*pos_nodes[0][0];
    T reg4=pos_nodes[1][0]*var_inter[0]; T reg5=pos_nodes[1][1]*var_inter[0]; T reg6=reg0*pos_nodes[0][1]; reg1=reg2+reg1; reg5=reg6+reg5;
    reg2=pos_nodes[2][2]*var_inter[1]; reg6=1-var_inter[2]; T reg7=pos_nodes[2][0]*var_inter[1]; T reg8=pos_nodes[2][1]*var_inter[1]; reg4=reg3+reg4;
    reg5=reg8+reg5; reg3=reg6*pos_nodes[0][1]; reg8=pos_nodes[2][1]*reg6; T reg9=pos_nodes[3][0]*reg0; reg4=reg7+reg4;
    reg7=pos_nodes[3][1]*reg0; T reg10=pos_nodes[2][0]*reg6; T reg11=reg6*pos_nodes[0][0]; reg1=reg2+reg1; reg2=pos_nodes[3][2]*reg0;
    T reg12=pos_nodes[0][2]*reg6; T reg13=pos_nodes[2][2]*reg6; reg8=reg8-reg3; T reg14=pos_nodes[4][0]*var_inter[0]; reg4=reg9-reg4;
    reg9=pos_nodes[4][2]*var_inter[0]; reg13=reg13-reg12; T reg15=var_inter[2]*pos_nodes[3][1]; T reg16=var_inter[2]*pos_nodes[3][2]; reg5=reg7-reg5;
    reg10=reg10-reg11; reg7=pos_nodes[4][1]*var_inter[0]; T reg17=var_inter[2]*pos_nodes[3][0]; reg1=reg2-reg1; reg2=pos_nodes[1][1]*reg6;
    reg8=reg8-reg15; T reg18=var_inter[2]*pos_nodes[5][1]; T reg19=pos_nodes[5][2]*var_inter[1]; T reg20=var_inter[2]*pos_nodes[5][2]; reg13=reg13-reg16;
    reg7=reg5+reg7; reg5=pos_nodes[5][1]*var_inter[1]; reg9=reg1+reg9; reg1=pos_nodes[1][0]*reg6; T reg21=var_inter[2]*pos_nodes[5][0];
    T reg22=pos_nodes[5][0]*var_inter[1]; reg10=reg10-reg17; reg14=reg4+reg14; reg4=reg0*reg6; T reg23=reg6*var_inter[0];
    T reg24=pos_nodes[1][1]*reg23; T reg25=pos_nodes[0][1]*reg4; reg5=reg7+reg5; reg11=reg1-reg11; reg1=reg6*var_inter[1];
    reg10=reg21+reg10; reg14=reg22+reg14; reg7=pos_nodes[0][0]*reg4; reg18=reg8+reg18; reg8=pos_nodes[1][0]*reg23;
    reg21=pos_nodes[1][2]*reg6; reg13=reg20+reg13; reg3=reg2-reg3; reg9=reg19+reg9; reg2=var_inter[2]*reg0;
    reg19=reg10*reg9; reg12=reg21-reg12; reg24=reg25+reg24; reg20=reg14*reg13; reg15=reg3-reg15;
    reg3=var_inter[2]*pos_nodes[4][1]; reg21=pos_nodes[0][2]*reg4; reg22=pos_nodes[1][2]*reg23; reg25=pos_nodes[2][1]*reg1; T reg26=reg18*reg9;
    reg8=reg7+reg8; reg7=pos_nodes[2][0]*reg1; T reg27=reg5*reg13; T reg28=var_inter[2]*pos_nodes[4][0]; reg17=reg11-reg17;
    reg27=reg26-reg27; reg11=reg10*reg5; reg22=reg21+reg22; reg21=pos_nodes[2][2]*reg1; reg20=reg19-reg20;
    T reg29=reg14*reg18; T reg30=var_inter[2]*pos_nodes[4][2]; reg16=reg12-reg16; reg28=reg17+reg28; reg8=reg7+reg8;
    reg7=var_inter[2]*var_inter[0]; reg12=pos_nodes[3][0]*reg2; reg17=pos_nodes[3][1]*reg2; reg24=reg25+reg24; reg3=reg15+reg3;
    reg15=reg3*reg20; reg25=pos_nodes[3][2]*reg2; reg22=reg21+reg22; reg12=reg8+reg12; reg8=pos_nodes[4][0]*reg7;
    reg21=var_inter[2]*var_inter[1]; reg17=reg24+reg17; reg24=pos_nodes[4][1]*reg7; reg29=reg11-reg29; reg30=reg16+reg30;
    reg16=reg28*reg27; T reg31=pos_nodes[5][0]*reg21; T reg32=reg14*reg30; T reg33=reg28*reg9; reg16=reg15-reg16;
    reg15=reg30*reg29; T reg34=reg18*reg30; T reg35=reg3*reg9; T reg36=reg5*reg30; T reg37=reg3*reg13;
    T reg38=reg28*reg13; T reg39=reg10*reg30; T reg40=pos_nodes[4][2]*reg7; reg25=reg22+reg25; reg8=reg12+reg8;
    reg24=reg17+reg24; reg12=pos_nodes[5][1]*reg21; reg32=reg33-reg32; reg39=reg38-reg39; reg34=reg37-reg34;
    reg17=reg28*reg5; reg36=reg35-reg36; reg22=reg14*reg3; T reg41=reg28*reg18; T reg42=reg10*reg3;
    T reg43=pos_nodes[5][2]*reg21; reg12=reg24+reg12; reg8=reg31+reg8; reg40=reg25+reg40; reg15=reg16-reg15;
    reg20=reg20/reg15; reg32=reg32/reg15; reg40=reg43+reg40; reg34=reg34/reg15; reg42=reg41-reg42;
    reg27=reg27/reg15; reg39=reg39/reg15; reg8=pos[0]-reg8; reg36=reg36/reg15; reg12=pos[1]-reg12;
    reg22=reg17-reg22; reg20=reg12*reg20; reg36=reg8*reg36; reg32=reg12*reg32; reg34=reg8*reg34;
    reg39=reg12*reg39; reg27=reg8*reg27; reg42=reg42/reg15; reg22=reg22/reg15; reg15=reg29/reg15;
    reg40=pos[2]-reg40; reg15=reg40*reg15; reg27=reg20-reg27; reg22=reg40*reg22; reg32=reg36-reg32;
    reg42=reg40*reg42; reg34=reg39-reg34; var_inter[0]=reg27-reg15; var_inter[1]=reg22+reg32; var_inter[2]=reg34-reg42;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[0][1]*reg0; T reg2=pos_nodes[1][1]*var_inter[0]; T reg3=reg0*pos_nodes[0][2];
    T reg4=pos_nodes[1][2]*var_inter[0]; T reg5=pos_nodes[1][0]*var_inter[0]; T reg6=reg0*pos_nodes[0][0]; T reg7=var_inter[1]*pos_nodes[2][0]; reg6=reg5+reg6;
    reg1=reg2+reg1; reg2=var_inter[1]*pos_nodes[2][1]; reg5=var_inter[1]*pos_nodes[2][2]; reg3=reg4+reg3; reg4=1-var_inter[2];
    reg2=reg1+reg2; reg5=reg3+reg5; reg1=reg4*pos_nodes[0][1]; reg3=reg0*pos_nodes[3][1]; T reg8=reg0*pos_nodes[3][2];
    T reg9=reg4*pos_nodes[0][2]; T reg10=reg4*pos_nodes[2][1]; reg7=reg6+reg7; reg6=reg4*pos_nodes[2][2]; T reg11=reg4*pos_nodes[2][0];
    T reg12=reg4*pos_nodes[0][0]; T reg13=reg0*pos_nodes[3][0]; reg2=reg3-reg2; reg3=var_inter[0]*pos_nodes[4][1]; T reg14=var_inter[2]*pos_nodes[3][2];
    T reg15=var_inter[0]*pos_nodes[4][0]; reg7=reg13-reg7; reg13=var_inter[2]*pos_nodes[3][1]; reg5=reg8-reg5; reg8=var_inter[0]*pos_nodes[4][2];
    reg11=reg11-reg12; T reg16=var_inter[2]*pos_nodes[3][0]; reg10=reg10-reg1; reg6=reg6-reg9; reg8=reg5+reg8;
    reg5=var_inter[1]*pos_nodes[5][2]; T reg17=var_inter[2]*pos_nodes[5][1]; T reg18=reg4*var_inter[0]; reg10=reg10-reg13; reg3=reg2+reg3;
    reg2=reg4*pos_nodes[1][0]; T reg19=reg4*pos_nodes[1][1]; T reg20=var_inter[1]*pos_nodes[5][1]; T reg21=var_inter[1]*pos_nodes[5][0]; reg15=reg7+reg15;
    reg7=var_inter[2]*pos_nodes[5][2]; T reg22=var_inter[2]*pos_nodes[5][0]; reg11=reg11-reg16; reg6=reg6-reg14; T reg23=reg4*reg0;
    reg20=reg3+reg20; reg3=pos_nodes[1][1]*reg18; reg17=reg10+reg17; reg10=reg23*pos_nodes[0][1]; reg1=reg19-reg1;
    reg5=reg8+reg5; reg7=reg6+reg7; reg6=reg4*pos_nodes[1][2]; reg8=reg4*var_inter[1]; reg19=reg23*pos_nodes[0][0];
    T reg24=pos_nodes[1][0]*reg18; reg21=reg15+reg21; reg12=reg2-reg12; reg22=reg11+reg22; reg2=reg8*pos_nodes[2][1];
    reg10=reg3+reg10; reg3=var_inter[2]*reg0; reg9=reg6-reg9; reg16=reg12-reg16; reg6=var_inter[2]*pos_nodes[4][0];
    reg11=reg20*reg7; reg19=reg24+reg19; reg12=reg8*pos_nodes[2][0]; reg15=reg17*reg5; reg24=reg23*pos_nodes[0][2];
    T reg25=pos_nodes[1][2]*reg18; T reg26=reg22*reg5; reg13=reg1-reg13; reg1=var_inter[2]*pos_nodes[4][1]; T reg27=reg21*reg7;
    reg24=reg25+reg24; reg27=reg26-reg27; reg25=reg21*reg17; T reg28=reg8*pos_nodes[2][2]; T reg29=reg22*reg20;
    reg11=reg15-reg11; reg12=reg19+reg12; reg19=var_inter[2]*pos_nodes[4][2]; reg14=reg9-reg14; reg6=reg16+reg6;
    reg9=reg3*pos_nodes[3][0]; reg16=reg3*pos_nodes[3][1]; reg2=reg10+reg2; reg1=reg13+reg1; reg10=var_inter[2]*var_inter[0];
    reg13=reg6*reg11; T reg30=reg1*reg27; T reg31=reg3*pos_nodes[3][2]; reg28=reg24+reg28; reg9=reg12+reg9;
    reg12=reg10*pos_nodes[4][0]; reg24=var_inter[1]*var_inter[2]; reg16=reg2+reg16; reg2=reg10*pos_nodes[4][1]; reg25=reg29-reg25;
    reg19=reg14+reg19; reg13=reg30-reg13; reg14=reg19*reg25; reg30=reg1*reg7; T reg32=reg17*reg19;
    T reg33=reg21*reg19; T reg34=reg1*reg5; T reg35=reg20*reg19; T reg36=reg6*reg5; T reg37=reg6*reg7;
    T reg38=reg22*reg19; T reg39=reg10*pos_nodes[4][2]; reg31=reg28+reg31; reg12=reg9+reg12; reg9=reg24*pos_nodes[5][0];
    reg2=reg16+reg2; reg16=reg24*pos_nodes[5][1]; reg33=reg36-reg33; reg38=reg37-reg38; reg32=reg30-reg32;
    reg28=reg6*reg20; T reg40=reg21*reg1; reg35=reg34-reg35; T reg41=reg6*reg17; T reg42=reg22*reg1;
    reg14=reg13-reg14; reg16=reg2+reg16; reg9=reg12+reg9; reg39=reg31+reg39; reg2=reg24*pos_nodes[5][2];
    reg16=pos[1]-reg16; reg40=reg28-reg40; reg9=pos[0]-reg9; reg38=reg38/reg14; reg42=reg41-reg42;
    reg2=reg39+reg2; reg33=reg33/reg14; reg27=reg27/reg14; reg32=reg32/reg14; reg35=reg35/reg14;
    reg11=reg11/reg14; reg27=reg16*reg27; reg35=reg9*reg35; reg33=reg16*reg33; reg32=reg9*reg32;
    reg38=reg16*reg38; reg11=reg9*reg11; reg42=reg42/reg14; reg40=reg40/reg14; reg14=reg25/reg14;
    reg2=pos[2]-reg2; reg14=reg2*reg14; reg11=reg27-reg11; reg40=reg2*reg40; reg33=reg35-reg33;
    reg42=reg2*reg42; reg32=reg38-reg32; var_inter[0]+=reg11-reg14; var_inter[1]+=reg40+reg33; var_inter[2]+=reg32-reg42;

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
    T reg4=var_inter[1]*reg1; reg2=val[1]*reg2; reg3=val[0]*reg3; reg2=reg3+reg2; reg4=val[2]*reg4;
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=reg0*elem.pos(0)[1]; T reg2=var_inter[0]*elem.pos(1)[2]; T reg3=elem.pos(0)[2]*reg0;
    T reg4=var_inter[0]*elem.pos(1)[1]; T reg5=1-var_inter[2]; T reg6=var_inter[1]*elem.pos(2)[2]; T reg7=reg4+reg1; T reg8=reg3+reg2;
    T reg9=var_inter[1]*elem.pos(2)[1]; T reg10=reg5*elem.pos(2)[2]; T reg11=reg8+reg6; T reg12=reg0*elem.pos(3)[2]; T reg13=reg7+reg9;
    T reg14=reg0*elem.pos(3)[1]; T reg15=reg5*elem.pos(0)[1]; T reg16=elem.pos(1)[1]*reg5; T reg17=reg5*elem.pos(2)[1]; T reg18=elem.pos(1)[2]*reg5;
    T reg19=elem.pos(0)[2]*reg5; reg16=reg16-reg15; T reg20=var_inter[0]*elem.pos(4)[2]; reg18=reg18-reg19; T reg21=var_inter[2]*elem.pos(3)[2];
    T reg22=var_inter[0]*elem.pos(4)[1]; reg17=reg17-reg15; T reg23=reg0*elem.pos(0)[0]; T reg24=var_inter[2]*elem.pos(3)[1]; T reg25=var_inter[0]*elem.pos(1)[0];
    reg12=reg12-reg11; reg14=reg14-reg13; reg10=reg10-reg19; reg16=reg16-reg24; T reg26=var_inter[2]*elem.pos(4)[2];
    reg10=reg10-reg21; T reg27=elem.pos(1)[0]*reg5; reg20=reg12+reg20; reg12=var_inter[1]*elem.pos(5)[1]; reg22=reg14+reg22;
    reg14=var_inter[1]*elem.pos(5)[2]; T reg28=reg23+reg25; T reg29=var_inter[2]*elem.pos(4)[1]; T reg30=elem.pos(2)[0]*reg5; reg18=reg18-reg21;
    T reg31=var_inter[2]*elem.pos(5)[2]; T reg32=var_inter[1]*elem.pos(2)[0]; T reg33=reg5*elem.pos(0)[0]; T reg34=var_inter[2]*elem.pos(5)[1]; reg17=reg17-reg24;
    reg10=reg31+reg10; reg16=reg29+reg16; reg27=reg27-reg33; reg29=reg32+reg28; reg14=reg20+reg14;
    reg20=var_inter[2]*elem.pos(3)[0]; reg30=reg30-reg33; reg31=reg0*elem.pos(3)[0]; reg17=reg34+reg17; reg22=reg12+reg22;
    reg26=reg18+reg26; reg12=reg17*reg14; reg18=reg14*reg16; reg34=reg26*reg22; T reg35=var_inter[2]*elem.pos(4)[0];
    T reg36=var_inter[2]*elem.pos(5)[0]; reg27=reg27-reg20; T reg37=reg10*reg22; reg30=reg30-reg20; T reg38=var_inter[0]*elem.pos(4)[0];
    reg31=reg31-reg29; reg38=reg31+reg38; reg31=var_inter[1]*elem.pos(5)[0]; reg37=reg12-reg37; reg12=reg26*reg17;
    reg34=reg18-reg34; reg18=reg16*reg10; reg35=reg27+reg35; reg36=reg30+reg36; reg31=reg38+reg31;
    reg27=reg35*reg37; reg30=reg34*reg36; reg12=reg18-reg12; reg30=reg27-reg30; reg18=reg31*reg12;
    reg18=reg30+reg18; return reg18;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Wedge,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=elem.pos(2)[2]-elem.pos(0)[2]; T reg1=elem.pos(0)[2]-elem.pos(2)[2]; T reg2=elem.pos(2)[1]-elem.pos(0)[1]; T reg3=elem.pos(1)[1]-elem.pos(0)[1]; T reg4=elem.pos(0)[1]-elem.pos(2)[1];
    T reg5=elem.pos(0)[2]-elem.pos(1)[2]; T reg6=elem.pos(1)[2]-elem.pos(0)[2]; T reg7=elem.pos(0)[1]-elem.pos(1)[1]; T reg8=elem.pos(3)[2]+reg0; T reg9=elem.pos(3)[2]+reg6;
    T reg10=elem.pos(3)[1]+reg2; reg5=reg5-elem.pos(3)[2]; reg4=reg4-elem.pos(3)[1]; reg1=reg1-elem.pos(3)[2]; T reg11=elem.pos(3)[1]+reg3;
    reg7=reg7-elem.pos(3)[1]; T reg12=elem.pos(4)[1]-reg11; T reg13=elem.pos(0)[0]-elem.pos(2)[0]; T reg14=elem.pos(4)[2]-reg9; reg5=elem.pos(4)[2]+reg5;
    reg1=elem.pos(5)[2]+reg1; reg7=elem.pos(4)[1]+reg7; reg4=elem.pos(5)[1]+reg4; T reg15=elem.pos(5)[1]-reg10; T reg16=elem.pos(3)[2]-elem.pos(0)[2];
    T reg17=elem.pos(0)[0]-elem.pos(1)[0]; T reg18=elem.pos(3)[1]-elem.pos(0)[1]; T reg19=elem.pos(5)[2]-reg8; T reg20=reg2*reg16; T reg21=reg7*reg16;
    T reg22=reg6*reg12; T reg23=reg3*reg14; T reg24=reg0*reg18; T reg25=reg5*reg18; T reg26=reg0*reg12;
    T reg27=reg3*reg16; T reg28=reg6*reg18; T reg29=reg2*reg14; T reg30=reg2*reg19; T reg31=reg7*reg19;
    T reg32=reg1*reg15; reg17=reg17-elem.pos(3)[0]; T reg33=reg4*reg19; T reg34=reg5*reg15; T reg35=reg6*reg15;
    T reg36=reg3*reg19; T reg37=reg5*reg12; T reg38=reg7*reg14; T reg39=reg4*reg16; T reg40=reg1*reg18;
    T reg41=reg1*reg12; T reg42=reg4*reg14; reg13=reg13-elem.pos(3)[0]; T reg43=reg0*reg15; reg24=reg20-reg24;
    reg34=reg31-reg34; reg32=reg33-reg32; reg28=reg27-reg28; reg25=reg21-reg25; reg35=reg36-reg35;
    reg43=reg30-reg43; reg40=reg39-reg40; reg20=elem.pos(1)[0]-elem.pos(0)[0]; reg21=elem.pos(2)[0]-elem.pos(0)[0]; reg17=elem.pos(4)[0]+reg17;
    reg37=reg38-reg37; reg41=reg42-reg41; reg13=elem.pos(5)[0]+reg13; reg22=reg23-reg22; reg26=reg29-reg26;
    reg23=reg3*reg1; reg27=reg0*reg7; reg29=reg6*reg4; reg30=reg2*reg5; reg31=reg4*reg5;
    reg33=reg1*reg7; reg36=reg21*reg34; reg38=reg13*reg35; reg31=2*reg31; reg39=reg17*reg43;
    reg42=reg17*reg32; reg32=reg20*reg32; reg34=reg13*reg34; reg33=2*reg33; T reg44=reg13*reg37;
    T reg45=reg17*reg41; T reg46=elem.pos(3)[0]+reg21; T reg47=reg13*reg22; reg27=reg23+reg27; reg23=reg13*reg28;
    T reg48=reg21*reg25; T reg49=reg17*reg40; reg30=reg29+reg30; reg29=elem.pos(3)[0]+reg20; T reg50=reg17*reg24;
    reg40=reg20*reg40; reg25=reg13*reg25; reg41=reg20*reg41; T reg51=reg17*reg26; reg37=reg21*reg37;
    T reg52=reg0*reg3; T reg53=reg2*reg6; T reg54=elem.pos(5)[0]-reg46; reg39=reg32+reg39; reg30=reg27-reg30;
    reg31=reg33-reg31; reg49=2*reg49; reg25=2*reg25; reg23=reg48+reg23; reg50=reg40+reg50;
    reg27=elem.pos(3)[0]-elem.pos(0)[0]; reg44=2*reg44; reg45=2*reg45; reg47=reg37+reg47; reg51=reg41+reg51;
    reg34=2*reg34; reg42=2*reg42; reg32=elem.pos(4)[0]-reg29; reg38=reg36+reg38; reg47=reg51-reg47;
    reg33=reg30*reg32; reg44=reg45-reg44; reg36=reg31*reg32; reg53=reg52-reg53; reg37=reg31*reg27;
    reg24=reg20*reg24; reg25=reg49-reg25; reg22=reg21*reg22; reg26=reg20*reg26; reg38=reg39-reg38;
    reg39=reg30*reg27; reg23=reg50-reg23; reg40=reg30*reg54; reg43=reg20*reg43; reg34=reg42-reg34;
    reg41=reg31*reg54; reg28=reg21*reg28; reg35=reg21*reg35; reg22=reg26-reg22; reg40=reg38+reg40;
    reg26=reg53*reg32; reg38=reg53*reg54; reg33=reg47+reg33; reg41=reg34+reg41; reg35=reg43-reg35;
    reg36=reg44+reg36; reg28=reg24-reg28; reg37=reg25+reg37; reg24=reg53*reg27; reg39=reg23+reg39;
    reg23=reg0*reg36; reg25=reg40*reg12; reg34=reg15*reg33; reg42=reg3*reg41; reg43=reg40*reg32;
    reg44=reg2*reg36; reg45=reg21*reg36; reg26=reg22+reg26; reg22=reg20*reg41; reg47=reg54*reg33;
    reg48=reg6*reg41; reg38=reg35+reg38; reg24=reg28+reg24; reg28=reg40*reg16; reg35=reg19*reg39;
    reg49=elem.pos(0)[2]*reg41; reg50=reg0*reg37; reg51=reg40*reg27; reg52=reg54*reg39; T reg55=elem.pos(0)[0]*reg41;
    T reg56=reg18*reg40; T reg57=reg15*reg39; T reg58=reg19*reg33; T reg59=elem.pos(0)[1]*reg41; T reg60=reg2*reg37;
    T reg61=reg21*reg37; T reg62=reg40*reg14; reg58=reg62+reg58; reg47=reg43+reg47; reg43=elem.pos(0)[2]*reg40;
    reg62=reg0*reg39; reg45=reg22+reg45; reg22=reg41*reg32; T reg63=reg38*reg16; T reg64=reg19*reg24;
    T reg65=reg54*reg36; T reg66=reg19*reg26; reg35=reg28+reg35; reg28=reg38*reg14; T reg67=reg0*reg33;
    reg50=reg49+reg50; reg49=reg19*reg36; T reg68=reg41*reg14; reg23=reg48+reg23; reg48=reg6*reg40;
    T reg69=reg41*reg16; T reg70=reg19*reg37; T reg71=reg15*reg26; T reg72=reg38*reg12; T reg73=reg2*reg33;
    T reg74=reg3*reg40; T reg75=reg15*reg37; T reg76=reg18*reg41; T reg77=reg54*reg37; T reg78=reg41*reg27;
    reg61=reg55+reg61; reg60=reg59+reg60; reg57=reg56+reg57; reg52=reg51+reg52; reg51=reg15*reg24;
    reg55=reg18*reg38; reg56=reg2*reg39; reg59=elem.pos(0)[1]*reg40; T reg79=reg54*reg24; T reg80=reg38*reg27;
    T reg81=reg21*reg39; T reg82=elem.pos(0)[0]*reg40; reg44=reg42+reg44; reg34=reg25+reg34; reg25=reg20*reg40;
    reg42=reg21*reg33; T reg83=reg38*reg32; T reg84=reg54*reg26; T reg85=reg41*reg12; T reg86=reg15*reg36;
    reg81=reg82+reg81; reg64=reg63+reg64; reg62=reg43+reg62; reg84=reg83+reg84; reg42=reg25+reg42;
    reg79=reg80+reg79; reg25=reg6*reg37; reg43=reg3*reg36; reg50=reg35+reg50; reg63=reg12*reg33;
    reg49=reg68+reg49; reg68=reg16*reg33; reg80=reg39*reg14; reg23=reg58+reg23; reg82=elem.pos(0)[2]*reg36;
    reg83=reg14*reg33; reg77=reg78+reg77; reg78=reg6*reg36; T reg87=elem.pos(0)[0]*reg36; T reg88=reg39*reg32;
    reg66=reg28+reg66; reg28=reg27*reg33; reg61=reg52+reg61; reg67=reg48+reg67; reg65=reg22+reg65;
    reg70=reg69+reg70; reg45=reg47+reg45; reg73=reg74+reg73; reg71=reg72+reg71; reg22=reg18*reg33;
    reg48=reg20*reg36; reg75=reg76+reg75; reg69=reg32*reg33; reg44=reg34+reg44; reg86=reg85+reg86;
    reg60=reg57+reg60; reg72=reg39*reg12; reg74=elem.pos(0)[1]*reg36; reg51=reg55+reg51; reg55=reg3*reg37;
    reg56=reg59+reg56; reg59=reg20*reg37; reg76=reg16*reg26; reg85=elem.pos(0)[0]*reg38; T reg89=reg21*reg24;
    T reg90=reg24*reg14; T reg91=reg2*reg41; reg79=reg81+reg79; reg50=reg35+reg50; reg35=reg37*reg12;
    reg81=2*reg70; reg61=reg52+reg61; reg52=2*reg75; T reg92=reg0*reg41; T reg93=reg19*reg40;
    T reg94=reg0*reg26; T reg95=reg6*reg38; reg80=reg68+reg80; reg68=2*reg77; T reg96=reg3*reg38;
    T reg97=reg3*reg33; reg55=reg74+reg55; reg74=reg12*reg26; reg64=reg62+reg64; reg23=reg58+reg23;
    reg58=reg0*reg24; reg62=elem.pos(0)[2]*reg38; T reg98=reg2*reg24; reg51=reg56+reg51; reg56=elem.pos(0)[1]*reg38;
    reg72=reg22+reg72; reg22=reg54*reg40; reg66=reg67+reg66; reg67=reg21*reg41; T reg99=2*reg49;
    T reg100=reg15*reg40; reg60=reg57+reg60; reg57=reg18*reg36; T reg101=elem.pos(0)[2]*reg33; T reg102=reg6*reg39;
    T reg103=2*reg86; T reg104=elem.pos(0)[1]*reg33; T reg105=reg3*reg39; T reg106=reg37*reg32; T reg107=reg27*reg36;
    reg45=reg47+reg45; reg47=reg6*reg33; T reg108=reg14*reg26; T reg109=2*reg65; T reg110=reg18*reg26;
    T reg111=reg24*reg12; T reg112=elem.pos(0)[0]*reg33; T reg113=reg20*reg39; T reg114=reg27*reg26; T reg115=reg24*reg32;
    reg83=2*reg83; reg78=2*reg78; reg87=reg59+reg87; reg43=2*reg43; reg88=reg28+reg88;
    reg63=2*reg63; reg82=reg25+reg82; reg25=reg2*reg26; reg28=reg16*reg36; reg59=reg37*reg14;
    reg71=reg73+reg71; reg48=2*reg48; reg69=2*reg69; reg73=reg32*reg26; reg44=reg34+reg44;
    reg84=reg42+reg84; reg34=reg21*reg26; reg42=reg20*reg38; T reg116=reg20*reg33; reg82=reg80+reg82;
    reg51=reg51/2; reg94=reg95+reg94; reg81=reg70+reg81; reg35=reg57+reg35; reg57=reg14*reg36;
    reg25=reg96+reg25; reg78=reg83+reg78; reg99=reg49+reg99; reg111=reg110+reg111; reg103=reg86+reg103;
    reg66=reg66/2; reg52=reg75+reg52; reg59=reg28+reg59; reg98=reg56+reg98; reg60=0.5*reg60;
    reg47=2*reg47; reg55=reg72+reg55; reg23=0.5*reg23; reg90=reg76+reg90; reg71=reg71/2;
    reg105=reg104+reg105; reg108=2*reg108; reg102=reg101+reg102; reg44=0.5*reg44; reg28=reg27*reg39;
    reg49=elem.pos(0)[0]*reg37; reg89=reg85+reg89; reg79=reg79/2; reg92=2*reg92; reg93=2*reg93;
    reg61=0.5*reg61; reg68=reg77+reg68; reg56=reg19*reg38; reg70=reg0*reg40; reg75=reg32*reg36;
    reg76=elem.pos(0)[2]*reg37; reg77=reg16*reg39; reg48=reg69+reg48; reg73=2*reg73; reg116=2*reg116;
    reg34=reg42+reg34; reg84=reg84/2; reg106=reg107+reg106; reg45=0.5*reg45; reg109=reg65+reg109;
    reg113=reg112+reg113; reg42=reg12*reg36; reg115=reg114+reg115; reg87=reg87+reg88; reg43=reg63+reg43;
    reg100=2*reg100; reg65=reg15*reg38; reg85=reg2*reg40; reg74=2*reg74; reg58=reg62+reg58;
    reg62=elem.pos(0)[1]*reg37; reg50=0.5*reg50; reg67=2*reg67; reg22=2*reg22; reg64=reg64/2;
    reg86=reg18*reg39; reg97=2*reg97; reg95=reg54*reg38; reg91=2*reg91; reg96=reg21*reg40;
    reg101=2*reg106; reg104=reg3*reg24; reg107=elem.pos(0)[1]*reg26; reg103=0.16666666666666666667*reg103; reg84=reg34+reg84;
    reg65=2*reg65; reg44=reg44/3; reg45=reg45/3; reg88=reg87+reg88; reg109=0.16666666666666666667*reg109;
    reg34=elem.pos(0)[0]*reg26; reg87=reg20*reg24; reg91=reg100+reg91; reg110=reg15*reg41; reg112=elem.pos(0)[2]*reg39;
    reg115=reg113+reg115; reg62=reg86+reg62; reg113=4*reg57; reg57=2*reg57; reg114=reg18*reg37;
    reg67=reg22+reg67; T reg117=reg54*reg41; reg51=reg98+reg51; reg81=0.16666666666666666667*reg81; reg98=elem.pos(0)[0]*reg39;
    T reg118=reg27*reg24; reg60=reg60/3; reg49=reg28+reg49; reg27=reg27*reg37; reg95=2*reg95;
    reg79=reg89+reg79; reg96=2*reg96; reg89=elem.pos(0)[1]*reg39; reg52=0.16666666666666666667*reg52; reg61=reg61/3;
    reg68=0.16666666666666666667*reg68; T reg119=4*reg75; reg75=2*reg75; reg18=reg18*reg24; reg48=reg69+reg48;
    reg73=reg116+reg73; reg71=reg25+reg71; reg85=2*reg85; reg25=reg20*reg26; reg56=2*reg56;
    reg66=reg94+reg66; reg70=2*reg70; reg50=reg50/3; reg55=reg72+reg55; reg23=reg23/3;
    reg99=0.16666666666666666667*reg99; reg111=reg105+reg111; reg69=elem.pos(0)[2]*reg26; reg72=reg6*reg24; reg108=reg47+reg108;
    reg47=reg6*reg26; reg74=reg97+reg74; reg94=reg16*reg24; reg90=reg102+reg90; reg82=reg80+reg82;
    reg76=reg77+reg76; reg80=reg3*reg26; reg64=reg58+reg64; reg58=2*reg59; reg43=reg63+reg43;
    reg92=reg93+reg92; reg63=2*reg42; reg42=4*reg42; reg78=reg83+reg78; reg83=reg19*reg41;
    reg16=reg16*reg37; reg97=2*reg35; reg102=reg2*reg38; reg82=0.5*reg82; reg105=2*reg110;
    reg116=2*reg83; reg111=reg111/2; reg119=reg75+reg119; reg118=reg98+reg118; reg65=reg85+reg65;
    reg52=reg52/4; reg90=reg90/2; reg92=reg93+reg92; reg110=4*reg110; reg60=reg51+reg60;
    reg62=reg86+reg62; reg72=reg69+reg72; reg51=2*reg27; reg83=4*reg83; reg61=reg79+reg61;
    reg91=reg100+reg91; reg49=reg28+reg49; reg99=reg99/4; reg23=reg66+reg23; reg28=2*reg114;
    reg55=0.5*reg55; reg50=reg64+reg50; reg68=reg68/4; reg97=reg35+reg97; reg56=reg70+reg56;
    reg73=reg73/2; reg25=2*reg25; reg101=reg106+reg101; reg35=2*reg16; reg45=reg84+reg45;
    reg95=reg96+reg95; reg88=0.5*reg88; reg109=reg109/4; reg87=reg34+reg87; reg34=4*reg117;
    reg42=reg63+reg42; reg117=2*reg117; reg115=reg115/2; reg76=reg77+reg76; reg43=0.5*reg43;
    reg74=reg74/2; reg67=reg22+reg67; reg113=reg57+reg113; reg78=0.5*reg78; reg58=reg59+reg58;
    reg22=reg0*reg38; reg81=reg81/4; reg44=reg71+reg44; reg48=0.5*reg48; reg18=reg89+reg18;
    reg80=2*reg80; reg94=reg112+reg94; reg103=reg103/4; reg104=reg107+reg104; reg57=reg21*reg38;
    reg108=reg108/2; reg47=2*reg47; reg59=elem.pos(0)[2]*reg24; reg67=0.5*reg67; reg63=elem.pos(0)[0]*reg24;
    reg51=reg27+reg51; reg18=reg18/2; reg57=2*reg57; reg27=elem.pos(0)[1]*reg24; reg102=2*reg102;
    reg91=0.5*reg91; reg76=0.5*reg76; reg35=reg16+reg35; reg118=reg118/2; reg49=0.5*reg49;
    reg34=reg117+reg34; reg65=reg65/2; reg95=reg95/2; reg83=reg116+reg83; reg50=reg81+reg50;
    reg119=0.16666666666666666667*reg119; reg82=reg82/3; reg22=2*reg22; reg58=0.16666666666666666667*reg58; reg48=reg48/3;
    reg94=reg94/2; reg103=reg44+reg103; reg108=reg47+reg108; reg73=reg25+reg73; reg101=0.16666666666666666667*reg101;
    reg88=reg88/3; reg109=reg45+reg109; reg42=0.16666666666666666667*reg42; reg43=reg43/3; reg115=reg87+reg115;
    reg113=0.16666666666666666667*reg113; reg78=reg78/3; reg74=reg80+reg74; reg97=0.16666666666666666667*reg97; reg28=reg114+reg28;
    reg56=reg56/2; reg68=reg61+reg68; reg55=reg55/3; reg99=reg23+reg99; reg90=reg72+reg90;
    reg62=0.5*reg62; reg111=reg104+reg111; reg52=reg60+reg52; reg92=0.5*reg92; reg110=reg105+reg110;
    reg43=reg74+reg43; reg56=reg22+reg56; reg42=reg42/4; reg92=reg92/3; reg16=2*reg103;
    reg51=0.16666666666666666667*reg51; reg115=reg88+reg115; reg34=0.16666666666666666667*reg34; reg101=reg101/4; reg22=2*reg68;
    reg49=reg49/3; reg59=reg94+reg59; reg48=reg73+reg48; reg83=0.16666666666666666667*reg83; reg118=reg63+reg118;
    reg119=reg119/4; reg23=2*reg109; reg110=0.16666666666666666667*reg110; reg97=reg97/4; reg62=reg62/3;
    reg28=0.16666666666666666667*reg28; reg18=reg27+reg18; reg55=reg111+reg55; reg91=reg91/3; reg82=reg90+reg82;
    reg58=reg58/4; reg25=2*reg50; reg27=2*reg52; reg65=reg102+reg65; reg44=2*reg99;
    reg35=0.16666666666666666667*reg35; reg95=reg57+reg95; reg113=reg113/4; reg76=reg76/3; reg67=reg67/3;
    reg78=reg108+reg78; reg45=reg40/2; reg49=reg118+reg49; reg47=0.5*reg41; reg83=reg83/4;
    reg91=reg65+reg91; reg97=reg55+reg97; reg51=reg51/4; reg110=reg110/4; reg92=reg56+reg92;
    reg62=reg18+reg62; reg28=reg28/4; reg18=reg23-reg22; reg119=reg48+reg119; reg58=reg82+reg58;
    reg101=reg115+reg101; reg48=reg16-reg27; reg42=reg43+reg42; reg43=reg44-reg25; reg113=reg78+reg113;
    reg67=reg95+reg67; reg76=reg59+reg76; reg34=reg34/4; reg35=reg35/4; reg51=reg49+reg51;
    reg110=reg91+reg110; reg49=4*reg109; reg28=reg62+reg28; reg18=reg23+reg18; reg55=reg119-reg101;
    reg25=reg99-reg25; reg22=reg109-reg22; reg56=4*reg103; reg48=reg16+reg48; reg39=reg39/2;
    reg57=4*reg99; reg59=reg42-reg97; reg37=0.5*reg37; reg43=reg44+reg43; reg34=reg67+reg34;
    reg60=reg113-reg58; reg83=reg92+reg83; reg35=reg76+reg35; reg27=reg103-reg27; reg61=0.5*reg36;
    reg62=reg33/2; reg45=reg45+reg38; reg47=reg47/3; reg63=2*reg119; reg64=2*reg42;
    reg65=reg16+reg56; reg24=reg39+reg24; reg39=reg101-reg51; reg22=reg22/2; reg61=reg61/3;
    reg66=1.5*reg34; reg67=3*reg34; reg18=reg18/2; reg62=reg62+reg26; reg69=1.5*reg83;
    reg101=reg55-reg101; reg25=reg25/2; reg27=reg27/2; reg55=reg58-reg35; reg37=reg37/3;
    reg70=3*reg83; reg71=reg97-reg28; reg47=reg45+reg47; reg45=2*reg113; reg43=reg43/2;
    reg97=reg59-reg97; reg59=reg23+reg49; reg72=reg44+reg57; reg48=reg48/2; reg58=reg60-reg58;
    reg60=1.5*reg110; reg73=3*reg110; reg83=0.5*reg83; reg37=reg24+reg37; reg34=0.5*reg34;
    reg25=reg55+reg25; reg43=reg58-reg43; reg60=reg60/3; reg69=reg69/3; reg24=reg70/3;
    reg66=reg66/3; reg55=reg113+reg45; reg22=reg39+reg22; reg39=reg65/2; reg27=reg71+reg27;
    reg58=reg72/2; reg71=reg42+reg64; reg48=reg97-reg48; reg74=reg73/3; reg18=reg101-reg18;
    reg75=reg119+reg63; reg76=reg59/2; reg77=reg67/3; reg110=0.5*reg110; reg78=2*reg47;
    reg68=reg68/2; reg52=reg52/2; reg62=reg61+reg62; reg50=reg50/2; reg68=reg51+reg68;
    reg51=reg62-reg37; reg61=reg39-reg71; reg79=reg78/2; reg80=reg34/3; reg81=reg58-reg55;
    reg48=reg48+reg74; reg82=2*reg62; reg18=reg18+reg77; reg60=reg27-reg60; reg27=reg110/3;
    reg52=reg28+reg52; reg35=reg50+reg35; reg28=reg83/3; reg69=reg25-reg69; reg43=reg43+reg24;
    reg25=reg76-reg75; reg66=reg22-reg66; reg22=reg47/2; reg66=reg66/2; reg51=reg51-reg79;
    reg43=0.5*reg43; reg81=reg81-reg24; reg28=reg35+reg28; reg25=reg25-reg77; reg48=0.5*reg48;
    reg18=0.5*reg18; reg69=reg69/2; reg35=reg79-reg82; reg27=reg52+reg27; reg61=reg61-reg74;
    reg80=reg68+reg80; reg60=reg60/2; reg18=reg18/3; reg80=reg66+reg80; reg48=reg48/3;
    reg25=0.16666666666666666667*reg25; reg60=reg27+reg60; reg37=reg22+reg37; reg61=0.16666666666666666667*reg61; reg35=0.5*reg35;
    reg43=reg43/3; reg51=reg51/2; reg69=reg28+reg69; reg81=0.16666666666666666667*reg81; reg43=reg69+reg43;
    reg35=reg35/3; reg48=reg60+reg48; reg61=reg61/4; reg81=reg81/4; reg18=reg80+reg18;
    reg51=reg37+reg51; reg25=reg25/4; reg35=reg51+reg35; reg61=reg48+reg61; reg25=reg18+reg25;
    reg81=reg43+reg81; res[0]=reg25/reg35; res[1]=reg61/reg35; res[2]=reg81/reg35;

    return res;
}
}
#endif // LMT_WEDGE
