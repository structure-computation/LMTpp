#ifndef LMT_QUAD_8
#define LMT_QUAD_8
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_8 &elem) { /// order -> degre du polynome a integrer exactement
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
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; reg1=reg1-1; T reg2=1-reg0;
    T reg3=1+reg0; T reg4=reg0-reg1; T reg5=0.25*reg3; T reg6=0.25*reg2; T reg7=1-reg1;
    T reg8=reg0+reg1; T reg9=0.5*reg2; T reg10=0.5*reg7; T reg11=0.5*reg3; T reg12=1+reg1;
    T reg13=reg6*reg7; T reg14=reg7*reg5; T reg15=1+reg8; reg4=reg4-1; T reg16=reg15*reg9;
    reg5=reg12*reg5; T reg17=2*reg14; T reg18=reg4*reg10; T reg19=2*reg13; T reg20=reg15*reg10;
    T reg21=0.5*reg12; T reg22=reg1-reg0; reg8=reg8-1; T reg23=reg4*reg11; reg20=reg19-reg20;
    reg18=reg17+reg18; T reg24=2*reg5; T reg25=reg8*reg21; reg23=reg17+reg23; reg16=reg19-reg16;
    reg17=reg8*reg11; reg6=reg6*reg12; reg22=reg22-1; reg25=reg24+reg25; reg19=2*reg6;
    T reg26=reg22*reg21; T reg27=pos_nodes[1][0]*reg18; T reg28=pos_nodes[0][0]*reg20; T reg29=pos_nodes[0][1]*reg16; T reg30=pos_nodes[1][1]*reg23;
    reg17=reg24+reg17; reg24=reg22*reg9; T reg31=pos_nodes[1][0]*reg23; T reg32=pos_nodes[0][0]*reg16; T reg33=pos_nodes[1][1]*reg18;
    T reg34=pos_nodes[0][1]*reg20; reg34=reg33-reg34; reg33=pos_nodes[2][1]*reg25; reg32=reg31+reg32; reg31=pos_nodes[2][0]*reg17;
    reg24=reg19+reg24; reg15=reg13*reg15; reg4=reg14*reg4; reg13=pos_nodes[2][1]*reg17; reg29=reg30+reg29;
    reg14=pos_nodes[2][0]*reg25; reg28=reg27-reg28; reg27=pow(reg0,2); reg30=2*reg0; reg26=reg19+reg26;
    reg27=1-reg27; reg19=reg4*pos_nodes[1][1]; reg8=reg5*reg8; reg5=2*reg1; T reg35=pos_nodes[3][1]*reg24;
    reg32=reg31-reg32; reg31=pos_nodes[3][0]*reg24; T reg36=pow(reg1,2); reg33=reg34+reg33; reg34=pos_nodes[3][1]*reg26;
    reg29=reg13-reg29; reg13=pos_nodes[1][0]*reg4; T reg37=pos_nodes[3][0]*reg26; reg14=reg28+reg14; reg28=reg7*reg30;
    T reg38=pos_nodes[0][1]*reg15; T reg39=pos_nodes[0][0]*reg15; T reg40=reg27*pos_nodes[4][0]; reg31=reg32+reg31; reg34=reg33-reg34;
    reg32=pos_nodes[2][0]*reg8; reg33=pos_nodes[4][1]*reg28; T reg41=0.5*reg27; reg39=reg13-reg39; reg13=reg3*reg5;
    reg22=reg6*reg22; reg35=reg29+reg35; reg6=reg27*pos_nodes[4][1]; reg36=1-reg36; reg37=reg14-reg37;
    reg14=pos_nodes[2][1]*reg8; reg29=pos_nodes[4][0]*reg28; reg38=reg19-reg38; reg19=0.5*reg36; reg32=reg39+reg32;
    reg39=reg22*pos_nodes[3][0]; reg14=reg38+reg14; reg38=reg22*pos_nodes[3][1]; reg7=reg7*reg41; reg33=reg34-reg33;
    reg34=reg36*pos_nodes[5][1]; T reg42=pos_nodes[5][0]*reg13; reg40=reg31-reg40; reg31=reg36*pos_nodes[5][0]; reg29=reg37-reg29;
    reg37=reg12*reg30; T reg43=pos_nodes[5][1]*reg13; reg6=reg35-reg6; reg34=reg33+reg34; reg33=pos_nodes[6][1]*reg37;
    reg35=reg27*pos_nodes[6][1]; reg43=reg6-reg43; reg38=reg14+reg38; reg6=reg7*pos_nodes[4][0]; reg39=reg32+reg39;
    reg14=reg7*pos_nodes[4][1]; reg32=reg27*pos_nodes[6][0]; reg42=reg40-reg42; reg40=reg2*reg5; reg3=reg3*reg19;
    reg31=reg29+reg31; reg29=pos_nodes[6][0]*reg37; T reg44=pos_nodes[7][1]*reg40; reg35=reg43+reg35; reg43=reg3*pos_nodes[5][1];
    reg41=reg12*reg41; reg29=reg31-reg29; reg12=reg36*pos_nodes[7][0]; reg14=reg38+reg14; reg31=reg36*pos_nodes[7][1];
    reg33=reg34-reg33; reg32=reg42+reg32; reg34=pos_nodes[7][0]*reg40; reg6=reg39+reg6; reg38=reg3*pos_nodes[5][0];
    reg44=reg35-reg44; reg43=reg14+reg43; reg14=reg41*pos_nodes[6][1]; reg31=reg33-reg31; reg19=reg2*reg19;
    reg12=reg29-reg12; reg2=reg41*pos_nodes[6][0]; reg38=reg6+reg38; reg34=reg32-reg34; reg6=reg34*reg31;
    reg29=reg19*pos_nodes[7][1]; reg14=reg43+reg14; reg2=reg38+reg2; reg32=reg12*reg44; reg33=reg19*pos_nodes[7][0];
    reg6=reg32-reg6; reg29=reg14+reg29; reg33=reg2+reg33; reg33=pos[0]-reg33; reg29=pos[1]-reg29;
    reg2=reg44/reg6; reg14=reg31/reg6; reg35=reg34/reg6; reg6=reg12/reg6; reg2=reg33*reg2;
    reg35=reg29*reg35; reg14=reg33*reg14; reg6=reg29*reg6; var_inter[0]=reg2-reg35; var_inter[1]=reg6-reg14;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_8 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; reg1=reg1-1; T reg2=1-reg0;
    T reg3=1+reg0; T reg4=reg1+reg0; T reg5=reg0-reg1; T reg6=0.25*reg2; T reg7=1-reg1;
    T reg8=0.25*reg3; T reg9=reg6*reg7; T reg10=1+reg4; T reg11=1+reg1; T reg12=0.5*reg7;
    T reg13=reg7*reg8; reg5=reg5-1; T reg14=0.5*reg2; T reg15=0.5*reg3; reg8=reg11*reg8;
    reg4=reg4-1; T reg16=reg10*reg14; T reg17=reg1-reg0; T reg18=reg5*reg15; T reg19=2*reg13;
    T reg20=reg5*reg12; T reg21=2*reg9; T reg22=reg10*reg12; T reg23=0.5*reg11; reg18=reg19+reg18;
    reg20=reg19+reg20; reg16=reg21-reg16; reg22=reg21-reg22; reg19=reg4*reg15; reg21=2*reg8;
    T reg24=reg4*reg23; reg17=reg17-1; reg6=reg6*reg11; T reg25=pos_nodes[1][1]*reg20; T reg26=pos_nodes[0][0]*reg16;
    T reg27=pos_nodes[1][0]*reg18; T reg28=reg17*reg14; reg19=reg21+reg19; T reg29=pos_nodes[0][1]*reg22; T reg30=pos_nodes[1][1]*reg18;
    T reg31=pos_nodes[0][1]*reg16; T reg32=pos_nodes[0][0]*reg22; T reg33=pos_nodes[1][0]*reg20; T reg34=reg17*reg23; T reg35=2*reg6;
    reg24=reg21+reg24; reg21=pos_nodes[2][1]*reg19; T reg36=pow(reg0,2); reg31=reg30+reg31; reg5=reg13*reg5;
    reg28=reg35+reg28; reg13=pos_nodes[2][0]*reg19; reg30=pos_nodes[2][0]*reg24; reg32=reg33-reg32; reg26=reg27+reg26;
    reg10=reg9*reg10; reg29=reg25-reg29; reg9=pos_nodes[2][1]*reg24; reg34=reg35+reg34; reg25=2*reg0;
    reg27=reg5*pos_nodes[1][0]; reg33=pos_nodes[0][0]*reg10; reg35=pos_nodes[3][1]*reg34; reg9=reg29+reg9; reg29=reg5*pos_nodes[1][1];
    T reg37=2*reg1; T reg38=pos_nodes[3][0]*reg28; T reg39=pos_nodes[0][1]*reg10; reg4=reg8*reg4; reg26=reg13-reg26;
    reg36=1-reg36; reg8=reg7*reg25; reg13=pos_nodes[3][1]*reg28; reg31=reg21-reg31; reg21=pow(reg1,2);
    reg30=reg32+reg30; reg32=pos_nodes[3][0]*reg34; reg38=reg26+reg38; reg26=reg36*pos_nodes[4][0]; T reg40=pos_nodes[4][1]*reg8;
    T reg41=0.5*reg36; reg33=reg27-reg33; reg27=reg4*pos_nodes[2][0]; reg35=reg9-reg35; reg21=1-reg21;
    reg9=reg4*pos_nodes[2][1]; reg39=reg29-reg39; reg13=reg31+reg13; reg29=reg36*pos_nodes[4][1]; reg17=reg6*reg17;
    reg6=reg3*reg37; reg32=reg30-reg32; reg30=pos_nodes[4][0]*reg8; reg9=reg39+reg9; reg31=reg17*pos_nodes[3][1];
    reg39=0.5*reg21; T reg42=reg21*pos_nodes[5][0]; reg30=reg32-reg30; reg7=reg7*reg41; reg32=reg17*pos_nodes[3][0];
    reg27=reg33+reg27; reg29=reg13-reg29; reg40=reg35-reg40; reg13=reg21*pos_nodes[5][1]; reg33=pos_nodes[5][0]*reg6;
    reg26=reg38-reg26; reg35=reg11*reg25; reg38=pos_nodes[5][1]*reg6; T reg43=reg36*pos_nodes[6][1]; reg38=reg29-reg38;
    reg13=reg40+reg13; reg29=pos_nodes[6][1]*reg35; reg31=reg9+reg31; reg9=reg7*pos_nodes[4][0]; reg32=reg27+reg32;
    reg27=reg7*pos_nodes[4][1]; reg40=reg36*pos_nodes[6][0]; reg33=reg26-reg33; reg26=reg2*reg37; reg3=reg39*reg3;
    reg42=reg30+reg42; reg30=pos_nodes[6][0]*reg35; T reg44=pos_nodes[7][1]*reg26; reg43=reg38+reg43; reg38=reg3*pos_nodes[5][1];
    reg11=reg41*reg11; reg30=reg42-reg30; reg41=reg21*pos_nodes[7][0]; reg27=reg31+reg27; reg31=reg21*pos_nodes[7][1];
    reg29=reg13-reg29; reg40=reg33+reg40; reg13=pos_nodes[7][0]*reg26; reg9=reg32+reg9; reg32=reg3*pos_nodes[5][0];
    reg38=reg27+reg38; reg27=reg11*pos_nodes[6][1]; reg44=reg43-reg44; reg31=reg29-reg31; reg29=reg11*pos_nodes[6][0];
    reg32=reg9+reg32; reg13=reg40-reg13; reg41=reg30-reg41; reg39=reg2*reg39; reg2=reg13*reg31;
    reg9=reg39*pos_nodes[7][0]; reg29=reg32+reg29; reg30=reg41*reg44; reg27=reg38+reg27; reg32=reg39*pos_nodes[7][1];
    reg2=reg30-reg2; reg32=reg27+reg32; reg9=reg29+reg9; reg32=pos[1]-reg32; reg27=reg44/reg2;
    reg9=pos[0]-reg9; reg29=reg31/reg2; reg33=reg13/reg2; reg2=reg41/reg2; reg27=reg9*reg27;
    reg33=reg32*reg33; reg29=reg9*reg29; reg2=reg32*reg2; var_inter[0]+=reg27-reg33; var_inter[1]+=reg2-reg29;

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
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; reg0=reg0-1; T reg2=1+reg0; T reg3=1-reg0;
    reg1=reg1-1; T reg4=reg0-reg1; T reg5=0.25*reg2; T reg6=0.25*reg3; T reg7=1-reg1;
    T reg8=reg0+reg1; reg4=reg4-1; T reg9=reg7*reg5; T reg10=1+reg1; T reg11=reg6*reg7;
    T reg12=1+reg8; reg5=reg10*reg5; reg8=reg8-1; reg4=reg9*reg4; reg12=reg11*reg12;
    reg9=pow(reg0,2); reg0=reg1-reg0; reg1=pow(reg1,2); reg6=reg6*reg10; reg9=1-reg9;
    reg8=reg5*reg8; reg0=reg0-1; reg4=val[1]*reg4; reg12=val[0]*reg12; reg12=reg4-reg12;
    reg8=val[2]*reg8; reg1=1-reg1; reg0=reg6*reg0; reg9=0.5*reg9; reg1=0.5*reg1;
    reg7=reg7*reg9; reg0=val[3]*reg0; reg8=reg12+reg8; reg2=reg2*reg1; reg7=val[4]*reg7;
    reg0=reg8+reg0; reg7=reg0+reg7; reg2=val[5]*reg2; reg9=reg10*reg9; reg2=reg7+reg2;
    reg9=val[6]*reg9; reg1=reg3*reg1; reg9=reg2+reg9; reg1=val[7]*reg1; res=reg9+reg1;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
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

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Quad_8,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=2*var_inter[0]; T reg1=2*var_inter[1]; reg0=reg0-1; T reg2=1+reg0; T reg3=1-reg0;
    reg1=reg1-1; T reg4=reg0-reg1; T reg5=0.25*reg2; T reg6=reg0+reg1; T reg7=1-reg1;
    T reg8=0.25*reg3; T reg9=reg7*reg5; T reg10=1+reg1; reg4=reg4-1; T reg11=0.5*reg7;
    T reg12=1+reg6; T reg13=reg8*reg7; T reg14=2*reg9; T reg15=2*reg13; T reg16=reg4*reg11;
    T reg17=0.5*reg10; T reg18=reg12*reg11; T reg19=reg1-reg0; reg5=reg10*reg5; reg6=reg6-1;
    reg8=reg8*reg10; reg19=reg19-1; reg18=reg15-reg18; T reg20=reg6*reg17; T reg21=2*reg5;
    reg16=reg14+reg16; T reg22=reg19*reg17; T reg23=elem.pos(0)[1]*reg18; T reg24=elem.pos(1)[1]*reg16; reg20=reg20+reg21;
    T reg25=elem.pos(0)[0]*reg18; T reg26=elem.pos(1)[0]*reg16; T reg27=2*reg8; T reg28=2*reg0; reg16=elem.pos(1)[2]*reg16;
    reg18=elem.pos(0)[2]*reg18; T reg29=elem.pos(2)[1]*reg20; reg22=reg22+reg27; reg23=reg24-reg23; reg24=elem.pos(2)[0]*reg20;
    reg25=reg26-reg25; reg23=reg29+reg23; reg26=elem.pos(3)[1]*reg22; reg18=reg16-reg18; reg24=reg25+reg24;
    reg16=0.5*reg2; reg20=elem.pos(2)[2]*reg20; reg25=reg7*reg28; reg29=0.5*reg3; T reg30=elem.pos(3)[0]*reg22;
    T reg31=pow(reg1,2); T reg32=elem.pos(4)[1]*reg25; reg24=reg24-reg30; reg31=1-reg31; reg18=reg20+reg18;
    reg23=reg23-reg26; reg20=elem.pos(3)[2]*reg22; T reg33=reg12*reg29; T reg34=elem.pos(4)[0]*reg25; T reg35=reg4*reg16;
    reg33=reg15-reg33; reg15=reg6*reg16; reg35=reg14+reg35; reg23=reg23-reg32; reg14=elem.pos(5)[0]*reg31;
    T reg36=elem.pos(4)[2]*reg25; reg24=reg24-reg34; reg18=reg18-reg20; T reg37=elem.pos(5)[1]*reg31; T reg38=reg10*reg28;
    T reg39=elem.pos(0)[0]*reg33; T reg40=elem.pos(5)[2]*reg31; T reg41=elem.pos(0)[1]*reg33; T reg42=reg19*reg29; T reg43=elem.pos(1)[1]*reg35;
    T reg44=elem.pos(6)[0]*reg38; reg18=reg18-reg36; reg23=reg37+reg23; reg14=reg24+reg14; reg24=elem.pos(6)[1]*reg38;
    reg15=reg21+reg15; reg21=elem.pos(1)[0]*reg35; reg14=reg14-reg44; reg37=elem.pos(7)[0]*reg31; reg33=elem.pos(0)[2]*reg33;
    T reg45=elem.pos(2)[1]*reg15; reg18=reg40+reg18; reg40=elem.pos(7)[1]*reg31; T reg46=pow(reg0,2); reg41=reg43+reg41;
    reg23=reg23-reg24; reg42=reg27+reg42; reg27=elem.pos(6)[2]*reg38; reg39=reg39+reg21; T reg47=elem.pos(2)[0]*reg15;
    T reg48=elem.pos(1)[2]*reg35; T reg49=elem.pos(7)[2]*reg31; reg18=reg18-reg27; T reg50=elem.pos(3)[0]*reg42; reg45=reg45-reg41;
    T reg51=elem.pos(3)[1]*reg42; reg47=reg47-reg39; reg15=elem.pos(2)[2]*reg15; reg14=reg14-reg37; T reg52=2*reg1;
    reg23=reg23-reg40; reg46=1-reg46; reg33=reg33+reg48; T reg53=pow(reg14,2); T reg54=reg2*reg52;
    T reg55=pow(reg23,2); reg18=reg18-reg49; T reg56=elem.pos(4)[0]*reg46; T reg57=elem.pos(4)[1]*reg46; reg51=reg45+reg51;
    reg47=reg50+reg47; reg15=reg15-reg33; reg42=elem.pos(3)[2]*reg42; reg45=pow(reg18,2); reg42=reg15+reg42;
    reg53=reg55+reg53; reg47=reg47-reg56; reg15=elem.pos(5)[0]*reg54; reg51=reg51-reg57; reg50=elem.pos(5)[1]*reg54;
    reg55=elem.pos(4)[2]*reg46; reg42=reg42-reg55; reg45=reg53+reg45; reg53=elem.pos(5)[2]*reg54; T reg58=elem.pos(6)[0]*reg46;
    T reg59=reg3*reg52; reg47=reg47-reg15; reg51=reg51-reg50; T reg60=elem.pos(6)[1]*reg46; T reg61=elem.pos(7)[1]*reg59;
    T reg62=elem.pos(6)[2]*reg46; reg60=reg51+reg60; reg45=pow(reg45,0.5); reg42=reg42-reg53; reg51=elem.pos(7)[0]*reg59;
    reg47=reg58+reg47; reg58=elem.pos(7)[2]*reg59; reg60=reg60-reg61; T reg63=reg14/reg45; T reg64=reg23/reg45;
    reg42=reg62+reg42; reg47=reg47-reg51; reg62=reg64*reg60; reg45=reg18/reg45; reg42=reg42-reg58;
    T reg65=reg47*reg63; reg62=reg65+reg62; reg65=reg45*reg42; reg65=reg62+reg65; reg62=reg64*reg65;
    T reg66=reg65*reg63; reg62=reg60-reg62; reg66=reg47-reg66; T reg67=reg45*reg65; reg67=reg42-reg67;
    T reg68=pow(reg62,2); T reg69=pow(reg66,2); T reg70=pow(reg67,2); reg68=reg69+reg68; reg70=reg68+reg70;
    reg70=pow(reg70,0.5); reg62=reg62/reg70; reg66=reg66/reg70; reg70=reg67/reg70; reg60=reg60*reg62;
    reg47=reg47*reg66; reg64=reg64*reg23; reg63=reg14*reg63; reg62=reg23*reg62; reg66=reg14*reg66;
    reg42=reg42*reg70; reg60=reg47+reg60; reg64=reg63+reg64; reg45=reg45*reg18; reg70=reg18*reg70;
    reg62=reg66+reg62; reg42=reg60+reg42; reg70=reg62+reg70; reg64=reg45+reg64; reg14=reg65*reg70;
    reg18=reg64*reg42; reg14=reg18-reg14; return reg14;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Quad_8,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.45534180126147951289*elem.pos(0)[0]; T reg1=0.12200846792814621817*elem.pos(1)[0]; T reg2=0.36602540378443865451*elem.pos(0)[0]; T reg3=0.45534180126147951289*elem.pos(1)[1]; T reg4=0.36602540378443865451*elem.pos(0)[1];
    T reg5=0.12200846792814621817*elem.pos(0)[1]; T reg6=0.12200846792814621817*elem.pos(1)[1]; T reg7=0.45534180126147951289*elem.pos(1)[0]; T reg8=0.45534180126147951289*elem.pos(0)[1]; T reg9=0.12200846792814621817*elem.pos(0)[0];
    T reg10=0.36602540378443865451*elem.pos(1)[1]; T reg11=0.36602540378443865451*elem.pos(1)[0]; T reg12=0.45534180126147951289*elem.pos(2)[0]; T reg13=0.12200846792814621817*elem.pos(2)[0]; T reg14=reg11+reg9;
    T reg15=reg1+reg2; T reg16=1.3660254037844385386*elem.pos(2)[0]; T reg17=1.3660254037844385386*elem.pos(1)[1]; T reg18=1.3660254037844385386*elem.pos(2)[1]; T reg19=0.12200846792814621817*elem.pos(2)[1];
    T reg20=reg3+reg4; T reg21=0.45534180126147951289*elem.pos(2)[1]; T reg22=reg10+reg5; T reg23=1.3660254037844385386*elem.pos(1)[0]; T reg24=reg10+reg8;
    T reg25=reg4+reg6; T reg26=reg2+reg7; T reg27=reg11+reg0; T reg28=0.09622504486493763966*elem.pos(0)[0]; T reg29=0.16666666666666667632*elem.pos(1)[0];
    T reg30=reg18+reg20; T reg31=0.12200846792814621817*elem.pos(3)[1]; T reg32=0.09622504486493763966*elem.pos(1)[0]; T reg33=0.16666666666666667632*elem.pos(1)[1]; T reg34=0.09622504486493763966*elem.pos(0)[1];
    T reg35=reg0+reg23; reg23=reg9+reg23; reg25=reg18+reg25; reg9=0.45534180126147951289*elem.pos(3)[1]; reg18=reg19+reg24;
    T reg36=1.3660254037844385386*elem.pos(3)[1]; T reg37=reg16+reg26; T reg38=0.12200846792814621817*elem.pos(3)[0]; T reg39=0.16666666666666667632*elem.pos(0)[1]; T reg40=1.3660254037844385386*elem.pos(0)[1];
    T reg41=reg13+reg27; reg5=reg5+reg17; reg16=reg15+reg16; reg15=0.45534180126147951289*elem.pos(3)[0]; T reg42=reg14+reg12;
    T reg43=1.3660254037844385386*elem.pos(3)[0]; T reg44=0.16666666666666667632*elem.pos(0)[0]; T reg45=reg22+reg21; T reg46=1.3660254037844385386*elem.pos(0)[0]; T reg47=0.09622504486493763966*elem.pos(1)[1];
    reg17=reg8+reg17; T reg48=reg47+reg39; reg37=reg38+reg37; T reg49=0.66666666666666670528*elem.pos(4)[0]; T reg50=reg32+reg44;
    reg1=reg1+reg46; reg5=reg21+reg5; T reg51=0.36602540378443865451*elem.pos(3)[1]; T reg52=0.16666666666666667632*elem.pos(2)[0]; reg23=reg12+reg23;
    T reg53=reg42+reg43; reg17=reg19+reg17; reg19=0.16666666666666667632*elem.pos(2)[1]; T reg54=0.096225044864937581723*elem.pos(1)[1]; T reg55=0.48803387171258487271*elem.pos(4)[0];
    T reg56=0.36602540378443865451*elem.pos(2)[0]; reg46=reg7+reg46; T reg57=reg36+reg45; reg28=reg29+reg28; reg30=reg30+reg31;
    reg16=reg16+reg15; T reg58=0.66666666666666670528*elem.pos(4)[1]; T reg59=0.096225044864937581723*elem.pos(2)[0]; reg41=reg43+reg41; reg43=reg3+reg40;
    reg34=reg33+reg34; T reg60=0.096225044864937581723*elem.pos(1)[0]; reg25=reg25+reg9; T reg61=0.48803387171258487271*elem.pos(4)[1]; reg35=reg13+reg35;
    reg13=0.36602540378443865451*elem.pos(3)[0]; T reg62=0.096225044864937581723*elem.pos(2)[1]; reg40=reg6+reg40; reg6=0.36602540378443865451*elem.pos(2)[1]; reg36=reg18+reg36;
    reg18=0.096225044864937581723*elem.pos(3)[1]; T reg63=reg48+reg19; T reg64=reg61-reg57; T reg65=reg55-reg53; reg41=reg41-reg49;
    T reg66=1.8213672050459180516*elem.pos(4)[0]; T reg67=0.48803387171258487271*elem.pos(5)[0]; reg44=reg60-reg44; reg35=reg35+reg13; reg60=0.48803387171258487271*elem.pos(5)[1];
    reg36=reg36-reg58; T reg68=0.66666666666666670528*elem.pos(5)[1]; reg25=reg25-reg61; T reg69=0.096225044864937581723*elem.pos(0)[0]; T reg70=1.8213672050459180516*elem.pos(5)[1];
    reg30=reg30-reg58; T reg71=0.096225044864937581723*elem.pos(0)[1]; T reg72=0.66666666666666670528*elem.pos(5)[0]; reg16=reg16-reg55; T reg73=reg46+reg56;
    reg40=reg6+reg40; reg59=reg59-reg28; T reg74=0.16666666666666667632*elem.pos(3)[0]; T reg75=reg6+reg43; reg1=reg56+reg1;
    reg62=reg62-reg34; T reg76=0.16666666666666667632*elem.pos(3)[1]; T reg77=reg5+reg51; T reg78=reg50+reg52; reg37=reg37-reg49;
    T reg79=1.8213672050459180516*elem.pos(5)[0]; T reg80=reg13+reg23; T reg81=0.096225044864937581723*elem.pos(3)[0]; reg17=reg51+reg17; reg39=reg54-reg39;
    reg54=1.8213672050459180516*elem.pos(4)[1]; T reg82=reg15+reg1; T reg83=reg58+reg77; T reg84=0.09622504486493763966*elem.pos(3)[0]; reg31=reg31+reg75;
    reg35=reg35-reg66; T reg85=reg9+reg40; T reg86=0.09622504486493763966*elem.pos(2)[1]; reg38=reg38+reg73; reg44=reg44-reg52;
    reg17=reg17-reg54; T reg87=reg49+reg80; T reg88=reg71-reg33; T reg89=0.14088324360345809781*elem.pos(4)[1]; T reg90=0.09622504486493763966*elem.pos(2)[0];
    T reg91=reg69-reg29; reg62=reg62-reg76; reg65=reg72+reg65; reg81=reg81-reg78; reg39=reg39-reg19;
    T reg92=0.66666666666666670528*elem.pos(6)[0]; reg37=reg37-reg79; T reg93=1.8213672050459180516*elem.pos(6)[1]; reg25=reg25+reg68; T reg94=0.09622504486493763966*elem.pos(3)[1];
    T reg95=0.66666666666666670528*elem.pos(6)[1]; reg30=reg30-reg70; T reg96=1.8213672050459180516*elem.pos(6)[0]; reg16=reg16+reg72; reg59=reg59-reg74;
    T reg97=0.14088324360345809781*elem.pos(4)[0]; reg36=reg36-reg60; reg18=reg18-reg63; reg41=reg41-reg67; reg64=reg68+reg64;
    reg62=reg62+reg89; T reg98=0.48803387171258487271*elem.pos(7)[0]; reg37=reg37+reg92; reg18=reg89+reg18; reg41=reg92+reg41;
    reg89=reg79-reg87; T reg99=0.52578342306320860749*elem.pos(5)[0]; T reg100=0.66666666666666670528*elem.pos(7)[1]; reg25=reg25-reg93; reg64=reg93+reg64;
    reg88=reg88-reg86; T reg101=0.48803387171258487271*elem.pos(7)[1]; reg30=reg30+reg95; reg91=reg91-reg90; reg44=reg44-reg84;
    T reg102=reg66-reg38; T reg103=0.66666666666666670528*elem.pos(7)[0]; reg16=reg16-reg96; T reg104=0.52578342306320860749*elem.pos(4)[1]; reg39=reg39-reg94;
    reg65=reg96+reg65; reg35=reg72+reg35; T reg105=0.48803387171258487271*elem.pos(6)[0]; reg49=reg49+reg82; reg36=reg95+reg36;
    T reg106=0.14088324360345809781*elem.pos(5)[1]; T reg107=reg54-reg31; T reg108=0.14088324360345809781*elem.pos(5)[0]; T reg109=reg70-reg83; T reg110=0.52578342306320860749*elem.pos(4)[0];
    reg59=reg97+reg59; T reg111=0.48803387171258487271*elem.pos(6)[1]; reg17=reg68+reg17; reg58=reg58+reg85; T reg112=1.8213672050459180516*elem.pos(7)[1];
    reg81=reg97+reg81; reg97=0.52578342306320860749*elem.pos(5)[1]; T reg113=1.8213672050459180516*elem.pos(7)[0]; reg107=reg68+reg107; reg68=reg67-reg49;
    reg39=reg39+reg104; reg102=reg72+reg102; reg88=reg88-reg76; reg72=reg60-reg58; reg59=reg59+reg99;
    reg41=reg41-reg113; T reg114=0.52578342306320860749*elem.pos(6)[0]; reg81=reg81+reg108; reg109=reg95+reg109; reg62=reg62+reg97;
    reg18=reg18+reg106; T reg115=0.52578342306320860749*elem.pos(6)[1]; reg35=reg35-reg105; reg36=reg36-reg112; reg37=reg37-reg98;
    reg17=reg17-reg111; reg65=reg65-reg103; reg89=reg92+reg89; reg25=reg25-reg100; reg30=reg30-reg101;
    reg91=reg91-reg74; reg44=reg110+reg44; reg16=reg16-reg103; reg64=reg64-reg100; T reg116=0.14088324360345809781*elem.pos(6)[1];
    reg18=reg115+reg18; reg39=reg97+reg39; reg68=reg92+reg68; reg88=reg104+reg88; reg92=0.52578342306320860749*elem.pos(7)[1];
    reg115=reg62+reg115; reg62=0.14088324360345809781*elem.pos(7)[1]; reg97=0.52578342306320860749*elem.pos(7)[0]; reg81=reg114+reg81; reg44=reg99+reg44;
    reg91=reg110+reg91; reg89=reg98+reg89; reg17=reg17-reg100; reg109=reg101+reg109; reg37=reg25*reg37;
    reg30=reg16*reg30; reg102=reg105+reg102; reg35=reg35-reg103; reg72=reg95+reg72; reg16=0.14088324360345809781*elem.pos(7)[0];
    reg114=reg59+reg114; reg36=reg65*reg36; reg41=reg64*reg41; reg107=reg111+reg107; reg25=0.14088324360345809781*elem.pos(6)[0];
    reg81=reg81+reg97; reg44=reg44+reg25; reg115=reg115+reg62; reg109=reg35*reg109; reg89=reg17*reg89;
    reg18=reg18+reg92; reg91=reg108+reg91; reg39=reg39+reg116; reg41=reg36-reg41; reg37=reg30-reg37;
    reg103=reg102-reg103; reg114=reg114+reg16; reg72=reg112+reg72; reg88=reg106+reg88; reg68=reg113+reg68;
    reg100=reg107-reg100; reg81=reg81*reg41; reg18=reg41*reg18; reg114=reg114*reg37; reg72=reg103*reg72;
    reg68=reg100*reg68; reg115=reg37*reg115; reg44=reg16+reg44; reg89=reg109-reg89; reg88=reg116+reg88;
    reg91=reg25+reg91; reg39=reg62+reg39; reg37=0.25*reg37; reg68=reg72-reg68; reg41=0.25*reg41;
    reg91=reg97+reg91; reg39=reg89*reg39; reg18=0.25*reg18; reg88=reg92+reg88; reg114=0.25*reg114;
    reg44=reg44*reg89; reg115=0.25*reg115; reg81=0.25*reg81; reg39=0.25*reg39; reg88=reg68*reg88;
    reg81=reg114+reg81; reg44=0.25*reg44; reg91=reg91*reg68; reg41=reg37+reg41; reg89=0.25*reg89;
    reg18=reg115+reg18; reg68=0.25*reg68; reg89=reg41+reg89; reg39=reg18+reg39; reg91=0.25*reg91;
    reg44=reg81+reg44; reg88=0.25*reg88; reg68=reg89+reg68; reg91=reg44+reg91; reg88=reg39+reg88;
    res[0]=reg91/reg68; res[1]=reg88/reg68;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Quad_8,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.36602540378443865451*elem.pos(1)[1]; T reg1=0.12200846792814621817*elem.pos(0)[1]; T reg2=0.12200846792814621817*elem.pos(1)[0]; T reg3=0.36602540378443865451*elem.pos(0)[0]; T reg4=0.36602540378443865451*elem.pos(0)[1];
    T reg5=0.36602540378443865451*elem.pos(1)[0]; T reg6=0.12200846792814621817*elem.pos(0)[0]; T reg7=0.12200846792814621817*elem.pos(1)[1]; T reg8=1.3660254037844385386*elem.pos(2)[0]; T reg9=1.3660254037844385386*elem.pos(1)[0];
    T reg10=0.12200846792814621817*elem.pos(0)[2]; T reg11=1.3660254037844385386*elem.pos(2)[1]; T reg12=reg2+reg3; T reg13=reg7+reg4; T reg14=0.45534180126147951289*elem.pos(0)[1];
    T reg15=0.36602540378443865451*elem.pos(1)[2]; T reg16=1.3660254037844385386*elem.pos(1)[1]; T reg17=0.12200846792814621817*elem.pos(1)[2]; T reg18=0.36602540378443865451*elem.pos(0)[2]; T reg19=reg0+reg1;
    T reg20=0.45534180126147951289*elem.pos(0)[0]; T reg21=0.45534180126147951289*elem.pos(2)[0]; T reg22=reg5+reg6; T reg23=0.45534180126147951289*elem.pos(2)[1]; T reg24=reg17+reg18;
    T reg25=0.45534180126147951289*elem.pos(0)[2]; T reg26=0.45534180126147951289*elem.pos(1)[1]; reg13=reg11+reg13; T reg27=reg23+reg19; T reg28=0.12200846792814621817*elem.pos(2)[1];
    T reg29=0.45534180126147951289*elem.pos(3)[1]; T reg30=0.45534180126147951289*elem.pos(3)[0]; reg12=reg8+reg12; T reg31=reg21+reg22; T reg32=1.3660254037844385386*elem.pos(1)[2];
    T reg33=1.3660254037844385386*elem.pos(3)[0]; T reg34=0.12200846792814621817*elem.pos(2)[0]; T reg35=1.3660254037844385386*elem.pos(3)[1]; T reg36=reg20+reg9; T reg37=1.3660254037844385386*elem.pos(0)[0];
    T reg38=0.45534180126147951289*elem.pos(1)[0]; T reg39=reg15+reg10; T reg40=1.3660254037844385386*elem.pos(2)[2]; T reg41=1.3660254037844385386*elem.pos(0)[1]; T reg42=0.45534180126147951289*elem.pos(2)[2];
    T reg43=reg14+reg16; reg24=reg40+reg24; T reg44=0.45534180126147951289*elem.pos(3)[2]; reg43=reg28+reg43; reg13=reg13+reg29;
    T reg45=reg25+reg32; T reg46=0.36602540378443865451*elem.pos(3)[0]; reg36=reg34+reg36; T reg47=0.48803387171258487271*elem.pos(4)[1]; T reg48=0.36602540378443865451*elem.pos(3)[1];
    T reg49=1.3660254037844385386*elem.pos(0)[2]; T reg50=reg31+reg33; T reg51=reg27+reg35; T reg52=reg26+reg41; T reg53=0.36602540378443865451*elem.pos(2)[1];
    T reg54=reg38+reg37; T reg55=0.36602540378443865451*elem.pos(2)[0]; T reg56=reg42+reg39; T reg57=1.3660254037844385386*elem.pos(3)[2]; T reg58=0.45534180126147951289*elem.pos(1)[2];
    reg12=reg12+reg30; T reg59=0.48803387171258487271*elem.pos(4)[0]; T reg60=0.12200846792814621817*elem.pos(2)[2]; T reg61=0.12200846792814621817*elem.pos(3)[0]; T reg62=1.8213672050459180516*elem.pos(4)[0];
    reg36=reg36+reg46; T reg63=reg47-reg51; T reg64=reg56+reg57; T reg65=reg59-reg50; reg43=reg43+reg48;
    T reg66=1.8213672050459180516*elem.pos(4)[1]; T reg67=0.12200846792814621817*elem.pos(3)[1]; T reg68=reg53+reg52; T reg69=0.36602540378443865451*elem.pos(3)[2]; reg45=reg60+reg45;
    reg24=reg24+reg44; T reg70=0.48803387171258487271*elem.pos(4)[2]; reg12=reg12-reg59; T reg71=0.36602540378443865451*elem.pos(2)[2]; T reg72=0.66666666666666670528*elem.pos(5)[0];
    T reg73=reg58+reg49; T reg74=reg55+reg54; T reg75=0.66666666666666670528*elem.pos(5)[1]; reg13=reg13-reg47; T reg76=1.8213672050459180516*elem.pos(4)[2];
    T reg77=reg67+reg68; reg63=reg75+reg63; T reg78=1.8213672050459180516*elem.pos(6)[0]; reg12=reg72+reg12; T reg79=reg61+reg74;
    T reg80=0.12200846792814621817*elem.pos(3)[2]; T reg81=reg70-reg64; T reg82=reg71+reg73; reg43=reg43-reg66; T reg83=0.66666666666666670528*elem.pos(5)[2];
    reg24=reg24-reg70; reg65=reg72+reg65; reg45=reg45+reg69; reg36=reg36-reg62; T reg84=1.8213672050459180516*elem.pos(6)[1];
    reg13=reg13+reg75; reg65=reg78+reg65; reg63=reg84+reg63; T reg85=reg66-reg77; T reg86=reg62-reg79;
    T reg87=reg80+reg82; reg36=reg72+reg36; T reg88=0.66666666666666670528*elem.pos(7)[1]; reg13=reg13-reg84; T reg89=reg3+reg38;
    reg45=reg45-reg76; T reg90=0.66666666666666670528*elem.pos(7)[0]; T reg91=reg4+reg26; T reg92=0.48803387171258487271*elem.pos(6)[0]; reg12=reg12-reg78;
    T reg93=reg0+reg14; reg24=reg24+reg83; T reg94=reg5+reg20; reg43=reg75+reg43; reg81=reg83+reg81;
    T reg95=0.48803387171258487271*elem.pos(6)[1]; T reg96=1.8213672050459180516*elem.pos(6)[2]; reg36=reg36-reg92; reg85=reg75+reg85; reg43=reg43-reg95;
    reg75=reg76-reg87; reg65=reg65-reg90; T reg97=reg15+reg25; reg28=reg28+reg93; reg63=reg63-reg88;
    reg86=reg72+reg86; reg34=reg34+reg94; reg81=reg96+reg81; reg16=reg1+reg16; reg9=reg6+reg9;
    reg1=0.48803387171258487271*elem.pos(6)[2]; reg45=reg83+reg45; reg6=reg18+reg58; reg72=0.66666666666666670528*elem.pos(7)[2]; reg24=reg24-reg96;
    reg13=reg13-reg88; reg12=reg12-reg90; reg11=reg11+reg91; reg8=reg8+reg89; reg32=reg10+reg32;
    reg10=0.66666666666666670528*elem.pos(4)[0]; reg40=reg40+reg6; reg37=reg2+reg37; reg36=reg36-reg90; reg81=reg81-reg72;
    reg86=reg92+reg86; reg2=pow(reg65,2); T reg98=pow(reg63,2); reg60=reg60+reg97; reg41=reg7+reg41;
    reg61=reg8+reg61; reg85=reg95+reg85; reg7=0.66666666666666670528*elem.pos(4)[1]; reg67=reg11+reg67; reg45=reg45-reg1;
    reg8=pow(reg12,2); reg11=pow(reg13,2); reg9=reg21+reg9; reg34=reg33+reg34; reg43=reg43-reg88;
    reg28=reg35+reg28; reg16=reg23+reg16; reg24=reg24-reg72; reg75=reg83+reg75; reg33=0.66666666666666670528*elem.pos(4)[2];
    reg35=reg48+reg16; reg88=reg85-reg88; reg98=reg2+reg98; reg80=reg40+reg80; reg2=pow(reg81,2);
    reg40=0.48803387171258487271*elem.pos(5)[1]; reg28=reg28-reg7; reg41=reg53+reg41; reg75=reg1+reg75; reg83=1.8213672050459180516*elem.pos(5)[1];
    reg34=reg34-reg10; reg85=0.48803387171258487271*elem.pos(5)[0]; reg67=reg67-reg7; reg60=reg57+reg60; reg57=pow(reg24,2);
    reg49=reg17+reg49; reg32=reg42+reg32; reg37=reg55+reg37; reg90=reg86-reg90; reg17=pow(reg43,2);
    reg86=pow(reg36,2); reg61=reg61-reg10; reg11=reg8+reg11; reg8=1.8213672050459180516*elem.pos(5)[0]; reg45=reg45-reg72;
    T reg99=reg46+reg9; reg60=reg60-reg33; reg17=reg86+reg17; reg34=reg34-reg85; reg67=reg67-reg83;
    reg86=0.66666666666666670528*elem.pos(6)[1]; T reg100=reg69+reg32; reg72=reg75-reg72; reg75=pow(reg45,2); T reg101=0.48803387171258487271*elem.pos(5)[2];
    reg57=reg11+reg57; reg11=reg30+reg37; T reg102=reg10+reg99; T reg103=reg7+reg35; T reg104=0.66666666666666670528*elem.pos(6)[0];
    reg61=reg61-reg8; T reg105=1.8213672050459180516*elem.pos(5)[2]; reg80=reg80-reg33; T reg106=reg29+reg41; T reg107=pow(reg90,2);
    T reg108=pow(reg88,2); reg28=reg28-reg40; reg2=reg98+reg2; reg49=reg71+reg49; reg98=1.8213672050459180516*elem.pos(7)[1];
    reg28=reg86+reg28; T reg109=0.48803387171258487271*elem.pos(7)[0]; reg60=reg60-reg101; reg75=reg17+reg75; reg17=reg33+reg100;
    reg57=pow(reg57,0.5); T reg110=reg44+reg49; T reg111=reg83-reg103; reg7=reg7+reg106; reg61=reg61+reg104;
    T reg112=0.66666666666666670528*elem.pos(6)[2]; reg80=reg80-reg105; reg108=reg107+reg108; reg107=reg8-reg102; T reg113=0.48803387171258487271*elem.pos(7)[1];
    reg2=pow(reg2,0.5); reg10=reg10+reg11; reg67=reg67+reg86; reg34=reg104+reg34; T reg114=1.8213672050459180516*elem.pos(7)[0];
    T reg115=pow(reg72,2); T reg116=reg85-reg10; reg111=reg86+reg111; reg115=reg108+reg115; reg107=reg104+reg107;
    reg108=reg13/reg57; T reg117=reg12/reg57; reg75=pow(reg75,0.5); T reg118=reg40-reg7; reg28=reg28-reg98;
    reg33=reg33+reg110; reg34=reg34-reg114; T reg119=0.48803387171258487271*elem.pos(7)[2]; T reg120=reg105-reg17; reg80=reg80+reg112;
    reg67=reg67-reg113; T reg121=reg65/reg2; T reg122=1.8213672050459180516*elem.pos(7)[2]; reg60=reg112+reg60; reg61=reg61-reg109;
    T reg123=reg63/reg2; T reg124=reg121*reg34; reg116=reg104+reg116; reg2=reg81/reg2; reg107=reg109+reg107;
    reg104=reg108*reg67; reg80=reg80-reg119; T reg125=reg101-reg33; reg118=reg86+reg118; reg57=reg24/reg57;
    reg86=reg36/reg75; T reg126=reg43/reg75; reg120=reg112+reg120; reg111=reg113+reg111; reg60=reg60-reg122;
    T reg127=reg117*reg61; reg115=pow(reg115,0.5); T reg128=reg123*reg28; T reg129=reg86*reg107; reg128=reg124+reg128;
    reg116=reg114+reg116; reg124=reg2*reg60; T reg130=reg90/reg115; reg104=reg127+reg104; reg75=reg45/reg75;
    reg127=reg88/reg115; T reg131=reg57*reg80; T reg132=reg126*reg111; reg118=reg98+reg118; reg125=reg112+reg125;
    reg120=reg119+reg120; reg112=reg127*reg118; reg132=reg129+reg132; reg129=reg75*reg120; reg125=reg122+reg125;
    reg131=reg104+reg131; reg124=reg128+reg124; reg115=reg72/reg115; reg104=reg130*reg116; reg112=reg104+reg112;
    reg129=reg132+reg129; reg104=reg115*reg125; reg128=reg108*reg131; reg132=reg121*reg124; T reg133=reg117*reg131;
    T reg134=reg123*reg124; T reg135=reg126*reg129; T reg136=reg57*reg131; reg128=reg67-reg128; reg133=reg61-reg133;
    reg132=reg34-reg132; T reg137=reg86*reg129; reg104=reg112+reg104; reg112=reg2*reg124; reg134=reg28-reg134;
    reg135=reg111-reg135; reg137=reg107-reg137; T reg138=pow(reg132,2); T reg139=pow(reg134,2); T reg140=reg127*reg104;
    T reg141=reg130*reg104; reg112=reg60-reg112; T reg142=reg75*reg129; T reg143=pow(reg133,2); T reg144=pow(reg128,2);
    reg136=reg80-reg136; T reg145=pow(reg137,2); reg142=reg120-reg142; T reg146=pow(reg135,2); reg140=reg118-reg140;
    reg141=reg116-reg141; T reg147=reg115*reg104; T reg148=pow(reg136,2); reg144=reg143+reg144; reg139=reg138+reg139;
    reg138=pow(reg112,2); reg143=0.16666666666666667632*elem.pos(0)[1]; T reg149=0.09622504486493763966*elem.pos(1)[1]; reg138=reg139+reg138; reg148=reg144+reg148;
    reg139=0.16666666666666667632*elem.pos(0)[0]; reg144=0.09622504486493763966*elem.pos(1)[0]; T reg150=pow(reg141,2); T reg151=pow(reg140,2); T reg152=0.16666666666666667632*elem.pos(1)[2];
    reg147=reg125-reg147; T reg153=0.16666666666666667632*elem.pos(0)[2]; T reg154=0.09622504486493763966*elem.pos(1)[2]; T reg155=0.09622504486493763966*elem.pos(0)[2]; reg146=reg145+reg146;
    reg145=0.16666666666666667632*elem.pos(1)[0]; T reg156=0.09622504486493763966*elem.pos(0)[0]; T reg157=pow(reg142,2); T reg158=0.09622504486493763966*elem.pos(0)[1]; T reg159=0.16666666666666667632*elem.pos(1)[1];
    T reg160=pow(reg147,2); reg158=reg159+reg158; T reg161=0.096225044864937581723*elem.pos(2)[1]; reg151=reg150+reg151; reg150=0.16666666666666667632*elem.pos(2)[1];
    T reg162=reg149+reg143; T reg163=0.096225044864937581723*elem.pos(2)[0]; reg156=reg145+reg156; T reg164=0.096225044864937581723*elem.pos(1)[1]; reg157=reg146+reg157;
    reg146=0.096225044864937581723*elem.pos(2)[2]; reg155=reg152+reg155; T reg165=0.096225044864937581723*elem.pos(1)[0]; T reg166=0.16666666666666667632*elem.pos(2)[2]; T reg167=reg154+reg153;
    T reg168=reg144+reg139; T reg169=0.16666666666666667632*elem.pos(2)[0]; reg148=pow(reg148,0.5); reg138=pow(reg138,0.5); T reg170=0.096225044864937581723*elem.pos(1)[2];
    reg143=reg164-reg143; reg164=0.096225044864937581723*elem.pos(0)[0]; reg153=reg170-reg153; reg128=reg128/reg148; reg133=reg133/reg148;
    reg170=0.096225044864937581723*elem.pos(3)[1]; reg132=reg132/reg138; T reg171=0.16666666666666667632*elem.pos(3)[0]; reg163=reg163-reg156; reg134=reg134/reg138;
    T reg172=0.096225044864937581723*elem.pos(3)[2]; T reg173=reg150+reg162; T reg174=reg166+reg167; reg139=reg165-reg139; reg146=reg146-reg155;
    reg165=0.16666666666666667632*elem.pos(3)[2]; reg157=pow(reg157,0.5); reg161=reg161-reg158; T reg175=0.16666666666666667632*elem.pos(3)[1]; reg160=reg151+reg160;
    reg151=0.096225044864937581723*elem.pos(0)[2]; T reg176=0.096225044864937581723*elem.pos(0)[1]; T reg177=0.096225044864937581723*elem.pos(3)[0]; T reg178=reg169+reg168; T reg179=0.09622504486493763966*elem.pos(3)[2];
    reg153=reg153-reg166; reg67=reg67*reg128; reg148=reg136/reg148; reg177=reg177-reg178; reg161=reg161-reg175;
    reg172=reg172-reg174; reg136=reg63*reg134; T reg180=reg65*reg132; reg138=reg112/reg138; reg134=reg28*reg134;
    reg28=0.14088324360345809781*elem.pos(4)[1]; reg160=pow(reg160,0.5); reg61=reg61*reg133; reg132=reg34*reg132; reg133=reg12*reg133;
    reg128=reg13*reg128; reg34=reg151-reg152; reg123=reg63*reg123; reg121=reg65*reg121; reg63=0.09622504486493763966*elem.pos(2)[2];
    reg137=reg137/reg157; reg135=reg135/reg157; reg146=reg146-reg165; reg65=reg176-reg159; reg112=0.09622504486493763966*elem.pos(2)[1];
    T reg181=0.09622504486493763966*elem.pos(3)[1]; reg143=reg143-reg150; T reg182=0.09622504486493763966*elem.pos(2)[0]; T reg183=reg164-reg145; T reg184=0.14088324360345809781*elem.pos(4)[2];
    reg170=reg170-reg173; T reg185=0.14088324360345809781*elem.pos(4)[0]; reg163=reg163-reg171; reg117=reg12*reg117; reg108=reg13*reg108;
    reg139=reg139-reg169; reg12=0.09622504486493763966*elem.pos(3)[0]; reg143=reg143-reg181; reg13=0.52578342306320860749*elem.pos(4)[1]; T reg186=0.52578342306320860749*elem.pos(4)[2];
    T reg187=reg43*reg135; T reg188=reg36*reg137; T reg189=0.52578342306320860749*elem.pos(4)[0]; T reg190=reg24*reg148; reg128=reg133+reg128;
    reg65=reg65-reg112; reg34=reg34-reg63; reg157=reg142/reg157; reg139=reg139-reg12; reg141=reg141/reg160;
    reg133=0.52578342306320860749*elem.pos(5)[1]; reg140=reg140/reg160; reg161=reg161+reg28; reg135=reg111*reg135; reg137=reg107*reg137;
    reg148=reg80*reg148; reg86=reg36*reg86; reg67=reg61+reg67; reg126=reg43*reg126; reg60=reg60*reg138;
    reg108=reg117+reg108; reg134=reg132+reg134; reg36=0.14088324360345809781*elem.pos(5)[2]; reg57=reg24*reg57; reg146=reg146+reg184;
    reg163=reg163+reg185; reg24=0.52578342306320860749*elem.pos(5)[0]; reg2=reg81*reg2; reg123=reg121+reg123; reg136=reg180+reg136;
    reg170=reg28+reg170; reg177=reg185+reg177; reg28=0.14088324360345809781*elem.pos(5)[0]; reg153=reg153-reg179; reg43=0.52578342306320860749*elem.pos(5)[2];
    reg172=reg184+reg172; reg183=reg183-reg182; reg138=reg81*reg138; reg61=0.14088324360345809781*elem.pos(5)[1]; reg34=reg34-reg165;
    reg153=reg153+reg186; reg146=reg146+reg43; reg80=0.52578342306320860749*elem.pos(6)[2]; reg143=reg143+reg13; reg172=reg172+reg36;
    reg161=reg161+reg133; reg81=0.52578342306320860749*elem.pos(6)[1]; reg170=reg170+reg61; reg65=reg65-reg175; reg107=reg90*reg141;
    reg139=reg139+reg189; reg160=reg147/reg160; reg118=reg118*reg140; reg141=reg116*reg141; reg57=reg108+reg57;
    reg126=reg86+reg126; reg75=reg45*reg75; reg127=reg88*reg127; reg130=reg90*reg130; reg86=0.52578342306320860749*elem.pos(6)[0];
    reg135=reg137+reg135; reg163=reg163+reg24; reg120=reg120*reg157; reg187=reg188+reg187; reg157=reg45*reg157;
    reg183=reg183-reg171; reg177=reg177+reg28; reg2=reg123+reg2; reg190=reg128+reg190; reg148=reg67+reg148;
    reg60=reg134+reg60; reg138=reg136+reg138; reg140=reg88*reg140; reg45=0.14088324360345809781*elem.pos(6)[1]; reg143=reg133+reg143;
    reg157=reg187+reg157; reg148=reg57*reg148; reg120=reg135+reg120; reg65=reg13+reg65; reg34=reg186+reg34;
    reg190=reg131*reg190; reg13=0.14088324360345809781*elem.pos(6)[2]; reg153=reg43+reg153; reg177=reg86+reg177; reg86=reg163+reg86;
    reg75=reg126+reg75; reg43=0.52578342306320860749*elem.pos(7)[0]; reg57=0.14088324360345809781*elem.pos(7)[0]; reg67=0.52578342306320860749*elem.pos(7)[2]; reg88=0.14088324360345809781*elem.pos(6)[0];
    reg146=reg146+reg80; reg172=reg80+reg172; reg80=0.14088324360345809781*elem.pos(7)[2]; reg60=reg2*reg60; reg139=reg24+reg139;
    reg138=reg124*reg138; reg118=reg141+reg118; reg183=reg189+reg183; reg170=reg81+reg170; reg2=reg72*reg160;
    reg115=reg72*reg115; reg24=0.52578342306320860749*elem.pos(7)[1]; reg81=reg161+reg81; reg160=reg125*reg160; reg127=reg130+reg127;
    reg140=reg107+reg140; reg72=0.14088324360345809781*elem.pos(7)[1]; reg153=reg153+reg13; reg139=reg139+reg88; reg2=reg140+reg2;
    reg172=reg172+reg67; reg86=reg86+reg57; reg65=reg61+reg65; reg115=reg127+reg115; reg81=reg81+reg72;
    reg183=reg28+reg183; reg120=reg75*reg120; reg34=reg36+reg34; reg146=reg146+reg80; reg143=reg143+reg45;
    reg170=reg170+reg24; reg157=reg129*reg157; reg160=reg118+reg160; reg190=reg148-reg190; reg138=reg60-reg138;
    reg177=reg177+reg43; reg146=reg190*reg146; reg160=reg115*reg160; reg139=reg57+reg139; reg177=reg177*reg138;
    reg81=reg190*reg81; reg153=reg80+reg153; reg2=reg104*reg2; reg65=reg45+reg65; reg172=reg138*reg172;
    reg183=reg88+reg183; reg143=reg72+reg143; reg170=reg138*reg170; reg157=reg120-reg157; reg86=reg86*reg190;
    reg34=reg13+reg34; reg153=reg157*reg153; reg172=0.25*reg172; reg86=0.25*reg86; reg138=0.25*reg138;
    reg177=0.25*reg177; reg146=0.25*reg146; reg81=0.25*reg81; reg190=0.25*reg190; reg2=reg160-reg2;
    reg65=reg24+reg65; reg183=reg43+reg183; reg143=reg157*reg143; reg139=reg139*reg157; reg34=reg67+reg34;
    reg170=0.25*reg170; reg153=0.25*reg153; reg183=reg183*reg2; reg34=reg2*reg34; reg170=reg81+reg170;
    reg139=0.25*reg139; reg143=0.25*reg143; reg65=reg2*reg65; reg177=reg86+reg177; reg138=reg190+reg138;
    reg157=0.25*reg157; reg172=reg146+reg172; reg34=0.25*reg34; reg139=reg177+reg139; reg157=reg138+reg157;
    reg143=reg170+reg143; reg65=0.25*reg65; reg153=reg172+reg153; reg2=0.25*reg2; reg183=0.25*reg183;
    reg65=reg143+reg65; reg183=reg139+reg183; reg2=reg157+reg2; reg34=reg153+reg34; res[2]=reg34/reg2;
    res[1]=reg65/reg2; res[0]=reg183/reg2;

    return res;
}
}
#endif // LMT_QUAD_8
