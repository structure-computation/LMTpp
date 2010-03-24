//
// C++ Interface: storebyrefif
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_storebyrefif_HEADER
#define LMT_storebyrefif_HEADER

namespace LMT {

/**
    if store_by_ref==true -> stores as const T &val.
    
    if store_by_ref==false -> stores as T val.
    
    should be specialized for heavy structures like Mat<> to store as a reference.
*/
template<class T,bool store_by_ref> struct StoreByRefIf;

template<class T> struct StoreByRefIf<T,false> {
    StoreByRefIf(const T &v):val(v) {}
    T val;
};
template<class T> struct StoreByRefIf<T,true> {
    StoreByRefIf(const T &v):val(v) {}
    const T &val;
};

};

#endif // LMT_storebyrefif_HEADER
