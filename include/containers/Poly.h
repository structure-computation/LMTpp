#ifndef POLY_H
#define POLY_H

#include <limits>
#include <assert.h>

#include "containers/vec.h"

namespace LMT {

/*!
    Cette classe sert à représenter un polynôme de plusieurs indéterminées. La différence avec la classe \a Pol est son stockage creux : i.e. on ne stocke que les monômes désirés.

*/
template< class T = double >
struct Poly {
    typedef T value_type;
    
    struct Monom {    
        Monom() : coef( 0 ) {}
        
        void init( T val ) { coef =  val; expo.resize( 0 ); name.resize( 0 ); }
        
        void init( T val, char _name, unsigned ex ) { 
            coef = val; 
            expo.resize( 0 ); 
            name.resize( 0 );
            if ( val != 0 ) {
                if ( ex ) {
                    expo.push_back( ex ); 
                    name.push_back( _name );
                }
            }
        } 
    
        template< int s>
        void init( T val, const Vec<char, s> _name, const Vec<unsigned, s> ex ) { 
            coef = val;
            expo.resize( 0 );
            name.resize( 0 );
            if ( val != 0 ) {
                name.reserve( _name.size() );
                expo.reserve( ex.size() );
                for( unsigned i = 0; i < ex.size(); ++i )
                    if ( ex[ i ] ) {
                        name.push_back( _name[ i ] );
                        expo.push_back( ex[ i ] ); 
                    }
            }
        } 
        
        Monom( T val ) { init( val ); }
        
        Monom( T val, char _name, unsigned ex ) { init( val, _name, ex ); }
  
        template< int s>
        Monom( T val, const Vec<char, s> _name, const Vec<unsigned, s> ex ) { init( val, _name, ex ); }
        
        bool same( char _name, unsigned ex ) const {
            if ( name.size() != 1 )
                return false;
            if ( ( name[ 0 ] == _name ) and ( ex == expo[ 0 ] ) )
                return true;
            else
                return false; 
        }
        
        template< int s>
        bool same( const Vec<char, s> _name, const Vec<unsigned, s> ex ) const { 
            if ( name.size() != _name.size() )
                return false;
            if ( expo.size() != ex.size() )
                return false;
            
            bool res = true;
            for( unsigned i = 0; i < name.size(); ++i )
                res &= name[ i ] == _name[ i ];
            if ( not( res ) )
                return false;
            for( unsigned i = 0; i < expo.size(); ++i )
                res &= expo[ i ] == ex[ i ];
            return res;
        }
        
        bool same( const Monom &m ) const { 
            if ( name.size() != m.name.size() )
                return false;
            if ( expo.size() != m.expo.size() )
                return false;
            
            bool res = true;
            for( unsigned i = 0; i < name.size(); ++i )
                res &= name[ i ] == m.name[ i ];
            if ( not( res ) )
                return false;
            for( unsigned i = 0; i < expo.size(); ++i )
                res &= expo[ i ] == m.ex[ i ];
            return res;
        }
        
        Monom& operator +=( T val ) {
            coef += val;
            if ( coef == 0 ) {
                expo.resize( 0 );
                name.resize( 0 );
            }
            return *this;
        }
        
        Monom& operator *=( T val ) {
            coef *= val;
            if ( coef == 0 ) {
                expo.resize( 0 );
                name.resize( 0 );
            }
            return *this;
        }
        
        Monom sqr() const {
            Monom res( *this );
            
            res.coef = coef * coef;
            res.expo = 2 * expo;
            return res;
        }
        
        Monom operator* ( const Monom &m ) const {
        
            Monom res;
            res.coef = coef * m.coef;
            
            if ( res.coef == 0 ) {
                return *this;
            }
            
            if ( name.size() == 0 ) {
                res.expo = m.expo;
                res.name = m.name;
                return res;
            }
            
            if ( m.name.size() == 0 ) {
                res.expo = expo;
                res.name = name;
                return res;
            }
            /// pas optimisé
            char max_name = std::max( LMT::max( name ), LMT::max( m.name ) );
            char min_name = std::min( LMT::min( name ), LMT::min( m.name ) );
            for( char c = min_name; c <= max_name; ++c ) {
                unsigned i = name.find( c );
                if ( i < name.size() ) {
                    unsigned j = m.name.find( c );
                    if ( j < m.name.size() ) {
                        res.name.push_back( c );
                        res.expo.push_back( expo[ i ] + m.expo[ j ] );
                    } else {
                        res.name.push_back( c );
                        res.expo.push_back( expo[ i ] );                                   
                    }
                } else {
                    unsigned j = m.name.find( c );
                    if ( j < m.name.size() ) {
                        res.name.push_back( c );
                        res.expo.push_back( m.expo[ j ] );
                    }
                }
            }
            return res;
        }
        
