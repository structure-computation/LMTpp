#ifndef GET_VAR_INTER__Tetra_H
#define GET_VAR_INTER__Tetra_H
 
 
namespace LMT {
 
template<class PosNodes,class Pvec,class TVI>
bool get_var_inter_algebric(const Tetra &elem, const PosNodes &pos_nodes, const Pvec &pos, TVI &var_inter, typename Pvec::template SubType<0>::T tolerance = 1e-7 ) {
    typedef typename Pvec::template SubType<0>::T T;
    TVI vi;
    T R_0 = pos[2]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[1][2]; T R_2 = pos_nodes[2][2];
    T R_3 = pos_nodes[0][2]; R_0 = R_3+R_0; R_0 = (-1.0)*R_0; R_3 = (-1.0)*R_3;
    R_1 = R_1+R_3; R_2 = R_2+R_3; T R_4 = pos_nodes[3][2]; R_3 = R_4+R_3;
    R_4 = pos_nodes[3][0]; T R_5 = pos_nodes[3][1]; T R_6 = pos[0]; R_6 = (-1.0)*R_6;
    T R_7 = pos[1]; R_7 = (-1.0)*R_7; T R_8 = pos_nodes[1][1]; T R_9 = pos_nodes[0][1];
    R_7 = R_9+R_7; R_7 = (-1.0)*R_7; R_9 = (-1.0)*R_9; R_5 = R_5+R_9;
    R_8 = R_8+R_9; T R_10 = pos_nodes[2][1]; R_9 = R_10+R_9; R_10 = pos_nodes[2][0];
    T R_11 = pos_nodes[0][0]; R_6 = R_11+R_6; T R_12 = (-1.0)*R_6; R_11 = (-1.0)*R_11;
    R_4 = R_4+R_11; R_10 = R_10+R_11; T R_13 = pos_nodes[1][0]; R_11 = R_13+R_11;
    R_11 = 1/R_11; R_1 = R_1*R_11; R_13 = R_6*R_1; R_13 = (-1.0)*R_13;
    T R_14 = R_4*R_1; R_1 = R_10*R_1; R_1 = (-1.0)*R_1; R_1 = R_2+R_1;
    R_8 = R_8*R_11; R_2 = R_4*R_8; R_2 = (-1.0)*R_2; R_2 = R_5+R_2;
    R_6 = R_6*R_8; R_6 = R_7+R_6; R_8 = R_10*R_8; R_8 = (-1.0)*R_8;
    R_8 = R_9+R_8; R_8 = 1/R_8; R_1 = R_1*R_8; R_9 = R_6*R_1;
    R_9 = R_13+R_9; R_9 = (-1.0)*R_9; R_9 = R_0+R_9; R_1 = R_1*R_2;
    R_14 = R_1+R_14; R_14 = (-1.0)*R_14; R_14 = R_3+R_14; R_14 = 1/R_14;
    R_9 = R_14*R_9; vi[2] = R_9; R_4 = R_4*R_9; R_4 = (-1.0)*R_4;
    R_12 = R_4+R_12; R_9 = R_2*R_9; R_9 = (-1.0)*R_9; R_9 = R_6+R_9;
    R_9 = R_8*R_9; vi[1] = R_9; R_9 = R_10*R_9; R_9 = (-1.0)*R_9;
    R_12 = R_9+R_12; R_12 = R_11*R_12; vi[0] = R_12; 

    var_inter = vi;
    return true;
}
}
#endif  /// GET_VAR_INTER__Tetra
 
