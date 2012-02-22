#ifndef SYSTEM_POLY_H
#define SYSTEM_POLY_H

#include <limits>
//#include <complex>
#include <assert.h>

#include "algo.h"
#include "system_Poly_common.h"

namespace LMT {

/// juste un seul polynôme. Valable pour des polynômes de degré petit
template<class T >
bool solve_polynomial_system( Vec<T> &sol, const Poly<T> &syst ) {
    
    sol.resize( 0 );
    
    if ( syst.monom_list.size() == 0 ) {
        sol.push_back( 0 );
        return true;    
    }

    Vec<T> coef;
    /// détermination du degré
    unsigned degree = 0;
    for( unsigned i = 0; i < syst.monom_list.size(); ++i )
        if ( syst.monom_list[ i ].expo.size() )
            degree = std::max( degree, syst.monom_list[ i ].expo[ 0 ] );
    
    /// détermination des coefficients
    coef.resize( degree + 1, 0 );
    for( unsigned i = 0; i < syst.monom_list.size(); ++i ) 
        if ( syst.monom_list[ i ].expo.size() )
            coef[ syst.monom_list[ i ].expo[ 0 ] ] = syst.monom_list[ i ].coef;
        else
            coef[ 0 ] = syst.monom_list[ i ].coef;

    return solve_polynomial_system( sol, coef );    
}

/*!
    Objectif :
        Cette fonction résout un système polynomial de 2 équations à 2 inconnues quasi linéaire au sens suivant :
         * Parmi les deux équations, une indéterminée a un degré total égal à 1,
         * Parmi les deux équations, une seule indéterminée est présente.
         
        Elle renvoie vrai si elle trouve un nombre fini de solutions et faux si le système n'est pas quasi linéaire ou si il y a une infinité de solutions.


    Entrées :
        * p1, p2 sont les deux polynômes à deux indéterminés. La fonction ne vérifie pas s'ils ont effectivement deux indéterminées et si celles-ci sont les-mêmes aux deux polynômes.
        * sol est la liste des solutions.

    Sorties :
        renvoie vrai si tout ce passe bien :-)

*/
template<class T >
bool solve_basic_polynomial_system( Vec< Vec<T, 2> >& sol, const Vec< Poly<T>, 2>& syst, const Vec< typename Poly<T>::Monom*, 2> mm = Vec< typename Poly<T>::Monom*, 2 >( NULL, NULL ), T tolerance = 128 * std::numeric_limits<T>::epsilon() ) {
    typedef Poly<T> P;
    
    typename P::Monom m0;
    typename P::Monom m1;
    if ( mm[ 0 ] ) 
        m0 = *mm[ 0 ];
    else
        m0 = syst[ 0 ].max_degree();
    if ( mm[ 1 ] ) 
        m1 = *mm[ 1 ];
    else
        m1 = syst[ 1 ].max_degree();        
    
    Vec<char> name_X;
    for( unsigned i = 0; i < m0.name.size(); ++i )
        name_X.push_back( m0.name[ i ] );
    for( unsigned i = 0; i < m1.name.size(); ++i )
        if ( name_X.find( m1.name[ i ] ) >= name_X.size() )
            name_X.push_back( m1.name[ i ] ); 
                   
    sort( name_X );
    
    Poly<T> p, p2;
    
    sol.resize( 0 );
    
    /// essai sur le premier polynôme 
    if ( extract_if_linear( p, name_X[ 0 ], syst[ 0 ] ) ) {
        p2 = syst[ 1 ].subs( name_X[ 0 ], p );
        Vec<T> s; solve_polynomial_system( s, p2 );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,2>( p.subs( name_X[ 1 ], s[ i ] ).evalf(), s[ i ] ) ); 
        }
        return true ;
    }
    
    if ( extract_if_linear( p, name_X[ 1 ], syst[ 0 ] ) ) {
        p2 = syst[ 1 ].subs( name_X[ 1 ], p );
        Vec<T> s; solve_polynomial_system( s, p2 );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,2>( s[ i ], p.subs( name_X[ 0 ], s[ i ] ).evalf() ) ); 
        }
        return true ;
    }

    /// essai sur le second polynôme 
    if ( extract_if_linear( p, name_X[ 0 ], syst[ 1 ] ) ) {
        p2 = syst[ 0 ].subs( name_X[ 0 ], p );
        Vec<T> s; solve_polynomial_system( s, p2 );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,2>( p.subs( name_X[ 1 ], s[ i ] ).evalf(), s[ i ] ) ); 
        }
        return true ;
    }
    
    if ( extract_if_linear( p, name_X[ 1 ], syst[ 1 ] ) ) {
        p2 = syst[ 0 ].subs( name_X[ 1 ], p );
        Vec<T> s; solve_polynomial_system( s, p2 );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,2>( s[ i ], p.subs( name_X[ 0 ], s[ i ] ).evalf() ) ); 
        }
        return true ;
    }

    /// si une des indéterminés n'apparaît pas dans l'une des équations, on résout simplement ce cas.
    if ( m0.name.size() == 1 ) {
        Vec<T> s; solve_polynomial_system( s, syst[ 0 ] ); // = syst[ 0 ].roots();
        for( unsigned i = 0; i < s.size(); ++i ) {
            P p = syst[ 1 ].subs( m0.name[ 0 ], s[ i ] );
            Vec<T> s2; solve_polynomial_system( s2, p ); // = p.roots();
            switch( m1.name.size() ) {
                case 1 :
                    if ( m1.name[ 0 ] == m0.name[ 0 ] ) return false;
                    if ( m1.name[ 0 ] < m0.name[ 0 ] ) {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s[ i ], s2[ j ] ) );
                    } else {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s2[ j ], s[ i ] ) );
                    }
                    break;
                case 2 :
                    if ( m1.name[ 0 ] == m0.name[ 0 ] ) {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s[ i ], s2[ j ] ) );
                    } else {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s2[ j ], s[ i ] ) );
                    }                    
                    break;
                default: return false;
            }
        }
        return true;
    }
    
    if ( m1.name.size() == 1 ) {
        Vec<T> s; solve_polynomial_system( s, syst[ 1 ] ); //.roots();
        for( unsigned i = 0; i < s.size(); ++i ) {
            P p = syst[ 0 ].subs( m0.name[ 0 ], s[ i ] );
            Vec<T> s2; solve_polynomial_system( s2, p );// = p.roots();
            switch( m1.name.size() ) {
                case 1 :
                    if ( m1.name[ 0 ] == m0.name[ 0 ] ) return false;
                    if ( m1.name[ 0 ] < m0.name[ 0 ] ) {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s[ i ], s2[ j ] ) );
                    } else {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s2[ j ], s[ i ] ) );
                    }
                    break;
                case 2 :
                    if ( m1.name[ 0 ] == m0.name[ 0 ] ) {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s[ i ], s2[ j ] ) );
                    } else {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s2[ j ], s[ i ] ) );
                    }                    
                    break;
                default: return false;
            }
        }
        return true;
    }
    
    return false;
}

