#ifndef LMT_TRIANGLE
#define LMT_TRIANGLE
namespace LMT {
inline const double *gauss_point_for_order(unsigned order, const Triangle &elem) { /// order -> degre du polynome a integrer exactement
    static const unsigned offset[] = { 0, 4, 8, 18, 31, 50, 72, 109, 146, 183, }; // fonction de lordre du poly
    static const double values[] = {
        0.5,0.333333333333,0.333333333333,
        0.0,
        0.5,0.333333333333,0.333333333333,
        0.0,
        0.166666666667,0.0,0.5,
        0.166666666667,0.5,0.5,
        0.166666666667,0.5,0.0,
        0.0,
        -0.28125,0.333333333333,0.333333333333,
        0.260416666667,0.2,0.2,
        0.260416666667,0.6,0.2,
        0.260416666667,0.2,0.6,
        0.0,
        0.111690794839005,0.44594849091596499999,0.44594849091596499999,
        0.111690794839005,0.44594849091596499999,0.10810301816807000002,
        0.111690794839005,0.10810301816807000002,0.44594849091596499999,
        0.054975871827660999999,0.091576213509771,0.091576213509771,
        0.054975871827660999999,0.091576213509771,0.81684757298045800001,
        0.054975871827660999999,0.81684757298045800001,0.091576213509771,
        0.0,
        0.1125,0.333333333333,0.333333333333,
        0.0661970763943,0.470142064105,0.470142064105,
        0.0661970763943,0.470142064105,0.0597158717898,
        0.0661970763943,0.0597158717898,0.470142064105,
        0.0629695902724,0.101286507323,0.101286507323,
        0.0629695902724,0.101286507323,0.797426985353,
        0.0629695902724,0.797426985353,0.101286507323,
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
template<class TNode> void permutation_if_jac_neg(const Triangle &elem,TNode **nodes) {
    typedef typename TNode::T T;
    T reg0=nodes[1]->pos[0]-nodes[0]->pos[0]; T reg1=nodes[2]->pos[1]-nodes[0]->pos[1]; T reg2=nodes[1]->pos[1]-nodes[0]->pos[1]; T reg3=nodes[2]->pos[0]-nodes[0]->pos[0]; reg1=reg0*reg1;
    reg3=reg2*reg3; T det_jac=reg1-reg3;

    if ( det_jac < 0 ) {
        TNode *tmp[] = {nodes[0],nodes[2],nodes[1]};
        for(unsigned i=0;i<3;++i) nodes[i] = tmp[i];
    }
}
template<class PosNodes,class Pvec,class TVI> void get_var_inter_linear(const Triangle &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=pos_nodes[2][1]-pos_nodes[0][1]; T reg1=pos_nodes[1][1]-pos_nodes[0][1]; T reg2=pos_nodes[2][0]-pos_nodes[0][0]; T reg3=pos_nodes[1][0]-pos_nodes[0][0]; T reg4=reg3*reg0;
    T reg5=reg2*reg1; reg5=reg4-reg5; T reg6=reg3/reg5; T reg7=reg2/reg5; T reg8=reg1/reg5;
    reg5=reg0/reg5; T reg9=pos[1]-pos_nodes[0][1]; T reg10=pos[0]-pos_nodes[0][0]; reg5=reg10*reg5; reg7=reg9*reg7;
    reg8=reg10*reg8; reg6=reg9*reg6; var_inter[0]=reg5-reg7; var_inter[1]=reg6-reg8;

}
template<class PosNodes,class Pvec,class TVI> void get_var_inter(const Triangle &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter) {
typedef typename Pvec::template SubType<0>::T T;
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=reg0*pos_nodes[0][0]; T reg2=var_inter[0]*pos_nodes[1][1]; T reg3=reg0*pos_nodes[0][1];
    T reg4=var_inter[0]*pos_nodes[1][0]; reg2=reg3+reg2; reg3=var_inter[1]*pos_nodes[2][1]; T reg5=var_inter[1]*pos_nodes[2][0]; reg4=reg1+reg4;
    reg1=pos_nodes[1][0]-pos_nodes[0][0]; T reg6=pos_nodes[2][0]-pos_nodes[0][0]; reg5=reg4+reg5; reg4=pos_nodes[1][1]-pos_nodes[0][1]; T reg7=pos_nodes[2][1]-pos_nodes[0][1];
    reg3=reg2+reg3; reg5=pos[0]-reg5; reg3=pos[1]-reg3; reg2=reg1*reg7; T reg8=reg1*var_inter[0];
    T reg9=reg4*var_inter[0]; T reg10=reg6*reg4; T reg11=reg7*var_inter[1]; reg9=reg3+reg9; reg8=reg5+reg8;
    reg3=reg6*var_inter[1]; reg10=reg2-reg10; reg8=reg3+reg8; reg9=reg11+reg9; reg3=reg7/reg10;
    reg5=reg4/reg10; reg11=reg6/reg10; reg10=reg1/reg10; reg10=reg9*reg10; reg5=reg8*reg5;
    reg11=reg9*reg11; reg3=reg8*reg3; var_inter[1]+=reg10-reg5; var_inter[0]+=reg3-reg11;

}
#ifndef STRUCT_P_plus_2
#define STRUCT_P_plus_2
struct P_plus_2 {};
#endif // STRUCT_P_plus_2
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const P_plus_2 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[1]*var_inter[0]; T reg1=val[2]*var_inter[1]; T reg2=pow(var_inter[0],2); T reg3=val[0]+reg0; reg3=reg3+reg1;
    T reg4=val[3]*reg2; T reg5=var_inter[0]*var_inter[1]; reg4=reg3+reg4; reg5=val[4]*reg5; reg3=pow(var_inter[1],2);
    reg5=reg4+reg5; reg4=val[5]*reg3; reg4=reg5+reg4; res=reg4;

}
#ifndef STRUCT_P_plus_3
#define STRUCT_P_plus_3
struct P_plus_3 {};
#endif // STRUCT_P_plus_3
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const P_plus_3 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[1]*var_inter[0]; T reg1=val[2]*var_inter[1]; T reg2=pow(var_inter[0],2); T reg3=val[0]+reg0; reg3=reg3+reg1;
    T reg4=val[3]*reg2; T reg5=var_inter[0]*var_inter[1]; reg4=reg3+reg4; reg5=val[4]*reg5; reg3=pow(var_inter[1],2);
    T reg6=pow(var_inter[0],3); reg5=reg4+reg5; reg4=val[5]*reg3; T reg7=val[6]*reg6; T reg8=var_inter[1]*reg2;
    reg4=reg5+reg4; reg8=val[7]*reg8; reg5=var_inter[0]*reg3; reg7=reg4+reg7; reg5=val[8]*reg5;
    reg4=pow(var_inter[1],3); reg8=reg7+reg8; reg5=reg8+reg5; reg7=val[9]*reg4; reg7=reg5+reg7;
    res=reg7;

}
#ifndef STRUCT_P_plus_0
#define STRUCT_P_plus_0
struct P_plus_0 {};
#endif // STRUCT_P_plus_0
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const P_plus_0 &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Global
#define STRUCT_Global
struct Global {};
#endif // STRUCT_Global
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const Global &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_P_plus_6
#define STRUCT_P_plus_6
struct P_plus_6 {};
#endif // STRUCT_P_plus_6
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const P_plus_6 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[1]*var_inter[0]; T reg1=val[2]*var_inter[1]; T reg2=val[0]+reg0; T reg3=pow(var_inter[0],2); reg2=reg2+reg1;
    T reg4=val[3]*reg3; T reg5=var_inter[0]*var_inter[1]; reg4=reg2+reg4; reg5=val[4]*reg5; reg2=pow(var_inter[1],2);
    reg5=reg4+reg5; reg4=val[5]*reg2; T reg6=pow(var_inter[0],3); reg4=reg5+reg4; reg5=val[6]*reg6;
    T reg7=var_inter[1]*reg3; reg5=reg4+reg5; reg7=val[7]*reg7; reg4=var_inter[0]*reg2; T reg8=pow(var_inter[1],3);
    reg4=val[8]*reg4; reg7=reg5+reg7; reg5=val[9]*reg8; reg4=reg7+reg4; reg7=pow(var_inter[0],4);
    reg5=reg4+reg5; reg4=val[10]*reg7; T reg9=var_inter[1]*reg6; reg4=reg5+reg4; reg9=val[11]*reg9;
    reg5=reg3*reg2; T reg10=var_inter[0]*reg8; reg5=val[12]*reg5; reg9=reg4+reg9; reg10=val[13]*reg10;
    reg5=reg9+reg5; reg4=pow(var_inter[1],4); reg10=reg5+reg10; reg5=val[14]*reg4; reg9=pow(var_inter[0],5);
    reg5=reg10+reg5; reg10=val[15]*reg9; T reg11=var_inter[1]*reg7; reg10=reg5+reg10; reg11=val[16]*reg11;
    reg5=reg2*reg6; reg5=val[17]*reg5; T reg12=reg3*reg8; reg11=reg10+reg11; reg5=reg11+reg5;
    reg12=val[18]*reg12; reg10=var_inter[0]*reg4; reg12=reg5+reg12; reg10=val[19]*reg10; reg5=pow(var_inter[1],5);
    reg11=val[20]*reg5; T reg13=pow(var_inter[0],6); reg10=reg12+reg10; reg11=reg10+reg11; reg10=val[21]*reg13;
    reg12=var_inter[1]*reg9; reg12=val[22]*reg12; T reg14=reg2*reg7; reg10=reg11+reg10; reg12=reg10+reg12;
    reg14=val[23]*reg14; reg10=reg6*reg8; reg10=val[24]*reg10; reg11=reg3*reg4; reg14=reg12+reg14;
    reg11=val[25]*reg11; reg12=var_inter[0]*reg5; reg10=reg14+reg10; reg11=reg10+reg11; reg12=val[26]*reg12;
    reg10=pow(var_inter[1],6); reg12=reg11+reg12; reg11=val[27]*reg10; reg11=reg12+reg11; res=reg11;

}
#ifndef STRUCT_Elementary_mul_nb_nodes
#define STRUCT_Elementary_mul_nb_nodes
struct Elementary_mul_nb_nodes {};
#endif // STRUCT_Elementary_mul_nb_nodes
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const Elementary_mul_nb_nodes &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_P_plus_4
#define STRUCT_P_plus_4
struct P_plus_4 {};
#endif // STRUCT_P_plus_4
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const P_plus_4 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[1]*var_inter[0]; T reg1=val[2]*var_inter[1]; T reg2=pow(var_inter[0],2); T reg3=val[0]+reg0; T reg4=var_inter[0]*var_inter[1];
    T reg5=val[3]*reg2; reg3=reg3+reg1; T reg6=pow(var_inter[1],2); reg4=val[4]*reg4; reg5=reg3+reg5;
    reg3=pow(var_inter[0],3); reg4=reg5+reg4; reg5=val[5]*reg6; T reg7=val[6]*reg3; T reg8=var_inter[1]*reg2;
    reg5=reg4+reg5; reg7=reg5+reg7; reg8=val[7]*reg8; reg4=var_inter[0]*reg6; reg4=val[8]*reg4;
    reg5=pow(var_inter[1],3); reg8=reg7+reg8; reg4=reg8+reg4; reg7=val[9]*reg5; reg8=pow(var_inter[0],4);
    reg7=reg4+reg7; reg4=val[10]*reg8; T reg9=var_inter[1]*reg3; reg9=val[11]*reg9; T reg10=reg2*reg6;
    reg4=reg7+reg4; reg9=reg4+reg9; reg10=val[12]*reg10; reg4=var_inter[0]*reg5; reg10=reg9+reg10;
    reg4=val[13]*reg4; reg7=pow(var_inter[1],4); reg4=reg10+reg4; reg9=val[14]*reg7; reg9=reg4+reg9;
    res=reg9;

}
#ifndef STRUCT_P_plus_5
#define STRUCT_P_plus_5
struct P_plus_5 {};
#endif // STRUCT_P_plus_5
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const P_plus_5 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[1]*var_inter[0]; T reg1=val[2]*var_inter[1]; T reg2=pow(var_inter[0],2); T reg3=val[0]+reg0; T reg4=val[3]*reg2;
    reg3=reg3+reg1; T reg5=var_inter[0]*var_inter[1]; reg4=reg3+reg4; reg5=val[4]*reg5; reg3=pow(var_inter[1],2);
    T reg6=pow(var_inter[0],3); reg5=reg4+reg5; reg4=val[5]*reg3; reg4=reg5+reg4; reg5=val[6]*reg6;
    T reg7=var_inter[1]*reg2; reg5=reg4+reg5; reg7=val[7]*reg7; reg4=var_inter[0]*reg3; reg7=reg5+reg7;
    reg4=val[8]*reg4; reg5=pow(var_inter[1],3); T reg8=val[9]*reg5; T reg9=pow(var_inter[0],4); reg4=reg7+reg4;
    reg8=reg4+reg8; reg4=val[10]*reg9; reg7=var_inter[1]*reg6; reg4=reg8+reg4; reg7=val[11]*reg7;
    reg8=reg2*reg3; T reg10=var_inter[0]*reg5; reg7=reg4+reg7; reg8=val[12]*reg8; reg4=pow(var_inter[1],4);
    reg10=val[13]*reg10; reg8=reg7+reg8; reg7=val[14]*reg4; reg10=reg8+reg10; reg8=pow(var_inter[0],5);
    reg7=reg10+reg7; reg10=val[15]*reg8; T reg11=var_inter[1]*reg9; reg10=reg7+reg10; reg11=val[16]*reg11;
    reg7=reg3*reg6; reg11=reg10+reg11; reg7=val[17]*reg7; reg10=reg2*reg5; T reg12=var_inter[0]*reg4;
    reg10=val[18]*reg10; reg7=reg11+reg7; reg10=reg7+reg10; reg12=val[19]*reg12; reg7=pow(var_inter[1],5);
    reg12=reg10+reg12; reg10=val[20]*reg7; reg10=reg12+reg10; res=reg10;

}
#ifndef STRUCT_Nodal
#define STRUCT_Nodal
struct Nodal {};
#endif // STRUCT_Nodal
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const Nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=val[0]*reg0; T reg2=val[1]*var_inter[0]; reg1=reg1+reg2;
    T reg3=val[2]*var_inter[1]; res=reg1+reg3;

}
#ifndef STRUCT_P_plus_8
#define STRUCT_P_plus_8
struct P_plus_8 {};
#endif // STRUCT_P_plus_8
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const P_plus_8 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[1]*var_inter[0]; T reg1=val[2]*var_inter[1]; T reg2=val[0]+reg0; T reg3=pow(var_inter[0],2); reg2=reg2+reg1;
    T reg4=val[3]*reg3; T reg5=var_inter[0]*var_inter[1]; reg4=reg2+reg4; reg5=val[4]*reg5; reg2=pow(var_inter[1],2);
    reg5=reg4+reg5; reg4=val[5]*reg2; T reg6=pow(var_inter[0],3); T reg7=var_inter[1]*reg3; T reg8=val[6]*reg6;
    reg4=reg5+reg4; reg8=reg4+reg8; reg4=var_inter[0]*reg2; reg7=val[7]*reg7; reg5=pow(var_inter[1],3);
    reg4=val[8]*reg4; reg7=reg8+reg7; reg8=pow(var_inter[0],4); T reg9=val[9]*reg5; reg4=reg7+reg4;
    reg7=val[10]*reg8; T reg10=var_inter[1]*reg6; reg9=reg4+reg9; reg7=reg9+reg7; reg10=val[11]*reg10;
    reg4=reg3*reg2; reg10=reg7+reg10; reg7=var_inter[0]*reg5; reg4=val[12]*reg4; reg9=pow(var_inter[1],4);
    reg7=val[13]*reg7; reg4=reg10+reg4; reg7=reg4+reg7; reg4=val[14]*reg9; reg10=pow(var_inter[0],5);
    reg4=reg7+reg4; reg7=val[15]*reg10; T reg11=var_inter[1]*reg8; reg7=reg4+reg7; reg11=val[16]*reg11;
    reg4=reg2*reg6; reg11=reg7+reg11; reg7=reg3*reg5; reg4=val[17]*reg4; reg4=reg11+reg4;
    reg7=val[18]*reg7; reg11=var_inter[0]*reg9; reg7=reg4+reg7; reg11=val[19]*reg11; reg4=pow(var_inter[1],5);
    reg11=reg7+reg11; reg7=val[20]*reg4; T reg12=pow(var_inter[0],6); reg7=reg11+reg7; reg11=val[21]*reg12;
    T reg13=var_inter[1]*reg10; T reg14=reg2*reg8; reg13=val[22]*reg13; reg11=reg7+reg11; reg13=reg11+reg13;
    reg14=val[23]*reg14; reg7=reg6*reg5; reg14=reg13+reg14; reg7=val[24]*reg7; reg11=reg3*reg9;
    reg13=var_inter[0]*reg4; reg11=val[25]*reg11; reg7=reg14+reg7; reg11=reg7+reg11; reg13=val[26]*reg13;
    reg7=pow(var_inter[1],6); reg13=reg11+reg13; reg11=val[27]*reg7; reg14=pow(var_inter[0],7); reg11=reg13+reg11;
    reg13=val[28]*reg14; T reg15=var_inter[1]*reg12; reg13=reg11+reg13; reg15=val[29]*reg15; reg11=reg2*reg10;
    reg15=reg13+reg15; reg11=val[30]*reg11; reg13=reg5*reg8; reg11=reg15+reg11; reg13=val[31]*reg13;
    reg15=reg6*reg9; reg13=reg11+reg13; reg15=val[32]*reg15; reg11=reg3*reg4; reg15=reg13+reg15;
    reg11=val[33]*reg11; reg13=var_inter[0]*reg7; reg11=reg15+reg11; reg13=val[34]*reg13; reg15=pow(var_inter[1],7);
    T reg16=val[35]*reg15; T reg17=pow(var_inter[0],8); reg13=reg11+reg13; reg14=var_inter[1]*reg14; reg16=reg13+reg16;
    reg17=val[36]*reg17; reg17=reg16+reg17; reg14=val[37]*reg14; reg12=reg2*reg12; reg14=reg17+reg14;
    reg12=val[38]*reg12; reg10=reg5*reg10; reg10=val[39]*reg10; reg9=reg8*reg9; reg12=reg14+reg12;
    reg10=reg12+reg10; reg9=val[40]*reg9; reg4=reg6*reg4; reg4=val[41]*reg4; reg7=reg3*reg7;
    reg9=reg10+reg9; reg7=val[42]*reg7; reg15=var_inter[0]*reg15; reg4=reg9+reg4; reg15=val[43]*reg15;
    reg2=pow(var_inter[1],8); reg7=reg4+reg7; reg15=reg7+reg15; reg2=val[44]*reg2; res=reg15+reg2;

}
#ifndef STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
#define STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
struct Elementary_mul_nb_nodes_of_each_children_elem {};
#endif // STRUCT_Elementary_mul_nb_nodes_of_each_children_elem
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const Elementary_mul_nb_nodes_of_each_children_elem &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Gauss
#define STRUCT_Gauss
struct Gauss {};
#endif // STRUCT_Gauss
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const Gauss &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0]+val[1];

}
#ifndef STRUCT_Der_nodal
#define STRUCT_Der_nodal
struct Der_nodal {};
#endif // STRUCT_Der_nodal
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const Der_nodal &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_P_plus_1
#define STRUCT_P_plus_1
struct P_plus_1 {};
#endif // STRUCT_P_plus_1
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const P_plus_1 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[1]*var_inter[0]; T reg1=val[0]+reg0; T reg2=val[2]*var_inter[1]; reg1=reg1+reg2; res=reg1;

}
#ifndef STRUCT_P_plus_7
#define STRUCT_P_plus_7
struct P_plus_7 {};
#endif // STRUCT_P_plus_7
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const P_plus_7 &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=val[1]*var_inter[0]; T reg1=val[2]*var_inter[1]; T reg2=pow(var_inter[0],2); T reg3=val[0]+reg0; T reg4=var_inter[0]*var_inter[1];
    T reg5=val[3]*reg2; reg3=reg3+reg1; reg5=reg3+reg5; reg4=val[4]*reg4; reg3=pow(var_inter[1],2);
    T reg6=pow(var_inter[0],3); T reg7=val[5]*reg3; reg4=reg5+reg4; reg5=val[6]*reg6; reg7=reg4+reg7;
    reg4=var_inter[1]*reg2; T reg8=var_inter[0]*reg3; reg5=reg7+reg5; reg4=val[7]*reg4; reg4=reg5+reg4;
    reg8=val[8]*reg8; reg5=pow(var_inter[1],3); reg7=val[9]*reg5; T reg9=pow(var_inter[0],4); reg8=reg4+reg8;
    reg4=var_inter[1]*reg6; T reg10=val[10]*reg9; reg7=reg8+reg7; reg8=reg2*reg3; reg4=val[11]*reg4;
    reg10=reg7+reg10; reg4=reg10+reg4; reg8=val[12]*reg8; reg7=var_inter[0]*reg5; reg10=pow(var_inter[1],4);
    reg7=val[13]*reg7; reg8=reg4+reg8; reg4=val[14]*reg10; reg7=reg8+reg7; reg8=pow(var_inter[0],5);
    T reg11=var_inter[1]*reg9; T reg12=val[15]*reg8; reg4=reg7+reg4; reg7=reg3*reg6; reg11=val[16]*reg11;
    reg12=reg4+reg12; reg11=reg12+reg11; reg7=val[17]*reg7; reg4=reg2*reg5; reg7=reg11+reg7;
    reg4=val[18]*reg4; reg11=var_inter[0]*reg10; reg4=reg7+reg4; reg11=val[19]*reg11; reg7=pow(var_inter[1],5);
    reg11=reg4+reg11; reg4=val[20]*reg7; reg12=pow(var_inter[0],6); reg4=reg11+reg4; reg11=val[21]*reg12;
    T reg13=var_inter[1]*reg8; T reg14=reg3*reg9; reg13=val[22]*reg13; reg11=reg4+reg11; reg13=reg11+reg13;
    reg14=val[23]*reg14; reg4=reg6*reg5; reg4=val[24]*reg4; reg11=reg2*reg10; reg14=reg13+reg14;
    reg4=reg14+reg4; reg11=val[25]*reg11; reg13=var_inter[0]*reg7; reg11=reg4+reg11; reg13=val[26]*reg13;
    reg4=pow(var_inter[1],6); reg14=pow(var_inter[0],7); reg13=reg11+reg13; reg11=val[27]*reg4; T reg15=val[28]*reg14;
    T reg16=var_inter[1]*reg12; reg11=reg13+reg11; reg15=reg11+reg15; reg16=val[29]*reg16; reg11=reg3*reg8;
    reg11=val[30]*reg11; reg13=reg5*reg9; reg16=reg15+reg16; reg11=reg16+reg11; reg13=val[31]*reg13;
    reg15=reg6*reg10; reg15=val[32]*reg15; reg16=reg2*reg7; reg13=reg11+reg13; reg16=val[33]*reg16;
    reg11=var_inter[0]*reg4; reg15=reg13+reg15; reg11=val[34]*reg11; reg13=pow(var_inter[1],7); reg16=reg15+reg16;
    reg11=reg16+reg11; reg15=val[35]*reg13; reg15=reg11+reg15; res=reg15;

}
#ifndef STRUCT_Elementary
#define STRUCT_Elementary
struct Elementary {};
#endif // STRUCT_Elementary
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const Elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef STRUCT_Bubble
#define STRUCT_Bubble
struct Bubble {};
#endif // STRUCT_Bubble
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const Bubble &n,const TVI &var_inter,const TVAL &val,T &res) {
    T reg0=1-var_inter[0]; reg0=reg0-var_inter[1]; T reg1=var_inter[0]*reg0; reg1=var_inter[1]*reg1; reg1=81*reg1;
    T reg2=1-reg1; T reg3=reg0*reg2; T reg4=var_inter[0]*reg2; reg2=var_inter[1]*reg2; reg4=val[1]*reg4;
    reg3=val[0]*reg3; reg4=reg3+reg4; reg2=val[2]*reg2; reg2=reg4+reg2; reg1=val[3]*reg1;
    res=reg2+reg1;

}
#ifndef STRUCT_Skin_elementary
#define STRUCT_Skin_elementary
struct Skin_elementary {};
#endif // STRUCT_Skin_elementary
template<class TVI,class TVAL,class T> void get_interp(const Triangle &ne,const Skin_elementary &n,const TVI &var_inter,const TVAL &val,T &res) {
    res=val[0];

}
#ifndef AUTORIZEDPERM
#define AUTORIZEDPERM
template<class T> struct AuthorizedPerm;
#endif // AUTORIZEDPERM
template<> struct AuthorizedPerm<Triangle> {
    static const unsigned nb_permutations = 0;
    template<class TE> static void make_permutation( TE &e, unsigned nb_perm ) {
    }
    template<class TE> static void unmake_permutation( TE &e, unsigned nb_perm ) {
    }
};

}
#endif // LMT_TRIANGLE
