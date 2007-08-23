#ifndef LMT_TETRA_10
#define LMT_TETRA_10
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Tetra_10 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 17, 34, 51, 72, 133, 194, 255, 316, 377, }; // fonction de lordre du poly
    static const double values[] = {
        0.0416666666667,0.138196601125,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0,
        0.0416666666667,0.138196601125,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0,
        0.0416666666667,0.138196601125,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0,
        -0.133333333333,0.25,0.25,0.25,
        0.075,0.166666666667,0.166666666667,0.166666666667,
        0.075,0.166666666667,0.166666666667,0.5,
        0.075,0.5,0.166666666667,0.166666666667,
        0.075,0.166666666667,0.5,0.166666666667,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Tetra_10 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=3*nodes[0]->pos[2]; T reg1=3*nodes[0]->pos[1]; T reg2=2*nodes[4]->pos[1]; T reg3=nodes[2]->pos[1]+reg1; T reg4=4*nodes[4]->pos[1];
    T reg5=nodes[1]->pos[2]+reg0; T reg6=nodes[1]->pos[1]+reg1; T reg7=4*nodes[4]->pos[2]; T reg8=nodes[3]->pos[2]+reg0; T reg9=2*nodes[4]->pos[2];
    T reg10=nodes[3]->pos[1]+reg1; T reg11=nodes[2]->pos[2]+reg0; reg10=reg10-reg2; T reg12=2*nodes[6]->pos[1]; T reg13=2*nodes[5]->pos[1];
    reg2=reg3-reg2; reg8=reg8-reg9; reg3=2*nodes[6]->pos[2]; T reg14=2*nodes[5]->pos[2]; reg9=reg11-reg9;
    reg5=reg5-reg7; reg11=3*nodes[0]->pos[0]; reg6=reg6-reg4; reg6=reg13+reg6; reg9=reg9+reg14;
    T reg15=4*nodes[6]->pos[2]; T reg16=4*nodes[7]->pos[2]; reg8=reg8-reg3; T reg17=2*nodes[4]->pos[0]; reg5=reg14+reg5;
    reg14=4*nodes[4]->pos[0]; T reg18=nodes[1]->pos[0]+reg11; T reg19=nodes[2]->pos[0]+reg11; reg13=reg2+reg13; reg2=4*nodes[6]->pos[1];
    T reg20=4*nodes[7]->pos[1]; reg10=reg10-reg12; reg10=reg10-reg20; T reg21=nodes[3]->pos[0]+reg11; reg19=reg19-reg17;
    T reg22=2*nodes[7]->pos[2]; reg9=reg9-reg15; reg3=reg5-reg3; reg5=2*nodes[8]->pos[1]; reg12=reg6-reg12;
    reg18=reg18-reg14; reg6=2*nodes[5]->pos[0]; reg13=reg13-reg2; T reg23=2*nodes[7]->pos[1]; reg8=reg8-reg16;
    T reg24=2*nodes[8]->pos[2]; reg3=reg3-reg22; T reg25=4*nodes[6]->pos[0]; reg19=reg6+reg19; T reg26=2*nodes[6]->pos[0];
    reg6=reg18+reg6; reg18=2*nodes[9]->pos[2]; reg8=reg8+reg24; reg17=reg21-reg17; reg10=reg10+reg5;
    reg12=reg12-reg23; reg22=reg9-reg22; reg23=reg13-reg23; reg9=2*nodes[9]->pos[1]; reg8=reg8+reg18;
    reg6=reg6-reg26; reg12=reg5+reg12; reg19=reg19-reg25; reg5=2*nodes[7]->pos[0]; reg3=reg24+reg3;
    reg26=reg17-reg26; reg10=reg9+reg10; reg13=4*nodes[7]->pos[0]; reg9=reg23+reg9; reg22=reg18+reg22;
    reg17=reg10*reg3; reg26=reg26-reg13; reg18=reg8*reg12; reg21=2*nodes[9]->pos[0]; reg19=reg19-reg5;
    reg5=reg6-reg5; reg6=2*nodes[8]->pos[0]; reg8=reg9*reg8; reg10=reg22*reg10; reg3=reg9*reg3;
    reg12=reg22*reg12; reg26=reg6+reg26; reg6=reg5+reg6; reg10=reg8-reg10; reg17=reg18-reg17;
    reg19=reg19+reg21; reg10=reg6*reg10; reg17=reg19*reg17; reg26=reg21+reg26; reg3=reg12-reg3;
    reg17=reg10-reg17; reg3=reg26*reg3; T det_jac=reg17+reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[9],nodes[8],nodes[7],nodes[6],nodes[5],nodes[4],nodes[3],nodes[2],nodes[1],nodes[0]};
        for(unsigned i=0;i<10;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[0];
    T reg3=reg1-1; T reg4=reg2-1; T reg5=2*var_inter[1]; T reg6=2*var_inter[2]; T reg7=reg6-1;
    T reg8=reg5-1; T reg9=reg4*var_inter[0]; T reg10=reg0*reg3; T reg11=pos_nodes[1][0]*reg9; T reg12=reg8*var_inter[1];
    reg8=reg5+reg8; reg3=reg1+reg3; reg6=reg6+reg7; reg1=pos_nodes[1][1]*reg9; reg5=reg10*pos_nodes[0][1];
    T reg13=pos_nodes[0][0]*reg10; T reg14=pos_nodes[0][1]*reg3; T reg15=pos_nodes[2][1]*reg8; T reg16=pos_nodes[3][1]*reg6; T reg17=pos_nodes[2][0]*reg12;
    T reg18=pos_nodes[1][2]*reg9; T reg19=pos_nodes[0][2]*reg10; T reg20=pos_nodes[3][2]*reg6; T reg21=pos_nodes[0][0]*reg3; T reg22=pos_nodes[2][2]*reg8;
    T reg23=pos_nodes[0][2]*reg3; reg11=reg13+reg11; reg13=pos_nodes[2][0]*reg8; T reg24=pos_nodes[2][1]*reg12; T reg25=pos_nodes[3][0]*reg6;
    reg1=reg5+reg1; reg5=4*var_inter[0]; reg0=4*reg0; reg7=reg7*var_inter[2]; T reg26=pos_nodes[4][2]*reg5;
    reg22=reg22-reg23; T reg27=reg0*var_inter[0]; reg16=reg16-reg14; T reg28=4*var_inter[1]; reg13=reg13-reg21;
    T reg29=pos_nodes[4][0]*reg5; reg25=reg25-reg21; T reg30=pos_nodes[3][1]*reg7; reg24=reg1+reg24; reg1=pos_nodes[2][2]*reg12;
    reg18=reg19+reg18; reg15=reg15-reg14; reg20=reg20-reg23; reg19=pos_nodes[4][1]*reg5; reg4=reg2+reg4;
    reg2=4*var_inter[2]; T reg31=pos_nodes[3][0]*reg7; reg17=reg11+reg17; reg16=reg16-reg19; reg11=pos_nodes[5][1]*reg5;
    reg19=reg15-reg19; reg15=pos_nodes[4][0]*reg27; reg31=reg17+reg31; reg25=reg25-reg29; reg17=reg28*pos_nodes[6][1];
    T reg32=pos_nodes[1][1]*reg4; reg1=reg18+reg1; reg18=pos_nodes[3][2]*reg7; reg20=reg20-reg26; T reg33=reg5*var_inter[1];
    T reg34=reg0-reg5; T reg35=reg0-reg28; T reg36=pos_nodes[1][0]*reg4; T reg37=pos_nodes[5][2]*reg5; reg26=reg22-reg26;
    reg22=reg28*pos_nodes[6][0]; reg30=reg24+reg30; reg24=reg28*pos_nodes[6][2]; T reg38=pos_nodes[4][1]*reg27; T reg39=reg0-reg2;
    reg29=reg13-reg29; reg13=pos_nodes[5][0]*reg5; reg14=reg32-reg14; reg32=pos_nodes[4][1]*reg34; T reg40=pos_nodes[7][2]*reg39;
    reg20=reg20-reg24; reg38=reg30+reg38; reg30=pos_nodes[5][1]*reg33; reg18=reg1+reg18; reg11=reg19+reg11;
    reg1=pos_nodes[6][1]*reg35; reg19=pos_nodes[7][1]*reg39; T reg41=pos_nodes[6][2]*reg35; reg37=reg26+reg37; reg16=reg16-reg17;
    reg26=pos_nodes[1][2]*reg4; T reg42=pos_nodes[4][2]*reg27; T reg43=reg0*var_inter[1]; reg15=reg31+reg15; reg31=pos_nodes[7][0]*reg39;
    reg25=reg25-reg22; T reg44=pos_nodes[4][0]*reg34; reg21=reg36-reg21; reg36=pos_nodes[5][0]*reg33; T reg45=pos_nodes[6][0]*reg35;
    reg13=reg29+reg13; reg19=reg16+reg19; reg16=reg5*pos_nodes[8][1]; reg31=reg25+reg31; reg45=reg13+reg45;
    reg30=reg38+reg30; reg13=pos_nodes[6][1]*reg43; reg41=reg37+reg41; reg44=reg21+reg44; reg23=reg26-reg23;
    reg21=pos_nodes[4][2]*reg34; reg25=reg28*pos_nodes[5][0]; reg26=pos_nodes[7][2]*reg2; reg29=pos_nodes[5][2]*reg33; reg42=reg18+reg42;
    reg18=pos_nodes[7][0]*reg2; reg32=reg14+reg32; reg14=reg28*pos_nodes[5][1]; reg37=pos_nodes[7][1]*reg2; reg38=reg5*pos_nodes[8][2];
    reg40=reg20+reg40; reg20=pos_nodes[6][0]*reg43; reg36=reg15+reg36; reg15=pos_nodes[8][0]*reg5; reg1=reg11+reg1;
    reg0=reg0*var_inter[2]; reg11=pos_nodes[9][2]*reg2; reg15=reg31+reg15; reg16=reg19+reg16; reg29=reg42+reg29;
    reg14=reg32+reg14; reg25=reg44+reg25; reg19=reg28*pos_nodes[5][2]; reg21=reg23+reg21; reg23=reg28*pos_nodes[9][1];
    reg38=reg40+reg38; reg31=reg28*pos_nodes[9][2]; reg32=pos_nodes[6][2]*reg43; reg40=pos_nodes[9][1]*reg2; reg42=reg5*var_inter[2];
    reg41=reg41-reg26; reg44=pos_nodes[7][1]*reg0; reg13=reg30+reg13; reg1=reg1-reg37; reg30=pos_nodes[7][0]*reg0;
    reg20=reg36+reg20; reg36=reg28*pos_nodes[9][0]; reg45=reg45-reg18; T reg46=pos_nodes[9][0]*reg2; reg41=reg11+reg41;
    reg38=reg31+reg38; reg22=reg25-reg22; reg11=reg28*var_inter[2]; reg1=reg40+reg1; reg15=reg36+reg15;
    reg30=reg20+reg30; reg23=reg16+reg23; reg16=pos_nodes[8][0]*reg42; reg46=reg45+reg46; reg44=reg13+reg44;
    reg13=reg42*pos_nodes[8][1]; reg20=pos_nodes[7][2]*reg0; reg32=reg29+reg32; reg17=reg14-reg17; reg19=reg21+reg19;
    reg37=reg17-reg37; reg14=pos_nodes[8][1]*reg2; reg20=reg32+reg20; reg16=reg30+reg16; reg17=reg42*pos_nodes[8][2];
    reg21=reg11*pos_nodes[9][0]; reg25=reg23*reg41; reg29=reg1*reg38; reg30=reg11*pos_nodes[9][1]; reg31=reg46*reg38;
    reg32=reg15*reg41; reg13=reg44+reg13; reg36=pos_nodes[8][0]*reg2; reg18=reg22-reg18; reg24=reg19-reg24;
    reg17=reg20+reg17; reg19=reg11*pos_nodes[9][2]; reg25=reg29-reg25; reg20=reg46*reg23; reg32=reg31-reg32;
    reg22=pos_nodes[8][2]*reg2; reg26=reg24-reg26; reg36=reg18+reg36; reg18=reg15*reg1; reg13=reg30+reg13;
    reg14=reg37+reg14; reg16=reg21+reg16; reg21=var_inter[0]*reg14; reg24=var_inter[0]*reg36; reg30=reg36*reg25;
    reg37=reg14*reg32; reg18=reg20-reg18; reg13=pos[1]-reg13; reg22=reg26+reg22; reg16=pos[0]-reg16;
    reg17=reg19+reg17; reg30=reg37-reg30; reg19=reg22*reg18; reg26=reg15*reg22; reg37=reg36*reg41;
    reg40=reg46*reg22; reg44=reg14*reg38; reg45=reg23*reg22; T reg47=reg36*reg38; T reg48=reg14*reg41;
    T reg49=reg1*reg22; T reg50=var_inter[0]*reg22; reg21=reg13+reg21; reg13=var_inter[1]*reg1; reg17=pos[2]-reg17;
    reg24=reg16+reg24; reg16=var_inter[1]*reg46; reg45=reg44-reg45; reg49=reg48-reg49; reg40=reg37-reg40;
    T reg51=reg36*reg23; reg19=reg30-reg19; reg30=reg15*reg14; T reg52=reg36*reg1; T reg53=reg46*reg14;
    T reg54=var_inter[2]*reg15; T reg55=var_inter[2]*reg23; reg26=reg47-reg26; reg24=reg16+reg24; reg50=reg17+reg50;
    reg16=var_inter[1]*reg41; reg21=reg13+reg21; reg30=reg51-reg30; reg24=reg54+reg24; reg40=reg40/reg19;
    reg13=var_inter[2]*reg38; reg53=reg52-reg53; reg49=reg49/reg19; reg21=reg55+reg21; reg45=reg45/reg19;
    reg50=reg16+reg50; reg25=reg25/reg19; reg26=reg26/reg19; reg32=reg32/reg19; reg32=reg32*reg21;
    reg45=reg24*reg45; reg26=reg26*reg21; reg49=reg24*reg49; reg40=reg21*reg40; reg25=reg24*reg25;
    reg53=reg53/reg19; reg30=reg30/reg19; reg19=reg18/reg19; reg50=reg13+reg50; reg19=reg50*reg19;
    reg25=reg32-reg25; reg30=reg50*reg30; reg26=reg45-reg26; reg53=reg50*reg53; reg49=reg40-reg49;
    var_inter[0]=reg25-reg19; var_inter[1]=reg30+reg26; var_inter[2]=reg49-reg53;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[0]; T reg2=2*reg0;
    T reg3=2*var_inter[2]; T reg4=2*var_inter[1]; T reg5=reg2-1; T reg6=reg1-1; T reg7=reg6*var_inter[0];
    T reg8=reg5*reg0; T reg9=reg4-1; T reg10=reg3-1; reg5=reg2+reg5; reg3=reg3+reg10;
    reg4=reg4+reg9; reg2=reg8*pos_nodes[0][1]; T reg11=reg7*pos_nodes[1][1]; T reg12=reg7*pos_nodes[1][0]; T reg13=reg8*pos_nodes[0][0];
    reg9=reg9*var_inter[1]; T reg14=reg8*pos_nodes[0][2]; T reg15=reg7*pos_nodes[1][2]; T reg16=pos_nodes[3][2]*reg3; T reg17=pos_nodes[0][0]*reg5;
    T reg18=pos_nodes[2][2]*reg4; T reg19=pos_nodes[0][2]*reg5; T reg20=pos_nodes[0][1]*reg5; T reg21=pos_nodes[2][0]*reg4; T reg22=pos_nodes[2][1]*reg4;
    T reg23=pos_nodes[3][1]*reg3; reg13=reg12+reg13; reg12=reg9*pos_nodes[2][0]; T reg24=pos_nodes[3][0]*reg3; reg2=reg11+reg2;
    reg11=reg9*pos_nodes[2][1]; reg10=reg10*var_inter[2]; reg0=4*reg0; T reg25=4*var_inter[0]; T reg26=reg25*pos_nodes[4][2];
    reg18=reg18-reg19; reg21=reg21-reg17; T reg27=reg25*pos_nodes[4][0]; T reg28=reg10*pos_nodes[3][1]; reg2=reg11+reg2;
    reg24=reg24-reg17; reg11=4*var_inter[1]; reg13=reg12+reg13; reg12=reg10*pos_nodes[3][0]; reg23=reg23-reg20;
    T reg29=var_inter[0]*reg0; T reg30=reg25*pos_nodes[4][1]; reg22=reg22-reg20; reg6=reg1+reg6; reg16=reg16-reg19;
    reg1=4*var_inter[2]; reg14=reg15+reg14; reg15=reg9*pos_nodes[2][2]; reg14=reg15+reg14; reg15=reg0-reg11;
    T reg31=pos_nodes[1][1]*reg6; T reg32=reg10*pos_nodes[3][2]; reg23=reg23-reg30; T reg33=var_inter[1]*reg25; T reg34=reg11*pos_nodes[6][1];
    reg16=reg16-reg26; reg12=reg13+reg12; reg13=reg29*pos_nodes[4][0]; T reg35=reg25*pos_nodes[5][1]; reg30=reg22-reg30;
    reg26=reg18-reg26; reg18=reg25*pos_nodes[5][2]; reg22=reg11*pos_nodes[6][0]; T reg36=reg11*pos_nodes[6][2]; T reg37=pos_nodes[1][0]*reg6;
    T reg38=reg0-reg1; reg21=reg21-reg27; T reg39=reg25*pos_nodes[5][0]; T reg40=reg29*pos_nodes[4][1]; reg27=reg24-reg27;
    reg28=reg2+reg28; reg2=reg0-reg25; reg20=reg31-reg20; reg24=pos_nodes[4][1]*reg2; reg18=reg26+reg18;
    reg26=pos_nodes[6][2]*reg15; reg31=pos_nodes[1][2]*reg6; T reg41=pos_nodes[7][1]*reg38; reg35=reg30+reg35; reg30=pos_nodes[6][1]*reg15;
    T reg42=pos_nodes[7][2]*reg38; reg16=reg16-reg36; reg23=reg23-reg34; reg32=reg14+reg32; reg14=reg33*pos_nodes[5][1];
    reg40=reg28+reg40; reg28=reg29*pos_nodes[4][2]; reg13=reg12+reg13; reg12=reg33*pos_nodes[5][0]; reg39=reg21+reg39;
    reg21=pos_nodes[6][0]*reg15; T reg43=pos_nodes[7][0]*reg38; T reg44=var_inter[1]*reg0; reg27=reg27-reg22; reg17=reg37-reg17;
    reg37=pos_nodes[4][0]*reg2; reg0=var_inter[2]*reg0; reg42=reg16+reg42; reg16=reg25*pos_nodes[8][1]; reg41=reg23+reg41;
    reg19=reg31-reg19; reg23=reg25*pos_nodes[8][0]; reg43=reg27+reg43; reg28=reg32+reg28; reg21=reg39+reg21;
    reg14=reg40+reg14; reg27=reg44*pos_nodes[6][1]; reg31=pos_nodes[7][0]*reg1; reg24=reg20+reg24; reg20=reg11*pos_nodes[5][1];
    reg32=pos_nodes[7][2]*reg1; reg39=pos_nodes[7][1]*reg1; reg26=reg18+reg26; reg18=reg33*pos_nodes[5][2]; reg40=reg25*pos_nodes[8][2];
    T reg45=reg44*pos_nodes[6][0]; reg12=reg13+reg12; reg30=reg35+reg30; reg13=pos_nodes[4][2]*reg2; reg37=reg17+reg37;
    reg17=reg11*pos_nodes[5][0]; reg35=reg11*pos_nodes[5][2]; T reg46=var_inter[2]*reg25; reg13=reg19+reg13; reg40=reg42+reg40;
    reg19=reg11*pos_nodes[9][2]; reg20=reg24+reg20; reg24=pos_nodes[9][2]*reg1; reg26=reg26-reg32; reg42=reg44*pos_nodes[6][2];
    reg18=reg28+reg18; reg28=reg0*pos_nodes[7][0]; reg45=reg12+reg45; reg30=reg30-reg39; reg12=pos_nodes[9][1]*reg1;
    T reg47=reg11*pos_nodes[9][0]; reg23=reg43+reg23; reg16=reg41+reg16; reg41=reg11*pos_nodes[9][1]; reg17=reg37+reg17;
    reg37=pos_nodes[9][0]*reg1; reg21=reg21-reg31; reg27=reg14+reg27; reg14=reg0*pos_nodes[7][1]; reg22=reg17-reg22;
    reg24=reg26+reg24; reg19=reg40+reg19; reg35=reg13+reg35; reg13=var_inter[2]*reg11; reg17=reg46*pos_nodes[8][1];
    reg14=reg27+reg14; reg37=reg21+reg37; reg41=reg16+reg41; reg47=reg23+reg47; reg12=reg30+reg12;
    reg28=reg45+reg28; reg16=reg46*pos_nodes[8][0]; reg42=reg18+reg42; reg34=reg20-reg34; reg18=reg0*pos_nodes[7][2];
    reg20=reg12*reg19; reg18=reg42+reg18; reg21=reg46*pos_nodes[8][2]; reg36=reg35-reg36; reg31=reg22-reg31;
    reg22=pos_nodes[8][0]*reg1; reg23=reg47*reg24; reg26=reg37*reg19; reg27=reg13*pos_nodes[9][1]; reg17=reg14+reg17;
    reg16=reg28+reg16; reg14=pos_nodes[8][1]*reg1; reg39=reg34-reg39; reg28=reg13*pos_nodes[9][0]; reg30=reg41*reg24;
    reg14=reg39+reg14; reg27=reg17+reg27; reg17=reg47*reg12; reg22=reg31+reg22; reg28=reg16+reg28;
    reg32=reg36-reg32; reg16=pos_nodes[8][2]*reg1; reg23=reg26-reg23; reg31=reg37*reg41; reg30=reg20-reg30;
    reg21=reg18+reg21; reg18=reg13*pos_nodes[9][2]; reg34=reg14*reg23; reg18=reg21+reg18; reg21=var_inter[0]*reg22;
    reg35=var_inter[0]*reg14; reg36=reg22*reg30; reg17=reg31-reg17; reg28=pos[0]-reg28; reg27=pos[1]-reg27;
    reg16=reg32+reg16; reg32=reg12*reg16; reg39=reg14*reg24; reg40=reg41*reg16; reg42=reg14*reg19;
    reg43=reg16*reg17; reg36=reg34-reg36; reg34=reg22*reg19; reg45=reg47*reg16; T reg48=reg22*reg24;
    T reg49=reg37*reg16; T reg50=var_inter[0]*reg16; reg18=pos[2]-reg18; reg35=reg27+reg35; reg27=var_inter[1]*reg12;
    T reg51=var_inter[1]*reg37; reg21=reg28+reg21; reg28=reg37*reg14; T reg52=reg22*reg12; reg32=reg39-reg32;
    T reg53=reg47*reg14; reg40=reg42-reg40; T reg54=reg22*reg41; reg43=reg36-reg43; reg36=var_inter[2]*reg41;
    T reg55=var_inter[2]*reg47; reg21=reg51+reg21; reg35=reg27+reg35; reg27=var_inter[1]*reg24; reg50=reg18+reg50;
    reg45=reg34-reg45; reg49=reg48-reg49; reg28=reg52-reg28; reg53=reg54-reg53; reg18=var_inter[2]*reg19;
    reg35=reg36+reg35; reg32=reg32/reg43; reg23=reg23/reg43; reg40=reg40/reg43; reg21=reg55+reg21;
    reg50=reg27+reg50; reg49=reg49/reg43; reg30=reg30/reg43; reg45=reg45/reg43; reg49=reg49*reg35;
    reg32=reg21*reg32; reg45=reg45*reg35; reg40=reg21*reg40; reg23=reg23*reg35; reg30=reg21*reg30;
    reg28=reg28/reg43; reg53=reg53/reg43; reg43=reg17/reg43; reg50=reg18+reg50; reg43=reg43*reg50;
    reg30=reg23-reg30; reg53=reg50*reg53; reg45=reg40-reg45; reg28=reg50*reg28; reg32=reg49-reg32;
    var_inter[0]+=reg30-reg43; var_inter[1]+=reg53+reg45; var_inter[2]+=reg32-reg28;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[0]; T reg2=2*reg0;
    T reg3=2*var_inter[1]; reg2=reg2-1; reg1=reg1-1; reg1=var_inter[0]*reg1; reg3=reg3-1;
    T reg4=2*var_inter[2]; reg2=reg0*reg2; reg1=val[1]*reg1; reg3=var_inter[1]*reg3; reg4=reg4-1;
    reg2=val[0]*reg2; reg0=4*reg0; reg4=var_inter[2]*reg4; reg3=val[2]*reg3; reg1=reg2+reg1;
    reg3=reg1+reg3; reg4=val[3]*reg4; reg1=4*var_inter[0]; reg2=var_inter[0]*reg0; T reg5=var_inter[1]*reg1;
    reg4=reg3+reg4; reg2=val[4]*reg2; reg5=val[5]*reg5; reg3=var_inter[1]*reg0; reg2=reg4+reg2;
    reg5=reg2+reg5; reg3=val[6]*reg3; reg0=var_inter[2]*reg0; reg2=4*var_inter[1]; reg1=var_inter[2]*reg1;
    reg0=val[7]*reg0; reg3=reg5+reg3; reg0=reg3+reg0; reg1=val[8]*reg1; reg2=var_inter[2]*reg2;
    reg1=reg0+reg1; reg2=val[9]*reg2; res=reg1+reg2;

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Tetra_10> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

}
#endif // LMT_TETRA_10
