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
    T reg0=nodes[0]->pos[2]+nodes[3]->pos[2]; T reg1=nodes[0]->pos[1]+nodes[3]->pos[1]; reg0=reg0-nodes[6]->pos[2]; reg1=reg1-nodes[6]->pos[1]; reg1=reg1+nodes[7]->pos[1];
    reg0=reg0+nodes[7]->pos[2]; T reg2=nodes[0]->pos[0]+nodes[3]->pos[0]; reg0=reg0-nodes[8]->pos[2]; reg2=reg2-nodes[6]->pos[0]; reg1=reg1-nodes[8]->pos[1];
    reg1=reg1-nodes[9]->pos[1]; reg0=reg0-nodes[9]->pos[2]; reg2=reg2+nodes[7]->pos[0]; reg1=reg1+nodes[10]->pos[1]; reg0=reg0+nodes[10]->pos[2];
    reg2=reg2-nodes[8]->pos[0]; reg0=reg0-nodes[11]->pos[2]; reg2=reg2-nodes[9]->pos[0]; reg1=reg1-nodes[11]->pos[1]; reg0=reg0-nodes[12]->pos[2];
    reg2=reg2+nodes[10]->pos[0]; reg1=reg1-nodes[12]->pos[1]; reg2=reg2-nodes[11]->pos[0]; T reg3=nodes[14]->pos[1]+reg1; T reg4=nodes[10]->pos[2]-nodes[7]->pos[2];
    T reg5=nodes[14]->pos[2]+reg0; reg0=nodes[13]->pos[2]+reg0; reg1=nodes[13]->pos[1]+reg1; T reg6=nodes[10]->pos[1]-nodes[7]->pos[1]; reg2=reg2-nodes[12]->pos[0];
    T reg7=reg3*reg4; T reg8=reg6*reg0; reg4=reg4*reg1; reg6=reg5*reg6; T reg9=nodes[13]->pos[0]+reg2;
    reg6=reg7-reg6; reg2=nodes[14]->pos[0]+reg2; reg8=reg4-reg8; reg1=reg5*reg1; reg0=reg3*reg0;
    reg6=reg9*reg6; reg8=reg2*reg8; reg2=nodes[10]->pos[0]-nodes[7]->pos[0]; reg0=reg1-reg0; reg8=reg6-reg8;
    reg0=reg2*reg0; T det_jac=reg8+reg0;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[14],nodes[13],nodes[12],nodes[11],nodes[10],nodes[9],nodes[8],nodes[7],nodes[6],nodes[5],nodes[4],nodes[3],nodes[2],nodes[1],nodes[0]};
        for(unsigned i=0;i<15;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*var_inter[0]; T reg3=2*reg0;
    T reg4=reg2-1; T reg5=reg3-1; T reg6=0.5*var_inter[0]; T reg7=2*var_inter[1]; T reg8=0.5*reg0;
    reg1=reg1-1; T reg9=0.5*var_inter[1]; T reg10=reg7-1; T reg11=reg6*reg4; T reg12=4*reg1;
    T reg13=reg8*reg5; T reg14=reg12*reg6; T reg15=pow(reg1,2); T reg16=reg9*reg10; T reg17=2*reg11;
    T reg18=reg8*reg12; T reg19=2*reg13; reg5=0.5*reg5; T reg20=reg12*reg9; T reg21=2*reg16;
    T reg22=reg14-reg17; reg15=1-reg15; T reg23=reg18-reg19; reg10=0.5*reg10; T reg24=1-reg1;
    reg10=reg10+var_inter[1]; T reg25=reg20-reg21; T reg26=pos_nodes[0][0]*reg23; T reg27=pos_nodes[1][0]*reg22; reg5=reg0+reg5;
    T reg28=reg23*pos_nodes[0][1]; T reg29=pos_nodes[1][1]*reg22; T reg30=reg24*reg11; reg6=reg15*reg6; T reg31=reg13*reg24;
    reg8=reg8*reg15; T reg32=pos_nodes[1][2]*reg22; T reg33=pos_nodes[0][2]*reg23; reg27=reg26+reg27; reg4=0.5*reg4;
    reg26=pos_nodes[2][2]*reg25; reg9=reg15*reg9; T reg34=reg24*reg16; reg31=reg31-reg8; T reg35=reg19+reg18;
    reg1=1+reg1; reg30=reg30-reg6; T reg36=reg24*reg10; T reg37=reg24*reg5; T reg38=pos_nodes[2][0]*reg25;
    T reg39=0.5*reg15; T reg40=pos_nodes[2][1]*reg25; reg29=reg28+reg29; reg32=reg33+reg32; reg40=reg29+reg40;
    reg36=reg36-reg39; reg28=pos_nodes[0][1]*reg31; reg13=reg13*reg1; reg29=pos_nodes[1][1]*reg30; reg33=pos_nodes[3][2]*reg35;
    T reg41=pos_nodes[1][0]*reg30; T reg42=pos_nodes[0][0]*reg31; reg34=reg34-reg9; reg38=reg27+reg38; reg27=reg17+reg14;
    T reg43=pos_nodes[3][0]*reg35; reg26=reg32+reg26; reg4=reg4+var_inter[0]; reg32=pos_nodes[3][1]*reg35; T reg44=reg39-reg37;
    T reg45=reg5*reg1; T reg46=pos_nodes[2][1]*reg36; T reg47=pos_nodes[0][2]*reg44; T reg48=pos_nodes[2][0]*reg36; T reg49=pos_nodes[2][2]*reg36;
    T reg50=reg39-reg45; T reg51=reg44*pos_nodes[0][1]; reg26=reg33+reg26; reg33=pos_nodes[4][2]*reg27; reg38=reg43+reg38;
    reg43=pos_nodes[4][0]*reg27; T reg52=pos_nodes[2][0]*reg34; reg41=reg42+reg41; reg42=pos_nodes[0][2]*reg31; T reg53=reg21+reg20;
    T reg54=pos_nodes[4][1]*reg27; reg40=reg32+reg40; reg29=reg28+reg29; reg28=pos_nodes[2][1]*reg34; reg32=pos_nodes[1][2]*reg30;
    T reg55=reg3*var_inter[0]; T reg56=pos_nodes[0][0]*reg44; T reg57=reg24*reg4; reg10=reg10*reg1; reg11=reg11*reg1;
    reg8=reg13-reg8; reg57=reg57-reg39; reg32=reg42+reg32; reg43=reg38+reg43; reg13=2*reg55;
    reg38=pos_nodes[5][0]*reg53; reg42=pos_nodes[3][0]*reg8; T reg58=pos_nodes[5][2]*reg53; reg52=reg41+reg52; reg33=reg26+reg33;
    reg26=pos_nodes[3][1]*reg50; reg49=reg47+reg49; reg41=pos_nodes[3][2]*reg50; reg46=reg51+reg46; reg6=reg11-reg6;
    reg16=reg16*reg1; reg11=var_inter[1]*reg2; reg28=reg29+reg28; reg29=pos_nodes[3][1]*reg8; reg54=reg40+reg54;
    reg40=pos_nodes[5][1]*reg53; reg48=reg56+reg48; reg10=reg10-reg39; T reg59=pos_nodes[2][2]*reg34; T reg60=pos_nodes[3][0]*reg50;
    reg46=reg26+reg46; reg48=reg60+reg48; reg49=reg41+reg49; T reg61=pos_nodes[5][2]*reg10; T reg62=pos_nodes[1][1]*reg57;
    T reg63=pos_nodes[5][0]*reg10; T reg64=pos_nodes[4][0]*reg6; reg52=reg42+reg52; reg58=reg33+reg58; reg33=pos_nodes[6][2]*reg13;
    reg42=pos_nodes[5][1]*reg10; T reg65=reg24*reg2; reg9=reg16-reg9; reg16=reg0*reg7; T reg66=pos_nodes[4][1]*reg6;
    reg28=reg29+reg28; reg29=pos_nodes[6][1]*reg13; reg40=reg54+reg40; reg54=pos_nodes[6][0]*reg13; reg38=reg43+reg38;
    reg43=pos_nodes[1][0]*reg57; reg59=reg32+reg59; reg32=2*reg11; reg4=reg4*reg1; T reg67=pos_nodes[3][2]*reg8;
    reg54=reg38-reg54; reg61=reg49+reg61; reg38=pos_nodes[1][2]*reg57; reg62=reg51+reg62; reg49=pos_nodes[7][0]*reg32;
    reg63=reg48+reg63; reg48=pos_nodes[6][2]*reg65; reg51=reg3-reg7; reg42=reg46+reg42; reg46=pos_nodes[6][1]*reg65;
    T reg68=pos_nodes[4][2]*reg6; T reg69=reg24*reg55; T reg70=pos_nodes[6][0]*reg65; reg59=reg67+reg59; reg3=reg3-reg2;
    reg29=reg40-reg29; reg40=pos_nodes[7][2]*reg32; reg33=reg58-reg33; reg58=pos_nodes[7][1]*reg32; reg67=2*reg16;
    reg4=reg4-reg39; reg43=reg56+reg43; reg56=pos_nodes[5][1]*reg9; reg66=reg28+reg66; reg64=reg52+reg64;
    reg28=pos_nodes[5][0]*reg9; reg56=reg66+reg56; reg52=pos_nodes[6][1]*reg69; reg66=reg24*reg3; reg47=reg38+reg47;
    reg38=reg24*reg11; reg58=reg29-reg58; reg29=reg24*reg51; T reg71=pos_nodes[8][1]*reg67; T reg72=pos_nodes[5][2]*reg9;
    reg43=reg60+reg43; reg60=pos_nodes[4][0]*reg4; reg46=reg42-reg46; reg42=pos_nodes[7][1]*reg65; reg68=reg59+reg68;
    reg59=pos_nodes[7][0]*reg65; reg70=reg63-reg70; reg63=pos_nodes[6][0]*reg69; reg28=reg64+reg28; reg64=pos_nodes[8][0]*reg67;
    T reg73=pos_nodes[7][2]*reg65; reg48=reg61-reg48; reg49=reg54-reg49; reg62=reg26+reg62; reg26=pos_nodes[4][1]*reg4;
    reg40=reg33-reg40; reg33=pos_nodes[8][2]*reg67; reg54=pos_nodes[9][2]*reg13; reg33=reg40-reg33; reg40=pos_nodes[7][0]*reg38;
    reg61=reg24*reg16; T reg74=pos_nodes[7][1]*reg38; reg52=reg56+reg52; reg63=reg28+reg63; reg24=reg24*reg7;
    reg64=reg49-reg64; reg59=reg70+reg59; reg28=pos_nodes[8][1]*reg29; reg49=pos_nodes[8][0]*reg29; reg56=pos_nodes[9][0]*reg13;
    reg71=reg58-reg71; reg58=pos_nodes[9][1]*reg13; reg26=reg62+reg26; reg62=reg2*reg1; reg41=reg47+reg41;
    reg47=pos_nodes[4][2]*reg4; reg72=reg68+reg72; reg73=reg48+reg73; reg48=pos_nodes[8][2]*reg29; reg68=pos_nodes[6][2]*reg69;
    reg42=reg46+reg42; reg46=pos_nodes[6][1]*reg66; reg60=reg43+reg60; reg43=pos_nodes[6][0]*reg66; reg70=pos_nodes[6][2]*reg66;
    reg54=reg33+reg54; reg33=pos_nodes[10][2]*reg32; reg47=reg41+reg47; reg68=reg72+reg68; reg41=pos_nodes[7][2]*reg38;
    reg58=reg71+reg58; reg71=pos_nodes[10][1]*reg32; reg72=pos_nodes[8][1]*reg61; reg74=reg52+reg74; reg48=reg73+reg48;
    reg52=pos_nodes[9][2]*reg62; reg73=pos_nodes[7][1]*reg24; reg46=reg26+reg46; reg26=pos_nodes[8][0]*reg61; reg40=reg63+reg40;
    reg55=reg55*reg1; reg63=pos_nodes[10][0]*reg32; reg56=reg64+reg56; reg28=reg42+reg28; reg42=pos_nodes[9][1]*reg62;
    reg43=reg60+reg43; reg60=pos_nodes[7][0]*reg24; reg49=reg59+reg49; reg59=pos_nodes[9][0]*reg62; reg11=reg11*reg1;
    reg64=pos_nodes[11][2]*reg67; reg72=reg74+reg72; reg74=pos_nodes[9][1]*reg55; reg33=reg54+reg33; reg63=reg56+reg63;
    reg54=pos_nodes[11][0]*reg67; reg56=pos_nodes[8][0]*reg24; reg26=reg40+reg26; reg40=pos_nodes[9][0]*reg55; T reg75=pos_nodes[10][2]*reg62;
    reg52=reg48-reg52; reg60=reg43+reg60; reg73=reg46+reg73; reg70=reg47+reg70; reg43=pos_nodes[7][2]*reg24;
    reg46=pos_nodes[8][1]*reg24; reg51=reg51*reg1; reg59=reg49-reg59; reg71=reg58+reg71; reg47=pos_nodes[11][1]*reg67;
    reg3=reg3*reg1; reg42=reg28-reg42; reg28=pos_nodes[10][0]*reg62; reg48=pos_nodes[8][2]*reg61; reg41=reg68+reg41;
    reg49=pos_nodes[10][1]*reg62; reg58=reg0*reg12; reg68=pos_nodes[11][2]*reg51; reg75=reg52+reg75; reg48=reg41+reg48;
    reg41=pos_nodes[9][2]*reg55; reg46=reg73-reg46; reg28=reg59+reg28; reg52=pos_nodes[10][0]*reg11; reg40=reg26+reg40;
    reg26=pos_nodes[11][0]*reg51; reg56=reg60-reg56; reg59=pos_nodes[12][0]*reg58; reg54=reg63+reg54; reg60=reg7*reg1;
    reg63=reg12*var_inter[0]; reg64=reg33+reg64; reg33=pos_nodes[9][0]*reg3; reg73=pos_nodes[12][2]*reg58; reg49=reg42+reg49;
    reg42=pos_nodes[11][1]*reg51; T reg76=pos_nodes[8][2]*reg24; reg43=reg70+reg43; reg70=pos_nodes[9][1]*reg3; reg1=reg16*reg1;
    reg74=reg72+reg74; reg16=pos_nodes[10][1]*reg11; reg47=reg71+reg47; reg71=pos_nodes[12][1]*reg58; reg26=reg28+reg26;
    reg28=pos_nodes[12][1]*reg15; reg68=reg75+reg68; reg72=pos_nodes[13][1]*reg63; reg75=pos_nodes[11][0]*reg1; reg52=reg40+reg52;
    reg40=reg12*var_inter[1]; reg0=reg0*reg15; T reg77=pos_nodes[13][2]*reg63; reg73=reg64-reg73; reg16=reg74+reg16;
    reg64=pos_nodes[11][1]*reg1; reg74=pos_nodes[13][0]*reg63; reg59=reg54-reg59; reg76=reg43-reg76; reg43=pos_nodes[9][2]*reg3;
    reg54=pos_nodes[12][2]*reg15; reg33=reg56+reg33; reg56=pos_nodes[10][0]*reg60; T reg78=pos_nodes[12][0]*reg15; reg42=reg49+reg42;
    reg71=reg47-reg71; reg41=reg48+reg41; reg70=reg46+reg70; reg46=pos_nodes[10][2]*reg11; reg47=pos_nodes[10][1]*reg60;
    reg48=var_inter[0]*reg15; reg72=reg71-reg72; reg49=pos_nodes[14][1]*reg40; reg26=reg26-reg78; reg56=reg33+reg56;
    reg33=pos_nodes[11][0]*reg60; reg77=reg73-reg77; reg71=pos_nodes[14][2]*reg40; reg73=pos_nodes[14][1]*reg15; reg42=reg42-reg28;
    T reg79=pos_nodes[11][2]*reg1; reg46=reg41+reg46; reg41=pos_nodes[12][1]*reg0; T reg80=pos_nodes[14][0]*reg15; reg43=reg76+reg43;
    reg76=pos_nodes[10][2]*reg60; reg75=reg52+reg75; reg47=reg70+reg47; reg52=pos_nodes[11][1]*reg60; reg68=reg68-reg54;
    reg70=pos_nodes[14][2]*reg15; reg64=reg16+reg64; reg74=reg59-reg74; reg16=pos_nodes[14][0]*reg40; reg59=pos_nodes[12][0]*reg0;
    reg79=reg46+reg79; reg46=reg48*pos_nodes[13][0]; reg75=reg59+reg75; reg16=reg74-reg16; reg49=reg72-reg49;
    reg52=reg47-reg52; reg80=reg26+reg80; reg70=reg68+reg70; reg64=reg41+reg64; reg26=reg48*pos_nodes[13][1];
    reg41=var_inter[1]*reg15; reg71=reg77-reg71; reg76=reg43+reg76; reg43=pos_nodes[12][2]*reg0; reg47=pos_nodes[11][2]*reg60;
    reg73=reg42+reg73; reg33=reg56-reg33; reg47=reg76-reg47; reg42=reg16*reg70; reg56=pos_nodes[13][0]*reg15;
    reg59=reg80*reg71; reg68=reg49*reg70; reg72=reg73*reg71; reg74=reg48*pos_nodes[13][2]; reg79=reg43+reg79;
    reg78=reg33-reg78; reg26=reg64+reg26; reg33=pos_nodes[13][1]*reg15; reg46=reg75+reg46; reg43=reg41*pos_nodes[14][1];
    reg64=reg41*pos_nodes[14][0]; reg28=reg52-reg28; reg52=reg16*reg73; reg42=reg59-reg42; reg75=reg80*reg49;
    reg68=reg72-reg68; reg33=reg28+reg33; reg64=reg46+reg64; reg28=pos_nodes[13][2]*reg15; reg56=reg78+reg56;
    reg54=reg47-reg54; reg74=reg79+reg74; reg43=reg26+reg43; reg26=reg41*pos_nodes[14][2]; reg52=reg75-reg52;
    reg64=pos[0]-reg64; reg46=reg33*reg42; reg26=reg74+reg26; reg47=reg56*reg68; reg74=reg56*var_inter[0];
    reg28=reg54+reg28; reg54=reg33*var_inter[0]; reg43=pos[1]-reg43; reg76=reg73*reg28; reg77=reg80*reg28;
    reg78=reg56*reg70; reg79=reg33*reg70; T reg81=reg49*reg28; T reg82=reg33*reg71; T reg83=reg28*reg52;
    reg47=reg46-reg47; reg46=reg16*reg28; T reg84=var_inter[0]*reg28; reg54=reg43+reg54; reg43=var_inter[1]*reg73;
    T reg85=reg56*reg71; reg74=reg64+reg74; reg64=reg80*var_inter[1]; reg26=pos[2]-reg26; reg46=reg85-reg46;
    T reg86=reg80*reg33; T reg87=reg56*reg73; reg77=reg78-reg77; T reg88=reg16*var_inter[2]; T reg89=var_inter[2]*reg49;
    reg74=reg64+reg74; reg54=reg43+reg54; reg43=var_inter[1]*reg70; reg84=reg26+reg84; reg83=reg47-reg83;
    reg81=reg82-reg81; reg26=reg16*reg33; reg47=reg56*reg49; reg76=reg79-reg76; reg77=reg77/reg83;
    reg26=reg47-reg26; reg74=reg88+reg74; reg64=var_inter[2]*reg71; reg54=reg89+reg54; reg42=reg42/reg83;
    reg86=reg87-reg86; reg84=reg43+reg84; reg68=reg68/reg83; reg46=reg46/reg83; reg81=reg81/reg83;
    reg76=reg76/reg83; reg42=reg42*reg54; reg81=reg74*reg81; reg26=reg26/reg83; reg46=reg46*reg54;
    reg86=reg86/reg83; reg76=reg74*reg76; reg77=reg77*reg54; reg84=reg64+reg84; reg68=reg74*reg68;
    reg83=reg52/reg83; reg86=reg84*reg86; reg76=reg77-reg76; reg46=reg81-reg46; reg26=reg84*reg26;
    reg83=reg83*reg84; reg68=reg42-reg68; var_inter[1]=reg26+reg46; var_inter[2]=reg76-reg86; var_inter[0]=reg68-reg83;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*reg0; T reg3=2*var_inter[2];
    T reg4=2*var_inter[1]; T reg5=0.5*var_inter[0]; T reg6=reg1-1; T reg7=reg2-1; T reg8=0.5*reg0;
    reg3=reg3-1; T reg9=0.5*var_inter[1]; T reg10=reg5*reg6; T reg11=reg4-1; T reg12=4*reg3;
    T reg13=reg7*reg8; T reg14=pow(reg3,2); T reg15=reg9*reg11; T reg16=reg5*reg12; T reg17=2*reg10;
    T reg18=reg8*reg12; T reg19=2*reg13; T reg20=reg18-reg19; T reg21=reg16-reg17; reg11=0.5*reg11;
    T reg22=reg9*reg12; T reg23=1-reg3; reg14=1-reg14; T reg24=2*reg15; reg7=0.5*reg7;
    T reg25=pos_nodes[1][2]*reg21; T reg26=reg22-reg24; T reg27=pos_nodes[1][1]*reg21; reg11=var_inter[1]+reg11; T reg28=pos_nodes[0][0]*reg20;
    T reg29=pos_nodes[1][0]*reg21; T reg30=pos_nodes[0][2]*reg20; T reg31=reg13*reg23; T reg32=pos_nodes[0][1]*reg20; reg8=reg8*reg14;
    reg7=reg0+reg7; T reg33=reg23*reg10; reg5=reg5*reg14; reg33=reg33-reg5; reg31=reg31-reg8;
    reg6=0.5*reg6; T reg34=reg23*reg15; reg9=reg14*reg9; T reg35=reg23*reg7; reg3=1+reg3;
    T reg36=reg19+reg18; T reg37=pos_nodes[2][2]*reg26; T reg38=reg23*reg11; reg25=reg30+reg25; reg30=pos_nodes[2][0]*reg26;
    T reg39=0.5*reg14; reg27=reg32+reg27; reg29=reg28+reg29; reg28=pos_nodes[2][1]*reg26; reg38=reg38-reg39;
    reg6=var_inter[0]+reg6; reg32=reg3*reg7; T reg40=pos_nodes[3][1]*reg36; T reg41=reg39-reg35; reg27=reg28+reg27;
    reg28=pos_nodes[1][0]*reg33; T reg42=reg31*pos_nodes[0][0]; T reg43=pos_nodes[3][0]*reg36; reg29=reg30+reg29; reg30=pos_nodes[3][2]*reg36;
    reg25=reg37+reg25; reg13=reg13*reg3; reg34=reg34-reg9; reg37=reg17+reg16; T reg44=pos_nodes[1][1]*reg33;
    T reg45=reg31*pos_nodes[0][1]; T reg46=reg39-reg32; T reg47=pos_nodes[2][0]*reg34; reg30=reg25+reg30; reg25=pos_nodes[4][2]*reg37;
    reg28=reg42+reg28; reg42=pos_nodes[4][0]*reg37; T reg48=pos_nodes[1][2]*reg33; T reg49=pos_nodes[0][0]*reg41; reg43=reg29+reg43;
    reg29=reg31*pos_nodes[0][2]; T reg50=pos_nodes[2][1]*reg38; T reg51=pos_nodes[2][2]*reg38; T reg52=reg24+reg22; reg11=reg3*reg11;
    T reg53=pos_nodes[2][0]*reg38; T reg54=pos_nodes[0][1]*reg41; T reg55=pos_nodes[4][1]*reg37; reg40=reg27+reg40; reg27=reg2*var_inter[0];
    reg44=reg45+reg44; reg45=pos_nodes[0][2]*reg41; T reg56=pos_nodes[2][1]*reg34; reg10=reg3*reg10; reg8=reg13-reg8;
    reg13=reg23*reg6; T reg57=2*reg27; T reg58=var_inter[1]*reg1; T reg59=reg8*pos_nodes[3][1]; reg55=reg40+reg55;
    reg40=pos_nodes[5][1]*reg52; reg44=reg56+reg44; reg25=reg30+reg25; reg11=reg11-reg39; reg30=pos_nodes[5][2]*reg52;
    reg56=pos_nodes[3][1]*reg46; reg53=reg49+reg53; reg5=reg10-reg5; reg10=pos_nodes[3][0]*reg46; reg28=reg47+reg28;
    reg47=reg8*pos_nodes[3][0]; reg48=reg29+reg48; reg29=pos_nodes[3][2]*reg46; reg13=reg13-reg39; T reg60=pos_nodes[5][0]*reg52;
    reg42=reg43+reg42; reg43=pos_nodes[2][2]*reg34; reg15=reg3*reg15; reg50=reg54+reg50; reg51=reg45+reg51;
    reg30=reg25+reg30; reg25=pos_nodes[6][2]*reg57; T reg61=reg5*pos_nodes[4][1]; reg59=reg44+reg59; reg47=reg28+reg47;
    reg28=2*reg58; reg44=reg5*pos_nodes[4][0]; T reg62=pos_nodes[6][0]*reg57; reg60=reg42+reg60; reg42=reg0*reg4;
    reg9=reg15-reg9; reg6=reg3*reg6; reg48=reg43+reg48; reg15=reg8*pos_nodes[3][2]; reg43=pos_nodes[1][0]*reg13;
    T reg63=pos_nodes[5][1]*reg11; reg50=reg56+reg50; reg51=reg29+reg51; T reg64=pos_nodes[5][2]*reg11; reg40=reg55+reg40;
    reg55=pos_nodes[6][1]*reg57; T reg65=reg23*reg1; reg53=reg10+reg53; T reg66=pos_nodes[5][0]*reg11; T reg67=pos_nodes[1][1]*reg13;
    T reg68=pos_nodes[6][2]*reg65; T reg69=reg23*reg27; reg25=reg30-reg25; reg30=reg5*pos_nodes[4][2]; reg63=reg50+reg63;
    reg50=pos_nodes[6][1]*reg65; reg62=reg60-reg62; reg60=pos_nodes[7][0]*reg28; T reg70=pos_nodes[1][2]*reg13; reg15=reg48+reg15;
    reg43=reg49+reg43; reg48=pos_nodes[7][2]*reg28; reg61=reg59+reg61; reg49=reg9*pos_nodes[5][1]; reg59=reg2-reg1;
    reg6=reg6-reg39; T reg71=pos_nodes[7][1]*reg28; reg66=reg53+reg66; reg2=reg2-reg4; reg53=2*reg42;
    T reg72=pos_nodes[6][0]*reg65; T reg73=reg9*pos_nodes[5][0]; reg55=reg40-reg55; reg44=reg47+reg44; reg67=reg54+reg67;
    reg64=reg51+reg64; reg40=reg69*pos_nodes[6][0]; reg73=reg44+reg73; reg49=reg61+reg49; reg44=reg69*pos_nodes[6][1];
    reg47=pos_nodes[8][1]*reg53; reg56=reg67+reg56; reg51=pos_nodes[4][1]*reg6; reg70=reg45+reg70; reg45=pos_nodes[7][1]*reg65;
    reg50=reg63-reg50; reg54=pos_nodes[7][2]*reg65; reg68=reg64-reg68; reg71=reg55-reg71; reg55=reg23*reg58;
    reg61=pos_nodes[4][0]*reg6; reg63=pos_nodes[8][2]*reg53; reg48=reg25-reg48; reg25=reg23*reg2; reg10=reg43+reg10;
    reg60=reg62-reg60; reg43=pos_nodes[8][0]*reg53; reg62=pos_nodes[7][0]*reg65; reg64=reg23*reg59; reg30=reg15+reg30;
    reg15=reg9*pos_nodes[5][2]; reg72=reg66-reg72; reg51=reg56+reg51; reg56=pos_nodes[6][1]*reg64; reg66=pos_nodes[7][1]*reg55;
    reg67=reg3*reg1; reg63=reg48-reg63; reg47=reg71-reg47; reg45=reg50+reg45; reg48=pos_nodes[8][1]*reg25;
    reg50=pos_nodes[4][2]*reg6; reg29=reg70+reg29; reg70=pos_nodes[6][0]*reg64; reg61=reg10+reg61; reg10=pos_nodes[9][1]*reg57;
    reg71=reg23*reg4; reg15=reg30+reg15; reg30=reg69*pos_nodes[6][2]; reg62=reg72+reg62; reg72=pos_nodes[8][0]*reg25;
    reg44=reg49+reg44; reg23=reg23*reg42; reg49=pos_nodes[9][2]*reg57; reg43=reg60-reg43; reg54=reg68+reg54;
    reg60=pos_nodes[8][2]*reg25; reg68=pos_nodes[9][0]*reg57; reg40=reg73+reg40; reg73=reg55*pos_nodes[7][0]; reg70=reg61+reg70;
    reg30=reg15+reg30; reg48=reg45+reg48; reg15=pos_nodes[9][1]*reg67; reg50=reg29+reg50; reg29=pos_nodes[7][2]*reg55;
    reg45=reg23*pos_nodes[8][0]; reg73=reg40+reg73; reg43=reg68+reg43; reg40=pos_nodes[10][0]*reg28; reg72=reg62+reg72;
    reg56=reg51+reg56; reg51=pos_nodes[7][1]*reg71; reg61=pos_nodes[9][0]*reg67; reg63=reg49+reg63; reg49=pos_nodes[10][2]*reg28;
    reg66=reg44+reg66; reg44=reg23*pos_nodes[8][1]; reg60=reg54+reg60; reg54=pos_nodes[6][2]*reg64; reg62=pos_nodes[10][1]*reg28;
    reg47=reg10+reg47; reg10=pos_nodes[9][2]*reg67; reg27=reg3*reg27; reg68=pos_nodes[7][0]*reg71; reg44=reg66+reg44;
    reg66=pos_nodes[11][1]*reg53; reg62=reg47+reg62; reg29=reg30+reg29; reg30=reg27*pos_nodes[9][1]; reg47=reg23*pos_nodes[8][2];
    reg58=reg3*reg58; T reg74=reg27*pos_nodes[9][0]; T reg75=pos_nodes[11][0]*reg53; reg40=reg43+reg40; reg43=reg0*reg12;
    reg45=reg73+reg45; reg73=pos_nodes[10][0]*reg67; T reg76=pos_nodes[10][2]*reg67; reg10=reg60-reg10; reg61=reg72-reg61;
    reg2=reg3*reg2; reg51=reg56+reg51; reg56=pos_nodes[8][1]*reg71; reg49=reg63+reg49; reg59=reg3*reg59;
    reg60=pos_nodes[10][1]*reg67; reg15=reg48-reg15; reg68=reg70+reg68; reg48=pos_nodes[8][0]*reg71; reg63=pos_nodes[11][2]*reg53;
    reg54=reg50+reg54; reg50=pos_nodes[7][2]*reg71; reg63=reg49+reg63; reg49=pos_nodes[12][2]*reg43; reg70=reg27*pos_nodes[9][2];
    reg76=reg10+reg76; reg10=pos_nodes[11][2]*reg2; reg72=pos_nodes[8][2]*reg71; reg50=reg54+reg50; reg44=reg30+reg44;
    reg47=reg29+reg47; reg29=reg58*pos_nodes[10][1]; reg60=reg15+reg60; reg15=pos_nodes[11][1]*reg2; reg30=pos_nodes[9][0]*reg59;
    reg54=reg3*reg4; T reg77=var_inter[0]*reg12; reg42=reg3*reg42; reg66=reg62+reg66; reg75=reg40+reg75;
    reg56=reg51-reg56; reg3=pos_nodes[9][1]*reg59; reg48=reg68-reg48; reg40=pos_nodes[12][0]*reg43; reg51=pos_nodes[11][0]*reg2;
    reg45=reg74+reg45; reg62=reg58*pos_nodes[10][0]; reg68=pos_nodes[12][1]*reg43; reg73=reg61+reg73; reg61=reg14*pos_nodes[12][2];
    reg74=pos_nodes[10][1]*reg54; reg56=reg3+reg56; reg48=reg30+reg48; reg3=pos_nodes[10][0]*reg54; reg49=reg63-reg49;
    reg30=pos_nodes[13][2]*reg77; reg63=reg42*pos_nodes[11][0]; reg62=reg45+reg62; reg10=reg76+reg10; reg45=reg14*pos_nodes[12][0];
    reg76=pos_nodes[13][1]*reg77; reg68=reg66-reg68; reg29=reg44+reg29; reg44=reg42*pos_nodes[11][1]; reg51=reg73+reg51;
    reg66=reg58*pos_nodes[10][2]; reg47=reg70+reg47; reg70=pos_nodes[9][2]*reg59; reg73=var_inter[1]*reg12; reg15=reg60+reg15;
    reg0=reg0*reg14; reg60=reg14*pos_nodes[12][1]; reg72=reg50-reg72; reg40=reg75-reg40; reg50=pos_nodes[13][0]*reg77;
    reg75=pos_nodes[14][0]*reg73; reg50=reg40-reg50; reg3=reg48+reg3; reg40=reg14*pos_nodes[14][0]; reg51=reg51-reg45;
    reg48=reg14*pos_nodes[14][2]; T reg78=pos_nodes[11][0]*reg54; T reg79=pos_nodes[14][1]*reg73; reg76=reg68-reg76; reg44=reg29+reg44;
    reg29=reg0*pos_nodes[12][1]; reg68=reg42*pos_nodes[11][2]; reg66=reg47+reg66; reg47=reg14*pos_nodes[14][1]; reg15=reg15-reg60;
    T reg80=var_inter[0]*reg14; reg72=reg70+reg72; reg70=pos_nodes[10][2]*reg54; T reg81=pos_nodes[11][1]*reg54; reg74=reg56+reg74;
    reg56=pos_nodes[14][2]*reg73; reg30=reg49-reg30; reg49=reg0*pos_nodes[12][0]; reg63=reg62+reg63; reg10=reg10-reg61;
    reg62=var_inter[1]*reg14; reg56=reg30-reg56; reg68=reg66+reg68; reg78=reg3-reg78; reg3=reg0*pos_nodes[12][2];
    reg81=reg74-reg81; reg70=reg72+reg70; reg30=pos_nodes[11][2]*reg54; reg47=reg15+reg47; reg15=reg80*pos_nodes[13][1];
    reg29=reg44+reg29; reg79=reg76-reg79; reg44=reg80*pos_nodes[13][0]; reg49=reg63+reg49; reg48=reg10+reg48;
    reg75=reg50-reg75; reg40=reg51+reg40; reg10=reg75*reg48; reg50=pos_nodes[13][2]*reg80; reg3=reg68+reg3;
    reg15=reg29+reg15; reg29=reg62*pos_nodes[14][1]; reg51=reg14*pos_nodes[13][1]; reg60=reg81-reg60; reg63=reg47*reg56;
    reg66=reg40*reg56; reg68=reg79*reg48; reg30=reg70-reg30; reg45=reg78-reg45; reg70=reg14*pos_nodes[13][0];
    reg44=reg49+reg44; reg49=reg62*pos_nodes[14][0]; reg68=reg63-reg68; reg72=reg40*reg79; reg70=reg45+reg70;
    reg10=reg66-reg10; reg45=reg75*reg47; reg74=reg62*pos_nodes[14][2]; reg50=reg3+reg50; reg61=reg30-reg61;
    reg51=reg60+reg51; reg29=reg15+reg29; reg3=pos_nodes[13][2]*reg14; reg49=reg44+reg49; reg15=reg70*reg68;
    reg49=pos[0]-reg49; reg3=reg61+reg3; reg29=pos[1]-reg29; reg74=reg50+reg74; reg30=reg51*reg10;
    reg45=reg72-reg45; reg44=var_inter[0]*reg51; reg50=var_inter[0]*reg70; reg60=reg3*reg45; reg61=reg75*reg3;
    reg15=reg30-reg15; reg30=reg51*reg56; reg76=reg79*reg3; reg78=reg70*reg48; reg81=reg51*reg48;
    T reg82=reg47*reg3; T reg83=reg70*reg56; T reg84=reg40*reg3; reg74=pos[2]-reg74; T reg85=var_inter[1]*reg40;
    reg50=reg49+reg50; reg49=var_inter[0]*reg3; reg44=reg29+reg44; reg29=var_inter[1]*reg47; reg61=reg83-reg61;
    T reg86=var_inter[2]*reg75; reg82=reg81-reg82; reg84=reg78-reg84; T reg87=var_inter[2]*reg79; reg76=reg30-reg76;
    reg50=reg85+reg50; reg60=reg15-reg60; reg15=reg70*reg79; reg85=reg40*reg51; reg44=reg29+reg44;
    reg29=var_inter[1]*reg48; reg49=reg74+reg49; reg74=reg70*reg47; T reg88=reg75*reg51; reg85=reg74-reg85;
    reg84=reg84/reg60; reg88=reg15-reg88; reg50=reg86+reg50; reg86=var_inter[2]*reg56; reg44=reg87+reg44;
    reg49=reg29+reg49; reg68=reg68/reg60; reg76=reg76/reg60; reg82=reg82/reg60; reg10=reg10/reg60;
    reg61=reg61/reg60; reg49=reg86+reg49; reg45=reg45/reg60; reg88=reg88/reg60; reg60=reg85/reg60;
    reg68=reg50*reg68; reg10=reg44*reg10; reg84=reg44*reg84; reg76=reg50*reg76; reg61=reg44*reg61;
    reg82=reg50*reg82; reg82=reg84-reg82; reg60=reg49*reg60; reg61=reg76-reg61; reg88=reg49*reg88;
    reg68=reg10-reg68; reg45=reg49*reg45; var_inter[1]+=reg88+reg61; var_inter[0]+=reg68-reg45; var_inter[2]+=reg82-reg60;

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
    T reg0=1-var_inter[0]; T reg1=2*var_inter[2]; reg0=reg0-var_inter[1]; reg1=reg1-1; T reg2=2*reg0;
    T reg3=2*var_inter[0]; T reg4=reg2-1; T reg5=0.5*reg0; T reg6=2*var_inter[1]; T reg7=pow(reg1,2);
    T reg8=0.5*var_inter[0]; T reg9=reg3-1; reg4=reg5*reg4; T reg10=1-reg1; reg7=1-reg7;
    reg9=reg8*reg9; T reg11=0.5*var_inter[1]; T reg12=reg6-1; reg8=reg7*reg8; T reg13=reg10*reg9;
    reg12=reg11*reg12; reg5=reg5*reg7; T reg14=reg4*reg10; reg13=reg13-reg8; reg14=reg14-reg5;
    reg11=reg7*reg11; reg1=1+reg1; T reg15=reg10*reg12; reg15=reg15-reg11; reg4=reg1*reg4;
    reg14=val[0]*reg14; reg13=val[1]*reg13; reg15=val[2]*reg15; reg5=reg4-reg5; reg9=reg1*reg9;
    reg13=reg14+reg13; reg12=reg1*reg12; reg8=reg9-reg8; reg5=val[3]*reg5; reg13=reg15+reg13;
    reg11=reg12-reg11; reg2=var_inter[0]*reg2; reg5=reg13+reg5; reg8=val[4]*reg8; reg11=val[5]*reg11;
    reg4=reg10*reg2; reg3=var_inter[1]*reg3; reg8=reg5+reg8; reg11=reg8+reg11; reg4=val[6]*reg4;
    reg5=reg10*reg3; reg6=reg0*reg6; reg5=val[7]*reg5; reg10=reg10*reg6; reg4=reg11+reg4;
    reg5=reg4+reg5; reg10=val[8]*reg10; reg2=reg1*reg2; reg2=val[9]*reg2; reg3=reg1*reg3;
    reg10=reg5+reg10; reg2=reg10+reg2; reg3=val[10]*reg3; reg6=reg1*reg6; reg6=val[11]*reg6;
    reg0=reg0*reg7; reg3=reg2+reg3; reg0=val[12]*reg0; reg1=var_inter[0]*reg7; reg6=reg3+reg6;
    reg1=val[13]*reg1; reg7=var_inter[1]*reg7; reg0=reg6+reg0; reg1=reg0+reg1; reg7=val[14]*reg7;
    res=reg1+reg7;

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
