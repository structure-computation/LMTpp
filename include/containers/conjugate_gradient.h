#ifndef CONJUGATE_GRADIENT_H
#define CONJUGATE_GRADIENT_H

namespace LMT {

/*!
    L'opérateur precond doit savoir faire * pour renvoyer l'opération de préconditionnement.
    
    \code
        Mat<double,Sym<>,SparseLine<> > K( f.matrices( Number<0>() ) );
        incomplete_chol_factorize( K );
    
        unsigned cpt_iter = conjugate_gradient( new_SolveUsingCholFactorize( K ), f.matrices( Number<0>() ), f.sollicitation, f.vectors[ 0 ], ConvergenceCriteriumNormInfDelta<double>( 1e-5 ) );
*/
template<class Precond,class Matrix,class TV,class TV_SOLUTION,class CritOperator>
unsigned conjugate_gradient( const Precond &precond, const Matrix &matrix, const TV &sollicitation, TV_SOLUTION &solution, const CritOperator &crit_op, bool disp_alpha = false ) {
    typedef typename TypeReduction<Plus,TV_SOLUTION>::T T;
    if ( solution.size() <= matrix.nb_rows() )
        solution.resize( matrix.nb_rows(), T(0) );
        
    //
    Vec<T> r, d, q, s;

    r = sollicitation - matrix * solution;
    
    if ( CritOperator::needs_delta_x == false and crit_op( solution, r ) )
        return 0;
    
    d = precond * r;
    
    T deltn = dot( r, d );
    unsigned cpt;
    for( cpt = 1; ; ++cpt ) {
        T delto = deltn;
        
        q = matrix * d;
        T dot_val = dot( d, q );
        T alpha = deltn / ( dot_val + ( dot_val == 0 ) );
        solution += alpha * d;
        r -= alpha * q; // r = b - A * x;
        
        if ( disp_alpha )
            PRINT( alpha );
        
        if ( crit_op( alpha * d, r ) )
            return cpt;
        
        s = precond * r;
        
        deltn = dot( r, s );
        
        T beta = deltn / delto;
        d = s + beta * d;
    }
    return cpt;
}

/*!
    Utile pour conjugate_gradient
*/
template<class TK>
struct SolveUsingCholFactorize {
    SolveUsingCholFactorize( const TK &k ) : K( k ) {}
    typedef typename TK::T MatrixScalarType;
    template<class TV>
    Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> operator*( const Vec<TV> &v ) const {
        Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> res;
        solve_using_chol_factorize( K, v, res );
        return res;
    }
    const TK &K;
};

/*
*/
template<class TK>
struct SolveUsingDotSolve {
    SolveUsingDotSolve( TK &k ) : K( k ) {}
    typedef double MatrixScalarType;
    template<class TV>
    Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> operator*( const Vec<TV> &v ) const {
        return K.solve( v );
    }
    mutable TK &K;
};


template<class T>
struct ConvergenceCriteriumNormInfDelta {
    static const bool needs_delta_x = true;
    static const bool residual = false;
    ConvergenceCriteriumNormInfDelta( T v ) : crit( v ) {}
    template<class TV0,class TV1> bool operator()( const TV0 &delta_x, const TV1 &residual ) const {
        for(unsigned i=0;i<delta_x.size();++i)
            if ( abs(delta_x[i]) > crit )
                return false;
        return true;
    }
    T crit;
};

template<class T>
struct ConvergenceCriteriumNorm2 {
    static const bool needs_delta_x = true;
    static const bool residual = false;
    ConvergenceCriteriumNorm2( T v ) : crit( v ) {}
    template<class TV0,class TV1> bool operator()( const TV0 &delta_x, const TV1 &residual ) const {
        return norm_2( delta_x ) < crit;
    }
    T crit;
};

template<class TK>
SolveUsingCholFactorize<TK> new_SolveUsingCholFactorize( const TK &k ) {
    return k;
}

template<class TK>
SolveUsingDotSolve<TK> new_SolveUsingDotSolve( TK &k ) {
    return k;
}
// new_SolveUsingInverseMatrix

} // namespace LMT
#endif // CONJUGATE_GRADIENT_H
