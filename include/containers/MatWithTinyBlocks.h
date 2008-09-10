#ifndef MATHWITHTINYBLOCKS_H
#define MATHWITHTINYBLOCKS_H

#include "mat.h"
#include "SimdAl.h"

namespace LMT {

template<class T,class ST>
struct MatWithTinyBlocks;

/**
 */
template<class T,int n>
struct RowOfMatWithTinyBlocks {
    static const int tiny_block_size = 10;
    typedef int ST;
    Vec<ST> indices;
    Vec<T> data;
    
    void add( ST col, T v_0_0, T v_0_1, T v_0_2, T v_1_0, T v_1_1, T v_1_2, T v_2_0, T v_2_1, T v_2_2 ) {
        for(unsigned i=0;i<indices.size();++i) {
            if ( indices[i] >= col ) {
                if ( indices[i] == col ) {
                    T *d = &data[ tiny_block_size * i ];
                    d[ 0 ] += v_0_0;
                    d[ 1 ] += v_0_1;
                    d[ 6 ] += v_0_2;
                    d[ 2 ] += v_1_0;
                    d[ 3 ] += v_1_1;
                    d[ 7 ] += v_1_2;
                    d[ 4 ] += v_2_0;
                    d[ 5 ] += v_2_1;
                    d[ 8 ] += v_2_2;
                    return;
                }
                else { // creation
                    ST *ni = indices.make_room_to_insert( i, 1 ); *ni = col;
                    T *d = data.make_room_to_insert( tiny_block_size * i, tiny_block_size );
                    d[ 0 ] = v_0_0;
                    d[ 1 ] = v_0_1;
                    d[ 6 ] = v_0_2;
                    d[ 2 ] = v_1_0;
                    d[ 3 ] = v_1_1;
                    d[ 7 ] = v_1_2;
                    d[ 4 ] = v_2_0;
                    d[ 5 ] = v_2_1;
                    d[ 8 ] = v_2_2;
                    return;
                }
            }
        }
        *indices.new_elem() = col;
        ST os = data.size(); data.resize( os + tiny_block_size );
        data[ os + 0 ] = v_0_0;
        data[ os + 1 ] = v_0_1;
        data[ os + 6 ] = v_0_2;
        data[ os + 2 ] = v_1_0;
        data[ os + 3 ] = v_1_1;
        data[ os + 7 ] = v_1_2;
        data[ os + 4 ] = v_2_0;
        data[ os + 5 ] = v_2_1;
        data[ os + 8 ] = v_2_2;
    }
    
    struct Block {
        static const ST nb_values_for_alignement = tiny_block_size;
        static int tiny_block_offset( int r, int c ) {
            static const int o[] = { 0, 1, 6, 2, 3, 7, 4, 5, 8 };
            return o[ r * n + c ];
        }
        T &operator()( int r, int c ) {
            return data[ tiny_block_offset( r, c ) ];
        }
        const T &operator()( int r, int c ) const {
            return data[ tiny_block_offset( r, c ) ];
        }
        T data[ tiny_block_size ];
    };
    
    
    T operator()( ST row, ST col ) const {
        for(unsigned i=0;i<indices.size();++i) {
            ST c = col - col % 3;
            if ( indices[i] >= c ) {
                if ( indices[i] == c )
                    return data[ tiny_block_size * i + Block::tiny_block_offset( row, col % n ) ];
                return 0;
            }
        }
        return 0;
    }
};

/**
 */
template<class T>
struct MatWithTinyBlocks<T,Sym<3> > {
    static const int n = 3;
    typedef int ST;
    typedef RowOfMatWithTinyBlocks<T,n> RB;
    struct DB {
        static const ST s = n * ( n + 1 ) / 2;
        static const ST nb_values_for_alignement = s;
        T data[ s ];
        
        DB() {
            for(int i=0;i<s;++i)
                data[i] = 0;
        }
        const T &operator()( int n_r, int n_c ) const {
            if ( n_c > n_r )
                return operator()( n_c, n_r );
            return data[ n_r * ( n_r + 1 ) / 2 + n_c ];
        }
        T &operator()( int n_r, int n_c ) {
            if ( n_c > n_r )
                return operator()( n_c, n_r );
            return data[ n_r * ( n_r + 1 ) / 2 + n_c ];
        }
    };
    
    Vec<RB> rows;
    Vec<DB> diags;
    ST nb_rows_, nb_cols_;

    ST nb_rows() const { return nb_rows_; }
    ST nb_cols() const { return nb_cols_; }

    void resize( ST r, ST c ) {
        assert( r % n == 0 );
        assert( c % n == 0 );
        nb_rows_ = r;
        nb_cols_ = c;
        rows.resize( r / n );
        diags.resize( r / n );
    }

    MatWithTinyBlocks( ST r = 0, ST c = 0 ) {
        resize( r, c );
    }
    
