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
    T reg0=0.5*nodes[0]->pos[2]; T reg1=0.5*nodes[2]->pos[2]; T reg2=0.5*nodes[1]->pos[2]; T reg3=0.5*nodes[1]->pos[1]; T reg4=0.5*nodes[0]->pos[1];
    T reg5=0.5*nodes[2]->pos[1]; T reg6=reg5+reg3; T reg7=0.5*nodes[4]->pos[1]; T reg8=0.5*nodes[3]->pos[2]; T reg9=reg2-reg0;
    reg3=reg3-reg4; reg0=reg1-reg0; T reg10=0.5*nodes[4]->pos[2]; reg1=reg2+reg1; reg2=0.5*nodes[3]->pos[1];
    reg4=reg5-reg4; reg9=reg9-reg8; reg3=reg3-reg2; reg5=0.5*nodes[1]->pos[0]; T reg11=0.5*nodes[0]->pos[0];
    reg2=reg4-reg2; reg4=0.5*nodes[5]->pos[1]; T reg12=reg10-reg1; T reg13=0.5*nodes[5]->pos[2]; reg8=reg0-reg8;
    reg0=reg7-reg6; T reg14=0.5*nodes[2]->pos[0]; T reg15=reg14-reg11; reg11=reg5-reg11; T reg16=0.5*nodes[3]->pos[0];
    reg2=reg2+reg4; reg12=reg12+reg13; reg8=reg13+reg8; reg3=reg7+reg3; reg0=reg4+reg0;
    reg9=reg10+reg9; reg4=reg12*reg3; reg7=reg8*reg0; reg0=reg0*reg9; reg11=reg11-reg16;
    reg14=reg5+reg14; reg5=0.5*nodes[4]->pos[0]; reg12=reg2*reg12; reg16=reg15-reg16; reg10=0.5*nodes[5]->pos[0];
    reg0=reg4-reg0; reg11=reg11+reg5; reg16=reg16+reg10; reg7=reg12-reg7; reg5=reg5-reg14;
    reg9=reg2*reg9; reg3=reg8*reg3; reg0=reg16*reg0; reg7=reg11*reg7; reg9=reg3-reg9;
    reg5=reg10+reg5; reg0=reg7-reg0; reg9=reg5*reg9; T det_jac=reg0+reg9;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1],nodes[3],nodes[5],nodes[4]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=var_inter[0]*pos_nodes[1][1]; T reg2=pos_nodes[0][1]*reg0; T reg3=var_inter[0]*pos_nodes[1][0];
    T reg4=pos_nodes[0][0]*reg0; T reg5=var_inter[0]*pos_nodes[1][2]; T reg6=reg0*pos_nodes[0][2]; reg6=reg5+reg6; reg5=var_inter[1]*pos_nodes[2][1];
    T reg7=1-var_inter[2]; reg3=reg4+reg3; reg4=var_inter[1]*pos_nodes[2][0]; reg1=reg2+reg1; reg2=var_inter[1]*pos_nodes[2][2];
    reg5=reg1+reg5; reg1=reg0*pos_nodes[3][1]; T reg8=reg7*pos_nodes[2][1]; T reg9=pos_nodes[0][1]*reg7; reg4=reg3+reg4;
    reg3=reg0*pos_nodes[3][0]; T reg10=reg7*pos_nodes[2][0]; T reg11=pos_nodes[0][0]*reg7; T reg12=reg0*pos_nodes[3][2]; T reg13=reg7*pos_nodes[2][2];
    reg2=reg6+reg2; reg6=reg7*pos_nodes[0][2]; T reg14=var_inter[0]*pos_nodes[4][1]; T reg15=var_inter[2]*pos_nodes[3][0]; reg13=reg13-reg6;
    reg10=reg10-reg11; reg5=reg1-reg5; reg4=reg3-reg4; reg1=var_inter[0]*pos_nodes[4][0]; reg3=var_inter[2]*pos_nodes[3][1];
    T reg16=var_inter[2]*pos_nodes[3][2]; reg8=reg8-reg9; T reg17=var_inter[0]*pos_nodes[4][2]; reg2=reg12-reg2; reg12=reg7*var_inter[0];
    T reg18=reg7*pos_nodes[1][0]; reg10=reg10-reg15; T reg19=var_inter[2]*pos_nodes[5][0]; T reg20=reg0*reg7; T reg21=var_inter[1]*pos_nodes[5][1];
    T reg22=var_inter[1]*pos_nodes[5][2]; reg17=reg2+reg17; reg14=reg5+reg14; reg2=var_inter[2]*pos_nodes[5][1]; reg8=reg8-reg3;
    reg1=reg4+reg1; reg13=reg13-reg16; reg4=var_inter[1]*pos_nodes[5][0]; reg5=var_inter[2]*pos_nodes[5][2]; T reg23=reg7*pos_nodes[1][1];
    reg2=reg8+reg2; reg4=reg1+reg4; reg1=pos_nodes[0][0]*reg20; reg19=reg10+reg19; reg8=reg12*pos_nodes[1][0];
    reg9=reg23-reg9; reg21=reg14+reg21; reg10=pos_nodes[0][1]*reg20; reg14=reg12*pos_nodes[1][1]; reg11=reg18-reg11;
    reg22=reg17+reg22; reg13=reg5+reg13; reg5=reg7*pos_nodes[1][2]; reg17=reg7*var_inter[1]; reg3=reg9-reg3;
    reg9=var_inter[2]*pos_nodes[4][1]; reg18=reg17*pos_nodes[2][0]; reg8=reg1+reg8; reg1=reg20*pos_nodes[0][2]; reg23=reg12*pos_nodes[1][2];
    T reg24=reg22*reg2; T reg25=reg13*reg21; T reg26=reg22*reg19; T reg27=reg17*pos_nodes[2][1]; T reg28=var_inter[2]*reg0;
    T reg29=reg13*reg4; reg14=reg10+reg14; reg15=reg11-reg15; reg10=var_inter[2]*pos_nodes[4][0]; reg6=reg5-reg6;
    reg27=reg14+reg27; reg29=reg26-reg29; reg5=reg28*pos_nodes[3][1]; reg9=reg3+reg9; reg23=reg1+reg23;
    reg1=reg17*pos_nodes[2][2]; reg16=reg6-reg16; reg3=var_inter[2]*pos_nodes[4][2]; reg25=reg24-reg25; reg6=reg19*reg21;
    reg11=reg4*reg2; reg14=var_inter[2]*var_inter[0]; reg10=reg15+reg10; reg18=reg8+reg18; reg8=reg28*pos_nodes[3][0];
    reg15=reg29*reg9; reg3=reg16+reg3; reg16=var_inter[2]*var_inter[1]; T reg30=reg14*pos_nodes[4][1]; reg27=reg5+reg27;
    reg5=reg25*reg10; reg11=reg6-reg11; reg1=reg23+reg1; reg23=reg14*pos_nodes[4][0]; T reg31=reg28*pos_nodes[3][2];
    reg18=reg8+reg18; reg8=reg16*pos_nodes[5][0]; T reg32=reg16*pos_nodes[5][1]; reg30=reg27+reg30; reg23=reg18+reg23;
    reg18=reg2*reg3; reg27=reg19*reg3; T reg33=reg13*reg10; T reg34=reg14*pos_nodes[4][2]; T reg35=reg4*reg3;
    reg5=reg15-reg5; reg15=reg11*reg3; reg1=reg31+reg1; reg31=reg22*reg9; T reg36=reg21*reg3;
    T reg37=reg22*reg10; T reg38=reg13*reg9; T reg39=reg4*reg9; reg34=reg1+reg34; reg1=reg16*pos_nodes[5][2];
    T reg40=reg19*reg9; T reg41=reg10*reg2; T reg42=reg10*reg21; reg27=reg33-reg27; reg35=reg37-reg35;
    reg15=reg5-reg15; reg32=reg30+reg32; reg18=reg38-reg18; reg36=reg31-reg36; reg8=reg23+reg8;
    reg32=pos[1]-reg32; reg18=reg18/reg15; reg39=reg42-reg39; reg36=reg36/reg15; reg8=pos[0]-reg8;
    reg27=reg27/reg15; reg25=reg25/reg15; reg29=reg29/reg15; reg35=reg35/reg15; reg40=reg41-reg40;
    reg1=reg34+reg1; reg39=reg39/reg15; reg11=reg11/reg15; reg1=pos[2]-reg1; reg15=reg40/reg15;
    reg18=reg18*reg8; reg25=reg25*reg8; reg27=reg27*reg32; reg29=reg29*reg32; reg36=reg36*reg8;
    reg35=reg35*reg32; reg15=reg1*reg15; reg35=reg36-reg35; reg39=reg1*reg39; reg25=reg29-reg25;
    reg11=reg1*reg11; reg18=reg27-reg18; var_inter[0]=reg25-reg11; var_inter[1]=reg39+reg35; var_inter[2]=reg18-reg15;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[0][0]*reg0; T reg2=pos_nodes[1][0]*var_inter[0]; T reg3=pos_nodes[1][2]*var_inter[0];
    T reg4=pos_nodes[0][2]*reg0; T reg5=pos_nodes[0][1]*reg0; T reg6=pos_nodes[1][1]*var_inter[0]; T reg7=pos_nodes[2][2]*var_inter[1]; reg3=reg4+reg3;
    reg4=pos_nodes[2][0]*var_inter[1]; reg2=reg1+reg2; reg1=pos_nodes[2][1]*var_inter[1]; reg6=reg5+reg6; reg5=1-var_inter[2];
    T reg8=pos_nodes[3][2]*reg0; T reg9=pos_nodes[3][1]*reg0; reg1=reg6+reg1; reg6=pos_nodes[2][2]*reg5; T reg10=pos_nodes[2][1]*reg5;
    reg7=reg3+reg7; reg3=reg5*pos_nodes[0][1]; T reg11=pos_nodes[0][2]*reg5; T reg12=reg5*pos_nodes[0][0]; T reg13=pos_nodes[2][0]*reg5;
    reg2=reg4+reg2; reg4=pos_nodes[3][0]*reg0; T reg14=var_inter[2]*pos_nodes[3][2]; reg6=reg6-reg11; T reg15=var_inter[0]*pos_nodes[4][1];
    reg1=reg9-reg1; reg9=var_inter[0]*pos_nodes[4][0]; reg2=reg4-reg2; reg10=reg10-reg3; reg13=reg13-reg12;
    reg4=var_inter[2]*pos_nodes[3][1]; reg7=reg8-reg7; reg8=var_inter[0]*pos_nodes[4][2]; T reg16=var_inter[2]*pos_nodes[3][0]; T reg17=var_inter[2]*pos_nodes[5][0];
    reg13=reg13-reg16; reg8=reg7+reg8; reg7=var_inter[1]*pos_nodes[5][2]; T reg18=var_inter[2]*pos_nodes[5][2]; reg6=reg6-reg14;
    reg9=reg2+reg9; reg2=pos_nodes[1][0]*reg5; T reg19=var_inter[1]*pos_nodes[5][0]; T reg20=var_inter[0]*reg5; T reg21=pos_nodes[1][1]*reg5;
    T reg22=reg5*reg0; reg10=reg10-reg4; T reg23=var_inter[2]*pos_nodes[5][1]; reg15=reg1+reg15; reg1=var_inter[1]*pos_nodes[5][1];
    reg7=reg8+reg7; reg3=reg21-reg3; reg23=reg10+reg23; reg18=reg6+reg18; reg1=reg15+reg1;
    reg6=reg22*pos_nodes[0][1]; reg12=reg2-reg12; reg19=reg9+reg19; reg2=pos_nodes[1][1]*reg20; reg8=pos_nodes[1][2]*reg5;
    reg9=pos_nodes[1][0]*reg20; reg17=reg13+reg17; reg10=reg22*pos_nodes[0][0]; reg13=var_inter[1]*reg5; reg15=reg22*pos_nodes[0][2];
    reg21=pos_nodes[1][2]*reg20; T reg24=var_inter[2]*reg0; T reg25=reg23*reg7; T reg26=reg1*reg18; T reg27=reg7*reg17;
    T reg28=pos_nodes[2][0]*reg13; reg9=reg10+reg9; reg10=var_inter[2]*pos_nodes[4][0]; T reg29=reg18*reg19; reg16=reg12-reg16;
    reg2=reg6+reg2; reg6=var_inter[2]*pos_nodes[4][1]; reg4=reg3-reg4; reg11=reg8-reg11; reg3=pos_nodes[2][1]*reg13;
    reg29=reg27-reg29; reg9=reg28+reg9; reg6=reg4+reg6; reg4=reg1*reg17; reg26=reg25-reg26;
    reg8=reg24*pos_nodes[3][0]; reg3=reg2+reg3; reg21=reg15+reg21; reg10=reg16+reg10; reg2=pos_nodes[2][2]*reg13;
    reg12=var_inter[2]*var_inter[0]; reg15=reg24*pos_nodes[3][1]; reg14=reg11-reg14; reg11=reg23*reg19; reg16=var_inter[2]*pos_nodes[4][2];
    reg11=reg4-reg11; reg28=reg12*pos_nodes[4][1]; reg8=reg9+reg8; reg9=reg12*pos_nodes[4][0]; reg2=reg21+reg2;
    reg21=reg24*pos_nodes[3][2]; T reg30=var_inter[2]*var_inter[1]; reg15=reg3+reg15; reg3=reg26*reg10; reg16=reg14+reg16;
    reg14=reg6*reg29; T reg31=reg30*pos_nodes[5][0]; reg9=reg8+reg9; reg21=reg2+reg21; reg2=reg12*pos_nodes[4][2];
    reg8=reg16*reg17; T reg32=reg18*reg10; T reg33=reg16*reg19; T reg34=reg7*reg10; T reg35=reg30*pos_nodes[5][1];
    T reg36=reg23*reg16; reg28=reg15+reg28; reg15=reg6*reg18; T reg37=reg1*reg16; T reg38=reg6*reg7;
    reg3=reg14-reg3; reg14=reg16*reg11; reg35=reg28+reg35; reg31=reg9+reg31; reg2=reg21+reg2;
    reg9=reg30*pos_nodes[5][2]; reg14=reg3-reg14; reg37=reg38-reg37; reg36=reg15-reg36; reg33=reg34-reg33;
    reg8=reg32-reg8; reg3=reg1*reg10; reg21=reg6*reg19; reg28=reg23*reg10; T reg39=reg6*reg17;
    reg31=pos[0]-reg31; reg39=reg28-reg39; reg9=reg2+reg9; reg26=reg26/reg14; reg37=reg37/reg14;
    reg36=reg36/reg14; reg35=pos[1]-reg35; reg29=reg29/reg14; reg33=reg33/reg14; reg8=reg8/reg14;
    reg21=reg3-reg21; reg37=reg31*reg37; reg11=reg11/reg14; reg39=reg39/reg14; reg33=reg35*reg33;
    reg36=reg31*reg36; reg29=reg35*reg29; reg14=reg21/reg14; reg9=pos[2]-reg9; reg8=reg35*reg8;
    reg26=reg31*reg26; reg33=reg37-reg33; reg39=reg9*reg39; reg11=reg9*reg11; reg36=reg8-reg36;
    reg14=reg9*reg14; reg26=reg29-reg26; var_inter[2]+=reg36-reg39; var_inter[1]+=reg14+reg33; var_inter[0]+=reg26-reg11;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=1-var_inter[2]; T reg2=reg1*reg0; T reg3=reg1*var_inter[0];
    T reg4=reg1*var_inter[1]; reg3=val[1]*reg3; reg2=val[0]*reg2; reg3=reg2+reg3; reg4=val[2]*reg4;
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
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[0]; T reg1=var_inter[2]-0.21132486540518707896; T reg2=2*var_inter[1]; T reg3=1-var_inter[2]; reg1=reg1/0.57735026918962573106;
    T reg4=reg2+reg0; T reg5=reg3-0.21132486540518707896; reg2=1-reg2; reg1=1-reg1; reg4=reg4-1;
    reg5=reg5/0.57735026918962573106; reg0=1-reg0; T reg6=reg2*reg1; T reg7=reg1*reg4; reg5=1-reg5;
    reg1=reg1*reg0; reg7=val[1]*reg7; reg6=val[0]*reg6; reg7=reg6+reg7; reg1=val[2]*reg1;
    reg6=reg2*reg5; reg6=val[3]*reg6; T reg8=reg4*reg5; reg1=reg7+reg1; reg6=reg1+reg6;
    reg8=val[4]*reg8; reg5=reg0*reg5; reg8=reg6+reg8; reg5=val[5]*reg5; res=reg8+reg5;

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Wedge &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; T reg2=reg1+reg0; reg2=reg2-1; reg0=1-reg0;
    reg1=1-reg1; T reg3=val[0]*reg2; T reg4=val[1]*reg0; reg4=reg3+reg4; reg3=val[2]*reg1;
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
    T reg0=1-var_inter[0]; T reg1=1-var_inter[2]; reg0=reg0-var_inter[1]; T reg2=reg1*reg0; res[0]=reg2;
    T reg3=reg1*var_inter[0]; res[1]=reg3; T reg4=reg1*var_inter[1]; res[2]=reg4; reg0=var_inter[2]*reg0;
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=elem.pos(0)[2]*reg0; T reg2=var_inter[0]*elem.pos(1)[2]; T reg3=elem.pos(0)[1]*reg0;
    T reg4=var_inter[0]*elem.pos(1)[1]; T reg5=var_inter[1]*elem.pos(2)[1]; T reg6=reg2+reg1; T reg7=1-var_inter[2]; T reg8=var_inter[1]*elem.pos(2)[2];
    T reg9=reg3+reg4; T reg10=reg7*elem.pos(2)[2]; T reg11=elem.pos(3)[2]*reg0; T reg12=reg8+reg6; T reg13=reg7*elem.pos(0)[1];
    T reg14=reg7*elem.pos(1)[2]; T reg15=reg7*elem.pos(1)[1]; T reg16=reg7*elem.pos(2)[1]; T reg17=reg7*elem.pos(0)[2]; T reg18=elem.pos(3)[1]*reg0;
    T reg19=reg9+reg5; T reg20=var_inter[0]*elem.pos(4)[1]; reg11=reg11-reg12; reg18=reg18-reg19; T reg21=var_inter[0]*elem.pos(1)[0];
    reg15=reg15-reg13; T reg22=var_inter[0]*elem.pos(4)[2]; reg14=reg14-reg17; T reg23=var_inter[2]*elem.pos(3)[1]; reg10=reg10-reg17;
    T reg24=elem.pos(0)[0]*reg0; reg16=reg16-reg13; T reg25=var_inter[2]*elem.pos(3)[2]; T reg26=reg7*elem.pos(1)[0]; T reg27=var_inter[1]*elem.pos(5)[2];
    reg11=reg22+reg11; reg16=reg16-reg23; reg22=var_inter[1]*elem.pos(5)[1]; T reg28=var_inter[2]*elem.pos(4)[2]; reg20=reg18+reg20;
    reg15=reg15-reg23; reg18=reg7*elem.pos(0)[0]; T reg29=var_inter[1]*elem.pos(2)[0]; T reg30=var_inter[2]*elem.pos(5)[2]; reg10=reg10-reg25;
    T reg31=var_inter[2]*elem.pos(4)[1]; T reg32=reg21+reg24; T reg33=var_inter[2]*elem.pos(5)[1]; reg14=reg14-reg25; T reg34=reg7*elem.pos(2)[0];
    reg30=reg10+reg30; reg34=reg34-reg18; reg26=reg26-reg18; reg16=reg33+reg16; reg27=reg11+reg27;
    reg15=reg31+reg15; reg10=elem.pos(3)[0]*reg0; reg28=reg14+reg28; reg11=var_inter[2]*elem.pos(3)[0]; reg20=reg22+reg20;
    reg14=reg32+reg29; reg22=reg15*reg27; reg26=reg26-reg11; reg31=reg20*reg28; reg33=reg20*reg30;
    T reg35=var_inter[0]*elem.pos(4)[0]; T reg36=reg16*reg27; T reg37=var_inter[2]*elem.pos(4)[0]; reg10=reg10-reg14; reg34=reg34-reg11;
    T reg38=var_inter[2]*elem.pos(5)[0]; reg35=reg10+reg35; reg33=reg36-reg33; reg10=reg16*reg28; reg36=var_inter[1]*elem.pos(5)[0];
    reg26=reg37+reg26; reg37=reg15*reg30; reg31=reg22-reg31; reg34=reg38+reg34; reg22=reg26*reg33;
    reg38=reg31*reg34; reg36=reg35+reg36; reg10=reg37-reg10; reg38=reg22-reg38; reg22=reg10*reg36;
    reg22=reg38+reg22; return reg22;

}
}
#endif // LMT_WEDGE
