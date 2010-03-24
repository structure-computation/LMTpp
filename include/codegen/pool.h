//
// C++ Interface: codegen_vector
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo_lec@club-internet.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include <stdlib.h>
#include <stdio.h>

namespace Codegen {

/// stores T objects in a contiguous way.
template<class T,unsigned sub_pool_size=1024>
class Pool {
public:
    Pool():sub_pools(NULL),nb_sub_pools(0) {}
    ~Pool();
    /// reserve room for a new T and return adress
    T *newSlot();
    /// say that *s will not be used anymore. If s==NULL, don't do anything
    void deleteSlot(const T *s);
private:
    struct Sub_pool {
        Sub_pool();
        void del() {
            delete [] data;
            free(disponible_slots);
        }
        bool full() { return (nb_disponible_slots==0); }
        T *newSlot() { return disponible_slots[--nb_disponible_slots]; }
        void deleteSlot(const T *s) { data[s-data] = T(); disponible_slots[nb_disponible_slots++] = &data[s-data]; }
        
        T *data;
        T **disponible_slots;
        unsigned nb_disponible_slots;
    };
    Sub_pool *sub_pools;
    unsigned nb_sub_pools;
};

template<class T,unsigned sub_pool_size>
T *Pool<T,sub_pool_size>::newSlot() {
    for(unsigned i=0;i<nb_sub_pools;++i)
        if ( ! sub_pools[i].full() )
            return sub_pools[i].newSlot();
    sub_pools = (Sub_pool *)realloc( sub_pools, (++nb_sub_pools)*sizeof(Sub_pool) );
    sub_pools[nb_sub_pools-1] = Sub_pool();
    return sub_pools[nb_sub_pools-1].newSlot();
}

template<class T,unsigned sub_pool_size>
Pool<T,sub_pool_size>::~Pool() {
    for(unsigned i=0;i<nb_sub_pools;++i)
        sub_pools[i].del();
    free(sub_pools);
}

template<class T,unsigned sub_pool_size>
void Pool<T,sub_pool_size>::deleteSlot(const T *s) {
    if ( s==NULL ) return;
    for(unsigned i=0;i<nb_sub_pools;++i) {
        if ( s>=sub_pools[i].data && s<sub_pools[i].data+sub_pool_size ) {
            sub_pools[i].deleteSlot(s);
            // if sub_pools[i] does not contain any object anymore, delete it
            if ( sub_pools[i].nb_disponible_slots==sub_pool_size ) {
                sub_pools[i].del();
                sub_pools[i] = sub_pools[--nb_sub_pools];
                sub_pools = (Sub_pool *)realloc( sub_pools, nb_sub_pools*sizeof(Sub_pool) );
                if ( nb_sub_pools==0 )
                    free(sub_pools);
            }
            return;
        }
    }
}

template<class T,unsigned sub_pool_size>
Pool<T,sub_pool_size>::Sub_pool::Sub_pool() {
    data = new T[sub_pool_size];
    disponible_slots = (T **)malloc( sub_pool_size * sizeof(T*) );
    nb_disponible_slots = sub_pool_size;
    T *ptr = data;
    for(unsigned i=0;i<sub_pool_size;++i)
        disponible_slots[i] = ptr++;
}

}