        Monom& operator*= ( const Monom &m ) {
            
            coef *= m.coef;
            
            if ( coef == 0 ) {
                expo.resize( 0 );
                name.resize( 0 );
                return *this;
            }
            
            if ( name.size() == 0 ) {
                expo = m.expo;
                name = m.name;
                return *this;
            }
            
            if ( m.name.size() == 0 )
                return *this;

            /// pas optimisé
            char max_name = std::max( LMT::max( name ), LMT::max( m.name ) );
            for( char c = 0; c <= max_name; ++c ) {
                unsigned i = name.find( c );
                if ( i < name.size() ) {
                    unsigned j = m.name.find( c );
                    if ( j < m.name.size() )
                        expo[ i ] += m.expo[ j ];
                } else {
                    unsigned j = m.name.find( c );
                    if ( j < m.name.size() ) {
                        unsigned k = 0;
                        while ( ( k < name.size() ) and ( name[ k ] < c ) )
                            k++;
                        if ( k < name.size() ) {
                            name.insert_before( k, c );
                            expo.insert_before( k, m.expo[ j ] );
                        } else {
                            name.push_back( c );
                            expo.push_back( m.expo[ j ] );
                        }
                    }
                }
            }
            return *this;
        }
        
        unsigned total_degree() const {
            unsigned res = 0;
            for( unsigned i = 0; i < expo.size(); ++i )
                res += expo[ i ];
            return res; 
        }
    
        bool is_constant( T *pv = NULL ) const {
            if ( name.size() == 0 ) {
                if ( pv )
                    *pv = coef;
                return true;
            }
            return false;
        }
        
        std::string to_string( bool maple = true ) const {
        
            std::ostringstream oss, oss2;
            int nom;
            oss  << std::setprecision( 17 );
            oss2 << std::setprecision( 17 );
            if ( coef < 0 )
                oss << " - ";
            if ( ( std::abs( coef ) != 1 ) or ( name.size() == 0 ) )
                oss << std::abs( coef );
            
            for( unsigned i = 0; i < expo.size(); ++i ) {
                switch( expo[ i ] ) {
                    case 0  : break;
                    case 1  : nom = name[ i ];
                              if ( maple )
                                if ( nom >= 0 ) oss2 << "X" << nom; else oss2 << "Xm" << -nom;
                              else 
                                if ( nom >= 0 ) oss2 << "X_" << nom; else oss2 << "X_m" << -nom;
                              break;
                    default : nom = name[ i ];
                              if ( maple )
                                  if ( nom >= 0 ) oss2 << "X" << nom; else oss2 << "Xm" << -nom;
                              else
                                  if ( nom >= 0 ) oss2 << "X_" << nom; else oss2 << "X_m" << -nom;
                               oss2 << "**" << expo[ i ];
                }
                if ( ( i < expo.size() - 1 ) and ( expo[ i ] ) )
                    oss2 << '*';
            }
            std::string mo = oss2.str();
            if ( mo.size() ) { 
                if ( std::abs( coef ) != 1 )
                    oss << '*' << mo;
                else
                    oss << mo;       
            }      
            return oss.str();
        }
        
        /*!
            Si *this == X**a alors la méthode renvoie X**a' où a' ne contient plus l'indéterminée _name.
            Rem : si _name n'apparaît pas dans les indéterminées, la méthode renvoie *this. 
        */
        Monom counterpart( char _name ) const {
            unsigned i = name.find( _name );
            if ( i >= name.size() )
                return *this;
            Vec<unsigned> temex = expo;
            Vec<char> nom = name;
            temex.erase_elem_nb( i );
            nom.erase_elem_nb( i );
            return Monom( coef, nom, temex );                         
        }
        
        Monom subs( char _name, T val  ) const {
            
            unsigned i = name.find( _name );
            if ( i >= name.size() )
                return *this;
            
            Vec<unsigned> temex = expo;
            Vec<char> nom = name;
            temex.erase_elem_nb( i );
            nom.erase_elem_nb( i );
            
            return Monom( std::pow( val, expo[ i ] ) * coef, nom, temex ); 
        }
        
