#ifndef LMT_QUAD
#define LMT_QUAD
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad &elem) { /// order -> degre du polynome a integrer exactement
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
template<class TNode> void permutation_if_jac_neg(const Quad &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=0.5*nodes[1]->pos[0]; T reg1=0.5*nodes[0]->pos[0]; T reg2=0.5*nodes[1]->pos[1]; T reg3=0.5*nodes[0]->pos[1]; T reg4=reg0+reg1;
    T reg5=reg2-reg3; reg2=reg3+reg2; reg3=0.5*nodes[2]->pos[1]; T reg6=0.5*nodes[2]->pos[0]; reg1=reg0-reg1;
    reg0=0.5*nodes[3]->pos[0]; reg1=reg1+reg6; reg2=reg3-reg2; T reg7=0.5*nodes[3]->pos[1]; reg5=reg3+reg5;
    reg4=reg6-reg4; reg1=reg1-reg0; reg2=reg2+reg7; reg7=reg5-reg7; reg4=reg0+reg4;
    reg4=reg7*reg4; reg2=reg1*reg2; T det_jac=reg2-reg4;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[3],nodes[2],nodes[1]};
        for(unsigned i=0;i<4;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
<<<<<<< HEAD:include/mesh/element_Quad.h
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=reg0*reg1; T reg3=reg1*var_inter[0]; T reg4=pos_nodes[0][0]*reg0;
    T reg5=var_inter[0]*pos_nodes[1][0]; T reg6=pos_nodes[0][0]*reg2; T reg7=reg3*pos_nodes[1][0]; T reg8=reg1*pos_nodes[1][1]; T reg9=reg1*pos_nodes[0][1];
    T reg10=reg0*pos_nodes[0][1]; T reg11=pos_nodes[1][1]*var_inter[0]; T reg12=reg2*pos_nodes[0][1]; T reg13=reg3*pos_nodes[1][1]; T reg14=pos_nodes[0][0]*reg1;
    T reg15=reg1*pos_nodes[1][0]; T reg16=var_inter[0]*var_inter[1]; T reg17=pos_nodes[2][1]*var_inter[0]; reg11=reg10+reg11; reg10=reg16*pos_nodes[2][0];
    reg7=reg6+reg7; reg9=reg8-reg9; reg6=reg0*var_inter[1]; reg13=reg12+reg13; reg5=reg4+reg5;
    reg4=pos_nodes[2][0]*var_inter[0]; reg8=reg16*pos_nodes[2][1]; reg12=pos_nodes[2][1]*var_inter[1]; T reg18=pos_nodes[2][0]*var_inter[1]; reg14=reg15-reg14;
    reg15=pos_nodes[3][1]*var_inter[1]; reg11=reg17-reg11; reg17=reg0*pos_nodes[3][1]; reg8=reg13+reg8; reg13=reg6*pos_nodes[3][1];
    reg18=reg14+reg18; reg14=pos_nodes[3][0]*var_inter[1]; reg5=reg4-reg5; reg4=reg0*pos_nodes[3][0]; reg10=reg7+reg10;
    reg12=reg9+reg12; reg7=reg6*pos_nodes[3][0]; reg13=reg8+reg13; reg15=reg12-reg15; reg14=reg18-reg14;
    reg7=reg10+reg7; reg4=reg5+reg4; reg17=reg11+reg17; reg7=pos[0]-reg7; reg13=pos[1]-reg13;
    reg5=var_inter[0]*reg14; reg8=reg4*reg15; reg9=var_inter[0]*reg15; reg10=reg14*reg17; reg8=reg10-reg8;
    reg9=reg13+reg9; reg11=var_inter[1]*reg17; reg5=reg7+reg5; reg7=var_inter[1]*reg4; reg5=reg7+reg5;
    reg9=reg11+reg9; reg7=reg17/reg8; reg11=reg15/reg8; reg12=reg4/reg8; reg8=reg14/reg8;
    reg7=reg5*reg7; reg12=reg9*reg12; reg11=reg5*reg11; reg8=reg9*reg8; var_inter[0]=reg7-reg12;
    var_inter[1]=reg8-reg11;
=======
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=reg1*var_inter[0]; T reg3=reg0*reg1; T reg4=reg2*pos_nodes[1][1];
    T reg5=reg3*pos_nodes[0][1]; T reg6=var_inter[0]*pos_nodes[1][1]; T reg7=reg0*pos_nodes[0][1]; T reg8=reg1*pos_nodes[0][1]; T reg9=reg1*pos_nodes[1][1];
    T reg10=reg2*pos_nodes[1][0]; T reg11=pos_nodes[0][0]*reg3; T reg12=var_inter[0]*pos_nodes[1][0]; T reg13=var_inter[0]*var_inter[1]; T reg14=pos_nodes[0][0]*reg0;
    T reg15=reg1*pos_nodes[1][0]; T reg16=pos_nodes[0][0]*reg1; T reg17=reg0*var_inter[1]; T reg18=reg13*pos_nodes[2][1]; reg4=reg5+reg4;
    reg16=reg15-reg16; reg6=reg7+reg6; reg5=var_inter[1]*pos_nodes[2][0]; reg7=var_inter[0]*pos_nodes[2][1]; reg15=var_inter[1]*pos_nodes[2][1];
    reg12=reg14+reg12; reg14=var_inter[0]*pos_nodes[2][0]; reg10=reg11+reg10; reg11=reg13*pos_nodes[2][0]; reg8=reg9-reg8;
    reg5=reg16+reg5; reg12=reg14-reg12; reg9=reg0*pos_nodes[3][0]; reg6=reg7-reg6; reg7=reg0*pos_nodes[3][1];
    reg14=pos_nodes[3][0]*reg17; reg11=reg10+reg11; reg10=var_inter[1]*pos_nodes[3][1]; reg15=reg8+reg15; reg18=reg4+reg18;
    reg4=pos_nodes[3][1]*reg17; reg8=var_inter[1]*pos_nodes[3][0]; reg9=reg12+reg9; reg10=reg15-reg10; reg8=reg5-reg8;
    reg14=reg11+reg14; reg7=reg6+reg7; reg4=reg18+reg4; reg14=pos[0]-reg14; reg4=pos[1]-reg4;
    reg5=reg9*reg10; reg6=reg8*reg7; reg11=var_inter[0]*reg8; reg12=var_inter[0]*reg10; reg12=reg4+reg12;
    reg5=reg6-reg5; reg4=var_inter[1]*reg9; reg11=reg14+reg11; reg14=var_inter[1]*reg7; reg11=reg4+reg11;
    reg4=reg8/reg5; reg15=reg9/reg5; reg16=reg10/reg5; reg5=reg7/reg5; reg12=reg14+reg12;
    reg16=reg11*reg16; reg4=reg12*reg4; reg15=reg12*reg15; reg5=reg11*reg5; var_inter[0]=reg5-reg15;
    var_inter[1]=reg4-reg16;
>>>>>>> 512dc2050926bfccc64f86a01cb2ce23c8050af9:include/mesh/element_Quad.h

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
<<<<<<< HEAD:include/mesh/element_Quad.h
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=reg0*reg1; T reg3=var_inter[0]*reg1; T reg4=pos_nodes[1][1]*reg1;
    T reg5=reg3*pos_nodes[1][0]; T reg6=pos_nodes[0][0]*reg2; T reg7=var_inter[0]*pos_nodes[1][0]; T reg8=pos_nodes[0][0]*reg0; T reg9=pos_nodes[0][1]*reg1;
    T reg10=pos_nodes[0][1]*reg0; T reg11=pos_nodes[1][1]*var_inter[0]; T reg12=pos_nodes[0][1]*reg2; T reg13=reg3*pos_nodes[1][1]; T reg14=var_inter[0]*var_inter[1];
    T reg15=pos_nodes[0][0]*reg1; T reg16=pos_nodes[1][0]*reg1; T reg17=pos_nodes[2][1]*var_inter[1]; reg9=reg4-reg9; reg13=reg12+reg13;
    reg4=reg14*pos_nodes[2][0]; reg5=reg6+reg5; reg6=reg14*pos_nodes[2][1]; reg12=var_inter[1]*reg0; T reg18=pos_nodes[2][1]*var_inter[0];
    reg7=reg8+reg7; reg8=pos_nodes[2][0]*var_inter[0]; reg15=reg16-reg15; reg16=pos_nodes[2][0]*var_inter[1]; reg11=reg10+reg11;
    reg10=pos_nodes[3][1]*var_inter[1]; reg17=reg9+reg17; reg11=reg18-reg11; reg9=pos_nodes[3][1]*reg0; reg18=reg12*pos_nodes[3][0];
    reg4=reg5+reg4; reg6=reg13+reg6; reg5=reg12*pos_nodes[3][1]; reg13=pos_nodes[3][0]*reg0; reg7=reg8-reg7;
    reg16=reg15+reg16; reg8=pos_nodes[3][0]*var_inter[1]; reg5=reg6+reg5; reg9=reg11+reg9; reg10=reg17-reg10;
    reg18=reg4+reg18; reg13=reg7+reg13; reg8=reg16-reg8; reg18=pos[0]-reg18; reg5=pos[1]-reg5;
    reg4=reg8*reg9; reg6=reg8*var_inter[0]; reg7=reg13*reg10; reg11=var_inter[0]*reg10; reg7=reg4-reg7;
    reg11=reg5+reg11; reg5=var_inter[1]*reg9; reg6=reg18+reg6; reg15=var_inter[1]*reg13; reg6=reg15+reg6;
    reg11=reg5+reg11; reg5=reg9/reg7; reg15=reg10/reg7; reg16=reg13/reg7; reg7=reg8/reg7;
    reg5=reg6*reg5; reg16=reg11*reg16; reg15=reg6*reg15; reg7=reg11*reg7; var_inter[0]+=reg5-reg16;
    var_inter[1]+=reg7-reg15;
=======
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=reg0*reg1; T reg3=reg1*var_inter[0]; T reg4=reg1*pos_nodes[1][1];
    T reg5=reg1*pos_nodes[0][1]; T reg6=var_inter[0]*var_inter[1]; T reg7=reg0*pos_nodes[0][1]; T reg8=var_inter[0]*pos_nodes[1][1]; T reg9=reg2*pos_nodes[0][1];
    T reg10=reg3*pos_nodes[1][1]; T reg11=reg1*pos_nodes[1][0]; T reg12=pos_nodes[0][0]*reg1; T reg13=reg3*pos_nodes[1][0]; T reg14=pos_nodes[0][0]*reg2;
    T reg15=pos_nodes[0][0]*reg0; T reg16=var_inter[0]*pos_nodes[1][0]; reg12=reg11-reg12; reg11=reg6*pos_nodes[2][1]; reg10=reg9+reg10;
    reg9=var_inter[1]*pos_nodes[2][0]; reg8=reg7+reg8; reg7=var_inter[0]*pos_nodes[2][1]; T reg17=var_inter[0]*pos_nodes[2][0]; reg13=reg14+reg13;
    reg14=reg6*pos_nodes[2][0]; reg5=reg4-reg5; reg4=var_inter[1]*pos_nodes[2][1]; reg16=reg15+reg16; reg15=reg0*var_inter[1];
    reg14=reg13+reg14; reg13=reg15*pos_nodes[3][0]; T reg18=reg15*pos_nodes[3][1]; reg11=reg10+reg11; reg16=reg17-reg16;
    reg10=reg0*pos_nodes[3][0]; reg9=reg12+reg9; reg12=var_inter[1]*pos_nodes[3][1]; reg17=reg0*pos_nodes[3][1]; reg8=reg7-reg8;
    reg4=reg5+reg4; reg5=var_inter[1]*pos_nodes[3][0]; reg12=reg4-reg12; reg10=reg16+reg10; reg5=reg9-reg5;
    reg13=reg14+reg13; reg17=reg8+reg17; reg18=reg11+reg18; reg4=var_inter[0]*reg12; reg13=pos[0]-reg13;
    reg18=pos[1]-reg18; reg7=reg5*reg17; reg8=reg10*reg12; reg9=reg5*var_inter[0]; reg11=reg10*var_inter[1];
    reg8=reg7-reg8; reg4=reg18+reg4; reg14=var_inter[1]*reg17; reg9=reg13+reg9; reg13=reg12/reg8;
    reg16=reg10/reg8; reg18=reg5/reg8; reg8=reg17/reg8; reg4=reg14+reg4; reg9=reg11+reg9;
    reg8=reg9*reg8; reg16=reg4*reg16; reg13=reg9*reg13; reg18=reg4*reg18; var_inter[0]+=reg8-reg16;
    var_inter[1]+=reg18-reg13;
>>>>>>> 512dc2050926bfccc64f86a01cb2ce23c8050af9:include/mesh/element_Quad.h

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=reg0*reg1; reg1=var_inter[0]*reg1; T reg3=val[0]*reg2;
    T reg4=val[1]*reg1; T reg5=var_inter[0]*var_inter[1]; reg0=var_inter[1]*reg0; T reg6=val[2]*reg5; reg4=reg3+reg4;
    reg6=reg4+reg6; reg3=val[3]*reg0; res=reg6+reg3;

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[0]+val[1]; reg0=val[2]+reg0; res=val[3]+reg0;

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
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=reg0*reg1; T reg3=var_inter[0]*reg2; reg3=var_inter[1]*reg3;
    reg3=16*reg3; T reg4=1-reg3; reg1=var_inter[0]*reg1; T reg5=reg2*reg4; T reg6=var_inter[0]*var_inter[1];
    T reg7=reg1*reg4; reg5=val[0]*reg5; reg7=val[1]*reg7; T reg8=reg6*reg4; reg0=var_inter[1]*reg0;
    reg8=val[2]*reg8; reg4=reg0*reg4; reg7=reg5+reg7; reg8=reg7+reg8; reg4=val[3]*reg4;
    reg4=reg8+reg4; reg3=val[4]*reg3; res=reg4+reg3;

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Quad> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

}
#endif // LMT_QUAD
