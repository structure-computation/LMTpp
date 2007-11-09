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
        0.0416666666667,0.138196601125,0.585410196625,0.138196601125,
        0.0416666666667,0.585410196625,0.138196601125,0.138196601125,
        0.0416666666667,0.138196601125,0.138196601125,0.585410196625,
        0.0,
        -0.133333333333,0.25,0.25,0.25,
        0.075,0.166666666667,0.166666666667,0.166666666667,
        0.075,0.166666666667,0.5,0.166666666667,
        0.075,0.5,0.166666666667,0.166666666667,
        0.075,0.166666666667,0.166666666667,0.5,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
        0.0,
        0.0197530864198,0.25,0.25,0.25,
        0.011511367871,0.31979362783,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.0406191165111,0.31979362783,
        0.011511367871,0.0406191165111,0.31979362783,0.31979362783,
        0.011511367871,0.31979362783,0.31979362783,0.0406191165111,
        0.0119895139632,0.0919710780527,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.724086765842,0.0919710780527,
        0.0119895139632,0.724086765842,0.0919710780527,0.0919710780527,
        0.0119895139632,0.0919710780527,0.0919710780527,0.724086765842,
        0.00881834215168,0.0563508326896,0.0563508326896,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.0563508326896,
        0.00881834215168,0.44364916731,0.44364916731,0.0563508326896,
        0.00881834215168,0.0563508326896,0.44364916731,0.44364916731,
        0.00881834215168,0.44364916731,0.0563508326896,0.44364916731,
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
    T reg0=pos_nodes[2][1]-pos_nodes[0][1]; T reg1=pos_nodes[3][0]-pos_nodes[0][0]; T reg2=pos_nodes[2][0]-pos_nodes[0][0]; T reg3=pos_nodes[3][1]-pos_nodes[0][1]; T reg4=pos_nodes[2][2]-pos_nodes[0][2];
    T reg5=pos_nodes[3][2]-pos_nodes[0][2]; T reg6=reg3*reg4; T reg7=reg0*reg5; T reg8=reg2*reg5; T reg9=reg1*reg4;
    T reg10=reg2*reg3; reg6=reg7-reg6; reg9=reg8-reg9; T reg11=reg1*reg0; T reg12=pos_nodes[1][1]-pos_nodes[0][1];
    T reg13=pos_nodes[1][0]-pos_nodes[0][0]; reg11=reg10-reg11; T reg14=reg12*reg9; T reg15=reg13*reg6; T reg16=pos_nodes[1][2]-pos_nodes[0][2];
    T reg17=reg2*reg16; T reg18=reg0*reg16; T reg19=reg1*reg16; T reg20=reg13*reg5; T reg21=reg12*reg4;
    T reg22=reg3*reg16; T reg23=reg12*reg5; reg15=reg14-reg15; reg14=reg13*reg4; T reg24=reg16*reg11;
    reg18=reg21-reg18; reg17=reg14-reg17; reg22=reg23-reg22; reg24=reg15-reg24; reg19=reg20-reg19;
    reg15=reg13*reg3; T reg25=reg1*reg12; T reg26=reg13*reg0; T reg27=reg2*reg12; reg17=reg17/reg24;
    reg27=reg26-reg27; reg25=reg15-reg25; reg18=reg18/reg24; reg22=reg22/reg24; reg6=reg6/reg24;
    reg9=reg9/reg24; reg19=reg19/reg24; T reg28=pos[1]-pos_nodes[0][1]; T reg29=pos[0]-pos_nodes[0][0]; reg18=reg29*reg18;
    reg19=reg19*reg28; reg22=reg29*reg22; reg17=reg28*reg17; reg9=reg9*reg28; reg6=reg29*reg6;
    reg27=reg27/reg24; reg25=reg25/reg24; T reg30=pos[2]-pos_nodes[0][2]; reg24=reg11/reg24; reg18=reg17-reg18;
    reg27=reg30*reg27; reg19=reg22-reg19; reg25=reg30*reg25; reg6=reg9-reg6; reg24=reg30*reg24;
    var_inter[1]=reg25+reg19; var_inter[0]=reg6-reg24; var_inter[2]=reg18-reg27;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=pos_nodes[0][1]*reg0; T reg2=pos_nodes[1][1]*var_inter[0];
    T reg3=pos_nodes[1][0]*var_inter[0]; T reg4=pos_nodes[0][0]*reg0; T reg5=pos_nodes[3][1]-pos_nodes[0][1]; T reg6=pos_nodes[1][2]*var_inter[0]; T reg7=pos_nodes[0][2]*reg0;
    T reg8=pos_nodes[3][2]-pos_nodes[0][2]; T reg9=pos_nodes[2][2]-pos_nodes[0][2]; T reg10=pos_nodes[2][0]-pos_nodes[0][0]; T reg11=pos_nodes[3][0]-pos_nodes[0][0]; T reg12=pos_nodes[2][1]-pos_nodes[0][1];
    reg3=reg4+reg3; reg4=pos_nodes[2][0]*var_inter[1]; reg2=reg1+reg2; reg1=pos_nodes[2][1]*var_inter[1]; T reg13=reg12*reg8;
    T reg14=reg5*reg9; reg1=reg2+reg1; reg2=pos_nodes[3][1]*var_inter[2]; T reg15=reg10*reg8; T reg16=reg11*reg9;
    reg6=reg7+reg6; reg7=pos_nodes[2][2]*var_inter[1]; T reg17=pos_nodes[3][0]*var_inter[2]; reg4=reg3+reg4; reg14=reg13-reg14;
    reg3=reg10*reg5; reg16=reg15-reg16; T reg18=reg11*reg12; T reg19=pos_nodes[3][2]*var_inter[2]; reg7=reg6+reg7;
    reg6=pos_nodes[1][1]-pos_nodes[0][1]; reg17=reg4+reg17; reg4=pos_nodes[1][0]-pos_nodes[0][0]; reg2=reg1+reg2; reg17=pos[0]-reg17;
    reg1=reg4*reg14; reg18=reg3-reg18; reg19=reg7+reg19; reg7=pos_nodes[1][2]-pos_nodes[0][2]; T reg20=var_inter[0]*reg4;
    reg2=pos[1]-reg2; T reg21=reg6*reg16; T reg22=var_inter[0]*reg6; T reg23=reg10*reg7; reg1=reg21-reg1;
    reg21=reg7*reg18; T reg24=reg12*reg7; T reg25=reg6*reg9; T reg26=reg5*reg7; T reg27=reg6*reg8;
    T reg28=reg4*reg8; T reg29=var_inter[0]*reg7; T reg30=reg11*reg7; reg22=reg2+reg22; reg2=var_inter[1]*reg12;
    T reg31=reg4*reg9; reg19=pos[2]-reg19; reg20=reg17+reg20; reg17=var_inter[1]*reg10; reg24=reg25-reg24;
    reg23=reg31-reg23; reg26=reg27-reg26; reg30=reg28-reg30; reg21=reg1-reg21; reg1=reg4*reg5;
    T reg32=var_inter[2]*reg11; T reg33=var_inter[2]*reg5; reg20=reg17+reg20; reg17=reg11*reg6; T reg34=reg4*reg12;
    reg22=reg2+reg22; reg2=reg10*reg6; reg29=reg19+reg29; reg19=var_inter[1]*reg9; reg23=reg23/reg21;
    reg17=reg1-reg17; reg2=reg34-reg2; reg22=reg33+reg22; reg29=reg19+reg29; reg19=var_inter[2]*reg8;
    reg20=reg32+reg20; reg14=reg14/reg21; reg30=reg30/reg21; reg26=reg26/reg21; reg16=reg16/reg21;
    reg24=reg24/reg21; reg18=reg18/reg21; reg29=reg19+reg29; reg17=reg17/reg21; reg21=reg2/reg21;
    reg14=reg20*reg14; reg16=reg16*reg22; reg23=reg22*reg23; reg26=reg20*reg26; reg30=reg30*reg22;
    reg24=reg20*reg24; reg24=reg23-reg24; reg21=reg29*reg21; reg30=reg26-reg30; reg17=reg29*reg17;
    reg14=reg16-reg14; reg18=reg29*reg18; var_inter[1]+=reg17+reg30; var_inter[0]+=reg14-reg18; var_inter[2]+=reg24-reg21;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; reg0=reg0-var_inter[2]; T reg1=val[1]*var_inter[0]; T reg2=val[0]*reg0;
    reg1=reg2+reg1; reg2=val[2]*var_inter[1]; reg2=reg1+reg2; reg1=val[3]*var_inter[2]; res=reg2+reg1;

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Tetra &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    reg1=var_inter[2]*reg1; reg1=256*reg1; T reg2=1-reg1; T reg3=reg0*reg2; T reg4=var_inter[0]*reg2;
    reg4=val[1]*reg4; T reg5=var_inter[1]*reg2; reg3=val[0]*reg3; reg4=reg3+reg4; reg5=val[2]*reg5;
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
