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
    T reg0=3*nodes[0]->pos[2]; T reg1=3*nodes[0]->pos[1]; T reg2=2*nodes[4]->pos[1]; T reg3=nodes[2]->pos[1]+reg1; T reg4=4*nodes[4]->pos[1];
    T reg5=4*nodes[4]->pos[2]; T reg6=nodes[1]->pos[1]+reg1; T reg7=nodes[1]->pos[2]+reg0; T reg8=nodes[3]->pos[2]+reg0; T reg9=2*nodes[4]->pos[2];
    T reg10=nodes[3]->pos[1]+reg1; T reg11=nodes[2]->pos[2]+reg0; reg8=reg8-reg9; reg10=reg10-reg2; T reg12=2*nodes[6]->pos[1];
    T reg13=2*nodes[5]->pos[1]; reg2=reg3-reg2; reg3=2*nodes[6]->pos[2]; T reg14=2*nodes[5]->pos[2]; reg9=reg11-reg9;
    reg7=reg7-reg5; reg11=3*nodes[0]->pos[0]; reg6=reg6-reg4; reg6=reg13+reg6; reg9=reg9+reg14;
    T reg15=4*nodes[6]->pos[2]; T reg16=4*nodes[7]->pos[2]; reg8=reg8-reg3; T reg17=2*nodes[4]->pos[0]; reg7=reg14+reg7;
    reg14=nodes[1]->pos[0]+reg11; T reg18=4*nodes[4]->pos[0]; T reg19=nodes[2]->pos[0]+reg11; reg13=reg2+reg13; reg2=4*nodes[6]->pos[1];
    T reg20=4*nodes[7]->pos[1]; reg10=reg10-reg12; reg10=reg10-reg20; T reg21=nodes[3]->pos[0]+reg11; reg3=reg7-reg3;
    reg12=reg6-reg12; reg6=2*nodes[7]->pos[2]; reg9=reg9-reg15; reg19=reg19-reg17; reg7=2*nodes[8]->pos[1];
    reg14=reg14-reg18; T reg22=2*nodes[5]->pos[0]; reg13=reg13-reg2; T reg23=2*nodes[7]->pos[1]; reg8=reg8-reg16;
    T reg24=2*nodes[8]->pos[2]; reg3=reg3-reg6; T reg25=4*nodes[6]->pos[0]; reg19=reg22+reg19; T reg26=2*nodes[6]->pos[0];
    reg22=reg14+reg22; reg14=2*nodes[9]->pos[2]; reg8=reg8+reg24; reg17=reg21-reg17; reg10=reg10+reg7;
    reg12=reg12-reg23; reg6=reg9-reg6; reg23=reg13-reg23; reg9=2*nodes[9]->pos[1]; reg8=reg8+reg14;
    reg22=reg22-reg26; reg12=reg7+reg12; reg19=reg19-reg25; reg7=2*nodes[7]->pos[0]; reg3=reg24+reg3;
    reg26=reg17-reg26; reg10=reg9+reg10; reg13=4*nodes[7]->pos[0]; reg9=reg23+reg9; reg6=reg14+reg6;
    reg14=reg10*reg3; reg26=reg26-reg13; reg17=reg8*reg12; reg21=2*nodes[9]->pos[0]; reg19=reg19-reg7;
    reg7=reg22-reg7; reg22=2*nodes[8]->pos[0]; reg8=reg9*reg8; reg10=reg6*reg10; reg3=reg9*reg3;
    reg12=reg6*reg12; reg26=reg22+reg26; reg22=reg7+reg22; reg10=reg8-reg10; reg14=reg17-reg14;
    reg19=reg19+reg21; reg10=reg22*reg10; reg14=reg19*reg14; reg26=reg21+reg26; reg3=reg12-reg3;
    reg14=reg10-reg14; reg3=reg26*reg3; T det_jac=reg14+reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[1],nodes[3],nodes[2],nodes[4],nodes[8],nodes[7],nodes[6],nodes[5],nodes[9]};
        for(unsigned i=0;i<10;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[1];
    T reg3=2*var_inter[2]; T reg4=reg2-1; T reg5=reg3-1; T reg6=reg1-1; reg1=reg6+reg1;
    reg3=reg3+reg5; reg2=reg2+reg4; T reg7=2*var_inter[0]; T reg8=pos_nodes[3][0]*reg3; T reg9=pos_nodes[2][2]*reg2;
    T reg10=reg7-1; T reg11=pos_nodes[3][2]*reg3; T reg12=pos_nodes[0][2]*reg1; T reg13=pos_nodes[2][1]*reg2; T reg14=pos_nodes[3][1]*reg3;
    T reg15=4*var_inter[0]; T reg16=pos_nodes[0][1]*reg1; T reg17=pos_nodes[2][0]*reg2; T reg18=pos_nodes[0][0]*reg1; reg14=reg14-reg16;
    T reg19=reg10*var_inter[0]; T reg20=pos_nodes[4][1]*reg15; T reg21=pos_nodes[4][2]*reg15; reg9=reg9-reg12; reg17=reg17-reg18;
    T reg22=4*var_inter[2]; T reg23=pos_nodes[4][0]*reg15; reg10=reg7+reg10; reg13=reg13-reg16; reg8=reg8-reg18;
    reg7=4*var_inter[1]; reg11=reg11-reg12; reg6=reg0*reg6; reg0=4*reg0; reg14=reg14-reg20;
    T reg24=reg0-reg22; T reg25=pos_nodes[1][1]*reg10; T reg26=reg7*pos_nodes[6][1]; reg8=reg8-reg23; reg23=reg17-reg23;
    reg17=pos_nodes[5][0]*reg15; T reg27=pos_nodes[5][1]*reg15; reg20=reg13-reg20; reg13=reg6*pos_nodes[0][0]; T reg28=pos_nodes[1][0]*reg19;
    reg11=reg11-reg21; reg4=reg4*var_inter[1]; T reg29=pos_nodes[5][2]*reg15; reg21=reg9-reg21; reg9=reg7*pos_nodes[6][2];
    T reg30=reg0-reg15; T reg31=reg0-reg7; T reg32=pos_nodes[1][0]*reg10; T reg33=reg6*pos_nodes[0][1]; T reg34=pos_nodes[1][1]*reg19;
    T reg35=reg7*pos_nodes[6][0]; T reg36=pos_nodes[7][1]*reg24; reg14=reg14-reg26; reg13=reg28+reg13; reg28=pos_nodes[0][2]*reg6;
    T reg37=pos_nodes[1][2]*reg19; reg16=reg25-reg16; reg25=pos_nodes[4][1]*reg30; T reg38=pos_nodes[7][2]*reg24; reg11=reg11-reg9;
    T reg39=pos_nodes[2][1]*reg4; T reg40=pos_nodes[6][2]*reg31; reg29=reg21+reg29; reg33=reg34+reg33; reg27=reg20+reg27;
    reg20=pos_nodes[6][1]*reg31; reg21=pos_nodes[1][2]*reg10; reg5=reg5*var_inter[2]; reg18=reg32-reg18; reg32=pos_nodes[4][0]*reg30;
    reg17=reg23+reg17; reg23=pos_nodes[6][0]*reg31; reg8=reg8-reg35; reg34=pos_nodes[7][0]*reg24; T reg41=pos_nodes[2][0]*reg4;
    reg38=reg11+reg38; reg23=reg17+reg23; reg20=reg27+reg20; reg11=pos_nodes[7][0]*reg22; reg36=reg14+reg36;
    reg14=reg15*pos_nodes[8][1]; reg17=pos_nodes[5][0]*reg7; reg32=reg18+reg32; reg33=reg39+reg33; reg18=pos_nodes[3][1]*reg5;
    reg40=reg29+reg40; reg13=reg41+reg13; reg27=pos_nodes[3][0]*reg5; reg12=reg21-reg12; reg21=pos_nodes[4][2]*reg30;
    reg29=pos_nodes[7][2]*reg22; reg39=reg15*pos_nodes[8][2]; reg41=pos_nodes[5][1]*reg7; reg25=reg16+reg25; reg34=reg8+reg34;
    reg28=reg37+reg28; reg8=reg0*var_inter[0]; reg16=pos_nodes[7][1]*reg22; reg37=pos_nodes[2][2]*reg4; T reg42=reg15*pos_nodes[8][0];
    reg17=reg32+reg17; reg32=pos_nodes[4][0]*reg8; reg18=reg33+reg18; reg33=pos_nodes[4][1]*reg8; T reg43=pos_nodes[9][2]*reg22;
    reg40=reg40-reg29; reg42=reg34+reg42; reg34=reg7*pos_nodes[9][0]; reg27=reg13+reg27; reg28=reg37+reg28;
    reg13=pos_nodes[3][2]*reg5; reg21=reg12+reg21; reg12=pos_nodes[5][2]*reg7; reg37=reg7*pos_nodes[9][1]; reg14=reg36+reg14;
    reg41=reg25+reg41; reg39=reg38+reg39; reg25=pos_nodes[9][0]*reg22; reg23=reg23-reg11; reg36=reg7*pos_nodes[9][2];
    reg38=reg15*var_inter[1]; reg20=reg20-reg16; T reg44=pos_nodes[9][1]*reg22; T reg45=pos_nodes[4][2]*reg8; reg12=reg21+reg12;
    reg25=reg23+reg25; reg13=reg28+reg13; reg21=pos_nodes[5][0]*reg38; reg32=reg27+reg32; reg34=reg42+reg34;
    reg44=reg20+reg44; reg20=reg0*var_inter[1]; reg43=reg40+reg43; reg23=pos_nodes[5][1]*reg38; reg33=reg18+reg33;
    reg26=reg41-reg26; reg35=reg17-reg35; reg36=reg39+reg36; reg37=reg14+reg37; reg45=reg13+reg45;
    reg0=reg0*var_inter[2]; reg13=pos_nodes[5][2]*reg38; reg14=pos_nodes[8][0]*reg22; reg11=reg35-reg11; reg23=reg33+reg23;
    reg17=reg20*pos_nodes[6][1]; reg21=reg32+reg21; reg18=pos_nodes[8][1]*reg22; reg16=reg26-reg16; reg26=reg20*pos_nodes[6][0];
    reg27=reg37*reg43; reg28=reg44*reg36; reg32=reg25*reg36; reg33=reg34*reg43; reg9=reg12-reg9;
    reg18=reg16+reg18; reg33=reg32-reg33; reg12=reg34*reg44; reg16=reg0*pos_nodes[7][0]; reg14=reg11+reg14;
    reg26=reg21+reg26; reg11=reg15*var_inter[2]; reg17=reg23+reg17; reg21=pos_nodes[7][1]*reg0; reg23=reg25*reg37;
    reg27=reg28-reg27; reg35=reg20*pos_nodes[6][2]; reg13=reg45+reg13; reg39=pos_nodes[8][2]*reg22; reg29=reg9-reg29;
    reg9=reg14*reg27; reg40=pos_nodes[7][2]*reg0; reg35=reg13+reg35; reg13=reg18*reg33; reg12=reg23-reg12;
    reg16=reg26+reg16; reg26=reg11*pos_nodes[8][0]; reg21=reg17+reg21; reg17=reg11*pos_nodes[8][1]; reg41=reg7*var_inter[2];
    reg39=reg29+reg39; reg29=reg18*reg43; reg42=reg37*reg39; reg45=reg18*reg36; T reg46=reg44*reg39;
    T reg47=reg39*reg12; reg9=reg13-reg9; reg26=reg16+reg26; reg13=reg41*pos_nodes[9][0]; reg16=reg14*reg36;
    reg17=reg21+reg17; reg21=reg41*pos_nodes[9][1]; T reg48=reg34*reg39; T reg49=reg14*reg43; T reg50=reg25*reg39;
    T reg51=reg11*pos_nodes[8][2]; reg40=reg35+reg40; reg35=reg14*reg44; reg46=reg29-reg46; reg48=reg16-reg48;
    T reg52=reg25*reg18; reg50=reg49-reg50; reg42=reg45-reg42; T reg53=reg14*reg37; T reg54=reg34*reg18;
    reg51=reg40+reg51; reg40=reg41*pos_nodes[9][2]; reg21=reg17+reg21; reg13=reg26+reg13; reg47=reg9-reg47;
    reg13=pos[0]-reg13; reg33=reg33/reg47; reg48=reg48/reg47; reg40=reg51+reg40; reg46=reg46/reg47;
    reg52=reg35-reg52; reg27=reg27/reg47; reg50=reg50/reg47; reg21=pos[1]-reg21; reg42=reg42/reg47;
    reg54=reg53-reg54; reg33=reg21*reg33; reg42=reg13*reg42; reg48=reg21*reg48; reg46=reg13*reg46;
    reg50=reg21*reg50; reg27=reg13*reg27; reg52=reg52/reg47; reg54=reg54/reg47; reg47=reg12/reg47;
    reg40=pos[2]-reg40; reg47=reg40*reg47; reg27=reg33-reg27; reg54=reg40*reg54; reg48=reg42-reg48;
    reg52=reg40*reg52; reg46=reg50-reg46; var_inter[0]=reg27-reg47; var_inter[1]=reg54+reg48; var_inter[2]=reg46-reg52;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[2];
    T reg3=2*var_inter[1]; T reg4=reg1-1; T reg5=reg2-1; T reg6=reg3-1; reg2=reg5+reg2;
    T reg7=2*var_inter[0]; reg1=reg1+reg4; reg3=reg3+reg6; T reg8=pos_nodes[3][2]*reg2; T reg9=reg7-1;
    T reg10=pos_nodes[3][0]*reg2; T reg11=pos_nodes[2][2]*reg3; T reg12=pos_nodes[0][2]*reg1; T reg13=pos_nodes[2][0]*reg3; T reg14=pos_nodes[0][1]*reg1;
    T reg15=pos_nodes[0][0]*reg1; T reg16=4*var_inter[0]; T reg17=pos_nodes[2][1]*reg3; T reg18=pos_nodes[3][1]*reg2; T reg19=4*var_inter[2];
    reg18=reg18-reg14; reg17=reg17-reg14; T reg20=pos_nodes[4][1]*reg16; T reg21=pos_nodes[4][2]*reg16; reg11=reg11-reg12;
    T reg22=pos_nodes[4][0]*reg16; reg7=reg7+reg9; reg13=reg13-reg15; reg9=reg9*var_inter[0]; T reg23=4*reg0;
    reg10=reg10-reg15; reg8=reg8-reg12; reg4=reg0*reg4; reg0=4*var_inter[1]; T reg24=pos_nodes[5][1]*reg16;
    T reg25=pos_nodes[1][1]*reg7; T reg26=pos_nodes[5][0]*reg16; reg10=reg10-reg22; reg22=reg13-reg22; reg13=pos_nodes[6][1]*reg0;
    reg17=reg17-reg20; T reg27=reg9*pos_nodes[1][0]; T reg28=reg23-reg0; T reg29=pos_nodes[0][0]*reg4; T reg30=reg23-reg19;
    reg20=reg18-reg20; reg18=pos_nodes[6][0]*reg0; T reg31=reg9*pos_nodes[1][1]; T reg32=pos_nodes[0][1]*reg4; reg8=reg8-reg21;
    T reg33=pos_nodes[1][0]*reg7; T reg34=reg23-reg16; reg6=reg6*var_inter[1]; T reg35=reg0*pos_nodes[6][2]; reg21=reg11-reg21;
    reg11=pos_nodes[5][2]*reg16; T reg36=pos_nodes[7][2]*reg30; T reg37=pos_nodes[1][2]*reg9; T reg38=pos_nodes[4][1]*reg34; reg14=reg25-reg14;
    reg25=pos_nodes[0][2]*reg4; T reg39=pos_nodes[2][0]*reg6; reg29=reg27+reg29; reg8=reg8-reg35; reg27=pos_nodes[6][2]*reg28;
    reg11=reg21+reg11; reg24=reg17+reg24; reg17=pos_nodes[6][1]*reg28; reg21=pos_nodes[1][2]*reg7; T reg40=pos_nodes[2][1]*reg6;
    reg32=reg31+reg32; reg31=pos_nodes[7][1]*reg30; reg20=reg20-reg13; T reg41=pos_nodes[4][0]*reg34; reg15=reg33-reg15;
    reg33=pos_nodes[7][0]*reg30; reg26=reg22+reg26; reg22=pos_nodes[6][0]*reg28; reg5=reg5*var_inter[2]; reg10=reg10-reg18;
    T reg42=pos_nodes[7][0]*reg19; reg17=reg24+reg17; reg31=reg20+reg31; reg20=reg16*pos_nodes[8][1]; reg24=pos_nodes[3][1]*reg5;
    T reg43=pos_nodes[5][0]*reg0; reg41=reg15+reg41; reg22=reg26+reg22; reg40=reg32+reg40; reg12=reg21-reg12;
    reg15=pos_nodes[4][2]*reg34; reg21=pos_nodes[7][2]*reg19; reg27=reg11+reg27; reg36=reg8+reg36; reg8=reg16*pos_nodes[8][2];
    reg11=reg23*var_inter[0]; reg25=reg37+reg25; reg26=pos_nodes[2][2]*reg6; reg38=reg14+reg38; reg14=pos_nodes[5][1]*reg0;
    reg33=reg10+reg33; reg10=pos_nodes[3][0]*reg5; reg32=pos_nodes[7][1]*reg19; reg37=reg16*pos_nodes[8][0]; reg39=reg29+reg39;
    reg8=reg36+reg8; reg43=reg41+reg43; reg37=reg33+reg37; reg29=reg0*pos_nodes[9][0]; reg40=reg24+reg40;
    reg24=pos_nodes[4][1]*reg11; reg33=pos_nodes[4][0]*reg11; reg36=reg16*var_inter[1]; reg41=pos_nodes[9][2]*reg19; reg27=reg27-reg21;
    T reg44=pos_nodes[5][2]*reg0; reg15=reg12+reg15; reg12=reg0*pos_nodes[9][1]; reg20=reg31+reg20; reg14=reg38+reg14;
    reg31=reg0*pos_nodes[9][2]; reg38=pos_nodes[3][2]*reg5; reg39=reg10+reg39; reg10=pos_nodes[9][0]*reg19; T reg45=pos_nodes[9][1]*reg19;
    reg17=reg17-reg32; reg26=reg25+reg26; reg22=reg22-reg42; reg25=pos_nodes[4][2]*reg11; reg44=reg15+reg44;
    reg15=pos_nodes[5][0]*reg36; reg26=reg38+reg26; reg41=reg27+reg41; reg27=reg23*var_inter[1]; reg33=reg39+reg33;
    reg29=reg37+reg29; reg31=reg8+reg31; reg45=reg17+reg45; reg10=reg22+reg10; reg13=reg14-reg13;
    reg18=reg43-reg18; reg12=reg20+reg12; reg24=reg40+reg24; reg8=pos_nodes[5][1]*reg36; reg14=reg27*pos_nodes[6][0];
    reg15=reg33+reg15; reg25=reg26+reg25; reg23=reg23*var_inter[2]; reg17=pos_nodes[6][1]*reg27; reg8=reg24+reg8;
    reg42=reg18-reg42; reg18=pos_nodes[8][0]*reg19; reg32=reg13-reg32; reg13=pos_nodes[8][1]*reg19; reg20=reg45*reg31;
    reg22=pos_nodes[5][2]*reg36; reg24=reg12*reg41; reg26=reg29*reg41; reg33=reg10*reg31; reg35=reg44-reg35;
    reg18=reg42+reg18; reg37=reg29*reg45; reg26=reg33-reg26; reg38=reg10*reg12; reg21=reg35-reg21;
    reg35=pos_nodes[8][2]*reg19; reg39=reg16*var_inter[2]; reg13=reg32+reg13; reg17=reg8+reg17; reg8=pos_nodes[7][1]*reg23;
    reg32=reg27*pos_nodes[6][2]; reg24=reg20-reg24; reg22=reg25+reg22; reg14=reg15+reg14; reg15=reg23*pos_nodes[7][0];
    reg32=reg22+reg32; reg22=pos_nodes[7][2]*reg23; reg25=reg18*reg24; reg40=var_inter[2]*reg0; reg8=reg17+reg8;
    reg17=reg39*pos_nodes[8][1]; reg15=reg14+reg15; reg14=reg39*pos_nodes[8][0]; reg35=reg21+reg35; reg21=reg13*reg26;
    reg37=reg38-reg37; reg42=reg12*reg35; reg25=reg21-reg25; reg21=reg35*reg37; reg43=reg13*reg31;
    reg44=reg13*reg41; T reg46=reg45*reg35; T reg47=reg39*pos_nodes[8][2]; reg22=reg32+reg22; reg14=reg15+reg14;
    reg17=reg8+reg17; reg8=reg40*pos_nodes[9][1]; reg15=reg18*reg31; reg32=reg40*pos_nodes[9][0]; T reg48=reg10*reg35;
    T reg49=reg29*reg35; T reg50=reg18*reg41; reg42=reg43-reg42; reg48=reg50-reg48; reg46=reg44-reg46;
    reg49=reg15-reg49; reg21=reg25-reg21; reg25=reg18*reg12; T reg51=reg29*reg13; T reg52=reg18*reg45;
    T reg53=reg40*pos_nodes[9][2]; reg47=reg22+reg47; reg8=reg17+reg8; reg32=reg14+reg32; reg14=reg10*reg13;
    reg48=reg48/reg21; reg51=reg25-reg51; reg14=reg52-reg14; reg8=pos[1]-reg8; reg32=pos[0]-reg32;
    reg53=reg47+reg53; reg24=reg24/reg21; reg42=reg42/reg21; reg46=reg46/reg21; reg26=reg26/reg21;
    reg49=reg49/reg21; reg53=pos[2]-reg53; reg37=reg37/reg21; reg51=reg51/reg21; reg21=reg14/reg21;
    reg24=reg32*reg24; reg26=reg8*reg26; reg48=reg8*reg48; reg42=reg32*reg42; reg49=reg8*reg49;
    reg46=reg32*reg46; reg46=reg48-reg46; reg21=reg53*reg21; reg49=reg42-reg49; reg51=reg53*reg51;
    reg24=reg26-reg24; reg37=reg53*reg37; var_inter[1]+=reg51+reg49; var_inter[0]+=reg24-reg37; var_inter[2]+=reg46-reg21;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[0]; T reg2=2*reg0;
    T reg3=2*var_inter[1]; reg1=reg1-1; reg2=reg2-1; T reg4=2*var_inter[2]; reg3=reg3-1;
    reg1=var_inter[0]*reg1; reg2=reg2*reg0; reg4=reg4-1; reg3=var_inter[1]*reg3; reg1=val[1]*reg1;
    reg2=val[0]*reg2; reg4=var_inter[2]*reg4; reg3=val[2]*reg3; reg1=reg2+reg1; reg0=4*reg0;
    reg3=reg1+reg3; reg1=var_inter[0]*reg0; reg4=val[3]*reg4; reg2=4*var_inter[0]; T reg5=var_inter[1]*reg2;
    reg4=reg3+reg4; reg1=val[4]*reg1; reg3=var_inter[1]*reg0; reg5=val[5]*reg5; reg1=reg4+reg1;
    reg5=reg1+reg5; reg3=val[6]*reg3; reg0=var_inter[2]*reg0; reg1=4*var_inter[1]; reg2=var_inter[2]*reg2;
    reg0=val[7]*reg0; reg3=reg5+reg3; reg0=reg3+reg0; reg2=val[8]*reg2; reg1=var_inter[2]*reg1;
    reg2=reg0+reg2; reg1=val[9]*reg1; res=reg2+reg1;

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
    T reg0=var_inter[0]-0.5; T reg1=var_inter[0]-0.16666666666666666667; T reg2=var_inter[0]-0.25; T reg3=reg2*reg0; reg0=reg1*reg0;
    reg3=reg3/0.027777777777777777774; T reg4=var_inter[1]-0.25; reg0=reg0/0.020833333333333333332; T reg5=var_inter[1]-0.16666666666666666667; reg1=reg2*reg1;
    reg1=reg1/0.083333333333333333329; reg3=reg4*reg3; T reg6=var_inter[1]-0.5; reg0=reg0*reg5; reg1=reg4*reg1;
    T reg7=reg6*reg3; reg0=reg6*reg0; reg7=reg7/0.027777777777777777774; T reg8=var_inter[2]-0.16666666666666666667; reg0=reg0/0.020833333333333333332;
    T reg9=var_inter[2]-0.25; reg1=reg6*reg1; reg6=var_inter[2]-0.5; reg7=reg9*reg7; T reg10=reg0*reg8;
    reg3=reg5*reg3; reg1=reg1/0.027777777777777777774; reg5=reg6*reg7; reg1=reg9*reg1; reg10=reg10*reg6;
    reg3=reg3/0.083333333333333333329; reg10=reg10/0.020833333333333333332; reg5=reg5/0.027777777777777777774; reg1=reg6*reg1; reg3=reg9*reg3;
    reg1=reg1/0.027777777777777777774; reg3=reg6*reg3; reg5=val[1]*reg5; reg10=val[0]*reg10; reg10=reg5-reg10;
    reg1=val[2]*reg1; reg3=reg3/0.027777777777777777774; reg7=reg8*reg7; reg1=reg10+reg1; reg3=val[3]*reg3;
    reg7=reg7/0.083333333333333333329; reg3=reg1+reg3; reg7=val[4]*reg7; res=reg3+reg7;

}
#ifndef STRUCT_Gauss_2
#define STRUCT_Gauss_2
struct Gauss_2 {};
#endif // STRUCT_Gauss_2
template<class TVI,class TVAL,class T> void get_interp(const Tetra_10 &ne,const Gauss_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=var_inter[0]-0.13819660112501051517; T reg1=var_inter[0]-0.58541019662496845445; reg0=reg0/0.44721359549995793928; reg1=reg1/0.44721359549995793928; T reg2=var_inter[1]-0.58541019662496845445;
    T reg3=var_inter[1]-0.13819660112501051517; reg0=reg2*reg0; reg2=reg1*reg2; reg2=reg2/0.44721359549995793928; T reg4=var_inter[2]-0.58541019662496845445;
    reg0=reg0/0.44721359549995793928; reg3=reg1*reg3; reg1=reg2*reg4; reg3=reg3/0.44721359549995793928; reg0=reg4*reg0;
    reg1=reg1/0.44721359549995793928; T reg5=var_inter[2]-0.13819660112501051517; reg0=reg0/0.44721359549995793928; reg3=reg4*reg3; reg3=reg3/0.44721359549995793928;
    reg5=reg2*reg5; reg4=val[1]*reg0; reg1=val[0]*reg1; reg1=reg4-reg1; reg4=val[2]*reg3;
    reg5=reg5/0.44721359549995793928; reg4=reg1+reg4; reg5=val[3]*reg5; res=reg4+reg5;

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
    T reg3=2*var_inter[0]; T reg4=2*var_inter[1]; T reg5=4*var_inter[0]; reg2=reg2-1; reg4=reg4-1;
    reg3=reg3-1; T reg6=4*var_inter[1]; T reg7=4*reg0; reg1=reg1-1; T reg8=var_inter[2]*reg5;
    res[8]=reg8; T reg9=var_inter[2]*reg7; res[7]=reg9; reg6=var_inter[2]*reg6; res[9]=reg6;
    T reg10=var_inter[1]*reg7; res[6]=reg10; reg5=var_inter[1]*reg5; res[5]=reg5; reg2=var_inter[2]*reg2;
    res[3]=reg2; reg4=var_inter[1]*reg4; res[2]=reg4; reg3=var_inter[0]*reg3; res[1]=reg3;
    reg0=reg1*reg0; res[0]=reg0; reg7=var_inter[0]*reg7; res[4]=reg7;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[2];
    T reg3=2*var_inter[1]; T reg4=2*var_inter[0]; T reg5=reg2-1; T reg6=reg3-1; T reg7=reg4-1;
    T reg8=reg1-1; T reg9=4*var_inter[0]; reg1=reg1+reg8; reg4=reg4+reg7; reg3=reg3+reg6;
    reg2=reg2+reg5; T reg10=4*reg0; T reg11=elem.pos(1)[2]*reg4; T reg12=elem.pos(0)[1]*reg1; T reg13=elem.pos(2)[2]*reg3;
    T reg14=elem.pos(2)[1]*reg3; T reg15=elem.pos(3)[1]*reg2; T reg16=elem.pos(1)[1]*reg4; T reg17=elem.pos(0)[2]*reg1; T reg18=reg10-reg9;
    T reg19=elem.pos(3)[2]*reg2; T reg20=4*var_inter[1]; reg16=reg16-reg12; reg13=reg13-reg17; T reg21=elem.pos(4)[2]*reg9;
    T reg22=elem.pos(4)[1]*reg9; T reg23=elem.pos(4)[2]*reg18; reg11=reg11-reg17; reg15=reg15-reg12; reg14=reg14-reg12;
    reg19=reg19-reg17; T reg24=elem.pos(4)[1]*reg18; T reg25=4*var_inter[2]; T reg26=elem.pos(6)[1]*reg20; reg13=reg13-reg21;
    reg15=reg15-reg22; T reg27=elem.pos(6)[2]*reg20; reg23=reg11+reg23; reg11=elem.pos(5)[2]*reg9; T reg28=elem.pos(5)[1]*reg20;
    reg3=elem.pos(2)[0]*reg3; T reg29=reg10-reg20; T reg30=reg10-reg25; reg19=reg19-reg21; T reg31=elem.pos(5)[1]*reg9;
    reg14=reg14-reg22; reg24=reg16+reg24; reg16=elem.pos(0)[0]*reg1; reg4=elem.pos(1)[0]*reg4; T reg32=elem.pos(5)[2]*reg20;
    reg15=reg15-reg26; T reg33=elem.pos(4)[0]*reg9; T reg34=elem.pos(6)[2]*reg29; reg13=reg11+reg13; reg19=reg19-reg27;
    reg31=reg14+reg31; reg3=reg3-reg16; reg11=elem.pos(7)[2]*reg30; reg14=elem.pos(6)[1]*reg29; reg28=reg24+reg28;
    reg18=elem.pos(4)[0]*reg18; reg4=reg4-reg16; reg32=reg23+reg32; reg2=elem.pos(3)[0]*reg2; reg23=elem.pos(7)[1]*reg30;
    reg18=reg4+reg18; reg11=reg19+reg11; reg34=reg13+reg34; reg4=elem.pos(8)[1]*reg9; reg2=reg2-reg16;
    reg13=elem.pos(7)[1]*reg25; reg32=reg32-reg27; reg28=reg28-reg26; reg23=reg15+reg23; reg3=reg3-reg33;
    reg14=reg31+reg14; reg15=elem.pos(5)[0]*reg20; reg19=elem.pos(8)[2]*reg9; reg24=elem.pos(7)[2]*reg25; reg31=elem.pos(5)[0]*reg9;
    T reg35=elem.pos(9)[1]*reg25; reg28=reg28-reg13; reg34=reg34-reg24; T reg36=elem.pos(9)[1]*reg20; reg29=elem.pos(6)[0]*reg29;
    reg14=reg14-reg13; T reg37=elem.pos(6)[0]*reg20; T reg38=elem.pos(8)[2]*reg25; reg2=reg2-reg33; reg15=reg18+reg15;
    reg18=elem.pos(9)[2]*reg20; reg31=reg3+reg31; reg19=reg11+reg19; reg3=elem.pos(9)[2]*reg25; reg11=elem.pos(8)[1]*reg25;
    reg4=reg23+reg4; reg32=reg32-reg24; reg15=reg15-reg37; reg36=reg4+reg36; reg34=reg3+reg34;
    reg30=elem.pos(7)[0]*reg30; reg2=reg2-reg37; reg29=reg31+reg29; reg35=reg14+reg35; reg28=reg11+reg28;
    reg3=elem.pos(7)[0]*reg25; reg19=reg18+reg19; reg32=reg38+reg32; reg4=elem.pos(8)[0]*reg9; reg11=reg32*reg36;
    reg2=reg30+reg2; reg14=reg19*reg35; reg18=elem.pos(8)[0]*reg25; reg23=reg36*reg34; reg30=reg19*reg28;
    reg15=reg15-reg3; reg29=reg29-reg3; reg31=elem.pos(9)[0]*reg25; reg38=elem.pos(9)[0]*reg20; reg23=reg14-reg23;
    reg11=reg30-reg11; reg14=reg28*reg34; reg4=reg2+reg4; reg15=reg18+reg15; reg31=reg29+reg31;
    reg2=reg32*reg35; reg18=reg31*reg11; reg2=reg14-reg2; reg38=reg4+reg38; reg4=reg15*reg23;
    reg14=reg2*reg38; reg18=reg4-reg18; reg14=reg18+reg14; return reg14;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Tetra_10,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=4*elem.pos(6)[1]; T reg1=4*elem.pos(0)[1]; T reg2=4*elem.pos(4)[1]; T reg3=4*elem.pos(0)[2]; T reg4=4*elem.pos(4)[2];
    T reg5=4*elem.pos(6)[2]; T reg6=reg1-reg2; T reg7=4*elem.pos(2)[1]; T reg8=reg5-reg3; T reg9=reg1-reg0;
    T reg10=4*elem.pos(7)[1]; T reg11=4*elem.pos(1)[2]; T reg12=3*elem.pos(0)[2]; T reg13=4*elem.pos(3)[2]; T reg14=3*elem.pos(0)[1];
    T reg15=reg3-reg5; T reg16=4*elem.pos(7)[2]; T reg17=4*elem.pos(3)[1]; T reg18=reg4-reg3; T reg19=4*elem.pos(5)[2];
    T reg20=reg2-reg1; T reg21=4*elem.pos(5)[1]; T reg22=reg0-reg1; T reg23=4*elem.pos(1)[1]; T reg24=4*elem.pos(2)[2];
    T reg25=reg3-reg4; T reg26=reg16+reg18; reg17=reg1+reg17; T reg27=8*elem.pos(7)[1]; reg18=reg19-reg18;
    T reg28=reg21-reg20; T reg29=8*elem.pos(4)[2]; reg11=reg3+reg11; T reg30=elem.pos(3)[1]+reg14; reg20=reg10+reg20;
    T reg31=reg25-reg16; T reg32=elem.pos(1)[1]+reg14; T reg33=elem.pos(1)[2]+reg12; T reg34=8*elem.pos(4)[1]; reg23=reg1+reg23;
    T reg35=4*elem.pos(8)[1]; T reg36=4*elem.pos(8)[2]; T reg37=reg6-reg10; reg19=reg25+reg19; reg7=reg1+reg7;
    reg21=reg6+reg21; reg22=reg10+reg22; reg24=reg3+reg24; reg6=8*elem.pos(6)[2]; reg8=reg16+reg8;
    reg25=8*elem.pos(6)[1]; T reg38=elem.pos(2)[2]+reg12; reg12=elem.pos(3)[2]+reg12; reg14=elem.pos(2)[1]+reg14; reg9=reg9-reg10;
    T reg39=4*elem.pos(9)[2]; T reg40=4*elem.pos(9)[1]; reg13=reg13+reg3; T reg41=8*elem.pos(7)[2]; reg15=reg15-reg16;
    reg19=reg19-reg5; reg21=reg21-reg0; reg18=reg18-reg5; T reg42=reg40-reg22; T reg43=reg0-reg14;
    reg24=reg24-reg6; T reg44=reg35-reg20; reg11=reg11-reg29; T reg45=reg39-reg8; reg23=reg23-reg34;
    T reg46=reg5-reg38; reg12=reg16-reg12; reg7=reg7-reg25; T reg47=4*elem.pos(0)[0]; T reg48=4*elem.pos(4)[0];
    reg40=reg9+reg40; reg13=reg13-reg41; reg39=reg15+reg39; reg17=reg17-reg27; reg9=reg36-reg26;
    reg28=reg28-reg0; reg36=reg31+reg36; reg35=reg37+reg35; reg15=reg4-reg33; reg31=reg2-reg32;
    reg30=reg10-reg30; reg37=reg17*reg19; T reg49=reg35*reg45; T reg50=reg13*reg21; T reg51=reg9*reg23;
    T reg52=reg48-reg47; T reg53=reg18*reg44; T reg54=reg28*reg9; T reg55=reg42*reg15; T reg56=reg19*reg30;
    T reg57=reg45*reg31; T reg58=reg12*reg21; T reg59=reg24*reg30; T reg60=reg39*reg42; T reg61=reg17*reg24;
    T reg62=reg40*reg45; T reg63=reg7*reg13; T reg64=reg46*reg42; T reg65=4*elem.pos(1)[0]; T reg66=reg7*reg12;
    T reg67=reg43*reg45; T reg68=reg17*reg46; T reg69=reg39*reg30; T reg70=reg13*reg31; T reg71=reg13*reg28;
    T reg72=reg40*reg9; T reg73=reg17*reg18; T reg74=reg39*reg44; T reg75=reg13*reg23; T reg76=reg35*reg9;
    T reg77=reg17*reg11; T reg78=reg36*reg44; T reg79=reg45*reg28; T reg80=reg7*reg9; T reg81=reg42*reg18;
    T reg82=reg24*reg44; T reg83=reg21*reg9; T reg84=reg45*reg23; T reg85=reg19*reg44; T reg86=reg42*reg11;
    T reg87=reg40*reg12; T reg88=reg13*reg43; T reg89=reg35*reg12; T reg90=reg17*reg15; T reg91=reg36*reg42;
    T reg92=reg36*reg30; T reg93=reg44*reg11; T reg94=4*elem.pos(6)[0]; T reg95=reg15*reg44; T reg96=reg30*reg11;
    T reg97=reg31*reg9; T reg98=reg12*reg23; T reg99=reg30*reg18; T reg100=reg46*reg44; T reg101=reg47-reg48;
    T reg102=4*elem.pos(5)[0]; T reg103=3*elem.pos(0)[0]; T reg104=4*elem.pos(2)[0]; T reg105=reg43*reg9; T reg106=reg12*reg28;
    T reg107=reg43*reg11; T reg108=reg31*reg18; T reg109=reg46*reg23; T reg110=reg15*reg28; T reg111=reg102-reg52;
    T reg112=reg17*reg36; reg95=reg96+reg95; reg96=reg13*reg35; T reg113=elem.pos(1)[0]+reg103; reg84=reg83+reg84;
    reg97=reg98+reg97; reg72=reg71+reg72; reg82=reg81+reg82; reg74=reg73+reg74; reg99=reg100+reg99;
    reg76=reg75+reg76; reg78=reg77+reg78; reg71=reg39*reg23; reg73=reg35*reg18; reg80=reg79+reg80;
    reg75=reg40*reg11; reg77=reg36*reg28; reg106=reg105+reg106; reg66=reg67+reg66; reg59=reg64+reg59;
    reg57=reg58+reg57; reg55=reg56+reg55; reg56=reg46*reg21; reg58=reg24*reg31; reg64=reg43*reg19;
    reg67=reg7*reg15; reg54=2*reg54; reg53=2*reg53; reg51=2*reg51; reg79=4*elem.pos(7)[0];
    reg93=2*reg93; reg81=reg18*reg23; reg83=reg28*reg11; reg98=reg36*reg43; reg100=reg40*reg15;
    reg105=reg35*reg46; T reg114=reg39*reg31; reg92=reg90+reg92; reg89=reg70+reg89; reg69=reg68+reg69;
    reg68=reg47-reg94; reg87=reg88+reg87; reg70=elem.pos(2)[0]+reg103; reg88=reg40*reg13; reg90=reg39*reg17;
    reg65=reg47+reg65; T reg115=8*elem.pos(4)[0]; T reg116=reg94-reg47; reg104=reg47+reg104; reg62=reg63+reg62;
    reg63=8*elem.pos(6)[0]; reg60=reg61+reg60; reg102=reg101+reg102; reg49=reg50+reg49; reg91=reg37+reg91;
    reg37=reg39*reg21; reg50=reg35*reg24; reg61=reg40*reg19; T reg117=reg7*reg36; T reg118=reg7*reg45;
    T reg119=reg24*reg42; T reg120=reg45*reg21; T reg121=reg42*reg19; T reg122=reg7*reg11; T reg123=reg19*reg28;
    T reg124=reg24*reg23; T reg125=reg21*reg18; reg86=reg85+reg86; reg103=elem.pos(3)[0]+reg103; reg82=reg80-reg82;
    reg67=reg64+reg67; reg64=4*elem.pos(3)[0]; reg110=reg107+reg110; reg80=reg94-reg70; reg102=reg102-reg94;
    reg58=reg56+reg58; reg60=reg62-reg60; reg88=2*reg88; reg77=reg75+reg77; reg55=reg57-reg55;
    reg86=reg84-reg86; reg65=reg65-reg115; reg90=2*reg90; reg56=reg48-reg113; reg96=2*reg96;
    reg93=reg51-reg93; reg122=reg123+reg122; reg81=2*reg81; reg117=reg61+reg117; reg83=2*reg83;
    reg98=reg100+reg98; reg50=reg37+reg50; reg105=reg114+reg105; reg53=reg54-reg53; reg91=reg49-reg91;
    reg124=reg125+reg124; reg92=reg89-reg92; reg101=reg101-reg79; reg37=4*elem.pos(8)[0]; reg69=reg87-reg69;
    reg68=reg68-reg79; reg49=4*elem.pos(9)[0]; reg51=reg7*reg19; reg73=reg71+reg73; reg54=reg24*reg21;
    reg78=reg76-reg78; reg121=2*reg121; reg116=reg79+reg116; reg120=2*reg120; reg99=reg106-reg99;
    reg74=reg72-reg74; reg119=2*reg119; reg118=2*reg118; reg52=reg79+reg52; reg95=reg97-reg95;
    reg104=reg104-reg63; reg108=reg109+reg108; reg59=reg66-reg59; reg112=2*reg112; reg57=reg39*reg35;
    reg111=reg111-reg94; reg61=reg40*reg36; reg122=reg124-reg122; reg62=reg111*reg95; reg66=reg104*reg92;
    reg71=reg65*reg53; reg72=reg56*reg53; reg101=reg101+reg37; reg75=reg65*reg99; reg51=2*reg51;
    reg119=reg118-reg119; reg61=2*reg61; reg76=reg111*reg78; reg110=reg108-reg110; reg84=reg49-reg116;
    reg85=reg80*reg78; reg77=reg73-reg77; reg57=2*reg57; reg117=reg50-reg117; reg90=reg88-reg90;
    reg98=reg105-reg98; reg50=reg65*reg74; reg83=reg81-reg83; reg121=reg120-reg121; reg112=reg96-reg112;
    reg54=2*reg54; reg73=reg80*reg86; reg81=reg111*reg93; reg87=reg104*reg78; reg88=reg55*reg111;
    reg89=reg80*reg93; reg96=reg91*reg111; reg97=reg59*reg65; reg100=reg56*reg82; reg105=8*elem.pos(7)[0];
    reg106=reg92*reg111; reg64=reg47+reg64; reg107=reg69*reg65; reg108=reg102*reg74; reg67=reg58-reg67;
    reg58=reg111*reg86; reg109=reg56*reg74; reg114=reg91*reg80; reg118=reg60*reg65; reg49=reg68+reg49;
    reg68=reg102*reg69; reg120=reg56*reg60; reg123=reg65*reg82; reg103=reg79-reg103; reg37=reg37-reg52;
    reg107=reg109+reg107; reg109=reg84*reg98; reg68=reg120+reg68; reg120=reg117*reg103; reg124=reg49*reg55;
    reg66=reg114+reg66; reg114=reg101*reg59; reg106=reg85+reg106; reg85=reg101*reg99; reg125=reg37*reg110;
    reg88=reg73+reg88; reg73=reg121*reg111; T reg126=reg102*reg99; reg97=reg100+reg97; reg100=reg67*reg37;
    T reg127=reg103*reg122; T reg128=reg104*reg86; T reg129=reg119*reg65; T reg130=reg102*reg82; T reg131=reg84*reg77;
    T reg132=reg117*reg37; T reg133=reg49*reg86; reg87=reg96+reg87; reg96=reg101*reg82; reg108=reg118+reg108;
    reg118=reg112*reg111; T reg134=reg49*reg78; T reg135=reg90*reg65; T reg136=reg101*reg74; T reg137=reg49*reg95;
    T reg138=reg103*reg77; T reg139=reg98*reg37; reg50=2*reg50; T reg140=reg101*reg53; reg76=2*reg76;
    T reg141=reg103*reg83; T reg142=reg49*reg93; T reg143=reg102*reg59; T reg144=reg56*reg119; reg72=reg75+reg72;
    reg89=reg89+reg62; T reg145=reg104*reg55; T reg146=reg121*reg80; T reg147=reg37*reg77; T reg148=reg37*reg122;
    reg123=2*reg123; T reg149=reg102*reg53; reg58=2*reg58; T reg150=reg104*reg93; T reg151=reg104*reg95;
    reg61=reg57-reg61; reg57=reg30*reg15; T reg152=reg46*reg30; reg51=reg54-reg51; reg64=reg64-reg105;
    reg54=reg101*reg69; T reg153=reg90*reg56; T reg154=2*reg71; T reg155=reg43*reg12; T reg156=reg37*reg83;
    T reg157=reg49*reg92; T reg158=reg12*reg31; T reg159=reg112*reg80; T reg160=2*reg81; T reg161=reg43*reg15;
    reg152=reg155-reg152; reg155=reg46*reg31; reg126=reg97+reg126; reg97=reg84*reg110; reg100=reg127+reg100;
    reg127=reg84*reg83; reg153=reg54+reg153; reg129=reg130+reg129; T reg162=reg61*reg37; T reg163=reg64*reg77;
    reg73=reg128+reg73; T reg164=reg64*reg67; reg109=reg120+reg109; reg159=reg157+reg159; reg57=reg158-reg57;
    reg120=reg90*reg102; reg139=reg138+reg139; reg138=reg51*reg103; reg158=reg84*reg67; T reg165=reg64*reg110;
    reg146=reg145+reg146; reg144=reg143+reg144; reg142=reg76+reg142; reg96=reg108+reg96; reg149=reg123+reg149;
    reg140=reg50+reg140; reg133=reg87+reg133; reg50=reg102*reg60; reg150=reg58+reg150; reg131=reg132+reg131;
    reg137=reg106+reg137; reg58=reg104*reg91; reg76=reg101*reg60; reg87=reg64*reg122; reg85=reg107+reg85;
    reg151=reg88+reg151; reg88=reg64*reg83; reg135=reg136+reg135; reg106=reg49*reg91; reg107=2*reg156;
    reg160=reg81+reg160; reg81=reg102*reg119; reg108=reg51*reg37; reg118=reg134+reg118; reg123=reg84*reg122;
    reg147=2*reg147; reg132=reg104*reg121; reg154=reg71+reg154; reg124=reg66+reg124; reg141=reg141+reg125;
    reg66=reg112*reg104; reg114=reg68+reg114; reg89=reg62+reg89; reg148=2*reg148; reg62=reg61*reg103;
    reg68=reg64*reg98; reg72=reg75+reg72; reg59=reg56*reg59; reg71=reg102*reg152; reg133=reg96-reg133;
    reg55=reg80*reg55; reg58=2*reg58; reg161=reg155-reg161; reg141=reg125+reg141; reg75=reg101*reg90;
    reg50=2*reg50; reg96=reg101*reg119; reg120=reg76+reg120; reg125=reg84*reg51; reg138=reg158+reg138;
    reg66=reg106+reg66; reg146=reg145+reg146; reg145=2*reg132; reg137=reg85-reg137; reg165=reg139+reg165;
    reg144=reg143+reg144; reg69=reg56*reg69; reg85=reg101*reg152; reg142=reg140-reg142; reg89=reg72-reg89;
    reg72=reg64*reg117; reg92=reg80*reg92; reg139=reg49*reg57; reg140=2*reg81; reg62=reg68+reg62;
    reg143=reg57*reg111; reg153=reg54+reg153; reg95=reg80*reg95; reg54=reg61*reg84; reg150=reg149-reg150;
    reg129=reg130+reg129; reg162=reg163+reg162; reg130=reg49*reg112; reg135=reg136+reg135; reg108=reg123+reg108;
    reg118=reg134+reg118; reg127=reg148+reg127; reg134=reg152*reg65; reg97=reg100+reg97; reg99=reg56*reg99;
    reg73=reg128+reg73; reg164=reg109+reg164; reg88=reg147+reg88; reg107=reg156+reg107; reg160=reg154-reg160;
    reg151=reg126-reg151; reg159=reg157+reg159; reg100=reg84*reg117; reg124=reg114-reg124; reg87=reg131+reg87;
    reg109=reg49*reg121; reg114=reg104*reg57; reg73=reg129-reg73; reg66=reg106+reg66; reg54=reg72+reg54;
    reg165=reg137+reg165; reg108=reg123+reg108; reg87=reg133+reg87; reg141=reg89+reg141; reg88=reg142+reg88;
    reg120=reg76+reg120; reg96=reg50+reg96; reg109=reg58+reg109; reg151=reg97+reg151; reg110=reg103*reg110;
    reg100=2*reg100; reg50=reg64*reg51; reg71=reg59+reg71; reg134=reg99+reg134; reg62=reg68+reg62;
    reg159=reg153-reg159; reg162=reg163+reg162; reg58=reg64*reg61; reg118=reg135-reg118; reg59=2*reg130;
    reg164=reg124+reg164; reg114=reg55+reg114; reg143=reg95+reg143; reg55=2*reg125; reg67=reg103*reg67;
    reg68=reg84*reg161; reg76=2*reg75; reg138=reg158+reg138; reg146=reg144-reg146; reg145=reg132+reg145;
    reg89=reg161*reg37; reg107=reg160+reg107; reg85=reg69+reg85; reg139=reg92+reg139; reg140=reg81+reg140;
    reg150=reg127+reg150; reg98=reg103*reg98; reg69=reg64*reg161; reg81=reg65*reg87; reg92=reg46*reg88;
    reg95=reg12*reg107; reg97=reg9*reg141; reg99=reg111*reg88; reg106=reg15*reg87; reg123=reg28*reg88;
    reg124=reg37*reg150; reg126=reg23*reg87; reg145=reg140-reg145; reg127=reg164*reg11; reg55=reg125+reg55;
    reg125=reg43*reg88; reg128=reg31*reg87; reg129=reg164*reg23; reg131=reg28*reg165; reg132=reg80*reg88;
    reg133=reg111*reg165; reg135=reg164*reg65; reg136=reg44*reg151; reg137=reg56*reg87; reg140=reg37*reg151;
    reg142=reg103*reg150; reg109=reg96-reg109; reg50=reg100+reg50; reg54=reg72+reg54; reg162=reg118+reg162;
    reg72=reg9*reg151; reg96=reg12*reg150; reg100=reg15*reg88; reg108=reg73+reg108; reg73=reg18*reg165;
    reg114=reg71-reg114; reg68=reg67+reg68; reg67=reg37*reg141; reg71=reg103*reg107; reg76=reg75+reg76;
    reg75=reg44*reg107; reg118=reg30*reg107; reg144=reg9*reg150; reg69=reg98+reg69; reg62=reg159+reg62;
    reg143=reg134-reg143; reg59=reg130+reg59; reg98=2*reg58; reg130=reg30*reg150; reg134=reg44*reg141;
    reg147=reg31*reg88; reg148=reg23*reg165; reg66=reg120-reg66; reg120=reg56*reg88; reg149=reg65*reg165;
    reg138=reg146+reg138; reg146=reg11*reg87; reg153=reg44*reg150; reg89=reg110+reg89; reg139=reg85-reg139;
    reg85=reg11*reg88; reg110=reg23*reg88; reg154=reg37*reg107; reg155=reg18*reg88; reg156=reg65*reg88;
    reg157=reg9*reg107; reg158=reg11*reg165; reg71=reg67+reg71; reg159=2*reg144; reg152=reg56*reg152;
    reg160=reg18*reg162; reg50=reg109+reg50; reg109=2*reg155; reg163=reg9*reg108; T reg166=reg31*reg162;
    T reg167=reg62*reg23; reg69=reg139+reg69; reg139=2*reg75; T reg168=reg44*reg165; T reg169=reg30*reg88;
    T reg170=reg138*reg9; T reg171=reg43*reg162; T reg172=reg62*reg28; T reg173=2*reg110; T reg174=reg9*reg87;
    reg135=reg137+reg135; T reg175=reg30*reg87; reg132=reg133+reg132; T reg176=reg164*reg44; T reg177=2*reg81;
    T reg178=reg111*reg162; T reg179=reg103*reg88; T reg180=reg37*reg165; T reg181=reg12*reg108; reg68=reg114+reg68;
    reg114=reg164*reg9; T reg182=reg12*reg87; reg95=reg97+reg95; T reg183=2*reg156; T reg184=2*reg99;
    T reg185=2*reg154; reg89=reg143+reg89; reg143=2*reg124; T reg186=reg120+reg149; reg55=reg145+reg55;
    reg145=reg158+reg100; T reg187=reg37*reg88; T reg188=reg44*reg108; T reg189=reg46*reg162; T reg190=reg37*reg87;
    T reg191=reg18*reg87; T reg192=reg56*reg162; T reg193=reg28*reg87; T reg194=reg62*reg65; T reg195=2*reg146;
    T reg196=reg62*reg18; reg98=reg58+reg98; reg58=reg44*reg87; T reg197=reg11*reg162; reg59=reg76-reg59;
    reg76=reg28*reg162; T reg198=reg9*reg88; T reg199=reg65*reg162; T reg200=2*reg153; T reg201=2*reg85;
    T reg202=reg37*reg108; reg92=reg73+reg92; T reg203=reg44*reg88; T reg204=2*reg157; T reg205=reg23*reg162;
    T reg206=reg43*reg87; T reg207=reg111*reg87; T reg208=reg164*reg111; T reg209=reg15*reg162; T reg210=reg164*reg37;
    T reg211=reg62*reg11; T reg212=reg9*reg165; T reg213=reg12*reg88; T reg214=reg103*reg87; T reg215=reg164*reg28;
    T reg216=reg80*reg87; reg96=reg72+reg96; T reg217=reg138*reg44; T reg218=reg30*reg108; T reg219=reg148+reg147;
    T reg220=reg62*reg111; T reg221=reg80*reg162; reg125=reg131+reg125; T reg222=reg138*reg37; T reg223=reg103*reg108;
    reg129=reg128+reg129; reg127=reg106+reg127; reg130=reg130+reg136; T reg224=reg164*reg18; T reg225=2*reg126;
    reg57=reg80*reg57; T reg226=reg46*reg87; reg54=reg66+reg54; reg66=2*reg123; reg118=reg134+reg118;
    reg142=reg140+reg142; T reg227=reg104*reg87; reg158=reg158+reg145; T reg228=reg62*reg9; reg207=2*reg207;
    T reg229=reg42*reg151; reg120=reg120+reg186; reg145=reg100+reg145; reg100=reg24*reg165; reg201=reg85+reg201;
    reg85=reg84*reg108; T reg230=reg50*reg111; T reg231=reg69*reg28; reg217=reg218+reg217; reg218=reg55*reg37;
    T reg232=reg111*reg141; T reg233=reg80*reg107; T reg234=reg50*reg65; T reg235=reg54*reg111; T reg236=elem.pos(0)[1]*reg87;
    T reg237=reg31*reg164; T reg238=reg104*reg162; T reg239=reg84*reg87; reg95=reg97+reg95; T reg240=reg50*reg37;
    T reg241=reg50*reg15; reg204=reg157+reg204; T reg242=reg12*reg162; T reg243=reg7*reg164; reg190=2*reg190;
    T reg244=reg104*reg88; T reg245=reg18*reg107; reg71=reg67+reg71; T reg246=reg84*reg150; T reg247=reg43*reg50;
    T reg248=reg30*reg151; T reg249=reg68*reg44; reg202=2*reg202; T reg250=reg42*reg138; T reg251=reg11*reg151;
    T reg252=reg55*reg30; T reg253=reg15*reg150; reg224=reg226+reg224; reg226=reg42*reg165; T reg254=reg50*reg30;
    reg172=reg171+reg172; reg171=reg54*reg31; T reg255=reg18*reg141; T reg256=reg46*reg107; reg176=reg175+reg176;
    reg175=reg45*reg151; reg178=2*reg178; reg98=reg59+reg98; reg59=reg50*reg31; T reg257=reg43*reg165;
    T reg258=reg7*reg165; reg215=reg206+reg215; reg206=elem.pos(0)[0]*reg88; T reg259=reg103*reg141; T reg260=reg56*reg165;
    T reg261=reg37*reg89; T reg262=reg43*reg54; T reg263=reg103*reg162; T reg264=reg7*reg62; T reg265=reg65*reg151;
    T reg266=reg69*reg65; T reg267=reg56*reg150; T reg268=reg42*reg164; T reg269=reg62*reg37; T reg270=reg84*reg88;
    T reg271=reg84*reg162; reg186=reg149+reg186; reg149=reg54*reg37; T reg272=reg45*reg141; reg210=reg214+reg210;
    reg214=reg84*reg165; T reg273=reg54*reg103; T reg274=reg45*reg162; T reg275=reg54*reg9; T reg276=reg84*reg62;
    T reg277=2*reg205; T reg278=2*reg203; T reg279=2*reg199; reg92=reg73+reg92; reg66=reg123+reg66;
    reg225=reg126+reg225; reg73=reg45*reg107; reg159=reg144+reg159; reg123=reg55*reg103; reg126=reg84*reg138;
    reg127=reg106+reg127; reg106=reg23*reg150; reg144=reg37*reg162; T reg280=reg68*reg37; T reg281=2*reg197;
    T reg282=reg9*reg162; T reg283=reg12*reg50; T reg284=reg45*reg164; T reg285=reg7*reg87; T reg286=reg50*reg28;
    T reg287=reg55*reg9; T reg288=reg45*reg108; reg195=reg146+reg195; reg109=reg155+reg109; reg146=reg56*reg54;
    reg155=reg50*reg18; T reg289=reg24*reg87; reg220=reg221+reg220; reg221=reg12*reg141; T reg290=reg50*reg9;
    T reg291=reg45*reg87; T reg292=reg24*reg162; T reg293=reg54*reg18; reg96=reg72+reg96; reg147=reg147+reg219;
    reg72=elem.pos(0)[2]*reg87; T reg294=reg56*reg50; T reg295=reg42*reg162; reg208=reg216+reg208; reg216=reg50*reg103;
    T reg296=reg84*reg164; T reg297=reg15*reg165; T reg298=reg9*reg89; T reg299=reg84*reg151; T reg300=reg104*reg62;
    T reg301=reg54*reg80; reg118=reg134+reg118; T reg302=reg104*reg165; T reg303=reg69*reg11; T reg304=reg28*reg141;
    T reg305=reg43*reg107; T reg306=reg23*reg151; reg161=reg103*reg161; T reg307=elem.pos(0)[2]*reg88; reg170=reg181+reg170;
    reg181=reg104*reg164; T reg308=reg50*reg80; reg200=reg153+reg200; reg153=reg24*reg62; T reg309=reg42*reg108;
    T reg310=reg55*reg44; T reg311=reg42*reg107; T reg312=reg28*reg107; reg139=reg75+reg139; T reg313=reg12*reg151;
    reg173=reg110+reg173; reg110=reg68*reg9; T reg314=reg46*reg54; T reg315=reg46*reg165; reg211=reg209+reg211;
    reg213=reg212+reg213; T reg316=reg69*reg18; T reg317=reg15*reg164; reg222=reg223+reg222; reg219=reg148+reg219;
    reg148=reg44*reg162; reg223=reg54*reg65; reg191=2*reg191; reg76=2*reg76; T reg318=reg54*reg23;
    reg196=reg189+reg196; reg58=2*reg58; reg189=reg42*reg88; T reg319=reg24*reg88; T reg320=reg50*reg11;
    reg193=2*reg193; T reg321=reg7*reg88; T reg322=reg111*reg107; T reg323=reg50*reg23; T reg324=reg31*reg150;
    T reg325=reg42*reg62; T reg326=reg42*reg150; reg188=2*reg188; T reg327=reg54*reg28; T reg328=reg54*reg44;
    T reg329=reg65*reg150; T reg330=reg45*reg138; T reg331=reg12*reg55; T reg332=reg84*reg107; reg143=reg124+reg143;
    reg124=reg45*reg165; T reg333=reg12*reg54; reg184=reg99+reg184; reg99=reg45*reg62; reg182=reg114+reg182;
    reg114=reg46*reg50; reg81=reg177+reg81; reg185=reg154+reg185; reg177=reg11*reg150; T reg334=reg24*reg164;
    reg183=reg156+reg183; reg156=reg54*reg15; reg194=reg192+reg194; reg179=reg180+reg179; T reg335=reg54*reg11;
    T reg336=2*reg198; T reg337=reg69*reg111; reg174=2*reg174; T reg338=reg80*reg165; T reg339=reg45*reg88;
    reg135=reg137+reg135; reg125=reg131+reg125; reg131=reg50*reg44; reg129=reg128+reg129; reg128=reg42*reg87;
    reg137=reg56*reg164; T reg340=reg84*reg141; reg130=reg136+reg130; reg136=reg42*reg141; reg132=reg133+reg132;
    reg133=elem.pos(0)[0]*reg87; reg142=reg140+reg142; reg163=2*reg163; reg140=reg54*reg30; T reg341=reg31*reg165;
    T reg342=reg69*reg23; T reg343=elem.pos(0)[1]*reg88; T reg344=reg44*reg89; T reg345=reg30*reg141; T reg346=reg45*reg150;
    reg160=2*reg160; T reg347=reg62*reg44; T reg348=reg103*reg151; T reg349=2*reg187; reg167=reg166+reg167;
    T reg350=reg30*reg162; T reg351=reg7*reg162; reg169=reg168+reg169; reg57=reg152-reg57; reg152=reg98*reg15;
    T reg352=reg17*reg87; reg328=reg295+reg328; reg131=reg128+reg131; reg295=reg98*reg28; T reg353=2*reg177;
    reg351=reg327+reg351; T reg354=reg42*reg69; reg222=reg299+reg222; T reg355=reg43*reg150; T reg356=reg98*reg43;
    reg72=reg317+reg72; reg317=2*reg245; T reg357=reg17*reg162; reg310=reg309+reg310; T reg358=reg243+reg247;
    T reg359=reg285+reg286; T reg360=reg98*reg44; T reg361=reg84*reg89; reg269=reg263+reg269; reg263=reg64*reg165;
    reg280=reg348+reg280; reg337=reg338+reg337; reg137=reg133+reg137; reg228=reg242+reg228; reg252=reg250+reg252;
    reg133=reg98*reg31; reg264=reg262+reg264; reg178=reg223+reg178; reg347=reg350+reg347; reg223=reg17*reg165;
    reg242=reg30*reg138; reg338=reg42*reg68; reg348=reg69*reg9; reg350=reg12*reg165; reg156=reg196+reg156;
    reg325=reg140+reg325; reg140=reg17*reg164; reg196=elem.pos(0)[1]*reg50; reg124=reg182+reg124; reg182=reg13*reg165;
    T reg362=reg13*reg151; T reg363=reg43*reg164; T reg364=reg7*reg69; T reg365=reg15*reg62; T reg366=elem.pos(0)[2]*reg162;
    reg302=reg208+reg302; reg208=reg294+reg208; reg244=reg207+reg244; reg207=reg234+reg207; reg316=reg315+reg316;
    reg234=elem.pos(0)[0]*reg162; reg294=reg45*reg89; reg110=reg313+reg110; reg313=reg56*reg62; reg315=reg98*reg65;
    reg170=reg175+reg170; T reg367=reg103*reg165; T reg368=reg69*reg37; T reg369=elem.pos(0)[1]*reg54; T reg370=reg64*reg150;
    reg270=reg190+reg270; reg144=2*reg144; reg100=reg224+reg100; reg190=reg64*reg88; T reg371=reg30*reg164;
    T reg372=reg64*reg151; reg214=reg210+reg214; reg241=reg224+reg241; reg210=reg98*reg56; reg220=reg146+reg220;
    reg146=reg31*reg62; reg224=elem.pos(0)[1]*reg162; T reg373=reg30*reg165; T reg374=reg69*reg44; reg211=reg209+reg211;
    reg209=reg13*reg162; T reg375=reg98*reg9; reg213=reg212+reg213; reg147=reg219+reg147; reg212=reg13*reg141;
    reg254=reg268+reg254; reg216=reg296+reg216; reg300=reg301+reg300; reg118=reg134+reg118; reg305=reg304+reg305;
    reg303=reg297+reg303; reg134=reg324+reg306; reg307=reg297+reg307; reg221=reg221+reg298; reg219=reg103*reg138;
    reg297=reg84*reg68; T reg376=reg104*reg69; T reg377=reg80*reg164; T reg378=elem.pos(0)[0]*reg50; T reg379=reg18*reg150;
    reg173=2*reg173; reg139=reg75+reg139; reg75=2*reg312; T reg380=reg11*reg108; T reg381=reg18*reg151;
    T reg382=reg289+reg155; T reg383=reg46*reg150; T reg384=reg15*reg108; T reg385=reg138*reg11; reg290=reg291+reg290;
    reg292=reg293+reg292; reg272=reg96+reg272; reg96=reg13*reg87; reg274=reg275+reg274; reg275=reg98*reg18;
    reg277=reg205+reg277; reg278=reg203+reg278; reg203=reg17*reg107; reg225=reg66+reg225; reg123=reg126+reg123;
    reg66=reg56*reg108; reg205=reg138*reg65; T reg386=reg308+reg181; reg311=reg200+reg311; reg200=reg28*reg150;
    T reg387=reg111*reg151; T reg388=reg80*reg150; reg127=reg92+reg127; reg92=reg23*reg108; reg349=reg187+reg349;
    reg187=elem.pos(0)[2]*reg50; T reg389=reg64*reg107; T reg390=reg24*reg69; T reg391=reg46*reg164; T reg392=reg13*reg164;
    reg99=reg333+reg99; reg333=reg98*reg46; reg184=reg81+reg184; reg332=reg143+reg332; reg81=reg65*reg108;
    reg143=reg111*reg150; reg145=reg158+reg145; reg95=reg97+reg95; reg233=reg232+reg233; reg97=reg267+reg265;
    reg158=reg45*reg69; reg256=reg255+reg256; T reg393=reg12*reg164; T reg394=elem.pos(0)[2]*reg54; T reg395=reg98*reg12;
    T reg396=reg13*reg62; reg71=reg67+reg71; reg67=reg46*reg62; reg186=reg120+reg186; reg120=reg64*reg164;
    reg276=reg273+reg276; reg273=reg98*reg80; reg73=reg159+reg73; reg195=reg109+reg195; reg109=reg84*reg69;
    reg159=reg103*reg164; T reg397=reg80*reg62; T reg398=elem.pos(0)[0]*reg54; reg281=reg197+reg281; reg336=reg198+reg336;
    reg197=reg13*reg107; reg198=2*reg322; T reg399=2*reg329; reg331=reg330+reg331; reg185=reg154+reg185;
    reg154=reg334+reg114; T reg400=reg64*reg62; T reg401=reg98*reg103; reg183=2*reg183; reg283=reg284+reg283;
    reg153=reg314+reg153; reg161=reg57+reg161; reg279=reg199+reg279; reg57=reg12*reg138; reg199=reg45*reg68;
    reg189=reg58+reg189; reg58=reg17*reg150; reg319=reg191+reg319; reg258=reg215+reg258; reg321=reg193+reg321;
    reg323=reg193+reg323; reg320=reg191+reg320; reg188=reg326+reg188; reg59=reg215+reg59; reg191=2*reg106;
    reg163=reg346+reg163; reg193=reg17*reg151; reg240=reg239+reg240; reg215=reg230+reg227; reg342=reg341+reg342;
    reg343=reg341+reg343; reg217=reg229+reg217; reg341=reg98*reg30; reg259=reg261+reg259; T reg402=reg98*reg111;
    T reg403=reg64*reg162; T reg404=reg98*reg37; reg194=reg192+reg194; reg192=reg17*reg62; T reg405=reg98*reg23;
    reg148=2*reg148; reg271=reg149+reg271; reg179=reg180+reg179; reg149=reg17*reg88; reg180=reg64*reg87;
    reg266=reg260+reg266; reg260=reg206+reg260; reg206=reg64*reg141; reg318=reg76+reg318; reg238=reg235+reg238;
    reg249=reg248+reg249; reg76=reg13*reg150; reg248=reg98*reg11; reg282=2*reg282; T reg406=reg138*reg23;
    T reg407=reg31*reg108; reg339=reg174+reg339; reg174=reg42*reg89; reg202=reg246+reg202; T reg408=reg13*reg88;
    reg236=reg237+reg236; reg231=reg257+reg231; reg340=reg142+reg340; reg287=reg288+reg287; reg142=reg28*reg151;
    reg237=reg253+reg251; reg132=reg135+reg132; reg136=reg130+reg136; reg129=reg125+reg129; reg335=reg160+reg335;
    reg201=2*reg201; reg218=reg85+reg218; reg125=reg17*reg141; reg169=reg168+reg169; reg171=reg172+reg171;
    reg226=reg176+reg226; reg167=reg166+reg167; reg204=reg157+reg204; reg130=reg43*reg62; reg345=reg344+reg345;
    reg135=reg325+reg140; reg157=elem.pos(0)[2]*reg165; reg160=reg15*reg69; reg166=reg17*reg69; reg325=reg356+reg325;
    reg389=reg349+reg389; reg168=reg17*reg68; reg172=reg42*reg55; reg176=elem.pos(0)[1]*reg98; reg257=reg7*reg50;
    reg204=reg201+reg204; reg349=reg279+reg349; reg253=reg237+reg253; reg71=reg186+reg71; reg186=reg17*reg138;
    reg202=reg246+reg202; reg201=reg111*reg108; reg256=reg255+reg256; reg268=reg254+reg268; reg264=reg262+reg264;
    reg267=reg267+reg97; reg97=reg265+reg97; reg242=reg338+reg242; reg233=reg232+reg233; reg196=reg363+reg196;
    reg95=reg145+reg95; reg145=reg42*reg161; reg246=reg30*reg68; reg254=2*reg143; reg262=elem.pos(0)[1]*reg164;
    reg364=reg363+reg364; reg265=2*reg81; reg279=reg43*reg69; reg332=reg184+reg332; reg152=reg152+reg228;
    reg184=reg341+reg192; reg244=reg207+reg244; reg228=reg228+reg182; reg207=reg15*reg151; reg356=reg18*reg89;
    reg221=reg298+reg221; reg307=reg303+reg307; reg320=reg319+reg320; reg163=reg346+reg163; reg212=reg213+reg212;
    reg298=elem.pos(0)[0]*reg150; reg303=reg56*reg151; reg213=reg211+reg213; reg211=reg68*reg65; reg127=reg272+reg127;
    reg272=reg111*reg89; reg388=reg387+reg388; reg319=reg80*reg141; reg205=reg66+reg205; reg346=reg30*reg62;
    reg315=reg315+reg144; reg144=reg144+reg190; reg369=reg130+reg369; reg340=reg132+reg340; reg335=reg335+reg339;
    reg76=reg339+reg76; reg248=reg248+reg282; reg383=reg381+reg383; reg282=reg282+reg408; reg130=2*reg92;
    reg354=reg371+reg354; reg370=reg270+reg370; reg353=reg177+reg353; reg132=reg12*reg89; reg270=reg178+reg270;
    reg177=reg161*reg9; reg185=reg183+reg185; reg317=reg245+reg317; reg399=reg329+reg399; reg178=reg18*reg108;
    reg198=reg322+reg198; reg197=reg336+reg197; reg336=reg281+reg336; reg183=reg56*reg107; reg281=reg65*reg141;
    reg266=reg260+reg266; reg260=reg28*reg89; reg329=reg43*reg141; reg195=reg73+reg195; reg259=reg261+reg259;
    reg73=2*reg380; reg261=2*reg379; reg194=reg194+reg179; reg339=reg65*reg107; reg363=elem.pos(0)[2]*reg150;
    reg371=reg68*reg11; reg206=reg179+reg206; reg133=reg133+reg347; reg347=reg347+reg223; reg216=reg296+reg216;
    reg179=reg13*reg69; reg241=reg100+reg241; reg100=reg64*reg69; reg238=reg235+reg238; reg235=reg269+reg263;
    reg269=reg210+reg269; reg210=reg64*reg138; reg136=reg129+reg136; reg129=reg64*reg89; reg296=reg103*reg62;
    reg368=reg367+reg368; reg313=reg234+reg313; reg234=reg12*reg62; reg367=reg13*reg68; T reg409=elem.pos(0)[0]*reg98;
    T reg410=reg161*reg37; T reg411=reg103*reg89; reg355=reg355+reg142; reg376=reg377+reg376; reg170=reg175+reg170;
    reg175=reg31*reg69; T reg412=elem.pos(0)[1]*reg165; T reg413=reg68*reg23; T reg414=reg30*reg89; T reg415=reg161*reg44;
    reg219=reg297+reg219; T reg416=elem.pos(0)[1]*reg150; reg324=reg324+reg134; reg372=reg214+reg372; reg214=reg220+reg214;
    reg134=reg306+reg134; reg224=reg146+reg224; reg361=reg280+reg361; reg337=reg137+reg337; reg374=reg373+reg374;
    reg305=reg304+reg305; reg137=reg17*reg89; reg118=reg147+reg118; reg300=reg301+reg300; reg203=reg278+reg203;
    reg278=reg277+reg278; reg187=reg391+reg187; reg275=reg275+reg274; reg274=reg274+reg96; reg59=reg258+reg59;
    reg217=reg229+reg217; reg283=reg284+reg283; reg292=reg293+reg292; reg290=reg291+reg290; reg57=reg199+reg57;
    reg146=reg13*reg108; reg147=reg138*reg28; reg220=elem.pos(0)[2]*reg98; reg287=reg288+reg287; reg158=reg393+reg158;
    reg229=reg46*reg141; reg289=reg289+reg382; reg382=reg155+reg382; reg153=reg314+reg153; reg155=reg43*reg108;
    reg258=reg56*reg69; reg277=elem.pos(0)[0]*reg165; reg236=reg231+reg236; reg174=reg249+reg174; reg231=reg13*reg138;
    reg240=reg239+reg240; reg171=reg171+reg226; reg239=reg64*reg108; reg193=reg226+reg193; reg390=reg391+reg390;
    reg230=reg230+reg215; reg226=2*reg200; reg251=reg237+reg251; reg237=reg45*reg55; reg215=reg227+reg215;
    reg311=reg225+reg311; reg308=reg308+reg386; reg386=reg181+reg386; reg406=reg407+reg406; reg123=reg126+reg123;
    reg181=reg24*reg50; reg218=reg85+reg218; reg109=reg159+reg109; reg159=elem.pos(0)[2]*reg164; reg252=reg250+reg252;
    reg225=reg148+reg149; reg148=reg405+reg148; reg227=reg80*reg69; reg249=reg64*reg68; reg280=reg138*reg111;
    reg284=reg80*reg108; reg188=reg326+reg188; reg291=reg46*reg69; reg293=reg46*reg108; reg72=reg316+reg72;
    reg301=reg31*reg107; reg306=reg23*reg141; reg314=reg375+reg209; reg316=reg138*reg18; reg326=reg360+reg357;
    reg373=reg23*reg107; reg391=reg13*reg89; reg393=reg84*reg161; reg405=reg103*reg68; reg58=reg189+reg58;
    T reg417=reg45*reg161; reg189=reg318+reg189; reg348=reg350+reg348; reg331=reg330+reg331; reg323=reg321+reg323;
    reg333=reg333+reg99; reg99=reg99+reg392; reg318=reg12*reg68; reg366=reg365+reg366; reg114=reg114+reg154;
    reg154=reg334+reg154; reg362=reg124+reg362; reg321=reg11*reg107; reg124=reg156+reg124; reg397=reg398+reg397;
    reg343=reg342+reg343; reg285=reg285+reg359; reg359=reg286+reg359; reg167=reg167+reg169; reg139=reg173+reg139;
    reg125=reg169+reg125; reg156=reg28*reg108; reg385=reg384+reg385; reg169=reg15*reg107; reg310=reg309+reg310;
    reg173=elem.pos(0)[0]*reg164; reg286=reg401+reg400; reg334=reg84*reg55; reg342=reg31*reg151; reg394=reg67+reg394;
    reg377=reg378+reg377; reg222=reg299+reg222; reg302=reg208+reg302; reg67=reg11*reg141; reg402=reg402+reg271;
    reg294=reg110+reg294; reg271=reg271+reg180; reg345=reg344+reg345; reg106=reg191+reg106; reg273=reg273+reg276;
    reg276=reg276+reg120; reg110=reg104*reg50; reg295=reg295+reg328; reg328=reg328+reg352; reg191=reg404+reg403;
    reg247=reg247+reg358; reg351=reg327+reg351; reg131=reg128+reg131; reg75=reg312+reg75; reg128=reg17*reg108;
    reg358=reg243+reg358; reg208=reg395+reg396; reg248=reg248+reg282; reg287=reg288+reg287; reg282=reg408+reg282;
    reg187=reg390+reg187; reg57=reg199+reg57; reg163=reg320+reg163; reg199=reg55*reg23; reg243=reg24*reg108;
    reg413=reg342+reg413; reg333=reg333+reg99; reg329=reg260+reg329; reg125=reg167+reg125; reg416=reg342+reg416;
    reg319=reg272+reg319; reg99=reg392+reg99; reg167=2*reg321; reg345=reg343+reg345; reg389=reg349+reg389;
    reg288=reg55*reg18; reg211=reg303+reg211; reg355=reg142+reg355; reg142=reg7*reg141; reg299=reg104*reg138;
    reg320=reg55*reg80; reg303=reg298+reg303; reg406=reg407+reg406; reg76=reg335+reg76; reg298=2*reg136;
    reg327=2*reg334; reg335=2*reg139; reg106=2*reg106; reg273=reg273+reg276; reg276=reg120+reg276;
    reg73=reg380+reg73; reg75=reg312+reg75; reg120=reg24*reg107; reg261=reg379+reg261; reg312=2*reg118;
    reg342=2*reg339; reg343=2*reg95; reg363=reg207+reg363; reg371=reg207+reg371; reg324=reg134+reg324;
    reg134=reg296+reg100; reg229=reg229+reg356; reg221=reg307+reg221; reg207=reg24*reg138; reg198=reg322+reg198;
    reg307=2*reg185; reg399=2*reg399; reg197=reg336+reg197; reg227=reg173+reg227; reg393=reg405+reg393;
    reg173=reg183+reg281; reg331=reg330+reg331; reg322=reg46*reg55; reg114=reg154+reg114; reg154=reg286+reg400;
    reg401=reg286+reg401; reg397=reg397+reg109; reg286=2*reg195; reg249=reg109+reg249; reg109=reg306+reg301;
    reg226=reg200+reg226; reg205=reg66+reg205; reg386=reg308+reg386; reg123=reg126+reg123; reg203=reg278+reg203;
    reg66=2*reg340; reg275=reg275+reg274; reg274=reg96+reg274; reg292=reg292+reg290; reg96=reg64*reg161;
    reg384=reg385+reg384; reg146=reg290+reg146; reg126=reg103*reg69; reg200=reg24*reg141; reg383=reg381+reg383;
    reg278=elem.pos(0)[0]*reg62; reg382=reg289+reg382; reg376=reg377+reg376; reg219=reg297+reg219; reg305=reg304+reg305;
    reg300=reg300+reg216; reg212=reg213+reg212; reg210=reg216+reg210; reg296=reg409+reg296; reg375=reg314+reg375;
    reg314=reg314+reg209; reg231=reg283+reg231; reg213=2*reg311; reg216=2*reg127; reg92=reg130+reg92;
    reg130=reg104*reg141; reg283=reg153+reg283; reg388=reg387+reg388; reg153=reg7*reg107; reg263=reg263+reg235;
    reg223=reg223+reg347; reg347=reg133+reg347; reg137=reg374+reg137; reg374=reg224+reg374; reg361=reg337+reg361;
    reg256=reg255+reg256; reg372=reg214+reg372; reg415=reg414+reg415; reg190=reg190+reg144; reg144=reg315+reg144;
    reg412=reg175+reg412; reg170=reg241+reg170; reg133=reg169+reg67; reg222=reg302+reg222; reg175=reg55*reg28;
    reg214=reg7*reg108; reg310=reg309+reg310; reg224=elem.pos(0)[0]*reg108; reg241=reg192+reg184; reg97=reg267+reg97;
    reg255=reg43*reg151; reg262=reg279+reg262; reg193=reg171+reg193; reg145=reg246+reg145; reg171=2*reg237;
    reg246=reg104*reg150; reg201=2*reg201; reg174=reg236+reg174; reg236=reg55*reg65; reg202=reg244+reg202;
    reg258=reg277+reg258; reg410=reg411+reg410; reg370=reg270+reg370; reg313=reg313+reg368; reg129=reg368+reg129;
    reg220=reg220+reg234; reg235=reg269+reg235; reg140=reg140+reg135; reg182=reg182+reg228; reg228=reg152+reg228;
    reg152=reg104*reg151; reg244=2*reg204; reg362=reg124+reg362; reg159=reg291+reg159; reg196=reg364+reg196;
    reg124=reg43*reg55; reg267=reg7*reg138; reg242=reg338+reg242; reg366=reg366+reg348; reg391=reg348+reg391;
    reg417=reg318+reg417; reg252=reg250+reg252; reg264=reg264+reg268; reg247=reg358+reg247; reg186=reg268+reg186;
    reg253=reg251+reg253; reg250=reg56*reg138; reg251=reg80*reg151; reg268=reg68*reg111; reg359=reg285+reg359;
    reg128=reg131+reg128; reg131=reg351+reg131; reg395=reg395+reg208; reg352=reg352+reg328; reg328=reg295+reg328;
    reg317=reg245+reg317; reg208=reg396+reg208; reg245=reg357+reg326; reg353=2*reg353; reg326=reg360+reg326;
    reg369=reg369+reg354; reg168=reg354+reg168; reg72=reg294+reg72; reg269=reg56*reg55; reg280=reg284+reg280;
    reg135=reg325+reg135; reg180=reg180+reg271; reg178=2*reg178; reg270=reg24*reg150; reg277=2*reg373;
    reg279=elem.pos(0)[2]*reg62; reg265=reg81+reg265; reg81=reg12*reg69; reg238=reg238+reg240; reg239=reg240+reg239;
    reg240=reg84*reg50; reg284=reg55*reg31; reg215=reg230+reg215; reg218=reg85+reg218; reg254=reg143+reg254;
    reg177=reg132+reg177; reg85=reg55*reg111; reg132=reg104*reg108; reg157=reg160+reg157; reg147=reg155+reg147;
    reg156=2*reg156; reg143=reg7*reg150; reg188=reg323+reg188; reg58=reg189+reg58; reg155=2*reg110;
    reg206=reg194+reg206; reg149=reg149+reg225; reg225=reg148+reg225; reg148=reg24*reg151; reg316=reg293+reg316;
    reg404=reg404+reg191; reg191=reg403+reg191; reg160=reg55*reg11; reg234=reg234+reg179; reg259=reg266+reg259;
    reg189=reg55*reg15; reg367=reg158+reg367; reg194=reg46*reg151; reg230=reg68*reg18; reg271=reg402+reg271;
    reg266=reg7*reg151; reg158=reg394+reg158; reg285=reg45*reg50; reg289=reg31*reg138; reg290=reg7*reg54;
    reg291=reg42*reg50; reg176=reg346+reg176; reg293=elem.pos(0)[1]*reg108; reg233=reg232+reg233; reg232=reg24*reg54;
    reg294=reg15*reg138; reg295=2*reg257; reg297=2*reg172; reg302=2*reg332; reg304=elem.pos(0)[2]*reg108;
    reg217=reg59+reg217; reg59=2*reg71; reg346=reg346+reg166; reg308=reg17*reg161; reg309=reg104*reg54;
    reg315=2*reg181; reg318=reg68*reg28; reg323=reg104*reg107; reg325=reg13*reg161; reg330=reg30*reg69;
    reg336=elem.pos(0)[1]*reg62; reg184=reg341+reg184; reg231=reg283+reg231; reg417=reg159+reg417; reg367=reg158+reg367;
    reg233=reg97+reg233; reg97=elem.pos(0)[0]*reg107; reg331=reg114+reg331; reg114=reg56*reg141; reg315=reg181+reg315;
    reg158=2*reg285; reg159=reg65*reg89; reg179=reg234+reg179; reg181=elem.pos(0)[2]*reg107; reg283=reg15*reg141;
    reg337=reg11*reg89; reg279=reg279+reg81; reg57=reg187+reg57; reg187=reg24*reg68; reg338=reg46*reg138;
    reg325=reg81+reg325; reg81=elem.pos(0)[2]*reg55; reg220=reg234+reg220; reg277=reg277+reg373; reg234=reg45*reg54;
    reg395=reg395+reg208; reg99=reg333+reg99; reg12=reg12*reg161; reg208=reg396+reg208; reg333=elem.pos(0)[2]*reg69;
    reg341=2*reg232; reg344=reg24*reg55; reg171=reg237+reg171; reg348=reg302-reg66; reg182=reg228+reg182;
    reg192=reg192+reg241; reg241=reg184+reg241; reg318=reg255+reg318; reg184=reg7*reg89; reg166=reg346+reg166;
    reg176=reg346+reg176; reg228=reg7*reg55; reg297=reg172+reg297; reg293=reg289+reg293; reg255=2*reg174;
    reg304=reg294+reg304; reg295=reg257+reg295; reg257=2*reg291; reg289=reg24*reg89; reg230=reg194+reg230;
    reg194=2*reg290; reg294=reg42*reg54; reg308=reg330+reg308; reg330=reg336+reg330; reg30=reg30*reg161;
    reg336=elem.pos(0)[1]*reg69; reg177=reg157+reg177; reg157=reg266+reg147; reg284=reg147+reg284; reg147=reg46*reg89;
    reg346=reg161*reg18; reg349=reg43*reg138; reg350=reg7*reg68; reg351=elem.pos(0)[1]*reg55; reg186=reg264+reg186;
    reg252=reg247+reg252; reg391=reg366+reg391; reg242=reg196+reg242; reg196=reg267+reg124; reg247=3*reg362;
    reg140=reg135+reg140; reg135=2*reg72; reg168=reg369+reg168; reg326=reg326+reg245; reg245=reg357+reg245;
    reg352=reg328+reg352; reg128=reg131+reg128; reg310=reg359+reg310; reg131=reg214+reg175; reg264=2*reg170;
    reg415=reg412+reg415; reg137=reg374+reg137; reg223=reg347+reg223; reg328=reg43*reg89; reg347=reg161*reg28;
    reg354=reg31*reg68; reg357=elem.pos(0)[1]*reg151; reg145=reg262+reg145; reg153=reg226+reg153; reg92=reg226+reg92;
    reg226=3*reg203; reg209=reg209+reg314; reg314=reg375+reg314; reg262=reg31*reg141; reg358=elem.pos(0)[1]*reg107;
    reg359=3*reg212; reg229=reg356+reg229; reg324=reg305+reg324; reg363=reg371+reg363; reg305=2*reg221;
    reg342=reg339+reg342; reg356=reg23*reg89; reg360=reg213-reg298; reg120=reg261+reg120; reg73=reg261+reg73;
    reg106=reg75+reg106; reg75=reg307-reg59; reg261=reg306+reg109; reg109=reg301+reg109; reg301=reg335-reg312;
    reg364=reg207+reg322; reg365=reg281+reg173; reg173=reg183+reg173; reg183=3*reg197; reg198=reg399+reg198;
    reg366=reg15*reg68; reg368=elem.pos(0)[2]*reg151; reg369=2*reg217; reg371=3*reg193; reg189=reg316+reg189;
    reg374=reg270+reg178; reg160=reg178+reg160; reg316=reg148+reg316; reg149=reg225+reg149; reg178=reg143+reg156;
    reg199=reg156+reg199; reg156=2*reg188; reg225=3*reg58; reg329=reg260+reg329; reg416=reg413+reg416;
    reg260=2*reg345; reg375=reg243+reg288; reg142=reg355+reg142; reg406=reg355+reg406; reg355=3*reg125;
    reg287=reg382+reg287; reg282=reg248+reg282; reg248=2*reg163; reg377=3*reg76; reg146=reg292+reg146;
    reg200=reg383+reg200; reg384=reg383+reg384; reg274=reg275+reg274; reg275=3*reg370; reg292=reg104*reg89;
    reg393=reg227+reg393; reg268=reg251+reg268; reg250=reg224+reg250; reg400=reg400+reg154; reg154=reg401+reg154;
    reg224=2*reg361; reg167=reg321+reg167; reg100=reg100+reg134; reg134=reg296+reg134; reg96=reg126+reg96;
    reg126=reg278+reg126; reg103=reg103*reg161; reg227=elem.pos(0)[0]*reg69; reg251=3*reg389; reg278=reg244-reg343;
    reg211=reg303+reg211; reg296=reg80*reg138; reg303=elem.pos(0)[0]*reg55; reg123=reg386+reg123; reg378=reg104*reg68;
    reg210=reg300+reg210; reg300=3*reg372; reg353=reg317+reg353; reg219=reg376+reg219; reg190=reg144+reg190;
    reg236=reg236+reg201; reg201=reg201+reg246; reg144=reg280+reg152; reg276=reg273+reg276; reg273=2*reg202;
    reg249=reg397+reg249; reg317=reg320+reg299; reg280=reg269+reg280; reg269=2*reg222; reg376=2*reg309;
    reg205=reg205+reg388; reg130=reg388+reg130; reg180=reg271+reg180; reg271=elem.pos(0)[0]*reg151; reg239=reg238+reg239;
    reg238=3*reg206; reg379=reg67+reg133; reg218=reg215+reg218; reg215=reg286-reg216; reg380=reg85+reg132;
    reg381=reg84*reg54; reg133=reg169+reg133; reg263=reg235+reg263; reg129=reg313+reg129; reg323=reg254+reg323;
    reg254=reg265+reg254; reg410=reg258+reg410; reg253=reg256+reg253; reg319=reg272+reg319; reg169=reg161*reg111;
    reg235=reg104*reg55; reg256=2*reg259; reg327=reg334+reg327; reg404=reg404+reg191; reg155=reg110+reg155;
    reg191=reg403+reg191; reg110=reg80*reg89; reg258=reg56*reg68; reg265=2*reg240; reg272=4*reg180;
    reg313=3*reg168; reg382=2*reg415; reg169=reg110+reg169; reg110=3*reg391; reg383=reg267+reg196;
    reg196=reg124+reg196; reg357=reg354+reg357; reg124=2*reg252; reg347=reg328+reg347; reg328=3*reg186;
    reg258=reg271+reg258; reg250=reg250+reg268; reg271=reg214+reg131; reg133=reg379+reg133; reg354=4*reg140;
    reg152=reg152+reg144; reg144=reg280+reg144; reg280=2*reg410; reg131=reg175+reg131; reg379=reg67+reg379;
    reg292=reg268+reg292; reg67=4*reg352; reg175=3*reg129; reg245=reg326+reg245; reg268=3*reg128;
    reg326=2*reg310; reg368=reg366+reg368; reg366=2*reg177; reg270=reg270+reg374; reg160=reg374+reg160;
    reg319=reg211+reg319; reg211=4*reg282; reg374=reg183-reg359; reg384=reg200+reg384; reg200=reg248-reg264;
    reg385=reg66-reg224; reg130=reg205+reg130; reg205=reg377-reg247; reg386=1.5*reg370; reg351=reg349+reg351;
    reg387=reg215-reg216; reg363=reg229+reg363; reg229=reg216-reg135; reg388=1.5*reg76; reg390=4*reg185;
    reg339=reg339+reg342; reg342=2*reg342; reg392=reg273-reg269; reg73=reg120+reg73; reg120=4*reg163;
    reg394=reg275-reg300; reg396=reg75-reg59; reg397=reg302+reg348; reg398=reg198-reg233; reg399=2*reg242;
    reg401=4*reg263; reg349=reg350+reg349; reg402=2*reg145; reg403=elem.pos(0)[1]*reg138; reg405=reg7*reg161;
    reg407=reg43*reg68; reg408=4*reg195; reg236=reg236+reg201; reg201=reg246+reg201; reg246=4*reg182;
    reg192=reg241+reg192; reg166=reg176+reg166; reg176=2*reg228; reg297=reg172+reg297; reg295=2*reg295;
    reg172=reg17*reg55; reg257=reg291+reg257; reg194=reg290+reg194; reg241=reg17*reg50; reg294=2*reg294;
    reg290=reg7*reg98; reg291=reg17*reg54; reg409=reg98*reg42; reg411=4*reg190; reg308=reg330+reg308;
    reg30=reg336+reg30; reg346=reg147+reg346; reg147=2*reg235; reg330=reg46*reg68; reg336=reg24*reg161;
    reg412=elem.pos(0)[2]*reg138; reg413=2*reg417; reg103=reg227+reg103; reg96=reg126+reg96; reg126=reg187+reg338;
    reg100=reg134+reg100; reg134=4*reg139; reg227=2*reg277; reg277=reg373+reg277; reg81=reg338+reg81;
    reg400=reg154+reg400; reg154=2*reg57; reg338=3*reg367; reg373=reg207+reg364; reg364=reg322+reg364;
    reg322=reg301-reg312; reg414=reg213+reg360; T reg418=reg106-reg324; T reg419=2*reg331; reg109=reg261+reg109;
    reg261=reg306+reg261; reg306=4*reg311; T reg420=3*reg231; T reg421=4*reg99; T reg422=reg226-reg355;
    reg208=reg395+reg208; reg395=reg98*reg84; T reg423=reg64*reg54; reg179=reg220+reg179; reg220=2*reg344;
    reg171=reg237+reg171; reg315=2*reg315; reg237=reg98*reg104; T reg424=reg13*reg55; reg158=reg285+reg158;
    reg381=2*reg381; reg341=reg232+reg341; reg232=reg64*reg50; reg285=reg13*reg50; reg234=2*reg234;
    T reg425=reg98*reg24; T reg426=reg13*reg54; T reg427=reg98*reg45; reg325=reg279+reg325; reg376=reg309+reg376;
    reg265=reg240+reg265; reg12=reg333+reg12; reg240=reg64*reg55; reg155=2*reg155; reg327=reg334+reg327;
    reg279=3*reg210; reg416=reg329+reg416; reg309=4*reg276; reg329=2*reg167; reg167=reg321+reg167;
    reg321=4*reg149; reg333=2*reg287; reg199=reg178+reg199; reg178=reg143+reg178; reg143=4*reg274;
    reg334=reg278-reg343; reg215=reg286+reg215; reg148=reg148+reg316; reg189=reg316+reg189; reg191=reg404+reg191;
    reg316=4*reg223; reg284=reg157+reg284; reg157=reg266+reg157; reg85=reg85+reg380; reg380=reg132+reg380;
    reg289=reg230+reg289; reg304=reg230+reg304; reg230=3*reg137; reg266=2*reg218; reg404=3*reg239;
    reg293=reg318+reg293; reg184=reg318+reg184; reg318=reg353-reg253; reg360=reg360-reg298; T reg428=1.5*reg203;
    T reg429=reg312-reg260; T reg430=reg311-reg298; T reg431=2*reg393; T reg432=elem.pos(0)[0]*reg138; T reg433=reg80*reg68;
    T reg434=reg104*reg161; reg358=reg262+reg358; reg262=reg356+reg262; T reg435=4*reg188; reg92=reg153+reg92;
    reg153=2*reg219; reg303=reg303+reg296; reg296=reg296+reg378; reg209=reg314+reg209; reg314=3*reg249;
    T reg436=reg225-reg371; T reg437=reg156-reg369; T reg438=4*reg204; T reg439=2*reg123; T reg440=1.5*reg58;
    T reg441=reg298-reg255; reg406=reg142+reg406; reg320=reg320+reg317; reg317=reg299+reg317; reg142=reg243+reg375;
    reg375=reg288+reg375; reg288=3*reg146; T reg442=4*reg332; T reg443=1.5*reg197; T reg444=reg114+reg159;
    T reg445=reg332-reg66; reg173=reg173+reg365; reg323=reg254+reg323; reg181=reg283+reg181; reg365=reg281+reg365;
    reg254=4*reg202; reg281=reg59-reg256; T reg446=reg195-reg216; reg114=reg97+reg114; reg348=reg348-reg66;
    reg97=reg251-reg238; reg283=reg337+reg283; T reg447=reg343-reg305; T reg448=1.5*reg389; T reg449=reg202-reg269;
    T reg450=2*reg180; T reg451=reg385-reg224; T reg452=reg371-reg313; reg365=reg173+reg365; reg418=reg418-reg324;
    reg173=reg377+reg205; T reg453=reg281-reg256; T reg454=2*reg352; T reg455=2*reg323; T reg456=1.5*reg128;
    T reg457=5*reg208; T reg458=reg448-reg238; T reg459=reg334-reg343; T reg460=3*reg308; T reg461=5*reg209;
    T reg462=reg67-reg354; T reg463=2*reg92; T reg464=reg268-reg328; T reg465=reg213+reg306; T reg466=reg326-reg124;
    T reg467=6*reg197; T reg468=reg374-reg359; T reg469=6*reg203; T reg470=2*reg274; reg215=reg387+reg215;
    T reg471=reg200-reg264; reg350=reg350+reg349; reg349=reg351+reg349; reg189=reg148+reg189; reg109=reg261+reg109;
    reg148=1.5*reg362; reg261=reg135-reg413; reg351=elem.pos(0)[0]*reg68; T reg472=reg15*reg89; T reg473=reg161*reg11;
    T reg474=elem.pos(0)[2]*reg141; T reg475=reg233-reg319; T reg476=1.5*reg193; T reg477=2*reg190; reg81=reg126+reg81;
    reg227=reg277+reg227; reg277=2*reg106; T reg478=reg255-reg402; T reg479=reg335+reg134; reg446=reg446-reg229;
    reg293=reg184+reg293; reg126=reg187+reg126; reg318=reg318-reg253; reg387=reg387-reg216; reg127=reg127-reg135;
    reg184=reg305-reg366; reg187=1.5*reg239; T reg480=1.5*reg212; reg414=reg360+reg414; T reg481=reg369-reg399;
    T reg482=reg322-reg312; reg205=reg205-reg247; T reg483=reg226+reg422; reg284=reg157+reg284; reg157=4*reg166;
    reg85=reg85+reg380; reg380=reg132+reg380; reg364=reg373+reg364; reg132=reg386-reg300; reg373=reg207+reg373;
    reg385=reg445-reg385; reg207=2*reg103; reg445=reg238-reg175; T reg484=4*reg179; reg304=reg289+reg304;
    reg289=reg211-reg246; T reg485=reg300-reg314; reg267=reg267+reg383; reg80=reg80*reg161; reg196=reg383+reg196;
    reg383=1.5*reg125; reg172=reg257+reg172; T reg486=reg436-reg371; T reg487=reg321-reg316; T reg488=4*reg100;
    T reg489=6*reg389; reg297=reg295+reg297; reg295=6*reg239; T reg490=reg260-reg382; T reg491=reg333-reg419;
    reg176=reg228+reg176; T reg492=reg323-reg130; reg378=reg378+reg296; T reg493=reg288-reg420; reg296=reg303+reg296;
    reg136=reg136-reg255; reg303=reg143-reg421; T reg494=4*reg218; T reg495=reg156+reg435; T reg496=2*reg353;
    T reg497=reg275+reg394; T reg498=reg188-reg369; T reg499=reg273+reg254; T reg500=reg441-reg255; T reg501=reg348-reg66;
    reg320=reg320+reg317; reg317=reg299+reg317; reg299=reg273+reg392; T reg502=reg440-reg371; T reg503=reg409+reg291;
    T reg504=reg355-reg230; T reg505=2*reg149; reg243=reg243+reg142; reg375=reg142+reg375; reg142=elem.pos(0)[0]*reg141;
    T reg506=reg56*reg89; T reg507=reg244+reg438; T reg508=reg161*reg65; reg368=reg346+reg368; reg290=reg290+reg294;
    reg294=reg294+reg241; reg346=reg437-reg369; reg257=reg194+reg257; reg194=reg31*reg89; T reg509=reg324-reg416;
    T reg510=reg97-reg238; reg441=reg430-reg441; reg430=reg429-reg260; T reg511=6*reg128; T reg512=reg428-reg355;
    T reg513=4*reg287; T reg514=reg272-reg309; reg405=reg407+reg405; reg403=reg407+reg403; reg407=4*reg310;
    T reg515=reg92-reg406; reg199=reg178+reg199; reg178=6*reg146; reg437=reg156+reg437; reg360=reg360-reg298;
    T reg516=0.5*reg58; reg436=reg225+reg436; reg422=reg422-reg355; T reg517=reg266-reg439; reg374=reg183+reg374;
    reg43=reg43*reg161; T reg518=elem.pos(0)[1]*reg68; reg329=reg167+reg329; reg58=6*reg58; reg160=reg270+reg160;
    reg201=reg236+reg201; reg167=2*reg30; reg236=5*reg400; reg356=reg356+reg262; reg358=reg262+reg358;
    reg262=0.5*reg370; reg270=reg302+reg442; T reg519=3*reg96; T reg520=2*reg73; reg434=reg433+reg434;
    reg433=reg432+reg433; reg340=reg340-reg224; reg432=elem.pos(0)[1]*reg141; T reg521=reg256-reg280; T reg522=0.5*reg76;
    T reg523=reg286+reg408; T reg524=1.5*reg206; T reg525=reg161*reg23; reg237=reg237+reg381; reg381=reg381+reg232;
    T reg526=reg264-reg154; T reg527=reg234+reg285; reg234=reg425+reg234; reg425=2*reg282; T reg528=reg359-reg110;
    T reg529=reg427+reg426; reg200=reg248+reg200; T reg530=1.5*reg146; reg339=reg342+reg339; reg342=2*reg198;
    T reg531=reg269-reg153; reg376=reg376+reg265; T reg532=reg307+reg390; reg240=reg265+reg240; reg169=reg258+reg169;
    reg258=reg447-reg305; reg133=reg379+reg133; reg327=reg155+reg327; reg147=reg235+reg147; reg155=reg388-reg247;
    reg337=reg337+reg283; reg336=reg330+reg336; reg357=reg347+reg357; reg412=reg330+reg412; reg181=reg283+reg181;
    reg229=reg229-reg135; reg265=reg73-reg384; reg283=reg253-reg363; reg76=6*reg76; reg398=reg398-reg233;
    reg292=reg250+reg292; reg397=reg348+reg397; reg250=reg396-reg59; reg330=elem.pos(0)[2]*reg68; reg97=reg251+reg97;
    reg347=1.5*reg372; reg46=reg46*reg161; reg348=2*reg12; reg114=reg114+reg444; reg444=reg159+reg444;
    reg159=reg395+reg423; reg379=reg224-reg431; reg214=reg214+reg271; reg220=reg344+reg220; reg394=reg394-reg300;
    T reg533=reg411-reg401; T reg534=reg404-reg279; reg171=reg315+reg171; reg131=reg271+reg131; reg271=reg248+reg120;
    reg424=reg158+reg424; reg158=reg341+reg158; reg315=5*reg245; reg392=reg392-reg269; reg341=reg443-reg359;
    T reg535=reg163-reg264; reg152=reg144+reg152; reg144=5*reg191; T reg536=3*reg325; reg370=6*reg370;
    T reg537=reg247-reg338; T reg538=5*reg192; T reg539=reg302+reg270; reg131=reg214+reg131; reg222=reg222-reg153;
    reg214=reg246-reg484; T reg540=1.5*reg249; T reg541=reg73+reg520; reg434=reg433+reg434; reg362=0.5*reg362;
    reg433=reg468-reg359; T reg542=2*reg327; T reg543=reg319-reg169; reg432=reg194+reg432; T reg544=2*reg271;
    T reg545=2*reg199; T reg546=reg333+reg513; reg340=reg340-reg379; T reg547=reg521-reg280; reg344=reg344+reg220;
    reg518=reg43+reg518; reg43=reg268+reg511; T reg548=2*reg263; T reg549=reg404+reg295; T reg550=reg225+reg58;
    T reg551=0.66666666666666666668*reg282; reg220=2*reg220; T reg552=reg394+reg497; T reg553=8*reg149; T reg554=reg534+reg404;
    T reg555=reg227-reg109; T reg556=reg187-reg279; T reg557=reg326+reg407; T reg558=reg211+reg289; T reg559=reg461-reg457;
    reg424=reg158+reg424; reg358=reg356+reg358; reg158=reg218-reg439; reg356=2*reg499; reg285=reg285+reg527;
    reg527=reg234+reg527; reg403=reg405+reg403; reg234=reg382-reg167; reg515=reg515-reg406; reg388=reg388+reg155;
    reg237=reg237+reg381; reg405=8*reg190; reg437=reg346+reg437; T reg560=reg425-reg246; T reg561=2*reg465;
    T reg562=reg486+reg436; reg31=reg31*reg161; T reg563=reg422-reg355; T reg564=elem.pos(0)[1]*reg89; T reg565=8*reg274;
    reg468=reg468+reg374; T reg566=8*reg282; reg525=reg194+reg525; reg194=reg144-reg236; reg318=reg318-reg253;
    T reg567=reg262-reg347; T reg568=reg533-reg401; T reg569=reg524-reg175; T reg570=reg286+reg523; T reg571=reg266+reg517;
    reg509=reg509-reg416; T reg572=8*reg352; T reg573=reg335+reg479; reg441=reg441-reg500; T reg574=reg201-reg152;
    T reg575=reg430-reg260; T reg576=reg510-reg238; reg440=reg440+reg502; reg265=reg265-reg384; T reg577=reg512-reg504;
    T reg578=2*reg160; reg301=reg335+reg301; T reg579=reg505-reg316; T reg580=2*reg523; reg397=reg501+reg397;
    T reg581=reg64*reg98; T reg582=reg250-reg59; reg142=reg142+reg506; reg128=0.5*reg128; T reg583=reg244+reg507;
    reg330=reg46+reg330; reg375=reg243+reg375; reg72=reg72-reg413; reg497=reg275+reg497; reg46=reg366-reg348;
    reg290=reg290+reg294; reg243=reg199-reg284; reg294=reg241+reg294; reg241=1.5*reg391; T reg584=0.66666666666666666668*reg149;
    reg498=reg498-reg481; T reg585=reg406-reg293; T reg586=reg480-reg110; reg299=reg392+reg299; T reg587=reg377+reg76;
    T reg588=1.5*reg137; reg283=reg283-reg363; T reg589=reg17*reg98; reg15=reg15*reg161; T reg590=elem.pos(0)[2]*reg89;
    T reg591=reg272+reg514; reg398=reg398-reg233; reg502=reg502-reg452; reg317=reg320+reg317; reg320=reg522-reg148;
    reg504=reg504-reg230; reg409=reg409+reg503; reg503=reg291+reg503; T reg592=reg175-reg519; T reg593=2*reg276;
    reg181=reg337+reg181; reg337=reg287-reg419; reg228=reg228+reg176; reg176=2*reg176; reg395=reg395+reg159;
    T reg594=1.5*reg210; reg508=reg506+reg508; reg506=2.5*reg209; reg136=reg136-reg478; reg378=reg296+reg378;
    reg296=reg288+reg178; reg444=reg114+reg444; reg159=reg423+reg159; reg114=reg363-reg368; T reg595=reg353+reg496;
    T reg596=0.66666666666666666668*reg180; T reg597=reg416-reg357; T reg598=reg326+reg466; T reg599=8*reg180; T reg600=reg383-reg230;
    T reg601=reg184-reg366; reg510=reg510+reg97; reg193=0.5*reg193; T reg602=reg268+reg464; reg172=reg257+reg172;
    reg492=reg492-reg130; reg200=reg471+reg200; reg257=reg516-reg476; T reg603=2*reg182; reg127=reg127-reg261;
    T reg604=reg67+reg462; reg347=reg347-reg314; T reg605=reg487-reg316; T reg606=reg251+reg489; reg146=0.5*reg146;
    T reg607=reg490-reg382; T reg608=reg258-reg305; T reg609=reg450-reg309; reg361=reg361-reg431; reg449=reg449-reg531;
    T reg610=reg384-reg304; T reg611=reg13*reg98; T reg612=reg453-reg256; T reg613=reg456-reg328; reg81=reg126+reg81;
    reg364=reg373+reg364; reg126=1.5*reg186; reg418=reg418-reg324; reg373=reg341-reg528; T reg614=2*reg147;
    reg414=reg360+reg414; reg155=reg155-reg537; T reg615=reg288+reg493; reg476=reg476-reg313; T reg616=reg482-reg312;
    reg147=reg235+reg147; reg235=2*reg270; T reg617=reg323+reg455; reg386=reg386+reg132; reg349=reg350+reg349;
    reg350=0.66666666666666666668*reg274; T reg618=reg307+reg532; T reg619=2.5*reg191; T reg620=reg110-reg536; T reg621=reg139-reg312;
    reg148=reg148-reg338; T reg622=reg280-reg207; T reg623=2.5*reg245; T reg624=reg316-reg157; T reg625=reg401-reg488;
    T reg626=reg477-reg401; reg170=reg170-reg154; T reg627=reg454-reg354; T reg628=reg205+reg173; reg240=reg376+reg240;
    reg376=elem.pos(0)[0]*reg89; T reg629=2*reg99; T reg630=2*reg201; T reg631=reg204-reg343; T reg632=reg143+reg303;
    T reg633=2*reg223; T reg634=1.5*reg231; reg289=reg289-reg246; T reg635=0.66666666666666666668*reg352; T reg636=2*reg297;
    reg80=reg351+reg80; reg351=reg230-reg460; reg174=reg174-reg402; reg473=reg472+reg473; reg535=reg535-reg526;
    T reg637=reg329-reg133; reg196=reg267+reg196; reg475=reg475-reg319; reg267=reg275+reg370; T reg638=reg310-reg124;
    reg436=reg225+reg436; T reg639=2*reg140; T reg640=reg339-reg365; T reg641=reg130-reg292; reg278=reg244+reg278;
    reg422=reg422+reg483; reg239=0.5*reg239; reg446=reg446-reg229; T reg642=reg266+reg494; reg75=reg307+reg75;
    reg474=reg472+reg474; reg380=reg85+reg380; reg385=reg385-reg451; reg412=reg336+reg412; reg132=reg132-reg485;
    reg85=reg185-reg59; reg56=reg56*reg161; reg336=reg445-reg175; reg372=0.5*reg372; reg472=reg470-reg421;
    T reg643=reg198+reg342; reg215=reg387+reg215; T reg644=1.5*reg367; T reg645=reg213+reg465; T reg646=2*reg495;
    T reg647=reg92+reg463; T reg648=reg160-reg189; T reg649=reg106+reg277; reg381=reg232+reg381; reg217=reg217-reg399;
    reg232=1.5*reg129; T reg650=reg315-reg538; reg528=reg528-reg110; reg427=reg427+reg529; reg529=reg426+reg529;
    T reg651=1.5*reg168; T reg652=0.66666666666666666668*reg190; T reg653=reg459-reg343; reg445=reg458-reg445; T reg654=2*reg171;
    reg173=reg377+reg173; reg487=reg321+reg487; T reg655=reg333+reg491; T reg656=reg226+reg469; reg533=reg411+reg533;
    T reg657=reg530-reg420; T reg658=reg183+reg467; T reg659=0.83333333333333333337*reg191; T reg660=3*reg172; T reg661=reg357-reg518;
    T reg662=0.66666666666666666668*reg223; reg388=reg155+reg388; reg186=0.5*reg186; reg56=reg376+reg56; reg376=2.5*reg192;
    T reg663=reg201+reg630; T reg664=reg619-reg236; reg193=reg193-reg651; reg446=reg446-reg608; T reg665=reg211+reg558;
    T reg666=1.5*reg308; reg389=0.5*reg389; T reg667=2*reg131; T reg668=reg124-reg399; reg294=reg290+reg294;
    reg290=reg636+reg407; T reg669=reg584-reg633; T reg670=reg568+reg533; reg432=reg525+reg432; reg525=reg239-reg594;
    T reg671=reg600-reg351; T reg672=reg407+reg156; T reg673=reg293-reg403; T reg674=reg544+reg570; T reg675=reg143+reg565;
    T reg676=reg356+reg539; reg168=0.5*reg168; reg564=reg31+reg564; reg173=reg628+reg173; reg585=reg585-reg293;
    reg31=reg478-reg382; T reg677=reg73+reg541; T reg678=reg380-reg317; T reg679=reg542+reg517; T reg680=reg433+reg468;
    T reg681=reg570+reg244; reg299=reg299+reg501; reg215=reg215+reg653; T reg682=reg506-reg457; T reg683=reg425+reg560;
    T reg684=reg636-reg124; T reg685=reg232-reg519; T reg686=reg588-reg460; T reg687=reg402-reg167; T reg688=reg292-reg434;
    reg447=reg631-reg447; reg631=reg635-reg639; reg242=reg242-reg402; T reg689=reg323+reg617; reg633=reg633-reg157;
    T reg690=reg526-reg135; T reg691=0.83333333333333333337*reg245; reg517=reg517-reg269; T reg692=3*reg240; reg409=reg409+reg503;
    reg503=reg291+reg503; reg59=reg501-reg59; reg197=0.5*reg197; reg291=reg399-reg402; reg501=reg636+reg466;
    reg361=reg361-reg622; T reg693=reg539+reg307; T reg694=reg169-reg80; T reg695=reg353+reg595; T reg696=2*reg267;
    T reg697=1.5*reg240; reg252=reg252-reg399; T reg698=reg494+reg273; T reg699=reg404+reg549; T reg700=reg542+reg494;
    T reg701=2*reg587; T reg702=reg596-reg593; reg597=reg597-reg357; reg318=reg318-reg253; T reg703=reg131-reg196;
    reg478=reg217-reg478; reg217=reg404+reg554; T reg704=reg531-reg224; T reg705=reg272+reg591; T reg706=reg211+reg566;
    reg352=0.16666666666666666667*reg352; T reg707=reg373-reg528; reg95=reg95-reg305; reg174=reg174-reg234; T reg708=reg189-reg81;
    T reg709=reg636+reg326; T reg710=reg183+reg658; T reg711=2*reg380; reg531=reg158-reg531; reg158=0.66666666666666666668*reg263;
    T reg712=reg284-reg349; T reg713=0.5*reg172; reg257=reg257-reg476; T reg714=reg548-reg488; T reg715=reg623-reg538;
    T reg716=reg251+reg606; T reg717=reg542-reg439; T reg718=reg654+reg333; T reg719=0.66666666666666666668*reg140; reg180=0.16666666666666666667*reg180;
    T reg720=2*reg166; reg145=reg145-reg167; reg136=reg136-reg607; T reg721=reg152-reg378; T reg722=reg288+reg296;
    reg638=reg638-reg481; reg481=reg481-reg255; T reg723=reg379-reg280; reg379=reg222-reg379; reg372=reg372-reg540;
    reg222=reg128-reg126; T reg724=reg133-reg181; T reg725=reg297-reg124; reg526=reg337-reg526; reg337=10*reg245;
    reg176=reg228+reg176; reg466=reg466-reg369; reg172=1.5*reg172; reg228=reg542+reg266; reg429=reg621-reg429;
    reg621=reg261-reg366; reg261=reg170-reg261; reg170=reg304-reg412; T reg726=reg288+reg615; T reg727=reg419-reg154;
    T reg728=reg171-reg419; reg449=reg449-reg451; reg451=reg451-reg256; T reg729=reg365-reg444; T reg730=reg471-reg216;
    reg418=reg418-reg324; reg393=reg393-reg207; T reg731=reg642+reg499; reg414=reg414+reg616; reg436=reg562+reg436;
    reg641=reg641-reg292; T reg732=reg563+reg422; T reg733=reg321+reg487; T reg734=2*reg164; reg187=reg187+reg556;
    T reg735=2.5*reg208; T reg736=reg154-reg413; reg331=reg331-reg154; reg475=reg475-reg319; T reg737=reg461+reg559;
    reg281=reg85-reg281; reg637=reg637-reg133; reg474=reg473+reg474; reg85=reg499+reg302; reg473=reg450+reg609;
    T reg738=reg626-reg625; T reg739=reg577-reg504; T reg740=reg513+reg248; T reg741=reg505+reg579; reg515=reg515-reg406;
    T reg742=2*reg88; reg437=reg437+reg360; reg312=reg360-reg312; reg360=reg268+reg602; T reg743=reg445-reg336;
    T reg744=reg67+reg604; reg487=reg605+reg487; T reg745=reg654-reg419; T reg746=3*reg424; T reg747=10*reg209;
    T reg748=reg92+reg647; T reg749=reg146-reg634; T reg750=reg109-reg358; reg385=reg385-reg612; reg471=reg655+reg471;
    reg655=2*reg87; reg249=0.5*reg249; T reg751=1.5*reg424; T reg752=reg226+reg656; T reg753=2*reg550;
    T reg754=reg268+reg43; T reg755=reg645+reg335; T reg756=1.5*reg96; T reg757=reg646+reg645; reg548=reg652-reg548;
    reg648=reg648-reg189; T reg758=2*reg165; reg386=reg132+reg386; T reg759=2*reg606; T reg760=reg275+reg267;
    T reg761=elem.pos(0)[2]*reg161; T reg762=reg307+reg618; T reg763=reg539+reg235; reg256=reg71-reg256; reg71=reg198+reg643;
    reg381=reg237+reg381; reg265=reg265-reg384; reg427=reg427+reg529; reg529=reg426+reg529; reg237=reg470+reg472;
    reg560=reg560-reg214; reg426=reg411+reg405; reg285=reg527+reg285; reg527=reg160+reg578; reg398=reg398-reg233;
    reg397=reg397+reg582; reg497=reg552+reg497; T reg764=reg576+reg510; reg417=reg417-reg348; reg533=reg411+reg533;
    T reg765=2*reg581; reg395=reg395+reg159; reg159=reg423+reg159; reg220=reg344+reg220; reg344=reg271+reg286;
    reg424=0.5*reg424; reg423=reg392-reg66; reg392=reg571+reg392; reg571=reg546+reg271; reg283=reg283-reg363;
    reg574=reg574-reg152; T reg766=reg106+reg649; T reg767=reg645+reg561; T reg768=reg335+reg573; T reg769=reg225+reg550;
    T reg770=2*reg656; reg343=reg387-reg343; reg387=reg200+reg387; reg114=reg114-reg368; reg555=reg555-reg109;
    reg127=reg127-reg601; reg320=reg320-reg148; reg200=reg586-reg620; reg301=reg322+reg301; reg322=reg551-reg603;
    T reg771=2*reg179; T reg772=0.66666666666666666668*reg99; T reg773=2*reg611; reg240=0.5*reg240; reg367=0.5*reg367;
    T reg774=1.5*reg325; T reg775=reg272+reg599; reg640=reg640-reg365; reg75=reg396+reg75; reg147=reg614+reg147;
    reg57=reg57-reg413; reg530=reg530+reg657; reg396=reg413-reg348; reg614=elem.pos(0)[0]*reg161; reg305=reg229-reg305;
    reg229=reg535-reg229; reg278=reg334+reg278; reg610=reg610-reg304; reg231=0.5*reg231; reg334=reg143+reg632;
    reg535=reg346-reg298; reg346=reg598+reg346; reg598=0.66666666666666666668*reg182; reg492=reg492-reg130; reg210=0.5*reg210;
    reg118=reg118-reg260; T reg776=reg241-reg536; reg362=reg362-reg644; reg243=reg243-reg284; reg72=reg72-reg46;
    T reg777=reg144+reg194; reg543=reg543-reg169; T reg778=2.5*reg400; T reg779=reg431-reg207; reg340=reg340-reg547;
    reg219=reg219-reg431; T reg780=reg244+reg583; reg567=reg567-reg347; T reg781=reg368-reg330; T reg782=reg569-reg592;
    reg626=reg477+reg626; T reg783=reg153-reg431; reg203=0.5*reg203; reg123=reg123-reg153; T reg784=reg377+reg587;
    T reg785=2*reg658; T reg786=reg199+reg545; T reg787=reg557+reg495; T reg788=reg491-reg264; reg491=reg654+reg491;
    reg274=0.16666666666666666667*reg274; reg508=reg142+reg508; reg142=reg495+reg213; T reg789=reg375-reg364; T reg790=reg315+reg650;
    T reg791=0.83333333333333333337*reg209; reg603=reg603-reg484; T reg792=reg350-reg629; T reg793=reg67+reg572; T reg794=reg321+reg553;
    reg558=reg289+reg558; T reg795=2*reg100; T reg796=0.66666666666666666668*reg276; T reg797=2*reg589; reg440=reg502+reg440;
    reg260=reg500-reg260; reg500=reg498-reg500; reg590=reg15+reg590; reg15=2*reg375; reg456=reg456+reg613;
    reg498=reg327-reg439; T reg798=reg439-reg153; T reg799=elem.pos(0)[1]*reg161; reg441=reg441-reg575; T reg800=10*reg191;
    T reg801=reg454+reg627; reg509=reg509-reg416; T reg802=reg570+reg580; T reg803=reg654+reg513; reg579=reg579-reg624;
    T reg804=0.83333333333333333337*reg208; T reg805=reg314-reg519; reg174=reg174/2; T reg806=reg587+reg183; reg673=reg673-reg357;
    T reg807=reg644-reg536; reg644=reg231-reg644; reg231=reg798-reg153; T reg808=0.66666666666666666668*reg381; T reg809=reg692+reg404;
    reg723=reg379-reg723; reg431=reg783-reg431; reg379=reg802+reg780; reg765=reg581+reg765; T reg810=reg753+reg769;
    reg341=reg443+reg341; reg258=reg447-reg258; reg443=reg549+reg267; reg783=reg123-reg783; reg278=reg459+reg278;
    reg123=reg181-reg474; reg447=reg692+reg549; reg459=reg378-reg434; T reg811=reg317-reg378; T reg812=reg330-reg761;
    T reg813=0.20833333333333333334*reg245; T reg814=reg662-reg720; reg480=reg197-reg480; reg184=reg95-reg184; reg585=reg585-reg416;
    reg555=reg555-reg109; reg95=reg352-reg719; reg193=reg193-reg686; T reg815=reg321+reg794; T reg816=reg240-reg594;
    reg594=reg594-reg314; reg798=reg498-reg798; reg301=reg482+reg301; reg482=reg752+reg770; reg483=reg226+reg483;
    reg417=reg417/2; reg694=reg694-reg56; reg257=reg257-reg671; reg635=reg635+reg631; reg243=reg243-reg406;
    reg524=reg389-reg524; reg504=reg502-reg504; reg498=reg144+reg800; reg521=reg256-reg521; reg256=reg636+reg709;
    reg361=reg361/2; T reg817=reg326+reg709; T reg818=reg660+reg268; T reg819=0.16666666666666666667*reg381; T reg820=reg669-reg633;
    T reg821=0.20833333333333333334*reg191; reg283=reg283-reg181; T reg822=0.16666666666666666667*reg285; reg372=reg372-reg685; T reg823=reg158-reg795;
    T reg824=reg623+reg715; T reg825=reg180-reg796; reg492=reg492-reg233; reg529=reg427+reg529; reg59=reg299+reg59;
    reg299=reg353+reg695; reg396=reg57-reg396; reg136=reg136/2; reg355=reg486-reg355; reg159=reg395+reg159;
    reg57=reg267+reg251; reg395=2*reg69; reg260=reg500-reg260; reg661=reg661-reg564; reg374=reg183+reg374;
    reg486=reg602+reg486; reg427=reg412-reg330; reg602=reg660+reg602; reg500=reg444-reg508; T reg826=0.66666666666666666668*reg179;
    reg99=0.16666666666666666667*reg99; reg298=reg535-reg298; T reg827=reg534+reg692; reg535=reg346+reg535; reg724=reg724-reg181;
    reg367=reg367-reg774; reg534=reg534-reg300; reg502=reg456+reg502; reg346=reg461+reg747; reg456=reg176+reg131;
    reg773=reg611+reg773; T reg828=2*reg285; T reg829=reg420-reg338; T reg830=reg751-reg420; T reg831=reg220+reg375;
    T reg832=reg211+reg706; T reg833=reg333+reg718; T reg834=0.66666666666666666668*reg100; reg276=0.16666666666666666667*reg276; reg249=reg249-reg756;
    T reg835=reg464-reg371; T reg836=reg106+reg748; reg464=reg660+reg464; T reg837=reg466-reg369; reg466=reg501+reg466;
    reg501=reg738+reg626; reg703=reg703-reg284; reg779=reg219-reg779; reg219=reg757+reg755; T reg838=reg754+reg753;
    reg383=reg203-reg383; T reg839=reg753+reg752; T reg840=reg67+reg793; T reg841=2*reg794; reg490=reg118-reg490;
    reg118=reg558+reg665; T reg842=reg147-reg317; reg385=reg385/2; reg393=reg393/2; T reg843=reg434-reg80;
    reg750=reg750-reg358; reg210=reg210-reg540; T reg844=reg290+reg672; reg440=reg440+reg739; reg454=reg454+reg801;
    T reg845=reg542+reg717; T reg846=reg156+reg672; T reg847=reg579+reg741; T reg848=4*reg285; T reg849=reg745-reg419;
    T reg850=reg199+reg667; reg745=reg654+reg745; T reg851=reg654+reg718; reg576=reg552+reg576; reg717=reg717-reg439;
    reg515=reg515-reg324; T reg852=reg143+reg334; T reg853=reg692-reg279; reg173=reg173+reg680; reg386=reg386+reg743;
    T reg854=reg660+reg511; reg312=reg437+reg312; reg437=reg511+reg225; T reg855=4*reg381; reg360=reg360+reg562;
    reg441=reg441/2; reg563=reg562+reg563; reg450=reg450+reg473; reg509=reg509-reg358; reg562=reg315+reg790;
    T reg856=reg220-reg364; T reg857=reg746-reg420; reg215=reg215/2; T reg858=reg80-reg614; reg381=2*reg381;
    T reg859=reg147+reg380; reg285=0.66666666666666666668*reg285; reg536=reg338-reg536; T reg860=reg691-reg376; T reg861=reg634-reg338;
    reg708=reg708-reg304; reg475=reg475-reg444; reg634=reg424-reg634; reg413=reg736-reg413; reg736=reg331-reg736;
    reg351=reg476-reg351; reg331=reg92+reg786; T reg862=0.83333333333333333337*reg400; T reg863=reg710+reg785; T reg864=reg701+reg784;
    reg476=reg222-reg476; reg637=reg637-reg133; reg222=reg81-reg412; reg597=reg597-reg432; reg31=reg478-reg31;
    reg478=reg731+reg85; T reg865=reg302+reg85; T reg866=reg106+reg766; reg318=reg318-reg133; T reg867=reg279-reg314;
    T reg868=reg697-reg279; T reg869=reg767+reg768; T reg870=reg542+reg228; T reg871=reg266+reg228; reg519=reg540-reg519;
    reg430=reg429-reg430; reg512=reg428+reg512; reg428=reg358-reg432; reg382=reg345-reg382; reg345=reg727-reg154;
    reg727=reg728-reg727; reg429=reg295+reg275; reg230=reg452-reg230; reg540=reg315+reg337; reg452=reg613-reg452;
    reg728=reg144+reg777; reg613=reg172+reg613; T reg872=reg364-reg81; reg552=reg217+reg552; reg255=reg481-reg255;
    reg481=reg638-reg481; reg418=reg418-reg109; reg217=reg550+reg226; reg638=reg43+reg550; T reg873=reg660+reg43;
    reg712=reg712-reg293; reg414=reg414/2; reg125=0.5*reg125; T reg874=reg746+reg288; T reg875=reg213+reg142;
    reg436=reg436+reg732; T reg876=reg67+reg744; T reg877=reg787+reg142; T reg878=reg323+reg663; T reg879=reg487+reg733;
    reg114=reg114-reg474; T reg880=0.66666666666666666668*reg294; reg453=reg281-reg453; reg281=reg313-reg460; T reg881=reg126-reg313;
    reg126=reg713-reg126; reg402=reg291-reg402; reg291=reg252-reg291; reg252=reg619+reg664; reg343=reg387+reg343;
    reg212=0.5*reg212; reg387=reg701+reg710; reg366=reg221-reg366; reg221=reg349-reg403; T reg882=reg722+reg701;
    T reg883=0.83333333333333333337*reg192; reg336=reg132-reg336; reg359=reg205-reg359; reg132=reg187+reg132; reg460=reg651-reg460;
    reg651=reg186-reg651; reg186=reg674+reg681; reg678=reg678-reg152; reg641=reg641-reg319; reg687=reg242-reg687;
    reg679=reg679+reg517; reg187=3*reg62; reg205=reg615+reg205; reg517=reg517-reg269; reg615=reg746+reg615;
    reg242=reg716+reg759; T reg884=reg684-reg124; reg684=reg636+reg684; T reg885=reg411+reg426; T reg886=reg176-reg196;
    reg721=reg721-reg292; reg530=reg530+reg155; reg458=reg448+reg458; reg640=reg640-reg365; reg448=reg657-reg537;
    reg75=reg250+reg75; reg97=reg251+reg97; reg250=2*reg294; T reg887=reg697+reg556; reg305=reg229-reg305;
    reg229=reg328-reg313; reg610=reg610-reg363; T reg888=reg172-reg328; reg388=reg388+reg707; T reg889=reg668-reg399;
    reg668=reg725-reg668; reg725=reg196-reg349; reg470=reg470+reg237; reg556=reg556-reg485; reg175=reg485-reg175;
    reg485=reg322-reg603; reg350=reg350+reg792; T reg890=reg560+reg683; reg110=reg537-reg110; reg320=reg320-reg200;
    reg127=reg127/2; reg537=2*reg426; reg797=reg589+reg797; T reg891=reg178+reg377; reg596=reg596+reg702;
    T reg892=reg461+reg737; T reg893=4*reg87; T reg894=reg746+reg178; reg781=reg781-reg590; reg72=reg72/2;
    reg362=reg362-reg776; T reg895=reg248+reg740; T reg896=reg274-reg772; T reg897=reg598-reg771; T reg898=reg803+reg740;
    T reg899=0.20833333333333333334*reg209; T reg900=reg160+reg15; T reg901=reg742-reg758; T reg902=reg791-reg735; reg567=reg567-reg782;
    reg340=reg340/2; reg789=reg789-reg189; reg543=reg543-reg508; reg491=reg491+reg788; reg788=reg788-reg264;
    T reg903=reg746+reg493; reg433=reg628+reg433; reg493=reg493-reg247; T reg904=4*reg88; reg280=reg259-reg280;
    reg206=0.5*reg206; reg216=reg730-reg216; reg730=reg471+reg730; reg729=reg729-reg444; reg259=reg403-reg518;
    reg471=reg198+reg689; reg451=reg449-reg451; reg170=reg170-reg368; reg621=reg261-reg621; reg261=0.66666666666666666668*reg166;
    reg749=reg749-reg148; reg620=reg148-reg620; reg140=0.16666666666666666667*reg140; reg628=reg726+reg628; reg148=3*reg162;
    reg168=reg168-reg666; reg449=reg353+reg677; reg648=reg648-reg384; reg145=reg145/2; reg726=reg676+reg693;
    T reg905=reg201+reg711; T reg906=reg548-reg714; T reg907=reg518-reg799; T reg908=reg700+reg698; T reg909=reg273+reg698;
    T reg910=reg699+reg696; T reg911=reg692+reg295; T reg912=reg696+reg716; T reg913=reg655-reg734; T reg914=0.16666666666666666667*reg294;
    T reg915=reg272+reg775; reg503=reg409+reg503; reg409=reg198+reg71; reg224=reg704-reg224; reg265=reg265-reg253;
    reg528=reg155-reg528; reg704=reg531-reg704; reg294=4*reg294; reg155=reg506+reg682; reg574=reg574-reg130;
    reg657=reg751+reg657; reg531=reg527+reg73; reg135=reg690-reg135; reg392=reg392+reg423; reg690=reg526-reg690;
    reg66=reg423-reg66; reg423=reg143+reg675; reg526=2*reg706; reg688=reg688-reg169; reg525=reg525-reg347;
    reg446=reg446/2; reg592=reg347-reg592; reg347=reg296+reg587; T reg916=reg746+reg296; reg398=reg398-reg365;
    reg397=reg397/2; reg497=reg497+reg764; T reg917=reg659-reg778; T reg918=reg272+reg705; T reg919=reg670+reg533;
    T reg920=reg286+reg344; T reg921=reg571+reg344; reg238=reg394-reg238; reg394=reg554+reg394; reg554=reg692+reg554;
    T reg922=reg660-reg328; T reg923=reg763+reg762; T reg924=reg696+reg760; reg811=reg811-reg378; reg338=reg829-reg338;
    T reg925=reg908+reg909; reg829=reg830-reg829; reg697=reg697+reg868; reg830=reg751+reg830; reg751=reg273+reg909;
    reg868=reg868-reg867; reg314=reg867-reg314; reg867=reg268+reg818; T reg926=0.20833333333333333334*reg400; reg214=reg472-reg214;
    T reg927=reg726/2; reg276=reg276-reg834; T reg928=reg381-reg309; reg249=reg249/3; T reg929=reg309-reg488;
    T reg930=1.5*reg162; T reg931=reg144+reg728; T reg932=reg746+reg874; T reg933=reg288+reg874; T reg934=reg106+reg836;
    T reg935=reg758-reg395; T reg936=reg87-reg734; reg588=reg125-reg588; reg125=reg201+reg905; T reg937=reg921+reg920;
    reg596=reg596+reg906; T reg938=2.5*reg159; reg487=reg744+reg487; T reg939=reg599+reg411; reg798=reg798-reg231;
    reg153=reg231-reg153; reg231=reg148-reg187; reg856=reg856-reg364; T reg940=reg915+reg537; reg417=reg812+reg417;
    reg812=0.041666666666666666668*reg503; T reg941=reg855+reg915; reg918=reg918+reg919; reg59=reg59/2; T reg942=reg857-reg420;
    T reg943=reg691+reg860; reg857=reg746+reg857; reg635=reg635+reg820; T reg944=reg461+reg346; T reg945=reg855+reg599;
    reg257=reg257/3; T reg946=2.5*reg529; T reg947=reg910+reg912; T reg948=2*reg765; T reg949=reg421-reg484;
    T reg950=reg429+reg275; reg136=reg597+reg136; reg597=reg692+reg911; reg765=reg581+reg765; reg581=reg660+reg818;
    T reg951=reg828-reg421; T reg952=reg565+reg211; T reg953=reg923/2; T reg954=reg572+reg321; reg569=reg524-reg569;
    reg621=reg621/2; reg524=reg294+reg572; reg140=reg140-reg261; reg575=reg430-reg575; reg430=reg821-reg862;
    reg512=reg577+reg512; reg577=reg225+reg437; T reg955=reg854+reg437; T reg956=0.20833333333333333334*reg192; reg727=reg727-reg345;
    T reg957=reg660+reg854; reg368=reg170-reg368; reg500=reg500-reg508; reg343=reg343/2; reg170=reg156+reg846;
    T reg958=reg844+reg846; T reg959=reg855+reg514; T reg960=reg198+reg471; T reg961=reg827+reg692; T reg962=reg423+reg526;
    reg518=reg259-reg518; reg872=reg872-reg81; reg259=reg199+reg850; reg451=reg451/2; reg66=reg392+reg66;
    reg300=reg534-reg300; reg845=reg845+reg717; reg576=reg552+reg576; reg392=reg659+reg917; reg145=reg907+reg145;
    reg552=reg219/2; reg568=reg591+reg568; reg238=reg394+reg238; reg234=reg382-reg234; reg190=0.16666666666666666667*reg190;
    reg648=reg648-reg384; reg382=reg461+reg892; reg907=reg838+reg839; reg852=reg852+reg118; T reg963=0.041666666666666666668*reg159;
    reg842=reg842-reg317; T reg964=reg294+reg840; T reg965=reg353+reg449; T reg966=reg272+reg915; T reg967=reg294+reg67;
    T reg968=reg432-reg564; reg168=reg168/3; T reg969=reg840+reg841; T reg970=reg315+reg540; reg154=reg345-reg154;
    reg385=reg475+reg385; reg393=reg858+reg393; reg401=reg514-reg401; reg345=reg375+reg831; reg207=reg410-reg207;
    reg886=reg886-reg196; reg620=reg749-reg620; reg394=reg554+reg394; reg750=reg750-reg358; reg586=reg480-reg586;
    reg410=reg746+reg903; reg607=reg490-reg607; reg601=reg184-reg601; reg184=reg347+reg806; reg600=reg383-reg600;
    reg459=reg459-reg434; reg383=5*reg529; reg264=reg788-reg264; reg788=reg491+reg788; reg475=reg916+reg347;
    reg723=reg723/2; reg816=reg816-reg594; reg805=reg594-reg805; reg450=reg450+reg501; reg779=reg779/2;
    reg480=2*reg773; reg789=reg789-reg189; reg592=reg525-reg592; reg490=reg808-reg593; reg491=reg884-reg124;
    reg340=reg543+reg340; reg488=reg593-reg488; reg884=reg684+reg884; reg282=0.16666666666666666667*reg282; reg514=reg379/2;
    reg525=reg526+reg832; reg567=reg567/3; reg543=0.83333333333333333337*reg159; reg554=reg901-reg758; reg593=reg873+reg638;
    reg594=reg638+reg217; reg795=reg796-reg795; reg622=reg280-reg622; reg280=reg294+reg793; reg684=reg877+reg875;
    reg169=reg688-reg169; reg688=reg793+reg794; reg749=reg508-reg56; reg796=reg819-reg796; reg858=reg429+reg911;
    T reg971=reg848+reg334; T reg972=reg92+reg331; reg519=reg210-reg519; reg210=reg143+reg423; T reg973=0.20833333333333333334*reg159;
    reg246=reg303-reg246; reg428=reg428-reg432; T reg974=reg742+reg904; T reg975=reg655+reg893; T reg976=reg864+reg863;
    reg303=reg848+reg303; T reg977=reg619+reg252; reg80=reg843-reg80; reg843=2*reg150; reg247=reg493-reg247;
    reg433=reg628+reg433; reg493=reg903+reg493; reg431=reg783-reg431; reg773=reg611+reg773; reg611=reg248+reg895;
    reg628=reg329+reg299; reg783=reg849-reg419; reg849=reg745+reg849; reg233=reg492-reg233; reg492=6*reg162;
    reg579=reg801+reg579; reg745=reg848+reg675; reg391=0.5*reg391; reg324=reg515-reg324; reg801=reg250+reg801;
    reg504=reg502+reg504; reg348=reg177-reg348; reg558=reg334+reg558; reg177=reg746+reg894; reg312=reg312/2;
    reg608=reg258-reg608; reg446=reg283+reg446; reg258=reg256+reg817; reg283=reg894+reg891; reg260=reg260/2;
    reg334=reg326+reg817; reg502=2*reg797; reg797=reg589+reg797; reg515=reg377+reg891; reg589=reg506+reg155;
    reg563=reg360+reg563; reg416=reg585-reg416; reg360=reg848+reg565; reg744=reg294+reg744; reg591=reg855+reg591;
    reg605=reg604+reg605; reg585=reg655+reg913; reg604=reg294+reg604; reg603=reg792-reg603; reg903=reg150-reg151;
    reg441=reg509+reg441; reg355=reg486+reg355; reg792=reg285+reg792; reg486=reg602+reg486; reg509=reg808+reg702;
    reg602=reg160+reg900; reg386=reg386/3; T reg978=reg899-reg804; reg714=reg702-reg714; reg298=reg535+reg298;
    reg440=reg440/3; reg896=reg896-reg897; reg397=reg398-reg397; reg362=reg362/3; reg398=reg131+reg456;
    reg243=reg243-reg406; reg535=reg660+reg922; reg72=reg781+reg72; reg497=reg497/3; reg702=reg898+reg895;
    reg454=reg454+reg847; reg781=reg924+reg242; T reg979=reg623+reg824; T reg980=reg144+reg498; T reg981=reg848-reg421;
    T reg982=reg67+reg840; T reg983=reg841+reg815; reg255=reg481-reg255; reg470=reg470+reg890; reg481=reg775+reg426;
    reg126=reg126-reg881; T reg984=reg294-reg354; reg281=reg881-reg281; reg712=reg712-reg293; reg612=reg453-reg612;
    reg453=reg675+reg706; reg881=reg880-reg639; reg137=0.5*reg137; reg639=reg639-reg157; reg555=reg555-reg109;
    T reg985=reg323+reg878; reg127=reg114+reg127; reg560=reg237+reg560; reg320=reg320/3; reg114=0.83333333333333333337*reg503;
    reg301=reg616+reg301; reg616=reg380+reg859; reg110=reg448-reg110; T reg986=0.041666666666666666668*reg529; reg483=reg422+reg483;
    reg237=reg828+reg237; reg422=reg882+reg387; reg633=reg631-reg633; reg466=reg466+reg837; T reg987=0.20833333333333333334*reg503;
    reg222=reg222-reg412; T reg988=reg381+reg473; reg703=reg703-reg284; reg738=reg473+reg738; reg472=reg828+reg472;
    reg637=reg637-reg133; reg473=reg855+reg705; reg361=reg694+reg361; reg670=reg705+reg670; reg694=reg478+reg865;
    reg221=reg221-reg403; reg167=reg415-reg167; reg46=reg366-reg46; reg574=reg574-reg130; reg366=reg227+reg866;
    reg241=reg212-reg241; reg624=reg627-reg624; reg625=reg609-reg625; reg627=reg250+reg627; reg212=reg869/2;
    reg609=reg381+reg609; reg415=5*reg503; reg230=reg452-reg230; reg705=reg810+reg482; reg452=reg613+reg452;
    reg402=reg291-reg402; reg313=reg229-reg313; reg291=reg692+reg809; reg357=reg673-reg357; reg613=reg447+reg443;
    reg305=reg305/2; reg673=reg339+reg409; T reg989=reg404+reg809; reg396=reg396/2; reg123=reg123-reg474;
    reg278=reg653+reg278; reg547=reg521-reg547; reg521=reg250-reg354; reg708=reg708-reg304; reg97=reg510+reg97;
    reg724=reg724-reg181; reg374=reg468+reg374; reg468=reg855+reg272; reg510=reg813-reg883; reg157=reg354-reg157;
    reg330=reg427-reg330; reg95=reg95-reg814; reg75=reg582+reg75; reg427=reg443+reg57; reg193=reg193/3;
    reg448=reg657+reg448; reg503=2.5*reg503; reg458=reg445+reg458; reg445=0.20833333333333333334*reg208; reg922=reg922-reg328;
    reg175=reg556-reg175; reg631=reg880+reg631; reg528=reg530+reg528; reg556=reg887+reg556; reg530=0.20833333333333333334*reg529;
    reg351=reg476-reg351; reg129=0.5*reg129; reg640=reg640-reg365; reg99=reg99-reg826; reg725=reg725-reg349;
    reg771=reg772-reg771; reg350=reg350+reg485; reg772=reg822-reg772; reg31=reg31/2; reg224=reg704-reg224;
    reg668=reg668-reg889; reg399=reg889-reg399; reg807=reg644-reg807; reg476=reg791+reg902; reg388=reg388/3;
    reg582=reg855+reg775; reg253=reg265-reg253; reg172=reg172+reg888; reg265=reg870+reg871; reg644=reg266+reg871;
    reg363=reg610-reg363; reg229=reg888-reg229; reg232=reg206-reg232; reg536=reg861-reg536; reg436=reg436/3;
    reg341=reg373+reg341; reg861=reg634-reg861; reg206=reg848+reg632; reg373=reg855-reg309; reg687=reg687/2;
    reg174=reg661+reg174; reg316=reg462-reg316; reg173=reg173/3; reg462=reg294+reg462; reg413=reg736-reg413;
    reg534=reg827+reg534; reg414=reg418-reg414; reg615=reg615+reg205; reg289=reg632+reg289; reg418=reg537+reg885;
    reg610=reg853-reg279; reg729=reg729-reg444; reg372=reg372/3; reg632=reg851+reg833; reg634=reg186/2;
    reg653=reg333+reg833; reg135=reg690-reg135; reg215=reg318-reg215; reg318=reg315+reg562; reg529=0.83333333333333333337*reg529;
    reg657=reg848+reg143; reg484=reg629-reg484; reg661=reg73+reg531; reg149=0.16666666666666666667*reg149; reg159=5*reg159;
    reg367=reg367/3; reg629=reg285-reg629; reg678=reg678-reg152; reg359=reg205+reg359; reg876=reg876+reg879;
    reg319=reg641-reg319; reg460=reg651-reg460; reg717=reg717-reg439; reg721=reg721-reg292; reg369=reg837-reg369;
    reg205=reg474-reg590; reg216=reg730+reg216; reg336=reg132+reg336; reg132=reg848+reg423; reg720=reg719-reg720;
    reg269=reg517-reg269; reg517=reg679+reg517; reg641=reg660+reg464; reg719=reg914-reg719; reg825=reg825-reg823;
    reg464=reg464+reg835; reg651=2*reg50; reg853=reg692+reg853; reg371=reg835-reg371; reg679=reg150+reg843;
    reg690=reg953-reg673; reg585=reg585+reg554; reg685=reg232-reg685; reg358=reg750-reg358; reg232=reg148+reg231;
    reg704=reg855+reg582; reg508=reg500-reg508; reg500=reg294+reg280; reg730=reg651-reg734; reg365=reg640-reg365;
    reg807=reg807/3; reg216=reg216/2; reg621=reg368+reg621; reg547=reg547/2; reg368=reg280+reg688;
    reg158=reg190-reg158; reg444=reg729-reg444; reg771=reg772-reg771; reg319=reg451+reg319; reg451=reg73+reg661;
    reg640=reg415+reg318; reg729=reg986-reg445; reg903=reg903-reg151; reg620=reg620/3; reg367=reg417+reg367;
    reg432=reg428-reg432; reg386=reg385-reg386; reg385=reg593+reg594; reg417=reg210+reg525; reg428=reg613+reg427;
    reg533=reg411+reg533; reg350=reg350/4; reg876=reg876/4; reg433=reg433/3; reg519=reg519/3;
    reg736=reg383-reg457; reg669=reg584+reg669; reg671=reg600-reg671; reg872=reg872-reg81; reg777=reg159+reg777;
    reg97=reg764+reg97; reg741=reg505+reg741; reg505=reg159+reg498; reg607=reg607/2; reg305=reg363+reg305;
    reg396=reg330+reg396; reg330=reg938+reg977; reg343=reg253-reg343; reg773=reg480+reg773; reg253=reg148+reg492;
    reg363=1.5*reg54; reg278=reg278/2; reg480=reg975+reg974; reg584=reg50-reg734; reg600=reg415+reg540;
    reg575=reg575/2; reg750=reg734-reg395; reg764=reg529+reg476; reg450=reg450/4; reg374=reg680+reg374;
    reg458=reg743+reg458; reg680=reg848+reg981; reg436=reg414+reg436; reg99=reg99/4; reg80=reg779+reg80;
    reg512=reg739+reg512; reg75=reg75/2; reg421=reg981-reg421; reg66=reg66/2; reg665=reg211+reg665;
    reg414=reg651+reg913; reg739=reg582+reg481; reg913=reg913-reg758; reg743=reg151-reg68; reg772=reg746+reg857;
    reg289=reg206+reg289; reg776=reg241-reg776; reg936=reg936-reg935; reg857=reg857+reg942; reg241=reg694/2;
    reg779=reg781/3; reg598=reg282-reg598; reg827=3*reg54; reg420=reg942-reg420; reg835=reg159+reg931;
    reg856=reg856-reg364; reg562=reg415+reg562; reg487=reg744+reg487; reg744=reg212-reg366; reg837=reg966+reg418;
    reg887=reg937/2; reg888=reg848+reg360; reg413=reg413/2; reg782=reg569-reg782; reg563=reg563/3;
    reg765=reg948+reg765; reg569=reg963-reg926; reg889=reg360+reg952; reg205=reg205-reg590; reg626=reg477+reg626;
    reg477=reg108-reg138; reg336=reg336/3; reg830=reg830+reg829; reg412=reg222-reg412; reg276=reg276/4;
    reg338=reg829-reg338; reg222=0.5*reg54; reg829=reg461+reg944; reg130=reg574-reg130; reg738=reg988+reg738;
    reg574=reg383+reg747; reg942=reg828+reg951; reg249=reg393+reg249; reg133=reg637-reg133; reg393=reg930-reg187;
    reg949=reg951-reg949; reg737=reg383+reg737; reg918=reg918/4; reg457=reg946-reg457; reg46=reg46/2;
    reg109=reg555-reg109; reg849=reg849+reg783; reg419=reg783-reg419; reg285=reg285+reg629; reg555=reg503+reg979;
    reg484=reg629-reg484; reg629=reg907/3; reg454=reg454/4; reg301=reg301/2; reg320=reg127+reg320;
    reg164=reg164-reg395; reg735=reg529-reg735; reg127=1.5*reg62; reg483=reg732+reg483; reg440=reg441-reg440;
    reg528=reg528/3; reg733=reg321+reg733; reg804=reg530-reg804; reg441=reg855+reg591; reg637=reg964+reg969;
    reg567=reg340+reg567; reg340=reg160+reg602; reg732=reg415+reg970; reg154=reg727-reg154; reg727=reg651+reg655;
    reg548=reg652+reg548; reg155=reg946+reg155; reg652=reg283+reg515; reg783=reg705/3; reg238=reg394+reg238;
    reg252=reg938+reg252; reg596=reg596/4; reg394=reg177+reg283; reg206=reg848+reg206; reg948=reg552-reg934;
    reg312=reg324-reg312; reg324=reg543+reg392; reg568=reg591+reg568; reg591=2*reg108; reg951=reg982+reg983;
    reg981=reg315+reg970; reg988=reg144+reg980; reg497=reg397+reg497; reg397=reg651+reg893; T reg990=reg893+reg742;
    reg536=reg861-reg536; reg359=reg615+reg359; reg612=reg612/2; reg560=reg237+reg560; reg237=reg702+reg611;
    reg384=reg648-reg384; reg615=reg143+reg657; reg648=reg848+reg657; reg576=reg576/3; reg861=reg333+reg653;
    T reg991=reg632+reg653; T reg992=reg634-reg965; T reg993=reg159-reg236; reg678=reg678-reg152; reg309=reg373-reg309;
    reg687=reg518+reg687; reg373=reg855+reg373; reg173=reg215+reg173; reg279=reg610-reg279; reg610=reg853+reg610;
    reg853=reg692+reg853; reg269=reg517+reg269; reg439=reg717-reg439; reg717=reg845+reg717; reg961=reg961+reg534;
    reg300=reg534+reg300; reg230=reg452+reg230; reg215=reg381+reg609; reg452=reg250+reg627; reg625=reg609+reg625;
    reg624=reg627+reg624; reg403=reg221-reg403; reg715=reg503+reg715; reg670=reg473+reg670; reg664=reg938+reg664;
    reg221=reg828+reg472; reg703=reg703-reg284; reg883=reg987-reg883; reg369=reg466+reg369; reg720=reg719-reg720;
    reg641=reg641+reg464; reg371=reg464+reg371; reg464=reg294+reg462; reg316=reg462+reg316; reg462=reg383+reg461;
    reg460=reg460/3; reg650=reg415+reg650; reg686=reg588-reg686; reg466=reg932+reg933; reg662=reg149-reg662;
    reg473=reg746+reg932; reg929=reg928-reg929; reg928=reg381+reg928; reg517=reg201+reg125; reg182=0.16666666666666666667*reg182;
    reg518=reg927-reg960; reg314=reg868-reg314; reg868=reg697+reg868; reg214=reg472+reg214; reg59=reg233-reg59;
    reg811=reg811-reg378; reg233=reg925+reg751; reg472=reg858+reg597; reg534=reg858+reg950; reg588=reg947/3;
    reg257=reg136+reg257; reg136=reg855+reg945; reg635=reg635/4; reg609=reg199+reg259; reg627=reg855+reg959;
    reg697=reg958+reg170; reg719=reg812-reg956; reg845=reg957+reg955; T reg994=reg955+reg577; reg140=reg140/4;
    T reg995=reg294+reg524; T reg996=reg524+reg954; T reg997=reg375+reg345; T reg998=reg415+reg337; T reg999=reg288+reg933;
    reg401=reg959+reg401; reg194=reg159+reg194; reg168=reg145+reg168; reg968=reg968-reg564; reg842=reg842-reg317;
    reg852=reg852/4; reg145=reg383+reg382; reg234=reg234/2; reg236=reg938-reg236; reg564=reg564-reg799;
    reg135=reg135/2; reg959=reg415-reg538; reg167=reg167/2; reg354=reg984-reg354; reg984=reg294+reg984;
    T reg1000=reg745+reg453; reg666=reg137-reg666; reg137=reg383+reg346; reg328=reg922-reg328; reg223=0.16666666666666666667*reg223;
    reg263=0.16666666666666666667*reg263; reg922=reg535+reg922; reg756=reg129-reg756; reg535=reg660+reg535; reg207=reg207/2;
    reg224=reg224/2; reg124=reg491-reg124; reg129=reg56-reg614; reg491=reg884+reg491; reg181=reg724-reg181;
    reg169=reg723+reg169; reg723=reg475+reg184; reg592=reg592/3; reg714=reg509+reg714; reg509=reg131+reg398;
    reg917=reg543+reg917; reg724=reg258+reg334; reg884=reg326+reg334; T reg1001=reg383+reg944; T reg1002=reg848+reg745;
    T reg1003=reg660+reg581; T reg1004=reg581+reg867; T reg1005=reg268+reg867; T reg1006=reg294+reg967; T reg1007=reg973+reg430;
    T reg1008=reg67+reg967; T reg1009=reg132+reg962; reg825=reg825/4; T reg1010=reg415+reg315; T reg1011=reg422/3;
    reg372=reg361+reg372; reg361=reg265+reg644; reg399=reg668-reg399; reg31=reg357+reg31; reg388=reg446-reg388;
    reg725=reg725-reg349; reg351=reg351/3; reg175=reg556+reg175; reg633=reg631+reg633; reg860=reg114+reg860;
    reg357=reg380+reg616; reg376=reg114-reg376; reg110=reg448+reg110; reg446=reg323+reg985; reg639=reg881-reg639;
    reg881=reg880+reg881; reg728=reg159+reg728; reg293=reg712-reg293; reg281=reg126-reg281; reg255=reg255/2;
    reg402=reg402/2; reg470=reg470/4; reg608=reg608/2; reg886=reg886-reg196; reg341=reg707+reg341;
    reg126=reg159+reg144; reg292=reg721-reg292; reg683=reg425+reg683; reg425=reg272+reg468; reg448=reg855+reg468;
    reg538=reg503-reg538; reg193=reg174+reg193; reg157=reg521-reg157; reg95=reg95/4; reg174=reg987+reg510;
    reg521=reg250+reg521; reg304=reg708-reg304; reg556=reg404+reg989; reg631=reg291+reg989; reg668=reg692+reg291;
    reg474=reg123-reg474; reg313=reg229-reg313; reg229=reg172+reg229; reg123=reg266+reg644; reg902=reg529+reg902;
    reg605=reg604+reg605; reg604=reg294+reg604; reg603=reg792+reg603; reg355=reg486+reg355; reg172=reg530+reg978;
    reg298=reg298/2; reg896=reg896/4; reg362=reg72+reg362; reg406=reg243-reg406; reg778=reg543-reg778;
    reg72=reg159+reg980; reg824=reg503+reg824; reg579=reg801+reg579; reg774=reg391-reg774; reg348=reg348/2;
    reg504=reg504/3; reg558=reg971+reg558; reg892=reg383+reg892; reg590=reg590-reg761; reg260=reg416+reg260;
    reg243=reg159+reg800; reg797=reg502+reg797; reg391=reg945+reg939; reg153=reg798-reg153; reg795=reg796-reg795;
    reg622=reg622/2; reg416=reg946+reg589; reg486=reg684/2; reg56=reg749-reg56; reg322=reg551+reg322;
    reg559=reg383+reg559; reg502=reg92+reg972; reg246=reg303+reg246; reg862=reg973-reg862; reg551=reg976/3;
    reg303=reg848+reg303; reg200=reg586-reg200; reg247=reg493+reg247; reg493=reg410+reg493; reg431=reg431/2;
    reg601=reg601/2; reg264=reg788+reg264; reg434=reg459-reg434; reg789=reg789-reg189; reg805=reg816-reg805;
    reg410=reg514-reg628; reg808=reg808+reg490; reg488=reg490-reg488; reg790=reg415+reg790; reg459=reg941+reg940;
    reg682=reg946+reg682; reg490=reg114+reg943; reg671=reg671/3; reg95=reg193+reg95; reg75=reg365-reg75;
    reg374=reg374/3; reg174=reg174/5; reg250=reg250+reg521; reg193=2*reg107; reg278=reg133-reg278;
    reg669=reg820+reg669; reg133=reg631+reg556; reg736=reg383+reg736; reg97=reg97/3; reg365=reg668+reg631;
    reg533=reg919+reg533; reg209=0.041666666666666666668*reg209; reg322=reg485+reg322; reg103=reg103/2; reg313=reg229+reg313;
    reg421=reg680+reg421; reg434=reg431+reg434; reg612=reg444+reg612; reg229=reg159+reg126; reg782=reg782/3;
    reg431=reg233/2; reg341=reg341/3; reg444=reg837/4; reg548=reg906+reg548; reg601=reg474+reg601;
    reg474=reg159+reg988; reg683=reg890+reg683; reg485=reg448+reg425; reg420=reg857+reg420; reg586=reg855+reg448;
    reg99=reg367+reg99; reg607=reg432+reg607; reg538=reg503+reg538; reg729=reg729/5; reg367=0.050000000000000000004*reg773;
    reg432=reg428/3; reg264=reg264/2; reg292=reg224+reg292; reg157=reg521+reg157; reg477=reg477-reg151;
    reg301=reg109-reg301; reg376=reg114+reg376; reg913=reg414+reg913; reg488=reg808+reg488; reg110=reg110/3;
    reg639=reg881+reg639; reg902=reg529+reg902; reg109=reg827+reg232; reg790=reg415+reg790; reg728=reg159+reg728;
    reg214=reg221+reg214; reg585=reg585/2; reg252=reg938+reg252; reg221=reg415+reg981; reg281=reg281/3;
    reg224=reg241-reg446; reg414=reg951/4; reg605=reg604+reg605; reg255=reg293+reg255; reg402=reg403+reg402;
    reg744=reg744-reg783; reg308=0.5*reg308; reg96=0.5*reg96; reg293=reg361+reg123; reg764=reg764/5;
    reg680=reg848+reg680; reg399=reg399/2; reg350=reg320-reg350; reg189=reg789-reg189; reg320=reg380+reg357;
    reg807=reg396+reg807; reg416=reg416/5; reg338=reg830+reg338; reg349=reg725-reg349; reg805=reg805/3;
    reg771=reg771/4; reg351=reg31+reg351; reg378=reg811-reg378; reg804=reg530+reg804; reg31=0.25*reg773;
    reg733=reg879+reg733; reg633=reg633/4; reg175=reg175/3; reg483=reg483/3; reg860=reg114+reg860;
    reg396=reg1004+reg1005; reg403=reg383+reg1001; reg1007=reg1007/5; reg665=reg118+reg665; reg118=reg1009/4;
    reg521=reg294+reg1006; reg559=reg383+reg559; reg530=reg107-reg141; reg604=reg1006+reg1008; reg66=reg130-reg66;
    reg457=reg946+reg457; reg825=reg372+reg825; reg130=reg415+reg600; reg823=reg158-reg823; reg158=reg415+reg1010;
    reg992=reg992-reg1011; reg372=reg159+reg505; reg490=reg490/5; reg707=6.0000000000000000004*reg797; reg626=reg501+reg626;
    reg501=6.0000000000000000004*reg773; reg135=reg304+reg135; reg635=reg257-reg635; reg622=reg56+reg622; reg777=reg159+reg777;
    reg592=reg169+reg592; reg56=reg723/3; reg238=reg238/3; reg169=reg385/3; reg714=reg714/4;
    reg518=reg518-reg588; reg257=reg131+reg509; reg245=0.041666666666666666668*reg245; reg304=reg486-reg502; reg708=3.0000000000000000002*reg773;
    reg712=reg724+reg884; reg685=reg685/3; reg901=reg742+reg901; reg917=reg543+reg917; reg918=reg497-reg918;
    reg795=reg795/4; reg497=reg1003+reg1004; reg835=reg835/5; reg721=reg887-reg451; reg725=reg500+reg368;
    reg862=reg973+reg862; reg410=reg410-reg551; reg756=reg756/3; reg547=reg508+reg547; reg949=reg942+reg949;
    reg12=reg12/2; reg207=reg129+reg207; reg129=0.25*reg765; reg508=reg107+reg679; reg749=reg472+reg534;
    reg124=reg491+reg124; reg247=reg493+reg247; reg200=reg200/3; reg857=reg772+reg857; reg886=reg886-reg196;
    reg433=reg343+reg433; reg690=reg690-reg779; reg519=reg80+reg519; reg608=reg181+reg608; reg942=reg828+reg942;
    reg80=3.0000000000000000002*reg797; reg450=reg386+reg450; reg959=reg415+reg959; reg181=reg704+reg739; reg330=reg330/5;
    reg167=reg564+reg167; reg354=reg984+reg354; reg155=reg946+reg155; reg343=reg827+reg253; reg984=reg294+reg984;
    reg246=reg303+reg246; reg560=reg560/4; reg386=reg855+reg136; reg666=reg666/3; reg491=reg1002+reg1000;
    reg528=reg305-reg528; reg305=reg480/2; reg493=reg383+reg137; reg328=reg922+reg328; reg303=reg848+reg303;
    reg922=reg535+reg922; reg458=reg458/3; reg325=0.5*reg325; reg261=reg223-reg261; reg834=reg263-reg834;
    reg223=reg383+reg574; reg216=reg384-reg216; reg439=reg717+reg439; reg348=reg590+reg348; reg263=reg55-reg138;
    reg384=reg397+reg990; reg269=reg269/2; reg535=reg651+reg730; reg734=reg730-reg734; reg564=reg417/4;
    reg590=reg827-reg187; reg300=reg961+reg300; reg504=reg260-reg504; reg260=reg199+reg609; reg81=reg872-reg81;
    reg717=reg363+reg393; reg730=reg459/4; reg772=reg697/2; reg788=0.050000000000000000004*reg797; reg789=reg855+reg627;
    reg741=reg847+reg741; reg719=reg719/5; reg792=reg150+reg591; reg164=reg164/2; reg796=reg68-reg161;
    reg798=reg222-reg127; reg826=reg182-reg826; reg182=6.0000000000000000004*reg765; reg640=reg640/5; reg419=reg849+reg419;
    reg993=reg159+reg993; reg876=reg436-reg876; reg824=reg503+reg824; reg152=reg678-reg152; reg309=reg373+reg309;
    reg568=reg441+reg568; reg774=reg774/3; reg373=reg855+reg373; reg750=reg584-reg750; reg579=reg579/4;
    reg436=reg138-reg68; reg441=reg237/2; reg279=reg610+reg279; reg187=reg363-reg187; reg610=reg853+reg610;
    reg584=reg827+reg492; reg562=reg415+reg562; reg678=reg655+reg727; reg801=reg637/4; reg194=reg159+reg194;
    reg30=reg30/2; reg842=reg842-reg317; reg808=reg827+reg148; reg948=reg948-reg629; reg682=reg946+reg682;
    reg563=reg312+reg563; reg852=reg173-reg852; reg892=reg383+reg892; reg234=reg968+reg234; reg173=3.0000000000000000002*reg765;
    reg324=reg324/5; reg312=reg136+reg391; reg145=reg145/5; reg236=reg938+reg236; reg596=reg567-reg596;
    reg231=reg827+reg231; reg470=reg388+reg470; reg936=reg936/2; reg686=reg686/3; reg814=reg662-reg814;
    reg487=reg487/4; reg512=reg512/3; reg558=reg558/4; reg388=reg845+reg994; reg575=reg358+reg575;
    reg140=reg168+reg140; reg381=reg381+reg928; reg168=reg159+reg243; reg358=reg294+reg995; reg567=reg848+reg888;
    reg662=reg995+reg996; reg811=reg375+reg997; reg929=reg928+reg929; reg743=reg743-reg89; reg620=reg621+reg620;
    reg621=reg55+reg108; reg816=reg415+reg998; reg820=reg466+reg999; reg153=reg153/2; reg828=reg651+reg727;
    reg830=reg473+reg466; reg154=reg154/2; reg847=reg415+reg732; reg401=reg627+reg401; reg627=reg394+reg652;
    reg336=reg319-reg336; reg284=reg703-reg284; reg883=reg987+reg883; reg569=reg569/5; reg720=reg720/4;
    reg896=reg362+reg896; reg737=reg383+reg737; reg369=reg369/2; reg319=reg383+reg829; reg576=reg59+reg576;
    reg314=reg868+reg314; reg59=reg201+reg517; reg289=reg206+reg289; reg371=reg641+reg371; reg206=reg383+reg462;
    reg460=reg687+reg460; reg758=reg88-reg758; reg413=reg412+reg413; reg362=reg294+reg464; reg412=reg159+reg72;
    reg603=reg603/4; reg230=reg230/3; reg191=0.041666666666666666668*reg191; reg641=reg888+reg889; reg897=reg598-reg897;
    reg903=reg903-reg141; reg776=reg776/3; reg598=0.050000000000000000004*reg765; reg355=reg355/3; reg624=reg452+reg624;
    reg670=reg670/4; reg625=reg215+reg625; reg46=reg205+reg46; reg856=reg856-reg364; reg715=reg503+reg715;
    reg172=reg172/5; reg738=reg738/4; reg664=reg938+reg664; reg298=reg406-reg298; reg205=0.25*reg797;
    reg215=reg160+reg340; reg406=reg848+reg648; reg452=reg648+reg615; reg650=reg415+reg650; reg484=reg285+reg484;
    reg454=reg440+reg454; reg555=reg555/5; reg536=reg536/3; reg285=reg991+reg861; reg735=reg529+reg735;
    reg778=reg543+reg778; reg359=reg359/3; reg276=reg249+reg276; reg316=reg464+reg316; reg897=reg897/4;
    reg774=reg348+reg774; reg172=reg896-reg172; reg484=reg484/4; reg249=reg627/3; reg978=reg899+reg978;
    reg348=reg773/6; reg603=reg620-reg603; reg440=reg403/5; reg729=reg99+reg729; reg445=reg209-reg445;
    reg410=reg410+reg564; reg736=reg383+reg736; reg559=reg383+reg559; reg374=reg278+reg374; reg902=reg902/5;
    reg683=reg683/4; reg145=reg852+reg145; reg708=reg708/6; reg776=reg46+reg776; reg264=reg189-reg264;
    reg992=reg992+reg118; reg735=reg529+reg735; reg419=reg419/2; reg367=reg367/6; reg892=reg892/5;
    reg826=reg826/4; reg110=reg135-reg110; reg457=reg946+reg457; reg382=reg461+reg382; reg721=reg721-reg56;
    reg665=reg665/4; reg46=reg285/2; reg341=reg608-reg341; reg99=reg406+reg452; reg558=reg433-reg558;
    reg247=reg247/3; reg560=reg528+reg560; reg200=reg601+reg200; reg289=reg289/4; reg135=reg567+reg641;
    reg189=reg491/4; reg338=reg338/3; reg278=reg383+reg206; reg433=reg383+reg493; reg764=reg350+reg764;
    reg350=reg848+reg680; reg421=reg680+reg421; reg476=reg791+reg476; reg949=reg942+reg949; reg322=reg322/4;
    reg464=reg383+reg223; reg359=reg216+reg359; reg154=reg81+reg154; reg682=reg946+reg682; reg214=reg214/4;
    reg81=reg848+reg406; reg364=reg856-reg364; reg589=reg506+reg589; reg216=reg830+reg820; reg31=reg31/6;
    reg804=reg804/5; reg416=reg470-reg416; reg470=reg501/6; reg506=reg375+reg811; reg528=reg441-reg215;
    reg737=reg383+reg737; reg246=reg303+reg246; reg771=reg807+reg771; reg536=reg413+reg536; reg420=reg857+reg420;
    reg155=reg155/5; reg303=reg319/5; reg166=0.16666666666666666667*reg166; reg650=reg415+reg650; reg823=reg823/4;
    reg719=reg140+reg719; reg788=reg788/6; reg140=reg855+reg586; reg413=reg586+reg485; reg626=reg626/4;
    reg458=reg612-reg458; reg529=reg159+reg229; reg720=reg460+reg720; reg883=reg883/5; reg316=reg362+reg316;
    reg835=reg918+reg835; reg205=reg205/6; reg685=reg622+reg685; reg281=reg402+reg281; reg756=reg207+reg756;
    reg834=reg834/4; reg639=reg639/4; reg926=reg191-reg926; reg376=reg114+reg376; reg371=reg371/3;
    reg114=reg797/6; reg207=reg412/5; reg733=reg733/4; reg173=reg173/6; reg533=reg533/4;
    reg317=reg842-reg317; reg483=reg301+reg483; reg97=reg75+reg97; reg392=reg659+reg392; reg75=reg221/5;
    reg744=reg744+reg414; reg439=reg439/2; reg301=reg474/5; reg279=reg610+reg279; reg690=reg690+reg444;
    reg362=reg855+reg373; reg309=reg373+reg309; reg430=reg821+reg430; reg487=reg563-reg487; reg993=reg159+reg993;
    reg562=reg562/5; reg30=reg799+reg30; reg308=reg308/3; reg373=reg182/6; reg402=reg380+reg320;
    reg460=reg293/2; reg977=reg619+reg977; reg563=reg365+reg133; reg948=reg948+reg801; reg601=reg712/2;
    reg624=reg624/4; reg175=reg292-reg175; reg625=reg625/4; reg292=reg497+reg396; reg664=reg938+reg664;
    reg230=reg255-reg230; reg255=reg294+reg521; reg608=reg521+reg604; reg300=reg300/3; reg670=reg576-reg670;
    reg576=reg415+reg158; reg401=reg789+reg401; reg728=reg728/5; reg666=reg167+reg666; reg194=reg159+reg194;
    reg261=reg261/4; reg956=reg245-reg956; reg174=reg95-reg174; reg860=reg860/5; reg95=reg431-reg59;
    reg167=reg749/3; reg633=reg351-reg633; reg351=reg386+reg312; reg518=reg518+reg730; reg1007=reg825-reg1007;
    reg399=reg349+reg399; reg313=reg313/3; reg157=reg250+reg157; reg250=reg159+reg168; reg538=reg503+reg538;
    reg330=reg450-reg330; reg80=reg80/6; reg369=reg284-reg369; reg196=reg886-reg196; reg124=reg124/2;
    reg640=reg876+reg640; reg714=reg592-reg714; reg917=reg917/5; reg328=reg922+reg328; reg284=reg294+reg984;
    reg354=reg984+reg354; reg715=reg503+reg715; reg979=reg623+reg979; reg959=reg415+reg959; reg741=reg741/4;
    reg512=reg575-reg512; reg349=reg707/6; reg450=reg131+reg257; reg575=reg847/5; reg355=reg298+reg355;
    reg530=reg530-reg141; reg298=reg415+reg130; reg901=reg554+reg901; reg224=reg224-reg432; reg554=reg181/4;
    reg252=reg252/5; reg103=reg614+reg103; reg96=reg96/3; reg738=reg336+reg738; reg100=0.16666666666666666667*reg100;
    reg395=reg165-reg395; reg165=reg159+reg372; reg336=reg827+reg808; reg592=reg828+reg678; reg824=reg824/5;
    reg610=reg108+reg621; reg579=reg504+reg579; reg504=0.5*reg162; reg569=reg276+reg569; reg598=reg598/6;
    reg795=reg519+reg795; reg862=reg862/5; reg129=reg129/6; reg590=reg827+reg590; reg276=reg827+reg584;
    reg935=reg758-reg935; reg568=reg568/4; reg519=reg141-reg89; reg238=reg66+reg238; reg179=0.16666666666666666667*reg179;
    reg777=reg159+reg777; reg66=reg384/2; reg325=reg325/3; reg12=reg761+reg12; reg612=reg150+reg792;
    reg585=reg903-reg585; reg109=reg109/3; reg790=reg415+reg790; reg231=reg827+reg231; reg913=reg913/2;
    reg151=reg477-reg151; reg605=reg605/4; reg304=reg304-reg169; reg717=reg717/3; reg477=reg725/4;
    reg743=reg936+reg743; reg614=reg305-reg508; reg619=reg343/3; reg269=reg152-reg269; reg943=reg691+reg943;
    reg187=reg363+reg187; reg510=reg813+reg510; reg68=reg436-reg68; reg750=reg750/2; reg152=0.66666666666666666668*reg98;
    reg814=reg814/4; reg363=reg107+reg193; reg686=reg234+reg686; reg234=2*reg974; reg782=reg547+reg782;
    reg798=reg798/3; reg796=reg164+reg796; reg164=4*reg98; reg324=reg596+reg324; reg436=reg415+reg816;
    reg555=reg454-reg555; reg454=reg358+reg662; reg547=reg388/3; reg596=reg772-reg260; reg318=reg315+reg318;
    reg548=reg548/4; reg931=reg144+reg931; reg314=reg314/3; reg778=reg543+reg778; reg378=reg153+reg378;
    reg734=reg535+reg734; reg669=reg669/4; reg263=reg263-reg138; reg929=reg381+reg929; reg490=reg635+reg490;
    reg153=2*reg98; reg671=reg607+reg671; reg488=reg488/4; reg381=reg765/6; reg236=reg938+reg236;
    reg805=reg434+reg805; reg434=reg165/5; reg535=reg454/4; reg777=reg777/5; reg596=reg596-reg547;
    reg371=reg369+reg371; reg728=reg670+reg728; reg568=reg238-reg568; reg860=reg633+reg860; reg490=reg490-reg114;
    reg548=reg782-reg548; reg416=reg708+reg416; reg330=reg173+reg330; reg238=reg81+reg99; reg224=reg224+reg554;
    reg650=reg415+reg650; reg715=reg715/5; reg510=reg510/5; reg814=reg686+reg814; reg476=reg476/5;
    reg824=reg579-reg824; reg624=reg230+reg624; reg316=reg316/4; reg322=reg200-reg322; reg200=reg46-reg506;
    reg230=reg216/3; reg369=reg383+reg278; reg605=reg355-reg605; reg392=reg392/5; reg355=reg415+reg436;
    reg790=reg790/5; reg543=reg592/2; reg579=reg108+reg610; reg559=reg383+reg559; reg246=reg246/4;
    reg590=reg827+reg590; reg734=reg734/2; reg138=reg263-reg138; reg247=reg264+reg247; reg153=reg153/4;
    reg187=reg187/3; reg68=reg750+reg68; reg152=reg152/4; reg798=reg796+reg798; reg263=reg107+reg363;
    reg264=reg234/2; reg607=reg148+reg253; reg620=reg164/4; reg902=reg603+reg902; reg603=4*reg50;
    reg622=reg276/3; reg935=reg935/2; reg519=reg519-reg89; reg393=reg930+reg393; reg623=reg66-reg612;
    reg109=reg585+reg109; reg528=reg528-reg249; reg231=reg231/3; reg913=reg151-reg913; reg151=reg135/4;
    reg717=reg743-reg717; reg585=reg383+reg464; reg614=reg614-reg619; reg141=reg530-reg141; reg901=reg901/2;
    reg232=reg148+reg232; reg127=reg504-reg127; reg89=reg89-reg161; reg395=reg395/2; reg530=reg827+reg336;
    reg883=reg720-reg883; reg518=reg518-reg207; reg639=reg281-reg639; reg376=reg376/5; reg721=reg721+reg189;
    reg313=reg399-reg313; reg157=reg157/4; reg538=reg503+reg538; reg281=reg433/5; reg124=reg196-reg124;
    reg328=reg328/3; reg354=reg284+reg354; reg959=reg415+reg959; reg196=reg601-reg450; reg284=reg292/3;
    reg399=reg255+reg608; reg503=reg415+reg576; reg261=reg666+reg261; reg956=reg956/5; reg174=reg205+reg174;
    reg289=reg359-reg289; reg737=reg737/5; reg897=reg776+reg897; reg172=reg31+reg172; reg978=reg978/5;
    reg764=reg764-reg348; reg931=reg931/5; reg533=reg97-reg533; reg690=reg690-reg301; reg155=reg560-reg155;
    reg445=reg445/5; reg826=reg774+reg826; reg977=reg977/5; reg682=reg682/5; reg308=reg30+reg308;
    reg214=reg110+reg214; reg166=reg166/4; reg192=0.041666666666666666668*reg192; reg626=reg458+reg626; reg719=reg719-reg788;
    reg835=reg835-reg373; reg430=reg430/5; reg30=reg159+reg529; reg457=reg946+reg457; reg97=reg140+reg413;
    reg683=reg341+reg683; reg419=reg364-reg419; reg95=reg95-reg167; reg555=reg80+reg555; reg589=reg589/5;
    reg179=reg179/4; reg324=reg324-reg381; reg804=reg771-reg804; reg733=reg483-reg733; reg100=reg100/4;
    reg943=reg943/5; reg421=reg350+reg421; reg410=reg410-reg303; reg669=reg671-reg669; reg325=reg12+reg325;
    reg892=reg558+reg892; reg12=reg351/4; reg110=reg159+reg250; reg992=reg992-reg440; reg318=reg318/5;
    reg1007=reg129+reg1007; reg640=reg640-reg349; reg735=reg735/5; reg420=reg420/3; reg917=reg714+reg917;
    reg926=reg926/5; reg484=reg536-reg484; reg834=reg756+reg834; reg400=0.041666666666666666668*reg400; reg562=reg487+reg562;
    reg979=reg979/5; reg823=reg685+reg823; reg741=reg512+reg741; reg439=reg317-reg439; reg382=reg382/5;
    reg317=reg298/5; reg208=0.041666666666666666668*reg208; reg304=reg304+reg477; reg252=reg738-reg252; reg664=reg664/5;
    reg488=reg805-reg488; reg279=reg279/3; reg194=reg159+reg194; reg862=reg795-reg862; reg309=reg362+reg309;
    reg338=reg154-reg338; reg569=reg569-reg598; reg729=reg729-reg367; reg665=reg374-reg665; reg96=reg103+reg96;
    reg401=reg401/4; reg300=reg269+reg300; reg949=reg949/4; reg145=reg145-reg470; reg236=reg938+reg236;
    reg948=reg948-reg575; reg993=reg159+reg993; reg929=reg929/4; reg103=reg460-reg402; reg154=reg563/3;
    reg314=reg378-reg314; reg744=reg744-reg75; reg736=reg383+reg736; reg625=reg175+reg625; reg778=reg778/5;
    reg528=reg528+reg151; reg175=reg399/4; reg978=reg897-reg978; reg232=reg232/3; reg269=2*reg555;
    reg318=reg733+reg318; reg341=2*reg145; reg721=reg721-reg281; reg948=reg349+reg948; reg917=reg917-reg381;
    reg664=reg625-reg664; reg328=reg124+reg328; reg196=reg196-reg284; reg979=reg741-reg979; reg124=2*reg729;
    reg354=reg354/4; reg127=reg127/3; reg231=reg913+reg231; reg959=reg415+reg959; reg89=reg395+reg89;
    reg166=reg308+reg166; reg804=reg804+reg31; reg382=reg665+reg382; reg744=reg349+reg744; reg993=reg159+reg993;
    reg797=0.0083333333333333333337*reg797; reg682=reg214-reg682; reg690=reg373+reg690; reg977=reg626-reg977; reg510=reg814-reg510;
    reg214=reg585/5; reg279=reg439+reg279; reg445=reg826+reg445; reg155=reg708+reg155; reg309=reg309/4;
    reg765=0.0083333333333333333337*reg765; reg69=reg69/2; reg614=reg620+reg614; reg62=0.5*reg62; reg901=reg141-reg901;
    reg538=reg538/5; reg141=2*reg569; reg157=reg313+reg157; reg992=reg470+reg992; reg735=reg484+reg735;
    reg308=2*reg172; reg926=reg834+reg926; reg376=reg639+reg376; reg717=reg153+reg717; reg313=2*reg330;
    reg518=reg373+reg518; reg350=2*reg835; reg883=reg883+reg205; reg359=reg159+reg30; reg931=reg533+reg931;
    reg362=reg97/4; reg103=reg103-reg154; reg192=reg192/5; reg589=reg683-reg589; reg476=reg322+reg476;
    reg650=reg650/5; reg562=reg562-reg349; reg929=reg314+reg929; reg314=2*reg1007; reg316=reg371-reg316;
    reg100=reg96+reg100; reg824=reg80+reg824; reg96=reg238/4; reg322=reg264-reg263; reg364=reg530/3;
    reg371=reg607/3; reg374=reg110/5; reg778=reg488+reg778; reg378=reg383+reg369; reg179=reg325+reg179;
    reg304=reg304-reg317; reg95=reg95+reg12; reg325=2*reg324; reg736=reg383+reg736; reg421=reg421/4;
    reg519=reg935+reg519; reg943=reg669+reg943; reg395=2*reg174; reg439=reg355/5; reg596=reg596+reg535;
    reg419=reg420+reg419; reg420=2*reg490; reg798=reg798-reg152; reg410=reg470+reg410; reg400=reg400/5;
    reg430=reg823-reg430; reg392=reg548+reg392; reg187=reg68-reg187; reg68=reg543-reg579; reg393=reg393/3;
    reg200=reg200-reg230; reg224=reg224-reg434; reg457=reg457/5; reg728=reg728-reg373; reg860=reg860-reg114;
    reg458=2*reg416; reg109=reg109-reg620; reg483=2*reg719; reg949=reg338+reg949; reg623=reg623-reg622;
    reg956=reg261+reg956; reg261=2*reg55; reg236=reg236/5; reg194=reg194/5; reg401=reg300-reg401;
    reg737=reg289+reg737; reg289=2*reg764; reg559=reg559/5; reg300=reg415+reg503; reg252=reg173+reg252;
    reg734=reg138-reg734; reg790=reg605+reg790; reg138=2*reg640; reg862=reg862+reg129; reg715=reg624-reg715;
    reg892=reg892-reg470; reg208=reg208/5; reg338=6*reg54; reg773=0.0083333333333333333337*reg773; reg590=reg590/3;
    reg777=reg568+reg777; reg484=reg651+reg603; reg902=reg902-reg348; reg246=reg247-reg246; reg247=1.5*reg902;
    reg559=reg246+reg559; reg246=0.5*reg155; reg778=reg778-reg381; reg367=reg445-reg367; reg400=reg100+reg400;
    reg590=reg734+reg590; reg187=reg187+reg153; reg100=reg765/6; reg445=2*reg109; reg737=reg737-reg470;
    reg236=reg929-reg236; reg487=reg55+reg261; reg318=reg318-reg349; reg488=2*reg614; reg978=reg31+reg978;
    reg161=reg69+reg161; reg145=reg145-reg458; reg232=reg901+reg232; reg31=2*reg484; reg69=reg827+reg338;
    reg68=reg68-reg364; reg512=3*reg728; reg533=1.5*reg518; reg536=0.16666666666666666667*reg98; reg548=reg744-reg138;
    reg138=reg138-reg269; reg558=reg458-reg289; reg560=reg350-reg313; reg322=reg322-reg371; reg764=reg764-reg308;
    reg568=reg308-reg124; reg605=1.5*reg892; reg350=reg690-reg350; reg624=3*reg155; reg931=reg931-reg373;
    reg625=1.5*reg948; reg626=3*reg562; reg62=reg62/3; reg430=reg129+reg430; reg381=reg392-reg381;
    reg476=reg476-reg348; reg650=reg316+reg650; reg129=0.5*reg562; reg316=1.5*reg824; reg200=reg200+reg96;
    reg392=3*reg860; reg393=reg519-reg393; reg95=reg95-reg374; reg519=reg378/5; reg330=reg330-reg325;
    reg633=reg325-reg314; reg715=reg80+reg715; reg635=0.5*reg892; reg155=1.5*reg155; reg639=3*reg902;
    reg457=reg949-reg457; reg892=3*reg892; reg659=0.5*reg728; reg665=1.5*reg252; reg666=3*reg917;
    reg788=reg956-reg788; reg669=2*reg717; reg670=reg289-reg308; reg416=reg416-reg289; reg623=reg620+reg623;
    reg671=3*reg862; reg680=reg773/6; reg777=reg777-reg373; reg208=reg179+reg208; reg790=reg790-reg349;
    reg179=1.5*reg917; reg683=0.5*reg252; reg685=3*reg883; reg686=reg314-reg141; reg687=1.5*reg860;
    reg691=0.5*reg824; reg304=reg349+reg304; reg324=reg324-reg314; reg736=reg736/5; reg224=reg373+reg224;
    reg703=reg395-reg483; reg490=reg490-reg395; reg421=reg419-reg421; reg596=reg596-reg439; reg943=reg943-reg114;
    reg555=reg555-reg420; reg419=reg420-reg395; reg714=0.5*reg992; reg348=reg735-reg348; reg598=reg926-reg598;
    reg114=reg376-reg114; reg562=1.5*reg562; reg824=3*reg824; reg518=0.5*reg518; reg376=reg359/5;
    reg103=reg103+reg362; reg720=reg797/6; reg192=reg166+reg192; reg589=reg708+reg589; reg382=reg382-reg470;
    reg993=reg993/5; reg682=reg708+reg682; reg309=reg279-reg309; reg977=reg173+reg977; reg205=reg510+reg205;
    reg835=reg835-reg313; reg166=reg313-reg325; reg528=reg528-reg214; reg728=1.5*reg728; reg252=3*reg252;
    reg127=reg89+reg127; reg89=3*reg804; reg194=reg401+reg194; reg231=reg231-reg620; reg992=1.5*reg992;
    reg279=reg300/5; reg196=reg196+reg175; reg664=reg173+reg664; reg401=reg341-reg458; reg341=reg410-reg341;
    reg959=reg959/5; reg948=0.5*reg948; reg538=reg157-reg538; reg354=reg328-reg354; reg979=reg80+reg979;
    reg157=2*reg798; reg328=reg269-reg420; reg721=reg470+reg721; reg640=reg640-reg269; reg510=reg948-reg562;
    reg733=4*reg737; reg152=reg127-reg152; reg528=reg470+reg528; reg127=reg536/4; reg734=reg401-reg458;
    reg735=reg992-reg892; reg892=reg892-reg624; reg401=reg341-reg401; reg68=reg620+reg68; reg382=reg382-reg589;
    reg161=reg62+reg161; reg62=2*reg721; reg194=reg194-reg373; reg341=reg665-reg666; reg738=reg666-reg671;
    reg741=0.66666666666666666668*reg777; reg743=1.5*reg862; reg917=0.5*reg917; reg750=2*reg664; reg756=4*reg778;
    reg758=4*reg348; reg761=2*reg682; reg771=0.66666666666666666668*reg737; reg774=0.16666666666666666667*reg721; reg141=reg1007-reg141;
    reg103=reg103-reg376; reg776=reg589-reg476; reg993=reg309+reg993; reg309=reg977-reg381; reg782=reg205-reg788;
    reg416=reg416-reg670; reg308=reg670-reg308; reg671=reg179-reg671; reg179=reg683-reg179; reg670=0.16666666666666666667*reg777;
    reg683=0.66666666666666666668*reg664; reg789=2*reg778; reg686=reg324-reg686; reg324=0.16666666666666666667*reg224; reg791=reg430-reg598;
    reg795=reg476-reg978; reg95=reg373+reg95; reg796=reg381-reg430; reg330=reg330-reg633; reg635=reg635-reg155;
    reg314=reg633-reg314; reg155=reg155-reg639; reg633=reg639-reg89; reg665=reg659-reg665; reg659=reg978-reg367;
    reg799=2*reg348; reg805=0.66666666666666666668*reg682; reg807=0.16666666666666666667*reg737; reg813=reg55+reg487; reg814=reg31/2;
    reg821=reg827+reg69; reg145=reg145-reg558; reg558=reg558-reg289; reg823=reg714-reg605; reg605=reg605-reg624;
    reg825=reg624-reg639; reg721=0.66666666666666666668*reg721; reg737=2*reg737; reg826=4*reg682; reg590=reg590-reg620;
    reg100=reg400+reg100; reg124=reg172-reg124; reg835=reg835-reg166; reg166=reg166-reg325; reg172=reg518-reg728;
    reg728=reg728-reg252; reg400=reg252-reg666; reg834=0.66666666666666666668*reg224; reg842=2*reg777; reg849=4*reg664;
    reg89=reg247-reg89; reg247=reg246-reg247; reg173=reg236+reg173; reg931=reg931-reg977; reg568=reg764-reg568;
    reg350=reg350-reg560; reg560=reg560-reg313; reg236=reg533-reg512; reg512=reg512-reg252; reg224=2*reg224;
    reg777=4*reg777; reg395=reg419-reg395; reg419=reg555-reg419; reg246=reg943-reg205; reg322=reg620+reg322;
    reg555=reg625-reg626; reg736=reg421+reg736; reg421=0.16666666666666666667*reg304; reg764=2*reg114; reg852=0.66666666666666666668*reg715;
    reg853=0.16666666666666666667*reg790; reg626=reg626-reg824; reg856=3*reg231; reg857=1.5*reg623; reg868=2*reg304;
    reg872=4*reg790; reg876=reg687-reg685; reg687=reg691-reg687; reg703=reg490-reg703; reg596=reg349+reg596;
    reg559=reg559-reg470; reg650=reg650-reg349; reg200=reg200-reg519; reg490=reg328-reg420; reg328=reg640-reg328;
    reg562=reg562-reg824; reg640=reg824-reg392; reg691=reg979-reg943; reg304=0.66666666666666666668*reg304; reg879=2*reg790;
    reg880=4*reg715; reg881=4*reg114; reg886=3*reg623; reg318=reg318-reg979; reg890=2*reg715;
    reg548=reg548-reg138; reg138=reg138-reg269; reg708=reg457+reg708; reg790=0.66666666666666666668*reg790; reg457=reg488-reg445;
    reg685=reg392-reg685; reg902=0.5*reg902; reg896=1.5*reg804; reg897=reg316-reg392; reg316=reg129-reg316;
    reg109=reg109-reg669; reg720=reg192+reg720; reg80=reg538+reg80; reg232=reg232-reg620; reg129=1.5*reg883;
    reg680=reg208+reg680; reg860=0.5*reg860; reg192=1.5*reg231; reg959=reg354+reg959; reg208=reg614-reg445;
    reg196=reg196-reg279; reg354=reg445-reg669; reg538=3*reg187; reg483=reg174-reg483; reg393=reg153+reg393;
    reg153=0.5*reg623; reg174=reg669-reg157; reg899=0.66666666666666666668*reg348; reg901=reg790-reg890; reg682=0.16666666666666666667*reg682;
    reg350=reg350-reg560; reg560=reg560-reg313; reg635=reg635-reg155; reg633=reg155-reg633; reg155=0.20833333333333333334*reg528;
    reg903=reg774-reg771; reg959=reg959-reg349; reg309=reg309-reg381; reg790=reg421-reg790; reg685=reg897-reg685;
    reg771=reg771-reg761; reg761=reg761-reg758; reg782=reg782-reg788; reg568=reg568/2; reg897=reg316-reg897;
    reg316=5*reg194; reg906=2.5*reg95; reg913=2.5*reg173; reg141=reg141/2; reg918=0.83333333333333333337*reg194;
    reg659=reg659-reg367; reg691=reg691-reg943; reg919=0.20833333333333333334*reg95; reg743=reg917-reg743; reg664=0.16666666666666666667*reg664;
    reg917=0.66666666666666666668*reg778; reg922=reg777-reg849; reg926=2.5*reg80; reg777=reg224-reg777; reg928=0.83333333333333333337*reg650;
    reg929=0.20833333333333333334*reg596; reg890=reg890-reg881; reg930=reg512-reg252; reg512=reg236-reg512; reg935=4*reg68;
    reg236=reg533+reg236; reg533=2.5*reg708; reg936=0.83333333333333333337*reg559; reg938=0.83333333333333333337*reg95; reg367=reg367-reg680;
    reg670=reg670-reg683; reg789=reg683-reg789; reg683=0.20833333333333333334*reg194; reg942=0.83333333333333333337*reg173; reg483=reg483/2;
    reg946=reg728-reg400; reg89=reg247-reg89; reg666=reg400-reg666; reg247=0.20833333333333333334*reg559; reg400=0.83333333333333333337*reg708;
    reg876=reg687-reg876; reg703=reg703/2; reg129=reg860-reg129; reg687=0.041666666666666666668*reg596; reg314=reg330-reg314;
    reg795=reg795-reg978; reg330=reg834-reg842; reg200=reg470+reg200; reg796=reg796-reg430; reg860=reg849-reg756;
    reg842=reg842-reg849; reg949=0.66666666666666666668*reg114; reg715=0.16666666666666666667*reg715; reg95=0.041666666666666666668*reg95; reg756=reg750-reg756;
    reg750=reg741-reg750; reg395=reg419-reg395; reg931=reg931-reg977; reg741=reg324-reg741; reg419=4*reg614;
    reg835=reg835-reg166; reg791=reg791-reg598; reg246=reg246-reg205; reg325=reg166-reg325; reg738=reg341-reg738;
    reg196=reg349+reg196; reg736=reg736-reg470; reg686=reg686/2; reg671=reg179-reg671; reg308=reg416-reg308;
    reg166=0.83333333333333333337*reg80; reg179=0.20833333333333333334*reg650; reg764=reg852-reg764; reg341=reg665-reg341; reg416=5*reg173;
    reg852=reg853-reg852; reg788=reg788-reg720; reg665=2.5*reg194; reg728=reg172-reg728; reg669=reg354-reg669;
    reg172=reg872-reg880; reg872=reg868-reg872; reg853=reg857-reg856; reg956=reg856-reg538; reg961=reg626-reg824;
    reg626=reg555-reg626; reg968=5*reg708; reg971=2*reg68; reg973=4*reg590; reg984=2.5*reg559;
    reg987=0.83333333333333333337*reg528; reg758=reg826-reg758; reg1007=reg737-reg826; reg555=reg625+reg555; reg737=reg721-reg737;
    reg625=reg322-reg232; reg639=reg825-reg639; reg825=reg605-reg825; reg605=reg823-reg605; reg823=reg821/3;
    T reg1012=reg138-reg269; T reg1013=reg814-reg813; reg896=reg902-reg896; reg289=reg558-reg289; reg902=reg393-reg152;
    T reg1014=5*reg559; T reg1015=1.5*reg187; reg231=0.5*reg231; reg174=reg109-reg174; reg109=2.5*reg528;
    T reg1016=reg153-reg192; reg538=reg192-reg538; reg192=reg733-reg826; reg157=reg717-reg157; reg733=reg62-reg733;
    reg717=0.66666666666666666668*reg68; T reg1017=2*reg590; T reg1018=reg892-reg624; reg892=reg735-reg892; reg528=0.041666666666666666668*reg528;
    reg735=reg992+reg735; reg992=reg734-reg458; T reg1019=reg232-reg393; reg734=reg401-reg734; reg382=reg382-reg589;
    reg127=reg161+reg127; reg161=5*reg650; reg401=2.5*reg596; reg124=reg124/2; reg354=reg208-reg354;
    reg596=0.83333333333333333337*reg596; reg208=2.5*reg650; T reg1020=reg304-reg879; reg993=reg993-reg373; T reg1021=5*reg80;
    reg392=reg640-reg392; reg879=reg879-reg880; reg103=reg373+reg103; reg640=reg562-reg640; reg776=reg776-reg476;
    reg881=reg880-reg881; reg562=reg510-reg562; reg598=reg598-reg100; reg799=reg805-reg799; reg420=reg490-reg420;
    reg510=reg488+reg457; reg457=reg457-reg445; reg558=reg145-reg558; reg138=reg548-reg138; reg490=reg328-reg490;
    reg318=reg318-reg979; reg145=reg886-reg856; reg805=reg807-reg805; reg304=reg304+reg1020; reg881=reg879-reg881;
    reg917=reg664-reg917; reg926=reg928-reg926; reg949=reg715-reg949; reg328=reg401-reg161; reg458=reg992-reg458;
    reg483=reg788+reg483; reg548=3.0000000000000000002*reg196; reg992=reg734-reg992; reg879=reg1020-reg879; reg729=reg729/2;
    reg928=reg929-reg928; reg129=reg129/3; reg314=reg314/2; reg161=reg161-reg1021; reg430=reg796-reg430;
    reg382=reg382-reg589; reg664=6.0000000000000000004*reg959; reg715=0.25*reg103; reg913=reg918-reg913; reg918=reg919-reg918;
    reg734=6.0000000000000000004*reg736; reg788=3.0000000000000000002*reg200; reg796=reg1014-reg968; reg1014=reg109-reg1014; reg420=reg490-reg420;
    reg141=reg598+reg141; reg826=reg192-reg826; reg691=reg691-reg943; reg903=reg903-reg771; reg761=reg771-reg761;
    reg756=reg750-reg756; reg192=reg733-reg192; reg750=reg741-reg750; reg562=reg562-reg640; reg733=reg62+reg733;
    reg743=reg743/3; reg490=0.25*reg196; reg738=reg341-reg738; reg624=reg1018-reg624; reg1018=reg892-reg1018;
    reg392=reg640-reg392; reg892=reg735+reg892; reg341=reg987-reg984; reg598=reg155-reg936; reg764=reg852-reg764;
    reg1021=reg208-reg1021; reg640=reg687-reg179; reg758=reg1007-reg758; reg166=reg179-reg166; reg179=3.0000000000000000002*reg959;
    reg308=reg308/2; reg671=reg671/3; reg1007=reg737-reg1007; reg735=0.050000000000000000004*reg196; reg741=0.25*reg959;
    reg686=reg791+reg686; reg633=reg635-reg633; reg804=0.5*reg804; reg737=reg721+reg737; reg790=reg790-reg901;
    reg639=reg825-reg639; reg205=reg246-reg205; reg825=reg605-reg825; reg269=reg1012-reg269; reg318=reg318-reg979;
    reg395=reg395/2; reg1012=reg138-reg1012; reg289=reg558-reg289; reg685=reg897-reg685; reg194=0.041666666666666666668*reg194;
    reg650=0.041666666666666666668*reg650; reg138=0.20833333333333333334*reg80; reg569=reg569/2; reg978=reg795-reg978; reg880=reg172-reg880;
    reg246=0.20833333333333333334*reg173; reg558=0.66666666666666666668*reg590; reg890=reg901-reg890; reg703=reg782+reg703; reg172=reg872-reg172;
    reg862=0.5*reg862; reg872=reg868+reg872; reg876=reg876/3; reg776=reg776-reg476; reg605=0.25*reg993;
    reg635=0.050000000000000000004*reg103; reg942=reg683-reg942; reg824=reg961-reg824; reg721=0.25*reg200; reg683=reg95-reg683;
    reg961=reg626-reg961; reg789=reg670-reg789; reg533=reg936-reg533; reg626=reg555+reg626; reg555=3.0000000000000000002*reg736;
    reg968=reg984-reg968; reg208=reg596-reg208; reg568=reg659+reg568; reg860=reg842-reg860; reg559=0.041666666666666666668*reg559;
    reg236=reg236+reg512; reg659=0.16666666666666666667*reg68; reg1017=reg717-reg1017; reg670=reg935-reg973; reg771=reg316-reg416;
    reg782=2*reg322; reg538=reg1016-reg538; reg325=reg835-reg325; reg1013=reg1013-reg823; reg623=6*reg623;
    reg791=0.25*reg736; reg842=reg330-reg842; reg902=reg902-reg152; reg445=reg457-reg445; reg313=reg560-reg313;
    reg560=reg350-reg560; reg350=reg528-reg247; reg400=reg247-reg400; reg728=reg728-reg946; reg666=reg946-reg666;
    reg316=reg906-reg316; reg157=reg157/2; reg457=reg510+reg457; reg856=reg145-reg856; reg247=0.20833333333333333334*reg708;
    reg896=reg896/3; reg510=0.050000000000000000004*reg200; reg330=reg834+reg330; reg795=reg488+reg419; reg807=reg224+reg777;
    reg834=3.0000000000000000002*reg103; reg956=reg853-reg956; reg416=reg665-reg416; reg777=reg777-reg922; reg152=reg152-reg127;
    reg1019=reg1019-reg393; reg799=reg805-reg799; reg805=3.0000000000000000002*reg993; reg931=reg931-reg977; reg665=reg938-reg665;
    reg973=reg971-reg973; reg367=reg124+reg367; reg1015=reg231-reg1015; reg512=reg512-reg930; reg89=reg89/3;
    reg174=reg174/2; reg309=reg309-reg381; reg124=6.0000000000000000004*reg993; reg899=reg682-reg899; reg849=reg922-reg849;
    reg669=reg354-reg669; reg252=reg930-reg252; reg853=reg857+reg853; reg625=reg625-reg232; reg719=reg719/2;
    reg145=reg886+reg145; reg883=0.5*reg883; reg626=reg626+reg961; reg348=0.16666666666666666667*reg348; reg231=reg488+reg795;
    reg354=reg872+reg172; reg862=reg862/3; reg625=reg625-reg232; reg166=reg640-reg166; reg805=reg103-reg805;
    reg640=0.0083333333333333333337*reg103; reg308=reg978+reg308; reg671=reg686+reg671; reg669=reg669/2; reg771=reg316-reg771;
    reg741=reg735-reg741; reg778=0.16666666666666666667*reg778; reg420=reg420/2; reg1013=reg1013+reg620; reg824=reg961-reg824;
    reg316=reg906+reg316; reg682=reg886+reg623; reg686=reg490-reg959; reg849=reg777-reg849; reg835=reg721-reg736;
    reg798=reg798/2; reg968=reg341-reg968; reg236=reg236+reg512; reg252=reg512-reg252; reg777=reg807+reg777;
    reg341=reg987+reg341; reg917=reg917/4; reg558=reg659-reg558; reg890=reg790-reg890; reg973=reg971+reg973;
    reg926=reg928-reg926; reg512=0.050000000000000000004*reg993; reg807=reg224+reg807; reg246=reg194-reg246; reg928=reg929+reg928;
    reg737=reg737+reg1007; reg758=reg1007-reg758; reg194=2*reg795; reg931=reg931-reg977; reg395=reg205+reg395;
    reg205=reg322+reg782; reg224=reg886+reg145; reg796=reg1014-reg796; reg685=reg685/3; reg956=reg853+reg956;
    reg856=reg145+reg856; reg943=reg691-reg943; reg62=reg62+reg733; reg538=reg538/3; reg639=reg825-reg639;
    reg313=reg560-reg313; reg633=reg633/3; reg743=reg141+reg743; reg555=reg200-reg555; reg187=0.5*reg187;
    reg670=reg935+reg670; reg155=reg155+reg598; reg533=reg598-reg533; reg883=reg883/3; reg141=0.0083333333333333333337*reg196;
    reg664=reg548-reg664; reg157=reg152+reg157; reg145=reg596+reg208; reg666=reg728-reg666; reg314=reg430+reg314;
    reg179=reg196-reg179; reg129=reg483+reg129; reg161=reg328-reg161; reg949=reg949/4; reg476=reg776-reg476;
    reg152=0.0083333333333333333337*reg200; reg330=reg330+reg842; reg860=reg842-reg860; reg430=0.050000000000000000004*reg736; reg289=reg289/2;
    reg919=reg919+reg918; reg892=reg892+reg1018; reg318=reg318-reg979; reg899=reg899/4; reg381=reg309-reg381;
    reg1017=reg717+reg1017; reg382=reg382-reg589; reg393=reg1019-reg393; reg761=reg903-reg761; reg445=reg457+reg445;
    reg1021=reg208-reg1021; reg756=reg750-reg756; reg624=reg1018-reg624; reg174=reg902+reg174; reg826=reg192-reg826;
    reg734=reg788-reg734; reg799=reg799/4; reg738=reg738/3; reg325=reg325/2; reg719=reg720+reg719;
    reg872=reg868+reg872; reg605=reg635-reg605; reg208=reg715-reg993; reg89=reg568+reg89; reg124=reg834-reg124;
    reg942=reg683-reg942; reg569=reg100+reg569; reg68=8*reg68; reg458=reg992-reg458; reg269=reg1012-reg269;
    reg789=reg789/4; reg192=reg733+reg192; reg880=reg172-reg880; reg876=reg703+reg876; reg100=reg938+reg665;
    reg392=reg562-reg392; reg416=reg665-reg416; reg764=reg764/4; reg729=reg680+reg729; reg138=reg650-reg138;
    reg114=0.16666666666666666667*reg114; reg304=reg879+reg304; reg328=reg401+reg328; reg172=0.050000000000000000004*reg959; reg881=reg879-reg881;
    reg247=reg559-reg247; reg1015=reg1015/3; reg791=reg510-reg791; reg1014=reg109+reg1014; reg400=reg350-reg400;
    reg896=reg367+reg896; reg913=reg918-reg913; reg804=reg804/3; reg445=reg445/2; reg926=reg928+reg926;
    reg62=reg62+reg192; reg804=reg729+reg804; reg179=reg196+reg179; reg917=reg743+reg917; reg173=0.041666666666666666668*reg173;
    reg309=reg109+reg1014; reg269=reg269/2; reg392=reg392/3; reg771=reg316+reg771; reg420=reg943+reg420;
    reg124=reg834+reg124; reg896=reg899+reg896; reg316=reg906+reg316; reg304=reg881+reg304; reg289=reg476+reg289;
    reg348=reg348/4; reg232=reg625-reg232; reg856=reg224+reg856; reg639=reg639/3; reg979=reg318-reg979;
    reg849=reg777+reg849; reg826=reg192+reg826; reg596=reg596+reg145; reg686=reg490+reg686; reg1021=reg145+reg1021;
    reg798=reg127+reg798; reg777=reg807+reg777; reg605=reg635+reg605; reg89=reg799+reg89; reg942=reg942/5;
    reg127=reg935+reg68; reg789=reg671+reg789; reg880=reg354+reg880; reg938=reg938+reg100; reg416=reg100+reg416;
    reg764=reg876+reg764; reg862=reg569+reg862; reg166=reg166/5; reg805=reg103+reg805; reg756=reg756/4;
    reg590=0.16666666666666666667*reg590; reg1017=reg1017/4; reg741=reg735+reg741; reg824=reg626+reg824; reg778=reg778/4;
    reg80=0.041666666666666666668*reg80; reg325=reg381+reg325; reg664=reg548+reg664; reg738=reg314+reg738; reg666=reg666/3;
    reg430=reg152-reg430; reg734=reg788+reg734; reg161=reg328+reg161; reg949=reg129+reg949; reg860=reg330+reg860;
    reg624=reg892+reg624; reg761=reg761/4; reg328=reg401+reg328; reg138=reg138/5; reg172=reg141-reg172;
    reg247=reg247/5; reg791=reg510+reg791; reg400=reg400/5; reg589=reg382-reg589; reg872=reg354+reg872;
    reg670=reg935+reg670; reg114=reg114/4; reg533=reg155+reg533; reg208=reg715+reg208; reg968=reg341+reg968;
    reg835=reg721+reg835; reg956=reg956/3; reg458=reg458/2; reg341=reg987+reg341; reg100=0.20833333333333333334*reg1013;
    reg558=reg558/4; reg252=reg236+reg252; reg1015=reg157+reg1015; reg512=reg640-reg512; reg973=reg971+reg973;
    reg246=reg246/5; reg758=reg737+reg758; reg890=reg890/4; reg129=2*reg682; reg145=reg886+reg682;
    reg669=reg393+reg669; reg155=reg194+reg231; reg977=reg931-reg977; reg157=reg322+reg205; reg796=reg1014+reg796;
    reg685=reg395+reg685; reg192=0.83333333333333333337*reg1013; reg187=reg187/3; reg538=reg174+reg538; reg708=0.041666666666666666668*reg708;
    reg883=reg719+reg883; reg555=reg200+reg555; reg913=reg919+reg913; reg313=reg313/2; reg633=reg308+reg633;
    reg1017=reg538-reg1017; reg445=reg232-reg445; reg458=reg589+reg458; reg664=reg548+reg664; reg192=reg192/5;
    reg973=reg973/4; reg758=reg758/4; reg956=reg669-reg956; reg968=reg341+reg968; reg174=2.5*reg1013;
    reg269=reg979+reg269; reg639=reg289+reg639; reg555=reg200+reg555; reg187=reg798+reg187; reg224=0.041666666666666666668*reg1013;
    reg778=reg862+reg778; reg824=reg824/3; reg590=reg590/4; reg872=reg880+reg872; reg401=reg401+reg328;
    reg247=reg896+reg247; reg161=reg328+reg161; reg624=reg624/3; reg430=reg430/6; reg686=reg490+reg686;
    reg860=reg860/4; reg926=reg926/5; reg856=reg856/3; reg890=reg685+reg890; reg791=reg791/6;
    reg252=reg252/3; reg138=reg949+reg138; reg246=reg917+reg246; reg512=reg512/6; reg172=reg172/6;
    reg558=reg1015+reg558; reg100=reg100/5; reg400=reg89+reg400; reg835=reg721+reg835; reg533=reg533/5;
    reg605=reg605/6; reg313=reg977+reg313; reg633=reg761+reg633; reg670=reg935+reg670; reg942=reg789+reg942;
    reg89=reg935+reg127; reg232=reg145+reg129; reg708=reg708/5; reg416=reg938+reg416; reg236=reg322+reg157;
    reg289=reg155/2; reg736=0.0083333333333333333337*reg736; reg166=reg764+reg166; reg805=reg103+reg805; reg741=reg741/6;
    reg796=reg309+reg796; reg756=reg738+reg756; reg826=reg62+reg826; reg80=reg80/5; reg114=reg883+reg114;
    reg959=0.0083333333333333333337*reg959; reg993=0.0083333333333333333337*reg993; reg1021=reg596+reg1021; reg304=reg304/4; reg734=reg788+reg734;
    reg913=reg913/5; reg124=reg834+reg124; reg392=reg420+reg392; reg173=reg173/5; reg849=reg777+reg849;
    reg309=reg109+reg309; reg208=reg715+reg208; reg666=reg325+reg666; reg179=reg196+reg179; reg348=reg804+reg348;
    reg906=reg906+reg316; reg771=reg316+reg771; reg416=reg416/5; reg62=reg224/5; reg913=reg756-reg913;
    reg192=reg1017+reg192; reg805=reg103+reg805; reg590=reg187+reg590; reg824=reg269-reg824; reg208=reg208/6;
    reg103=reg232/3; reg80=reg114+reg80; reg734=reg788+reg734; reg605=reg942-reg605; reg872=reg872/4;
    reg959=reg959/6; reg172=reg138+reg172; reg664=reg548+reg664; reg100=reg558-reg100; reg430=reg247+reg430;
    reg791=reg400-reg791; reg860=reg666-reg860; reg161=reg401+reg161; reg796=reg309+reg796; reg109=reg935+reg89;
    reg624=reg458-reg624; reg533=reg633-reg533; reg835=reg835/6; reg512=reg246+reg512; reg758=reg639-reg758;
    reg252=reg313-reg252; reg856=reg445+reg856; reg973=reg956+reg973; reg926=reg890-reg926; reg174=reg174/5;
    reg686=reg686/6; reg849=reg849/4; reg771=reg906+reg771; reg124=reg834+reg124; reg304=reg392-reg304;
    reg826=reg826/4; reg993=reg993/6; reg1021=reg1021/5; reg179=reg196+reg179; reg173=reg778+reg173;
    reg741=reg166-reg741; reg968=reg968/5; reg670=reg670/4; reg555=reg200+reg555; reg708=reg348+reg708;
    reg1013=5*reg1013; reg736=reg736/6; reg114=reg289-reg236; reg664=reg548+reg664; reg416=reg860+reg416;
    reg124=reg834+reg124; reg512=reg512/2; reg172=reg172/2; reg734=reg788+reg734; reg430=reg430/2;
    reg826=reg624+reg826; reg993=reg173+reg993; reg736=reg708+reg736; reg741=0.5*reg741; reg192=0.5*reg192;
    reg1021=reg304+reg1021; reg805=reg805/6; reg179=reg179/6; reg208=reg913+reg208; reg605=0.5*reg605;
    reg872=reg824+reg872; reg835=reg533+reg835; reg968=reg758+reg968; reg114=reg114-reg103; reg791=0.5*reg791;
    reg555=reg555/6; reg670=reg856-reg670; reg138=reg109/4; reg174=reg973-reg174; reg62=reg590+reg62;
    reg686=reg926+reg686; reg161=reg161/5; reg796=reg796/5; reg849=reg252+reg849; reg100=reg100/2;
    reg166=reg1013/5; reg959=reg80+reg959; reg771=reg771/5; reg430=reg736+reg430; reg734=reg734/6;
    reg796=reg826-reg796; reg791=reg791/3; reg114=reg114+reg138; reg179=reg1021-reg179; reg208=0.16666666666666666667*reg208;
    reg605=reg605/3; reg174=0.16666666666666666667*reg174; reg555=reg968-reg555; reg512=reg993+reg512; reg100=reg62+reg100;
    reg805=reg416-reg805; reg161=reg872-reg161; reg664=reg664/6; reg192=reg192/3; reg172=reg959+reg172;
    reg741=reg741/3; reg124=reg124/6; reg771=reg849-reg771; reg686=0.16666666666666666667*reg686; reg835=0.16666666666666666667*reg835;
    reg670=reg670+reg166; reg805=0.041666666666666666668*reg805; reg124=reg771+reg124; reg605=reg512+reg605; reg208=reg208/4;
    reg670=0.041666666666666666668*reg670; reg114=reg114-reg166; reg179=0.041666666666666666668*reg179; reg791=reg430+reg791; reg835=reg835/4;
    reg555=0.041666666666666666668*reg555; reg664=reg161+reg664; reg741=reg172+reg741; reg686=reg686/4; reg192=reg100+reg192;
    reg174=reg174/4; reg734=reg796+reg734; reg114=0.0083333333333333333337*reg114; reg174=reg192+reg174; reg670=reg670/5;
    reg124=0.0083333333333333333337*reg124; reg208=reg605+reg208; reg805=reg805/5; reg734=0.0083333333333333333337*reg734; reg835=reg791+reg835;
    reg664=0.0083333333333333333337*reg664; reg686=reg741+reg686; reg555=reg555/5; reg179=reg179/5; reg555=reg835+reg555;
    reg734=reg734/6; reg114=reg114/6; reg670=reg174+reg670; reg805=reg208+reg805; reg124=reg124/6;
    reg664=reg664/6; reg179=reg686+reg179; reg114=reg670+reg114; reg124=reg805+reg124; reg664=reg179+reg664;
    reg734=reg555+reg734; res[1]=reg664/reg114; res[0]=reg124/reg114; res[2]=reg734/reg114;

    return res;
}
}
#endif // LMT_TETRA_10
