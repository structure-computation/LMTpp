#ifndef LMT_QUAD_8
#define LMT_QUAD_8
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_8 &elem) { /// order -> degre du polynome a integrer exactement
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
template<class TNode> void permutation_if_jac_neg(const Quad_8 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=nodes[5]->pos[0]-nodes[7]->pos[0]; T reg1=nodes[6]->pos[1]-nodes[4]->pos[1]; T reg2=nodes[5]->pos[1]-nodes[7]->pos[1]; T reg3=nodes[6]->pos[0]-nodes[4]->pos[0]; reg1=reg0*reg1;
    reg3=reg2*reg3; T det_jac=reg1-reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[7],nodes[3],nodes[6],nodes[2],nodes[5],nodes[1],nodes[4]};
        for(unsigned i=0;i<8;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad_8 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; T reg2=1+reg0; reg1=reg1-1;
    T reg3=1-reg0; T reg4=0.25*reg3; T reg5=1-reg1; T reg6=reg0+reg1; T reg7=0.25*reg2;
    T reg8=reg0-reg1; T reg9=0.5*reg3; T reg10=reg4*reg5; T reg11=1+reg6; T reg12=1+reg1;
    T reg13=reg5*reg7; T reg14=0.5*reg5; T reg15=0.5*reg2; reg8=reg8-1; T reg16=reg8*reg14;
    T reg17=2*reg13; T reg18=2*reg10; T reg19=reg8*reg15; T reg20=reg11*reg14; T reg21=0.5*reg12;
    T reg22=reg11*reg9; reg7=reg12*reg7; reg6=reg6-1; T reg23=reg1-reg0; reg19=reg17+reg19;
    reg22=reg18-reg22; T reg24=reg6*reg15; T reg25=reg6*reg21; T reg26=2*reg7; reg20=reg18-reg20;
    reg4=reg4*reg12; reg17=reg16+reg17; reg23=reg23-1; reg16=pos_nodes[1][0]*reg19; reg18=pos_nodes[0][0]*reg22;
    T reg27=reg23*reg21; T reg28=pos_nodes[1][0]*reg17; T reg29=pos_nodes[0][0]*reg20; T reg30=reg23*reg9; T reg31=pos_nodes[0][1]*reg22;
    T reg32=pos_nodes[1][1]*reg19; reg24=reg26+reg24; T reg33=pos_nodes[1][1]*reg17; T reg34=pos_nodes[0][1]*reg20; T reg35=2*reg4;
    reg25=reg26+reg25; reg11=reg10*reg11; reg27=reg35+reg27; reg10=2*reg0; reg30=reg35+reg30;
    reg29=reg28-reg29; reg26=pos_nodes[2][0]*reg25; reg34=reg33-reg34; reg13=reg8*reg13; reg8=pos_nodes[2][1]*reg25;
    reg28=pow(reg0,2); reg31=reg32+reg31; reg32=pos_nodes[2][0]*reg24; reg33=pos_nodes[2][1]*reg24; reg18=reg16+reg18;
    reg31=reg33-reg31; reg16=pos_nodes[3][1]*reg30; reg8=reg34+reg8; reg33=pow(reg1,2); reg34=pos_nodes[3][0]*reg27;
    reg26=reg29+reg26; reg29=pos_nodes[3][0]*reg30; reg35=pos_nodes[0][1]*reg11; reg18=reg32-reg18; reg32=2*reg1;
    T reg36=pos_nodes[0][0]*reg11; T reg37=pos_nodes[1][0]*reg13; T reg38=reg5*reg10; T reg39=reg13*pos_nodes[1][1]; reg6=reg7*reg6;
    reg28=1-reg28; reg7=pos_nodes[3][1]*reg27; reg29=reg18+reg29; reg18=reg28*pos_nodes[4][0]; T reg40=reg2*reg32;
    T reg41=pos_nodes[4][1]*reg38; reg7=reg8-reg7; reg8=reg6*pos_nodes[2][1]; reg35=reg39-reg35; reg39=0.5*reg28;
    reg23=reg4*reg23; reg36=reg37-reg36; reg4=reg6*pos_nodes[2][0]; reg34=reg26-reg34; reg26=pos_nodes[4][0]*reg38;
    reg33=1-reg33; reg37=reg28*pos_nodes[4][1]; reg16=reg31+reg16; reg5=reg39*reg5; reg31=0.5*reg33;
    reg41=reg7-reg41; reg7=reg33*pos_nodes[5][1]; T reg42=reg23*pos_nodes[3][1]; T reg43=pos_nodes[5][0]*reg40; reg18=reg29-reg18;
    reg8=reg35+reg8; reg4=reg36+reg4; reg29=reg23*pos_nodes[3][0]; reg35=pos_nodes[5][1]*reg40; reg36=reg12*reg10;
    reg26=reg34-reg26; reg34=reg33*pos_nodes[5][0]; reg37=reg16-reg37; reg16=pos_nodes[6][1]*reg36; reg7=reg41+reg7;
    reg41=reg28*pos_nodes[6][1]; reg35=reg37-reg35; reg37=reg5*pos_nodes[4][1]; reg42=reg8+reg42; reg8=reg5*pos_nodes[4][0];
    reg2=reg31*reg2; reg34=reg26+reg34; reg26=pos_nodes[6][0]*reg36; reg29=reg4+reg29; reg4=reg3*reg32;
    T reg44=reg28*pos_nodes[6][0]; reg43=reg18-reg43; reg18=pos_nodes[7][1]*reg4; reg41=reg35+reg41; reg8=reg29+reg8;
    reg29=reg2*pos_nodes[5][0]; reg26=reg34-reg26; reg34=reg33*pos_nodes[7][0]; reg44=reg43+reg44; reg35=reg33*pos_nodes[7][1];
    reg16=reg7-reg16; reg7=pos_nodes[7][0]*reg4; reg12=reg39*reg12; reg37=reg42+reg37; reg39=reg2*pos_nodes[5][1];
    reg18=reg41-reg18; reg31=reg3*reg31; reg39=reg37+reg39; reg3=reg12*pos_nodes[6][1]; reg34=reg26-reg34;
    reg35=reg16-reg35; reg7=reg44-reg7; reg29=reg8+reg29; reg8=reg12*pos_nodes[6][0]; reg16=reg7*reg35;
    reg26=reg31*pos_nodes[7][1]; reg3=reg39+reg3; reg37=reg34*reg18; reg8=reg29+reg8; reg29=reg31*pos_nodes[7][0];
    reg26=reg3+reg26; reg16=reg37-reg16; reg29=reg8+reg29; reg3=reg7/reg16; reg8=reg35/reg16;
    reg39=reg34/reg16; reg16=reg18/reg16; reg26=pos[1]-reg26; reg29=pos[0]-reg29; reg16=reg29*reg16;
    reg3=reg26*reg3; reg8=reg29*reg8; reg39=reg26*reg39; var_inter[0]=reg16-reg3; var_inter[1]=reg39-reg8;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_8 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; T reg2=1+reg0; T reg3=1-reg0;
    reg1=reg1-1; T reg4=1-reg1; T reg5=0.25*reg3; T reg6=reg0+reg1; T reg7=reg0-reg1;
    T reg8=0.25*reg2; T reg9=0.5*reg3; T reg10=0.5*reg4; reg7=reg7-1; T reg11=reg8*reg4;
    T reg12=1+reg1; T reg13=1+reg6; T reg14=0.5*reg2; T reg15=reg5*reg4; T reg16=reg7*reg14;
    T reg17=reg13*reg10; T reg18=reg7*reg10; T reg19=2*reg11; T reg20=2*reg15; T reg21=0.5*reg12;
    T reg22=reg13*reg9; reg8=reg12*reg8; reg6=reg6-1; T reg23=reg1-reg0; reg17=reg20-reg17;
    T reg24=2*reg8; reg18=reg19+reg18; T reg25=reg6*reg21; reg5=reg12*reg5; reg23=reg23-1;
    T reg26=reg6*reg14; reg22=reg20-reg22; reg16=reg19+reg16; reg19=reg23*reg9; reg26=reg24+reg26;
    reg25=reg24+reg25; reg20=2*reg5; reg24=reg23*reg21; T reg27=pos_nodes[1][0]*reg18; T reg28=pos_nodes[0][0]*reg17;
    T reg29=pos_nodes[0][0]*reg22; T reg30=pos_nodes[0][1]*reg22; T reg31=pos_nodes[1][1]*reg16; T reg32=pos_nodes[1][0]*reg16; T reg33=pos_nodes[0][1]*reg17;
    T reg34=pos_nodes[1][1]*reg18; T reg35=pos_nodes[2][1]*reg26; reg33=reg34-reg33; reg34=pos_nodes[2][1]*reg25; reg30=reg31+reg30;
    reg29=reg32+reg29; reg31=pos_nodes[2][0]*reg26; reg32=pos_nodes[2][0]*reg25; reg28=reg27-reg28; reg27=2*reg0;
    reg24=reg20+reg24; reg19=reg20+reg19; reg7=reg11*reg7; reg15=reg13*reg15; reg11=pow(reg0,2);
    reg13=reg7*pos_nodes[1][0]; reg20=pos_nodes[3][1]*reg24; T reg36=pow(reg1,2); T reg37=pos_nodes[0][0]*reg15; T reg38=2*reg1;
    reg6=reg8*reg6; reg11=1-reg11; reg30=reg35-reg30; reg34=reg33+reg34; reg8=pos_nodes[3][0]*reg24;
    reg32=reg28+reg32; reg28=reg15*pos_nodes[0][1]; reg33=pos_nodes[1][1]*reg7; reg35=pos_nodes[3][1]*reg19; reg29=reg31-reg29;
    reg31=reg27*reg4; T reg39=pos_nodes[3][0]*reg19; T reg40=pos_nodes[4][0]*reg11; reg39=reg29+reg39; reg37=reg13-reg37;
    reg13=pos_nodes[2][0]*reg6; reg23=reg5*reg23; reg5=0.5*reg11; reg36=1-reg36; reg29=pos_nodes[2][1]*reg6;
    reg28=reg33-reg28; reg33=pos_nodes[4][1]*reg11; reg35=reg30+reg35; reg8=reg32-reg8; reg30=pos_nodes[4][0]*reg31;
    reg32=reg2*reg38; T reg41=pos_nodes[4][1]*reg31; reg20=reg34-reg20; reg33=reg35-reg33; reg34=pos_nodes[5][1]*reg32;
    reg41=reg20-reg41; reg29=reg28+reg29; reg20=reg36*pos_nodes[5][1]; reg28=pos_nodes[3][0]*reg23; reg13=reg37+reg13;
    reg35=pos_nodes[3][1]*reg23; reg40=reg39-reg40; reg37=pos_nodes[5][0]*reg32; reg39=0.5*reg36; reg4=reg5*reg4;
    T reg42=reg12*reg27; T reg43=reg36*pos_nodes[5][0]; reg30=reg8-reg30; reg8=pos_nodes[6][1]*reg42; reg41=reg20+reg41;
    reg34=reg33-reg34; reg20=reg11*pos_nodes[6][1]; reg33=reg38*reg3; reg30=reg43+reg30; reg43=pos_nodes[6][0]*reg42;
    reg37=reg40-reg37; reg40=reg11*pos_nodes[6][0]; reg2=reg2*reg39; reg35=reg29+reg35; reg29=pos_nodes[4][0]*reg4;
    reg28=reg13+reg28; reg13=pos_nodes[4][1]*reg4; reg20=reg34+reg20; reg34=pos_nodes[7][1]*reg33; T reg44=reg2*pos_nodes[5][1];
    reg13=reg35+reg13; reg43=reg30-reg43; reg30=reg36*pos_nodes[7][0]; reg35=reg36*pos_nodes[7][1]; T reg45=reg2*pos_nodes[5][0];
    reg8=reg41-reg8; reg29=reg28+reg29; reg5=reg12*reg5; reg40=reg37+reg40; reg12=pos_nodes[7][0]*reg33;
    reg28=reg5*pos_nodes[6][1]; reg13=reg44+reg13; reg12=reg40-reg12; reg29=reg45+reg29; reg37=reg5*pos_nodes[6][0];
    reg34=reg20-reg34; reg3=reg39*reg3; reg30=reg43-reg30; reg35=reg8-reg35; reg8=reg3*pos_nodes[7][0];
    reg37=reg29+reg37; reg20=reg12*reg35; reg29=reg30*reg34; reg28=reg13+reg28; reg13=reg3*pos_nodes[7][1];
    reg20=reg29-reg20; reg13=reg28+reg13; reg8=reg37+reg8; reg28=reg12/reg20; reg37=reg30/reg20;
    reg39=reg35/reg20; reg20=reg34/reg20; reg13=pos[1]-reg13; reg8=pos[0]-reg8; reg20=reg8*reg20;
    reg28=reg13*reg28; reg39=reg8*reg39; reg37=reg13*reg37; var_inter[0]+=reg20-reg28; var_inter[1]+=reg37-reg39;

}
template<> struct ElemVarInterFromPosNonLinear<Quad_8> { static const bool res = 2; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; reg0=reg0-1; T reg2=1-reg0; reg1=reg1-1;
    T reg3=1+reg0; T reg4=reg0+reg1; T reg5=1-reg1; T reg6=0.25*reg2; T reg7=0.25*reg3;
    T reg8=reg0-reg1; T reg9=1+reg1; T reg10=reg5*reg7; reg8=reg8-1; T reg11=reg6*reg5;
    T reg12=1+reg4; reg8=reg10*reg8; reg4=reg4-1; reg7=reg9*reg7; reg12=reg11*reg12;
    reg10=reg1-reg0; reg0=pow(reg0,2); reg4=reg7*reg4; reg0=1-reg0; reg6=reg6*reg9;
    reg10=reg10-1; reg1=pow(reg1,2); reg8=val[1]*reg8; reg12=val[0]*reg12; reg12=reg8-reg12;
    reg4=val[2]*reg4; reg1=1-reg1; reg10=reg6*reg10; reg0=0.5*reg0; reg5=reg5*reg0;
    reg10=val[3]*reg10; reg4=reg12+reg4; reg1=0.5*reg1; reg3=reg3*reg1; reg5=val[4]*reg5;
    reg10=reg4+reg10; reg5=reg10+reg5; reg3=val[5]*reg3; reg0=reg9*reg0; reg3=reg5+reg3;
    reg0=val[6]*reg0; reg1=reg2*reg1; reg0=reg3+reg0; reg1=val[7]*reg1; res=reg0+reg1;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Quad_8 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; reg1=reg1-1; T reg2=1-reg0;
    T reg3=pow(reg1,2); T reg4=1+reg0; T reg5=reg0+reg1; T reg6=pow(reg0,2); T reg7=1-reg1;
    T reg8=0.25*reg2; T reg9=reg1-reg0; reg6=1-reg6; reg0=reg0-reg1; reg3=1-reg3;
    T reg10=0.25*reg4; reg1=1+reg1; T reg11=1+reg5; T reg12=reg8*reg7; reg6=0.5*reg6;
    reg3=0.5*reg3; reg9=reg9-1; reg8=reg8*reg1; reg5=reg5-1; T reg13=reg1*reg10;
    reg0=reg0-1; reg10=reg7*reg10; reg11=reg12*reg11; reg9=reg8*reg9; res[3]=reg9;
    reg5=reg13*reg5; res[2]=reg5; reg0=reg10*reg0; res[1]=reg0; reg7=reg7*reg6;
    res[4]=reg7; reg4=reg4*reg3; res[5]=reg4; reg6=reg1*reg6; res[6]=reg6;
    reg3=reg2*reg3; res[7]=reg3; res[0]=-reg11;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Quad_8> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

}
#endif // LMT_QUAD_8
