//
// C++ Interface: refinement
//
// Description:
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_refinement_HEADER
#define LMT_refinement_HEADER

#include "mesh.h"
#include "triangle.h"
#include "quad.h"
#include "tetra.h"
#include "../util/rectilinear_iterator.h"

namespace LMT {

namespace LMTPRIVATE {

    template<class TM,class TMParent, unsigned nb_elem_type, class TE, class T >
    void append_node_cut_at_bar( TM &m, 
                                 TMParent &m_parent, 
                                 DynamicData<typename TM::TNode*, nb_elem_type > &cut, 
                                 TE *e, 
                                 T p0, 
                                 T p1 ) {

        typedef typename TMParent::TNode TN;
        TN *nn = m_parent.add_node();
        m.elem_list.get_data( cut, *e ) = nn;

        std::pair< T,const TN *> pond_list[] = {
            std::pair< T,const TN *>( p0, e->node_virtual( 0 ) ),
            std::pair< T,const TN *>( p1, e->node_virtual( 1 ) )
        };
        DM::get_ponderation( pond_list, 2, *nn );
    }

    template<class TM,class TMParent,unsigned num_sub_mesh,unsigned max_num_sub_mesh>
    struct Refinment {
        typedef typename TM::TNode TNode;
        typedef Refinment<typename TM::TNext,TMParent,num_sub_mesh+1,max_num_sub_mesh> RNext;
        typedef typename TM::Tpos T;
        typedef DynamicData<TNode *,TM::TElemList::nb_elem_type> TDN;

        ///
        Refinment(TMParent *mp):m_parent(mp),cut("cut"),next(mp) {}
        
        ///
        template<class Op> struct RefineBars {
            template<class TE> void operator()(const TE &e) const {}
            template<class NB,class TN,class TD,unsigned nl> void operator()( Element<Bar,NB,TN,TD,nl> &e ) const {
                T val = (*op)(e);
                if ( val == 1 )
                    val = 0.5;
                //
                if ( val > 0 and val < 1 ) {
                    typename TMParent::TNode *nn = m_parent->add_node();
                    m->elem_list.get_data(*cut,e) = nn;

                    std::pair<typename TM::Tpos,const TN *> pond_list[] = {
                        std::pair<typename TM::Tpos,const TN *>( 1-val, e.node(0) ),
                        std::pair<typename TM::Tpos,const TN *>( val  , e.node(1) )
                    };
                    DM::get_ponderation( pond_list, 2, *nn );
                    //append_node_cut_at_bar( *m, *m_parent, *cut, &e, 1 - val, val );
                }
                else
                    m->elem_list.get_data(*cut,e) = (TNode *)NULL;
            }
            Op *op;
            TDN *cut;
            TM *m;
            TMParent *m_parent;
        };
        ///
        template<class Op> void update_cut(TM &m,Op &op) {
            // create nodes on center of Bar elements which are considered to be too long
            next.update_cut(m.next,op);

            RefineBars<Op> rb;
            rb.op = &op;
            rb.cut = &cut;
            rb.m = &m;
            rb.m_parent = m_parent;

            m.elem_list.synchronize_dyn(&cut);
            apply( m.elem_list, rb );
        }
        ///
        template<class TE> bool div(TE &e,const Number<0> &nnn) { return false; }
        template<class TE> bool div(TE &e,const Number<1> &nnn) {
            TNode *nn[] = { m_parent->elem_list.get_data(cut,e) };
            return divide_element( e, *m_parent, nn );
        }
        template<class TE> bool div(TE &e,const Number<2> &nnn) {
            static const unsigned nb_children = NbChildrenElement<typename TE::NE,1>::res;
            TNode *nn[nb_children];
            for(unsigned i=0;i<nb_children;++i)
                nn[i] = m_parent->template sub_mesh<1>().elem_list.get_data(next.cut, *m_parent->get_children_of(e,Number<1>())[i] );
            return divide_element( e, *m_parent, nn );
        }
        template<class TE> bool div(TE &e,const Number<3> &nnn) {
            static const unsigned nb_children = NbChildrenElement<typename TE::NE,2>::res;
            TNode *nn[nb_children];
            for(unsigned i=0;i<nb_children;++i)
                nn[i] = m_parent->template sub_mesh<2>().elem_list.get_data(next.next.cut, *m_parent->get_children_of(e,Number<2>())[i] );
            return divide_element( e, *m_parent, nn );
        }
        ///
        template<class TE> bool operator()(TE &e) { return div(e,Number<TE::nb_var_inter>()); }
                
