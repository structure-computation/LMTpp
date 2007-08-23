#ifndef LMT_WEDGE_15
#define LMT_WEDGE_15
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Wedge_15 &elem) { /// order -> degre du polynome a integrer exactement
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
template<class TNode> void permutation_if_jac_neg(const Wedge_15 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=nodes[0]->pos[2]+nodes[3]->pos[2]; T reg1=nodes[0]->pos[1]+nodes[3]->pos[1]; reg0=reg0-nodes[6]->pos[2]; reg1=reg1-nodes[6]->pos[1]; reg1=nodes[7]->pos[1]+reg1;
    T reg2=nodes[0]->pos[0]+nodes[3]->pos[0]; reg0=nodes[7]->pos[2]+reg0; reg2=reg2-nodes[6]->pos[0]; reg1=reg1-nodes[8]->pos[1]; reg0=reg0-nodes[8]->pos[2];
    reg0=reg0-nodes[9]->pos[2]; reg1=reg1-nodes[9]->pos[1]; reg2=nodes[7]->pos[0]+reg2; reg1=nodes[10]->pos[1]+reg1; reg2=reg2-nodes[8]->pos[0];
    reg0=nodes[10]->pos[2]+reg0; reg2=reg2-nodes[9]->pos[0]; reg1=reg1-nodes[11]->pos[1]; reg0=reg0-nodes[11]->pos[2]; reg1=reg1-nodes[12]->pos[1];
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*reg0; T reg3=2*var_inter[0];
    T reg4=0.5*var_inter[0]; T reg5=0.5*reg0; reg1=reg1-1; T reg6=2*var_inter[1]; T reg7=reg2-1;
    T reg8=reg3-1; T reg9=reg4*reg8; T reg10=0.5*var_inter[1]; T reg11=4*reg1; T reg12=reg6-1;
    T reg13=reg5*reg7; T reg14=2*reg9; T reg15=reg10*reg12; T reg16=pow(reg1,2); T reg17=reg11*reg4;
    T reg18=2*reg13; T reg19=reg5*reg11; reg12=0.5*reg12; T reg20=reg17-reg14; reg7=0.5*reg7;
    T reg21=reg19-reg18; T reg22=2*reg15; T reg23=reg10*reg11; reg16=1-reg16; T reg24=1-reg1;
    T reg25=reg24*reg9; reg7=reg0+reg7; reg5=reg5*reg16; T reg26=reg13*reg24; T reg27=pos_nodes[0][2]*reg21;
    T reg28=pos_nodes[1][2]*reg20; T reg29=pos_nodes[0][1]*reg21; reg12=var_inter[1]+reg12; T reg30=pos_nodes[1][1]*reg20; T reg31=pos_nodes[0][0]*reg21;
    T reg32=pos_nodes[1][0]*reg20; T reg33=reg23-reg22; reg4=reg16*reg4; reg8=0.5*reg8; T reg34=0.5*reg16;
    T reg35=reg7*reg24; T reg36=reg12*reg24; T reg37=reg18+reg19; reg31=reg32+reg31; reg32=pos_nodes[2][0]*reg33;
    reg29=reg30+reg29; reg30=pos_nodes[2][1]*reg33; reg25=reg25-reg4; T reg38=reg15*reg24; reg10=reg10*reg16;
    reg26=reg26-reg5; reg1=1+reg1; reg27=reg28+reg27; reg28=pos_nodes[2][2]*reg33; reg38=reg38-reg10;
    T reg39=reg34-reg35; T reg40=reg1*reg7; reg13=reg1*reg13; reg36=reg36-reg34; T reg41=pos_nodes[3][2]*reg37;
    reg28=reg27+reg28; reg27=reg14+reg17; T reg42=pos_nodes[0][1]*reg26; T reg43=reg25*pos_nodes[1][1]; reg32=reg31+reg32;
    reg31=pos_nodes[3][0]*reg37; T reg44=reg25*pos_nodes[1][0]; T reg45=pos_nodes[0][0]*reg26; T reg46=pos_nodes[3][1]*reg37; reg30=reg29+reg30;
    reg8=var_inter[0]+reg8; reg29=pos_nodes[4][2]*reg27; reg41=reg28+reg41; reg28=pos_nodes[2][2]*reg36; T reg47=pos_nodes[0][2]*reg39;
    T reg48=reg38*pos_nodes[2][1]; reg42=reg43+reg42; reg43=pos_nodes[4][1]*reg27; reg46=reg30+reg46; reg12=reg1*reg12;
    reg30=pos_nodes[2][1]*reg36; T reg49=pos_nodes[0][1]*reg39; T reg50=reg38*pos_nodes[2][0]; T reg51=pos_nodes[2][0]*reg36; reg45=reg44+reg45;
    reg44=pos_nodes[4][0]*reg27; reg31=reg32+reg31; reg32=reg22+reg23; reg9=reg1*reg9; reg5=reg13-reg5;
    reg13=pos_nodes[0][0]*reg39; T reg52=var_inter[0]*reg2; T reg53=reg34-reg40; T reg54=pos_nodes[0][2]*reg26; T reg55=reg25*pos_nodes[1][2];
    T reg56=reg8*reg24; reg44=reg31+reg44; reg31=pos_nodes[5][0]*reg32; reg50=reg45+reg50; reg45=reg5*pos_nodes[3][0];
    T reg57=pos_nodes[3][1]*reg53; T reg58=2*reg52; reg30=reg49+reg30; reg4=reg9-reg4; reg43=reg46+reg43;
    reg9=pos_nodes[5][1]*reg32; reg15=reg15*reg1; reg48=reg42+reg48; reg42=reg5*pos_nodes[3][1]; reg46=reg38*pos_nodes[2][2];
    T reg59=pos_nodes[3][2]*reg53; reg54=reg55+reg54; reg28=reg47+reg28; reg55=var_inter[1]*reg3; reg29=reg41+reg29;
    reg41=pos_nodes[5][2]*reg32; reg12=reg12-reg34; reg51=reg13+reg51; T reg60=pos_nodes[3][0]*reg53; reg56=reg56-reg34;
    T reg61=2*reg55; T reg62=pos_nodes[6][2]*reg58; reg41=reg29+reg41; reg29=pos_nodes[5][0]*reg12; reg51=reg60+reg51;
    reg31=reg44+reg31; reg44=pos_nodes[6][0]*reg58; T reg63=pos_nodes[5][2]*reg12; reg28=reg59+reg28; reg8=reg1*reg8;
    reg45=reg50+reg45; reg50=reg4*pos_nodes[4][0]; T reg64=reg4*pos_nodes[4][1]; reg42=reg48+reg42; reg48=pos_nodes[6][1]*reg58;
    reg9=reg43+reg9; reg43=pos_nodes[1][1]*reg56; T reg65=reg24*reg3; T reg66=reg6*reg0; T reg67=pos_nodes[5][1]*reg12;
    reg30=reg57+reg30; reg10=reg15-reg10; reg15=reg5*pos_nodes[3][2]; reg46=reg54+reg46; reg54=pos_nodes[1][0]*reg56;
    T reg68=reg52*reg24; T reg69=reg2-reg6; T reg70=pos_nodes[6][2]*reg65; reg63=reg28+reg63; reg15=reg46+reg15;
    reg8=reg8-reg34; reg48=reg9-reg48; reg9=pos_nodes[7][1]*reg61; reg28=pos_nodes[1][2]*reg56; reg46=reg4*pos_nodes[4][2];
    reg50=reg45+reg50; reg45=reg10*pos_nodes[5][0]; reg64=reg42+reg64; reg42=reg10*pos_nodes[5][1]; T reg71=pos_nodes[7][2]*reg61;
    reg62=reg41-reg62; reg41=pos_nodes[6][1]*reg65; reg67=reg30+reg67; reg30=pos_nodes[6][0]*reg65; reg29=reg51+reg29;
    reg2=reg2-reg3; reg44=reg31-reg44; reg31=2*reg66; reg51=pos_nodes[7][0]*reg61; reg13=reg54+reg13;
    reg49=reg43+reg49; reg43=reg10*pos_nodes[5][2]; reg54=reg2*reg24; reg41=reg67-reg41; reg67=pos_nodes[8][1]*reg31;
    reg9=reg48-reg9; reg48=pos_nodes[7][1]*reg65; T reg72=reg55*reg24; T reg73=pos_nodes[4][1]*reg8; reg57=reg49+reg57;
    reg30=reg29-reg30; reg29=pos_nodes[8][2]*reg31; reg71=reg62-reg71; reg49=pos_nodes[7][0]*reg65; reg62=pos_nodes[4][0]*reg8;
    reg60=reg13+reg60; reg51=reg44-reg51; reg13=pos_nodes[8][0]*reg31; reg44=pos_nodes[7][2]*reg65; reg70=reg63-reg70;
    reg47=reg28+reg47; reg42=reg64+reg42; reg28=reg68*pos_nodes[6][1]; reg63=reg68*pos_nodes[6][0]; reg45=reg50+reg45;
    reg50=reg69*reg24; reg46=reg15+reg46; reg15=pos_nodes[9][2]*reg58; reg64=reg6*reg24; reg29=reg71-reg29;
    reg48=reg41+reg48; reg41=pos_nodes[8][1]*reg50; reg71=pos_nodes[6][0]*reg54; reg62=reg60+reg62; reg43=reg46+reg43;
    reg46=pos_nodes[9][1]*reg58; reg60=pos_nodes[8][2]*reg50; reg44=reg70+reg44; reg67=reg9-reg67; reg28=reg42+reg28;
    reg9=pos_nodes[4][2]*reg8; reg42=reg68*pos_nodes[6][2]; reg59=reg47+reg59; reg47=reg72*pos_nodes[7][1]; reg70=pos_nodes[9][0]*reg58;
    reg13=reg51-reg13; reg51=pos_nodes[6][1]*reg54; reg73=reg57+reg73; reg24=reg66*reg24; reg57=reg1*reg3;
    reg63=reg45+reg63; reg45=reg72*pos_nodes[7][0]; T reg74=pos_nodes[8][0]*reg50; reg49=reg30+reg49; reg45=reg63+reg45;
    reg30=reg24*pos_nodes[8][0]; reg63=pos_nodes[10][1]*reg61; reg47=reg28+reg47; reg28=reg24*pos_nodes[8][1]; reg46=reg67+reg46;
    reg9=reg59+reg9; reg59=pos_nodes[6][2]*reg54; reg67=pos_nodes[10][0]*reg61; reg60=reg44+reg60; reg44=pos_nodes[9][2]*reg57;
    reg70=reg13+reg70; reg13=pos_nodes[7][0]*reg64; reg71=reg62+reg71; reg52=reg1*reg52; reg15=reg29+reg15;
    reg29=pos_nodes[10][2]*reg61; reg42=reg43+reg42; reg43=reg72*pos_nodes[7][2]; reg62=pos_nodes[9][0]*reg57; reg74=reg49+reg74;
    reg49=pos_nodes[9][1]*reg57; reg41=reg48+reg41; reg48=pos_nodes[7][1]*reg64; reg51=reg73+reg51; reg49=reg41-reg49;
    reg41=pos_nodes[7][2]*reg64; reg73=reg52*pos_nodes[9][0]; reg30=reg45+reg30; reg59=reg9+reg59; reg9=pos_nodes[11][0]*reg31;
    reg45=reg24*pos_nodes[8][2]; reg43=reg42+reg43; reg69=reg1*reg69; reg28=reg47+reg28; reg42=reg52*pos_nodes[9][1];
    reg67=reg70+reg67; reg47=pos_nodes[10][1]*reg57; reg55=reg1*reg55; reg44=reg60-reg44; reg60=pos_nodes[10][2]*reg57;
    reg62=reg74-reg62; reg70=pos_nodes[10][0]*reg57; reg2=reg1*reg2; reg74=reg0*reg11; reg29=reg15+reg29;
    reg15=pos_nodes[11][2]*reg31; reg63=reg46+reg63; reg46=pos_nodes[11][1]*reg31; T reg75=pos_nodes[8][1]*reg64; reg13=reg71+reg13;
    reg71=pos_nodes[8][0]*reg64; reg48=reg51+reg48; reg51=pos_nodes[12][2]*reg74; T reg76=pos_nodes[12][0]*reg74; reg15=reg29+reg15;
    reg29=pos_nodes[11][1]*reg69; reg47=reg49+reg47; reg49=var_inter[0]*reg11; reg9=reg67+reg9; reg66=reg1*reg66;
    reg67=pos_nodes[8][2]*reg64; reg41=reg59+reg41; reg1=reg6*reg1; reg59=pos_nodes[9][1]*reg2; reg75=reg48-reg75;
    reg70=reg62+reg70; reg48=pos_nodes[11][0]*reg69; reg46=reg63+reg46; reg62=pos_nodes[12][1]*reg74; reg71=reg13-reg71;
    reg13=reg55*pos_nodes[10][0]; reg73=reg30+reg73; reg30=pos_nodes[9][0]*reg2; reg63=reg52*pos_nodes[9][2]; reg45=reg43+reg45;
    reg42=reg28+reg42; reg28=reg55*pos_nodes[10][1]; reg43=pos_nodes[11][2]*reg69; reg60=reg44+reg60; reg59=reg75+reg59;
    reg44=pos_nodes[10][1]*reg1; reg43=reg60+reg43; reg76=reg9-reg76; reg9=pos_nodes[13][0]*reg49; reg60=var_inter[1]*reg11;
    reg30=reg71+reg30; reg71=pos_nodes[12][1]*reg16; reg75=reg66*pos_nodes[11][0]; reg13=reg73+reg13; reg62=reg46-reg62;
    reg46=pos_nodes[13][1]*reg49; reg48=reg70+reg48; reg70=reg55*pos_nodes[10][2]; reg73=pos_nodes[12][0]*reg16; reg63=reg45+reg63;
    reg28=reg42+reg28; reg42=reg66*pos_nodes[11][1]; reg45=pos_nodes[10][0]*reg1; T reg77=pos_nodes[12][2]*reg16; T reg78=pos_nodes[9][2]*reg2;
    reg67=reg41-reg67; reg29=reg47+reg29; reg51=reg15-reg51; reg15=pos_nodes[13][2]*reg49; reg0=reg0*reg16;
    reg15=reg51-reg15; reg41=pos_nodes[14][2]*reg60; reg70=reg63+reg70; reg47=reg66*pos_nodes[11][2]; reg48=reg48-reg73;
    reg51=var_inter[0]*reg16; reg63=pos_nodes[11][1]*reg1; T reg79=pos_nodes[14][0]*reg16; reg44=reg59+reg44; reg59=pos_nodes[11][0]*reg1;
    T reg80=pos_nodes[14][2]*reg16; reg43=reg43-reg77; reg9=reg76-reg9; reg75=reg13+reg75; reg13=reg0*pos_nodes[12][0];
    reg76=pos_nodes[14][1]*reg16; T reg81=pos_nodes[14][1]*reg60; reg46=reg62-reg46; reg62=reg0*pos_nodes[12][1]; T reg82=pos_nodes[10][2]*reg1;
    reg78=reg67+reg78; reg29=reg29-reg71; reg67=pos_nodes[14][0]*reg60; reg42=reg28+reg42; reg45=reg30+reg45;
    reg79=reg48+reg79; reg62=reg42+reg62; reg28=reg51*pos_nodes[13][1]; reg63=reg44-reg63; reg59=reg45-reg59;
    reg81=reg46-reg81; reg47=reg70+reg47; reg30=reg0*pos_nodes[12][2]; reg42=var_inter[1]*reg16; reg13=reg75+reg13;
    reg76=reg29+reg76; reg41=reg15-reg41; reg67=reg9-reg67; reg82=reg78+reg82; reg9=pos_nodes[11][2]*reg1;
    reg15=reg51*pos_nodes[13][0]; reg80=reg43+reg80; reg29=reg51*pos_nodes[13][2]; reg15=reg13+reg15; reg71=reg63-reg71;
    reg13=reg76*reg41; reg43=reg81*reg80; reg44=pos_nodes[13][1]*reg16; reg45=reg79*reg41; reg46=reg67*reg80;
    reg48=reg42*pos_nodes[14][0]; reg73=reg59-reg73; reg59=pos_nodes[13][0]*reg16; reg28=reg62+reg28; reg62=reg42*pos_nodes[14][1];
    reg9=reg82-reg9; reg30=reg47+reg30; reg43=reg13-reg43; reg47=reg79*reg81; reg29=reg30+reg29;
    reg46=reg45-reg46; reg30=reg67*reg76; reg48=reg15+reg48; reg59=reg73+reg59; reg15=reg42*pos_nodes[14][2];
    reg62=reg28+reg62; reg44=reg71+reg44; reg77=reg9-reg77; reg9=pos_nodes[13][2]*reg16; reg48=pos[0]-reg48;
    reg9=reg77+reg9; reg30=reg47-reg30; reg62=pos[1]-reg62; reg28=reg44*reg46; reg15=reg29+reg15;
    reg29=var_inter[0]*reg59; reg63=var_inter[0]*reg44; reg70=reg59*reg43; reg63=reg62+reg63; reg62=var_inter[1]*reg76;
    reg29=reg48+reg29; reg48=var_inter[1]*reg79; reg15=pos[2]-reg15; reg71=reg79*reg9; reg73=reg59*reg80;
    reg75=reg67*reg9; reg77=reg59*reg41; reg78=reg76*reg9; reg82=reg44*reg80; T reg83=reg81*reg9;
    T reg84=reg44*reg41; reg70=reg28-reg70; reg28=var_inter[0]*reg9; T reg85=reg9*reg30; reg63=reg62+reg63;
    reg28=reg15+reg28; reg15=var_inter[1]*reg80; reg29=reg48+reg29; reg48=var_inter[2]*reg81; reg62=reg79*reg44;
    T reg86=var_inter[2]*reg67; T reg87=reg59*reg76; T reg88=reg67*reg44; T reg89=reg59*reg81; reg83=reg84-reg83;
    reg71=reg73-reg71; reg75=reg77-reg75; reg78=reg82-reg78; reg85=reg70-reg85; reg70=var_inter[2]*reg41;
    reg83=reg83/reg85; reg78=reg78/reg85; reg29=reg86+reg29; reg28=reg15+reg28; reg46=reg46/reg85;
    reg63=reg48+reg63; reg62=reg87-reg62; reg75=reg75/reg85; reg88=reg89-reg88; reg43=reg43/reg85;
    reg71=reg71/reg85; reg28=reg70+reg28; reg71=reg63*reg71; reg30=reg30/reg85; reg78=reg29*reg78;
    reg88=reg88/reg85; reg85=reg62/reg85; reg43=reg29*reg43; reg75=reg63*reg75; reg46=reg63*reg46;
    reg83=reg29*reg83; reg30=reg28*reg30; reg43=reg46-reg43; reg88=reg28*reg88; reg75=reg83-reg75;
    reg78=reg71-reg78; reg85=reg28*reg85; var_inter[0]=reg43-reg30; var_inter[1]=reg88+reg75; var_inter[2]=reg78-reg85;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*var_inter[2]; T reg3=2*reg0;
    T reg4=0.5*var_inter[0]; T reg5=reg1-1; reg2=reg2-1; T reg6=2*var_inter[1]; T reg7=0.5*reg0;
    T reg8=reg3-1; T reg9=4*reg2; T reg10=reg4*reg5; T reg11=0.5*var_inter[1]; T reg12=reg6-1;
    T reg13=reg7*reg8; T reg14=2*reg13; T reg15=reg9*reg7; T reg16=pow(reg2,2); T reg17=reg11*reg12;
    T reg18=2*reg10; T reg19=reg9*reg4; reg12=0.5*reg12; T reg20=reg15-reg14; reg8=0.5*reg8;
    T reg21=reg19-reg18; T reg22=2*reg17; T reg23=reg9*reg11; T reg24=1-reg2; reg16=1-reg16;
    T reg25=reg20*pos_nodes[0][1]; T reg26=reg21*pos_nodes[1][0]; T reg27=reg20*pos_nodes[0][0]; T reg28=reg23-reg22; T reg29=reg10*reg24;
    reg4=reg4*reg16; T reg30=reg21*pos_nodes[1][1]; T reg31=reg20*pos_nodes[0][2]; reg7=reg7*reg16; T reg32=reg21*pos_nodes[1][2];
    T reg33=reg13*reg24; reg12=reg12+var_inter[1]; reg8=reg8+reg0; reg30=reg25+reg30; reg25=reg28*pos_nodes[2][1];
    T reg34=reg12*reg24; T reg35=reg8*reg24; reg32=reg31+reg32; reg31=reg28*pos_nodes[2][2]; T reg36=reg28*pos_nodes[2][0];
    reg26=reg27+reg26; reg29=reg29-reg4; reg27=reg17*reg24; reg11=reg11*reg16; reg2=1+reg2;
    T reg37=reg14+reg15; T reg38=0.5*reg16; reg5=0.5*reg5; reg33=reg33-reg7; T reg39=pos_nodes[3][1]*reg37;
    reg5=reg5+var_inter[0]; reg25=reg30+reg25; reg30=reg29*pos_nodes[1][0]; T reg40=pos_nodes[0][1]*reg33; T reg41=reg29*pos_nodes[1][1];
    reg34=reg34-reg38; T reg42=reg38-reg35; T reg43=pos_nodes[0][0]*reg33; reg36=reg26+reg36; reg27=reg27-reg11;
    reg26=pos_nodes[3][2]*reg37; reg31=reg32+reg31; reg32=pos_nodes[3][0]*reg37; T reg44=reg8*reg2; reg13=reg2*reg13;
    T reg45=reg18+reg19; T reg46=reg27*pos_nodes[2][0]; reg30=reg43+reg30; reg43=reg22+reg23; T reg47=reg38-reg44;
    T reg48=pos_nodes[4][0]*reg45; reg36=reg32+reg36; reg32=reg3*var_inter[0]; reg10=reg10*reg2; reg7=reg13-reg7;
    reg13=reg29*pos_nodes[1][2]; T reg49=reg33*pos_nodes[0][2]; T reg50=pos_nodes[4][2]*reg45; reg31=reg26+reg31; reg26=reg34*pos_nodes[2][2];
    T reg51=reg42*pos_nodes[0][2]; T reg52=reg27*pos_nodes[2][1]; reg41=reg40+reg41; reg40=pos_nodes[4][1]*reg45; reg25=reg39+reg25;
    reg39=reg34*pos_nodes[2][1]; T reg53=reg42*pos_nodes[0][1]; T reg54=reg5*reg24; T reg55=reg42*pos_nodes[0][0]; T reg56=reg34*pos_nodes[2][0];
    reg12=reg12*reg2; T reg57=pos_nodes[3][0]*reg7; reg46=reg30+reg46; reg30=pos_nodes[3][1]*reg47; reg39=reg53+reg39;
    reg56=reg55+reg56; reg40=reg25+reg40; reg25=pos_nodes[5][1]*reg43; T reg58=pos_nodes[3][1]*reg7; reg12=reg12-reg38;
    reg52=reg41+reg52; reg41=pos_nodes[3][2]*reg47; reg26=reg51+reg26; reg50=reg31+reg50; reg31=pos_nodes[5][2]*reg43;
    reg13=reg49+reg13; reg49=reg27*pos_nodes[2][2]; reg4=reg10-reg4; reg17=reg17*reg2; reg10=pos_nodes[3][0]*reg47;
    reg54=reg54-reg38; T reg59=reg1*var_inter[1]; T reg60=2*reg32; reg48=reg36+reg48; reg36=pos_nodes[5][0]*reg43;
    T reg61=pos_nodes[5][0]*reg12; T reg62=reg54*pos_nodes[1][1]; reg56=reg10+reg56; reg39=reg30+reg39; T reg63=pos_nodes[5][1]*reg12;
    reg25=reg40+reg25; reg40=pos_nodes[6][1]*reg60; T reg64=reg1*reg24; reg52=reg58+reg52; reg58=pos_nodes[4][1]*reg4;
    reg26=reg41+reg26; T reg65=pos_nodes[5][2]*reg12; T reg66=2*reg59; reg31=reg50+reg31; reg50=pos_nodes[6][2]*reg60;
    T reg67=pos_nodes[3][2]*reg7; reg49=reg13+reg49; reg11=reg17-reg11; reg13=reg54*pos_nodes[1][0]; reg5=reg5*reg2;
    reg17=reg6*reg0; reg36=reg48+reg36; reg48=pos_nodes[6][0]*reg60; reg46=reg57+reg46; reg57=pos_nodes[4][0]*reg4;
    T reg68=pos_nodes[5][0]*reg11; reg61=reg56+reg61; reg62=reg53+reg62; reg53=pos_nodes[4][2]*reg4; reg49=reg67+reg49;
    reg56=reg66*pos_nodes[7][2]; reg50=reg31-reg50; reg31=pos_nodes[6][2]*reg64; reg65=reg26+reg65; reg26=2*reg17;
    reg67=reg54*pos_nodes[1][2]; T reg69=pos_nodes[5][1]*reg11; reg58=reg52+reg58; reg52=pos_nodes[6][0]*reg64; T reg70=reg66*pos_nodes[7][1];
    reg63=reg39+reg63; reg39=pos_nodes[6][1]*reg64; reg40=reg25-reg40; reg25=reg3-reg6; reg3=reg3-reg1;
    reg5=reg5-reg38; reg13=reg55+reg13; reg55=pos_nodes[7][0]*reg66; reg48=reg36-reg48; reg57=reg46+reg57;
    reg36=reg32*reg24; reg70=reg40-reg70; reg40=pos_nodes[8][1]*reg26; reg46=reg59*reg24; reg55=reg48-reg55;
    reg48=reg36*pos_nodes[6][1]; T reg71=reg36*pos_nodes[6][0]; T reg72=pos_nodes[8][0]*reg26; T reg73=reg25*reg24; reg69=reg58+reg69;
    reg67=reg51+reg67; reg51=reg3*reg24; reg31=reg65-reg31; reg58=reg64*pos_nodes[7][2]; reg56=reg50-reg56;
    reg50=pos_nodes[8][2]*reg26; reg13=reg10+reg13; reg10=pos_nodes[4][0]*reg5; reg53=reg49+reg53; reg49=pos_nodes[5][2]*reg11;
    reg68=reg57+reg68; reg62=reg30+reg62; reg30=pos_nodes[4][1]*reg5; reg52=reg61-reg52; reg57=pos_nodes[7][0]*reg64;
    reg39=reg63-reg39; reg61=reg64*pos_nodes[7][1]; reg57=reg52+reg57; reg49=reg53+reg49; reg30=reg62+reg30;
    reg50=reg56-reg50; reg52=pos_nodes[9][2]*reg60; reg69=reg48+reg69; reg48=reg46*pos_nodes[7][1]; reg53=pos_nodes[8][2]*reg73;
    reg58=reg31+reg58; reg31=pos_nodes[9][1]*reg60; reg40=reg70-reg40; reg56=pos_nodes[8][0]*reg73; reg62=reg36*pos_nodes[6][2];
    reg63=pos_nodes[9][0]*reg60; reg65=pos_nodes[6][1]*reg51; reg10=reg13+reg10; reg72=reg55-reg72; reg61=reg39+reg61;
    reg13=pos_nodes[8][1]*reg73; reg39=reg1*reg2; reg55=pos_nodes[6][0]*reg51; reg70=reg6*reg24; reg24=reg17*reg24;
    T reg74=pos_nodes[4][2]*reg5; reg67=reg41+reg67; reg41=reg46*pos_nodes[7][0]; reg68=reg71+reg68; reg52=reg50+reg52;
    reg30=reg65+reg30; reg50=reg70*pos_nodes[7][1]; reg65=pos_nodes[9][2]*reg39; reg53=reg58+reg53; reg74=reg67+reg74;
    reg58=pos_nodes[6][2]*reg51; reg67=pos_nodes[10][2]*reg66; reg71=pos_nodes[10][0]*reg66; reg63=reg72+reg63; reg72=pos_nodes[9][1]*reg39;
    reg49=reg62+reg49; reg62=reg46*pos_nodes[7][2]; reg32=reg32*reg2; T reg75=pos_nodes[7][0]*reg70; reg10=reg55+reg10;
    reg55=reg24*pos_nodes[8][0]; reg41=reg68+reg41; reg13=reg61+reg13; reg56=reg57+reg56; reg57=pos_nodes[10][1]*reg66;
    reg61=reg24*pos_nodes[8][1]; reg48=reg69+reg48; reg68=pos_nodes[9][0]*reg39; reg31=reg40+reg31; reg40=pos_nodes[10][0]*reg39;
    reg75=reg10+reg75; reg25=reg25*reg2; reg10=pos_nodes[11][2]*reg26; reg67=reg52+reg67; reg52=pos_nodes[11][1]*reg26;
    reg57=reg31+reg57; reg68=reg56-reg68; reg31=pos_nodes[8][0]*reg70; reg50=reg30+reg50; reg30=pos_nodes[8][1]*reg70;
    reg71=reg63+reg71; reg56=pos_nodes[11][0]*reg26; reg63=reg24*pos_nodes[8][2]; reg62=reg49+reg62; reg55=reg41+reg55;
    reg59=reg59*reg2; reg41=pos_nodes[10][1]*reg39; reg49=pos_nodes[9][0]*reg32; reg72=reg13-reg72; reg13=reg9*reg0;
    reg3=reg3*reg2; reg69=pos_nodes[10][2]*reg39; T reg76=pos_nodes[9][1]*reg32; reg61=reg48+reg61; reg74=reg58+reg74;
    reg48=reg70*pos_nodes[7][2]; reg65=reg53-reg65; reg56=reg71+reg56; reg41=reg72+reg41; reg40=reg68+reg40;
    reg53=reg9*var_inter[0]; reg10=reg67+reg10; reg58=pos_nodes[12][2]*reg13; reg52=reg57+reg52; reg57=pos_nodes[9][0]*reg3;
    reg31=reg75-reg31; reg67=pos_nodes[11][0]*reg25; reg17=reg17*reg2; reg63=reg62+reg63; reg62=pos_nodes[9][2]*reg32;
    reg68=pos_nodes[12][1]*reg13; reg2=reg6*reg2; reg71=pos_nodes[10][0]*reg59; reg72=pos_nodes[8][2]*reg70; reg48=reg74+reg48;
    reg76=reg61+reg76; reg49=reg55+reg49; reg55=pos_nodes[10][1]*reg59; reg61=pos_nodes[12][0]*reg13; reg74=pos_nodes[9][1]*reg3;
    reg75=pos_nodes[11][1]*reg25; T reg77=pos_nodes[11][2]*reg25; reg69=reg65+reg69; reg30=reg50-reg30; reg0=reg0*reg16;
    reg50=pos_nodes[11][1]*reg17; reg68=reg52-reg68; reg52=pos_nodes[13][1]*reg53; reg62=reg63+reg62; reg63=pos_nodes[10][2]*reg59;
    reg55=reg76+reg55; reg65=reg9*var_inter[1]; reg72=reg48-reg72; reg48=pos_nodes[9][2]*reg3; reg76=pos_nodes[12][0]*reg16;
    reg75=reg41+reg75; reg77=reg69+reg77; reg41=pos_nodes[10][0]*reg2; reg57=reg31+reg57; reg31=pos_nodes[12][1]*reg16;
    reg74=reg30+reg74; reg30=pos_nodes[10][1]*reg2; reg61=reg56-reg61; reg56=pos_nodes[13][0]*reg53; reg69=pos_nodes[11][0]*reg17;
    reg71=reg49+reg71; reg49=pos_nodes[12][2]*reg16; reg67=reg40+reg67; reg58=reg10-reg58; reg10=pos_nodes[13][2]*reg53;
    reg40=var_inter[0]*reg16; T reg78=pos_nodes[12][0]*reg0; T reg79=pos_nodes[14][0]*reg16; reg69=reg71+reg69; reg71=pos_nodes[14][1]*reg16;
    reg75=reg75-reg31; reg67=reg67-reg76; reg63=reg62+reg63; reg52=reg68-reg52; reg62=pos_nodes[14][1]*reg65;
    reg68=pos_nodes[14][2]*reg65; reg10=reg58-reg10; reg58=pos_nodes[14][0]*reg65; reg56=reg61-reg56; reg41=reg57+reg41;
    reg57=pos_nodes[11][0]*reg2; reg61=pos_nodes[14][2]*reg16; reg77=reg77-reg49; reg30=reg74+reg30; reg74=pos_nodes[10][2]*reg2;
    reg48=reg72+reg48; reg72=pos_nodes[11][1]*reg2; T reg80=pos_nodes[12][1]*reg0; reg50=reg55+reg50; reg55=pos_nodes[11][2]*reg17;
    T reg81=pos_nodes[12][2]*reg0; reg61=reg77+reg61; reg72=reg30-reg72; reg74=reg48+reg74; reg30=pos_nodes[11][2]*reg2;
    reg57=reg41-reg57; reg41=reg16*var_inter[1]; reg58=reg56-reg58; reg68=reg10-reg68; reg78=reg69+reg78;
    reg62=reg52-reg62; reg10=pos_nodes[13][0]*reg40; reg48=pos_nodes[13][1]*reg40; reg80=reg50+reg80; reg71=reg75+reg71;
    reg79=reg67+reg79; reg55=reg63+reg55; reg31=reg72-reg31; reg76=reg57-reg76; reg10=reg78+reg10;
    reg30=reg74-reg30; reg50=pos_nodes[14][0]*reg41; reg52=pos_nodes[13][2]*reg40; reg81=reg55+reg81; reg55=pos_nodes[13][0]*reg16;
    reg56=reg58*reg61; reg57=reg79*reg68; reg63=pos_nodes[13][1]*reg16; reg67=reg62*reg61; reg69=reg71*reg68;
    reg72=pos_nodes[14][1]*reg41; reg48=reg80+reg48; reg74=pos_nodes[14][2]*reg41; reg50=reg10+reg50; reg55=reg76+reg55;
    reg63=reg31+reg63; reg52=reg81+reg52; reg72=reg48+reg72; reg10=pos_nodes[13][2]*reg16; reg49=reg30-reg49;
    reg67=reg69-reg67; reg30=reg58*reg71; reg56=reg57-reg56; reg31=reg79*reg62; reg48=reg63*var_inter[0];
    reg72=pos[1]-reg72; reg75=reg55*reg67; reg76=reg55*var_inter[0]; reg77=reg63*reg56; reg30=reg31-reg30;
    reg74=reg52+reg74; reg50=pos[0]-reg50; reg10=reg49+reg10; reg74=pos[2]-reg74; reg49=reg79*var_inter[1];
    reg76=reg50+reg76; reg50=reg71*reg10; reg52=reg55*reg68; reg78=reg58*reg10; reg80=reg55*reg61;
    reg81=reg79*reg10; T reg82=reg63*reg61; T reg83=reg62*reg10; T reg84=reg63*reg68; T reg85=reg10*reg30;
    reg75=reg77-reg75; reg77=reg71*var_inter[1]; T reg86=reg10*var_inter[0]; reg48=reg72+reg48; reg78=reg52-reg78;
    reg48=reg77+reg48; reg83=reg84-reg83; reg81=reg80-reg81; reg72=reg55*reg62; reg77=reg58*reg63;
    T reg87=reg55*reg71; T reg88=reg79*reg63; reg50=reg82-reg50; T reg89=reg58*var_inter[2]; T reg90=reg61*var_inter[1];
    reg85=reg75-reg85; reg76=reg49+reg76; reg86=reg74+reg86; reg49=reg62*var_inter[2]; reg56=reg56/reg85;
    reg74=reg68*var_inter[2]; reg78=reg78/reg85; reg50=reg50/reg85; reg83=reg83/reg85; reg81=reg81/reg85;
    reg77=reg72-reg77; reg48=reg49+reg48; reg76=reg89+reg76; reg88=reg87-reg88; reg67=reg67/reg85;
    reg86=reg90+reg86; reg86=reg74+reg86; reg50=reg76*reg50; reg81=reg48*reg81; reg78=reg48*reg78;
    reg83=reg76*reg83; reg56=reg48*reg56; reg67=reg76*reg67; reg88=reg88/reg85; reg77=reg77/reg85;
    reg85=reg30/reg85; reg85=reg86*reg85; reg67=reg56-reg67; reg77=reg86*reg77; reg78=reg83-reg78;
    reg50=reg81-reg50; reg88=reg86*reg88; var_inter[0]+=reg67-reg85; var_inter[2]+=reg50-reg88; var_inter[1]+=reg77+reg78;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*reg0; reg1=reg1-1;
    T reg3=2*var_inter[0]; T reg4=pow(reg1,2); T reg5=reg2-1; T reg6=0.5*reg0; T reg7=0.5*var_inter[0];
    T reg8=reg3-1; T reg9=2*var_inter[1]; reg4=1-reg4; reg8=reg7*reg8; T reg10=0.5*var_inter[1];
    T reg11=reg9-1; reg5=reg6*reg5; T reg12=1-reg1; reg6=reg6*reg4; T reg13=reg12*reg8;
    reg7=reg4*reg7; T reg14=reg5*reg12; reg11=reg10*reg11; T reg15=reg12*reg11; reg13=reg13-reg7;
    reg14=reg14-reg6; reg10=reg4*reg10; reg1=1+reg1; reg13=val[1]*reg13; reg5=reg5*reg1;
    reg14=val[0]*reg14; reg15=reg15-reg10; reg15=val[2]*reg15; reg6=reg5-reg6; reg13=reg14+reg13;
    reg8=reg8*reg1; reg15=reg13+reg15; reg6=val[3]*reg6; reg7=reg8-reg7; reg11=reg11*reg1;
    reg10=reg11-reg10; reg2=var_inter[0]*reg2; reg6=reg15+reg6; reg7=val[4]*reg7; reg10=val[5]*reg10;
    reg5=reg12*reg2; reg3=var_inter[1]*reg3; reg7=reg6+reg7; reg10=reg7+reg10; reg5=val[6]*reg5;
    reg6=reg12*reg3; reg9=reg0*reg9; reg6=val[7]*reg6; reg12=reg12*reg9; reg5=reg10+reg5;
    reg6=reg5+reg6; reg12=val[8]*reg12; reg2=reg1*reg2; reg2=val[9]*reg2; reg3=reg1*reg3;
    reg12=reg6+reg12; reg2=reg12+reg2; reg3=val[10]*reg3; reg9=reg1*reg9; reg9=val[11]*reg9;
    reg0=reg0*reg4; reg3=reg2+reg3; reg9=reg3+reg9; reg0=val[12]*reg0; reg1=var_inter[0]*reg4;
    reg0=reg9+reg0; reg1=val[13]*reg1; reg4=var_inter[1]*reg4; reg1=reg0+reg1; reg4=val[14]*reg4;
    res=reg1+reg4;

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
