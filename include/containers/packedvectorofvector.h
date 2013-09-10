//
// C++ Interface: packedvectorofvector
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_packedvectorofvector_HEADER
#define LMT_packedvectorofvector_HEADER

#include "vec.h"
#include "simpleiterator.h"

namespace LMT {

/*!
    PackedVectorOfVector est un type servant à stocker plusieurs vecteurs les uns après les autres dans un unique vecteur. 

    \friend samir.amrouche@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/
template<class T>
class PackedVectorOfVector {
public:
    PackedVectorOfVector() {}
    template<int s> PackedVectorOfVector(const Vec<Vec<T,s> > &vv) {
        offsets.resize( vv.size()+1 );
        offsets[0] = 0;
        for(unsigned i=0;i<vv.size();++i)
            offsets[i+1] = offsets[i] + vv[i].size();
        vec.resize( offsets.back() );
        for(unsigned i=0,cpt=0;i<vv.size();++i)
            for(unsigned j=0;j<vv[i].size();++j,++cpt)
                vec[cpt] = vv[i][j];
    }
    
    SimpleIterator<T> operator[](unsigned i) { return SimpleIterator<T>( vec.begin()+offsets[i], vec.begin()+offsets[i+1] ); }
    SimpleConstIterator<T> operator[](unsigned i) const { return SimpleConstIterator<T>( vec.begin()+offsets[i], vec.begin()+offsets[i+1] ); }
    
    void free() { vec.free(); offsets.free(); }
protected:
    Vec<T> vec;
    Vec<unsigned> offsets;
};

};

#endif // LMT_packedvectorofvector_HEADER
