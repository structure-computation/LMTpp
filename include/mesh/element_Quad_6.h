#ifndef LMT_QUAD_6
#define LMT_QUAD_6
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_6 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 13, 26, 39, 52, 65, 78, 91, 104, 117, }; // fonction de lordre du poly
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
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=reg0-var_inter[0]; T reg3=reg0+reg1; T reg4=var_inter[0]-0.5;
    reg2=4*reg2; T reg5=2*reg3; T reg6=reg4+var_inter[0]; T reg7=reg0*var_inter[0]; reg1=reg0*reg1;
    reg0=1-var_inter[1]; reg6=2*reg6; reg1=2*reg1; T reg8=reg0*reg2; reg7=4*reg7;
    reg4=reg4*var_inter[0]; T reg9=reg0*reg5; T reg10=reg7*pos_nodes[4][0]; T reg11=pos_nodes[0][0]*reg1; T reg12=pos_nodes[4][1]*reg8;
    T reg13=pos_nodes[0][1]*reg9; T reg14=reg0*reg6; T reg15=pos_nodes[4][0]*reg8; T reg16=pos_nodes[0][0]*reg9; T reg17=reg7*pos_nodes[4][1];
    T reg18=pos_nodes[0][1]*reg1; reg4=2*reg4; reg11=reg10+reg11; reg10=pos_nodes[1][0]*reg4; T reg19=pos_nodes[1][0]*reg14;
    reg16=reg15-reg16; reg15=reg0*reg7; reg13=reg12-reg13; reg12=pos_nodes[1][1]*reg14; T reg20=var_inter[1]*reg5;
    T reg21=pos_nodes[1][1]*reg4; reg18=reg17+reg18; reg17=reg0*reg1; reg21=reg18+reg21; reg18=reg15*pos_nodes[4][1];
    T reg22=pos_nodes[0][1]*reg17; T reg23=pos_nodes[0][0]*reg17; T reg24=reg15*pos_nodes[4][0]; reg10=reg11+reg10; reg11=reg1*pos_nodes[3][1];
    reg12=reg13+reg12; reg13=pos_nodes[3][1]*reg20; T reg25=reg1*pos_nodes[3][0]; reg0=reg0*reg4; T reg26=pos_nodes[3][0]*reg20;
    reg2=var_inter[1]*reg2; reg19=reg16+reg19; reg16=pos_nodes[1][1]*reg0; reg22=reg18+reg22; reg6=var_inter[1]*reg6;
    reg13=reg12-reg13; reg12=pos_nodes[5][1]*reg2; reg18=reg7*pos_nodes[5][1]; T reg27=var_inter[1]*reg1; reg21=reg11-reg21;
    reg10=reg25-reg10; reg11=pos_nodes[1][0]*reg0; reg23=reg24+reg23; reg26=reg19-reg26; reg19=pos_nodes[5][0]*reg2;
    reg24=reg7*pos_nodes[5][0]; reg25=pos_nodes[2][0]*reg6; reg19=reg26+reg19; reg26=var_inter[1]*reg7; reg24=reg10+reg24;
    reg18=reg21+reg18; reg10=pos_nodes[2][1]*reg6; reg12=reg13+reg12; reg13=pos_nodes[2][0]*reg4; reg21=pos_nodes[2][1]*reg4;
    reg11=reg23+reg11; reg23=reg27*pos_nodes[3][0]; T reg28=reg27*pos_nodes[3][1]; reg16=reg22+reg16; reg28=reg16+reg28;
    reg21=reg18+reg21; reg16=reg26*pos_nodes[5][1]; reg18=var_inter[1]*reg4; reg10=reg12+reg10; reg12=reg26*pos_nodes[5][0];
    reg23=reg11+reg23; reg13=reg24+reg13; reg25=reg19+reg25; reg11=reg13*reg10; reg19=reg25*reg21;
    reg22=pos_nodes[2][0]*reg18; reg12=reg23+reg12; reg16=reg28+reg16; reg23=pos_nodes[2][1]*reg18; reg11=reg19-reg11;
    reg23=reg16+reg23; reg22=reg12+reg22; reg23=pos[1]-reg23; reg22=pos[0]-reg22; reg12=reg21/reg11;
    reg16=reg10/reg11; reg24=reg13/reg11; reg11=reg25/reg11; reg12=reg22*reg12; reg24=reg23*reg24;
    reg16=reg22*reg16; reg11=reg23*reg11; var_inter[0]=reg12-reg24; var_inter[1]=reg11-reg16;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=reg0-var_inter[0]; T reg3=reg1+reg0; T reg4=var_inter[0]-0.5;
    T reg5=2*reg3; T reg6=reg4+var_inter[0]; T reg7=reg0*var_inter[0]; reg0=reg1*reg0; reg1=1-var_inter[1];
    reg2=4*reg2; T reg8=reg1*reg5; reg0=2*reg0; reg4=reg4*var_inter[0]; reg7=4*reg7;
    T reg9=reg1*reg2; reg6=2*reg6; T reg10=pos_nodes[0][0]*reg8; T reg11=pos_nodes[4][0]*reg9; T reg12=reg1*reg6;
    T reg13=pos_nodes[0][1]*reg8; T reg14=pos_nodes[4][1]*reg9; T reg15=pos_nodes[0][1]*reg0; T reg16=reg7*pos_nodes[4][1]; reg4=2*reg4;
    T reg17=pos_nodes[4][0]*reg7; T reg18=pos_nodes[0][0]*reg0; T reg19=pos_nodes[1][0]*reg12; reg10=reg11-reg10; reg13=reg14-reg13;
    reg11=pos_nodes[1][1]*reg12; reg14=pos_nodes[1][0]*reg4; reg17=reg18+reg17; reg18=var_inter[1]*reg5; T reg20=reg7*reg1;
    T reg21=reg1*reg0; T reg22=reg4*pos_nodes[1][1]; reg16=reg15+reg16; reg11=reg13+reg11; reg13=pos_nodes[3][1]*reg18;
    reg15=pos_nodes[3][1]*reg0; T reg23=pos_nodes[4][1]*reg20; T reg24=pos_nodes[0][1]*reg21; reg22=reg16+reg22; reg16=pos_nodes[4][0]*reg20;
    T reg25=pos_nodes[0][0]*reg21; reg14=reg17+reg14; reg17=pos_nodes[3][0]*reg18; reg19=reg10+reg19; reg2=var_inter[1]*reg2;
    reg1=reg4*reg1; reg10=pos_nodes[3][0]*reg0; T reg26=reg7*pos_nodes[5][1]; reg22=reg15-reg22; reg15=reg0*var_inter[1];
    T reg27=pos_nodes[5][1]*reg2; reg13=reg11-reg13; reg23=reg24+reg23; reg6=var_inter[1]*reg6; reg11=reg1*pos_nodes[1][1];
    reg14=reg10-reg14; reg10=pos_nodes[5][0]*reg7; reg24=reg1*pos_nodes[1][0]; reg16=reg25+reg16; reg25=pos_nodes[5][0]*reg2;
    reg17=reg19-reg17; reg19=reg15*pos_nodes[3][1]; reg11=reg23+reg11; reg23=pos_nodes[2][0]*reg6; reg25=reg17+reg25;
    reg17=reg4*pos_nodes[2][1]; reg26=reg22+reg26; reg10=reg14+reg10; reg14=reg7*var_inter[1]; reg22=reg4*pos_nodes[2][0];
    T reg28=pos_nodes[2][1]*reg6; reg27=reg13+reg27; reg13=reg15*pos_nodes[3][0]; reg24=reg16+reg24; reg23=reg25+reg23;
    reg16=reg14*pos_nodes[5][0]; reg17=reg26+reg17; reg13=reg24+reg13; reg24=reg14*pos_nodes[5][1]; reg19=reg11+reg19;
    reg11=reg4*var_inter[1]; reg22=reg10+reg22; reg28=reg27+reg28; reg24=reg19+reg24; reg10=reg11*pos_nodes[2][1];
    reg19=reg23*reg17; reg25=reg22*reg28; reg16=reg13+reg16; reg13=reg11*pos_nodes[2][0]; reg25=reg19-reg25;
    reg10=reg24+reg10; reg13=reg16+reg13; reg10=pos[1]-reg10; reg13=pos[0]-reg13; reg16=reg17/reg25;
    reg24=reg28/reg25; reg26=reg22/reg25; reg25=reg23/reg25; reg16=reg13*reg16; reg26=reg10*reg26;
    reg24=reg13*reg24; reg25=reg10*reg25; var_inter[0]+=reg16-reg26; var_inter[1]+=reg25-reg24;

}
template<> struct ElemVarInterFromPosNonLinear<Quad_6> { static const bool res = 2; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    reg0=2*reg0; reg3=4*reg3; reg2=var_inter[0]*reg2; reg1=1-var_inter[1]; T reg4=reg0*reg1;
    T reg5=reg3*reg1; reg2=2*reg2; reg4=val[0]*reg4; reg1=reg2*reg1; reg5=val[4]*reg5;
    reg0=var_inter[1]*reg0; reg1=val[1]*reg1; reg5=reg4+reg5; reg0=val[3]*reg0; reg3=var_inter[1]*reg3;
    reg1=reg5+reg1; reg0=reg1+reg0; reg3=val[5]*reg3; reg2=var_inter[1]*reg2; reg3=reg0+reg3;
    reg2=val[2]*reg2; res=reg3+reg2;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Quad_6 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
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
template<class TVI,class TVAL> void get_shape_functions(const Quad_6 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=var_inter[0]-0.5; T reg1=1-var_inter[0]; T reg2=0.5-var_inter[0]; reg0=var_inter[0]*reg0; T reg3=var_inter[0]*reg1;
    reg2=reg1*reg2; reg2=2*reg2; reg3=4*reg3; reg0=2*reg0; reg1=1-var_inter[1];
    T reg4=reg3*reg1; res[4]=reg4; T reg5=reg2*reg1; res[0]=reg5; reg1=reg0*reg1;
    res[1]=reg1; reg2=var_inter[1]*reg2; res[3]=reg2; reg3=var_inter[1]*reg3; res[5]=reg3;
    reg0=var_inter[1]*reg0; res[2]=reg0;

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

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Quad_6,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=reg0-var_inter[0]; T reg3=reg0+reg1; T reg4=var_inter[0]-0.5;
    reg2=4*reg2; T reg5=2*reg3; T reg6=var_inter[0]+reg4; T reg7=1-var_inter[1]; reg6=2*reg6;
    T reg8=reg7*reg5; T reg9=reg7*reg2; T reg10=elem.pos(0)[0]*reg8; T reg11=elem.pos(4)[1]*reg9; T reg12=elem.pos(4)[0]*reg9;
    T reg13=elem.pos(0)[1]*reg8; T reg14=reg7*reg6; T reg15=var_inter[1]*reg5; reg12=reg12-reg10; T reg16=elem.pos(1)[0]*reg14;
    reg9=elem.pos(4)[2]*reg9; T reg17=elem.pos(1)[1]*reg14; T reg18=elem.pos(0)[2]*reg8; reg11=reg11-reg13; reg14=elem.pos(1)[2]*reg14;
    T reg19=elem.pos(3)[0]*reg15; reg9=reg9-reg18; reg12=reg16+reg12; reg2=var_inter[1]*reg2; reg11=reg17+reg11;
    reg16=elem.pos(3)[1]*reg15; reg9=reg14+reg9; reg11=reg11-reg16; reg14=elem.pos(3)[2]*reg15; reg12=reg12-reg19;
    reg6=var_inter[1]*reg6; reg1=reg0*reg1; reg17=elem.pos(5)[0]*reg2; reg0=var_inter[0]*reg0; T reg20=elem.pos(5)[1]*reg2;
    reg1=2*reg1; reg0=4*reg0; reg2=elem.pos(5)[2]*reg2; reg4=var_inter[0]*reg4; reg12=reg17+reg12;
    reg17=elem.pos(2)[0]*reg6; reg9=reg9-reg14; reg11=reg20+reg11; reg20=elem.pos(2)[1]*reg6; T reg21=elem.pos(4)[0]*reg0;
    T reg22=elem.pos(0)[0]*reg1; T reg23=elem.pos(0)[1]*reg1; reg2=reg9+reg2; reg9=elem.pos(4)[1]*reg0; reg12=reg17+reg12;
    reg6=elem.pos(2)[2]*reg6; reg4=2*reg4; reg11=reg20+reg11; reg17=elem.pos(0)[2]*reg1; reg20=elem.pos(4)[2]*reg0;
    T reg24=elem.pos(1)[1]*reg4; T reg25=elem.pos(1)[0]*reg4; T reg26=reg22+reg21; reg6=reg2+reg6; reg2=reg9+reg23;
    T reg27=pow(reg12,2); T reg28=pow(reg11,2); T reg29=reg20+reg17; T reg30=elem.pos(3)[1]*reg1; T reg31=reg25+reg26;
    T reg32=elem.pos(1)[2]*reg4; T reg33=reg2+reg24; T reg34=elem.pos(3)[0]*reg1; reg28=reg27+reg28; reg27=pow(reg6,2);
    T reg35=reg29+reg32; T reg36=elem.pos(3)[2]*reg1; T reg37=reg0*elem.pos(5)[0]; T reg38=reg0*elem.pos(5)[1]; reg30=reg30-reg33;
    reg34=reg34-reg31; reg27=reg28+reg27; reg28=elem.pos(2)[1]*reg4; reg34=reg37+reg34; reg37=elem.pos(2)[0]*reg4;
    reg36=reg36-reg35; T reg39=reg0*elem.pos(5)[2]; reg30=reg38+reg30; reg27=pow(reg27,0.5); reg38=reg11/reg27;
    reg39=reg36+reg39; reg36=elem.pos(2)[2]*reg4; reg28=reg30+reg28; reg37=reg34+reg37; reg30=reg12/reg27;
    reg27=reg6/reg27; reg36=reg39+reg36; reg34=reg37*reg30; reg39=reg28*reg38; reg39=reg34+reg39;
    reg34=reg27*reg36; reg34=reg39+reg34; reg39=reg30*reg34; T reg40=reg38*reg34; T reg41=reg27*reg34;
    reg40=reg28-reg40; reg39=reg37-reg39; T reg42=pow(reg40,2); T reg43=pow(reg39,2); reg41=reg36-reg41;
    reg42=reg43+reg42; reg43=pow(reg41,2); reg42=reg43+reg42; reg42=pow(reg42,0.5); reg39=reg39/reg42;
    reg40=reg40/reg42; reg43=reg40*reg11; reg42=reg41/reg42; reg40=reg28*reg40; reg37=reg37*reg39;
    reg30=reg30*reg12; reg11=reg38*reg11; reg12=reg39*reg12; reg11=reg30+reg11; reg36=reg42*reg36;
    reg40=reg37+reg40; reg42=reg6*reg42; reg12=reg43+reg12; reg27=reg6*reg27; reg42=reg12+reg42;
    reg36=reg40+reg36; reg27=reg11+reg27; reg6=reg34*reg42; reg11=reg27*reg36; reg6=reg11-reg6;
    return reg6;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Quad_6,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.66666666666666670528*elem.pos(4)[1]; T reg1=0.12200846792814621818*elem.pos(0)[1]; T reg2=0.032692070451105301881*elem.pos(0)[0]; T reg3=0.48803387171258487271*elem.pos(4)[0]; T reg4=0.45534180126147951289*elem.pos(0)[0];
    T reg5=0.48803387171258487271*elem.pos(4)[1]; T reg6=0.032692070451105301881*elem.pos(0)[1]; T reg7=0.12200846792814621818*elem.pos(0)[0]; T reg8=0.66666666666666670528*elem.pos(4)[0]; T reg9=0.45534180126147957081*elem.pos(0)[0];
    T reg10=0.45534180126147957081*elem.pos(0)[1]; T reg11=0.45534180126147951289*elem.pos(0)[1]; T reg12=0.032692070451105301881*elem.pos(1)[1]; reg10=reg5-reg10; T reg13=0.12200846792814621818*elem.pos(1)[1];
    T reg14=0.12200846792814621818*elem.pos(1)[0]; reg4=reg8+reg4; reg11=reg0+reg11; reg0=reg0-reg1; T reg15=0.45534180126147951289*elem.pos(1)[1];
    T reg16=1.8213672050459180516*elem.pos(4)[1]; T reg17=0.12200846792814616024*elem.pos(0)[0]; T reg18=reg6-reg5; T reg19=0.45534180126147957081*elem.pos(1)[1]; T reg20=0.12200846792814616024*elem.pos(0)[1];
    T reg21=0.032692070451105301881*elem.pos(1)[0]; reg8=reg8-reg7; T reg22=0.45534180126147951289*elem.pos(1)[0]; reg9=reg3-reg9; T reg23=1.8213672050459180516*elem.pos(4)[0];
    T reg24=0.45534180126147957081*elem.pos(1)[0]; T reg25=reg2-reg3; reg19=reg18+reg19; reg18=0.12200846792814616024*elem.pos(3)[1]; T reg26=1.6993587371177718913*elem.pos(1)[0];
    T reg27=1.6993587371177718913*elem.pos(0)[0]; reg11=reg11-reg13; T reg28=0.12200846792814621818*elem.pos(3)[0]; T reg29=1.6993587371177718913*elem.pos(3)[1]; T reg30=0.45534180126147951289*elem.pos(3)[1];
    T reg31=0.025783423063208590757*elem.pos(0)[0]; reg22=reg8+reg22; reg8=0.14088324360345809781*elem.pos(4)[0]; T reg32=1.6993587371177718913*elem.pos(0)[1]; T reg33=1.6993587371177718913*elem.pos(3)[0];
    reg9=reg9-reg21; reg4=reg4-reg14; T reg34=0.12200846792814616024*elem.pos(3)[0]; T reg35=1.6993587371177718913*elem.pos(1)[1]; T reg36=reg20-reg16;
    reg24=reg25+reg24; reg25=0.12200846792814621818*elem.pos(3)[1]; T reg37=0.096225044864937627422*elem.pos(0)[1]; T reg38=0.45534180126147951289*elem.pos(3)[0]; reg15=reg0+reg15;
    reg0=reg17-reg23; T reg39=0.025783423063208590757*elem.pos(0)[1]; T reg40=0.14088324360345809781*elem.pos(4)[1]; T reg41=0.096225044864937627422*elem.pos(0)[0]; reg10=reg10-reg12;
    T reg42=reg8-reg31; reg35=reg36+reg35; reg36=0.032692070451105301881*elem.pos(3)[1]; reg33=reg9-reg33; reg11=reg30-reg11;
    reg9=0.032692070451105301881*elem.pos(3)[0]; reg26=reg0+reg26; reg29=reg10-reg29; reg4=reg38-reg4; reg0=0.52578342306320860749*elem.pos(4)[0];
    reg10=0.025783423063208590757*elem.pos(1)[1]; reg30=reg40-reg39; reg19=reg19+reg18; reg38=1.8213672050459180516*elem.pos(5)[1]; T reg43=0.66666666666666670528*elem.pos(5)[1];
    reg15=reg25+reg15; T reg44=0.12200846792814616024*elem.pos(1)[1]; reg32=reg16-reg32; reg40=reg40+reg37; T reg45=0.096225044864937627422*elem.pos(1)[1];
    T reg46=0.52578342306320860749*elem.pos(4)[1]; T reg47=0.096225044864937627422*elem.pos(1)[0]; reg22=reg28+reg22; T reg48=0.66666666666666670528*elem.pos(5)[0]; T reg49=1.8213672050459180516*elem.pos(5)[0];
    T reg50=0.12200846792814616024*elem.pos(1)[0]; reg27=reg23-reg27; reg8=reg8+reg41; T reg51=0.025783423063208590757*elem.pos(1)[0]; reg24=reg24+reg34;
    T reg52=0.35911675639654188548*elem.pos(0)[1]; reg30=reg30+reg45; T reg53=0.096225044864937627422*elem.pos(3)[1]; T reg54=0.35911675639654188548*elem.pos(1)[0]; T reg55=reg0-reg41;
    T reg56=0.45534180126147957081*elem.pos(3)[1]; reg40=reg40-reg10; reg32=reg32-reg44; reg26=reg26+reg9; T reg57=0.35911675639654188548*elem.pos(3)[1];
    T reg58=0.35911675639654188548*elem.pos(1)[1]; T reg59=reg46-reg37; T reg60=0.48803387171258487271*elem.pos(5)[0]; T reg61=0.45534180126147957081*elem.pos(3)[0]; reg27=reg27-reg50;
    T reg62=0.35911675639654188548*elem.pos(0)[0]; T reg63=0.48803387171258487271*elem.pos(5)[1]; reg35=reg35+reg36; reg19=reg19-reg38; reg33=reg49+reg33;
    T reg64=0.12200846792814616024*elem.pos(2)[0]; T reg65=0.35911675639654188548*elem.pos(3)[0]; reg8=reg8-reg51; reg11=reg43+reg11; T reg66=0.12200846792814621818*elem.pos(2)[1];
    T reg67=0.45534180126147951289*elem.pos(2)[0]; reg29=reg38+reg29; T reg68=0.12200846792814616024*elem.pos(2)[1]; T reg69=0.096225044864937627422*elem.pos(3)[0]; T reg70=reg48-reg22;
    T reg71=0.45534180126147951289*elem.pos(2)[1]; T reg72=1.6993587371177718913*elem.pos(2)[1]; reg43=reg43-reg15; T reg73=0.12200846792814621818*elem.pos(2)[0]; reg4=reg48+reg4;
    reg48=1.6993587371177718913*elem.pos(2)[0]; reg24=reg24-reg49; reg42=reg42+reg47; reg48=reg24+reg48; reg56=reg32-reg56;
    reg62=reg0+reg62; reg0=0.45534180126147957081*elem.pos(2)[1]; reg35=reg35-reg63; reg24=0.52578342306320860749*elem.pos(5)[1]; reg30=reg30-reg53;
    reg65=reg8+reg65; reg71=reg43+reg71; reg52=reg46+reg52; reg72=reg19+reg72; reg8=0.025783423063208590757*elem.pos(3)[1];
    reg4=reg4-reg73; reg54=reg55+reg54; reg19=0.025783423063208590757*elem.pos(3)[0]; reg58=reg59+reg58; reg61=reg27-reg61;
    reg29=reg29-reg68; reg11=reg11-reg66; reg33=reg33-reg64; reg26=reg26-reg60; reg27=0.45534180126147957081*elem.pos(2)[0];
    reg57=reg40+reg57; reg42=reg42-reg69; reg32=0.52578342306320860749*elem.pos(5)[0]; reg67=reg70+reg67; reg48=reg48*reg71;
    reg56=reg63+reg56; reg40=0.032692070451105301881*elem.pos(2)[1]; reg30=reg30+reg24; reg43=0.35911675639654188548*elem.pos(2)[1]; reg46=0.35911675639654188548*elem.pos(2)[0];
    reg42=reg42+reg32; reg57=reg24+reg57; reg24=0.096225044864937627422*elem.pos(2)[1]; reg58=reg58-reg8; reg55=0.14088324360345809781*elem.pos(5)[1];
    reg52=reg52-reg45; reg54=reg54-reg19; reg33=reg33*reg11; reg59=0.032692070451105301881*elem.pos(2)[0]; reg61=reg60+reg61;
    reg72=reg72*reg67; reg27=reg26+reg27; reg62=reg62-reg47; reg26=0.096225044864937627422*elem.pos(2)[0]; reg65=reg32+reg65;
    reg32=0.14088324360345809781*elem.pos(5)[0]; reg0=reg35+reg0; reg29=reg29*reg4; reg62=reg69+reg62; reg54=reg54+reg32;
    reg0=reg67*reg0; reg43=reg30+reg43; reg46=reg42+reg46; reg65=reg65-reg26; reg27=reg71*reg27;
    reg57=reg57-reg24; reg58=reg58+reg55; reg61=reg61-reg59; reg72=reg48-reg72; reg56=reg56-reg40;
    reg29=reg33-reg29; reg52=reg53+reg52; reg61=reg11*reg61; reg54=reg26+reg54; reg46=reg46*reg72;
    reg11=0.025783423063208590757*elem.pos(2)[0]; reg56=reg4*reg56; reg57=reg29*reg57; reg43=reg72*reg43; reg4=0.025783423063208590757*elem.pos(2)[1];
    reg52=reg55+reg52; reg0=reg27-reg0; reg58=reg24+reg58; reg62=reg32+reg62; reg65=reg65*reg29;
    reg57=0.25*reg57; reg72=0.25*reg72; reg52=reg52-reg4; reg58=reg0*reg58; reg65=0.25*reg65;
    reg43=0.25*reg43; reg54=reg54*reg0; reg62=reg62-reg11; reg56=reg61-reg56; reg46=0.25*reg46;
    reg29=0.25*reg29; reg52=reg56*reg52; reg62=reg62*reg56; reg29=reg72+reg29; reg58=0.25*reg58;
    reg0=0.25*reg0; reg65=reg46+reg65; reg54=0.25*reg54; reg57=reg43+reg57; reg0=reg29+reg0;
    reg56=0.25*reg56; reg58=reg57+reg58; reg62=0.25*reg62; reg54=reg65+reg54; reg52=0.25*reg52;
    reg56=reg0+reg56; reg62=reg54+reg62; reg52=reg58+reg52; res[0]=reg62/reg56; res[1]=reg52/reg56;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Quad_6,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.48803387171258487271*elem.pos(4)[1]; T reg1=0.032692070451105301881*elem.pos(0)[1]; T reg2=0.032692070451105301881*elem.pos(0)[0]; T reg3=0.48803387171258487271*elem.pos(4)[0]; T reg4=0.45534180126147957081*elem.pos(0)[0];
    T reg5=0.45534180126147957081*elem.pos(0)[1]; reg4=reg3-reg4; T reg6=reg1-reg0; T reg7=0.45534180126147957081*elem.pos(1)[0]; T reg8=reg2-reg3;
    T reg9=0.45534180126147957081*elem.pos(1)[1]; T reg10=0.48803387171258487271*elem.pos(4)[2]; T reg11=0.032692070451105301881*elem.pos(0)[2]; T reg12=0.12200846792814616024*elem.pos(0)[1]; T reg13=1.8213672050459180516*elem.pos(4)[1];
    T reg14=0.032692070451105301881*elem.pos(1)[0]; reg5=reg0-reg5; T reg15=0.12200846792814616024*elem.pos(0)[0]; T reg16=1.8213672050459180516*elem.pos(4)[0]; T reg17=0.032692070451105301881*elem.pos(1)[1];
    T reg18=0.45534180126147957081*elem.pos(0)[2]; reg5=reg5-reg17; T reg19=1.6993587371177718913*elem.pos(3)[1]; T reg20=0.032692070451105301881*elem.pos(1)[2]; reg18=reg10-reg18;
    reg9=reg6+reg9; reg6=0.12200846792814616024*elem.pos(3)[1]; T reg21=0.12200846792814616024*elem.pos(0)[2]; T reg22=1.8213672050459180516*elem.pos(4)[2]; T reg23=0.45534180126147957081*elem.pos(1)[2];
    T reg24=reg11-reg10; T reg25=1.6993587371177718913*elem.pos(1)[1]; T reg26=reg12-reg13; T reg27=1.6993587371177718913*elem.pos(3)[0]; T reg28=1.6993587371177718913*elem.pos(1)[0];
    T reg29=reg15-reg16; reg4=reg4-reg14; T reg30=1.6993587371177718913*elem.pos(0)[0]; T reg31=0.12200846792814616024*elem.pos(3)[0]; reg7=reg8+reg7;
    reg8=1.6993587371177718913*elem.pos(0)[1]; reg24=reg23+reg24; reg23=0.12200846792814616024*elem.pos(3)[2]; reg19=reg5-reg19; reg8=reg13-reg8;
    reg18=reg18-reg20; reg5=0.032692070451105301881*elem.pos(3)[1]; reg25=reg26+reg25; reg26=1.6993587371177718913*elem.pos(3)[2]; T reg32=0.12200846792814616024*elem.pos(1)[1];
    T reg33=0.032692070451105301881*elem.pos(3)[0]; reg28=reg29+reg28; reg29=1.8213672050459180516*elem.pos(5)[0]; T reg34=0.12200846792814616024*elem.pos(1)[0]; T reg35=reg21-reg22;
    reg7=reg7+reg31; reg27=reg4-reg27; reg9=reg9+reg6; reg4=1.8213672050459180516*elem.pos(5)[1]; reg30=reg16-reg30;
    T reg36=1.6993587371177718913*elem.pos(1)[2]; T reg37=1.6993587371177718913*elem.pos(0)[2]; reg27=reg29+reg27; T reg38=0.12200846792814616024*elem.pos(2)[0]; T reg39=0.12200846792814616024*elem.pos(2)[1];
    reg19=reg4+reg19; reg26=reg18-reg26; reg18=0.45534180126147957081*elem.pos(3)[0]; reg30=reg30-reg34; reg7=reg7-reg29;
    T reg40=1.6993587371177718913*elem.pos(2)[0]; reg35=reg36+reg35; reg36=0.032692070451105301881*elem.pos(3)[2]; reg9=reg9-reg4; T reg41=1.6993587371177718913*elem.pos(2)[1];
    reg37=reg22-reg37; T reg42=0.12200846792814616024*elem.pos(1)[2]; reg24=reg24+reg23; T reg43=1.8213672050459180516*elem.pos(5)[2]; T reg44=0.48803387171258487271*elem.pos(5)[1];
    reg28=reg28+reg33; T reg45=0.48803387171258487271*elem.pos(5)[0]; reg8=reg8-reg32; T reg46=0.45534180126147957081*elem.pos(3)[1]; reg25=reg25+reg5;
    reg25=reg25-reg44; reg28=reg28-reg45; T reg47=0.45534180126147957081*elem.pos(2)[0]; reg35=reg35+reg36; T reg48=0.48803387171258487271*elem.pos(5)[2];
    T reg49=0.45534180126147951289*elem.pos(0)[1]; T reg50=0.45534180126147951289*elem.pos(0)[0]; reg27=reg27-reg38; T reg51=0.45534180126147957081*elem.pos(3)[2]; reg37=reg37-reg42;
    T reg52=0.12200846792814616024*elem.pos(2)[2]; reg26=reg43+reg26; reg46=reg8-reg46; reg18=reg30-reg18; reg19=reg19-reg39;
    reg8=0.45534180126147957081*elem.pos(2)[1]; reg41=reg9+reg41; reg40=reg7+reg40; reg24=reg24-reg43; reg7=1.6993587371177718913*elem.pos(2)[2];
    reg9=0.66666666666666670528*elem.pos(4)[0]; reg30=0.12200846792814621818*elem.pos(0)[0]; T reg53=0.66666666666666670528*elem.pos(4)[1]; T reg54=0.12200846792814621818*elem.pos(0)[1]; reg8=reg25+reg8;
    reg49=reg53+reg49; reg25=0.12200846792814621818*elem.pos(1)[1]; T reg55=0.12200846792814621818*elem.pos(1)[0]; reg7=reg24+reg7; reg47=reg28+reg47;
    reg50=reg9+reg50; reg24=0.45534180126147951289*elem.pos(0)[2]; reg28=0.66666666666666670528*elem.pos(4)[2]; T reg56=0.12200846792814621818*elem.pos(0)[2]; T reg57=pow(reg27,2);
    reg9=reg9-reg30; T reg58=0.45534180126147951289*elem.pos(1)[0]; reg53=reg53-reg54; T reg59=pow(reg19,2); reg26=reg26-reg52;
    T reg60=0.45534180126147951289*elem.pos(1)[1]; T reg61=pow(reg41,2); reg18=reg45+reg18; T reg62=pow(reg40,2); reg35=reg35-reg48;
    T reg63=0.45534180126147957081*elem.pos(2)[2]; T reg64=0.032692070451105301881*elem.pos(2)[0]; reg51=reg37-reg51; reg37=0.032692070451105301881*elem.pos(2)[1]; reg46=reg44+reg46;
    T reg65=0.032692070451105301881*elem.pos(2)[2]; reg51=reg48+reg51; reg58=reg9+reg58; reg53=reg60+reg53; reg59=reg57+reg59;
    reg46=reg46-reg37; reg9=0.12200846792814621818*elem.pos(3)[1]; reg57=pow(reg26,2); reg24=reg28+reg24; reg60=0.12200846792814621818*elem.pos(1)[2];
    T reg66=0.45534180126147951289*elem.pos(3)[0]; reg18=reg18-reg64; reg50=reg50-reg55; T reg67=0.45534180126147951289*elem.pos(3)[1]; reg49=reg49-reg25;
    reg61=reg62+reg61; reg62=pow(reg8,2); reg63=reg35+reg63; reg35=pow(reg7,2); T reg68=pow(reg47,2);
    T reg69=0.12200846792814621818*elem.pos(3)[0]; T reg70=0.45534180126147951289*elem.pos(1)[2]; reg28=reg28-reg56; reg58=reg69+reg58; reg62=reg68+reg62;
    reg68=0.12200846792814621818*elem.pos(3)[2]; reg49=reg67-reg49; reg50=reg66-reg50; reg51=reg51-reg65; reg35=reg61+reg35;
    reg61=0.66666666666666670528*elem.pos(5)[0]; reg66=0.45534180126147951289*elem.pos(3)[2]; reg67=pow(reg18,2); reg24=reg24-reg60; reg57=reg59+reg57;
    reg59=pow(reg63,2); T reg71=0.66666666666666670528*elem.pos(5)[1]; reg53=reg9+reg53; reg28=reg70+reg28; reg70=pow(reg46,2);
    T reg72=0.45534180126147951289*elem.pos(2)[1]; T reg73=reg71-reg53; reg28=reg68+reg28; reg49=reg71+reg49; reg71=0.12200846792814621818*elem.pos(2)[0];
    reg50=reg61+reg50; reg70=reg67+reg70; reg67=0.66666666666666670528*elem.pos(5)[2]; T reg74=pow(reg51,2); reg35=pow(reg35,0.5);
    T reg75=0.12200846792814621818*elem.pos(2)[1]; reg59=reg62+reg59; reg24=reg66-reg24; reg57=pow(reg57,0.5); reg62=0.45534180126147951289*elem.pos(2)[0];
    reg61=reg61-reg58; reg59=pow(reg59,0.5); reg49=reg49-reg75; reg66=reg40/reg35; T reg76=0.12200846792814621818*elem.pos(2)[2];
    T reg77=reg41/reg35; reg24=reg67+reg24; reg74=reg70+reg74; reg70=0.45534180126147951289*elem.pos(2)[2]; reg50=reg50-reg71;
    reg67=reg67-reg28; T reg78=reg19/reg57; reg72=reg73+reg72; reg73=reg27/reg57; reg62=reg61+reg62;
    reg70=reg67+reg70; reg61=reg8/reg59; reg74=pow(reg74,0.5); reg67=reg47/reg59; reg35=reg7/reg35;
    T reg79=reg77*reg72; reg24=reg24-reg76; T reg80=reg73*reg50; T reg81=reg78*reg49; reg57=reg26/reg57;
    T reg82=reg66*reg62; T reg83=reg46/reg74; T reg84=reg18/reg74; reg79=reg82+reg79; reg81=reg80+reg81;
    reg80=reg57*reg24; reg59=reg63/reg59; reg82=reg62*reg67; T reg85=reg72*reg61; T reg86=reg35*reg70;
    reg85=reg82+reg85; reg82=reg70*reg59; reg80=reg81+reg80; reg86=reg79+reg86; reg74=reg51/reg74;
    reg79=reg50*reg84; reg81=reg49*reg83; reg82=reg85+reg82; reg85=reg77*reg86; T reg87=reg66*reg86;
    reg81=reg79+reg81; reg79=reg24*reg74; T reg88=reg73*reg80; T reg89=reg78*reg80; T reg90=reg57*reg80;
    reg89=reg49-reg89; reg85=reg72-reg85; T reg91=reg35*reg86; T reg92=reg67*reg82; reg79=reg81+reg79;
    reg87=reg62-reg87; reg81=reg61*reg82; reg88=reg50-reg88; T reg93=pow(reg87,2); T reg94=pow(reg85,2);
    reg91=reg70-reg91; T reg95=reg59*reg82; T reg96=pow(reg88,2); reg81=reg72-reg81; reg92=reg62-reg92;
    T reg97=reg84*reg79; T reg98=pow(reg89,2); T reg99=reg83*reg79; reg90=reg24-reg90; T reg100=pow(reg81,2);
    T reg101=pow(reg92,2); reg95=reg70-reg95; T reg102=pow(reg91,2); reg94=reg93+reg94; reg93=pow(reg90,2);
    reg98=reg96+reg98; reg96=reg74*reg79; reg99=reg49-reg99; reg97=reg50-reg97; T reg103=pow(reg99,2);
    T reg104=pow(reg97,2); reg102=reg94+reg102; reg93=reg98+reg93; reg96=reg24-reg96; reg100=reg101+reg100;
    reg94=pow(reg95,2); reg98=pow(reg96,2); reg94=reg100+reg94; reg93=pow(reg93,0.5); reg102=pow(reg102,0.5);
    reg103=reg104+reg103; reg85=reg85/reg102; reg88=reg88/reg93; reg87=reg87/reg102; reg100=0.14088324360345809781*elem.pos(4)[2];
    reg101=0.025783423063208590757*elem.pos(0)[0]; reg104=0.14088324360345809781*elem.pos(4)[0]; T reg105=0.14088324360345809781*elem.pos(4)[1]; T reg106=0.096225044864937627422*elem.pos(0)[0]; T reg107=0.096225044864937627422*elem.pos(0)[1];
    T reg108=0.025783423063208590757*elem.pos(0)[1]; reg94=pow(reg94,0.5); reg89=reg89/reg93; reg98=reg103+reg98; reg103=0.096225044864937627422*elem.pos(0)[2];
    T reg109=0.025783423063208590757*elem.pos(0)[2]; reg92=reg92/reg94; reg81=reg81/reg94; T reg110=0.52578342306320860749*elem.pos(4)[2]; T reg111=0.096225044864937627422*elem.pos(1)[0];
    T reg112=reg104-reg101; T reg113=reg19*reg89; T reg114=0.52578342306320860749*elem.pos(4)[0]; T reg115=reg27*reg88; reg93=reg90/reg93;
    reg98=pow(reg98,0.5); reg89=reg49*reg89; reg73=reg27*reg73; reg78=reg19*reg78; reg19=0.096225044864937627422*elem.pos(1)[1];
    reg27=reg100-reg109; reg88=reg50*reg88; reg90=reg105-reg108; reg77=reg41*reg77; reg66=reg40*reg66;
    T reg116=0.025783423063208590757*elem.pos(1)[1]; T reg117=0.025783423063208590757*elem.pos(1)[0]; reg104=reg104+reg106; reg105=reg105+reg107; T reg118=reg62*reg87;
    T reg119=reg72*reg85; reg102=reg91/reg102; reg100=reg100+reg103; reg91=0.025783423063208590757*elem.pos(1)[2]; T reg120=0.52578342306320860749*elem.pos(4)[1];
    T reg121=0.096225044864937627422*elem.pos(1)[2]; reg87=reg40*reg87; reg85=reg41*reg85; reg99=reg99/reg98; reg97=reg97/reg98;
    reg40=0.35911675639654188548*elem.pos(0)[2]; reg41=0.35911675639654188548*elem.pos(0)[1]; T reg122=reg110-reg103; reg27=reg121+reg27; T reg123=reg120-reg107;
    T reg124=0.096225044864937627422*elem.pos(3)[2]; reg90=reg19+reg90; T reg125=0.35911675639654188548*elem.pos(1)[1]; T reg126=0.096225044864937627422*elem.pos(3)[1]; T reg127=0.35911675639654188548*elem.pos(3)[1];
    reg105=reg105-reg116; T reg128=0.35911675639654188548*elem.pos(1)[2]; T reg129=0.35911675639654188548*elem.pos(3)[2]; reg100=reg100-reg91; reg104=reg104-reg117;
    reg78=reg73+reg78; reg94=reg95/reg94; reg72=reg72*reg81; reg62=reg62*reg92; reg85=reg87+reg85;
    reg57=reg26*reg57; reg61=reg8*reg61; reg67=reg47*reg67; reg73=reg7*reg102; reg89=reg88+reg89;
    reg87=reg24*reg93; reg113=reg115+reg113; reg93=reg26*reg93; reg26=0.35911675639654188548*elem.pos(1)[0]; reg88=reg114-reg106;
    reg95=0.35911675639654188548*elem.pos(3)[0]; reg77=reg66+reg77; reg92=reg47*reg92; reg81=reg8*reg81; reg35=reg7*reg35;
    reg119=reg118+reg119; reg7=0.096225044864937627422*elem.pos(3)[0]; reg112=reg112+reg111; reg102=reg70*reg102; reg8=0.35911675639654188548*elem.pos(0)[0];
    reg123=reg125+reg123; reg95=reg104+reg95; reg47=0.52578342306320860749*elem.pos(5)[0]; reg93=reg113+reg93; reg66=0.025783423063208590757*elem.pos(3)[1];
    reg87=reg89+reg87; reg89=0.025783423063208590757*elem.pos(3)[2]; reg57=reg78+reg57; reg50=reg50*reg97; reg122=reg128+reg122;
    reg49=reg49*reg99; reg78=0.52578342306320860749*elem.pos(5)[2]; reg99=reg46*reg99; reg97=reg18*reg97; reg98=reg96/reg98;
    reg129=reg100+reg129; reg112=reg112-reg7; reg127=reg105+reg127; reg27=reg27-reg124; reg96=reg63*reg94;
    reg81=reg92+reg81; reg94=reg70*reg94; reg72=reg62+reg72; reg102=reg119+reg102; reg59=reg63*reg59;
    reg61=reg67+reg61; reg73=reg85+reg73; reg84=reg18*reg84; reg83=reg46*reg83; reg8=reg114+reg8;
    reg35=reg77+reg35; reg18=0.52578342306320860749*elem.pos(5)[1]; reg41=reg120+reg41; reg90=reg90-reg126; reg46=0.025783423063208590757*elem.pos(3)[0];
    reg26=reg88+reg26; reg40=reg110+reg40; reg127=reg18+reg127; reg27=reg27+reg78; reg122=reg122-reg89;
    reg73=reg86*reg73; reg62=0.096225044864937627422*elem.pos(2)[1]; reg63=0.096225044864937627422*elem.pos(2)[2]; reg129=reg78+reg129; reg67=0.35911675639654188548*elem.pos(2)[1];
    reg18=reg90+reg18; reg70=0.096225044864937627422*elem.pos(2)[0]; reg95=reg47+reg95; reg8=reg8-reg111; reg77=0.35911675639654188548*elem.pos(2)[0];
    reg96=reg81+reg96; reg47=reg112+reg47; reg94=reg72+reg94; reg59=reg61+reg59; reg41=reg41-reg19;
    reg83=reg84+reg83; reg61=0.14088324360345809781*elem.pos(5)[0]; reg74=reg51*reg74; reg26=reg26-reg46; reg40=reg40-reg121;
    reg102=reg35*reg102; reg93=reg80*reg93; reg87=reg57*reg87; reg49=reg50+reg49; reg24=reg24*reg98;
    reg99=reg97+reg99; reg98=reg51*reg98; reg35=0.14088324360345809781*elem.pos(5)[1]; reg123=reg123-reg66; reg50=0.35911675639654188548*elem.pos(2)[2];
    reg51=0.14088324360345809781*elem.pos(5)[2]; reg41=reg126+reg41; reg123=reg123+reg35; reg127=reg127-reg62; reg77=reg47+reg77;
    reg50=reg27+reg50; reg8=reg7+reg8; reg40=reg124+reg40; reg96=reg82*reg96; reg94=reg59*reg94;
    reg26=reg26+reg61; reg74=reg83+reg74; reg93=reg87-reg93; reg24=reg49+reg24; reg98=reg99+reg98;
    reg73=reg102-reg73; reg122=reg122+reg51; reg95=reg95-reg70; reg67=reg18+reg67; reg129=reg129-reg63;
    reg18=0.025783423063208590757*elem.pos(2)[0]; reg8=reg61+reg8; reg77=reg77*reg73; reg27=0.025783423063208590757*elem.pos(2)[2]; reg40=reg51+reg40;
    reg50=reg73*reg50; reg127=reg93*reg127; reg96=reg94-reg96; reg129=reg93*reg129; reg47=0.025783423063208590757*elem.pos(2)[1];
    reg41=reg35+reg41; reg26=reg70+reg26; reg67=reg73*reg67; reg95=reg95*reg93; reg24=reg74*reg24;
    reg123=reg62+reg123; reg122=reg63+reg122; reg98=reg79*reg98; reg50=0.25*reg50; reg129=0.25*reg129;
    reg73=0.25*reg73; reg122=reg96*reg122; reg40=reg40-reg27; reg93=0.25*reg93; reg8=reg8-reg18;
    reg67=0.25*reg67; reg77=0.25*reg77; reg127=0.25*reg127; reg123=reg96*reg123; reg98=reg24-reg98;
    reg41=reg41-reg47; reg95=0.25*reg95; reg26=reg26*reg96; reg123=0.25*reg123; reg127=reg67+reg127;
    reg41=reg98*reg41; reg40=reg98*reg40; reg129=reg50+reg129; reg95=reg77+reg95; reg122=0.25*reg122;
    reg8=reg8*reg98; reg96=0.25*reg96; reg93=reg73+reg93; reg26=0.25*reg26; reg122=reg129+reg122;
    reg8=0.25*reg8; reg96=reg93+reg96; reg98=0.25*reg98; reg26=reg95+reg26; reg123=reg127+reg123;
    reg41=0.25*reg41; reg40=0.25*reg40; reg40=reg122+reg40; reg8=reg26+reg8; reg98=reg96+reg98;
    reg41=reg123+reg41; res[0]=reg8/reg98; res[1]=reg41/reg98; res[2]=reg40/reg98;

    return res;
}
}
#endif // LMT_QUAD_6