    void reserve_lines( const Vec<ST> &nb_tiny_blocks_per_line ) {
        for(unsigned i=0;i<rows.size();++i) {
            rows[ i ].indices.reserve( nb_tiny_blocks_per_line[i] );
            rows[ i ].data   .reserve( nb_tiny_blocks_per_line[i] * RB::tiny_block_size );
        }
    }
    
    template<class T2> MatWithTinyBlocks( const MatWithTinyBlocks<T2,Sym<3> > &m ) {
        resize( m.nb_rows_, m.nb_rows_ );
        for(unsigned r=0;r<rows.size();++r) {
            rows[r].indices = m.rows[r].indices;
            rows[r].data    = m.rows[r].data   ;
        }
    }
    
    template<class T2> MatWithTinyBlocks( Mat<T2,Sym<>,SparseLine<> > &m ) {
        resize( m.nb_rows(), m.nb_cols() );
        for(unsigned r=0;r<rows.size();++r) {
            rows[r].indices.reserve( m.data[ r * 3 ].indices.size() / 3 );
            rows[r].data   .reserve( m.data[ r * 3 ].indices.size() / 3 * RB::Block::nb_values_for_alignement );
        }
        //
        for( ST r=0; r<ST( m.nb_rows() );  ) {
            for(ST j=0;j<ST( m.data[r].indices.size() );) {
                ST in = m.data[r].indices[j] / n;
                T v_0 = 0, v_1 = 0, v_2 = 0;
                if ( j < ST( m.data[r].indices.size() ) and ST( m.data[r].indices[j] / n ) == in and m.data[r].indices[j] % n == 0 )
                    v_0 = m.data[r].data[j++];
                if ( j < ST( m.data[r].indices.size() ) and ST( m.data[r].indices[j] / n ) == in and m.data[r].indices[j] % n == 1 )
                    v_1 = m.data[r].data[j++];
                if ( j < ST( m.data[r].indices.size() ) and ST( m.data[r].indices[j] / n ) == in and m.data[r].indices[j] % n == 2 )
                    v_2 = m.data[r].data[j++];
                add( r-0, in * n, v_0, v_1, v_2, 0, 0, 0, 0, 0, 0 );
            }
            ++r;
            for(ST j=0;j<ST( m.data[r].indices.size() );) {
                ST in = m.data[r].indices[j] / n;
                T v_0 = 0, v_1 = 0, v_2 = 0;
                if ( j < ST( m.data[r].indices.size() ) and ST( m.data[r].indices[j] / n ) == in and m.data[r].indices[j] % n == 0 )
                    v_0 = m.data[r].data[j++];
                if ( j < ST( m.data[r].indices.size() ) and ST( m.data[r].indices[j] / n ) == in and m.data[r].indices[j] % n == 1 )
                    v_1 = m.data[r].data[j++];
                if ( j < ST( m.data[r].indices.size() ) and ST( m.data[r].indices[j] / n ) == in and m.data[r].indices[j] % n == 2 )
                    v_2 = m.data[r].data[j++];
                add( r-1, in * n, 0, 0, 0, v_0, v_1, v_2, 0, 0, 0 );
            }
            ++r;
            for(ST j=0;j<ST( m.data[r].indices.size() );) {
                ST in = m.data[r].indices[j] / n;
                T v_0 = 0, v_1 = 0, v_2 = 0;
                if ( j < ST( m.data[r].indices.size() ) and ST( m.data[r].indices[j] / n ) == in and m.data[r].indices[j] % n == 0 )
                    v_0 = m.data[r].data[j++];
                if ( j < ST( m.data[r].indices.size() ) and ST( m.data[r].indices[j] / n ) == in and m.data[r].indices[j] % n == 1 )
                    v_1 = m.data[r].data[j++];
                if ( j < ST( m.data[r].indices.size() ) and ST( m.data[r].indices[j] / n ) == in and m.data[r].indices[j] % n == 2 )
                    v_2 = m.data[r].data[j++];
                add( r-2, in * n, 0, 0, 0, 0, 0, 0, v_0, v_1, v_2 );
            }
            ++r;
        }
    }

    void add( ST row, ST col, T v_0_0, T v_0_1, T v_0_2, T v_1_0, T v_1_1, T v_1_2, T v_2_0, T v_2_1, T v_2_2 ) {
        assert( row % n == 0 );
        assert( col % n == 0 );
        if ( row / n == col / n ) {
            DB &d = diags[ row / n ];
            
            d( 0, 0 ) += v_0_0;
            // d( 0, 1 ) += v_0_1;
            // d( 0, 2 ) += v_0_2;
            
            d( 1, 0 ) += v_1_0;
            d( 1, 1 ) += v_1_1;
            // d( 1, 2 ) += v_1_2;
            
            d( 2, 0 ) += v_2_0;
            d( 2, 1 ) += v_2_1;
            d( 2, 2 ) += v_2_2;
        }
        else
            rows[ row / n ].add( col, v_0_0, v_0_1, v_0_2, v_1_0, v_1_1, v_1_2, v_2_0, v_2_1, v_2_2 );
    }
    
