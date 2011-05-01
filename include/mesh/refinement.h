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
#include "tetra.h"

namespace LMT {

namespace LMTPRIVATE {
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
            template<class NB,class TN,class TD,unsigned nl> void operator()(Element<Bar,NB,TN,TD,nl> &e) const {
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
    LMTPRIVATE::Refinment<TM,TM,0,TM::dim+1> r(&m);
    r.update_cut(m,op);

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
        if ( d0 * d1 >= 0 )
            return 0;
        typename TE::T o = d0 / ( d0 - d1 );
        if ( o < 0.1 ) {
            e.node( 0 )->pos = e.node( 0 )->pos + ( e.node( 1 )->pos - e.node( 0 )->pos ) * o;
            return 0;
        }
        if ( o > 0.9 ) {
            e.node( 1 )->pos = e.node( 1 )->pos + ( e.node( 0 )->pos - e.node( 1 )->pos ) * ( 1 - o );
            return 0;
        }
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

};

#endif // LMT_refinement_HEADER
