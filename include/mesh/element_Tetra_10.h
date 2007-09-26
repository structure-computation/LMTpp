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
    T reg3=reg1-1; T reg4=reg2-1; T reg5=2*var_inter[1]; T reg6=2*var_inter[2]; T reg7=reg5-1;
    T reg8=reg6-1; T reg9=reg4*var_inter[0]; T reg10=reg0*reg3; T reg11=var_inter[1]*reg7; reg6=reg6+reg8;
    reg7=reg5+reg7; reg3=reg1+reg3; reg1=pos_nodes[0][0]*reg10; reg5=pos_nodes[1][0]*reg9; T reg12=reg10*pos_nodes[0][1];
    T reg13=pos_nodes[1][1]*reg9; T reg14=pos_nodes[0][0]*reg3; T reg15=pos_nodes[3][2]*reg6; T reg16=pos_nodes[1][2]*reg9; T reg17=pos_nodes[0][2]*reg10;
    T reg18=pos_nodes[2][2]*reg7; T reg19=pos_nodes[0][2]*reg3; T reg20=pos_nodes[2][1]*reg11; T reg21=pos_nodes[3][1]*reg6; reg13=reg12+reg13;
    reg12=pos_nodes[2][0]*reg7; T reg22=pos_nodes[2][1]*reg7; T reg23=pos_nodes[0][1]*reg3; T reg24=pos_nodes[3][0]*reg6; reg5=reg1+reg5;
    reg1=pos_nodes[2][0]*reg11; reg0=4*reg0; reg8=var_inter[2]*reg8; T reg25=4*var_inter[0]; T reg26=pos_nodes[3][1]*reg8;
    reg20=reg13+reg20; reg21=reg21-reg23; reg12=reg12-reg14; reg13=pos_nodes[4][0]*reg25; T reg27=pos_nodes[4][1]*reg25;
    reg22=reg22-reg23; reg24=reg24-reg14; T reg28=pos_nodes[3][0]*reg8; reg1=reg5+reg1; reg18=reg18-reg19;
    reg5=pos_nodes[4][2]*reg25; T reg29=var_inter[0]*reg0; T reg30=pos_nodes[2][2]*reg11; T reg31=4*var_inter[2]; reg4=reg2+reg4;
    reg15=reg15-reg19; reg16=reg17+reg16; reg2=4*var_inter[1]; reg17=pos_nodes[3][2]*reg8; reg30=reg16+reg30;
    reg28=reg1+reg28; reg1=pos_nodes[4][0]*reg29; reg16=pos_nodes[1][1]*reg4; T reg32=pos_nodes[6][1]*reg2; reg15=reg15-reg5;
    reg22=reg22-reg27; T reg33=pos_nodes[5][1]*reg25; T reg34=pos_nodes[5][2]*reg25; reg5=reg18-reg5; reg27=reg21-reg27;
    reg18=pos_nodes[6][2]*reg2; reg21=pos_nodes[4][1]*reg29; reg26=reg20+reg26; reg20=pos_nodes[5][0]*reg25; reg12=reg12-reg13;
    T reg35=pos_nodes[1][0]*reg4; T reg36=var_inter[1]*reg25; reg13=reg24-reg13; reg24=reg0-reg31; T reg37=reg0-reg25;
    T reg38=reg0-reg2; T reg39=pos_nodes[6][0]*reg2; reg23=reg16-reg23; reg16=pos_nodes[4][1]*reg37; T reg40=pos_nodes[4][0]*reg37;
    reg14=reg35-reg14; reg27=reg27-reg32; reg15=reg15-reg18; reg35=pos_nodes[7][2]*reg24; T reg41=pos_nodes[7][1]*reg24;
    T reg42=pos_nodes[6][0]*reg38; reg33=reg22+reg33; reg22=pos_nodes[6][1]*reg38; T reg43=pos_nodes[6][2]*reg38; reg34=reg5+reg34;
    reg20=reg12+reg20; reg5=pos_nodes[1][2]*reg4; reg12=pos_nodes[7][0]*reg24; reg13=reg13-reg39; reg1=reg28+reg1;
    reg28=pos_nodes[5][0]*reg36; T reg44=pos_nodes[5][1]*reg36; reg21=reg26+reg21; reg26=pos_nodes[4][2]*reg29; reg17=reg30+reg17;
    reg30=var_inter[1]*reg0; reg27=reg41+reg27; reg41=pos_nodes[8][1]*reg25; T reg45=pos_nodes[5][0]*reg2; T reg46=pos_nodes[7][0]*reg31;
    reg44=reg21+reg44; reg21=pos_nodes[7][2]*reg31; T reg47=pos_nodes[6][1]*reg30; T reg48=pos_nodes[4][2]*reg37; reg19=reg5-reg19;
    reg40=reg14+reg40; reg5=pos_nodes[8][0]*reg25; reg14=pos_nodes[5][2]*reg36; reg12=reg13+reg12; reg28=reg1+reg28;
    reg1=pos_nodes[6][0]*reg30; reg26=reg17+reg26; reg0=var_inter[2]*reg0; reg16=reg23+reg16; reg13=pos_nodes[5][1]*reg2;
    reg43=reg34+reg43; reg17=pos_nodes[8][2]*reg25; reg23=pos_nodes[7][1]*reg31; reg15=reg35+reg15; reg42=reg20+reg42;
    reg22=reg33+reg22; reg45=reg40+reg45; reg20=pos_nodes[6][2]*reg30; reg14=reg26+reg14; reg48=reg19+reg48;
    reg19=pos_nodes[5][2]*reg2; reg43=reg43-reg21; reg26=pos_nodes[9][2]*reg31; reg33=var_inter[2]*reg25; reg34=pos_nodes[9][2]*reg2;
    reg17=reg15+reg17; reg22=reg22-reg23; reg15=pos_nodes[9][1]*reg31; reg42=reg42-reg46; reg35=pos_nodes[9][0]*reg31;
    reg41=reg27+reg41; reg27=pos_nodes[9][1]*reg2; reg5=reg12+reg5; reg12=pos_nodes[9][0]*reg2; reg1=reg28+reg1;
    reg47=reg44+reg47; reg28=pos_nodes[7][1]*reg0; reg13=reg16+reg13; reg16=pos_nodes[7][0]*reg0; reg40=var_inter[2]*reg2;
    reg12=reg5+reg12; reg35=reg42+reg35; reg20=reg14+reg20; reg5=pos_nodes[7][2]*reg0; reg26=reg43+reg26;
    reg32=reg13-reg32; reg34=reg17+reg34; reg16=reg1+reg16; reg1=pos_nodes[8][0]*reg33; reg13=pos_nodes[8][1]*reg33;
    reg28=reg47+reg28; reg19=reg48+reg19; reg39=reg45-reg39; reg15=reg22+reg15; reg27=reg41+reg27;
    reg14=reg15*reg34; reg1=reg16+reg1; reg16=pos_nodes[9][0]*reg40; reg17=reg27*reg26; reg22=pos_nodes[9][1]*reg40;
    reg13=reg28+reg13; reg5=reg20+reg5; reg23=reg32-reg23; reg20=pos_nodes[8][1]*reg31; reg28=pos_nodes[8][0]*reg31;
    reg18=reg19-reg18; reg46=reg39-reg46; reg19=pos_nodes[8][2]*reg33; reg32=reg35*reg34; reg39=reg12*reg26;
    reg41=pos_nodes[9][2]*reg40; reg19=reg5+reg19; reg16=reg1+reg16; reg20=reg23+reg20; reg17=reg14-reg17;
    reg1=reg35*reg27; reg28=reg46+reg28; reg39=reg32-reg39; reg5=pos_nodes[8][2]*reg31; reg21=reg18-reg21;
    reg18=reg12*reg15; reg22=reg13+reg22; reg18=reg1-reg18; reg13=reg20*reg39; reg23=reg28*reg17;
    reg42=var_inter[0]*reg20; reg43=var_inter[0]*reg28; reg16=pos[0]-reg16; reg22=pos[1]-reg22; reg5=reg21+reg5;
    reg41=reg19+reg41; reg19=reg28*reg26; reg21=reg15*reg5; reg44=reg35*reg5; reg45=reg20*reg26;
    reg46=reg27*reg5; reg47=reg20*reg34; reg48=reg5*reg18; reg23=reg13-reg23; reg13=reg12*reg5;
    reg41=pos[2]-reg41; T reg49=var_inter[1]*reg35; reg43=reg16+reg43; reg16=reg28*reg34; T reg50=var_inter[1]*reg15;
    T reg51=var_inter[0]*reg5; reg42=reg22+reg42; reg21=reg45-reg21; reg22=var_inter[2]*reg27; reg46=reg47-reg46;
    reg43=reg49+reg43; reg48=reg23-reg48; reg44=reg19-reg44; reg23=reg28*reg15; reg42=reg50+reg42;
    reg49=reg12*reg20; reg50=var_inter[1]*reg26; T reg52=reg35*reg20; reg13=reg16-reg13; reg51=reg41+reg51;
    reg41=reg28*reg27; T reg53=var_inter[2]*reg12; reg52=reg23-reg52; reg49=reg41-reg49; reg44=reg44/reg48;
    reg39=reg39/reg48; reg13=reg13/reg48; reg43=reg53+reg43; reg53=var_inter[2]*reg34; reg42=reg22+reg42;
    reg51=reg50+reg51; reg17=reg17/reg48; reg46=reg46/reg48; reg21=reg21/reg48; reg51=reg53+reg51;
    reg18=reg18/reg48; reg49=reg49/reg48; reg48=reg52/reg48; reg17=reg43*reg17; reg39=reg39*reg42;
    reg44=reg42*reg44; reg46=reg43*reg46; reg13=reg13*reg42; reg21=reg43*reg21; reg21=reg44-reg21;
    reg48=reg51*reg48; reg13=reg46-reg13; reg49=reg51*reg49; reg17=reg39-reg17; reg18=reg51*reg18;
    var_inter[1]=reg49+reg13; var_inter[0]=reg17-reg18; var_inter[2]=reg21-reg48;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[0]; T reg2=2*reg0;
    T reg3=2*var_inter[1]; T reg4=reg1-1; T reg5=reg2-1; T reg6=2*var_inter[2]; T reg7=reg3-1;
    T reg8=var_inter[0]*reg4; T reg9=reg0*reg5; T reg10=reg6-1; reg3=reg3+reg7; reg7=var_inter[1]*reg7;
    T reg11=pos_nodes[1][0]*reg8; T reg12=pos_nodes[0][0]*reg9; reg6=reg6+reg10; reg5=reg2+reg5; reg2=pos_nodes[1][1]*reg8;
    T reg13=pos_nodes[0][1]*reg9; T reg14=pos_nodes[0][0]*reg5; T reg15=pos_nodes[2][2]*reg3; T reg16=pos_nodes[0][2]*reg5; T reg17=pos_nodes[3][2]*reg6;
    T reg18=pos_nodes[0][2]*reg9; T reg19=pos_nodes[1][2]*reg8; T reg20=pos_nodes[2][0]*reg3; T reg21=pos_nodes[3][1]*reg6; reg11=reg12+reg11;
    reg12=pos_nodes[0][1]*reg5; T reg22=pos_nodes[2][1]*reg3; T reg23=pos_nodes[3][0]*reg6; reg2=reg13+reg2; reg13=pos_nodes[2][1]*reg7;
    T reg24=pos_nodes[2][0]*reg7; reg10=reg10*var_inter[2]; reg0=4*reg0; T reg25=4*var_inter[0]; T reg26=reg25*pos_nodes[4][2];
    reg15=reg15-reg16; reg20=reg20-reg14; T reg27=reg25*pos_nodes[4][0]; T reg28=reg10*pos_nodes[3][1]; reg2=reg13+reg2;
    reg23=reg23-reg14; reg13=reg0*var_inter[0]; reg11=reg24+reg11; reg24=reg10*pos_nodes[3][0]; reg21=reg21-reg12;
    T reg29=reg25*pos_nodes[4][1]; reg22=reg22-reg12; T reg30=4*var_inter[1]; reg4=reg1+reg4; reg17=reg17-reg16;
    reg1=4*var_inter[2]; T reg31=pos_nodes[2][2]*reg7; reg19=reg18+reg19; reg18=reg25*pos_nodes[5][1]; reg22=reg22-reg29;
    T reg32=reg13*pos_nodes[4][0]; reg24=reg11+reg24; reg17=reg17-reg26; reg11=reg30*pos_nodes[6][1]; reg29=reg21-reg29;
    reg21=pos_nodes[1][1]*reg4; T reg33=reg0-reg30; T reg34=reg25*var_inter[1]; reg26=reg15-reg26; reg15=reg25*pos_nodes[5][2];
    T reg35=reg30*pos_nodes[6][0]; T reg36=reg30*pos_nodes[6][2]; T reg37=pos_nodes[1][0]*reg4; T reg38=reg0-reg1; reg20=reg20-reg27;
    T reg39=reg25*pos_nodes[5][0]; T reg40=reg10*pos_nodes[3][2]; reg27=reg23-reg27; reg19=reg31+reg19; reg23=reg0-reg25;
    reg28=reg2+reg28; reg2=reg13*pos_nodes[4][1]; reg31=pos_nodes[7][2]*reg38; reg17=reg17-reg36; reg29=reg29-reg11;
    T reg41=pos_nodes[7][1]*reg38; T reg42=pos_nodes[6][1]*reg33; reg18=reg22+reg18; reg22=pos_nodes[1][2]*reg4; T reg43=reg34*pos_nodes[5][1];
    T reg44=pos_nodes[6][2]*reg33; reg15=reg26+reg15; reg26=reg13*pos_nodes[4][2]; reg2=reg28+reg2; reg28=pos_nodes[4][1]*reg23;
    reg12=reg21-reg12; reg40=reg19+reg40; reg19=reg0*var_inter[1]; reg14=reg37-reg14; reg21=pos_nodes[4][0]*reg23;
    reg39=reg20+reg39; reg20=pos_nodes[6][0]*reg33; reg27=reg27-reg35; reg37=pos_nodes[7][0]*reg38; reg32=reg24+reg32;
    reg24=reg34*pos_nodes[5][0]; T reg45=reg25*pos_nodes[8][0]; reg37=reg27+reg37; reg31=reg17+reg31; reg17=reg25*pos_nodes[8][2];
    reg20=reg39+reg20; reg27=pos_nodes[7][1]*reg1; reg44=reg15+reg44; reg43=reg2+reg43; reg2=reg19*pos_nodes[6][1];
    reg28=reg12+reg28; reg21=reg14+reg21; reg12=reg30*pos_nodes[5][0]; reg14=reg30*pos_nodes[5][1]; reg16=reg22-reg16;
    reg15=pos_nodes[4][2]*reg23; reg22=pos_nodes[7][2]*reg1; reg39=reg34*pos_nodes[5][2]; reg26=reg40+reg26; reg40=pos_nodes[7][0]*reg1;
    reg0=reg0*var_inter[2]; T reg46=reg25*pos_nodes[8][1]; reg42=reg18+reg42; reg24=reg32+reg24; reg41=reg29+reg41;
    reg18=reg19*pos_nodes[6][0]; reg29=pos_nodes[9][1]*reg1; reg42=reg42-reg27; reg15=reg16+reg15; reg16=reg30*pos_nodes[5][2];
    reg12=reg21+reg12; reg21=reg25*var_inter[2]; reg18=reg24+reg18; reg24=reg19*pos_nodes[6][2]; reg39=reg26+reg39;
    reg26=reg0*pos_nodes[7][0]; reg32=pos_nodes[9][2]*reg1; T reg47=reg30*pos_nodes[9][1]; reg46=reg41+reg46; reg44=reg44-reg22;
    reg41=pos_nodes[9][0]*reg1; reg20=reg20-reg40; reg45=reg37+reg45; reg37=reg30*pos_nodes[9][0]; reg2=reg43+reg2;
    reg43=pos_nodes[7][1]*reg0; T reg48=reg30*pos_nodes[9][2]; reg17=reg31+reg17; reg14=reg28+reg14; reg32=reg44+reg32;
    reg35=reg12-reg35; reg12=reg30*var_inter[2]; reg48=reg17+reg48; reg16=reg15+reg16; reg24=reg39+reg24;
    reg15=pos_nodes[7][2]*reg0; reg17=reg21*pos_nodes[8][1]; reg43=reg2+reg43; reg11=reg14-reg11; reg41=reg20+reg41;
    reg47=reg46+reg47; reg37=reg45+reg37; reg29=reg42+reg29; reg26=reg18+reg26; reg2=reg21*pos_nodes[8][0];
    reg14=reg47*reg32; reg18=reg29*reg48; reg20=reg41*reg48; reg28=reg37*reg32; reg36=reg16-reg36;
    reg40=reg35-reg40; reg16=pos_nodes[8][0]*reg1; reg15=reg24+reg15; reg24=reg12*pos_nodes[9][1]; reg17=reg43+reg17;
    reg2=reg26+reg2; reg26=reg21*pos_nodes[8][2]; reg31=pos_nodes[8][1]*reg1; reg27=reg11-reg27; reg11=reg12*pos_nodes[9][0];
    reg26=reg15+reg26; reg15=reg12*pos_nodes[9][2]; reg11=reg2+reg11; reg31=reg27+reg31; reg24=reg17+reg24;
    reg2=reg37*reg29; reg16=reg40+reg16; reg22=reg36-reg22; reg17=pos_nodes[8][2]*reg1; reg28=reg20-reg28;
    reg27=reg41*reg47; reg14=reg18-reg14; reg35=reg31*reg28; reg36=reg16*reg14; reg39=var_inter[0]*reg31;
    reg40=var_inter[0]*reg16; reg15=reg26+reg15; reg2=reg27-reg2; reg17=reg22+reg17; reg11=pos[0]-reg11;
    reg24=pos[1]-reg24; reg22=reg16*reg32; reg26=reg41*reg17; reg42=reg37*reg17; reg43=reg29*reg17;
    reg44=reg16*reg48; reg36=reg35-reg36; reg35=var_inter[0]*reg17; reg45=reg17*reg2; reg39=reg24+reg39;
    reg24=var_inter[1]*reg29; reg46=reg31*reg48; T reg49=reg47*reg17; T reg50=reg31*reg32; reg40=reg11+reg40;
    reg11=var_inter[1]*reg41; reg15=pos[2]-reg15; reg45=reg36-reg45; reg42=reg44-reg42; reg49=reg46-reg49;
    reg43=reg50-reg43; reg36=reg16*reg47; T reg51=reg37*reg31; reg35=reg15+reg35; reg15=var_inter[1]*reg32;
    T reg52=reg16*reg29; reg39=reg24+reg39; reg24=reg41*reg31; reg26=reg22-reg26; reg40=reg11+reg40;
    reg11=var_inter[2]*reg37; T reg53=var_inter[2]*reg47; reg43=reg43/reg45; reg51=reg36-reg51; reg49=reg49/reg45;
    reg24=reg52-reg24; reg14=reg14/reg45; reg28=reg28/reg45; reg42=reg42/reg45; reg35=reg15+reg35;
    reg39=reg53+reg39; reg15=var_inter[2]*reg48; reg40=reg11+reg40; reg26=reg26/reg45; reg43=reg40*reg43;
    reg42=reg42*reg39; reg49=reg40*reg49; reg26=reg26*reg39; reg28=reg28*reg39; reg14=reg40*reg14;
    reg24=reg24/reg45; reg51=reg51/reg45; reg35=reg15+reg35; reg45=reg2/reg45; reg43=reg26-reg43;
    reg24=reg35*reg24; reg42=reg49-reg42; reg51=reg35*reg51; reg14=reg28-reg14; reg45=reg45*reg35;
    var_inter[1]+=reg51+reg42; var_inter[0]+=reg14-reg45; var_inter[2]+=reg43-reg24;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[0];
    reg1=reg1-1; reg2=reg2-1; T reg3=2*var_inter[1]; reg1=reg0*reg1; reg2=var_inter[0]*reg2;
    reg3=reg3-1; T reg4=2*var_inter[2]; reg3=var_inter[1]*reg3; reg2=val[1]*reg2; reg1=val[0]*reg1;
    reg4=reg4-1; reg0=4*reg0; reg2=reg1+reg2; reg4=var_inter[2]*reg4; reg3=val[2]*reg3;
    reg1=var_inter[0]*reg0; T reg5=4*var_inter[0]; reg3=reg2+reg3; reg4=val[3]*reg4; reg4=reg3+reg4;
    reg1=val[4]*reg1; reg2=var_inter[1]*reg5; reg1=reg4+reg1; reg2=val[5]*reg2; reg3=var_inter[1]*reg0;
    reg2=reg1+reg2; reg3=val[6]*reg3; reg0=var_inter[2]*reg0; reg1=4*var_inter[1]; reg3=reg2+reg3;
    reg0=val[7]*reg0; reg5=var_inter[2]*reg5; reg1=var_inter[2]*reg1; reg5=val[8]*reg5; reg0=reg3+reg0;
    reg5=reg0+reg5; reg1=val[9]*reg1; res=reg1+reg5;

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
