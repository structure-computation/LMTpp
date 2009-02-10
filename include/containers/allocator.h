//
// C++ Interface: %{MODULE}
//
// Description: 
//
//
// Author: %{AUTHOR} <%{EMAIL}>, (C) %{YEAR}
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_ALLOCATOR_HEADER
#define LMT_ALLOCATOR_HEADER

#include "config.h"
#include "basicops.h"
#include <assert.h>
#include <stdlib.h>
#ifndef WITHOUT_MALLOC
    #include <malloc.h>
#endif
// #define PRINT_ALLOC
#ifdef PRINT_ALLOC
    #include <map>
#endif

namespace LMT {

struct AllocateWithNew { };
struct AllocateWithMalloc { };

template<unsigned p> struct NextPow2 { static const unsigned res = 2 * NextPow2< p / 2 >::res; };
template<> struct NextPow2<0> { static const unsigned res = 0; };
template<> struct NextPow2<1> { static const unsigned res = 1; };


#ifdef PRINT_ALLOC
extern std::map<std::string,long long> total_allocated;


/*!
    Cette fonction affiche le nombre d'octets que prend chaque fonction. Elle s'utilise avec la classe \a Allocator .
    
    Pour l'utiliser :
        "-DPRINT_ALLOC" dans les flags de compilation
        "std::map<std::string,long long> total_allocated;" dans un .cpp (quelconque)
        et après, disp_alloc("toto"); affichera toto puis une liste de types d'objets et la place qu'ils prennent en mémoire.
        ou sum_alloc(); renvoie la taille totale utilisée par les objets LMTpp
    
    \friend raphael.pasquier@lmt.ens-cachan.fr
*/
inline void disp_alloc(const char *prefix="") {
    long long s = 0;
    for(std::map<std::string,long long>::const_iterator iter=total_allocated.begin();iter!=total_allocated.end();++iter) {
        if ( iter->second ) {
            std::cout << prefix << iter->second << " " << std::flush;
            system( ( "c++filt " + iter->first ).c_str() );
            s += iter->second;
        }
    }
    std::cout << prefix << "sum -> " << s << std::endl;
}
inline long long sum_alloc() {
    long long s = 0;
    for(std::map<std::string,long long>::const_iterator iter=total_allocated.begin();iter!=total_allocated.end();++iter)
        s += iter->second;
    return s;
}
#endif

/** */
template<class T,unsigned alignement,class TypeAlloc=AllocateWithNew> struct Allocator;

template<class T,unsigned alignement>
struct Allocator<T,alignement,AllocateWithMalloc> {
    static const unsigned al = NextPow2<alignement*sizeof(T)>::res;
    T *allocate(unsigned size) {
        #ifdef PRINT_ALLOC
        allocated = size * sizeof(T);
        total_allocated[ typeid(T).name() ] += allocated;
        #endif
        #ifndef WITHOUT_MALLOC
            T *res = (T *)memalign( MAX(al,sizeof(void*)), size*sizeof(T) );
            if ( !res ) {
                std::cerr << "Problème d'allocation : il est impossible de réserver " << size*sizeof(T) << " octets." << std::endl;
                assert(0);
            }
            return res;
        #else
            alloc_ptr = (T *)malloc( size*sizeof(T) + al -1 );
            if ( !alloc_ptr ) {
                std::cerr << "Problème d'allocation : il est impossible de réserver " << size*sizeof(T) << " octets." << std::endl;
                assert(0);
            }
        return alloc_ptr + ((alignement-(((long)alloc_ptr/sizeof(T))%alignement))%alignement);
        #endif
    }
    void free_mem(T *v) {
        #ifdef PRINT_ALLOC
        if ( v ) total_allocated[ typeid(T).name() ] -= allocated;
        #endif
        #ifndef WITHOUT_MALLOC
            if ( v ) free(v);
        #else
            if ( v ) free(alloc_ptr);
        #endif
    }
    void clear() {
        #ifdef WITHOUT_MALLOC
            alloc_ptr = NULL;
        #endif
        #ifdef PRINT_ALLOC
        allocated = 0;
        #endif
    }
    #ifdef WITHOUT_MALLOC
        T *alloc_ptr;
    #endif
    #ifdef PRINT_ALLOC
    long long allocated;
    #endif
};

template<class T,unsigned alignement>
struct Allocator<T,alignement,AllocateWithNew> {
    Allocator():alloc_ptr(NULL) {}
    T *allocate(unsigned size) {
        #ifdef PRINT_ALLOC
        allocated = size * sizeof(T);
        total_allocated[ typeid(T).name() ] += allocated;
        #endif
        
        alloc_ptr = new T[size+alignement-1];
        if ( !alloc_ptr )
            std::cerr << "Problème d'allocation : il est impossible de réserver " << size*sizeof(T) << " octets (avec alignement=" << alignement << ")." << std::endl;
            //             std::cerr << "Allocation pb" << std::endl;
        return alloc_ptr + ((alignement-(((long)alloc_ptr/sizeof(T))%alignement))%alignement);
    }
    void free_mem(T *v) {
        #ifdef PRINT_ALLOC
        if ( v ) total_allocated[ typeid(T).name() ] -= allocated;
        #endif
        if ( v ) delete [] alloc_ptr;
    }
    
    void clear() {
        alloc_ptr = NULL;
        #ifdef PRINT_ALLOC
        allocated = 0;
        #endif
    }
    
    T *alloc_ptr;
    #ifdef PRINT_ALLOC
    long long allocated;
    #endif
};

/** To be specialized for each type, to say if you want malloc, new, ...
  By default, alignement=1 and new is the preferred procedure, except for base types like float, double
  for which we prefere malloc (or memalign) and alignement can be > 1 (according to config.h)
 */
template<class TS>
struct PreferredAllocator {
    typedef Allocator<TS,1,AllocateWithNew> T;
};

template<> struct PreferredAllocator<unsigned> { typedef Allocator<unsigned,LMT_ALIGNEMENT_unsigned,AllocateWithMalloc> T; static const unsigned align=LMT_ALIGNEMENT_unsigned; };
template<> struct PreferredAllocator<int     > { typedef Allocator<int     ,LMT_ALIGNEMENT_int     ,AllocateWithMalloc> T; static const unsigned align=LMT_ALIGNEMENT_int     ; };
template<> struct PreferredAllocator<double  > { typedef Allocator<double  ,LMT_ALIGNEMENT_double  ,AllocateWithMalloc> T; static const unsigned align=LMT_ALIGNEMENT_double  ; };
template<> struct PreferredAllocator<float   > { typedef Allocator<float   ,LMT_ALIGNEMENT_float   ,AllocateWithMalloc> T; static const unsigned align=LMT_ALIGNEMENT_float   ; };
template<> struct PreferredAllocator<char    > { typedef Allocator<char    ,LMT_ALIGNEMENT_char    ,AllocateWithMalloc> T; static const unsigned align=LMT_ALIGNEMENT_char    ; };
template<> struct PreferredAllocator<bool    > { typedef Allocator<bool    ,1                      ,AllocateWithMalloc> T; static const unsigned align=1                      ; };


}

#endif // LMT_ALLOCATOR_HEADER
