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
    T reg0=0.5*nodes[1]->pos[1]; T reg1=0.5*nodes[0]->pos[1]; T reg2=0.5*nodes[0]->pos[0]; T reg3=0.5*nodes[1]->pos[0]; T reg4=0.5*nodes[3]->pos[1];
    reg0=reg0-reg1; T reg5=0.5*nodes[3]->pos[0]; reg3=reg3-reg2; T reg6=0.5*nodes[2]->pos[1]; reg4=reg0-reg4;
    reg0=0.5*nodes[2]->pos[0]; reg5=reg3-reg5; reg3=nodes[5]->pos[1]-nodes[4]->pos[1]; reg0=reg5+reg0; reg6=reg4+reg6;
    reg4=nodes[5]->pos[0]-nodes[4]->pos[0]; reg3=reg0*reg3; reg4=reg6*reg4; T det_jac=reg3-reg4;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[3],nodes[2],nodes[1],nodes[0],nodes[5],nodes[4]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=reg0*var_inter[0]; T reg3=reg0-var_inter[0]; T reg4=var_inter[0]-0.5;
    T reg5=reg0+reg1; reg1=reg0*reg1; reg3=4*reg3; reg0=2*reg5; T reg6=reg4+var_inter[0];
    reg1=2*reg1; reg2=4*reg2; reg4=reg4*var_inter[0]; T reg7=1-var_inter[1]; T reg8=reg7*reg3;
    T reg9=reg7*reg0; reg4=2*reg4; reg6=2*reg6; T reg10=reg2*reg7; T reg11=reg7*reg1;
    T reg12=reg1*pos_nodes[0][1]; T reg13=reg2*pos_nodes[4][1]; T reg14=pos_nodes[0][1]*reg9; T reg15=pos_nodes[0][0]*reg9; T reg16=pos_nodes[4][0]*reg8;
    T reg17=reg7*reg6; T reg18=pos_nodes[4][1]*reg8; T reg19=reg11*pos_nodes[0][1]; T reg20=reg10*pos_nodes[4][1]; T reg21=pos_nodes[0][0]*reg1;
    T reg22=reg2*pos_nodes[4][0]; T reg23=pos_nodes[0][0]*reg11; T reg24=pos_nodes[4][0]*reg10; reg7=reg4*reg7; T reg25=reg4*pos_nodes[1][1];
    reg13=reg12+reg13; reg12=pos_nodes[1][1]*reg17; reg14=reg18-reg14; reg18=pos_nodes[1][0]*reg7; reg24=reg23+reg24;
    reg23=reg1*var_inter[1]; reg20=reg19+reg20; reg19=pos_nodes[1][1]*reg7; T reg26=reg4*pos_nodes[1][0]; reg22=reg21+reg22;
    reg21=var_inter[1]*reg0; reg15=reg16-reg15; reg16=pos_nodes[1][0]*reg17; reg3=var_inter[1]*reg3; T reg27=pos_nodes[3][1]*reg1;
    reg25=reg13+reg25; reg13=pos_nodes[3][1]*reg21; reg12=reg14+reg12; reg14=pos_nodes[3][0]*reg23; reg18=reg24+reg18;
    reg16=reg15+reg16; reg15=pos_nodes[3][0]*reg21; reg24=pos_nodes[3][0]*reg1; T reg28=reg2*var_inter[1]; T reg29=pos_nodes[3][1]*reg23;
    reg19=reg20+reg19; reg26=reg22+reg26; reg20=reg4*var_inter[1]; reg25=reg27-reg25; reg22=reg2*pos_nodes[5][1];
    reg27=pos_nodes[5][1]*reg3; reg13=reg12-reg13; reg29=reg19+reg29; reg6=var_inter[1]*reg6; reg26=reg24-reg26;
    reg12=reg2*pos_nodes[5][0]; reg19=reg28*pos_nodes[5][0]; reg14=reg18+reg14; reg18=reg28*pos_nodes[5][1]; reg24=pos_nodes[5][0]*reg3;
    reg15=reg16-reg15; reg22=reg25+reg22; reg16=reg4*pos_nodes[2][1]; reg25=pos_nodes[2][1]*reg20; reg18=reg29+reg18;
    reg29=pos_nodes[2][1]*reg6; reg27=reg13+reg27; reg24=reg15+reg24; reg13=pos_nodes[2][0]*reg20; reg19=reg14+reg19;
    reg14=pos_nodes[2][0]*reg6; reg15=reg4*pos_nodes[2][0]; reg12=reg26+reg12; reg25=reg18+reg25; reg14=reg24+reg14;
    reg15=reg12+reg15; reg16=reg22+reg16; reg13=reg19+reg13; reg29=reg27+reg29; reg13=pos[0]-reg13;
    reg25=pos[1]-reg25; reg12=var_inter[0]*reg14; reg18=reg15*reg29; reg19=var_inter[0]*reg29; reg22=reg14*reg16;
    reg18=reg22-reg18; reg19=reg25+reg19; reg24=var_inter[1]*reg16; reg12=reg13+reg12; reg13=var_inter[1]*reg15;
    reg12=reg13+reg12; reg19=reg24+reg19; reg13=reg16/reg18; reg24=reg29/reg18; reg25=reg15/reg18;
    reg18=reg14/reg18; reg13=reg12*reg13; reg25=reg19*reg25; reg24=reg12*reg24; reg18=reg19*reg18;
    var_inter[0]=reg13-reg25; var_inter[1]=reg18-reg24;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.5-var_inter[0]; T reg1=1-var_inter[0]; T reg2=reg1*var_inter[0]; T reg3=reg1*reg0; T reg4=var_inter[0]-0.5;
    reg0=reg1+reg0; reg1=reg1-var_inter[0]; T reg5=2*reg0; T reg6=1-var_inter[1]; T reg7=reg4*var_inter[0];
    reg4=reg4+var_inter[0]; reg1=4*reg1; reg2=4*reg2; reg3=2*reg3; T reg8=reg6*reg1;
    T reg9=reg3*reg6; T reg10=reg6*reg5; T reg11=reg2*reg6; reg4=2*reg4; reg7=2*reg7;
    T reg12=pos_nodes[4][0]*reg2; T reg13=pos_nodes[4][1]*reg8; T reg14=pos_nodes[0][1]*reg10; T reg15=pos_nodes[0][0]*reg3; T reg16=reg11*pos_nodes[4][1];
    T reg17=pos_nodes[0][0]*reg10; T reg18=pos_nodes[4][0]*reg8; T reg19=reg6*reg4; T reg20=pos_nodes[0][0]*reg9; T reg21=reg3*pos_nodes[0][1];
    T reg22=pos_nodes[4][1]*reg2; T reg23=reg11*pos_nodes[4][0]; T reg24=reg9*pos_nodes[0][1]; reg6=reg7*reg6; T reg25=pos_nodes[1][1]*reg7;
    reg22=reg21+reg22; reg21=pos_nodes[1][1]*reg19; reg14=reg13-reg14; reg13=reg6*pos_nodes[1][0]; reg23=reg20+reg23;
    reg16=reg24+reg16; reg20=pos_nodes[1][1]*reg6; reg24=reg7*pos_nodes[1][0]; reg12=reg15+reg12; reg15=reg3*var_inter[1];
    T reg26=var_inter[1]*reg5; reg17=reg18-reg17; reg18=pos_nodes[1][0]*reg19; T reg27=pos_nodes[3][1]*reg3; reg25=reg22+reg25;
    reg22=pos_nodes[3][1]*reg26; reg21=reg14+reg21; reg1=var_inter[1]*reg1; reg14=pos_nodes[3][1]*reg15; reg13=reg23+reg13;
    reg23=reg2*var_inter[1]; T reg28=pos_nodes[3][0]*reg3; reg20=reg16+reg20; reg24=reg12+reg24; reg12=pos_nodes[3][0]*reg26;
    reg16=pos_nodes[3][0]*reg15; reg18=reg17+reg18; reg17=reg7*var_inter[1]; reg20=reg14+reg20; reg25=reg27-reg25;
    reg14=reg2*pos_nodes[5][1]; reg27=pos_nodes[5][1]*reg1; reg22=reg21-reg22; reg21=reg23*pos_nodes[5][1]; T reg29=pos_nodes[5][0]*reg1;
    reg4=var_inter[1]*reg4; reg24=reg28-reg24; reg28=reg2*pos_nodes[5][0]; reg12=reg18-reg12; reg18=reg23*pos_nodes[5][0];
    reg13=reg16+reg13; reg14=reg25+reg14; reg16=pos_nodes[2][1]*reg7; reg25=pos_nodes[2][1]*reg17; reg21=reg20+reg21;
    reg20=pos_nodes[2][1]*reg4; reg27=reg22+reg27; reg29=reg12+reg29; reg12=pos_nodes[2][0]*reg17; reg18=reg13+reg18;
    reg13=pos_nodes[2][0]*reg4; reg22=pos_nodes[2][0]*reg7; reg28=reg24+reg28; reg25=reg21+reg25; reg13=reg29+reg13;
    reg22=reg28+reg22; reg16=reg14+reg16; reg12=reg18+reg12; reg20=reg27+reg20; reg12=pos[0]-reg12;
    reg25=pos[1]-reg25; reg14=var_inter[0]*reg13; reg18=reg22*reg20; reg21=var_inter[0]*reg20; reg24=reg13*reg16;
    reg18=reg24-reg18; reg21=reg25+reg21; reg25=var_inter[1]*reg16; reg14=reg12+reg14; reg12=var_inter[1]*reg22;
    reg14=reg12+reg14; reg21=reg25+reg21; reg12=reg16/reg18; reg25=reg20/reg18; reg27=reg22/reg18;
    reg18=reg13/reg18; reg12=reg14*reg12; reg27=reg21*reg27; reg25=reg14*reg25; reg18=reg21*reg18;
    var_inter[0]+=reg12-reg27; var_inter[1]+=reg18-reg25;

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
    reg1=1-var_inter[1]; reg2=var_inter[0]*reg2; reg3=4*reg3; reg0=2*reg0; T reg4=reg3*reg1;
    T reg5=reg0*reg1; reg2=2*reg2; reg4=val[4]*reg4; reg5=val[0]*reg5; reg1=reg2*reg1;
    reg1=val[1]*reg1; reg0=var_inter[1]*reg0; reg4=reg5+reg4; reg0=val[3]*reg0; reg3=var_inter[1]*reg3;
    reg1=reg4+reg1; reg0=reg1+reg0; reg3=val[5]*reg3; reg2=var_inter[1]*reg2; reg3=reg0+reg3;
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
