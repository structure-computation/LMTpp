#ifndef SORTED_LIST_H
#define SORTED_LIST_H

/**
    T must contain T *next and T* prev as attributes
*/
template<class T>
struct SortedList {
    SortedList() : beg( NULL ), end( NULL ) {
    }
    
    void push_sup( T *v ) { // push a > element
        v->next = NULL;
        v->prev = end;
        end = v;
    }
    
    
    T *beg;
    T *end;
};

#endif // SORTED_LIST_H
