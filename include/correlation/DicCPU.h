#ifndef DIV_CPU_H
#define DIV_CPU_H

#include <correlation/ImgInterp.h>
#include <containers/mat.h>
#include <util/rectilinear_iterator.h>
#include <util/symamd.h>
#include <mesh/make_rect.h>
#include <QtCore/QMutex>
#include "mesh_carac_correlation.h"

namespace LMT {

template<class T,unsigned dim>
struct DicCPU {
    typedef Mesh<Mesh_carac_pb_correlation_basic<double,2> > TM_exemple;

    ///
    DicCPU() {
        levenberg_marq = 0.0;
        prec_linear_system = 1e-4;
        nb_threads_for_assembly = 4;
        div_pixel = 4;
    }

    ///
    template<class NAME_VAR>
    struct Assemble {
        template<class TE,class TIMGf,class TIMGg> void operator()( const TE &e, DicCPU &dic, const TIMGf &f, const TIMGg &g ) {
            ExtractDM<NAME_VAR> ed;
            Vec<T,dim> P[TE::nb_nodes], D[TE::nb_nodes], MA( e.pos(0) ), MI( e.pos(0) );
            for(int i=0;i<TE::nb_nodes;++i) P[ i ] = e.pos(i);
            for(int i=0;i<TE::nb_nodes;++i) D[ i ] = e.pos(i) + ed( *e.node(i) );
            for(int i=1;i<TE::nb_nodes;++i) MI = min( MI, P[ i ] ); // hum
            for(int i=1;i<TE::nb_nodes;++i) MA = max( MA, P[ i ] ); // hum
            f.load_if_necessary( MI, MA );
            g.load_if_necessary( MI, MA );
            //
            Vec<T,dim*TE::nb_nodes> F( 0 );
            Mat<T,Gen<dim*TE::nb_nodes> > M; M.set( 0 ); // hum
            //
            Vec<T,TE::nb_var_inter> var_inter( 0 );
            Vec<T,dim> O, old_O;
            for( Rectilinear_iterator<T,dim> p( Vec<int,dim>(MI), Vec<int,dim>(MA) + 2, 1.0 / dic.div_pixel ); p; ++p ) {
                get_var_inter( typename TE::NE(), P, Vec<T,dim>( p.pos ), var_inter );
                get_interp( typename TE::NE(), Nodal(), var_inter, P, O );
                while ( ElemVarInterFromPosNonLinear<typename TE::NE>::res ) { // TODO : linear case
                    old_O = O;
                    get_var_inter( typename TE::NE(), P, Vec<T,dim>( p.pos ), var_inter );
                    get_interp( typename TE::NE(), Nodal(), var_inter, P, O );
                    if ( max( old_O - O ) < 1e-2 )
                        break;
                }
                if ( not var_inter_is_inside( typename TE::NE(), var_inter, 1e-6 ) )
                    continue;
                
                //
                Vec<T,dim> DO;
                get_interp( typename TE::NE(), Nodal(), var_inter, D, DO );
                
                //
                Vec<T,TE::nb_nodes> shape_functions;
                get_shape_functions( typename TE::NE(), var_inter, shape_functions );
                Vec<T,dim> grad = 0.5 * ( f.grad( O ) + g.grad( DO ) );
                
                Vec<T,dim*TE::nb_nodes> sham_grad;
                for(int i=0,n=0;i<TE::nb_nodes;++i)
                    for(int d=0;d<dim;++d,++n)
                        sham_grad[ n ] = shape_functions[ i ] * grad[ d ];
                        
                
                T diff_fg = f( O ) - g( DO );
                dic.sum_residual += abs( diff_fg );
                
                for(int n=0;n<dim*TE::nb_nodes;++n) {
                    F[ n ] += sham_grad[ n ] * diff_fg;
                    for(int m=n;m<dim*TE::nb_nodes;++m)
                        M( n, m ) += sham_grad[ n ] * sham_grad[ m ];
                }
            }
            
            //
            mutex.lock();
            if ( want_mat ) {
                for(int i=0,n=0;i<TE::nb_nodes;++i)
                    for(int d=0;d<dim;++d,++n)
                        for(int j=0,m=0;j<TE::nb_nodes;++j)
                            for(int c=0;c<dim;++c,++m)
                                if ( n <= m )
                                    dic.M( dic.indice_noda[ e.node(i)->number ] + d, dic.indice_noda[ e.node(j)->number ] + c ) += M( n, m );
            }
            //
            if ( want_vec ) {
                for(int i=0,n=0;i<TE::nb_nodes;++i)
                    for(int d=0;d<dim;++d,++n)
                        dic.F[ dic.indice_noda[ e.node(i)->number ] + d ] += F[ n ];
            }
            mutex.unlock();
        }
        bool want_mat, want_vec;
        QMutex mutex;
    };

