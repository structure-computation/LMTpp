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
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*reg0; T reg2=2*var_inter[0]; T reg3=reg1-1;
    T reg4=reg2-1; T reg5=2*var_inter[1]; T reg6=reg0*reg3; T reg7=reg4*var_inter[0]; T reg8=reg5-1;
    T reg9=reg7*pos_nodes[1][0]; T reg10=reg6*pos_nodes[0][0]; reg3=reg1+reg3; reg4=reg2+reg4; reg1=reg8*var_inter[1];
    reg2=4*reg0; T reg11=reg6*pos_nodes[0][1]; T reg12=reg7*pos_nodes[1][1]; reg8=reg5+reg8; reg5=4*var_inter[0];
    T reg13=pos_nodes[2][0]*reg8; T reg14=pos_nodes[0][0]*reg3; reg9=reg10+reg9; reg10=reg1*pos_nodes[2][0]; T reg15=pos_nodes[1][1]*reg4;
    T reg16=pos_nodes[0][1]*reg3; T reg17=pos_nodes[2][1]*reg8; reg12=reg11+reg12; reg11=reg1*pos_nodes[2][1]; T reg18=reg2-reg5;
    T reg19=reg2*var_inter[0]; T reg20=pos_nodes[1][0]*reg4; T reg21=reg5*var_inter[1]; T reg22=4*var_inter[1]; T reg23=reg5*pos_nodes[3][1];
    reg17=reg17-reg16; reg11=reg12+reg11; reg12=reg19*pos_nodes[3][1]; T reg24=pos_nodes[3][1]*reg18; reg16=reg15-reg16;
    reg15=reg19*pos_nodes[3][0]; reg10=reg9+reg10; reg9=pos_nodes[3][0]*reg18; reg20=reg20-reg14; reg14=reg13-reg14;
    reg13=reg5*pos_nodes[3][0]; T reg25=reg22*pos_nodes[4][0]; reg0=reg0*reg22; reg9=reg20+reg9; reg20=reg5*pos_nodes[4][1];
    reg23=reg17-reg23; reg2=reg2-reg22; reg17=reg22*pos_nodes[4][1]; reg24=reg16+reg24; reg12=reg11+reg12;
    reg13=reg14-reg13; reg11=reg21*pos_nodes[4][1]; reg14=reg21*pos_nodes[4][0]; reg15=reg10+reg15; reg10=reg5*pos_nodes[4][0];
    reg25=reg9+reg25; reg9=reg0*pos_nodes[5][1]; reg16=pos_nodes[5][1]*reg2; reg20=reg23+reg20; reg23=pos_nodes[5][0]*reg2;
    T reg26=reg22*pos_nodes[5][0]; reg10=reg13+reg10; reg13=reg22*pos_nodes[5][1]; reg17=reg24+reg17; reg14=reg15+reg14;
    reg15=reg0*pos_nodes[5][0]; reg11=reg12+reg11; reg9=reg11+reg9; reg16=reg20+reg16; reg26=reg25-reg26;
    reg13=reg17-reg13; reg15=reg14+reg15; reg23=reg10+reg23; reg15=pos[0]-reg15; reg9=pos[1]-reg9;
<<<<<<< HEAD:include/mesh/element_Triangle_6.h
    reg10=var_inter[0]*reg26; reg11=reg23*reg13; reg12=var_inter[0]*reg13; reg14=reg26*reg16; reg11=reg14-reg11;
    reg12=reg9+reg12; reg9=var_inter[1]*reg16; reg10=reg15+reg10; reg15=var_inter[1]*reg23; reg10=reg15+reg10;
    reg12=reg9+reg12; reg9=reg16/reg11; reg15=reg13/reg11; reg17=reg23/reg11; reg11=reg26/reg11;
    reg9=reg10*reg9; reg17=reg12*reg17; reg15=reg10*reg15; reg11=reg12*reg11; var_inter[0]=reg9-reg17;
    var_inter[1]=reg11-reg15;
=======
    reg10=reg26*reg16; reg11=var_inter[0]*reg26; reg12=reg23*reg13; reg14=var_inter[0]*reg13; reg12=reg10-reg12;
    reg14=reg9+reg14; reg9=var_inter[1]*reg16; reg11=reg15+reg11; reg15=var_inter[1]*reg23; reg11=reg15+reg11;
    reg14=reg9+reg14; reg9=reg16/reg12; reg15=reg13/reg12; reg17=reg23/reg12; reg12=reg26/reg12;
    reg9=reg11*reg9; reg17=reg14*reg17; reg15=reg11*reg15; reg12=reg14*reg12; var_inter[0]=reg9-reg17;
    var_inter[1]=reg12-reg15;
