#ifndef GET_VAR_INTER__Triangle_H
#define GET_VAR_INTER__Triangle_H
 
 
namespace LMT {
 
template<class PosNodes,class Pvec,class TVI>
bool get_var_inter_algebric(const Triangle &elem, const PosNodes &pos_nodes, const Pvec &pos, TVI &var_inter, typename Pvec::template SubType<0>::T tolerance = 1e-7 ) {
    typedef typename Pvec::template SubType<0>::T T;
    TVI vi;
    T R_0 = pos[1]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[1][1]; T R_2 = pos_nodes[0][1];
    R_0 = R_2+R_0; R_0 = (-1.0)*R_0; R_2 = (-1.0)*R_2; R_1 = R_1+R_2;
    T R_3 = pos_nodes[2][1]; R_2 = R_3+R_2; R_3 = pos_nodes[2][0]; T R_4 = pos[0];
    R_4 = (-1.0)*R_4; T R_5 = pos_nodes[0][0]; R_4 = R_5+R_4; T R_6 = (-1.0)*R_4;
    R_5 = (-1.0)*R_5; R_3 = R_3+R_5; T R_7 = pos_nodes[1][0]; R_5 = R_7+R_5;
    R_5 = 1/R_5; R_1 = R_1*R_5; R_4 = R_4*R_1; R_4 = R_0+R_4;
    R_1 = R_3*R_1; R_1 = (-1.0)*R_1; R_1 = R_2+R_1; R_1 = 1/R_1;
    R_4 = R_1*R_4; vi[1] = R_4; R_4 = R_3*R_4; R_4 = (-1.0)*R_4;
    R_4 = R_6+R_4; R_4 = R_5*R_4; vi[0] = R_4; 

    var_inter = vi;
    return true;
}
}
#endif  /// GET_VAR_INTER__Triangle
 