    ///
    template<class NAME_VAR>
    struct MakeDefImg {
        template<class TE,class TIMGf,class TIMGr> void operator()( const TE &e, const TIMGf &f, TIMGr &r ) const {
            ExtractDM<NAME_VAR> ed;
            Vec<T,dim> P[TE::nb_nodes], D[TE::nb_nodes], MA( e.pos(0) + ed( *e.node(0) ) ), MI( e.pos(0) + ed( *e.node(0) ) );
            for(int i=0;i<TE::nb_nodes;++i) P[ i ] = e.pos(i);
            for(int i=0;i<TE::nb_nodes;++i) D[ i ] = e.pos(i) + ed( *e.node(i) );
            for(int i=1;i<TE::nb_nodes;++i) MI = min( MI, D[ i ] ); // hum
            for(int i=1;i<TE::nb_nodes;++i) MA = max( MA, D[ i ] ); // hum
            f.load_if_necessary( MI, MA );
            r.load_if_necessary( MI, MA, true );
            //
            Vec<T,TE::nb_var_inter> var_inter( 0 );
            Vec<T,dim> O, old_O;
            for( Rectilinear_iterator<int,dim> p( MI, MA + 1, 1 ); p; ++p ) {
                get_var_inter( typename TE::NE(), D, Vec<T,dim>( p.pos ), var_inter );
                get_interp( typename TE::NE(), Nodal(), var_inter, P, O );
                while ( ElemVarInterFromPosNonLinear<typename TE::NE>::res ) { // TODO : linear case
                    old_O = O;
                    get_var_inter( typename TE::NE(), D, Vec<T,dim>( p.pos ), var_inter );
                    get_interp( typename TE::NE(), Nodal(), var_inter, P, O );
                    if ( max( old_O - O ) < 1e-2 )
                        break;
                }
                if ( not var_inter_is_inside( typename TE::NE(), var_inter, 1e-6 ) )
                    continue;
                //
                r( p.pos ) = f( O );
            }
        }
    };
    
    ///
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR> void assemble( const TIMGf &f, const TIMGg &g, const TM &m, const NAME_VAR &name_var, bool want_mat = true, bool want_vec = true ) {
        unsigned nb_ddl = m.node_list.size() * dim;
        if ( want_mat ) {
            //indice_noda = dim * symamd( m );
            indice_noda = dim * range( m.node_list.size() );
            
            M.clear();
            M.resize( nb_ddl );
        }
        if ( want_vec ) {
            F.resize( nb_ddl );
            F.set( 0.0 );
        }
        
        //
        Assemble<NAME_VAR> ass;
        ass.want_mat = want_mat;
        ass.want_vec = want_vec;
        sum_residual = 0;
        apply_mt( m.elem_list, nb_threads_for_assembly, ass, *this, f, g );
        
        //
        if ( want_mat ) {
            if ( levenberg_marq ) {
                T ni =  norm_inf( M.diag() );
                M.diag() += levenberg_marq * ( ni + ( ni == 0 ) );
            }
            C_M = M;
            chol_factorize( C_M );
        }
    }

    ///
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR> void exec( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR &name_var, bool want_mat = true ) {
        // read_from_mesh( m, name_var );
        assemble( f, g, m, name_var, want_mat, true );
        solve_linear_system();
        update_mesh( m, name_var );
    }
    
    ///
    void solve_linear_system() {
        solve_using_chol_factorize( C_M, F, dU );
        // Mat<T,Gen<> > m( M );
        // dU = inv( m ) * F;
    }
    
    ///
    template<class TM,class NAME_VAR> void update_mesh( TM &m, const NAME_VAR &name_var ) const {
        ExtractDM<NAME_VAR> ed;
        for(int i=0;i<m.node_list.size();++i)
            for(int d=0;d<dim;++d)
                ed( m.node_list[i] )[ d ] += dU[ indice_noda[ i ] + d ];
    }

    //     template<class TM,class NAME_VAR> void read_from_mesh( const TM &m, const NAME_VAR &name_var ) {
    //         ExtractDM<NAME_VAR> ed;
    //         U.resize( dim * m.node_list.size() );
    //         for(int i=0;i<m.node_list.size();++i)
    //             for(int d=0;d<dim;++d)
    //                 U[ indice_noda[ i ] + d ] = ed( m.node_list[i] )[ d ];
    //     }
    
    ///
    template<class TIMGf,class TM,class NAME_VAR,class TIMGr> void get_def_img( const TIMGf &f, TM &m, const NAME_VAR &name_var, TIMGr &r ) {
        r.resize( f.sizes );
        r.set( -1 );
        apply( m.elem_list, MakeDefImg<NAME_VAR>(), f, r );
    }
    
    ///
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR,class TIMGr> void get_residual_img( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR &name_var, TIMGr &r ) {
        get_def_img( f, m, name_var, r );
        for( Rectilinear_iterator<int,dim> p( 0, Vec<int,dim>( f.sizes - 1 ), 1 ); p; ++p ) {
            g.load_if_necessary( p.pos, p.pos );
            r.load_if_necessary( p.pos, p.pos, true );
            r( p.pos ) = ( r( p.pos ) >= 0 ? abs( r( p.pos ) - g( p.pos ) ) : -1 );
        }
    }
    
    ///
    template<class TIMG,class TF,class NAME_VAR>
    void femu_fit( const TIMG &f, const TIMG &g, TF &formulation, const NAME_VAR &name_var ) {
        formulation.erase_constraints_from( 0 );
    }
    
    
    Mat<T,Sym<>,SparseLine<> > M, C_M;
    Vec<int> indice_noda;
    Vec<T> F;
    Vec<T> dU;
    T sum_residual;
    
    T prec_linear_system;
    T levenberg_marq;
    unsigned nb_threads_for_assembly;
    unsigned div_pixel; // for "correct" integration
};

}

#endif // DIV_CPU_H
