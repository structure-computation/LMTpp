#ifndef LMT_GMRES_HEADER
#define LMT_GMRES_HEADER

#include "mat.h"

namespace LMT {

template<class TM,class TV>
Vec<typename TypePromote< Divides, typename TV::template SubType<0>::T,typename TM::T>::T> gmres(const TM &m,const TV &v,typename TM::T prec=1e-9,unsigned max_nb_iter=50) {
    
    return v;
}

};

#endif // LMT_GMRES_HEADER
