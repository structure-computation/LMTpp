#ifndef LMT_TETRA_10
#define LMT_TETRA_10
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Tetra_10 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 5, 10, 27, 48, 109, 170, 231, 292, 353, }; // fonction de lordre du poly
    static const double values[] = {
        0.166666666667,0.25,0.25,0.25,
        0.0,
        0.166666666667,0.25,0.25,0.25,
        0.0,
        0.0416666666667,0.138196601125,0.138196601125,0.138196601125,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
        0.0,
        -0.133333333333,0.25,0.25,0.25,
        0.075,0.166666666667,0.166666666667,0.166666666667,
        0.075,0.5,0.166666666667,0.166666666667,
        0.075,0.166666666667,0.5,0.166666666667,
        0.075,0.166666666667,0.166666666667,0.5,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Tetra_10 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=3*nodes[0]->pos[2]; T reg1=3*nodes[0]->pos[1]; T reg2=reg0+nodes[2]->pos[2]; T reg3=2*nodes[4]->pos[2]; T reg4=reg0+nodes[3]->pos[2];
    T reg5=4*nodes[4]->pos[2]; T reg6=reg0+nodes[1]->pos[2]; T reg7=reg1+nodes[3]->pos[1]; T reg8=4*nodes[4]->pos[1]; T reg9=reg1+nodes[1]->pos[1];
    T reg10=2*nodes[4]->pos[1]; T reg11=reg1+nodes[2]->pos[1]; reg7=reg7-reg10; T reg12=2*nodes[6]->pos[1]; reg9=reg9-reg8;
    reg6=reg6-reg5; T reg13=2*nodes[5]->pos[2]; reg2=reg2-reg3; reg10=reg11-reg10; reg11=2*nodes[6]->pos[2];
    T reg14=2*nodes[5]->pos[1]; reg3=reg4-reg3; reg4=3*nodes[0]->pos[0]; T reg15=reg4+nodes[2]->pos[0]; T reg16=2*nodes[4]->pos[0];
    reg9=reg14+reg9; reg6=reg13+reg6; T reg17=reg4+nodes[1]->pos[0]; T reg18=4*nodes[4]->pos[0]; reg14=reg10+reg14;
    reg10=4*nodes[6]->pos[1]; reg13=reg2+reg13; reg2=4*nodes[6]->pos[2]; reg7=reg7-reg12; T reg19=4*nodes[7]->pos[1];
    reg3=reg3-reg11; T reg20=4*nodes[7]->pos[2]; T reg21=reg4+nodes[3]->pos[0]; reg11=reg6-reg11; reg13=reg13-reg2;
    reg6=2*nodes[7]->pos[2]; reg14=reg14-reg10; reg12=reg9-reg12; reg9=2*nodes[5]->pos[0]; reg7=reg7-reg19;
    T reg22=2*nodes[8]->pos[2]; reg17=reg17-reg18; reg3=reg3-reg20; T reg23=2*nodes[7]->pos[1]; reg15=reg15-reg16;
    T reg24=2*nodes[8]->pos[1]; T reg25=2*nodes[9]->pos[1]; reg16=reg21-reg16; reg14=reg14-reg23; reg21=2*nodes[9]->pos[2];
    T reg26=2*nodes[6]->pos[0]; reg11=reg11-reg6; reg6=reg13-reg6; reg3=reg3+reg22; reg17=reg17+reg9;
    reg23=reg12-reg23; reg15=reg9+reg15; reg7=reg7+reg24; reg9=4*nodes[6]->pos[0]; reg17=reg17-reg26;
    reg3=reg3+reg21; reg12=2*nodes[7]->pos[0]; reg14=reg14+reg25; reg7=reg25+reg7; reg15=reg15-reg9;
    reg6=reg21+reg6; reg23=reg24+reg23; reg11=reg22+reg11; reg26=reg16-reg26; reg13=4*nodes[7]->pos[0];
    reg16=reg7*reg11; reg21=reg3*reg23; reg17=reg17-reg12; reg3=reg14*reg3; reg22=2*nodes[9]->pos[0];
    reg12=reg15-reg12; reg26=reg26-reg13; reg7=reg6*reg7; reg15=2*nodes[8]->pos[0]; reg17=reg17+reg15;
    reg11=reg14*reg11; reg23=reg6*reg23; reg26=reg15+reg26; reg16=reg21-reg16; reg12=reg12+reg22;
    reg7=reg3-reg7; reg11=reg23-reg11; reg26=reg22+reg26; reg16=reg12*reg16; reg7=reg17*reg7;
    reg11=reg26*reg11; reg16=reg7-reg16; T det_jac=reg16+reg11;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[1],nodes[3],nodes[2],nodes[4],nodes[8],nodes[7],nodes[6],nodes[5],nodes[9]};
        for(unsigned i=0;i<10;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[2];
    T reg3=2*var_inter[1]; T reg4=reg1-1; T reg5=reg3-1; T reg6=reg2-1; T reg7=2*var_inter[0];
    reg2=reg2+reg6; reg3=reg3+reg5; reg1=reg1+reg4; T reg8=reg7-1; T reg9=4*var_inter[0];
    T reg10=reg1*pos_nodes[0][0]; T reg11=reg2*pos_nodes[3][2]; T reg12=reg3*pos_nodes[2][2]; T reg13=reg1*pos_nodes[0][2]; T reg14=reg2*pos_nodes[3][1];
    T reg15=reg3*pos_nodes[2][1]; T reg16=reg1*pos_nodes[0][1]; T reg17=reg2*pos_nodes[3][0]; T reg18=reg3*pos_nodes[2][0]; T reg19=4*var_inter[2];
    reg4=reg0*reg4; reg15=reg15-reg16; T reg20=pos_nodes[4][1]*reg9; reg7=reg8+reg7; reg0=4*reg0;
    reg14=reg14-reg16; T reg21=4*var_inter[1]; reg11=reg11-reg13; reg17=reg17-reg10; reg18=reg18-reg10;
    reg8=reg8*var_inter[0]; T reg22=pos_nodes[4][2]*reg9; reg12=reg12-reg13; T reg23=pos_nodes[4][0]*reg9; T reg24=pos_nodes[6][0]*reg21;
    T reg25=pos_nodes[6][1]*reg21; T reg26=reg0-reg9; T reg27=reg0-reg19; reg15=reg15-reg20; T reg28=pos_nodes[5][1]*reg9;
    T reg29=reg8*pos_nodes[1][1]; reg20=reg14-reg20; reg11=reg11-reg22; reg14=reg4*pos_nodes[0][1]; T reg30=pos_nodes[5][2]*reg9;
    reg22=reg12-reg22; reg12=pos_nodes[6][2]*reg21; T reg31=reg0-reg21; reg18=reg18-reg23; T reg32=pos_nodes[5][0]*reg9;
    T reg33=reg8*pos_nodes[1][0]; reg23=reg17-reg23; reg17=reg4*pos_nodes[0][0]; reg5=reg5*var_inter[1]; T reg34=reg7*pos_nodes[1][1];
    T reg35=reg7*pos_nodes[1][0]; reg32=reg18+reg32; reg20=reg20-reg25; reg18=reg27*pos_nodes[7][1]; T reg36=pos_nodes[6][0]*reg31;
    T reg37=reg27*pos_nodes[7][2]; reg11=reg11-reg12; T reg38=pos_nodes[7][0]*reg27; reg23=reg23-reg24; reg14=reg29+reg14;
    reg29=pos_nodes[2][1]*reg5; T reg39=reg8*pos_nodes[1][2]; T reg40=pos_nodes[6][2]*reg31; reg30=reg22+reg30; reg22=reg26*pos_nodes[4][1];
    T reg41=reg7*pos_nodes[1][2]; reg10=reg35-reg10; reg35=reg26*pos_nodes[4][0]; reg6=reg6*var_inter[2]; T reg42=pos_nodes[2][0]*reg5;
    reg28=reg15+reg28; reg15=pos_nodes[6][1]*reg31; reg16=reg34-reg16; reg34=pos_nodes[0][2]*reg4; reg17=reg33+reg17;
    reg33=reg26*pos_nodes[4][2]; reg13=reg41-reg13; reg41=pos_nodes[5][0]*reg21; T reg43=reg19*pos_nodes[7][2]; reg35=reg10+reg35;
    reg40=reg30+reg40; reg37=reg11+reg37; reg10=pos_nodes[7][0]*reg19; reg11=var_inter[0]*reg0; reg30=pos_nodes[8][2]*reg9;
    reg34=reg39+reg34; reg39=pos_nodes[2][2]*reg5; reg15=reg28+reg15; reg28=pos_nodes[5][1]*reg21; reg18=reg20+reg18;
    reg20=pos_nodes[8][1]*reg9; reg22=reg16+reg22; reg29=reg14+reg29; reg38=reg23+reg38; reg14=pos_nodes[3][1]*reg6;
    reg16=pos_nodes[8][0]*reg9; reg23=reg19*pos_nodes[7][1]; T reg44=pos_nodes[3][0]*reg6; reg36=reg32+reg36; reg42=reg17+reg42;
    reg17=pos_nodes[3][2]*reg6; reg39=reg34+reg39; reg15=reg15-reg23; reg32=pos_nodes[9][1]*reg19; reg36=reg36-reg10;
    reg34=pos_nodes[9][2]*reg21; reg30=reg37+reg30; reg37=pos_nodes[9][0]*reg19; reg20=reg18+reg20; reg18=pos_nodes[9][1]*reg21;
    T reg45=pos_nodes[9][0]*reg21; reg33=reg13+reg33; reg13=reg9*var_inter[1]; reg44=reg42+reg44; reg42=pos_nodes[4][0]*reg11;
    reg16=reg38+reg16; reg38=pos_nodes[4][1]*reg11; reg14=reg29+reg14; reg41=reg35+reg41; reg40=reg40-reg43;
    reg29=pos_nodes[9][2]*reg19; reg35=pos_nodes[5][2]*reg21; reg28=reg22+reg28; reg45=reg16+reg45; reg24=reg41-reg24;
    reg16=pos_nodes[5][0]*reg13; reg42=reg44+reg42; reg22=reg0*var_inter[1]; reg41=pos_nodes[4][2]*reg11; reg37=reg36+reg37;
    reg35=reg33+reg35; reg25=reg28-reg25; reg28=pos_nodes[5][1]*reg13; reg38=reg14+reg38; reg29=reg40+reg29;
    reg17=reg39+reg17; reg18=reg20+reg18; reg32=reg15+reg32; reg34=reg30+reg34; reg41=reg17+reg41;
    reg14=pos_nodes[8][1]*reg19; reg12=reg35-reg12; reg23=reg25-reg23; reg15=pos_nodes[8][0]*reg19; reg17=pos_nodes[5][2]*reg13;
    reg10=reg24-reg10; reg20=reg45*reg29; reg24=reg37*reg34; reg25=pos_nodes[6][1]*reg22; reg28=reg38+reg28;
    reg16=reg42+reg16; reg30=reg18*reg29; reg33=reg32*reg34; reg0=reg0*var_inter[2]; reg35=pos_nodes[6][0]*reg22;
    reg35=reg16+reg35; reg14=reg23+reg14; reg16=pos_nodes[7][0]*reg0; reg23=reg45*reg32; reg20=reg24-reg20;
    reg36=reg37*reg18; reg30=reg33-reg30; reg38=pos_nodes[7][1]*reg0; reg39=reg9*var_inter[2]; reg43=reg12-reg43;
    reg12=pos_nodes[8][2]*reg19; reg25=reg28+reg25; reg15=reg10+reg15; reg17=reg41+reg17; reg10=pos_nodes[6][2]*reg22;
    reg28=pos_nodes[8][1]*reg39; reg38=reg25+reg38; reg12=reg43+reg12; reg10=reg17+reg10; reg17=pos_nodes[8][0]*reg39;
    reg16=reg35+reg16; reg25=pos_nodes[7][2]*reg0; reg35=reg21*var_inter[2]; reg40=reg15*reg30; reg41=reg14*reg20;
    reg23=reg36-reg23; reg42=pos_nodes[9][0]*reg35; reg17=reg16+reg17; reg16=reg32*reg12; reg43=reg15*reg34;
    reg44=reg14*reg29; T reg46=reg18*reg12; T reg47=reg14*reg34; T reg48=reg37*reg12; T reg49=reg12*reg23;
    reg40=reg41-reg40; reg41=reg15*reg29; T reg50=pos_nodes[8][2]*reg39; reg25=reg10+reg25; reg28=reg38+reg28;
    reg10=pos_nodes[9][1]*reg35; reg38=reg45*reg12; reg38=reg43-reg38; reg42=reg17+reg42; reg16=reg44-reg16;
    reg48=reg41-reg48; reg17=reg15*reg18; T reg51=reg45*reg14; T reg52=reg15*reg32; T reg53=reg37*reg14;
    reg46=reg47-reg46; reg49=reg40-reg49; reg40=pos_nodes[9][2]*reg35; reg50=reg25+reg50; reg10=reg28+reg10;
    reg16=reg16/reg49; reg46=reg46/reg49; reg30=reg30/reg49; reg40=reg50+reg40; reg20=reg20/reg49;
    reg10=pos[1]-reg10; reg38=reg38/reg49; reg42=pos[0]-reg42; reg48=reg48/reg49; reg51=reg17-reg51;
    reg53=reg52-reg53; reg30=reg42*reg30; reg20=reg10*reg20; reg46=reg42*reg46; reg38=reg10*reg38;
    reg40=pos[2]-reg40; reg16=reg42*reg16; reg48=reg10*reg48; reg53=reg53/reg49; reg51=reg51/reg49;
    reg49=reg23/reg49; reg53=reg40*reg53; reg16=reg48-reg16; reg38=reg46-reg38; reg51=reg40*reg51;
    reg30=reg20-reg30; reg49=reg40*reg49; var_inter[1]=reg51+reg38; var_inter[2]=reg16-reg53; var_inter[0]=reg30-reg49;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[2];
    T reg3=2*var_inter[1]; T reg4=reg1-1; T reg5=reg3-1; T reg6=reg2-1; reg2=reg2+reg6;
    T reg7=2*var_inter[0]; reg1=reg1+reg4; reg3=reg3+reg5; T reg8=reg1*pos_nodes[0][1]; T reg9=reg3*pos_nodes[2][1];
    T reg10=reg2*pos_nodes[3][1]; T reg11=reg1*pos_nodes[0][2]; T reg12=reg3*pos_nodes[2][2]; T reg13=reg2*pos_nodes[3][0]; T reg14=reg2*pos_nodes[3][2];
    T reg15=reg7-1; T reg16=reg3*pos_nodes[2][0]; T reg17=reg1*pos_nodes[0][0]; T reg18=4*var_inter[0]; T reg19=4*var_inter[1];
    reg9=reg9-reg8; T reg20=pos_nodes[4][1]*reg18; reg10=reg10-reg8; reg12=reg12-reg11; T reg21=pos_nodes[4][2]*reg18;
    reg14=reg14-reg11; reg7=reg7+reg15; reg4=reg4*reg0; T reg22=4*var_inter[2]; reg0=4*reg0;
    reg15=reg15*var_inter[0]; reg13=reg13-reg17; T reg23=pos_nodes[4][0]*reg18; reg16=reg16-reg17; T reg24=pos_nodes[5][2]*reg18;
    reg12=reg12-reg21; reg21=reg14-reg21; reg9=reg9-reg20; reg14=pos_nodes[5][1]*reg18; T reg25=reg19*pos_nodes[6][1];
    T reg26=reg19*pos_nodes[6][2]; T reg27=reg0-reg18; reg13=reg13-reg23; T reg28=pos_nodes[5][0]*reg18; reg23=reg16-reg23;
    reg16=reg7*pos_nodes[1][1]; T reg29=reg4*pos_nodes[0][0]; T reg30=reg15*pos_nodes[1][0]; reg20=reg10-reg20; reg10=reg19*pos_nodes[6][0];
    reg5=reg5*var_inter[1]; T reg31=reg15*pos_nodes[1][1]; T reg32=reg0-reg19; T reg33=reg4*pos_nodes[0][1]; T reg34=reg7*pos_nodes[1][0];
    T reg35=reg0-reg22; T reg36=reg7*pos_nodes[1][2]; reg33=reg31+reg33; reg31=pos_nodes[2][1]*reg5; T reg37=reg35*pos_nodes[7][1];
    reg24=reg12+reg24; reg12=pos_nodes[6][2]*reg32; reg21=reg21-reg26; T reg38=reg35*pos_nodes[7][2]; T reg39=reg4*pos_nodes[0][2];
    T reg40=reg15*pos_nodes[1][2]; T reg41=pos_nodes[6][0]*reg32; reg28=reg23+reg28; reg6=reg6*var_inter[2]; reg23=reg27*pos_nodes[4][0];
    reg17=reg34-reg17; reg30=reg29+reg30; reg29=pos_nodes[2][0]*reg5; reg8=reg16-reg8; reg16=reg27*pos_nodes[4][1];
    reg14=reg9+reg14; reg9=pos_nodes[6][1]*reg32; reg34=pos_nodes[7][0]*reg35; reg20=reg20-reg25; reg13=reg13-reg10;
    reg11=reg36-reg11; reg36=reg27*pos_nodes[4][2]; T reg42=reg22*pos_nodes[7][2]; T reg43=reg0*var_inter[0]; T reg44=pos_nodes[8][0]*reg18;
    reg34=reg13+reg34; reg13=pos_nodes[8][1]*reg18; reg12=reg24+reg12; reg24=pos_nodes[8][2]*reg18; reg16=reg8+reg16;
    reg41=reg28+reg41; reg8=reg22*pos_nodes[7][1]; reg38=reg21+reg38; reg21=reg19*pos_nodes[5][1]; reg40=reg39+reg40;
    reg28=pos_nodes[2][2]*reg5; reg9=reg14+reg9; reg37=reg20+reg37; reg23=reg17+reg23; reg31=reg33+reg31;
    reg14=reg19*pos_nodes[5][0]; reg17=pos_nodes[7][0]*reg22; reg20=reg6*pos_nodes[3][1]; reg33=reg6*pos_nodes[3][0]; reg29=reg30+reg29;
    reg13=reg37+reg13; reg30=reg18*var_inter[1]; reg37=pos_nodes[9][0]*reg22; reg41=reg41-reg17; reg39=reg43*pos_nodes[4][1];
    reg20=reg31+reg20; reg38=reg24+reg38; reg24=reg19*pos_nodes[9][2]; reg21=reg16+reg21; reg16=pos_nodes[9][1]*reg22;
    reg28=reg40+reg28; reg31=reg6*pos_nodes[3][2]; reg9=reg9-reg8; reg36=reg11+reg36; reg11=reg19*pos_nodes[5][2];
    reg40=reg43*pos_nodes[4][0]; reg33=reg29+reg33; reg29=reg19*pos_nodes[9][1]; reg14=reg23+reg14; reg34=reg44+reg34;
    reg23=reg19*pos_nodes[9][0]; reg12=reg12-reg42; reg44=pos_nodes[9][2]*reg22; reg23=reg34+reg23; reg10=reg14-reg10;
    reg14=reg0*var_inter[1]; reg34=reg43*pos_nodes[4][2]; reg31=reg28+reg31; reg28=pos_nodes[5][0]*reg30; reg40=reg33+reg40;
    reg16=reg9+reg16; reg39=reg20+reg39; reg9=pos_nodes[5][1]*reg30; reg11=reg36+reg11; reg29=reg13+reg29;
    reg44=reg12+reg44; reg37=reg41+reg37; reg24=reg38+reg24; reg25=reg21-reg25; reg12=pos_nodes[6][0]*reg14;
    reg26=reg11-reg26; reg28=reg40+reg28; reg11=pos_nodes[5][2]*reg30; reg17=reg10-reg17; reg10=pos_nodes[8][0]*reg22;
    reg13=pos_nodes[6][1]*reg14; reg9=reg39+reg9; reg34=reg31+reg34; reg20=reg23*reg44; reg21=reg37*reg24;
    reg0=reg0*var_inter[2]; reg31=pos_nodes[8][1]*reg22; reg8=reg25-reg8; reg25=reg16*reg24; reg33=reg29*reg44;
    reg36=pos_nodes[7][0]*reg0; reg12=reg28+reg12; reg42=reg26-reg42; reg26=var_inter[2]*reg18; reg11=reg34+reg11;
    reg28=pos_nodes[8][2]*reg22; reg17=reg10+reg17; reg31=reg8+reg31; reg8=pos_nodes[7][1]*reg0; reg13=reg9+reg13;
    reg9=pos_nodes[6][2]*reg14; reg33=reg25-reg33; reg10=reg23*reg16; reg34=reg37*reg29; reg20=reg21-reg20;
    reg42=reg28+reg42; reg28=pos_nodes[8][0]*reg26; reg38=pos_nodes[7][2]*reg0; reg9=reg11+reg9; reg36=reg12+reg36;
    reg11=pos_nodes[8][1]*reg26; reg8=reg13+reg8; reg10=reg34-reg10; reg12=reg31*reg20; reg13=reg17*reg33;
    reg39=reg19*var_inter[2]; reg36=reg28+reg36; reg28=reg39*pos_nodes[9][1]; reg40=reg39*pos_nodes[9][0]; reg11=reg8+reg11;
    reg8=pos_nodes[8][2]*reg26; reg41=reg37*reg42; T reg45=reg17*reg44; T reg46=reg23*reg42; T reg47=reg17*reg24;
    T reg48=reg16*reg42; T reg49=reg31*reg44; T reg50=reg29*reg42; T reg51=reg31*reg24; T reg52=reg42*reg10;
    reg13=reg12-reg13; reg38=reg9+reg38; reg52=reg13-reg52; reg50=reg51-reg50; reg28=reg11+reg28;
    reg48=reg49-reg48; reg9=reg39*pos_nodes[9][2]; reg46=reg47-reg46; reg38=reg8+reg38; reg41=reg45-reg41;
    reg8=reg17*reg29; reg11=reg23*reg31; reg12=reg17*reg16; reg40=reg36+reg40; reg13=reg37*reg31;
    reg50=reg50/reg52; reg28=pos[1]-reg28; reg48=reg48/reg52; reg33=reg33/reg52; reg20=reg20/reg52;
    reg46=reg46/reg52; reg13=reg12-reg13; reg9=reg38+reg9; reg11=reg8-reg11; reg41=reg41/reg52;
    reg40=pos[0]-reg40; reg50=reg40*reg50; reg9=pos[2]-reg9; reg20=reg28*reg20; reg46=reg28*reg46;
    reg48=reg40*reg48; reg41=reg28*reg41; reg33=reg40*reg33; reg13=reg13/reg52; reg11=reg11/reg52;
    reg52=reg10/reg52; reg13=reg9*reg13; reg48=reg41-reg48; reg46=reg50-reg46; reg11=reg9*reg11;
    reg52=reg9*reg52; reg33=reg20-reg33; var_inter[1]+=reg11+reg46; var_inter[2]+=reg48-reg13; var_inter[0]+=reg33-reg52;

}
template<> struct ElemVarInterFromPosNonLinear<Tetra_10> { static const bool res = 3; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[0];
    T reg3=2*var_inter[1]; reg2=reg2-1; reg1=reg1-1; T reg4=2*var_inter[2]; reg3=reg3-1;
    reg1=reg1*reg0; reg2=var_inter[0]*reg2; reg1=val[0]*reg1; reg2=val[1]*reg2; reg3=var_inter[1]*reg3;
    reg4=reg4-1; reg0=4*reg0; reg4=var_inter[2]*reg4; reg3=val[2]*reg3; reg2=reg1+reg2;
    reg1=var_inter[0]*reg0; reg4=val[3]*reg4; reg3=reg2+reg3; reg2=4*var_inter[0]; reg1=val[4]*reg1;
    T reg5=var_inter[1]*reg2; reg4=reg3+reg4; reg1=reg4+reg1; reg5=val[5]*reg5; reg3=var_inter[1]*reg0;
    reg0=var_inter[2]*reg0; reg3=val[6]*reg3; reg5=reg1+reg5; reg1=4*var_inter[1]; reg2=var_inter[2]*reg2;
    reg0=val[7]*reg0; reg3=reg5+reg3; reg1=var_inter[2]*reg1; reg2=val[8]*reg2; reg0=reg3+reg0;
    reg1=val[9]*reg1; reg2=reg0+reg2; res=reg2+reg1;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_1
#define STRUCT_Gauss_1
struct Gauss_1 {};
#endif // STRUCT_Gauss_1
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Gauss_1 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=var_inter[0]-0.25; T reg1=0.25+reg0; T reg2=var_inter[1]-0.25; reg1=reg1/0.25; T reg3=0.25+reg2;
    reg3=reg1*reg3; reg1=var_inter[2]-0.25; reg3=reg3/0.25; T reg4=0.25+reg1; reg4=reg3*reg4;
    reg4=reg4/0.25; res=val[0]*reg4;

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_3
#define STRUCT_Gauss_3
struct Gauss_3 {};
#endif // STRUCT_Gauss_3
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Gauss_3 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=var_inter[0]-0.5; T reg1=var_inter[0]-0.25; T reg2=var_inter[0]-0.16666666666666665741; T reg3=reg2*reg0; reg0=reg1*reg0;
    T reg4=var_inter[1]-0.16666666666666665741; reg3=reg3/0.020833333333333335646; T reg5=var_inter[1]-0.25; reg2=reg1*reg2; reg0=reg0/0.027777777777777783175;
    reg0=reg5*reg0; reg2=reg2/0.083333333333333342585; reg3=reg3*reg4; T reg6=var_inter[1]-0.5; reg2=reg5*reg2;
    T reg7=reg6*reg0; reg3=reg6*reg3; T reg8=var_inter[2]-0.25; reg2=reg6*reg2; reg6=var_inter[2]-0.16666666666666665741;
    reg7=reg7/0.027777777777777783175; reg3=reg3/0.020833333333333335646; T reg9=reg3*reg6; T reg10=var_inter[2]-0.5; reg2=reg2/0.027777777777777783175;
    reg0=reg4*reg0; reg7=reg8*reg7; reg9=reg9*reg10; reg2=reg8*reg2; reg4=reg10*reg7;
    reg0=reg0/0.083333333333333342585; reg0=reg8*reg0; reg2=reg10*reg2; reg4=reg4/0.027777777777777783175; reg9=reg9/0.020833333333333335646;
    reg4=val[1]*reg4; reg9=val[0]*reg9; reg2=reg2/0.027777777777777783175; reg0=reg10*reg0; reg7=reg6*reg7;
    reg0=reg0/0.027777777777777783175; reg2=val[2]*reg2; reg9=reg4-reg9; reg2=reg9+reg2; reg0=val[3]*reg0;
    reg7=reg7/0.083333333333333342585; reg0=reg2+reg0; reg7=val[4]*reg7; res=reg0+reg7;

}
#ifndef STRUCT_Gauss_2
#define STRUCT_Gauss_2
struct Gauss_2 {};
#endif // STRUCT_Gauss_2
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Gauss_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=var_inter[0]-0.58541019662496851517; T reg1=var_inter[0]-0.1381966011250105042; reg1=reg1/0.44721359549995798321; reg0=reg0/0.44721359549995798321; T reg2=var_inter[1]-0.58541019662496851517;
    reg1=reg2*reg1; T reg3=var_inter[1]-0.1381966011250105042; reg2=reg0*reg2; reg1=reg1/0.44721359549995798321; T reg4=var_inter[2]-0.58541019662496851517;
    reg2=reg2/0.44721359549995798321; reg3=reg0*reg3; reg0=reg2*reg4; reg1=reg4*reg1; reg3=reg3/0.44721359549995798321;
    reg1=reg1/0.44721359549995798321; reg3=reg4*reg3; reg4=var_inter[2]-0.1381966011250105042; reg0=reg0/0.44721359549995798321; reg0=val[0]*reg0;
    T reg5=val[1]*reg1; reg3=reg3/0.44721359549995798321; reg4=reg2*reg4; reg0=reg5-reg0; reg5=val[2]*reg3;
    reg4=reg4/0.44721359549995798321; reg5=reg0+reg5; reg4=val[3]*reg4; res=reg5+reg4;

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
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
template<class TVI,class TVAL> void get_shape_functions(const Tetra_10 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[2];
    T reg3=2*var_inter[1]; T reg4=2*var_inter[0]; T reg5=4*reg0; reg2=reg2-1; reg3=reg3-1;
    reg4=reg4-1; T reg6=4*var_inter[1]; T reg7=4*var_inter[0]; reg1=reg1-1; reg0=reg1*reg0;
    res[0]=reg0; reg6=var_inter[2]*reg6; res[9]=reg6; reg4=var_inter[0]*reg4; res[1]=reg4;
    reg1=var_inter[2]*reg7; res[8]=reg1; reg3=var_inter[1]*reg3; res[2]=reg3; T reg8=var_inter[2]*reg5;
    res[7]=reg8; T reg9=var_inter[1]*reg5; res[6]=reg9; reg2=var_inter[2]*reg2; res[3]=reg2;
    reg7=var_inter[1]*reg7; res[5]=reg7; reg5=var_inter[0]*reg5; res[4]=reg5;

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

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Tetra_10,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[0]; T reg2=2*var_inter[1];
    T reg3=2*var_inter[2]; T reg4=2*reg0; T reg5=reg1-1; T reg6=reg2-1; T reg7=reg4-1;
    T reg8=reg3-1; T reg9=4*var_inter[0]; reg2=reg2+reg6; reg3=reg3+reg8; reg1=reg1+reg5;
    reg4=reg4+reg7; T reg10=4*reg0; T reg11=reg1*elem.pos(1)[2]; T reg12=elem.pos(0)[2]*reg4; T reg13=elem.pos(0)[1]*reg4;
    T reg14=elem.pos(1)[1]*reg1; T reg15=elem.pos(3)[2]*reg3; T reg16=reg2*elem.pos(2)[2]; T reg17=elem.pos(3)[1]*reg3; T reg18=reg2*elem.pos(2)[1];
    T reg19=reg10-reg9; T reg20=4*var_inter[2]; reg17=reg17-reg13; reg11=reg11-reg12; reg18=reg18-reg13;
    reg14=reg14-reg13; T reg21=elem.pos(4)[1]*reg9; T reg22=elem.pos(4)[2]*reg9; reg15=reg15-reg12; T reg23=4*var_inter[1];
    T reg24=elem.pos(4)[1]*reg19; T reg25=elem.pos(4)[2]*reg19; reg16=reg16-reg12; reg2=reg2*elem.pos(2)[0]; T reg26=elem.pos(0)[0]*reg4;
    T reg27=reg10-reg20; T reg28=elem.pos(5)[2]*reg9; reg18=reg18-reg21; reg15=reg15-reg22; reg24=reg14+reg24;
    reg14=elem.pos(5)[1]*reg23; T reg29=elem.pos(6)[1]*reg23; T reg30=elem.pos(5)[2]*reg23; reg1=elem.pos(1)[0]*reg1; reg17=reg17-reg21;
    reg16=reg16-reg22; T reg31=elem.pos(5)[1]*reg9; reg11=reg25+reg11; reg25=elem.pos(6)[2]*reg23; T reg32=reg10-reg23;
    T reg33=elem.pos(7)[1]*reg27; reg16=reg28+reg16; reg19=elem.pos(4)[0]*reg19; reg28=elem.pos(6)[2]*reg32; reg1=reg1-reg26;
    reg2=reg2-reg26; reg24=reg14+reg24; reg30=reg11+reg30; reg15=reg15-reg25; reg18=reg31+reg18;
    reg3=elem.pos(3)[0]*reg3; reg11=elem.pos(6)[1]*reg32; reg14=elem.pos(7)[2]*reg27; reg31=elem.pos(4)[0]*reg9; reg17=reg17-reg29;
    reg28=reg16+reg28; reg33=reg17+reg33; reg16=elem.pos(5)[0]*reg9; reg24=reg24-reg29; reg18=reg11+reg18;
    reg11=elem.pos(5)[0]*reg23; reg17=reg9*elem.pos(8)[1]; T reg34=elem.pos(7)[1]*reg20; T reg35=elem.pos(7)[2]*reg20; reg1=reg19+reg1;
    reg30=reg30-reg25; reg15=reg14+reg15; reg2=reg2-reg31; reg3=reg3-reg26; reg14=reg9*elem.pos(8)[2];
    reg33=reg17+reg33; reg17=elem.pos(9)[1]*reg20; reg19=reg23*elem.pos(9)[2]; reg18=reg18-reg34; reg2=reg16+reg2;
    reg30=reg30-reg35; reg16=elem.pos(9)[2]*reg20; reg28=reg28-reg35; reg3=reg3-reg31; reg32=elem.pos(6)[0]*reg32;
    T reg36=elem.pos(8)[2]*reg20; T reg37=elem.pos(8)[1]*reg20; reg24=reg24-reg34; reg15=reg14+reg15; reg14=elem.pos(6)[0]*reg23;
    T reg38=reg23*elem.pos(9)[1]; reg11=reg1+reg11; reg11=reg11-reg14; reg37=reg24+reg37; reg36=reg30+reg36;
    reg27=elem.pos(7)[0]*reg27; reg1=elem.pos(7)[0]*reg20; reg17=reg18+reg17; reg38=reg33+reg38; reg19=reg15+reg19;
    reg16=reg28+reg16; reg2=reg32+reg2; reg3=reg3-reg14; reg15=reg9*elem.pos(8)[0]; reg3=reg27+reg3;
    reg2=reg2-reg1; reg18=elem.pos(9)[0]*reg20; reg24=elem.pos(8)[0]*reg20; reg11=reg11-reg1; reg27=reg38*reg16;
    reg28=reg17*reg19; reg30=reg36*reg38; reg32=reg37*reg19; reg33=reg23*elem.pos(9)[0]; reg27=reg28-reg27;
    reg15=reg3+reg15; reg3=reg37*reg16; reg28=reg36*reg17; reg24=reg11+reg24; reg30=reg32-reg30;
    reg18=reg2+reg18; reg33=reg15+reg33; reg2=reg24*reg27; reg11=reg30*reg18; reg28=reg3-reg28;
    reg11=reg2-reg11; reg2=reg28*reg33; reg11=reg2+reg11; return reg11;

}
}
#endif // LMT_TETRA_10
