#ifndef DIV_CPU_H
#define DIV_CPU_H

#include "ImgInterp.h"
#include <containers/mat.h>
#include <util/rectilinear_iterator.h>
#include <util/symamd.h>
#include <mesh/make_rect.h>
#include <formulation/FormulationFit.h>
#include <QtCore/QMutex>
#include <formulation/formulation.h>
#include "mesh_carac_correlation.h"
// #include "containers/eig_lapack.h"
// #include <correlation/pixelotomie.h>

namespace LMT {

///
template<class TE,class  TIMG_f,class TIMG_g,class TM,class TV,class T> void dic_elem_matrix( const TE &elem, const TIMG_f &f, const TIMG_g &g, TM &M, TV &V, int x, int y, StructForType<T> ) {
    assert( 0 );
}
template<class TE,class TIMG_f,class TIMG_g,class TDIC,class Pvec,class T,class MT>
void dic_elem_matrix_( const TE &elem, const TIMG_f &f, const TIMG_g &g, TDIC &dic, const Pvec &MI, const Pvec &MA, StructForType<T>, MT &mutex ) {
    assert( 0 );
}

/*!
    Corrélation sur CPU

    Il faut spécifier un critère d'arrêt avant exec ou exec_rigid_body (min_norm_inf_dU ou min_norm_2_dU par exemple).

    On a besoin de QtGui et de QtCore dans les librairies.
*/
template<class T,unsigned dim,bool want_lum_corr=true>
struct DicCPU {
    typedef Mesh<Mesh_carac_pb_correlation_basic<double,dim> > TM_exemple; ///
    typedef Vec<T,dim> Pvec;

    struct ShapeFunctionAncestor {
        virtual unsigned size() const = 0;
        virtual Pvec operator()( Pvec pos, int i ) const = 0;
        virtual bool mask( Pvec pos, int i ) const = 0;
    };

    ///
    DicCPU() {
        levenberg_marq = 0.0;
        nb_threads_for_assembly = 1;
        div_pixel = 1;
        delta_gray = 1;
        relaxation = 1;
        max_cpt_iter = 50;
        min_norm_inf_dU = 0;
        min_norm_2_dU = 0;
        display_norm_inf_dU = true;
        display_norm_2_dU = false;
        display_iteration_time = false;
        multi_resolution = 0;
        remove_eig_val_if_lower_than = 0;
        want_epsilon = true;
        importance_pixelotomy = 0;
        importance_pixelotomy[0] = 1;
        pond_surf = 1000;
    }

