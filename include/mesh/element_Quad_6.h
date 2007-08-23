#ifndef LMT_QUAD_6
#define LMT_QUAD_6
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_6 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 13, 26, 39, 52, 65, 78, 91, 104, 117, }; // fonction de lordre du poly
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
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Quad_6 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=0.5*nodes[1]->pos[0]; T reg1=0.5*nodes[0]->pos[0]; T reg2=0.5*nodes[1]->pos[1]; T reg3=0.5*nodes[0]->pos[1]; reg1=reg0-reg1;
    reg0=0.5*nodes[3]->pos[0]; reg3=reg2-reg3; reg2=0.5*nodes[3]->pos[1]; reg2=reg3-reg2; reg3=0.5*nodes[2]->pos[0];
    T reg4=0.5*nodes[2]->pos[1]; reg0=reg1-reg0; reg3=reg0+reg3; reg0=nodes[5]->pos[1]-nodes[4]->pos[1]; reg1=nodes[5]->pos[0]-nodes[4]->pos[0];
    reg4=reg2+reg4; reg3=reg0*reg3; reg4=reg1*reg4; T det_jac=reg3-reg4;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[3],nodes[2],nodes[1],nodes[0],nodes[5],nodes[4]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=reg0*var_inter[0]; T reg3=reg1*reg0; reg1=reg1+reg0;
    reg0=reg0-var_inter[0]; T reg4=var_inter[0]-0.5; reg0=4*reg0; T reg5=reg4+var_inter[0]; T reg6=1-var_inter[1];
    reg1=2*reg1; reg2=4*reg2; reg3=2*reg3; reg4=reg4*var_inter[0]; T reg7=reg6*reg1;
    reg4=2*reg4; T reg8=reg6*reg0; T reg9=reg6*reg3; T reg10=reg2*reg6; reg5=2*reg5;
    T reg11=pos_nodes[4][0]*reg10; T reg12=reg9*pos_nodes[0][0]; T reg13=reg7*pos_nodes[0][1]; T reg14=pos_nodes[4][1]*reg8; T reg15=reg3*pos_nodes[0][0];
    T reg16=reg2*pos_nodes[4][1]; reg8=pos_nodes[4][0]*reg8; reg7=reg7*pos_nodes[0][0]; T reg17=reg3*pos_nodes[0][1]; T reg18=reg4*reg6;
    T reg19=reg9*pos_nodes[0][1]; T reg20=reg2*pos_nodes[4][0]; reg6=reg6*reg5; T reg21=pos_nodes[4][1]*reg10; T reg22=pos_nodes[1][0]*reg18;
    T reg23=pos_nodes[1][1]*reg18; reg12=reg11+reg12; reg21=reg19+reg21; reg11=reg3*var_inter[1]; reg13=reg14-reg13;
    reg1=reg1*var_inter[1]; reg14=reg4*pos_nodes[1][0]; reg19=pos_nodes[1][0]*reg6; reg6=pos_nodes[1][1]*reg6; reg7=reg8-reg7;
    reg20=reg15+reg20; reg17=reg16+reg17; reg8=reg4*pos_nodes[1][1]; reg15=reg11*pos_nodes[3][0]; reg21=reg23+reg21;
    reg16=pos_nodes[3][1]*reg3; reg8=reg17+reg8; reg17=reg11*pos_nodes[3][1]; reg6=reg13+reg6; reg13=pos_nodes[3][1]*reg1;
    reg14=reg20+reg14; reg12=reg22+reg12; reg19=reg7+reg19; reg1=pos_nodes[3][0]*reg1; reg7=reg2*var_inter[1];
    reg3=pos_nodes[3][0]*reg3; reg0=reg0*var_inter[1]; reg20=pos_nodes[5][1]*reg0; reg15=reg12+reg15; reg21=reg17+reg21;
    reg12=reg2*pos_nodes[5][0]; reg2=reg2*pos_nodes[5][1]; reg17=reg7*pos_nodes[5][0]; reg5=reg5*var_inter[1]; reg13=reg6-reg13;
    reg0=pos_nodes[5][0]*reg0; reg6=reg7*pos_nodes[5][1]; reg14=reg3-reg14; reg3=reg4*var_inter[1]; reg1=reg19-reg1;
    reg8=reg16-reg8; reg13=reg20+reg13; reg21=reg6+reg21; reg8=reg2+reg8; reg2=reg3*pos_nodes[2][0];
    reg1=reg0+reg1; reg14=reg12+reg14; reg0=reg4*pos_nodes[2][1]; reg6=pos_nodes[2][1]*reg5; reg5=pos_nodes[2][0]*reg5;
    reg17=reg15+reg17; reg4=reg4*pos_nodes[2][0]; reg12=reg3*pos_nodes[2][1]; reg21=reg12+reg21; reg2=reg17+reg2;
    reg13=reg6+reg13; reg14=reg4+reg14; reg1=reg5+reg1; reg8=reg0+reg8; reg0=reg1*reg8;
    reg4=reg14*reg13; reg5=var_inter[0]*reg13; reg6=reg1*var_inter[0]; reg21=pos[1]-reg21; reg2=pos[0]-reg2;
    reg4=reg0-reg4; reg5=reg21+reg5; reg12=var_inter[1]*reg8; reg6=reg2+reg6; reg2=var_inter[1]*reg14;
    reg6=reg2+reg6; reg5=reg12+reg5; reg2=reg8/reg4; reg12=reg13/reg4; reg15=reg14/reg4;
    reg4=reg1/reg4; reg2=reg6*reg2; reg15=reg5*reg15; reg12=reg6*reg12; reg4=reg5*reg4;
    var_inter[0]=reg2-reg15; var_inter[1]=reg4-reg12;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.5-var_inter[0]; T reg1=1-var_inter[0]; T reg2=reg1+reg0; T reg3=reg1-var_inter[0]; T reg4=reg1*var_inter[0];
    reg0=reg1*reg0; reg1=var_inter[0]-0.5; T reg5=reg1+var_inter[0]; reg2=2*reg2; reg3=4*reg3;
    reg4=4*reg4; reg0=2*reg0; reg1=reg1*var_inter[0]; T reg6=1-var_inter[1]; reg5=2*reg5;
    reg1=2*reg1; T reg7=reg6*reg4; T reg8=reg6*reg0; T reg9=reg6*reg3; T reg10=reg6*reg2;
    T reg11=reg6*reg5; T reg12=reg0*pos_nodes[0][0]; T reg13=pos_nodes[4][1]*reg4; T reg14=pos_nodes[0][0]*reg10; T reg15=pos_nodes[4][0]*reg9;
    T reg16=reg0*pos_nodes[0][1]; reg9=pos_nodes[4][1]*reg9; T reg17=reg8*pos_nodes[0][1]; reg6=reg1*reg6; T reg18=pos_nodes[4][0]*reg4;
    T reg19=pos_nodes[4][1]*reg7; reg10=pos_nodes[0][1]*reg10; T reg20=reg8*pos_nodes[0][0]; T reg21=pos_nodes[4][0]*reg7; reg10=reg9-reg10;
    reg9=reg1*pos_nodes[1][0]; reg2=var_inter[1]*reg2; reg20=reg21+reg20; reg21=pos_nodes[1][0]*reg11; T reg22=reg1*pos_nodes[1][1];
    reg11=pos_nodes[1][1]*reg11; T reg23=reg6*pos_nodes[1][0]; T reg24=reg0*var_inter[1]; reg14=reg15-reg14; reg18=reg12+reg18;
    reg13=reg16+reg13; reg12=pos_nodes[1][1]*reg6; reg17=reg19+reg17; reg15=pos_nodes[3][1]*reg0; reg16=reg4*var_inter[1];
    reg19=reg24*pos_nodes[3][0]; T reg25=reg24*pos_nodes[3][1]; reg0=pos_nodes[3][0]*reg0; T reg26=pos_nodes[3][0]*reg2; reg21=reg14+reg21;
    reg13=reg22+reg13; reg9=reg18+reg9; reg20=reg23+reg20; reg17=reg12+reg17; reg3=var_inter[1]*reg3;
    reg11=reg10+reg11; reg2=pos_nodes[3][1]*reg2; reg10=reg16*pos_nodes[5][1]; reg12=pos_nodes[5][1]*reg3; reg13=reg15-reg13;
    reg14=pos_nodes[5][1]*reg4; reg2=reg11-reg2; reg11=reg1*var_inter[1]; reg25=reg17+reg25; reg9=reg0-reg9;
    reg5=var_inter[1]*reg5; reg19=reg20+reg19; reg26=reg21-reg26; reg4=pos_nodes[5][0]*reg4; reg0=reg16*pos_nodes[5][0];
    reg3=pos_nodes[5][0]*reg3; reg13=reg14+reg13; reg14=reg11*pos_nodes[2][1]; reg15=reg1*pos_nodes[2][0]; reg2=reg12+reg2;
    reg0=reg19+reg0; reg12=pos_nodes[2][0]*reg5; reg5=pos_nodes[2][1]*reg5; reg26=reg3+reg26; reg3=reg11*pos_nodes[2][0];
    reg9=reg4+reg9; reg10=reg25+reg10; reg1=reg1*pos_nodes[2][1]; reg14=reg10+reg14; reg3=reg0+reg3;
    reg2=reg5+reg2; reg13=reg1+reg13; reg26=reg12+reg26; reg9=reg15+reg9; reg0=var_inter[0]*reg2;
    reg1=reg26*reg13; reg4=reg9*reg2; reg5=var_inter[0]*reg26; reg14=pos[1]-reg14; reg3=pos[0]-reg3;
    reg4=reg1-reg4; reg0=reg14+reg0; reg10=var_inter[1]*reg13; reg5=reg3+reg5; reg3=var_inter[1]*reg9;
    reg5=reg3+reg5; reg0=reg10+reg0; reg3=reg13/reg4; reg10=reg2/reg4; reg12=reg9/reg4;
    reg4=reg26/reg4; reg3=reg5*reg3; reg12=reg0*reg12; reg10=reg5*reg10; reg4=reg0*reg4;
    var_inter[0]+=reg3-reg12; var_inter[1]+=reg4-reg10;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=0.5-var_inter[0]; T reg1=1-var_inter[0]; T reg2=var_inter[0]-0.5; T reg3=var_inter[0]*reg1; reg0=reg1*reg0;
    reg2=var_inter[0]*reg2; reg3=4*reg3; reg0=2*reg0; reg1=1-var_inter[1]; reg2=2*reg2;
    T reg4=reg3*reg1; T reg5=reg0*reg1; reg4=val[4]*reg4; reg5=val[0]*reg5; reg1=reg2*reg1;
    reg1=val[1]*reg1; reg0=var_inter[1]*reg0; reg4=reg5+reg4; reg1=reg4+reg1; reg0=val[3]*reg0;
    reg3=var_inter[1]*reg3; reg0=reg1+reg0; reg3=val[5]*reg3; reg2=var_inter[1]*reg2; reg3=reg0+reg3;
    reg2=val[2]*reg2; res=reg3+reg2;

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Quad_6> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

}
#endif // LMT_QUAD_6
