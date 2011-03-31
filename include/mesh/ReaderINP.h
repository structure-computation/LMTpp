#ifndef READER_INP_H
#define READER_INP_H

#include <assert.h>
#include <map>
#include <limits>
#include <iostream>
#include <stdexcept>

#include "mesh.h"
#include "hexa.h"
#include "tetra.h"
#include "tetra_10.h"
#include "triangle.h"
#include "triangle_6.h"
#include "../io/lineoutput.h" /// normalize_end_line()

namespace LMT {

/// remplace dans str les caractères c par subs.
void replace_char( std::string& str, char c, char subs) {
    size_t i = 0,i2;
    while ( (i2 = str.find( c, i ) ) != std::string::npos ) {
        str[ i2 ] = subs;
        i = i2;
    }
}

/*!
    lorsque une ligne d'un fichier texte DOS est lue, il reste le caractère CR Carriage Return ( code ASCII 13 ) qui gène la récupèration des nombres de la ligne. Il est donc nécessaire de le retirer. On supprime aussi les espaces pour une meilleure lecture.
*/
// void normalize_end_line( std::string& str ) {
//     size_t pos = str.size() - 1;
//     while( ( pos >= 1 ) and ( ( str[ pos ] == 13 ) or ( str[ pos ] == ' ' ) ) ) pos--;
//     str.resize( pos + 1 );
// }

/// retourne le nombre de caractères c à partir de la position start
unsigned compter_caractere( const std::string& s, char c, int start = 0 ) {

    unsigned l,co,p ;

    l = s.size() ;
    co = 0 ;
    for( p = start ; p < l; p++ )
        if (s[ p ] == c ) co++ ;
    return co;
}

/*!
  cette fonction récupère la valeur v d'une expression de la forme param1=v ou param2=v de la chaine str sous forme d'une chaine de caractère.
 */
std::string value( const std::string& str, const char* param1, const char* param2, const char* descripteur = " ,\n" ) {
    std::string stmp;
    size_t pos, pos2;
    const char* pchar;

    if ( ( pos = str.find( param1 ) ) != std::string::npos ) {
        pos += strlen( param1 );
        pchar = strpbrk( str.c_str() + pos, descripteur );
        if ( pchar ) pos2 = pchar - str.c_str(); else pos2 = str.size();
        stmp = str.substr( pos, pos2 - pos );
        return stmp;
    } else if ( ( pos = str.find( param2 ) ) != std::string::npos ) {
        pos += strlen( param2 );
        pchar = strpbrk( str.c_str() + pos, descripteur );
        if ( pchar ) pos2 = pchar - str.c_str(); else pos2 = str.size();
        stmp = str.substr( pos, pos2 - pos );
        return stmp;
    }
    return stmp;
}

/*!
    Objectif :
        Cette fonction sert à sauter le corps d'un conteneur correspondant à un mot-clé de ABAQUS ( e.g. STEP ).
    
    Paramètres :
        * is est le descripteur du fichier ABAQUS,
        * next recevra la ligne qui contient la chaîne "descripteur",
        * descripteur est la chaîne de caractères qui sert d'arrêt au saut. Par exemple si on veut s'arrêter à "*END STEP", on mettra cette chaîne.
    Retour:
        Elle renvoie vrai si la lecture s'est bien passée et faux sinon.
*/
bool jump( std::ifstream& is, std::string &next, const char* descripteur ) {
    std::string str;
    
    next.clear();
    while( true ) {
        str.clear();
        getline( is,str );
        if ( !is.good() )
            return false;
        normalize_end_line( str );
        
        if ( str.find( descripteur ) != std::string::npos ) {
            next = str;
            break;
        }
    }

    return true;
}

typedef enum {
    ELEMENT_LMT_UNDETERMINED = -2,
    ELEMENT_LMT_UNKNOWN = -1,
    ELEMENT_LMT_NODAL_ELEMENT = 0,
    ELEMENT_LMT_BAR = 1,
    ELEMENT_LMT_TRIANGLE = 2,
    ELEMENT_LMT_QUAD = 3,
    ELEMENT_LMT_TETRA = 4,
    ELEMENT_LMT_HEXA = 5,
    ELEMENT_LMT_PRISM = 6,
    ELEMENT_LMT_TETRA_10 = 7,
    ELEMENT_LMT_TRIANGLE_6 = 8
} Element_LMT_ID;

const char* name_element_LMT( Element_LMT_ID iel ) {
    switch( iel ) {
        case ELEMENT_LMT_UNDETERMINED : return "undetermined element";
        case ELEMENT_LMT_UNKNOWN : return "unknown element";
        case ELEMENT_LMT_NODAL_ELEMENT : return "NodalElement";
        case ELEMENT_LMT_BAR : return "Bar";
        case ELEMENT_LMT_TRIANGLE : return "Triangle";
        case ELEMENT_LMT_QUAD : return "Quad";
        case ELEMENT_LMT_TETRA : return "Tetra";
        case ELEMENT_LMT_HEXA : return "Hexa";
        case ELEMENT_LMT_PRISM : return "Prism";
        case ELEMENT_LMT_TETRA_10 : return "Tetra_10";
        case ELEMENT_LMT_TRIANGLE_6 : return "Triangle_6";
        default : return "element TODO";        
    }
}

template <class NE >
struct El_LMT {
    static const Element_LMT_ID res = ELEMENT_LMT_UNDETERMINED;
};

template<>
struct El_LMT<Tetra_10> {
    static const Element_LMT_ID res = ELEMENT_LMT_TETRA_10;
};

template<>
struct El_LMT<Triangle_6> {
    static const Element_LMT_ID res = ELEMENT_LMT_TRIANGLE_6;
};

template<>
struct El_LMT<Tetra> {
    static const Element_LMT_ID res = ELEMENT_LMT_TETRA;
};

template<>
struct El_LMT<Hexa> {
    static const Element_LMT_ID res = ELEMENT_LMT_HEXA;
};


template<class EA, class Pvec >
struct CmpEl {

    template<class TE, class TOL >
    void operator() ( TE &e , TOL tol ) {
        if ( El_LMT<typename TE::NameElem>::res == element_LMT ) {
        
            if ( ea )
                return;

            if ( length( c - center( e ) ) < tol )
                ea = &e;
            
        } else {
            std::cerr << "Error CmpEl() : bad match between LMT element and ABAQUS element" << std::endl;
        }
    }

    Pvec c;
    Element_LMT_ID element_LMT;
    EA* ea;
};


/*!
    Objectif :
        récupèrer le maximum d'information d'un fichier INP ( ABAQUS ).
         
    Utilisation :
        \code C/C++
            TM mesh;
            ReaderINP<TM> readerINP( mesh, "file.inp" );
            display_mesh( mesh );


    Actuellement le lecteur INP ne connaît que les types : 
        C3D8R   <=> Hexa
        C3D8I   <=> Hexa
        C3D8    <=> Hexa
        C3D4    <=> Tetra
        C3D10   <=> Tetra_10
        S3R     <=> Triangle
        S3      <=> Triangle
        S4R     <=> Quad
        R3D4    <=> Quad
        M3D4    <=> Quad
        R3D3    <=> Triangle
        B31     <=> Bar
        SpringA <=> Bar
        SPRING1 <=> Bar
        CONN3D2 <=> Bar
        C3D6    <=> Prism
        ROTARYI <=> NodalElement
        MASS    <=> NodalElement
   Pour en ajouter, il faut le faire dans la méthode ElementINP.add_element_at(), et le constructeur de ElementSet.

    doc interne
    
    ReaderINP contient des structures quasi identiques aux structures de INP, comme par exemple Element, Orientation, SolidSection, etc...
    Parmi ces structures, celles jouant le rôle de conteneur comme par exemple ElementSet contiennent des tableaux d'entiers, ces entiers correspondant à ceux utilisés par INP pour numéroter les objets. 
    Pour ensuite accéder à l'élément ou le noeud d'indice cet entier, on utilise des map du genre map<int, Object > .
    Plus précisément, ReaderINP contient :
    \code C/C++
        map<int, TNode*> map_num_node;
        map<int, ElementINP > map_num_element;
        map<string, NodeSet*> map_NodeSet;
        map<string, ElementSet*> map_ElementSet;
        map<string, Orientation*> map_Orientation;
        map<string, SolidSection*> map_SolidSection;
        map<string, Material*> map_Material;
        map<string, Contact_Pair*> map_Conctact_Pair;
        map<string, Surface*> map_Surface;
        map<string, Boundary*> map_Boundary;
        map<string, Transform*> map_Transform;
*/
template<class TM> 
struct ReaderINP {
    typedef typename TM::Pvec Pvec;
    typedef Vec<double, 3 > PvecInp;
    typedef typename TM::TNode TNode;
    typedef typename TM::TNode::T T;
    typedef typename TM::MA::EA EA;
    static const unsigned dim = TM::dim;
    
    typedef enum {
        STATUS_START                = -1,
        STATUS_IGNORED              = 0,
        STATUS_NODE                 = 1,
        STATUS_ELEMENT              = 2,
        STATUS_NSET                 = 3,
        STATUS_ELSET                = 4,
        STATUS_ORIENTATION          = 5,
        STATUS_SOLID_SECTION        = 6,
        STATUS_MATERIAL             = 7,
        STATUS_STEP                 = 8,
        STATUS_CONTACT_PAIR         = 9,
//         STATUS_SURFACE_INTERACTION  = 10,
        STATUS_SURFACE              = 11,
        STATUS_COMMENT              = 12,
        STATUS_BOUNDARY             = 13,
        STATUS_TRANSFORM            = 14
        //STATUS_PART                 = 15
    } Status_ID;
    
   
    /// double : nécessaire et suffisant ;
    /// cet objet ne sert qu' à enregistrer la position d'un noeud
    struct NodeInp {
        NodeInp() : index_LMTpp( -1 ) {}
        NodeInp( const Vec<double> &posi ) : pos( posi ) {}
        
        /// malheureusement le conversion est doublée par un constructeur très générique...
        template< class T, int _s >
        operator Vec<T,_s>() const {
            Vec<T,_s> ret;
            if ( ret.size() != pos.size() )
                std::cerr << "WARNING ReaderINP : error to convert the position of node." << std::endl;
            for( unsigned i = 0; i < ret.size(); ++i ) 
                ret[ i ] = pos[ i ];
            return ret;
        }
        
        template< class T, int _s >
        void copy_to( Vec<T,_s> &v ) const {
            if ( v.size() != pos.size() )
                std::cerr << "WARNING ReaderINP : error to convert the position of node." << std::endl;
            for( unsigned i = 0; i < v.size(); ++i ) 
                v[ i ] = pos[ i ];
        }
        
        PvecInp pos; /// un maillage ABAQUS est toujours défini dans l'espace
        int index_LMTpp; /// index du noeud du maillage LMTpp construit par le constructeur de \a ReaderINP 
    };
    
    typedef std::map<unsigned, NodeInp> Map_num_node;
    
    /*! 
        Classe représentant un élément INP.
        
        Rem : j' ai des soucis pour me débarasser de l'attribut element_LMT et faire de l'héritage à la place. 
    */
    struct ElementINP {
        ElementINP() : ptrEA( NULL ) { }
        ElementINP( Element_LMT_ID id_el, EA* p, Vec<unsigned> &lnode ) : element_LMT( id_el ), ptrEA( p ), list_node( lnode ) {}

