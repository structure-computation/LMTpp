#ifndef GET_VAR_INTER__Triangle_6_H
#define GET_VAR_INTER__Triangle_6_H
 
#include <containers/polynomials.h>
 
 
namespace LMT {
 
template<class PosNodes,class Pvec,class TVI>
bool get_var_inter_experimental(const Triangle_6 &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter, typename Pvec::template SubType<0>::T tolerance = 1e-7 ) {
    typedef typename Pvec::template SubType<0>::T T;
    T U, V, eval, eval2, U2, V2;
    Vec< T, 5 > coeff_resultant_U;
    Vec< T, 3 > coeff_V;
    Vec< T > sol_U, sol_V;
    Vec< Vec< T >, 2 > coeff_poly;
    Vec< Vec< T, 2 > > sol_poly;
    bool isSolution;

    /// on résout le problème s'il est "quasi-linéaire"
    coeff_poly[0].resize(6);
    coeff_poly[1].resize(6);
    {
    T R_0 = pos_nodes[4][1]; R_0 = 4.0*R_0; T R_1 = pos_nodes[5][1]; T R_2 = (-4.0)*R_1;
    R_0 = R_0+R_2; R_1 = 4.0*R_1; T R_3 = pos_nodes[2][1]; T R_4 = 2.0*R_3;
    R_3 = (-1.0)*R_3; T R_5 = pos_nodes[3][1]; T R_6 = (-4.0)*R_5; R_5 = 4.0*R_5;
    T R_7 = pos_nodes[1][1]; T R_8 = 2.0*R_7; R_7 = (-1.0)*R_7; T R_9 = pos[1];
    R_9 = (-1.0)*R_9; T R_10 = pos_nodes[0][1]; T R_11 = 4.0*R_10; R_11 = R_6+R_11;
    R_0 = R_11+R_0; coeff_poly[1][4] = R_0; R_0 = 2.0*R_10; R_4 = R_4+R_0;
    R_2 = R_4+R_2; coeff_poly[1][5] = R_2; R_0 = R_8+R_0; R_0 = R_6+R_0;
    coeff_poly[1][3] = R_0; R_0 = (-3.0)*R_10; R_3 = R_3+R_0; R_1 = R_3+R_1;
    coeff_poly[1][2] = R_1; R_0 = R_7+R_0; R_5 = R_0+R_5; coeff_poly[1][1] = R_5;
    R_9 = R_10+R_9; coeff_poly[1][0] = R_9; R_9 = pos_nodes[4][0]; R_9 = 4.0*R_9;
    R_10 = pos_nodes[5][0]; R_5 = (-4.0)*R_10; R_9 = R_5+R_9; R_10 = 4.0*R_10;
    R_0 = pos_nodes[2][0]; R_7 = 2.0*R_0; R_0 = (-1.0)*R_0; R_1 = pos_nodes[1][0];
    R_3 = 2.0*R_1; R_1 = (-1.0)*R_1; R_6 = pos_nodes[3][0]; R_8 = (-4.0)*R_6;
    R_6 = 4.0*R_6; R_2 = pos_nodes[0][0]; R_4 = 4.0*R_2; R_4 = R_4+R_8;
    R_4 = R_9+R_4; coeff_poly[0][4] = R_4; R_4 = 2.0*R_2; R_7 = R_7+R_4;
    R_5 = R_7+R_5; coeff_poly[0][5] = R_5; R_3 = R_4+R_3; R_3 = R_8+R_3;
    coeff_poly[0][3] = R_3; R_3 = (-3.0)*R_2; R_0 = R_0+R_3; R_10 = R_0+R_10;
    coeff_poly[0][2] = R_10; R_3 = R_1+R_3; R_3 = R_6+R_3; coeff_poly[0][1] = R_3;
    R_3 = pos[0]; R_3 = (-1.0)*R_3; R_2 = R_3+R_2; coeff_poly[0][0] = R_2;

    }
    if (solve_quasi_linear_polynomial_system_2X( coeff_poly, sol_poly, tolerance ) )
        for( unsigned i=0; i< sol_poly.size(); ++i) 
            if ( var_inter_is_inside( Triangle_6(), sol_poly[i], tolerance ) ) {
                var_inter += sol_poly[i];
                return true;
            }


    
    T R_0 = pos_nodes[4][0]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[1][1]; T R_2 = (-1.0)*R_1;
    T R_3 = pos_nodes[1][0]; T R_4 = (-1.0)*R_3; T R_5 = pos_nodes[3][0]; T R_6 = (-4.0)*R_5;
    T R_7 = 4.0*R_5; T R_8 = pos_nodes[4][1]; R_8 = (-1.0)*R_8; T R_9 = pos_nodes[3][1];
    T R_10 = (-8.0)*R_9; T R_11 = (-4.0)*R_9; T R_12 = 4.0*R_9; T R_13 = pos[0];
    R_13 = (-1.0)*R_13; T R_14 = pos_nodes[5][1]; T R_15 = (-4.0)*R_14; T R_16 = (-8.0)*R_14;
    T R_17 = 4.0*R_14; T R_18 = pos_nodes[2][1]; T R_19 = (-1.0)*R_18; T R_20 = pos_nodes[5][0];
    T R_21 = (-8.0)*R_20; T R_22 = 4.0*R_20; T R_23 = (-4.0)*R_20; T R_24 = pos_nodes[2][0];
    T R_25 = (-1.0)*R_24; T R_26 = pos_nodes[0][0]; R_3 = R_26+R_3; R_3 = 2.0*R_3;
    R_6 = R_3+R_6; R_3 = pow(R_6,2); T R_27 = (-1.0)*R_26; R_27 = R_0+R_27;
    R_5 = R_27+R_5; R_20 = R_5+R_20; R_5 = pow(R_20,2); R_27 = (-3.0)*R_26;
    R_4 = R_4+R_27; R_4 = R_7+R_4; R_7 = pow(R_4,2); R_27 = R_25+R_27;
    R_22 = R_27+R_22; R_27 = pow(R_22,2); R_13 = R_13+R_26; R_25 = pow(R_13,2);
    R_24 = R_26+R_24; R_26 = 4.0*R_24; R_26 = R_21+R_26; R_24 = 2.0*R_24;
    R_23 = R_24+R_23; R_24 = pow(R_23,2); R_21 = pos[1]; R_21 = (-1.0)*R_21;
    R_0 = pos_nodes[0][1]; R_1 = R_1+R_0; T R_28 = 4.0*R_1; R_28 = R_10+R_28;
    R_1 = 2.0*R_1; R_1 = R_11+R_1; R_11 = pow(R_1,2); R_11 = R_24*R_11;
    R_10 = R_24*R_1; T R_29 = (-1.0)*R_0; R_9 = R_29+R_9; R_8 = R_9+R_8;
    R_14 = R_8+R_14; R_8 = pow(R_14,2); R_8 = R_23*R_8; R_9 = R_8*R_6;
    R_9 = 16.0*R_9; R_29 = R_4*R_8; R_29 = 16.0*R_29; R_8 = R_8*R_13;
    R_8 = 16.0*R_8; T R_30 = R_20*R_14; R_30 = R_23*R_30; T R_31 = R_1*R_30;
    R_31 = (-16.0)*R_31; T R_32 = R_22*R_14; R_32 = R_23*R_32; T R_33 = R_1*R_32;
    R_33 = 4.0*R_33; R_18 = R_18+R_0; T R_34 = 2.0*R_18; R_15 = R_34+R_15;
    R_28 = R_15*R_28; R_28 = R_28*R_22; R_28 = R_20*R_28; R_28 = (-4.0)*R_28;
    R_34 = R_15*R_1; T R_35 = R_5*R_34; R_35 = 16.0*R_35; R_35 = R_11+R_35;
    R_34 = R_34*R_27; R_11 = R_15*R_14; T R_36 = R_20*R_11; T R_37 = R_6*R_36;
    R_37 = (-16.0)*R_37; T R_38 = R_4*R_36; R_38 = (-16.0)*R_38; R_36 = R_13*R_36;
    R_36 = (-16.0)*R_36; R_11 = R_11*R_22; T R_39 = R_11*R_6; R_39 = 4.0*R_39;
    T R_40 = R_4*R_11; R_40 = 4.0*R_40; R_11 = R_11*R_13; R_11 = 4.0*R_11;
    T R_41 = pow(R_15,2); R_3 = R_41*R_3; T R_42 = R_4*R_41; R_42 = R_6*R_42;
    R_42 = 2.0*R_42; R_7 = R_41*R_7; T R_43 = R_41*R_13; T R_44 = R_43*R_6;
    R_44 = 2.0*R_44; R_43 = R_43*R_4; R_43 = 2.0*R_43; R_25 = R_41*R_25;
    R_18 = 4.0*R_18; R_16 = R_18+R_16; R_18 = R_23*R_16; R_41 = R_6*R_16;
    R_41 = R_23*R_41; T R_45 = R_1*R_41; R_45 = (-1.0)*R_45; R_45 = R_3+R_45;
    R_37 = R_45+R_37; R_37 = R_31+R_37; R_35 = R_37+R_35; R_35 = R_9+R_35;
    coeff_resultant_U[4] = R_35; R_35 = R_4*R_16; R_35 = R_23*R_35; R_9 = R_1*R_35;
    R_9 = (-1.0)*R_9; R_16 = R_13*R_16; R_16 = R_23*R_16; R_37 = R_1*R_16;
    R_37 = (-1.0)*R_37; R_31 = (-3.0)*R_0; R_2 = R_2+R_31; R_12 = R_2+R_12;
    R_18 = R_12*R_18; R_18 = R_18*R_6; R_18 = (-1.0)*R_18; R_2 = R_12*R_30;
    R_2 = (-16.0)*R_2; R_45 = R_12*R_32; R_45 = 4.0*R_45; R_3 = R_12*R_35;
    R_3 = (-1.0)*R_3; R_3 = R_7+R_3; R_7 = pow(R_12,2); R_7 = R_24*R_7;
    R_44 = R_7+R_44; R_34 = R_44+R_34; R_44 = R_12*R_16; R_44 = (-1.0)*R_44;
    R_7 = R_15*R_12; T R_46 = R_5*R_7; R_46 = 16.0*R_46; R_46 = R_9+R_46;
    R_18 = R_46+R_18; R_18 = R_42+R_18; R_42 = R_7*R_22; R_42 = R_20*R_42;
    R_42 = (-8.0)*R_42; R_7 = R_7*R_27; R_44 = R_7+R_44; R_7 = R_12*R_24;
    R_46 = R_1*R_7; R_46 = 2.0*R_46; R_31 = R_19+R_31; R_17 = R_31+R_17;
    R_26 = R_26*R_17; R_26 = R_26*R_14; R_31 = R_6*R_26; R_31 = (-4.0)*R_31;
    R_39 = R_31+R_39; R_33 = R_39+R_33; R_33 = R_38+R_33; R_2 = R_33+R_2;
    R_26 = R_4*R_26; R_26 = (-4.0)*R_26; R_26 = R_40+R_26; R_45 = R_26+R_45;
    R_36 = R_45+R_36; R_45 = R_20*R_17; R_45 = R_23*R_45; R_26 = R_1*R_45;
    R_26 = 4.0*R_26; R_40 = R_12*R_45; R_40 = 4.0*R_40; R_33 = R_23*R_17;
    R_14 = R_33*R_14; R_14 = R_13*R_14; R_14 = (-8.0)*R_14; R_14 = R_11+R_14;
    R_11 = R_22*R_17; R_11 = R_23*R_11; R_1 = R_1*R_11; R_1 = (-1.0)*R_1;
    R_12 = R_12*R_11; R_12 = (-1.0)*R_12; R_43 = R_12+R_43; R_12 = R_15*R_17;
    R_33 = R_12*R_20; R_38 = R_33*R_6; R_38 = 4.0*R_38; R_38 = R_46+R_38;
    R_26 = R_38+R_26; R_26 = R_18+R_26; R_26 = R_2+R_26; R_29 = R_26+R_29;
    R_28 = R_29+R_28; coeff_resultant_U[3] = R_28; R_28 = R_4*R_33; R_28 = 4.0*R_28;
    R_33 = R_33*R_13; R_33 = 4.0*R_33; R_12 = R_12*R_22; R_29 = R_6*R_12;
    R_29 = (-1.0)*R_29; R_26 = R_4*R_12; R_26 = (-1.0)*R_26; R_12 = R_13*R_12;
    R_12 = (-1.0)*R_12; R_17 = pow(R_17,2); R_17 = R_23*R_17; R_6 = R_17*R_6;
    R_4 = R_17*R_4; R_13 = R_17*R_13; R_21 = R_0+R_21; R_30 = R_30*R_21;
    R_30 = (-16.0)*R_30; R_30 = R_36+R_30; R_41 = R_41*R_21; R_41 = (-1.0)*R_41;
    R_41 = R_3+R_41; R_10 = R_10*R_21; R_10 = 2.0*R_10; R_29 = R_10+R_29;
    R_29 = R_1+R_29; R_28 = R_29+R_28; R_28 = R_40+R_28; R_35 = R_35*R_21;
    R_35 = (-1.0)*R_35; R_35 = R_44+R_35; R_35 = R_43+R_35; R_45 = R_45*R_21;
    R_45 = 4.0*R_45; R_7 = R_7*R_21; R_7 = 2.0*R_7; R_7 = R_26+R_7;
    R_33 = R_7+R_33; R_45 = R_33+R_45; R_35 = R_45+R_35; R_35 = R_4+R_35;
    R_32 = R_32*R_21; R_32 = 4.0*R_32; R_32 = R_14+R_32; R_35 = R_32+R_35;
    R_11 = R_21*R_11; R_11 = (-1.0)*R_11; R_15 = R_15*R_21; R_5 = R_15*R_5;
    R_5 = 16.0*R_5; R_37 = R_5+R_37; R_34 = R_37+R_34; R_41 = R_34+R_41;
    R_41 = R_28+R_41; R_6 = R_41+R_6; R_30 = R_6+R_30; R_8 = R_30+R_8;
    R_8 = R_42+R_8; coeff_resultant_U[2] = R_8; R_22 = R_15*R_22; R_22 = R_20*R_22;
    R_22 = (-8.0)*R_22; R_22 = R_35+R_22; coeff_resultant_U[1] = R_22; R_27 = R_15*R_27;
    R_11 = R_27+R_11; R_16 = R_16*R_21; R_16 = (-1.0)*R_16; R_12 = R_16+R_12;
    R_12 = R_13+R_12; R_25 = R_12+R_25; R_21 = pow(R_21,2); R_24 = R_21*R_24;
    R_25 = R_24+R_25; R_11 = R_25+R_11; coeff_resultant_U[0] = R_11; 

    //PRINT( coeff_resultant_U );
    //std::cout << setprecision(16) << " coeff_resultant_U  " << std::endl;
    //for( unsigned i=0; i < coeff_resultant_U.size(); ++i ) std::cout << "(" << coeff_resultant_U[i] << ") * U**" << i << " + " ;
    //std::cout << std::endl;
    sol_U = Pol<4,1,T>(coeff_resultant_U).real_roots();
    //PRINT( sol_U );
    for( unsigned i=0; i < sol_U.size(); ++i ) {
        U = sol_U[i];
        //PRINT(U);
        if ((U >= -0.01) and (U <= 1.01)) {
            /// calcul des coefficients du polynôme en V
            T R_0 = pos_nodes[5][0]; T R_1 = (-4.0)*R_0; T R_2 = pos_nodes[4][0]; T R_3 = pos_nodes[2][0];
            T R_4 = 2.0*R_3; R_3 = (-1.0)*R_3; T R_5 = pos_nodes[3][0]; T R_6 = pos_nodes[1][0];
            T R_7 = U; T R_8 = (-1.0)+R_7; R_0 = R_8*R_0; R_0 = (-4.0)*R_0;
            R_2 = R_2*R_7; R_2 = 4.0*R_2; R_0 = R_2+R_0; R_2 = 4.0*R_7;
            R_2 = (-3.0)+R_2; R_8 = (-1.0)*R_7; R_8 = 1.0+R_8; R_5 = R_5*R_7;
            T R_9 = (-4.0)*R_5; R_8 = R_5*R_8; R_8 = 4.0*R_8; R_6 = R_6*R_7;
            R_5 = 2.0*R_7; T R_10 = (-1.0)+R_5; R_6 = R_10*R_6; R_5 = (-3.0)+R_5;
            R_7 = R_5*R_7; R_7 = 1.0+R_7; R_5 = pos_nodes[0][0]; R_10 = 2.0*R_5;
            R_10 = R_4+R_10; R_1 = R_10+R_1; coeff_V[2] = R_1; R_2 = R_5*R_2;
            R_2 = R_3+R_2; R_9 = R_2+R_9; R_0 = R_9+R_0; coeff_V[1] = R_0;
            R_7 = R_5*R_7; R_6 = R_7+R_6; R_8 = R_6+R_8; R_6 = pos[0];
            R_6 = (-1.0)*R_6; R_8 = R_6+R_8; coeff_V[0] = R_8; 

            if ( max( abs( coeff_V ) ) < tolerance ) {
                T R_0 = pos_nodes[5][1]; T R_1 = (-4.0)*R_0; T R_2 = pos_nodes[4][1]; T R_3 = pos_nodes[2][1];
                T R_4 = 2.0*R_3; R_3 = (-1.0)*R_3; T R_5 = pos[1]; R_5 = (-1.0)*R_5;
                T R_6 = pos_nodes[3][1]; T R_7 = pos_nodes[1][1]; T R_8 = pos_nodes[0][1]; T R_9 = 2.0*R_8;
                R_9 = R_4+R_9; R_1 = R_9+R_1; coeff_V[2] = R_1; R_1 = U;
                R_9 = (-1.0)+R_1; R_0 = R_9*R_0; R_0 = (-4.0)*R_0; R_2 = R_2*R_1;
                R_2 = 4.0*R_2; R_0 = R_2+R_0; R_2 = 4.0*R_1; R_2 = (-3.0)+R_2;
                R_2 = R_2*R_8; R_3 = R_2+R_3; R_2 = (-1.0)*R_1; R_2 = 1.0+R_2;
                R_6 = R_1*R_6; R_9 = (-4.0)*R_6; R_3 = R_9+R_3; R_0 = R_3+R_0;
                coeff_V[1] = R_0; R_2 = R_6*R_2; R_2 = 4.0*R_2; R_7 = R_7*R_1;
                R_6 = 2.0*R_1; R_0 = (-1.0)+R_6; R_7 = R_0*R_7; R_6 = (-3.0)+R_6;
                R_1 = R_6*R_1; R_1 = 1.0+R_1; R_8 = R_1*R_8; R_7 = R_8+R_7;
                R_2 = R_7+R_2; R_5 = R_2+R_5; coeff_V[0] = R_5; 

            }
            sol_V = Pol<2,1,T>( coeff_V ).real_roots();
            //PRINT( sol_V);
            for( unsigned j=0; j < sol_V.size(); ++j ) {
                U = sol_U[i];
                V = sol_V[j];
                TVI vi( U, V );
                //PRINT( vi );
                if ( var_inter_is_inside( Triangle_6(), vi, 0.01 ) ) {
                    //std::cout << "- 0" << std::endl; PRINT( U ); PRINT( V );
                    isSolution = true;
                    for( unsigned t=0; t<6; ++t ) { /// méthode de Newton-Raphson
                        T R_0 = pos[1]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[2][1]; T R_2 = pos_nodes[1][1];
                        T R_3 = pos_nodes[4][1]; T R_4 = (-1.0)*R_3; T R_5 = pos_nodes[5][1]; T R_6 = (-1.0)*R_5;
                        R_6 = R_6+R_3; T R_7 = pos_nodes[3][1]; R_4 = R_7+R_4; T R_8 = pos_nodes[0][1];
                        T R_9 = pos[0]; R_9 = (-1.0)*R_9; T R_10 = pos_nodes[2][0]; T R_11 = pos_nodes[5][0];
                        T R_12 = (-1.0)*R_11; T R_13 = pos_nodes[4][0]; T R_14 = (-1.0)*R_13; R_12 = R_13+R_12;
                        T R_15 = pos_nodes[3][0]; R_14 = R_14+R_15; T R_16 = pos_nodes[0][0]; T R_17 = V;
                        T R_18 = R_1*R_17; R_6 = R_6*R_17; R_13 = R_13*R_17; T R_19 = 2.0*R_17;
                        T R_20 = (-3.0)+R_19; R_20 = R_20*R_17; T R_21 = (-1.0)+R_19; R_18 = R_21*R_18;
                        R_21 = R_21*R_10; T R_22 = 4.0*R_17; T R_23 = (-1.0)+R_22; R_1 = R_1*R_23;
                        R_23 = R_10*R_23; R_12 = R_17*R_12; R_10 = (-1.0)*R_17; T R_24 = U;
                        R_4 = R_4*R_24; R_3 = R_3*R_24; T R_25 = R_2*R_24; T R_26 = (-1.0)*R_24;
                        R_26 = R_26+R_10; R_26 = 1.0+R_26; T R_27 = R_26*R_24; R_27 = R_27*R_7;
                        R_26 = R_26*R_15; R_13 = R_26+R_13; R_13 = 4.0*R_13; R_26 = 2.0*R_24;
                        T R_28 = (-1.0)+R_26; R_25 = R_28*R_25; R_22 = R_26+R_22; R_22 = (-3.0)+R_22;
                        R_22 = R_22*R_24; R_22 = R_20+R_22; R_22 = 1.0+R_22; R_20 = R_22*R_8;
                        R_25 = R_20+R_25; R_18 = R_25+R_18; R_0 = R_18+R_0; R_22 = R_22*R_16;
                        R_19 = R_19+R_24; R_19 = (-1.0)+R_19; R_18 = R_5*R_19; R_18 = R_4+R_18;
                        R_18 = (-4.0)*R_18; R_19 = R_11*R_19; R_14 = R_14*R_24; R_19 = R_14+R_19;
                        R_19 = (-4.0)*R_19; R_14 = (-2.0)*R_24; R_14 = R_10+R_14; R_14 = 1.0+R_14;
                        R_7 = R_14*R_7; R_6 = R_7+R_6; R_6 = 4.0*R_6; R_15 = R_14*R_15;
                        R_12 = R_15+R_12; R_12 = 4.0*R_12; R_15 = R_24+R_17; R_14 = (-1.0)+R_15;
                        R_5 = R_14*R_5; R_5 = (-1.0)*R_5; R_5 = R_3+R_5; R_5 = R_5*R_17;
                        R_27 = R_5+R_27; R_27 = 4.0*R_27; R_27 = R_0+R_27; R_27 = (-1.0)*R_27;
                        R_11 = R_14*R_11; R_11 = (-4.0)*R_11; R_21 = R_11+R_21; R_21 = R_21*R_17;
                        R_15 = 4.0*R_15; R_15 = (-3.0)+R_15; R_8 = R_15*R_8; R_11 = R_8+R_18;
                        R_11 = R_1+R_11; R_11 = R_11*R_17; R_11 = R_27+R_11; R_6 = R_8+R_6;
                        R_16 = R_15*R_16; R_19 = R_16+R_19; R_19 = R_23+R_19; R_23 = R_19*R_17;
                        R_12 = R_16+R_12; R_16 = 4.0*R_24; R_16 = (-1.0)+R_16; R_2 = R_2*R_16;
                        R_2 = R_6+R_2; R_6 = pos_nodes[1][0]; R_28 = R_28*R_6; R_28 = R_13+R_28;
                        R_28 = R_28*R_24; R_28 = R_9+R_28; R_28 = R_22+R_28; R_28 = R_21+R_28;
                        R_28 = (-1.0)*R_28; R_16 = R_6*R_16; R_12 = R_16+R_12; R_16 = R_12*R_24;
                        R_28 = R_16+R_28; R_23 = R_23+R_28; R_12 = 1/R_12; R_16 = R_12*R_2;
                        R_16 = R_16*R_19; R_16 = (-1.0)*R_16; R_16 = R_8+R_16; R_16 = R_18+R_16;
                        R_16 = R_1+R_16; R_16 = 1/R_16; R_23 = R_12*R_23; R_23 = (-1.0)*R_23;
                        R_24 = R_23+R_24; R_2 = R_24*R_2; R_11 = R_2+R_11; R_16 = R_11*R_16;
                        V2 = R_16; R_16 = (-1.0)*R_16; R_16 = R_17+R_16; R_19 = R_16*R_19;
                        R_28 = R_19+R_28; R_28 = R_12*R_28; U2 = R_28; 

                        T err = 1 + abs(U) + abs(V); err = (abs(U-U2) + abs(V-V2)) / err;
                        U = U2; V = V2;
                        if (err < tolerance ) break;
                        vi = TVI( U, V );
                        if (not( var_inter_is_inside( Triangle_6(), vi, tolerance ) ) ) {
                            isSolution = false;
                            break;
                        }
                        //std::cout << "- " << t+1 << std::endl; PRINT( U ); PRINT( V  );
                    }
                    /// on teste notre solution (U, V) en évaluant la position en ce point (U, V).
                    if (isSolution) {
                        T R_0 = pos[1]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[2][1]; T R_2 = pos_nodes[1][1];
                        T R_3 = pos_nodes[0][1]; T R_4 = pos_nodes[3][1]; T R_5 = pos_nodes[5][1]; T R_6 = pos_nodes[4][1];
                        T R_7 = pos_nodes[5][0]; T R_8 = pos_nodes[4][0]; T R_9 = pos_nodes[3][0]; T R_10 = pos_nodes[2][0];
                        T R_11 = pos_nodes[1][0]; T R_12 = pos_nodes[0][0]; T R_13 = U; R_2 = R_2*R_13;
                        R_4 = R_13*R_4; R_6 = R_6*R_13; R_8 = R_8*R_13; R_9 = R_9*R_13;
                        T R_14 = (-1.0)*R_13; R_11 = R_11*R_13; T R_15 = 2.0*R_13; T R_16 = (-1.0)+R_15;
                        R_2 = R_16*R_2; R_11 = R_16*R_11; R_16 = V; R_1 = R_1*R_16;
                        R_5 = R_16*R_5; R_6 = R_6*R_16; R_6 = 4.0*R_6; R_7 = R_16*R_7;
                        T R_17 = R_13+R_16; R_17 = (-1.0)+R_17; R_5 = R_5*R_17; R_5 = (-4.0)*R_5;
                        R_5 = R_6+R_5; R_7 = R_17*R_7; R_7 = (-4.0)*R_7; R_8 = R_8*R_16;
                        R_8 = 4.0*R_8; R_7 = R_8+R_7; R_8 = (-1.0)*R_16; R_8 = R_14+R_8;
                        R_8 = 1.0+R_8; R_4 = R_8*R_4; R_4 = 4.0*R_4; R_9 = R_8*R_9;
                        R_9 = 4.0*R_9; R_10 = R_16*R_10; R_8 = 4.0*R_16; R_8 = R_15+R_8;
                        R_8 = (-3.0)+R_8; R_13 = R_8*R_13; R_8 = 2.0*R_16; R_15 = (-1.0)+R_8;
                        R_1 = R_15*R_1; R_1 = R_2+R_1; R_15 = R_10*R_15; R_15 = R_11+R_15;
                        R_8 = (-3.0)+R_8; R_16 = R_8*R_16; R_13 = R_16+R_13; R_13 = 1.0+R_13;
                        R_3 = R_13*R_3; R_1 = R_3+R_1; R_1 = R_4+R_1; R_1 = R_5+R_1;
                        R_0 = R_1+R_0; eval2 = R_0; R_12 = R_13*R_12; R_15 = R_12+R_15;
                        R_9 = R_15+R_9; R_7 = R_9+R_7; R_9 = pos[0]; R_9 = (-1.0)*R_9;
                        R_7 = R_9+R_7; eval = R_7; 

                        //PRINT( eval ); PRINT( eval2 );
                        if ( (abs(eval) < tolerance) and (abs(eval2) < tolerance) ) {
                           var_inter += TVI( U, V );
                           return true;
                        }
                    } /// if la méthode Newton à converger vers une solution dans l'espace de référence
                } /// if var_inter_is_inside 
            }  /// for sur sol_V
        } /// endif U in [0;1]
    } /// for sur sol_U
    
    //var_inter += std::numeric_limits<T>::max();
    return false;
}
}
#endif  /// GET_VAR_INTER__Triangle_6
 
