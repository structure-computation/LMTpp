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

/*!
    = Tables des matières

        [[#rem|Remarques générales]]
        [[#param|Paramètres template]]
        [[#foire|Foire aux questions]]
        [[#ex|Exemple d'utilisation]] 

     = \anchor rem Remarque générales

        En utilisant la classe LocalMinimizer du fichier local_minimizer.h, vous pourrez trouver un minimum local d'une fonction objectif de votre choix. Il suffit juste de doter votre fonction objectif d'une fontion membre operator(). Pour une meilleure efficacité, vous pouvez la dotez d'une fonction membre grad et même d'une fonction membre hessian. 

    = \anchor param Parametres template

        La classe LocalMinimizer possède 4 paramètres template : LocalMinimizer <TF,TA,TS,TC>.

        * TF est le type de la fonction dont vous souhaitez trouver un minimum local.

        * TA est le type d'algorithme que vous souhaitez utiliser. Vous avez le choix entre :
            * \a GradAlgorithm <g,T> pour un algorithme du gradient. Ses paramètres template sont :
                * g indique la manière dont vous souhaitez calculer le grad.
                    * g=0 (valeur par défaut) pour un gradient numérique calculé à un espace espilon du point local.
                    * g=1 pour un calcul analytique fourni par la fonction objectif
                * T est le type de epsilon utilisé pour le calcul numérique du gradient. Sa valeur par défaut est "double"

            * \a BfgsAlgorithm <g,T,s> (valeur par défaut) pour un algorithme BFGS. Ses paramètres template sont :
                * g indique la manière dont vous souhaitez calculer le grad :
                    * g=0 (valeur par défaut) pour un gradient numérique calculé à un espace espilon du point local.
                    * g=1 pour un calcul analytique fourni par la fonction objectif
                * T est le type de epsilon utilisé pour le calcul numérique du gradient. Sa valeur par défaut est "double"
                * s est la taille de la matrice B. Sa valeur par défaut est -1 (taille dynamique)

            * \a NewtonAlgorithm <g,T> pour un algorithme de Newton. Ses paramètres template sont :
                * g indique la manière dont vous souhaitez calculer le gradient et le hessien.
                    * g=0 (valeur par défaut) pour un calcul numérique à un espace espilon du point local.
                    * g=1 pour un calcul analytique du gradient, et numérique du hessien à partir du gradient analytique.
                    * g=2 pour un calcul analytique du gradient et du hessien.
                * T est le type de epsilon utilisé pour le calcul numérique du gradient ou du hessien. Sa valeur par défaut est "double"

        * TS est le type de recherche de pas que vous souhaitez utiliser. Vous avez le choix entre :
            * \a ConstantStep <T> pour un pas constant. Son paramètre template est :
                * T est le type du pas. Sa valeur par défaut est "double"

            * \a ArmijoStep <g,T> (valeur par défaut) pour un pas variable vérifiant la règle d'Armijo. Ses paramètres template sont :
                * g indique la manière dont vous souhaitez calculer le grad.
                    * g=0 (valeur par défaut) pour un gradient numérique calculé à un espace espilon du point local.
                    * g=1 pour un calcul analytique fourni par la fonction objectif
                * T est le type du pas, du parametre de la règle et de epsilon utilisé pour le calcul numérique du gradient

        * TC est le type de critère d'arret que vous souhaitez utiliser. Vous avez le choix entre :
            * \a IterationNumberCriterion pour un arret où bout d'un nombre d'itération donnés.

            * \a AbsoluteValueCriterion <T> pour un arret dès que la valeur de la fonction passe en dessous d'une certaine valeur objectif. Son paramètre template est :
                * T est le type de la valeur objecif. Sa valeur par défaut est "double"

            * \a RelativeValueCriterion <T> pour un arret dès que le rapport de la valeur de la fonction sur la valeur initiale passe en dessous d'une certaine valeur objectif. Son paramètre template est :
                * T est le type de la valeur objecif. Sa valeur par défaut est "double"

            * \a AbsoluteStepCriterion <T,s> pour un arret dès que la norme absolue de la difference entre deux points d'evaluations passe en dessous d'une certaine valeur objectif. Ses paramètres template sontt :
                * T est le type de la valeur objecif et des coordonnées des points d'évaluations. Sa valeur par défaut est "double"
                * s est la taille des points d'évaluations. Sa valeur par défaut est -1 (taille dynamique)

            * \a RelativeStepCriterion <T,s> pour un arret dès que la norme relative de la difference entre deux points d'evaluations passe en dessous d'une certaine valeur objectif. Ses paramètres template sontt :
                * T est le type de la valeur objecif et des coordonnées des points d'évaluations. Sa valeur par défaut est "double"
                * s est la taille des points d'évaluations. Sa valeur par défaut est -1 (taille dynamique)

    = \anchor foire Foire aux questions
        * Comment créer un créer un minisateur pour une fonction f de type TF ?
            \code C/C++
                LocalMinimizer<TF> lm(f); 
        * Comment obtenir le minimum de f en partant d'un vecteur x ?
            \code C/C++
                Vec<T> m=lm.solve(x); 
        * Comment modifier la valeur de epsilon pour le calcul du gradient ou du hessien ?
            \code C/C++
                lm.algorithm.epsilon = 42e-6 
        * Comment modifier la valeur du pas ?
            \code C/C++
                lm.step.value = 42e-3 
        * Comment modifier la valeur du parametre de la règle d'Armijo ?
            \code C/C++
                lm.step.parameter = 42e-3 
        * Comment modifier la valeur du critère d'arret ?
            \code C/C++
                lm.criterion.value = 42e-6 
        * Comment afficher les points d'évaluation au fur et a mesure de la minimisation ?
            \code C/C++
                LocalMinimizer<TF> lm(f,true); OU
                lm.print_res=true;
        * Comment afficher la valeur de la fonction objectif au fur et a mesure de la minimisation ?
            \code C/C++
                LocalMinimizer<TF> lm(f,true,true); OU
                lm.print_value=true;

    = \anchor ex Exemple d'utilisation

        Dans cet exemple, on cherche a minimiser une fonction de Rosenbrock. On part de (0,0) et on espère arriver à (1,1) en utilisant un algorithme de Newton avec un pas variable qui vaut initialement 0,5.

        Dans cet exemple, le gradient et le hessien de la fonction sont calculés de manière numérique. Vous pouvez faire le calcul de manière analytique en changeant les valeurs de g dans les parametres template de LocalMinimizer. Il faudra également décommenter la fonction grad de la classe Rosenbrock, et au besoin la fonction hessian.
        \code C/C++
            template <class T=double, int s=-1> struct Rosenbrock {
                Rosenbrock () {}
                T operator() (const Vec<T,s> &input) const {
                    return pow(input[0]-1,T(2))+4*pow(input[0]*input[0]-input[1],T(2));
                }
                Vec<T,s> grad (const Vec<T,s> &input) const {
                    Vec<T,s> res;
                    res.resize(2);
                    res[0]=2*(input[0]-1)+16*input[0]*(input[0]*input[0]-input[1]);
                    res[1]=-8*(input[0]*input[0]-input[1]);
                    return res;
                }
                Mat<T,Gen< s > > hessian (const Vec<T,s> &input) const {
                    Mat<T,Sym<> > res;
                    res.resize(2);
                    res(0,0)=T(2)+48*input[0]*input[0]-16*input[0]*input[1];
                    res(0,1)=-16*input[0]*input[0];
                    res(1,0)=-16*input[0]*input[0];
                    res(1,1)=T(8);
                    return res;
                }
            };
            
            int main(int argc,char **argv) {
                Rosenbrock<> ros;
                LocalMinimizer<Rosenbrock<>,NewtonAlgorithm<0>,ArmijoStep<0>,RelativeStepCriterion<> > newton_var(ros,1);
                newton_var.step.value=0.5;
                PRINT(newton_var.solve(Vec<T>(0,0)));
            } 


    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend camille.gouttebroze@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/
template <class TF, class TA=BfgsAlgorithm<>, class TS=ArmijoStep<>, class TC=RelativeStepCriterion<> >
struct LocalMinimizer {

    LocalMinimizer (TF &func, bool print_x=0 ) { f=&func; print_res=print_x; }

    template <class T, int s> Vec<T,s> solve(const Vec<T,s> &input) {
        Vec<T,s> res=input;
        for (;criterion.update(f,res);) {
            Vec<T,s> direction=algorithm.get_direction(f,res);
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
