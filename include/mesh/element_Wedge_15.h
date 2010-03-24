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
    T reg0=nodes[0]->pos[2]+nodes[3]->pos[2]; T reg1=nodes[0]->pos[1]+nodes[3]->pos[1]; reg0=reg0-nodes[6]->pos[2]; reg1=reg1-nodes[6]->pos[1]; reg0=nodes[7]->pos[2]+reg0;
    T reg2=nodes[0]->pos[0]+nodes[3]->pos[0]; reg1=nodes[7]->pos[1]+reg1; reg1=reg1-nodes[8]->pos[1]; reg2=reg2-nodes[6]->pos[0]; reg0=reg0-nodes[8]->pos[2];
    reg1=reg1-nodes[9]->pos[1]; reg0=reg0-nodes[9]->pos[2]; reg2=nodes[7]->pos[0]+reg2; reg1=nodes[10]->pos[1]+reg1; reg2=reg2-nodes[8]->pos[0];
    reg0=nodes[10]->pos[2]+reg0; reg2=reg2-nodes[9]->pos[0]; reg1=reg1-nodes[11]->pos[1]; reg0=reg0-nodes[11]->pos[2]; reg1=reg1-nodes[12]->pos[1];
    reg0=reg0-nodes[12]->pos[2]; reg2=nodes[10]->pos[0]+reg2; T reg3=nodes[13]->pos[1]+reg1; reg1=nodes[14]->pos[1]+reg1; T reg4=nodes[10]->pos[2]-nodes[7]->pos[2];
    reg2=reg2-nodes[11]->pos[0]; T reg5=nodes[13]->pos[2]+reg0; reg0=nodes[14]->pos[2]+reg0; T reg6=nodes[10]->pos[1]-nodes[7]->pos[1]; T reg7=reg4*reg3;
    T reg8=reg0*reg6; reg6=reg6*reg5; reg4=reg1*reg4; reg2=reg2-nodes[12]->pos[0]; reg5=reg1*reg5;
    reg3=reg0*reg3; reg6=reg7-reg6; reg0=nodes[13]->pos[0]+reg2; reg2=nodes[14]->pos[0]+reg2; reg8=reg4-reg8;
    reg6=reg2*reg6; reg1=nodes[10]->pos[0]-nodes[7]->pos[0]; reg8=reg0*reg8; reg5=reg3-reg5; reg6=reg8-reg6;
    reg5=reg1*reg5; T det_jac=reg6+reg5;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[14],nodes[13],nodes[12],nodes[11],nodes[10],nodes[9],nodes[8],nodes[7],nodes[6],nodes[5],nodes[4],nodes[3],nodes[2],nodes[1],nodes[0]};
        for(unsigned i=0;i<15;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*reg0; T reg3=2*var_inter[2];
    T reg4=2*var_inter[1]; T reg5=0.5*var_inter[0]; T reg6=reg1-1; T reg7=reg2-1; T reg8=0.5*reg0;
    reg3=reg3-1; T reg9=reg4-1; T reg10=reg8*reg7; T reg11=0.5*var_inter[1]; T reg12=4*reg3;
    T reg13=reg5*reg6; T reg14=2*reg13; T reg15=reg5*reg12; T reg16=reg11*reg9; T reg17=reg8*reg12;
    T reg18=2*reg10; T reg19=reg17-reg18; T reg20=reg15-reg14; reg9=0.5*reg9; reg7=0.5*reg7;
    T reg21=2*reg16; T reg22=reg11*reg12; T reg23=pow(reg3,2); reg23=1-reg23; T reg24=pos_nodes[1][2]*reg20;
    T reg25=pos_nodes[0][2]*reg19; reg7=reg0+reg7; reg9=var_inter[1]+reg9; T reg26=pos_nodes[1][1]*reg20; T reg27=pos_nodes[0][1]*reg19;
    T reg28=pos_nodes[1][0]*reg20; T reg29=pos_nodes[0][0]*reg19; T reg30=1-reg3; T reg31=reg22-reg21; T reg32=pos_nodes[2][2]*reg31;
    reg24=reg25+reg24; reg25=pos_nodes[2][0]*reg31; T reg33=reg30*reg7; T reg34=0.5*reg23; reg6=0.5*reg6;
    T reg35=reg30*reg9; reg28=reg29+reg28; reg29=pos_nodes[2][1]*reg31; reg26=reg27+reg26; reg27=reg18+reg17;
    reg3=1+reg3; T reg36=reg34-reg33; reg6=var_inter[0]+reg6; T reg37=reg3*reg7; reg35=reg35-reg34;
    T reg38=pos_nodes[3][1]*reg27; reg29=reg26+reg29; reg32=reg24+reg32; reg24=pos_nodes[3][2]*reg27; reg26=reg14+reg15;
    T reg39=pos_nodes[3][0]*reg27; reg25=reg28+reg25; reg28=reg21+reg22; T reg40=reg10*reg30; T reg41=reg30*reg6;
    reg5=reg23*reg5; T reg42=reg34-reg37; T reg43=pos_nodes[4][0]*reg26; T reg44=pos_nodes[0][0]*reg36; T reg45=pos_nodes[4][1]*reg26;
    reg38=reg29+reg38; reg39=reg25+reg39; reg25=pos_nodes[0][1]*reg36; reg29=var_inter[0]*reg2; reg9=reg3*reg9;
    T reg46=pos_nodes[2][0]*reg35; T reg47=pos_nodes[2][1]*reg35; T reg48=reg13*reg30; reg8=reg23*reg8; T reg49=pos_nodes[2][2]*reg35;
    T reg50=pos_nodes[0][2]*reg36; reg24=reg32+reg24; reg32=pos_nodes[4][2]*reg26; T reg51=reg1*var_inter[1]; T reg52=pos_nodes[5][2]*reg28;
    reg32=reg24+reg32; reg24=pos_nodes[3][0]*reg42; reg9=reg9-reg34; T reg53=2*reg29; reg11=reg23*reg11;
    T reg54=reg30*reg16; T reg55=pos_nodes[5][1]*reg28; reg45=reg38+reg45; reg49=reg50+reg49; reg48=reg48-reg5;
    reg38=pos_nodes[3][1]*reg42; reg47=reg25+reg47; T reg56=pos_nodes[5][0]*reg28; reg43=reg39+reg43; reg41=reg41-reg34;
    reg39=pos_nodes[3][2]*reg42; reg40=reg40-reg8; reg46=reg44+reg46; T reg57=reg48*pos_nodes[1][0]; reg46=reg24+reg46;
    reg54=reg54-reg11; T reg58=reg1*reg30; T reg59=pos_nodes[5][0]*reg9; reg47=reg38+reg47; reg10=reg10*reg3;
    T reg60=pos_nodes[1][1]*reg41; T reg61=pos_nodes[5][1]*reg9; reg6=reg3*reg6; T reg62=reg48*pos_nodes[1][1]; reg52=reg32+reg52;
    reg32=reg0*reg4; T reg63=pos_nodes[1][0]*reg41; T reg64=reg40*pos_nodes[0][0]; T reg65=reg40*pos_nodes[0][1]; reg56=reg43+reg56;
    reg43=pos_nodes[6][0]*reg53; T reg66=2*reg51; T reg67=pos_nodes[6][1]*reg53; reg55=reg45+reg55; reg49=reg39+reg49;
    reg45=pos_nodes[5][2]*reg9; T reg68=pos_nodes[6][2]*reg53; reg60=reg25+reg60; reg43=reg56-reg43; reg25=pos_nodes[2][0]*reg54;
    reg57=reg64+reg57; reg56=pos_nodes[7][0]*reg66; reg64=2*reg32; reg63=reg44+reg63; reg44=reg40*pos_nodes[0][2];
    reg62=reg65+reg62; reg65=pos_nodes[7][1]*reg66; reg67=reg55-reg67; reg45=reg49+reg45; reg49=reg48*pos_nodes[1][2];
    reg55=pos_nodes[2][1]*reg54; T reg69=reg2-reg1; reg6=reg6-reg34; reg13=reg13*reg3; T reg70=pos_nodes[6][2]*reg58;
    reg2=reg2-reg4; T reg71=pos_nodes[6][1]*reg58; reg47=reg61+reg47; reg8=reg10-reg8; reg10=pos_nodes[1][2]*reg41;
    reg59=reg46+reg59; reg46=pos_nodes[6][0]*reg58; reg61=pos_nodes[7][2]*reg66; reg68=reg52-reg68; reg55=reg62+reg55;
    reg10=reg50+reg10; reg61=reg68-reg61; reg50=pos_nodes[8][2]*reg64; reg52=reg8*pos_nodes[3][1]; reg62=pos_nodes[8][1]*reg64;
    reg56=reg43-reg56; reg43=pos_nodes[8][0]*reg64; reg65=reg67-reg65; reg49=reg44+reg49; reg44=pos_nodes[2][2]*reg54;
    reg67=pos_nodes[7][1]*reg58; reg71=reg47-reg71; reg70=reg45-reg70; reg25=reg57+reg25; reg45=reg8*pos_nodes[3][0];
    reg47=pos_nodes[7][2]*reg58; reg57=pos_nodes[4][1]*reg6; reg38=reg60+reg38; reg5=reg13-reg5; reg16=reg16*reg3;
    reg13=reg30*reg69; reg60=pos_nodes[7][0]*reg58; reg46=reg59-reg46; reg59=pos_nodes[4][0]*reg6; reg24=reg63+reg24;
    reg63=reg30*reg2; reg68=pos_nodes[8][2]*reg63; T reg72=reg30*reg4; reg47=reg70+reg47; reg70=pos_nodes[9][2]*reg53;
    T reg73=pos_nodes[4][2]*reg6; reg39=reg10+reg39; reg11=reg16-reg11; reg50=reg61-reg50; reg10=pos_nodes[6][1]*reg13;
    reg57=reg38+reg57; reg52=reg55+reg52; reg16=pos_nodes[8][0]*reg63; reg38=pos_nodes[8][1]*reg63; reg67=reg71+reg67;
    reg43=reg56-reg43; reg55=pos_nodes[9][0]*reg53; reg56=reg1*reg3; reg61=pos_nodes[9][1]*reg53; reg62=reg65-reg62;
    reg59=reg24+reg59; reg24=pos_nodes[6][0]*reg13; reg60=reg46+reg60; reg46=reg8*pos_nodes[3][2]; reg44=reg49+reg44;
    reg49=reg5*pos_nodes[4][1]; reg45=reg25+reg45; reg25=reg5*pos_nodes[4][0]; reg65=pos_nodes[9][2]*reg56; reg73=reg39+reg73;
    reg39=pos_nodes[6][2]*reg13; reg68=reg47+reg68; reg47=pos_nodes[9][1]*reg56; reg71=pos_nodes[7][1]*reg72; reg10=reg57+reg10;
    reg38=reg67+reg38; reg57=pos_nodes[10][1]*reg66; reg55=reg43+reg55; reg43=pos_nodes[10][0]*reg66; reg61=reg62+reg61;
    reg62=reg11*pos_nodes[5][1]; reg49=reg52+reg49; reg24=reg59+reg24; reg52=reg5*pos_nodes[4][2]; reg46=reg44+reg46;
    reg25=reg45+reg25; reg44=reg11*pos_nodes[5][0]; reg45=pos_nodes[7][0]*reg72; reg59=reg30*reg29; reg16=reg60+reg16;
    reg60=pos_nodes[9][0]*reg56; reg67=pos_nodes[10][2]*reg66; reg70=reg50+reg70; reg50=pos_nodes[11][1]*reg64; reg57=reg61+reg57;
    reg47=reg38-reg47; reg38=pos_nodes[10][1]*reg56; reg61=pos_nodes[8][0]*reg72; reg45=reg24+reg45; reg24=reg0*reg12;
    reg43=reg55+reg43; reg55=pos_nodes[11][0]*reg64; T reg74=reg59*pos_nodes[6][1]; reg62=reg49+reg62; reg49=reg11*pos_nodes[5][2];
    reg52=reg46+reg52; reg44=reg25+reg44; reg25=reg59*pos_nodes[6][0]; reg46=pos_nodes[11][2]*reg64; reg67=reg70+reg67;
    reg70=reg30*reg51; reg69=reg3*reg69; T reg75=pos_nodes[10][0]*reg56; reg60=reg16-reg60; reg71=reg10+reg71;
    reg65=reg68-reg65; reg10=pos_nodes[10][2]*reg56; reg16=pos_nodes[8][1]*reg72; reg68=pos_nodes[7][2]*reg72; reg39=reg73+reg39;
    reg2=reg3*reg2; reg73=pos_nodes[8][2]*reg72; T reg76=pos_nodes[7][1]*reg70; reg74=reg62+reg74; reg68=reg39+reg68;
    reg50=reg57+reg50; reg39=pos_nodes[12][1]*reg24; reg57=reg4*reg3; reg62=var_inter[0]*reg12; reg55=reg43+reg55;
    reg43=pos_nodes[12][0]*reg24; T reg77=reg59*pos_nodes[6][2]; reg49=reg52+reg49; reg52=pos_nodes[11][0]*reg2; reg25=reg44+reg25;
    reg44=reg70*pos_nodes[7][0]; T reg78=pos_nodes[12][2]*reg24; reg46=reg67+reg46; reg30=reg30*reg32; reg75=reg60+reg75;
    reg16=reg71-reg16; reg60=pos_nodes[9][1]*reg69; reg67=pos_nodes[11][2]*reg2; reg10=reg65+reg10; reg38=reg47+reg38;
    reg47=pos_nodes[11][1]*reg2; reg65=pos_nodes[9][0]*reg69; reg61=reg45-reg61; reg73=reg68-reg73; reg45=pos_nodes[9][2]*reg69;
    reg68=reg23*pos_nodes[12][2]; reg67=reg10+reg67; reg29=reg3*reg29; reg78=reg46-reg78; reg10=pos_nodes[13][2]*reg62;
    reg77=reg49+reg77; reg46=pos_nodes[7][2]*reg70; reg49=pos_nodes[13][1]*reg62; reg39=reg50-reg39; reg65=reg61+reg65;
    reg50=pos_nodes[10][0]*reg57; reg61=reg23*pos_nodes[12][0]; reg47=reg38+reg47; reg38=reg23*pos_nodes[12][1]; reg71=pos_nodes[10][1]*reg57;
    reg60=reg16+reg60; reg76=reg74+reg76; reg16=reg30*pos_nodes[8][1]; reg74=var_inter[1]*reg12; reg43=reg55-reg43;
    reg55=pos_nodes[13][0]*reg62; reg52=reg75+reg52; reg44=reg25+reg44; reg25=reg30*pos_nodes[8][0]; reg75=pos_nodes[14][0]*reg74;
    T reg79=reg23*pos_nodes[14][0]; reg52=reg52-reg61; reg50=reg65+reg50; reg65=pos_nodes[11][0]*reg57; T reg80=reg23*pos_nodes[14][1];
    reg47=reg47-reg38; reg67=reg67-reg68; T reg81=reg23*pos_nodes[14][2]; reg25=reg44+reg25; reg44=pos_nodes[11][1]*reg57;
    reg71=reg60+reg71; reg60=reg29*pos_nodes[9][0]; reg51=reg3*reg51; T reg82=pos_nodes[14][2]*reg74; reg10=reg78-reg10;
    reg55=reg43-reg55; reg43=reg30*pos_nodes[8][2]; reg46=reg77+reg46; reg49=reg39-reg49; reg39=pos_nodes[14][1]*reg74;
    reg77=pos_nodes[10][2]*reg57; reg45=reg73+reg45; reg16=reg76+reg16; reg73=reg29*pos_nodes[9][1]; reg43=reg46+reg43;
    reg77=reg45+reg77; reg45=pos_nodes[11][2]*reg57; reg44=reg71-reg44; reg32=reg3*reg32; reg81=reg67+reg81;
    reg39=reg49-reg39; reg73=reg16+reg73; reg3=reg51*pos_nodes[10][1]; reg80=reg47+reg80; reg16=reg51*pos_nodes[10][0];
    reg65=reg50-reg65; reg60=reg25+reg60; reg82=reg10-reg82; reg10=reg29*pos_nodes[9][2]; reg79=reg52+reg79;
    reg75=reg55-reg75; reg3=reg73+reg3; reg25=reg32*pos_nodes[11][1]; reg46=reg32*pos_nodes[11][0]; reg47=reg51*pos_nodes[10][2];
    reg16=reg60+reg16; reg0=reg23*reg0; reg49=reg75*reg81; reg45=reg77-reg45; reg38=reg44-reg38;
    reg44=reg23*pos_nodes[13][1]; reg50=reg23*pos_nodes[13][0]; reg10=reg43+reg10; reg43=reg39*reg81; reg52=reg80*reg82;
    reg61=reg65-reg61; reg55=reg79*reg82; reg43=reg52-reg43; reg60=reg75*reg80; reg49=reg55-reg49;
    reg65=reg32*pos_nodes[11][2]; reg47=reg10+reg47; reg10=reg0*pos_nodes[12][1]; reg25=reg3+reg25; reg3=reg79*reg39;
    reg46=reg16+reg46; reg16=reg0*pos_nodes[12][0]; reg67=reg23*pos_nodes[13][2]; reg50=reg61+reg50; reg44=reg38+reg44;
    reg68=reg45-reg68; reg38=reg23*var_inter[0]; reg65=reg47+reg65; reg45=reg0*pos_nodes[12][2]; reg47=reg44*reg49;
    reg60=reg3-reg60; reg16=reg46+reg16; reg46=reg38*pos_nodes[13][0]; reg61=reg38*pos_nodes[13][1]; reg71=reg23*var_inter[1];
    reg73=reg50*reg43; reg67=reg68+reg67; reg10=reg25+reg10; reg25=reg44*reg82; reg68=reg67*reg60;
    reg61=reg10+reg61; reg73=reg47-reg73; reg10=reg71*pos_nodes[14][1]; reg47=reg39*reg67; reg76=reg44*reg81;
    reg77=reg80*reg67; reg78=reg38*pos_nodes[13][2]; reg45=reg65+reg45; reg65=reg50*reg82; T reg83=reg79*reg67;
    T reg84=reg75*reg67; T reg85=reg50*reg81; T reg86=reg71*pos_nodes[14][0]; reg46=reg16+reg46; reg83=reg85-reg83;
    reg47=reg25-reg47; reg77=reg76-reg77; reg84=reg65-reg84; reg68=reg73-reg68; reg16=reg50*reg39;
    reg10=reg61+reg10; reg61=reg75*reg44; reg73=reg50*reg80; T reg87=reg71*pos_nodes[14][2]; reg78=reg45+reg78;
    reg45=reg79*reg44; reg86=reg46+reg86; reg83=reg83/reg68; reg61=reg16-reg61; reg45=reg73-reg45;
    reg86=pos[0]-reg86; reg10=pos[1]-reg10; reg87=reg78+reg87; reg43=reg43/reg68; reg47=reg47/reg68;
    reg77=reg77/reg68; reg49=reg49/reg68; reg84=reg84/reg68; reg87=pos[2]-reg87; reg60=reg60/reg68;
    reg61=reg61/reg68; reg68=reg45/reg68; reg43=reg86*reg43; reg49=reg10*reg49; reg83=reg10*reg83;
    reg47=reg86*reg47; reg84=reg10*reg84; reg77=reg86*reg77; reg77=reg83-reg77; reg68=reg87*reg68;
    reg84=reg47-reg84; reg61=reg87*reg61; reg43=reg49-reg43; reg60=reg87*reg60; var_inter[1]=reg61+reg84;
    var_inter[0]=reg43-reg60; var_inter[2]=reg77-reg68;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*var_inter[2]; T reg3=2*reg0;
    reg2=reg2-1; T reg4=0.5*reg0; T reg5=reg3-1; T reg6=2*var_inter[1]; T reg7=0.5*var_inter[0];
    T reg8=reg1-1; T reg9=4*reg2; T reg10=reg7*reg8; T reg11=reg6-1; T reg12=reg4*reg5;
    T reg13=0.5*var_inter[1]; T reg14=reg7*reg9; T reg15=2*reg10; T reg16=reg13*reg11; T reg17=reg4*reg9;
    T reg18=2*reg12; T reg19=reg17-reg18; reg5=0.5*reg5; T reg20=reg14-reg15; reg11=0.5*reg11;
    T reg21=2*reg16; T reg22=reg13*reg9; T reg23=pow(reg2,2); reg5=reg0+reg5; T reg24=reg22-reg21;
    T reg25=pos_nodes[0][0]*reg19; reg23=1-reg23; T reg26=pos_nodes[1][0]*reg20; T reg27=pos_nodes[1][1]*reg20; T reg28=pos_nodes[0][1]*reg19;
    reg11=var_inter[1]+reg11; T reg29=1-reg2; T reg30=pos_nodes[1][2]*reg20; T reg31=pos_nodes[0][2]*reg19; T reg32=0.5*reg23;
    T reg33=reg29*reg5; T reg34=pos_nodes[2][1]*reg24; reg27=reg28+reg27; reg28=pos_nodes[2][2]*reg24; reg30=reg31+reg30;
    reg31=reg29*reg11; T reg35=reg18+reg17; reg8=0.5*reg8; T reg36=pos_nodes[2][0]*reg24; reg26=reg25+reg26;
    reg2=1+reg2; reg25=reg2*reg5; reg28=reg30+reg28; reg30=pos_nodes[3][2]*reg35; T reg37=pos_nodes[3][0]*reg35;
    reg36=reg26+reg36; reg31=reg31-reg32; reg34=reg27+reg34; reg26=pos_nodes[3][1]*reg35; reg8=var_inter[0]+reg8;
    reg27=reg32-reg33; T reg38=reg15+reg14; reg11=reg2*reg11; T reg39=pos_nodes[0][0]*reg27; T reg40=pos_nodes[4][1]*reg38;
    reg26=reg34+reg26; reg34=reg32-reg25; T reg41=pos_nodes[2][2]*reg31; T reg42=pos_nodes[0][2]*reg27; T reg43=reg29*reg8;
    reg37=reg36+reg37; reg4=reg23*reg4; reg36=pos_nodes[4][0]*reg38; T reg44=reg21+reg22; T reg45=reg29*reg12;
    T reg46=reg10*reg29; reg7=reg7*reg23; T reg47=var_inter[0]*reg3; T reg48=pos_nodes[0][1]*reg27; T reg49=pos_nodes[2][1]*reg31;
    T reg50=pos_nodes[4][2]*reg38; reg30=reg28+reg30; reg28=pos_nodes[2][0]*reg31; reg36=reg37+reg36; reg40=reg26+reg40;
    reg26=pos_nodes[5][1]*reg44; reg37=pos_nodes[3][0]*reg34; T reg51=pos_nodes[5][0]*reg44; T reg52=2*reg47; reg45=reg45-reg4;
    reg46=reg46-reg7; T reg53=pos_nodes[3][1]*reg34; reg49=reg48+reg49; reg28=reg39+reg28; reg11=reg11-reg32;
    reg13=reg13*reg23; T reg54=pos_nodes[3][2]*reg34; reg41=reg42+reg41; T reg55=pos_nodes[5][2]*reg44; reg50=reg30+reg50;
    reg30=reg1*var_inter[1]; T reg56=reg16*reg29; reg43=reg43-reg32; reg41=reg54+reg41; T reg57=pos_nodes[5][2]*reg11;
    T reg58=reg1*reg29; T reg59=pos_nodes[5][1]*reg11; reg49=reg53+reg49; reg28=reg37+reg28; T reg60=pos_nodes[5][0]*reg11;
    T reg61=reg6*reg0; T reg62=reg46*pos_nodes[1][0]; T reg63=pos_nodes[1][1]*reg43; reg55=reg50+reg55; reg50=reg45*pos_nodes[0][1];
    T reg64=pos_nodes[6][0]*reg52; reg51=reg36+reg51; reg36=pos_nodes[6][1]*reg52; reg26=reg40+reg26; reg40=pos_nodes[6][2]*reg52;
    T reg65=pos_nodes[1][0]*reg43; reg8=reg2*reg8; T reg66=reg46*pos_nodes[1][1]; reg12=reg2*reg12; T reg67=reg45*pos_nodes[0][0];
    T reg68=2*reg30; reg56=reg56-reg13; T reg69=pos_nodes[7][0]*reg68; reg64=reg51-reg64; reg62=reg67+reg62;
    reg51=2*reg61; reg67=reg56*pos_nodes[2][0]; T reg70=reg46*pos_nodes[1][2]; T reg71=pos_nodes[7][2]*reg68; reg40=reg55-reg40;
    reg10=reg10*reg2; reg4=reg12-reg4; reg12=pos_nodes[1][2]*reg43; reg8=reg8-reg32; reg55=reg3-reg6;
    T reg72=pos_nodes[6][1]*reg58; T reg73=reg45*pos_nodes[0][2]; reg57=reg41+reg57; reg59=reg49+reg59; reg41=pos_nodes[6][2]*reg58;
    reg49=reg56*pos_nodes[2][1]; reg60=reg28+reg60; reg28=pos_nodes[6][0]*reg58; reg3=reg3-reg1; reg36=reg26-reg36;
    reg26=pos_nodes[7][1]*reg68; reg63=reg48+reg63; reg66=reg50+reg66; reg65=reg39+reg65; reg26=reg36-reg26;
    reg36=pos_nodes[8][1]*reg51; reg71=reg40-reg71; reg39=pos_nodes[8][2]*reg51; reg49=reg66+reg49; reg40=reg4*pos_nodes[3][1];
    reg69=reg64-reg69; reg48=pos_nodes[8][0]*reg51; reg12=reg42+reg12; reg42=pos_nodes[7][1]*reg58; reg72=reg59-reg72;
    reg41=reg57-reg41; reg50=pos_nodes[7][2]*reg58; reg57=reg56*pos_nodes[2][2]; reg70=reg73+reg70; reg59=pos_nodes[4][1]*reg8;
    reg53=reg63+reg53; reg63=reg4*pos_nodes[3][0]; reg67=reg62+reg67; reg62=pos_nodes[7][0]*reg58; reg28=reg60-reg28;
    reg60=reg29*reg55; reg64=pos_nodes[4][0]*reg8; reg37=reg65+reg37; reg65=reg29*reg3; reg16=reg16*reg2;
    reg7=reg10-reg7; reg62=reg28+reg62; reg59=reg53+reg59; reg10=pos_nodes[6][1]*reg65; reg13=reg16-reg13;
    reg39=reg71-reg39; reg16=pos_nodes[9][2]*reg52; reg28=pos_nodes[8][1]*reg60; reg53=pos_nodes[8][0]*reg60; reg66=reg1*reg2;
    reg42=reg72+reg42; reg50=reg41+reg50; reg41=pos_nodes[6][0]*reg65; reg64=reg37+reg64; reg36=reg26-reg36;
    reg26=pos_nodes[9][1]*reg52; reg37=pos_nodes[8][2]*reg60; reg40=reg49+reg40; reg49=reg7*pos_nodes[4][1]; reg71=pos_nodes[4][2]*reg8;
    reg54=reg12+reg54; reg12=reg6*reg29; reg48=reg69-reg48; reg69=reg7*pos_nodes[4][0]; reg63=reg67+reg63;
    reg67=reg4*pos_nodes[3][2]; reg57=reg70+reg57; reg70=pos_nodes[9][0]*reg52; reg72=pos_nodes[10][1]*reg68; reg26=reg36+reg26;
    reg36=reg13*pos_nodes[5][0]; reg69=reg63+reg69; reg41=reg64+reg41; reg63=pos_nodes[7][0]*reg12; reg67=reg57+reg67;
    reg57=reg7*pos_nodes[4][2]; reg42=reg28+reg42; reg28=pos_nodes[9][1]*reg66; reg50=reg37+reg50; reg37=pos_nodes[9][2]*reg66;
    reg71=reg54+reg71; reg54=pos_nodes[10][2]*reg68; reg64=pos_nodes[7][1]*reg12; reg10=reg59+reg10; reg16=reg39+reg16;
    reg39=pos_nodes[10][0]*reg68; reg70=reg48+reg70; reg62=reg53+reg62; reg48=pos_nodes[9][0]*reg66; reg49=reg40+reg49;
    reg40=reg13*pos_nodes[5][1]; reg53=reg29*reg47; reg59=pos_nodes[6][2]*reg65; reg59=reg71+reg59; reg71=reg13*pos_nodes[5][2];
    reg37=reg50-reg37; reg50=pos_nodes[10][2]*reg66; reg73=pos_nodes[7][2]*reg12; T reg74=pos_nodes[8][0]*reg12; reg63=reg41+reg63;
    reg41=reg53*pos_nodes[6][1]; reg40=reg49+reg40; reg3=reg2*reg3; reg39=reg70+reg39; reg72=reg26+reg72;
    reg26=pos_nodes[11][1]*reg51; reg49=pos_nodes[11][0]*reg51; reg70=pos_nodes[8][1]*reg12; reg64=reg10+reg64; reg10=reg29*reg30;
    reg36=reg69+reg36; reg69=reg53*pos_nodes[6][0]; reg48=reg62-reg48; reg62=pos_nodes[10][0]*reg66; reg55=reg2*reg55;
    T reg75=reg0*reg9; reg57=reg67+reg57; reg28=reg42-reg28; reg42=pos_nodes[11][2]*reg51; reg67=pos_nodes[10][1]*reg66;
    reg54=reg16+reg54; reg16=var_inter[0]*reg9; T reg76=reg6*reg2; reg42=reg54+reg42; reg69=reg36+reg69;
    reg36=reg10*pos_nodes[7][0]; reg54=pos_nodes[12][2]*reg75; reg62=reg48+reg62; reg41=reg40+reg41; reg40=pos_nodes[7][1]*reg10;
    reg48=pos_nodes[8][2]*reg12; reg73=reg59+reg73; reg59=pos_nodes[11][2]*reg55; reg50=reg37+reg50; reg37=pos_nodes[11][1]*reg55;
    reg67=reg28+reg67; reg28=pos_nodes[9][0]*reg3; reg74=reg63-reg74; reg29=reg61*reg29; reg63=pos_nodes[11][0]*reg55;
    reg71=reg57+reg71; reg57=reg53*pos_nodes[6][2]; T reg77=pos_nodes[12][0]*reg75; reg49=reg39+reg49; reg39=pos_nodes[12][1]*reg75;
    T reg78=pos_nodes[9][1]*reg3; reg70=reg64-reg70; reg26=reg72+reg26; reg64=reg10*pos_nodes[7][2]; reg59=reg50+reg59;
    reg54=reg42-reg54; reg48=reg73-reg48; reg42=pos_nodes[13][2]*reg16; reg47=reg2*reg47; reg50=reg23*pos_nodes[12][2];
    reg57=reg71+reg57; reg71=pos_nodes[9][2]*reg3; reg39=reg26-reg39; reg26=pos_nodes[13][1]*reg16; reg28=reg74+reg28;
    reg72=pos_nodes[10][0]*reg76; reg73=reg29*pos_nodes[8][1]; reg74=reg23*pos_nodes[12][0]; T reg79=var_inter[1]*reg9; reg77=reg49-reg77;
    reg49=pos_nodes[13][0]*reg16; reg37=reg67+reg37; reg67=reg23*pos_nodes[12][1]; reg40=reg41+reg40; reg41=pos_nodes[10][1]*reg76;
    reg78=reg70+reg78; reg63=reg62+reg63; reg36=reg69+reg36; reg62=reg29*pos_nodes[8][0]; reg63=reg63-reg74;
    reg30=reg2*reg30; reg72=reg28+reg72; reg28=pos_nodes[11][0]*reg76; reg69=reg29*pos_nodes[8][2]; reg70=pos_nodes[14][2]*reg79;
    T reg80=reg23*pos_nodes[14][1]; reg37=reg37-reg67; reg59=reg59-reg50; T reg81=reg23*pos_nodes[14][2]; reg42=reg54-reg42;
    reg36=reg62+reg36; reg54=reg47*pos_nodes[9][0]; reg62=reg23*pos_nodes[14][0]; T reg82=pos_nodes[14][0]*reg79; T reg83=pos_nodes[11][1]*reg76;
    reg41=reg78+reg41; reg49=reg77-reg49; reg26=reg39-reg26; reg39=pos_nodes[14][1]*reg79; reg64=reg57+reg64;
    reg40=reg73+reg40; reg57=reg47*pos_nodes[9][1]; reg71=reg48+reg71; reg48=pos_nodes[10][2]*reg76; reg83=reg41-reg83;
    reg57=reg40+reg57; reg40=reg30*pos_nodes[10][1]; reg48=reg71+reg48; reg70=reg42-reg70; reg82=reg49-reg82;
    reg41=pos_nodes[11][2]*reg76; reg54=reg36+reg54; reg62=reg63+reg62; reg81=reg59+reg81; reg36=reg30*pos_nodes[10][0];
    reg42=reg47*pos_nodes[9][2]; reg2=reg61*reg2; reg80=reg37+reg80; reg64=reg69+reg64; reg28=reg72-reg28;
    reg39=reg26-reg39; reg26=reg2*pos_nodes[11][1]; reg40=reg57+reg40; reg36=reg54+reg36; reg37=reg2*pos_nodes[11][0];
    reg42=reg64+reg42; reg67=reg83-reg67; reg49=reg23*pos_nodes[13][1]; reg54=reg30*pos_nodes[10][2]; reg57=reg23*pos_nodes[13][0];
    reg0=reg23*reg0; reg59=reg82*reg81; reg61=reg62*reg70; reg63=reg39*reg81; reg64=reg80*reg70;
    reg41=reg48-reg41; reg74=reg28-reg74; reg54=reg42+reg54; reg28=reg2*pos_nodes[11][2]; reg42=reg82*reg80;
    reg37=reg36+reg37; reg36=pos_nodes[12][0]*reg0; reg48=pos_nodes[12][1]*reg0; reg26=reg40+reg26; reg40=var_inter[0]*reg23;
    reg49=reg67+reg49; reg57=reg74+reg57; reg59=reg61-reg59; reg67=reg62*reg39; reg63=reg64-reg63;
    reg50=reg41-reg50; reg41=reg23*pos_nodes[13][2]; reg28=reg54+reg28; reg54=pos_nodes[12][2]*reg0; reg42=reg67-reg42;
    reg69=pos_nodes[13][1]*reg40; reg48=reg26+reg48; reg26=reg23*var_inter[1]; reg41=reg50+reg41; reg50=reg57*reg63;
    reg71=reg49*reg59; reg36=reg37+reg36; reg37=pos_nodes[13][0]*reg40; reg72=reg49*reg70; reg73=reg41*reg42;
    reg69=reg48+reg69; reg48=reg39*reg41; reg74=reg49*reg81; reg77=reg80*reg41; reg78=pos_nodes[13][2]*reg40;
    reg54=reg28+reg54; reg28=pos_nodes[14][1]*reg26; reg83=reg57*reg70; T reg84=reg62*reg41; reg37=reg36+reg37;
    reg36=pos_nodes[14][0]*reg26; T reg85=reg82*reg41; reg50=reg71-reg50; reg71=reg57*reg81; reg84=reg71-reg84;
    reg77=reg74-reg77; reg48=reg72-reg48; reg85=reg83-reg85; reg73=reg50-reg73; reg50=reg57*reg39;
    T reg86=reg82*reg49; T reg87=reg57*reg80; T reg88=pos_nodes[14][2]*reg26; reg78=reg54+reg78; reg28=reg69+reg28;
    reg54=reg62*reg49; reg36=reg37+reg36; reg84=reg84/reg73; reg86=reg50-reg86; reg54=reg87-reg54;
    reg36=pos[0]-reg36; reg28=pos[1]-reg28; reg88=reg78+reg88; reg63=reg63/reg73; reg48=reg48/reg73;
    reg77=reg77/reg73; reg59=reg59/reg73; reg85=reg85/reg73; reg88=pos[2]-reg88; reg42=reg42/reg73;
    reg86=reg86/reg73; reg73=reg54/reg73; reg63=reg36*reg63; reg59=reg28*reg59; reg84=reg28*reg84;
    reg48=reg36*reg48; reg85=reg28*reg85; reg77=reg36*reg77; reg77=reg84-reg77; reg73=reg88*reg73;
    reg85=reg48-reg85; reg86=reg88*reg86; reg63=reg59-reg63; reg42=reg88*reg42; var_inter[1]+=reg86+reg85;
    var_inter[0]+=reg63-reg42; var_inter[2]+=reg77-reg73;

}
template<> struct ElemVarInterFromPosNonLinear<Wedge_15> { static const bool res = 3; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*var_inter[0]; reg1=reg1-1;
    T reg3=2*reg0; T reg4=pow(reg1,2); T reg5=reg3-1; T reg6=2*var_inter[1]; T reg7=0.5*reg0;
    T reg8=0.5*var_inter[0]; T reg9=reg2-1; reg5=reg5*reg7; T reg10=1-reg1; reg9=reg8*reg9;
    T reg11=0.5*var_inter[1]; reg4=1-reg4; T reg12=reg6-1; reg7=reg4*reg7; reg8=reg4*reg8;
    T reg13=reg10*reg9; T reg14=reg5*reg10; reg12=reg11*reg12; reg1=1+reg1; reg14=reg14-reg7;
    reg13=reg13-reg8; T reg15=reg10*reg12; reg11=reg4*reg11; reg13=val[1]*reg13; reg15=reg15-reg11;
    reg5=reg5*reg1; reg14=val[0]*reg14; reg9=reg9*reg1; reg15=val[2]*reg15; reg7=reg5-reg7;
    reg13=reg14+reg13; reg15=reg13+reg15; reg7=val[3]*reg7; reg8=reg9-reg8; reg12=reg12*reg1;
    reg7=reg15+reg7; reg8=val[4]*reg8; reg11=reg12-reg11; reg3=var_inter[0]*reg3; reg5=reg10*reg3;
    reg9=var_inter[1]*reg2; reg8=reg7+reg8; reg11=val[5]*reg11; reg5=val[6]*reg5; reg7=reg10*reg9;
    reg12=reg0*reg6; reg11=reg8+reg11; reg5=reg11+reg5; reg7=val[7]*reg7; reg10=reg10*reg12;
    reg10=val[8]*reg10; reg3=reg1*reg3; reg7=reg5+reg7; reg10=reg7+reg10; reg3=val[9]*reg3;
    reg9=reg1*reg9; reg3=reg10+reg3; reg9=val[10]*reg9; reg12=reg1*reg12; reg9=reg3+reg9;
    reg12=val[11]*reg12; reg0=reg4*reg0; reg12=reg9+reg12; reg0=val[12]*reg0; reg1=reg4*var_inter[0];
    reg4=reg4*var_inter[1]; reg1=val[13]*reg1; reg0=reg12+reg0; reg1=reg0+reg1; reg4=val[14]*reg4;
    res=reg1+reg4;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=var_inter[2]-0.14644660940672626914; T reg1=2*var_inter[0]; T reg2=2*var_inter[1]; reg0=reg0/0.70710678118654746172; T reg3=1-var_inter[2];
    T reg4=reg1+reg2; T reg5=1-reg1; reg0=1-reg0; reg4=reg4-1; reg3=reg3-0.14644660940672626914;
    reg3=reg3/0.70710678118654746172; T reg6=reg4*reg0; T reg7=1-reg2; T reg8=reg0*reg5; reg0=reg0*reg7;
    reg3=1-reg3; reg8=val[1]*reg8; reg6=val[0]*reg6; reg8=reg6+reg8; reg0=val[2]*reg0;
    reg6=reg4*reg3; reg6=val[3]*reg6; T reg9=reg5*reg3; reg0=reg8+reg0; reg9=val[4]*reg9;
    reg3=reg7*reg3; reg6=reg0+reg6; reg9=reg6+reg9; reg3=val[5]*reg3; res=reg9+reg3;

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; T reg2=reg0+reg1; T reg3=1-reg0; reg2=reg2-1;
    T reg4=1-reg1; T reg5=val[0]*reg2; T reg6=val[1]*reg3; reg6=reg5+reg6; reg5=val[2]*reg4;
    res=reg6+reg5;

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
template<class TVI,class TVAL> void get_shape_functions(const Wedge_15 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*var_inter[1]; T reg3=2*reg0;
    T reg4=2*var_inter[0]; reg1=reg1-1; T reg5=reg4-1; T reg6=0.5*var_inter[1]; T reg7=reg2-1;
    T reg8=0.5*var_inter[0]; T reg9=0.5*reg0; T reg10=reg3-1; T reg11=pow(reg1,2); T reg12=1-reg1;
    reg10=reg10*reg9; reg5=reg8*reg5; reg1=1+reg1; reg11=1-reg11; reg7=reg6*reg7;
    T reg13=reg0*reg2; T reg14=var_inter[1]*reg4; reg3=var_inter[0]*reg3; T reg15=reg7*reg1; T reg16=reg5*reg1;
    T reg17=reg10*reg1; reg6=reg11*reg6; reg7=reg12*reg7; reg9=reg11*reg9; reg8=reg11*reg8;
    reg5=reg12*reg5; reg10=reg10*reg12; T reg18=reg1*reg13; res[11]=reg18; reg0=reg11*reg0;
    res[12]=reg0; T reg19=reg1*reg14; res[10]=reg19; T reg20=reg11*var_inter[0]; res[13]=reg20;
    reg1=reg1*reg3; res[9]=reg1; reg13=reg12*reg13; res[8]=reg13; reg11=reg11*var_inter[1];
    res[14]=reg11; reg14=reg12*reg14; res[7]=reg14; reg15=reg15-reg6; res[5]=reg15;
    reg16=reg16-reg8; res[4]=reg16; reg17=reg17-reg9; res[3]=reg17; reg6=reg7-reg6;
    res[2]=reg6; reg3=reg12*reg3; res[6]=reg3; reg8=reg5-reg8; res[1]=reg8;
    reg9=reg10-reg9; res[0]=reg9;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Wedge_15> {
    static const unsigned nb_permutations = 5;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
        if ( nb_perm == 0 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[5],e.nodes[4],e.nodes[0],e.nodes[2],e.nodes[1],e.nodes[11],e.nodes[10],e.nodes[9],e.nodes[8],e.nodes[7],e.nodes[6],e.nodes[12],e.nodes[14],e.nodes[13]};
            for(unsigned i=0;i<15;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 1 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[2],e.nodes[0],e.nodes[4],e.nodes[5],e.nodes[3],e.nodes[7],e.nodes[8],e.nodes[6],e.nodes[10],e.nodes[11],e.nodes[9],e.nodes[13],e.nodes[14],e.nodes[12]};
            for(unsigned i=0;i<15;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 2 ) {
            typename TE::TNode *tmp[] = {e.nodes[5],e.nodes[4],e.nodes[3],e.nodes[2],e.nodes[1],e.nodes[0],e.nodes[10],e.nodes[9],e.nodes[11],e.nodes[7],e.nodes[6],e.nodes[8],e.nodes[14],e.nodes[13],e.nodes[12]};
            for(unsigned i=0;i<15;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 3 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[0],e.nodes[1],e.nodes[5],e.nodes[3],e.nodes[4],e.nodes[8],e.nodes[6],e.nodes[7],e.nodes[11],e.nodes[9],e.nodes[10],e.nodes[14],e.nodes[12],e.nodes[13]};
            for(unsigned i=0;i<15;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 4 ) {
            typename TE::TNode *tmp[] = {e.nodes[4],e.nodes[3],e.nodes[5],e.nodes[1],e.nodes[0],e.nodes[2],e.nodes[9],e.nodes[11],e.nodes[10],e.nodes[6],e.nodes[8],e.nodes[7],e.nodes[13],e.nodes[12],e.nodes[14]};
            for(unsigned i=0;i<15;++i) e.nodes[i] = tmp[i];
            return;
        }
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
        if ( nb_perm == 0 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[5],e.nodes[4],e.nodes[0],e.nodes[2],e.nodes[1],e.nodes[11],e.nodes[10],e.nodes[9],e.nodes[8],e.nodes[7],e.nodes[6],e.nodes[12],e.nodes[14],e.nodes[13]};
            for(unsigned i=0;i<15;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 1 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[0],e.nodes[1],e.nodes[5],e.nodes[3],e.nodes[4],e.nodes[8],e.nodes[6],e.nodes[7],e.nodes[11],e.nodes[9],e.nodes[10],e.nodes[14],e.nodes[12],e.nodes[13]};
            for(unsigned i=0;i<15;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 2 ) {
            typename TE::TNode *tmp[] = {e.nodes[5],e.nodes[4],e.nodes[3],e.nodes[2],e.nodes[1],e.nodes[0],e.nodes[10],e.nodes[9],e.nodes[11],e.nodes[7],e.nodes[6],e.nodes[8],e.nodes[14],e.nodes[13],e.nodes[12]};
            for(unsigned i=0;i<15;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 3 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[2],e.nodes[0],e.nodes[4],e.nodes[5],e.nodes[3],e.nodes[7],e.nodes[8],e.nodes[6],e.nodes[10],e.nodes[11],e.nodes[9],e.nodes[13],e.nodes[14],e.nodes[12]};
            for(unsigned i=0;i<15;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 4 ) {
            typename TE::TNode *tmp[] = {e.nodes[4],e.nodes[3],e.nodes[5],e.nodes[1],e.nodes[0],e.nodes[2],e.nodes[9],e.nodes[11],e.nodes[10],e.nodes[6],e.nodes[8],e.nodes[7],e.nodes[13],e.nodes[12],e.nodes[14]};
            for(unsigned i=0;i<15;++i) e.nodes[i] = tmp[i];
            return;
        }
    }
};

}
#endif // LMT_WEDGE_15
