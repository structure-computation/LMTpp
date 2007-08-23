#ifndef EIGEN_H
#define EIGEN_H

namespace LMT {

/**
   compute eigen values and vectors.
   input : vec in vector form
   output : eigenvalues, eigenvectors
 */
template<class T>
void get_eigen_values_and_vectors( const Vec<T,3> &vec, Vec<T,2> &eigenvalues, Vec<Vec<T,2>,2> &eigenvectors ) {
    T b = vec[0]+vec[1];
    T delta = sqrt( b*b - 4 * ( vec[0]*vec[1] - vec[2]*vec[2] ) );
    eigenvalues[0] = 0.5 * ( b - delta );
    eigenvalues[1] = 0.5 * ( b + delta );
    
    //
    if ( LMT::abs(vec[0]-eigenvalues[0]) > LMT::abs( vec[2] ) )
        eigenvectors[0] = Vec<T,2>( vec[2] / (eigenvalues[0]-vec[0]), 1.0 );
    else if ( abs( vec[2] ) >  abs( eigenvalues[0]-vec[1] ) )
        eigenvectors[0] = Vec<T,2>( 1.0, (eigenvalues[0]-vec[0]) / vec[2] );
    else 
        eigenvectors[0] = Vec<T,2>( 1.0, vec[2] / (eigenvalues[0]-vec[1]) );
           
    eigenvectors[0] /= length( eigenvectors[0] );
    
    eigenvectors[1] = Vec<T,2>( -eigenvectors[0][1], eigenvectors[0][0] );
}

}


#endif // EIGEN_H
