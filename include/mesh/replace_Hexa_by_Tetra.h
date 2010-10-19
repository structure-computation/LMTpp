#ifndef REPLACE_HEXA_BY_TETRA_H
#define REPLACE_HEXA_BY_TETRA_H
  
namespace LMT {
 
template<class TM>
struct Replace_Hexa_by_Tetra {
    Replace_Hexa_by_Tetra( TM &m ) : ptr_m( &m ) {} 
    
    template< class NameBehavior, class TNode_, class TData, unsigned num_in_elem_list_ >
    bool operator() ( Element< Hexa, NameBehavior, TNode_, TData, num_in_elem_list_ > &e ) {
        Vec< typename Element< Hexa, NameBehavior, TNode_, TData, num_in_elem_list_ >::TNode*, 4 > vn;
        /// Tetra 0
        vn[ 0 ] = e.node( 0 );
        vn[ 1 ] = e.node( 1 );
        vn[ 2 ] = e.node( 3 );
        vn[ 3 ] = e.node( 4 );
        permutation_if_jac_neg ( Tetra(), vn.ptr() );
        ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
        /// Tetra 1
        vn[ 0 ] = e.node( 1 );
        vn[ 1 ] = e.node( 2 );
        vn[ 2 ] = e.node( 3 );
        vn[ 3 ] = e.node( 5 );
        permutation_if_jac_neg ( Tetra(), vn.ptr() );
        ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
        /// Tetra 2
        vn[ 0 ] = e.node( 1 );
        vn[ 1 ] = e.node( 3 );
        vn[ 2 ] = e.node( 4 );
        vn[ 3 ] = e.node( 5 );
        permutation_if_jac_neg ( Tetra(), vn.ptr() );
        ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
        /// Tetra 3
        vn[ 0 ] = e.node( 5 );
        vn[ 1 ] = e.node( 3 );
        vn[ 2 ] = e.node( 7 );
        vn[ 3 ] = e.node( 4 );
        permutation_if_jac_neg ( Tetra(), vn.ptr() );
        ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
        /// Tetra 4
        vn[ 0 ] = e.node( 5 );
        vn[ 1 ] = e.node( 2 );
        vn[ 2 ] = e.node( 3 );
        vn[ 3 ] = e.node( 7 );
        permutation_if_jac_neg ( Tetra(), vn.ptr() );
        ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
        /// Tetra 5
        vn[ 0 ] = e.node( 5 );
        vn[ 1 ] = e.node( 2 );
        vn[ 2 ] = e.node( 6 );
        vn[ 3 ] = e.node( 7 );
        permutation_if_jac_neg ( Tetra(), vn.ptr() );
        ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
        return true;    
    }
    
    /// pour tous les autres éléments autres que \a Hexa , on renvoie faux
    template<class TE> 
    bool operator() ( TE &e ) { 
        return false;
    }

    TM* ptr_m;
};

/*!
Cette fonction enlève tous les \a Hexa du maillage "m" et les remplace par des \a Tetra . Le maillage "m" est donc __modifié__ .  

Param :
    m : est un maillage de la plateforme.
    
Retour :
    m avec aucun \a Hexa

*/
template <class TM>
void replace_Hexa_by_Tetra( TM &m ) {

    Replace_Hexa_by_Tetra<TM> rh( m );
    
    m.remove_elements_if( rh );
}
 
}
#endif  /// REPLACE_HEXA_BY_TETRA
 
