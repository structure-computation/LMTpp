#ifndef LMT_TETRA_10
#define LMT_TETRA_10
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Tetra_10 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 17, 34, 51, 72, 133, 194, 255, 316, 377, }; // fonction de lordre du poly
    static const double values[] = {
        0.0416666666667,0.138196601125,0.138196601125,0.138196601125,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
        0.0,
        0.0416666666667,0.138196601125,0.138196601125,0.138196601125,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
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
    T reg0=3*nodes[0]->pos[2]; T reg1=3*nodes[0]->pos[1]; T reg2=2*nodes[4]->pos[1]; T reg3=nodes[2]->pos[1]+reg1; T reg4=nodes[1]->pos[1]+reg1;
    T reg5=nodes[1]->pos[2]+reg0; T reg6=4*nodes[4]->pos[1]; T reg7=4*nodes[4]->pos[2]; T reg8=nodes[3]->pos[2]+reg0; T reg9=2*nodes[4]->pos[2];
    T reg10=nodes[3]->pos[1]+reg1; T reg11=nodes[2]->pos[2]+reg0; reg8=reg8-reg9; reg10=reg10-reg2; T reg12=2*nodes[6]->pos[1];
    T reg13=2*nodes[5]->pos[1]; reg2=reg3-reg2; reg3=2*nodes[6]->pos[2]; T reg14=2*nodes[5]->pos[2]; reg9=reg11-reg9;
    reg5=reg5-reg7; reg11=3*nodes[0]->pos[0]; reg4=reg4-reg6; reg4=reg13+reg4; reg9=reg9+reg14;
    T reg15=4*nodes[6]->pos[2]; T reg16=4*nodes[7]->pos[2]; reg8=reg8-reg3; T reg17=2*nodes[4]->pos[0]; reg5=reg14+reg5;
    reg14=4*nodes[4]->pos[0]; T reg18=nodes[1]->pos[0]+reg11; T reg19=nodes[2]->pos[0]+reg11; reg13=reg2+reg13; reg2=4*nodes[6]->pos[1];
    T reg20=4*nodes[7]->pos[1]; reg10=reg10-reg12; reg10=reg10-reg20; T reg21=nodes[3]->pos[0]+reg11; reg3=reg5-reg3;
    reg12=reg4-reg12; reg4=2*nodes[7]->pos[2]; reg9=reg9-reg15; reg19=reg19-reg17; reg5=2*nodes[8]->pos[1];
    reg18=reg18-reg14; T reg22=2*nodes[5]->pos[0]; reg13=reg13-reg2; T reg23=2*nodes[7]->pos[1]; reg8=reg8-reg16;
    T reg24=2*nodes[8]->pos[2]; reg3=reg3-reg4; T reg25=4*nodes[6]->pos[0]; reg19=reg22+reg19; T reg26=2*nodes[6]->pos[0];
    reg22=reg18+reg22; reg18=2*nodes[9]->pos[2]; reg8=reg8+reg24; reg17=reg21-reg17; reg10=reg10+reg5;
    reg12=reg12-reg23; reg4=reg9-reg4; reg23=reg13-reg23; reg9=2*nodes[9]->pos[1]; reg8=reg8+reg18;
    reg22=reg22-reg26; reg12=reg5+reg12; reg19=reg19-reg25; reg5=2*nodes[7]->pos[0]; reg3=reg24+reg3;
    reg26=reg17-reg26; reg10=reg9+reg10; reg13=4*nodes[7]->pos[0]; reg9=reg23+reg9; reg4=reg18+reg4;
    reg17=reg10*reg3; reg26=reg26-reg13; reg18=reg8*reg12; reg21=2*nodes[9]->pos[0]; reg19=reg19-reg5;
    reg5=reg22-reg5; reg22=2*nodes[8]->pos[0]; reg8=reg9*reg8; reg10=reg4*reg10; reg3=reg9*reg3;
    reg12=reg4*reg12; reg26=reg22+reg26; reg22=reg5+reg22; reg10=reg8-reg10; reg17=reg18-reg17;
    reg19=reg19+reg21; reg10=reg22*reg10; reg17=reg19*reg17; reg26=reg21+reg26; reg3=reg12-reg3;
    reg17=reg10-reg17; reg3=reg26*reg3; T det_jac=reg17+reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[1],nodes[3],nodes[2],nodes[4],nodes[8],nodes[7],nodes[6],nodes[5],nodes[9]};
        for(unsigned i=0;i<10;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[2];
    T reg3=2*var_inter[1]; T reg4=reg1-1; T reg5=reg3-1; T reg6=reg2-1; T reg7=2*var_inter[0];
    reg2=reg2+reg6; reg3=reg3+reg5; reg1=reg1+reg4; T reg8=pos_nodes[2][1]*reg3; T reg9=pos_nodes[0][1]*reg1;
    T reg10=pos_nodes[3][1]*reg2; T reg11=reg7-1; T reg12=4*var_inter[0]; T reg13=pos_nodes[3][2]*reg2; T reg14=pos_nodes[2][0]*reg3;
    T reg15=pos_nodes[3][0]*reg2; T reg16=pos_nodes[0][0]*reg1; T reg17=pos_nodes[2][2]*reg3; T reg18=pos_nodes[0][2]*reg1; T reg19=pos_nodes[4][1]*reg12;
    T reg20=pos_nodes[4][2]*reg12; reg17=reg17-reg18; reg7=reg7+reg11; T reg21=4*var_inter[2]; T reg22=pos_nodes[4][0]*reg12;
    reg14=reg14-reg16; reg10=reg10-reg9; reg8=reg8-reg9; reg15=reg15-reg16; reg4=reg0*reg4;
    T reg23=4*var_inter[1]; reg0=4*reg0; reg13=reg13-reg18; reg11=reg11*var_inter[0]; T reg24=pos_nodes[0][0]*reg4;
    T reg25=pos_nodes[1][0]*reg11; T reg26=reg0-reg23; T reg27=pos_nodes[1][1]*reg7; T reg28=pos_nodes[6][1]*reg23; reg14=reg14-reg22;
    T reg29=pos_nodes[5][0]*reg12; T reg30=pos_nodes[5][1]*reg12; reg22=reg15-reg22; reg8=reg8-reg19; reg15=reg0-reg21;
    reg13=reg13-reg20; reg5=var_inter[1]*reg5; T reg31=pos_nodes[5][2]*reg12; reg20=reg17-reg20; reg17=pos_nodes[6][2]*reg23;
    T reg32=reg0-reg12; T reg33=pos_nodes[1][0]*reg7; reg19=reg10-reg19; reg10=pos_nodes[0][1]*reg4; T reg34=pos_nodes[1][1]*reg11;
    T reg35=pos_nodes[6][0]*reg23; reg13=reg13-reg17; T reg36=pos_nodes[2][0]*reg5; T reg37=pos_nodes[7][2]*reg15; T reg38=pos_nodes[1][2]*reg11;
    reg9=reg27-reg9; reg27=pos_nodes[4][1]*reg32; reg19=reg19-reg28; T reg39=pos_nodes[7][1]*reg15; T reg40=pos_nodes[6][2]*reg26;
    T reg41=pos_nodes[0][2]*reg4; reg31=reg20+reg31; reg10=reg34+reg10; reg20=pos_nodes[2][1]*reg5; reg30=reg8+reg30;
    reg8=pos_nodes[6][1]*reg26; reg34=pos_nodes[1][2]*reg7; T reg42=pos_nodes[4][0]*reg32; reg16=reg33-reg16; reg29=reg14+reg29;
    reg14=pos_nodes[6][0]*reg26; reg22=reg22-reg35; reg33=pos_nodes[7][0]*reg15; reg6=var_inter[2]*reg6; reg24=reg25+reg24;
    reg25=pos_nodes[3][1]*reg6; reg8=reg30+reg8; reg36=reg24+reg36; reg24=pos_nodes[3][0]*reg6; reg14=reg29+reg14;
    reg18=reg34-reg18; reg29=pos_nodes[4][2]*reg32; reg20=reg10+reg20; reg10=pos_nodes[7][0]*reg21; reg30=pos_nodes[7][2]*reg21;
    reg34=pos_nodes[7][1]*reg21; T reg43=pos_nodes[2][2]*reg5; T reg44=pos_nodes[5][1]*reg23; reg27=reg9+reg27; reg33=reg22+reg33;
    reg9=pos_nodes[8][0]*reg12; reg41=reg38+reg41; reg42=reg16+reg42; reg40=reg31+reg40; reg39=reg19+reg39;
    reg16=reg12*pos_nodes[8][1]; reg19=reg0*var_inter[0]; reg22=pos_nodes[5][0]*reg23; reg37=reg13+reg37; reg13=reg12*pos_nodes[8][2];
    reg25=reg20+reg25; reg22=reg42+reg22; reg20=pos_nodes[4][1]*reg19; reg31=pos_nodes[3][2]*reg6; reg29=reg18+reg29;
    reg43=reg41+reg43; reg18=pos_nodes[5][2]*reg23; reg38=var_inter[1]*reg12; reg40=reg40-reg30; reg41=pos_nodes[9][2]*reg21;
    reg42=reg23*pos_nodes[9][2]; reg13=reg37+reg13; reg8=reg8-reg34; reg14=reg14-reg10; reg37=pos_nodes[9][0]*reg21;
    reg24=reg36+reg24; reg44=reg27+reg44; reg9=reg33+reg9; reg27=reg23*pos_nodes[9][0]; reg33=pos_nodes[9][1]*reg21;
    reg36=pos_nodes[4][0]*reg19; reg16=reg39+reg16; reg39=reg23*pos_nodes[9][1]; reg36=reg24+reg36; reg24=pos_nodes[5][0]*reg38;
    T reg45=var_inter[1]*reg0; reg28=reg44-reg28; reg41=reg40+reg41; reg27=reg9+reg27; reg31=reg43+reg31;
    reg9=pos_nodes[4][2]*reg19; reg18=reg29+reg18; reg37=reg14+reg37; reg42=reg13+reg42; reg39=reg16+reg39;
    reg35=reg22-reg35; reg33=reg8+reg33; reg20=reg25+reg20; reg8=pos_nodes[5][1]*reg38; reg0=var_inter[2]*reg0;
    reg13=pos_nodes[6][0]*reg45; reg24=reg36+reg24; reg10=reg35-reg10; reg14=pos_nodes[8][0]*reg21; reg8=reg20+reg8;
    reg16=pos_nodes[6][1]*reg45; reg34=reg28-reg34; reg20=reg27*reg41; reg22=reg37*reg42; reg25=pos_nodes[8][1]*reg21;
    reg17=reg18-reg17; reg9=reg31+reg9; reg18=pos_nodes[5][2]*reg38; reg28=reg39*reg41; reg29=reg33*reg42;
    reg20=reg22-reg20; reg31=reg37*reg39; reg35=reg27*reg33; reg28=reg29-reg28; reg36=pos_nodes[6][2]*reg45;
    reg13=reg24+reg13; reg18=reg9+reg18; reg9=pos_nodes[7][1]*reg0; reg16=reg8+reg16; reg14=reg10+reg14;
    reg25=reg34+reg25; reg30=reg17-reg30; reg8=pos_nodes[8][2]*reg21; reg10=pos_nodes[7][0]*reg0; reg17=var_inter[2]*reg12;
    reg24=reg17*pos_nodes[8][1]; reg34=reg14*reg28; reg9=reg16+reg9; reg16=reg25*reg20; reg40=var_inter[2]*reg23;
    reg35=reg31-reg35; reg43=pos_nodes[7][2]*reg0; reg36=reg18+reg36; reg10=reg13+reg10; reg13=pos_nodes[8][0]*reg17;
    reg8=reg30+reg8; reg18=reg25*reg42; reg30=reg39*reg8; reg44=reg25*reg41; T reg46=reg8*reg35;
    reg34=reg16-reg34; reg16=reg37*reg8; T reg47=reg33*reg8; T reg48=reg14*reg42; T reg49=reg27*reg8;
    T reg50=reg14*reg41; reg24=reg9+reg24; reg9=reg40*pos_nodes[9][1]; T reg51=reg40*pos_nodes[9][0]; reg13=reg10+reg13;
    reg10=reg17*pos_nodes[8][2]; reg43=reg36+reg43; reg49=reg48-reg49; reg51=reg13+reg51; reg16=reg50-reg16;
    reg47=reg44-reg47; reg13=reg14*reg39; reg30=reg18-reg30; reg36=reg27*reg25; T reg52=reg14*reg33;
    reg46=reg34-reg46; reg10=reg43+reg10; reg34=reg40*pos_nodes[9][2]; reg43=reg37*reg25; reg9=reg24+reg9;
    reg16=reg16/reg46; reg36=reg13-reg36; reg43=reg52-reg43; reg49=reg49/reg46; reg20=reg20/reg46;
    reg51=pos[0]-reg51; reg47=reg47/reg46; reg30=reg30/reg46; reg9=pos[1]-reg9; reg28=reg28/reg46;
    reg34=reg10+reg34; reg47=reg51*reg47; reg49=reg9*reg49; reg30=reg51*reg30; reg16=reg9*reg16;
    reg20=reg9*reg20; reg28=reg51*reg28; reg43=reg43/reg46; reg36=reg36/reg46; reg46=reg35/reg46;
    reg34=pos[2]-reg34; reg46=reg34*reg46; reg28=reg20-reg28; reg36=reg34*reg36; reg49=reg30-reg49;
    reg43=reg34*reg43; reg47=reg16-reg47; var_inter[0]=reg28-reg46; var_inter[1]=reg36+reg49; var_inter[2]=reg47-reg43;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[2]; T reg2=2*var_inter[1];
    T reg3=2*reg0; T reg4=reg2-1; T reg5=reg3-1; T reg6=reg1-1; T reg7=2*var_inter[0];
    reg3=reg5+reg3; reg2=reg2+reg4; reg1=reg1+reg6; T reg8=pos_nodes[3][2]*reg1; T reg9=4*var_inter[0];
    T reg10=pos_nodes[2][2]*reg2; T reg11=pos_nodes[0][2]*reg3; T reg12=pos_nodes[0][0]*reg3; T reg13=pos_nodes[3][1]*reg1; T reg14=pos_nodes[2][0]*reg2;
    T reg15=pos_nodes[2][1]*reg2; T reg16=pos_nodes[0][1]*reg3; T reg17=pos_nodes[3][0]*reg1; T reg18=reg7-1; reg15=reg15-reg16;
    T reg19=pos_nodes[4][2]*reg9; reg10=reg10-reg11; T reg20=pos_nodes[4][1]*reg9; reg7=reg18+reg7; T reg21=4*var_inter[2];
    T reg22=pos_nodes[4][0]*reg9; reg14=reg14-reg12; reg13=reg13-reg16; reg17=reg17-reg12; T reg23=4*reg0;
    reg8=reg8-reg11; reg18=reg18*var_inter[0]; reg0=reg5*reg0; reg5=4*var_inter[1]; T reg24=pos_nodes[0][0]*reg0;
    T reg25=reg18*pos_nodes[1][0]; T reg26=reg23-reg5; T reg27=pos_nodes[1][1]*reg7; reg14=reg14-reg22; T reg28=pos_nodes[5][0]*reg9;
    T reg29=pos_nodes[5][1]*reg9; reg15=reg15-reg20; T reg30=pos_nodes[6][1]*reg5; reg22=reg17-reg22; reg17=reg23-reg21;
    reg4=var_inter[1]*reg4; reg8=reg8-reg19; T reg31=pos_nodes[5][2]*reg9; reg19=reg10-reg19; reg10=pos_nodes[6][2]*reg5;
    T reg32=reg23-reg9; T reg33=pos_nodes[1][0]*reg7; reg20=reg13-reg20; reg13=pos_nodes[0][1]*reg0; T reg34=reg18*pos_nodes[1][1];
    T reg35=pos_nodes[6][0]*reg5; reg20=reg20-reg30; T reg36=pos_nodes[2][0]*reg4; reg8=reg8-reg10; T reg37=pos_nodes[7][2]*reg17;
    reg16=reg27-reg16; reg27=pos_nodes[4][1]*reg32; T reg38=pos_nodes[7][1]*reg17; T reg39=pos_nodes[1][2]*reg18; T reg40=reg0*pos_nodes[0][2];
    T reg41=pos_nodes[6][2]*reg26; reg31=reg19+reg31; reg13=reg34+reg13; reg19=pos_nodes[2][1]*reg4; reg34=pos_nodes[1][2]*reg7;
    reg29=reg15+reg29; reg15=pos_nodes[6][1]*reg26; T reg42=pos_nodes[4][0]*reg32; reg12=reg33-reg12; reg28=reg14+reg28;
    reg14=pos_nodes[6][0]*reg26; reg22=reg22-reg35; reg33=pos_nodes[7][0]*reg17; reg6=var_inter[2]*reg6; reg24=reg25+reg24;
    reg25=pos_nodes[3][1]*reg6; reg15=reg29+reg15; reg36=reg24+reg36; reg24=pos_nodes[3][0]*reg6; reg14=reg28+reg14;
    reg11=reg34-reg11; reg28=pos_nodes[4][2]*reg32; reg19=reg13+reg19; reg13=pos_nodes[7][0]*reg21; reg29=pos_nodes[7][2]*reg21;
    reg34=pos_nodes[7][1]*reg21; T reg43=pos_nodes[2][2]*reg4; T reg44=pos_nodes[5][1]*reg5; reg27=reg16+reg27; reg33=reg22+reg33;
    reg16=pos_nodes[8][0]*reg9; reg40=reg39+reg40; reg42=reg12+reg42; reg41=reg31+reg41; reg38=reg20+reg38;
    reg12=reg9*pos_nodes[8][1]; reg20=var_inter[0]*reg23; reg22=pos_nodes[5][0]*reg5; reg37=reg8+reg37; reg8=reg9*pos_nodes[8][2];
    reg25=reg19+reg25; reg22=reg42+reg22; reg19=pos_nodes[4][1]*reg20; reg31=pos_nodes[3][2]*reg6; reg28=reg11+reg28;
    reg43=reg40+reg43; reg11=pos_nodes[5][2]*reg5; reg39=var_inter[1]*reg9; reg41=reg41-reg29; reg40=pos_nodes[9][2]*reg21;
    reg42=reg5*pos_nodes[9][2]; reg8=reg37+reg8; reg37=pos_nodes[4][0]*reg20; T reg45=reg5*pos_nodes[9][1]; reg12=reg38+reg12;
    reg44=reg27+reg44; reg16=reg33+reg16; reg27=reg5*pos_nodes[9][0]; reg24=reg36+reg24; reg33=pos_nodes[9][1]*reg21;
    reg36=pos_nodes[9][0]*reg21; reg14=reg14-reg13; reg15=reg15-reg34; reg38=pos_nodes[5][0]*reg39; T reg46=var_inter[1]*reg23;
    reg42=reg8+reg42; reg36=reg14+reg36; reg11=reg28+reg11; reg40=reg41+reg40; reg30=reg44-reg30;
    reg45=reg12+reg45; reg35=reg22-reg35; reg33=reg15+reg33; reg19=reg25+reg19; reg8=pos_nodes[5][1]*reg39;
    reg12=pos_nodes[4][2]*reg20; reg31=reg43+reg31; reg27=reg16+reg27; reg37=reg24+reg37; reg14=pos_nodes[5][2]*reg39;
    reg12=reg31+reg12; reg38=reg37+reg38; reg15=pos_nodes[6][0]*reg46; reg23=var_inter[2]*reg23; reg16=reg33*reg42;
    reg22=reg45*reg40; reg24=reg36*reg42; reg25=reg27*reg40; reg34=reg30-reg34; reg13=reg35-reg13;
    reg28=pos_nodes[8][0]*reg21; reg10=reg11-reg10; reg11=pos_nodes[6][1]*reg46; reg8=reg19+reg8; reg19=pos_nodes[8][1]*reg21;
    reg19=reg34+reg19; reg30=reg23*pos_nodes[7][1]; reg11=reg8+reg11; reg14=reg12+reg14; reg8=pos_nodes[6][2]*reg46;
    reg28=reg13+reg28; reg22=reg16-reg22; reg12=reg36*reg45; reg25=reg24-reg25; reg13=reg27*reg33;
    reg15=reg38+reg15; reg31=pos_nodes[8][2]*reg21; reg29=reg10-reg29; reg10=pos_nodes[7][0]*reg23; reg34=var_inter[2]*reg9;
    reg35=reg28*reg22; reg37=reg19*reg25; reg31=reg29+reg31; reg29=pos_nodes[7][2]*reg23; reg8=reg14+reg8;
    reg14=pos_nodes[8][0]*reg34; reg10=reg15+reg10; reg15=reg5*var_inter[2]; reg30=reg11+reg30; reg11=reg34*pos_nodes[8][1];
    reg13=reg12-reg13; reg38=reg31*reg13; reg35=reg37-reg35; reg37=reg33*reg31; reg41=reg19*reg42;
    reg43=reg45*reg31; reg44=reg28*reg42; T reg47=reg27*reg31; T reg48=reg15*pos_nodes[9][0]; T reg49=reg19*reg40;
    reg14=reg10+reg14; reg10=reg28*reg40; T reg50=reg36*reg31; T reg51=reg34*pos_nodes[8][2]; reg29=reg8+reg29;
    reg11=reg30+reg11; reg8=reg15*pos_nodes[9][1]; reg47=reg44-reg47; reg50=reg10-reg50; reg37=reg49-reg37;
    reg30=reg28*reg45; reg43=reg41-reg43; T reg52=reg27*reg19; T reg53=reg28*reg33; T reg54=reg36*reg19;
    reg8=reg11+reg8; reg51=reg29+reg51; reg11=reg15*pos_nodes[9][2]; reg48=reg14+reg48; reg38=reg35-reg38;
    reg48=pos[0]-reg48; reg25=reg25/reg38; reg47=reg47/reg38; reg11=reg51+reg11; reg37=reg37/reg38;
    reg54=reg53-reg54; reg22=reg22/reg38; reg50=reg50/reg38; reg43=reg43/reg38; reg8=pos[1]-reg8;
    reg52=reg30-reg52; reg25=reg8*reg25; reg43=reg48*reg43; reg47=reg8*reg47; reg37=reg48*reg37;
    reg50=reg8*reg50; reg22=reg48*reg22; reg54=reg54/reg38; reg52=reg52/reg38; reg38=reg13/reg38;
    reg11=pos[2]-reg11; reg38=reg11*reg38; reg22=reg25-reg22; reg52=reg11*reg52; reg47=reg43-reg47;
    reg54=reg11*reg54; reg37=reg50-reg37; var_inter[0]+=reg22-reg38; var_inter[1]+=reg52+reg47; var_inter[2]+=reg37-reg54;

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
    reg2=reg2-1; T reg3=2*var_inter[1]; reg1=reg1-1; reg1=var_inter[0]*reg1; reg3=reg3-1;
    T reg4=2*var_inter[2]; reg2=reg2*reg0; reg1=val[1]*reg1; reg3=var_inter[1]*reg3; reg4=reg4-1;
    reg2=val[0]*reg2; reg0=4*reg0; reg4=var_inter[2]*reg4; reg3=val[2]*reg3; reg1=reg2+reg1;
    reg3=reg1+reg3; reg4=val[3]*reg4; reg1=4*var_inter[0]; reg2=var_inter[0]*reg0; T reg5=var_inter[1]*reg1;
    reg4=reg3+reg4; reg2=val[4]*reg2; reg5=val[5]*reg5; reg3=var_inter[1]*reg0; reg2=reg4+reg2;
    reg5=reg2+reg5; reg3=val[6]*reg3; reg0=var_inter[2]*reg0; reg2=4*var_inter[1]; reg1=var_inter[2]*reg1;
    reg0=val[7]*reg0; reg3=reg5+reg3; reg0=reg3+reg0; reg1=val[8]*reg1; reg2=var_inter[2]*reg2;
    reg1=reg0+reg1; reg2=val[9]*reg2; res=reg1+reg2;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[0];
    T reg3=2*var_inter[1]; T reg4=2*var_inter[2]; T reg5=4*var_inter[1]; T reg6=4*var_inter[0]; T reg7=4*reg0;
    reg4=reg4-1; reg3=reg3-1; reg2=reg2-1; reg1=reg1-1; reg3=var_inter[1]*reg3;
    res[2]=reg3; reg4=var_inter[2]*reg4; res[3]=reg4; reg2=var_inter[0]*reg2; res[1]=reg2;
    T reg8=var_inter[0]*reg7; res[4]=reg8; reg0=reg1*reg0; res[0]=reg0; reg1=var_inter[1]*reg6;
    res[5]=reg1; T reg9=var_inter[1]*reg7; res[6]=reg9; reg7=var_inter[2]*reg7; res[7]=reg7;
    reg6=var_inter[2]*reg6; res[8]=reg6; reg5=var_inter[2]*reg5; res[9]=reg5;

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
