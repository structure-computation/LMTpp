/***************************************************************************
                          Rectilinear_iterator.h  -  description
                             -------------------
    begin                : lun oct 21 2002
    copyright            : (C) 2002 by hleclerc
    email                : hleclerc@lmamef23
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef RECTILINEAR_ITERATOR_H
#define RECTILINEAR_ITERATOR_H

#include "containers/vec.h"

namespace LMT {

/// allows to sweep a multidimensional box, Pt \in [beg,end[
template<class T,int dim>
class Rectilinear_iterator {
public:
  typedef Vec<T,dim> Tvec;
  ///
  Rectilinear_iterator(Tvec beg,Tvec end,Tvec increment=Tvec(1)):lower(beg),upper(end),inc(increment) {
    pos=beg;
  }
  ///
  Rectilinear_iterator(T beg,T end,T increment=T(1)):lower(beg),upper(end),inc(increment) {
    pos=beg;
  }
  ///
  operator bool() const { return ( inc[dim-1]>0 ? pos[dim-1]<upper[dim-1] : pos[dim-1]>upper[dim-1] ); }
  ///
  Rectilinear_iterator &operator++() {
    pos[0]+=inc[0];
    for(int d=0;d<dim-1;d++) {
      if ( ( inc[d]>0 ? pos[d]>=upper[d] : pos[d]<=upper[d] ) ) {
        pos[d] = lower[d];
        pos[d+1] += inc[d+1];
      }
      else
        return *this;
    }
    return *this;
  }  
  /// pos[0]+pos[1]+...
  T sum_pos() const {
    T res = 0;
    for(int i=0;i<dim;++i)
      res += pos[i];
    return res;
  }
  
  /// THE datum
  Tvec pos;
  /// first corner of the box
  Tvec lower;
  /// second corner of the box
  Tvec upper;
  /// increment
  Tvec inc;
};

}

#endif // RECTILINEAR_ITERATOR_H
