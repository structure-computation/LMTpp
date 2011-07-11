#ifndef SYSTEM_POLY_COMMON_H
#define SYSTEM_POLY_COMMON_H

#include <assert.h>

#include "Poly.h"

#include "polynomials.h" /// ret_roots_by_companion_matrix()
#include "determinant.h"
#include "util/combinatorialiterator.h"

namespace LMT {

/*!
    Objectif :
        placer dans un vecteur la valeur des coéfficients des monômes d'un polynôme suivant un certain ordre monomial ???
    
    Paramètres :
        * coef est le vecteur qui recevra les coefficients
        * p est le polynôme
        * name est la liste des noms de variable du polynôme
        * nb_name est le nombre de noms
        
*/
template<unsigned nb_name,int s, class T, int s2 >
void fill_coef( Vec<T, s >& coef, const Poly<T> &p, Vec<char, s2> &name, Number<nb_name> ) {
    assert( 0 );
}

template<int s, class T, int s2 >
void fill_coef( Vec<T, s >& coef, const Poly<T> &p, Vec<char, s2> &name, Number<2> ) {
    coef.set( 0 );
    
    for( unsigned i = 0; i < p.monom_list.size(); ++i ) {
        unsigned index = 0;
        unsigned dt = p.monom_list[ i ].total_degree();
        dt *= ( dt + 1 ); dt >>= 1; 
        if ( p.monom_list[ i ].expo.size() == 2 ) {
            index = dt + p.monom_list[ i ].expo[ 1 ];
        } else if ( p.monom_list[ i ].expo.size() == 1 ) {
            if ( p.monom_list[ i ].name[ 0 ] == name[ 0 ] )
                index = dt;
            else
                index = dt + p.monom_list[ i ].expo[ 0 ];
        }
        if ( index < coef.size() )
            coef[ index ] = p.monom_list[ i ].coef;
    }
}

// template<int s, class T, class TTOL, int s2 >
// void fill_coef( Vec<T, s >& coef, const Poly<T, TTOL> &p, Vec<char, s2> &name, Number<3> ) {
//     coef.set( 0 );
// }
/*!
    Objectif :
        évaluer une fonction polynomiale en les indéterminées vi 
        
    Paramètres :
        * coef sont les coefficients du polynôme rangés dans l'ordre "classique" ( e.g. 1 U V U^2 UV V^2 U^3 U^2V ... en deux indéterminées )
        * valeur des indéterminées.
         
    Retour
        renvoie l'image de vi.
*/
template<class T, int s, int s2>
T polyres( const Vec<T,s> &coef, const Vec<T,s2> &vi ) {
    assert( 0 );
    return T( 0 );
}

template<class T, int s >
T polyres( const Vec<T,s> &coef, const Vec<T,2> &vi ) {
    T ret = 0;
    Vec<unsigned, 2> expo;
    
    for( unsigned i = 0, inf = 0, sup = 1, h = 1; i < coef.size(); ++i ) {
        
        if ( i == sup ) {
            inf += h;
            ++h;
            sup += h;
        }
        
        expo[ 1 ] = i - inf;
        expo[ 0 ] = h - expo[ 1 ] - 1;
        
        T p = coef[ i ];
        for( unsigned j = 0; j < 2; ++j )
            if ( expo[ j ] )
                p *= std::pow( vi[ j ], expo[ j ] );
        ret += p;
    }
    
    return ret;
}

template<class T, int s >
T polyres( const Vec<T,s> &coef, const Vec<T,3> &vi ) {
    T ret = 0;
    Vec<int, 2> expo;
    int inf = 0, sup = 1, inf2 = 0, sup2 = 1, h = 1, h2 = 1, i2;
    
    for( int i = 0; i < coef.size(); ++i ) {
        
        if ( i == sup ) {
            inf += h * ( h + 1 ) / 2;
            ++h;
            sup += h * ( h + 1 ) / 2;
            inf2 = 0;
            sup2 = 1;
            h2 = 1;
        }
        
        i2 = i - inf;
        if ( i2 == sup2 ) {
            inf2 += h2;
            ++h2;
            sup2 += h2;
        }        
        i2 -= inf2; 
        expo[ 2 ] = i2;
        expo[ 1 ] = h2 - i2 - 1;
        expo[ 0 ] = h - h2;

        T p = coef[ i ];
        for( unsigned j = 0; j < 3; ++j )
            if ( expo[ j ] )
                p *= std::pow( vi[ j ], expo[ j ] );
        ret += p;        
    }
    
    return ret;
}

template<class T >
bool extract_if_linear( Poly<T> &ret, unsigned char _name, const Poly<T> &p ) {

    unsigned k = 0;
    bool isPossible = false;
    
    ret.vanish();
    
    for( unsigned i = 0; i < p.monom_list.size(); ++i ) {
        unsigned j = p.monom_list[ i ].name.find( _name );
        if ( j < p.monom_list[ i ].name.size() ) {
            if ( p.monom_list[ i ].expo[ j ] > 1 )
                return false;
            else {
                if ( ( p.monom_list[ i ].name.size() == 1 ) and ( p.monom_list[ i ].coef != 0 ) ) {
                    k = i;
                    isPossible = true;
                } else
                    return false;
            }
        }
    }
    
    if ( isPossible ) {
        for( unsigned i = 0; i < k; ++i )
            ret.add( p.monom_list[ i ] );
        for( unsigned i = k + 1; i < p.monom_list.size(); ++i )
            ret.add( p.monom_list[ i ] );
        T mul = -1 / p.monom_list[ k ].coef;
        for( unsigned i = 0; i < ret.monom_list.size(); ++i )
            ret.monom_list[ i ].coef *= mul;
    }
    
    return isPossible;
}

template<class T >
bool extract_if_linear( Vec< Poly<T>, 2 > &ret, const Vec< char, 2 > _name, const Vec< Poly<T>, 2 > &p ) {
    
    bool isPossible = false;
    
    return isPossible;
}

/*!
    Objectif: 
        Déterminer les racines du polynôme coef[0] + coef[1] X + ... coef[ coef.size()-1 ] X**( coef.size()-1 ) dans T.
        
    Paramètre :
        * sol est le vecteur contenant les racines qui ont été calculées. Ces racines sont du même type que les coefficients.
        * coef est le vecteur contenant les coefficients.
    
    Retour :
        renvoie vrai si le calcul n'a pas posé de problème.
        
    Remarque : résoudre un polynôme n'est pas facile, surtout il y a des racines multiples ou s'il y a un paquet de racines voisines (cluster). 
    Dans ces derniers cas, la précision sur les racines est de l'ordre de epsilon**( 1 / k ) où epsilon est la précision sur les coefficients et k est l'ordre ou le nombre de racines dans le paquet. On a essayé de gérer ce problème dans le cas où certaines racines du paquet sont complexes.
    Précisément pour des racines complexes proches de l'axe réel, on a essayé d'évaluer une estmation de la précision de la racine en supposant qu'on avait une précision maximale sur les coefficients (i.e. de l'ordre de numeric_limits<T>::epsilon() ) et on a considéré que la racine était réelle lorsque cette estimation était proche de la valeur absolue de sa partie imaginaire.
    En faisant un développement de Taylor et en notant k l'ordre de s la solution et P = p0 + p1 X + ... + pn X**n le polynôme on trouve 
    \latex
         \delta s ~ \sqrt[k]{ \frac{ k! }{ P^(k)( s ) } sum_{j=0}^n \delta p_j s^{j}
    où delta_P = delta_p0 + delta_p1 X + ... + delta_pn X**n 
    Réf : 
    *   le livre de Durand sur la résolution des équations algébriques Tome 1
    *   tous les travaux de Mr Dario Andrea Bini ( cf MPSolve ). 
      
*/
template<class T, int s >
bool solve_polynomial_system( Vec<T> &sol, const Vec<T, s> &coef ) {
    typedef std::complex<T> C;

    sol.resize( 0 );
    int deg = coef.size() - 1;
    for( unsigned i = 0; i < coef.size(); ++i )
        if ( std::abs( coef[ deg ] ) )
            break;
        else
            deg--; 

    switch( deg ) {
        case -1 : case 0 : return false;
        case 1  :{  sol.push_back( -coef[ 0 ] / coef[ 1 ] ); } break;
        case 2  :{  T den = 1 / coef[ 2 ];
                    T b = coef[ 1 ] * den;
                    T c = coef[ 0 ] * den;
                    T delta = b * b - 4 * c;
                    if (delta > 0. ) {
                        /// soit e1 = | A - B | et e2 = | A + B |. Pour éviter une erreur de cancellation, on choisit entre A-B et A+B suivant la plus grande valeur entre e1 et e2.
                        T rd = sqrt( delta );
                        if ( std::abs( b + rd ) > std::abs( b - rd ) ) {
                            sol.push_back( -2 * c / ( b + rd ) );
                            sol.push_back( -0.5 * ( b + rd ) );
                        } else {
                            sol.push_back( -2 * c / ( b - rd ) );
                            sol.push_back( -0.5 * ( b - rd ) );
                        }
                        return true;
                    }
                    if ( std::abs( delta ) < 32 * ( 2 + std::abs( b ) ) * std::numeric_limits<T>::epsilon() ) {
                        /// delta proche de zéro et on est dans une situation où de petits écarts sur les coefficients entraînent de grandes différences sur les solutions.
                        sol.push_back( -0.5 * b );
                        return true; 
                    } 
                 } break;
        case 3  :{ /// http://fr.wikipedia.org/wiki/Méthode_de_Cardan
                    T den = 1 / coef[ 3 ];
                    T a   = coef[2] * den;
                    T b   = coef[1] * den;
                    T c   = coef[0] * den;
                    T p   = b - std::pow( a, 2 ) / 3.;
                    T q   = std::pow( a, 3 ) / 13.5 - a * b / 3 + c;
                    T delta = 4 * std::pow(p, T(3) ) + 27 * std::pow( q, T(2) );
                    if ( delta >= 0 ) {
                        T u=(-13.5*q+sqrt(6.75*delta));
                        T v=(-13.5*q-sqrt(6.75*delta));    
                        sol.push_back(( sgn(u) * std::pow( std::abs(u), 1/T(3) ) + sgn(v) * std::pow( std::abs(v), 1/T(3) ) - a) / 3 );
                        
                    }
                    if ( delta < 0 ) {
                        C j( -0.5, sqrt( 3. )/2. );
                        C v( -13.5 * q, sqrt( -6.75 * delta ) );
                        C u = std::pow( v, T(1) / T(3) );
                        sol.push_back((2.*std::real(u)-a)/3.);
                        sol.push_back((2.*std::real(j*u)-a)/3.);
                        sol.push_back((2.*std::real(j*j*u)-a)/3.);
                    }
                } break;
        default :{  Vec<C> solc; 
                    Vec<T> pd; pd.resize( coef.size() - 2 );
                     
                    ret_roots_by_companion_matrix( coef, coef.size() - 1, solc );
                    for( int i = 0; i < solc.size(); ++i ) {
                    
                        if ( solc[ i ].imag() == 0 ) {
                                sol.push_back( solc[ i ].real() );
                                continue;
                        }
                        
                        if ( ( std::abs( solc[i].imag() ) < 0.51 ) and ( solc[i].imag() > 0 ) ) {
                            //std::cout << "===========" << i << setprecision( 18 ) << std::endl;
                            //PRINT( solc[ i ] );
                            pd[ 0 ] = coef.back();
                            for( unsigned j = 1; j < pd.size(); ++j ) 
                                pd[ j ] = 0;
                            
                            for( int k = coef.size() - 2; k >= 0; k-- ) {
                                int nnd = ( pd.size() < coef.size() - k ) ? pd.size() - 1 : ( coef.size() - 1 - k );
                                for( int l = nnd; l > 0; l-- )
                                    pd[ l ] = pd[ l ] * solc[ i ].real() + pd[ l - 1 ];
                                pd[ 0 ] = pd[ 0 ] * solc[ i ].real() + coef[ k ];
                            }

                            for( int k = 0; k < pd.size(); ++k )
                                pd[ k ] = std::abs( pd[ k ] );
                                
                            //for( int k = 0; k < pd.size(); ++k )
                            //    PRINT( pd[ k ] );
                            
                            if ( pd[ 0 ] > std::ldexp( 1, 4 - ( std::numeric_limits<T>::digits >> 1 ) ) )
                                continue;
                                            
                            pd[ 0 ] = std::ldexp( pd[ 0 ] + std::numeric_limits<T>::epsilon(), 10 );
                            for( int k = 1; k < pd.size(); ++k ) {
                                if ( pd[ k ] > pd[ 0 ] ) {
                                    T rac = std::abs( solc[ i ] ), som = 1, rac_pow = rac;
                                    for( int l = 1; l <= coef.size(); ++l ) {
                                        som += rac_pow;
                                        rac_pow *= rac;
                                    }
                                    //PRINT( k ); PRINT( som );
                                    //PRINT( std::ldexp( std::pow( som  / pd[ k ] * std::numeric_limits<T>::epsilon(), 1 / (T)k ), 8 ) );
                                    if ( std::abs( solc[ i ].imag() ) < std::ldexp( std::pow( som  / pd[ k ] * std::numeric_limits<T>::epsilon(), 1 / (T)k ), 8 ) )
                                        sol.push_back( solc[ i ].real() );
                                    break;
                                }
                            }
                            
                        }
                    }
                 } break;
    }
    return true;
}

template<class T, int s >
bool solve_polynomial_system( Vec< std::complex<T> > &sol, const Vec<T, s> &coef ) {
    typedef std::complex<T> C;

    sol.resize( 0 );
    int deg = coef.size() - 1;
    for( unsigned i = 0; i < coef.size(); ++i )
        if ( std::abs( coef[ deg ] ) )
            break;
        else
            deg--; 

    switch( deg ) {
        case -1 : case 0 : return false;
        case 1  :{  sol.push_back( C( -coef[ 0 ] / coef[ 1 ], 0 ) ); return true; } break;
        case 2  :{  T den = 1 / coef[ 2 ];
                    T b = coef[ 1 ] * den;
                    T c = coef[ 0 ] * den;
                    T delta = b * b - 4 * c;
                    if (delta > 0. ) {
                        /// soit e1 = | A - B | et e2 = | A + B |. Pour éviter une erreur de cancellation, on choisit entre A-B et A+B suivant la plus grande valeur entre e1 et e2.
                        T rd = sqrt( delta );
                        if ( std::abs( b + rd ) > std::abs( b - rd ) ) {
                            sol.push_back( C( -2 * c / ( b + rd ), 0 ) );
                            sol.push_back( C( -0.5 * ( b + rd ), 0 ) );
                        } else {
                            sol.push_back( C( -2 * c / ( b - rd ), 0 ) );
                            sol.push_back( C( -0.5 * ( b - rd ), 0 ) );
                        }
                        return true;
                    }
                    if ( std::abs( delta ) < 32 * ( 2 + std::abs( b ) ) * std::numeric_limits<T>::epsilon() ) {
                        /// delta proche de zéro et on est dans une situation où de petits écarts sur les coefficients entraînent de grandes différences sur les solutions.
                        sol.push_back( C( -0.5 * b, 0 ) );
                        return true;
                    }
                    
                    T rd = 0.5 * sqrt( -delta );
                    T bp = -0.5 * b;
                    sol.push_back( C( bp,  rd ) );
                    sol.push_back( C( bp, -rd ) );
                    return true;                    
                    
                 } break;
        case 3  :{ /// http://fr.wikipedia.org/wiki/Méthode_de_Cardan
                    T den = 1 / coef[ 3 ];
                    T a   = coef[2] * den;
                    T b   = coef[1] * den;
                    T c   = coef[0] * den;
                    T p   = b - std::pow( a, 2 ) / 3.;
                    T q   = std::pow( a, 3 ) / 13.5 - a * b / 3 + c;
                    T delta = 4 * std::pow(p, 3 ) + 27 * std::pow( q, 2 );
                    C  j( -0.5, sqrt( 3. )/2. );
                    C cj( -0.5, -sqrt( 3. )/2. );
                    if ( delta >= 0 ) {
                        T u = -13.5 * q + sqrt( 6.75 * delta );
                        T v = -13.5 * q - sqrt( 6.75 * delta );
                        u = sgn(u) * std::pow( std::abs(u), 1/T(3) );
                        v = sgn(v) * std::pow( std::abs(v), 1/T(3) );
                        sol.push_back( C( ( u + v - a ) / 3, 0 ) );
                        C z1 = u * j + v * cj;
                        sol.push_back( z1 - a / 3 );
                        sol.push_back( conj( z1 ) - a / 3 );
                    }
                    if ( delta < 0 ) {
                        C j( -0.5, sqrt( 3. )/2. );
                        C v( -13.5 * q, sqrt( -6.75 * delta ) );
                        C u = std::pow( v, T(1) / T(3) );
                        sol.push_back( C( (2.*std::real(u)-a)/3., 0 ) );
                        sol.push_back( C( (2.*std::real(j*u)-a)/3., 0 ) );
                        sol.push_back( C( (2.*std::real(j*j*u)-a)/3., 0 ) );
                    }
                } break;
        default :{  Vec<C> solc; 
                    Vec<T> pd; pd.resize( coef.size() - 2 );
                     
                    ret_roots_by_companion_matrix( coef, coef.size() - 1, solc );
                    for( int i = 0; i < solc.size(); ++i ) {
                    
                        if ( solc[ i ].imag() == 0 ) {
                                sol.push_back( C( solc[ i ].real(), 0 ) );
                                continue;
                        }
                        
                        if ( std::abs( solc[i].imag() ) >= 0.5 ) {
                            sol.push_back( solc[ i ] );
                            continue;
                        }
                        
                        /// on a peut être une racine réelle...
                        /// on calcule les dérivées en ce point pour évaluer la précision maximale qu'on peut avoir de la racine en supposant qu'on avait une précision maximale sur les coefficients du polynôme.
                        if ( ( std::abs( solc[i].imag() ) < 0.5 ) and ( solc[i].imag() > 0 ) ) {
                            //std::cout << "===========" << i << setprecision( 18 ) << std::endl;
                            //PRINT( solc[ i ] );
                            pd[ 0 ] = coef.back();
                            for( unsigned j = 1; j < pd.size(); ++j ) 
                                pd[ j ] = 0;
                            
                            for( int k = coef.size() - 2; k >= 0; k-- ) {
                                int nnd = ( pd.size() < coef.size() - k ) ? pd.size() - 1 : ( coef.size() - 1 - k );
                                for( int l = nnd; l > 0; l-- )
                                    pd[ l ] = pd[ l ] * solc[ i ].real() + pd[ l - 1 ];
                                pd[ 0 ] = pd[ 0 ] * solc[ i ].real() + coef[ k ];
                            }

                            for( int k = 0; k < pd.size(); ++k )
                                pd[ k ] = std::abs( pd[ k ] );
                                
                            //for( int k = 0; k < pd.size(); ++k )
                            //    PRINT( pd[ k ] );
                            
                            if ( pd[ 0 ] > std::ldexp( 1, 4 - ( std::numeric_limits<T>::digits >> 1 ) ) ) { /// on n'a pas de cluster ou de racine multiple
                                sol.push_back( solc[ i ] );
                                sol.push_back( std::conj( solc[ i ] ) );
                                continue;
                            }
                                            
                            pd[ 0 ] = std::ldexp( pd[ 0 ] + std::numeric_limits<T>::epsilon(), 10 );
                            bool is_real = false;
                            for( int k = 1; k < pd.size(); ++k ) {
                                if ( pd[ k ] > pd[ 0 ] ) {
                                    T rac = std::abs( solc[ i ] ), som = 1, rac_pow = rac;
                                    for( int l = 1; l <= coef.size(); ++l ) {
                                        som += rac_pow;
                                        rac_pow *= rac;
                                    }
                                    //PRINT( k ); PRINT( som );
                                    //PRINT( std::ldexp( std::pow( som  / pd[ k ] * std::numeric_limits<T>::epsilon(), 1 / (T)k ), 8 ) );
                                    if ( std::abs( solc[ i ].imag() ) < std::ldexp( std::pow( som  / pd[ k ] * std::numeric_limits<T>::epsilon(), 1 / (T)k ), 8 ) ) {
                                        sol.push_back( C( solc[ i ].real(), 0 ) );
                                        is_real = true;
                                    }
                                    break;
                                }
                            }
                            
                            if ( not ( is_real ) ) {
                                sol.push_back( solc[ i ] );
                                sol.push_back( std::conj( solc[ i ] ) );                           
                            }
                            
                        }
                    }
                 } break;
    }
    return true;
}

/*!
    Objectif :
        Cette fonction tente de résoudre le système polynomiale en les inconnues ( U, V ) :
            F2_quad := f[0]+f[1]*U+f[2]*V+f[4]*U*V = 0
            G2_quad := g[0]+g[1]*U+g[2]*V+g[4]*U*V = 0
            
        qui correspond à un \a Quad .
        On est conduit à résoudre une équation du second degré via la théorie du résultant.

*/
template<class T>
bool solve_polynomial_system_resultant_2_par( Vec< Vec<T, 2> > &sol, const Vec<T,6> &f, const Vec<T, 6> &g ) {

    T repsi = std::ldexp( 1, 4 - ( std::numeric_limits<T>::digits >> 1 ) );
    sol.resize( 0 );
    Vec<T, 3> coef;
    /// résultant suivant V, la deuxième indéterminée.  
    coef[ 0 ] = g[0]*f[2]-f[0]*g[2];
    coef[ 1 ] = g[0]*f[4]+g[1]*f[2]-f[0]*g[4]-f[1]*g[2];
    coef[ 2 ] = g[1]*f[4]-f[1]*g[4];
    
    Vec<T> sol1;
    bool ret = solve_polynomial_system( sol1, coef );
    if ( ret ) {
        for( unsigned i = 0; i < sol1.size(); ++i ) {
            T U = sol1[ i ];
            T c1  = f[2] + f[4] * U;
            T c11 = g[2] + g[4] * U;
            T V;
            if ( std::abs( c1 ) > std::abs( c11 ) ) {
                V = ( -f[0] - f[1] * U ) / c1;
                if ( std::abs( g[0]+g[1]*U+g[2]*V+g[4]*U*V ) < repsi )
                    sol.push_back( Vec<T, 2>( U, V ) );
            } else {
                if ( c11 ) {
                    V = ( -g[0] - g[1] * U ) / c11;
                    if ( std::abs( f[0]+f[1]*U+f[2]*V+f[4]*U*V ) < repsi )
                    sol.push_back( Vec<T, 2>( U, V ) );
                } else
                    return false;
            }
        }
        return true;
    }
    
    /// résultant suivant U, la deuxième indéterminée.  
    coef[ 0 ] = g[0]*f[1]-f[0]*g[1];
    coef[ 1 ] = g[0]*f[4]+f[1]*g[2]-f[0]*g[4]-g[1]*f[2];
    coef[ 2 ] = g[2]*f[4]-f[2]*g[4];
    
    ret = solve_polynomial_system( sol1, coef );
    if ( ret ) {
        for( unsigned i = 0; i < sol1.size(); ++i ) {
            T V = sol1[ i ];
            T c1  = f[1] + f[4] * V;
            T c11 = g[1] + g[4] * V;
            T U;
            if ( std::abs( c1 ) > std::abs( c11 ) ) {
                U = ( -f[0] - f[2] * sol1[ i ] ) / c1;
                if ( std::abs( g[0]+g[1]*U+g[2]*V+g[4]*U*V ) < repsi )
                    sol.push_back( Vec<T, 2>( U, V ) );
            } else {
                if ( c11 ) {
                    U = ( -g[0] - g[2] * V ) / c11;
                    if ( std::abs( f[0]+f[1]*U+f[2]*V+f[4]*U*V ) < repsi )
                        sol.push_back( Vec<T, 2>( U, V ) );
                } else
                    return false;
            }
        }
    }
        
    return ret;
}

// template<class T>
// bool less_at_three( const Vec<T,3> &a, const Vec<T,3> &b ) {
//     return a[ 2 ] < b[ 2 ];
// }

struct Less_at_three {
    template<class T>
    bool operator()( const Vec<T,3> &a, const Vec<T,3> &b ) const {
        return a[ 2 ] < b[ 2 ];
    }
};

/*!
    Objectif :
        Cette fonction tente de résoudre le système polynomiale en les inconnues ( U, V ) :
            F2 := f[0]+f[1]*U+f[2]*V+f[3]*U^2+f[4]*U*V+f[5]*V^2 = 0
            G2 := g[0]+g[1]*U+g[2]*V+g[3]*U^2+g[4]*U*V+g[5]*V^2 = 0
            
        qui correspond au cas général en degré 2.
        On est conduit à résoudre une équation du degré 4 via la théorie du résultant.

*/
template<class T>
bool solve_polynomial_system_resultant_2( Vec< Vec<T, 2> > &sol, const Vec<T,6> &f, const Vec<T, 6> &g ) {

    typedef Vec<T, 2> V2;

    sol.resize( 0 );
    Vec<T, 5> coef;
    Vec<V2> residu_list;
    T repsi = std::ldexp( 1, 4 - ( std::numeric_limits<T>::digits >> 1 ) );

    /// résultant suivant V, la deuxième indéterminée.  
    coef[ 0 ] = g[0]*g[5]*f[2]*f[2]+f[5]*f[5]*g[0]*g[0]-2*g[5]*f[0]*f[5]*g[0]-g[2]*g[5]*f[2]*f[0]+f[5]*g[2]*g[2]*f[0]+g[5]*g[5]*f[0]*f[0]-g[2]*f[2]*f[5]*g[0];
    coef[ 1 ] =  -g[2]*f[2]*f[5]*g[1]+2*g[5]*g[5]*f[0]*f[1]+g[1]*g[5]*f[2]*f[2]-2*g[5]*f[0]*f[5]*g[1]-2*g[5]*f[1]*f[5]*g[0]+2*f[5]*f[5]*g[1]*g[0]-g[2]*g[5]*f[2]*f[1]-g[2]*g[5]*f[4]*f[0]-g[2]*f[4]*f[5]*g[0]+f[5]*g[2]*g[2]*f[1]+2*g[2]*f[5]*g[4]*f[0]-g[4]*g[5]*f[2]*f[0]-g[4]*f[2]*f[5]*g[0]+2*g[0]*g[5]*f[2]*f[4];
    coef[ 2 ] =  g[5]*g[5]*f[1]*f[1]+2*g[5]*g[5]*f[0]*f[3]+f[5]*f[5]*g[1]*g[1]+g[0]*g[5]*f[4]*f[4]+g[3]*g[5]*f[2]*f[2]-2*g[5]*f[0]*f[5]*g[3]-2*g[5]*f[1]*f[5]*g[1]-2*g[5]*f[3]*f[5]*g[0]+2*f[5]*f[5]*g[3]*g[0]-g[2]*g[5]*f[2]*f[3]-g[2]*f[2]*f[5]*g[3]-g[2]*g[5]*f[4]*f[1]-g[2]*f[4]*f[5]*g[1]+f[5]*g[2]*g[2]*f[3]+2*f[5]*g[2]*g[4]*f[1]-g[4]*g[5]*f[2]*f[1]-g[4]*f[2]*f[5]*g[1]-g[4]*g[5]*f[4]*f[0]-g[4]*f[4]*f[5]*g[0]+g[4]*g[4]*f[5]*f[0]+2*g[1]*g[5]*f[2]*f[4];
    coef[ 3 ] =  2*g[5]*g[5]*f[1]*f[3]+g[1]*g[5]*f[4]*f[4]-2*g[5]*f[1]*f[5]*g[3]-2*g[5]*f[5]*g[1]*f[3]+2*f[5]*f[5]*g[1]*g[3]-g[2]*g[5]*f[4]*f[3]-g[2]*f[4]*f[5]*g[3]+2*f[5]*g[2]*g[4]*f[3]-g[4]*g[5]*f[2]*f[3]-g[4]*f[2]*f[5]*g[3]-g[4]*g[5]*f[4]*f[1]-g[4]*f[4]*f[5]*g[1]+g[4]*g[4]*f[5]*f[1]+2*g[3]*g[5]*f[2]*f[4];
    
    coef[ 4 ] = g[5]*g[5]*f[3]*f[3]+f[5]*f[5]*g[3]*g[3]+g[3]*g[5]*f[4]*f[4]-2*g[5]*f[3]*f[5]*g[3]-g[4]*g[5]*f[4]*f[3]-g[4]*f[4]*f[5]*g[3]+g[4]*g[4]*f[5]*f[3];
    
    Vec<T> sol1;
    bool ret = solve_polynomial_system( sol1, coef );
    
    if ( ret ) {
        for( unsigned i = 0; i < sol1.size(); ++i ) {
            Vec<T, 3> coef2; /// f[0]+f[1]*U+f[2]*V+f[3]*U^2+f[4]*U*V+f[5]*V^2
            T U = sol1[i];
            coef2[ 0 ] = f[0] + U * ( f[1] + f[3] * U );
            coef2[ 1 ] = f[2] + f[4] * U;
            coef2[ 2 ] = f[5];
            Vec<T> sol2;
            T V;
            bool ret2 = solve_polynomial_system( sol2, coef2 );
            if ( ret2 ) {
                for( unsigned j = 0; j < sol2.size(); ++j ) {
                    V = sol2[j];
                    V2 residu( f[0]+f[1]*U+f[2]*V+f[3]*U*U+f[4]*U*V+f[5]*V*V, g[0]+g[1]*U+g[2]*V+g[3]*U*U+g[4]*U*V+g[5]*V*V );
                    if ( max( std::abs( residu[ 0 ] ), std::abs( residu[ 1 ] ) ) < repsi ) {
                        sol.push_back( V2( U, V ) );
                        residu_list.push_back( residu );
                    }
                }
            } else {
                /// g[0]+g[1]*U+g[2]*V+g[3]*U^2+g[4]*U*V+g[5]*V^2
                coef2[ 0 ] = g[0] + sol1[i] * ( g[1] + g[3] * U );
                coef2[ 1 ] = g[2] + g[4] * sol1[i];
                coef2[ 2 ] = g[5];
                ret2 = solve_polynomial_system( sol2, coef2 );
                if ( ret2 ) {
                    for( unsigned j = 0; j < sol2.size(); ++j ) {
                        V = sol2[j];
                        V2 residu( f[0]+f[1]*U+f[2]*V+f[3]*U*U+f[4]*U*V+f[5]*V*V, g[0]+g[1]*U+g[2]*V+g[3]*U*U+g[4]*U*V+g[5]*V*V );
                        if ( max( std::abs( residu[ 0 ] ), std::abs( residu[ 1 ] ) ) < repsi ) {
                            sol.push_back( V2( U, V ) );
                            residu_list.push_back( residu );
                        }
                    }
                }
            }
        }
        /// amélioration de la qualité par la méthode de Newton
        for( unsigned i = 0; i < sol.size(); ++i ) {
            Mat<T, Gen<2,2>, Dense<> > M;
            M( 0, 0 ) = f[1]+2*f[3]*sol[ i ][ 0 ]+f[4]*sol[ i ][ 1 ];
            M( 0, 1 ) = f[2]+2*f[5]*sol[ i ][ 1 ]+f[4]*sol[ i ][ 0 ];
            M( 1, 0 ) = g[1]+2*g[3]*sol[ i ][ 0 ]+g[4]*sol[ i ][ 1 ];
            M( 1, 1 ) = g[2]+2*g[5]*sol[ i ][ 1 ]+g[4]*sol[ i ][ 0 ];
            T deter = determinant( M );
            if ( std::abs( deter ) > repsi ) {
                sol[ i ] -= inv( M ) * residu_list[ i ];
            }
        }
        if ( sol.size() )
            return true;
        else {
            sol.resize( 0 );
            residu_list.resize( 0 );
        }
    } 
    
    /// résultant suivant U, la première indéterminée.
    coef[ 0 ] = g[0]*g[3]*f[1]*f[1]+f[3]*f[3]*g[0]*g[0]-2*g[3]*f[0]*f[3]*g[0]-g[1]*g[3]*f[1]*f[0]+f[3]*g[1]*g[1]*f[0]+g[3]*g[3]*f[0]*f[0]-g[1]*f[1]*f[3]*g[0];
    coef[ 1 ] = -g[4]*f[1]*f[3]*g[0]+2*g[3]*g[3]*f[0]*f[2]+g[2]*g[3]*f[1]*f[1]-2*g[3]*f[3]*g[0]*f[2]-2*g[3]*f[0]*f[3]*g[2]+2*f[3]*f[3]*g[0]*g[2]-g[4]*g[3]*f[1]*f[0]+2*g[4]*f[3]*g[1]*f[0]-g[1]*g[3]*f[1]*f[2]-g[1]*f[1]*f[3]*g[2]-g[1]*g[3]*f[4]*f[0]-g[1]*f[4]*f[3]*g[0]+f[3]*g[1]*g[1]*f[2]+2*g[0]*g[3]*f[1]*f[4];
    coef[ 2 ] = g[3]*g[3]*f[2]*f[2]+2*g[3]*g[3]*f[0]*f[5]+f[3]*f[3]*g[2]*g[2]+g[0]*g[3]*f[4]*f[4]+g[3]*g[5]*f[1]*f[1]-g[1]*g[3]*f[1]*f[5]-2*g[3]*f[0]*f[3]*g[5]-2*g[3]*f[3]*g[0]*f[5]+2*f[3]*f[3]*g[0]*g[5]-2*g[3]*f[2]*f[3]*g[2]-g[4]*g[3]*f[1]*f[2]-f[1]*g[4]*f[3]*g[2]-g[4]*g[3]*f[4]*f[0]-g[4]*f[4]*f[3]*g[0]+2*f[3]*g[4]*g[1]*f[2]+g[4]*g[4]*f[3]*f[0]-g[1]*f[1]*f[3]*g[5]-g[1]*g[3]*f[4]*f[2]-g[1]*f[4]*f[3]*g[2]+f[3]*g[1]*g[1]*f[5]+2*g[2]*g[3]*f[1]*f[4];
    coef[ 3 ] = 2*f[3]*f[3]*g[2]*g[5]-2*g[3]*f[2]*f[3]*g[5]+2*g[3]*g[3]*f[2]*f[5]+g[2]*g[3]*f[4]*f[4]-2*g[3]*f[3]*g[2]*f[5]-g[4]*g[3]*f[1]*f[5]-f[1]*g[4]*f[3]*g[5]-g[4]*g[3]*f[4]*f[2]-g[4]*f[4]*f[3]*g[2]+2*f[3]*g[4]*g[1]*f[5]+g[4]*g[4]*f[3]*f[2]-g[1]*g[3]*f[4]*f[5]-g[1]*f[4]*f[3]*g[5]+2*g[3]*g[5]*f[1]*f[4];
    coef[ 4 ] = g[5]*g[5]*f[3]*f[3]+f[5]*f[5]*g[3]*g[3]+g[3]*g[5]*f[4]*f[4]-2*g[5]*f[3]*f[5]*g[3]-g[4]*g[5]*f[4]*f[3]-g[4]*f[4]*f[5]*g[3]+g[4]*g[4]*f[5]*f[3];

    ret = solve_polynomial_system( sol1, coef );
    
    if ( ret ) {
        for( unsigned i = 0; i < sol1.size(); ++i ) {
            Vec<T, 3> coef2; /// f[0]+f[1]*U+f[2]*V+f[3]*U^2+f[4]*U*V+f[5]*V^2
            T V = sol1[i];
            coef2[ 0 ] = f[0] + V * ( f[2] + f[5] * V );
            coef2[ 1 ] = f[1] + f[4] * V;
            coef2[ 2 ] = f[3];
            Vec<T> sol2;
            bool ret2 = solve_polynomial_system( sol2, coef2 );
            if ( ret2 ) {
                T U;
                for( unsigned j = 0; j < sol2.size(); ++j ) {
                    U = sol2[ j ];
                    V2 residu( f[0]+f[1]*U+f[2]*V+f[3]*U*U+f[4]*U*V+f[5]*V*V, g[0]+g[1]*U+g[2]*V+g[3]*U*U+g[4]*U*V+g[5]*V*V );
                    if ( max( std::abs( residu[ 0 ] ), std::abs( residu[ 1 ] ) ) < repsi ) {
                        sol.push_back( V2( U, V ) );
                        residu_list.push_back( residu );
                    }
                }
            } else {
                /// g[0]+g[1]*U+g[2]*V+g[3]*U^2+g[4]*U*V+g[5]*V^2
                coef2[ 0 ] = g[0] + V * ( g[2] + g[5] * V );
                coef2[ 1 ] = g[1] + g[4] * V;
                coef2[ 2 ] = g[3];
                ret2 = solve_polynomial_system( sol2, coef2 );
                if ( ret2 ) {
                    T U;
                    for( unsigned j = 0; j < sol2.size(); ++j ) {
                        U = sol2[ j ];
                    V2 residu( f[0]+f[1]*U+f[2]*V+f[3]*U*U+f[4]*U*V+f[5]*V*V, g[0]+g[1]*U+g[2]*V+g[3]*U*U+g[4]*U*V+g[5]*V*V );
                    if ( max( std::abs( residu[ 0 ] ), std::abs( residu[ 1 ] ) ) < repsi ) {
                        sol.push_back( V2( U, V ) );
                        residu_list.push_back( residu );
                    }
                    }
                }
            }
        }
        /// amélioration de la qualité par la méthode de Newton
        for( unsigned i = 0; i < sol.size(); ++i ) {
            Mat<T, Gen<2,2>, Dense<> > M;
            M( 0, 0 ) = f[1]+2*f[3]*sol[ i ][ 0 ]+f[4]*sol[ i ][ 1 ];
            M( 0, 1 ) = f[2]+2*f[5]*sol[ i ][ 1 ]+f[4]*sol[ i ][ 0 ];
            M( 1, 0 ) = g[1]+2*g[3]*sol[ i ][ 0 ]+g[4]*sol[ i ][ 1 ];
            M( 1, 1 ) = g[2]+2*g[5]*sol[ i ][ 1 ]+g[4]*sol[ i ][ 0 ];
            T deter = determinant( M );
            if ( std::abs( deter ) > repsi ) {
                sol[ i ] -= inv( M ) * residu_list[ i ];
            }
        }
        if ( sol.size() )
            return true;
        else
            false;
    }
}

/*!
    Objectif :
        Cette fonction tente de résoudre le système polynomiale en les inconnues ( U, V ) :
            F2_hexa := f[0]+f[1]*U+f[2]*V+f[3]*U^2+f[4]*U*V+f[5]*V^2+f[7]*U^2*V+f[8]*U*V^2+f[12]*U^2*V^2 = 0
            G2_hexa := g[0]+g[1]*U+g[2]*V+g[3]*U^2+g[4]*U*V+g[5]*V^2+g[7]*U^2*V+g[8]*U*V^2+g[12]*U^2*V^2 = 0
            
        qui correspond à un \a Hexa mais aussi un \a Quad_8 et \a Quad_9 .
        On est conduit à résoudre une équation du second degré via la théorie du résultant.

*/
template<class T, int s>
bool solve_polynomial_system_resultant_4_par( Vec< Vec<T, 2> > &sol, const Vec<T, s > &f, const Vec<T, s > &g ) {

    typedef Vec<T, 2> V2;
    typedef Vec<T, 3> V3;
    typedef std::complex<T> C;

    T repsi = std::ldexp( 1, 4 - ( std::numeric_limits<T>::digits >> 2 ) );
    T nr;
    Vec< V3 > sr; /// Vec<T,3> contien la solution puis la norme du résidu
    Vec< V2 > residu_list;
    sol.resize( 0 );
    
    Vec<T, 9> coef;
    /// résultant suivant V, la deuxième indéterminée.  
    coef[ 0 ] = std::pow(f[5],2)*std::pow(g[0],2)+g[0]*g[5]*std::pow(f[2],2)+f[5]*std::pow(g[2],2)*f[0]-g[2]*g[5]*f[2]*f[0]-2*g[5]*f[0]*f[5]*g[0]+std::pow(g[5],2)*std::pow(f[0],2)-g[2]*f[2]*f[5]*g[0];
    coef[ 1 ] = -2*f[5]*g[0]*f[0]*g[8]-2*g[0]*f[8]*g[5]*f[0]-g[2]*f[2]*f[5]*g[1]+g[1]*g[5]*std::pow(f[2],2)+2*std::pow(g[5],2)*f[0]*f[1]-2*g[5]*f[0]*f[5]*g[1]-2*g[5]*f[1]*f[5]*g[0]+2*std::pow(f[5],2)*g[1]*g[0]-g[2]*g[5]*f[2]*f[1]-g[2]*g[5]*f[4]*f[0]-g[2]*f[4]*f[5]*g[0]+f[5]*std::pow(g[2],2)*f[1]+2*g[2]*f[5]*g[4]*f[0]-g[4]*g[5]*f[2]*f[0]-g[4]*f[2]*f[5]*g[0]+2*g[0]*g[5]*f[2]*f[4]-g[0]*f[2]*g[2]*f[8]+2*f[5]*std::pow(g[0],2)*f[8]+g[0]*std::pow(f[2],2)*g[8]-f[0]*g[2]*f[2]*g[8]+f[0]*std::pow(g[2],2)*f[8]+2*g[5]*std::pow(f[0],2)*g[8];
    coef[ 2 ] = std::pow(g[4],2)*f[5]*f[0]+g[0]*g[5]*std::pow(f[4],2)+f[1]*std::pow(g[2],2)*f[8]+std::pow(g[0],2)*std::pow(f[8],2)-f[0]*g[4]*f[2]*g[8]+2*f[0]*g[2]*g[4]*f[8]-f[0]*g[2]*f[4]*g[8]+2*g[0]*f[2]*f[4]*g[8]-g[0]*f[2]*g[4]*f[8]-g[0]*f[4]*g[2]*f[8]+4*g[5]*f[0]*f[1]*g[8]-f[1]*g[2]*f[2]*g[8]+std::pow(g[5],2)*std::pow(f[1],2)+std::pow(f[5],2)*std::pow(g[1],2)-2*g[5]*f[0]*f[5]*g[3]-2*g[5]*f[1]*f[5]*g[1]-2*g[5]*f[3]*f[5]*g[0]-g[2]*g[5]*f[2]*f[3]-g[2]*f[2]*f[5]*g[3]-g[2]*g[5]*f[4]*f[1]-g[2]*f[4]*f[5]*g[1]+2*f[5]*g[2]*g[4]*f[1]-g[4]*g[5]*f[2]*f[1]-g[4]*f[2]*f[5]*g[1]-g[4]*g[5]*f[4]*f[0]-g[4]*f[4]*f[5]*g[0]+2*g[1]*g[5]*f[2]*f[4]+g[3]*g[5]*std::pow(f[2],2)+2*std::pow(f[5],2)*g[3]*g[0]+f[5]*std::pow(g[2],2)*f[3]+2*std::pow(g[5],2)*f[0]*f[3]-g[1]*f[2]*g[2]*f[8]-2*g[1]*f[8]*g[5]*f[0]-2*f[5]*g[1]*f[0]*g[8]-2*g[0]*f[8]*f[0]*g[8]-2*g[0]*f[8]*g[5]*f[1]+g[1]*std::pow(f[2],2)*g[8]-2*g[0]*f[12]*g[5]*f[0]-2*f[5]*g[0]*f[0]*g[12]+4*f[5]*g[0]*g[1]*f[8]-2*f[5]*g[0]*f[1]*g[8]+std::pow(f[0],2)*std::pow(g[8],2)-g[0]*f[7]*f[5]*g[2]-g[0]*f[2]*g[2]*f[12]-g[0]*f[2]*g[7]*f[5]+2*g[0]*f[2]*f[7]*g[5]-f[0]*g[7]*g[5]*f[2]+2*f[0]*g[2]*g[7]*f[5]-f[0]*g[2]*f[2]*g[12]-f[0]*g[2]*f[7]*g[5]+2*g[5]*std::pow(f[0],2)*g[12]+2*f[5]*std::pow(g[0],2)*f[12]+g[0]*std::pow(f[2],2)*g[12]+f[0]*std::pow(g[2],2)*f[12];
    coef[ 3 ] = std::pow(g[4],2)*f[5]*f[1]+f[3]*std::pow(g[2],2)*f[8]+2*std::pow(g[5],2)*f[1]*f[3]+f[0]*std::pow(g[4],2)*f[8]-f[1]*g[4]*f[2]*g[8]-g[0]*f[4]*g[4]*f[8]-f[0]*g[4]*f[4]*g[8]-f[1]*g[2]*f[4]*g[8]+4*g[5]*f[0]*f[3]*g[8]-2*g[3]*f[8]*g[5]*f[0]+2*g[0]*std::pow(f[8],2)*g[1]-2*g[5]*f[1]*f[5]*g[3]-2*g[5]*f[5]*g[1]*f[3]-g[2]*g[5]*f[4]*f[3]-g[2]*f[4]*f[5]*g[3]+2*f[5]*g[2]*g[4]*f[3]-g[4]*g[5]*f[2]*f[3]-g[4]*f[2]*f[5]*g[3]-g[4]*g[5]*f[4]*f[1]-g[4]*f[4]*f[5]*g[1]+2*g[3]*g[5]*f[2]*f[4]+2*std::pow(f[5],2)*g[1]*g[3]+g[1]*g[5]*std::pow(f[4],2)-2*f[5]*g[0]*f[3]*g[8]+g[3]*std::pow(f[2],2)*g[8]-2*g[1]*f[8]*f[0]*g[8]-2*g[1]*f[8]*g[5]*f[1]-g[3]*f[2]*g[2]*f[8]-g[1]*f[2]*g[4]*f[8]+2*g[1]*f[2]*f[4]*g[8]-2*f[5]*g[3]*f[0]*g[8]-g[1]*f[4]*g[2]*f[8]+2*f[1]*g[2]*g[4]*f[8]-2*f[5]*g[1]*f[1]*g[8]+2*f[0]*std::pow(g[8],2)*f[1]+2*g[5]*std::pow(f[1],2)*g[8]+2*f[5]*std::pow(g[1],2)*f[8]+g[0]*std::pow(f[4],2)*g[8]-2*g[1]*f[12]*g[5]*f[0]-2*g[0]*f[8]*f[0]*g[12]-f[3]*g[2]*f[2]*g[8]-2*g[0]*f[12]*f[0]*g[8]-2*g[0]*f[12]*g[5]*f[1]-2*f[5]*g[1]*f[0]*g[12]+4*f[5]*g[0]*g[1]*f[12]-2*f[5]*g[0]*f[1]*g[12]+4*f[5]*g[0]*g[3]*f[8]+2*g[0]*f[4]*f[2]*g[12]-g[0]*f[4]*g[7]*f[5]-g[0]*f[4]*g[2]*f[12]-g[0]*f[7]*f[5]*g[4]-2*g[0]*f[8]*f[1]*g[8]-2*g[0]*f[8]*g[5]*f[3]+2*g[0]*f[4]*f[7]*g[5]+4*g[5]*f[0]*f[1]*g[12]-g[0]*f[7]*g[2]*f[8]-g[0]*f[2]*g[4]*f[12]-g[0]*f[2]*g[7]*f[8]+2*g[0]*f[2]*f[7]*g[8]-g[1]*f[2]*g[2]*f[12]-g[1]*f[2]*g[7]*f[5]-g[1]*f[7]*f[5]*g[2]+2*f[1]*g[2]*g[7]*f[5]+2*g[1]*f[2]*f[7]*g[5]-f[0]*g[7]*g[5]*f[4]-f[1]*g[2]*f[7]*g[5]-f[1]*g[2]*f[2]*g[12]-f[0]*g[4]*f[2]*g[12]-f[0]*g[4]*f[7]*g[5]+2*f[0]*g[2]*g[7]*f[8]-f[0]*g[2]*f[4]*g[12]-f[0]*g[2]*f[7]*g[8]+2*f[0]*g[4]*g[2]*f[12]+2*f[0]*g[4]*g[7]*f[5]-f[1]*g[7]*g[5]*f[2]-f[0]*g[7]*f[2]*g[8]+2*std::pow(f[0],2)*g[8]*g[12]+2*std::pow(g[0],2)*f[8]*f[12]+g[1]*std::pow(f[2],2)*g[12]+f[1]*std::pow(g[2],2)*f[12];
    coef[ 4 ] = std::pow(g[5],2)*std::pow(f[3],2)+g[1]*std::pow(f[4],2)*g[8]+std::pow(f[5],2)*std::pow(g[3],2)+f[1]*std::pow(g[4],2)*f[8]+std::pow(f[1],2)*std::pow(g[8],2)-2*f[5]*g[1]*f[3]*g[8]+std::pow(g[4],2)*f[5]*f[3]+g[3]*g[5]*std::pow(f[4],2)-f[3]*g[2]*f[4]*g[8]-g[3]*f[4]*g[2]*f[8]+2*g[3]*f[2]*f[4]*g[8]+4*g[5]*f[1]*f[3]*g[8]-f[1]*g[4]*f[4]*g[8]-2*g[5]*f[3]*f[5]*g[3]-g[4]*g[5]*f[4]*f[3]-g[4]*f[4]*f[5]*g[3]+2*g[0]*std::pow(f[8],2)*g[3]-2*g[1]*f[8]*f[1]*g[8]-2*g[1]*f[8]*g[5]*f[3]-g[3]*f[2]*g[4]*f[8]-g[1]*f[4]*g[4]*f[8]+4*f[5]*g[1]*g[3]*f[8]+2*f[0]*std::pow(g[8],2)*f[3]+std::pow(g[1],2)*std::pow(f[8],2)-f[2]*g[7]*f[1]*g[8]+2*g[1]*f[2]*f[7]*g[8]-g[0]*f[7]*g[4]*f[8]+2*g[0]*f[7]*f[4]*g[8]-g[0]*f[4]*g[7]*f[8]+2*f[0]*g[7]*g[4]*f[8]-2*g[1]*f[12]*f[0]*g[8]-2*g[1]*f[12]*g[5]*f[1]-f[2]*g[7]*g[1]*f[8]+2*f[1]*g[2]*g[7]*f[8]-g[2]*f[7]*g[1]*f[8]-g[2]*f[7]*f[1]*g[8]-2*g[0]*f[8]*f[1]*g[12]+2*f[3]*g[2]*g[4]*f[8]-f[3]*g[4]*f[2]*g[8]-2*g[0]*f[12]*f[0]*g[12]-2*g[0]*f[12]*f[1]*g[8]-2*g[0]*f[12]*g[5]*f[3]-2*f[5]*g[1]*f[1]*g[12]+4*f[5]*g[0]*g[3]*f[12]-2*f[5]*g[0]*f[3]*g[12]+4*g[0]*f[8]*g[1]*f[12]-f[0]*g[7]*f[4]*g[8]-2*f[5]*g[3]*f[0]*g[12]-f[0]*g[4]*f[7]*g[8]-2*g[1]*f[8]*f[0]*g[12]-2*g[3]*f[8]*f[0]*g[8]-2*g[3]*f[8]*g[5]*f[1]+4*g[5]*f[0]*f[3]*g[12]+2*g[0]*f[2]*f[7]*g[12]-2*g[3]*f[12]*g[5]*f[0]-2*g[0]*f[8]*f[3]*g[8]-2*f[5]*g[3]*f[1]*g[8]-g[0]*f[7]*g[2]*f[12]-g[0]*f[2]*g[7]*f[12]-g[0]*f[4]*g[4]*f[12]+4*f[0]*g[8]*f[1]*g[12]-g[1]*f[4]*g[2]*f[12]-g[1]*f[4]*g[7]*f[5]+2*g[1]*f[4]*f[2]*g[12]+2*g[1]*f[4]*f[7]*g[5]-g[0]*f[7]*g[7]*f[5]-g[1]*f[7]*f[5]*g[4]-g[1]*f[2]*g[4]*f[12]-g[3]*f[7]*f[5]*g[2]-g[3]*f[2]*g[2]*f[12]-g[3]*f[2]*g[7]*f[5]-f[1]*g[2]*f[4]*g[12]+2*g[3]*f[2]*f[7]*g[5]-f[0]*g[4]*f[4]*g[12]+2*f[0]*g[2]*g[7]*f[12]-f[0]*g[2]*f[7]*g[12]-f[1]*g[7]*g[5]*f[4]-f[1]*g[4]*f[2]*g[12]-f[1]*g[4]*f[7]*g[5]-f[0]*g[7]*f[7]*g[5]+2*f[1]*g[4]*g[2]*f[12]+2*f[1]*g[4]*g[7]*f[5]-f[0]*g[7]*f[2]*g[12]-f[3]*g[7]*g[5]*f[2]+2*f[3]*g[2]*g[7]*f[5]-f[3]*g[2]*f[2]*g[12]-f[3]*g[2]*f[7]*g[5]+2*g[5]*std::pow(f[1],2)*g[12]+2*f[5]*std::pow(g[1],2)*f[12]+g[0]*std::pow(f[4],2)*g[12]+g[0]*std::pow(f[7],2)*g[5]+g[3]*std::pow(f[2],2)*g[12]+f[3]*std::pow(g[2],2)*f[12]+f[0]*std::pow(g[4],2)*f[12]+f[0]*std::pow(g[7],2)*f[5]+std::pow(g[0],2)*std::pow(f[12],2)+std::pow(f[0],2)*std::pow(g[12],2);
    coef[ 5 ] = f[3]*std::pow(g[4],2)*f[8]+2*f[1]*std::pow(g[8],2)*f[3]-f[3]*g[4]*f[4]*g[8]-g[3]*f[4]*g[4]*f[8]+2*g[5]*std::pow(f[3],2)*g[8]+f[0]*std::pow(g[7],2)*f[8]-2*g[1]*f[8]*f[3]*g[8]+g[3]*std::pow(f[4],2)*g[8]+g[0]*std::pow(f[7],2)*g[8]+2*f[5]*std::pow(g[3],2)*f[8]-f[7]*g[5]*g[4]*f[3]+2*f[7]*g[5]*f[4]*g[3]-g[5]*f[4]*g[7]*f[3]+2*g[1]*std::pow(f[8],2)*g[3]-g[0]*f[7]*g[7]*f[8]-f[0]*g[7]*f[7]*g[8]-2*g[1]*f[12]*f[0]*g[12]-2*g[1]*f[12]*f[1]*g[8]+4*g[0]*f[8]*g[3]*f[12]-2*g[0]*f[8]*f[3]*g[12]-2*g[0]*f[12]*f[1]*g[12]-2*g[0]*f[12]*f[3]*g[8]+4*f[5]*g[1]*g[3]*f[12]-2*g[3]*f[8]*f[0]*g[12]-g[7]*f[5]*f[4]*g[3]-2*f[5]*g[3]*f[1]*g[12]-f[5]*g[4]*f[7]*g[3]-2*g[1]*f[12]*g[5]*f[3]+2*f[5]*g[4]*g[7]*f[3]-2*f[5]*g[1]*f[3]*g[12]-2*g[1]*f[8]*f[1]*g[12]-2*g[3]*f[8]*g[5]*f[3]-2*g[3]*f[12]*f[0]*g[8]-2*g[3]*f[12]*g[5]*f[1]-g[0]*f[4]*g[7]*f[12]-2*f[5]*g[3]*f[3]*g[8]-2*g[3]*f[8]*f[1]*g[8]+2*g[0]*f[4]*f[7]*g[12]-g[0]*f[7]*g[4]*f[12]+4*g[5]*f[1]*f[3]*g[12]+4*f[0]*g[8]*f[3]*g[12]-g[1]*f[4]*g[7]*f[8]+2*g[1]*f[4]*f[7]*g[8]-g[1]*f[7]*g[4]*f[8]-g[1]*f[2]*g[7]*f[12]-g[1]*f[4]*g[4]*f[12]+2*g[3]*f[4]*f[2]*g[12]-g[1]*f[7]*g[2]*f[12]-g[1]*f[7]*g[7]*f[5]+2*g[1]*f[2]*f[7]*g[12]+2*g[3]*f[2]*f[7]*g[8]-g[3]*f[2]*g[4]*f[12]-g[3]*f[2]*g[7]*f[8]-f[1]*g[4]*f[7]*g[8]-g[3]*f[4]*g[2]*f[12]+2*f[1]*g[2]*g[7]*f[12]-f[0]*g[7]*f[4]*g[12]-g[3]*f[7]*g[2]*f[8]+2*f[0]*g[4]*g[7]*f[12]-f[1]*g[7]*f[4]*g[8]-f[1]*g[4]*f[4]*g[12]+2*f[1]*g[4]*g[7]*f[8]-f[0]*g[4]*f[7]*g[12]-f[3]*g[7]*f[2]*g[8]-f[3]*g[4]*f[2]*g[12]+2*f[3]*g[2]*g[7]*f[8]-f[3]*g[2]*f[4]*g[12]-f[1]*g[7]*f[2]*g[12]-f[1]*g[7]*f[7]*g[5]+2*f[3]*g[4]*g[2]*f[12]-f[1]*g[2]*f[7]*g[12]-f[3]*g[2]*f[7]*g[8]+2*std::pow(f[1],2)*g[8]*g[12]+2*f[0]*std::pow(g[12],2)*f[1]+2*std::pow(g[1],2)*f[8]*f[12]+2*g[0]*std::pow(f[12],2)*g[1]+g[1]*std::pow(f[4],2)*g[12]+g[1]*std::pow(f[7],2)*g[5]+f[1]*std::pow(g[4],2)*f[12]+f[1]*std::pow(g[7],2)*f[5];
    coef[ 6 ] = std::pow(g[7],2)*f[5]*f[3]-2*g[3]*f[8]*f[3]*g[8]+std::pow(f[3],2)*std::pow(g[8],2)+g[5]*std::pow(f[7],2)*g[3]+std::pow(g[3],2)*std::pow(f[8],2)-f[7]*g[5]*g[7]*f[3]-2*g[1]*f[8]*f[3]*g[12]-2*g[1]*f[12]*f[1]*g[12]-2*g[0]*f[12]*f[3]*g[12]-2*g[3]*f[8]*f[1]*g[12]-g[7]*f[5]*f[7]*g[3]-2*f[5]*g[3]*f[3]*g[12]-2*g[1]*f[12]*f[3]*g[8]+4*g[1]*f[8]*g[3]*f[12]-2*g[3]*f[12]*f[0]*g[12]-2*g[3]*f[12]*f[1]*g[8]-2*g[3]*f[12]*g[5]*f[3]+4*f[1]*g[8]*f[3]*g[12]-g[1]*f[4]*g[7]*f[12]+2*g[1]*f[4]*f[7]*g[12]-g[0]*f[7]*g[7]*f[12]-g[1]*f[7]*g[4]*f[12]-g[3]*f[7]*g[4]*f[8]+2*g[3]*f[4]*f[7]*g[8]-g[1]*f[7]*g[7]*f[8]-f[1]*g[4]*f[7]*g[12]-g[3]*f[4]*g[4]*f[12]+2*g[3]*f[2]*f[7]*g[12]-g[3]*f[2]*g[7]*f[12]-g[3]*f[4]*g[7]*f[8]-g[3]*f[7]*g[2]*f[12]-f[1]*g[7]*f[4]*g[12]-f[0]*g[7]*f[7]*g[12]+2*f[1]*g[4]*g[7]*f[12]-f[3]*g[7]*f[4]*g[8]-f[3]*g[4]*f[4]*g[12]-f[3]*g[4]*f[7]*g[8]+2*f[3]*g[2]*g[7]*f[12]-f[1]*g[7]*f[7]*g[8]+2*f[3]*g[4]*g[7]*f[8]-f[3]*g[7]*f[2]*g[12]-f[3]*g[2]*f[7]*g[12]+2*g[5]*std::pow(f[3],2)*g[12]+2*f[5]*std::pow(g[3],2)*f[12]+2*g[0]*std::pow(f[12],2)*g[3]+g[0]*std::pow(f[7],2)*g[12]+g[1]*std::pow(f[7],2)*g[8]+g[3]*std::pow(f[4],2)*g[12]+f[0]*std::pow(g[7],2)*f[12]+f[1]*std::pow(g[7],2)*f[8]+f[3]*std::pow(g[4],2)*f[12]+2*f[0]*std::pow(g[12],2)*f[3]+std::pow(f[1],2)*std::pow(g[12],2)+std::pow(g[1],2)*std::pow(f[12],2);
    coef[ 7 ] = -2*g[1]*f[12]*f[3]*g[12]-2*g[3]*f[8]*f[3]*g[12]-2*g[3]*f[12]*f[3]*g[8]-2*g[3]*f[12]*f[1]*g[12]-g[1]*f[7]*g[7]*f[12]-g[3]*f[4]*g[7]*f[12]+2*f[1]*std::pow(g[12],2)*f[3]+2*std::pow(g[3],2)*f[8]*f[12]+2*g[3]*f[4]*f[7]*g[12]+2*g[1]*std::pow(f[12],2)*g[3]-g[3]*f[7]*g[4]*f[12]-g[3]*f[7]*g[7]*f[8]+2*std::pow(f[3],2)*g[8]*g[12]+g[3]*std::pow(f[7],2)*g[8]+g[1]*std::pow(f[7],2)*g[12]+f[3]*std::pow(g[7],2)*f[8]+f[1]*std::pow(g[7],2)*f[12]+2*f[3]*g[4]*g[7]*f[12]-f[1]*g[7]*f[7]*g[12]-f[3]*g[4]*f[7]*g[12]-f[3]*g[7]*f[4]*g[12]-f[3]*g[7]*f[7]*g[8];
    coef[ 8 ] = -2*g[3]*f[12]*f[3]*g[12]-g[3]*f[7]*g[7]*f[12]+g[3]*std::pow(f[7],2)*g[12]+f[3]*std::pow(g[7],2)*f[12]-f[3]*g[7]*f[7]*g[12]+std::pow(g[3],2)*std::pow(f[12],2)+std::pow(f[3],2)*std::pow(g[12],2);
    
    //PRINT( repsi );
    Vec<T> sol1;
    bool ret = solve_polynomial_system( sol1, coef );
    //PRINT( coef );
    //PRINT( sol1 );
    if ( ret ) {
        for( unsigned i = 0; i < sol1.size(); ++i ) {
            Vec<T, 3> coef2; /// f[0]+f[1]*U+f[2]*V+f[3]*U^2+f[4]*U*V+f[5]*V^2+f[7]*U^2*V+f[8]*U*V^2+f[12]*U^2*V^2
            T U = sol1[i];
            //std::cout << "~~~ U = " << U << "  ~~~~" << endl;
            coef2[ 0 ] = f[0] + U * ( f[1] + f[3]  * U );
            coef2[ 1 ] = f[2] + U * ( f[4] + f[7]  * U );
            coef2[ 2 ] = f[5] + U * ( f[8] + f[12] * U );
            //PRINT( coef2 );
            Vec<C> sol2;
            bool ret2 = solve_polynomial_system( sol2, coef2 );
            //PRINT( ret2 );
            //PRINT( sol2 );
            if ( ret2 ) {
                for( unsigned j = 0; j < sol2.size(); ++j )
                    if ( ( sol2[ j ].imag() >= 0 ) and ( sol2[ j ].imag() < repsi ) ) {
                        V2 uv( U, sol2[j].real() );
                        V2 residu( polyres( f, uv ), polyres( g, uv ) ); 
                        //std::cout << "U = " << U << "  V = " << uv[ 1 ] << " residu = " << residu << endl;
                        nr = norm_inf( residu );
                        if ( nr < repsi ) {
                            sr.push_back( V3( uv[ 0 ], uv[ 1 ], nr ) );
                            residu_list.push_back( residu );
                        }
                    }
            } else {
                /// g[0]+g[1]*U+g[2]*V+g[3]*U^2+g[4]*U*V+g[5]*V^2+g[7]*U^2*V+g[8]*U*V^2+g[12]*U^2*V^2
                coef2[ 0 ] = g[0] + U * ( g[1] + g[3]  * U );
                coef2[ 1 ] = g[2] + U * ( g[4] + g[7]  * U );
                coef2[ 2 ] = g[5] + U * ( g[8] + g[12] * U );
                ret2 = solve_polynomial_system( sol2, coef2 );
                //PRINT( ret2 );
                //PRINT( sol2 );
                if ( ret2 ) {
                    for( unsigned j = 0; j < sol2.size(); ++j )
                        if ( ( sol2[ j ].imag() >= 0 ) and ( sol2[ j ].imag() < repsi ) ) {
                            V2 uv( U, sol2[j].real() );
                            V2 residu( polyres( f, uv ), polyres( g, uv ) );
                            //std::cout << "U = " << U << "  V = " << uv[ 1 ] << " residu = " << residu << endl;
                            nr = norm_inf( residu );
                            if ( nr < repsi ) {
                                sr.push_back( V3( uv[ 0 ], uv[ 1 ], nr ) );
                                residu_list.push_back( residu );
                            }
                        }
                }
            }
        }
    } else {
    
        /// résultant suivant U, la première indéterminée.  
        coef[ 0 ] = std::pow(f[3],2)*std::pow(g[0],2)+g[0]*g[3]*std::pow(f[1],2)-2*g[3]*f[0]*f[3]*g[0]+std::pow(g[3],2)*std::pow(f[0],2)-g[1]*g[3]*f[1]*f[0]+f[3]*std::pow(g[1],2)*f[0]-g[1]*f[1]*f[3]*g[0];
        coef[ 1 ] = 2*std::pow(g[3],2)*f[0]*f[2]+g[2]*g[3]*std::pow(f[1],2)-2*g[3]*f[0]*f[3]*g[2]-2*g[3]*f[3]*g[0]*f[2]+2*std::pow(f[3],2)*g[0]*g[2]-g[4]*g[3]*f[1]*f[0]-g[4]*f[1]*f[3]*g[0]+2*g[4]*f[3]*g[1]*f[0]-g[1]*g[3]*f[1]*f[2]-g[1]*f[1]*f[3]*g[2]-g[1]*g[3]*f[4]*f[0]-g[1]*f[4]*f[3]*g[0]+f[3]*std::pow(g[1],2)*f[2]+2*g[0]*g[3]*f[1]*f[4]+f[0]*std::pow(g[1],2)*f[7]-f[0]*g[1]*f[1]*g[7]+2*std::pow(g[0],2)*f[3]*f[7]+2*std::pow(f[0],2)*g[3]*g[7]-2*g[0]*f[3]*f[0]*g[7]-2*g[0]*f[7]*f[0]*g[3]-g[0]*f[1]*g[1]*f[7]+g[0]*std::pow(f[1],2)*g[7];
        coef[ 2 ] = g[3]*g[5]*std::pow(f[1],2)+std::pow(g[4],2)*f[3]*f[0]+g[0]*std::pow(f[1],2)*g[12]+2*std::pow(g[3],2)*f[0]*f[5]+2*std::pow(f[3],2)*g[0]*g[5]-2*g[3]*f[3]*g[0]*f[5]-2*g[3]*f[0]*f[3]*g[5]+g[0]*g[3]*std::pow(f[4],2)+f[3]*std::pow(g[1],2)*f[5]+std::pow(g[3],2)*std::pow(f[2],2)+std::pow(f[3],2)*std::pow(g[2],2)-2*g[3]*f[2]*f[3]*g[2]-g[4]*g[3]*f[1]*f[2]-f[1]*g[4]*f[3]*g[2]-g[4]*g[3]*f[4]*f[0]-g[4]*f[4]*f[3]*g[0]+2*f[3]*g[4]*g[1]*f[2]-g[1]*g[3]*f[1]*f[5]-g[1]*f[1]*f[3]*g[5]-g[1]*g[3]*f[4]*f[2]-g[1]*f[4]*f[3]*g[2]+2*g[2]*g[3]*f[1]*f[4]+std::pow(f[0],2)*std::pow(g[7],2)+std::pow(g[0],2)*std::pow(f[7],2)-2*g[0]*f[7]*f[0]*g[7]-2*f[0]*g[2]*f[7]*g[3]+4*f[0]*g[3]*f[2]*g[7]+2*std::pow(g[0],2)*f[3]*f[12]+4*g[0]*f[3]*g[2]*f[7]-2*g[0]*f[3]*f[2]*g[7]-2*g[0]*f[2]*f[7]*g[3]-2*f[3]*g[2]*f[0]*g[7]+f[2]*std::pow(g[1],2)*f[7]-g[1]*f[2]*f[1]*g[7]-f[0]*g[1]*f[1]*g[12]-g[1]*f[8]*f[0]*g[3]+f[0]*std::pow(g[1],2)*f[12]-f[0]*g[4]*f[1]*g[7]-g[0]*f[1]*g[1]*f[12]-g[0]*f[1]*g[4]*f[7]-g[0]*f[1]*g[8]*f[3]+2*g[0]*f[4]*f[1]*g[7]-g[0]*f[4]*g[1]*f[7]+2*g[0]*f[8]*f[1]*g[3]-f[1]*g[2]*g[1]*f[7]+2*f[0]*g[8]*g[1]*f[3]+g[2]*std::pow(f[1],2)*g[7]-2*g[0]*f[12]*f[0]*g[3]+2*f[0]*g[4]*g[1]*f[7]-f[0]*g[1]*f[4]*g[7]-f[0]*g[8]*f[1]*g[3]-g[0]*f[8]*g[1]*f[3]-2*g[0]*f[3]*f[0]*g[12]+2*std::pow(f[0],2)*g[3]*g[12];
        coef[ 3 ] = 2*std::pow(g[3],2)*f[2]*f[5]+2*std::pow(f[3],2)*g[2]*g[5]+f[0]*std::pow(g[4],2)*f[7]-g[0]*f[7]*f[1]*g[8]+4*g[0]*f[7]*g[5]*f[3]-f[0]*g[4]*f[4]*g[7]+2*f[2]*g[8]*g[1]*f[3]-f[1]*g[4]*f[2]*g[7]-g[0]*f[4]*g[4]*f[7]+2*f[1]*g[2]*f[4]*g[7]-2*g[5]*f[0]*f[3]*g[7]+g[2]*g[3]*std::pow(f[4],2)+std::pow(g[4],2)*f[3]*f[2]-2*g[3]*f[2]*f[3]*g[5]-2*g[3]*f[3]*g[2]*f[5]-g[4]*g[3]*f[1]*f[5]-f[1]*g[4]*f[3]*g[5]-g[4]*g[3]*f[4]*f[2]-g[4]*f[4]*f[3]*g[2]+2*f[3]*g[4]*g[1]*f[5]-g[1]*g[3]*f[4]*f[5]-g[1]*f[4]*f[3]*g[5]+2*g[3]*g[5]*f[1]*f[4]-2*f[5]*g[0]*f[3]*g[7]-g[0]*f[7]*g[1]*f[8]-2*f[0]*g[2]*f[7]*g[7]+2*g[3]*std::pow(f[2],2)*g[7]-g[1]*f[8]*f[0]*g[7]-2*g[3]*f[2]*g[2]*f[7]+2*g[1]*f[2]*g[4]*f[7]-g[1]*f[2]*f[4]*g[7]-2*g[3]*f[7]*g[5]*f[0]+4*f[5]*g[3]*f[0]*g[7]-g[1]*f[4]*g[2]*f[7]-f[0]*g[7]*f[1]*g[8]-f[1]*g[2]*g[4]*f[7]-f[5]*g[1]*f[1]*g[7]+g[5]*std::pow(f[1],2)*g[7]+2*g[0]*f[8]*f[1]*g[7]+f[5]*std::pow(g[1],2)*f[7]+2*f[3]*std::pow(g[2],2)*f[7]+g[0]*std::pow(f[4],2)*g[7]-2*f[3]*g[2]*f[2]*g[7]-2*f[5]*g[0]*g[3]*f[7]-g[1]*f[7]*g[5]*f[1]+2*g[1]*f[7]*f[0]*g[8]-2*g[2]*f[12]*f[0]*g[3]+4*g[0]*f[3]*g[2]*f[12]-2*g[0]*f[3]*f[2]*g[12]+2*std::pow(g[0],2)*f[7]*f[12]+2*g[0]*std::pow(f[7],2)*g[2]-2*g[0]*f[7]*f[0]*g[12]-2*g[0]*f[2]*f[7]*g[7]-2*f[3]*g[2]*f[0]*g[12]-g[1]*f[2]*f[8]*g[3]+f[2]*std::pow(g[1],2)*f[12]-f[0]*g[4]*f[1]*g[12]-g[2]*f[8]*g[1]*f[3]+2*g[2]*f[8]*f[1]*g[3]-g[0]*f[1]*g[4]*f[12]+2*g[0]*f[4]*f[1]*g[12]-g[0]*f[4]*g[1]*f[12]-f[1]*g[2]*g[8]*f[3]-g[0]*f[4]*g[8]*f[3]-f[1]*g[2]*g[1]*f[12]+g[2]*std::pow(f[1],2)*g[12]-g[1]*f[2]*f[1]*g[12]-f[0]*g[8]*f[4]*g[3]-g[0]*f[8]*g[4]*f[3]-2*g[0]*f[12]*f[0]*g[7]-f[0]*g[4]*f[8]*g[3]+2*f[0]*g[4]*g[1]*f[12]-f[0]*g[1]*f[4]*g[12]-2*g[0]*f[12]*f[2]*g[3]-f[2]*g[8]*f[1]*g[3]+2*f[0]*g[8]*g[4]*f[3]+2*g[0]*f[8]*f[4]*g[3]+2*std::pow(f[0],2)*g[7]*g[12]+2*f[0]*std::pow(g[7],2)*f[2]+4*f[0]*g[3]*f[2]*g[12];
        coef[ 4 ] = std::pow(g[5],2)*std::pow(f[3],2)+std::pow(f[5],2)*std::pow(g[3],2)+2*f[5]*g[1]*f[3]*g[8]+std::pow(g[4],2)*f[5]*f[3]+g[3]*g[5]*std::pow(f[4],2)-f[3]*g[2]*f[4]*g[8]+2*g[3]*f[4]*g[2]*f[8]-g[3]*f[2]*f[4]*g[8]-g[5]*f[1]*f[3]*g[8]-2*g[5]*f[3]*f[5]*g[3]-g[4]*g[5]*f[4]*f[3]-g[4]*f[4]*f[5]*g[3]+g[0]*std::pow(f[8],2)*g[3]-g[1]*f[8]*g[5]*f[3]-g[3]*f[2]*g[4]*f[8]-f[5]*g[1]*g[3]*f[8]+f[0]*std::pow(g[8],2)*f[3]-f[2]*g[7]*f[1]*g[8]+2*g[1]*f[2]*f[7]*g[8]-2*g[2]*f[7]*f[2]*g[7]-g[0]*f[7]*g[4]*f[8]-g[0]*f[7]*f[4]*g[8]+2*g[0]*f[4]*g[7]*f[8]-f[0]*g[7]*g[4]*f[8]+2*g[1]*f[12]*f[0]*g[8]-g[1]*f[12]*g[5]*f[1]-f[2]*g[7]*g[1]*f[8]+2*f[1]*g[2]*g[7]*f[8]-g[2]*f[7]*g[1]*f[8]-g[2]*f[7]*f[1]*g[8]+2*g[0]*f[8]*f[1]*g[12]-f[3]*g[2]*g[4]*f[8]+2*f[3]*g[4]*f[2]*g[8]-2*g[0]*f[12]*f[0]*g[12]-g[0]*f[12]*f[1]*g[8]+4*g[0]*f[12]*g[5]*f[3]-f[5]*g[1]*f[1]*g[12]-2*f[5]*g[0]*g[3]*f[12]-2*f[5]*g[0]*f[3]*g[12]-g[0]*f[8]*g[1]*f[12]-f[0]*g[7]*f[4]*g[8]+4*f[5]*g[3]*f[0]*g[12]+2*f[0]*g[4]*f[7]*g[8]-g[1]*f[8]*f[0]*g[12]-g[3]*f[8]*f[0]*g[8]+2*g[3]*f[8]*g[5]*f[1]-2*g[5]*f[0]*f[3]*g[12]-2*g[0]*f[2]*f[7]*g[12]-2*g[3]*f[12]*g[5]*f[0]-g[0]*f[8]*f[3]*g[8]-f[5]*g[3]*f[1]*g[8]+4*g[0]*f[7]*g[2]*f[12]-2*g[0]*f[2]*g[7]*f[12]-g[0]*f[4]*g[4]*f[12]-f[0]*g[8]*f[1]*g[12]-g[1]*f[4]*g[2]*f[12]-g[1]*f[4]*g[7]*f[5]-g[1]*f[4]*f[2]*g[12]-g[1]*f[4]*f[7]*g[5]-2*g[0]*f[7]*g[7]*f[5]+2*g[1]*f[7]*f[5]*g[4]+2*g[1]*f[2]*g[4]*f[12]-2*g[3]*f[7]*f[5]*g[2]-2*g[3]*f[2]*g[2]*f[12]+4*g[3]*f[2]*g[7]*f[5]+2*f[1]*g[2]*f[4]*g[12]-2*g[3]*f[2]*f[7]*g[5]-f[0]*g[4]*f[4]*g[12]+f[2]*std::pow(g[4],2)*f[7]-2*f[0]*g[2]*g[7]*f[12]-2*f[0]*g[2]*f[7]*g[12]+2*f[1]*g[7]*g[5]*f[4]-f[1]*g[4]*f[2]*g[12]-f[1]*g[4]*f[7]*g[5]-2*f[0]*g[7]*f[7]*g[5]-f[1]*g[4]*g[2]*f[12]-f[1]*g[4]*g[7]*f[5]+4*f[0]*g[7]*f[2]*g[12]-2*f[3]*g[7]*g[5]*f[2]-2*f[3]*g[2]*g[7]*f[5]-2*f[3]*g[2]*f[2]*g[12]+4*f[3]*g[2]*f[7]*g[5]-g[4]*f[2]*f[4]*g[7]+g[5]*std::pow(f[1],2)*g[12]+f[5]*std::pow(g[1],2)*f[12]+g[0]*std::pow(f[4],2)*g[12]+std::pow(g[2],2)*std::pow(f[7],2)+2*g[0]*std::pow(f[7],2)*g[5]+2*g[3]*std::pow(f[2],2)*g[12]+2*f[3]*std::pow(g[2],2)*f[12]+f[0]*std::pow(g[4],2)*f[12]+2*f[0]*std::pow(g[7],2)*f[5]-g[2]*f[4]*g[4]*f[7]+g[2]*std::pow(f[4],2)*g[7]+std::pow(f[2],2)*std::pow(g[7],2)+std::pow(g[0],2)*std::pow(f[12],2)+std::pow(f[0],2)*std::pow(g[12],2);
        coef[ 5 ] = -2*f[7]*g[5]*f[0]*g[12]-f[2]*g[8]*f[8]*g[3]+2*f[2]*g[8]*g[1]*f[12]-2*g[2]*f[7]*f[5]*g[7]+2*std::pow(f[5],2)*g[3]*g[7]+2*g[5]*f[1]*g[7]*f[8]-f[2]*g[7]*f[4]*g[8]+2*g[4]*f[2]*f[7]*g[8]-g[1]*f[7]*g[5]*f[8]-2*g[2]*f[7]*f[2]*g[12]-f[7]*g[5]*f[1]*g[8]-f[2]*g[7]*g[4]*f[8]-g[2]*f[7]*g[4]*f[8]-g[2]*f[7]*f[4]*g[8]+2*g[2]*f[4]*g[7]*f[8]-g[7]*f[5]*g[1]*f[8]-g[7]*f[5]*f[1]*g[8]+2*f[5]*g[1]*f[7]*g[8]-2*g[2]*f[12]*f[2]*g[7]+2*f[0]*std::pow(g[12],2)*f[2]-f[2]*g[8]*f[1]*g[12]-2*f[7]*g[5]*f[5]*g[3]+f[2]*std::pow(g[4],2)*f[12]-2*g[2]*f[12]*f[5]*g[3]-2*g[2]*f[12]*f[0]*g[12]+4*f[0]*g[7]*f[5]*g[12]+4*g[0]*f[7]*g[5]*f[12]+2*std::pow(f[2],2)*g[7]*g[12]-2*g[5]*f[12]*f[2]*g[3]+4*f[5]*g[3]*f[2]*g[12]-2*g[0]*f[7]*f[5]*g[12]-2*f[3]*g[2]*f[5]*g[12]-g[0]*f[8]*g[8]*f[7]-g[4]*f[2]*f[4]*g[12]+g[0]*std::pow(f[8],2)*g[7]-g[5]*f[8]*g[4]*f[3]+2*std::pow(g[2],2)*f[7]*f[12]+4*g[5]*f[3]*g[2]*f[12]+2*g[5]*f[8]*f[4]*g[3]-g[1]*f[2]*f[8]*g[12]-g[5]*f[4]*g[8]*f[3]-2*g[0]*f[12]*f[2]*g[12]+2*f[5]*g[8]*g[4]*f[3]-g[4]*g[5]*f[4]*f[7]+2*g[5]*f[4]*f[1]*g[12]-g[5]*f[4]*g[1]*f[12]+g[5]*std::pow(f[4],2)*g[7]-g[2]*f[8]*g[8]*f[3]-g[5]*f[1]*g[4]*f[12]+g[2]*std::pow(f[8],2)*g[3]-g[2]*f[8]*g[1]*f[12]+g[2]*std::pow(f[4],2)*g[12]-g[0]*f[4]*g[8]*f[12]-f[1]*g[2]*g[8]*f[12]+f[0]*std::pow(g[8],2)*f[7]+2*g[0]*f[8]*f[4]*g[12]-g[0]*f[8]*g[4]*f[12]-f[0]*g[8]*f[4]*g[12]-f[0]*g[4]*f[8]*g[12]-f[5]*g[8]*f[4]*g[3]-f[5]*g[4]*f[8]*g[3]+std::pow(g[4],2)*f[5]*f[7]-g[4]*f[4]*f[5]*g[7]+2*f[5]*g[4]*g[1]*f[12]-f[5]*g[4]*f[1]*g[12]-2*g[0]*f[12]*f[5]*g[7]-f[5]*g[1]*f[4]*g[12]+f[2]*std::pow(g[8],2)*f[3]+2*g[5]*std::pow(f[7],2)*g[2]-2*g[5]*f[3]*f[5]*g[7]+2*f[5]*std::pow(g[7],2)*f[2]-2*g[5]*f[3]*f[2]*g[12]+2*g[0]*std::pow(f[12],2)*g[2]+2*std::pow(g[5],2)*f[3]*f[7]-f[0]*g[8]*f[8]*g[7]+2*f[0]*g[8]*g[4]*f[12]-g[2]*f[4]*g[4]*f[12]+2*g[2]*f[8]*f[1]*g[12]-2*g[5]*f[12]*f[0]*g[7]-2*f[7]*g[5]*f[2]*g[7];
        coef[ 6 ] = -f[2]*g[8]*f[4]*g[12]+2*std::pow(f[5],2)*g[3]*g[12]-f[2]*g[8]*f[8]*g[7]-2*g[2]*f[7]*f[5]*g[12]-f[7]*g[5]*f[4]*g[8]+2*g[5]*f[4]*g[7]*f[8]-g[7]*f[5]*f[4]*g[8]+2*f[5]*g[4]*f[7]*g[8]-f[5]*g[4]*g[7]*f[8]-f[7]*g[5]*g[4]*f[8]-2*g[2]*f[12]*f[2]*g[12]-2*f[7]*g[5]*f[5]*g[7]-2*g[2]*f[12]*f[5]*g[7]+std::pow(g[2],2)*std::pow(f[12],2)-2*f[7]*g[5]*f[2]*g[12]-2*g[5]*f[12]*f[0]*g[12]+g[5]*std::pow(f[8],2)*g[3]-2*g[5]*f[12]*f[5]*g[3]-g[4]*f[2]*f[8]*g[12]+std::pow(f[5],2)*std::pow(g[7],2)+4*g[7]*f[5]*f[2]*g[12]+g[0]*std::pow(f[8],2)*g[12]-2*g[5]*f[12]*f[2]*g[7]-2*g[5]*f[3]*f[5]*g[12]-g[1]*f[8]*g[5]*f[12]+2*std::pow(g[5],2)*f[3]*f[12]+2*g[5]*f[8]*f[1]*g[12]-2*g[0]*f[12]*f[5]*g[12]-g[4]*g[5]*f[4]*f[12]-g[2]*f[8]*g[8]*f[7]+g[5]*std::pow(f[4],2)*g[12]-g[2]*f[8]*g[4]*f[12]-g[5]*f[1]*g[8]*f[12]+g[2]*std::pow(f[8],2)*g[7]+2*g[2]*f[8]*f[4]*g[12]+f[0]*std::pow(g[8],2)*f[12]-f[0]*g[8]*f[8]*g[12]-g[0]*f[8]*g[8]*f[12]-f[5]*g[8]*f[8]*g[3]+2*f[5]*g[8]*g[1]*f[12]-f[5]*g[8]*f[1]*g[12]-g[4]*f[4]*f[5]*g[12]+std::pow(g[4],2)*f[5]*f[12]-f[5]*g[1]*f[8]*g[12]+2*f[2]*g[8]*g[4]*f[12]+f[2]*std::pow(g[8],2)*f[7]+std::pow(g[5],2)*std::pow(f[7],2)+4*f[7]*g[5]*g[2]*f[12]+2*g[0]*std::pow(f[12],2)*g[5]+std::pow(f[2],2)*std::pow(g[12],2)-g[2]*f[4]*g[8]*f[12]+f[5]*std::pow(g[8],2)*f[3]-g[5]*f[8]*g[8]*f[3]+2*f[0]*std::pow(g[12],2)*f[5];
        coef[ 7 ] = -2*g[2]*f[12]*f[5]*g[12]-g[5]*f[8]*g[8]*f[7]-g[5]*f[8]*g[4]*f[12]+g[5]*std::pow(f[8],2)*g[7]+2*g[5]*f[8]*f[4]*g[12]-g[5]*f[4]*g[8]*f[12]-g[2]*f[8]*g[8]*f[12]+g[2]*std::pow(f[8],2)*g[12]+2*f[5]*g[8]*g[4]*f[12]-f[5]*g[8]*f[4]*g[12]-f[5]*g[8]*f[8]*g[7]-f[5]*g[4]*f[8]*g[12]+f[2]*std::pow(g[8],2)*f[12]-f[2]*g[8]*f[8]*g[12]+2*g[5]*std::pow(f[12],2)*g[2]+2*std::pow(g[5],2)*f[7]*f[12]+2*f[5]*std::pow(g[12],2)*f[2]+2*std::pow(f[5],2)*g[7]*g[12]-2*f[7]*g[5]*f[5]*g[12]-2*g[5]*f[12]*f[5]*g[7]-2*g[5]*f[12]*f[2]*g[12]+f[5]*std::pow(g[8],2)*f[7];
        coef[ 8 ] = std::pow(f[5],2)*std::pow(g[12],2)-g[5]*f[8]*g[8]*f[12]+g[5]*std::pow(f[8],2)*g[12]-f[5]*g[8]*f[8]*g[12]+std::pow(g[5],2)*std::pow(f[12],2)-2*g[5]*f[12]*f[5]*g[12]+f[5]*std::pow(g[8],2)*f[12];
        
        ret = solve_polynomial_system( sol1, coef );
        if ( ret ) {
            for( unsigned i = 0; i < sol1.size(); ++i ) {
                Vec<T, 3> coef2; /// f[0]+f[1]*U+f[2]*V+f[3]*U^2+f[4]*U*V+f[5]*V^2+f[7]*U^2*V+f[8]*U*V^2+f[12]*U^2*V^2
                T V = sol1[i];
                //std::cout << "~~~ U = " << U << "  ~~~~" << endl;
                coef2[ 0 ] = f[0] + V * ( f[2] + f[5]  * V );
                coef2[ 1 ] = f[1] + V * ( f[4] + f[8]  * V );
                coef2[ 2 ] = f[3] + V * ( f[7] + f[12] * V );
                //PRINT( coef2 );
                Vec<C> sol2;
                bool ret2 = solve_polynomial_system( sol2, coef2 );
                //PRINT( ret2 );
                //PRINT( sol2 );
                if ( ret2 ) {
                    for( unsigned j = 0; j < sol2.size(); ++j )
                        if ( ( sol2[ j ].imag() >= 0 ) and ( sol2[ j ].imag() < repsi ) ) {
                            V2 uv( sol2[j].real(), V );
                            V2 residu( polyres( f, uv ), polyres( g, uv ) ); 
                            //std::cout << "U = " << U << "  V = " << uv[ 1 ] << " residu = " << residu << endl;
                            nr = norm_inf( residu );
                            if ( nr < repsi ) {
                                sr.push_back( V3( uv[0], uv[1], nr ) );
                                residu_list.push_back( residu );
                            }
                        }
                } else {
                    /// g[0]+g[1]*U+g[2]*V+g[3]*U^2+g[4]*U*V+g[5]*V^2+g[7]*U^2*V+g[8]*U*V^2+g[12]*U^2*V^2
                    coef2[ 0 ] = g[0] + V * ( g[2] + g[5]  * V );
                    coef2[ 1 ] = g[1] + V * ( g[4] + g[8]  * V );
                    coef2[ 2 ] = g[3] + V * ( g[7] + g[12] * V );
                    ret2 = solve_polynomial_system( sol2, coef2 );
                    //PRINT( ret2 );
                    //PRINT( sol2 );
                    if ( ret2 ) {
                        for( unsigned j = 0; j < sol2.size(); ++j )
                            if ( ( sol2[ j ].imag() >= 0 ) and ( sol2[ j ].imag() < repsi ) ) {
                                V2 uv( sol2[j].real(), V );
                                V2 residu( polyres( f, uv ), polyres( g, uv ) );
                                //std::cout << "U = " << U << "  V = " << uv[ 1 ] << " residu = " << residu << endl;
                                nr = norm_inf( residu );
                                if ( max( std::abs( residu[ 0 ] ), std::abs( residu[ 1 ] ) ) < repsi ) {
                                    sr.push_back( V3( uv[0], uv[1], nr ) );
                                    residu_list.push_back( residu );
                                }
                            }
                    }
                }
            }
        }
    }    
    
    //std::cout << "sol = " << sol << std::endl;
    /// amélioration de la qualité par la méthode de Newton
    for( unsigned i = 0; i < sr.size(); ++i ) {
        Mat<T, Gen<2,2>, Dense<> > J;
        J( 0, 0 ) = f[1]+2*f[3]*sr[i][0]+f[4]*sr[i][1]+2*f[7]*sr[i][0]*sr[i][1]+(f[8]+2*f[12]*sr[i][0])*std::pow(sr[i][1],2);
        J( 0, 1 ) = f[2]+f[4]*sr[i][0]+2*f[5]*sr[i][1]+2*f[8]*sr[i][0]*sr[i][1]+(f[7]+2*f[12]*sr[i][1])*std::pow(sr[i][0],2);
        J( 1, 0 ) = g[1]+2*g[3]*sr[i][0]+g[4]*sr[i][1]+2*g[7]*sr[i][0]*sr[i][1]+(g[8]+2*g[12]*sr[i][0])*std::pow(sr[i][1],2);
        J( 1, 1 ) = g[2]+g[4]*sr[i][0]+2*g[5]*sr[i][1]+2*g[8]*sr[i][0]*sr[i][1]+(g[7]+2*g[12]*sr[i][1])*std::pow(sr[i][0],2);
        //std::cout << "sol _ i = " << sr[ i ] << std::endl;
        //std::cout << "residu initial = " << residu_list[ i ] << std::endl;
        if ( std::abs( determinant( J ) ) > repsi ) {
            V2 uv( sr[ i ][ 0 ], sr[ i ][ 1 ] );
            uv -= inv( J ) * residu_list[ i ];
            residu_list[ i ] = V2( polyres( f, uv ), polyres( g, uv ) );
            J( 0, 0 ) = f[1]+2*f[3]*uv[0]+f[4]*uv[1]+2*f[7]*uv[0]*uv[1]+(f[8]+2*f[12]*uv[0])*std::pow(uv[1],2);
            J( 0, 1 ) = f[2]+f[4]*uv[0]+2*f[5]*uv[1]+2*f[8]*uv[0]*uv[1]+(f[7]+2*f[12]*uv[1])*std::pow(uv[0],2);
            J( 1, 0 ) = g[1]+2*g[3]*uv[0]+g[4]*uv[1]+2*g[7]*uv[0]*uv[1]+(g[8]+2*g[12]*uv[0])*std::pow(uv[1],2);
            J( 1, 1 ) = g[2]+g[4]*uv[0]+2*g[5]*uv[1]+2*g[8]*uv[0]*uv[1]+(g[7]+2*g[12]*uv[1])*std::pow(uv[0],2);
            //std::cout << "residu intermediaire = " << residu_list[ i ] << std::endl;
            uv -= inv( J ) * residu_list[ i ];
            residu_list[ i ] = V2( polyres( f, uv ), polyres( g, uv ) );
            sr[ i ] = V3( uv[ 0 ], uv[ 1 ], norm_inf( residu_list[ i ] ) );          
        }
        //std::cout << "residu final = " << residu_list[ i ] << std::endl;
    }
    
    if ( sr.size() ) {
        LMT::sort( sr, Less_at_three() );
        sol.resize( sr.size() );
        for( unsigned i = 0; i < sr.size(); ++i )
            sol[ i ] = V2( sr[ i ][ 0 ], sr[ i ][ 1 ] ); 
        return true;
    } else
        return false;
}

}

#endif
