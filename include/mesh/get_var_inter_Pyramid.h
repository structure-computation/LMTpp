#ifndef GET_VAR_INTER__Pyramid_H
#define GET_VAR_INTER__Pyramid_H
 
#include <containers/polynomials.h>
 
 
namespace LMT {
 
template<class PosNodes,class Pvec,class TVI>
bool get_var_inter_experimental(const Pyramid &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter, typename Pvec::template SubType<0>::T tolerance = 1e-7 ) {
    typedef typename Pvec::template SubType<0>::T T;
    T w0, w1, w2, U, V, W, eval, eval2, eval3, U2, V2, W2;
    int i_pivot;
    Vec< Vec< T, 6>, 2 > coeff_resultant_UV;
    Vec< T, 5 > coeff_resultant_U;
    Vec< T > sol_U;
    Vec< T, 3 > coeff_V, coeff_V2;
    Vec< T, 2 > coeff_W;
    Vec< T > sol_V;
    Vec< T > sol_W;
    Vec< T, 6 > coeff_resultant_UV5;
    Vec< T, 6 > coeff_resultant_UV6;
    TVI sol_vi = 0;
    T err_vi = std::numeric_limits<T>::max(), err;
    Vec< Vec< T >, 3 > coeff_poly;
    Vec< Vec< T, 3 > > sol_poly;

    /// on résout le problème s'il est "quasi-linéaire"
    coeff_poly[0].resize(10);
    coeff_poly[1].resize(10);
    coeff_poly[2].resize(10);
    {
    T R_0 = pos_nodes[1][2]; T R_1 = (-1.0)*R_0; T R_2 = -0.5*R_0; T R_3 = pos_nodes[3][2];
    T R_4 = -0.5*R_3; T R_5 = pos_nodes[4][2]; R_5 = 2.0*R_5; R_4 = R_5+R_4;
    R_5 = pos_nodes[2][2]; T R_6 = (-1.0)*R_5; T R_7 = -0.5*R_5; T R_8 = pos_nodes[0][2];
    R_3 = R_3+R_8; R_3 = R_1+R_3; R_6 = R_3+R_6; coeff_poly[2][8] = R_6;
    R_6 = (-1.0)*R_8; R_0 = R_6+R_0; coeff_poly[2][3] = R_0; R_6 = R_5+R_6;
    coeff_poly[2][2] = R_6; R_6 = -0.5*R_8; R_6 = R_4+R_6; R_2 = R_6+R_2;
    R_2 = R_7+R_2; coeff_poly[2][1] = R_2; R_2 = pos[2]; R_2 = (-1.0)*R_2;
    R_8 = R_2+R_8; coeff_poly[2][0] = R_8; R_8 = pos_nodes[3][1]; R_2 = -0.5*R_8;
    R_7 = pos_nodes[4][1]; R_7 = 2.0*R_7; R_2 = R_7+R_2; R_7 = pos_nodes[1][1];
    R_6 = (-1.0)*R_7; R_4 = -0.5*R_7; R_5 = pos_nodes[2][1]; R_0 = (-1.0)*R_5;
    R_3 = -0.5*R_5; R_1 = pos[1]; R_1 = (-1.0)*R_1; T R_9 = pos_nodes[0][1];
    R_8 = R_9+R_8; R_6 = R_8+R_6; R_6 = R_0+R_6; coeff_poly[1][8] = R_6;
    R_6 = (-1.0)*R_9; R_7 = R_7+R_6; coeff_poly[1][3] = R_7; R_6 = R_5+R_6;
    coeff_poly[1][2] = R_6; R_6 = -0.5*R_9; R_2 = R_6+R_2; R_2 = R_4+R_2;
    R_2 = R_3+R_2; coeff_poly[1][1] = R_2; R_1 = R_9+R_1; coeff_poly[1][0] = R_1;
    R_1 = pos_nodes[4][0]; R_1 = 2.0*R_1; R_9 = pos_nodes[3][0]; R_2 = -0.5*R_9;
    R_1 = R_2+R_1; R_2 = pos_nodes[1][0]; R_3 = (-1.0)*R_2; R_4 = -0.5*R_2;
    R_6 = pos_nodes[2][0]; R_5 = (-1.0)*R_6; R_7 = -0.5*R_6; R_0 = pos[0];
    R_0 = (-1.0)*R_0; R_8 = pos_nodes[0][0]; R_9 = R_8+R_9; R_9 = R_3+R_9;
    R_5 = R_9+R_5; coeff_poly[0][8] = R_5; R_5 = (-1.0)*R_8; R_2 = R_2+R_5;
    coeff_poly[0][3] = R_2; R_5 = R_6+R_5; coeff_poly[0][2] = R_5; R_5 = -0.5*R_8;
    R_5 = R_1+R_5; R_5 = R_4+R_5; R_5 = R_7+R_5; coeff_poly[0][1] = R_5;
    R_0 = R_8+R_0; coeff_poly[0][0] = R_0; 
    coeff_poly[0][4] = 0.0; coeff_poly[0][5] = 0.0; coeff_poly[0][6] = 0.0; coeff_poly[0][7] = 0.0;
    coeff_poly[0][9] = 0.0; coeff_poly[1][4] = 0.0; coeff_poly[1][5] = 0.0; coeff_poly[1][6] = 0.0;
    coeff_poly[1][7] = 0.0; coeff_poly[1][9] = 0.0; coeff_poly[2][4] = 0.0; coeff_poly[2][5] = 0.0;
    coeff_poly[2][6] = 0.0; coeff_poly[2][7] = 0.0; coeff_poly[2][9] = 0.0; 

    }
    if (solve_quasi_linear_polynomial_system_3X( coeff_poly, sol_poly, tolerance ) )
        for( unsigned i=0; i< sol_poly.size(); ++i) 
            if ( var_inter_is_inside( Pyramid(), sol_poly[i], tolerance ) ) {
                var_inter += sol_poly[i];
                return true;
            }

    {

    T R_0 = pos_nodes[4][1]; R_0 = 2.0*R_0; T R_1 = pos_nodes[2][1]; T R_2 = (-1.0)*R_1;
    T R_3 = pos_nodes[3][1]; T R_4 = pos_nodes[1][1]; T R_5 = (-1.0)*R_4; T R_6 = pos[1];
    R_6 = (-1.0)*R_6; T R_7 = pos_nodes[0][1]; T R_8 = R_7+R_3; R_5 = R_8+R_5;
    R_5 = R_2+R_5; R_2 = R_7+R_1; R_2 = R_3+R_2; R_2 = R_2+R_4;
    R_2 = -0.5*R_2; R_0 = R_2+R_0; R_2 = (-1.0)*R_7; R_1 = R_1+R_2;
    R_2 = R_4+R_2; R_6 = R_7+R_6; R_7 = pos_nodes[4][2]; R_7 = 2.0*R_7;
    R_4 = pos_nodes[2][2]; R_3 = (-1.0)*R_4; R_8 = pos_nodes[3][2]; T R_9 = R_8+R_4;
    T R_10 = pos_nodes[4][0]; R_10 = 2.0*R_10; T R_11 = pos_nodes[3][0]; T R_12 = pos_nodes[2][0];
    T R_13 = (-1.0)*R_12; T R_14 = pos_nodes[1][0]; T R_15 = (-1.0)*R_14; T R_16 = pos[2];
    R_16 = (-1.0)*R_16; T R_17 = pos_nodes[1][2]; T R_18 = (-1.0)*R_17; R_9 = R_17+R_9;
    T R_19 = pos_nodes[0][2]; R_8 = R_8+R_19; R_8 = R_18+R_8; R_3 = R_8+R_3;
    R_8 = R_3*R_1; R_18 = R_0*R_3; T R_20 = R_6*R_3; R_9 = R_9+R_19;
    R_9 = -0.5*R_9; R_7 = R_9+R_7; R_9 = R_7*R_5; R_9 = (-1.0)*R_9;
    R_18 = R_9+R_18; coeff_resultant_UV6[4] = R_18; R_18 = R_7*R_2; R_18 = (-1.0)*R_18;
    R_16 = R_16+R_19; R_9 = R_16*R_5; R_9 = (-1.0)*R_9; T R_21 = R_16*R_2;
    R_21 = (-1.0)*R_21; R_19 = (-1.0)*R_19; R_4 = R_4+R_19; R_5 = R_5*R_4;
    R_5 = (-1.0)*R_5; R_8 = R_5+R_8; coeff_resultant_UV6[5] = R_8; R_2 = R_4*R_2;
    R_2 = (-1.0)*R_2; R_17 = R_19+R_17; R_1 = R_1*R_17; R_2 = R_1+R_2;
    R_9 = R_2+R_9; R_20 = R_9+R_20; coeff_resultant_UV6[2] = R_20; R_0 = R_0*R_17;
    R_0 = R_18+R_0; coeff_resultant_UV6[1] = R_0; R_6 = R_6*R_17; R_21 = R_6+R_21;
    coeff_resultant_UV6[0] = R_21; R_21 = pos[0]; R_21 = (-1.0)*R_21; R_6 = pos_nodes[0][0];
    R_11 = R_6+R_11; R_15 = R_15+R_11; R_13 = R_15+R_13; R_15 = R_4*R_13;
    R_15 = (-1.0)*R_15; R_0 = R_7*R_13; R_0 = (-1.0)*R_0; R_13 = R_16*R_13;
    R_13 = (-1.0)*R_13; R_11 = R_12+R_11; R_11 = R_11+R_14; R_11 = -0.5*R_11;
    R_10 = R_11+R_10; R_11 = R_10*R_3; R_0 = R_11+R_0; coeff_resultant_UV5[4] = R_0;
    R_10 = R_10*R_17; R_0 = (-1.0)*R_6; R_12 = R_12+R_0; R_11 = R_3*R_12;
    R_15 = R_11+R_15; coeff_resultant_UV5[5] = R_15; R_12 = R_12*R_17; R_0 = R_14+R_0;
    R_4 = R_4*R_0; R_4 = (-1.0)*R_4; R_4 = R_12+R_4; R_13 = R_4+R_13;
    R_7 = R_7*R_0; R_7 = (-1.0)*R_7; R_7 = R_10+R_7; coeff_resultant_UV5[1] = R_7;
    R_0 = R_16*R_0; R_0 = (-1.0)*R_0; R_21 = R_6+R_21; R_3 = R_21*R_3;
    R_13 = R_3+R_13; coeff_resultant_UV5[2] = R_13; R_17 = R_21*R_17; R_0 = R_17+R_0;
    coeff_resultant_UV5[0] = R_0; 
    coeff_resultant_UV5[3] = 0.0; coeff_resultant_UV6[3] = 0.0; 

    }


    //PRINT( coeff_resultant_UV5 ); PRINT( coeff_resultant_UV6 );

    T w0_3; T w1_3; T w2_3; T w0_8;
    T w1_8; T w2_8; T w0_6; T w1_6; T w2_6; 
    T R_0 = pos_nodes[2][2]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[3][2]; T R_2 = pos_nodes[3][1];
    T R_3 = pos_nodes[2][1]; R_3 = (-1.0)*R_3; T R_4 = pos_nodes[2][0]; R_4 = (-1.0)*R_4;
    T R_5 = pos_nodes[3][0]; T R_6 = pos_nodes[1][2]; T R_7 = (-1.0)*R_6; T R_8 = pos_nodes[0][2];
    R_1 = R_1+R_8; R_1 = R_7+R_1; R_0 = R_1+R_0; w2_8 = R_0;
    R_8 = (-1.0)*R_8; R_6 = R_8+R_6; w2_3 = R_6; R_6 = pos_nodes[0][1];
    R_2 = R_6+R_2; R_6 = (-1.0)*R_6; R_8 = pos_nodes[1][1]; R_0 = (-1.0)*R_8;
    R_0 = R_2+R_0; R_0 = R_3+R_0; w1_8 = R_0; R_6 = R_8+R_6;
    w1_3 = R_6; R_6 = pos_nodes[0][0]; R_5 = R_6+R_5; R_6 = (-1.0)*R_6;
    R_8 = pos_nodes[1][0]; R_0 = (-1.0)*R_8; R_5 = R_0+R_5; R_4 = R_5+R_4;
    w0_8 = R_4; R_6 = R_8+R_6; w0_3 = R_6; 
    w0_6 = 0.0; w1_6 = 0.0; w2_6 = 0.0; 

    w0 = 
 abs( w0_3 ) + 
 abs( w0_8 ) + 
 abs( w0_6 ) + 
 0;
    w1 = 
 abs( w1_3 ) + 
 abs( w1_8 ) + 
 abs( w1_6 ) + 
 0;
    w2 = 
 abs( w2_3 ) + 
 abs( w2_8 ) + 
 abs( w2_6 ) + 
 0;
    T w_max = max( max( w0, w1), w2 );
    if ( w0 == w_max ) {
        i_pivot = 0;
        T R_0 = pos_nodes[4][2]; R_0 = 2.0*R_0; T R_1 = pos_nodes[4][0]; R_1 = 2.0*R_1;
        T R_2 = pos_nodes[4][1]; R_2 = 2.0*R_2; T R_3 = pos_nodes[3][1]; T R_4 = pos_nodes[2][1];
        T R_5 = (-1.0)*R_4; T R_6 = pos[2]; R_6 = (-1.0)*R_6; T R_7 = pos[1];
        R_7 = (-1.0)*R_7; T R_8 = pos_nodes[0][1]; T R_9 = R_8+R_4; R_9 = R_3+R_9;
        R_3 = R_8+R_3; R_7 = R_8+R_7; R_8 = (-1.0)*R_8; R_4 = R_4+R_8;
        T R_10 = pos_nodes[1][1]; R_9 = R_9+R_10; R_9 = -0.5*R_9; R_2 = R_9+R_2;
        R_9 = (-1.0)*R_10; R_9 = R_3+R_9; R_9 = R_5+R_9; R_8 = R_10+R_8;
        R_10 = pos[0]; R_10 = (-1.0)*R_10; R_5 = pos_nodes[3][0]; R_3 = pos_nodes[1][0];
        T R_11 = (-1.0)*R_3; T R_12 = pos_nodes[0][0]; R_10 = R_12+R_10; T R_13 = R_10*R_9;
        R_13 = (-1.0)*R_13; T R_14 = R_10*R_8; R_14 = (-1.0)*R_14; R_5 = R_12+R_5;
        R_11 = R_11+R_5; R_12 = (-1.0)*R_12; T R_15 = R_3+R_12; T R_16 = R_2*R_15;
        T R_17 = R_4*R_15; T R_18 = R_7*R_15; R_18 = R_14+R_18; R_14 = pow(R_18,2);
        T R_19 = pos_nodes[2][0]; R_5 = R_19+R_5; R_3 = R_5+R_3; R_3 = -0.5*R_3;
        R_1 = R_3+R_1; R_3 = R_1*R_8; R_3 = (-1.0)*R_3; R_3 = R_16+R_3;
        R_16 = pow(R_3,2); R_5 = R_1*R_9; R_5 = (-1.0)*R_5; T R_20 = (-1.0)*R_19;
        R_20 = R_11+R_20; R_2 = R_2*R_20; R_5 = R_2+R_5; R_2 = pow(R_5,2);
        R_7 = R_7*R_20; R_4 = R_4*R_20; R_12 = R_19+R_12; R_8 = R_12*R_8;
        R_8 = (-1.0)*R_8; R_8 = R_17+R_8; R_8 = R_13+R_8; R_7 = R_8+R_7;
        R_8 = pow(R_7,2); R_9 = R_9*R_12; R_9 = (-1.0)*R_9; R_9 = R_4+R_9;
        R_4 = pow(R_9,2); R_13 = pos_nodes[2][2]; R_17 = (-1.0)*R_13; R_19 = pos_nodes[0][2];
        R_6 = R_6+R_19; R_11 = R_6*R_15; R_6 = R_6*R_20; T R_21 = (-1.0)*R_19;
        T R_22 = R_13+R_21; T R_23 = R_22*R_15; R_22 = R_22*R_20; T R_24 = pos_nodes[3][2];
        R_13 = R_24+R_13; R_24 = R_24+R_19; T R_25 = pos_nodes[1][2]; R_13 = R_25+R_13;
        R_19 = R_13+R_19; R_19 = -0.5*R_19; R_0 = R_19+R_0; R_15 = R_0*R_15;
        R_20 = R_0*R_20; R_21 = R_21+R_25; R_0 = R_1*R_21; R_0 = (-1.0)*R_0;
        R_0 = R_15+R_0; R_15 = pow(R_0,2); R_15 = R_4*R_15; R_19 = R_4*R_0;
        R_13 = R_10*R_21; R_13 = (-1.0)*R_13; R_13 = R_11+R_13; R_19 = R_19*R_13;
        R_19 = 2.0*R_19; R_11 = pow(R_13,2); R_11 = R_4*R_11; R_21 = R_12*R_21;
        R_21 = (-1.0)*R_21; R_23 = R_21+R_23; R_25 = (-1.0)*R_25; R_24 = R_25+R_24;
        R_17 = R_24+R_17; R_1 = R_1*R_17; R_1 = (-1.0)*R_1; R_20 = R_1+R_20;
        R_1 = R_5*R_20; R_1 = R_1*R_9; R_24 = R_1*R_0; R_24 = (-1.0)*R_24;
        R_1 = R_1*R_13; R_1 = (-1.0)*R_1; R_25 = pow(R_20,2); R_25 = R_25*R_9;
        R_21 = R_25*R_3; R_25 = R_25*R_18; R_4 = R_7*R_20; R_4 = R_9*R_4;
        T R_26 = R_4*R_0; R_26 = (-1.0)*R_26; R_4 = R_13*R_4; R_4 = (-1.0)*R_4;
        R_10 = R_10*R_17; R_10 = (-1.0)*R_10; R_23 = R_10+R_23; R_6 = R_23+R_6;
        R_23 = R_5*R_6; R_23 = R_9*R_23; R_10 = R_23*R_0; R_10 = (-1.0)*R_10;
        R_23 = R_13*R_23; R_23 = (-1.0)*R_23; T R_27 = R_9*R_6; R_27 = R_20*R_27;
        T R_28 = R_3*R_27; R_28 = 2.0*R_28; R_27 = R_18*R_27; R_27 = 2.0*R_27;
        T R_29 = R_7*R_6; R_29 = R_29*R_9; T R_30 = R_29*R_0; R_30 = (-1.0)*R_30;
        R_29 = R_29*R_13; R_29 = (-1.0)*R_29; T R_31 = pow(R_6,2); R_31 = R_31*R_9;
        T R_32 = R_31*R_3; R_31 = R_31*R_18; R_12 = R_17*R_12; R_12 = (-1.0)*R_12;
        R_22 = R_12+R_22; R_12 = R_22*R_0; R_17 = R_2*R_12; T R_33 = R_7*R_12;
        R_33 = R_33*R_5; R_33 = 2.0*R_33; R_12 = R_8*R_12; T R_34 = R_22*R_3;
        R_34 = R_9*R_34; T R_35 = R_34*R_0; R_35 = (-2.0)*R_35; R_34 = R_13*R_34;
        R_34 = (-2.0)*R_34; R_20 = R_22*R_20; T R_36 = R_5*R_20; T R_37 = R_36*R_3;
        R_37 = (-1.0)*R_37; R_24 = R_37+R_24; R_24 = R_17+R_24; R_21 = R_24+R_21;
        coeff_resultant_U[3] = R_21; R_36 = R_36*R_18; R_36 = (-1.0)*R_36; R_20 = R_7*R_20;
        R_21 = R_3*R_20; R_21 = (-1.0)*R_21; R_28 = R_21+R_28; R_26 = R_28+R_26;
        R_36 = R_26+R_36; R_36 = R_1+R_36; R_20 = R_18*R_20; R_20 = (-1.0)*R_20;
        R_20 = R_27+R_20; R_4 = R_20+R_4; R_20 = R_22*R_13; R_2 = R_2*R_20;
        R_2 = R_15+R_2; R_15 = R_7*R_20; R_15 = R_5*R_15; R_15 = 2.0*R_15;
        R_20 = R_8*R_20; R_29 = R_20+R_29; R_6 = R_22*R_6; R_5 = R_5*R_6;
        R_20 = R_5*R_3; R_20 = (-1.0)*R_20; R_10 = R_20+R_10; R_5 = R_5*R_18;
        R_5 = (-1.0)*R_5; R_6 = R_7*R_6; R_7 = R_6*R_3; R_7 = (-1.0)*R_7;
        R_7 = R_19+R_7; R_5 = R_7+R_5; R_23 = R_5+R_23; R_6 = R_18*R_6;
        R_6 = (-1.0)*R_6; R_5 = R_22*R_18; R_5 = R_9*R_5; R_0 = R_5*R_0;
        R_0 = (-2.0)*R_0; R_12 = R_0+R_12; R_12 = R_34+R_12; R_13 = R_5*R_13;
        R_13 = (-2.0)*R_13; R_6 = R_13+R_6; R_6 = R_31+R_6; R_22 = pow(R_22,2);
        R_16 = R_16*R_22; R_35 = R_16+R_35; R_35 = R_2+R_35; R_10 = R_35+R_10;
        R_10 = R_36+R_10; R_10 = R_25+R_10; R_10 = R_33+R_10; coeff_resultant_U[2] = R_10;
        R_18 = R_18*R_22; R_3 = R_18*R_3; R_3 = 2.0*R_3; R_3 = R_30+R_3;
        R_3 = R_12+R_3; R_23 = R_3+R_23; R_23 = R_32+R_23; R_23 = R_4+R_23;
        R_23 = R_15+R_23; coeff_resultant_U[1] = R_23; R_14 = R_22*R_14; R_6 = R_14+R_6;
        R_11 = R_6+R_11; R_29 = R_11+R_29; coeff_resultant_U[0] = R_29; 
        coeff_resultant_U[4] = 0.0; 

    } else
        if ( w1 == w_max ) {
            i_pivot = 1;
            T R_0 = pos_nodes[4][2]; R_0 = 2.0*R_0; T R_1 = pos_nodes[4][1]; R_1 = 2.0*R_1;
            T R_2 = pos_nodes[4][0]; R_2 = 2.0*R_2; T R_3 = pos[0]; R_3 = (-1.0)*R_3;
            T R_4 = pos_nodes[3][0]; T R_5 = pos_nodes[2][0]; T R_6 = (-1.0)*R_5; T R_7 = pos_nodes[0][0];
            R_3 = R_7+R_3; R_4 = R_7+R_4; T R_8 = R_5+R_4; R_7 = (-1.0)*R_7;
            R_5 = R_5+R_7; T R_9 = pos_nodes[1][0]; R_8 = R_8+R_9; R_8 = -0.5*R_8;
            R_2 = R_8+R_2; R_8 = (-1.0)*R_9; R_4 = R_8+R_4; R_6 = R_4+R_6;
            R_7 = R_9+R_7; R_9 = pos_nodes[3][1]; R_4 = pos_nodes[2][1]; R_8 = (-1.0)*R_4;
            T R_10 = pos_nodes[2][2]; T R_11 = (-1.0)*R_10; T R_12 = pos_nodes[3][2]; T R_13 = R_12+R_10;
            T R_14 = pos_nodes[1][1]; T R_15 = (-1.0)*R_14; T R_16 = pos[2]; R_16 = (-1.0)*R_16;
            T R_17 = pos_nodes[1][2]; R_13 = R_17+R_13; T R_18 = (-1.0)*R_17; T R_19 = pos_nodes[0][2];
            R_13 = R_13+R_19; R_13 = -0.5*R_13; R_0 = R_13+R_0; R_12 = R_12+R_19;
            R_12 = R_18+R_12; R_11 = R_12+R_11; R_16 = R_16+R_19; R_19 = (-1.0)*R_19;
            R_10 = R_10+R_19; R_17 = R_19+R_17; R_19 = pos[1]; R_19 = (-1.0)*R_19;
            R_12 = pos_nodes[0][1]; R_18 = R_12+R_4; R_18 = R_9+R_18; R_18 = R_18+R_14;
            R_18 = -0.5*R_18; R_1 = R_18+R_1; R_18 = R_1*R_7; R_18 = (-1.0)*R_18;
            R_13 = R_1*R_17; R_13 = (-1.0)*R_13; T R_20 = R_1*R_11; R_20 = (-1.0)*R_20;
            R_1 = R_1*R_6; R_1 = (-1.0)*R_1; R_9 = R_12+R_9; R_15 = R_9+R_15;
            R_15 = R_8+R_15; R_8 = R_0*R_15; R_20 = R_8+R_20; R_8 = pow(R_20,2);
            R_9 = R_2*R_15; R_1 = R_9+R_1; R_9 = R_1*R_20; T R_21 = pow(R_1,2);
            T R_22 = R_16*R_15; T R_23 = R_15*R_5; T R_24 = R_3*R_15; R_15 = R_15*R_10;
            T R_25 = (-1.0)*R_12; R_4 = R_4+R_25; T R_26 = R_4*R_17; R_26 = (-1.0)*R_26;
            T R_27 = R_4*R_6; R_27 = (-1.0)*R_27; R_27 = R_23+R_27; R_8 = R_27*R_8;
            R_9 = R_27*R_9; R_23 = pow(R_27,2); T R_28 = R_4*R_7; R_28 = (-1.0)*R_28;
            R_4 = R_11*R_4; R_4 = (-1.0)*R_4; R_15 = R_4+R_15; R_4 = R_15*R_20;
            T R_29 = R_1*R_4; T R_30 = pow(R_15,2); R_25 = R_14+R_25; R_2 = R_2*R_25;
            R_18 = R_2+R_18; R_2 = R_18*R_8; R_14 = R_29*R_18; R_14 = (-1.0)*R_14;
            T R_31 = pow(R_18,2); R_31 = R_31*R_30; T R_32 = R_15*R_18; R_32 = R_27*R_32;
            R_0 = R_0*R_25; R_13 = R_0+R_13; R_0 = R_13*R_9; R_0 = (-1.0)*R_0;
            R_14 = R_0+R_14; R_0 = R_32*R_13; R_0 = (-2.0)*R_0; R_0 = R_31+R_0;
            R_31 = pow(R_13,2); R_31 = R_23*R_31; T R_33 = R_13*R_15; T R_34 = R_21*R_33;
            R_34 = R_14+R_34; R_2 = R_34+R_2; coeff_resultant_U[3] = R_2; R_2 = R_23*R_13;
            R_3 = R_3*R_25; R_10 = R_10*R_25; R_26 = R_10+R_26; R_5 = R_5*R_25;
            R_5 = R_28+R_5; R_25 = R_16*R_25; R_19 = R_12+R_19; R_7 = R_19*R_7;
            R_7 = (-1.0)*R_7; R_3 = R_7+R_3; R_8 = R_8*R_3; R_29 = R_29*R_3;
            R_29 = (-1.0)*R_29; R_7 = R_30*R_3; R_7 = R_18*R_7; R_7 = 2.0*R_7;
            R_12 = R_15*R_3; R_12 = R_27*R_12; R_16 = R_13*R_12; R_16 = (-2.0)*R_16;
            R_28 = pow(R_3,2); R_30 = R_28*R_30; R_11 = R_19*R_11; R_11 = (-1.0)*R_11;
            R_26 = R_11+R_26; R_22 = R_26+R_22; R_26 = R_22*R_1; R_26 = R_27*R_26;
            R_11 = R_13*R_26; R_11 = (-1.0)*R_11; R_28 = R_22*R_27; R_28 = R_28*R_20;
            R_10 = R_28*R_18; R_10 = 2.0*R_10; R_28 = R_28*R_3; R_28 = 2.0*R_28;
            R_34 = pow(R_22,2); R_34 = R_27*R_34; R_14 = R_18*R_34; R_34 = R_34*R_3;
            T R_35 = R_22*R_15; T R_36 = R_1*R_35; T R_37 = R_18*R_36; R_37 = (-1.0)*R_37;
            R_11 = R_37+R_11; R_36 = R_3*R_36; R_36 = (-1.0)*R_36; R_6 = R_19*R_6;
            R_6 = (-1.0)*R_6; R_6 = R_5+R_6; R_24 = R_6+R_24; R_6 = R_24*R_33;
            R_6 = R_1*R_6; R_6 = 2.0*R_6; R_4 = R_24*R_4; R_5 = R_4*R_18;
            R_5 = (-1.0)*R_5; R_10 = R_5+R_10; R_4 = R_4*R_3; R_4 = (-1.0)*R_4;
            R_4 = R_28+R_4; R_20 = R_24*R_20; R_20 = R_27*R_20; R_28 = R_13*R_20;
            R_28 = (-1.0)*R_28; R_10 = R_28+R_10; R_29 = R_10+R_29; R_35 = R_24*R_35;
            R_18 = R_18*R_35; R_18 = (-1.0)*R_18; R_3 = R_35*R_3; R_3 = (-1.0)*R_3;
            R_22 = R_22*R_24; R_22 = R_27*R_22; R_13 = R_13*R_22; R_13 = (-1.0)*R_13;
            R_7 = R_13+R_7; R_13 = pow(R_24,2); R_33 = R_13*R_33; R_33 = R_16+R_33;
            R_17 = R_19*R_17; R_17 = (-1.0)*R_17; R_25 = R_17+R_25; R_9 = R_25*R_9;
            R_9 = (-1.0)*R_9; R_9 = R_29+R_9; R_32 = R_25*R_32; R_32 = (-2.0)*R_32;
            R_32 = R_33+R_32; R_32 = R_7+R_32; R_2 = R_25*R_2; R_2 = 2.0*R_2;
            R_18 = R_2+R_18; R_36 = R_18+R_36; R_26 = R_25*R_26; R_26 = (-1.0)*R_26;
            R_36 = R_26+R_36; R_32 = R_36+R_32; R_14 = R_32+R_14; R_20 = R_25*R_20;
            R_20 = (-1.0)*R_20; R_4 = R_20+R_4; R_14 = R_4+R_14; R_12 = R_25*R_12;
            R_12 = (-2.0)*R_12; R_3 = R_12+R_3; R_34 = R_3+R_34; R_34 = R_30+R_34;
            R_30 = pow(R_25,2); R_30 = R_23*R_30; R_34 = R_30+R_34; R_22 = R_25*R_22;
            R_22 = (-1.0)*R_22; R_15 = R_25*R_15; R_21 = R_15*R_21; R_31 = R_21+R_31;
            R_0 = R_31+R_0; R_0 = R_11+R_0; R_9 = R_0+R_9; R_8 = R_9+R_8;
            R_6 = R_8+R_6; coeff_resultant_U[2] = R_6; R_24 = R_15*R_24; R_24 = R_1*R_24;
            R_24 = 2.0*R_24; R_14 = R_24+R_14; coeff_resultant_U[1] = R_14; R_13 = R_15*R_13;
            R_22 = R_13+R_22; R_34 = R_22+R_34; coeff_resultant_U[0] = R_34; 
            coeff_resultant_U[4] = 0.0; 

        } else {
            i_pivot = 2;
            T R_0 = pos_nodes[4][1]; R_0 = 2.0*R_0; T R_1 = pos_nodes[4][2]; R_1 = 2.0*R_1;
            T R_2 = pos_nodes[4][0]; R_2 = 2.0*R_2; T R_3 = pos[0]; R_3 = (-1.0)*R_3;
            T R_4 = pos_nodes[3][1]; T R_5 = pos_nodes[2][1]; T R_6 = (-1.0)*R_5; T R_7 = pos_nodes[3][0];
            T R_8 = pos_nodes[1][0]; T R_9 = (-1.0)*R_8; T R_10 = pos_nodes[0][0]; R_3 = R_10+R_3;
            R_7 = R_10+R_7; R_9 = R_9+R_7; R_10 = (-1.0)*R_10; T R_11 = R_8+R_10;
            T R_12 = pos_nodes[2][0]; R_7 = R_12+R_7; R_8 = R_7+R_8; R_8 = -0.5*R_8;
            R_2 = R_8+R_2; R_8 = (-1.0)*R_12; R_8 = R_9+R_8; R_10 = R_12+R_10;
            R_12 = pos_nodes[2][2]; R_9 = (-1.0)*R_12; R_7 = pos_nodes[3][2]; T R_13 = R_7+R_12;
            T R_14 = pos_nodes[1][1]; T R_15 = (-1.0)*R_14; T R_16 = pos[2]; R_16 = (-1.0)*R_16;
            T R_17 = pos_nodes[1][2]; R_13 = R_17+R_13; T R_18 = (-1.0)*R_17; T R_19 = pos_nodes[0][2];
            R_13 = R_13+R_19; R_13 = -0.5*R_13; R_1 = R_13+R_1; R_13 = R_1*R_11;
            R_13 = (-1.0)*R_13; T R_20 = R_1*R_8; R_20 = (-1.0)*R_20; R_7 = R_7+R_19;
            R_7 = R_18+R_7; R_9 = R_7+R_9; R_7 = R_2*R_9; R_20 = R_7+R_20;
            R_7 = pow(R_20,2); R_18 = R_3*R_9; T R_21 = R_9*R_10; R_16 = R_16+R_19;
            T R_22 = R_16*R_11; R_22 = (-1.0)*R_22; T R_23 = R_16*R_8; R_23 = (-1.0)*R_23;
            R_19 = (-1.0)*R_19; R_12 = R_12+R_19; R_11 = R_12*R_11; R_11 = (-1.0)*R_11;
            R_8 = R_12*R_8; R_8 = (-1.0)*R_8; R_8 = R_21+R_8; R_21 = pow(R_8,2);
            R_17 = R_19+R_17; R_2 = R_2*R_17; R_13 = R_2+R_13; R_2 = pow(R_13,2);
            R_3 = R_3*R_17; R_22 = R_3+R_22; R_3 = pow(R_22,2); R_10 = R_10*R_17;
            R_11 = R_10+R_11; R_23 = R_11+R_23; R_23 = R_18+R_23; R_18 = pow(R_23,2);
            R_11 = pos[1]; R_11 = (-1.0)*R_11; R_10 = pos_nodes[0][1]; R_19 = R_10+R_5;
            R_19 = R_4+R_19; R_19 = R_19+R_14; R_19 = -0.5*R_19; R_0 = R_19+R_0;
            R_19 = R_0*R_9; R_0 = R_0*R_17; R_4 = R_10+R_4; R_15 = R_4+R_15;
            R_15 = R_6+R_15; R_6 = R_1*R_15; R_6 = (-1.0)*R_6; R_19 = R_6+R_19;
            R_6 = pow(R_19,2); R_6 = R_8*R_6; R_4 = R_6*R_13; R_6 = R_6*R_22;
            T R_24 = R_20*R_19; R_24 = R_8*R_24; T R_25 = R_23*R_19; R_25 = R_8*R_25;
            T R_26 = R_15*R_12; R_26 = (-1.0)*R_26; R_15 = R_16*R_15; R_15 = (-1.0)*R_15;
            T R_27 = (-1.0)*R_10; R_5 = R_5+R_27; T R_28 = R_9*R_5; R_28 = R_26+R_28;
            R_26 = R_28*R_19; T R_29 = R_20*R_26; T R_30 = R_29*R_13; R_30 = (-1.0)*R_30;
            R_29 = R_29*R_22; R_29 = (-1.0)*R_29; R_26 = R_23*R_26; T R_31 = R_13*R_26;
            R_31 = (-1.0)*R_31; R_26 = R_22*R_26; R_26 = (-1.0)*R_26; T R_32 = R_28*R_13;
            R_32 = R_8*R_32; T R_33 = pow(R_28,2); R_2 = R_33*R_2; T R_34 = R_33*R_22;
            R_34 = R_34*R_13; R_34 = 2.0*R_34; R_3 = R_33*R_3; R_33 = R_28*R_22;
            R_33 = R_33*R_8; R_5 = R_5*R_17; R_27 = R_14+R_27; R_1 = R_1*R_27;
            R_1 = (-1.0)*R_1; R_0 = R_1+R_0; R_1 = R_0*R_24; R_1 = (-1.0)*R_1;
            R_1 = R_30+R_1; R_30 = R_0*R_25; R_30 = (-1.0)*R_30; R_14 = R_0*R_32;
            R_14 = (-2.0)*R_14; R_14 = R_2+R_14; R_2 = pow(R_0,2); R_2 = R_2*R_21;
            T R_35 = R_0*R_33; R_35 = (-2.0)*R_35; T R_36 = R_0*R_28; T R_37 = R_7*R_36;
            R_37 = R_1+R_37; R_4 = R_37+R_4; coeff_resultant_U[3] = R_4; R_4 = R_36*R_23;
            R_4 = R_4*R_20; R_4 = 2.0*R_4; R_36 = R_36*R_18; R_35 = R_36+R_35;
            R_36 = R_0*R_21; R_12 = R_12*R_27; R_12 = (-1.0)*R_12; R_12 = R_5+R_12;
            R_15 = R_12+R_15; R_27 = R_16*R_27; R_27 = (-1.0)*R_27; R_11 = R_10+R_11;
            R_9 = R_11*R_9; R_9 = R_15+R_9; R_15 = R_9*R_8; R_19 = R_15*R_19;
            R_15 = R_19*R_13; R_15 = 2.0*R_15; R_31 = R_15+R_31; R_30 = R_31+R_30;
            R_29 = R_30+R_29; R_19 = R_19*R_22; R_19 = 2.0*R_19; R_19 = R_26+R_19;
            R_26 = R_9*R_20; R_26 = R_26*R_8; R_30 = R_0*R_26; R_30 = (-1.0)*R_30;
            R_31 = pow(R_9,2); R_31 = R_31*R_8; R_15 = R_31*R_13; R_31 = R_31*R_22;
            R_10 = R_9*R_28; R_16 = R_10*R_20; R_12 = R_16*R_13; R_12 = (-1.0)*R_12;
            R_12 = R_30+R_12; R_16 = R_16*R_22; R_16 = (-1.0)*R_16; R_10 = R_10*R_23;
            R_13 = R_10*R_13; R_13 = (-1.0)*R_13; R_22 = R_10*R_22; R_22 = (-1.0)*R_22;
            R_9 = R_9*R_23; R_9 = R_8*R_9; R_0 = R_0*R_9; R_0 = (-1.0)*R_0;
            R_0 = R_34+R_0; R_17 = R_11*R_17; R_27 = R_17+R_27; R_24 = R_27*R_24;
            R_24 = (-1.0)*R_24; R_29 = R_24+R_29; R_25 = R_27*R_25; R_25 = (-1.0)*R_25;
            R_25 = R_19+R_25; R_32 = R_27*R_32; R_32 = (-2.0)*R_32; R_32 = R_35+R_32;
            R_32 = R_0+R_32; R_26 = R_27*R_26; R_26 = (-1.0)*R_26; R_36 = R_27*R_36;
            R_36 = 2.0*R_36; R_13 = R_36+R_13; R_16 = R_13+R_16; R_26 = R_16+R_26;
            R_32 = R_26+R_32; R_32 = R_15+R_32; R_25 = R_32+R_25; R_32 = pow(R_27,2);
            R_32 = R_21*R_32; R_33 = R_27*R_33; R_33 = (-2.0)*R_33; R_33 = R_22+R_33;
            R_31 = R_33+R_31; R_3 = R_31+R_3; R_32 = R_3+R_32; R_28 = R_27*R_28;
            R_7 = R_7*R_28; R_7 = R_2+R_7; R_14 = R_7+R_14; R_14 = R_12+R_14;
            R_29 = R_14+R_29; R_6 = R_29+R_6; R_6 = R_4+R_6; coeff_resultant_U[2] = R_6;
            R_23 = R_23*R_28; R_23 = R_20*R_23; R_23 = 2.0*R_23; R_25 = R_23+R_25;
            coeff_resultant_U[1] = R_25; R_18 = R_28*R_18; R_9 = R_27*R_9; R_9 = (-1.0)*R_9;
            R_18 = R_9+R_18; R_32 = R_18+R_32; coeff_resultant_U[0] = R_32; 
            coeff_resultant_U[4] = 0.0; 

        }
    //PRINT( i_pivot );
    //PRINT( coeff_resultant_U );
    //std::cout << scientific << " coeff_resultant_U  " << std::endl;
    //std::cout << setprecision(16) << " coeff_resultant_U  " << std::endl;
    //for( unsigned i=0; i < coeff_resultant_U.size(); ++i ) std::cout << "(" << coeff_resultant_U[i] << ") * U**" << i << " + " ;
    //std::cout << std::endl;
    sol_U = Pol<4,1,T>(coeff_resultant_U).real_roots( /*1e-2*/ /*ldexp( std::numeric_limits<T>::epsilon() , 5 )*/ );
    //PRINT( sol_U );
    //Vec< std::complex<T> > croot;
    //croot = Pol<4,1,T>(coeff_resultant_U).roots();
    //PRINT( croot );
    for( unsigned i=0; i < sol_U.size(); ++i ) {
        U = sol_U[i];
        if ((U >= -0.01) and (U <= 1.01)) {
            switch( i_pivot ) {
                case 0 : {
                    T R_0 = pos_nodes[4][2]; R_0 = 2.0*R_0; T R_1 = pos_nodes[2][2]; T R_2 = (-1.0)*R_1;
                    T R_3 = pos_nodes[3][2]; T R_4 = R_3+R_1; T R_5 = pos_nodes[1][2]; T R_6 = (-1.0)*R_5;
                    R_4 = R_5+R_4; T R_7 = pos_nodes[0][2]; R_3 = R_3+R_7; R_3 = R_6+R_3;
                    R_2 = R_3+R_2; R_4 = R_4+R_7; R_4 = -0.5*R_4; R_0 = R_4+R_0;
                    R_4 = (-1.0)*R_7; R_1 = R_1+R_4; R_5 = R_4+R_5; R_4 = pos[2];
                    R_4 = (-1.0)*R_4; R_7 = R_4+R_7; R_4 = pos_nodes[4][0]; R_4 = 2.0*R_4;
                    R_3 = pos_nodes[3][0]; R_6 = pos_nodes[2][0]; T R_8 = (-1.0)*R_6; T R_9 = pos_nodes[4][1];
                    R_9 = 2.0*R_9; T R_10 = pos_nodes[2][1]; T R_11 = (-1.0)*R_10; T R_12 = pos_nodes[3][1];
                    T R_13 = U; T R_14 = pos_nodes[1][0]; T R_15 = (-1.0)*R_14; T R_16 = pos[1];
                    R_16 = (-1.0)*R_16; T R_17 = pos_nodes[0][1]; T R_18 = R_17+R_12; T R_19 = R_17+R_10;
                    R_19 = R_12+R_19; R_16 = R_17+R_16; R_17 = (-1.0)*R_17; R_10 = R_10+R_17;
                    R_12 = pos_nodes[1][1]; T R_20 = (-1.0)*R_12; R_20 = R_18+R_20; R_20 = R_11+R_20;
                    R_19 = R_19+R_12; R_19 = -0.5*R_19; R_9 = R_19+R_9; R_17 = R_12+R_17;
                    R_12 = pos[0]; R_12 = (-1.0)*R_12; R_19 = pos_nodes[0][0]; R_3 = R_19+R_3;
                    R_15 = R_15+R_3; R_8 = R_15+R_8; R_15 = R_1*R_8; R_11 = R_0*R_8;
                    R_18 = R_7*R_8; T R_21 = R_10*R_8; T R_22 = R_9*R_8; R_8 = R_16*R_8;
                    R_3 = R_6+R_3; R_3 = R_3+R_14; R_3 = -0.5*R_3; R_4 = R_3+R_4;
                    R_3 = R_4*R_2; R_3 = (-1.0)*R_3; R_11 = R_3+R_11; R_11 = R_11*R_13;
                    R_3 = R_4*R_5; R_3 = (-1.0)*R_3; T R_23 = R_4*R_20; R_23 = (-1.0)*R_23;
                    R_23 = R_22+R_23; R_23 = R_23*R_13; R_4 = R_4*R_17; R_4 = (-1.0)*R_4;
                    R_22 = (-1.0)*R_19; R_6 = R_6+R_22; T R_24 = R_2*R_6; R_24 = (-1.0)*R_24;
                    R_15 = R_24+R_15; coeff_V2[2] = R_15; R_15 = R_6*R_5; R_15 = (-1.0)*R_15;
                    R_24 = R_20*R_6; R_24 = (-1.0)*R_24; R_24 = R_21+R_24; coeff_V[2] = R_24;
                    R_6 = R_6*R_17; R_6 = (-1.0)*R_6; R_22 = R_14+R_22; R_1 = R_1*R_22;
                    R_1 = R_15+R_1; R_0 = R_0*R_22; R_3 = R_0+R_3; R_3 = R_13*R_3;
                    R_7 = R_7*R_22; R_10 = R_10*R_22; R_6 = R_10+R_6; R_9 = R_9*R_22;
                    R_4 = R_9+R_4; R_4 = R_13*R_4; R_22 = R_16*R_22; R_12 = R_19+R_12;
                    R_2 = R_12*R_2; R_2 = (-1.0)*R_2; R_1 = R_2+R_1; R_18 = R_1+R_18;
                    R_11 = R_18+R_11; coeff_V2[1] = R_11; R_5 = R_12*R_5; R_5 = (-1.0)*R_5;
                    R_5 = R_7+R_5; R_3 = R_5+R_3; coeff_V2[0] = R_3; R_20 = R_12*R_20;
                    R_20 = (-1.0)*R_20; R_6 = R_20+R_6; R_8 = R_6+R_8; R_23 = R_8+R_23;
                    coeff_V[1] = R_23; R_17 = R_12*R_17; R_17 = (-1.0)*R_17; R_22 = R_17+R_22;
                    R_4 = R_22+R_4; coeff_V[0] = R_4; 

                    if ( norm_inf( coeff_V2 ) > norm_inf( coeff_V ) )  coeff_V = coeff_V2; 
                } break; /// i_pivot == 0
                case 1 : {
                    T R_0 = pos_nodes[4][2]; R_0 = 2.0*R_0; T R_1 = pos_nodes[2][2]; T R_2 = (-1.0)*R_1;
                    T R_3 = pos_nodes[3][2]; T R_4 = R_3+R_1; T R_5 = pos[2]; R_5 = (-1.0)*R_5;
                    T R_6 = pos_nodes[1][2]; T R_7 = (-1.0)*R_6; R_4 = R_6+R_4; T R_8 = pos_nodes[0][2];
                    R_3 = R_3+R_8; R_3 = R_7+R_3; R_2 = R_3+R_2; R_4 = R_4+R_8;
                    R_4 = -0.5*R_4; R_0 = R_4+R_0; R_5 = R_5+R_8; R_8 = (-1.0)*R_8;
                    R_1 = R_1+R_8; R_6 = R_8+R_6; R_8 = pos[0]; R_8 = (-1.0)*R_8;
                    R_4 = pos[1]; R_4 = (-1.0)*R_4; R_3 = U; R_7 = pos_nodes[4][1];
                    R_7 = 2.0*R_7; T R_9 = pos_nodes[2][1]; T R_10 = (-1.0)*R_9; T R_11 = pos_nodes[3][1];
                    T R_12 = pos_nodes[0][1]; T R_13 = R_12+R_11; R_4 = R_12+R_4; T R_14 = R_4*R_2;
                    R_14 = (-1.0)*R_14; T R_15 = R_4*R_6; R_15 = (-1.0)*R_15; T R_16 = R_12+R_9;
                    R_16 = R_11+R_16; R_12 = (-1.0)*R_12; R_9 = R_9+R_12; R_11 = R_2*R_9;
                    R_11 = (-1.0)*R_11; T R_17 = R_9*R_6; R_17 = (-1.0)*R_17; T R_18 = pos_nodes[1][1];
                    T R_19 = (-1.0)*R_18; R_19 = R_13+R_19; R_19 = R_10+R_19; R_10 = R_19*R_1;
                    R_10 = R_11+R_10; coeff_V2[2] = R_10; R_10 = R_0*R_19; R_11 = R_5*R_19;
                    R_16 = R_16+R_18; R_16 = -0.5*R_16; R_7 = R_16+R_7; R_2 = R_7*R_2;
                    R_2 = (-1.0)*R_2; R_2 = R_10+R_2; R_2 = R_3*R_2; R_6 = R_7*R_6;
                    R_6 = (-1.0)*R_6; R_12 = R_18+R_12; R_1 = R_1*R_12; R_17 = R_1+R_17;
                    R_17 = R_14+R_17; R_11 = R_17+R_11; R_2 = R_11+R_2; coeff_V2[1] = R_2;
                    R_0 = R_0*R_12; R_6 = R_0+R_6; R_6 = R_6*R_3; R_5 = R_5*R_12;
                    R_5 = R_15+R_5; R_6 = R_5+R_6; coeff_V2[0] = R_6; R_6 = pos_nodes[4][0];
                    R_6 = 2.0*R_6; R_5 = pos_nodes[1][0]; R_15 = (-1.0)*R_5; R_0 = pos_nodes[3][0];
                    R_2 = pos_nodes[0][0]; R_8 = R_2+R_8; R_11 = R_8*R_19; R_8 = R_8*R_12;
                    R_17 = (-1.0)*R_2; R_14 = R_5+R_17; R_1 = R_9*R_14; R_1 = (-1.0)*R_1;
                    R_18 = R_4*R_14; R_18 = (-1.0)*R_18; R_8 = R_18+R_8; R_14 = R_7*R_14;
                    R_14 = (-1.0)*R_14; R_0 = R_2+R_0; R_15 = R_15+R_0; R_2 = pos_nodes[2][0];
                    R_18 = (-1.0)*R_2; R_18 = R_15+R_18; R_9 = R_9*R_18; R_9 = (-1.0)*R_9;
                    R_7 = R_7*R_18; R_7 = (-1.0)*R_7; R_18 = R_4*R_18; R_18 = (-1.0)*R_18;
                    R_17 = R_2+R_17; R_4 = R_19*R_17; R_9 = R_4+R_9; coeff_V[2] = R_9;
                    R_17 = R_17*R_12; R_17 = R_1+R_17; R_18 = R_17+R_18; R_11 = R_18+R_11;
                    R_0 = R_2+R_0; R_5 = R_0+R_5; R_5 = -0.5*R_5; R_6 = R_5+R_6;
                    R_19 = R_6*R_19; R_7 = R_19+R_7; R_7 = R_7*R_3; R_7 = R_11+R_7;
                    coeff_V[1] = R_7; R_12 = R_6*R_12; R_14 = R_12+R_14; R_3 = R_14*R_3;
                    R_8 = R_3+R_8; coeff_V[0] = R_8; 

                    if ( norm_inf( coeff_V2 ) > norm_inf( coeff_V ) )  coeff_V = coeff_V2; 
                } break; /// i_pivot == 1
                case 2 : {
                             {
                    T R_0 = pos_nodes[4][1]; R_0 = 2.0*R_0; T R_1 = pos_nodes[2][1]; T R_2 = (-1.0)*R_1;
                    T R_3 = pos_nodes[3][1]; T R_4 = pos_nodes[1][1]; T R_5 = (-1.0)*R_4; T R_6 = pos[1];
                    R_6 = (-1.0)*R_6; T R_7 = pos_nodes[0][1]; T R_8 = R_7+R_3; R_5 = R_8+R_5;
                    R_5 = R_2+R_5; R_2 = R_7+R_1; R_2 = R_3+R_2; R_2 = R_2+R_4;
                    R_2 = -0.5*R_2; R_0 = R_2+R_0; R_2 = (-1.0)*R_7; R_1 = R_1+R_2;
                    R_2 = R_4+R_2; R_6 = R_7+R_6; R_7 = pos[2]; R_7 = (-1.0)*R_7;
                    R_4 = pos[0]; R_4 = (-1.0)*R_4; R_3 = U; R_8 = pos_nodes[4][2];
                    R_8 = 2.0*R_8; T R_9 = pos_nodes[2][2]; T R_10 = (-1.0)*R_9; T R_11 = pos_nodes[3][2];
                    T R_12 = R_11+R_9; T R_13 = pos_nodes[1][2]; T R_14 = (-1.0)*R_13; R_12 = R_13+R_12;
                    T R_15 = pos_nodes[0][2]; R_11 = R_11+R_15; R_11 = R_14+R_11; R_10 = R_11+R_10;
                    R_11 = R_10*R_1; R_14 = R_0*R_10; T R_16 = R_6*R_10; R_7 = R_7+R_15;
                    T R_17 = R_7*R_5; R_17 = (-1.0)*R_17; T R_18 = R_7*R_2; R_18 = (-1.0)*R_18;
                    R_12 = R_12+R_15; R_12 = -0.5*R_12; R_8 = R_12+R_8; R_12 = R_8*R_5;
                    R_12 = (-1.0)*R_12; R_14 = R_12+R_14; R_14 = R_3*R_14; R_12 = R_8*R_2;
                    R_12 = (-1.0)*R_12; R_15 = (-1.0)*R_15; R_9 = R_9+R_15; R_5 = R_5*R_9;
                    R_5 = (-1.0)*R_5; R_11 = R_5+R_11; coeff_V2[2] = R_11; R_2 = R_9*R_2;
                    R_2 = (-1.0)*R_2; R_13 = R_15+R_13; R_1 = R_1*R_13; R_2 = R_1+R_2;
                    R_17 = R_2+R_17; R_16 = R_17+R_16; R_14 = R_16+R_14; coeff_V2[1] = R_14;
                    R_0 = R_0*R_13; R_0 = R_12+R_0; R_0 = R_0*R_3; R_6 = R_6*R_13;
                    R_18 = R_6+R_18; R_0 = R_18+R_0; coeff_V2[0] = R_0; R_0 = pos_nodes[4][0];
                    R_0 = 2.0*R_0; R_18 = pos_nodes[1][0]; R_6 = (-1.0)*R_18; R_12 = pos_nodes[3][0];
                    R_14 = pos_nodes[0][0]; R_4 = R_14+R_4; R_16 = R_4*R_10; R_4 = R_4*R_13;
                    R_17 = (-1.0)*R_14; R_2 = R_18+R_17; R_1 = R_9*R_2; R_1 = (-1.0)*R_1;
                    R_15 = R_7*R_2; R_15 = (-1.0)*R_15; R_15 = R_4+R_15; R_2 = R_8*R_2;
                    R_2 = (-1.0)*R_2; R_12 = R_14+R_12; R_6 = R_6+R_12; R_14 = pos_nodes[2][0];
                    R_17 = R_14+R_17; R_4 = R_10*R_17; R_17 = R_17*R_13; R_1 = R_17+R_1;
                    R_17 = (-1.0)*R_14; R_17 = R_6+R_17; R_9 = R_9*R_17; R_9 = (-1.0)*R_9;
                    R_9 = R_4+R_9; coeff_V[2] = R_9; R_7 = R_7*R_17; R_7 = (-1.0)*R_7;
                    R_7 = R_1+R_7; R_7 = R_16+R_7; R_17 = R_8*R_17; R_17 = (-1.0)*R_17;
                    R_12 = R_14+R_12; R_18 = R_12+R_18; R_18 = -0.5*R_18; R_0 = R_18+R_0;
                    R_10 = R_0*R_10; R_17 = R_10+R_17; R_17 = R_17*R_3; R_7 = R_17+R_7;
                    coeff_V[1] = R_7; R_13 = R_0*R_13; R_2 = R_13+R_2; R_3 = R_2*R_3;
                    R_15 = R_3+R_15; coeff_V[0] = R_15; 

                             }
                    if ( norm_inf( coeff_V2 ) > norm_inf( coeff_V ) )  coeff_V = coeff_V2; 
                } break; /// i_pivot == 2
            } /// switch i_pivot
            sol_V = Pol<2,1,T>( coeff_V ).real_roots( /*1e-2*/ ldexp( std::numeric_limits<T>::epsilon() , 10 ) );
            //PRINT( U ); PRINT( coeff_V );
            //std::cout << setprecision(16) << " coeff_V  " << std::endl;
            //for( unsigned i=0; i < coeff_V.size(); ++i ) std::cout << "(" << coeff_V[i] << ") * V**" << i << " + " ;
            //std::cout << std::endl;
            //PRINT( sol_V );
            for( unsigned j=0; j < sol_V.size(); ++j ) {
                V = sol_V[j];
                if ( (V >= -0.01) and ( V <= 1.01) ){
                    switch( i_pivot ) {
                        case 0 : {
                        T R_0 = pos[0]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[3][0]; T R_2 = pos_nodes[4][0];
                        T R_3 = pos_nodes[0][0]; T R_4 = pos_nodes[1][0]; T R_5 = V; T R_6 = R_1*R_5;
                        T R_7 = (-1.0)+R_5; R_7 = R_3*R_7; R_6 = R_7+R_6; R_7 = (-1.0)*R_5;
                        T R_8 = 1.0+R_7; R_8 = R_4*R_8; R_6 = R_8+R_6; R_8 = U;
                        R_1 = R_1*R_8; R_1 = -0.5*R_1; R_2 = R_2*R_8; R_2 = 2.0*R_2;
                        R_1 = R_2+R_1; R_4 = R_4*R_8; R_4 = -0.5*R_4; R_8 = -0.5*R_8;
                        R_7 = R_8+R_7; R_7 = 1.0+R_7; R_7 = R_3*R_7; R_1 = R_7+R_1;
                        R_1 = R_4+R_1; R_8 = R_8+R_5; R_4 = pos_nodes[2][0]; R_5 = R_4*R_5;
                        R_5 = (-1.0)*R_5; R_6 = R_5+R_6; coeff_W[1] = R_6; R_8 = R_4*R_8;
                        R_1 = R_8+R_1; R_0 = R_1+R_0; coeff_W[0] = R_0; 

                        } break; /// i_pivot == 0
                        case 1 : {
                        T R_0 = pos[1]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[2][1]; T R_2 = V;
                        T R_3 = R_1*R_2; R_3 = (-1.0)*R_3; T R_4 = (-1.0)+R_2; T R_5 = (-1.0)*R_2;
                        T R_6 = 1.0+R_5; T R_7 = pos_nodes[0][1]; R_4 = R_7*R_4; T R_8 = pos_nodes[4][1];
                        T R_9 = pos_nodes[3][1]; T R_10 = R_9*R_2; R_4 = R_10+R_4; R_10 = U;
                        T R_11 = -0.5*R_10; R_2 = R_11+R_2; R_2 = R_1*R_2; R_5 = R_11+R_5;
                        R_5 = 1.0+R_5; R_5 = R_7*R_5; R_8 = R_8*R_10; R_8 = 2.0*R_8;
                        R_9 = R_9*R_10; R_9 = -0.5*R_9; R_8 = R_9+R_8; R_5 = R_8+R_5;
                        R_8 = pos_nodes[1][1]; R_6 = R_8*R_6; R_4 = R_6+R_4; R_3 = R_4+R_3;
                        coeff_W[1] = R_3; R_10 = R_8*R_10; R_10 = -0.5*R_10; R_5 = R_10+R_5;
                        R_2 = R_5+R_2; R_0 = R_2+R_0; coeff_W[0] = R_0; 

                        } break; /// i_pivot == 1
                        case 2 : {
                        T R_0 = pos[2]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[2][2]; T R_2 = V;
                        T R_3 = (-1.0)+R_2; T R_4 = R_1*R_2; R_4 = (-1.0)*R_4; T R_5 = (-1.0)*R_2;
                        T R_6 = 1.0+R_5; T R_7 = pos_nodes[0][2]; R_3 = R_7*R_3; T R_8 = pos_nodes[4][2];
                        T R_9 = pos_nodes[3][2]; T R_10 = R_9*R_2; R_3 = R_10+R_3; R_10 = U;
                        T R_11 = -0.5*R_10; R_2 = R_11+R_2; R_2 = R_1*R_2; R_5 = R_11+R_5;
                        R_5 = 1.0+R_5; R_5 = R_7*R_5; R_8 = R_8*R_10; R_8 = 2.0*R_8;
                        R_9 = R_9*R_10; R_9 = -0.5*R_9; R_8 = R_9+R_8; R_5 = R_8+R_5;
                        R_8 = pos_nodes[1][2]; R_6 = R_8*R_6; R_3 = R_6+R_3; R_3 = R_4+R_3;
                        coeff_W[1] = R_3; R_10 = R_8*R_10; R_10 = -0.5*R_10; R_5 = R_10+R_5;
                        R_2 = R_5+R_2; R_0 = R_2+R_0; coeff_W[0] = R_0; 

                        } break; /// i_pivot == 2
                    } /// switch i_pivot
                    sol_W = Pol<1,1,T>( coeff_W ).real_roots( 1e-2 );
                    //PRINT( sol_W );
                    for( unsigned k=0; k < sol_W.size(); ++k ) {
                        W = sol_W[k];
                        TVI vi( U, V, W );
                        //PRINT( vi );
                        if ( var_inter_is_inside( Pyramid(), vi, 0.25 ) ) {
                            for( unsigned t=0; t<3; ++t ) { /// méthode de Newton-Raphson
                                T R_0 = pos[1]; R_0 = (-1.0)*R_0; T R_1 = pos[2]; R_1 = (-1.0)*R_1;
                                T R_2 = pos_nodes[4][2]; T R_3 = 2.0*R_2; T R_4 = pos_nodes[2][2]; T R_5 = (-1.0)*R_4;
                                T R_6 = pos_nodes[3][2]; T R_7 = R_6+R_4; R_5 = R_6+R_5; T R_8 = pos_nodes[0][2];
                                T R_9 = pos_nodes[1][2]; R_7 = R_9+R_7; R_7 = R_7+R_8; R_7 = -0.5*R_7;
                                R_3 = R_7+R_3; R_7 = (-1.0)*R_9; R_7 = R_6+R_7; T R_10 = pos[0];
                                R_10 = (-1.0)*R_10; T R_11 = U; R_2 = R_2*R_11; R_2 = 2.0*R_2;
                                T R_12 = R_3*R_11; T R_13 = -0.5*R_11; T R_14 = pos_nodes[4][1]; T R_15 = R_14*R_11;
                                R_15 = 2.0*R_15; R_14 = 2.0*R_14; T R_16 = pos_nodes[1][1]; T R_17 = (-1.0)*R_16;
                                T R_18 = pos_nodes[2][1]; T R_19 = (-1.0)*R_18; T R_20 = pos_nodes[0][1]; T R_21 = R_20+R_18;
                                T R_22 = pos_nodes[3][1]; R_19 = R_22+R_19; R_17 = R_22+R_17; R_21 = R_22+R_21;
                                R_21 = R_21+R_16; R_21 = -0.5*R_21; R_14 = R_21+R_14; R_21 = V;
                                R_19 = R_19*R_21; R_5 = R_5*R_21; T R_23 = (-1.0)+R_21; T R_24 = R_20*R_23;
                                T R_25 = R_8*R_23; T R_26 = (-1.0)*R_21; R_26 = 1.0+R_26; T R_27 = R_16*R_26;
                                T R_28 = R_27+R_24; R_28 = R_28+R_19; T R_29 = R_9*R_26; T R_30 = R_29+R_25;
                                R_30 = R_30+R_5; T R_31 = W; R_28 = R_31*R_28; R_17 = R_17*R_31;
                                R_7 = R_31*R_7; R_30 = R_31*R_30; T R_32 = R_21*R_31; R_32 = R_13+R_32;
                                R_22 = R_32*R_22; R_15 = R_22+R_15; R_6 = R_6*R_32; R_6 = R_2+R_6;
                                R_2 = R_31*R_26; R_2 = R_13+R_2; R_16 = R_16*R_2; R_9 = R_9*R_2;
                                R_22 = (-1.0)*R_31; T R_33 = 1.0+R_22; T R_34 = R_18*R_33; T R_35 = R_4*R_33;
                                T R_36 = R_21*R_33; R_36 = R_13+R_36; R_18 = R_18*R_36; R_4 = R_4*R_36;
                                T R_37 = (-1.0)+R_31; T R_38 = R_20*R_37; T R_39 = R_38+R_34; R_39 = R_39+R_17;
                                R_39 = R_39*R_21; R_28 = R_39+R_28; R_39 = R_37*R_8; T R_40 = R_35+R_39;
                                R_40 = R_40+R_7; R_40 = R_40*R_21; T R_41 = R_21*R_37; R_41 = R_13+R_41;
                                R_41 = R_22+R_41; R_41 = 1.0+R_41; R_20 = R_20*R_41; R_20 = R_15+R_20;
                                R_16 = R_20+R_16; R_16 = R_18+R_16; R_0 = R_16+R_0; R_0 = (-1.0)*R_0;
                                R_0 = R_28+R_0; R_8 = R_41*R_8; R_6 = R_8+R_6; R_6 = R_9+R_6;
                                R_4 = R_6+R_4; R_1 = R_4+R_1; R_1 = (-1.0)*R_1; R_1 = R_12+R_1;
                                R_1 = R_40+R_1; R_1 = R_30+R_1; R_30 = pos_nodes[4][0]; R_40 = R_30*R_11;
                                R_40 = 2.0*R_40; R_30 = 2.0*R_30; R_12 = pos_nodes[1][0]; R_2 = R_12*R_2;
                                R_26 = R_12*R_26; R_4 = (-1.0)*R_12; R_6 = pos_nodes[3][0]; R_32 = R_32*R_6;
                                R_40 = R_32+R_40; R_4 = R_6+R_4; R_4 = R_31*R_4; R_32 = pos_nodes[0][0];
                                R_41 = R_32*R_41; R_40 = R_41+R_40; R_40 = R_2+R_40; R_23 = R_32*R_23;
                                R_23 = R_26+R_23; R_37 = R_32*R_37; R_32 = R_32+R_6; R_26 = pos_nodes[2][0];
                                R_36 = R_26*R_36; R_36 = R_40+R_36; R_10 = R_36+R_10; R_10 = (-1.0)*R_10;
                                R_36 = (-1.0)*R_26; R_36 = R_6+R_36; R_36 = R_21*R_36; R_23 = R_36+R_23;
                                R_36 = R_23*R_31; R_33 = R_26*R_33; R_33 = R_37+R_33; R_4 = R_33+R_4;
                                R_33 = R_21*R_4; R_32 = R_26+R_32; R_12 = R_32+R_12; R_12 = -0.5*R_12;
                                R_30 = R_12+R_30; R_12 = R_30*R_11; R_12 = R_10+R_12; R_33 = R_33+R_12;
                                R_33 = R_36+R_33; R_30 = 1/R_30; R_36 = R_14*R_30; R_10 = R_23*R_36;
                                R_10 = (-1.0)*R_10; R_10 = R_27+R_10; R_10 = R_24+R_10; R_10 = R_19+R_10;
                                R_36 = R_4*R_36; R_36 = (-1.0)*R_36; R_36 = R_38+R_36; R_34 = R_36+R_34;
                                R_34 = R_17+R_34; R_34 = 1/R_34; R_3 = R_3*R_30; R_17 = R_23*R_3;
                                R_36 = R_33*R_3; R_3 = R_4*R_3; R_3 = (-1.0)*R_3; R_35 = R_3+R_35;
                                R_39 = R_35+R_39; R_39 = R_7+R_39; R_39 = R_39*R_34; R_7 = R_39*R_10;
                                R_7 = R_17+R_7; R_7 = (-1.0)*R_7; R_7 = R_29+R_7; R_7 = R_25+R_7;
                                R_7 = R_5+R_7; R_7 = 1/R_7; R_33 = R_33*R_30; R_33 = (-1.0)*R_33;
                                R_33 = R_11+R_33; R_33 = R_14*R_33; R_14 = R_33+R_0; R_14 = R_39*R_14;
                                R_36 = R_14+R_36; R_36 = (-1.0)*R_36; R_36 = R_1+R_36; R_7 = R_36*R_7;
                                W2 = R_7; R_36 = (-1.0)*R_7; R_36 = R_31+R_36; R_23 = R_36*R_23;
                                R_23 = R_12+R_23; R_10 = R_7*R_10; R_10 = (-1.0)*R_10; R_0 = R_10+R_0;
                                R_0 = R_33+R_0; R_34 = R_0*R_34; V2 = R_34; R_34 = (-1.0)*R_34;
                                R_34 = R_21+R_34; R_34 = R_4*R_34; R_23 = R_34+R_23; R_23 = R_30*R_23;
                                U2 = R_23; 

                                T err = 1 + abs(U) + abs(V) + abs(W); err = (abs(U-U2) + abs(V-V2) + abs(W-W2)) / err;
                                U = U2; V = V2; W = W2;
                                if (err < tolerance ) break;
                                //std::cout << "- " << t << std::endl; PRINT( U - 0.7 ); PRINT( V - 0.88 ); PRINT( W - 0.9 ); // PRINT( U ); PRINT( V ); PRINT( W );
                            }  /// for de la méthode de Newton-Raphson
                            T R_0 = pos[2]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[2][2]; T R_2 = pos_nodes[3][2];
                            T R_3 = pos_nodes[4][2]; T R_4 = pos_nodes[0][2]; T R_5 = pos_nodes[1][2]; T R_6 = pos[1];
                            R_6 = (-1.0)*R_6; T R_7 = pos_nodes[1][1]; T R_8 = pos_nodes[0][1]; T R_9 = pos_nodes[4][1];
                            T R_10 = pos_nodes[3][1]; T R_11 = pos_nodes[2][1]; T R_12 = pos[0]; R_12 = (-1.0)*R_12;
                            T R_13 = pos_nodes[2][0]; T R_14 = pos_nodes[4][0]; T R_15 = pos_nodes[3][0]; T R_16 = pos_nodes[0][0];
                            T R_17 = V; T R_18 = (-1.0)*R_17; R_18 = 1.0+R_18; T R_19 = W;
                            T R_20 = R_17*R_19; T R_21 = (-1.0)+R_19; R_21 = R_17*R_21; T R_22 = (-1.0)*R_19;
                            T R_23 = 1.0+R_22; R_23 = R_17*R_23; R_18 = R_19*R_18; R_19 = U;
                            R_3 = R_3*R_19; R_3 = 2.0*R_3; R_9 = R_9*R_19; R_9 = 2.0*R_9;
                            R_14 = R_14*R_19; R_14 = 2.0*R_14; R_19 = -0.5*R_19; R_23 = R_19+R_23;
                            R_1 = R_1*R_23; R_11 = R_11*R_23; R_23 = R_13*R_23; R_20 = R_19+R_20;
                            R_2 = R_2*R_20; R_2 = R_3+R_2; R_10 = R_20*R_10; R_9 = R_10+R_9;
                            R_15 = R_20*R_15; R_14 = R_15+R_14; R_21 = R_19+R_21; R_21 = R_22+R_21;
                            R_21 = 1.0+R_21; R_4 = R_21*R_4; R_2 = R_4+R_2; R_8 = R_8*R_21;
                            R_8 = R_9+R_8; R_21 = R_16*R_21; R_14 = R_21+R_14; R_18 = R_19+R_18;
                            R_5 = R_5*R_18; R_2 = R_5+R_2; R_1 = R_2+R_1; R_0 = R_1+R_0;
                            eval3 = R_0; R_7 = R_7*R_18; R_7 = R_8+R_7; R_7 = R_11+R_7;
                            R_6 = R_7+R_6; eval2 = R_6; R_6 = pos_nodes[1][0]; R_18 = R_6*R_18;
                            R_14 = R_18+R_14; R_23 = R_14+R_23; R_12 = R_23+R_12; eval = R_12;

                            //PRINT( eval ); PRINT( eval2 ); PRINT( eval3 ); PRINT( U ); PRINT( V ); PRINT( W );
                            if ( ( err = max( abs(eval), abs(eval2), abs(eval3) ) ) < tolerance ) {
                                //PRINT( TVI( U, V, W ) ); PRINT( err );
                                if ( err < err_vi ) {
                                    sol_vi = TVI( U, V, W );
                                    err_vi = err;
                                }
                            }
                        } /// if var_inter_is_inside 
                    } /// for sol_W
                } /// endif V in [0;1]
            } /// for sol_V
        } /// endif U in [0;1]
    } /// for sur sol_U
    
    var_inter += sol_vi;
    if ( err_vi < 0.1 )
        return true;
    else
        return false;
}
}
#endif  /// GET_VAR_INTER__Pyramid
 
