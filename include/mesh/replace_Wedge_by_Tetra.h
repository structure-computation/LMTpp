#ifndef REPLACE_WEDGE_BY_TETRA_H
#define REPLACE_WEDGE_BY_TETRA_H
  
namespace LMT {
 
template<class TM>
struct Replace_Wedge_by_Tetra {
    Replace_Wedge_by_Tetra( TM &m ) : ptr_m( &m ), impossible( false ) {} 
    
    template< class NameBehavior, class TNode_, class TData, unsigned num_in_elem_list_ >
    bool operator() ( Element< Wedge, NameBehavior, TNode_, TData, num_in_elem_list_ > &e ) {
        typedef typename Element< Wedge, NameBehavior, TNode_, TData, num_in_elem_list_ >::TNode::T T;
        
        typename Element< Wedge, NameBehavior, TNode_, TData, num_in_elem_list_ >::TNode* nn[4];
        T l1, l2;
        unsigned min1, min2, BF, BD, CD;
        
        if ( impossible ) return false;
        
        
        l1 = length( e.pos( 1 ) - e.pos( 5 ) );
        l2 = length( e.pos( 2 ) - e.pos( 4 ) );
        if ( l1 < l2 ) 
            BF = 1;
        else {
            if ( l2 > l1 )
               BF = 0;
            else {
                min1 = min( e.node( 1 )->number, e.node( 5 )->number );
                min2 = min( e.node( 2 )->number, e.node( 4 )->number );
                if ( min1 < min2 ) BF = 1; else BF = 0;
            }
        }

        l1 = length( e.pos( 1 ) - e.pos( 3 ) );
        l2 = length( e.pos( 0 ) - e.pos( 4 ) );
        if ( l1 < l2 ) 
            BD = 1;
        else {
            if ( l2 > l1 )
               BD = 0;
            else {
                min1 = min( e.node( 1 )->number, e.node( 3 )->number );
                min2 = min( e.node( 0 )->number, e.node( 4 )->number );
                if ( min1 < min2 ) BD = 1; else BD = 0;
            }
        }

        l1 = length( e.pos( 2 ) - e.pos( 3 ) );
        l2 = length( e.pos( 0 ) - e.pos( 5 ) );
        if ( l1 < l2 ) 
            CD = 1;
        else {
            if ( l2 > l1 )
               CD = 0;
            else {
                min1 = min( e.node( 2 )->number, e.node( 3 )->number );
                min2 = min( e.node( 0 )->number, e.node( 5 )->number );
                if ( min1 < min2 ) CD = 1; else CD = 0;
            }
        }
        
        unsigned index = BF + 2 * BD + 4 * CD;
        switch( index ) {
            case 0 : /// 000
                nn[0] = e.node( 0 );
                nn[1] = e.node( 1 );
                nn[2] = e.node( 2 );
                nn[3] = e.node( 4 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 3 );
                nn[1] = e.node( 4 );
                nn[2] = e.node( 5 );
                nn[3] = e.node( 0 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 0 );
                nn[1] = e.node( 2 );
                nn[2] = e.node( 5 );
                nn[3] = e.node( 4 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                break;
            case 1 : /// 001
                nn[0] = e.node( 0 );
                nn[1] = e.node( 1 );
                nn[2] = e.node( 2 );
                nn[3] = e.node( 5 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 0 );
                nn[1] = e.node( 1 );
                nn[2] = e.node( 4 );
                nn[3] = e.node( 5 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 0 );
                nn[1] = e.node( 3 );
                nn[2] = e.node( 5 );
                nn[3] = e.node( 4 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                break;                
            case 2 : /// 010
                impossible = true;
                std::cerr << "Error Replace_Wedge_by_Tetra : case 2" << std::endl;
                return false;
                break;
            case 3 : /// 011
                nn[0] = e.node( 0 );
                nn[1] = e.node( 1 );
                nn[2] = e.node( 2 );
                nn[3] = e.node( 5 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 1 );
                nn[1] = e.node( 3 );
                nn[2] = e.node( 4 );
                nn[3] = e.node( 5 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 0 );
                nn[1] = e.node( 1 );
                nn[2] = e.node( 3 );
                nn[3] = e.node( 5 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                break;
            case 4 : /// 100
                nn[0] = e.node( 3 );
                nn[1] = e.node( 4 );
                nn[2] = e.node( 5 );
                nn[3] = e.node( 2 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 0 );
                nn[1] = e.node( 1 );
                nn[2] = e.node( 2 );
                nn[3] = e.node( 4 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 0 );
                nn[1] = e.node( 3 );
                nn[2] = e.node( 4 );
                nn[3] = e.node( 2 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                break;
            case 5 : /// 101
                impossible = true;
                std::cerr << "Error Replace_Wedge_by_Tetra : case 5" << std::endl;
                return false;
                break;
            case 6 : /// 110
                nn[0] = e.node( 3 );
                nn[1] = e.node( 4 );
                nn[2] = e.node( 5 );
                nn[3] = e.node( 2 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 1 );
                nn[1] = e.node( 3 );
                nn[2] = e.node( 4 );
                nn[3] = e.node( 2 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 0 );
                nn[1] = e.node( 1 );
                nn[2] = e.node( 3 );
                nn[3] = e.node( 2 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                break;
            case 7 : /// 111
                nn[0] = e.node( 0 );
                nn[1] = e.node( 1 );
                nn[2] = e.node( 2 );
                nn[3] = e.node( 3 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 1 );
                nn[1] = e.node( 3 );
                nn[2] = e.node( 4 );
                nn[3] = e.node( 5 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                nn[0] = e.node( 1 );
                nn[1] = e.node( 2 );
                nn[2] = e.node( 5 );
                nn[3] = e.node( 3 );
                permutation_if_jac_neg ( Tetra(), nn );
                DM::copy( e, *( ptr_m->add_element( Tetra(), NameBehavior(), nn ) ) );
                break;
            default : ;
        }
        return true;    
    }
    
    /// pour tous les autres éléments autres que \a Wedge , on renvoie faux
    template<class TE> 
    bool operator() ( TE &e ) { 
        return false;
    }

    TM* ptr_m;
    bool impossible;
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
    
    if ( rw.impossible ) 
        std::cerr << "Error replace_Wedge_by_Tetra() : impossible to replace all wedges. " << std::endl;
}
 
}
#endif  /// REPLACE_WEDGE_BY_TETRA
 
