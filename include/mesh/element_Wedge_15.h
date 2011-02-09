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
    T reg0=nodes[0]->pos[2]+nodes[3]->pos[2]; T reg1=nodes[0]->pos[1]+nodes[3]->pos[1]; reg0=reg0-nodes[6]->pos[2]; reg1=reg1-nodes[6]->pos[1]; reg0=nodes[7]->pos[2]+reg0;
    reg1=nodes[7]->pos[1]+reg1; T reg2=nodes[3]->pos[0]+nodes[0]->pos[0]; reg0=reg0-nodes[8]->pos[2]; reg1=reg1-nodes[8]->pos[1]; reg2=reg2-nodes[6]->pos[0];
    reg0=reg0-nodes[9]->pos[2]; reg1=reg1-nodes[9]->pos[1]; reg2=nodes[7]->pos[0]+reg2; reg1=nodes[10]->pos[1]+reg1; reg2=reg2-nodes[8]->pos[0];
    reg0=nodes[10]->pos[2]+reg0; reg1=reg1-nodes[11]->pos[1]; reg0=reg0-nodes[11]->pos[2]; reg2=reg2-nodes[9]->pos[0]; reg0=reg0-nodes[12]->pos[2];
    reg1=reg1-nodes[12]->pos[1]; reg2=nodes[10]->pos[0]+reg2; T reg3=nodes[13]->pos[2]+reg0; T reg4=nodes[13]->pos[1]+reg1; T reg5=nodes[10]->pos[1]-nodes[7]->pos[1];
    reg0=nodes[14]->pos[2]+reg0; T reg6=nodes[10]->pos[2]-nodes[7]->pos[2]; reg1=nodes[14]->pos[1]+reg1; reg2=reg2-nodes[11]->pos[0]; T reg7=reg5*reg3;
    T reg8=reg1*reg6; reg6=reg6*reg4; reg5=reg0*reg5; reg2=reg2-nodes[12]->pos[0]; T reg9=nodes[14]->pos[0]+reg2;
    reg5=reg8-reg5; reg7=reg6-reg7; reg4=reg0*reg4; reg3=reg1*reg3; reg2=nodes[13]->pos[0]+reg2;
    reg5=reg2*reg5; reg7=reg9*reg7; reg0=nodes[10]->pos[0]-nodes[7]->pos[0]; reg3=reg4-reg3; reg7=reg5-reg7;
    reg3=reg0*reg3; T det_jac=reg7+reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[14],nodes[13],nodes[12],nodes[11],nodes[10],nodes[9],nodes[8],nodes[7],nodes[6],nodes[5],nodes[4],nodes[3],nodes[2],nodes[1],nodes[0]};
        for(unsigned i=0;i<15;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*var_inter[0]; T reg3=2*reg0;
    T reg4=reg2-1; T reg5=0.5*var_inter[0]; T reg6=0.5*reg0; T reg7=reg3-1; reg1=reg1-1;
    T reg8=2*var_inter[1]; T reg9=reg7*reg6; T reg10=reg5*reg4; T reg11=0.5*var_inter[1]; T reg12=reg8-1;
    T reg13=4*reg1; T reg14=reg6*reg13; T reg15=2*reg9; T reg16=reg5*reg13; T reg17=reg11*reg12;
    T reg18=2*reg10; reg7=0.5*reg7; T reg19=pow(reg1,2); reg12=0.5*reg12; T reg20=reg16-reg18;
    T reg21=reg14-reg15; T reg22=2*reg17; T reg23=reg11*reg13; reg19=1-reg19; reg7=reg0+reg7;
    reg12=var_inter[1]+reg12; T reg24=pos_nodes[1][1]*reg20; T reg25=pos_nodes[0][1]*reg21; T reg26=pos_nodes[0][2]*reg21; T reg27=pos_nodes[1][2]*reg20;
    T reg28=reg23-reg22; T reg29=pos_nodes[0][0]*reg21; T reg30=pos_nodes[1][0]*reg20; T reg31=1-reg1; T reg32=0.5*reg19;
    T reg33=pos_nodes[2][1]*reg28; reg4=0.5*reg4; T reg34=reg15+reg14; reg25=reg24+reg25; reg24=reg31*reg12;
    reg26=reg27+reg26; reg27=pos_nodes[2][2]*reg28; T reg35=reg31*reg7; reg1=1+reg1; T reg36=pos_nodes[2][0]*reg28;
    reg29=reg30+reg29; reg30=reg1*reg7; reg33=reg25+reg33; reg25=pos_nodes[3][1]*reg34; reg27=reg26+reg27;
    reg26=pos_nodes[3][2]*reg34; T reg37=reg32-reg35; reg4=var_inter[0]+reg4; T reg38=reg18+reg16; reg24=reg24-reg32;
    T reg39=pos_nodes[3][0]*reg34; reg36=reg29+reg36; reg29=pos_nodes[4][1]*reg38; reg25=reg33+reg25; reg33=pos_nodes[2][0]*reg24;
    T reg40=pos_nodes[4][2]*reg38; reg26=reg27+reg26; reg27=pos_nodes[2][2]*reg24; T reg41=reg22+reg23; T reg42=pos_nodes[4][0]*reg38;
    reg39=reg36+reg39; reg36=pos_nodes[0][2]*reg37; T reg43=reg9*reg31; T reg44=reg31*reg4; reg12=reg1*reg12;
    T reg45=reg32-reg30; reg6=reg6*reg19; T reg46=pos_nodes[2][1]*reg24; T reg47=pos_nodes[0][0]*reg37; T reg48=reg3*var_inter[0];
    T reg49=pos_nodes[0][1]*reg37; T reg50=reg31*reg10; reg5=reg19*reg5; T reg51=pos_nodes[5][0]*reg41; T reg52=2*reg48;
    T reg53=pos_nodes[5][2]*reg41; reg40=reg26+reg40; reg26=pos_nodes[3][1]*reg45; T reg54=pos_nodes[3][0]*reg45; T reg55=reg2*var_inter[1];
    reg27=reg36+reg27; reg44=reg44-reg32; reg12=reg12-reg32; T reg56=pos_nodes[3][2]*reg45; reg33=reg47+reg33;
    reg11=reg11*reg19; reg43=reg43-reg6; T reg57=reg17*reg31; reg50=reg50-reg5; reg42=reg39+reg42;
    reg46=reg46+reg49; reg29=reg25+reg29; reg25=pos_nodes[5][1]*reg41; reg9=reg1*reg9; reg39=pos_nodes[1][1]*reg44;
    reg57=reg57-reg11; T reg58=pos_nodes[6][0]*reg52; T reg59=reg8*reg0; T reg60=2*reg55; reg27=reg56+reg27;
    T reg61=pos_nodes[5][2]*reg12; reg51=reg42+reg51; reg42=reg2*reg31; reg33=reg54+reg33; T reg62=pos_nodes[5][0]*reg12;
    T reg63=pos_nodes[5][1]*reg12; reg46=reg46+reg26; reg25=reg29+reg25; reg29=pos_nodes[6][1]*reg52; T reg64=pos_nodes[1][0]*reg50;
    T reg65=pos_nodes[6][2]*reg52; T reg66=reg43*pos_nodes[0][1]; T reg67=pos_nodes[1][1]*reg50; reg4=reg1*reg4; T reg68=pos_nodes[1][0]*reg44;
    T reg69=reg43*pos_nodes[0][0]; reg53=reg40+reg53; reg47=reg68+reg47; reg40=pos_nodes[7][2]*reg60; reg68=reg3-reg2;
    reg4=reg4-reg32; reg65=reg53-reg65; reg49=reg39+reg49; reg39=pos_nodes[1][2]*reg50; reg53=pos_nodes[0][2]*reg43;
    T reg70=pos_nodes[6][0]*reg42; reg62=reg33+reg62; reg61=reg27+reg61; reg27=pos_nodes[6][2]*reg42; reg33=2*reg59;
    reg3=reg3-reg8; T reg71=pos_nodes[7][1]*reg60; reg29=reg25-reg29; reg25=pos_nodes[6][1]*reg42; reg63=reg46+reg63;
    reg66=reg67+reg66; reg46=reg57*pos_nodes[2][1]; reg69=reg64+reg69; reg64=reg57*pos_nodes[2][0]; reg67=pos_nodes[7][0]*reg60;
    reg58=reg51-reg58; reg51=pos_nodes[1][2]*reg44; reg10=reg1*reg10; reg6=reg9-reg6; reg54=reg47+reg54;
    reg9=pos_nodes[4][0]*reg4; reg46=reg66+reg46; reg25=reg63-reg25; reg47=pos_nodes[7][1]*reg42; reg63=reg31*reg3;
    reg70=reg62-reg70; reg62=pos_nodes[7][0]*reg42; reg66=pos_nodes[8][1]*reg33; reg71=reg29-reg71; reg40=reg65-reg40;
    reg29=pos_nodes[8][2]*reg33; reg65=reg57*pos_nodes[2][2]; reg53=reg39+reg53; reg5=reg10-reg5; reg36=reg51+reg36;
    reg67=reg58-reg67; reg10=pos_nodes[8][0]*reg33; reg17=reg17*reg1; reg26=reg49+reg26; reg39=pos_nodes[4][1]*reg4;
    reg49=reg31*reg68; reg64=reg69+reg64; reg51=reg6*pos_nodes[3][0]; reg58=reg6*pos_nodes[3][1]; reg27=reg61-reg27;
    reg61=pos_nodes[7][2]*reg42; reg65=reg53+reg65; reg53=reg6*pos_nodes[3][2]; reg69=pos_nodes[8][0]*reg63; T reg72=reg8*reg31;
    reg51=reg64+reg51; reg62=reg70+reg62; reg11=reg17-reg11; reg17=reg1*reg2; reg64=pos_nodes[8][1]*reg63;
    reg47=reg25+reg47; reg39=reg26+reg39; reg25=pos_nodes[6][1]*reg49; reg26=reg5*pos_nodes[4][0]; reg9=reg54+reg9;
    reg54=pos_nodes[6][0]*reg49; reg70=pos_nodes[9][1]*reg52; reg66=reg71-reg66; reg29=reg40-reg29; reg10=reg67-reg10;
    reg56=reg36+reg56; reg36=reg5*pos_nodes[4][1]; reg58=reg46+reg58; reg61=reg27+reg61; reg27=pos_nodes[9][2]*reg52;
    reg40=pos_nodes[8][2]*reg63; reg46=pos_nodes[9][0]*reg52; reg67=pos_nodes[4][2]*reg4; reg64=reg47+reg64; reg47=pos_nodes[9][1]*reg17;
    reg40=reg61+reg40; reg61=pos_nodes[10][1]*reg60; reg71=pos_nodes[10][0]*reg60; T reg73=pos_nodes[9][2]*reg17; reg26=reg51+reg26;
    reg46=reg10+reg46; reg54=reg9+reg54; reg9=pos_nodes[7][0]*reg72; reg67=reg56+reg67; reg10=pos_nodes[6][2]*reg49;
    reg51=pos_nodes[5][1]*reg11; reg56=reg48*reg31; T reg74=pos_nodes[5][0]*reg11; reg36=reg58+reg36; reg58=pos_nodes[10][2]*reg60;
    reg27=reg29+reg27; reg53=reg65+reg53; reg29=reg5*pos_nodes[4][2]; reg39=reg25+reg39; reg25=pos_nodes[7][1]*reg72;
    reg65=pos_nodes[9][0]*reg17; reg69=reg62+reg69; reg70=reg66+reg70; reg25=reg39+reg25; reg39=pos_nodes[8][1]*reg72;
    reg68=reg1*reg68; reg62=pos_nodes[6][0]*reg56; reg66=reg55*reg31; reg73=reg40-reg73; reg40=pos_nodes[10][2]*reg17;
    reg51=reg36+reg51; reg74=reg26+reg74; reg26=pos_nodes[6][1]*reg56; reg36=pos_nodes[11][2]*reg33; reg10=reg67+reg10;
    reg67=pos_nodes[7][2]*reg72; T reg75=pos_nodes[10][0]*reg17; reg58=reg27+reg58; reg29=reg53+reg29; reg27=pos_nodes[5][2]*reg11;
    reg65=reg69-reg65; reg53=reg0*reg13; reg69=pos_nodes[10][1]*reg17; reg47=reg64-reg47; reg3=reg1*reg3;
    reg61=reg70+reg61; reg9=reg54+reg9; reg54=pos_nodes[8][0]*reg72; reg71=reg46+reg71; reg46=pos_nodes[11][0]*reg33;
    reg64=pos_nodes[11][1]*reg33; reg70=pos_nodes[7][1]*reg66; T reg76=var_inter[0]*reg13; reg62=reg74+reg62; reg74=pos_nodes[7][0]*reg66;
    T reg77=pos_nodes[8][2]*reg72; reg26=reg51+reg26; reg67=reg10+reg67; reg10=pos_nodes[12][2]*reg53; reg36=reg58+reg36;
    reg51=pos_nodes[11][0]*reg3; reg75=reg65+reg75; reg46=reg71+reg46; reg58=pos_nodes[12][0]*reg53; reg27=reg29+reg27;
    reg29=pos_nodes[6][2]*reg56; reg65=pos_nodes[11][1]*reg3; reg69=reg47+reg69; reg64=reg61+reg64; reg47=pos_nodes[12][1]*reg53;
    reg31=reg59*reg31; reg39=reg25-reg39; reg25=pos_nodes[9][0]*reg68; reg54=reg9-reg54; reg9=pos_nodes[9][1]*reg68;
    reg61=reg8*reg1; reg40=reg73+reg40; reg71=pos_nodes[11][2]*reg3; reg51=reg75+reg51; reg74=reg62+reg74;
    reg62=var_inter[1]*reg13; reg73=pos_nodes[8][0]*reg31; reg58=reg46-reg58; reg46=pos_nodes[13][0]*reg76; reg25=reg54+reg25;
    reg54=pos_nodes[10][0]*reg61; reg75=pos_nodes[12][0]*reg19; T reg78=pos_nodes[7][2]*reg66; reg47=reg64-reg47; reg65=reg69+reg65;
    reg64=pos_nodes[13][1]*reg76; reg69=pos_nodes[9][2]*reg68; T reg79=pos_nodes[12][2]*reg19; T reg80=pos_nodes[12][1]*reg19; reg71=reg40+reg71;
    reg77=reg67-reg77; reg29=reg27+reg29; reg27=pos_nodes[10][1]*reg61; reg9=reg39+reg9; reg48=reg1*reg48;
    reg70=reg26+reg70; reg10=reg36-reg10; reg26=pos_nodes[13][2]*reg76; reg36=pos_nodes[8][1]*reg31; reg39=pos_nodes[14][2]*reg62;
    reg69=reg77+reg69; reg40=pos_nodes[10][2]*reg61; reg67=pos_nodes[11][0]*reg61; reg54=reg25+reg54; reg71=reg71-reg79;
    reg25=pos_nodes[14][2]*reg19; reg26=reg10-reg26; reg51=reg51-reg75; reg10=pos_nodes[14][0]*reg19; reg77=pos_nodes[9][0]*reg48;
    reg73=reg74+reg73; reg55=reg1*reg55; reg27=reg9+reg27; reg9=pos_nodes[11][1]*reg61; reg74=pos_nodes[8][2]*reg31;
    reg78=reg29+reg78; reg29=pos_nodes[14][0]*reg62; reg46=reg58-reg46; reg65=reg65-reg80; reg58=pos_nodes[14][1]*reg19;
    reg64=reg47-reg64; reg47=pos_nodes[14][1]*reg62; reg36=reg70+reg36; reg70=pos_nodes[9][1]*reg48; reg39=reg26-reg39;
    reg74=reg78+reg74; reg26=pos_nodes[9][2]*reg48; reg10=reg51+reg10; reg25=reg71+reg25; reg51=pos_nodes[11][2]*reg61;
    reg40=reg69+reg40; reg69=pos_nodes[10][1]*reg55; reg70=reg36+reg70; reg47=reg64-reg47; reg58=reg65+reg58;
    reg29=reg46-reg29; reg9=reg27-reg9; reg77=reg73+reg77; reg27=pos_nodes[10][0]*reg55; reg67=reg54-reg67;
    reg59=reg1*reg59; reg1=reg47*reg25; reg51=reg40-reg51; reg36=pos_nodes[11][1]*reg59; reg69=reg70+reg69;
    reg40=pos_nodes[13][1]*reg19; reg80=reg9-reg80; reg9=reg58*reg39; reg75=reg67-reg75; reg46=pos_nodes[13][0]*reg19;
    reg26=reg74+reg26; reg54=pos_nodes[10][2]*reg55; reg64=reg25*reg29; reg65=reg39*reg10; reg0=reg19*reg0;
    reg27=reg77+reg27; reg67=pos_nodes[11][0]*reg59; reg70=pos_nodes[13][2]*reg19; reg79=reg51-reg79; reg1=reg9-reg1;
    reg51=pos_nodes[12][1]*reg0; reg36=reg69+reg36; reg69=reg47*reg10; reg40=reg80+reg40; reg71=pos_nodes[12][0]*reg0;
    reg67=reg27+reg67; reg27=reg58*reg29; reg46=reg75+reg46; reg64=reg65-reg64; reg73=reg19*var_inter[0];
    reg74=pos_nodes[11][2]*reg59; reg54=reg26+reg54; reg71=reg67+reg71; reg26=pos_nodes[13][0]*reg73; reg51=reg36+reg51;
    reg36=pos_nodes[13][1]*reg73; reg67=reg19*var_inter[1]; reg27=reg69-reg27; reg75=reg40*reg64; reg74=reg54+reg74;
    reg54=pos_nodes[12][2]*reg0; reg77=reg1*reg46; reg70=reg79+reg70; reg78=pos_nodes[13][2]*reg73; reg54=reg74+reg54;
    reg74=reg70*reg10; reg79=reg25*reg46; reg80=reg58*reg70; T reg81=reg40*reg39; T reg82=reg47*reg70;
    T reg83=reg40*reg25; reg77=reg75-reg77; reg36=reg51+reg36; reg51=pos_nodes[14][1]*reg67; reg26=reg71+reg26;
    reg71=pos_nodes[14][0]*reg67; reg75=reg70*reg29; T reg84=reg70*reg27; T reg85=reg39*reg46; T reg86=reg40*reg10;
    T reg87=reg58*reg46; T reg88=reg40*reg29; T reg89=reg47*reg46; reg78=reg54+reg78; reg74=reg79-reg74;
    reg54=pos_nodes[14][2]*reg67; reg84=reg77-reg84; reg82=reg81-reg82; reg51=reg36+reg51; reg75=reg85-reg75;
    reg71=reg26+reg71; reg80=reg83-reg80; reg71=pos[0]-reg71; reg54=reg78+reg54; reg80=reg80/reg84;
    reg64=reg64/reg84; reg75=reg75/reg84; reg51=pos[1]-reg51; reg82=reg82/reg84; reg74=reg74/reg84;
    reg88=reg89-reg88; reg86=reg87-reg86; reg1=reg1/reg84; reg75=reg51*reg75; reg54=pos[2]-reg54;
    reg27=reg27/reg84; reg80=reg80*reg71; reg88=reg88/reg84; reg84=reg86/reg84; reg1=reg1*reg71;
    reg74=reg51*reg74; reg64=reg51*reg64; reg82=reg82*reg71; reg84=reg54*reg84; reg27=reg54*reg27;
    reg80=reg74-reg80; reg75=reg82-reg75; reg88=reg54*reg88; reg1=reg64-reg1; var_inter[2]=reg80-reg84;
    var_inter[1]=reg88+reg75; var_inter[0]=reg1-reg27;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*reg0; T reg3=2*var_inter[0];
    reg1=reg1-1; T reg4=reg3-1; T reg5=0.5*reg0; T reg6=2*var_inter[1]; T reg7=0.5*var_inter[0];
    T reg8=reg2-1; T reg9=reg7*reg4; T reg10=4*reg1; T reg11=0.5*var_inter[1]; T reg12=reg6-1;
    T reg13=reg5*reg8; T reg14=reg5*reg10; T reg15=2*reg13; T reg16=2*reg9; T reg17=reg12*reg11;
    T reg18=reg7*reg10; reg8=0.5*reg8; T reg19=reg14-reg15; T reg20=reg18-reg16; T reg21=pow(reg1,2);
    T reg22=reg11*reg10; T reg23=2*reg17; reg12=0.5*reg12; reg8=reg0+reg8; T reg24=pos_nodes[0][0]*reg19;
    T reg25=reg22-reg23; T reg26=pos_nodes[1][0]*reg20; reg12=reg12+var_inter[1]; reg21=1-reg21; T reg27=pos_nodes[0][2]*reg19;
    T reg28=pos_nodes[1][2]*reg20; T reg29=pos_nodes[1][1]*reg20; T reg30=pos_nodes[0][1]*reg19; T reg31=1-reg1; reg26=reg24+reg26;
    reg24=pos_nodes[2][2]*reg25; reg28=reg27+reg28; reg29=reg30+reg29; reg27=reg15+reg14; reg30=pos_nodes[2][0]*reg25;
    T reg32=pos_nodes[2][1]*reg25; T reg33=reg12*reg31; T reg34=reg8*reg31; reg1=1+reg1; T reg35=0.5*reg21;
    reg4=0.5*reg4; reg33=reg33-reg35; T reg36=pos_nodes[3][2]*reg27; reg28=reg24+reg28; reg24=reg16+reg18;
    T reg37=reg8*reg1; reg29=reg32+reg29; reg32=pos_nodes[3][1]*reg27; T reg38=reg35-reg34; reg4=reg4+var_inter[0];
    reg26=reg30+reg26; reg30=pos_nodes[3][0]*reg27; T reg39=reg9*reg31; reg7=reg21*reg7; T reg40=pos_nodes[4][1]*reg24;
    reg32=reg29+reg32; reg29=reg2*var_inter[0]; T reg41=reg38*pos_nodes[0][2]; T reg42=reg13*reg31; T reg43=pos_nodes[2][2]*reg33;
    T reg44=pos_nodes[4][2]*reg24; reg5=reg5*reg21; reg36=reg28+reg36; reg12=reg12*reg1; reg28=reg38*pos_nodes[0][0];
    T reg45=reg23+reg22; T reg46=pos_nodes[2][0]*reg33; T reg47=reg35-reg37; T reg48=pos_nodes[4][0]*reg24; T reg49=reg4*reg31;
    reg30=reg26+reg30; reg26=reg38*pos_nodes[0][1]; T reg50=pos_nodes[2][1]*reg33; reg36=reg44+reg36; reg50=reg26+reg50;
    reg46=reg28+reg46; reg44=pos_nodes[5][1]*reg45; T reg51=pos_nodes[5][2]*reg45; reg43=reg41+reg43; T reg52=reg47*pos_nodes[3][2];
    T reg53=pos_nodes[5][0]*reg45; T reg54=reg47*pos_nodes[3][1]; reg32=reg40+reg32; reg40=2*reg29; reg30=reg48+reg30;
    reg48=reg17*reg31; reg11=reg21*reg11; T reg55=reg3*var_inter[1]; reg42=reg42-reg5; reg49=reg49-reg35;
    reg12=reg12-reg35; T reg56=reg47*pos_nodes[3][0]; reg39=reg39-reg7; T reg57=reg3*reg31; T reg58=reg39*pos_nodes[1][1];
    T reg59=reg42*pos_nodes[0][1]; reg4=reg4*reg1; T reg60=reg12*pos_nodes[5][0]; reg13=reg1*reg13; T reg61=reg49*pos_nodes[1][1];
    T reg62=pos_nodes[6][1]*reg40; T reg63=pos_nodes[6][2]*reg40; reg46=reg56+reg46; reg36=reg51+reg36; reg48=reg48-reg11;
    reg32=reg44+reg32; reg44=reg49*pos_nodes[1][0]; reg51=reg12*pos_nodes[5][1]; reg50=reg54+reg50; T reg64=reg0*reg6;
    T reg65=reg12*pos_nodes[5][2]; T reg66=reg42*pos_nodes[0][0]; T reg67=pos_nodes[6][0]*reg40; reg43=reg52+reg43; reg30=reg53+reg30;
    reg53=reg39*pos_nodes[1][0]; T reg68=2*reg55; T reg69=reg2-reg3; reg53=reg66+reg53; reg61=reg26+reg61;
    reg63=reg36-reg63; reg26=2*reg64; reg4=reg4-reg35; reg67=reg30-reg67; reg30=pos_nodes[7][0]*reg68;
    reg36=pos_nodes[7][2]*reg68; reg66=reg48*pos_nodes[2][0]; T reg70=reg39*pos_nodes[1][2]; reg50=reg51+reg50; reg51=pos_nodes[6][1]*reg57;
    T reg71=reg42*pos_nodes[0][2]; T reg72=reg48*pos_nodes[2][1]; reg9=reg1*reg9; reg2=reg2-reg6; reg58=reg59+reg58;
    reg59=pos_nodes[6][2]*reg57; T reg73=pos_nodes[7][1]*reg68; reg43=reg65+reg43; reg62=reg32-reg62; reg44=reg28+reg44;
    reg46=reg60+reg46; reg28=pos_nodes[6][0]*reg57; reg32=reg49*pos_nodes[1][2]; reg5=reg13-reg5; reg13=pos_nodes[8][2]*reg26;
    reg36=reg63-reg36; reg60=reg5*pos_nodes[3][0]; reg53=reg66+reg53; reg59=reg43-reg59; reg32=reg41+reg32;
    reg17=reg17*reg1; reg41=pos_nodes[7][2]*reg57; reg43=reg5*pos_nodes[3][1]; reg58=reg72+reg58; reg7=reg9-reg7;
    reg9=reg4*pos_nodes[4][1]; reg63=pos_nodes[8][1]*reg26; reg73=reg62-reg73; reg54=reg61+reg54; reg51=reg50-reg51;
    reg50=pos_nodes[7][1]*reg57; reg30=reg67-reg30; reg61=reg48*pos_nodes[2][2]; reg62=reg31*reg2; reg65=reg69*reg31;
    reg66=pos_nodes[8][0]*reg26; reg67=reg4*pos_nodes[4][0]; reg56=reg44+reg56; reg28=reg46-reg28; reg44=pos_nodes[7][0]*reg57;
    reg70=reg71+reg70; reg50=reg51+reg50; reg46=reg4*pos_nodes[4][2]; reg51=reg5*pos_nodes[3][2]; reg70=reg61+reg70;
    reg52=reg32+reg52; reg32=reg65*pos_nodes[6][1]; reg54=reg9+reg54; reg9=reg6*reg31; reg13=reg36-reg13;
    reg36=pos_nodes[9][2]*reg40; reg61=pos_nodes[8][1]*reg62; reg71=pos_nodes[8][0]*reg62; reg44=reg28+reg44; reg56=reg67+reg56;
    reg28=reg65*pos_nodes[6][0]; reg63=reg73-reg63; reg67=pos_nodes[9][1]*reg40; reg72=reg7*pos_nodes[4][1]; reg73=reg3*reg1;
    reg43=reg58+reg43; reg41=reg59+reg41; reg58=pos_nodes[8][2]*reg62; reg66=reg30-reg66; reg30=pos_nodes[9][0]*reg40;
    reg60=reg53+reg60; reg53=reg7*pos_nodes[4][0]; reg11=reg17-reg11; reg17=reg29*reg31; reg60=reg53+reg60;
    reg61=reg50+reg61; reg50=pos_nodes[9][1]*reg73; reg53=pos_nodes[9][0]*reg73; reg59=reg11*pos_nodes[5][0]; reg71=reg44+reg71;
    reg51=reg70+reg51; reg44=reg7*pos_nodes[4][2]; reg28=reg56+reg28; reg67=reg63+reg67; reg56=pos_nodes[10][1]*reg68;
    reg63=reg9*pos_nodes[7][0]; reg70=reg11*pos_nodes[5][1]; T reg74=pos_nodes[10][0]*reg68; reg30=reg66+reg30; reg43=reg72+reg43;
    reg66=pos_nodes[9][2]*reg73; reg58=reg41+reg58; reg41=pos_nodes[10][2]*reg68; reg52=reg46+reg52; reg46=reg9*pos_nodes[7][1];
    reg32=reg54+reg32; reg54=reg65*pos_nodes[6][2]; reg36=reg13+reg36; reg13=pos_nodes[8][1]*reg9; reg46=reg32+reg46;
    reg32=pos_nodes[10][2]*reg73; reg72=reg9*pos_nodes[7][2]; T reg75=reg11*pos_nodes[5][2]; reg69=reg69*reg1; reg54=reg52+reg54;
    reg56=reg67+reg56; reg52=pos_nodes[11][1]*reg26; reg67=pos_nodes[11][2]*reg26; reg51=reg44+reg51; reg44=pos_nodes[11][0]*reg26;
    reg2=reg1*reg2; reg74=reg30+reg74; reg63=reg28+reg63; reg28=pos_nodes[8][0]*reg9; reg43=reg70+reg43;
    reg30=reg17*pos_nodes[6][1]; reg41=reg36+reg41; reg36=reg0*reg10; reg70=pos_nodes[10][0]*reg73; reg53=reg71-reg53;
    reg71=reg55*reg31; reg60=reg59+reg60; reg59=pos_nodes[10][1]*reg73; T reg76=reg17*pos_nodes[6][0]; reg50=reg61-reg50;
    reg66=reg58-reg66; reg51=reg75+reg51; reg70=reg53+reg70; reg53=pos_nodes[11][0]*reg2; reg58=reg71*pos_nodes[7][1];
    reg61=pos_nodes[9][0]*reg69; reg75=pos_nodes[12][2]*reg36; reg72=reg54+reg72; reg54=var_inter[0]*reg10; reg28=reg63-reg28;
    reg67=reg41+reg67; reg30=reg43+reg30; reg13=reg46-reg13; reg41=pos_nodes[9][1]*reg69; reg31=reg64*reg31;
    reg43=reg71*pos_nodes[7][0]; reg46=reg17*pos_nodes[6][2]; reg32=reg66+reg32; reg63=pos_nodes[11][1]*reg2; reg59=reg50+reg59;
    reg50=reg1*reg6; reg66=pos_nodes[11][2]*reg2; reg76=reg60+reg76; reg60=pos_nodes[12][0]*reg36; reg44=reg74+reg44;
    reg74=pos_nodes[8][2]*reg9; reg52=reg56+reg52; reg56=pos_nodes[12][1]*reg36; reg61=reg28+reg61; reg28=pos_nodes[10][0]*reg50;
    T reg77=reg21*pos_nodes[12][2]; T reg78=reg21*pos_nodes[12][0]; T reg79=pos_nodes[9][2]*reg69; reg74=reg72-reg74; reg29=reg29*reg1;
    reg46=reg51+reg46; reg51=reg71*pos_nodes[7][2]; reg60=reg44-reg60; reg44=pos_nodes[13][0]*reg54; reg72=pos_nodes[13][2]*reg54;
    reg43=reg76+reg43; reg76=reg31*pos_nodes[8][0]; reg75=reg67-reg75; reg41=reg13+reg41; reg13=pos_nodes[10][1]*reg50;
    reg67=reg21*pos_nodes[12][1]; T reg80=var_inter[1]*reg10; reg53=reg70+reg53; reg63=reg59+reg63; reg56=reg52-reg56;
    reg52=pos_nodes[13][1]*reg54; reg66=reg32+reg66; reg58=reg30+reg58; reg30=reg31*pos_nodes[8][1]; reg51=reg46+reg51;
    reg66=reg66-reg77; reg72=reg75-reg72; reg32=reg31*pos_nodes[8][2]; reg46=pos_nodes[14][2]*reg80; reg59=reg21*pos_nodes[14][2];
    reg70=pos_nodes[9][1]*reg29; reg63=reg63-reg67; reg28=reg61+reg28; reg61=reg21*pos_nodes[14][0]; reg53=reg53-reg78;
    reg55=reg55*reg1; reg30=reg58+reg30; reg58=pos_nodes[11][0]*reg50; reg75=pos_nodes[11][1]*reg50; reg13=reg41+reg13;
    reg44=reg60-reg44; reg41=pos_nodes[14][0]*reg80; reg79=reg74+reg79; reg60=pos_nodes[10][2]*reg50; reg74=reg21*pos_nodes[14][1];
    reg76=reg43+reg76; reg43=pos_nodes[9][0]*reg29; T reg81=pos_nodes[14][1]*reg80; reg52=reg56-reg52; reg74=reg63+reg74;
    reg53=reg61+reg53; reg75=reg13-reg75; reg46=reg72-reg46; reg41=reg44-reg41; reg43=reg76+reg43;
    reg13=pos_nodes[10][0]*reg55; reg44=pos_nodes[11][2]*reg50; reg60=reg79+reg60; reg56=pos_nodes[9][2]*reg29; reg32=reg51+reg32;
    reg58=reg28-reg58; reg1=reg64*reg1; reg28=pos_nodes[10][1]*reg55; reg70=reg30+reg70; reg81=reg52-reg81;
    reg66=reg59+reg66; reg30=reg21*pos_nodes[13][0]; reg0=reg0*reg21; reg56=reg32+reg56; reg32=pos_nodes[10][2]*reg55;
    reg51=reg74*reg46; reg52=reg81*reg66; reg59=reg53*reg46; reg61=reg41*reg66; reg78=reg58-reg78;
    reg44=reg60-reg44; reg58=pos_nodes[11][1]*reg1; reg28=reg70+reg28; reg60=reg21*pos_nodes[13][1]; reg67=reg75-reg67;
    reg13=reg43+reg13; reg43=pos_nodes[11][0]*reg1; reg32=reg56+reg32; reg56=pos_nodes[11][2]*reg1; reg58=reg28+reg58;
    reg43=reg13+reg43; reg13=pos_nodes[12][1]*reg0; reg60=reg67+reg60; reg28=reg21*var_inter[0]; reg63=pos_nodes[12][0]*reg0;
    reg30=reg78+reg30; reg52=reg51-reg52; reg64=reg53*reg81; reg67=reg21*pos_nodes[13][2]; reg77=reg44-reg77;
    reg61=reg59-reg61; reg44=reg41*reg74; reg67=reg77+reg67; reg70=reg30*reg52; reg56=reg32+reg56;
    reg32=reg60*reg61; reg44=reg64-reg44; reg72=pos_nodes[12][2]*reg0; reg75=pos_nodes[13][1]*reg28; reg58=reg13+reg58;
    reg43=reg63+reg43; reg13=pos_nodes[13][0]*reg28; reg63=reg21*var_inter[1]; reg70=reg32-reg70; reg13=reg43+reg13;
    reg32=reg67*reg44; reg43=reg60*reg46; reg76=reg81*reg67; reg77=reg60*reg66; reg78=reg74*reg67;
    reg79=reg30*reg46; T reg82=reg41*reg67; T reg83=reg30*reg66; T reg84=reg53*reg67; T reg85=pos_nodes[14][0]*reg63;
    reg75=reg58+reg75; reg58=pos_nodes[14][1]*reg63; reg56=reg72+reg56; reg72=pos_nodes[13][2]*reg28; T reg86=reg53*reg60;
    T reg87=reg30*reg74; T reg88=reg41*reg60; T reg89=reg30*reg81; reg84=reg83-reg84; reg58=reg75+reg58;
    reg82=reg79-reg82; reg78=reg77-reg78; reg72=reg56+reg72; reg13=reg85+reg13; reg56=pos_nodes[14][2]*reg63;
    reg32=reg70-reg32; reg76=reg43-reg76; reg86=reg87-reg86; reg78=reg78/reg32; reg88=reg89-reg88;
    reg13=pos[0]-reg13; reg72=reg56+reg72; reg84=reg84/reg32; reg52=reg52/reg32; reg61=reg61/reg32;
    reg58=pos[1]-reg58; reg82=reg82/reg32; reg76=reg76/reg32; reg84=reg58*reg84; reg78=reg13*reg78;
    reg82=reg58*reg82; reg76=reg13*reg76; reg61=reg58*reg61; reg52=reg13*reg52; reg86=reg86/reg32;
    reg88=reg88/reg32; reg32=reg44/reg32; reg72=pos[2]-reg72; reg32=reg72*reg32; reg52=reg61-reg52;
    reg88=reg72*reg88; reg82=reg76-reg82; reg86=reg72*reg86; reg78=reg84-reg78; var_inter[0]+=reg52-reg32;
    var_inter[1]+=reg88+reg82; var_inter[2]+=reg78-reg86;

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
    reg11=reg9*reg11; reg1=1+reg1; reg13=reg13-reg6; reg14=val[1]*reg14; reg15=reg15-reg11;
    reg5=reg5*reg1; reg13=val[0]*reg13; reg6=reg5-reg6; reg15=val[2]*reg15; reg7=reg7*reg1;
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
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[1]; T reg1=2*var_inter[0]; T reg2=var_inter[2]-0.14644660940672626914; T reg3=1-var_inter[2]; T reg4=reg1+reg0;
    reg2=reg2/0.70710678118654746172; T reg5=1-reg1; reg4=reg4-1; reg2=1-reg2; reg3=reg3-0.14644660940672626914;
    T reg6=1-reg0; T reg7=reg2*reg5; T reg8=reg4*reg2; reg3=reg3/0.70710678118654746172; reg8=val[0]*reg8;
    reg3=1-reg3; reg7=val[1]*reg7; reg2=reg2*reg6; T reg9=reg4*reg3; reg2=val[2]*reg2;
    reg7=reg8+reg7; reg2=reg7+reg2; reg9=val[3]*reg9; reg7=reg5*reg3; reg7=val[4]*reg7;
    reg9=reg2+reg9; reg3=reg6*reg3; reg9=reg7+reg9; reg3=val[5]*reg3; res=reg9+reg3;

}
#ifndef STRUCT_Gauss_2
#define STRUCT_Gauss_2
struct Gauss_2 {};
#endif // STRUCT_Gauss_2
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Gauss_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[1]; T reg1=2*var_inter[0]; T reg2=var_inter[2]-0.14644660940672626914; T reg3=1-var_inter[2]; T reg4=reg1+reg0;
    reg2=reg2/0.70710678118654746172; T reg5=1-reg1; reg4=reg4-1; reg2=1-reg2; reg3=reg3-0.14644660940672626914;
    T reg6=1-reg0; T reg7=reg2*reg5; T reg8=reg4*reg2; reg3=reg3/0.70710678118654746172; reg8=val[0]*reg8;
    reg3=1-reg3; reg7=val[1]*reg7; reg2=reg2*reg6; T reg9=reg4*reg3; reg2=val[2]*reg2;
    reg7=reg8+reg7; reg2=reg7+reg2; reg9=val[3]*reg9; reg7=reg5*reg3; reg7=val[4]*reg7;
    reg9=reg2+reg9; reg3=reg6*reg3; reg9=reg7+reg9; reg3=val[5]*reg3; res=reg9+reg3;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*reg0; T reg2=2*var_inter[2]; T reg3=2*var_inter[0];
    T reg4=reg1-1; T reg5=0.5*reg0; reg2=reg2-1; T reg6=0.5*var_inter[0]; T reg7=reg3-1;
    T reg8=2*var_inter[1]; T reg9=0.5*var_inter[1]; T reg10=reg6*reg7; T reg11=reg8-1; T reg12=reg5*reg4;
    T reg13=4*reg2; T reg14=2*reg12; T reg15=2*reg10; T reg16=reg13*reg6; T reg17=reg5*reg13;
    T reg18=reg9*reg11; T reg19=reg16-reg15; reg7=0.5*reg7; T reg20=reg17-reg14; T reg21=2*reg18;
    T reg22=reg13*reg9; reg11=0.5*reg11; reg4=0.5*reg4; T reg23=pow(reg2,2); reg7=var_inter[0]+reg7;
    T reg24=elem.pos(0)[1]*reg20; T reg25=elem.pos(1)[1]*reg19; T reg26=elem.pos(0)[2]*reg20; reg11=var_inter[1]+reg11; reg4=reg0+reg4;
    T reg27=elem.pos(1)[2]*reg19; T reg28=1-reg2; reg23=1-reg23; T reg29=reg22-reg21; T reg30=reg28*reg11;
    reg24=reg25+reg24; reg25=reg28*reg7; T reg31=0.5*reg23; T reg32=elem.pos(2)[2]*reg29; T reg33=reg28*reg4;
    T reg34=reg14+reg17; reg26=reg27+reg26; reg27=elem.pos(2)[1]*reg29; reg2=1+reg2; T reg35=reg34*elem.pos(3)[2];
    T reg36=reg34*elem.pos(3)[1]; reg24=reg27+reg24; reg27=reg4*reg2; T reg37=reg15+reg16; T reg38=reg31-reg33;
    reg26=reg32+reg26; reg30=reg30-reg31; reg25=reg25-reg31; reg7=reg2*reg7; reg32=elem.pos(2)[1]*reg30;
    reg36=reg24+reg36; reg24=elem.pos(2)[2]*reg30; T reg39=reg21+reg22; T reg40=elem.pos(4)[1]*reg37; reg20=elem.pos(0)[0]*reg20;
    T reg41=elem.pos(0)[2]*reg38; T reg42=elem.pos(1)[2]*reg25; T reg43=var_inter[0]*reg1; reg19=elem.pos(1)[0]*reg19; reg11=reg11*reg2;
    T reg44=elem.pos(1)[1]*reg25; T reg45=elem.pos(0)[1]*reg38; T reg46=elem.pos(4)[2]*reg37; reg35=reg26+reg35; reg26=reg31-reg27;
    reg42=reg42+reg41; T reg47=reg26*elem.pos(3)[2]; T reg48=var_inter[1]*reg3; reg32=reg32+reg45; T reg49=elem.pos(5)[1]*reg39;
    reg7=reg7-reg31; T reg50=reg1-reg3; reg24=reg41+reg24; reg41=2*reg43; reg29=elem.pos(2)[0]*reg29;
    reg11=reg11-reg31; reg46=reg35+reg46; reg35=elem.pos(5)[2]*reg39; reg40=reg36+reg40; reg20=reg19+reg20;
    reg45=reg44+reg45; reg19=reg26*elem.pos(3)[1]; reg38=reg38*elem.pos(0)[0]; reg36=elem.pos(5)[2]*reg11; reg32=reg32+reg19;
    reg24=reg47+reg24; reg44=elem.pos(5)[1]*reg11; reg34=reg34*elem.pos(3)[0]; T reg51=reg28*reg3; reg25=elem.pos(1)[0]*reg25;
    T reg52=reg28*reg50; reg30=elem.pos(2)[0]*reg30; reg19=reg45+reg19; reg45=2*reg48; T reg53=reg0*reg8;
    T reg54=elem.pos(4)[2]*reg7; T reg55=reg41*elem.pos(6)[2]; T reg56=elem.pos(4)[1]*reg7; T reg57=reg41*elem.pos(6)[1]; reg35=reg46+reg35;
    reg40=reg49+reg40; reg47=reg42+reg47; reg29=reg20+reg29; reg47=reg54+reg47; reg25=reg38+reg25;
    reg1=reg1-reg8; reg37=elem.pos(4)[0]*reg37; reg40=reg40-reg57; reg20=elem.pos(7)[1]*reg45; reg56=reg19+reg56;
    reg30=reg38+reg30; reg19=elem.pos(6)[2]*reg52; reg38=elem.pos(6)[1]*reg52; reg42=reg51*elem.pos(6)[1]; reg36=reg24+reg36;
    reg24=reg51*elem.pos(6)[2]; reg46=2*reg53; reg34=reg29+reg34; reg26=reg26*elem.pos(3)[0]; reg29=reg28*reg8;
    reg44=reg32+reg44; reg32=reg45*elem.pos(7)[2]; reg35=reg35-reg55; reg7=elem.pos(4)[0]*reg7; reg39=elem.pos(5)[0]*reg39;
    reg44=reg44-reg42; reg49=elem.pos(7)[1]*reg51; reg54=reg29*elem.pos(7)[2]; reg19=reg47+reg19; reg36=reg36-reg24;
    reg25=reg26+reg25; reg47=elem.pos(7)[1]*reg29; T reg58=reg51*elem.pos(7)[2]; reg40=reg40-reg20; T reg59=reg46*elem.pos(8)[1];
    reg38=reg56+reg38; reg56=reg46*elem.pos(8)[2]; reg35=reg35-reg32; reg30=reg26+reg30; reg37=reg34+reg37;
    reg26=reg28*reg1; reg11=elem.pos(5)[0]*reg11; reg35=reg35-reg56; reg34=reg3*reg2; T reg60=reg29*elem.pos(8)[2];
    reg11=reg30+reg11; reg52=elem.pos(6)[0]*reg52; reg7=reg25+reg7; reg25=reg41*elem.pos(9)[2]; reg37=reg39+reg37;
    reg40=reg40-reg59; reg30=reg41*elem.pos(9)[1]; reg39=reg41*elem.pos(6)[0]; reg49=reg44+reg49; reg44=reg26*elem.pos(8)[1];
    reg19=reg54+reg19; reg54=reg29*elem.pos(8)[1]; T reg61=reg51*elem.pos(6)[0]; T reg62=reg26*elem.pos(8)[2]; reg58=reg36+reg58;
    reg50=reg50*reg2; reg38=reg47+reg38; reg36=reg51*elem.pos(7)[0]; reg37=reg37-reg39; reg40=reg30+reg40;
    reg30=reg50*elem.pos(9)[2]; reg19=reg19-reg60; reg11=reg11-reg61; reg62=reg58+reg62; reg47=reg45*elem.pos(10)[1];
    reg58=reg34*elem.pos(9)[1]; T reg63=reg8*reg2; reg38=reg38-reg54; T reg64=reg45*elem.pos(7)[0]; reg25=reg35+reg25;
    reg35=reg34*elem.pos(9)[2]; reg52=reg7+reg52; reg44=reg49+reg44; reg7=reg29*elem.pos(7)[0]; reg49=reg50*elem.pos(9)[1];
    T reg65=reg45*elem.pos(10)[2]; T reg66=elem.pos(10)[2]*reg63; reg47=reg40+reg47; reg40=reg46*elem.pos(11)[1]; reg26=reg26*elem.pos(8)[0];
    T reg67=reg34*elem.pos(10)[2]; T reg68=reg29*elem.pos(8)[0]; T reg69=reg46*elem.pos(11)[2]; reg36=reg11+reg36; reg11=elem.pos(10)[1]*reg63;
    reg49=reg38+reg49; reg62=reg62-reg35; reg38=reg34*elem.pos(10)[1]; reg44=reg44-reg58; T reg70=reg0*reg13;
    reg52=reg7+reg52; reg65=reg25+reg65; reg30=reg19+reg30; reg1=reg2*reg1; reg37=reg37-reg64;
    reg7=reg46*elem.pos(8)[0]; reg19=elem.pos(12)[2]*reg70; reg25=elem.pos(12)[1]*reg70; reg37=reg37-reg7; T reg71=reg34*elem.pos(9)[0];
    T reg72=reg1*elem.pos(11)[2]; reg67=reg62+reg67; reg62=reg41*elem.pos(9)[0]; reg52=reg52-reg68; T reg73=elem.pos(11)[1]*reg63;
    reg11=reg49+reg11; reg38=reg44+reg38; reg66=reg30+reg66; reg30=elem.pos(11)[2]*reg63; reg44=reg1*elem.pos(11)[1];
    reg50=reg50*elem.pos(9)[0]; reg65=reg69+reg65; reg26=reg36+reg26; reg36=var_inter[0]*reg13; reg40=reg47+reg40;
    reg44=reg38+reg44; reg38=elem.pos(10)[0]*reg63; reg37=reg62+reg37; reg26=reg26-reg71; reg47=elem.pos(12)[1]*reg23;
    reg49=elem.pos(13)[1]*reg36; reg40=reg40-reg25; reg62=reg34*elem.pos(10)[0]; reg66=reg66-reg30; reg65=reg65-reg19;
    reg69=elem.pos(12)[2]*reg23; T reg74=elem.pos(13)[2]*reg36; reg11=reg11-reg73; reg52=reg50+reg52; reg50=var_inter[1]*reg13;
    T reg75=reg45*elem.pos(10)[0]; reg72=reg67+reg72; reg67=elem.pos(13)[1]*reg23; reg11=reg11-reg47; T reg76=elem.pos(14)[2]*reg23;
    reg44=reg44-reg47; T reg77=elem.pos(13)[2]*reg23; T reg78=elem.pos(14)[1]*reg23; reg66=reg66-reg69; reg52=reg38+reg52;
    reg38=elem.pos(11)[0]*reg63; reg1=reg1*elem.pos(11)[0]; reg62=reg26+reg62; reg72=reg72-reg69; reg26=reg46*elem.pos(11)[0];
    reg37=reg75+reg37; reg75=elem.pos(14)[2]*reg50; reg65=reg65-reg74; reg40=reg40-reg49; T reg79=elem.pos(14)[1]*reg50;
    reg37=reg26+reg37; reg67=reg11+reg67; reg78=reg44+reg78; reg11=elem.pos(12)[0]*reg23; reg52=reg52-reg38;
    reg40=reg40-reg79; reg66=reg77+reg66; reg65=reg65-reg75; reg26=elem.pos(12)[0]*reg70; reg72=reg76+reg72;
    reg1=reg62+reg1; reg52=reg52-reg11; reg44=elem.pos(13)[0]*reg23; reg1=reg1-reg11; reg62=reg40*reg72;
    reg76=elem.pos(13)[0]*reg36; reg77=elem.pos(14)[0]*reg23; T reg80=reg78*reg65; T reg81=reg66*reg40; T reg82=reg65*reg67;
    reg37=reg37-reg26; reg62=reg80-reg62; reg1=reg77+reg1; reg77=reg78*reg66; reg80=reg67*reg72;
    T reg83=elem.pos(14)[0]*reg50; reg81=reg82-reg81; reg44=reg52+reg44; reg37=reg37-reg76; reg77=reg80-reg77;
    reg52=reg81*reg1; reg37=reg37-reg83; reg80=reg62*reg44; reg52=reg80-reg52; reg80=reg77*reg37;
    reg80=reg52+reg80; return reg80;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Wedge_15,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.27378906834863934872*elem.pos(1)[1]; T reg1=0.27378906834863943131*elem.pos(0)[1]; T reg2=0.81282032302755082053*elem.pos(0)[2]; T reg3=0.27378906834863943131*elem.pos(0)[2]; T reg4=0.27378906834863934872*elem.pos(1)[2];
    T reg5=0.11094010767585030302*elem.pos(1)[1]; T reg6=0.11094010767585030302*elem.pos(1)[2]; T reg7=0.81282032302755082053*elem.pos(0)[1]; T reg8=0.11094010767585030302*elem.pos(0)[1]; T reg9=0.27378906834863934872*elem.pos(2)[1];
    T reg10=reg0+reg1; T reg11=reg5+reg7; T reg12=0.11094010767585030302*elem.pos(2)[1]; T reg13=0.11094010767585030302*elem.pos(0)[2]; T reg14=0.11094010767585030302*elem.pos(2)[2];
    T reg15=reg6+reg2; T reg16=0.27378906834863934872*elem.pos(2)[2]; T reg17=reg4+reg3; T reg18=reg15+reg14; T reg19=0.57282032302755088275*elem.pos(3)[1];
    T reg20=0.57282032302755088275*elem.pos(3)[2]; T reg21=0.49601129057086162889*elem.pos(3)[2]; T reg22=reg17+reg16; T reg23=0.81282032302755082053*elem.pos(1)[1]; T reg24=0.81282032302755082053*elem.pos(1)[2];
    T reg25=0.49601129057086162889*elem.pos(3)[1]; T reg26=reg10+reg9; T reg27=0.81282032302755082053*elem.pos(2)[1]; T reg28=reg5+reg8; T reg29=0.81282032302755082053*elem.pos(2)[2];
    T reg30=reg6+reg13; T reg31=reg11+reg12; T reg32=0.49601129057086158327*elem.pos(1)[1]; T reg33=0.49601129057086162889*elem.pos(0)[1]; T reg34=0.070441621801729122516*elem.pos(1)[2];
    T reg35=0.81282032302755082053*elem.pos(0)[0]; T reg36=0.11094010767585030302*elem.pos(1)[0]; T reg37=0.49106836025229589073*elem.pos(1)[2]; T reg38=0.49106836025229589073*elem.pos(1)[1]; T reg39=0.27378906834863934872*elem.pos(1)[0];
    T reg40=0.27378906834863943131*elem.pos(0)[0]; T reg41=0.35094010767585030747*elem.pos(4)[1]; T reg42=reg19+reg31; T reg43=0.77081185509940458903*elem.pos(0)[2]; T reg44=0.49106836025229589073*elem.pos(2)[2];
    T reg45=0.07044162180172894739*elem.pos(0)[2]; T reg46=0.070441621801729122516*elem.pos(2)[2]; T reg47=reg13+reg24; T reg48=reg8+reg23; T reg49=reg25+reg26;
    T reg50=0.49601129057086158327*elem.pos(4)[1]; T reg51=0.49601129057086158327*elem.pos(4)[2]; T reg52=reg21+reg22; T reg53=0.07044162180172894739*elem.pos(0)[1]; T reg54=0.070441621801729122516*elem.pos(2)[1];
    T reg55=reg28+reg27; T reg56=0.35094010767585030747*elem.pos(3)[1]; T reg57=reg30+reg29; T reg58=0.49601129057086158327*elem.pos(1)[2]; T reg59=0.49601129057086162889*elem.pos(0)[2];
    T reg60=0.35094010767585030747*elem.pos(3)[2]; T reg61=0.070441621801729122516*elem.pos(1)[1]; T reg62=0.49106836025229589073*elem.pos(2)[1]; T reg63=0.77081185509940458903*elem.pos(0)[1]; T reg64=reg20+reg18;
    T reg65=0.35094010767585030747*elem.pos(4)[2]; T reg66=0.77081185509940458903*elem.pos(2)[2]; T reg67=reg60+reg57; reg59=reg58+reg59; reg58=0.49601129057086158327*elem.pos(2)[2];
    T reg68=0.49106836025229589073*elem.pos(0)[1]; T reg69=0.77081185509940458903*elem.pos(2)[1]; T reg70=reg53-reg61; reg33=reg32+reg33; reg32=0.49601129057086158327*elem.pos(2)[1];
    T reg71=0.11094010767585030302*elem.pos(2)[0]; T reg72=reg36+reg35; T reg73=reg45-reg34; T reg74=reg43+reg37; T reg75=reg63+reg38;
    T reg76=reg39+reg40; T reg77=0.27378906834863934872*elem.pos(2)[0]; T reg78=0.35094010767585030747*elem.pos(5)[1]; T reg79=reg42+reg41; reg45=reg45-reg46;
    T reg80=0.26289171153160427653*elem.pos(3)[2]; T reg81=reg64+reg65; T reg82=reg62+reg63; T reg83=reg14+reg47; T reg84=0.35094010767585030747*elem.pos(5)[2];
    T reg85=reg12+reg48; T reg86=0.037478521766071383161*elem.pos(3)[1]; T reg87=0.11094010767585030302*elem.pos(0)[0]; T reg88=reg49+reg50; T reg89=0.49601129057086158327*elem.pos(5)[1];
    T reg90=0.49601129057086158327*elem.pos(5)[2]; T reg91=reg52+reg51; T reg92=0.26289171153160427653*elem.pos(3)[1]; reg53=reg53-reg54; T reg93=reg56+reg55;
    T reg94=0.49106836025229589073*elem.pos(0)[2]; T reg95=0.57282032302755088275*elem.pos(0)[1]; T reg96=0.35094010767585030747*elem.pos(1)[1]; T reg97=reg44+reg43; T reg98=0.037478521766071383161*elem.pos(3)[2];
    T reg99=0.57282032302755088275*elem.pos(0)[2]; T reg100=0.35094010767585030747*elem.pos(1)[2]; T reg101=0.77081185509940458903*elem.pos(1)[2]; reg32=reg33+reg32; reg33=0.77081185509940458903*elem.pos(1)[1];
    T reg102=0.16130768281804421985*elem.pos(1)[0]; T reg103=0.10535898384862248483*elem.pos(0)[0]; T reg104=0.35094010767585030747*elem.pos(0)[2]; T reg105=reg72+reg71; T reg106=0.57282032302755088275*elem.pos(3)[0];
    reg73=reg80+reg73; T reg107=0.26289171153160432348*elem.pos(4)[2]; T reg108=0.37559830641437077015*elem.pos(5)[1]; T reg109=0.19874168162164588299*elem.pos(0)[2]; T reg110=0.19874168162164587908*elem.pos(1)[2];
    T reg111=reg91+reg90; T reg112=0.37559830641437077015*elem.pos(4)[2]; T reg113=reg98-reg74; T reg114=0.4444444444444444691*elem.pos(6)[1]; T reg115=reg88+reg89;
    T reg116=reg86-reg82; T reg117=0.16130768281804421985*elem.pos(1)[1]; T reg118=0.10535898384862248483*elem.pos(0)[1]; T reg119=reg36+reg87; T reg120=0.37559830641437077015*elem.pos(4)[1];
    reg86=reg86-reg75; T reg121=0.35094010767585030747*elem.pos(2)[2]; T reg122=0.81282032302755082053*elem.pos(2)[0]; T reg123=reg41+reg93; T reg124=0.57282032302755088275*elem.pos(5)[1];
    T reg125=0.37559830641437077015*elem.pos(3)[2]; reg66=reg66+reg94; T reg126=0.19874168162164588299*elem.pos(0)[0]; T reg127=0.19874168162164587908*elem.pos(1)[0]; T reg128=reg81+reg84;
    T reg129=0.27378906834863943131*elem.pos(3)[2]; reg53=reg53+reg92; T reg130=0.57282032302755088275*elem.pos(5)[2]; T reg131=reg65+reg67; T reg132=0.26289171153160432348*elem.pos(5)[1];
    T reg133=0.070441621801729122516*elem.pos(2)[0]; reg98=reg98-reg97; reg58=reg59+reg58; reg59=0.07044162180172894739*elem.pos(0)[0]; T reg134=0.37559830641437077015*elem.pos(3)[1];
    reg69=reg69+reg68; T reg135=0.37559830641437077015*elem.pos(5)[2]; T reg136=0.19874168162164587908*elem.pos(1)[1]; T reg137=0.070441621801729122516*elem.pos(1)[0]; T reg138=0.35094010767585030747*elem.pos(0)[1];
    T reg139=0.19874168162164588299*elem.pos(0)[1]; T reg140=0.81282032302755082053*elem.pos(1)[0]; reg70=reg92+reg70; reg92=0.26289171153160432348*elem.pos(4)[1]; T reg141=0.27378906834863943131*elem.pos(3)[1];
    T reg142=0.57282032302755088275*elem.pos(4)[2]; T reg143=0.77081185509940458903*elem.pos(0)[0]; T reg144=0.49106836025229589073*elem.pos(1)[0]; reg95=reg96+reg95; T reg145=reg56+reg85;
    T reg146=reg60+reg83; T reg147=0.57282032302755088275*elem.pos(4)[1]; T reg148=reg76+reg77; reg99=reg100+reg99; T reg149=0.10535898384862248483*elem.pos(0)[2];
    T reg150=0.49601129057086162889*elem.pos(3)[0]; T reg151=0.49106836025229589073*elem.pos(2)[0]; T reg152=0.16130768281804421985*elem.pos(1)[2]; T reg153=0.26289171153160432348*elem.pos(5)[2]; reg80=reg45+reg80;
    reg45=0.48000000000000000888*elem.pos(6)[2]; T reg154=0.35094010767585030747*elem.pos(2)[1]; T reg155=0.4444444444444444691*elem.pos(6)[2]; T reg156=0.48000000000000000888*elem.pos(6)[1]; T reg157=reg79+reg78;
    T reg158=0.26289171153160432348*elem.pos(2)[2]; T reg159=reg152+reg149; T reg160=reg157+reg156; reg96=reg96+reg138; T reg161=0.57282032302755088275*elem.pos(2)[1];
    T reg162=0.26289171153160432348*elem.pos(2)[1]; T reg163=reg123+reg124; T reg164=0.49106836025229589073*elem.pos(0)[0]; reg98=reg98-reg135; T reg165=0.26289171153160427653*elem.pos(0)[2];
    T reg166=0.037478521766071383161*elem.pos(3)[0]; T reg167=0.57282032302755088275*elem.pos(1)[1]; T reg168=0.26289171153160427653*elem.pos(3)[0]; T reg169=reg136+reg139; T reg170=0.19874168162164587908*elem.pos(2)[1];
    T reg171=reg87+reg140; T reg172=reg144+reg143; T reg173=0.16130768281804421985*elem.pos(0)[0]; T reg174=0.63094010767585032744*elem.pos(6)[2]; T reg175=0.77081185509940458903*elem.pos(2)[0];
    reg70=reg70-reg92; T reg176=1.7512105867530111459e-16*elem.pos(6)[1]; reg116=reg116-reg108; T reg177=0.19874168162164587908*elem.pos(2)[0]; T reg178=reg127+reg126;
    T reg179=reg128+reg45; T reg180=0.63094010767585032744*elem.pos(6)[1]; reg80=reg80-reg153; T reg181=1.0515668461264170957*elem.pos(6)[2]; T reg182=0.16000000000000001776*elem.pos(6)[2];
    T reg183=reg131+reg130; T reg184=0.26289171153160427653*elem.pos(0)[1]; T reg185=0.16000000000000001776*elem.pos(6)[1]; reg53=reg53-reg132; T reg186=reg59-reg137;
    reg59=reg59-reg133; T reg187=0.16000000000000001776*elem.pos(7)[2]; T reg188=0.16000000000000001776*elem.pos(7)[1]; reg58=reg129+reg58; reg129=0.27378906834863934872*elem.pos(4)[2];
    T reg189=1.0515668461264170957*elem.pos(6)[1]; T reg190=0.037478521766071383161*elem.pos(5)[1]; reg69=reg69+reg134; T reg191=0.49601129057086158327*elem.pos(4)[0]; T reg192=reg150+reg148;
    reg66=reg66+reg125; T reg193=0.037478521766071383161*elem.pos(5)[2]; T reg194=0.16130768281804421985*elem.pos(2)[0]; T reg195=0.35094010767585030747*elem.pos(4)[0]; T reg196=0.35094010767585030747*elem.pos(3)[0];
    T reg197=reg106+reg105; reg100=reg100+reg104; T reg198=0.16130768281804421985*elem.pos(0)[1]; reg95=reg95+reg154; T reg199=0.26289171153160432348*elem.pos(1)[2];
    T reg200=reg145+reg147; reg73=reg73-reg107; T reg201=1.7512105867530111459e-16*elem.pos(6)[2]; T reg202=reg110+reg109; T reg203=0.44444444444444439511*elem.pos(7)[2];
    T reg204=0.57282032302755088275*elem.pos(1)[2]; T reg205=reg115+reg114; T reg206=reg143+reg151; T reg207=0.26289171153160432348*elem.pos(1)[1]; T reg208=0.44444444444444439511*elem.pos(7)[1];
    reg99=reg99+reg121; T reg209=0.57282032302755088275*elem.pos(2)[2]; T reg210=1.2618802153517004798*elem.pos(6)[2]; reg113=reg113-reg112; T reg211=0.81282032302755082053*elem.pos(3)[2];
    T reg212=0.16130768281804421985*elem.pos(2)[1]; T reg213=0.16130768281804421985*elem.pos(2)[2]; T reg214=reg119+reg122; reg101=reg94+reg101; T reg215=reg146+reg142;
    reg32=reg141+reg32; reg141=0.27378906834863934872*elem.pos(4)[1]; T reg216=0.49601129057086158327*elem.pos(1)[0]; T reg217=0.49601129057086162889*elem.pos(0)[0]; reg86=reg86-reg120;
    T reg218=1.2618802153517004798*elem.pos(6)[1]; T reg219=reg102+reg103; T reg220=0.19874168162164587908*elem.pos(2)[2]; T reg221=0.16130768281804421985*elem.pos(0)[2]; T reg222=reg111+reg155;
    T reg223=reg117+reg118; T reg224=0.81282032302755082053*elem.pos(3)[1]; reg33=reg68+reg33; T reg225=reg196+reg214; T reg226=reg222+reg203;
    reg116=reg116-reg180; T reg227=reg202+reg220; T reg228=0.037478521766071383161*elem.pos(0)[2]; T reg229=0.13459165171168747556*elem.pos(3)[2]; T reg230=0.48000000000000000888*elem.pos(7)[1];
    T reg231=0.77081185509940458903*elem.pos(1)[0]; T reg232=1.0515668461264170957*elem.pos(7)[1]; T reg233=0.37559830641437077015*elem.pos(2)[2]; T reg234=reg163+reg185; T reg235=0.4444444444444444691*elem.pos(8)[2];
    T reg236=0.037478521766071383161*elem.pos(4)[2]; T reg237=0.10535898384862248483*elem.pos(1)[0]; reg101=reg125+reg101; reg175=reg164+reg175; T reg238=reg84+reg215;
    T reg239=0.11094010767585030302*elem.pos(3)[2]; T reg240=0.037478521766071383161*elem.pos(4)[1]; T reg241=reg71+reg171; T reg242=0.11094010767585030302*elem.pos(3)[1]; reg33=reg134+reg33;
    T reg243=reg68-reg38; T reg244=0.17464101615137755461*elem.pos(3)[0]; T reg245=0.48000000000000000888*elem.pos(8)[2]; T reg246=0.4444444444444444691*elem.pos(8)[1]; T reg247=0.37559830641437077015*elem.pos(3)[0];
    reg189=reg53-reg189; reg53=reg205+reg208; T reg248=reg94-reg37; T reg249=reg219+reg194; T reg250=reg179+reg187;
    T reg251=reg78+reg200; T reg252=1.0515668461264170957*elem.pos(7)[2]; reg186=reg168+reg186; T reg253=0.26289171153160432348*elem.pos(4)[0]; reg209=reg100+reg209;
    reg181=reg80-reg181; reg161=reg96+reg161; reg80=0.11094010767585030302*elem.pos(4)[1]; reg86=reg86+reg218; reg96=reg165-reg199;
    reg100=0.17464101615137755461*elem.pos(3)[1]; reg113=reg113+reg210; T reg254=reg184-reg207; T reg255=0.63094010767585032744*elem.pos(7)[1]; reg201=reg73+reg201;
    reg99=reg211+reg99; reg73=0.11094010767585030302*elem.pos(4)[2]; reg211=reg197+reg195; T reg256=0.35094010767585030747*elem.pos(5)[0]; T reg257=reg117+reg198;
    T reg258=0.10535898384862248483*elem.pos(2)[1]; T reg259=reg169+reg170; T reg260=0.27378906834863934872*elem.pos(5)[1]; reg141=reg32+reg141; reg32=0.37559830641437077015*elem.pos(1)[2];
    reg176=reg70+reg176; reg98=reg98-reg174; reg70=reg102+reg173; T reg261=0.49601129057086158327*elem.pos(5)[0]; T reg262=reg160+reg188;
    T reg263=0.48000000000000000888*elem.pos(8)[1]; T reg264=0.57282032302755088275*elem.pos(0)[0]; T reg265=0.17464101615137755461*elem.pos(3)[2]; T reg266=0.037478521766071383161*elem.pos(0)[1]; T reg267=0.37559830641437077015*elem.pos(2)[1];
    T reg268=reg192+reg191; T reg269=reg166-reg172; T reg270=0.37559830641437077015*elem.pos(4)[0]; T reg271=reg159+reg213; T reg272=reg152+reg221;
    T reg273=0.10535898384862248483*elem.pos(2)[2]; reg95=reg224+reg95; reg166=reg166-reg206; reg224=0.37559830641437077015*elem.pos(5)[0]; T reg274=0.10535898384862248483*elem.pos(1)[2];
    T reg275=reg223+reg212; T reg276=0.49601129057086158327*elem.pos(2)[0]; reg217=reg216+reg217; reg204=reg104+reg204; reg104=0.13459165171168747556*elem.pos(3)[0];
    reg216=0.13459165171168747556*elem.pos(3)[1]; T reg277=0.27378906834863934872*elem.pos(5)[2]; T reg278=0.26289171153160432348*elem.pos(5)[0]; reg59=reg168+reg59; reg69=reg69-reg190;
    reg129=reg58+reg129; reg58=0.37559830641437077015*elem.pos(1)[1]; reg168=0.10535898384862248483*elem.pos(1)[1]; T reg279=reg183+reg182; T reg280=0.48000000000000000888*elem.pos(7)[2];
    T reg281=0.35094010767585030747*elem.pos(1)[0]; T reg282=reg178+reg177; T reg283=0.07044162180172894739*elem.pos(3)[1]; reg184=reg184-reg162; T reg284=0.63094010767585032744*elem.pos(7)[2];
    reg66=reg66-reg193; T reg285=0.07044162180172894739*elem.pos(3)[2]; reg167=reg138+reg167; reg165=reg165-reg158; reg138=0.10535898384862248483*elem.pos(2)[0];
    T reg286=reg45+reg238; reg94=reg94-reg44; T reg287=0.4444444444444444691*elem.pos(9)[2]; T reg288=reg226+reg235; T reg289=0.092025650515289130841*elem.pos(4)[2];
    T reg290=0.092025650515289130841*elem.pos(3)[2]; reg184=reg184+reg283; T reg291=reg272+reg273; T reg292=0.070441621801729122516*elem.pos(5)[1]; T reg293=0.092025650515289130841*elem.pos(4)[1];
    T reg294=reg156+reg251; reg209=reg239+reg209; reg101=reg101-reg236; reg165=reg165+reg285; T reg295=reg221+reg274;
    T reg296=0.13459165171168746096*elem.pos(1)[0]; T reg297=0.13459165171168747556*elem.pos(0)[0]; T reg298=0.37559830641437077015*elem.pos(0)[1]; T reg299=0.037478521766071383161*elem.pos(2)[1]; reg264=reg281+reg264;
    T reg300=0.35094010767585030747*elem.pos(2)[0]; T reg301=reg198+reg168; T reg302=0.77081185509940458903*elem.pos(3)[1]; T reg303=reg266-reg267; T reg304=0.13459165171168746096*elem.pos(4)[0];
    reg68=reg68-reg62; T reg305=0.092025650515289130841*elem.pos(4)[0]; T reg306=reg104+reg282; T reg307=0.13459165171168747556*elem.pos(0)[1]; T reg308=reg229+reg227;
    T reg309=0.070441621801729122516*elem.pos(5)[2]; T reg310=reg265+reg271; reg95=reg95+reg80; T reg311=reg257+reg258; T reg312=0.26289171153160432348*elem.pos(2)[0];
    reg260=reg141+reg260; reg141=0.13459165171168746096*elem.pos(4)[1]; T reg313=reg244+reg249; T reg314=0.57282032302755088275*elem.pos(4)[0]; reg189=reg232+reg189;
    T reg315=0.11094010767585030302*elem.pos(5)[1]; reg277=reg129+reg277; reg99=reg99+reg73; reg129=1.7512105867530111459e-16*elem.pos(8)[1]; T reg316=0.26289171153160427653*elem.pos(0)[0];
    T reg317=0.26289171153160432348*elem.pos(1)[0]; T reg318=reg216+reg259; T reg319=0.77081185509940458903*elem.pos(3)[2]; T reg320=reg100+reg275; T reg321=reg228-reg233;
    reg276=reg217+reg276; reg228=reg228-reg32; reg217=0.13459165171168746096*elem.pos(4)[2]; reg266=reg266-reg58; reg231=reg164+reg231;
    T reg322=0.27378906834863943131*elem.pos(3)[0]; T reg323=0.13459165171168746096*elem.pos(1)[2]; T reg324=0.11094010767585030302*elem.pos(5)[2]; T reg325=reg196+reg241; T reg326=0.13459165171168747556*elem.pos(0)[2];
    T reg327=0.070441621801729122516*elem.pos(4)[2]; reg96=reg285+reg96; reg285=0.092025650515289130841*elem.pos(3)[1]; T reg328=0.13459165171168746096*elem.pos(1)[1]; reg33=reg33-reg240;
    T reg329=0.070441621801729122516*elem.pos(4)[1]; reg254=reg283+reg254; reg283=0.48000000000000000888*elem.pos(6)[0]; T reg330=1.0515668461264170957*elem.pos(8)[1]; reg176=reg232+reg176;
    reg232=0.092025650515289130841*elem.pos(3)[0]; T reg331=reg70+reg138; reg167=reg154+reg167; reg154=1.0515668461264170957*elem.pos(6)[0]; reg59=reg59-reg278;
    reg180=reg69-reg180; reg69=0.35094010767585030747*elem.pos(0)[0]; T reg332=reg279+reg280; reg174=reg66-reg174; reg66=reg234+reg230;
    reg161=reg242+reg161; T reg333=1.7512105867530111459e-16*elem.pos(6)[0]; reg186=reg186-reg253; reg175=reg247+reg175; T reg334=0.037478521766071383161*elem.pos(5)[0];
    reg243=reg134+reg243; T reg335=0.4444444444444444691*elem.pos(9)[1]; T reg336=reg53+reg246; reg248=reg125+reg248; T reg337=reg195+reg225;
    T reg338=0.57282032302755088275*elem.pos(5)[0]; reg116=reg255+reg116; T reg339=1.2618802153517004798*elem.pos(8)[1]; T reg340=reg250+reg245; T reg341=0.48000000000000000888*elem.pos(9)[2];
    T reg342=0.4444444444444444691*elem.pos(6)[0]; reg98=reg284+reg98; T reg343=1.2618802153517004798*elem.pos(8)[2]; T reg344=reg268+reg261; T reg345=reg262+reg263;
    T reg346=0.48000000000000000888*elem.pos(9)[1]; reg269=reg269-reg270; T reg347=1.2618802153517004798*elem.pos(6)[0]; reg166=reg166-reg224; T reg348=0.63094010767585032744*elem.pos(6)[0];
    reg204=reg121+reg204; reg86=reg255+reg86; reg121=0.63094010767585032744*elem.pos(8)[1]; T reg349=1.0515668461264170957*elem.pos(8)[2]; reg201=reg252+reg201;
    reg113=reg284+reg113; T reg350=0.63094010767585032744*elem.pos(8)[2]; T reg351=reg211+reg256; reg181=reg252+reg181; reg252=1.7512105867530111459e-16*elem.pos(8)[2];
    T reg352=reg173+reg237; T reg353=0.37559830641437077015*elem.pos(0)[2]; T reg354=0.037478521766071383161*elem.pos(2)[2]; T reg355=0.49106836025229589073*elem.pos(5)[1]; reg303=reg303-reg302;
    T reg356=0.81282032302755082053*elem.pos(5)[1]; T reg357=0.63094010767585032744*elem.pos(7)[0]; reg184=reg184-reg292; T reg358=0.28176648720691616366*elem.pos(6)[1]; reg269=reg269+reg347;
    T reg359=reg310+reg289; T reg360=0.092025650515289130841*elem.pos(5)[2]; T reg361=0.092025650515289130841*elem.pos(5)[1]; T reg362=0.16000000000000001776*elem.pos(9)[2]; T reg363=reg245+reg332;
    reg94=reg125+reg94; reg125=0.81282032302755082053*elem.pos(4)[1]; reg167=reg242+reg167; reg242=0.17464101615137755461*elem.pos(0)[0]; T reg364=0.092025650515289130841*elem.pos(1)[0];
    reg180=reg255+reg180; T reg365=reg290+reg291; T reg366=reg308+reg217; T reg367=0.13459165171168746096*elem.pos(5)[2]; T reg368=0.16000000000000001776*elem.pos(9)[1];
    T reg369=reg263+reg66; reg99=reg99+reg324; reg98=reg98+reg343; reg333=reg186+reg333; reg186=0.16905989232414971697*elem.pos(9)[2];
    T reg370=reg296+reg297; T reg371=0.13459165171168746096*elem.pos(2)[0]; T reg372=0.037478521766071383161*elem.pos(1)[2]; T reg373=0.81282032302755082053*elem.pos(3)[0]; T reg374=0.49106836025229589073*elem.pos(3)[1];
    T reg375=reg298-reg299; T reg376=reg346-reg345; reg161=reg80+reg161; reg80=0.16000000000000001776*elem.pos(10)[1]; reg264=reg264+reg300;
    T reg377=0.13459165171168746096*elem.pos(5)[0]; T reg378=reg306+reg304; reg174=reg284+reg174; reg204=reg239+reg204; reg349=reg201-reg349;
    reg201=0.092025650515289130841*elem.pos(1)[2]; reg239=0.17464101615137755461*elem.pos(0)[2]; T reg379=4.6923546249730193496e-17*elem.pos(6)[1]; reg114=reg260-reg114; reg254=reg254-reg329;
    reg260=reg280+reg286; T reg380=0.16000000000000001776*elem.pos(8)[2]; T reg381=0.16000000000000001776*elem.pos(7)[0]; T reg382=reg351+reg283; T reg383=0.07044162180172894739*elem.pos(3)[0];
    T reg384=reg316-reg312; reg316=reg316-reg317; reg113=reg113-reg350; T reg385=0.13459165171168746096*elem.pos(5)[1]; T reg386=0.81282032302755082053*elem.pos(4)[2];
    T reg387=reg318+reg141; T reg388=0.33811978464829938699*elem.pos(9)[2]; reg155=reg277-reg155; reg277=reg320+reg293; reg154=reg59-reg154;
    reg59=reg194+reg352; T reg389=reg213+reg295; reg166=reg166-reg348; T reg390=0.27378906834863934872*elem.pos(4)[0]; reg276=reg322+reg276;
    reg165=reg165-reg309; reg322=0.28176648720691616366*elem.pos(6)[2]; T reg391=4.6923546249730193496e-17*elem.pos(9)[2]; reg252=reg181+reg252; reg181=reg323+reg326;
    T reg392=reg232+reg331; T reg393=0.13459165171168746096*elem.pos(2)[2]; T reg394=0.28176648720691616366*elem.pos(9)[2]; reg86=reg86-reg121; T reg395=0.33811978464829938699*elem.pos(9)[1];
    T reg396=4.6923546249730193496e-17*elem.pos(6)[2]; reg96=reg96-reg327; reg330=reg176-reg330; reg176=4.6923546249730193496e-17*elem.pos(9)[1]; T reg397=0.37559830641437077015*elem.pos(2)[0];
    reg228=reg228-reg319; T reg398=0.49106836025229589073*elem.pos(4)[2]; T reg399=0.092025650515289130841*elem.pos(1)[1]; reg243=reg243-reg120; T reg400=0.037478521766071383161*elem.pos(1)[1];
    T reg401=1.8928203230275508072*elem.pos(7)[1]; T reg402=reg335-reg336; T reg403=0.44444444444444439511*elem.pos(10)[1]; reg33=reg33-reg218; T reg404=0.17464101615137755461*elem.pos(0)[1];
    T reg405=0.037478521766071383161*elem.pos(0)[0]; T reg406=0.57282032302755088275*elem.pos(1)[0]; T reg407=0.37559830641437077015*elem.pos(1)[0]; T reg408=reg285+reg311; reg68=reg134+reg68;
    reg175=reg175-reg334; reg101=reg101-reg210; reg95=reg95+reg315; reg134=reg230+reg294; T reg409=0.16000000000000001776*elem.pos(8)[1];
    T reg410=reg212+reg301; T reg411=0.49106836025229589073*elem.pos(3)[2]; T reg412=0.49106836025229589073*elem.pos(4)[1]; reg266=reg266-reg302; reg116=reg116+reg339;
    T reg413=0.16000000000000001776*elem.pos(6)[0]; T reg414=reg337+reg338; T reg415=0.092025650515289130841*elem.pos(5)[0]; T reg416=reg313+reg305; reg231=reg247+reg231;
    T reg417=0.037478521766071383161*elem.pos(4)[0]; T reg418=0.16905989232414971697*elem.pos(9)[1]; T reg419=reg328+reg307; T reg420=0.13459165171168746096*elem.pos(2)[1]; reg248=reg248-reg112;
    T reg421=reg353-reg354; T reg422=1.8928203230275508072*elem.pos(7)[2]; reg129=reg189+reg129; reg189=0.28176648720691616366*elem.pos(9)[1]; T reg423=0.49106836025229589073*elem.pos(5)[2];
    reg321=reg321-reg319; T reg424=reg341-reg340; T reg425=reg164-reg144; T reg426=0.44444444444444439511*elem.pos(7)[0]; T reg427=0.16000000000000001776*elem.pos(10)[2];
    T reg428=reg287-reg288; reg281=reg281+reg69; T reg429=0.57282032302755088275*elem.pos(2)[0]; T reg430=reg344+reg342; T reg431=1.0515668461264170957*elem.pos(7)[0];
    T reg432=0.81282032302755082053*elem.pos(5)[2]; reg209=reg73+reg209; reg73=0.44444444444444439511*elem.pos(10)[2]; T reg433=reg325+reg314; T reg434=0.17464101615137755461*elem.pos(4)[1];
    T reg435=0.19874168162164588299*elem.pos(3)[1]; T reg436=reg293+reg408; T reg437=reg181+reg393; reg98=reg98-reg186; reg116=reg116-reg418;
    T reg438=0.16905989232414971697*elem.pos(10)[2]; reg86=reg86+reg395; T reg439=0.17464101615137755461*elem.pos(5)[1]; reg321=reg321-reg423; T reg440=0.16905989232414971697*elem.pos(6)[2];
    T reg441=reg419+reg420; reg396=reg96+reg396; reg96=0.33811978464829938699*elem.pos(6)[1]; reg266=reg266-reg412; T reg442=reg387+reg385;
    T reg443=0.35052228204213907079*elem.pos(6)[1]; T reg444=reg366+reg367; T reg445=0.35052228204213907079*elem.pos(6)[2]; T reg446=0.37856406460551018245*elem.pos(6)[1]; reg384=reg383+reg384;
    reg99=reg99-reg45; T reg447=reg298-reg400; T reg448=0.070441621801729122516*elem.pos(5)[0]; T reg449=0.092025650515289130841*elem.pos(0)[2]; T reg450=0.092025650515289130841*elem.pos(0)[0];
    T reg451=0.092025650515289130841*elem.pos(2)[2]; T reg452=reg260+reg380; reg394=reg252-reg394; reg252=reg430+reg426; reg379=reg254+reg379;
    reg254=reg201+reg239; T reg453=reg285+reg410; T reg454=0.33811978464829938699*elem.pos(6)[2]; T reg455=reg405-reg407; T reg456=0.16905989232414971697*elem.pos(6)[1];
    reg303=reg303-reg355; T reg457=reg364+reg242; reg68=reg68-reg108; T reg458=0.092025650515289130841*elem.pos(2)[0]; T reg459=0.77081185509940458903*elem.pos(3)[0];
    T reg460=reg277+reg361; T reg461=0.63094010767585032744*elem.pos(8)[0]; T reg462=0.11094010767585030302*elem.pos(4)[0]; T reg463=0.37856406460551018245*elem.pos(6)[2]; T reg464=reg359+reg360;
    T reg465=0.48000000000000000888*elem.pos(11)[1]; T reg466=0.037478521766071383161*elem.pos(2)[0]; reg269=reg357+reg269; T reg467=0.092025650515289130841*elem.pos(0)[1]; reg95=reg95-reg156;
    reg429=reg281+reg429; reg281=0.17464101615137755461*elem.pos(4)[0]; T reg468=0.4444444444444444691*elem.pos(8)[0]; T reg469=reg353-reg372; reg405=reg405-reg397;
    T reg470=0.16905989232414971697*elem.pos(10)[1]; T reg471=0.19874168162164588299*elem.pos(3)[2]; T reg472=0.48000000000000000888*elem.pos(11)[2]; reg391=reg349+reg391; reg424=reg424+reg427;
    reg349=1.2618802153517004798*elem.pos(8)[0]; reg376=reg376+reg80; reg390=reg276+reg390; reg276=0.27378906834863934872*elem.pos(5)[0]; reg166=reg357+reg166;
    T reg473=0.17464101615137755461*elem.pos(4)[2]; T reg474=reg290+reg389; reg264=reg373+reg264; reg373=1.8928203230275508072*elem.pos(6)[1]; T reg475=reg232+reg59;
    T reg476=reg399+reg404; T reg477=0.17464101615137755461*elem.pos(5)[2]; T reg478=reg289+reg365; T reg479=0.092025650515289130841*elem.pos(2)[1]; reg228=reg228-reg398;
    reg333=reg431+reg333; T reg480=reg370+reg371; T reg481=0.77081185509940458903*elem.pos(5)[1]; reg375=reg375+reg374; T reg482=1.0515668461264170957*elem.pos(8)[0];
    T reg483=0.35052228204213907079*elem.pos(6)[0]; T reg484=reg378+reg377; reg174=reg174-reg343; T reg485=0.28176648720691616366*elem.pos(7)[1]; T reg486=1.8928203230275508072*elem.pos(6)[2];
    reg356=reg161+reg356; reg358=reg184-reg358; reg125=reg167+reg125; reg161=0.48000000000000000888*elem.pos(10)[2]; reg167=reg362-reg363;
    reg94=reg94-reg135; reg180=reg180-reg339; reg184=0.28176648720691616366*elem.pos(10)[2]; reg428=reg428+reg73; T reg487=0.4444444444444444691*elem.pos(11)[2];
    reg203=reg155-reg203; reg154=reg431+reg154; reg155=1.7512105867530111459e-16*elem.pos(8)[0]; reg431=0.28176648720691616366*elem.pos(7)[2]; T reg488=0.17464101615137755461*elem.pos(5)[0];
    reg322=reg165-reg322; reg165=reg305+reg392; T reg489=reg416+reg415; T reg490=reg134+reg409; T reg491=0.37856406460551018245*elem.pos(6)[0];
    reg421=reg421+reg411; T reg492=0.48000000000000000888*elem.pos(7)[0]; T reg493=reg414+reg413; reg231=reg231-reg417; T reg494=0.77081185509940458903*elem.pos(5)[2];
    T reg495=1.8928203230275508072*elem.pos(8)[2]; reg248=reg422+reg248; reg164=reg164-reg151; T reg496=1.8928203230275508072*elem.pos(8)[1]; reg243=reg401+reg243;
    reg33=reg255+reg33; reg402=reg402+reg403; reg255=0.4444444444444444691*elem.pos(11)[1]; reg348=reg175-reg348; reg101=reg284+reg101;
    reg406=reg69+reg406; reg69=0.28176648720691616366*elem.pos(10)[1]; reg189=reg129-reg189; reg129=reg256+reg433; reg425=reg247+reg425;
    reg175=0.48000000000000000888*elem.pos(10)[1]; reg284=reg368-reg369; T reg497=0.11094010767585030302*elem.pos(3)[0]; T reg498=0.19874168162164588299*elem.pos(3)[0]; reg113=reg113+reg388;
    T reg499=0.070441621801729122516*elem.pos(4)[0]; reg316=reg383+reg316; reg383=reg382+reg381; T reg500=0.48000000000000000888*elem.pos(8)[0]; reg386=reg204+reg386;
    reg208=reg114-reg208; reg114=0.37559830641437077015*elem.pos(0)[0]; reg176=reg330+reg176; reg432=reg209+reg432; reg204=0.17464101615137755461*elem.pos(1)[1];
    reg209=0.7698003589195010602*elem.pos(12)[1]; reg394=reg394+reg184; reg330=reg471+reg437; T reg501=reg364+reg450; reg189=reg189+reg69;
    T reg502=4.6923546249730193496e-17*elem.pos(11)[2]; reg429=reg497+reg429; T reg503=0.4444444444444444691*elem.pos(9)[0]; T reg504=4.6923546249730193496e-17*elem.pos(11)[1]; T reg505=0.17464101615137755461*elem.pos(2)[0];
    reg350=reg101-reg350; reg188=reg95-reg188; reg95=reg252+reg468; reg101=0.33811978464829938699*elem.pos(11)[1]; T reg506=0.17464101615137755461*elem.pos(2)[1];
    T reg507=reg399+reg467; reg322=reg431+reg322; T reg508=reg201+reg449; reg348=reg357+reg348; reg486=reg94-reg486;
    reg94=0.1261880215351700725*elem.pos(7)[0]; T reg509=0.48000000000000000888*elem.pos(9)[0]; T reg510=reg383+reg500; reg447=reg374+reg447; reg373=reg68-reg373;
    reg284=reg284+reg175; reg68=0.16905989232414971697*elem.pos(7)[2]; T reg511=1.8928203230275508072*elem.pos(7)[0]; T reg512=reg254+reg451; reg425=reg425-reg270;
    reg406=reg300+reg406; reg300=reg283+reg129; reg321=reg321-reg440; T reg513=reg446-reg460; T reg514=1.3856406460551017033*elem.pos(12)[2];
    reg443=reg443-reg442; reg424=reg424+reg472; T reg515=0.35052228204213901243*elem.pos(7)[2]; reg125=reg315+reg125; reg315=reg341-reg452;
    T reg516=4.6923546249730193496e-17*elem.pos(8)[2]; reg495=reg248-reg495; reg248=0.50717967697244910395*elem.pos(10)[2]; reg494=reg421+reg494; reg421=reg436+reg439;
    T reg517=0.1261880215351700725*elem.pos(6)[1]; T reg518=reg453+reg434; reg231=reg231-reg347; reg316=reg316-reg499; T reg519=0.17464101615137755461*elem.pos(1)[2];
    T reg520=4.6923546249730193496e-17*elem.pos(6)[0]; T reg521=reg493+reg492; T reg522=0.16905989232414971697*elem.pos(11)[2]; T reg523=reg491-reg489; reg113=reg438+reg113;
    reg266=reg266+reg96; T reg524=reg346-reg490; T reg525=reg353-reg32; T reg526=0.037478521766071383161*elem.pos(1)[0]; reg402=reg402+reg255;
    T reg527=0.77081185509940458903*elem.pos(4)[2]; reg455=reg455-reg459; T reg528=0.49106836025229589073*elem.pos(4)[0]; reg228=reg228+reg454; reg469=reg411+reg469;
    T reg529=0.17464101615137755461*elem.pos(2)[2]; T reg530=reg476+reg479; reg121=reg33-reg121; reg33=0.28176648720691616366*elem.pos(6)[0]; reg384=reg384-reg448;
    T reg531=0.10535898384862248483*elem.pos(3)[1]; reg496=reg243-reg496; reg116=reg116+reg470; reg243=0.50717967697244910395*elem.pos(10)[1]; T reg532=0.19874168162164587908*elem.pos(4)[1];
    T reg533=reg435+reg441; reg405=reg405-reg459; T reg534=0.49106836025229589073*elem.pos(5)[0]; reg164=reg247+reg164; reg247=0.7698003589195010602*elem.pos(12)[2];
    T reg535=reg298-reg58; T reg536=4.6923546249730193496e-17*elem.pos(8)[1]; T reg537=reg478+reg477; T reg538=0.1261880215351700725*elem.pos(6)[2]; reg358=reg485+reg358;
    reg396=reg431+reg396; reg185=reg356-reg185; reg356=reg475+reg281; reg431=0.10535898384862248483*elem.pos(3)[2]; T reg539=4.6923546249730193496e-17*elem.pos(9)[0];
    T reg540=0.16905989232414971697*elem.pos(7)[1]; T reg541=reg114-reg466; T reg542=1.3856406460551017033*elem.pos(12)[1]; reg376=reg376+reg465; reg482=reg333-reg482;
    reg333=0.28176648720691616366*elem.pos(11)[1]; T reg543=0.10535898384862248483*elem.pos(3)[0]; T reg544=0.33811978464829938699*elem.pos(9)[0]; reg182=reg432-reg182; reg418=reg180-reg418;
    reg86=reg470+reg86; reg180=0.16905989232414971697*elem.pos(11)[1]; reg432=reg457+reg458; T reg545=0.17464101615137755461*elem.pos(1)[0]; T reg546=reg165+reg488;
    reg176=reg69+reg176; reg269=reg269-reg461; reg167=reg167+reg161; reg69=0.11094010767585030302*elem.pos(5)[0]; reg264=reg264+reg462;
    T reg547=0.1261880215351700725*elem.pos(7)[1]; T reg548=reg463-reg464; T reg549=0.16905989232414971697*elem.pos(9)[0]; T reg550=0.35052228204213901243*elem.pos(7)[1]; reg276=reg390+reg276;
    reg481=reg375+reg481; reg445=reg445-reg444; reg375=0.19874168162164587908*elem.pos(4)[0]; reg390=0.28176648720691616366*elem.pos(9)[0]; T reg551=0.33811978464829938699*elem.pos(11)[2];
    reg428=reg428+reg487; reg98=reg98+reg438; T reg552=reg498+reg480; reg386=reg324+reg386; reg391=reg184+reg391;
    reg246=reg208-reg246; reg184=0.77081185509940458903*elem.pos(4)[1]; reg208=0.19874168162164587908*elem.pos(4)[2]; reg187=reg99-reg187; reg235=reg203-reg235;
    reg99=0.49106836025229589073*elem.pos(3)[0]; reg186=reg174-reg186; reg303=reg303-reg456; reg174=0.28176648720691616366*elem.pos(8)[2]; reg166=reg166+reg349;
    reg483=reg483-reg484; reg203=0.35052228204213901243*elem.pos(7)[0]; reg324=0.1261880215351700725*elem.pos(7)[2]; T reg553=reg474+reg473; T reg554=0.28176648720691616366*elem.pos(8)[1];
    T reg555=0.1261880215351700725*elem.pos(6)[0]; reg379=reg485+reg379; reg485=0.28176648720691616366*elem.pos(11)[2]; reg155=reg154+reg155; reg182=reg182-reg280;
    reg154=reg450+reg545; reg298=reg298-reg267; reg517=reg517-reg421; reg353=reg353-reg233; reg525=reg411+reg525;
    T reg556=0.77081185509940458903*elem.pos(5)[0]; reg541=reg99+reg541; reg456=reg481-reg456; reg184=reg447+reg184; reg513=reg547+reg513;
    reg447=0.81282032302755082053*elem.pos(5)[0]; reg481=0.16130768281804421985*elem.pos(3)[0]; reg547=0.37856406460551018245*elem.pos(8)[1]; reg406=reg497+reg406; reg156=reg125-reg156;
    reg443=reg550+reg443; reg125=0.35052228204213907079*elem.pos(8)[1]; reg45=reg386-reg45; reg429=reg462+reg429; reg386=0.37856406460551018245*elem.pos(7)[1];
    reg462=0.16905989232414971697*elem.pos(8)[2]; reg228=reg68+reg228; reg497=0.81282032302755082053*elem.pos(4)[0]; reg527=reg469+reg527; reg185=reg185-reg230;
    reg264=reg264+reg69; reg469=reg501+reg505; reg535=reg374+reg535; reg550=reg114-reg526; reg440=reg494-reg440;
    reg524=reg175+reg524; reg494=0.50717967697244910395*elem.pos(9)[2]; reg486=reg422+reg486; reg428=reg428+reg247; reg422=0.16000000000000001776*elem.pos(11)[2];
    reg315=reg161+reg315; T reg557=0.76980035891950093199*elem.pos(13)[2]; T reg558=0.50717967697244910395*elem.pos(9)[1]; reg373=reg401+reg373; reg401=reg415+reg356;
    reg502=reg394+reg502; reg394=0.66666666666666670528*elem.pos(12)[2]; T reg559=0.16000000000000001776*elem.pos(9)[0]; T reg560=reg500+reg521; T reg561=0.50717967697244910395*elem.pos(11)[2];
    reg495=reg495+reg248; T reg562=0.50717967697244910395*elem.pos(11)[1]; reg496=reg496+reg243; reg287=reg235+reg287; reg235=1.0515668461264170957*elem.pos(9)[1];
    reg536=reg358+reg536; reg483=reg203+reg483; reg203=0.35052228204213907079*elem.pos(8)[0]; reg358=0.19874168162164587908*elem.pos(5)[0]; T reg563=reg552+reg375;
    T reg564=0.16000000000000001776*elem.pos(8)[0]; T reg565=reg492+reg300; reg350=reg350-reg388; reg504=reg189+reg504; reg189=0.66666666666666670528*elem.pos(12)[1];
    reg121=reg121-reg395; T reg566=1.8928203230275508072*elem.pos(6)[0]; reg164=reg164-reg224; reg231=reg357+reg231; reg357=0.16000000000000001776*elem.pos(11)[1];
    reg86=reg86-reg180; reg485=reg391-reg485; reg166=reg166-reg549; reg391=0.16905989232414971697*elem.pos(10)[0]; reg269=reg269+reg544;
    T reg567=0.46188021535170061048*elem.pos(13)[1]; reg376=reg376+reg542; reg98=reg98+reg551; T reg568=0.46188021535170061048*elem.pos(13)[2]; reg424=reg424+reg514;
    reg116=reg116+reg101; T reg569=reg503-reg95; T reg570=0.44444444444444439511*elem.pos(10)[0]; T reg571=0.37856406460551018245*elem.pos(8)[0]; reg523=reg94+reg523;
    reg94=0.37856406460551018245*elem.pos(7)[0]; reg348=reg348-reg349; reg402=reg402+reg209; T reg572=0.76980035891950093199*elem.pos(13)[1]; T reg573=1.8928203230275508072*elem.pos(8)[0];
    reg425=reg511+reg425; T reg574=0.46188021535170061048*elem.pos(12)[1]; reg284=reg465+reg284; reg186=reg438+reg186; reg539=reg482+reg539;
    reg482=0.28176648720691616366*elem.pos(10)[0]; T reg575=0.46188021535170061048*elem.pos(12)[2]; reg167=reg472+reg167; reg418=reg470+reg418; reg390=reg155-reg390;
    reg555=reg555-reg546; reg333=reg176-reg333; reg155=0.16000000000000001776*elem.pos(10)[0]; reg176=reg509-reg510; reg113=reg113-reg522;
    T reg576=0.19874168162164587908*elem.pos(5)[1]; T reg577=0.19874168162164587908*elem.pos(5)[2]; reg174=reg396-reg174; reg396=reg531+reg530; T reg578=0.33811978464829938699*elem.pos(6)[0];
    T reg579=1.7512105867530111459e-16*elem.pos(9)[2]; T reg580=reg330+reg208; reg342=reg276-reg342; reg276=reg360+reg553; reg455=reg455-reg528;
    T reg581=0.16130768281804421985*elem.pos(4)[1]; reg538=reg538-reg537; T reg582=reg543+reg432; T reg583=0.16130768281804421985*elem.pos(4)[0]; T reg584=0.37856406460551018245*elem.pos(8)[2];
    reg548=reg324+reg548; reg303=reg540+reg303; reg324=0.16130768281804421985*elem.pos(3)[1]; T reg585=reg507+reg506; T reg586=0.33811978464829938699*elem.pos(8)[1];
    T reg587=0.37856406460551018245*elem.pos(7)[2]; reg188=reg188-reg263; T reg588=0.35052228204213907079*elem.pos(8)[2]; reg445=reg515+reg445; reg187=reg187-reg245;
    reg321=reg68+reg321; reg515=0.33811978464829938699*elem.pos(8)[2]; T reg589=reg467+reg204; T reg590=0.16905989232414971697*elem.pos(8)[1]; T reg591=0.28176648720691616366*elem.pos(7)[0];
    reg520=reg316+reg520; reg266=reg540+reg266; reg316=reg449+reg519; reg335=reg246+reg335; reg246=1.0515668461264170957*elem.pos(9)[2];
    T reg592=reg508+reg529; reg33=reg384-reg33; reg384=reg361+reg518; T reg593=0.16130768281804421985*elem.pos(3)[2]; T reg594=reg533+reg532;
    reg405=reg405-reg534; T reg595=1.7512105867530111459e-16*elem.pos(9)[1]; reg554=reg379-reg554; reg379=reg431+reg512; T reg596=0.16130768281804421985*elem.pos(4)[2];
    T reg597=0.16905989232414971697*elem.pos(6)[0]; reg516=reg322+reg516; reg322=0.66666666666666670528*elem.pos(13)[1]; reg280=reg45-reg280; reg45=reg324+reg585;
    T reg598=0.10143593539448982642*elem.pos(9)[1]; T reg599=0.50717967697244910395*elem.pos(7)[2]; reg333=reg333-reg189; reg353=reg411+reg353; reg517=reg386+reg517;
    reg411=0.16130768281804421985*elem.pos(5)[1]; reg525=reg525-reg398; T reg600=reg396+reg581; reg485=reg485-reg394; reg298=reg374+reg298;
    reg374=0.66666666666666670528*elem.pos(13)[2]; T reg601=reg458+reg154; reg446=reg446-reg384; T reg602=0.4444444444444444691*elem.pos(11)[0]; reg569=reg569+reg570;
    reg447=reg429+reg447; reg429=0.093922162402305398307*elem.pos(6)[1]; T reg603=reg594+reg576; T reg604=0.76980035891950093199*elem.pos(14)[2]; reg184=reg184-reg96;
    reg428=reg428+reg557; T reg605=reg580+reg577; T reg606=0.093922162402305398307*elem.pos(6)[2]; T reg607=0.093922162402305398307*elem.pos(9)[1]; reg125=reg443+reg125;
    reg443=reg379+reg596; T reg608=0.16130768281804421985*elem.pos(5)[2]; T reg609=0.66666666666666670528*elem.pos(14)[1]; reg504=reg504-reg189; reg527=reg527-reg454;
    T reg610=reg593+reg592; T reg611=reg451+reg316; T reg612=0.093922162402305398307*elem.pos(9)[0]; reg203=reg483+reg203; reg497=reg406+reg497;
    reg406=4.6923546249730193496e-17*elem.pos(11)[0]; reg390=reg482+reg390; reg513=reg513+reg547; reg483=reg479+reg589; T reg613=0.28176648720691616366*elem.pos(11)[0];
    reg482=reg539+reg482; reg588=reg445+reg588; reg445=0.093922162402305398307*elem.pos(9)[2]; reg539=0.76980035891950093199*elem.pos(14)[1]; reg402=reg402+reg572;
    reg230=reg156-reg230; reg548=reg548+reg584; reg550=reg99+reg550; reg156=0.77081185509940458903*elem.pos(4)[0]; T reg614=0.10143593539448982642*elem.pos(9)[2];
    reg538=reg587+reg538; T reg615=0.66666666666666670528*elem.pos(14)[2]; reg502=reg502-reg394; reg463=reg463-reg276; reg561=reg495-reg561;
    reg33=reg591+reg33; reg562=reg496-reg562; reg495=4.6923546249730193496e-17*elem.pos(8)[0]; reg549=reg348-reg549; reg595=reg554+reg595;
    reg348=0.50717967697244910395*elem.pos(10)[0]; reg579=reg174+reg579; reg573=reg425-reg573; reg174=reg114-reg407; reg284=reg284+reg574;
    reg426=reg342-reg426; reg186=reg186-reg551; reg342=reg481+reg469; reg167=reg167+reg575; reg425=reg582+reg583;
    reg496=0.16130768281804421985*elem.pos(5)[0]; reg418=reg418-reg101; reg303=reg303+reg586; reg555=reg94+reg555; reg554=0.63094010767585032744*elem.pos(9)[1];
    reg187=reg341+reg187; reg264=reg264-reg283; T reg616=0.48000000000000000888*elem.pos(11)[0]; reg321=reg321+reg515; T reg617=reg565+reg564;
    reg350=reg438+reg350; reg121=reg470+reg121; reg438=reg563+reg358; reg245=reg182-reg245; reg566=reg164-reg566;
    reg164=0.093922162402305398307*elem.pos(6)[0]; reg461=reg231-reg461; reg235=reg536-reg235; reg182=1.0515668461264170957*elem.pos(10)[1]; reg524=reg524+reg357;
    reg494=reg486-reg494; reg73=reg287+reg73; reg440=reg68+reg440; reg246=reg516-reg246; reg315=reg315+reg422;
    reg456=reg540+reg456; reg231=1.0515668461264170957*elem.pos(10)[2]; reg558=reg373-reg558; reg403=reg335+reg403; reg491=reg491-reg401;
    reg520=reg591+reg520; reg263=reg185-reg263; reg185=0.28176648720691616366*elem.pos(8)[0]; reg287=0.48000000000000000888*elem.pos(10)[0]; reg335=reg559-reg560;
    reg373=0.33811978464829938699*elem.pos(11)[0]; reg166=reg391+reg166; reg188=reg346+reg188; reg556=reg541+reg556; reg470=0.16905989232414971697*elem.pos(11)[0];
    reg269=reg269+reg391; reg486=1.2618802153517004798*elem.pos(9)[2]; reg516=0.46188021535170061048*elem.pos(14)[1]; reg376=reg376+reg567; reg228=reg228-reg462;
    reg98=reg98-reg394; reg536=0.16905989232414971697*elem.pos(7)[0]; reg455=reg455+reg578; reg541=0.46188021535170061048*elem.pos(14)[2]; reg424=reg424+reg568;
    reg116=reg116-reg189; reg405=reg405-reg597; reg591=0.50717967697244910395*elem.pos(7)[1]; reg535=reg535-reg412; T reg618=1.2618802153517004798*elem.pos(9)[1];
    reg266=reg266-reg590; T reg619=0.10143593539448982642*elem.pos(9)[0]; reg523=reg523+reg571; reg113=reg113-reg394; T reg620=0.63094010767585032744*elem.pos(9)[2];
    reg176=reg176+reg155; reg86=reg86-reg189; reg405=reg536+reg405; reg487=reg73+reg487; reg73=0.093922162402305382675*elem.pos(10)[2];
    reg429=reg429-reg603; reg456=reg456-reg586; T reg621=0.033811978464829945269*elem.pos(9)[1]; reg517=reg547+reg517; reg547=0.16905989232414971697*elem.pos(8)[0];
    T reg622=0.63094010767585032744*elem.pos(10)[1]; reg246=reg246+reg231; reg497=reg69+reg497; reg69=1.7512105867530111459e-16*elem.pos(11)[2]; reg455=reg536+reg455;
    reg255=reg403+reg255; reg303=reg303-reg554; reg446=reg386+reg446; reg386=reg509-reg617; reg184=reg540+reg184;
    reg403=0.093922162402305382675*elem.pos(7)[0]; reg540=0.093922162402305382675*elem.pos(10)[0]; reg187=reg427+reg187; reg245=reg362+reg245; reg321=reg321-reg620;
    reg381=reg264-reg381; reg612=reg203+reg612; reg266=reg266+reg618; reg164=reg164-reg438; reg203=0.1261880215351700725*elem.pos(8)[1];
    reg527=reg68+reg527; reg68=0.093922162402305382675*elem.pos(7)[1]; reg264=0.33811978464829938699*elem.pos(8)[0]; reg362=0.63094010767585032744*elem.pos(10)[2]; reg235=reg235+reg182;
    reg427=1.7512105867530111459e-16*elem.pos(11)[1]; reg445=reg588+reg445; reg588=1.0515668461264170957*elem.pos(11)[1]; reg606=reg606-reg605; T reg623=reg600+reg411;
    reg538=reg584+reg538; reg584=0.10143593539448982642*elem.pos(6)[1]; reg579=reg231+reg579; reg188=reg80+reg188; reg80=1.0515668461264170957*elem.pos(11)[2];
    reg231=0.093922162402305382675*elem.pos(7)[2]; T reg624=0.1261880215351700725*elem.pos(8)[2]; T reg625=0.093922162402305382675*elem.pos(10)[1]; reg463=reg587+reg463; reg587=reg581+reg45;
    T reg626=0.10535898384862248483*elem.pos(5)[1]; T reg627=0.10535898384862248483*elem.pos(5)[0]; T reg628=reg583+reg342; reg607=reg125+reg607; reg125=0.033811978464829945269*elem.pos(9)[2];
    reg468=reg426-reg468; reg513=reg513+reg598; reg426=0.033811978464829945269*elem.pos(10)[1]; reg185=reg520-reg185; reg520=1.7512105867530111459e-16*elem.pos(9)[0];
    T reg629=0.10535898384862248483*elem.pos(4)[2]; T reg630=0.10143593539448982642*elem.pos(6)[0]; T reg631=reg425+reg496; T reg632=reg593+reg611; T reg633=0.10535898384862248483*elem.pos(5)[2];
    reg548=reg548+reg614; T reg634=reg596+reg610; T reg635=0.033811978464829945269*elem.pos(10)[2]; reg228=reg228+reg486; reg495=reg33+reg495;
    reg33=1.0515668461264170957*elem.pos(9)[0]; T reg636=0.10143593539448982642*elem.pos(6)[2]; T reg637=0.10535898384862248483*elem.pos(4)[1]; T reg638=reg443+reg608; T reg639=reg324+reg483;
    reg595=reg182+reg595; reg380=reg280-reg380; reg573=reg573+reg348; reg166=reg166+reg373; reg485=reg485+reg374;
    reg402=reg402+reg539; reg182=0.50717967697244910395*elem.pos(11)[0]; reg549=reg391+reg549; reg413=reg447-reg413; reg353=reg353-reg423;
    reg280=0.50717967697244910395*elem.pos(6)[2]; reg562=reg562-reg189; reg561=reg561-reg394; reg269=reg269-reg470; reg597=reg556-reg597;
    reg335=reg335+reg287; reg376=reg376+reg516; reg98=reg98+reg615; reg424=reg424+reg541; reg116=reg116+reg609;
    reg263=reg368+reg263; reg406=reg390+reg406; reg555=reg571+reg555; reg368=0.033811978464829945269*elem.pos(9)[0]; reg418=reg418-reg189;
    reg390=0.10535898384862248483*elem.pos(4)[0]; reg447=reg481+reg601; reg556=1.3856406460551017033*elem.pos(12)[0]; reg176=reg176+reg616; reg571=0.66666666666666670528*elem.pos(12)[0];
    reg298=reg298-reg355; T reg640=0.50717967697244910395*elem.pos(6)[1]; reg613=reg482-reg613; reg333=reg333+reg322; reg113=reg113+reg374;
    reg167=reg568+reg167; reg482=1.3856406460551017033*elem.pos(14)[2]; reg186=reg186-reg394; reg86=reg86+reg322; reg284=reg567+reg284;
    T reg641=1.3856406460551017033*elem.pos(14)[1]; reg174=reg99+reg174; reg524=reg574+reg524; reg504=reg504+reg609; T reg642=0.50717967697244910395*elem.pos(8)[2];
    reg494=reg248+reg494; reg248=1.3856406460551017033*elem.pos(13)[1]; T reg643=0.50717967697244910395*elem.pos(9)[0]; reg525=reg599+reg525; reg180=reg121-reg180;
    reg156=reg550+reg156; reg566=reg511+reg566; reg121=0.033811978464829945269*elem.pos(10)[0]; reg535=reg591+reg535; reg440=reg440-reg515;
    reg511=1.3856406460551017033*elem.pos(13)[2]; reg502=reg502+reg615; reg569=reg569+reg602; reg491=reg94+reg491; reg409=reg230-reg409;
    reg461=reg461-reg544; reg94=0.1261880215351700725*elem.pos(8)[0]; reg230=0.50717967697244910395*elem.pos(8)[1]; reg522=reg350-reg522; reg350=0.7698003589195010602*elem.pos(12)[0];
    reg428=reg428+reg604; reg114=reg114-reg397; reg558=reg243+reg558; reg523=reg523+reg619; reg315=reg575+reg315;
    reg243=0.63094010767585032744*elem.pos(9)[0]; reg550=reg376*reg113; T reg644=reg428*reg333; reg187=reg472+reg187; reg203=reg446+reg203;
    reg446=0.10143593539448982642*elem.pos(11)[0]; reg121=reg523+reg121; reg523=1.2618802153517004798*elem.pos(11)[1]; reg303=reg303+reg622; reg176=reg176+reg556;
    T reg645=0.46188021535170061048*elem.pos(13)[0]; reg73=reg445+reg73; reg445=reg116*reg424; reg455=reg455-reg547; reg376=reg98*reg376;
    T reg646=1.2618802153517004798*elem.pos(9)[0]; T reg647=reg584-reg623; reg569=reg569+reg350; reg188=reg465+reg188; reg269=reg269-reg571;
    T reg648=reg402*reg485; T reg649=0.033811978464829945269*elem.pos(7)[1]; T reg650=0.093922162402305398307*elem.pos(8)[1]; T reg651=reg587+reg626; T reg652=0.033811978464829945269*elem.pos(6)[1];
    reg429=reg68+reg429; reg166=reg166-reg571; reg68=reg639+reg637; T reg653=1.2618802153517004798*elem.pos(11)[2]; reg321=reg321+reg362;
    T reg654=0.76980035891950093199*elem.pos(13)[0]; reg424=reg424*reg86; reg405=reg405+reg264; T reg655=reg634+reg633; T reg656=0.033811978464829945269*elem.pos(6)[2];
    reg561=reg561+reg374; T reg657=reg632+reg629; T reg658=1.0515668461264170957*elem.pos(10)[0]; reg520=reg185+reg520; reg335=reg616+reg335;
    reg185=0.46188021535170061048*elem.pos(12)[0]; reg255=reg255-reg209; reg69=reg246+reg69; reg94=reg491+reg94; reg428=reg504*reg428;
    reg558=reg558-reg189; reg487=reg487-reg247; reg315=reg315+reg511; reg427=reg235+reg427; reg494=reg494-reg394;
    reg235=0.093922162402305398307*elem.pos(8)[0]; reg524=reg524+reg248; reg164=reg403+reg164; reg461=reg391+reg461; reg643=reg566-reg643;
    reg540=reg612+reg540; reg246=0.093922162402305398307*elem.pos(11)[0]; reg391=0.16000000000000001776*elem.pos(11)[0]; reg180=reg180-reg189; reg386=reg287+reg386;
    reg522=reg522-reg394; reg403=0.093922162402305398307*elem.pos(11)[2]; reg491=0.66666666666666670528*elem.pos(14)[0]; reg406=reg406-reg571; reg566=reg630-reg631;
    reg368=reg555+reg368; reg555=0.10143593539448982642*elem.pos(10)[0]; reg635=reg548+reg635; reg548=0.10143593539448982642*elem.pos(11)[2]; reg612=0.66666666666666670528*elem.pos(13)[0];
    reg613=reg613-reg571; T reg659=0.033811978464829945269*elem.pos(7)[0]; reg125=reg538+reg125; reg538=0.10143593539448982642*elem.pos(10)[2]; reg503=reg468+reg503;
    reg418=reg418+reg609; reg167=reg167+reg482; reg186=reg186+reg615; reg624=reg463+reg624; reg80=reg579-reg80;
    reg284=reg284+reg641; reg606=reg231+reg606; reg231=0.093922162402305398307*elem.pos(8)[2]; reg463=0.033811978464829945269*elem.pos(7)[2]; reg588=reg595-reg588;
    reg402=reg502*reg402; reg33=reg495-reg33; reg182=reg573-reg182; reg468=reg636-reg638; reg549=reg549-reg373;
    reg562=reg562+reg322; reg174=reg174-reg528; reg114=reg99+reg114; reg99=0.10143593539448982642*elem.pos(10)[1]; reg495=0.50717967697244910395*elem.pos(7)[0];
    reg380=reg341+reg380; reg341=0.093922162402305398307*elem.pos(11)[1]; reg642=reg525-reg642; reg525=1.8928203230275508072*elem.pos(10)[2]; reg156=reg156-reg578;
    reg620=reg440-reg620; reg621=reg517+reg621; reg625=reg607+reg625; reg266=reg622+reg266; reg440=0.63094010767585032744*elem.pos(11)[1];
    reg280=reg353-reg280; reg409=reg346+reg409; reg413=reg413-reg492; reg597=reg536+reg597; reg228=reg362+reg228;
    reg346=0.63094010767585032744*elem.pos(11)[2]; reg263=reg175+reg263; reg353=0.033811978464829945269*elem.pos(6)[0]; reg517=reg628+reg627; reg230=reg535-reg230;
    reg535=1.8928203230275508072*elem.pos(10)[1]; reg381=reg381-reg500; reg283=reg497-reg283; reg497=reg447+reg390; reg462=reg527-reg462;
    reg245=reg161+reg245; reg590=reg184-reg590; reg640=reg298-reg640; reg554=reg456-reg554; reg184=0.10143593539448982642*elem.pos(11)[1];
    reg426=reg513+reg426; reg549=reg549-reg571; reg368=reg368+reg555; reg125=reg125+reg538; reg187=reg187-reg514;
    reg280=reg599+reg280; reg406=reg406+reg491; reg298=1.8928203230275508072*elem.pos(9)[2]; reg456=reg167*reg562; reg570=reg503+reg570;
    reg503=reg284*reg561; reg513=0.10143593539448982642*elem.pos(7)[0]; reg113=reg116*reg113; reg86=reg98*reg86; reg98=1.8928203230275508072*elem.pos(9)[1];
    reg167=reg418*reg167; reg116=0.10143593539448982642*elem.pos(8)[0]; reg566=reg659+reg566; reg527=0.50717967697244910395*elem.pos(8)[0]; reg174=reg495+reg174;
    reg635=reg635+reg548; reg573=0.40000000000000000835*elem.pos(12)[2]; reg640=reg591+reg640; reg284=reg186*reg284; reg579=0.22222222222222225976*elem.pos(12)[1];
    reg341=reg625+reg341; reg613=reg613+reg612; reg591=0.22222222222222225976*elem.pos(12)[2]; reg403=reg73+reg403; reg381=reg509+reg381;
    reg380=reg161+reg380; reg303=reg303+reg523; reg402=reg428-reg402; reg182=reg182-reg571; reg73=0.50717967697244910395*elem.pos(6)[0];
    reg656=reg656-reg655; reg643=reg348+reg643; reg180=reg180+reg322; reg522=reg522+reg374; reg161=1.0515668461264170957*elem.pos(11)[0];
    reg348=reg608+reg657; reg245=reg472+reg245; reg386=reg386+reg391; reg520=reg520+reg658; reg590=reg590-reg618;
    reg255=reg255-reg572; reg69=reg69-reg394; reg492=reg283-reg492; reg283=0.22222222222222225976*elem.pos(12)[0]; reg246=reg540+reg246;
    reg487=reg487-reg557; reg427=reg427-reg189; reg554=reg622+reg554; reg462=reg462-reg486; reg235=reg164+reg235;
    reg164=0.35052228204213907079*elem.pos(9)[0]; reg353=reg353-reg517; reg624=reg614+reg624; reg263=reg465+reg263; reg335=reg335+reg185;
    reg80=reg80-reg394; reg588=reg588-reg189; reg231=reg606+reg231; reg428=0.35052228204213907079*elem.pos(9)[2]; reg409=reg175+reg409;
    reg94=reg619+reg94; reg175=1.7512105867530111459e-16*elem.pos(11)[0]; reg33=reg658+reg33; reg558=reg558+reg609; reg620=reg362+reg620;
    reg468=reg463+reg468; reg463=0.10143593539448982642*elem.pos(8)[2]; reg315=reg541+reg315; reg156=reg536+reg156; reg494=reg494+reg615;
    reg524=reg516+reg524; reg465=0.10143593539448982642*elem.pos(7)[2]; reg114=reg114-reg534; reg470=reg461-reg470; reg461=0.40000000000000000835*elem.pos(12)[1];
    reg650=reg429+reg650; reg621=reg621+reg99; reg228=reg228-reg346; reg321=reg321+reg653; reg455=reg455+reg646;
    reg652=reg652-reg651; reg121=reg121+reg446; reg188=reg188-reg542; reg405=reg405-reg243; reg429=0.40000000000000000835*elem.pos(12)[0];
    reg333=reg502*reg333; reg472=1.8928203230275508072*elem.pos(11)[2]; reg166=reg166+reg491; reg569=reg569+reg654; reg266=reg266-reg440;
    reg648=reg644-reg648; reg500=reg413-reg500; reg413=0.76980035891950093199*elem.pos(14)[0]; reg550=reg424-reg550; reg424=0.46188021535170061048*elem.pos(14)[0];
    reg176=reg176+reg645; reg502=reg496+reg497; reg642=reg642+reg525; reg485=reg504*reg485; reg269=reg269+reg612;
    reg504=0.35052228204213907079*elem.pos(9)[1]; reg536=0.63094010767585032744*elem.pos(10)[0]; reg540=0.10143593539448982642*elem.pos(8)[1]; reg376=reg445-reg376; reg203=reg598+reg203;
    reg597=reg597-reg264; reg445=0.10143593539448982642*elem.pos(7)[1]; reg647=reg649+reg647; reg230=reg230+reg535; reg595=reg411+reg68;
    reg426=reg426+reg184; reg598=1.8928203230275508072*elem.pos(11)[1]; reg409=reg357+reg409; reg175=reg33+reg175; reg33=0.033811978464829945269*elem.pos(11)[0];
    reg357=0.13333333333333334846*elem.pos(13)[0]; reg94=reg555+reg94; reg468=reg468+reg463; reg503=reg456-reg503; reg353=reg513+reg353;
    reg456=0.37856406460551018245*elem.pos(9)[1]; reg624=reg538+reg624; reg538=0.033811978464829945269*elem.pos(11)[2]; reg263=reg263-reg574; reg647=reg647+reg540;
    reg335=reg645+reg335; reg80=reg80+reg374; reg555=1.3856406460551017033*elem.pos(14)[0]; reg562=reg186*reg562; reg588=reg588+reg322;
    reg472=reg642-reg472; reg561=reg418*reg561; reg428=reg231+reg428; reg186=0.35052228204213901243*elem.pos(10)[2]; reg620=reg620-reg653;
    reg266=reg266-reg189; reg386=reg185+reg386; reg231=1.3856406460551017033*elem.pos(13)[0]; reg418=0.22222222222222222276*elem.pos(13)[0]; reg255=reg255-reg539;
    reg598=reg230-reg598; reg246=reg246+reg283; reg564=reg492-reg564; reg69=reg69+reg615; reg230=0.033811978464829945269*elem.pos(11)[1];
    reg590=reg622+reg590; reg203=reg99+reg203; reg487=reg487-reg604; reg554=reg554-reg523; reg427=reg427+reg609;
    reg485=reg333-reg485; reg405=reg536+reg405; reg462=reg362+reg462; reg99=1.2618802153517004798*elem.pos(11)[0]; reg164=reg235+reg164;
    reg235=0.35052228204213901243*elem.pos(10)[0]; reg333=0.37856406460551018245*elem.pos(9)[2]; reg362=reg558*reg315; reg492=0.35052228204213901243*elem.pos(10)[1]; reg547=reg156-reg547;
    reg504=reg650+reg504; reg156=reg494*reg524; reg621=reg184+reg621; reg455=reg455+reg536; reg470=reg470-reg571;
    reg184=0.63094010767585032744*elem.pos(11)[0]; reg73=reg114-reg73; reg656=reg465+reg656; reg643=reg643-reg571; reg315=reg315*reg180;
    reg569=reg569+reg413; reg161=reg520-reg161; reg114=0.13333333333333334846*elem.pos(12)[1]; reg524=reg524*reg522; reg636=reg636-reg348;
    reg245=reg245-reg575; reg121=reg121+reg429; reg188=reg188-reg567; reg182=reg182+reg612; reg321=reg321-reg394;
    reg403=reg403+reg591; reg520=0.22222222222222222276*elem.pos(13)[2]; reg380=reg422+reg380; reg648=reg406*reg648; reg406=0.13333333333333334846*elem.pos(13)[1];
    reg613=reg402*reg613; reg630=reg630-reg502; reg284=reg167-reg284; reg652=reg445+reg652; reg550=reg166*reg550;
    reg98=reg640-reg98; reg166=0.13333333333333334846*elem.pos(13)[2]; reg635=reg635+reg573; reg500=reg559+reg500; reg341=reg341+reg579;
    reg167=0.22222222222222222276*elem.pos(13)[1]; reg402=1.8928203230275508072*elem.pos(10)[0]; reg584=reg584-reg595; reg269=reg376*reg269; reg527=reg174-reg527;
    reg228=reg228-reg394; reg566=reg566+reg116; reg174=0.37856406460551018245*elem.pos(9)[0]; reg187=reg187-reg568; reg368=reg446+reg368;
    reg303=reg303-reg189; reg426=reg426+reg461; reg602=reg570+reg602; reg381=reg155+reg381; reg176=reg176+reg424;
    reg113=reg86-reg113; reg86=0.13333333333333334846*elem.pos(12)[0]; reg298=reg280-reg298; reg243=reg597-reg243; reg155=0.13333333333333334846*elem.pos(12)[2];
    reg125=reg548+reg125; reg549=reg549+reg491; reg280=reg69*reg255; reg98=reg535+reg98; reg376=1.8928203230275508072*elem.pos(9)[0];
    reg381=reg616+reg381; reg422=0.1261880215351700725*elem.pos(9)[2]; reg656=reg463+reg656; reg455=reg455-reg184; reg321=reg321+reg615;
    reg522=reg558*reg522; reg73=reg495+reg73; reg446=0.1261880215351700725*elem.pos(10)[0]; reg630=reg513+reg630; reg564=reg509+reg564;
    reg386=reg386+reg231; reg554=reg554-reg189; reg470=reg470+reg612; reg303=reg303+reg609; reg463=0.033811978464829945269*elem.pos(8)[0];
    reg180=reg494*reg180; reg636=reg465+reg636; reg440=reg590-reg440; reg187=reg187-reg541; reg621=reg621+reg114;
    reg230=reg203+reg230; reg203=reg427*reg487; reg524=reg315-reg524; reg315=0.033811978464829945269*elem.pos(8)[2]; reg465=0.22222222222222222276*elem.pos(14)[0];
    reg246=reg246+reg418; reg494=1.8928203230275508072*elem.pos(11)[0]; reg495=0.22222222222222222276*elem.pos(14)[2]; reg161=reg161-reg571; reg527=reg527+reg402;
    reg245=reg245-reg568; reg403=reg403+reg520; reg228=reg228+reg374; reg550=reg269-reg550; reg643=reg643+reg491;
    reg598=reg598-reg189; reg368=reg368+reg86; reg269=0.35052228204213907079*elem.pos(11)[2]; reg186=reg428+reg186; reg380=reg380-reg575;
    reg346=reg462-reg346; reg428=0.033811978464829945269*elem.pos(8)[1]; reg648=reg613-reg648; reg561=reg562-reg561; reg182=reg284*reg182;
    reg405=reg405+reg99; reg487=reg487*reg588; reg335=reg335+reg555; reg284=0.1261880215351700725*elem.pos(9)[0]; reg188=reg188-reg516;
    reg255=reg255*reg80; reg113=reg176*reg113; reg353=reg116+reg353; reg125=reg125+reg155; reg298=reg525+reg298;
    reg263=reg263-reg567; reg503=reg549*reg503; reg538=reg624+reg538; reg602=reg602-reg350; reg243=reg536+reg243;
    reg647=reg647+reg456; reg116=0.1261880215351700725*elem.pos(10)[1]; reg176=0.35052228204213907079*elem.pos(11)[0]; reg472=reg472-reg394; reg235=reg164+reg235;
    reg566=reg566+reg174; reg156=reg362-reg156; reg500=reg287+reg500; reg164=0.22222222222222222276*elem.pos(14)[1]; reg547=reg547-reg646;
    reg341=reg341+reg167; reg492=reg504+reg492; reg362=0.1261880215351700725*elem.pos(10)[2]; reg468=reg468+reg333; reg462=0.1261880215351700725*elem.pos(9)[1];
    reg504=0.35052228204213907079*elem.pos(11)[1]; reg635=reg635+reg166; reg121=reg121+reg357; reg620=reg620-reg394; reg266=reg266+reg322;
    reg509=0.13333333333333334846*elem.pos(14)[1]; reg426=reg426+reg406; reg33=reg94+reg33; reg584=reg445+reg584; reg409=reg409-reg574;
    reg569=reg485*reg569; reg175=reg175-reg571; reg652=reg540+reg652; reg94=0.13333333333333334846*elem.pos(14)[2]; reg445=0.13333333333333334846*elem.pos(14)[0];
    reg554=reg554+reg609; reg113=reg550+reg113; reg440=reg440-reg189; reg648=reg569+reg648; reg463=reg630+reg463;
    reg472=reg472+reg374; reg243=reg243-reg99; reg298=reg298-reg394; reg503=reg182-reg503; reg620=reg620+reg615;
    reg263=reg263-reg641; reg561=reg335*reg561; reg121=reg121+reg445; reg380=reg380-reg511; reg33=reg86+reg33;
    reg182=0.40000000000000000835*elem.pos(13)[0]; reg409=reg409-reg248; reg547=reg536+reg547; reg500=reg616+reg500; reg470=reg156*reg470;
    reg189=reg98-reg189; reg376=reg73-reg376; reg245=reg245-reg482; reg494=reg527-reg494; reg524=reg643*reg524;
    reg73=0.40000000000000000835*elem.pos(14)[0]; reg368=reg357+reg368; reg386=reg424+reg386; reg522=reg180-reg522; reg598=reg598+reg322;
    reg246=reg246+reg465; reg446=reg566+reg446; reg341=reg341+reg164; reg635=reg635+reg94; reg80=reg427*reg80;
    reg588=reg69*reg588; reg125=reg166+reg125; reg69=0.40000000000000000835*elem.pos(14)[2]; reg602=reg602-reg654; reg538=reg155+reg538;
    reg98=0.40000000000000000835*elem.pos(13)[2]; reg255=reg487-reg255; reg284=reg353+reg284; reg156=0.37856406460551018245*elem.pos(10)[0]; reg269=reg186+reg269;
    reg175=reg175+reg491; reg362=reg468+reg362; reg180=0.37856406460551018245*elem.pos(11)[2]; reg161=reg161+reg612; reg422=reg656+reg422;
    reg186=0.37856406460551018245*elem.pos(10)[2]; reg405=reg405-reg571; reg230=reg114+reg230; reg335=0.40000000000000000835*elem.pos(13)[1]; reg353=0.40000000000000000835*elem.pos(14)[1];
    reg621=reg406+reg621; reg455=reg455-reg571; reg504=reg492+reg504; reg427=reg187*reg266; reg468=reg321*reg188;
    reg116=reg647+reg116; reg485=0.37856406460551018245*elem.pos(11)[1]; reg426=reg426+reg509; reg462=reg652+reg462; reg487=0.37856406460551018245*elem.pos(10)[1];
    reg428=reg584+reg428; reg188=reg188*reg228; reg187=reg303*reg187; reg381=reg381-reg556; reg403=reg403+reg495;
    reg492=0.37856406460551018245*elem.pos(11)[0]; reg280=reg203-reg280; reg564=reg287+reg564; reg315=reg636+reg315; reg394=reg346-reg394;
    reg176=reg235+reg176; reg381=reg381-reg645; reg564=reg391+reg564; reg368=reg368+reg73; reg403=reg648*reg403;
    reg266=reg321*reg266; reg228=reg303*reg228; reg446=reg446+reg492; reg609=reg189+reg609; reg341=reg648*reg341;
    reg635=reg113*reg635; reg80=reg588-reg80; reg380=reg380-reg541; reg602=reg602-reg413; reg189=reg620*reg263;
    reg125=reg125+reg69; reg522=reg386*reg522; reg615=reg298+reg615; reg538=reg538+reg98; reg255=reg175*reg255;
    reg284=reg284+reg156; reg561=reg503+reg561; reg269=reg591+reg269; reg33=reg33+reg182; reg283=reg176+reg283;
    reg230=reg230+reg335; reg175=reg245*reg598; reg621=reg621+reg353; reg455=reg455+reg612; reg374=reg394+reg374;
    reg504=reg579+reg504; reg468=reg187-reg468; reg322=reg440+reg322; reg263=reg263*reg472; reg243=reg243-reg571;
    reg246=reg648*reg246; reg116=reg116+reg485; reg426=reg113*reg426; reg462=reg462+reg487; reg500=reg500-reg185;
    reg494=reg494-reg571; reg428=reg456+reg428; reg121=reg121*reg113; reg188=reg427-reg188; reg405=reg405+reg491;
    reg463=reg174+reg463; reg161=reg280*reg161; reg409=reg409-reg516; reg315=reg333+reg315; reg422=reg422+reg186;
    reg184=reg547-reg184; reg376=reg402+reg376; reg362=reg362+reg180; reg524=reg470-reg524; reg245=reg554*reg245;
    reg174=0.1261880215351700725*elem.pos(11)[1]; reg113=0.13020833333333334259*reg113; reg121=0.13020833333333334259*reg121; reg176=0.1261880215351700725*elem.pos(11)[2]; reg463=reg156+reg463;
    reg156=0.1261880215351700725*elem.pos(11)[0]; reg188=reg405*reg188; reg381=reg381-reg424; reg184=reg184-reg571; reg80=reg602*reg80;
    reg189=reg245-reg189; reg403=0.140625*reg403; reg635=0.13020833333333334259*reg635; reg228=reg266-reg228; reg446=reg429+reg446;
    reg564=reg564-reg185; reg341=0.140625*reg341; reg362=reg573+reg362; reg246=0.140625*reg246; reg418=reg283+reg418;
    reg230=reg509+reg230; reg621=reg561*reg621; reg455=reg468*reg455; reg243=reg243+reg491; reg187=reg409*reg374;
    reg571=reg376-reg571; reg504=reg167+reg504; reg167=reg380*reg322; reg422=reg180+reg422; reg263=reg175-reg263;
    reg116=reg461+reg116; reg426=0.13020833333333334259*reg426; reg648=0.140625*reg648; reg462=reg485+reg462; reg500=reg500-reg645;
    reg598=reg620*reg598; reg472=reg554*reg472; reg494=reg494+reg612; reg315=reg186+reg315; reg428=reg487+reg428;
    reg538=reg94+reg538; reg522=reg524+reg522; reg284=reg492+reg284; reg409=reg615*reg409; reg368=reg368*reg561;
    reg125=reg561*reg125; reg380=reg609*reg380; reg255=reg161-reg255; reg269=reg520+reg269; reg33=reg445+reg33;
    reg374=reg609*reg374; reg246=reg121-reg246; reg174=reg428+reg174; reg284=reg86+reg284; reg648=reg113-reg648;
    reg409=reg380-reg409; reg156=reg463+reg156; reg561=0.13020833333333334259*reg561; reg538=reg522*reg538; reg472=reg598-reg472;
    reg500=reg500-reg555; reg462=reg114+reg462; reg341=reg426-reg341; reg494=reg189*reg494; reg116=reg406+reg116;
    reg263=reg243*reg263; reg422=reg155+reg422; reg368=0.13020833333333334259*reg368; reg187=reg167-reg187; reg504=reg164+reg504;
    reg269=reg495+reg269; reg491=reg571+reg491; reg465=reg418+reg465; reg230=reg522*reg230; reg621=0.13020833333333334259*reg621;
    reg176=reg315+reg176; reg80=reg255+reg80; reg403=reg635-reg403; reg322=reg615*reg322; reg564=reg564-reg231;
    reg362=reg166+reg362; reg446=reg357+reg446; reg228=reg381*reg228; reg33=reg33*reg522; reg612=reg184+reg612;
    reg125=0.13020833333333334259*reg125; reg188=reg455-reg188; reg522=0.13020833333333334259*reg522; reg504=reg80*reg504; reg368=reg246+reg368;
    reg472=reg500*reg472; reg446=reg445+reg446; reg538=0.13020833333333334259*reg538; reg187=reg491*reg187; reg648=reg561+reg648;
    reg462=reg406+reg462; reg564=reg564-reg424; reg228=reg188+reg228; reg263=reg494-reg263; reg612=reg409*reg612;
    reg116=reg509+reg116; reg362=reg94+reg362; reg176=reg155+reg176; reg374=reg322-reg374; reg156=reg86+reg156;
    reg621=reg341+reg621; reg125=reg403+reg125; reg230=0.13020833333333334259*reg230; reg174=reg114+reg174; reg465=reg465*reg80;
    reg269=reg80*reg269; reg284=reg357+reg284; reg422=reg166+reg422; reg33=0.13020833333333334259*reg33; reg422=reg69+reg422;
    reg269=0.140625*reg269; reg522=reg648+reg522; reg230=reg621+reg230; reg504=0.140625*reg504; reg80=0.140625*reg80;
    reg374=reg564*reg374; reg33=reg368+reg33; reg465=0.140625*reg465; reg116=reg228*reg116; reg446=reg446*reg228;
    reg176=reg98+reg176; reg156=reg182+reg156; reg187=reg612-reg187; reg284=reg73+reg284; reg362=reg228*reg362;
    reg462=reg353+reg462; reg174=reg335+reg174; reg472=reg263+reg472; reg538=reg125+reg538; reg465=reg33-reg465;
    reg362=0.13020833333333334259*reg362; reg284=reg284*reg472; reg462=reg472*reg462; reg504=reg230-reg504; reg156=reg445+reg156;
    reg80=reg522-reg80; reg228=0.13020833333333334259*reg228; reg422=reg472*reg422; reg446=0.13020833333333334259*reg446; reg174=reg509+reg174;
    reg269=reg538-reg269; reg116=0.13020833333333334259*reg116; reg176=reg94+reg176; reg374=reg187+reg374; reg174=reg374*reg174;
    reg422=0.13020833333333334259*reg422; reg116=reg504+reg116; reg446=reg465+reg446; reg176=reg374*reg176; reg156=reg156*reg374;
    reg80=reg228+reg80; reg362=reg269+reg362; reg462=0.13020833333333334259*reg462; reg284=0.13020833333333334259*reg284; reg472=0.13020833333333334259*reg472;
    reg176=0.13020833333333334259*reg176; reg462=reg116+reg462; reg174=0.13020833333333334259*reg174; reg156=0.13020833333333334259*reg156; reg374=0.13020833333333334259*reg374;
    reg422=reg362+reg422; reg472=reg80+reg472; reg284=reg446+reg284; reg174=reg462+reg174; reg176=reg422+reg176;
    reg374=reg472+reg374; reg156=reg284+reg156; res[1]=reg174/reg374; res[0]=reg156/reg374; res[2]=reg176/reg374;

    return res;
}
}
#endif // LMT_WEDGE_15
