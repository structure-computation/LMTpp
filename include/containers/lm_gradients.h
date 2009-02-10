////////////////////////////////////
//  Author : Camille GOUTTEBROZE  //
//  gouttebroze@lmt.ens-cachan.fr //
////////////////////////////////////

#ifndef lm_gradients_HEADER
#define lm_gradients_HEADER

#include <containers/mat.h>
#include <containers/number.h>

namespace LMT {

/**
  @author Gouttebroze
*/

template <class TF, class T, int s> Vec<T,s> lm_gradient(TF &f,const Vec<T,s> &x, Number<0>, const T &epsilon=T(0.000001) ) {
    Vec<T,s> res;
    res.resize(x.size());
    T local_value=f->operator()(x);
    for (int i=0;i<res.size();i++) {
        Vec<T,s> v_epsilon;
        v_epsilon.resize(x.size(),T(0));
        v_epsilon[i]=epsilon;
        res[i]=(f->operator()(Vec<T,s>(x+v_epsilon))-local_value)/epsilon;
    }
    return res;
};

template <class TF, class T, int s, unsigned n> Vec<T,s> lm_gradient(TF &f,const Vec<T,s> &x, Number<n>, const T &epsilon=T(0) ) {
    return f->grad(x);
};

template <class TF, class T, int s> Mat<T,Gen<s> > lm_hessian(TF &f,const Vec<T,s> &x, Number<0>, const T &epsilon=T(0.000001) ) {
    Mat<T,Gen<s> > res;
    res.resize(x.size());
    T local_value=f->operator()(x);
    for (int i=0;i<res.nb_rows();i++) {
        Vec<T,s> v_epsilon_i;
        v_epsilon_i.resize(x.size(),T(0));
        v_epsilon_i[i]=epsilon;
        for (int j=0;j<res.nb_cols();j++) {
            Vec<T,s> v_epsilon_j;
            v_epsilon_j.resize(x.size(),T(0));
            v_epsilon_j[j]=epsilon;
            res(i,j)=(f->operator()(x+v_epsilon_i+v_epsilon_j)-f->operator()(x+v_epsilon_i)-f->operator()(x+v_epsilon_j)+local_value)/(epsilon*epsilon);
        }
    }
    return res;
};

template <class TF, class T, int s> Mat<T,Gen<s> > lm_hessian(TF &f,const Vec<T,s> &x, Number<1>, const T &epsilon=T(0.000001) ) {
    Mat<T,Gen<s> > res;
    res.resize(x.size());
    Vec<T,s> local_gradient=f->grad(x);
    for (int i=0;i<res.nb_rows();i++) {
        Vec<T,s> v_epsilon;
        v_epsilon.resize(x.size(),T(0));
        v_epsilon[i]=epsilon;
        for (int j=0;j<res.nb_cols();j++)
            res(i,j)=(f->grad(x+v_epsilon)[j]-local_gradient[j])/epsilon;
    }
    return res;
};

template <class TF, class T, int s, unsigned n> Mat<T,Gen<s> > lm_hessian(TF &f,const Vec<T,s> &x, Number<n>, const T &epsilon=T(0) ) {
    return f->hessian(x);
};

}

#endif // lm_gradients_HEADER
