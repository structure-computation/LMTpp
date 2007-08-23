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
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; reg1=reg1-1; T reg2=1-reg0;
    T reg3=1+reg0; T reg4=reg0+reg1; T reg5=reg0-reg1; T reg6=0.25*reg2; T reg7=1-reg1;
    T reg8=0.25*reg3; T reg9=0.5*reg7; reg5=reg5-1; T reg10=reg7*reg8; T reg11=1+reg4;
    T reg12=reg6*reg7; T reg13=1+reg1; T reg14=0.5*reg3; T reg15=0.5*reg2; T reg16=2*reg10;
    T reg17=reg9*reg5; T reg18=2*reg12; T reg19=0.5*reg13; T reg20=reg11*reg9; T reg21=reg14*reg5;
    reg4=reg4-1; reg8=reg13*reg8; T reg22=reg11*reg15; T reg23=reg1-reg0; T reg24=reg14*reg4;
    reg20=reg18-reg20; reg5=reg10*reg5; reg21=reg16+reg21; reg17=reg16+reg17; reg22=reg18-reg22;
    reg11=reg12*reg11; reg10=reg19*reg4; reg12=2*reg8; reg16=pow(reg0,2); reg23=reg23-1;
    reg6=reg6*reg13; reg18=pos_nodes[0][1]*reg11; reg24=reg12+reg24; T reg25=reg5*pos_nodes[1][1]; T reg26=pos_nodes[0][1]*reg22;
    T reg27=reg21*pos_nodes[1][1]; T reg28=pos_nodes[0][1]*reg20; T reg29=reg17*pos_nodes[1][1]; T reg30=pos_nodes[0][0]*reg11; T reg31=pos_nodes[1][0]*reg5;
    T reg32=pos_nodes[0][0]*reg22; T reg33=pos_nodes[1][0]*reg21; T reg34=reg23*reg15; reg4=reg8*reg4; reg8=reg23*reg19;
    T reg35=2*reg6; reg10=reg12+reg10; reg12=pos_nodes[1][0]*reg17; T reg36=pos_nodes[0][0]*reg20; T reg37=pow(reg1,2);
    reg16=1-reg16; reg23=reg6*reg23; reg6=0.5*reg16; reg34=reg35+reg34; T reg38=reg24*pos_nodes[2][0];
    reg32=reg33+reg32; reg37=1-reg37; reg33=reg24*pos_nodes[2][1]; reg30=reg31-reg30; reg26=reg27+reg26;
    reg27=reg4*pos_nodes[2][0]; reg28=reg29-reg28; reg29=reg4*pos_nodes[2][1]; reg31=reg10*pos_nodes[2][1]; reg36=reg12-reg36;
    reg12=reg10*pos_nodes[2][0]; reg18=reg25-reg18; reg8=reg35+reg8; reg25=2*reg0; reg26=reg33-reg26;
    reg33=reg8*pos_nodes[3][1]; reg30=reg27+reg30; reg27=reg23*pos_nodes[3][0]; reg35=pos_nodes[3][0]*reg34; reg32=reg38-reg32;
    reg28=reg31+reg28; reg31=2*reg1; reg38=pos_nodes[3][1]*reg34; T reg39=reg7*reg25; reg7=reg7*reg6;
    T reg40=reg8*pos_nodes[3][0]; reg36=reg12+reg36; reg18=reg29+reg18; reg12=reg23*pos_nodes[3][1]; reg29=0.5*reg37;
    T reg41=reg7*pos_nodes[4][1]; T reg42=reg39*pos_nodes[4][1]; reg12=reg18+reg12; reg33=reg28-reg33; reg27=reg30+reg27;
    reg18=reg7*pos_nodes[4][0]; reg28=reg16*pos_nodes[4][1]; reg30=reg16*pos_nodes[4][0]; reg35=reg32+reg35; reg32=reg31*reg3;
    T reg43=reg39*pos_nodes[4][0]; reg3=reg29*reg3; reg38=reg26+reg38; reg40=reg36-reg40; reg42=reg33-reg42;
    reg26=pos_nodes[5][1]*reg32; reg28=reg38-reg28; reg33=pos_nodes[5][0]*reg37; reg43=reg40-reg43; reg36=pos_nodes[5][1]*reg37;
    reg38=reg25*reg13; reg13=reg6*reg13; reg6=pos_nodes[5][0]*reg3; reg18=reg27+reg18; reg30=reg35-reg30;
    reg27=pos_nodes[5][0]*reg32; reg35=pos_nodes[5][1]*reg3; reg41=reg12+reg41; reg12=pos_nodes[6][1]*reg38; reg26=reg28-reg26;
    reg28=pos_nodes[6][1]*reg16; reg42=reg36+reg42; reg36=pos_nodes[6][0]*reg13; reg6=reg18+reg6; reg35=reg41+reg35;
    reg18=pos_nodes[6][0]*reg16; reg27=reg30-reg27; reg30=reg31*reg2; reg2=reg29*reg2; reg33=reg43+reg33;
    reg29=pos_nodes[6][0]*reg38; reg40=pos_nodes[6][1]*reg13; reg41=pos_nodes[7][1]*reg30; reg40=reg35+reg40; reg35=pos_nodes[7][1]*reg2;
    reg28=reg26+reg28; reg26=pos_nodes[7][0]*reg37; reg43=pos_nodes[7][1]*reg37; reg12=reg42-reg12; reg29=reg33-reg29;
    reg33=pos_nodes[7][0]*reg2; reg36=reg6+reg36; reg18=reg27+reg18; reg6=pos_nodes[7][0]*reg30; reg35=reg40+reg35;
    reg26=reg29-reg26; reg6=reg18-reg6; reg33=reg36+reg33; reg41=reg28-reg41; reg43=reg12-reg43;
    reg12=reg6*reg43; reg18=reg26*reg41; reg27=var_inter[0]*reg43; reg33=pos[0]-reg33; reg28=var_inter[0]*reg26;
    reg35=pos[1]-reg35; reg12=reg18-reg12; reg27=reg35+reg27; reg29=var_inter[1]*reg41; reg28=reg33+reg28;
    reg33=var_inter[1]*reg6; reg28=reg33+reg28; reg27=reg29+reg27; reg29=reg41/reg12; reg33=reg43/reg12;
    reg35=reg6/reg12; reg12=reg26/reg12; reg29=reg28*reg29; reg35=reg27*reg35; reg33=reg28*reg33;
    reg12=reg27*reg12; var_inter[0]=reg29-reg35; var_inter[1]=reg12-reg33;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_8 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; reg1=reg1-1; T reg2=1-reg0;
    T reg3=1+reg0; T reg4=reg0+reg1; T reg5=1-reg1; T reg6=0.25*reg3; T reg7=reg0-reg1;
    T reg8=0.25*reg2; T reg9=0.5*reg3; T reg10=0.5*reg2; T reg11=0.5*reg5; T reg12=reg8*reg5;
    T reg13=reg5*reg6; reg7=reg7-1; T reg14=1+reg1; T reg15=1+reg4; T reg16=reg7*reg11;
    T reg17=2*reg13; T reg18=reg1-reg0; reg6=reg14*reg6; T reg19=2*reg12; T reg20=reg11*reg15;
    T reg21=0.5*reg14; reg4=reg4-1; T reg22=reg7*reg9; T reg23=reg10*reg15; T reg24=2*reg6;
    T reg25=reg4*reg21; reg20=reg19-reg20; reg16=reg16+reg17; reg22=reg17+reg22; reg15=reg12*reg15;
    reg23=reg19-reg23; reg12=reg4*reg9; reg17=pow(reg0,2); reg13=reg7*reg13; reg8=reg8*reg14;
    reg18=reg18-1; reg17=1-reg17; reg7=pos_nodes[1][1]*reg16; reg19=pos_nodes[1][0]*reg16; T reg26=pos_nodes[0][0]*reg20;
    T reg27=pos_nodes[0][0]*reg23; T reg28=pos_nodes[1][0]*reg22; T reg29=pos_nodes[0][1]*reg20; T reg30=pos_nodes[0][1]*reg23; T reg31=pos_nodes[1][1]*reg22;
    T reg32=reg18*reg10; reg12=reg24+reg12; T reg33=pow(reg1,2); T reg34=reg18*reg21; T reg35=2*reg8;
    reg25=reg24+reg25; reg24=reg13*pos_nodes[1][0]; T reg36=pos_nodes[0][0]*reg15; reg4=reg6*reg4; reg6=pos_nodes[0][1]*reg15;
    T reg37=reg13*pos_nodes[1][1]; reg33=1-reg33; reg32=reg35+reg32; reg29=reg7-reg29; reg36=reg24-reg36;
    reg7=reg4*pos_nodes[2][0]; reg24=pos_nodes[2][0]*reg12; reg18=reg8*reg18; reg27=reg28+reg27; reg8=0.5*reg17;
    reg26=reg19-reg26; reg19=pos_nodes[2][0]*reg25; reg28=2*reg0; reg34=reg35+reg34; reg30=reg31+reg30;
    reg31=pos_nodes[2][1]*reg12; reg35=pos_nodes[2][1]*reg25; reg6=reg37-reg6; reg37=reg4*pos_nodes[2][1]; reg37=reg6+reg37;
    reg6=pos_nodes[3][1]*reg32; T reg38=reg18*pos_nodes[3][0]; reg7=reg36+reg7; reg36=reg28*reg5; reg30=reg31-reg30;
    reg31=reg18*pos_nodes[3][1]; T reg39=0.5*reg33; reg35=reg29+reg35; reg5=reg8*reg5; reg29=pos_nodes[3][1]*reg34;
    T reg40=2*reg1; T reg41=pos_nodes[3][0]*reg34; reg19=reg26+reg19; reg27=reg24-reg27; reg24=pos_nodes[3][0]*reg32;
    reg26=pos_nodes[4][1]*reg36; reg29=reg35-reg29; reg38=reg7+reg38; reg7=reg5*pos_nodes[4][0]; reg35=reg5*pos_nodes[4][1];
    reg6=reg30+reg6; reg30=reg17*pos_nodes[4][1]; reg31=reg37+reg31; reg37=pos_nodes[4][0]*reg36; T reg42=reg17*pos_nodes[4][0];
    reg41=reg19-reg41; reg19=reg39*reg3; reg3=reg40*reg3; reg24=reg27+reg24; reg27=reg33*pos_nodes[5][0];
    reg37=reg41-reg37; reg41=reg33*pos_nodes[5][1]; reg26=reg29-reg26; reg29=reg28*reg14; T reg43=reg19*pos_nodes[5][1];
    reg35=reg31+reg35; reg30=reg6-reg30; reg6=pos_nodes[5][1]*reg3; reg31=reg19*pos_nodes[5][0]; reg7=reg38+reg7;
    reg42=reg24-reg42; reg24=pos_nodes[5][0]*reg3; reg14=reg8*reg14; reg6=reg30-reg6; reg8=reg17*pos_nodes[6][1];
    reg39=reg2*reg39; reg43=reg35+reg43; reg30=pos_nodes[6][1]*reg29; reg41=reg26+reg41; reg27=reg37+reg27;
    reg26=pos_nodes[6][0]*reg29; reg35=reg17*pos_nodes[6][0]; reg24=reg42-reg24; reg37=reg14*pos_nodes[6][1]; reg2=reg2*reg40;
    reg31=reg7+reg31; reg7=reg14*pos_nodes[6][0]; reg38=pos_nodes[7][0]*reg2; reg35=reg24+reg35; reg7=reg31+reg7;
    reg24=pos_nodes[7][1]*reg2; reg8=reg6+reg8; reg6=reg39*pos_nodes[7][0]; reg31=reg39*pos_nodes[7][1]; reg37=reg43+reg37;
    reg42=reg33*pos_nodes[7][0]; reg26=reg27-reg26; reg30=reg41-reg30; reg27=reg33*pos_nodes[7][1]; reg31=reg37+reg31;
    reg24=reg8-reg24; reg27=reg30-reg27; reg42=reg26-reg42; reg6=reg7+reg6; reg38=reg35-reg38;
    reg6=pos[0]-reg6; reg31=pos[1]-reg31; reg7=reg42*reg24; reg8=var_inter[0]*reg42; reg26=reg38*reg27;
    reg30=var_inter[0]*reg27; reg26=reg7-reg26; reg30=reg31+reg30; reg31=var_inter[1]*reg24; reg8=reg6+reg8;
    reg6=var_inter[1]*reg38; reg8=reg6+reg8; reg30=reg31+reg30; reg6=reg24/reg26; reg31=reg27/reg26;
    reg35=reg38/reg26; reg26=reg42/reg26; reg6=reg8*reg6; reg35=reg30*reg35; reg31=reg8*reg31;
    reg26=reg30*reg26; var_inter[0]+=reg6-reg35; var_inter[1]+=reg26-reg31;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    reg1=reg1-1; T reg4=0.25*reg2; T reg5=reg0-reg1; T reg6=0.25*reg3; T reg7=1-reg1;
    T reg8=reg0+reg1; T reg9=1+reg1; T reg10=reg7*reg4; reg5=reg5-1; T reg11=reg6*reg7;
    T reg12=1+reg8; reg5=reg10*reg5; reg8=reg8-1; reg4=reg9*reg4; reg12=reg11*reg12;
    reg10=reg1-reg0; reg0=pow(reg0,2); reg6=reg6*reg9; reg10=reg10-1; reg0=1-reg0;
    reg8=reg4*reg8; reg1=pow(reg1,2); reg5=val[1]*reg5; reg12=val[0]*reg12; reg12=reg5-reg12;
    reg8=val[2]*reg8; reg1=1-reg1; reg10=reg6*reg10; reg0=0.5*reg0; reg1=0.5*reg1;
    reg7=reg7*reg0; reg8=reg12+reg8; reg10=val[3]*reg10; reg2=reg2*reg1; reg7=val[4]*reg7;
    reg10=reg8+reg10; reg7=reg10+reg7; reg2=val[5]*reg2; reg0=reg9*reg0; reg2=reg7+reg2;
    reg0=val[6]*reg0; reg1=reg3*reg1; reg0=reg2+reg0; reg1=val[7]*reg1; res=reg0+reg1;

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Quad_8 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
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