        /// A tous les éléments 2D qui ont au moins deux arêtes coupés, on coupe tous les autres arêtes
        /// Number<dim> représente la dimension du maillage initial.
        template<class TE> 
        void append_constrainted_cut( TE &e, const Number<0> &nnn ) { }
        
        template<class TE> 
        void append_constrainted_cut( TE &e, const Number<1> &nnn ) { }
        
        template<class TE> 
        void append_constrainted_cut( TE &e, const Number<2> &nnn ) {
            static const unsigned nb_children = NbChildrenElement<typename TE::NE,1>::res;
            TNode *nn[ nb_children ];
            unsigned cpt_cut = 0;
            for( unsigned i = 0; i < nb_children; ++i ) {
                nn[ i ] = m_parent->template sub_mesh<1>().elem_list.get_data( next.cut, *m_parent->get_children_of( e, Number<1>() )[ i ] );
                if ( nn[ i ] )
                    cpt_cut++;
            }
            
            if ( cpt_cut >= 2 ) {
                for( unsigned i = 0; i < nb_children; ++i )
                    if ( nn[ i ] == NULL )
                        append_node_cut_at_bar( m_parent->template sub_mesh<1>(), 
                                                *m_parent, 
                                                next.cut, 
                                                m_parent->get_children_of( e, Number<1>() )[ i ], 
                                                0.5, 
                                                0.5 );
            }
        }
        
        template<class TE> 
        void append_constrainted_cut( TE &e, const Number<3> &nnn ) {
            static const unsigned nb_children = NbChildrenElement<typename TE::NE,2>::res;
            TNode *nn[nb_children];
            unsigned cpt_cut = 0;
            for( unsigned i = 0; i < nb_children; ++i ) {
                nn[ i ] = m_parent->template sub_mesh<2>().elem_list.get_data( next.next.cut, *m_parent->get_children_of( e, Number<2>() )[ i ] );
                if ( nn[ i ] )
                    cpt_cut++;
            }
            
            if ( cpt_cut >= 2 ) {
                for( unsigned i = 0; i < nb_children; ++i )
                    if ( nn[ i ] == NULL )
                        append_node_cut_at_bar( m_parent->template sub_mesh<1>(), 
                                                *m_parent, 
                                                next.cut, 
                                                m_parent->get_children_of( e, Number<2>() )[ i ], 
                                                0.5, 
                                                0.5 );
            }
        }
        /// deuxième foncteur
        template<class TE, unsigned num> bool operator()(TE &e, const Number<num> &nnn ) { 
            append_constrainted_cut( e, nnn ); 
        }

        /// on étend la coupe si l'arête coupée n'est pas la plus longue de l'élément 
        /// Number<dim> représente la dimension du maillage initial.
        template<class TN> 
        void spread_cut( ElementAncestor<TN> *ea, const Number<0> &nnn ) { }
        
        template<class TN> 
        void spread_cut( ElementAncestor<TN> *ea, const Number<1> &nnn ) { }
        
