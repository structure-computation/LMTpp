#ifndef LMT_WEDGE_15
#define LMT_WEDGE_15
#include "node.h"
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*reg0; T reg3=2*var_inter[2];
    T reg4=0.5*var_inter[0]; T reg5=reg1-1; T reg6=0.5*reg0; T reg7=reg2-1; reg3=reg3-1;
    T reg8=2*var_inter[1]; T reg9=4*reg3; T reg10=reg7*reg6; T reg11=0.5*var_inter[1]; T reg12=reg5*reg4;
    T reg13=reg8-1; T reg14=2*reg12; T reg15=reg4*reg9; T reg16=2*reg10; T reg17=reg6*reg9;
    T reg18=reg11*reg13; T reg19=reg11*reg9; T reg20=2*reg18; T reg21=pow(reg3,2); T reg22=reg17-reg16;
    T reg23=reg15-reg14; reg13=0.5*reg13; reg7=0.5*reg7; T reg24=pos_nodes[0][2]*reg22; reg13=var_inter[1]+reg13;
    T reg25=pos_nodes[1][2]*reg23; reg7=reg0+reg7; T reg26=1-reg3; T reg27=pos_nodes[1][1]*reg23; T reg28=pos_nodes[0][1]*reg22;
    T reg29=pos_nodes[0][0]*reg22; T reg30=pos_nodes[1][0]*reg23; T reg31=reg19-reg20; reg21=1-reg21; T reg32=pos_nodes[2][2]*reg31;
    reg24=reg25+reg24; reg25=reg26*reg13; reg5=0.5*reg5; reg29=reg30+reg29; reg30=pos_nodes[2][0]*reg31;
    T reg33=reg26*reg7; T reg34=0.5*reg21; T reg35=reg16+reg17; T reg36=pos_nodes[2][1]*reg31; reg28=reg27+reg28;
    reg3=1+reg3; reg27=reg14+reg15; T reg37=pos_nodes[3][2]*reg35; T reg38=reg34-reg33; T reg39=reg3*reg7;
    reg32=reg24+reg32; reg25=reg25-reg34; reg30=reg29+reg30; reg24=pos_nodes[3][0]*reg35; reg36=reg28+reg36;
    reg28=pos_nodes[3][1]*reg35; reg5=var_inter[0]+reg5; reg29=pos_nodes[0][2]*reg38; T reg40=pos_nodes[4][0]*reg27; reg24=reg30+reg24;
    reg30=pos_nodes[4][2]*reg27; T reg41=pos_nodes[2][2]*reg25; reg37=reg32+reg37; reg32=pos_nodes[4][1]*reg27; reg28=reg36+reg28;
    reg36=pos_nodes[0][1]*reg38; reg6=reg6*reg21; T reg42=reg26*reg5; reg4=reg21*reg4; T reg43=reg26*reg12;
    T reg44=reg10*reg26; T reg45=pos_nodes[0][0]*reg38; T reg46=reg2*var_inter[0]; reg13=reg3*reg13; T reg47=pos_nodes[2][0]*reg25;
    T reg48=reg34-reg39; T reg49=pos_nodes[2][1]*reg25; T reg50=reg20+reg19; T reg51=2*reg46; T reg52=pos_nodes[3][2]*reg48;
    T reg53=pos_nodes[5][0]*reg50; reg40=reg24+reg40; reg24=pos_nodes[3][1]*reg48; reg44=reg44-reg6; T reg54=pos_nodes[5][2]*reg50;
    reg41=reg29+reg41; reg30=reg37+reg30; reg43=reg43-reg4; reg47=reg45+reg47; reg13=reg13-reg34;
    reg42=reg42-reg34; reg37=pos_nodes[3][0]*reg48; T reg55=reg18*reg26; reg11=reg11*reg21; reg32=reg28+reg32;
    reg49=reg49+reg36; reg28=pos_nodes[5][1]*reg50; T reg56=var_inter[1]*reg1; T reg57=pos_nodes[1][1]*reg42; T reg58=pos_nodes[1][0]*reg42;
    T reg59=pos_nodes[0][0]*reg44; T reg60=pos_nodes[1][0]*reg43; reg28=reg32+reg28; reg32=pos_nodes[6][2]*reg51; reg54=reg30+reg54;
    reg30=pos_nodes[5][2]*reg13; reg41=reg52+reg41; reg49=reg49+reg24; T reg61=2*reg56; T reg62=pos_nodes[5][1]*reg13;
    reg5=reg3*reg5; reg55=reg55-reg11; reg10=reg3*reg10; reg53=reg40+reg53; reg40=pos_nodes[6][0]*reg51;
    T reg63=reg8*reg0; T reg64=pos_nodes[1][1]*reg43; T reg65=pos_nodes[0][1]*reg44; T reg66=reg26*reg1; T reg67=pos_nodes[6][1]*reg51;
    reg47=reg37+reg47; T reg68=pos_nodes[5][0]*reg13; T reg69=pos_nodes[7][0]*reg61; reg40=reg53-reg40; reg53=reg2-reg8;
    T reg70=pos_nodes[6][0]*reg66; reg45=reg58+reg45; reg58=pos_nodes[7][1]*reg61; reg67=reg28-reg67; reg68=reg47+reg68;
    reg6=reg10-reg6; reg12=reg3*reg12; reg10=pos_nodes[6][1]*reg66; reg62=reg49+reg62; reg28=reg55*pos_nodes[2][0];
    reg65=reg64+reg65; reg47=reg55*pos_nodes[2][1]; reg49=pos_nodes[1][2]*reg43; reg64=pos_nodes[0][2]*reg44; T reg71=pos_nodes[6][2]*reg66;
    reg30=reg41+reg30; reg41=pos_nodes[7][2]*reg61; reg32=reg54-reg32; reg36=reg57+reg36; reg59=reg60+reg59;
    reg5=reg5-reg34; reg2=reg2-reg1; reg54=2*reg63; reg57=pos_nodes[1][2]*reg42; reg60=pos_nodes[7][2]*reg66;
    T reg72=reg26*reg53; reg70=reg68-reg70; reg68=pos_nodes[7][0]*reg66; T reg73=reg55*pos_nodes[2][2]; reg64=reg49+reg64;
    reg49=pos_nodes[7][1]*reg66; reg41=reg32-reg41; reg32=pos_nodes[8][2]*reg54; reg10=reg62-reg10; reg4=reg12-reg4;
    reg12=reg6*pos_nodes[3][0]; reg28=reg59+reg28; reg47=reg65+reg47; reg59=reg6*pos_nodes[3][1]; reg62=pos_nodes[4][1]*reg5;
    reg24=reg36+reg24; reg36=reg26*reg2; reg65=pos_nodes[8][1]*reg54; reg57=reg29+reg57; reg71=reg30-reg71;
    reg69=reg40-reg69; reg29=pos_nodes[8][0]*reg54; reg30=pos_nodes[4][0]*reg5; reg37=reg45+reg37; reg18=reg18*reg3;
    reg58=reg67-reg58; reg73=reg64+reg73; reg40=reg8*reg26; reg45=reg6*pos_nodes[3][2]; reg11=reg18-reg11;
    reg30=reg37+reg30; reg62=reg24+reg62; reg18=pos_nodes[6][1]*reg36; reg24=reg3*reg1; reg37=pos_nodes[6][0]*reg36;
    reg68=reg70+reg68; reg64=pos_nodes[8][0]*reg72; reg52=reg57+reg52; reg57=pos_nodes[9][0]*reg51; reg67=pos_nodes[4][2]*reg5;
    reg29=reg69-reg29; reg69=reg4*pos_nodes[4][1]; reg70=reg4*pos_nodes[4][0]; T reg74=pos_nodes[8][1]*reg72; reg49=reg10+reg49;
    reg32=reg41-reg32; reg65=reg58-reg65; reg10=pos_nodes[9][1]*reg51; reg41=pos_nodes[8][2]*reg72; reg60=reg71+reg60;
    reg58=pos_nodes[9][2]*reg51; reg59=reg47+reg59; reg12=reg28+reg12; reg28=pos_nodes[9][2]*reg24; reg67=reg52+reg67;
    reg47=pos_nodes[6][2]*reg36; reg52=reg46*reg26; reg37=reg30+reg37; reg30=pos_nodes[7][0]*reg40; reg41=reg60+reg41;
    reg60=pos_nodes[9][0]*reg24; reg64=reg68+reg64; reg70=reg12+reg70; reg12=pos_nodes[7][1]*reg40; reg18=reg62+reg18;
    reg62=reg4*pos_nodes[4][2]; reg45=reg73+reg45; reg69=reg59+reg69; reg59=pos_nodes[5][1]*reg11; reg68=pos_nodes[9][1]*reg24;
    reg74=reg49+reg74; reg58=reg32+reg58; reg32=pos_nodes[10][2]*reg61; reg49=pos_nodes[10][1]*reg61; reg10=reg65+reg10;
    reg65=pos_nodes[10][0]*reg61; reg57=reg29+reg57; reg29=pos_nodes[5][0]*reg11; reg71=reg56*reg26; reg73=pos_nodes[11][1]*reg54;
    reg49=reg10+reg49; reg53=reg3*reg53; reg10=pos_nodes[8][0]*reg40; reg30=reg37+reg30; reg59=reg69+reg59;
    reg37=pos_nodes[7][2]*reg40; reg47=reg67+reg47; reg67=pos_nodes[6][1]*reg52; reg69=pos_nodes[11][0]*reg54; reg65=reg57+reg65;
    reg2=reg3*reg2; reg57=pos_nodes[11][2]*reg54; reg32=reg58+reg32; reg62=reg45+reg62; reg45=pos_nodes[5][2]*reg11;
    reg58=reg0*reg9; reg68=reg74-reg68; reg74=pos_nodes[10][1]*reg24; reg29=reg70+reg29; reg70=pos_nodes[6][0]*reg52;
    T reg75=pos_nodes[10][0]*reg24; reg18=reg12+reg18; reg12=pos_nodes[8][1]*reg40; reg28=reg41-reg28; reg41=pos_nodes[10][2]*reg24;
    reg60=reg64-reg60; reg45=reg62+reg45; reg62=pos_nodes[6][2]*reg52; reg67=reg59+reg67; reg59=reg71*pos_nodes[7][1];
    reg64=pos_nodes[7][0]*reg71; reg70=reg29+reg70; reg26=reg63*reg26; reg29=pos_nodes[11][1]*reg53; reg74=reg68+reg74;
    reg68=pos_nodes[11][2]*reg53; reg41=reg28+reg41; reg28=var_inter[0]*reg9; reg69=reg65+reg69; reg65=pos_nodes[12][0]*reg58;
    reg57=reg32+reg57; reg32=pos_nodes[9][0]*reg2; reg10=reg30-reg10; reg30=reg8*reg3; T reg76=pos_nodes[12][2]*reg58;
    reg75=reg60+reg75; reg60=pos_nodes[9][1]*reg2; reg12=reg18-reg12; reg18=pos_nodes[12][1]*reg58; reg73=reg49+reg73;
    reg37=reg47+reg37; reg47=pos_nodes[8][2]*reg40; reg49=pos_nodes[11][0]*reg53; reg65=reg69-reg65; reg76=reg57-reg76;
    reg57=pos_nodes[13][0]*reg28; reg69=pos_nodes[13][2]*reg28; T reg77=pos_nodes[8][1]*reg26; reg59=reg67+reg59; reg67=pos_nodes[12][0]*reg21;
    T reg78=pos_nodes[7][2]*reg71; reg62=reg45+reg62; reg18=reg73-reg18; reg45=var_inter[1]*reg9; reg73=pos_nodes[13][1]*reg28;
    T reg79=pos_nodes[10][0]*reg30; reg32=reg10+reg32; reg68=reg41+reg68; reg49=reg75+reg49; reg10=pos_nodes[9][2]*reg2;
    reg47=reg37-reg47; reg60=reg12+reg60; reg12=pos_nodes[10][1]*reg30; reg37=pos_nodes[8][0]*reg26; reg64=reg70+reg64;
    reg41=pos_nodes[12][1]*reg21; reg70=pos_nodes[12][2]*reg21; reg29=reg74+reg29; reg46=reg3*reg46; reg74=pos_nodes[9][0]*reg46;
    reg37=reg64+reg37; reg79=reg32+reg79; reg32=pos_nodes[11][0]*reg30; reg64=pos_nodes[14][0]*reg21; reg49=reg49-reg67;
    reg75=pos_nodes[14][0]*reg45; reg57=reg65-reg57; reg10=reg47+reg10; reg78=reg62+reg78; reg47=pos_nodes[10][2]*reg30;
    reg62=pos_nodes[9][1]*reg46; reg65=pos_nodes[8][2]*reg26; reg77=reg59+reg77; reg59=pos_nodes[14][1]*reg45; reg73=reg18-reg73;
    reg18=pos_nodes[14][1]*reg21; reg29=reg29-reg41; T reg80=pos_nodes[11][1]*reg30; reg12=reg60+reg12; reg60=pos_nodes[14][2]*reg45;
    reg69=reg76-reg69; reg56=reg3*reg56; reg68=reg68-reg70; reg76=pos_nodes[14][2]*reg21; reg76=reg68+reg76;
    reg47=reg10+reg47; reg10=pos_nodes[10][1]*reg56; reg75=reg57-reg75; reg62=reg77+reg62; reg63=reg3*reg63;
    reg3=pos_nodes[11][2]*reg30; reg32=reg79-reg32; reg59=reg73-reg59; reg57=pos_nodes[9][2]*reg46; reg18=reg29+reg18;
    reg65=reg78+reg65; reg64=reg49+reg64; reg60=reg69-reg60; reg80=reg12-reg80; reg12=pos_nodes[10][0]*reg56;
    reg74=reg37+reg74; reg3=reg47-reg3; reg29=reg76*reg75; reg37=reg60*reg64; reg47=reg59*reg76;
    reg49=reg18*reg60; reg68=pos_nodes[11][1]*reg63; reg10=reg62+reg10; reg62=pos_nodes[13][0]*reg21; reg67=reg32-reg67;
    reg32=pos_nodes[13][1]*reg21; reg41=reg80-reg41; reg12=reg74+reg12; reg69=pos_nodes[11][0]*reg63; reg0=reg0*reg21;
    reg57=reg65+reg57; reg65=pos_nodes[10][2]*reg56; reg73=pos_nodes[11][2]*reg63; reg65=reg57+reg65; reg29=reg37-reg29;
    reg47=reg49-reg47; reg57=reg59*reg64; reg74=reg18*reg75; reg77=pos_nodes[13][2]*reg21; reg70=reg3-reg70;
    reg3=pos_nodes[12][1]*reg0; reg68=reg10+reg68; reg62=reg67+reg62; reg32=reg41+reg32; reg69=reg12+reg69;
    reg10=pos_nodes[12][0]*reg0; reg12=var_inter[0]*reg21; reg41=reg32*reg29; reg77=reg70+reg77; reg67=pos_nodes[13][1]*reg12;
    reg3=reg68+reg3; reg10=reg69+reg10; reg68=pos_nodes[13][0]*reg12; reg73=reg65+reg73; reg65=pos_nodes[12][2]*reg0;
    reg69=reg47*reg62; reg70=var_inter[1]*reg21; reg74=reg57-reg74; reg78=reg77*reg64; reg79=reg76*reg62;
    reg67=reg3+reg67; reg3=pos_nodes[14][1]*reg70; reg80=reg77*reg75; T reg81=reg60*reg62; T reg82=reg18*reg77;
    reg68=reg10+reg68; reg10=reg32*reg76; T reg83=reg59*reg77; T reg84=reg32*reg60; T reg85=pos_nodes[14][0]*reg70;
    T reg86=reg77*reg74; reg69=reg41-reg69; reg65=reg73+reg65; reg41=pos_nodes[13][2]*reg12; reg73=reg18*reg62;
    T reg87=reg32*reg75; T reg88=reg59*reg62; T reg89=reg32*reg64; reg78=reg79-reg78; reg80=reg81-reg80;
    reg41=reg65+reg41; reg65=pos_nodes[14][2]*reg70; reg3=reg67+reg3; reg85=reg68+reg85; reg82=reg10-reg82;
    reg83=reg84-reg83; reg86=reg69-reg86; reg85=pos[0]-reg85; reg89=reg73-reg89; reg65=reg41+reg65;
    reg47=reg47/reg86; reg83=reg83/reg86; reg82=reg82/reg86; reg29=reg29/reg86; reg3=pos[1]-reg3;
    reg80=reg80/reg86; reg87=reg88-reg87; reg78=reg78/reg86; reg65=pos[2]-reg65; reg87=reg87/reg86;
    reg89=reg89/reg86; reg78=reg3*reg78; reg82=reg82*reg85; reg86=reg74/reg86; reg47=reg47*reg85;
    reg80=reg3*reg80; reg83=reg83*reg85; reg29=reg3*reg29; reg80=reg83-reg80; reg86=reg65*reg86;
    reg89=reg65*reg89; reg87=reg65*reg87; reg82=reg78-reg82; reg47=reg29-reg47; var_inter[1]=reg87+reg80;
    var_inter[2]=reg82-reg89; var_inter[0]=reg47-reg86;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*var_inter[0]; T reg3=2*reg0;
    reg1=reg1-1; T reg4=2*var_inter[1]; T reg5=0.5*var_inter[0]; T reg6=reg2-1; T reg7=reg3-1;
    T reg8=0.5*reg0; T reg9=reg8*reg7; T reg10=reg4-1; T reg11=reg5*reg6; T reg12=0.5*var_inter[1];
    T reg13=4*reg1; T reg14=reg12*reg10; T reg15=2*reg11; T reg16=reg5*reg13; T reg17=2*reg9;
    T reg18=reg8*reg13; T reg19=pow(reg1,2); reg10=0.5*reg10; T reg20=2*reg14; T reg21=reg12*reg13;
    reg7=0.5*reg7; T reg22=reg16-reg15; T reg23=reg18-reg17; T reg24=pos_nodes[1][2]*reg22; reg7=reg0+reg7;
    T reg25=1-reg1; reg19=1-reg19; T reg26=pos_nodes[1][1]*reg22; T reg27=pos_nodes[0][1]*reg23; T reg28=reg21-reg20;
    T reg29=pos_nodes[1][0]*reg22; T reg30=pos_nodes[0][0]*reg23; reg10=var_inter[1]+reg10; T reg31=pos_nodes[0][2]*reg23; reg29=reg30+reg29;
    reg24=reg31+reg24; reg30=reg17+reg18; reg31=pos_nodes[2][1]*reg28; T reg32=pos_nodes[2][0]*reg28; T reg33=reg25*reg10;
    reg26=reg27+reg26; reg27=pos_nodes[2][2]*reg28; reg1=1+reg1; T reg34=reg25*reg7; T reg35=0.5*reg19;
    reg6=0.5*reg6; T reg36=reg1*reg7; T reg37=reg35-reg34; reg6=reg6+var_inter[0]; reg33=reg33-reg35;
    T reg38=pos_nodes[3][2]*reg30; reg24=reg27+reg24; reg27=reg15+reg16; reg29=reg32+reg29; reg32=pos_nodes[3][0]*reg30;
    T reg39=pos_nodes[3][1]*reg30; reg26=reg31+reg26; reg39=reg26+reg39; reg26=reg25*reg11; reg5=reg19*reg5;
    reg31=reg25*reg6; T reg40=pos_nodes[4][1]*reg27; T reg41=pos_nodes[2][1]*reg33; T reg42=pos_nodes[0][2]*reg37; T reg43=reg37*pos_nodes[0][1];
    T reg44=pos_nodes[2][2]*reg33; T reg45=pos_nodes[4][2]*reg27; T reg46=reg3*var_inter[0]; T reg47=reg9*reg25; T reg48=pos_nodes[2][0]*reg33;
    T reg49=pos_nodes[4][0]*reg27; reg38=reg24+reg38; reg32=reg29+reg32; reg24=reg20+reg21; reg29=reg35-reg36;
    T reg50=reg37*pos_nodes[0][0]; reg10=reg1*reg10; reg8=reg8*reg19; T reg51=pos_nodes[5][1]*reg24; reg48=reg50+reg48;
    reg39=reg40+reg39; reg12=reg19*reg12; reg40=reg25*reg14; T reg52=pos_nodes[5][2]*reg24; reg38=reg45+reg38;
    reg10=reg10-reg35; reg45=2*reg46; reg32=reg49+reg32; reg49=pos_nodes[5][0]*reg24; T reg53=reg29*pos_nodes[3][0];
    reg41=reg43+reg41; reg44=reg42+reg44; T reg54=reg29*pos_nodes[3][1]; T reg55=reg29*pos_nodes[3][2]; reg47=reg47-reg8;
    reg26=reg26-reg5; T reg56=var_inter[1]*reg2; reg31=reg31-reg35; T reg57=reg25*reg2; reg41=reg54+reg41;
    T reg58=pos_nodes[6][2]*reg45; T reg59=reg10*pos_nodes[5][1]; T reg60=2*reg56; T reg61=pos_nodes[6][0]*reg45; reg49=reg32+reg49;
    reg52=reg38+reg52; reg48=reg53+reg48; reg32=reg10*pos_nodes[5][0]; reg40=reg40-reg12; reg38=reg47*pos_nodes[0][0];
    T reg62=reg26*pos_nodes[1][0]; T reg63=reg26*pos_nodes[1][1]; reg51=reg39+reg51; reg39=reg31*pos_nodes[1][1]; T reg64=reg31*pos_nodes[1][0];
    T reg65=reg0*reg4; T reg66=reg47*pos_nodes[0][1]; reg9=reg1*reg9; reg6=reg1*reg6; T reg67=pos_nodes[6][1]*reg45;
    T reg68=reg10*pos_nodes[5][2]; reg44=reg55+reg44; T reg69=reg40*pos_nodes[2][1]; T reg70=2*reg65; reg63=reg66+reg63;
    reg61=reg49-reg61; reg49=pos_nodes[7][0]*reg60; reg66=pos_nodes[6][1]*reg57; reg59=reg41+reg59; reg41=reg40*pos_nodes[2][0];
    reg62=reg38+reg62; reg38=reg31*pos_nodes[1][2]; T reg71=pos_nodes[6][2]*reg57; reg68=reg44+reg68; reg64=reg50+reg64;
    reg39=reg43+reg39; reg6=reg6-reg35; reg43=pos_nodes[7][1]*reg60; reg67=reg51-reg67; reg44=pos_nodes[0][2]*reg47;
    reg50=reg3-reg2; reg51=reg26*pos_nodes[1][2]; T reg72=pos_nodes[7][2]*reg60; reg58=reg52-reg58; reg3=reg3-reg4;
    reg32=reg48+reg32; reg48=pos_nodes[6][0]*reg57; reg11=reg1*reg11; reg8=reg9-reg8; reg49=reg61-reg49;
    reg9=pos_nodes[8][0]*reg70; reg52=reg40*pos_nodes[2][2]; reg66=reg59-reg66; reg59=reg25*reg3; reg61=reg8*pos_nodes[3][1];
    reg51=reg44+reg51; reg53=reg64+reg53; reg63=reg69+reg63; reg72=reg58-reg72; reg44=reg6*pos_nodes[4][0];
    reg71=reg68-reg71; reg58=pos_nodes[7][2]*reg57; reg14=reg1*reg14; reg64=reg25*reg50; reg68=pos_nodes[8][2]*reg70;
    reg62=reg41+reg62; reg41=reg8*pos_nodes[3][0]; reg5=reg11-reg5; reg11=pos_nodes[7][0]*reg57; reg48=reg32-reg48;
    reg32=reg6*pos_nodes[4][1]; reg38=reg42+reg38; reg42=pos_nodes[7][1]*reg57; reg54=reg39+reg54; reg39=pos_nodes[8][1]*reg70;
    reg43=reg67-reg43; reg67=reg5*pos_nodes[4][1]; reg69=reg64*pos_nodes[6][1]; reg12=reg14-reg12; reg55=reg38+reg55;
    reg39=reg43-reg39; reg14=reg25*reg4; reg58=reg71+reg58; reg38=pos_nodes[8][2]*reg59; reg43=pos_nodes[9][1]*reg45;
    reg54=reg32+reg54; reg32=reg6*pos_nodes[4][2]; reg41=reg62+reg41; reg11=reg48+reg11; reg48=pos_nodes[8][1]*reg59;
    reg42=reg66+reg42; reg53=reg44+reg53; reg44=reg64*pos_nodes[6][0]; reg62=reg8*pos_nodes[3][2]; reg51=reg52+reg51;
    reg52=reg1*reg2; reg9=reg49-reg9; reg49=pos_nodes[9][0]*reg45; reg61=reg63+reg61; reg63=reg5*pos_nodes[4][0];
    reg66=pos_nodes[8][0]*reg59; reg68=reg72-reg68; reg71=pos_nodes[9][2]*reg45; reg72=pos_nodes[9][1]*reg52; T reg73=reg14*pos_nodes[7][1];
    reg54=reg69+reg54; reg43=reg39+reg43; reg39=pos_nodes[10][1]*reg60; reg61=reg67+reg61; reg67=reg12*pos_nodes[5][1];
    reg69=reg64*pos_nodes[6][2]; reg48=reg42+reg48; reg62=reg51+reg62; reg42=reg14*pos_nodes[7][0]; reg53=reg44+reg53;
    reg49=reg9+reg49; reg9=pos_nodes[10][0]*reg60; reg44=pos_nodes[9][0]*reg52; reg66=reg11+reg66; reg11=pos_nodes[9][2]*reg52;
    reg38=reg58+reg38; reg71=reg68+reg71; reg55=reg32+reg55; reg32=reg46*reg25; reg51=reg12*pos_nodes[5][0];
    reg41=reg63+reg41; reg58=reg5*pos_nodes[4][2]; reg63=pos_nodes[10][2]*reg60; reg68=reg32*pos_nodes[6][1]; T reg74=reg12*pos_nodes[5][2];
    reg62=reg58+reg62; reg58=pos_nodes[11][1]*reg70; T reg75=pos_nodes[10][0]*reg52; reg44=reg66-reg44; reg39=reg43+reg39;
    reg50=reg1*reg50; reg43=reg56*reg25; reg66=pos_nodes[11][2]*reg70; reg63=reg71+reg63; reg3=reg1*reg3;
    reg55=reg69+reg55; reg69=reg14*pos_nodes[7][2]; reg73=reg54+reg73; reg54=pos_nodes[8][1]*reg14; reg51=reg41+reg51;
    reg41=reg32*pos_nodes[6][0]; reg67=reg61+reg67; reg11=reg38-reg11; reg38=pos_nodes[10][2]*reg52; reg61=pos_nodes[10][1]*reg52;
    reg71=pos_nodes[11][0]*reg70; reg9=reg49+reg9; reg72=reg48-reg72; reg48=reg0*reg13; reg42=reg53+reg42;
    reg49=reg14*pos_nodes[8][0]; reg25=reg65*reg25; reg69=reg55+reg69; reg53=pos_nodes[8][2]*reg14; reg55=reg32*pos_nodes[6][2];
    T reg76=pos_nodes[12][2]*reg48; reg66=reg63+reg66; reg63=reg43*pos_nodes[7][1]; reg67=reg68+reg67; reg68=pos_nodes[11][2]*reg3;
    reg74=reg62+reg74; reg38=reg11+reg38; reg54=reg73-reg54; reg11=pos_nodes[9][1]*reg50; reg62=reg43*pos_nodes[7][0];
    reg51=reg41+reg51; reg41=pos_nodes[12][0]*reg48; reg71=reg9+reg71; reg9=var_inter[0]*reg13; reg73=pos_nodes[11][0]*reg3;
    reg75=reg44+reg75; reg61=reg72+reg61; reg44=reg1*reg4; reg49=reg42-reg49; reg42=pos_nodes[9][0]*reg50;
    reg72=pos_nodes[12][1]*reg48; reg58=reg39+reg58; reg39=pos_nodes[11][1]*reg3; T reg77=reg43*pos_nodes[7][2]; reg53=reg69-reg53;
    reg69=pos_nodes[9][2]*reg50; T reg78=reg19*pos_nodes[12][2]; T reg79=reg25*pos_nodes[8][0]; reg62=reg51+reg62; reg74=reg55+reg74;
    reg46=reg46*reg1; reg51=pos_nodes[13][0]*reg9; reg41=reg71-reg41; reg68=reg38+reg68; reg42=reg49+reg42;
    reg38=var_inter[1]*reg13; reg73=reg75+reg73; reg49=pos_nodes[10][0]*reg44; reg55=reg19*pos_nodes[12][0]; reg71=pos_nodes[13][2]*reg9;
    reg76=reg66-reg76; reg39=reg61+reg39; reg61=reg19*pos_nodes[12][1]; reg63=reg67+reg63; reg66=reg25*pos_nodes[8][1];
    reg67=pos_nodes[10][1]*reg44; reg11=reg54+reg11; reg54=pos_nodes[13][1]*reg9; reg72=reg58-reg72; reg58=reg19*pos_nodes[14][2];
    reg68=reg68-reg78; reg66=reg63+reg66; reg63=pos_nodes[9][1]*reg46; reg73=reg73-reg55; reg67=reg11+reg67;
    reg51=reg41-reg51; reg11=pos_nodes[14][0]*reg38; reg41=pos_nodes[11][1]*reg44; reg75=reg19*pos_nodes[14][0]; reg56=reg56*reg1;
    reg79=reg62+reg79; reg62=pos_nodes[9][0]*reg46; reg39=reg39-reg61; reg71=reg76-reg71; reg76=pos_nodes[14][2]*reg38;
    T reg80=reg19*pos_nodes[14][1]; T reg81=reg25*pos_nodes[8][2]; T reg82=pos_nodes[11][0]*reg44; reg49=reg42+reg49; reg77=reg74+reg77;
    reg54=reg72-reg54; reg42=pos_nodes[10][2]*reg44; reg69=reg53+reg69; reg53=pos_nodes[14][1]*reg38; reg75=reg73+reg75;
    reg72=pos_nodes[9][2]*reg46; reg81=reg77+reg81; reg53=reg54-reg53; reg80=reg39+reg80; reg41=reg67-reg41;
    reg82=reg49-reg82; reg65=reg1*reg65; reg76=reg71-reg76; reg62=reg79+reg62; reg1=pos_nodes[10][0]*reg56;
    reg39=pos_nodes[11][2]*reg44; reg42=reg69+reg42; reg11=reg51-reg11; reg58=reg68+reg58; reg49=pos_nodes[10][1]*reg56;
    reg63=reg66+reg63; reg51=reg75*reg76; reg54=reg53*reg58; reg66=reg80*reg76; reg67=pos_nodes[10][2]*reg56;
    reg72=reg81+reg72; reg68=reg19*pos_nodes[13][0]; reg69=reg11*reg58; reg71=reg19*pos_nodes[13][1]; reg39=reg42-reg39;
    reg55=reg82-reg55; reg42=pos_nodes[11][0]*reg65; reg1=reg62+reg1; reg49=reg63+reg49; reg62=pos_nodes[11][1]*reg65;
    reg0=reg0*reg19; reg61=reg41-reg61; reg41=reg75*reg53; reg54=reg66-reg54; reg63=pos_nodes[12][1]*reg0;
    reg62=reg49+reg62; reg69=reg51-reg69; reg49=pos_nodes[11][2]*reg65; reg67=reg72+reg67; reg72=reg11*reg80;
    reg73=pos_nodes[12][0]*reg0; reg42=reg1+reg42; reg61=reg71+reg61; reg1=reg19*pos_nodes[13][2]; reg71=reg19*var_inter[0];
    reg55=reg68+reg55; reg78=reg39-reg78; reg39=reg19*var_inter[1]; reg68=reg55*reg54; reg63=reg62+reg63;
    reg62=reg61*reg69; reg74=pos_nodes[12][2]*reg0; reg49=reg67+reg49; reg78=reg1+reg78; reg1=pos_nodes[13][0]*reg71;
    reg72=reg41-reg72; reg73=reg42+reg73; reg42=pos_nodes[13][1]*reg71; reg67=reg78*reg72; reg77=reg61*reg76;
    reg68=reg62-reg68; reg62=reg53*reg78; reg79=reg11*reg78; reg81=reg55*reg58; reg82=reg55*reg76;
    T reg83=reg75*reg78; T reg84=reg80*reg78; T reg85=reg61*reg58; T reg86=pos_nodes[14][1]*reg39; reg74=reg49+reg74;
    reg63=reg42+reg63; reg42=pos_nodes[13][2]*reg71; reg49=pos_nodes[14][0]*reg39; reg73=reg1+reg73; reg86=reg63+reg86;
    reg79=reg82-reg79; reg83=reg81-reg83; reg1=reg55*reg53; reg84=reg85-reg84; reg63=reg11*reg61;
    T reg87=reg55*reg80; reg62=reg77-reg62; reg67=reg68-reg67; reg49=reg73+reg49; reg68=reg75*reg61;
    reg74=reg42+reg74; reg42=pos_nodes[14][2]*reg39; reg63=reg1-reg63; reg83=reg83/reg67; reg68=reg87-reg68;
    reg86=pos[1]-reg86; reg79=reg79/reg67; reg69=reg69/reg67; reg84=reg84/reg67; reg62=reg62/reg67;
    reg54=reg54/reg67; reg49=pos[0]-reg49; reg42=reg74+reg42; reg42=pos[2]-reg42; reg83=reg86*reg83;
    reg84=reg49*reg84; reg79=reg86*reg79; reg62=reg49*reg62; reg69=reg86*reg69; reg54=reg49*reg54;
    reg68=reg68/reg67; reg63=reg63/reg67; reg67=reg72/reg67; reg54=reg69-reg54; reg67=reg42*reg67;
    reg63=reg42*reg63; reg79=reg62-reg79; reg68=reg42*reg68; reg84=reg83-reg84; var_inter[0]+=reg54-reg67;
    var_inter[1]+=reg63+reg79; var_inter[2]+=reg84-reg68;

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
    reg14=reg13+reg14; reg6=val[3]*reg6; reg15=reg14+reg15; reg8=reg7-reg8; reg12=reg12*reg1;
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
    T reg0=2*var_inter[1]; T reg1=2*var_inter[0]; T reg2=var_inter[2]-0.14644660940672626914; T reg3=1-var_inter[2]; reg2=reg2/0.70710678118654746172;
    T reg4=reg1+reg0; reg4=reg4-1; reg3=reg3-0.14644660940672626914; reg2=1-reg2; T reg5=1-reg1;
    reg3=reg3/0.70710678118654746172; T reg6=reg4*reg2; T reg7=reg2*reg5; T reg8=1-reg0; reg3=1-reg3;
    reg6=val[0]*reg6; reg7=val[1]*reg7; reg2=reg2*reg8; T reg9=reg4*reg3; reg2=val[2]*reg2;
    reg7=reg6+reg7; reg2=reg7+reg2; reg9=val[3]*reg9; reg6=reg5*reg3; reg6=val[4]*reg6;
    reg9=reg2+reg9; reg3=reg8*reg3; reg9=reg6+reg9; reg3=val[5]*reg3; res=reg9+reg3;

}
#ifndef STRUCT_Gauss_2
#define STRUCT_Gauss_2
struct Gauss_2 {};
#endif // STRUCT_Gauss_2
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Gauss_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[1]; T reg1=2*var_inter[0]; T reg2=var_inter[2]-0.14644660940672626914; T reg3=1-var_inter[2]; reg2=reg2/0.70710678118654746172;
    T reg4=reg1+reg0; reg4=reg4-1; reg3=reg3-0.14644660940672626914; reg2=1-reg2; T reg5=1-reg1;
    reg3=reg3/0.70710678118654746172; T reg6=reg4*reg2; T reg7=reg2*reg5; T reg8=1-reg0; reg3=1-reg3;
    reg6=val[0]*reg6; reg7=val[1]*reg7; reg2=reg2*reg8; T reg9=reg4*reg3; reg2=val[2]*reg2;
    reg7=reg6+reg7; reg2=reg7+reg2; reg9=val[3]*reg9; reg6=reg5*reg3; reg6=val[4]*reg6;
    reg9=reg2+reg9; reg3=reg8*reg3; reg9=reg6+reg9; reg3=val[5]*reg3; res=reg9+reg3;

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
    T reg4=reg1-1; T reg5=2*var_inter[1]; T reg6=reg3-1; reg2=reg2-1; T reg7=0.5*var_inter[0];
    T reg8=0.5*reg0; T reg9=reg8*reg4; T reg10=4*reg2; T reg11=reg7*reg6; T reg12=0.5*var_inter[1];
    T reg13=reg5-1; T reg14=2*reg9; T reg15=reg12*reg13; T reg16=reg10*reg7; T reg17=2*reg11;
    T reg18=reg8*reg10; reg6=0.5*reg6; reg13=0.5*reg13; reg4=0.5*reg4; T reg19=reg16-reg17;
    T reg20=reg18-reg14; T reg21=2*reg15; T reg22=reg10*reg12; T reg23=pow(reg2,2); reg13=var_inter[1]+reg13;
    reg4=reg0+reg4; reg23=1-reg23; T reg24=elem.pos(1)[1]*reg19; T reg25=elem.pos(0)[1]*reg20; T reg26=elem.pos(1)[2]*reg19;
    T reg27=elem.pos(0)[2]*reg20; reg6=var_inter[0]+reg6; T reg28=reg22-reg21; T reg29=1-reg2; T reg30=elem.pos(2)[2]*reg28;
    reg27=reg26+reg27; reg26=reg14+reg18; T reg31=reg29*reg4; T reg32=elem.pos(2)[1]*reg28; reg2=1+reg2;
    T reg33=reg29*reg6; reg24=reg25+reg24; reg25=0.5*reg23; T reg34=reg29*reg13; reg33=reg33-reg25;
    T reg35=reg17+reg16; reg32=reg24+reg32; reg24=reg4*reg2; reg34=reg34-reg25; T reg36=elem.pos(3)[2]*reg26;
    reg30=reg27+reg30; reg27=reg25-reg31; T reg37=elem.pos(3)[1]*reg26; reg13=reg13*reg2; reg20=reg20*elem.pos(0)[0];
    reg37=reg32+reg37; reg32=elem.pos(4)[2]*reg35; T reg38=reg34*elem.pos(2)[2]; T reg39=reg34*elem.pos(2)[1]; reg36=reg30+reg36;
    reg19=elem.pos(1)[0]*reg19; reg6=reg2*reg6; reg30=var_inter[0]*reg1; T reg40=reg25-reg24; T reg41=elem.pos(1)[2]*reg33;
    T reg42=elem.pos(0)[2]*reg27; T reg43=elem.pos(4)[1]*reg35; T reg44=elem.pos(0)[1]*reg27; T reg45=elem.pos(1)[1]*reg33; T reg46=reg21+reg22;
    T reg47=var_inter[1]*reg3; reg41=reg41+reg42; reg32=reg36+reg32; reg36=reg46*elem.pos(5)[2]; reg28=elem.pos(2)[0]*reg28;
    T reg48=elem.pos(3)[2]*reg40; T reg49=reg1-reg3; reg39=reg44+reg39; reg6=reg6-reg25; reg45=reg44+reg45;
    reg13=reg13-reg25; reg44=2*reg30; T reg50=elem.pos(3)[1]*reg40; reg38=reg42+reg38; reg19=reg20+reg19;
    reg20=elem.pos(5)[1]*reg46; reg43=reg37+reg43; reg45=reg50+reg45; reg27=reg27*elem.pos(0)[0]; reg37=elem.pos(4)[1]*reg6;
    reg42=reg29*reg49; T reg51=elem.pos(5)[1]*reg13; T reg52=elem.pos(4)[2]*reg6; reg38=reg38+reg48; reg48=reg41+reg48;
    reg41=reg0*reg5; reg39=reg50+reg39; reg50=elem.pos(6)[1]*reg44; reg26=elem.pos(3)[0]*reg26; T reg53=elem.pos(6)[2]*reg44;
    reg36=reg32+reg36; reg28=reg19+reg28; reg19=elem.pos(5)[2]*reg13; reg20=reg43+reg20; reg32=2*reg47;
    reg33=elem.pos(1)[0]*reg33; reg43=reg29*reg3; reg34=reg34*elem.pos(2)[0]; reg39=reg51+reg39; reg51=elem.pos(6)[1]*reg43;
    T reg54=2*reg41; T reg55=reg42*elem.pos(6)[1]; reg45=reg37+reg45; reg28=reg26+reg28; reg26=reg29*reg5;
    reg36=reg36-reg53; reg37=reg32*elem.pos(7)[2]; reg20=reg20-reg50; T reg56=elem.pos(6)[2]*reg43; reg35=elem.pos(4)[0]*reg35;
    T reg57=elem.pos(7)[1]*reg32; reg33=reg33+reg27; reg1=reg1-reg5; T reg58=reg42*elem.pos(6)[2]; reg52=reg48+reg52;
    reg34=reg27+reg34; reg19=reg38+reg19; reg40=elem.pos(3)[0]*reg40; reg28=reg35+reg28; reg13=elem.pos(5)[0]*reg13;
    reg6=elem.pos(4)[0]*reg6; reg27=elem.pos(7)[2]*reg43; reg19=reg19-reg56; reg35=elem.pos(7)[1]*reg43; reg36=reg36-reg37;
    reg55=reg45+reg55; reg38=elem.pos(7)[1]*reg26; reg58=reg52+reg58; reg45=reg54*elem.pos(8)[1]; reg34=reg40+reg34;
    reg39=reg39-reg51; reg48=elem.pos(7)[2]*reg26; reg52=reg29*reg1; reg20=reg20-reg57; reg46=elem.pos(5)[0]*reg46;
    reg40=reg33+reg40; reg33=reg54*elem.pos(8)[2]; reg19=reg27+reg19; reg27=elem.pos(9)[1]*reg44; reg34=reg13+reg34;
    reg13=elem.pos(6)[0]*reg44; reg36=reg36-reg33; T reg59=reg3*reg2; T reg60=elem.pos(6)[0]*reg43; reg20=reg20-reg45;
    reg28=reg46+reg28; reg6=reg40+reg6; reg42=reg42*elem.pos(6)[0]; reg40=reg52*elem.pos(8)[1]; reg46=elem.pos(8)[2]*reg26;
    reg58=reg48+reg58; reg48=reg52*elem.pos(8)[2]; reg35=reg39+reg35; reg39=elem.pos(9)[2]*reg44; reg49=reg49*reg2;
    T reg61=elem.pos(8)[1]*reg26; reg38=reg55+reg38; reg55=elem.pos(7)[0]*reg26; T reg62=reg32*elem.pos(10)[1]; T reg63=reg32*elem.pos(7)[0];
    reg28=reg28-reg13; T reg64=reg5*reg2; reg27=reg20+reg27; reg20=reg49*elem.pos(9)[1]; reg40=reg35+reg40;
    reg58=reg58-reg46; reg35=elem.pos(7)[0]*reg43; reg38=reg38-reg61; T reg65=reg49*elem.pos(9)[2]; T reg66=reg59*elem.pos(9)[1];
    reg36=reg39+reg36; reg34=reg34-reg60; reg19=reg48+reg19; reg39=reg32*elem.pos(10)[2]; reg48=reg59*elem.pos(9)[2];
    reg42=reg6+reg42; reg6=reg64*elem.pos(10)[2]; reg28=reg28-reg63; T reg67=reg54*elem.pos(8)[0]; reg19=reg19-reg48;
    reg1=reg2*reg1; reg65=reg58+reg65; reg58=reg54*elem.pos(11)[2]; reg20=reg38+reg20; reg38=reg64*elem.pos(10)[1];
    T reg68=reg59*elem.pos(10)[1]; reg40=reg40-reg66; reg52=reg52*elem.pos(8)[0]; reg35=reg34+reg35; reg34=reg0*reg10;
    reg36=reg39+reg36; reg39=elem.pos(8)[0]*reg26; reg55=reg42+reg55; reg42=reg59*elem.pos(10)[2]; T reg69=reg54*elem.pos(11)[1];
    reg62=reg27+reg62; reg27=elem.pos(12)[2]*reg34; T reg70=reg64*elem.pos(11)[1]; T reg71=reg59*elem.pos(9)[0]; reg68=reg40+reg68;
    reg52=reg35+reg52; reg49=reg49*elem.pos(9)[0]; reg55=reg55-reg39; reg35=var_inter[0]*reg10; reg40=elem.pos(9)[0]*reg44;
    reg58=reg36+reg58; reg6=reg65+reg6; reg36=reg64*elem.pos(11)[2]; reg65=elem.pos(12)[1]*reg34; reg62=reg69+reg62;
    reg38=reg20+reg38; reg20=elem.pos(11)[2]*reg1; reg19=reg42+reg19; reg28=reg28-reg67; reg42=elem.pos(11)[1]*reg1;
    reg69=reg32*elem.pos(10)[0]; reg40=reg28+reg40; reg62=reg62-reg65; reg28=reg64*elem.pos(10)[0]; reg55=reg49+reg55;
    reg49=elem.pos(12)[2]*reg23; T reg72=var_inter[1]*reg10; reg6=reg6-reg36; T reg73=reg59*elem.pos(10)[0]; reg52=reg52-reg71;
    reg42=reg68+reg42; reg38=reg38-reg70; reg58=reg58-reg27; reg68=elem.pos(12)[1]*reg23; T reg74=elem.pos(13)[1]*reg35;
    reg20=reg19+reg20; reg19=elem.pos(13)[2]*reg35; reg28=reg55+reg28; reg42=reg42-reg68; reg55=reg64*elem.pos(11)[0];
    reg1=elem.pos(11)[0]*reg1; reg20=reg20-reg49; reg6=reg6-reg49; T reg75=elem.pos(13)[2]*reg23; T reg76=elem.pos(14)[2]*reg23;
    reg62=reg62-reg74; reg69=reg40+reg69; reg40=reg54*elem.pos(11)[0]; reg73=reg52+reg73; reg52=elem.pos(14)[1]*reg23;
    T reg77=elem.pos(13)[1]*reg23; T reg78=elem.pos(14)[2]*reg72; reg58=reg58-reg19; T reg79=elem.pos(14)[1]*reg72; reg38=reg38-reg68;
    reg6=reg75+reg6; reg77=reg38+reg77; reg42=reg52+reg42; reg1=reg73+reg1; reg76=reg20+reg76;
    reg20=elem.pos(12)[0]*reg34; reg38=elem.pos(12)[0]*reg23; reg58=reg58-reg78; reg28=reg28-reg55; reg40=reg69+reg40;
    reg62=reg62-reg79; reg52=elem.pos(14)[0]*reg23; reg69=elem.pos(13)[0]*reg35; reg40=reg40-reg20; reg28=reg28-reg38;
    reg73=elem.pos(13)[0]*reg23; reg75=reg58*reg42; T reg80=reg77*reg58; T reg81=reg76*reg62; reg1=reg1-reg38;
    T reg82=reg62*reg6; reg1=reg52+reg1; reg52=reg76*reg77; T reg83=elem.pos(14)[0]*reg72; T reg84=reg6*reg42;
    reg40=reg40-reg69; reg28=reg73+reg28; reg82=reg80-reg82; reg81=reg75-reg81; reg40=reg40-reg83;
    reg84=reg52-reg84; reg52=reg81*reg28; reg73=reg1*reg82; reg75=reg84*reg40; reg73=reg52-reg73;
    reg75=reg73+reg75; return reg75;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Wedge_15,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.11094010767585030302*elem.pos(1)[1]; T reg1=0.81282032302755082053*elem.pos(0)[1]; T reg2=0.27378906834863934872*elem.pos(1)[2]; T reg3=0.81282032302755082053*elem.pos(0)[2]; T reg4=0.11094010767585030302*elem.pos(1)[2];
    T reg5=0.27378906834863943131*elem.pos(0)[1]; T reg6=0.27378906834863934872*elem.pos(1)[1]; T reg7=0.27378906834863943131*elem.pos(0)[2]; T reg8=0.27378906834863934872*elem.pos(2)[1]; T reg9=0.11094010767585030302*elem.pos(0)[2];
    T reg10=reg3+reg4; T reg11=reg5+reg6; T reg12=reg1+reg0; T reg13=0.11094010767585030302*elem.pos(0)[1]; T reg14=0.27378906834863934872*elem.pos(2)[2];
    T reg15=reg7+reg2; T reg16=0.11094010767585030302*elem.pos(2)[1]; T reg17=0.11094010767585030302*elem.pos(2)[2]; T reg18=reg16+reg12; T reg19=reg0+reg13;
    T reg20=0.57282032302755088275*elem.pos(3)[1]; T reg21=0.81282032302755082053*elem.pos(1)[1]; T reg22=0.81282032302755082053*elem.pos(2)[1]; T reg23=reg8+reg11; T reg24=0.49601129057086162889*elem.pos(3)[1];
    T reg25=0.81282032302755082053*elem.pos(2)[2]; T reg26=reg17+reg10; T reg27=0.57282032302755088275*elem.pos(3)[2]; T reg28=reg14+reg15; T reg29=0.49601129057086162889*elem.pos(3)[2];
    T reg30=reg4+reg9; T reg31=0.81282032302755082053*elem.pos(1)[2]; T reg32=0.77081185509940458903*elem.pos(0)[1]; T reg33=0.35094010767585030747*elem.pos(3)[2]; T reg34=reg22+reg19;
    T reg35=0.49106836025229589073*elem.pos(2)[1]; T reg36=reg18+reg20; T reg37=reg9+reg31; T reg38=0.35094010767585030747*elem.pos(4)[1]; T reg39=reg25+reg30;
    T reg40=0.35094010767585030747*elem.pos(3)[1]; T reg41=0.070441621801729122516*elem.pos(2)[2]; T reg42=0.07044162180172894739*elem.pos(0)[2]; T reg43=0.49601129057086158327*elem.pos(4)[2]; T reg44=reg28+reg29;
    T reg45=0.49601129057086162889*elem.pos(0)[1]; T reg46=0.49601129057086158327*elem.pos(1)[1]; T reg47=0.27378906834863943131*elem.pos(0)[0]; T reg48=0.27378906834863934872*elem.pos(1)[0]; T reg49=0.070441621801729122516*elem.pos(2)[1];
    T reg50=reg26+reg27; T reg51=0.35094010767585030747*elem.pos(4)[2]; T reg52=0.49601129057086158327*elem.pos(1)[2]; T reg53=0.07044162180172894739*elem.pos(0)[1]; T reg54=0.49601129057086162889*elem.pos(0)[2];
    T reg55=0.49106836025229589073*elem.pos(1)[2]; T reg56=0.49601129057086158327*elem.pos(4)[1]; T reg57=reg23+reg24; T reg58=0.49106836025229589073*elem.pos(1)[1]; T reg59=0.070441621801729122516*elem.pos(1)[1];
    T reg60=0.81282032302755082053*elem.pos(0)[0]; T reg61=0.11094010767585030302*elem.pos(1)[0]; T reg62=reg13+reg21; T reg63=0.070441621801729122516*elem.pos(1)[2]; T reg64=0.49106836025229589073*elem.pos(2)[2];
    T reg65=0.77081185509940458903*elem.pos(0)[2]; T reg66=reg39+reg33; T reg67=reg44+reg43; T reg68=0.49601129057086158327*elem.pos(2)[1]; T reg69=reg58+reg32;
    reg46=reg45+reg46; reg45=reg60+reg61; reg52=reg54+reg52; reg54=0.77081185509940458903*elem.pos(2)[2]; T reg70=reg42-reg63;
    T reg71=0.49106836025229589073*elem.pos(0)[2]; T reg72=reg16+reg62; T reg73=reg65+reg55; T reg74=reg34+reg40; T reg75=0.11094010767585030302*elem.pos(2)[0];
    T reg76=0.49601129057086158327*elem.pos(2)[2]; T reg77=0.35094010767585030747*elem.pos(1)[1]; T reg78=0.49106836025229589073*elem.pos(0)[1]; T reg79=0.77081185509940458903*elem.pos(2)[1]; T reg80=reg53-reg49;
    T reg81=0.037478521766071383161*elem.pos(3)[2]; T reg82=reg64+reg65; T reg83=0.11094010767585030302*elem.pos(0)[0]; T reg84=0.27378906834863934872*elem.pos(2)[0]; reg53=reg53-reg59;
    T reg85=reg47+reg48; T reg86=reg57+reg56; T reg87=0.49601129057086158327*elem.pos(5)[1]; T reg88=0.35094010767585030747*elem.pos(5)[2]; T reg89=0.26289171153160427653*elem.pos(3)[1];
    T reg90=reg50+reg51; T reg91=0.037478521766071383161*elem.pos(3)[1]; T reg92=reg32+reg35; T reg93=0.57282032302755088275*elem.pos(0)[2]; T reg94=0.35094010767585030747*elem.pos(1)[2];
    T reg95=reg17+reg37; reg42=reg42-reg41; T reg96=0.35094010767585030747*elem.pos(5)[1]; T reg97=reg36+reg38; T reg98=0.26289171153160427653*elem.pos(3)[2];
    T reg99=0.49601129057086158327*elem.pos(5)[2]; T reg100=0.57282032302755088275*elem.pos(0)[1]; reg80=reg89+reg80; T reg101=0.27378906834863943131*elem.pos(3)[2]; T reg102=0.37559830641437077015*elem.pos(3)[1];
    reg52=reg76+reg52; reg76=0.77081185509940458903*elem.pos(1)[2]; T reg103=reg84+reg85; T reg104=0.070441621801729122516*elem.pos(2)[0]; T reg105=0.19874168162164587908*elem.pos(1)[0];
    T reg106=0.19874168162164588299*elem.pos(0)[0]; T reg107=0.26289171153160432348*elem.pos(5)[1]; T reg108=0.81282032302755082053*elem.pos(1)[0]; reg79=reg78+reg79; T reg109=0.77081185509940458903*elem.pos(1)[1];
    T reg110=0.16130768281804421985*elem.pos(1)[0]; T reg111=0.10535898384862248483*elem.pos(0)[0]; T reg112=reg75+reg45; T reg113=0.57282032302755088275*elem.pos(3)[0]; T reg114=reg51+reg66;
    T reg115=0.49601129057086162889*elem.pos(3)[0]; T reg116=0.57282032302755088275*elem.pos(5)[2]; T reg117=0.37559830641437077015*elem.pos(5)[2]; T reg118=reg81-reg82; T reg119=0.26289171153160432348*elem.pos(4)[1];
    reg100=reg100+reg77; T reg120=0.35094010767585030747*elem.pos(2)[1]; reg42=reg42+reg98; T reg121=0.10535898384862248483*elem.pos(0)[1]; T reg122=0.16130768281804421985*elem.pos(1)[1];
    T reg123=reg97+reg96; T reg124=0.48000000000000000888*elem.pos(6)[1]; T reg125=0.26289171153160432348*elem.pos(5)[2]; reg93=reg93+reg94; T reg126=reg91-reg92;
    T reg127=0.77081185509940458903*elem.pos(0)[0]; T reg128=0.49106836025229589073*elem.pos(1)[0]; T reg129=reg33+reg95; T reg130=0.57282032302755088275*elem.pos(4)[2]; T reg131=0.07044162180172894739*elem.pos(0)[0];
    T reg132=0.35094010767585030747*elem.pos(0)[2]; T reg133=0.070441621801729122516*elem.pos(1)[0]; T reg134=0.35094010767585030747*elem.pos(0)[1]; T reg135=0.81282032302755082053*elem.pos(2)[0]; T reg136=reg61+reg83;
    T reg137=reg88+reg90; T reg138=0.48000000000000000888*elem.pos(6)[2]; T reg139=0.4444444444444444691*elem.pos(6)[1]; T reg140=reg86+reg87; T reg141=0.19874168162164588299*elem.pos(0)[1];
    T reg142=0.19874168162164587908*elem.pos(1)[1]; reg53=reg89+reg53; reg54=reg54+reg71; reg89=0.37559830641437077015*elem.pos(3)[2]; T reg143=0.37559830641437077015*elem.pos(4)[2];
    reg81=reg81-reg73; reg70=reg98+reg70; reg98=0.26289171153160432348*elem.pos(4)[2]; T reg144=0.57282032302755088275*elem.pos(4)[1]; T reg145=reg40+reg72;
    T reg146=0.16130768281804421985*elem.pos(1)[2]; T reg147=0.10535898384862248483*elem.pos(0)[2]; T reg148=0.4444444444444444691*elem.pos(6)[2]; T reg149=0.37559830641437077015*elem.pos(4)[1]; reg91=reg91-reg69;
    T reg150=0.35094010767585030747*elem.pos(2)[2]; T reg151=0.49106836025229589073*elem.pos(2)[0]; reg46=reg68+reg46; reg68=0.27378906834863943131*elem.pos(3)[1]; T reg152=0.57282032302755088275*elem.pos(5)[1];
    T reg153=reg38+reg74; T reg154=reg99+reg67; T reg155=0.37559830641437077015*elem.pos(5)[1]; T reg156=0.19874168162164588299*elem.pos(0)[2]; T reg157=0.19874168162164587908*elem.pos(1)[2];
    reg70=reg70-reg98; T reg158=1.7512105867530111459e-16*elem.pos(6)[2]; T reg159=0.037478521766071383161*elem.pos(5)[1]; T reg160=reg135+reg136; T reg161=reg131-reg133;
    T reg162=0.35094010767585030747*elem.pos(3)[0]; T reg163=0.44444444444444439511*elem.pos(7)[1]; T reg164=0.77081185509940458903*elem.pos(2)[0]; T reg165=0.037478521766071383161*elem.pos(5)[2]; reg131=reg131-reg104;
    T reg166=0.26289171153160427653*elem.pos(3)[0]; T reg167=reg129+reg130; T reg168=0.44444444444444439511*elem.pos(7)[2]; T reg169=reg154+reg148; T reg170=0.16000000000000001776*elem.pos(6)[1];
    T reg171=reg153+reg152; T reg172=1.7512105867530111459e-16*elem.pos(6)[1]; reg53=reg53-reg119; reg126=reg126-reg155; T reg173=0.49106836025229589073*elem.pos(0)[0];
    reg42=reg42-reg125; T reg174=1.0515668461264170957*elem.pos(6)[2]; T reg175=reg145+reg144; reg109=reg78+reg109; reg79=reg102+reg79;
    reg54=reg54+reg89; T reg176=0.16130768281804421985*elem.pos(0)[0]; T reg177=reg116+reg114; T reg178=reg140+reg139; T reg179=0.16000000000000001776*elem.pos(6)[2];
    T reg180=0.16000000000000001776*elem.pos(7)[1]; T reg181=0.81282032302755082053*elem.pos(3)[2]; reg93=reg150+reg93; T reg182=reg127+reg128; T reg183=0.037478521766071383161*elem.pos(3)[0];
    T reg184=0.16130768281804421985*elem.pos(0)[1]; T reg185=0.49601129057086158327*elem.pos(1)[0]; T reg186=0.49601129057086162889*elem.pos(0)[0]; T reg187=0.19874168162164587908*elem.pos(2)[2]; T reg188=reg156+reg157;
    reg91=reg91-reg149; T reg189=1.2618802153517004798*elem.pos(6)[1]; T reg190=0.16130768281804421985*elem.pos(2)[2]; T reg191=0.26289171153160432348*elem.pos(1)[2]; T reg192=reg147+reg146;
    T reg193=0.26289171153160432348*elem.pos(1)[1]; reg81=reg81-reg143; T reg194=1.2618802153517004798*elem.pos(6)[2]; T reg195=0.16130768281804421985*elem.pos(0)[2]; T reg196=0.27378906834863934872*elem.pos(4)[1];
    T reg197=0.57282032302755088275*elem.pos(2)[2]; reg94=reg94+reg132; T reg198=0.57282032302755088275*elem.pos(2)[1]; reg77=reg77+reg134; T reg199=0.63094010767585032744*elem.pos(6)[1];
    T reg200=reg137+reg138; T reg201=0.16000000000000001776*elem.pos(7)[2]; T reg202=0.57282032302755088275*elem.pos(1)[2]; T reg203=0.57282032302755088275*elem.pos(1)[1]; T reg204=0.19874168162164587908*elem.pos(2)[1];
    T reg205=reg141+reg142; T reg206=0.81282032302755082053*elem.pos(3)[1]; reg118=reg118-reg117; T reg207=0.63094010767585032744*elem.pos(6)[2]; reg100=reg120+reg100;
    T reg208=0.16130768281804421985*elem.pos(2)[1]; T reg209=reg121+reg122; T reg210=reg123+reg124; T reg211=reg83+reg108; reg80=reg80-reg107;
    T reg212=1.0515668461264170957*elem.pos(6)[1]; T reg213=0.26289171153160432348*elem.pos(2)[1]; T reg214=0.35094010767585030747*elem.pos(4)[0]; T reg215=0.26289171153160427653*elem.pos(0)[1]; T reg216=reg112+reg113;
    T reg217=reg106+reg105; reg101=reg52+reg101; reg52=0.27378906834863934872*elem.pos(4)[2]; T reg218=reg111+reg110; reg76=reg71+reg76;
    reg68=reg46+reg68; reg46=reg103+reg115; T reg219=reg127+reg151; T reg220=0.49601129057086158327*elem.pos(4)[0]; T reg221=0.16130768281804421985*elem.pos(2)[0];
    T reg222=0.19874168162164587908*elem.pos(2)[0]; T reg223=0.26289171153160427653*elem.pos(0)[2]; T reg224=0.26289171153160432348*elem.pos(2)[2]; T reg225=reg75+reg211; reg206=reg100+reg206;
    reg100=0.11094010767585030302*elem.pos(4)[1]; T reg226=1.0515668461264170957*elem.pos(7)[2]; T reg227=0.10535898384862248483*elem.pos(2)[0]; T reg228=0.13459165171168747556*elem.pos(3)[1]; T reg229=reg204+reg205;
    reg174=reg42-reg174; reg42=reg110+reg176; reg76=reg89+reg76; reg94=reg197+reg94; reg197=0.11094010767585030302*elem.pos(3)[2];
    T reg230=0.037478521766071383161*elem.pos(4)[2]; reg164=reg173+reg164; T reg231=0.4444444444444444691*elem.pos(8)[1]; T reg232=reg178+reg163; T reg233=0.037478521766071383161*elem.pos(4)[1];
    reg77=reg198+reg77; reg198=0.11094010767585030302*elem.pos(3)[1]; T reg234=0.35094010767585030747*elem.pos(1)[0]; T reg235=0.57282032302755088275*elem.pos(0)[0]; T reg236=reg160+reg162;
    reg109=reg102+reg109; T reg237=1.0515668461264170957*elem.pos(7)[1]; reg212=reg80-reg212; reg202=reg132+reg202; reg80=0.37559830641437077015*elem.pos(1)[2];
    reg203=reg134+reg203; reg132=0.37559830641437077015*elem.pos(1)[1]; reg185=reg186+reg185; reg134=0.27378906834863934872*elem.pos(5)[2]; reg186=0.49601129057086158327*elem.pos(2)[0];
    T reg238=reg187+reg188; T reg239=0.13459165171168747556*elem.pos(3)[2]; T reg240=reg223-reg191; reg52=reg101+reg52; reg101=reg190+reg192;
    T reg241=0.17464101615137755461*elem.pos(3)[2]; T reg242=reg215-reg193; reg223=reg223-reg224; T reg243=0.07044162180172894739*elem.pos(3)[2]; T reg244=0.10535898384862248483*elem.pos(2)[2];
    T reg245=reg146+reg195; T reg246=0.10535898384862248483*elem.pos(1)[2]; T reg247=0.27378906834863934872*elem.pos(5)[1]; reg196=reg68+reg196; reg68=reg96+reg175;
    T reg248=0.037478521766071383161*elem.pos(0)[2]; T reg249=0.37559830641437077015*elem.pos(2)[2]; T reg250=0.10535898384862248483*elem.pos(1)[0]; T reg251=0.77081185509940458903*elem.pos(1)[0]; T reg252=reg208+reg209;
    T reg253=0.17464101615137755461*elem.pos(3)[1]; T reg254=0.11094010767585030302*elem.pos(4)[2]; reg181=reg93+reg181; reg93=0.07044162180172894739*elem.pos(3)[1]; T reg255=0.10535898384862248483*elem.pos(2)[1];
    T reg256=reg88+reg167; T reg257=0.4444444444444444691*elem.pos(8)[2]; T reg258=reg169+reg168; reg215=reg215-reg213; T reg259=0.37559830641437077015*elem.pos(2)[1];
    T reg260=0.037478521766071383161*elem.pos(0)[1]; T reg261=reg122+reg184; T reg262=0.10535898384862248483*elem.pos(1)[1]; T reg263=0.17464101615137755461*elem.pos(3)[0]; reg161=reg161+reg166;
    T reg264=0.26289171153160432348*elem.pos(4)[0]; T reg265=reg221+reg218; reg118=reg118-reg207; T reg266=0.63094010767585032744*elem.pos(7)[2]; T reg267=reg183-reg219;
    T reg268=reg171+reg170; T reg269=0.48000000000000000888*elem.pos(7)[1]; T reg270=reg210+reg180; T reg271=0.48000000000000000888*elem.pos(8)[1]; reg91=reg91+reg189;
    T reg272=reg46+reg220; T reg273=reg78-reg58; reg183=reg183-reg182; T reg274=0.37559830641437077015*elem.pos(4)[0]; T reg275=0.13459165171168747556*elem.pos(3)[0];
    T reg276=reg222+reg217; T reg277=reg216+reg214; T reg278=0.35094010767585030747*elem.pos(5)[0]; reg79=reg79-reg159; reg81=reg81+reg194;
    T reg279=0.26289171153160432348*elem.pos(5)[0]; reg131=reg166+reg131; reg166=0.48000000000000000888*elem.pos(7)[2]; reg172=reg53+reg172; reg53=reg200+reg201;
    T reg280=0.48000000000000000888*elem.pos(8)[2]; T reg281=0.37559830641437077015*elem.pos(3)[0]; T reg282=0.63094010767585032744*elem.pos(7)[1]; reg126=reg126-reg199; T reg283=reg177+reg179;
    T reg284=0.49601129057086158327*elem.pos(5)[0]; reg158=reg70+reg158; reg54=reg54-reg165; reg70=0.37559830641437077015*elem.pos(5)[0]; T reg285=reg71-reg55;
    T reg286=reg276+reg275; T reg287=0.13459165171168746096*elem.pos(4)[0]; T reg288=reg244+reg245; reg52=reg134+reg52; reg134=0.070441621801729122516*elem.pos(5)[2];
    T reg289=0.63094010767585032744*elem.pos(6)[0]; T reg290=0.092025650515289130841*elem.pos(3)[2]; T reg291=0.26289171153160432348*elem.pos(1)[0]; reg267=reg267-reg70; T reg292=0.26289171153160427653*elem.pos(0)[0];
    T reg293=reg195+reg246; reg223=reg223+reg243; T reg294=0.13459165171168746096*elem.pos(1)[2]; T reg295=0.13459165171168747556*elem.pos(0)[2]; reg247=reg196+reg247;
    reg251=reg173+reg251; reg199=reg79-reg199; reg109=reg109-reg233; reg131=reg131-reg279; reg79=1.0515668461264170957*elem.pos(6)[0];
    reg76=reg76-reg230; reg196=1.7512105867530111459e-16*elem.pos(8)[1]; reg212=reg212+reg237; T reg296=0.092025650515289130841*elem.pos(4)[0]; T reg297=reg265+reg263;
    T reg298=reg162+reg225; T reg299=0.57282032302755088275*elem.pos(4)[0]; T reg300=reg176+reg250; T reg301=reg284+reg272; T reg302=0.4444444444444444691*elem.pos(6)[0];
    T reg303=0.070441621801729122516*elem.pos(5)[1]; T reg304=0.48000000000000000888*elem.pos(6)[0]; T reg305=reg278+reg277; reg215=reg93+reg215; T reg306=reg270+reg271;
    reg181=reg181+reg254; T reg307=0.092025650515289130841*elem.pos(4)[1]; T reg308=reg252+reg253; T reg309=reg248-reg249; T reg310=0.77081185509940458903*elem.pos(3)[2];
    T reg311=0.13459165171168746096*elem.pos(4)[1]; T reg312=reg229+reg228; T reg313=1.2618802153517004798*elem.pos(8)[2]; reg118=reg118+reg266; reg206=reg206+reg100;
    T reg314=0.11094010767585030302*elem.pos(5)[1]; T reg315=reg260-reg132; reg203=reg120+reg203; reg120=0.48000000000000000888*elem.pos(9)[2]; T reg316=reg53+reg280;
    reg248=reg248-reg80; reg202=reg150+reg202; reg150=0.35094010767585030747*elem.pos(0)[0]; T reg317=0.35094010767585030747*elem.pos(2)[0]; reg235=reg235+reg234;
    reg77=reg77+reg198; T reg318=0.37559830641437077015*elem.pos(0)[2]; T reg319=0.037478521766071383161*elem.pos(2)[2]; reg94=reg94+reg197; T reg320=1.2618802153517004798*elem.pos(8)[1];
    reg126=reg126+reg282; T reg321=0.37559830641437077015*elem.pos(0)[1]; T reg322=0.037478521766071383161*elem.pos(2)[1]; T reg323=0.63094010767585032744*elem.pos(8)[2]; reg81=reg266+reg81;
    reg242=reg93+reg242; reg93=0.070441621801729122516*elem.pos(4)[1]; T reg324=0.092025650515289130841*elem.pos(4)[2]; T reg325=reg101+reg241; reg240=reg243+reg240;
    reg243=0.070441621801729122516*elem.pos(4)[2]; T reg326=0.63094010767585032744*elem.pos(8)[1]; T reg327=0.26289171153160432348*elem.pos(2)[0]; T reg328=0.13459165171168746096*elem.pos(4)[2]; T reg329=reg238+reg239;
    reg91=reg282+reg91; reg185=reg186+reg185; reg186=0.27378906834863943131*elem.pos(3)[0]; T reg330=0.13459165171168747556*elem.pos(0)[0]; T reg331=0.13459165171168746096*elem.pos(1)[0];
    T reg332=0.13459165171168746096*elem.pos(1)[1]; T reg333=0.13459165171168747556*elem.pos(0)[1]; T reg334=reg184+reg262; T reg335=0.092025650515289130841*elem.pos(3)[1]; T reg336=reg255+reg261;
    T reg337=0.77081185509940458903*elem.pos(3)[1]; T reg338=1.2618802153517004798*elem.pos(6)[0]; reg260=reg260-reg259; reg183=reg183-reg274; T reg339=0.11094010767585030302*elem.pos(5)[2];
    T reg340=0.48000000000000000888*elem.pos(9)[1]; reg158=reg226+reg158; T reg341=1.0515668461264170957*elem.pos(8)[2]; T reg342=0.092025650515289130841*elem.pos(3)[0]; reg164=reg281+reg164;
    T reg343=reg232+reg231; reg172=reg237+reg172; reg237=reg227+reg42; T reg344=reg214+reg236; T reg345=0.4444444444444444691*elem.pos(9)[2];
    T reg346=0.037478521766071383161*elem.pos(5)[0]; T reg347=0.57282032302755088275*elem.pos(5)[0]; T reg348=reg124+reg68; reg207=reg54-reg207; reg161=reg161-reg264;
    reg54=1.7512105867530111459e-16*elem.pos(8)[2]; reg226=reg174+reg226; reg174=1.0515668461264170957*elem.pos(8)[1]; T reg349=reg283+reg166; reg78=reg78-reg35;
    reg273=reg102+reg273; T reg350=0.4444444444444444691*elem.pos(9)[1]; T reg351=reg138+reg256; reg71=reg71-reg64; T reg352=reg258+reg257;
    T reg353=reg268+reg269; reg285=reg89+reg285; T reg354=1.7512105867530111459e-16*elem.pos(6)[0]; T reg355=reg288+reg290; T reg356=0.49106836025229589073*elem.pos(4)[2];
    T reg357=0.07044162180172894739*elem.pos(3)[0]; reg248=reg248-reg310; T reg358=1.8928203230275508072*elem.pos(7)[2]; T reg359=reg120-reg316; reg78=reg102+reg78;
    reg242=reg242-reg93; reg102=4.6923546249730193496e-17*elem.pos(6)[1]; reg203=reg198+reg203; reg198=0.81282032302755082053*elem.pos(4)[1]; T reg360=reg325+reg324;
    T reg361=reg173-reg128; T reg362=0.33811978464829938699*elem.pos(9)[1]; T reg363=0.16000000000000001776*elem.pos(10)[2]; T reg364=0.16000000000000001776*elem.pos(8)[2]; T reg365=reg166+reg351;
    reg148=reg52-reg148; reg52=0.57282032302755088275*elem.pos(2)[0]; T reg366=0.092025650515289130841*elem.pos(1)[2]; T reg367=0.17464101615137755461*elem.pos(0)[2]; reg234=reg234+reg150;
    reg267=reg267-reg289; T reg368=0.16000000000000001776*elem.pos(9)[1]; reg223=reg223-reg134; T reg369=0.28176648720691616366*elem.pos(6)[2]; T reg370=reg295+reg294;
    T reg371=4.6923546249730193496e-17*elem.pos(9)[1]; T reg372=0.13459165171168746096*elem.pos(2)[2]; T reg373=0.37559830641437077015*elem.pos(2)[0]; reg174=reg172-reg174; reg172=reg286+reg287;
    T reg374=0.33811978464829938699*elem.pos(9)[2]; reg139=reg247-reg139; reg247=reg350-reg343; T reg375=reg190+reg293; reg202=reg197+reg202;
    reg81=reg81-reg323; reg197=0.81282032302755082053*elem.pos(4)[2]; T reg376=reg292-reg291; T reg377=reg237+reg342; T reg378=0.13459165171168746096*elem.pos(2)[1];
    T reg379=reg208+reg334; T reg380=reg347+reg344; T reg381=0.16000000000000001776*elem.pos(6)[0]; T reg382=reg336+reg335; T reg383=0.63094010767585032744*elem.pos(7)[0];
    T reg384=0.49106836025229589073*elem.pos(5)[1]; reg118=reg118+reg313; reg183=reg183+reg338; reg260=reg260-reg337; T reg385=reg312+reg311;
    T reg386=0.44444444444444439511*elem.pos(10)[1]; T reg387=0.092025650515289130841*elem.pos(5)[1]; T reg388=reg340-reg306; reg273=reg273-reg149; reg181=reg339+reg181;
    T reg389=reg308+reg307; T reg390=1.8928203230275508072*elem.pos(7)[1]; reg309=reg309-reg310; T reg391=0.16000000000000001776*elem.pos(10)[1]; T reg392=1.0515668461264170957*elem.pos(7)[0];
    reg354=reg161+reg354; reg161=0.49106836025229589073*elem.pos(5)[2]; T reg393=0.16905989232414971697*elem.pos(9)[2]; reg240=reg240-reg243; T reg394=4.6923546249730193496e-17*elem.pos(6)[2];
    T reg395=0.49106836025229589073*elem.pos(4)[1]; reg91=reg91-reg326; T reg396=0.092025650515289130841*elem.pos(5)[2]; reg315=reg315-reg337; reg285=reg285-reg143;
    T reg397=0.037478521766071383161*elem.pos(1)[1]; T reg398=reg329+reg328; reg292=reg292-reg327; reg54=reg226+reg54; reg226=0.28176648720691616366*elem.pos(9)[2];
    T reg399=0.037478521766071383161*elem.pos(1)[2]; T reg400=0.13459165171168746096*elem.pos(5)[2]; T reg401=0.57282032302755088275*elem.pos(1)[0]; reg186=reg185+reg186; reg185=0.27378906834863934872*elem.pos(4)[0];
    T reg402=0.37559830641437077015*elem.pos(1)[0]; T reg403=0.037478521766071383161*elem.pos(0)[0]; T reg404=0.13459165171168746096*elem.pos(5)[1]; T reg405=0.092025650515289130841*elem.pos(1)[1]; T reg406=0.17464101615137755461*elem.pos(0)[1];
    T reg407=0.13459165171168746096*elem.pos(2)[0]; T reg408=reg330+reg331; reg206=reg206+reg314; T reg409=reg333+reg332; T reg410=reg301+reg302;
    T reg411=0.44444444444444439511*elem.pos(7)[0]; T reg412=0.16000000000000001776*elem.pos(8)[1]; reg79=reg131-reg79; reg94=reg254+reg94; reg77=reg100+reg77;
    reg100=0.13459165171168746096*elem.pos(5)[0]; reg131=0.81282032302755082053*elem.pos(5)[1]; reg76=reg76-reg194; reg126=reg126+reg320; reg196=reg212+reg196;
    reg212=0.28176648720691616366*elem.pos(9)[1]; reg254=0.81282032302755082053*elem.pos(5)[2]; T reg413=0.16000000000000001776*elem.pos(7)[0]; T reg414=reg305+reg304; T reg415=reg345-reg352;
    reg109=reg109-reg189; T reg416=reg298+reg299; T reg417=0.092025650515289130841*elem.pos(1)[0]; T reg418=0.17464101615137755461*elem.pos(0)[0]; reg207=reg266+reg207;
    T reg419=reg297+reg296; T reg420=0.49106836025229589073*elem.pos(3)[2]; T reg421=reg271+reg353; T reg422=reg318-reg319; T reg423=0.092025650515289130841*elem.pos(5)[0];
    T reg424=0.16905989232414971697*elem.pos(9)[1]; T reg425=reg269+reg348; T reg426=reg221+reg300; reg164=reg164-reg346; reg71=reg89+reg71;
    reg251=reg281+reg251; reg89=0.037478521766071383161*elem.pos(4)[0]; T reg427=0.49106836025229589073*elem.pos(3)[1]; reg235=reg317+reg235; reg341=reg158-reg341;
    reg158=4.6923546249730193496e-17*elem.pos(9)[2]; T reg428=0.81282032302755082053*elem.pos(3)[0]; T reg429=reg321-reg322; T reg430=0.44444444444444439511*elem.pos(10)[2]; reg199=reg282+reg199;
    T reg431=0.28176648720691616366*elem.pos(6)[1]; T reg432=reg280+reg349; reg215=reg215-reg303; T reg433=0.16000000000000001776*elem.pos(9)[2]; T reg434=0.27378906834863934872*elem.pos(5)[0];
    T reg435=0.17464101615137755461*elem.pos(5)[0]; T reg436=0.16905989232414971697*elem.pos(10)[1]; reg429=reg427+reg429; T reg437=0.63094010767585032744*elem.pos(8)[0]; T reg438=0.77081185509940458903*elem.pos(3)[0];
    T reg439=reg403-reg402; T reg440=1.8928203230275508072*elem.pos(8)[1]; reg273=reg273+reg390; T reg441=0.17464101615137755461*elem.pos(5)[1]; reg158=reg341+reg158;
    reg185=reg186+reg185; reg186=0.77081185509940458903*elem.pos(5)[1]; reg289=reg164-reg289; reg164=0.092025650515289130841*elem.pos(0)[1]; reg309=reg309-reg161;
    reg181=reg181-reg138; reg341=0.48000000000000000888*elem.pos(10)[2]; T reg442=0.35052228204213907079*elem.pos(6)[2]; T reg443=reg400+reg398; T reg444=0.070441621801729122516*elem.pos(5)[0];
    T reg445=reg321-reg397; reg422=reg422+reg420; reg118=reg118-reg393; reg292=reg357+reg292; reg207=reg207-reg313;
    T reg446=0.16905989232414971697*elem.pos(6)[1]; reg251=reg251-reg89; T reg447=reg423+reg419; reg260=reg260-reg384; reg226=reg54-reg226;
    reg54=reg318-reg399; T reg448=0.37856406460551018245*elem.pos(6)[0]; T reg449=reg404+reg385; reg401=reg150+reg401; reg150=reg425+reg412;
    reg388=reg391+reg388; T reg450=0.48000000000000000888*elem.pos(11)[1]; reg354=reg354+reg392; reg76=reg266+reg76; reg266=0.17464101615137755461*elem.pos(4)[1];
    T reg451=1.0515668461264170957*elem.pos(8)[0]; T reg452=reg335+reg379; T reg453=1.8928203230275508072*elem.pos(8)[2]; T reg454=reg387+reg389; reg183=reg183+reg383;
    T reg455=0.16905989232414971697*elem.pos(10)[2]; T reg456=reg433-reg432; T reg457=0.37856406460551018245*elem.pos(6)[1]; T reg458=reg380+reg381; T reg459=reg307+reg382;
    T reg460=0.48000000000000000888*elem.pos(7)[0]; reg212=reg196-reg212; reg196=0.48000000000000000888*elem.pos(11)[2]; T reg461=reg406+reg405; T reg462=0.77081185509940458903*elem.pos(5)[2];
    reg173=reg173-reg151; T reg463=0.092025650515289130841*elem.pos(2)[1]; reg109=reg282+reg109; reg199=reg199-reg320; reg282=0.19874168162164588299*elem.pos(3)[1];
    T reg464=0.35052228204213907079*elem.pos(6)[1]; T reg465=reg378+reg409; reg206=reg206-reg124; reg94=reg254+reg94; reg254=reg407+reg408;
    T reg466=0.19874168162164588299*elem.pos(3)[0]; T reg467=1.7512105867530111459e-16*elem.pos(8)[0]; reg79=reg392+reg79; reg392=0.16905989232414971697*elem.pos(6)[2]; T reg468=reg296+reg377;
    T reg469=0.17464101615137755461*elem.pos(4)[2]; T reg470=reg290+reg375; reg431=reg215-reg431; reg215=0.28176648720691616366*elem.pos(7)[1]; reg197=reg202+reg197;
    reg234=reg52+reg234; reg52=0.28176648720691616366*elem.pos(10)[2]; reg202=0.4444444444444444691*elem.pos(8)[0]; T reg471=reg410+reg411; reg357=reg376+reg357;
    reg376=0.070441621801729122516*elem.pos(4)[0]; T reg472=0.33811978464829938699*elem.pos(6)[2]; T reg473=0.4444444444444444691*elem.pos(11)[1]; reg248=reg248-reg356; T reg474=reg324+reg355;
    T reg475=0.092025650515289130841*elem.pos(2)[2]; T reg476=0.11094010767585030302*elem.pos(4)[0]; reg126=reg126-reg424; T reg477=0.17464101615137755461*elem.pos(4)[0]; T reg478=1.8928203230275508072*elem.pos(6)[1];
    T reg479=0.28176648720691616366*elem.pos(7)[2]; reg369=reg223-reg369; reg223=0.19874168162164588299*elem.pos(3)[2]; T reg480=reg372+reg370; reg415=reg430+reg415;
    reg371=reg174+reg371; reg174=0.4444444444444444691*elem.pos(11)[2]; reg403=reg403-reg373; T reg481=0.37559830641437077015*elem.pos(0)[0]; T reg482=reg100+reg172;
    T reg483=0.35052228204213907079*elem.pos(6)[0]; T reg484=0.11094010767585030302*elem.pos(3)[0]; T reg485=0.092025650515289130841*elem.pos(0)[0]; T reg486=reg368-reg421; reg81=reg81+reg374;
    T reg487=reg414+reg413; reg247=reg386+reg247; T reg488=0.48000000000000000888*elem.pos(8)[0]; reg163=reg139-reg163; reg131=reg77+reg131;
    reg198=reg203+reg198; reg267=reg383+reg267; reg77=1.2618802153517004798*elem.pos(8)[0]; reg139=0.037478521766071383161*elem.pos(2)[0]; reg203=reg365+reg364;
    reg91=reg91+reg362; reg361=reg361+reg281; T reg489=0.33811978464829938699*elem.pos(6)[1]; T reg490=0.48000000000000000888*elem.pos(10)[1]; reg394=reg240+reg394;
    reg315=reg315-reg395; reg240=0.28176648720691616366*elem.pos(10)[1]; T reg491=reg418+reg417; T reg492=reg278+reg416; reg359=reg363+reg359;
    reg78=reg78-reg155; T reg493=0.17464101615137755461*elem.pos(5)[2]; T reg494=reg367+reg366; T reg495=reg342+reg426; reg285=reg285+reg358;
    reg428=reg235+reg428; reg71=reg71-reg117; reg235=1.8928203230275508072*elem.pos(6)[2]; T reg496=0.092025650515289130841*elem.pos(0)[2]; reg102=reg242+reg102;
    reg242=0.092025650515289130841*elem.pos(2)[0]; T reg497=0.37856406460551018245*elem.pos(6)[2]; reg168=reg148-reg168; reg148=reg396+reg360; T reg498=0.16905989232414971697*elem.pos(7)[2];
    T reg499=0.7698003589195010602*elem.pos(12)[1]; reg309=reg309-reg392; reg428=reg428+reg476; reg464=reg464-reg449; T reg500=0.35052228204213901243*elem.pos(7)[1];
    reg247=reg247+reg473; reg234=reg234+reg484; T reg501=reg318-reg80; T reg502=reg321-reg132; T reg503=0.11094010767585030302*elem.pos(5)[0];
    T reg504=reg481-reg139; T reg505=1.3856406460551017033*elem.pos(12)[2]; reg359=reg359+reg196; T reg506=0.17464101615137755461*elem.pos(1)[0]; reg422=reg462+reg422;
    reg439=reg439-reg438; reg462=0.49106836025229589073*elem.pos(4)[0]; reg401=reg317+reg401; reg198=reg314+reg198; reg314=0.037478521766071383161*elem.pos(1)[0];
    reg317=0.77081185509940458903*elem.pos(4)[2]; reg315=reg315+reg489; reg54=reg420+reg54; T reg507=0.77081185509940458903*elem.pos(4)[1]; reg445=reg427+reg445;
    T reg508=reg242+reg491; T reg509=0.10535898384862248483*elem.pos(3)[0]; T reg510=0.17464101615137755461*elem.pos(2)[0]; reg429=reg186+reg429; reg403=reg403-reg438;
    reg186=reg458+reg460; T reg511=0.49106836025229589073*elem.pos(3)[0]; reg453=reg285-reg453; reg170=reg131-reg170; reg131=0.49106836025229589073*elem.pos(5)[0];
    reg285=reg417+reg485; reg289=reg383+reg289; T reg512=0.50717967697244910395*elem.pos(10)[2]; reg126=reg126+reg436; reg197=reg339+reg197;
    reg248=reg248+reg472; reg180=reg206-reg180; reg179=reg94-reg179; reg94=reg495+reg477; reg206=0.1261880215351700725*elem.pos(6)[2];
    reg235=reg71-reg235; reg357=reg357-reg376; reg71=4.6923546249730193496e-17*elem.pos(6)[0]; reg339=reg493+reg474; reg478=reg78-reg478;
    reg78=4.6923546249730193496e-17*elem.pos(11)[1]; T reg513=0.1261880215351700725*elem.pos(7)[2]; T reg514=reg497-reg148; T reg515=0.35052228204213901243*elem.pos(7)[0]; reg102=reg215+reg102;
    T reg516=0.28176648720691616366*elem.pos(8)[1]; T reg517=0.28176648720691616366*elem.pos(11)[1]; T reg518=reg304+reg492; T reg519=0.16905989232414971697*elem.pos(11)[1]; reg91=reg91+reg436;
    reg361=reg361-reg274; reg394=reg479+reg394; T reg520=0.28176648720691616366*elem.pos(8)[2]; reg393=reg207-reg393; reg207=0.35052228204213901243*elem.pos(7)[2];
    T reg521=reg448-reg447; reg442=reg442-reg443; T reg522=1.8928203230275508072*elem.pos(7)[0]; reg292=reg292-reg444; T reg523=reg366+reg496;
    T reg524=0.17464101615137755461*elem.pos(2)[2]; T reg525=4.6923546249730193496e-17*elem.pos(8)[1]; T reg526=0.10535898384862248483*elem.pos(3)[2]; reg415=reg415+reg174; T reg527=0.7698003589195010602*elem.pos(12)[2];
    T reg528=reg120-reg203; T reg529=0.16905989232414971697*elem.pos(9)[0]; reg215=reg431+reg215; reg267=reg267+reg77; reg257=reg168-reg257;
    reg168=0.17464101615137755461*elem.pos(1)[2]; reg431=reg475+reg494; T reg530=0.19874168162164587908*elem.pos(4)[2]; T reg531=reg480+reg223; reg486=reg490+reg486;
    reg371=reg240+reg371; reg479=reg369+reg479; reg369=4.6923546249730193496e-17*elem.pos(8)[2]; T reg532=reg487+reg488; T reg533=0.48000000000000000888*elem.pos(9)[0];
    reg483=reg483-reg482; T reg534=0.16905989232414971697*elem.pos(11)[2]; reg81=reg455+reg81; T reg535=0.4444444444444444691*elem.pos(9)[0]; reg231=reg163-reg231;
    reg163=reg470+reg469; T reg536=reg471+reg202; T reg537=0.19874168162164587908*elem.pos(4)[1]; T reg538=reg465+reg282; T reg539=0.1261880215351700725*elem.pos(6)[0];
    T reg540=reg435+reg468; T reg541=reg254+reg466; T reg542=0.19874168162164587908*elem.pos(4)[0]; reg326=reg109-reg326; reg109=reg452+reg266;
    T reg543=0.1261880215351700725*elem.pos(6)[1]; T reg544=reg441+reg459; T reg545=0.28176648720691616366*elem.pos(11)[2]; T reg546=4.6923546249730193496e-17*elem.pos(9)[0]; reg451=reg354-reg451;
    reg260=reg260-reg446; reg354=0.16905989232414971697*elem.pos(7)[1]; reg424=reg199-reg424; reg158=reg52+reg158; reg251=reg251-reg338;
    reg199=0.1261880215351700725*elem.pos(7)[1]; T reg547=reg457-reg454; T reg548=1.3856406460551017033*elem.pos(12)[1]; reg388=reg388+reg450; T reg549=0.50717967697244910395*elem.pos(10)[1];
    reg201=reg181-reg201; reg440=reg273-reg440; reg181=0.33811978464829938699*elem.pos(11)[2]; reg118=reg455+reg118; reg273=0.28176648720691616366*elem.pos(6)[0];
    T reg550=0.1261880215351700725*elem.pos(7)[0]; T reg551=0.33811978464829938699*elem.pos(11)[1]; reg226=reg52+reg226; reg173=reg281+reg173; reg52=0.17464101615137755461*elem.pos(1)[1];
    reg281=0.28176648720691616366*elem.pos(9)[0]; reg467=reg79+reg467; reg79=0.33811978464829938699*elem.pos(9)[0]; reg183=reg183-reg437; T reg552=4.6923546249730193496e-17*elem.pos(11)[2];
    reg323=reg76-reg323; reg185=reg434+reg185; reg76=reg405+reg164; reg434=reg340-reg150; T reg553=reg463+reg461;
    T reg554=0.17464101615137755461*elem.pos(2)[1]; reg456=reg341+reg456; T reg555=0.10535898384862248483*elem.pos(3)[1]; reg212=reg240+reg212; reg240=0.66666666666666670528*elem.pos(12)[1];
    T reg556=reg524+reg523; T reg557=0.44444444444444439511*elem.pos(10)[0]; reg212=reg78+reg212; reg281=reg467-reg281; reg517=reg371-reg517;
    reg392=reg422-reg392; reg502=reg427+reg502; reg78=0.28176648720691616366*elem.pos(10)[0]; reg371=0.76980035891950093199*elem.pos(13)[1]; reg422=0.16130768281804421985*elem.pos(3)[2];
    reg179=reg179-reg166; reg170=reg170-reg269; reg247=reg247+reg499; reg467=reg496+reg168; T reg558=reg535-reg536;
    reg446=reg429-reg446; reg545=reg158-reg545; reg207=reg442+reg207; reg158=reg481-reg314; reg507=reg445+reg507;
    reg429=reg164+reg52; reg317=reg54+reg317; reg54=0.16130768281804421985*elem.pos(3)[1]; reg442=reg554+reg76; reg401=reg484+reg401;
    reg552=reg226+reg552; reg226=0.81282032302755082053*elem.pos(4)[0]; reg445=reg485+reg506; reg484=0.16130768281804421985*elem.pos(4)[1]; T reg559=reg553+reg555;
    T reg560=reg538+reg537; T reg561=0.19874168162164587908*elem.pos(5)[1]; T reg562=reg387+reg109; T reg563=0.37856406460551018245*elem.pos(7)[1]; reg543=reg543-reg544;
    reg546=reg451+reg546; reg451=0.66666666666666670528*elem.pos(12)[2]; T reg564=0.37856406460551018245*elem.pos(8)[1]; reg199=reg547+reg199; reg500=reg464+reg500;
    reg464=0.35052228204213907079*elem.pos(8)[1]; reg547=0.16130768281804421985*elem.pos(4)[2]; T reg565=reg431+reg526; reg501=reg420+reg501; T reg566=0.77081185509940458903*elem.pos(5)[0];
    reg504=reg511+reg504; T reg567=0.81282032302755082053*elem.pos(5)[0]; T reg568=reg531+reg530; reg234=reg476+reg234; reg476=0.19874168162164587908*elem.pos(5)[2];
    T reg569=reg396+reg163; T reg570=reg510+reg285; T reg571=0.16130768281804421985*elem.pos(3)[0]; reg321=reg321-reg259; reg415=reg415+reg527;
    T reg572=0.37856406460551018245*elem.pos(7)[2]; reg206=reg206-reg339; T reg573=0.76980035891950093199*elem.pos(13)[2]; T reg574=0.37856406460551018245*elem.pos(8)[2]; reg513=reg514+reg513;
    reg138=reg197-reg138; reg318=reg318-reg249; reg515=reg483+reg515; reg197=0.35052228204213907079*elem.pos(8)[0]; reg124=reg198-reg124;
    reg198=0.35052228204213907079*elem.pos(8)[2]; reg528=reg341+reg528; reg483=0.16000000000000001776*elem.pos(11)[2]; reg514=0.16905989232414971697*elem.pos(8)[2]; reg248=reg498+reg248;
    reg201=reg201-reg280; reg393=reg455+reg393; T reg575=0.28176648720691616366*elem.pos(7)[0]; reg235=reg358+reg235; reg358=0.50717967697244910395*elem.pos(9)[2];
    reg428=reg503+reg428; reg71=reg357+reg71; reg434=reg490+reg434; reg357=0.16000000000000001776*elem.pos(11)[1]; T reg576=0.46188021535170061048*elem.pos(12)[2];
    reg456=reg196+reg456; reg359=reg359+reg505; reg424=reg424+reg436; reg251=reg383+reg251; reg350=reg231+reg350;
    reg231=0.46188021535170061048*elem.pos(13)[1]; reg388=reg388+reg548; reg383=0.16905989232414971697*elem.pos(8)[1]; reg326=reg326-reg362; T reg577=0.33811978464829938699*elem.pos(8)[1];
    reg260=reg260+reg354; reg323=reg323-reg374; reg520=reg394-reg520; reg289=reg289-reg77; reg394=reg488+reg186;
    reg403=reg403-reg131; T reg578=0.16000000000000001776*elem.pos(9)[0]; T reg579=0.33811978464829938699*elem.pos(8)[2]; T reg580=0.50717967697244910395*elem.pos(11)[2]; reg180=reg180-reg271;
    T reg581=0.16905989232414971697*elem.pos(6)[0]; T reg582=1.7512105867530111459e-16*elem.pos(9)[1]; reg453=reg512+reg453; T reg583=1.7512105867530111459e-16*elem.pos(9)[2]; reg516=reg102-reg516;
    reg102=0.50717967697244910395*elem.pos(11)[1]; reg440=reg549+reg440; reg539=reg539-reg540; T reg584=0.37856406460551018245*elem.pos(7)[0]; reg478=reg390+reg478;
    reg390=0.50717967697244910395*elem.pos(9)[1]; reg309=reg309+reg498; reg118=reg118+reg181; T reg585=1.8928203230275508072*elem.pos(8)[0]; reg361=reg361+reg522;
    reg273=reg292-reg273; reg292=0.46188021535170061048*elem.pos(12)[1]; reg486=reg450+reg486; T reg586=0.46188021535170061048*elem.pos(13)[2]; T reg587=1.8928203230275508072*elem.pos(6)[0];
    reg183=reg183+reg79; reg91=reg91-reg519; T reg588=1.0515668461264170957*elem.pos(9)[2]; T reg589=reg460+reg518; T reg590=0.16000000000000001776*elem.pos(8)[0];
    reg369=reg479+reg369; reg479=reg541+reg542; T reg591=reg508+reg509; T reg592=0.16130768281804421985*elem.pos(4)[0]; reg81=reg81-reg534;
    T reg593=0.19874168162164587908*elem.pos(5)[0]; T reg594=reg423+reg94; T reg595=0.33811978464829938699*elem.pos(6)[0]; reg267=reg267-reg529; reg439=reg439-reg462;
    T reg596=reg533-reg532; T reg597=0.16000000000000001776*elem.pos(10)[0]; reg126=reg126+reg551; T reg598=0.37856406460551018245*elem.pos(8)[0]; reg550=reg521+reg550;
    reg315=reg354+reg315; reg521=1.0515668461264170957*elem.pos(9)[1]; reg302=reg185-reg302; reg173=reg173-reg70; reg525=reg215+reg525;
    reg185=0.16905989232414971697*elem.pos(10)[0]; reg345=reg257+reg345; reg215=0.46188021535170061048*elem.pos(14)[2]; reg321=reg427+reg321; reg226=reg401+reg226;
    reg430=reg345+reg430; reg257=reg475+reg467; reg180=reg340+reg180; reg521=reg525-reg521; reg118=reg118-reg451;
    reg126=reg126-reg240; reg390=reg478-reg390; reg345=reg570+reg571; reg401=0.48000000000000000888*elem.pos(10)[0]; reg427=0.10143593539448982642*elem.pos(9)[2];
    reg478=0.66666666666666670528*elem.pos(14)[2]; reg513=reg513+reg574; reg539=reg539+reg584; reg317=reg317-reg472; reg525=0.16905989232414971697*elem.pos(7)[0];
    T reg599=reg565+reg547; reg582=reg516+reg582; reg516=1.0515668461264170957*elem.pos(10)[1]; reg439=reg439+reg595; T reg600=reg578-reg394;
    reg552=reg552-reg451; T reg601=reg556+reg422; T reg602=reg589+reg590; reg318=reg420+reg318; reg588=reg369-reg588;
    reg434=reg434+reg357; reg587=reg173-reg587; reg206=reg206+reg572; reg437=reg251-reg437; reg386=reg350+reg386;
    reg173=0.77081185509940458903*elem.pos(4)[0]; reg251=0.66666666666666670528*elem.pos(14)[1]; reg212=reg212-reg240; reg497=reg497-reg569; reg158=reg511+reg158;
    reg350=1.2618802153517004798*elem.pos(9)[1]; reg315=reg315-reg383; reg269=reg124-reg269; reg124=reg242+reg445; reg436=reg326+reg436;
    reg323=reg455+reg323; reg183=reg185+reg183; reg326=0.76980035891950093199*elem.pos(14)[2]; reg415=reg415+reg573; reg369=0.16905989232414971697*elem.pos(11)[0];
    reg359=reg359+reg586; reg420=0.16130768281804421985*elem.pos(5)[2]; reg455=0.093922162402305398307*elem.pos(6)[2]; reg528=reg528+reg483; T reg603=1.2618802153517004798*elem.pos(9)[2];
    reg248=reg248-reg514; reg507=reg507-reg489; reg448=reg448-reg594; T reg604=0.28176648720691616366*elem.pos(8)[0]; reg166=reg138-reg166;
    reg71=reg71+reg575; reg138=reg476+reg568; reg358=reg235-reg358; reg235=1.0515668461264170957*elem.pos(10)[2]; T reg605=0.48000000000000000888*elem.pos(11)[0];
    T reg606=0.46188021535170061048*elem.pos(14)[1]; T reg607=0.66666666666666670528*elem.pos(13)[2]; reg545=reg545-reg451; reg424=reg424-reg551; reg596=reg597+reg596;
    T reg608=0.10143593539448982642*elem.pos(9)[1]; reg456=reg456+reg576; reg199=reg199+reg564; reg428=reg428-reg304; reg502=reg502-reg395;
    T reg609=0.50717967697244910395*elem.pos(7)[1]; T reg610=0.63094010767585032744*elem.pos(9)[1]; reg280=reg179-reg280; reg393=reg393-reg181; reg201=reg120+reg201;
    reg179=0.66666666666666670528*elem.pos(13)[1]; reg517=reg517-reg240; T reg611=0.093922162402305398307*elem.pos(6)[1]; T reg612=0.33811978464829938699*elem.pos(11)[0]; T reg613=0.4444444444444444691*elem.pos(11)[0];
    reg543=reg543+reg563; reg558=reg557+reg558; reg411=reg302-reg411; reg392=reg498+reg392; reg550=reg550+reg598;
    reg302=0.10143593539448982642*elem.pos(9)[0]; T reg614=0.16130768281804421985*elem.pos(5)[0]; T reg615=reg591+reg592; reg271=reg170-reg271; reg260=reg260+reg577;
    reg170=reg442+reg54; T reg616=4.6923546249730193496e-17*elem.pos(11)[0]; reg281=reg78+reg281; T reg617=reg463+reg429; T reg618=reg481-reg402;
    T reg619=reg559+reg484; T reg620=0.16130768281804421985*elem.pos(5)[1]; reg388=reg388+reg231; T reg621=0.093922162402305398307*elem.pos(6)[0]; reg198=reg207+reg198;
    reg207=0.093922162402305398307*elem.pos(9)[2]; T reg622=0.28176648720691616366*elem.pos(11)[0]; reg546=reg78+reg546; reg446=reg354+reg446; reg102=reg440-reg102;
    reg583=reg520+reg583; reg78=0.093922162402305398307*elem.pos(9)[1]; reg403=reg403-reg581; reg234=reg567+reg234; reg464=reg500+reg464;
    reg580=reg453-reg580; reg309=reg309+reg579; reg440=0.63094010767585032744*elem.pos(9)[2]; reg457=reg457-reg562; reg453=0.76980035891950093199*elem.pos(14)[1];
    reg247=reg247+reg371; reg529=reg289-reg529; reg486=reg486+reg292; reg273=reg575+reg273; reg289=4.6923546249730193496e-17*elem.pos(8)[0];
    reg81=reg81-reg451; reg500=reg593+reg479; reg520=0.50717967697244910395*elem.pos(7)[2]; reg91=reg91-reg240; reg197=reg515+reg197;
    reg501=reg501-reg356; reg515=0.50717967697244910395*elem.pos(10)[0]; reg585=reg361-reg585; reg361=0.093922162402305398307*elem.pos(9)[0]; reg567=reg561+reg560;
    reg267=reg185+reg267; reg504=reg566+reg504; reg543=reg564+reg543; reg457=reg563+reg457; reg563=0.10535898384862248483*elem.pos(5)[2];
    reg564=0.10143593539448982642*elem.pos(6)[1]; reg118=reg118+reg478; reg226=reg503+reg226; reg611=reg611-reg567; reg503=0.1261880215351700725*elem.pos(8)[1];
    reg566=0.033811978464829945269*elem.pos(9)[1]; reg575=reg620+reg619; T reg623=0.10143593539448982642*elem.pos(6)[2]; T reg624=0.093922162402305382675*elem.pos(7)[1]; T reg625=0.093922162402305382675*elem.pos(7)[0];
    T reg626=reg420+reg599; reg174=reg430+reg174; reg455=reg455-reg138; reg430=0.093922162402305382675*elem.pos(7)[2]; reg621=reg621-reg500;
    T reg627=0.093922162402305382675*elem.pos(10)[2]; reg201=reg363+reg201; reg604=reg71-reg604; reg71=1.7512105867530111459e-16*elem.pos(9)[0]; reg363=1.0515668461264170957*elem.pos(9)[0];
    reg289=reg273+reg289; reg273=0.63094010767585032744*elem.pos(10)[2]; reg359=reg359+reg215; reg513=reg513+reg427; T reg628=0.033811978464829945269*elem.pos(10)[1];
    T reg629=1.0515668461264170957*elem.pos(11)[2]; reg583=reg235+reg583; T reg630=0.093922162402305382675*elem.pos(10)[1]; reg207=reg198+reg207; reg198=0.033811978464829945269*elem.pos(10)[2];
    reg78=reg464+reg78; reg180=reg391+reg180; reg309=reg309-reg440; reg582=reg516+reg582; reg391=1.0515668461264170957*elem.pos(11)[1];
    reg588=reg235+reg588; reg235=0.10535898384862248483*elem.pos(5)[1]; reg464=1.7512105867530111459e-16*elem.pos(11)[2]; reg202=reg411-reg202; reg411=0.63094010767585032744*elem.pos(10)[1];
    T reg631=reg571+reg124; T reg632=0.10535898384862248483*elem.pos(4)[0]; T reg633=0.1261880215351700725*elem.pos(8)[2]; reg497=reg572+reg497; reg572=reg484+reg170;
    T reg634=reg54+reg617; T reg635=0.10535898384862248483*elem.pos(4)[1]; reg473=reg386+reg473; reg386=0.033811978464829945269*elem.pos(9)[2]; reg206=reg574+reg206;
    reg126=reg126+reg251; reg199=reg199+reg608; reg260=reg260-reg610; reg388=reg388+reg606; reg501=reg501+reg520;
    reg574=0.50717967697244910395*elem.pos(8)[2]; reg486=reg231+reg486; T reg636=1.3856406460551017033*elem.pos(14)[1]; reg585=reg515+reg585; reg581=reg504-reg581;
    reg504=0.66666666666666670528*elem.pos(12)[0]; reg622=reg546-reg622; reg546=0.50717967697244910395*elem.pos(11)[0]; reg102=reg102-reg240; T reg637=0.33811978464829938699*elem.pos(8)[0];
    reg403=reg525+reg403; reg381=reg234-reg381; reg580=reg580-reg451; reg247=reg247+reg453; reg529=reg185+reg529;
    reg234=0.10535898384862248483*elem.pos(5)[0]; reg600=reg401+reg600; T reg638=reg592+reg345; reg552=reg552+reg478; reg539=reg598+reg539;
    reg598=0.033811978464829945269*elem.pos(9)[0]; reg321=reg321-reg384; T reg639=0.50717967697244910395*elem.pos(6)[1]; reg415=reg415+reg326; reg390=reg549+reg390;
    reg446=reg446-reg577; reg361=reg197+reg361; reg91=reg91+reg179; reg81=reg81+reg607; reg267=reg267+reg612;
    reg280=reg433+reg280; reg596=reg596+reg605; reg197=0.093922162402305382675*elem.pos(10)[0]; reg433=0.10143593539448982642*elem.pos(6)[0]; reg549=reg614+reg615;
    reg392=reg392-reg579; T reg640=0.7698003589195010602*elem.pos(12)[0]; reg558=reg558+reg613; T reg641=1.3856406460551017033*elem.pos(12)[0]; T reg642=0.033811978464829945269*elem.pos(10)[0];
    reg271=reg368+reg271; reg550=reg550+reg302; reg616=reg281+reg616; reg413=reg428-reg413; reg618=reg618+reg511;
    reg545=reg545+reg607; reg424=reg424-reg240; reg456=reg586+reg456; reg502=reg502+reg609; reg281=0.50717967697244910395*elem.pos(8)[1];
    reg368=1.3856406460551017033*elem.pos(14)[2]; reg517=reg517+reg179; reg393=reg393-reg451; reg437=reg437-reg79; reg428=1.7512105867530111459e-16*elem.pos(11)[1];
    reg212=reg212+reg251; reg317=reg498+reg317; reg315=reg315+reg350; reg439=reg439+reg525; reg412=reg269-reg412;
    reg519=reg436-reg519; reg269=0.16905989232414971697*elem.pos(8)[0]; reg436=reg422+reg257; reg498=0.10535898384862248483*elem.pos(4)[2]; reg534=reg323-reg534;
    reg183=reg183-reg369; reg173=reg158+reg173; reg587=reg522+reg587; reg158=0.50717967697244910395*elem.pos(9)[0]; reg323=reg533-reg602;
    reg507=reg354+reg507; reg448=reg584+reg448; reg354=0.1261880215351700725*elem.pos(8)[0]; reg364=reg166-reg364; reg166=1.3856406460551017033*elem.pos(13)[2];
    reg521=reg516+reg521; reg248=reg248+reg603; reg358=reg512+reg358; reg318=reg318-reg161; reg512=0.50717967697244910395*elem.pos(6)[2];
    reg481=reg481-reg373; reg516=reg547+reg601; reg522=1.3856406460551017033*elem.pos(13)[1]; reg528=reg576+reg528; reg434=reg292+reg434;
    reg584=0.10143593539448982642*elem.pos(11)[0]; T reg643=0.093922162402305398307*elem.pos(11)[0]; T reg644=0.033811978464829945269*elem.pos(6)[1]; T reg645=reg235+reg572; reg616=reg616-reg504;
    T reg646=0.66666666666666670528*elem.pos(14)[0]; reg550=reg642+reg550; reg503=reg457+reg503; reg183=reg183-reg504; reg174=reg174-reg527;
    reg354=reg448+reg354; reg448=0.093922162402305398307*elem.pos(8)[2]; reg430=reg455+reg430; reg455=reg563+reg516; reg267=reg267-reg504;
    reg624=reg611+reg624; reg457=0.093922162402305398307*elem.pos(8)[1]; reg521=reg428+reg521; reg535=reg202+reg535; reg202=0.033811978464829945269*elem.pos(6)[2];
    reg428=reg388*reg81; reg611=reg359*reg91; reg642=0.76980035891950093199*elem.pos(13)[0]; reg558=reg558+reg640; T reg647=reg564-reg575;
    T reg648=reg623-reg626; T reg649=0.033811978464829945269*elem.pos(7)[1]; T reg650=0.033811978464829945269*elem.pos(7)[2]; reg361=reg197+reg361; reg596=reg596+reg641;
    reg197=0.46188021535170061048*elem.pos(13)[0]; T reg651=reg436+reg498; reg546=reg585-reg546; reg102=reg102+reg179; reg437=reg185+reg437;
    reg473=reg473-reg499; reg580=reg580+reg607; reg185=reg552*reg247; reg386=reg206+reg386; reg434=reg434+reg522;
    reg391=reg582-reg391; reg529=reg529-reg612; reg600=reg605+reg600; reg206=1.0515668461264170957*elem.pos(10)[0]; reg582=0.46188021535170061048*elem.pos(12)[0];
    reg585=0.10143593539448982642*elem.pos(10)[0]; reg358=reg358-reg451; reg598=reg539+reg598; reg539=reg212*reg415; reg528=reg528+reg166;
    reg390=reg390-reg240; reg513=reg198+reg513; reg198=0.10143593539448982642*elem.pos(11)[2]; reg71=reg604+reg71; reg604=reg634+reg635;
    reg247=reg247*reg545; reg424=reg424+reg251; T reg652=0.16000000000000001776*elem.pos(11)[0]; reg323=reg401+reg323; reg388=reg118*reg388;
    reg456=reg456+reg368; reg363=reg289-reg363; reg415=reg415*reg517; reg158=reg587-reg158; reg393=reg393+reg478;
    reg464=reg588+reg464; reg534=reg534-reg451; reg486=reg486+reg636; reg289=0.66666666666666670528*elem.pos(13)[0]; reg629=reg583-reg629;
    reg519=reg519-reg240; reg622=reg622-reg504; reg633=reg497+reg633; reg207=reg627+reg207; reg497=0.093922162402305398307*elem.pos(11)[2];
    reg583=0.10143593539448982642*elem.pos(10)[2]; reg574=reg501-reg574; reg501=reg631+reg632; reg581=reg525+reg581; reg440=reg392-reg440;
    reg392=1.2618802153517004798*elem.pos(11)[1]; reg587=0.63094010767585032744*elem.pos(9)[0]; reg403=reg403+reg637; reg381=reg381-reg460; reg588=reg433-reg549;
    reg304=reg226-reg304; reg566=reg543+reg566; reg226=reg234+reg638; reg481=reg511+reg481; reg511=0.033811978464829945269*elem.pos(6)[0];
    reg280=reg341+reg280; reg543=0.033811978464829945269*elem.pos(7)[0]; reg514=reg317-reg514; reg439=reg439-reg269; reg317=0.10143593539448982642*elem.pos(10)[1];
    reg413=reg413-reg488; reg201=reg196+reg201; reg260=reg411+reg260; reg199=reg628+reg199; reg627=0.10143593539448982642*elem.pos(11)[1];
    reg628=0.093922162402305398307*elem.pos(11)[1]; reg78=reg630+reg78; reg309=reg273+reg309; reg630=1.2618802153517004798*elem.pos(11)[2]; reg271=reg490+reg271;
    reg180=reg450+reg180; reg359=reg126*reg359; reg618=reg618-reg462; T reg653=0.50717967697244910395*elem.pos(7)[0]; T reg654=1.8928203230275508072*elem.pos(10)[1];
    reg281=reg502-reg281; reg502=1.8928203230275508072*elem.pos(10)[2]; reg248=reg273+reg248; reg364=reg120+reg364; reg120=0.63094010767585032744*elem.pos(11)[2];
    reg173=reg173-reg595; reg610=reg446-reg610; reg412=reg340+reg412; reg315=reg411+reg315; reg340=0.63094010767585032744*elem.pos(11)[1];
    reg512=reg318-reg512; reg639=reg321-reg639; reg318=1.2618802153517004798*elem.pos(9)[0]; reg625=reg621+reg625; reg321=0.093922162402305398307*elem.pos(8)[0];
    reg383=reg507-reg383; reg446=1.8928203230275508072*elem.pos(11)[1]; reg386=reg583+reg386; reg358=reg358+reg478; reg512=reg520+reg512;
    reg507=reg424*reg456; reg520=0.50717967697244910395*elem.pos(8)[0]; reg71=reg206+reg71; reg621=1.0515668461264170957*elem.pos(11)[0]; reg323=reg323+reg652;
    reg618=reg618+reg653; reg281=reg654+reg281; T reg655=1.8928203230275508072*elem.pos(9)[2]; reg574=reg502+reg574; reg434=reg606+reg434;
    reg247=reg415-reg247; reg629=reg629-reg451; reg550=reg550+reg584; reg315=reg315-reg340; reg497=reg207+reg497;
    reg207=0.22222222222222225976*elem.pos(12)[2]; reg415=0.40000000000000000835*elem.pos(12)[0]; T reg656=0.22222222222222225976*elem.pos(12)[1]; reg628=reg78+reg628; reg412=reg490+reg412;
    reg519=reg519+reg179; reg369=reg437-reg369; reg391=reg391-reg240; reg534=reg534+reg607; reg309=reg309+reg630;
    reg173=reg525+reg173; reg180=reg180-reg548; reg158=reg515+reg158; reg513=reg513+reg198; reg78=0.40000000000000000835*elem.pos(12)[2];
    reg437=0.63094010767585032744*elem.pos(10)[0]; reg529=reg529-reg504; reg521=reg521-reg240; reg650=reg648+reg650; reg490=0.10143593539448982642*elem.pos(8)[2];
    reg390=reg390+reg251; reg515=1.8928203230275508072*elem.pos(9)[1]; reg600=reg600+reg582; reg388=reg359-reg388; reg359=0.50717967697244910395*elem.pos(6)[0];
    reg481=reg481-reg131; reg639=reg609+reg639; reg248=reg248-reg120; reg525=reg420+reg651; reg511=reg511-reg226;
    reg202=reg202-reg455; reg609=0.10143593539448982642*elem.pos(7)[2]; reg648=0.10143593539448982642*elem.pos(7)[0]; reg598=reg585+reg598; reg514=reg514-reg603;
    reg439=reg439+reg318; T reg657=1.8928203230275508072*elem.pos(11)[2]; reg473=reg473-reg371; T reg658=reg393*reg486; T reg659=reg614+reg501;
    reg364=reg341+reg364; reg633=reg427+reg633; reg622=reg622+reg289; reg581=reg581-reg637; reg464=reg464-reg451;
    reg383=reg383-reg350; reg546=reg546-reg504; reg403=reg403-reg587; reg354=reg302+reg354; reg456=reg456*reg102;
    reg528=reg215+reg528; reg448=reg430+reg448; reg302=0.35052228204213907079*elem.pos(9)[2]; reg488=reg381-reg488; reg185=reg539-reg185;
    reg486=reg486*reg580; reg174=reg174-reg573; reg460=reg304-reg460; reg304=reg620+reg604; reg199=reg199+reg627;
    reg341=0.40000000000000000835*elem.pos(12)[1]; reg321=reg625+reg321; reg381=0.35052228204213907079*elem.pos(9)[0]; reg81=reg126*reg81; reg91=reg118*reg91;
    reg118=0.10143593539448982642*elem.pos(7)[1]; reg644=reg644-reg645; reg126=0.46188021535170061048*elem.pos(14)[0]; reg596=reg596+reg197; reg427=0.22222222222222225976*elem.pos(12)[0];
    reg643=reg361+reg643; reg440=reg273+reg440; reg610=reg411+reg610; reg558=reg558+reg642; reg361=0.76980035891950093199*elem.pos(14)[0];
    reg517=reg552*reg517; reg545=reg212*reg545; reg457=reg624+reg457; reg212=0.35052228204213907079*elem.pos(9)[1]; reg430=0.10143593539448982642*elem.pos(8)[1];
    reg649=reg647+reg649; reg280=reg196+reg280; reg566=reg317+reg566; reg557=reg535+reg557; reg428=reg611-reg428;
    reg267=reg267+reg646; reg543=reg588+reg543; reg196=0.10143593539448982642*elem.pos(8)[0]; reg363=reg206+reg363; reg260=reg392+reg260;
    reg271=reg450+reg271; reg413=reg533+reg413; reg616=reg616+reg646; reg201=reg201-reg505; reg183=reg183+reg289;
    reg206=1.7512105867530111459e-16*elem.pos(11)[0]; reg503=reg608+reg503; reg450=0.22222222222222222276*elem.pos(13)[1]; reg515=reg639-reg515; reg412=reg357+reg412;
    reg488=reg578+reg488; reg183=reg388*reg183; reg302=reg448+reg302; reg486=reg456-reg486; reg610=reg610-reg392;
    reg357=reg390*reg528; reg590=reg460-reg590; reg545=reg517-reg545; reg628=reg628+reg656; reg558=reg558+reg361;
    reg174=reg174-reg326; reg388=0.033811978464829945269*elem.pos(11)[0]; reg403=reg437+reg403; reg354=reg585+reg354; reg546=reg546+reg289;
    reg497=reg497+reg207; reg448=0.22222222222222222276*elem.pos(13)[2]; reg383=reg411+reg383; reg587=reg581-reg587; reg528=reg528*reg519;
    reg411=0.35052228204213901243*elem.pos(10)[2]; reg440=reg440-reg630; reg456=1.2618802153517004798*elem.pos(11)[0]; reg460=0.35052228204213901243*elem.pos(10)[0]; reg511=reg511+reg648;
    reg202=reg202+reg609; reg503=reg317+reg503; reg317=0.13333333333333334846*elem.pos(12)[1]; reg629=reg629+reg607; reg543=reg543+reg196;
    reg598=reg584+reg598; reg267=reg428*reg267; reg514=reg273+reg514; reg613=reg557+reg613; reg359=reg481-reg359;
    reg273=0.033811978464829945269*elem.pos(11)[1]; reg580=reg424*reg580; reg102=reg393*reg102; reg393=0.37856406460551018245*elem.pos(9)[0]; reg424=1.3856406460551017033*elem.pos(14)[0];
    reg600=reg197+reg600; reg566=reg627+reg566; reg428=1.8928203230275508072*elem.pos(10)[0]; reg248=reg248-reg451; reg481=0.13333333333333334846*elem.pos(12)[0];
    reg517=0.37856406460551018245*elem.pos(9)[2]; reg650=reg650+reg490; reg201=reg201-reg586; reg623=reg623-reg525; reg529=reg529+reg646;
    reg280=reg280-reg576; reg521=reg521+reg251; reg649=reg649+reg430; reg535=0.37856406460551018245*elem.pos(9)[1]; reg212=reg457+reg212;
    reg457=0.13333333333333334846*elem.pos(12)[2]; reg386=reg198+reg386; reg446=reg281-reg446; reg81=reg91-reg81; reg381=reg321+reg381;
    reg616=reg247*reg616; reg369=reg369-reg504; reg655=reg512-reg655; reg91=0.35052228204213901243*elem.pos(10)[1]; reg198=reg358*reg434;
    reg520=reg618-reg520; reg158=reg158-reg504; reg247=0.13333333333333334846*elem.pos(13)[1]; reg199=reg199+reg341; reg391=reg391+reg179;
    reg643=reg643+reg427; reg281=0.13333333333333334846*elem.pos(13)[2]; reg513=reg513+reg78; reg564=reg564-reg304; reg269=reg173-reg269;
    reg173=0.22222222222222222276*elem.pos(13)[0]; reg180=reg180-reg231; reg621=reg71-reg621; reg434=reg434*reg534; reg71=0.13333333333333334846*elem.pos(13)[0];
    reg413=reg597+reg413; reg315=reg315-reg240; reg309=reg309-reg451; reg622=reg185*reg622; reg439=reg437+reg439;
    reg185=0.63094010767585032744*elem.pos(11)[0]; reg321=0.033811978464829945269*elem.pos(11)[2]; reg633=reg583+reg633; reg550=reg550+reg415; reg206=reg363+reg206;
    reg260=reg260-reg240; reg433=reg433-reg659; reg364=reg483+reg364; reg464=reg464+reg478; reg658=reg507-reg658;
    reg644=reg644+reg118; reg473=reg473-reg453; reg323=reg582+reg323; reg271=reg271-reg292; reg596=reg596+reg126;
    reg363=1.3856406460551017033*elem.pos(13)[0]; reg657=reg574-reg657; reg515=reg654+reg515; reg369=reg369+reg289; reg511=reg196+reg511;
    reg643=reg643+reg173; reg196=0.1261880215351700725*elem.pos(9)[0]; reg566=reg566+reg317; reg340=reg383-reg340; reg434=reg528-reg434;
    reg439=reg439-reg185; reg383=0.35052228204213907079*elem.pos(11)[0]; reg610=reg610-reg240; reg483=0.033811978464829945269*elem.pos(8)[2]; reg269=reg269-reg318;
    reg381=reg460+reg381; reg315=reg315+reg179; reg273=reg503+reg273; reg623=reg609+reg623; reg655=reg502+reg655;
    reg364=reg364-reg576; reg460=0.22222222222222222276*elem.pos(14)[0]; reg519=reg358*reg519; reg534=reg390*reg534; reg323=reg323+reg363;
    reg388=reg354+reg388; reg543=reg543+reg393; reg158=reg158+reg646; reg198=reg357-reg198; reg354=0.35052228204213907079*elem.pos(11)[1];
    reg412=reg412-reg292; reg598=reg598+reg481; reg212=reg91+reg212; reg206=reg206-reg504; reg413=reg605+reg413;
    reg199=reg199+reg247; reg520=reg428+reg520; reg91=1.8928203230275508072*elem.pos(11)[0]; reg357=0.13333333333333334846*elem.pos(14)[1]; reg81=reg596*reg81;
    reg358=reg464*reg473; reg446=reg446-reg240; reg386=reg386+reg457; reg390=0.1261880215351700725*elem.pos(9)[1]; reg644=reg430+reg644;
    reg657=reg657-reg451; reg430=0.033811978464829945269*elem.pos(8)[0]; reg433=reg648+reg433; reg321=reg633+reg321; reg403=reg403+reg456;
    reg440=reg440-reg451; reg587=reg437+reg587; reg473=reg473*reg629; reg271=reg271-reg231; reg201=reg201-reg215;
    reg502=0.22222222222222222276*elem.pos(14)[1]; reg628=reg628+reg450; reg260=reg260+reg251; reg497=reg497+reg448; reg503=0.22222222222222222276*elem.pos(14)[2];
    reg507=reg174*reg391; reg616=reg622-reg616; reg309=reg309+reg478; reg512=0.033811978464829945269*elem.pos(8)[1]; reg550=reg550+reg71;
    reg621=reg621-reg504; reg180=reg180-reg606; reg564=reg118+reg564; reg118=0.13333333333333334846*elem.pos(14)[0]; reg513=reg513+reg281;
    reg528=0.13333333333333334846*elem.pos(14)[2]; reg488=reg401+reg488; reg280=reg280-reg586; reg539=0.1261880215351700725*elem.pos(10)[2]; reg649=reg649+reg535;
    reg529=reg486*reg529; reg486=1.8928203230275508072*elem.pos(9)[0]; reg267=reg183-reg267; reg650=reg650+reg517; reg248=reg248+reg607;
    reg600=reg600+reg424; reg359=reg653+reg359; reg613=reg613-reg640; reg580=reg102-reg580; reg120=reg514-reg120;
    reg102=0.1261880215351700725*elem.pos(10)[1]; reg202=reg490+reg202; reg183=0.1261880215351700725*elem.pos(9)[2]; reg490=0.35052228204213907079*elem.pos(11)[2]; reg546=reg658*reg546;
    reg174=reg521*reg174; reg590=reg533+reg590; reg302=reg411+reg302; reg411=0.1261880215351700725*elem.pos(10)[0]; reg545=reg558*reg545;
    reg657=reg657+reg607; reg543=reg411+reg543; reg411=reg201*reg315; reg545=reg616+reg545; reg403=reg403-reg504;
    reg440=reg440+reg478; reg643=reg643+reg460; reg580=reg600*reg580; reg196=reg511+reg196; reg587=reg587-reg456;
    reg271=reg271-reg636; reg511=0.37856406460551018245*elem.pos(11)[0]; reg446=reg446+reg179; reg280=reg280-reg368; reg81=reg267+reg81;
    reg413=reg413-reg641; reg488=reg605+reg488; reg91=reg520-reg91; reg515=reg515-reg240; reg610=reg610+reg251;
    reg267=0.40000000000000000835*elem.pos(14)[0]; reg598=reg71+reg598; reg364=reg364-reg166; reg529=reg546-reg529; reg550=reg550+reg118;
    reg514=0.37856406460551018245*elem.pos(10)[0]; reg520=reg180*reg248; reg655=reg655-reg451; reg486=reg359-reg486; reg650=reg539+reg650;
    reg359=0.37856406460551018245*elem.pos(11)[2]; reg390=reg644+reg390; reg199=reg199+reg357; reg533=0.37856406460551018245*elem.pos(10)[2]; reg451=reg120-reg451;
    reg183=reg202+reg183; reg120=0.37856406460551018245*elem.pos(10)[1]; reg202=0.37856406460551018245*elem.pos(11)[1]; reg649=reg102+reg649; reg483=reg623+reg483;
    reg383=reg381+reg383; reg613=reg613-reg642; reg391=reg464*reg391; reg629=reg521*reg629; reg354=reg212+reg354;
    reg102=0.40000000000000000835*elem.pos(14)[2]; reg386=reg281+reg386; reg430=reg433+reg430; reg321=reg457+reg321; reg212=0.40000000000000000835*elem.pos(13)[2];
    reg358=reg174-reg358; reg180=reg309*reg180; reg513=reg513+reg528; reg621=reg621+reg289; reg497=reg497+reg503;
    reg590=reg401+reg590; reg490=reg302+reg490; reg628=reg628+reg502; reg473=reg507-reg473; reg201=reg260*reg201;
    reg512=reg564+reg512; reg206=reg206+reg646; reg388=reg481+reg388; reg174=0.40000000000000000835*elem.pos(13)[0]; reg158=reg434*reg158;
    reg269=reg437+reg269; reg302=0.40000000000000000835*elem.pos(13)[1]; reg534=reg519-reg534; reg381=0.40000000000000000835*elem.pos(14)[1]; reg273=reg317+reg273;
    reg323=reg126+reg323; reg566=reg247+reg566; reg240=reg340-reg240; reg439=reg439-reg504; reg369=reg198*reg369;
    reg412=reg412-reg522; reg413=reg413-reg197; reg158=reg369-reg158; reg590=reg652+reg590; reg185=reg269-reg185;
    reg643=reg545*reg643; reg490=reg207+reg490; reg512=reg535+reg512; reg628=reg628*reg545; reg439=reg439+reg289;
    reg488=reg488-reg582; reg198=reg440*reg271; reg273=reg273+reg302; reg386=reg386+reg102; reg207=reg280*reg446;
    reg430=reg393+reg430; reg412=reg412-reg606; reg271=reg271*reg657; reg403=reg403+reg646; reg321=reg321+reg212;
    reg478=reg655+reg478; reg91=reg91-reg504; reg180=reg201-reg180; reg587=reg587-reg504; reg513=reg81*reg513;
    reg550=reg81*reg550; reg621=reg358*reg621; reg497=reg497*reg545; reg580=reg529+reg580; reg607=reg451+reg607;
    reg183=reg533+reg183; reg206=reg473*reg206; reg388=reg388+reg174; reg196=reg514+reg196; reg649=reg649+reg202;
    reg280=reg610*reg280; reg566=reg566+reg381; reg483=reg517+reg483; reg598=reg598+reg267; reg427=reg383+reg427;
    reg251=reg515+reg251; reg613=reg613-reg361; reg179=reg240+reg179; reg354=reg656+reg354; reg543=reg543+reg511;
    reg315=reg309*reg315; reg486=reg428+reg486; reg520=reg411-reg520; reg364=reg364-reg215; reg650=reg650+reg359;
    reg390=reg120+reg390; reg629=reg391-reg629; reg248=reg260*reg248; reg199=reg81*reg199; reg534=reg323*reg534;
    reg413=reg413-reg126; reg403=reg520*reg403; reg354=reg450+reg354; reg543=reg415+reg543; reg390=reg202+reg390;
    reg629=reg613*reg629; reg273=reg357+reg273; reg201=0.1261880215351700725*elem.pos(11)[0]; reg248=reg315-reg248; reg512=reg120+reg512;
    reg643=0.140625*reg643; reg120=0.1261880215351700725*elem.pos(11)[1]; reg173=reg427+reg173; reg81=0.13020833333333334259*reg81; reg91=reg91+reg289;
    reg199=0.13020833333333334259*reg199; reg566=reg580*reg566; reg628=0.140625*reg628; reg550=0.13020833333333334259*reg550; reg206=reg621-reg206;
    reg513=0.13020833333333334259*reg513; reg649=reg341+reg649; reg198=reg280-reg198; reg497=0.140625*reg497; reg488=reg488-reg197;
    reg202=0.1261880215351700725*elem.pos(11)[2]; reg483=reg533+reg483; reg490=reg448+reg490; reg590=reg590-reg582; reg446=reg440*reg446;
    reg657=reg610*reg657; reg388=reg118+reg388; reg534=reg158+reg534; reg158=reg251*reg364; reg486=reg486-reg504;
    reg587=reg587+reg646; reg598=reg580*reg598; reg364=reg364*reg179; reg650=reg78+reg650; reg545=0.140625*reg545;
    reg196=reg511+reg196; reg386=reg580*reg386; reg78=reg478*reg412; reg430=reg514+reg430; reg412=reg412*reg607;
    reg504=reg185-reg504; reg321=reg528+reg321; reg271=reg207-reg271; reg183=reg359+reg183; reg439=reg180*reg439;
    reg202=reg483+reg202; reg460=reg173+reg460; reg183=reg457+reg183; reg120=reg512+reg120; reg628=reg199-reg628;
    reg657=reg446-reg657; reg354=reg502+reg354; reg646=reg486+reg646; reg598=0.13020833333333334259*reg598; reg248=reg413*reg248;
    reg390=reg317+reg390; reg412=reg364-reg412; reg649=reg247+reg649; reg650=reg281+reg650; reg196=reg481+reg196;
    reg386=0.13020833333333334259*reg386; reg403=reg439-reg403; reg201=reg430+reg201; reg78=reg158-reg78; reg580=0.13020833333333334259*reg580;
    reg321=reg534*reg321; reg91=reg198*reg91; reg289=reg504+reg289; reg545=reg81-reg545; reg273=reg534*reg273;
    reg643=reg550-reg643; reg629=reg206+reg629; reg497=reg513-reg497; reg543=reg71+reg543; reg488=reg488-reg424;
    reg490=reg503+reg490; reg590=reg590-reg363; reg388=reg534*reg388; reg179=reg478*reg179; reg566=0.13020833333333334259*reg566;
    reg587=reg271*reg587; reg607=reg251*reg607; reg273=0.13020833333333334259*reg273; reg289=reg78*reg289; reg354=reg629*reg354;
    reg566=reg628+reg566; reg196=reg71+reg196; reg649=reg357+reg649; reg598=reg643+reg598; reg388=0.13020833333333334259*reg388;
    reg543=reg118+reg543; reg202=reg457+reg202; reg183=reg281+reg183; reg120=reg317+reg120; reg657=reg488*reg657;
    reg545=reg580+reg545; reg534=0.13020833333333334259*reg534; reg321=0.13020833333333334259*reg321; reg646=reg412*reg646; reg390=reg247+reg390;
    reg490=reg629*reg490; reg590=reg590-reg126; reg587=reg91-reg587; reg650=reg528+reg650; reg607=reg179-reg607;
    reg201=reg481+reg201; reg248=reg403+reg248; reg386=reg497+reg386; reg460=reg629*reg460; reg273=reg566+reg273;
    reg490=0.140625*reg490; reg534=reg545+reg534; reg202=reg212+reg202; reg607=reg590*reg607; reg629=0.140625*reg629;
    reg120=reg302+reg120; reg543=reg248*reg543; reg646=reg289-reg646; reg354=0.140625*reg354; reg321=reg386+reg321;
    reg196=reg267+reg196; reg390=reg381+reg390; reg657=reg587+reg657; reg388=reg598+reg388; reg201=reg174+reg201;
    reg183=reg102+reg183; reg650=reg248*reg650; reg649=reg248*reg649; reg460=0.140625*reg460; reg201=reg118+reg201;
    reg607=reg646+reg607; reg543=0.13020833333333334259*reg543; reg248=0.13020833333333334259*reg248; reg629=reg534-reg629; reg202=reg528+reg202;
    reg490=reg321-reg490; reg120=reg357+reg120; reg354=reg273-reg354; reg196=reg657*reg196; reg390=reg657*reg390;
    reg183=reg657*reg183; reg650=0.13020833333333334259*reg650; reg649=0.13020833333333334259*reg649; reg460=reg388-reg460; reg629=reg248+reg629;
    reg657=0.13020833333333334259*reg657; reg201=reg607*reg201; reg649=reg354+reg649; reg390=0.13020833333333334259*reg390; reg120=reg607*reg120;
    reg196=0.13020833333333334259*reg196; reg650=reg490+reg650; reg183=0.13020833333333334259*reg183; reg202=reg607*reg202; reg543=reg460+reg543;
    reg196=reg543+reg196; reg120=0.13020833333333334259*reg120; reg390=reg649+reg390; reg183=reg650+reg183; reg201=0.13020833333333334259*reg201;
    reg607=0.13020833333333334259*reg607; reg657=reg629+reg657; reg202=0.13020833333333334259*reg202; reg201=reg196+reg201; reg607=reg657+reg607;
    reg120=reg390+reg120; reg202=reg183+reg202; res[0]=reg201/reg607; res[1]=reg120/reg607; res[2]=reg202/reg607;

    return res;
}
}
#endif // LMT_WEDGE_15
