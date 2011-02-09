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
    T reg0=1-var_inter[0]; T reg1=0.5-var_inter[0]; T reg2=var_inter[0]-0.5; T reg3=2*reg0; T reg4=2*var_inter[0];
    T reg5=2*reg1; T reg6=2*reg2; reg1=reg3*reg1; T reg7=4*var_inter[0]; reg3=reg5+reg3;
    reg6=reg4+reg6; reg5=4*reg0; reg2=reg4*reg2; reg4=pos_nodes[0][0]*reg1; T reg8=reg2*pos_nodes[1][0];
    T reg9=pos_nodes[0][0]*reg3; T reg10=pos_nodes[1][0]*reg6; reg7=reg5-reg7; reg5=reg5*var_inter[0]; reg9=reg10-reg9;
    reg10=pos_nodes[2][0]*reg7; reg4=reg8+reg4; reg8=pos_nodes[2][0]*reg5; reg10=reg9+reg10; reg8=reg4+reg8;
    reg8=pos[0]-reg8; reg4=1.0/reg10; reg4=reg8*reg4; var_inter[0]=reg4;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Bar_3 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.5-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=1-var_inter[0]; T reg3=2*reg0; T reg4=2*reg1;
    T reg5=2*reg2; T reg6=2*var_inter[0]; T reg7=4*reg2; reg3=reg3+reg5; reg4=reg4+reg6;
    T reg8=4*var_inter[0]; reg1=reg6*reg1; reg5=reg0*reg5; reg0=var_inter[0]*reg7; reg8=reg7-reg8;
    reg6=pos_nodes[1][0]*reg4; reg7=pos_nodes[0][0]*reg3; T reg9=pos_nodes[1][0]*reg1; T reg10=pos_nodes[0][0]*reg5; reg7=reg6-reg7;
    reg6=pos_nodes[2][0]*reg8; T reg11=pos_nodes[2][0]*reg0; reg9=reg10+reg9; reg6=reg7+reg6; reg11=reg9+reg11;
    reg7=1.0/reg6; reg11=pos[0]-reg11; reg7=reg11*reg7; var_inter[0]+=reg7;

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
    T reg0=1-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=2*var_inter[0]; T reg3=2*reg0; T reg4=0.5-var_inter[0];
    T reg5=4*reg0; reg1=reg2*reg1; reg4=reg3*reg4; reg4=val[0]*reg4; reg1=val[1]*reg1;
    reg5=var_inter[0]*reg5; reg1=reg4+reg1; reg5=val[2]*reg5; res=reg1+reg5;

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
    T reg0=1-var_inter[0]; T reg1=var_inter[0]-0.5; T reg2=0.5-var_inter[0]; T reg3=2*reg1; T reg4=2*reg2;
    T reg5=2*var_inter[0]; T reg6=2*reg0; T reg7=4*var_inter[0]; reg4=reg6+reg4; reg3=reg5+reg3;
    T reg8=4*reg0; T reg9=elem.pos(1)[0]*reg3; reg7=reg8-reg7; T reg10=elem.pos(0)[0]*reg4; T reg11=elem.pos(0)[1]*reg4;
    T reg12=elem.pos(1)[1]*reg3; T reg13=elem.pos(2)[1]*reg7; T reg14=elem.pos(0)[2]*reg4; reg3=elem.pos(1)[2]*reg3; reg9=reg9-reg10;
    T reg15=elem.pos(2)[0]*reg7; reg12=reg12-reg11; reg7=elem.pos(2)[2]*reg7; reg3=reg3-reg14; reg15=reg9+reg15;
    reg13=reg12+reg13; reg3=reg7+reg3; reg7=pow(reg15,2); reg9=pow(reg13,2); reg9=reg7+reg9;
    reg7=pow(reg3,2); reg7=reg9+reg7; reg7=pow(reg7,0.5); reg9=reg13/reg7; reg12=reg15/reg7;
    reg7=reg3/reg7; reg9=reg13*reg9; reg15=reg12*reg15; reg9=reg15+reg9; reg7=reg3*reg7;
    reg7=reg9+reg7; return reg7;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,1> barycenter( const Element<Bar_3,TN,Node<1,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,1> res;
    T reg0=4*elem.pos(0)[0]; T reg1=4*elem.pos(1)[0]; T reg2=8*elem.pos(2)[0]; T reg3=3*elem.pos(0)[0]; reg1=reg1+reg0;
    reg1=reg1-reg2; T reg4=4*elem.pos(2)[0]; reg3=elem.pos(1)[0]+reg3; reg4=reg4-reg3; T reg5=2*reg1;
    T reg6=reg1*elem.pos(0)[0]; T reg7=pow(reg4,2); T reg8=reg4*reg1; T reg9=reg4*reg5; T reg10=reg1*reg5;
    T reg11=pow(reg1,2); reg9=reg8+reg9; reg7=reg6+reg7; reg9=0.5*reg9; reg10=reg11+reg10;
    reg7=reg7/2; reg6=reg4*elem.pos(0)[0]; reg10=0.16666666666666666667*reg10; reg7=reg6+reg7; reg9=reg9/3;
    reg6=reg1/2; reg9=reg7+reg9; reg10=reg10/4; reg10=reg9+reg10; reg4=reg6+reg4;
    res[0]=reg10/reg4;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Bar_3,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=4*elem.pos(1)[0]; T reg1=4*elem.pos(0)[0]; T reg2=4*elem.pos(1)[1]; T reg3=4*elem.pos(0)[1]; T reg4=3*elem.pos(0)[1];
    T reg5=3*elem.pos(0)[0]; T reg6=8*elem.pos(2)[1]; reg2=reg2+reg3; reg0=reg0+reg1; T reg7=8*elem.pos(2)[0];
    T reg8=4*elem.pos(2)[1]; reg0=reg0-reg7; reg4=elem.pos(1)[1]+reg4; reg5=elem.pos(1)[0]+reg5; T reg9=4*elem.pos(2)[0];
    reg2=reg2-reg6; T reg10=2*reg0; T reg11=2*reg2; reg8=reg8-reg4; reg9=reg9-reg5;
    T reg12=pow(reg8,2); T reg13=reg9*reg10; T reg14=reg8*reg11; T reg15=pow(reg9,2); reg14=reg13+reg14;
    reg13=reg2*reg11; T reg16=reg0*reg10; reg12=reg15+reg12; reg16=reg13+reg16; reg13=pow(reg12,-4.5);
    reg15=3.5*reg14; T reg17=2.5*reg16; reg15=reg13*reg15; reg13=pow(reg12,-3.5); T reg18=2.5*reg14;
    T reg19=reg13*reg17; reg15=reg18*reg15; reg18=reg13*reg18; reg13=pow(reg12,-2.5); T reg20=1.5*reg14;
    T reg21=1.5*reg16; reg15=reg19-reg15; reg19=reg20*reg18; T reg22=reg13*reg21; reg15=reg20*reg15;
    reg20=reg13*reg20; reg18=reg21*reg18; reg19=reg22-reg19; reg13=pow(reg12,-1.5); reg16=0.5*reg16;
    reg14=0.5*reg14; reg22=reg16*reg20; reg20=reg14*reg20; T reg23=reg14*reg19; T reg24=reg16*reg13;
    reg15=reg18+reg15; reg23=reg22+reg23; reg20=reg24-reg20; reg13=reg14*reg13; reg15=reg18+reg15;
    reg23=reg22+reg23; reg19=reg16*reg19; reg18=reg14*reg20; reg22=pow(reg12,-0.5); reg15=reg14*reg15;
    reg24=reg16*reg13; T reg25=reg14*reg23; reg18=reg24+reg18; reg13=reg14*reg13; T reg26=reg22*reg16;
    reg20=reg16*reg20; reg15=reg19-reg15; reg13=reg26-reg13; reg22=reg22*reg14; reg15=reg19+reg15;
    reg25=reg20-reg25; reg18=reg24+reg18; reg24=2*reg13; reg15=reg19+reg15; reg25=reg20+reg25;
    reg19=2*reg22; reg26=2*reg18; reg12=pow(reg12,0.5); reg23=reg16*reg23; reg25=reg20+reg25;
    reg20=reg22*reg24; reg15=reg14*reg15; reg14=reg12*reg26; T reg27=reg13*reg19; T reg28=reg12*reg24;
    T reg29=reg22*reg19; T reg30=reg0*reg13; T reg31=reg9*reg18; reg29=reg28+reg29; reg27=reg20+reg27;
    reg14=reg20-reg14; reg20=reg12*reg19; reg28=2*reg25; T reg32=reg2*reg13; T reg33=reg8*reg18;
    reg15=reg23+reg15; reg31=reg30-reg31; reg24=reg13*reg24; T reg34=reg0*reg18; reg26=reg22*reg26;
    reg33=reg32-reg33; reg28=reg12*reg28; reg19=reg19*reg18; reg15=reg23+reg15; T reg35=reg9*reg25;
    T reg36=2*reg20; T reg37=reg8*reg25; reg18=reg2*reg18; T reg38=2*reg29; reg27=reg14+reg27;
    reg14=reg8*reg13; T reg39=reg2*reg22; reg13=reg9*reg13; T reg40=pow(reg12,2); T reg41=reg0*reg22;
    T reg42=reg40*reg38; T reg43=reg20*reg36; T reg44=reg8*reg22; reg22=reg9*reg22; reg19=reg24-reg19;
    reg15=reg23+reg15; reg37=reg18+reg37; reg13=reg41+reg13; reg14=reg39+reg14; reg31=reg30+reg31;
    reg35=reg34+reg35; T reg45=2*reg27; reg33=reg32+reg33; reg28=reg26+reg28; reg26=reg24-reg26;
    reg15=reg23+reg15; reg23=reg13*reg29; reg19=reg26+reg19; reg35=reg34+reg35; reg43=reg42+reg43;
    reg24=reg44*reg27; reg42=reg20*reg14; T reg46=reg44*reg29; T reg47=reg22*reg27; T reg48=reg29*reg36;
    reg38=reg20*reg38; reg45=reg40*reg45; reg28=reg26-reg28; reg26=reg14*reg29; T reg49=reg13*reg20;
    reg37=reg18+reg37; T reg50=reg20*reg33; T reg51=reg22*reg29; reg36=reg40*reg36; T reg52=reg20*reg31;
    T reg53=reg8*reg15; reg19=reg28+reg19; reg28=reg52+reg23; reg46=reg42+reg46; reg47=reg23+reg47;
    reg23=reg2*reg25; reg35=reg34+reg35; T reg54=2*reg36; T reg55=reg44*reg20; reg15=reg9*reg15;
    T reg56=reg22*reg20; reg24=reg26+reg24; T reg57=pow(reg40,2); T reg58=2*reg43; reg48=reg38+reg48;
    reg38=reg45+reg38; reg26=reg50+reg26; reg25=reg0*reg25; reg51=reg49+reg51; reg37=reg18+reg37;
    reg45=reg14*reg27; T reg59=reg13*reg27; T reg60=reg31*reg29; T reg61=reg20*reg35; reg53=reg23-reg53;
    reg48=reg38+reg48; reg38=reg36*reg54; reg58=reg57*reg58; reg24=reg26+reg24; T reg62=reg29*reg33;
    T reg63=reg20*reg37; reg15=reg25-reg15; reg54=reg57*reg54; T reg64=reg22*reg19; T reg65=reg55*reg43;
    reg19=reg44*reg19; reg47=reg28+reg47; T reg66=reg51*reg36; T reg67=reg36*reg46; T reg68=reg56*reg43;
    T reg69=reg60+reg59; reg15=reg25+reg15; T reg70=reg62-reg63; T reg71=reg20*reg32; reg53=reg23+reg53;
    reg60=reg60-reg61; reg68=reg66+reg68; reg65=reg67+reg65; T reg72=reg39*reg29; reg38=reg58+reg38;
    reg58=2*reg54; T reg73=reg36*reg24; T reg74=reg56*reg36; T reg75=pow(reg57,2); T reg76=reg51*reg43;
    T reg77=reg55*reg48; T reg78=reg36*reg47; reg64=reg59+reg64; reg59=reg55*reg36; T reg79=reg46*reg43;
    reg48=reg56*reg48; reg19=reg45+reg19; T reg80=reg20*reg30; T reg81=reg41*reg29; reg45=reg62+reg45;
    reg62=reg73+reg79; reg53=reg23+reg53; reg15=reg25+reg15; reg64=reg69+reg64; T reg82=reg74*reg54;
    T reg83=pow(reg75,2); T reg84=reg20*reg39; T reg85=reg41*reg27; reg77=reg79+reg77; reg79=reg54*reg65;
    T reg86=reg20*reg18; T reg87=reg29*reg32; T reg88=reg49*reg43; reg72=reg71+reg72; T reg89=reg74*reg38;
    T reg90=reg78+reg76; reg38=reg59*reg38; reg29=reg30*reg29; T reg91=reg36*reg42; T reg92=reg20*reg34;
    reg58=reg75*reg58; reg20=reg41*reg20; T reg93=reg68*reg54; reg81=reg80+reg81; T reg94=reg59*reg54;
    T reg95=reg36*reg28; T reg96=reg70+reg45; T reg97=reg49*reg36; reg69=reg60+reg69; T reg98=reg36*reg26;
    T reg99=reg42*reg43; reg27=reg39*reg27; reg19=reg45+reg19; reg48=reg76+reg48; reg48=reg90+reg48;
    reg27=reg87+reg27; reg88=reg95+reg88; reg45=reg36*reg72; reg76=reg36*reg84; T reg100=reg20*reg36;
    reg38=reg79+reg38; reg89=reg93+reg89; T reg101=reg82*reg58; T reg102=reg36*reg81; reg58=reg94*reg58;
    T reg103=reg66*reg54; reg15=reg25+reg15; reg19=reg96+reg19; T reg104=reg29-reg92; T reg105=reg20*reg43;
    T reg106=reg36*reg52; T reg107=reg36*reg50; T reg108=reg54*reg67; reg85=reg29+reg85; reg64=reg69+reg64;
    reg29=reg54*reg91; T reg109=reg97*reg54; reg43=reg84*reg43; reg99=reg98+reg99; reg77=reg62+reg77;
    reg87=reg87-reg86; reg53=reg23+reg53; T reg110=pow(reg83,2); reg27=reg87+reg27; reg60=reg60/reg57;
    T reg111=reg36*reg71; T reg112=reg100*reg54; reg106=reg106/reg75; reg85=reg104+reg85; reg36=reg36*reg80;
    reg105=reg102+reg105; reg88=reg88/reg75; reg109=reg109/reg83; reg48=reg48/reg75; reg96=reg96/reg57;
    reg98=reg98/reg75; reg99=reg99/reg75; reg29=reg29/reg83; reg19=reg19/reg57; reg73=reg73/reg75;
    reg62=reg62/reg75; reg108=reg108/reg83; reg64=reg64/reg57; reg78=reg78/reg75; reg77=reg77/reg75;
    reg79=reg79/reg83; reg90=reg90/reg75; reg38=reg38/reg83; reg103=reg103/reg83; reg58=reg58/reg110;
    reg89=reg89/reg83; reg43=reg45+reg43; reg54=reg54*reg76; reg93=reg93/reg83; reg110=reg101/reg110;
    reg15=reg15/reg40; reg61=reg61/reg57; reg70=reg70/reg57; reg107=reg107/reg75; reg69=reg69/reg57;
    reg95=reg95/reg75; reg53=reg53/reg40; reg63=reg63/reg57; reg112=reg112/reg83; reg36=reg36/reg75;
    reg103=reg90-reg103; reg95=reg69-reg95; reg93=reg48-reg93; reg105=reg105/reg75; reg25=reg25/reg40;
    reg92=reg92/reg57; reg78=reg64-reg78; reg109=reg88-reg109; reg110=reg89-reg110; reg106=reg60-reg106;
    reg85=reg85/reg57; reg61=reg15-reg61; reg102=reg102/reg75; reg65=reg65/reg75; reg67=reg67/reg75;
    reg24=reg24/reg57; reg91=reg91/reg75; reg26=reg26/reg57; reg37=reg37/reg40; reg50=reg50/reg57;
    reg43=reg43/reg75; reg54=reg54/reg83; reg82=reg82/reg83; reg68=reg68/reg75; reg66=reg66/reg75;
    reg47=reg47/reg57; reg107=reg70-reg107; reg97=reg97/reg75; reg28=reg28/reg57; reg35=reg35/reg40;
    reg63=reg53-reg63; reg52=reg52/reg57; reg98=reg96-reg98; reg29=reg99-reg29; reg73=reg19-reg73;
    reg108=reg62-reg108; reg79=reg77-reg79; reg58=reg38-reg58; reg27=reg27/reg57; reg86=reg86/reg57;
    reg45=reg45/reg75; reg23=reg23/reg40; reg111=reg111/reg75; reg87=reg87/reg57; reg83=reg94/reg83;
    reg104=reg104/reg57; reg66=reg47-reg66; reg102=reg85-reg102; reg86=reg23-reg86; reg58=reg79-reg58;
    reg61=reg106+reg61; reg97=reg28-reg97; reg103=reg78-reg103; reg111=reg87-reg111; reg35=reg52+reg35;
    reg36=reg104-reg36; reg108=reg73-reg108; reg63=reg107+reg63; reg100=reg100/reg75; reg81=reg81/reg57;
    reg109=reg95-reg109; reg34=reg34/reg40; reg80=reg80/reg57; reg92=reg25-reg92; reg29=reg98-reg29;
    reg91=reg26-reg91; reg83=reg65-reg83; reg37=reg50+reg37; reg112=reg105-reg112; reg67=reg24-reg67;
    reg76=reg76/reg75; reg72=reg72/reg57; reg18=reg18/reg40; reg45=reg27-reg45; reg71=reg71/reg57;
    reg110=reg93-reg110; reg82=reg68-reg82; reg54=reg43-reg54; reg86=reg111+reg86; reg83=reg67-reg83;
    reg29=reg63+reg29; reg31=reg31/reg40; reg49=reg49/reg57; reg59=reg59/reg75; reg46=reg46/reg57;
    reg42=reg42/reg57; reg33=reg33/reg40; reg51=reg51/reg57; reg91=reg37+reg91; reg110=reg103-reg110;
    reg75=reg74/reg75; reg112=reg102-reg112; reg82=reg66-reg82; reg34=reg80+reg34; reg109=reg61+reg109;
    reg58=reg108-reg58; reg76=reg72-reg76; reg100=reg81-reg100; reg92=reg36+reg92; reg54=reg45-reg54;
    reg18=reg71+reg18; reg97=reg35+reg97; reg20=reg20/reg57; reg30=reg30/reg40; reg49=reg31-reg49;
    reg58=reg29+reg58; reg75=reg51-reg75; reg32=reg32/reg40; reg84=reg84/reg57; reg42=reg33-reg42;
    reg59=reg46-reg59; reg110=reg109+reg110; reg112=reg92+reg112; reg83=reg91+reg83; reg76=reg18+reg76;
    reg100=reg34+reg100; reg54=reg86+reg54; reg82=reg97+reg82; reg110=reg112+reg110; reg58=reg54+reg58;
    reg14=reg14/reg40; reg75=reg49-reg75; reg56=reg56/reg57; reg84=reg32-reg84; reg13=reg13/reg40;
    reg57=reg55/reg57; reg20=reg30-reg20; reg83=reg76+reg83; reg59=reg42-reg59; reg82=reg100+reg82;
    reg41=reg41/reg40; reg56=reg13-reg56; reg75=reg20+reg75; reg13=reg2*reg83; reg110=reg9*reg110;
    reg39=reg39/reg40; reg15=reg0*reg82; reg57=reg14-reg57; reg58=reg8*reg58; reg59=reg84+reg59;
    reg82=reg9*reg82; reg14=reg2*reg59; reg57=reg39+reg57; reg83=reg8*reg83; reg58=reg13+reg58;
    reg56=reg41+reg56; reg44=reg44/reg40; reg18=reg2/reg12; reg19=reg0*reg75; reg40=reg22/reg40;
    reg110=reg15+reg110; reg20=reg0/reg12; reg82=reg19-reg82; reg58=reg13+reg58; reg40=reg20-reg40;
    reg20=reg0*reg56; reg75=reg9*reg75; reg83=reg14-reg83; reg59=reg8*reg59; reg44=reg18-reg44;
    reg18=reg2*reg57; reg110=reg15+reg110; reg22=reg9/reg12; reg23=reg0*reg40; reg83=reg14+reg83;
    reg58=reg13+reg58; reg57=reg8*reg57; reg110=reg15+reg110; reg24=reg2*reg44; reg59=reg18+reg59;
    reg75=reg20+reg75; reg82=reg19+reg82; reg56=reg9*reg56; reg12=reg8/reg12; reg56=reg23-reg56;
    reg58=reg13+reg58; reg40=reg9*reg40; reg25=reg22*reg0; reg59=reg18+reg59; reg110=reg15+reg110;
    reg44=reg8*reg44; reg75=reg20+reg75; reg57=reg24-reg57; reg83=reg14+reg83; reg26=reg12*reg2;
    reg82=reg19+reg82; reg83=reg14+reg83; reg57=reg24+reg57; reg75=reg20+reg75; reg110=reg15+reg110;
    reg56=reg23+reg56; reg58=reg13+reg58; reg26=reg44+reg26; reg25=reg40+reg25; reg82=reg19+reg82;
    reg12=reg8*reg12; reg22=reg9*reg22; reg59=reg18+reg59; reg59=reg75+reg59; reg58=reg110+reg58;
    reg26=reg25+reg26; reg83=reg82+reg83; reg57=reg56+reg57; reg12=reg22+reg12; reg13=elem.pos(0)[0]*reg57;
    reg14=reg9*reg26; reg15=reg12*reg0; reg18=reg9*reg57; reg19=elem.pos(0)[1]*reg57; reg20=reg8*reg26;
    reg22=reg8*reg83; reg23=elem.pos(0)[1]*reg59; reg24=elem.pos(0)[1]*reg58; reg25=reg9*reg83; reg27=reg0*reg59;
    reg28=reg12*reg2; reg29=reg2*reg26; reg30=reg8*reg57; reg31=reg2*reg57; reg32=elem.pos(0)[0]*reg58;
    reg33=elem.pos(0)[0]*reg83; reg34=reg2*reg59; reg35=reg9*reg59; reg36=reg0*reg57; reg37=reg8*reg59;
    reg38=elem.pos(0)[1]*reg83; reg39=reg0*reg26; reg40=elem.pos(0)[0]*reg59; reg41=elem.pos(0)[1]*reg26; reg8=reg8*reg12;
    reg19=reg19+reg20; reg28=reg20+reg28; reg32=reg25-reg32; reg25=reg27+reg25; reg23=reg30-reg23;
    reg30=reg30+reg29; reg20=reg34+reg22; reg33=reg35+reg33; reg42=elem.pos(0)[0]*reg26; reg9=reg9*reg12;
    reg35=reg36-reg35; reg43=reg31-reg37; reg38=reg37+reg38; reg37=reg18+reg39; reg40=reg18-reg40;
    reg13=reg13+reg14; reg15=reg14+reg15; reg24=reg22-reg24; reg8=reg41+reg8; reg14=reg34+reg20;
    reg24=reg20+reg24; reg28=reg19+reg28; reg23=reg23+reg30; reg30=reg29+reg30; reg18=reg31+reg43;
    reg38=reg43-reg38; reg19=reg36+reg35; reg20=reg27+reg25; reg32=reg25+reg32; reg33=reg35-reg33;
    reg9=reg42+reg9; reg39=reg39+reg37; reg37=reg40+reg37; reg15=reg13+reg15; reg30=reg23+reg30;
    reg57=0.5*reg57; reg9=reg9/2; reg33=reg33+reg19; reg13=elem.pos(0)[1]*reg12; reg19=reg36+reg19;
    reg39=reg37+reg39; reg15=0.5*reg15; reg38=reg38+reg18; reg18=reg31+reg18; reg26=reg26/2;
    reg22=reg27+reg20; reg23=elem.pos(0)[0]*reg12; reg32=reg20+reg32; reg24=reg14+reg24; reg14=reg34+reg14;
    reg28=0.5*reg28; reg8=reg8/2; reg19=reg33+reg19; reg30=0.16666666666666666667*reg30; reg39=0.16666666666666666667*reg39;
    reg18=reg38+reg18; reg24=reg24+reg14; reg14=reg34+reg14; reg8=reg13+reg8; reg28=reg28/3;
    reg32=reg32+reg22; reg22=reg27+reg22; reg15=reg15/3; reg9=reg23+reg9; reg13=0.16666666666666666667*reg59;
    reg57=reg57/3; reg26=reg12+reg26; reg30=reg30/4; reg28=reg8+reg28; reg15=reg9+reg15;
    reg39=reg39/4; reg14=reg24+reg14; reg8=0.041666666666666666668*reg83; reg18=0.041666666666666666668*reg18; reg57=reg26+reg57;
    reg13=reg13/4; reg19=0.041666666666666666668*reg19; reg22=reg32+reg22; reg58=0.0083333333333333333337*reg58; reg8=reg8/5;
    reg13=reg57-reg13; reg18=reg18/5; reg30=reg28+reg30; reg19=reg19/5; reg39=reg15+reg39;
    reg9=0.0083333333333333333337*reg14; reg12=0.0083333333333333333337*reg22; reg9=reg9/6; reg18=reg30+reg18; reg8=reg13-reg8;
    reg58=reg58/6; reg19=reg39+reg19; reg12=reg12/6; reg8=reg58+reg8; reg12=reg19-reg12;
    reg9=reg18-reg9; res[0]=reg12/reg8; res[1]=reg9/reg8;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Bar_3,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=4*elem.pos(0)[1]; T reg1=4*elem.pos(1)[1]; T reg2=4*elem.pos(0)[0]; T reg3=4*elem.pos(1)[0]; T reg4=4*elem.pos(0)[2];
    T reg5=3*elem.pos(0)[1]; T reg6=4*elem.pos(1)[2]; T reg7=3*elem.pos(0)[0]; reg1=reg1+reg0; T reg8=8*elem.pos(2)[1];
    reg3=reg3+reg2; T reg9=8*elem.pos(2)[0]; reg5=elem.pos(1)[1]+reg5; T reg10=3*elem.pos(0)[2]; reg1=reg1-reg8;
    T reg11=4*elem.pos(2)[1]; reg3=reg3-reg9; reg7=elem.pos(1)[0]+reg7; reg6=reg6+reg4; T reg12=8*elem.pos(2)[2];
    T reg13=4*elem.pos(2)[0]; reg13=reg13-reg7; T reg14=2*reg1; reg6=reg6-reg12; reg11=reg11-reg5;
    T reg15=2*reg3; T reg16=4*elem.pos(2)[2]; reg10=elem.pos(1)[2]+reg10; T reg17=reg11*reg14; T reg18=reg13*reg15;
    reg16=reg16-reg10; T reg19=2*reg6; T reg20=pow(reg11,2); T reg21=pow(reg13,2); T reg22=pow(reg16,2);
    reg20=reg21+reg20; reg17=reg18+reg17; reg18=reg16*reg19; reg21=reg3*reg15; T reg23=reg1*reg14;
    reg18=reg17+reg18; reg23=reg21+reg23; reg17=reg6*reg19; reg22=reg20+reg22; reg17=reg23+reg17;
    reg20=3.5*reg18; reg21=pow(reg22,-4.5); reg20=reg21*reg20; reg21=2.5*reg18; reg23=2.5*reg17;
    T reg24=pow(reg22,-3.5); reg20=reg21*reg20; T reg25=1.5*reg17; T reg26=1.5*reg18; T reg27=pow(reg22,-2.5);
    T reg28=reg24*reg23; reg21=reg24*reg21; reg20=reg28-reg20; reg24=reg26*reg21; reg28=reg27*reg25;
    reg27=reg27*reg26; reg18=0.5*reg18; T reg29=pow(reg22,-1.5); reg17=0.5*reg17; reg24=reg28-reg24;
    reg21=reg25*reg21; reg20=reg26*reg20; reg26=reg18*reg27; reg27=reg17*reg27; reg28=reg17*reg29;
    reg20=reg21+reg20; T reg30=reg18*reg24; reg26=reg28-reg26; reg29=reg18*reg29; reg30=reg27+reg30;
    reg20=reg21+reg20; reg21=reg18*reg26; reg30=reg27+reg30; reg27=pow(reg22,-0.5); reg28=reg17*reg29;
    reg24=reg17*reg24; reg20=reg18*reg20; reg26=reg17*reg26; reg29=reg18*reg29; T reg31=reg18*reg30;
    T reg32=reg27*reg17; reg21=reg28+reg21; reg20=reg24-reg20; reg21=reg28+reg21; reg27=reg27*reg18;
    reg20=reg24+reg20; reg31=reg26-reg31; reg29=reg32-reg29; reg28=2*reg27; reg32=2*reg21;
    reg22=pow(reg22,0.5); T reg33=2*reg29; reg31=reg26+reg31; reg20=reg24+reg20; reg31=reg26+reg31;
    reg24=reg27*reg33; reg20=reg18*reg20; reg30=reg17*reg30; reg18=reg22*reg33; reg26=reg27*reg28;
    T reg34=reg22*reg32; T reg35=reg29*reg28; reg35=reg24+reg35; T reg36=reg3*reg29; reg34=reg24-reg34;
    reg24=2*reg31; T reg37=reg1*reg29; T reg38=reg22*reg28; reg26=reg18+reg26; reg18=reg13*reg21;
    reg20=reg30+reg20; T reg39=reg11*reg21; reg24=reg22*reg24; T reg40=reg13*reg31; reg32=reg27*reg32;
    reg33=reg29*reg33; T reg41=reg6*reg29; reg39=reg37-reg39; T reg42=reg1*reg21; T reg43=reg3*reg21;
    T reg44=reg11*reg29; T reg45=reg11*reg31; T reg46=reg1*reg27; reg35=reg34+reg35; reg34=2*reg26;
    T reg47=reg16*reg21; reg20=reg30+reg20; reg28=reg28*reg21; T reg48=reg13*reg29; T reg49=2*reg38;
    T reg50=reg3*reg27; T reg51=pow(reg22,2); reg18=reg36-reg18; reg28=reg33-reg28; reg39=reg37+reg39;
    reg18=reg36+reg18; T reg52=2*reg35; reg47=reg41-reg47; reg33=reg33-reg32; reg24=reg32+reg24;
    reg45=reg42+reg45; reg32=reg11*reg27; reg20=reg30+reg20; T reg53=reg13*reg27; reg48=reg50+reg48;
    T reg54=reg38*reg49; T reg55=reg51*reg34; reg44=reg46+reg44; T reg56=reg16*reg31; reg29=reg16*reg29;
    reg21=reg6*reg21; reg40=reg43+reg40; T reg57=reg6*reg27; T reg58=reg38*reg44; reg28=reg33+reg28;
    T reg59=reg32*reg35; reg45=reg42+reg45; T reg60=reg44*reg26; T reg61=reg53*reg26; T reg62=reg51*reg49;
    reg52=reg51*reg52; T reg63=reg32*reg26; reg34=reg38*reg34; reg49=reg26*reg49; reg47=reg41+reg47;
    reg56=reg21+reg56; reg29=reg57+reg29; T reg64=reg38*reg18; reg40=reg43+reg40; T reg65=reg48*reg26;
    reg24=reg33-reg24; reg33=reg53*reg35; reg54=reg55+reg54; reg55=reg48*reg38; T reg66=reg38*reg39;
    reg27=reg16*reg27; reg20=reg30+reg20; reg59=reg60+reg59; reg30=reg3*reg31; reg63=reg58+reg63;
    T reg67=2*reg54; reg40=reg43+reg40; T reg68=reg38*reg47; T reg69=reg29*reg26; T reg70=reg64+reg65;
    reg45=reg42+reg45; T reg71=reg38*reg29; T reg72=reg27*reg26; reg49=reg34+reg49; T reg73=reg27*reg35;
    reg34=reg52+reg34; reg33=reg65+reg33; reg56=reg21+reg56; reg52=2*reg62; reg65=reg13*reg20;
    reg60=reg66+reg60; reg28=reg24+reg28; reg24=pow(reg51,2); T reg74=reg1*reg31; T reg75=reg53*reg38;
    reg61=reg55+reg61; T reg76=reg32*reg38; T reg77=reg11*reg20; reg20=reg16*reg20; T reg78=reg75*reg54;
    reg49=reg34+reg49; reg77=reg74-reg77; reg72=reg71+reg72; reg34=reg24*reg52; reg56=reg21+reg56;
    T reg79=reg26*reg39; T reg80=reg38*reg45; reg31=reg6*reg31; T reg81=reg38*reg40; T reg82=reg18*reg26;
    T reg83=reg53*reg28; reg65=reg30-reg65; T reg84=reg27*reg38; T reg85=reg32*reg28; T reg86=reg76*reg54;
    reg33=reg70+reg33; T reg87=reg61*reg62; reg59=reg60+reg59; reg52=reg62*reg52; reg67=reg24*reg67;
    T reg88=reg62*reg63; reg73=reg69+reg73; reg69=reg68+reg69; T reg89=reg44*reg35; T reg90=reg48*reg35;
    T reg91=reg63*reg54; reg83=reg90+reg83; reg65=reg30+reg65; T reg92=reg62*reg59; reg85=reg89+reg85;
    T reg93=reg79-reg80; T reg94=reg76*reg49; T reg95=reg38*reg36; reg90=reg82+reg90; T reg96=reg50*reg26;
    reg77=reg74+reg77; reg78=reg87+reg78; reg89=reg79+reg89; reg79=2*reg34; T reg97=reg29*reg35;
    reg52=reg67+reg52; reg86=reg88+reg86; reg20=reg31-reg20; reg67=reg76*reg62; T reg98=reg38*reg56;
    T reg99=reg26*reg47; reg28=reg27*reg28; reg73=reg69+reg73; T reg100=reg75*reg49; T reg101=reg46*reg26;
    T reg102=reg84*reg54; T reg103=reg62*reg33; T reg104=reg61*reg54; T reg105=reg38*reg37; T reg106=reg75*reg62;
    T reg107=pow(reg24,2); T reg108=reg62*reg72; reg82=reg82-reg81; T reg109=reg72*reg54; T reg110=reg92+reg91;
    T reg111=reg38*reg41; reg28=reg97+reg28; T reg112=reg50*reg35; T reg113=reg55*reg62; T reg114=reg62*reg73;
    T reg115=reg62*reg58; T reg116=reg55*reg54; reg94=reg91+reg94; reg97=reg99+reg97; reg91=reg82+reg90;
    reg20=reg31+reg20; T reg117=reg67*reg52; reg99=reg99-reg98; reg101=reg105+reg101; T reg118=reg34*reg86;
    T reg119=reg67*reg34; T reg120=reg62*reg70; T reg121=reg106*reg34; T reg122=pow(reg107,2); reg65=reg30+reg65;
    T reg123=reg103+reg104; T reg124=reg84*reg62; reg83=reg90+reg83; reg100=reg104+reg100; reg102=reg108+reg102;
    reg90=reg50*reg38; reg96=reg95+reg96; reg104=reg46*reg35; reg77=reg74+reg77; reg49=reg84*reg49;
    T reg125=reg36*reg26; T reg126=reg93+reg89; T reg127=reg38*reg43; T reg128=reg62*reg60; T reg129=reg78*reg34;
    T reg130=reg38*reg46; T reg131=reg26*reg37; T reg132=reg38*reg42; reg85=reg89+reg85; reg79=reg107*reg79;
    reg89=reg57*reg26; T reg133=reg106*reg52; T reg134=reg58*reg54; T reg135=reg34*reg102; T reg136=reg87*reg34;
    reg52=reg124*reg52; reg35=reg57*reg35; T reg137=pow(reg122,2); reg20=reg31+reg20; T reg138=reg130*reg54;
    T reg139=reg62*reg101; reg28=reg97+reg28; reg104=reg131+reg104; reg131=reg131-reg132; T reg140=reg121*reg79;
    T reg141=reg62*reg130; reg133=reg129+reg133; T reg142=reg62*reg71; reg100=reg123+reg100; T reg143=reg62*reg64;
    T reg144=reg38*reg57; T reg145=reg71*reg54; reg97=reg99+reg97; T reg146=reg62*reg69; T reg147=reg113*reg34;
    T reg148=reg114+reg109; reg116=reg120+reg116; reg85=reg126+reg85; T reg149=reg125-reg127; T reg150=reg34*reg115;
    reg112=reg125+reg112; reg125=reg34*reg88; reg134=reg128+reg134; reg94=reg110+reg94; T reg151=reg62*reg96;
    T reg152=reg90*reg54; reg89=reg111+reg89; reg117=reg118+reg117; reg38=reg38*reg21; T reg153=reg124*reg34;
    reg77=reg74+reg77; T reg154=reg90*reg62; T reg155=reg62*reg66; reg49=reg109+reg49; reg26=reg26*reg41;
    reg65=reg30+reg65; reg83=reg91+reg83; reg109=reg119*reg79; reg79=reg153*reg79; T reg156=reg34*reg108;
    T reg157=reg62*reg95; reg49=reg148+reg49; reg143=reg143/reg107; reg82=reg82/reg24; T reg158=reg154*reg34;
    reg112=reg149+reg112; reg152=reg151+reg152; reg52=reg135+reg52; reg150=reg150/reg122; reg134=reg134/reg107;
    reg128=reg128/reg107; reg126=reg126/reg24; reg147=reg147/reg122; reg80=reg80/reg24; reg77=reg77/reg51;
    reg155=reg155/reg107; reg93=reg93/reg24; reg83=reg83/reg24; reg103=reg103/reg107; reg123=reg123/reg107;
    reg136=reg136/reg122; T reg159=reg34*reg141; reg138=reg139+reg138; reg104=reg131+reg104; reg100=reg100/reg107;
    T reg160=reg62*reg105; reg129=reg129/reg122; reg133=reg133/reg122; reg140=reg140/reg137; reg28=reg97+reg28;
    T reg161=reg34*reg142; reg145=reg146+reg145; reg20=reg31+reg20; T reg162=reg62*reg68; reg54=reg144*reg54;
    T reg163=reg62*reg89; reg35=reg26+reg35; reg26=reg26-reg38; reg109=reg109/reg137; reg65=reg65/reg51;
    reg117=reg117/reg122; reg81=reg81/reg24; reg118=reg118/reg122; reg94=reg94/reg107; reg125=reg125/reg122;
    reg110=reg110/reg107; reg91=reg91/reg24; reg120=reg120/reg107; reg116=reg116/reg107; reg92=reg92/reg107;
    reg85=reg85/reg24; T reg164=reg62*reg144; reg62=reg62*reg111; reg158=reg158/reg122; reg132=reg132/reg24;
    reg152=reg152/reg107; reg120=reg91-reg120; reg145=reg145/reg107; reg113=reg113/reg107; reg151=reg151/reg107;
    reg161=reg161/reg122; reg112=reg112/reg24; reg70=reg70/reg24; reg40=reg40/reg51; reg109=reg117-reg109;
    reg64=reg64/reg24; reg127=reg127/reg24; reg30=reg30/reg51; reg104=reg104/reg24; reg147=reg116-reg147;
    reg157=reg157/reg107; reg139=reg139/reg107; reg146=reg146/reg107; reg97=reg97/reg24; reg140=reg133-reg140;
    reg98=reg98/reg24; reg121=reg121/reg122; reg66=reg66/reg24; reg45=reg45/reg51; reg78=reg78/reg107;
    reg60=reg60/reg24; reg115=reg115/reg107; reg81=reg65-reg81; reg59=reg59/reg24; reg88=reg88/reg107;
    reg143=reg82-reg143; reg86=reg86/reg107; reg119=reg119/reg122; reg87=reg87/reg107; reg131=reg131/reg24;
    reg160=reg160/reg107; reg33=reg33/reg24; reg74=reg74/reg51; reg128=reg126-reg128; reg125=reg110-reg125;
    reg35=reg26+reg35; reg136=reg123-reg136; reg99=reg99/reg24; reg162=reg162/reg107; reg80=reg77-reg80;
    reg118=reg94-reg118; reg155=reg93-reg155; reg92=reg85-reg92; reg129=reg100-reg129; reg20=reg20/reg51;
    reg34=reg34*reg164; reg103=reg83-reg103; reg137=reg79/reg137; reg52=reg52/reg122; reg149=reg149/reg24;
    reg138=reg138/reg107; reg159=reg159/reg122; reg28=reg28/reg24; reg114=reg114/reg107; reg148=reg148/reg107;
    reg54=reg163+reg54; reg156=reg156/reg122; reg49=reg49/reg107; reg135=reg135/reg122; reg150=reg134-reg150;
    reg98=reg20-reg98; reg54=reg54/reg107; reg35=reg35/reg24; reg34=reg34/reg122; reg121=reg78-reg121;
    reg163=reg163/reg107; reg81=reg143+reg81; reg136=reg103-reg136; reg87=reg33-reg87; reg162=reg99-reg162;
    reg95=reg95/reg24; reg43=reg43/reg51; reg113=reg70-reg113; reg38=reg38/reg24; reg96=reg96/reg24;
    reg154=reg154/reg107; reg40=reg64+reg40; reg31=reg31/reg51; reg62=reg62/reg107; reg147=reg120-reg147;
    reg161=reg145-reg161; reg109=reg118-reg109; reg127=reg30-reg127; reg157=reg149-reg157; reg139=reg104-reg139;
    reg114=reg28-reg114; reg159=reg138-reg159; reg156=reg148-reg156; reg135=reg49-reg135; reg137=reg52-reg137;
    reg80=reg155+reg80; reg125=reg92-reg125; reg122=reg153/reg122; reg102=reg102/reg107; reg68=reg68/reg24;
    reg108=reg108/reg107; reg56=reg56/reg51; reg73=reg73/reg24; reg69=reg69/reg24; reg142=reg142/reg107;
    reg150=reg128-reg150; reg26=reg26/reg24; reg141=reg141/reg107; reg101=reg101/reg24; reg45=reg66+reg45;
    reg115=reg60-reg115; reg140=reg129-reg140; reg42=reg42/reg51; reg88=reg59-reg88; reg105=reg105/reg24;
    reg119=reg86-reg119; reg160=reg131-reg160; reg158=reg152-reg158; reg132=reg74-reg132; reg146=reg97-reg146;
    reg151=reg112-reg151; reg150=reg80+reg150; reg58=reg58/reg24; reg63=reg63/reg24; reg67=reg67/reg107;
    reg140=reg136-reg140; reg18=reg18/reg51; reg38=reg31-reg38; reg55=reg55/reg24; reg61=reg61/reg24;
    reg106=reg106/reg107; reg159=reg139-reg159; reg39=reg39/reg51; reg62=reg26-reg62; reg132=reg160+reg132;
    reg109=reg125-reg109; reg113=reg40+reg113; reg121=reg87-reg121; reg98=reg162+reg98; reg42=reg105+reg42;
    reg141=reg101-reg141; reg115=reg45+reg115; reg119=reg88-reg119; reg158=reg151-reg158; reg161=reg146-reg161;
    reg127=reg157+reg127; reg111=reg111/reg24; reg21=reg21/reg51; reg89=reg89/reg24; reg164=reg164/reg107;
    reg156=reg114-reg156; reg137=reg135-reg137; reg122=reg102-reg122; reg108=reg73-reg108; reg56=reg68+reg56;
    reg142=reg69-reg142; reg163=reg35-reg163; reg34=reg54-reg34; reg43=reg95+reg43; reg154=reg96-reg154;
    reg147=reg81+reg147; reg119=reg115+reg119; reg158=reg127+reg158; reg109=reg150+reg109; reg47=reg47/reg51;
    reg161=reg98+reg161; reg71=reg71/reg24; reg72=reg72/reg24; reg21=reg111+reg21; reg107=reg124/reg107;
    reg106=reg61-reg106; reg159=reg132+reg159; reg38=reg62+reg38; reg137=reg156-reg137; reg55=reg18-reg55;
    reg90=reg90/reg24; reg36=reg36/reg51; reg122=reg108-reg122; reg164=reg89-reg164; reg34=reg163-reg34;
    reg154=reg43+reg154; reg142=reg56+reg142; reg67=reg63-reg67; reg121=reg113+reg121; reg58=reg39-reg58;
    reg140=reg147+reg140; reg141=reg42+reg141; reg37=reg37/reg51; reg130=reg130/reg24; reg164=reg21+reg164;
    reg76=reg76/reg24; reg44=reg44/reg51; reg121=reg154+reg121; reg34=reg38+reg34; reg122=reg142+reg122;
    reg75=reg75/reg24; reg48=reg48/reg51; reg90=reg36-reg90; reg137=reg161+reg137; reg140=reg158+reg140;
    reg119=reg141+reg119; reg67=reg58-reg67; reg130=reg37-reg130; reg41=reg41/reg51; reg71=reg47-reg71;
    reg109=reg159+reg109; reg106=reg55-reg106; reg107=reg72-reg107; reg144=reg144/reg24; reg76=reg44-reg76;
    reg107=reg71-reg107; reg18=reg3*reg121; reg46=reg46/reg51; reg20=reg1*reg119; reg140=reg13*reg140;
    reg67=reg130+reg67; reg50=reg50/reg51; reg122=reg164+reg122; reg75=reg48-reg75; reg24=reg84/reg24;
    reg109=reg11*reg109; reg106=reg90+reg106; reg29=reg29/reg51; reg144=reg41-reg144; reg137=reg34+reg137;
    reg76=reg46+reg76; reg57=reg57/reg51; reg75=reg50+reg75; reg21=reg1/reg22; reg32=reg32/reg51;
    reg137=reg16*reg137; reg26=reg6*reg122; reg109=reg20+reg109; reg28=reg3/reg22; reg53=reg53/reg51;
    reg24=reg29-reg24; reg121=reg13*reg121; reg29=reg3*reg106; reg30=reg1*reg67; reg119=reg11*reg119;
    reg140=reg18+reg140; reg107=reg144+reg107; reg31=reg3*reg75; reg106=reg13*reg106; reg33=reg1*reg76;
    reg109=reg20+reg109; reg140=reg18+reg140; reg67=reg11*reg67; reg34=reg6*reg107; reg119=reg30-reg119;
    reg51=reg27/reg51; reg27=reg6/reg22; reg53=reg28-reg53; reg32=reg21-reg32; reg121=reg29-reg121;
    reg24=reg57+reg24; reg137=reg26+reg137; reg122=reg16*reg122; reg137=reg26+reg137; reg21=reg11/reg22;
    reg28=reg1*reg32; reg107=reg16*reg107; reg122=reg34-reg122; reg35=reg13/reg22; reg109=reg20+reg109;
    reg121=reg29+reg121; reg140=reg18+reg140; reg76=reg11*reg76; reg67=reg33+reg67; reg51=reg27-reg51;
    reg27=reg6*reg24; reg119=reg30+reg119; reg106=reg31+reg106; reg36=reg3*reg53; reg75=reg13*reg75;
    reg53=reg13*reg53; reg121=reg29+reg121; reg107=reg27+reg107; reg76=reg28-reg76; reg24=reg16*reg24;
    reg119=reg30+reg119; reg137=reg26+reg137; reg122=reg34+reg122; reg106=reg31+reg106; reg75=reg36-reg75;
    reg37=reg6*reg51; reg140=reg18+reg140; reg109=reg20+reg109; reg32=reg11*reg32; reg38=reg21*reg1;
    reg67=reg33+reg67; reg22=reg16/reg22; reg39=reg35*reg3; reg76=reg28+reg76; reg39=reg53+reg39;
    reg38=reg32+reg38; reg121=reg29+reg121; reg122=reg34+reg122; reg24=reg37-reg24; reg106=reg31+reg106;
    reg140=reg18+reg140; reg75=reg36+reg75; reg109=reg20+reg109; reg35=reg13*reg35; reg21=reg11*reg21;
    reg67=reg33+reg67; reg18=reg22*reg6; reg51=reg16*reg51; reg107=reg27+reg107; reg119=reg30+reg119;
    reg137=reg26+reg137; reg22=reg16*reg22; reg122=reg34+reg122; reg21=reg35+reg21; reg119=reg121+reg119;
    reg137=reg26+reg137; reg76=reg75+reg76; reg67=reg106+reg67; reg38=reg39+reg38; reg18=reg51+reg18;
    reg107=reg27+reg107; reg24=reg37+reg24; reg109=reg140+reg109; reg137=reg109+reg137; reg18=reg38+reg18;
    reg22=reg21+reg22; reg107=reg67+reg107; reg24=reg76+reg24; reg122=reg119+reg122; reg20=elem.pos(0)[0]*reg24;
    reg21=reg13*reg18; reg26=reg22*reg3; reg27=reg1*reg107; reg28=elem.pos(0)[0]*reg122; reg29=reg11*reg24;
    reg30=elem.pos(0)[1]*reg107; reg31=reg1*reg18; reg32=elem.pos(0)[0]*reg137; reg33=elem.pos(0)[2]*reg122; reg34=reg16*reg107;
    reg35=reg6*reg24; reg36=reg22*reg1; reg37=reg11*reg18; reg38=reg6*reg18; reg39=elem.pos(0)[2]*reg107;
    reg40=reg16*reg24; reg41=elem.pos(0)[1]*reg24; reg42=reg22*reg6; reg43=reg16*reg18; reg44=elem.pos(0)[2]*reg24;
    reg45=reg11*reg122; reg46=elem.pos(0)[1]*reg137; reg47=reg13*reg122; reg48=elem.pos(0)[0]*reg107; reg49=reg1*reg24;
    reg50=reg6*reg107; reg51=reg13*reg107; reg52=reg3*reg18; reg53=reg16*reg122; reg54=reg11*reg107;
    reg55=reg3*reg107; reg56=reg13*reg24; reg57=reg3*reg24; reg58=elem.pos(0)[2]*reg137; reg59=elem.pos(0)[1]*reg122;
    reg59=reg54+reg59; reg60=reg56+reg52; reg39=reg40-reg39; reg40=reg40+reg38; reg48=reg56-reg48;
    reg42=reg43+reg42; reg43=reg44+reg43; reg11=reg11*reg22; reg16=reg16*reg22; reg44=elem.pos(0)[2]*reg18;
    reg56=elem.pos(0)[1]*reg18; reg61=reg27+reg45; reg46=reg45-reg46; reg45=reg57-reg51; reg62=reg29+reg31;
    reg30=reg29-reg30; reg28=reg51+reg28; reg33=reg34+reg33; reg29=reg50+reg53; reg26=reg21+reg26;
    reg21=reg20+reg21; reg58=reg53-reg58; reg20=reg55+reg47; reg13=reg13*reg22; reg32=reg47-reg32;
    reg36=reg37+reg36; reg34=reg35-reg34; reg47=elem.pos(0)[0]*reg18; reg54=reg49-reg54; reg37=reg41+reg37;
    reg11=reg56+reg11; reg59=reg54-reg59; reg54=reg49+reg54; reg36=reg37+reg36; reg31=reg31+reg62;
    reg62=reg30+reg62; reg30=reg27+reg61; reg52=reg52+reg60; reg60=reg48+reg60; reg58=reg29+reg58;
    reg37=reg55+reg20; reg13=reg47+reg13; reg29=reg50+reg29; reg41=reg57+reg45; reg28=reg45-reg28;
    reg45=reg35+reg34; reg33=reg34-reg33; reg26=reg21+reg26; reg32=reg20+reg32; reg38=reg38+reg40;
    reg40=reg39+reg40; reg46=reg61+reg46; reg42=reg43+reg42; reg16=reg44+reg16; reg58=reg29+reg58;
    reg29=reg50+reg29; reg46=reg30+reg46; reg30=reg27+reg30; reg11=reg11/2; reg59=reg59+reg54;
    reg54=reg49+reg54; reg35=reg35+reg45; reg45=reg33+reg45; reg42=0.5*reg42; reg38=reg40+reg38;
    reg16=reg16/2; reg57=reg57+reg41; reg20=elem.pos(0)[0]*reg22; reg24=0.5*reg24; reg41=reg28+reg41;
    reg18=reg18/2; reg52=reg60+reg52; reg21=elem.pos(0)[2]*reg22; reg32=reg37+reg32; reg37=reg55+reg37;
    reg26=0.5*reg26; reg28=elem.pos(0)[1]*reg22; reg36=0.5*reg36; reg31=reg62+reg31; reg13=reg13/2;
    reg32=reg32+reg37; reg33=0.16666666666666666667*reg107; reg37=reg55+reg37; reg38=0.16666666666666666667*reg38; reg26=reg26/3;
    reg35=reg45+reg35; reg13=reg20+reg13; reg31=0.16666666666666666667*reg31; reg54=reg59+reg54; reg42=reg42/3;
    reg16=reg21+reg16; reg50=reg50+reg29; reg24=reg24/3; reg46=reg46+reg30; reg30=reg27+reg30;
    reg29=reg58+reg29; reg52=0.16666666666666666667*reg52; reg18=reg22+reg18; reg11=reg28+reg11; reg36=reg36/3;
    reg57=reg41+reg57; reg50=reg29+reg50; reg35=0.041666666666666666668*reg35; reg42=reg16+reg42; reg37=reg32+reg37;
    reg38=reg38/4; reg57=0.041666666666666666668*reg57; reg26=reg13+reg26; reg52=reg52/4; reg54=0.041666666666666666668*reg54;
    reg33=reg33/4; reg24=reg18+reg24; reg13=0.041666666666666666668*reg122; reg30=reg46+reg30; reg36=reg11+reg36;
    reg31=reg31/4; reg35=reg35/5; reg38=reg42+reg38; reg33=reg24-reg33; reg11=0.0083333333333333333337*reg50;
    reg16=0.0083333333333333333337*reg30; reg31=reg36+reg31; reg54=reg54/5; reg13=reg13/5; reg18=0.0083333333333333333337*reg37;
    reg52=reg26+reg52; reg57=reg57/5; reg137=0.0083333333333333333337*reg137; reg11=reg11/6; reg35=reg38+reg35;
    reg13=reg33-reg13; reg137=reg137/6; reg57=reg52+reg57; reg18=reg18/6; reg16=reg16/6;
    reg54=reg31+reg54; reg18=reg57-reg18; reg13=reg137+reg13; reg16=reg54-reg16; reg11=reg35-reg11;
    res[0]=reg18/reg13; res[2]=reg11/reg13; res[1]=reg16/reg13;

    return res;
}
}
#endif // LMT_BAR_3
