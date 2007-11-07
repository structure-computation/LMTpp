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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*var_inter[2]; T reg3=2*reg0;
    T reg4=2*var_inter[1]; reg2=reg2-1; T reg5=0.5*reg0; T reg6=reg3-1; T reg7=reg1-1;
    T reg8=0.5*var_inter[0]; T reg9=reg4-1; T reg10=4*reg2; T reg11=reg8*reg7; T reg12=0.5*var_inter[1];
    T reg13=reg5*reg6; T reg14=pow(reg2,2); T reg15=2*reg11; T reg16=reg8*reg10; T reg17=reg5*reg10;
    T reg18=2*reg13; T reg19=reg12*reg9; T reg20=reg16-reg15; T reg21=2*reg19; T reg22=reg12*reg10;
    T reg23=reg17-reg18; reg9=0.5*reg9; reg14=1-reg14; reg6=0.5*reg6; T reg24=1-reg2;
    reg6=reg0+reg6; T reg25=reg22-reg21; T reg26=pos_nodes[1][1]*reg20; T reg27=pos_nodes[0][0]*reg23; T reg28=pos_nodes[1][0]*reg20;
    T reg29=pos_nodes[0][1]*reg23; T reg30=pos_nodes[1][2]*reg20; T reg31=pos_nodes[0][2]*reg23; reg9=var_inter[1]+reg9; reg8=reg14*reg8;
    reg5=reg5*reg14; T reg32=reg13*reg24; T reg33=reg24*reg11; T reg34=pos_nodes[2][1]*reg25; T reg35=reg24*reg6;
    T reg36=0.5*reg14; reg7=0.5*reg7; reg26=reg29+reg26; reg29=reg24*reg9; T reg37=pos_nodes[2][2]*reg25;
    reg30=reg31+reg30; reg31=pos_nodes[2][0]*reg25; reg32=reg32-reg5; reg33=reg33-reg8; T reg38=reg24*reg19;
    reg12=reg14*reg12; reg28=reg27+reg28; reg2=1+reg2; reg27=reg18+reg17; reg34=reg26+reg34;
    reg26=pos_nodes[3][1]*reg27; T reg39=pos_nodes[0][0]*reg32; reg37=reg30+reg37; reg30=pos_nodes[3][2]*reg27; T reg40=reg36-reg35;
    T reg41=pos_nodes[1][0]*reg33; reg7=var_inter[0]+reg7; T reg42=reg2*reg6; T reg43=pos_nodes[3][0]*reg27; reg31=reg28+reg31;
    reg29=reg29-reg36; reg28=reg15+reg16; reg38=reg38-reg12; reg13=reg13*reg2; T reg44=pos_nodes[1][1]*reg33;
    T reg45=reg32*pos_nodes[0][1]; T reg46=pos_nodes[4][0]*reg28; T reg47=pos_nodes[0][0]*reg40; reg43=reg31+reg43; reg5=reg13-reg5;
    reg13=pos_nodes[1][2]*reg33; reg31=pos_nodes[0][2]*reg32; T reg48=pos_nodes[2][1]*reg29; T reg49=pos_nodes[2][2]*reg29; T reg50=reg21+reg22;
    reg11=reg11*reg2; reg9=reg2*reg9; T reg51=reg3*var_inter[0]; T reg52=pos_nodes[2][0]*reg29; T reg53=pos_nodes[0][1]*reg40;
    T reg54=pos_nodes[4][2]*reg28; reg41=reg39+reg41; reg39=pos_nodes[2][0]*reg38; reg30=reg37+reg30; reg37=pos_nodes[0][2]*reg40;
    reg44=reg45+reg44; reg26=reg34+reg26; reg34=pos_nodes[2][1]*reg38; reg45=reg24*reg7; T reg55=pos_nodes[4][1]*reg28;
    T reg56=reg36-reg42; T reg57=reg1*var_inter[1]; reg54=reg30+reg54; reg52=reg47+reg52; reg9=reg9-reg36;
    reg34=reg44+reg34; reg30=pos_nodes[5][0]*reg50; reg19=reg19*reg2; reg8=reg11-reg8; reg46=reg43+reg46;
    reg39=reg41+reg39; reg49=reg37+reg49; reg11=reg5*pos_nodes[3][0]; reg41=pos_nodes[3][1]*reg56; reg48=reg53+reg48;
    reg43=2*reg51; reg44=pos_nodes[5][1]*reg50; T reg58=pos_nodes[2][2]*reg38; reg13=reg31+reg13; reg55=reg26+reg55;
    reg26=pos_nodes[5][2]*reg50; reg31=reg5*pos_nodes[3][1]; T reg59=pos_nodes[3][0]*reg56; T reg60=pos_nodes[3][2]*reg56; reg45=reg45-reg36;
    T reg61=reg8*pos_nodes[4][1]; T reg62=reg0*reg4; T reg63=pos_nodes[6][2]*reg43; reg12=reg19-reg12; reg31=reg34+reg31;
    reg11=reg39+reg11; reg19=2*reg57; reg26=reg54+reg26; reg34=reg8*pos_nodes[4][0]; reg39=pos_nodes[6][0]*reg43;
    reg30=reg46+reg30; reg46=pos_nodes[1][0]*reg45; reg54=reg24*reg1; T reg64=pos_nodes[6][1]*reg43; reg44=reg55+reg44;
    reg52=reg59+reg52; reg55=pos_nodes[5][0]*reg9; T reg65=pos_nodes[5][2]*reg9; reg49=reg60+reg49; reg48=reg41+reg48;
    reg7=reg2*reg7; T reg66=pos_nodes[1][1]*reg45; T reg67=pos_nodes[5][1]*reg9; T reg68=reg5*pos_nodes[3][2]; reg58=reg13+reg58;
    reg13=pos_nodes[1][2]*reg45; reg68=reg58+reg68; reg46=reg47+reg46; reg47=reg8*pos_nodes[4][2]; reg58=reg3-reg1;
    reg7=reg7-reg36; reg39=reg30-reg39; reg30=pos_nodes[7][0]*reg19; reg34=reg11+reg34; reg11=pos_nodes[7][1]*reg19;
    T reg69=pos_nodes[6][2]*reg54; T reg70=reg12*pos_nodes[5][1]; reg61=reg31+reg61; reg31=pos_nodes[7][2]*reg19; reg63=reg26-reg63;
    reg26=2*reg62; reg66=reg53+reg66; reg53=pos_nodes[6][0]*reg54; reg55=reg52+reg55; reg52=reg24*reg51;
    reg65=reg49+reg65; reg3=reg3-reg4; reg49=reg12*pos_nodes[5][0]; reg67=reg48+reg67; reg48=pos_nodes[6][1]*reg54;
    reg64=reg44-reg64; reg70=reg61+reg70; reg44=reg52*pos_nodes[6][1]; reg11=reg64-reg11; reg61=pos_nodes[8][1]*reg26;
    reg13=reg37+reg13; reg37=pos_nodes[7][1]*reg54; reg48=reg67-reg48; reg64=pos_nodes[4][1]*reg7; reg41=reg66+reg41;
    reg49=reg34+reg49; reg34=reg52*pos_nodes[6][0]; reg69=reg65-reg69; reg65=pos_nodes[7][2]*reg54; reg66=pos_nodes[7][0]*reg54;
    reg53=reg55-reg53; reg55=reg24*reg3; reg67=reg12*pos_nodes[5][2]; reg47=reg68+reg47; reg68=reg24*reg58;
    reg59=reg46+reg59; reg46=pos_nodes[4][0]*reg7; T reg71=pos_nodes[8][2]*reg26; reg31=reg63-reg31; reg30=reg39-reg30;
    reg39=pos_nodes[8][0]*reg26; reg63=reg24*reg57; reg37=reg48+reg37; reg48=pos_nodes[4][2]*reg7; T reg72=pos_nodes[8][0]*reg55;
    T reg73=reg1*reg2; reg64=reg41+reg64; reg41=pos_nodes[6][1]*reg68; T reg74=reg52*pos_nodes[6][2]; reg67=reg47+reg67;
    reg60=reg13+reg60; reg13=pos_nodes[9][2]*reg43; reg47=pos_nodes[8][1]*reg55; T reg75=reg24*reg4; T reg76=pos_nodes[8][2]*reg55;
    T reg77=pos_nodes[6][0]*reg68; reg46=reg59+reg46; reg59=pos_nodes[9][0]*reg43; reg39=reg30-reg39; reg34=reg49+reg34;
    reg30=reg63*pos_nodes[7][0]; reg71=reg31-reg71; reg31=pos_nodes[7][1]*reg63; reg24=reg24*reg62; reg49=pos_nodes[9][1]*reg43;
    reg65=reg69+reg65; reg61=reg11-reg61; reg44=reg70+reg44; reg66=reg53+reg66; reg48=reg60+reg48;
    reg11=pos_nodes[9][1]*reg73; reg51=reg2*reg51; reg37=reg47+reg37; reg47=pos_nodes[7][2]*reg63; reg77=reg46+reg77;
    reg46=reg24*pos_nodes[8][1]; reg31=reg44+reg31; reg44=pos_nodes[10][1]*reg19; reg49=reg61+reg49; reg74=reg67+reg74;
    reg53=reg24*pos_nodes[8][0]; reg60=pos_nodes[10][0]*reg19; reg59=reg39+reg59; reg30=reg34+reg30; reg34=pos_nodes[9][2]*reg73;
    reg65=reg76+reg65; reg39=pos_nodes[9][0]*reg73; reg66=reg72+reg66; reg41=reg64+reg41; reg61=pos_nodes[7][1]*reg75;
    reg13=reg71+reg13; reg64=pos_nodes[10][2]*reg19; reg67=pos_nodes[7][0]*reg75; reg69=pos_nodes[6][2]*reg68; reg34=reg65-reg34;
    reg44=reg49+reg44; reg49=pos_nodes[11][1]*reg26; reg65=pos_nodes[10][2]*reg73; reg70=reg51*pos_nodes[9][1]; reg31=reg46+reg31;
    reg46=pos_nodes[10][0]*reg73; reg71=reg51*pos_nodes[9][0]; reg30=reg53+reg30; reg53=reg24*pos_nodes[8][2]; reg72=reg0*reg10;
    reg76=pos_nodes[8][0]*reg75; reg67=reg77+reg67; reg47=reg74+reg47; reg57=reg2*reg57; reg60=reg59+reg60;
    reg59=pos_nodes[11][0]*reg26; reg58=reg2*reg58; reg64=reg13+reg64; reg13=pos_nodes[7][2]*reg75; reg69=reg48+reg69;
    reg48=pos_nodes[8][1]*reg75; reg61=reg41+reg61; reg41=pos_nodes[11][2]*reg26; reg3=reg2*reg3; reg39=reg66-reg39;
    reg66=pos_nodes[10][1]*reg73; reg11=reg37-reg11; reg37=pos_nodes[11][2]*reg3; reg65=reg34+reg65; reg41=reg64+reg41;
    reg70=reg31+reg70; reg31=reg57*pos_nodes[10][1]; reg34=pos_nodes[12][2]*reg72; reg47=reg53+reg47; reg53=reg51*pos_nodes[9][2];
    reg64=pos_nodes[8][2]*reg75; reg13=reg69+reg13; reg69=reg4*reg2; reg74=pos_nodes[12][0]*reg72; reg59=reg60+reg59;
    reg66=reg11+reg66; reg11=pos_nodes[11][1]*reg3; reg76=reg67-reg76; reg60=var_inter[0]*reg10; reg49=reg44+reg49;
    reg62=reg2*reg62; reg2=pos_nodes[9][1]*reg58; reg46=reg39+reg46; reg39=pos_nodes[12][1]*reg72; reg44=reg57*pos_nodes[10][0];
    reg71=reg30+reg71; reg30=pos_nodes[11][0]*reg3; reg67=pos_nodes[9][0]*reg58; reg48=reg61-reg48; reg34=reg41-reg34;
    reg41=pos_nodes[10][1]*reg69; reg2=reg48+reg2; reg48=pos_nodes[10][0]*reg69; reg67=reg76+reg67; reg61=pos_nodes[13][2]*reg60;
    reg76=reg62*pos_nodes[11][0]; reg44=reg71+reg44; reg71=reg14*pos_nodes[12][2]; reg37=reg65+reg37; reg65=reg14*pos_nodes[12][0];
    reg77=pos_nodes[13][1]*reg60; reg39=reg49-reg39; reg31=reg70+reg31; reg49=reg62*pos_nodes[11][1]; reg30=reg46+reg30;
    reg46=reg57*pos_nodes[10][2]; reg53=reg47+reg53; reg0=reg0*reg14; reg47=var_inter[1]*reg10; reg11=reg66+reg11;
    reg66=reg14*pos_nodes[12][1]; reg64=reg13-reg64; reg13=pos_nodes[9][2]*reg58; reg74=reg59-reg74; reg59=pos_nodes[13][0]*reg60;
    reg70=pos_nodes[14][0]*reg47; reg59=reg74-reg59; reg48=reg67+reg48; reg67=reg14*pos_nodes[14][0]; reg30=reg30-reg65;
    reg74=reg14*pos_nodes[14][2]; T reg78=pos_nodes[11][0]*reg69; T reg79=pos_nodes[14][1]*reg47; reg77=reg39-reg77; reg49=reg31+reg49;
    reg31=reg0*pos_nodes[12][1]; reg39=reg62*pos_nodes[11][2]; reg46=reg53+reg46; reg53=reg14*pos_nodes[14][1]; reg11=reg11-reg66;
    T reg80=reg14*var_inter[0]; reg13=reg64+reg13; reg64=pos_nodes[10][2]*reg69; T reg81=pos_nodes[11][1]*reg69; reg41=reg2+reg41;
    reg2=pos_nodes[14][2]*reg47; reg61=reg34-reg61; reg34=reg0*pos_nodes[12][0]; reg76=reg44+reg76; reg37=reg37-reg71;
    reg44=reg14*var_inter[1]; reg2=reg61-reg2; reg39=reg46+reg39; reg78=reg48-reg78; reg46=reg0*pos_nodes[12][2];
    reg81=reg41-reg81; reg64=reg13+reg64; reg13=pos_nodes[11][2]*reg69; reg53=reg11+reg53; reg11=reg80*pos_nodes[13][1];
    reg31=reg49+reg31; reg79=reg77-reg79; reg41=reg80*pos_nodes[13][0]; reg34=reg76+reg34; reg74=reg37+reg74;
    reg70=reg59-reg70; reg67=reg30+reg67; reg30=reg53*reg2; reg37=reg80*pos_nodes[13][2]; reg46=reg39+reg46;
    reg11=reg31+reg11; reg31=reg44*pos_nodes[14][1]; reg39=reg14*pos_nodes[13][1]; reg66=reg81-reg66; reg48=reg79*reg74;
    reg49=reg67*reg2; reg59=reg70*reg74; reg13=reg64-reg13; reg65=reg78-reg65; reg61=reg14*pos_nodes[13][0];
    reg41=reg34+reg41; reg34=reg44*pos_nodes[14][0]; reg64=reg70*reg53; reg59=reg49-reg59; reg76=reg67*reg79;
    reg48=reg30-reg48; reg61=reg65+reg61; reg65=reg44*pos_nodes[14][2]; reg37=reg46+reg37; reg31=reg11+reg31;
    reg11=reg14*pos_nodes[13][2]; reg39=reg66+reg39; reg71=reg13-reg71; reg34=reg41+reg34; reg13=reg61*reg48;
    reg34=pos[0]-reg34; reg11=reg71+reg11; reg31=pos[1]-reg31; reg65=reg37+reg65; reg37=reg39*reg59;
    reg64=reg76-reg64; reg41=var_inter[0]*reg39; reg46=var_inter[0]*reg61; reg66=reg11*reg64; reg71=reg61*reg74;
    reg13=reg37-reg13; reg37=reg67*reg11; reg77=reg39*reg2; reg78=reg79*reg11; reg81=reg39*reg74;
    T reg82=reg53*reg11; T reg83=reg61*reg2; T reg84=reg70*reg11; T reg85=var_inter[1]*reg67; reg65=pos[2]-reg65;
    reg46=reg34+reg46; reg34=var_inter[0]*reg11; reg41=reg31+reg41; reg31=var_inter[1]*reg53; reg84=reg83-reg84;
    T reg86=var_inter[2]*reg70; reg82=reg81-reg82; T reg87=var_inter[2]*reg79; reg37=reg71-reg37; reg78=reg77-reg78;
    reg46=reg85+reg46; reg66=reg13-reg66; reg13=reg61*reg79; reg85=reg70*reg39; reg41=reg31+reg41;
    reg31=reg61*reg53; T reg88=var_inter[1]*reg74; reg34=reg65+reg34; reg65=reg67*reg39; reg37=reg37/reg66;
    reg65=reg31-reg65; reg85=reg13-reg85; reg84=reg84/reg66; reg59=reg59/reg66; reg82=reg82/reg66;
    reg78=reg78/reg66; reg46=reg86+reg46; reg48=reg48/reg66; reg86=var_inter[2]*reg2; reg41=reg87+reg41;
    reg34=reg88+reg34; reg78=reg46*reg78; reg59=reg41*reg59; reg84=reg41*reg84; reg82=reg46*reg82;
    reg37=reg41*reg37; reg48=reg46*reg48; reg65=reg65/reg66; reg85=reg85/reg66; reg66=reg64/reg66;
    reg34=reg86+reg34; reg66=reg34*reg66; reg48=reg59-reg48; reg85=reg34*reg85; reg84=reg78-reg84;
    reg65=reg34*reg65; reg82=reg37-reg82; var_inter[0]=reg48-reg66; var_inter[1]=reg85+reg84; var_inter[2]=reg82-reg65;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*reg0; T reg3=2*var_inter[2];
    T reg4=0.5*var_inter[0]; T reg5=reg1-1; T reg6=2*var_inter[1]; T reg7=reg2-1; T reg8=0.5*reg0;
    reg3=reg3-1; T reg9=reg6-1; T reg10=0.5*var_inter[1]; T reg11=reg8*reg7; T reg12=reg4*reg5;
    T reg13=4*reg3; T reg14=reg10*reg9; T reg15=pow(reg3,2); T reg16=reg4*reg13; T reg17=2*reg12;
    T reg18=reg8*reg13; T reg19=2*reg11; T reg20=reg10*reg13; T reg21=2*reg14; reg15=1-reg15;
    T reg22=reg18-reg19; T reg23=1-reg3; T reg24=reg16-reg17; reg9=0.5*reg9; reg7=0.5*reg7;
    T reg25=pos_nodes[1][0]*reg24; T reg26=reg23*reg12; reg4=reg15*reg4; T reg27=pos_nodes[0][0]*reg22; T reg28=pos_nodes[0][2]*reg22;
    T reg29=reg20-reg21; T reg30=pos_nodes[0][1]*reg22; reg7=reg0+reg7; T reg31=pos_nodes[1][1]*reg24; reg9=var_inter[1]+reg9;
    T reg32=pos_nodes[1][2]*reg24; reg8=reg8*reg15; T reg33=reg11*reg23; T reg34=reg19+reg18; reg27=reg25+reg27;
    reg25=pos_nodes[2][0]*reg29; T reg35=pos_nodes[2][1]*reg29; reg30=reg31+reg30; reg31=reg23*reg9; T reg36=0.5*reg15;
    reg5=0.5*reg5; T reg37=reg23*reg7; reg33=reg33-reg8; reg3=1+reg3; T reg38=pos_nodes[2][2]*reg29;
    reg28=reg32+reg28; reg26=reg26-reg4; reg32=reg23*reg14; reg10=reg15*reg10; reg11=reg11*reg3;
    T reg39=pos_nodes[3][2]*reg34; reg35=reg30+reg35; reg30=pos_nodes[3][1]*reg34; reg31=reg31-reg36; T reg40=reg3*reg7;
    T reg41=reg36-reg37; reg5=var_inter[0]+reg5; reg32=reg32-reg10; reg38=reg28+reg38; reg28=pos_nodes[1][0]*reg26;
    T reg42=pos_nodes[0][0]*reg33; reg25=reg27+reg25; reg27=pos_nodes[0][1]*reg33; T reg43=reg17+reg16; T reg44=pos_nodes[3][0]*reg34;
    T reg45=pos_nodes[1][1]*reg26; T reg46=pos_nodes[0][0]*reg41; T reg47=reg21+reg20; reg8=reg11-reg8; reg11=pos_nodes[0][2]*reg41;
    T reg48=pos_nodes[0][2]*reg33; reg12=reg3*reg12; T reg49=pos_nodes[1][2]*reg26; reg38=reg39+reg38; reg39=pos_nodes[4][2]*reg43;
    T reg50=pos_nodes[0][1]*reg41; T reg51=pos_nodes[2][1]*reg31; reg42=reg28+reg42; reg28=pos_nodes[2][2]*reg31; T reg52=reg2*var_inter[0];
    T reg53=pos_nodes[2][0]*reg32; T reg54=pos_nodes[4][0]*reg43; reg25=reg44+reg25; reg44=pos_nodes[2][0]*reg31; reg9=reg3*reg9;
    T reg55=pos_nodes[4][1]*reg43; reg35=reg30+reg35; reg30=pos_nodes[2][1]*reg32; T reg56=reg36-reg40; reg27=reg45+reg27;
    reg45=reg23*reg5; T reg57=reg8*pos_nodes[3][1]; reg4=reg12-reg4; reg14=reg14*reg3; reg9=reg9-reg36;
    reg53=reg42+reg53; reg12=2*reg52; reg44=reg46+reg44; reg42=pos_nodes[5][1]*reg47; reg54=reg25+reg54;
    reg25=pos_nodes[5][0]*reg47; T reg58=pos_nodes[3][1]*reg56; reg55=reg35+reg55; reg48=reg49+reg48; reg35=pos_nodes[3][2]*reg56;
    reg49=pos_nodes[3][0]*reg56; T reg59=pos_nodes[5][2]*reg47; reg30=reg27+reg30; reg45=reg45-reg36; reg39=reg38+reg39;
    reg27=reg8*pos_nodes[3][0]; reg38=var_inter[1]*reg1; reg51=reg50+reg51; T reg60=pos_nodes[2][2]*reg32; reg28=reg11+reg28;
    T reg61=reg4*pos_nodes[4][1]; reg30=reg57+reg30; reg57=pos_nodes[6][2]*reg12; reg59=reg39+reg59; reg10=reg14-reg10;
    reg42=reg55+reg42; reg14=pos_nodes[6][1]*reg12; reg39=reg0*reg6; reg55=2*reg38; T reg62=pos_nodes[1][0]*reg45;
    reg5=reg3*reg5; T reg63=reg8*pos_nodes[3][2]; T reg64=pos_nodes[5][1]*reg9; reg51=reg58+reg51; reg28=reg35+reg28;
    T reg65=pos_nodes[5][2]*reg9; T reg66=reg23*reg1; reg60=reg48+reg60; reg53=reg27+reg53; reg27=reg4*pos_nodes[4][0];
    reg44=reg49+reg44; reg48=pos_nodes[5][0]*reg9; T reg67=pos_nodes[6][0]*reg12; reg25=reg54+reg25; reg54=pos_nodes[1][1]*reg45;
    T reg68=pos_nodes[7][0]*reg55; reg67=reg25-reg67; reg25=reg52*reg23; reg27=reg53+reg27; reg53=2*reg39;
    reg5=reg5-reg36; reg46=reg62+reg46; reg62=pos_nodes[1][2]*reg45; T reg69=pos_nodes[6][1]*reg66; reg64=reg51+reg64;
    reg51=reg2-reg1; reg60=reg63+reg60; reg63=reg4*pos_nodes[4][2]; reg2=reg2-reg6; reg65=reg28+reg65;
    reg28=pos_nodes[6][2]*reg66; reg48=reg44+reg48; reg44=pos_nodes[6][0]*reg66; reg50=reg54+reg50; reg54=reg10*pos_nodes[5][1];
    T reg70=reg10*pos_nodes[5][0]; T reg71=pos_nodes[7][2]*reg55; reg57=reg59-reg57; reg14=reg42-reg14; reg42=pos_nodes[7][1]*reg55;
    reg61=reg30+reg61; reg30=pos_nodes[8][1]*reg53; reg42=reg14-reg42; reg11=reg62+reg11; reg14=pos_nodes[7][1]*reg66;
    reg69=reg64-reg69; reg59=reg25*pos_nodes[6][1]; reg54=reg61+reg54; reg61=pos_nodes[4][1]*reg5; reg70=reg27+reg70;
    reg27=pos_nodes[7][2]*reg66; reg50=reg58+reg50; reg28=reg65-reg28; reg44=reg48-reg44; reg48=pos_nodes[7][0]*reg66;
    reg58=reg23*reg2; reg62=pos_nodes[4][0]*reg5; reg46=reg49+reg46; reg49=reg23*reg51; reg63=reg60+reg63;
    reg60=reg10*pos_nodes[5][2]; reg64=pos_nodes[8][2]*reg53; reg71=reg57-reg71; reg68=reg67-reg68; reg57=reg25*pos_nodes[6][0];
    reg65=pos_nodes[8][0]*reg53; reg67=reg38*reg23; reg61=reg50+reg61; reg50=reg67*pos_nodes[7][1]; T reg72=reg3*reg1;
    reg54=reg59+reg54; reg59=pos_nodes[9][2]*reg12; T reg73=reg25*pos_nodes[6][2]; reg14=reg69+reg14; reg69=pos_nodes[8][1]*reg58;
    T reg74=pos_nodes[4][2]*reg5; reg11=reg35+reg11; reg62=reg46+reg62; reg35=reg39*reg23; reg46=pos_nodes[6][0]*reg49;
    reg23=reg23*reg6; reg60=reg63+reg60; reg30=reg42-reg30; reg42=pos_nodes[9][1]*reg12; reg27=reg28+reg27;
    reg70=reg57+reg70; reg48=reg44+reg48; reg28=pos_nodes[8][0]*reg58; reg44=pos_nodes[6][1]*reg49; reg57=pos_nodes[8][2]*reg58;
    reg64=reg71-reg64; reg63=reg67*pos_nodes[7][0]; reg65=reg68-reg65; reg68=pos_nodes[9][0]*reg12; reg71=reg35*pos_nodes[8][1];
    reg69=reg14+reg69; reg14=pos_nodes[9][1]*reg72; reg57=reg27+reg57; reg27=pos_nodes[9][2]*reg72; T reg75=pos_nodes[6][2]*reg49;
    T reg76=pos_nodes[10][1]*reg55; reg42=reg30+reg42; reg63=reg70+reg63; reg60=reg73+reg60; reg30=reg67*pos_nodes[7][2];
    reg70=reg35*pos_nodes[8][0]; reg73=pos_nodes[9][0]*reg72; reg62=reg46+reg62; reg46=pos_nodes[7][0]*reg23; reg61=reg44+reg61;
    reg50=reg54+reg50; reg44=pos_nodes[7][1]*reg23; reg74=reg11+reg74; reg11=pos_nodes[10][0]*reg55; reg28=reg48+reg28;
    reg59=reg64+reg59; reg52=reg52*reg3; reg68=reg65+reg68; reg48=pos_nodes[10][2]*reg55; reg54=pos_nodes[11][0]*reg53;
    reg70=reg63+reg70; reg11=reg68+reg11; reg38=reg38*reg3; reg76=reg42+reg76; reg42=pos_nodes[11][1]*reg53;
    reg63=reg35*pos_nodes[8][2]; reg30=reg60+reg30; reg60=reg0*reg13; reg64=reg52*pos_nodes[9][1]; reg71=reg50+reg71;
    reg2=reg3*reg2; reg44=reg61+reg44; reg50=pos_nodes[8][1]*reg23; reg48=reg59+reg48; reg59=pos_nodes[7][2]*reg23;
    reg74=reg75+reg74; reg61=pos_nodes[11][2]*reg53; reg65=pos_nodes[8][0]*reg23; reg46=reg62+reg46; reg73=reg28-reg73;
    reg14=reg69-reg14; reg28=pos_nodes[10][1]*reg72; reg62=reg52*pos_nodes[9][0]; reg68=pos_nodes[10][0]*reg72; reg51=reg3*reg51;
    reg69=pos_nodes[10][2]*reg72; reg27=reg57-reg27; reg57=pos_nodes[12][2]*reg60; reg61=reg48+reg61; reg69=reg27+reg69;
    reg27=pos_nodes[11][2]*reg2; reg63=reg30+reg63; reg30=reg52*pos_nodes[9][2]; reg59=reg74+reg59; reg48=pos_nodes[8][2]*reg23;
    reg74=reg38*pos_nodes[10][1]; reg64=reg71+reg64; reg71=reg6*reg3; reg75=pos_nodes[12][0]*reg60; reg54=reg11+reg54;
    reg28=reg14+reg28; reg11=pos_nodes[11][1]*reg2; reg65=reg46-reg65; reg14=var_inter[0]*reg13; reg42=reg76+reg42;
    reg3=reg39*reg3; reg39=pos_nodes[9][1]*reg51; reg68=reg73+reg68; reg46=pos_nodes[12][1]*reg60; reg73=reg38*pos_nodes[10][0];
    reg62=reg70+reg62; reg70=pos_nodes[11][0]*reg2; reg76=pos_nodes[9][0]*reg51; reg50=reg44-reg50; reg57=reg61-reg57;
    reg44=pos_nodes[10][1]*reg71; reg39=reg50+reg39; reg50=pos_nodes[10][0]*reg71; reg76=reg65+reg76; reg61=pos_nodes[13][2]*reg14;
    reg65=reg3*pos_nodes[11][0]; reg73=reg62+reg73; reg62=reg15*pos_nodes[12][2]; reg27=reg69+reg27; reg69=reg15*pos_nodes[12][0];
    T reg77=pos_nodes[13][1]*reg14; reg46=reg42-reg46; reg74=reg64+reg74; reg42=reg3*pos_nodes[11][1]; reg70=reg68+reg70;
    reg64=reg38*pos_nodes[10][2]; reg30=reg63+reg30; reg0=reg0*reg15; reg63=var_inter[1]*reg13; reg11=reg28+reg11;
    reg28=reg15*pos_nodes[12][1]; reg48=reg59-reg48; reg59=pos_nodes[9][2]*reg51; reg75=reg54-reg75; reg54=pos_nodes[13][0]*reg14;
    reg68=pos_nodes[14][0]*reg63; reg54=reg75-reg54; reg50=reg76+reg50; reg75=reg15*pos_nodes[14][0]; reg70=reg70-reg69;
    reg76=reg15*pos_nodes[14][2]; T reg78=pos_nodes[11][0]*reg71; T reg79=pos_nodes[14][1]*reg63; reg77=reg46-reg77; reg42=reg74+reg42;
    reg46=reg0*pos_nodes[12][1]; reg74=reg3*pos_nodes[11][2]; reg64=reg30+reg64; reg30=reg15*pos_nodes[14][1]; reg11=reg11-reg28;
    T reg80=reg15*var_inter[0]; reg59=reg48+reg59; reg48=pos_nodes[10][2]*reg71; T reg81=pos_nodes[11][1]*reg71; reg44=reg39+reg44;
    reg39=pos_nodes[14][2]*reg63; reg61=reg57-reg61; reg57=reg0*pos_nodes[12][0]; reg65=reg73+reg65; reg27=reg27-reg62;
    reg73=var_inter[1]*reg15; reg39=reg61-reg39; reg74=reg64+reg74; reg78=reg50-reg78; reg50=reg0*pos_nodes[12][2];
    reg81=reg44-reg81; reg48=reg59+reg48; reg44=pos_nodes[11][2]*reg71; reg30=reg11+reg30; reg11=reg80*pos_nodes[13][1];
    reg46=reg42+reg46; reg79=reg77-reg79; reg42=reg80*pos_nodes[13][0]; reg57=reg65+reg57; reg76=reg27+reg76;
    reg68=reg54-reg68; reg75=reg70+reg75; reg27=reg30*reg39; reg54=reg80*pos_nodes[13][2]; reg50=reg74+reg50;
    reg11=reg46+reg11; reg46=reg73*pos_nodes[14][1]; reg59=reg15*pos_nodes[13][1]; reg28=reg81-reg28; reg61=reg79*reg76;
    reg64=reg75*reg39; reg65=reg68*reg76; reg44=reg48-reg44; reg69=reg78-reg69; reg48=reg15*pos_nodes[13][0];
    reg42=reg57+reg42; reg57=reg73*pos_nodes[14][0]; reg70=reg68*reg30; reg65=reg64-reg65; reg74=reg75*reg79;
    reg61=reg27-reg61; reg48=reg69+reg48; reg69=reg73*pos_nodes[14][2]; reg54=reg50+reg54; reg46=reg11+reg46;
    reg11=reg15*pos_nodes[13][2]; reg59=reg28+reg59; reg62=reg44-reg62; reg57=reg42+reg57; reg28=reg48*reg61;
    reg57=pos[0]-reg57; reg11=reg62+reg11; reg46=pos[1]-reg46; reg69=reg54+reg69; reg42=reg59*reg65;
    reg70=reg74-reg70; reg44=var_inter[0]*reg59; reg50=var_inter[0]*reg48; reg54=reg11*reg70; reg62=reg48*reg76;
    reg28=reg42-reg28; reg42=reg75*reg11; reg77=reg59*reg39; reg78=reg79*reg11; reg81=reg59*reg76;
    T reg82=reg30*reg11; T reg83=reg48*reg39; T reg84=reg68*reg11; T reg85=var_inter[1]*reg75; reg69=pos[2]-reg69;
    reg50=reg57+reg50; reg57=var_inter[0]*reg11; reg44=reg46+reg44; reg46=var_inter[1]*reg30; reg84=reg83-reg84;
    T reg86=var_inter[2]*reg68; reg82=reg81-reg82; T reg87=var_inter[2]*reg79; reg42=reg62-reg42; reg78=reg77-reg78;
    reg50=reg85+reg50; reg54=reg28-reg54; reg28=reg48*reg79; reg85=reg68*reg59; reg44=reg46+reg44;
    reg46=reg48*reg30; T reg88=var_inter[1]*reg76; reg57=reg69+reg57; reg69=reg75*reg59; reg42=reg42/reg54;
    reg69=reg46-reg69; reg85=reg28-reg85; reg84=reg84/reg54; reg65=reg65/reg54; reg82=reg82/reg54;
    reg78=reg78/reg54; reg50=reg86+reg50; reg61=reg61/reg54; reg86=var_inter[2]*reg39; reg44=reg87+reg44;
    reg57=reg88+reg57; reg78=reg50*reg78; reg65=reg44*reg65; reg84=reg44*reg84; reg82=reg50*reg82;
    reg42=reg44*reg42; reg61=reg50*reg61; reg69=reg69/reg54; reg85=reg85/reg54; reg54=reg70/reg54;
    reg57=reg86+reg57; reg54=reg57*reg54; reg61=reg65-reg61; reg85=reg57*reg85; reg84=reg78-reg84;
    reg69=reg57*reg69; reg82=reg42-reg82; var_inter[0]+=reg61-reg54; var_inter[1]+=reg85+reg84; var_inter[2]+=reg82-reg69;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; T reg2=2*reg0; T reg3=2*var_inter[0];
    reg1=reg1-1; T reg4=0.5*var_inter[0]; T reg5=pow(reg1,2); T reg6=0.5*reg0; T reg7=2*var_inter[1];
    T reg8=reg3-1; T reg9=reg2-1; reg8=reg4*reg8; reg9=reg6*reg9; T reg10=1-reg1;
    T reg11=0.5*var_inter[1]; reg5=1-reg5; T reg12=reg7-1; T reg13=reg10*reg8; reg4=reg5*reg4;
    T reg14=reg9*reg10; reg6=reg6*reg5; reg12=reg11*reg12; reg13=reg13-reg4; T reg15=reg10*reg12;
    reg1=1+reg1; reg11=reg5*reg11; reg14=reg14-reg6; reg14=val[0]*reg14; reg9=reg1*reg9;
    reg15=reg15-reg11; reg13=val[1]*reg13; reg8=reg1*reg8; reg6=reg9-reg6; reg15=val[2]*reg15;
    reg13=reg14+reg13; reg15=reg13+reg15; reg6=val[3]*reg6; reg4=reg8-reg4; reg12=reg1*reg12;
    reg15=reg6+reg15; reg4=val[4]*reg4; reg11=reg12-reg11; reg2=var_inter[0]*reg2; reg4=reg15+reg4;
    reg11=val[5]*reg11; reg6=reg2*reg10; reg3=var_inter[1]*reg3; reg6=val[6]*reg6; reg11=reg4+reg11;
    reg4=reg3*reg10; reg7=reg0*reg7; reg10=reg7*reg10; reg4=val[7]*reg4; reg6=reg11+reg6;
    reg4=reg6+reg4; reg10=val[8]*reg10; reg2=reg1*reg2; reg3=reg1*reg3; reg10=reg4+reg10;
    reg2=val[9]*reg2; reg2=reg10+reg2; reg3=val[10]*reg3; reg7=reg1*reg7; reg0=reg0*reg5;
    reg7=val[11]*reg7; reg3=reg2+reg3; reg1=var_inter[0]*reg5; reg0=val[12]*reg0; reg7=reg3+reg7;
    reg0=reg7+reg0; reg1=val[13]*reg1; reg5=var_inter[1]*reg5; reg1=reg0+reg1; reg5=val[14]*reg5;
    res=reg1+reg5;

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
