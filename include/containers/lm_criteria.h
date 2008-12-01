////////////////////////////////////
//  Author : Camille GOUTTEBROZE  //
//  gouttebroze@lmt.ens-cachan.fr //
////////////////////////////////////

#ifndef lm_criteria_HEADER
#define lm_criteria_HEADER

#include <containers/vec.h>

namespace LMT {

/**
  @author Gouttebroze
*/

struct IterationNumberCriterion {
    IterationNumberCriterion (const unsigned imax=100u) { iteration=0u; iteration_max=imax;}
    template <class TF, class T, int s> bool update(TF &f,const Vec<T,s> &x) {
        iteration++;
        return (iteration<iteration_max);
    }
    unsigned iteration;
    unsigned iteration_max;
};

template <class T=double>
struct AbsoluteValueCriterion {
    AbsoluteValueCriterion (const T &v=T(0.000001)) { value=v;}
    template <class TF, int s> bool update(TF &f,const Vec<T,s> &x) {
        return (abs(f->operator()(x))>value);
    }
    T value;
};

template <class T=double>
struct RelativeValueCriterion {
    RelativeValueCriterion (const T &v=T(0.000001)) { value=v; initialisation_done=false; }
    template <class TF, int s> bool update(TF &f,const Vec<T,s> &x) {
        if (not initialisation_done) {
            initial_value=f->operator()(x);
            initialisation_done=true;
        }
        return (abs(f->operator()(x)/initial_value)>value);
    }
    bool initialisation_done;
    T value;
    T initial_value;
};

template <class T=double, int s=-1>
struct AbsoluteStepCriterion {
    AbsoluteStepCriterion (const T &v=T(0.001)) { value=v;}
    template <class TF> bool update(TF &f,const Vec<T,s> &x) {
        if (not initialisation_done) {
            input_before=x;
            initialisation_done=true;
            return true;
        }
        bool res = norm_2(x-input_before)>value;
        input_before=x;
        return res;
    }
    bool initialisation_done;
    T value;
    Vec<T,s> input_before;
};

template <class T=double, int s=-1>
struct RelativeStepCriterion {
    RelativeStepCriterion (const T &v=T(0.001)) { value=v;}
    template <class TF> bool update(TF &f,const Vec<T,s> &x) {
        if (not initialisation_done) {
            input_before=x;
            initialisation_done=true;
            return true;
        }
        bool res = norm_2(x-input_before)/norm_2(x)>value;
        input_before=x;
        return res;
    }
    bool initialisation_done;
    T value;
    Vec<T,s> input_before;
};

}

#endif // lm_criteria_HEADER
