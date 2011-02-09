#ifndef LMT_BAR_4
#define LMT_BAR_4
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
    T reg0=0.6040626850758430438*elem.pos(0)[0]; T reg1=0.91021395698862253836*elem.pos(2)[0]; T reg2=2.2615982821468569761*elem.pos(2)[0]; T reg3=0.037742890800314621403*elem.pos(0)[0]; T reg4=0.023200603736802050376*elem.pos(0)[0];
    T reg5=3.3353846195212432377*elem.pos(2)[0]; T reg6=0.46972365229854333709*elem.pos(0)[0]; T reg7=0.15072953754849390466*elem.pos(2)[0]; reg1=reg1-reg3; T reg8=0.062142259086802441412*elem.pos(0)[0];
    T reg9=0.13717836651415197166*elem.pos(0)[0]; T reg10=0.15072953754849408133*elem.pos(3)[0]; T reg11=3.3353846195212434166*elem.pos(3)[0]; T reg12=0.31139327261482343745*elem.pos(2)[0]; reg0=reg2+reg0;
    reg7=reg7-reg4; T reg13=reg6-reg5; T reg14=0.91021395698862271498*elem.pos(3)[0]; T reg15=2.2615982821468567972*elem.pos(3)[0]; T reg16=0.43609286044426324715*elem.pos(2)[0];
    T reg17=reg9-reg16; T reg18=2.5393493786539290877*elem.pos(3)[0]; T reg19=0.94454568826984199422*elem.pos(3)[0]; reg8=reg8-reg12; T reg20=2.5393493786539285922*elem.pos(2)[0];
    T reg21=0.60406268507584341281*elem.pos(1)[0]; reg13=reg13+reg15; T reg22=0.30470532525817892595*elem.pos(0)[0]; T reg23=0.037742890800314584493*elem.pos(1)[0]; reg7=reg7+reg14;
    T reg24=0.94454568826984188878*elem.pos(2)[0]; T reg25=0.46972365229854320652*elem.pos(1)[0]; T reg26=reg11-reg0; T reg27=0.023200603736802073067*elem.pos(1)[0]; reg1=reg1+reg10;
    T reg28=2.8382638725840401981*elem.pos(0)[0]; T reg29=0.71150405089204334872*elem.pos(0)[0]; reg28=reg20-reg28; reg20=0.43609286044426374252*elem.pos(3)[0]; T reg30=3.3306249665903141463*elem.pos(2)[0];
    reg22=reg24+reg22; reg24=0.31139327261482333201*elem.pos(3)[0]; T reg31=0.028808060190825802817*elem.pos(0)[0]; reg13=reg21+reg13; reg7=reg7-reg23;
    reg21=0.13194163259416033594*elem.pos(2)[0]; reg26=reg26-reg25; reg1=reg1-reg27; T reg32=2.8382638725840407781*elem.pos(1)[0]; reg18=reg17-reg18;
    reg17=0.3047053252581790631*elem.pos(1)[0]; reg8=reg8+reg19; T reg33=7.5267377805044972149*elem.pos(2)[0]; T reg34=0.27875481331111525221*elem.pos(3)[0]; reg31=reg31-reg21;
    T reg35=7.5267377805044979131*elem.pos(3)[0]; reg29=reg30-reg29; reg7=reg13*reg7; reg1=reg26*reg1; reg30=0.82437875909221917811*elem.pos(0)[0];
    reg18=reg32+reg18; reg8=reg17+reg8; reg17=0.27875481331111522752*elem.pos(2)[0]; reg32=0.13717836651415205219*elem.pos(1)[0]; reg28=reg28+reg20;
    T reg36=0.06214225908680241343*elem.pos(1)[0]; reg24=reg22-reg24; reg22=4.9076168648062268828*elem.pos(0)[0]; T reg37=3.3306249665903134478*elem.pos(3)[0]; reg31=reg31+reg34;
    reg30=reg17+reg30; reg22=reg33-reg22; reg17=0.13194163259416031138*elem.pos(3)[0]; reg26=0.2339569672863455*reg26; reg33=0.82437875909221940309*elem.pos(1)[0];
    reg13=0.2339569672863455*reg13; reg7=0.2339569672863455*reg7; reg35=reg29-reg35; reg29=4.9076168648062275983*elem.pos(1)[0]; reg1=0.2339569672863455*reg1;
    reg8=reg18*reg8; reg24=reg36+reg24; reg28=reg28-reg32; reg18=0.1803807865240695*reg18; reg26=reg13+reg26;
    reg17=reg30-reg17; reg1=reg7+reg1; reg8=0.1803807865240695*reg8; reg7=0.028808060190825794929*elem.pos(1)[0]; reg37=reg22-reg37;
    reg24=reg28*reg24; reg31=reg33+reg31; reg13=0.71150405089204313291*elem.pos(1)[0]; reg35=reg29+reg35; reg28=0.1803807865240695*reg28;
    reg18=reg26+reg18; reg31=reg35*reg31; reg17=reg7+reg17; reg24=0.1803807865240695*reg24; reg37=reg13+reg37;
    reg8=reg1+reg8; reg17=reg37*reg17; reg35=0.085662246189584999998*reg35; reg31=0.085662246189584999998*reg31; reg24=reg8+reg24;
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
    T reg0=0.6040626850758430438*elem.pos(0)[1]; T reg1=2.2615982821468569761*elem.pos(2)[1]; T reg2=3.3353846195212432377*elem.pos(2)[0]; T reg3=2.2615982821468569761*elem.pos(2)[0]; T reg4=0.46972365229854333709*elem.pos(0)[1];
    T reg5=0.6040626850758430438*elem.pos(0)[0]; T reg6=3.3353846195212432377*elem.pos(2)[1]; T reg7=0.46972365229854333709*elem.pos(0)[0]; T reg8=2.2615982821468567972*elem.pos(3)[0]; T reg9=0.46972365229854333709*elem.pos(0)[2];
    T reg10=3.3353846195212432377*elem.pos(2)[2]; T reg11=0.43609286044426324715*elem.pos(2)[1]; T reg12=reg7-reg2; T reg13=0.13717836651415197166*elem.pos(0)[1]; T reg14=reg4-reg6;
    T reg15=2.2615982821468567972*elem.pos(3)[1]; T reg16=0.6040626850758430438*elem.pos(0)[2]; T reg17=2.2615982821468569761*elem.pos(2)[2]; T reg18=3.3353846195212434166*elem.pos(3)[1]; reg0=reg1+reg0;
    T reg19=0.43609286044426324715*elem.pos(2)[0]; T reg20=3.3353846195212434166*elem.pos(3)[0]; reg5=reg3+reg5; T reg21=0.13717836651415197166*elem.pos(0)[0]; T reg22=0.60406268507584341281*elem.pos(1)[0];
    reg12=reg12+reg8; T reg23=0.60406268507584341281*elem.pos(1)[1]; reg14=reg14+reg15; T reg24=3.3353846195212434166*elem.pos(3)[2]; T reg25=reg9-reg10;
    T reg26=2.2615982821468567972*elem.pos(3)[2]; reg16=reg17+reg16; T reg27=reg18-reg0; T reg28=0.46972365229854320652*elem.pos(1)[1]; T reg29=reg20-reg5;
    T reg30=0.46972365229854320652*elem.pos(1)[0]; T reg31=0.43609286044426324715*elem.pos(2)[2]; T reg32=0.13717836651415197166*elem.pos(0)[2]; T reg33=2.5393493786539290877*elem.pos(3)[1]; T reg34=reg13-reg11;
    T reg35=2.8382638725840401981*elem.pos(0)[1]; T reg36=2.5393493786539285922*elem.pos(2)[1]; T reg37=reg21-reg19; T reg38=2.5393493786539290877*elem.pos(3)[0]; T reg39=2.8382638725840401981*elem.pos(0)[0];
    T reg40=2.5393493786539285922*elem.pos(2)[0]; T reg41=0.60406268507584341281*elem.pos(1)[2]; T reg42=reg32-reg31; T reg43=2.5393493786539290877*elem.pos(3)[2]; reg25=reg25+reg26;
    T reg44=3.3306249665903141463*elem.pos(2)[1]; T reg45=0.43609286044426374252*elem.pos(3)[1]; T reg46=0.71150405089204334872*elem.pos(0)[1]; T reg47=0.46972365229854320652*elem.pos(1)[2]; reg27=reg27-reg28;
    reg35=reg36-reg35; reg39=reg40-reg39; reg29=reg29-reg30; reg36=0.43609286044426374252*elem.pos(3)[0]; reg38=reg37-reg38;
    reg37=2.8382638725840407781*elem.pos(1)[0]; reg40=2.5393493786539285922*elem.pos(2)[2]; T reg48=2.8382638725840401981*elem.pos(0)[2]; T reg49=3.3306249665903141463*elem.pos(2)[0]; T reg50=0.71150405089204334872*elem.pos(0)[0];
    T reg51=2.8382638725840407781*elem.pos(1)[1]; T reg52=reg24-reg16; reg14=reg23+reg14; reg33=reg34-reg33; reg12=reg22+reg12;
    reg38=reg37+reg38; reg50=reg49-reg50; reg22=7.5267377805044979131*elem.pos(3)[0]; reg23=0.13717836651415205219*elem.pos(1)[1]; reg39=reg39+reg36;
    reg52=reg52-reg47; reg34=pow(reg29,2); reg37=0.43609286044426374252*elem.pos(3)[2]; reg48=reg40-reg48; reg43=reg42-reg43;
    reg35=reg35+reg45; reg33=reg51+reg33; reg40=2.8382638725840407781*elem.pos(1)[2]; reg42=pow(reg27,2); reg49=0.13717836651415205219*elem.pos(1)[0];
    reg46=reg44-reg46; reg44=7.5267377805044979131*elem.pos(3)[1]; reg51=pow(reg14,2); reg25=reg41+reg25; reg41=7.5267377805044972149*elem.pos(2)[1];
    T reg53=4.9076168648062268828*elem.pos(0)[1]; T reg54=3.3306249665903141463*elem.pos(2)[2]; T reg55=0.71150405089204334872*elem.pos(0)[2]; T reg56=pow(reg12,2); T reg57=4.9076168648062268828*elem.pos(0)[0];
    T reg58=7.5267377805044972149*elem.pos(2)[0]; T reg59=pow(reg38,2); reg22=reg50-reg22; reg53=reg41-reg53; reg41=4.9076168648062275983*elem.pos(1)[0];
    reg35=reg35-reg23; reg48=reg48+reg37; reg57=reg58-reg57; reg50=3.3306249665903134478*elem.pos(3)[0]; reg58=0.13717836651415205219*elem.pos(1)[2];
    reg43=reg40+reg43; reg40=4.9076168648062275983*elem.pos(1)[1]; reg44=reg46-reg44; reg46=pow(reg33,2); T reg60=7.5267377805044972149*elem.pos(2)[2];
    reg39=reg39-reg49; T reg61=4.9076168648062268828*elem.pos(0)[2]; reg55=reg54-reg55; reg54=7.5267377805044979131*elem.pos(3)[2]; reg42=reg34+reg42;
    reg34=pow(reg25,2); reg51=reg56+reg51; reg56=3.3306249665903134478*elem.pos(3)[1]; T reg62=pow(reg52,2); reg61=reg60-reg61;
    reg60=3.3306249665903134478*elem.pos(3)[2]; reg56=reg53-reg56; reg53=0.71150405089204313291*elem.pos(1)[1]; T reg63=pow(reg35,2); reg46=reg59+reg46;
    reg44=reg40+reg44; reg40=4.9076168648062275983*elem.pos(1)[2]; reg54=reg55-reg54; reg55=pow(reg39,2); reg34=reg51+reg34;
    reg62=reg42+reg62; reg22=reg41+reg22; reg41=0.71150405089204313291*elem.pos(1)[0]; reg48=reg48-reg58; reg50=reg57-reg50;
    reg42=pow(reg43,2); reg42=reg46+reg42; reg60=reg61-reg60; reg46=0.71150405089204313291*elem.pos(1)[2]; reg56=reg53+reg56;
    reg51=pow(reg22,2); reg63=reg55+reg63; reg50=reg41+reg50; reg41=pow(reg48,2); reg53=pow(reg44,2);
    reg62=pow(reg62,0.5); reg54=reg40+reg54; reg34=pow(reg34,0.5); reg40=0.91021395698862253836*elem.pos(2)[2]; reg55=0.037742890800314621403*elem.pos(0)[2];
    reg57=0.15072953754849390466*elem.pos(2)[2]; reg59=0.023200603736802050376*elem.pos(0)[2]; reg53=reg51+reg53; reg51=0.91021395698862253836*elem.pos(2)[1]; reg61=0.037742890800314621403*elem.pos(0)[1];
    T reg64=pow(reg54,2); T reg65=0.15072953754849390466*elem.pos(2)[1]; reg41=reg63+reg41; reg63=0.023200603736802050376*elem.pos(0)[1]; reg60=reg46+reg60;
    reg46=pow(reg50,2); T reg66=pow(reg56,2); reg42=pow(reg42,0.5); T reg67=0.023200603736802050376*elem.pos(0)[0]; T reg68=reg14/reg34;
    T reg69=reg27/reg62; T reg70=0.15072953754849390466*elem.pos(2)[0]; T reg71=reg29/reg62; T reg72=0.91021395698862253836*elem.pos(2)[0]; T reg73=reg12/reg34;
    T reg74=0.037742890800314621403*elem.pos(0)[0]; reg73=reg12*reg73; reg12=0.91021395698862271498*elem.pos(3)[1]; reg65=reg65-reg63; reg68=reg14*reg68;
    reg34=reg25/reg34; reg66=reg46+reg66; reg57=reg57-reg59; reg14=0.91021395698862271498*elem.pos(3)[2]; reg46=0.31139327261482343745*elem.pos(2)[2];
    T reg75=0.062142259086802441412*elem.pos(0)[2]; reg40=reg40-reg55; reg62=reg52/reg62; reg69=reg27*reg69; reg71=reg29*reg71;
    reg27=0.15072953754849408133*elem.pos(3)[2]; reg29=0.15072953754849408133*elem.pos(3)[0]; reg72=reg72-reg74; T reg76=0.31139327261482343745*elem.pos(2)[1]; T reg77=0.062142259086802441412*elem.pos(0)[1];
    reg70=reg70-reg67; T reg78=reg33/reg42; T reg79=reg38/reg42; T reg80=0.91021395698862271498*elem.pos(3)[0]; T reg81=pow(reg60,2);
    T reg82=0.062142259086802441412*elem.pos(0)[0]; T reg83=0.31139327261482343745*elem.pos(2)[0]; T reg84=0.15072953754849408133*elem.pos(3)[1]; reg51=reg51-reg61; reg41=pow(reg41,0.5);
    reg64=reg53+reg64; reg53=0.94454568826984199422*elem.pos(3)[2]; reg75=reg75-reg46; T reg85=0.30470532525817892595*elem.pos(0)[2]; T reg86=0.023200603736802073067*elem.pos(1)[0];
    reg40=reg40+reg27; T reg87=0.94454568826984188878*elem.pos(2)[2]; reg34=reg25*reg34; reg68=reg73+reg68; reg81=reg66+reg81;
    reg64=pow(reg64,0.5); reg25=0.037742890800314584493*elem.pos(1)[0]; reg66=0.94454568826984188878*elem.pos(2)[1]; reg73=0.30470532525817892595*elem.pos(0)[1]; T reg88=0.30470532525817892595*elem.pos(0)[0];
    T reg89=0.94454568826984188878*elem.pos(2)[0]; T reg90=0.94454568826984199422*elem.pos(3)[1]; reg77=reg77-reg76; reg42=reg43/reg42; reg78=reg33*reg78;
    reg79=reg38*reg79; reg70=reg70+reg80; reg33=0.94454568826984199422*elem.pos(3)[0]; reg82=reg82-reg83; reg51=reg51+reg84;
    reg38=reg39/reg41; T reg91=0.023200603736802073067*elem.pos(1)[1]; T reg92=reg35/reg41; reg65=reg65+reg12; T reg93=0.037742890800314584493*elem.pos(1)[1];
    T reg94=0.037742890800314584493*elem.pos(1)[2]; reg57=reg57+reg14; T reg95=0.023200603736802073067*elem.pos(1)[2]; reg62=reg52*reg62; reg69=reg71+reg69;
    reg72=reg72+reg29; reg81=pow(reg81,0.5); reg40=reg40-reg95; reg57=reg57-reg94; reg65=reg65-reg93;
    reg51=reg51-reg91; reg52=0.13194163259416033594*elem.pos(2)[1]; reg71=0.028808060190825802817*elem.pos(0)[1]; T reg96=0.3047053252581790631*elem.pos(1)[1]; reg77=reg77+reg90;
    reg66=reg73+reg66; reg73=0.31139327261482333201*elem.pos(3)[1]; T reg97=0.028808060190825802817*elem.pos(0)[2]; T reg98=0.13194163259416033594*elem.pos(2)[2]; reg41=reg48/reg41;
    reg92=reg35*reg92; reg35=0.13194163259416033594*elem.pos(2)[0]; T reg99=0.028808060190825802817*elem.pos(0)[0]; reg38=reg39*reg38; reg62=reg69+reg62;
    reg39=0.3047053252581790631*elem.pos(1)[0]; reg69=0.31139327261482333201*elem.pos(3)[2]; reg72=reg72-reg86; reg87=reg85+reg87; reg82=reg82+reg33;
    reg34=reg68+reg34; reg68=reg22/reg64; reg88=reg89+reg88; reg85=0.31139327261482333201*elem.pos(3)[0]; reg70=reg70-reg25;
    reg89=0.3047053252581790631*elem.pos(1)[2]; reg75=reg75+reg53; reg78=reg79+reg78; reg79=reg44/reg64; reg42=reg43*reg42;
    reg97=reg97-reg98; reg41=reg48*reg41; reg92=reg38+reg92; reg85=reg88-reg85; reg82=reg39+reg82;
    reg38=0.06214225908680241343*elem.pos(1)[1]; reg65=reg34*reg65; reg71=reg71-reg52; reg73=reg66-reg73; reg77=reg96+reg77;
    reg72=reg72*reg62; reg39=0.27875481331111525221*elem.pos(3)[2]; reg51=reg62*reg51; reg43=0.06214225908680241343*elem.pos(1)[0]; reg48=0.27875481331111522752*elem.pos(2)[2];
    reg66=0.82437875909221917811*elem.pos(0)[2]; reg42=reg78+reg42; reg40=reg62*reg40; reg78=0.82437875909221917811*elem.pos(0)[0]; reg88=0.27875481331111522752*elem.pos(2)[0];
    reg75=reg89+reg75; reg89=0.06214225908680241343*elem.pos(1)[2]; reg64=reg54/reg64; reg79=reg44*reg79; reg68=reg22*reg68;
    reg22=reg50/reg81; reg70=reg70*reg34; reg44=reg56/reg81; reg96=0.27875481331111525221*elem.pos(3)[1]; T reg100=0.82437875909221917811*elem.pos(0)[1];
    T reg101=0.27875481331111522752*elem.pos(2)[1]; reg99=reg99-reg35; T reg102=0.27875481331111525221*elem.pos(3)[0]; reg69=reg87-reg69; reg57=reg34*reg57;
    reg57=0.2339569672863455*reg57; reg69=reg89+reg69; reg87=0.82437875909221940309*elem.pos(1)[2]; reg75=reg42*reg75; reg48=reg66+reg48;
    reg66=0.13194163259416031138*elem.pos(3)[1]; reg101=reg100+reg101; reg89=0.82437875909221940309*elem.pos(1)[1]; reg73=reg38+reg73; reg97=reg97+reg39;
    reg38=0.13194163259416031138*elem.pos(3)[2]; reg71=reg71+reg96; reg40=0.2339569672863455*reg40; reg64=reg54*reg64; reg62=0.2339569672863455*reg62;
    reg41=reg92+reg41; reg72=0.2339569672863455*reg72; reg81=reg60/reg81; reg54=0.82437875909221940309*elem.pos(1)[0]; reg44=reg56*reg44;
    reg82=reg82*reg42; reg22=reg50*reg22; reg34=0.2339569672863455*reg34; reg65=0.2339569672863455*reg65; reg51=0.2339569672863455*reg51;
    reg99=reg99+reg102; reg77=reg42*reg77; reg85=reg43+reg85; reg79=reg68+reg79; reg43=0.13194163259416031138*elem.pos(3)[0];
    reg78=reg88+reg78; reg70=0.2339569672863455*reg70; reg42=0.1803807865240695*reg42; reg62=reg34+reg62; reg64=reg79+reg64;
    reg75=0.1803807865240695*reg75; reg81=reg60*reg81; reg44=reg22+reg44; reg40=reg57+reg40; reg43=reg78-reg43;
    reg22=0.028808060190825794929*elem.pos(1)[0]; reg99=reg54+reg99; reg69=reg41*reg69; reg77=0.1803807865240695*reg77; reg85=reg85*reg41;
    reg66=reg101-reg66; reg73=reg41*reg73; reg72=reg70+reg72; reg97=reg87+reg97; reg34=0.028808060190825794929*elem.pos(1)[1];
    reg38=reg48-reg38; reg48=0.028808060190825794929*elem.pos(1)[2]; reg71=reg89+reg71; reg82=0.1803807865240695*reg82; reg51=reg65+reg51;
    reg38=reg48+reg38; reg99=reg99*reg64; reg82=reg72+reg82; reg97=reg64*reg97; reg75=reg40+reg75;
    reg85=0.1803807865240695*reg85; reg69=0.1803807865240695*reg69; reg43=reg22+reg43; reg81=reg44+reg81; reg66=reg34+reg66;
    reg77=reg51+reg77; reg42=reg62+reg42; reg41=0.1803807865240695*reg41; reg73=0.1803807865240695*reg73; reg71=reg64*reg71;
    reg97=0.085662246189584999998*reg97; reg71=0.085662246189584999998*reg71; reg64=0.085662246189584999998*reg64; reg66=reg81*reg66; reg85=reg82+reg85;
    reg69=reg75+reg69; reg73=reg77+reg73; reg41=reg42+reg41; reg38=reg81*reg38; reg43=reg43*reg81;
    reg99=0.085662246189584999998*reg99; reg97=reg69+reg97; reg38=0.085662246189584999998*reg38; reg71=reg73+reg71; reg81=0.085662246189584999998*reg81;
    reg64=reg41+reg64; reg66=0.085662246189584999998*reg66; reg43=0.085662246189584999998*reg43; reg99=reg85+reg99; reg81=reg64+reg81;
    reg66=reg71+reg66; reg43=reg99+reg43; reg38=reg97+reg38; res[0]=reg43/reg81; res[1]=reg66/reg81;
    res[2]=reg38/reg81;

    return res;
}
}
#endif // LMT_BAR_4
