#ifndef LMT_QUAD_9
#define LMT_QUAD_9
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_9 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 13, 26, 39, 52, 74, 96, 118, 140, 162, }; // fonction de lordre du poly
    static const double values[] = {
        0.25,0.788675134595,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.788675134595,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.788675134595,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.788675134595,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.25,0.788675134595,0.788675134595,
        0.25,0.788675134595,0.211324865405,
        0.25,0.211324865405,0.788675134595,
        0.25,0.211324865405,0.211324865405,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
        0.285714285714,0.5,0.5,
        0.14880952381,0.158434974468,0.158434974468,
        0.14880952381,0.841565025532,0.841565025532,
        0.104166666667,0.312871678857,0.94532721089,
        0.104166666667,0.687128321143,0.0546727891096,
        0.104166666667,0.0546727891096,0.687128321143,
        0.104166666667,0.94532721089,0.312871678857,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Quad_9 &elem,TNode **nodes) {

    if ( nodes[0]->pos.size() != 2 )
        return;

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
    T reg0=var_inter[0]-0.5; T reg1=0.5-var_inter[0]; T reg2=1-var_inter[0]; T reg3=4*reg0; T reg4=4*reg1;
    T reg5=4*var_inter[0]; T reg6=4*reg2; T reg7=1-var_inter[1]; T reg8=reg6*reg1; T reg9=0.5-var_inter[1];
    T reg10=reg5*reg0; T reg11=8*var_inter[0]; T reg12=8*reg2; reg4=reg6+reg4; reg3=reg5+reg3;
    reg5=reg8*reg7; reg6=reg12-reg11; T reg13=reg8*reg9; T reg14=reg7*reg10; T reg15=reg9*reg10;
    T reg16=reg7*reg3; T reg17=var_inter[0]*reg12; T reg18=reg7*reg4; T reg19=reg9*reg17; reg16=reg9*reg16;
    T reg20=reg7*reg6; T reg21=reg7*reg17; reg15=reg14+reg15; T reg22=var_inter[1]-0.5; reg13=reg5+reg13;
    T reg23=reg9*reg18; T reg24=pos_nodes[0][1]*reg23; T reg25=reg8*var_inter[1]; reg19=reg21+reg19; T reg26=var_inter[1]*reg4;
    reg20=reg9*reg20; T reg27=pos_nodes[1][0]*reg15; T reg28=reg23*pos_nodes[0][0]; T reg29=pos_nodes[1][0]*reg16; T reg30=pos_nodes[1][1]*reg15;
    T reg31=pos_nodes[0][1]*reg13; T reg32=reg8*reg22; T reg33=pos_nodes[1][1]*reg16; T reg34=pos_nodes[0][0]*reg13; reg28=reg29-reg28;
    reg29=pos_nodes[4][0]*reg20; reg30=reg31+reg30; reg31=pos_nodes[4][1]*reg19; T reg35=pos_nodes[4][1]*reg20; T reg36=var_inter[1]*reg10;
    T reg37=pos_nodes[4][0]*reg19; reg27=reg34+reg27; reg34=reg10*reg22; reg32=reg25+reg32; reg5=reg5*reg9;
    reg14=reg9*reg14; T reg38=reg26*reg22; reg3=var_inter[1]*reg3; reg24=reg33-reg24; reg33=8*reg1;
    reg1=reg1*reg12; T reg39=pos_nodes[1][0]*reg14; reg21=reg9*reg21; reg34=reg36+reg34; reg9=reg17*reg22;
    T reg40=pos_nodes[0][0]*reg5; T reg41=var_inter[1]*reg17; reg35=reg24+reg35; reg37=reg27+reg37; reg24=pos_nodes[3][1]*reg38;
    reg27=pos_nodes[1][1]*reg14; T reg42=pos_nodes[0][1]*reg5; T reg43=pos_nodes[3][0]*reg32; reg3=reg3*reg22; reg6=var_inter[1]*reg6;
    reg33=reg12+reg33; reg12=8*reg0; reg31=reg30+reg31; reg29=reg28+reg29; reg28=pos_nodes[3][0]*reg38;
    reg30=pos_nodes[3][1]*reg32; T reg44=var_inter[1]*reg1; reg9=reg41+reg9; T reg45=pos_nodes[4][1]*reg21; reg27=reg42+reg27;
    reg39=reg40+reg39; reg40=pos_nodes[4][0]*reg21; reg2=16*reg2; reg42=pos_nodes[2][0]*reg34; reg37=reg43-reg37;
    reg0=reg0*reg11; reg43=pos_nodes[2][1]*reg3; T reg46=reg7*reg1; reg24=reg35-reg24; reg35=pos_nodes[2][0]*reg3;
    reg6=reg6*reg22; T reg47=reg7*reg33; reg25=reg25*reg22; reg28=reg29-reg28; reg29=pos_nodes[2][1]*reg34;
    reg11=reg12+reg11; reg31=reg30-reg31; reg12=16*var_inter[0]; reg42=reg37+reg42; reg30=pos_nodes[3][1]*reg25;
    reg37=pos_nodes[6][0]*reg9; reg45=reg27+reg45; reg40=reg39+reg40; reg27=pos_nodes[3][0]*reg25; reg39=pos_nodes[6][1]*reg9;
    reg29=reg31+reg29; reg43=reg24+reg43; reg24=pos_nodes[6][1]*reg6; reg31=reg7*reg0; T reg48=var_inter[0]*reg2;
    reg44=reg46-reg44; T reg49=var_inter[1]*reg47; reg11=reg7*reg11; reg12=reg2-reg12; reg2=var_inter[1]*reg0;
    reg36=reg22*reg36; T reg50=pos_nodes[6][0]*reg6; reg35=reg28+reg35; reg11=var_inter[1]*reg11; reg12=reg7*reg12;
    reg39=reg29+reg39; reg41=reg22*reg41; reg22=pos_nodes[7][1]*reg44; reg28=pos_nodes[7][0]*reg49; reg50=reg35+reg50;
    reg29=pos_nodes[2][0]*reg36; reg27=reg40+reg27; reg7=reg7*reg48; reg30=reg45+reg30; reg35=pos_nodes[2][1]*reg36;
    reg24=reg43+reg24; reg40=pos_nodes[7][0]*reg44; reg37=reg42+reg37; reg2=reg31-reg2; reg42=var_inter[1]*reg48;
    reg43=pos_nodes[7][1]*reg49; reg43=reg24-reg43; reg24=pos_nodes[5][1]*reg11; reg12=var_inter[1]*reg12; reg22=reg39+reg22;
    reg39=pos_nodes[5][1]*reg2; reg35=reg30+reg35; reg30=pos_nodes[6][1]*reg41; reg29=reg27+reg29; reg27=pos_nodes[6][0]*reg41;
    reg45=pos_nodes[5][0]*reg2; reg40=reg37+reg40; reg42=reg7-reg42; reg46=var_inter[1]*reg46; reg28=reg50-reg28;
    reg37=pos_nodes[5][0]*reg11; reg31=var_inter[1]*reg31; reg50=pos_nodes[8][1]*reg42; reg39=reg22+reg39; reg27=reg29+reg27;
    reg22=pos_nodes[7][0]*reg46; reg29=pos_nodes[8][0]*reg42; reg45=reg40+reg45; reg24=reg43+reg24; reg40=pos_nodes[8][1]*reg12;
    reg30=reg35+reg30; reg35=pos_nodes[7][1]*reg46; reg37=reg28+reg37; reg28=pos_nodes[8][0]*reg12; reg29=reg45+reg29;
    reg43=pos_nodes[5][1]*reg31; reg7=var_inter[1]*reg7; reg35=reg30+reg35; reg40=reg24+reg40; reg28=reg37+reg28;
    reg50=reg39+reg50; reg22=reg27+reg22; reg24=pos_nodes[5][0]*reg31; reg24=reg22+reg24; reg22=pos_nodes[8][0]*reg7;
    reg43=reg35+reg43; reg27=pos_nodes[8][1]*reg7; reg30=reg28*reg50; reg35=reg29*reg40; reg22=reg24+reg22;
    reg27=reg43+reg27; reg35=reg30-reg35; reg24=reg28/reg35; reg37=reg29/reg35; reg39=reg40/reg35;
    reg35=reg50/reg35; reg27=pos[1]-reg27; reg22=pos[0]-reg22; reg35=reg22*reg35; reg37=reg27*reg37;
    reg39=reg22*reg39; reg24=reg27*reg24; var_inter[0]=reg35-reg37; var_inter[1]=reg24-reg39;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_9 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=var_inter[0]-0.5; T reg1=1-var_inter[0]; T reg2=0.5-var_inter[0]; T reg3=4*var_inter[0]; T reg4=4*reg2;
    T reg5=4*reg0; T reg6=4*reg1; T reg7=0.5-var_inter[1]; reg4=reg6+reg4; T reg8=reg3*reg0;
    reg6=reg6*reg2; reg5=reg3+reg5; reg3=1-var_inter[1]; T reg9=8*reg1; T reg10=8*var_inter[0];
    T reg11=reg3*reg8; T reg12=reg3*reg5; T reg13=reg9-reg10; T reg14=reg6*reg7; T reg15=reg3*reg4;
    T reg16=reg7*reg8; T reg17=reg9*var_inter[0]; T reg18=reg6*reg3; T reg19=var_inter[1]-0.5; T reg20=reg7*reg15;
    reg12=reg7*reg12; T reg21=reg3*reg13; reg14=reg18+reg14; reg16=reg11+reg16; T reg22=reg7*reg17;
    T reg23=reg3*reg17; T reg24=pos_nodes[1][0]*reg16; T reg25=pos_nodes[0][0]*reg14; T reg26=pos_nodes[1][1]*reg12; T reg27=pos_nodes[0][1]*reg20;
    T reg28=reg6*reg19; reg21=reg7*reg21; T reg29=var_inter[1]*reg4; T reg30=pos_nodes[0][1]*reg14; T reg31=pos_nodes[1][1]*reg16;
    reg22=reg23+reg22; T reg32=pos_nodes[0][0]*reg20; T reg33=reg6*var_inter[1]; T reg34=pos_nodes[1][0]*reg12; T reg35=reg19*reg29;
    reg5=var_inter[1]*reg5; reg28=reg33+reg28; T reg36=reg8*reg19; T reg37=pos_nodes[4][0]*reg21; reg32=reg34-reg32;
    reg24=reg25+reg24; reg25=8*reg2; reg34=pos_nodes[4][0]*reg22; T reg38=reg8*var_inter[1]; reg27=reg26-reg27;
    reg26=pos_nodes[4][1]*reg21; T reg39=pos_nodes[4][1]*reg22; reg18=reg18*reg7; reg11=reg7*reg11; reg31=reg30+reg31;
    reg30=pos_nodes[1][1]*reg11; T reg40=reg18*pos_nodes[0][1]; reg39=reg31+reg39; reg37=reg32+reg37; reg31=pos_nodes[3][0]*reg35;
    reg32=pos_nodes[3][1]*reg28; T reg41=pos_nodes[3][1]*reg35; reg26=reg27+reg26; reg36=reg38+reg36; reg27=pos_nodes[1][0]*reg11;
    T reg42=pos_nodes[0][0]*reg18; T reg43=reg17*reg19; T reg44=pos_nodes[3][0]*reg28; reg34=reg24+reg34; reg13=var_inter[1]*reg13;
    reg23=reg7*reg23; reg5=reg19*reg5; reg7=reg17*var_inter[1]; reg2=reg2*reg9; reg24=8*reg0;
    reg25=reg9+reg25; reg1=16*reg1; reg43=reg7+reg43; reg9=reg3*reg25; reg34=reg44-reg34;
    reg44=pos_nodes[2][0]*reg36; reg27=reg42+reg27; reg42=pos_nodes[4][0]*reg23; reg41=reg26-reg41; reg26=pos_nodes[2][1]*reg5;
    T reg45=reg23*pos_nodes[4][1]; T reg46=reg3*reg2; reg39=reg32-reg39; reg32=pos_nodes[2][1]*reg36; reg33=reg33*reg19;
    reg30=reg40+reg30; reg13=reg19*reg13; reg0=reg10*reg0; reg40=16*var_inter[0]; reg24=reg10+reg24;
    reg31=reg37-reg31; reg10=pos_nodes[2][0]*reg5; reg37=reg2*var_inter[1]; reg42=reg27+reg42; reg27=pos_nodes[3][0]*reg33;
    T reg47=pos_nodes[6][0]*reg13; reg10=reg31+reg10; reg26=reg41+reg26; reg31=pos_nodes[6][1]*reg13; reg41=pos_nodes[3][1]*reg33;
    reg45=reg30+reg45; reg24=reg3*reg24; reg38=reg19*reg38; reg32=reg39+reg32; reg30=pos_nodes[6][1]*reg43;
    reg40=reg1-reg40; reg39=var_inter[1]*reg9; reg37=reg46-reg37; reg44=reg34+reg44; reg34=pos_nodes[6][0]*reg43;
    T reg48=reg0*var_inter[1]; T reg49=reg3*reg0; reg1=reg1*var_inter[0]; T reg50=pos_nodes[7][0]*reg39; reg47=reg10+reg47;
    reg31=reg26+reg31; reg10=pos_nodes[7][1]*reg39; reg26=pos_nodes[2][1]*reg38; reg41=reg45+reg41; reg40=reg3*reg40;
    reg45=pos_nodes[7][0]*reg37; reg30=reg32+reg30; reg3=reg3*reg1; reg32=pos_nodes[7][1]*reg37; T reg51=reg1*var_inter[1];
    reg48=reg49-reg48; reg7=reg19*reg7; reg24=var_inter[1]*reg24; reg34=reg44+reg34; reg27=reg42+reg27;
    reg19=pos_nodes[2][0]*reg38; reg19=reg27+reg19; reg27=reg7*pos_nodes[6][0]; reg26=reg41+reg26; reg41=reg7*pos_nodes[6][1];
    reg51=reg3-reg51; reg42=pos_nodes[5][1]*reg24; reg10=reg31-reg10; reg31=pos_nodes[5][0]*reg48; reg30=reg32+reg30;
    reg32=pos_nodes[5][1]*reg48; reg50=reg47-reg50; reg46=reg46*var_inter[1]; reg44=pos_nodes[5][0]*reg24; reg34=reg45+reg34;
    reg40=var_inter[1]*reg40; reg45=reg46*pos_nodes[7][0]; reg49=reg49*var_inter[1]; reg47=pos_nodes[8][0]*reg51; reg31=reg34+reg31;
    reg32=reg30+reg32; reg30=pos_nodes[8][1]*reg51; reg34=reg46*pos_nodes[7][1]; reg44=reg50+reg44; reg50=pos_nodes[8][0]*reg40;
    reg41=reg26+reg41; reg26=pos_nodes[8][1]*reg40; reg42=reg10+reg42; reg27=reg19+reg27; reg41=reg34+reg41;
    reg10=reg49*pos_nodes[5][1]; reg30=reg32+reg30; reg50=reg44+reg50; reg19=reg49*pos_nodes[5][0]; reg27=reg45+reg27;
    reg3=reg3*var_inter[1]; reg47=reg31+reg47; reg26=reg42+reg26; reg31=reg50*reg30; reg32=reg3*pos_nodes[8][1];
    reg10=reg41+reg10; reg34=reg47*reg26; reg41=reg3*pos_nodes[8][0]; reg19=reg27+reg19; reg34=reg31-reg34;
    reg41=reg19+reg41; reg32=reg10+reg32; reg10=reg50/reg34; reg19=reg47/reg34; reg27=reg26/reg34;
    reg34=reg30/reg34; reg41=pos[0]-reg41; reg32=pos[1]-reg32; reg10=reg10*reg32; reg27=reg41*reg27;
    reg19=reg19*reg32; reg34=reg41*reg34; var_inter[0]+=reg34-reg19; var_inter[1]+=reg10-reg27;

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
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=4*reg0; T reg3=var_inter[0]-0.5; T reg4=4*var_inter[0];
    T reg5=8*reg0; reg2=reg2*reg1; T reg6=1-var_inter[1]; reg4=reg4*reg3; T reg7=reg2*reg6;
    T reg8=0.5-var_inter[1]; T reg9=var_inter[0]*reg5; T reg10=reg6*reg4; reg7=reg7*reg8; reg10=reg8*reg10;
    T reg11=reg6*reg9; reg10=val[1]*reg10; reg11=reg8*reg11; reg2=var_inter[1]*reg2; reg8=var_inter[1]-0.5;
    reg7=val[0]*reg7; reg10=reg7+reg10; reg4=var_inter[1]*reg4; reg11=val[4]*reg11; reg2=reg2*reg8;
    reg2=val[3]*reg2; reg4=reg8*reg4; reg9=var_inter[1]*reg9; reg11=reg10+reg11; reg7=8*var_inter[0];
    reg5=reg1*reg5; reg9=reg8*reg9; reg0=16*reg0; reg5=reg6*reg5; reg4=val[2]*reg4;
    reg2=reg11+reg2; reg7=reg3*reg7; reg5=var_inter[1]*reg5; reg7=reg6*reg7; reg9=val[6]*reg9;
    reg4=reg2+reg4; reg0=var_inter[0]*reg0; reg7=var_inter[1]*reg7; reg0=reg6*reg0; reg5=val[7]*reg5;
    reg9=reg4+reg9; reg5=reg9+reg5; reg7=val[5]*reg7; reg0=var_inter[1]*reg0; reg7=reg5+reg7;
    reg0=val[8]*reg0; res=reg7+reg0;

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
    T reg5=16*reg0; T reg6=0.5-var_inter[0]; reg0=4*reg0; reg5=var_inter[0]*reg5; T reg7=1-var_inter[1];
    reg4=reg4*reg3; reg0=reg0*reg6; T reg8=var_inter[0]*reg2; reg1=reg3*reg1; reg2=reg6*reg2;
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