        template<int s>
        Monom subs( const Vec<char, s> &_name, const Vec<T, s> &val  ) const {
            
            T new_coef = coef;
            Vec<unsigned> temex;
            Vec<char> nom;
            
            for( unsigned i = 0; i < _name.size(); ++i ) {
                unsigned j = name.find( _name[ i ] );
                if ( j < name.size() )
                    new_coef *= std::pow( val[ i ], expo[ j ] );
            }
            
            for( unsigned i = 0; i < name.size(); ++i ) {
                unsigned j = _name.find( name[ i ] );
                if ( j >= _name.size() ) {
                    nom.push_back( name[ i ] );
                    temex.push_back( expo[ i ] );
                }
            }
            if ( new_coef != 0 )
                return Monom( new_coef, nom, temex );
            else 
                return Monom( new_coef );     
        }
    
        Vec<unsigned> expo;      /// exposant des indéterminées
        Vec<char> name; /// nom des indéterminées. Il est primordial que les noms soient classés par ordre croissant.
        T coef; /// coefficient devant le monôme
    };
    
    void add( T val ) {
        for( unsigned i = 0; i < monom_list.size(); ++i )
            if ( monom_list[ i ].is_constant() ) {
                monom_list[ i ] += val;
                return;
            }
        monom_list.push_back( Monom( val ) );
    }
    
    void add( T val, char _name, unsigned ex, bool with_update = false ) {
        
        unsigned i = find_monom( _name, ex );
        if ( i == npos ) 
            monom_list.push_back( Monom( val, _name, ex ) );
        else {
            monom_list[ i ] += val;
            if ( with_update )
                update();
        }   
    }
    
    template< int s >
    void add( T val, const Vec<char, s> _name, const Vec<unsigned, s> ex, bool with_update = false ) {
        
        unsigned i = find_monom( _name, ex );
        if ( i == npos ) 
            monom_list.push_back( Monom( val, _name, ex ) );
        else {
            monom_list[ i ] += val;
            if ( with_update )
                update();
        }   
    }
    
    void add( const Monom &m, bool with_update = false ) {
        
        unsigned i = find_monom( m.name, m.expo );
        if ( i == npos ) 
            monom_list.push_back( m );
        else {
            monom_list[ i ] += m.coef;
            if ( with_update )
                update();
        }   
    }
    
    template< int s >
    void init( Vec<T, s> &list_value, unsigned nb_x ) {
        clear();
        switch( nb_x ) {
            case 1 : {
                for( unsigned i = 0; i < list_value.size(); ++i ) {
                    if ( list_value[ i ] )
                        add( list_value[ i ], 0, i );
                }
            } break;
            case 2 : {
                Vec<char, 2> name( 0, 1 );
                Vec<unsigned, 2> expo( 0, 0 );
                for( unsigned i = 0; i < list_value.size(); ++i ) {
                    if ( list_value[ i ] )
                        add( list_value[ i ], name, expo );
                    if ( expo[ 0 ] == 0 ) {
                        expo[ 0 ] = expo[ 1 ] + 1;
                        expo[ 1 ] = 0;
                    } else {
                        expo[ 0 ]--;
                        expo[ 1 ]++;
                    }
                }
            } break;
            case 3 : {
                Vec<char, 3> name( 0, 1, 2 );
                Vec<unsigned, 3> expo( 0, 0, 0 );
                for( unsigned i = 0; i < list_value.size(); ++i ) {
                    if ( list_value[ i ] )
                        add( list_value[ i ], name, expo );
                    if ( expo[ 0 ] == 0 ) {
                        if ( expo[ 1 ] == 0 ) {
                            expo[ 0 ] = expo[ 2 ] + 1;
                            expo[ 2 ] = 0; 
                        } else {
                            expo[ 1 ]--;
                            expo[ 2 ]++;
                        }
                    } else {
                        if ( expo[ 1 ] == 0 ) {
                            expo[ 0 ]--;
                            expo[ 1 ] = expo[ 2 ] + 1;
                            expo[ 2 ] = 0; 
                        } else {
                            expo[ 1 ]--;
                            expo[ 2 ]++;
                        }                        
                    }                    
                }
            } break;            
            default :
                std::cerr << "Error Poly.init() for nb_x = " << nb_x << std::endl;
                assert( 0 );
        }
    }
    
