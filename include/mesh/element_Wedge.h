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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[0][1]*reg0; T reg2=pos_nodes[0][0]*reg0; T reg3=pos_nodes[1][0]*var_inter[0];
    T reg4=pos_nodes[1][1]*var_inter[0]; T reg5=var_inter[0]*pos_nodes[1][2]; T reg6=pos_nodes[0][2]*reg0; T reg7=var_inter[1]*pos_nodes[2][2]; reg6=reg5+reg6;
    reg5=var_inter[1]*pos_nodes[2][1]; reg4=reg1+reg4; reg1=1-var_inter[2]; reg2=reg3+reg2; reg3=var_inter[1]*pos_nodes[2][0];
    T reg8=reg0*pos_nodes[3][1]; reg3=reg2+reg3; reg2=reg1*pos_nodes[2][1]; T reg9=reg0*pos_nodes[3][0]; reg5=reg4+reg5;
    reg4=pos_nodes[0][2]*reg1; T reg10=pos_nodes[0][1]*reg1; T reg11=reg1*pos_nodes[2][2]; T reg12=reg0*pos_nodes[3][2]; T reg13=reg1*pos_nodes[2][0];
    reg7=reg6+reg7; reg6=pos_nodes[0][0]*reg1; reg7=reg12-reg7; reg13=reg13-reg6; reg12=var_inter[0]*pos_nodes[4][2];
    reg11=reg11-reg4; T reg14=var_inter[2]*pos_nodes[3][0]; T reg15=var_inter[2]*pos_nodes[3][2]; T reg16=var_inter[0]*pos_nodes[4][1]; reg5=reg8-reg5;
    reg3=reg9-reg3; reg8=var_inter[0]*pos_nodes[4][0]; reg2=reg2-reg10; reg9=var_inter[2]*pos_nodes[3][1]; reg8=reg3+reg8;
    reg3=var_inter[1]*pos_nodes[5][0]; T reg17=pos_nodes[1][0]*reg1; T reg18=reg1*var_inter[0]; T reg19=reg1*reg0; T reg20=var_inter[1]*pos_nodes[5][2];
    reg12=reg7+reg12; reg13=reg13-reg14; reg7=var_inter[2]*pos_nodes[5][2]; reg11=reg11-reg15; T reg21=pos_nodes[1][1]*reg1;
    reg16=reg5+reg16; reg5=var_inter[1]*pos_nodes[5][1]; T reg22=var_inter[2]*pos_nodes[5][0]; T reg23=var_inter[2]*pos_nodes[5][1]; reg2=reg2-reg9;
    reg20=reg12+reg20; reg12=var_inter[1]*reg1; reg23=reg2+reg23; reg7=reg11+reg7; reg5=reg16+reg5;
    reg2=pos_nodes[0][1]*reg19; reg11=pos_nodes[1][1]*reg18; reg3=reg8+reg3; reg8=pos_nodes[1][0]*reg18; reg16=pos_nodes[0][0]*reg19;
    reg22=reg13+reg22; reg6=reg17-reg6; reg13=reg1*pos_nodes[1][2]; reg10=reg21-reg10; reg17=reg22*reg20;
    reg21=reg5*reg7; T reg24=reg3*reg7; reg16=reg8+reg16; reg8=var_inter[2]*reg0; T reg25=reg23*reg20;
    T reg26=var_inter[2]*pos_nodes[4][0]; reg14=reg6-reg14; reg6=var_inter[2]*pos_nodes[4][1]; T reg27=pos_nodes[0][2]*reg19; T reg28=reg18*pos_nodes[1][2];
    T reg29=reg12*pos_nodes[2][0]; reg11=reg2+reg11; reg2=reg12*pos_nodes[2][1]; reg4=reg13-reg4; reg9=reg10-reg9;
    reg10=reg22*reg5; reg21=reg25-reg21; reg24=reg17-reg24; reg13=var_inter[2]*var_inter[0]; T reg30=reg3*reg23;
    T reg31=var_inter[2]*pos_nodes[4][2]; reg26=reg14+reg26; reg15=reg4-reg15; reg4=reg8*pos_nodes[3][0]; reg14=reg8*pos_nodes[3][1];
    reg6=reg9+reg6; reg2=reg11+reg2; reg29=reg16+reg29; reg9=reg12*pos_nodes[2][2]; reg27=reg28+reg27;
    reg11=reg13*pos_nodes[4][1]; reg14=reg2+reg14; reg30=reg10-reg30; reg2=reg6*reg24; reg31=reg15+reg31;
    reg15=reg13*pos_nodes[4][0]; reg16=reg8*pos_nodes[3][2]; reg9=reg27+reg9; reg4=reg29+reg4; reg27=reg26*reg21;
    reg28=var_inter[1]*var_inter[2]; reg29=reg28*pos_nodes[5][1]; reg11=reg14+reg11; reg14=reg13*pos_nodes[4][2]; reg16=reg9+reg16;
    reg9=reg22*reg31; T reg32=reg26*reg7; reg27=reg2-reg27; reg2=reg3*reg31; T reg33=reg26*reg20;
    reg15=reg4+reg15; reg4=reg6*reg20; T reg34=reg31*reg30; T reg35=reg5*reg31; T reg36=reg23*reg31;
    T reg37=reg28*pos_nodes[5][0]; T reg38=reg6*reg7; reg14=reg16+reg14; reg16=reg28*pos_nodes[5][2]; T reg39=reg22*reg6;
    reg37=reg15+reg37; reg34=reg27-reg34; reg15=reg26*reg23; reg2=reg33-reg2; reg9=reg32-reg9;
    reg35=reg4-reg35; reg29=reg11+reg29; reg36=reg38-reg36; reg11=reg26*reg5; reg27=reg3*reg6;
    reg29=pos[1]-reg29; reg16=reg14+reg16; reg37=pos[0]-reg37; reg21=reg21/reg34; reg35=reg35/reg34;
    reg36=reg36/reg34; reg24=reg24/reg34; reg2=reg2/reg34; reg9=reg9/reg34; reg27=reg11-reg27;
    reg39=reg15-reg39; reg30=reg30/reg34; reg27=reg27/reg34; reg34=reg39/reg34; reg21=reg37*reg21;
    reg24=reg29*reg24; reg16=pos[2]-reg16; reg9=reg29*reg9; reg36=reg37*reg36; reg2=reg29*reg2;
    reg35=reg37*reg35; reg30=reg16*reg30; reg21=reg24-reg21; reg36=reg9-reg36; reg34=reg16*reg34;
    reg2=reg35-reg2; reg27=reg16*reg27; var_inter[2]=reg36-reg34; var_inter[1]=reg27+reg2; var_inter[0]=reg21-reg30;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[1][2]*var_inter[0]; T reg2=pos_nodes[0][2]*reg0; T reg3=pos_nodes[1][1]*var_inter[0];
    T reg4=pos_nodes[0][1]*reg0; T reg5=pos_nodes[1][0]*var_inter[0]; T reg6=pos_nodes[0][0]*reg0; T reg7=pos_nodes[2][2]*var_inter[1]; reg1=reg2+reg1;
    reg2=pos_nodes[2][0]*var_inter[1]; reg5=reg6+reg5; reg6=1-var_inter[2]; reg3=reg4+reg3; reg4=pos_nodes[2][1]*var_inter[1];
    T reg8=reg0*pos_nodes[3][1]; T reg9=pos_nodes[2][1]*reg6; reg3=reg4+reg3; reg4=pos_nodes[0][2]*reg6; reg5=reg2+reg5;
    reg2=pos_nodes[0][1]*reg6; T reg10=reg6*pos_nodes[2][2]; T reg11=reg0*pos_nodes[3][0]; T reg12=reg0*pos_nodes[3][2]; T reg13=pos_nodes[2][0]*reg6;
    reg1=reg7+reg1; reg7=pos_nodes[0][0]*reg6; T reg14=var_inter[2]*pos_nodes[3][1]; reg9=reg9-reg2; reg3=reg8-reg3;
    reg8=var_inter[0]*pos_nodes[4][1]; T reg15=var_inter[2]*pos_nodes[3][2]; T reg16=var_inter[0]*pos_nodes[4][0]; reg5=reg11-reg5; reg11=var_inter[0]*pos_nodes[4][2];
    reg1=reg12-reg1; reg10=reg10-reg4; reg12=var_inter[2]*pos_nodes[3][0]; reg13=reg13-reg7; reg11=reg1+reg11;
    reg1=pos_nodes[5][1]*var_inter[1]; reg8=reg3+reg8; reg3=pos_nodes[5][2]*var_inter[1]; T reg17=var_inter[2]*pos_nodes[5][1]; reg9=reg9-reg14;
    reg10=reg10-reg15; T reg18=var_inter[2]*pos_nodes[5][2]; T reg19=reg6*var_inter[0]; T reg20=pos_nodes[1][1]*reg6; T reg21=pos_nodes[1][0]*reg6;
    reg13=reg13-reg12; T reg22=var_inter[2]*pos_nodes[5][0]; T reg23=reg6*reg0; reg16=reg5+reg16; reg5=pos_nodes[5][0]*var_inter[1];
    reg5=reg16+reg5; reg1=reg8+reg1; reg8=pos_nodes[0][1]*reg23; reg16=pos_nodes[1][1]*reg19; T reg24=pos_nodes[1][2]*reg6;
    reg22=reg13+reg22; reg18=reg10+reg18; reg10=reg6*var_inter[1]; reg7=reg21-reg7; reg3=reg11+reg3;
    reg2=reg20-reg2; reg11=pos_nodes[0][0]*reg23; reg13=pos_nodes[1][0]*reg19; reg17=reg9+reg17; reg9=reg5*reg18;
    reg20=reg22*reg3; reg21=reg1*reg18; T reg25=reg17*reg3; T reg26=pos_nodes[1][2]*reg19; T reg27=pos_nodes[0][2]*reg23;
    reg14=reg2-reg14; reg2=var_inter[2]*pos_nodes[4][1]; reg12=reg7-reg12; reg7=var_inter[2]*pos_nodes[4][0]; T reg28=var_inter[2]*reg0;
    reg4=reg24-reg4; reg24=pos_nodes[2][0]*reg10; T reg29=pos_nodes[2][1]*reg10; reg13=reg11+reg13; reg16=reg8+reg16;
    reg8=reg5*reg17; reg9=reg20-reg9; reg11=reg22*reg1; reg21=reg25-reg21; reg13=reg24+reg13;
    reg26=reg27+reg26; reg16=reg29+reg16; reg24=reg28*pos_nodes[3][1]; reg27=reg10*pos_nodes[2][2]; reg2=reg14+reg2;
    reg14=reg28*pos_nodes[3][0]; reg15=reg4-reg15; reg4=var_inter[2]*pos_nodes[4][2]; reg7=reg12+reg7; reg12=var_inter[2]*var_inter[0];
    reg8=reg11-reg8; reg14=reg13+reg14; reg13=reg2*reg9; reg4=reg15+reg4; reg15=var_inter[2]*var_inter[1];
    reg29=reg7*reg21; T reg30=reg12*pos_nodes[4][0]; T reg31=reg28*pos_nodes[3][2]; reg26=reg27+reg26; reg27=reg12*pos_nodes[4][1];
    reg24=reg16+reg24; reg16=reg22*reg4; T reg32=reg7*reg18; T reg33=reg5*reg4; T reg34=reg7*reg3;
    T reg35=reg17*reg4; T reg36=reg2*reg18; T reg37=reg1*reg4; T reg38=reg2*reg3; T reg39=reg4*reg8;
    reg29=reg13-reg29; reg31=reg26+reg31; reg13=reg12*pos_nodes[4][2]; reg30=reg14+reg30; reg14=reg15*pos_nodes[5][0];
    reg26=reg15*pos_nodes[5][1]; reg27=reg24+reg27; reg33=reg34-reg33; reg16=reg32-reg16; reg13=reg31+reg13;
    reg24=reg15*pos_nodes[5][2]; reg35=reg36-reg35; reg31=reg7*reg1; T reg40=reg5*reg2; reg37=reg38-reg37;
    T reg41=reg22*reg2; reg39=reg29-reg39; reg29=reg7*reg17; reg26=reg27+reg26; reg14=reg30+reg14;
    reg41=reg29-reg41; reg40=reg31-reg40; reg16=reg16/reg39; reg14=pos[0]-reg14; reg33=reg33/reg39;
    reg9=reg9/reg39; reg35=reg35/reg39; reg37=reg37/reg39; reg21=reg21/reg39; reg26=pos[1]-reg26;
    reg24=reg13+reg24; reg16=reg26*reg16; reg35=reg14*reg35; reg33=reg26*reg33; reg37=reg14*reg37;
    reg9=reg26*reg9; reg21=reg14*reg21; reg41=reg41/reg39; reg24=pos[2]-reg24; reg40=reg40/reg39;
    reg39=reg8/reg39; reg21=reg9-reg21; reg39=reg24*reg39; reg40=reg24*reg40; reg33=reg37-reg33;
    reg41=reg24*reg41; reg35=reg16-reg35; var_inter[0]+=reg21-reg39; var_inter[1]+=reg40+reg33; var_inter[2]+=reg35-reg41;

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
    T reg4=var_inter[1]*reg1; reg3=val[1]*reg3; reg2=val[0]*reg2; reg3=reg2+reg3; reg4=val[2]*reg4;
    reg0=var_inter[2]*reg0; reg4=reg3+reg4; reg0=val[3]*reg0; reg2=var_inter[0]*var_inter[2]; reg0=reg4+reg0;
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
    reg8=val[1]*reg8; reg5=1-reg5; reg1=reg1*reg7; T reg10=reg6*reg5; reg1=val[2]*reg1;
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
    reg8=val[1]*reg8; reg5=1-reg5; reg1=reg1*reg7; T reg10=reg6*reg5; reg1=val[2]*reg1;
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
    T reg4=var_inter[0]*elem.pos(1)[2]; T reg5=reg2+reg1; T reg6=1-var_inter[2]; T reg7=var_inter[1]*elem.pos(2)[2]; T reg8=var_inter[1]*elem.pos(2)[1];
    T reg9=reg4+reg3; T reg10=reg6*elem.pos(2)[2]; T reg11=elem.pos(1)[2]*reg6; T reg12=reg6*elem.pos(0)[1]; T reg13=elem.pos(0)[2]*reg6;
    T reg14=elem.pos(1)[1]*reg6; T reg15=reg6*elem.pos(2)[1]; T reg16=reg0*elem.pos(3)[2]; T reg17=reg8+reg5; T reg18=reg7+reg9;
    T reg19=reg0*elem.pos(3)[1]; reg14=reg14-reg12; reg16=reg16-reg18; reg15=reg15-reg12; T reg20=reg0*elem.pos(0)[0];
    T reg21=var_inter[0]*elem.pos(4)[2]; reg10=reg10-reg13; T reg22=var_inter[0]*elem.pos(1)[0]; T reg23=var_inter[2]*elem.pos(3)[1]; T reg24=var_inter[0]*elem.pos(4)[1];
    reg11=reg11-reg13; reg19=reg19-reg17; T reg25=var_inter[2]*elem.pos(3)[2]; reg21=reg16+reg21; reg24=reg19+reg24;
    reg16=var_inter[1]*elem.pos(2)[0]; reg19=var_inter[1]*elem.pos(5)[1]; T reg26=var_inter[2]*elem.pos(5)[1]; reg15=reg15-reg23; T reg27=var_inter[1]*elem.pos(5)[2];
    T reg28=elem.pos(1)[0]*reg6; T reg29=var_inter[2]*elem.pos(5)[2]; T reg30=reg6*elem.pos(0)[0]; reg10=reg10-reg25; reg11=reg11-reg25;
    T reg31=reg22+reg20; T reg32=var_inter[2]*elem.pos(4)[2]; T reg33=var_inter[2]*elem.pos(4)[1]; reg14=reg14-reg23; T reg34=elem.pos(2)[0]*reg6;
    reg28=reg28-reg30; T reg35=var_inter[2]*elem.pos(3)[0]; reg21=reg27+reg21; reg10=reg29+reg10; reg24=reg19+reg24;
    reg19=reg31+reg16; reg32=reg11+reg32; reg11=reg0*elem.pos(3)[0]; reg33=reg14+reg33; reg26=reg15+reg26;
    reg34=reg34-reg30; reg14=var_inter[2]*elem.pos(4)[0]; reg15=var_inter[2]*elem.pos(5)[0]; reg34=reg34-reg35; reg27=reg24*reg32;
    reg29=reg33*reg21; T reg36=reg26*reg21; reg28=reg28-reg35; T reg37=var_inter[0]*elem.pos(4)[0]; reg11=reg11-reg19;
    T reg38=reg10*reg24; T reg39=reg10*reg33; reg27=reg29-reg27; reg29=var_inter[1]*elem.pos(5)[0]; reg38=reg36-reg38;
    reg14=reg28+reg14; reg37=reg11+reg37; reg15=reg34+reg15; reg11=reg32*reg26; reg28=reg27*reg15;
    reg29=reg37+reg29; reg34=reg14*reg38; reg11=reg39-reg11; reg36=reg29*reg11; reg28=reg34-reg28;
    reg28=reg36+reg28; return reg28;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Wedge,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.5*elem.pos(2)[1]; T reg1=0.5*elem.pos(2)[2]; T reg2=0.78867513459481286553*elem.pos(1)[2]; T reg3=0.78867513459481286553*elem.pos(1)[1]; T reg4=0.5*elem.pos(0)[1];
    T reg5=0.5*elem.pos(1)[1]; T reg6=0.78867513459481286553*elem.pos(0)[2]; T reg7=0.78867513459481286553*elem.pos(2)[2]; T reg8=0.5*elem.pos(0)[2]; T reg9=0.5*elem.pos(1)[2];
    T reg10=0.78867513459481286553*elem.pos(0)[1]; T reg11=0.78867513459481286553*elem.pos(2)[1]; T reg12=reg9+reg1; T reg13=0.21132486540518713447*elem.pos(3)[1]; reg2=reg2-reg6;
    T reg14=0.5*elem.pos(3)[2]; reg3=reg3-reg10; T reg15=0.5*elem.pos(4)[1]; T reg16=reg5+reg4; T reg17=0.5*elem.pos(3)[1];
    reg9=reg9+reg8; T reg18=0.21132486540518713447*elem.pos(3)[2]; reg6=reg7-reg6; reg7=0.5*elem.pos(4)[2]; reg10=reg11-reg10;
    reg5=reg5+reg0; reg11=0.21132486540518713447*elem.pos(0)[2]; reg9=reg14-reg9; T reg19=0.21132486540518713447*elem.pos(2)[2]; T reg20=0.78867513459481286553*elem.pos(1)[0];
    T reg21=0.78867513459481286553*elem.pos(0)[0]; reg6=reg6-reg18; T reg22=0.21132486540518713447*elem.pos(5)[2]; T reg23=0.21132486540518713447*elem.pos(0)[1]; T reg24=0.21132486540518713447*elem.pos(2)[1];
    T reg25=0.21132486540518713447*elem.pos(1)[2]; reg0=reg4+reg0; reg16=reg17-reg16; reg1=reg8+reg1; reg4=0.78867513459481286553*elem.pos(2)[0];
    reg8=0.5*elem.pos(5)[1]; T reg26=reg15-reg5; reg3=reg3-reg13; T reg27=0.21132486540518713447*elem.pos(4)[1]; T reg28=0.21132486540518713447*elem.pos(1)[1];
    reg18=reg2-reg18; reg2=0.21132486540518713447*elem.pos(4)[2]; T reg29=0.21132486540518713447*elem.pos(5)[1]; reg13=reg10-reg13; reg10=0.5*elem.pos(5)[2];
    T reg30=reg7-reg12; T reg31=0.21132486540518713447*elem.pos(3)[0]; reg25=reg25-reg11; reg20=reg20-reg21; reg29=reg13+reg29;
    reg13=0.78867513459481286553*elem.pos(3)[2]; reg11=reg19-reg11; reg19=0.78867513459481286553*elem.pos(3)[1]; reg24=reg24-reg23; reg0=reg17-reg0;
    reg1=reg14-reg1; reg14=0.5*elem.pos(2)[0]; reg26=reg26+reg8; reg30=reg30+reg10; reg23=reg28-reg23;
    reg17=0.5*elem.pos(0)[0]; reg28=0.5*elem.pos(1)[0]; reg2=reg18+reg2; reg27=reg3+reg27; reg21=reg4-reg21;
    reg15=reg16+reg15; reg22=reg6+reg22; reg7=reg9+reg7; reg0=reg8+reg0; reg1=reg10+reg1;
    reg3=reg2*reg26; reg4=reg27*reg30; reg6=reg22*reg26; reg8=reg29*reg30; reg9=0.5*elem.pos(4)[0];
    reg10=reg28+reg17; reg16=0.5*elem.pos(3)[0]; reg20=reg20-reg31; reg18=0.21132486540518713447*elem.pos(4)[0]; T reg32=reg15*reg2;
    T reg33=reg7*reg27; T reg34=0.21132486540518713447*elem.pos(5)[0]; reg31=reg21-reg31; reg21=reg22*reg15; T reg35=reg29*reg7;
    reg28=reg28+reg14; reg25=reg25-reg13; T reg36=0.78867513459481286553*elem.pos(4)[1]; T reg37=0.21132486540518713447*elem.pos(1)[0]; reg13=reg11-reg13;
    reg23=reg23-reg19; reg11=0.21132486540518713447*elem.pos(0)[0]; T reg38=0.78867513459481286553*elem.pos(4)[2]; T reg39=0.78867513459481286553*elem.pos(5)[1]; T reg40=0.78867513459481286553*elem.pos(5)[2];
    reg19=reg24-reg19; reg24=0.21132486540518713447*elem.pos(2)[0]; reg39=reg19+reg39; reg10=reg16-reg10; reg32=reg33-reg32;
    reg40=reg13+reg40; reg24=reg24-reg11; reg38=reg25+reg38; reg34=reg31+reg34; reg21=reg35-reg21;
    reg36=reg23+reg36; reg13=0.39433756729740643276*elem.pos(1)[2]; reg14=reg17+reg14; reg17=reg2*reg0; reg19=reg27*reg1;
    reg23=reg22*reg0; reg25=0.39433756729740643276*elem.pos(0)[1]; reg31=reg29*reg1; reg33=0.5*elem.pos(5)[0]; reg35=reg9-reg28;
    reg3=reg4-reg3; reg11=reg37-reg11; reg4=0.78867513459481286553*elem.pos(3)[0]; reg37=0.39433756729740643276*elem.pos(1)[1]; reg6=reg8-reg6;
    reg8=0.39433756729740643276*elem.pos(2)[1]; T reg41=0.39433756729740643276*elem.pos(2)[0]; reg2=reg29*reg2; reg27=reg22*reg27; reg22=0.39433756729740643276*elem.pos(0)[2];
    reg29=0.39433756729740643276*elem.pos(2)[2]; T reg42=0.39433756729740643276*elem.pos(0)[0]; T reg43=0.39433756729740643276*elem.pos(1)[0]; reg18=reg20+reg18; reg14=reg16-reg14;
    reg17=reg19-reg17; reg23=reg31-reg23; reg16=reg37+reg25; reg19=0.10566243270259356724*elem.pos(3)[1]; reg35=reg35+reg33;
    reg20=0.10566243270259356724*elem.pos(4)[1]; reg3=reg34*reg3; reg31=reg13+reg29; reg32=reg34*reg32; reg6=reg18*reg6;
    T reg44=reg43+reg42; reg37=reg37+reg8; reg9=reg10+reg9; reg10=0.10566243270259356724*elem.pos(4)[0]; reg2=reg27-reg2;
    reg43=reg43+reg41; reg27=0.10566243270259356724*elem.pos(3)[0]; T reg45=reg15*reg40; reg15=reg15*reg38; T reg46=reg7*reg39;
    reg24=reg24-reg4; T reg47=0.78867513459481286553*elem.pos(5)[0]; T reg48=0.10566243270259356724*elem.pos(3)[2]; T reg49=0.78867513459481286553*elem.pos(4)[0]; reg4=reg11-reg4;
    reg7=reg7*reg36; reg11=0.10566243270259356724*elem.pos(4)[2]; reg21=reg18*reg21; reg13=reg13+reg22; T reg50=0.10566243270259356724*elem.pos(5)[1];
    T reg51=0.10566243270259356724*elem.pos(1)[2]; reg47=reg24+reg47; reg37=reg20+reg37; reg24=0.10566243270259356724*elem.pos(5)[0]; reg43=reg10+reg43;
    reg29=reg22+reg29; reg22=0.10566243270259356724*elem.pos(0)[2]; reg45=reg46-reg45; reg15=reg7-reg15; reg7=reg40*reg36;
    reg3=reg6-reg3; reg6=reg39*reg38; reg49=reg4+reg49; reg4=reg2*reg35; reg41=reg42+reg41;
    reg16=reg16+reg19; reg42=0.10566243270259356724*elem.pos(0)[0]; reg46=0.10566243270259356724*elem.pos(1)[0]; reg23=reg18*reg23; reg17=reg34*reg17;
    reg14=reg33+reg14; reg18=0.10566243270259356724*elem.pos(1)[1]; reg33=reg30*reg39; reg32=reg21-reg32; reg21=reg9*reg2;
    reg34=reg26*reg38; reg26=reg26*reg40; T reg52=0.10566243270259356724*elem.pos(0)[1]; reg31=reg11+reg31; reg44=reg44+reg27;
    reg8=reg25+reg8; reg13=reg13+reg48; reg25=0.10566243270259356724*elem.pos(5)[2]; reg30=reg30*reg36; reg36=reg1*reg36;
    reg45=reg49*reg45; T reg53=0.39433756729740643276*elem.pos(3)[1]; reg40=reg0*reg40; reg39=reg1*reg39; reg1=reg18+reg52;
    reg41=reg27+reg41; reg27=reg51+reg22; reg38=reg0*reg38; reg11=reg13+reg11; reg17=reg23-reg17;
    reg0=0.39433756729740643276*elem.pos(3)[2]; reg2=reg2*reg14; reg26=reg33-reg26; reg13=reg46+reg42; reg23=0.39433756729740643276*elem.pos(3)[0];
    reg15=reg47*reg15; reg33=0.10566243270259356724*elem.pos(2)[2]; T reg54=0.10566243270259356724*elem.pos(2)[1]; reg6=reg7-reg6; reg7=0.10566243270259356724*elem.pos(2)[0];
    reg29=reg48+reg29; reg4=reg3+reg4; reg34=reg30-reg34; reg21=reg32+reg21; reg43=reg43+reg24;
    reg8=reg19+reg8; reg20=reg16+reg20; reg31=reg31+reg25; reg10=reg44+reg10; reg37=reg37+reg50;
    reg2=reg17+reg2; reg27=reg27+reg0; reg3=0.39433756729740643276*elem.pos(4)[2]; reg9=reg9*reg6; reg37=reg37*reg4;
    reg13=reg13+reg23; reg16=0.39433756729740643276*elem.pos(4)[0]; reg15=reg45-reg15; reg51=reg51+reg33; reg10=reg10*reg21;
    reg18=reg18+reg54; reg29=reg25+reg29; reg17=0.39433756729740643276*elem.pos(4)[1]; reg38=reg36-reg38; reg20=reg20*reg21;
    reg11=reg11*reg21; reg31=reg31*reg4; reg26=reg49*reg26; reg1=reg1+reg53; reg43=reg43*reg4;
    reg40=reg39-reg40; reg8=reg50+reg8; reg41=reg24+reg41; reg34=reg47*reg34; reg46=reg46+reg7;
    reg54=reg52+reg54; reg27=reg27+reg3; reg19=0.39433756729740643276*elem.pos(5)[1]; reg34=reg26-reg34; reg35=reg35*reg6;
    reg4=0.083333333333333328707*reg4; reg29=reg29*reg2; reg10=0.083333333333333328707*reg10; reg37=0.083333333333333328707*reg37; reg20=0.083333333333333328707*reg20;
    reg31=0.083333333333333328707*reg31; reg21=0.083333333333333328707*reg21; reg8=reg8*reg2; reg7=reg42+reg7; reg46=reg16+reg46;
    reg43=0.083333333333333328707*reg43; reg33=reg22+reg33; reg40=reg49*reg40; reg11=0.083333333333333328707*reg11; reg18=reg17+reg18;
    reg38=reg47*reg38; reg51=reg3+reg51; reg3=0.39433756729740643276*elem.pos(5)[2]; reg16=reg13+reg16; reg13=0.39433756729740643276*elem.pos(5)[0];
    reg9=reg15+reg9; reg41=reg41*reg2; reg17=reg1+reg17; reg7=reg23+reg7; reg16=reg16*reg9;
    reg46=reg46+reg13; reg4=reg21+reg4; reg6=reg14*reg6; reg38=reg40-reg38; reg35=reg34+reg35;
    reg2=0.083333333333333328707*reg2; reg18=reg18+reg19; reg54=reg53+reg54; reg17=reg17*reg9; reg8=0.083333333333333328707*reg8;
    reg37=reg20+reg37; reg43=reg10+reg43; reg41=0.083333333333333328707*reg41; reg33=reg0+reg33; reg51=reg51+reg3;
    reg27=reg27*reg9; reg29=0.083333333333333328707*reg29; reg31=reg11+reg31; reg51=reg51*reg35; reg33=reg3+reg33;
    reg27=0.083333333333333328707*reg27; reg7=reg13+reg7; reg46=reg46*reg35; reg6=reg38+reg6; reg54=reg19+reg54;
    reg29=reg31+reg29; reg18=reg18*reg35; reg2=reg4+reg2; reg9=0.083333333333333328707*reg9; reg41=reg43+reg41;
    reg16=0.083333333333333328707*reg16; reg8=reg37+reg8; reg17=0.083333333333333328707*reg17; reg17=reg8+reg17; reg18=0.083333333333333328707*reg18;
    reg9=reg2+reg9; reg7=reg7*reg6; reg35=0.083333333333333328707*reg35; reg27=reg29+reg27; reg51=0.083333333333333328707*reg51;
    reg33=reg33*reg6; reg54=reg54*reg6; reg16=reg41+reg16; reg46=0.083333333333333328707*reg46; reg54=0.083333333333333328707*reg54;
    reg7=0.083333333333333328707*reg7; reg35=reg9+reg35; reg6=0.083333333333333328707*reg6; reg46=reg16+reg46; reg51=reg27+reg51;
    reg18=reg17+reg18; reg33=0.083333333333333328707*reg33; reg6=reg35+reg6; reg7=reg46+reg7; reg54=reg18+reg54;
    reg33=reg51+reg33; res[0]=reg7/reg6; res[1]=reg54/reg6; res[2]=reg33/reg6;

    return res;
}
}
#endif // LMT_WEDGE
