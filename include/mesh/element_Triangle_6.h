#ifndef LMT_TRIANGLE_6
#define LMT_TRIANGLE_6
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Triangle_6 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 19, 38, 57, 76, 95, 117, 154, 191, 228, }; // fonction de lordre du poly
    static const double values[] = {
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.0,
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.0,
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.0,
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.0,
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.0,
        0.1125,0.333333333333,0.333333333333,
        0.0661970763943,0.47014206410511505396,0.47014206410511505396,
        0.0661970763943,0.059715871789769892075,0.47014206410511505396,
        0.0661970763943,0.47014206410511505396,0.059715871789769892075,
        0.0629695902724,0.10128650732345637064,0.10128650732345637064,
        0.0629695902724,0.79742698535308725871,0.10128650732345637064,
        0.0629695902724,0.10128650732345637064,0.79742698535308725871,
        0.0,
        0.025422453185102999999,0.063089014491501999997,0.063089014491501999997,
        0.025422453185102999999,0.87382197101699600001,0.063089014491501999997,
        0.025422453185102999999,0.063089014491501999997,0.87382197101699600001,
        0.058393137863188999999,0.24928674517091000001,0.24928674517091000001,
        0.058393137863188999999,0.50142650965817999999,0.24928674517091000001,
        0.058393137863188999999,0.24928674517091000001,0.50142650965817999999,
        0.041425537809187,0.31035245103378499999,0.053145049844815999999,
        0.041425537809187,0.053145049844815999999,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.053145049844815999999,
        0.041425537809187,0.31035245103378499999,0.63650249912139900002,
        0.041425537809187,0.053145049844815999999,0.63650249912139900002,
        0.0,
        0.025422453185102999999,0.063089014491501999997,0.063089014491501999997,
        0.025422453185102999999,0.87382197101699600001,0.063089014491501999997,
        0.025422453185102999999,0.063089014491501999997,0.87382197101699600001,
        0.058393137863188999999,0.24928674517091000001,0.24928674517091000001,
        0.058393137863188999999,0.50142650965817999999,0.24928674517091000001,
        0.058393137863188999999,0.24928674517091000001,0.50142650965817999999,
        0.041425537809187,0.31035245103378499999,0.053145049844815999999,
        0.041425537809187,0.053145049844815999999,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.053145049844815999999,
        0.041425537809187,0.31035245103378499999,0.63650249912139900002,
        0.041425537809187,0.053145049844815999999,0.63650249912139900002,
        0.0,
        0.025422453185102999999,0.063089014491501999997,0.063089014491501999997,
        0.025422453185102999999,0.87382197101699600001,0.063089014491501999997,
        0.025422453185102999999,0.063089014491501999997,0.87382197101699600001,
        0.058393137863188999999,0.24928674517091000001,0.24928674517091000001,
        0.058393137863188999999,0.50142650965817999999,0.24928674517091000001,
        0.058393137863188999999,0.24928674517091000001,0.50142650965817999999,
        0.041425537809187,0.31035245103378499999,0.053145049844815999999,
        0.041425537809187,0.053145049844815999999,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.053145049844815999999,
        0.041425537809187,0.31035245103378499999,0.63650249912139900002,
        0.041425537809187,0.053145049844815999999,0.63650249912139900002,
        0.0,
        0.025422453185102999999,0.063089014491501999997,0.063089014491501999997,
        0.025422453185102999999,0.87382197101699600001,0.063089014491501999997,
        0.025422453185102999999,0.063089014491501999997,0.87382197101699600001,
        0.058393137863188999999,0.24928674517091000001,0.24928674517091000001,
        0.058393137863188999999,0.50142650965817999999,0.24928674517091000001,
        0.058393137863188999999,0.24928674517091000001,0.50142650965817999999,
        0.041425537809187,0.31035245103378499999,0.053145049844815999999,
        0.041425537809187,0.053145049844815999999,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.053145049844815999999,
        0.041425537809187,0.31035245103378499999,0.63650249912139900002,
        0.041425537809187,0.053145049844815999999,0.63650249912139900002,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Triangle_6 &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=nodes[0]->pos[0]+nodes[2]->pos[0]; T reg1=nodes[1]->pos[1]+nodes[0]->pos[1]; T reg2=2*nodes[3]->pos[1]; T reg3=nodes[2]->pos[1]+nodes[0]->pos[1]; T reg4=2*nodes[3]->pos[0];
    T reg5=nodes[0]->pos[0]+nodes[1]->pos[0]; T reg6=2*nodes[4]->pos[0]; reg3=reg3-reg2; T reg7=2*nodes[4]->pos[1]; reg0=reg0-reg4;
    reg5=reg5-reg4; reg1=reg1-reg2; reg5=reg5+reg6; T reg8=2*nodes[5]->pos[0]; reg3=reg3+reg7;
    T reg9=2*nodes[5]->pos[1]; reg0=reg6+reg0; reg1=reg7+reg1; reg0=reg0-reg8; reg1=reg1-reg9;
    reg3=reg3-reg9; reg5=reg5-reg8; reg3=reg5*reg3; reg0=reg1*reg0; T det_jac=reg3-reg0;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[5],nodes[4],nodes[3],nodes[2],nodes[1],nodes[0]};
        for(unsigned i=0;i<6;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Triangle_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*reg0; T reg3=2*var_inter[1];
    T reg4=reg3-1; T reg5=reg1-1; T reg6=reg2-1; T reg7=4*var_inter[0]; T reg8=4*reg0;
    reg3=reg4+reg3; reg1=reg1+reg5; reg2=reg2+reg6; T reg9=reg3*pos_nodes[2][1]; T reg10=pos_nodes[0][1]*reg2;
    T reg11=pos_nodes[1][1]*reg1; reg6=reg0*reg6; T reg12=reg3*pos_nodes[2][0]; reg5=reg5*var_inter[0]; T reg13=pos_nodes[0][0]*reg2;
    T reg14=pos_nodes[1][0]*reg1; T reg15=reg8-reg7; T reg16=4*var_inter[1]; reg4=var_inter[1]*reg4; T reg17=pos_nodes[1][1]*reg5;
    T reg18=reg6*pos_nodes[0][1]; T reg19=reg7*pos_nodes[3][1]; reg9=reg9-reg10; T reg20=reg5*pos_nodes[1][0]; T reg21=reg6*pos_nodes[0][0];
    T reg22=reg7*pos_nodes[3][0]; reg12=reg12-reg13; reg10=reg11-reg10; reg11=reg15*pos_nodes[3][1]; reg13=reg14-reg13;
    reg14=reg15*pos_nodes[3][0]; reg20=reg21+reg20; reg21=reg4*pos_nodes[2][0]; T reg23=reg7*pos_nodes[4][0]; reg22=reg12-reg22;
    reg12=reg8-reg16; reg8=reg8*var_inter[0]; reg17=reg18+reg17; reg18=reg16*pos_nodes[4][1]; reg11=reg10+reg11;
    reg10=reg4*pos_nodes[2][1]; T reg24=reg16*pos_nodes[4][0]; reg14=reg13+reg14; reg13=reg7*pos_nodes[4][1]; reg19=reg9-reg19;
    reg20=reg21+reg20; reg9=reg8*pos_nodes[3][0]; reg21=var_inter[1]*reg7; reg23=reg22+reg23; reg22=reg12*pos_nodes[5][0];
    T reg25=reg16*pos_nodes[5][0]; reg24=reg14+reg24; reg14=reg16*pos_nodes[5][1]; T reg26=reg12*pos_nodes[5][1]; reg18=reg11+reg18;
    reg13=reg19+reg13; reg11=reg8*pos_nodes[3][1]; reg17=reg10+reg17; reg10=reg21*pos_nodes[4][1]; reg11=reg17+reg11;
    reg23=reg22+reg23; reg25=reg24-reg25; reg17=reg0*reg16; reg13=reg26+reg13; reg14=reg18-reg14;
    reg9=reg20+reg9; reg18=reg21*pos_nodes[4][0]; reg19=reg17*pos_nodes[5][1]; reg10=reg11+reg10; reg18=reg9+reg18;
    reg9=reg25*reg13; reg11=reg17*pos_nodes[5][0]; reg20=reg23*reg14; reg10=reg19+reg10; reg18=reg11+reg18;
    reg20=reg9-reg20; reg18=pos[0]-reg18; reg11=reg25/reg20; reg19=reg23/reg20; reg22=reg14/reg20;
    reg20=reg13/reg20; reg10=pos[1]-reg10; reg20=reg18*reg20; reg19=reg10*reg19; reg22=reg18*reg22;
    reg11=reg10*reg11; var_inter[0]=reg20-reg19; var_inter[1]=reg11-reg22;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Triangle_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[1]; T reg2=2*var_inter[0]; T reg3=2*reg0;
    T reg4=reg3-1; T reg5=reg2-1; T reg6=reg1-1; reg3=reg4+reg3; reg2=reg2+reg5;
    reg1=reg6+reg1; T reg7=4*var_inter[0]; T reg8=4*reg0; T reg9=pos_nodes[0][1]*reg3; T reg10=pos_nodes[1][1]*reg2;
    T reg11=pos_nodes[2][1]*reg1; T reg12=pos_nodes[2][0]*reg1; T reg13=pos_nodes[0][0]*reg3; T reg14=pos_nodes[1][0]*reg2; T reg15=reg8-reg7;
    reg5=reg5*var_inter[0]; reg4=reg0*reg4; reg10=reg10-reg9; T reg16=pos_nodes[3][1]*reg15; reg6=reg6*var_inter[1];
    T reg17=pos_nodes[1][0]*reg5; T reg18=pos_nodes[0][0]*reg4; reg9=reg11-reg9; reg11=reg7*pos_nodes[3][1]; T reg19=reg7*pos_nodes[3][0];
    reg12=reg12-reg13; T reg20=pos_nodes[0][1]*reg4; T reg21=pos_nodes[3][0]*reg15; T reg22=4*var_inter[1]; reg13=reg14-reg13;
    reg14=reg5*pos_nodes[1][1]; T reg23=reg8*var_inter[0]; T reg24=reg22*pos_nodes[4][1]; reg14=reg20+reg14; reg16=reg10+reg16;
    reg10=reg7*pos_nodes[4][1]; reg17=reg18+reg17; reg18=reg6*pos_nodes[2][0]; reg11=reg9-reg11; reg19=reg12-reg19;
    reg9=reg22*pos_nodes[4][0]; reg12=reg7*pos_nodes[4][0]; reg8=reg8-reg22; reg20=reg6*pos_nodes[2][1]; reg21=reg13+reg21;
    reg11=reg10+reg11; reg10=reg23*pos_nodes[3][1]; reg13=reg22*pos_nodes[5][1]; reg16=reg24+reg16; reg14=reg20+reg14;
    reg20=pos_nodes[5][1]*reg8; reg21=reg9+reg21; reg9=reg22*pos_nodes[5][0]; reg24=reg7*var_inter[1]; T reg25=reg23*pos_nodes[3][0];
    reg17=reg18+reg17; reg19=reg12+reg19; reg12=pos_nodes[5][0]*reg8; reg18=reg0*reg22; T reg26=reg24*pos_nodes[4][1];
    reg20=reg11+reg20; reg9=reg21-reg9; reg12=reg19+reg12; reg11=reg24*pos_nodes[4][0]; reg13=reg16-reg13;
    reg25=reg17+reg25; reg10=reg14+reg10; reg10=reg26+reg10; reg14=reg18*pos_nodes[5][1]; reg16=reg9*reg20;
    reg25=reg11+reg25; reg11=reg18*pos_nodes[5][0]; reg17=reg12*reg13; reg14=reg10+reg14; reg17=reg16-reg17;
    reg11=reg25+reg11; reg10=reg12/reg17; reg19=reg13/reg17; reg21=reg9/reg17; reg17=reg20/reg17;
    reg14=pos[1]-reg14; reg11=pos[0]-reg11; reg17=reg11*reg17; reg10=reg14*reg10; reg19=reg11*reg19;
    reg21=reg14*reg21; var_inter[0]+=reg17-reg10; var_inter[1]+=reg21-reg19;

}
template<> struct ElemVarInterFromPosNonLinear<Triangle_6> { static const bool res = 2; };
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*reg0; T reg2=2*var_inter[0]; reg2=reg2-1;
    reg1=reg1-1; T reg3=2*var_inter[1]; reg2=var_inter[0]*reg2; reg3=reg3-1; reg1=reg1*reg0;
    reg2=val[1]*reg2; reg1=val[0]*reg1; T reg4=4*reg0; reg3=var_inter[1]*reg3; reg4=var_inter[0]*reg4;
    T reg5=4*var_inter[0]; reg2=reg1+reg2; reg3=val[2]*reg3; reg1=4*var_inter[1]; reg5=var_inter[1]*reg5;
    reg4=val[3]*reg4; reg3=reg2+reg3; reg1=reg1*reg0; reg5=val[4]*reg5; reg4=reg3+reg4;
    reg1=val[5]*reg1; reg5=reg4+reg5; res=reg5+reg1;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_0
