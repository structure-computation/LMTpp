#include "exsolver.h"
#include <math.h>
#include <iostream>
#include <limits>

using namespace std;
using namespace Codegen;

ExSolver::ExSolver(const Ex &equation) {
    objective = abs(equation);
    
    std::set<Ex,Ex::ExMapCmp> sub_symbols;
    equation.get_sub_symbols(sub_symbols);
    for(std::set<Ex,Ex::ExMapCmp>::const_iterator iter=sub_symbols.begin();iter!=sub_symbols.end();++iter)
        symbols.push_back(*iter);
    
    resize( symbols.size(), symbols.size() );
    vec = ExVector::differentiate(equation,symbols);
    mat = ExMatrix::differentiate(vec,symbols);
}

ExSolver::ExSolver(const ExVector &equations) {
    objective = abs(equations).sum();
    
    std::set<Ex,Ex::ExMapCmp> sub_symbols;
    equations.get_sub_symbols(sub_symbols);
    for(std::set<Ex,Ex::ExMapCmp>::const_iterator iter=sub_symbols.begin();iter!=sub_symbols.end();++iter)
        symbols.push_back(*iter);
    
    unsigned l = std::max(equations.size(),symbols.size());
    resize( l, symbols.size() );
        
    vec = equations;
    vec.resize(l);
    mat = ExMatrix::differentiate(vec,symbols);
}

ExSolver::~ExSolver() {
    gsl_matrix_free( gslMat );
    gsl_vector_free( gslVec );
    gsl_matrix_free( V );
    gsl_vector_free( S );
    gsl_vector_free( work );
    gsl_vector_free( X );
}

void ExSolver::resize(unsigned nbLines,unsigned nbCols) {
    nl = nbLines;
    nc = nbCols;
        
    gslMat = gsl_matrix_alloc( nl, nc );
    gslVec = gsl_vector_alloc( nl );
    
    U = gslMat;
    V = gsl_matrix_alloc( nc, nc );
    S = gsl_vector_alloc( nc );
    work = gsl_vector_alloc( nc );
    
    X = gsl_vector_alloc( nc );
}

/// set doubleMat with setVal() on each value of ex matrix
void ExSolver::updateGslData(int level) {
    for(unsigned l=0;l<nl;++l)
        gsl_vector_set( gslVec, l, vec[l].get_val() );
    for(unsigned l=0;l<nl;++l)
        for(unsigned c=0;c<nc;++c)
            gsl_matrix_set( gslMat, l, c, (symbols[c].get_movability_level()>=level ? mat(l,c).get_val() : 0.0 ) );
}

/// return error according to objective function
double ExSolver::iteration(double minRatio,int level,double prec) {
    updateGslData(level);
    
    // SVD    
    gsl_linalg_SV_decomp( U, V, S, work );

    // elimination of nul or quasi-nul values
    double M = 0.0;
    for(unsigned c=0;c<nc;++c)
        M = std::max( M, fabs(gsl_vector_get(S,c)) );
    if ( M <= numeric_limits<double>::epsilon() * 1e3 )
        return -1.0;
    M *= minRatio;
    for(unsigned c=0;c<nc;++c)
        if ( fabs(gsl_vector_get(S,c)) <= M )
            gsl_vector_set( S, c, 1e6 * M );
    
    gsl_linalg_SV_solve (U,V,S,gslVec,X);
    
    
    // update values
    double best_pp = 0.0, best_obj = objective.get_val()-std::numeric_limits<double>::epsilon()*10.0;
    for(double pp=0.2;pp<=1.5;pp+=0.2) {
        // we try
        for(unsigned c=0;c<nc;++c)
            symbols[c].set_val( symbols[c].get_val()-gsl_vector_get( X, c ) * post_mult * pp );
        if ( objective.get_val() < best_obj ) {
            best_pp = pp;
            best_obj = objective.get_val();
        }
        for(unsigned c=0;c<nc;++c)
            symbols[c].set_val( symbols[c].get_val()+gsl_vector_get( X, c ) * post_mult * pp );
    }
    post_mult *= best_pp;
    for(unsigned c=0;c<nc;++c)
        symbols[c].set_val( symbols[c].get_val()-gsl_vector_get( X, c ) * post_mult );

    // return max offset        
    M = 0.0;
    for(unsigned c=0;c<nc;++c)
        M = std::max( M, fabs(gsl_vector_get(X,c)) );
    return M * post_mult;
}

bool ExSolver::solve(double prec,unsigned nb_max_iter) {
    for(int mov_level=3;mov_level>=0;--mov_level) {
        unsigned cpt = 0;
        post_mult = 1.0;
        while( true ) {
            if ( iteration(1e-6,mov_level,prec) <= prec )
                break;
            for(unsigned c=0;c<nc;++c)
                if ( gsl_vector_get(X,c)+1==gsl_vector_get(X,c) ) // test for nan
                    return false;
            if ( ++cpt >= nb_max_iter )
                return false;
        }
        // cout << "#  After " << cpt << " iterations." << endl;
    }
    return true;
}

void ExSolver::displayVec() const {
    for(unsigned c=0;c<nc;++c)
        cout << gsl_vector_get(X,c) << " ";
    cout << endl;
}

void ExSolver::displayMat() const {
    for(unsigned l=0;l<nl;++l) {
        cout << "\t";
        for(unsigned c=0;c<nc;++c)
            cout << gsl_matrix_get(gslMat, l, c ) << "\t";
        cout << endl;
    }
}
