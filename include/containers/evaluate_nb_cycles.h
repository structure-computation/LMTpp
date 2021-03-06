#ifndef EVALUATE_NB_CYCLES_H
#define EVALUATE_NB_CYCLES_H

#include <stdlib.h>
#include <stdio.h>
#include <sched.h>
#include <sys/mman.h>
#include <sys/time.h>

// #define crout_alain
#ifdef crout_alain
#include "crout.h"
extern Crout crout;
#endif

// inline void GetTick(long long &t) {
//     #ifdef NOx86
//         t = 0;
//     #else
//         __asm__ volatile ("RDTSC" : "=A" (t));
//     #endif
// }
// 
// inline long long getTick() {
//     long long t;
//     GetTick(t);
//     return t;
// }
// 
// template<class Op>
// long long evaluate_nb_cycles(Op &op) {
//     struct sched_param schedParam;
//     schedParam.sched_priority=sched_get_priority_max(SCHED_FIFO);
//     int err;
//     if ((err=sched_setscheduler(0,SCHED_FIFO,&schedParam))!=0) {
//         //std::cerr << "sched_setscheduler " << err << std::endl;
//         //exit(1);
//     }
//     mlockall(MCL_CURRENT);
// 
//     int size=1000000;
//     int *trash=new int[size];
//     while(--size) {
//         *(trash+size)=10;
//         *(trash+size)+=20;
//     }
//     delete trash;
// 
//     long long t1,t2;
//     GetTick(t1);
//     op();
//     GetTick(t2);
//     munlockall();
// 
//     return t2-t1;
// }

/*!
\keyword Utilitaires 
\brief Structure permettant de déterminer le temps écoulé entre deux instants donnés.

En délarant une instance de type TicToc, on détermine le temps écoulé en éxecutant la fonction :
\code
    TicToc t;
    t.start();
    ...code...
    t.stop();
    
L'appel de stop renvoit le temps éoulé en secondes. Un appel de start fait intervenir la fonction getTick() qui renvoit une information non exprimé en secondes. Il est alors nécessaire lorsque l'on fait la différence de deux getTick() de diviser par la fréquence du processeur. 

Pour cela, on peut renseigner le champ freq correspondant à la fréquence du processeur (par défaut 3.4 Ghz)
    

    @author Alain Caignot
      Dit "el Caignal"
*/
struct TicToc {
    TicToc(){}
    void start() { gettimeofday( &start1,&toto); }
    void stop() {
        gettimeofday( &stop1,&toto);
        res = ((double)stop1.tv_sec-(double)start1.tv_sec)+((double)stop1.tv_usec-(double)start1.tv_usec) / 1e6;
    }
    void print() { printf("%f\n",res); }
    struct timeval start1, stop1;
    struct timezone toto;
    double res;
};

inline double time_of_day_in_sec() {
    struct timeval st;
    struct timezone toto;
    gettimeofday( &st, &toto );
    return st.tv_sec + st.tv_usec / 1e6;
}

#ifdef crout_alain
struct TicToc2 {
    TicToc2(){}
    void start() { gettimeofday( &start1,&toto); }
    void stop() {
        gettimeofday( &stop1,&toto);
        res = ((double)stop1.tv_sec-(double)start1.tv_sec)+((double)stop1.tv_usec-(double)start1.tv_usec) / 1e6;
    }
    void print() { crout << res << "\n"; }
    struct timeval start1, stop1;
    struct timezone toto;
    double res;
};
#endif

#endif // EVALUATE_NB_CYCLES_H