        /*!
            Cette méthode ajoute à "mesh" l'élément concerné. 
            Pour des raisons de performance on a besoin du conteneur "match_inode_inp_lmtpp" qui fait la correspondance entre l'indice du noeud dans le fichier Inp d'Abaqus et l'indice du noeud de "mesh" dans la liste node_list. Son utilisé est d'éviter les doublons de noeuds dans le maillage LMT++ sans utiliser leurs coordonnées. 
            On a choisi un map et pas un simple vector ou Vec car la méthode find() de map est en complexité O( ln( N ) ) et non O( N ) comme les conteneurs précédents.
        */
        template<class TMESH>
        typename TMESH::MA::EA* add_element_at( TMESH &mesh, std::map< unsigned, unsigned > &match_inode_inp_lmtpp, Map_num_node &mapNode ) const {
            //typedef typename TM::MA::EA EALocal;
            typedef typename TMESH::TNode TNodeLocal;
            typedef typename TMESH::Pvec PvecLocal;
            typedef typename TMESH::TNode::T TLocal;
            
            Vec< TNodeLocal* > vnlocal;
            PvecLocal v;
            typename std::map< unsigned, unsigned >::iterator it;
            
            vnlocal.resize( list_node.size() );

            for( unsigned j = 0; j < list_node.size(); j++ ) {
                
                it = match_inode_inp_lmtpp.find( list_node[ j ] );
                if ( it != match_inode_inp_lmtpp.end() ) {
                    vnlocal[ j ] = &mesh.node_list[ it->second ];    
                } else {
                    mapNode[ list_node[ j ] ].copy_to( v );
                    vnlocal[ j ] = mesh.add_node( v );
                    match_inode_inp_lmtpp[ list_node[ j ] ] = match_inode_inp_lmtpp.size() - 1; 
                }
            }

            switch( element_LMT ) {
                case ELEMENT_LMT_TETRA :
                    permutation_if_jac_neg ( Tetra(), vnlocal.ptr() );
                    return mesh.add_element( Tetra(), DefaultBehavior(), vnlocal.ptr() );  
                                  
                case ELEMENT_LMT_HEXA :
                    permutation_if_jac_neg ( Hexa(), vnlocal.ptr() );
                    return mesh.add_element( Hexa(), DefaultBehavior(), vnlocal.ptr() );     
                               
                case ELEMENT_LMT_TRIANGLE :
                    permutation_if_jac_neg ( Triangle(), vnlocal.ptr() );
                    return mesh.add_element( Triangle(),DefaultBehavior(), vnlocal.ptr() );  
                              
                case ELEMENT_LMT_QUAD :
                    permutation_if_jac_neg ( Quad(), vnlocal.ptr() );
                    return mesh.add_element( Quad(),DefaultBehavior(), vnlocal.ptr() );                
                
                case ELEMENT_LMT_TETRA_10 :
                    permutation_if_jac_neg ( Tetra_10(), vnlocal.ptr() );
                    return mesh.add_element( Tetra_10(),DefaultBehavior(), vnlocal.ptr() );
                
                case ELEMENT_LMT_BAR :
                    return mesh.add_element( Bar(),DefaultBehavior(), vnlocal.ptr() );
                    
                case ELEMENT_LMT_NODAL_ELEMENT :
                    return mesh.add_element( NodalElement(),DefaultBehavior(), vnlocal.ptr() ); 
                    
                default :
                    std::cerr << "WARNING ReaderINP : the element does not append by ElementINP. TODO" << std::endl; 
                    return NULL;
            }
        }
        
        /*!
            cette méthode retourne un ElementINP correspondant à la surface d' identifiant idFace de l'élément courant. 
            Référence ABAQUS :
                2.3.2 Defining element-based surfaces
                    paragraphe : Creating surface facets by specifying solid, continuum shell, and cohesive element faces
                22.1.4 Three-dimensional solid element library
        */
        ElementINP get_facet( unsigned idFace ) const {
        
            ElementINP res;

            if ( element_LMT == ELEMENT_LMT_HEXA ) {
                switch( idFace ) {
                    case 1 : 
                        res.list_node.resize( 4 );
                        res.list_node[ 0 ] = list_node[ 0 ];
                        res.list_node[ 1 ] = list_node[ 1 ];
                        res.list_node[ 2 ] = list_node[ 2 ];
                        res.list_node[ 3 ] = list_node[ 3 ];
                        res.element_LMT = ELEMENT_LMT_QUAD;
                        break;
                    case 2 : 
                        res.list_node.resize( 4 );
                        res.list_node[ 0 ] = list_node[ 4 ];
                        res.list_node[ 1 ] = list_node[ 5 ];
                        res.list_node[ 2 ] = list_node[ 6 ];
                        res.list_node[ 3 ] = list_node[ 7 ];
                        res.element_LMT = ELEMENT_LMT_QUAD;
                        break;
                    case 3 : 
                        res.list_node.resize( 4 );
                        res.list_node[ 0 ] = list_node[ 0 ];
                        res.list_node[ 1 ] = list_node[ 1 ];
                        res.list_node[ 2 ] = list_node[ 5 ];
                        res.list_node[ 3 ] = list_node[ 4 ];
                        res.element_LMT = ELEMENT_LMT_QUAD;
                        break;
                    case 4 :
                        res.list_node.resize( 4 );
                        res.list_node[ 0 ] = list_node[ 1 ];
                        res.list_node[ 1 ] = list_node[ 2 ];
                        res.list_node[ 2 ] = list_node[ 6 ];
                        res.list_node[ 3 ] = list_node[ 5 ];
                        res.element_LMT = ELEMENT_LMT_QUAD;
                        break;
                    case 5 : 
                        res.list_node.resize( 4 );
                        res.list_node[ 0 ] = list_node[ 2 ];
                        res.list_node[ 1 ] = list_node[ 3 ];
                        res.list_node[ 2 ] = list_node[ 7 ];
                        res.list_node[ 3 ] = list_node[ 6 ];
                        res.element_LMT = ELEMENT_LMT_QUAD;
                        break;
                    case 6 :
                        res.list_node.resize( 4 );
                        res.list_node[ 0 ] = list_node[ 0 ];
                        res.list_node[ 1 ] = list_node[ 3 ];
                        res.list_node[ 2 ] = list_node[ 7 ];
                        res.list_node[ 3 ] = list_node[ 4 ]; 
                        res.element_LMT = ELEMENT_LMT_QUAD;
                        break;
                    default : 
                        std::cerr << "WARNING ReaderINP : bad id face of Hexa" << std::endl;
                        res.element_LMT = ELEMENT_LMT_UNDETERMINED;                        
                }
                
                return res;
            }
            
            if ( element_LMT == ELEMENT_LMT_TETRA_10 ) {
                switch( idFace ) {
                    case 1 :
                        res.list_node.resize( 6 );
                        res.list_node[ 0 ] = list_node[ 0 ];
                        res.list_node[ 1 ] = list_node[ 1 ];
                        res.list_node[ 2 ] = list_node[ 2 ];
                        res.list_node[ 3 ] = list_node[ 4 ];
                        res.list_node[ 4 ] = list_node[ 5 ];
                        res.list_node[ 5 ] = list_node[ 6 ];
                        res.element_LMT = ELEMENT_LMT_TRIANGLE_6;
                        break;
                    case 2 :
                        res.list_node.resize( 6 );
                        res.list_node[ 0 ] = list_node[ 0 ];
                        res.list_node[ 1 ] = list_node[ 1 ];
                        res.list_node[ 2 ] = list_node[ 3 ];
                        res.list_node[ 3 ] = list_node[ 4 ];
                        res.list_node[ 4 ] = list_node[ 8 ];
                        res.list_node[ 5 ] = list_node[ 7 ];
                        res.element_LMT = ELEMENT_LMT_TRIANGLE_6;
                        break;
                    case 3 :
                        res.list_node.resize( 6 );
                        res.list_node[ 0 ] = list_node[ 1 ];
                        res.list_node[ 1 ] = list_node[ 2 ];
                        res.list_node[ 2 ] = list_node[ 3 ];
                        res.list_node[ 3 ] = list_node[ 5 ];
                        res.list_node[ 4 ] = list_node[ 9 ];
                        res.list_node[ 5 ] = list_node[ 8 ];
                        res.element_LMT = ELEMENT_LMT_TRIANGLE_6;
                        break;
                    case 4 :
                        res.list_node.resize( 6 );
                        res.list_node[ 0 ] = list_node[ 0 ];
                        res.list_node[ 1 ] = list_node[ 2 ];
                        res.list_node[ 2 ] = list_node[ 3 ];
                        res.list_node[ 3 ] = list_node[ 6 ];
                        res.list_node[ 4 ] = list_node[ 9 ];
                        res.list_node[ 5 ] = list_node[ 7 ];
                        res.element_LMT = ELEMENT_LMT_TRIANGLE_6;
                        break;
                    default:
                        std::cerr << "WARNING ReaderINP : bad id face of Hexa" << std::endl;
                        res.element_LMT = ELEMENT_LMT_UNDETERMINED;    
                }
                            
                return res;
            }
            
            std::cerr << "WARNING ReaderINP : the surface element is unknown by ElementINP. TODO" << std::endl;
            res.element_LMT = ELEMENT_LMT_UNDETERMINED;
            return res;
        }
        
        template<class TMESH>
        void add_surface_element_at( TMESH &mesh, std::map< unsigned, unsigned > &match_inode_inp_lmtpp, Map_num_node &mapNode, unsigned idFace ) const {
            typedef typename TMESH::TNode TNodeLocal;
            typedef typename TMESH::Pvec PvecLocal;
            Vec< TNodeLocal* > vnlocal;
            PvecLocal v;
            typename std::map< unsigned, unsigned >::iterator it;
            
            ElementINP e = get_facet( idFace );
            
            if ( e.element_LMT < 0 ) {
                std::cerr << "Error ReaderINP : ElementINP.add_surface_element_at() bugs" << std::endl;
                return; 
            }
            
            vnlocal.resize( e.list_node.size() );
            for( unsigned j = 0; j < e.list_node.size(); ++j ) {
                      
                it = match_inode_inp_lmtpp.find( e.list_node[ j ] );  /// le noeud est-il déjà dans le "mesh" ?
                if ( it != match_inode_inp_lmtpp.end() ) {
                    vnlocal[ j ] = &mesh.node_list[ it->second ];    
                } else {
                    mapNode[ e.list_node[ j ] ].copy_to( v );
                    vnlocal[ j ] = mesh.add_node( v );
                    match_inode_inp_lmtpp[ e.list_node[ j ] ] = match_inode_inp_lmtpp.size() - 1; 
                }
            }
            
            if ( e.element_LMT == ELEMENT_LMT_QUAD ) {
                //permutation_if_jac_neg ( Quad(), vnlocal.ptr() );
                mesh.add_element( Quad(), DefaultBehavior(), vnlocal.ptr() );
                return;
            }
            
            if ( e.element_LMT == ELEMENT_LMT_TRIANGLE_6 ) {
                /// permutation_if_jac_neg() pose problème
                //permutation_if_jac_neg ( Triangle_6(), vnlocal.ptr() );
                mesh.add_element( Triangle_6(), DefaultBehavior(), vnlocal.ptr() );
                return;
            }
            
            std::cerr << "WARNING ReaderINP : the surface element does not append by ElementINP. TODO" << std::endl;
        }
        
        Element_LMT_ID element_LMT; /// nom LMT++ de l'élément ( e.g. Triangle, Hexa )
        EA* ptrEA; /// pointeur sur l'élément du maillage entier
        Vec<unsigned> list_node; /// la valeur de l'entier correspondant à l'entrée de Map_num_nodeInp de ReaderINP : i.e. l'index du noeud dans le fichier INP
    };

    typedef std::map<unsigned, ElementINP > Map_num_element;
    
    /// renvoie le centre de l'élément
    PvecInp center( const ElementINP &e ) {
        PvecInp c = 0;
        
        if ( e.element_LMT != ELEMENT_LMT_TRIANGLE_6 ) {
            for( unsigned i = 0; i < e.list_node.size(); ++i )
                c += map_num_node[ e.list_node[ i ] ].pos;
            return c / ( e.list_node.size() + ( e.list_node.size() == 0 ) );
        } else {
            /// cf la fonction center() de Triangle_6
            return ( map_num_node[ e.list_node[ 0 ] ].pos + map_num_node[ e.list_node[ 1 ] ].pos + map_num_node[ e.list_node[ 2 ] ].pos ) / 3;
        }
    }
    
    /*!
    Ce code souhaite représenter la méthode de stockage des identifiants entiers des noeuds ou des éléments dans Abaqus.
    Dans le format Inp de Abaqus, un Elset ( ou un NSet ) peut contenir soit :
        * une liste d'indices toute simple soit, 
        * une liste de triplets d'entiers  start, end, step qui signifie que le Elset contient tous les indices de la forme start + i * step où i parcourt les entiers positifs ou nul tout en vérifiant start + i * step <= end ( attention le end est toujours compris pour un step égal à un ).    
    */
    template<class _TI, class _TDATA>
    struct ClusterList {
        typedef _TI TI;
        typedef _TDATA TDATA;
        
        struct iterator {
            TI i, h;
            const ClusterList *p;
            unsigned index_data;
            
            iterator( const ClusterList* pa = NULL ) : i( 0 ), h( 0 ), p( pa ), index_data( 0 ) {}
            
            void operator++() {            
                if ( p->isGenerate ) {
                    TI id = p->ci[ 3 * i ] + ( h + 1 ) * p->ci[ 3 * i + 2 ];
                    if ( id <= p->ci[ 3 * i + 1 ] )
                        ++h;
                    else {
                        ++i; h = 0;
                    }
                } else {
                    ++i;
                }
                index_data++;
            }
            
