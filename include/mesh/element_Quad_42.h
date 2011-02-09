#ifndef LMT_QUAD_42
#define LMT_QUAD_42
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
    T reg5=reg4*reg2; reg3=reg4*reg3; T reg6=reg0-var_inter[0]; T reg7=reg1*var_inter[0]; T reg8=reg1*reg0;
    reg5=reg8+reg5; reg3=reg3-reg7; reg0=reg0*var_inter[0]; T reg9=reg4*reg6; reg9=reg9-reg0;
    T reg10=4.5*reg5; reg8=reg8*reg4; reg3=13.5*reg3; reg7=reg7*reg4; reg6=reg1*reg6;
    T reg11=1-var_inter[1]; reg6=reg6-reg0; T reg12=reg11*reg10; T reg13=reg11*reg3; reg9=13.5*reg9;
    reg4=reg0*reg4; reg7=13.5*reg7; reg8=4.5*reg8; T reg14=reg11*reg9; T reg15=pos_nodes[4][1]*reg13;
    T reg16=pos_nodes[0][0]*reg12; T reg17=pos_nodes[0][1]*reg12; T reg18=reg8*pos_nodes[0][1]; T reg19=pos_nodes[4][1]*reg7; T reg20=pos_nodes[4][0]*reg7;
    reg6=4.5*reg6; T reg21=reg8*pos_nodes[0][0]; T reg22=pos_nodes[4][0]*reg13; reg4=13.5*reg4; reg0=reg1*reg0;
    reg1=reg4*pos_nodes[5][0]; T reg23=reg11*reg7; T reg24=reg11*reg6; T reg25=reg11*reg8; reg20=reg21+reg20;
    reg21=reg4*pos_nodes[5][1]; reg0=4.5*reg0; reg16=reg22-reg16; reg19=reg18+reg19; reg18=pos_nodes[5][0]*reg14;
    reg17=reg15-reg17; reg15=pos_nodes[5][1]*reg14; reg22=reg25*pos_nodes[0][1]; T reg26=pos_nodes[1][0]*reg24; reg20=reg1-reg20;
    reg1=pos_nodes[1][0]*reg0; T reg27=pos_nodes[1][1]*reg0; reg19=reg21-reg19; reg21=reg25*pos_nodes[0][0]; T reg28=reg23*pos_nodes[4][0];
    reg18=reg16-reg18; reg15=reg17-reg15; reg16=reg4*reg11; reg17=pos_nodes[4][1]*reg23; T reg29=pos_nodes[1][1]*reg24;
    T reg30=var_inter[1]*reg10; reg27=reg19-reg27; reg19=pos_nodes[3][1]*reg8; reg28=reg21+reg28; reg21=reg16*pos_nodes[5][0];
    T reg31=pos_nodes[3][0]*reg8; reg1=reg20-reg1; reg29=reg15+reg29; reg15=reg16*pos_nodes[5][1]; reg17=reg22+reg17;
    reg20=pos_nodes[3][1]*reg30; reg3=var_inter[1]*reg3; reg11=reg11*reg0; reg22=pos_nodes[3][0]*reg30; reg26=reg18+reg26;
    reg21=reg28-reg21; reg18=reg11*pos_nodes[1][0]; reg20=reg29-reg20; reg28=pos_nodes[7][1]*reg3; reg29=reg11*pos_nodes[1][1];
    reg15=reg17-reg15; reg17=reg8*var_inter[1]; reg9=var_inter[1]*reg9; reg22=reg26-reg22; reg26=pos_nodes[7][0]*reg3;
    T reg32=reg7*pos_nodes[7][1]; reg19=reg27+reg19; reg31=reg1+reg31; reg1=reg7*pos_nodes[7][0]; reg27=pos_nodes[6][1]*reg9;
    reg28=reg20+reg28; reg20=reg4*pos_nodes[6][1]; reg32=reg19+reg32; reg29=reg15+reg29; reg15=pos_nodes[3][1]*reg17;
    reg19=reg7*var_inter[1]; reg6=var_inter[1]*reg6; reg26=reg22+reg26; reg22=pos_nodes[6][0]*reg9; reg1=reg31+reg1;
    reg31=reg4*pos_nodes[6][0]; reg18=reg21+reg18; reg21=pos_nodes[3][0]*reg17; T reg33=reg4*var_inter[1]; reg15=reg29+reg15;
    reg29=reg19*pos_nodes[7][1]; T reg34=pos_nodes[2][1]*reg0; reg20=reg32-reg20; reg22=reg26-reg22; reg26=pos_nodes[2][0]*reg6;
    reg32=pos_nodes[2][1]*reg6; reg31=reg1-reg31; reg1=pos_nodes[2][0]*reg0; reg21=reg18+reg21; reg27=reg28-reg27;
    reg18=reg19*pos_nodes[7][0]; reg28=var_inter[1]*reg0; reg32=reg27+reg32; reg29=reg15+reg29; reg34=reg20+reg34;
    reg1=reg31+reg1; reg15=reg33*pos_nodes[6][1]; reg26=reg22+reg26; reg20=reg33*pos_nodes[6][0]; reg18=reg21+reg18;
    reg15=reg29-reg15; reg21=pos_nodes[2][1]*reg28; reg22=reg26*reg34; reg27=reg28*pos_nodes[2][0]; reg20=reg18-reg20;
    reg18=reg1*reg32; reg21=reg15+reg21; reg18=reg22-reg18; reg27=reg20+reg27; reg27=pos[0]-reg27;
    reg21=pos[1]-reg21; reg15=reg34/reg18; reg20=reg32/reg18; reg29=reg1/reg18; reg18=reg26/reg18;
    reg15=reg27*reg15; reg29=reg21*reg29; reg20=reg27*reg20; reg18=reg21*reg18; var_inter[0]+=reg15-reg29;
    var_inter[1]+=reg18-reg20;

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
    reg5=var_inter[1]*reg5; res[7]=reg5; reg1=reg1*var_inter[1]; res[2]=reg1; res[6]=-reg3;
    res[5]=-reg2;

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
    T reg0=0.66666666666666662966-var_inter[0]; T reg1=0.33333333333333331483-var_inter[0]; T reg2=1-var_inter[0]; T reg3=reg0-var_inter[0]; T reg4=reg1+reg0;
    T reg5=var_inter[0]*reg0; reg3=reg2*reg3; T reg6=reg2*reg4; T reg7=reg1-var_inter[0]; T reg8=reg1*reg0;
    T reg9=reg2*reg7; reg3=reg3-reg5; reg6=reg8+reg6; reg1=var_inter[0]*reg1; T reg10=1-var_inter[1];
    reg7=reg0*reg7; T reg11=4.5*reg6; reg3=13.5*reg3; reg9=reg9-reg1; reg9=13.5*reg9;
    T reg12=reg10*reg3; reg7=reg7-reg1; T reg13=reg10*reg11; T reg14=reg10*reg9; T reg15=elem.pos(0)[1]*reg13;
    T reg16=elem.pos(4)[1]*reg12; reg7=4.5*reg7; T reg17=elem.pos(0)[0]*reg13; T reg18=elem.pos(4)[0]*reg12; reg16=reg16-reg15;
    T reg19=elem.pos(0)[2]*reg13; T reg20=elem.pos(5)[0]*reg14; reg18=reg18-reg17; reg12=elem.pos(4)[2]*reg12; T reg21=reg10*reg7;
    T reg22=elem.pos(5)[1]*reg14; T reg23=reg21*elem.pos(1)[1]; reg22=reg16-reg22; reg20=reg18-reg20; reg16=var_inter[1]*reg11;
    reg14=elem.pos(5)[2]*reg14; reg12=reg12-reg19; reg18=reg21*elem.pos(1)[0]; reg21=reg21*elem.pos(1)[2]; reg5=reg2*reg5;
    reg14=reg12-reg14; reg3=var_inter[1]*reg3; reg12=elem.pos(3)[0]*reg16; reg23=reg22+reg23; reg8=reg2*reg8;
    reg22=elem.pos(3)[1]*reg16; reg18=reg20+reg18; reg9=var_inter[1]*reg9; reg20=elem.pos(3)[2]*reg16; T reg24=elem.pos(7)[1]*reg3;
    reg23=reg23-reg22; reg5=13.5*reg5; reg21=reg14+reg21; reg2=reg2*reg1; reg14=elem.pos(7)[0]*reg3;
    reg8=4.5*reg8; reg18=reg18-reg12; T reg25=elem.pos(4)[1]*reg5; reg3=elem.pos(7)[2]*reg3; reg21=reg21-reg20;
    T reg26=elem.pos(0)[0]*reg8; T reg27=elem.pos(4)[0]*reg5; T reg28=elem.pos(6)[1]*reg9; reg24=reg23+reg24; reg1=reg0*reg1;
    reg7=var_inter[1]*reg7; reg0=elem.pos(6)[0]*reg9; reg14=reg18+reg14; reg2=13.5*reg2; reg18=elem.pos(0)[1]*reg8;
    reg23=elem.pos(4)[2]*reg5; reg1=4.5*reg1; reg9=elem.pos(6)[2]*reg9; reg3=reg21+reg3; reg21=elem.pos(5)[1]*reg2;
    T reg29=reg27+reg26; T reg30=elem.pos(5)[0]*reg2; T reg31=elem.pos(2)[0]*reg7; reg0=reg14-reg0; reg14=reg18+reg25;
    T reg32=elem.pos(0)[2]*reg8; reg28=reg24-reg28; reg24=elem.pos(2)[1]*reg7; T reg33=reg1*elem.pos(1)[0]; T reg34=elem.pos(5)[2]*reg2;
    T reg35=reg32+reg23; T reg36=reg30-reg29; T reg37=reg1*elem.pos(1)[1]; T reg38=reg21-reg14; reg7=elem.pos(2)[2]*reg7;
    reg0=reg31+reg0; reg9=reg3-reg9; reg24=reg28+reg24; reg38=reg38-reg37; reg3=pow(reg24,2);
    reg28=pow(reg0,2); reg31=elem.pos(3)[0]*reg8; T reg39=elem.pos(3)[1]*reg8; reg7=reg9+reg7; reg9=reg34-reg35;
    reg36=reg36-reg33; T reg40=reg1*elem.pos(1)[2]; reg36=reg31+reg36; reg31=reg5*elem.pos(7)[0]; reg9=reg9-reg40;
    T reg41=elem.pos(7)[1]*reg5; T reg42=pow(reg7,2); reg3=reg28+reg3; reg28=elem.pos(3)[2]*reg8; reg39=reg38+reg39;
    reg42=reg3+reg42; reg3=elem.pos(6)[0]*reg2; reg38=elem.pos(6)[1]*reg2; reg31=reg36+reg31; reg28=reg9+reg28;
    reg9=reg5*elem.pos(7)[2]; reg41=reg39+reg41; reg36=reg1*elem.pos(2)[0]; reg38=reg41-reg38; reg39=reg1*elem.pos(2)[1];
    reg41=reg2*elem.pos(6)[2]; reg9=reg28+reg9; reg3=reg31-reg3; reg42=pow(reg42,0.5); reg39=reg38+reg39;
    reg41=reg9-reg41; reg9=reg1*elem.pos(2)[2]; reg28=reg24/reg42; reg31=reg0/reg42; reg36=reg3+reg36;
    reg41=reg9+reg41; reg3=reg36*reg31; reg42=reg7/reg42; reg9=reg39*reg28; reg3=reg9+reg3;
    reg9=reg41*reg42; reg9=reg3+reg9; reg3=reg9*reg28; reg38=reg9*reg31; reg3=reg39-reg3;
    reg38=reg36-reg38; T reg43=reg9*reg42; T reg44=pow(reg38,2); reg43=reg41-reg43; T reg45=pow(reg3,2);
    reg45=reg44+reg45; reg44=pow(reg43,2); reg44=reg45+reg44; reg44=pow(reg44,0.5); reg3=reg3/reg44;
    reg38=reg38/reg44; reg45=reg24*reg3; reg36=reg36*reg38; reg28=reg24*reg28; reg38=reg0*reg38;
    reg31=reg0*reg31; reg44=reg43/reg44; reg3=reg39*reg3; reg45=reg38+reg45; reg41=reg41*reg44;
    reg36=reg3+reg36; reg28=reg31+reg28; reg42=reg7*reg42; reg44=reg7*reg44; reg41=reg36+reg41;
    reg44=reg45+reg44; reg42=reg28+reg42; reg0=reg9*reg44; reg3=reg41*reg42; reg0=reg3-reg0;
    return reg0;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Quad_42,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.74785275173800116902*elem.pos(4)[1]; T reg1=0.062499999999999993061*elem.pos(0)[0]; T reg2=0.48801408404140790478*elem.pos(0)[0]; T reg3=0.74785275173800116902*elem.pos(4)[0]; T reg4=1.8214212528966687488*elem.pos(0)[1];
    T reg5=0.48801408404140790478*elem.pos(0)[1]; T reg6=2.2214212528966688501*elem.pos(4)[1]; T reg7=1.6875*elem.pos(4)[0]; T reg8=0.062500000000000055511*elem.pos(0)[0]; T reg9=0.062500000000000055511*elem.pos(0)[1];
    T reg10=1.6875*elem.pos(4)[1]; T reg11=2.2214212528966688501*elem.pos(4)[0]; T reg12=1.8214212528966687488*elem.pos(0)[0]; T reg13=0.5624999999999998751*elem.pos(4)[1]; T reg14=0.062499999999999993061*elem.pos(0)[1];
    T reg15=0.5624999999999998751*elem.pos(4)[0]; reg4=reg6-reg4; reg6=1.6875*elem.pos(5)[1]; T reg16=reg9-reg10; T reg17=0.47857874710333128711*elem.pos(5)[1];
    T reg18=0.56250000000000006245*elem.pos(5)[0]; reg15=reg15-reg1; T reg19=0.29785275173800131643*elem.pos(4)[1]; T reg20=0.061985915958592081643*elem.pos(0)[1]; reg5=reg0+reg5;
    reg0=0.29785275173800124148*elem.pos(5)[1]; T reg21=0.47857874710333157733*elem.pos(4)[1]; T reg22=0.078578747103331282649*elem.pos(0)[1]; T reg23=0.061985915958592081643*elem.pos(0)[0]; T reg24=0.29785275173800131643*elem.pos(4)[0];
    reg12=reg11-reg12; reg11=0.47857874710333128711*elem.pos(5)[0]; T reg25=0.078578747103331282649*elem.pos(0)[0]; T reg26=reg8-reg7; T reg27=1.6875*elem.pos(5)[0];
    T reg28=0.47857874710333157733*elem.pos(4)[0]; reg2=reg3+reg2; reg3=0.29785275173800124148*elem.pos(5)[0]; T reg29=0.56250000000000006245*elem.pos(5)[1]; reg13=reg13-reg14;
    reg20=reg20-reg19; T reg30=0.28124999999999993755*elem.pos(4)[1]; T reg31=0.031249999999999996531*elem.pos(0)[1]; T reg32=0.061985915958592059837*elem.pos(1)[1]; reg5=reg0-reg5;
    reg25=reg28-reg25; reg11=reg12-reg11; reg0=0.37392637586900058451*elem.pos(4)[0]; reg12=0.24400704202070395239*elem.pos(0)[0]; reg28=0.031249999999999996531*elem.pos(0)[0];
    T reg33=0.28124999999999993755*elem.pos(4)[0]; T reg34=0.078578747103331214053*elem.pos(1)[0]; T reg35=2.2214212528966691402*elem.pos(5)[1]; reg23=reg23-reg24; reg22=reg21-reg22;
    reg21=0.74785275173800124399*elem.pos(5)[0]; reg13=reg29+reg13; T reg36=0.062499999999999993061*elem.pos(1)[1]; T reg37=0.24400704202070395239*elem.pos(0)[1]; T reg38=0.11091229182759281127*elem.pos(0)[1];
    T reg39=2.9946318793450032447*elem.pos(4)[1]; T reg40=0.078578747103331214053*elem.pos(1)[1]; reg17=reg4-reg17; reg16=reg16+reg6; reg4=0.062499999999999930604*elem.pos(1)[1];
    reg2=reg3-reg2; reg3=0.37392637586900058451*elem.pos(4)[1]; T reg41=0.061985915958592059837*elem.pos(1)[0]; T reg42=0.11091229182759281127*elem.pos(0)[0]; T reg43=2.2214212528966691402*elem.pos(5)[0];
    T reg44=0.74785275173800124399*elem.pos(5)[1]; T reg45=0.062499999999999993061*elem.pos(1)[0]; reg15=reg18+reg15; reg26=reg26+reg27; T reg46=0.062499999999999930604*elem.pos(1)[0];
    T reg47=2.9946318793450032447*elem.pos(4)[0]; reg20=reg44+reg20; T reg48=1.8214212528966690672*elem.pos(1)[0]; reg37=reg3+reg37; reg3=0.48801408404140790478*elem.pos(3)[1];
    T reg49=1.8214212528966687488*elem.pos(3)[1]; T reg50=0.48801408404140790478*elem.pos(3)[0]; T reg51=0.030992957979296040822*elem.pos(0)[0]; T reg52=0.14892637586900065821*elem.pos(4)[1]; reg34=reg11+reg34;
    reg11=1.8214212528966687488*elem.pos(3)[0]; reg40=reg17+reg40; reg32=reg5-reg32; reg5=0.030992957979296040822*elem.pos(0)[1]; reg17=0.14892637586900065821*elem.pos(4)[0];
    reg43=reg25-reg43; reg25=0.14892637586900062074*elem.pos(5)[1]; reg41=reg2-reg41; reg2=0.48801408404140807646*elem.pos(1)[1]; T reg53=reg45-reg15;
    T reg54=reg42-reg47; T reg55=2.9946318793450032447*elem.pos(5)[0]; T reg56=0.062500000000000055511*elem.pos(3)[1]; reg16=reg16-reg4; T reg57=reg38-reg39;
    T reg58=2.9946318793450032447*elem.pos(5)[1]; T reg59=0.062499999999999993061*elem.pos(3)[1]; T reg60=reg36-reg13; T reg61=0.062500000000000055511*elem.pos(3)[0]; reg26=reg26-reg46;
    T reg62=3.942126756372671509*elem.pos(4)[0]; T reg63=3.2322880886760779675*elem.pos(0)[0]; T reg64=0.28125000000000003123*elem.pos(5)[0]; reg33=reg33-reg28; T reg65=3.942126756372671509*elem.pos(4)[1];
    T reg66=3.2322880886760779675*elem.pos(0)[1]; reg35=reg22-reg35; reg22=1.8214212528966690672*elem.pos(1)[1]; reg23=reg21+reg23; T reg67=0.48801408404140807646*elem.pos(1)[0];
    T reg68=0.14892637586900062074*elem.pos(5)[0]; reg12=reg0+reg12; reg0=0.28125000000000003123*elem.pos(5)[1]; reg30=reg30-reg31; T reg69=0.062499999999999993061*elem.pos(3)[0];
    T reg70=0.13944558288274055635*elem.pos(0)[0]; T reg71=0.061985915958592081643*elem.pos(3)[1]; T reg72=0.84928425057933444099*elem.pos(4)[0]; reg25=reg37-reg25; reg54=reg54+reg55;
    reg37=0.055456145913796350227*elem.pos(0)[0]; T reg73=0.030992957979296029919*elem.pos(1)[1]; T reg74=0.031249999999999996531*elem.pos(1)[1]; T reg75=0.078578747103331282649*elem.pos(3)[1]; reg22=reg35+reg22;
    reg66=reg65-reg66; reg35=0.84928425057933392599*elem.pos(5)[1]; reg65=0.11091229182759258962*elem.pos(1)[0]; reg30=reg30+reg0; T reg76=0.078578747103331282649*elem.pos(3)[0];
    reg48=reg43+reg48; reg43=0.061985915958592081643*elem.pos(3)[0]; reg57=reg57+reg58; T reg77=0.11091229182759258962*elem.pos(1)[1]; T reg78=0.13944558288274055635*elem.pos(0)[1];
    T reg79=0.84928425057933444099*elem.pos(4)[1]; reg67=reg23+reg67; T reg80=0.49910531322416709662*elem.pos(4)[0]; reg63=reg62-reg63; reg2=reg20+reg2;
    reg62=0.84928425057933392599*elem.pos(5)[0]; reg50=reg41+reg50; reg26=reg26+reg61; reg41=1.6875*elem.pos(7)[0]; T reg81=2.2214212528966688501*elem.pos(7)[1];
    reg49=reg40-reg49; reg40=0.74785275173800116902*elem.pos(7)[1]; reg3=reg32+reg3; reg60=reg60-reg59; reg32=0.5624999999999998751*elem.pos(7)[1];
    reg16=reg16+reg56; T reg82=1.6875*elem.pos(7)[1]; T reg83=2.2214212528966688501*elem.pos(7)[0]; reg11=reg34-reg11; reg34=0.49910531322416709662*elem.pos(4)[1];
    T reg84=0.055456145913796350227*elem.pos(0)[1]; reg53=reg53-reg69; T reg85=0.5624999999999998751*elem.pos(7)[0]; reg68=reg12-reg68; reg12=0.030992957979296029919*elem.pos(1)[0];
    T reg86=0.373926375869000622*elem.pos(5)[0]; reg51=reg51-reg17; reg33=reg33+reg64; T reg87=0.031249999999999996531*elem.pos(1)[0]; reg5=reg5-reg52;
    T reg88=0.373926375869000622*elem.pos(5)[1]; T reg89=0.74785275173800116902*elem.pos(7)[0]; reg54=reg54-reg65; reg62=reg63-reg62; reg63=0.13944558288274043462*elem.pos(1)[0];
    reg16=reg16-reg82; T reg90=1.6875*elem.pos(6)[1]; reg35=reg66-reg35; reg66=0.13944558288274043462*elem.pos(1)[1]; T reg91=0.49910531322416726286*elem.pos(5)[0];
    reg80=reg80-reg37; reg85=reg53+reg85; reg53=0.56250000000000006245*elem.pos(6)[0]; T reg92=0.43301408404140791412*elem.pos(0)[1]; T reg93=0.66356850115866743183*elem.pos(4)[1];
    T reg94=0.29785275173800131643*elem.pos(7)[0]; reg43=reg43-reg67; reg26=reg26-reg41; reg78=reg79-reg78; reg79=3.942126756372672024*elem.pos(5)[1];
    reg70=reg72-reg70; reg33=reg33-reg87; reg72=0.43301408404140791412*elem.pos(0)[0]; T reg95=1.6875*elem.pos(6)[0]; T reg96=0.66356850115866743183*elem.pos(4)[0];
    T reg97=0.38036812065499675528*elem.pos(4)[0]; T reg98=0.014087708172407299745*elem.pos(0)[0]; T reg99=0.014087708172407299745*elem.pos(3)[1]; reg57=reg57-reg77; T reg100=3.942126756372672024*elem.pos(5)[0];
    T reg101=0.031249999999999996531*elem.pos(3)[0]; reg32=reg60+reg32; reg60=0.56250000000000006245*elem.pos(6)[1]; T reg102=0.38036812065499675528*elem.pos(4)[1]; T reg103=0.014087708172407299745*elem.pos(0)[1];
    T reg104=0.014087708172407299745*elem.pos(3)[0]; reg75=reg22-reg75; reg34=reg34-reg84; reg83=reg11+reg83; reg11=0.47857874710333128711*elem.pos(6)[0];
    reg22=0.29785275173800131643*elem.pos(7)[1]; reg71=reg71-reg2; reg40=reg3+reg40; reg3=0.29785275173800124148*elem.pos(6)[1]; T reg105=0.47857874710333157733*elem.pos(7)[0];
    reg76=reg48-reg76; reg81=reg49+reg81; reg48=0.47857874710333128711*elem.pos(6)[1]; reg49=0.24400704202070403823*elem.pos(1)[1]; reg89=reg50+reg89;
    reg50=0.29785275173800124148*elem.pos(6)[0]; reg5=reg5+reg88; reg73=reg25+reg73; reg25=0.24400704202070395239*elem.pos(3)[1]; T reg106=0.24400704202070403823*elem.pos(1)[0];
    reg51=reg51+reg86; reg12=reg68+reg12; reg68=0.24400704202070395239*elem.pos(3)[0]; T reg107=0.49910531322416726286*elem.pos(5)[1]; reg30=reg30-reg74;
    T reg108=0.031249999999999996531*elem.pos(3)[1]; T reg109=0.47857874710333157733*elem.pos(7)[1]; T reg110=0.28124999999999993755*elem.pos(7)[0]; T reg111=0.055000000000000010008*elem.pos(0)[1]; T reg112=0.26428425057933379666*elem.pos(4)[1];
    reg48=reg81-reg48; reg100=reg70-reg100; reg70=3.2322880886760785326*elem.pos(1)[0]; reg81=2.2214212528966691402*elem.pos(6)[1]; reg80=reg80+reg91;
    reg105=reg76+reg105; reg76=2.2214212528966691402*elem.pos(6)[0]; reg79=reg78-reg79; reg78=0.26428425057933373015*elem.pos(5)[0]; reg49=reg5+reg49;
    reg72=reg96+reg72; reg5=0.030992957979296040822*elem.pos(3)[1]; reg96=0.061985915958592059837*elem.pos(2)[1]; reg3=reg40-reg3; reg26=reg26+reg95;
    reg40=3.2322880886760785326*elem.pos(1)[1]; T reg113=0.062499999999999993061*elem.pos(2)[0]; T reg114=0.26428425057933379666*elem.pos(4)[0]; T reg115=0.055000000000000010008*elem.pos(0)[0]; T reg116=0.41055441711725952999*elem.pos(3)[1];
    reg66=reg35+reg66; reg109=reg75+reg109; reg106=reg51+reg106; reg35=0.030992957979296040822*elem.pos(3)[0]; reg51=0.37392637586900058451*elem.pos(7)[1];
    reg25=reg73+reg25; reg34=reg34+reg107; reg73=0.055456145913796350227*elem.pos(1)[1]; reg68=reg12+reg68; reg12=0.061985915958592059837*elem.pos(2)[0];
    reg50=reg89-reg50; reg75=0.37392637586900058451*elem.pos(7)[0]; reg89=0.41055441711725952999*elem.pos(3)[0]; reg43=reg43-reg94; reg63=reg62+reg63;
    reg62=0.74785275173800124399*elem.pos(6)[0]; reg33=reg33-reg101; T reg117=0.078578747103331214053*elem.pos(2)[1]; T reg118=0.74785275173800124399*elem.pos(6)[1]; T reg119=0.41055441711725952999*elem.pos(0)[0];
    T reg120=0.50071574942066619112*elem.pos(4)[0]; T reg121=reg103-reg102; T reg122=0.38036812065499675528*elem.pos(5)[1]; reg92=reg93+reg92; reg93=0.38036812065499675528*elem.pos(7)[0];
    reg32=reg32+reg60; T reg123=0.062499999999999930604*elem.pos(2)[1]; reg16=reg16+reg90; reg54=reg54+reg104; T reg124=0.062499999999999993061*elem.pos(2)[1];
    T reg125=0.28124999999999993755*elem.pos(7)[1]; T reg126=0.055456145913796350227*elem.pos(1)[0]; T reg127=0.26428425057933373015*elem.pos(5)[1]; reg30=reg30-reg108; reg85=reg85+reg53;
    T reg128=0.38036812065499675528*elem.pos(5)[0]; reg71=reg71-reg22; T reg129=reg98-reg97; T reg130=0.50071574942066619112*elem.pos(4)[1]; reg11=reg83-reg11;
    reg83=0.38036812065499675528*elem.pos(7)[1]; T reg131=0.41055441711725952999*elem.pos(0)[1]; T reg132=0.062499999999999930604*elem.pos(2)[0]; reg57=reg57+reg99; T reg133=0.078578747103331214053*elem.pos(2)[0];
    T reg134=0.14892637586900065821*elem.pos(7)[1]; reg115=reg115-reg114; T reg135=0.10787324362732864825*elem.pos(5)[1]; reg51=reg25+reg51; reg25=0.10787324362732871366*elem.pos(4)[0];
    reg131=reg130-reg131; reg130=0.14892637586900062074*elem.pos(6)[1]; T reg136=0.0070438540862036428341*elem.pos(0)[1]; T reg137=0.66356850115866749835*elem.pos(5)[0]; T reg138=0.01408770817240727159*elem.pos(1)[1];
    T reg139=0.10787324362732864825*elem.pos(5)[0]; reg119=reg120-reg119; reg120=0.017711911323922008951*elem.pos(0)[1]; T reg140=0.0070438540862036428341*elem.pos(0)[0]; T reg141=0.063394686775832778473*elem.pos(4)[0];
    T reg142=0.017711911323922008951*elem.pos(3)[1]; reg40=reg79+reg40; reg129=reg129+reg128; reg5=reg49+reg5; reg49=0.054999999999999990659*elem.pos(1)[1];
    reg79=0.10787324362732871366*elem.pos(4)[1]; T reg143=0.017711911323922008951*elem.pos(0)[0]; T reg144=0.01408770817240727159*elem.pos(1)[0]; T reg145=0.28125000000000003123*elem.pos(6)[1]; T reg146=0.017711911323922008951*elem.pos(3)[0];
    reg70=reg100+reg70; reg100=0.0070438540862036428341*elem.pos(3)[1]; reg34=reg34-reg73; reg121=reg121+reg122; reg111=reg111-reg112;
    T reg147=0.66356850115866749835*elem.pos(5)[1]; T reg148=0.063394686775832778473*elem.pos(4)[1]; reg125=reg30+reg125; reg127=reg92-reg127; reg133=reg11+reg133;
    reg54=reg54-reg93; reg96=reg3+reg96; reg3=0.38036812065499675528*elem.pos(6)[0]; reg117=reg48+reg117; reg12=reg50+reg12;
    reg26=reg26-reg132; reg80=reg80-reg126; reg71=reg71+reg118; reg11=0.50071574942066619112*elem.pos(7)[0]; reg89=reg63-reg89;
    reg35=reg106+reg35; reg30=0.14892637586900065821*elem.pos(7)[0]; reg48=0.28125000000000003123*elem.pos(6)[0]; reg57=reg57-reg83; reg50=0.38036812065499675528*elem.pos(6)[1];
    reg63=1.8214212528966690672*elem.pos(2)[0]; reg76=reg105-reg76; reg92=0.14892637586900062074*elem.pos(6)[0]; reg16=reg16-reg123; reg75=reg68+reg75;
    reg68=1.8214212528966690672*elem.pos(2)[1]; reg81=reg109-reg81; reg43=reg43+reg62; reg105=0.48801408404140807646*elem.pos(2)[0]; reg106=0.50071574942066619112*elem.pos(7)[1];
    reg116=reg66-reg116; reg66=0.0070438540862036428341*elem.pos(3)[0]; reg32=reg32-reg124; reg85=reg85-reg113; reg109=0.48801408404140807646*elem.pos(2)[1];
    reg78=reg72-reg78; reg72=0.054999999999999990659*elem.pos(1)[0]; reg110=reg33+reg110; reg111=reg111+reg147; reg16=reg16*reg85;
    reg110=reg110+reg48; reg33=0.031249999999999996531*elem.pos(2)[0]; T reg149=0.054999999999999990659*elem.pos(3)[1]; reg26=reg26*reg32; reg49=reg127+reg49;
    reg141=reg141-reg140; reg127=0.063394686775832799587*elem.pos(5)[0]; T reg150=0.084284250579333737197*elem.pos(4)[1]; T reg151=0.054999999999999990659*elem.pos(0)[1]; reg139=reg119-reg139;
    reg119=0.017711911323921993489*elem.pos(1)[0]; T reg152=0.063394686775832778473*elem.pos(7)[0]; T reg153=0.054999999999999990659*elem.pos(0)[0]; T reg154=0.084284250579333737197*elem.pos(4)[0]; reg80=reg80-reg66;
    reg135=reg131-reg135; reg131=0.017711911323921993489*elem.pos(1)[1]; T reg155=0.063394686775832799587*elem.pos(5)[1]; reg148=reg148-reg136; T reg156=0.11091229182759281127*elem.pos(3)[1];
    reg121=reg121-reg138; reg54=reg54+reg3; T reg157=0.01408770817240727159*elem.pos(2)[0]; reg143=reg25-reg143; reg25=0.50071574942066625656*elem.pos(5)[0];
    reg120=reg79-reg120; reg79=0.50071574942066625656*elem.pos(5)[1]; T reg158=0.11091229182759281127*elem.pos(3)[0]; reg129=reg129-reg144; reg57=reg57+reg50;
    T reg159=0.01408770817240727159*elem.pos(2)[1]; T reg160=0.43301408404140806645*elem.pos(1)[1]; reg146=reg70-reg146; reg92=reg75-reg92; reg70=0.373926375869000622*elem.pos(6)[0];
    reg35=reg35-reg30; reg130=reg51-reg130; reg11=reg89+reg11; reg51=0.030992957979296029919*elem.pos(2)[0]; reg75=0.10787324362732864825*elem.pos(6)[1];
    reg106=reg116+reg106; reg89=0.10787324362732864825*elem.pos(6)[0]; reg116=0.030992957979296029919*elem.pos(2)[1]; reg115=reg115+reg137; reg117=reg117*reg12;
    reg133=reg133*reg96; reg5=reg5-reg134; T reg161=0.43301408404140806645*elem.pos(1)[0]; T reg162=0.373926375869000622*elem.pos(6)[1]; reg142=reg40-reg142;
    reg109=reg71+reg109; reg72=reg78+reg72; reg40=0.054999999999999990659*elem.pos(3)[0]; reg125=reg125+reg145; reg71=0.10787324362732871366*elem.pos(7)[1];
    reg68=reg81+reg68; reg78=0.063394686775832778473*elem.pos(7)[1]; reg34=reg34-reg100; reg81=0.031249999999999996531*elem.pos(2)[1]; reg105=reg43+reg105;
    reg63=reg76+reg63; reg43=0.10787324362732871366*elem.pos(7)[0]; reg131=reg135+reg131; reg76=3.2322880886760779675*elem.pos(3)[1]; reg135=0.0070438540862036428341*elem.pos(1)[1];
    T reg163=0.063394686775832799587*elem.pos(6)[1]; reg78=reg34+reg78; reg5=reg5+reg162; reg34=0.24400704202070403823*elem.pos(2)[1]; T reg164=0.063394686775832799587*elem.pos(6)[0];
    reg16=reg26-reg16; reg119=reg139+reg119; reg152=reg80+reg152; reg26=3.2322880886760779675*elem.pos(3)[0]; reg68=reg68*reg105;
    reg63=reg63*reg109; reg149=reg49+reg149; reg49=0.084284250579333737197*elem.pos(7)[1]; reg110=reg110-reg33; reg125=reg125-reg81;
    reg80=0.41055441711725960177*elem.pos(1)[1]; reg139=0.24400704202070403823*elem.pos(2)[0]; reg35=reg35+reg70; reg79=reg120-reg79; reg160=reg111+reg160;
    reg111=0.0069859159585920716348*elem.pos(3)[1]; reg120=0.41055441711725960177*elem.pos(1)[0]; reg25=reg143-reg25; reg116=reg130+reg116; reg117=reg133-reg117;
    reg51=reg92+reg51; reg92=0.0069859159585920716348*elem.pos(0)[0]; reg130=0.033568501158667519769*elem.pos(4)[0]; reg148=reg148+reg155; reg133=0.084284250579333737197*elem.pos(7)[0];
    reg143=0.033568501158667511326*elem.pos(5)[0]; reg153=reg154+reg153; reg151=reg150+reg151; reg150=0.033568501158667511326*elem.pos(5)[1]; reg154=0.017711911323921993489*elem.pos(2)[1];
    reg43=reg146+reg43; reg146=0.50071574942066625656*elem.pos(6)[0]; reg121=reg121+reg156; reg40=reg72+reg40; reg71=reg142+reg71;
    reg72=0.50071574942066625656*elem.pos(6)[1]; reg142=0.0070438540862036428341*elem.pos(1)[0]; reg141=reg141+reg127; T reg165=0.0069859159585920716348*elem.pos(0)[1]; T reg166=0.033568501158667519769*elem.pos(4)[1];
    T reg167=2.9946318793450032447*elem.pos(7)[1]; reg89=reg11-reg89; reg57=reg57-reg159; reg75=reg106-reg75; reg54=reg54-reg157;
    reg129=reg129+reg158; reg11=2.9946318793450032447*elem.pos(7)[0]; reg106=0.0069859159585920716348*elem.pos(3)[0]; reg161=reg115+reg161; reg115=0.017711911323921993489*elem.pos(2)[0];
    T reg168=0.033568501158667519769*elem.pos(7)[1]; reg111=reg160+reg111; reg160=2.9946318793450032447*elem.pos(6)[0]; reg129=reg129-reg11; reg141=reg141-reg142;
    T reg169=0.055456145913796350227*elem.pos(3)[0]; reg49=reg149+reg49; reg149=0.033568501158667511326*elem.pos(6)[1]; reg154=reg75+reg154; reg54=reg32*reg54;
    reg80=reg79+reg80; reg75=0.13944558288274055635*elem.pos(3)[1]; reg110=reg110*reg16; reg34=reg5+reg34; reg115=reg89+reg115;
    reg106=reg161+reg106; reg5=0.033568501158667519769*elem.pos(7)[0]; reg51=reg51*reg117; reg116=reg117*reg116; reg79=0.033568501158667511326*elem.pos(6)[0];
    reg133=reg40+reg133; reg139=reg35+reg139; reg146=reg43-reg146; reg125=reg16*reg125; reg35=0.41055441711725960177*elem.pos(2)[0];
    reg40=0.084284250579333745647*elem.pos(5)[1]; reg72=reg71-reg72; reg43=0.41055441711725960177*elem.pos(2)[1]; reg165=reg165-reg166; reg68=reg63-reg68;
    reg57=reg85*reg57; reg63=2.9946318793450032447*elem.pos(6)[1]; reg148=reg148-reg135; reg121=reg121-reg167; reg92=reg92-reg130;
    reg71=0.084284250579333745647*elem.pos(5)[0]; reg89=0.055456145913796350227*elem.pos(3)[1]; reg161=3.942126756372671509*elem.pos(7)[1]; reg76=reg131-reg76; reg131=0.0069859159585920691772*elem.pos(1)[1];
    reg150=reg151-reg150; reg151=3.942126756372671509*elem.pos(7)[0]; reg78=reg78+reg163; reg26=reg119-reg26; reg119=0.13944558288274055635*elem.pos(3)[0];
    T reg170=0.0070438540862036428341*elem.pos(2)[1]; reg120=reg25+reg120; reg25=0.0070438540862036428341*elem.pos(2)[0]; reg152=reg152+reg164; reg143=reg153-reg143;
    reg153=0.0069859159585920691772*elem.pos(1)[0]; reg116=0.12345679012345679715*reg116; T reg171=0.11091229182759258962*elem.pos(2)[1]; reg78=reg78-reg170; T reg172=0.084284250579333745647*elem.pos(6)[0];
    reg110=0.19753086419753085323*reg110; reg34=reg68*reg34; reg43=reg72+reg43; reg106=reg106-reg5; reg148=reg148-reg89;
    reg72=0.84928425057933392599*elem.pos(6)[1]; reg165=reg165+reg40; reg161=reg76+reg161; reg35=reg146+reg35; reg151=reg26+reg151;
    reg115=reg96*reg115; reg125=0.19753086419753085323*reg125; reg131=reg150+reg131; reg153=reg143+reg153; reg26=0.43301408404140791412*elem.pos(3)[0];
    reg76=0.49910531322416709662*elem.pos(7)[1]; reg79=reg133-reg79; reg133=0.0069859159585920691772*elem.pos(2)[0]; reg51=0.12345679012345679715*reg51; reg143=0.84928425057933392599*elem.pos(6)[0];
    reg146=0.055000000000000010008*elem.pos(1)[1]; reg119=reg120-reg119; reg120=0.84928425057933444099*elem.pos(7)[0]; reg129=reg129+reg160; reg150=0.11091229182759258962*elem.pos(2)[0];
    reg139=reg139*reg68; T reg173=0.43301408404140791412*elem.pos(3)[1]; reg111=reg111-reg168; T reg174=0.084284250579333745647*elem.pos(6)[1]; reg75=reg80-reg75;
    reg80=0.84928425057933444099*elem.pos(7)[1]; reg152=reg152-reg25; T reg175=0.49910531322416709662*elem.pos(7)[0]; reg16=0.19753086419753085323*reg16; reg117=0.12345679012345679715*reg117;
    T reg176=0.0069859159585920691772*elem.pos(2)[1]; reg141=reg141-reg169; T reg177=0.055000000000000010008*elem.pos(1)[0]; reg92=reg92+reg71; reg57=reg54-reg57;
    reg154=reg12*reg154; reg121=reg121+reg63; reg149=reg49-reg149; reg49=0.055000000000000010008*elem.pos(2)[0]; reg106=reg106+reg172;
    reg111=reg111+reg174; reg154=reg115-reg154; reg120=reg119+reg120; reg43=reg105*reg43; reg139=0.12345679012345679715*reg139;
    reg26=reg153+reg26; reg54=0.66356850115866743183*elem.pos(7)[0]; reg129=reg129-reg150; reg115=0.055000000000000010008*elem.pos(3)[1]; reg119=3.942126756372672024*elem.pos(6)[0];
    reg34=0.12345679012345679715*reg34; reg78=reg57*reg78; reg153=0.49910531322416726286*elem.pos(6)[1]; reg146=reg165+reg146; reg35=reg109*reg35;
    reg68=0.12345679012345679715*reg68; reg117=reg16+reg117; reg121=reg121-reg171; reg176=reg149+reg176; reg16=0.055000000000000010008*elem.pos(3)[0];
    reg177=reg92+reg177; reg175=reg141+reg175; reg76=reg148+reg76; reg92=0.13944558288274043462*elem.pos(2)[0]; reg141=0.49910531322416726286*elem.pos(6)[0];
    reg143=reg151-reg143; reg152=reg152*reg57; reg51=reg110+reg51; reg110=0.66356850115866743183*elem.pos(7)[1]; reg133=reg79+reg133;
    reg173=reg131+reg173; reg79=3.942126756372672024*elem.pos(6)[1]; reg80=reg75+reg80; reg72=reg161-reg72; reg116=reg125+reg116;
    reg75=0.13944558288274043462*elem.pos(2)[1]; reg125=0.055000000000000010008*elem.pos(2)[1]; reg131=0.26428425057933379666*elem.pos(7)[1]; reg115=reg146+reg115; reg78=0.12345679012345679715*reg78;
    reg146=0.26428425057933373015*elem.pos(6)[1]; reg176=reg154*reg176; reg110=reg173+reg110; reg125=reg111+reg125; reg76=reg76+reg153;
    reg111=0.055456145913796350227*elem.pos(2)[1]; reg148=0.26428425057933379666*elem.pos(7)[0]; reg16=reg177+reg16; reg75=reg72+reg75; reg139=reg51+reg139;
    reg119=reg120-reg119; reg51=3.2322880886760785326*elem.pos(2)[0]; reg92=reg143+reg92; reg79=reg80-reg79; reg72=3.2322880886760785326*elem.pos(2)[1];
    reg80=0.26428425057933373015*elem.pos(6)[0]; reg54=reg26+reg54; reg121=reg85*reg121; reg129=reg32*reg129; reg68=reg117+reg68;
    reg57=0.12345679012345679715*reg57; reg26=0.055456145913796350227*elem.pos(2)[0]; reg175=reg175+reg141; reg34=reg116+reg34; reg43=reg35-reg43;
    reg133=reg133*reg154; reg152=0.12345679012345679715*reg152; reg49=reg106+reg49; reg16=reg16-reg148; reg32=0.66356850115866749835*elem.pos(6)[1];
    reg75=reg12*reg75; reg115=reg115-reg131; reg92=reg96*reg92; reg133=0.077160493827160489544*reg133; reg12=0.054999999999999990659*elem.pos(2)[0];
    reg152=reg139+reg152; reg80=reg54-reg80; reg76=reg76-reg111; reg49=reg49*reg43; reg121=reg129-reg121;
    reg35=0.054999999999999990659*elem.pos(2)[1]; reg146=reg110-reg146; reg175=reg175-reg26; reg125=reg43*reg125; reg54=0.66356850115866749835*elem.pos(6)[0];
    reg78=reg34+reg78; reg72=reg79+reg72; reg176=0.077160493827160489544*reg176; reg57=reg68+reg57; reg51=reg119+reg51;
    reg154=0.077160493827160489544*reg154; reg175=reg175*reg121; reg176=reg78+reg176; reg154=reg57+reg154; reg43=0.077160493827160489544*reg43;
    reg35=reg146+reg35; reg49=0.077160493827160489544*reg49; reg133=reg152+reg133; reg115=reg115+reg32; reg34=0.43301408404140806645*elem.pos(2)[1];
    reg125=0.077160493827160489544*reg125; reg76=reg121*reg76; reg72=reg105*reg72; reg51=reg109*reg51; reg75=reg92-reg75;
    reg12=reg80+reg12; reg16=reg16+reg54; reg57=0.43301408404140806645*elem.pos(2)[0]; reg125=reg176+reg125; reg34=reg115+reg34;
    reg121=0.12345679012345679715*reg121; reg43=reg154+reg43; reg12=reg12*reg75; reg35=reg75*reg35; reg76=0.12345679012345679715*reg76;
    reg72=reg51-reg72; reg175=0.12345679012345679715*reg175; reg49=reg133+reg49; reg57=reg16+reg57; reg35=0.077160493827160489544*reg35;
    reg76=reg125+reg76; reg175=reg49+reg175; reg57=reg57*reg72; reg121=reg43+reg121; reg75=0.077160493827160489544*reg75;
    reg12=0.077160493827160489544*reg12; reg34=reg72*reg34; reg12=reg175+reg12; reg34=0.077160493827160489544*reg34; reg72=0.077160493827160489544*reg72;
    reg75=reg121+reg75; reg35=reg76+reg35; reg57=0.077160493827160489544*reg57; reg34=reg35+reg34; reg72=reg75+reg72;
    reg57=reg12+reg57; res[1]=reg34/reg72; res[0]=reg57/reg72;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Quad_42,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=2.2214212528966688501*elem.pos(4)[0]; T reg1=1.8214212528966687488*elem.pos(0)[0]; T reg2=1.8214212528966687488*elem.pos(0)[1]; T reg3=2.2214212528966688501*elem.pos(4)[1]; T reg4=0.062500000000000055511*elem.pos(0)[0];
    T reg5=0.062500000000000055511*elem.pos(0)[1]; T reg6=1.6875*elem.pos(4)[0]; T reg7=1.6875*elem.pos(4)[1]; T reg8=reg4-reg6; T reg9=1.6875*elem.pos(5)[0];
    T reg10=0.078578747103331282649*elem.pos(0)[1]; T reg11=1.8214212528966687488*elem.pos(0)[2]; T reg12=2.2214212528966688501*elem.pos(4)[2]; T reg13=0.47857874710333157733*elem.pos(4)[0]; T reg14=0.062500000000000055511*elem.pos(0)[2];
    T reg15=1.6875*elem.pos(4)[2]; T reg16=0.47857874710333128711*elem.pos(5)[0]; T reg17=0.47857874710333157733*elem.pos(4)[1]; reg1=reg0-reg1; reg0=0.47857874710333128711*elem.pos(5)[1];
    reg2=reg3-reg2; reg3=1.6875*elem.pos(5)[1]; T reg18=reg5-reg7; T reg19=0.078578747103331282649*elem.pos(0)[0]; reg19=reg13-reg19;
    reg0=reg2-reg0; reg2=0.078578747103331282649*elem.pos(0)[2]; reg16=reg1-reg16; reg1=0.078578747103331214053*elem.pos(1)[1]; reg18=reg18+reg3;
    reg13=2.2214212528966691402*elem.pos(5)[0]; T reg20=2.2214212528966691402*elem.pos(5)[1]; T reg21=0.062499999999999930604*elem.pos(1)[1]; T reg22=1.6875*elem.pos(5)[2]; T reg23=0.078578747103331214053*elem.pos(1)[0];
    T reg24=0.47857874710333128711*elem.pos(5)[2]; reg11=reg12-reg11; reg12=2.9946318793450032447*elem.pos(4)[1]; T reg25=0.11091229182759281127*elem.pos(0)[1]; T reg26=0.11091229182759281127*elem.pos(0)[0];
    reg8=reg8+reg9; T reg27=2.9946318793450032447*elem.pos(4)[0]; T reg28=0.062499999999999930604*elem.pos(1)[0]; T reg29=reg14-reg15; reg10=reg17-reg10;
    reg17=0.47857874710333157733*elem.pos(4)[2]; reg20=reg10-reg20; reg10=3.942126756372671509*elem.pos(4)[0]; T reg30=3.2322880886760779675*elem.pos(0)[0]; T reg31=0.062500000000000055511*elem.pos(3)[0];
    reg8=reg8-reg28; reg2=reg17-reg2; reg17=1.8214212528966687488*elem.pos(3)[0]; reg23=reg16+reg23; reg16=2.2214212528966691402*elem.pos(5)[2];
    T reg32=2.9946318793450032447*elem.pos(4)[2]; T reg33=0.078578747103331214053*elem.pos(1)[2]; reg24=reg11-reg24; reg29=reg29+reg22; reg11=0.062499999999999930604*elem.pos(1)[2];
    T reg34=0.11091229182759281127*elem.pos(0)[2]; T reg35=reg26-reg27; T reg36=2.9946318793450032447*elem.pos(5)[0]; T reg37=3.942126756372671509*elem.pos(4)[1]; reg13=reg19-reg13;
    reg19=1.8214212528966690672*elem.pos(1)[0]; T reg38=reg25-reg12; T reg39=1.8214212528966690672*elem.pos(1)[1]; T reg40=2.9946318793450032447*elem.pos(5)[1]; T reg41=3.2322880886760779675*elem.pos(0)[1];
    reg1=reg0+reg1; reg18=reg18-reg21; reg0=0.062500000000000055511*elem.pos(3)[1]; T reg42=1.8214212528966687488*elem.pos(3)[1]; reg8=reg8+reg31;
    T reg43=1.6875*elem.pos(7)[0]; reg18=reg18+reg0; T reg44=0.062500000000000055511*elem.pos(3)[2]; T reg45=3.942126756372671509*elem.pos(4)[2]; reg29=reg29-reg11;
    T reg46=3.2322880886760779675*elem.pos(0)[2]; reg19=reg13+reg19; reg41=reg37-reg41; reg13=0.078578747103331282649*elem.pos(3)[0]; reg37=0.84928425057933392599*elem.pos(5)[1];
    T reg47=1.6875*elem.pos(7)[1]; T reg48=2.9946318793450032447*elem.pos(5)[2]; T reg49=0.078578747103331282649*elem.pos(3)[1]; reg42=reg1-reg42; reg1=2.2214212528966688501*elem.pos(7)[1];
    T reg50=reg34-reg32; reg35=reg35+reg36; reg33=reg24+reg33; reg24=1.8214212528966687488*elem.pos(3)[2]; T reg51=1.8214212528966690672*elem.pos(1)[2];
    reg16=reg2-reg16; reg2=0.11091229182759258962*elem.pos(1)[1]; reg38=reg38+reg40; reg17=reg23-reg17; reg23=0.84928425057933444099*elem.pos(4)[0];
    T reg52=0.13944558288274055635*elem.pos(0)[0]; T reg53=2.2214212528966688501*elem.pos(7)[0]; T reg54=0.84928425057933392599*elem.pos(5)[0]; reg30=reg10-reg30; reg10=0.84928425057933444099*elem.pos(4)[1];
    T reg55=0.13944558288274055635*elem.pos(0)[1]; reg39=reg20+reg39; reg20=0.11091229182759258962*elem.pos(1)[0]; reg50=reg50+reg48; T reg56=0.11091229182759258962*elem.pos(1)[2];
    T reg57=0.062499999999999993061*elem.pos(0)[0]; reg38=reg38-reg2; T reg58=0.014087708172407299745*elem.pos(3)[1]; reg54=reg30-reg54; reg30=0.47857874710333157733*elem.pos(7)[0];
    reg51=reg16+reg51; reg16=0.47857874710333157733*elem.pos(7)[1]; T reg59=0.5624999999999998751*elem.pos(4)[0]; T reg60=0.014087708172407299745*elem.pos(3)[0]; T reg61=0.062499999999999993061*elem.pos(0)[1];
    T reg62=0.13944558288274043462*elem.pos(1)[0]; T reg63=0.5624999999999998751*elem.pos(4)[1]; reg49=reg39-reg49; reg39=0.38036812065499675528*elem.pos(4)[0]; T reg64=0.014087708172407299745*elem.pos(0)[0];
    reg1=reg42+reg1; reg42=0.38036812065499675528*elem.pos(4)[1]; T reg65=0.014087708172407299745*elem.pos(0)[1]; T reg66=0.47857874710333128711*elem.pos(6)[1]; reg24=reg33-reg24;
    reg33=2.2214212528966688501*elem.pos(7)[2]; T reg67=0.078578747103331282649*elem.pos(3)[2]; T reg68=0.74785275173800116902*elem.pos(4)[1]; T reg69=0.48801408404140790478*elem.pos(0)[1]; T reg70=0.48801408404140790478*elem.pos(0)[0];
    T reg71=0.74785275173800116902*elem.pos(4)[0]; reg37=reg41-reg37; reg41=0.13944558288274043462*elem.pos(1)[1]; reg13=reg19-reg13; reg19=1.6875*elem.pos(7)[2];
    reg29=reg29+reg44; T reg72=1.6875*elem.pos(6)[1]; reg18=reg18-reg47; reg46=reg45-reg46; reg45=0.84928425057933392599*elem.pos(5)[2];
    T reg73=1.6875*elem.pos(6)[0]; reg8=reg8-reg43; reg52=reg23-reg52; reg23=3.942126756372672024*elem.pos(5)[0]; reg53=reg17+reg53;
    reg17=0.47857874710333128711*elem.pos(6)[0]; reg35=reg35-reg20; reg55=reg10-reg55; reg10=3.942126756372672024*elem.pos(5)[1]; T reg74=0.84928425057933444099*elem.pos(4)[2];
    T reg75=0.13944558288274055635*elem.pos(0)[2]; reg67=reg51-reg67; reg51=0.47857874710333157733*elem.pos(7)[2]; T reg76=0.29785275173800131643*elem.pos(4)[0]; T reg77=0.061985915958592081643*elem.pos(0)[0];
    T reg78=2.2214212528966691402*elem.pos(6)[1]; reg16=reg49+reg16; reg49=2.2214212528966691402*elem.pos(6)[0]; reg30=reg13+reg30; reg17=reg53-reg17;
    reg13=0.078578747103331214053*elem.pos(2)[0]; reg66=reg1-reg66; reg1=0.078578747103331214053*elem.pos(2)[1]; reg53=0.74785275173800116902*elem.pos(4)[2]; reg33=reg24+reg33;
    reg24=0.47857874710333128711*elem.pos(6)[2]; T reg79=0.48801408404140790478*elem.pos(0)[2]; reg68=reg69+reg68; reg69=0.29785275173800124148*elem.pos(5)[1]; reg70=reg71+reg70;
    reg71=0.29785275173800124148*elem.pos(5)[0]; T reg80=0.41055441711725952999*elem.pos(0)[1]; reg59=reg59-reg57; T reg81=0.56250000000000006245*elem.pos(5)[0]; reg62=reg54+reg62;
    reg54=0.50071574942066619112*elem.pos(4)[1]; T reg82=3.2322880886760785326*elem.pos(1)[1]; T reg83=0.41055441711725952999*elem.pos(3)[0]; reg10=reg55-reg10; reg55=0.41055441711725952999*elem.pos(0)[0];
    reg41=reg37+reg41; reg37=0.41055441711725952999*elem.pos(3)[1]; T reg84=0.50071574942066619112*elem.pos(4)[0]; T reg85=1.6875*elem.pos(6)[2]; reg29=reg29-reg19;
    T reg86=0.38036812065499675528*elem.pos(4)[2]; T reg87=0.062499999999999930604*elem.pos(2)[1]; reg18=reg18+reg72; T reg88=0.062499999999999930604*elem.pos(2)[0]; reg8=reg8+reg73;
    reg45=reg46-reg45; reg46=0.13944558288274043462*elem.pos(1)[2]; T reg89=0.014087708172407299745*elem.pos(0)[2]; reg23=reg52-reg23; reg52=3.2322880886760785326*elem.pos(1)[0];
    T reg90=0.061985915958592081643*elem.pos(0)[1]; T reg91=0.29785275173800131643*elem.pos(4)[1]; T reg92=reg65-reg42; T reg93=0.38036812065499675528*elem.pos(5)[0]; T reg94=reg64-reg39;
    T reg95=0.38036812065499675528*elem.pos(5)[1]; reg35=reg35+reg60; T reg96=0.38036812065499675528*elem.pos(7)[0]; T reg97=3.942126756372672024*elem.pos(5)[2]; reg75=reg74-reg75;
    reg74=0.5624999999999998751*elem.pos(4)[2]; T reg98=0.062499999999999993061*elem.pos(0)[2]; reg38=reg38+reg58; T reg99=0.38036812065499675528*elem.pos(7)[1]; reg63=reg63-reg61;
    T reg100=0.56250000000000006245*elem.pos(5)[1]; reg50=reg50-reg56; T reg101=0.014087708172407299745*elem.pos(3)[2]; reg92=reg92+reg95; reg53=reg79+reg53;
    reg79=0.01408770817240727159*elem.pos(1)[1]; T reg102=0.017711911323922008951*elem.pos(0)[1]; T reg103=0.10787324362732871366*elem.pos(4)[1]; T reg104=0.017711911323922008951*elem.pos(0)[0]; reg70=reg71-reg70;
    reg71=0.061985915958592059837*elem.pos(1)[0]; T reg105=0.10787324362732871366*elem.pos(4)[0]; T reg106=0.41055441711725952999*elem.pos(0)[2]; T reg107=0.50071574942066619112*elem.pos(4)[2]; T reg108=0.10787324362732864825*elem.pos(5)[1];
    reg68=reg69-reg68; reg69=0.061985915958592059837*elem.pos(1)[1]; T reg109=0.29785275173800124148*elem.pos(5)[2]; reg80=reg54-reg80; reg54=0.10787324362732864825*elem.pos(5)[0];
    reg55=reg84-reg55; reg84=0.38036812065499675528*elem.pos(5)[2]; T reg110=reg89-reg86; T reg111=0.74785275173800124399*elem.pos(5)[1]; reg77=reg77-reg76;
    T reg112=0.74785275173800124399*elem.pos(5)[0]; T reg113=2.2214212528966691402*elem.pos(6)[2]; reg51=reg67+reg51; reg90=reg90-reg91; reg67=0.061985915958592081643*elem.pos(0)[2];
    T reg114=0.29785275173800131643*elem.pos(4)[2]; reg35=reg35-reg96; T reg115=0.38036812065499675528*elem.pos(6)[0]; T reg116=1.8214212528966690672*elem.pos(2)[1]; reg78=reg16-reg78;
    reg38=reg38-reg99; reg16=0.38036812065499675528*elem.pos(6)[1]; reg50=reg50+reg101; T reg117=0.38036812065499675528*elem.pos(7)[2]; T reg118=1.8214212528966690672*elem.pos(2)[0];
    reg49=reg30-reg49; reg83=reg62-reg83; reg30=0.50071574942066619112*elem.pos(7)[0]; reg37=reg41-reg37; reg41=0.50071574942066619112*elem.pos(7)[1];
    reg46=reg45+reg46; reg45=0.41055441711725952999*elem.pos(3)[2]; reg52=reg23+reg52; reg23=0.017711911323922008951*elem.pos(3)[0]; reg82=reg10+reg82;
    reg10=0.017711911323922008951*elem.pos(3)[1]; reg97=reg75-reg97; reg62=3.2322880886760785326*elem.pos(1)[2]; reg94=reg94+reg93; reg75=0.01408770817240727159*elem.pos(1)[0];
    reg24=reg33-reg24; reg33=0.078578747103331214053*elem.pos(2)[2]; reg74=reg74-reg98; reg8=reg8-reg88; reg18=reg18-reg87;
    T reg119=0.56250000000000006245*elem.pos(5)[2]; reg13=reg17+reg13; reg17=0.062499999999999993061*elem.pos(1)[0]; reg59=reg81+reg59; reg1=reg66+reg1;
    reg63=reg100+reg63; reg66=0.062499999999999930604*elem.pos(2)[2]; reg29=reg29+reg85; T reg120=0.062499999999999993061*elem.pos(1)[1]; reg106=reg107-reg106;
    reg107=0.10787324362732864825*elem.pos(5)[2]; reg77=reg112+reg77; T reg121=0.48801408404140807646*elem.pos(1)[0]; reg90=reg111+reg90; T reg122=0.48801408404140807646*elem.pos(1)[1];
    T reg123=0.74785275173800124399*elem.pos(5)[2]; reg67=reg67-reg114; T reg124=0.017711911323921993489*elem.pos(1)[1]; reg108=reg80-reg108; reg80=1.8214212528966690672*elem.pos(2)[2];
    reg113=reg51-reg113; reg51=0.017711911323922008951*elem.pos(3)[2]; reg116=reg78+reg116; reg62=reg97+reg62; reg78=0.10787324362732871366*elem.pos(7)[1];
    reg10=reg82-reg10; reg118=reg49+reg118; reg104=reg105-reg104; reg49=0.50071574942066625656*elem.pos(5)[0]; reg82=pow(reg13,2);
    reg102=reg103-reg102; reg97=0.50071574942066625656*elem.pos(5)[1]; reg103=0.10787324362732871366*elem.pos(4)[2]; reg105=0.10787324362732864825*elem.pos(6)[1]; reg41=reg37+reg41;
    reg29=reg29-reg66; reg37=0.10787324362732864825*elem.pos(6)[0]; reg30=reg83+reg30; reg83=reg17-reg59; T reg125=0.062499999999999993061*elem.pos(3)[0];
    T reg126=pow(reg18,2); reg94=reg94-reg75; T reg127=0.11091229182759281127*elem.pos(3)[0]; reg92=reg92-reg79; T reg128=0.11091229182759281127*elem.pos(3)[1];
    reg110=reg110+reg84; T reg129=0.01408770817240727159*elem.pos(1)[2]; T reg130=pow(reg8,2); T reg131=0.38036812065499675528*elem.pos(6)[2]; reg50=reg50-reg117;
    T reg132=reg120-reg63; T reg133=0.01408770817240727159*elem.pos(2)[1]; reg38=reg38+reg16; T reg134=0.062499999999999993061*elem.pos(3)[1]; T reg135=0.01408770817240727159*elem.pos(2)[0];
    reg35=reg35+reg115; reg74=reg119+reg74; T reg136=0.062499999999999993061*elem.pos(1)[2]; reg45=reg46-reg45; reg46=0.50071574942066619112*elem.pos(7)[2];
    reg54=reg55-reg54; reg55=0.017711911323921993489*elem.pos(1)[0]; reg23=reg52-reg23; reg71=reg70-reg71; reg52=0.48801408404140790478*elem.pos(3)[0];
    reg33=reg24+reg33; reg69=reg68-reg69; reg24=0.48801408404140790478*elem.pos(3)[1]; reg68=pow(reg1,2); reg53=reg109-reg53;
    reg70=0.061985915958592059837*elem.pos(1)[2]; reg109=0.10787324362732871366*elem.pos(7)[0]; T reg137=0.017711911323922008951*elem.pos(0)[2]; reg35=reg35-reg135; reg68=reg82+reg68;
    reg82=reg136-reg74; T reg138=0.062499999999999993061*elem.pos(3)[2]; reg70=reg53-reg70; reg53=0.48801408404140790478*elem.pos(3)[2]; reg46=reg45+reg46;
    reg45=0.10787324362732864825*elem.pos(6)[2]; reg55=reg54+reg55; reg54=3.2322880886760779675*elem.pos(3)[0]; reg124=reg108+reg124; reg108=3.2322880886760779675*elem.pos(3)[1];
    T reg139=0.10787324362732871366*elem.pos(7)[2]; reg51=reg62-reg51; reg62=0.48801408404140807646*elem.pos(1)[2]; reg67=reg123+reg67; T reg140=0.061985915958592081643*elem.pos(3)[1];
    reg122=reg90+reg122; T reg141=0.061985915958592081643*elem.pos(3)[0]; reg121=reg77+reg121; reg80=reg113+reg80; reg109=reg23+reg109;
    reg107=reg106-reg107; reg23=0.017711911323921993489*elem.pos(1)[2]; reg126=reg130+reg126; reg106=pow(reg29,2); reg113=0.017711911323921993489*elem.pos(2)[0];
    reg37=reg30-reg37; reg52=reg71+reg52; reg30=0.74785275173800116902*elem.pos(7)[0]; reg83=reg83-reg125; reg105=reg41-reg105;
    reg41=0.017711911323921993489*elem.pos(2)[1]; reg94=reg94+reg127; reg71=2.9946318793450032447*elem.pos(7)[0]; reg92=reg92+reg128; reg130=2.9946318793450032447*elem.pos(7)[1];
    T reg142=pow(reg33,2); reg110=reg110-reg129; T reg143=0.11091229182759281127*elem.pos(3)[2]; T reg144=0.01408770817240727159*elem.pos(2)[2]; reg50=reg50+reg131;
    reg24=reg69+reg24; reg69=0.5624999999999998751*elem.pos(7)[0]; T reg145=0.74785275173800116902*elem.pos(7)[1]; reg38=reg38-reg133; reg132=reg132-reg134;
    T reg146=0.5624999999999998751*elem.pos(7)[1]; T reg147=0.50071574942066625656*elem.pos(6)[1]; reg78=reg10+reg78; reg10=0.50071574942066625656*elem.pos(5)[2]; T reg148=0.41055441711725960177*elem.pos(1)[0];
    T reg149=0.50071574942066625656*elem.pos(6)[0]; reg137=reg103-reg137; reg97=reg102-reg97; reg49=reg104-reg49; reg102=0.41055441711725960177*elem.pos(1)[1];
    reg103=pow(reg116,2); reg104=pow(reg118,2); reg54=reg55-reg54; reg55=3.942126756372671509*elem.pos(7)[0]; T reg150=2.9946318793450032447*elem.pos(7)[2];
    reg110=reg110+reg143; reg147=reg78-reg147; reg78=0.41055441711725960177*elem.pos(2)[1]; reg108=reg124-reg108; reg124=3.942126756372671509*elem.pos(7)[1];
    T reg151=0.41055441711725960177*elem.pos(1)[2]; T reg152=0.50071574942066625656*elem.pos(6)[2]; reg142=reg68+reg142; reg139=reg51+reg139; reg51=2.9946318793450032447*elem.pos(6)[1];
    reg92=reg92-reg130; reg68=0.061985915958592081643*elem.pos(3)[2]; reg62=reg67+reg62; T reg153=2.9946318793450032447*elem.pos(6)[0]; T reg154=0.29785275173800131643*elem.pos(7)[1];
    T reg155=0.13944558288274055635*elem.pos(3)[0]; reg148=reg49+reg148; reg69=reg83+reg69; reg49=0.56250000000000006245*elem.pos(6)[0]; reg145=reg24+reg145;
    reg24=0.29785275173800124148*elem.pos(6)[1]; reg83=pow(reg38,2); reg146=reg132+reg146; reg132=0.56250000000000006245*elem.pos(6)[1]; reg50=reg50-reg144;
    T reg156=pow(reg35,2); reg82=reg82-reg138; T reg157=0.5624999999999998751*elem.pos(7)[2]; T reg158=0.41055441711725960177*elem.pos(2)[0]; reg149=reg109-reg149;
    reg45=reg46-reg45; reg46=0.017711911323921993489*elem.pos(2)[2]; reg53=reg70+reg53; reg70=0.74785275173800116902*elem.pos(7)[2]; reg113=reg37+reg113;
    reg37=0.29785275173800124148*elem.pos(6)[0]; reg109=pow(reg80,2); reg10=reg137-reg10; reg106=reg126+reg106; reg103=reg104+reg103;
    reg30=reg52+reg30; reg102=reg97+reg102; reg41=reg105+reg41; reg23=reg107+reg23; reg52=3.2322880886760779675*elem.pos(3)[2];
    reg141=reg141-reg121; reg97=0.29785275173800131643*elem.pos(7)[0]; reg104=0.13944558288274055635*elem.pos(3)[1]; reg140=reg140-reg122; reg94=reg94-reg71;
    reg105=0.41055441711725960177*elem.pos(2)[2]; reg104=reg102-reg104; reg102=2.9946318793450032447*elem.pos(6)[2]; reg107=pow(reg113,2); reg46=reg45+reg46;
    reg45=0.84928425057933444099*elem.pos(7)[0]; reg110=reg110-reg150; reg151=reg10+reg151; reg10=0.84928425057933392599*elem.pos(6)[0]; reg55=reg54+reg55;
    reg155=reg148-reg155; reg54=3.942126756372671509*elem.pos(7)[2]; reg69=reg69+reg49; reg126=0.062499999999999993061*elem.pos(2)[0]; reg137=0.13944558288274055635*elem.pos(3)[2];
    reg52=reg23-reg52; reg83=reg156+reg83; reg24=reg145-reg24; reg23=0.061985915958592059837*elem.pos(2)[1]; reg146=reg146+reg132;
    reg145=0.062499999999999993061*elem.pos(2)[1]; reg148=pow(reg50,2); reg109=reg103+reg109; reg158=reg149+reg158; reg103=0.84928425057933444099*elem.pos(7)[1];
    reg106=pow(reg106,0.5); reg157=reg82+reg157; reg82=0.56250000000000006245*elem.pos(6)[2]; reg140=reg140-reg154; reg149=0.74785275173800124399*elem.pos(6)[1];
    reg94=reg94+reg153; reg156=0.11091229182759258962*elem.pos(2)[0]; reg68=reg68-reg62; T reg159=0.29785275173800131643*elem.pos(7)[2]; T reg160=0.061985915958592059837*elem.pos(2)[0];
    reg92=reg92+reg51; T reg161=0.11091229182759258962*elem.pos(2)[1]; reg78=reg147+reg78; reg142=pow(reg142,0.5); reg37=reg30-reg37;
    reg30=pow(reg41,2); reg152=reg139-reg152; reg70=reg53+reg70; reg53=0.84928425057933392599*elem.pos(6)[1]; reg139=0.29785275173800124148*elem.pos(6)[2];
    reg141=reg141-reg97; reg124=reg108+reg124; reg108=0.74785275173800124399*elem.pos(6)[0]; reg160=reg37+reg160; reg45=reg155+reg45;
    reg148=reg83+reg148; reg37=0.74785275173800124399*elem.pos(6)[2]; reg68=reg68-reg159; reg146=reg146-reg145; reg83=0.13944558288274043462*elem.pos(2)[0];
    reg147=0.84928425057933444099*elem.pos(7)[2]; reg137=reg151-reg137; reg23=reg24+reg23; reg24=3.942126756372672024*elem.pos(6)[0]; reg151=reg13/reg142;
    reg139=reg70-reg139; reg94=reg94-reg156; reg70=0.061985915958592059837*elem.pos(2)[2]; reg69=reg69-reg126; reg155=0.48801408404140807646*elem.pos(2)[1];
    reg140=reg140+reg149; reg54=reg52+reg54; reg52=0.84928425057933392599*elem.pos(6)[2]; T reg162=reg8/reg106; T reg163=pow(reg78,2);
    T reg164=reg18/reg106; reg110=reg110+reg102; reg53=reg124-reg53; reg30=reg107+reg30; reg105=reg152+reg105;
    reg107=0.062499999999999993061*elem.pos(2)[2]; reg157=reg157+reg82; reg92=reg92-reg161; reg124=pow(reg46,2); reg152=0.13944558288274043462*elem.pos(2)[1];
    T reg165=0.48801408404140807646*elem.pos(2)[0]; reg141=reg141+reg108; reg109=pow(reg109,0.5); T reg166=0.11091229182759258962*elem.pos(2)[2]; T reg167=reg1/reg142;
    reg10=reg55-reg10; reg103=reg104+reg103; reg55=3.942126756372672024*elem.pos(6)[1]; reg104=pow(reg158,2); reg106=reg29/reg106;
    reg24=reg45-reg24; reg45=pow(reg92,2); T reg168=3.2322880886760785326*elem.pos(2)[1]; T reg169=pow(reg94,2); reg142=reg33/reg142;
    T reg170=pow(reg105,2); T reg171=3.2322880886760785326*elem.pos(2)[0]; T reg172=reg151*reg160; reg110=reg110-reg166; reg148=pow(reg148,0.5);
    reg52=reg54-reg52; reg54=0.13944558288274043462*elem.pos(2)[2]; T reg173=reg118/reg109; T reg174=reg116/reg109; reg165=reg141+reg165;
    reg70=reg139+reg70; reg155=reg140+reg155; reg163=reg104+reg163; reg68=reg68+reg37; reg104=0.48801408404140807646*elem.pos(2)[2];
    reg152=reg53+reg152; reg83=reg10+reg83; reg124=reg30+reg124; reg157=reg157-reg107; reg55=reg103-reg55;
    reg10=reg162*reg69; reg30=reg164*reg146; reg53=3.942126756372672024*elem.pos(6)[2]; reg103=reg167*reg23; reg147=reg137+reg147;
    reg45=reg169+reg45; reg104=reg68+reg104; reg68=reg38/reg148; reg137=3.2322880886760785326*elem.pos(2)[2]; reg139=reg174*reg155;
    reg140=reg35/reg148; reg103=reg172+reg103; reg141=reg142*reg70; reg169=reg173*reg165; reg171=reg24+reg171;
    reg24=pow(reg152,2); reg109=reg80/reg109; reg30=reg10+reg30; reg54=reg52+reg54; reg170=reg163+reg170;
    reg10=pow(reg110,2); reg53=reg147-reg53; reg168=reg55+reg168; reg52=reg106*reg157; reg55=pow(reg83,2);
    reg124=pow(reg124,0.5); reg141=reg103+reg141; reg103=pow(reg171,2); reg147=pow(reg54,2); reg163=pow(reg168,2);
    reg24=reg55+reg24; reg148=reg50/reg148; reg170=pow(reg170,0.5); reg55=reg69*reg140; reg172=reg146*reg68;
    T reg175=reg109*reg104; reg10=reg45+reg10; reg45=reg41/reg124; reg137=reg53+reg137; reg53=reg113/reg124;
    reg52=reg30+reg52; reg139=reg169+reg139; reg30=reg167*reg141; reg163=reg103+reg163; reg103=reg158/reg170;
    reg169=reg78/reg170; T reg176=pow(reg137,2); reg172=reg55+reg172; reg55=reg157*reg148; T reg177=reg23*reg45;
    reg124=reg46/reg124; reg175=reg139+reg175; reg10=pow(reg10,0.5); reg139=reg162*reg52; reg147=reg24+reg147;
    reg24=reg160*reg53; T reg178=reg164*reg52; T reg179=reg151*reg141; reg176=reg163+reg176; reg163=reg174*reg175;
    T reg180=reg173*reg175; T reg181=reg155*reg169; reg177=reg24+reg177; reg30=reg23-reg30; reg24=reg142*reg141;
    T reg182=reg92/reg10; reg55=reg172+reg55; reg147=pow(reg147,0.5); reg179=reg160-reg179; reg172=reg165*reg103;
    reg139=reg69-reg139; T reg183=reg94/reg10; T reg184=reg70*reg124; reg170=reg105/reg170; T reg185=reg106*reg52;
    reg178=reg146-reg178; reg184=reg177+reg184; reg176=pow(reg176,0.5); reg177=pow(reg179,2); T reg186=pow(reg30,2);
    reg24=reg70-reg24; T reg187=reg152/reg147; T reg188=reg83/reg147; reg185=reg157-reg185; T reg189=pow(reg178,2);
    T reg190=pow(reg139,2); reg180=reg165-reg180; reg163=reg155-reg163; T reg191=reg109*reg175; T reg192=reg146*reg182;
    reg181=reg172+reg181; reg172=reg104*reg170; T reg193=reg68*reg55; T reg194=reg140*reg55; T reg195=reg69*reg183;
    reg10=reg110/reg10; reg172=reg181+reg172; reg186=reg177+reg186; reg177=pow(reg24,2); reg181=reg171/reg176;
    T reg196=reg168/reg176; T reg197=reg23*reg187; T reg198=reg160*reg188; reg147=reg54/reg147; T reg199=reg45*reg184;
    T reg200=pow(reg185,2); T reg201=reg53*reg184; reg189=reg190+reg189; reg191=reg104-reg191; reg190=reg157*reg10;
    T reg202=pow(reg163,2); reg194=reg69-reg194; T reg203=pow(reg180,2); reg192=reg195+reg192; reg193=reg146-reg193;
    reg195=reg148*reg55; T reg204=0.031249999999999996531*elem.pos(0)[1]; T reg205=reg103*reg172; T reg206=0.28124999999999993755*elem.pos(4)[1]; T reg207=0.031249999999999996531*elem.pos(0)[0];
    reg190=reg192+reg190; reg192=0.28124999999999993755*elem.pos(4)[0]; reg176=reg137/reg176; T reg208=reg165*reg181; T reg209=reg155*reg196;
    T reg210=reg70*reg147; reg197=reg198+reg197; reg198=reg169*reg172; T reg211=0.37392637586900058451*elem.pos(4)[1]; T reg212=0.24400704202070395239*elem.pos(0)[1];
    reg200=reg189+reg200; reg202=reg203+reg202; reg189=pow(reg191,2); reg203=0.37392637586900058451*elem.pos(4)[2]; T reg213=0.24400704202070395239*elem.pos(0)[2];
    T reg214=0.24400704202070395239*elem.pos(0)[0]; T reg215=pow(reg194,2); T reg216=pow(reg193,2); reg195=reg157-reg195; reg201=reg160-reg201;
    T reg217=0.37392637586900058451*elem.pos(4)[0]; T reg218=0.28124999999999993755*elem.pos(4)[2]; reg177=reg186+reg177; reg186=reg124*reg184; T reg219=0.031249999999999996531*elem.pos(0)[2];
    reg199=reg23-reg199; T reg220=0.14892637586900065821*elem.pos(4)[1]; T reg221=reg170*reg172; reg214=reg217+reg214; reg192=reg192-reg207;
    reg216=reg215+reg216; reg198=reg155-reg198; reg215=pow(reg199,2); reg217=pow(reg195,2); reg186=reg70-reg186;
    reg205=reg165-reg205; T reg222=0.14892637586900062074*elem.pos(5)[0]; reg189=reg202+reg189; reg202=pow(reg201,2); reg211=reg212+reg211;
    reg212=0.14892637586900062074*elem.pos(5)[1]; reg203=reg213+reg203; reg213=reg182*reg190; reg218=reg218-reg219; reg177=pow(reg177,0.5);
    T reg223=0.28125000000000003123*elem.pos(5)[2]; T reg224=0.14892637586900062074*elem.pos(5)[2]; T reg225=reg183*reg190; reg210=reg197+reg210; reg197=reg104*reg176;
    reg206=reg206-reg204; T reg226=0.28125000000000003123*elem.pos(5)[1]; reg209=reg208+reg209; reg208=0.030992957979296040822*elem.pos(0)[2]; T reg227=0.14892637586900065821*elem.pos(4)[2];
    reg200=pow(reg200,0.5); T reg228=0.030992957979296040822*elem.pos(0)[1]; T reg229=0.28125000000000003123*elem.pos(5)[0]; T reg230=0.14892637586900065821*elem.pos(4)[0]; T reg231=0.030992957979296040822*elem.pos(0)[0];
    T reg232=0.373926375869000622*elem.pos(5)[1]; reg228=reg228-reg220; reg197=reg209+reg197; reg189=pow(reg189,0.5); reg209=pow(reg205,2);
    T reg233=pow(reg198,2); reg221=reg104-reg221; reg224=reg203-reg224; reg139=reg139/reg200; reg203=reg187*reg210;
    reg178=reg178/reg200; T reg234=reg188*reg210; T reg235=0.030992957979296029919*elem.pos(1)[1]; reg212=reg211-reg212; reg211=0.49910531322416709662*elem.pos(4)[2];
    T reg236=0.055456145913796350227*elem.pos(0)[2]; T reg237=0.030992957979296029919*elem.pos(1)[2]; reg30=reg30/reg177; reg206=reg206+reg226; T reg238=0.031249999999999996531*elem.pos(1)[1];
    T reg239=0.031249999999999996531*elem.pos(1)[2]; T reg240=0.031249999999999996531*elem.pos(1)[0]; reg192=reg192+reg229; reg231=reg231-reg230; reg179=reg179/reg177;
    T reg241=0.373926375869000622*elem.pos(5)[0]; reg208=reg208-reg227; T reg242=0.373926375869000622*elem.pos(5)[2]; reg225=reg69-reg225; T reg243=0.055456145913796350227*elem.pos(0)[1];
    reg218=reg218+reg223; T reg244=0.49910531322416709662*elem.pos(4)[1]; T reg245=0.030992957979296029919*elem.pos(1)[0]; reg222=reg214-reg222; reg217=reg216+reg217;
    reg214=pow(reg186,2); reg213=reg146-reg213; reg215=reg202+reg215; reg202=0.49910531322416709662*elem.pos(4)[0]; reg216=reg10*reg190;
    T reg246=0.055456145913796350227*elem.pos(0)[0]; T reg247=reg18*reg178; reg206=reg206-reg238; T reg248=0.031249999999999996531*elem.pos(3)[1]; T reg249=reg8*reg139;
    reg200=reg185/reg200; reg178=reg146*reg178; reg185=pow(reg213,2); T reg250=pow(reg225,2); reg216=reg157-reg216;
    reg237=reg224+reg237; reg224=0.24400704202070395239*elem.pos(3)[2]; reg139=reg69*reg139; reg208=reg208+reg242; T reg251=0.43301408404140791412*elem.pos(0)[0];
    T reg252=0.24400704202070403823*elem.pos(1)[2]; T reg253=0.66356850115866743183*elem.pos(4)[0]; reg180=reg180/reg189; reg217=pow(reg217,0.5); reg163=reg163/reg189;
    T reg254=0.49910531322416726286*elem.pos(5)[0]; reg202=reg202-reg246; reg218=reg218-reg239; T reg255=0.031249999999999996531*elem.pos(3)[2]; T reg256=reg196*reg197;
    T reg257=reg13*reg179; T reg258=0.66356850115866743183*elem.pos(4)[1]; T reg259=0.43301408404140791412*elem.pos(0)[1]; T reg260=reg1*reg30; T reg261=reg181*reg197;
    reg228=reg228+reg232; T reg262=0.24400704202070403823*elem.pos(1)[1]; reg164=reg18*reg164; reg18=0.031249999999999996531*elem.pos(3)[0]; reg192=reg192-reg240;
    reg162=reg8*reg162; reg231=reg231+reg241; reg8=0.24400704202070403823*elem.pos(1)[0]; T reg263=0.66356850115866743183*elem.pos(4)[2]; T reg264=0.24400704202070395239*elem.pos(3)[0];
    T reg265=0.43301408404140791412*elem.pos(0)[2]; reg214=reg215+reg214; reg245=reg222+reg245; reg235=reg212+reg235; reg151=reg13*reg151;
    reg13=0.24400704202070395239*elem.pos(3)[1]; reg234=reg160-reg234; reg179=reg160*reg179; reg203=reg23-reg203; reg30=reg23*reg30;
    reg212=reg147*reg210; reg167=reg1*reg167; reg244=reg244-reg243; reg211=reg211-reg236; reg1=0.49910531322416726286*elem.pos(5)[1];
    reg215=pow(reg221,2); reg233=reg209+reg233; reg209=0.49910531322416726286*elem.pos(5)[2]; reg177=reg24/reg177; reg264=reg245+reg264;
    reg167=reg151+reg167; reg24=0.37392637586900058451*elem.pos(7)[0]; reg151=0.030992957979296040822*elem.pos(3)[0]; reg142=reg33*reg142; reg8=reg231+reg8;
    reg33=reg33*reg177; reg222=pow(reg216,2); reg231=0.37392637586900058451*elem.pos(7)[2]; reg245=0.055456145913796350227*elem.pos(1)[0]; reg30=reg179+reg30;
    reg260=reg257+reg260; reg224=reg237+reg224; reg177=reg70*reg177; reg247=reg249+reg247; reg179=reg29*reg200;
    reg200=reg157*reg200; reg237=0.26428425057933379666*elem.pos(4)[2]; reg178=reg139+reg178; reg139=0.055000000000000010008*elem.pos(0)[2]; reg249=pow(reg234,2);
    reg257=pow(reg203,2); reg212=reg70-reg212; reg173=reg118*reg173; reg174=reg116*reg174; T reg266=reg176*reg197;
    reg256=reg155-reg256; T reg267=reg165*reg180; reg261=reg165-reg261; T reg268=reg155*reg163; reg189=reg191/reg189;
    reg180=reg118*reg180; reg163=reg116*reg163; reg218=reg218-reg255; reg116=0.28124999999999993755*elem.pos(7)[2]; reg118=0.26428425057933373015*elem.pos(5)[2];
    reg263=reg265+reg263; reg211=reg211+reg209; reg191=0.055456145913796350227*elem.pos(1)[2]; reg202=reg202+reg254; reg265=0.030992957979296040822*elem.pos(3)[2];
    reg252=reg208+reg252; reg194=reg194/reg217; reg214=pow(reg214,0.5); reg164=reg162+reg164; reg106=reg29*reg106;
    reg193=reg193/reg217; reg258=reg259+reg258; reg29=0.26428425057933373015*elem.pos(5)[1]; reg162=0.26428425057933379666*elem.pos(4)[1]; reg208=0.055000000000000010008*elem.pos(0)[1];
    reg215=reg233+reg215; reg233=0.37392637586900058451*elem.pos(7)[1]; reg13=reg235+reg13; reg235=0.28124999999999993755*elem.pos(7)[1]; reg206=reg206-reg248;
    reg251=reg253+reg251; reg253=0.26428425057933373015*elem.pos(5)[0]; reg259=0.055456145913796350227*elem.pos(1)[1]; reg192=reg192-reg18; T reg269=0.28124999999999993755*elem.pos(7)[0];
    T reg270=0.055000000000000010008*elem.pos(0)[0]; T reg271=0.26428425057933379666*elem.pos(4)[0]; reg262=reg228+reg262; reg244=reg244+reg1; reg185=reg250+reg185;
    reg228=0.030992957979296040822*elem.pos(3)[1]; reg250=pow(reg212,2); reg215=pow(reg215,0.5); reg257=reg249+reg257; reg249=0.14892637586900062074*elem.pos(6)[1];
    reg233=reg13+reg233; reg228=reg262+reg228; reg13=0.14892637586900065821*elem.pos(7)[1]; reg177=reg30+reg177; reg30=0.063394686775832778473*elem.pos(4)[0];
    reg262=0.0070438540862036428341*elem.pos(0)[0]; reg179=reg247+reg179; reg247=0.66356850115866749835*elem.pos(5)[0]; reg200=reg178+reg200; reg270=reg270-reg271;
    reg178=0.28125000000000003123*elem.pos(6)[1]; reg235=reg206+reg235; reg142=reg167+reg142; reg167=0.054999999999999990659*elem.pos(1)[0]; reg253=reg251-reg253;
    reg206=0.14892637586900065821*elem.pos(7)[0]; reg251=0.063394686775832778473*elem.pos(4)[1]; T reg272=0.0070438540862036428341*elem.pos(0)[1]; T reg273=0.14892637586900062074*elem.pos(6)[0]; reg24=reg264+reg24;
    reg199=reg199/reg214; reg201=reg201/reg214; reg264=0.0070438540862036428341*elem.pos(3)[2]; reg151=reg8+reg151; reg211=reg211-reg191;
    reg8=0.0070438540862036428341*elem.pos(3)[1]; reg244=reg244-reg259; T reg274=0.28125000000000003123*elem.pos(6)[0]; reg118=reg263-reg118; reg263=0.054999999999999990659*elem.pos(1)[2];
    reg106=reg164+reg106; reg33=reg260+reg33; reg164=pow(reg261,2); reg269=reg192+reg269; reg192=pow(reg256,2);
    reg29=reg258-reg29; reg266=reg104-reg266; reg258=0.054999999999999990659*elem.pos(1)[1]; reg163=reg180+reg163; reg180=reg80*reg189;
    reg260=reg38*reg193; T reg275=reg35*reg194; reg116=reg218+reg116; reg218=0.28125000000000003123*elem.pos(6)[2]; reg217=reg195/reg217;
    reg193=reg146*reg193; reg139=reg139-reg237; reg195=0.66356850115866749835*elem.pos(5)[2]; T reg276=0.14892637586900065821*elem.pos(7)[2]; reg265=reg252+reg265;
    reg194=reg69*reg194; reg208=reg208-reg162; reg68=reg38*reg68; reg140=reg35*reg140; reg35=0.66356850115866749835*elem.pos(5)[1];
    reg38=0.0070438540862036428341*elem.pos(0)[2]; reg252=0.14892637586900062074*elem.pos(6)[2]; reg231=reg224+reg231; reg224=0.063394686775832778473*elem.pos(4)[2]; reg202=reg202-reg245;
    reg222=reg185+reg222; reg185=0.0070438540862036428341*elem.pos(3)[0]; reg268=reg267+reg268; reg189=reg104*reg189; reg174=reg173+reg174;
    reg109=reg80*reg109; reg80=0.063394686775832778473*elem.pos(7)[1]; reg214=reg186/reg214; reg167=reg253+reg167; reg151=reg151-reg206;
    reg173=0.373926375869000622*elem.pos(6)[0]; reg251=reg251-reg272; reg186=reg23*reg199; reg253=0.030992957979296029919*elem.pos(2)[0]; reg273=reg24-reg273;
    reg68=reg140+reg68; reg24=0.084284250579333737197*elem.pos(4)[0]; reg140=0.054999999999999990659*elem.pos(0)[1]; reg267=0.054999999999999990659*elem.pos(0)[0]; T reg277=reg160*reg201;
    T reg278=0.084284250579333737197*elem.pos(4)[1]; T reg279=0.063394686775832778473*elem.pos(7)[2]; reg211=reg211-reg264; reg148=reg50*reg148; reg202=reg202-reg185;
    T reg280=0.063394686775832778473*elem.pos(7)[0]; reg270=reg270+reg247; T reg281=0.43301408404140806645*elem.pos(1)[0]; T reg282=0.373926375869000622*elem.pos(6)[1]; reg228=reg228-reg13;
    T reg283=0.063394686775832799587*elem.pos(5)[2]; reg177=reg142*reg177; reg142=0.43301408404140806645*elem.pos(1)[1]; reg208=reg208+reg35; reg224=reg224-reg38;
    reg109=reg174+reg109; reg174=0.054999999999999990659*elem.pos(3)[1]; reg33=reg141*reg33; reg222=pow(reg222,0.5); reg141=0.063394686775832799587*elem.pos(5)[1];
    reg252=reg231-reg252; reg231=0.030992957979296029919*elem.pos(2)[2]; reg199=reg41*reg199; reg201=reg113*reg201; reg244=reg244-reg8;
    reg193=reg194+reg193; reg194=0.054999999999999990659*elem.pos(3)[0]; reg192=reg164+reg192; reg164=reg157*reg217; T reg284=pow(reg266,2);
    reg258=reg29+reg258; reg250=reg257+reg250; reg29=0.063394686775832799587*elem.pos(5)[0]; reg180=reg163+reg180; reg205=reg205/reg215;
    reg179=reg52*reg179; reg198=reg198/reg215; reg52=0.030992957979296029919*elem.pos(2)[1]; reg249=reg233-reg249; reg30=reg30-reg262;
    reg260=reg275+reg260; reg217=reg50*reg217; reg116=reg116+reg218; reg50=0.084284250579333737197*elem.pos(4)[2]; reg163=0.054999999999999990659*elem.pos(0)[2];
    reg233=0.031249999999999996531*elem.pos(2)[2]; reg189=reg268+reg189; reg269=reg269+reg274; reg257=0.031249999999999996531*elem.pos(2)[0]; reg268=0.373926375869000622*elem.pos(6)[2];
    reg275=0.43301408404140806645*elem.pos(1)[2]; reg263=reg118+reg263; reg118=0.054999999999999990659*elem.pos(3)[2]; reg53=reg113*reg53; reg45=reg41*reg45;
    reg265=reg265-reg276; reg139=reg139+reg195; reg235=reg235+reg178; reg200=reg106*reg200; reg41=0.031249999999999996531*elem.pos(2)[1];
    reg278=reg140+reg278; reg106=0.063394686775832799587*elem.pos(6)[1]; reg113=0.24400704202070403823*elem.pos(2)[1]; reg228=reg228+reg282; reg140=0.0069859159585920716348*elem.pos(0)[1];
    reg116=reg116-reg233; T reg285=0.0069859159585920716348*elem.pos(3)[1]; reg142=reg208+reg142; reg52=reg249+reg52; reg265=reg265+reg268;
    reg80=reg244+reg80; reg208=0.084284250579333737197*elem.pos(7)[1]; reg244=0.0070438540862036428341*elem.pos(1)[1]; reg251=reg251+reg141; reg284=reg192+reg284;
    reg174=reg258+reg174; reg192=0.24400704202070403823*elem.pos(2)[2]; reg249=0.033568501158667511326*elem.pos(5)[1]; reg258=0.033568501158667519769*elem.pos(4)[1]; reg235=reg235-reg41;
    reg231=reg252+reg231; reg225=reg225/reg222; reg252=reg70*reg214; reg213=reg213/reg222; reg186=reg277+reg186;
    reg124=reg46*reg124; reg45=reg53+reg45; reg53=0.0069859159585920716348*elem.pos(0)[2]; reg277=0.084284250579333737197*elem.pos(7)[0]; reg194=reg167+reg194;
    reg167=0.033568501158667519769*elem.pos(4)[2]; reg267=reg24+reg267; reg24=0.033568501158667511326*elem.pos(5)[0]; reg217=reg260+reg217; reg164=reg193+reg164;
    reg148=reg68+reg148; reg68=0.0069859159585920716348*elem.pos(3)[2]; reg275=reg139+reg275; reg215=reg221/reg215; reg50=reg163+reg50;
    reg139=reg158*reg205; reg163=reg78*reg198; reg198=reg155*reg198; reg205=reg165*reg205; reg169=reg78*reg169;
    reg30=reg30+reg29; reg78=0.0070438540862036428341*elem.pos(1)[0]; reg103=reg158*reg103; reg158=0.033568501158667511326*elem.pos(5)[2]; reg193=0.0069859159585920716348*elem.pos(3)[0];
    reg281=reg270+reg281; reg221=0.0070438540862036428341*elem.pos(1)[2]; reg224=reg224+reg283; reg214=reg46*reg214; reg199=reg201+reg199;
    reg279=reg211+reg279; reg46=0.063394686775832799587*elem.pos(6)[2]; reg201=0.0069859159585920716348*elem.pos(0)[0]; reg211=0.033568501158667519769*elem.pos(4)[0]; reg118=reg263+reg118;
    reg260=0.084284250579333737197*elem.pos(7)[2]; reg269=reg269-reg257; reg179=reg200-reg179; reg253=reg273+reg253; reg33=reg177-reg33;
    reg151=reg151+reg173; reg177=0.24400704202070403823*elem.pos(2)[0]; reg189=reg109*reg189; reg180=reg175*reg180; reg250=pow(reg250,0.5);
    reg280=reg202+reg280; reg109=0.063394686775832799587*elem.pos(6)[0]; reg164=reg148*reg164; reg193=reg281+reg193; reg148=0.033568501158667519769*elem.pos(7)[0];
    reg175=0.0069859159585920691772*elem.pos(1)[2]; reg158=reg50-reg158; reg285=reg142+reg285; reg249=reg278-reg249; reg50=0.0069859159585920691772*elem.pos(1)[1];
    reg169=reg103+reg169; reg170=reg105*reg170; reg103=0.084284250579333745647*elem.pos(5)[1]; reg140=reg140-reg258; reg52=reg33*reg52;
    reg280=reg280+reg109; reg198=reg205+reg198; reg142=0.0070438540862036428341*elem.pos(2)[0]; reg53=reg53-reg167; reg177=reg151+reg177;
    reg277=reg194+reg277; reg151=0.033568501158667511326*elem.pos(6)[0]; reg194=0.084284250579333745647*elem.pos(5)[2]; reg208=reg174+reg208; reg253=reg253*reg33;
    reg174=0.0070438540862036428341*elem.pos(2)[1]; reg80=reg80+reg106; reg124=reg45+reg124; reg251=reg251-reg244; reg45=0.055456145913796350227*elem.pos(3)[1];
    reg200=0.033568501158667511326*elem.pos(6)[1]; reg116=reg179*reg116; reg252=reg186+reg252; reg269=reg269*reg179; reg180=reg189-reg180;
    reg214=reg199+reg214; reg217=reg55*reg217; reg55=0.033568501158667519769*elem.pos(7)[1]; reg113=reg228+reg113; reg183=reg94*reg183;
    reg182=reg92*reg182; reg69=reg69*reg225; reg146=reg146*reg213; reg222=reg216/reg222; reg225=reg94*reg225;
    reg213=reg92*reg213; reg231=reg33*reg231; reg92=0.033568501158667519769*elem.pos(7)[2]; reg24=reg267-reg24; reg94=0.0069859159585920691772*elem.pos(1)[0];
    reg68=reg275+reg68; reg192=reg265+reg192; reg234=reg234/reg250; reg284=pow(reg284,0.5); reg203=reg203/reg250;
    reg186=0.033568501158667511326*elem.pos(6)[2]; reg260=reg118+reg260; reg201=reg201-reg211; reg118=0.084284250579333745647*elem.pos(5)[0]; reg189=0.0070438540862036428341*elem.pos(2)[2];
    reg279=reg279+reg46; reg105=reg105*reg215; reg199=0.055456145913796350227*elem.pos(3)[0]; reg163=reg139+reg163; reg139=0.055456145913796350227*elem.pos(3)[2];
    reg30=reg30-reg78; reg235=reg179*reg235; reg224=reg224-reg221; reg215=reg104*reg215; reg202=0.0069859159585920691772*elem.pos(2)[2];
    reg23=reg23*reg203; reg253=0.12345679012345679715*reg253; reg170=reg169+reg170; reg160=reg160*reg234; reg261=reg261/reg284;
    reg256=reg256/reg284; reg169=0.49910531322416709662*elem.pos(7)[2]; reg177=reg177*reg180; reg205=0.055000000000000010008*elem.pos(1)[2]; reg192=reg180*reg192;
    reg187=reg152*reg187; reg53=reg53+reg194; reg216=0.084284250579333745647*elem.pos(6)[1]; reg285=reg285-reg55; reg215=reg198+reg215;
    reg279=reg279-reg189; reg140=reg140+reg103; reg198=0.055000000000000010008*elem.pos(1)[1]; reg228=0.43301408404140791412*elem.pos(3)[1]; reg50=reg249+reg50;
    reg249=0.055000000000000010008*elem.pos(1)[0]; reg201=reg201+reg118; reg52=0.12345679012345679715*reg52; reg179=0.19753086419753085323*reg179; reg203=reg152*reg203;
    reg234=reg83*reg234; reg269=0.19753086419753085323*reg269; reg105=reg163+reg105; reg186=reg260-reg186; reg152=0.49910531322416709662*elem.pos(7)[1];
    reg251=reg251-reg45; reg250=reg212/reg250; reg163=reg110*reg222; reg151=reg277-reg151; reg212=0.0069859159585920691772*elem.pos(2)[0];
    reg213=reg225+reg213; reg116=0.19753086419753085323*reg116; reg193=reg193-reg148; reg30=reg30-reg199; reg80=reg80-reg174;
    reg222=reg157*reg222; reg157=0.49910531322416709662*elem.pos(7)[0]; reg146=reg69+reg146; reg224=reg224-reg139; reg10=reg110*reg10;
    reg252=reg124*reg252; reg182=reg183+reg182; reg113=reg180*reg113; reg214=reg184*reg214; reg69=0.43301408404140791412*elem.pos(3)[2];
    reg175=reg158+reg175; reg188=reg83*reg188; reg280=reg280-reg142; reg235=0.19753086419753085323*reg235; reg83=0.43301408404140791412*elem.pos(3)[0];
    reg94=reg24+reg94; reg217=reg164-reg217; reg33=0.12345679012345679715*reg33; reg24=0.0069859159585920691772*elem.pos(2)[1]; reg200=reg208-reg200;
    reg110=0.084284250579333745647*elem.pos(6)[0]; reg231=0.12345679012345679715*reg231; reg124=0.084284250579333745647*elem.pos(6)[2]; reg68=reg68-reg92; reg198=reg140+reg198;
    reg140=0.055000000000000010008*elem.pos(3)[1]; reg158=0.49910531322416726286*elem.pos(6)[2]; reg164=0.055000000000000010008*elem.pos(3)[2]; reg68=reg68+reg124; reg231=reg116+reg231;
    reg202=reg186+reg202; reg205=reg53+reg205; reg192=0.12345679012345679715*reg192; reg169=reg224+reg169; reg53=0.66356850115866743183*elem.pos(7)[2];
    reg279=reg217*reg279; reg69=reg175+reg69; reg116=0.055000000000000010008*elem.pos(2)[2]; reg165=reg165*reg261; reg155=reg155*reg256;
    reg284=reg266/reg284; reg261=reg171*reg261; reg256=reg168*reg256; reg33=reg179+reg33; reg180=0.12345679012345679715*reg180;
    reg105=reg172*reg105; reg215=reg170*reg215; reg170=0.055000000000000010008*elem.pos(2)[0]; reg193=reg193+reg110; reg214=reg252-reg214;
    reg52=reg235+reg52; reg113=0.12345679012345679715*reg113; reg80=reg217*reg80; reg24=reg200+reg24; reg285=reg285+reg216;
    reg83=reg94+reg83; reg94=0.66356850115866743183*elem.pos(7)[0]; reg187=reg188+reg187; reg147=reg54*reg147; reg222=reg146+reg222;
    reg23=reg160+reg23; reg70=reg70*reg250; reg203=reg234+reg203; reg250=reg54*reg250; reg10=reg182+reg10;
    reg249=reg201+reg249; reg54=0.055000000000000010008*elem.pos(3)[0]; reg146=0.49910531322416726286*elem.pos(6)[0]; reg157=reg30+reg157; reg163=reg213+reg163;
    reg181=reg171*reg181; reg196=reg168*reg196; reg280=reg280*reg217; reg177=0.12345679012345679715*reg177; reg253=reg269+reg253;
    reg212=reg151+reg212; reg30=0.49910531322416726286*elem.pos(6)[1]; reg228=reg50+reg228; reg152=reg251+reg152; reg50=0.66356850115866743183*elem.pos(7)[1];
    reg151=0.055000000000000010008*elem.pos(2)[1]; reg104=reg104*reg284; reg192=reg231+reg192; reg177=reg253+reg177; reg155=reg165+reg155;
    reg116=reg68+reg116; reg163=reg190*reg163; reg176=reg137*reg176; reg196=reg181+reg196; reg94=reg83+reg94;
    reg68=0.26428425057933379666*elem.pos(7)[1]; reg140=reg198+reg140; reg83=0.26428425057933379666*elem.pos(7)[0]; reg54=reg249+reg54; reg279=0.12345679012345679715*reg279;
    reg164=reg205+reg164; reg160=0.26428425057933379666*elem.pos(7)[2]; reg165=0.26428425057933373015*elem.pos(6)[0]; reg157=reg157+reg146; reg168=0.055456145913796350227*elem.pos(2)[0];
    reg222=reg10*reg222; reg202=reg214*reg202; reg250=reg203+reg250; reg147=reg187+reg147; reg50=reg228+reg50;
    reg70=reg23+reg70; reg10=0.26428425057933373015*elem.pos(6)[1]; reg24=reg214*reg24; reg151=reg285+reg151; reg80=0.12345679012345679715*reg80;
    reg113=reg52+reg113; reg23=0.26428425057933373015*elem.pos(6)[2]; reg53=reg69+reg53; reg212=reg212*reg214; reg152=reg152+reg30;
    reg170=reg193+reg170; reg52=0.055456145913796350227*elem.pos(2)[1]; reg217=0.12345679012345679715*reg217; reg180=reg33+reg180; reg284=reg137*reg284;
    reg105=reg215-reg105; reg280=0.12345679012345679715*reg280; reg256=reg261+reg256; reg169=reg169+reg158; reg33=0.055456145913796350227*elem.pos(2)[2];
    reg70=reg147*reg70; reg69=0.054999999999999990659*elem.pos(2)[2]; reg104=reg155+reg104; reg10=reg50-reg10; reg151=reg105*reg151;
    reg170=reg170*reg105; reg202=0.077160493827160489544*reg202; reg50=0.054999999999999990659*elem.pos(2)[1]; reg164=reg164-reg160; reg137=0.66356850115866749835*elem.pos(6)[2];
    reg80=reg113+reg80; reg113=0.054999999999999990659*elem.pos(2)[0]; reg165=reg94-reg165; reg24=0.077160493827160489544*reg24; reg23=reg53-reg23;
    reg280=reg177+reg280; reg53=0.66356850115866749835*elem.pos(6)[1]; reg140=reg140-reg68; reg176=reg196+reg176; reg217=reg180+reg217;
    reg94=0.66356850115866749835*elem.pos(6)[0]; reg54=reg54-reg83; reg214=0.077160493827160489544*reg214; reg152=reg152-reg52; reg279=reg192+reg279;
    reg169=reg169-reg33; reg116=reg105*reg116; reg212=0.077160493827160489544*reg212; reg157=reg157-reg168; reg250=reg210*reg250;
    reg284=reg256+reg284; reg163=reg222-reg163; reg116=0.077160493827160489544*reg116; reg170=0.077160493827160489544*reg170; reg169=reg163*reg169;
    reg212=reg280+reg212; reg69=reg23+reg69; reg164=reg164+reg137; reg23=0.43301408404140806645*elem.pos(2)[2]; reg147=0.43301408404140806645*elem.pos(2)[1];
    reg140=reg140+reg53; reg152=reg163*reg152; reg151=0.077160493827160489544*reg151; reg24=reg80+reg24; reg50=reg10+reg50;
    reg105=0.077160493827160489544*reg105; reg214=reg217+reg214; reg284=reg197*reg284; reg104=reg176*reg104; reg10=0.43301408404140806645*elem.pos(2)[0];
    reg113=reg165+reg113; reg202=reg279+reg202; reg250=reg70-reg250; reg157=reg157*reg163; reg54=reg54+reg94;
    reg151=reg24+reg151; reg69=reg250*reg69; reg50=reg250*reg50; reg170=reg212+reg170; reg152=0.12345679012345679715*reg152;
    reg163=0.12345679012345679715*reg163; reg105=reg214+reg105; reg10=reg54+reg10; reg113=reg113*reg250; reg23=reg164+reg23;
    reg116=reg202+reg116; reg169=0.12345679012345679715*reg169; reg157=0.12345679012345679715*reg157; reg284=reg104-reg284; reg147=reg140+reg147;
    reg69=0.077160493827160489544*reg69; reg147=reg284*reg147; reg157=reg170+reg157; reg152=reg151+reg152; reg50=0.077160493827160489544*reg50;
    reg250=0.077160493827160489544*reg250; reg163=reg105+reg163; reg169=reg116+reg169; reg23=reg284*reg23; reg10=reg10*reg284;
    reg113=0.077160493827160489544*reg113; reg50=reg152+reg50; reg23=0.077160493827160489544*reg23; reg147=0.077160493827160489544*reg147; reg69=reg169+reg69;
    reg284=0.077160493827160489544*reg284; reg250=reg163+reg250; reg10=0.077160493827160489544*reg10; reg113=reg157+reg113; reg147=reg50+reg147;
    reg284=reg250+reg284; reg10=reg113+reg10; reg23=reg69+reg23; res[2]=reg23/reg284; res[1]=reg147/reg284;
    res[0]=reg10/reg284;

    return res;
}
}
#endif // LMT_QUAD_42
