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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*reg0; T reg3=2*var_inter[2];
    T reg4=2*var_inter[1]; T reg5=reg1-1; T reg6=0.5*reg0; reg3=reg3-1; T reg7=0.5*var_inter[0];
    T reg8=reg2-1; T reg9=reg4-1; T reg10=reg7*reg5; T reg11=0.5*var_inter[1]; T reg12=4*reg3;
    T reg13=reg6*reg8; T reg14=reg12*reg6; T reg15=pow(reg3,2); T reg16=2*reg13; T reg17=reg11*reg9;
    T reg18=2*reg10; T reg19=reg7*reg12; reg9=0.5*reg9; T reg20=reg14-reg16; T reg21=reg19-reg18;
    T reg22=2*reg17; T reg23=reg11*reg12; reg8=0.5*reg8; T reg24=1-reg3; reg15=1-reg15;
    T reg25=pos_nodes[0][0]*reg20; T reg26=pos_nodes[1][0]*reg21; T reg27=reg13*reg24; T reg28=reg23-reg22; T reg29=pos_nodes[1][1]*reg21;
    reg6=reg15*reg6; T reg30=pos_nodes[0][1]*reg20; T reg31=pos_nodes[0][2]*reg20; T reg32=pos_nodes[1][2]*reg21; reg9=var_inter[1]+reg9;
    reg8=reg8+reg0; T reg33=reg24*reg10; reg7=reg15*reg7; T reg34=reg16+reg14; T reg35=pos_nodes[2][1]*reg28;
    reg29=reg30+reg29; reg26=reg25+reg26; reg25=pos_nodes[2][0]*reg28; reg30=reg24*reg8; T reg36=0.5*reg15;
    reg5=0.5*reg5; reg32=reg31+reg32; reg31=pos_nodes[2][2]*reg28; T reg37=reg24*reg9; reg3=1+reg3;
    reg11=reg15*reg11; T reg38=reg24*reg17; reg27=reg27-reg6; reg33=reg33-reg7; T reg39=reg36-reg30;
    reg38=reg38-reg11; reg13=reg13*reg3; T reg40=pos_nodes[1][0]*reg33; T reg41=pos_nodes[0][0]*reg27; T reg42=pos_nodes[3][0]*reg34;
    reg5=var_inter[0]+reg5; T reg43=reg3*reg8; T reg44=pos_nodes[1][1]*reg33; T reg45=pos_nodes[0][1]*reg27; T reg46=reg18+reg19;
    T reg47=pos_nodes[3][1]*reg34; reg35=reg29+reg35; reg37=reg37-reg36; reg29=pos_nodes[3][2]*reg34; reg31=reg32+reg31;
    reg25=reg26+reg25; reg26=pos_nodes[2][0]*reg37; reg40=reg41+reg40; reg9=reg3*reg9; reg32=reg22+reg23;
    reg41=pos_nodes[4][0]*reg46; T reg48=pos_nodes[0][0]*reg39; reg42=reg25+reg42; reg25=reg36-reg43; T reg49=pos_nodes[2][2]*reg37;
    reg6=reg13-reg6; reg10=reg10*reg3; reg13=var_inter[0]*reg2; reg29=reg31+reg29; reg31=pos_nodes[4][2]*reg46;
    T reg50=pos_nodes[0][2]*reg39; T reg51=pos_nodes[2][1]*reg38; reg44=reg45+reg44; reg45=pos_nodes[4][1]*reg46; reg47=reg35+reg47;
    reg35=pos_nodes[2][1]*reg37; T reg52=pos_nodes[2][0]*reg38; T reg53=reg24*reg5; T reg54=pos_nodes[0][2]*reg27; T reg55=pos_nodes[1][2]*reg33;
    T reg56=pos_nodes[0][1]*reg39; reg49=reg50+reg49; reg52=reg40+reg52; reg40=reg6*pos_nodes[3][0]; T reg57=pos_nodes[2][2]*reg38;
    reg26=reg48+reg26; T reg58=pos_nodes[5][0]*reg32; reg31=reg29+reg31; reg29=pos_nodes[5][2]*reg32; T reg59=pos_nodes[3][2]*reg25;
    reg41=reg42+reg41; reg55=reg54+reg55; reg42=pos_nodes[3][1]*reg25; reg54=reg6*pos_nodes[3][1]; reg51=reg44+reg51;
    reg44=pos_nodes[5][1]*reg32; reg45=reg47+reg45; reg47=2*reg13; reg35=reg56+reg35; reg9=reg9-reg36;
    reg53=reg53-reg36; T reg60=pos_nodes[3][0]*reg25; reg7=reg10-reg7; reg17=reg17*reg3; reg10=var_inter[1]*reg1;
    T reg61=pos_nodes[1][1]*reg53; reg57=reg55+reg57; reg55=reg6*pos_nodes[3][2]; T reg62=pos_nodes[5][2]*reg9; reg49=reg59+reg49;
    reg11=reg17-reg11; reg17=2*reg10; T reg63=pos_nodes[6][2]*reg47; T reg64=reg4*reg0; reg29=reg31+reg29;
    reg31=reg7*pos_nodes[4][0]; reg40=reg52+reg40; reg52=pos_nodes[1][0]*reg53; reg5=reg3*reg5; reg58=reg41+reg58;
    reg41=pos_nodes[6][0]*reg47; T reg65=pos_nodes[5][0]*reg9; reg26=reg60+reg26; reg44=reg45+reg44; reg45=pos_nodes[5][1]*reg9;
    T reg66=pos_nodes[6][1]*reg47; reg35=reg42+reg35; reg54=reg51+reg54; reg51=reg7*pos_nodes[4][1]; T reg67=reg24*reg1;
    reg66=reg44-reg66; reg5=reg5-reg36; reg44=pos_nodes[7][0]*reg17; T reg68=pos_nodes[1][2]*reg53; T reg69=pos_nodes[7][1]*reg17;
    reg31=reg40+reg31; reg40=reg11*pos_nodes[5][0]; T reg70=pos_nodes[6][1]*reg67; reg45=reg35+reg45; reg63=reg29-reg63;
    reg29=pos_nodes[7][2]*reg17; reg35=reg7*pos_nodes[4][2]; reg55=reg57+reg55; reg51=reg54+reg51; reg54=reg11*pos_nodes[5][1];
    reg61=reg56+reg61; reg56=pos_nodes[6][0]*reg67; reg52=reg48+reg52; reg48=2*reg64; reg57=reg24*reg13;
    reg62=reg49+reg62; reg49=pos_nodes[6][2]*reg67; reg65=reg26+reg65; reg26=reg2-reg4; reg41=reg58-reg41;
    reg2=reg2-reg1; reg40=reg31+reg40; reg31=reg57*pos_nodes[6][0]; reg70=reg45-reg70; reg56=reg65-reg56;
    reg45=pos_nodes[7][0]*reg67; reg58=reg24*reg10; reg65=pos_nodes[4][1]*reg5; reg29=reg63-reg29; reg63=reg11*pos_nodes[5][2];
    reg35=reg55+reg35; reg42=reg61+reg42; reg55=pos_nodes[7][2]*reg67; reg61=reg57*pos_nodes[6][1]; reg54=reg51+reg54;
    reg51=pos_nodes[8][2]*reg48; reg49=reg62-reg49; reg62=reg24*reg26; reg69=reg66-reg69; reg68=reg50+reg68;
    reg50=reg24*reg2; reg66=pos_nodes[8][1]*reg48; T reg71=pos_nodes[8][0]*reg48; reg60=reg52+reg60; reg52=pos_nodes[4][0]*reg5;
    reg44=reg41-reg44; reg41=pos_nodes[7][1]*reg67; reg66=reg69-reg66; reg61=reg54+reg61; reg54=pos_nodes[7][1]*reg58;
    reg69=pos_nodes[6][1]*reg50; T reg72=reg1*reg3; T reg73=pos_nodes[8][2]*reg62; T reg74=pos_nodes[8][0]*reg62; reg45=reg56+reg45;
    reg56=pos_nodes[9][1]*reg47; T reg75=pos_nodes[8][1]*reg62; reg41=reg70+reg41; reg71=reg44-reg71; reg44=pos_nodes[9][0]*reg47;
    reg70=pos_nodes[4][2]*reg5; reg59=reg68+reg59; reg68=reg57*pos_nodes[6][2]; reg63=reg35+reg63; reg35=reg24*reg4;
    reg52=reg60+reg52; reg60=pos_nodes[6][0]*reg50; reg31=reg40+reg31; reg40=reg58*pos_nodes[7][0]; reg24=reg24*reg64;
    reg65=reg42+reg65; reg55=reg49+reg55; reg42=pos_nodes[9][2]*reg47; reg51=reg29-reg51; reg29=pos_nodes[10][1]*reg17;
    reg56=reg66+reg56; reg54=reg61+reg54; reg49=reg24*pos_nodes[8][1]; reg68=reg63+reg68; reg13=reg3*reg13;
    reg61=pos_nodes[7][1]*reg35; reg70=reg59+reg70; reg59=pos_nodes[6][2]*reg50; reg63=pos_nodes[10][0]*reg17; reg44=reg71+reg44;
    reg69=reg65+reg69; reg60=reg52+reg60; reg73=reg55+reg73; reg52=pos_nodes[9][2]*reg72; reg55=pos_nodes[9][0]*reg72;
    reg74=reg45+reg74; reg45=pos_nodes[7][2]*reg58; reg65=reg24*pos_nodes[8][0]; reg40=reg31+reg40; reg31=pos_nodes[7][0]*reg35;
    reg75=reg41+reg75; reg41=pos_nodes[9][1]*reg72; reg42=reg51+reg42; reg51=pos_nodes[10][2]*reg17; reg66=reg13*pos_nodes[9][1];
    reg71=pos_nodes[7][2]*reg35; reg59=reg70+reg59; reg49=reg54+reg49; reg10=reg3*reg10; reg54=pos_nodes[11][2]*reg48;
    reg70=pos_nodes[10][2]*reg72; reg52=reg73-reg52; reg29=reg56+reg29; reg51=reg42+reg51; reg42=pos_nodes[11][0]*reg48;
    reg56=pos_nodes[8][1]*reg35; reg73=reg12*reg0; reg31=reg60+reg31; reg60=pos_nodes[8][0]*reg35; reg61=reg69+reg61;
    reg2=reg3*reg2; reg63=reg44+reg63; reg41=reg75-reg41; reg44=pos_nodes[10][1]*reg72; reg45=reg68+reg45;
    reg68=reg24*pos_nodes[8][2]; reg65=reg40+reg65; reg40=pos_nodes[10][0]*reg72; reg69=reg13*pos_nodes[9][0]; reg55=reg74-reg55;
    reg26=reg3*reg26; reg74=pos_nodes[11][1]*reg48; reg75=pos_nodes[12][0]*reg73; T reg76=reg4*reg3; reg63=reg42+reg63;
    reg69=reg65+reg69; reg71=reg59+reg71; reg42=pos_nodes[8][2]*reg35; reg59=var_inter[0]*reg12; reg60=reg31-reg60;
    reg31=pos_nodes[9][0]*reg2; reg65=pos_nodes[11][2]*reg26; reg64=reg3*reg64; reg3=reg13*pos_nodes[9][2]; reg68=reg45+reg68;
    reg40=reg55+reg40; reg70=reg52+reg70; reg45=pos_nodes[11][0]*reg26; reg51=reg54+reg51; reg52=pos_nodes[12][2]*reg73;
    reg29=reg74+reg29; reg54=pos_nodes[12][1]*reg73; reg44=reg41+reg44; reg41=pos_nodes[11][1]*reg26; reg55=pos_nodes[9][1]*reg2;
    reg56=reg61-reg56; reg66=reg49+reg66; reg49=reg10*pos_nodes[10][0]; reg61=reg10*pos_nodes[10][1]; reg49=reg69+reg49;
    reg52=reg51-reg52; reg70=reg65+reg70; reg54=reg29-reg54; reg40=reg45+reg40; reg29=pos_nodes[13][1]*reg59;
    reg44=reg41+reg44; reg41=reg64*pos_nodes[11][1]; reg3=reg68+reg3; reg45=reg15*pos_nodes[12][0]; reg51=reg10*pos_nodes[10][2];
    reg65=pos_nodes[10][0]*reg76; reg75=reg63-reg75; reg63=pos_nodes[13][0]*reg59; reg55=reg56+reg55; reg42=reg71-reg42;
    reg56=pos_nodes[9][2]*reg2; reg68=var_inter[1]*reg12; reg69=pos_nodes[10][1]*reg76; reg71=reg64*pos_nodes[11][0]; reg74=reg15*pos_nodes[12][1];
    T reg77=reg15*pos_nodes[12][2]; reg31=reg60+reg31; reg60=pos_nodes[13][2]*reg59; reg61=reg66+reg61; reg0=reg15*reg0;
    reg66=reg64*pos_nodes[11][2]; T reg78=pos_nodes[14][2]*reg68; reg60=reg52-reg60; reg51=reg3+reg51; reg3=pos_nodes[11][1]*reg76;
    reg69=reg55+reg69; reg44=reg44-reg74; reg52=reg15*pos_nodes[14][1]; reg55=reg0*pos_nodes[12][0]; reg29=reg54-reg29;
    reg54=pos_nodes[14][1]*reg68; reg49=reg71+reg49; reg61=reg41+reg61; reg41=reg0*pos_nodes[12][1]; reg71=pos_nodes[14][0]*reg68;
    reg63=reg75-reg63; reg75=var_inter[0]*reg15; T reg79=reg15*pos_nodes[14][2]; reg70=reg70-reg77; reg65=reg31+reg65;
    reg31=pos_nodes[11][0]*reg76; T reg80=pos_nodes[10][2]*reg76; reg56=reg42+reg56; reg40=reg40-reg45; reg42=reg15*pos_nodes[14][0];
    reg31=reg65-reg31; reg71=reg63-reg71; reg51=reg66+reg51; reg63=reg0*pos_nodes[12][2]; reg65=var_inter[1]*reg15;
    reg55=reg49+reg55; reg49=reg75*pos_nodes[13][0]; reg42=reg40+reg42; reg79=reg70+reg79; reg40=pos_nodes[11][2]*reg76;
    reg80=reg56+reg80; reg56=reg75*pos_nodes[13][1]; reg41=reg61+reg41; reg54=reg29-reg54; reg52=reg44+reg52;
    reg3=reg69-reg3; reg78=reg60-reg78; reg29=reg71*reg79; reg44=reg42*reg78; reg60=reg54*reg79;
    reg61=reg52*reg78; reg66=reg75*pos_nodes[13][2]; reg63=reg51+reg63; reg40=reg80-reg40; reg74=reg3-reg74;
    reg45=reg31-reg45; reg3=reg15*pos_nodes[13][1]; reg49=reg55+reg49; reg31=reg65*pos_nodes[14][0]; reg56=reg41+reg56;
    reg41=reg15*pos_nodes[13][0]; reg51=reg65*pos_nodes[14][1]; reg55=reg15*pos_nodes[13][2]; reg69=reg71*reg52; reg29=reg44-reg29;
    reg3=reg74+reg3; reg41=reg45+reg41; reg45=reg42*reg54; reg60=reg61-reg60; reg31=reg49+reg31;
    reg77=reg40-reg77; reg40=reg65*pos_nodes[14][2]; reg51=reg56+reg51; reg66=reg63+reg66; reg69=reg45-reg69;
    reg40=reg66+reg40; reg49=reg3*reg29; reg56=var_inter[0]*reg41; reg63=reg41*reg60; reg51=pos[1]-reg51;
    reg31=pos[0]-reg31; reg55=reg77+reg55; reg66=var_inter[0]*reg3; reg70=reg41*reg78; reg74=reg52*reg55;
    reg77=reg71*reg55; reg80=reg3*reg79; T reg81=reg54*reg55; T reg82=reg3*reg78; T reg83=reg41*reg79;
    T reg84=reg42*reg55; T reg85=reg55*reg69; reg63=reg49-reg63; reg49=var_inter[1]*reg52; reg66=reg51+reg66;
    reg40=pos[2]-reg40; reg51=var_inter[1]*reg42; T reg86=var_inter[0]*reg55; reg56=reg31+reg56; reg84=reg83-reg84;
    reg31=reg41*reg54; T reg87=reg71*reg3; reg77=reg70-reg77; T reg88=reg41*reg52; T reg89=reg42*reg3;
    T reg90=var_inter[2]*reg54; reg56=reg51+reg56; reg66=reg49+reg66; reg49=var_inter[1]*reg79; reg86=reg40+reg86;
    reg40=var_inter[2]*reg71; reg74=reg80-reg74; reg81=reg82-reg81; reg85=reg63-reg85; reg60=reg60/reg85;
    reg84=reg84/reg85; reg74=reg74/reg85; reg86=reg49+reg86; reg77=reg77/reg85; reg87=reg31-reg87;
    reg56=reg40+reg56; reg81=reg81/reg85; reg40=var_inter[2]*reg78; reg89=reg88-reg89; reg29=reg29/reg85;
    reg66=reg90+reg66; reg84=reg66*reg84; reg74=reg56*reg74; reg77=reg66*reg77; reg81=reg56*reg81;
    reg29=reg66*reg29; reg60=reg56*reg60; reg89=reg89/reg85; reg87=reg87/reg85; reg86=reg40+reg86;
    reg85=reg69/reg85; reg87=reg86*reg87; reg77=reg81-reg77; reg60=reg29-reg60; reg89=reg86*reg89;
    reg74=reg84-reg74; reg85=reg86*reg85; var_inter[0]=reg60-reg85; var_inter[1]=reg87+reg77; var_inter[2]=reg74-reg89;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*var_inter[2]; T reg3=2*reg0;
    reg2=reg2-1; T reg4=0.5*reg0; T reg5=reg1-1; T reg6=0.5*var_inter[0]; T reg7=2*var_inter[1];
    T reg8=reg3-1; T reg9=0.5*var_inter[1]; T reg10=reg7-1; T reg11=4*reg2; T reg12=reg6*reg5;
    T reg13=reg4*reg8; T reg14=reg9*reg10; T reg15=reg11*reg6; T reg16=pow(reg2,2); T reg17=2*reg12;
    T reg18=2*reg13; T reg19=reg4*reg11; T reg20=reg19-reg18; reg10=0.5*reg10; T reg21=reg15-reg17;
    T reg22=reg11*reg9; T reg23=2*reg14; reg16=1-reg16; reg8=0.5*reg8; T reg24=1-reg2;
    reg10=reg10+var_inter[1]; T reg25=reg21*pos_nodes[1][2]; T reg26=reg20*pos_nodes[0][2]; T reg27=reg22-reg23; T reg28=reg21*pos_nodes[1][0];
    T reg29=reg20*pos_nodes[0][0]; reg6=reg16*reg6; T reg30=reg24*reg12; reg4=reg4*reg16; T reg31=reg13*reg24;
    T reg32=reg21*pos_nodes[1][1]; T reg33=reg20*pos_nodes[0][1]; reg8=reg0+reg8; T reg34=0.5*reg16; reg5=0.5*reg5;
    T reg35=reg8*reg24; reg26=reg25+reg26; reg25=reg27*pos_nodes[2][2]; reg2=1+reg2; reg9=reg16*reg9;
    T reg36=reg10*reg24; T reg37=reg18+reg19; T reg38=reg24*reg14; reg33=reg32+reg33; reg32=reg27*pos_nodes[2][1];
    reg30=reg30-reg6; T reg39=reg27*pos_nodes[2][0]; reg29=reg28+reg29; reg31=reg31-reg4; reg28=reg31*pos_nodes[0][0];
    T reg40=reg30*pos_nodes[1][0]; T reg41=pos_nodes[3][1]*reg37; reg32=reg33+reg32; reg13=reg13*reg2; reg36=reg36-reg34;
    reg33=reg34-reg35; T reg42=reg8*reg2; reg38=reg38-reg9; reg39=reg29+reg39; reg29=pos_nodes[3][2]*reg37;
    T reg43=pos_nodes[3][0]*reg37; T reg44=reg17+reg15; T reg45=reg31*pos_nodes[0][1]; T reg46=reg30*pos_nodes[1][1]; reg25=reg26+reg25;
    reg5=reg5+var_inter[0]; reg43=reg39+reg43; reg4=reg13-reg4; reg12=reg12*reg2; reg13=pos_nodes[4][0]*reg44;
    reg26=reg23+reg22; reg41=reg32+reg41; reg32=reg33*pos_nodes[0][2]; reg39=pos_nodes[4][1]*reg44; T reg47=reg36*pos_nodes[2][1];
    T reg48=pos_nodes[4][2]*reg44; T reg49=reg33*pos_nodes[0][1]; T reg50=reg38*pos_nodes[2][1]; reg45=reg46+reg45; reg46=reg33*pos_nodes[0][0];
    reg29=reg25+reg29; reg25=reg38*pos_nodes[2][0]; T reg51=reg5*reg24; reg28=reg40+reg28; reg10=reg10*reg2;
    reg40=reg3*var_inter[0]; T reg52=reg36*pos_nodes[2][0]; T reg53=reg31*pos_nodes[0][2]; T reg54=reg30*pos_nodes[1][2]; T reg55=reg36*pos_nodes[2][2];
    T reg56=reg34-reg42; T reg57=reg38*pos_nodes[2][2]; reg53=reg54+reg53; reg54=pos_nodes[3][1]*reg56; T reg58=pos_nodes[3][2]*reg56;
    T reg59=pos_nodes[3][0]*reg4; reg13=reg43+reg13; reg47=reg49+reg47; reg25=reg28+reg25; reg55=reg32+reg55;
    reg28=pos_nodes[3][1]*reg4; reg50=reg45+reg50; reg43=pos_nodes[3][0]*reg56; reg45=pos_nodes[5][2]*reg26; reg51=reg51-reg34;
    reg14=reg14*reg2; reg6=reg12-reg6; reg10=reg10-reg34; reg12=reg1*var_inter[1]; reg52=reg46+reg52;
    reg39=reg41+reg39; reg48=reg29+reg48; reg29=pos_nodes[5][0]*reg26; reg41=2*reg40; T reg60=pos_nodes[5][1]*reg26;
    T reg61=reg51*pos_nodes[1][0]; T reg62=reg51*pos_nodes[1][1]; reg57=reg53+reg57; reg55=reg58+reg55; reg53=pos_nodes[4][0]*reg6;
    reg59=reg25+reg59; reg5=reg5*reg2; reg9=reg14-reg9; reg14=2*reg12; reg25=reg24*reg1;
    reg47=reg54+reg47; T reg63=pos_nodes[6][0]*reg41; reg13=reg29+reg13; reg29=pos_nodes[5][1]*reg10; reg39=reg60+reg39;
    reg60=pos_nodes[6][1]*reg41; T reg64=pos_nodes[4][1]*reg6; T reg65=pos_nodes[5][2]*reg10; T reg66=reg0*reg7; reg52=reg43+reg52;
    reg48=reg45+reg48; reg45=pos_nodes[5][0]*reg10; T reg67=pos_nodes[6][2]*reg41; reg28=reg50+reg28; reg50=pos_nodes[3][2]*reg4;
    reg64=reg28+reg64; reg49=reg62+reg49; reg28=pos_nodes[5][1]*reg9; reg62=reg40*reg24; T reg68=reg14*pos_nodes[7][1];
    reg60=reg39-reg60; reg39=reg51*pos_nodes[1][2]; reg47=reg29+reg47; reg29=pos_nodes[6][1]*reg25; reg5=reg5-reg34;
    T reg69=reg3-reg1; reg46=reg61+reg46; reg3=reg3-reg7; reg52=reg45+reg52; reg45=pos_nodes[6][0]*reg25;
    reg61=pos_nodes[6][2]*reg25; reg67=reg48-reg67; reg48=reg14*pos_nodes[7][2]; T reg70=2*reg66; reg55=reg65+reg55;
    reg63=reg13-reg63; reg13=pos_nodes[7][0]*reg14; reg65=pos_nodes[5][0]*reg9; reg53=reg59+reg53; reg59=pos_nodes[4][2]*reg6;
    reg50=reg57+reg50; reg29=reg47-reg29; reg47=reg25*pos_nodes[7][1]; reg64=reg28+reg64; reg28=pos_nodes[6][1]*reg62;
    reg32=reg39+reg32; reg54=reg49+reg54; reg53=reg65+reg53; reg39=pos_nodes[8][2]*reg70; reg49=pos_nodes[8][1]*reg70;
    reg68=reg60-reg68; reg48=reg67-reg48; reg57=pos_nodes[6][0]*reg62; reg60=pos_nodes[7][0]*reg25; reg45=reg52-reg45;
    reg61=reg55-reg61; reg52=reg25*pos_nodes[7][2]; reg55=reg69*reg24; reg59=reg50+reg59; reg43=reg46+reg43;
    reg46=pos_nodes[4][0]*reg5; reg50=pos_nodes[5][2]*reg9; reg65=reg3*reg24; reg67=pos_nodes[8][0]*reg70; reg13=reg63-reg13;
    reg63=pos_nodes[4][1]*reg5; T reg71=reg12*reg24; T reg72=pos_nodes[9][1]*reg41; reg49=reg68-reg49; reg68=reg71*pos_nodes[7][1];
    T reg73=pos_nodes[6][0]*reg55; reg46=reg43+reg46; reg28=reg64+reg28; reg43=reg1*reg2; reg64=reg24*reg7;
    reg60=reg45+reg60; reg45=pos_nodes[8][0]*reg65; T reg74=pos_nodes[9][0]*reg41; reg67=reg13-reg67; reg63=reg54+reg63;
    reg13=pos_nodes[9][2]*reg41; reg47=reg29+reg47; reg29=pos_nodes[8][1]*reg65; reg39=reg48-reg39; reg59=reg50+reg59;
    reg48=pos_nodes[6][1]*reg55; reg58=reg32+reg58; reg32=pos_nodes[6][2]*reg62; reg50=pos_nodes[4][2]*reg5; reg24=reg66*reg24;
    reg57=reg53+reg57; reg53=pos_nodes[7][0]*reg71; reg52=reg61+reg52; reg54=pos_nodes[8][2]*reg65; reg50=reg58+reg50;
    reg58=pos_nodes[6][2]*reg55; reg61=pos_nodes[10][2]*reg14; T reg75=pos_nodes[9][2]*reg43; reg13=reg39+reg13; reg68=reg28+reg68;
    reg28=pos_nodes[8][1]*reg24; reg32=reg59+reg32; reg39=reg71*pos_nodes[7][2]; reg54=reg52+reg54; reg48=reg63+reg48;
    reg73=reg46+reg73; reg46=pos_nodes[7][0]*reg64; reg52=reg64*pos_nodes[7][1]; reg59=pos_nodes[8][0]*reg24; reg53=reg57+reg53;
    reg29=reg47+reg29; reg47=pos_nodes[9][1]*reg43; reg40=reg40*reg2; reg57=pos_nodes[10][0]*reg14; reg74=reg67+reg74;
    reg63=pos_nodes[10][1]*reg14; reg72=reg49+reg72; reg49=pos_nodes[9][0]*reg43; reg45=reg60+reg45; reg60=pos_nodes[10][2]*reg43;
    reg75=reg54-reg75; reg3=reg3*reg2; reg54=pos_nodes[9][0]*reg40; reg59=reg53+reg59; reg46=reg73+reg46;
    reg53=pos_nodes[8][0]*reg64; reg67=pos_nodes[11][0]*reg70; reg57=reg74+reg57; reg49=reg45-reg49; reg45=reg0*reg11;
    reg73=pos_nodes[11][2]*reg70; reg74=pos_nodes[10][0]*reg43; T reg76=pos_nodes[9][1]*reg40; T reg77=pos_nodes[8][2]*reg24; reg39=reg32+reg39;
    reg28=reg68+reg28; reg63=reg72+reg63; reg32=pos_nodes[11][1]*reg70; reg68=pos_nodes[10][1]*reg43; reg47=reg29-reg47;
    reg61=reg13+reg61; reg12=reg12*reg2; reg13=pos_nodes[8][1]*reg64; reg52=reg48+reg52; reg58=reg50+reg58;
    reg29=reg64*pos_nodes[7][2]; reg69=reg69*reg2; reg48=pos_nodes[12][2]*reg45; reg73=reg61+reg73; reg50=pos_nodes[9][0]*reg69;
    reg53=reg46-reg53; reg66=reg66*reg2; reg2=reg7*reg2; reg46=pos_nodes[12][1]*reg45; reg32=reg63+reg32;
    reg76=reg28+reg76; reg28=pos_nodes[10][1]*reg12; reg61=pos_nodes[9][2]*reg40; reg77=reg39+reg77; reg39=pos_nodes[11][1]*reg3;
    reg68=reg47+reg68; reg47=pos_nodes[9][1]*reg69; reg13=reg52-reg13; reg29=reg58+reg29; reg52=pos_nodes[8][2]*reg64;
    reg58=pos_nodes[10][0]*reg12; reg54=reg59+reg54; reg59=pos_nodes[12][0]*reg45; reg67=reg57+reg67; reg57=reg11*var_inter[0];
    reg63=pos_nodes[11][0]*reg3; reg74=reg49+reg74; reg60=reg75+reg60; reg49=pos_nodes[11][2]*reg3; reg0=reg0*reg16;
    reg72=pos_nodes[13][2]*reg57; reg61=reg77+reg61; reg75=pos_nodes[10][2]*reg12; reg48=reg73-reg48; reg73=reg11*var_inter[1];
    reg59=reg67-reg59; reg67=pos_nodes[13][0]*reg57; reg28=reg76+reg28; reg76=pos_nodes[11][1]*reg66; reg77=pos_nodes[13][1]*reg57;
    reg58=reg54+reg58; reg54=pos_nodes[11][0]*reg66; reg63=reg74+reg63; reg74=pos_nodes[12][0]*reg16; reg52=reg29-reg52;
    reg29=pos_nodes[9][2]*reg69; reg46=reg32-reg46; reg47=reg13+reg47; reg13=pos_nodes[10][1]*reg2; reg32=pos_nodes[10][0]*reg2;
    reg50=reg53+reg50; reg53=pos_nodes[12][2]*reg16; reg39=reg68+reg39; reg68=pos_nodes[12][1]*reg16; reg49=reg60+reg49;
    reg39=reg39-reg68; reg67=reg59-reg67; reg59=pos_nodes[14][1]*reg16; reg60=pos_nodes[14][0]*reg73; T reg78=pos_nodes[11][1]*reg2;
    reg13=reg47+reg13; reg54=reg58+reg54; reg47=pos_nodes[12][0]*reg0; reg58=pos_nodes[14][2]*reg16; reg49=reg49-reg53;
    T reg79=reg16*var_inter[0]; reg72=reg48-reg72; reg48=pos_nodes[14][2]*reg73; reg32=reg50+reg32; reg50=pos_nodes[10][2]*reg2;
    reg29=reg52+reg29; reg52=pos_nodes[11][0]*reg2; T reg80=pos_nodes[14][1]*reg73; reg63=reg63-reg74; T reg81=pos_nodes[14][0]*reg16;
    T reg82=pos_nodes[12][1]*reg0; reg76=reg28+reg76; reg75=reg61+reg75; reg28=pos_nodes[11][2]*reg66; reg77=reg46-reg77;
    reg59=reg39+reg59; reg80=reg77-reg80; reg78=reg13-reg78; reg13=pos_nodes[13][0]*reg79; reg47=reg54+reg47;
    reg60=reg67-reg60; reg81=reg63+reg81; reg52=reg32-reg52; reg32=reg16*var_inter[1]; reg39=pos_nodes[12][2]*reg0;
    reg28=reg75+reg28; reg82=reg76+reg82; reg46=pos_nodes[13][1]*reg79; reg58=reg49+reg58; reg48=reg72-reg48;
    reg49=pos_nodes[11][2]*reg2; reg50=reg29+reg50; reg29=pos_nodes[13][0]*reg16; reg46=reg82+reg46; reg74=reg52-reg74;
    reg49=reg50-reg49; reg50=pos_nodes[14][1]*reg32; reg39=reg28+reg39; reg28=pos_nodes[13][2]*reg79; reg13=reg47+reg13;
    reg47=pos_nodes[14][0]*reg32; reg68=reg78-reg68; reg52=pos_nodes[13][1]*reg16; reg54=reg59*reg48; reg61=reg80*reg58;
    reg63=reg60*reg58; reg67=reg81*reg48; reg28=reg39+reg28; reg39=pos_nodes[14][2]*reg32; reg72=reg60*reg59;
    reg29=reg74+reg29; reg63=reg67-reg63; reg50=reg46+reg50; reg47=reg13+reg47; reg13=reg81*reg80;
    reg53=reg49-reg53; reg46=pos_nodes[13][2]*reg16; reg61=reg54-reg61; reg52=reg68+reg52; reg47=pos[0]-reg47;
    reg49=reg29*var_inter[0]; reg39=reg28+reg39; reg28=reg52*var_inter[0]; reg68=reg29*reg61; reg72=reg13-reg72;
    reg74=reg52*reg63; reg46=reg53+reg46; reg50=pos[1]-reg50; reg53=reg46*var_inter[0]; reg75=reg59*reg46;
    reg28=reg50+reg28; reg50=reg59*var_inter[1]; reg76=reg52*reg58; reg49=reg47+reg49; reg47=reg81*var_inter[1];
    reg39=pos[2]-reg39; reg68=reg74-reg68; reg74=reg46*reg72; reg77=reg80*reg46; reg78=reg52*reg48;
    reg82=reg29*reg48; T reg83=reg60*reg46; T reg84=reg29*reg58; T reg85=reg81*reg46; reg83=reg82-reg83;
    reg85=reg84-reg85; T reg86=reg29*reg80; T reg87=reg60*reg52; T reg88=reg29*reg59; T reg89=reg81*reg52;
    reg74=reg68-reg74; reg68=reg60*var_inter[2]; T reg90=reg80*var_inter[2]; reg77=reg78-reg77; T reg91=reg58*var_inter[1];
    reg49=reg47+reg49; reg53=reg39+reg53; reg28=reg50+reg28; reg75=reg76-reg75; reg63=reg63/reg74;
    reg28=reg90+reg28; reg83=reg83/reg74; reg75=reg75/reg74; reg53=reg91+reg53; reg85=reg85/reg74;
    reg77=reg77/reg74; reg39=reg48*var_inter[2]; reg87=reg86-reg87; reg89=reg88-reg89; reg61=reg61/reg74;
    reg49=reg68+reg49; reg85=reg28*reg85; reg75=reg49*reg75; reg72=reg72/reg74; reg83=reg28*reg83;
    reg77=reg49*reg77; reg53=reg39+reg53; reg87=reg87/reg74; reg63=reg28*reg63; reg74=reg89/reg74;
    reg61=reg49*reg61; reg61=reg63-reg61; reg87=reg53*reg87; reg83=reg77-reg83; reg74=reg53*reg74;
    reg75=reg85-reg75; reg72=reg53*reg72; var_inter[0]+=reg61-reg72; var_inter[2]+=reg75-reg74; var_inter[1]+=reg87+reg83;

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
    reg14=reg14-reg6; reg1=1+reg1; reg10=reg4*reg10; reg14=val[0]*reg14; reg15=reg15-reg10;
    reg5=reg5*reg1; reg13=val[1]*reg13; reg15=val[2]*reg15; reg13=reg14+reg13; reg6=reg5-reg6;
    reg8=reg8*reg1; reg15=reg13+reg15; reg6=val[3]*reg6; reg7=reg8-reg7; reg11=reg11*reg1;
    reg10=reg11-reg10; reg2=var_inter[0]*reg2; reg6=reg15+reg6; reg7=val[4]*reg7; reg10=val[5]*reg10;
    reg5=reg12*reg2; reg3=var_inter[1]*reg3; reg7=reg6+reg7; reg10=reg7+reg10; reg5=val[6]*reg5;
    reg6=reg12*reg3; reg9=reg0*reg9; reg6=val[7]*reg6; reg12=reg12*reg9; reg5=reg10+reg5;
    reg6=reg5+reg6; reg12=val[8]*reg12; reg2=reg1*reg2; reg12=reg6+reg12; reg2=val[9]*reg2;
    reg3=reg1*reg3; reg2=reg12+reg2; reg3=val[10]*reg3; reg9=reg1*reg9; reg3=reg2+reg3;
    reg9=val[11]*reg9; reg0=reg0*reg4; reg1=var_inter[0]*reg4; reg0=val[12]*reg0; reg9=reg3+reg9;
    reg1=val[13]*reg1; reg4=var_inter[1]*reg4; reg0=reg9+reg0; reg1=reg0+reg1; reg4=val[14]*reg4;
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
