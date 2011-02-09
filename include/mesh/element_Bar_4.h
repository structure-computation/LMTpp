#ifndef LMT_BAR_4
#define LMT_BAR_4
#include "node.h"
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Bar_4 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 13, 26, 39, 52, 65, 78, 91, 104, 117, }; // fonction de lordre du poly
    static const double values[] = {
        0.2339569672863455,0.61930959304159850001,
        0.2339569672863455,0.38069040695840149999,
        0.1803807865240695,0.8306046932331325,
        0.1803807865240695,0.1693953067668675,
        0.085662246189584999998,0.96623475710157599998,
        0.085662246189584999998,0.033765242898423999989,
        0.0,
        0.2339569672863455,0.61930959304159850001,
        0.2339569672863455,0.38069040695840149999,
        0.1803807865240695,0.8306046932331325,
        0.1803807865240695,0.1693953067668675,
        0.085662246189584999998,0.96623475710157599998,
        0.085662246189584999998,0.033765242898423999989,
        0.0,
        0.2339569672863455,0.61930959304159850001,
        0.2339569672863455,0.38069040695840149999,
        0.1803807865240695,0.8306046932331325,
        0.1803807865240695,0.1693953067668675,
        0.085662246189584999998,0.96623475710157599998,
        0.085662246189584999998,0.033765242898423999989,
        0.0,
        0.2339569672863455,0.61930959304159850001,
        0.2339569672863455,0.38069040695840149999,
        0.1803807865240695,0.8306046932331325,
        0.1803807865240695,0.1693953067668675,
        0.085662246189584999998,0.96623475710157599998,
        0.085662246189584999998,0.033765242898423999989,
        0.0,
        0.2339569672863455,0.61930959304159850001,
        0.2339569672863455,0.38069040695840149999,
        0.1803807865240695,0.8306046932331325,
        0.1803807865240695,0.1693953067668675,
        0.085662246189584999998,0.96623475710157599998,
        0.085662246189584999998,0.033765242898423999989,
        0.0,
        0.2339569672863455,0.61930959304159850001,
        0.2339569672863455,0.38069040695840149999,
        0.1803807865240695,0.8306046932331325,
        0.1803807865240695,0.1693953067668675,
        0.085662246189584999998,0.96623475710157599998,
        0.085662246189584999998,0.033765242898423999989,
        0.0,
        0.2339569672863455,0.61930959304159850001,
        0.2339569672863455,0.38069040695840149999,
        0.1803807865240695,0.8306046932331325,
        0.1803807865240695,0.1693953067668675,
        0.085662246189584999998,0.96623475710157599998,
        0.085662246189584999998,0.033765242898423999989,
        0.0,
        0.2339569672863455,0.61930959304159850001,
        0.2339569672863455,0.38069040695840149999,
        0.1803807865240695,0.8306046932331325,
        0.1803807865240695,0.1693953067668675,
        0.085662246189584999998,0.96623475710157599998,
        0.085662246189584999998,0.033765242898423999989,
        0.0,
        0.2339569672863455,0.61930959304159850001,
        0.2339569672863455,0.38069040695840149999,
        0.1803807865240695,0.8306046932331325,
        0.1803807865240695,0.1693953067668675,
        0.085662246189584999998,0.96623475710157599998,
        0.085662246189584999998,0.033765242898423999989,
        0.0,
        0.2339569672863455,0.61930959304159850001,
        0.2339569672863455,0.38069040695840149999,
        0.1803807865240695,0.8306046932331325,
        0.1803807865240695,0.1693953067668675,
        0.085662246189584999998,0.96623475710157599998,
        0.085662246189584999998,0.033765242898423999989,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Bar_4 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=3.375*nodes[2]->pos[0]; T reg1=0.12500000000000011102*nodes[0]->pos[0]; T reg2=reg1-reg0; T reg3=3.375*nodes[3]->pos[0]; T reg4=0.12499999999999986121*nodes[1]->pos[0];
    reg2=reg2+reg3; T det_jac=reg2-reg4;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[1],nodes[0],nodes[3],nodes[2]};
        for(unsigned i=0;i<4;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Bar_4 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=reg1+reg0; T reg3=1-var_inter[0]; T reg4=reg1-var_inter[0];
    T reg5=reg1*var_inter[0]; T reg6=reg0-var_inter[0]; T reg7=reg2*reg3; T reg8=reg1*reg0; reg4=reg4*reg3;
    reg0=reg0*var_inter[0]; T reg9=reg8*reg3; T reg10=reg5*reg3; T reg11=reg6*reg3; reg8=reg7+reg8;
    reg5=reg4-reg5; reg3=reg0*reg3; reg10=13.5*reg10; reg9=4.5*reg9; reg6=reg1*reg6;
    reg4=4.5*reg8; reg11=reg11-reg0; reg5=13.5*reg5; reg6=reg6-reg0; reg7=pos_nodes[0][0]*reg9;
    T reg12=pos_nodes[2][0]*reg10; reg11=13.5*reg11; T reg13=pos_nodes[0][0]*reg4; T reg14=pos_nodes[2][0]*reg5; reg0=reg1*reg0;
    reg3=13.5*reg3; reg6=4.5*reg6; reg0=4.5*reg0; reg1=reg3*pos_nodes[3][0]; reg12=reg7+reg12;
    reg7=reg11*pos_nodes[3][0]; reg13=reg14-reg13; reg1=reg12-reg1; reg12=pos_nodes[1][0]*reg0; reg7=reg13-reg7;
    reg13=pos_nodes[1][0]*reg6; reg1=reg12+reg1; reg7=reg13+reg7; reg1=pos[0]-reg1; reg12=1.0/reg7;
    reg12=reg1*reg12; var_inter[0]=reg12;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Bar_4 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=1-var_inter[0]; T reg3=reg1-var_inter[0]; T reg4=reg0+reg1;
    T reg5=reg0-var_inter[0]; T reg6=reg4*reg2; reg3=reg3*reg2; T reg7=var_inter[0]*reg1; T reg8=reg0*reg1;
    reg0=reg0*var_inter[0]; T reg9=reg2*reg7; T reg10=reg2*reg8; T reg11=reg5*reg2; reg8=reg6+reg8;
    reg7=reg3-reg7; reg11=reg11-reg0; reg2=reg0*reg2; reg3=4.5*reg8; reg9=13.5*reg9;
    reg10=4.5*reg10; reg7=13.5*reg7; reg5=reg5*reg1; reg5=reg5-reg0; reg6=pos_nodes[2][0]*reg9;
    T reg12=pos_nodes[0][0]*reg10; reg2=13.5*reg2; reg1=reg0*reg1; reg0=pos_nodes[0][0]*reg3; T reg13=pos_nodes[2][0]*reg7;
    reg11=13.5*reg11; T reg14=pos_nodes[3][0]*reg2; reg6=reg12+reg6; reg12=reg11*pos_nodes[3][0]; reg0=reg13-reg0;
    reg5=4.5*reg5; reg1=4.5*reg1; reg14=reg6-reg14; reg6=pos_nodes[1][0]*reg1; reg12=reg0-reg12;
    reg0=pos_nodes[1][0]*reg5; reg14=reg6+reg14; reg12=reg0+reg12; reg0=1.0/reg12; reg14=pos[0]-reg14;
    reg0=reg14*reg0; var_inter[0]+=reg0;

}
template<> struct ElemVarInterFromPosNonLinear<Bar_4> { static const bool res = 1; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=1-var_inter[0]; T reg3=reg1*reg0; T reg4=var_inter[0]*reg1;
    reg0=var_inter[0]*reg0; reg3=reg2*reg3; reg4=reg2*reg4; reg2=reg2*reg0; reg4=13.5*reg4;
    reg3=4.5*reg3; reg0=reg1*reg0; reg2=13.5*reg2; reg4=val[2]*reg4; reg3=val[0]*reg3;
    reg1=val[3]*reg2; reg4=reg3+reg4; reg0=4.5*reg0; reg0=val[1]*reg0; reg1=reg4-reg1;
    res=reg0+reg1;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Bar_4 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=1-var_inter[0]; T reg3=var_inter[0]*reg0; reg0=reg1*reg0;
    T reg4=reg2*reg3; T reg5=var_inter[0]*reg1; reg4=13.5*reg4; reg3=reg1*reg3; reg5=reg2*reg5;
    reg0=reg2*reg0; reg3=4.5*reg3; res[1]=reg3; res[3]=-reg4; reg5=13.5*reg5;
    res[2]=reg5; reg0=4.5*reg0; res[0]=reg0;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Bar_4> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Bar_4,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=reg1+reg0; T reg3=reg1-var_inter[0]; T reg4=1-var_inter[0];
    T reg5=reg4*reg2; reg3=reg4*reg3; T reg6=reg0-var_inter[0]; T reg7=var_inter[0]*reg1; T reg8=reg1*reg0;
    T reg9=reg4*reg6; reg5=reg8+reg5; reg3=reg3-reg7; reg0=var_inter[0]*reg0; T reg10=4.5*reg5;
    reg9=reg9-reg0; reg6=reg1*reg6; reg3=13.5*reg3; T reg11=elem.pos(2)[0]*reg3; reg6=reg6-reg0;
    T reg12=elem.pos(0)[0]*reg10; T reg13=elem.pos(2)[1]*reg3; reg9=13.5*reg9; T reg14=elem.pos(0)[1]*reg10; reg6=4.5*reg6;
    reg11=reg11-reg12; T reg15=elem.pos(3)[1]*reg9; T reg16=elem.pos(3)[0]*reg9; reg3=elem.pos(2)[2]*reg3; T reg17=elem.pos(0)[2]*reg10;
    reg13=reg13-reg14; T reg18=elem.pos(1)[1]*reg6; T reg19=elem.pos(1)[0]*reg6; reg16=reg11-reg16; reg15=reg13-reg15;
    reg3=reg3-reg17; reg9=elem.pos(3)[2]*reg9; reg19=reg16+reg19; reg9=reg3-reg9; reg6=elem.pos(1)[2]*reg6;
    reg18=reg15+reg18; reg9=reg6+reg9; reg3=pow(reg19,2); reg6=pow(reg18,2); reg11=pow(reg9,2);
    reg3=reg6+reg3; reg11=reg3+reg11; reg11=pow(reg11,0.5); reg3=reg18/reg11; reg6=reg19/reg11;
    reg11=reg9/reg11; reg18=reg3*reg18; reg6=reg19*reg6; reg6=reg18+reg6; reg9=reg11*reg9;
    reg9=reg6+reg9; return reg9;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,1> barycenter( const Element<Bar_4,TN,Node<1,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,1> res;
    T reg0=27*elem.pos(0)[0]; T reg1=44.999999999999999001*elem.pos(2)[0]; T reg2=17.9999999999999995*elem.pos(0)[0]; T reg3=81*elem.pos(2)[0]; T reg4=5.4999999999999996392*elem.pos(0)[0];
    T reg5=8.9999999999999995004*elem.pos(2)[0]; T reg6=35.9999999999999995*elem.pos(3)[0]; reg1=reg2-reg1; reg4=reg5-reg4; reg2=4.4999999999999997502*elem.pos(3)[0];
    reg5=reg3-reg0; T reg7=81*elem.pos(3)[0]; T reg8=0.99999999999999988898*elem.pos(1)[0]; reg2=reg4-reg2; reg5=reg5-reg7;
    reg4=27*elem.pos(1)[0]; reg6=reg1+reg6; reg1=8.9999999999999995004*elem.pos(1)[0]; reg5=reg5+reg4; reg1=reg6-reg1;
    reg6=0.99999999999999988898*elem.pos(0)[0]; reg2=reg8+reg2; reg8=reg2*reg1; T reg9=2*reg1; T reg10=reg6*reg5;
    T reg11=2*reg5; T reg12=reg2*reg5; T reg13=pow(reg1,2); T reg14=reg2*reg9; T reg15=reg6*reg1;
    T reg16=pow(reg2,2); reg10=reg8+reg10; reg8=reg1*reg5; T reg17=reg2*reg11; T reg18=reg1*reg9;
    reg9=reg5*reg9; T reg19=reg1*reg11; reg13=reg12+reg13; T reg20=pow(reg5,2); T reg21=reg5*reg11;
    T reg22=reg19+reg8; reg9=reg19+reg9; reg13=reg12+reg13; reg15=reg16+reg15; reg18=reg17+reg18;
    reg10=reg14+reg10; reg15=reg15/2; reg12=reg21+reg20; reg14=2*reg21; reg22=reg8+reg22;
    reg10=0.5*reg10; reg6=reg2*reg6; reg9=reg19+reg9; reg13=reg18+reg13; reg22=reg9+reg22;
    reg14=reg21+reg14; reg13=0.16666666666666666667*reg13; reg12=reg20+reg12; reg10=reg10/3; reg15=reg6+reg15;
    reg13=reg13/4; reg10=reg15+reg10; reg12=reg14+reg12; reg22=0.041666666666666666668*reg22; reg12=0.0083333333333333333337*reg12;
    reg13=reg10+reg13; reg6=0.5*reg5; reg22=reg22/5; reg1=reg1/2; reg22=reg13+reg22;
    reg12=reg12/6; reg1=reg2+reg1; reg6=reg6/3; reg12=reg22+reg12; reg6=reg1+reg6;
    res[0]=reg12/reg6;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Bar_4,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=81*elem.pos(2)[1]; T reg1=27*elem.pos(0)[1]; T reg2=44.999999999999999001*elem.pos(2)[1]; T reg3=27*elem.pos(0)[0]; T reg4=81*elem.pos(2)[0];
    T reg5=17.9999999999999995*elem.pos(0)[1]; T reg6=44.999999999999999001*elem.pos(2)[0]; T reg7=17.9999999999999995*elem.pos(0)[0]; reg2=reg5-reg2; reg5=35.9999999999999995*elem.pos(3)[1];
    T reg8=5.4999999999999996392*elem.pos(0)[1]; T reg9=35.9999999999999995*elem.pos(3)[0]; reg6=reg7-reg6; reg7=8.9999999999999995004*elem.pos(2)[1]; T reg10=5.4999999999999996392*elem.pos(0)[0];
    T reg11=reg4-reg3; T reg12=81*elem.pos(3)[0]; T reg13=reg0-reg1; T reg14=8.9999999999999995004*elem.pos(2)[0]; T reg15=81*elem.pos(3)[1];
    reg10=reg14-reg10; reg9=reg6+reg9; reg6=8.9999999999999995004*elem.pos(1)[0]; reg14=4.4999999999999997502*elem.pos(3)[0]; reg13=reg13-reg15;
    reg11=reg11-reg12; T reg16=27*elem.pos(1)[0]; reg5=reg2+reg5; reg2=4.4999999999999997502*elem.pos(3)[1]; reg8=reg7-reg8;
    reg7=27*elem.pos(1)[1]; T reg17=8.9999999999999995004*elem.pos(1)[1]; reg6=reg9-reg6; reg11=reg11+reg16; reg17=reg5-reg17;
    reg13=reg13+reg7; reg14=reg10-reg14; reg5=0.99999999999999988898*elem.pos(1)[0]; reg9=0.99999999999999988898*elem.pos(1)[1]; reg2=reg8-reg2;
    reg8=2*reg11; reg5=reg14+reg5; reg10=2*reg13; reg14=2*reg6; T reg18=2*reg17;
    reg2=reg9+reg2; reg9=reg17*reg18; T reg19=reg2*reg10; T reg20=reg2*reg18; T reg21=pow(reg5,2);
    T reg22=pow(reg2,2); T reg23=reg6*reg14; T reg24=reg5*reg14; T reg25=reg5*reg8; reg23=reg25+reg23;
    reg25=reg6*reg8; reg14=reg14*reg11; T reg26=reg17*reg10; reg18=reg18*reg13; reg9=reg19+reg9;
    reg22=reg21+reg22; reg20=reg24+reg20; reg18=reg26+reg18; reg9=reg23+reg9; reg19=3.5*reg20;
    reg21=pow(reg22,-4.5); reg14=reg25+reg14; reg23=2.5*reg20; reg24=pow(reg22,-3.5); reg14=reg25+reg14;
    reg25=2.5*reg9; reg19=reg21*reg19; reg18=reg26+reg18; reg19=reg23*reg19; reg23=reg24*reg23;
    reg21=reg13*reg10; reg25=reg24*reg25; reg24=1.5*reg20; reg26=pow(reg22,-2.5); T reg27=reg11*reg8;
    reg18=reg14+reg18; reg14=1.5*reg9; T reg28=reg24*reg23; reg19=reg25-reg19; reg25=reg26*reg14;
    T reg29=1.5*reg18; T reg30=2*reg27; T reg31=2*reg21; reg23=reg14*reg23; reg29=reg26*reg29;
    reg14=pow(reg22,-1.5); reg9=0.5*reg9; reg20=0.5*reg20; reg30=reg27+reg30; reg31=reg21+reg31;
    reg28=reg25-reg28; reg19=reg24*reg19; reg24=reg26*reg24; reg18=0.5*reg18; reg31=reg30+reg31;
    reg21=reg20*reg24; reg25=reg9*reg14; reg26=reg14*reg18; reg27=reg9*reg24; reg19=reg23+reg19;
    reg23=reg29-reg23; reg29=reg20*reg28; reg19=reg23-reg19; reg26=reg26-reg27; reg21=reg25-reg21;
    reg31=0.5*reg31; reg29=reg27+reg29; reg23=reg20*reg14; reg25=pow(reg22,-0.5); reg27=reg20*reg21;
    reg30=reg9*reg23; reg14=reg14*reg31; reg24=reg18*reg24; reg28=reg9*reg28; T reg32=reg25*reg18;
    reg19=reg20*reg19; reg29=reg26-reg29; reg26=reg20*reg23; T reg33=reg25*reg31; T reg34=reg23*reg18;
    T reg35=reg20*reg29; reg27=reg30+reg27; reg30=reg32-reg30; reg32=reg25*reg9; reg19=reg28+reg19;
    T reg36=reg9*reg21; reg14=reg14-reg24; reg28=reg24+reg28; reg26=reg32-reg26; reg25=reg25*reg20;
    reg14=reg14-reg28; reg24=reg34+reg36; reg34=reg33-reg34; reg19=reg28+reg19; reg27=reg30-reg27;
    reg35=reg36+reg35; reg35=reg24+reg35; reg28=2*reg25; reg22=pow(reg22,0.5); reg24=reg34-reg24;
    reg30=2*reg27; reg19=reg14-reg19; reg14=2*reg26; reg32=reg22*reg30; reg33=reg25*reg14;
    reg34=reg26*reg28; reg35=reg24-reg35; reg24=reg22*reg14; reg36=reg25*reg28; reg19=reg20*reg19;
    reg23=reg23*reg31; reg21=reg18*reg21; reg29=reg9*reg29; reg9=reg6*reg26; reg18=reg25*reg13;
    reg20=reg25*reg11; T reg37=reg22*reg28; T reg38=reg5*reg27; T reg39=reg21+reg29; T reg40=reg17*reg26;
    reg32=reg32+reg33; reg21=reg23+reg21; T reg41=2*reg35; reg34=reg33+reg34; reg36=reg24+reg36;
    reg19=reg29+reg19; reg24=reg2*reg27; reg29=2*reg37; reg19=reg39+reg19; reg33=reg18+reg40;
    reg24=reg40+reg24; reg39=reg21+reg39; reg21=reg23+reg21; reg23=reg11*reg26; reg40=reg6*reg27;
    T reg42=reg5*reg35; reg34=reg32+reg34; reg32=reg2*reg35; T reg43=2*reg36; T reg44=reg17*reg27;
    T reg45=reg13*reg26; T reg46=reg5*reg26; T reg47=pow(reg22,2); T reg48=reg6*reg25; T reg49=reg20+reg9;
    T reg50=reg17*reg25; T reg51=reg2*reg26; reg41=reg22*reg41; reg30=reg25*reg30; reg38=reg9+reg38;
    reg28=reg28*reg27; reg14=reg26*reg14; reg9=reg37*reg29; reg26=reg47*reg43; reg24=reg33+reg24;
    reg32=reg44+reg32; reg41=reg41+reg30; reg30=reg30+reg14; reg28=reg14+reg28; reg21=reg21+reg39;
    reg14=reg2*reg25; T reg52=2*reg34; reg51=reg50+reg51; reg42=reg40+reg42; reg40=reg23+reg40;
    reg25=reg5*reg25; reg46=reg48+reg46; reg38=reg49+reg38; reg44=reg45+reg44; reg19=reg39+reg19;
    reg39=reg46*reg37; reg41=reg41+reg30; reg19=reg21+reg19; reg28=reg30+reg28; reg21=reg37*reg24;
    reg52=reg47*reg52; reg43=reg37*reg43; reg30=reg51*reg36; T reg53=reg36*reg29; T reg54=reg45+reg44;
    T reg55=reg46*reg36; T reg56=reg14*reg34; T reg57=reg37*reg38; reg42=reg40+reg42; reg29=reg47*reg29;
    reg40=reg23+reg40; reg9=reg26+reg9; reg26=reg25*reg34; reg32=reg44+reg32; reg44=reg14*reg36;
    T reg58=reg25*reg36; T reg59=reg37*reg51; T reg60=reg14*reg37; reg52=reg52+reg43; reg53=reg43+reg53;
    reg43=reg57+reg55; T reg61=2*reg29; reg56=reg30+reg56; reg58=reg39+reg58; T reg62=reg11*reg27;
    reg42=reg40+reg42; T reg63=pow(reg47,2); T reg64=reg6*reg35; T reg65=reg25*reg37; reg30=reg21+reg30;
    reg26=reg55+reg26; reg44=reg59+reg44; reg35=reg17*reg35; reg28=reg41+reg28; reg41=2*reg9;
    reg32=reg54+reg32; reg55=reg2*reg19; reg27=reg13*reg27; reg19=reg5*reg19; T reg66=reg29*reg44;
    T reg67=reg37*reg49; T reg68=reg36*reg24; T reg69=reg60*reg9; T reg70=reg37*reg32; T reg71=reg38*reg36;
    T reg72=reg48*reg36; T reg73=reg29*reg61; T reg74=reg27+reg35; T reg75=reg46*reg34; reg41=reg63*reg41;
    T reg76=reg65*reg9; reg61=reg63*reg61; T reg77=reg14*reg28; T reg78=reg58*reg29; reg26=reg43+reg26;
    reg28=reg25*reg28; T reg79=reg51*reg34; reg19=reg64-reg19; T reg80=reg50*reg36; T reg81=reg37*reg33;
    T reg82=reg37*reg42; reg53=reg52+reg53; reg56=reg30+reg56; reg55=reg35-reg55; reg64=reg62+reg64;
    reg35=reg37*reg54; reg52=reg27+reg74; T reg83=reg36*reg33; reg76=reg78+reg76; reg80=reg81+reg80;
    T reg84=reg50*reg34; reg55=reg74+reg55; reg74=reg44*reg9; T reg85=reg70+reg68; reg28=reg75+reg28;
    T reg86=reg29*reg56; T reg87=reg60*reg29; reg77=reg79+reg77; T reg88=reg29*reg26; T reg89=reg58*reg9;
    T reg90=reg48*reg37; T reg91=reg37*reg50; T reg92=reg60*reg53; reg79=reg68+reg79; reg34=reg48*reg34;
    reg53=reg65*reg53; reg68=reg49*reg36; T reg93=reg82+reg71; T reg94=2*reg61; T reg95=reg65*reg29;
    reg73=reg41+reg73; reg41=pow(reg63,2); reg69=reg66+reg69; reg19=reg64+reg19; reg75=reg71+reg75;
    reg72=reg67+reg72; reg64=reg62+reg64; reg71=reg37*reg40; T reg96=reg93+reg75; T reg97=reg29*reg43;
    T reg98=reg39*reg9; T reg99=reg59*reg9; reg19=reg64+reg19; T reg100=reg29*reg30; reg77=reg79+reg77;
    reg79=reg85+reg79; T reg101=reg29*reg91; T reg102=reg27+reg52; reg94=reg41*reg94; T reg103=reg87*reg73;
    reg73=reg95*reg73; T reg104=reg76*reg61; reg55=reg52+reg55; reg52=reg87*reg61; T reg105=reg61*reg69;
    reg92=reg74+reg92; reg53=reg89+reg53; reg64=reg62+reg64; T reg106=reg71+reg68; reg34=reg68+reg34;
    reg74=reg86+reg74; reg68=reg29*reg59; T reg107=reg29*reg72; T reg108=reg90*reg9; reg89=reg88+reg89;
    reg28=reg75+reg28; reg9=reg91*reg9; reg75=reg29*reg80; reg84=reg83+reg84; reg83=reg35+reg83;
    T reg109=pow(reg41,2); T reg110=reg95*reg61; T reg111=reg39*reg29; T reg112=reg90*reg29; reg19=reg64+reg19;
    reg53=reg89+reg53; T reg113=reg29*reg81; T reg114=reg37*reg20; reg84=reg83+reg84; reg103=reg105+reg103;
    T reg115=reg37*reg45; T reg116=reg78*reg61; T reg117=reg29*reg67; T reg118=reg110*reg94; reg9=reg75+reg9;
    T reg119=reg61*reg101; T reg120=reg29*reg21; T reg121=pow(reg109,2); reg55=reg102+reg55; reg34=reg106+reg34;
    T reg122=reg112*reg61; reg108=reg107+reg108; reg92=reg74+reg92; reg73=reg104+reg73; T reg123=reg29*reg57;
    reg77=reg79+reg77; T reg124=reg20*reg36; T reg125=reg37*reg23; reg98=reg97+reg98; T reg126=reg61*reg66;
    T reg127=reg111*reg61; reg99=reg100+reg99; reg61=reg61*reg68; reg37=reg37*reg18; reg28=reg96+reg28;
    reg36=reg36*reg18; reg94=reg52*reg94; reg99=reg99/reg41; reg34=reg34/reg63; reg85=reg85/reg63;
    reg107=reg107/reg41; reg61=reg61/reg109; reg120=reg120/reg41; reg117=reg117/reg41; reg100=reg100/reg41;
    reg79=reg79/reg63; reg106=reg106/reg63; reg71=reg71/reg63; reg124=reg125+reg124; reg64=reg64/reg47;
    T reg128=reg29*reg114; reg28=reg28/reg63; reg36=reg115+reg36; reg29=reg29*reg37; reg88=reg88/reg41;
    reg102=reg102/reg47; reg35=reg35/reg63; reg83=reg83/reg63; reg127=reg127/reg109; reg98=reg98/reg41;
    reg97=reg97/reg41; reg96=reg96/reg63; reg123=reg123/reg41; reg93=reg93/reg63; reg82=reg82/reg63;
    reg19=reg19/reg47; reg113=reg113/reg41; reg84=reg84/reg63; reg75=reg75/reg41; reg89=reg89/reg41;
    reg53=reg53/reg41; reg9=reg9/reg41; reg119=reg119/reg109; reg116=reg116/reg109; reg55=reg55/reg47;
    reg118=reg118/reg121; reg70=reg70/reg63; reg122=reg122/reg109; reg108=reg108/reg41; reg126=reg126/reg109;
    reg92=reg92/reg41; reg74=reg74/reg41; reg104=reg104/reg109; reg103=reg103/reg109; reg121=reg94/reg121;
    reg86=reg86/reg41; reg77=reg77/reg63; reg73=reg73/reg109; reg105=reg105/reg109; reg32=reg32/reg47;
    reg75=reg84-reg75; reg21=reg21/reg63; reg26=reg26/reg63; reg111=reg111/reg41; reg30=reg30/reg63;
    reg119=reg9-reg119; reg43=reg43/reg63; reg68=reg68/reg41; reg57=reg57/reg63; reg70=reg55-reg70;
    reg118=reg73-reg118; reg116=reg89-reg116; reg122=reg108-reg122; reg42=reg42/reg47; reg56=reg56/reg63;
    reg66=reg66/reg41; reg104=reg53-reg104; reg36=reg36/reg63; reg29=reg29/reg41; reg121=reg103-reg121;
    reg127=reg98-reg127; reg27=reg27/reg47; reg97=reg96-reg97; reg88=reg28-reg88; reg123=reg93-reg123;
    reg54=reg54/reg47; reg110=reg110/reg109; reg81=reg81/reg63; reg82=reg19-reg82; reg80=reg80/reg63;
    reg35=reg102-reg35; reg115=reg115/reg63; reg76=reg76/reg41; reg101=reg101/reg41; reg113=reg83-reg113;
    reg78=reg78/reg41; reg126=reg74-reg126; reg120=reg85-reg120; reg105=reg92-reg105; reg124=reg124/reg63;
    reg117=reg106-reg117; reg62=reg62/reg47; reg125=reg125/reg63; reg128=reg128/reg41; reg86=reg77-reg86;
    reg109=reg52/reg109; reg112=reg112/reg41; reg69=reg69/reg41; reg72=reg72/reg63; reg100=reg79-reg100;
    reg71=reg64-reg71; reg67=reg67/reg63; reg40=reg40/reg47; reg107=reg34-reg107; reg61=reg99-reg61;
    reg123=reg82-reg123; reg125=reg62-reg125; reg126=reg86-reg126; reg58=reg58/reg63; reg81=reg54-reg81;
    reg95=reg95/reg41; reg128=reg124-reg128; reg101=reg80-reg101; reg39=reg39/reg63; reg38=reg38/reg47;
    reg110=reg76-reg110; reg67=reg40-reg67; reg90=reg90/reg63; reg120=reg70-reg120; reg37=reg37/reg63;
    reg45=reg45/reg47; reg127=reg97-reg127; reg49=reg49/reg47; reg116=reg88-reg116; reg115=reg27-reg115;
    reg29=reg36-reg29; reg121=reg105-reg121; reg61=reg100-reg61; reg119=reg75-reg119; reg109=reg69-reg109;
    reg117=reg71-reg117; reg118=reg104-reg118; reg68=reg30-reg68; reg21=reg32-reg21; reg111=reg43-reg111;
    reg23=reg23/reg47; reg41=reg87/reg41; reg44=reg44/reg63; reg57=reg42-reg57; reg59=reg59/reg63;
    reg112=reg72-reg112; reg113=reg35-reg113; reg66=reg56-reg66; reg78=reg26-reg78; reg114=reg114/reg63;
    reg122=reg107-reg122; reg33=reg33/reg47; reg91=reg91/reg63; reg24=reg24/reg47; reg68=reg21-reg68;
    reg20=reg20/reg47; reg29=reg115-reg29; reg112=reg67-reg112; reg127=reg123-reg127; reg61=reg120-reg61;
    reg122=reg117-reg122; reg121=reg126-reg121; reg118=reg116-reg118; reg114=reg23-reg114; reg101=reg81-reg101;
    reg128=reg125-reg128; reg95=reg58-reg95; reg18=reg18/reg47; reg91=reg33-reg91; reg39=reg38-reg39;
    reg59=reg24-reg59; reg41=reg44-reg41; reg111=reg57-reg111; reg90=reg49-reg90; reg110=reg78-reg110;
    reg109=reg66-reg109; reg37=reg45-reg37; reg119=reg113-reg119; reg9=reg13/reg22; reg50=reg50/reg47;
    reg60=reg60/reg63; reg63=reg65/reg63; reg51=reg51/reg47; reg121=reg61-reg121; reg110=reg111-reg110;
    reg101=reg37+reg101; reg112=reg114+reg112; reg109=reg68-reg109; reg118=reg127-reg118; reg122=reg128+reg122;
    reg119=reg29+reg119; reg41=reg59-reg41; reg91=reg18+reg91; reg46=reg46/reg47; reg95=reg39-reg95;
    reg90=reg20+reg90; reg18=reg11/reg22; reg48=reg48/reg47; reg48=reg18-reg48; reg63=reg46-reg63;
    reg50=reg9-reg50; reg60=reg51-reg60; reg95=reg90+reg95; reg41=reg91+reg41; reg109=reg101+reg109;
    reg110=reg112+reg110; reg121=reg119+reg121; reg118=reg122+reg118; reg63=reg48-reg63; reg118=reg5*reg118;
    reg9=reg13*reg41; reg18=reg17*reg109; reg60=reg50-reg60; reg14=reg14/reg47; reg19=reg17/reg22;
    reg47=reg25/reg47; reg20=reg6/reg22; reg21=reg6*reg110; reg23=reg11*reg95; reg121=reg2*reg121;
    reg118=reg21+reg118; reg24=reg9+reg18; reg14=reg19-reg14; reg47=reg20-reg47; reg121=reg18+reg121;
    reg110=reg5*reg110; reg18=reg11*reg63; reg19=reg13*reg60; reg20=reg17*reg41; reg25=reg6*reg95;
    reg109=reg2*reg109; reg21=reg23+reg21; reg26=reg6*reg63; reg95=reg5*reg95; reg27=reg47*reg11;
    reg28=reg17*reg60; reg41=reg2*reg41; reg29=reg14*reg13; reg30=reg18-reg25; reg32=reg23+reg21;
    reg33=reg2/reg22; reg22=reg5/reg22; reg118=reg21+reg118; reg109=reg20+reg109; reg20=reg19-reg20;
    reg21=reg9+reg24; reg121=reg24+reg121; reg110=reg25+reg110; reg24=reg9+reg21; reg95=reg26-reg95;
    reg121=reg21+reg121; reg26=reg26+reg27; reg41=reg28-reg41; reg110=reg30-reg110; reg28=reg28+reg29;
    reg30=reg18+reg30; reg109=reg20-reg109; reg20=reg19+reg20; reg21=reg33*reg13; reg25=reg22*reg11;
    reg60=reg2*reg60; reg34=reg6*reg47; reg35=reg17*reg14; reg63=reg5*reg63; reg118=reg32+reg118;
    reg32=reg23+reg32; reg25=reg34+reg25; reg34=reg63+reg34; reg18=reg18+reg30; reg30=reg110+reg30;
    reg47=reg5*reg47; reg36=reg22*reg6; reg23=reg23+reg32; reg32=reg118+reg32; reg21=reg35+reg21;
    reg29=reg29+reg28; reg28=reg41+reg28; reg121=reg121+reg24; reg24=reg9+reg24; reg35=reg60+reg35;
    reg109=reg109+reg20; reg27=reg27+reg26; reg26=reg95+reg26; reg14=reg2*reg14; reg9=reg33*reg17;
    reg20=reg19+reg20; reg21=reg35+reg21; reg33=reg2*reg33; reg22=reg5*reg22; reg20=reg109+reg20;
    reg25=reg34+reg25; reg18=reg30+reg18; reg9=reg14+reg9; reg23=reg32+reg23; reg36=reg47+reg36;
    reg29=reg28+reg29; reg24=reg121+reg24; reg27=reg26+reg27; reg14=0.99999999999999988898*elem.pos(0)[0]; reg19=0.99999999999999988898*elem.pos(0)[1];
    reg20=reg18+reg20; reg9=reg36+reg9; reg24=reg23+reg24; reg29=reg27+reg29; reg33=reg22+reg33;
    reg21=reg25+reg21; reg18=reg11*reg21; reg22=reg14*reg24; reg23=reg14*reg20; reg25=reg5*reg29;
    reg26=reg6*reg29; reg27=reg6*reg21; reg28=reg21*reg19; reg30=reg13*reg21; reg32=reg17*reg29;
    reg34=reg24*reg19; reg35=reg33*reg6; reg36=reg14*reg29; reg37=reg5*reg21; reg38=reg2*reg20;
    reg6=reg6*reg9; reg39=reg9*reg13; reg40=reg33*reg11; reg41=reg17*reg21; reg42=reg2*reg29;
    reg43=reg20*reg19; reg44=reg5*reg9; reg45=reg14*reg21; reg46=reg2*reg9; reg47=reg5*reg20;
    reg48=reg33*reg13; reg49=reg17*reg9; reg17=reg33*reg17; reg50=reg2*reg21; reg51=reg29*reg19;
    reg52=reg9*reg11; reg53=reg32+reg30; reg32=reg38+reg32; reg28=reg28+reg46; reg34=reg38-reg34;
    reg2=reg2*reg33; reg38=reg9*reg19; reg17=reg46+reg17; reg46=reg41+reg39; reg51=reg51+reg50;
    reg41=reg42+reg41; reg42=reg43+reg42; reg43=reg26+reg18; reg50=reg50+reg49; reg48=reg49+reg48;
    reg26=reg47+reg26; reg23=reg23+reg25; reg25=reg25+reg27; reg27=reg27+reg52; reg45=reg45+reg44;
    reg40=reg6+reg40; reg6=reg37+reg6; reg37=reg36+reg37; reg35=reg44+reg35; reg22=reg47-reg22;
    reg5=reg5*reg33; reg36=reg14*reg9; reg2=reg38+reg2; reg38=reg30+reg53; reg23=reg23+reg25;
    reg53=reg32+reg53; reg17=reg28+reg17; reg25=reg25+reg27; reg27=reg52+reg27; reg51=reg51+reg50;
    reg48=reg50+reg48; reg40=reg6+reg40; reg32=reg34+reg32; reg42=reg42+reg41; reg6=reg37+reg6;
    reg35=reg45+reg35; reg41=reg41+reg46; reg46=reg39+reg46; reg5=reg36+reg5; reg22=reg22+reg26;
    reg26=reg26+reg43; reg43=reg18+reg43; reg48=reg51+reg48; reg14=reg14*reg33; reg27=reg25+reg27;
    reg32=reg32+reg53; reg25=reg23+reg25; reg17=0.5*reg17; reg53=reg53+reg38; reg40=reg6+reg40;
    reg21=0.5*reg21; reg38=reg30+reg38; reg5=reg5/2; reg35=0.5*reg35; reg9=reg9/2;
    reg18=reg18+reg43; reg19=reg33*reg19; reg42=reg42+reg41; reg2=reg2/2; reg46=reg41+reg46;
    reg43=reg26+reg43; reg26=reg22+reg26; reg48=0.16666666666666666667*reg48; reg35=reg35/3; reg40=0.16666666666666666667*reg40;
    reg46=reg42+reg46; reg26=reg26+reg43; reg5=reg14+reg5; reg18=reg43+reg18; reg9=reg33+reg9;
    reg21=reg21/3; reg17=reg17/3; reg2=reg19+reg2; reg38=reg53+reg38; reg29=0.16666666666666666667*reg29;
    reg53=reg32+reg53; reg27=reg25+reg27; reg35=reg5+reg35; reg27=0.041666666666666666668*reg27; reg21=reg9+reg21;
    reg29=reg29/4; reg48=reg48/4; reg17=reg2+reg17; reg46=0.041666666666666666668*reg46; reg40=reg40/4;
    reg38=reg53+reg38; reg18=reg26+reg18; reg20=0.041666666666666666668*reg20; reg48=reg17+reg48; reg38=0.0083333333333333333337*reg38;
    reg18=0.0083333333333333333337*reg18; reg40=reg35+reg40; reg27=reg27/5; reg46=reg46/5; reg2=0.0083333333333333333337*reg24;
    reg20=reg20/5; reg29=reg21+reg29; reg27=reg40+reg27; reg18=reg18/6; reg46=reg48+reg46;
    reg38=reg38/6; reg2=reg2/6; reg20=reg29+reg20; reg38=reg46+reg38; reg18=reg27+reg18;
    reg2=reg20-reg2; res[0]=reg18/reg2; res[1]=reg38/reg2;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Bar_4,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=44.999999999999999001*elem.pos(2)[1]; T reg1=17.9999999999999995*elem.pos(0)[1]; T reg2=44.999999999999999001*elem.pos(2)[0]; T reg3=17.9999999999999995*elem.pos(0)[0]; T reg4=27*elem.pos(0)[1];
    T reg5=81*elem.pos(2)[1]; T reg6=81*elem.pos(2)[0]; T reg7=27*elem.pos(0)[0]; T reg8=5.4999999999999996392*elem.pos(0)[1]; T reg9=8.9999999999999995004*elem.pos(2)[1];
    T reg10=35.9999999999999995*elem.pos(3)[0]; reg2=reg3-reg2; reg3=5.4999999999999996392*elem.pos(0)[0]; T reg11=8.9999999999999995004*elem.pos(2)[0]; T reg12=81*elem.pos(3)[1];
    T reg13=27*elem.pos(0)[2]; T reg14=44.999999999999999001*elem.pos(2)[2]; T reg15=17.9999999999999995*elem.pos(0)[2]; T reg16=81*elem.pos(3)[0]; T reg17=81*elem.pos(2)[2];
    T reg18=reg5-reg4; T reg19=35.9999999999999995*elem.pos(3)[1]; reg0=reg1-reg0; reg1=reg6-reg7; reg18=reg18-reg12;
    T reg20=8.9999999999999995004*elem.pos(2)[2]; T reg21=5.4999999999999996392*elem.pos(0)[2]; T reg22=reg17-reg13; T reg23=27*elem.pos(1)[1]; T reg24=4.4999999999999997502*elem.pos(3)[1];
    reg8=reg9-reg8; reg10=reg2+reg10; reg2=8.9999999999999995004*elem.pos(1)[0]; reg9=27*elem.pos(1)[0]; T reg25=4.4999999999999997502*elem.pos(3)[0];
    reg3=reg11-reg3; reg1=reg1-reg16; reg11=81*elem.pos(3)[2]; reg19=reg0+reg19; reg0=8.9999999999999995004*elem.pos(1)[1];
    T reg26=35.9999999999999995*elem.pos(3)[2]; reg14=reg15-reg14; reg15=8.9999999999999995004*elem.pos(1)[2]; reg26=reg14+reg26; reg0=reg19-reg0;
    reg1=reg1+reg9; reg2=reg10-reg2; reg10=27*elem.pos(1)[2]; reg22=reg22-reg11; reg14=0.99999999999999988898*elem.pos(1)[0];
    reg25=reg3-reg25; reg3=0.99999999999999988898*elem.pos(1)[1]; reg24=reg8-reg24; reg18=reg18+reg23; reg21=reg20-reg21;
    reg8=4.4999999999999997502*elem.pos(3)[2]; reg15=reg26-reg15; reg19=2*reg0; reg22=reg22+reg10; reg20=2*reg18;
    reg26=2*reg2; T reg27=0.99999999999999988898*elem.pos(1)[2]; reg24=reg3+reg24; reg3=2*reg1; reg8=reg21-reg8;
    reg25=reg14+reg25; reg14=2*reg15; reg21=pow(reg24,2); T reg28=reg0*reg19; T reg29=reg24*reg20;
    T reg30=reg24*reg19; T reg31=reg2*reg26; T reg32=reg25*reg3; T reg33=2*reg22; T reg34=reg25*reg26;
    T reg35=pow(reg25,2); reg8=reg27+reg8; reg31=reg32+reg31; reg28=reg29+reg28; reg27=reg8*reg33;
    reg29=reg15*reg14; reg19=reg19*reg18; reg32=reg0*reg20; reg26=reg26*reg1; T reg36=reg2*reg3;
    reg21=reg35+reg21; reg35=pow(reg8,2); reg30=reg34+reg30; reg34=reg8*reg14; reg35=reg21+reg35;
    reg34=reg30+reg34; reg28=reg31+reg28; reg29=reg27+reg29; reg26=reg36+reg26; reg21=reg15*reg33;
    reg14=reg14*reg22; reg19=reg32+reg19; reg27=3.5*reg34; reg30=pow(reg35,-4.5); reg14=reg21+reg14;
    reg29=reg28+reg29; reg19=reg32+reg19; reg26=reg36+reg26; reg28=2.5*reg29; reg31=reg18*reg20;
    reg32=reg1*reg3; reg14=reg21+reg14; reg21=pow(reg35,-3.5); reg36=2.5*reg34; reg19=reg26+reg19;
    reg27=reg30*reg27; reg28=reg21*reg28; reg27=reg36*reg27; reg26=reg22*reg33; reg30=2*reg31;
    T reg37=2*reg32; T reg38=1.5*reg34; T reg39=1.5*reg29; T reg40=pow(reg35,-2.5); reg36=reg21*reg36;
    reg14=reg19+reg14; reg19=2*reg26; reg30=reg31+reg30; reg21=1.5*reg14; reg37=reg32+reg37;
    reg27=reg28-reg27; reg28=reg40*reg39; reg31=reg38*reg36; reg29=0.5*reg29; reg32=pow(reg35,-1.5);
    T reg41=reg40*reg38; reg14=0.5*reg14; reg19=reg26+reg19; reg34=0.5*reg34; reg31=reg28-reg31;
    reg30=reg37+reg30; reg27=reg38*reg27; reg36=reg39*reg36; reg21=reg40*reg21; reg26=reg29*reg32;
    reg28=reg34*reg31; reg37=reg34*reg41; reg38=reg29*reg41; reg39=reg32*reg14; reg19=reg30+reg19;
    reg27=reg36+reg27; reg36=reg21-reg36; reg21=pow(reg35,-0.5); reg39=reg39-reg38; reg19=0.5*reg19;
    reg37=reg26-reg37; reg28=reg38+reg28; reg26=reg34*reg32; reg27=reg36-reg27; reg28=reg39-reg28;
    reg31=reg29*reg31; reg30=reg34*reg37; reg41=reg14*reg41; reg27=reg34*reg27; reg32=reg32*reg19;
    reg36=reg29*reg26; reg38=reg21*reg14; reg39=reg34*reg28; reg32=reg32-reg41; reg27=reg31+reg27;
    reg38=reg38-reg36; reg31=reg41+reg31; reg30=reg36+reg30; reg36=reg21*reg19; reg40=reg29*reg37;
    reg41=reg34*reg26; T reg42=reg26*reg14; T reg43=reg21*reg29; reg32=reg32-reg31; reg30=reg38-reg30;
    reg39=reg40+reg39; reg27=reg31+reg27; reg40=reg42+reg40; reg42=reg36-reg42; reg21=reg21*reg34;
    reg41=reg43-reg41; reg27=reg32-reg27; reg31=2*reg41; reg35=pow(reg35,0.5); reg32=2*reg30;
    reg36=2*reg21; reg39=reg40+reg39; reg40=reg42-reg40; reg27=reg34*reg27; reg34=reg35*reg31;
    reg38=reg21*reg36; reg42=reg41*reg36; reg43=reg21*reg31; T reg44=reg35*reg32; reg39=reg40-reg39;
    reg26=reg26*reg19; reg37=reg14*reg37; reg28=reg29*reg28; reg38=reg34+reg38; reg14=reg26+reg37;
    reg29=reg21*reg18; reg34=reg0*reg41; reg40=reg24*reg30; T reg45=reg2*reg41; reg42=reg43+reg42;
    T reg46=reg21*reg1; T reg47=2*reg39; T reg48=reg25*reg30; reg43=reg44+reg43; reg44=reg35*reg36;
    reg37=reg37+reg28; reg27=reg28+reg27; reg48=reg45+reg48; reg47=reg35*reg47; reg27=reg37+reg27;
    reg32=reg21*reg32; reg28=reg1*reg41; T reg49=pow(reg35,2); T reg50=reg18*reg41; T reg51=2*reg44;
    T reg52=2*reg38; T reg53=reg29+reg34; reg40=reg34+reg40; reg42=reg43+reg42; reg34=reg2*reg21;
    reg43=reg25*reg41; T reg54=reg21*reg22; T reg55=reg15*reg41; T reg56=reg8*reg30; T reg57=reg25*reg39;
    T reg58=reg2*reg30; reg31=reg41*reg31; reg36=reg36*reg30; reg37=reg14+reg37; T reg59=reg0*reg21;
    T reg60=reg0*reg30; T reg61=reg24*reg41; T reg62=reg24*reg39; reg14=reg26+reg14; reg45=reg46+reg45;
    reg26=reg32+reg31; T reg63=reg22*reg41; reg14=reg14+reg37; reg36=reg31+reg36; reg31=reg24*reg21;
    reg57=reg58+reg57; reg56=reg55+reg56; reg62=reg60+reg62; reg55=reg54+reg55; T reg64=2*reg42;
    T reg65=reg44*reg51; T reg66=reg49*reg52; T reg67=reg25*reg21; T reg68=reg15*reg21; reg61=reg59+reg61;
    reg27=reg37+reg27; reg32=reg47+reg32; reg41=reg8*reg41; reg60=reg50+reg60; reg37=reg15*reg30;
    reg48=reg45+reg48; reg47=reg8*reg39; reg43=reg34+reg43; reg58=reg28+reg58; reg40=reg53+reg40;
    T reg69=reg44*reg40; T reg70=reg67*reg42; T reg71=reg31*reg38; T reg72=reg38*reg51; T reg73=reg61*reg38;
    T reg74=reg44*reg61; reg52=reg44*reg52; reg64=reg49*reg64; T reg75=reg31*reg42; T reg76=reg43*reg38;
    T reg77=reg44*reg48; reg57=reg58+reg57; reg56=reg55+reg56; reg21=reg8*reg21; reg36=reg26+reg36;
    reg26=reg32+reg26; reg58=reg28+reg58; reg41=reg68+reg41; reg32=reg63+reg37; reg65=reg66+reg65;
    reg66=reg67*reg38; reg51=reg49*reg51; reg27=reg14+reg27; reg14=reg50+reg60; reg47=reg37+reg47;
    reg62=reg60+reg62; reg37=reg43*reg44; reg60=reg2*reg39; reg75=reg73+reg75; T reg78=reg77+reg76;
    T reg79=reg25*reg27; reg47=reg32+reg47; T reg80=reg0*reg39; reg57=reg58+reg57; T reg81=2*reg51;
    T reg82=reg44*reg56; T reg83=reg44*reg41; T reg84=reg21*reg38; reg32=reg63+reg32; reg66=reg37+reg66;
    reg36=reg26+reg36; reg62=reg14+reg62; reg26=2*reg65; T reg85=reg21*reg42; reg70=reg76+reg70;
    reg71=reg74+reg71; reg76=reg1*reg30; T reg86=reg18*reg30; T reg87=pow(reg49,2); T reg88=reg31*reg44;
    reg73=reg69+reg73; T reg89=reg41*reg38; T reg90=reg67*reg44; reg64=reg64+reg52; T reg91=reg24*reg27;
    reg72=reg52+reg72; reg79=reg60-reg79; reg52=reg44*reg45; reg91=reg80-reg91; T reg92=reg21*reg44;
    T reg93=reg34*reg38; reg39=reg15*reg39; T reg94=reg44*reg53; reg60=reg76+reg60; T reg95=reg61*reg42;
    reg85=reg89+reg85; reg80=reg86+reg80; reg47=reg32+reg47; reg26=reg87*reg26; reg70=reg78+reg70;
    T reg96=reg48*reg38; T reg97=reg51*reg81; T reg98=reg31*reg36; reg72=reg64+reg72; reg64=reg66*reg51;
    reg27=reg8*reg27; T reg99=reg90*reg65; reg89=reg82+reg89; T reg100=reg43*reg42; T reg101=reg44*reg57;
    reg75=reg73+reg75; reg81=reg87*reg81; reg30=reg22*reg30; T reg102=reg51*reg71; T reg103=reg59*reg38;
    reg84=reg83+reg84; T reg104=reg88*reg65; T reg105=reg67*reg36; T reg106=reg44*reg62; T reg107=reg38*reg40;
    T reg108=reg101+reg96; reg104=reg102+reg104; reg91=reg80+reg91; T reg109=reg71*reg65; reg103=reg94+reg103;
    T reg110=reg106+reg107; reg107=reg107+reg95; reg93=reg52+reg93; reg99=reg64+reg99; reg96=reg96+reg100;
    T reg111=reg88*reg72; reg79=reg60+reg79; T reg112=reg45*reg38; reg85=reg89+reg85; reg105=reg100+reg105;
    reg100=reg51*reg84; T reg113=reg92*reg65; T reg114=reg59*reg42; T reg115=reg44*reg55; reg36=reg21*reg36;
    T reg116=reg51*reg75; T reg117=reg51*reg70; T reg118=reg90*reg51; T reg119=reg66*reg65; T reg120=reg68*reg38;
    T reg121=pow(reg87,2); T reg122=2*reg81; T reg123=reg34*reg42; reg27=reg39-reg27; reg97=reg26+reg97;
    reg26=reg44*reg59; T reg124=reg88*reg51; T reg125=reg90*reg72; T reg126=reg41*reg42; T reg127=reg44*reg58;
    reg39=reg30+reg39; reg80=reg86+reg80; T reg128=reg38*reg56; T reg129=reg44*reg47; reg98=reg95+reg98;
    reg60=reg76+reg60; reg95=reg34*reg44; T reg130=reg44*reg14; T reg131=reg38*reg53; T reg132=reg86+reg80;
    T reg133=reg118*reg97; T reg134=reg99*reg81; reg27=reg39+reg27; T reg135=reg76+reg60; reg122=reg121*reg122;
    T reg136=reg118*reg81; T reg137=pow(reg121,2); T reg138=reg124*reg81; T reg139=reg128+reg126; reg79=reg60+reg79;
    reg125=reg119+reg125; reg98=reg107+reg98; reg60=reg51*reg73; T reg140=reg51*reg26; reg107=reg110+reg107;
    T reg141=reg130+reg131; T reg142=reg81*reg104; T reg143=reg124*reg97; reg114=reg131+reg114; reg131=reg51*reg74;
    reg113=reg100+reg113; T reg144=reg51*reg103; T reg145=reg74*reg65; reg36=reg126+reg36; reg126=reg26*reg65;
    reg111=reg109+reg111; reg128=reg129+reg128; T reg146=reg127+reg112; T reg147=reg44*reg32; T reg148=reg38*reg55;
    T reg149=reg44*reg68; T reg150=reg108+reg96; T reg151=reg37*reg65; reg119=reg117+reg119; reg123=reg112+reg123;
    reg112=reg95*reg51; T reg152=reg51*reg78; T reg153=reg51*reg85; reg72=reg92*reg72; reg42=reg68*reg42;
    reg91=reg80+reg91; reg80=reg84*reg65; T reg154=reg92*reg51; reg105=reg96+reg105; reg109=reg116+reg109;
    reg120=reg115+reg120; reg96=reg95*reg65; reg39=reg30+reg39; T reg155=reg37*reg51; T reg156=reg51*reg93;
    T reg157=reg46*reg38; T reg158=reg44*reg28; reg97=reg154*reg97; T reg159=reg81*reg102; T reg160=reg44*reg46;
    T reg161=reg153+reg80; reg42=reg148+reg42; T reg162=reg83*reg65; reg91=reg132+reg91; T reg163=reg81*reg113;
    T reg164=reg51*reg89; reg36=reg139+reg36; reg98=reg107+reg98; T reg165=reg81*reg140; T reg166=reg155*reg81;
    reg148=reg147+reg148; reg139=reg128+reg139; reg111=reg109+reg111; T reg167=reg30+reg39; T reg168=reg51*reg83;
    T reg169=reg81*reg131; reg145=reg60+reg145; reg151=reg152+reg151; T reg170=reg38*reg29; T reg171=reg51*reg149;
    reg65=reg149*reg65; reg125=reg119+reg125; T reg172=reg51*reg52; T reg173=reg51*reg120; T reg174=reg51*reg77;
    T reg175=reg112*reg81; reg96=reg156+reg96; reg133=reg134+reg133; reg27=reg39+reg27; reg39=reg44*reg50;
    T reg176=reg136*reg122; T reg177=pow(reg137,2); T reg178=reg64*reg81; reg79=reg135+reg79; reg123=reg146+reg123;
    T reg179=reg51*reg94; T reg180=reg44*reg29; T reg181=reg138*reg122; reg114=reg141+reg114; reg105=reg150+reg105;
    reg126=reg144+reg126; reg72=reg80+reg72; reg80=reg51*reg69; T reg182=reg154*reg81; reg143=reg142+reg143;
    reg175=reg175/reg137; reg96=reg96/reg121; reg146=reg146/reg87; reg181=reg181/reg177; reg109=reg109/reg121;
    reg123=reg123/reg87; reg172=reg172/reg121; reg159=reg159/reg137; reg135=reg135/reg49; T reg183=reg51*reg160;
    reg142=reg142/reg137; T reg184=reg44*reg63; reg143=reg143/reg137; reg156=reg156/reg121; reg127=reg127/reg87;
    reg111=reg111/reg121; reg44=reg44*reg54; reg157=reg158+reg157; reg27=reg167+reg27; reg176=reg176/reg177;
    reg116=reg116/reg121; reg98=reg98/reg87; T reg185=reg51*reg82; reg170=reg39+reg170; T reg186=reg51*reg180;
    reg132=reg132/reg49; reg130=reg130/reg87; reg162=reg164+reg162; T reg187=reg81*reg168; reg141=reg141/reg87;
    reg179=reg179/reg121; reg114=reg114/reg87; reg144=reg144/reg121; reg126=reg126/reg121; reg165=reg165/reg137;
    reg36=reg139+reg36; reg91=reg91/reg49; T reg188=reg81*reg100; reg106=reg106/reg87; reg110=reg110/reg87;
    reg80=reg80/reg121; reg72=reg161+reg72; reg107=reg107/reg87; reg97=reg163+reg97; reg122=reg182*reg122;
    reg60=reg60/reg121; reg145=reg145/reg121; reg169=reg169/reg137; reg152=reg152/reg121; reg151=reg151/reg121;
    reg166=reg166/reg137; reg150=reg150/reg87; T reg189=reg51*reg115; reg42=reg148+reg42; reg105=reg105/reg87;
    reg117=reg117/reg121; reg174=reg174/reg121; reg119=reg119/reg121; reg178=reg178/reg137; reg108=reg108/reg87;
    reg101=reg101/reg87; reg65=reg173+reg65; reg79=reg79/reg49; reg133=reg133/reg137; reg134=reg134/reg137;
    reg81=reg81*reg171; reg38=reg38*reg54; reg125=reg125/reg121; reg152=reg150-reg152; reg169=reg145-reg169;
    reg116=reg98-reg116; reg106=reg91-reg106; reg156=reg123-reg156; reg174=reg108-reg174; reg175=reg96-reg175;
    reg60=reg107-reg60; reg80=reg110-reg80; reg101=reg79-reg101; reg134=reg125-reg134; reg176=reg133-reg176;
    reg86=reg86/reg49; reg39=reg39/reg87; reg172=reg146-reg172; reg170=reg170/reg87; reg178=reg119-reg178;
    reg186=reg186/reg121; reg130=reg132-reg130; reg117=reg105-reg117; reg183=reg183/reg121; reg179=reg141-reg179;
    reg166=reg151-reg166; reg144=reg114-reg144; reg157=reg157/reg87; reg158=reg158/reg87; reg165=reg126-reg165;
    reg76=reg76/reg49; reg93=reg93/reg87; reg112=reg112/reg121; reg57=reg57/reg49; reg77=reg77/reg87;
    reg78=reg78/reg87; reg155=reg155/reg121; reg70=reg70/reg87; reg127=reg135-reg127; reg64=reg64/reg121;
    reg99=reg99/reg121; reg136=reg136/reg137; reg51=reg51*reg44; reg38=reg184+reg38; reg14=reg14/reg49;
    reg94=reg94/reg87; reg103=reg103/reg87; reg140=reg140/reg121; reg62=reg62/reg49; reg69=reg69/reg87;
    reg73=reg73/reg87; reg131=reg131/reg121; reg75=reg75/reg87; reg102=reg102/reg121; reg104=reg104/reg121;
    reg138=reg138/reg137; reg177=reg122/reg177; reg97=reg97/reg137; reg163=reg163/reg137; reg72=reg72/reg121;
    reg188=reg188/reg137; reg161=reg161/reg121; reg153=reg153/reg121; reg36=reg36/reg87; reg187=reg187/reg137;
    reg162=reg162/reg121; reg164=reg164/reg121; reg139=reg139/reg87; reg185=reg185/reg121; reg128=reg128/reg87;
    reg129=reg129/reg87; reg27=reg27/reg49; reg81=reg81/reg137; reg65=reg65/reg121; reg173=reg173/reg121;
    reg42=reg42/reg87; reg189=reg189/reg121; reg148=reg148/reg87; reg147=reg147/reg87; reg167=reg167/reg49;
    reg58=reg58/reg49; reg52=reg52/reg87; reg159=reg109-reg159; reg181=reg143-reg181; reg142=reg111-reg142;
    reg160=reg160/reg87; reg176=reg134-reg176; reg168=reg168/reg121; reg52=reg58-reg52; reg89=reg89/reg87;
    reg37=reg37/reg87; reg112=reg93-reg112; reg48=reg48/reg49; reg82=reg82/reg87; reg47=reg47/reg49;
    reg77=reg57-reg77; reg174=reg101-reg174; reg95=reg95/reg87; reg45=reg45/reg49; reg155=reg78-reg155;
    reg171=reg171/reg121; reg172=reg127-reg172; reg64=reg70-reg64; reg120=reg120/reg87; reg129=reg27-reg129;
    reg178=reg117-reg178; reg173=reg42-reg173; reg113=reg113/reg121; reg137=reg182/reg137; reg81=reg65-reg81;
    reg124=reg124/reg121; reg71=reg71/reg87; reg74=reg74/reg87; reg40=reg40/reg49; reg26=reg26/reg87;
    reg183=reg157-reg183; reg53=reg53/reg49; reg189=reg148-reg189; reg100=reg100/reg121; reg147=reg167-reg147;
    reg85=reg85/reg87; reg118=reg118/reg121; reg66=reg66/reg87; reg28=reg28/reg49; reg166=reg152-reg166;
    reg187=reg162-reg187; reg94=reg14-reg94; reg165=reg144-reg165; reg140=reg103-reg140; reg153=reg36-reg153;
    reg181=reg142-reg181; reg188=reg161-reg188; reg69=reg62-reg69; reg80=reg106-reg80; reg131=reg73-reg131;
    reg163=reg72-reg163; reg30=reg30/reg49; reg102=reg75-reg102; reg175=reg156-reg175; reg159=reg116-reg159;
    reg138=reg104-reg138; reg177=reg97-reg177; reg169=reg60-reg169; reg184=reg184/reg87; reg186=reg170-reg186;
    reg136=reg99-reg136; reg180=reg180/reg87; reg50=reg50/reg49; reg39=reg86-reg39; reg51=reg51/reg121;
    reg179=reg130-reg179; reg158=reg76-reg158; reg164=reg139-reg164; reg115=reg115/reg87; reg185=reg128-reg185;
    reg38=reg38/reg87; reg32=reg32/reg49; reg46=reg46/reg49; reg137=reg113-reg137; reg74=reg40-reg74;
    reg185=reg129-reg185; reg124=reg71-reg124; reg177=reg163-reg177; reg100=reg85-reg100; reg169=reg80-reg169;
    reg26=reg53-reg26; reg29=reg29/reg49; reg188=reg153-reg188; reg186=reg39-reg186; reg81=reg173-reg81;
    reg118=reg66-reg118; reg95=reg45-reg95; reg37=reg48-reg37; reg165=reg179-reg165; reg176=reg178-reg176;
    reg187=reg164-reg187; reg181=reg159-reg181; reg184=reg30-reg184; reg168=reg89-reg168; reg160=reg28-reg160;
    reg166=reg174-reg166; reg180=reg50-reg180; reg82=reg47-reg82; reg44=reg44/reg87; reg112=reg52-reg112;
    reg51=reg38-reg51; reg63=reg63/reg49; reg183=reg158-reg183; reg189=reg147-reg189; reg136=reg64-reg136;
    reg171=reg120-reg171; reg55=reg55/reg49; reg149=reg149/reg87; reg155=reg77-reg155; reg138=reg102-reg138;
    reg175=reg172-reg175; reg56=reg56/reg49; reg83=reg83/reg87; reg131=reg69-reg131; reg84=reg84/reg87;
    reg121=reg154/reg121; reg115=reg32-reg115; reg140=reg94-reg140; reg181=reg169-reg181; reg88=reg88/reg87;
    reg137=reg100-reg137; reg136=reg155-reg136; reg61=reg61/reg49; reg59=reg59/reg49; reg14=reg18/reg35;
    reg44=reg63-reg44; reg187=reg185-reg187; reg90=reg90/reg87; reg43=reg43/reg49; reg34=reg34/reg49;
    reg165=reg186+reg165; reg27=reg1/reg35; reg140=reg180+reg140; reg138=reg131-reg138; reg177=reg188-reg177;
    reg175=reg183+reg175; reg95=reg46+reg95; reg176=reg166-reg176; reg51=reg184-reg51; reg112=reg160+reg112;
    reg118=reg37-reg118; reg81=reg189-reg81; reg168=reg82-reg168; reg26=reg29+reg26; reg121=reg84-reg121;
    reg83=reg56-reg83; reg124=reg74-reg124; reg171=reg115-reg171; reg149=reg55-reg149; reg54=reg54/reg49;
    reg121=reg83-reg121; reg124=reg26+reg124; reg149=reg54+reg149; reg34=reg27-reg34; reg81=reg51+reg81;
    reg118=reg95+reg118; reg90=reg43-reg90; reg138=reg140+reg138; reg177=reg187-reg177; reg176=reg175+reg176;
    reg59=reg14-reg59; reg88=reg61-reg88; reg137=reg168-reg137; reg87=reg92/reg87; reg171=reg44+reg171;
    reg41=reg41/reg49; reg136=reg112+reg136; reg181=reg165+reg181; reg14=reg22/reg35; reg68=reg68/reg49;
    reg26=reg2*reg136; reg27=reg18*reg124; reg28=reg1*reg118; reg137=reg171+reg137; reg31=reg31/reg49;
    reg29=reg0/reg35; reg30=reg2/reg35; reg67=reg67/reg49; reg32=reg0*reg138; reg87=reg41-reg87;
    reg121=reg149+reg121; reg181=reg24*reg181; reg68=reg14-reg68; reg90=reg34-reg90; reg177=reg81+reg177;
    reg88=reg59-reg88; reg176=reg25*reg176; reg136=reg25*reg136; reg177=reg8*reg177; reg138=reg24*reg138;
    reg14=reg15*reg137; reg34=reg27+reg32; reg36=reg22*reg121; reg67=reg30-reg67; reg31=reg29-reg31;
    reg181=reg32+reg181; reg29=reg18*reg88; reg30=reg15/reg35; reg49=reg21/reg49; reg87=reg68-reg87;
    reg21=reg28+reg26; reg32=reg0*reg124; reg37=reg1*reg90; reg38=reg2*reg118; reg176=reg26+reg176;
    reg181=reg34+reg181; reg26=reg36+reg14; reg177=reg14+reg177; reg14=reg22*reg87; reg39=reg15*reg121;
    reg138=reg32+reg138; reg137=reg8*reg137; reg32=reg29-reg32; reg136=reg38+reg136; reg38=reg37-reg38;
    reg49=reg30-reg49; reg30=reg24/reg35; reg40=reg25/reg35; reg41=reg31*reg18; reg124=reg24*reg124;
    reg42=reg0*reg88; reg43=reg67*reg1; reg118=reg25*reg118; reg44=reg2*reg90; reg34=reg27+reg34;
    reg45=reg28+reg21; reg176=reg21+reg176; reg21=reg36+reg26; reg46=reg29+reg32; reg138=reg32-reg138;
    reg88=reg24*reg88; reg32=reg0*reg31; reg47=reg30*reg18; reg48=reg40*reg1; reg50=reg37+reg38;
    reg136=reg38-reg136; reg38=reg2*reg67; reg51=reg49*reg22; reg121=reg8*reg121; reg52=reg15*reg87;
    reg90=reg25*reg90; reg53=reg42+reg41; reg124=reg42-reg124; reg118=reg44-reg118; reg44=reg44+reg43;
    reg42=reg28+reg45; reg176=reg45+reg176; reg35=reg8/reg35; reg137=reg39+reg137; reg39=reg14-reg39;
    reg181=reg34+reg181; reg34=reg27+reg34; reg177=reg26+reg177; reg121=reg52-reg121; reg26=reg36+reg21;
    reg118=reg118+reg44; reg44=reg43+reg44; reg41=reg41+reg53; reg53=reg124+reg53; reg52=reg52+reg51;
    reg177=reg21+reg177; reg90=reg90+reg38; reg48=reg38+reg48; reg21=reg30*reg0; reg31=reg24*reg31;
    reg38=reg35*reg22; reg43=reg40*reg2; reg27=reg27+reg34; reg28=reg28+reg42; reg88=reg88+reg32;
    reg42=reg176+reg42; reg29=reg29+reg46; reg34=reg181+reg34; reg46=reg138+reg46; reg47=reg32+reg47;
    reg37=reg37+reg50; reg50=reg136+reg50; reg137=reg39-reg137; reg39=reg14+reg39; reg87=reg8*reg87;
    reg32=reg15*reg49; reg67=reg25*reg67; reg36=reg36+reg26; reg26=reg177+reg26; reg47=reg88+reg47;
    reg48=reg90+reg48; reg38=reg32+reg38; reg44=reg118+reg44; reg32=reg87+reg32; reg28=reg42+reg28;
    reg27=reg34+reg27; reg29=reg46+reg29; reg37=reg50+reg37; reg137=reg137+reg39; reg39=reg14+reg39;
    reg43=reg67+reg43; reg21=reg31+reg21; reg49=reg8*reg49; reg14=reg35*reg15; reg40=reg25*reg40;
    reg41=reg53+reg41; reg51=reg51+reg52; reg52=reg121+reg52; reg30=reg24*reg30; reg27=reg28+reg27;
    reg29=reg37+reg29; reg47=reg48+reg47; reg41=reg44+reg41; reg35=reg8*reg35; reg30=reg40+reg30;
    reg38=reg32+reg38; reg21=reg43+reg21; reg39=reg137+reg39; reg51=reg52+reg51; reg14=reg49+reg14;
    reg36=reg26+reg36; reg35=reg30+reg35; reg26=0.99999999999999988898*elem.pos(0)[1]; reg14=reg21+reg14; reg21=0.99999999999999988898*elem.pos(0)[0];
    reg36=reg27+reg36; reg27=0.99999999999999988898*elem.pos(0)[2]; reg38=reg47+reg38; reg39=reg29+reg39; reg51=reg41+reg51;
    reg28=reg14*reg22; reg29=reg38*reg27; reg30=reg14*reg1; reg31=reg18*reg38; reg32=reg8*reg39;
    reg34=reg36*reg27; reg37=reg15*reg51; reg40=reg22*reg38; reg41=reg21*reg36; reg42=reg0*reg51;
    reg43=reg2*reg51; reg44=reg36*reg26; reg45=reg1*reg38; reg46=reg24*reg39; reg47=reg14*reg18;
    reg48=reg0*reg38; reg49=reg24*reg51; reg50=reg39*reg26; reg52=reg35*reg18; reg53=reg0*reg14;
    reg54=reg24*reg38; reg55=reg51*reg26; reg0=reg35*reg0; reg56=reg24*reg14; reg57=reg38*reg26;
    reg58=reg25*reg39; reg59=reg21*reg38; reg60=reg25*reg14; reg61=reg51*reg27; reg62=reg35*reg2;
    reg63=reg8*reg38; reg64=reg35*reg15; reg65=reg15*reg14; reg66=reg21*reg51; reg67=reg25*reg38;
    reg68=reg2*reg14; reg69=reg35*reg22; reg70=reg35*reg1; reg71=reg39*reg27; reg72=reg8*reg51;
    reg2=reg2*reg38; reg73=reg8*reg14; reg74=reg25*reg51; reg75=reg21*reg39; reg15=reg15*reg38;
    reg29=reg29+reg73; reg76=reg54+reg53; reg54=reg55+reg54; reg64=reg73+reg64; reg55=reg14*reg27;
    reg0=reg56+reg0; reg8=reg8*reg35; reg56=reg57+reg56; reg57=reg72+reg15; reg15=reg15+reg28;
    reg24=reg24*reg35; reg73=reg14*reg26; reg52=reg53+reg52; reg61=reg61+reg63; reg53=reg42+reg31;
    reg50=reg50+reg49; reg49=reg49+reg48; reg42=reg46+reg42; reg48=reg48+reg47; reg63=reg63+reg65;
    reg72=reg71+reg72; reg44=reg46-reg44; reg69=reg65+reg69; reg34=reg32-reg34; reg46=reg37+reg40;
    reg37=reg32+reg37; reg62=reg60+reg62; reg60=reg59+reg60; reg66=reg66+reg67; reg41=reg58-reg41;
    reg67=reg67+reg68; reg58=reg58+reg43; reg70=reg68+reg70; reg43=reg43+reg45; reg75=reg75+reg74;
    reg74=reg74+reg2; reg25=reg25*reg35; reg32=reg21*reg14; reg2=reg2+reg30; reg59=reg31+reg53;
    reg53=reg42+reg53; reg65=reg37+reg46; reg37=reg34+reg37; reg42=reg44+reg42; reg41=reg41+reg58;
    reg47=reg47+reg48; reg48=reg49+reg48; reg58=reg58+reg43; reg49=reg50+reg49; reg43=reg45+reg43;
    reg30=reg30+reg2; reg8=reg55+reg8; reg25=reg32+reg25; reg64=reg29+reg64; reg62=reg60+reg62;
    reg61=reg61+reg63; reg66=reg66+reg67; reg69=reg63+reg69; reg70=reg67+reg70; reg72=reg72+reg57;
    reg75=reg75+reg74; reg57=reg57+reg15; reg15=reg28+reg15; reg2=reg74+reg2; reg0=reg56+reg0;
    reg52=reg76+reg52; reg76=reg54+reg76; reg46=reg40+reg46; reg24=reg73+reg24; reg28=reg53+reg59;
    reg59=reg31+reg59; reg8=reg8/2; reg26=reg35*reg26; reg37=reg37+reg65; reg24=reg24/2;
    reg62=0.5*reg62; reg38=0.5*reg38; reg64=0.5*reg64; reg40=reg40+reg46; reg0=0.5*reg0;
    reg30=reg2+reg30; reg27=reg35*reg27; reg21=reg21*reg35; reg46=reg65+reg46; reg2=reg75+reg2;
    reg14=reg14/2; reg29=reg58+reg43; reg43=reg45+reg43; reg58=reg41+reg58; reg15=reg57+reg15;
    reg52=reg76+reg52; reg49=reg49+reg48; reg47=reg48+reg47; reg57=reg72+reg57; reg25=reg25/2;
    reg70=reg66+reg70; reg53=reg42+reg53; reg69=reg61+reg69; reg51=0.16666666666666666667*reg51; reg38=reg38/3;
    reg14=reg35+reg14; reg40=reg46+reg40; reg70=0.16666666666666666667*reg70; reg64=reg64/3; reg69=0.16666666666666666667*reg69;
    reg15=reg57+reg15; reg46=reg37+reg46; reg8=reg27+reg8; reg25=reg21+reg25; reg62=reg62/3;
    reg53=reg53+reg28; reg59=reg28+reg59; reg24=reg26+reg24; reg0=reg0/3; reg47=reg49+reg47;
    reg52=0.16666666666666666667*reg52; reg43=reg29+reg43; reg30=reg2+reg30; reg29=reg58+reg29; reg47=0.041666666666666666668*reg47;
    reg43=reg29+reg43; reg38=reg14+reg38; reg51=reg51/4; reg15=0.041666666666666666668*reg15; reg69=reg69/4;
    reg64=reg8+reg64; reg62=reg25+reg62; reg39=0.041666666666666666668*reg39; reg59=reg53+reg59; reg0=reg24+reg0;
    reg52=reg52/4; reg70=reg70/4; reg40=reg46+reg40; reg30=0.041666666666666666668*reg30; reg69=reg64+reg69;
    reg40=0.0083333333333333333337*reg40; reg15=reg15/5; reg2=0.0083333333333333333337*reg36; reg51=reg38+reg51; reg47=reg47/5;
    reg52=reg0+reg52; reg59=0.0083333333333333333337*reg59; reg43=0.0083333333333333333337*reg43; reg70=reg62+reg70; reg30=reg30/5;
    reg39=reg39/5; reg40=reg40/6; reg15=reg69+reg15; reg39=reg51+reg39; reg2=reg2/6;
    reg43=reg43/6; reg30=reg70+reg30; reg47=reg52+reg47; reg59=reg59/6; reg2=reg39-reg2;
    reg43=reg30+reg43; reg59=reg47+reg59; reg40=reg15+reg40; res[1]=reg59/reg2; res[0]=reg43/reg2;
    res[2]=reg40/reg2;

    return res;
}
}
#endif // LMT_BAR_4
