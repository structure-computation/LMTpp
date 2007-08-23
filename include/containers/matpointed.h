//
// C++ Interface: matpointed
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matpointed_HEADER
#define LMT_matpointed_HEADER

namespace LMT {

template<class TM,bool const_mat=false>
struct MatPointed { };

template<class TM,bool const_mat> struct IsMatOp<MatPointed<TM,const_mat> > { typedef int T; };

/**
 * stored a pointer on matrix. *this acts as a scale * matrix where scale 
 */
template<class TM_,bool const_mat,class Structure,class Storage>
class Mat<MatPointed<TM_,const_mat>,Structure,Storage,int> {
public:
    typedef TM_ TM;
    typedef typename TM::T T;
    
    Mat():scale(1.0) { m.val = 0; }
    
    Mat(const TM &_m):scale(1.0) { m.val = &_m; }

    unsigned nb_rows() const { return m.val->nb_rows(); }
    unsigned nb_cols() const { return m.val->nb_cols(); }
    
    T operator()(unsigned i,unsigned j) const {
        if ( m.val )
            return scale * (*m.val)(i,j);
        return 0;
    }
    
    PtrConstIf<TM,const_mat> m;
    T scale;
};

};

#endif // LMT_matpointed_HEADER