    T operator()( ST row, ST col ) const {
        if ( col > row )
            return operator()( col, row );
        if ( row / n == col / n )
            return diags[ row / n ]( row % n, col % n );
        return rows[ row / n ]( row % n, col );
    }
    
    void partial_mul( const Vec<T> &v, Vec<T> &r, ST num_thread, ST nb_thread ) const {
        const Vec<T> &v_for_trans = v; // HUM
        Vec<T> &r_for_trans = r;
        ST beg = (ST)rows.size() * ( num_thread + 0 ) / nb_thread;
        ST end = (ST)rows.size() * ( num_thread + 1 ) / nb_thread;
        for( ST num_block_set=beg; num_block_set<end; ++num_block_set ) {
        // for( ST num_block_set=num_thread; num_block_set<(ST)rows.size(); num_block_set += nb_thread ) {
            ST real_row = num_block_set * 3;
            const RB &lbs = rows[ num_block_set ];
            const T *d = lbs.data.ptr();
            
            SimdVecAl<T,2> res_s_0 = SimdVecAl<T,2>::zero();
            SimdVecAl<T,2> res_s_1 = SimdVecAl<T,2>::zero();
            SimdVecAl<T,2> res_s_2 = SimdVecAl<T,2>::zero();
            T res_f_0 = 0;
            T res_f_1 = 0;
            T res_f_2 = 0;
            for(ST ci=0; ci<(ST)lbs.indices.size(); ++ci, d += RB::tiny_block_size ) {
                ST real_col = lbs.indices[ci];
                           
                SimdVecAl<T,2> vec_s_0(v[real_col+0],v[real_col+1]);
                T vec_f_0( v[real_col+2] );
                
                res_s_0 += reinterpret_cast<const SimdVecAl<T,2> &>( d[ 0 ] ) * vec_s_0;
                res_f_0 += d[ 6 ] * vec_f_0;
                res_s_1 += reinterpret_cast<const SimdVecAl<T,2> &>( d[ 2 ] ) * vec_s_0;
                res_f_1 += d[ 7 ] * vec_f_0;
                res_s_2 += reinterpret_cast<const SimdVecAl<T,2> &>( d[ 4 ] ) * vec_s_0;
                res_f_2 += d[ 8 ] * vec_f_0;
                            
                SimdVecAl<T,2> tmp_s_0 = 
                    ( reinterpret_cast<const SimdVecAl<T,2> &>( d[ 0 ] ) ) * SimdVecAl<T,2>( v_for_trans[ real_row + 0 ] ) +
                    ( reinterpret_cast<const SimdVecAl<T,2> &>( d[ 2 ] ) ) * SimdVecAl<T,2>( v_for_trans[ real_row + 1 ] ) +
                    ( reinterpret_cast<const SimdVecAl<T,2> &>( d[ 4 ] ) ) * SimdVecAl<T,2>( v_for_trans[ real_row + 2 ] );
                r_for_trans[ real_col + 0 ] += tmp_s_0[0];
                r_for_trans[ real_col + 1 ] += tmp_s_0[1];
                T tmp_f = 0;
                tmp_f += ( d[ 6 ] ) * v_for_trans[ num_block_set * 3 + 0 ];
                tmp_f += ( d[ 7 ] ) * v_for_trans[ num_block_set * 3 + 1 ];
                tmp_f += ( d[ 8 ] ) * v_for_trans[ num_block_set * 3 + 2 ];
                r_for_trans[ real_col + 2 ] += tmp_f;
            }
            const DB &db = diags[ num_block_set ];
            r[ num_block_set * 3 + 0 ] += res_s_0[0]+res_s_0[1]+res_f_0+db( 0, 0 ) *v[num_block_set*3+0]+db( 0, 1 )*v[num_block_set*3+1]+db( 0, 2 )*v[num_block_set*3+2];
            r[ num_block_set * 3 + 1 ] += res_s_1[0]+res_s_1[1]+res_f_1+db( 1, 0 ) *v[num_block_set*3+0]+db( 1, 1 )*v[num_block_set*3+1]+db( 1, 2 )*v[num_block_set*3+2];
            r[ num_block_set * 3 + 2 ] += res_s_2[0]+res_s_2[1]+res_f_2+db( 2, 0 ) *v[num_block_set*3+0]+db( 2, 1 )*v[num_block_set*3+1]+db( 2, 2 )*v[num_block_set*3+2];
        }
    }
    
    struct Mul {
        void operator()( int num_thread, const MatWithTinyBlocks &m, const Vec<T> &v, Vec<Vec<T> > &r ) const {
            m.partial_mul( v, r[num_thread], num_thread, nb_thread );
        }
        unsigned nb_thread;
    };
    
