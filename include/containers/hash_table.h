#ifndef CONTAINERS_HASH_TABLE_H
#define CONTAINERS_HASH_TABLE_H

#include "vec.h"
#include "algo.h"

namespace LMT {

template<class K,class V,unsigned hash_size=256,class HashFunction=Function<C_1>,class NewValFunction=Function<C_1>,class EqualFunction=ExactlyEqual>
struct HashTable {
    struct Item {
        K key;
        V val;
    };
    
    struct SameKey {
        template<class Eq>
        bool operator()(const Item &i,const K &k,const Eq &eq) const { return eq( i.key, k ); }
    };

    V &operator()( const K &key, int hash_val ) {
        hash_val %= hash_size;
        Item *item = find_elem( data[ hash_val ], SameKey(), key, eq );
        if ( item )
            return item->val;
        // not found
        item = data[ hash_val ].new_elem();
        item->key = key;
        new_val_function( item->val );
        return item->val;
    }
    
    V &operator[]( const K &key ) {
        return operator()( key, hash_function( key ) );
    }
    
    V &insert( const K &key, const V &val ) {
        V &res = operator[]( key );
        res = val;
        return res;
    }
    
    Vec<Splitted<Item,256> > data[hash_size];
    HashFunction hash_function;
    NewValFunction new_val_function;
    EqualFunction eq;
};

}

#endif // CONTAINERS_HASH_TABLE_H