            TI operator*() const {
                if ( p->isGenerate )
                    return p->ci[ 3 * i ] + h * p->ci[ 3 * i + 2 ];  
                else
                    return p->ci[ i ];            
            }
            
            bool operator!=( const iterator &it ) const {
                return ( it.p != p ) or ( it.i != i ) or ( it.h != h );  
            }
            
            void display() const {
                std::cout << "p = " << p << " i = " << i << " h = " << h << std::endl;
            }
            
            TDATA get_data() const { return p->data[ index_data ]; }
            
            void get_data( TDATA &d ) { d = p->data[ index_data ]; }
        };
        
        iterator begin() const {
            iterator iter( this );
            iter.i = 0;
            iter.h = 0; 
            iter.index_data  = 0;
            return iter;
        }
    
        iterator end() const {
            iterator iter( this );
            if ( isGenerate )
                iter.i = ci.size() / 3;
                
            else
                iter.i = ci.size();
            return iter;
        }
        
        unsigned nb_elements() const {
            unsigned sum = 0;
            if ( isGenerate ) {
                for( unsigned i = 0; i < ci.size(); i += 3 ) {
                    sum += ( 1 + ci[ i + 1 ] - ci[ i ]) / ci[ i + 2 ];
                }
                return sum ; 
            } else {
                return ci.size();
            }
        }
       
        TDATA get_data() const { return data[ index ]; }
        void get_data( TDATA &d ) { d = data[ index ]; }
        
        
        bool isGenerate;
        Vec<TI> ci;
        Vec<TDATA> data;
    };
    
    template<class _TI>
    struct ClusterList<_TI, void> {
        typedef _TI TI;
        
        struct iterator {
            TI i, h;
            const ClusterList *p;
            
            iterator( const ClusterList* pa = NULL ) : i( 0 ), h( 0 ), p( pa ) {}
            
            void operator++() {            
                if ( p->isGenerate ) {
                    TI id = p->ci[ 3 * i ] + ( h + 1 ) * p->ci[ 3 * i + 2 ];
                    if ( id <= p->ci[ 3 * i + 1 ] )
                        ++h;
                    else {
                        ++i; h = 0;
                    }
                } else {
                    ++i;
                }
            }
            
            TI operator*() const {
                if ( p->isGenerate )
                    return p->ci[ 3 * i ] + h * p->ci[ 3 * i + 2 ];  
                else
                    return p->ci[ i ];            
            }
            
            bool operator!=( const iterator &it ) const {
                return ( it.p != p ) or ( it.i != i ) or ( it.h != h );  
            }
            
            void display() const {
                std::cout << "p = " << p << " i = " << i << " h = " << h << std::endl;
            }
        };
        
        iterator begin() const { 
            iterator iter( this );
            iter.i = 0;
            iter.h = 0; 
            return iter;
        }
    
        iterator end() const {
            iterator iter( this );
            if ( isGenerate )
                iter.i = ci.size() / 3;
                
            else
                iter.i = ci.size();
            return iter;
        }
        
        unsigned nb_elements() const {
            unsigned sum = 0;
            if ( isGenerate ) {
                for( unsigned i = 0; i < ci.size(); i += 3 ) {
                    sum += ( 1 + ci[ i + 1 ] - ci[ i ]) / ci[ i + 2 ];
                }
                return sum ; 
            } else {
                return ci.size();
            }
        }
        
        bool isGenerate;
        Vec<TI> ci;
    };
    

    struct NodeSet : public ClusterList<unsigned, void> {
        NodeSet() { this->isGenerate = false; withCoordinate = true;}
        NodeSet( const std::string& str ) {
            if ((str.find("GENERATE") != std::string::npos) or (str.find("generate") != std::string::npos))
                this->isGenerate = true;
            else
                this->isGenerate = false;
            withCoordinate = false;
        }
        
        void read( TM &m, std::string& str, Map_num_node &map_num_nodeInp ) {
            double p;
            int number;
            NodeInp node;

            replace_char( str, ',', ' ' );
            normalize_end_line( str );
            std::istringstream iss( str );
            if ( withCoordinate ) {
                iss >> number;
                /// lecture des coordonnées
                unsigned cpt = 0;
                while ( not( iss.eof() ) ) {
                    iss >> p;
//                     if ( iss.eof() )
//                         break;
                    if ( cpt < 3 )
                        node.pos[ cpt ] = p;
                    else
                        std::cerr << "Error ReaderINP : dimension too large" << std::endl;
                    cpt++;
                }
                
                if ( cpt < 3 )
                    std::cerr << "Error ReaderINP : bad dimension" << std::endl;
                    
                map_num_nodeInp[ number ] = node;
                this->ci.push_back( number );
            } else {
                //PRINT("+++++++++++++++++++++++++++++++++++++++++++++++++++++++");
                //std::cout << "<<<|" << str << "|>>>" << std::endl;
                while( not( iss.eof() ) ) {
                    iss >> number;
//                     PRINT( number );
//                     if ( iss.eof() )
//                         break;
                    //PRINT( number );
                    this->ci.push_back( number );
                }
            }
        }
        
        void display() const {
            std::cout << " isGenerate = " << this->isGenerate << std::endl;
            std::cout << " withCoordinate = " << withCoordinate << std::endl;
            typename NodeSet::iterator it;
            for( it = this->begin(); it != this->end(); ++it )
                std::cout << *it << " ";
            std::cout << std::endl;
        }
        
        bool withCoordinate;
    };
    
    struct ElementSet : public ClusterList<unsigned, void> {
        ElementSet( const std::string& str ) {
            if ((str.find( "GENERATE" ) != std::string::npos) or (str.find( "generate" ) != std::string::npos))
                this->isGenerate = true;
            else
                this->isGenerate = false;
 
            element_INP = value( str, "TYPE=", "type=" );
            element_LMT = ELEMENT_LMT_UNDETERMINED;
            nb_nodes = 0;
            //PRINT( element_INP );
            //PRINT( this->isGenerate );
            /// ref : liste des éléments Abaqus http://muscadet.lmt.ens-cachan.fr:2080/v6.7/books/usb/default.htm
            /// page : Output Variable and Element Indexes/Standard ElementSet Index
            if ( element_INP.size() ) {
                if ( element_INP == "C3D8R"   ) { element_LMT = ELEMENT_LMT_HEXA; nb_nodes = 8; return; }
                if ( element_INP == "C3D8I"   ) { element_LMT = ELEMENT_LMT_HEXA; nb_nodes = 8; return; }
                if ( element_INP == "C3D8"    ) { element_LMT = ELEMENT_LMT_HEXA; nb_nodes = 8; return; }
                if ( element_INP == "C3D4"    ) { element_LMT = ELEMENT_LMT_TETRA; nb_nodes = 4; return; }
                if ( element_INP == "C3D10"   ) { element_LMT = ELEMENT_LMT_TETRA_10; nb_nodes = 10; return; }
                if ( element_INP == "S3R"     ) { element_LMT = ELEMENT_LMT_TRIANGLE; nb_nodes = 3; return; }
                if ( element_INP == "S3"      ) { element_LMT = ELEMENT_LMT_TRIANGLE; nb_nodes = 3; return; }
                if ( element_INP == "S4R"     ) { element_LMT = ELEMENT_LMT_QUAD; nb_nodes = 4; return; }
                if ( element_INP == "R3D4"    ) { element_LMT = ELEMENT_LMT_QUAD; nb_nodes = 4; return; } /// dans R^3
                if ( element_INP == "M3D4"    ) { element_LMT = ELEMENT_LMT_QUAD; nb_nodes = 4; return; } /// dans R^3
                if ( element_INP == "R3D3"    ) { element_LMT = ELEMENT_LMT_TRIANGLE; nb_nodes = 3; return; } /// dans R^3
                if ( element_INP == "B31"     ) { element_LMT = ELEMENT_LMT_BAR; nb_nodes = 2; return; } /// dans R^3
                if ( element_INP == "SpringA" ) { element_LMT = ELEMENT_LMT_BAR; nb_nodes = 2; return; }
                if ( element_INP == "SPRING1" ) { element_LMT = ELEMENT_LMT_BAR; nb_nodes = 2; return; } /// à vérifier sur un exemple  
                if ( element_INP == "CONN3D2" ) { element_LMT = ELEMENT_LMT_BAR; nb_nodes = 2; return; } 
                if ( element_INP == "C3D6"    ) { element_LMT = ELEMENT_LMT_PRISM; nb_nodes = 6; return; }
                if ( element_INP == "ROTARYI" ) { element_LMT = ELEMENT_LMT_NODAL_ELEMENT; nb_nodes = 1; return; }
                if ( element_INP == "MASS"    ) { element_LMT = ELEMENT_LMT_NODAL_ELEMENT; nb_nodes = 1; return; }
                element_LMT = ELEMENT_LMT_UNKNOWN;
            }
        }
        
        void read( TM                             &m,
                   std::string                    &str, 
                   std::map< unsigned, unsigned > &match_inode_inp_lmtpp, 
                   Map_num_node                   &mapNode, 
                   Map_num_element                &map_num_element ) {
                   
            unsigned number,number2;
            Vec<unsigned> vninp;

            replace_char( str, ',', ' ' );
            std::istringstream s( str );

            if ( this->isGenerate ) {
                while( not( s.eof() ) ) {
                    s >> number;
                    //PRINT( number );
                    this->ci.push_back( number );
                }            
            } else {
                if ( element_LMT >= 0 ) {
                    s >> number;
                    this->ci.push_back( number );
                    vninp.resize( nb_nodes );
                    for ( unsigned i = 0; i < nb_nodes; i++ ) {
                        s >> number2;
                        vninp[ i ] = number2;
                    }
                    map_num_element[ number ] = ElementINP( element_LMT, NULL, vninp );
                    map_num_element[ number ].ptrEA = map_num_element[ number ].add_element_at( m, match_inode_inp_lmtpp, mapNode );
                    //map_num_element[ number ] = ElementINP( element_LMT, std::numeric_limits<unsigned>::max(), vninp );
                } else {
                    while( not( s.eof() ) ) {
                        s >> number;
                        //PRINT( number );
                        this->ci.push_back( number );
                    }
                }
            }
        }
        
        void display() const {
            std::cout << " nombre d'elements = " << this->nb_elements() << std::endl;
            std::cout << " type d'element = " << name_element_LMT( element_LMT ) << std::endl;
            typename ElementSet::iterator it;
            for( it = this->begin(); it != this->end(); ++it )
                std::cout << *it << " ";
            std::cout << std::endl;
        }
        
        unsigned nb_nodes;
        std::string element_INP;
        Element_LMT_ID element_LMT;
    };
    
    /// TINFO = unsigned pour un index de noeud ou un string pour un nom de NodeSet.
    template<class TINFO = unsigned >
    struct BNode {
        BNode() : _constraint( 0 ) {}
    
        /// 0 <-> u_x, 1 <-> u_y, 2 <-> u_z, 3 <-> phi_x, 4 <-> phi_y, 5 <-> phi_z
        void set_constraint( unsigned i ) {
            char mask = 1 << i;
            _constraint |= mask;
        }
        
        bool constraint( unsigned i ) const {
            char mask = 1 << i;
            mask = mask & _constraint;
            mask >>= i;
            return (bool) mask;
        }
    
        TINFO info;
        char _constraint;
        double value; /// je ne sais pas s'il faut une valeur ou une valeur pour chaque contrainte
    };
    
    struct Boundary {
        
