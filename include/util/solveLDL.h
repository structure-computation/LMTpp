#ifndef SOLVE_LDL_H
#define SOLVE_LDL_H

#include "containers/mat.h"
extern "C" {
#include "amd/amd.h"
}
#include "beep.h"

class LDL_solver {
public:
    typedef double T;
    
    LDL_solver() {pseudo_inverse=false;}
    bool pseudo_inverse;
    
    /// after that, data in mat won't be used anymore.
    void get_factorization( LMT::Mat<double,LMT::Sym<>,LMT::SparseLine<> > &mat, bool want_free=true, bool want_semi_morse=false, bool want_amd_order=true );
    /// after that, data in mat won't be used anymore.
    void get_factorization( LMT::Mat<double,LMT::Gen<>,LMT::SparseLine<> > &mat, bool want_free=true, bool want_semi_morse=false, bool want_amd_order=true );
    /// after that, data in mat won't be used anymore.
    void get_factorization( LMT::Mat<double,LMT::Sym<>,LMT::SparseLine<> > &mat, LMT::Vec<LMT::Vec<double> > &Kernel, bool want_free=true, bool want_semi_morse=false, bool want_amd_order=true ); // PK et PG (pseudo-inverse)
    void get_factorization( LMT::Mat<double,LMT::Gen<>,LMT::SparseLine<> > &mat, LMT::Vec<LMT::Vec<double> > &Kernel, bool want_free=true, bool want_semi_morse=false, bool want_amd_order=true ); // PK et PG (pseudo-inverse)
    /// ...
    template<class TM> void get_factorization( const TM &mat, bool want_free=true, bool want_semi_morse=false, bool want_amd_order=true ) { assert(0); /* TODO */ }
    /// ...
    void solve( LMT::Vec<double> &vec );
    
private:
    ///
    void update_block_set_from_factorization();
    ///
    void semi_morse_lsolve( LMT::Vec<double> &Y );
    ///
    void semi_morse_ltsolve( LMT::Vec<double> &Y );
    
    /// LDL stuff
    double Info[AMD_INFO];
    LMT::Vec<double> Ax, Lx, B, D, X, Y;
    LMT::Vec<int> Ai, Ap, Li, Lp, P, Pinv, Flag, Pattern, Lnz, Parent;
    int lnz, n;
    
    /// semimorse stuff
    bool want_semi_morse_;
    LMT::Vec<T> data_for_block_set;
    LMT::Vec<LineOfBeeps> beep_lines;
};

#endif // SOLVE_LDL_H