#define STRUCT_Gauss_0
struct Gauss_0 {};
#endif // STRUCT_Gauss_0
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Gauss_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss_2
#define STRUCT_Gauss_2
struct Gauss_2 {};
#endif // STRUCT_Gauss_2
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Gauss_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Flat_interpolation
#define STRUCT_Flat_interpolation
struct Flat_interpolation {};
#endif // STRUCT_Flat_interpolation
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Flat_interpolation &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Nodal_3
#define STRUCT_Nodal_3
struct Nodal_3 {};
#endif // STRUCT_Nodal_3
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Nodal_3 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=val[0]*reg0; T reg2=val[1]*var_inter[0]; reg2=reg1+reg2;
    reg1=val[2]*var_inter[1]; res=reg2+reg1;

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
template<class TVI,class TVAL> void get_shape_functions(const Triangle_6 &ne,const TVI &var_inter,TVAL &res) {
    typedef typename TVAL::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*reg0; T reg2=2*var_inter[1]; T reg3=2*var_inter[0];
    reg3=reg3-1; T reg4=4*var_inter[1]; T reg5=4*var_inter[0]; T reg6=4*reg0; reg2=reg2-1;
    reg1=reg1-1; reg6=var_inter[0]*reg6; res[3]=reg6; reg5=var_inter[1]*reg5; res[4]=reg5;
    reg4=reg4*reg0; res[5]=reg4; reg2=var_inter[1]*reg2; res[2]=reg2; reg1=reg1*reg0;
    res[0]=reg1; reg3=var_inter[0]*reg3; res[1]=reg3;

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Triangle_6> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

template<class TN,class TNG,class TD,unsigned NET,class TVI>
typename TNG::T get_det_jac( const Element<Triangle_6,TN,TNG,TD,NET> &elem, const TVI &var_inter ) {
    typedef typename TNG::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*reg0; T reg2=2*var_inter[0]; T reg3=reg1-1;
    T reg4=reg2-1; reg2=reg2+reg4; T reg5=4*var_inter[0]; T reg6=4*reg0; reg1=reg1+reg3;
    T reg7=elem.pos(1)[0]*reg2; T reg8=reg1*elem.pos(0)[0]; T reg9=reg6-reg5; T reg10=elem.pos(1)[1]*reg2; T reg11=elem.pos(0)[1]*reg1;
    reg10=reg10-reg11; T reg12=elem.pos(3)[0]*reg9; reg2=elem.pos(1)[2]*reg2; T reg13=elem.pos(0)[2]*reg1; T reg14=4*var_inter[1];
    T reg15=elem.pos(3)[1]*reg9; reg7=reg7-reg8; reg2=reg2-reg13; reg9=elem.pos(3)[2]*reg9; T reg16=elem.pos(4)[1]*reg14;
    T reg17=elem.pos(4)[0]*reg14; reg10=reg15+reg10; reg7=reg12+reg7; reg12=2*var_inter[1]; reg9=reg2+reg9;
    reg2=elem.pos(5)[1]*reg14; reg15=reg12-1; T reg18=elem.pos(4)[2]*reg14; T reg19=elem.pos(5)[0]*reg14; reg7=reg17+reg7;
    reg10=reg16+reg10; reg7=reg7-reg19; reg18=reg9+reg18; reg12=reg12+reg15; reg9=elem.pos(5)[2]*reg14;
    reg10=reg10-reg2; reg16=pow(reg10,2); reg17=pow(reg7,2); reg18=reg18-reg9; T reg20=elem.pos(2)[0]*reg12;
    T reg21=elem.pos(2)[1]*reg12; T reg22=elem.pos(3)[0]*reg5; reg12=elem.pos(2)[2]*reg12; T reg23=elem.pos(3)[1]*reg5; reg16=reg17+reg16;
    reg17=pow(reg18,2); reg21=reg21-reg11; reg20=reg20-reg8; T reg24=reg6-reg14; T reg25=elem.pos(4)[1]*reg5;
    reg21=reg21-reg23; T reg26=elem.pos(3)[2]*reg5; reg17=reg16+reg17; reg12=reg12-reg13; reg16=elem.pos(4)[0]*reg5;
    reg20=reg20-reg22; reg20=reg16+reg20; reg16=elem.pos(5)[0]*reg24; reg12=reg12-reg26; reg17=pow(reg17,0.5);
    reg25=reg21+reg25; reg21=elem.pos(5)[1]*reg24; T reg27=elem.pos(4)[2]*reg5; T reg28=reg10/reg17; T reg29=reg7/reg17;
    reg21=reg25+reg21; reg20=reg16+reg20; reg24=elem.pos(5)[2]*reg24; reg27=reg12+reg27; reg17=reg18/reg17;
    reg12=reg21*reg28; reg16=reg20*reg29; reg27=reg24+reg27; reg24=reg17*reg27; reg12=reg16+reg12;
    reg24=reg12+reg24; reg12=reg24*reg28; reg16=reg24*reg29; reg12=reg21-reg12; reg16=reg20-reg16;
    reg25=reg24*reg17; T reg30=pow(reg12,2); T reg31=pow(reg16,2); reg25=reg27-reg25; reg30=reg31+reg30;
    reg31=pow(reg25,2); reg31=reg30+reg31; reg31=pow(reg31,0.5); reg12=reg12/reg31; reg16=reg16/reg31;
    reg20=reg20*reg16; reg31=reg25/reg31; reg29=reg29*reg7; reg28=reg28*reg10; reg7=reg16*reg7;
    reg21=reg21*reg12; reg10=reg12*reg10; reg27=reg31*reg27; reg31=reg18*reg31; reg17=reg18*reg17;
    reg21=reg20+reg21; reg10=reg7+reg10; reg28=reg29+reg28; reg10=reg31+reg10; reg17=reg28+reg17;
    reg27=reg21+reg27; reg7=reg24*reg10; reg12=reg27*reg17; reg7=reg12-reg7; return reg7;

}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,2> barycenter( const Element<Triangle_6,TN,Node<2,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,2> res;
    T reg0=0.78379396366385999995*elem.pos(0)[1]; T reg1=0.56758792732771999991*elem.pos(1)[0]; T reg2=0.78379396366385999995*elem.pos(0)[0]; T reg3=0.56758792732771999991*elem.pos(1)[1]; T reg4=0.78379396366385999995*elem.pos(2)[0];
    T reg5=0.78379396366385999995*elem.pos(1)[1]; T reg6=0.56758792732771999991*elem.pos(0)[0]; T reg7=0.78379396366385999995*elem.pos(1)[0]; T reg8=0.56758792732771999991*elem.pos(0)[1]; T reg9=0.78379396366385999995*elem.pos(2)[1];
    T reg10=reg1+reg2; T reg11=reg0+reg3; T reg12=0.048208377815511963759*elem.pos(1)[0]; T reg13=0.56758792732771999991*elem.pos(2)[0]; T reg14=0.084730493093977855013*elem.pos(0)[0];
    T reg15=0.048208377815511963759*elem.pos(1)[1]; T reg16=1.78379396366386*elem.pos(3)[0]; T reg17=reg6+reg4; T reg18=reg9+reg8; T reg19=0.084730493093977855013*elem.pos(0)[1];
    T reg20=0.048208377815511963759*elem.pos(0)[0]; T reg21=0.56758792732771999991*elem.pos(2)[1]; T reg22=1.78379396366386*elem.pos(3)[1]; T reg23=reg7+reg6; T reg24=1.3513818909915799999*elem.pos(3)[0];
    T reg25=0.084730493093977855013*elem.pos(1)[0]; T reg26=1.3513818909915799999*elem.pos(3)[1]; T reg27=reg8+reg5; T reg28=0.084730493093977855013*elem.pos(1)[1]; T reg29=0.048208377815511963759*elem.pos(0)[1];
    reg9=reg9-reg0; T reg30=0.43241207267228000009*elem.pos(3)[1]; T reg31=0.63369514596091600003*elem.pos(1)[1]; T reg32=reg2+reg13; T reg33=0.63369514596091600003*elem.pos(2)[1];
    T reg34=reg24-reg10; T reg35=2.2673902919218320001*elem.pos(0)[0]; T reg36=0.63369514596091600003*elem.pos(1)[0]; T reg37=reg0+reg21; T reg38=2.2673902919218320001*elem.pos(0)[1];
    T reg39=reg26-reg11; T reg40=reg20+reg25; T reg41=0.43241207267228000009*elem.pos(3)[0]; reg4=reg4-reg2; reg27=reg27-reg26;
    T reg42=0.048208377815511963759*elem.pos(2)[1]; T reg43=reg15+reg19; reg17=reg17-reg16; T reg44=1.78379396366386*elem.pos(4)[0]; reg23=reg23-reg24;
    T reg45=reg28+reg29; T reg46=reg14+reg12; T reg47=0.048208377815511963759*elem.pos(2)[0]; T reg48=1.78379396366386*elem.pos(4)[1]; reg18=reg18-reg22;
    T reg49=0.63369514596091600003*elem.pos(2)[0]; T reg50=reg15+reg29; T reg51=reg42+reg45; T reg52=0.084730493093977855013*elem.pos(2)[1]; reg16=reg16+reg32;
    T reg53=reg12+reg20; T reg54=0.084730493093977855013*elem.pos(2)[0]; T reg55=0.19283351126204785504*elem.pos(3)[1]; T reg56=reg43+reg42; T reg57=0.074803807748196670769*elem.pos(1)[1];
    T reg58=0.51763234198767131696*elem.pos(0)[1]; reg0=reg5-reg0; reg5=reg33+reg38; T reg59=2.2673902919218320001*elem.pos(1)[1]; T reg60=0.63369514596091600003*elem.pos(0)[0];
    T reg61=2.2673902919218320001*elem.pos(1)[0]; T reg62=0.366304854039084*elem.pos(3)[1]; T reg63=0.63369514596091600003*elem.pos(0)[1]; T reg64=0.074803807748196670769*elem.pos(1)[0]; T reg65=0.51763234198767131696*elem.pos(0)[0];
    T reg66=0.366304854039084*elem.pos(3)[0]; T reg67=reg35+reg49; reg35=reg36+reg35; T reg68=2.9010854378827480001*elem.pos(3)[0]; T reg69=2.9010854378827480001*elem.pos(3)[1];
    reg38=reg38+reg31; reg23=reg23+reg44; T reg70=1.78379396366386*elem.pos(5)[1]; T reg71=reg47+reg40; T reg72=1.78379396366386*elem.pos(5)[0];
    T reg73=1.3513818909915799999*elem.pos(5)[0]; T reg74=0.43241207267228000009*elem.pos(4)[0]; reg17=reg44+reg17; reg41=reg4-reg41; reg4=0.19283351126204785504*elem.pos(3)[0];
    reg22=reg22+reg37; reg30=reg9-reg30; reg9=0.43241207267228000009*elem.pos(4)[1]; reg27=reg48+reg27; reg34=reg44+reg34;
    reg39=reg48+reg39; reg2=reg7-reg2; reg7=reg46+reg47; reg18=reg18+reg48; T reg75=1.3513818909915799999*elem.pos(5)[1];
    T reg76=0.79548022620090607244*elem.pos(4)[1]; reg17=reg17-reg73; T reg77=reg55-reg56; reg59=reg63+reg59; T reg78=0.366304854039084*elem.pos(4)[0];
    T reg79=reg68-reg35; reg30=reg30+reg9; reg34=reg34-reg72; T reg80=0.074803807748196670763*elem.pos(0)[1]; T reg81=reg69-reg38;
    T reg82=2.2673902919218320001*elem.pos(2)[1]; reg61=reg61+reg60; T reg83=reg67+reg66; reg58=reg58-reg57; T reg84=0.51763234198767131696*elem.pos(1)[1];
    T reg85=0.79548022620090607244*elem.pos(4)[0]; T reg86=reg4-reg7; reg65=reg65-reg64; T reg87=0.074803807748196670769*elem.pos(2)[0]; T reg88=3.2673902919218320001*elem.pos(3)[1];
    T reg89=reg63-reg33; T reg90=0.074803807748196670769*elem.pos(2)[1]; reg2=reg74+reg2; T reg91=0.43241207267228000009*elem.pos(5)[0]; reg0=reg9+reg0;
    reg9=0.43241207267228000009*elem.pos(5)[1]; reg48=reg48-reg22; reg44=reg44-reg16; T reg92=0.51763234198767131696*elem.pos(1)[0]; T reg93=0.074803807748196670763*elem.pos(0)[0];
    reg27=reg27-reg70; T reg94=reg50+reg52; T reg95=0.79548022620090607244*elem.pos(3)[1]; T reg96=0.19283351126204785504*elem.pos(4)[0]; reg4=reg4-reg71;
    T reg97=reg53+reg54; T reg98=0.79548022620090607244*elem.pos(3)[0]; reg72=reg23-reg72; reg18=reg18-reg75; reg23=reg60-reg49;
    T reg99=0.366304854039084*elem.pos(4)[1]; T reg100=reg5+reg62; reg70=reg39-reg70; reg74=reg41+reg74; reg39=3.2673902919218320001*elem.pos(3)[0];
    reg41=2.2673902919218320001*elem.pos(2)[0]; T reg101=0.19283351126204785504*elem.pos(4)[1]; reg55=reg55-reg51; reg95=reg95-reg94; reg58=reg58-reg90;
    reg82=reg63+reg82; T reg102=0.79548022620090607244*elem.pos(5)[1]; reg61=reg61-reg68; reg88=reg89-reg88; reg89=3.2673902919218320001*elem.pos(4)[1];
    reg55=reg55+reg101; reg17=reg27*reg17; reg92=reg92-reg93; reg27=3.2673902919218320001*elem.pos(4)[0]; reg59=reg59-reg69;
    T reg103=reg60-reg36; reg39=reg23-reg39; reg84=reg84-reg80; reg23=0.366304854039084*elem.pos(5)[0]; reg79=reg79+reg78;
    T reg104=2.9010854378827480001*elem.pos(5)[1]; reg34=reg30*reg34; reg30=reg99-reg100; reg74=reg70*reg74; reg41=reg60+reg41;
    reg72=reg18*reg72; reg18=0.074803807748196670769*elem.pos(0)[1]; reg98=reg98-reg97; reg4=reg4+reg96; reg70=0.79548022620090607244*elem.pos(5)[0];
    T reg105=0.074803807748196670769*elem.pos(0)[0]; reg44=reg73+reg44; reg48=reg75+reg48; reg9=reg0-reg9; reg91=reg2-reg91;
    reg0=0.29921523099278668308*elem.pos(3)[1]; reg2=2.710505431213761085e-20*elem.pos(3)[0]; T reg106=0.19283351126204785504*elem.pos(5)[1]; T reg107=0.29921523099278668308*elem.pos(3)[0]; reg65=reg65-reg87;
    reg76=reg77+reg76; reg77=reg63-reg31; T reg108=2.9010854378827480001*elem.pos(5)[0]; T reg109=reg78-reg83; reg85=reg86+reg85;
    reg86=0.19283351126204785504*elem.pos(5)[0]; T reg110=2.710505431213761085e-20*elem.pos(3)[1]; T reg111=0.366304854039084*elem.pos(5)[1]; reg81=reg99+reg81; reg66=reg41-reg66;
    reg77=reg77-reg110; reg62=reg82-reg62; reg41=reg64+reg105; reg82=0.51763234198767131696*elem.pos(2)[0]; reg76=reg76+reg106;
    reg103=reg103-reg2; reg102=reg55+reg102; reg98=reg96+reg98; reg55=reg57+reg18; reg96=0.29921523099278668305*elem.pos(3)[1];
    reg74=reg34-reg74; reg30=reg30+reg104; reg79=reg79-reg23; reg84=reg84-reg90; reg81=reg81-reg111;
    reg85=reg85+reg86; reg109=reg109+reg108; reg70=reg4+reg70; reg107=reg65+reg107; reg4=0.033544811523148658458*elem.pos(4)[0];
    reg34=0.51763234198767131696*elem.pos(2)[1]; reg65=0.033544811523148658458*elem.pos(4)[1]; reg0=reg58+reg0; reg88=reg88+reg89; reg58=5.42101086242752217e-20*elem.pos(5)[1];
    reg17=reg72-reg17; reg61=reg78+reg61; reg44=reg9*reg44; reg59=reg99+reg59; reg95=reg101+reg95;
    reg39=reg39+reg27; reg9=5.42101086242752217e-20*elem.pos(5)[0]; reg92=reg92-reg87; reg72=0.29921523099278668305*elem.pos(3)[0]; reg91=reg48*reg91;
    reg34=reg34-reg55; reg48=0.033544811523148658455*elem.pos(3)[1]; reg101=0.29921523099278668308*elem.pos(4)[1]; reg96=reg84+reg96; reg84=0.29921523099278668308*elem.pos(5)[1];
    reg76=reg17*reg76; reg65=reg0+reg65; reg95=reg106+reg95; reg102=reg74*reg102; reg109=reg81*reg109;
    reg82=reg82-reg41; reg66=reg78+reg66; reg0=3.2673902919218320001*elem.pos(5)[1]; reg77=reg89+reg77; reg78=3.2673902919218320001*elem.pos(5)[0];
    reg103=reg27+reg103; reg62=reg99+reg62; reg4=reg107+reg4; reg27=0.29921523099278668308*elem.pos(5)[0]; reg81=0.29921523099278668308*elem.pos(4)[0];
    reg88=reg88-reg58; reg72=reg92+reg72; reg23=reg61-reg23; reg39=reg39-reg9; reg111=reg59-reg111;
    reg44=reg91-reg44; reg98=reg86+reg98; reg70=reg74*reg70; reg59=0.033544811523148658455*elem.pos(3)[0]; reg79=reg30*reg79;
    reg85=reg17*reg85; reg23=reg88*reg23; reg59=reg82+reg59; reg39=reg111*reg39; reg17=0.111690794839005*reg17;
    reg48=reg34+reg48; reg102=0.111690794839005*reg102; reg70=0.111690794839005*reg70; reg72=reg72+reg81; reg30=0.033544811523148658451*elem.pos(5)[0];
    reg4=reg4+reg27; reg74=0.111690794839005*reg74; reg95=reg44*reg95; reg85=0.111690794839005*reg85; reg65=reg65+reg84;
    reg66=reg66-reg108; reg0=reg77-reg0; reg98=reg44*reg98; reg96=reg96+reg101; reg109=reg79-reg109;
    reg78=reg103-reg78; reg34=0.033544811523148658451*elem.pos(5)[1]; reg76=0.111690794839005*reg76; reg62=reg62-reg104; reg70=reg85+reg70;
    reg34=reg96+reg34; reg48=reg101+reg48; reg98=0.111690794839005*reg98; reg4=reg109*reg4; reg65=reg109*reg65;
    reg95=0.111690794839005*reg95; reg39=reg23-reg39; reg102=reg76+reg102; reg59=reg81+reg59; reg30=reg72+reg30;
    reg74=reg17+reg74; reg44=0.111690794839005*reg44; reg78=reg62*reg78; reg66=reg0*reg66; reg48=reg84+reg48;
    reg59=reg27+reg59; reg34=reg39*reg34; reg44=reg74+reg44; reg109=0.054975871827660999999*reg109; reg98=reg70+reg98;
    reg4=0.054975871827660999999*reg4; reg65=0.054975871827660999999*reg65; reg66=reg78-reg66; reg95=reg102+reg95; reg30=reg39*reg30;
    reg4=reg98+reg4; reg48=reg66*reg48; reg59=reg66*reg59; reg65=reg95+reg65; reg39=0.054975871827660999999*reg39;
    reg109=reg44+reg109; reg34=0.054975871827660999999*reg34; reg30=0.054975871827660999999*reg30; reg59=0.054975871827660999999*reg59; reg34=reg65+reg34;
    reg30=reg4+reg30; reg39=reg109+reg39; reg66=0.054975871827660999999*reg66; reg48=0.054975871827660999999*reg48; reg48=reg34+reg48;
    reg59=reg30+reg59; reg66=reg39+reg66; res[0]=reg59/reg66; res[1]=reg48/reg66;

    return res;
}
template<class TN,class T,class TNodalStaticData,class TD,unsigned NET>
Vec<T,3> barycenter( const Element<Triangle_6,TN,Node<3,T,TNodalStaticData>,TD,NET> &elem ) {
    Vec<T,3> res;
    T reg0=0.56758792732771999991*elem.pos(0)[0]; T reg1=0.78379396366385999995*elem.pos(1)[0]; T reg2=0.56758792732771999991*elem.pos(0)[1]; T reg3=0.78379396366385999995*elem.pos(1)[1]; T reg4=0.78379396366385999995*elem.pos(0)[0];
    T reg5=0.56758792732771999991*elem.pos(1)[0]; T reg6=0.56758792732771999991*elem.pos(1)[1]; T reg7=0.78379396366385999995*elem.pos(0)[1]; T reg8=1.3513818909915799999*elem.pos(3)[1]; T reg9=reg6+reg7;
    T reg10=0.56758792732771999991*elem.pos(0)[2]; T reg11=reg3+reg2; T reg12=1.3513818909915799999*elem.pos(3)[0]; T reg13=reg1+reg0; T reg14=0.78379396366385999995*elem.pos(1)[2];
    T reg15=0.56758792732771999991*elem.pos(1)[2]; T reg16=reg5+reg4; T reg17=0.78379396366385999995*elem.pos(0)[2]; reg13=reg13-reg12; T reg18=reg14+reg10;
    T reg19=reg8-reg9; T reg20=1.3513818909915799999*elem.pos(3)[2]; T reg21=reg15+reg17; T reg22=reg12-reg16; T reg23=0.63369514596091600003*elem.pos(1)[0];
    T reg24=2.2673902919218320001*elem.pos(0)[0]; T reg25=1.78379396366386*elem.pos(4)[1]; reg11=reg11-reg8; T reg26=0.63369514596091600003*elem.pos(1)[1]; T reg27=2.2673902919218320001*elem.pos(0)[1];
    T reg28=1.78379396366386*elem.pos(4)[0]; T reg29=reg20-reg21; T reg30=1.78379396366386*elem.pos(5)[0]; reg13=reg13+reg28; reg11=reg11+reg25;
    T reg31=1.78379396366386*elem.pos(5)[1]; T reg32=2.2673902919218320001*elem.pos(1)[0]; T reg33=0.63369514596091600003*elem.pos(0)[0]; T reg34=0.43241207267228000009*elem.pos(4)[1]; reg22=reg28+reg22;
    T reg35=0.63369514596091600003*elem.pos(0)[1]; reg1=reg1-reg4; T reg36=reg23+reg24; T reg37=0.43241207267228000009*elem.pos(4)[0]; T reg38=2.9010854378827480001*elem.pos(3)[0];
    T reg39=2.2673902919218320001*elem.pos(1)[1]; T reg40=1.78379396366386*elem.pos(4)[2]; T reg41=2.9010854378827480001*elem.pos(3)[1]; T reg42=reg26+reg27; reg18=reg18-reg20;
    T reg43=0.63369514596091600003*elem.pos(1)[2]; T reg44=2.2673902919218320001*elem.pos(0)[2]; reg3=reg3-reg7; reg19=reg25+reg19; reg32=reg32+reg33;
    reg39=reg39+reg35; reg29=reg40+reg29; reg19=reg19-reg31; T reg45=reg43+reg44; T reg46=2.9010854378827480001*elem.pos(3)[2];
    T reg47=0.366304854039084*elem.pos(4)[1]; T reg48=reg41-reg42; T reg49=0.366304854039084*elem.pos(4)[0]; T reg50=reg38-reg36; reg22=reg22-reg30;
    reg14=reg14-reg17; reg3=reg34+reg3; T reg51=0.43241207267228000009*elem.pos(5)[1]; T reg52=1.78379396366386*elem.pos(5)[2]; reg18=reg18+reg40;
    T reg53=2.2673902919218320001*elem.pos(1)[2]; reg30=reg13-reg30; reg13=0.63369514596091600003*elem.pos(0)[2]; reg31=reg11-reg31; reg11=0.43241207267228000009*elem.pos(5)[0];
    T reg54=0.43241207267228000009*elem.pos(4)[2]; reg1=reg37+reg1; T reg55=0.366304854039084*elem.pos(4)[2]; reg53=reg53+reg13; T reg56=pow(reg19,2);
    T reg57=reg46-reg45; reg50=reg50+reg49; T reg58=0.366304854039084*elem.pos(5)[0]; reg11=reg1-reg11; reg1=reg35-reg26;
    T reg59=0.366304854039084*elem.pos(5)[1]; reg48=reg48+reg47; T reg60=2.710505431213761085e-20*elem.pos(3)[1]; T reg61=reg33-reg23; T reg62=2.710505431213761085e-20*elem.pos(3)[0];
    reg14=reg54+reg14; reg51=reg3-reg51; reg39=reg39-reg41; reg18=reg18-reg52; reg3=0.43241207267228000009*elem.pos(5)[2];
    reg32=reg32-reg38; T reg63=0.78379396366385999995*elem.pos(2)[0]; T reg64=pow(reg31,2); reg52=reg29-reg52; reg29=0.78379396366385999995*elem.pos(2)[1];
    T reg65=pow(reg22,2); T reg66=pow(reg30,2); T reg67=0.56758792732771999991*elem.pos(2)[1]; T reg68=0.56758792732771999991*elem.pos(2)[0]; reg50=reg50-reg58;
    reg1=reg1-reg60; reg61=reg61-reg62; reg3=reg14-reg3; reg14=reg13-reg43; T reg69=2.710505431213761085e-20*elem.pos(3)[2];
    T reg70=pow(reg18,2); T reg71=pow(reg51,2); reg32=reg49+reg32; reg64=reg66+reg64; reg66=reg0+reg63;
    T reg72=1.78379396366386*elem.pos(3)[0]; T reg73=pow(reg52,2); T reg74=reg2+reg29; T reg75=1.78379396366386*elem.pos(3)[1]; reg39=reg47+reg39;
    reg56=reg65+reg56; reg65=0.78379396366385999995*elem.pos(2)[2]; T reg76=0.366304854039084*elem.pos(5)[2]; reg57=reg57+reg55; reg53=reg53-reg46;
    T reg77=pow(reg11,2); T reg78=3.2673902919218320001*elem.pos(4)[0]; T reg79=3.2673902919218320001*elem.pos(4)[1]; reg48=reg48-reg59; reg29=reg29-reg7;
    T reg80=0.43241207267228000009*elem.pos(3)[1]; T reg81=0.43241207267228000009*elem.pos(3)[0]; reg73=reg56+reg73; reg63=reg63-reg4; reg71=reg77+reg71;
    reg53=reg55+reg53; reg56=3.2673902919218320001*elem.pos(4)[2]; reg59=reg39-reg59; reg70=reg64+reg70; reg61=reg78+reg61;
    reg58=reg32-reg58; reg66=reg66-reg72; reg32=3.2673902919218320001*elem.pos(5)[0]; reg74=reg74-reg75; reg1=reg79+reg1;
    reg39=0.63369514596091600003*elem.pos(2)[1]; reg64=3.2673902919218320001*elem.pos(5)[1]; reg77=0.63369514596091600003*elem.pos(2)[0]; T reg82=reg10+reg65; T reg83=1.78379396366386*elem.pos(3)[2];
    reg14=reg14-reg69; reg57=reg57-reg76; T reg84=pow(reg48,2); T reg85=pow(reg50,2); T reg86=0.56758792732771999991*elem.pos(2)[2];
    reg7=reg7+reg67; reg4=reg4+reg68; T reg87=pow(reg3,2); reg64=reg1-reg64; reg14=reg56+reg14;
    reg32=reg61-reg32; reg1=3.2673902919218320001*elem.pos(5)[2]; reg61=0.43241207267228000009*elem.pos(3)[2]; reg65=reg65-reg17; reg76=reg53-reg76;
    reg53=pow(reg59,2); T reg88=pow(reg58,2); T reg89=0.63369514596091600003*elem.pos(2)[2]; T reg90=0.366304854039084*elem.pos(3)[1]; reg27=reg27+reg39;
    T reg91=0.366304854039084*elem.pos(3)[0]; reg24=reg24+reg77; T reg92=pow(reg57,2); reg84=reg85+reg84; reg17=reg17+reg86;
    reg75=reg75+reg7; reg72=reg72+reg4; reg87=reg71+reg87; reg81=reg63-reg81; reg80=reg29-reg80;
    reg29=1.3513818909915799999*elem.pos(5)[0]; reg66=reg28+reg66; reg82=reg82-reg83; reg63=1.3513818909915799999*elem.pos(5)[1]; reg74=reg25+reg74;
    reg70=pow(reg70,0.5); reg73=pow(reg73,0.5); reg87=pow(reg87,0.5); reg1=reg14-reg1; reg83=reg83+reg17;
    reg14=pow(reg64,2); reg71=pow(reg32,2); reg85=reg33-reg77; T reg93=reg27+reg90; T reg94=reg22/reg73;
    T reg95=3.2673902919218320001*elem.pos(3)[0]; T reg96=reg19/reg73; reg66=reg66-reg29; T reg97=3.2673902919218320001*elem.pos(3)[1]; T reg98=reg35-reg39;
    reg44=reg44+reg89; reg37=reg81+reg37; reg81=0.366304854039084*elem.pos(3)[2]; reg25=reg25-reg75; reg34=reg80+reg34;
    reg61=reg65-reg61; reg28=reg28-reg72; reg65=1.3513818909915799999*elem.pos(5)[2]; reg82=reg40+reg82; reg92=reg84+reg92;
    reg80=reg31/reg70; reg84=reg30/reg70; T reg99=2.2673902919218320001*elem.pos(2)[1]; reg53=reg88+reg53; reg74=reg74-reg63;
    reg88=pow(reg76,2); T reg100=2.2673902919218320001*elem.pos(2)[0]; T reg101=reg24+reg91; reg25=reg63+reg25; T reg102=reg51/reg87;
    reg70=reg18/reg70; reg95=reg85-reg95; reg40=reg40-reg83; reg73=reg52/reg73; reg85=reg44+reg81;
    reg88=reg53+reg88; reg28=reg29+reg28; reg53=reg11/reg87; reg99=reg35+reg99; reg82=reg82-reg65;
    T reg103=reg80*reg74; reg100=reg33+reg100; T reg104=reg49-reg101; T reg105=2.9010854378827480001*elem.pos(5)[0]; reg54=reg61+reg54;
    reg61=reg94*reg37; T reg106=2.2673902919218320001*elem.pos(2)[2]; T reg107=pow(reg1,2); reg14=reg71+reg14; reg71=reg84*reg66;
    T reg108=3.2673902919218320001*elem.pos(3)[2]; T reg109=reg13-reg89; T reg110=reg47-reg93; T reg111=2.9010854378827480001*elem.pos(5)[1]; T reg112=reg96*reg34;
    reg97=reg98-reg97; reg92=pow(reg92,0.5); reg98=reg70*reg82; T reg113=2.9010854378827480001*elem.pos(5)[2]; T reg114=reg50/reg92;
    T reg115=reg48/reg92; reg103=reg71+reg103; reg104=reg104+reg105; reg71=reg102*reg25; T reg116=reg55-reg85;
    reg110=reg110+reg111; reg40=reg65+reg40; reg112=reg61+reg112; reg61=reg53*reg28; reg87=reg3/reg87;
    reg88=pow(reg88,0.5); T reg117=reg73*reg54; reg108=reg109-reg108; reg107=reg14+reg107; reg106=reg13+reg106;
    reg78=reg95+reg78; reg14=5.42101086242752217e-20*elem.pos(5)[0]; reg90=reg99-reg90; reg95=5.42101086242752217e-20*elem.pos(5)[1]; reg79=reg97+reg79;
    reg91=reg100-reg91; reg97=reg114*reg104; reg107=pow(reg107,0.5); reg91=reg49+reg91; reg92=reg57/reg92;
    reg90=reg47+reg90; reg81=reg106-reg81; reg117=reg112+reg117; reg98=reg103+reg98; reg116=reg116+reg113;
    reg71=reg61+reg71; reg47=reg58/reg88; reg49=reg59/reg88; reg61=reg87*reg40; reg78=reg78-reg14;
    reg99=reg115*reg110; reg79=reg79-reg95; reg56=reg108+reg56; reg100=5.42101086242752217e-20*elem.pos(5)[2]; reg103=reg64/reg107;
    reg99=reg97+reg99; reg91=reg91-reg105; reg97=reg47*reg78; reg106=reg32/reg107; reg90=reg90-reg111;
    reg88=reg76/reg88; reg108=reg49*reg79; reg81=reg55+reg81; reg56=reg56-reg100; reg55=reg92*reg116;
    reg109=reg84*reg98; reg112=reg80*reg98; T reg118=reg96*reg117; T reg119=reg94*reg117; reg61=reg71+reg61;
    reg71=reg103*reg90; reg109=reg66-reg109; reg118=reg34-reg118; reg112=reg74-reg112; T reg120=reg70*reg98;
    reg119=reg37-reg119; T reg121=reg88*reg56; reg81=reg81-reg113; T reg122=reg73*reg117; T reg123=reg102*reg61;
    reg108=reg97+reg108; reg55=reg99+reg55; reg97=reg53*reg61; reg99=reg106*reg91; reg107=reg1/reg107;
    T reg124=pow(reg109,2); T reg125=reg114*reg55; T reg126=pow(reg112,2); T reg127=pow(reg119,2); T reg128=reg115*reg55;
    reg120=reg82-reg120; reg71=reg99+reg71; reg123=reg25-reg123; reg121=reg108+reg121; reg99=pow(reg118,2);
    reg108=reg87*reg61; reg122=reg54-reg122; T reg129=reg107*reg81; reg97=reg28-reg97; T reg130=reg49*reg121;
    T reg131=reg92*reg55; reg108=reg40-reg108; T reg132=reg47*reg121; reg129=reg71+reg129; reg126=reg124+reg126;
    reg71=pow(reg120,2); reg124=pow(reg123,2); reg99=reg127+reg99; reg127=pow(reg97,2); T reg133=pow(reg122,2);
    reg128=reg110-reg128; reg125=reg104-reg125; T reg134=pow(reg128,2); reg124=reg127+reg124; reg130=reg79-reg130;
    reg127=pow(reg108,2); T reg135=reg88*reg121; reg131=reg116-reg131; T reg136=pow(reg125,2); reg133=reg99+reg133;
    reg132=reg78-reg132; reg71=reg126+reg71; reg99=reg106*reg129; reg126=reg103*reg129; reg133=pow(reg133,0.5);
    T reg137=pow(reg130,2); reg71=pow(reg71,0.5); reg99=reg91-reg99; reg126=reg90-reg126; reg127=reg124+reg127;
    reg134=reg136+reg134; reg135=reg56-reg135; reg124=pow(reg132,2); reg136=reg107*reg129; T reg138=pow(reg131,2);
    T reg139=0.048208377815511963759*elem.pos(1)[2]; T reg140=0.048208377815511963759*elem.pos(0)[1]; T reg141=0.084730493093977855013*elem.pos(1)[0]; T reg142=0.048208377815511963759*elem.pos(0)[0]; T reg143=0.084730493093977855013*elem.pos(0)[2];
    T reg144=0.048208377815511963759*elem.pos(1)[0]; T reg145=0.084730493093977855013*elem.pos(1)[1]; T reg146=0.084730493093977855013*elem.pos(0)[0]; T reg147=0.084730493093977855013*elem.pos(0)[1]; reg138=reg134+reg138;
    reg118=reg118/reg133; reg112=reg112/reg71; reg109=reg109/reg71; reg134=pow(reg99,2); T reg148=pow(reg126,2);
    reg136=reg81-reg136; reg119=reg119/reg133; T reg149=0.048208377815511963759*elem.pos(1)[1]; T reg150=pow(reg135,2); reg127=pow(reg127,0.5);
    reg137=reg124+reg137; reg124=0.048208377815511963759*elem.pos(0)[2]; T reg151=0.084730493093977855013*elem.pos(1)[2]; reg37=reg37*reg119; T reg152=reg142+reg141;
    reg80=reg31*reg80; reg84=reg30*reg84; T reg153=0.048208377815511963759*elem.pos(2)[0]; T reg154=reg146+reg144; T reg155=reg145+reg140;
    reg34=reg34*reg118; reg133=reg122/reg133; reg94=reg22*reg94; reg96=reg19*reg96; reg119=reg22*reg119;
    reg22=0.048208377815511963759*elem.pos(2)[1]; reg122=reg149+reg147; reg118=reg19*reg118; reg148=reg134+reg148; reg19=pow(reg136,2);
    reg150=reg137+reg150; reg134=0.048208377815511963759*elem.pos(2)[2]; reg137=reg139+reg143; reg31=reg31*reg112; reg30=reg30*reg109;
    reg123=reg123/reg127; reg71=reg120/reg71; reg138=pow(reg138,0.5); reg120=reg151+reg124; reg97=reg97/reg127;
    reg112=reg74*reg112; reg109=reg66*reg109; reg19=reg148+reg19; reg66=0.19283351126204785504*elem.pos(3)[1]; reg150=pow(reg150,0.5);
    reg25=reg25*reg123; reg28=reg28*reg97; reg74=reg134+reg120; reg125=reg125/reg138; reg128=reg128/reg138;
    reg148=reg52*reg133; T reg156=reg122+reg22; T reg157=reg144+reg142; T reg158=0.084730493093977855013*elem.pos(2)[0]; T reg159=0.074803807748196670769*elem.pos(1)[0];
    reg34=reg37+reg34; reg133=reg54*reg133; reg37=reg18*reg71; reg31=reg30+reg31; reg30=0.51763234198767131696*elem.pos(0)[2];
    reg71=reg82*reg71; reg112=reg109+reg112; reg118=reg119+reg118; reg54=0.51763234198767131696*elem.pos(0)[0]; reg82=0.074803807748196670769*elem.pos(1)[2];
    reg109=0.084730493093977855013*elem.pos(2)[2]; reg119=reg139+reg124; reg123=reg51*reg123; reg97=reg11*reg97; reg127=reg108/reg127;
    reg108=reg154+reg153; T reg160=0.19283351126204785504*elem.pos(3)[0]; reg53=reg11*reg53; reg11=reg153+reg152; reg102=reg51*reg102;
    reg51=reg149+reg140; T reg161=0.084730493093977855013*elem.pos(2)[1]; T reg162=reg22+reg155; reg80=reg84+reg80; reg70=reg18*reg70;
    reg18=0.19283351126204785504*elem.pos(3)[2]; reg73=reg52*reg73; reg52=0.51763234198767131696*elem.pos(0)[1]; reg84=reg137+reg134; reg96=reg94+reg96;
    reg94=0.074803807748196670769*elem.pos(1)[1]; T reg163=reg119+reg109; T reg164=0.074803807748196670763*elem.pos(0)[2]; T reg165=0.074803807748196670769*elem.pos(2)[0]; reg54=reg54-reg159;
    T reg166=0.79548022620090607244*elem.pos(4)[0]; T reg167=reg3*reg127; reg123=reg97+reg123; reg97=reg160-reg108; reg52=reg52-reg94;
    reg114=reg50*reg114; T reg168=0.79548022620090607244*elem.pos(3)[2]; reg115=reg48*reg115; T reg169=0.19283351126204785504*elem.pos(4)[2]; T reg170=0.51763234198767131696*elem.pos(1)[2];
    T reg171=reg51+reg161; reg102=reg53+reg102; reg87=reg3*reg87; reg3=0.51763234198767131696*elem.pos(1)[0]; reg53=0.074803807748196670763*elem.pos(0)[1];
    reg71=reg112+reg71; reg112=0.51763234198767131696*elem.pos(1)[1]; reg70=reg80+reg70; reg80=0.074803807748196670769*elem.pos(2)[1]; reg133=reg34+reg133;
    reg30=reg30-reg82; reg34=0.074803807748196670769*elem.pos(2)[2]; reg73=reg96+reg73; reg48=reg48*reg128; reg96=0.79548022620090607244*elem.pos(3)[0];
    reg50=reg50*reg125; T reg172=reg157+reg158; T reg173=0.79548022620090607244*elem.pos(4)[1]; T reg174=reg18-reg84; T reg175=reg66-reg156;
    T reg176=0.79548022620090607244*elem.pos(4)[2]; reg138=reg131/reg138; reg148=reg118+reg148; reg128=reg110*reg128; reg125=reg104*reg125;
    reg66=reg66-reg162; reg104=0.19283351126204785504*elem.pos(4)[1]; reg37=reg31+reg37; reg18=reg18-reg74; reg127=reg40*reg127;
    reg31=0.074803807748196670763*elem.pos(0)[0]; reg19=pow(reg19,0.5); reg130=reg130/reg150; reg25=reg28+reg25; reg132=reg132/reg150;
    reg28=0.79548022620090607244*elem.pos(3)[1]; reg40=0.19283351126204785504*elem.pos(4)[0]; reg160=reg160-reg11; reg110=0.29921523099278668308*elem.pos(3)[2]; reg118=0.19283351126204785504*elem.pos(5)[1];
    reg131=0.074803807748196670769*elem.pos(0)[2]; reg170=reg170-reg164; reg173=reg175+reg173; reg18=reg18+reg169; reg175=0.79548022620090607244*elem.pos(5)[2];
    reg30=reg30-reg34; T reg177=0.79548022620090607244*elem.pos(5)[1]; reg66=reg66+reg104; reg99=reg99/reg19; reg126=reg126/reg19;
    T reg178=0.29921523099278668308*elem.pos(3)[1]; reg112=reg112-reg53; reg52=reg52-reg80; reg176=reg174+reg176; reg168=reg168-reg163;
    reg28=reg28-reg171; reg174=0.074803807748196670769*elem.pos(0)[1]; T reg179=0.19283351126204785504*elem.pos(5)[2]; reg87=reg102+reg87; reg102=0.074803807748196670769*elem.pos(0)[0];
    reg116=reg116*reg138; reg96=reg96-reg172; reg92=reg57*reg92; T reg180=reg59*reg130; T reg181=reg58*reg132;
    reg3=reg3-reg31; reg37=reg98*reg37; reg150=reg135/reg150; reg148=reg117*reg148; reg132=reg78*reg132;
    reg130=reg79*reg130; reg167=reg123+reg167; reg78=0.29921523099278668308*elem.pos(3)[0]; reg128=reg125+reg128; reg71=reg70*reg71;
    reg115=reg114+reg115; reg127=reg25+reg127; reg47=reg58*reg47; reg133=reg73*reg133; reg160=reg160+reg40;
    reg49=reg59*reg49; reg166=reg97+reg166; reg25=0.79548022620090607244*elem.pos(5)[0]; reg54=reg54-reg165; reg58=0.19283351126204785504*elem.pos(5)[0];
    reg138=reg57*reg138; reg48=reg50+reg48; reg50=0.29921523099278668305*elem.pos(3)[0]; reg168=reg169+reg168; reg52=reg178+reg52;
    reg57=0.033544811523148658458*elem.pos(4)[1]; reg30=reg110+reg30; reg37=reg71-reg37; reg167=reg61*reg167; reg59=0.033544811523148658458*elem.pos(4)[2];
    reg166=reg166+reg58; reg177=reg66+reg177; reg127=reg87*reg127; reg148=reg133-reg148; reg92=reg115+reg92;
    reg49=reg47+reg49; reg96=reg40+reg96; reg173=reg173+reg118; reg175=reg18+reg175; reg28=reg104+reg28;
    reg25=reg160+reg25; reg88=reg76*reg88; reg18=reg82+reg131; reg40=0.51763234198767131696*elem.pos(2)[0]; reg47=reg159+reg102;
    reg61=0.51763234198767131696*elem.pos(2)[2]; reg116=reg128+reg116; reg138=reg48+reg138; reg112=reg112-reg80; reg76=reg76*reg150;
    reg180=reg181+reg180; reg170=reg170-reg34; reg150=reg56*reg150; reg91=reg91*reg99; reg130=reg132+reg130;
    reg90=reg90*reg126; reg3=reg3-reg165; reg19=reg136/reg19; reg48=0.29921523099278668305*elem.pos(3)[1]; reg78=reg54+reg78;
    reg99=reg32*reg99; reg126=reg64*reg126; reg106=reg32*reg106; reg103=reg64*reg103; reg176=reg176+reg179;
    reg32=0.033544811523148658458*elem.pos(4)[0]; reg54=0.29921523099278668305*elem.pos(3)[2]; reg56=reg94+reg174; reg64=0.51763234198767131696*elem.pos(2)[1]; reg66=0.033544811523148658455*elem.pos(3)[1];
    reg138=reg55*reg138; reg64=reg64-reg56; reg116=reg92*reg116; reg55=0.29921523099278668308*elem.pos(4)[1]; reg28=reg118+reg28;
    reg112=reg48+reg112; reg166=reg166*reg37; reg48=0.29921523099278668308*elem.pos(4)[0]; reg50=reg3+reg50; reg176=reg37*reg176;
    reg3=0.29921523099278668308*elem.pos(5)[1]; reg57=reg52+reg57; reg107=reg1*reg107; reg103=reg106+reg103; reg61=reg61-reg18;
    reg52=0.033544811523148658455*elem.pos(3)[0]; reg40=reg40-reg47; reg70=0.033544811523148658455*elem.pos(3)[2]; reg71=0.29921523099278668308*elem.pos(4)[2]; reg170=reg54+reg170;
    reg76=reg180+reg76; reg150=reg130+reg150; reg90=reg91+reg90; reg81=reg81*reg19; reg126=reg99+reg126;
    reg19=reg1*reg19; reg1=0.29921523099278668308*elem.pos(5)[2]; reg177=reg148*reg177; reg59=reg30+reg59; reg32=reg78+reg32;
    reg30=0.29921523099278668308*elem.pos(5)[0]; reg88=reg49+reg88; reg168=reg179+reg168; reg96=reg58+reg96; reg173=reg37*reg173;
    reg175=reg148*reg175; reg167=reg127-reg167; reg25=reg25*reg148; reg61=reg70+reg61; reg138=reg116-reg138;
    reg175=0.111690794839005*reg175; reg49=0.033544811523148658451*elem.pos(5)[2]; reg170=reg170+reg71; reg96=reg96*reg167; reg166=0.111690794839005*reg166;
    reg168=reg167*reg168; reg32=reg32+reg30; reg59=reg59+reg1; reg176=0.111690794839005*reg176; reg25=0.111690794839005*reg25;
    reg173=0.111690794839005*reg173; reg177=0.111690794839005*reg177; reg37=0.111690794839005*reg37; reg28=reg167*reg28; reg54=0.033544811523148658451*elem.pos(5)[0];
    reg50=reg50+reg48; reg57=reg57+reg3; reg148=0.111690794839005*reg148; reg112=reg112+reg55; reg58=0.033544811523148658451*elem.pos(5)[1];
    reg19=reg126+reg19; reg64=reg66+reg64; reg107=reg103+reg107; reg52=reg40+reg52; reg76=reg121*reg76;
    reg150=reg88*reg150; reg81=reg90+reg81; reg59=reg138*reg59; reg19=reg129*reg19; reg148=reg37+reg148;
    reg76=reg150-reg76; reg49=reg170+reg49; reg167=0.111690794839005*reg167; reg96=0.111690794839005*reg96; reg168=0.111690794839005*reg168;
    reg52=reg48+reg52; reg61=reg71+reg61; reg175=reg176+reg175; reg81=reg107*reg81; reg25=reg166+reg25;
    reg177=reg173+reg177; reg58=reg112+reg58; reg64=reg55+reg64; reg32=reg32*reg138; reg28=0.111690794839005*reg28;
    reg57=reg138*reg57; reg54=reg50+reg54; reg58=reg76*reg58; reg32=0.054975871827660999999*reg32; reg59=0.054975871827660999999*reg59;
    reg19=reg81-reg19; reg54=reg54*reg76; reg49=reg76*reg49; reg57=0.054975871827660999999*reg57; reg167=reg148+reg167;
    reg138=0.054975871827660999999*reg138; reg96=reg25+reg96; reg28=reg177+reg28; reg168=reg175+reg168; reg52=reg30+reg52;
    reg64=reg3+reg64; reg61=reg1+reg61; reg54=0.054975871827660999999*reg54; reg49=0.054975871827660999999*reg49; reg64=reg19*reg64;
    reg58=0.054975871827660999999*reg58; reg61=reg19*reg61; reg32=reg96+reg32; reg59=reg168+reg59; reg57=reg28+reg57;
    reg52=reg52*reg19; reg76=0.054975871827660999999*reg76; reg138=reg167+reg138; reg61=0.054975871827660999999*reg61; reg19=0.054975871827660999999*reg19;
    reg76=reg138+reg76; reg64=0.054975871827660999999*reg64; reg54=reg32+reg54; reg49=reg59+reg49; reg52=0.054975871827660999999*reg52;
    reg58=reg57+reg58; reg64=reg58+reg64; reg52=reg54+reg52; reg19=reg76+reg19; reg61=reg49+reg61;
    res[2]=reg61/reg19; res[0]=reg52/reg19; res[1]=reg64/reg19;

    return res;
}
}
#endif // LMT_TRIANGLE_6
