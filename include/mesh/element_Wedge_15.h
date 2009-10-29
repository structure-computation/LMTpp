#ifndef LMT_WEDGE_15
#define LMT_WEDGE_15
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Wedge_15 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 25, 50, 75, 108, 181, 266, 351, 436, 521, }; // fonction de lordre du poly
    static const double values[] = {
        0.0833333333333,0.5,0.0,0.211324865405,
        0.0833333333333,0.5,0.5,0.211324865405,
        0.0833333333333,0.0,0.5,0.211324865405,
        0.0833333333333,0.5,0.0,0.788675134595,
        0.0833333333333,0.5,0.5,0.788675134595,
        0.0833333333333,0.0,0.5,0.788675134595,
        0.0,
        0.0833333333333,0.5,0.0,0.211324865405,
        0.0833333333333,0.5,0.5,0.211324865405,
        0.0833333333333,0.0,0.5,0.211324865405,
        0.0833333333333,0.5,0.0,0.788675134595,
        0.0833333333333,0.5,0.5,0.788675134595,
        0.0833333333333,0.0,0.5,0.788675134595,
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
    T reg0=nodes[0]->pos[1]+nodes[3]->pos[1]; T reg1=nodes[0]->pos[2]+nodes[3]->pos[2]; reg1=reg1-nodes[6]->pos[2]; reg0=reg0-nodes[6]->pos[1]; reg1=reg1+nodes[7]->pos[2];
    reg0=reg0+nodes[7]->pos[1]; T reg2=nodes[0]->pos[0]+nodes[3]->pos[0]; reg0=reg0-nodes[8]->pos[1]; reg1=reg1-nodes[8]->pos[2]; reg2=reg2-nodes[6]->pos[0];
    reg0=reg0-nodes[9]->pos[1]; reg1=reg1-nodes[9]->pos[2]; reg2=reg2+nodes[7]->pos[0]; reg1=reg1+nodes[10]->pos[2]; reg2=reg2-nodes[8]->pos[0];
    reg0=reg0+nodes[10]->pos[1]; reg0=reg0-nodes[11]->pos[1]; reg1=reg1-nodes[11]->pos[2]; reg2=reg2-nodes[9]->pos[0]; reg2=reg2+nodes[10]->pos[0];
    reg0=reg0-nodes[12]->pos[1]; reg1=reg1-nodes[12]->pos[2]; reg2=reg2-nodes[11]->pos[0]; T reg3=nodes[14]->pos[1]+reg0; T reg4=nodes[10]->pos[2]-nodes[7]->pos[2];
    T reg5=nodes[14]->pos[2]+reg1; T reg6=nodes[10]->pos[1]-nodes[7]->pos[1]; reg0=reg0+nodes[13]->pos[1]; reg1=nodes[13]->pos[2]+reg1; T reg7=reg4*reg0;
    T reg8=reg6*reg1; reg2=reg2-nodes[12]->pos[0]; reg4=reg3*reg4; reg6=reg5*reg6; reg1=reg3*reg1;
    reg0=reg5*reg0; reg3=reg2+nodes[13]->pos[0]; reg8=reg7-reg8; reg6=reg4-reg6; reg2=nodes[14]->pos[0]+reg2;
    reg1=reg0-reg1; reg0=nodes[10]->pos[0]-nodes[7]->pos[0]; reg8=reg2*reg8; reg6=reg3*reg6; reg8=reg6-reg8;
    reg1=reg0*reg1; T det_jac=reg8+reg1;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[14],nodes[13],nodes[12],nodes[11],nodes[10],nodes[9],nodes[8],nodes[7],nodes[6],nodes[5],nodes[4],nodes[3],nodes[2],nodes[1],nodes[0]};
        for(unsigned i=0;i<15;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*var_inter[2]; T reg3=2*reg0;
    T reg4=reg3-1; T reg5=0.5*var_inter[0]; T reg6=reg1-1; reg2=reg2-1; T reg7=0.5*reg0;
    T reg8=2*var_inter[1]; T reg9=4*reg2; T reg10=reg4*reg7; T reg11=0.5*var_inter[1]; T reg12=reg5*reg6;
    T reg13=reg8-1; T reg14=reg5*reg9; T reg15=2*reg12; T reg16=reg7*reg9; T reg17=2*reg10;
    T reg18=reg11*reg13; T reg19=reg14-reg15; T reg20=reg16-reg17; reg4=0.5*reg4; reg13=0.5*reg13;
    T reg21=pow(reg2,2); T reg22=2*reg18; T reg23=reg11*reg9; T reg24=reg23-reg22; T reg25=pos_nodes[0][0]*reg20;
    reg21=1-reg21; T reg26=pos_nodes[1][0]*reg19; T reg27=pos_nodes[1][1]*reg19; T reg28=1-reg2; T reg29=pos_nodes[1][2]*reg19;
    T reg30=pos_nodes[0][2]*reg20; reg13=var_inter[1]+reg13; T reg31=pos_nodes[0][1]*reg20; reg4=reg0+reg4; T reg32=pos_nodes[2][0]*reg24;
    reg26=reg25+reg26; reg25=reg28*reg13; reg6=0.5*reg6; T reg33=0.5*reg21; T reg34=reg28*reg4;
    T reg35=reg17+reg16; reg2=1+reg2; T reg36=pos_nodes[2][1]*reg24; reg27=reg31+reg27; reg29=reg30+reg29;
    reg30=pos_nodes[2][2]*reg24; reg30=reg29+reg30; reg29=pos_nodes[3][2]*reg35; reg31=reg33-reg34; reg6=var_inter[0]+reg6;
    T reg37=reg2*reg4; reg25=reg25-reg33; reg36=reg27+reg36; reg27=pos_nodes[3][1]*reg35; T reg38=reg15+reg14;
    reg32=reg26+reg32; reg26=pos_nodes[3][0]*reg35; reg27=reg36+reg27; reg36=pos_nodes[4][1]*reg38; T reg39=pos_nodes[2][1]*reg25;
    T reg40=pos_nodes[0][1]*reg31; T reg41=pos_nodes[0][2]*reg31; T reg42=pos_nodes[4][0]*reg38; T reg43=reg28*reg6; reg26=reg32+reg26;
    reg32=reg33-reg37; T reg44=pos_nodes[0][0]*reg31; reg13=reg2*reg13; T reg45=pos_nodes[2][0]*reg25; T reg46=pos_nodes[2][2]*reg25;
    T reg47=reg22+reg23; T reg48=reg10*reg28; reg7=reg21*reg7; reg5=reg21*reg5; T reg49=reg28*reg12;
    reg29=reg30+reg29; reg30=pos_nodes[4][2]*reg38; T reg50=var_inter[0]*reg3; reg30=reg29+reg30; reg13=reg13-reg33;
    reg36=reg27+reg36; reg43=reg43-reg33; reg27=2*reg50; reg46=reg41+reg46; reg29=reg1*var_inter[1];
    T reg51=pos_nodes[3][1]*reg32; reg39=reg40+reg39; reg48=reg48-reg7; T reg52=pos_nodes[5][0]*reg47; T reg53=pos_nodes[3][0]*reg32;
    reg49=reg49-reg5; T reg54=pos_nodes[5][1]*reg47; T reg55=pos_nodes[5][2]*reg47; reg42=reg26+reg42; reg26=reg28*reg18;
    reg11=reg21*reg11; T reg56=pos_nodes[3][2]*reg32; reg45=reg44+reg45; T reg57=reg28*reg1; T reg58=pos_nodes[6][1]*reg27;
    T reg59=pos_nodes[1][0]*reg49; T reg60=reg48*pos_nodes[0][0]; T reg61=pos_nodes[6][0]*reg27; reg42=reg52+reg42; reg52=pos_nodes[5][0]*reg13;
    T reg62=pos_nodes[1][1]*reg43; T reg63=reg48*pos_nodes[0][1]; T reg64=pos_nodes[1][1]*reg49; T reg65=pos_nodes[5][2]*reg13; T reg66=reg0*reg8;
    reg45=reg53+reg45; reg46=reg56+reg46; reg30=reg55+reg30; reg55=pos_nodes[6][2]*reg27; reg36=reg54+reg36;
    reg54=pos_nodes[5][1]*reg13; T reg67=pos_nodes[1][0]*reg43; reg39=reg51+reg39; reg10=reg10*reg2; reg26=reg26-reg11;
    T reg68=2*reg29; reg6=reg2*reg6; reg59=reg60+reg59; reg12=reg12*reg2; reg7=reg10-reg7;
    reg10=pos_nodes[1][2]*reg43; reg60=pos_nodes[0][2]*reg48; T reg69=pos_nodes[1][2]*reg49; reg52=reg45+reg52; reg45=pos_nodes[6][0]*reg57;
    T reg70=pos_nodes[7][0]*reg68; reg61=reg42-reg61; reg67=reg44+reg67; reg58=reg36-reg58; reg36=pos_nodes[7][1]*reg68;
    reg42=2*reg66; reg62=reg40+reg62; reg39=reg54+reg39; reg40=reg3-reg1; reg44=pos_nodes[6][1]*reg57;
    reg64=reg63+reg64; reg54=pos_nodes[2][1]*reg26; reg6=reg6-reg33; reg63=pos_nodes[6][2]*reg57; reg46=reg65+reg46;
    reg65=pos_nodes[7][2]*reg68; reg55=reg30-reg55; reg3=reg3-reg8; reg30=pos_nodes[2][0]*reg26; reg70=reg61-reg70;
    reg61=pos_nodes[8][0]*reg42; reg10=reg41+reg10; reg30=reg59+reg30; reg41=pos_nodes[3][0]*reg7; reg59=pos_nodes[3][1]*reg7;
    reg54=reg64+reg54; reg51=reg62+reg51; reg62=pos_nodes[4][1]*reg6; reg64=pos_nodes[8][1]*reg42; reg36=reg58-reg36;
    reg44=reg39-reg44; reg39=pos_nodes[7][1]*reg57; reg58=pos_nodes[2][2]*reg26; reg69=reg60+reg69; reg60=reg28*reg3;
    reg63=reg46-reg63; reg45=reg52-reg45; reg46=pos_nodes[7][0]*reg57; reg52=pos_nodes[7][2]*reg57; T reg71=pos_nodes[4][0]*reg6;
    reg53=reg67+reg53; reg67=reg28*reg40; T reg72=pos_nodes[8][2]*reg42; reg65=reg55-reg65; reg5=reg12-reg5;
    reg18=reg18*reg2; reg12=reg1*reg2; reg41=reg30+reg41; reg30=pos_nodes[4][0]*reg5; reg55=pos_nodes[4][1]*reg5;
    reg59=reg54+reg59; reg52=reg63+reg52; reg54=pos_nodes[8][2]*reg60; reg62=reg51+reg62; reg51=pos_nodes[6][1]*reg67;
    reg63=pos_nodes[9][1]*reg27; reg64=reg36-reg64; reg36=pos_nodes[6][0]*reg67; reg71=reg53+reg71; reg11=reg18-reg11;
    reg18=pos_nodes[9][2]*reg27; reg53=reg28*reg8; T reg73=pos_nodes[8][1]*reg60; reg72=reg65-reg72; reg39=reg44+reg39;
    reg56=reg10+reg56; reg10=pos_nodes[4][2]*reg6; reg44=pos_nodes[8][0]*reg60; reg46=reg45+reg46; reg61=reg70-reg61;
    reg45=pos_nodes[9][0]*reg27; reg58=reg69+reg58; reg65=pos_nodes[3][2]*reg7; reg54=reg52+reg54; reg52=pos_nodes[9][2]*reg12;
    reg69=pos_nodes[5][1]*reg11; reg70=pos_nodes[6][2]*reg67; T reg74=pos_nodes[5][0]*reg11; reg18=reg72+reg18; reg72=pos_nodes[7][0]*reg53;
    T reg75=pos_nodes[9][0]*reg12; T reg76=pos_nodes[10][2]*reg68; reg51=reg62+reg51; reg62=pos_nodes[7][1]*reg53; reg36=reg71+reg36;
    reg71=pos_nodes[10][1]*reg68; reg63=reg64+reg63; reg64=reg50*reg28; reg10=reg56+reg10; reg56=pos_nodes[4][2]*reg5;
    reg65=reg58+reg65; reg58=pos_nodes[10][0]*reg68; reg45=reg61+reg45; reg30=reg41+reg30; reg41=pos_nodes[9][1]*reg12;
    reg73=reg39+reg73; reg55=reg59+reg55; reg44=reg46+reg44; reg41=reg73-reg41; reg39=pos_nodes[10][1]*reg12;
    reg40=reg2*reg40; reg46=reg29*reg28; reg70=reg10+reg70; reg76=reg18+reg76; reg10=pos_nodes[7][2]*reg53;
    reg56=reg65+reg56; reg18=pos_nodes[10][0]*reg12; reg59=pos_nodes[6][0]*reg64; reg30=reg74+reg30; reg58=reg45+reg58;
    reg45=pos_nodes[6][1]*reg64; reg55=reg69+reg55; reg52=reg54-reg52; reg54=pos_nodes[5][2]*reg11; reg61=pos_nodes[11][0]*reg42;
    reg65=pos_nodes[11][1]*reg42; reg69=pos_nodes[11][2]*reg42; reg73=pos_nodes[10][2]*reg12; reg3=reg2*reg3; reg74=pos_nodes[8][0]*reg53;
    reg72=reg36+reg72; reg75=reg44-reg75; reg62=reg51+reg62; reg36=pos_nodes[8][1]*reg53; reg71=reg63+reg71;
    reg44=reg0*reg9; reg69=reg76+reg69; reg51=pos_nodes[6][2]*reg64; reg56=reg54+reg56; reg54=reg46*pos_nodes[7][1];
    reg45=reg55+reg45; reg55=pos_nodes[12][1]*reg44; reg65=reg71+reg65; reg73=reg52+reg73; reg52=pos_nodes[11][2]*reg3;
    reg10=reg70+reg10; reg63=pos_nodes[8][2]*reg53; reg70=pos_nodes[12][2]*reg44; reg71=var_inter[0]*reg9; reg28=reg66*reg28;
    reg76=pos_nodes[7][0]*reg46; reg59=reg30+reg59; reg36=reg62-reg36; reg30=pos_nodes[9][1]*reg40; reg61=reg58+reg61;
    reg58=pos_nodes[12][0]*reg44; reg62=pos_nodes[9][0]*reg40; reg18=reg75+reg18; reg75=reg8*reg2; reg39=reg41+reg39;
    reg41=pos_nodes[11][0]*reg3; T reg77=pos_nodes[11][1]*reg3; reg74=reg72-reg74; reg62=reg74+reg62; reg72=pos_nodes[13][2]*reg71;
    reg70=reg69-reg70; reg69=var_inter[1]*reg9; reg74=pos_nodes[8][0]*reg28; reg76=reg59+reg76; reg54=reg45+reg54;
    reg45=pos_nodes[8][1]*reg28; reg52=reg73+reg52; reg59=pos_nodes[10][0]*reg75; reg73=pos_nodes[13][0]*reg71; reg50=reg50*reg2;
    reg58=reg61-reg58; reg61=pos_nodes[12][1]*reg21; T reg78=pos_nodes[7][2]*reg46; T reg79=pos_nodes[12][0]*reg21; T reg80=pos_nodes[12][2]*reg21;
    T reg81=pos_nodes[10][1]*reg75; reg30=reg36+reg30; reg51=reg56+reg51; reg55=reg65-reg55; reg36=pos_nodes[13][1]*reg71;
    reg56=pos_nodes[9][2]*reg40; reg63=reg10-reg63; reg77=reg39+reg77; reg41=reg18+reg41; reg41=reg41-reg79;
    reg10=pos_nodes[14][0]*reg69; reg73=reg58-reg73; reg18=pos_nodes[10][2]*reg75; reg56=reg63+reg56; reg59=reg62+reg59;
    reg39=pos_nodes[14][0]*reg21; reg58=pos_nodes[11][0]*reg75; reg62=pos_nodes[8][2]*reg28; reg78=reg51+reg78; reg51=pos_nodes[11][1]*reg75;
    reg81=reg30+reg81; reg36=reg55-reg36; reg30=pos_nodes[14][1]*reg69; reg77=reg77-reg61; reg55=pos_nodes[14][2]*reg69;
    reg72=reg70-reg72; reg63=pos_nodes[9][0]*reg50; reg74=reg76+reg74; reg45=reg54+reg45; reg54=pos_nodes[9][1]*reg50;
    reg29=reg29*reg2; reg65=pos_nodes[14][1]*reg21; reg70=pos_nodes[14][2]*reg21; reg52=reg52-reg80; reg76=pos_nodes[9][2]*reg50;
    reg62=reg78+reg62; reg58=reg59-reg58; reg55=reg72-reg55; reg2=reg66*reg2; reg70=reg52+reg70;
    reg51=reg81-reg51; reg52=pos_nodes[10][0]*reg29; reg63=reg74+reg63; reg59=pos_nodes[10][1]*reg29; reg66=pos_nodes[11][2]*reg75;
    reg18=reg56+reg18; reg39=reg41+reg39; reg65=reg77+reg65; reg10=reg73-reg10; reg30=reg36-reg30;
    reg54=reg45+reg54; reg36=pos_nodes[11][1]*reg2; reg41=pos_nodes[11][0]*reg2; reg52=reg63+reg52; reg59=reg54+reg59;
    reg45=reg65*reg55; reg54=reg10*reg70; reg56=reg39*reg55; reg63=reg30*reg70; reg0=reg21*reg0;
    reg72=pos_nodes[10][2]*reg29; reg76=reg62+reg76; reg79=reg58-reg79; reg58=pos_nodes[13][0]*reg21; reg66=reg18-reg66;
    reg18=pos_nodes[13][1]*reg21; reg61=reg51-reg61; reg51=var_inter[0]*reg21; reg41=reg52+reg41; reg52=pos_nodes[11][2]*reg2;
    reg72=reg76+reg72; reg62=pos_nodes[12][1]*reg0; reg18=reg61+reg18; reg63=reg45-reg63; reg61=reg39*reg30;
    reg73=pos_nodes[13][2]*reg21; reg80=reg66-reg80; reg58=reg79+reg58; reg66=pos_nodes[12][0]*reg0; reg54=reg56-reg54;
    reg74=reg10*reg65; reg36=reg59+reg36; reg73=reg80+reg73; reg59=pos_nodes[13][0]*reg51; reg76=pos_nodes[13][1]*reg51;
    reg36=reg62+reg36; reg62=reg21*var_inter[1]; reg77=pos_nodes[12][2]*reg0; reg78=reg58*reg63; reg79=reg18*reg54;
    reg52=reg72+reg52; reg74=reg61-reg74; reg41=reg66+reg41; reg66=reg18*reg55; reg72=reg65*reg73;
    reg80=reg73*reg74; reg81=reg58*reg55; reg78=reg79-reg78; reg79=reg10*reg73; T reg82=reg58*reg70;
    T reg83=reg39*reg73; T reg84=reg30*reg73; reg52=reg77+reg52; reg77=pos_nodes[13][2]*reg51; T reg85=reg18*reg70;
    reg76=reg36+reg76; reg36=pos_nodes[14][0]*reg62; reg59=reg41+reg59; reg41=pos_nodes[14][1]*reg62; reg72=reg85-reg72;
    reg84=reg66-reg84; reg79=reg81-reg79; reg41=reg76+reg41; reg80=reg78-reg80; reg83=reg82-reg83;
    reg76=pos_nodes[14][2]*reg62; reg77=reg52+reg77; reg52=reg39*reg18; reg78=reg58*reg30; T reg86=reg10*reg18;
    reg36=reg59+reg36; reg59=reg58*reg65; reg63=reg63/reg80; reg84=reg84/reg80; reg72=reg72/reg80;
    reg54=reg54/reg80; reg79=reg79/reg80; reg41=pos[1]-reg41; reg83=reg83/reg80; reg36=pos[0]-reg36;
    reg86=reg78-reg86; reg76=reg77+reg76; reg52=reg59-reg52; reg86=reg86/reg80; reg74=reg74/reg80;
    reg76=pos[2]-reg76; reg80=reg52/reg80; reg63=reg36*reg63; reg54=reg41*reg54; reg84=reg36*reg84;
    reg79=reg41*reg79; reg83=reg41*reg83; reg72=reg36*reg72; reg63=reg54-reg63; reg74=reg76*reg74;
    reg86=reg86*reg76; reg72=reg83-reg72; reg80=reg80*reg76; reg79=reg84-reg79; var_inter[0]=reg63-reg74;
    var_inter[2]=reg72-reg80; var_inter[1]=reg86+reg79;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Wedge_15 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*var_inter[2]; T reg3=2*reg0;
    T reg4=2*var_inter[1]; T reg5=reg3-1; reg2=reg2-1; T reg6=0.5*reg0; T reg7=0.5*var_inter[0];
    T reg8=reg1-1; T reg9=0.5*var_inter[1]; T reg10=reg4-1; T reg11=reg7*reg8; T reg12=4*reg2;
    T reg13=reg6*reg5; T reg14=reg9*reg10; T reg15=reg7*reg12; T reg16=2*reg11; T reg17=reg6*reg12;
    T reg18=2*reg13; reg5=0.5*reg5; reg10=0.5*reg10; T reg19=2*reg14; T reg20=reg9*reg12;
    T reg21=reg17-reg18; T reg22=pow(reg2,2); T reg23=reg15-reg16; T reg24=pos_nodes[1][2]*reg23; T reg25=pos_nodes[1][0]*reg23;
    T reg26=pos_nodes[0][2]*reg21; T reg27=pos_nodes[1][1]*reg23; reg5=reg0+reg5; reg10=var_inter[1]+reg10; T reg28=reg20-reg19;
    T reg29=pos_nodes[0][1]*reg21; T reg30=pos_nodes[0][0]*reg21; T reg31=1-reg2; reg22=1-reg22; T reg32=pos_nodes[2][2]*reg28;
    reg2=1+reg2; T reg33=pos_nodes[2][1]*reg28; reg27=reg29+reg27; reg29=pos_nodes[2][0]*reg28; reg25=reg30+reg25;
    reg30=reg18+reg17; T reg34=0.5*reg22; reg24=reg26+reg24; reg26=reg31*reg5; reg8=0.5*reg8;
    T reg35=reg31*reg10; reg27=reg33+reg27; reg33=pos_nodes[3][0]*reg30; T reg36=reg16+reg15; T reg37=pos_nodes[3][1]*reg30;
    reg25=reg29+reg25; reg29=reg2*reg5; T reg38=reg34-reg26; reg8=var_inter[0]+reg8; reg35=reg35-reg34;
    reg24=reg32+reg24; reg32=pos_nodes[3][2]*reg30; T reg39=pos_nodes[2][1]*reg35; reg25=reg33+reg25; reg33=pos_nodes[0][1]*reg38;
    T reg40=pos_nodes[4][0]*reg36; T reg41=pos_nodes[0][0]*reg38; T reg42=reg13*reg31; T reg43=pos_nodes[2][0]*reg35; reg6=reg22*reg6;
    T reg44=reg34-reg29; reg24=reg32+reg24; reg32=pos_nodes[4][2]*reg36; T reg45=reg31*reg8; T reg46=pos_nodes[2][2]*reg35;
    T reg47=pos_nodes[0][2]*reg38; reg10=reg2*reg10; T reg48=reg19+reg20; T reg49=var_inter[0]*reg3; T reg50=pos_nodes[4][1]*reg36;
    reg27=reg37+reg27; reg7=reg7*reg22; reg37=reg31*reg11; reg43=reg41+reg43; reg10=reg10-reg34;
    T reg51=2*reg49; T reg52=pos_nodes[3][0]*reg44; reg40=reg25+reg40; reg25=pos_nodes[5][0]*reg48; T reg53=pos_nodes[3][2]*reg44;
    reg46=reg47+reg46; T reg54=pos_nodes[5][2]*reg48; reg45=reg45-reg34; reg32=reg24+reg32; reg24=pos_nodes[3][1]*reg44;
    T reg55=reg31*reg14; reg39=reg33+reg39; reg9=reg22*reg9; reg37=reg37-reg7; reg50=reg27+reg50;
    reg27=reg1*var_inter[1]; T reg56=pos_nodes[5][1]*reg48; reg42=reg42-reg6; reg46=reg53+reg46; T reg57=pos_nodes[5][2]*reg10;
    T reg58=pos_nodes[5][0]*reg10; reg43=reg52+reg43; reg54=reg32+reg54; reg32=pos_nodes[6][2]*reg51; T reg59=pos_nodes[1][1]*reg37;
    T reg60=reg42*pos_nodes[0][1]; T reg61=pos_nodes[6][1]*reg51; reg56=reg50+reg56; reg50=2*reg27; T reg62=pos_nodes[5][1]*reg10;
    reg39=reg24+reg39; T reg63=pos_nodes[1][1]*reg45; T reg64=pos_nodes[1][0]*reg37; T reg65=reg42*pos_nodes[0][0]; T reg66=pos_nodes[6][0]*reg51;
    reg25=reg40+reg25; reg55=reg55-reg9; reg40=pos_nodes[1][0]*reg45; reg13=reg13*reg2; T reg67=reg1*reg31;
    T reg68=reg4*reg0; reg8=reg2*reg8; reg6=reg13-reg6; reg13=pos_nodes[2][1]*reg55; reg64=reg65+reg64;
    reg65=pos_nodes[6][2]*reg67; reg57=reg46+reg57; reg11=reg2*reg11; reg46=pos_nodes[7][0]*reg50; reg66=reg25-reg66;
    reg62=reg39+reg62; reg8=reg8-reg34; reg25=pos_nodes[1][2]*reg45; reg59=reg60+reg59; reg39=pos_nodes[6][1]*reg67;
    reg40=reg41+reg40; reg58=reg43+reg58; reg41=pos_nodes[6][0]*reg67; reg43=pos_nodes[2][0]*reg55; reg61=reg56-reg61;
    reg56=pos_nodes[1][2]*reg37; reg60=reg42*pos_nodes[0][2]; T reg69=pos_nodes[7][1]*reg50; reg63=reg33+reg63; reg33=reg3-reg1;
    T reg70=pos_nodes[7][2]*reg50; reg32=reg54-reg32; reg54=2*reg68; reg3=reg3-reg4; reg64=reg43+reg64;
    reg39=reg62-reg39; reg59=reg13+reg59; reg13=pos_nodes[3][0]*reg6; reg43=pos_nodes[7][1]*reg67; reg46=reg66-reg46;
    reg62=pos_nodes[8][0]*reg54; reg69=reg61-reg69; reg61=pos_nodes[8][1]*reg54; reg66=pos_nodes[3][1]*reg6; reg56=reg60+reg56;
    reg60=reg31*reg3; reg41=reg58-reg41; reg58=pos_nodes[7][0]*reg67; T reg71=pos_nodes[2][2]*reg55; T reg72=reg31*reg33;
    T reg73=pos_nodes[8][2]*reg54; reg70=reg32-reg70; reg63=reg24+reg63; reg24=pos_nodes[7][2]*reg67; reg65=reg57-reg65;
    reg7=reg11-reg7; reg14=reg2*reg14; reg11=pos_nodes[4][1]*reg8; reg25=reg47+reg25; reg32=pos_nodes[4][0]*reg8;
    reg40=reg52+reg40; reg11=reg63+reg11; reg47=reg31*reg4; reg52=pos_nodes[8][1]*reg60; reg57=pos_nodes[6][1]*reg72;
    reg56=reg71+reg56; reg63=pos_nodes[3][2]*reg6; reg71=pos_nodes[9][2]*reg51; reg73=reg70-reg73; reg24=reg65+reg24;
    reg9=reg14-reg9; reg14=pos_nodes[8][2]*reg60; reg65=pos_nodes[4][2]*reg8; reg25=reg53+reg25; reg53=reg7*pos_nodes[4][1];
    reg59=reg66+reg59; reg66=pos_nodes[9][1]*reg51; reg61=reg69-reg61; reg43=reg39+reg43; reg58=reg41+reg58;
    reg32=reg40+reg32; reg39=pos_nodes[6][0]*reg72; reg40=pos_nodes[8][0]*reg60; reg62=reg46-reg62; reg41=pos_nodes[9][0]*reg51;
    reg46=reg7*pos_nodes[4][0]; reg64=reg13+reg64; reg13=reg1*reg2; reg69=pos_nodes[10][0]*reg50; reg43=reg52+reg43;
    reg52=pos_nodes[9][1]*reg13; reg41=reg62+reg41; reg62=pos_nodes[10][1]*reg50; reg66=reg61+reg66; reg46=reg64+reg46;
    reg61=pos_nodes[9][0]*reg13; reg58=reg40+reg58; reg53=reg59+reg53; reg40=pos_nodes[5][1]*reg9; reg59=pos_nodes[10][2]*reg50;
    reg64=pos_nodes[9][2]*reg13; reg24=reg14+reg24; reg14=reg31*reg49; reg70=reg7*pos_nodes[4][2]; reg56=reg63+reg56;
    reg65=reg25+reg65; reg25=pos_nodes[7][0]*reg47; reg32=reg39+reg32; reg39=pos_nodes[6][2]*reg72; reg63=pos_nodes[5][0]*reg9;
    reg11=reg57+reg11; reg57=pos_nodes[7][1]*reg47; reg71=reg73+reg71; reg73=reg31*reg27; T reg74=pos_nodes[10][2]*reg13;
    reg64=reg24-reg64; reg24=pos_nodes[11][0]*reg54; reg69=reg41+reg69; reg59=reg71+reg59; reg62=reg66+reg62;
    reg41=pos_nodes[11][2]*reg54; reg66=pos_nodes[8][0]*reg47; reg71=pos_nodes[11][1]*reg54; T reg75=pos_nodes[6][1]*reg14; T reg76=pos_nodes[7][2]*reg47;
    reg40=reg53+reg40; reg53=pos_nodes[10][0]*reg13; reg65=reg39+reg65; reg39=reg0*reg12; reg33=reg2*reg33;
    reg25=reg32+reg25; reg52=reg43-reg52; reg32=pos_nodes[10][1]*reg13; reg57=reg11+reg57; reg63=reg46+reg63;
    reg11=pos_nodes[8][1]*reg47; reg3=reg2*reg3; reg70=reg56+reg70; reg43=pos_nodes[5][2]*reg9; reg61=reg58-reg61;
    reg46=pos_nodes[6][0]*reg14; reg56=pos_nodes[12][2]*reg39; reg41=reg59+reg41; reg58=pos_nodes[7][1]*reg73; reg59=pos_nodes[9][1]*reg33;
    reg11=reg57-reg11; reg40=reg75+reg40; reg57=reg2*reg4; reg75=pos_nodes[6][2]*reg14; reg53=reg61+reg53;
    reg61=pos_nodes[11][0]*reg3; reg63=reg46+reg63; reg46=pos_nodes[7][0]*reg73; T reg77=var_inter[0]*reg12; reg76=reg65+reg76;
    reg65=pos_nodes[8][2]*reg47; reg31=reg31*reg68; reg66=reg25-reg66; reg43=reg70+reg43; reg25=pos_nodes[9][0]*reg33;
    reg74=reg64+reg74; reg64=pos_nodes[11][2]*reg3; reg71=reg62+reg71; reg62=pos_nodes[12][1]*reg39; reg32=reg52+reg32;
    reg52=pos_nodes[11][1]*reg3; reg24=reg69+reg24; reg69=pos_nodes[12][0]*reg39; reg70=pos_nodes[13][0]*reg77; T reg78=pos_nodes[10][0]*reg57;
    reg69=reg24-reg69; reg65=reg76-reg65; reg24=pos_nodes[9][2]*reg33; reg76=var_inter[1]*reg12; reg46=reg63+reg46;
    reg25=reg66+reg25; reg52=reg32+reg52; reg61=reg53+reg61; reg32=reg22*pos_nodes[12][2]; reg49=reg2*reg49;
    reg53=pos_nodes[8][0]*reg31; reg63=reg22*pos_nodes[12][1]; reg64=reg74+reg64; reg66=pos_nodes[10][1]*reg57; reg74=pos_nodes[8][1]*reg31;
    reg58=reg40+reg58; reg40=pos_nodes[13][2]*reg77; reg56=reg41-reg56; reg41=pos_nodes[7][2]*reg73; reg43=reg75+reg43;
    reg59=reg11+reg59; reg11=pos_nodes[13][1]*reg77; reg62=reg71-reg62; reg71=reg22*pos_nodes[12][0]; reg41=reg43+reg41;
    reg27=reg2*reg27; reg43=pos_nodes[11][0]*reg57; reg78=reg25+reg78; reg64=reg64-reg32; reg25=pos_nodes[14][2]*reg76;
    reg75=reg22*pos_nodes[14][1]; T reg79=reg22*pos_nodes[14][2]; reg40=reg56-reg40; reg58=reg74+reg58; reg66=reg59+reg66;
    reg56=reg49*pos_nodes[9][1]; reg59=pos_nodes[14][1]*reg76; reg11=reg62-reg11; reg62=pos_nodes[11][1]*reg57; reg46=reg53+reg46;
    reg53=reg49*pos_nodes[9][0]; reg70=reg69-reg70; reg69=pos_nodes[14][0]*reg76; reg24=reg65+reg24; reg65=pos_nodes[10][2]*reg57;
    reg61=reg61-reg71; reg74=reg22*pos_nodes[14][0]; T reg80=reg31*pos_nodes[8][2]; reg52=reg52-reg63; T reg81=reg49*pos_nodes[9][2];
    reg41=reg80+reg41; reg25=reg40-reg25; reg74=reg61+reg74; reg68=reg2*reg68; reg2=reg27*pos_nodes[10][0];
    reg65=reg24+reg65; reg24=pos_nodes[11][2]*reg57; reg40=reg27*pos_nodes[10][1]; reg56=reg58+reg56; reg59=reg11-reg59;
    reg62=reg66-reg62; reg43=reg78-reg43; reg75=reg52+reg75; reg69=reg70-reg69; reg79=reg64+reg79;
    reg53=reg46+reg53; reg40=reg56+reg40; reg11=reg68*pos_nodes[11][1]; reg2=reg53+reg2; reg81=reg41+reg81;
    reg41=reg27*pos_nodes[10][2]; reg46=reg68*pos_nodes[11][0]; reg52=reg75*reg25; reg53=reg59*reg79; reg56=reg22*pos_nodes[13][1];
    reg24=reg65-reg24; reg63=reg62-reg63; reg58=reg22*pos_nodes[13][0]; reg61=reg74*reg25; reg62=reg69*reg79;
    reg71=reg43-reg71; reg0=reg22*reg0; reg46=reg2+reg46; reg2=reg0*pos_nodes[12][0]; reg41=reg81+reg41;
    reg43=reg68*pos_nodes[11][2]; reg53=reg52-reg53; reg64=reg74*reg59; reg62=reg61-reg62; reg65=reg69*reg75;
    reg58=reg71+reg58; reg32=reg24-reg32; reg24=reg22*pos_nodes[13][2]; reg66=reg0*pos_nodes[12][1]; reg11=reg40+reg11;
    reg56=reg63+reg56; reg40=var_inter[0]*reg22; reg2=reg46+reg2; reg46=reg58*reg53; reg63=reg40*pos_nodes[13][0];
    reg66=reg11+reg66; reg11=reg40*pos_nodes[13][1]; reg70=reg56*reg62; reg43=reg41+reg43; reg41=reg0*pos_nodes[12][2];
    reg24=reg32+reg24; reg65=reg64-reg65; reg32=var_inter[1]*reg22; reg71=reg74*reg24; reg78=reg58*reg79;
    reg46=reg70-reg46; reg70=reg24*reg65; reg80=reg56*reg25; reg81=reg59*reg24; T reg82=reg69*reg24;
    T reg83=reg56*reg79; T reg84=reg75*reg24; T reg85=reg58*reg25; T reg86=reg32*pos_nodes[14][0]; T reg87=reg32*pos_nodes[14][1];
    reg63=reg2+reg63; reg2=reg40*pos_nodes[13][2]; reg41=reg43+reg41; reg11=reg66+reg11; reg86=reg63+reg86;
    reg82=reg85-reg82; reg71=reg78-reg71; reg43=reg58*reg59; reg84=reg83-reg84; reg63=reg69*reg56;
    reg66=reg58*reg75; reg81=reg80-reg81; reg70=reg46-reg70; reg2=reg41+reg2; reg41=reg32*pos_nodes[14][2];
    reg46=reg74*reg56; reg87=reg11+reg87; reg63=reg43-reg63; reg71=reg71/reg70; reg46=reg66-reg46;
    reg86=pos[0]-reg86; reg87=pos[1]-reg87; reg82=reg82/reg70; reg62=reg62/reg70; reg84=reg84/reg70;
    reg81=reg81/reg70; reg53=reg53/reg70; reg41=reg2+reg41; reg71=reg87*reg71; reg84=reg86*reg84;
    reg82=reg87*reg82; reg81=reg86*reg81; reg62=reg87*reg62; reg53=reg86*reg53; reg41=pos[2]-reg41;
    reg46=reg46/reg70; reg63=reg63/reg70; reg70=reg65/reg70; reg70=reg41*reg70; reg53=reg62-reg53;
    reg63=reg41*reg63; reg82=reg81-reg82; reg46=reg41*reg46; reg84=reg71-reg84; var_inter[0]+=reg53-reg70;
    var_inter[1]+=reg63+reg82; var_inter[2]+=reg84-reg46;

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
    T reg0=1-var_inter[0]; T reg1=2*var_inter[2]; reg0=reg0-var_inter[1]; reg1=reg1-1; T reg2=2*var_inter[0];
    T reg3=2*reg0; T reg4=0.5*reg0; T reg5=reg3-1; T reg6=2*var_inter[1]; T reg7=0.5*var_inter[0];
    T reg8=reg2-1; T reg9=pow(reg1,2); reg5=reg5*reg4; T reg10=1-reg1; T reg11=reg6-1;
    T reg12=0.5*var_inter[1]; reg9=1-reg9; reg8=reg7*reg8; reg11=reg12*reg11; reg4=reg4*reg9;
    T reg13=reg5*reg10; reg7=reg9*reg7; T reg14=reg10*reg8; reg14=reg14-reg7; reg13=reg13-reg4;
    T reg15=reg10*reg11; reg12=reg12*reg9; reg1=1+reg1; reg5=reg5*reg1; reg15=reg15-reg12;
    reg13=val[0]*reg13; reg14=val[1]*reg14; reg15=val[2]*reg15; reg4=reg5-reg4; reg8=reg1*reg8;
    reg14=reg13+reg14; reg15=reg14+reg15; reg4=val[3]*reg4; reg7=reg8-reg7; reg11=reg11*reg1;
    reg3=var_inter[0]*reg3; reg12=reg11-reg12; reg7=val[4]*reg7; reg4=reg15+reg4; reg5=reg10*reg3;
    reg12=val[5]*reg12; reg8=var_inter[1]*reg2; reg7=reg4+reg7; reg12=reg7+reg12; reg4=reg0*reg6;
    reg7=reg10*reg8; reg5=val[6]*reg5; reg10=reg10*reg4; reg7=val[7]*reg7; reg5=reg12+reg5;
    reg3=reg1*reg3; reg10=val[8]*reg10; reg7=reg5+reg7; reg10=reg7+reg10; reg3=val[9]*reg3;
    reg8=reg1*reg8; reg10=reg3+reg10; reg8=val[10]*reg8; reg4=reg1*reg4; reg8=reg10+reg8;
    reg4=val[11]*reg4; reg0=reg0*reg9; reg4=reg8+reg4; reg0=val[12]*reg0; reg1=var_inter[0]*reg9;
    reg0=reg4+reg0; reg1=val[13]*reg1; reg9=var_inter[1]*reg9; reg9=val[14]*reg9; reg1=reg0+reg1;
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
    T reg0=2*var_inter[0]; T reg1=var_inter[2]-0.14644660940672626914; T reg2=2*var_inter[1]; T reg3=reg2+reg0; T reg4=1-var_inter[2];
    reg1=reg1/0.70710678118654746172; reg4=reg4-0.14644660940672626914; reg3=reg3-1; T reg5=1-reg0; reg1=1-reg1;
    reg4=reg4/0.70710678118654746172; T reg6=1-reg2; T reg7=reg1*reg5; T reg8=reg3*reg1; reg4=1-reg4;
    reg1=reg1*reg6; reg7=val[1]*reg7; reg8=val[0]*reg8; reg1=val[2]*reg1; reg7=reg8+reg7;
    reg8=reg3*reg4; T reg9=reg5*reg4; reg8=val[3]*reg8; reg1=reg7+reg1; reg8=reg1+reg8;
    reg9=val[4]*reg9; reg4=reg6*reg4; reg9=reg8+reg9; reg4=val[5]*reg4; res=reg9+reg4;

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Wedge_15 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; T reg2=reg1+reg0; reg2=reg2-1; T reg3=1-reg0;
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[2]; reg1=reg1-1; T reg2=2*reg0;
    T reg3=2*var_inter[0]; T reg4=2*var_inter[1]; T reg5=reg3-1; T reg6=0.5*var_inter[0]; T reg7=pow(reg1,2);
    T reg8=reg4-1; T reg9=0.5*var_inter[1]; T reg10=0.5*reg0; T reg11=reg2-1; reg7=1-reg7;
    reg5=reg6*reg5; T reg12=1-reg1; reg11=reg11*reg10; reg8=reg9*reg8; reg1=1+reg1;
    T reg13=reg11*reg12; T reg14=reg12*reg8; reg10=reg10*reg7; reg9=reg9*reg7; T reg15=reg0*reg4;
    T reg16=var_inter[1]*reg3; reg2=var_inter[0]*reg2; reg11=reg11*reg1; reg8=reg8*reg1; T reg17=reg12*reg5;
    reg5=reg1*reg5; reg6=reg7*reg6; reg17=reg17-reg6; res[1]=reg17; reg13=reg13-reg10;
    res[0]=reg13; T reg18=var_inter[1]*reg7; res[14]=reg18; T reg19=var_inter[0]*reg7; res[13]=reg19;
    reg7=reg0*reg7; res[12]=reg7; reg0=reg1*reg15; res[11]=reg0; T reg20=reg1*reg16;
    res[10]=reg20; reg1=reg1*reg2; res[9]=reg1; reg15=reg12*reg15; res[8]=reg15;
    reg16=reg12*reg16; res[7]=reg16; reg2=reg12*reg2; res[6]=reg2; reg8=reg8-reg9;
    res[5]=reg8; reg6=reg5-reg6; res[4]=reg6; reg10=reg11-reg10; res[3]=reg10;
    reg9=reg14-reg9; res[2]=reg9;

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