    Vec<T> mul( const Vec<T> &v, unsigned nb_thread ) const {
        Vec<Vec<T> > r; r.resize( nb_thread );
        for(unsigned i=0;i<nb_thread;++i)
            r[i].resize( nb_rows_, 0 );
        //
        Mul m; m.nb_thread = nb_thread;
        apply_mt( range(nb_thread), nb_thread, m, *this, v, r );
        //
        for(int n=0;n<nb_rows_;++n) {
            T z = r[0][n];
            for(unsigned i=1;i<nb_thread;++i)
                z += r[i][n];
            r[0][n] = z;
        }
        return r[0];
    }
    
    Vec<T> operator*( const Vec<T> &v ) const {
        return mul( v, 1 );
    }
    
    inline static bool find_corresponding_blocks( const RB &bs_0, const RB &bs_1, ST &ind_0, ST &ind_1 ) {
        if ( --ind_0 < 0 or --ind_1 < 0 )
            return false;
        while ( true ) {
            if ( bs_0.indices[ind_0] == bs_1.indices[ind_1] ) {
                return true;
            } else if ( bs_0.indices[ind_0] < bs_1.indices[ind_1] ) {
                if ( --ind_1 < 0 )
                    return false;
            } else {
                if ( --ind_0 < 0 )
                    return false;
            }
        }
    }
    
