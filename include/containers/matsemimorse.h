#ifndef MATSEMIMORSE_H
#define MATSEMIMORSE_H

#include <map>

namespace LMT {

template<bool pouet=false>
struct SemiMorse {
    typedef Col TO;
    static const bool col_oriented = true;
    static std::string name() { std::ostringstream os; os << "SparseCholMod col_oriented=" << col_oriented;  return os.str(); }
    static const bool dense = false;
    static const bool sparse = true;
    static const bool skyline = false;

    typedef SemiMorse Trans;
};

template<class T>
struct Mat<T, Sym<>, SemiMorse, void> {
    static const unsigned al = SimdSize<T>::res; /// alignement
    static const unsigned want_aligned_block_if_size_supeq = al * 3;
    
    Mat() { r=0; c=0; }
    
    template<class AP,class AI,class AX> Mat( const AP &Ap, const AI &Ai, const AX &Ax, const DI &diag_ ) {
        diag = diag_;
        
        
    }
    
    unsigned nb_rows() const { return r; }
    unsigned nb_cols() const { return c; }
    
    unsigned r,c;
};

}

#endif // MATSEMIMORSE_H
