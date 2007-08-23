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

inline void GetTick(long long &t) {
    #ifdef NOx86
        t = 0;
    #else
        __asm__ volatile ("RDTSC" : "=A" (t));
    #endif
}

inline long long getTick() {
    long long t;
    GetTick(t);
    return t;
}

template<class Op>
long long evaluate_nb_cycles(Op &op) {
    struct sched_param schedParam;
    schedParam.sched_priority=sched_get_priority_max(SCHED_FIFO);
    int err;
    if ((err=sched_setscheduler(0,SCHED_FIFO,&schedParam))!=0) {
        //std::cerr << "sched_setscheduler " << err << std::endl;
        //exit(1);
    }
    mlockall(MCL_CURRENT);

    int size=1000000;
    int *trash=new int[size];
    while(--size) {
        *(trash+size)=10;
        *(trash+size)+=20;
    }
    delete trash;

    long long t1,t2;
    GetTick(t1);
    op();
    GetTick(t2);
    munlockall();

    return t2-t1;
}

/** \ingroup  Utilitaires 
\brief Structure permettant de d�erminer le temps �oul�entre deux instants donn�.

En d�larant une instance de type TicToc, on d�ermine le temps �oul�en ��utant la fonction :
\code
TicToc t;
t.start();
...code...
t.stop();
\endcode
L'appel de stop renvoit le temps �oul�en secondes. Un appel de start fait intervenir la fonction getTick() qui renvoit une information non exprim� en secondes. Il est alors n�essaire lorsque l'on fait la diff�ence de deux getTick() de diviser par la fr�uence du processeur. 

Pour cela, on peut renseigner le champ freq correspondant �la fr�uence du processeur (par d�aut 3.4 Ghz)
    
struct TicToc {
    TicToc(){freq = 3.4e9;}
    void start() { v = getTick(); }
    void stop(const char *sep="\n") { printf( "%f", (getTick()-v)/freq); printf(sep); }
    long long v;
    double freq;
};

    @author Alain Caignot
      Dit "el Caignal"
*/
struct TicToc {
    TicToc(){}
    void start() { gettimeofday( &start1,&toto); }
    void stop() {
         gettimeofday( &stop1,&toto);
         res = ((double)stop1.tv_sec-(double)start1.tv_sec)+((double)stop1.tv_usec-(double)start1.tv_usec) / 1e6;
         printf("%f\n",res);
    }
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
        crout << res << "\n";
    }
    struct timeval start1, stop1;
    struct timezone toto;
    double res;
};
#endif

#endif // EVALUATE_NB_CYCLES_H
