#ifndef PreBiCGSTAB_H
#define PreBiCGSTAB_H

#include <containers/matinv.h>
#include <containers/mat.h>
#include <containers/matsparse.h>
#include <containers/matsparselu.h>

namespace LMT {

/*!
    L'opérateur precond doit savoir faire * pour renvoyer l'opération de préconditionnement.
    Pour les matrices symetriques
    \code
        Mat<double,Sym<>,SparseLine<> > K( f.matrices( Number<0>() ) );
        incomplete_chol_factorize( K );
        int max_iter = 300;
        unsigned status = conjugate_gradient( new_SolveUsingCholFactorize( K ), f.matrices( Number<0>() ), f.sollicitation, f.vectors[ 0 ], ConvergenceCriteriumNormInfDelta<double>( 1e-5 ) ,max_iter );
        
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class Precond,class Matrix,class TV,class TV_SOLUTION,class CritOperator>
unsigned conjugate_gradient( const Precond &precond, const Matrix &matrix, const TV &sollicitation, TV_SOLUTION &solution, const CritOperator &crit_op, int &max_iter ) {
    typedef typename TypeReduction<Plus,TV_SOLUTION>::T T;
    if ( solution.size() <= matrix.nb_rows() )
        solution.resize( matrix.nb_rows(), T(0) );
        
    //
    Vec<T> r, d, q, s;

    r = sollicitation - matrix * solution;
    
    if ( CritOperator::needs_delta_x == false and crit_op( solution, r ) ){
        max_iter = 0;
        return 0;
    }
    
    d = precond * r;
    
    T deltn = dot( r, d );
    unsigned cpt;
    for( cpt = 1; cpt < max_iter ; ++cpt ) {
        T delto = deltn;
        
        q = matrix * d;
        T dot_dq = dot( d, q );
        T alpha = deltn / ( dot_dq + ( dot_dq == 0 ) );
        solution += alpha * d;
        r -= alpha * q; // r = b - A * x;
        
        // PRINT( alpha );
        
        if ( crit_op( alpha * d, r ) ){
            max_iter = cpt;
            return 0;
        }
        
        s = precond * r;
        
        deltn = dot( r, s );
        
        T beta = deltn / delto;
        d = s + beta * d;
    }
    return 1;
}   
    
    
/*!
    L'opérateur precond doit savoir faire * pour renvoyer l'opération de préconditionnement.
    Pour les matrices non symetriques
    \code
        Mat<double,Sym<>,SparseLine<> > K( f.matrices( Number<0>() ) );
        incomplete_chol_factorize( K );
    
        int max_iter = 300;
        unsigned status = PreBiCGSTAB( new_SolveUsingCholFactorize( K ), f.matrices( Number<0>() ), f.sollicitation, f.vectors[ 0 ], ConvergenceCriteriumNormInfDelta<double>( 1e-5 ) , max_iter );
        
        voir http://en.wikipedia.org/wiki/Biconjugate_gradient_stabilized_method
        http://www.netlib.org/templates/cpp/bicgstab.h
        
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class Precond,class Matrix,class TV,class TV_SOLUTION,class CritOperator>
unsigned PreBiCGSTAB( const Precond &precond, const Matrix &matrix, const TV &sollicitation, TV_SOLUTION &solution, const CritOperator &crit_op , int &max_iter ) {
    typedef typename TypeReduction<Plus,TV_SOLUTION>::T T;
    if ( solution.size() <= matrix.nb_rows() )
        solution.resize( matrix.nb_rows(), T(0) );
        
    //
    Vec<T> r,rh0;

    r = sollicitation - matrix * solution;
    rh0=r;
    
    T rhoold=1;
    T rho=1,alpha=1,beta=0,omega=1;
    
    Vec<T> v,p;
    v.resize( matrix.nb_rows(), T(0) );
    p.resize( matrix.nb_rows(), T(0) );
    
    
    if ( CritOperator::needs_delta_x == false and crit_op( solution, r ) ){
        max_iter = 0;
        return 0;
    }
    
    unsigned cpt;
    for( cpt = 1;cpt<max_iter ; ++cpt ) {
        
        rho = dot( rh0 , r );
        
        if(rho==0){
            //failed
            return 1;
        }
        
        if(cpt==1)
            p = r;
        else {
            beta = ( rho / rhoold ) * ( alpha / omega );
            p = r + beta * ( p - omega * v );
        }
        
        Vec<T> y = precond * p;
        
        v = matrix * y;
        
        alpha = rho / dot( rh0 , v );
        
        Vec<T> s = r - alpha * v;
        
        if ( crit_op( alpha * v , s ) ){
            solution += alpha * y;
            max_iter = cpt ;
            return 0;
        }
        
        Vec<T> z = precond * s;
        
        Vec<T> t = matrix * z;    
        
        omega = dot( t, s) / dot( t , t );
        
        solution += alpha * y + omega * z;
        
        r = s - omega * t;
        
        rhoold = rho;
        
        if ( crit_op( alpha * y + omega * z , r ) ){
            max_iter = cpt;
            return 0;
        }
        
        if(omega==0){
            //failed 
            return 1;
        }
        
    }
    return 0;
}

/*!
    L'opérateur precond doit savoir faire * pour renvoyer l'opération de préconditionnement.
    
    \code
        Mat<double,Sym<>,SparseLine<> > K( f.matrices( Number<0>() ) );
        incomplete_chol_factorize( K );
        int max_iter = 300;
        double tol = 1e-10;
        int status = PreBiCGSTAB( new_SolveUsingCholFactorize( K ), f.matrices( Number<0>() ), f.sollicitation, f.vectors[ 0 ], tol , max_iter );
        
        voir http://en.wikipedia.org/wiki/Biconjugate_gradient_stabilized_method
        http://www.netlib.org/templates/cpp/gmres.h
        
    Iterative template routine -- GMRES

    GMRES solves the unsymmetric linear system Ax = b using the 
    Generalized Minimum Residual method

    GMRES follows the algorithm described on p. 20 of the 
    SIAM Templates book.

    The return value indicates convergence within max_iter (input)
    iterations (0), or no convergence within max_iter iterations (1).

    Upon successful return, output arguments have the following values:
    
        x  --  approximate solution to Ax = b
    max_iter  --  the number of iterations performed before the
                tolerance was reached
        tol  --  the residual after the final iteration
        
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/

 

template < class Matrix, class Vector,class VectorVector >
void 
Update(Vector &x, int k, Matrix &h, Vector &s, VectorVector v)
{
  Vector y(s);

  // Backsolve:  
  for (int i = k; i >= 0; i--) {
    y[i] /= h(i,i);
    for (int j = i - 1; j >= 0; j--)
      y[j] -= h(j,i) * y[i];
  }

  for (int j = 0; j <= k; j++)
    x += v[j] * y[j];
}

/*!
    Objectif :
        résoudre un système linéaire par la méthode gmres.

    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système

*/
template<class Precond,class Matrix,class TV,class TV_SOLUTION>                                                         
unsigned GMRES( const Precond &precond, const Matrix &matrix, const TV &sollicitation, TV_SOLUTION &solution, double &tol , int &max_iter, int m=0) {
    typedef typename TypeReduction<Plus,TV_SOLUTION>::T T;
    //const int m = 50;//le nombre de sous iterations avant restart
    const int dim = matrix.nb_rows();
    
    if ( solution.size() <= (unsigned)dim )
        solution.resize( dim, T(0) );
    
    //voir http://plasimo.phys.tue.nl/TBCI/online-docu/html/gmres_8h-source.html
    if (m == 0)
        m = dim/8+max_iter/4;
    if (m > max_iter)
        m = max_iter;
    
    Mat<T> H(m+1,m+1);//hessenberg superieure (optimiser le stockage peut etre)
    
    T resid;
    Vec<T> s, cs, sn, w;
    s.resize(m+1,0.0);
    cs.resize(m+1,0.0);
    sn.resize(m+1,0.0);
    w.resize(matrix.nb_rows(),T(0));
    
    
    T normb = norm_2( precond * sollicitation );
    Vec<T> r = precond * (TV)(sollicitation -  matrix * solution);
    T beta = norm_2(r);
  
    if (normb == 0.0)
        normb = 1;
  
    if ((resid = norm_2(r) / normb) <= tol) {
        tol = resid;
        max_iter = 0;
        return 0;
    }

    Vec<Vec<T> > v;
    v.resize(m+1);
    for(int i=0;i<m+1;++i) v[i].reserve(matrix.nb_rows());
    
    int j = 1 ,ii,k;
    while (j <= max_iter) {
        v[0] = r / beta;    // ??? r / beta
        s.set(0.);
        s[0] = beta;
    
        for (ii = 0; ii < m && j <= max_iter; ii++, j++) {
            w = precond * (TV)(matrix * v[ii]);
            for (k = 0; k <= ii; k++) {
                H(k, ii) = dot(w, v[k]);
                w -= H(k, ii) * v[k];
            }
            //voir http://plasimo.phys.tue.nl/TBCI/online-docu/html/gmres_8h-source.html
            const register T normw = norm_2(w);
            H(ii+1, ii) = normw;
            v[ii+1] = w / normw; // ??? w / H(i+1, i)

            for (k = 0; k < ii; k++)
                ApplyPlaneRotation(H(k,ii), H(k+1,ii), cs[k], sn[k]);
      
            GeneratePlaneRotation(H(ii,ii), normw, cs[ii], sn[ii]);
            ApplyPlaneRotation(H(ii,ii), H(ii+1,ii), cs[ii], sn[ii]);
            ApplyPlaneRotation(s[ii], s[ii+1], cs[ii], sn[ii]);
      
            if ((resid = abs(s[ii+1]) / normb) < tol) {
                Update(solution, ii, H, s, v);
                tol = resid;
                max_iter = j;
                return 0;
            }
        }
        Update(solution, m - 1, H, s, v);
        r = precond * (TV)(sollicitation - matrix * solution);
        beta = norm_2(r);
        if ((resid = beta / normb) < tol) {
            tol = resid;
            max_iter = j;
            return 0;
        }
    }
    tol = resid;
    return 1;
}

/*!

    doc ?

*/
template<class Real> 
void GeneratePlaneRotation(Real &dx,const Real &dy, Real &cs, Real &sn)
{
  if (dy == 0.0) {
    cs = 1.0;
    sn = 0.0;
  } else if (abs(dy) > abs(dx)) {
    const Real temp = dx / dy;
    sn = 1.0 / sqrt( 1.0 + temp*temp );
    cs = temp * sn;
  } else {
    Real temp = dy / dx;
    cs = 1.0 / sqrt( 1.0 + temp*temp );
    sn = temp * cs;
  }
}


template<class Real> 
void ApplyPlaneRotation(Real &dx, Real &dy, const Real &cs,const  Real &sn)
{
  Real temp  =  cs * dx + sn * dy;
  dy = cs * dy - sn * dx ;
  dx = temp;
}

//fin GMRES


/*!
    preconditionneur
    
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
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

/*!
    préconditionneur

    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class TK>
struct SolveUsingCholMod {
    SolveUsingCholMod( TK &k ) : K( k ) {}
    typedef double MatrixScalarType;
    template<class TV>
    Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> operator*( const Vec<TV> &v ) const {
        return K.solve( v );
    }
    mutable TK &K;
};

/*!
    preconditionneur SSOR (General)

    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/

template<class T,class Structure,class Storage>
struct SolveUsingSSOR {
    SolveUsingSSOR( const Mat<T,Structure,Storage> &k ) : K( k ) {}
    typedef double MatrixScalarType;
    template<class TV>
    Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> operator*( const Vec<TV> &v ) const {
        //K=D+L+LT 
        //C=(D+L)D^-1(D+LT)
        //C^-1=(D+LT)^-1D(D+L)^1
        typedef typename TypePromote<Multiplies,MatrixScalarType,TV>::T TR;
        Vec<TR> res;
        res.resize(K.nb_cols());
        //descente
        for(unsigned i=0;i<K.nb_rows();++i) {
            TR tmp = v[i];
            for(unsigned j=0;j<i;++j)
                tmp -= K(i,j) * res[j];
            res[i] = tmp / K(i,i);
        }
        //diag
        res =  K.diag()*res;
        //remontee    
        for(int i=K.nb_rows()-1;i>=0;--i) {
            TR tmp = res[i];
            for(unsigned j=i+1;j<K.nb_rows();++j)
                tmp -= K(i,j) * res[j];
            res[i] = tmp / K(i,i);
        }
        return res;
    }
    const Mat<T,Structure,Storage> &K;
};

/*!
    preconditionneur SSOR (Specialisation type sparse)
     
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class T>
struct SolveUsingSSOR<T,Sym<>,SparseLine<> > {
    SolveUsingSSOR( const Mat<T,Sym<>,SparseLine<> > &k ) : K( k ) {}
    typedef double MatrixScalarType;
    template<class TV>
    Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> operator*( const Vec<TV> &sol ) const {
        //K=D+L+LT 
        //C=(D/omega+L)D^-1(D+LT)
        //C^-1=(D+LT)^-1D(D+L)^1
        typedef typename TypePromote<Multiplies,MatrixScalarType,TV>::T TR;
        Vec<TR> res;
        Mat<T,Gen<>,SparseLU> mat(K);
        unsigned nb_lines = mat.nb_rows();
        //
        if ( res.size() <= nb_lines )
            res.resize( nb_lines, T(0) );
        //descente
        for(unsigned line=0;line<nb_lines;++line) {
            T v = sol[line];
            for(unsigned i=0;i<mat.L[line].data.size();++i)
                v -= mat.L[line].data[i] * res[ mat.L[line].indices[i] ];
            res[line] = v / K(line,line) ;
        }
        //diag
        res =  K.diag()*res;
        //remontée
        Vec<T> tmpvec = res;
        while (nb_lines--) {
            assert( mat.U[nb_lines].data.size() );
            T tmp = tmpvec[nb_lines] /  mat.U[nb_lines].data.back();
            for(unsigned i=0;i<mat.U[nb_lines].data.size()-1;++i)
                tmpvec[ mat.U[nb_lines].indices[i] ] -= mat.U[nb_lines].data[i] * tmp;
            res[nb_lines] = tmp ;
        }
        return res;
    }
    const Mat<T,Sym<>,SparseLine<> > &K;
};

/*!
    preconditionneur Jacobi

    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class TK>
struct SolveUsingJacobi {
    SolveUsingJacobi( const TK &k ) : K( k ) {}
    typedef double MatrixScalarType;
    template<class TV>
    Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> operator*( const Vec<TV> &v ) const {
        //C=Diag(K)
        Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> res;
        res.resize(K.nb_cols());
        //diag
        res = solve(K.diag(),v);
        return res;
    }
    const TK &K;
};

/*!
pour les systemes couplés

    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class TK, class TCholMod, class TUMFPACK>
struct SolveUsingCholModSystemWithSameK {
    SolveUsingCholModSystemWithSameK( TCholMod &kc , TUMFPACK &ku  ) : KCholMod( kc ) , KUMFPACK( ku )  {
        use_cholmod = true;
    }
    typedef double MatrixScalarType;
    template<class TV>
    Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> operator*( const Vec<TV> &v ) const {
        unsigned total_size = v.size();
        
        Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> res;
        res.resize(v.size());
        if( use_cholmod ){
            res[range(total_size / 2 )] = KCholMod.solve( v[range( total_size / 2 )] );
            if(isnan(res[0])){
                use_cholmod = false ;
                PRINTN("cholmod failed"); 
                KCholMod.free_data();
                res[range(total_size / 2 )] = KUMFPACK.solve( v[range( total_size / 2 )] );
            }
        }
        else
            res[range(total_size / 2 )] = KUMFPACK.solve( v[range( total_size / 2 )] );
        
        if( use_cholmod )
            res[range(total_size / 2 , total_size )] = KCholMod.solve( v[range( total_size / 2 , total_size )] );
        else
            res[range(total_size / 2 , total_size )] = KUMFPACK.solve( v[range( total_size / 2 , total_size )] );
        
        return res;
    }
    mutable bool use_cholmod;
    TCholMod &KCholMod;
    TUMFPACK &KUMFPACK;
    
};

template<class TK>
struct SolveUsingLDLSystemWithSameK {
    SolveUsingLDLSystemWithSameK( TK &k ) : K( k ) {}
    typedef double MatrixScalarType;
    template<class TV>
    Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> operator*( const Vec<TV> &v ) const {
        unsigned total_size = v.size();
        
        Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> res1( v[range( total_size / 2 )] );
        Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> res2( v[range( total_size / 2 ,total_size )] );
        
        K.solve( res1 );
        K.solve( res2 );
        
        Vec<TV> res;res.resize(total_size,0.);
        res[range( total_size / 2 )]=res1;
        res[range( total_size / 2 ,total_size )]=res2;
        return res;
    }
    TK &K;
};

template<class TK>
struct SolveUsingPREGCSystemWithSameK {
    SolveUsingPREGCSystemWithSameK( TK &k ) : K( k ) {}
    typedef double MatrixScalarType;
    template<class TV>
    Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> operator*( const Vec<TV> &v ) const {
        unsigned total_size = v.size();

        Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> res1;
        res1.resize(total_size / 2,0.);
        Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> res2;
        res2.resize(total_size / 2,0.);
        
        Vec<TV> v1(v[range( total_size / 2 )]);
        Vec<TV> v2(v[range( total_size / 2 ,total_size )]);

        PRINTN("Precon");
        int max_iter = 400;
        double tol = 1e-20;
        unsigned status = PreBiCGSTAB( new_SolveUsingSSOR( K ) , K , v1 , res1, ConvergenceCriteriumNormInfDelta<double>( tol ) , max_iter );
        PRINTN(max_iter);
        PRINTN(tol);
        status = PreBiCGSTAB( new_SolveUsingSSOR( K ) , K , v2 , res2 , ConvergenceCriteriumNormInfDelta<double>(tol ) , max_iter );
        PRINTN(max_iter);
        PRINTN(tol);
        PRINTN("fin Precon");
        
        Vec<TV> res;res.resize(total_size,0.);
        res[range( total_size / 2 )]=res1;
        res[range( total_size / 2 ,total_size )]=res2;
        return res;
    }
    const TK &K;
//     const TK &K1;
};

template<class TK>
struct GrosseMatriceParPetitBout {
    GrosseMatriceParPetitBout( TK &k11 , TK &k12 , TK &k21 , TK &k22 ) : K11( k11 ) , K12( k12) , K21( k21 ) , K22( k22 ) {}
    typedef double MatrixScalarType;
    template<class TV>
    Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> operator*( const Vec<TV> &v ) const {
        unsigned total_size = v.size();

        Vec<typename TypePromote<Multiplies,MatrixScalarType,TV>::T> res;
        res.resize(v.size());
        
        res[range(total_size / 2 )] = K11 * v[range( total_size / 2 )] + K12 * v[range( total_size / 2 , total_size )];
        res[range(total_size / 2 , total_size )] = K21 * v[range( total_size / 2 )] + K22 * v[range( total_size / 2 , total_size)];

        return res;
    }
    
    const unsigned nb_rows() const {
        return K11.nb_rows() + K12.nb_rows();
    }
    
    mutable TK &K11,&K12,&K21,&K22;
};


/*!
criteres d'arret

    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
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

/*!
    critère d'arrêt
    
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class T>
struct ConvergenceCriteriumNormInfResidual {
    static const bool needs_delta_x = true;
    static const bool residual = false;
    ConvergenceCriteriumNormInfResidual( T v ) : crit( v ) {}
    template<class TV0,class TV1> bool operator()( const TV0 &delta_x, const TV1 &residual ) const {
        for(unsigned i=0;i<residual.size();++i)
            if ( abs(residual[i]) > crit )
                return false;
        return true;
    }
    T crit;
};

/*!
    crée un préconditionneur
    
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class TK>
SolveUsingCholFactorize<TK> new_SolveUsingCholFactorize( const TK &k ) {
    return k;
}

/*!
    crée un préconditionneur
    
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class TK>
SolveUsingCholMod<TK> new_SolveUsingCholMod( TK &k ) {
    return k;
}

/*!
    crée un préconditionneur
    
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class T,class Structure,class Storage>
SolveUsingSSOR<T,Structure,Storage> new_SolveUsingSSOR( const Mat<T,Structure,Storage> &k ) {
    return k;
}

/*!
    crée un préconditionneur
    
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class TK>
SolveUsingJacobi<TK> new_SolveUsingJacobi( TK &k ) {
    return k;
}

/*!
pour la resolution de systeme HX + BX' = F , HX' + B'X = F' 

    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
// template<class TK>
// SolveUsingCholModSystemWithSameK<TK> new_SolveUsingCholModSystemWithSameK( TK &k ) {
//     return k;
// }

/*!
     
    \keyword Matrice/Solver
    \keyword Mathématiques/Algèbre linéaire/Système
*/
template<class TK>
GrosseMatriceParPetitBout<TK> new_GrosseMatriceParPetitBout( TK &k11,TK &k12,TK &k21,TK &k22 ) {
    GrosseMatriceParPetitBout<TK> res(k11,k12,k21,k22);
    return res;
}

//fin pour la resolution de systeme HX + BX' = F , HX' + B'X = F'

} // namespace LMT
#endif // PreBiCGSTAB_H
