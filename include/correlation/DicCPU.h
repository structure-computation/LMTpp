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
// #include <correlation/pixelotomie.h>

namespace LMT {

///
template<class TE,class  TIMG_f,class TIMG_g,class TM,class TV,class T> void dic_elem_matrix( const TE &elem, const TIMG_f &f, const TIMG_g &g, TM &M, TV &V, int x, int y, StructForType<T> ) {
    assert( 0 );
}

/**

*/
template<class T,unsigned dim>
struct DicCPU {
    typedef Mesh<Mesh_carac_pb_correlation_basic<double,dim> > TM_exemple;
    static const bool want_lum_corr = true;

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
        display_iteration_time = false;
    }

    ///
    template<class NAME_VAR_DEPL,class NAME_VAR_GREY,bool use_g_as_ref>
    struct Assemble {
        template<class TE,class TIMGf,class TIMGg> void operator()( const TE &e, DicCPU &dic, const TIMGf &f, const TIMGg &g ) {
            Vec<T,dim> P[TE::nb_nodes], D[TE::nb_nodes], MA( e.pos(0) ), MI( e.pos(0) );
            for(int i=0;i<TE::nb_nodes;++i) P[ i ] = e.pos(i) + ed_depl( *e.node(i) ) * ( 0 + use_g_as_ref );
            for(int i=0;i<TE::nb_nodes;++i) D[ i ] = e.pos(i) + ed_depl( *e.node(i) ) * ( 1 - use_g_as_ref );
            for(int i=1;i<TE::nb_nodes;++i) MI = min( MI, P[ i ] ); // hum
            for(int i=1;i<TE::nb_nodes;++i) MA = max( MA, P[ i ] ); // hum
            f.load_if_necessary( MI, MA );
            g.load_if_necessary( MI, MA );
            //
            Vec<T,    (dim+want_lum_corr)*TE::nb_nodes  > F( 0 );
            Mat<T,Gen<(dim+want_lum_corr)*TE::nb_nodes> > M; M.set( 0 );
            
            if ( dic.div_pixel <= 0 ) {
                for( Rectilinear_iterator<int,dim> p( Vec<int,dim>(MI), Vec<int,dim>(MA) + 1, 1 ); p; ++p )
                    dic_elem_matrix( e, f, g, M, F, p.pos[0], p.pos[1], StructForType<T>() );
            } else {
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
                    Vec<T,TE::nb_nodes> shape_functions;
                    get_shape_functions( typename TE::NE(), var_inter, shape_functions );
                    
                    T val_grey = 0;
                    for(int i=0;i<TE::nb_nodes;++i)
                        val_grey += shape_functions[ i ] * ed_grey( *e.node(i) ); // dic.U_grey[ dic.indice_noda_grey[ e.node( i )->number ] ];
                        
                    //
                    Vec<T,dim> DO;
                    get_interp( typename TE::NE(), Nodal(), var_inter, D, DO );
                    
                    Vec<T,dim> PF( use_g_as_ref ? DO : p.pos );
                    Vec<T,dim> PG( use_g_as_ref ? p.pos : DO );
                    T val_f = f( PF );
                    T val_g = val_grey * g( PG );
                    Vec<T,dim> grad = 0.5 * ( f.grad( PF ) + val_grey * g.grad( PG ) );
                    
                    T diff_fg = val_f - val_g;
                    
                    // dU part
                    Vec<T,dim*TE::nb_nodes> sham_grad;
                    for(int i=0,n=0;i<TE::nb_nodes;++i)
                        for(int d=0;d<dim;++d,++n)
                            sham_grad[ n ] = shape_functions[ i ] * grad[ d ];
                            
                    //
                    for(int i=0;i<TE::nb_nodes;++i) {
                        for(int d=0;d<dim;++d) {
                            F[ i * ( dim + 1 ) + d ] += sham_grad[ i * dim + d ] * diff_fg;
                            for(int j=0;j<TE::nb_nodes;++j)
                                for(int c=0;c<dim;++c)
                                    M( i * ( dim + 1 ) + d, j * ( dim + 1 ) + c ) += sham_grad[ i * dim + d ] * sham_grad[ j * dim + c ];
                        }
                    }
                    
                    
                    // dG part
                    Vec<T,TE::nb_nodes> sham_grey;
                    for(int i=0;i<TE::nb_nodes;++i)
                        sham_grey[ i ] = shape_functions[ i ] * val_g;
                        
                    //
                    for(int i=0;i<TE::nb_nodes;++i) {
                        for(int j=0;j<TE::nb_nodes;++j)
                            M( i * ( dim + 1 ) + dim, j * ( dim + 1 ) + dim ) += sham_grey[ i ] * sham_grey[ j ];
                        F[ i * ( dim + 1 ) + dim ] += sham_grey[ i ] * diff_fg;
                    }
                    
                    // residual
                    dic.sum_residual += abs( diff_fg );
                }
            }
            
            
            //
            mutex.lock();
            if ( want_mat ) {
                for(int i=0,n=0;i<TE::nb_nodes;++i)
                    for(int d=0;d<dim+want_lum_corr;++d,++n)
                        for(int j=0,m=0;j<TE::nb_nodes;++j)
                            for(int c=0;c<dim+want_lum_corr;++c,++m)
                                if ( n <= m )
                                    dic.M( dic.indice_noda[ e.node(i)->number ] + d, dic.indice_noda[ e.node(j)->number ] + c ) += M( n, m );
            }
            //
            if ( want_vec ) {
                for(int i=0,n=0;i<TE::nb_nodes;++i)
                    for(int d=0;d<dim+want_lum_corr;++d,++n)
                        dic.F[ dic.indice_noda[ e.node(i)->number ] + d ] += F[ n ];
            }
            mutex.unlock();
        }
        bool want_mat, want_vec;
        QMutex mutex;
        ExtractDM<NAME_VAR_DEPL> ed_depl;
        ExtractDM<NAME_VAR_GREY> ed_grey;
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
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR_DEPL,class NAME_VAR_GREY>
    void assemble( const TIMGf &f, const TIMGg &g, const TM &m, const NAME_VAR_DEPL &name_var_depl, const NAME_VAR_GREY &name_var_grey, bool want_mat = true, bool want_vec = true ) {
        unsigned nb_ddl = ( dim + want_lum_corr ) * m.node_list.size();
        if ( want_mat ) {
            // indice_noda_grey = range( m.node_list.size() );
            indice_noda = ( dim + want_lum_corr ) * symamd( m );
            
            M.clear();
            M.resize( nb_ddl );
        }
        if ( want_vec ) {
            F.resize( nb_ddl );
            F.set( 0.0 );
        }
        
        sum_residual = 0;
        
        //         //
        //         Assemble<NAME_VAR_DEPL,NAME_VAR_GREY,true> ass_1;
        //         ass_1.want_mat = want_mat;
        //         ass_1.want_vec = want_vec;
        //         apply_mt( m.elem_list, nb_threads_for_assembly, ass_1, *this, f, g );
        
        //
        Assemble<NAME_VAR_DEPL,NAME_VAR_GREY,false> ass_2;
        ass_2.want_mat = want_mat;
        ass_2.want_vec = want_vec;
        apply_mt( m.elem_list, nb_threads_for_assembly, ass_2, *this, f, g );
        
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
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR_DEPL,class NAME_VAR_GREY> 
    void exec( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR_DEPL &name_var_depl, const NAME_VAR_GREY &name_var_grey, bool want_mat = true, bool want_vec = true ) {
        for(cpt_iter=0;cpt_iter<max_cpt_iter;++cpt_iter) {
            assemble( f, g, m, name_var_depl, name_var_grey, want_mat, want_vec );
            // simple break conditions
            if ( want_vec == false or ( min_norm_inf_dU == 0 and min_norm_2_dU == 0 ) )
                break;
            
            solve_linear_system();
            PRINT( dU );
            
            //
            dU *= relaxation;
            update_mesh( m, name_var_depl, name_var_grey );
            
            //
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
    
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR,class NAME_LUM>
    void exec_rigid_body( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR &name_var, const NAME_LUM &name_lum, bool want_mat = true, bool want_vec = true ) {
        typedef typename TM::Pvec Pvec;
        double time_old = time_of_day_in_sec();
        for(cpt_iter=0;cpt_iter<max_cpt_iter;++cpt_iter) {
            assemble( f, g, m, name_var, name_lum, want_mat, want_vec );
            // simple break conditions
            if ( want_vec == false or ( min_norm_inf_dU == 0 and min_norm_2_dU == 0 ) )
                break;
            
            // search_dir
            const unsigned nb_search_dir = 3 + 3 * ( dim == 3 );
            Pvec C = center( m );
            Vec<Vec<T>,nb_search_dir> search_dir;
            for(unsigned i=0;i<nb_search_dir;++i)
                search_dir[ i ].resize( F.size() );
            for(unsigned i=0;i<m.node_list.size();++i)
                for(int j=0;j<dim;++j)
                    for(int k=0;k<dim;++k)
                        search_dir[ j ][ indice_noda[i] + k ] = ( j == k );
            if ( dim == 2 ) {
                for(unsigned i=0;i<m.node_list.size();++i) {
                    search_dir[ 2 ][ indice_noda[i] + 0 ] = C[1] - m.node_list[i].pos[1];
                    search_dir[ 2 ][ indice_noda[i] + 1 ] = m.node_list[i].pos[0] - C[0];
                }
            } else {
                for(unsigned i=0;i<m.node_list.size();++i) {
                    for(int j=0;j<dim;++j) {
                        Pvec D = vect_prod( C - m.node_list[i].pos, static_dirac_vec<dim>( 1, j ) );
                        for(int k=0;k<dim;++k)
                            search_dir[ dim + j ][ indice_noda[i] + k ] = D[ k ];
                    }
                }
            }
            
            // system to solve
            Vec<T> F_red; F_red.resize( nb_search_dir );
            Mat<T> M_red( F_red.size() );
            for(unsigned i=0;i<nb_search_dir;++i) {
                F_red[ i ] = dot( F, search_dir[ i ] );
                for(unsigned j=0;j<nb_search_dir;++j)
                    M_red( i, j ) = dot( M * search_dir[ i ], search_dir[ j ] );
            }
            if ( levenberg_marq ) {
                T ni =  norm_inf( M_red.diag() );
                M_red.diag() += levenberg_marq * ( ni + ( ni == 0 ) );
            }
            Vec<T> dU_red = inv( M_red ) * F_red;
            
            // update_mesh ( translation + "true" rotation )
            ExtractDM<NAME_VAR> ed;
            for(int i=0;i<m.node_list.size();++i) {
                Pvec cp = m.node_list[i].pos + ed( m.node_list[i] ) - C, nv = cp;
                for(int j=0;j<1+2*(dim==3);++j)
                    nv += dU_red[ dim + j ] * search_dir[ dim + j ][ indice_noda[i] + range( dim ) ];
                Pvec rot = nv * norm_2( cp, 1e-40 ) / norm_2( nv, 1e-40 ) - cp; // length conservation
                //
                ed( m.node_list[i] ) += rot + dU_red[ range(dim) ];
            }
            
            history_norm_inf_dU.push_back( norm_inf( dU_red ) );
            history_norm_2_dU  .push_back( norm_2  ( dU_red ) );
            if ( display_norm_inf_dU or display_norm_2_dU )
                PRINT( dU_red );
            
            if ( display_iteration_time ) {
                double time_cur = time_of_day_in_sec();
                PRINT( time_cur - time_old );
                time_old = time_cur;
            }

            // convergence
            if ( norm_inf( dU_red ) <= min_norm_inf_dU or norm_2( dU_red ) <= min_norm_2_dU )
                break;
        }
    }
    
    ///
    void solve_linear_system() {
        solve_using_chol_factorize( C_M     , F     , dU      );
    }
    
    ///
    template<class TM,class NAME_VAR_DEPL,class NAME_VAR_GREY> void update_mesh( TM &m, const NAME_VAR_DEPL &name_var_depl, const NAME_VAR_GREY &name_var_grey ) const {
        ExtractDM<NAME_VAR_DEPL> ed_depl;
        ExtractDM<NAME_VAR_GREY> ed_grey;
        for(int i=0;i<m.node_list.size();++i) {
            for(int d=0;d<dim;++d)
                ed_depl( m.node_list[i] )[ d ] += dU[ indice_noda[ i ] + d ];
            ed_grey( m.node_list[i] ) += dU[ indice_noda[ i ] + dim ];
        }
    }
    
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
                            locU_sgn += inv_M( j, dc->indice_noda_depl[ e.node(i)->number ] + d ) * sham_grad;
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
    Vec<T> F, dU;
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
    unsigned div_pixel; /// for "correct" integration. 0 means analytical integration
    bool display_norm_inf_dU; /// display norm_inf( dU ) au cours des itérations, vrai par défaut
    bool display_norm_2_dU; /// display norm_2( dU ) au cours des itérations, faux par défaut
    bool display_iteration_time; ///
};

}

#endif // DIV_CPU_H
