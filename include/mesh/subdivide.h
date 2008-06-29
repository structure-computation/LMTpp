#ifndef MESH_SUBDIVIDE_H
#define MESH_SUBDIVIDE_H

namespace LMT {

template<class TM1,class TM2>
Vec<int> subdivide( TM1 &r, const TM2 &m ) {
    r = m;
}

}

#endif // MESH_SUBDIVIDE_H
