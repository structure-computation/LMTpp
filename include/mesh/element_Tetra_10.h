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
    T reg0=3*nodes[0]->pos[2]; T reg1=3*nodes[0]->pos[1]; T reg2=2*nodes[4]->pos[1]; T reg3=nodes[2]->pos[1]+reg1; T reg4=nodes[1]->pos[1]+reg1;
    T reg5=4*nodes[4]->pos[2]; T reg6=4*nodes[4]->pos[1]; T reg7=nodes[1]->pos[2]+reg0; T reg8=nodes[3]->pos[2]+reg0; T reg9=2*nodes[4]->pos[2];
    T reg10=nodes[3]->pos[1]+reg1; T reg11=nodes[2]->pos[2]+reg0; reg8=reg8-reg9; reg10=reg10-reg2; T reg12=2*nodes[6]->pos[1];
    T reg13=2*nodes[5]->pos[1]; reg2=reg3-reg2; reg3=2*nodes[6]->pos[2]; T reg14=2*nodes[5]->pos[2]; reg9=reg11-reg9;
    reg7=reg7-reg5; reg11=3*nodes[0]->pos[0]; reg4=reg4-reg6; reg4=reg13+reg4; reg9=reg9+reg14;
    T reg15=4*nodes[6]->pos[2]; T reg16=4*nodes[7]->pos[2]; reg8=reg8-reg3; T reg17=2*nodes[4]->pos[0]; reg7=reg14+reg7;
    reg14=nodes[1]->pos[0]+reg11; T reg18=4*nodes[4]->pos[0]; T reg19=nodes[2]->pos[0]+reg11; reg13=reg2+reg13; reg2=4*nodes[6]->pos[1];
    T reg20=4*nodes[7]->pos[1]; reg10=reg10-reg12; reg10=reg10-reg20; T reg21=nodes[3]->pos[0]+reg11; reg3=reg7-reg3;
    reg12=reg4-reg12; reg4=2*nodes[7]->pos[2]; reg9=reg9-reg15; reg19=reg19-reg17; reg7=2*nodes[8]->pos[1];
    reg14=reg14-reg18; T reg22=2*nodes[5]->pos[0]; reg13=reg13-reg2; T reg23=2*nodes[7]->pos[1]; reg8=reg8-reg16;
    T reg24=2*nodes[8]->pos[2]; reg3=reg3-reg4; T reg25=4*nodes[6]->pos[0]; reg19=reg22+reg19; T reg26=2*nodes[6]->pos[0];
    reg22=reg14+reg22; reg14=2*nodes[9]->pos[2]; reg8=reg8+reg24; reg17=reg21-reg17; reg10=reg10+reg7;
    reg12=reg12-reg23; reg4=reg9-reg4; reg23=reg13-reg23; reg9=2*nodes[9]->pos[1]; reg8=reg8+reg14;
    reg22=reg22-reg26; reg12=reg7+reg12; reg19=reg19-reg25; reg7=2*nodes[7]->pos[0]; reg3=reg24+reg3;
    reg26=reg17-reg26; reg10=reg9+reg10; reg13=4*nodes[7]->pos[0]; reg9=reg23+reg9; reg4=reg14+reg4;
    reg14=reg10*reg3; reg26=reg26-reg13; reg17=reg8*reg12; reg21=2*nodes[9]->pos[0]; reg19=reg19-reg7;
    reg7=reg22-reg7; reg22=2*nodes[8]->pos[0]; reg8=reg9*reg8; reg10=reg4*reg10; reg3=reg9*reg3;
    reg12=reg4*reg12; reg26=reg22+reg26; reg22=reg7+reg22; reg10=reg8-reg10; reg14=reg17-reg14;
    reg19=reg19+reg21; reg10=reg22*reg10; reg14=reg19*reg14; reg26=reg21+reg26; reg3=reg12-reg3;
    reg14=reg10-reg14; reg3=reg26*reg3; T det_jac=reg14+reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[1],nodes[3],nodes[2],nodes[4],nodes[8],nodes[7],nodes[6],nodes[5],nodes[9]};
        for(unsigned i=0;i<10;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[1]; T reg2=2*reg0;
    T reg3=2*var_inter[2]; T reg4=reg1-1; T reg5=reg2-1; T reg6=reg3-1; reg2=reg2+reg5;
    T reg7=2*var_inter[0]; reg3=reg3+reg6; reg1=reg1+reg4; T reg8=pos_nodes[3][0]*reg3; T reg9=pos_nodes[2][2]*reg1;
    T reg10=pos_nodes[2][1]*reg1; T reg11=pos_nodes[3][2]*reg3; T reg12=pos_nodes[0][2]*reg2; T reg13=reg7-1; T reg14=pos_nodes[3][1]*reg3;
    T reg15=4*var_inter[0]; T reg16=pos_nodes[0][0]*reg2; T reg17=pos_nodes[0][1]*reg2; T reg18=pos_nodes[2][0]*reg1; reg14=reg14-reg17;
    reg18=reg18-reg16; T reg19=4*var_inter[2]; T reg20=reg15*pos_nodes[4][0]; reg10=reg10-reg17; T reg21=reg15*pos_nodes[4][1];
    T reg22=reg15*pos_nodes[4][2]; reg7=reg7+reg13; reg9=reg9-reg12; reg13=reg13*var_inter[0]; T reg23=4*reg0;
    T reg24=4*var_inter[1]; reg11=reg11-reg12; reg5=reg0*reg5; reg8=reg8-reg16; reg8=reg8-reg20;
    reg20=reg18-reg20; reg0=reg15*pos_nodes[5][0]; reg18=reg15*pos_nodes[5][1]; reg10=reg10-reg21; T reg25=reg24*pos_nodes[6][1];
    T reg26=pos_nodes[1][1]*reg7; T reg27=reg23-reg19; T reg28=reg5*pos_nodes[0][0]; T reg29=reg13*pos_nodes[1][0]; reg21=reg14-reg21;
    reg4=var_inter[1]*reg4; reg11=reg11-reg22; reg14=reg15*pos_nodes[5][2]; reg22=reg9-reg22; reg9=reg24*pos_nodes[6][2];
    T reg30=reg23-reg15; T reg31=reg23-reg24; T reg32=pos_nodes[1][0]*reg7; T reg33=reg5*pos_nodes[0][1]; T reg34=reg13*pos_nodes[1][1];
    T reg35=reg24*pos_nodes[6][0]; reg11=reg11-reg9; reg17=reg26-reg17; reg26=pos_nodes[4][1]*reg30; T reg36=pos_nodes[7][2]*reg27;
    reg28=reg29+reg28; reg29=reg13*pos_nodes[1][2]; T reg37=reg5*pos_nodes[0][2]; T reg38=pos_nodes[6][2]*reg31; reg14=reg22+reg14;
    reg18=reg10+reg18; reg10=pos_nodes[6][1]*reg31; reg22=pos_nodes[1][2]*reg7; reg33=reg34+reg33; reg34=pos_nodes[2][1]*reg4;
    reg21=reg21-reg25; T reg39=pos_nodes[7][1]*reg27; reg6=reg6*var_inter[2]; reg16=reg32-reg16; reg32=pos_nodes[4][0]*reg30;
    reg0=reg20+reg0; reg20=pos_nodes[6][0]*reg31; reg8=reg8-reg35; T reg40=pos_nodes[7][0]*reg27; T reg41=pos_nodes[2][0]*reg4;
    reg20=reg0+reg20; reg10=reg18+reg10; reg0=reg15*pos_nodes[8][2]; reg18=pos_nodes[7][0]*reg19; reg39=reg21+reg39;
    reg21=reg15*pos_nodes[8][1]; T reg42=reg24*pos_nodes[5][0]; reg32=reg16+reg32; reg33=reg34+reg33; reg16=reg6*pos_nodes[3][1];
    reg34=pos_nodes[7][2]*reg19; reg37=reg29+reg37; reg29=reg23*var_inter[0]; reg12=reg22-reg12; reg22=pos_nodes[4][2]*reg30;
    T reg43=pos_nodes[2][2]*reg4; T reg44=reg15*pos_nodes[8][0]; reg40=reg8+reg40; reg26=reg17+reg26; reg38=reg14+reg38;
    reg8=reg24*pos_nodes[5][1]; reg14=reg6*pos_nodes[3][0]; reg28=reg41+reg28; reg36=reg11+reg36; reg11=pos_nodes[7][1]*reg19;
    reg17=pos_nodes[9][2]*reg19; reg37=reg43+reg37; reg41=reg6*pos_nodes[3][2]; reg38=reg38-reg34; reg43=reg24*pos_nodes[9][2];
    T reg45=reg29*pos_nodes[4][1]; reg16=reg33+reg16; reg14=reg28+reg14; reg22=reg12+reg22; reg12=reg24*pos_nodes[5][2];
    reg28=reg15*var_inter[1]; reg33=reg24*pos_nodes[9][0]; T reg46=reg29*pos_nodes[4][0]; reg44=reg40+reg44; reg42=reg32+reg42;
    reg32=reg24*pos_nodes[9][1]; reg21=reg39+reg21; reg0=reg36+reg0; reg8=reg26+reg8; reg26=pos_nodes[9][0]*reg19;
    reg20=reg20-reg18; reg10=reg10-reg11; reg36=pos_nodes[9][1]*reg19; reg12=reg22+reg12; reg26=reg20+reg26;
    reg20=reg23*var_inter[1]; reg22=reg28*pos_nodes[5][0]; reg46=reg14+reg46; reg17=reg38+reg17; reg25=reg8-reg25;
    reg41=reg37+reg41; reg8=reg29*pos_nodes[4][2]; reg36=reg10+reg36; reg43=reg0+reg43; reg33=reg44+reg33;
    reg0=reg28*pos_nodes[5][1]; reg45=reg16+reg45; reg35=reg42-reg35; reg32=reg21+reg32; reg9=reg12-reg9;
    reg23=reg23*var_inter[2]; reg10=reg33*reg17; reg12=reg26*reg43; reg14=reg32*reg17; reg16=reg36*reg43;
    reg21=reg20*pos_nodes[6][0]; reg11=reg25-reg11; reg25=pos_nodes[8][1]*reg19; reg22=reg46+reg22; reg37=pos_nodes[8][0]*reg19;
    reg18=reg35-reg18; reg0=reg45+reg0; reg35=reg20*pos_nodes[6][1]; reg38=reg28*pos_nodes[5][2]; reg8=reg41+reg8;
    reg39=reg20*pos_nodes[6][2]; reg38=reg8+reg38; reg14=reg16-reg14; reg8=reg26*reg32; reg10=reg12-reg10;
    reg40=reg33*reg36; reg41=reg23*pos_nodes[7][0]; reg21=reg22+reg21; reg25=reg11+reg25; reg37=reg18+reg37;
    reg35=reg0+reg35; reg0=reg23*pos_nodes[7][1]; reg11=reg15*var_inter[2]; reg34=reg9-reg34; reg9=pos_nodes[8][2]*reg19;
    reg18=reg11*pos_nodes[8][0]; reg22=reg37*reg14; reg41=reg21+reg41; reg21=reg25*reg10; reg42=reg24*var_inter[2];
    reg40=reg8-reg40; reg44=reg23*pos_nodes[7][2]; reg39=reg38+reg39; reg9=reg34+reg9; reg0=reg35+reg0;
    reg34=reg11*pos_nodes[8][1]; reg35=reg26*reg9; reg38=reg25*reg43; reg45=reg9*reg40; reg46=reg32*reg9;
    reg22=reg21-reg22; reg21=reg25*reg17; T reg47=reg36*reg9; T reg48=reg37*reg43; T reg49=reg33*reg9;
    T reg50=reg37*reg17; T reg51=reg42*pos_nodes[9][1]; reg34=reg0+reg34; reg44=reg39+reg44; reg0=reg11*pos_nodes[8][2];
    reg39=reg42*pos_nodes[9][0]; reg18=reg41+reg18; reg49=reg48-reg49; reg35=reg50-reg35; reg47=reg21-reg47;
    reg41=reg37*reg32; reg51=reg34+reg51; reg34=reg33*reg25; reg46=reg38-reg46; reg39=reg18+reg39;
    reg45=reg22-reg45; reg18=reg37*reg36; reg0=reg44+reg0; reg22=reg42*pos_nodes[9][2]; reg44=reg26*reg25;
    reg44=reg18-reg44; reg35=reg35/reg45; reg34=reg41-reg34; reg49=reg49/reg45; reg10=reg10/reg45;
    reg51=pos[1]-reg51; reg47=reg47/reg45; reg46=reg46/reg45; reg14=reg14/reg45; reg22=reg0+reg22;
    reg39=pos[0]-reg39; reg47=reg39*reg47; reg49=reg51*reg49; reg35=reg51*reg35; reg46=reg39*reg46;
    reg10=reg51*reg10; reg14=reg39*reg14; reg44=reg44/reg45; reg34=reg34/reg45; reg45=reg40/reg45;
    reg22=pos[2]-reg22; reg45=reg22*reg45; reg14=reg10-reg14; reg34=reg22*reg34; reg49=reg46-reg49;
    reg44=reg22*reg44; reg47=reg35-reg47; var_inter[0]=reg14-reg45; var_inter[1]=reg34+reg49; var_inter[2]=reg47-reg44;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra_10 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*reg0; T reg2=2*var_inter[1];
    T reg3=2*var_inter[2]; T reg4=reg1-1; T reg5=reg3-1; T reg6=reg2-1; T reg7=2*var_inter[0];
    reg1=reg4+reg1; reg3=reg3+reg5; reg2=reg6+reg2; T reg8=pos_nodes[2][2]*reg2; T reg9=pos_nodes[0][2]*reg1;
    T reg10=pos_nodes[0][0]*reg1; T reg11=pos_nodes[2][0]*reg2; T reg12=pos_nodes[3][2]*reg3; T reg13=pos_nodes[3][1]*reg3; T reg14=pos_nodes[3][0]*reg3;
    T reg15=4*var_inter[0]; T reg16=pos_nodes[2][1]*reg2; T reg17=reg7-1; T reg18=pos_nodes[0][1]*reg1; reg16=reg16-reg18;
    T reg19=pos_nodes[4][1]*reg15; T reg20=4*reg0; T reg21=pos_nodes[4][2]*reg15; reg8=reg8-reg9; reg0=reg4*reg0;
    reg7=reg7+reg17; reg11=reg11-reg10; reg4=4*var_inter[2]; T reg22=pos_nodes[4][0]*reg15; reg13=reg13-reg18;
    reg17=reg17*var_inter[0]; T reg23=4*var_inter[1]; reg12=reg12-reg9; reg14=reg14-reg10; T reg24=reg0*pos_nodes[0][0];
    T reg25=reg20-reg23; T reg26=pos_nodes[1][0]*reg17; reg13=reg13-reg19; reg11=reg11-reg22; T reg27=pos_nodes[1][1]*reg7;
    T reg28=pos_nodes[5][0]*reg15; T reg29=pos_nodes[5][1]*reg15; reg19=reg16-reg19; reg16=reg20-reg4; T reg30=pos_nodes[6][1]*reg23;
    reg22=reg14-reg22; reg12=reg12-reg21; reg14=pos_nodes[6][0]*reg23; T reg31=reg0*pos_nodes[0][1]; T reg32=pos_nodes[1][1]*reg17;
    T reg33=pos_nodes[1][0]*reg7; T reg34=reg20-reg15; T reg35=reg23*pos_nodes[6][2]; reg6=reg6*var_inter[1]; reg21=reg8-reg21;
    reg8=pos_nodes[5][2]*reg15; T reg36=pos_nodes[7][2]*reg16; T reg37=pos_nodes[4][1]*reg34; reg18=reg27-reg18; reg26=reg24+reg26;
    reg24=reg0*pos_nodes[0][2]; reg27=pos_nodes[1][2]*reg17; reg12=reg12-reg35; T reg38=pos_nodes[6][2]*reg25; reg8=reg21+reg8;
    reg29=reg19+reg29; reg19=pos_nodes[6][1]*reg25; reg21=pos_nodes[1][2]*reg7; reg32=reg31+reg32; reg31=pos_nodes[2][1]*reg6;
    T reg39=pos_nodes[7][1]*reg16; reg13=reg13-reg30; reg5=reg5*var_inter[2]; reg10=reg33-reg10; reg33=pos_nodes[4][0]*reg34;
    reg28=reg11+reg28; reg11=pos_nodes[6][0]*reg25; reg22=reg22-reg14; T reg40=pos_nodes[7][0]*reg16; T reg41=pos_nodes[2][0]*reg6;
    reg36=reg12+reg36; reg11=reg28+reg11; reg19=reg29+reg19; reg12=pos_nodes[7][0]*reg4; reg39=reg13+reg39;
    reg13=reg15*pos_nodes[8][1]; reg28=pos_nodes[5][0]*reg23; reg33=reg10+reg33; reg32=reg31+reg32; reg10=reg5*pos_nodes[3][1];
    reg38=reg8+reg38; reg26=reg41+reg26; reg8=reg5*pos_nodes[3][0]; reg9=reg21-reg9; reg21=pos_nodes[4][2]*reg34;
    reg29=pos_nodes[7][2]*reg4; reg31=reg15*pos_nodes[8][2]; reg41=pos_nodes[5][1]*reg23; reg37=reg18+reg37; reg40=reg22+reg40;
    reg27=reg24+reg27; reg18=reg20*var_inter[0]; reg22=pos_nodes[7][1]*reg4; reg24=pos_nodes[2][2]*reg6; T reg42=reg15*pos_nodes[8][0];
    reg28=reg33+reg28; reg33=reg18*pos_nodes[4][0]; reg10=reg32+reg10; reg32=reg18*pos_nodes[4][1]; T reg43=pos_nodes[9][2]*reg4;
    reg38=reg38-reg29; reg42=reg40+reg42; reg40=reg23*pos_nodes[9][0]; reg8=reg26+reg8; reg27=reg24+reg27;
    reg24=reg5*pos_nodes[3][2]; reg21=reg9+reg21; reg9=pos_nodes[5][2]*reg23; reg26=reg23*pos_nodes[9][1]; reg13=reg39+reg13;
    reg41=reg37+reg41; reg31=reg36+reg31; reg36=pos_nodes[9][0]*reg4; reg11=reg11-reg12; reg37=reg23*pos_nodes[9][2];
    reg39=reg15*var_inter[1]; reg19=reg19-reg22; T reg44=pos_nodes[9][1]*reg4; T reg45=reg18*pos_nodes[4][2]; reg9=reg21+reg9;
    reg36=reg11+reg36; reg24=reg27+reg24; reg11=pos_nodes[5][0]*reg39; reg33=reg8+reg33; reg40=reg42+reg40;
    reg44=reg19+reg44; reg8=reg20*var_inter[1]; reg43=reg38+reg43; reg19=pos_nodes[5][1]*reg39; reg32=reg10+reg32;
    reg30=reg41-reg30; reg14=reg28-reg14; reg37=reg31+reg37; reg26=reg13+reg26; reg45=reg24+reg45;
    reg20=reg20*var_inter[2]; reg10=pos_nodes[5][2]*reg39; reg13=pos_nodes[8][0]*reg4; reg12=reg14-reg12; reg19=reg32+reg19;
    reg14=pos_nodes[6][1]*reg8; reg11=reg33+reg11; reg21=pos_nodes[8][1]*reg4; reg22=reg30-reg22; reg24=pos_nodes[6][0]*reg8;
    reg27=reg26*reg43; reg28=reg44*reg37; reg30=reg36*reg37; reg31=reg40*reg43; reg35=reg9-reg35;
    reg21=reg22+reg21; reg31=reg30-reg31; reg9=reg40*reg44; reg22=reg20*pos_nodes[7][0]; reg13=reg12+reg13;
    reg24=reg11+reg24; reg11=reg15*var_inter[2]; reg14=reg19+reg14; reg12=pos_nodes[7][1]*reg20; reg19=reg36*reg26;
    reg27=reg28-reg27; reg32=reg8*pos_nodes[6][2]; reg10=reg45+reg10; reg33=pos_nodes[8][2]*reg4; reg29=reg35-reg29;
    reg35=reg13*reg27; reg38=pos_nodes[7][2]*reg20; reg32=reg10+reg32; reg10=reg21*reg31; reg9=reg19-reg9;
    reg22=reg24+reg22; reg24=reg11*pos_nodes[8][0]; reg12=reg14+reg12; reg14=reg11*pos_nodes[8][1]; reg41=reg23*var_inter[2];
    reg33=reg29+reg33; reg29=reg21*reg43; reg42=reg26*reg33; reg45=reg21*reg37; T reg46=reg44*reg33;
    T reg47=reg33*reg9; reg35=reg10-reg35; reg24=reg22+reg24; reg10=reg41*pos_nodes[9][0]; reg22=reg13*reg37;
    reg14=reg12+reg14; reg12=reg41*pos_nodes[9][1]; T reg48=reg40*reg33; T reg49=reg13*reg43; T reg50=reg36*reg33;
    T reg51=reg11*pos_nodes[8][2]; reg38=reg32+reg38; reg32=reg13*reg44; reg46=reg29-reg46; reg48=reg22-reg48;
    T reg52=reg36*reg21; reg50=reg49-reg50; reg42=reg45-reg42; T reg53=reg13*reg26; T reg54=reg40*reg21;
    reg51=reg38+reg51; reg38=reg41*pos_nodes[9][2]; reg12=reg14+reg12; reg10=reg24+reg10; reg47=reg35-reg47;
    reg10=pos[0]-reg10; reg31=reg31/reg47; reg48=reg48/reg47; reg38=reg51+reg38; reg46=reg46/reg47;
    reg52=reg32-reg52; reg27=reg27/reg47; reg50=reg50/reg47; reg12=pos[1]-reg12; reg42=reg42/reg47;
    reg54=reg53-reg54; reg31=reg12*reg31; reg42=reg10*reg42; reg48=reg12*reg48; reg46=reg10*reg46;
    reg50=reg12*reg50; reg27=reg10*reg27; reg52=reg52/reg47; reg54=reg54/reg47; reg47=reg9/reg47;
    reg38=pos[2]-reg38; reg47=reg38*reg47; reg27=reg31-reg27; reg54=reg38*reg54; reg48=reg42-reg48;
    reg52=reg38*reg52; reg46=reg50-reg46; var_inter[0]+=reg27-reg47; var_inter[1]+=reg54+reg48; var_inter[2]+=reg46-reg52;

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
    reg2=var_inter[0]*reg0; reg3=reg1+reg3; reg4=val[3]*reg4; reg1=4*var_inter[0]; T reg5=var_inter[1]*reg1;
    reg4=reg3+reg4; reg2=val[4]*reg2; reg3=var_inter[1]*reg0; reg5=val[5]*reg5; reg2=reg4+reg2;
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=2*var_inter[2]; T reg2=2*var_inter[1];
    T reg3=2*reg0; T reg4=2*var_inter[0]; T reg5=reg1-1; T reg6=reg2-1; T reg7=reg4-1;
    T reg8=reg3-1; reg1=reg1+reg5; reg4=reg4+reg7; reg3=reg3+reg8; T reg9=4*var_inter[0];
    reg2=reg2+reg6; T reg10=4*reg0; T reg11=reg10-reg9; T reg12=elem.pos(2)[2]*reg2; T reg13=elem.pos(3)[2]*reg1;
    T reg14=reg3*elem.pos(0)[2]; T reg15=elem.pos(1)[2]*reg4; T reg16=elem.pos(1)[1]*reg4; T reg17=elem.pos(2)[1]*reg2; T reg18=reg3*elem.pos(0)[1];
    T reg19=elem.pos(3)[1]*reg1; T reg20=elem.pos(4)[1]*reg9; reg13=reg13-reg14; T reg21=elem.pos(4)[1]*reg11; reg19=reg19-reg18;
    reg17=reg17-reg18; T reg22=4*var_inter[2]; T reg23=4*var_inter[1]; reg12=reg12-reg14; reg15=reg15-reg14;
    T reg24=elem.pos(4)[2]*reg9; T reg25=elem.pos(4)[2]*reg11; reg16=reg16-reg18; reg12=reg12-reg24; T reg26=elem.pos(5)[1]*reg9;
    reg17=reg17-reg20; T reg27=elem.pos(6)[1]*reg23; reg15=reg25+reg15; reg25=reg3*elem.pos(0)[0]; T reg28=elem.pos(6)[2]*reg23;
    T reg29=elem.pos(5)[2]*reg9; reg13=reg13-reg24; T reg30=reg10-reg22; reg2=elem.pos(2)[0]*reg2; reg4=elem.pos(1)[0]*reg4;
    reg16=reg21+reg16; reg21=elem.pos(5)[1]*reg23; T reg31=reg10-reg23; T reg32=elem.pos(5)[2]*reg23; reg19=reg19-reg20;
    reg13=reg13-reg28; reg19=reg19-reg27; reg26=reg17+reg26; reg4=reg4-reg25; reg17=elem.pos(7)[2]*reg30;
    reg1=elem.pos(3)[0]*reg1; T reg33=elem.pos(6)[1]*reg31; T reg34=elem.pos(7)[1]*reg30; reg2=reg2-reg25; reg12=reg29+reg12;
    reg29=elem.pos(4)[0]*reg9; reg11=elem.pos(4)[0]*reg11; T reg35=elem.pos(6)[2]*reg31; reg32=reg15+reg32; reg21=reg16+reg21;
    reg1=reg1-reg25; reg15=elem.pos(7)[1]*reg22; reg16=elem.pos(8)[1]*reg9; T reg36=elem.pos(5)[0]*reg23; T reg37=elem.pos(5)[0]*reg9;
    reg4=reg11+reg4; reg21=reg21-reg27; reg26=reg33+reg26; reg35=reg12+reg35; reg11=elem.pos(8)[2]*reg9;
    reg2=reg2-reg29; reg19=reg34+reg19; reg17=reg13+reg17; reg12=elem.pos(7)[2]*reg22; reg32=reg32-reg28;
    reg35=reg35-reg12; reg13=elem.pos(8)[2]*reg22; reg33=elem.pos(8)[1]*reg22; reg32=reg32-reg12; reg34=elem.pos(9)[1]*reg23;
    reg1=reg1-reg29; T reg38=elem.pos(9)[2]*reg22; T reg39=elem.pos(6)[0]*reg23; reg21=reg21-reg15; reg4=reg36+reg4;
    reg16=reg19+reg16; reg26=reg26-reg15; reg19=elem.pos(9)[2]*reg23; reg31=elem.pos(6)[0]*reg31; reg17=reg11+reg17;
    reg11=elem.pos(9)[1]*reg22; reg2=reg37+reg2; reg38=reg35+reg38; reg35=elem.pos(7)[0]*reg22; reg30=elem.pos(7)[0]*reg30;
    reg19=reg17+reg19; reg31=reg2+reg31; reg11=reg26+reg11; reg34=reg16+reg34; reg4=reg4-reg39;
    reg32=reg13+reg32; reg1=reg1-reg39; reg33=reg21+reg33; reg2=elem.pos(8)[0]*reg22; reg4=reg4-reg35;
    reg13=reg38*reg34; reg16=reg34*reg32; reg17=reg19*reg33; reg21=reg19*reg11; reg1=reg30+reg1;
    reg26=elem.pos(8)[0]*reg9; reg31=reg31-reg35; reg30=elem.pos(9)[0]*reg22; reg16=reg17-reg16; reg30=reg31+reg30;
    reg17=reg38*reg33; reg13=reg21-reg13; reg21=reg11*reg32; reg31=elem.pos(9)[0]*reg23; reg4=reg2+reg4;
    reg26=reg1+reg26; reg31=reg26+reg31; reg21=reg17-reg21; reg1=reg30*reg16; reg2=reg13*reg4;
    reg1=reg2-reg1; reg2=reg31*reg21; reg2=reg1+reg2; return reg2;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Tetra_10,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.44721359549995798321*elem.pos(2)[1]; T reg1=1.3416407864998739496*elem.pos(0)[1]; T reg2=0.44721359549995798321*elem.pos(3)[2]; T reg3=1.3416407864998739496*elem.pos(0)[2]; T reg4=1.3416407864998740607*elem.pos(1)[2];
    T reg5=0.44721359549995798321*elem.pos(2)[2]; T reg6=1.3416407864998740607*elem.pos(1)[1]; T reg7=0.44721359549995798321*elem.pos(3)[1]; T reg8=0.44721359549995798321*elem.pos(1)[1]; T reg9=0.44721359549995798321*elem.pos(1)[2];
    T reg10=0.44721359549995809424*elem.pos(0)[1]; T reg11=0.44721359549995809424*elem.pos(0)[2]; T reg12=reg0+reg1; T reg13=0.55278640450004201679*elem.pos(4)[1]; T reg14=1.7888543819998321549*elem.pos(4)[2];
    reg4=reg11+reg4; T reg15=reg10-reg0; T reg16=reg2+reg3; T reg17=0.55278640450004201679*elem.pos(4)[2]; T reg18=2.3416407864998740607*elem.pos(4)[1];
    T reg19=reg3+reg5; T reg20=1.7888543819998321549*elem.pos(4)[1]; reg6=reg10+reg6; T reg21=reg1+reg7; reg1=reg1+reg8;
    T reg22=1.7888543819998319329*elem.pos(4)[1]; T reg23=reg10-reg7; T reg24=reg11-reg2; reg3=reg3+reg9; T reg25=1.7888543819998319329*elem.pos(4)[2];
    T reg26=reg11-reg5; T reg27=2.3416407864998740607*elem.pos(4)[2]; T reg28=1.3416407864998740607*elem.pos(2)[1]; T reg29=1.3416407864998740607*elem.pos(2)[2]; reg28=reg10+reg28;
    reg29=reg11+reg29; T reg30=reg23-reg18; T reg31=0.44721359549995798321*elem.pos(2)[0]; T reg32=0.10000000000000004421*elem.pos(0)[2]; T reg33=1.3416407864998740607*elem.pos(3)[2];
    T reg34=0.55278640450004201679*elem.pos(6)[1]; T reg35=reg13+reg21; T reg36=reg17+reg19; T reg37=0.55278640450004201679*elem.pos(5)[2]; reg6=reg6-reg20;
    T reg38=0.099999999999999995089*elem.pos(1)[0]; T reg39=0.099999999999999995089*elem.pos(1)[2]; T reg40=0.10000000000000004421*elem.pos(0)[0]; T reg41=1.3416407864998740607*elem.pos(1)[0]; T reg42=0.44721359549995809424*elem.pos(0)[0];
    T reg43=1.3416407864998740607*elem.pos(3)[1]; reg18=reg15-reg18; T reg44=2.3416407864998740607*elem.pos(5)[1]; T reg45=0.10000000000000008145*elem.pos(1)[0]; T reg46=0.099999999999999982674*elem.pos(0)[0];
    T reg47=0.10000000000000004421*elem.pos(0)[1]; T reg48=0.099999999999999995089*elem.pos(1)[1]; T reg49=reg24-reg27; T reg50=0.099999999999999982674*elem.pos(0)[1]; T reg51=0.10000000000000008145*elem.pos(1)[1];
    reg27=reg26-reg27; T reg52=2.3416407864998740607*elem.pos(5)[2]; reg25=reg25-reg3; reg22=reg22-reg1; T reg53=0.55278640450004201679*elem.pos(5)[1];
    T reg54=reg12+reg13; reg4=reg4-reg14; T reg55=1.1102230246251565404e-16*elem.pos(4)[2]; T reg56=reg11-reg9; T reg57=1.1102230246251565404e-16*elem.pos(4)[1];
    T reg58=reg10-reg8; T reg59=reg16+reg17; T reg60=0.55278640450004201679*elem.pos(6)[2]; T reg61=1.3416407864998739496*elem.pos(0)[0]; T reg62=0.10000000000000008145*elem.pos(1)[2];
    T reg63=0.099999999999999982674*elem.pos(0)[2]; T reg64=0.44721359549995798321*elem.pos(1)[0]; T reg65=1.3416407864998740607*elem.pos(2)[0]; reg49=reg49-reg60; T reg66=1.1102230246251565404e-16*elem.pos(7)[2];
    T reg67=0.44721359549995798321*elem.pos(3)[0]; reg51=reg51-reg50; reg62=reg62-reg63; reg27=reg27+reg52; reg25=reg37+reg25;
    T reg68=reg53-reg54; T reg69=1.1102230246251565404e-16*elem.pos(6)[2]; reg24=reg24-reg17; T reg70=2.3416407864998740607*elem.pos(6)[2]; reg47=reg47-reg48;
    reg56=reg56-reg55; T reg71=0.099999999999999995089*elem.pos(2)[1]; T reg72=1.1102230246251565404e-16*elem.pos(6)[1]; reg41=reg41+reg42; reg18=reg18+reg44;
    reg58=reg58-reg57; reg45=reg45-reg46; T reg73=1.7888543819998321549*elem.pos(4)[0]; T reg74=1.7888543819998319329*elem.pos(4)[0]; reg43=reg10+reg43;
    T reg75=reg64+reg61; T reg76=1.7888543819998319329*elem.pos(7)[1]; reg23=reg23-reg13; T reg77=0.099999999999999995089*elem.pos(2)[2]; T reg78=reg35+reg34;
    T reg79=2.3416407864998740607*elem.pos(4)[0]; T reg80=2.3416407864998740607*elem.pos(6)[1]; T reg81=reg61+reg31; T reg82=0.55278640450004201679*elem.pos(4)[0]; T reg83=0.099999999999999995089*elem.pos(2)[0];
    T reg84=reg42-reg31; T reg85=reg59+reg60; reg33=reg11+reg33; T reg86=1.7888543819998319329*elem.pos(7)[2]; reg29=reg29-reg17;
    T reg87=1.1102230246251565404e-16*elem.pos(7)[1]; T reg88=1.7888543819998319329*elem.pos(6)[2]; reg30=reg30-reg34; reg4=reg37+reg4; T reg89=reg37-reg36;
    reg32=reg32-reg39; reg6=reg53+reg6; T reg90=1.7888543819998319329*elem.pos(6)[1]; reg40=reg40-reg38; reg22=reg53+reg22;
    reg28=reg28-reg13; reg44=reg44+reg58; reg6=reg6-reg34; T reg91=reg42-reg64; T reg92=1.1102230246251565404e-16*elem.pos(4)[0];
    reg29=reg37+reg29; reg65=reg42+reg65; reg15=reg15-reg13; reg41=reg41-reg73; reg27=reg27-reg69;
    T reg93=2.3416407864998740607*elem.pos(8)[1]; reg28=reg53+reg28; T reg94=1.7888543819998321549*elem.pos(6)[1]; reg52=reg52+reg56; reg4=reg4-reg60;
    reg26=reg26-reg17; reg49=reg49-reg66; reg30=reg30-reg87; reg17=reg33-reg17; reg23=reg23-reg80;
    reg33=reg38+reg46; T reg95=0.10000000000000008145*elem.pos(2)[0]; T reg96=2.3416407864998740607*elem.pos(8)[2]; reg18=reg18-reg72; T reg97=reg42-reg67;
    T reg98=reg84-reg79; T reg99=2.3416407864998740607*elem.pos(5)[0]; T reg100=1.7888543819998321549*elem.pos(6)[2]; reg24=reg24-reg70; reg61=reg61+reg67;
    reg51=reg51-reg71; reg25=reg25-reg60; T reg101=0.10000000000000008145*elem.pos(2)[1]; reg22=reg22-reg34; T reg102=reg48+reg50;
    T reg103=reg81+reg82; reg76=reg76-reg78; T reg104=0.55278640450004201679*elem.pos(8)[1]; T reg105=0.55278640450004201679*elem.pos(7)[2]; reg88=reg89+reg88;
    reg32=reg32-reg77; reg86=reg86-reg85; reg89=0.55278640450004201679*elem.pos(8)[2]; T reg106=0.099999999999999995089*elem.pos(3)[2]; T reg107=0.55278640450004201679*elem.pos(7)[1];
    reg90=reg68+reg90; reg68=0.55278640450004201679*elem.pos(5)[0]; reg74=reg74-reg75; reg62=reg62-reg77; T reg108=0.10000000000000008145*elem.pos(2)[2];
    T reg109=reg39+reg63; T reg110=0.099999999999999995089*elem.pos(3)[0]; reg40=reg40-reg83; reg13=reg43-reg13; reg45=reg45-reg83;
    reg47=reg47-reg71; reg43=0.099999999999999995089*elem.pos(3)[1]; reg56=reg37+reg56; reg74=reg74+reg68; T reg111=0.55278640450004201679*elem.pos(6)[0];
    reg80=reg44-reg80; reg44=0.32360679774997896214*elem.pos(4)[2]; reg79=reg97-reg79; reg32=reg32-reg106; reg70=reg52-reg70;
    reg4=reg4-reg105; reg52=0.32360679774997891248*elem.pos(4)[0]; reg90=reg90-reg107; T reg112=0.55278640450004201679*elem.pos(9)[1]; reg45=reg45-reg110;
    reg86=reg89+reg86; reg15=reg53+reg15; reg24=reg24-reg66; reg28=reg28-reg94; reg13=reg13-reg34;
    T reg113=1.7888543819998321549*elem.pos(7)[1]; reg40=reg40-reg110; reg91=reg91-reg92; reg58=reg53+reg58; reg53=0.32360679774997896214*elem.pos(4)[0];
    reg108=reg108-reg109; reg29=reg29-reg100; reg41=reg68+reg41; reg23=reg23-reg87; reg95=reg95-reg33;
    T reg114=0.32360679774997891248*elem.pos(4)[2]; reg62=reg62-reg106; reg65=reg65-reg82; T reg115=reg82+reg61; reg49=reg96+reg49;
    reg26=reg37+reg26; reg51=reg51-reg43; reg37=0.32360679774997891248*elem.pos(4)[1]; reg25=reg25-reg105; T reg116=0.32360679774997896214*elem.pos(4)[1];
    reg27=reg27-reg105; reg22=reg22-reg107; reg47=reg47-reg43; reg101=reg101-reg102; reg30=reg93+reg30;
    T reg117=1.7888543819998321549*elem.pos(7)[2]; reg17=reg17-reg60; T reg118=1.7888543819998319329*elem.pos(6)[0]; T reg119=reg68-reg103; reg6=reg6-reg107;
    T reg120=0.55278640450004201679*elem.pos(9)[2]; T reg121=1.3416407864998740607*elem.pos(3)[0]; reg88=reg88-reg105; reg18=reg18-reg107; T reg122=1.1102230246251565404e-16*elem.pos(6)[0];
    reg98=reg98+reg99; reg76=reg104+reg76; reg15=reg15-reg72; T reg123=0.32360679774997897748*elem.pos(5)[1]; reg116=reg47+reg116;
    reg47=0.076393202250021018215*elem.pos(5)[2]; reg84=reg84-reg82; reg13=reg13-reg113; reg108=reg108-reg106; T reg124=2.3416407864998740607*elem.pos(9)[2];
    reg37=reg51+reg37; reg51=0.076393202250021002874*elem.pos(4)[2]; reg121=reg42+reg121; reg44=reg32+reg44; reg32=reg77+reg109;
    T reg125=reg71+reg102; reg24=reg89+reg24; T reg126=0.10000000000000008145*elem.pos(3)[1]; T reg127=0.10000000000000008145*elem.pos(3)[2]; T reg128=0.076393202250021018215*elem.pos(5)[1];
    reg60=reg56-reg60; reg56=2.3416407864998740607*elem.pos(7)[2]; reg70=reg70-reg105; T reg129=1.7888543819998321549*elem.pos(6)[0]; reg65=reg68+reg65;
    reg97=reg97-reg82; reg34=reg58-reg34; reg58=reg83+reg33; T reg130=0.076393202250021002874*elem.pos(4)[1]; reg101=reg101-reg43;
    reg114=reg62+reg114; reg62=2.3416407864998740607*elem.pos(9)[1]; reg23=reg104+reg23; T reg131=0.10000000000000008145*elem.pos(3)[0]; T reg132=0.32360679774997897748*elem.pos(5)[2];
    reg26=reg26-reg69; reg80=reg80-reg107; reg105=reg29-reg105; reg17=reg17-reg117; reg29=2.3416407864998740607*elem.pos(7)[1];
    reg30=reg112+reg30; reg95=reg95-reg110; reg98=reg98-reg122; reg6=reg104+reg6; reg22=reg104+reg22;
    T reg133=1.7888543819998319329*elem.pos(7)[0]; T reg134=reg111+reg115; T reg135=0.32360679774997897748*elem.pos(5)[0]; reg52=reg45+reg52; reg45=1.1102230246251565404e-16*elem.pos(7)[0];
    reg79=reg79-reg111; reg4=reg89+reg4; reg25=reg89+reg25; reg76=reg112+reg76; reg88=reg120+reg88;
    reg86=reg86+reg120; reg90=reg90+reg112; reg74=reg74-reg111; T reg136=0.55278640450004201679*elem.pos(7)[0]; T reg137=0.076393202250021018215*elem.pos(5)[0];
    reg18=reg112+reg18; reg53=reg40+reg53; reg99=reg99+reg91; reg40=2.3416407864998740607*elem.pos(6)[0]; reg49=reg120+reg49;
    reg118=reg119+reg118; reg27=reg120+reg27; reg41=reg41-reg111; reg107=reg28-reg107; reg28=0.076393202250021002874*elem.pos(4)[0];
    reg119=reg88*reg76; reg60=reg60-reg56; T reg138=reg90*reg86; T reg139=reg30*reg4; reg56=reg26-reg56;
    reg41=reg41-reg136; reg131=reg131-reg58; reg101=reg101+reg130; reg34=reg34-reg29; reg52=reg52+reg135;
    reg126=reg126-reg125; reg91=reg68+reg91; reg26=0.076393202250021002874*elem.pos(6)[0]; T reg140=reg18*reg49; reg84=reg68+reg84;
    reg49=reg49*reg6; reg13=reg104+reg13; reg98=reg98-reg136; reg29=reg15-reg29; reg17=reg89+reg17;
    reg15=0.55278640450004201679*elem.pos(9)[0]; reg118=reg118-reg136; reg30=reg27*reg30; reg68=0.55278640450004201679*elem.pos(8)[0]; reg65=reg65-reg129;
    T reg141=0.32360679774997896214*elem.pos(6)[1]; T reg142=0.32360679774997896214*elem.pos(6)[0]; reg114=reg114+reg132; T reg143=0.076393202250021002874*elem.pos(6)[2]; reg116=reg116+reg128;
    reg133=reg133-reg134; reg23=reg23+reg62; reg95=reg95+reg28; reg127=reg127-reg32; reg108=reg108+reg51;
    reg105=reg120+reg105; reg53=reg53+reg137; reg99=reg99-reg40; reg24=reg24+reg124; reg107=reg112+reg107;
    reg74=reg74-reg136; reg40=reg97-reg40; reg97=0.076393202250021002874*elem.pos(6)[1]; reg44=reg44+reg47; T reg144=0.32360679774997896214*elem.pos(6)[2];
    reg37=reg37+reg123; reg86=reg86*reg22; reg70=reg89+reg70; reg76=reg76*reg25; reg89=2.3416407864998740607*elem.pos(8)[0];
    reg79=reg79-reg45; reg82=reg121-reg82; reg80=reg104+reg80; reg82=reg82-reg111; reg25=reg90*reg25;
    reg60=reg96+reg60; reg22=reg88*reg22; reg37=reg37+reg97; reg88=0.076393202250021002874*elem.pos(7)[0]; reg90=1.7888543819998321549*elem.pos(7)[0];
    reg76=reg86-reg76; reg86=0.32360679774997896214*elem.pos(7)[1]; reg13=reg112+reg13; reg127=reg51+reg127; reg84=reg84-reg122;
    reg141=reg116+reg141; reg133=reg68+reg133; reg34=reg93+reg34; reg51=0.076393202250021002874*elem.pos(7)[1]; reg52=reg52+reg26;
    reg118=reg118+reg15; reg74=reg68+reg74; reg40=reg40-reg45; reg139=reg49-reg139; reg144=reg44+reg144;
    reg44=reg23*reg70; reg49=0.32360679774997896214*elem.pos(7)[2]; reg93=reg24*reg80; reg79=reg89+reg79; reg6=reg27*reg6;
    reg4=reg18*reg4; reg18=0.32360679774997896214*elem.pos(7)[0]; reg65=reg65-reg136; reg142=reg53+reg142; reg114=reg114+reg143;
    reg27=0.076393202250021002874*elem.pos(7)[2]; reg23=reg105*reg23; reg95=reg135+reg95; reg53=0.32360679774997891248*elem.pos(6)[0]; reg136=reg99-reg136;
    reg24=reg107*reg24; reg29=reg62+reg29; reg98=reg15+reg98; reg30=reg140-reg30; reg17=reg120+reg17;
    reg119=reg138-reg119; reg62=0.32360679774997891248*elem.pos(6)[1]; reg96=2.3416407864998740607*elem.pos(7)[0]; reg41=reg68+reg41; reg111=reg91-reg111;
    reg56=reg124+reg56; reg126=reg130+reg126; reg101=reg123+reg101; reg91=0.32360679774997891248*elem.pos(6)[2]; reg108=reg132+reg108;
    reg131=reg28+reg131; reg114=reg114+reg27; reg28=0.076393202250021018215*elem.pos(8)[0]; reg133=reg15+reg133; reg62=reg101+reg62;
    reg25=reg22-reg25; reg119=reg74*reg119; reg86=reg141+reg86; reg22=0.32360679774997897748*elem.pos(8)[1]; reg18=reg142+reg18;
    reg76=reg118*reg76; reg74=0.32360679774997897748*elem.pos(8)[2]; reg37=reg37+reg51; reg49=reg144+reg49; reg126=reg128+reg126;
    reg91=reg108+reg91; reg99=0.076393202250021018215*elem.pos(8)[2]; reg101=0.32360679774997897748*elem.pos(8)[0]; reg111=reg111-reg96; reg82=reg82-reg90;
    reg30=reg41*reg30; reg41=reg13*reg60; reg104=reg17*reg34; reg17=reg29*reg17; reg52=reg52+reg88;
    reg4=reg6-reg4; reg131=reg137+reg131; reg79=reg15+reg79; reg53=reg95+reg53; reg23=reg24-reg23;
    reg139=reg98*reg139; reg13=reg56*reg13; reg70=reg107*reg70; reg80=reg105*reg80; reg96=reg84-reg96;
    reg127=reg47+reg127; reg136=reg68+reg136; reg65=reg15+reg65; reg6=0.076393202250021018215*elem.pos(8)[1]; reg24=2.3416407864998740607*elem.pos(9)[0];
    reg40=reg68+reg40; reg44=reg93-reg44; reg52=reg101+reg52; reg62=reg51+reg62; reg13=reg17-reg13;
    reg111=reg89+reg111; reg17=0.076393202250021018215*elem.pos(9)[2]; reg126=reg97+reg126; reg47=0.32360679774997891248*elem.pos(7)[1]; reg49=reg99+reg49;
    reg114=reg74+reg114; reg91=reg27+reg91; reg27=0.32360679774997891248*elem.pos(7)[0]; reg131=reg26+reg131; reg139=reg30-reg139;
    reg70=reg80-reg70; reg40=reg40+reg24; reg44=reg65*reg44; reg82=reg68+reg82; reg86=reg6+reg86;
    reg53=reg88+reg53; reg18=reg28+reg18; reg76=reg119-reg76; reg26=0.076393202250021018215*elem.pos(9)[1]; reg30=0.32360679774997891248*elem.pos(7)[2];
    reg127=reg143+reg127; reg4=reg79*reg4; reg25=reg133*reg25; reg41=reg104-reg41; reg96=reg24+reg96;
    reg34=reg56*reg34; reg37=reg22+reg37; reg60=reg29*reg60; reg23=reg136*reg23; reg24=0.076393202250021018215*elem.pos(9)[0];
    reg86=reg86+reg26; reg60=reg34-reg60; reg29=0.32360679774997897748*elem.pos(9)[0]; reg70=reg40*reg70; reg30=reg127+reg30;
    reg25=reg76+reg25; reg44=reg23-reg44; reg4=reg139+reg4; reg13=reg111*reg13; reg37=reg26+reg37;
    reg52=reg24+reg52; reg41=reg96*reg41; reg62=reg6+reg62; reg6=0.32360679774997897748*elem.pos(9)[1]; reg49=reg49+reg17;
    reg23=0.32360679774997897748*elem.pos(9)[2]; reg91=reg99+reg91; reg24=reg18+reg24; reg114=reg17+reg114; reg27=reg131+reg27;
    reg82=reg15+reg82; reg47=reg126+reg47; reg53=reg28+reg53; reg49=reg25*reg49; reg52=reg52*reg4;
    reg70=reg44+reg70; reg30=reg74+reg30; reg47=reg22+reg47; reg27=reg101+reg27; reg114=reg4*reg114;
    reg62=reg62+reg6; reg91=reg91+reg23; reg37=reg4*reg37; reg41=reg13-reg41; reg86=reg25*reg86;
    reg60=reg82*reg60; reg53=reg53+reg29; reg24=reg24*reg25; reg114=0.041666666666666664354*reg114; reg25=0.041666666666666664354*reg25;
    reg52=0.041666666666666664354*reg52; reg49=0.041666666666666664354*reg49; reg53=reg53*reg70; reg30=reg23+reg30; reg47=reg6+reg47;
    reg27=reg29+reg27; reg62=reg70*reg62; reg37=0.041666666666666664354*reg37; reg24=0.041666666666666664354*reg24; reg86=0.041666666666666664354*reg86;
    reg60=reg41+reg60; reg4=0.041666666666666664354*reg4; reg91=reg70*reg91; reg30=reg60*reg30; reg91=0.041666666666666664354*reg91;
    reg114=reg49+reg114; reg52=reg24+reg52; reg53=0.041666666666666664354*reg53; reg47=reg60*reg47; reg62=0.041666666666666664354*reg62;
    reg37=reg86+reg37; reg27=reg27*reg60; reg4=reg25+reg4; reg70=0.041666666666666664354*reg70; reg30=0.041666666666666664354*reg30;
    reg53=reg52+reg53; reg27=0.041666666666666664354*reg27; reg70=reg4+reg70; reg60=0.041666666666666664354*reg60; reg91=reg114+reg91;
    reg62=reg37+reg62; reg47=0.041666666666666664354*reg47; reg60=reg70+reg60; reg27=reg53+reg27; reg47=reg62+reg47;
    reg30=reg91+reg30; res[0]=reg27/reg60; res[1]=reg47/reg60; res[2]=reg30/reg60;

    return res;
}
}
#endif // LMT_TETRA_10
