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
    T reg0=0.66666666666666662966-var_inter[0]; T reg1=0.33333333333333331483-var_inter[0]; T reg2=1-var_inter[0]; T reg3=reg1+reg0; T reg4=reg0-var_inter[0];
    T reg5=var_inter[0]*reg0; T reg6=reg1-var_inter[0]; T reg7=reg3*reg2; T reg8=reg1*reg0; reg4=reg4*reg2;
    reg1=reg1*var_inter[0]; T reg9=reg2*reg5; T reg10=reg2*reg8; T reg11=reg6*reg2; reg5=reg4-reg5;
    reg8=reg7+reg8; reg2=reg2*reg1; reg9=13.5*reg9; reg10=4.5*reg10; reg6=reg6*reg0;
    reg4=4.5*reg8; reg5=13.5*reg5; reg11=reg11-reg1; reg11=13.5*reg11; reg0=reg1*reg0;
    reg2=13.5*reg2; reg7=pos_nodes[2][0]*reg5; T reg12=pos_nodes[0][0]*reg4; reg1=reg6-reg1; reg6=pos_nodes[2][0]*reg9;
    T reg13=pos_nodes[0][0]*reg10; reg1=4.5*reg1; reg12=reg7-reg12; reg0=4.5*reg0; reg7=reg11*pos_nodes[3][0];
    reg6=reg13+reg6; reg13=reg2*pos_nodes[3][0]; reg13=reg6-reg13; reg6=pos_nodes[1][0]*reg0; reg7=reg12-reg7;
    reg12=pos_nodes[1][0]*reg1; reg7=reg12+reg7; reg13=reg6+reg13; reg13=pos[0]-reg13; reg6=1.0/reg7;
    reg6=reg13*reg6; var_inter[0]=reg6;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Bar_4 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=reg1-var_inter[0]; T reg3=1-var_inter[0]; T reg4=reg1+reg0;
    reg2=reg2*reg3; T reg5=reg4*reg3; T reg6=reg0-var_inter[0]; T reg7=reg1*reg0; T reg8=reg1*var_inter[0];
    reg0=reg0*var_inter[0]; T reg9=reg8*reg3; T reg10=reg7*reg3; T reg11=reg6*reg3; reg8=reg2-reg8;
    reg7=reg5+reg7; reg11=reg11-reg0; reg6=reg6*reg1; reg8=13.5*reg8; reg10=4.5*reg10;
    reg2=4.5*reg7; reg3=reg0*reg3; reg9=13.5*reg9; reg3=13.5*reg3; reg1=reg0*reg1;
    reg0=reg6-reg0; reg5=pos_nodes[2][0]*reg8; reg6=pos_nodes[0][0]*reg2; T reg12=pos_nodes[0][0]*reg10; T reg13=pos_nodes[2][0]*reg9;
    reg11=13.5*reg11; T reg14=reg3*pos_nodes[3][0]; reg13=reg12+reg13; reg0=4.5*reg0; reg1=4.5*reg1;
    reg12=reg11*pos_nodes[3][0]; reg6=reg5-reg6; reg14=reg13-reg14; reg5=pos_nodes[1][0]*reg1; reg13=pos_nodes[1][0]*reg0;
    reg12=reg6-reg12; reg12=reg13+reg12; reg14=reg5+reg14; reg5=1.0/reg12; reg14=pos[0]-reg14;
    reg5=reg14*reg5; var_inter[0]+=reg5;

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
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=var_inter[0]*reg1; T reg3=reg1*reg0; T reg4=1-var_inter[0];
    reg0=var_inter[0]*reg0; reg2=reg4*reg2; reg3=reg3*reg4; reg4=reg4*reg0; reg3=4.5*reg3;
    reg2=13.5*reg2; reg2=val[2]*reg2; reg3=val[0]*reg3; reg4=13.5*reg4; reg0=reg1*reg0;
    reg0=4.5*reg0; reg2=reg3+reg2; reg1=val[3]*reg4; reg0=val[1]*reg0; reg1=reg2-reg1;
    res=reg0+reg1;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Bar_4 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    T reg4=reg2*reg3; T reg5=var_inter[0]*reg1; reg3=reg1*reg3; reg4=13.5*reg4; reg0=reg0*reg2;
    reg5=reg2*reg5; reg0=4.5*reg0; res[0]=reg0; reg5=13.5*reg5; res[2]=reg5;
    res[3]=-reg4; reg3=4.5*reg3; res[1]=reg3;

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

}
#endif // LMT_BAR_4
