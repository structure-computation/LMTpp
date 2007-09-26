#ifndef LMT_WEDGE_15
#define LMT_WEDGE_15
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Wedge_15 &elem) { /// order -> degre du polynome a integrer exactement
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
template<class TNode> void permutation_if_jac_neg(const Wedge_15 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=nodes[0]->pos[2]+nodes[3]->pos[2]; T reg1=nodes[0]->pos[1]+nodes[3]->pos[1]; reg0=reg0-nodes[6]->pos[2]; reg1=reg1-nodes[6]->pos[1]; reg1=nodes[7]->pos[1]+reg1;
    T reg2=nodes[3]->pos[0]+nodes[0]->pos[0]; reg0=nodes[7]->pos[2]+reg0; reg2=reg2-nodes[6]->pos[0]; reg0=reg0-nodes[8]->pos[2]; reg1=reg1-nodes[8]->pos[1];
    reg0=reg0-nodes[9]->pos[2]; reg2=nodes[7]->pos[0]+reg2; reg1=reg1-nodes[9]->pos[1]; reg0=nodes[10]->pos[2]+reg0; reg2=reg2-nodes[8]->pos[0];
    reg1=nodes[10]->pos[1]+reg1; reg0=reg0-nodes[11]->pos[2]; reg1=reg1-nodes[11]->pos[1]; reg2=reg2-nodes[9]->pos[0]; reg1=reg1-nodes[12]->pos[1];
    reg0=reg0-nodes[12]->pos[2]; reg2=nodes[10]->pos[0]+reg2; T reg3=nodes[10]->pos[1]-nodes[7]->pos[1]; T reg4=nodes[14]->pos[2]+reg0; reg0=nodes[13]->pos[2]+reg0;
    T reg5=nodes[10]->pos[2]-nodes[7]->pos[2]; T reg6=nodes[14]->pos[1]+reg1; reg2=reg2-nodes[11]->pos[0]; reg1=nodes[13]->pos[1]+reg1; T reg7=reg4*reg3;
    reg3=reg3*reg0; T reg8=reg5*reg1; reg5=reg6*reg5; reg2=reg2-nodes[12]->pos[0]; reg0=reg6*reg0;
    reg1=reg4*reg1; reg3=reg8-reg3; reg4=nodes[13]->pos[0]+reg2; reg2=nodes[14]->pos[0]+reg2; reg7=reg5-reg7;
    reg3=reg2*reg3; reg2=nodes[10]->pos[0]-nodes[7]->pos[0]; reg7=reg4*reg7; reg0=reg1-reg0; reg3=reg7-reg3;
    reg0=reg2*reg0; T det_jac=reg3+reg0;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[14],nodes[13],nodes[12],nodes[11],nodes[10],nodes[9],nodes[8],nodes[7],nodes[6],nodes[5],nodes[4],nodes[3],nodes[2],nodes[1],nodes[0]};
        for(unsigned i=0;i<15;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*reg0; T reg3=2*var_inter[2];
    T reg4=reg1-1; T reg5=reg2-1; T reg6=0.5*reg0; T reg7=0.5*var_inter[0]; reg3=reg3-1;
    T reg8=2*var_inter[1]; T reg9=4*reg3; T reg10=reg8-1; T reg11=reg7*reg4; T reg12=0.5*var_inter[1];
    T reg13=reg5*reg6; T reg14=pow(reg3,2); T reg15=reg7*reg9; T reg16=2*reg11; T reg17=reg6*reg9;
    T reg18=reg12*reg10; T reg19=2*reg13; T reg20=reg15-reg16; T reg21=1-reg3; reg14=1-reg14;
    T reg22=reg17-reg19; reg10=0.5*reg10; reg5=0.5*reg5; T reg23=2*reg18; T reg24=reg12*reg9;
    T reg25=pos_nodes[0][2]*reg22; T reg26=pos_nodes[1][2]*reg20; reg7=reg7*reg14; T reg27=pos_nodes[0][1]*reg22; T reg28=pos_nodes[1][1]*reg20;
    reg6=reg14*reg6; reg10=var_inter[1]+reg10; T reg29=reg13*reg21; T reg30=reg24-reg23; T reg31=reg11*reg21;
    T reg32=pos_nodes[0][0]*reg22; T reg33=pos_nodes[1][0]*reg20; reg5=reg0+reg5; T reg34=pos_nodes[2][1]*reg30; reg28=reg27+reg28;
    reg27=reg21*reg10; T reg35=reg21*reg5; reg4=0.5*reg4; reg31=reg31-reg7; T reg36=0.5*reg14;
    T reg37=reg18*reg21; reg12=reg12*reg14; T reg38=reg19+reg17; reg33=reg32+reg33; reg32=pos_nodes[2][0]*reg30;
    reg29=reg29-reg6; T reg39=pos_nodes[2][2]*reg30; reg3=1+reg3; reg26=reg25+reg26; reg25=pos_nodes[3][2]*reg38;
    reg34=reg28+reg34; reg28=pos_nodes[3][1]*reg38; reg27=reg27-reg36; T reg40=pos_nodes[3][0]*reg38; reg32=reg33+reg32;
    reg33=reg3*reg5; reg4=var_inter[0]+reg4; reg39=reg26+reg39; reg26=reg36-reg35; T reg41=reg31*pos_nodes[1][0];
    T reg42=pos_nodes[0][0]*reg29; T reg43=reg16+reg15; reg37=reg37-reg12; reg13=reg3*reg13; T reg44=reg31*pos_nodes[1][1];
    T reg45=pos_nodes[0][1]*reg29; T reg46=pos_nodes[0][2]*reg26; reg10=reg3*reg10; reg25=reg39+reg25; reg39=pos_nodes[4][0]*reg43;
    reg40=reg32+reg40; reg32=pos_nodes[0][2]*reg29; T reg47=pos_nodes[0][0]*reg26; T reg48=pos_nodes[2][0]*reg27; T reg49=reg31*pos_nodes[1][2];
    T reg50=pos_nodes[4][1]*reg43; reg28=reg34+reg28; reg34=var_inter[0]*reg2; reg11=reg11*reg3; T reg51=pos_nodes[2][2]*reg27;
    T reg52=pos_nodes[0][1]*reg26; T reg53=reg23+reg24; T reg54=pos_nodes[2][1]*reg27; reg6=reg13-reg6; reg41=reg42+reg41;
    reg13=reg37*pos_nodes[2][0]; reg44=reg45+reg44; reg42=reg36-reg33; reg45=reg37*pos_nodes[2][1]; T reg55=pos_nodes[4][2]*reg43;
    T reg56=reg21*reg4; reg49=reg32+reg49; reg7=reg11-reg7; reg18=reg18*reg3; reg11=pos_nodes[5][2]*reg53;
    reg32=2*reg34; reg48=reg47+reg48; T reg57=reg6*pos_nodes[3][0]; T reg58=reg1*var_inter[1]; reg13=reg41+reg13;
    reg41=pos_nodes[3][2]*reg42; T reg59=reg6*pos_nodes[3][1]; reg56=reg56-reg36; reg45=reg44+reg45; reg55=reg25+reg55;
    reg25=pos_nodes[3][1]*reg42; reg54=reg52+reg54; reg44=pos_nodes[5][0]*reg53; reg10=reg10-reg36; T reg60=reg37*pos_nodes[2][2];
    reg39=reg40+reg39; reg40=pos_nodes[3][0]*reg42; reg50=reg28+reg50; reg51=reg46+reg51; reg28=pos_nodes[5][1]*reg53;
    reg11=reg55+reg11; reg55=reg7*pos_nodes[4][0]; reg57=reg13+reg57; reg13=reg6*pos_nodes[3][2]; reg51=reg41+reg51;
    T reg61=pos_nodes[5][1]*reg10; reg54=reg25+reg54; T reg62=2*reg58; T reg63=pos_nodes[1][1]*reg56; T reg64=pos_nodes[6][2]*reg32;
    T reg65=reg7*pos_nodes[4][1]; reg28=reg50+reg28; reg50=reg1*reg21; T reg66=pos_nodes[5][2]*reg10; reg44=reg39+reg44;
    reg39=pos_nodes[1][0]*reg56; T reg67=reg8*reg0; reg60=reg49+reg60; reg49=pos_nodes[6][1]*reg32; T reg68=pos_nodes[6][0]*reg32;
    reg4=reg3*reg4; reg48=reg40+reg48; T reg69=pos_nodes[5][0]*reg10; reg12=reg18-reg12; reg59=reg45+reg59;
    reg18=2*reg67; reg68=reg44-reg68; reg44=pos_nodes[7][0]*reg62; reg45=reg34*reg21; T reg70=pos_nodes[1][2]*reg56;
    T reg71=pos_nodes[7][1]*reg62; reg63=reg52+reg63; reg52=reg7*pos_nodes[4][2]; reg13=reg60+reg13; reg4=reg4-reg36;
    reg60=reg2-reg1; reg49=reg28-reg49; reg39=reg47+reg39; reg28=pos_nodes[6][2]*reg50; reg66=reg51+reg66;
    reg47=reg12*pos_nodes[5][1]; reg65=reg59+reg65; reg64=reg11-reg64; reg11=pos_nodes[7][2]*reg62; reg61=reg54+reg61;
    reg51=pos_nodes[6][1]*reg50; reg55=reg57+reg55; reg54=reg12*pos_nodes[5][0]; reg57=pos_nodes[6][0]*reg50; reg69=reg48+reg69;
    reg2=reg2-reg8; reg48=pos_nodes[4][1]*reg4; reg25=reg63+reg25; reg54=reg55+reg54; reg55=reg45*pos_nodes[6][0];
    reg28=reg66-reg28; reg59=pos_nodes[7][2]*reg50; reg63=reg21*reg60; reg40=reg39+reg40; reg39=pos_nodes[4][0]*reg4;
    reg46=reg70+reg46; reg66=reg21*reg2; reg52=reg13+reg52; reg57=reg69-reg57; reg13=pos_nodes[7][0]*reg50;
    reg69=reg12*pos_nodes[5][2]; reg71=reg49-reg71; reg49=pos_nodes[8][1]*reg18; reg70=pos_nodes[7][1]*reg50; reg51=reg61-reg51;
    reg61=pos_nodes[8][2]*reg18; reg11=reg64-reg11; reg47=reg65+reg47; reg64=reg45*pos_nodes[6][1]; reg65=reg58*reg21;
    reg44=reg68-reg44; reg68=pos_nodes[8][0]*reg18; reg49=reg71-reg49; reg71=pos_nodes[9][1]*reg32; reg48=reg25+reg48;
    reg25=pos_nodes[6][1]*reg63; reg41=reg46+reg41; reg46=pos_nodes[4][2]*reg4; T reg72=pos_nodes[8][1]*reg66; reg70=reg51+reg70;
    reg64=reg47+reg64; reg47=reg65*pos_nodes[7][1]; reg55=reg54+reg55; reg51=pos_nodes[9][0]*reg32; reg68=reg44-reg68;
    reg61=reg11-reg61; reg11=pos_nodes[8][0]*reg66; reg13=reg57+reg13; reg44=reg1*reg3; reg54=pos_nodes[9][2]*reg32;
    reg57=pos_nodes[6][0]*reg63; reg39=reg40+reg39; reg40=reg8*reg21; reg69=reg52+reg69; reg52=reg45*pos_nodes[6][2];
    reg21=reg67*reg21; reg59=reg28+reg59; reg28=pos_nodes[8][2]*reg66; T reg73=reg65*pos_nodes[7][0]; reg46=reg41+reg46;
    reg25=reg48+reg25; reg41=reg21*pos_nodes[8][0]; reg54=reg61+reg54; reg48=pos_nodes[10][2]*reg62; reg61=pos_nodes[7][0]*reg40;
    reg57=reg39+reg57; reg52=reg69+reg52; reg39=reg65*pos_nodes[7][2]; reg71=reg49+reg71; reg49=pos_nodes[10][1]*reg62;
    reg69=reg21*pos_nodes[8][1]; reg47=reg64+reg47; reg64=pos_nodes[9][2]*reg44; reg28=reg59+reg28; reg34=reg3*reg34;
    reg59=pos_nodes[10][0]*reg62; T reg74=pos_nodes[9][1]*reg44; reg72=reg70+reg72; reg70=pos_nodes[7][1]*reg40; reg11=reg13+reg11;
    reg13=pos_nodes[6][2]*reg63; reg73=reg55+reg73; reg55=pos_nodes[9][0]*reg44; reg51=reg68+reg51; reg68=reg0*reg9;
    T reg75=pos_nodes[8][1]*reg40; reg49=reg71+reg49; reg71=pos_nodes[11][1]*reg18; T reg76=reg34*pos_nodes[9][1]; reg69=reg47+reg69;
    reg13=reg46+reg13; reg46=pos_nodes[7][2]*reg40; reg47=pos_nodes[11][0]*reg18; reg39=reg52+reg39; reg52=reg21*pos_nodes[8][2];
    reg58=reg3*reg58; reg59=reg51+reg59; reg51=pos_nodes[10][1]*reg44; reg74=reg72-reg74; reg2=reg3*reg2;
    reg41=reg73+reg41; reg48=reg54+reg48; reg54=pos_nodes[11][2]*reg18; reg72=pos_nodes[8][0]*reg40; reg61=reg57+reg61;
    reg55=reg11-reg55; reg11=reg34*pos_nodes[9][0]; reg60=reg3*reg60; reg57=pos_nodes[10][2]*reg44; reg64=reg28-reg64;
    reg28=pos_nodes[10][0]*reg44; reg70=reg25+reg70; reg25=pos_nodes[11][2]*reg2; reg76=reg69+reg76; reg69=reg58*pos_nodes[10][1];
    reg73=pos_nodes[12][2]*reg68; reg54=reg48+reg54; reg46=reg13+reg46; reg13=pos_nodes[8][2]*reg40; reg57=reg64+reg57;
    reg52=reg39+reg52; reg39=reg34*pos_nodes[9][2]; reg48=reg58*pos_nodes[10][0]; reg11=reg41+reg11; reg41=pos_nodes[11][0]*reg2;
    reg64=reg8*reg3; reg51=reg74+reg51; reg74=pos_nodes[11][1]*reg2; reg72=reg61-reg72; reg61=pos_nodes[9][0]*reg60;
    reg71=reg49+reg71; reg67=reg3*reg67; reg28=reg55+reg28; reg3=pos_nodes[12][0]*reg68; reg47=reg59+reg47;
    reg49=var_inter[0]*reg9; reg55=pos_nodes[9][1]*reg60; reg59=pos_nodes[12][1]*reg68; reg75=reg70-reg75; reg70=reg14*pos_nodes[12][0];
    T reg77=reg67*pos_nodes[11][0]; reg73=reg54-reg73; reg54=reg14*pos_nodes[12][2]; T reg78=pos_nodes[13][2]*reg49; reg55=reg75+reg55;
    reg75=pos_nodes[10][1]*reg64; reg61=reg72+reg61; reg72=pos_nodes[10][0]*reg64; reg48=reg11+reg48; reg25=reg57+reg25;
    reg41=reg28+reg41; reg11=pos_nodes[13][1]*reg49; reg59=reg71-reg59; reg69=reg76+reg69; reg28=reg67*pos_nodes[11][1];
    reg57=var_inter[1]*reg9; reg3=reg47-reg3; reg47=reg58*pos_nodes[10][2]; reg39=reg52+reg39; reg0=reg14*reg0;
    reg52=pos_nodes[13][0]*reg49; reg74=reg51+reg74; reg51=reg14*pos_nodes[12][1]; reg13=reg46-reg13; reg46=pos_nodes[9][2]*reg60;
    reg71=reg14*pos_nodes[14][2]; reg25=reg25-reg54; reg52=reg3-reg52; reg3=pos_nodes[14][0]*reg57; reg76=reg14*pos_nodes[14][0];
    reg77=reg48+reg77; reg48=reg0*pos_nodes[12][0]; reg41=reg41-reg70; T reg79=reg0*pos_nodes[12][1]; reg28=reg69+reg28;
    reg69=reg67*pos_nodes[11][2]; reg47=reg39+reg47; reg39=reg14*pos_nodes[14][1]; reg74=reg74-reg51; T reg80=var_inter[0]*reg14;
    reg11=reg59-reg11; reg46=reg13+reg46; reg13=pos_nodes[10][2]*reg64; reg59=pos_nodes[14][1]*reg57; T reg81=pos_nodes[14][2]*reg57;
    reg78=reg73-reg78; reg73=pos_nodes[11][1]*reg64; reg75=reg55+reg75; reg72=reg61+reg72; reg55=pos_nodes[11][0]*reg64;
    reg61=reg0*pos_nodes[12][2]; reg69=reg47+reg69; reg47=var_inter[1]*reg14; reg81=reg78-reg81; reg55=reg72-reg55;
    reg59=reg11-reg59; reg79=reg28+reg79; reg11=reg80*pos_nodes[13][1]; reg39=reg74+reg39; reg73=reg75-reg73;
    reg13=reg46+reg13; reg28=pos_nodes[11][2]*reg64; reg46=reg80*pos_nodes[13][0]; reg71=reg25+reg71; reg48=reg77+reg48;
    reg3=reg52-reg3; reg76=reg41+reg76; reg25=reg47*pos_nodes[14][1]; reg11=reg79+reg11; reg41=reg14*pos_nodes[13][1];
    reg51=reg73-reg51; reg52=reg14*pos_nodes[13][0]; reg70=reg55-reg70; reg28=reg13-reg28; reg61=reg69+reg61;
    reg13=reg80*pos_nodes[13][2]; reg55=reg39*reg81; reg69=reg59*reg71; reg72=reg76*reg81; reg73=reg3*reg71;
    reg74=reg47*pos_nodes[14][0]; reg46=reg48+reg46; reg13=reg61+reg13; reg48=reg47*pos_nodes[14][2]; reg69=reg55-reg69;
    reg61=reg76*reg59; reg73=reg72-reg73; reg75=reg3*reg39; reg74=reg46+reg74; reg46=reg14*pos_nodes[13][2];
    reg25=reg11+reg25; reg52=reg70+reg52; reg41=reg51+reg41; reg54=reg28-reg54; reg25=pos[1]-reg25;
    reg46=reg54+reg46; reg48=reg13+reg48; reg11=var_inter[0]*reg52; reg74=pos[0]-reg74; reg13=reg41*reg73;
    reg28=var_inter[0]*reg41; reg75=reg61-reg75; reg51=reg52*reg69; reg54=reg59*reg46; reg70=reg41*reg81;
    reg77=reg52*reg81; reg78=reg3*reg46; reg79=reg52*reg71; reg51=reg13-reg51; reg13=reg46*reg75;
    reg48=pos[2]-reg48; T reg82=var_inter[1]*reg76; reg11=reg74+reg11; reg74=reg76*reg46; T reg83=var_inter[1]*reg39;
    reg28=reg25+reg28; reg25=reg39*reg46; T reg84=var_inter[0]*reg46; T reg85=reg41*reg71; T reg86=reg3*reg41;
    reg13=reg51-reg13; reg25=reg85-reg25; reg51=reg52*reg39; T reg87=reg76*reg41; reg74=reg79-reg74;
    reg54=reg70-reg54; T reg88=reg52*reg59; reg78=reg77-reg78; reg84=reg48+reg84; reg48=var_inter[1]*reg71;
    reg28=reg83+reg28; reg83=var_inter[2]*reg3; T reg89=var_inter[2]*reg59; reg11=reg82+reg11; reg86=reg88-reg86;
    reg78=reg78/reg13; reg73=reg73/reg13; reg74=reg74/reg13; reg87=reg51-reg87; reg11=reg83+reg11;
    reg25=reg25/reg13; reg82=var_inter[2]*reg81; reg54=reg54/reg13; reg28=reg89+reg28; reg84=reg48+reg84;
    reg69=reg69/reg13; reg54=reg11*reg54; reg73=reg73*reg28; reg78=reg78*reg28; reg25=reg11*reg25;
    reg74=reg28*reg74; reg69=reg11*reg69; reg87=reg87/reg13; reg86=reg86/reg13; reg13=reg75/reg13;
    reg84=reg82+reg84; reg13=reg84*reg13; reg69=reg73-reg69; reg86=reg84*reg86; reg78=reg54-reg78;
    reg87=reg84*reg87; reg25=reg74-reg25; var_inter[0]=reg69-reg13; var_inter[1]=reg86+reg78; var_inter[2]=reg25-reg87;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*var_inter[0]; T reg3=2*reg0;
    reg1=reg1-1; T reg4=0.5*var_inter[0]; T reg5=reg3-1; T reg6=0.5*reg0; T reg7=2*var_inter[1];
    T reg8=reg2-1; T reg9=reg7-1; T reg10=reg8*reg4; T reg11=4*reg1; T reg12=reg6*reg5;
    T reg13=0.5*var_inter[1]; T reg14=pow(reg1,2); T reg15=reg13*reg9; T reg16=2*reg10; T reg17=reg4*reg11;
    T reg18=2*reg12; T reg19=reg6*reg11; T reg20=1-reg1; reg14=1-reg14; reg5=0.5*reg5;
    T reg21=reg13*reg11; T reg22=2*reg15; reg9=0.5*reg9; T reg23=reg19-reg18; T reg24=reg17-reg16;
    T reg25=reg21-reg22; T reg26=pos_nodes[1][0]*reg24; T reg27=pos_nodes[1][2]*reg24; T reg28=pos_nodes[0][0]*reg23; T reg29=pos_nodes[0][2]*reg23;
    reg9=var_inter[1]+reg9; T reg30=pos_nodes[1][1]*reg24; T reg31=pos_nodes[0][1]*reg23; reg5=reg0+reg5; T reg32=reg20*reg12;
    T reg33=reg20*reg10; reg6=reg14*reg6; reg4=reg14*reg4; T reg34=reg20*reg5; T reg35=0.5*reg14;
    reg8=0.5*reg8; reg32=reg32-reg6; T reg36=reg20*reg9; reg31=reg30+reg31; reg30=pos_nodes[2][1]*reg25;
    T reg37=reg18+reg19; reg33=reg33-reg4; reg28=reg26+reg28; reg26=pos_nodes[2][0]*reg25; T reg38=pos_nodes[2][2]*reg25;
    reg1=1+reg1; reg29=reg27+reg29; reg13=reg14*reg13; reg27=reg20*reg15; reg8=var_inter[0]+reg8;
    reg27=reg27-reg13; reg36=reg36-reg35; reg30=reg31+reg30; reg31=pos_nodes[3][1]*reg37; reg38=reg29+reg38;
    reg29=reg16+reg17; reg12=reg12*reg1; T reg39=pos_nodes[3][2]*reg37; T reg40=reg33*pos_nodes[1][0]; T reg41=reg32*pos_nodes[0][0];
    T reg42=reg1*reg5; T reg43=reg35-reg34; T reg44=pos_nodes[3][0]*reg37; reg26=reg28+reg26; reg28=reg32*pos_nodes[0][1];
    T reg45=reg33*pos_nodes[1][1]; T reg46=pos_nodes[2][1]*reg36; T reg47=reg33*pos_nodes[1][2]; T reg48=reg32*pos_nodes[0][2]; T reg49=pos_nodes[0][0]*reg43;
    T reg50=pos_nodes[2][2]*reg36; T reg51=pos_nodes[4][1]*reg29; T reg52=pos_nodes[0][2]*reg43; reg9=reg1*reg9; T reg53=pos_nodes[2][0]*reg36;
    T reg54=pos_nodes[0][1]*reg43; T reg55=pos_nodes[4][2]*reg29; T reg56=reg27*pos_nodes[2][1]; T reg57=reg22+reg21; T reg58=pos_nodes[4][0]*reg29;
    reg44=reg26+reg44; reg26=reg27*pos_nodes[2][0]; reg41=reg40+reg41; reg39=reg38+reg39; reg10=reg10*reg1;
    reg6=reg12-reg6; reg12=reg35-reg42; reg38=var_inter[0]*reg3; reg40=reg20*reg8; reg28=reg45+reg28;
    reg31=reg30+reg31; reg30=2*reg38; reg45=reg6*pos_nodes[3][1]; reg56=reg28+reg56; reg28=pos_nodes[5][1]*reg57;
    reg31=reg51+reg31; reg53=reg49+reg53; reg51=pos_nodes[3][1]*reg12; reg9=reg9-reg35; T reg59=reg27*pos_nodes[2][2];
    T reg60=pos_nodes[5][2]*reg57; reg44=reg58+reg44; reg58=pos_nodes[5][0]*reg57; T reg61=reg6*pos_nodes[3][0]; reg26=reg41+reg26;
    reg39=reg55+reg39; reg41=reg2*var_inter[1]; reg46=reg54+reg46; reg55=pos_nodes[3][2]*reg12; T reg62=pos_nodes[3][0]*reg12;
    reg40=reg40-reg35; reg50=reg52+reg50; reg48=reg47+reg48; reg15=reg15*reg1; reg4=reg10-reg4;
    reg10=reg7*reg0; reg45=reg56+reg45; reg47=pos_nodes[6][1]*reg30; reg28=reg31+reg28; reg31=2*reg41;
    reg60=reg39+reg60; reg58=reg44+reg58; reg39=pos_nodes[6][2]*reg30; reg44=pos_nodes[6][0]*reg30; reg56=pos_nodes[5][1]*reg9;
    reg61=reg26+reg61; reg59=reg48+reg59; reg26=pos_nodes[5][2]*reg9; reg50=reg55+reg50; reg48=reg20*reg2;
    reg53=reg62+reg53; T reg63=pos_nodes[5][0]*reg9; reg13=reg15-reg13; reg15=reg4*pos_nodes[4][1]; reg8=reg1*reg8;
    T reg64=pos_nodes[1][1]*reg40; T reg65=pos_nodes[1][0]*reg40; T reg66=reg4*pos_nodes[4][0]; T reg67=reg6*pos_nodes[3][2]; reg46=reg51+reg46;
    T reg68=reg4*pos_nodes[4][2]; reg56=reg46+reg56; reg46=pos_nodes[6][1]*reg48; reg44=reg58-reg44; reg58=pos_nodes[7][0]*reg31;
    reg49=reg65+reg49; reg65=pos_nodes[1][2]*reg40; T reg69=reg3-reg2; T reg70=reg20*reg38; reg3=reg3-reg7;
    reg54=reg64+reg54; reg67=reg59+reg67; reg63=reg53+reg63; reg53=pos_nodes[6][0]*reg48; reg26=reg50+reg26;
    reg50=pos_nodes[6][2]*reg48; reg59=reg13*pos_nodes[5][0]; reg64=pos_nodes[7][2]*reg31; reg39=reg60-reg39; reg61=reg66+reg61;
    reg8=reg8-reg35; reg45=reg15+reg45; reg15=reg13*pos_nodes[5][1]; reg60=2*reg10; reg66=pos_nodes[7][1]*reg31;
    reg47=reg28-reg47; reg66=reg47-reg66; reg51=reg54+reg51; reg28=pos_nodes[8][1]*reg60; reg47=pos_nodes[4][1]*reg8;
    reg54=reg70*pos_nodes[6][1]; reg15=reg45+reg15; reg50=reg26-reg50; reg26=pos_nodes[7][2]*reg48; reg52=reg65+reg52;
    reg45=reg70*pos_nodes[6][0]; reg46=reg56-reg46; reg59=reg61+reg59; reg56=pos_nodes[7][1]*reg48; reg62=reg49+reg62;
    reg67=reg68+reg67; reg49=reg13*pos_nodes[5][2]; reg61=reg20*reg3; reg65=reg20*reg69; reg68=pos_nodes[8][2]*reg60;
    reg64=reg39-reg64; reg58=reg44-reg58; reg39=pos_nodes[8][0]*reg60; reg44=pos_nodes[7][0]*reg48; reg53=reg63-reg53;
    reg63=reg20*reg41; T reg71=pos_nodes[4][0]*reg8; reg51=reg47+reg51; reg47=reg2*reg1; T reg72=pos_nodes[6][1]*reg65;
    reg54=reg15+reg54; reg53=reg44+reg53; reg62=reg71+reg62; reg55=reg52+reg55; reg15=pos_nodes[9][2]*reg30;
    reg44=pos_nodes[8][1]*reg61; reg46=reg56+reg46; reg52=pos_nodes[6][0]*reg65; reg28=reg66-reg28; reg56=pos_nodes[9][1]*reg30;
    reg66=reg63*pos_nodes[7][0]; reg71=reg20*reg10; T reg73=pos_nodes[9][0]*reg30; reg39=reg58-reg39; reg68=reg64-reg68;
    reg45=reg59+reg45; reg58=reg70*pos_nodes[6][2]; reg49=reg67+reg49; reg20=reg20*reg7; reg59=pos_nodes[8][2]*reg61;
    reg50=reg26+reg50; reg26=reg63*pos_nodes[7][1]; reg64=pos_nodes[4][2]*reg8; reg67=pos_nodes[8][0]*reg61; reg58=reg49+reg58;
    reg49=pos_nodes[9][1]*reg47; reg44=reg46+reg44; reg52=reg62+reg52; reg46=pos_nodes[7][0]*reg20; reg62=reg63*pos_nodes[7][2];
    T reg74=pos_nodes[10][0]*reg31; reg73=reg39+reg73; reg38=reg38*reg1; reg45=reg66+reg45; reg39=reg71*pos_nodes[8][0];
    reg66=pos_nodes[9][2]*reg47; reg59=reg50+reg59; reg50=pos_nodes[9][0]*reg47; reg67=reg53+reg67; reg53=pos_nodes[7][1]*reg20;
    reg72=reg51+reg72; reg54=reg26+reg54; reg26=reg71*pos_nodes[8][1]; reg15=reg68+reg15; reg51=pos_nodes[10][2]*reg31;
    reg68=pos_nodes[6][2]*reg65; reg55=reg64+reg55; reg64=pos_nodes[10][1]*reg31; reg56=reg28+reg56; reg26=reg54+reg26;
    reg28=reg38*pos_nodes[9][1]; reg54=pos_nodes[7][2]*reg20; T reg75=pos_nodes[11][1]*reg60; reg58=reg62+reg58; reg62=reg71*pos_nodes[8][2];
    reg41=reg41*reg1; reg64=reg56+reg64; reg56=pos_nodes[11][0]*reg60; reg74=reg73+reg74; reg73=reg0*reg11;
    reg39=reg45+reg39; reg45=reg38*pos_nodes[9][0]; T reg76=pos_nodes[10][0]*reg47; T reg77=pos_nodes[10][2]*reg47; reg66=reg59-reg66;
    reg50=reg67-reg50; reg3=reg1*reg3; reg72=reg53+reg72; reg53=pos_nodes[8][1]*reg20; reg51=reg15+reg51;
    reg68=reg55+reg68; reg15=pos_nodes[11][2]*reg60; reg69=reg1*reg69; reg55=pos_nodes[8][0]*reg20; reg52=reg46+reg52;
    reg46=pos_nodes[10][1]*reg47; reg49=reg44-reg49; reg44=reg38*pos_nodes[9][2]; reg62=reg58+reg62; reg58=pos_nodes[11][2]*reg3;
    reg77=reg66+reg77; reg59=pos_nodes[12][2]*reg73; reg15=reg51+reg15; reg68=reg54+reg68; reg51=pos_nodes[8][2]*reg20;
    reg28=reg26+reg28; reg26=reg41*pos_nodes[10][1]; reg46=reg49+reg46; reg49=pos_nodes[11][1]*reg3; reg56=reg74+reg56;
    reg54=pos_nodes[9][1]*reg69; reg75=reg64+reg75; reg10=reg10*reg1; reg64=var_inter[0]*reg11; reg53=reg72-reg53;
    reg55=reg52-reg55; reg52=pos_nodes[9][0]*reg69; reg1=reg7*reg1; reg66=pos_nodes[12][0]*reg73; reg45=reg39+reg45;
    reg39=pos_nodes[12][1]*reg73; reg67=pos_nodes[11][0]*reg3; reg76=reg50+reg76; reg50=reg41*pos_nodes[10][0]; reg72=reg14*pos_nodes[12][2];
    reg74=pos_nodes[10][1]*reg1; reg54=reg53+reg54; reg52=reg55+reg52; reg53=pos_nodes[10][0]*reg1; reg59=reg15-reg59;
    reg15=pos_nodes[13][2]*reg64; reg55=reg10*pos_nodes[11][0]; reg50=reg45+reg50; reg58=reg77+reg58; reg45=reg14*pos_nodes[12][0];
    reg77=pos_nodes[13][1]*reg64; reg39=reg75-reg39; reg26=reg28+reg26; reg28=reg10*pos_nodes[11][1]; reg67=reg76+reg67;
    reg75=reg41*pos_nodes[10][2]; reg44=reg62+reg44; reg0=reg14*reg0; reg62=var_inter[1]*reg11; reg49=reg46+reg49;
    reg46=reg14*pos_nodes[12][1]; reg51=reg68-reg51; reg68=pos_nodes[9][2]*reg69; reg66=reg56-reg66; reg56=pos_nodes[13][0]*reg64;
    reg53=reg52+reg53; reg52=pos_nodes[14][0]*reg62; reg76=reg14*pos_nodes[14][0]; reg67=reg67-reg45; reg56=reg66-reg56;
    reg66=reg14*pos_nodes[14][2]; T reg78=pos_nodes[11][0]*reg1; T reg79=reg10*pos_nodes[11][2]; T reg80=pos_nodes[14][1]*reg62; reg77=reg39-reg77;
    reg28=reg26+reg28; reg26=reg0*pos_nodes[12][1]; reg75=reg44+reg75; reg39=var_inter[0]*reg14; reg44=reg14*pos_nodes[14][1];
    reg49=reg49-reg46; T reg81=pos_nodes[11][1]*reg1; reg68=reg51+reg68; reg51=pos_nodes[10][2]*reg1; reg74=reg54+reg74;
    reg54=pos_nodes[14][2]*reg62; reg15=reg59-reg15; reg59=reg0*pos_nodes[12][0]; reg55=reg50+reg55; reg58=reg58-reg72;
    reg50=reg0*pos_nodes[12][2]; T reg82=reg14*var_inter[1]; reg54=reg15-reg54; reg78=reg53-reg78; reg79=reg75+reg79;
    reg15=reg39*pos_nodes[13][1]; reg80=reg77-reg80; reg76=reg67+reg76; reg52=reg56-reg52; reg53=reg39*pos_nodes[13][0];
    reg66=reg58+reg66; reg59=reg55+reg59; reg26=reg28+reg26; reg28=pos_nodes[11][2]*reg1; reg51=reg68+reg51;
    reg44=reg49+reg44; reg81=reg74-reg81; reg28=reg51-reg28; reg46=reg81-reg46; reg49=reg76*reg54;
    reg51=reg52*reg66; reg55=reg82*pos_nodes[14][1]; reg26=reg15+reg26; reg50=reg79+reg50; reg15=reg14*pos_nodes[13][0];
    reg56=reg14*pos_nodes[13][1]; reg58=reg80*reg66; reg67=reg44*reg54; reg68=reg39*pos_nodes[13][2]; reg74=reg82*pos_nodes[14][0];
    reg59=reg53+reg59; reg45=reg78-reg45; reg53=reg76*reg80; reg50=reg68+reg50; reg58=reg67-reg58;
    reg51=reg49-reg51; reg68=reg52*reg44; reg75=reg82*pos_nodes[14][2]; reg45=reg15+reg45; reg72=reg28-reg72;
    reg46=reg56+reg46; reg74=reg59+reg74; reg15=reg14*pos_nodes[13][2]; reg55=reg26+reg55; reg72=reg15+reg72;
    reg15=reg45*reg58; reg74=pos[0]-reg74; reg26=reg46*reg51; reg55=pos[1]-reg55; reg68=reg53-reg68;
    reg28=var_inter[0]*reg46; reg56=var_inter[0]*reg45; reg75=reg50+reg75; reg50=reg46*reg54; reg59=reg80*reg72;
    reg77=reg72*reg68; reg15=reg26-reg15; reg26=reg46*reg66; reg78=reg44*reg72; reg79=reg45*reg54;
    reg81=reg52*reg72; T reg83=reg45*reg66; T reg84=reg76*reg72; T reg85=var_inter[1]*reg76; reg75=pos[2]-reg75;
    reg56=reg74+reg56; reg74=var_inter[0]*reg72; reg28=reg55+reg28; reg55=var_inter[1]*reg44; reg81=reg79-reg81;
    T reg86=var_inter[2]*reg52; reg78=reg26-reg78; T reg87=var_inter[2]*reg80; reg84=reg83-reg84; reg59=reg50-reg59;
    reg56=reg85+reg56; reg77=reg15-reg77; reg15=reg45*reg80; reg85=reg52*reg46; reg28=reg55+reg28;
    reg55=reg45*reg44; T reg88=var_inter[1]*reg66; reg74=reg75+reg74; reg75=reg76*reg46; reg84=reg84/reg77;
    reg75=reg55-reg75; reg85=reg15-reg85; reg81=reg81/reg77; reg51=reg51/reg77; reg78=reg78/reg77;
    reg59=reg59/reg77; reg56=reg86+reg56; reg58=reg58/reg77; reg86=var_inter[2]*reg54; reg28=reg87+reg28;
    reg74=reg88+reg74; reg59=reg56*reg59; reg51=reg28*reg51; reg81=reg28*reg81; reg78=reg56*reg78;
    reg84=reg28*reg84; reg58=reg56*reg58; reg75=reg75/reg77; reg85=reg85/reg77; reg77=reg68/reg77;
    reg74=reg86+reg74; reg77=reg74*reg77; reg58=reg51-reg58; reg85=reg74*reg85; reg81=reg59-reg81;
    reg75=reg74*reg75; reg78=reg84-reg78; var_inter[0]+=reg58-reg77; var_inter[1]+=reg85+reg81; var_inter[2]+=reg78-reg75;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=2*var_inter[2]; reg0=reg0-var_inter[1]; reg1=reg1-1; T reg2=2*var_inter[0];
    T reg3=2*reg0; T reg4=reg2-1; T reg5=0.5*var_inter[0]; T reg6=0.5*reg0; T reg7=reg3-1;
    T reg8=2*var_inter[1]; T reg9=pow(reg1,2); reg7=reg6*reg7; T reg10=1-reg1; reg9=1-reg9;
    reg4=reg5*reg4; T reg11=0.5*var_inter[1]; T reg12=reg8-1; reg6=reg6*reg9; T reg13=reg10*reg4;
    reg5=reg9*reg5; T reg14=reg7*reg10; reg12=reg11*reg12; reg14=reg14-reg6; reg13=reg13-reg5;
    T reg15=reg10*reg12; reg1=1+reg1; reg11=reg9*reg11; reg14=val[0]*reg14; reg15=reg15-reg11;
    reg7=reg7*reg1; reg13=val[1]*reg13; reg15=val[2]*reg15; reg13=reg14+reg13; reg6=reg7-reg6;
    reg4=reg4*reg1; reg15=reg13+reg15; reg6=val[3]*reg6; reg5=reg4-reg5; reg12=reg12*reg1;
    reg11=reg12-reg11; reg3=var_inter[0]*reg3; reg6=reg15+reg6; reg5=val[4]*reg5; reg11=val[5]*reg11;
    reg4=reg10*reg3; reg2=var_inter[1]*reg2; reg5=reg6+reg5; reg11=reg5+reg11; reg4=val[6]*reg4;
    reg5=reg10*reg2; reg8=reg0*reg8; reg5=val[7]*reg5; reg10=reg10*reg8; reg4=reg11+reg4;
    reg5=reg4+reg5; reg10=val[8]*reg10; reg3=reg1*reg3; reg3=val[9]*reg3; reg2=reg1*reg2;
    reg10=reg5+reg10; reg3=reg10+reg3; reg2=val[10]*reg2; reg8=reg1*reg8; reg8=val[11]*reg8;
    reg0=reg0*reg9; reg2=reg3+reg2; reg0=val[12]*reg0; reg1=var_inter[0]*reg9; reg8=reg2+reg8;
    reg0=reg8+reg0; reg1=val[13]*reg1; reg9=var_inter[1]*reg9; reg1=reg0+reg1; reg9=val[14]*reg9;
    res=reg1+reg9;

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Wedge_15> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

}
#endif // LMT_WEDGE_15
