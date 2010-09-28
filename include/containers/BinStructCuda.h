#include "containers/vec.h"
using namespace LMT;
typedef std::string String;

#define APPLY_BS( res, n ) res.apply( #n, n )

struct Toto {
    template<class TB>
    void apply_bs( TB &res ) {
        APPLY_BS( res, a );
        APPLY_BS( res, b );
        APPLY_BS( res, c );
    }
    Vec<double> a;
    Vec<float > b;
    Vec<Vec<double> > c;
};

struct BinStructCudaMakeCpp_1 {
    template<class T>
    void apply( const char *name, const Vec<T> & ) {
        std::cout << "    inline " << TypeInformation<T>::type() << " *ptr_" << name << "() { return (char *)this + off_" << name << "; }\n";
    }
    template<class T>
    void apply( const char *name, const Vec<Vec<T> > & ) {
        std::cout << "    inline " << TypeInformation<T>::type() << " *ptr_" << name << "( int n ) {\n";
        std::cout << "        int off = reinterpret_cast<int *>( reinterpret_cast<char *>( this ) + off_" << name << " )[ 2 * n + 1 ]; }\n";
        std::cout << "        return reinterpret_cast<" << TypeInformation<T>::type() << " *>( reinterpret_cast<char *>( this ) + off ); }\n";
        std::cout << "    }\n";
    }
};

struct BinStructCudaMakeCpp_2 {
    template<class T>
    void apply( const char *name, const Vec<T> & ) {
        std::cout << "    int len_" << name << ";\n";
        std::cout << "    int off_" << name << ";\n";
    }
};

struct BinStructCudaGetRoomAndCopyData {
    BinStructCudaGetRoomAndCopyData( int alig = 16 * 4 ) : alig( alig ) {}

    void phase_1() {
        copy_data = false;

        head = 0;
        data = 0;
    }

    void phase_2() {
        copy_data = true;

        int room = ceil( head, alig ) + data;
        pt = (char *)malloc( room ); // cuda
        tm = (char *)malloc( head ); // local

        data = ceil( head, alig );
        head = 0;

    }

    void phase_3() {
        memcpy( pt, tm, head ); // cuda
    }

    template<class T>
    void apply( const char *, const Vec<T> &val ) {
        if ( copy_data ) {
            reinterpret_cast<int *>( tm + head )[ 0 ] = val.size();
            reinterpret_cast<int *>( tm + head )[ 1 ] = data;
        }
        head += sizeof( int ) * 2; // len + off

        data = ceil( data, alig );
        if ( copy_data )
            memcpy( pt + data, val.ptr(), sizeof( T ) * val.size() ); // cuda
        data += sizeof( T ) * val.size();
    }

    template<class T>
    void apply( const char *, const Vec<Vec<double> > &val ) {
        if ( copy_data ) {
            reinterpret_cast<int *>( tm + head )[ 0 ] = val.size();
            reinterpret_cast<int *>( tm + head )[ 1 ] = data;
        }
        head += sizeof( int ) * 2; // len + off

        int pos_off = data;
        data += sizeof( int ) * 2; // len + off for each sub vec

        Vec<int> off;
        if ( copy_data )
            off.resize( 2 * val.size() );
        for( unsigned i = 0; i < val.size(); ++i ) {
            data = ceil( data, alig );
            if ( copy_data ) {
                off[ 2 * i + 0 ] = val[ i ].size();
                off[ 2 * i + 0 ] = data;
                memcpy( pt + data, val[ i ].ptr(), sizeof( T ) * val.size() ); // cuda
            }
            data += sizeof( T ) * val[ i ].size();
        }

        if ( copy_data )
            memcpy( pt + pos_off, off.ptr(), sizeof( int ) * 2 * val.size() );
    }

    int room() const { return ceil( head, alig ) + data; }

    int alig;
    int head;
    int data;
    char *pt; ///< used if copy_data
    char *tm; ///< used if copy_data
    bool copy_data;
};

template<class T>
void make_cuda_struct( std::ostream &os, Toto &toto, const char *name ) {
    os << "struct " << name << " {\n";
    os << "struct " << name << " {\n";
    os << "};\n";
}

int main() {
    Toto toto;
    toto.a = Vec<double>( 1, 2, 3 );
    toto.c = Vec<Vec<double> >( Vec<double>( 1, 2, 3 ),  Vec<double>( 4, 5, 6 ) );

    BinStructCudaGetRoomAndCopyData gr;
    gr.phase_1();
    toto.apply_bs( gr );
    gr.phase_2();
    toto.apply_bs( gr );
    gr.phase_3();
    toto.apply_bs( gr );

    PRINT( gr.room() );


    BinStructCudaMakeCpp_1 mc_1;
    toto.apply_bs( mc_1 );

    BinStructCudaMakeCpp_2 mc_2;
    toto.apply_bs( mc_2 );
}
