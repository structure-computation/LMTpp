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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[1][0]*var_inter[0]; T reg2=pos_nodes[0][0]*reg0; T reg3=reg0*pos_nodes[0][1];
    T reg4=pos_nodes[1][1]*var_inter[0]; T reg5=1-var_inter[2]; T reg6=reg0*pos_nodes[0][2]; T reg7=pos_nodes[1][2]*var_inter[0]; reg4=reg3+reg4;
    reg3=pos_nodes[2][1]*var_inter[1]; reg1=reg2+reg1; reg2=pos_nodes[2][0]*var_inter[1]; T reg8=pos_nodes[2][2]*var_inter[1]; reg7=reg6+reg7;
    reg6=reg0*reg5; T reg9=reg5*var_inter[0]; T reg10=reg5*pos_nodes[0][1]; reg8=reg7+reg8; reg7=pos_nodes[3][2]*reg0;
    T reg11=reg5*pos_nodes[2][2]; T reg12=reg5*pos_nodes[0][2]; T reg13=reg9*pos_nodes[1][1]; T reg14=reg6*pos_nodes[0][1]; reg3=reg4+reg3;
    reg4=reg5*pos_nodes[2][1]; T reg15=reg5*var_inter[1]; T reg16=pos_nodes[3][1]*reg0; reg2=reg1+reg2; reg1=pos_nodes[0][0]*reg6;
    T reg17=reg9*pos_nodes[1][0]; T reg18=pos_nodes[0][0]*reg5; T reg19=reg5*pos_nodes[2][0]; T reg20=pos_nodes[3][0]*reg0; T reg21=pos_nodes[4][1]*var_inter[0];
    reg19=reg19-reg18; T reg22=pos_nodes[4][0]*var_inter[0]; reg13=reg14+reg13; reg14=reg15*pos_nodes[2][1]; reg4=reg4-reg10;
    T reg23=pos_nodes[3][2]*var_inter[2]; reg3=reg16-reg3; reg11=reg11-reg12; reg2=reg20-reg2; reg16=pos_nodes[3][1]*var_inter[2];
    reg20=pos_nodes[3][0]*var_inter[2]; reg17=reg1+reg17; reg1=reg15*pos_nodes[2][0]; reg8=reg7-reg8; reg7=pos_nodes[4][2]*var_inter[0];
    T reg24=reg0*var_inter[2]; T reg25=reg6*pos_nodes[0][2]; T reg26=reg9*pos_nodes[1][2]; T reg27=pos_nodes[5][1]*var_inter[1]; reg21=reg3+reg21;
    reg7=reg8+reg7; reg3=pos_nodes[5][2]*var_inter[1]; reg26=reg25+reg26; reg8=pos_nodes[5][1]*var_inter[2]; reg25=reg5*pos_nodes[1][0];
    reg4=reg4-reg16; T reg28=reg15*pos_nodes[2][2]; reg19=reg19-reg20; T reg29=pos_nodes[5][0]*var_inter[2]; reg22=reg2+reg22;
    reg2=pos_nodes[5][0]*var_inter[1]; T reg30=var_inter[0]*var_inter[2]; reg1=reg17+reg1; reg17=pos_nodes[3][0]*reg24; T reg31=reg5*pos_nodes[1][1];
    T reg32=pos_nodes[5][2]*var_inter[2]; reg14=reg13+reg14; reg13=pos_nodes[3][1]*reg24; reg11=reg11-reg23; reg2=reg22+reg2;
    reg10=reg31-reg10; reg22=var_inter[1]*var_inter[2]; reg32=reg11+reg32; reg29=reg19+reg29; reg11=pos_nodes[3][2]*reg24;
    reg28=reg26+reg28; reg18=reg25-reg18; reg19=reg5*pos_nodes[1][2]; reg17=reg1+reg17; reg1=pos_nodes[4][0]*reg30;
    reg8=reg4+reg8; reg27=reg21+reg27; reg4=pos_nodes[4][1]*reg30; reg3=reg7+reg3; reg13=reg14+reg13;
    reg7=reg27*reg32; reg14=pos_nodes[5][0]*reg22; reg16=reg10-reg16; reg10=pos_nodes[4][1]*var_inter[2]; reg1=reg17+reg1;
    reg17=pos_nodes[4][2]*reg30; reg21=reg8*reg3; reg25=reg2*reg32; reg12=reg19-reg12; reg11=reg28+reg11;
    reg19=pos_nodes[4][0]*var_inter[2]; reg20=reg18-reg20; reg4=reg13+reg4; reg13=reg29*reg3; reg18=pos_nodes[5][1]*reg22;
    reg25=reg13-reg25; reg14=reg1+reg14; reg1=pos_nodes[4][2]*var_inter[2]; reg23=reg12-reg23; reg12=pos_nodes[5][2]*reg22;
    reg17=reg11+reg17; reg10=reg16+reg10; reg19=reg20+reg19; reg11=reg2*reg8; reg18=reg4+reg18;
    reg4=reg29*reg27; reg7=reg21-reg7; reg11=reg4-reg11; reg14=pos[0]-reg14; reg16=reg25*reg10;
    reg1=reg23+reg1; reg20=var_inter[0]*reg19; reg12=reg17+reg12; reg17=var_inter[0]*reg10; reg18=pos[1]-reg18;
    reg23=reg7*reg19; reg12=pos[2]-reg12; reg26=var_inter[1]*reg29; reg14=reg20+reg14; reg20=var_inter[1]*reg8;
    reg18=reg17+reg18; reg17=var_inter[0]*reg1; reg23=reg16-reg23; reg16=reg11*reg1; reg28=reg10*reg3;
    reg31=reg27*reg1; T reg33=reg10*reg32; T reg34=reg8*reg1; T reg35=reg19*reg32; T reg36=reg29*reg1;
    T reg37=reg19*reg3; T reg38=reg2*reg1; T reg39=var_inter[2]*reg2; T reg40=var_inter[2]*reg27; reg14=reg26+reg14;
    reg18=reg20+reg18; reg20=var_inter[1]*reg32; reg12=reg17+reg12; reg16=reg23-reg16; reg31=reg28-reg31;
    reg34=reg33-reg34; reg38=reg37-reg38; reg36=reg35-reg36; reg17=reg19*reg27; reg23=reg29*reg10;
    reg26=reg2*reg10; T reg41=reg19*reg8; reg12=reg20+reg12; reg7=reg7/reg16; reg18=reg40+reg18;
    reg23=reg41-reg23; reg20=var_inter[2]*reg3; reg25=reg25/reg16; reg26=reg17-reg26; reg31=reg31/reg16;
    reg14=reg39+reg14; reg34=reg34/reg16; reg38=reg38/reg16; reg36=reg36/reg16; reg7=reg14*reg7;
    reg25=reg18*reg25; reg23=reg23/reg16; reg31=reg14*reg31; reg12=reg20+reg12; reg36=reg18*reg36;
    reg26=reg26/reg16; reg34=reg14*reg34; reg38=reg18*reg38; reg16=reg11/reg16; reg23=reg12*reg23;
    reg34=reg36-reg34; reg38=reg31-reg38; reg26=reg12*reg26; reg16=reg12*reg16; reg7=reg25-reg7;
    var_inter[1]=reg26+reg38; var_inter[2]=reg34-reg23; var_inter[0]=reg7-reg16;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=var_inter[0]*pos_nodes[1][0]; T reg2=var_inter[0]*pos_nodes[1][1]; T reg3=pos_nodes[0][0]*reg0;
    T reg4=var_inter[0]*pos_nodes[1][2]; T reg5=reg0*pos_nodes[0][2]; T reg6=pos_nodes[0][1]*reg0; T reg7=1-var_inter[2]; T reg8=var_inter[1]*pos_nodes[2][2];
    reg4=reg5+reg4; reg5=reg0*reg7; T reg9=var_inter[0]*reg7; T reg10=var_inter[1]*pos_nodes[2][1]; reg2=reg6+reg2;
    reg1=reg3+reg1; reg3=var_inter[1]*pos_nodes[2][0]; reg6=pos_nodes[0][1]*reg5; reg3=reg1+reg3; reg1=reg9*pos_nodes[1][1];
    reg8=reg4+reg8; reg4=pos_nodes[0][1]*reg7; T reg11=reg7*pos_nodes[0][2]; T reg12=reg0*pos_nodes[3][1]; T reg13=reg7*pos_nodes[2][1];
    T reg14=reg9*pos_nodes[1][0]; T reg15=pos_nodes[0][0]*reg5; T reg16=var_inter[1]*reg7; T reg17=reg0*pos_nodes[3][2]; T reg18=reg7*pos_nodes[2][2];
    T reg19=pos_nodes[0][0]*reg7; reg10=reg2+reg10; reg2=reg7*pos_nodes[2][0]; T reg20=reg0*pos_nodes[3][0]; reg10=reg12-reg10;
    reg12=var_inter[0]*pos_nodes[4][1]; T reg21=reg9*pos_nodes[1][2]; reg13=reg13-reg4; T reg22=var_inter[2]*reg0; T reg23=var_inter[2]*pos_nodes[3][1];
    reg1=reg6+reg1; reg6=reg16*pos_nodes[2][1]; T reg24=reg16*pos_nodes[2][0]; reg14=reg15+reg14; reg18=reg18-reg11;
    reg15=reg5*pos_nodes[0][2]; T reg25=var_inter[2]*pos_nodes[3][0]; T reg26=var_inter[2]*pos_nodes[3][2]; reg2=reg2-reg19; reg8=reg17-reg8;
    reg17=var_inter[0]*pos_nodes[4][2]; reg3=reg20-reg3; reg20=var_inter[0]*pos_nodes[4][0]; reg12=reg10+reg12; reg10=var_inter[1]*pos_nodes[5][1];
    reg18=reg18-reg26; reg17=reg8+reg17; reg8=reg22*pos_nodes[3][1]; T reg27=var_inter[2]*pos_nodes[5][2]; reg6=reg1+reg6;
    reg20=reg3+reg20; reg1=var_inter[2]*pos_nodes[5][1]; reg13=reg13-reg23; reg3=var_inter[1]*pos_nodes[5][2]; T reg28=var_inter[0]*var_inter[2];
    reg21=reg15+reg21; reg15=reg16*pos_nodes[2][2]; T reg29=reg7*pos_nodes[1][0]; T reg30=var_inter[1]*pos_nodes[5][0]; T reg31=reg7*pos_nodes[1][1];
    T reg32=var_inter[2]*pos_nodes[5][0]; reg2=reg2-reg25; T reg33=reg22*pos_nodes[3][0]; reg24=reg14+reg24; reg32=reg2+reg32;
    reg2=reg7*pos_nodes[1][2]; reg19=reg29-reg19; reg14=var_inter[1]*var_inter[2]; reg27=reg18+reg27; reg1=reg13+reg1;
    reg3=reg17+reg3; reg4=reg31-reg4; reg15=reg21+reg15; reg13=reg22*pos_nodes[3][2]; reg10=reg12+reg10;
    reg12=reg28*pos_nodes[4][0]; reg33=reg24+reg33; reg30=reg20+reg30; reg8=reg6+reg8; reg6=reg28*pos_nodes[4][1];
    reg13=reg15+reg13; reg15=reg28*pos_nodes[4][2]; reg17=reg1*reg3; reg18=reg10*reg27; reg20=reg32*reg3;
    reg21=reg30*reg27; reg25=reg19-reg25; reg19=var_inter[2]*pos_nodes[4][0]; reg12=reg33+reg12; reg24=reg14*pos_nodes[5][0];
    reg23=reg4-reg23; reg4=var_inter[2]*pos_nodes[4][1]; reg6=reg8+reg6; reg8=reg14*pos_nodes[5][1]; reg11=reg2-reg11;
    reg18=reg17-reg18; reg2=reg32*reg10; reg29=reg14*pos_nodes[5][2]; reg15=reg13+reg15; reg13=var_inter[2]*pos_nodes[4][2];
    reg19=reg25+reg19; reg26=reg11-reg26; reg24=reg12+reg24; reg21=reg20-reg21; reg11=reg30*reg1;
    reg8=reg6+reg8; reg4=reg23+reg4; reg6=reg4*reg21; reg12=reg19*reg18; reg11=reg2-reg11;
    reg23=var_inter[0]*reg4; reg13=reg26+reg13; reg8=pos[1]-reg8; reg24=pos[0]-reg24; reg29=reg15+reg29;
    reg15=var_inter[0]*reg19; reg25=reg4*reg27; reg26=reg10*reg13; reg31=reg4*reg3; reg33=reg1*reg13;
    T reg34=reg13*reg11; reg12=reg6-reg12; reg29=pos[2]-reg29; reg6=var_inter[1]*reg32; reg15=reg24+reg15;
    reg24=reg19*reg3; T reg35=reg30*reg13; T reg36=reg19*reg27; T reg37=reg32*reg13; T reg38=var_inter[0]*reg13;
    reg23=reg8+reg23; reg8=var_inter[1]*reg1; reg33=reg25-reg33; reg35=reg24-reg35; reg37=reg36-reg37;
    T reg39=reg19*reg10; T reg40=reg30*reg4; T reg41=reg19*reg1; reg26=reg31-reg26; T reg42=reg32*reg4;
    reg23=reg8+reg23; reg8=var_inter[1]*reg27; reg38=reg29+reg38; reg15=reg6+reg15; reg6=var_inter[2]*reg10;
    reg29=var_inter[2]*reg30; reg34=reg12-reg34; reg21=reg21/reg34; reg35=reg35/reg34; reg38=reg8+reg38;
    reg33=reg33/reg34; reg18=reg18/reg34; reg42=reg41-reg42; reg26=reg26/reg34; reg37=reg37/reg34;
    reg23=reg6+reg23; reg6=var_inter[2]*reg3; reg40=reg39-reg40; reg15=reg29+reg15; reg21=reg23*reg21;
    reg26=reg15*reg26; reg35=reg23*reg35; reg33=reg15*reg33; reg37=reg23*reg37; reg18=reg15*reg18;
    reg42=reg42/reg34; reg40=reg40/reg34; reg34=reg11/reg34; reg38=reg6+reg38; reg34=reg38*reg34;
    reg18=reg21-reg18; reg40=reg38*reg40; reg35=reg26-reg35; reg42=reg38*reg42; reg33=reg37-reg33;
    var_inter[0]+=reg18-reg34; var_inter[1]+=reg40+reg35; var_inter[2]+=reg33-reg42;

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
    reg1=var_inter[1]*reg1; reg3=val[0]*reg3; reg2=val[1]*reg2; reg0=var_inter[2]*reg0; reg1=val[2]*reg1;
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
