#ifndef DIV_CPU_H
#define DIV_CPU_H

#include <correlation/ImgInterp.h>
#include <containers/mat.h>
#include <util/rectilinear_iterator.h>
#include <util/symamd.h>
#include <mesh/make_rect.h>
#include <formulation/FormulationFit.h>
#include <QtCore/QMutex>
#include "mesh_carac_correlation.h"

namespace LMT {

template<class T,unsigned dim>
struct DicCPU {
    typedef Mesh<Mesh_carac_pb_correlation_basic<double,2> > TM_exemple;

    ///
    DicCPU() {
        levenberg_marq = 0.0;
        nb_threads_for_assembly = 4;
        div_pixel = 1;
        delta_gray = 1;
        relaxation = 1;
        max_cpt_iter = 50;
        min_norm_inf_dU = 0;
        min_norm_2_dU = 0;
        display_norm_inf_dU = true;
        display_norm_2_dU = false;
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
            for( Rectilinear_iterator<T,dim> p( Vec<int,dim>(MI), Vec<int,dim>(MA) + 2, 1.0 / dic.div_pixel ); p; ++p ) {
                while ( true ) {
                    get_var_inter( typename TE::NE(), P, p.pos, var_inter );
                    if ( not ElemVarInterFromPosNonLinear<typename TE::NE>::res ) break;
                    Vec<T,dim> O;
                    get_interp( typename TE::NE(), Nodal(), var_inter, P, O );
                    if ( max( p.pos - O ) < 1e-2 ) break;
                }
                if ( not var_inter_is_inside( typename TE::NE(), var_inter, 1e-6 ) )
                    continue;
                
                //
                Vec<T,dim> DO;
                get_interp( typename TE::NE(), Nodal(), var_inter, D, DO );
                
                //
                Vec<T,TE::nb_nodes> shape_functions;
                get_shape_functions( typename TE::NE(), var_inter, shape_functions );
                Vec<T,dim> grad = 0.5 * ( f.grad( p.pos ) + g.grad( DO ) );
                
                Vec<T,dim*TE::nb_nodes> sham_grad;
                for(int i=0,n=0;i<TE::nb_nodes;++i)
                    for(int d=0;d<dim;++d,++n)
                        sham_grad[ n ] = shape_functions[ i ] * grad[ d ];
                        
                
                T diff_fg = f( p.pos ) - g( DO );
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
            Vec<T,dim> O;
            for( Rectilinear_iterator<int,dim> p( MI, MA + 2, 1 ); p; ++p ) {
                while ( true ) {
                    get_var_inter( typename TE::NE(), D, Vec<T,dim>( p.pos ), var_inter );
                    if ( not ElemVarInterFromPosNonLinear<typename TE::NE>::res ) break;
                    Vec<T,dim> O;
                    get_interp( typename TE::NE(), Nodal(), var_inter, D, O );
                    if ( max( p.pos - O ) < 1e-2 ) break;
                }
                if ( not var_inter_is_inside( typename TE::NE(), var_inter, 1e-6 ) )
                    continue;
                //
                Vec<T,dim> O;
                get_interp( typename TE::NE(), Nodal(), var_inter, P, O );
                r.tex_int( p.pos ) = f( O );
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
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR> void exec( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR &name_var, bool want_mat = true, bool want_vec = true ) {
        for(cpt_iter=0;cpt_iter<max_cpt_iter;++cpt_iter) {
            assemble( f, g, m, name_var, want_mat, want_vec );
            // simple break conditions
            if ( want_vec == false or ( min_norm_inf_dU == 0 and min_norm_2_dU == 0 ) )
                break;
            
            //
            solve_linear_system();
            dU *= relaxation;
            update_mesh( m, name_var );
            
            history_norm_inf_dU.push_back( norm_inf( dU ) );
            history_norm_2_dU  .push_back( norm_2  ( dU ) );
            if ( display_norm_inf_dU )
                PRINT( norm_inf( dU ) );
            if ( display_norm_2_dU )
                PRINT( norm_2( dU ) );
            
            // convergence
            if ( norm_inf( dU ) <= min_norm_inf_dU or norm_2( dU ) <= min_norm_2_dU )
                break;
        }
    }
    
    ///
    void solve_linear_system() {
        solve_using_chol_factorize( C_M, F, dU );
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
            r.tex_int( p.pos ) = ( r.tex_int( p.pos ) >= 0 ? abs( r.tex_int( p.pos ) - g.tex_int( p.pos ) ) : -1 );
        }
    }
    
    ///
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR> void display_residual_img( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR &name_var ) {
        ImgInterp<T,dim> r;
        get_residual_img( f, g, m, name_var, r );
        r.display( true );
    }
    
    template<class NAME_VAR>
    struct GetSensitivity {
        GetSensitivity( DicCPU *dc ) : dc( dc ), inv_M( dc->C_M.nb_rows() ) {
            Vec<T> res;
            for(unsigned i=0;i<dc->C_M.nb_rows();++i) {
                solve_using_chol_factorize( dc->C_M, Vec<T>( dirac_vec( 1, i, dc->C_M.nb_rows() ) ), res );
                for(int j=0;j<dc->C_M.nb_rows();++j)
                    inv_M( j, i ) = res[ j ];
            }
            dU.resize( dc->nb_threads_for_assembly );
            for(unsigned i=0;i<dc->nb_threads_for_assembly;++i)
                dU[i].resize( dc->C_M.nb_rows(), 0.0 );
        }
        template<class TE,class TIMGf,class TIMGg> void operator()( const TE &e, unsigned num_thread, const TIMGf &f, const TIMGg &g ) {
            ExtractDM<NAME_VAR> ed;
            Vec<T,dim> P[TE::nb_nodes], D[TE::nb_nodes], MA( e.pos(0) ), MI( e.pos(0) );
            for(int i=0;i<TE::nb_nodes;++i) P[ i ] = e.pos(i);
            for(int i=0;i<TE::nb_nodes;++i) D[ i ] = e.pos(i) + ed( *e.node(i) );
            for(int i=1;i<TE::nb_nodes;++i) MI = min( MI, e.pos(i) ); // hum
            for(int i=1;i<TE::nb_nodes;++i) MA = max( MA, e.pos(i) ); // hum
            f.load_if_necessary( MI, MA );
            g.load_if_necessary( MI, MA );
            //
            Vec<T,TE::nb_var_inter> var_inter( 0 );
            Vec<T> &locU = dU[ num_thread ];
            for( Rectilinear_iterator<T,dim> p( Vec<int,dim>(MI), Vec<int,dim>(MA) + 2, 1.0 / dc->div_pixel ); p; ++p ) {
                while ( true ) {
                    get_var_inter( typename TE::NE(), P, p.pos, var_inter );
                    if ( not ElemVarInterFromPosNonLinear<typename TE::NE>::res ) break;
                    Vec<T,dim> O;
                    get_interp( typename TE::NE(), Nodal(), var_inter, P, O );
                    if ( max( p.pos - O ) < 1e-2 ) break;
                }
                if ( not var_inter_is_inside( typename TE::NE(), var_inter, 1e-6 ) )
                    continue;
                
                //
                Vec<T,dim> DO;
                get_interp( typename TE::NE(), Nodal(), var_inter, D, DO );
                
                //
                Vec<T,TE::nb_nodes> shape_functions;
                get_shape_functions( typename TE::NE(), var_inter, shape_functions );
                Vec<T,dim> grad = 0.5 * ( f.grad( p.pos ) + g.grad( DO ) );
                        
                //
                for(int j=0;j<locU.size();++j) {
                    T locU_sgn = 0.0;
                    for(int i=0;i<TE::nb_nodes;++i) {
                        for(int d=0;d<dim;++d) {
                            T sham_grad = shape_functions[ i ] * grad[ d ];
                            locU_sgn += inv_M( j, dc->indice_noda[ e.node(i)->number ] + d ) * sham_grad;
                        }
                    }
                    locU[ j ] += 2 * dc->delta_gray * abs( locU_sgn );
                }
            }
        }
        Mat<T,Sym<> > inv_M;
        Vec<Vec<T> > dU;
        QMutex mutex;
        DicCPU *dc;
    };
    
    ///
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR,class NAME_RES>
    T get_sensitivity( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR &name_var, const NAME_RES &name_res ) {
        GetSensitivity<NAME_VAR> gs( this );
        apply_mt_with_num_thread( m.elem_list, nb_threads_for_assembly, gs, f, g );
        Vec<T> dU = gs.dU[ 0 ]; for(int i=1;i<gs.dU.size(); dU += gs.dU[ i++ ] );
            
        //
        ExtractDM<NAME_RES> ed;
        for(int i=0;i<m.node_list.size();++i)
            for(int d=0;d<dim;++d)
                ed( m.node_list[i] )[ d ] = dU[ indice_noda[ i ] + d ];
        
        //
        return mean( dU );
    }
    
    // output
    Mat<T,Sym<>,SparseLine<> > M, C_M;
    Vec<int> indice_noda;
    Vec<T> F;
    Vec<T> dU;
    T sum_residual;
    unsigned cpt_iter; // nombre d'itérations pour converger
    Vec<T> history_norm_inf_dU;
    Vec<T> history_norm_2_dU;
    
    // input
    T levenberg_marq;
    T relaxation;
    T delta_gray; /// erreur capteur
    T min_norm_inf_dU; /// norm_inf( dU ) < min_norm_inf_dU pour que ça s'arrête
    T min_norm_2_dU; /// à moins que norm_2( dU ) < min_norm_2_dU
    unsigned max_cpt_iter; /// à moins que nb_iter >= max_cpt_iter
    unsigned nb_threads_for_assembly;
    unsigned div_pixel; /// for "correct" integration
    bool display_norm_inf_dU; /// display norm_inf( dU ) au cours des itérations, vrai par défaut
    bool display_norm_2_dU; /// display norm_2( dU ) au cours des itérations, faux par défaut
};

}

#endif // DIV_CPU_H
