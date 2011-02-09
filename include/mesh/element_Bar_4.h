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
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=reg1-var_inter[0]; T reg3=reg0+reg1; T reg4=1-var_inter[0];
    T reg5=var_inter[0]*reg1; T reg6=reg0-var_inter[0]; T reg7=reg0*reg1; T reg8=reg3*reg4; reg2=reg2*reg4;
    T reg9=reg4*reg5; reg0=reg0*var_inter[0]; T reg10=reg6*reg4; reg5=reg2-reg5; reg2=reg4*reg7;
    reg7=reg8+reg7; reg2=4.5*reg2; reg4=reg0*reg4; reg9=13.5*reg9; reg6=reg6*reg1;
    reg5=13.5*reg5; reg8=4.5*reg7; reg10=reg10-reg0; reg1=reg0*reg1; reg4=13.5*reg4;
    reg0=reg6-reg0; reg6=pos_nodes[0][0]*reg2; T reg11=pos_nodes[2][0]*reg9; reg10=13.5*reg10; T reg12=pos_nodes[0][0]*reg8;
    T reg13=pos_nodes[2][0]*reg5; reg1=4.5*reg1; reg0=4.5*reg0; reg12=reg13-reg12; reg13=pos_nodes[3][0]*reg4;
    reg11=reg6+reg11; reg6=reg10*pos_nodes[3][0]; reg13=reg11-reg13; reg11=pos_nodes[1][0]*reg1; reg6=reg12-reg6;
    reg12=pos_nodes[1][0]*reg0; reg13=reg11+reg13; reg6=reg12+reg6; reg13=pos[0]-reg13; reg11=1.0/reg6;
    reg11=reg13*reg11; var_inter[0]=reg11;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Bar_4 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=1-var_inter[0]; T reg3=reg1-var_inter[0]; T reg4=reg1+reg0;
    T reg5=reg1*var_inter[0]; T reg6=reg1*reg0; reg3=reg3*reg2; T reg7=reg4*reg2; T reg8=reg0-var_inter[0];
    T reg9=reg6*reg2; T reg10=reg5*reg2; reg0=reg0*var_inter[0]; T reg11=reg8*reg2; reg5=reg3-reg5;
    reg6=reg7+reg6; reg11=reg11-reg0; reg9=4.5*reg9; reg3=4.5*reg6; reg5=13.5*reg5;
    reg2=reg0*reg2; reg8=reg8*reg1; reg10=13.5*reg10; reg8=reg8-reg0; reg2=13.5*reg2;
    reg1=reg0*reg1; reg11=13.5*reg11; reg0=pos_nodes[2][0]*reg10; reg7=pos_nodes[0][0]*reg9; T reg12=pos_nodes[2][0]*reg5;
    T reg13=pos_nodes[0][0]*reg3; reg1=4.5*reg1; T reg14=reg2*pos_nodes[3][0]; reg8=4.5*reg8; reg0=reg7+reg0;
    reg7=reg11*pos_nodes[3][0]; reg13=reg12-reg13; reg12=pos_nodes[1][0]*reg8; reg7=reg13-reg7; reg13=pos_nodes[1][0]*reg1;
    reg14=reg0-reg14; reg14=reg13+reg14; reg7=reg12+reg7; reg0=1.0/reg7; reg14=pos[0]-reg14;
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
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=reg1*reg0; T reg3=1-var_inter[0]; T reg4=var_inter[0]*reg1;
    reg2=reg3*reg2; reg4=reg3*reg4; reg0=var_inter[0]*reg0; reg2=4.5*reg2; reg4=13.5*reg4;
    reg3=reg3*reg0; reg4=val[2]*reg4; reg2=val[0]*reg2; reg3=13.5*reg3; reg0=reg1*reg0;
    reg1=val[3]*reg3; reg4=reg2+reg4; reg0=4.5*reg0; reg0=val[1]*reg0; reg1=reg4-reg1;
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
    T reg0=0.66666666666666662966-var_inter[0]; T reg1=0.33333333333333331483-var_inter[0]; T reg2=1-var_inter[0]; T reg3=reg0+reg1; T reg4=reg0-var_inter[0];
    reg4=reg2*reg4; T reg5=var_inter[0]*reg0; T reg6=reg0*reg1; T reg7=reg2*reg3; T reg8=reg1-var_inter[0];
    reg1=var_inter[0]*reg1; T reg9=reg2*reg8; reg4=reg4-reg5; reg7=reg6+reg7; reg8=reg0*reg8;
    reg4=13.5*reg4; reg9=reg9-reg1; T reg10=4.5*reg7; T reg11=elem.pos(0)[1]*reg10; T reg12=elem.pos(2)[1]*reg4;
    reg9=13.5*reg9; T reg13=elem.pos(0)[0]*reg10; T reg14=elem.pos(2)[0]*reg4; reg8=reg8-reg1; T reg15=elem.pos(3)[1]*reg9;
    T reg16=elem.pos(3)[0]*reg9; reg8=4.5*reg8; reg14=reg14-reg13; reg4=elem.pos(2)[2]*reg4; reg12=reg12-reg11;
    T reg17=elem.pos(0)[2]*reg10; T reg18=elem.pos(1)[0]*reg8; reg4=reg4-reg17; T reg19=elem.pos(1)[1]*reg8; reg9=elem.pos(3)[2]*reg9;
    reg15=reg12-reg15; reg16=reg14-reg16; reg16=reg18+reg16; reg8=elem.pos(1)[2]*reg8; reg15=reg19+reg15;
    reg9=reg4-reg9; reg4=pow(reg15,2); reg8=reg9+reg8; reg9=pow(reg16,2); reg4=reg9+reg4;
    reg9=pow(reg8,2); reg4=reg9+reg4; reg4=pow(reg4,0.5); reg9=reg15/reg4; reg12=reg16/reg4;
    reg4=reg8/reg4; reg9=reg15*reg9; reg16=reg12*reg16; reg8=reg4*reg8; reg16=reg9+reg16;
    reg16=reg8+reg16; return reg16;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,1> barycenter( const Element<Bar_4,TN,Node<1,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,1> res;
    T reg0=0.6040626850758430438*elem.pos(0)[0]; T reg1=0.023200603736802050376*elem.pos(0)[0]; T reg2=2.2615982821468569761*elem.pos(2)[0]; T reg3=0.15072953754849390466*elem.pos(2)[0]; T reg4=0.46972365229854333709*elem.pos(0)[0];
    T reg5=3.3353846195212432377*elem.pos(2)[0]; T reg6=0.91021395698862253836*elem.pos(2)[0]; T reg7=0.037742890800314621403*elem.pos(0)[0]; T reg8=0.15072953754849408133*elem.pos(3)[0]; T reg9=3.3353846195212434166*elem.pos(3)[0];
    T reg10=0.13717836651415197166*elem.pos(0)[0]; reg0=reg2+reg0; reg6=reg6-reg7; T reg11=0.062142259086802441412*elem.pos(0)[0]; T reg12=0.31139327261482343745*elem.pos(2)[0];
    T reg13=reg4-reg5; T reg14=2.2615982821468567972*elem.pos(3)[0]; reg3=reg3-reg1; T reg15=0.91021395698862271498*elem.pos(3)[0]; T reg16=0.43609286044426324715*elem.pos(2)[0];
    T reg17=reg10-reg16; T reg18=2.5393493786539290877*elem.pos(3)[0]; T reg19=0.94454568826984199422*elem.pos(3)[0]; reg11=reg11-reg12; T reg20=2.5393493786539285922*elem.pos(2)[0];
    T reg21=0.60406268507584341281*elem.pos(1)[0]; reg13=reg13+reg14; T reg22=0.30470532525817892595*elem.pos(0)[0]; T reg23=0.037742890800314584493*elem.pos(1)[0]; reg3=reg3+reg15;
    T reg24=0.94454568826984188878*elem.pos(2)[0]; T reg25=0.46972365229854320652*elem.pos(1)[0]; T reg26=reg9-reg0; T reg27=0.023200603736802073067*elem.pos(1)[0]; reg6=reg6+reg8;
    T reg28=2.8382638725840401981*elem.pos(0)[0]; T reg29=0.71150405089204334872*elem.pos(0)[0]; reg28=reg20-reg28; reg20=0.43609286044426374252*elem.pos(3)[0]; T reg30=3.3306249665903141463*elem.pos(2)[0];
    reg22=reg24+reg22; reg24=0.31139327261482333201*elem.pos(3)[0]; T reg31=0.028808060190825802817*elem.pos(0)[0]; reg13=reg21+reg13; reg3=reg3-reg23;
    reg21=0.13194163259416033594*elem.pos(2)[0]; reg26=reg26-reg25; reg6=reg6-reg27; T reg32=2.8382638725840407781*elem.pos(1)[0]; reg18=reg17-reg18;
    reg17=0.3047053252581790631*elem.pos(1)[0]; reg11=reg11+reg19; T reg33=7.5267377805044972149*elem.pos(2)[0]; T reg34=0.27875481331111525221*elem.pos(3)[0]; reg31=reg31-reg21;
    T reg35=7.5267377805044979131*elem.pos(3)[0]; reg29=reg30-reg29; reg3=reg13*reg3; reg6=reg26*reg6; reg30=0.82437875909221917811*elem.pos(0)[0];
    reg18=reg32+reg18; reg11=reg17+reg11; reg17=0.27875481331111522752*elem.pos(2)[0]; reg32=0.13717836651415205219*elem.pos(1)[0]; reg28=reg28+reg20;
    T reg36=0.06214225908680241343*elem.pos(1)[0]; reg24=reg22-reg24; reg22=4.9076168648062268828*elem.pos(0)[0]; T reg37=3.3306249665903134478*elem.pos(3)[0]; reg31=reg31+reg34;
    reg30=reg17+reg30; reg22=reg33-reg22; reg17=0.13194163259416031138*elem.pos(3)[0]; reg26=0.2339569672863455*reg26; reg33=0.82437875909221940309*elem.pos(1)[0];
    reg13=0.2339569672863455*reg13; reg3=0.2339569672863455*reg3; reg35=reg29-reg35; reg29=4.9076168648062275983*elem.pos(1)[0]; reg6=0.2339569672863455*reg6;
    reg11=reg18*reg11; reg24=reg36+reg24; reg28=reg28-reg32; reg18=0.1803807865240695*reg18; reg26=reg13+reg26;
    reg17=reg30-reg17; reg6=reg3+reg6; reg11=0.1803807865240695*reg11; reg3=0.028808060190825794929*elem.pos(1)[0]; reg37=reg22-reg37;
    reg24=reg28*reg24; reg31=reg33+reg31; reg13=0.71150405089204313291*elem.pos(1)[0]; reg35=reg29+reg35; reg28=0.1803807865240695*reg28;
    reg18=reg26+reg18; reg31=reg35*reg31; reg17=reg3+reg17; reg24=0.1803807865240695*reg24; reg37=reg13+reg37;
    reg11=reg6+reg11; reg17=reg37*reg17; reg35=0.085662246189584999998*reg35; reg31=0.085662246189584999998*reg31; reg24=reg11+reg24;
    reg28=reg18+reg28; reg37=0.085662246189584999998*reg37; reg35=reg28+reg35; reg17=0.085662246189584999998*reg17; reg31=reg24+reg31;
    reg17=reg31+reg17; reg37=reg35+reg37; res[0]=reg17/reg37;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Bar_4,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.46972365229854333709*elem.pos(0)[1]; T reg1=3.3353846195212432377*elem.pos(2)[1]; T reg2=0.6040626850758430438*elem.pos(0)[1]; T reg3=3.3353846195212432377*elem.pos(2)[0]; T reg4=2.2615982821468569761*elem.pos(2)[0];
    T reg5=0.46972365229854333709*elem.pos(0)[0]; T reg6=0.6040626850758430438*elem.pos(0)[0]; T reg7=2.2615982821468569761*elem.pos(2)[1]; T reg8=0.43609286044426324715*elem.pos(2)[0]; reg6=reg4+reg6;
    T reg9=3.3353846195212434166*elem.pos(3)[1]; T reg10=3.3353846195212434166*elem.pos(3)[0]; T reg11=0.13717836651415197166*elem.pos(0)[0]; reg2=reg7+reg2; T reg12=2.2615982821468567972*elem.pos(3)[1];
    T reg13=reg0-reg1; T reg14=0.43609286044426324715*elem.pos(2)[1]; T reg15=0.13717836651415197166*elem.pos(0)[1]; T reg16=reg5-reg3; T reg17=2.2615982821468567972*elem.pos(3)[0];
    T reg18=0.46972365229854320652*elem.pos(1)[0]; T reg19=reg10-reg6; reg13=reg13+reg12; T reg20=0.60406268507584341281*elem.pos(1)[1]; reg16=reg16+reg17;
    T reg21=0.60406268507584341281*elem.pos(1)[0]; T reg22=2.5393493786539290877*elem.pos(3)[0]; T reg23=reg11-reg8; T reg24=2.5393493786539285922*elem.pos(2)[1]; T reg25=2.8382638725840401981*elem.pos(0)[1];
    T reg26=reg15-reg14; T reg27=2.5393493786539290877*elem.pos(3)[1]; T reg28=2.8382638725840401981*elem.pos(0)[0]; T reg29=reg9-reg2; T reg30=0.46972365229854320652*elem.pos(1)[1];
    T reg31=2.5393493786539285922*elem.pos(2)[0]; reg27=reg26-reg27; reg28=reg31-reg28; reg21=reg16+reg21; reg16=2.8382638725840407781*elem.pos(1)[1];
    reg26=2.8382638725840407781*elem.pos(1)[0]; reg22=reg23-reg22; reg13=reg20+reg13; reg20=0.43609286044426374252*elem.pos(3)[0]; reg25=reg24-reg25;
    reg23=0.71150405089204334872*elem.pos(0)[0]; reg24=3.3306249665903141463*elem.pos(2)[0]; reg31=0.43609286044426374252*elem.pos(3)[1]; reg29=reg29-reg30; reg19=reg19-reg18;
    T reg32=0.71150405089204334872*elem.pos(0)[1]; T reg33=3.3306249665903141463*elem.pos(2)[1]; T reg34=4.9076168648062268828*elem.pos(0)[1]; T reg35=pow(reg29,2); T reg36=pow(reg19,2);
    reg25=reg25+reg31; T reg37=7.5267377805044972149*elem.pos(2)[1]; T reg38=7.5267377805044972149*elem.pos(2)[0]; T reg39=0.13717836651415205219*elem.pos(1)[1]; T reg40=0.13717836651415205219*elem.pos(1)[0];
    reg28=reg28+reg20; T reg41=4.9076168648062268828*elem.pos(0)[0]; T reg42=pow(reg21,2); reg32=reg33-reg32; reg23=reg24-reg23;
    reg24=7.5267377805044979131*elem.pos(3)[0]; reg33=7.5267377805044979131*elem.pos(3)[1]; reg26=reg22+reg26; reg27=reg16+reg27; reg16=pow(reg13,2);
    reg22=pow(reg27,2); reg35=reg36+reg35; reg25=reg25-reg39; reg36=3.3306249665903134478*elem.pos(3)[0]; T reg43=pow(reg26,2);
    reg41=reg38-reg41; reg28=reg28-reg40; reg24=reg23-reg24; reg23=4.9076168648062275983*elem.pos(1)[0]; reg16=reg42+reg16;
    reg33=reg32-reg33; reg32=4.9076168648062275983*elem.pos(1)[1]; reg38=3.3306249665903134478*elem.pos(3)[1]; reg34=reg37-reg34; reg37=0.023200603736802050376*elem.pos(0)[0];
    reg42=0.15072953754849390466*elem.pos(2)[0]; reg36=reg41-reg36; reg22=reg43+reg22; reg41=0.71150405089204313291*elem.pos(1)[0]; reg16=pow(reg16,0.5);
    reg23=reg24+reg23; reg33=reg32+reg33; reg24=0.91021395698862253836*elem.pos(2)[0]; reg32=0.037742890800314621403*elem.pos(0)[0]; reg38=reg34-reg38;
    reg35=pow(reg35,0.5); reg34=pow(reg25,2); reg43=0.023200603736802050376*elem.pos(0)[1]; T reg44=0.15072953754849390466*elem.pos(2)[1]; T reg45=0.71150405089204313291*elem.pos(1)[1];
    T reg46=0.91021395698862253836*elem.pos(2)[1]; T reg47=pow(reg28,2); T reg48=0.037742890800314621403*elem.pos(0)[1]; reg46=reg46-reg48; reg44=reg44-reg43;
    T reg49=pow(reg23,2); T reg50=0.91021395698862271498*elem.pos(3)[1]; T reg51=pow(reg33,2); reg34=reg47+reg34; reg47=0.15072953754849408133*elem.pos(3)[1];
    reg38=reg45+reg38; reg41=reg36+reg41; reg36=0.062142259086802441412*elem.pos(0)[1]; reg45=0.31139327261482343745*elem.pos(2)[1]; T reg52=reg29/reg35;
    reg35=reg19/reg35; T reg53=0.31139327261482343745*elem.pos(2)[0]; T reg54=0.062142259086802441412*elem.pos(0)[0]; T reg55=0.15072953754849408133*elem.pos(3)[0]; reg22=pow(reg22,0.5);
    reg24=reg24-reg32; reg42=reg42-reg37; T reg56=reg21/reg16; reg16=reg13/reg16; T reg57=0.91021395698862271498*elem.pos(3)[0];
    reg56=reg21*reg56; reg44=reg44+reg50; reg51=reg49+reg51; reg21=0.023200603736802073067*elem.pos(1)[1]; reg16=reg13*reg16;
    reg42=reg42+reg57; reg24=reg24+reg55; reg13=0.023200603736802073067*elem.pos(1)[0]; reg49=0.037742890800314584493*elem.pos(1)[0]; reg46=reg46+reg47;
    T reg58=0.037742890800314584493*elem.pos(1)[1]; reg34=pow(reg34,0.5); T reg59=0.94454568826984199422*elem.pos(3)[1]; reg36=reg36-reg45; T reg60=0.94454568826984188878*elem.pos(2)[0];
    T reg61=0.30470532525817892595*elem.pos(0)[0]; T reg62=reg27/reg22; T reg63=pow(reg41,2); reg22=reg26/reg22; T reg64=0.94454568826984199422*elem.pos(3)[0];
    reg54=reg54-reg53; T reg65=0.30470532525817892595*elem.pos(0)[1]; T reg66=0.94454568826984188878*elem.pos(2)[1]; T reg67=pow(reg38,2); reg52=reg29*reg52;
    reg35=reg19*reg35; reg51=pow(reg51,0.5); reg19=0.028808060190825802817*elem.pos(0)[1]; reg29=0.13194163259416033594*elem.pos(2)[1]; reg67=reg63+reg67;
    reg63=0.3047053252581790631*elem.pos(1)[1]; T reg68=0.31139327261482333201*elem.pos(3)[0]; reg22=reg26*reg22; reg61=reg60+reg61; reg26=0.3047053252581790631*elem.pos(1)[0];
    reg62=reg27*reg62; reg54=reg54+reg64; reg36=reg36+reg59; reg52=reg35+reg52; reg27=reg28/reg34;
    reg46=reg46-reg21; reg34=reg25/reg34; reg24=reg24-reg13; reg35=0.13194163259416033594*elem.pos(2)[0]; reg60=0.028808060190825802817*elem.pos(0)[0];
    reg44=reg44-reg58; reg66=reg65+reg66; reg65=0.31139327261482333201*elem.pos(3)[1]; reg16=reg56+reg16; reg42=reg42-reg49;
    reg56=0.27875481331111525221*elem.pos(3)[1]; T reg69=0.82437875909221917811*elem.pos(0)[1]; T reg70=0.27875481331111522752*elem.pos(2)[1]; reg46=reg52*reg46; reg36=reg63+reg36;
    reg19=reg19-reg29; reg63=0.06214225908680241343*elem.pos(1)[1]; reg67=pow(reg67,0.5); reg44=reg16*reg44; reg65=reg66-reg65;
    reg66=reg33/reg51; reg51=reg23/reg51; T reg71=0.27875481331111525221*elem.pos(3)[0]; reg60=reg60-reg35; reg34=reg25*reg34;
    reg27=reg28*reg27; reg25=0.06214225908680241343*elem.pos(1)[0]; reg24=reg24*reg52; reg26=reg54+reg26; reg28=0.82437875909221917811*elem.pos(0)[0];
    reg54=0.27875481331111522752*elem.pos(2)[0]; reg62=reg22+reg62; reg42=reg42*reg16; reg68=reg61-reg68; reg26=reg26*reg62;
    reg25=reg68+reg25; reg34=reg27+reg34; reg16=0.2339569672863455*reg16; reg65=reg63+reg65; reg46=0.2339569672863455*reg46;
    reg44=0.2339569672863455*reg44; reg60=reg60+reg71; reg22=0.82437875909221940309*elem.pos(1)[0]; reg36=reg62*reg36; reg42=0.2339569672863455*reg42;
    reg24=0.2339569672863455*reg24; reg51=reg23*reg51; reg66=reg33*reg66; reg23=reg41/reg67; reg67=reg38/reg67;
    reg27=0.82437875909221940309*elem.pos(1)[1]; reg19=reg19+reg56; reg33=0.13194163259416031138*elem.pos(3)[0]; reg28=reg54+reg28; reg70=reg69+reg70;
    reg52=0.2339569672863455*reg52; reg54=0.13194163259416031138*elem.pos(3)[1]; reg66=reg51+reg66; reg26=0.1803807865240695*reg26; reg54=reg70-reg54;
    reg36=0.1803807865240695*reg36; reg33=reg28-reg33; reg24=reg42+reg24; reg28=0.028808060190825794929*elem.pos(1)[0]; reg46=reg44+reg46;
    reg23=reg41*reg23; reg67=reg38*reg67; reg38=0.028808060190825794929*elem.pos(1)[1]; reg25=reg25*reg34; reg52=reg16+reg52;
    reg62=0.1803807865240695*reg62; reg19=reg27+reg19; reg22=reg60+reg22; reg65=reg34*reg65; reg19=reg66*reg19;
    reg65=0.1803807865240695*reg65; reg54=reg38+reg54; reg28=reg33+reg28; reg22=reg22*reg66; reg67=reg23+reg67;
    reg62=reg52+reg62; reg34=0.1803807865240695*reg34; reg26=reg24+reg26; reg25=0.1803807865240695*reg25; reg36=reg46+reg36;
    reg65=reg36+reg65; reg22=0.085662246189584999998*reg22; reg66=0.085662246189584999998*reg66; reg34=reg62+reg34; reg54=reg67*reg54;
    reg25=reg26+reg25; reg19=0.085662246189584999998*reg19; reg28=reg28*reg67; reg22=reg25+reg22; reg28=0.085662246189584999998*reg28;
    reg19=reg65+reg19; reg66=reg34+reg66; reg67=0.085662246189584999998*reg67; reg54=0.085662246189584999998*reg54; reg54=reg19+reg54;
    reg28=reg22+reg28; reg67=reg66+reg67; res[1]=reg54/reg67; res[0]=reg28/reg67;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Bar_4,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.46972365229854333709*elem.pos(0)[0]; T reg1=0.46972365229854333709*elem.pos(0)[1]; T reg2=3.3353846195212432377*elem.pos(2)[1]; T reg3=0.6040626850758430438*elem.pos(0)[0]; T reg4=0.6040626850758430438*elem.pos(0)[1];
    T reg5=2.2615982821468569761*elem.pos(2)[1]; T reg6=2.2615982821468569761*elem.pos(2)[0]; T reg7=3.3353846195212432377*elem.pos(2)[0]; T reg8=0.13717836651415197166*elem.pos(0)[0]; T reg9=0.43609286044426324715*elem.pos(2)[1];
    T reg10=0.13717836651415197166*elem.pos(0)[1]; reg4=reg5+reg4; T reg11=0.43609286044426324715*elem.pos(2)[0]; T reg12=reg0-reg7; T reg13=3.3353846195212434166*elem.pos(3)[1];
    T reg14=2.2615982821468567972*elem.pos(3)[0]; T reg15=3.3353846195212434166*elem.pos(3)[0]; reg3=reg6+reg3; T reg16=reg1-reg2; T reg17=2.2615982821468567972*elem.pos(3)[1];
    T reg18=3.3353846195212432377*elem.pos(2)[2]; T reg19=0.46972365229854333709*elem.pos(0)[2]; T reg20=2.2615982821468569761*elem.pos(2)[2]; T reg21=0.6040626850758430438*elem.pos(0)[2]; T reg22=0.46972365229854320652*elem.pos(1)[1];
    T reg23=reg13-reg4; T reg24=0.46972365229854320652*elem.pos(1)[0]; T reg25=reg15-reg3; reg12=reg12+reg14; T reg26=0.60406268507584341281*elem.pos(1)[0];
    reg16=reg16+reg17; T reg27=0.60406268507584341281*elem.pos(1)[1]; T reg28=reg19-reg18; T reg29=2.2615982821468567972*elem.pos(3)[2]; T reg30=0.13717836651415197166*elem.pos(0)[2];
    T reg31=0.43609286044426324715*elem.pos(2)[2]; T reg32=2.5393493786539290877*elem.pos(3)[1]; T reg33=reg10-reg9; T reg34=2.8382638725840401981*elem.pos(0)[1]; T reg35=2.5393493786539285922*elem.pos(2)[1];
    T reg36=2.5393493786539290877*elem.pos(3)[0]; T reg37=reg8-reg11; T reg38=2.8382638725840401981*elem.pos(0)[0]; T reg39=2.5393493786539285922*elem.pos(2)[0]; T reg40=3.3353846195212434166*elem.pos(3)[2];
    reg21=reg20+reg21; T reg41=3.3306249665903141463*elem.pos(2)[1]; T reg42=0.71150405089204334872*elem.pos(0)[1]; T reg43=0.43609286044426374252*elem.pos(3)[0]; reg38=reg39-reg38;
    reg34=reg35-reg34; reg35=0.43609286044426374252*elem.pos(3)[1]; reg39=0.60406268507584341281*elem.pos(1)[2]; T reg44=2.5393493786539290877*elem.pos(3)[2]; T reg45=reg30-reg31;
    T reg46=2.8382638725840407781*elem.pos(1)[1]; reg32=reg33-reg32; reg33=2.8382638725840407781*elem.pos(1)[0]; reg36=reg37-reg36; reg25=reg25-reg24;
    reg37=2.5393493786539285922*elem.pos(2)[2]; T reg47=2.8382638725840401981*elem.pos(0)[2]; T reg48=3.3306249665903141463*elem.pos(2)[0]; T reg49=0.71150405089204334872*elem.pos(0)[0]; T reg50=0.46972365229854320652*elem.pos(1)[2];
    T reg51=reg40-reg21; reg23=reg23-reg22; reg26=reg12+reg26; reg27=reg16+reg27; reg28=reg28+reg29;
    reg12=7.5267377805044972149*elem.pos(2)[0]; reg16=4.9076168648062268828*elem.pos(0)[0]; T reg52=pow(reg25,2); T reg53=2.8382638725840407781*elem.pos(1)[2]; T reg54=7.5267377805044972149*elem.pos(2)[1];
    T reg55=4.9076168648062268828*elem.pos(0)[1]; T reg56=pow(reg23,2); reg44=reg45-reg44; reg51=reg51-reg50; reg46=reg32+reg46;
    reg39=reg28+reg39; reg28=7.5267377805044979131*elem.pos(3)[0]; reg49=reg48-reg49; reg33=reg36+reg33; reg32=0.43609286044426374252*elem.pos(3)[2];
    reg47=reg37-reg47; reg36=0.13717836651415205219*elem.pos(1)[1]; reg37=pow(reg26,2); reg34=reg34+reg35; reg45=0.71150405089204334872*elem.pos(0)[2];
    reg48=0.13717836651415205219*elem.pos(1)[0]; T reg57=7.5267377805044979131*elem.pos(3)[1]; T reg58=pow(reg27,2); reg42=reg41-reg42; reg41=3.3306249665903141463*elem.pos(2)[2];
    reg38=reg38+reg43; T reg59=4.9076168648062275983*elem.pos(1)[1]; reg38=reg38-reg48; T reg60=4.9076168648062275983*elem.pos(1)[0]; reg28=reg49-reg28;
    reg49=pow(reg33,2); T reg61=4.9076168648062268828*elem.pos(0)[2]; T reg62=0.13717836651415205219*elem.pos(1)[2]; reg47=reg47+reg32; reg45=reg41-reg45;
    reg41=7.5267377805044972149*elem.pos(2)[2]; T reg63=7.5267377805044979131*elem.pos(3)[2]; T reg64=pow(reg39,2); reg16=reg12-reg16; reg12=3.3306249665903134478*elem.pos(3)[0];
    reg34=reg34-reg36; reg53=reg44+reg53; reg58=reg37+reg58; reg56=reg52+reg56; reg55=reg54-reg55;
    reg37=3.3306249665903134478*elem.pos(3)[1]; reg57=reg42-reg57; reg42=pow(reg51,2); reg44=pow(reg46,2); reg52=3.3306249665903134478*elem.pos(3)[2];
    reg61=reg41-reg61; reg44=reg49+reg44; reg41=pow(reg38,2); reg49=pow(reg53,2); reg63=reg45-reg63;
    reg59=reg57+reg59; reg45=4.9076168648062275983*elem.pos(1)[2]; reg12=reg16-reg12; reg16=0.71150405089204313291*elem.pos(1)[0]; reg64=reg58+reg64;
    reg42=reg56+reg42; reg60=reg28+reg60; reg28=pow(reg34,2); reg47=reg47-reg62; reg37=reg55-reg37;
    reg54=0.71150405089204313291*elem.pos(1)[1]; reg55=pow(reg59,2); reg28=reg41+reg28; reg41=pow(reg60,2); reg45=reg63+reg45;
    reg54=reg37+reg54; reg49=reg44+reg49; reg16=reg12+reg16; reg64=pow(reg64,0.5); reg52=reg61-reg52;
    reg12=pow(reg47,2); reg42=pow(reg42,0.5); reg37=0.71150405089204313291*elem.pos(1)[2]; reg44=0.037742890800314621403*elem.pos(0)[2]; reg56=0.91021395698862253836*elem.pos(2)[2];
    reg57=0.023200603736802050376*elem.pos(0)[2]; reg55=reg41+reg55; reg37=reg52+reg37; reg41=0.15072953754849390466*elem.pos(2)[1]; reg52=pow(reg54,2);
    reg58=0.15072953754849390466*elem.pos(2)[2]; reg61=0.023200603736802050376*elem.pos(0)[1]; reg63=pow(reg45,2); reg12=reg28+reg12; reg28=0.91021395698862253836*elem.pos(2)[1];
    T reg65=pow(reg16,2); T reg66=0.037742890800314621403*elem.pos(0)[1]; reg49=pow(reg49,0.5); T reg67=reg23/reg42; T reg68=reg25/reg42;
    T reg69=reg26/reg64; T reg70=reg27/reg64; T reg71=0.91021395698862253836*elem.pos(2)[0]; T reg72=0.037742890800314621403*elem.pos(0)[0]; T reg73=0.023200603736802050376*elem.pos(0)[0];
    T reg74=0.15072953754849390466*elem.pos(2)[0]; T reg75=0.062142259086802441412*elem.pos(0)[1]; T reg76=0.31139327261482343745*elem.pos(2)[2]; T reg77=0.31139327261482343745*elem.pos(2)[1]; T reg78=0.91021395698862271498*elem.pos(3)[0];
    T reg79=0.062142259086802441412*elem.pos(0)[2]; reg74=reg74-reg73; reg28=reg28-reg66; reg63=reg55+reg63; reg42=reg51/reg42;
    reg52=reg65+reg52; reg67=reg23*reg67; reg68=reg25*reg68; reg69=reg26*reg69; reg23=0.15072953754849408133*elem.pos(3)[0];
    reg71=reg71-reg72; reg70=reg27*reg70; reg25=0.15072953754849408133*elem.pos(3)[1]; reg64=reg39/reg64; reg26=0.91021395698862271498*elem.pos(3)[2];
    reg58=reg58-reg57; reg56=reg56-reg44; reg27=0.15072953754849408133*elem.pos(3)[2]; reg55=pow(reg37,2); reg65=reg46/reg49;
    T reg80=reg33/reg49; reg12=pow(reg12,0.5); T reg81=0.91021395698862271498*elem.pos(3)[1]; T reg82=0.31139327261482343745*elem.pos(2)[0]; T reg83=0.062142259086802441412*elem.pos(0)[0];
    reg41=reg41-reg61; reg58=reg58+reg26; reg70=reg69+reg70; reg69=0.037742890800314584493*elem.pos(1)[2]; reg41=reg41+reg81;
    reg74=reg74+reg78; T reg84=0.037742890800314584493*elem.pos(1)[0]; reg56=reg56+reg27; T reg85=0.023200603736802073067*elem.pos(1)[2]; reg55=reg52+reg55;
    reg79=reg79-reg76; reg52=0.94454568826984199422*elem.pos(3)[2]; T reg86=0.037742890800314584493*elem.pos(1)[1]; reg63=pow(reg63,0.5); T reg87=0.30470532525817892595*elem.pos(0)[2];
    T reg88=0.94454568826984188878*elem.pos(2)[2]; reg80=reg33*reg80; reg65=reg46*reg65; reg49=reg53/reg49; reg33=0.94454568826984199422*elem.pos(3)[0];
    reg75=reg75-reg77; reg83=reg83-reg82; reg46=reg34/reg12; T reg89=0.94454568826984188878*elem.pos(2)[1]; T reg90=0.30470532525817892595*elem.pos(0)[1];
    T reg91=0.30470532525817892595*elem.pos(0)[0]; T reg92=0.94454568826984188878*elem.pos(2)[0]; T reg93=0.023200603736802073067*elem.pos(1)[1]; T reg94=reg38/reg12; reg28=reg28+reg25;
    reg42=reg51*reg42; reg67=reg68+reg67; reg51=0.023200603736802073067*elem.pos(1)[0]; reg71=reg71+reg23; reg68=0.94454568826984199422*elem.pos(3)[1];
    reg64=reg39*reg64; reg39=0.3047053252581790631*elem.pos(1)[1]; reg83=reg83+reg33; T reg95=0.3047053252581790631*elem.pos(1)[0]; reg65=reg80+reg65;
    reg49=reg53*reg49; reg53=0.13194163259416033594*elem.pos(2)[1]; reg55=pow(reg55,0.5); reg56=reg56-reg85; reg92=reg91+reg92;
    reg90=reg89+reg90; reg80=0.31139327261482333201*elem.pos(3)[1]; reg58=reg58-reg69; reg89=0.31139327261482333201*elem.pos(3)[0]; reg64=reg70+reg64;
    reg70=0.31139327261482333201*elem.pos(3)[2]; reg71=reg71-reg51; reg91=reg60/reg63; T reg96=reg59/reg63; reg28=reg28-reg93;
    reg87=reg88+reg87; reg88=0.13194163259416033594*elem.pos(2)[0]; T reg97=0.3047053252581790631*elem.pos(1)[2]; reg41=reg41-reg86; T reg98=0.028808060190825802817*elem.pos(0)[0];
    reg75=reg75+reg68; reg42=reg67+reg42; reg94=reg38*reg94; reg46=reg34*reg46; reg74=reg74-reg84;
    reg12=reg47/reg12; reg34=0.028808060190825802817*elem.pos(0)[1]; reg38=0.028808060190825802817*elem.pos(0)[2]; reg67=0.13194163259416033594*elem.pos(2)[2]; reg79=reg79+reg52;
    T reg99=0.27875481331111522752*elem.pos(2)[1]; reg34=reg34-reg53; reg28=reg42*reg28; T reg100=0.06214225908680241343*elem.pos(1)[1]; T reg101=0.27875481331111525221*elem.pos(3)[1];
    T reg102=0.82437875909221917811*elem.pos(0)[1]; reg41=reg64*reg41; reg39=reg75+reg39; reg80=reg90-reg80; reg96=reg59*reg96;
    reg91=reg60*reg91; reg74=reg74*reg64; reg70=reg87-reg70; reg59=0.06214225908680241343*elem.pos(1)[2]; reg60=0.27875481331111525221*elem.pos(3)[0];
    reg98=reg98-reg88; reg38=reg38-reg67; reg75=0.27875481331111525221*elem.pos(3)[2]; reg12=reg47*reg12; reg46=reg94+reg46;
    reg71=reg71*reg42; reg95=reg83+reg95; reg49=reg65+reg49; reg47=0.27875481331111522752*elem.pos(2)[2]; reg65=0.82437875909221917811*elem.pos(0)[2];
    reg83=0.06214225908680241343*elem.pos(1)[0]; reg89=reg92-reg89; reg58=reg64*reg58; reg87=reg54/reg55; reg90=reg16/reg55;
    reg56=reg42*reg56; reg63=reg45/reg63; reg92=0.27875481331111522752*elem.pos(2)[0]; reg94=0.82437875909221917811*elem.pos(0)[0]; reg97=reg79+reg97;
    reg58=0.2339569672863455*reg58; reg79=0.13194163259416031138*elem.pos(3)[2]; reg65=reg47+reg65; reg97=reg49*reg97; reg47=0.13194163259416031138*elem.pos(3)[1];
    reg100=reg80+reg100; reg102=reg99+reg102; reg80=0.82437875909221940309*elem.pos(1)[2]; reg38=reg38+reg75; reg99=0.82437875909221940309*elem.pos(1)[1];
    reg34=reg34+reg101; reg56=0.2339569672863455*reg56; reg59=reg70+reg59; reg92=reg94+reg92; reg70=0.13194163259416031138*elem.pos(3)[0];
    reg64=0.2339569672863455*reg64; reg90=reg16*reg90; reg87=reg54*reg87; reg55=reg37/reg55; reg63=reg45*reg63;
    reg42=0.2339569672863455*reg42; reg96=reg91+reg96; reg74=0.2339569672863455*reg74; reg16=0.82437875909221940309*elem.pos(1)[0]; reg98=reg98+reg60;
    reg12=reg46+reg12; reg71=0.2339569672863455*reg71; reg41=0.2339569672863455*reg41; reg28=0.2339569672863455*reg28; reg83=reg89+reg83;
    reg39=reg49*reg39; reg95=reg95*reg49; reg56=reg58+reg56; reg100=reg12*reg100; reg45=0.028808060190825794929*elem.pos(1)[2];
    reg79=reg65-reg79; reg87=reg90+reg87; reg28=reg41+reg28; reg55=reg37*reg55; reg97=0.1803807865240695*reg97;
    reg63=reg96+reg63; reg37=0.028808060190825794929*elem.pos(1)[0]; reg70=reg92-reg70; reg39=0.1803807865240695*reg39; reg42=reg64+reg42;
    reg49=0.1803807865240695*reg49; reg80=reg38+reg80; reg16=reg98+reg16; reg99=reg34+reg99; reg95=0.1803807865240695*reg95;
    reg59=reg12*reg59; reg71=reg74+reg71; reg83=reg83*reg12; reg34=0.028808060190825794929*elem.pos(1)[1]; reg47=reg102-reg47;
    reg45=reg79+reg45; reg80=reg63*reg80; reg16=reg16*reg63; reg83=0.1803807865240695*reg83; reg59=0.1803807865240695*reg59;
    reg97=reg56+reg97; reg95=reg71+reg95; reg37=reg70+reg37; reg55=reg87+reg55; reg34=reg47+reg34;
    reg39=reg28+reg39; reg49=reg42+reg49; reg12=0.1803807865240695*reg12; reg100=0.1803807865240695*reg100; reg99=reg63*reg99;
    reg80=0.085662246189584999998*reg80; reg99=0.085662246189584999998*reg99; reg63=0.085662246189584999998*reg63; reg34=reg55*reg34; reg83=reg95+reg83;
    reg59=reg97+reg59; reg100=reg39+reg100; reg12=reg49+reg12; reg45=reg55*reg45; reg37=reg37*reg55;
    reg16=0.085662246189584999998*reg16; reg80=reg59+reg80; reg45=0.085662246189584999998*reg45; reg99=reg100+reg99; reg55=0.085662246189584999998*reg55;
    reg63=reg12+reg63; reg34=0.085662246189584999998*reg34; reg37=0.085662246189584999998*reg37; reg16=reg83+reg16; reg55=reg63+reg55;
    reg34=reg99+reg34; reg37=reg16+reg37; reg45=reg80+reg45; res[0]=reg37/reg55; res[1]=reg34/reg55;
    res[2]=reg45/reg55;

    return res;
}
}
#endif // LMT_BAR_4