    template< int s >
    void init( Vec<T> &list_value, Vec<Vec<char, s > > &list_name, Vec<Vec<unsigned, s > > &list_expo ) {
        assert( ( list_value.size() == list_expo.size() ) and ( list_value.size() == list_name.size() ) );
        
        clear();
        for( unsigned i = 0; i < list_value.size(); ++i ) 
            if ( list_value[ i ] )
                add( list_value[ i ], list_name[ i ], list_expo[ i ] );
    }
    
    unsigned find_monom( char _name, unsigned ex ) {
        for( unsigned i = 0; i < monom_list.size(); ++i )
            if ( monom_list[ i ].same( _name, ex ) )
                return i;
        return npos;    
    }
   
    template< int s >
    unsigned find_monom( const Vec<char, s> _name, const Vec<unsigned, s> ex ) {
        for( unsigned i = 0; i < monom_list.size(); ++i )
            if ( monom_list[ i ].same( _name, ex ) )
                return i;
        return npos;    
    }
   
    Poly& operator+= ( const Monom &m ) {
        add( m, true );
        return *this;
    }
    
    Poly& operator+= ( const Poly &p ) {
        for( unsigned i = 0; i < p.monom_list.size(); ++i )
            add( p.monom_list[ i ] );
        update();
        return *this;
    }
    
    Poly& operator*= ( const Monom &m ) {
        if ( m.coef == 0 ) {
            vanish();
            return *this;
        }
        
        for( unsigned i = 0; i < monom_list.size(); ++i )
            monom_list[ i ] *= m;
            
        for( unsigned i = 0; i < monom_list.size(); ++i )
            if ( monom_list[ i ].coef == 0 )
                 monom_list.erase_elem_nb( i );
        return *this;
    }
    
    Poly& operator*= ( const Poly &p ) {
        Poly tmp( *this );
        monom_list.resize( 0 );
        for( unsigned i = 0; i < tmp.monom_list.size(); ++i )
            for( unsigned j = 0; j < p.monom_list.size(); ++j ) {
                Monom m = tmp.monom_list[ i ] * p.monom_list[ j ];
                add( m );
            }
        update();
        return *this;
    }    
    
    Poly operator* ( const Poly &p ) const {
        Poly tmp;
        for( unsigned i = 0; i < monom_list.size(); ++i )
            for( unsigned j = 0; j < p.monom_list.size(); ++j ) {
                Monom m = monom_list[ i ] * p.monom_list[ j ];
                tmp.add( m );
            }
        tmp.update();
        return tmp;
    } 
    
    Poly sqr() const {
        Poly tmp;
        for( unsigned i = 0; i < monom_list.size(); ++i ) {
            Monom m = monom_list[ i ].sqr();
            tmp.add( m ); 
        }
        
        for( unsigned i = 0; i < monom_list.size(); ++i )
            for( unsigned j = i + 1; j < monom_list.size(); ++j ) {
                Monom m = monom_list[ i ] * monom_list[ j ];
                m *= (T) 2;
                tmp.add( m );
            }
        tmp.update();
        return tmp;
    } 
    
    void update( T tolerance = 128 * std::numeric_limits<T>::epsilon() ) {
        if ( monom_list.size() <= 1 ) return;
        T maxi = 0;
        for( unsigned i = 0; i < monom_list.size(); ++i )
            maxi = LMT::max( maxi, LMT::abs( monom_list[ i ].coef ) );
        if ( maxi == 0 ) {
            monom_list.resize( 1 );
            monom_list[ 0 ].name.resize( 0 );
            monom_list[ 0 ].expo.resize( 0 );
        } else {
            for( unsigned i = 0; i < monom_list.size(); ++i )
                if ( LMT::abs( monom_list[ i ].coef ) * maxi < tolerance )
                    monom_list.erase_elem_nb( i );
        }
    }
    
    /*!
    si on écrit le polynom *this ainsi sum_i a_i X**i alors la méthode renvoie X**m où m = max( i ).
    Autrement dit, pour chaque indéterminée X_k on a le maximum des i_k sur tous les monômes X**i du polynôme. 
    */
    Monom max_degree() const {
        Monom m( 1 );
        
        for( unsigned i = 0; i < monom_list.size(); ++i )
            for( unsigned j = 0; j < monom_list[ i ].name.size(); ++j ) {
                unsigned k = m.name.find( monom_list[ i ].name[ j ] );
                if ( k < m.name.size() )
                    m.expo[ k ] = std::max( m.expo[ k ], monom_list[ i ].expo[ j ] );
                else {
                    unsigned l = 0;
                    while( ( l < m.name.size() ) and ( m.name[ l ] < monom_list[ i ].name[ j ] ) )
                        l++;
                    if ( l == m.name.size() ) {
                        m.name.push_back( monom_list[ i ].name[ j ] );
                        m.expo.push_back( monom_list[ i ].expo[ j ] );
                    } else {
                        m.name.insert_before( l, monom_list[ i ].name[ j ] );
                        m.expo.insert_before( l, monom_list[ i ].expo[ j ] );
                    }
                }
            }
        return m;
    }
    