        /// lit la fin de la ligne : node or nodeset, 1,,    0.0 à partir de deb et modifie bn en conséquence
        template< class TINFO>
        void read_the_end( std::string& str, size_t deb, BNode<TINFO> &bn ) {
        
            bn.value = std::numeric_limits<double>::quiet_NaN();
            unsigned number, number2;
            char c = str[ deb ];
            if ( isdigit( c ) ) {
                number = c - '0' - 1;
                bn.set_constraint( number );
                deb += 2;
                if ( deb >= str.size() )
                    return;
                if ( str[ deb ] == ',' ) {
                    deb++;
                    if ( deb >= str.size() )
                        return;
                    bn.value = atof( str.c_str() + deb );
                } else {
                    deb++;
                    if ( deb >= str.size() )
                        return;
                    c = str[ deb ];
                    if ( isdigit( c ) ) {
                        number2 = c - '0' -1;
                        for( unsigned i = number + 1; i <= number2; ++i )
                            bn.set_constraint( i );
                    }
                    deb += 2;
                    if ( deb >= str.size() )
                        return;
                    bn.value = atof( str.c_str() + deb );                    
                }
                
            } else {
                if ( strcmp( str.c_str() + deb, "XSYMM" ) == 0 ) {
                    bn.set_constraint( 0 );
                    bn.set_constraint( 4 );
                    bn.set_constraint( 5 );
                    return;
                }
                if ( strcmp( str.c_str() + deb, "YSYMM" ) == 0 ) {
                    bn.set_constraint( 1 );
                    bn.set_constraint( 3 );
                    bn.set_constraint( 5 );
                    return;
                }                
                if ( strcmp( str.c_str() + deb, "ZSYMM" ) == 0 ) {
                    bn.set_constraint( 2 );
                    bn.set_constraint( 3 );
                    bn.set_constraint( 4 );
                    return;
                }
                if ( strcmp( str.c_str() + deb, "ENCASTRE" ) == 0 ) {
                    bn.set_constraint( 1 );
                    bn.set_constraint( 2 );
                    bn.set_constraint( 3 );
                    bn.set_constraint( 4 );
                    bn.set_constraint( 5 );
                    bn.set_constraint( 0 );
                    return;
                }
                if ( strcmp( str.c_str() + deb, "PINNED" ) == 0 ) {
                    bn.set_constraint( 0 );
                    bn.set_constraint( 1 );
                    bn.set_constraint( 2 );
                    return;
                }
                if ( strcmp( str.c_str() + deb, "XASYMM" ) == 0 ) {
                    bn.set_constraint( 1 );
                    bn.set_constraint( 2 );
                    bn.set_constraint( 3 );
                    return;
                }
                if ( strcmp( str.c_str() + deb, "YASYMM" ) == 0 ) {
                    bn.set_constraint( 0 );
                    bn.set_constraint( 2 );
                    bn.set_constraint( 4 );
                    return;
                }                
                if ( strcmp( str.c_str() + deb, "ZASYMM" ) == 0 ) {
                    bn.set_constraint( 0 );
                    bn.set_constraint( 1 );
                    bn.set_constraint( 5 );
                    return;
                }
            }
        }
        
        void read( std::string& str ) {
            std::string stmp;
            //PRINT( str );
            char c = str[ 0 ];
            if ( not( isdigit( c ) ) and ( c != ' ' ) ) { /// name of NodeSet
                size_t pos = str.find( ',' );
                stmp = str.substr( 0, pos );
                unsigned i;
                for( i = 0; i < list_bnodeset.size(); ++i )
                    if ( list_bnodeset[ i ].info == stmp )
                        break;
                if ( i < list_bnodeset.size() ) {
                    read_the_end( str, pos + 2, list_bnodeset[ i ] );
                } else {
                    BNode<std::string> bnodeset;
                    bnodeset.info = str.substr( 0, pos );
                    read_the_end( str, pos + 2, bnodeset );
                    list_bnodeset.push_back( bnodeset );
                }
            } else { /// index of Node
                BNode<> bnode;
                bnode.info = (unsigned ) atoi( str.c_str() );
                size_t pos = str.find( ',' );
                read_the_end( str, pos + 2, bnode );            
                list_bnode.push_back( bnode );
            }
        }
        
        void display() const {
            for( unsigned i = 0; i < list_bnodeset.size(); ++i ) {
                std::cout << "name of node set is " << list_bnodeset[ i ].info << std::endl;
                std::cout << "constraint = ";
                for( unsigned j = 1; j <= 6; ++j ) 
                    std::cout << list_bnodeset[ i ].constraint( j ) << std::endl;
            }
            for( unsigned i = 0; i < list_bnode.size(); ++i ) {
                std::cout << "index INP of node is " << list_bnode[ i ].info << std::endl;
                for( unsigned j = 1; j <= 6; ++j ) 
                    std::cout << list_bnode[ i ].constraint( j ) << std::endl;
            }
            std::cout << std::endl;
        }
        
        Vec<BNode<std::string> > list_bnodeset; /// list_nodeset
        Vec<BNode<> > list_bnode; /// index des noeuds par rapport à l'index INP
    };
    
    struct Orientation {
        Orientation( const std::string& str ) {
            std::string s;

            s = value( str, "SYSTEM=", "system=" );
            if ( ( s.size() == 0 ) or ( s == "R" ) )
                rectangular = true;
            else
                rectangular = false;
        }
        
        void read( std::string& str ) { 
            replace_char( str, ',', ' ' );
            std::istringstream iss( str );
            if ( rectangular ) {
                iss >> v1 >> v2;
            } else
                std::cerr << "WARNING ReaderINP : TODO Orientation::cylindrical " << std::endl;
            
        }
        
        void setProperty( EA* ptrEA ) const {
            if ( ptrEA ) {
                ptrEA->set_field( std::string( "v1" ), v1 );
                ptrEA->set_field( std::string( "v2" ), v2 );
            } else
                std::cerr << "WARNING ReaderINP::Orientation::setProperty() : ptrEA == NULL " << std::endl;
        }
        
        Vec<double, 3 > v1, v2;
        bool rectangular; /// system = rectangular or cylindrical
    };
    
    struct Transform {
    
        typedef enum {
            COORDINATE_RECTANGULAR_CARTESIAN = 0,
            COORDINATE_CYLINDRICAL           = 1,
            COORDINATE_SPHERICAL             = 2
        } TYPE_COORDINATE_ID;
    
        Transform( const std::string& str ) {
            std::string s;

            s = value( str, "TYPE=", "Type=" );
            type_coordinate = COORDINATE_RECTANGULAR_CARTESIAN;
            if ( s != "R" )
                std::cerr << "WARNING ReaderINP::Transform : TODO coordinate cylindrical and spherical" << std::endl;
        }
        
        void read( std::string& str ) { 
            replace_char( str, ',', ' ' );
            std::istringstream iss( str );
            switch( type_coordinate ) {
                case COORDINATE_RECTANGULAR_CARTESIAN : iss >> v1 >> v2; break;
                case COORDINATE_CYLINDRICAL : case COORDINATE_SPHERICAL : 
                    std::cerr << "WARNING ReaderINP::Transform.read() : TODO coordinate cylindrical and spherical" << std::endl;
                    break;
                default :
                    std::cerr << "WARNING ReaderINP::Transform.read() : unknown coordinate" << std::endl;
            }
            A.col( 0 ) = v1;
            A.col( 1 ) = v2;
            A.col( 2 ) = vect_prod( v1, v2 );
            
        }
        
        void display() const {
             switch( type_coordinate ) {
                case COORDINATE_RECTANGULAR_CARTESIAN : std::cout << " rectangular Cartesian coordinate" << std::endl; break;
                case COORDINATE_CYLINDRICAL           : std::cout << " cylindrical coordinate" << std::endl; break;
                case COORDINATE_SPHERICAL             : std::cout << " spherical coordinate" << std::endl; break;
                default :
                    std::cerr << "WARNING ReaderINP::Transform.display() : unknown coordinate" << std::endl;
            }
            std::cout << " v1 = " << v1 << std::endl;
            std::cout << " v2 = " << v2 << std::endl;
            std::cout << " matrix of transformation = " << std::endl;
            PRINTN( A );
        }
        
        Vec<double, 3 > v1, v2;
        Mat< double, Gen<3,3> > A;
        TYPE_COORDINATE_ID type_coordinate;
    };    
    
    struct Material_property {
        virtual ~Material_property() {}
        virtual void display() const {}
        virtual void setData( std::string& str ) {
            std::cerr << "WARNING ReaderINP : hum... you use Material_property::setData() " << std::endl;
        }
        virtual void setProperty( EA* pea ) const { 
            std::cerr << "WARNING ReaderINP : hum... you use Material_property::setProperty() " << std::endl;
        } 
    };
    
    struct Elastic_property : public Material_property {
        Elastic_property( const std::string& s ) { type = s;}
        
        virtual void display() const {
            std::cout << " type = " << type << std::endl;
            std::cout << " data = " ;
            for( unsigned i = 0; i < data.size() ;i++ )
                std::cout << data[ i ] << " ";
            std::cout << std::endl;
        }
        
        virtual void setData( std::string& str ) {
            replace_char( str, ',', ' ' );
            std::istringstream iss( str );
            if (type != "ISO") {
                data.resize( 9 );
                for( unsigned i = 0; i < 9; i++ ) 
                    iss >> data[i];
            } else {
                data.resize( 2 );
                for( unsigned i = 0 ; i < 2 ; i++ ) 
                    iss >> data[i];
            }
        }
        
        virtual void setProperty( EA* pea ) const { 
            if (type == "ISO") {
                pea->set_field( std::string( "elastic_modulus_1" ), data[ 0 ] );
                pea->set_field( std::string( "elastic_modulus_2" ), data[ 0 ] );
                pea->set_field( std::string( "elastic_modulus_3" ), data[ 0 ] );
                pea->set_field( std::string( "poisson_ratio_12" ), data[ 1 ] );
                pea->set_field( std::string( "poisson_ratio_13" ), data[ 1 ] );
                pea->set_field( std::string( "poisson_ratio_23" ), data[ 1 ] );
                double t = data[ 0 ] / ( 2 * ( 1 + data[ 1 ] ) ); 
                pea->set_field( std::string( "shear_modulus_12" ), t );
                pea->set_field( std::string( "shear_modulus_13" ), t );
                pea->set_field( std::string( "shear_modulus_23" ), t );
            } else {
                pea->set_field( std::string( "elastic_modulus_1" ), data[ 0 ] );
                pea->set_field( std::string( "elastic_modulus_2" ), data[ 1 ] );
                pea->set_field( std::string( "elastic_modulus_3" ), data[ 2 ] );
                pea->set_field( std::string( "poisson_ratio_12" ), data[ 3 ] );
                pea->set_field( std::string( "poisson_ratio_13" ), data[ 4 ] );
                pea->set_field( std::string( "poisson_ratio_23" ), data[ 5 ] );
                pea->set_field( std::string( "shear_modulus_12" ), data[ 6 ] );
                pea->set_field( std::string( "shear_modulus_13" ), data[ 7 ] );
                pea->set_field( std::string( "shear_modulus_23" ), data[ 8 ] );
            }
        }
        
        std::string type;
        Vec<double> data;
    };
    
    struct Material {
        typedef enum {
            OPTION_IGNORED       = 0,
            OPTION_DENSITY       = 1,
            OPTION_ELASTIC       = 2,
            OPTION_COMMENTED     = 3
        } Option_material_ID;
        
        Material() { material_property = NULL; density = 0.;}
        ~Material() { delete material_property; }
        void display() { 
            std::cout << " density =" << density << std::endl;
            std::cout << " property = " << std::endl;
            if ( material_property )
                material_property->display();
            else
                std::cout << " WARNING ReaderINP : not property..." << std::endl;
        }
        std::string parse( std::ifstream& is, std::string &lastCommentMaterial ) {
            std::string str,str2, lastComment;
            unsigned c;
            Option_material_ID ctxte = OPTION_IGNORED;

            while( true ) {
                str.clear();
                getline( is, str );
                normalize_end_line( str );
                if ( !is.good() )
                    break;
                    
                for( c = 0; c < nb_principale_keyword; ++c )
                    if ( str.find( list_principale_keyword[ c ] ) != std::string::npos ) {
                        lastCommentMaterial = lastComment;
                        return str;
                    }
                if ( str.size() == 0 )
                    continue;
                    
                if (str[ 0 ] == '*') {
                    if (str[ 1 ] == '*') { 
                        ctxte = OPTION_COMMENTED;
                        if ( str.size() > 3 )
                            lastComment = str.substr( 3 );
                        continue;
                    }/// c'est un commentaire
                    if ((str.find ( "DENSITY", 1 ) == 1) or (str.find ( "Density", 1 ) == 1)) { 
                        ctxte = OPTION_DENSITY;
                        continue;
                    }
                    if ((str.find ( "ELASTIC", 1 ) == 1) or (str.find ( "Elastic", 1 ) == 1)) { 
                        ctxte = OPTION_ELASTIC; 
                        material_property = new Elastic_property( value( str, "TYPE=", "type=", ",\n" ) );
                        continue; 
                    }
                    ctxte = OPTION_IGNORED; /// na !
                    continue;
                }
                /// utilisation du contexte
                switch( ctxte ) {
                    case OPTION_DENSITY : density = atof( str.c_str() ); break;
                    case OPTION_ELASTIC : 
                        str2.clear();
                        getline( is, str2 );
                        if ( !is.good() )
                            return ""; /// je ne sais pas trop quoi renvoyer...
                        normalize_end_line( str );
                        str += str2;
                        material_property->setData( str );
                        break;
                    case OPTION_IGNORED : case OPTION_COMMENTED : break;
                }
            }
            lastCommentMaterial = lastComment;
            return ""; /// sortie anormale
        }
        