        template<class TN> 
        void spread_cut( ElementAncestor<TN> *ea, const Number<2> &nnn ) {
            typedef typename TN::T T;
            typedef ElementAncestor<TN> EA;
            
            unsigned nb_children = ea->nb_children_virtual( 1 );
            Vec<TNode *> nn; nn.resize( nb_children );
            Vec<T> ll; ll.resize( nb_children );

            T max_l_cut = 0.;

            for( unsigned i = 0; i < nb_children; ++i ) {
                nn[ i ] = m_parent->template sub_mesh<1>().elem_list.get_data( next.cut, *m_parent->get_children_of_EA( ea, Number<1>() )[ i ] );
                ll[ i ] = length( m_parent->get_children_of_EA( ea, Number<1>() )[ i ]->node_virtual( 1 )->pos - m_parent->get_children_of_EA( ea, Number<1>() )[ i ]->node_virtual( 0 )->pos );
                if ( ( nn[ i ] ) and ( ll[ i ] > max_l_cut ) )
                    max_l_cut = ll[ i ];
            }
            
            if ( max_l_cut > 0 ) {
            
                SimpleConstIterator<EA *> itea = m_par->get_elem_neighbours_EA( ea );
            
                for( unsigned i = 0; i < nb_children; ++i ) {
                    bool ok_for_spread = false;
                    if ( ( nn[ i ] == NULL ) and ( ll[ i ] >= max_l_cut ) ) {
                        append_node_cut_at_bar( m_parent->template sub_mesh<1>(), 
                                                *m_parent, 
                                                next.cut, 
                                                m_parent->get_children_of_EA( ea, Number<1>() )[ i ], 
                                                0.5, 
                                                0.5 );
                        ok_for_spread = true;
                    }
                    
                    if ( ( nn[ i ] ) or ( ok_for_spread ) ) {
                        /// extension aux voisins
                        /// TODO
                        /// ne pas oublier de vérifier que la barre n'est pas déjà coupée            
                        //spread_cut( , nnn );
                    }
                }
            }
        }
        
        template<class TE> 
        void spread_cut( TE &e, const Relative_Number<3> &nnn ) {
            /// TODO
        }

