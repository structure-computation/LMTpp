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
    T reg5=pos_nodes[3][2]-pos_nodes[0][2]; T reg6=reg3*reg4; T reg7=reg0*reg5; T reg8=reg2*reg5; T reg9=reg1*reg4;
    reg6=reg8-reg6; T reg10=reg0*reg3; T reg11=pos_nodes[1][0]-pos_nodes[0][0]; T reg12=pos_nodes[1][1]-pos_nodes[0][1]; reg9=reg7-reg9;
    T reg13=reg1*reg2; reg13=reg10-reg13; T reg14=reg6*reg11; T reg15=reg9*reg12; T reg16=pos_nodes[1][2]-pos_nodes[0][2];
    T reg17=reg12*reg5; T reg18=reg3*reg16; T reg19=reg12*reg4; T reg20=reg13*reg16; T reg21=reg2*reg16;
    T reg22=reg0*reg16; T reg23=reg11*reg4; reg14=reg15-reg14; reg15=reg1*reg16; T reg24=reg11*reg5;
    T reg25=reg0*reg12; T reg26=reg11*reg2; reg20=reg14-reg20; reg18=reg17-reg18; reg14=reg1*reg12;
    T reg27=reg11*reg3; reg21=reg19-reg21; reg15=reg24-reg15; reg22=reg23-reg22; reg14=reg27-reg14;
    reg22=reg22/reg20; reg15=reg15/reg20; reg9=reg9/reg20; reg21=reg21/reg20; reg18=reg18/reg20;
    reg6=reg6/reg20; T reg28=pos[1]-pos_nodes[0][1]; T reg29=pos[0]-pos_nodes[0][0]; reg25=reg26-reg25; reg6=reg29*reg6;
    T reg30=pos[2]-pos_nodes[0][2]; reg9=reg28*reg9; reg18=reg29*reg18; reg15=reg28*reg15; reg21=reg29*reg21;
    reg13=reg13/reg20; reg22=reg28*reg22; reg25=reg25/reg20; reg20=reg14/reg20; reg25=reg30*reg25;
    reg15=reg18-reg15; reg20=reg30*reg20; reg21=reg22-reg21; reg6=reg9-reg6; reg13=reg30*reg13;
    var_inter[1]=reg20+reg15; var_inter[0]=reg6-reg13; var_inter[2]=reg21-reg25;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=pos_nodes[3][2]-pos_nodes[0][2]; T reg2=pos_nodes[2][2]-pos_nodes[0][2]; T reg3=pos_nodes[2][1]-pos_nodes[0][1]; T reg4=pos_nodes[3][1]-pos_nodes[0][1];
    T reg5=pos_nodes[2][0]-pos_nodes[0][0]; T reg6=pos_nodes[3][0]-pos_nodes[0][0]; reg0=reg0-var_inter[1]; T reg7=reg3*reg1; T reg8=reg6*reg2;
    T reg9=reg4*reg2; T reg10=reg5*reg1; reg0=reg0-var_inter[2]; reg8=reg10-reg8; T reg11=reg0*pos_nodes[0][1];
    T reg12=var_inter[0]*pos_nodes[1][1]; T reg13=pos_nodes[1][1]-pos_nodes[0][1]; T reg14=var_inter[0]*pos_nodes[1][0]; T reg15=reg5*reg4; reg9=reg7-reg9;
    T reg16=pos_nodes[1][0]-pos_nodes[0][0]; T reg17=reg0*pos_nodes[0][0]; T reg18=reg6*reg3; T reg19=reg16*reg9; T reg20=reg13*reg8;
    reg18=reg15-reg18; T reg21=reg0*pos_nodes[0][2]; T reg22=var_inter[0]*pos_nodes[1][2]; T reg23=pos_nodes[1][2]-pos_nodes[0][2]; T reg24=pos_nodes[2][0]*var_inter[1];
    reg11=reg12+reg11; reg12=pos_nodes[2][1]*var_inter[1]; reg17=reg14+reg17; reg14=reg13*reg1; reg19=reg20-reg19;
    reg20=reg23*reg18; T reg25=reg16*reg1; T reg26=reg6*reg23; T reg27=reg16*reg2; reg17=reg24+reg17;
    reg24=pos_nodes[3][0]*var_inter[2]; reg11=reg12+reg11; reg12=pos_nodes[3][1]*var_inter[2]; T reg28=reg5*reg23; T reg29=pos_nodes[2][2]*var_inter[1];
    reg21=reg22+reg21; reg22=reg3*reg23; T reg30=reg13*reg2; T reg31=reg4*reg23; reg22=reg30-reg22;
    reg28=reg27-reg28; T reg32=reg16*reg4; reg20=reg19-reg20; reg31=reg14-reg31; reg19=reg6*reg13;
    T reg33=reg16*reg3; T reg34=reg5*reg13; reg26=reg25-reg26; T reg35=pos_nodes[3][2]*var_inter[2]; reg24=reg17+reg24;
    reg21=reg29+reg21; reg12=reg11+reg12; reg8=reg8/reg20; reg19=reg32-reg19; reg26=reg26/reg20;
    reg28=reg28/reg20; reg24=pos[0]-reg24; reg34=reg33-reg34; reg12=pos[1]-reg12; reg22=reg22/reg20;
    reg31=reg31/reg20; reg35=reg21+reg35; reg9=reg9/reg20; reg8=reg8*reg12; reg31=reg24*reg31;
    reg26=reg26*reg12; reg22=reg24*reg22; reg28=reg12*reg28; reg9=reg24*reg9; reg34=reg34/reg20;
    reg19=reg19/reg20; reg20=reg18/reg20; reg35=pos[2]-reg35; reg20=reg35*reg20; reg9=reg8-reg9;
    reg19=reg35*reg19; reg26=reg31-reg26; reg34=reg35*reg34; reg22=reg28-reg22; var_inter[0]+=reg9-reg20;
    var_inter[1]+=reg19+reg26; var_inter[2]+=reg22-reg34;

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
    T reg0=elem.pos(2)[1]-elem.pos(0)[1]; T reg1=elem.pos(2)[2]-elem.pos(0)[2]; T reg2=elem.pos(3)[2]-elem.pos(0)[2]; T reg3=elem.pos(1)[1]-elem.pos(0)[1]; T reg4=elem.pos(1)[2]-elem.pos(0)[2];
    T reg5=elem.pos(3)[1]-elem.pos(0)[1]; T reg6=reg5*reg4; T reg7=reg5*reg1; T reg8=reg0*reg2; T reg9=reg3*reg2;
    T reg10=elem.pos(2)[0]-elem.pos(0)[0]; reg6=reg9-reg6; reg7=reg8-reg7; reg8=reg0*reg4; reg9=reg3*reg1;
    T reg11=elem.pos(1)[0]-elem.pos(0)[0]; reg8=reg9-reg8; reg9=reg11*reg7; T reg12=reg10*reg6; T reg13=elem.pos(3)[0]-elem.pos(0)[0];
    T reg14=reg13*reg8; reg12=reg9-reg12; reg12=reg14+reg12; return reg12;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Tetra,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=elem.pos(2)[1]-elem.pos(0)[1]; T reg1=elem.pos(2)[2]-elem.pos(0)[2]; T reg2=elem.pos(1)[2]-elem.pos(0)[2]; T reg3=elem.pos(1)[1]-elem.pos(0)[1]; T reg4=elem.pos(3)[1]-elem.pos(0)[1];
    T reg5=elem.pos(3)[2]-elem.pos(0)[2]; T reg6=reg0*reg5; T reg7=reg3*reg5; T reg8=reg1*reg4; T reg9=reg2*reg4;
    T reg10=0.25*elem.pos(1)[1]; T reg11=0.25*elem.pos(0)[1]; T reg12=0.25*elem.pos(1)[2]; T reg13=0.25*elem.pos(0)[2]; T reg14=0.25*elem.pos(1)[0];
    T reg15=0.25*elem.pos(0)[0]; T reg16=reg2*reg0; T reg17=reg3*reg1; T reg18=elem.pos(2)[0]-elem.pos(0)[0]; T reg19=elem.pos(1)[0]-elem.pos(0)[0];
    reg8=reg6-reg8; reg9=reg7-reg9; reg6=0.25*elem.pos(2)[2]; reg16=reg17-reg16; reg13=reg12+reg13;
    reg7=reg18*reg9; reg12=reg19*reg8; reg14=reg15+reg14; reg15=0.25*elem.pos(2)[0]; reg17=0.25*elem.pos(2)[1];
    reg11=reg10+reg11; reg10=elem.pos(3)[0]-elem.pos(0)[0]; reg6=reg13+reg6; reg13=0.25*elem.pos(3)[2]; T reg20=0.25*elem.pos(3)[1];
    reg17=reg11+reg17; reg11=0.25*elem.pos(3)[0]; reg15=reg14+reg15; reg14=reg10*reg16; reg7=reg12-reg7;
    reg11=reg15+reg11; reg20=reg17+reg20; reg13=reg6+reg13; reg14=reg7+reg14; reg13=reg14*reg13;
    reg11=reg14*reg11; reg20=reg14*reg20; reg13=0.16666666666666665741*reg13; reg11=0.16666666666666665741*reg11; reg20=0.16666666666666665741*reg20;
    reg6=0.16666666666666665741*reg14; res[2]=reg13/reg6; res[0]=reg11/reg6; res[1]=reg20/reg6;

    return res;
}
}
#endif // LMT_TETRA
