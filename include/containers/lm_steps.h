////////////////////////////////////
//  Author : Camille GOUTTEBROZE  //
//  gouttebroze@lmt.ens-cachan.fr //
////////////////////////////////////

#ifndef lm_steps_HEADER
#define lm_steps_HEADER

#include <containers/vec.h>
#include <containers/number.h>

namespace LMT {

/**
  @author Gouttebroze
*/

template <class T=double>
struct ConstantStep {
    ConstantStep (const T &v=T(1)) { value=v; }
    template <class TF, int s1, int s2> void update(TF &j,const Vec<T,s1> &c, const Vec<T,s2> &g) {}
    T value;
};

template <int g=0, class T=double>
struct ArmijoStep {
    ArmijoStep (const T &v=T(1), const T &p=T(1)/T(2), const T &e=T(0.000001)) { value=v; parameter=p; epsilon=e; }
    template <class TF, int s> void update(TF &j,const Vec<T,s> &c, const Vec<T,s> &d) {
        T f=T(1);
        T y=T(0);
        T toto=parameter*dot(lm_gradient(j,c,Number<g>(),epsilon),d);
        for(T aux=2*value; f>y; aux=aux*0.5) {
            f=j->operator()(Vec<T,s>(c+aux*d));
            y=j->operator()(c)+aux*toto;
            value=aux;
        }
    }
    T value;
    T parameter;
    T epsilon;
};

template <class T=double>
struct WolfeStep {/* TODO */};

template <class T=double>
struct OptimalStep {/* TODO */};

}

#endif // lm_steps_HEADER