        TMParent *m_parent;
        TDN cut;
        RNext next;
    };
    template<class TM,class TMParent,unsigned max_num_sub_mesh>
    struct Refinment<TM,TMParent,max_num_sub_mesh,max_num_sub_mesh> {
        Refinment(TMParent *mp) {}
        template<class T> void update_cut(const TM &m,T max_length) const {}
    };
};

/*!
    Cette fonction divise les barres (segments) d'un maillage 1, 2 ou 3D suivant l'opérateur op.

    Ça veut dire, que ça divise les éléments Tetra, Hexa, etc... qui contiennent ces barres.

    L'opérateur op peut soit renvoyer  un booléen soit un double. Il prend aussi forcément un élément de type barre en paramètre. 
    
    Si c'est 0 -> on ne coupe pas
    
    Si c'est 1 (=true) -> on coupe au milieu
    
    Si c'est dans ] 0, 1 [ il coupe par de façon proportionnelle ( 0 -> vers le noeud 0, 1 -> vers le noeud 1).
        
    C'est-à-dire qu'il est au moins de la forme :
    \code C/C++
        struct MyOp {
            template<class TE
            RET operator()( TE &e ) const { // e un 1 var_inter (Bar, ...)
                  /// votre code 
            }
        };
    où RET est soit un type flottant, soit un booléen.
    S'il renvoie un booléen, il y a opération de division au milieu de la barre s'il renvoie vrai.
    S'il renvoie un double r, rien n'est fait lorsque r=0, il divise la barre lorsque r est compris entre 0 et 1. La position de la division dépend de r suivant les points barycentrique ( pos(0); 1 - r ) ( pos(1); r ) . Lorsque r=1, il divise au milieu.
    Enfin refinement() renvoie vrai si elle divise au moins une barre et faux sinon.

    \keyword Maillage/Elément/Opération

    subdivide each element bar e contained in mesh or sub_meshes such as op(e)==true (true means subdivision). Subdivide parents


    Voici un exemple pour diviser un maillage jusqu'à obtenir une taille max donnée

    \code C/C++
        read_msh_2( ... );
        while ( refinement_if_length_sup( m, max_length ) );



*/
template<class TM,class Op>
bool refinement(TM &m,Op &op) {
    // m.update_elem_children();
    m.update_elem_children( Number<TM::nvi-1>() );
    LMTPRIVATE::Refinment<TM,TM,0,TM::dim+1> r( &m );
    r.update_cut( m, op );
    
    /// on raffine s'il y a au moins deux arêtes coupées par élément
    apply( m.elem_list, r, Number<TM::dim>() );
    /// on propage le raffinement
//     m.update_elem_neighbours();
//     for( unsigned i = 0; i < m.elem_list.size(); ++i )
//         r.spread_cut( m.elem_list[ i ], Number<TM::dim>() );
    

    m.elem_list.reg_dyn( &r.cut );
    bool res = m.remove_elements_if( r );
    m.elem_list.unreg_dyn( &r.cut );

    m.signal_connectivity_change();
    return res;
}

/*!
    Peut être utilisé pour couper un maillage avec un level-set
*/
template<class PhiExtract>
struct LevelSetRefinement {
    LevelSetRefinement( const PhiExtract &p ) : ed( p ) {}
    template<class TE> typename TE::T operator()( TE &e ) const {
        typename TE::T d0 = ed( *e.node(0) );
        typename TE::T d1 = ed( *e.node(1) );
        if ( ( d0 * d1 ) >= 0 )
            return 0;
        typename TE::T o = d0 / ( d0 - d1 );
//         if ( o < 0.1 ) {
//             e.node( 0 )->pos = e.node( 0 )->pos + ( e.node( 1 )->pos - e.node( 0 )->pos ) * o;
//             return 0;
//         }
//         if ( o > 0.9 ) {
//             e.node( 1 )->pos = e.node( 1 )->pos + ( e.node( 0 )->pos - e.node( 1 )->pos ) * ( 1 - o );
//             return 0;
//         }
        return o;
    }
    const PhiExtract &ed;
};

template<class PhiExtract>
struct LevelSetRemoveNeg {
    LevelSetRemoveNeg( const PhiExtract &p ) : ed( p ) {}
    template<class TE> typename TE::T operator()( const TE &e ) const {
        typename TE::T d = 0;
        for(unsigned i=0;i<TE::nb_nodes;++i)
            d += ed( *e.node(i) );
        d /= TE::nb_nodes;
        return d <= 0;
    }
    const PhiExtract &ed;
};

/*!
    Ojectif :
        Cette fonction permet de couper un maillage en fonction de la valeur d'un atribut nodal et scalaire. Plus précisément considérons un attribut nodal scalaire ( i.e. double en général ), qu'on nommera phi. Après l'appel de la fonction, le maillage n'aura que des éléments pour lesquelles la valeur de phi aux noeuds est positive.
        
    Paramètres :
        * <strong> m </strong> est un maillage qui sera modifié si nécessaire.
        * <strong> PhiExtract </strong> est une classe qui permet d'accéder à la valeur d'un attribut du maillage m. Par exemple ce sera la classe \a ExtractDM < phi_DM > où <strong> phi </strong> est le nom de l'attribut. Remarque : il faut que le MeshCarac du maillage contienne une classe phi_DM.
           
    Retour :
        renvoie vrai s'il y a eu des changements et faux sinon. 
        
    Voici un exemple de code. Il faudra adapter le MeshCarac.
    \code C/C++
    
        #include "mesh/make_rect.h"
        #include "mesh/refinement.h"
        #include "mesh/displayparaview.h"
        
        // inclusion du code de notre MeshCarac  
        #include "MonMeshCarac.h"
    
        int main(int argc,char **argv) {
        
            typedef Mesh< Mesh_carac_MonMeshCarac< double,2> > TM;
            typedef TM::Pvec Pvec;
            typedef TM::TNode::T T;
            
            TM m;
            make_rect( m, Triangle(), Pvec( 0, 0 ), Pvec( 1., 1. ), Pvec( 20, 20 ) );
        
            for( unsigned i = 0 ; i < m.node_list.size(); ++i )
                m.node_list[i].phi = sin( std::sqrt( i ) * 5. ); 
        
            display_mesh( m );
        
            PRINT( level_set_cut( m, ExtractDM< phi_DM >() ) );

            display_mesh( m );
            
            return 0; 
        }
    
*/
template<class TM,class PhiExtract>
bool level_set_cut( TM &m, const PhiExtract &p ) {
    LevelSetRefinement<PhiExtract> lr( p );
    refinement( m, lr );
    LevelSetRemoveNeg<PhiExtract> ln( p );
    return m.remove_elements_if( ln );
}

/*!
    opérateur créé pour la fonction \a refinement_if_length_sup .
*/
template<class T>
struct RafinementOpBasedOnLength {
    template<class TE> bool operator()(const TE &e) const { return length(e.node(1)->pos-e.node(0)->pos) > max_length; }
    T max_length;
};

/*!

    Cette fonction divise toutes les barres (segments) du maillage en deux pour lesquelles la longueur est supérieure à max_length.
    Elle renvoie vrai si elle divise au moins une barre et faux sinon. Ainsi si on souhaite que toutes les barres soient inférieures à max_length, on relancera la fonction autant de fois que nécessaire.

    \keyword Maillage/Elément/Opération
    subdivide each element bar e such as length(e)>max_length (true means subdivision).
*/
template<class TM,class T>
bool refinement_if_length_sup(TM &m,T max_length) {
    RafinementOpBasedOnLength<T> rl;
    rl.max_length = max_length;
    return refinement(m,rl);
}

/*!
  Exemple :

  \code
    #include <mesh/mesh.h>
    #include <mesh/meshcaracstd.h>
    #include <mesh/refinement.h>
    #include <mesh/make_rect.h>
    #include <mesh/displayparaview.h>
    #include <correlation/ImgInterp.h>
    using namespace LMT;


    int main() {
        typedef Mesh<MeshCaracStd<2,2> > TM;
        typedef ImgInterp<double,2> TI;

        TM m;
        make_rect( m, Triangle(), 0, 1024, 40 );

        TI bin( "/home/leclerc/Data/Croix/masque_0.png" );
        TI cut = img_dist_from_front( bin, 100, 128.0 );
        TI stp; stp.resize( cut.sizes, -1 );

        cut.display( true );

        LevelSetImageRefinement<TI> lr( cut, stp );
        refinement( m, lr );

        display( m );
    }


*/
template<class TIMG1,class TIMG2=TIMG1>
struct LevelSetImageRefinement {
    LevelSetImageRefinement( const TIMG1 &ls_crack, const TIMG2 &ls_front ) : ls_crack( ls_crack ), ls_front( ls_front ) {}
    template<class TE> double operator()( TE &e ) const {
        double step = 1.0/measure( e );
        for(double x=0;x<=1;x+=step) {
            typename TE::Pvec P0 = e.pos(0) + (e.pos(1)-e.pos(0))*(x-step);
            if ( ls_front( P0 ) > 0 )
                return 0;
            typename TE::Pvec P1 = e.pos(0) + (e.pos(1)-e.pos(0))*(x     );
            bool s1 = ls_crack( P0 ) > 0;
            bool s2 = ls_crack( P1 ) > 0;
            if ( s1 xor s2 ) {
                if ( x < 0.4 ) {
                    e.node(0)->pos = P1;
                    return 0;
                }
                if ( x > 0.6 ) {
                    e.node(1)->pos = P1;
                    return 0;
                }
                return x;
            }
        }
        return 0;
    }
    const TIMG1 &ls_crack;
    const TIMG2 &ls_front;
};

/*!
    Objectif :
        Ce foncteur est conçu pour la fonction \a refinement () . Il permet de raffiner localement un maillage. Pour plus de renseignement, voir l'explication à la fin.
        
    Attributs :
        * <strong> c </strong> le centre de la zone que l'on veut raffiner. c n'est pas forcément un point dans le maillage.
        * <strong> l_min </strong> la longueur minimale des côtés des éléments du maillage.
        * <strong> k </strong> le coefficient d'augmentation de la longueur maximale des côtés des éléments en fonction de la distance au point c.
        
    Description :
        on décide de couper le côté d'un élément ( i.e. une \a Bar ) si sa longueur est supérieure à d * k + l_min où d est la distance entre le milieu du côté et le centre c.
         
    Exemple de code :
    \code C/C++
        typedef Mesh< Mesh_carac_MonMeshCarac< double,2> > TM;
        typedef TM::Pvec Pvec;
        typedef TM::TNode::T T;
    
        refinement( m, Local_refinement<T, Pvec >( 0.01, 0.2, Pvec( 0.2, 0.5 ) ) );
    
    On raffinera au point de coordonnées ( 0.2, 0.5 ) avec une longueur minimale de 0.01 et une augmentation de 0.2. 

*/
template < class T, class Pvec>
struct Local_refinement {
    Local_refinement( T length_min, T _k, Pvec _c ) : l_min( length_min ), k( _k ), c( _c ) {}