        double density;
        Material_property* material_property;
    };
    
    struct ContactPair {
        void display() const {
            std::cout << " name 1 is \"" << s_surface_1 << "\"" << std::endl;
            std::cout << " name 2 is \"" << s_surface_2 << "\"" << std::endl;
            std::cout << " data   is  |" << s_data << "|" << std::endl;
        }
        
        std::string parse( std::ifstream& is ) {
            std::string str;
            unsigned c;
            
            getline( is, str ); /// lecture des deux surfaces écrits sous la forme nom1, nom2
            normalize_end_line( str );
            const char *pchar = strpbrk( str.c_str(), "," );
            int i;
            if ( pchar ) i = pchar - str.c_str(); else i = str.size();
            s_surface_1 = str.substr( 0, i );
            s_surface_2 = str.substr( i + 2 ); /// + 2 pour sauter le , et l'espace
            if ( !is.good() )
                    return "";
            while( true ) {
                str.clear();
                getline( is, str );
                if ( !is.good() )
                    break;
                normalize_end_line( str );
                for( c = 0; c < nb_keyword; ++c )
                    if ( str.find( list_keyword[ c ] ) != std::string::npos ) {
                        s_data += str + "\n"; /// pas super comme traitement ;-)
                        break;
                    }
                if ( c < nb_keyword ) 
                    continue;   
                for( c = 0; c < nb_principale_keyword; ++c )
                    if ( str.find( list_principale_keyword[ c ] ) != std::string::npos ) {
                        return str;
                    }
                s_data += str + "\n";
            }
            return "";
        }            
    
        std::string s_surface_1, s_surface_2, s_data;
        
        static const unsigned nb_keyword = 4;
        static const char* list_keyword[ nb_keyword ];
    };
    
    /*!
    Ce type sert à représenter une surface INP ( qui sont toutes des polyèdres ).
    Elle est définie par des noeuds ou bien des éléments volumiques avec un identifiant de face
    
    Référence ABAQUS :
        2.3.2 Defining element-based surfaces
        2.3.3 Defining node-based surfaces
    
    */
    struct Surface {
        Surface( const std::string &str ) {
            std::string s_type = value( str, "TYPE=", "type=" ); 
            if ( ( s_type == "ELEMENT" ) or ( s_type == "Element" ) )
                type = 0;
            else 
                type = 1; /// Node
        }
        
        void display() const {
            if ( type == 0 ) { 
                std::cout << "this type is ELEMENT" << std::endl; 
                for( unsigned i = 0; i < indice.size() ; ++i )
                    std::cout << " element " << indice[ i ] << " and id face = " << id_face[ i ] << std::endl;
            } else {
                std::cout << "this type is NODE" << std::endl;
                for( unsigned i = 0; i < indice.size() ; ++i )
                    std::cout << " node " << indice[ i ] << std::endl;
            }         
        }
        
        void read( std::string& str ) {
            unsigned number;
            unsigned p;
            
            char c = str[ 0 ];
            if ( not( isdigit( c ) ) and ( c != ' ' ) ) { /// nom d'elset
                size_t pos = str.find( ',' );
                name_elset.push_back( str.substr( 0, pos ) );
                id_face_of_elset.push_back( str[ pos + 3 ] - '0' );
                return;
            }
            
            replace_char( str, ',', ' ' );
            std::istringstream iss( str );
            iss >> number;
            indice.push_back( number );
            
            if ( type == 0 ) {
                p = str.find( 'S' );
                if ( p != std::string::npos ) 
                    id_face.push_back( str[ p + 1 ] - '0' );
                else {
                    std::cerr << "WARNING ReaderINP : ID face of Surface is unknown" << std::endl;
                    id_face.push_back( 0 );        
                }
            }   
        }
        
        void get_index_element_and_id_face( Vec<unsigned> &ind, Vec<unsigned> &idFace, const std::map< std::string, ElementSet*> &map_elset ) const {
            if ( type == 1 ) {
                std::cerr << "WARNING ReaderINP : get_index_element_and_id_face() has bad type" << std::endl;
                ind.resize( 0 );
                idFace.resize( 0 );
                return;  
            }
            
            ind = indice;
            idFace = id_face;
            
            for( unsigned i = 0; i < name_elset.size(); ++i ) {
                typename std::map< std::string, ElementSet* >::const_iterator it;
                 
                it = map_elset.find( name_elset[ i ] ); 

                if ( it != map_elset.end() ) {
                    unsigned old_size = ind.size();
                    //std::cout << it->first << " nb = " << it->second->nb_elements() << std::endl;
                    ind.resize( ind.size() + it->second->nb_elements() );
                    idFace.resize( idFace.size() + it->second->nb_elements() );
                    typename ElementSet::iterator itel;
                    for( itel = it->second->begin(); itel != it->second->end(); ++itel, ++old_size ) {
                        ind[ old_size ] = *itel;
                        idFace[ old_size ] = id_face_of_elset[ i ];
                    }
                } else
                    std::cerr << "WARNING ReaderINP : get_index_element_and_id_face() unknown elset name" << std::endl;
            }
        }

        Vec<unsigned> indice; /// la value correspond à l'entrée dans la Map_num_nodeInp ou encore Map_num_element : i.e. indice INP.
        Vec<unsigned> id_face; /// la valeur correspond à l'identifiant de face de Abaqus
        Vec<std::string> name_elset;
        Vec<unsigned> id_face_of_elset;
        unsigned type; /// 0 <=> ELEMENT, 1 <=> NODE
    };
    
    struct SolidSection {
        SolidSection( const std::string& str ) { 
            s_material = value( str, "MATERIAL=", "material=" ); 
            s_orientation = value( str, "ORIENTATION=", "orientation=" ); 
            material = NULL;
            orientation = NULL;
        }
        void setData( Material* pma, Orientation* por ) { material = pma; orientation = por; }
        void display() {
            std::cout << " s_material    = ||" << s_material << "||" << std::endl;
            std::cout << " s_orientation = ||" << s_orientation << "||" << std::endl;
            if ( material )
                material->display();
            if ( orientation )
                orientation->display();
        }
        std::string s_material;
        std::string s_orientation;
        Material* material;
        Orientation* orientation;
    };
    
    void update_solidSection() {
        Material* pmat;
        Orientation* por;
        typename std::map< std::string, SolidSection* >::iterator it4;
        for( it4 = map_SolidSection.begin(); it4 != map_SolidSection.end(); it4++ )
            if ( it4->second ) {
                if ( it4->second->s_material.size() )
                    pmat = map_Material[ it4->second->s_material ];
                else
                    pmat = NULL;
                if (it4->second->s_orientation.size())
                    por = map_Orientation[ it4->second->s_orientation ];
                else
                    por = NULL;
                it4->second->setData( pmat, por ) ;
            }
    }
    
    /*!
        Malheureusement la définition de certains bords dépend d'un NodeSet qui est défini après lui d'où la création de cette méthode.
    
    */
//     void update_Boundary() {
//         typename std::map< std::string, Boundary* >::iterator it;
//     
//         for( it = map_Boundary.begin(); it != map_Boundary.end(); it++ )
//             if ( ( it->second ) and ( it->second->name_nodeset.size() ) ) {
//                 /// 
//                 typename std::map< std::string, NodeSet* >::iterator it2 = map_NodeSet.find( it->second->name_nodeset );
//                 if ( it2 != map_NodeSet.end() ) {
//                     *(it->second) = *(it2->second);
//                 } else  
//                     std::cerr << "Error ReaderINP : impossible to find the NodeSet " << it->second->name_nodeset << " of Boundary " << it->first << std::endl;
//             }
//     }
    
    /*!
        Cette méthode sert à définir le type d'élément des Elset.
        Pas vraiment nécessaire.
    */
    void update_Elset() {
        typename std::map< std::string, ElementSet* >::iterator it;
    
        for( it = map_ElementSet.begin(); it != map_ElementSet.end(); it++ )
            if ( ( it->second ) and ( it->second->nb_elements() ) ) {
                ///  
                if ( it->second->element_LMT < 0 ) {
                    typename ElementSet::iterator itel = it->second->begin();
                    it->second->element_LMT = map_num_element[ *itel ].element_LMT;
                }
            } else 
                std::cerr << "Error ReaderINP.update_Elset() : ElementSet vacuum" << std::endl;
    }
    
    /*!
        Application des tansformations aux ensembles de noeuds correspondants.
        WARNING : cette méthode ne peut s'appliquer qu'au maillage principal créé par le constructeur car on va modifier la position de ses noeuds.
        De plus il faut que les "index_LMTpp" soient mis à jour avant son utilisation.
    */
    void update_Transform( TM &m ) {
        typename std::map< std::string, Transform* >::iterator it;
    
        for( it = map_Transform.begin(); it != map_Transform.end(); it++ )
            if ( it->second ) {
                /// 
                typename std::map< std::string, NodeSet* >::iterator it2 = map_NodeSet.find( it->first );
                if ( it2 != map_NodeSet.end() ) {
                    typename NodeSet::iterator it3;
                    for( it3 = it2->second->begin(); it3 != it2->second->end(); ++it3 ) {
                        unsigned i_inp   = *it3;
                        unsigned i_lmtpp = map_num_node[ *it3 ].index_LMTpp;
                        map_num_node[ i_inp ].pos = it->second->A * map_num_node[ i_inp ].pos;
                        m.node_list[ i_lmtpp ].pos = map_num_node[ i_inp ].pos;
                    }
                } else  
                    std::cerr << "Error ReaderINP : impossible to find the NodeSet " << it->first << " of transform " << it->first << std::endl;
            }
    }
    
//     struct Part {
//         Part( const std::string &name ) {
//         
//         }
//         
//         void parse( std::ifstream& is ) {
//         
//         }
//     
//     };
    
    ReaderINP() {}
    
    ReaderINP( TM &m, const char* filename) { parse( m, filename ); }
    
    ~ReaderINP() {
        typename std::map< std::string, ElementSet*>::iterator it;
        for( it = map_ElementSet.begin(); it != map_ElementSet.end(); it++) delete it->second;
        
        typename std::map< std::string, NodeSet*>::iterator it2;
        for( it2 = map_NodeSet.begin(); it2 != map_NodeSet.end(); it2++) delete it2->second;
        
        typename std::map< std::string, Orientation*>::iterator it3;
        for( it3 = map_Orientation.begin(); it3 != map_Orientation.end(); it3++) delete it3->second;
        
        typename std::map< std::string, SolidSection*>::iterator it4;
        for( it4 = map_SolidSection.begin(); it4 != map_SolidSection.end(); it4++) delete it4->second;
        
        typename std::map< std::string, Material*>::iterator it5;
        for( it5 = map_Material.begin(); it5 != map_Material.end(); it5++) delete it5->second;
        
        typename std::map< std::string, ContactPair*>::iterator it6;
        for( it6 = map_ConctactPair.begin(); it6 != map_ConctactPair.end(); it6++) delete it6->second;
        
        typename std::map< std::string, Surface*>::iterator it7;
        for( it7 = map_Surface.begin(); it7 != map_Surface.end(); it7++) delete it7->second;
    
        typename std::map< std::string, Boundary*>::iterator it8;
        for( it8 = map_Boundary.begin(); it8 != map_Boundary.end(); it8++) delete it8->second;
    
        typename std::map< std::string, Transform*>::iterator it9;
        for( it9 = map_Transform.begin(); it9 != map_Transform.end(); it9++) delete it9->second;
    
//         typename std::map< std::string, Part*>::iterator it10;
//         for( it10 = map_Part.begin(); it10 != map_Part.end(); it10++) delete it10->second;
    }
    