>>>>>>> 512dc2050926bfccc64f86a01cb2ce23c8050af9:include/mesh/element_Triangle_6.h

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Triangle_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=2*reg0; T reg2=2*var_inter[0]; T reg3=reg1-1;
    T reg4=reg2-1; T reg5=2*var_inter[1]; T reg6=reg5-1; T reg7=reg4*var_inter[0]; T reg8=reg0*reg3;
<<<<<<< HEAD:include/mesh/element_Triangle_6.h
    reg4=reg2+reg4; reg3=reg1+reg3; reg1=pos_nodes[0][0]*reg8; reg2=reg7*pos_nodes[1][0]; reg5=reg5+reg6;
=======
    reg4=reg2+reg4; reg3=reg1+reg3; reg5=reg5+reg6; reg1=pos_nodes[0][0]*reg8; reg2=reg7*pos_nodes[1][0];
>>>>>>> 512dc2050926bfccc64f86a01cb2ce23c8050af9:include/mesh/element_Triangle_6.h
    T reg9=reg8*pos_nodes[0][1]; T reg10=reg7*pos_nodes[1][1]; T reg11=4*var_inter[0]; T reg12=4*reg0; reg6=reg6*var_inter[1];
    T reg13=pos_nodes[2][1]*reg5; T reg14=pos_nodes[0][1]*reg3; T reg15=pos_nodes[1][1]*reg4; T reg16=reg6*pos_nodes[2][0]; reg2=reg1+reg2;
<<<<<<< HEAD:include/mesh/element_Triangle_6.h
    reg10=reg9+reg10; reg1=pos_nodes[2][0]*reg5; reg9=reg6*pos_nodes[2][1]; T reg17=pos_nodes[0][0]*reg3; T reg18=reg12-reg11;
    T reg19=reg12*var_inter[0]; T reg20=pos_nodes[1][0]*reg4; T reg21=reg11*var_inter[1]; T reg22=4*var_inter[1]; T reg23=reg11*pos_nodes[3][1];
    reg13=reg13-reg14; reg9=reg10+reg9; reg10=reg19*pos_nodes[3][1]; T reg24=pos_nodes[3][1]*reg18; reg14=reg15-reg14;
    reg15=reg19*pos_nodes[3][0]; reg16=reg2+reg16; reg2=pos_nodes[3][0]*reg18; reg20=reg20-reg17; reg17=reg1-reg17;
    reg1=reg11*pos_nodes[3][0]; T reg25=reg22*pos_nodes[4][0]; reg0=reg0*reg22; reg2=reg20+reg2; reg20=reg11*pos_nodes[4][1];
    reg23=reg13-reg23; reg12=reg12-reg22; reg13=reg22*pos_nodes[4][1]; reg24=reg14+reg24; reg10=reg9+reg10;
    reg1=reg17-reg1; reg9=reg21*pos_nodes[4][1]; reg14=reg21*pos_nodes[4][0]; reg15=reg16+reg15; reg16=reg11*pos_nodes[4][0];
    reg25=reg2+reg25; reg2=reg0*pos_nodes[5][1]; reg17=pos_nodes[5][1]*reg12; reg20=reg23+reg20; reg23=pos_nodes[5][0]*reg12;
    T reg26=reg22*pos_nodes[5][0]; reg16=reg1+reg16; reg1=reg22*pos_nodes[5][1]; reg13=reg24+reg13; reg14=reg15+reg14;
    reg15=reg0*pos_nodes[5][0]; reg9=reg10+reg9; reg2=reg9+reg2; reg17=reg20+reg17; reg26=reg25-reg26;
    reg1=reg13-reg1; reg15=reg14+reg15; reg23=reg16+reg23; reg15=pos[0]-reg15; reg2=pos[1]-reg2;
    reg9=var_inter[0]*reg26; reg10=reg23*reg1; reg13=var_inter[0]*reg1; reg14=reg26*reg17; reg10=reg14-reg10;
    reg13=reg2+reg13; reg2=var_inter[1]*reg17; reg9=reg15+reg9; reg15=var_inter[1]*reg23; reg9=reg15+reg9;
    reg13=reg2+reg13; reg2=reg17/reg10; reg15=reg1/reg10; reg16=reg23/reg10; reg10=reg26/reg10;
    reg2=reg9*reg2; reg16=reg13*reg16; reg15=reg9*reg15; reg10=reg13*reg10; var_inter[0]+=reg2-reg16;
    var_inter[1]+=reg10-reg15;
