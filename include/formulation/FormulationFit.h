#ifndef LMT_FORMULATION_FIT_H
#define LMT_FORMULATION_FIT_H

namespace LMT {

template<class TF>
struct FormulationFit {
    typedef typename TF::ScalarType ScalarType;
    
    /// for now, assumes matrix of f is symmetric
    FormulationFit( TF &f ) : f( f ) {
        levenberg_marq = 0;
        relaxation = 1;
        conv = 1e-4;
    }
    
    template<class TMAT>
    void exec( const Vec<ScalarType> &exp_val, const TMAT &exp_mat, Vec<ScalarType> sens_val ) {
        if ( sens_val.size() < exp_val.size() )
            sens_val.resize( exp_val.size(), 1.0 );
            
        history.resize( 0 );
        
        f.allocate_matrices();
        f.shift();
        for(unsigned num_iter=0;;++num_iter) {
            f.assemble();
            
            Inv<ScalarType,Sym<>,SparseLine<> > I( f.matrices(Number<0>()) );
            f.vectors[ 0 ] = I * f.sollicitation;
            
            f.update_variables();
            f.call_after_solve();
            
            //
            Vec<Vec<ScalarType>,TF::nb_der_var> der_U;
            for(unsigned i=0;i<TF::nb_der_var;++i) {
                f.assemble_vector_der_var( i );
                der_U[ i ] = I * f.sollicitation;
            }
            //
            Mat<ScalarType> M( TF::nb_der_var );
            Vec<ScalarType,TF::nb_der_var> V;
            for(unsigned i=0;i<TF::nb_der_var;++i) {
                Vec<ScalarType> dUi = exp_mat * der_U[i];
                V[ i ] = dot( dUi, exp_val - f.vectors[0] );
                for(unsigned j=0;j<TF::nb_der_var;++j)
                    M( i, j ) = dot( dUi, der_U[j] );
            }
            
            if ( norm_inf( M.diag() ) == 0 )
                M.diag() = 1.0;
                
            if ( levenberg_marq )
                M.diag() += max( abs( M.diag() ) ) * levenberg_marq;
            
            //
            Inv<ScalarType> IM( M );
            Vec<ScalarType> dD = IM * V;
            PRINT( dD );
            
            history.push_back( norm_inf( dD ) );
            TF::Carac::add_to_der_vars( f, dD );
            
            if ( all( abs( dD ) < conv ) or num_iter == 20 ) {
                // sensitivity analysis
                Mat<ScalarType> du_exp_mat( TF::nb_der_var, f.sollicitation.size() );
                for(unsigned r=0;r<TF::nb_der_var;++r)
                    du_exp_mat.row( r ) = exp_mat * der_U[r];
                Mat<ScalarType> Minv_du_exp_mat( TF::nb_der_var, f.sollicitation.size() );
                for(unsigned c=0;c<f.sollicitation.size();++c)
                    Minv_du_exp_mat.col( c ) = IM * du_exp_mat.col( c );
                    
                //
                sensitivity_after_fit.resize( TF::nb_der_var );
                for(unsigned i=0;i<TF::nb_der_var;++i)
                    sensitivity_after_fit[ i ] = sum( abs( sens_val * Minv_du_exp_mat.row( i ) ) );
                    
                //
                break;
            }
        }
    }
    
    TF &f;
    
    // inputs
    ScalarType levenberg_marq;
    Vec<ScalarType,TF::nb_der_var> relaxation; // U += relaxation * dU;
    Vec<ScalarType,TF::nb_der_var> conv; // norm_inf( dParams ) < conv => convergence
    
    // outputs
    Vec<ScalarType> history;
    Vec<ScalarType> sensitivity_after_fit;
};

}


#endif // LMT_FORMULATION_FIT_H
