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
    T reg0=nodes[1]->pos[2]-nodes[0]->pos[2]; T reg1=nodes[1]->pos[1]-nodes[0]->pos[1]; T reg2=nodes[3]->pos[1]-nodes[0]->pos[1]; T reg3=nodes[2]->pos[2]-nodes[0]->pos[2]; T reg4=nodes[3]->pos[2]-nodes[0]->pos[2];
    T reg5=nodes[2]->pos[1]-nodes[0]->pos[1]; T reg6=reg2*reg0; T reg7=reg4*reg1; reg2=reg3*reg2; reg4=reg5*reg4;
    reg0=reg5*reg0; reg1=reg3*reg1; reg6=reg7-reg6; reg3=nodes[1]->pos[0]-nodes[0]->pos[0]; reg5=nodes[2]->pos[0]-nodes[0]->pos[0];
    reg2=reg4-reg2; reg6=reg5*reg6; reg4=nodes[3]->pos[0]-nodes[0]->pos[0]; reg2=reg3*reg2; reg0=reg1-reg0;
    reg6=reg2-reg6; reg0=reg4*reg0; T det_jac=reg6+reg0;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1],nodes[3]};
        for(unsigned i=0;i<4;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Tetra &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=pos_nodes[3][2]-pos_nodes[0][2]; T reg1=pos_nodes[2][2]-pos_nodes[0][2]; T reg2=pos_nodes[2][0]-pos_nodes[0][0]; T reg3=pos_nodes[3][0]-pos_nodes[0][0]; T reg4=pos_nodes[2][1]-pos_nodes[0][1];
    T reg5=pos_nodes[3][1]-pos_nodes[0][1]; T reg6=reg5*reg1; T reg7=reg4*reg0; T reg8=reg2*reg0; T reg9=reg3*reg1;
    T reg10=pos_nodes[1][0]-pos_nodes[0][0]; reg9=reg8-reg9; T reg11=pos_nodes[1][1]-pos_nodes[0][1]; T reg12=reg2*reg5; reg6=reg7-reg6;
    T reg13=reg3*reg4; T reg14=reg11*reg9; T reg15=reg10*reg6; reg13=reg12-reg13; T reg16=pos_nodes[1][2]-pos_nodes[0][2];
    T reg17=reg10*reg1; T reg18=reg2*reg16; T reg19=reg3*reg16; T reg20=reg4*reg16; reg15=reg14-reg15;
    reg14=reg16*reg13; T reg21=reg10*reg0; T reg22=reg11*reg1; T reg23=reg11*reg0; T reg24=reg5*reg16;
    reg19=reg21-reg19; reg20=reg22-reg20; reg18=reg17-reg18; reg24=reg23-reg24; reg14=reg15-reg14;
    reg15=reg5*reg10; T reg25=reg3*reg11; T reg26=reg4*reg10; T reg27=reg2*reg11; reg18=reg18/reg14;
    reg27=reg26-reg27; reg25=reg15-reg25; reg19=reg19/reg14; reg20=reg20/reg14; reg24=reg24/reg14;
    reg6=reg6/reg14; reg9=reg9/reg14; T reg28=pos[0]-pos_nodes[0][0]; T reg29=pos[1]-pos_nodes[0][1]; reg24=reg28*reg24;
    reg9=reg9*reg29; reg19=reg29*reg19; reg20=reg28*reg20; reg18=reg29*reg18; reg6=reg28*reg6;
    reg27=reg27/reg14; reg25=reg25/reg14; reg14=reg13/reg14; reg13=pos[2]-pos_nodes[0][2]; reg14=reg13*reg14;
    reg6=reg9-reg6; reg25=reg13*reg25; reg19=reg24-reg19; reg27=reg13*reg27; reg20=reg18-reg20;
    var_inter[0]=reg6-reg14; var_inter[1]=reg25+reg19; var_inter[2]=reg20-reg27;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=pos_nodes[3][2]-pos_nodes[0][2]; T reg2=pos_nodes[2][2]-pos_nodes[0][2]; T reg3=pos_nodes[3][1]-pos_nodes[0][1];
    T reg4=pos_nodes[2][1]-pos_nodes[0][1]; T reg5=pos_nodes[2][0]-pos_nodes[0][0]; T reg6=pos_nodes[3][0]-pos_nodes[0][0]; T reg7=reg3*reg2; T reg8=reg4*reg1;
    T reg9=reg5*reg1; T reg10=reg6*reg2; reg0=reg0-var_inter[2]; reg7=reg8-reg7; T reg11=reg5*reg3;
    T reg12=pos_nodes[1][1]*var_inter[0]; T reg13=pos_nodes[0][1]*reg0; T reg14=pos_nodes[1][0]-pos_nodes[0][0]; T reg15=pos_nodes[1][1]-pos_nodes[0][1]; reg10=reg9-reg10;
    T reg16=reg6*reg4; T reg17=pos_nodes[1][0]*var_inter[0]; T reg18=pos_nodes[0][0]*reg0; T reg19=reg15*reg10; reg16=reg11-reg16;
    T reg20=reg14*reg7; T reg21=pos_nodes[1][2]*var_inter[0]; T reg22=pos_nodes[0][2]*reg0; T reg23=pos_nodes[1][2]-pos_nodes[0][2]; reg17=reg18+reg17;
    reg18=pos_nodes[2][0]*var_inter[1]; reg12=reg13+reg12; reg13=pos_nodes[2][1]*var_inter[1]; T reg24=reg15*reg1; T reg25=reg23*reg16;
    reg20=reg19-reg20; reg18=reg17+reg18; reg17=var_inter[2]*pos_nodes[3][0]; reg19=reg14*reg2; reg13=reg12+reg13;
    reg12=reg3*reg23; T reg26=var_inter[2]*pos_nodes[3][1]; T reg27=reg15*reg2; T reg28=reg4*reg23; T reg29=pos_nodes[2][2]*var_inter[1];
    reg21=reg22+reg21; reg22=reg6*reg23; T reg30=reg5*reg23; T reg31=reg14*reg1; reg12=reg24-reg12;
    reg22=reg31-reg22; reg30=reg19-reg30; reg28=reg27-reg28; reg25=reg20-reg25; reg20=reg14*reg3;
    T reg32=reg6*reg15; T reg33=reg14*reg4; T reg34=var_inter[2]*pos_nodes[3][2]; reg29=reg21+reg29; reg21=reg5*reg15;
    reg26=reg13+reg26; reg17=reg18+reg17; reg32=reg20-reg32; reg30=reg30/reg25; reg21=reg33-reg21;
    reg17=pos[0]-reg17; reg26=pos[1]-reg26; reg34=reg29+reg34; reg7=reg7/reg25; reg12=reg12/reg25;
    reg28=reg28/reg25; reg10=reg10/reg25; reg22=reg22/reg25; reg34=pos[2]-reg34; reg16=reg16/reg25;
    reg32=reg32/reg25; reg25=reg21/reg25; reg7=reg17*reg7; reg10=reg26*reg10; reg30=reg26*reg30;
    reg12=reg17*reg12; reg22=reg26*reg22; reg28=reg17*reg28; reg28=reg30-reg28; reg25=reg34*reg25;
    reg22=reg12-reg22; reg32=reg34*reg32; reg7=reg10-reg7; reg16=reg34*reg16; var_inter[1]+=reg32+reg22;
    var_inter[0]+=reg7-reg16; var_inter[2]+=reg28-reg25;

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
    reg2=reg1+reg2; reg1=val[2]*var_inter[1]; reg1=reg2+reg1; reg2=val[3]*var_inter[2]; res=reg1+reg2;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=var_inter[0]-0.16666666666666665741; T reg1=var_inter[0]-0.5; T reg2=var_inter[0]-0.25; T reg3=reg1*reg2; reg1=reg0*reg1;
    T reg4=var_inter[1]-0.25; reg3=reg3/0.027777777777777783175; reg2=reg0*reg2; reg0=var_inter[1]-0.16666666666666665741; reg1=reg1/0.020833333333333335646;
    T reg5=var_inter[1]-0.5; reg1=reg1*reg0; reg2=reg2/0.083333333333333342585; reg3=reg3*reg4; reg2=reg4*reg2;
    reg4=reg5*reg3; reg1=reg5*reg1; reg4=reg4/0.027777777777777783175; T reg6=var_inter[2]-0.25; T reg7=var_inter[2]-0.16666666666666665741;
    reg1=reg1/0.020833333333333335646; reg2=reg5*reg2; reg4=reg4*reg6; reg2=reg2/0.027777777777777783175; reg5=var_inter[2]-0.5;
    T reg8=reg1*reg7; reg3=reg0*reg3; reg8=reg8*reg5; reg0=reg5*reg4; reg2=reg6*reg2;
    reg3=reg3/0.083333333333333342585; reg2=reg5*reg2; reg8=reg8/0.020833333333333335646; reg0=reg0/0.027777777777777783175; reg3=reg6*reg3;
    reg2=reg2/0.027777777777777783175; reg0=val[1]*reg0; reg8=val[0]*reg8; reg3=reg5*reg3; reg3=reg3/0.027777777777777783175;
    reg4=reg7*reg4; reg2=val[2]*reg2; reg8=reg0-reg8; reg4=reg4/0.083333333333333342585; reg3=val[3]*reg3;
    reg2=reg8+reg2; reg3=reg2+reg3; reg4=val[4]*reg4; res=reg3+reg4;

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
    reg1=var_inter[2]*reg1; reg1=256*reg1; T reg2=1-reg1; T reg3=reg2*reg0; T reg4=var_inter[0]*reg2;
    T reg5=var_inter[1]*reg2; reg4=val[1]*reg4; reg3=val[0]*reg3; reg4=reg3+reg4; reg5=val[2]*reg5;
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

}
#endif // LMT_TETRA
