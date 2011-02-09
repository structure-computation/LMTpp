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
    T reg0=1-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=0.5-var_inter[0]; T reg3=4*reg1; T reg4=4*reg2;
    T reg5=4*var_inter[0]; T reg6=4*reg0; reg3=reg5+reg3; T reg7=0.5-var_inter[1]; reg4=reg6+reg4;
    T reg8=8*var_inter[0]; T reg9=1-var_inter[1]; reg6=reg6*reg2; reg5=reg5*reg1; T reg10=8*reg0;
    T reg11=reg10-reg8; T reg12=reg5*reg7; T reg13=reg6*reg7; T reg14=reg9*reg4; T reg15=reg6*reg9;
    T reg16=reg5*reg9; T reg17=reg9*reg3; T reg18=reg10*var_inter[0]; reg17=reg7*reg17; T reg19=reg7*reg14;
    T reg20=reg9*reg11; T reg21=reg18*reg9; reg12=reg16+reg12; reg13=reg15+reg13; T reg22=var_inter[1]-0.5;
    T reg23=reg18*reg7; T reg24=pos_nodes[0][1]*reg19; T reg25=pos_nodes[0][1]*reg13; T reg26=pos_nodes[1][1]*reg17; T reg27=pos_nodes[0][0]*reg13;
    T reg28=pos_nodes[1][0]*reg12; T reg29=reg6*reg22; reg23=reg21+reg23; T reg30=pos_nodes[1][1]*reg12; T reg31=pos_nodes[0][0]*reg19;
    T reg32=pos_nodes[1][0]*reg17; reg20=reg7*reg20; T reg33=var_inter[1]*reg4; T reg34=var_inter[1]*reg6; T reg35=pos_nodes[4][0]*reg20;
    reg31=reg32-reg31; reg29=reg34+reg29; reg32=reg5*reg22; T reg36=pos_nodes[4][1]*reg23; reg25=reg30+reg25;
    reg16=reg16*reg7; reg30=8*reg2; reg3=var_inter[1]*reg3; T reg37=reg22*reg33; reg15=reg15*reg7;
    T reg38=pos_nodes[4][0]*reg23; T reg39=var_inter[1]*reg5; reg24=reg26-reg24; reg26=pos_nodes[4][1]*reg20; reg27=reg28+reg27;
    reg28=reg18*reg22; reg32=reg39+reg32; T reg40=pos_nodes[3][0]*reg29; T reg41=var_inter[1]*reg18; reg35=reg31+reg35;
    reg31=pos_nodes[3][0]*reg37; reg2=reg2*reg10; T reg42=pos_nodes[0][0]*reg15; T reg43=pos_nodes[1][0]*reg16; reg36=reg25+reg36;
    reg25=pos_nodes[0][1]*reg15; T reg44=reg16*pos_nodes[1][1]; reg38=reg27+reg38; reg27=pos_nodes[3][1]*reg29; reg7=reg21*reg7;
    reg3=reg22*reg3; reg11=var_inter[1]*reg11; reg30=reg10+reg30; reg26=reg24+reg26; reg10=8*reg1;
    reg21=pos_nodes[3][1]*reg37; reg34=reg34*reg22; reg24=pos_nodes[2][0]*reg32; T reg45=var_inter[1]*reg2; T reg46=reg9*reg2;
    reg1=reg1*reg8; reg38=reg40-reg38; reg28=reg41+reg28; reg40=pos_nodes[2][1]*reg32; T reg47=pos_nodes[2][1]*reg3;
    reg21=reg26-reg21; reg0=16*reg0; reg11=reg22*reg11; reg26=reg9*reg30; reg10=reg8+reg10;
    reg8=16*var_inter[0]; T reg48=reg7*pos_nodes[4][1]; T reg49=reg7*pos_nodes[4][0]; reg31=reg35-reg31; reg35=pos_nodes[2][0]*reg3;
    reg42=reg43+reg42; reg25=reg44+reg25; reg36=reg27-reg36; reg49=reg42+reg49; reg27=reg34*pos_nodes[3][0];
    reg42=pos_nodes[6][0]*reg28; reg43=pos_nodes[6][1]*reg28; reg24=reg38+reg24; reg38=pos_nodes[6][1]*reg11; reg40=reg36+reg40;
    reg47=reg21+reg47; reg21=var_inter[1]*reg1; reg45=reg46-reg45; reg39=reg22*reg39; reg10=reg9*reg10;
    reg36=var_inter[1]*reg26; reg8=reg0-reg8; reg44=reg34*pos_nodes[3][1]; reg48=reg25+reg48; reg25=reg9*reg1;
    reg35=reg31+reg35; reg0=reg0*var_inter[0]; reg31=pos_nodes[6][0]*reg11; reg10=var_inter[1]*reg10; T reg50=pos_nodes[7][1]*reg36;
    reg38=reg47+reg38; reg47=reg9*reg0; reg44=reg48+reg44; reg48=reg39*pos_nodes[2][1]; reg43=reg40+reg43;
    reg40=var_inter[1]*reg0; reg21=reg25-reg21; reg42=reg24+reg42; reg24=pos_nodes[7][0]*reg45; reg41=reg22*reg41;
    reg22=pos_nodes[7][1]*reg45; T reg51=pos_nodes[7][0]*reg36; reg31=reg35+reg31; reg27=reg49+reg27; reg35=reg39*pos_nodes[2][0];
    reg8=reg9*reg8; reg9=pos_nodes[5][1]*reg21; reg22=reg43+reg22; reg50=reg38-reg50; reg38=pos_nodes[5][1]*reg10;
    reg48=reg44+reg48; reg43=reg41*pos_nodes[6][1]; reg8=var_inter[1]*reg8; reg51=reg31-reg51; reg31=pos_nodes[5][0]*reg10;
    reg46=var_inter[1]*reg46; reg40=reg47-reg40; reg24=reg42+reg24; reg42=pos_nodes[5][0]*reg21; reg35=reg27+reg35;
    reg27=reg41*pos_nodes[6][0]; reg25=var_inter[1]*reg25; reg44=reg46*pos_nodes[7][1]; reg31=reg51+reg31; reg49=pos_nodes[8][1]*reg40;
    reg9=reg22+reg9; reg22=pos_nodes[8][0]*reg8; reg38=reg50+reg38; reg50=pos_nodes[8][1]*reg8; reg43=reg48+reg43;
    reg42=reg24+reg42; reg24=pos_nodes[8][0]*reg40; reg48=reg46*pos_nodes[7][0]; reg27=reg35+reg27; reg50=reg38+reg50;
    reg22=reg31+reg22; reg24=reg42+reg24; reg49=reg9+reg49; reg48=reg27+reg48; reg9=reg25*pos_nodes[5][0];
    reg44=reg43+reg44; reg47=var_inter[1]*reg47; reg27=reg25*pos_nodes[5][1]; reg27=reg44+reg27; reg31=reg47*pos_nodes[8][1];
    reg35=reg22*reg49; reg9=reg48+reg9; reg38=reg47*pos_nodes[8][0]; reg42=reg24*reg50; reg31=reg27+reg31;
    reg42=reg35-reg42; reg38=reg9+reg38; reg9=reg24/reg42; reg27=reg50/reg42; reg43=reg22/reg42;
    reg42=reg49/reg42; reg31=pos[1]-reg31; reg38=pos[0]-reg38; reg42=reg38*reg42; reg9=reg31*reg9;
    reg27=reg38*reg27; reg43=reg31*reg43; var_inter[0]=reg42-reg9; var_inter[1]=reg43-reg27;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_9 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=var_inter[0]-0.5; T reg3=4*reg1; T reg4=4*reg0;
    T reg5=4*var_inter[0]; T reg6=4*reg2; reg3=reg4+reg3; T reg7=8*reg0; T reg8=reg5*reg2;
    reg4=reg4*reg1; reg6=reg5+reg6; reg5=8*var_inter[0]; T reg9=1-var_inter[1]; T reg10=0.5-var_inter[1];
    T reg11=reg9*reg8; T reg12=reg7*var_inter[0]; T reg13=reg9*reg6; T reg14=reg7-reg5; T reg15=reg4*reg9;
    T reg16=reg4*reg10; T reg17=reg9*reg3; T reg18=reg10*reg8; reg16=reg15+reg16; T reg19=reg9*reg14;
    reg13=reg10*reg13; T reg20=var_inter[1]-0.5; reg18=reg11+reg18; T reg21=reg12*reg9; T reg22=reg12*reg10;
    T reg23=reg10*reg17; T reg24=pos_nodes[1][1]*reg18; T reg25=pos_nodes[0][1]*reg16; T reg26=pos_nodes[1][1]*reg13; T reg27=pos_nodes[0][1]*reg23;
    T reg28=pos_nodes[1][0]*reg18; T reg29=pos_nodes[0][0]*reg16; reg19=reg10*reg19; T reg30=var_inter[1]*reg3; T reg31=pos_nodes[1][0]*reg13;
    T reg32=pos_nodes[0][0]*reg23; T reg33=reg20*reg4; reg22=reg21+reg22; T reg34=reg4*var_inter[1]; T reg35=pos_nodes[4][0]*reg19;
    reg32=reg31-reg32; reg33=reg34+reg33; reg31=pos_nodes[4][1]*reg22; T reg36=reg20*reg8; reg24=reg25+reg24;
    reg25=8*reg1; reg6=var_inter[1]*reg6; T reg37=reg20*reg30; reg15=reg15*reg10; T reg38=pos_nodes[4][0]*reg22;
    reg11=reg10*reg11; reg27=reg26-reg27; reg26=pos_nodes[4][1]*reg19; reg28=reg29+reg28; reg29=reg8*var_inter[1];
    T reg39=pos_nodes[3][1]*reg37; reg38=reg28+reg38; reg28=pos_nodes[3][0]*reg33; T reg40=reg12*var_inter[1]; reg1=reg7*reg1;
    reg35=reg32+reg35; reg32=pos_nodes[3][0]*reg37; T reg41=reg11*pos_nodes[1][0]; T reg42=reg15*pos_nodes[0][0]; reg31=reg24+reg31;
    reg24=pos_nodes[1][1]*reg11; T reg43=reg15*pos_nodes[0][1]; T reg44=pos_nodes[3][1]*reg33; reg6=reg20*reg6; reg14=var_inter[1]*reg14;
    T reg45=reg12*reg20; reg25=reg7+reg25; reg10=reg21*reg10; reg7=8*reg2; reg36=reg29+reg36;
    reg26=reg27+reg26; reg45=reg40+reg45; reg21=reg1*var_inter[1]; reg27=reg9*reg1; reg2=reg5*reg2;
    T reg46=pos_nodes[2][1]*reg36; T reg47=pos_nodes[2][0]*reg36; reg38=reg28-reg38; reg31=reg44-reg31; reg28=pos_nodes[2][1]*reg6;
    reg39=reg26-reg39; reg34=reg34*reg20; reg0=16*reg0; reg14=reg20*reg14; reg26=reg9*reg25;
    reg7=reg5+reg7; reg5=16*var_inter[0]; reg44=reg10*pos_nodes[4][1]; T reg48=reg10*pos_nodes[4][0]; reg32=reg35-reg32;
    reg35=pos_nodes[2][0]*reg6; reg41=reg42+reg41; reg24=reg43+reg24; reg42=reg34*pos_nodes[3][0]; reg48=reg41+reg48;
    reg41=pos_nodes[6][1]*reg45; reg43=pos_nodes[6][0]*reg45; reg47=reg38+reg47; reg38=pos_nodes[6][1]*reg14; reg46=reg31+reg46;
    reg28=reg39+reg28; reg29=reg20*reg29; reg31=reg2*var_inter[1]; reg21=reg27-reg21; reg7=reg9*reg7;
    reg39=var_inter[1]*reg26; reg5=reg0-reg5; T reg49=reg34*pos_nodes[3][1]; reg44=reg24+reg44; reg24=reg9*reg2;
    reg35=reg32+reg35; reg0=reg0*var_inter[0]; reg32=pos_nodes[6][0]*reg14; reg7=var_inter[1]*reg7; T reg50=pos_nodes[7][1]*reg39;
    reg38=reg28+reg38; reg28=reg9*reg0; reg49=reg44+reg49; reg44=reg29*pos_nodes[2][1]; reg41=reg46+reg41;
    reg46=reg0*var_inter[1]; reg31=reg24-reg31; reg43=reg47+reg43; reg47=pos_nodes[7][0]*reg21; reg40=reg20*reg40;
    reg20=pos_nodes[7][1]*reg21; T reg51=pos_nodes[7][0]*reg39; reg32=reg35+reg32; reg42=reg48+reg42; reg35=reg29*pos_nodes[2][0];
    reg5=reg9*reg5; reg9=pos_nodes[5][1]*reg31; reg20=reg41+reg20; reg50=reg38-reg50; reg38=pos_nodes[5][1]*reg7;
    reg44=reg49+reg44; reg41=reg40*pos_nodes[6][1]; reg5=var_inter[1]*reg5; reg51=reg32-reg51; reg32=pos_nodes[5][0]*reg7;
    reg27=reg27*var_inter[1]; reg46=reg28-reg46; reg47=reg43+reg47; reg43=pos_nodes[5][0]*reg31; reg35=reg42+reg35;
    reg42=reg40*pos_nodes[6][0]; reg41=reg44+reg41; reg44=reg27*pos_nodes[7][1]; reg24=reg24*var_inter[1]; reg32=reg51+reg32;
    reg48=pos_nodes[8][1]*reg46; reg9=reg20+reg9; reg20=pos_nodes[8][0]*reg5; reg38=reg50+reg38; reg49=pos_nodes[8][1]*reg5;
    reg43=reg47+reg43; reg47=pos_nodes[8][0]*reg46; reg50=reg27*pos_nodes[7][0]; reg42=reg35+reg42; reg20=reg32+reg20;
    reg49=reg38+reg49; reg50=reg42+reg50; reg48=reg9+reg48; reg9=reg24*pos_nodes[5][0]; reg44=reg41+reg44;
    reg47=reg43+reg47; reg32=reg24*pos_nodes[5][1]; reg28=reg28*var_inter[1]; reg32=reg44+reg32; reg35=reg28*pos_nodes[8][1];
    reg38=reg20*reg48; reg9=reg50+reg9; reg41=reg28*pos_nodes[8][0]; reg42=reg47*reg49; reg35=reg32+reg35;
    reg42=reg38-reg42; reg41=reg9+reg41; reg9=reg47/reg42; reg32=reg49/reg42; reg43=reg20/reg42;
    reg42=reg48/reg42; reg35=pos[1]-reg35; reg41=pos[0]-reg41; reg42=reg41*reg42; reg9=reg35*reg9;
    reg32=reg41*reg32; reg43=reg35*reg43; var_inter[0]+=reg42-reg9; var_inter[1]+=reg43-reg32;

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
    reg9=val[0]*reg9; reg8=reg9+reg8; reg3=var_inter[1]*reg3; reg11=val[4]*reg11; reg1=reg1*reg10;
    reg1=val[3]*reg1; reg3=reg10*reg3; reg5=reg2*reg5; reg7=var_inter[1]*reg7; reg11=reg8+reg11;
    reg2=8*var_inter[0]; reg5=reg6*reg5; reg2=reg4*reg2; reg7=reg10*reg7; reg0=16*reg0;
    reg3=val[2]*reg3; reg1=reg11+reg1; reg0=var_inter[0]*reg0; reg2=reg6*reg2; reg5=var_inter[1]*reg5;
    reg7=val[6]*reg7; reg3=reg1+reg3; reg5=val[7]*reg5; reg2=var_inter[1]*reg2; reg7=reg3+reg7;
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
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Quad_9 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
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

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Quad_9,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=1-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=0.5-var_inter[0]; T reg3=4*reg1; T reg4=4*reg0;
    T reg5=4*var_inter[0]; T reg6=4*reg2; T reg7=1-var_inter[1]; reg3=reg5+reg3; T reg8=8*reg0;
    T reg9=8*var_inter[0]; reg6=reg4+reg6; T reg10=reg8-reg9; T reg11=reg7*reg3; T reg12=0.5-var_inter[1];
    T reg13=reg7*reg6; reg11=reg12*reg11; T reg14=reg12*reg13; T reg15=reg7*reg10; T reg16=elem.pos(0)[0]*reg14;
    T reg17=elem.pos(1)[0]*reg11; T reg18=elem.pos(0)[1]*reg14; T reg19=elem.pos(1)[1]*reg11; T reg20=var_inter[1]-0.5; reg15=reg12*reg15;
    T reg21=var_inter[1]*reg6; T reg22=elem.pos(4)[0]*reg15; T reg23=reg20*reg21; reg17=reg17-reg16; reg3=var_inter[1]*reg3;
    T reg24=8*reg2; reg11=elem.pos(1)[2]*reg11; reg19=reg19-reg18; T reg25=elem.pos(0)[2]*reg14; T reg26=elem.pos(4)[1]*reg15;
    reg17=reg22+reg17; reg19=reg26+reg19; reg22=elem.pos(3)[1]*reg23; reg3=reg20*reg3; reg24=reg8+reg24;
    reg26=elem.pos(3)[0]*reg23; T reg27=8*reg1; reg15=elem.pos(4)[2]*reg15; reg11=reg11-reg25; reg4=reg2*reg4;
    reg5=reg5*reg1; reg10=var_inter[1]*reg10; reg27=reg9+reg27; reg10=reg20*reg10; T reg28=16*var_inter[0];
    T reg29=reg12*reg5; T reg30=reg4*reg12; reg19=reg19-reg22; T reg31=reg7*reg24; T reg32=var_inter[0]*reg8;
    T reg33=reg7*reg5; T reg34=reg4*reg7; reg15=reg11+reg15; reg11=elem.pos(2)[1]*reg3; reg0=16*reg0;
    T reg35=elem.pos(3)[2]*reg23; T reg36=elem.pos(2)[0]*reg3; reg17=reg17-reg26; T reg37=reg12*reg32; reg29=reg33+reg29;
    T reg38=var_inter[1]*reg31; reg11=reg19+reg11; reg3=elem.pos(2)[2]*reg3; reg19=elem.pos(6)[0]*reg10; reg27=reg7*reg27;
    T reg39=reg7*reg32; reg36=reg17+reg36; reg17=elem.pos(6)[1]*reg10; reg15=reg15-reg35; reg30=reg34+reg30;
    reg28=reg0-reg28; reg27=var_inter[1]*reg27; T reg40=elem.pos(0)[0]*reg30; T reg41=elem.pos(1)[0]*reg29; reg3=reg15+reg3;
    reg17=reg11+reg17; reg11=var_inter[1]*reg4; reg10=elem.pos(6)[2]*reg10; reg19=reg36+reg19; reg15=elem.pos(0)[1]*reg30;
    reg36=elem.pos(7)[1]*reg38; reg28=reg7*reg28; T reg42=elem.pos(1)[1]*reg29; reg37=reg39+reg37; T reg43=elem.pos(7)[0]*reg38;
    T reg44=reg4*reg20; T reg45=reg5*reg20; T reg46=elem.pos(7)[2]*reg38; reg44=reg11+reg44; T reg47=var_inter[1]*reg5;
    reg28=var_inter[1]*reg28; T reg48=elem.pos(0)[2]*reg30; T reg49=reg41+reg40; T reg50=elem.pos(1)[2]*reg29; T reg51=elem.pos(5)[0]*reg27;
    T reg52=elem.pos(5)[1]*reg27; reg19=reg19-reg43; T reg53=elem.pos(4)[0]*reg37; reg10=reg3+reg10; reg3=elem.pos(4)[1]*reg37;
    T reg54=reg42+reg15; reg17=reg17-reg36; T reg55=reg54+reg3; T reg56=elem.pos(8)[1]*reg28; T reg57=elem.pos(3)[1]*reg44;
    T reg58=elem.pos(4)[2]*reg37; reg19=reg51+reg19; reg51=reg48+reg50; T reg59=elem.pos(8)[0]*reg28; T reg60=reg53+reg49;
    T reg61=reg32*reg20; reg10=reg10-reg46; reg45=reg47+reg45; T reg62=var_inter[1]*reg32; reg8=reg2*reg8;
    reg52=reg17+reg52; reg27=elem.pos(5)[2]*reg27; reg2=elem.pos(3)[0]*reg44; reg17=elem.pos(2)[1]*reg45; reg44=elem.pos(3)[2]*reg44;
    T reg63=reg58+reg51; T reg64=var_inter[1]*reg8; reg56=reg52+reg56; reg28=elem.pos(8)[2]*reg28; reg52=reg7*reg8;
    reg9=reg1*reg9; reg1=elem.pos(2)[0]*reg45; reg59=reg19+reg59; reg27=reg10+reg27; reg61=reg62+reg61;
    reg57=reg57-reg55; reg2=reg2-reg60; reg44=reg44-reg63; reg45=elem.pos(2)[2]*reg45; reg10=var_inter[1]*reg9;
    reg19=elem.pos(6)[1]*reg61; reg17=reg57+reg17; reg57=pow(reg56,2); T reg65=pow(reg59,2); reg28=reg27+reg28;
    reg27=elem.pos(6)[0]*reg61; T reg66=reg7*reg9; reg2=reg1+reg2; reg0=var_inter[0]*reg0; reg64=reg52-reg64;
    reg45=reg44+reg45; reg61=elem.pos(6)[2]*reg61; reg1=pow(reg28,2); reg10=reg66-reg10; reg44=elem.pos(7)[1]*reg64;
    reg27=reg2+reg27; reg19=reg17+reg19; reg2=var_inter[1]*reg0; reg7=reg7*reg0; reg17=elem.pos(7)[0]*reg64;
    reg57=reg65+reg57; reg2=reg7-reg2; reg64=elem.pos(7)[2]*reg64; reg45=reg61+reg45; reg27=reg17+reg27;
    reg1=reg57+reg1; reg17=elem.pos(5)[1]*reg10; reg57=elem.pos(5)[0]*reg10; reg44=reg19+reg44; reg64=reg45+reg64;
    reg10=elem.pos(5)[2]*reg10; reg19=elem.pos(8)[0]*reg2; reg27=reg57+reg27; reg1=pow(reg1,0.5); reg17=reg44+reg17;
    reg44=elem.pos(8)[1]*reg2; reg27=reg19+reg27; reg10=reg64+reg10; reg19=reg56/reg1; reg2=elem.pos(8)[2]*reg2;
    reg44=reg17+reg44; reg17=reg59/reg1; reg1=reg28/reg1; reg45=reg17*reg27; reg2=reg10+reg2;
    reg10=reg19*reg44; reg10=reg45+reg10; reg45=reg2*reg1; reg45=reg10+reg45; reg10=reg17*reg45;
    reg57=reg19*reg45; reg61=reg1*reg45; reg10=reg27-reg10; reg57=reg44-reg57; reg61=reg2-reg61;
    reg64=pow(reg10,2); reg65=pow(reg57,2); T reg67=pow(reg61,2); reg65=reg64+reg65; reg67=reg65+reg67;
    reg67=pow(reg67,0.5); reg10=reg10/reg67; reg57=reg57/reg67; reg27=reg27*reg10; reg10=reg59*reg10;
    reg64=reg57*reg56; reg57=reg44*reg57; reg56=reg19*reg56; reg59=reg17*reg59; reg67=reg61/reg67;
    reg2=reg2*reg67; reg57=reg27+reg57; reg64=reg10+reg64; reg1=reg1*reg28; reg56=reg59+reg56;
    reg67=reg28*reg67; reg1=reg56+reg1; reg64=reg67+reg64; reg2=reg57+reg2; reg10=reg64*reg45;
    reg17=reg1*reg2; reg10=reg17-reg10; return reg10;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Quad_9,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.070441621801729003199*elem.pos(0)[1]; T reg1=0.018874775675311855147*elem.pos(1)[1]; T reg2=0.018874775675311855147*elem.pos(0)[0]; T reg3=0.26289171153160429149*elem.pos(1)[0]; T reg4=0.26289171153160429149*elem.pos(1)[1];
    T reg5=0.26289171153160429149*elem.pos(0)[1]; T reg6=0.070441621801729003199*elem.pos(0)[0]; T reg7=0.018874775675311855147*elem.pos(1)[0]; T reg8=0.26289171153160429149*elem.pos(0)[0]; T reg9=0.018874775675311855147*elem.pos(0)[1];
    T reg10=0.070441621801729003199*elem.pos(1)[0]; T reg11=0.070441621801729003199*elem.pos(1)[1]; T reg12=reg3+reg2; T reg13=0.981125224324688029*elem.pos(1)[1]; T reg14=0.10313369225283431404*elem.pos(4)[1];
    T reg15=0.28176648720691614664*elem.pos(4)[0]; T reg16=reg9-reg11; T reg17=0.070441621801729003213*elem.pos(0)[0]; T reg18=0.98112522432468802895*elem.pos(1)[1]; T reg19=0.070441621801729003213*elem.pos(0)[1];
    T reg20=reg7-reg6; T reg21=0.98112522432468802895*elem.pos(1)[0]; reg7=reg7+reg8; T reg22=0.10313369225283431404*elem.pos(4)[0]; T reg23=reg1-reg0;
    reg2=reg2-reg10; T reg24=0.28176648720691614664*elem.pos(4)[1]; reg9=reg9+reg4; reg1=reg1+reg5; T reg25=0.981125224324688029*elem.pos(1)[0];
    T reg26=0.26289171153160429149*elem.pos(3)[1]; reg2=reg2-reg22; T reg27=0.014886066246173484324*elem.pos(1)[0]; T reg28=0.26289171153160429149*elem.pos(3)[0]; T reg29=0.055555555555555552339*elem.pos(0)[0];
    reg7=reg7-reg15; T reg30=0.98112522432468802895*elem.pos(3)[0]; T reg31=0.981125224324688029*elem.pos(3)[1]; reg16=reg16-reg14; reg23=reg23-reg14;
    T reg32=0.070441621801729003213*elem.pos(3)[1]; T reg33=reg24-reg9; reg1=reg1-reg24; T reg34=0.98112522432468802895*elem.pos(3)[1]; reg20=reg20-reg22;
    T reg35=0.981125224324688029*elem.pos(3)[0]; T reg36=0.014886066246173484324*elem.pos(0)[0]; T reg37=0.055555555555555552339*elem.pos(1)[0]; T reg38=0.981125224324688029*elem.pos(0)[0]; T reg39=0.98112522432468802895*elem.pos(0)[1];
    T reg40=0.070441621801729003213*elem.pos(1)[1]; T reg41=0.981125224324688029*elem.pos(0)[1]; T reg42=0.98112522432468802895*elem.pos(0)[0]; T reg43=0.070441621801729003213*elem.pos(1)[0]; T reg44=0.014886066246173484324*elem.pos(0)[1];
    reg25=reg25-reg8; T reg45=0.055555555555555552339*elem.pos(1)[1]; T reg46=1.4364670255861677246*elem.pos(4)[0]; T reg47=1.0515668461264170322*elem.pos(4)[0]; reg21=reg21+reg17;
    T reg48=0.014886066246173484324*elem.pos(1)[1]; T reg49=0.055555555555555552339*elem.pos(0)[1]; reg13=reg13-reg5; T reg50=1.4364670255861677246*elem.pos(4)[1]; T reg51=0.070441621801729003213*elem.pos(3)[0];
    T reg52=reg15-reg12; reg18=reg18+reg19; T reg53=1.0515668461264170322*elem.pos(4)[1]; T reg54=0.081338978618764150166*elem.pos(4)[1]; reg38=reg38-reg3;
    reg30=reg7-reg30; reg44=reg44-reg45; reg7=0.070441621801729003213*elem.pos(2)[0]; reg27=reg27-reg29; reg48=reg48-reg49;
    T reg55=0.20733615597604870572*elem.pos(1)[1]; reg39=reg40+reg39; reg41=reg41-reg4; reg42=reg43+reg42; reg23=reg31-reg23;
    reg31=0.26289171153160429149*elem.pos(2)[1]; reg25=reg46+reg25; reg34=reg1-reg34; reg1=0.070441621801729003213*elem.pos(2)[1]; reg18=reg18-reg53;
    reg20=reg35-reg20; reg13=reg13+reg50; reg35=0.018874775675311855147*elem.pos(3)[1]; T reg56=0.018874775675311855147*elem.pos(3)[0]; reg21=reg21-reg47;
    T reg57=0.26289171153160429149*elem.pos(2)[0]; T reg58=0.20733615597604870572*elem.pos(1)[0]; reg36=reg36-reg37; T reg59=0.98112522432468802895*elem.pos(2)[1]; reg33=reg33+reg32;
    T reg60=0.981125224324688029*elem.pos(2)[0]; T reg61=0.98112522432468802895*elem.pos(2)[0]; reg16=reg26+reg16; T reg62=0.981125224324688029*elem.pos(2)[1]; T reg63=0.081338978618764150166*elem.pos(4)[0];
    reg2=reg28+reg2; reg52=reg52+reg51; T reg64=0.20733615597604870572*elem.pos(0)[0]; T reg65=reg47-reg42; T reg66=0.070441621801729003199*elem.pos(3)[1];
    reg23=reg23-reg31; reg59=reg33+reg59; reg33=1.0515668461264170322*elem.pos(6)[1]; reg41=reg50+reg41; reg50=0.070441621801729003199*elem.pos(2)[0];
    reg25=reg56-reg25; reg34=reg34-reg1; reg18=reg18-reg35; T reg67=0.070441621801729003199*elem.pos(2)[1]; reg13=reg35-reg13;
    reg35=1.4364670255861677246*elem.pos(6)[1]; reg62=reg62-reg16; reg20=reg20-reg57; reg61=reg52+reg61; reg52=1.0515668461264170322*elem.pos(6)[0];
    reg56=reg21-reg56; reg58=reg58-reg29; reg21=0.30356120084098635952*elem.pos(4)[0]; reg44=reg44-reg54; T reg68=0.055555555555555552339*elem.pos(3)[1];
    reg55=reg55-reg49; T reg69=0.30356120084098635952*elem.pos(4)[1]; T reg70=0.20733615597604870572*elem.pos(3)[1]; reg48=reg48-reg54; T reg71=1.4364670255861677246*elem.pos(6)[0];
    reg38=reg46+reg38; reg46=0.070441621801729003199*elem.pos(3)[0]; reg60=reg60-reg2; reg27=reg27-reg63; reg30=reg30-reg7;
    T reg72=reg53-reg39; reg36=reg36-reg63; T reg73=0.055555555555555552339*elem.pos(3)[0]; T reg74=0.20733615597604870572*elem.pos(0)[1]; T reg75=0.20733615597604870572*elem.pos(3)[0];
    reg70=reg48+reg70; reg48=0.055555555555555552339*elem.pos(2)[1]; reg61=reg61-reg52; T reg76=0.28176648720691614664*elem.pos(6)[0]; reg56=reg56-reg57;
    reg55=reg55+reg69; T reg77=0.014886066246173484324*elem.pos(3)[1]; T reg78=0.10313369225283431406*elem.pos(7)[0]; T reg79=0.014886066246173484324*elem.pos(3)[0]; reg58=reg21+reg58;
    reg74=reg74-reg45; T reg80=0.018874775675311855147*elem.pos(2)[1]; reg41=reg66+reg41; reg72=reg26+reg72; reg36=reg36-reg73;
    T reg81=0.20733615597604870572*elem.pos(2)[0]; T reg82=0.018874775675311855147*elem.pos(2)[0]; reg65=reg28+reg65; reg38=reg46+reg38; reg64=reg64-reg37;
    T reg83=0.10313369225283431404*elem.pos(6)[0]; reg25=reg25-reg50; T reg84=0.28176648720691614664*elem.pos(6)[1]; reg44=reg44-reg68; T reg85=0.20733615597604870572*elem.pos(2)[1];
    reg18=reg18-reg31; T reg86=0.10313369225283431404*elem.pos(6)[1]; reg13=reg13-reg67; T reg87=0.10313369225283431406*elem.pos(7)[1]; reg30=reg52+reg30;
    T reg88=1.4364670255861677246*elem.pos(7)[0]; reg62=reg62+reg35; T reg89=0.28176648720691614667*elem.pos(7)[0]; reg20=reg71+reg20; T reg90=1.0515668461264170322*elem.pos(7)[0];
    T reg91=1.4364670255861677246*elem.pos(7)[1]; reg34=reg33+reg34; T reg92=0.28176648720691614667*elem.pos(7)[1]; reg59=reg59-reg33; reg23=reg35+reg23;
    reg71=reg60+reg71; reg75=reg27+reg75; reg27=0.055555555555555552339*elem.pos(2)[0]; reg35=1.0515668461264170322*elem.pos(7)[1]; reg64=reg21+reg64;
    reg77=reg55+reg77; reg21=1.0515668461264170322*elem.pos(5)[0]; reg74=reg69+reg74; reg55=0.30356120084098635952*elem.pos(6)[0]; reg71=reg71+reg89;
    reg81=reg36+reg81; reg36=0.28176648720691614667*elem.pos(5)[1]; reg30=reg30-reg88; reg60=0.10313369225283431406*elem.pos(5)[0]; reg69=reg80-reg41;
    reg25=reg25-reg83; reg23=reg23-reg35; reg18=reg18+reg84; reg65=reg65+reg82; reg62=reg62+reg92;
    T reg93=1.0515668461264170322*elem.pos(5)[1]; reg75=reg75-reg27; T reg94=1.4364670255861677246*elem.pos(5)[0]; reg61=reg61+reg78; reg70=reg70-reg48;
    reg79=reg58+reg79; reg85=reg44+reg85; reg44=0.30356120084098635952*elem.pos(6)[1]; reg58=0.28176648720691614667*elem.pos(5)[0]; reg56=reg56+reg76;
    reg82=reg82-reg38; T reg95=1.4364670255861677246*elem.pos(5)[1]; reg20=reg20-reg90; reg59=reg59+reg87; reg72=reg80+reg72;
    reg80=0.10313369225283431406*elem.pos(5)[1]; reg34=reg34-reg91; reg13=reg13-reg86; reg77=reg77-reg48; reg85=reg85+reg44;
    T reg96=0.081338978618764150166*elem.pos(6)[1]; T reg97=0.014886066246173484324*elem.pos(2)[0]; reg23=reg23+reg36; T reg98=0.081338978618764150159*elem.pos(7)[1]; reg75=reg55+reg75;
    T reg99=0.30356120084098635952*elem.pos(7)[0]; reg65=reg65-reg76; reg71=reg71-reg21; reg70=reg44+reg70; reg44=0.30356120084098635952*elem.pos(7)[1];
    reg30=reg30-reg60; reg82=reg82-reg83; reg59=reg59+reg95; reg69=reg69-reg86; reg72=reg72-reg84;
    T reg100=1.5396007178390020388*elem.pos(8)[0]; reg79=reg79-reg27; T reg101=0.081338978618764150166*elem.pos(6)[0]; T reg102=0.014886066246173484324*elem.pos(2)[1]; reg61=reg61+reg94;
    reg74=reg74-reg68; reg20=reg20+reg58; reg56=reg78+reg56; reg34=reg34-reg80; reg13=reg13-reg92;
    reg18=reg87+reg18; T reg103=0.081338978618764150159*elem.pos(7)[0]; reg55=reg81+reg55; reg64=reg64-reg73; reg25=reg25-reg89;
    reg62=reg62-reg93; reg81=1.5396007178390020388*elem.pos(8)[1]; reg34=reg81+reg34; reg91=reg72-reg91; reg61=reg61-reg100;
    reg56=reg94+reg56; reg59=reg59-reg81; reg72=0.081338978618764150166*elem.pos(7)[1]; reg82=reg90+reg82; reg94=0.081338978618764150159*elem.pos(5)[1];
    reg70=reg70+reg44; reg20=reg20-reg100; reg77=reg77-reg96; reg102=reg74+reg102; reg74=0.30356120084098635952*elem.pos(5)[1];
    reg85=reg85-reg98; T reg104=0.081338978618764150159*elem.pos(5)[0]; T reg105=0.081338978618764150166*elem.pos(7)[0]; reg75=reg75+reg99; reg79=reg79-reg101;
    reg97=reg64+reg97; reg23=reg23-reg81; reg64=0.30356120084098635952*elem.pos(5)[0]; reg69=reg35+reg69; reg71=reg71-reg100;
    reg25=reg21+reg25; reg30=reg100+reg30; reg18=reg95+reg18; reg62=reg62-reg81; reg13=reg93+reg13;
    reg55=reg55-reg103; reg88=reg65-reg88; reg62=reg61*reg62; reg75=reg75-reg104; reg18=reg18-reg81;
    reg85=reg85+reg74; reg88=reg88-reg60; reg61=0.44444444444444449594*elem.pos(8)[1]; reg102=reg102-reg96; reg79=reg79-reg105;
    reg97=reg97-reg101; reg25=reg100+reg25; reg91=reg91-reg80; reg56=reg56-reg100; reg13=reg81+reg13;
    reg65=0.44444444444444449594*elem.pos(8)[0]; reg77=reg77-reg72; reg71=reg59*reg71; reg82=reg82-reg58; reg70=reg70-reg94;
    reg69=reg69-reg36; reg20=reg34*reg20; reg55=reg55+reg64; reg23=reg30*reg23; reg85=reg85+reg61;
    reg70=reg61+reg70; reg71=reg62-reg71; reg102=reg44+reg102; reg30=0.081338978618764150166*elem.pos(5)[1]; reg77=reg74+reg77;
    reg79=reg64+reg79; reg20=reg23-reg20; reg13=reg56*reg13; reg55=reg55+reg65; reg25=reg18*reg25;
    reg97=reg99+reg97; reg18=0.081338978618764150166*elem.pos(5)[0]; reg88=reg100+reg88; reg69=reg81+reg69; reg91=reg81+reg91;
    reg82=reg100+reg82; reg75=reg65+reg75; reg97=reg97-reg18; reg69=reg88*reg69; reg85=reg71*reg85;
    reg102=reg102-reg30; reg70=reg20*reg70; reg25=reg13-reg25; reg77=reg61+reg77; reg82=reg91*reg82;
    reg75=reg75*reg20; reg55=reg55*reg71; reg79=reg65+reg79; reg77=reg25*reg77; reg75=0.25*reg75;
    reg79=reg79*reg25; reg85=0.25*reg85; reg97=reg65+reg97; reg102=reg61+reg102; reg70=0.25*reg70;
    reg71=0.25*reg71; reg20=0.25*reg20; reg82=reg69-reg82; reg55=0.25*reg55; reg25=0.25*reg25;
    reg20=reg71+reg20; reg70=reg85+reg70; reg79=0.25*reg79; reg77=0.25*reg77; reg75=reg55+reg75;
    reg97=reg97*reg82; reg102=reg82*reg102; reg102=0.25*reg102; reg82=0.25*reg82; reg77=reg70+reg77;
    reg79=reg75+reg79; reg25=reg20+reg25; reg97=0.25*reg97; reg82=reg25+reg82; reg97=reg79+reg97;
    reg102=reg77+reg102; res[1]=reg102/reg82; res[0]=reg97/reg82;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Quad_9,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.018874775675311855147*elem.pos(1)[1]; T reg1=0.26289171153160429149*elem.pos(0)[1]; T reg2=0.018874775675311855147*elem.pos(0)[1]; T reg3=0.26289171153160429149*elem.pos(1)[1]; T reg4=0.018874775675311855147*elem.pos(1)[0];
    T reg5=0.26289171153160429149*elem.pos(0)[0]; T reg6=0.26289171153160429149*elem.pos(1)[0]; T reg7=0.018874775675311855147*elem.pos(0)[0]; T reg8=0.070441621801729003213*elem.pos(0)[0]; T reg9=reg0+reg1;
    T reg10=0.018874775675311855147*elem.pos(0)[2]; T reg11=0.26289171153160429149*elem.pos(1)[2]; T reg12=0.98112522432468802895*elem.pos(1)[0]; T reg13=0.28176648720691614664*elem.pos(4)[1]; T reg14=reg3+reg2;
    T reg15=0.28176648720691614664*elem.pos(4)[0]; T reg16=reg6+reg7; T reg17=0.018874775675311855147*elem.pos(1)[2]; T reg18=0.98112522432468802895*elem.pos(1)[1]; T reg19=0.070441621801729003213*elem.pos(0)[1];
    T reg20=0.26289171153160429149*elem.pos(0)[2]; T reg21=reg4+reg5; reg9=reg9-reg13; T reg22=reg17+reg20; T reg23=reg15-reg16;
    T reg24=0.070441621801729003213*elem.pos(3)[0]; T reg25=0.98112522432468802895*elem.pos(3)[1]; T reg26=0.070441621801729003213*elem.pos(3)[1]; T reg27=0.98112522432468802895*elem.pos(0)[1]; T reg28=0.070441621801729003213*elem.pos(1)[1];
    T reg29=reg13-reg14; T reg30=0.98112522432468802895*elem.pos(0)[0]; T reg31=0.070441621801729003213*elem.pos(1)[0]; reg18=reg18+reg19; T reg32=reg11+reg10;
    T reg33=0.28176648720691614664*elem.pos(4)[2]; T reg34=0.98112522432468802895*elem.pos(3)[0]; reg21=reg21-reg15; T reg35=1.0515668461264170322*elem.pos(4)[1]; reg12=reg12+reg8;
    T reg36=1.0515668461264170322*elem.pos(4)[0]; T reg37=0.070441621801729003213*elem.pos(0)[2]; T reg38=0.98112522432468802895*elem.pos(1)[2]; T reg39=0.98112522432468802895*elem.pos(2)[0]; reg18=reg18-reg35;
    T reg40=0.018874775675311855147*elem.pos(3)[1]; reg38=reg38+reg37; T reg41=1.0515668461264170322*elem.pos(4)[2]; T reg42=0.018874775675311855147*elem.pos(3)[0]; reg12=reg12-reg36;
    reg29=reg29+reg26; T reg43=0.98112522432468802895*elem.pos(2)[1]; T reg44=0.070441621801729003213*elem.pos(3)[2]; T reg45=reg33-reg32; T reg46=0.98112522432468802895*elem.pos(3)[2];
    reg22=reg22-reg33; reg34=reg21-reg34; reg21=0.070441621801729003213*elem.pos(2)[0]; T reg47=0.98112522432468802895*elem.pos(0)[2]; T reg48=0.070441621801729003213*elem.pos(1)[2];
    reg27=reg28+reg27; reg25=reg9-reg25; reg9=0.070441621801729003213*elem.pos(2)[1]; reg23=reg23+reg24; reg30=reg31+reg30;
    reg45=reg45+reg44; T reg49=0.98112522432468802895*elem.pos(2)[2]; T reg50=0.26289171153160429149*elem.pos(2)[0]; T reg51=0.26289171153160429149*elem.pos(2)[1]; reg47=reg48+reg47;
    T reg52=0.018874775675311855147*elem.pos(3)[2]; reg38=reg38-reg41; T reg53=0.26289171153160429149*elem.pos(3)[0]; reg12=reg12-reg42; reg18=reg18-reg40;
    T reg54=0.26289171153160429149*elem.pos(3)[1]; reg34=reg34-reg21; T reg55=1.0515668461264170322*elem.pos(6)[0]; reg39=reg23+reg39; reg23=reg36-reg30;
    reg25=reg25-reg9; T reg56=reg35-reg27; reg43=reg29+reg43; reg29=1.0515668461264170322*elem.pos(6)[1]; reg46=reg22-reg46;
    reg22=0.070441621801729003213*elem.pos(2)[2]; T reg57=0.10313369225283431406*elem.pos(7)[1]; T reg58=0.070441621801729003199*elem.pos(1)[0]; T reg59=0.26289171153160429149*elem.pos(3)[2]; reg43=reg43-reg29;
    T reg60=1.4364670255861677246*elem.pos(7)[0]; T reg61=reg41-reg47; reg56=reg54+reg56; reg12=reg12-reg50; T reg62=0.28176648720691614664*elem.pos(6)[0];
    T reg63=0.28176648720691614664*elem.pos(6)[1]; reg18=reg18-reg51; T reg64=0.10313369225283431406*elem.pos(7)[0]; reg34=reg55+reg34; T reg65=0.070441621801729003199*elem.pos(1)[1];
    reg25=reg29+reg25; T reg66=0.018874775675311855147*elem.pos(2)[0]; reg23=reg53+reg23; reg49=reg45+reg49; reg45=1.0515668461264170322*elem.pos(6)[2];
    T reg67=0.070441621801729003199*elem.pos(0)[0]; reg46=reg46-reg22; T reg68=0.070441621801729003199*elem.pos(0)[1]; T reg69=0.26289171153160429149*elem.pos(2)[2]; T reg70=0.018874775675311855147*elem.pos(2)[1];
    reg39=reg39-reg55; T reg71=1.4364670255861677246*elem.pos(7)[1]; reg38=reg38-reg52; reg46=reg45+reg46; T reg72=1.4364670255861677246*elem.pos(7)[2];
    T reg73=0.10313369225283431406*elem.pos(5)[1]; reg12=reg12+reg62; reg25=reg25-reg71; reg4=reg4-reg67; T reg74=0.070441621801729003199*elem.pos(1)[2];
    reg0=reg0-reg68; T reg75=0.070441621801729003199*elem.pos(0)[2]; T reg76=0.10313369225283431406*elem.pos(5)[0]; reg34=reg34-reg60; reg39=reg39+reg64;
    reg23=reg23+reg66; T reg77=1.4364670255861677246*elem.pos(5)[1]; reg56=reg56+reg70; T reg78=1.4364670255861677246*elem.pos(5)[0]; reg43=reg43+reg57;
    T reg79=0.981125224324688029*elem.pos(1)[0]; T reg80=0.981125224324688029*elem.pos(1)[1]; T reg81=0.28176648720691614664*elem.pos(6)[2]; reg38=reg38-reg69; reg7=reg7-reg58;
    T reg82=0.10313369225283431404*elem.pos(4)[0]; reg61=reg59+reg61; T reg83=0.018874775675311855147*elem.pos(2)[2]; reg18=reg18+reg63; reg2=reg2-reg65;
    reg49=reg49-reg45; T reg84=0.10313369225283431406*elem.pos(7)[2]; T reg85=0.10313369225283431404*elem.pos(4)[1]; reg25=reg25-reg73; reg43=reg43+reg77;
    T reg86=1.5396007178390020388*elem.pos(8)[1]; T reg87=0.981125224324688029*elem.pos(1)[2]; reg46=reg46-reg72; T reg88=1.5396007178390020388*elem.pos(8)[0]; reg39=reg39+reg78;
    reg23=reg23-reg62; reg56=reg56-reg63; reg34=reg34-reg76; reg61=reg61+reg83; T reg89=0.981125224324688029*elem.pos(0)[0];
    T reg90=0.981125224324688029*elem.pos(0)[1]; reg38=reg38+reg81; reg79=reg79-reg5; T reg91=0.10313369225283431404*elem.pos(4)[2]; reg10=reg10-reg74;
    reg17=reg17-reg75; reg7=reg7-reg82; T reg92=1.4364670255861677246*elem.pos(4)[0]; reg18=reg57+reg18; reg12=reg64+reg12;
    reg0=reg0-reg85; reg80=reg80-reg1; T reg93=0.981125224324688029*elem.pos(3)[1]; T reg94=1.4364670255861677246*elem.pos(4)[1]; reg4=reg4-reg82;
    T reg95=1.4364670255861677246*elem.pos(5)[2]; reg2=reg2-reg85; reg49=reg49+reg84; T reg96=0.981125224324688029*elem.pos(3)[0]; T reg97=0.10313369225283431406*elem.pos(5)[2];
    reg61=reg61-reg81; reg12=reg78+reg12; reg89=reg89-reg6; reg18=reg77+reg18; reg90=reg90-reg3;
    reg77=0.981125224324688029*elem.pos(0)[2]; reg34=reg88+reg34; reg38=reg84+reg38; reg71=reg56-reg71; reg17=reg17-reg91;
    reg60=reg23-reg60; reg23=0.981125224324688029*elem.pos(3)[2]; reg79=reg79+reg92; reg0=reg93-reg0; reg25=reg86+reg25;
    reg56=1.4364670255861677246*elem.pos(4)[2]; reg4=reg96-reg4; reg87=reg87-reg20; reg80=reg80+reg94; reg46=reg46-reg97;
    reg10=reg10-reg91; reg39=reg39-reg88; reg49=reg49+reg95; reg78=1.5396007178390020388*elem.pos(8)[2]; reg93=0.981125224324688029*elem.pos(2)[1];
    reg2=reg54+reg2; reg43=reg43-reg86; reg7=reg53+reg7; reg96=0.981125224324688029*elem.pos(2)[0]; reg10=reg59+reg10;
    T reg98=0.981125224324688029*elem.pos(2)[2]; T reg99=pow(reg43,2); T reg100=0.070441621801729003199*elem.pos(3)[0]; reg89=reg92+reg89; reg92=0.070441621801729003199*elem.pos(3)[1];
    reg90=reg94+reg90; reg94=pow(reg39,2); reg87=reg87+reg56; reg17=reg23-reg17; reg0=reg0-reg51;
    reg4=reg4-reg50; reg46=reg78+reg46; reg12=reg12-reg88; reg23=1.4364670255861677246*elem.pos(6)[1]; reg93=reg93-reg2;
    reg18=reg18-reg86; T reg101=1.4364670255861677246*elem.pos(6)[0]; reg96=reg96-reg7; reg72=reg61-reg72; reg38=reg95+reg38;
    reg71=reg71-reg73; reg79=reg42-reg79; reg42=0.070441621801729003199*elem.pos(2)[0]; reg49=reg49-reg78; reg80=reg40-reg80;
    reg40=0.070441621801729003199*elem.pos(2)[1]; reg61=pow(reg34,2); reg95=pow(reg25,2); reg60=reg60-reg76; reg77=reg77-reg11;
    reg4=reg101+reg4; T reg102=1.0515668461264170322*elem.pos(7)[0]; T reg103=pow(reg18,2); reg101=reg96+reg101; reg96=0.28176648720691614667*elem.pos(7)[0];
    reg60=reg88+reg60; reg89=reg100+reg89; reg93=reg93+reg23; T reg104=pow(reg12,2); T reg105=0.28176648720691614667*elem.pos(7)[1];
    reg95=reg61+reg95; reg0=reg23+reg0; reg23=1.0515668461264170322*elem.pos(7)[1]; reg98=reg98-reg10; reg61=1.4364670255861677246*elem.pos(6)[2];
    reg72=reg72-reg97; reg71=reg86+reg71; T reg106=pow(reg46,2); reg17=reg17-reg69; reg38=reg38-reg78;
    reg80=reg80-reg40; T reg107=0.070441621801729003199*elem.pos(3)[2]; T reg108=0.10313369225283431404*elem.pos(6)[1]; reg87=reg52-reg87; reg52=pow(reg49,2);
    reg99=reg94+reg99; reg79=reg79-reg42; reg94=0.070441621801729003199*elem.pos(2)[2]; T reg109=0.10313369225283431404*elem.pos(6)[0]; reg90=reg92+reg90;
    reg77=reg56+reg77; reg70=reg70-reg90; reg66=reg66-reg89; reg72=reg78+reg72; reg56=pow(reg60,2);
    T reg110=1.0515668461264170322*elem.pos(5)[1]; reg93=reg93+reg105; reg79=reg79-reg109; T reg111=1.0515668461264170322*elem.pos(5)[0]; reg101=reg101+reg96;
    reg103=reg104+reg103; reg52=reg99+reg52; reg80=reg80-reg108; reg99=pow(reg38,2); reg104=pow(reg71,2);
    reg87=reg87-reg94; T reg112=0.10313369225283431404*elem.pos(6)[2]; reg106=reg95+reg106; reg4=reg4-reg102; reg95=0.28176648720691614667*elem.pos(5)[0];
    reg77=reg107+reg77; reg0=reg0-reg23; T reg113=0.28176648720691614667*elem.pos(5)[1]; T reg114=0.28176648720691614667*elem.pos(7)[2]; reg98=reg98+reg61;
    T reg115=1.0515668461264170322*elem.pos(7)[2]; reg17=reg61+reg17; reg52=pow(reg52,0.5); reg61=pow(reg72,2); reg87=reg87-reg112;
    reg80=reg80-reg105; T reg116=1.0515668461264170322*elem.pos(5)[2]; reg66=reg66-reg109; reg0=reg0+reg113; reg106=pow(reg106,0.5);
    reg99=reg103+reg99; reg79=reg79-reg96; reg98=reg98+reg114; reg103=0.28176648720691614667*elem.pos(5)[2]; reg83=reg83-reg77;
    reg70=reg70-reg108; reg93=reg93-reg110; reg4=reg4+reg95; reg101=reg101-reg111; reg104=reg56+reg104;
    reg17=reg17-reg115; reg87=reg87-reg114; reg17=reg17+reg103; reg93=reg93-reg86; reg0=reg0-reg86;
    reg4=reg4-reg88; reg80=reg110+reg80; reg61=reg104+reg61; reg101=reg101-reg88; reg83=reg83-reg112;
    reg70=reg23+reg70; reg99=pow(reg99,0.5); reg66=reg102+reg66; reg98=reg98-reg116; reg56=reg34/reg106;
    reg79=reg111+reg79; reg104=reg39/reg52; T reg117=reg25/reg106; T reg118=reg43/reg52; T reg119=reg104*reg101;
    reg79=reg88+reg79; T reg120=reg56*reg4; reg87=reg116+reg87; reg98=reg98-reg78; reg83=reg115+reg83;
    reg70=reg70-reg113; reg106=reg46/reg106; T reg121=reg118*reg93; reg17=reg17-reg78; T reg122=reg18/reg99;
    T reg123=reg12/reg99; reg52=reg49/reg52; reg66=reg66-reg95; T reg124=reg117*reg0; reg61=pow(reg61,0.5);
    reg80=reg86+reg80; reg70=reg86+reg70; reg99=reg38/reg99; T reg125=reg123*reg79; reg83=reg83-reg103;
    reg87=reg78+reg87; T reg126=reg60/reg61; T reg127=reg52*reg98; T reg128=reg106*reg17; reg121=reg119+reg121;
    reg66=reg88+reg66; reg124=reg120+reg124; reg119=reg71/reg61; reg120=reg122*reg80; reg83=reg78+reg83;
    T reg129=reg126*reg66; reg61=reg72/reg61; reg120=reg125+reg120; reg125=reg119*reg70; T reg130=reg99*reg87;
    reg127=reg121+reg127; reg128=reg124+reg128; reg121=reg117*reg128; reg130=reg120+reg130; reg120=reg104*reg127;
    reg124=reg61*reg83; T reg131=reg118*reg127; reg125=reg129+reg125; reg129=reg56*reg128; reg124=reg125+reg124;
    reg125=reg123*reg130; reg131=reg93-reg131; reg120=reg101-reg120; T reg132=reg52*reg127; reg129=reg4-reg129;
    T reg133=reg106*reg128; T reg134=reg122*reg130; reg121=reg0-reg121; T reg135=reg99*reg130; reg134=reg80-reg134;
    reg132=reg98-reg132; T reg136=pow(reg131,2); T reg137=pow(reg120,2); reg125=reg79-reg125; T reg138=reg119*reg124;
    T reg139=reg126*reg124; reg133=reg17-reg133; T reg140=pow(reg121,2); T reg141=pow(reg129,2); T reg142=0.014886066246173484324*elem.pos(0)[2];
    T reg143=0.055555555555555552339*elem.pos(1)[2]; T reg144=pow(reg125,2); T reg145=0.055555555555555552339*elem.pos(1)[0]; T reg146=0.014886066246173484324*elem.pos(0)[0]; T reg147=pow(reg134,2);
    reg135=reg87-reg135; T reg148=0.055555555555555552339*elem.pos(1)[1]; T reg149=0.014886066246173484324*elem.pos(0)[1]; T reg150=0.014886066246173484324*elem.pos(1)[1]; T reg151=0.055555555555555552339*elem.pos(0)[1];
    T reg152=0.014886066246173484324*elem.pos(1)[0]; T reg153=0.055555555555555552339*elem.pos(0)[0]; T reg154=reg61*reg124; reg138=reg70-reg138; reg139=reg66-reg139;
    T reg155=pow(reg132,2); reg136=reg137+reg136; reg140=reg141+reg140; reg137=pow(reg133,2); reg141=0.014886066246173484324*elem.pos(1)[2];
    T reg156=0.055555555555555552339*elem.pos(0)[2]; reg142=reg142-reg143; T reg157=0.081338978618764150166*elem.pos(4)[2]; reg149=reg149-reg148; T reg158=0.081338978618764150166*elem.pos(4)[1];
    T reg159=0.081338978618764150166*elem.pos(4)[0]; reg146=reg146-reg145; T reg160=pow(reg135,2); reg150=reg150-reg151; reg147=reg144+reg147;
    reg137=reg140+reg137; reg155=reg136+reg155; reg152=reg152-reg153; reg141=reg141-reg156; reg154=reg83-reg154;
    reg136=0.20733615597604870572*elem.pos(1)[2]; reg140=pow(reg138,2); reg144=0.20733615597604870572*elem.pos(1)[1]; T reg161=0.20733615597604870572*elem.pos(1)[0]; T reg162=pow(reg139,2);
    T reg163=0.30356120084098635952*elem.pos(4)[1]; T reg164=0.20733615597604870572*elem.pos(0)[0]; T reg165=0.20733615597604870572*elem.pos(0)[1]; reg149=reg149-reg158; T reg166=0.055555555555555552339*elem.pos(3)[1];
    T reg167=0.055555555555555552339*elem.pos(3)[0]; reg146=reg146-reg159; reg144=reg144-reg151; reg150=reg150-reg158; T reg168=pow(reg154,2);
    T reg169=0.20733615597604870572*elem.pos(3)[1]; reg155=pow(reg155,0.5); reg137=pow(reg137,0.5); reg136=reg136-reg156; T reg170=0.20733615597604870572*elem.pos(3)[2];
    reg141=reg141-reg157; reg161=reg161-reg153; T reg171=0.30356120084098635952*elem.pos(4)[2]; T reg172=0.30356120084098635952*elem.pos(4)[0]; reg152=reg152-reg159;
    reg160=reg147+reg160; reg147=0.20733615597604870572*elem.pos(3)[0]; reg140=reg162+reg140; reg162=0.055555555555555552339*elem.pos(3)[2]; reg142=reg142-reg157;
    T reg173=0.20733615597604870572*elem.pos(0)[2]; reg160=pow(reg160,0.5); T reg174=0.20733615597604870572*elem.pos(2)[1]; T reg175=0.014886066246173484324*elem.pos(3)[1]; reg144=reg144+reg163;
    reg168=reg140+reg168; reg149=reg149-reg166; reg140=0.014886066246173484324*elem.pos(3)[2]; reg136=reg136+reg171; T reg176=0.014886066246173484324*elem.pos(3)[0];
    reg161=reg161+reg172; reg164=reg164-reg145; reg170=reg141+reg170; reg141=0.055555555555555552339*elem.pos(2)[2]; reg121=reg121/reg137;
    reg129=reg129/reg137; reg173=reg173-reg143; reg131=reg131/reg155; reg120=reg120/reg155; reg165=reg165-reg148;
    reg147=reg152+reg147; reg152=0.055555555555555552339*elem.pos(2)[1]; reg146=reg146-reg167; T reg177=0.20733615597604870572*elem.pos(2)[0]; T reg178=0.055555555555555552339*elem.pos(2)[0];
    reg142=reg142-reg162; reg169=reg150+reg169; reg150=0.20733615597604870572*elem.pos(2)[2]; reg175=reg144+reg175; reg144=0.30356120084098635952*elem.pos(6)[1];
    reg170=reg170-reg141; T reg179=reg43*reg131; T reg180=reg39*reg120; reg173=reg171+reg173; reg171=reg25*reg121;
    T reg181=reg34*reg129; reg155=reg132/reg155; reg137=reg133/reg137; reg131=reg93*reg131; reg121=reg0*reg121;
    reg129=reg4*reg129; reg147=reg147-reg178; reg165=reg163+reg165; reg120=reg101*reg120; reg117=reg25*reg117;
    reg56=reg34*reg56; reg104=reg39*reg104; reg118=reg43*reg118; reg168=pow(reg168,0.5); reg177=reg146+reg177;
    reg0=0.30356120084098635952*elem.pos(6)[2]; reg140=reg136+reg140; reg176=reg161+reg176; reg4=0.30356120084098635952*elem.pos(6)[0]; reg174=reg149+reg174;
    reg164=reg172+reg164; reg150=reg142+reg150; reg134=reg134/reg160; reg125=reg125/reg160; reg169=reg169-reg152;
    reg25=0.081338978618764150159*elem.pos(7)[1]; reg174=reg174+reg144; reg138=reg138/reg168; reg169=reg144+reg169; reg139=reg139/reg168;
    reg131=reg120+reg131; reg98=reg98*reg155; reg140=reg140-reg141; reg147=reg4+reg147; reg34=0.081338978618764150166*elem.pos(6)[2];
    reg39=0.30356120084098635952*elem.pos(7)[0]; reg179=reg180+reg179; reg155=reg49*reg155; reg118=reg104+reg118; reg123=reg12*reg123;
    reg122=reg18*reg122; reg150=reg150+reg0; reg79=reg79*reg125; reg80=reg80*reg134; reg160=reg135/reg160;
    reg4=reg177+reg4; reg43=0.081338978618764150159*elem.pos(7)[0]; reg175=reg175-reg152; reg93=0.081338978618764150166*elem.pos(6)[1]; reg101=0.014886066246173484324*elem.pos(2)[2];
    reg165=reg165-reg166; reg104=0.014886066246173484324*elem.pos(2)[1]; reg120=0.014886066246173484324*elem.pos(2)[0]; reg164=reg164-reg167; reg125=reg12*reg125;
    reg173=reg173-reg162; reg134=reg18*reg134; reg17=reg17*reg137; reg12=0.30356120084098635952*elem.pos(7)[2]; reg171=reg181+reg171;
    reg121=reg129+reg121; reg106=reg46*reg106; reg137=reg46*reg137; reg170=reg0+reg170; reg0=0.30356120084098635952*elem.pos(7)[1];
    reg176=reg176-reg178; reg18=0.081338978618764150166*elem.pos(6)[0]; reg117=reg56+reg117; reg46=0.081338978618764150159*elem.pos(7)[2]; reg52=reg49*reg52;
    reg140=reg140-reg34; reg49=0.081338978618764150166*elem.pos(7)[2]; reg104=reg165+reg104; reg56=0.081338978618764150159*elem.pos(5)[2]; reg101=reg173+reg101;
    reg170=reg170+reg12; reg129=0.081338978618764150166*elem.pos(7)[1]; reg174=reg174-reg25; reg132=0.30356120084098635952*elem.pos(5)[1]; reg175=reg175-reg93;
    reg169=reg169+reg0; reg133=0.081338978618764150159*elem.pos(5)[1]; reg135=0.30356120084098635952*elem.pos(5)[2]; reg150=reg150-reg46; reg119=reg71*reg119;
    reg136=0.081338978618764150166*elem.pos(7)[0]; reg176=reg176-reg18; reg126=reg126*reg60; reg4=reg4-reg43; reg142=0.30356120084098635952*elem.pos(5)[0];
    reg66=reg66*reg139; reg70=reg70*reg138; reg168=reg154/reg168; reg137=reg171+reg137; reg139=reg60*reg139;
    reg138=reg71*reg138; reg17=reg121+reg17; reg106=reg117+reg106; reg52=reg118+reg52; reg122=reg123+reg122;
    reg99=reg38*reg99; reg38=reg38*reg160; reg80=reg79+reg80; reg98=reg131+reg98; reg134=reg125+reg134;
    reg160=reg87*reg160; reg155=reg179+reg155; reg120=reg164+reg120; reg60=0.081338978618764150159*elem.pos(5)[0]; reg147=reg147+reg39;
    reg38=reg134+reg38; reg104=reg104-reg93; reg71=0.44444444444444449594*elem.pos(8)[2]; reg120=reg120-reg18; reg160=reg80+reg160;
    reg4=reg4+reg142; reg79=0.44444444444444449594*elem.pos(8)[0]; reg150=reg150+reg135; reg99=reg122+reg99; reg175=reg175-reg129;
    reg101=reg101-reg34; reg140=reg140-reg49; reg147=reg147-reg60; reg155=reg127*reg155; reg98=reg52*reg98;
    reg52=reg72*reg168; reg138=reg139+reg138; reg174=reg174+reg132; reg80=0.44444444444444449594*elem.pos(8)[1]; reg170=reg170-reg56;
    reg17=reg106*reg17; reg168=reg83*reg168; reg70=reg66+reg70; reg137=reg128*reg137; reg61=reg72*reg61;
    reg176=reg176-reg136; reg119=reg126+reg119; reg169=reg169-reg133; reg38=reg130*reg38; reg147=reg79+reg147;
    reg140=reg135+reg140; reg137=reg17-reg137; reg160=reg99*reg160; reg155=reg98-reg155; reg150=reg150+reg71;
    reg170=reg71+reg170; reg176=reg142+reg176; reg169=reg80+reg169; reg4=reg4+reg79; reg175=reg132+reg175;
    reg61=reg119+reg61; reg168=reg70+reg168; reg174=reg174+reg80; reg52=reg138+reg52; reg17=0.081338978618764150166*elem.pos(5)[0];
    reg120=reg39+reg120; reg104=reg0+reg104; reg0=0.081338978618764150166*elem.pos(5)[1]; reg39=0.081338978618764150166*elem.pos(5)[2]; reg101=reg12+reg101;
    reg170=reg137*reg170; reg52=reg124*reg52; reg174=reg155*reg174; reg168=reg61*reg168; reg4=reg4*reg155;
    reg101=reg101-reg39; reg140=reg71+reg140; reg147=reg147*reg137; reg169=reg137*reg169; reg150=reg155*reg150;
    reg38=reg160-reg38; reg176=reg79+reg176; reg175=reg80+reg175; reg104=reg104-reg0; reg120=reg120-reg17;
    reg137=0.25*reg137; reg4=0.25*reg4; reg104=reg80+reg104; reg101=reg71+reg101; reg52=reg168-reg52;
    reg176=reg176*reg38; reg170=0.25*reg170; reg120=reg79+reg120; reg140=reg38*reg140; reg174=0.25*reg174;
    reg175=reg38*reg175; reg155=0.25*reg155; reg147=0.25*reg147; reg169=0.25*reg169; reg150=0.25*reg150;
    reg176=0.25*reg176; reg38=0.25*reg38; reg140=0.25*reg140; reg104=reg52*reg104; reg137=reg155+reg137;
    reg101=reg52*reg101; reg120=reg120*reg52; reg170=reg150+reg170; reg175=0.25*reg175; reg147=reg4+reg147;
    reg169=reg174+reg169; reg101=0.25*reg101; reg140=reg170+reg140; reg104=0.25*reg104; reg175=reg169+reg175;
    reg52=0.25*reg52; reg38=reg137+reg38; reg120=0.25*reg120; reg176=reg147+reg176; reg104=reg175+reg104;
    reg52=reg38+reg52; reg120=reg176+reg120; reg101=reg140+reg101; res[2]=reg101/reg52; res[1]=reg104/reg52;
    res[0]=reg120/reg52;

    return res;
}
}
#endif // LMT_QUAD_9
