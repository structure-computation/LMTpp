#ifndef LMT_WEDGE_15
#define LMT_WEDGE_15
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Wedge_15 &elem) { /// order -> degre du polynome a integrer exactement
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
template<class TNode> void permutation_if_jac_neg(const Wedge_15 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=nodes[3]->pos[2]+nodes[0]->pos[2]; T reg1=nodes[3]->pos[1]+nodes[0]->pos[1]; reg0=reg0-nodes[6]->pos[2]; reg1=reg1-nodes[6]->pos[1]; reg0=nodes[7]->pos[2]+reg0;
    reg1=nodes[7]->pos[1]+reg1; T reg2=nodes[3]->pos[0]+nodes[0]->pos[0]; reg0=reg0-nodes[8]->pos[2]; reg1=reg1-nodes[8]->pos[1]; reg2=reg2-nodes[6]->pos[0];
    reg0=reg0-nodes[9]->pos[2]; reg1=reg1-nodes[9]->pos[1]; reg2=nodes[7]->pos[0]+reg2; reg0=nodes[10]->pos[2]+reg0; reg1=nodes[10]->pos[1]+reg1;
    reg2=reg2-nodes[8]->pos[0]; reg1=reg1-nodes[11]->pos[1]; reg0=reg0-nodes[11]->pos[2]; reg2=reg2-nodes[9]->pos[0]; reg0=reg0-nodes[12]->pos[2];
    reg2=nodes[10]->pos[0]+reg2; reg1=reg1-nodes[12]->pos[1]; T reg3=nodes[10]->pos[2]-nodes[7]->pos[2]; T reg4=nodes[14]->pos[1]+reg1; T reg5=nodes[14]->pos[2]+reg0;
    T reg6=nodes[10]->pos[1]-nodes[7]->pos[1]; reg2=reg2-nodes[11]->pos[0]; reg0=nodes[13]->pos[2]+reg0; reg1=nodes[13]->pos[1]+reg1; reg2=reg2-nodes[12]->pos[0];
    T reg7=reg6*reg0; T reg8=reg4*reg3; reg6=reg5*reg6; reg3=reg3*reg1; reg7=reg3-reg7;
    reg1=reg5*reg1; reg0=reg4*reg0; reg3=nodes[13]->pos[0]+reg2; reg6=reg8-reg6; reg2=nodes[14]->pos[0]+reg2;
    reg7=reg2*reg7; reg2=nodes[10]->pos[0]-nodes[7]->pos[0]; reg0=reg1-reg0; reg6=reg3*reg6; reg7=reg6-reg7;
    reg0=reg2*reg0; T det_jac=reg7+reg0;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[14],nodes[13],nodes[12],nodes[11],nodes[10],nodes[9],nodes[8],nodes[7],nodes[6],nodes[5],nodes[4],nodes[3],nodes[2],nodes[1],nodes[0]};
        for(unsigned i=0;i<15;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*var_inter[0]; T reg3=2*reg0;
    T reg4=2*var_inter[1]; T reg5=reg2-1; T reg6=0.5*var_inter[0]; reg1=reg1-1; T reg7=0.5*reg0;
    T reg8=reg3-1; T reg9=reg4-1; T reg10=0.5*var_inter[1]; T reg11=reg5*reg6; T reg12=reg8*reg7;
    T reg13=4*reg1; T reg14=reg13*reg7; T reg15=2*reg12; T reg16=reg13*reg6; T reg17=2*reg11;
    T reg18=reg10*reg9; reg9=0.5*reg9; T reg19=2*reg18; T reg20=reg13*reg10; T reg21=reg16-reg17;
    T reg22=reg14-reg15; T reg23=pow(reg1,2); reg8=0.5*reg8; T reg24=pos_nodes[1][1]*reg21; T reg25=pos_nodes[0][1]*reg22;
    T reg26=1-reg1; T reg27=reg20-reg19; reg8=reg0+reg8; T reg28=pos_nodes[0][0]*reg22; T reg29=pos_nodes[1][0]*reg21;
    reg9=var_inter[1]+reg9; T reg30=pos_nodes[1][2]*reg21; T reg31=pos_nodes[0][2]*reg22; reg23=1-reg23; T reg32=0.5*reg23;
    T reg33=pos_nodes[2][0]*reg27; T reg34=reg26*reg8; T reg35=pos_nodes[2][1]*reg27; reg1=1+reg1; reg25=reg24+reg25;
    reg5=0.5*reg5; reg28=reg29+reg28; reg24=reg26*reg9; reg29=reg15+reg14; T reg36=pos_nodes[2][2]*reg27;
    reg31=reg30+reg31; reg28=reg33+reg28; reg30=pos_nodes[3][0]*reg29; reg33=reg17+reg16; reg25=reg35+reg25;
    reg35=pos_nodes[3][1]*reg29; reg5=reg5+var_inter[0]; reg24=reg24-reg32; reg31=reg36+reg31; reg36=pos_nodes[3][2]*reg29;
    T reg37=reg1*reg8; T reg38=reg32-reg34; T reg39=pos_nodes[2][0]*reg24; reg9=reg1*reg9; T reg40=pos_nodes[0][0]*reg38;
    T reg41=reg32-reg37; T reg42=reg3*var_inter[0]; T reg43=reg26*reg5; T reg44=reg19+reg20; T reg45=pos_nodes[2][2]*reg24;
    reg36=reg31+reg36; reg31=pos_nodes[4][2]*reg33; T reg46=pos_nodes[0][2]*reg38; T reg47=pos_nodes[4][1]*reg33; reg35=reg25+reg35;
    reg25=reg26*reg11; T reg48=pos_nodes[2][1]*reg24; T reg49=pos_nodes[0][1]*reg38; reg6=reg23*reg6; reg7=reg23*reg7;
    T reg50=reg12*reg26; T reg51=pos_nodes[4][0]*reg33; reg30=reg28+reg30; reg43=reg43-reg32; reg25=reg25-reg6;
    reg28=pos_nodes[5][2]*reg44; reg31=reg36+reg31; reg50=reg50-reg7; reg45=reg46+reg45; reg36=pos_nodes[3][2]*reg41;
    reg9=reg9-reg32; T reg52=pos_nodes[3][0]*reg41; T reg53=pos_nodes[5][1]*reg44; reg47=reg35+reg47; reg48=reg49+reg48;
    reg35=pos_nodes[3][1]*reg41; T reg54=pos_nodes[5][0]*reg44; reg51=reg30+reg51; reg39=reg40+reg39; reg30=2*reg42;
    T reg55=reg26*reg18; reg10=reg23*reg10; T reg56=var_inter[1]*reg2; T reg57=pos_nodes[6][2]*reg30; reg28=reg31+reg28;
    reg31=pos_nodes[5][2]*reg9; reg45=reg36+reg45; T reg58=pos_nodes[0][1]*reg50; T reg59=pos_nodes[1][1]*reg25; reg39=reg52+reg39;
    T reg60=pos_nodes[5][0]*reg9; T reg61=pos_nodes[6][1]*reg30; reg53=reg47+reg53; reg47=pos_nodes[1][0]*reg43; T reg62=pos_nodes[1][0]*reg25;
    T reg63=pos_nodes[0][0]*reg50; reg55=reg55-reg10; reg12=reg12*reg1; T reg64=pos_nodes[5][1]*reg9; T reg65=2*reg56;
    reg48=reg35+reg48; T reg66=pos_nodes[1][1]*reg43; reg54=reg51+reg54; reg51=pos_nodes[6][0]*reg30; T reg67=reg0*reg4;
    T reg68=reg26*reg2; reg5=reg5*reg1; T reg69=2*reg67; reg58=reg59+reg58; reg40=reg47+reg40;
    reg47=pos_nodes[2][1]*reg55; reg60=reg39+reg60; reg39=pos_nodes[6][0]*reg68; reg59=pos_nodes[7][1]*reg65; reg61=reg53-reg61;
    reg53=reg3-reg2; reg5=reg5-reg32; reg7=reg12-reg7; reg11=reg1*reg11; reg12=pos_nodes[6][1]*reg68;
    reg64=reg48+reg64; reg48=pos_nodes[2][0]*reg55; reg49=reg66+reg49; reg51=reg54-reg51; reg54=pos_nodes[7][0]*reg65;
    reg63=reg62+reg63; reg62=pos_nodes[6][2]*reg68; reg66=pos_nodes[1][2]*reg43; T reg70=pos_nodes[7][2]*reg65; reg31=reg45+reg31;
    reg45=pos_nodes[1][2]*reg25; reg57=reg28-reg57; reg28=pos_nodes[0][2]*reg50; reg3=reg3-reg4; T reg71=pos_nodes[7][1]*reg68;
    reg12=reg64-reg12; reg64=pos_nodes[7][2]*reg68; reg6=reg11-reg6; reg18=reg18*reg1; reg11=pos_nodes[4][1]*reg5;
    reg35=reg49+reg35; reg49=pos_nodes[2][2]*reg55; T reg72=reg26*reg3; T reg73=pos_nodes[3][0]*reg7; reg63=reg48+reg63;
    reg70=reg57-reg70; reg48=pos_nodes[8][2]*reg69; reg54=reg51-reg54; reg51=pos_nodes[8][0]*reg69; reg57=pos_nodes[4][0]*reg5;
    reg52=reg40+reg52; reg58=reg47+reg58; reg62=reg31-reg62; reg31=pos_nodes[3][1]*reg7; reg46=reg66+reg46;
    reg59=reg61-reg59; reg40=reg26*reg53; reg28=reg45+reg28; reg45=pos_nodes[7][0]*reg68; reg47=pos_nodes[8][1]*reg69;
    reg39=reg60-reg39; reg73=reg63+reg73; reg28=reg49+reg28; reg47=reg59-reg47; reg49=pos_nodes[9][1]*reg30;
    reg48=reg70-reg48; reg59=pos_nodes[4][1]*reg6; reg31=reg58+reg31; reg58=pos_nodes[9][2]*reg30; reg60=pos_nodes[4][0]*reg6;
    reg61=pos_nodes[3][2]*reg7; reg10=reg18-reg10; reg36=reg46+reg36; reg18=pos_nodes[8][2]*reg72; reg11=reg35+reg11;
    reg35=pos_nodes[6][1]*reg40; reg46=pos_nodes[4][2]*reg5; reg64=reg62+reg64; reg62=pos_nodes[8][1]*reg72; reg71=reg12+reg71;
    reg12=reg1*reg2; reg63=pos_nodes[6][0]*reg40; reg66=reg26*reg4; reg70=pos_nodes[8][0]*reg72; reg57=reg52+reg57;
    reg52=pos_nodes[9][0]*reg30; reg51=reg54-reg51; reg45=reg39+reg45; reg39=pos_nodes[9][0]*reg12; reg70=reg45+reg70;
    reg49=reg47+reg49; reg45=pos_nodes[9][2]*reg12; reg18=reg64+reg18; reg47=pos_nodes[10][1]*reg65; reg54=pos_nodes[7][1]*reg66;
    reg64=pos_nodes[6][2]*reg40; reg46=reg36+reg46; reg35=reg11+reg35; reg11=pos_nodes[5][1]*reg10; reg59=reg31+reg59;
    reg31=pos_nodes[10][0]*reg65; reg36=reg26*reg42; reg62=reg71+reg62; reg71=pos_nodes[9][1]*reg12; T reg74=pos_nodes[4][2]*reg6;
    reg61=reg28+reg61; reg52=reg51+reg52; reg28=pos_nodes[10][2]*reg65; reg58=reg48+reg58; reg60=reg73+reg60;
    reg48=pos_nodes[5][0]*reg10; reg63=reg57+reg63; reg51=pos_nodes[7][0]*reg66; reg57=pos_nodes[10][1]*reg12; reg71=reg62-reg71;
    reg39=reg70-reg39; reg47=reg49+reg47; reg49=pos_nodes[11][1]*reg69; reg62=reg0*reg13; reg70=pos_nodes[10][0]*reg12;
    reg73=reg26*reg56; T reg75=pos_nodes[5][2]*reg10; reg74=reg61+reg74; reg53=reg1*reg53; reg28=reg58+reg28;
    reg51=reg63+reg51; reg58=pos_nodes[8][0]*reg66; reg61=pos_nodes[11][2]*reg69; reg63=pos_nodes[10][2]*reg12; reg45=reg18-reg45;
    reg18=pos_nodes[7][2]*reg66; reg64=reg46+reg64; reg3=reg1*reg3; reg46=pos_nodes[6][1]*reg36; reg11=reg59+reg11;
    reg31=reg52+reg31; reg52=pos_nodes[6][0]*reg36; reg59=pos_nodes[11][0]*reg69; reg54=reg35+reg54; reg35=pos_nodes[8][1]*reg66;
    reg48=reg60+reg48; reg60=pos_nodes[9][0]*reg53; reg63=reg45+reg63; reg70=reg39+reg70; reg39=reg1*reg4;
    reg45=pos_nodes[11][2]*reg3; T reg76=pos_nodes[9][1]*reg53; reg35=reg54-reg35; reg54=pos_nodes[8][2]*reg66; reg18=reg64+reg18;
    reg47=reg49+reg47; reg49=pos_nodes[12][1]*reg62; reg64=pos_nodes[7][1]*reg73; reg46=reg11+reg46; reg11=pos_nodes[11][0]*reg3;
    reg26=reg26*reg67; reg31=reg59+reg31; reg59=pos_nodes[6][2]*reg36; reg75=reg74+reg75; reg74=pos_nodes[12][0]*reg62;
    T reg77=var_inter[0]*reg13; T reg78=pos_nodes[11][1]*reg3; T reg79=pos_nodes[12][2]*reg62; reg58=reg51-reg58; reg28=reg61+reg28;
    reg57=reg71+reg57; reg51=pos_nodes[7][0]*reg73; reg52=reg48+reg52; reg42=reg1*reg42; reg48=pos_nodes[8][0]*reg26;
    reg64=reg46+reg64; reg46=pos_nodes[8][1]*reg26; reg61=pos_nodes[7][2]*reg73; reg59=reg75+reg59; reg51=reg52+reg51;
    reg63=reg45+reg63; reg54=reg18-reg54; reg18=pos_nodes[9][2]*reg53; reg74=reg31-reg74; reg31=pos_nodes[13][0]*reg77;
    reg45=pos_nodes[12][2]*reg23; reg52=pos_nodes[13][2]*reg77; reg71=pos_nodes[12][0]*reg23; reg79=reg28-reg79; reg28=pos_nodes[10][0]*reg39;
    reg60=reg58+reg60; reg58=var_inter[1]*reg13; reg57=reg78+reg57; reg76=reg35+reg76; reg35=pos_nodes[10][1]*reg39;
    reg75=pos_nodes[12][1]*reg23; reg78=pos_nodes[13][1]*reg77; reg70=reg11+reg70; reg49=reg47-reg49; reg11=pos_nodes[14][1]*reg23;
    reg48=reg51+reg48; reg47=pos_nodes[9][0]*reg42; reg51=pos_nodes[14][2]*reg23; reg63=reg63-reg45; T reg80=pos_nodes[14][0]*reg23;
    reg70=reg70-reg71; T reg81=pos_nodes[11][1]*reg39; reg28=reg60+reg28; reg60=pos_nodes[11][0]*reg39; reg35=reg76+reg35;
    reg18=reg54+reg18; reg54=pos_nodes[10][2]*reg39; reg56=reg1*reg56; reg76=pos_nodes[8][2]*reg26; reg61=reg59+reg61;
    reg31=reg74-reg31; reg59=pos_nodes[14][0]*reg58; reg74=pos_nodes[14][2]*reg58; reg52=reg79-reg52; reg79=pos_nodes[14][1]*reg58;
    reg78=reg49-reg78; reg46=reg64+reg46; reg49=pos_nodes[9][1]*reg42; reg57=reg57-reg75; reg51=reg63+reg51;
    reg80=reg70+reg80; reg81=reg35-reg81; reg11=reg57+reg11; reg74=reg52-reg74; reg59=reg31-reg59;
    reg31=pos_nodes[10][0]*reg56; reg47=reg48+reg47; reg60=reg28-reg60; reg76=reg61+reg76; reg28=pos_nodes[9][2]*reg42;
    reg67=reg1*reg67; reg1=pos_nodes[11][2]*reg39; reg35=pos_nodes[10][1]*reg56; reg49=reg46+reg49; reg79=reg78-reg79;
    reg54=reg18+reg54; reg0=reg23*reg0; reg18=reg79*reg51; reg46=reg11*reg74; reg31=reg47+reg31;
    reg47=pos_nodes[13][1]*reg23; reg48=pos_nodes[11][0]*reg67; reg52=reg80*reg74; reg57=reg59*reg51; reg75=reg81-reg75;
    reg1=reg54-reg1; reg71=reg60-reg71; reg54=pos_nodes[13][0]*reg23; reg60=pos_nodes[10][2]*reg56; reg28=reg76+reg28;
    reg61=pos_nodes[11][1]*reg67; reg35=reg49+reg35; reg49=pos_nodes[12][1]*reg0; reg35=reg61+reg35; reg47=reg75+reg47;
    reg31=reg48+reg31; reg48=reg59*reg11; reg18=reg46-reg18; reg61=reg80*reg79; reg54=reg71+reg54;
    reg63=pos_nodes[12][0]*reg0; reg64=reg23*var_inter[0]; reg60=reg28+reg60; reg57=reg52-reg57; reg28=pos_nodes[11][2]*reg67;
    reg70=pos_nodes[13][2]*reg23; reg45=reg1-reg45; reg1=reg23*var_inter[1]; reg71=pos_nodes[12][2]*reg0; reg60=reg28+reg60;
    reg70=reg45+reg70; reg28=reg47*reg57; reg48=reg61-reg48; reg45=pos_nodes[13][0]*reg64; reg63=reg31+reg63;
    reg31=reg54*reg18; reg49=reg35+reg49; reg35=pos_nodes[13][1]*reg64; reg75=reg80*reg70; reg76=reg47*reg51;
    reg78=reg54*reg51; reg81=reg54*reg74; T reg82=reg47*reg74; T reg83=reg79*reg70; T reg84=reg59*reg70;
    reg31=reg28-reg31; reg28=pos_nodes[14][0]*reg1; reg35=reg49+reg35; reg45=reg63+reg45; reg49=reg11*reg70;
    reg71=reg60+reg71; reg60=pos_nodes[13][2]*reg64; reg63=pos_nodes[14][1]*reg1; T reg85=reg48*reg70; T reg86=reg80*reg47;
    reg84=reg81-reg84; T reg87=pos_nodes[14][2]*reg1; reg60=reg71+reg60; reg28=reg45+reg28; reg83=reg82-reg83;
    reg45=reg54*reg11; reg71=reg59*reg47; T reg88=reg54*reg79; reg63=reg35+reg63; reg85=reg31-reg85;
    reg75=reg78-reg75; reg49=reg76-reg49; reg28=pos[0]-reg28; reg63=pos[1]-reg63; reg87=reg60+reg87;
    reg49=reg49/reg85; reg83=reg83/reg85; reg18=reg18/reg85; reg86=reg45-reg86; reg57=reg57/reg85;
    reg84=reg84/reg85; reg75=reg75/reg85; reg71=reg88-reg71; reg49=reg49*reg28; reg75=reg75*reg63;
    reg71=reg71/reg85; reg57=reg57*reg63; reg87=pos[2]-reg87; reg83=reg83*reg28; reg86=reg86/reg85;
    reg84=reg84*reg63; reg18=reg18*reg28; reg85=reg48/reg85; reg85=reg85*reg87; reg84=reg83-reg84;
    reg18=reg57-reg18; reg86=reg86*reg87; reg49=reg75-reg49; reg71=reg71*reg87; var_inter[1]=reg71+reg84;
    var_inter[2]=reg49-reg86; var_inter[0]=reg18-reg85;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*var_inter[2]; T reg3=2*reg0;
    T reg4=0.5*var_inter[0]; T reg5=0.5*reg0; T reg6=reg1-1; T reg7=reg3-1; reg2=reg2-1;
    T reg8=2*var_inter[1]; T reg9=4*reg2; T reg10=reg7*reg5; T reg11=reg6*reg4; T reg12=0.5*var_inter[1];
    T reg13=reg8-1; T reg14=reg12*reg13; T reg15=2*reg10; T reg16=reg5*reg9; T reg17=2*reg11;
    T reg18=reg4*reg9; T reg19=pow(reg2,2); reg7=0.5*reg7; reg13=0.5*reg13; T reg20=reg18-reg17;
    T reg21=reg16-reg15; T reg22=2*reg14; T reg23=reg12*reg9; T reg24=pos_nodes[0][1]*reg21; reg7=reg0+reg7;
    T reg25=pos_nodes[1][1]*reg20; T reg26=reg23-reg22; T reg27=1-reg2; T reg28=pos_nodes[1][2]*reg20; T reg29=pos_nodes[0][2]*reg21;
    T reg30=pos_nodes[1][0]*reg20; reg19=1-reg19; reg13=var_inter[1]+reg13; T reg31=pos_nodes[0][0]*reg21; reg24=reg25+reg24;
    reg25=pos_nodes[2][0]*reg26; T reg32=reg27*reg7; reg6=0.5*reg6; T reg33=0.5*reg19; reg31=reg30+reg31;
    reg30=pos_nodes[2][1]*reg26; T reg34=reg27*reg13; reg29=reg28+reg29; reg28=reg15+reg16; reg2=1+reg2;
    T reg35=pos_nodes[2][2]*reg26; T reg36=pos_nodes[3][1]*reg28; T reg37=pos_nodes[3][0]*reg28; reg25=reg31+reg25; reg34=reg34-reg33;
    reg30=reg24+reg30; reg24=reg17+reg18; reg31=reg2*reg7; T reg38=pos_nodes[3][2]*reg28; reg6=var_inter[0]+reg6;
    T reg39=reg33-reg32; reg35=reg29+reg35; reg29=reg33-reg31; T reg40=pos_nodes[4][0]*reg24; T reg41=pos_nodes[4][2]*reg24;
    T reg42=reg27*reg6; reg30=reg36+reg30; reg36=pos_nodes[4][1]*reg24; T reg43=reg27*reg11; reg4=reg19*reg4;
    reg25=reg37+reg25; reg37=pos_nodes[2][0]*reg34; T reg44=pos_nodes[2][1]*reg34; reg35=reg38+reg35; reg38=pos_nodes[0][1]*reg39;
    T reg45=reg27*reg10; reg5=reg19*reg5; T reg46=var_inter[0]*reg3; T reg47=pos_nodes[2][2]*reg34; T reg48=pos_nodes[0][2]*reg39;
    T reg49=reg22+reg23; T reg50=pos_nodes[0][0]*reg39; reg13=reg2*reg13; reg44=reg38+reg44; reg40=reg25+reg40;
    reg25=pos_nodes[5][0]*reg49; T reg51=pos_nodes[3][1]*reg29; T reg52=pos_nodes[3][0]*reg29; reg13=reg13-reg33; T reg53=pos_nodes[5][2]*reg49;
    reg43=reg43-reg4; reg41=reg35+reg41; reg35=reg27*reg14; reg12=reg19*reg12; T reg54=var_inter[1]*reg1;
    reg45=reg45-reg5; reg47=reg48+reg47; T reg55=pos_nodes[3][2]*reg29; T reg56=2*reg46; reg37=reg50+reg37;
    T reg57=pos_nodes[5][1]*reg49; reg36=reg30+reg36; reg42=reg42-reg33; reg25=reg40+reg25; reg30=pos_nodes[6][0]*reg56;
    reg40=reg27*reg1; T reg58=2*reg54; T reg59=pos_nodes[5][0]*reg13; reg37=reg52+reg37; reg47=reg55+reg47;
    T reg60=pos_nodes[5][2]*reg13; T reg61=pos_nodes[0][1]*reg45; T reg62=reg43*pos_nodes[1][1]; T reg63=pos_nodes[6][1]*reg56; reg57=reg36+reg57;
    reg6=reg2*reg6; reg36=pos_nodes[6][2]*reg56; T reg64=reg8*reg0; T reg65=pos_nodes[1][0]*reg42; T reg66=pos_nodes[5][1]*reg13;
    reg44=reg51+reg44; reg53=reg41+reg53; reg41=pos_nodes[1][1]*reg42; reg35=reg35-reg12; T reg67=pos_nodes[0][0]*reg45;
    T reg68=reg43*pos_nodes[1][0]; reg10=reg10*reg2; T reg69=pos_nodes[0][2]*reg45; reg36=reg53-reg36; reg53=pos_nodes[6][2]*reg40;
    reg60=reg47+reg60; reg47=reg43*pos_nodes[1][2]; T reg70=pos_nodes[1][2]*reg42; T reg71=pos_nodes[2][1]*reg35; T reg72=2*reg64;
    reg61=reg62+reg61; reg62=pos_nodes[7][1]*reg58; reg63=reg57-reg63; reg57=pos_nodes[7][2]*reg58; T reg73=pos_nodes[6][1]*reg40;
    reg66=reg44+reg66; reg38=reg41+reg38; reg41=pos_nodes[2][0]*reg35; reg67=reg68+reg67; reg44=pos_nodes[7][0]*reg58;
    reg30=reg25-reg30; reg25=pos_nodes[6][0]*reg40; reg59=reg37+reg59; reg50=reg65+reg50; reg37=reg3-reg8;
    reg11=reg11*reg2; reg5=reg10-reg5; reg6=reg6-reg33; reg3=reg3-reg1; reg10=pos_nodes[8][0]*reg72;
    reg65=pos_nodes[3][1]*reg5; reg53=reg60-reg53; reg44=reg30-reg44; reg30=pos_nodes[8][1]*reg72; reg62=reg63-reg62;
    reg60=pos_nodes[4][1]*reg6; reg63=pos_nodes[7][2]*reg40; reg38=reg51+reg38; reg51=pos_nodes[3][0]*reg5; reg71=reg61+reg71;
    reg69=reg47+reg69; reg41=reg67+reg41; reg48=reg70+reg48; reg47=pos_nodes[8][2]*reg72; reg57=reg36-reg57;
    reg36=reg27*reg3; reg73=reg66-reg73; reg25=reg59-reg25; reg4=reg11-reg4; reg14=reg2*reg14;
    reg50=reg52+reg50; reg11=pos_nodes[7][0]*reg40; reg52=pos_nodes[4][0]*reg6; reg59=reg27*reg37; reg61=pos_nodes[2][2]*reg35;
    reg66=pos_nodes[7][1]*reg40; reg67=pos_nodes[4][2]*reg6; reg48=reg55+reg48; reg55=pos_nodes[3][2]*reg5; reg61=reg69+reg61;
    reg68=pos_nodes[4][1]*reg4; reg71=reg65+reg71; reg65=pos_nodes[8][1]*reg59; reg73=reg66+reg73; reg66=pos_nodes[6][0]*reg36;
    reg52=reg50+reg52; reg50=reg27*reg8; reg30=reg62-reg30; reg60=reg38+reg60; reg38=pos_nodes[9][1]*reg56;
    reg62=pos_nodes[6][1]*reg36; reg69=pos_nodes[9][0]*reg56; reg10=reg44-reg10; reg53=reg63+reg53; reg44=pos_nodes[8][2]*reg59;
    reg63=reg2*reg1; reg12=reg14-reg12; reg25=reg11+reg25; reg11=pos_nodes[8][0]*reg59; reg47=reg57-reg47;
    reg41=reg51+reg41; reg14=pos_nodes[9][2]*reg56; reg51=pos_nodes[4][0]*reg4; reg69=reg10+reg69; reg10=pos_nodes[10][1]*reg58;
    reg38=reg30+reg38; reg30=pos_nodes[9][1]*reg63; reg65=reg73+reg65; reg57=reg27*reg46; reg44=reg53+reg44;
    reg53=pos_nodes[9][2]*reg63; reg61=reg55+reg61; reg55=pos_nodes[4][2]*reg4; reg70=pos_nodes[9][0]*reg63; reg11=reg25+reg11;
    reg25=pos_nodes[7][0]*reg50; reg73=pos_nodes[5][1]*reg12; reg68=reg71+reg68; reg71=pos_nodes[6][2]*reg36; reg51=reg41+reg51;
    reg41=pos_nodes[7][1]*reg50; T reg74=pos_nodes[5][0]*reg12; reg66=reg52+reg66; reg52=pos_nodes[10][2]*reg58; reg14=reg47+reg14;
    reg67=reg48+reg67; reg47=pos_nodes[10][0]*reg58; reg62=reg60+reg62; reg48=reg27*reg54; reg60=pos_nodes[7][2]*reg50;
    reg3=reg2*reg3; T reg75=pos_nodes[6][1]*reg57; reg73=reg68+reg73; reg71=reg67+reg71; reg67=pos_nodes[10][2]*reg63;
    reg53=reg44-reg53; reg44=pos_nodes[11][2]*reg72; reg52=reg14+reg52; reg10=reg38+reg10; reg14=pos_nodes[11][1]*reg72;
    reg37=reg2*reg37; reg38=pos_nodes[8][0]*reg50; reg66=reg25+reg66; reg62=reg41+reg62; reg25=reg0*reg9;
    reg70=reg11-reg70; reg11=pos_nodes[10][0]*reg63; reg41=pos_nodes[5][2]*reg12; reg55=reg61+reg55; reg61=pos_nodes[8][1]*reg50;
    reg30=reg65-reg30; reg65=pos_nodes[10][1]*reg63; reg74=reg51+reg74; reg51=pos_nodes[6][0]*reg57; reg68=pos_nodes[11][0]*reg72;
    reg47=reg69+reg47; reg69=pos_nodes[7][1]*reg48; reg68=reg47+reg68; reg41=reg55+reg41; reg47=pos_nodes[6][2]*reg57;
    reg55=pos_nodes[12][0]*reg25; T reg76=reg48*pos_nodes[7][0]; reg75=reg73+reg75; reg73=pos_nodes[8][2]*reg50; reg71=reg60+reg71;
    reg60=pos_nodes[9][0]*reg3; reg38=reg66-reg38; reg51=reg74+reg51; reg44=reg52+reg44; reg52=pos_nodes[12][2]*reg25;
    reg67=reg53+reg67; reg53=pos_nodes[12][1]*reg25; reg14=reg10+reg14; reg61=reg62-reg61; reg10=pos_nodes[9][1]*reg3;
    reg62=pos_nodes[11][2]*reg37; reg66=pos_nodes[11][0]*reg37; reg74=var_inter[0]*reg9; reg27=reg27*reg64; reg11=reg70+reg11;
    reg70=pos_nodes[11][1]*reg37; reg65=reg30+reg65; reg30=reg8*reg2; reg51=reg76+reg51; reg76=reg27*pos_nodes[8][0];
    reg66=reg11+reg66; reg73=reg71-reg73; reg11=pos_nodes[9][2]*reg3; reg60=reg38+reg60; reg38=reg19*pos_nodes[12][2];
    reg71=pos_nodes[10][0]*reg30; T reg77=pos_nodes[13][0]*reg74; reg55=reg68-reg55; reg68=var_inter[1]*reg9; reg46=reg46*reg2;
    reg62=reg67+reg62; reg67=reg19*pos_nodes[12][0]; T reg78=pos_nodes[10][1]*reg30; reg10=reg61+reg10; reg53=reg14-reg53;
    reg14=pos_nodes[13][1]*reg74; reg47=reg41+reg47; reg41=reg19*pos_nodes[12][1]; reg75=reg69+reg75; reg61=reg27*pos_nodes[8][1];
    reg70=reg65+reg70; reg52=reg44-reg52; reg44=pos_nodes[13][2]*reg74; reg65=pos_nodes[7][2]*reg48; reg69=reg27*pos_nodes[8][2];
    reg47=reg65+reg47; reg65=reg46*pos_nodes[9][0]; T reg79=pos_nodes[11][1]*reg30; T reg80=pos_nodes[14][1]*reg68; reg14=reg53-reg14;
    reg71=reg60+reg71; reg53=pos_nodes[11][0]*reg30; reg54=reg54*reg2; reg78=reg10+reg78; reg44=reg52-reg44;
    reg62=reg62-reg38; reg10=reg19*pos_nodes[14][2]; reg70=reg70-reg41; reg52=reg46*pos_nodes[9][1]; reg61=reg75+reg61;
    reg66=reg66-reg67; reg11=reg73+reg11; reg60=pos_nodes[10][2]*reg30; reg73=reg19*pos_nodes[14][1]; reg75=reg19*pos_nodes[14][0];
    T reg81=pos_nodes[14][2]*reg68; reg76=reg51+reg76; reg51=pos_nodes[14][0]*reg68; reg77=reg55-reg77; reg73=reg70+reg73;
    reg75=reg66+reg75; reg10=reg62+reg10; reg2=reg64*reg2; reg79=reg78-reg79; reg65=reg76+reg65;
    reg81=reg44-reg81; reg44=reg54*pos_nodes[10][0]; reg53=reg71-reg53; reg80=reg14-reg80; reg51=reg77-reg51;
    reg69=reg47+reg69; reg14=reg46*pos_nodes[9][2]; reg47=reg54*pos_nodes[10][1]; reg55=pos_nodes[11][2]*reg30; reg60=reg11+reg60;
    reg52=reg61+reg52; reg11=reg73*reg81; reg61=reg54*pos_nodes[10][2]; reg14=reg69+reg14; reg62=reg80*reg10;
    reg64=reg51*reg10; reg66=reg75*reg81; reg0=reg19*reg0; reg69=reg2*pos_nodes[11][0]; reg55=reg60-reg55;
    reg41=reg79-reg41; reg60=reg19*pos_nodes[13][1]; reg70=reg19*pos_nodes[13][0]; reg44=reg65+reg44; reg67=reg53-reg67;
    reg53=reg2*pos_nodes[11][1]; reg47=reg52+reg47; reg52=reg0*pos_nodes[12][0]; reg69=reg44+reg69; reg61=reg14+reg61;
    reg14=reg2*pos_nodes[11][2]; reg60=reg41+reg60; reg41=reg19*var_inter[0]; reg62=reg11-reg62; reg53=reg47+reg53;
    reg44=reg0*pos_nodes[12][1]; reg47=reg75*reg80; reg70=reg67+reg70; reg64=reg66-reg64; reg65=reg51*reg73;
    reg38=reg55-reg38; reg55=reg19*pos_nodes[13][2]; reg67=reg70*reg62; reg71=reg60*reg64; reg76=reg0*pos_nodes[12][2];
    reg14=reg61+reg14; reg65=reg47-reg65; reg55=reg38+reg55; reg38=reg41*pos_nodes[13][1]; reg44=reg53+reg44;
    reg53=reg19*var_inter[1]; reg52=reg69+reg52; reg61=reg41*pos_nodes[13][0]; reg69=reg60*reg10; reg77=reg80*reg55;
    reg78=reg60*reg81; reg79=reg73*reg55; T reg82=reg55*reg65; reg67=reg71-reg67; reg71=reg70*reg81;
    T reg83=reg53*pos_nodes[14][1]; reg38=reg44+reg38; reg61=reg52+reg61; reg44=reg53*pos_nodes[14][0]; reg52=reg51*reg55;
    T reg84=reg70*reg10; T reg85=reg75*reg55; T reg86=reg41*pos_nodes[13][2]; reg76=reg14+reg76; reg52=reg71-reg52;
    reg85=reg84-reg85; reg79=reg69-reg79; reg14=reg70*reg80; T reg87=reg51*reg60; reg77=reg78-reg77;
    T reg88=reg70*reg73; T reg89=reg75*reg60; reg44=reg61+reg44; reg86=reg76+reg86; reg61=reg53*pos_nodes[14][2];
    reg83=reg38+reg83; reg82=reg67-reg82; reg64=reg64/reg82; reg83=pos[1]-reg83; reg52=reg52/reg82;
    reg79=reg79/reg82; reg89=reg88-reg89; reg61=reg86+reg61; reg85=reg85/reg82; reg62=reg62/reg82;
    reg77=reg77/reg82; reg44=pos[0]-reg44; reg87=reg14-reg87; reg64=reg83*reg64; reg77=reg44*reg77;
    reg52=reg83*reg52; reg79=reg44*reg79; reg85=reg83*reg85; reg62=reg44*reg62; reg89=reg89/reg82;
    reg87=reg87/reg82; reg82=reg65/reg82; reg61=pos[2]-reg61; reg82=reg61*reg82; reg62=reg64-reg62;
    reg87=reg61*reg87; reg52=reg77-reg52; reg89=reg61*reg89; reg79=reg85-reg79; var_inter[0]+=reg62-reg82;
    var_inter[1]+=reg87+reg52; var_inter[2]+=reg79-reg89;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*reg0; T reg3=2*var_inter[0];
    reg1=reg1-1; T reg4=2*var_inter[1]; T reg5=reg2-1; T reg6=0.5*reg0; T reg7=reg3-1;
    T reg8=0.5*var_inter[0]; T reg9=pow(reg1,2); T reg10=1-reg1; reg5=reg6*reg5; reg9=1-reg9;
    reg7=reg8*reg7; T reg11=0.5*var_inter[1]; T reg12=reg4-1; T reg13=reg5*reg10; reg6=reg6*reg9;
    T reg14=reg10*reg7; reg8=reg9*reg8; reg12=reg11*reg12; T reg15=reg10*reg12; reg14=reg14-reg8;
    reg11=reg9*reg11; reg1=1+reg1; reg13=reg13-reg6; reg13=val[0]*reg13; reg5=reg5*reg1;
    reg15=reg15-reg11; reg14=val[1]*reg14; reg6=reg5-reg6; reg15=val[2]*reg15; reg7=reg7*reg1;
    reg14=reg13+reg14; reg15=reg14+reg15; reg6=val[3]*reg6; reg8=reg7-reg8; reg12=reg12*reg1;
    reg2=var_inter[0]*reg2; reg11=reg12-reg11; reg8=val[4]*reg8; reg6=reg15+reg6; reg5=reg10*reg2;
    reg11=val[5]*reg11; reg8=reg6+reg8; reg6=var_inter[1]*reg3; reg5=val[6]*reg5; reg11=reg8+reg11;
    reg7=reg10*reg6; reg8=reg0*reg4; reg7=val[7]*reg7; reg5=reg11+reg5; reg10=reg10*reg8;
    reg7=reg5+reg7; reg10=val[8]*reg10; reg2=reg1*reg2; reg6=reg1*reg6; reg10=reg7+reg10;
    reg2=val[9]*reg2; reg8=reg1*reg8; reg6=val[10]*reg6; reg2=reg10+reg2; reg0=reg0*reg9;
    reg8=val[11]*reg8; reg6=reg2+reg6; reg0=val[12]*reg0; reg1=var_inter[0]*reg9; reg8=reg6+reg8;
    reg0=reg8+reg0; reg1=val[13]*reg1; reg9=var_inter[1]*reg9; reg9=val[14]*reg9; reg1=reg0+reg1;
    res=reg1+reg9;

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
    T reg0=2*var_inter[1]; T reg1=2*var_inter[0]; T reg2=var_inter[2]-0.14644660940672626914; T reg3=reg1+reg0; T reg4=1-var_inter[2];
    reg2=reg2/0.70710678118654746172; reg4=reg4-0.14644660940672626914; T reg5=1-reg1; reg2=1-reg2; reg3=reg3-1;
    T reg6=reg3*reg2; T reg7=reg2*reg5; T reg8=1-reg0; reg4=reg4/0.70710678118654746172; reg6=val[0]*reg6;
    reg7=val[1]*reg7; reg2=reg2*reg8; reg4=1-reg4; T reg9=reg3*reg4; reg2=val[2]*reg2;
    reg7=reg6+reg7; reg2=reg7+reg2; reg9=val[3]*reg9; reg6=reg5*reg4; reg9=reg2+reg9;
    reg6=val[4]*reg6; reg4=reg8*reg4; reg6=reg9+reg6; reg4=val[5]*reg4; res=reg6+reg4;

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[1]; T reg1=2*var_inter[0]; T reg2=reg1+reg0; reg2=reg2-1; T reg3=1-reg1;
    T reg4=1-reg0; T reg5=val[0]*reg2; T reg6=val[1]*reg3; reg6=reg5+reg6; reg5=val[2]*reg4;
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*var_inter[1]; T reg3=2*var_inter[0];
    reg1=reg1-1; T reg4=2*reg0; T reg5=reg2-1; T reg6=pow(reg1,2); T reg7=reg4-1;
    T reg8=0.5*var_inter[1]; T reg9=0.5*var_inter[0]; T reg10=0.5*reg0; T reg11=reg3-1; T reg12=1+reg1;
    reg5=reg8*reg5; reg11=reg9*reg11; reg7=reg10*reg7; reg6=1-reg6; reg1=1-reg1;
    T reg13=var_inter[1]*reg3; T reg14=reg0*reg2; reg4=var_inter[0]*reg4; T reg15=reg5*reg12; T reg16=reg11*reg12;
    T reg17=reg7*reg12; reg8=reg6*reg8; reg5=reg1*reg5; reg7=reg7*reg1; reg10=reg10*reg6;
    reg9=reg6*reg9; reg11=reg1*reg11; T reg18=reg12*reg14; res[11]=reg18; reg0=reg0*reg6;
    res[12]=reg0; T reg19=reg12*reg13; res[10]=reg19; reg12=reg12*reg4; res[9]=reg12;
    reg14=reg1*reg14; res[8]=reg14; T reg20=var_inter[0]*reg6; res[13]=reg20; reg13=reg1*reg13;
    res[7]=reg13; reg4=reg1*reg4; res[6]=reg4; reg15=reg15-reg8; res[5]=reg15;
    reg16=reg16-reg9; res[4]=reg16; reg17=reg17-reg10; res[3]=reg17; reg8=reg5-reg8;
    res[2]=reg8; reg6=var_inter[1]*reg6; res[14]=reg6; reg9=reg11-reg9; res[1]=reg9;
    reg10=reg7-reg10; res[0]=reg10;

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

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Wedge_15,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*reg0; T reg3=2*var_inter[0];
    T reg4=0.5*var_inter[0]; T reg5=reg2-1; T reg6=0.5*reg0; T reg7=reg3-1; T reg8=2*var_inter[1];
    reg1=reg1-1; T reg9=4*reg1; T reg10=reg6*reg5; T reg11=reg4*reg7; T reg12=reg8-1;
    T reg13=0.5*var_inter[1]; T reg14=2*reg10; T reg15=reg13*reg12; T reg16=reg6*reg9; T reg17=reg4*reg9;
    T reg18=2*reg11; T reg19=reg17-reg18; T reg20=reg16-reg14; T reg21=2*reg15; T reg22=reg13*reg9;
    reg5=0.5*reg5; T reg23=pow(reg1,2); reg12=0.5*reg12; reg7=0.5*reg7; T reg24=reg22-reg21;
    reg23=1-reg23; reg12=var_inter[1]+reg12; T reg25=elem.pos(0)[2]*reg20; T reg26=elem.pos(1)[2]*reg19; T reg27=elem.pos(1)[1]*reg19;
    T reg28=1-reg1; T reg29=elem.pos(0)[1]*reg20; reg7=var_inter[0]+reg7; reg5=reg0+reg5; reg29=reg27+reg29;
    reg1=1+reg1; reg27=elem.pos(2)[1]*reg24; T reg30=0.5*reg23; T reg31=reg28*reg7; T reg32=elem.pos(2)[2]*reg24;
    reg26=reg25+reg26; reg25=reg14+reg16; T reg33=reg28*reg5; T reg34=reg28*reg12; reg31=reg31-reg30;
    T reg35=reg30-reg33; T reg36=reg1*reg5; T reg37=elem.pos(3)[2]*reg25; reg34=reg34-reg30; reg26=reg32+reg26;
    reg32=reg18+reg17; reg29=reg27+reg29; reg27=elem.pos(3)[1]*reg25; reg27=reg29+reg27; reg29=reg21+reg22;
    T reg38=elem.pos(1)[2]*reg31; T reg39=elem.pos(4)[1]*reg32; reg7=reg1*reg7; T reg40=elem.pos(4)[2]*reg32; reg20=elem.pos(0)[0]*reg20;
    reg19=elem.pos(1)[0]*reg19; T reg41=elem.pos(2)[2]*reg34; T reg42=elem.pos(1)[1]*reg31; reg37=reg26+reg37; reg26=elem.pos(2)[1]*reg34;
    T reg43=var_inter[0]*reg2; T reg44=elem.pos(0)[1]*reg35; reg12=reg1*reg12; T reg45=reg30-reg36; T reg46=elem.pos(0)[2]*reg35;
    reg7=reg7-reg30; T reg47=elem.pos(3)[1]*reg45; T reg48=elem.pos(5)[1]*reg29; reg39=reg27+reg39; reg27=reg2-reg3;
    reg38=reg38+reg46; reg42=reg44+reg42; reg41=reg46+reg41; reg20=reg19+reg20; reg44=reg26+reg44;
    reg19=var_inter[1]*reg3; reg12=reg12-reg30; reg26=elem.pos(3)[2]*reg45; reg40=reg37+reg40; reg24=elem.pos(2)[0]*reg24;
    reg37=elem.pos(5)[2]*reg29; reg46=2*reg43; T reg49=elem.pos(4)[1]*reg7; T reg50=2*reg19; T reg51=elem.pos(6)[1]*reg46;
    reg24=reg20+reg24; reg34=elem.pos(2)[0]*reg34; reg37=reg40+reg37; reg41=reg26+reg41; reg44=reg44+reg47;
    reg35=elem.pos(0)[0]*reg35; reg26=reg38+reg26; reg31=elem.pos(1)[0]*reg31; reg20=elem.pos(5)[2]*reg12; reg38=reg28*reg27;
    reg40=reg28*reg3; T reg52=elem.pos(4)[2]*reg7; T reg53=elem.pos(5)[1]*reg12; T reg54=elem.pos(6)[2]*reg46; T reg55=reg0*reg8;
    reg25=elem.pos(3)[0]*reg25; reg42=reg47+reg42; reg48=reg39+reg48; reg37=reg37-reg54; reg39=elem.pos(7)[2]*reg50;
    reg49=reg42+reg49; reg26=reg52+reg26; reg45=elem.pos(3)[0]*reg45; reg42=elem.pos(6)[1]*reg38; reg32=elem.pos(4)[0]*reg32;
    reg47=elem.pos(7)[1]*reg50; reg34=reg35+reg34; reg52=elem.pos(6)[1]*reg40; reg44=reg53+reg44; reg53=elem.pos(6)[2]*reg38;
    reg31=reg35+reg31; reg24=reg25+reg24; reg25=elem.pos(6)[2]*reg40; reg48=reg48-reg51; reg2=reg2-reg8;
    reg35=reg28*reg8; reg20=reg41+reg20; reg41=2*reg55; reg42=reg49+reg42; reg37=reg37-reg39;
    reg48=reg48-reg47; reg24=reg32+reg24; reg32=elem.pos(7)[1]*reg40; reg20=reg20-reg25; reg34=reg34+reg45;
    reg45=reg31+reg45; reg31=elem.pos(7)[1]*reg35; reg53=reg26+reg53; reg26=elem.pos(7)[2]*reg35; reg12=elem.pos(5)[0]*reg12;
    reg7=elem.pos(4)[0]*reg7; reg49=reg41*elem.pos(8)[1]; T reg56=elem.pos(7)[2]*reg40; reg29=elem.pos(5)[0]*reg29; reg44=reg44-reg52;
    T reg57=reg28*reg2; T reg58=reg41*elem.pos(8)[2]; T reg59=reg3*reg1; T reg60=elem.pos(8)[2]*reg57; T reg61=elem.pos(6)[0]*reg46;
    reg26=reg53+reg26; reg53=elem.pos(8)[2]*reg35; reg12=reg34+reg12; reg34=elem.pos(8)[1]*reg57; reg38=elem.pos(6)[0]*reg38;
    reg44=reg32+reg44; reg32=elem.pos(6)[0]*reg40; T reg62=elem.pos(8)[1]*reg35; reg24=reg29+reg24; reg20=reg56+reg20;
    reg29=elem.pos(9)[2]*reg46; reg31=reg42+reg31; reg27=reg1*reg27; reg45=reg7+reg45; reg37=reg37-reg58;
    reg48=reg48-reg49; reg7=elem.pos(9)[1]*reg46; reg38=reg45+reg38; reg60=reg20+reg60; reg20=elem.pos(7)[0]*reg35;
    reg31=reg31-reg62; reg42=elem.pos(9)[1]*reg27; reg45=elem.pos(9)[2]*reg59; reg56=elem.pos(9)[2]*reg27; reg29=reg37+reg29;
    reg37=elem.pos(10)[2]*reg50; T reg63=elem.pos(7)[0]*reg40; T reg64=elem.pos(10)[1]*reg50; reg44=reg34+reg44; reg34=elem.pos(9)[1]*reg59;
    reg12=reg12-reg32; T reg65=reg8*reg1; reg7=reg48+reg7; reg26=reg26-reg53; reg24=reg24-reg61;
    reg48=elem.pos(7)[0]*reg50; reg57=elem.pos(8)[0]*reg57; T reg66=elem.pos(8)[0]*reg35; T reg67=reg0*reg9; reg12=reg63+reg12;
    reg42=reg31+reg42; reg37=reg29+reg37; reg24=reg24-reg48; reg29=elem.pos(10)[1]*reg65; reg31=reg41*elem.pos(11)[2];
    reg63=elem.pos(10)[2]*reg59; T reg68=reg41*elem.pos(8)[0]; reg60=reg60-reg45; reg64=reg7+reg64; reg7=reg41*elem.pos(11)[1];
    T reg69=elem.pos(10)[1]*reg59; reg20=reg38+reg20; reg2=reg1*reg2; reg44=reg44-reg34; reg26=reg56+reg26;
    reg38=elem.pos(10)[2]*reg65; reg56=elem.pos(9)[0]*reg46; T reg70=elem.pos(11)[2]*reg65; reg63=reg60+reg63; reg20=reg20-reg66;
    reg60=elem.pos(9)[0]*reg59; reg57=reg12+reg57; reg12=elem.pos(11)[2]*reg2; reg24=reg24-reg68; T reg71=var_inter[0]*reg9;
    reg38=reg26+reg38; reg26=elem.pos(12)[1]*reg67; reg7=reg64+reg7; reg27=elem.pos(9)[0]*reg27; reg64=elem.pos(12)[2]*reg67;
    reg44=reg69+reg44; reg69=elem.pos(11)[1]*reg2; reg37=reg31+reg37; reg42=reg29+reg42; reg29=elem.pos(11)[1]*reg65;
    reg31=elem.pos(10)[0]*reg50; reg38=reg38-reg70; T reg72=elem.pos(12)[2]*reg23; reg37=reg37-reg64; T reg73=elem.pos(10)[0]*reg59;
    T reg74=elem.pos(13)[1]*reg71; reg7=reg7-reg26; T reg75=elem.pos(10)[0]*reg65; reg69=reg44+reg69; reg44=var_inter[1]*reg9;
    T reg76=elem.pos(13)[2]*reg71; reg63=reg12+reg63; reg24=reg56+reg24; reg20=reg27+reg20; reg12=elem.pos(12)[1]*reg23;
    reg42=reg42-reg29; reg57=reg57-reg60; reg27=reg41*elem.pos(11)[0]; reg38=reg38-reg72; reg37=reg37-reg76;
    reg73=reg57+reg73; reg56=elem.pos(14)[2]*reg44; reg57=elem.pos(14)[2]*reg23; reg63=reg63-reg72; reg2=elem.pos(11)[0]*reg2;
    reg31=reg24+reg31; reg7=reg7-reg74; reg24=elem.pos(14)[1]*reg44; reg75=reg20+reg75; reg20=elem.pos(13)[2]*reg23;
    reg42=reg42-reg12; T reg77=elem.pos(13)[1]*reg23; reg69=reg69-reg12; T reg78=elem.pos(11)[0]*reg65; T reg79=elem.pos(14)[1]*reg23;
    reg69=reg79+reg69; reg27=reg31+reg27; reg57=reg63+reg57; reg2=reg73+reg2; reg75=reg75-reg78;
    reg38=reg20+reg38; reg20=elem.pos(12)[0]*reg67; reg7=reg7-reg24; reg37=reg37-reg56; reg77=reg42+reg77;
    reg31=elem.pos(12)[0]*reg23; reg42=reg7*reg57; reg63=reg7*reg38; reg73=elem.pos(13)[0]*reg23; reg79=reg77*reg37;
    T reg80=elem.pos(13)[0]*reg71; reg2=reg2-reg31; T reg81=reg37*reg69; T reg82=elem.pos(14)[0]*reg23; reg75=reg75-reg31;
    reg27=reg27-reg20; T reg83=elem.pos(14)[0]*reg44; reg73=reg75+reg73; reg42=reg81-reg42; reg75=reg38*reg69;
    reg27=reg27-reg80; reg81=reg57*reg77; reg63=reg79-reg63; reg82=reg2+reg82; reg2=reg82*reg63;
    reg79=reg73*reg42; reg75=reg81-reg75; reg27=reg27-reg83; reg2=reg79-reg2; reg79=reg75*reg27;
    reg79=reg2+reg79; return reg79;

}
}
#endif // LMT_WEDGE_15
