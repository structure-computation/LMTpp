/***************************************************************************
                          convergence_criteria.h  -  description
                             -------------------
    begin                : lun jun 17 2002
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
#ifndef CONVERGENCE_CRITERIA_H
#define CONVERGENCE_CRITERIA_H

/// A convergence criteria
template<class Name_criteria,class T>
struct Convergence_criterium {};

/// Example of a convergence criteria
struct Norm2_is_inf {};

/// Specialization for Norm2_is_inf
template<class T>
struct Convergence_criterium<Norm2_is_inf,T> {
    template<class TS>
    T operator()(const TS &syst) {
        T res=T(0);
        for(int i=0;i<syst.size();++i)
            res+=pow(syst.vectors[0](i)-syst.old_vec(i),2);
        return sqrt(res);
    }
};

/// Example of a convergence criteria
struct Norm1_is_inf {};

/// Specialization for Norm1_is_inf
template<class T>
struct Convergence_criterium<Norm1_is_inf,T> {
    template<class TS>
    T operator()(const TS &syst) {
        using namespace std;
        T res = T(0);
        for(unsigned i=0;i<syst.size();++i)
            res = max( res, abs(syst.old_vec(i)-syst.vecs[0](i)) );
        return res;
    }
};

#endif