    bool is_univariable() const {
        Monom m = max_degree();
        return ( m.name.size() == 1 ) or m.is_constant();
    }
    
    bool is_constant( T* pv = NULL ) const {
        if ( monom_list.size() > 1 )
            return false; 
        if ( monom_list.size() == 0 ) {
            if ( pv ) 
                *pv = (T) 0;
            return true;    
        }
        return monom_list[ 0 ].is_constant( pv );
    }
    
    /// le zéro, c'est un problème
    bool is_zero( T tolerance = 128 * std::numeric_limits<T>::epsilon() ) const {
        if ( monom_list.size() > 1 ) 
            return false;
        if ( monom_list.size() == 0 )
            return true;    
        return ( ( LMT::abs( monom_list[ 0 ].coef ) < tolerance ) and ( monom_list[ 0 ].name.size() == 0 ) );
    }
    
    Poly subs( char _name, T val  ) const {
        
        Poly res;
        
        for( unsigned i = 0; i < monom_list.size(); ++i ) 
            res += monom_list[ i ].subs( _name, val );
        
        return res;
    }
    
    /*!
    il faut que value[ 0 ] corresponde à name[ 0 ], etc...
    
    */
    template<int s >
    Poly subs( const Vec<char, s> _name, const Vec<T, s> value ) const {
    
        Poly ret;
        for( unsigned i = 0; i <  monom_list.size(); ++i ) {
            ret += monom_list[ i ].subs( _name, value );
        }
        ret.update();
        return ret;
    }
    
    Poly subs( char _name, const Poly &p ) const {
        
        T v;
        if ( p.is_constant( &v ) )
            return subs( _name, v );
        
        Poly res;
        /// pas optimisé
        Vec<Poly> power; power.push_back( p ); /// contiendra les puissances de p tel que power[ i ] = p**( i + 1 ); 
        
        for( unsigned i = 0; i < monom_list.size(); ++i ) {
            unsigned j = monom_list[ i ].name.find( _name );
            if ( j < monom_list[ i ].name.size() ) {
                Monom m( monom_list[ i ] );
                m.expo.erase_elem_nb( j );
                m.name.erase_elem_nb( j );
                if ( monom_list[ i ].expo[ j ] > power.size() ) {
                    while( monom_list[ i ].expo[ j ] > power.size() )
                        power.push_back( power.back() * p );
                }
                Poly tmp( power[ monom_list[ i ].expo[ j ] - 1 ] );
                tmp *= m;
                res += tmp;
            } else
                res += monom_list[ i ];
        }
        res.update();
        return res;
    }
    
    T evalf() const {
        T v;
        if ( is_constant( &v ) )
            return v;
        std::cerr << "Error Poly::eval() : the polynom is not a constant." << std::endl;
        return 0;
    }
    
    unsigned total_degree() const {
        unsigned res = 0;
        for( unsigned i = 0; i < monom_list.size(); ++i )
            res = std::max( res, monom_list[ i ].total_degree() );
        return res; 
    }
    
    std::string to_string( bool bracket = false, bool maple = true ) const {
        
        if ( monom_list.size() == 0 )
            return "0";
        
        std::string res;
        for( unsigned i = 0; i < monom_list.size(); ++i ) {
            if ( bracket )
                res += " <" + monom_list[ i ].to_string( maple ) + "> ";
            else
                res += monom_list[ i ].to_string( maple );
            if ( i < monom_list.size() - 1 )
                if ( monom_list[ i + 1 ].coef > 0 ) 
                    res += " + ";
        }
        return res;
    }
    
    friend std::ostream &operator<<( std::ostream &os, const Poly &p ) {
        os << p.to_string();
        return os;
    }
    
    void clear() {
        monom_list.resize( 0 );
    }
    
    void vanish() {
        monom_list.resize( 0 );
    }
    
    static const unsigned npos = 4294967295; /// = 2**32 - 1
    Vec< Monom > monom_list;
};

}

#endif
