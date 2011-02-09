#ifndef LMT_QUAD
#define LMT_QUAD
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
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=pos_nodes[1][1]*var_inter[0]; T reg3=pos_nodes[0][1]*reg1; T reg4=reg1*pos_nodes[1][1];
    T reg5=pos_nodes[0][0]*reg0; T reg6=pos_nodes[1][0]*var_inter[0]; T reg7=pos_nodes[0][0]*reg1; T reg8=pos_nodes[1][0]*reg1; T reg9=pos_nodes[0][1]*reg0;
    T reg10=pos_nodes[2][1]*var_inter[0]; reg5=reg6+reg5; reg6=reg0*reg1; T reg11=pos_nodes[2][0]*var_inter[0]; reg9=reg2+reg9;
    reg2=pos_nodes[2][0]*var_inter[1]; reg7=reg8-reg7; reg8=reg1*var_inter[0]; reg3=reg4-reg3; reg4=pos_nodes[2][1]*var_inter[1];
    T reg12=pos_nodes[1][1]*reg8; T reg13=var_inter[1]*var_inter[0]; T reg14=reg6*pos_nodes[0][1]; reg4=reg3+reg4; reg3=pos_nodes[3][1]*var_inter[1];
    T reg15=reg6*pos_nodes[0][0]; T reg16=pos_nodes[1][0]*reg8; T reg17=pos_nodes[3][0]*reg0; reg5=reg11-reg5; reg11=pos_nodes[3][0]*var_inter[1];
    reg2=reg7+reg2; reg9=reg10-reg9; reg7=pos_nodes[3][1]*reg0; reg3=reg4-reg3; reg7=reg9+reg7;
    reg14=reg12+reg14; reg4=reg13*pos_nodes[2][1]; reg9=reg13*pos_nodes[2][0]; reg15=reg16+reg15; reg17=reg5+reg17;
    reg5=reg0*var_inter[1]; reg11=reg2-reg11; reg4=reg14+reg4; reg2=pos_nodes[3][1]*reg5; reg10=reg17*reg3;
    reg12=pos_nodes[3][0]*reg5; reg9=reg15+reg9; reg14=reg11*reg7; reg12=reg9+reg12; reg2=reg4+reg2;
    reg10=reg14-reg10; reg4=reg11/reg10; reg9=reg17/reg10; reg15=reg3/reg10; reg10=reg7/reg10;
    reg2=pos[1]-reg2; reg12=pos[0]-reg12; reg10=reg12*reg10; reg9=reg2*reg9; reg15=reg12*reg15;
    reg4=reg2*reg4; var_inter[0]+=reg10-reg9; var_inter[1]+=reg4-reg15;

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
    T reg0=1-var_inter[1]; T reg1=1-var_inter[0]; T reg2=var_inter[0]*reg0; reg0=reg1*reg0; T reg3=val[0]*reg0;
    T reg4=val[1]*reg2; T reg5=var_inter[0]*var_inter[1]; reg4=reg3+reg4; reg3=val[2]*reg5; reg1=var_inter[1]*reg1;
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
    reg3=16*reg3; reg0=var_inter[0]*reg0; T reg4=1-reg3; T reg5=var_inter[0]*var_inter[1]; T reg6=reg2*reg4;
    T reg7=reg0*reg4; T reg8=reg5*reg4; reg7=val[1]*reg7; reg6=val[0]*reg6; reg1=var_inter[1]*reg1;
    reg7=reg6+reg7; reg8=val[2]*reg8; reg4=reg1*reg4; reg8=reg7+reg8; reg4=val[3]*reg4;
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
    T reg0=1-var_inter[1]; T reg1=elem.pos(0)[0]*reg0; T reg2=elem.pos(0)[1]*reg0; T reg3=elem.pos(1)[1]*reg0; T reg4=elem.pos(1)[0]*reg0;
    reg4=reg4-reg1; T reg5=var_inter[1]*elem.pos(2)[1]; T reg6=elem.pos(0)[2]*reg0; T reg7=elem.pos(1)[2]*reg0; reg3=reg3-reg2;
    T reg8=var_inter[1]*elem.pos(2)[0]; T reg9=var_inter[1]*elem.pos(3)[0]; reg5=reg3+reg5; reg3=var_inter[1]*elem.pos(2)[2]; T reg10=var_inter[1]*elem.pos(3)[1];
    reg7=reg7-reg6; reg4=reg8+reg4; reg8=var_inter[1]*elem.pos(3)[2]; reg4=reg4-reg9; reg3=reg7+reg3;
    reg5=reg5-reg10; reg7=pow(reg5,2); T reg11=pow(reg4,2); reg3=reg3-reg8; T reg12=1-var_inter[0];
    T reg13=pow(reg3,2); T reg14=elem.pos(0)[1]*reg12; T reg15=var_inter[0]*elem.pos(1)[1]; reg7=reg11+reg7; reg11=elem.pos(0)[0]*reg12;
    T reg16=var_inter[0]*elem.pos(1)[0]; T reg17=var_inter[0]*elem.pos(2)[1]; T reg18=var_inter[0]*elem.pos(2)[0]; T reg19=elem.pos(0)[2]*reg12; T reg20=reg11+reg16;
    T reg21=var_inter[0]*elem.pos(1)[2]; reg7=reg13+reg7; reg13=reg15+reg14; reg17=reg17-reg13; reg18=reg18-reg20;
    T reg22=reg21+reg19; T reg23=reg12*elem.pos(3)[1]; T reg24=var_inter[0]*elem.pos(2)[2]; reg7=pow(reg7,0.5); T reg25=reg12*elem.pos(3)[0];
    reg17=reg23+reg17; reg24=reg24-reg22; reg23=reg12*elem.pos(3)[2]; T reg26=reg5/reg7; T reg27=reg4/reg7;
    reg25=reg18+reg25; reg7=reg3/reg7; reg18=reg17*reg26; T reg28=reg27*reg25; reg23=reg24+reg23;
    reg18=reg28+reg18; reg24=reg23*reg7; reg24=reg18+reg24; reg18=reg24*reg27; reg28=reg24*reg26;
    T reg29=reg24*reg7; reg18=reg25-reg18; reg28=reg17-reg28; T reg30=pow(reg28,2); T reg31=pow(reg18,2);
    reg29=reg23-reg29; T reg32=pow(reg29,2); reg30=reg31+reg30; reg30=reg32+reg30; reg30=pow(reg30,0.5);
    reg18=reg18/reg30; reg28=reg28/reg30; reg25=reg18*reg25; reg31=reg5*reg28; reg28=reg17*reg28;
    reg27=reg27*reg4; reg26=reg5*reg26; reg30=reg29/reg30; reg18=reg4*reg18; reg28=reg25+reg28;
    reg7=reg7*reg3; reg26=reg27+reg26; reg3=reg3*reg30; reg18=reg31+reg18; reg30=reg23*reg30;
    reg7=reg26+reg7; reg3=reg18+reg3; reg28=reg30+reg28; reg4=reg24*reg3; reg5=reg28*reg7;
    reg4=reg5-reg4; return reg4;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Quad,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.78867513459481286553*elem.pos(0)[0]; T reg1=0.78867513459481286553*elem.pos(1)[1]; T reg2=0.21132486540518713447*elem.pos(0)[1]; T reg3=0.21132486540518713447*elem.pos(1)[1]; T reg4=0.78867513459481286553*elem.pos(0)[1];
    T reg5=0.78867513459481286553*elem.pos(1)[0]; T reg6=0.21132486540518713447*elem.pos(0)[0]; T reg7=0.21132486540518713447*elem.pos(1)[0]; T reg8=reg3+reg4; reg3=reg3-reg2;
    T reg9=reg6+reg5; T reg10=0.21132486540518713447*elem.pos(2)[1]; T reg11=0.21132486540518713447*elem.pos(2)[0]; T reg12=reg7+reg0; reg2=reg2+reg1;
    T reg13=0.78867513459481286553*elem.pos(2)[1]; T reg14=0.78867513459481286553*elem.pos(2)[0]; reg6=reg7-reg6; reg7=0.044658198738520458147*elem.pos(1)[1]; T reg15=0.16666666666666667632*elem.pos(0)[1];
    T reg16=0.16666666666666667632*elem.pos(1)[1]; T reg17=0.044658198738520458147*elem.pos(0)[1]; T reg18=0.16666666666666667632*elem.pos(1)[0]; T reg19=0.044658198738520458147*elem.pos(0)[0]; reg8=reg10-reg8;
    reg12=reg11-reg12; T reg20=0.044658198738520458147*elem.pos(1)[0]; T reg21=0.16666666666666667632*elem.pos(0)[0]; reg0=reg5-reg0; reg4=reg1-reg4;
    reg1=0.78867513459481286553*elem.pos(3)[0]; reg5=0.78867513459481286553*elem.pos(3)[1]; reg6=reg6+reg14; T reg22=0.21132486540518713447*elem.pos(3)[0]; reg3=reg13+reg3;
    reg2=reg13-reg2; reg13=0.21132486540518713447*elem.pos(3)[1]; reg9=reg14-reg9; reg8=reg5+reg8; reg14=0.16666666666666667632*elem.pos(2)[1];
    reg7=reg15+reg7; T reg23=0.6220084679281461892*elem.pos(1)[1]; reg2=reg2+reg13; reg12=reg1+reg12; reg5=reg3-reg5;
    reg3=0.6220084679281461892*elem.pos(1)[0]; T reg24=0.6220084679281461892*elem.pos(2)[1]; reg17=reg17+reg16; reg9=reg9+reg22; reg0=reg11+reg0;
    reg11=0.6220084679281461892*elem.pos(2)[0]; reg19=reg18+reg19; reg4=reg10+reg4; reg10=0.16666666666666667632*elem.pos(2)[0]; reg20=reg20+reg21;
    reg1=reg6-reg1; reg6=reg1*reg8; reg1=reg1*reg2; T reg25=0.6220084679281461892*elem.pos(0)[1]; reg23=reg15+reg23;
    reg22=reg0-reg22; reg0=0.16666666666666667632*elem.pos(3)[0]; reg11=reg19+reg11; reg15=0.6220084679281461892*elem.pos(0)[0]; reg19=0.6220084679281461892*elem.pos(3)[1];
    reg7=reg7+reg14; T reg26=reg5*reg12; reg21=reg3+reg21; reg5=reg5*reg9; reg13=reg4-reg13;
    reg3=0.6220084679281461892*elem.pos(3)[0]; reg4=0.16666666666666667632*elem.pos(3)[1]; reg24=reg17+reg24; reg20=reg20+reg10; reg5=reg1-reg5;
    reg9=reg13*reg9; reg1=0.044658198738520458147*elem.pos(2)[1]; reg25=reg16+reg25; reg11=reg11+reg0; reg16=0.044658198738520458147*elem.pos(3)[1];
    reg23=reg14+reg23; reg2=reg2*reg22; reg19=reg7+reg19; reg10=reg21+reg10; reg24=reg24+reg4;
    reg7=0.044658198738520458147*elem.pos(3)[0]; reg26=reg6-reg26; reg18=reg15+reg18; reg3=reg20+reg3; reg6=0.044658198738520458147*elem.pos(2)[0];
    reg11=reg5*reg11; reg22=reg8*reg22; reg12=reg13*reg12; reg6=reg18+reg6; reg3=reg26*reg3;
    reg9=reg2-reg9; reg7=reg10+reg7; reg24=reg24*reg5; reg19=reg19*reg26; reg1=reg25+reg1;
    reg16=reg23+reg16; reg3=0.25*reg3; reg5=0.25*reg5; reg7=reg9*reg7; reg12=reg22-reg12;
    reg0=reg6+reg0; reg26=0.25*reg26; reg24=0.25*reg24; reg19=0.25*reg19; reg16=reg9*reg16;
    reg11=0.25*reg11; reg1=reg4+reg1; reg7=0.25*reg7; reg3=reg11+reg3; reg0=reg12*reg0;
    reg1=reg12*reg1; reg26=reg5+reg26; reg9=0.25*reg9; reg19=reg24+reg19; reg16=0.25*reg16;
    reg9=reg26+reg9; reg12=0.25*reg12; reg0=0.25*reg0; reg16=reg19+reg16; reg1=0.25*reg1;
    reg3=reg7+reg3; reg12=reg9+reg12; reg0=reg3+reg0; reg1=reg16+reg1; res[0]=reg0/reg12;
    res[1]=reg1/reg12;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Quad,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.21132486540518713447*elem.pos(0)[1]; T reg1=0.21132486540518713447*elem.pos(1)[1]; T reg2=0.21132486540518713447*elem.pos(1)[0]; T reg3=0.21132486540518713447*elem.pos(0)[0]; T reg4=0.78867513459481286553*elem.pos(1)[1];
    T reg5=0.78867513459481286553*elem.pos(1)[0]; T reg6=reg2-reg3; T reg7=0.78867513459481286553*elem.pos(2)[1]; T reg8=0.78867513459481286553*elem.pos(0)[0]; T reg9=0.78867513459481286553*elem.pos(0)[1];
    T reg10=0.78867513459481286553*elem.pos(2)[0]; T reg11=reg1-reg0; T reg12=0.21132486540518713447*elem.pos(1)[2]; T reg13=0.21132486540518713447*elem.pos(0)[2]; reg11=reg7+reg11;
    T reg14=0.78867513459481286553*elem.pos(3)[1]; T reg15=reg12-reg13; T reg16=0.78867513459481286553*elem.pos(2)[2]; T reg17=0.78867513459481286553*elem.pos(3)[0]; reg6=reg6+reg10;
    T reg18=0.78867513459481286553*elem.pos(1)[2]; T reg19=0.21132486540518713447*elem.pos(2)[0]; T reg20=0.21132486540518713447*elem.pos(2)[1]; T reg21=0.78867513459481286553*elem.pos(0)[2]; T reg22=reg5-reg8;
    T reg23=reg4-reg9; T reg24=0.21132486540518713447*elem.pos(3)[1]; T reg25=0.21132486540518713447*elem.pos(3)[0]; T reg26=0.21132486540518713447*elem.pos(2)[2]; reg22=reg19+reg22;
    T reg27=0.78867513459481286553*elem.pos(3)[2]; reg15=reg16+reg15; reg23=reg20+reg23; T reg28=reg18-reg21; reg11=reg11-reg14;
    reg6=reg6-reg17; T reg29=0.21132486540518713447*elem.pos(3)[2]; T reg30=pow(reg11,2); reg15=reg15-reg27; T reg31=pow(reg6,2);
    reg22=reg22-reg25; reg28=reg26+reg28; reg23=reg23-reg24; reg28=reg28-reg29; T reg32=pow(reg23,2);
    T reg33=pow(reg22,2); T reg34=pow(reg15,2); reg30=reg31+reg30; reg32=reg33+reg32; reg9=reg1+reg9;
    reg8=reg2+reg8; reg1=pow(reg28,2); reg4=reg0+reg4; reg34=reg30+reg34; reg5=reg3+reg5;
    reg8=reg19-reg8; reg4=reg7-reg4; reg34=pow(reg34,0.5); reg9=reg20-reg9; reg18=reg13+reg18;
    reg5=reg10-reg5; reg1=reg32+reg1; reg21=reg12+reg21; reg0=reg11/reg34; reg2=reg6/reg34;
    reg21=reg26-reg21; reg1=pow(reg1,0.5); reg9=reg14+reg9; reg25=reg5+reg25; reg18=reg16-reg18;
    reg24=reg4+reg24; reg8=reg17+reg8; reg3=reg0*reg9; reg4=reg2*reg8; reg21=reg27+reg21;
    reg5=reg2*reg25; reg34=reg15/reg34; reg7=reg0*reg24; reg10=reg23/reg1; reg29=reg18+reg29;
    reg12=reg22/reg1; reg13=reg25*reg12; reg1=reg28/reg1; reg7=reg5+reg7; reg5=reg34*reg29;
    reg3=reg4+reg3; reg4=reg24*reg10; reg14=reg34*reg21; reg4=reg13+reg4; reg14=reg3+reg14;
    reg3=reg9*reg10; reg13=reg29*reg1; reg16=reg8*reg12; reg5=reg7+reg5; reg7=reg2*reg5;
    reg17=reg0*reg5; reg3=reg16+reg3; reg16=reg21*reg1; reg18=reg0*reg14; reg19=reg2*reg14;
    reg13=reg4+reg13; reg4=reg12*reg13; reg20=reg34*reg14; reg18=reg9-reg18; reg19=reg8-reg19;
    reg26=reg10*reg13; reg7=reg25-reg7; reg16=reg3+reg16; reg17=reg24-reg17; reg3=reg34*reg5;
    reg20=reg21-reg20; reg27=pow(reg7,2); reg30=pow(reg18,2); reg31=pow(reg19,2); reg32=reg12*reg16;
    reg33=pow(reg17,2); T reg35=reg10*reg16; reg4=reg25-reg4; reg26=reg24-reg26; reg3=reg29-reg3;
    T reg36=reg1*reg13; T reg37=pow(reg3,2); T reg38=pow(reg20,2); reg30=reg31+reg30; reg36=reg29-reg36;
    reg31=reg1*reg16; T reg39=pow(reg26,2); reg33=reg27+reg33; reg32=reg8-reg32; reg35=reg9-reg35;
    reg27=pow(reg4,2); T reg40=pow(reg35,2); reg31=reg21-reg31; T reg41=pow(reg32,2); reg37=reg33+reg37;
    reg39=reg27+reg39; reg38=reg30+reg38; reg27=pow(reg36,2); reg38=pow(reg38,0.5); reg30=pow(reg31,2);
    reg40=reg41+reg40; reg37=pow(reg37,0.5); reg27=reg39+reg27; reg30=reg40+reg30; reg17=reg17/reg37;
    reg27=pow(reg27,0.5); reg7=reg7/reg37; reg18=reg18/reg38; reg19=reg19/reg38; reg4=reg4/reg27;
    reg26=reg26/reg27; reg2=reg6*reg2; reg33=reg11*reg17; reg0=reg11*reg0; reg39=reg8*reg19;
    reg40=reg9*reg18; reg38=reg20/reg38; reg19=reg6*reg19; reg18=reg11*reg18; reg11=reg25*reg7;
    reg17=reg24*reg17; reg37=reg3/reg37; reg7=reg6*reg7; reg30=pow(reg30,0.5); reg10=reg23*reg10;
    reg34=reg15*reg34; reg0=reg2+reg0; reg25=reg25*reg4; reg24=reg24*reg26; reg27=reg36/reg27;
    reg4=reg22*reg4; reg26=reg23*reg26; reg12=reg22*reg12; reg2=0.044658198738520458147*elem.pos(1)[1]; reg3=0.044658198738520458147*elem.pos(0)[1];
    reg6=0.16666666666666667632*elem.pos(1)[1]; reg20=reg15*reg37; reg33=reg7+reg33; reg7=0.16666666666666667632*elem.pos(1)[0]; reg36=0.044658198738520458147*elem.pos(0)[0];
    reg41=0.16666666666666667632*elem.pos(0)[1]; reg37=reg29*reg37; T reg42=0.044658198738520458147*elem.pos(1)[2]; T reg43=0.16666666666666667632*elem.pos(0)[2]; reg17=reg11+reg17;
    reg40=reg39+reg40; reg11=reg21*reg38; reg39=0.044658198738520458147*elem.pos(1)[0]; reg18=reg19+reg18; reg38=reg15*reg38;
    reg15=0.16666666666666667632*elem.pos(0)[0]; reg19=0.044658198738520458147*elem.pos(0)[2]; T reg44=0.16666666666666667632*elem.pos(1)[2]; reg35=reg35/reg30; reg32=reg32/reg30;
    T reg45=0.6220084679281461892*elem.pos(1)[1]; reg2=reg2+reg41; reg19=reg44+reg19; T reg46=0.6220084679281461892*elem.pos(2)[2]; T reg47=0.16666666666666667632*elem.pos(2)[1];
    reg3=reg6+reg3; T reg48=0.6220084679281461892*elem.pos(2)[1]; T reg49=0.16666666666666667632*elem.pos(2)[2]; reg42=reg42+reg43; T reg50=0.6220084679281461892*elem.pos(1)[2];
    reg23=reg23*reg35; reg22=reg22*reg32; reg30=reg31/reg30; reg35=reg9*reg35; reg32=reg8*reg32;
    reg10=reg12+reg10; reg20=reg33+reg20; reg1=reg28*reg1; reg36=reg36+reg7; reg8=0.6220084679281461892*elem.pos(2)[0];
    reg34=reg0+reg34; reg24=reg25+reg24; reg29=reg29*reg27; reg37=reg17+reg37; reg11=reg40+reg11;
    reg26=reg4+reg26; reg27=reg28*reg27; reg0=0.16666666666666667632*elem.pos(2)[0]; reg4=0.6220084679281461892*elem.pos(1)[0]; reg39=reg15+reg39;
    reg38=reg18+reg38; reg42=reg49+reg42; reg9=0.6220084679281461892*elem.pos(3)[2]; reg11=reg34*reg11; reg50=reg43+reg50;
    reg28=reg28*reg30; reg23=reg22+reg23; reg38=reg14*reg38; reg37=reg34*reg37; reg3=reg48+reg3;
    reg12=0.16666666666666667632*elem.pos(3)[1]; reg14=0.6220084679281461892*elem.pos(3)[0]; reg39=reg39+reg0; reg2=reg47+reg2; reg17=0.6220084679281461892*elem.pos(3)[1];
    reg45=reg41+reg45; reg18=0.16666666666666667632*elem.pos(3)[2]; reg19=reg46+reg19; reg22=0.6220084679281461892*elem.pos(0)[1]; reg20=reg5*reg20;
    reg29=reg24+reg29; reg1=reg10+reg1; reg5=0.16666666666666667632*elem.pos(3)[0]; reg8=reg36+reg8; reg4=reg15+reg4;
    reg10=0.6220084679281461892*elem.pos(0)[0]; reg15=0.6220084679281461892*elem.pos(0)[2]; reg27=reg26+reg27; reg30=reg21*reg30; reg35=reg32+reg35;
    reg29=reg1*reg29; reg20=reg37-reg20; reg22=reg6+reg22; reg3=reg3+reg12; reg14=reg39+reg14;
    reg6=0.044658198738520458147*elem.pos(3)[2]; reg21=0.044658198738520458147*elem.pos(2)[0]; reg10=reg7+reg10; reg27=reg13*reg27; reg17=reg2+reg17;
    reg19=reg19+reg18; reg2=0.044658198738520458147*elem.pos(2)[1]; reg45=reg47+reg45; reg7=0.044658198738520458147*elem.pos(3)[1]; reg13=0.044658198738520458147*elem.pos(2)[2];
    reg30=reg35+reg30; reg38=reg11-reg38; reg28=reg23+reg28; reg50=reg49+reg50; reg15=reg44+reg15;
    reg9=reg42+reg9; reg4=reg0+reg4; reg8=reg8+reg5; reg0=0.044658198738520458147*elem.pos(3)[0]; reg30=reg1*reg30;
    reg8=reg8*reg20; reg22=reg2+reg22; reg0=reg4+reg0; reg14=reg14*reg38; reg3=reg20*reg3;
    reg27=reg29-reg27; reg28=reg16*reg28; reg7=reg45+reg7; reg15=reg13+reg15; reg6=reg50+reg6;
    reg19=reg20*reg19; reg17=reg38*reg17; reg9=reg38*reg9; reg21=reg10+reg21; reg19=0.25*reg19;
    reg6=reg27*reg6; reg15=reg18+reg15; reg9=0.25*reg9; reg28=reg30-reg28; reg21=reg5+reg21;
    reg14=0.25*reg14; reg38=0.25*reg38; reg20=0.25*reg20; reg8=0.25*reg8; reg3=0.25*reg3;
    reg17=0.25*reg17; reg7=reg27*reg7; reg22=reg12+reg22; reg0=reg0*reg27; reg17=reg3+reg17;
    reg7=0.25*reg7; reg15=reg28*reg15; reg6=0.25*reg6; reg0=0.25*reg0; reg27=0.25*reg27;
    reg38=reg20+reg38; reg22=reg28*reg22; reg9=reg19+reg9; reg21=reg21*reg28; reg14=reg8+reg14;
    reg0=reg14+reg0; reg6=reg9+reg6; reg21=0.25*reg21; reg27=reg38+reg27; reg28=0.25*reg28;
    reg7=reg17+reg7; reg22=0.25*reg22; reg15=0.25*reg15; reg15=reg6+reg15; reg21=reg0+reg21;
    reg28=reg27+reg28; reg22=reg7+reg22; res[0]=reg21/reg28; res[1]=reg22/reg28; res[2]=reg15/reg28;

    return res;
}
}
#endif // LMT_QUAD
