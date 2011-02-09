#ifndef LMT_TETRA
#define LMT_TETRA
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Tetra &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 5, 10, 27, 48, 109, 170, 231, 292, 353, }; // fonction de lordre du poly
    static const double values[] = {
        0.166666666667,0.25,0.25,0.25,
        0.0,
        0.166666666667,0.25,0.25,0.25,
        0.0,
        0.0416666666667,0.138196601125,0.138196601125,0.138196601125,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
        0.0,
        -0.133333333333,0.25,0.25,0.25,
        0.075,0.166666666667,0.166666666667,0.166666666667,
        0.075,0.5,0.166666666667,0.166666666667,
        0.075,0.166666666667,0.5,0.166666666667,
        0.075,0.166666666667,0.166666666667,0.5,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Tetra &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=nodes[3]->pos[1]-nodes[0]->pos[1]; T reg1=nodes[2]->pos[2]-nodes[0]->pos[2]; T reg2=nodes[1]->pos[1]-nodes[0]->pos[1]; T reg3=nodes[3]->pos[2]-nodes[0]->pos[2]; T reg4=nodes[2]->pos[1]-nodes[0]->pos[1];
    T reg5=nodes[1]->pos[2]-nodes[0]->pos[2]; T reg6=reg3*reg2; T reg7=reg0*reg5; reg3=reg4*reg3; reg0=reg1*reg0;
    T reg8=nodes[2]->pos[0]-nodes[0]->pos[0]; T reg9=nodes[1]->pos[0]-nodes[0]->pos[0]; reg0=reg3-reg0; reg7=reg6-reg7; reg2=reg1*reg2;
    reg5=reg4*reg5; reg0=reg9*reg0; reg7=reg8*reg7; reg1=nodes[3]->pos[0]-nodes[0]->pos[0]; reg5=reg2-reg5;
    reg7=reg0-reg7; reg5=reg1*reg5; T det_jac=reg7+reg5;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1],nodes[3]};
        for(unsigned i=0;i<4;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Tetra &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=pos_nodes[2][0]-pos_nodes[0][0]; T reg1=pos_nodes[3][0]-pos_nodes[0][0]; T reg2=pos_nodes[2][1]-pos_nodes[0][1]; T reg3=pos_nodes[3][1]-pos_nodes[0][1]; T reg4=pos_nodes[2][2]-pos_nodes[0][2];
    T reg5=pos_nodes[3][2]-pos_nodes[0][2]; T reg6=reg2*reg5; T reg7=reg3*reg4; T reg8=reg0*reg5; T reg9=reg1*reg4;
    T reg10=pos_nodes[1][0]-pos_nodes[0][0]; reg7=reg6-reg7; T reg11=reg0*reg3; T reg12=pos_nodes[1][1]-pos_nodes[0][1]; T reg13=reg1*reg2;
    reg9=reg8-reg9; reg13=reg11-reg13; T reg14=pos_nodes[1][2]-pos_nodes[0][2]; T reg15=reg9*reg12; T reg16=reg7*reg10;
    T reg17=reg13*reg14; T reg18=reg12*reg5; T reg19=reg3*reg14; T reg20=reg12*reg4; reg16=reg15-reg16;
    reg15=reg0*reg14; T reg21=reg10*reg4; T reg22=reg2*reg14; T reg23=reg1*reg14; T reg24=reg10*reg5;
    T reg25=reg0*reg12; T reg26=reg10*reg2; reg17=reg16-reg17; reg19=reg18-reg19; reg16=reg1*reg12;
    T reg27=reg10*reg3; reg22=reg20-reg22; reg23=reg24-reg23; reg15=reg21-reg15; reg16=reg27-reg16;
    reg15=reg15/reg17; reg23=reg23/reg17; reg9=reg9/reg17; reg22=reg22/reg17; reg19=reg19/reg17;
    reg7=reg7/reg17; T reg28=pos[1]-pos_nodes[0][1]; T reg29=pos[0]-pos_nodes[0][0]; reg25=reg26-reg25; reg7=reg29*reg7;
    T reg30=pos[2]-pos_nodes[0][2]; reg9=reg28*reg9; reg19=reg29*reg19; reg23=reg28*reg23; reg22=reg29*reg22;
    reg13=reg13/reg17; reg15=reg28*reg15; reg25=reg25/reg17; reg17=reg16/reg17; reg25=reg30*reg25;
    reg23=reg19-reg23; reg17=reg30*reg17; reg22=reg15-reg22; reg7=reg9-reg7; reg13=reg30*reg13;
    var_inter[1]=reg17+reg23; var_inter[0]=reg7-reg13; var_inter[2]=reg22-reg25;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=pos_nodes[2][1]-pos_nodes[0][1]; T reg2=pos_nodes[3][2]-pos_nodes[0][2]; T reg3=pos_nodes[3][0]-pos_nodes[0][0]; T reg4=pos_nodes[2][0]-pos_nodes[0][0];
    T reg5=pos_nodes[2][2]-pos_nodes[0][2]; reg0=reg0-var_inter[1]; T reg6=pos_nodes[3][1]-pos_nodes[0][1]; reg0=reg0-var_inter[2]; T reg7=reg3*reg5;
    T reg8=reg4*reg2; T reg9=reg1*reg2; T reg10=reg6*reg5; T reg11=pos_nodes[1][1]*var_inter[0]; T reg12=pos_nodes[0][1]*reg0;
    T reg13=pos_nodes[1][1]-pos_nodes[0][1]; reg10=reg9-reg10; T reg14=reg4*reg6; T reg15=pos_nodes[1][0]*var_inter[0]; T reg16=pos_nodes[0][0]*reg0;
    T reg17=reg3*reg1; reg7=reg8-reg7; T reg18=pos_nodes[1][0]-pos_nodes[0][0]; T reg19=pos_nodes[1][2]-pos_nodes[0][2]; T reg20=pos_nodes[0][2]*reg0;
    T reg21=pos_nodes[1][2]*var_inter[0]; T reg22=reg18*reg10; T reg23=reg13*reg7; reg17=reg14-reg17; reg15=reg16+reg15;
    reg16=var_inter[1]*pos_nodes[2][1]; reg11=reg12+reg11; reg12=var_inter[1]*pos_nodes[2][0]; T reg24=reg3*reg19; T reg25=reg19*reg17;
    T reg26=reg18*reg5; reg12=reg15+reg12; reg15=var_inter[2]*pos_nodes[3][0]; T reg27=reg18*reg2; T reg28=reg13*reg2;
    T reg29=reg6*reg19; T reg30=reg13*reg5; T reg31=reg4*reg19; T reg32=var_inter[1]*pos_nodes[2][2]; reg21=reg20+reg21;
    reg16=reg11+reg16; reg11=var_inter[2]*pos_nodes[3][1]; reg20=reg1*reg19; reg22=reg23-reg22; reg31=reg26-reg31;
    reg25=reg22-reg25; reg29=reg28-reg29; reg20=reg30-reg20; reg22=reg4*reg13; reg24=reg27-reg24;
    reg15=reg12+reg15; reg12=reg18*reg1; reg23=reg18*reg6; T reg33=var_inter[2]*pos_nodes[3][2]; reg32=reg21+reg32;
    reg11=reg16+reg11; reg16=reg3*reg13; reg22=reg12-reg22; reg16=reg23-reg16; reg31=reg31/reg25;
    reg7=reg7/reg25; reg24=reg24/reg25; reg15=pos[0]-reg15; reg11=pos[1]-reg11; reg33=reg32+reg33;
    reg10=reg10/reg25; reg29=reg29/reg25; reg20=reg20/reg25; reg33=pos[2]-reg33; reg17=reg17/reg25;
    reg16=reg16/reg25; reg25=reg22/reg25; reg10=reg15*reg10; reg7=reg7*reg11; reg31=reg11*reg31;
    reg29=reg15*reg29; reg24=reg24*reg11; reg20=reg15*reg20; reg20=reg31-reg20; reg25=reg33*reg25;
    reg24=reg29-reg24; reg16=reg33*reg16; reg10=reg7-reg10; reg17=reg33*reg17; var_inter[1]+=reg16+reg24;
    var_inter[0]+=reg10-reg17; var_inter[2]+=reg20-reg25;

}
template<> struct ElemVarInterFromPosNonLinear<Tetra> { static const bool res = 0; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=val[0]*reg0; T reg2=val[1]*var_inter[0];
    T reg3=val[2]*var_inter[1]; reg2=reg1+reg2; reg1=val[3]*var_inter[2]; reg3=reg2+reg3; res=reg3+reg1;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_1
#define STRUCT_Gauss_1
struct Gauss_1 {};
#endif // STRUCT_Gauss_1
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Gauss_1 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=var_inter[0]-0.25; T reg1=0.25+reg0; T reg2=var_inter[1]-0.25; reg1=reg1/0.25; T reg3=0.25+reg2;
    reg3=reg1*reg3; reg1=var_inter[2]-0.25; reg3=reg3/0.25; T reg4=0.25+reg1; reg4=reg3*reg4;
    reg4=reg4/0.25; res=val[0]*reg4;

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_3
#define STRUCT_Gauss_3
struct Gauss_3 {};
#endif // STRUCT_Gauss_3
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Gauss_3 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=var_inter[0]-0.5; T reg1=var_inter[0]-0.16666666666666666667; T reg2=var_inter[0]-0.25; T reg3=reg2*reg0; reg0=reg1*reg0;
    reg3=reg3/0.027777777777777777774; T reg4=var_inter[1]-0.25; reg0=reg0/0.020833333333333333332; T reg5=var_inter[1]-0.16666666666666666667; reg1=reg2*reg1;
    reg1=reg1/0.083333333333333333329; reg3=reg4*reg3; T reg6=var_inter[1]-0.5; reg0=reg0*reg5; reg1=reg4*reg1;
    T reg7=reg6*reg3; reg0=reg6*reg0; reg7=reg7/0.027777777777777777774; T reg8=var_inter[2]-0.16666666666666666667; reg0=reg0/0.020833333333333333332;
    T reg9=var_inter[2]-0.25; reg1=reg6*reg1; reg6=var_inter[2]-0.5; reg7=reg9*reg7; T reg10=reg0*reg8;
    reg3=reg5*reg3; reg1=reg1/0.027777777777777777774; reg5=reg6*reg7; reg1=reg9*reg1; reg10=reg10*reg6;
    reg3=reg3/0.083333333333333333329; reg10=reg10/0.020833333333333333332; reg5=reg5/0.027777777777777777774; reg1=reg6*reg1; reg3=reg9*reg3;
    reg1=reg1/0.027777777777777777774; reg3=reg6*reg3; reg5=val[1]*reg5; reg10=val[0]*reg10; reg10=reg5-reg10;
    reg1=val[2]*reg1; reg3=reg3/0.027777777777777777774; reg7=reg8*reg7; reg1=reg10+reg1; reg3=val[3]*reg3;
    reg7=reg7/0.083333333333333333329; reg3=reg1+reg3; reg7=val[4]*reg7; res=reg3+reg7;

}
#ifndef STRUCT_Gauss_2
#define STRUCT_Gauss_2
struct Gauss_2 {};
#endif // STRUCT_Gauss_2
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Gauss_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=var_inter[0]-0.13819660112501051517; T reg1=var_inter[0]-0.58541019662496845445; reg0=reg0/0.44721359549995793928; reg1=reg1/0.44721359549995793928; T reg2=var_inter[1]-0.58541019662496845445;
    T reg3=var_inter[1]-0.13819660112501051517; reg0=reg2*reg0; reg2=reg1*reg2; reg2=reg2/0.44721359549995793928; T reg4=var_inter[2]-0.58541019662496845445;
    reg0=reg0/0.44721359549995793928; reg3=reg1*reg3; reg1=reg2*reg4; reg3=reg3/0.44721359549995793928; reg0=reg4*reg0;
    reg1=reg1/0.44721359549995793928; T reg5=var_inter[2]-0.13819660112501051517; reg0=reg0/0.44721359549995793928; reg3=reg4*reg3; reg3=reg3/0.44721359549995793928;
    reg5=reg2*reg5; reg4=val[1]*reg0; reg1=val[0]*reg1; reg1=reg4-reg1; reg4=val[2]*reg3;
    reg5=reg5/0.44721359549995793928; reg4=reg1+reg4; reg5=val[3]*reg5; res=reg4+reg5;

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Bubble
#define STRUCT_Bubble
struct Bubble {};
#endif // STRUCT_Bubble
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Bubble &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=var_inter[0]*reg0; reg1=var_inter[1]*reg1;
    reg1=var_inter[2]*reg1; reg1=256*reg1; T reg2=1-reg1; T reg3=reg0*reg2; T reg4=var_inter[0]*reg2;
    reg3=val[0]*reg3; reg4=val[1]*reg4; T reg5=var_inter[1]*reg2; reg4=reg3+reg4; reg5=val[2]*reg5;
    reg2=var_inter[2]*reg2; reg5=reg4+reg5; reg2=val[3]*reg2; reg2=reg5+reg2; reg1=val[4]*reg1;
    res=reg2+reg1;

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Tetra &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    res[1]=var_inter[0]; res[2]=var_inter[1]; T reg0=1-var_inter[0]; res[3]=var_inter[2]; reg0=reg0-var_inter[1];
    reg0=reg0-var_inter[2]; res[0]=reg0;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Tetra> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Tetra,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=elem.pos(1)[2]-elem.pos(0)[2]; T reg1=elem.pos(2)[2]-elem.pos(0)[2]; T reg2=elem.pos(2)[1]-elem.pos(0)[1]; T reg3=elem.pos(1)[1]-elem.pos(0)[1]; T reg4=elem.pos(3)[2]-elem.pos(0)[2];
    T reg5=elem.pos(3)[1]-elem.pos(0)[1]; T reg6=reg0*reg5; T reg7=reg4*reg2; T reg8=reg1*reg5; T reg9=reg4*reg3;
    T reg10=reg2*reg0; reg8=reg7-reg8; reg7=reg1*reg3; T reg11=elem.pos(2)[0]-elem.pos(0)[0]; T reg12=elem.pos(1)[0]-elem.pos(0)[0];
    reg6=reg9-reg6; reg9=elem.pos(3)[0]-elem.pos(0)[0]; T reg13=reg12*reg8; T reg14=reg6*reg11; reg10=reg7-reg10;
    reg14=reg13-reg14; reg7=reg9*reg10; reg7=reg14+reg7; return reg7;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Tetra,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=elem.pos(3)[1]-elem.pos(0)[1]; T reg1=elem.pos(1)[1]-elem.pos(0)[1]; T reg2=elem.pos(1)[2]-elem.pos(0)[2]; T reg3=elem.pos(2)[1]-elem.pos(0)[1]; T reg4=elem.pos(2)[2]-elem.pos(0)[2];
    T reg5=elem.pos(3)[2]-elem.pos(0)[2]; T reg6=reg0*reg2; T reg7=reg0*reg4; T reg8=reg1*reg5; T reg9=reg3*reg5;
    T reg10=elem.pos(1)[0]-elem.pos(0)[0]; reg7=reg9-reg7; reg9=elem.pos(2)[0]-elem.pos(0)[0]; reg6=reg8-reg6; reg8=reg1*reg4;
    T reg11=reg2*reg3; T reg12=elem.pos(3)[0]-elem.pos(0)[0]; T reg13=reg10*reg7; T reg14=reg9*reg6; reg11=reg8-reg11;
    reg14=reg13-reg14; reg8=reg12*reg11; reg8=reg14+reg8; reg13=reg5*reg8; reg14=reg0*reg8;
    T reg15=reg12*reg8; T reg16=2*reg13; T reg17=elem.pos(0)[0]*reg8; T reg18=reg10*reg8; T reg19=2*reg14;
    T reg20=reg3*reg8; T reg21=reg2*reg8; T reg22=reg1*reg8; T reg23=reg4*reg8; T reg24=2*reg15;
    T reg25=reg9*reg8; T reg26=reg8*elem.pos(0)[1]; T reg27=elem.pos(0)[2]*reg8; T reg28=reg25+reg18; T reg29=reg20+reg22;
    T reg30=reg23-reg27; T reg31=reg16/2; T reg32=reg19/2; T reg33=reg20-reg26; T reg34=reg23+reg21;
    T reg35=reg24/2; T reg36=reg25-reg17; reg33=reg33-reg32; T reg37=reg35-reg28; reg30=reg30-reg31;
    T reg38=reg31-reg34; reg36=reg36-reg35; T reg39=reg32-reg29; T reg40=2*reg37; T reg41=reg22-reg26;
    T reg42=2*reg33; T reg43=2*reg18; T reg44=2*reg22; T reg45=reg21-reg27; T reg46=2*reg39;
    T reg47=2*reg30; T reg48=2*reg36; T reg49=reg18-reg17; T reg50=2*reg21; T reg51=2*reg38;
    reg45=reg45-reg31; T reg52=reg14/2; T reg53=2*reg20; T reg54=reg31-reg50; T reg55=reg51-reg47;
    T reg56=2*reg23; T reg57=reg13/2; T reg58=reg46-reg42; reg41=reg41-reg32; T reg59=reg32-reg44;
    T reg60=reg15/2; T reg61=reg35-reg43; T reg62=reg40-reg48; reg49=reg49-reg35; T reg63=2*reg25;
    T reg64=4*reg37; reg52=reg26+reg52; reg26=reg54-reg45; T reg65=reg35-reg63; T reg66=reg32-reg53;
    reg58=reg46+reg58; reg48=reg37-reg48; reg57=reg27+reg57; reg62=reg40+reg62; reg27=reg61-reg49;
    reg42=reg39-reg42; T reg67=reg59-reg41; T reg68=reg31-reg56; T reg69=4*reg39; T reg70=4*reg38;
    reg55=reg51+reg55; reg47=reg38-reg47; reg60=reg17+reg60; reg17=reg41-reg52; T reg71=reg51+reg70;
    reg27=reg27-reg49; T reg72=reg45-reg57; reg47=reg47/2; reg42=reg42/2; reg62=reg62/2;
    T reg73=1.5*reg68; T reg74=2*reg54; T reg75=1.5*reg66; reg58=reg58/2; T reg76=3*reg65;
    T reg77=1.5*reg65; T reg78=3*reg66; T reg79=reg46+reg69; reg48=reg48/2; reg49=reg49-reg60;
    T reg80=3*reg68; reg41=reg67-reg41; reg55=reg55/2; reg67=2*reg61; T reg81=reg40+reg64;
    T reg82=2*reg59; reg45=reg26-reg45; reg36=reg36/2; reg26=reg79/2; reg58=reg41-reg58;
    reg41=reg78/3; T reg83=reg59+reg82; reg47=reg72+reg47; reg30=reg30/2; reg68=0.5*reg68;
    reg72=reg71/2; T reg84=reg54+reg74; T reg85=reg80/3; T reg86=2*reg8; reg55=reg45-reg55;
    reg45=reg81/2; T reg87=reg61+reg67; reg65=0.5*reg65; T reg88=reg76/3; reg66=0.5*reg66;
    reg73=reg73/3; reg62=reg27-reg62; reg33=reg33/2; reg42=reg17+reg42; reg75=reg75/3;
    reg48=reg49+reg48; reg77=reg77/3; reg17=reg65/3; reg36=reg60+reg36; reg30=reg57+reg30;
    reg27=reg68/3; reg49=reg45-reg87; reg57=reg72-reg84; reg55=reg55+reg85; reg60=reg86/2;
    reg62=reg62+reg88; reg73=reg47-reg73; reg33=reg52+reg33; reg47=reg66/3; reg75=reg42-reg75;
    reg77=reg48-reg77; reg58=reg58+reg41; reg42=reg26-reg83; reg55=0.5*reg55; reg27=reg30+reg27;
    reg57=reg57-reg85; reg73=reg73/2; reg62=0.5*reg62; reg30=reg86-reg60; reg49=reg49-reg88;
    reg47=reg33+reg47; reg58=0.5*reg58; reg42=reg42-reg41; reg33=reg60-reg86; reg75=reg75/2;
    reg48=reg8/2; reg77=reg77/2; reg17=reg36+reg17; reg48=reg8-reg48; reg49=0.16666666666666666667*reg49;
    reg62=reg62/3; reg30=0.5*reg30; reg33=reg33/2; reg77=reg17+reg77; reg57=0.16666666666666666667*reg57;
    reg73=reg27+reg73; reg55=reg55/3; reg42=0.16666666666666666667*reg42; reg75=reg47+reg75; reg58=reg58/3;
    reg30=reg30/3; reg33=reg48+reg33; reg55=reg73+reg55; reg58=reg75+reg58; reg42=reg42/4;
    reg49=reg49/4; reg62=reg77+reg62; reg57=reg57/4; reg57=reg55+reg57; reg49=reg62+reg49;
    reg30=reg33+reg30; reg42=reg58+reg42; res[0]=reg49/reg30; res[1]=reg42/reg30; res[2]=reg57/reg30;

    return res;
}
}
#endif // LMT_TETRA
