#ifndef GET_VAR_INTER_COMMON_H
#define GET_VAR_INTER_COMMON_H
 
#include <vector>
#include <algorithm>
#include <containers/polynomials.h>
#include <containers/mat.h>
 
namespace LMT {
    
inline unsigned ind_2( unsigned i) { unsigned t = i*(i+1); return t/2; } 
inline unsigned ind_3( unsigned i) { unsigned t = i*(i+1)*(i+2); return t/6; } 

void display_poly_2X( unsigned N );    
    
/*!
    Cette fonction prend en paramètre un "polynôme" à 3 indéterminées X_0, X_1 et X_2 et l'évalue partiellement de sorte qu'il ne reste qu'un seule indéterminée X_ir. 

entrées : 
     * coef est un vecteur des coefficients d'un polynômes à trois indéterminées rangés l'ordre classique (degré total croissant).
     * ir est l'indice de l'indéterminée restante ( 0 correponsd  à la première indéterminée).
     * val sont les valeurs à substituer aux indéterminées dans l'ordre croissant d'indices.

sortie :
    renvoie ret, un vecteur des coefficients dans l'ordre suivant : 1, X, X^2, etc  
 */    

template<class T>
void coeff_2_to_1( Vec<T>& coeff, unsigned ir, T val, Vec<T>& ret ) {
    unsigned l0;
    unsigned l0_bound[2], i[2];
    T p;
    Vec<T,2> lval;
 
    switch(ir) {
        case 0 : lval[1] = val; break;
        case 1 : lval[0] = val; break;
        default : lval[0] = 0; lval[1] = 0;  
    }

    l0 = 0;
    l0_bound[0] = ind_2( 0 ); /// 0 = l0
    l0_bound[1] = ind_2( 1 ); /// 1 = l0 + 1
    for (unsigned n=0; n< coeff.size(); ++n) {
        if (n < l0_bound[1]) {
            i[1] = n-l0_bound[0];
            i[0] = l0 - i[1]; 
            /// évaluation
            if ( i[ir] >= ret.size() ) {
                ret.resize( i[ir]+1 );
                ret[i[ir]] = 0;
            }
            p = coeff[n];
            for( unsigned j=0; j<2 ; ++j )
                if (j != ir)        
                    p *= pow( lval[j], i[j] );
            ret[i[ir]] += p;
            /// fin de l'évaluation       
        } else {
            l0++;
            l0_bound[0] = l0_bound[1];
            l0_bound[1] = ind_2( l0+1 );
            i[0] = l0;
            i[1] = 0;
            /// évaluation
            if ( i[ir] >= ret.size() ) {
                ret.resize( i[ir]+1 );
                ret[i[ir]] = 0;
            }
            p = coeff[n];
            for( unsigned j=0; j<2 ; ++j )
                if (j != ir)        
                    p *= pow( lval[j], i[j] );
            ret[i[ir]] += p;
            /// fin de l'évaluation
        }
    }
}

void display_poly_3X( unsigned N );
    
/*!
Cette fonction prend en paramètre un "polynôme" à 3 indéterminées X_0, X_1 et X_2 et l'évalue partiellement de sorte qu'il ne reste qu'un seule indéterminée X_ir. 

entrées : 
        * coef est un vecteur des coefficients d'un polynômes à trois indéterminées rangés l'ordre classique (degré total croissant).
        * ir est l'indice de l'indéterminée restante ( 0 correponsd  à la première indéterminée).
        * val sont les valeurs à substituer aux indéterminées dans l'ordre croissant d'indices.

sortie :
        renvoie ret, un vecteur des coefficients dans l'ordre suivant : 1, X, X^2, etc  
*/    

template<class T>
void coeff_3_to_1( Vec<T>& coeff, unsigned ir, Vec<T,2> val, Vec<T>& ret ) {
    unsigned l0, l1;
    unsigned l0_bound[2], l1_bound[2], i[3];
    T p;
    Vec<T,3> lval;
    
    switch(ir) {
        case 0 : lval[1] = val[0]; lval[2] = val[1]; break;
        case 1 : lval[0] = val[0]; lval[2] = val[1]; break;
        case 2 : lval[0] = val[0]; lval[1] = val[1]; break;
        default : lval[0] = 0; lval[1] = 0; lval[2] = 0;  
    }

    l0 = 0;
    l0_bound[0] = 0; /// ind_3( l0 );
    l0_bound[1] = ind_3( 1 ); /// 1 = l0 + 1
    l1 = 0;
    l1_bound[0] = 0; /// ind_2( 0 );
    l1_bound[1] = ind_2( 1 ); /// 1 = l1 + 1
    for (unsigned n=0; n< coeff.size(); ++n) {
        //PRINT( n );// PRINT( l0_bound[0] ); PRINT( l0_bound[1] ); PRINT( l1_bound[0] ); PRINT( l1_bound[1] ); PRINT( l0 ); PRINT( l1 );
        if (n < l0_bound[1]) {
            if (n-l0_bound[0] < l1_bound[1] ) {
                i[2] = n - l0_bound[0] - l1_bound[0];
                i[1] = l1 - i[2];
                i[0] = l0 - i[1] - i[2];
                //std::cout << " i = " << i[0] << " , j = " << i[1] << " , k = " << i[2] << std::endl;
                /// évaluation
                if ( i[ir] >= ret.size() ) {
                    ret.resize( i[ir]+1 );
                    ret[i[ir]] = 0;
                }
                p = coeff[n];
                for( unsigned j=0; j<3 ; ++j )
                    if (j != ir)        
                        p *= pow( lval[j], i[j] );
                ret[i[ir]] += p;
                /// fin de l'évaluation
            } else {
                l1++;
                i[2] = 0;
                i[1] = l1;
                i[0] = l0 - i[1];
                //std::cout << " i = " << i[0] << " , j = " << i[1] << " , k = " << i[2] << std::endl;
                /// évaluation
                if ( i[ir] >= ret.size() ) {
                    ret.resize( i[ir]+1 );
                    ret[i[ir]] = 0;
                }
                p = coeff[n];
                for( unsigned j=0; j<3 ; ++j )
                    if (j != ir)        
                        p *= pow( lval[j], i[j] );
                ret[i[ir]] += p;
                /// fin de l'évaluation
                l1_bound[0] = l1_bound[1];
                l1_bound[1] = ind_2( l1+1 ); 
                //PRINT( l1_bound[0] ); PRINT( l1_bound[1] );     
            }
        } else {
        /// j=k=0 et i = l0
            l0++;
            i[0] = l0;
            i[1] = 0;
            i[2] = 0;
            //std::cout << " i = " << i[0] << " , j = " << i[1] << " , k = " << i[2] << std::endl;
            /// évaluation
            if ( i[ir] >= ret.size() ) {
                ret.resize( i[ir]+1 );
                ret[i[ir]] = 0;
            }
            p = coeff[n];
            for( unsigned j=0; j<3 ; ++j )
                if (j != ir)        
                    p *= pow( lval[j], i[j] );
            ret[i[ir]] += p;
            /// fin de l'évaluation
            l0_bound[0] = l0_bound[1];
            l0_bound[1] = ind_3( l0+1 );
            l1 = 0;
            l1_bound[0] = 0; /// ind_2( 0 );
            l1_bound[1] = ind_2( 1 ); /// 1 = l1 + 1 
        }
    
    }
}

template<class T>
unsigned nb_zero( const Vec<T>& v, unsigned start, unsigned end, T eps = 1e-4 ) {
    unsigned c = 0;
    for (unsigned i=start;i < end; ++i)
        if (abs( v[i] ) < eps)
            c++;
    return c;
}

template<class T>
unsigned nb_zero( const Vec<T>& v, Vec<unsigned>& non_null, unsigned start, unsigned end, T eps = 1e-4 ) {
    non_null.resize( 0 );
    unsigned c = 0;
    for (unsigned i=start;i < end; ++i)
        if (abs( v[i] ) < eps)
            c++;
        else
            non_null.push_back( i );
    return c;
}

template<class T>
unsigned deg_( const Vec<T>& v, T& term, T eps = 1e-4 ) {

    if (v.size() ==0) {
        term = 0;
        return 0;   
    }
    for (unsigned i= v.size()-1;i >0; --i)
        if (abs( v[i] ) > eps) {
            term = v[i];
            return i;        
        }
    term = v[0];
    return 0;
}

/*!
Cette fonction enlève toutes les valeurs de cut contenues dans v  

*/
void difference( std::vector<unsigned>& v, const std::vector<unsigned>& cut );

/*!
Cette fonction résout un système polynomial de 2 équations à 2 inconnues quasi linéaire au sens suivant :
    Parmi les deux équations, une est de la forme c0 - c1 X .
    Elle renvoie vrai si elle trouve un nombre fini de solutions et faux si le système n'est pas quasi linéaire ou si il y a une infinité de solutions.
    Les polynômes sont exprimés dans l'ordre classique de degré total croissant.

    Entrées :
        * syst[0], syst[1] les deux polynômes à deux indéterminés.
        * tol est la tolérance qu'on s'accorde sur la nullité d'un nombre.

    Sorties :
        * sol est la liste des solutions.

 */
template<class T>
bool solve_quasi_linear_polynomial_system_2X( Vec< Vec<T>, 2>& syst, Vec< Vec<T, 2> >& sol, T tol = 1e-4) {
    sol.resize( 0 );
    T t;
    unsigned n0 = deg_( syst[0], t, tol );
    unsigned n1 = deg_( syst[1], t, tol );
    bool b0 = (n0 <= 2);
    bool b1 = (n0 <= 2);
    if (not( b0 or b1 ))
        return false; /// système non quasi-linéaire
    
    unsigned ieq[2]; /// la première valeur est l' indices de l' équation linéaire et la dernière l'indice de l'autre équation polynomiale.
    Vec<unsigned> in ; /// indice des inconnues pour l' équation linéaire
    
    if (b0) {
        n0 = nb_zero( syst[0], in, 1, 3, tol );
        ieq[0] = 0; ieq[1] = 1;
    } else {
        n0 = nb_zero( syst[1], in, 1, 3, tol );
        ieq[0] = 1; ieq[1] = 0;
    }
    if ( n0 == 0 )
        return false; /// trop d'inconnues. En fait cette configuration demanderait de faire des substitutions et actuellement on ne sait faire.
    
    if (not( in.size() ))
        return false; /// aucune solution ou une infinité
    
    //PRINT( in ); PRINT( ieq[0] ); PRINT( ieq[1] );
    /// on résout :
    T soluLin = -syst[ ieq[0] ][0] / syst[ ieq[0] ][ in[0] ];
    //PRINT( soluLin );

    in[0]--; /// ir[0] était égal à l'indice de l'inconnue dans la liste des coeff du polynôme c0 + c1 X + c2 Y + c3 Z + c4 X^2 + ... donc on retranche 1 pour avoir l'indice de l'inconnue par rapport à la liste X_0, X_1.
    Vec<T> coeffs;
    coeff_2_to_1( syst[ieq[1]], 1-in[0], soluLin, coeffs );
    //PRINT( coeffs );
    Vec<T> solu = Pol<15,1,T>( coeffs ).real_roots(); /// le 15 est un problème
    for( unsigned i=0;i<solu.size(); ++i) {
        Vec<T, 2> oneSol;
        oneSol[ in[0] ] = soluLin;
        oneSol[ 1-in[0] ] = solu[i];
        //PRINT( oneSol );
        sol.push_back( oneSol );
    }
    //PRINT( solu );
    return true;
}





/*!
Cette fonction résout un système polynomial de 3 équations à 3 inconnues quasi linéaire au sens suivant :
    Parmi les trois équations, deux sont linéaires à deux inconnues.
Elle renvoie vrai si elle trouve un nombre fini de solutions et faux si le système n'est pas quasi linéaire ou si il y a une infinité de solutions.
Les polynômes sont exprimés dans l'ordre classqiue de degré total croissant.

Entrées :
    * syst[0], syst[1], syst[2], les trois polynômes à trois indéterminés.
    * tol est la tolérance qu'on s'accorde sur la nullité d'un nombre.

Sorties :
    * sol est la liste des solutions.

*/
template<class T>
bool solve_quasi_linear_polynomial_system_3X( Vec< Vec<T>, 3>& syst, Vec< Vec<T, 3> >& sol, T tol = 1e-4) {
    
    sol.resize( 0 );
    T t;
    unsigned n0 = deg_( syst[0], t, tol );
    unsigned n1 = deg_( syst[1], t, tol );
    unsigned n2 = deg_( syst[2], t, tol );
    bool b0 = (n0 <= 4) and (n1 <= 4);
    bool b1 = (n0 <= 4) and (n2 <= 4);
    bool b2 = (n2 <= 4) and (n1 <= 4);
    if (not( b0 or b1 or b2 ))
        return false; /// système non quasi-linéaire
    
    unsigned ieq[3]; /// les deux premières valeurs sont les indices des équations linéaires et la dernière l'indice de l'autre équation polynomiale.
    Vec< Vec<unsigned>, 2 > in ; /// indice des inconnues pour chaque équation
    
    if (b0) {
        n0 = nb_zero( syst[0], in[0], 1, 4, tol );
        n1 = nb_zero( syst[1], in[1], 1, 4, tol );
        ieq[0] = 0; ieq[1] = 1; ieq[2] = 2;
    } else if (b1) {
        n0 = nb_zero( syst[0], in[0], 1, 4, tol );
        n1 = nb_zero( syst[2], in[1], 1, 4, tol );
        ieq[0] = 0; ieq[1] = 2; ieq[2] = 1;
    } else {
        n0 = nb_zero( syst[1], in[0], 1, 4, tol );
        n1 = nb_zero( syst[2], in[1], 1, 4, tol );
        ieq[0] = 1; ieq[1] = 2; ieq[2] = 0;
    }
    if (( n0 == 0 ) or ( n1 == 0 ))
        return false; /// trop d'inconnues
    
    if (not( in[0].size() ))
        return false; /// aucune solution ou une infinité
    
    if (not( in[1].size() ))
        return false; /// aucune solution ou une infinité

    //PRINT( ieq[0] ); PRINT( ieq[1] ); PRINT( ieq[2] ); PRINT( in[0] ); PRINT( in[1] );
    std::vector<unsigned> nb_unknown;/// on détermine les indices de touts les inconnues.
    for(unsigned i = 0; i < in.size(); ++i )
        for(unsigned j = 0; j < in[i].size(); ++j ) {
            unsigned k;
            for(k = 0; k < nb_unknown.size(); ++k )
                if (nb_unknown[k] == in[i][j])
                    break;
            if (k == nb_unknown.size())
                nb_unknown.push_back( in[i][j] );
        }
    sort( nb_unknown.begin(), nb_unknown.end() );
    //for ( unsigned t = 0 ; t < nb_unknown.size(); ++t) std::cout << " un[" << t << "] = " << nb_unknown[t] << std::endl; 
    if ( (nb_unknown.size() >= 3) or (nb_unknown.size() <= 1) )
       return false;  /// trop d'inconnues ou pas assez
    
    /// on recherche l'inconnue restante
    std::vector<unsigned> ir;
    ir.resize(3); ir[0] = 1; ir[1] = 2; ir[2] = 3;
    difference( ir, nb_unknown ); 
    //for ( unsigned t = 0 ; t < ir.size(); ++t) std::cout << " ir[" << t << "] = " << ir[t] << std::endl;
    if (ir.size() != 1)
        return false;
    ir[0]--; /// ir[0] était égal à l'indice de l'inconnue dans la liste des coeff du polynôme c0 + c1 X + c2 Y + c3 Z + c4 X^2 + ... donc on retranche 1 pour avoir l'indice de l'inconnue.
    
    Mat<T> M(2,2,0.);
    Vec<T,2> b; //, solu;
    for( unsigned i=0;i<in.size(); ++i)
        for( unsigned j=0;j<in[i].size(); ++j) {
            unsigned jj = 0;
            for ( unsigned t = 0 ; t < nb_unknown.size(); ++t)
                if ( nb_unknown[t] == in[i][j] ) {
                    jj = t;
                    break;
                }
            M(i,jj) = syst[ieq[i]][ in[i][j] ];
        }
    /// second membre = - terme  constant des polynômes
    b[0] = -syst[ieq[0]][0]; 
    b[1] = -syst[ieq[1]][0];
    //PRINTN( M ); PRINT( b );
    //for ( unsigned t = 0 ; t < nb_unknown.size(); ++t) std::cout << " un " << nb_unknown[t] << std::endl; 
    //for ( unsigned t = 0 ; t < ir.size(); ++t) std::cout << " ir " << ir[t] << std::endl;
    Vec<T, 2> soluLin = inv( M ) * b;
    //PRINT( soluLin ); PRINT( ir[0] ); PRINT( syst[ieq[2]] );
    /// s'il y a des solutions, on continue
    Vec<T> coeffs;
    coeff_3_to_1( syst[ieq[2]], ir[0], soluLin, coeffs );
    //PRINT( coeffs );
    Vec<T> solu = Pol<15,1,T>( coeffs ).real_roots(); /// le 15 est un problème
    for ( unsigned t = 0 ; t < nb_unknown.size(); ++t) nb_unknown[t]--; /// les indices sont décalées à cause du terme constant du polynôme
    for( unsigned i=0;i<solu.size(); ++i) {
        Vec<T, 3> oneSol;
        for ( unsigned t = 0 ; t < nb_unknown.size(); ++t)
            oneSol[ nb_unknown[t] ] = soluLin[t];
        oneSol[ ir[0] ] = solu[i];
        //PRINT( oneSol );
        sol.push_back( oneSol );
    }
    //PRINT( solu );
    return true;
}
    
}

#endif  /// GET_VAR_INTER_COMMON
 