    static Status_ID setStatus( const std::string& str ) {
        if (str[1] == '*')                                                                      { return STATUS_COMMENT; }/// c'est un commentaire
        if ((str.find ("NODE PRINT,",1) == 1) or (str.find ("Node Print,",1) == 1))             { return STATUS_IGNORED; }
        if ((str.find ("NODE OUTPUT,",1) == 1) or (str.find ("Node Output,",1 ) == 1))          { return STATUS_IGNORED; }
        if ((str.find ("NODE FILE,",1) == 1) or (str.find ("Node File,",1 ) == 1))              { return STATUS_IGNORED; }
        if ((str.find ("ELEMENT OUTPUT,",1) == 1) or (str.find ("Element Output,",1 ) == 1))    { return STATUS_IGNORED; }
        //if ((str.find ("PART",1) == 1) or (str.find ("Part",1 ) == 1))                        { return STATUS_PART; }
        if (((str.find ("NODE",1) == 1) or (str.find ("Node",1 ) == 1)) and (str.size() == 5 )) { return STATUS_NODE; }
        if ((str.find ("ELEMENT,",1) == 1) or (str.find ("Element,",1) == 1))                   { return STATUS_ELEMENT; }
        if ((str.find ("NSET,",1) == 1) or (str.find ("Nset,",1) == 1))                         { return STATUS_NSET; }
        if ((str.find ("ELSET,",1) == 1)  or (str.find ("Elset,",1) == 1))                      { return STATUS_ELSET; }
        if ((str.find ("ORIENTATION,",1) == 1) or (str.find ("Orientation,",1) == 1))           { return STATUS_ORIENTATION; }
        if ((str.find ("SOLID SECTION,",1) == 1) or (str.find ("Solid Section,",1) == 1))       { return STATUS_SOLID_SECTION; }
        if ((str.find ("MATERIAL,",1) == 1) or (str.find ("Material,",1) == 1))                 { return STATUS_MATERIAL; }
        if ((str.find ("STEP,",1) == 1) or (str.find ("Step,",1) == 1))                         { return STATUS_STEP; }
        if ((str.find ("CONTACT PAIR,",1) == 1) or (str.find ("Contact Pair,",1) == 1))         { return STATUS_CONTACT_PAIR; }
        if ((str.find ("SURFACE,",1) == 1) or (str.find ("Surface,",1) == 1))                   { return STATUS_SURFACE; }
        if ((str.find ("BOUNDARY,",1) == 1) or (str.find ("Boundary,",1) == 1))                 { return STATUS_BOUNDARY; }
        if ((str.find ("TRANSFORM,",1) == 1) or (str.find ("Transform,",1) == 1))               { return STATUS_TRANSFORM; }
        std::cerr << "WARNING ReaderINP : ignored option = " << value( str, "*", "*", ",\n") << std::endl;
        return STATUS_IGNORED; /// option non traitée
    }

  /// il est nécessaire de contrôler la construction de maillage par une instance de \a ReaderINP : cad UNE SEULE instance doit être créée.
  private :
    void parse( TM &m, const char* filename ) {
        std::string str, str2, name, lastComment = "unknown_boundary";
        std::map< unsigned, unsigned > match_inode_inp_lmtpp; /// correspondance entre les index INP et ceux des noeuds du maillage LMTpp
        unsigned n;
        Status_ID ctxte = STATUS_START;
        NodeSet* pns = NULL;
        ElementSet* pes = NULL;
        Orientation* por = NULL;
        SolidSection* pss = NULL;
        Material* pma = NULL;
        ContactPair* pcp = NULL;
        Surface* ps = NULL;
        Boundary* pb = NULL;
        Transform* pt = NULL;
        bool loop = true;

        str.reserve( 2048 );
        str2.reserve( 2048 );
        
        /// ouverture du fichier
        std::ifstream is( filename );
        if ( ! is.is_open() )
            throw std::runtime_error( "opening of file INP has failed." );
        /// état de l'automate
        while ( loop ) {

            if ( ( ctxte != STATUS_MATERIAL ) and ( ctxte != STATUS_CONTACT_PAIR ) and ( ctxte != STATUS_IGNORED ) ) { 
                /// Material et Contact Pair sont vus comme des conteneurs donc ils parsent eux-même le fichier et leur parseur rend la prochaine ligne à lire 
                str.clear();
                getline( is, str );
                if ( !is.good() )
                    break;
                normalize_end_line( str );
                //PRINT( ctxte );
            }
            /// évaluation du contexte
            if ( str.size() == 0 )
                continue;
            if ( str[ 0 ] == '*' ) {
                ctxte = setStatus( str );
                switch( ctxte ) {
                    case STATUS_START         : break;
                    case STATUS_COMMENT       : if ( str.size() > 3 ) lastComment = str.substr( 3 ); break;
                    case STATUS_NODE          : pns  = map_NodeSet[ internal_name[ 0 ] ] = new NodeSet(); break;
                    case STATUS_ELEMENT       : str2 = value( str, "ELSET=", "elset=" );
                                                if ( str2.size() )  
                                                    pes  = map_ElementSet[ str2 ] = new ElementSet( str );
                                                else
                                                    pes  = map_ElementSet[ internal_name[ 1 ] ] = new ElementSet( str );
                                                break;
                    case STATUS_NSET          : pns  = map_NodeSet[ value( str, "NSET=","nset=" ) ] = new NodeSet( str ); break;
                    case STATUS_ELSET         : pes  = map_ElementSet[ value( str, "ELSET=", "elset=" ) ] = new ElementSet( str ); break;
                    case STATUS_ORIENTATION   : por  = map_Orientation[ value( str, "NAME=", "name=" ) ] = new Orientation( str ); break;
                    case STATUS_SOLID_SECTION : pss  = map_SolidSection[ value( str, "ELSET=", "elset=" ) ] = new SolidSection( str ); break;
                    case STATUS_STEP          : break; /// STEP est aussi un "conteneur". TODO
                    case STATUS_MATERIAL      : pma  = map_Material[ value( str, "NAME=", "name=" ) ] = new Material() ; 
                                                str  = pma->parse( is, lastComment );
                                                //pma->display();
                                                break;
                    case STATUS_CONTACT_PAIR  : pcp  = map_ConctactPair[ value( str, "INTERACTION=", "interaction=" ) ] = new ContactPair();
                                                str  = pcp->parse( is );
                                                //pcp->display();
                                                break;
                    case STATUS_SURFACE       : ps = map_Surface[ value( str, "NAME=", "name=" ) ] = new Surface( str ); break;
                    case STATUS_BOUNDARY      : 
                                                { std::string nameBoundary;
                                                  size_t p = lastComment.find( "name" );
                                                  if ( p != std::string::npos ) {
                                                      size_t p2 = lastComment.find( 0x20, p + 6 );
                                                      if ( p2 != std::string::npos )
                                                          nameBoundary = lastComment.substr( p + 6, p2 - p );
                                                      else
                                                          nameBoundary = lastComment.substr( p + 6 );   
                                                  } else 
                                                      nameBoundary = lastComment;
                                                  pb = map_Boundary[ nameBoundary ] = new Boundary(); 
                                                } break;
                    case STATUS_TRANSFORM     : pt = map_Transform[ value( str, "NSET=", "nset=" ) ] = new Transform( str ); break;
                    case STATUS_IGNORED       : loop = jump( is, str, "*" ); /*std::cout << "line --|" << str << "|--" << std::endl;*/ break;  
                }
                continue; /// on revient au début de la boucle.
            }
            
            /// utilisation du contexte
            switch( ctxte ) {
                case STATUS_COMMENT : continue;
                case STATUS_START   : continue;
                case STATUS_NODE    : case STATUS_NSET : pns->read( m, str, map_num_node ); continue;
                case STATUS_ELEMENT : case STATUS_ELSET :
                    /// malheureusement l'info de *ELEMENT est parfois mise sur deux lignes...
                    n = pes->nb_nodes;
                    if ( ( n > 0 ) and ( compter_caractere( str, ',' ) < n ) ) {
                        str2.clear();
                        getline ( is, str2 );
                        if ( !is.good() )
                            break;
                        normalize_end_line( str );
                        str += str2;
                    }
                    pes->read( m, str, match_inode_inp_lmtpp, map_num_node, map_num_element );
                    continue;
                case STATUS_ORIENTATION :
                    /// malheureusement l'info est parfois mise sur deux lignes...
                    if (compter_caractere(str,',') == 5) {
                        str2.clear();
                        getline ( is, str2 );
                        if ( !is.good() )
                            break;
                        normalize_end_line( str );    
                        str += str2;
                    }
                    por->read( str );
                    continue;
                case STATUS_TRANSFORM :
                    pt->read( str );
                    continue;
                case STATUS_SURFACE :
                    ps->read( str );
                    continue;
                case STATUS_BOUNDARY :
                    pb->read( str );
                    continue;
                case STATUS_IGNORED : case STATUS_SOLID_SECTION : case STATUS_MATERIAL : case STATUS_STEP : case STATUS_CONTACT_PAIR : continue;
            }
        }
        
        is.close();
        update_Elset();
        update_solidSection();
        //update_Boundary();
        /// initialisation des index_LMTpp, les index des noeuds du maillage principal "m".
        std::map< unsigned, unsigned >::iterator it;
        for( it = match_inode_inp_lmtpp.begin(); it != match_inode_inp_lmtpp.end(); ++it )  
            map_num_node[ it->first ].index_LMTpp = it->second;
        /// on applique les transformations aux noeuds de "m" ainsi qu'aux noeuds NodeInp.
        update_Transform( m );
        /// mise à jour de la peau du maillage 
        m.update_skin();
    }
    
  public : 
    
    template<class _TNODE> 
    struct EgalityPos {
        bool operator()( _TNODE& n1, _TNODE& n2) const {return n1.pos == n2.pos; }
        
    };
     
    template<class TMESH>
    void create_mesh_by_elset( TMESH &mesh, const std::string &nameElSet ) {
    
        std::map< unsigned, unsigned > match_inode_inp_lmtpp;
        typename std::map< std::string, ElementSet*>::iterator it;

        it = map_ElementSet.find( nameElSet );
        if ( it != map_ElementSet.end() ) {
            ElementSet* elset = it->second;
            typename ElementSet::iterator itel;
            for( itel = elset->begin(); itel != elset->end(); ++itel ) {
                map_num_element[ *itel ].add_element_at( mesh, match_inode_inp_lmtpp, map_num_node );
            }
        } else 
            std::cerr << "WARNING ReaderINP : you wish to create a mesh by unknown ElSet " << nameElSet << std::endl; 
    }
    
    template<class TMESH>
    void create_mesh_by_surface( TMESH &mesh, const std::string &nameSurface ) {
        typename std::map< std::string, Surface* >::const_iterator it;
        std::map< unsigned, unsigned > match_inode_inp_lmtpp;
        
        it = map_Surface.find( nameSurface );
        if ( it != map_Surface.end() ) {
            if ( it->second->type == 0 ) { /// ELEMENTS-SURFACE
                Vec<unsigned> indice;
                Vec<unsigned> idFace;
                it->second->get_index_element_and_id_face( indice, idFace, map_ElementSet );
                for( unsigned i = 0; i < indice.size(); ++i )
                    map_num_element[ indice[ i ] ].add_surface_element_at( mesh, match_inode_inp_lmtpp, map_num_node, idFace[ i ] );
            
            
            } else
                std::cerr << "WARNING ReaderINP : does not create surface defined by node : TODO" << std::endl;
        } else {
            std::cerr << "WARNING ReaderINP : you use create_mesh_by_surface() with un unknown name \"" << nameSurface << "\"" << std::endl;
        }
    }
    
    /*!
    Cette méthode place dans list_el les pointeurs des éléments du maillage "mesh" qui appartiennent à la surface nommé "nameSurface".
    Elle retourne le nombre de ces indices.
    Deux éléments sont considérés comme confondus si distance séparant la position de leur centre est inféieure à "tol".
    Par défaut la tolérance "tol" est à 10^-4.
    */
    template<class TMESH >
    unsigned get_element_skin_of_surface( Vec< typename TMESH::MA::EA *> &list_el, 
                                          TMESH &mesh, 
                                          const std::string &nameSurface, 
                                          typename TMESH::TNode::T tol = 1e-4 ) {
        
        typedef typename TMESH::Pvec PvecLocal;
        PvecLocal po;
        typename std::map< std::string, Surface* >::iterator it;
        
        it = map_Surface.find( nameSurface );
        list_el.resize( 0 );
        
        if ( it != map_Surface.end() ) {
            //mesh.update_skin();
            if ( it->second->type == 0 ) { /// ELEMENT-SURFACE
            
                Vec<unsigned> indicel;
                Vec<unsigned> idFace;
                it->second->get_index_element_and_id_face( indicel, idFace, map_ElementSet );            
            
                /// pour chaque facette, on cherche une facette de mesh de même centre
                CmpEl< typename TMESH::MA::EA, PvecInp > cmpel;
                
                for( unsigned i = 0; i < indicel.size(); ++i ) {
                
                    ElementINP el_inp = map_num_element[ indicel[ i ] ].get_facet( idFace[ i ] );
                    if ( el_inp.element_LMT < 0 )
                        continue; /// problème
                        
                    cmpel.element_LMT = el_inp.element_LMT;
                    cmpel.c = center( el_inp );
                    cmpel.ea = NULL; /// initialisation
                    apply( mesh.sub_mesh( Number<1>() ).elem_list, cmpel, tol );
                    if ( cmpel.ea ) 
                        list_el.push_back( cmpel.ea );
                }
                return list_el.size();
            } else { /// NODAL-SURFACE
                std::cerr << "WARNING ReaderINP.get_element_skin_of_surface() : nodal surface ???? " << std::endl;
                return 0;
            }
        } else {
            std::cerr << "WARNING ReaderINP.get_element_skin_of_surface() : unknown name \"" << nameSurface << "\"" << std::endl;
            return 0;
        }
    }
    
