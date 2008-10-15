#ifndef LMT_radix_sort_HEADER
#define LMT_radix_sort_HEADER

#include <containers/vec.h>

namespace LMT {


/**
    \code
        struct MonTrucAClasser {
            unsigned unsigned_for_radix_sort() const {
                return val;
            }
            unsigned val;
        };
        
        using namespace LMT;
        int main() {
            Vec<MonTrucAClasser> v;
            for(unsigned i=0;i<16;++i)
                v.new_elem()->val = rand();
            
            for(unsigned i=0;i<v.size();++i)
                std::cout << v[i].val << " ";
            std::cout << std::endl;
            
            Vec<MonTrucAClasser *> r = radix_sort( v );
            
            for(unsigned i=0;i<r.size() - 1;++i)
                std::cout << r[i+1]->val - r[i]->val << " ";
            std::cout << std::endl;
        }
*/
template<class TV,class UnsignedExtraction>
Vec<typename TV::template SubType<0>::T *> radix_sort( const TV &vn, const UnsignedExtraction &ue ) {
    typedef typename TV::template SubType<0>::T T;
    
    static const unsigned nb_bits  = 8;
    static const unsigned nb_steps = 32 / nb_bits;
    static const unsigned nb_terms = 2 << nb_bits;
    
    Vec<T *> res; res.reserve( vn.size() );
    apply( vn, PushBackPtr(), res );
    
    for(unsigned num_step=0, shift=0; num_step<nb_steps; ++num_step, shift += nb_bits ) {
        // nb items per bucket
        unsigned sizes[ nb_terms ];
        for(unsigned i=0;i<nb_terms;++i)
            sizes[ i ] = 0;
        for(unsigned i=0;i<res.size();++i) {
            unsigned int_val = ue( *res[ i ] ) >> shift;
            sizes[ int_val % nb_terms ]++;
        }
        
        // accumulation
        unsigned offsets[ nb_terms ];
        for( unsigned i=0, acc=0; i<nb_terms; acc += sizes[ i ], ++i )
            offsets[ i ] = acc;
        
        // partially sorted list
        Vec<T *> new_res; new_res.resize( res.size() );
        for(unsigned i=0;i<res.size();++i) {
            unsigned int_val = ue( *res[ i ] ) >> shift;
            new_res[ offsets[ int_val % nb_terms ] ++ ] = res[ i ];
        }
        res = new_res;
    }
    
    return res;
}

struct UnsignedExtractionStd {
    template<class T> unsigned operator()( const T &v ) const {
        return v.unsigned_for_radix_sort();
    }
};

template<class TV>
Vec<typename TV::template SubType<0>::T *> radix_sort( const TV &vn ) {
    return radix_sort( vn, UnsignedExtractionStd() );
}

/**
    \code
        Vec<unsigned> l( 700,6,4,5,1,3,5,4,9 );
        Vec<unsigned> ind = radix_sort_with_index( l );
        PRINT( l[ind] );
*/
template<class T,int s,class UE>
Vec<unsigned,s> radix_sort_with_index( const Vec<T,s> &vn, const UE &ue ) {
    static const unsigned nb_bits  = 8;
    static const unsigned nb_steps = 32 / nb_bits;
    static const unsigned nb_terms = 2 << nb_bits;
    
    Vec<unsigned> res; res = range( vn.size() );
    for(unsigned num_step=0, shift=0; num_step<nb_steps; ++num_step, shift += nb_bits ) {
        // nb items per bucket
        unsigned sizes[ nb_terms ];
        for(unsigned i=0;i<nb_terms;++i)
            sizes[ i ] = 0;
        for(unsigned i=0;i<res.size();++i) {
            unsigned int_val = ue( vn[ res[ i ] ] ) >> shift;
            sizes[ int_val % nb_terms ]++;
        }
        
        // accumulation
        unsigned offsets[ nb_terms ];
        for( unsigned i=0, acc=0; i<nb_terms; acc += sizes[ i ], ++i )
            offsets[ i ] = acc;
        
        // partially sorted list
        Vec<unsigned> new_res; new_res.resize( res.size() );
        for(unsigned i=0;i<res.size();++i) {
            unsigned int_val = ue( vn[ res[ i ] ] ) >> shift;
            new_res[ offsets[ int_val % nb_terms ] ++ ] = res[ i ];
        }
        res = new_res;
    }
    
    return res;
}

template<class T,int s,class UE>
Vec<unsigned,s> radix_sort_with_index( const Vec<unsigned,s> &vn ) {
    return radix_sort_with_index( vn, Function<C_1>() );
}


}


#endif // LMT_radix_sort_HEADER
