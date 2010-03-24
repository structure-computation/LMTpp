#ifndef GENERIC_MATRIX_H
#define GENERIC_MATRIX_H

namespace LMT {

template<class T>
struct GenericMatrix {
    virtual Vec<T> solve(const Vec<T> &x) = 0;
};

}

#endif // GENERIC_MATRIX_H
