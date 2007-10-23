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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[0][0]*reg0; T reg2=pos_nodes[1][0]*var_inter[0]; T reg3=reg0*pos_nodes[0][1];
    T reg4=pos_nodes[1][1]*var_inter[0]; T reg5=pos_nodes[0][2]*reg0; T reg6=var_inter[0]*pos_nodes[1][2]; T reg7=1-var_inter[2]; reg6=reg5+reg6;
    reg4=reg3+reg4; reg3=var_inter[1]*pos_nodes[2][1]; reg5=var_inter[1]*pos_nodes[2][2]; T reg8=reg0*reg7; T reg9=reg7*var_inter[0];
    reg2=reg1+reg2; reg1=var_inter[1]*pos_nodes[2][0]; T reg10=reg7*pos_nodes[2][1]; T reg11=reg7*pos_nodes[0][1]; T reg12=reg0*pos_nodes[3][2];
    T reg13=reg7*pos_nodes[2][2]; T reg14=pos_nodes[0][2]*reg7; T reg15=pos_nodes[1][1]*reg9; T reg16=reg8*pos_nodes[0][1]; reg3=reg4+reg3;
    reg4=pos_nodes[1][0]*reg9; T reg17=pos_nodes[0][0]*reg8; reg1=reg2+reg1; reg2=reg0*pos_nodes[3][1]; T reg18=reg0*pos_nodes[3][0];
    T reg19=reg7*pos_nodes[2][0]; T reg20=pos_nodes[0][0]*reg7; reg5=reg6+reg5; reg6=reg7*var_inter[1]; T reg21=reg6*pos_nodes[2][1];
    reg15=reg16+reg15; reg16=var_inter[0]*pos_nodes[4][1]; reg3=reg2-reg3; reg2=var_inter[0]*pos_nodes[4][2]; T reg22=pos_nodes[0][2]*reg8;
    T reg23=reg9*pos_nodes[1][2]; T reg24=var_inter[2]*pos_nodes[3][0]; reg19=reg19-reg20; reg1=reg18-reg1; reg18=var_inter[0]*pos_nodes[4][0];
    T reg25=reg0*var_inter[2]; reg4=reg17+reg4; reg17=reg6*pos_nodes[2][0]; T reg26=var_inter[2]*pos_nodes[3][1]; reg10=reg10-reg11;
    reg5=reg12-reg5; reg12=var_inter[2]*pos_nodes[3][2]; reg13=reg13-reg14; T reg27=reg25*pos_nodes[3][0]; T reg28=var_inter[1]*pos_nodes[5][2];
    reg17=reg4+reg17; reg23=reg22+reg23; reg4=reg6*pos_nodes[2][2]; reg22=var_inter[2]*pos_nodes[5][2]; reg13=reg13-reg12;
    T reg29=var_inter[0]*var_inter[2]; T reg30=var_inter[2]*pos_nodes[5][1]; T reg31=pos_nodes[1][0]*reg7; reg10=reg10-reg26; T reg32=var_inter[1]*pos_nodes[5][0];
    reg18=reg1+reg18; reg1=var_inter[2]*pos_nodes[5][0]; reg19=reg19-reg24; T reg33=reg25*pos_nodes[3][1]; reg21=reg15+reg21;
    reg15=var_inter[1]*pos_nodes[5][1]; reg16=reg3+reg16; reg3=pos_nodes[1][1]*reg7; reg2=reg5+reg2; reg27=reg17+reg27;
    reg1=reg19+reg1; reg33=reg21+reg33; reg5=reg29*pos_nodes[4][1]; reg20=reg31-reg20; reg17=var_inter[1]*var_inter[2];
    reg15=reg16+reg15; reg28=reg2+reg28; reg30=reg10+reg30; reg32=reg18+reg32; reg2=reg29*pos_nodes[4][0];
    reg11=reg3-reg11; reg22=reg13+reg22; reg3=reg7*pos_nodes[1][2]; reg10=reg25*pos_nodes[3][2]; reg4=reg23+reg4;
    reg26=reg11-reg26; reg11=var_inter[2]*pos_nodes[4][1]; reg13=reg29*pos_nodes[4][2]; reg16=reg17*pos_nodes[5][0]; reg2=reg27+reg2;
    reg14=reg3-reg14; reg3=reg32*reg22; reg5=reg33+reg5; reg18=var_inter[2]*pos_nodes[4][0]; reg19=reg17*pos_nodes[5][1];
    reg21=reg1*reg28; reg23=reg30*reg28; reg10=reg4+reg10; reg24=reg20-reg24; reg4=reg15*reg22;
    reg3=reg21-reg3; reg19=reg5+reg19; reg4=reg23-reg4; reg16=reg2+reg16; reg2=reg1*reg15;
    reg5=reg32*reg30; reg11=reg26+reg11; reg12=reg14-reg12; reg14=var_inter[2]*pos_nodes[4][2]; reg18=reg24+reg18;
    reg13=reg10+reg13; reg10=reg17*pos_nodes[5][2]; reg5=reg2-reg5; reg20=reg3*reg11; reg24=var_inter[0]*reg11;
    reg10=reg13+reg10; reg13=var_inter[0]*reg18; reg16=pos[0]-reg16; reg14=reg12+reg14; reg12=reg4*reg18;
    reg19=pos[1]-reg19; reg10=pos[2]-reg10; reg26=reg11*reg22; reg27=reg32*reg14; reg31=reg18*reg28;
    reg33=var_inter[1]*reg1; reg16=reg13+reg16; reg13=reg1*reg14; T reg34=reg18*reg22; T reg35=var_inter[1]*reg30;
    reg19=reg24+reg19; reg24=reg15*reg14; T reg36=var_inter[0]*reg14; T reg37=reg11*reg28; T reg38=reg30*reg14;
    reg12=reg20-reg12; reg20=reg5*reg14; reg24=reg37-reg24; reg38=reg26-reg38; reg27=reg31-reg27;
    reg13=reg34-reg13; reg20=reg12-reg20; reg10=reg36+reg10; reg12=var_inter[1]*reg22; reg19=reg35+reg19;
    reg16=reg33+reg16; reg33=var_inter[2]*reg15; reg35=var_inter[2]*reg32; reg36=reg18*reg15; T reg39=reg32*reg11;
    T reg40=reg18*reg30; T reg41=reg1*reg11; reg3=reg3/reg20; reg16=reg35+reg16; reg35=var_inter[2]*reg28;
    reg19=reg33+reg19; reg10=reg12+reg10; reg4=reg4/reg20; reg41=reg40-reg41; reg13=reg13/reg20;
    reg39=reg36-reg39; reg27=reg27/reg20; reg38=reg38/reg20; reg24=reg24/reg20; reg41=reg41/reg20;
    reg13=reg19*reg13; reg5=reg5/reg20; reg38=reg16*reg38; reg4=reg16*reg4; reg27=reg19*reg27;
    reg20=reg39/reg20; reg10=reg35+reg10; reg24=reg16*reg24; reg3=reg19*reg3; reg20=reg10*reg20;
    reg27=reg24-reg27; reg4=reg3-reg4; reg41=reg10*reg41; reg5=reg10*reg5; reg38=reg13-reg38;
    var_inter[0]=reg4-reg5; var_inter[1]=reg20+reg27; var_inter[2]=reg38-reg41;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[0][0]*reg0; T reg2=var_inter[0]*pos_nodes[1][0]; T reg3=pos_nodes[0][1]*reg0;
    T reg4=var_inter[0]*pos_nodes[1][1]; T reg5=reg0*pos_nodes[0][2]; T reg6=var_inter[0]*pos_nodes[1][2]; T reg7=1-var_inter[2]; T reg8=var_inter[1]*pos_nodes[2][2];
    reg2=reg1+reg2; reg1=var_inter[1]*pos_nodes[2][0]; reg6=reg5+reg6; reg4=reg3+reg4; reg3=var_inter[1]*pos_nodes[2][1];
    reg5=var_inter[0]*reg7; T reg9=reg0*reg7; reg8=reg6+reg8; reg1=reg2+reg1; reg2=pos_nodes[0][0]*reg9;
    reg6=reg5*pos_nodes[1][0]; T reg10=reg7*pos_nodes[2][1]; T reg11=reg0*pos_nodes[3][1]; T reg12=pos_nodes[0][1]*reg7; T reg13=reg0*pos_nodes[3][2];
    T reg14=reg7*pos_nodes[0][2]; reg3=reg4+reg3; reg4=reg7*pos_nodes[2][2]; T reg15=pos_nodes[0][1]*reg9; T reg16=reg5*pos_nodes[1][1];
    T reg17=reg7*pos_nodes[2][0]; T reg18=reg0*pos_nodes[3][0]; T reg19=pos_nodes[0][0]*reg7; T reg20=var_inter[1]*reg7; reg16=reg15+reg16;
    reg15=var_inter[2]*pos_nodes[3][1]; T reg21=reg20*pos_nodes[2][1]; T reg22=var_inter[2]*pos_nodes[3][2]; reg4=reg4-reg14; reg10=reg10-reg12;
    T reg23=reg20*pos_nodes[2][0]; reg6=reg2+reg6; reg2=var_inter[2]*reg0; reg8=reg13-reg8; reg13=var_inter[0]*pos_nodes[4][2];
    T reg24=var_inter[0]*pos_nodes[4][0]; reg1=reg18-reg1; reg18=var_inter[2]*pos_nodes[3][0]; T reg25=reg9*pos_nodes[0][2]; reg17=reg17-reg19;
    T reg26=reg5*pos_nodes[1][2]; T reg27=var_inter[0]*pos_nodes[4][1]; reg3=reg11-reg3; reg11=reg2*pos_nodes[3][1]; T reg28=var_inter[1]*pos_nodes[5][1];
    reg27=reg3+reg27; reg21=reg16+reg21; reg4=reg4-reg22; reg3=var_inter[2]*pos_nodes[5][2]; reg16=var_inter[0]*var_inter[2];
    reg13=reg8+reg13; reg8=var_inter[1]*pos_nodes[5][2]; reg26=reg25+reg26; reg25=reg20*pos_nodes[2][2]; T reg29=var_inter[2]*pos_nodes[5][0];
    reg17=reg17-reg18; T reg30=reg7*pos_nodes[1][0]; T reg31=reg2*pos_nodes[3][0]; reg23=reg6+reg23; reg6=var_inter[2]*pos_nodes[5][1];
    T reg32=reg7*pos_nodes[1][1]; reg10=reg10-reg15; reg24=reg1+reg24; reg1=var_inter[1]*pos_nodes[5][0]; reg19=reg30-reg19;
    reg30=var_inter[1]*var_inter[2]; reg23=reg31+reg23; reg31=reg2*pos_nodes[3][2]; reg25=reg26+reg25; reg26=reg16*pos_nodes[4][0];
    reg3=reg4+reg3; reg4=reg16*pos_nodes[4][1]; reg21=reg11+reg21; reg12=reg32-reg12; reg1=reg24+reg1;
    reg11=reg7*pos_nodes[1][2]; reg28=reg27+reg28; reg6=reg10+reg6; reg8=reg13+reg8; reg29=reg17+reg29;
    reg10=reg29*reg8; reg18=reg19-reg18; reg13=var_inter[2]*pos_nodes[4][0]; reg26=reg23+reg26; reg17=reg30*pos_nodes[5][0];
    reg19=reg1*reg3; reg25=reg31+reg25; reg14=reg11-reg14; reg11=reg16*pos_nodes[4][2]; reg23=reg30*pos_nodes[5][1];
    reg4=reg21+reg4; reg15=reg12-reg15; reg12=var_inter[2]*pos_nodes[4][1]; reg21=reg28*reg3; reg24=reg6*reg8;
    reg11=reg25+reg11; reg25=reg30*pos_nodes[5][2]; reg27=reg29*reg28; reg21=reg24-reg21; reg13=reg18+reg13;
    reg17=reg26+reg17; reg18=var_inter[2]*pos_nodes[4][2]; reg22=reg14-reg22; reg19=reg10-reg19; reg23=reg4+reg23;
    reg12=reg15+reg12; reg4=reg1*reg6; reg14=reg12*reg19; reg4=reg27-reg4; reg15=reg13*reg21;
    reg26=var_inter[0]*reg12; reg17=pos[0]-reg17; reg23=pos[1]-reg23; reg18=reg22+reg18; reg25=reg11+reg25;
    reg11=var_inter[0]*reg13; reg22=reg12*reg8; reg31=reg28*reg18; reg32=reg12*reg3; T reg33=reg18*reg4;
    T reg34=reg13*reg8; reg15=reg14-reg15; reg25=pos[2]-reg25; reg14=reg6*reg18; T reg35=reg1*reg18;
    T reg36=var_inter[1]*reg29; T reg37=reg13*reg3; T reg38=reg29*reg18; T reg39=var_inter[0]*reg18; reg26=reg23+reg26;
    reg23=var_inter[1]*reg6; reg11=reg17+reg11; reg14=reg32-reg14; reg35=reg34-reg35; reg31=reg22-reg31;
    reg38=reg37-reg38; reg17=reg13*reg28; T reg40=reg1*reg12; T reg41=reg13*reg6; T reg42=reg29*reg12;
    T reg43=var_inter[2]*reg28; reg11=reg36+reg11; reg26=reg23+reg26; reg23=var_inter[1]*reg3; reg39=reg25+reg39;
    reg25=var_inter[2]*reg1; reg33=reg15-reg33; reg14=reg14/reg33; reg39=reg23+reg39; reg35=reg35/reg33;
    reg31=reg31/reg33; reg26=reg43+reg26; reg42=reg41-reg42; reg19=reg19/reg33; reg38=reg38/reg33;
    reg15=var_inter[2]*reg8; reg11=reg25+reg11; reg21=reg21/reg33; reg40=reg17-reg40; reg19=reg19*reg26;
    reg31=reg11*reg31; reg35=reg26*reg35; reg14=reg11*reg14; reg38=reg26*reg38; reg21=reg11*reg21;
    reg42=reg42/reg33; reg40=reg40/reg33; reg33=reg4/reg33; reg39=reg15+reg39; reg33=reg39*reg33;
    reg21=reg19-reg21; reg40=reg39*reg40; reg35=reg31-reg35; reg42=reg39*reg42; reg14=reg38-reg14;
    var_inter[0]+=reg21-reg33; var_inter[1]+=reg40+reg35; var_inter[2]+=reg14-reg42;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=1-var_inter[2]; T reg2=var_inter[0]*reg1; T reg3=reg0*reg1;
    reg2=val[1]*reg2; reg3=val[0]*reg3; reg1=var_inter[1]*reg1; reg1=val[2]*reg1; reg0=var_inter[2]*reg0;
    reg2=reg3+reg2; reg0=val[3]*reg0; reg3=var_inter[0]*var_inter[2]; reg1=reg2+reg1; reg3=val[4]*reg3;
    reg2=var_inter[1]*var_inter[2]; reg0=reg1+reg0; reg3=reg0+reg3; reg2=val[5]*reg2; res=reg3+reg2;

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
