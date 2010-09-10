#ifndef MATSPARSEOP_H
#define MATSPARSEOP_H

template<class T>
Mat<T,Gen<> > operator*(const Mat<T,Gen<> > &a,const Mat<T,Sym<>,SparseLine<> > &b) {
    Mat<T,Gen<> > res( a.nb_rows(), b.nb_cols() );
    // upper part of b
    for(unsigned i=0;i<a.nb_rows();++i) {
        for(unsigned j=0;j<b.nb_cols();++j) {
            T r = T(0);
            for(unsigned k=0;k<b.data[j].indices.size();++k)
                r += a(i,b.data[j].indices[k]) * b.data[j].data[k];
            res(i,j) = r;
        }
    }
    // lower part of b
    for(unsigned i=0;i<a.nb_rows();++i)
        for(unsigned j=0;j<b.nb_cols();++j)
            for(int k=0;k<(int)b.data[j].indices.size() - (b.data[j].indices.size() and b.data[j].indices.back()==j);++k) // without diag
                res( i, b.data[j].indices[k] ) += a( i, j ) * b.data[j].data[k];
    return res;
}

/// cette surdéfinition de * rentre en conflit avec le code de construct_matrix()
// template<class T>
// Mat<T,Gen<> > operator*(const Mat<T,Sym<>,SparseLine<> > &a,const Mat<T,Gen<> > &b) {
//     Mat<T,Gen<> > res( a.nb_rows(), b.nb_cols() );
//     // upper part of b
//     for(unsigned i=0;i<a.nb_rows();++i) {
//         for(unsigned j=0;j<b.nb_cols();++j) {
//             T r = T(0);
//             for(unsigned k=0;k<a.data[i].indices.size();++k)
//                 r += a.data[i].data[k] * b(a.data[i].indices[k],j);
//             res(i,j) = r;
//         }
//     }
//     // lower part of b
//     for(unsigned i=0;i<a.nb_rows();++i)
//         for(unsigned j=0;j<b.nb_cols();++j)
//             for(int k=0;k<(int)a.data[i].indices.size() - (a.data[i].indices.size() and a.data[i].indices.back()==i);++k) // without diag
//                 res( a.data[i].indices[k], j ) += a.data[i].data[k] * b( i, j );
//     return res;
// }

#endif // MATSPARSEOP_H
