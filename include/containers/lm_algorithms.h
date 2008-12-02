////////////////////////////////////
//  Author : Camille GOUTTEBROZE  //
//  gouttebroze@lmt.ens-cachan.fr //
////////////////////////////////////

#ifndef lm_algorithms_HEADER
#define lm_algorithms_HEADER

#include <containers/mat.h>
#include <containers/number.h>

namespace LMT {

/**
  @author Gouttebroze
*/

template <int g=0, class T=double>
struct GradAlgorithm {
    GradAlgorithm (const T &e=T(0.000001)) { epsilon=e; }
    template <class TF, int s> Vec<T,s> get_direction(TF &f,const Vec<T,s> &x) {
        return -lm_gradient(f,x,Number<g>(),epsilon);
    }
    T epsilon;
};

template <int g=0, class T=double, int s=-1>
struct BfgsAlgorithm {

    BfgsAlgorithm (const T &e=T(0.000001)) { epsilon=e; }

    template <class TF> Vec<T,s> get_direction(TF &f,const Vec<T,s> &x) {
        if (not initialisation_done) {
            B.resize(x.size());
            B.set(T(0));
            for (int i=0;i<x.size();i++)
                B(i,i)=T(1);
            grad=lm_gradient(f,x,Number<g>(),epsilon);
            initialisation_done=true;
        }        
        else {
            grad_before=grad;
            grad=lm_gradient(f,x,Number<g>(),epsilon);
            Vec<T> grad_diff=grad-grad_before;
            B=B+vec2matsym(grad_diff)/dot(grad_diff,direction)-(B*vec2matsym(direction)*B)/dot(direction,B*direction);
        }
        direction=-(inv(B)*grad);
        return direction;
    }

    bool initialisation_done;
    Mat<T,Gen<s> > B;
    Vec<T,s> grad;
    Vec<T,s> grad_before;
    Vec<T,s> direction;
    T epsilon;
    
};

template <int g=0, class T=double>
struct NewtonAlgorithm {
    NewtonAlgorithm (const T &e=T(0.000001)) { epsilon=e; }
    template <class TF, int s> Vec<T,s> get_direction(TF &f,const Vec<T,s> &x) {
        return -(inv(lm_hessian(f,x,Number<g>(),epsilon))*lm_gradient(f,x,Number<g>(),epsilon));
    }
    T epsilon;
};

}

#endif // lm_algorithms_HEADER
