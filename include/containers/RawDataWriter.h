#ifndef LMT_CONTAINERS_RawDataWriter_HEADER
#define LMT_CONTAINERS_RawDataWriter_HEADER

#include "vec.h"

namespace LMT {

/**
\example    
    RawDataWriter rd;
    for(unsigned i=0;i<10000;++i) {
        char *a = rd.new_elem( StructForType<char>() );
        *a = (char)i;
    }
    char *c = rd.to_contiguous();
    for(unsigned i=0;i<rd.size();++i)
        std::cout << (int)c[i] << " ";
    std::cout << std::endl;
    free( c );

*/
struct RawDataWriter {
    static const int atomic_size = 4096;
    
    struct Atom {
        Atom *next;
        int reserved;
        int size;
        char data[ 4 ];
    };
    
    RawDataWriter() : first(NULL), last(NULL), size_(0) { }
    
    ~RawDataWriter() {
        for( Atom *a = first; a;  ) {
            Atom *o = a;
            a = a->next;
            free( o );
        }
    }
    
    template<class T>
    T *new_elem( const StructForType<T> &, int nb = 1 ) {
        int s = sizeof( T ) * nb;
        if ( not first )
            first = make_reservation( s );
        else if ( last->size + s >= last->reserved )
            make_reservation( s );
        //
        T *res = reinterpret_cast<T *>( last->data + last->size );
        for(int i=0;i<nb;++i) {
            new ( last->data + last->size ) T;
            last->size += sizeof( T );
            size_ += sizeof( T );
        }
        return res;
    }
    
    template<class T>
    T *push_back( const T &val ) {
        T *res = new_elem( StructForType<T>() );
        *res = val;
        return res;
    }
    
    void make_alignment( int al ) {
        int s = ceil( size_, al ) - size_;
        if ( s ) {
            char *r = new_elem( StructForType<char>(), s );
            for(int i=0;i<s;++i)
                r[i] = 0;
        }
    }
    
    char *to_contiguous() const {
        char *res = (char *)malloc( size() ), *ptr = res;
        for( Atom *a = first; a; ptr += a->size, a = a->next )
            memcpy( ptr, a->data, a->size );
        return res;
    }
    
    int size() const {
        return size_;
    }
private:
    Atom *make_reservation( int for_at_least ) {
        int reservation = max( for_at_least, atomic_size );
        Atom *res = ( Atom * )malloc( sizeof( Atom ) - 4 + reservation );
        res->next = NULL;
        res->reserved = reservation;
        res->size = 0;
        //
        if ( last )
            last->next = res;
        last = res;
        return res;
    }
    
    Atom *first, *last;
    int size_;
};

}

#endif // LMT_CONTAINERS_RawDataWriter_HEADER
