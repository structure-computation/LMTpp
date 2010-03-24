#ifndef CODEGEN_EXSOLVER_H
#define CODEGEN_EXSOLVER_H

#include "exmatrix.h"
#include <gsl/gsl_linalg.h>
    
namespace Codegen {

/*!
    Cette classe sert pour le calcul symbolique des formulations écrites en Python.

    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \author LECLERC Hugo
*/
class ExSolver {
public:
    typedef Ex::T T;
    /// goal : minimize expr / symbols which are contained in eqs
    ExSolver(const Ex &equation);
    /// goal : find zeroes (at best) for each equations.
    ExSolver(const ExVector &equations);
    ~ExSolver();

    bool solve(double prec = 1e-7,unsigned nb_max_iter=100);
    double iteration(double minRatio,int mov_level,double prec);
    
    void displayMat() const;
    void displayVec() const;
    
    ExVector symbols;
private:
    void updateGslData(int level);
    void resize(unsigned nbLines,unsigned nbCols);
    
    unsigned nl,nc;    
    gsl_matrix *gslMat;
    gsl_vector *gslVec;
    
    gsl_matrix *U;
    gsl_matrix *V;
    gsl_vector *S;
    gsl_vector *work;
    gsl_vector *X;
    double post_mult;
    
    ExMatrix mat;
    ExVector vec;
    
    Ex objective;
};

};

#endif // CODEGEN_EXSOLVER_H
