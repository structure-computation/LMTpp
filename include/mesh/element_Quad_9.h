#ifndef LMT_QUAD_9
#define LMT_QUAD_9
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_9 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 13, 26, 39, 52, 74, 96, 118, 140, 162, }; // fonction de lordre du poly
    static const double values[] = {
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.211324865405,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.94532721089,0.312871678857,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.312871678857,0.94532721089,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Quad_9 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=nodes[5]->pos[0]-nodes[7]->pos[0]; T reg1=nodes[6]->pos[1]-nodes[4]->pos[1]; T reg2=nodes[5]->pos[1]-nodes[7]->pos[1]; T reg3=nodes[6]->pos[0]-nodes[4]->pos[0]; reg1=reg0*reg1;
    reg3=reg2*reg3; T det_jac=reg1-reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[7],nodes[3],nodes[6],nodes[2],nodes[5],nodes[1],nodes[4],nodes[8]};
        for(unsigned i=0;i<9;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad_9 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.5-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=1-var_inter[0]; T reg3=4*reg0; T reg4=4*reg1;
    T reg5=4*reg2; T reg6=4*var_inter[0]; reg4=reg6+reg4; T reg7=1-var_inter[1]; reg3=reg5+reg3;
    T reg8=8*var_inter[0]; T reg9=8*reg2; reg6=reg6*reg1; reg5=reg0*reg5; T reg10=0.5-var_inter[1];
    T reg11=reg7*reg3; T reg12=reg6*reg7; T reg13=reg9*var_inter[0]; T reg14=reg9-reg8; T reg15=reg5*reg7;
    T reg16=reg10*reg6; T reg17=reg7*reg4; T reg18=reg5*reg10; T reg19=reg7*reg14; T reg20=var_inter[1]-0.5;
    reg17=reg10*reg17; reg18=reg15+reg18; reg16=reg12+reg16; T reg21=reg10*reg13; T reg22=reg10*reg11;
    T reg23=reg13*reg7; T reg24=pos_nodes[1][1]*reg16; reg19=reg10*reg19; T reg25=var_inter[1]*reg3; T reg26=pos_nodes[0][1]*reg18;
    T reg27=pos_nodes[0][1]*reg22; T reg28=pos_nodes[1][0]*reg17; T reg29=pos_nodes[0][0]*reg22; reg21=reg23+reg21; T reg30=reg5*reg20;
    T reg31=pos_nodes[0][0]*reg18; T reg32=pos_nodes[1][0]*reg16; T reg33=pos_nodes[1][1]*reg17; T reg34=reg5*var_inter[1]; reg4=var_inter[1]*reg4;
    T reg35=reg20*reg25; T reg36=pos_nodes[4][0]*reg19; reg29=reg28-reg29; reg28=reg6*var_inter[1]; reg12=reg10*reg12;
    reg32=reg31+reg32; reg15=reg10*reg15; reg31=8*reg0; reg27=reg33-reg27; reg33=pos_nodes[4][1]*reg19;
    T reg37=pos_nodes[4][0]*reg21; T reg38=reg6*reg20; reg30=reg34+reg30; reg24=reg26+reg24; reg26=pos_nodes[4][1]*reg21;
    reg37=reg32+reg37; reg32=pos_nodes[0][0]*reg15; reg36=reg29+reg36; reg29=pos_nodes[3][0]*reg35; T reg39=pos_nodes[3][0]*reg30;
    T reg40=reg13*reg20; reg38=reg28+reg38; reg26=reg24+reg26; reg24=pos_nodes[3][1]*reg30; T reg41=pos_nodes[3][1]*reg35;
    reg33=reg27+reg33; reg0=reg0*reg9; reg27=reg13*var_inter[1]; T reg42=pos_nodes[0][1]*reg15; T reg43=reg12*pos_nodes[1][1];
    reg23=reg10*reg23; reg10=8*reg1; T reg44=reg12*pos_nodes[1][0]; reg31=reg9+reg31; reg14=var_inter[1]*reg14;
    reg4=reg20*reg4; reg44=reg32+reg44; reg9=pos_nodes[4][0]*reg23; reg37=reg39-reg37; reg32=var_inter[1]*reg0;
    reg40=reg27+reg40; reg39=pos_nodes[2][0]*reg38; T reg45=pos_nodes[4][1]*reg23; reg41=reg33-reg41; reg33=pos_nodes[2][1]*reg4;
    T reg46=pos_nodes[2][1]*reg38; reg26=reg24-reg26; reg43=reg42+reg43; reg34=reg34*reg20; reg14=reg20*reg14;
    reg24=reg7*reg31; reg10=reg8+reg10; reg42=16*var_inter[0]; T reg47=reg7*reg0; reg8=reg1*reg8;
    reg29=reg36-reg29; reg1=pos_nodes[2][0]*reg4; reg2=16*reg2; reg36=pos_nodes[3][0]*reg34; reg9=reg44+reg9;
    reg44=var_inter[0]*reg2; T reg48=pos_nodes[3][1]*reg34; T reg49=var_inter[1]*reg24; reg10=reg7*reg10; reg28=reg20*reg28;
    reg45=reg43+reg45; reg43=pos_nodes[6][0]*reg40; reg39=reg37+reg39; reg32=reg47-reg32; reg37=var_inter[1]*reg8;
    T reg50=pos_nodes[6][1]*reg14; reg33=reg41+reg33; reg41=reg7*reg8; reg1=reg29+reg1; reg29=pos_nodes[6][0]*reg14;
    T reg51=pos_nodes[6][1]*reg40; reg42=reg2-reg42; reg46=reg26+reg46; reg2=pos_nodes[7][1]*reg49; reg50=reg33+reg50;
    reg26=pos_nodes[7][1]*reg32; reg33=reg7*reg44; reg51=reg46+reg51; reg27=reg20*reg27; reg20=var_inter[1]*reg44;
    reg37=reg41-reg37; reg29=reg1+reg29; reg1=pos_nodes[7][0]*reg49; reg42=reg7*reg42; reg43=reg39+reg43;
    reg7=pos_nodes[7][0]*reg32; reg39=pos_nodes[2][1]*reg28; reg48=reg45+reg48; reg10=var_inter[1]*reg10; reg36=reg9+reg36;
    reg9=pos_nodes[2][0]*reg28; reg45=pos_nodes[5][0]*reg10; reg1=reg29-reg1; reg29=pos_nodes[5][1]*reg10; reg2=reg50-reg2;
    reg46=pos_nodes[6][1]*reg27; reg39=reg48+reg39; reg20=reg33-reg20; reg42=var_inter[1]*reg42; reg47=var_inter[1]*reg47;
    reg7=reg43+reg7; reg43=pos_nodes[5][0]*reg37; reg26=reg51+reg26; reg48=pos_nodes[5][1]*reg37; reg50=pos_nodes[6][0]*reg27;
    reg9=reg36+reg9; reg46=reg39+reg46; reg48=reg26+reg48; reg26=pos_nodes[8][1]*reg20; reg36=pos_nodes[7][1]*reg47;
    reg45=reg1+reg45; reg1=pos_nodes[8][0]*reg42; reg39=pos_nodes[8][1]*reg42; reg29=reg2+reg29; reg43=reg7+reg43;
    reg41=var_inter[1]*reg41; reg2=pos_nodes[8][0]*reg20; reg50=reg9+reg50; reg7=pos_nodes[7][0]*reg47; reg1=reg45+reg1;
    reg2=reg43+reg2; reg26=reg48+reg26; reg7=reg50+reg7; reg9=pos_nodes[5][0]*reg41; reg33=var_inter[1]*reg33;
    reg36=reg46+reg36; reg43=pos_nodes[5][1]*reg41; reg39=reg29+reg39; reg29=reg33*pos_nodes[8][1]; reg43=reg36+reg43;
    reg9=reg7+reg9; reg7=reg33*pos_nodes[8][0]; reg36=reg2*reg39; reg45=reg1*reg26; reg29=reg43+reg29;
    reg36=reg45-reg36; reg7=reg9+reg7; reg29=pos[1]-reg29; reg9=reg26/reg36; reg7=pos[0]-reg7;
    reg43=reg39/reg36; reg46=reg2/reg36; reg36=reg1/reg36; reg9=reg7*reg9; reg46=reg29*reg46;
    reg43=reg7*reg43; reg36=reg29*reg36; var_inter[0]=reg9-reg46; var_inter[1]=reg36-reg43;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_9 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.5-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=1-var_inter[0]; T reg3=4*reg0; T reg4=4*reg1;
    T reg5=4*reg2; T reg6=4*var_inter[0]; T reg7=8*reg2; T reg8=reg6*reg1; T reg9=0.5-var_inter[1];
    T reg10=1-var_inter[1]; T reg11=8*var_inter[0]; reg3=reg5+reg3; reg4=reg6+reg4; reg5=reg0*reg5;
    reg6=reg10*reg3; T reg12=reg7-reg11; T reg13=reg5*reg10; T reg14=reg10*reg4; T reg15=var_inter[0]*reg7;
    T reg16=reg9*reg8; T reg17=reg5*reg9; T reg18=reg10*reg8; reg16=reg18+reg16; reg17=reg13+reg17;
    T reg19=reg15*reg9; reg14=reg9*reg14; T reg20=reg10*reg12; T reg21=reg9*reg6; T reg22=var_inter[1]-0.5;
    T reg23=reg15*reg10; reg20=reg9*reg20; T reg24=pos_nodes[1][0]*reg16; T reg25=pos_nodes[0][0]*reg17; T reg26=pos_nodes[1][1]*reg14;
    T reg27=pos_nodes[0][1]*reg21; T reg28=var_inter[1]*reg3; T reg29=reg5*reg22; T reg30=pos_nodes[1][1]*reg16; T reg31=reg5*var_inter[1];
    T reg32=pos_nodes[0][1]*reg17; reg19=reg23+reg19; T reg33=pos_nodes[0][0]*reg21; T reg34=pos_nodes[1][0]*reg14; T reg35=8*reg0;
    reg4=var_inter[1]*reg4; T reg36=reg22*reg28; reg33=reg34-reg33; reg29=reg31+reg29; reg34=var_inter[1]*reg8;
    T reg37=reg22*reg8; T reg38=pos_nodes[4][0]*reg19; T reg39=pos_nodes[4][0]*reg20; reg13=reg13*reg9; reg32=reg30+reg32;
    reg18=reg9*reg18; reg30=pos_nodes[4][1]*reg19; reg27=reg26-reg27; reg24=reg25+reg24; reg25=pos_nodes[4][1]*reg20;
    reg26=pos_nodes[1][1]*reg18; reg24=reg38+reg24; reg38=reg13*pos_nodes[0][1]; reg33=reg39+reg33; reg39=pos_nodes[3][0]*reg36;
    reg32=reg30+reg32; reg30=pos_nodes[3][0]*reg29; T reg40=reg15*reg22; reg9=reg23*reg9; reg37=reg34+reg37;
    reg23=reg13*pos_nodes[0][0]; T reg41=pos_nodes[3][1]*reg29; T reg42=pos_nodes[3][1]*reg36; reg27=reg25+reg27; reg25=pos_nodes[1][0]*reg18;
    reg35=reg7+reg35; T reg43=8*reg1; reg7=reg0*reg7; reg12=var_inter[1]*reg12; reg4=reg22*reg4;
    reg0=reg15*var_inter[1]; T reg44=reg10*reg35; reg12=reg22*reg12; reg31=reg31*reg22; reg40=reg0+reg40;
    T reg45=reg7*var_inter[1]; T reg46=reg9*pos_nodes[4][0]; T reg47=reg9*pos_nodes[4][1]; reg26=reg38+reg26; reg38=reg7*reg10;
    reg1=reg11*reg1; T reg48=pos_nodes[2][0]*reg37; reg24=reg30-reg24; reg25=reg23+reg25; reg23=pos_nodes[2][1]*reg4;
    reg30=pos_nodes[2][1]*reg37; reg32=reg41-reg32; reg42=reg27-reg42; reg27=16*var_inter[0]; reg2=16*reg2;
    reg43=reg11+reg43; reg39=reg33-reg39; reg11=pos_nodes[2][0]*reg4; reg23=reg42+reg23; reg48=reg24+reg48;
    reg24=pos_nodes[6][0]*reg40; reg33=pos_nodes[6][1]*reg12; reg41=pos_nodes[6][1]*reg40; reg30=reg32+reg30; reg32=var_inter[0]*reg2;
    reg42=reg31*pos_nodes[3][0]; reg25=reg46+reg25; reg46=reg31*pos_nodes[3][1]; reg26=reg47+reg26; reg47=var_inter[1]*reg44;
    reg34=reg22*reg34; reg45=reg38-reg45; T reg49=pos_nodes[6][0]*reg12; reg11=reg39+reg11; reg43=reg10*reg43;
    reg39=reg1*var_inter[1]; reg27=reg2-reg27; reg2=reg1*reg10; reg49=reg11+reg49; reg43=var_inter[1]*reg43;
    reg33=reg23+reg33; reg27=reg10*reg27; reg11=pos_nodes[7][1]*reg47; reg23=pos_nodes[7][0]*reg47; reg10=reg32*reg10;
    T reg50=var_inter[1]*reg32; reg39=reg2-reg39; reg24=reg48+reg24; reg48=pos_nodes[7][0]*reg45; T reg51=pos_nodes[7][1]*reg45;
    reg41=reg30+reg41; reg0=reg22*reg0; reg42=reg25+reg42; reg22=reg34*pos_nodes[2][0]; reg46=reg26+reg46;
    reg25=reg34*pos_nodes[2][1]; reg11=reg33-reg11; reg26=pos_nodes[5][1]*reg43; reg51=reg41+reg51; reg30=pos_nodes[5][1]*reg39;
    reg25=reg46+reg25; reg33=reg0*pos_nodes[6][1]; reg27=var_inter[1]*reg27; reg23=reg49-reg23; reg41=pos_nodes[5][0]*reg43;
    reg50=reg10-reg50; reg38=reg38*var_inter[1]; reg48=reg24+reg48; reg24=pos_nodes[5][0]*reg39; reg22=reg42+reg22;
    reg42=reg0*pos_nodes[6][0]; reg46=reg38*pos_nodes[7][1]; reg41=reg23+reg41; reg23=pos_nodes[8][0]*reg27; reg26=reg11+reg26;
    reg11=pos_nodes[8][1]*reg50; reg30=reg51+reg30; reg49=pos_nodes[8][1]*reg27; reg24=reg48+reg24; reg48=pos_nodes[8][0]*reg50;
    reg33=reg25+reg33; reg42=reg22+reg42; reg22=reg38*pos_nodes[7][0]; reg2=reg2*var_inter[1]; reg48=reg24+reg48;
    reg49=reg26+reg49; reg24=reg2*pos_nodes[5][0]; reg11=reg30+reg11; reg10=var_inter[1]*reg10; reg25=reg2*pos_nodes[5][1];
    reg23=reg41+reg23; reg46=reg33+reg46; reg22=reg42+reg22; reg26=reg10*pos_nodes[8][1]; reg30=reg48*reg49;
    reg25=reg46+reg25; reg33=reg23*reg11; reg41=reg10*pos_nodes[8][0]; reg24=reg22+reg24; reg30=reg33-reg30;
    reg26=reg25+reg26; reg41=reg24+reg41; reg26=pos[1]-reg26; reg22=reg11/reg30; reg41=pos[0]-reg41;
    reg24=reg49/reg30; reg25=reg48/reg30; reg30=reg23/reg30; reg22=reg41*reg22; reg25=reg26*reg25;
    reg24=reg41*reg24; reg30=reg26*reg30; var_inter[0]+=reg22-reg25; var_inter[1]+=reg30-reg24;

}
template<> struct ElemVarInterFromPosNonLinear<Quad_9> { static const bool res = 2; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=4*reg0; T reg2=0.5-var_inter[0]; T reg3=4*var_inter[0]; T reg4=var_inter[0]-0.5;
    T reg5=8*reg0; reg3=reg3*reg4; reg1=reg2*reg1; T reg6=1-var_inter[1]; T reg7=var_inter[0]*reg5;
    T reg8=reg6*reg3; T reg9=reg1*reg6; T reg10=0.5-var_inter[1]; reg9=reg9*reg10; reg8=reg10*reg8;
    T reg11=reg6*reg7; reg8=val[1]*reg8; reg11=reg10*reg11; reg1=var_inter[1]*reg1; reg10=var_inter[1]-0.5;
    reg9=val[0]*reg9; reg8=reg9+reg8; reg11=val[4]*reg11; reg3=var_inter[1]*reg3; reg1=reg1*reg10;
    reg5=reg2*reg5; reg2=8*var_inter[0]; reg7=var_inter[1]*reg7; reg3=reg10*reg3; reg1=val[3]*reg1;
    reg11=reg8+reg11; reg1=reg11+reg1; reg3=val[2]*reg3; reg7=reg10*reg7; reg2=reg4*reg2;
    reg0=16*reg0; reg5=reg6*reg5; reg2=reg6*reg2; reg0=var_inter[0]*reg0; reg5=var_inter[1]*reg5;
    reg7=val[6]*reg7; reg3=reg1+reg3; reg5=val[7]*reg5; reg7=reg3+reg7; reg2=var_inter[1]*reg2;
    reg0=reg6*reg0; reg5=reg7+reg5; reg2=val[5]*reg2; reg0=var_inter[1]*reg0; reg2=reg5+reg2;
    reg0=val[8]*reg0; res=reg2+reg0;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Quad_9 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=8*var_inter[0]; T reg2=8*reg0; T reg3=var_inter[0]-0.5; T reg4=4*var_inter[0];
    T reg5=16*reg0; reg0=4*reg0; T reg6=0.5-var_inter[0]; reg5=var_inter[0]*reg5; reg4=reg4*reg3;
    T reg7=1-var_inter[1]; reg0=reg6*reg0; T reg8=var_inter[0]*reg2; reg1=reg3*reg1; reg2=reg6*reg2;
    reg5=reg7*reg5; reg1=reg7*reg1; reg2=reg7*reg2; reg3=var_inter[1]*reg8; reg6=var_inter[1]*reg4;
    T reg9=var_inter[1]-0.5; T reg10=var_inter[1]*reg0; reg8=reg7*reg8; reg4=reg7*reg4; T reg11=0.5-var_inter[1];
    reg7=reg0*reg7; reg6=reg9*reg6; res[2]=reg6; reg10=reg10*reg9; res[3]=reg10;
    reg3=reg9*reg3; res[6]=reg3; reg2=var_inter[1]*reg2; res[7]=reg2; reg8=reg11*reg8;
    res[4]=reg8; reg4=reg11*reg4; res[1]=reg4; reg1=var_inter[1]*reg1; res[5]=reg1;
    reg11=reg7*reg11; res[0]=reg11; reg5=var_inter[1]*reg5; res[8]=reg5;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Quad_9> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

}
#endif // LMT_QUAD_9
