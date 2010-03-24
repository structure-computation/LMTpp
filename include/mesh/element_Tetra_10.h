#ifndef LMT_TETRA_10
#define LMT_TETRA_10
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Tetra_10 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 17, 34, 51, 72, 133, 194, 255, 316, 377, }; // fonction de lordre du poly
    static const double values[] = {
        0.0416666666667,0.138196601125,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
        0.0,
        0.0416666666667,0.138196601125,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
        0.0,
        0.0416666666667,0.138196601125,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
        0.0,
        -0.133333333333,0.25,0.25,0.25,
        0.075,0.166666666667,0.166666666667,0.166666666667,
        0.075,0.166666666667,0.5,0.166666666667,
        0.075,0.5,0.166666666667,0.166666666667,
        0.075,0.166666666667,0.166666666667,0.5,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Tetra_10 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=3*nodes[0]->pos[2]; T reg1=3*nodes[0]->pos[1]; T reg2=2*nodes[4]->pos[1]; T reg3=nodes[2]->pos[1]+reg1; T reg4=nodes[1]->pos[1]+reg1;
    T reg5=nodes[1]->pos[2]+reg0; T reg6=4*nodes[4]->pos[1]; T reg7=4*nodes[4]->pos[2]; T reg8=nodes[3]->pos[1]+reg1; T reg9=nodes[3]->pos[2]+reg0;
    T reg10=2*nodes[4]->pos[2]; T reg11=nodes[2]->pos[2]+reg0; reg8=reg8-reg2; T reg12=2*nodes[6]->pos[1]; T reg13=2*nodes[5]->pos[1];
    reg2=reg3-reg2; reg9=reg9-reg10; reg3=2*nodes[6]->pos[2]; T reg14=2*nodes[5]->pos[2]; reg10=reg11-reg10;
    reg5=reg5-reg7; reg11=3*nodes[0]->pos[0]; reg4=reg4-reg6; reg4=reg13+reg4; reg10=reg10+reg14;
    T reg15=4*nodes[6]->pos[2]; T reg16=4*nodes[7]->pos[1]; reg9=reg9-reg3; T reg17=4*nodes[7]->pos[2]; T reg18=2*nodes[4]->pos[0];
    T reg19=4*nodes[4]->pos[0]; T reg20=nodes[1]->pos[0]+reg11; T reg21=nodes[2]->pos[0]+reg11; reg13=reg2+reg13; reg2=4*nodes[6]->pos[1];
    reg8=reg8-reg12; reg5=reg14+reg5; reg8=reg8-reg16; reg12=reg4-reg12; reg4=nodes[3]->pos[0]+reg11;
    reg3=reg5-reg3; reg5=2*nodes[7]->pos[2]; reg10=reg10-reg15; reg21=reg21-reg18; reg14=2*nodes[8]->pos[1];
    T reg22=2*nodes[5]->pos[0]; reg20=reg20-reg19; reg13=reg13-reg2; T reg23=2*nodes[7]->pos[1]; reg9=reg9-reg17;
    T reg24=2*nodes[8]->pos[2]; T reg25=4*nodes[6]->pos[0]; reg21=reg22+reg21; T reg26=2*nodes[6]->pos[0]; reg22=reg20+reg22;
    reg3=reg3-reg5; reg18=reg4-reg18; reg4=2*nodes[9]->pos[2]; reg8=reg8+reg14; reg9=reg9+reg24;
    reg5=reg10-reg5; reg13=reg13-reg23; reg10=2*nodes[9]->pos[1]; reg23=reg12-reg23; reg22=reg22-reg26;
    reg23=reg14+reg23; reg21=reg21-reg25; reg12=2*nodes[7]->pos[0]; reg3=reg24+reg3; reg14=4*nodes[7]->pos[0];
    reg8=reg10+reg8; reg26=reg18-reg26; reg10=reg13+reg10; reg5=reg4+reg5; reg4=reg9+reg4;
    reg9=reg8*reg3; reg26=reg26-reg14; reg13=reg4*reg23; reg18=2*nodes[9]->pos[0]; reg21=reg21-reg12;
    reg12=reg22-reg12; reg20=2*nodes[8]->pos[0]; reg4=reg10*reg4; reg8=reg5*reg8; reg3=reg10*reg3;
    reg23=reg5*reg23; reg26=reg20+reg26; reg20=reg12+reg20; reg8=reg4-reg8; reg9=reg13-reg9;
    reg21=reg21+reg18; reg8=reg20*reg8; reg9=reg21*reg9; reg26=reg18+reg26; reg3=reg23-reg3;
    reg9=reg8-reg9; reg3=reg26*reg3; T det_jac=reg9+reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[1],nodes[3],nodes[2],nodes[4],nodes[8],nodes[7],nodes[6],nodes[5],nodes[9]};
        for(unsigned i=0;i<10;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[2];
    T reg3=2*var_inter[1]; T reg4=reg1-1; T reg5=reg2-1; T reg6=reg3-1; T reg7=2*var_inter[0];
    reg1=reg1+reg4; reg3=reg3+reg6; reg2=reg2+reg5; T reg8=pos_nodes[2][2]*reg3; T reg9=4*var_inter[0];
    T reg10=pos_nodes[0][2]*reg1; T reg11=pos_nodes[0][0]*reg1; T reg12=pos_nodes[2][0]*reg3; T reg13=pos_nodes[3][1]*reg2; T reg14=pos_nodes[3][2]*reg2;
    T reg15=pos_nodes[2][1]*reg3; T reg16=pos_nodes[0][1]*reg1; T reg17=pos_nodes[3][0]*reg2; T reg18=reg7-1; T reg19=pos_nodes[4][0]*reg9;
    reg12=reg12-reg11; reg7=reg7+reg18; T reg20=4*var_inter[2]; reg14=reg14-reg10; reg18=reg18*var_inter[0];
    reg17=reg17-reg11; reg8=reg8-reg10; T reg21=pos_nodes[4][2]*reg9; T reg22=4*reg0; T reg23=4*var_inter[1];
    reg13=reg13-reg16; reg4=reg0*reg4; reg0=pos_nodes[4][1]*reg9; reg15=reg15-reg16; T reg24=reg22-reg23;
    reg13=reg13-reg0; reg12=reg12-reg19; T reg25=pos_nodes[1][0]*reg18; T reg26=pos_nodes[0][0]*reg4; T reg27=pos_nodes[1][1]*reg7;
    T reg28=pos_nodes[5][0]*reg9; T reg29=pos_nodes[6][1]*reg23; reg19=reg17-reg19; reg17=pos_nodes[5][1]*reg9; T reg30=reg22-reg20;
    reg0=reg15-reg0; reg14=reg14-reg21; reg15=pos_nodes[5][2]*reg9; reg21=reg8-reg21; reg8=pos_nodes[6][2]*reg23;
    reg6=var_inter[1]*reg6; T reg31=reg22-reg9; T reg32=pos_nodes[1][0]*reg7; T reg33=pos_nodes[1][1]*reg18; T reg34=reg4*pos_nodes[0][1];
    T reg35=pos_nodes[6][0]*reg23; reg13=reg13-reg29; T reg36=pos_nodes[1][2]*reg18; reg25=reg26+reg25; reg26=pos_nodes[2][0]*reg6;
    T reg37=pos_nodes[4][1]*reg31; T reg38=reg4*pos_nodes[0][2]; T reg39=pos_nodes[7][2]*reg30; reg16=reg27-reg16; reg14=reg14-reg8;
    reg27=pos_nodes[7][1]*reg30; T reg40=pos_nodes[6][2]*reg24; reg15=reg21+reg15; reg33=reg34+reg33; reg21=pos_nodes[2][1]*reg6;
    reg17=reg0+reg17; reg0=pos_nodes[6][1]*reg24; reg34=pos_nodes[1][2]*reg7; T reg41=pos_nodes[7][0]*reg30; reg28=reg12+reg28;
    reg12=pos_nodes[6][0]*reg24; T reg42=pos_nodes[4][0]*reg31; reg5=var_inter[2]*reg5; reg19=reg19-reg35; reg11=reg32-reg11;
    reg32=pos_nodes[5][1]*reg23; T reg43=reg22*var_inter[0]; reg11=reg42+reg11; reg42=pos_nodes[7][1]*reg20; T reg44=pos_nodes[7][2]*reg20;
    reg21=reg33+reg21; reg10=reg34-reg10; reg12=reg28+reg12; reg0=reg17+reg0; reg17=pos_nodes[4][2]*reg31;
    reg28=pos_nodes[3][1]*reg5; reg26=reg25+reg26; reg25=pos_nodes[3][0]*reg5; reg33=pos_nodes[2][2]*reg6; reg36=reg38+reg36;
    reg34=pos_nodes[8][1]*reg9; reg27=reg13+reg27; reg13=pos_nodes[8][2]*reg9; reg39=reg14+reg39; reg14=pos_nodes[5][0]*reg23;
    reg38=pos_nodes[7][0]*reg20; reg40=reg15+reg40; reg15=pos_nodes[8][0]*reg9; reg41=reg19+reg41; reg16=reg37+reg16;
    reg14=reg11+reg14; reg11=pos_nodes[4][1]*reg43; reg28=reg21+reg28; reg10=reg17+reg10; reg17=pos_nodes[5][2]*reg23;
    reg19=reg9*var_inter[1]; reg40=reg40-reg44; reg21=pos_nodes[9][2]*reg20; reg13=reg39+reg13; reg37=pos_nodes[9][2]*reg23;
    reg33=reg36+reg33; reg36=pos_nodes[3][2]*reg5; reg39=pos_nodes[9][1]*reg23; reg34=reg27+reg34; reg32=reg16+reg32;
    reg15=reg41+reg15; reg16=pos_nodes[9][0]*reg23; reg25=reg26+reg25; reg26=pos_nodes[9][1]*reg20; reg0=reg0-reg42;
    reg27=pos_nodes[4][0]*reg43; reg41=pos_nodes[9][0]*reg20; reg12=reg12-reg38; T reg45=pos_nodes[4][2]*reg43; reg37=reg13+reg37;
    reg41=reg12+reg41; reg17=reg10+reg17; reg21=reg40+reg21; reg29=reg32-reg29; reg10=reg22*var_inter[1];
    reg39=reg34+reg39; reg12=pos_nodes[5][0]*reg19; reg25=reg27+reg25; reg16=reg15+reg16; reg36=reg33+reg36;
    reg35=reg14-reg35; reg13=pos_nodes[5][1]*reg19; reg28=reg11+reg28; reg26=reg0+reg26; reg0=reg39*reg21;
    reg11=reg41*reg37; reg14=pos_nodes[5][2]*reg19; reg15=reg26*reg37; reg27=reg16*reg21; reg32=pos_nodes[6][0]*reg10;
    reg36=reg45+reg36; reg12=reg25+reg12; reg38=reg35-reg38; reg25=pos_nodes[6][1]*reg10; reg13=reg28+reg13;
    reg42=reg29-reg42; reg8=reg17-reg8; reg22=reg22*var_inter[2]; reg17=pos_nodes[8][0]*reg20; reg28=pos_nodes[8][1]*reg20;
    reg29=pos_nodes[7][1]*reg22; reg25=reg13+reg25; reg17=reg38+reg17; reg14=reg36+reg14; reg28=reg42+reg28;
    reg32=reg12+reg32; reg12=pos_nodes[7][0]*reg22; reg13=pos_nodes[6][2]*reg10; reg27=reg11-reg27; reg33=reg16*reg26;
    reg44=reg8-reg44; reg8=reg41*reg39; reg0=reg15-reg0; reg34=reg9*var_inter[2]; reg35=pos_nodes[8][2]*reg20;
    reg13=reg14+reg13; reg14=pos_nodes[7][2]*reg22; reg36=reg17*reg0; reg29=reg25+reg29; reg25=pos_nodes[8][1]*reg34;
    reg12=reg32+reg12; reg32=pos_nodes[8][0]*reg34; reg38=reg28*reg27; reg33=reg8-reg33; reg40=reg23*var_inter[2];
    reg35=reg44+reg35; reg42=reg28*reg21; reg44=reg39*reg35; reg45=reg28*reg37; T reg46=reg26*reg35;
    reg36=reg38-reg36; reg38=reg35*reg33; reg25=reg29+reg25; reg29=pos_nodes[9][1]*reg40; T reg47=reg41*reg35;
    T reg48=reg17*reg21; T reg49=pos_nodes[9][0]*reg40; reg32=reg12+reg32; reg14=reg13+reg14; reg12=pos_nodes[8][2]*reg34;
    reg13=reg16*reg35; T reg50=reg17*reg37; T reg51=reg41*reg28; reg13=reg50-reg13; T reg52=reg17*reg26;
    reg47=reg48-reg47; T reg53=reg17*reg39; reg44=reg45-reg44; T reg54=reg16*reg28; reg46=reg42-reg46;
    reg49=reg32+reg49; reg29=reg25+reg29; reg12=reg14+reg12; reg14=pos_nodes[9][2]*reg40; reg38=reg36-reg38;
    reg27=reg27/reg38; reg14=reg12+reg14; reg13=reg13/reg38; reg46=reg46/reg38; reg0=reg0/reg38;
    reg51=reg52-reg51; reg47=reg47/reg38; reg29=pos[1]-reg29; reg44=reg44/reg38; reg49=pos[0]-reg49;
    reg54=reg53-reg54; reg27=reg29*reg27; reg44=reg49*reg44; reg13=reg29*reg13; reg46=reg49*reg46;
    reg47=reg29*reg47; reg0=reg49*reg0; reg51=reg51/reg38; reg54=reg54/reg38; reg38=reg33/reg38;
    reg14=pos[2]-reg14; reg38=reg14*reg38; reg0=reg27-reg0; reg54=reg14*reg54; reg13=reg44-reg13;
    reg51=reg14*reg51; reg46=reg47-reg46; var_inter[0]=reg0-reg38; var_inter[1]=reg54+reg13; var_inter[2]=reg46-reg51;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[2]; T reg2=2*var_inter[1];
    T reg3=2*reg0; T reg4=reg3-1; T reg5=reg1-1; T reg6=reg2-1; reg1=reg1+reg5;
    T reg7=2*var_inter[0]; reg2=reg2+reg6; reg3=reg3+reg4; T reg8=pos_nodes[3][0]*reg1; T reg9=pos_nodes[3][2]*reg1;
    T reg10=pos_nodes[2][0]*reg2; T reg11=pos_nodes[2][2]*reg2; T reg12=reg7-1; T reg13=pos_nodes[2][1]*reg2; T reg14=pos_nodes[0][0]*reg3;
    T reg15=pos_nodes[0][2]*reg3; T reg16=pos_nodes[3][1]*reg1; T reg17=pos_nodes[0][1]*reg3; T reg18=4*var_inter[0]; T reg19=reg18*pos_nodes[4][1];
    reg13=reg13-reg17; T reg20=reg18*pos_nodes[4][2]; reg11=reg11-reg15; reg10=reg10-reg14; reg7=reg7+reg12;
    T reg21=reg18*pos_nodes[4][0]; T reg22=4*var_inter[2]; reg16=reg16-reg17; T reg23=4*var_inter[1]; reg9=reg9-reg15;
    T reg24=4*reg0; reg0=reg4*reg0; reg12=reg12*var_inter[0]; reg8=reg8-reg14; reg4=reg24-reg22;
    reg16=reg16-reg19; T reg25=reg23*pos_nodes[6][0]; reg10=reg10-reg21; T reg26=reg18*pos_nodes[5][0]; T reg27=reg18*pos_nodes[5][1];
    reg19=reg13-reg19; reg21=reg8-reg21; reg8=reg12*pos_nodes[1][0]; reg13=reg23*pos_nodes[6][1]; T reg28=pos_nodes[1][1]*reg7;
    T reg29=pos_nodes[0][0]*reg0; reg6=reg6*var_inter[1]; reg9=reg9-reg20; T reg30=reg18*pos_nodes[5][2]; reg20=reg11-reg20;
    reg11=reg23*pos_nodes[6][2]; T reg31=reg24-reg18; T reg32=reg24-reg23; T reg33=pos_nodes[1][0]*reg7; T reg34=reg12*pos_nodes[1][1];
    T reg35=reg0*pos_nodes[0][1]; reg17=reg28-reg17; reg28=pos_nodes[4][1]*reg31; reg9=reg9-reg11; T reg36=pos_nodes[7][2]*reg4;
    T reg37=reg6*pos_nodes[2][0]; T reg38=reg0*pos_nodes[0][2]; T reg39=reg12*pos_nodes[1][2]; T reg40=pos_nodes[6][2]*reg32; reg30=reg20+reg30;
    reg27=reg19+reg27; reg19=pos_nodes[6][1]*reg32; reg20=pos_nodes[1][2]*reg7; T reg41=reg6*pos_nodes[2][1]; reg34=reg35+reg34;
    reg16=reg16-reg13; reg35=pos_nodes[7][1]*reg4; reg5=var_inter[2]*reg5; reg14=reg33-reg14; reg33=pos_nodes[4][0]*reg31;
    reg26=reg10+reg26; reg10=pos_nodes[6][0]*reg32; reg21=reg21-reg25; T reg42=pos_nodes[7][0]*reg4; reg8=reg29+reg8;
    reg29=pos_nodes[7][1]*reg22; reg15=reg20-reg15; reg20=reg6*pos_nodes[2][2]; reg36=reg9+reg36; reg9=reg18*pos_nodes[8][2];
    reg10=reg26+reg10; reg26=reg24*var_inter[0]; reg19=reg27+reg19; reg27=reg5*pos_nodes[3][1]; reg39=reg38+reg39;
    reg41=reg34+reg41; reg34=pos_nodes[7][0]*reg22; reg33=reg14+reg33; reg35=reg16+reg35; reg14=reg18*pos_nodes[8][1];
    reg16=reg23*pos_nodes[5][0]; reg38=pos_nodes[4][2]*reg31; reg40=reg30+reg40; reg37=reg8+reg37; reg8=reg23*pos_nodes[5][1];
    reg28=reg17+reg28; reg17=reg5*pos_nodes[3][0]; reg42=reg21+reg42; reg21=reg18*pos_nodes[8][0]; reg30=pos_nodes[7][2]*reg22;
    reg16=reg33+reg16; reg33=reg26*pos_nodes[4][0]; reg40=reg40-reg30; T reg43=pos_nodes[9][2]*reg22; reg27=reg41+reg27;
    reg41=reg26*pos_nodes[4][1]; T reg44=reg18*var_inter[1]; T reg45=reg23*pos_nodes[9][2]; reg9=reg36+reg9; reg36=reg23*pos_nodes[5][2];
    reg17=reg37+reg17; reg38=reg15+reg38; reg20=reg39+reg20; reg15=reg23*pos_nodes[9][0]; reg21=reg42+reg21;
    reg37=reg5*pos_nodes[3][2]; reg8=reg28+reg8; reg28=pos_nodes[9][0]*reg22; reg10=reg10-reg34; reg19=reg19-reg29;
    reg39=pos_nodes[9][1]*reg22; reg42=reg23*pos_nodes[9][1]; reg14=reg35+reg14; reg42=reg14+reg42; reg25=reg16-reg25;
    reg43=reg40+reg43; reg36=reg38+reg36; reg15=reg21+reg15; reg13=reg8-reg13; reg37=reg20+reg37;
    reg8=reg24*var_inter[1]; reg14=reg26*pos_nodes[4][2]; reg28=reg10+reg28; reg39=reg19+reg39; reg45=reg9+reg45;
    reg9=reg44*pos_nodes[5][0]; reg33=reg17+reg33; reg10=reg44*pos_nodes[5][1]; reg41=reg27+reg41; reg16=reg28*reg45;
    reg17=reg15*reg43; reg19=reg42*reg43; reg20=reg39*reg45; reg14=reg37+reg14; reg21=reg44*pos_nodes[5][2];
    reg11=reg36-reg11; reg27=reg8*pos_nodes[6][0]; reg29=reg13-reg29; reg24=reg24*var_inter[2]; reg13=pos_nodes[8][1]*reg22;
    reg9=reg33+reg9; reg33=reg8*pos_nodes[6][1]; reg10=reg41+reg10; reg35=pos_nodes[8][0]*reg22; reg34=reg25-reg34;
    reg25=reg28*reg42; reg17=reg16-reg17; reg36=reg15*reg39; reg37=reg18*var_inter[2]; reg21=reg14+reg21;
    reg14=reg8*pos_nodes[6][2]; reg19=reg20-reg19; reg27=reg9+reg27; reg9=reg24*pos_nodes[7][0]; reg38=pos_nodes[8][2]*reg22;
    reg30=reg11-reg30; reg13=reg29+reg13; reg35=reg34+reg35; reg33=reg10+reg33; reg10=reg24*pos_nodes[7][1];
    reg11=reg24*pos_nodes[7][2]; reg14=reg21+reg14; reg9=reg27+reg9; reg21=reg37*pos_nodes[8][0]; reg36=reg25-reg36;
    reg10=reg33+reg10; reg27=reg37*pos_nodes[8][1]; reg29=reg23*var_inter[2]; reg38=reg30+reg38; reg30=reg13*reg17;
    reg33=reg35*reg19; reg34=reg13*reg45; reg40=reg42*reg38; reg41=reg13*reg43; T reg46=reg39*reg38;
    T reg47=reg35*reg45; T reg48=reg15*reg38; T reg49=reg38*reg36; T reg50=reg37*pos_nodes[8][2]; reg11=reg14+reg11;
    reg14=reg35*reg43; T reg51=reg28*reg38; reg33=reg30-reg33; reg30=reg29*pos_nodes[9][1]; reg27=reg10+reg27;
    reg21=reg9+reg21; reg9=reg29*pos_nodes[9][0]; reg48=reg47-reg48; reg51=reg14-reg51; reg46=reg41-reg46;
    reg10=reg35*reg42; T reg52=reg15*reg13; reg40=reg34-reg40; reg30=reg27+reg30; reg50=reg11+reg50;
    reg49=reg33-reg49; reg11=reg35*reg39; reg9=reg21+reg9; reg21=reg28*reg13; reg27=reg29*pos_nodes[9][2];
    reg51=reg51/reg49; reg52=reg10-reg52; reg21=reg11-reg21; reg48=reg48/reg49; reg17=reg17/reg49;
    reg46=reg46/reg49; reg30=pos[1]-reg30; reg40=reg40/reg49; reg19=reg19/reg49; reg9=pos[0]-reg9;
    reg27=reg50+reg27; reg46=reg9*reg46; reg48=reg30*reg48; reg51=reg30*reg51; reg40=reg9*reg40;
    reg17=reg30*reg17; reg19=reg9*reg19; reg21=reg21/reg49; reg52=reg52/reg49; reg49=reg36/reg49;
    reg27=pos[2]-reg27; reg49=reg27*reg49; reg19=reg17-reg19; reg52=reg27*reg52; reg48=reg40-reg48;
    reg21=reg27*reg21; reg46=reg51-reg46; var_inter[0]+=reg19-reg49; var_inter[1]+=reg52+reg48; var_inter[2]+=reg46-reg21;

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
    reg1=reg1-1; reg2=reg2-1; T reg3=2*var_inter[1]; T reg4=2*var_inter[2]; reg1=reg1*reg0;
    reg2=var_inter[0]*reg2; reg3=reg3-1; reg4=reg4-1; reg1=val[0]*reg1; reg3=var_inter[1]*reg3;
    reg2=val[1]*reg2; reg0=4*reg0; reg2=reg1+reg2; reg4=var_inter[2]*reg4; reg3=reg3*val[2];
    reg4=val[3]*reg4; reg1=var_inter[0]*reg0; T reg5=4*var_inter[0]; reg2=reg3+reg2; reg4=reg2+reg4;
    reg1=val[4]*reg1; reg2=var_inter[1]*reg5; reg3=var_inter[1]*reg0; reg1=reg4+reg1; reg2=val[5]*reg2;
    reg0=var_inter[2]*reg0; reg3=val[6]*reg3; reg2=reg1+reg2; reg1=4*var_inter[1]; reg5=var_inter[2]*reg5;
    reg0=val[7]*reg0; reg3=reg2+reg3; reg5=val[8]*reg5; reg1=var_inter[2]*reg1; reg0=reg3+reg0;
    reg5=reg0+reg5; reg1=val[9]*reg1; res=reg5+reg1;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[0]; T reg2=2*var_inter[2];
    T reg3=2*reg0; T reg4=2*var_inter[1]; reg1=reg1-1; reg4=reg4-1; T reg5=4*var_inter[1];
    T reg6=4*var_inter[0]; T reg7=4*reg0; reg2=reg2-1; reg3=reg3-1; T reg8=var_inter[0]*reg7;
    res[4]=reg8; T reg9=var_inter[1]*reg6; res[5]=reg9; T reg10=var_inter[1]*reg7; res[6]=reg10;
    reg7=var_inter[2]*reg7; res[7]=reg7; reg6=var_inter[2]*reg6; res[8]=reg6; reg5=var_inter[2]*reg5;
    res[9]=reg5; reg0=reg3*reg0; res[0]=reg0; reg2=var_inter[2]*reg2; res[3]=reg2;
    reg1=var_inter[0]*reg1; res[1]=reg1; reg4=var_inter[1]*reg4; res[2]=reg4;

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