/*!
cette fonction n'a pas la prétention de résoudre n'nimporte quelle système polynomial. On se contentera de polynômes au degré total petit et avec des systèmes ayant qu'un nombre fini de solutions.

*/
template<class T >
bool solve_polynomial_system( Vec< Vec<T, 2> >& sol, 
                              const Vec< Poly<T>, 2>& syst, 
                              T tolerance = 128 * std::numeric_limits<T>::epsilon() ) {
    typedef Poly<T> P;
    
    typename P::Monom m0 = syst[ 0 ].max_degree();
    typename P::Monom m1 = syst[ 1 ].max_degree();
    Vec< typename P::Monom*, 2 > mm( &m0, &m1 );
    
    sol.resize( 0 );
    
    if ( ( m0.is_constant() ) or ( m1.is_constant() ) ) return false;
    
    bool retlin = solve_basic_polynomial_system( sol, syst, mm );
    if ( retlin )
        return retlin;

    /// on rentre dans le cas général
    unsigned tdmax = std::max( syst[ 0 ].total_degree(), syst[ 0 ].total_degree() );
    //PRINT( tdmax );
    switch( tdmax ) {
        case 2 : {
            Vec<T, 6> c0, c1;
            fill_coef( c0, syst[ 0 ], m0.name, Number<2>() );
            fill_coef( c1, syst[ 1 ], m0.name, Number<2>() );
            //PRINT( c0 ); PRINT( c1 );
            if ( ( c0[ 3 ] == 0 ) and ( c0[ 5 ] == 0 ) and ( c1[ 3 ] == 0 ) and ( c1[ 5 ] == 0 ) )
                return solve_polynomial_system_resultant_2_par( sol, c0, c1 );
            else ///cas général
                return solve_polynomial_system_resultant_2( sol, c0, c1 );
        } break;
        default: 
            std::cerr << "Error solve_polynomial_system(): total degree  = "<< tdmax << " is not done." << std::endl;
            return false;
    }

    return false;
}

