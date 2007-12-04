//
// C++ Interface: vecparticularcases
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_vecparticularcases_HEADER
#define LMT_vecparticularcases_HEADER

namespace LMT {

template<class T1,int s1,class T2,int s2>
typename TypePromote<Multiplies,typename Vec<Sparse<T1>,s1>::template SubType<0>::T,typename Vec<T2,s2>::template SubType<0>::T>::T
dot( const Vec<Sparse<T1>,s1> &v1, const Vec<T2,s2> &v2 ) {
    typedef typename TypePromote<Multiplies,typename Vec<Sparse<T1>,s1>::template SubType<0>::T,typename Vec<T2,s2>::template SubType<0>::T>::T T;
    T res = 0;
    for(unsigned i=0;i<v1.indices.size();++i)
        res += v1.data[i] * v2[ v1.indices[i] ];
    return res;
}

template<class T1,int s1,class T2,int s2>
typename TypePromote<Multiplies,typename Vec<T1,s1>::template SubType<0>::T,typename Vec<Sparse<T2>,s2>::template SubType<0>::T>::T
dot( const Vec<T1,s1> &v1, const Vec<Sparse<T2>,s2> &v2 ) {
    typedef typename TypePromote<Multiplies,typename Vec<T1,s1>::template SubType<0>::T,typename Vec<Sparse<T2>,s2>::template SubType<0>::T>::T T;
    T res = 0;
    for(unsigned i=0;i<v2.indices.size();++i)
        res += v2.data[i] * v1[ v2.indices[i] ];
    return res;
}

template<class T1,int s1,class T2,int s2>
typename TypePromote<Multiplies,typename Vec<T1,s1>::template SubType<0>::T,typename Vec<Sparse<T2>,s2>::template SubType<0>::T>::T
dot( const Vec<Sparse<T1>,s1> &v1, const Vec<Sparse<T2>,s2> &v2 ) {
    typedef typename TypePromote<Multiplies,typename Vec<T1,s1>::template SubType<0>::T,typename Vec<Sparse<T2>,s2>::template SubType<0>::T>::T T;
    T res = 0;
    if ( v1.indices.size() and v2.indices.size() ) {
        unsigned i1 = 0, i2 = 0;
        while ( true ) {
            if ( v1.indices[i1] == v2.indices[i2] ) {
                res += v1.data[i1] * v2.data[i2];
                if ( ++i1 >= v1.indices.size() )
                    break;
                if ( ++i2 >= v2.indices.size() )
                    break;
            }
            else if ( v1.indices[i1] < v2.indices[i2] ) {
                if ( ++i1 >= v1.indices.size() )
                    break;
            }
            else {
                if ( ++i2 >= v2.indices.size() )
                    break;
            }
        }
    }
    return res;
}

};

#endif // LMT_vecparticularcases_HEADER
