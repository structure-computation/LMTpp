#ifndef REPLACE_WEDGE_BY_TETRA_H
#define REPLACE_WEDGE_BY_TETRA_H
  
namespace LMT {
 
template<class TM>
struct Replace_Wedge_by_Tetra {
    Replace_Wedge_by_Tetra( TM &m ) : ptr_m( &m ) {} 
    
    template< class NameBehavior, class TNode_, class TData, unsigned num_in_elem_list_ >
    bool operator() ( Element< Wedge, NameBehavior, TNode_, TData, num_in_elem_list_ > &e ) {
        Vec< typename Element< Wedge, NameBehavior, TNode_, TData, num_in_elem_list_ >::TNode*, 4 > vn;
        /// Tetra 0
//         vn[ 0 ] = e.node( 0 );
//         vn[ 1 ] = e.node( 1 );
//         vn[ 2 ] = e.node( 2 );
//         vn[ 3 ] = e.node( 5 );
//         permutation_if_jac_neg ( Tetra(), vn.ptr() );
//         ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
//         /// Tetra 1
//         vn[ 0 ] = e.node( 0 );
//         vn[ 1 ] = e.node( 1 );
//         vn[ 2 ] = e.node( 3 );
//         vn[ 3 ] = e.node( 5 );
//         permutation_if_jac_neg ( Tetra(), vn.ptr() );
//         ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
//         /// Tetra 2
//         vn[ 0 ] = e.node( 1 );
//         vn[ 1 ] = e.node( 3 );
//         vn[ 2 ] = e.node( 4 );
//         vn[ 3 ] = e.node( 5 );
//         permutation_if_jac_neg ( Tetra(), vn.ptr() );
//         ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );

/// well
        vn[ 0 ] = e.node( 0 );
        vn[ 1 ] = e.node( 1 );
        vn[ 2 ] = e.node( 2 );
        vn[ 3 ] = e.node( 3 );
        permutation_if_jac_neg ( Tetra(), vn.ptr() );
        ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
        /// Tetra 1
        vn[ 0 ] = e.node( 2 );
        vn[ 1 ] = e.node( 3 );
        vn[ 2 ] = e.node( 4 );
        vn[ 3 ] = e.node( 5 );
        permutation_if_jac_neg ( Tetra(), vn.ptr() );
        ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
        /// Tetra 2
        vn[ 0 ] = e.node( 1 );
        vn[ 1 ] = e.node( 2 );
        vn[ 2 ] = e.node( 3 );
        vn[ 3 ] = e.node( 4 );
        permutation_if_jac_neg ( Tetra(), vn.ptr() );
        ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );

/// old
//         vn[ 0 ] = e.node( 0 );
//         vn[ 1 ] = e.node( 1 );
//         vn[ 2 ] = e.node( 2 );
//         vn[ 3 ] = e.node( 4 );
//         permutation_if_jac_neg ( Tetra(), vn.ptr() );
//         ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
//         /// Tetra 1
//         vn[ 0 ] = e.node( 0 );
//         vn[ 1 ] = e.node( 2 );
//         vn[ 2 ] = e.node( 4 );
//         vn[ 3 ] = e.node( 5 );
//         permutation_if_jac_neg ( Tetra(), vn.ptr() );
//         ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
//         /// Tetra 2
//         vn[ 0 ] = e.node( 0 );
//         vn[ 1 ] = e.node( 3 );
//         vn[ 2 ] = e.node( 4 );
//         vn[ 3 ] = e.node( 5 );
//         permutation_if_jac_neg ( Tetra(), vn.ptr() );
//         ptr_m->add_element( Tetra(), DefaultBehavior(), vn.ptr() );
        return true;    
    }
    
    /// pour tous les autres éléments autres que \a Wedge , on renvoie faux
    template<class TE> 
    bool operator() ( TE &e ) { 
        return false;
    }

    TM* ptr_m;
};

/*!
Cette fonction enlève tous les \a Hexa du maillage "m" et les remplace par des \a Wedge . Le maillage "m" est donc __modifié__ .  

Param :
    m : est un maillage de la plateforme.
    
Retour :
    m avec aucun \a Wedge

*/
template <class TM>
void replace_Wedge_by_Tetra( TM &m ) {

    Replace_Wedge_by_Tetra<TM> rw( m );
    
    m.remove_elements_if( rw );
}
 
}
#endif  /// REPLACE_WEDGE_BY_TETRA
 
