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

    if ( nodes[0]->pos.size() != 2 )
        return;

    typedef typename TNode::T T;
    T reg0=0.5*nodes[1]->pos[0]; T reg1=0.5*nodes[0]->pos[0]; T reg2=0.5*nodes[0]->pos[1]; T reg3=0.5*nodes[1]->pos[1]; T reg4=reg3-reg2;
    T reg5=reg0+reg1; reg2=reg3+reg2; reg3=0.5*nodes[2]->pos[1]; T reg6=0.5*nodes[2]->pos[0]; reg1=reg0-reg1;
    reg0=0.5*nodes[3]->pos[0]; reg1=reg1+reg6; reg2=reg3-reg2; T reg7=0.5*nodes[3]->pos[1]; reg5=reg6-reg5;
    reg4=reg3+reg4; reg1=reg1-reg0; reg2=reg2+reg7; reg5=reg0+reg5; reg7=reg4-reg7;
    reg7=reg5*reg7; reg2=reg1*reg2; T det_jac=reg2-reg7;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[3],nodes[2],nodes[1]};
        for(unsigned i=0;i<4;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=pos_nodes[0][0]*reg0; T reg3=pos_nodes[1][0]*var_inter[0]; T reg4=pos_nodes[0][1]*reg1;
    T reg5=reg1*pos_nodes[1][1]; T reg6=pos_nodes[0][0]*reg1; T reg7=pos_nodes[1][0]*reg1; T reg8=pos_nodes[0][1]*reg0; T reg9=var_inter[0]*pos_nodes[1][1];
    T reg10=reg1*reg0; reg3=reg2+reg3; reg2=var_inter[0]*reg1; T reg11=var_inter[0]*pos_nodes[2][0]; reg4=reg5-reg4;
    reg5=var_inter[1]*pos_nodes[2][1]; T reg12=var_inter[1]*pos_nodes[2][0]; reg6=reg7-reg6; reg7=var_inter[0]*pos_nodes[2][1]; reg9=reg8+reg9;
    reg5=reg4+reg5; reg4=var_inter[1]*pos_nodes[3][1]; reg8=pos_nodes[1][1]*reg2; T reg13=pos_nodes[3][1]*reg0; reg9=reg7-reg9;
    reg7=pos_nodes[0][1]*reg10; T reg14=pos_nodes[0][0]*reg10; T reg15=pos_nodes[1][0]*reg2; reg12=reg6+reg12; reg6=var_inter[1]*pos_nodes[3][0];
    T reg16=pos_nodes[3][0]*reg0; reg3=reg11-reg3; reg11=var_inter[1]*var_inter[0]; reg3=reg16+reg3; reg6=reg12-reg6;
    reg12=var_inter[1]*reg0; reg8=reg7+reg8; reg4=reg5-reg4; reg5=pos_nodes[2][0]*reg11; reg15=reg14+reg15;
    reg7=pos_nodes[2][1]*reg11; reg9=reg13+reg9; reg7=reg8+reg7; reg8=reg6*reg9; reg13=reg3*reg4;
    reg14=pos_nodes[3][1]*reg12; reg5=reg15+reg5; reg15=reg12*pos_nodes[3][0]; reg13=reg8-reg13; reg7=reg14+reg7;
    reg5=reg15+reg5; reg7=pos[1]-reg7; reg14=reg9/reg13; reg5=pos[0]-reg5; reg15=reg4/reg13;
    reg16=reg3/reg13; reg13=reg6/reg13; reg14=reg5*reg14; reg16=reg7*reg16; reg15=reg5*reg15;
    reg13=reg7*reg13; var_inter[0]=reg14-reg16; var_inter[1]=reg13-reg15;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=pos_nodes[1][1]*reg1; T reg3=pos_nodes[0][1]*reg1; T reg4=pos_nodes[0][0]*reg0;
    T reg5=pos_nodes[1][0]*var_inter[0]; T reg6=pos_nodes[1][1]*var_inter[0]; T reg7=pos_nodes[0][1]*reg0; T reg8=pos_nodes[0][0]*reg1; T reg9=pos_nodes[1][0]*reg1;
    T reg10=var_inter[1]*pos_nodes[2][1]; T reg11=pos_nodes[2][1]*var_inter[0]; reg3=reg2-reg3; reg7=reg6+reg7; reg2=reg1*reg0;
    reg6=var_inter[0]*reg1; T reg12=pos_nodes[2][0]*var_inter[0]; reg4=reg5+reg4; reg8=reg9-reg8; reg5=var_inter[1]*pos_nodes[2][0];
    reg10=reg3+reg10; reg3=var_inter[1]*pos_nodes[3][1]; reg9=reg6*pos_nodes[1][1]; T reg13=pos_nodes[0][1]*reg2; reg4=reg12-reg4;
    reg12=pos_nodes[3][0]*reg0; T reg14=pos_nodes[1][0]*reg6; T reg15=pos_nodes[0][0]*reg2; T reg16=var_inter[1]*pos_nodes[3][0]; reg5=reg8+reg5;
    reg7=reg11-reg7; reg8=var_inter[1]*var_inter[0]; reg11=pos_nodes[3][1]*reg0; reg3=reg10-reg3; reg11=reg7+reg11;
    reg16=reg5-reg16; reg12=reg4+reg12; reg15=reg14+reg15; reg4=reg8*pos_nodes[2][0]; reg13=reg9+reg13;
    reg5=reg8*pos_nodes[2][1]; reg7=var_inter[1]*reg0; reg5=reg13+reg5; reg9=reg7*pos_nodes[3][1]; reg10=reg16*reg11;
    reg4=reg15+reg4; reg13=reg7*pos_nodes[3][0]; reg14=reg12*reg3; reg9=reg5+reg9; reg14=reg10-reg14;
    reg13=reg4+reg13; reg4=reg12/reg14; reg5=reg3/reg14; reg15=reg16/reg14; reg14=reg11/reg14;
    reg9=pos[1]-reg9; reg13=pos[0]-reg13; reg14=reg13*reg14; reg4=reg9*reg4; reg5=reg13*reg5;
    reg15=reg9*reg15; var_inter[0]+=reg14-reg4; var_inter[1]+=reg15-reg5;

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
    T reg0=1-var_inter[1]; T reg1=1-var_inter[0]; T reg2=reg1*reg0; reg0=var_inter[0]*reg0; T reg3=var_inter[0]*var_inter[1];
    T reg4=val[0]*reg2; T reg5=val[1]*reg0; reg5=reg4+reg5; reg4=val[2]*reg3; reg1=var_inter[1]*reg1;
    reg4=reg5+reg4; reg5=val[3]*reg1; res=reg4+reg5;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Quad &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    reg3=16*reg3; reg0=var_inter[0]*reg0; T reg4=1-reg3; T reg5=reg4*reg0; T reg6=reg4*reg2;
    T reg7=var_inter[0]*var_inter[1]; reg1=var_inter[1]*reg1; reg6=val[0]*reg6; reg5=val[1]*reg5; T reg8=reg7*reg4;
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
    T reg0=1-var_inter[0]; T reg1=1-var_inter[1]; T reg2=var_inter[0]*var_inter[1]; res[2]=reg2; T reg3=var_inter[1]*reg0;
    res[3]=reg3; T reg4=var_inter[0]*reg1; res[1]=reg4; reg1=reg0*reg1; res[0]=reg1;

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
    T reg0=1-var_inter[1]; T reg1=elem.pos(1)[1]*reg0; T reg2=reg0*elem.pos(0)[0]; T reg3=elem.pos(0)[1]*reg0; T reg4=elem.pos(1)[0]*reg0;
    T reg5=var_inter[1]*elem.pos(2)[0]; T reg6=elem.pos(0)[2]*reg0; T reg7=elem.pos(1)[2]*reg0; T reg8=var_inter[1]*elem.pos(2)[1]; reg1=reg1-reg3;
    reg4=reg4-reg2; T reg9=var_inter[1]*elem.pos(3)[1]; T reg10=var_inter[1]*elem.pos(3)[0]; reg7=reg7-reg6; reg5=reg4+reg5;
    reg4=var_inter[1]*elem.pos(2)[2]; reg8=reg1+reg8; reg1=var_inter[1]*elem.pos(3)[2]; reg8=reg8-reg9; reg4=reg7+reg4;
    reg5=reg5-reg10; reg7=pow(reg8,2); reg4=reg4-reg1; T reg11=1-var_inter[0]; T reg12=pow(reg5,2);
    T reg13=reg11*elem.pos(0)[0]; T reg14=var_inter[0]*elem.pos(1)[1]; T reg15=var_inter[0]*elem.pos(1)[0]; T reg16=pow(reg4,2); T reg17=elem.pos(0)[1]*reg11;
    reg7=reg12+reg7; reg12=reg13+reg15; T reg18=reg17+reg14; T reg19=var_inter[0]*elem.pos(2)[0]; T reg20=var_inter[0]*elem.pos(2)[1];
    T reg21=var_inter[0]*elem.pos(1)[2]; T reg22=elem.pos(0)[2]*reg11; reg16=reg7+reg16; reg7=reg11*elem.pos(3)[1]; reg16=pow(reg16,0.5);
    reg19=reg19-reg12; reg20=reg20-reg18; T reg23=var_inter[0]*elem.pos(2)[2]; T reg24=reg11*elem.pos(3)[0]; T reg25=reg22+reg21;
    T reg26=reg5/reg16; reg19=reg24+reg19; reg24=reg11*elem.pos(3)[2]; T reg27=reg8/reg16; reg20=reg7+reg20;
    reg23=reg23-reg25; reg24=reg23+reg24; reg16=reg4/reg16; reg7=reg27*reg20; reg23=reg26*reg19;
    T reg28=reg24*reg16; reg23=reg7+reg23; reg23=reg28+reg23; reg7=reg23*reg26; reg28=reg23*reg27;
    T reg29=reg23*reg16; reg28=reg20-reg28; reg7=reg19-reg7; reg29=reg24-reg29; T reg30=pow(reg28,2);
    T reg31=pow(reg7,2); reg31=reg30+reg31; reg30=pow(reg29,2); reg30=reg31+reg30; reg30=pow(reg30,0.5);
    reg7=reg7/reg30; reg28=reg28/reg30; reg30=reg29/reg30; reg29=reg7*reg5; reg27=reg8*reg27;
    reg19=reg7*reg19; reg20=reg28*reg20; reg28=reg8*reg28; reg5=reg26*reg5; reg19=reg20+reg19;
    reg24=reg24*reg30; reg5=reg27+reg5; reg30=reg30*reg4; reg4=reg16*reg4; reg28=reg29+reg28;
    reg19=reg24+reg19; reg4=reg5+reg4; reg28=reg30+reg28; reg5=reg19*reg4; reg7=reg23*reg28;
    reg7=reg5-reg7; return reg7;

}
}
#endif // LMT_QUAD