    void chol_incomp() {
        for ( ST num_block_set=0;num_block_set<ST( rows.size() );++num_block_set ) {
            // ST real_row = num_block_set * 3;
            RB &lbs = rows[ num_block_set ];

            // L
            if ( lbs.indices.size() ) {
                T *d = lbs.data.ptr();
                for ( ST indice_col_block = 0; indice_col_block < ST( lbs.indices.size() ); ++indice_col_block ) {
                    ST num_new_col_block = lbs.indices[indice_col_block] / n;
                    ST num_col_block_0 = rows[ num_new_col_block ].indices.size(), num_col_block_1 = indice_col_block;
                    const DB &db = diags[ num_new_col_block ]; // *reinterpret_cast<DB *> ( diags.ptr() + num_new_col_block * DB::nb_values_for_alignement );
                    if ( find_corresponding_blocks ( rows[ num_new_col_block ], rows[ num_block_set ], num_col_block_0, num_col_block_1 ) ) {
                        // reg initialisation
                        SimdVecAl<T,2> res_s_0_0 = SimdVecAl<T,2>::zero(), res_s_0_1 = SimdVecAl<T,2>::zero(), res_s_0_2 = SimdVecAl<T,2>::zero(), 
                                            res_s_1_0 = SimdVecAl<T,2>::zero(), res_s_1_1 = SimdVecAl<T,2>::zero(), res_s_1_2 = SimdVecAl<T,2>::zero(), 
                                            res_s_2_0 = SimdVecAl<T,2>::zero(), res_s_2_1 = SimdVecAl<T,2>::zero(), res_s_2_2 = SimdVecAl<T,2>::zero();
                        T res_f_0_0 = 0, res_f_0_1 = 0, res_f_0_2 = 0, res_f_1_0 = 0, res_f_1_1 = 0, res_f_1_2 = 0, res_f_2_0 = 0, res_f_2_1 = 0, res_f_2_2 = 0;
                        // dot
                        do {
                            const T *dj = rows[ num_new_col_block ].data.ptr() + num_col_block_0 * RB::tiny_block_size;
                            const T *di = rows[ num_block_set     ].data.ptr() + num_col_block_1 * RB::tiny_block_size;

                            res_s_0_0 += *reinterpret_cast<const SimdVecAl<T,2> *> ( di + 0 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( dj + 0 );
                            res_f_0_0 += di[ 6 ] * dj[ 6 ];
                            res_s_1_0 += *reinterpret_cast<const SimdVecAl<T,2> *> ( di + 2 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( dj + 0 );
                            res_f_1_0 += di[ 7 ] * dj[ 6 ];
                            res_s_2_0 += *reinterpret_cast<const SimdVecAl<T,2> *> ( di + 4 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( dj + 0 );
                            res_f_2_0 += di[ 8 ] * dj[ 6 ];
                            res_s_0_1 += *reinterpret_cast<const SimdVecAl<T,2> *> ( di + 0 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( dj + 2 );
                            res_f_0_1 += di[ 6 ] * dj[ 7 ];
                            res_s_1_1 += *reinterpret_cast<const SimdVecAl<T,2> *> ( di + 2 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( dj + 2 );
                            res_f_1_1 += di[ 7 ] * dj[ 7 ];
                            res_s_2_1 += *reinterpret_cast<const SimdVecAl<T,2> *> ( di + 4 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( dj + 2 );
                            res_f_2_1 += di[ 8 ] * dj[ 7 ];
                            res_s_0_2 += *reinterpret_cast<const SimdVecAl<T,2> *> ( di + 0 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( dj + 4 );
                            res_f_0_2 += di[ 6 ] * dj[ 8 ];
                            res_s_1_2 += *reinterpret_cast<const SimdVecAl<T,2> *> ( di + 2 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( dj + 4 );
                            res_f_1_2 += di[ 7 ] * dj[ 8 ];
                            res_s_2_2 += *reinterpret_cast<const SimdVecAl<T,2> *> ( di + 4 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( dj + 4 );
                            res_f_2_2 += di[ 8 ] * dj[ 8 ];
                        }
                        while ( find_corresponding_blocks ( rows[ num_new_col_block ], rows[ num_block_set ], num_col_block_0, num_col_block_1 ) );
                        // reg save
                        typename RB::Block &ob = *reinterpret_cast<typename RB::Block *> ( d ); d += RB::tiny_block_size;

                        ob( 0,0 ) = ( ob( 0,0 )-res_s_0_0[0]-res_s_0_0[1]-res_f_0_0 ) / db( 0,0 );
                        ob( 1,0 ) = ( ob( 1,0 )-res_s_1_0[0]-res_s_1_0[1]-res_f_1_0 ) / db( 0,0 );
                        ob( 2,0 ) = ( ob( 2,0 )-res_s_2_0[0]-res_s_2_0[1]-res_f_2_0 ) / db( 0,0 );
                        ob( 0,1 ) = ( ob( 0,1 )-res_s_0_1[0]-res_s_0_1[1]-res_f_0_1-ob( 0,0 ) *db( 1,0 ) ) / db( 1,1 );
                        ob( 1,1 ) = ( ob( 1,1 )-res_s_1_1[0]-res_s_1_1[1]-res_f_1_1-ob( 1,0 ) *db( 1,0 ) ) / db( 1,1 );
                        ob( 2,1 ) = ( ob( 2,1 )-res_s_2_1[0]-res_s_2_1[1]-res_f_2_1-ob( 2,0 ) *db( 1,0 ) ) / db( 1,1 );
                        ob( 0,2 ) = ( ob( 0,2 )-res_s_0_2[0]-res_s_0_2[1]-res_f_0_2-ob( 0,0 ) *db( 2,0 )-ob( 0,1 ) *db( 2,1 ) ) / db( 2,2 );
                        ob( 1,2 ) = ( ob( 1,2 )-res_s_1_2[0]-res_s_1_2[1]-res_f_1_2-ob( 1,0 ) *db( 2,0 )-ob( 1,1 ) *db( 2,1 ) ) / db( 2,2 );
                        ob( 2,2 ) = ( ob( 2,2 )-res_s_2_2[0]-res_s_2_2[1]-res_f_2_2-ob( 2,0 ) *db( 2,0 )-ob( 2,1 ) *db( 2,1 ) ) / db( 2,2 );
                    }
                    else {
                        typename RB::Block &ob = *reinterpret_cast<typename RB::Block *> ( d ); d += RB::tiny_block_size;

                        ob( 0,0 ) = ob( 0,0 ) / db ( 0,0 );
                        ob( 1,0 ) = ob( 1,0 ) / db ( 0,0 );
                        ob( 2,0 ) = ob( 2,0 ) / db ( 0,0 );
                        ob( 0,1 ) = ( ob( 0,1 )-ob( 0,0 ) *db ( 1,0 ) ) / db ( 1,1 );
                        ob( 1,1 ) = ( ob( 1,1 )-ob( 1,0 ) *db ( 1,0 ) ) / db ( 1,1 );
                        ob( 2,1 ) = ( ob( 2,1 )-ob( 2,0 ) *db ( 1,0 ) ) / db ( 1,1 );
                        ob( 0,2 ) = ( ob( 0,2 )-ob( 0,0 ) *db ( 2,0 )-ob( 0,1 ) *db ( 2,1 ) ) / db ( 2,2 );
                        ob( 1,2 ) = ( ob( 1,2 )-ob( 1,0 ) *db ( 2,0 )-ob( 1,1 ) *db ( 2,1 ) ) / db ( 2,2 );
                        ob( 2,2 ) = ( ob( 2,2 )-ob( 2,0 ) *db ( 2,0 )-ob( 2,1 ) *db ( 2,1 ) ) / db ( 2,2 );
                    }
                }
            }
            // D
            DB &ob = diags[ num_block_set ]; // *reinterpret_cast<DB *> ( diags.ptr() + num_block_set * DB::nb_values_for_alignement );
            SimdVecAl<T,2> res_s_0_0 = SimdVecAl<T,2>::zero(), res_s_1_0 = SimdVecAl<T,2>::zero(), res_s_1_1 = SimdVecAl<T,2>::zero(), res_s_2_0 = SimdVecAl<T,2>::zero(), res_s_2_1 = SimdVecAl<T,2>::zero(), res_s_2_2 = SimdVecAl<T,2>::zero(); T res_f_0_0 = 0, res_f_1_0 = 0, res_f_1_1 = 0, res_f_2_0 = 0, res_f_2_1 = 0, res_f_2_2 = 0;
            // dot( x, x )
            T *d = lbs.data.ptr();
            for ( ST col_block=0; col_block < ST( lbs.indices.size() ); ++col_block, d += RB::tiny_block_size ) {
                res_s_0_0 += *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 0 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 0 );
                res_f_0_0 += d[ 6 ] * d[ 6 ];
                res_s_1_0 += *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 2 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 0 );
                res_f_1_0 += d[ 7 ] * d[ 6 ];
                res_s_2_0 += *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 4 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 0 );
                res_f_2_0 += d[ 8 ] * d[ 6 ];
                res_s_1_1 += *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 2 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 2 );
                res_f_1_1 += d[ 7 ] * d[ 7 ];
                res_s_2_1 += *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 4 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 2 );
                res_f_2_1 += d[ 8 ] * d[ 7 ];
                res_s_2_2 += *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 4 ) * *reinterpret_cast<const SimdVecAl<T,2> *> ( d + 4 );
                res_f_2_2 += d[ 8 ] * d[ 8 ];
            }

            
            ob( 0,0 ) = sqrt ( ob( 0,0 )-res_s_0_0[0]-res_s_0_0[1]-res_f_0_0 );
            ob( 1,0 ) = ( ob( 1,0 )-res_s_1_0[0]-res_s_1_0[1]-res_f_1_0 ) / ob( 0,0 );
            ob( 2,0 ) = ( ob( 2,0 )-res_s_2_0[0]-res_s_2_0[1]-res_f_2_0 ) / ob( 0,0 );
            ob( 1,1 ) = sqrt ( ob( 1,1 )-res_s_1_1[0]-res_s_1_1[1]-res_f_1_1-ob( 1,0 ) *ob( 1,0 ) );
            ob( 2,1 ) = ( ob( 2,1 )-res_s_2_1[0]-res_s_2_1[1]-res_f_2_1-ob( 2,0 ) * ob( 1,0 ) ) / ob( 1,1 );
            ob( 2,2 ) = sqrt ( ob( 2,2 )-res_s_2_2[0]-res_s_2_2[1]-res_f_2_2-ob( 2,0 ) * ob( 2,0 ) - ob( 2,1 ) * ob( 2,1 ) );
        }
    }
    
    ST size_in_bytes() const {
        return row_size_in_bytes() + diag_size_in_bytes();
    }
    
    ST row_size_in_bytes() const {
        ST res = 0;
        for(unsigned i=0;i<rows.size();++i)
            res += rows[i].indices.size_in_bytes() + rows[i].data.size_in_bytes();
        return res;
    }
    
    ST diag_size_in_bytes() const {
        return diags.size_in_bytes();
    }
    
    Vec<T> solve( const Vec<T> &v ) const {
        Vec<T> res = v;
        solve_down( res );
        solve_up( res );
        return res;
    }
    
    void solve_down( Vec<T> &r ) const {
        for ( ST num_block_set=0;num_block_set<ST( rows.size() );++num_block_set ) {
            ST real_row = num_block_set * 3;
            const RB &lbs = rows[ num_block_set ];
            const T *d = lbs.data.ptr();
            
            #ifdef __pouetSSE2__
                register __v2df res_s_0 = _mm_setzero_pd();
                register __v2df res_s_1 = _mm_setzero_pd();
                register __v2df res_s_2 = _mm_setzero_pd();
                register T res_f_0 = 0.0;
                register T res_f_1 = 0.0;
                register T res_f_2 = 0.0;
                for ( ST ci=0; ci < ST( lbs.indices.size() ); ++ci, d += RB::Block::nb_values_for_alignement ) {
                    ST real_col = lbs.indices[ci];
    
                    register __v2df vec_s_0 = { r[real_col+0], r[real_col+1] };
                    register T vec_f_0 ( r[real_col+2] );
    
                    res_s_0 = _mm_add_pd( res_s_0, _mm_mul_pd( reinterpret_cast<const __v2df &>( d[ 0 ] ), vec_s_0 ) );
                    res_f_0 += d[ 6 ] * vec_f_0;
                    res_s_1 = _mm_add_pd( res_s_1, _mm_mul_pd( reinterpret_cast<const __v2df &>( d[ 2 ] ), vec_s_0 ) );
                    res_f_1 += d[ 7 ] * vec_f_0;
                    res_s_2 = _mm_add_pd( res_s_2, _mm_mul_pd( reinterpret_cast<const __v2df &>( d[ 4 ] ), vec_s_0 ) );
                    res_f_2 += d[ 8 ] * vec_f_0;
                }
    
                const DB &db = diags[ num_block_set ];
                r[ real_row + 0 ] -= SimdVecAl<T,2>(res_s_0).sum() + res_f_0;
                r[ real_row + 0 ] /= db ( 0,0 );
                r[ real_row + 1 ] -= SimdVecAl<T,2>(res_s_1).sum() + res_f_1 + db( 1,0 ) * r[ real_row + 0 ];
                r[ real_row + 1 ] /= db ( 1,1 );
                r[ real_row + 2 ] -= SimdVecAl<T,2>(res_s_2).sum() + res_f_2 + db( 2,0 ) * r[ real_row + 0 ] + db( 2,1 ) * r[ real_row + 1 ];
                r[ real_row + 2 ] /= db ( 2,2 );
            #else  // __SSE2__
                SimdVecAl<T,2> res_s_0 = SimdVecAl<T,2>::zero();
                SimdVecAl<T,2> res_s_1 = SimdVecAl<T,2>::zero();
                SimdVecAl<T,2> res_s_2 = SimdVecAl<T,2>::zero();
                T res_f_0 = 0;
                T res_f_1 = 0;
                T res_f_2 = 0;
                for ( ST ci=0; ci < ST( lbs.indices.size() ); ++ci, d += RB::Block::nb_values_for_alignement ) {
                    ST real_col = lbs.indices[ci];
    
                    SimdVecAl<T,2> vec_s_0( r[real_col+0], r[real_col+1] );
                    T vec_f_0 ( r[real_col+2] );
    
                    res_s_0 += reinterpret_cast<const SimdVecAl<T,2> &> ( d[ 0 ] ) * vec_s_0;
                    res_f_0 += d[ 6 ] * vec_f_0;
                    res_s_1 += reinterpret_cast<const SimdVecAl<T,2> &> ( d[ 2 ] ) * vec_s_0;
                    res_f_1 += d[ 7 ] * vec_f_0;
                    res_s_2 += reinterpret_cast<const SimdVecAl<T,2> &> ( d[ 4 ] ) * vec_s_0;
                    res_f_2 += d[ 8 ] * vec_f_0;
                }
    
                const DB &db = diags[ num_block_set ];
                r[ real_row + 0 ] -= res_s_0[0] + res_s_0[1] + res_f_0;
                r[ real_row + 0 ] /= db ( 0,0 );
                r[ real_row + 1 ] -= res_s_1[0] + res_s_1[1] + res_f_1 + db( 1,0 ) * r[ real_row + 0 ];
                r[ real_row + 1 ] /= db ( 1,1 );
                r[ real_row + 2 ] -= res_s_2[0] + res_s_2[1] + res_f_2 + db( 2,0 ) * r[ real_row + 0 ] + db( 2,1 ) * r[ real_row + 1 ];
                r[ real_row + 2 ] /= db ( 2,2 );
            #endif // __SSE2__
        }
    }
    
    void solve_up( Vec<T> &r ) const {
        for ( ST num_block_set=ST( rows.size() )-1;num_block_set>=0;--num_block_set ) {
            ST real_row = num_block_set * 3;
            const RB &lbs = rows[ num_block_set ];

            const DB &db = diags[ num_block_set ];
            r[ real_row + 2 ] /= db ( 2, 2 );
            r[ real_row + 0 ] -= db ( 2, 0 ) * r[ real_row + 2 ];
            r[ real_row + 1 ] -= db ( 2, 1 ) * r[ real_row + 2 ];
            r[ real_row + 1 ] /= db ( 1, 1 );
            r[ real_row + 0 ] -= db ( 1, 0 ) * r[ real_row + 1 ];
            r[ real_row + 0 ] /= db ( 0, 0 );
            if ( lbs.indices.size() ) {
                const T *d = lbs.data.ptr() + ( lbs.indices.size()-1 ) * RB::Block::nb_values_for_alignement;

                SimdVecAl<T,2> vec_s_0 ( r[ real_row + 0 ] ); register T vec_f_0 ( r[ real_row + 0 ] );
                SimdVecAl<T,2> vec_s_1 ( r[ real_row + 1 ] ); register T vec_f_1 ( r[ real_row + 1 ] );
                SimdVecAl<T,2> vec_s_2 ( r[ real_row + 2 ] ); register T vec_f_2 ( r[ real_row + 2 ] );
                for ( ST ci=lbs.indices.size()-1; ci>=0; --ci ) {
                    ST real_col = lbs.indices[ci];

                    //                     SimdVecAl<T,2> tmp_s_0 ( r[ real_col + 0 ], r[ real_col + 1 ] );
                    //                     T tmp_f_0 ( r[ real_col + 2 ] );
                    //                     
                    //                     tmp_s_0 -= vec_s_0 * reinterpret_cast<const SimdVecAl<T,2> &> ( d[ 0 ] );
                    //                     tmp_f_0 -= vec_f_0 * d[ 6 ];
                    //                     tmp_s_0 -= vec_s_1 * reinterpret_cast<const SimdVecAl<T,2> &> ( d[ 2 ] );
                    //                     tmp_f_0 -= vec_f_1 * d[ 7 ];
                    //                     tmp_s_0 -= vec_s_2 * reinterpret_cast<const SimdVecAl<T,2> &> ( d[ 4 ] );
                    //                     tmp_f_0 -= vec_f_2 * d[ 8 ];
                    //                     r[ real_col + 0 ] = tmp_s_0[ 0 ];
                    //                     r[ real_col + 1 ] = tmp_s_0[ 1 ];
                    //                     r[ real_col + 2 ] = tmp_f_0;
                    SimdVecAl<T,2> tmp_s_0 = SimdVecAl<T,2>( r[ real_col + 0 ], r[ real_col + 1 ] ) -
                        ( vec_s_0 * reinterpret_cast<const SimdVecAl<T,2> &> ( d[ 0 ] ) + 
                          vec_s_1 * reinterpret_cast<const SimdVecAl<T,2> &> ( d[ 2 ] ) +
                          vec_s_2 * reinterpret_cast<const SimdVecAl<T,2> &> ( d[ 4 ] )
                        );
                    
                    r[ real_col + 0 ] = tmp_s_0[ 0 ];
                    r[ real_col + 1 ] = tmp_s_0[ 1 ];
                    r[ real_col + 2 ] -= vec_f_0 * d[ 6 ] + vec_f_1 * d[ 7 ] + vec_f_2 * d[ 8 ];
                    
                    d -= RB::Block::nb_values_for_alignement;
                }
            }
        }
    }
};

template<class T,class TO>
std::ostream &operator<<( std::ostream &os, const MatWithTinyBlocks<T,TO> &m ) {
    for(int i=0;i<m.nb_rows_;++i) {
        for(int j=0;j<m.nb_cols_;++j)
            os << std::setw(8) << m( i, j ) << " "; 
        os << "\n";
    }
    return os;
}

/*
 mp -> foactorized mat
*/
template<class TM,class TO,class TA,class T> void solve_using_incomplete_chol_factorize( const MatWithTinyBlocks<TM,TO> &mp, const TA &A, const Vec<T> &b, Vec<T> &x, T crit = 1e-4, bool disp_r = false ) {
    // bool disp_timing = true;
    if ( x.size() <= (unsigned)A.nb_rows() )
        x.resize( A.nb_rows(), 0.0 );
        
    //
    Vec<T> r, d, q, s;
    T t0 = time_of_day_in_sec();

    r = b - A * x;
    if ( disp_r ) PRINT( max(abs(r)) );
    
    T t1 = time_of_day_in_sec();
    PRINT( ( 2 * A.row_size_in_bytes() + A.diag_size_in_bytes() + 2 * b.size_in_bytes() ) / (t1-t0) );
    
    for(unsigned i=0;;++i) { if ( i==r.size() ) return; if ( abs(r[i]) > crit ) break; }
    
    t0 = time_of_day_in_sec();
    
    d = mp.solve( r );
    
    t1 = time_of_day_in_sec();
    PRINT( ( 2 * ( A.row_size_in_bytes() + A.diag_size_in_bytes() ) + 3 * b.size_in_bytes() ) / (t1-t0) );
    
    //     if ( disp_timing ) { T t1 = time_of_day_in_sec(); std::cout << "solve -> " << t1 - t0 << std::endl; t0 = t1; }
    
    T deltn = dot(r,d);
    unsigned cpt = 0;
    while ( true ) {
        T delto = deltn;
        
        q = A * d;
        //         if ( disp_timing ) { T t1 = time_of_day_in_sec(); std::cout << "mul -> " << t1 - t0 << std::endl; t0 = t1; }
        T alpha = deltn / dot( d, q );
        x += alpha * d;
        r -= alpha * q; // r = b - A * x;
        if ( disp_r ) PRINT( max(abs(r)) );
        for(unsigned i=0;;++i) { if ( i==r.size() ) return; if ( abs(r[i]) > crit ) break; }
            
        //         if ( disp_timing ) { T t1 = time_of_day_in_sec(); std::cout << "alpha * ... -> " << t1 - t0 << std::endl; t0 = t1; }
        
        s = mp.solve( r );
        //         if ( disp_timing ) { T t1 = time_of_day_in_sec(); std::cout << "solve -> " << t1 - t0 << std::endl; t0 = t1; }
        
        deltn = dot( r, s );
        //         if ( disp_timing ) { T t1 = time_of_day_in_sec(); std::cout << "dot -> " << t1 - t0 << std::endl; t0 = t1; }
        
        T beta = deltn / delto;
        d = s + beta * d;
        //         if ( disp_timing ) { T t1 = time_of_day_in_sec(); std::cout << "d -> " << t1 - t0 << std::endl; t0 = t1; }
        ++cpt;
    }
}


}

#endif // MATHWITHTINYBLOCKS_H