/*!
    Objectif :
        Cette fonction résout un système polynomial de 3 équations à 3 inconnues quasi linéaire au sens suivant :
         * Parmi les deux équations, une indéterminée a un degré total égal à 1,
         * Parmi les deux équations, une seule indéterminée est présente.
         
        Elle renvoie vrai si elle trouve un nombre fini de solutions et faux si le système n'est pas quasi linéaire ou si il y a une infinité de solutions.


    Entrées :
        * p1, p2 sont les deux polynômes à deux indéterminés. La fonction ne vérifie pas s'ils ont effectivement deux indéterminées et si celles-ci sont les-mêmes aux deux polynômes.
        * sol est la liste des solutions.

    Sorties :
        renvoie vrai si tout ce passe bien :-)

*/
template<class T >
bool solve_basic_polynomial_system( Vec< Vec<T, 3> >& sol, 
                                    const Vec< Poly<T>, 3>& syst, 
                                    const Vec< typename Poly<T>::Monom*, 3> mm = Vec< typename Poly<T>::Monom*, 3 >( NULL, NULL, NULL ), 
                                    T tolerance = 128 * std::numeric_limits<T>::epsilon() ) {
    typedef Poly<T> P;
    
    typename P::Monom m0;
    typename P::Monom m1;
    typename P::Monom m2;
    
    if ( mm[ 0 ] ) 
        m0 = *mm[ 0 ];
    else
        m0 = syst[ 0 ].max_degree();
    if ( mm[ 1 ] ) 
        m1 = *mm[ 1 ];
    else
        m1 = syst[ 1 ].max_degree();        
    if ( mm[ 2 ] ) 
        m2 = *mm[ 2 ];
    else
        m2 = syst[ 2 ].max_degree(); 

    Vec<char> name_X;
    for( unsigned i = 0; i < m0.name.size(); ++i )
        name_X.push_back( m0.name[ i ] );
    for( unsigned i = 0; i < m1.name.size(); ++i )
        if ( name_X.find( m1.name[ i ] ) >= name_X.size() )
            name_X.push_back( m1.name[ i ] );        
    for( unsigned i = 0; i < m2.name.size(); ++i )
        if ( name_X.find( m2.name[ i ] ) >= name_X.size() )
            name_X.push_back( m2.name[ i ] );  
    sort( name_X );

    P p;
    Vec< P, 2> sub_syst;
    
    sol.resize( 0 );
    
    /// essai sur le premier polynôme 
    if ( extract_if_linear( p, name_X[ 0 ], syst[ 0 ] ) ) {
        sub_syst[ 0 ] = syst[ 1 ].subs( name_X[ 0 ], p );
        sub_syst[ 1 ] = syst[ 2 ].subs( name_X[ 0 ], p );
        Vec< Vec<T, 2> > s;
        solve_polynomial_system( s, sub_syst, tolerance );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,3>( p.subs( Vec<char,2>( name_X[ 1 ], name_X[ 2 ] ), s[ i ] ).evalf(), s[ i ][ 0 ], s[ i ][ 1 ] ) ); 
        }
        return true ;
    }
    
    if ( extract_if_linear( p, name_X[ 1 ], syst[ 0 ] ) ) {
        sub_syst[ 0 ] = syst[ 1 ].subs( name_X[ 1 ], p );
        sub_syst[ 1 ] = syst[ 2 ].subs( name_X[ 1 ], p );
        Vec< Vec<T, 2> > s;
        solve_polynomial_system( s, sub_syst, tolerance );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,3>( s[ i ][ 0 ], p.subs( Vec<char,2>( name_X[ 0 ], name_X[ 2 ] ), s[ i ] ).evalf(), s[ i ][ 1 ] ) ); 
        }
        return true ;
    }
    
    if ( extract_if_linear( p, name_X[ 2 ], syst[ 0 ] ) ) {
        sub_syst[ 0 ] = syst[ 1 ].subs( name_X[ 2 ], p );
        sub_syst[ 1 ] = syst[ 2 ].subs( name_X[ 2 ], p );
        Vec< Vec<T, 2> > s;
        solve_polynomial_system( s, sub_syst, tolerance );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,3>( s[ i ][ 0 ], s[ i ][ 1 ], p.subs( Vec<char,2>( name_X[ 0 ], name_X[ 1 ] ), s[ i ] ).evalf() ) ); 
        }
        return true ;
    }
  
    /// essai sur le deuxième polynôme 
    if ( extract_if_linear( p, name_X[ 0 ], syst[ 1 ] ) ) {
        sub_syst[ 0 ] = syst[ 0 ].subs( name_X[ 0 ], p );
        sub_syst[ 1 ] = syst[ 2 ].subs( name_X[ 0 ], p );
        Vec< Vec<T, 2> > s;
        solve_polynomial_system( s, sub_syst, tolerance );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,3>( p.subs( Vec<char,2>( name_X[ 1 ], name_X[ 2 ] ), s[ i ] ).evalf(), s[ i ][ 0 ], s[ i ][ 1 ] ) ); 
        }
        return true ;
    }
    
    if ( extract_if_linear( p, name_X[ 1 ], syst[ 1 ] ) ) {
        sub_syst[ 0 ] = syst[ 0 ].subs( name_X[ 1 ], p );
        sub_syst[ 1 ] = syst[ 2 ].subs( name_X[ 1 ], p );
        Vec< Vec<T, 2> > s;
        solve_polynomial_system( s, sub_syst, tolerance );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,3>( s[ i ][ 0 ], p.subs( Vec<char,2>( name_X[ 0 ], name_X[ 2 ] ), s[ i ] ).evalf(), s[ i ][ 1 ] ) ); 
        }
        return true ;
    }
    
    if ( extract_if_linear( p, name_X[ 2 ], syst[ 1 ] ) ) {
        sub_syst[ 0 ] = syst[ 0 ].subs( name_X[ 2 ], p );
        sub_syst[ 1 ] = syst[ 2 ].subs( name_X[ 2 ], p );
        Vec< Vec<T, 2> > s;
        solve_polynomial_system( s, sub_syst, tolerance );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,3>( s[ i ][ 0 ], s[ i ][ 1 ], p.subs( Vec<char,2>( name_X[ 0 ], name_X[ 1 ] ), s[ i ] ).evalf() ) ); 
        }
        return true ;
    }
    
    /// essai sur le troisième polynôme 
    if ( extract_if_linear( p, name_X[ 0 ], syst[ 2 ] ) ) {
        sub_syst[ 0 ] = syst[ 0 ].subs( name_X[ 0 ], p );
        sub_syst[ 1 ] = syst[ 1 ].subs( name_X[ 0 ], p );
        Vec< Vec<T, 2> > s;
        solve_polynomial_system( s, sub_syst, tolerance );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,3>( p.subs( Vec<char,2>( name_X[ 1 ], name_X[ 2 ] ), s[ i ] ).evalf(), s[ i ][ 0 ], s[ i ][ 1 ] ) ); 
        }
        return true ;
    }
    
    if ( extract_if_linear( p, name_X[ 1 ], syst[ 2 ] ) ) {
        sub_syst[ 0 ] = syst[ 0 ].subs( name_X[ 1 ], p );
        sub_syst[ 1 ] = syst[ 1 ].subs( name_X[ 1 ], p );
        Vec< Vec<T, 2> > s;
        solve_polynomial_system( s, sub_syst, tolerance );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,3>( s[ i ][ 0 ], p.subs( Vec<char,2>( name_X[ 0 ], name_X[ 2 ] ), s[ i ] ).evalf(), s[ i ][ 1 ] ) ); 
        }
        return true ;
    }
    
    if ( extract_if_linear( p, name_X[ 2 ], syst[ 2 ] ) ) {
        sub_syst[ 0 ] = syst[ 0 ].subs( name_X[ 2 ], p );
        sub_syst[ 1 ] = syst[ 1 ].subs( name_X[ 2 ], p );
        Vec< Vec<T, 2> > s;
        solve_polynomial_system( s, sub_syst, tolerance );
        for( unsigned i = 0; i < s.size(); ++i ) {
            sol.push_back( Vec<T,3>( s[ i ][ 0 ], s[ i ][ 1 ], p.subs( Vec<char,2>( name_X[ 0 ], name_X[ 1 ] ), s[ i ] ).evalf() ) ); 
        }
        return true ;
    }

    /// si une des indéterminés n'apparaît pas dans l'une des équations, on résout simplement ce cas.
    /*
    if ( m0.name.size() == 1 ) {
        Vec<T> s; solve_polynomial_system( s, syst[ 0 ], tolerance ); // = syst[ 0 ].roots();
        for( unsigned i = 0; i < s.size(); ++i ) {
            P p = syst[ 1 ].subs( m0.name[ 0 ], s[ i ] );
            Vec<T> s2; solve_polynomial_system( s2, p, tolerance ); // = p.roots();
            switch( m1.name.size() ) {
                case 1 :
                    if ( m1.name[ 0 ] == m0.name[ 0 ] ) return false;
                    if ( m1.name[ 0 ] < m0.name[ 0 ] ) {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s[ i ], s2[ j ] ) );
                    } else {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s2[ j ], s[ i ] ) );
                    }
                    break;
                case 2 :
                    if ( m1.name[ 0 ] == m0.name[ 0 ] ) {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s[ i ], s2[ j ] ) );
                    } else {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s2[ j ], s[ i ] ) );
                    }                    
                    break;
                default: return false;
            }
        }
        return true;
    }
    
    if ( m1.name.size() == 1 ) {
        Vec<T> s; solve_polynomial_system( s, syst[ 1 ], tolerance ); //.roots();
        for( unsigned i = 0; i < s.size(); ++i ) {
            P p = syst[ 0 ].subs( m0.name[ 0 ], s[ i ] );
            Vec<T> s2; solve_polynomial_system( s2, p, tolerance );// = p.roots();
            switch( m1.name.size() ) {
                case 1 :
                    if ( m1.name[ 0 ] == m0.name[ 0 ] ) return false;
                    if ( m1.name[ 0 ] < m0.name[ 0 ] ) {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s[ i ], s2[ j ] ) );
                    } else {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s2[ j ], s[ i ] ) );
                    }
                    break;
                case 2 :
                    if ( m1.name[ 0 ] == m0.name[ 0 ] ) {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s[ i ], s2[ j ] ) );
                    } else {
                        for( unsigned j = 0; j < s2.size(); ++j )
                            sol.push_back( Vec<T, 2>( s2[ j ], s[ i ] ) );
                    }                    
                    break;
                default: return false;
            }
        }
        return true;
    }
    */    
    return false;
}

}

#endif
