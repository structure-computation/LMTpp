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
    T reg3=1+reg0; T reg4=reg0+reg1; T reg5=1-reg1; T reg6=0.25*reg2; T reg7=0.25*reg3;
    T reg8=reg0-reg1; T reg9=1+reg1; T reg10=0.5*reg5; T reg11=reg5*reg7; reg8=reg8-1;
    T reg12=0.5*reg2; T reg13=0.5*reg3; T reg14=1+reg4; T reg15=reg6*reg5; T reg16=0.5*reg9;
    T reg17=reg14*reg10; T reg18=2*reg15; T reg19=reg10*reg8; T reg20=2*reg11; reg7=reg9*reg7;
    reg4=reg4-1; T reg21=reg1-reg0; T reg22=reg14*reg12; T reg23=reg8*reg13; T reg24=pow(reg0,2);
    reg21=reg21-1; reg6=reg6*reg9; T reg25=reg4*reg13; reg22=reg18-reg22; reg8=reg11*reg8;
    reg11=reg16*reg4; reg23=reg20+reg23; T reg26=2*reg7; reg14=reg15*reg14; reg17=reg18-reg17;
    reg19=reg20+reg19; reg15=pos_nodes[1][1]*reg23; reg18=pos_nodes[0][1]*reg22; reg20=pos_nodes[0][0]*reg17; T reg27=pos_nodes[1][0]*reg19;
    reg11=reg26+reg11; reg4=reg7*reg4; reg25=reg26+reg25; reg7=reg21*reg12; reg26=pow(reg1,2);
    T reg28=pos_nodes[1][0]*reg23; reg24=1-reg24; T reg29=pos_nodes[0][0]*reg22; T reg30=2*reg6; T reg31=reg16*reg21;
    T reg32=pos_nodes[0][0]*reg14; T reg33=pos_nodes[1][0]*reg8; T reg34=reg14*pos_nodes[0][1]; T reg35=pos_nodes[1][1]*reg8; T reg36=pos_nodes[1][1]*reg19;
    T reg37=pos_nodes[0][1]*reg17; T reg38=pos_nodes[2][0]*reg25; reg7=reg30+reg7; T reg39=pos_nodes[2][0]*reg4; T reg40=pos_nodes[2][1]*reg4;
    reg34=reg35-reg34; reg35=pos_nodes[2][1]*reg25; reg29=reg28+reg29; reg28=pos_nodes[2][1]*reg11; reg18=reg15+reg18;
    reg32=reg33-reg32; reg37=reg36-reg37; reg15=0.5*reg24; reg26=1-reg26; reg21=reg6*reg21;
    reg31=reg30+reg31; reg6=2*reg0; reg20=reg27-reg20; reg27=pos_nodes[2][0]*reg11; reg30=reg5*reg15;
    reg29=reg38-reg29; reg33=pos_nodes[3][0]*reg7; reg36=pos_nodes[3][1]*reg7; reg18=reg35-reg18; reg5=reg5*reg6;
    reg35=2*reg1; reg39=reg32+reg39; reg32=pos_nodes[3][0]*reg21; reg38=pos_nodes[3][1]*reg31; reg28=reg37+reg28;
    reg37=0.5*reg26; T reg41=pos_nodes[3][1]*reg21; reg27=reg20+reg27; reg20=pos_nodes[3][0]*reg31; reg40=reg34+reg40;
    reg34=pos_nodes[4][0]*reg5; reg38=reg28-reg38; reg28=pos_nodes[4][1]*reg5; T reg42=pos_nodes[4][0]*reg30; reg32=reg39+reg32;
    reg39=pos_nodes[4][1]*reg30; reg41=reg40+reg41; reg20=reg27-reg20; reg36=reg18+reg36; reg18=pos_nodes[4][1]*reg24;
    reg27=pos_nodes[4][0]*reg24; reg33=reg29+reg33; reg29=reg3*reg37; reg3=reg3*reg35; reg18=reg36-reg18;
    reg39=reg41+reg39; reg36=pos_nodes[5][1]*reg26; reg28=reg38-reg28; reg38=pos_nodes[5][1]*reg3; reg40=pos_nodes[5][1]*reg29;
    reg41=reg6*reg9; reg27=reg33-reg27; reg33=pos_nodes[5][0]*reg3; T reg43=pos_nodes[5][0]*reg26; reg34=reg20-reg34;
    reg42=reg32+reg42; reg20=pos_nodes[5][0]*reg29; reg15=reg9*reg15; reg9=pos_nodes[6][1]*reg24; reg38=reg18-reg38;
    reg33=reg27-reg33; reg18=pos_nodes[6][0]*reg24; reg40=reg39+reg40; reg27=reg2*reg35; reg32=pos_nodes[6][1]*reg41;
    reg36=reg28+reg36; reg20=reg42+reg20; reg28=pos_nodes[6][0]*reg15; reg37=reg2*reg37; reg43=reg34+reg43;
    reg2=pos_nodes[6][1]*reg15; reg34=pos_nodes[6][0]*reg41; reg39=pos_nodes[7][1]*reg27; reg42=pos_nodes[7][0]*reg26; reg34=reg43-reg34;
    reg9=reg38+reg9; reg18=reg33+reg18; reg33=pos_nodes[7][0]*reg27; reg38=pos_nodes[7][1]*reg26; reg32=reg36-reg32;
    reg28=reg20+reg28; reg20=pos_nodes[7][0]*reg37; reg2=reg40+reg2; reg36=pos_nodes[7][1]*reg37; reg36=reg2+reg36;
    reg42=reg34-reg42; reg39=reg9-reg39; reg33=reg18-reg33; reg38=reg32-reg38; reg20=reg28+reg20;
    reg20=pos[0]-reg20; reg36=pos[1]-reg36; reg2=var_inter[0]*reg42; reg9=reg33*reg38; reg18=var_inter[0]*reg38;
    reg28=reg42*reg39; reg9=reg28-reg9; reg18=reg36+reg18; reg32=var_inter[1]*reg39; reg2=reg20+reg2;
    reg20=var_inter[1]*reg33; reg2=reg20+reg2; reg18=reg32+reg18; reg20=reg39/reg9; reg32=reg38/reg9;
    reg34=reg33/reg9; reg9=reg42/reg9; reg20=reg2*reg20; reg34=reg18*reg34; reg32=reg2*reg32;
    reg9=reg18*reg9; var_inter[0]=reg20-reg34; var_inter[1]=reg9-reg32;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_8 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=2*var_inter[0]; reg0=reg0-1; T reg1=2*var_inter[1]; T reg2=1+reg0; T reg3=1-reg0;
    reg1=reg1-1; T reg4=0.25*reg3; T reg5=reg1+reg0; T reg6=reg0-reg1; T reg7=1-reg1;
    T reg8=0.25*reg2; T reg9=0.5*reg2; T reg10=0.5*reg3; T reg11=0.5*reg7; T reg12=1+reg5;
    T reg13=reg4*reg7; T reg14=1+reg1; T reg15=reg7*reg8; reg6=reg6-1; reg8=reg14*reg8;
    reg5=reg5-1; T reg16=0.5*reg14; T reg17=reg12*reg11; T reg18=reg6*reg9; T reg19=2*reg13;
    T reg20=reg1-reg0; T reg21=reg12*reg10; T reg22=2*reg15; T reg23=reg11*reg6; T reg24=reg5*reg9;
    reg21=reg19-reg21; T reg25=pow(reg0,2); reg18=reg22+reg18; reg20=reg20-1; reg12=reg13*reg12;
    reg4=reg4*reg14; reg6=reg15*reg6; reg17=reg19-reg17; reg13=2*reg8; reg23=reg22+reg23;
    reg15=reg16*reg5; reg5=reg8*reg5; reg8=pos_nodes[0][1]*reg12; reg19=pos_nodes[1][1]*reg6; reg22=pos_nodes[0][1]*reg21;
    T reg26=pos_nodes[1][1]*reg18; T reg27=pos_nodes[0][1]*reg17; T reg28=pos_nodes[1][1]*reg23; reg25=1-reg25; T reg29=pow(reg1,2);
    reg15=reg13+reg15; T reg30=2*reg4; T reg31=reg16*reg20; T reg32=pos_nodes[0][0]*reg12; T reg33=pos_nodes[1][0]*reg6;
    T reg34=pos_nodes[1][0]*reg23; T reg35=pos_nodes[0][0]*reg17; T reg36=pos_nodes[0][0]*reg21; T reg37=pos_nodes[1][0]*reg18; T reg38=reg20*reg10;
    reg24=reg13+reg24; reg22=reg26+reg22; reg13=pos_nodes[2][0]*reg24; reg8=reg19-reg8; reg19=pos_nodes[2][1]*reg5;
    reg26=pos_nodes[2][1]*reg24; reg36=reg37+reg36; reg37=pos_nodes[2][1]*reg15; reg27=reg28-reg27; reg32=reg33-reg32;
    reg28=pos_nodes[2][0]*reg5; reg29=1-reg29; reg38=reg30+reg38; reg33=0.5*reg25; reg20=reg4*reg20;
    reg4=pos_nodes[2][0]*reg15; reg35=reg34-reg35; reg31=reg30+reg31; reg30=2*reg0; reg4=reg35+reg4;
    reg34=2*reg1; reg36=reg13-reg36; reg13=pos_nodes[3][0]*reg38; reg35=pos_nodes[3][1]*reg38; reg22=reg26-reg22;
    reg26=reg7*reg30; reg28=reg32+reg28; reg32=pos_nodes[3][0]*reg20; T reg39=pos_nodes[3][1]*reg31; reg37=reg27+reg37;
    reg7=reg7*reg33; reg27=0.5*reg29; T reg40=pos_nodes[3][1]*reg20; reg19=reg8+reg19; reg8=pos_nodes[3][0]*reg31;
    T reg41=reg34*reg2; reg39=reg37-reg39; reg37=pos_nodes[4][1]*reg26; T reg42=pos_nodes[4][0]*reg7; reg32=reg28+reg32;
    reg2=reg2*reg27; reg28=pos_nodes[4][1]*reg7; reg40=reg19+reg40; reg8=reg4-reg8; reg35=reg22+reg35;
    reg4=pos_nodes[4][1]*reg25; reg19=pos_nodes[4][0]*reg25; reg13=reg36+reg13; reg22=pos_nodes[4][0]*reg26; reg28=reg40+reg28;
    reg36=pos_nodes[5][1]*reg2; reg4=reg35-reg4; reg35=pos_nodes[5][1]*reg29; reg37=reg39-reg37; reg39=pos_nodes[5][1]*reg41;
    reg19=reg13-reg19; reg13=pos_nodes[5][0]*reg41; reg40=pos_nodes[5][0]*reg29; reg33=reg14*reg33; reg14=reg30*reg14;
    reg42=reg32+reg42; reg32=pos_nodes[5][0]*reg2; reg22=reg8-reg22; reg8=pos_nodes[6][1]*reg25; reg39=reg4-reg39;
    reg13=reg19-reg13; reg4=pos_nodes[6][0]*reg25; reg27=reg3*reg27; reg36=reg28+reg36; reg3=reg3*reg34;
    reg19=pos_nodes[6][1]*reg14; reg35=reg37+reg35; reg32=reg42+reg32; reg28=pos_nodes[6][0]*reg33; reg40=reg22+reg40;
    reg22=pos_nodes[6][1]*reg33; reg37=pos_nodes[6][0]*reg14; reg42=pos_nodes[7][1]*reg3; reg37=reg40-reg37; reg40=pos_nodes[7][0]*reg29;
    reg8=reg39+reg8; reg4=reg13+reg4; reg13=pos_nodes[7][0]*reg3; reg39=pos_nodes[7][1]*reg29; reg19=reg35-reg19;
    reg28=reg32+reg28; reg32=pos_nodes[7][0]*reg27; reg22=reg36+reg22; reg35=pos_nodes[7][1]*reg27; reg35=reg22+reg35;
    reg40=reg37-reg40; reg42=reg8-reg42; reg13=reg4-reg13; reg39=reg19-reg39; reg32=reg28+reg32;
    reg32=pos[0]-reg32; reg35=pos[1]-reg35; reg4=var_inter[0]*reg40; reg8=reg13*reg39; reg19=var_inter[0]*reg39;
    reg22=reg40*reg42; reg8=reg22-reg8; reg19=reg35+reg19; reg28=var_inter[1]*reg42; reg4=reg32+reg4;
    reg32=var_inter[1]*reg13; reg4=reg32+reg4; reg19=reg28+reg19; reg28=reg42/reg8; reg32=reg39/reg8;
    reg35=reg13/reg8; reg8=reg40/reg8; reg28=reg4*reg28; reg35=reg19*reg35; reg32=reg4*reg32;
    reg8=reg19*reg8; var_inter[0]+=reg28-reg35; var_inter[1]+=reg8-reg32;

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
    reg10=reg1-reg0; reg0=pow(reg0,2); reg8=reg4*reg8; reg0=1-reg0; reg6=reg6*reg9;
    reg10=reg10-1; reg1=pow(reg1,2); reg5=val[1]*reg5; reg12=val[0]*reg12; reg12=reg5-reg12;
    reg8=val[2]*reg8; reg1=1-reg1; reg10=reg6*reg10; reg0=0.5*reg0; reg7=reg7*reg0;
    reg10=val[3]*reg10; reg8=reg12+reg8; reg1=0.5*reg1; reg2=reg2*reg1; reg7=val[4]*reg7;
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
