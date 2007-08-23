#ifndef KERNEL_H
#ifndef KERNEL_H


namespace LMT {

///
template<class T,unsigned dim,class Type> struct DiffuseApproximationKernel { };

///
template<class T,unsigned dim> struct DiffuseApproximationKernel<T,dim,DiffuseApproximation_Kernel_N2> {
    
    Vec<T,dim> pos;
    T r;
};



}

#endif // KERNEL_H
