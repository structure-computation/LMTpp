#ifndef VECGPU_H
#define VECGPU_H

#include <cuda_runtime.h>
#include <containers/vec.h>
#include <cutil.h>

namespace LMT {

template<class T,bool on_gpu=true>
struct VecGPU {
    typedef int ST;

    VecGPU() : data(NULL), size_(0) { }
    
    template<bool m_on_gpu>
    VecGPU( const VecGPU<T,m_on_gpu> &v ) {
        size_ = v.size_;
        if ( on_gpu )
            CUDA_SAFE_CALL( cudaMalloc( (void**)&data, size_ * sizeof(T) ) );
        else
            data = new T[ size_ ];
        cudaMemcpyKind k[] = { cudaMemcpyHostToHost, cudaMemcpyDeviceToHost, cudaMemcpyHostToDevice, cudaMemcpyDeviceToDevice };
        CUDA_SAFE_CALL( cudaMemcpy( data, v.data, size_ * sizeof(T), k[ 2 * on_gpu + m_on_gpu ] ) );
    }
    
    VecGPU( const Vec<T> &v ) {
        init( v );
    }
    
    void operator=( const Vec<T> &v ) {
        assert( not data );
        init( v );
    }
    
    void init( const Vec<T> &v ) {
        size_ = v.size();
        if ( on_gpu )
            CUDA_SAFE_CALL( cudaMalloc( (void**)&data, size_ * sizeof(T) ) );
        else
            data = new T[ size_ ];
        cudaMemcpyKind k[] = { cudaMemcpyHostToHost, cudaMemcpyHostToDevice };
        CUDA_SAFE_CALL( cudaMemcpy( data, v.ptr(), size_ * sizeof(T), k[ on_gpu ] ) );
    }    
    
    ~VecGPU() {
        if ( on_gpu ) {
            if ( data )
                cudaFree( data );
        }
        else
            delete [] data;
    }

    ST size() const { return size_; }

    operator Vec<T>() const {
        if ( on_gpu )
            return VecGPU<T,false>( *this );
        Vec<T> res; res.resize( size_ );
        for(int i=0;i<size_;++i)
            res[i] = data[i];
        return res;
    }

    T *copy() const {
        assert( on_gpu );
        T *res;
        CUDA_SAFE_CALL( cudaMalloc( (void **)&res, size_ * sizeof(T) ) );
        CUDA_SAFE_CALL( cudaMemcpy( res, data, size_ * sizeof(T), cudaMemcpyDeviceToDevice ) );
        return res;
    }

    T *ptr() {
        return data;
    }

    T *data;
    ST size_;
};

template<class T>
std::ostream &operator<<( std::ostream &os, const VecGPU<T,false> &V ) {
    for(unsigned i=0;i<V.size();++i)
        os << V.data[i] << " ";
    return os;
}

template<class T>
std::ostream &operator<<( std::ostream &os, const VecGPU<T,true> &W ) {
    VecGPU<T,false> V( W );
    for(unsigned i=0;i<V.size();++i)
        os << V.data[i] << " ";
    return os;
}

}

#endif // VECGPU_H
