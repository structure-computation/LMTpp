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
    T reg0=nodes[2]->pos[2]-nodes[0]->pos[2]; T reg1=nodes[3]->pos[1]-nodes[0]->pos[1]; T reg2=nodes[3]->pos[2]-nodes[0]->pos[2]; T reg3=nodes[2]->pos[1]-nodes[0]->pos[1]; T reg4=nodes[1]->pos[1]-nodes[0]->pos[1];
    T reg5=nodes[1]->pos[2]-nodes[0]->pos[2]; T reg6=reg0*reg1; T reg7=reg2*reg4; reg1=reg1*reg5; reg2=reg3*reg2;
    reg5=reg3*reg5; reg4=reg0*reg4; reg1=reg7-reg1; reg0=nodes[2]->pos[0]-nodes[0]->pos[0]; reg6=reg2-reg6;
    reg2=nodes[1]->pos[0]-nodes[0]->pos[0]; reg6=reg2*reg6; reg1=reg0*reg1; reg0=nodes[3]->pos[0]-nodes[0]->pos[0]; reg5=reg4-reg5;
    reg1=reg6-reg1; reg5=reg0*reg5; T det_jac=reg1+reg5;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1],nodes[3]};
        for(unsigned i=0;i<4;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Tetra &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=pos_nodes[3][2]-pos_nodes[0][2]; T reg1=pos_nodes[2][2]-pos_nodes[0][2]; T reg2=pos_nodes[3][1]-pos_nodes[0][1]; T reg3=pos_nodes[2][1]-pos_nodes[0][1]; T reg4=pos_nodes[3][0]-pos_nodes[0][0];
    T reg5=pos_nodes[2][0]-pos_nodes[0][0]; T reg6=reg4*reg1; T reg7=reg5*reg0; T reg8=reg3*reg0; T reg9=reg2*reg1;
    T reg10=reg5*reg2; T reg11=pos_nodes[1][1]-pos_nodes[0][1]; T reg12=pos_nodes[1][0]-pos_nodes[0][0]; T reg13=reg4*reg3; reg6=reg7-reg6;
    reg9=reg8-reg9; T reg14=reg9*reg12; T reg15=reg6*reg11; reg13=reg10-reg13; T reg16=pos_nodes[1][2]-pos_nodes[0][2];
    T reg17=reg5*reg16; T reg18=reg12*reg1; T reg19=reg13*reg16; T reg20=reg4*reg16; T reg21=reg12*reg0;
    reg14=reg15-reg14; reg15=reg3*reg16; T reg22=reg11*reg0; T reg23=reg11*reg1; T reg24=reg2*reg16;
    T reg25=reg5*reg11; T reg26=reg12*reg3; reg19=reg14-reg19; reg24=reg22-reg24; reg15=reg23-reg15;
    reg20=reg21-reg20; reg17=reg18-reg17; reg14=reg4*reg11; T reg27=reg12*reg2; reg14=reg27-reg14;
    reg24=reg24/reg19; T reg28=pos[0]-pos_nodes[0][0]; reg15=reg15/reg19; T reg29=pos[1]-pos_nodes[0][1]; reg6=reg6/reg19;
    reg20=reg20/reg19; reg9=reg9/reg19; reg17=reg17/reg19; reg25=reg26-reg25; reg9=reg9*reg28;
    reg6=reg29*reg6; reg24=reg24*reg28; reg14=reg14/reg19; T reg30=pos[2]-pos_nodes[0][2]; reg20=reg29*reg20;
    reg13=reg13/reg19; reg19=reg25/reg19; reg15=reg15*reg28; reg17=reg29*reg17; reg20=reg24-reg20;
    reg14=reg30*reg14; reg9=reg6-reg9; reg15=reg17-reg15; reg13=reg30*reg13; reg19=reg30*reg19;
    var_inter[1]=reg14+reg20; var_inter[0]=reg9-reg13; var_inter[2]=reg15-reg19;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Tetra &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; T reg1=pos_nodes[2][2]-pos_nodes[0][2]; T reg2=pos_nodes[3][1]-pos_nodes[0][1]; T reg3=pos_nodes[2][1]-pos_nodes[0][1]; T reg4=pos_nodes[3][0]-pos_nodes[0][0];
    T reg5=pos_nodes[2][0]-pos_nodes[0][0]; T reg6=pos_nodes[3][2]-pos_nodes[0][2]; reg0=reg0-var_inter[1]; T reg7=reg5*reg6; T reg8=reg4*reg1;
    T reg9=reg3*reg6; reg0=reg0-var_inter[2]; T reg10=reg2*reg1; T reg11=reg4*reg3; reg8=reg7-reg8;
    T reg12=pos_nodes[0][0]*reg0; T reg13=pos_nodes[1][0]*var_inter[0]; T reg14=pos_nodes[1][0]-pos_nodes[0][0]; reg10=reg9-reg10; T reg15=reg5*reg2;
    T reg16=pos_nodes[1][1]-pos_nodes[0][1]; T reg17=pos_nodes[0][1]*reg0; T reg18=pos_nodes[1][1]*var_inter[0]; T reg19=pos_nodes[1][2]-pos_nodes[0][2]; reg11=reg15-reg11;
    T reg20=pos_nodes[0][2]*reg0; T reg21=pos_nodes[1][2]*var_inter[0]; T reg22=reg16*reg8; T reg23=pos_nodes[2][1]*var_inter[1]; reg18=reg17+reg18;
    reg17=reg10*reg14; T reg24=pos_nodes[2][0]*var_inter[1]; reg13=reg12+reg13; reg12=reg16*reg1; T reg25=reg2*reg19;
    T reg26=reg16*reg6; T reg27=reg3*reg19; T reg28=reg19*reg11; reg17=reg22-reg17; reg22=pos_nodes[3][0]*var_inter[2];
    reg13=reg24+reg13; reg24=reg14*reg6; T reg29=reg4*reg19; T reg30=pos_nodes[2][2]*var_inter[1]; reg21=reg20+reg21;
    reg23=reg18+reg23; reg18=pos_nodes[3][1]*var_inter[2]; reg20=reg14*reg1; T reg31=reg5*reg19; reg27=reg12-reg27;
    T reg32=reg14*reg2; reg29=reg24-reg29; reg31=reg20-reg31; T reg33=reg4*reg16; T reg34=reg14*reg3;
    T reg35=reg5*reg16; reg25=reg26-reg25; reg13=reg22+reg13; reg18=reg23+reg18; reg30=reg21+reg30;
    reg21=pos_nodes[3][2]*var_inter[2]; reg28=reg17-reg28; reg8=reg8/reg28; reg21=reg30+reg21; reg29=reg29/reg28;
    reg18=pos[1]-reg18; reg27=reg27/reg28; reg35=reg34-reg35; reg13=pos[0]-reg13; reg31=reg31/reg28;
    reg10=reg10/reg28; reg25=reg25/reg28; reg33=reg32-reg33; reg8=reg18*reg8; reg25=reg13*reg25;
    reg29=reg18*reg29; reg27=reg13*reg27; reg31=reg18*reg31; reg10=reg13*reg10; reg35=reg35/reg28;
    reg33=reg33/reg28; reg28=reg11/reg28; reg21=pos[2]-reg21; reg28=reg21*reg28; reg10=reg8-reg10;
    reg33=reg21*reg33; reg29=reg25-reg29; reg35=reg21*reg35; reg27=reg31-reg27; var_inter[0]+=reg10-reg28;
    var_inter[1]+=reg33+reg29; var_inter[2]+=reg27-reg35;

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
    reg1=reg2+reg1; reg2=val[2]*var_inter[1]; reg2=reg1+reg2; reg1=val[3]*var_inter[2]; res=reg2+reg1;

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
    T reg0=var_inter[0]-0.25; T reg1=var_inter[0]-0.16666666666666665741; T reg2=var_inter[0]-0.5; T reg3=reg1*reg2; reg2=reg2*reg0;
    T reg4=var_inter[1]-0.25; reg2=reg2/0.027777777777777783175; T reg5=var_inter[1]-0.16666666666666665741; reg3=reg3/0.020833333333333335646; reg0=reg1*reg0;
    reg2=reg2*reg4; reg1=var_inter[1]-0.5; reg0=reg0/0.083333333333333342585; reg3=reg3*reg5; reg3=reg1*reg3;
    T reg6=reg1*reg2; reg0=reg4*reg0; reg0=reg1*reg0; reg1=var_inter[2]-0.16666666666666665741; reg3=reg3/0.020833333333333335646;
    reg4=var_inter[2]-0.25; reg6=reg6/0.027777777777777783175; reg2=reg5*reg2; reg6=reg6*reg4; reg5=reg3*reg1;
    T reg7=var_inter[2]-0.5; reg0=reg0/0.027777777777777783175; reg2=reg2/0.083333333333333342585; T reg8=reg7*reg6; reg5=reg5*reg7;
    reg0=reg4*reg0; reg8=reg8/0.027777777777777783175; reg0=reg7*reg0; reg5=reg5/0.020833333333333335646; reg4=reg2*reg4;
    reg0=reg0/0.027777777777777783175; reg8=val[1]*reg8; reg7=reg4*reg7; reg5=val[0]*reg5; reg7=reg7/0.027777777777777783175;
    reg6=reg1*reg6; reg5=reg8-reg5; reg0=val[2]*reg0; reg7=val[3]*reg7; reg5=reg0+reg5;
    reg6=reg6/0.083333333333333342585; reg7=reg5+reg7; reg6=val[4]*reg6; res=reg7+reg6;

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
    reg1=var_inter[2]*reg1; reg1=256*reg1; T reg2=1-reg1; T reg3=var_inter[0]*reg2; T reg4=reg0*reg2;
    reg4=val[0]*reg4; reg3=val[1]*reg3; T reg5=var_inter[1]*reg2; reg5=val[2]*reg5; reg2=var_inter[2]*reg2;
    reg3=reg4+reg3; reg2=val[3]*reg2; reg3=reg5+reg3; reg1=val[4]*reg1; reg2=reg3+reg2;
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
    T reg0=elem.pos(1)[1]-elem.pos(0)[1]; T reg1=elem.pos(2)[1]-elem.pos(0)[1]; T reg2=elem.pos(2)[2]-elem.pos(0)[2]; T reg3=elem.pos(3)[2]-elem.pos(0)[2]; T reg4=elem.pos(3)[1]-elem.pos(0)[1];
    T reg5=elem.pos(1)[2]-elem.pos(0)[2]; T reg6=reg3*reg1; T reg7=reg4*reg2; T reg8=reg4*reg5; T reg9=reg3*reg0;
    T reg10=reg5*reg1; reg8=reg9-reg8; reg9=elem.pos(1)[0]-elem.pos(0)[0]; T reg11=reg2*reg0; T reg12=elem.pos(2)[0]-elem.pos(0)[0];
    reg7=reg6-reg7; reg10=reg11-reg10; reg6=elem.pos(3)[0]-elem.pos(0)[0]; reg11=reg8*reg12; T reg13=reg9*reg7;
    reg11=reg13-reg11; reg13=reg10*reg6; reg11=reg13+reg11; return reg11;

}
}
#endif // LMT_TETRA
