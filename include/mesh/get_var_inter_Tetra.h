#ifndef GET_VAR_INTER__Tetra_H
#define GET_VAR_INTER__Tetra_H
 
 
namespace LMT {
 
template<class PosNodes,class Pvec,class TVI>
bool get_var_inter_experimental(const Tetra &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter, typename Pvec::template SubType<0>::T tolerance = 1e-7 ) {
    typedef typename Pvec::template SubType<0>::T T;
    TVI vi;
    T R_0 = pos[1]; R_0 = (-1.0)*R_0; T R_1 = pos[2]; R_1 = (-1.0)*R_1;
    T R_2 = pos_nodes[3][1]; T R_3 = pos_nodes[1][1]; T R_4 = pos_nodes[0][1]; R_0 = R_4+R_0;
    R_0 = (-1.0)*R_0; R_4 = (-1.0)*R_4; R_2 = R_2+R_4; R_3 = R_3+R_4;
    T R_5 = pos_nodes[2][1]; R_4 = R_5+R_4; R_5 = pos_nodes[1][2]; T R_6 = pos_nodes[2][0];
    T R_7 = pos_nodes[2][2]; T R_8 = pos_nodes[0][2]; R_1 = R_8+R_1; R_1 = (-1.0)*R_1;
    R_8 = (-1.0)*R_8; R_5 = R_5+R_8; R_7 = R_7+R_8; T R_9 = pos_nodes[3][2];
    R_8 = R_9+R_8; R_9 = pos_nodes[3][0]; T R_10 = pos[0]; R_10 = (-1.0)*R_10;
    T R_11 = pos_nodes[0][0]; R_10 = R_11+R_10; T R_12 = (-1.0)*R_10; R_11 = (-1.0)*R_11;
    R_6 = R_6+R_11; R_9 = R_9+R_11; T R_13 = pos_nodes[1][0]; R_11 = R_13+R_11;
    R_11 = 1/R_11; R_3 = R_3*R_11; R_13 = R_10*R_3; R_13 = R_0+R_13;
    R_0 = R_9*R_3; R_0 = (-1.0)*R_0; R_0 = R_2+R_0; R_3 = R_6*R_3;
    R_3 = (-1.0)*R_3; R_3 = R_4+R_3; R_3 = 1/R_3; R_5 = R_5*R_11;
    R_10 = R_10*R_5; R_10 = (-1.0)*R_10; R_4 = R_9*R_5; R_5 = R_6*R_5;
    R_5 = (-1.0)*R_5; R_5 = R_7+R_5; R_5 = R_5*R_3; R_7 = R_5*R_13;
    R_7 = R_10+R_7; R_7 = (-1.0)*R_7; R_7 = R_1+R_7; R_5 = R_5*R_0;
    R_4 = R_5+R_4; R_4 = (-1.0)*R_4; R_4 = R_8+R_4; R_4 = 1/R_4;
    R_7 = R_4*R_7; vi[2] = R_7; R_0 = R_7*R_0; R_0 = (-1.0)*R_0;
    R_0 = R_13+R_0; R_0 = R_3*R_0; vi[1] = R_0; R_0 = R_6*R_0;
    R_0 = (-1.0)*R_0; R_7 = R_9*R_7; R_7 = (-1.0)*R_7; R_7 = R_12+R_7;
    R_0 = R_7+R_0; R_0 = R_11*R_0; vi[0] = R_0; 

    var_inter += vi;
    return true;
}
}
#endif  /// GET_VAR_INTER__Tetra
 