    ///
    template<class NAME_VAR_DEPL,class NAME_VAR_GREY,bool use_g_as_ref>
    struct Assemble {
        template<class TE,class TIMGf,class TIMGg> void operator()( const TE &e, DicCPU &dic, const TIMGf &f, const TIMGg &g ) {
            Vec<T,dim> P[TE::nb_nodes], D[TE::nb_nodes], MA( e.pos(0) ), MI( e.pos(0) );
            for(unsigned i=0;i<TE::nb_nodes;++i) P[ i ] = e.pos(i) + ed_depl( *e.node(i) ) * ( 0 + use_g_as_ref );
            for(unsigned i=0;i<TE::nb_nodes;++i) D[ i ] = e.pos(i) + ed_depl( *e.node(i) ) * ( 1 - use_g_as_ref );
            for(unsigned i=1;i<TE::nb_nodes;++i) MI = min( MI, P[ i ] ); // hum
            for(unsigned i=1;i<TE::nb_nodes;++i) MA = max( MA, P[ i ] ); // hum
            f.load_if_necessary( MI, MA );
            g.load_if_necessary( MI, MA );

            double sum_abs_diff_fg  = 0;
            double sum_sq_diff_fg   = 0;
            double nb_covered_pixel = 0;
            double min_f = +std::numeric_limits<T>::max();
            double max_f = -std::numeric_limits<T>::max();

            if ( dic.div_pixel < 0 ) {
                dic_elem_matrix_( e, f, g, dic, MI, MA, StructForType<T>(), mutex );
            } else {
                unsigned nb_ddl_fe = ( dim + want_lum_corr ) * TE::nb_nodes;
                unsigned s = nb_ddl_fe + dic.sum_nb_additional_shape_functions();
                Vec<T> F; F.resize( s, 0 );
                Mat<T> M( s, s ); M.set( 0 );
                //
                if ( dic.div_pixel == 0 ) {
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
                        for(unsigned i=0;i<TE::nb_nodes;++i)
                            val_grey += shape_functions[ i ] * ed_grey( *e.node(i) ); // dic.U_grey[ dic.indice_noda_grey[ e.node( i )->number ] ];

                        //
                        Vec<T,dim> DO;
                        get_interp( typename TE::NE(), Nodal(), var_inter, D, DO );

                        bool want_FE = true;
                        for(unsigned n=0,c=0;n<dic.additional_shape_functions.size();++n) {
                            for(unsigned i=0;i<dic.additional_shape_functions[n]->size();++i,++c) {
                                if ( dic.additional_shape_functions[n]->mask( p.pos, i ) ) {
                                    if ( want_FE ) {
                                        DO = p.pos;
                                        want_FE = false;
                                    }
                                    DO += dic.coeffs_additional_shape_functions[ c ] *
                                        dic.additional_shape_functions[n]->operator()( p.pos, i );
                                }
                            }
                        }

                        Vec<T,dim> PF( use_g_as_ref ? DO : p.pos );
                        Vec<T,dim> PG( use_g_as_ref ? p.pos : DO );
                        T val_f = f( PF );
                        T val_g = val_grey * g( PG );
                        Vec<T,dim> grad = 0.5 * ( f.grad( PF ) + val_grey * g.grad( PG ) );
                        T diff_fg = val_f - val_g;

                        //
                        //if ( want_FE ) {
                        unsigned sum_non_integer = 0;
                        for(unsigned i=0;i<p.pos.size();++i)
                            sum_non_integer += ( abs( round( p.pos[i] ) - p.pos[i] ) > 0.1 );
                        T imp = dic.importance_pixelotomy[ sum_non_integer ];

                        // dU part
                        Vec<T,dim*TE::nb_nodes> sham_grad;
                        for(unsigned i=0,n=0;i<TE::nb_nodes;++i)
                            for(unsigned d=0;d<dim;++d,++n)
                                sham_grad[ n ] = shape_functions[ i ] * grad[ d ];

                        // dU part
                        double pond_FE = ( want_FE ? 1.0 : 1e-3 );
                        for(unsigned i=0;i<TE::nb_nodes;++i) {
                            for(unsigned d=0;d<dim;++d) {
                                F[ i * ( dim + want_lum_corr ) + d ] += pond_FE * imp * sham_grad[ i * dim + d ] * diff_fg;
                                for(unsigned j=0;j<TE::nb_nodes;++j)
                                    for(unsigned c=0;c<dim;++c)
                                        M( i * ( dim + want_lum_corr ) + d, j * ( dim + want_lum_corr ) + c ) += pond_FE * imp * sham_grad[ i * dim + d ] * sham_grad[ j * dim + c ];
                            }
                        }

                        // dG part
                        Vec<T,TE::nb_nodes> sham_grey;
                        for(unsigned i=0;i<TE::nb_nodes;++i)
                            sham_grey[ i ] = shape_functions[ i ] * val_g;

                        if ( want_lum_corr ) {
                            for(unsigned i=0;i<TE::nb_nodes;++i) {
                                for(unsigned j=0;j<TE::nb_nodes;++j)
                                    M( i * ( dim + 1 ) + dim, j * ( dim + 1 ) + dim ) += imp * sham_grey[ i ] * sham_grey[ j ];
                                F[ i * ( dim + 1 ) + dim ] += imp * sham_grey[ i ] * diff_fg;
                            }
                        }

                        if ( want_FE == false ) {
                            // additional_shape_functions
                            for(unsigned n0=0,c0=nb_ddl_fe;n0<dic.additional_shape_functions.size();++n0) {
                                for(unsigned i0=0;i0<dic.additional_shape_functions[n0]->size();++i0,++c0) {
                                    if ( dic.additional_shape_functions[n0]->mask( p.pos, i0 ) ) {
                                        F[ c0 ] += dot( dic.additional_shape_functions[n0]->operator()( p.pos, i0 ), grad ) * diff_fg;
                                        for(unsigned n1=0,c1=nb_ddl_fe;n1<dic.additional_shape_functions.size();++n1) {
                                            for(unsigned i1=0;i1<dic.additional_shape_functions[n1]->size();++i1,++c1) {
                                                M( c0, c1 ) += dot( dic.additional_shape_functions[n0]->operator()( p.pos, i0 ), grad ) *
                                                dot( dic.additional_shape_functions[n1]->operator()( p.pos, i1 ), grad );
                                            }
                                        }
                                    }
                                }
                            }

                            // glue
                            bool has_want_FE_neighbors = false;
                            for( Rectilinear_iterator<T,dim> o( Pvec(p.pos-1), Pvec(p.pos) + 2 ); o; ++o ) {
                                if ( o != p ) {
                                    for(unsigned n0=0,c0=nb_ddl_fe;n0<dic.additional_shape_functions.size();++n0) {
                                        for(unsigned i0=0;i0<dic.additional_shape_functions[n0]->size();++i0,++c0) {
                                            if ( dic.additional_shape_functions[n0]->mask( p.pos, i0 ) == false ) {
                                                has_want_FE_neighbors = true;
                                                break; // TODO: optimize
                                            }
                                        }
                                    }
                                }
                            }
                            //
                            if ( has_want_FE_neighbors ) {
                                // W_i * W_j
                                for(unsigned n0=0,c0=nb_ddl_fe;n0<dic.additional_shape_functions.size();++n0)
                                    for(unsigned i0=0;i0<dic.additional_shape_functions[n0]->size();++i0,++c0)
                                        for(unsigned n1=0,c1=nb_ddl_fe;n1<dic.additional_shape_functions.size();++n1)
                                            for(unsigned i1=0;i1<dic.additional_shape_functions[n1]->size();++i1,++c1)
                                                M( c0, c1 ) += dic.pond_surf * dot( dic.additional_shape_functions[n0]->operator()( p.pos, i0 ),
                                                               dic.additional_shape_functions[n1]->operator()( p.pos, i1 ) );
                                // N_i * N_j
                                for(unsigned i0=0,n0=0;i0<TE::nb_nodes;++i0)
                                    for(unsigned d0=0;d0<dim;++d0,++n0)
                                        for(unsigned i1=0,n1=0;i1<TE::nb_nodes;++i1)
                                            for(unsigned d1=0;d1<dim;++d1,++n1)
                                                M( n0, n1 ) += dic.pond_surf * shape_functions[ i0 ] * shape_functions[ i1 ];
                                // N_i * W_j
                                for(unsigned i0=0,n0=0;i0<TE::nb_nodes;++i0) {
                                    for(unsigned d0=0;d0<dim;++d0,++n0) {
                                        for(unsigned n1=0,c1=nb_ddl_fe;n1<dic.additional_shape_functions.size();++n1) {
                                            for(unsigned i1=0;i1<dic.additional_shape_functions[n1]->size();++i1,++c1) {
                                                T res = dic.pond_surf * shape_functions[ i0 ] * dic.additional_shape_functions[n1]->operator()( p.pos, i1 )[ d0 ];
                                                M( n0, c1 ) += res;
                                                M( c1, n0 ) += res;
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        // residual
                        sum_abs_diff_fg += abs( diff_fg );
                        sum_sq_diff_fg  += pow( diff_fg, 2 );
                        nb_covered_pixel++;
                        min_f = min( min_f, val_f );
                        max_f = max( max_f, val_f );
                    }
                }


                //
                mutex.lock();

                dic.sum_abs_diff_fg  += sum_abs_diff_fg;
                dic.sum_sq_diff_fg   += sum_sq_diff_fg;
                dic.nb_covered_pixel += nb_covered_pixel;
                dic.min_f = min( dic.min_f, min_f );
                dic.max_f = max( dic.max_f, max_f );

                if ( want_mat ) {
                    for(unsigned i=0,n=0;i<TE::nb_nodes;++i)
                        for(unsigned d=0;d<dim+want_lum_corr;++d,++n)
                            for(unsigned j=0,m=0;j<TE::nb_nodes;++j)
                                for(unsigned c=0;c<dim+want_lum_corr;++c,++m)
                                    if ( n <= m )
                                        dic.M( dic.indice_noda[ e.node(i)->number ] + d, dic.indice_noda[ e.node(j)->number ] + c ) += M( n, m );
                    for(unsigned i=0;i<dic.sum_nb_additional_shape_functions();++i)
                        for(unsigned j=0;j<=i;++j)
                            dic.M( dic.indice_additional_shape_functions + i, dic.indice_additional_shape_functions + j ) +=
                                    M( nb_ddl_fe + i, nb_ddl_fe + j );

                }

                if ( want_vec ) {
                    for(unsigned i=0,n=0;i<TE::nb_nodes;++i)
                        for(unsigned d=0;d<dim+want_lum_corr;++d,++n)
                            dic.F[ dic.indice_noda[ e.node(i)->number ] + d ] += F[ n ];
                    for(unsigned i=0;i<dic.sum_nb_additional_shape_functions();++i)
                        dic.F[ dic.indice_additional_shape_functions + i ] += F[ nb_ddl_fe + i ];
                }

                mutex.unlock();
            }
        }
        bool want_mat, want_vec;
        QMutex mutex;
        ExtractDM<NAME_VAR_DEPL> ed_depl;
        ExtractDM<NAME_VAR_GREY> ed_grey;
    };

    ///
    template<class NAME_VAR_DEPL,class NAME_VAR_GREY>
    struct MakeDefImg {
        template<class TE,class TIMGf,class TIMGr> void operator()( const TE &e, const TIMGf &f, TIMGr &r, const DicCPU &dic ) const {
            ExtractDM<NAME_VAR_DEPL> ed;
            ExtractDM<NAME_VAR_GREY> eg;
            Vec<T,dim> P[TE::nb_nodes], D[TE::nb_nodes], MA( e.pos(0) + ed( *e.node(0) ) ), MI( e.pos(0) + ed( *e.node(0) ) );
            T G[TE::nb_nodes];
            for(unsigned i=0;i<TE::nb_nodes;++i) P[ i ] = e.pos(i);
            for(unsigned i=0;i<TE::nb_nodes;++i) D[ i ] = e.pos(i) + ed( *e.node(i) );
            for(unsigned i=0;i<TE::nb_nodes;++i) G[ i ] = eg( *e.node(i) );
            for(unsigned i=1;i<TE::nb_nodes;++i) MI = min( MI, D[ i ] ); // hum (won't work e.g. for Triangle_6...)
            for(unsigned i=1;i<TE::nb_nodes;++i) MA = max( MA, D[ i ] ); // hum (won't work e.g. for Triangle_6...)
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

                bool want_FE = true;
                for(unsigned n=0,c=0;n<dic.additional_shape_functions.size();++n) {
                    for(unsigned i=0;i<dic.additional_shape_functions[n]->size();++i,++c) {
                        if ( dic.additional_shape_functions[n]->mask( p.pos, i ) ) {
                            if ( want_FE ) {
                                O = p.pos;
                                want_FE = false;
                            }
                            O += dic.d_coeffs_additional_shape_functions[ c ] * dic.additional_shape_functions[n]->operator()( p.pos, i );
                        }
                    }
                }

                //
                T g;
                get_interp( typename TE::NE(), Nodal(), var_inter, G, g );
                r.tex_int( p.pos ) = g * f( O );
            }
        }
    };

    unsigned sum_nb_additional_shape_functions() const {
        unsigned res = 0;
        for(unsigned n=0;n<additional_shape_functions.size();++n)
            res += additional_shape_functions[ n ]->size();
        return res;
    }

    /// toto
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR_DEPL,class NAME_VAR_GREY>
    void assemble( const TIMGf &f, const TIMGg &g, const TM &m, const NAME_VAR_DEPL &name_var_depl, const NAME_VAR_GREY &name_var_grey, bool want_mat = true, bool want_vec = true, int resol_level = 0 ) {
        unsigned nb_ddl_fe = ( dim + want_lum_corr ) * m.node_list.size();
        unsigned nb_ddl = nb_ddl_fe + sum_nb_additional_shape_functions();
        if ( want_mat ) {
            indice_noda = ( dim + want_lum_corr ) * symamd( m );
            indice_additional_shape_functions = nb_ddl_fe;

            M.clear();
            M.resize( nb_ddl );
        }
        if ( want_vec ) {
            F.resize( nb_ddl );
            F.set( 0.0 );
        }

        coeffs_additional_shape_functions.resize( sum_nb_additional_shape_functions(), 0 );
        d_coeffs_additional_shape_functions.resize( sum_nb_additional_shape_functions(), 0 );

        sum_abs_diff_fg  = 0;
        sum_sq_diff_fg   = 0;
        nb_covered_pixel = 0;
        min_f = +std::numeric_limits<T>::max();
        max_f = -std::numeric_limits<T>::max();

        //
        Assemble<NAME_VAR_DEPL,NAME_VAR_GREY,false> ass_2;
        ass_2.want_mat = want_mat;
        ass_2.want_vec = want_vec;
        apply_mt( m.elem_list, nb_threads_for_assembly, ass_2, *this, f, g );

        //
        if ( want_mat ) {
            //             if ( remove_eig_val_if_lower_than ) {
            //                 Vec<double> eig_val;
            //                 Mat<double> eig_vec;
            //                 get_eig_sym( M, eig_val, eig_vec );
            //                 PRINT( eig_val );
            //                 for(unsigned i=0;i<eig_val.size()-1;++i)
            //                     if ( eig_val[i] < remove_eig_val_if_lower_than )
            //                         for(unsigned j=0;j<M.nb_rows();++j)
            //                             for(unsigned k=0;k<M.nb_cols();++k)
            //                                 M( j, k ) += remove_eig_val_if_lower_than * eig_vec[j] * eig_vec[k];
            //             }
            if ( levenberg_marq ) {
                //T ni =  norm_inf( M.diag() );
                M.diag() += levenberg_marq; // * ( ni + ( ni == 0 ) );
            }

            C_M = M;
            //double max_diag = norm_inf( M.diag() );
            //for(unsigned i=0;i<M.nb_rows();++i)
            //   C_M( i, i ) += 1e6 * pond_surf * ( C_M( i, i ) < 1e-3 * max_diag );
            //C_M( i, i ) += ;

            // double t0 = time_of_day_in_sec();
            chol_factorize( C_M );
            // incomplete_chol_factorize( C_M );
            // t1 += time_of_day_in_sec() - t0;
        }

        adimensioned_residual = sqrt( sum_sq_diff_fg ) / ( max_f - min_f ) / nb_covered_pixel;
    }

    /// resol_level must be managed internally
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR_DEPL,class NAME_VAR_GREY>
    bool exec( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR_DEPL &name_var_depl, const NAME_VAR_GREY &name_var_grey, bool want_mat = true, bool want_vec = true, int resol_level = 0 ) {
        if ( min_norm_inf_dU == 0 and min_norm_2_dU == 0 )
            std::cerr << "Il faut préciser au moins un critère d'arrêt (ex : min_norm_inf_dU ou min_norm_2_dU)." << std::endl;

        if ( resol_level < multi_resolution ) {
            ExtractDM<NAME_VAR_DEPL> pd;
            for(unsigned i=0;i<m.node_list.size();++i) {
                m.node_list[i].pos -= 0.5;
                m.node_list[i].pos /= 2;
                pd( m.node_list[i] ) /= 2;
                coeffs_additional_shape_functions /= 2;
            }
            exec( f.pyramidal_filter(), g.pyramidal_filter(), m, name_var_depl, name_var_grey, want_mat, want_vec, resol_level + 1 );
            for(unsigned i=0;i<m.node_list.size();++i) {
                m.node_list[i].pos *= 2;
                m.node_list[i].pos += 0.5;
                pd( m.node_list[i] ) *= 2;
                coeffs_additional_shape_functions *= 2;
            }
        }
        //
        for(cpt_iter=0;;++cpt_iter) {
            if ( cpt_iter == max_cpt_iter ) {
                std::cerr << "Convergence pb." << std::endl;
                break;
            }
            double time_old = time_of_day_in_sec();

            assemble( f, g, m, name_var_depl, name_var_grey, want_mat, want_vec, resol_level );

            // simple break conditions
            if ( want_vec == false or ( min_norm_inf_dU == 0 and min_norm_2_dU == 0 ) ) {
                std::cout << "iter=" << cpt_iter << " adimensioned_residual=" << adimensioned_residual << std::endl;
                break;
            }

            solve_linear_system();

            if ( display_iteration_time ) {
                double time_cur = time_of_day_in_sec();
                PRINT( time_cur - time_old );
                time_old = time_cur;
            }

            //
            dU *= relaxation;

            //PRINT( M );
            //PRINT( F );
            //PRINT( dU );

            update_mesh( m, name_var_depl, name_var_grey );
            for(unsigned i=0;i<sum_nb_additional_shape_functions();++i) {
                d_coeffs_additional_shape_functions[ i ] = dU[ indice_additional_shape_functions + i ];
                coeffs_additional_shape_functions[ i ] += d_coeffs_additional_shape_functions[ i ];
            }

            //
            history_norm_inf_dU.push_back( norm_inf( dU ) );
            history_norm_2_dU  .push_back( norm_2  ( dU ) );
            if ( display_norm_inf_dU )
                std::cout << "iter=" << cpt_iter << " norm_inf(dU)=" << norm_inf( dU ) << " adimensioned_residual=" << adimensioned_residual << std::endl;
            if ( display_norm_2_dU )
                std::cout << "iter=" << cpt_iter << " norm_2(dU)="   << norm_2( dU )   << " adimensioned_residual=" << adimensioned_residual << std::endl;

            // convergence
            if ( norm_inf( dU ) <= min_norm_inf_dU or norm_2( dU ) <= min_norm_2_dU )
                break;

            if ( name_tmp_paraview_file.size() ) {
                std::ofstream fout( ( name_tmp_paraview_file + to_string( cpt_iter ) + ".vtu" ).c_str() );
                write_mesh_vtk<true>( fout, m );
            }
        }

        //
        if ( resol_level == 0 and want_epsilon ) {
            get_epsilon( m );
        }
        return cpt_iter < max_cpt_iter;
    }

    /// fill epsilon field in TM
    template<class TM>
    void get_epsilon( TM &m ) {
        Formulation< TM, correlation_basic > f( m );
        f.call_after_solve();
    }

    template<class TIMGf,class TIMGg,class TM,class NAME_VAR_DEPL,class NAME_VAR_GREY>
    void exec_rigid_body( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR_DEPL &name_var_depl, const NAME_VAR_GREY &name_var_grey, bool want_mat = true, bool want_vec = true, int resol_level = 0 ) {
        const unsigned nb_search_dir = 3 + 3 * ( dim == 3 );
        U_red.resize( nb_search_dir );
        U_red.set( 0.0 );
        //
        if ( resol_level < multi_resolution ) {
            ExtractDM<NAME_VAR_DEPL> pd;
            for(unsigned i=0;i<m.node_list.size();++i) {
                m.node_list[i].pos   /= 2;
                pd( m.node_list[i] ) /= 2;
                U_red                /= 2;
            }
            exec_rigid_body( f.pyramidal_filter(), g.pyramidal_filter(), m, name_var_depl, name_var_grey, want_mat, want_vec, resol_level + 1 );
            for(unsigned i=0;i<m.node_list.size();++i) {
                m.node_list[i].pos   *= 2;
                pd( m.node_list[i] ) *= 2;
                U_red                *= 2;
            }
        }
        //
        typedef typename TM::Pvec Pvec;
        double time_old = time_of_day_in_sec();
        for(cpt_iter=0;;++cpt_iter) {
            if ( cpt_iter == max_cpt_iter ) {
                std::cerr << "Convergence pb." << std::endl;
                break;
            }
            assemble( f, g, m, name_var_depl, name_var_grey, want_mat, want_vec, resol_level );
            // simple break conditions
            if ( want_vec == false or ( min_norm_inf_dU == 0 and min_norm_2_dU == 0 ) ) {
                std::cout << "iter=" << cpt_iter << " adimensioned_residual=" << adimensioned_residual << std::endl;
                break;
            }

            // search_dir
            Pvec C = center( m );
            Vec<Vec<T>,nb_search_dir> search_dir;
            for(unsigned i=0;i<nb_search_dir;++i)
                search_dir[ i ].resize( F.size(), 0 );
            for(unsigned i=0;i<m.node_list.size();++i)
                for(unsigned j=0;j<dim;++j)
                    for(unsigned k=0;k<dim;++k)
                        search_dir[ j ][ indice_noda[i] + k ] = ( j == k );
            if ( dim == 2 ) {
                for(unsigned i=0;i<m.node_list.size();++i) {
                    search_dir[ 2 ][ indice_noda[i] + 0 ] = C[1] - m.node_list[i].pos[1];
                    search_dir[ 2 ][ indice_noda[i] + 1 ] = m.node_list[i].pos[0] - C[0];
                }
            } else {
                for(unsigned i=0;i<m.node_list.size();++i) {
                    for(unsigned j=0;j<dim;++j) {
                        Pvec D = vect_prod( C - m.node_list[i].pos, static_dirac_vec<dim>( 1, j ) );
                        for(unsigned k=0;k<dim;++k)
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
            Vec<T> dU_red = inv( M_red ) * F_red;
            U_red += dU_red;

            // update_mesh ( translation + "true" rotation )
            ExtractDM<NAME_VAR_DEPL> ed;
            for(unsigned i=0;i<m.node_list.size();++i) {
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
                std::cout << "iter=" << cpt_iter << " dU_red=" << dU_red << " adimensioned_residual=" << adimensioned_residual << std::endl;

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
        solve_using_chol_factorize( C_M, F, dU );
        // solve_using_incomplete_chol_factorize( C_M, M, F, dU, 1e-2, true );
    }

    ///
    template<class TM,class NAME_VAR_DEPL,class NAME_VAR_GREY> void update_mesh( TM &m, const NAME_VAR_DEPL &name_var_depl, const NAME_VAR_GREY &name_var_grey ) const {
        ExtractDM<NAME_VAR_DEPL> ed_depl;
        ExtractDM<NAME_VAR_GREY> ed_grey;
        for(unsigned nn=0;nn<m.node_list.size();++nn) {
            bool want_FE = true;
            for(unsigned n=0,c=0;n<additional_shape_functions.size();++n) {
                for(unsigned i=0;i<additional_shape_functions[n]->size();++i,++c) {
                    if ( additional_shape_functions[n]->mask( m.node_list[nn].pos, i ) ) {
                        want_FE = false;
                        ed_depl( m.node_list[nn] ) += d_coeffs_additional_shape_functions[ c ] * additional_shape_functions[n]->operator()( m.node_list[nn].pos, i );
                    }
                }
            }
            //
            if ( want_FE )
                for(unsigned d=0;d<dim;++d)
                    ed_depl( m.node_list[nn] )[ d ] += dU[ indice_noda[ nn ] + d ];
            if ( want_lum_corr )
                ed_grey( m.node_list[nn] ) += dU[ indice_noda[ nn ] + dim ];
        }
    }

    ///
    template<class TIMGf,class TM,class NAME_VAR_DEPL,class NAME_VAR_GREY,class TIMGr>
    void get_def_img( const TIMGf &f, TM &m, const NAME_VAR_DEPL &name_var_depl, const NAME_VAR_GREY &name_var_grey, TIMGr &r ) {
        r.resize( f.sizes );
        r.set( -1 );
        apply( m.elem_list, MakeDefImg<NAME_VAR_DEPL,NAME_VAR_GREY>(), f, r, *this );
    }

    ///
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR_DEPL,class NAME_VAR_GREY,class TIMGr>
    void get_residual_img( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR_DEPL &name_var_depl, const NAME_VAR_GREY &name_var_grey, TIMGr &r ) {
        get_def_img( f, m, name_var_depl, name_var_grey, r );
        for( Rectilinear_iterator<int,dim> p( 0, Vec<int,dim>( f.sizes - 1 ), 1 ); p; ++p ) {
            g.load_if_necessary( p.pos, p.pos );
            r.load_if_necessary( p.pos, p.pos, true );
            r.tex_int( p.pos ) = ( r.tex_int( p.pos ) >= 0 ? abs( r.tex_int( p.pos ) - g.tex_int( p.pos ) ) : -1 );
        }
    }

    ///
    template<class TIMGf,class TIMGg,class TM,class NAME_VAR_DEPL,class NAME_VAR_GREY>
    void display_residual_img( const TIMGf &f, const TIMGg &g, TM &m, const NAME_VAR_DEPL &name_var_depl, const NAME_VAR_GREY &name_var_grey, bool want_high_contrast = true, const std::string &filename = "residual.png" ) {
        ImgInterp<T,dim> r;
        get_residual_img( f, g, m, name_var_depl, name_var_grey, r );
        r.display( want_high_contrast, filename );
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
    Mat<T,Sym<>,SparseLine<> > M; /// matrice de corrélation
    Mat<T,Sym<>,SparseLine<> > C_M; /// cholesky de M
    Vec<int> indice_noda; /// numéro de noeud -> positionnement dans la matrice. Les ddl sont organisé par blocs
        /// nb ddl = nb_dim + 1 si calcul de luminosité
    int indice_additional_shape_functions;
    Vec<T> F; /// second membre
    Vec<T> dU; /// dernière itération (inclus la luminosité)
    T sum_abs_diff_fg; // sum_{for each pixel i} | f( x_i + d_i ) - g( x_i ) |
    T sum_sq_diff_fg ; // sum_{for each pixel i} ( f( x_i + d_i ) - g( x_i ) ) ^ 2
    T adimensioned_residual; // sqrt( sum_{for each pixel i} ( f( x_i + d_i ) - a_i * g( x_i ) ) ^ 2 ) / ( max( f ) - min( f ) ) / nb_covered_pixels
    int nb_covered_pixel;
    T min_f, max_f;
    unsigned cpt_iter; // nombre d'itérations pour converger lors du précédent exec (valable aussi pour exec_rigid_body)
    Vec<T> history_norm_inf_dU;
    Vec<T> history_norm_2_dU;
    T pond_surf; /// penalty coeff for the surfacic glue

    // input
    T levenberg_marq;
    T relaxation;
    Vec<T,3> importance_pixelotomy;
    T delta_gray; /// erreur capteur
    T min_norm_inf_dU; /// norm_inf( dU ) < min_norm_inf_dU pour que ça s'arrête
    T min_norm_2_dU; /// à moins que norm_2( dU ) < min_norm_2_dU
    unsigned max_cpt_iter; /// à moins que nb_iter >= max_cpt_iter
    unsigned nb_threads_for_assembly;
    int div_pixel; /// for "correct" integration. 0 means analytical integration
    bool display_norm_inf_dU; /// affiche norm_inf( dU ) au cours des itérations, vrai par défaut
    bool display_norm_2_dU; /// affiche norm_2( dU ) au cours des itérations, faux par défaut
    bool display_iteration_time; ///
    int multi_resolution; /// div = 2^multi_resolution meaning that 0 = no multi res.
    std::string name_tmp_paraview_file; /// base name to save intermediate results during iterations
    T remove_eig_val_if_lower_than;
    bool want_epsilon; /// true by default
    Vec<T> U_red; /// vector result of exec_rigid_body
    Vec<ShapeFunctionAncestor *> additional_shape_functions;
    Vec<double> coeffs_additional_shape_functions;
    Vec<double> d_coeffs_additional_shape_functions;
};

}

#endif // DIV_CPU_H