    void tag_mesh_by_surface( const std::string &nameSurface, const std::string& nameTag, T valueTag = (T) 1. ) {
        typename std::map< std::string, Surface* >::iterator it;
        
        it = map_Surface.find( nameSurface );
        if ( it != map_Surface.end() ) {
            Surface* surf = it->second;
            if ( surf->type == 0 ) { /// ELEMENTS-SURFACE
                typename Map_num_element::iterator it2;
                
                for( it2 = map_num_element.begin(); it2 != map_num_element.end(); ++it2 )
                    if ( it2->second.ptrEA )
                        it2->second.ptrEA->set_field( nameTag, 0. );
                    else
                        std::cerr << "WARNING ReaderINP : buzzzzzzzzzzz "  << std::endl;
               
                for( unsigned i = 0; i < surf->indice.size(); ++i )
                    if ( map_num_element[ surf->indice[ i ] ].ptrEA )
                        map_num_element[ surf->indice[ i ] ].ptrEA->set_field( nameTag, valueTag );
                    else
                        std::cerr << "WARNING ReaderINP : problem to tag the element " << surf->indice[ i ] << std::endl;
            } else
                std::cerr << "WARNING ReaderINP : does not tag mesh by surface defined by node : TODO" << std::endl;
        } else {
            std::cerr << "WARNING ReaderINP : you use tag_mesh_by_surface() with un unknown name " << nameSurface << std::endl;
        }
    }
    
    /*!
    Cette méthode place dans index les indices des noeuds du maillage "mesh" qui appartiennent à la surface nommé "nameSurface".
    Elle retourne le nombre de ces indices.
    Deux points sont considérés comme confondus si leur distance euclidienne est inféieure à "tol".
    Par défaut la tolérance "tol" est à 10^-4.
    */
    template<class TMESH >
    unsigned get_index_node_of_surface( Vec<unsigned> &index, TMESH &mesh, const std::string& nameSurface, typename TMESH::TNode::T tol = 1e-4 ) {
        typedef typename TMESH::Pvec PvecLocal;
        PvecLocal po;
        typename std::map< std::string, Surface* >::iterator it;
        
        it = map_Surface.find( nameSurface );
        index.resize( 0 );
        
        if ( it != map_Surface.end() ) {
            Surface* surf = it->second;
            if ( surf->type == 0 ) { /// ELEMENT-SURFACE
                Vec<unsigned> lindex, bigindex;
                for( unsigned i = 0; i < surf->indice.size(); ++i ) {
                    /// on cherche à obtenir les indices des noeuds de la surface de l'élément "i" concerné .
                    map_num_element[ surf->indice[ i ] ].get_index_node_of_surface( lindex, surf->id_face[ i ] );

                    for( unsigned j = 0; j < lindex.size(); ++j )
                        if ( not( bigindex.contains( lindex[ j ] ) ) ) 
                                    bigindex.push_back( lindex[ j ] );
                }

                for( unsigned i = 0; i < bigindex.size(); ++i ) {
                    map_num_node[ bigindex[ i ] ].copy_to( po ); /// pas optimisé
                    for( unsigned j = 0; j < mesh.node_list.size(); ++j )
                        if ( LMT::distance( po, mesh.node_list[ j ].pos ) < tol ) {
                            index.push_back( j );
                            break;
                        }
                }
                return index.size();
                
            } else { /// NODAL-SURFACE
                for( unsigned i = 0; i < surf->indice.size(); ++i ) {
                    //po = (PvecLocal) map_num_node[ surf->indice[ i ] ];
                    map_num_node[ surf->indice[ i ] ].copy_to( po ); /// pas optimisé
                    for( unsigned j = 0; j < mesh.node_list.size(); ++j )
                        if ( LMT::distance( po, mesh.node_list[ j ].pos ) < tol ) {
                            index.push_back( j );
                            break;
                        }
                }
                return index.size();
            }
        } else {
            std::cerr << "WARNING ReaderINP : you use get_index_node_of_surface() with unknown name " << nameSurface << std::endl;
            return 0;
        }
    }
    
    /*!
        Objectif :
            cette méthode retourne dans le vecteur "index" les indices des noeuds du maillage "m" généré par le constructeur appartenant au bord nommé "nameBoundary".
            
        Paramètres :
            * index est le tableau des indices des noeuds du bord "nameBoundary",
            * nameBoundary est le nom du bord.
            
        Retour :
            nombre d'éléments du vecteur "index".
    */
    unsigned get_index_node_of_boundary( Vec<unsigned> &index, const std::string& nameBoundary ) {
    
        typename std::map< std::string, Boundary* >::iterator it;
        int ind;
        
        it = map_Boundary.find( nameBoundary );
        index.resize( 0 );
        
        if ( it != map_Boundary.end() ) {
            Boundary* bord = it->second;
            for( unsigned i = 0; i < bord->list_bnode.size(); ++i ) {
                ind = map_num_node[ bord->list_bnode[ i ].info ].index_LMTpp;
                if ( ind >= 0 )
                    index.push_back( ind );
                else {   
                    std::cerr << "WARNING ReaderINP.get_index_node_of_boundary() : negative index" << std::endl;
                    //assert( 0 );
                }
            }
            
            for( unsigned i = 0; i < bord->list_bnodeset.size(); ++i ) {
                typename std::map< std::string, NodeSet* >::iterator it2 = map_NodeSet.find( bord->list_bnodeset[ i ].info   );
                if ( it2 != map_NodeSet.end() ) {
                    typename NodeSet::iterator it3;
                    for( it3 = it2->second->begin(); it3 != it2->second->end(); ++it3 ) {
                        ind = map_num_node[ *it3 ].index_LMTpp;
                        if ( ind >= 0 )
                            index.push_back( ind );
                        else {   
                            std::cerr << "WARNING ReaderINP.get_index_node_of_boundary() : negative index" << std::endl;
                            //assert( 0 );
                        }                    
                    }
                } else
                    std::cerr << "WARNING ReaderINP.get_index_node_of_boundary() : unknown NodeSet" << std::endl;
            }
        
        } else {
            std::cerr << "WARNING ReaderINP : you use get_index_node_of_boundary() with unknown name " << nameBoundary << std::endl;
        }
        
        return index.size();
    }
    
    //template<class TMESH,class TTOL>
    //unsigned get_node_of_boundary( Vec<BNode<> > &bnode_list, TMESH &m, const std::string & nameBoundary, TTOL tol = 1e-4 ) const {
    unsigned get_node_of_boundary( Vec<BNode<> > &bnode_list, const std::string & nameBoundary ) {
        typename std::map< std::string, Boundary* >::iterator it;
        int ind;
        
        it = map_Boundary.find( nameBoundary );
        bnode_list.resize( 0 );
        
        if ( it != map_Boundary.end() ) {
            Boundary* bord = it->second;
            for( unsigned i = 0; i < bord->list_bnode.size(); ++i ) {
                ind = map_num_node[ bord->list_bnode[ i ].info ].index_LMTpp;
                if ( ind >= 0 ) {
                    BNode<> bn = bord->list_bnode[ i ];
                    bn.info = (unsigned ) ind; /// on met à jour l'index avec celui du maillage LMTpp
                    bnode_list.push_back( bn );
                } else {   
                    std::cerr << "WARNING ReaderINP.get_node_of_boundary() : negative index" << std::endl;
                    //assert( 0 );
                }
            }
            
            for( unsigned i = 0; i < bord->list_bnodeset.size(); ++i ) {
                typename std::map< std::string, NodeSet* >::iterator it2 = map_NodeSet.find( bord->list_bnodeset[ i ].info   );
                if ( it2 != map_NodeSet.end() ) {
                    typename NodeSet::iterator it3;
                    for( it3 = it2->second->begin(); it3 != it2->second->end(); ++it3 ) {
                        ind = map_num_node[ *it3 ].index_LMTpp;
                        if ( ind >= 0 ) {
                            BNode<> bn;
                            bn._constraint = bord->list_bnodeset[ i ]._constraint;
                            bn.value = bord->list_bnodeset[ i ].value;
                            bn.info = (unsigned ) ind; /// on met à jour l'index avec celui du maillage LMTpp
                            bnode_list.push_back( bn );
                        } else {   
                            std::cerr << "WARNING ReaderINP.get_node_of_boundary() : negative index" << std::endl;
                            //assert( 0 );
                        }                    
                    }    
                } else
                    std::cerr << "WARNING ReaderINP.get_node_of_boundary() : unknown NodeSet" << std::endl;
            }
        
        } else {
            std::cerr << "WARNING ReaderINP : you use get_node_of_boundary() with unknown name " << nameBoundary << std::endl;
        }
        
        return bnode_list.size();
    }
    
    template< class Ca, unsigned ma, class TTOL>
    unsigned get_node_of_boundary( Vec< BNode<> > &bnode_list, Mesh<Ca,ma> &m, const std::string & nameBoundary, TTOL tol ) {
    
        typename std::map< std::string, Boundary* >::iterator it;
        PvecInp p;
        unsigned j;
        
        it = map_Boundary.find( nameBoundary );
        bnode_list.resize( 0 );
        
        if ( it != map_Boundary.end() ) {
            Boundary* bord = it->second;
            for( unsigned i = 0; i < bord->list_bnode.size(); ++i ) {
                p = map_num_node[ bord->list_bnode[ i ].info ].pos;
                /// on recherche dans le maillage m s'il existe un noeud à la même position 
                for( j = 0; j < m.node_list.size(); ++j ) 
                    if ( length( p - m.node_list[ j ].pos ) < tol )
                        break;
                if ( j < m.node_list.size() ) {
                    BNode<> bn = bord->list_bnode[ i ];
                    bn.info = j; /// on met à jour l'index avec celui du maillage LMTpp
                    bnode_list.push_back( bn );
                } else {
                    std::cerr << "WARNING ReaderINP.get_node_of_boundary() : unfound node at position " << p << std::endl;
                }
            }
            
            for( unsigned i = 0; i < bord->list_bnodeset.size(); ++i ) {
                typename std::map< std::string, NodeSet* >::iterator it2 = map_NodeSet.find( bord->list_bnodeset[ i ].info   );
                if ( it2 != map_NodeSet.end() ) {
                    typename NodeSet::iterator it3;
                    for( it3 = it2->second->begin(); it3 != it2->second->end(); ++it3 ) {
                        p = map_num_node[ *it3 ].pos;
                        /// on recherche dans le maillage m s'il existe un noeud à la même position
                        for( j = 0; j < m.node_list.size(); ++j ) 
                            if ( length( p - m.node_list[ j ].pos ) < tol )
                                break;                        
                        if ( j < m.node_list.size() ) {
                            BNode<> bn;
                            bn._constraint = bord->list_bnodeset[ i ]._constraint;
                            bn.value = bord->list_bnodeset[ i ].value;
                            bn.info = j; /// on met à jour l'index avec celui du maillage LMTpp
                            bnode_list.push_back( bn );
                        } else {   
                            std::cerr << "WARNING ReaderINP.get_node_of_boundary() : unfound node at position " << p << std::endl;
                            //assert( 0 );
                        }                    
                    }    
                } else
                    std::cerr << "WARNING ReaderINP.get_node_of_boundary() : unknown NodeSet" << std::endl;
            }
        
        } else {
            std::cerr << "WARNING ReaderINP : you use get_node_of_boundary() with unknown name " << nameBoundary << std::endl;
        }
        
        return bnode_list.size();
    }
    
    /*!
        Objectif :
            cette méthode retourne dans le vecteur "index" les indices des noeuds du maillage "m" généré par le constructeur appartenant au NodeSet nommé "nameNodeSet".
            
        Paramètres :
            * index est le tableau des indices des noeuds du NodeSet,
            * nameNodeSet est le nom du bord.
            
        Retour :
            nombre d'éléments du vecteur "index".
            
        Rq : il faut que index_LMTpp soit bien initialisé.
    */
    unsigned get_index_node_of_node_set( Vec<unsigned> &index, const std::string& nameNodeSet ) {
    
        typename std::map< std::string, NodeSet* >::iterator it;
        int i;
        
        it = map_NodeSet.find( nameNodeSet );
        index.resize( 0 );
        
        if ( it != map_NodeSet.end() ) {
            typename NodeSet::iterator it2;
            for( it2 = it->second->begin(); it2 != it->second->end(); ++it2 ) {
                i = map_num_node[ *it2 ].index_LMTpp;
                if ( i >= 0 )
                    index.push_back( i );
                else {   
                    std::cerr << "WARNING ReaderINP.get_index_node_of_node_set() : negative index" << std::endl;
                    //assert( 0 );
                }
            }
        
        } else {
            std::cerr << "WARNING ReaderINP : you use get_node_of_boundary() with unknown name " << nameNodeSet << std::endl;
        }
        
        return index.size();
    }
    
