//
// C++ Interface: MaterialPoint
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_MaterialPoint_HEADER
#define LMT_MaterialPoint_HEADER

#include "mat.h"

namespace LMT {

/// \{

/// contains a deplacement and a rotation field. Equivalent to a torsor.
template<class T,unsigned dim>
class MaterialPoint {
public:
    typedef Vec<T,dim> Pvec;
    typedef Vec<dim-(dim==2),T> Rvec;
    
    MaterialPoint() {}
    MaterialPoint(const T &val) { dep=val; rot=val; }
    MaterialPoint(const Pvec &d,const Rvec &r):dep(d),rot(r) {}
    
    void operator*=(const T &v) { *this = v * *this; }
    void operator+=(const MaterialPoint &m) { dep += m.dep; rot += m.rot; }
    
    /// deplacement
    Pvec dep;
    /// rotation ( vector of dim 1 in 2D, 3 in 3D )
    Rvec rot;
};

/**
 \relates LMT::MaterialPoint
 */
template<unsigned dim,class T1,class T2>
inline typename TypePromoteAdd<T1,T2>::T dot(const MaterialPoint<T1,dim> &p1,const MaterialPoint<T2,dim> &p2) {
    return dot(p1.dep,p2.dep) + dot(p1.rot,p2.rot);
}

/**
 \relates LMT::MaterialPoint
 */
template<unsigned dim,class T>
inline MaterialPoint<T,dim> conj(const MaterialPoint<T,dim> &v1) {
    return MaterialPoint<T,dim>( conj( v1.dep ), conj( v1.rot ) );
}

/**
 \relates LMT::MaterialPoint
 */
template<unsigned dim,class T1,class T2>
inline MaterialPoint<typename TypePromoteAdd<T1,T2>::T,dim> operator*(const MaterialPoint<T1,dim> &p1,const T2 &p2) {
    return MaterialPoint<typename TypePromoteAdd<T1,T2>::T,dim>( p1.dep * p2, p1.rot * p2);
}
/**
 \relates LMT::MaterialPoint
 */
template<unsigned dim,class T2,class T1>
inline MaterialPoint<typename TypePromoteAdd<T1,T2>::T,dim> operator*(const T2 &p2,const MaterialPoint<T1,dim> &p1) {
    return MaterialPoint<typename TypePromoteAdd<T1,T2>::T,dim>( p2 * p1.dep, p2 * p1.rot );
}

/**
 \relates LMT::MaterialPoint
 output without carriage returns
 */
template<unsigned dim,class T>
std::ostream &line_output( std::ostream &s, const MaterialPoint<T,dim> &v ) {
    return s << v.dep << " " << v.rot;
}
/**
 \relates LMT::MaterialPoint
 */
template<unsigned dim,class T>
std::istream &line_input( std::istream &s, MaterialPoint<T,dim> &v ) {
    return s >> v.dep >> v.rot;
}

/** output with carriage returns
 \relates LMT::MaterialPoint
 */
template<unsigned dim,class T>
std::ostream &operator<<( std::ostream &s, const MaterialPoint<T,dim> &v ) {
    return s << v.dep << " " << v.rot;
}


/// \}

};

#endif // LMT_MaterialPoint_HEADER