=======
    reg10=reg9+reg10; reg1=pos_nodes[2][0]*reg5; reg9=reg6*pos_nodes[2][1]; T reg17=pos_nodes[0][0]*reg3; T reg18=pos_nodes[1][0]*reg4;
    T reg19=reg12-reg11; T reg20=reg12*var_inter[0]; reg16=reg2+reg16; reg2=reg20*pos_nodes[3][0]; reg15=reg15-reg14;
    T reg21=pos_nodes[3][1]*reg19; reg14=reg13-reg14; reg13=reg11*pos_nodes[3][1]; T reg22=4*var_inter[1]; T reg23=reg11*var_inter[1];
    reg9=reg10+reg9; reg10=reg20*pos_nodes[3][1]; T reg24=pos_nodes[3][0]*reg19; reg18=reg18-reg17; reg17=reg1-reg17;
    reg1=reg11*pos_nodes[3][0]; T reg25=reg22*pos_nodes[4][0]; reg0=reg0*reg22; reg24=reg18+reg24; reg18=reg11*pos_nodes[4][1];
    reg13=reg14-reg13; reg12=reg12-reg22; reg14=reg22*pos_nodes[4][1]; reg21=reg15+reg21; reg10=reg9+reg10;
    reg1=reg17-reg1; reg9=reg23*pos_nodes[4][1]; reg15=reg23*pos_nodes[4][0]; reg2=reg16+reg2; reg16=reg11*pos_nodes[4][0];
    reg25=reg24+reg25; reg17=reg0*pos_nodes[5][1]; reg24=pos_nodes[5][1]*reg12; reg18=reg13+reg18; reg13=pos_nodes[5][0]*reg12;
    T reg26=reg22*pos_nodes[5][0]; reg16=reg1+reg16; reg1=reg22*pos_nodes[5][1]; reg14=reg21+reg14; reg15=reg2+reg15;
    reg2=reg0*pos_nodes[5][0]; reg9=reg10+reg9; reg17=reg9+reg17; reg24=reg18+reg24; reg26=reg25-reg26;
    reg1=reg14-reg1; reg2=reg15+reg2; reg13=reg16+reg13; reg2=pos[0]-reg2; reg17=pos[1]-reg17;
    reg9=var_inter[0]*reg26; reg10=reg13*reg1; reg14=var_inter[0]*reg1; reg15=reg26*reg24; reg10=reg15-reg10;
    reg14=reg17+reg14; reg16=var_inter[1]*reg24; reg9=reg2+reg9; reg2=var_inter[1]*reg13; reg9=reg2+reg9;
    reg14=reg16+reg14; reg2=reg24/reg10; reg16=reg1/reg10; reg17=reg13/reg10; reg10=reg26/reg10;
    reg2=reg9*reg2; reg17=reg14*reg17; reg16=reg9*reg16; reg10=reg14*reg10; var_inter[0]+=reg2-reg17;
    var_inter[1]+=reg10-reg16;
>>>>>>> 512dc2050926bfccc64f86a01cb2ce23c8050af9:include/mesh/element_Triangle_6.h

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
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
    reg2=reg2-1; T reg3=2*var_inter[1]; reg2=reg0*reg2; reg1=var_inter[0]*reg1; reg3=reg3-1;
    reg1=val[1]*reg1; reg3=var_inter[1]*reg3; reg2=val[0]*reg2; T reg4=4*reg0; reg3=val[2]*reg3;
    reg4=var_inter[0]*reg4; T reg5=4*var_inter[0]; reg1=reg2+reg1; reg3=reg1+reg3; reg4=val[3]*reg4;
    reg5=var_inter[1]*reg5; reg1=4*var_inter[1]; reg4=reg3+reg4; reg5=val[4]*reg5; reg1=reg0*reg1;
    reg5=reg4+reg5; reg1=val[5]*reg1; res=reg5+reg1;

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Triangle_6 &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

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
