#ifndef LMT_TRIANGLE_6
#define LMT_TRIANGLE_6
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Triangle_6 &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 19, 38, 57, 76, 95, 117, 154, 191, 228, }; // fonction de lordre du poly
    static const double values[] = {
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.0,
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.0,
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.0,
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.0,
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.0,
        0.1125,0.333333333333,0.333333333333,
        0.0661970763943,0.47014206410511505396,0.47014206410511505396,
        0.0661970763943,0.47014206410511505396,0.059715871789769892075,
        0.0661970763943,0.059715871789769892075,0.47014206410511505396,
        0.0629695902724,0.10128650732345637064,0.10128650732345637064,
        0.0629695902724,0.10128650732345637064,0.79742698535308725871,
        0.0629695902724,0.79742698535308725871,0.10128650732345637064,
        0.0,
        0.025422453185102999999,0.063089014491501999997,0.063089014491501999997,
        0.025422453185102999999,0.063089014491501999997,0.87382197101699600001,
        0.025422453185102999999,0.87382197101699600001,0.063089014491501999997,
        0.058393137863188999999,0.24928674517091000001,0.24928674517091000001,
        0.058393137863188999999,0.24928674517091000001,0.50142650965817999999,
        0.058393137863188999999,0.50142650965817999999,0.24928674517091000001,
        0.041425537809187,0.053145049844815999999,0.31035245103378499999,
        0.041425537809187,0.31035245103378499999,0.053145049844815999999,
        0.041425537809187,0.31035245103378499999,0.63650249912139900002,
        0.041425537809187,0.053145049844815999999,0.63650249912139900002,
        0.041425537809187,0.63650249912139900002,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.053145049844815999999,
        0.0,
        0.025422453185102999999,0.063089014491501999997,0.063089014491501999997,
        0.025422453185102999999,0.063089014491501999997,0.87382197101699600001,
        0.025422453185102999999,0.87382197101699600001,0.063089014491501999997,
        0.058393137863188999999,0.24928674517091000001,0.24928674517091000001,
        0.058393137863188999999,0.24928674517091000001,0.50142650965817999999,
        0.058393137863188999999,0.50142650965817999999,0.24928674517091000001,
        0.041425537809187,0.053145049844815999999,0.31035245103378499999,
        0.041425537809187,0.31035245103378499999,0.053145049844815999999,
        0.041425537809187,0.31035245103378499999,0.63650249912139900002,
        0.041425537809187,0.053145049844815999999,0.63650249912139900002,
        0.041425537809187,0.63650249912139900002,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.053145049844815999999,
        0.0,
        0.025422453185102999999,0.063089014491501999997,0.063089014491501999997,
        0.025422453185102999999,0.063089014491501999997,0.87382197101699600001,
        0.025422453185102999999,0.87382197101699600001,0.063089014491501999997,
        0.058393137863188999999,0.24928674517091000001,0.24928674517091000001,
        0.058393137863188999999,0.24928674517091000001,0.50142650965817999999,
        0.058393137863188999999,0.50142650965817999999,0.24928674517091000001,
        0.041425537809187,0.053145049844815999999,0.31035245103378499999,
        0.041425537809187,0.31035245103378499999,0.053145049844815999999,
        0.041425537809187,0.31035245103378499999,0.63650249912139900002,
        0.041425537809187,0.053145049844815999999,0.63650249912139900002,
        0.041425537809187,0.63650249912139900002,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.053145049844815999999,
        0.0,
        0.025422453185102999999,0.063089014491501999997,0.063089014491501999997,
        0.025422453185102999999,0.063089014491501999997,0.87382197101699600001,
        0.025422453185102999999,0.87382197101699600001,0.063089014491501999997,
        0.058393137863188999999,0.24928674517091000001,0.24928674517091000001,
        0.058393137863188999999,0.24928674517091000001,0.50142650965817999999,
        0.058393137863188999999,0.50142650965817999999,0.24928674517091000001,
        0.041425537809187,0.053145049844815999999,0.31035245103378499999,
        0.041425537809187,0.31035245103378499999,0.053145049844815999999,
        0.041425537809187,0.31035245103378499999,0.63650249912139900002,
        0.041425537809187,0.053145049844815999999,0.63650249912139900002,
        0.041425537809187,0.63650249912139900002,0.31035245103378499999,
        0.041425537809187,0.63650249912139900002,0.053145049844815999999,
        0.0,
    };
    return values + offset[order];
}
template<class TNode> void permutation_if_jac_neg(const Triangle_6 &elem,TNode **nodes) {

    if ( nodes[0]->pos.size() != 2 )
        return;

    typedef typename TNode::T T;
    T reg0=nodes[0]->pos[0]+nodes[2]->pos[0]; T reg1=nodes[0]->pos[1]+nodes[1]->pos[1]; T reg2=2*nodes[3]->pos[1]; T reg3=nodes[0]->pos[1]+nodes[2]->pos[1]; T reg4=2*nodes[3]->pos[0];
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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*reg0; T reg2=2*var_inter[1]; T reg3=2*var_inter[0];
    T reg4=reg1-1; T reg5=reg2-1; T reg6=reg3-1; reg2=reg2+reg5; reg3=reg3+reg6;
    reg1=reg1+reg4; T reg7=4*reg0; T reg8=4*var_inter[0]; T reg9=pos_nodes[2][0]*reg2; reg4=reg4*reg0;
    T reg10=pos_nodes[2][1]*reg2; T reg11=pos_nodes[0][0]*reg1; T reg12=pos_nodes[1][0]*reg3; T reg13=reg7-reg8; T reg14=pos_nodes[0][1]*reg1;
    T reg15=pos_nodes[1][1]*reg3; reg6=reg6*var_inter[0]; reg5=var_inter[1]*reg5; reg15=reg15-reg14; reg14=reg10-reg14;
    reg10=pos_nodes[3][1]*reg8; T reg16=reg6*pos_nodes[1][0]; T reg17=pos_nodes[0][0]*reg4; T reg18=pos_nodes[3][0]*reg8; T reg19=pos_nodes[3][1]*reg13;
    reg9=reg9-reg11; T reg20=reg4*pos_nodes[0][1]; T reg21=4*var_inter[1]; T reg22=pos_nodes[1][1]*reg6; reg11=reg12-reg11;
    reg12=pos_nodes[3][0]*reg13; T reg23=var_inter[0]*reg7; T reg24=pos_nodes[2][1]*reg5; reg19=reg15+reg19; reg15=pos_nodes[4][1]*reg21;
    T reg25=pos_nodes[4][1]*reg8; reg12=reg11+reg12; reg11=pos_nodes[4][0]*reg21; T reg26=pos_nodes[2][0]*reg5; reg16=reg17+reg16;
    reg22=reg20+reg22; reg10=reg14-reg10; reg14=pos_nodes[4][0]*reg8; reg18=reg9-reg18; reg7=reg7-reg21;
    reg9=reg21*pos_nodes[5][1]; reg15=reg19+reg15; reg24=reg22+reg24; reg10=reg25+reg10; reg17=pos_nodes[5][1]*reg7;
    reg19=pos_nodes[3][1]*reg23; reg11=reg12+reg11; reg12=reg21*pos_nodes[5][0]; reg14=reg18+reg14; reg18=pos_nodes[5][0]*reg7;
    reg26=reg16+reg26; reg16=pos_nodes[3][0]*reg23; reg20=var_inter[1]*reg8; reg22=pos_nodes[4][0]*reg20; reg16=reg26+reg16;
    reg9=reg15-reg9; reg15=pos_nodes[4][1]*reg20; reg18=reg14+reg18; reg19=reg24+reg19; reg14=reg0*reg21;
    reg17=reg10+reg17; reg12=reg11-reg12; reg15=reg19+reg15; reg10=reg14*pos_nodes[5][1]; reg11=reg18*reg9;
    reg19=reg14*pos_nodes[5][0]; reg22=reg16+reg22; reg16=reg12*reg17; reg10=reg15+reg10; reg11=reg16-reg11;
    reg19=reg22+reg19; reg10=pos[1]-reg10; reg15=reg17/reg11; reg19=pos[0]-reg19; reg22=reg9/reg11;
    reg24=reg18/reg11; reg11=reg12/reg11; reg15=reg19*reg15; reg24=reg10*reg24; reg22=reg19*reg22;
    reg11=reg10*reg11; var_inter[0]=reg15-reg24; var_inter[1]=reg11-reg22;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Triangle_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*var_inter[1]; T reg3=2*reg0;
    T reg4=reg2-1; T reg5=reg1-1; T reg6=reg3-1; reg1=reg1+reg5; reg3=reg6+reg3;
    reg2=reg2+reg4; T reg7=4*reg0; T reg8=4*var_inter[0]; T reg9=pos_nodes[2][1]*reg2; reg6=reg6*reg0;
    T reg10=pos_nodes[1][1]*reg1; T reg11=pos_nodes[0][1]*reg3; reg5=reg5*var_inter[0]; T reg12=pos_nodes[2][0]*reg2; T reg13=pos_nodes[0][0]*reg3;
    T reg14=pos_nodes[1][0]*reg1; T reg15=reg7-reg8; reg12=reg12-reg13; T reg16=reg6*pos_nodes[0][1]; T reg17=reg8*pos_nodes[3][0];
    T reg18=reg6*pos_nodes[0][0]; T reg19=pos_nodes[1][0]*reg5; T reg20=reg8*pos_nodes[3][1]; reg9=reg9-reg11; T reg21=pos_nodes[3][1]*reg15;
    reg11=reg10-reg11; reg10=4*var_inter[1]; T reg22=pos_nodes[3][0]*reg15; reg13=reg14-reg13; reg4=reg4*var_inter[1];
    reg14=pos_nodes[1][1]*reg5; reg21=reg11+reg21; reg11=pos_nodes[4][1]*reg10; T reg23=reg7*var_inter[0]; reg19=reg18+reg19;
    reg14=reg16+reg14; reg16=reg4*pos_nodes[2][0]; reg20=reg9-reg20; reg9=reg8*pos_nodes[4][1]; reg18=reg8*pos_nodes[4][0];
    reg17=reg12-reg17; reg7=reg7-reg10; reg12=reg4*pos_nodes[2][1]; reg22=reg13+reg22; reg13=pos_nodes[4][0]*reg10;
    reg9=reg20+reg9; reg20=reg10*pos_nodes[5][1]; reg11=reg21+reg11; reg21=pos_nodes[5][1]*reg7; reg14=reg12+reg14;
    reg12=reg23*pos_nodes[3][1]; T reg24=pos_nodes[5][0]*reg7; reg19=reg16+reg19; reg16=reg23*pos_nodes[3][0]; reg18=reg17+reg18;
    reg17=reg10*pos_nodes[5][0]; reg13=reg22+reg13; reg22=reg8*var_inter[1]; T reg25=reg0*reg10; reg20=reg11-reg20;
    reg11=pos_nodes[4][0]*reg22; reg21=reg9+reg21; reg17=reg13-reg17; reg16=reg19+reg16; reg12=reg14+reg12;
    reg9=pos_nodes[4][1]*reg22; reg24=reg18+reg24; reg9=reg12+reg9; reg12=reg25*pos_nodes[5][1]; reg13=reg24*reg20;
    reg14=reg17*reg21; reg11=reg16+reg11; reg16=reg25*pos_nodes[5][0]; reg12=reg9+reg12; reg13=reg14-reg13;
    reg16=reg11+reg16; reg12=pos[1]-reg12; reg9=reg17/reg13; reg11=reg24/reg13; reg18=reg20/reg13;
    reg13=reg21/reg13; reg16=pos[0]-reg16; reg13=reg16*reg13; reg11=reg11*reg12; reg18=reg16*reg18;
    reg9=reg12*reg9; var_inter[0]+=reg13-reg11; var_inter[1]+=reg9-reg18;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[0]; T reg2=2*reg0; reg1=reg1-1;
    T reg3=2*var_inter[1]; reg2=reg2-1; reg1=var_inter[0]*reg1; reg2=reg0*reg2; reg3=reg3-1;
    reg1=val[1]*reg1; reg3=var_inter[1]*reg3; reg2=val[0]*reg2; T reg4=4*reg0; reg3=val[2]*reg3;
    reg4=var_inter[0]*reg4; reg1=reg2+reg1; reg2=4*var_inter[0]; T reg5=4*var_inter[1]; reg2=var_inter[1]*reg2;
    reg4=val[3]*reg4; reg3=reg1+reg3; reg5=reg0*reg5; reg2=val[4]*reg2; reg4=reg3+reg4;
    reg2=reg4+reg2; reg5=val[5]*reg5; res=reg2+reg5;

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    reg1=var_inter[1]*val[2]; res=reg2+reg1;

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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*var_inter[1]; T reg2=2*var_inter[0]; T reg3=2*reg0;
    reg2=reg2-1; T reg4=4*var_inter[1]; reg3=reg3-1; reg1=reg1-1; T reg5=4*reg0;
    T reg6=4*var_inter[0]; reg4=reg0*reg4; res[5]=reg4; reg6=var_inter[1]*reg6; res[4]=reg6;
    reg5=var_inter[0]*reg5; res[3]=reg5; reg1=var_inter[1]*reg1; res[2]=reg1; reg2=var_inter[0]*reg2;
    res[1]=reg2; reg3=reg0*reg3; res[0]=reg3;

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

}
#endif // LMT_TRIANGLE_6
