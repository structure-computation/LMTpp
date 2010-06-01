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
    R_0 = R_2+R_0; R_1 = 4.0*R_1; T R_3 = pos_nodes[2][1]; T R_4 = 2.0*R_3;
    R_3 = (-1.0)*R_3; T R_5 = pos_nodes[3][1]; T R_6 = (-4.0)*R_5; R_5 = 4.0*R_5;
    T R_7 = pos_nodes[1][1]; T R_8 = 2.0*R_7; R_7 = (-1.0)*R_7; T R_9 = pos[1];
    R_9 = (-1.0)*R_9; T R_10 = pos_nodes[0][1]; T R_11 = 4.0*R_10; R_11 = R_6+R_11;
    R_0 = R_11+R_0; coeff_poly[1][4] = R_0; R_0 = 2.0*R_10; R_4 = R_4+R_0;
    R_2 = R_4+R_2; coeff_poly[1][5] = R_2; R_8 = R_0+R_8; R_8 = R_6+R_8;
    coeff_poly[1][3] = R_8; R_8 = (-3.0)*R_10; R_3 = R_8+R_3; R_1 = R_3+R_1;
    coeff_poly[1][2] = R_1; R_7 = R_8+R_7; R_5 = R_7+R_5; coeff_poly[1][1] = R_5;
    R_9 = R_10+R_9; coeff_poly[1][0] = R_9; R_9 = pos_nodes[4][0]; R_9 = 4.0*R_9;
    R_10 = pos_nodes[5][0]; R_5 = (-4.0)*R_10; R_9 = R_9+R_5; R_10 = 4.0*R_10;
    R_7 = pos_nodes[2][0]; R_8 = 2.0*R_7; R_7 = (-1.0)*R_7; R_1 = pos_nodes[1][0];
    R_3 = 2.0*R_1; R_1 = (-1.0)*R_1; R_6 = pos_nodes[3][0]; R_0 = (-4.0)*R_6;
    R_6 = 4.0*R_6; R_2 = pos[0]; R_2 = (-1.0)*R_2; R_4 = pos_nodes[0][0];
    R_11 = 4.0*R_4; R_11 = R_0+R_11; R_9 = R_11+R_9; coeff_poly[0][4] = R_9;
    R_9 = 2.0*R_4; R_8 = R_9+R_8; R_5 = R_8+R_5; coeff_poly[0][5] = R_5;
    R_9 = R_3+R_9; R_9 = R_0+R_9; coeff_poly[0][3] = R_9; R_9 = (-3.0)*R_4;
    R_7 = R_7+R_9; R_10 = R_7+R_10; coeff_poly[0][2] = R_10; R_9 = R_1+R_9;
    R_9 = R_6+R_9; coeff_poly[0][1] = R_9; R_2 = R_4+R_2; coeff_poly[0][0] = R_2;

    }
    if (solve_quasi_linear_polynomial_system_2X( coeff_poly, sol_poly, tolerance ) )
        for( unsigned i=0; i< sol_poly.size(); ++i) 
            if ( var_inter_is_inside( Triangle_6(), sol_poly[i], tolerance ) ) {
                var_inter += sol_poly[i];
                return true;
            }


    
    T R_0 = pos_nodes[4][1]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[4][0]; R_1 = (-1.0)*R_1;
    T R_2 = pos_nodes[3][1]; T R_3 = (-8.0)*R_2; T R_4 = (-4.0)*R_2; T R_5 = 4.0*R_2;
    T R_6 = pos_nodes[1][1]; T R_7 = (-1.0)*R_6; T R_8 = pos_nodes[1][0]; T R_9 = (-1.0)*R_8;
    T R_10 = pos_nodes[3][0]; T R_11 = (-4.0)*R_10; T R_12 = 4.0*R_10; T R_13 = pos[0];
    R_13 = (-1.0)*R_13; T R_14 = pos_nodes[2][1]; T R_15 = (-1.0)*R_14; T R_16 = pos_nodes[5][1];
    T R_17 = (-8.0)*R_16; T R_18 = 4.0*R_16; T R_19 = (-4.0)*R_16; T R_20 = pos[1];
    R_20 = (-1.0)*R_20; T R_21 = pos_nodes[0][1]; R_6 = R_21+R_6; T R_22 = 4.0*R_6;
    R_22 = R_3+R_22; R_6 = 2.0*R_6; R_6 = R_4+R_6; R_4 = pow(R_6,2);
    R_3 = (-1.0)*R_21; R_2 = R_3+R_2; R_2 = R_16+R_2; R_2 = R_0+R_2;
    R_0 = pow(R_2,2); R_16 = (-3.0)*R_21; R_7 = R_16+R_7; R_5 = R_7+R_5;
    R_7 = pow(R_5,2); R_15 = R_16+R_15; R_18 = R_15+R_18; R_15 = pow(R_18,2);
    R_14 = R_21+R_14; R_16 = 4.0*R_14; R_17 = R_16+R_17; R_14 = 2.0*R_14;
    R_14 = R_19+R_14; R_22 = R_22*R_14; R_19 = R_14*R_6; R_16 = R_14*R_2;
    R_3 = R_14*R_5; T R_23 = pow(R_14,2); T R_24 = R_14*R_18; R_20 = R_21+R_20;
    R_14 = R_14*R_20; R_21 = pow(R_20,2); T R_25 = pos_nodes[5][0]; T R_26 = (-8.0)*R_25;
    T R_27 = 4.0*R_25; T R_28 = (-4.0)*R_25; T R_29 = pos_nodes[2][0]; T R_30 = (-1.0)*R_29;
    T R_31 = pos_nodes[0][0]; R_8 = R_31+R_8; R_8 = 2.0*R_8; R_8 = R_11+R_8;
    R_11 = pow(R_8,2); R_11 = R_23*R_11; T R_32 = R_8*R_17; T R_33 = (-1.0)*R_31;
    R_33 = R_10+R_33; R_33 = R_1+R_33; R_25 = R_33+R_25; R_33 = pow(R_25,2);
    R_1 = R_33*R_19; R_1 = 16.0*R_1; R_10 = R_33*R_3; R_10 = 16.0*R_10;
    R_33 = R_33*R_14; R_33 = 16.0*R_33; T R_34 = R_25*R_2; T R_35 = R_25*R_16;
    T R_36 = R_35*R_8; R_36 = (-16.0)*R_36; T R_37 = R_25*R_18; T R_38 = R_25*R_24;
    T R_39 = R_38*R_8; R_39 = 4.0*R_39; R_13 = R_31+R_13; T R_40 = R_13*R_35;
    R_40 = (-16.0)*R_40; T R_41 = R_38*R_13; R_41 = 4.0*R_41; T R_42 = R_13*R_23;
    T R_43 = R_8*R_42; R_43 = 2.0*R_43; T R_44 = pow(R_13,2); R_44 = R_23*R_44;
    T R_45 = R_13*R_17; T R_46 = (-3.0)*R_31; R_9 = R_9+R_46; R_9 = R_12+R_9;
    R_12 = R_9*R_23; R_12 = R_12*R_8; R_12 = 2.0*R_12; R_35 = R_9*R_35;
    R_35 = (-16.0)*R_35; R_38 = R_38*R_9; R_38 = 4.0*R_38; T R_47 = pow(R_9,2);
    R_23 = R_47*R_23; R_47 = R_9*R_17; R_42 = R_9*R_42; R_42 = 2.0*R_42;
    R_46 = R_30+R_46; R_27 = R_46+R_27; R_22 = R_22*R_27; R_22 = R_22*R_25;
    R_22 = (-4.0)*R_22; R_46 = R_27*R_3; R_46 = R_25*R_46; R_46 = (-8.0)*R_46;
    R_30 = R_14*R_27; R_30 = R_25*R_30; R_30 = (-8.0)*R_30; R_25 = R_27*R_2;
    R_16 = R_27*R_16; T R_48 = R_8*R_16; R_48 = 4.0*R_48; T R_49 = R_9*R_16;
    R_49 = 4.0*R_49; R_16 = R_13*R_16; R_16 = 4.0*R_16; T R_50 = R_27*R_18;
    T R_51 = pow(R_27,2); R_19 = R_51*R_19; R_3 = R_51*R_3; R_14 = R_51*R_14;
    R_24 = R_27*R_24; R_27 = R_24*R_8; R_27 = (-1.0)*R_27; R_51 = R_24*R_9;
    R_51 = (-1.0)*R_51; R_24 = R_24*R_13; R_24 = (-1.0)*R_24; R_29 = R_31+R_29;
    R_31 = 4.0*R_29; R_31 = R_26+R_31; R_31 = R_31*R_18; R_31 = R_31*R_2;
    R_26 = R_8*R_31; R_26 = (-4.0)*R_26; R_48 = R_26+R_48; R_31 = R_9*R_31;
    R_31 = (-4.0)*R_31; R_49 = R_31+R_49; R_29 = 2.0*R_29; R_28 = R_29+R_28;
    R_17 = R_28*R_17; R_17 = R_5*R_17; R_17 = R_8*R_17; R_17 = (-1.0)*R_17;
    R_0 = R_28*R_0; R_29 = R_0*R_8; R_29 = 16.0*R_29; R_31 = R_9*R_0;
    R_31 = 16.0*R_31; R_0 = R_13*R_0; R_0 = 16.0*R_0; R_32 = R_32*R_28;
    R_26 = R_32*R_6; R_26 = (-1.0)*R_26; R_26 = R_11+R_26; R_36 = R_26+R_36;
    R_32 = R_32*R_20; R_32 = (-1.0)*R_32; R_34 = R_28*R_34; R_26 = R_34*R_6;
    R_26 = (-16.0)*R_26; R_36 = R_26+R_36; R_26 = R_34*R_5; R_26 = (-16.0)*R_26;
    R_34 = R_34*R_20; R_34 = (-16.0)*R_34; R_25 = R_28*R_25; R_11 = R_6*R_25;
    R_11 = 4.0*R_11; R_48 = R_11+R_48; R_35 = R_48+R_35; R_26 = R_35+R_26;
    R_35 = R_5*R_25; R_35 = 4.0*R_35; R_35 = R_49+R_35; R_40 = R_35+R_40;
    R_34 = R_40+R_34; R_25 = R_20*R_25; R_25 = 4.0*R_25; R_18 = R_28*R_18;
    R_2 = R_18*R_2; R_2 = R_13*R_2; R_2 = (-8.0)*R_2; R_16 = R_2+R_16;
    R_25 = R_16+R_25; R_37 = R_37*R_28; R_16 = R_37*R_6; R_16 = 4.0*R_16;
    R_2 = R_37*R_5; R_2 = 4.0*R_2; R_37 = R_37*R_20; R_37 = 4.0*R_37;
    R_47 = R_28*R_47; R_18 = R_6*R_47; R_18 = (-1.0)*R_18; R_18 = R_10+R_18;
    R_17 = R_18+R_17; R_17 = R_12+R_17; R_12 = R_47*R_5; R_12 = (-1.0)*R_12;
    R_12 = R_23+R_12; R_32 = R_12+R_32; R_47 = R_47*R_20; R_47 = (-1.0)*R_47;
    R_50 = R_50*R_28; R_12 = R_6*R_50; R_12 = (-1.0)*R_12; R_23 = R_50*R_5;
    R_23 = (-1.0)*R_23; R_42 = R_23+R_42; R_50 = R_20*R_50; R_50 = (-1.0)*R_50;
    R_50 = R_14+R_50; R_15 = R_28*R_15; R_8 = R_8*R_15; R_9 = R_9*R_15;
    R_15 = R_13*R_15; R_45 = R_28*R_45; R_13 = R_6*R_45; R_13 = (-1.0)*R_13;
    R_33 = R_13+R_33; R_13 = R_45*R_5; R_13 = (-1.0)*R_13; R_13 = R_3+R_13;
    R_47 = R_13+R_47; R_47 = R_42+R_47; R_45 = R_20*R_45; R_45 = (-1.0)*R_45;
    R_45 = R_24+R_45; R_15 = R_45+R_15; R_44 = R_15+R_44; R_28 = pow(R_28,2);
    R_4 = R_4*R_28; R_1 = R_4+R_1; R_36 = R_1+R_36; R_29 = R_36+R_29;
    coeff_resultant_U[4] = R_29; R_29 = R_28*R_6; R_29 = R_29*R_20; R_29 = 2.0*R_29;
    R_27 = R_29+R_27; R_12 = R_27+R_12; R_38 = R_12+R_38; R_2 = R_38+R_2;
    R_7 = R_28*R_7; R_7 = R_43+R_7; R_19 = R_7+R_19; R_19 = R_33+R_19;
    R_32 = R_19+R_32; R_2 = R_32+R_2; R_2 = R_8+R_2; R_2 = R_34+R_2;
    R_0 = R_2+R_0; R_46 = R_0+R_46; coeff_resultant_U[2] = R_46; R_5 = R_28*R_5;
    R_6 = R_5*R_6; R_6 = 2.0*R_6; R_39 = R_6+R_39; R_39 = R_16+R_39;
    R_39 = R_17+R_39; R_39 = R_26+R_39; R_31 = R_39+R_31; R_22 = R_31+R_22;
    coeff_resultant_U[3] = R_22; R_20 = R_5*R_20; R_20 = 2.0*R_20; R_20 = R_51+R_20;
    R_41 = R_20+R_41; R_37 = R_41+R_37; R_37 = R_47+R_37; R_37 = R_9+R_37;
    R_25 = R_37+R_25; R_30 = R_25+R_30; coeff_resultant_U[1] = R_30; R_21 = R_28*R_21;
    R_44 = R_21+R_44; R_50 = R_44+R_50; coeff_resultant_U[0] = R_50; 

    //PRINT( coeff_resultant_U );
    //std::cout << setprecision(16) << " coeff_resultant_U  " << std::endl;
    //for( unsigned i=0; i < coeff_resultant_U.size(); ++i ) std::cout << "(" << coeff_resultant_U[i] << ") * U**" << i << " + " ;
    //std::cout << std::endl;
    sol_U = Pol<4,1,T>(coeff_resultant_U).real_roots( 1e-2 );
    //PRINT( sol_U );
    for( unsigned i=0; i < sol_U.size(); ++i ) {
        U = sol_U[i];
        //PRINT(U);
        if ((U >= -0.01) and (U <= 1.01)) {
            /// calcul des coefficients du polynôme en V
            T R_0 = pos_nodes[2][0]; T R_1 = 2.0*R_0; R_0 = (-1.0)*R_0; T R_2 = pos_nodes[4][0];
            T R_3 = pos_nodes[5][0]; T R_4 = (-4.0)*R_3; T R_5 = pos[0]; R_5 = (-1.0)*R_5;
            T R_6 = pos_nodes[1][0]; T R_7 = pos_nodes[0][0]; T R_8 = 2.0*R_7; R_1 = R_8+R_1;
            R_4 = R_1+R_4; coeff_V[2] = R_4; R_4 = pos_nodes[3][0]; R_1 = U;
            R_8 = 4.0*R_1; R_8 = (-3.0)+R_8; R_8 = R_7*R_8; R_8 = R_0+R_8;
            R_2 = R_2*R_1; R_2 = 4.0*R_2; R_0 = (-1.0)+R_1; R_3 = R_0*R_3;
            R_3 = (-4.0)*R_3; R_2 = R_3+R_2; R_6 = R_1*R_6; R_3 = 2.0*R_1;
            R_0 = (-1.0)+R_3; R_6 = R_0*R_6; R_3 = (-3.0)+R_3; R_3 = R_3*R_1;
            R_3 = 1.0+R_3; R_3 = R_7*R_3; R_6 = R_3+R_6; R_4 = R_4*R_1;
            R_3 = (-4.0)*R_4; R_8 = R_3+R_8; R_8 = R_2+R_8; coeff_V[1] = R_8;
            R_1 = (-1.0)*R_1; R_1 = 1.0+R_1; R_4 = R_1*R_4; R_4 = 4.0*R_4;
            R_6 = R_4+R_6; R_5 = R_6+R_5; coeff_V[0] = R_5; 

            if ( max( abs( coeff_V ) ) < tolerance ) {
                T R_0 = pos_nodes[2][1]; T R_1 = 2.0*R_0; R_0 = (-1.0)*R_0; T R_2 = pos_nodes[5][1];
                T R_3 = (-4.0)*R_2; T R_4 = pos_nodes[4][1]; T R_5 = pos_nodes[0][1]; T R_6 = 2.0*R_5;
                R_6 = R_1+R_6; R_3 = R_6+R_3; coeff_V[2] = R_3; R_3 = pos_nodes[1][1];
                R_6 = pos_nodes[3][1]; R_1 = U; T R_7 = 4.0*R_1; R_7 = (-3.0)+R_7;
                R_7 = R_5*R_7; R_7 = R_0+R_7; R_0 = (-1.0)+R_1; R_2 = R_0*R_2;
                R_2 = (-4.0)*R_2; R_4 = R_4*R_1; R_4 = 4.0*R_4; R_2 = R_4+R_2;
                R_4 = 2.0*R_1; R_0 = (-3.0)+R_4; R_0 = R_0*R_1; R_0 = 1.0+R_0;
                R_0 = R_5*R_0; R_4 = (-1.0)+R_4; R_3 = R_1*R_3; R_4 = R_3*R_4;
                R_0 = R_4+R_0; R_6 = R_1*R_6; R_4 = (-4.0)*R_6; R_7 = R_4+R_7;
                R_7 = R_2+R_7; coeff_V[1] = R_7; R_1 = (-1.0)*R_1; R_1 = 1.0+R_1;
                R_6 = R_1*R_6; R_6 = 4.0*R_6; R_0 = R_6+R_0; R_6 = pos[1];
                R_6 = (-1.0)*R_6; R_0 = R_6+R_0; coeff_V[0] = R_0; 

            }
            sol_V = Pol<2,1,T>( coeff_V ).real_roots(  );
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
                        T R_0 = pos[1]; R_0 = (-1.0)*R_0; T R_1 = pos[0]; R_1 = (-1.0)*R_1;
                        T R_2 = pos_nodes[1][0]; T R_3 = pos_nodes[1][1]; T R_4 = pos_nodes[5][1]; T R_5 = (-1.0)*R_4;
                        T R_6 = pos_nodes[4][1]; T R_7 = (-1.0)*R_6; R_5 = R_6+R_5; T R_8 = pos_nodes[3][1];
                        R_7 = R_8+R_7; T R_9 = pos_nodes[0][0]; T R_10 = pos_nodes[3][0]; T R_11 = (-1.0)*R_10;
                        T R_12 = pos_nodes[4][0]; R_11 = R_12+R_11; T R_13 = pos_nodes[5][0]; T R_14 = (-1.0)*R_13;
                        R_14 = R_12+R_14; T R_15 = pos_nodes[2][0]; T R_16 = U; T R_17 = R_16*R_3;
                        T R_18 = R_16*R_2; T R_19 = 2.0*R_16; T R_20 = (-1.0)+R_19; R_17 = R_17*R_20;
                        R_18 = R_20*R_18; R_20 = (-1.0)*R_16; R_12 = R_12*R_16; R_12 = (-1.0)*R_12;
                        R_7 = R_16*R_7; T R_21 = 4.0*R_16; R_21 = (-1.0)+R_21; R_2 = R_2*R_21;
                        R_3 = R_21*R_3; R_21 = (-2.0)*R_16; R_11 = R_16*R_11; T R_22 = pos_nodes[0][1];
                        T R_23 = V; R_6 = R_6*R_23; T R_24 = R_15*R_23; R_14 = R_23*R_14;
                        R_5 = R_23*R_5; T R_25 = (-1.0)*R_23; R_20 = R_20+R_25; R_20 = 1.0+R_20;
                        T R_26 = R_8*R_20; R_6 = R_26+R_6; R_6 = R_16*R_6; R_20 = R_10*R_20;
                        R_20 = R_16*R_20; R_20 = (-1.0)*R_20; R_21 = R_25+R_21; R_21 = 1.0+R_21;
                        R_10 = R_10*R_21; R_10 = R_14+R_10; R_10 = 4.0*R_10; R_21 = R_8*R_21;
                        R_5 = R_21+R_5; R_5 = 4.0*R_5; R_21 = 2.0*R_23; R_8 = (-3.0)+R_21;
                        R_8 = R_23*R_8; R_14 = (-1.0)+R_21; R_24 = R_14*R_24; R_21 = R_21+R_16;
                        R_21 = (-1.0)+R_21; R_25 = R_4*R_21; R_25 = R_7+R_25; R_25 = (-4.0)*R_25;
                        R_21 = R_13*R_21; R_21 = (-1.0)*R_21; R_11 = R_21+R_11; R_11 = 4.0*R_11;
                        R_21 = R_23+R_16; R_7 = (-1.0)+R_21; R_26 = R_23*R_7; R_4 = R_26*R_4;
                        R_4 = (-1.0)*R_4; R_6 = R_4+R_6; R_6 = 4.0*R_6; R_13 = R_7*R_13;
                        R_12 = R_13+R_12; R_12 = R_12*R_23; R_20 = R_12+R_20; R_20 = (-4.0)*R_20;
                        R_21 = 4.0*R_21; R_21 = (-3.0)+R_21; R_12 = R_9*R_21; R_10 = R_10+R_12;
                        R_2 = R_10+R_2; R_10 = R_16*R_2; R_2 = 1/R_2; R_12 = R_11+R_12;
                        R_21 = R_22*R_21; R_11 = R_21+R_25; R_5 = R_21+R_5; R_3 = R_5+R_3;
                        R_5 = R_3*R_2; R_13 = 4.0*R_23; R_19 = R_19+R_13; R_19 = (-3.0)+R_19;
                        R_19 = R_16*R_19; R_8 = R_19+R_8; R_8 = 1.0+R_8; R_22 = R_22*R_8;
                        R_8 = R_9*R_8; R_8 = R_24+R_8; R_8 = R_1+R_8; R_8 = R_18+R_8;
                        R_8 = R_20+R_8; R_8 = (-1.0)*R_8; R_8 = R_10+R_8; R_13 = (-1.0)+R_13;
                        R_15 = R_15*R_13; R_12 = R_15+R_12; R_15 = R_23*R_12; R_15 = R_15+R_8;
                        R_15 = R_15*R_2; R_15 = (-1.0)*R_15; R_16 = R_15+R_16; R_3 = R_16*R_3;
                        R_5 = R_12*R_5; R_5 = (-1.0)*R_5; R_5 = R_21+R_5; R_25 = R_5+R_25;
                        R_5 = pos_nodes[2][1]; R_21 = R_5*R_23; R_21 = R_14*R_21; R_17 = R_21+R_17;
                        R_0 = R_17+R_0; R_22 = R_0+R_22; R_6 = R_22+R_6; R_6 = (-1.0)*R_6;
                        R_13 = R_5*R_13; R_11 = R_13+R_11; R_11 = R_11*R_23; R_11 = R_6+R_11;
                        R_11 = R_3+R_11; R_25 = R_13+R_25; R_25 = 1/R_25; R_11 = R_25*R_11;
                        V2 = R_11; R_11 = (-1.0)*R_11; R_23 = R_11+R_23; R_12 = R_23*R_12;
                        R_8 = R_12+R_8; R_2 = R_8*R_2; U2 = R_2; 

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
                        T R_0 = pos_nodes[5][1]; T R_1 = pos_nodes[4][1]; T R_2 = pos_nodes[0][1]; T R_3 = pos_nodes[1][1];
                        T R_4 = pos_nodes[2][1]; T R_5 = pos_nodes[3][1]; T R_6 = pos[1]; R_6 = (-1.0)*R_6;
                        T R_7 = pos[0]; R_7 = (-1.0)*R_7; T R_8 = pos_nodes[0][0]; T R_9 = pos_nodes[1][0];
                        T R_10 = pos_nodes[2][0]; T R_11 = pos_nodes[3][0]; T R_12 = pos_nodes[4][0]; T R_13 = pos_nodes[5][0];
                        T R_14 = U; R_1 = R_1*R_14; R_3 = R_14*R_3; R_5 = R_14*R_5;
                        R_9 = R_14*R_9; T R_15 = 2.0*R_14; T R_16 = (-1.0)+R_15; R_3 = R_3*R_16;
                        R_9 = R_16*R_9; R_11 = R_11*R_14; R_16 = (-1.0)*R_14; R_12 = R_12*R_14;
                        T R_17 = V; R_0 = R_17*R_0; R_1 = R_17*R_1; R_1 = 4.0*R_1;
                        R_4 = R_4*R_17; T R_18 = 4.0*R_17; R_18 = R_15+R_18; R_18 = (-3.0)+R_18;
                        R_18 = R_14*R_18; R_10 = R_10*R_17; R_15 = 2.0*R_17; T R_19 = (-3.0)+R_15;
                        R_19 = R_17*R_19; R_19 = R_18+R_19; R_19 = 1.0+R_19; R_2 = R_2*R_19;
                        R_19 = R_8*R_19; R_15 = (-1.0)+R_15; R_4 = R_15*R_4; R_3 = R_4+R_3;
                        R_2 = R_3+R_2; R_10 = R_15*R_10; R_9 = R_10+R_9; R_19 = R_9+R_19;
                        R_9 = (-1.0)*R_17; R_9 = R_16+R_9; R_9 = 1.0+R_9; R_5 = R_5*R_9;
                        R_5 = 4.0*R_5; R_2 = R_5+R_2; R_11 = R_9*R_11; R_11 = 4.0*R_11;
                        R_19 = R_11+R_19; R_12 = R_17*R_12; R_12 = 4.0*R_12; R_13 = R_17*R_13;
                        R_14 = R_17+R_14; R_14 = (-1.0)+R_14; R_0 = R_14*R_0; R_0 = (-4.0)*R_0;
                        R_0 = R_1+R_0; R_0 = R_2+R_0; R_0 = R_6+R_0; eval2 = R_0;
                        R_13 = R_14*R_13; R_13 = (-4.0)*R_13; R_12 = R_13+R_12; R_19 = R_12+R_19;
                        R_7 = R_19+R_7; eval = R_7; 

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
 
