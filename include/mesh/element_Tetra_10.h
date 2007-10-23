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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[0]; T reg2=2*reg0;
    T reg3=reg1-1; T reg4=2*var_inter[1]; T reg5=reg2-1; T reg6=2*var_inter[2]; T reg7=reg3*var_inter[0];
    T reg8=reg4-1; T reg9=reg0*reg5; T reg10=reg6-1; T reg11=reg8*var_inter[1]; T reg12=pos_nodes[0][0]*reg9;
    reg5=reg2+reg5; reg6=reg6+reg10; reg8=reg4+reg8; reg2=pos_nodes[1][1]*reg7; reg4=reg9*pos_nodes[0][1];
    T reg13=pos_nodes[1][0]*reg7; T reg14=pos_nodes[1][2]*reg7; T reg15=reg9*pos_nodes[0][2]; T reg16=pos_nodes[3][2]*reg6; T reg17=pos_nodes[0][0]*reg5;
    T reg18=pos_nodes[2][2]*reg8; T reg19=pos_nodes[0][2]*reg5; T reg20=pos_nodes[2][0]*reg8; T reg21=pos_nodes[3][0]*reg6; T reg22=pos_nodes[2][1]*reg11;
    reg2=reg4+reg2; reg13=reg12+reg13; reg4=pos_nodes[2][0]*reg11; reg12=pos_nodes[3][1]*reg6; T reg23=pos_nodes[2][1]*reg8;
    T reg24=pos_nodes[0][1]*reg5; T reg25=4*var_inter[0]; reg0=4*reg0; reg10=var_inter[2]*reg10; T reg26=pos_nodes[2][2]*reg11;
    reg14=reg15+reg14; reg15=pos_nodes[4][2]*reg25; reg18=reg18-reg19; T reg27=pos_nodes[4][1]*reg25; T reg28=pos_nodes[4][0]*reg25;
    reg20=reg20-reg17; reg23=reg23-reg24; reg4=reg13+reg4; reg13=pos_nodes[3][0]*reg10; T reg29=4*var_inter[2];
    reg21=reg21-reg17; reg3=reg1+reg3; reg16=reg16-reg19; reg12=reg12-reg24; reg1=4*var_inter[1];
    T reg30=pos_nodes[3][1]*reg10; T reg31=var_inter[0]*reg0; reg22=reg2+reg22; reg21=reg21-reg28; reg23=reg23-reg27;
    reg27=reg12-reg27; reg26=reg14+reg26; reg13=reg4+reg13; reg2=pos_nodes[4][0]*reg31; reg4=pos_nodes[3][2]*reg10;
    reg12=pos_nodes[5][1]*reg25; reg14=var_inter[1]*reg25; T reg32=pos_nodes[1][1]*reg3; reg16=reg16-reg15; T reg33=reg0-reg25;
    T reg34=reg0-reg1; T reg35=pos_nodes[1][0]*reg3; T reg36=pos_nodes[5][2]*reg25; reg15=reg18-reg15; reg18=pos_nodes[6][0]*reg1;
    T reg37=pos_nodes[6][2]*reg1; T reg38=pos_nodes[6][1]*reg1; T reg39=reg0-reg29; reg28=reg20-reg28; reg20=pos_nodes[5][0]*reg25;
    T reg40=pos_nodes[4][1]*reg31; reg30=reg22+reg30; reg22=pos_nodes[4][1]*reg33; reg24=reg32-reg24; reg4=reg26+reg4;
    reg26=pos_nodes[4][2]*reg31; reg12=reg23+reg12; reg23=pos_nodes[6][1]*reg34; reg27=reg27-reg38; reg32=pos_nodes[7][1]*reg39;
    reg40=reg30+reg40; reg30=pos_nodes[5][1]*reg14; T reg41=pos_nodes[1][2]*reg3; reg36=reg15+reg36; reg15=pos_nodes[6][2]*reg34;
    reg16=reg16-reg37; T reg42=pos_nodes[7][2]*reg39; reg17=reg35-reg17; reg35=pos_nodes[4][0]*reg33; T reg43=var_inter[1]*reg0;
    reg20=reg28+reg20; reg28=pos_nodes[6][0]*reg34; reg21=reg21-reg18; T reg44=pos_nodes[7][0]*reg39; reg2=reg13+reg2;
    reg13=pos_nodes[5][0]*reg14; reg44=reg21+reg44; reg42=reg16+reg42; reg16=pos_nodes[8][2]*reg25; reg15=reg36+reg15;
    reg28=reg20+reg28; reg20=pos_nodes[7][1]*reg29; reg21=pos_nodes[5][1]*reg1; reg30=reg40+reg30; reg36=pos_nodes[6][1]*reg43;
    reg35=reg17+reg35; reg0=var_inter[2]*reg0; reg17=pos_nodes[5][0]*reg1; reg19=reg41-reg19; reg40=pos_nodes[4][2]*reg33;
    reg41=pos_nodes[7][0]*reg29; T reg45=pos_nodes[7][2]*reg29; T reg46=pos_nodes[5][2]*reg14; reg26=reg4+reg26; reg22=reg24+reg22;
    reg23=reg12+reg23; reg13=reg2+reg13; reg2=pos_nodes[6][0]*reg43; reg32=reg27+reg32; reg4=pos_nodes[8][1]*reg25;
    reg12=pos_nodes[8][0]*reg25; reg2=reg13+reg2; reg13=pos_nodes[7][0]*reg0; reg24=pos_nodes[6][2]*reg43; reg27=pos_nodes[5][2]*reg1;
    reg40=reg19+reg40; reg46=reg26+reg46; reg19=pos_nodes[9][2]*reg1; reg23=reg23-reg20; reg17=reg35+reg17;
    reg26=pos_nodes[9][1]*reg29; reg16=reg42+reg16; reg35=var_inter[2]*reg25; reg21=reg22+reg21; reg22=pos_nodes[7][1]*reg0;
    reg36=reg30+reg36; reg30=pos_nodes[9][2]*reg29; reg42=pos_nodes[9][0]*reg1; reg12=reg44+reg12; reg28=reg28-reg41;
    reg44=pos_nodes[9][0]*reg29; reg4=reg32+reg4; reg32=pos_nodes[9][1]*reg1; reg15=reg15-reg45; reg30=reg15+reg30;
    reg18=reg17-reg18; reg19=reg16+reg19; reg27=reg40+reg27; reg24=reg46+reg24; reg15=pos_nodes[7][2]*reg0;
    reg16=pos_nodes[8][1]*reg35; reg22=reg36+reg22; reg38=reg21-reg38; reg44=reg28+reg44; reg32=reg4+reg32;
    reg42=reg12+reg42; reg4=var_inter[2]*reg1; reg26=reg23+reg26; reg13=reg2+reg13; reg2=pos_nodes[8][0]*reg35;
    reg12=reg26*reg19; reg17=reg32*reg30; reg21=reg44*reg19; reg23=reg42*reg30; reg37=reg27-reg37;
    reg41=reg18-reg41; reg18=pos_nodes[8][0]*reg29; reg15=reg24+reg15; reg24=pos_nodes[9][1]*reg4; reg16=reg22+reg16;
    reg2=reg13+reg2; reg13=pos_nodes[8][2]*reg35; reg22=pos_nodes[8][1]*reg29; reg20=reg38-reg20; reg27=pos_nodes[9][0]*reg4;
    reg13=reg15+reg13; reg15=pos_nodes[9][2]*reg4; reg27=reg2+reg27; reg22=reg20+reg22; reg24=reg16+reg24;
    reg2=reg42*reg26; reg18=reg41+reg18; reg45=reg37-reg45; reg16=pos_nodes[8][2]*reg29; reg23=reg21-reg23;
    reg20=reg44*reg32; reg17=reg12-reg17; reg28=reg22*reg23; reg36=reg18*reg17; reg37=var_inter[0]*reg22;
    reg38=var_inter[0]*reg18; reg15=reg13+reg15; reg2=reg20-reg2; reg16=reg45+reg16; reg27=pos[0]-reg27;
    reg24=pos[1]-reg24; reg13=reg18*reg30; reg40=reg44*reg16; reg41=reg42*reg16; reg45=reg26*reg16;
    reg46=reg18*reg19; reg36=reg28-reg36; reg28=var_inter[0]*reg16; T reg47=reg16*reg2; reg37=reg24+reg37;
    reg24=var_inter[1]*reg26; T reg48=reg22*reg19; T reg49=reg32*reg16; T reg50=reg22*reg30; reg38=reg27+reg38;
    reg27=var_inter[1]*reg44; reg15=pos[2]-reg15; reg47=reg36-reg47; reg41=reg46-reg41; reg49=reg48-reg49;
    reg45=reg50-reg45; reg36=reg18*reg32; T reg51=reg42*reg22; reg28=reg15+reg28; reg15=var_inter[1]*reg30;
    T reg52=reg18*reg26; reg37=reg24+reg37; reg24=reg44*reg22; reg40=reg13-reg40; reg38=reg27+reg38;
    reg27=var_inter[2]*reg42; T reg53=var_inter[2]*reg32; reg45=reg45/reg47; reg51=reg36-reg51; reg49=reg49/reg47;
    reg24=reg52-reg24; reg17=reg17/reg47; reg23=reg23/reg47; reg41=reg41/reg47; reg28=reg15+reg28;
    reg37=reg53+reg37; reg15=var_inter[2]*reg19; reg38=reg27+reg38; reg40=reg40/reg47; reg45=reg38*reg45;
    reg41=reg41*reg37; reg49=reg38*reg49; reg40=reg40*reg37; reg23=reg23*reg37; reg17=reg38*reg17;
    reg24=reg24/reg47; reg51=reg51/reg47; reg28=reg15+reg28; reg47=reg2/reg47; reg45=reg40-reg45;
    reg24=reg28*reg24; reg41=reg49-reg41; reg51=reg28*reg51; reg17=reg23-reg17; reg47=reg47*reg28;
    var_inter[1]=reg51+reg41; var_inter[0]=reg17-reg47; var_inter[2]=reg45-reg24;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[0];
    T reg3=2*var_inter[2]; T reg4=2*var_inter[1]; T reg5=reg2-1; T reg6=reg1-1; T reg7=reg3-1;
    T reg8=reg4-1; T reg9=reg5*var_inter[0]; T reg10=reg0*reg6; reg4=reg4+reg8; reg6=reg1+reg6;
    reg3=reg3+reg7; reg1=reg9*pos_nodes[1][1]; reg8=var_inter[1]*reg8; T reg11=reg10*pos_nodes[0][1]; T reg12=reg10*pos_nodes[0][0];
    T reg13=reg9*pos_nodes[1][0]; T reg14=reg9*pos_nodes[1][2]; T reg15=reg10*pos_nodes[0][2]; T reg16=pos_nodes[3][2]*reg3; T reg17=pos_nodes[0][0]*reg6;
    T reg18=pos_nodes[2][2]*reg4; T reg19=pos_nodes[0][2]*reg6; T reg20=pos_nodes[2][0]*reg4; T reg21=pos_nodes[2][1]*reg8; T reg22=pos_nodes[3][0]*reg3;
    reg1=reg11+reg1; reg11=4*var_inter[0]; reg13=reg12+reg13; reg12=pos_nodes[2][0]*reg8; T reg23=pos_nodes[3][1]*reg3;
    T reg24=pos_nodes[2][1]*reg4; T reg25=pos_nodes[0][1]*reg6; reg7=var_inter[2]*reg7; reg0=4*reg0; T reg26=var_inter[0]*reg0;
    T reg27=reg11*pos_nodes[4][2]; reg18=reg18-reg19; T reg28=pos_nodes[2][2]*reg8; reg20=reg20-reg17; T reg29=reg11*pos_nodes[4][0];
    T reg30=reg7*pos_nodes[3][0]; T reg31=reg7*pos_nodes[3][1]; reg21=reg1+reg21; reg22=reg22-reg17; reg14=reg15+reg14;
    reg24=reg24-reg25; reg16=reg16-reg19; reg1=4*var_inter[1]; reg15=reg11*pos_nodes[4][1]; reg5=reg2+reg5;
    reg2=4*var_inter[2]; reg23=reg23-reg25; reg12=reg13+reg12; reg24=reg24-reg15; reg13=reg11*pos_nodes[5][1];
    reg15=reg23-reg15; reg23=reg26*pos_nodes[4][0]; T reg32=reg11*var_inter[1]; reg12=reg30+reg12; reg22=reg22-reg29;
    reg30=reg1*pos_nodes[6][1]; T reg33=pos_nodes[1][1]*reg5; T reg34=reg0-reg1; T reg35=reg0-reg2; T reg36=pos_nodes[1][0]*reg5;
    T reg37=reg0-reg11; reg28=reg14+reg28; reg14=reg11*pos_nodes[5][2]; reg18=reg18-reg27; T reg38=reg1*pos_nodes[6][0];
    T reg39=reg1*pos_nodes[6][2]; reg27=reg16-reg27; reg29=reg20-reg29; reg16=reg11*pos_nodes[5][0]; reg20=reg7*pos_nodes[3][2];
    T reg40=reg26*pos_nodes[4][1]; reg21=reg31+reg21; reg27=reg27-reg39; reg31=pos_nodes[7][2]*reg35; T reg41=pos_nodes[4][1]*reg37;
    reg25=reg33-reg25; reg13=reg24+reg13; reg24=pos_nodes[6][1]*reg34; reg33=pos_nodes[6][2]*reg34; reg14=reg18+reg14;
    reg18=pos_nodes[1][2]*reg5; reg15=reg15-reg30; T reg42=pos_nodes[7][1]*reg35; T reg43=reg32*pos_nodes[5][1]; reg40=reg21+reg40;
    reg21=reg26*pos_nodes[4][2]; reg28=reg20+reg28; reg16=reg29+reg16; reg20=pos_nodes[6][0]*reg34; reg17=reg36-reg17;
    reg29=pos_nodes[4][0]*reg37; reg22=reg22-reg38; reg36=reg32*pos_nodes[5][0]; reg23=reg12+reg23; reg12=pos_nodes[7][0]*reg35;
    T reg44=var_inter[1]*reg0; reg0=var_inter[2]*reg0; reg12=reg22+reg12; reg22=reg11*pos_nodes[8][0]; reg20=reg16+reg20;
    reg16=reg11*pos_nodes[8][1]; reg43=reg40+reg43; reg40=reg44*pos_nodes[6][1]; reg33=reg14+reg33; reg29=reg17+reg29;
    reg19=reg18-reg19; reg14=pos_nodes[4][2]*reg37; reg17=reg1*pos_nodes[5][0]; reg18=pos_nodes[7][2]*reg2; T reg45=reg32*pos_nodes[5][2];
    reg21=reg28+reg21; reg28=pos_nodes[7][0]*reg2; T reg46=pos_nodes[7][1]*reg2; T reg47=reg44*pos_nodes[6][0]; reg36=reg23+reg36;
    reg24=reg13+reg24; reg31=reg27+reg31; reg13=reg1*pos_nodes[5][1]; reg41=reg25+reg41; reg23=reg11*pos_nodes[8][2];
    reg42=reg15+reg42; reg17=reg29+reg17; reg15=reg1*pos_nodes[5][2]; reg14=reg19+reg14; reg13=reg41+reg13;
    reg45=reg21+reg45; reg23=reg31+reg23; reg19=reg44*pos_nodes[6][2]; reg21=reg1*pos_nodes[9][2]; reg16=reg42+reg16;
    reg25=reg1*pos_nodes[9][1]; reg27=reg11*var_inter[2]; reg22=reg12+reg22; reg12=reg1*pos_nodes[9][0]; reg29=pos_nodes[9][1]*reg2;
    reg24=reg24-reg46; reg31=pos_nodes[9][0]*reg2; reg20=reg20-reg28; reg47=reg36+reg47; reg36=reg0*pos_nodes[7][0];
    reg40=reg43+reg40; reg41=reg0*pos_nodes[7][1]; reg42=pos_nodes[9][2]*reg2; reg33=reg33-reg18; reg38=reg17-reg38;
    reg17=reg1*var_inter[2]; reg42=reg33+reg42; reg21=reg23+reg21; reg29=reg24+reg29; reg36=reg47+reg36;
    reg30=reg13-reg30; reg13=reg27*pos_nodes[8][0]; reg15=reg14+reg15; reg12=reg22+reg12; reg19=reg45+reg19;
    reg14=reg0*pos_nodes[7][2]; reg25=reg16+reg25; reg31=reg20+reg31; reg16=reg27*pos_nodes[8][1]; reg41=reg40+reg41;
    reg13=reg36+reg13; reg14=reg19+reg14; reg19=pos_nodes[8][1]*reg2; reg46=reg30-reg46; reg20=reg17*pos_nodes[9][0];
    reg22=reg27*pos_nodes[8][2]; reg23=reg29*reg21; reg24=reg25*reg42; reg16=reg41+reg16; reg30=reg17*pos_nodes[9][1];
    reg33=pos_nodes[8][0]*reg2; reg28=reg38-reg28; reg39=reg15-reg39; reg15=reg12*reg42; reg36=reg31*reg21;
    reg22=reg14+reg22; reg14=reg17*pos_nodes[9][2]; reg20=reg13+reg20; reg19=reg46+reg19; reg30=reg16+reg30;
    reg24=reg23-reg24; reg13=reg31*reg25; reg16=reg12*reg29; reg15=reg36-reg15; reg38=pos_nodes[8][2]*reg2;
    reg18=reg39-reg18; reg33=reg28+reg33; reg16=reg13-reg16; reg28=reg19*reg15; reg39=reg33*reg24;
    reg40=var_inter[0]*reg19; reg41=var_inter[0]*reg33; reg14=reg22+reg14; reg20=pos[0]-reg20; reg30=pos[1]-reg30;
    reg38=reg18+reg38; reg18=reg33*reg42; reg22=reg31*reg38; reg43=reg29*reg38; reg45=reg12*reg38;
    reg46=reg33*reg21; reg14=pos[2]-reg14; reg39=reg28-reg39; reg28=var_inter[0]*reg38; reg47=reg38*reg16;
    reg40=reg30+reg40; reg30=var_inter[1]*reg29; T reg48=reg19*reg21; reg41=reg20+reg41; reg20=var_inter[1]*reg31;
    T reg49=reg25*reg38; T reg50=reg19*reg42; T reg51=reg33*reg25; reg49=reg48-reg49; reg47=reg39-reg47;
    reg45=reg46-reg45; reg43=reg50-reg43; reg39=reg12*reg19; reg28=reg14+reg28; reg14=var_inter[1]*reg42;
    T reg52=reg33*reg29; reg40=reg30+reg40; reg30=reg31*reg19; reg22=reg18-reg22; reg41=reg20+reg41;
    reg20=var_inter[2]*reg25; T reg53=var_inter[2]*reg12; reg43=reg43/reg47; reg49=reg49/reg47; reg39=reg51-reg39;
    reg30=reg52-reg30; reg24=reg24/reg47; reg15=reg15/reg47; reg45=reg45/reg47; reg28=reg14+reg28;
    reg40=reg20+reg40; reg14=var_inter[2]*reg21; reg41=reg53+reg41; reg22=reg22/reg47; reg43=reg41*reg43;
    reg45=reg45*reg40; reg49=reg41*reg49; reg22=reg22*reg40; reg15=reg15*reg40; reg24=reg41*reg24;
    reg30=reg30/reg47; reg39=reg39/reg47; reg28=reg14+reg28; reg47=reg16/reg47; reg43=reg22-reg43;
    reg30=reg28*reg30; reg45=reg49-reg45; reg39=reg28*reg39; reg24=reg15-reg24; reg47=reg47*reg28;
    var_inter[1]+=reg39+reg45; var_inter[0]+=reg24-reg47; var_inter[2]+=reg43-reg30;

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
    reg1=reg1-1; T reg3=2*var_inter[1]; reg2=reg2-1; reg2=reg0*reg2; T reg4=2*var_inter[2];
    reg3=reg3-1; reg1=var_inter[0]*reg1; reg2=val[0]*reg2; reg1=val[1]*reg1; reg4=reg4-1;
    reg3=var_inter[1]*reg3; reg3=val[2]*reg3; reg1=reg2+reg1; reg0=4*reg0; reg4=var_inter[2]*reg4;
    reg4=val[3]*reg4; reg3=reg1+reg3; reg1=4*var_inter[0]; reg2=var_inter[0]*reg0; reg2=val[4]*reg2;
    reg4=reg3+reg4; reg3=var_inter[1]*reg1; reg2=reg4+reg2; reg3=val[5]*reg3; reg4=var_inter[1]*reg0;
    reg4=val[6]*reg4; reg0=var_inter[2]*reg0; reg3=reg2+reg3; reg2=4*var_inter[1]; reg0=val[7]*reg0;
    reg1=var_inter[2]*reg1; reg4=reg3+reg4; reg2=var_inter[2]*reg2; reg1=val[8]*reg1; reg0=reg4+reg0;
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
