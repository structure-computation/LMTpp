#ifndef LMT_BAR_3
#define LMT_BAR_3
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Bar_3 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 5, 10, 15, 20, 27, 34, 41, 48, 55, }; // fonction de lordre du poly
    static const double values[] = {
        0.5,0.211324865405,
        0.5,0.788675134595,
        0.0,
        0.5,0.211324865405,
        0.5,0.788675134595,
        0.0,
        0.5,0.211324865405,
        0.5,0.788675134595,
        0.0,
        0.5,0.211324865405,
        0.5,0.788675134595,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
        0.444444444444,0.5,
        0.277777777778,0.112701665379,
        0.277777777778,0.887298334621,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Bar_3 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T det_jac=nodes[1]->pos[0]-nodes[0]->pos[0];

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[1],nodes[0],nodes[2]};
        for(unsigned i=0;i<3;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Bar_3 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.5-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=1-var_inter[0]; T reg3=2*var_inter[0]; T reg4=2*reg1;
    T reg5=2*reg2; T reg6=2*reg0; reg0=reg5*reg0; T reg7=4*reg2; reg1=reg1*reg3;
    reg3=reg4+reg3; reg5=reg6+reg5; reg4=4*var_inter[0]; reg6=pos_nodes[0][0]*reg5; T reg8=reg3*pos_nodes[1][0];
    T reg9=var_inter[0]*reg7; T reg10=pos_nodes[1][0]*reg1; T reg11=pos_nodes[0][0]*reg0; reg4=reg7-reg4; reg7=pos_nodes[2][0]*reg9;
    reg11=reg10+reg11; reg10=pos_nodes[2][0]*reg4; reg6=reg8-reg6; reg7=reg11+reg7; reg10=reg6+reg10;
    reg7=pos[0]-reg7; reg6=1.0/reg10; reg6=reg7*reg6; var_inter[0]=reg6;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Bar_3 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=var_inter[0]-0.5; T reg3=2*reg2; T reg4=2*reg1;
    T reg5=2*var_inter[0]; T reg6=2*reg0; reg3=reg3+reg5; T reg7=4*reg0; reg4=reg4+reg6;
    T reg8=4*var_inter[0]; reg2=reg5*reg2; reg1=reg6*reg1; reg5=var_inter[0]*reg7; reg8=reg7-reg8;
    reg6=pos_nodes[1][0]*reg3; reg7=pos_nodes[0][0]*reg4; T reg9=pos_nodes[0][0]*reg1; T reg10=pos_nodes[1][0]*reg2; T reg11=pos_nodes[2][0]*reg8;
    reg7=reg6-reg7; reg6=pos_nodes[2][0]*reg5; reg10=reg9+reg10; reg11=reg7+reg11; reg6=reg10+reg6;
    reg7=1.0/reg11; reg6=pos[0]-reg6; reg7=reg6*reg7; var_inter[0]+=reg7;

}
template<> struct ElemVarInterFromPosNonLinear<Bar_3> { static const bool res = 1; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal_2
#define STRUCT_Nodal_2
struct Nodal_2 {};
#endif // STRUCT_Nodal_2
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Nodal_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=val[0]*reg0; T reg2=val[1]*var_inter[0]; res=reg1+reg2;

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=0.5-var_inter[0]; T reg3=2*var_inter[0]; T reg4=2*reg0;
    T reg5=4*reg0; reg1=reg3*reg1; reg2=reg4*reg2; reg2=val[0]*reg2; reg1=val[1]*reg1;
    reg5=var_inter[0]*reg5; reg1=reg2+reg1; reg5=val[2]*reg5; res=reg1+reg5;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Bar_3 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Bar_3 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=2*var_inter[0]; T reg2=2*reg0; T reg3=0.5-var_inter[0]; T reg4=var_inter[0]-0.5;
    T reg5=4*reg0; reg3=reg2*reg3; res[0]=reg3; reg4=reg1*reg4; res[1]=reg4;
    reg5=var_inter[0]*reg5; res[2]=reg5;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Bar_3> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Bar_3,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=1-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=0.5-var_inter[0]; T reg3=2*reg2; T reg4=2*reg1;
    T reg5=2*var_inter[0]; T reg6=2*reg0; T reg7=4*var_inter[0]; reg3=reg6+reg3; reg4=reg5+reg4;
    T reg8=4*reg0; T reg9=elem.pos(0)[1]*reg3; T reg10=elem.pos(1)[1]*reg4; T reg11=elem.pos(0)[0]*reg3; T reg12=elem.pos(1)[0]*reg4;
    reg7=reg8-reg7; T reg13=elem.pos(2)[1]*reg7; reg10=reg10-reg9; reg12=reg12-reg11; reg4=elem.pos(1)[2]*reg4;
    T reg14=elem.pos(0)[2]*reg3; T reg15=elem.pos(2)[0]*reg7; reg13=reg10+reg13; reg7=elem.pos(2)[2]*reg7; reg12=reg15+reg12;
    reg4=reg4-reg14; reg4=reg7+reg4; reg7=pow(reg12,2); reg10=pow(reg13,2); reg15=pow(reg4,2);
    reg10=reg7+reg10; reg15=reg10+reg15; reg15=pow(reg15,0.5); reg7=reg12/reg15; reg10=reg13/reg15;
    reg15=reg4/reg15; reg10=reg13*reg10; reg12=reg7*reg12; reg15=reg4*reg15; reg10=reg12+reg10;
    reg15=reg10+reg15; return reg15;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,1> barycenter( const Element<Bar_3,TN,Node<1,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,1> res;
    T reg0=0.12200846792814621818*elem.pos(0)[0]; T reg1=0.45534180126147951289*elem.pos(1)[0]; T reg2=2.1547005383792514621*elem.pos(0)[0]; T reg3=0.15470053837925146212*elem.pos(1)[0]; T reg4=2.1547005383792514621*elem.pos(1)[0];
    T reg5=0.15470053837925146212*elem.pos(0)[0]; T reg6=0.12200846792814621818*elem.pos(1)[0]; T reg7=0.45534180126147951289*elem.pos(0)[0]; reg1=reg1-reg0; reg4=reg4+reg5;
    T reg8=2.3094010767585029242*elem.pos(2)[0]; reg2=reg3+reg2; T reg9=0.66666666666666670528*elem.pos(2)[0]; reg7=reg7-reg6; T reg10=reg8-reg2;
    reg7=reg7+reg9; reg1=reg9+reg1; reg4=reg4-reg8; reg1=reg1*reg4; reg7=reg7*reg10;
    reg10=0.5*reg10; reg7=0.5*reg7; reg1=0.5*reg1; reg4=0.5*reg4; reg1=reg7+reg1;
    reg4=reg10+reg4; res[0]=reg1/reg4;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Bar_3,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=2.1547005383792514621*elem.pos(0)[0]; T reg1=0.15470053837925146212*elem.pos(1)[0]; T reg2=0.15470053837925146212*elem.pos(1)[1]; T reg3=2.1547005383792514621*elem.pos(0)[1]; T reg4=0.15470053837925146212*elem.pos(0)[1];
    T reg5=2.1547005383792514621*elem.pos(1)[1]; T reg6=0.15470053837925146212*elem.pos(0)[0]; T reg7=2.1547005383792514621*elem.pos(1)[0]; reg7=reg7+reg6; reg5=reg5+reg4;
    T reg8=2.3094010767585029242*elem.pos(2)[1]; reg3=reg2+reg3; T reg9=2.3094010767585029242*elem.pos(2)[0]; reg0=reg1+reg0; reg7=reg7-reg9;
    reg5=reg5-reg8; T reg10=reg8-reg3; T reg11=reg9-reg0; T reg12=pow(reg10,2); T reg13=pow(reg7,2);
    T reg14=pow(reg5,2); T reg15=pow(reg11,2); reg12=reg15+reg12; reg14=reg13+reg14; reg14=pow(reg14,0.5);
    reg12=pow(reg12,0.5); reg13=0.45534180126147951289*elem.pos(1)[1]; reg15=0.12200846792814621818*elem.pos(0)[1]; T reg16=reg7/reg14; T reg17=0.12200846792814621818*elem.pos(1)[1];
    T reg18=0.45534180126147951289*elem.pos(0)[1]; reg14=reg5/reg14; T reg19=0.45534180126147951289*elem.pos(0)[0]; T reg20=0.12200846792814621818*elem.pos(1)[0]; T reg21=0.12200846792814621818*elem.pos(0)[0];
    T reg22=0.45534180126147951289*elem.pos(1)[0]; T reg23=reg10/reg12; reg12=reg11/reg12; reg14=reg5*reg14; reg19=reg19-reg20;
    reg16=reg7*reg16; reg5=0.66666666666666670528*elem.pos(2)[0]; reg18=reg18-reg17; reg12=reg11*reg12; reg23=reg10*reg23;
    reg7=0.66666666666666670528*elem.pos(2)[1]; reg22=reg22-reg21; reg13=reg13-reg15; reg18=reg18+reg7; reg13=reg7+reg13;
    reg14=reg16+reg14; reg19=reg19+reg5; reg23=reg12+reg23; reg22=reg5+reg22; reg13=reg14*reg13;
    reg22=reg22*reg14; reg19=reg19*reg23; reg18=reg23*reg18; reg14=0.5*reg14; reg13=0.5*reg13;
    reg22=0.5*reg22; reg18=0.5*reg18; reg23=0.5*reg23; reg19=0.5*reg19; reg13=reg18+reg13;
    reg14=reg23+reg14; reg22=reg19+reg22; res[1]=reg13/reg14; res[0]=reg22/reg14;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Bar_3,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.15470053837925146212*elem.pos(1)[0]; T reg1=2.1547005383792514621*elem.pos(1)[0]; T reg2=0.15470053837925146212*elem.pos(0)[0]; T reg3=2.1547005383792514621*elem.pos(0)[0]; T reg4=2.1547005383792514621*elem.pos(1)[1];
    T reg5=0.15470053837925146212*elem.pos(0)[1]; T reg6=0.15470053837925146212*elem.pos(1)[1]; T reg7=2.1547005383792514621*elem.pos(0)[1]; reg7=reg6+reg7; T reg8=2.3094010767585029242*elem.pos(2)[1];
    reg3=reg0+reg3; T reg9=2.1547005383792514621*elem.pos(0)[2]; T reg10=0.15470053837925146212*elem.pos(1)[2]; T reg11=2.3094010767585029242*elem.pos(2)[0]; reg1=reg1+reg2;
    reg4=reg4+reg5; T reg12=2.1547005383792514621*elem.pos(1)[2]; T reg13=0.15470053837925146212*elem.pos(0)[2]; reg1=reg1-reg11; T reg14=2.3094010767585029242*elem.pos(2)[2];
    reg9=reg10+reg9; reg4=reg4-reg8; reg12=reg12+reg13; T reg15=reg8-reg7; T reg16=reg11-reg3;
    T reg17=pow(reg15,2); T reg18=pow(reg16,2); T reg19=reg14-reg9; T reg20=pow(reg1,2); reg12=reg12-reg14;
    T reg21=pow(reg4,2); T reg22=pow(reg12,2); reg21=reg20+reg21; reg20=pow(reg19,2); reg17=reg18+reg17;
    reg20=reg17+reg20; reg22=reg21+reg22; reg20=pow(reg20,0.5); reg22=pow(reg22,0.5); reg17=reg1/reg22;
    reg18=reg4/reg22; reg21=reg15/reg20; T reg23=reg16/reg20; reg17=reg1*reg17; reg18=reg4*reg18;
    reg22=reg12/reg22; reg1=0.45534180126147951289*elem.pos(0)[1]; reg4=0.12200846792814621818*elem.pos(1)[1]; T reg24=0.12200846792814621818*elem.pos(0)[1]; T reg25=0.45534180126147951289*elem.pos(1)[1];
    T reg26=0.45534180126147951289*elem.pos(0)[2]; T reg27=0.12200846792814621818*elem.pos(1)[2]; T reg28=0.12200846792814621818*elem.pos(0)[2]; T reg29=0.45534180126147951289*elem.pos(1)[2]; T reg30=0.12200846792814621818*elem.pos(1)[0];
    T reg31=0.45534180126147951289*elem.pos(0)[0]; reg23=reg16*reg23; reg20=reg19/reg20; reg16=0.12200846792814621818*elem.pos(0)[0]; T reg32=0.45534180126147951289*elem.pos(1)[0];
    reg21=reg15*reg21; reg15=0.66666666666666670528*elem.pos(2)[1]; reg1=reg1-reg4; reg20=reg19*reg20; reg25=reg25-reg24;
    reg21=reg23+reg21; reg26=reg26-reg27; reg19=0.66666666666666670528*elem.pos(2)[2]; reg22=reg12*reg22; reg18=reg17+reg18;
    reg32=reg32-reg16; reg29=reg29-reg28; reg31=reg31-reg30; reg12=0.66666666666666670528*elem.pos(2)[0]; reg26=reg26+reg19;
    reg25=reg15+reg25; reg20=reg21+reg20; reg29=reg19+reg29; reg15=reg1+reg15; reg31=reg12+reg31;
    reg32=reg12+reg32; reg22=reg18+reg22; reg15=reg20*reg15; reg31=reg31*reg20; reg29=reg22*reg29;
    reg25=reg22*reg25; reg26=reg20*reg26; reg32=reg32*reg22; reg29=0.5*reg29; reg20=0.5*reg20;
    reg26=0.5*reg26; reg32=0.5*reg32; reg22=0.5*reg22; reg25=0.5*reg25; reg31=0.5*reg31;
    reg15=0.5*reg15; reg32=reg31+reg32; reg22=reg20+reg22; reg25=reg15+reg25; reg29=reg26+reg29;
    res[2]=reg29/reg22; res[0]=reg32/reg22; res[1]=reg25/reg22;

    return res;
}
}
#endif // LMT_BAR_3
