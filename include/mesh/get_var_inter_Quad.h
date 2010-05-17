#ifndef GET_VAR_INTER__Quad_H
#define GET_VAR_INTER__Quad_H
 
#include <containers/polynomials.h>
 
 
namespace LMT {
 
template<class PosNodes,class Pvec,class TVI>
bool get_var_inter_experimental(const Quad &elem,const PosNodes &pos_nodes,const Pvec &pos,TVI &var_inter, typename Pvec::template SubType<0>::T tolerance = 1e-7 ) {
    typedef typename Pvec::template SubType<0>::T T;
    T U, V, eval, eval2, U2, V2;
    Vec< T, 3 > coeff_resultant_U;
    Vec< T, 3 > coeff_V;
    Vec< T > sol_U, sol_V;
    Vec< Vec< T >, 2 > coeff_poly;
    Vec< Vec< T, 2 > > sol_poly;
    bool isSolution;

    /// on résout le problème s'il est "quasi-linéaire"
    coeff_poly[0].resize(6);
    coeff_poly[1].resize(6);
    {
    T R_0 = pos_nodes[2][1]; T R_1 = pos_nodes[3][1]; T R_2 = (-1.0)*R_1; T R_3 = pos_nodes[1][1];
    T R_4 = (-1.0)*R_3; T R_5 = pos_nodes[0][1]; R_4 = R_4+R_5; R_2 = R_4+R_2;
    R_0 = R_2+R_0; coeff_poly[1][4] = R_0; R_0 = (-1.0)*R_5; R_1 = R_0+R_1;
    coeff_poly[1][2] = R_1; R_3 = R_0+R_3; coeff_poly[1][1] = R_3; R_3 = pos[1];
    R_3 = (-1.0)*R_3; R_5 = R_3+R_5; coeff_poly[1][0] = R_5; R_5 = pos_nodes[2][0];
    R_3 = pos_nodes[3][0]; R_0 = (-1.0)*R_3; R_1 = pos_nodes[1][0]; R_2 = (-1.0)*R_1;
    R_4 = pos[0]; R_4 = (-1.0)*R_4; T R_6 = pos_nodes[0][0]; R_2 = R_2+R_6;
    R_0 = R_2+R_0; R_0 = R_5+R_0; coeff_poly[0][4] = R_0; R_0 = (-1.0)*R_6;
    R_3 = R_0+R_3; coeff_poly[0][2] = R_3; R_1 = R_0+R_1; coeff_poly[0][1] = R_1;
    R_4 = R_6+R_4; coeff_poly[0][0] = R_4; 
    coeff_poly[0][3] = 0.0; coeff_poly[0][5] = 0.0; coeff_poly[1][3] = 0.0; coeff_poly[1][5] = 0.0;
    

    }
    if (solve_quasi_linear_polynomial_system_2X( coeff_poly, sol_poly, tolerance ) )
        for( unsigned i=0; i< sol_poly.size(); ++i) 
            if ( var_inter_is_inside( Quad(), sol_poly[i], tolerance ) ) {
                var_inter += sol_poly[i];
                return true;
            }


    
    T R_0 = pos_nodes[2][1]; T R_1 = pos_nodes[1][1]; T R_2 = (-1.0)*R_1; T R_3 = pos_nodes[1][0];
    T R_4 = (-1.0)*R_3; T R_5 = pos_nodes[2][0]; T R_6 = pos[0]; R_6 = (-1.0)*R_6;
    T R_7 = pos_nodes[3][1]; T R_8 = (-1.0)*R_7; T R_9 = pos_nodes[3][0]; T R_10 = (-1.0)*R_9;
    T R_11 = pos_nodes[0][0]; R_4 = R_4+R_11; R_10 = R_4+R_10; R_10 = R_5+R_10;
    R_6 = R_11+R_6; R_11 = (-1.0)*R_11; R_3 = R_11+R_3; R_9 = R_11+R_9;
    R_11 = pos_nodes[0][1]; R_2 = R_2+R_11; R_8 = R_2+R_8; R_0 = R_8+R_0;
    R_8 = R_3*R_0; R_8 = (-1.0)*R_8; R_0 = R_6*R_0; R_0 = (-1.0)*R_0;
    R_2 = (-1.0)*R_11; R_1 = R_2+R_1; R_5 = R_1*R_10; R_5 = R_8+R_5;
    coeff_resultant_U[2] = R_5; R_1 = R_9*R_1; R_0 = R_1+R_0; R_7 = R_2+R_7;
    R_3 = R_3*R_7; R_3 = (-1.0)*R_3; R_3 = R_0+R_3; R_6 = R_7*R_6;
    R_6 = (-1.0)*R_6; R_7 = pos[1]; R_7 = (-1.0)*R_7; R_11 = R_7+R_11;
    R_10 = R_11*R_10; R_3 = R_10+R_3; coeff_resultant_U[1] = R_3; R_9 = R_11*R_9;
    R_6 = R_9+R_6; coeff_resultant_U[0] = R_6; 

    //PRINT( coeff_resultant_U );
    //std::cout << setprecision(16) << " coeff_resultant_U  " << std::endl;
    //for( unsigned i=0; i < coeff_resultant_U.size(); ++i ) std::cout << "(" << coeff_resultant_U[i] << ") * U**" << i << " + " ;
    //std::cout << std::endl;
    sol_U = Pol<2,1,T>(coeff_resultant_U).real_roots( 1e-2 );
    //PRINT( sol_U );
    for( unsigned i=0; i < sol_U.size(); ++i ) {
        U = sol_U[i];
        //PRINT(U);
        if ((U >= -0.01) and (U <= 1.01)) {
            /// calcul des coefficients du polynôme en V
            T R_0 = pos_nodes[2][0]; T R_1 = pos_nodes[3][0]; T R_2 = pos[0]; R_2 = (-1.0)*R_2;
            T R_3 = pos_nodes[1][0]; T R_4 = pos_nodes[0][0]; T R_5 = U; R_0 = R_0*R_5;
            T R_6 = (-1.0)+R_5; R_6 = R_4*R_6; R_3 = R_3*R_5; T R_7 = (-1.0)*R_3;
            R_7 = R_6+R_7; R_5 = (-1.0)*R_5; R_5 = 1.0+R_5; R_1 = R_5*R_1;
            R_1 = R_7+R_1; R_0 = R_1+R_0; coeff_V[1] = R_0; R_4 = R_5*R_4;
            R_3 = R_4+R_3; R_2 = R_3+R_2; coeff_V[0] = R_2; 
            coeff_V[2] = 0.0; 

            if ( max( abs( coeff_V ) ) < tolerance ) {
                T R_0 = pos_nodes[2][1]; T R_1 = pos_nodes[3][1]; T R_2 = pos[1]; R_2 = (-1.0)*R_2;
                T R_3 = pos_nodes[0][1]; T R_4 = pos_nodes[1][1]; T R_5 = U; R_0 = R_0*R_5;
                T R_6 = (-1.0)+R_5; R_6 = R_6*R_3; T R_7 = (-1.0)*R_5; R_7 = 1.0+R_7;
                R_1 = R_7*R_1; R_3 = R_7*R_3; R_4 = R_5*R_4; R_5 = (-1.0)*R_4;
                R_5 = R_6+R_5; R_5 = R_1+R_5; R_0 = R_5+R_0; coeff_V[1] = R_0;
                R_3 = R_4+R_3; R_2 = R_3+R_2; coeff_V[0] = R_2; 
                coeff_V[2] = 0.0; 

            }
            sol_V = Pol<2,1,T>( coeff_V ).real_roots(  );
            //PRINT( sol_V);
            for( unsigned j=0; j < sol_V.size(); ++j ) {
                U = sol_U[i];
                V = sol_V[j];
                TVI vi( U, V );
                //PRINT( vi );
                if ( var_inter_is_inside( Quad(), vi, 0.01 ) ) {
                    //std::cout << "- 0" << std::endl; PRINT( U ); PRINT( V );
                    isSolution = true;
                    for( unsigned t=0; t<6; ++t ) { /// méthode de Newton-Raphson
                        T R_0 = pos[1]; R_0 = (-1.0)*R_0; T R_1 = pos_nodes[0][1]; T R_2 = pos_nodes[3][1];
                        T R_3 = (-1.0)*R_2; T R_4 = pos_nodes[2][1]; R_3 = R_4+R_3; T R_5 = pos_nodes[1][1];
                        T R_6 = (-1.0)*R_5; R_6 = R_6+R_4; T R_7 = pos_nodes[1][0]; T R_8 = (-1.0)*R_7;
                        T R_9 = pos_nodes[2][0]; R_8 = R_8+R_9; T R_10 = pos_nodes[0][0]; T R_11 = pos[0];
                        R_11 = (-1.0)*R_11; T R_12 = U; R_6 = R_6*R_12; R_8 = R_12*R_8;
                        T R_13 = (-1.0)+R_12; T R_14 = R_13*R_1; R_13 = R_10*R_13; T R_15 = (-1.0)*R_12;
                        R_15 = 1.0+R_15; T R_16 = R_15*R_2; R_14 = R_16+R_14; R_16 = R_14+R_6;
                        T R_17 = V; R_16 = R_16*R_17; R_4 = R_4*R_17; R_2 = R_2*R_17;
                        R_2 = R_15*R_2; R_0 = R_2+R_0; R_3 = R_3*R_17; R_2 = R_9*R_17;
                        T R_18 = (-1.0)*R_17; T R_19 = 1.0+R_18; R_5 = R_19*R_5; R_4 = R_4+R_5;
                        R_4 = R_4*R_12; R_7 = R_19*R_7; R_2 = R_2+R_7; R_2 = R_2*R_12;
                        R_19 = (-1.0)+R_17; T R_20 = R_19*R_1; R_20 = R_5+R_20; R_20 = R_3+R_20;
                        R_3 = R_10*R_19; R_3 = R_7+R_3; R_19 = R_19*R_12; R_18 = R_19+R_18;
                        R_18 = 1.0+R_18; R_1 = R_18*R_1; R_1 = R_0+R_1; R_4 = R_1+R_4;
                        R_4 = (-1.0)*R_4; R_16 = R_4+R_16; R_18 = R_10*R_18; R_10 = pos_nodes[3][0];
                        R_4 = R_15*R_10; R_4 = R_13+R_4; R_8 = R_4+R_8; R_4 = R_8*R_17;
                        R_13 = (-1.0)*R_10; R_13 = R_9+R_13; R_13 = R_13*R_17; R_3 = R_13+R_3;
                        R_13 = 1/R_3; R_9 = R_20*R_13; R_9 = R_8*R_9; R_9 = (-1.0)*R_9;
                        R_9 = R_14+R_9; R_9 = R_6+R_9; R_9 = 1/R_9; R_3 = R_12*R_3;
                        R_10 = R_10*R_17; R_15 = R_10*R_15; R_11 = R_15+R_11; R_18 = R_11+R_18;
                        R_2 = R_18+R_2; R_2 = (-1.0)*R_2; R_3 = R_2+R_3; R_4 = R_4+R_3;
                        R_4 = R_4*R_13; R_4 = (-1.0)*R_4; R_12 = R_4+R_12; R_12 = R_20*R_12;
                        R_12 = R_16+R_12; R_12 = R_9*R_12; V2 = R_12; R_12 = (-1.0)*R_12;
                        R_17 = R_12+R_17; R_17 = R_8*R_17; R_17 = R_3+R_17; R_13 = R_17*R_13;
                        U2 = R_13; 

                        T err = 1 + abs(U) + abs(V); err = (abs(U-U2) + abs(V-V2)) / err;
                        U = U2; V = V2;
                        if (err < tolerance ) break;
                        vi = TVI( U, V );
                        if (not( var_inter_is_inside( Quad(), vi, tolerance ) ) ) {
                            isSolution = false;
                            break;
                        }
                        //std::cout << "- " << t+1 << std::endl; PRINT( U ); PRINT( V  );
                    }
                    /// on teste notre solution (U, V) en évaluant la position en ce point (U, V).
                    if (isSolution) {
                        T R_0 = pos_nodes[2][1]; T R_1 = pos_nodes[3][1]; T R_2 = pos_nodes[0][1]; T R_3 = pos_nodes[1][1];
                        T R_4 = pos[1]; R_4 = (-1.0)*R_4; T R_5 = pos[0]; R_5 = (-1.0)*R_5;
                        T R_6 = pos_nodes[3][0]; T R_7 = pos_nodes[0][0]; T R_8 = pos_nodes[1][0]; T R_9 = V;
                        R_1 = R_1*R_9; R_6 = R_6*R_9; T R_10 = (-1.0)+R_9; T R_11 = (-1.0)*R_9;
                        T R_12 = 1.0+R_11; T R_13 = U; R_0 = R_0*R_13; R_0 = R_0*R_9;
                        R_3 = R_13*R_3; R_3 = R_3*R_12; T R_14 = (-1.0)*R_13; R_14 = 1.0+R_14;
                        R_1 = R_14*R_1; R_14 = R_6*R_14; R_10 = R_10*R_13; R_11 = R_10+R_11;
                        R_11 = 1.0+R_11; R_2 = R_11*R_2; R_2 = R_3+R_2; R_1 = R_2+R_1;
                        R_0 = R_1+R_0; R_0 = R_4+R_0; eval2 = R_0; R_11 = R_7*R_11;
                        R_8 = R_8*R_13; R_8 = R_12*R_8; R_11 = R_8+R_11; R_14 = R_11+R_14;
                        R_11 = pos_nodes[2][0]; R_13 = R_11*R_13; R_9 = R_13*R_9; R_14 = R_9+R_14;
                        R_5 = R_14+R_5; eval = R_5; 

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
#endif  /// GET_VAR_INTER__Quad
 