    template<class TE> 
    bool operator()( TE &e ) const {
        T l = length( e.node( 1 )->pos - e.node( 0 )->pos );
        T v = length( center( e ) - c ) * k + l_min;
        if ( l > v ) 
            return true;
        else
            return false;
    }

    T l_min, k;
    Pvec c; /// centre
};

namespace LMTPRIVATE {
    template<class TM,class MA,class I>
    struct MaskCutter {
        typedef typename TM::Tpos T;
        MaskCutter( const MA &mask, I lim_inf, I lim_sup ) : mask( mask ), lim_inf( lim_inf ), lim_sup( lim_sup ) {}
        //
        struct Cut {
            Cut( MaskCutter &mc ) : mc( mc ) {}
            template<class TE> T operator()( TE &e ) const {
                if ( mc.node_is_blocked[ e.node( 0 )->number ] and mc.node_is_blocked[ e.node( 1 )->number ] )
                    return 0;
                double step = 1.0 / measure( e );
                for( double x=0; x <= 1; x += step ) {
                    typename TE::Pvec P0 = e.pos( 0 ) + ( e.pos( 1 ) - e.pos( 0 ) ) * ( x - step );
                    typename TE::Pvec P1 = e.pos( 0 ) + ( e.pos( 1 ) - e.pos( 0 ) ) * ( x        );
                    bool c_01 = mc.mask( P0 ) < mc.lim_inf and mc.mask( P1 ) >= mc.lim_sup;
                    bool c_10 = mc.mask( P1 ) < mc.lim_inf and mc.mask( P0 ) >= mc.lim_sup;
                    if ( c_01 or c_10 )
                        return x;
                }
                return 0;
            }
            MaskCutter &mc;
        };
        //
        struct Rem {
            Rem( MaskCutter &mc ) : mc( mc ) {}
            template<class TE> bool operator()( TE &e ) const { return mc.mask( center( e ) ) < mc.lim_inf; }
            MaskCutter &mc;
        };