    /*!
        Objectif :
            cette méthode retourne dans le vecteur "names" les noms des NodeSet .
            
        Paramètres :
            * index est le tableau des noms des NodeSet,
            
        Retour :
            nombre d'éléments du vecteur "names".
            
    */
    unsigned get_name_of_node_set( Vec<std::string> &names ) {
    
        typename std::map< std::string, NodeSet* >::iterator it;

        names.resize( 0 );
        for( it = map_NodeSet.begin(); it != map_NodeSet.end(); ++it )
            names.push_back( it->first );
        
        return names.size();
    }
    
    template<class TMESH>
    void create_mesh_by_material( TMESH &mesh, const std::string &nameMaterial ) {
        std::map< unsigned, unsigned > match_inode_inp_lmtpp;
        typename std::map< std::string, SolidSection* >::iterator it;
        typename TMESH::MA::EA *ptrEA;
        ElementSet* elset;
        Orientation *ori;
        Material* material;
        //ElementINP mel;

        for( it = map_SolidSection.begin(); it != map_SolidSection.end(); it++ ) {
            //PRINT(it->first);
            if ( it->second ) {
                if ( it->second->s_material == nameMaterial ) {
                    ori = it->second->orientation;
                    material = it->second->material;
                    typename std::map< std::string, ElementSet*>::iterator itelset = map_ElementSet.find( it->first );
                    
                    if ( itelset != map_ElementSet.end() ) {
                        elset = itelset->second;
                        typename ElementSet::iterator itel;
                        for( itel = elset->begin(); itel != elset->end(); ++itel ) {
                            ptrEA = map_num_element[ *itel ].add_element_at( mesh, match_inode_inp_lmtpp, map_num_node );
                            if ( ptrEA ) {
                                if ( ori )
                                    ori->setProperty( ptrEA );
                                //else
                                    //std::cerr << "WARNING ReaderINP : ori == NULL  material = " << nameMaterial << std::endl;
                                if ( material ) {
                                    if ( material->material_property ) 
                                        material->material_property->setProperty( ptrEA );
                                    //else
                                        //std::cerr << "WARNING ReaderINP : material->material_property == NULL" << std::endl;
                                } else
                                    std::cerr << "WARNING ReaderINP : material == NULL" << std::endl;
                            } else
                                std::cerr << "WARNING ReaderINP : ptrEA == NULL" << std::endl;
                        }
                    }
                }
            } else
                std::cerr << ">> it->second == NULL ..." << std::endl;
        }
    }
    
    void display_map_element_set( bool withElement = false) {

        typename std::map< std::string, ElementSet* >::iterator it;

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                Element Set                       *" << std::endl;
        std::cout << "****************************************************" << std::endl;
        
        for( it = map_ElementSet.begin(); it != map_ElementSet.end(); it++) {
            std::cout << "name is \"" <<  it->first << "\"" << std::endl;
            if ( withElement ) {
                if ( it->second )
                    it->second->display();
                else
                    std::cout << ">> it->second == NULL ..." << std::endl;
            }
        }
    }
    
    void display_map_node_set(bool withNode = false) {

        typename std::map< std::string, NodeSet* >::iterator it;

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                   Node Set                       *" << std::endl;
        std::cout << "****************************************************" << std::endl;
        
        for( it = map_NodeSet.begin(); it != map_NodeSet.end(); it++) {
            std::cout << "name is " <<  it->first << std::endl;
            if ( withNode ) {
                if (it->second)
                    it->second->display();
                else
                    std::cout << ">> it->second == NULL ..." << std::endl;
            }
        }
    }
    
    void display_map_orientation() {

        typename std::map< std::string, Orientation* >::iterator it;

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                 Orientation                      *" << std::endl;
        std::cout << "****************************************************" << std::endl;

        for( it = map_Orientation.begin(); it != map_Orientation.end(); it++) {
            //PRINT(it->first);
            std::cout << "Orientation named " << it->first << std::endl;
            if (it->second) {
                //std::cout << " DATA = " << it->second->data << std::endl;
                std::cout << " v1 = " << it->second->v1 << std::endl;
                std::cout << " v2 = " << it->second->v2 << std::endl;
            } else
                std::cout << ">> it->second == NULL ..." << std::endl;
        }
    }
    
    void display_node() {

        typename Map_num_node::iterator it;

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                       Node                       *" << std::endl;
        std::cout << "****************************************************" << std::endl;

        for( it = map_num_node.begin(); it != map_num_node.end(); it++ )
            std::cout << "name is " <<  it->first << " at position " << it->second.pos << std::endl;
    }
    
    void display_element() {

        typename Map_num_element::iterator it;
        
        std::cout << "****************************************************" << std::endl;
        std::cout << "*                   Element                        *" << std::endl;
        std::cout << "****************************************************" << std::endl;
        PRINT( map_num_element.size() );
        for( it = map_num_element.begin(); it != map_num_element.end(); it++)
            std::cout << "name is " <<  it->first << " of type " << it->second.name << std::endl; //PRINT( *( it->second.ptr ) );
    }
    
    void display_map_material() {

        typename std::map< std::string, Material* >::iterator it;

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                   Material                       *" << std::endl;
        std::cout << "****************************************************" << std::endl;

        for( it = map_Material.begin(); it != map_Material.end(); it++) {
            std::cout << "name is " <<  it->first << std::endl;
            if ( it->second ) {
                    it->second->display();
            } else
                std::cout << ">> it->second == NULL ..." << std::endl;
        }
    }
    
    /*!
        Objectif :
            cette méthode retourne dans le vecteur "names" les noms des Material .
            
        Paramètres :
            * index est le tableau des noms des NodeSet,
            
        Retour :
            nombre d'éléments du vecteur "names".
            
    */
    unsigned get_name_of_material( Vec<std::string> &names ) {
    
        typename std::map< std::string, Material* >::iterator it;

        names.resize( 0 );
        for( it = map_Material.begin(); it != map_Material.end(); ++it )
            names.push_back( it->first );
        
        return names.size();
    }
    
    void display_map_solid_section() {

        typename std::map< std::string, SolidSection* >::iterator it;

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                Solid Section                     *" << std::endl;
        std::cout << "****************************************************" << std::endl;
        
        for( it = map_SolidSection.begin(); it != map_SolidSection.end(); it++) {
            std::cout << "name is " <<  it->first << std::endl;
            if ( it->second ) {
                if ( it->second->material )
                    it->second->material->display();
                else
                    std::cout << ">> it->second->material == NULL ..." << std::endl;
                if ( it->second->orientation ) {
                    std::cout << " orientation::v1 = " << it->second->orientation->v1 << std::endl;
                    std::cout << " orientation::v2 = " << it->second->orientation->v2 << std::endl;
                } else
                    std::cout << ">> it->second->orientation == NULL ..." << std::endl;
            } else
                std::cout << ">> it->second == NULL ..." << std::endl;
        }
    }
    
    void display_map_surface( bool withIndice = false ) {

        typename std::map< std::string, Surface* >::iterator it;

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                   Surface                        *" << std::endl;
        std::cout << "****************************************************" << std::endl;
        
        for( it = map_Surface.begin(); it != map_Surface.end(); it++) {
            std::cout << "name is \"" <<  it->first << "\"" << std::endl;
            if ( withIndice ) {
                if ( it->second )
                    it->second->display();
                else
                    std::cout << ">> it->second == NULL ..." << std::endl;
            }
        }
    }
    
    /*!
        Objectif :
            cette méthode retourne dans le vecteur "names" les noms des Surface .
            
        Paramètres :
            * index est le tableau des noms des surfaces,
            
        Retour :
            nombre d'éléments du vecteur "names".
            
    */
    unsigned get_name_of_surface( Vec<std::string> &names ) {
    
        typename std::map< std::string, Surface* >::iterator it;

        names.resize( 0 );
        for( it = map_Surface.begin(); it != map_Surface.end(); ++it )
            names.push_back( it->first );
        
        return names.size();
    }
    
    void display_map_boundary( bool withIndice = false ) {

        typename std::map< std::string, Boundary* >::iterator it;

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                   Boundary                        *" << std::endl;
        std::cout << "****************************************************" << std::endl;
        
        for( it = map_Boundary.begin(); it != map_Boundary.end(); it++) {
            std::cout << "name is " <<  it->first << std::endl;
            if ( withIndice ) {
                if ( it->second )
                    it->second->display();
                else
                    std::cout << ">> it->second == NULL ..." << std::endl;
            }
        }
    }
    
    /*!
        Objectif :
            cette méthode retourne dans le vecteur "names" les noms des Boundary .
            
        Paramètres :
            * index est le tableau des noms des Boundary,
            
        Retour :
            nombre d'éléments du vecteur "names".
            
    */
    unsigned get_name_of_boundary( Vec<std::string> &names ) {
    
        typename std::map< std::string, Boundary* >::iterator it;

        names.resize( 0 );
        for( it = map_Boundary.begin(); it != map_Boundary.end(); ++it )
            names.push_back( it->first );
        
        return names.size();
    }
    
    void display_map_transform( bool withData = false ) {

        typename std::map< std::string, Transform* >::iterator it;

        std::cout << "****************************************************" << std::endl;
        std::cout << "*                   Transform                      *" << std::endl;
        std::cout << "****************************************************" << std::endl;
        
        for( it = map_Transform.begin(); it != map_Transform.end(); it++) {
            std::cout << "name is " <<  it->first << std::endl;
            if ( withData ) {
                if ( it->second )
                    it->second->display();
                else
                    std::cout << ">> it->second == NULL ..." << std::endl;
            }
        }
    }
    
    /// attributs :
    //std::map< std::string, Part*> map_NodeSet;
    std::map< std::string, NodeSet*> map_NodeSet;
    std::map< std::string, ElementSet*> map_ElementSet;
    std::map< std::string, Orientation*> map_Orientation;
    std::map< std::string, SolidSection*> map_SolidSection;
    std::map< std::string, Material*> map_Material;
    std::map< std::string, ContactPair*> map_ConctactPair;
    std::map< std::string, Surface*> map_Surface;
    std::map< std::string, Boundary*> map_Boundary;
    std::map< std::string, Transform*> map_Transform;
    Map_num_node map_num_node;
    Map_num_element map_num_element;

    static const char* internal_name[ 2 ];
    static const unsigned nb_principale_keyword = 38; /// 39 avec Part
    static const char* list_principale_keyword[ nb_principale_keyword ];
};

template<class TM> 
const char* ReaderINP<TM>::internal_name[2] = {
    "__READERINP__ALL_NODES__",
    "__READERINP__ALL_ELEMENTS__"
};

template<class TM> 
const char* ReaderINP<TM>::list_principale_keyword[ ReaderINP<TM>::nb_principale_keyword ] = {
    //"PART",
    "MATERIAL",
    "NODE",
    "ELEMENT",
    "NSET",
    "ELSET",
    "ORIENTATION",
    "SOLID SECTION",
    "BOUNDARY",
    "AMPLITUDE",   /// 10
    "SURFACE",
    "CONTACT PAIR",
    "STEP",
    "STATIC",
    "CLOAD",
    "DLOAD",
    "TEMPERATURE",
    "NODE PRINT",
    "EL PRINT",
    "MODAL PRINT", /// 20
    "ENERGY PRINT",
    "PRINT",
    "ELEMENT OUTPUT",
    "OUTPUT",
    "END STEP",
    "TRANSFORM",
    "Material",
    "Node",
    "Element",
    "Nset",  /// 30
    "Elset",
    "Orientation",       
    "Solid Section",
    "Boundary",
    "Amplitude",
    "Surface",
    "Contact Pair",
    "Step",
    "End Step"
    //"" /// pour indiquer la fin
};

template<class TM> 
const char* ReaderINP<TM>::ContactPair::list_keyword[ ReaderINP<TM>::ContactPair::nb_keyword ] = {
    "FRICTION",
    "Friction",
    "SURFACE INTERACTION",
    "Surface Interaction"
    //""
};    

};


#endif  /// READER_INP_H


