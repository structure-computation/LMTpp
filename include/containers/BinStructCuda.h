#include "containers/vec.h"
#include "containers/CudaHelper.h"

namespace LMT {

#define APPLY_BS( res, n ) res.apply( #n, n )

struct BinStructCudaMakeCpp {
    template<class T>
    void apply( const char *name, const Vec<T> & ) {
        std::cout << "    Vec<" << TypeInformation<T>::type() << "> " << name << ";\n";
    }
    template<class T>
    void apply( const char *name, const Vec<Vec<T> > & ) {
        std::cout << "    Vec<Vec<" << TypeInformation<T>::type() << "> > " << name << ";\n";
    }
};

template<bool gpu>
struct BinStructCudaGetRoomAndCopyData {
    typedef int I;
    typedef typename AlternativeOnType<gpu,size_t,int>::T P;
    static const int alig = gpu ? 16 * 4 : 16;

    struct TV {
        TV() {}
        TV( I len, P ptr ) : len( len ), ptr( ptr ) {}

        I len;
        P ptr;
    };

    BinStructCudaGetRoomAndCopyData() {
    }

    void begin_phase_1() {
        copy_data = false;

        head = 0;
        data = 0;
    }

    void begin_phase_2() {
        copy_data = true;

        int room = ceil( head, alig ) + data;
        if ( gpu )
            cudaMalloc( &pt, room );
        else
            pt = reinterpret_cast<char *>( malloc( room ) );
        tm = (char *)malloc( head ); // local

        data = ceil( head, alig );
        head = 0;
    }

    void begin_phase_3() {
        cudaMemcpy( pt, tm, head, gpu ? cudaMemcpyDeviceToHost : cudaMemcpyHostToHost );
    }

    template<class T>
    P append_head( const T &val ) {
        if ( copy_data )
            *reinterpret_cast<T *>( tm + head ) = val;
        P res = P( SizeType( pt + head ) );
        head += sizeof( T ); // len
        return res;
    }

    template<class T>
    P append_data( const T &val ) {
        if ( copy_data )
            cudaMemcpy( pt + data, &val, sizeof( T ), gpu ? cudaMemcpyDeviceToHost : cudaMemcpyHostToHost );
        P res = P( pt + data );
        data += sizeof( T ); // len
        return res;
    }

    template<class T,class S>
    P append_data( const T *val, S size ) { /// returns ptr
        data = ceil( data, alig );
        P res = P( SizeType( pt + data ) );
        if ( copy_data )
            cudaMemcpy( pt + data, val, sizeof( T ) * size, gpu ? cudaMemcpyDeviceToHost : cudaMemcpyHostToHost );
        data += sizeof( T ) * size;
        return res;
    }


    template<class T>
    void apply( const char *, const Vec<T> &val ) {
        // data
        P data_ptr = append_data( val.ptr(), val.size() );
        // len_v, ptr_v
        append_head( TV( val.size(), data_ptr ) );
    }

    template<class T>
    void apply( const char *, const Vec<Vec<T> > &val ) {
        // tmp vec with len_0 ptr_0 len_1 ptr_1 ...
        Vec<TV> tmp; tmp.resize( val.size() );
        for( unsigned i = 0; i < val.size(); ++i )
            tmp[ i ] = TV( val[ i ].size(), append_data( val[ i ].ptr(), val[ i ].size() ) );

        // copy tmp vec in data
        append_head( TV( tmp.size(), append_data( tmp.ptr(), tmp.size() ) ) );
    }

    int head; /// offset in header
    int data; /// offset in data
    char *pt; ///< target data
    char *tm; ///< tmp local data (used for header)
    bool copy_data;
    int ptr_size; ///< in target
};

template<class T>
void generate_cuda_struct( std::ostream &os, const T &str, const char *name ) {
    os << "struct " << name << " {\n";
    os << "    template<class T> struct Vec {\n";
    os << "        T operator[]( int index ) const { return ptr[ index ]; }\n";
    os << "        int size() const { return len; }\n";
    os << "        int len;\n";
    os << "        T  *ptr;\n";
    os << "    };\n";
    BinStructCudaMakeCpp mc;
    str.apply_bs( mc );
    os << "};\n";
}

template<bool gpu,class T>
void *copy_cuda_struct( const T &str ) {
    BinStructCudaGetRoomAndCopyData<gpu> gr;
    gr.begin_phase_1();
    str.apply_bs( gr );

    gr.begin_phase_2();
    str.apply_bs( gr );

    gr.begin_phase_3();

    PRINT( (SizeType)gr.pt );
    return gr.pt;
}

}
