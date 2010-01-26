#include <correlation/DicCPU.h>
#include "pb_dep_cor.h"
#include <mesh/make_mesh_from_mask.h>
#include <mesh/refinement.h>

using namespace LMT;

struct Refinment {
    Refinment() : r("Croix/refinment.png") {}
    template<class TE> double operator()( const TE &e ) const { return 0.5 * ( r( center( e ) ) < measure( e ) ); }
    ImgInterp<float,2> r;
};

int main( int argc, char **argv ) {
    typedef Mesh<Mesh_carac_pb_dep_cor<double,2> > TM;
    typedef TM::Pvec Pvec;
    typedef Formulation<TM,elasticity_dep> TF;

    ImgInterp<float,2> f( "Croix/composite00.png" );
    ImgInterp<float,2> g( "Croix/composite01.png" );

    TM m;
    make_mesh_from_mask( "Croix/masque_0.png", m, 60 );

    // dep from regular mesh
    DicCPU<float,2> dic;
    dic.nb_threads_for_assembly = 8;
    dic.min_norm_inf_dU = 1e-2;
    //    dic.multi_resolution = 1;
    //    dic.exec_rigid_body( f, g, m, dep_DM(), lum_DM() );
    dic.multi_resolution = 0;
    dic.exec( f, g, m, dep_DM(), lum_DM() );

    //    dic.display_residual_img( f, g, m, dep_DM(), lum_DM(), false, "cours_FH_dic_residual.png" );

    // refinment
    Refinment refi;
    while( refinement( m, refi ) );

    display( m, "croix.pvsm" );

    
    
    // contraintes
    TF formulation( m );
    m.update_skin();
    double min_node_dist = m.skin.min_node_dist() * 0.9;
    TM::Pvec mi, ma, me;
    get_min_max( generate( m.node_list, ExtractDM<pos_DM>() ), mi, ma );
    mi += min_node_dist;
    ma -= min_node_dist;
    for(unsigned i=0;i<m.node_list.size();++i)
        if ( m.node_list[i].pos[0] < mi[0] or m.node_list[i].pos[1] < mi[1] or m.node_list[i].pos[0] > ma[0] or m.node_list[i].pos[1] > ma[1] )
            for(int d=0;d<2;++d)
                formulation.add_constraint( "node[" + to_string( i ) + "].dep[" + to_string( d ) + "] - " + to_string( m.node_list[i].dep[d] ), 1e5 );

    // -> indice_noda
    dic.assemble( f, g, m, dep_DM(), lum_DM() );

    //
    while ( true ) {
        // get derivatives
        Vec<Vec<double> > der_for, der_dic;
        formulation.solve_and_get_derivatives( der_for );
        der_dic.resize( der_for.size() );
        for(unsigned i=0;i<der_for.size();++i) {
            der_dic[ i ].resize( dic.F.size(), 0.0 );
            for(unsigned n=0;n<m.node_list.size();++n)
                for(int d=0;d<2;++d)
                    der_dic[ i ][ dic.indice_noda[ n ] + d ] = der_for[ i ][ (*formulation.indice_noda)[ n ] + d ];
        }

        //formulation.get_der_var_on_mesh( 0 );
        //display( m );

        // get M and F
        dic.assemble( f, g, m, dep_DM(), lum_DM() );
        PRINT( dic.adimensioned_residual );

        //
        Mat<double,Sym<>,SparseLine<> > M( der_dic.size() );
        Vec<double> V; V.resize( der_dic.size(), 0 );
        for(unsigned i=0;i<der_dic.size();++i) {
            V[ i ] += dot( der_dic[ i ], dic.F );
            for(unsigned j=0;j<=i;++j)
                M( i, j ) += dot( der_dic[ j ], dic.M * der_dic[ i ] );
        }

        Vec<double> dD = inv( M ) * V;
        PRINT( dD );
        TF::Carac::add_to_der_vars( formulation, dD );

        dic.dU.resize( dic.F.size() );
        dic.dU.set( 0.0 );
        for(unsigned i=0;i<der_dic.size();++i)
            dic.dU += dD[ i ] * der_dic[ i ];
        dic.update_mesh( m, dep_DM(), lum_DM() );

        if ( norm_2( dD ) <= 1e-2 )
            break;
    }


    //    dic.display_residual_img( f, g, m, dep_DM(), lum_DM(), false, "cours_FH_idic_R.png" );
    //     dic.assemble( f, g, m, dep_DM(), lum_DM() );
    //     PRINT( dic.adimensioned_residual );
    //     PRINT( m.poisson_ratio );
    display( m, "croix.pvsm" );
}


