#ifndef LMT_QUAD_42
#define LMT_QUAD_42
#include "node.h"
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Quad_42 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 28, 56, 84, 112, 140, 168, 196, 224, 252, }; // fonction de lordre du poly
    static const double values[] = {
        0.197530864198,0.5,0.5,
        0.123456790123,0.112701665379,0.5,
        0.123456790123,0.887298334621,0.5,
        0.123456790123,0.5,0.112701665379,
        0.0771604938272,0.112701665379,0.112701665379,
        0.0771604938272,0.887298334621,0.112701665379,
        0.123456790123,0.5,0.887298334621,
        0.0771604938272,0.112701665379,0.887298334621,
        0.0771604938272,0.887298334621,0.887298334621,
        0.0,
        0.197530864198,0.5,0.5,
        0.123456790123,0.112701665379,0.5,
        0.123456790123,0.887298334621,0.5,
        0.123456790123,0.5,0.112701665379,
        0.0771604938272,0.112701665379,0.112701665379,
        0.0771604938272,0.887298334621,0.112701665379,
        0.123456790123,0.5,0.887298334621,
        0.0771604938272,0.112701665379,0.887298334621,
        0.0771604938272,0.887298334621,0.887298334621,
        0.0,
        0.197530864198,0.5,0.5,
        0.123456790123,0.112701665379,0.5,
        0.123456790123,0.887298334621,0.5,
        0.123456790123,0.5,0.112701665379,
        0.0771604938272,0.112701665379,0.112701665379,
        0.0771604938272,0.887298334621,0.112701665379,
        0.123456790123,0.5,0.887298334621,
        0.0771604938272,0.112701665379,0.887298334621,
        0.0771604938272,0.887298334621,0.887298334621,
        0.0,
        0.197530864198,0.5,0.5,
        0.123456790123,0.112701665379,0.5,
        0.123456790123,0.887298334621,0.5,
        0.123456790123,0.5,0.112701665379,
        0.0771604938272,0.112701665379,0.112701665379,
        0.0771604938272,0.887298334621,0.112701665379,
        0.123456790123,0.5,0.887298334621,
        0.0771604938272,0.112701665379,0.887298334621,
        0.0771604938272,0.887298334621,0.887298334621,
        0.0,
        0.197530864198,0.5,0.5,
        0.123456790123,0.112701665379,0.5,
        0.123456790123,0.887298334621,0.5,
        0.123456790123,0.5,0.112701665379,
        0.0771604938272,0.112701665379,0.112701665379,
        0.0771604938272,0.887298334621,0.112701665379,
        0.123456790123,0.5,0.887298334621,
        0.0771604938272,0.112701665379,0.887298334621,
        0.0771604938272,0.887298334621,0.887298334621,
        0.0,
        0.197530864198,0.5,0.5,
        0.123456790123,0.112701665379,0.5,
        0.123456790123,0.887298334621,0.5,
        0.123456790123,0.5,0.112701665379,
        0.0771604938272,0.112701665379,0.112701665379,
        0.0771604938272,0.887298334621,0.112701665379,
        0.123456790123,0.5,0.887298334621,
        0.0771604938272,0.112701665379,0.887298334621,
        0.0771604938272,0.887298334621,0.887298334621,
        0.0,
        0.197530864198,0.5,0.5,
        0.123456790123,0.112701665379,0.5,
        0.123456790123,0.887298334621,0.5,
        0.123456790123,0.5,0.112701665379,
        0.0771604938272,0.112701665379,0.112701665379,
        0.0771604938272,0.887298334621,0.112701665379,
        0.123456790123,0.5,0.887298334621,
        0.0771604938272,0.112701665379,0.887298334621,
        0.0771604938272,0.887298334621,0.887298334621,
        0.0,
        0.197530864198,0.5,0.5,
        0.123456790123,0.112701665379,0.5,
        0.123456790123,0.887298334621,0.5,
        0.123456790123,0.5,0.112701665379,
        0.0771604938272,0.112701665379,0.112701665379,
        0.0771604938272,0.887298334621,0.112701665379,
        0.123456790123,0.5,0.887298334621,
        0.0771604938272,0.112701665379,0.887298334621,
        0.0771604938272,0.887298334621,0.887298334621,
        0.0,
        0.197530864198,0.5,0.5,
        0.123456790123,0.112701665379,0.5,
        0.123456790123,0.887298334621,0.5,
        0.123456790123,0.5,0.112701665379,
        0.0771604938272,0.112701665379,0.112701665379,
        0.0771604938272,0.887298334621,0.112701665379,
        0.123456790123,0.5,0.887298334621,
        0.0771604938272,0.112701665379,0.887298334621,
        0.0771604938272,0.887298334621,0.887298334621,
        0.0,
        0.197530864198,0.5,0.5,
        0.123456790123,0.112701665379,0.5,
        0.123456790123,0.887298334621,0.5,
        0.123456790123,0.5,0.112701665379,
        0.0771604938272,0.112701665379,0.112701665379,
        0.0771604938272,0.887298334621,0.112701665379,
        0.123456790123,0.5,0.887298334621,
        0.0771604938272,0.112701665379,0.887298334621,
        0.0771604938272,0.887298334621,0.887298334621,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Quad_42 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=0.062499999999999993061*nodes[0]->pos[1]; T reg1=0.5624999999999998751*nodes[4]->pos[1]; T reg2=1.6875*nodes[4]->pos[1]; T reg3=0.062500000000000055511*nodes[0]->pos[0]; T reg4=1.6875*nodes[4]->pos[0];
    T reg5=0.062500000000000055511*nodes[0]->pos[1]; T reg6=0.062499999999999993061*nodes[0]->pos[0]; T reg7=0.5624999999999998751*nodes[4]->pos[0]; reg7=reg7-reg6; reg1=reg1-reg0;
    T reg8=1.6875*nodes[5]->pos[0]; T reg9=reg3-reg4; T reg10=0.56250000000000006245*nodes[5]->pos[0]; T reg11=reg5-reg2; T reg12=1.6875*nodes[5]->pos[1];
    T reg13=0.56250000000000006245*nodes[5]->pos[1]; reg7=reg10+reg7; T reg14=0.062499999999999993061*nodes[1]->pos[0]; reg1=reg13+reg1; T reg15=0.062499999999999993061*nodes[1]->pos[1];
    reg11=reg11+reg12; T reg16=0.062499999999999930604*nodes[1]->pos[1]; T reg17=0.062499999999999930604*nodes[1]->pos[0]; reg9=reg9+reg8; T reg18=0.062500000000000055511*nodes[3]->pos[1];
    reg11=reg11-reg16; T reg19=0.062499999999999993061*nodes[3]->pos[0]; T reg20=reg14-reg7; T reg21=reg15-reg1; T reg22=0.062499999999999993061*nodes[3]->pos[1];
    T reg23=0.062500000000000055511*nodes[3]->pos[0]; reg9=reg9-reg17; reg21=reg21-reg22; T reg24=0.5624999999999998751*nodes[7]->pos[1]; reg11=reg11+reg18;
    T reg25=1.6875*nodes[7]->pos[1]; reg9=reg9+reg23; T reg26=1.6875*nodes[7]->pos[0]; reg20=reg20-reg19; T reg27=0.5624999999999998751*nodes[7]->pos[0];
    T reg28=0.56250000000000006245*nodes[6]->pos[0]; reg27=reg20+reg27; reg20=1.6875*nodes[6]->pos[1]; reg11=reg11-reg25; T reg29=0.56250000000000006245*nodes[6]->pos[1];
    reg24=reg21+reg24; reg9=reg9-reg26; reg21=1.6875*nodes[6]->pos[0]; reg11=reg11+reg20; T reg30=0.062499999999999930604*nodes[2]->pos[1];
    reg27=reg27+reg28; T reg31=0.062499999999999993061*nodes[2]->pos[0]; T reg32=0.062499999999999993061*nodes[2]->pos[1]; reg24=reg24+reg29; reg9=reg9+reg21;
    T reg33=0.062499999999999930604*nodes[2]->pos[0]; reg27=reg27-reg31; reg11=reg11-reg30; reg24=reg24-reg32; reg9=reg9-reg33;
    reg24=reg9*reg24; reg27=reg11*reg27; T det_jac=reg24-reg27;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[3],nodes[2],nodes[1],nodes[0],nodes[7],nodes[6],nodes[5],nodes[4]};
        for(unsigned i=0;i<8;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Quad_42 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=reg0+reg1; T reg3=reg1-var_inter[0]; T reg4=1-var_inter[0];
    T reg5=reg4*reg2; reg3=reg4*reg3; T reg6=reg1*var_inter[0]; T reg7=reg0-var_inter[0]; T reg8=reg0*reg1;
    reg5=reg8+reg5; reg0=reg0*var_inter[0]; reg3=reg3-reg6; T reg9=reg4*reg7; reg6=reg4*reg6;
    reg7=reg1*reg7; T reg10=4.5*reg5; T reg11=1-var_inter[1]; reg9=reg9-reg0; reg8=reg4*reg8;
    reg3=13.5*reg3; reg4=reg4*reg0; reg6=13.5*reg6; reg8=4.5*reg8; T reg12=reg11*reg10;
    T reg13=reg11*reg3; reg9=13.5*reg9; reg7=reg7-reg0; T reg14=pos_nodes[4][1]*reg13; T reg15=pos_nodes[4][1]*reg6;
    T reg16=pos_nodes[0][1]*reg12; T reg17=pos_nodes[4][0]*reg6; T reg18=pos_nodes[0][0]*reg8; T reg19=pos_nodes[0][0]*reg12; T reg20=pos_nodes[0][1]*reg8;
    T reg21=reg11*reg9; reg7=4.5*reg7; T reg22=pos_nodes[4][0]*reg13; reg0=reg1*reg0; reg4=13.5*reg4;
    reg19=reg22-reg19; reg1=pos_nodes[5][0]*reg21; reg15=reg20+reg15; reg20=reg11*reg7; reg22=pos_nodes[5][1]*reg4;
    T reg23=reg11*reg8; T reg24=reg11*reg6; T reg25=pos_nodes[5][0]*reg4; reg17=reg18+reg17; reg0=4.5*reg0;
    reg16=reg14-reg16; reg14=pos_nodes[5][1]*reg21; reg18=pos_nodes[1][1]*reg0; reg15=reg22-reg15; reg22=pos_nodes[1][0]*reg0;
    reg17=reg25-reg17; reg25=pos_nodes[0][0]*reg23; T reg26=pos_nodes[1][0]*reg20; reg1=reg19-reg1; reg14=reg16-reg14;
    reg16=pos_nodes[1][1]*reg20; reg19=reg11*reg4; T reg27=pos_nodes[4][1]*reg24; T reg28=var_inter[1]*reg10; T reg29=pos_nodes[0][1]*reg23;
    T reg30=pos_nodes[4][0]*reg24; T reg31=pos_nodes[3][1]*reg28; reg18=reg15-reg18; reg15=pos_nodes[3][0]*reg8; reg22=reg17-reg22;
    reg16=reg14+reg16; reg14=pos_nodes[5][0]*reg19; reg30=reg25+reg30; reg17=pos_nodes[3][1]*reg8; reg25=pos_nodes[5][1]*reg19;
    reg11=reg11*reg0; reg27=reg29+reg27; reg29=pos_nodes[3][0]*reg28; reg26=reg1+reg26; reg3=var_inter[1]*reg3;
    reg1=pos_nodes[1][1]*reg11; reg25=reg27-reg25; reg27=var_inter[1]*reg8; reg31=reg16-reg31; reg16=pos_nodes[7][1]*reg3;
    T reg32=pos_nodes[1][0]*reg11; reg14=reg30-reg14; reg9=var_inter[1]*reg9; reg29=reg26-reg29; reg26=pos_nodes[7][0]*reg3;
    reg30=pos_nodes[7][0]*reg6; reg15=reg22+reg15; reg22=pos_nodes[7][1]*reg6; reg17=reg18+reg17; reg18=pos_nodes[6][1]*reg9;
    reg16=reg31+reg16; reg31=pos_nodes[6][1]*reg4; reg22=reg17+reg22; reg1=reg25+reg1; reg17=pos_nodes[3][1]*reg27;
    reg25=var_inter[1]*reg6; reg7=var_inter[1]*reg7; reg26=reg29+reg26; reg29=pos_nodes[6][0]*reg9; T reg33=pos_nodes[3][0]*reg27;
    reg32=reg14+reg32; reg30=reg15+reg30; reg14=pos_nodes[6][0]*reg4; reg15=var_inter[1]*reg4; T reg34=pos_nodes[2][1]*reg0;
    reg31=reg22-reg31; reg29=reg26-reg29; reg22=pos_nodes[2][0]*reg7; reg14=reg30-reg14; reg26=pos_nodes[2][0]*reg0;
    reg17=reg1+reg17; reg1=pos_nodes[7][1]*reg25; reg30=pos_nodes[2][1]*reg7; reg18=reg16-reg18; reg33=reg32+reg33;
    reg16=pos_nodes[7][0]*reg25; reg32=var_inter[1]*reg0; reg1=reg17+reg1; reg17=pos_nodes[6][1]*reg15; T reg35=pos_nodes[6][0]*reg15;
    reg34=reg31+reg34; reg16=reg33+reg16; reg30=reg18+reg30; reg22=reg29+reg22; reg26=reg14+reg26;
    reg17=reg1-reg17; reg1=pos_nodes[2][1]*reg32; reg14=reg22*reg34; reg18=pos_nodes[2][0]*reg32; reg35=reg16-reg35;
    reg16=reg26*reg30; reg1=reg17+reg1; reg16=reg14-reg16; reg18=reg35+reg18; reg18=pos[0]-reg18;
    reg1=pos[1]-reg1; reg17=reg34/reg16; reg29=reg30/reg16; reg31=reg26/reg16; reg16=reg22/reg16;
    reg17=reg18*reg17; reg31=reg1*reg31; reg29=reg18*reg29; reg16=reg1*reg16; var_inter[0]=reg17-reg31;
    var_inter[1]=reg16-reg29;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Quad_42 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=reg1+reg0; T reg3=reg1-var_inter[0]; T reg4=1-var_inter[0];
    T reg5=reg4*reg2; reg3=reg4*reg3; T reg6=reg0-var_inter[0]; T reg7=reg1*reg0; T reg8=reg1*var_inter[0];
    reg0=reg0*var_inter[0]; reg5=reg7+reg5; T reg9=reg4*reg6; reg3=reg3-reg8; reg7=reg7*reg4;
    reg8=reg8*reg4; reg9=reg9-reg0; reg3=13.5*reg3; reg6=reg1*reg6; T reg10=1-var_inter[1];
    T reg11=4.5*reg5; T reg12=reg10*reg11; T reg13=reg10*reg3; reg9=13.5*reg9; reg7=4.5*reg7;
    reg6=reg6-reg0; reg4=reg0*reg4; reg8=13.5*reg8; T reg14=pos_nodes[4][1]*reg13; T reg15=reg8*pos_nodes[4][0];
    T reg16=pos_nodes[0][1]*reg12; T reg17=reg7*pos_nodes[0][0]; T reg18=reg10*reg9; T reg19=reg7*pos_nodes[0][1]; T reg20=reg8*pos_nodes[4][1];
    reg6=4.5*reg6; T reg21=pos_nodes[4][0]*reg13; T reg22=pos_nodes[0][0]*reg12; reg4=13.5*reg4; reg1=reg0*reg1;
    reg0=pos_nodes[5][0]*reg18; reg22=reg21-reg22; reg21=reg10*reg7; T reg23=reg10*reg6; T reg24=reg8*reg10;
    reg16=reg14-reg16; reg20=reg19+reg20; reg14=reg4*pos_nodes[5][0]; reg1=4.5*reg1; reg19=reg4*pos_nodes[5][1];
    reg15=reg17+reg15; reg17=pos_nodes[5][1]*reg18; T reg25=reg21*pos_nodes[0][1]; T reg26=reg24*pos_nodes[4][1]; T reg27=pos_nodes[1][1]*reg1;
    reg20=reg19-reg20; reg19=pos_nodes[1][0]*reg23; T reg28=pos_nodes[1][0]*reg1; reg15=reg14-reg15; reg0=reg22-reg0;
    reg14=reg21*pos_nodes[0][0]; reg22=reg24*pos_nodes[4][0]; T reg29=var_inter[1]*reg11; T reg30=reg4*reg10; T reg31=pos_nodes[1][1]*reg23;
    reg17=reg16-reg17; reg22=reg14+reg22; reg27=reg20-reg27; reg14=pos_nodes[3][1]*reg7; reg16=pos_nodes[3][0]*reg7;
    reg28=reg15-reg28; reg15=reg30*pos_nodes[5][0]; reg31=reg17+reg31; reg17=pos_nodes[3][1]*reg29; reg26=reg25+reg26;
    reg20=reg30*pos_nodes[5][1]; reg25=pos_nodes[3][0]*reg29; reg19=reg0+reg19; reg3=var_inter[1]*reg3; reg10=reg10*reg1;
    reg17=reg31-reg17; reg0=pos_nodes[7][1]*reg3; reg31=reg10*pos_nodes[1][1]; T reg32=reg7*var_inter[1]; T reg33=reg10*pos_nodes[1][0];
    reg15=reg22-reg15; reg9=var_inter[1]*reg9; reg20=reg26-reg20; reg25=reg19-reg25; reg19=pos_nodes[7][0]*reg3;
    reg14=reg27+reg14; reg22=reg8*pos_nodes[7][0]; reg16=reg28+reg16; reg26=reg8*pos_nodes[7][1]; reg0=reg17+reg0;
    reg17=pos_nodes[6][1]*reg9; reg26=reg14+reg26; reg14=reg4*pos_nodes[6][1]; reg31=reg20+reg31; reg20=pos_nodes[3][1]*reg32;
    reg27=reg8*var_inter[1]; reg6=var_inter[1]*reg6; reg19=reg25+reg19; reg25=pos_nodes[6][0]*reg9; reg22=reg16+reg22;
    reg16=reg4*pos_nodes[6][0]; reg28=pos_nodes[3][0]*reg32; reg33=reg15+reg33; reg25=reg19-reg25; reg15=pos_nodes[2][0]*reg6;
    reg19=pos_nodes[2][1]*reg1; reg14=reg26-reg14; reg26=reg4*var_inter[1]; reg16=reg22-reg16; reg22=pos_nodes[2][0]*reg1;
    reg20=reg31+reg20; reg28=reg33+reg28; reg31=reg27*pos_nodes[7][0]; reg33=reg27*pos_nodes[7][1]; T reg34=pos_nodes[2][1]*reg6;
    reg17=reg0-reg17; reg33=reg20+reg33; reg0=reg26*pos_nodes[6][1]; reg20=reg26*pos_nodes[6][0]; reg31=reg28+reg31;
    reg19=reg14+reg19; reg15=reg25+reg15; reg14=var_inter[1]*reg1; reg34=reg17+reg34; reg22=reg16+reg22;
    reg0=reg33-reg0; reg16=pos_nodes[2][1]*reg14; reg17=reg15*reg19; reg25=reg14*pos_nodes[2][0]; reg20=reg31-reg20;
    reg28=reg22*reg34; reg16=reg0+reg16; reg28=reg17-reg28; reg25=reg20+reg25; reg25=pos[0]-reg25;
    reg16=pos[1]-reg16; reg0=reg19/reg28; reg20=reg34/reg28; reg31=reg22/reg28; reg28=reg15/reg28;
    reg0=reg25*reg0; reg31=reg16*reg31; reg20=reg25*reg20; reg28=reg16*reg28; var_inter[0]+=reg0-reg31;
    var_inter[1]+=reg28-reg20;

}
template<> struct ElemVarInterFromPosNonLinear<Quad_42> { static const bool res = 2; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Quad_42 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Quad_42 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_42 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=0.66666666666666662966-var_inter[0]; T reg1=0.33333333333333331483-var_inter[0]; T reg2=1-var_inter[0]; T reg3=var_inter[0]*reg0; T reg4=reg1*reg0;
    reg4=reg2*reg4; reg3=reg2*reg3; reg1=var_inter[0]*reg1; reg4=4.5*reg4; reg3=13.5*reg3;
    reg2=reg2*reg1; T reg5=1-var_inter[1]; reg2=13.5*reg2; reg1=reg0*reg1; reg0=reg4*reg5;
    T reg6=reg3*reg5; reg0=val[0]*reg0; reg6=val[4]*reg6; T reg7=reg2*reg5; reg1=4.5*reg1;
    reg7=val[5]*reg7; reg5=reg1*reg5; reg6=reg0+reg6; reg7=reg6-reg7; reg5=val[1]*reg5;
    reg4=var_inter[1]*reg4; reg4=val[3]*reg4; reg3=var_inter[1]*reg3; reg5=reg7+reg5; reg3=val[7]*reg3;
    reg0=var_inter[1]*reg2; reg4=reg5+reg4; reg3=reg4+reg3; reg0=val[6]*reg0; reg1=reg1*var_inter[1];
    reg0=reg3-reg0; reg1=val[2]*reg1; res=reg0+reg1;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Quad_42 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Quad_42 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Quad_42 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Quad_42 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_42 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Quad_42 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Quad_42 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=var_inter[0]*reg0; T reg2=1-var_inter[0]; T reg3=0.66666666666666662966-var_inter[0]; T reg4=reg2*reg1;
    T reg5=var_inter[0]*reg3; reg0=reg0*reg3; T reg6=1-var_inter[1]; reg4=13.5*reg4; reg1=reg3*reg1;
    reg5=reg2*reg5; reg0=reg2*reg0; reg5=13.5*reg5; reg1=4.5*reg1; reg0=4.5*reg0;
    reg2=reg4*reg6; reg3=var_inter[1]*reg4; T reg7=reg0*reg6; res[0]=reg7; T reg8=reg5*reg6;
    res[4]=reg8; reg6=reg1*reg6; res[1]=reg6; reg0=var_inter[1]*reg0; res[3]=reg0;
    reg5=var_inter[1]*reg5; res[7]=reg5; reg1=reg1*var_inter[1]; res[2]=reg1; res[5]=-reg2;
    res[6]=-reg3;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Quad_42> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Quad_42,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=0.33333333333333331483-var_inter[0]; T reg1=0.66666666666666662966-var_inter[0]; T reg2=reg0+reg1; T reg3=reg1-var_inter[0]; T reg4=1-var_inter[0];
    T reg5=reg4*reg2; T reg6=reg0-var_inter[0]; reg3=reg4*reg3; T reg7=var_inter[0]*reg1; T reg8=reg0*reg1;
    reg5=reg8+reg5; reg0=var_inter[0]*reg0; reg3=reg3-reg7; T reg9=reg4*reg6; T reg10=1-var_inter[1];
    reg6=reg1*reg6; reg9=reg9-reg0; T reg11=4.5*reg5; reg3=13.5*reg3; reg6=reg6-reg0;
    T reg12=reg10*reg3; T reg13=reg10*reg11; reg9=13.5*reg9; T reg14=reg10*reg9; T reg15=elem.pos(0)[0]*reg13;
    T reg16=elem.pos(4)[0]*reg12; reg6=4.5*reg6; T reg17=elem.pos(4)[1]*reg12; T reg18=elem.pos(0)[1]*reg13; T reg19=elem.pos(5)[0]*reg14;
    reg12=elem.pos(4)[2]*reg12; reg17=reg17-reg18; reg16=reg16-reg15; T reg20=reg10*reg6; T reg21=elem.pos(0)[2]*reg13;
    T reg22=elem.pos(5)[1]*reg14; T reg23=elem.pos(1)[1]*reg20; T reg24=elem.pos(1)[0]*reg20; reg14=elem.pos(5)[2]*reg14; reg19=reg16-reg19;
    reg12=reg12-reg21; reg22=reg17-reg22; reg16=var_inter[1]*reg11; reg20=elem.pos(1)[2]*reg20; reg19=reg24+reg19;
    reg23=reg22+reg23; reg8=reg4*reg8; reg7=reg4*reg7; reg3=var_inter[1]*reg3; reg17=elem.pos(3)[0]*reg16;
    reg14=reg12-reg14; reg12=elem.pos(3)[1]*reg16; reg8=4.5*reg8; reg4=reg4*reg0; reg19=reg19-reg17;
    reg23=reg23-reg12; reg22=elem.pos(7)[1]*reg3; reg20=reg14+reg20; reg14=elem.pos(3)[2]*reg16; reg24=elem.pos(7)[0]*reg3;
    reg9=var_inter[1]*reg9; reg7=13.5*reg7; T reg25=elem.pos(4)[1]*reg7; reg20=reg20-reg14; reg0=reg1*reg0;
    reg3=elem.pos(7)[2]*reg3; reg1=elem.pos(6)[0]*reg9; T reg26=elem.pos(0)[1]*reg8; reg6=var_inter[1]*reg6; T reg27=elem.pos(4)[0]*reg7;
    T reg28=elem.pos(0)[0]*reg8; reg24=reg19+reg24; reg19=elem.pos(6)[1]*reg9; reg22=reg23+reg22; reg4=13.5*reg4;
    reg23=reg27+reg28; T reg29=elem.pos(0)[2]*reg8; reg0=4.5*reg0; reg19=reg22-reg19; reg22=elem.pos(5)[1]*reg4;
    T reg30=reg26+reg25; T reg31=elem.pos(2)[0]*reg6; reg1=reg24-reg1; reg24=elem.pos(4)[2]*reg7; reg9=elem.pos(6)[2]*reg9;
    reg3=reg20+reg3; reg20=elem.pos(2)[1]*reg6; T reg32=elem.pos(5)[0]*reg4; T reg33=elem.pos(5)[2]*reg4; reg6=elem.pos(2)[2]*reg6;
    T reg34=reg22-reg30; reg31=reg1+reg31; reg1=reg0*elem.pos(1)[1]; T reg35=reg29+reg24; reg19=reg20+reg19;
    reg20=reg32-reg23; reg9=reg3-reg9; reg3=reg0*elem.pos(1)[0]; T reg36=reg0*elem.pos(1)[2]; T reg37=elem.pos(3)[0]*reg8;
    reg20=reg20-reg3; T reg38=pow(reg19,2); T reg39=reg33-reg35; T reg40=elem.pos(3)[1]*reg8; reg34=reg34-reg1;
    reg6=reg9+reg6; reg9=pow(reg31,2); T reg41=pow(reg6,2); T reg42=elem.pos(7)[1]*reg7; reg9=reg38+reg9;
    reg39=reg39-reg36; reg38=reg7*elem.pos(7)[0]; reg34=reg40+reg34; reg37=reg20+reg37; reg20=elem.pos(3)[2]*reg8;
    reg34=reg42+reg34; reg20=reg39+reg20; reg37=reg38+reg37; reg38=elem.pos(6)[0]*reg4; reg39=elem.pos(6)[1]*reg4;
    reg41=reg9+reg41; reg9=reg7*elem.pos(7)[2]; reg40=reg0*elem.pos(2)[1]; reg39=reg34-reg39; reg34=reg4*elem.pos(6)[2];
    reg9=reg20+reg9; reg38=reg37-reg38; reg20=reg0*elem.pos(2)[0]; reg41=pow(reg41,0.5); reg37=reg19/reg41;
    reg42=reg0*elem.pos(2)[2]; reg39=reg40+reg39; reg40=reg31/reg41; reg34=reg9-reg34; reg20=reg38+reg20;
    reg42=reg34+reg42; reg9=reg20*reg40; reg34=reg39*reg37; reg41=reg6/reg41; reg34=reg9+reg34;
    reg9=reg42*reg41; reg9=reg34+reg9; reg34=reg9*reg40; reg38=reg9*reg37; T reg43=reg9*reg41;
    reg34=reg20-reg34; reg38=reg39-reg38; T reg44=pow(reg34,2); T reg45=pow(reg38,2); reg43=reg42-reg43;
    T reg46=pow(reg43,2); reg45=reg44+reg45; reg45=reg46+reg45; reg45=pow(reg45,0.5); reg34=reg34/reg45;
    reg38=reg38/reg45; reg39=reg38*reg39; reg37=reg19*reg37; reg40=reg31*reg40; reg20=reg20*reg34;
    reg45=reg43/reg45; reg34=reg31*reg34; reg38=reg19*reg38; reg39=reg20+reg39; reg42=reg42*reg45;
    reg37=reg40+reg37; reg41=reg6*reg41; reg45=reg6*reg45; reg38=reg34+reg38; reg38=reg45+reg38;
    reg42=reg39+reg42; reg41=reg37+reg41; reg6=reg42*reg41; reg19=reg9*reg38; reg19=reg6-reg19;
    return reg19;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Quad_42,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=1.8214212528966687488*elem.pos(0)[1]; T reg1=0.062499999999999993061*elem.pos(0)[1]; T reg2=0.5624999999999998751*elem.pos(4)[1]; T reg3=0.062500000000000055511*elem.pos(0)[1]; T reg4=0.74785275173800116902*elem.pos(4)[1];
    T reg5=1.6875*elem.pos(4)[0]; T reg6=1.6875*elem.pos(4)[1]; T reg7=0.062500000000000055511*elem.pos(0)[0]; T reg8=2.2214212528966688501*elem.pos(4)[1]; T reg9=2.2214212528966688501*elem.pos(4)[0];
    T reg10=1.8214212528966687488*elem.pos(0)[0]; T reg11=0.48801408404140790478*elem.pos(0)[1]; T reg12=0.48801408404140790478*elem.pos(0)[0]; T reg13=0.5624999999999998751*elem.pos(4)[0]; T reg14=0.062499999999999993061*elem.pos(0)[0];
    T reg15=0.74785275173800116902*elem.pos(4)[0]; T reg16=0.56250000000000006245*elem.pos(5)[1]; reg2=reg2-reg1; reg4=reg11+reg4; reg11=0.29785275173800131643*elem.pos(4)[1];
    T reg17=0.47857874710333128711*elem.pos(5)[1]; T reg18=reg3-reg6; T reg19=1.6875*elem.pos(5)[1]; T reg20=0.061985915958592081643*elem.pos(0)[1]; reg0=reg8-reg0;
    reg8=0.56250000000000006245*elem.pos(5)[0]; reg13=reg13-reg14; T reg21=0.47857874710333128711*elem.pos(5)[0]; reg10=reg9-reg10; reg9=0.29785275173800131643*elem.pos(4)[0];
    T reg22=0.47857874710333157733*elem.pos(4)[0]; T reg23=0.078578747103331282649*elem.pos(0)[0]; T reg24=0.061985915958592081643*elem.pos(0)[0]; T reg25=0.29785275173800124148*elem.pos(5)[0]; reg12=reg15+reg12;
    reg15=0.078578747103331282649*elem.pos(0)[1]; T reg26=0.47857874710333157733*elem.pos(4)[1]; T reg27=0.29785275173800124148*elem.pos(5)[1]; T reg28=1.6875*elem.pos(5)[0]; T reg29=reg7-reg5;
    T reg30=0.24400704202070395239*elem.pos(0)[0]; reg21=reg10-reg21; reg13=reg8+reg13; reg10=0.062499999999999993061*elem.pos(1)[0]; T reg31=0.74785275173800124399*elem.pos(5)[1];
    T reg32=0.37392637586900058451*elem.pos(4)[0]; T reg33=0.078578747103331214053*elem.pos(1)[0]; T reg34=2.2214212528966691402*elem.pos(5)[1]; reg15=reg26-reg15; reg26=0.74785275173800124399*elem.pos(5)[0];
    reg24=reg24-reg9; reg4=reg27-reg4; reg20=reg20-reg11; reg27=0.031249999999999996531*elem.pos(0)[1]; T reg35=0.28124999999999993755*elem.pos(4)[1];
    T reg36=0.061985915958592059837*elem.pos(1)[1]; reg2=reg16+reg2; reg12=reg25-reg12; reg25=0.061985915958592059837*elem.pos(1)[0]; T reg37=0.062499999999999930604*elem.pos(1)[0];
    reg29=reg29+reg28; T reg38=2.2214212528966691402*elem.pos(5)[0]; reg23=reg22-reg23; reg22=0.031249999999999996531*elem.pos(0)[0]; T reg39=0.28124999999999993755*elem.pos(4)[0];
    T reg40=2.9946318793450032447*elem.pos(4)[0]; T reg41=0.11091229182759281127*elem.pos(0)[0]; T reg42=0.24400704202070395239*elem.pos(0)[1]; T reg43=0.062499999999999930604*elem.pos(1)[1]; reg18=reg18+reg19;
    reg17=reg0-reg17; reg0=0.078578747103331214053*elem.pos(1)[1]; T reg44=2.9946318793450032447*elem.pos(4)[1]; T reg45=0.062499999999999993061*elem.pos(1)[1]; T reg46=0.37392637586900058451*elem.pos(4)[1];
    T reg47=0.11091229182759281127*elem.pos(0)[1]; T reg48=1.8214212528966690672*elem.pos(1)[0]; reg38=reg23-reg38; reg23=0.030992957979296040822*elem.pos(0)[0]; reg46=reg42+reg46;
    reg42=0.14892637586900065821*elem.pos(4)[0]; T reg49=1.8214212528966687488*elem.pos(3)[1]; reg33=reg21+reg33; reg21=1.8214212528966687488*elem.pos(3)[0]; T reg50=0.030992957979296040822*elem.pos(0)[1];
    reg20=reg31+reg20; T reg51=0.14892637586900065821*elem.pos(4)[1]; T reg52=0.14892637586900062074*elem.pos(5)[1]; T reg53=0.48801408404140790478*elem.pos(3)[1]; reg0=reg17+reg0;
    reg17=0.48801408404140790478*elem.pos(3)[0]; reg36=reg4-reg36; reg25=reg12-reg25; reg4=0.48801408404140807646*elem.pos(1)[1]; reg12=reg10-reg13;
    T reg54=reg41-reg40; T reg55=2.9946318793450032447*elem.pos(5)[0]; T reg56=0.062500000000000055511*elem.pos(3)[1]; reg18=reg18-reg43; T reg57=reg47-reg44;
    T reg58=2.9946318793450032447*elem.pos(5)[1]; T reg59=0.062499999999999993061*elem.pos(3)[1]; T reg60=reg45-reg2; T reg61=0.062500000000000055511*elem.pos(3)[0]; reg29=reg29-reg37;
    T reg62=3.942126756372671509*elem.pos(4)[0]; T reg63=3.2322880886760779675*elem.pos(0)[0]; T reg64=0.28125000000000003123*elem.pos(5)[0]; reg39=reg39-reg22; T reg65=3.942126756372671509*elem.pos(4)[1];
    T reg66=3.2322880886760779675*elem.pos(0)[1]; reg34=reg15-reg34; reg15=1.8214212528966690672*elem.pos(1)[1]; reg24=reg26+reg24; T reg67=0.48801408404140807646*elem.pos(1)[0];
    T reg68=0.14892637586900062074*elem.pos(5)[0]; reg30=reg32+reg30; reg32=0.28125000000000003123*elem.pos(5)[1]; reg35=reg35-reg27; T reg69=0.062499999999999993061*elem.pos(3)[0];
    T reg70=0.13944558288274055635*elem.pos(0)[0]; T reg71=0.061985915958592081643*elem.pos(3)[1]; T reg72=0.84928425057933444099*elem.pos(4)[0]; reg52=reg46-reg52; reg54=reg54+reg55;
    reg46=0.055456145913796350227*elem.pos(0)[0]; T reg73=0.030992957979296029919*elem.pos(1)[1]; T reg74=0.031249999999999996531*elem.pos(1)[1]; T reg75=0.078578747103331282649*elem.pos(3)[1]; reg15=reg34+reg15;
    reg66=reg65-reg66; reg34=0.84928425057933392599*elem.pos(5)[1]; reg65=0.11091229182759258962*elem.pos(1)[0]; reg35=reg35+reg32; T reg76=0.078578747103331282649*elem.pos(3)[0];
    reg48=reg38+reg48; reg38=0.061985915958592081643*elem.pos(3)[0]; reg57=reg57+reg58; T reg77=0.11091229182759258962*elem.pos(1)[1]; T reg78=0.13944558288274055635*elem.pos(0)[1];
    T reg79=0.84928425057933444099*elem.pos(4)[1]; reg67=reg24+reg67; T reg80=0.49910531322416709662*elem.pos(4)[0]; reg63=reg62-reg63; reg4=reg20+reg4;
    reg62=0.84928425057933392599*elem.pos(5)[0]; reg17=reg25+reg17; reg29=reg29+reg61; reg25=1.6875*elem.pos(7)[0]; T reg81=2.2214212528966688501*elem.pos(7)[1];
    reg49=reg0-reg49; reg0=0.74785275173800116902*elem.pos(7)[1]; reg53=reg36+reg53; reg60=reg60-reg59; reg36=0.5624999999999998751*elem.pos(7)[1];
    reg18=reg18+reg56; T reg82=1.6875*elem.pos(7)[1]; T reg83=2.2214212528966688501*elem.pos(7)[0]; reg21=reg33-reg21; reg33=0.055456145913796350227*elem.pos(0)[1];
    T reg84=0.49910531322416709662*elem.pos(4)[1]; reg12=reg12-reg69; T reg85=0.5624999999999998751*elem.pos(7)[0]; reg68=reg30-reg68; reg30=0.030992957979296029919*elem.pos(1)[0];
    T reg86=0.373926375869000622*elem.pos(5)[0]; reg23=reg23-reg42; reg39=reg39+reg64; T reg87=0.031249999999999996531*elem.pos(1)[0]; reg50=reg50-reg51;
    T reg88=0.373926375869000622*elem.pos(5)[1]; T reg89=0.74785275173800116902*elem.pos(7)[0]; reg54=reg54-reg65; reg62=reg63-reg62; reg63=0.13944558288274043462*elem.pos(1)[0];
    reg18=reg18-reg82; T reg90=1.6875*elem.pos(6)[1]; reg34=reg66-reg34; reg66=0.13944558288274043462*elem.pos(1)[1]; T reg91=0.49910531322416726286*elem.pos(5)[0];
    reg80=reg80-reg46; reg85=reg12+reg85; reg12=0.56250000000000006245*elem.pos(6)[0]; T reg92=0.66356850115866743183*elem.pos(4)[1]; T reg93=0.43301408404140791412*elem.pos(0)[1];
    T reg94=0.29785275173800131643*elem.pos(7)[0]; reg38=reg38-reg67; reg29=reg29-reg25; reg78=reg79-reg78; reg79=3.942126756372672024*elem.pos(5)[1];
    reg70=reg72-reg70; reg39=reg39-reg87; reg72=0.43301408404140791412*elem.pos(0)[0]; T reg95=1.6875*elem.pos(6)[0]; T reg96=0.66356850115866743183*elem.pos(4)[0];
    T reg97=0.38036812065499675528*elem.pos(4)[0]; T reg98=0.014087708172407299745*elem.pos(0)[0]; T reg99=0.014087708172407299745*elem.pos(3)[1]; reg57=reg57-reg77; T reg100=3.942126756372672024*elem.pos(5)[0];
    T reg101=0.031249999999999996531*elem.pos(3)[0]; reg36=reg60+reg36; reg60=0.56250000000000006245*elem.pos(6)[1]; T reg102=0.38036812065499675528*elem.pos(4)[1]; T reg103=0.014087708172407299745*elem.pos(0)[1];
    T reg104=0.014087708172407299745*elem.pos(3)[0]; reg75=reg15-reg75; reg84=reg84-reg33; reg83=reg21+reg83; reg15=0.47857874710333128711*elem.pos(6)[0];
    reg21=0.29785275173800131643*elem.pos(7)[1]; reg71=reg71-reg4; reg0=reg53+reg0; reg53=0.29785275173800124148*elem.pos(6)[1]; T reg105=0.47857874710333157733*elem.pos(7)[0];
    reg76=reg48-reg76; reg81=reg49+reg81; reg48=0.47857874710333128711*elem.pos(6)[1]; reg49=0.24400704202070403823*elem.pos(1)[1]; reg89=reg17+reg89;
    reg17=0.29785275173800124148*elem.pos(6)[0]; reg50=reg50+reg88; reg73=reg52+reg73; reg52=0.24400704202070395239*elem.pos(3)[1]; T reg106=0.24400704202070403823*elem.pos(1)[0];
    reg23=reg23+reg86; reg30=reg68+reg30; reg68=0.24400704202070395239*elem.pos(3)[0]; T reg107=0.49910531322416726286*elem.pos(5)[1]; reg35=reg35-reg74;
    T reg108=0.031249999999999996531*elem.pos(3)[1]; T reg109=0.47857874710333157733*elem.pos(7)[1]; T reg110=0.28124999999999993755*elem.pos(7)[0]; T reg111=0.26428425057933379666*elem.pos(4)[1]; T reg112=0.055000000000000010008*elem.pos(0)[1];
    reg48=reg81-reg48; reg100=reg70-reg100; reg70=3.2322880886760785326*elem.pos(1)[0]; reg81=2.2214212528966691402*elem.pos(6)[1]; reg80=reg80+reg91;
    reg105=reg76+reg105; reg76=2.2214212528966691402*elem.pos(6)[0]; reg79=reg78-reg79; reg78=0.26428425057933373015*elem.pos(5)[0]; reg49=reg50+reg49;
    reg72=reg96+reg72; reg50=0.030992957979296040822*elem.pos(3)[1]; reg96=0.061985915958592059837*elem.pos(2)[1]; reg53=reg0-reg53; reg29=reg29+reg95;
    reg0=3.2322880886760785326*elem.pos(1)[1]; T reg113=0.062499999999999993061*elem.pos(2)[0]; T reg114=0.26428425057933379666*elem.pos(4)[0]; T reg115=0.055000000000000010008*elem.pos(0)[0]; T reg116=0.41055441711725952999*elem.pos(3)[1];
    reg66=reg34+reg66; reg109=reg75+reg109; reg106=reg23+reg106; reg23=0.030992957979296040822*elem.pos(3)[0]; reg34=0.37392637586900058451*elem.pos(7)[1];
    reg52=reg73+reg52; reg84=reg84+reg107; reg73=0.055456145913796350227*elem.pos(1)[1]; reg68=reg30+reg68; reg30=0.061985915958592059837*elem.pos(2)[0];
    reg17=reg89-reg17; reg75=0.37392637586900058451*elem.pos(7)[0]; reg89=0.41055441711725952999*elem.pos(3)[0]; reg38=reg38-reg94; reg63=reg62+reg63;
    reg62=0.74785275173800124399*elem.pos(6)[0]; reg39=reg39-reg101; T reg117=0.078578747103331214053*elem.pos(2)[1]; T reg118=0.74785275173800124399*elem.pos(6)[1]; T reg119=0.41055441711725952999*elem.pos(0)[0];
    T reg120=0.50071574942066619112*elem.pos(4)[0]; T reg121=reg103-reg102; T reg122=0.38036812065499675528*elem.pos(5)[1]; reg92=reg93+reg92; reg93=0.38036812065499675528*elem.pos(7)[0];
    reg36=reg36+reg60; T reg123=0.062499999999999930604*elem.pos(2)[1]; reg18=reg18+reg90; reg54=reg54+reg104; T reg124=0.062499999999999993061*elem.pos(2)[1];
    T reg125=0.28124999999999993755*elem.pos(7)[1]; T reg126=0.055456145913796350227*elem.pos(1)[0]; T reg127=0.26428425057933373015*elem.pos(5)[1]; reg35=reg35-reg108; reg85=reg85+reg12;
    T reg128=0.38036812065499675528*elem.pos(5)[0]; reg71=reg71-reg21; T reg129=reg98-reg97; T reg130=0.50071574942066619112*elem.pos(4)[1]; reg15=reg83-reg15;
    reg83=0.38036812065499675528*elem.pos(7)[1]; T reg131=0.41055441711725952999*elem.pos(0)[1]; T reg132=0.062499999999999930604*elem.pos(2)[0]; reg57=reg57+reg99; T reg133=0.078578747103331214053*elem.pos(2)[0];
    T reg134=0.14892637586900065821*elem.pos(7)[1]; reg115=reg115-reg114; T reg135=0.10787324362732864825*elem.pos(5)[1]; reg34=reg52+reg34; reg52=0.10787324362732871366*elem.pos(4)[0];
    reg131=reg130-reg131; reg130=0.14892637586900062074*elem.pos(6)[1]; T reg136=0.063394686775832778473*elem.pos(4)[1]; T reg137=0.66356850115866749835*elem.pos(5)[0]; T reg138=0.01408770817240727159*elem.pos(1)[1];
    T reg139=0.10787324362732864825*elem.pos(5)[0]; reg119=reg120-reg119; reg120=0.017711911323922008951*elem.pos(0)[1]; T reg140=0.0070438540862036428341*elem.pos(0)[0]; T reg141=0.063394686775832778473*elem.pos(4)[0];
    T reg142=0.017711911323922008951*elem.pos(3)[1]; reg0=reg79+reg0; reg129=reg129+reg128; reg50=reg49+reg50; reg49=0.054999999999999990659*elem.pos(1)[1];
    reg79=0.10787324362732871366*elem.pos(4)[1]; T reg143=0.017711911323922008951*elem.pos(0)[0]; T reg144=0.01408770817240727159*elem.pos(1)[0]; T reg145=0.28125000000000003123*elem.pos(6)[1]; T reg146=0.017711911323922008951*elem.pos(3)[0];
    reg70=reg100+reg70; reg100=0.0070438540862036428341*elem.pos(3)[1]; reg84=reg84-reg73; reg121=reg121+reg122; reg112=reg112-reg111;
    T reg147=0.66356850115866749835*elem.pos(5)[1]; T reg148=0.0070438540862036428341*elem.pos(0)[1]; reg125=reg35+reg125; reg127=reg92-reg127; reg133=reg15+reg133;
    reg54=reg54-reg93; reg96=reg53+reg96; reg15=0.38036812065499675528*elem.pos(6)[0]; reg117=reg48+reg117; reg30=reg17+reg30;
    reg29=reg29-reg132; reg80=reg80-reg126; reg71=reg71+reg118; reg17=0.50071574942066619112*elem.pos(7)[0]; reg89=reg63-reg89;
    reg23=reg106+reg23; reg35=0.14892637586900065821*elem.pos(7)[0]; reg48=0.28125000000000003123*elem.pos(6)[0]; reg57=reg57-reg83; reg53=0.38036812065499675528*elem.pos(6)[1];
    reg63=1.8214212528966690672*elem.pos(2)[0]; reg76=reg105-reg76; reg92=0.14892637586900062074*elem.pos(6)[0]; reg18=reg18-reg123; reg75=reg68+reg75;
    reg68=1.8214212528966690672*elem.pos(2)[1]; reg81=reg109-reg81; reg38=reg38+reg62; reg105=0.48801408404140807646*elem.pos(2)[0]; reg106=0.50071574942066619112*elem.pos(7)[1];
    reg116=reg66-reg116; reg66=0.0070438540862036428341*elem.pos(3)[0]; reg36=reg36-reg124; reg85=reg85-reg113; reg109=0.48801408404140807646*elem.pos(2)[1];
    reg78=reg72-reg78; reg72=0.054999999999999990659*elem.pos(1)[0]; reg110=reg39+reg110; reg112=reg112+reg147; reg18=reg18*reg85;
    reg110=reg110+reg48; reg39=0.031249999999999996531*elem.pos(2)[0]; T reg149=0.054999999999999990659*elem.pos(3)[1]; reg29=reg29*reg36; reg49=reg127+reg49;
    reg141=reg141-reg140; reg127=0.063394686775832799587*elem.pos(5)[0]; T reg150=0.054999999999999990659*elem.pos(0)[1]; T reg151=0.084284250579333737197*elem.pos(4)[1]; reg139=reg119-reg139;
    reg119=0.017711911323921993489*elem.pos(1)[0]; T reg152=0.063394686775832778473*elem.pos(7)[0]; T reg153=0.054999999999999990659*elem.pos(0)[0]; T reg154=0.084284250579333737197*elem.pos(4)[0]; reg80=reg80-reg66;
    reg135=reg131-reg135; reg131=0.017711911323921993489*elem.pos(1)[1]; T reg155=0.063394686775832799587*elem.pos(5)[1]; reg136=reg136-reg148; T reg156=0.11091229182759281127*elem.pos(3)[1];
    reg121=reg121-reg138; reg54=reg54+reg15; T reg157=0.01408770817240727159*elem.pos(2)[0]; reg143=reg52-reg143; reg52=0.50071574942066625656*elem.pos(5)[0];
    reg120=reg79-reg120; reg79=0.50071574942066625656*elem.pos(5)[1]; T reg158=0.11091229182759281127*elem.pos(3)[0]; reg129=reg129-reg144; reg57=reg57+reg53;
    T reg159=0.01408770817240727159*elem.pos(2)[1]; T reg160=0.43301408404140806645*elem.pos(1)[1]; reg146=reg70-reg146; reg92=reg75-reg92; reg70=0.373926375869000622*elem.pos(6)[0];
    reg23=reg23-reg35; reg130=reg34-reg130; reg17=reg89+reg17; reg34=0.030992957979296029919*elem.pos(2)[0]; reg75=0.10787324362732864825*elem.pos(6)[1];
    reg106=reg116+reg106; reg89=0.10787324362732864825*elem.pos(6)[0]; reg116=0.030992957979296029919*elem.pos(2)[1]; reg115=reg115+reg137; reg117=reg117*reg30;
    reg133=reg133*reg96; reg50=reg50-reg134; T reg161=0.43301408404140806645*elem.pos(1)[0]; T reg162=0.373926375869000622*elem.pos(6)[1]; reg142=reg0-reg142;
    reg109=reg71+reg109; reg72=reg78+reg72; reg0=0.054999999999999990659*elem.pos(3)[0]; reg125=reg125+reg145; reg71=0.10787324362732871366*elem.pos(7)[1];
    reg68=reg81+reg68; reg78=0.063394686775832778473*elem.pos(7)[1]; reg84=reg84-reg100; reg81=0.031249999999999996531*elem.pos(2)[1]; reg105=reg38+reg105;
    reg63=reg76+reg63; reg38=0.10787324362732871366*elem.pos(7)[0]; reg131=reg135+reg131; reg76=3.2322880886760779675*elem.pos(3)[1]; reg135=0.0070438540862036428341*elem.pos(1)[1];
    T reg163=0.063394686775832799587*elem.pos(6)[1]; reg78=reg84+reg78; reg50=reg50+reg162; reg84=0.24400704202070403823*elem.pos(2)[1]; T reg164=0.063394686775832799587*elem.pos(6)[0];
    reg18=reg29-reg18; reg119=reg139+reg119; reg152=reg80+reg152; reg29=3.2322880886760779675*elem.pos(3)[0]; reg68=reg68*reg105;
    reg63=reg63*reg109; reg149=reg49+reg149; reg49=0.084284250579333737197*elem.pos(7)[1]; reg110=reg110-reg39; reg125=reg125-reg81;
    reg80=0.41055441711725960177*elem.pos(1)[1]; reg139=0.24400704202070403823*elem.pos(2)[0]; reg23=reg23+reg70; reg79=reg120-reg79; reg160=reg112+reg160;
    reg112=0.0069859159585920716348*elem.pos(3)[1]; reg120=0.41055441711725960177*elem.pos(1)[0]; reg52=reg143-reg52; reg116=reg130+reg116; reg117=reg133-reg117;
    reg34=reg92+reg34; reg92=0.0069859159585920716348*elem.pos(0)[0]; reg130=0.033568501158667519769*elem.pos(4)[0]; reg136=reg136+reg155; reg133=0.084284250579333737197*elem.pos(7)[0];
    reg143=0.033568501158667511326*elem.pos(5)[0]; reg153=reg154+reg153; reg151=reg150+reg151; reg150=0.033568501158667511326*elem.pos(5)[1]; reg154=0.017711911323921993489*elem.pos(2)[1];
    reg38=reg146+reg38; reg146=0.50071574942066625656*elem.pos(6)[0]; reg121=reg121+reg156; reg0=reg72+reg0; reg71=reg142+reg71;
    reg72=0.50071574942066625656*elem.pos(6)[1]; reg142=0.0070438540862036428341*elem.pos(1)[0]; reg141=reg141+reg127; T reg165=0.033568501158667519769*elem.pos(4)[1]; T reg166=0.0069859159585920716348*elem.pos(0)[1];
    T reg167=2.9946318793450032447*elem.pos(7)[1]; reg89=reg17-reg89; reg57=reg57-reg159; reg75=reg106-reg75; reg54=reg54-reg157;
    reg129=reg129+reg158; reg17=2.9946318793450032447*elem.pos(7)[0]; reg106=0.0069859159585920716348*elem.pos(3)[0]; reg161=reg115+reg161; reg115=0.017711911323921993489*elem.pos(2)[0];
    T reg168=0.033568501158667519769*elem.pos(7)[1]; reg112=reg160+reg112; reg160=2.9946318793450032447*elem.pos(6)[0]; reg129=reg129-reg17; reg141=reg141-reg142;
    T reg169=0.055456145913796350227*elem.pos(3)[0]; reg49=reg149+reg49; reg149=0.033568501158667511326*elem.pos(6)[1]; reg154=reg75+reg154; reg54=reg36*reg54;
    reg80=reg79+reg80; reg75=0.13944558288274055635*elem.pos(3)[1]; reg110=reg110*reg18; reg84=reg50+reg84; reg115=reg89+reg115;
    reg106=reg161+reg106; reg50=0.033568501158667519769*elem.pos(7)[0]; reg34=reg34*reg117; reg116=reg117*reg116; reg79=0.033568501158667511326*elem.pos(6)[0];
    reg133=reg0+reg133; reg139=reg23+reg139; reg146=reg38-reg146; reg125=reg18*reg125; reg0=0.41055441711725960177*elem.pos(2)[0];
    reg23=0.084284250579333745647*elem.pos(5)[1]; reg72=reg71-reg72; reg38=0.41055441711725960177*elem.pos(2)[1]; reg166=reg166-reg165; reg68=reg63-reg68;
    reg57=reg85*reg57; reg63=2.9946318793450032447*elem.pos(6)[1]; reg136=reg136-reg135; reg121=reg121-reg167; reg92=reg92-reg130;
    reg71=0.084284250579333745647*elem.pos(5)[0]; reg89=0.055456145913796350227*elem.pos(3)[1]; reg161=3.942126756372671509*elem.pos(7)[1]; reg76=reg131-reg76; reg131=0.0069859159585920691772*elem.pos(1)[1];
    reg150=reg151-reg150; reg151=3.942126756372671509*elem.pos(7)[0]; reg78=reg78+reg163; reg29=reg119-reg29; reg119=0.13944558288274055635*elem.pos(3)[0];
    T reg170=0.0070438540862036428341*elem.pos(2)[1]; reg120=reg52+reg120; reg52=0.0070438540862036428341*elem.pos(2)[0]; reg152=reg152+reg164; reg143=reg153-reg143;
    reg153=0.0069859159585920691772*elem.pos(1)[0]; reg116=0.12345679012345679715*reg116; T reg171=0.11091229182759258962*elem.pos(2)[1]; reg78=reg78-reg170; T reg172=0.084284250579333745647*elem.pos(6)[0];
    reg110=0.19753086419753085323*reg110; reg84=reg68*reg84; reg38=reg72+reg38; reg106=reg106-reg50; reg136=reg136-reg89;
    reg72=0.84928425057933392599*elem.pos(6)[1]; reg166=reg166+reg23; reg161=reg76+reg161; reg0=reg146+reg0; reg151=reg29+reg151;
    reg115=reg96*reg115; reg125=0.19753086419753085323*reg125; reg131=reg150+reg131; reg153=reg143+reg153; reg29=0.43301408404140791412*elem.pos(3)[0];
    reg76=0.49910531322416709662*elem.pos(7)[1]; reg79=reg133-reg79; reg133=0.0069859159585920691772*elem.pos(2)[0]; reg34=0.12345679012345679715*reg34; reg143=0.84928425057933392599*elem.pos(6)[0];
    reg146=0.055000000000000010008*elem.pos(1)[1]; reg119=reg120-reg119; reg120=0.84928425057933444099*elem.pos(7)[0]; reg129=reg129+reg160; reg150=0.11091229182759258962*elem.pos(2)[0];
    reg139=reg139*reg68; T reg173=0.43301408404140791412*elem.pos(3)[1]; reg112=reg112-reg168; T reg174=0.084284250579333745647*elem.pos(6)[1]; reg75=reg80-reg75;
    reg80=0.84928425057933444099*elem.pos(7)[1]; reg152=reg152-reg52; T reg175=0.49910531322416709662*elem.pos(7)[0]; reg18=0.19753086419753085323*reg18; reg117=0.12345679012345679715*reg117;
    T reg176=0.0069859159585920691772*elem.pos(2)[1]; reg141=reg141-reg169; T reg177=0.055000000000000010008*elem.pos(1)[0]; reg92=reg92+reg71; reg57=reg54-reg57;
    reg154=reg30*reg154; reg121=reg121+reg63; reg149=reg49-reg149; reg49=0.055000000000000010008*elem.pos(2)[0]; reg106=reg106+reg172;
    reg112=reg112+reg174; reg154=reg115-reg154; reg120=reg119+reg120; reg38=reg105*reg38; reg139=0.12345679012345679715*reg139;
    reg29=reg153+reg29; reg54=0.66356850115866743183*elem.pos(7)[0]; reg129=reg129-reg150; reg115=0.055000000000000010008*elem.pos(3)[1]; reg119=3.942126756372672024*elem.pos(6)[0];
    reg84=0.12345679012345679715*reg84; reg78=reg57*reg78; reg153=0.49910531322416726286*elem.pos(6)[1]; reg146=reg166+reg146; reg0=reg109*reg0;
    reg68=0.12345679012345679715*reg68; reg117=reg18+reg117; reg121=reg121-reg171; reg176=reg149+reg176; reg18=0.055000000000000010008*elem.pos(3)[0];
    reg177=reg92+reg177; reg175=reg141+reg175; reg76=reg136+reg76; reg92=0.13944558288274043462*elem.pos(2)[0]; reg136=0.49910531322416726286*elem.pos(6)[0];
    reg143=reg151-reg143; reg152=reg152*reg57; reg34=reg110+reg34; reg110=0.66356850115866743183*elem.pos(7)[1]; reg133=reg79+reg133;
    reg173=reg131+reg173; reg79=3.942126756372672024*elem.pos(6)[1]; reg80=reg75+reg80; reg72=reg161-reg72; reg116=reg125+reg116;
    reg75=0.13944558288274043462*elem.pos(2)[1]; reg125=0.055000000000000010008*elem.pos(2)[1]; reg131=0.26428425057933379666*elem.pos(7)[1]; reg115=reg146+reg115; reg78=0.12345679012345679715*reg78;
    reg141=0.26428425057933373015*elem.pos(6)[1]; reg176=reg154*reg176; reg110=reg173+reg110; reg125=reg112+reg125; reg76=reg76+reg153;
    reg112=0.055456145913796350227*elem.pos(2)[1]; reg146=0.26428425057933379666*elem.pos(7)[0]; reg18=reg177+reg18; reg75=reg72+reg75; reg139=reg34+reg139;
    reg119=reg120-reg119; reg34=3.2322880886760785326*elem.pos(2)[0]; reg92=reg143+reg92; reg79=reg80-reg79; reg72=3.2322880886760785326*elem.pos(2)[1];
    reg80=0.26428425057933373015*elem.pos(6)[0]; reg54=reg29+reg54; reg121=reg85*reg121; reg129=reg36*reg129; reg68=reg117+reg68;
    reg57=0.12345679012345679715*reg57; reg29=0.055456145913796350227*elem.pos(2)[0]; reg175=reg175+reg136; reg84=reg116+reg84; reg38=reg0-reg38;
    reg133=reg133*reg154; reg152=0.12345679012345679715*reg152; reg49=reg106+reg49; reg18=reg18-reg146; reg0=0.66356850115866749835*elem.pos(6)[1];
    reg75=reg30*reg75; reg115=reg115-reg131; reg92=reg96*reg92; reg133=0.077160493827160489544*reg133; reg30=0.054999999999999990659*elem.pos(2)[0];
    reg152=reg139+reg152; reg80=reg54-reg80; reg76=reg76-reg112; reg49=reg49*reg38; reg121=reg129-reg121;
    reg36=0.054999999999999990659*elem.pos(2)[1]; reg141=reg110-reg141; reg175=reg175-reg29; reg125=reg38*reg125; reg54=0.66356850115866749835*elem.pos(6)[0];
    reg78=reg84+reg78; reg72=reg79+reg72; reg176=0.077160493827160489544*reg176; reg57=reg68+reg57; reg34=reg119+reg34;
    reg154=0.077160493827160489544*reg154; reg175=reg175*reg121; reg176=reg78+reg176; reg154=reg57+reg154; reg38=0.077160493827160489544*reg38;
    reg36=reg141+reg36; reg49=0.077160493827160489544*reg49; reg133=reg152+reg133; reg115=reg115+reg0; reg57=0.43301408404140806645*elem.pos(2)[1];
    reg125=0.077160493827160489544*reg125; reg76=reg121*reg76; reg72=reg105*reg72; reg34=reg109*reg34; reg75=reg92-reg75;
    reg30=reg80+reg30; reg18=reg18+reg54; reg68=0.43301408404140806645*elem.pos(2)[0]; reg125=reg176+reg125; reg57=reg115+reg57;
    reg121=0.12345679012345679715*reg121; reg38=reg154+reg38; reg30=reg30*reg75; reg36=reg75*reg36; reg76=0.12345679012345679715*reg76;
    reg72=reg34-reg72; reg175=0.12345679012345679715*reg175; reg49=reg133+reg49; reg68=reg18+reg68; reg36=0.077160493827160489544*reg36;
    reg76=reg125+reg76; reg175=reg49+reg175; reg68=reg68*reg72; reg121=reg38+reg121; reg75=0.077160493827160489544*reg75;
    reg30=0.077160493827160489544*reg30; reg57=reg72*reg57; reg30=reg175+reg30; reg57=0.077160493827160489544*reg57; reg72=0.077160493827160489544*reg72;
    reg75=reg121+reg75; reg36=reg76+reg36; reg68=0.077160493827160489544*reg68; reg57=reg36+reg57; reg72=reg75+reg72;
    reg68=reg30+reg68; res[1]=reg57/reg72; res[0]=reg68/reg72;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Quad_42,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=1.8214212528966687488*elem.pos(0)[0]; T reg1=2.2214212528966688501*elem.pos(4)[0]; T reg2=0.062500000000000055511*elem.pos(0)[1]; T reg3=1.6875*elem.pos(4)[0]; T reg4=0.062500000000000055511*elem.pos(0)[0];
    T reg5=1.6875*elem.pos(4)[1]; T reg6=2.2214212528966688501*elem.pos(4)[1]; T reg7=1.8214212528966687488*elem.pos(0)[1]; T reg8=1.6875*elem.pos(5)[1]; T reg9=0.47857874710333128711*elem.pos(5)[0];
    reg0=reg1-reg0; reg1=reg2-reg5; T reg10=reg4-reg3; T reg11=1.6875*elem.pos(5)[0]; T reg12=1.6875*elem.pos(4)[2];
    T reg13=0.062500000000000055511*elem.pos(0)[2]; T reg14=1.8214212528966687488*elem.pos(0)[2]; T reg15=2.2214212528966688501*elem.pos(4)[2]; T reg16=0.078578747103331282649*elem.pos(0)[1]; T reg17=0.47857874710333157733*elem.pos(4)[1];
    reg7=reg6-reg7; reg6=0.47857874710333128711*elem.pos(5)[1]; T reg18=0.078578747103331282649*elem.pos(0)[0]; T reg19=0.47857874710333157733*elem.pos(4)[0]; T reg20=0.11091229182759281127*elem.pos(0)[0];
    T reg21=reg13-reg12; T reg22=1.6875*elem.pos(5)[2]; T reg23=0.062499999999999930604*elem.pos(1)[1]; T reg24=2.9946318793450032447*elem.pos(4)[1]; T reg25=2.2214212528966691402*elem.pos(5)[1];
    T reg26=0.11091229182759281127*elem.pos(0)[1]; reg16=reg17-reg16; reg18=reg19-reg18; reg1=reg1+reg8; reg17=2.2214212528966691402*elem.pos(5)[0];
    reg19=0.078578747103331282649*elem.pos(0)[2]; T reg27=0.47857874710333157733*elem.pos(4)[2]; T reg28=0.47857874710333128711*elem.pos(5)[2]; reg14=reg15-reg14; reg15=0.078578747103331214053*elem.pos(1)[1];
    reg6=reg7-reg6; reg7=0.078578747103331214053*elem.pos(1)[0]; reg9=reg0-reg9; reg0=0.062499999999999930604*elem.pos(1)[0]; reg10=reg10+reg11;
    T reg29=2.9946318793450032447*elem.pos(4)[0]; T reg30=2.2214212528966691402*elem.pos(5)[2]; T reg31=3.2322880886760779675*elem.pos(0)[0]; T reg32=3.2322880886760779675*elem.pos(0)[1]; reg25=reg16-reg25;
    reg28=reg14-reg28; reg14=1.8214212528966690672*elem.pos(1)[1]; reg16=0.078578747103331214053*elem.pos(1)[2]; reg1=reg1-reg23; T reg33=0.062500000000000055511*elem.pos(3)[1];
    T reg34=0.062499999999999930604*elem.pos(1)[2]; reg21=reg21+reg22; T reg35=3.942126756372671509*elem.pos(4)[1]; reg19=reg27-reg19; reg10=reg10-reg0;
    reg27=2.9946318793450032447*elem.pos(4)[2]; T reg36=0.11091229182759281127*elem.pos(0)[2]; reg7=reg9+reg7; reg9=2.9946318793450032447*elem.pos(5)[1]; T reg37=reg26-reg24;
    T reg38=1.8214212528966687488*elem.pos(3)[0]; T reg39=0.062500000000000055511*elem.pos(3)[0]; T reg40=3.942126756372671509*elem.pos(4)[0]; reg15=reg6+reg15; reg6=reg20-reg29;
    T reg41=2.9946318793450032447*elem.pos(5)[0]; T reg42=1.8214212528966687488*elem.pos(3)[1]; reg17=reg18-reg17; reg18=1.8214212528966690672*elem.pos(1)[0]; reg1=reg1+reg33;
    T reg43=1.6875*elem.pos(7)[1]; T reg44=1.8214212528966687488*elem.pos(3)[2]; reg16=reg28+reg16; reg42=reg15-reg42; reg15=2.2214212528966688501*elem.pos(7)[1];
    reg38=reg7-reg38; reg7=2.2214212528966688501*elem.pos(7)[0]; reg31=reg40-reg31; reg28=0.84928425057933392599*elem.pos(5)[0]; reg32=reg35-reg32;
    reg35=0.84928425057933392599*elem.pos(5)[1]; reg40=2.9946318793450032447*elem.pos(5)[2]; T reg45=3.942126756372671509*elem.pos(4)[2]; T reg46=reg36-reg27; T reg47=3.2322880886760779675*elem.pos(0)[2];
    T reg48=0.11091229182759258962*elem.pos(1)[1]; reg37=reg37+reg9; reg18=reg17+reg18; reg17=0.078578747103331282649*elem.pos(3)[0]; reg14=reg25+reg14;
    reg25=0.078578747103331282649*elem.pos(3)[1]; T reg49=0.062500000000000055511*elem.pos(3)[2]; reg21=reg21-reg34; T reg50=0.84928425057933444099*elem.pos(4)[1]; T reg51=0.13944558288274055635*elem.pos(0)[1];
    reg6=reg6+reg41; T reg52=0.11091229182759258962*elem.pos(1)[0]; reg10=reg10+reg39; T reg53=1.6875*elem.pos(7)[0]; T reg54=0.84928425057933444099*elem.pos(4)[0];
    T reg55=0.13944558288274055635*elem.pos(0)[0]; reg30=reg19-reg30; reg19=1.8214212528966690672*elem.pos(1)[2]; T reg56=0.47857874710333157733*elem.pos(7)[0]; T reg57=0.13944558288274043462*elem.pos(1)[0];
    T reg58=0.062499999999999993061*elem.pos(0)[1]; reg28=reg31-reg28; reg31=2.2214212528966688501*elem.pos(7)[2]; T reg59=0.5624999999999998751*elem.pos(4)[1]; T reg60=0.014087708172407299745*elem.pos(3)[0];
    reg17=reg18-reg17; reg6=reg6-reg52; reg35=reg32-reg35; reg18=0.13944558288274043462*elem.pos(1)[1]; reg32=0.38036812065499675528*elem.pos(4)[1];
    reg42=reg15+reg42; reg15=0.11091229182759258962*elem.pos(1)[2]; T reg61=0.47857874710333128711*elem.pos(6)[1]; reg46=reg46+reg40; T reg62=3.942126756372672024*elem.pos(5)[1];
    T reg63=0.014087708172407299745*elem.pos(0)[0]; T reg64=0.38036812065499675528*elem.pos(4)[0]; reg44=reg16-reg44; reg16=0.74785275173800116902*elem.pos(4)[1]; T reg65=0.014087708172407299745*elem.pos(3)[1];
    reg51=reg50-reg51; reg47=reg45-reg47; reg45=0.84928425057933392599*elem.pos(5)[2]; reg50=0.48801408404140790478*elem.pos(0)[1]; reg37=reg37-reg48;
    T reg66=1.6875*elem.pos(7)[2]; T reg67=3.942126756372672024*elem.pos(5)[0]; T reg68=1.6875*elem.pos(6)[1]; T reg69=0.13944558288274055635*elem.pos(0)[2]; reg1=reg1-reg43;
    T reg70=0.84928425057933444099*elem.pos(4)[2]; reg21=reg21+reg49; T reg71=0.014087708172407299745*elem.pos(0)[1]; reg38=reg7+reg38; reg25=reg14-reg25;
    reg7=0.078578747103331282649*elem.pos(3)[2]; reg19=reg30+reg19; reg55=reg54-reg55; reg10=reg10-reg53; reg14=0.74785275173800116902*elem.pos(4)[0];
    reg30=1.6875*elem.pos(6)[0]; reg54=0.47857874710333157733*elem.pos(7)[1]; T reg72=0.47857874710333128711*elem.pos(6)[0]; T reg73=0.48801408404140790478*elem.pos(0)[0]; T reg74=0.5624999999999998751*elem.pos(4)[0];
    T reg75=0.062499999999999993061*elem.pos(0)[0]; T reg76=reg63-reg64; T reg77=0.41055441711725952999*elem.pos(0)[1]; T reg78=0.48801408404140790478*elem.pos(0)[2]; reg72=reg38-reg72;
    reg38=0.74785275173800116902*elem.pos(4)[2]; T reg79=0.38036812065499675528*elem.pos(5)[0]; T reg80=0.38036812065499675528*elem.pos(4)[2]; T reg81=0.078578747103331214053*elem.pos(2)[0]; T reg82=0.29785275173800124148*elem.pos(5)[0];
    T reg83=0.50071574942066619112*elem.pos(4)[1]; T reg84=reg71-reg32; reg16=reg50+reg16; reg50=3.942126756372672024*elem.pos(5)[2]; reg69=reg70-reg69;
    reg70=0.29785275173800124148*elem.pos(5)[1]; T reg85=0.29785275173800131643*elem.pos(4)[1]; T reg86=0.38036812065499675528*elem.pos(5)[1]; T reg87=0.41055441711725952999*elem.pos(3)[0]; reg57=reg28+reg57;
    reg28=0.061985915958592081643*elem.pos(0)[1]; T reg88=0.50071574942066619112*elem.pos(4)[0]; T reg89=0.41055441711725952999*elem.pos(0)[0]; reg73=reg14+reg73; reg14=0.38036812065499675528*elem.pos(7)[1];
    T reg90=0.061985915958592081643*elem.pos(0)[0]; T reg91=0.29785275173800131643*elem.pos(4)[0]; reg17=reg56+reg17; reg74=reg74-reg75; reg56=0.56250000000000006245*elem.pos(5)[0];
    T reg92=2.2214212528966691402*elem.pos(6)[0]; reg6=reg6+reg60; reg25=reg54+reg25; reg54=2.2214212528966691402*elem.pos(6)[1]; T reg93=1.6875*elem.pos(6)[2];
    reg21=reg21-reg66; T reg94=0.014087708172407299745*elem.pos(0)[2]; T reg95=3.2322880886760785326*elem.pos(1)[0]; reg67=reg55-reg67; reg7=reg19-reg7;
    reg19=0.47857874710333157733*elem.pos(7)[2]; reg55=0.062499999999999930604*elem.pos(2)[1]; reg1=reg1+reg68; reg10=reg10+reg30; T reg96=0.062499999999999930604*elem.pos(2)[0];
    T reg97=0.38036812065499675528*elem.pos(7)[0]; reg18=reg35+reg18; reg35=0.41055441711725952999*elem.pos(3)[1]; T reg98=0.014087708172407299745*elem.pos(3)[2]; reg46=reg46-reg15;
    reg61=reg42-reg61; reg42=0.078578747103331214053*elem.pos(2)[1]; T reg99=3.2322880886760785326*elem.pos(1)[1]; reg62=reg51-reg62; reg51=0.47857874710333128711*elem.pos(6)[2];
    T reg100=0.56250000000000006245*elem.pos(5)[1]; reg59=reg59-reg58; T reg101=0.13944558288274043462*elem.pos(1)[2]; reg45=reg47-reg45; reg37=reg37+reg65;
    reg47=0.062499999999999993061*elem.pos(0)[2]; T reg102=0.5624999999999998751*elem.pos(4)[2]; reg44=reg31+reg44; reg31=0.061985915958592081643*elem.pos(0)[2]; T reg103=reg94-reg80;
    reg84=reg84+reg86; T reg104=0.29785275173800131643*elem.pos(4)[2]; T reg105=0.38036812065499675528*elem.pos(5)[2]; T reg106=0.078578747103331214053*elem.pos(2)[2]; reg51=reg44-reg51;
    reg44=0.01408770817240727159*elem.pos(1)[1]; T reg107=1.8214212528966690672*elem.pos(2)[1]; reg54=reg25-reg54; reg7=reg19+reg7; reg19=2.2214212528966691402*elem.pos(6)[2];
    reg25=0.38036812065499675528*elem.pos(6)[0]; reg6=reg6-reg97; T reg108=1.8214212528966690672*elem.pos(2)[0]; reg92=reg17-reg92; reg17=0.74785275173800124399*elem.pos(5)[0];
    reg37=reg37-reg14; T reg109=0.38036812065499675528*elem.pos(6)[1]; T reg110=0.38036812065499675528*elem.pos(7)[2]; reg90=reg90-reg91; T reg111=0.017711911323922008951*elem.pos(0)[0];
    T reg112=0.10787324362732871366*elem.pos(4)[0]; reg46=reg46+reg98; T reg113=0.01408770817240727159*elem.pos(1)[0]; reg76=reg76+reg79; reg38=reg78+reg38;
    reg78=0.29785275173800124148*elem.pos(5)[2]; T reg114=0.10787324362732871366*elem.pos(4)[1]; T reg115=0.061985915958592059837*elem.pos(1)[1]; reg16=reg70-reg16; reg70=0.017711911323922008951*elem.pos(0)[1];
    T reg116=0.061985915958592059837*elem.pos(1)[0]; reg73=reg82-reg73; reg82=0.74785275173800124399*elem.pos(5)[1]; reg28=reg28-reg85; T reg117=3.2322880886760785326*elem.pos(1)[2];
    reg50=reg69-reg50; reg87=reg57-reg87; reg57=0.017711911323922008951*elem.pos(3)[1]; reg77=reg83-reg77; reg69=0.10787324362732864825*elem.pos(5)[1];
    reg99=reg62+reg99; reg62=0.50071574942066619112*elem.pos(7)[1]; reg83=0.017711911323922008951*elem.pos(3)[0]; reg35=reg18-reg35; reg95=reg67+reg95;
    reg18=0.41055441711725952999*elem.pos(0)[2]; reg67=0.50071574942066619112*elem.pos(4)[2]; reg10=reg10-reg96; reg1=reg1-reg55; reg102=reg102-reg47;
    T reg118=0.56250000000000006245*elem.pos(5)[2]; reg21=reg21+reg93; T reg119=0.062499999999999993061*elem.pos(1)[1]; reg59=reg100+reg59; T reg120=0.062499999999999930604*elem.pos(2)[2];
    reg101=reg45+reg101; reg45=0.41055441711725952999*elem.pos(3)[2]; T reg121=0.062499999999999993061*elem.pos(1)[0]; reg74=reg56+reg74; T reg122=0.10787324362732864825*elem.pos(5)[0];
    reg42=reg61+reg42; reg61=0.50071574942066619112*elem.pos(7)[0]; reg81=reg72+reg81; reg89=reg88-reg89; reg72=0.017711911323922008951*elem.pos(0)[2];
    reg88=0.10787324362732871366*elem.pos(7)[0]; T reg123=0.10787324362732871366*elem.pos(4)[2]; T reg124=0.50071574942066619112*elem.pos(7)[2]; reg18=reg67-reg18; reg67=0.10787324362732864825*elem.pos(5)[2];
    T reg125=0.50071574942066625656*elem.pos(5)[0]; reg111=reg112-reg111; reg31=reg31-reg104; reg19=reg7-reg19; reg7=1.8214212528966690672*elem.pos(2)[2];
    reg112=0.10787324362732864825*elem.pos(6)[1]; reg35=reg62+reg35; reg46=reg46-reg110; reg62=0.38036812065499675528*elem.pos(6)[2]; reg6=reg6+reg25;
    T reg126=pow(reg42,2); T reg127=reg121-reg74; T reg128=0.062499999999999993061*elem.pos(3)[0]; reg108=reg92+reg108; reg45=reg101-reg45;
    reg92=0.01408770817240727159*elem.pos(2)[0]; reg21=reg21-reg120; reg101=pow(reg81,2); reg106=reg51+reg106; reg51=reg119-reg59;
    T reg129=0.062499999999999993061*elem.pos(3)[1]; T reg130=0.01408770817240727159*elem.pos(1)[2]; T reg131=pow(reg1,2); reg107=reg54+reg107; reg103=reg103+reg105;
    reg102=reg118+reg102; reg37=reg37+reg109; reg54=0.01408770817240727159*elem.pos(2)[1]; T reg132=pow(reg10,2); T reg133=0.062499999999999993061*elem.pos(1)[2];
    T reg134=0.017711911323921993489*elem.pos(1)[1]; reg69=reg77-reg69; reg122=reg89-reg122; reg77=0.017711911323921993489*elem.pos(1)[0]; reg57=reg99-reg57;
    reg116=reg73-reg116; reg28=reg82+reg28; reg73=0.48801408404140790478*elem.pos(3)[1]; reg115=reg16-reg115; reg16=0.48801408404140807646*elem.pos(1)[1];
    reg89=0.10787324362732864825*elem.pos(6)[0]; reg87=reg61+reg87; reg61=0.48801408404140790478*elem.pos(3)[0]; reg84=reg84-reg44; reg70=reg114-reg70;
    reg99=0.50071574942066625656*elem.pos(5)[1]; reg114=0.017711911323922008951*elem.pos(3)[2]; reg117=reg50+reg117; reg50=0.74785275173800124399*elem.pos(5)[2]; reg83=reg95-reg83;
    reg95=0.11091229182759281127*elem.pos(3)[0]; reg76=reg76-reg113; T reg135=0.10787324362732871366*elem.pos(7)[1]; T reg136=0.11091229182759281127*elem.pos(3)[1]; reg90=reg17+reg90;
    reg38=reg78-reg38; reg78=0.48801408404140807646*elem.pos(1)[0]; T reg137=0.061985915958592059837*elem.pos(1)[2]; T reg138=0.11091229182759281127*elem.pos(3)[2]; reg78=reg90+reg78;
    reg7=reg19+reg7; reg19=0.5624999999999998751*elem.pos(7)[0]; T reg139=0.10787324362732864825*elem.pos(6)[2]; reg84=reg84+reg136; T reg140=pow(reg108,2);
    reg31=reg50+reg31; T reg141=0.10787324362732871366*elem.pos(7)[2]; T reg142=0.061985915958592081643*elem.pos(3)[1]; reg16=reg28+reg16; T reg143=pow(reg21,2);
    reg114=reg117-reg114; reg83=reg88+reg83; reg88=0.50071574942066625656*elem.pos(6)[0]; reg103=reg103-reg130; reg117=0.061985915958592081643*elem.pos(3)[0];
    reg131=reg132+reg131; reg132=0.48801408404140807646*elem.pos(1)[2]; T reg144=pow(reg107,2); T reg145=0.50071574942066625656*elem.pos(6)[1]; T reg146=2.9946318793450032447*elem.pos(7)[1];
    reg57=reg135+reg57; reg135=0.017711911323921993489*elem.pos(1)[2]; reg67=reg18-reg67; reg18=0.41055441711725960177*elem.pos(1)[0]; reg125=reg111-reg125;
    reg111=0.017711911323921993489*elem.pos(2)[1]; reg112=reg35-reg112; reg46=reg46+reg62; reg35=0.01408770817240727159*elem.pos(2)[2]; reg76=reg76+reg95;
    T reg147=3.2322880886760779675*elem.pos(3)[1]; T reg148=0.48801408404140790478*elem.pos(3)[2]; reg137=reg38-reg137; reg134=reg69+reg134; reg38=2.9946318793450032447*elem.pos(7)[0];
    reg69=0.017711911323921993489*elem.pos(2)[0]; reg73=reg115+reg73; reg89=reg87-reg89; reg87=3.2322880886760779675*elem.pos(3)[0]; reg115=0.74785275173800116902*elem.pos(7)[1];
    reg77=reg122+reg77; reg99=reg70-reg99; reg61=reg116+reg61; reg70=0.74785275173800116902*elem.pos(7)[0]; reg116=0.41055441711725960177*elem.pos(1)[1];
    reg72=reg123-reg72; reg122=0.50071574942066625656*elem.pos(5)[2]; reg123=pow(reg106,2); reg126=reg101+reg126; reg45=reg124+reg45;
    reg37=reg37-reg54; reg51=reg51-reg129; reg101=0.5624999999999998751*elem.pos(7)[1]; reg124=reg133-reg102; T reg149=0.062499999999999993061*elem.pos(3)[2];
    reg127=reg127-reg128; reg6=reg6-reg92; T reg150=0.41055441711725960177*elem.pos(2)[1]; reg73=reg115+reg73; reg143=reg131+reg143;
    reg87=reg77-reg87; reg145=reg57-reg145; reg57=0.29785275173800131643*elem.pos(7)[1]; reg142=reg142-reg16; reg77=0.41055441711725960177*elem.pos(1)[2];
    reg115=0.29785275173800124148*elem.pos(6)[0]; reg61=reg70+reg61; reg70=0.017711911323921993489*elem.pos(2)[2]; reg131=3.942126756372671509*elem.pos(7)[0]; reg139=reg45-reg139;
    reg116=reg99+reg116; reg114=reg141+reg114; reg45=0.13944558288274055635*elem.pos(3)[1]; reg99=0.56250000000000006245*elem.pos(6)[0]; reg132=reg31+reg132;
    reg141=0.061985915958592081643*elem.pos(3)[2]; reg84=reg84-reg146; T reg151=2.9946318793450032447*elem.pos(6)[1]; T reg152=2.9946318793450032447*elem.pos(7)[2]; T reg153=0.50071574942066625656*elem.pos(6)[2];
    reg127=reg19+reg127; reg122=reg72-reg122; reg123=reg126+reg123; reg147=reg134-reg147; reg103=reg103+reg138;
    reg124=reg124-reg149; reg19=0.13944558288274055635*elem.pos(3)[0]; reg18=reg125+reg18; reg111=reg112+reg111; reg135=reg67+reg135;
    reg67=pow(reg37,2); reg144=reg140+reg144; reg72=pow(reg7,2); reg112=3.2322880886760779675*elem.pos(3)[2]; reg46=reg46-reg35;
    reg125=2.9946318793450032447*elem.pos(6)[0]; reg76=reg76-reg38; reg126=0.5624999999999998751*elem.pos(7)[2]; reg88=reg83-reg88; reg83=0.41055441711725960177*elem.pos(2)[0];
    reg134=0.29785275173800131643*elem.pos(7)[0]; reg140=0.56250000000000006245*elem.pos(6)[1]; T reg154=0.29785275173800124148*elem.pos(6)[1]; reg148=reg137+reg148; reg51=reg101+reg51;
    reg101=pow(reg6,2); reg69=reg89+reg69; reg89=0.74785275173800116902*elem.pos(7)[2]; reg137=3.942126756372671509*elem.pos(7)[1]; reg117=reg117-reg78;
    T reg155=2.9946318793450032447*elem.pos(6)[2]; reg103=reg103-reg152; T reg156=pow(reg111,2); T reg157=0.11091229182759258962*elem.pos(2)[0]; reg150=reg145+reg150;
    reg153=reg114-reg153; reg67=reg101+reg67; reg101=0.11091229182759258962*elem.pos(2)[1]; reg84=reg84+reg151; reg114=0.41055441711725960177*elem.pos(2)[2];
    reg145=0.13944558288274055635*elem.pos(3)[2]; T reg158=pow(reg46,2); reg76=reg76+reg125; reg45=reg116-reg45; reg77=reg122+reg77;
    reg70=reg139+reg70; reg116=pow(reg69,2); reg83=reg88+reg83; reg141=reg141-reg132; reg88=0.29785275173800131643*elem.pos(7)[2];
    reg122=0.29785275173800124148*elem.pos(6)[2]; reg139=0.74785275173800124399*elem.pos(6)[1]; reg142=reg142-reg57; reg51=reg51+reg140; T reg159=0.062499999999999993061*elem.pos(2)[1];
    T reg160=0.74785275173800124399*elem.pos(6)[0]; reg117=reg117-reg134; reg72=reg144+reg72; reg123=pow(reg123,0.5); reg124=reg126+reg124;
    reg126=0.84928425057933444099*elem.pos(7)[1]; reg144=0.56250000000000006245*elem.pos(6)[2]; reg112=reg135-reg112; reg135=3.942126756372671509*elem.pos(7)[2]; reg87=reg131+reg87;
    reg131=0.84928425057933392599*elem.pos(6)[0]; reg19=reg18-reg19; reg143=pow(reg143,0.5); reg154=reg73-reg154; reg18=0.061985915958592059837*elem.pos(2)[1];
    reg73=0.062499999999999993061*elem.pos(2)[0]; reg127=reg127+reg99; T reg161=0.061985915958592059837*elem.pos(2)[0]; reg115=reg61-reg115; reg61=0.84928425057933444099*elem.pos(7)[0];
    T reg162=0.84928425057933392599*elem.pos(6)[1]; reg148=reg89+reg148; reg147=reg137+reg147; reg156=reg116+reg156; reg89=pow(reg70,2);
    reg162=reg147-reg162; reg124=reg124+reg144; reg116=0.062499999999999993061*elem.pos(2)[2]; reg114=reg153+reg114; reg137=reg81/reg123;
    reg51=reg51-reg159; reg145=reg77-reg145; reg77=0.84928425057933392599*elem.pos(6)[2]; reg112=reg135+reg112; reg161=reg115+reg161;
    reg115=reg10/reg143; reg158=reg67+reg158; reg131=reg87-reg131; reg67=3.942126756372672024*elem.pos(6)[0]; reg19=reg61+reg19;
    reg61=pow(reg150,2); reg87=0.13944558288274043462*elem.pos(2)[0]; reg135=reg1/reg143; reg147=0.13944558288274043462*elem.pos(2)[1]; reg141=reg141-reg88;
    reg153=0.74785275173800124399*elem.pos(6)[2]; reg127=reg127-reg73; reg84=reg84-reg101; reg122=reg148-reg122; reg148=0.48801408404140807646*elem.pos(2)[1];
    reg142=reg142+reg139; reg18=reg154+reg18; reg154=0.061985915958592059837*elem.pos(2)[2]; reg45=reg126+reg45; reg76=reg76-reg157;
    reg126=0.48801408404140807646*elem.pos(2)[0]; T reg163=3.942126756372672024*elem.pos(6)[1]; reg117=reg117+reg160; T reg164=pow(reg83,2); reg72=pow(reg72,0.5);
    T reg165=reg42/reg123; reg103=reg103+reg155; T reg166=0.84928425057933444099*elem.pos(7)[2]; T reg167=0.11091229182759258962*elem.pos(2)[2]; reg123=reg106/reg123;
    T reg168=reg137*reg161; T reg169=pow(reg114,2); T reg170=3.2322880886760785326*elem.pos(2)[1]; T reg171=reg165*reg18; reg163=reg45-reg163;
    reg158=pow(reg158,0.5); reg154=reg122+reg154; reg45=3.942126756372672024*elem.pos(6)[2]; reg145=reg166+reg145; reg61=reg164+reg61;
    reg89=reg156+reg89; reg143=reg21/reg143; reg122=0.48801408404140807646*elem.pos(2)[2]; reg156=pow(reg84,2); reg141=reg141+reg153;
    reg148=reg142+reg148; reg126=reg117+reg126; reg117=pow(reg76,2); reg142=reg115*reg127; reg103=reg103-reg167;
    reg164=reg107/reg72; reg166=reg108/reg72; T reg172=reg135*reg51; reg87=reg131+reg87; reg67=reg19-reg67;
    reg19=3.2322880886760785326*elem.pos(2)[0]; reg147=reg162+reg147; reg77=reg112-reg77; reg124=reg124-reg116; reg112=0.13944558288274043462*elem.pos(2)[2];
    reg89=pow(reg89,0.5); reg131=pow(reg87,2); reg122=reg141+reg122; reg141=reg123*reg154; reg156=reg117+reg156;
    reg172=reg142+reg172; reg171=reg168+reg171; reg19=reg67+reg19; reg67=reg164*reg148; reg112=reg77+reg112;
    reg77=reg166*reg126; reg117=pow(reg147,2); reg142=3.2322880886760785326*elem.pos(2)[2]; reg45=reg145-reg45; reg145=reg6/reg158;
    reg162=reg143*reg124; reg72=reg7/reg72; reg168=reg37/reg158; reg169=reg61+reg169; reg170=reg163+reg170;
    reg61=pow(reg103,2); reg162=reg172+reg162; reg163=pow(reg170,2); reg172=reg69/reg89; T reg173=reg111/reg89;
    reg158=reg46/reg158; reg141=reg171+reg141; reg171=reg127*reg145; T reg174=reg51*reg168; T reg175=reg72*reg122;
    reg67=reg77+reg67; reg169=pow(reg169,0.5); reg77=pow(reg112,2); reg61=reg156+reg61; reg117=reg131+reg117;
    reg131=pow(reg19,2); reg142=reg45+reg142; reg77=reg117+reg77; reg45=reg161*reg172; reg117=reg18*reg173;
    reg156=reg165*reg141; reg61=pow(reg61,0.5); T reg176=reg135*reg162; reg175=reg67+reg175; reg89=reg70/reg89;
    reg67=reg115*reg162; T reg177=reg137*reg141; T reg178=pow(reg142,2); reg174=reg171+reg174; reg171=reg150/reg169;
    T reg179=reg124*reg158; reg163=reg131+reg163; reg131=reg83/reg169; reg169=reg114/reg169; T reg180=reg84/reg61;
    reg67=reg127-reg67; T reg181=reg76/reg61; T reg182=reg126*reg131; reg176=reg51-reg176; T reg183=reg148*reg171;
    reg178=reg163+reg178; reg163=reg143*reg162; T reg184=reg164*reg175; reg179=reg174+reg179; reg77=pow(reg77,0.5);
    reg174=reg123*reg141; reg156=reg18-reg156; reg117=reg45+reg117; reg45=reg154*reg89; reg177=reg161-reg177;
    T reg185=reg166*reg175; reg184=reg148-reg184; T reg186=reg87/reg77; T reg187=reg147/reg77; reg185=reg126-reg185;
    reg61=reg103/reg61; T reg188=reg168*reg179; T reg189=reg145*reg179; reg183=reg182+reg183; reg182=reg122*reg169;
    T reg190=reg72*reg175; reg45=reg117+reg45; reg117=pow(reg177,2); T reg191=pow(reg156,2); reg174=reg154-reg174;
    reg163=reg124-reg163; T reg192=pow(reg176,2); T reg193=pow(reg67,2); reg178=pow(reg178,0.5); T reg194=reg51*reg180;
    T reg195=reg127*reg181; T reg196=reg161*reg186; reg77=reg112/reg77; T reg197=reg18*reg187; T reg198=reg19/reg178;
    T reg199=reg170/reg178; T reg200=reg172*reg45; T reg201=reg173*reg45; reg182=reg183+reg182; reg194=reg195+reg194;
    reg183=reg124*reg61; reg195=reg158*reg179; T reg202=pow(reg174,2); reg188=reg51-reg188; T reg203=pow(reg184,2);
    T reg204=pow(reg185,2); reg189=reg127-reg189; T reg205=pow(reg163,2); reg192=reg193+reg192; reg190=reg122-reg190;
    reg191=reg117+reg191; reg117=0.37392637586900058451*elem.pos(4)[1]; reg193=0.28124999999999993755*elem.pos(4)[1]; T reg206=0.031249999999999996531*elem.pos(0)[1]; T reg207=0.37392637586900058451*elem.pos(4)[2];
    T reg208=0.031249999999999996531*elem.pos(0)[2]; reg202=reg191+reg202; reg191=0.24400704202070395239*elem.pos(0)[2]; T reg209=reg148*reg199; reg195=reg124-reg195;
    T reg210=pow(reg188,2); T reg211=reg126*reg198; T reg212=pow(reg189,2); reg178=reg142/reg178; T reg213=0.24400704202070395239*elem.pos(0)[1];
    T reg214=0.031249999999999996531*elem.pos(0)[0]; T reg215=0.28124999999999993755*elem.pos(4)[2]; reg205=reg192+reg205; reg192=pow(reg190,2); T reg216=0.37392637586900058451*elem.pos(4)[0];
    T reg217=0.24400704202070395239*elem.pos(0)[0]; T reg218=0.28124999999999993755*elem.pos(4)[0]; reg200=reg161-reg200; reg183=reg194+reg183; reg201=reg18-reg201;
    reg194=reg89*reg45; T reg219=reg154*reg77; reg197=reg196+reg197; reg203=reg204+reg203; reg196=reg171*reg182;
    reg204=reg131*reg182; T reg220=0.14892637586900065821*elem.pos(4)[0]; T reg221=reg181*reg183; T reg222=0.030992957979296040822*elem.pos(0)[0]; T reg223=0.14892637586900065821*elem.pos(4)[1];
    T reg224=0.030992957979296040822*elem.pos(0)[1]; reg117=reg213+reg117; reg213=0.14892637586900062074*elem.pos(5)[1]; reg192=reg203+reg192; reg219=reg197+reg219;
    reg197=0.030992957979296040822*elem.pos(0)[2]; reg215=reg215-reg208; reg203=0.28125000000000003123*elem.pos(5)[2]; reg205=pow(reg205,0.5); reg217=reg216+reg217;
    reg216=0.14892637586900062074*elem.pos(5)[0]; T reg225=pow(reg200,2); T reg226=pow(reg201,2); reg194=reg154-reg194; reg210=reg212+reg210;
    reg212=reg169*reg182; reg196=reg148-reg196; T reg227=0.14892637586900065821*elem.pos(4)[2]; reg204=reg126-reg204; T reg228=0.14892637586900062074*elem.pos(5)[2];
    reg207=reg191+reg207; reg193=reg193-reg206; reg191=0.28125000000000003123*elem.pos(5)[1]; T reg229=reg122*reg178; reg209=reg211+reg209;
    reg211=pow(reg195,2); reg202=pow(reg202,0.5); T reg230=reg180*reg183; T reg231=0.28125000000000003123*elem.pos(5)[0]; reg218=reg218-reg214;
    T reg232=0.373926375869000622*elem.pos(5)[2]; reg197=reg197-reg227; T reg233=reg187*reg219; T reg234=reg186*reg219; T reg235=pow(reg204,2);
    T reg236=pow(reg196,2); reg212=reg122-reg212; T reg237=0.030992957979296029919*elem.pos(1)[2]; T reg238=0.055456145913796350227*elem.pos(0)[2]; T reg239=0.49910531322416709662*elem.pos(4)[2];
    reg228=reg207-reg228; reg207=reg61*reg183; reg230=reg51-reg230; reg221=reg127-reg221; T reg240=pow(reg194,2);
    reg226=reg225+reg226; reg225=0.031249999999999996531*elem.pos(1)[2]; reg176=reg176/reg205; reg215=reg215+reg203; reg67=reg67/reg205;
    reg222=reg222-reg220; T reg241=0.373926375869000622*elem.pos(5)[0]; reg193=reg193+reg191; T reg242=0.031249999999999996531*elem.pos(1)[1]; T reg243=0.49910531322416709662*elem.pos(4)[0];
    T reg244=0.055456145913796350227*elem.pos(0)[0]; reg192=pow(reg192,0.5); reg156=reg156/reg202; reg177=reg177/reg202; T reg245=0.373926375869000622*elem.pos(5)[1];
    reg211=reg210+reg211; reg213=reg117-reg213; reg117=0.030992957979296029919*elem.pos(1)[1]; reg210=0.030992957979296029919*elem.pos(1)[0]; reg224=reg224-reg223;
    reg229=reg209+reg229; reg216=reg217-reg216; reg209=0.031249999999999996531*elem.pos(1)[0]; reg218=reg218+reg231; reg217=0.055456145913796350227*elem.pos(0)[1];
    T reg246=0.49910531322416709662*elem.pos(4)[1]; reg205=reg163/reg205; reg185=reg185/reg192; reg184=reg184/reg192; reg163=reg51*reg176;
    T reg247=reg127*reg67; T reg248=reg77*reg219; reg135=reg1*reg135; T reg249=0.24400704202070395239*elem.pos(3)[1]; reg243=reg243-reg244;
    T reg250=0.49910531322416726286*elem.pos(5)[0]; reg115=reg10*reg115; reg117=reg213+reg117; reg211=pow(reg211,0.5); reg213=0.24400704202070395239*elem.pos(3)[0];
    reg210=reg216+reg210; reg216=0.24400704202070395239*elem.pos(3)[2]; reg237=reg228+reg237; reg239=reg239-reg238; reg228=0.49910531322416726286*elem.pos(5)[2];
    reg137=reg81*reg137; reg165=reg42*reg165; T reg251=reg161*reg177; T reg252=reg18*reg156; reg202=reg174/reg202;
    reg246=reg246-reg217; reg174=0.43301408404140791412*elem.pos(0)[2]; T reg253=0.66356850115866743183*elem.pos(4)[2]; T reg254=0.49910531322416726286*elem.pos(5)[1]; reg177=reg81*reg177;
    reg156=reg42*reg156; reg207=reg124-reg207; reg233=reg18-reg233; reg42=pow(reg230,2); reg81=pow(reg221,2);
    reg176=reg1*reg176; reg222=reg222+reg241; reg1=0.24400704202070403823*elem.pos(1)[0]; reg67=reg10*reg67; reg10=0.24400704202070403823*elem.pos(1)[1];
    reg224=reg224+reg245; reg236=reg235+reg236; reg235=0.031249999999999996531*elem.pos(3)[2]; reg215=reg215-reg225; T reg255=0.43301408404140791412*elem.pos(0)[1];
    T reg256=0.66356850115866743183*elem.pos(4)[1]; T reg257=0.24400704202070403823*elem.pos(1)[2]; T reg258=0.43301408404140791412*elem.pos(0)[0]; reg197=reg197+reg232; T reg259=0.66356850115866743183*elem.pos(4)[0];
    T reg260=reg199*reg229; T reg261=pow(reg212,2); reg193=reg193-reg242; T reg262=0.031249999999999996531*elem.pos(3)[1]; reg240=reg226+reg240;
    reg234=reg161-reg234; reg226=0.031249999999999996531*elem.pos(3)[0]; reg218=reg218-reg209; T reg263=reg198*reg229; T reg264=pow(reg207,2);
    T reg265=reg21*reg205; T reg266=pow(reg233,2); T reg267=reg106*reg202; reg42=reg81+reg42; reg176=reg67+reg176;
    reg156=reg177+reg156; reg216=reg237+reg216; reg240=pow(reg240,0.5); reg67=0.030992957979296040822*elem.pos(3)[1]; reg261=reg236+reg261;
    reg10=reg224+reg10; reg81=0.28124999999999993755*elem.pos(7)[2]; reg213=reg210+reg213; reg177=0.055000000000000010008*elem.pos(0)[0]; reg210=0.26428425057933379666*elem.pos(4)[1];
    reg224=0.26428425057933379666*elem.pos(4)[0]; reg239=reg239+reg228; reg263=reg126-reg263; reg165=reg137+reg165; reg123=reg106*reg123;
    reg106=0.37392637586900058451*elem.pos(7)[2]; reg137=0.055456145913796350227*elem.pos(1)[2]; reg236=0.37392637586900058451*elem.pos(7)[0]; reg260=reg148-reg260; reg237=reg178*reg229;
    reg252=reg251+reg252; reg202=reg154*reg202; reg215=reg215-reg235; reg253=reg174+reg253; reg163=reg247+reg163;
    reg192=reg190/reg192; reg174=0.055000000000000010008*elem.pos(0)[1]; reg258=reg259+reg258; reg190=reg108*reg185; reg247=reg107*reg184;
    reg248=reg154-reg248; reg143=reg21*reg143; reg135=reg115+reg135; reg21=0.28124999999999993755*elem.pos(7)[1]; reg249=reg117+reg249;
    reg115=pow(reg234,2); reg117=0.28124999999999993755*elem.pos(7)[0]; reg193=reg193-reg262; reg243=reg243+reg250; reg251=0.055456145913796350227*elem.pos(1)[0];
    reg259=0.055456145913796350227*elem.pos(1)[1]; reg218=reg218-reg226; reg188=reg188/reg211; T reg268=0.37392637586900058451*elem.pos(7)[1]; reg189=reg189/reg211;
    T reg269=0.030992957979296040822*elem.pos(3)[2]; T reg270=0.26428425057933373015*elem.pos(5)[2]; reg256=reg255+reg256; reg1=reg222+reg1; reg246=reg246+reg254;
    reg222=0.030992957979296040822*elem.pos(3)[0]; reg166=reg108*reg166; reg164=reg107*reg164; reg107=0.26428425057933373015*elem.pos(5)[1]; reg205=reg124*reg205;
    reg108=0.26428425057933379666*elem.pos(4)[2]; reg255=0.055000000000000010008*elem.pos(0)[2]; reg185=reg126*reg185; T reg271=0.26428425057933373015*elem.pos(5)[0]; reg184=reg148*reg184;
    reg257=reg197+reg257; reg197=0.28125000000000003123*elem.pos(6)[0]; reg269=reg257+reg269; reg218=reg117+reg218; reg117=0.0070438540862036428341*elem.pos(3)[1];
    reg246=reg246-reg259; reg107=reg256-reg107; reg205=reg163+reg205; reg265=reg176+reg265; reg163=0.14892637586900062074*elem.pos(6)[2];
    reg143=reg135+reg143; reg216=reg106+reg216; reg106=reg127*reg189; reg135=reg51*reg188; reg176=0.14892637586900065821*elem.pos(7)[2];
    reg211=reg195/reg211; reg195=0.28125000000000003123*elem.pos(6)[1]; reg193=reg21+reg193; reg189=reg6*reg189; reg188=reg37*reg188;
    reg21=0.0070438540862036428341*elem.pos(0)[0]; reg256=0.063394686775832778473*elem.pos(4)[0]; reg271=reg258-reg271; reg255=reg255-reg108; reg257=0.66356850115866749835*elem.pos(5)[2];
    reg258=0.054999999999999990659*elem.pos(1)[0]; T reg272=0.0070438540862036428341*elem.pos(0)[1]; T reg273=0.063394686775832778473*elem.pos(4)[1]; T reg274=0.054999999999999990659*elem.pos(1)[1]; reg261=pow(reg261,0.5);
    reg200=reg200/reg240; reg201=reg201/reg240; reg237=reg122-reg237; T reg275=pow(reg260,2); T reg276=pow(reg263,2);
    T reg277=0.063394686775832778473*elem.pos(4)[2]; reg177=reg177-reg224; T reg278=0.66356850115866749835*elem.pos(5)[0]; reg215=reg81+reg215; reg81=0.28125000000000003123*elem.pos(6)[2];
    T reg279=0.0070438540862036428341*elem.pos(0)[2]; reg213=reg236+reg213; reg236=0.14892637586900062074*elem.pos(6)[0]; reg174=reg174-reg210; reg239=reg239-reg137;
    T reg280=0.0070438540862036428341*elem.pos(3)[2]; reg123=reg165+reg123; reg202=reg252+reg202; reg165=0.66356850115866749835*elem.pos(5)[1]; reg267=reg156+reg267;
    reg264=reg42+reg264; reg67=reg10+reg67; reg10=0.14892637586900065821*elem.pos(7)[0]; reg270=reg253-reg270; reg42=0.054999999999999990659*elem.pos(1)[2];
    reg222=reg1+reg222; reg168=reg37*reg168; reg145=reg6*reg145; reg1=0.0070438540862036428341*elem.pos(3)[0]; reg243=reg243-reg251;
    reg249=reg268+reg249; reg6=0.14892637586900062074*elem.pos(6)[1]; reg37=pow(reg248,2); reg156=reg7*reg192; reg247=reg190+reg247;
    reg266=reg115+reg266; reg115=0.14892637586900065821*elem.pos(7)[1]; reg192=reg122*reg192; reg184=reg185+reg184; reg72=reg7*reg72;
    reg164=reg166+reg164; reg7=0.030992957979296029919*elem.pos(2)[2]; reg274=reg107+reg274; reg107=0.054999999999999990659*elem.pos(3)[1]; reg166=0.031249999999999996531*elem.pos(2)[2];
    reg215=reg215+reg81; reg275=reg276+reg275; reg185=pow(reg237,2); reg190=0.084284250579333737197*elem.pos(4)[1]; reg252=0.054999999999999990659*elem.pos(0)[1];
    reg253=0.063394686775832799587*elem.pos(5)[1]; reg273=reg273-reg272; reg193=reg193+reg195; reg268=0.031249999999999996531*elem.pos(2)[1]; reg6=reg249-reg6;
    reg249=0.030992957979296029919*elem.pos(2)[1]; reg276=0.43301408404140806645*elem.pos(1)[1]; reg174=reg174+reg165; reg67=reg67-reg115; T reg281=0.373926375869000622*elem.pos(6)[1];
    T reg282=0.063394686775832778473*elem.pos(7)[1]; reg246=reg246-reg117; reg163=reg216-reg163; reg255=reg255+reg257; reg202=reg123*reg202;
    reg256=reg256-reg21; reg123=0.063394686775832799587*elem.pos(5)[0]; reg173=reg111*reg173; reg172=reg69*reg172; reg216=0.030992957979296029919*elem.pos(2)[0];
    reg236=reg213-reg236; reg213=0.063394686775832778473*elem.pos(7)[0]; T reg283=0.054999999999999990659*elem.pos(3)[2]; reg42=reg270+reg42; reg265=reg162*reg265;
    reg205=reg143*reg205; reg264=pow(reg264,0.5); reg243=reg243-reg1; reg143=0.031249999999999996531*elem.pos(2)[0]; reg218=reg218+reg197;
    reg177=reg177+reg278; reg162=0.43301408404140806645*elem.pos(1)[0]; reg277=reg277-reg279; reg270=0.063394686775832799587*elem.pos(5)[2]; T reg284=0.373926375869000622*elem.pos(6)[0];
    reg222=reg222-reg10; reg111=reg111*reg201; reg69=reg69*reg200; reg72=reg164+reg72; reg192=reg184+reg192;
    reg204=reg204/reg261; reg196=reg196/reg261; reg240=reg194/reg240; reg267=reg141*reg267; reg141=0.43301408404140806645*elem.pos(1)[2];
    reg201=reg18*reg201; reg200=reg161*reg200; reg156=reg247+reg156; reg135=reg106+reg135; reg106=0.084284250579333737197*elem.pos(4)[2];
    reg164=0.063394686775832778473*elem.pos(7)[2]; reg184=0.373926375869000622*elem.pos(6)[2]; reg269=reg269-reg176; reg258=reg271+reg258; reg194=0.054999999999999990659*elem.pos(3)[0];
    reg247=0.054999999999999990659*elem.pos(0)[0]; reg271=0.084284250579333737197*elem.pos(4)[0]; reg37=reg266+reg37; reg188=reg189+reg188; reg189=reg46*reg211;
    reg266=0.054999999999999990659*elem.pos(0)[2]; reg168=reg145+reg168; reg158=reg46*reg158; reg211=reg124*reg211; reg239=reg239-reg280;
    reg46=0.033568501158667511326*elem.pos(5)[2]; reg277=reg277+reg270; reg145=0.0070438540862036428341*elem.pos(1)[2]; reg211=reg135+reg211; reg189=reg188+reg189;
    reg106=reg266+reg106; reg135=0.24400704202070403823*elem.pos(2)[0]; reg111=reg69+reg111; reg69=reg154*reg240; reg188=0.084284250579333737197*elem.pos(7)[0];
    reg266=0.0069859159585920716348*elem.pos(3)[1]; reg240=reg70*reg240; reg243=reg213+reg243; reg213=0.063394686775832799587*elem.pos(6)[0]; reg190=reg252+reg190;
    reg252=0.0069859159585920716348*elem.pos(0)[1]; T reg285=0.033568501158667519769*elem.pos(4)[1]; T reg286=0.0070438540862036428341*elem.pos(1)[1]; reg273=reg273+reg253; T reg287=0.0069859159585920716348*elem.pos(0)[2];
    reg156=reg175*reg156; reg249=reg6+reg249; reg276=reg174+reg276; reg194=reg258+reg194; reg173=reg172+reg173;
    reg89=reg70*reg89; reg193=reg193-reg268; reg158=reg168+reg158; reg201=reg200+reg201; reg192=reg72*reg192;
    reg185=reg275+reg185; reg265=reg205-reg265; reg283=reg42+reg283; reg221=reg221/reg264; reg218=reg218-reg143;
    reg230=reg230/reg264; reg6=0.084284250579333737197*elem.pos(7)[2]; reg246=reg282+reg246; reg42=0.063394686775832799587*elem.pos(6)[1]; reg70=0.063394686775832799587*elem.pos(6)[2];
    reg239=reg164+reg239; reg72=0.084284250579333737197*elem.pos(7)[1]; reg247=reg271+reg247; reg164=0.033568501158667511326*elem.pos(5)[0]; reg168=0.0069859159585920716348*elem.pos(0)[0];
    reg172=0.033568501158667519769*elem.pos(4)[0]; reg174=0.24400704202070403823*elem.pos(2)[2]; reg269=reg269+reg184; reg7=reg163+reg7; reg163=0.033568501158667511326*elem.pos(5)[1];
    reg107=reg274+reg107; reg37=pow(reg37,0.5); reg162=reg177+reg162; reg175=0.0069859159585920716348*elem.pos(3)[0]; reg222=reg222+reg284;
    reg215=reg215-reg166; reg177=0.033568501158667519769*elem.pos(4)[2]; reg131=reg83*reg131; reg171=reg150*reg171; reg267=reg202-reg267;
    reg200=0.0069859159585920716348*elem.pos(3)[2]; reg202=reg126*reg204; reg205=reg148*reg196; reg261=reg212/reg261; reg67=reg67+reg281;
    reg212=0.0070438540862036428341*elem.pos(1)[0]; reg141=reg255+reg141; reg204=reg83*reg204; reg196=reg150*reg196; reg83=0.24400704202070403823*elem.pos(2)[1];
    reg216=reg236+reg216; reg256=reg256+reg123; reg150=0.033568501158667511326*elem.pos(6)[1]; reg107=reg72+reg107; reg249=reg267*reg249;
    reg72=0.084284250579333745647*elem.pos(5)[2]; reg218=reg218*reg265; reg156=reg192-reg156; reg135=reg222+reg135; reg287=reg287-reg177;
    reg193=reg265*reg193; reg216=reg216*reg267; reg83=reg67+reg83; reg67=0.033568501158667519769*elem.pos(7)[1]; reg192=0.0070438540862036428341*elem.pos(2)[1];
    reg222=0.0069859159585920691772*elem.pos(1)[2]; reg236=0.0070438540862036428341*elem.pos(2)[0]; reg246=reg246+reg42; reg243=reg243+reg213; reg200=reg141+reg200;
    reg171=reg131+reg171; reg169=reg114*reg169; reg205=reg202+reg205; reg131=reg122*reg261; reg196=reg204+reg196;
    reg261=reg114*reg261; reg114=0.033568501158667519769*elem.pos(7)[2]; reg256=reg256-reg212; reg141=0.055456145913796350227*elem.pos(3)[0]; reg202=0.033568501158667511326*elem.pos(6)[2];
    reg283=reg6+reg283; reg181=reg76*reg181; reg180=reg84*reg180; reg127=reg127*reg221; reg51=reg51*reg230;
    reg264=reg207/reg264; reg221=reg76*reg221; reg230=reg84*reg230; reg6=0.0070438540862036428341*elem.pos(2)[2]; reg239=reg239+reg70;
    reg215=reg265*reg215; reg164=reg247-reg164; reg76=0.0069859159585920691772*elem.pos(1)[0]; reg84=0.084284250579333745647*elem.pos(5)[0]; reg168=reg168-reg172;
    reg174=reg269+reg174; reg7=reg267*reg7; reg234=reg234/reg37; reg233=reg233/reg37; reg211=reg158*reg211;
    reg189=reg179*reg189; reg46=reg106-reg46; reg266=reg276+reg266; reg194=reg188+reg194; reg273=reg273-reg286;
    reg106=0.055456145913796350227*elem.pos(3)[1]; reg158=0.033568501158667511326*elem.pos(6)[0]; reg163=reg190-reg163; reg179=0.0069859159585920691772*elem.pos(1)[1]; reg252=reg252-reg285;
    reg188=0.084284250579333745647*elem.pos(5)[1]; reg175=reg162+reg175; reg162=0.033568501158667519769*elem.pos(7)[0]; reg240=reg111+reg240; reg277=reg277-reg145;
    reg69=reg201+reg69; reg185=pow(reg185,0.5); reg89=reg173+reg89; reg111=0.055456145913796350227*elem.pos(3)[2]; reg173=0.0069859159585920691772*elem.pos(2)[2];
    reg190=0.49910531322416709662*elem.pos(7)[2]; reg7=0.12345679012345679715*reg7; reg201=0.084284250579333745647*elem.pos(6)[2]; reg200=reg200-reg114; reg266=reg266-reg67;
    reg204=0.084284250579333745647*elem.pos(6)[1]; reg174=reg156*reg174; reg207=0.055000000000000010008*elem.pos(1)[2]; reg247=0.49910531322416709662*elem.pos(7)[1]; reg255=0.055000000000000010008*elem.pos(1)[1];
    reg215=0.19753086419753085323*reg215; reg150=reg107-reg150; reg107=0.0069859159585920691772*elem.pos(2)[1]; reg252=reg252+reg188; reg202=reg283-reg202;
    reg273=reg273-reg106; reg239=reg239-reg6; reg277=reg277-reg111; reg258=0.43301408404140791412*elem.pos(3)[2]; reg287=reg287+reg72;
    reg222=reg46+reg222; reg179=reg163+reg179; reg46=0.43301408404140791412*elem.pos(3)[1]; reg256=reg256-reg141; reg186=reg87*reg186;
    reg187=reg147*reg187; reg161=reg161*reg234; reg18=reg18*reg233; reg37=reg248/reg37; reg163=0.49910531322416709662*elem.pos(7)[0];
    reg234=reg87*reg234; reg233=reg147*reg233; reg243=reg243-reg236; reg189=reg211-reg189; reg168=reg168+reg84;
    reg87=0.055000000000000010008*elem.pos(1)[0]; reg267=0.12345679012345679715*reg267; reg158=reg194-reg158; reg261=reg196+reg261; reg131=reg205+reg131;
    reg169=reg171+reg169; reg263=reg263/reg185; reg147=0.0069859159585920691772*elem.pos(2)[0]; reg260=reg260/reg185; reg69=reg89*reg69;
    reg240=reg45*reg240; reg45=0.084284250579333745647*elem.pos(6)[0]; reg175=reg175-reg162; reg51=reg127+reg51; reg124=reg124*reg264;
    reg61=reg103*reg61; reg230=reg221+reg230; reg246=reg246-reg192; reg264=reg103*reg264; reg83=reg156*reg83;
    reg180=reg181+reg180; reg249=0.12345679012345679715*reg249; reg193=0.19753086419753085323*reg193; reg76=reg164+reg76; reg89=0.43301408404140791412*elem.pos(3)[0];
    reg265=0.19753086419753085323*reg265; reg135=reg135*reg156; reg218=0.19753086419753085323*reg218; reg216=0.12345679012345679715*reg216; reg199=reg170*reg199;
    reg187=reg186+reg187; reg239=reg189*reg239; reg126=reg126*reg263; reg124=reg51+reg124; reg256=reg163+reg256;
    reg148=reg148*reg260; reg185=reg237/reg185; reg51=0.055000000000000010008*elem.pos(2)[0]; reg175=reg175+reg45; reg263=reg19*reg263;
    reg200=reg200+reg201; reg103=0.055000000000000010008*elem.pos(2)[2]; reg61=reg180+reg61; reg89=reg76+reg89; reg76=0.66356850115866743183*elem.pos(7)[0];
    reg7=reg215+reg7; reg233=reg234+reg233; reg127=reg112*reg37; reg173=reg202+reg173; reg37=reg154*reg37;
    reg154=0.49910531322416726286*elem.pos(6)[0]; reg18=reg161+reg18; reg87=reg168+reg87; reg174=0.12345679012345679715*reg174; reg161=0.055000000000000010008*elem.pos(3)[0];
    reg261=reg182*reg261; reg264=reg230+reg264; reg131=reg169*reg131; reg77=reg112*reg77; reg198=reg19*reg198;
    reg19=0.49910531322416726286*elem.pos(6)[1]; reg273=reg247+reg273; reg243=reg243*reg189; reg112=0.66356850115866743183*elem.pos(7)[1]; reg135=0.12345679012345679715*reg135;
    reg258=reg222+reg258; reg156=0.12345679012345679715*reg156; reg267=reg265+reg267; reg163=0.66356850115866743183*elem.pos(7)[2]; reg46=reg179+reg46;
    reg216=reg218+reg216; reg107=reg150+reg107; reg150=0.055000000000000010008*elem.pos(2)[1]; reg164=0.49910531322416726286*elem.pos(6)[2]; reg266=reg266+reg204;
    reg83=0.12345679012345679715*reg83; reg249=reg193+reg249; reg240=reg69-reg240; reg246=reg189*reg246; reg69=0.055000000000000010008*elem.pos(3)[1];
    reg255=reg252+reg255; reg260=reg170*reg260; reg168=0.055000000000000010008*elem.pos(3)[2]; reg277=reg190+reg277; reg207=reg287+reg207;
    reg147=reg158+reg147; reg83=reg249+reg83; reg37=reg18+reg37; reg264=reg183*reg264; reg189=0.12345679012345679715*reg189;
    reg135=reg216+reg135; reg89=reg76+reg89; reg18=0.26428425057933373015*elem.pos(6)[0]; reg77=reg187+reg77; reg258=reg163+reg258;
    reg76=0.26428425057933373015*elem.pos(6)[2]; reg239=0.12345679012345679715*reg239; reg168=reg207+reg168; reg174=reg7+reg174; reg7=0.26428425057933379666*elem.pos(7)[2];
    reg158=0.055456145913796350227*elem.pos(2)[0]; reg256=reg256+reg154; reg150=reg266+reg150; reg147=reg147*reg240; reg246=0.12345679012345679715*reg246;
    reg103=reg200+reg103; reg69=reg255+reg69; reg122=reg122*reg185; reg260=reg263+reg260; reg148=reg126+reg148;
    reg185=reg142*reg185; reg126=0.26428425057933379666*elem.pos(7)[1]; reg51=reg175+reg51; reg178=reg142*reg178; reg199=reg198+reg199;
    reg277=reg277+reg164; reg142=0.055456145913796350227*elem.pos(2)[2]; reg163=0.26428425057933373015*elem.pos(6)[1]; reg46=reg112+reg46; reg161=reg87+reg161;
    reg107=reg240*reg107; reg87=0.26428425057933379666*elem.pos(7)[0]; reg261=reg131-reg261; reg124=reg61*reg124; reg173=reg240*reg173;
    reg156=reg267+reg156; reg127=reg233+reg127; reg243=0.12345679012345679715*reg243; reg61=0.055456145913796350227*elem.pos(2)[1]; reg273=reg273+reg19;
    reg168=reg168-reg7; reg112=0.66356850115866749835*elem.pos(6)[2]; reg256=reg256-reg158; reg131=0.054999999999999990659*elem.pos(2)[2]; reg76=reg258-reg76;
    reg173=0.077160493827160489544*reg173; reg51=reg51*reg261; reg243=reg135+reg243; reg277=reg277-reg142; reg103=reg261*reg103;
    reg147=0.077160493827160489544*reg147; reg135=0.66356850115866749835*elem.pos(6)[1]; reg69=reg69-reg126; reg185=reg260+reg185; reg122=reg148+reg122;
    reg178=reg199+reg178; reg150=reg261*reg150; reg148=0.66356850115866749835*elem.pos(6)[0]; reg161=reg161-reg87; reg107=0.077160493827160489544*reg107;
    reg240=0.077160493827160489544*reg240; reg246=reg83+reg246; reg189=reg156+reg189; reg83=0.054999999999999990659*elem.pos(2)[1]; reg127=reg219*reg127;
    reg37=reg77*reg37; reg163=reg46-reg163; reg46=0.054999999999999990659*elem.pos(2)[0]; reg239=reg174+reg239; reg18=reg89-reg18;
    reg264=reg124-reg264; reg273=reg273-reg61; reg77=0.43301408404140806645*elem.pos(2)[1]; reg147=reg243+reg147; reg69=reg69+reg135;
    reg273=reg264*reg273; reg277=reg264*reg277; reg185=reg229*reg185; reg261=0.077160493827160489544*reg261; reg240=reg189+reg240;
    reg83=reg163+reg83; reg256=reg256*reg264; reg103=0.077160493827160489544*reg103; reg131=reg76+reg131; reg76=0.43301408404140806645*elem.pos(2)[2];
    reg150=0.077160493827160489544*reg150; reg122=reg178*reg122; reg89=0.43301408404140806645*elem.pos(2)[0]; reg161=reg161+reg148; reg107=reg246+reg107;
    reg51=0.077160493827160489544*reg51; reg173=reg239+reg173; reg168=reg168+reg112; reg127=reg37-reg127; reg46=reg18+reg46;
    reg273=0.12345679012345679715*reg273; reg76=reg168+reg76; reg150=reg107+reg150; reg131=reg127*reg131; reg261=reg240+reg261;
    reg264=0.12345679012345679715*reg264; reg89=reg161+reg89; reg51=reg147+reg51; reg46=reg46*reg127; reg103=reg173+reg103;
    reg77=reg69+reg77; reg185=reg122-reg185; reg256=0.12345679012345679715*reg256; reg83=reg127*reg83; reg277=0.12345679012345679715*reg277;
    reg83=0.077160493827160489544*reg83; reg277=reg103+reg277; reg89=reg89*reg185; reg264=reg261+reg264; reg77=reg185*reg77;
    reg256=reg51+reg256; reg131=0.077160493827160489544*reg131; reg273=reg150+reg273; reg127=0.077160493827160489544*reg127; reg76=reg185*reg76;
    reg46=0.077160493827160489544*reg46; reg46=reg256+reg46; reg76=0.077160493827160489544*reg76; reg185=0.077160493827160489544*reg185; reg127=reg264+reg127;
    reg131=reg277+reg131; reg77=0.077160493827160489544*reg77; reg83=reg273+reg83; reg89=0.077160493827160489544*reg89; reg185=reg127+reg185;
    reg77=reg83+reg77; reg89=reg46+reg89; reg76=reg131+reg76; res[0]=reg89/reg185; res[1]=reg77/reg185;
    res[2]=reg76/reg185;

    return res;
}
}
#endif // LMT_QUAD_42
