////////////////////////////////////
//  Author : Camille GOUTTEBROZE  //
//  gouttebroze@lmt.ens-cachan.fr //
////////////////////////////////////

#ifndef local_minimiser_HEADER
#define local_minimiser_HEADER

#include <containers/vec.h>
#include "lm_gradients.h"
#include "lm_algorithms.h"
#include "lm_steps.h"
#include "lm_criteria.h"

namespace LMT {

/**
  @author Gouttebroze
*/

template <class TF, class TA=BfgsAlgorithm<>, class TS=ArmijoStep<>, class TC=RelativeStepCriterion<> >
struct LocalMinimizer {

    LocalMinimizer (TF &func, bool print_x=0 ) { f=&func; print_res=print_x; }

    template <class T, int s> Vec<T,s> solve(const Vec<T,s> &input) {
        Vec<T,s> res=input;
        for (;criterion.update(f,res);) {
            Vec<T> direction=algorithm.get_direction(f,res);
            step.update(f,res,direction);
            res+=step.value*direction;
            if (print_res)
                std::cout << "The local minimiser is now at : " << res << std::endl;
        }
        return res;
    }

    TF *f;
    TA algorithm;
    TS step;
    TC criterion;
    bool print_res;

};

}

#endif // local_minimiser_HEADER
