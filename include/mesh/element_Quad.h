#ifndef LMT_QUAD
#define LMT_QUAD
#include "node.h"
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad &elem) { /// order -> degre du polynome a integrer exactement
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
template<class TNode> void permutation_if_jac_neg(const Quad &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=0.5*nodes[1]->pos[1]; T reg1=0.5*nodes[0]->pos[1]; T reg2=0.5*nodes[0]->pos[0]; T reg3=0.5*nodes[1]->pos[0]; T reg4=reg3+reg2;
    T reg5=reg0-reg1; reg0=reg1+reg0; reg1=0.5*nodes[2]->pos[1]; T reg6=0.5*nodes[2]->pos[0]; reg2=reg3-reg2;
    reg0=reg1-reg0; reg3=0.5*nodes[3]->pos[1]; reg5=reg1+reg5; reg1=0.5*nodes[3]->pos[0]; reg4=reg6-reg4;
    reg6=reg2+reg6; reg0=reg0+reg3; reg6=reg6-reg1; reg3=reg5-reg3; reg4=reg1+reg4;
    reg0=reg6*reg0; reg4=reg3*reg4; T det_jac=reg0-reg4;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[3],nodes[2],nodes[1]};
        for(unsigned i=0;i<4;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[1]; T reg1=1-var_inter[0]; T reg2=pos_nodes[0][1]*reg0; T reg3=pos_nodes[1][1]*reg0; T reg4=pos_nodes[1][0]*reg0;
    T reg5=pos_nodes[0][0]*reg0; T reg6=pos_nodes[0][1]*reg1; T reg7=var_inter[0]*pos_nodes[1][1]; T reg8=var_inter[0]*pos_nodes[1][0]; T reg9=pos_nodes[0][0]*reg1;
    T reg10=var_inter[1]*pos_nodes[2][0]; reg7=reg6+reg7; reg6=var_inter[0]*pos_nodes[2][1]; T reg11=var_inter[0]*pos_nodes[2][0]; reg8=reg9+reg8;
    reg9=var_inter[0]*reg0; T reg12=reg0*reg1; reg2=reg3-reg2; reg3=var_inter[1]*pos_nodes[2][1]; reg5=reg4-reg5;
    reg4=var_inter[1]*pos_nodes[3][0]; reg7=reg6-reg7; reg6=pos_nodes[3][1]*reg1; T reg13=pos_nodes[1][0]*reg9; T reg14=pos_nodes[0][1]*reg12;
    T reg15=pos_nodes[1][1]*reg9; T reg16=var_inter[0]*var_inter[1]; T reg17=pos_nodes[0][0]*reg12; reg5=reg10+reg5; reg10=var_inter[1]*pos_nodes[3][1];
    T reg18=pos_nodes[3][0]*reg1; reg8=reg11-reg8; reg2=reg3+reg2; reg4=reg5-reg4; reg3=var_inter[1]*reg1;
    reg18=reg8+reg18; reg5=pos_nodes[2][0]*reg16; reg13=reg17+reg13; reg10=reg2-reg10; reg6=reg7+reg6;
    reg2=pos_nodes[2][1]*reg16; reg15=reg14+reg15; reg13=reg5+reg13; reg5=pos_nodes[3][0]*reg3; reg7=reg18*reg10;
    reg8=reg6*reg4; reg11=pos_nodes[3][1]*reg3; reg15=reg2+reg15; reg5=reg13+reg5; reg11=reg15+reg11;
    reg7=reg8-reg7; reg5=pos[0]-reg5; reg11=pos[1]-reg11; reg2=reg6/reg7; reg13=reg4/reg7;
    reg14=reg18/reg7; reg7=reg10/reg7; reg2=reg5*reg2; reg14=reg11*reg14; reg7=reg5*reg7;
    reg13=reg11*reg13; var_inter[0]=reg2-reg14; var_inter[1]=reg13-reg7;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=pos_nodes[0][1]*reg0; T reg3=pos_nodes[1][1]*var_inter[0]; T reg4=reg1*pos_nodes[0][1];
    T reg5=reg1*pos_nodes[1][1]; T reg6=pos_nodes[0][0]*reg0; T reg7=pos_nodes[1][0]*var_inter[0]; T reg8=reg1*pos_nodes[0][0]; T reg9=reg1*pos_nodes[1][0];
    T reg10=pos_nodes[2][1]*var_inter[1]; reg4=reg5-reg4; reg5=reg1*var_inter[0]; T reg11=pos_nodes[2][1]*var_inter[0]; reg6=reg7+reg6;
    reg2=reg3+reg2; reg3=reg1*reg0; reg8=reg9-reg8; reg7=pos_nodes[2][0]*var_inter[1]; reg9=pos_nodes[2][0]*var_inter[0];
    T reg12=pos_nodes[3][0]*var_inter[1]; reg6=reg9-reg6; reg9=pos_nodes[3][0]*reg0; reg7=reg8+reg7; reg8=pos_nodes[1][0]*reg5;
    T reg13=pos_nodes[0][0]*reg3; T reg14=var_inter[1]*var_inter[0]; reg2=reg11-reg2; reg11=pos_nodes[3][1]*var_inter[1]; T reg15=pos_nodes[0][1]*reg3;
    T reg16=reg5*pos_nodes[1][1]; T reg17=pos_nodes[3][1]*reg0; reg10=reg4+reg10; reg11=reg10-reg11; reg17=reg2+reg17;
    reg15=reg16+reg15; reg2=reg14*pos_nodes[2][1]; reg4=reg14*pos_nodes[2][0]; reg13=reg8+reg13; reg9=reg6+reg9;
    reg6=reg0*var_inter[1]; reg12=reg7-reg12; reg7=reg9*reg11; reg2=reg15+reg2; reg8=pos_nodes[3][1]*reg6;
    reg10=pos_nodes[3][0]*reg6; reg4=reg13+reg4; reg13=reg12*reg17; reg10=reg4+reg10; reg8=reg2+reg8;
    reg7=reg13-reg7; reg2=reg12/reg7; reg4=reg9/reg7; reg15=reg11/reg7; reg7=reg17/reg7;
    reg8=pos[1]-reg8; reg10=pos[0]-reg10; reg7=reg10*reg7; reg4=reg8*reg4; reg15=reg10*reg15;
    reg2=reg8*reg2; var_inter[0]+=reg7-reg4; var_inter[1]+=reg2-reg15;

}
template<> struct ElemVarInterFromPosNonLinear<Quad> { static const bool res = 2; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[1]; T reg1=1-var_inter[0]; T reg2=reg1*reg0; reg0=var_inter[0]*reg0; T reg3=val[0]*reg2;
    T reg4=val[1]*reg0; T reg5=var_inter[0]*var_inter[1]; reg4=reg3+reg4; reg3=val[2]*reg5; reg1=var_inter[1]*reg1;
    reg3=reg4+reg3; reg4=val[3]*reg1; res=reg3+reg4;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[0]+val[1]; reg0=val[2]+reg0; res=val[3]+reg0;

}
#ifndef STRUCT_Gauss_2
#define STRUCT_Gauss_2
struct Gauss_2 {};
#endif // STRUCT_Gauss_2
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Gauss_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[0]+val[1]; reg0=val[2]+reg0; res=val[3]+reg0;

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Bubble
#define STRUCT_Bubble
struct Bubble {};
#endif // STRUCT_Bubble
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Bubble &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[1]; T reg1=1-var_inter[0]; T reg2=reg1*reg0; T reg3=var_inter[0]*reg2; reg3=var_inter[1]*reg3;
    reg3=16*reg3; T reg4=1-reg3; reg0=var_inter[0]*reg0; T reg5=reg0*reg4; T reg6=reg2*reg4;
    T reg7=var_inter[0]*var_inter[1]; T reg8=reg7*reg4; reg5=val[1]*reg5; reg6=val[0]*reg6; reg1=var_inter[1]*reg1;
    reg5=reg6+reg5; reg8=val[2]*reg8; reg4=reg1*reg4; reg8=reg5+reg8; reg4=val[3]*reg4;
    reg4=reg8+reg4; reg3=val[4]*reg3; res=reg4+reg3;

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Quad &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=reg0*reg1; res[0]=reg2; reg1=var_inter[0]*reg1;
    res[1]=reg1; T reg3=var_inter[0]*var_inter[1]; res[2]=reg3; reg0=var_inter[1]*reg0; res[3]=reg0;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Quad> {
    static const unsigned nb_permutations = 3;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
        if ( nb_perm == 0 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[2],e.nodes[3],e.nodes[0]};
            for(unsigned i=0;i<4;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 1 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[3],e.nodes[0],e.nodes[1]};
            for(unsigned i=0;i<4;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 2 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[0],e.nodes[1],e.nodes[2]};
            for(unsigned i=0;i<4;++i) e.nodes[i] = tmp[i];
            return;
        }
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
        if ( nb_perm == 0 ) {
            typename TE::TNode *tmp[] = {e.nodes[3],e.nodes[0],e.nodes[1],e.nodes[2]};
            for(unsigned i=0;i<4;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 1 ) {
            typename TE::TNode *tmp[] = {e.nodes[2],e.nodes[3],e.nodes[0],e.nodes[1]};
            for(unsigned i=0;i<4;++i) e.nodes[i] = tmp[i];
            return;
        }
        if ( nb_perm == 2 ) {
            typename TE::TNode *tmp[] = {e.nodes[1],e.nodes[2],e.nodes[3],e.nodes[0]};
            for(unsigned i=0;i<4;++i) e.nodes[i] = tmp[i];
            return;
        }
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Quad,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=1-var_inter[1]; T reg1=elem.pos(0)[1]*reg0; T reg2=elem.pos(0)[0]*reg0; T reg3=elem.pos(1)[0]*reg0; T reg4=elem.pos(1)[1]*reg0;
    T reg5=elem.pos(0)[2]*reg0; T reg6=var_inter[1]*elem.pos(2)[1]; T reg7=var_inter[1]*elem.pos(2)[0]; T reg8=elem.pos(1)[2]*reg0; reg3=reg3-reg2;
    reg4=reg4-reg1; reg8=reg8-reg5; T reg9=var_inter[1]*elem.pos(2)[2]; T reg10=var_inter[1]*elem.pos(3)[1]; T reg11=var_inter[1]*elem.pos(3)[0];
    reg3=reg7+reg3; reg6=reg4+reg6; reg3=reg3-reg11; reg9=reg8+reg9; reg4=var_inter[1]*elem.pos(3)[2];
    reg6=reg6-reg10; reg7=pow(reg3,2); reg8=1-var_inter[0]; T reg12=pow(reg6,2); reg9=reg9-reg4;
    T reg13=pow(reg9,2); reg12=reg7+reg12; reg7=var_inter[0]*elem.pos(1)[1]; T reg14=var_inter[0]*elem.pos(1)[0]; T reg15=elem.pos(0)[1]*reg8;
    T reg16=elem.pos(0)[0]*reg8; reg13=reg12+reg13; reg12=reg14+reg16; T reg17=var_inter[0]*elem.pos(1)[2]; T reg18=elem.pos(0)[2]*reg8;
    T reg19=var_inter[0]*elem.pos(2)[0]; T reg20=reg15+reg7; T reg21=var_inter[0]*elem.pos(2)[1]; reg19=reg19-reg12; T reg22=reg8*elem.pos(3)[0];
    T reg23=var_inter[0]*elem.pos(2)[2]; reg21=reg21-reg20; T reg24=reg8*elem.pos(3)[1]; reg13=pow(reg13,0.5); T reg25=reg18+reg17;
    T reg26=reg6/reg13; T reg27=reg3/reg13; T reg28=reg8*elem.pos(3)[2]; reg23=reg23-reg25; reg22=reg19+reg22;
    reg24=reg21+reg24; reg19=reg26*reg24; reg21=reg27*reg22; reg28=reg23+reg28; reg13=reg9/reg13;
    reg19=reg21+reg19; reg21=reg13*reg28; reg21=reg19+reg21; reg19=reg26*reg21; reg23=reg27*reg21;
    T reg29=reg13*reg21; reg23=reg22-reg23; reg19=reg24-reg19; reg29=reg28-reg29; T reg30=pow(reg23,2);
    T reg31=pow(reg19,2); T reg32=pow(reg29,2); reg31=reg30+reg31; reg32=reg31+reg32; reg32=pow(reg32,0.5);
    reg19=reg19/reg32; reg23=reg23/reg32; reg32=reg29/reg32; reg22=reg22*reg23; reg24=reg24*reg19;
    reg26=reg26*reg6; reg27=reg27*reg3; reg6=reg19*reg6; reg23=reg3*reg23; reg26=reg27+reg26;
    reg13=reg13*reg9; reg28=reg28*reg32; reg32=reg9*reg32; reg6=reg23+reg6; reg24=reg22+reg24;
    reg28=reg24+reg28; reg26=reg13+reg26; reg32=reg6+reg32; reg3=reg32*reg21; reg6=reg26*reg28;
    reg3=reg6-reg3; return reg3;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Quad,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.78867513459481286553*elem.pos(0)[1]; T reg1=0.78867513459481286553*elem.pos(1)[1]; T reg2=0.21132486540518713447*elem.pos(0)[1]; T reg3=0.78867513459481286553*elem.pos(0)[0]; T reg4=0.78867513459481286553*elem.pos(1)[0];
    T reg5=0.21132486540518713447*elem.pos(1)[1]; T reg6=0.21132486540518713447*elem.pos(1)[0]; T reg7=0.21132486540518713447*elem.pos(0)[0]; T reg8=reg7+reg4; reg7=reg6-reg7;
    T reg9=0.78867513459481286553*elem.pos(2)[0]; T reg10=reg5-reg2; T reg11=0.78867513459481286553*elem.pos(2)[1]; reg2=reg2+reg1; T reg12=0.21132486540518713447*elem.pos(2)[1];
    reg5=reg0+reg5; T reg13=0.21132486540518713447*elem.pos(2)[0]; reg6=reg3+reg6; T reg14=0.78867513459481286553*elem.pos(3)[0]; reg7=reg7+reg9;
    T reg15=0.044658198738520458147*elem.pos(1)[1]; T reg16=0.16666666666666667632*elem.pos(0)[1]; T reg17=0.16666666666666667632*elem.pos(1)[0]; T reg18=0.044658198738520458147*elem.pos(0)[0]; T reg19=0.16666666666666667632*elem.pos(1)[1];
    T reg20=0.044658198738520458147*elem.pos(0)[1]; reg2=reg11-reg2; T reg21=0.21132486540518713447*elem.pos(3)[1]; reg5=reg12-reg5; T reg22=0.044658198738520458147*elem.pos(1)[0];
    reg10=reg11+reg10; reg11=0.78867513459481286553*elem.pos(3)[1]; reg6=reg13-reg6; reg0=reg1-reg0; reg1=0.21132486540518713447*elem.pos(3)[0];
    reg8=reg9-reg8; reg3=reg4-reg3; reg4=0.16666666666666667632*elem.pos(0)[0]; reg9=0.6220084679281461892*elem.pos(1)[0]; reg22=reg22+reg4;
    T reg23=0.16666666666666667632*elem.pos(2)[0]; reg15=reg16+reg15; T reg24=0.16666666666666667632*elem.pos(2)[1]; reg6=reg6+reg14; reg5=reg5+reg11;
    T reg25=0.6220084679281461892*elem.pos(1)[1]; reg8=reg8+reg1; T reg26=0.6220084679281461892*elem.pos(2)[1]; reg20=reg20+reg19; reg18=reg17+reg18;
    reg3=reg13+reg3; reg13=0.6220084679281461892*elem.pos(2)[0]; reg11=reg10-reg11; reg0=reg12+reg0; reg14=reg7-reg14;
    reg2=reg2+reg21; reg7=reg11*reg8; reg13=reg18+reg13; reg10=0.16666666666666667632*elem.pos(3)[0]; reg12=reg14*reg2;
    reg18=0.6220084679281461892*elem.pos(0)[1]; reg25=reg16+reg25; reg22=reg22+reg23; reg21=reg0-reg21; reg0=0.16666666666666667632*elem.pos(3)[1];
    reg1=reg3-reg1; reg3=0.6220084679281461892*elem.pos(3)[0]; reg16=0.6220084679281461892*elem.pos(0)[0]; reg15=reg15+reg24; T reg27=0.6220084679281461892*elem.pos(3)[1];
    reg26=reg20+reg26; reg4=reg9+reg4; reg14=reg5*reg14; reg11=reg6*reg11; reg26=reg26+reg0;
    reg7=reg12-reg7; reg13=reg13+reg10; reg23=reg4+reg23; reg4=0.044658198738520458147*elem.pos(3)[0]; reg9=0.044658198738520458147*elem.pos(2)[0];
    reg17=reg16+reg17; reg8=reg21*reg8; reg2=reg1*reg2; reg25=reg24+reg25; reg12=0.044658198738520458147*elem.pos(3)[1];
    reg3=reg22+reg3; reg18=reg19+reg18; reg16=0.044658198738520458147*elem.pos(2)[1]; reg11=reg14-reg11; reg27=reg15+reg27;
    reg26=reg26*reg7; reg12=reg25+reg12; reg8=reg2-reg8; reg4=reg23+reg4; reg9=reg17+reg9;
    reg1=reg5*reg1; reg21=reg6*reg21; reg3=reg3*reg11; reg16=reg18+reg16; reg27=reg11*reg27;
    reg13=reg13*reg7; reg21=reg1-reg21; reg16=reg0+reg16; reg11=0.25*reg11; reg10=reg9+reg10;
    reg3=0.25*reg3; reg27=0.25*reg27; reg7=0.25*reg7; reg12=reg8*reg12; reg4=reg4*reg8;
    reg26=0.25*reg26; reg13=0.25*reg13; reg13=reg3+reg13; reg27=reg26+reg27; reg12=0.25*reg12;
    reg16=reg21*reg16; reg8=0.25*reg8; reg7=reg11+reg7; reg10=reg10*reg21; reg4=0.25*reg4;
    reg10=0.25*reg10; reg8=reg7+reg8; reg21=0.25*reg21; reg16=0.25*reg16; reg12=reg27+reg12;
    reg4=reg13+reg4; reg10=reg4+reg10; reg21=reg8+reg21; reg16=reg12+reg16; res[0]=reg10/reg21;
    res[1]=reg16/reg21;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Quad,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.21132486540518713447*elem.pos(1)[1]; T reg1=0.21132486540518713447*elem.pos(1)[0]; T reg2=0.21132486540518713447*elem.pos(0)[1]; T reg3=0.21132486540518713447*elem.pos(0)[0]; T reg4=reg0-reg2;
    T reg5=0.78867513459481286553*elem.pos(0)[1]; T reg6=0.78867513459481286553*elem.pos(0)[0]; T reg7=0.78867513459481286553*elem.pos(1)[0]; T reg8=0.78867513459481286553*elem.pos(1)[1]; T reg9=0.78867513459481286553*elem.pos(2)[1];
    T reg10=reg1-reg3; T reg11=0.21132486540518713447*elem.pos(1)[2]; T reg12=0.21132486540518713447*elem.pos(0)[2]; T reg13=0.78867513459481286553*elem.pos(2)[0]; T reg14=0.78867513459481286553*elem.pos(3)[0];
    reg4=reg4+reg9; T reg15=0.78867513459481286553*elem.pos(3)[1]; T reg16=0.78867513459481286553*elem.pos(2)[2]; T reg17=reg11-reg12; reg10=reg10+reg13;
    T reg18=0.78867513459481286553*elem.pos(1)[2]; T reg19=0.21132486540518713447*elem.pos(2)[0]; T reg20=0.21132486540518713447*elem.pos(2)[1]; T reg21=0.78867513459481286553*elem.pos(0)[2]; T reg22=reg7-reg6;
    T reg23=reg8-reg5; T reg24=0.21132486540518713447*elem.pos(3)[1]; T reg25=0.21132486540518713447*elem.pos(3)[0]; T reg26=0.21132486540518713447*elem.pos(2)[2]; T reg27=0.78867513459481286553*elem.pos(3)[2];
    reg17=reg17+reg16; reg22=reg19+reg22; reg23=reg20+reg23; T reg28=reg18-reg21; reg4=reg4-reg15;
    reg10=reg10-reg14; T reg29=0.21132486540518713447*elem.pos(3)[2]; T reg30=pow(reg4,2); reg17=reg17-reg27; T reg31=pow(reg10,2);
    reg22=reg22-reg25; reg28=reg26+reg28; reg23=reg23-reg24; reg28=reg28-reg29; T reg32=pow(reg23,2);
    T reg33=pow(reg22,2); T reg34=pow(reg17,2); reg30=reg31+reg30; reg32=reg33+reg32; reg5=reg0+reg5;
    reg6=reg1+reg6; reg0=pow(reg28,2); reg8=reg2+reg8; reg34=reg30+reg34; reg7=reg3+reg7;
    reg6=reg19-reg6; reg8=reg9-reg8; reg34=pow(reg34,0.5); reg5=reg20-reg5; reg18=reg12+reg18;
    reg7=reg13-reg7; reg0=reg32+reg0; reg21=reg11+reg21; reg1=reg4/reg34; reg2=reg10/reg34;
    reg21=reg26-reg21; reg0=pow(reg0,0.5); reg5=reg15+reg5; reg25=reg7+reg25; reg18=reg16-reg18;
    reg8=reg24+reg8; reg6=reg14+reg6; reg3=reg1*reg5; reg7=reg2*reg6; reg21=reg27+reg21;
    reg9=reg2*reg25; reg34=reg17/reg34; reg11=reg1*reg8; reg12=reg23/reg0; reg29=reg18+reg29;
    reg13=reg22/reg0; reg14=reg25*reg13; reg0=reg28/reg0; reg11=reg9+reg11; reg9=reg34*reg29;
    reg3=reg7+reg3; reg7=reg8*reg12; reg15=reg34*reg21; reg7=reg14+reg7; reg15=reg3+reg15;
    reg3=reg5*reg12; reg14=reg29*reg0; reg16=reg6*reg13; reg9=reg11+reg9; reg11=reg2*reg15;
    reg14=reg7+reg14; reg7=reg1*reg15; reg18=reg21*reg0; reg19=reg2*reg9; reg3=reg16+reg3;
    reg16=reg1*reg9; reg11=reg6-reg11; reg7=reg5-reg7; reg18=reg3+reg18; reg3=reg34*reg15;
    reg16=reg8-reg16; reg20=reg34*reg9; reg24=reg13*reg14; reg26=reg12*reg14; reg19=reg25-reg19;
    reg27=pow(reg11,2); reg20=reg29-reg20; reg24=reg25-reg24; reg30=pow(reg7,2); reg31=reg13*reg18;
    reg3=reg21-reg3; reg32=reg12*reg18; reg26=reg8-reg26; reg33=pow(reg19,2); T reg35=reg0*reg14;
    T reg36=pow(reg16,2); T reg37=pow(reg3,2); T reg38=pow(reg20,2); reg30=reg27+reg30; reg27=pow(reg26,2);
    reg36=reg33+reg36; reg35=reg29-reg35; reg32=reg5-reg32; reg33=reg0*reg18; reg31=reg6-reg31;
    T reg39=pow(reg24,2); reg27=reg39+reg27; reg39=pow(reg31,2); reg37=reg30+reg37; reg33=reg21-reg33;
    reg30=pow(reg35,2); reg38=reg36+reg38; reg36=pow(reg32,2); reg38=pow(reg38,0.5); reg37=pow(reg37,0.5);
    T reg40=pow(reg33,2); reg30=reg27+reg30; reg36=reg39+reg36; reg40=reg36+reg40; reg30=pow(reg30,0.5);
    reg19=reg19/reg38; reg16=reg16/reg38; reg11=reg11/reg37; reg7=reg7/reg37; reg27=reg25*reg19;
    reg40=pow(reg40,0.5); reg36=reg8*reg16; reg38=reg20/reg38; reg20=reg6*reg11; reg39=reg5*reg7;
    reg19=reg10*reg19; reg24=reg24/reg30; reg37=reg3/reg37; reg26=reg26/reg30; reg2=reg10*reg2;
    reg16=reg4*reg16; reg1=reg4*reg1; reg7=reg4*reg7; reg11=reg10*reg11; reg1=reg2+reg1;
    reg34=reg17*reg34; reg25=reg25*reg24; reg8=reg8*reg26; reg30=reg35/reg30; reg24=reg22*reg24;
    reg26=reg23*reg26; reg31=reg31/reg40; reg32=reg32/reg40; reg2=0.16666666666666667632*elem.pos(0)[2]; reg3=0.044658198738520458147*elem.pos(1)[2];
    reg4=0.16666666666666667632*elem.pos(1)[1]; reg10=0.044658198738520458147*elem.pos(0)[1]; reg35=0.044658198738520458147*elem.pos(1)[1]; T reg41=0.16666666666666667632*elem.pos(0)[1]; T reg42=0.044658198738520458147*elem.pos(0)[2];
    T reg43=0.16666666666666667632*elem.pos(1)[2]; reg7=reg11+reg7; reg11=0.16666666666666667632*elem.pos(0)[0]; T reg44=reg17*reg37; T reg45=0.044658198738520458147*elem.pos(1)[0];
    reg17=reg17*reg38; reg16=reg19+reg16; reg19=0.16666666666666667632*elem.pos(1)[0]; T reg46=0.044658198738520458147*elem.pos(0)[0]; reg38=reg29*reg38;
    reg36=reg27+reg36; reg39=reg20+reg39; reg37=reg21*reg37; reg12=reg23*reg12; reg13=reg22*reg13;
    reg20=0.6220084679281461892*elem.pos(1)[2]; reg27=0.16666666666666667632*elem.pos(2)[2]; reg3=reg3+reg2; T reg47=0.16666666666666667632*elem.pos(2)[0]; reg45=reg11+reg45;
    reg37=reg39+reg37; reg22=reg22*reg31; reg39=reg28*reg30; reg38=reg36+reg38; reg26=reg24+reg26;
    reg23=reg23*reg32; reg32=reg5*reg32; reg34=reg1+reg34; reg42=reg43+reg42; reg0=reg28*reg0;
    reg12=reg13+reg12; reg1=0.6220084679281461892*elem.pos(2)[2]; reg31=reg6*reg31; reg40=reg33/reg40; reg5=0.6220084679281461892*elem.pos(1)[1];
    reg6=0.6220084679281461892*elem.pos(1)[0]; reg13=0.6220084679281461892*elem.pos(2)[0]; reg24=0.16666666666666667632*elem.pos(2)[1]; reg35=reg35+reg41; reg46=reg46+reg19;
    reg17=reg16+reg17; reg44=reg7+reg44; reg8=reg25+reg8; reg30=reg29*reg30; reg7=0.6220084679281461892*elem.pos(2)[1];
    reg10=reg4+reg10; reg21=reg21*reg40; reg32=reg31+reg32; reg23=reg22+reg23; reg40=reg28*reg40;
    reg20=reg2+reg20; reg2=0.6220084679281461892*elem.pos(3)[2]; reg3=reg3+reg27; reg16=0.16666666666666667632*elem.pos(3)[1]; reg7=reg10+reg7;
    reg10=0.6220084679281461892*elem.pos(3)[1]; reg35=reg35+reg24; reg5=reg41+reg5; reg22=0.16666666666666667632*elem.pos(3)[2]; reg1=reg42+reg1;
    reg25=0.6220084679281461892*elem.pos(0)[1]; reg17=reg9*reg17; reg0=reg12+reg0; reg9=0.16666666666666667632*elem.pos(3)[0]; reg13=reg46+reg13;
    reg6=reg11+reg6; reg44=reg15*reg44; reg30=reg8+reg30; reg37=reg34*reg37; reg39=reg26+reg39;
    reg8=0.6220084679281461892*elem.pos(0)[2]; reg11=0.6220084679281461892*elem.pos(0)[0]; reg45=reg45+reg47; reg12=0.6220084679281461892*elem.pos(3)[0]; reg38=reg34*reg38;
    reg1=reg1+reg22; reg35=reg10+reg35; reg8=reg43+reg8; reg10=0.044658198738520458147*elem.pos(2)[2]; reg15=0.044658198738520458147*elem.pos(3)[1];
    reg21=reg32+reg21; reg6=reg47+reg6; reg44=reg37-reg44; reg5=reg24+reg5; reg7=reg16+reg7;
    reg24=0.044658198738520458147*elem.pos(3)[0]; reg30=reg0*reg30; reg12=reg45+reg12; reg39=reg14*reg39; reg14=0.044658198738520458147*elem.pos(3)[2];
    reg25=reg4+reg25; reg4=0.044658198738520458147*elem.pos(2)[1]; reg40=reg23+reg40; reg11=reg19+reg11; reg2=reg3+reg2;
    reg3=0.044658198738520458147*elem.pos(2)[0]; reg17=reg38-reg17; reg20=reg27+reg20; reg13=reg13+reg9; reg24=reg6+reg24;
    reg5=reg15+reg5; reg4=reg25+reg4; reg40=reg18*reg40; reg3=reg11+reg3; reg2=reg44*reg2;
    reg14=reg20+reg14; reg39=reg30-reg39; reg10=reg8+reg10; reg21=reg0*reg21; reg7=reg17*reg7;
    reg13=reg13*reg17; reg12=reg12*reg44; reg35=reg44*reg35; reg1=reg17*reg1; reg1=0.25*reg1;
    reg10=reg22+reg10; reg14=reg39*reg14; reg2=0.25*reg2; reg40=reg21-reg40; reg3=reg9+reg3;
    reg12=0.25*reg12; reg44=0.25*reg44; reg17=0.25*reg17; reg13=0.25*reg13; reg7=0.25*reg7;
    reg35=0.25*reg35; reg5=reg39*reg5; reg4=reg16+reg4; reg24=reg24*reg39; reg35=reg7+reg35;
    reg5=0.25*reg5; reg10=reg40*reg10; reg14=0.25*reg14; reg24=0.25*reg24; reg39=0.25*reg39;
    reg44=reg17+reg44; reg4=reg40*reg4; reg2=reg1+reg2; reg3=reg3*reg40; reg12=reg13+reg12;
    reg24=reg12+reg24; reg14=reg2+reg14; reg3=0.25*reg3; reg39=reg44+reg39; reg40=0.25*reg40;
    reg5=reg35+reg5; reg4=0.25*reg4; reg10=0.25*reg10; reg10=reg14+reg10; reg3=reg24+reg3;
    reg40=reg39+reg40; reg4=reg5+reg4; res[0]=reg3/reg40; res[1]=reg4/reg40; res[2]=reg10/reg40;

    return res;
}
}
#endif // LMT_QUAD