        const MA &mask;
        I lim_inf;
        I lim_sup;
        Vec<bool> node_is_blocked;
    };
}

/*!
  coupe d'un maillage par un masque. Un élément est coupé quand un bord a mask < lim_inf et l'autre a mask >= lim_sup
*/
template<class TM,class MA,class I>
bool mask_cut( TM &m, const MA &mask, I lim_inf, I lim_sup, I dist_disp, bool remove_inf_elem = false ) {
    typedef LMTPRIVATE::MaskCutter<TM,MA,I> MC;
    typedef typename TM::Pvec Pvec;
    typedef typename TM::Tpos T;
    //
    MC mc( mask, lim_inf, lim_sup );
    mc.node_is_blocked.resize( m.node_list.size(), false );
    // nodal displacement
    m.update_skin();
    for( int n = 0; n < m.node_list.size(); ++n ) {
        Pvec &P = m.node_list[ n ].pos, N = P;
        T o = dist_disp * ( 1 + 1e-6 ), d = o;
        if ( mask( P ) < lim_inf ) {
            for( Rectilinear_iterator<T,TM::dim> iter( Pvec( P - dist_disp ), Pvec( P + dist_disp + 1 ) ); iter; ++iter ) {
                T n = length( P - iter.pos );
                if ( d > n and mask( iter.pos ) >= lim_sup ) {
                    N = iter.pos;
                    d = n;
                }
            }
        } else if ( mask( P ) >= lim_sup ) {
            for( Rectilinear_iterator<T,TM::dim> iter( Pvec( P - dist_disp ), Pvec( P + dist_disp + 1 ) ); iter; ++iter ) {
                T n = length( P - iter.pos );
                if ( d > n and mask( iter.pos ) < lim_inf ) {
                    N = iter.pos;
                    d = n;
                }
            }
        }
        if ( d != o ) {
            mc.node_is_blocked[ m.node_list[ n ].number ] = true;
            P = N;
        }
    }
    // cut
    typename MC::Cut cut( mc );
    bool res = refinement( m, cut );
    // rem
    if ( remove_inf_elem ) {
        typename MC::Rem rem( mc );
        m.remove_elements_if( rem );
    }
    return res;
}



};

#endif // LMT_refinement_HEADER
