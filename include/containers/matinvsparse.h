//
// C++ Interface: matinvsparse
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matinvsparse_HEADER
#define LMT_matinvsparse_HEADER

namespace LMT {

template<class T> inline T dot_chol_factorize( const Vec<Sparse<T> > &v1, const Vec<Sparse<T> > &v2 ) {
    T res = T( 0.0 );
    if ( v2.indices.size() == 0 ) return T( 0.0 );
    for(unsigned i=0,j=0;i<v1.indices.size()-1;++i) {
        while ( v2.indices[j] < v1.indices[i] ) {
            ++j;
            if ( j==v2.indices.size() ) return res;
        }
        if ( v2.indices[j] == v1.indices[i] ) res += v2.data[j] * v1.data[i];
    }
    return res;
}

template<unsigned n>
struct HashCH {
    HashCH() {
        for(unsigned i=0;i<n;++i) v[n] = 0;
    }
    inline void add(unsigned col) {
        unsigned i = col / 32;
        v[ i % n ] |= ( 1 << (col%32) );
    }
    inline static bool cor(const HashCH &h1,const HashCH &h2) {
        for(unsigned i=0;i<n;++i)
            if ( h1.v[i] & h2.v[i] )
                return true;
        return false;
    }
    unsigned v[n];
};

template<class T,class TS> void chol_factorize( Mat<T,TS,SparseLine<> > &m ) {
    static const unsigned NN = 16;
    Vec<HashCH<NN> > hash; hash.resize( m.nb_rows() );
    for(unsigned line=0;line<m.nb_rows();++line) {
        for(unsigned ind=0;ind<m.data[line].indices.size()-1;++ind) {
            // m_ij != 0
            unsigned col = m.data[line].indices[ind];
            m.data[line].data[ind] = ( m.data[line].data[ind] - dot_chol_factorize( m.data[col], m.data[line] ) ) / m.data[col].data.back();
            hash[ line ].add( col );
            // m_ij == 0
            unsigned ie = m.data[line].indices[ind+1];
            while ( ++col < ie ) {
                if ( not HashCH<NN>::cor( hash[col], hash[ line ] ) ) continue;

                T v = dot_chol_factorize( m.data[col], m.data[line] );
                if ( LMT::abs( v ) ) {
                    unsigned os = m.data[line].indices.size();
                    m.data[line].indices.resize( os+1 );
                    m.data[line].data.resize( os+1 );
                    ++ind;
                    for(unsigned k=os;k>ind;--k) {
                        m.data[line].indices[k] = m.data[line].indices[k-1];
                        m.data[line].data[k] = m.data[line].data[k-1];
                    }
                    m.data[line].data[ind] = -v / m.data[col].data.back();
                    m.data[line].indices[ind] = col;
                    hash[ line ].add( col );
                }
            }
        }
        // on diag
        m.data[line].data.back() = sqrt( m.data[line].data.back() - norm_2_p2( m.data[line].data.begin(), m.data[line].data.size()-1 ) );
    }
    //PRINT( hash );
}

template<class T> void incomplete_chol_factorize( Mat<T,Sym<>,SparseLine<> > &m ) {
    for(unsigned line=0;line<m.nb_rows();++line) {
        for(unsigned ind=0;ind<m.data[line].indices.size()-1;++ind) {
            // m_ij != 0
            unsigned col = m.data[line].indices[ind];
            m.data[line].data[ind] = ( m.data[line].data[ind] - dot_chol_factorize( m.data[col], m.data[line] ) ) / m.data[col].data.back();
        
            /*            // m_ij == 0
                        unsigned ie = min( m.data[line].indices[ind+1], col+2 );
                        while ( ++col < ie ) {
                            T v = dot_chol_factorize( m.data[col], m.data[line] );
                            if ( v ) {
                                unsigned os = m.data[line].indices.size();
                                m.data[line].indices.resize( os+1 );
                                m.data[line].data.resize( os+1 );
                                ++ind;
                                for(unsigned k=os;k>ind;--k) {
                                    m.data[line].indices[k] = m.data[line].indices[k-1];
                                    m.data[line].data[k] = m.data[line].data[k-1];
                                }
                                m.data[line].data[ind] = -v / m.data[col].data.back();
                                m.data[line].indices[ind] = col;
                            }
                        }*/
        
        
        }
        // on diag
        m.data[line].data.back() = sqrt( m.data[line].data.back() - norm_2_p2( m.data[line].data.begin(), m.data[line].data.size()-1 ) );
    }
}

/// m is assumed to be factorized
template<class T,int s,int s2> void solve_using_chol_factorize( const Mat<T,Sym<s>,SparseLine<> > &mat, const Vec<T> &sol, Vec<T,s2> &res ) {
    unsigned nb_lines = mat.nb_rows();
    
    res.resize( nb_lines );
    //
    for(unsigned line=0;line<nb_lines;++line) {
        T v = sol[line];
        for(unsigned i=0;i<mat.data[line].data.size()-1;++i)
            v -= mat.data[line].data[i] * res[ mat.data[line].indices[i] ];
        res[line] = v / mat.data[line].data.back();
    }

    //
    Vec<T,s2> tmpvec = res;
    while (nb_lines--) {
        T tmp = tmpvec[nb_lines] / mat.data[nb_lines].data.back();
        for(unsigned i=0;i<mat.data[nb_lines].data.size()-1;++i)
            tmpvec[ mat.data[nb_lines].indices[i] ] -= mat.data[nb_lines].data[i] * tmp;
        res[nb_lines] = tmp;
    }
}

/// m is assumed to be factorized
template<class T,int s,int s2> void solve_using_chol_factorize( const Mat<T,Herm<s>,SparseLine<> > &mat, const Vec<T> &sol, Vec<T,s2> &res ) {
    unsigned nb_lines = mat.nb_rows();
    
    res.resize( nb_lines );
    //
    for(unsigned line=0;line<nb_lines;++line) {
        T v = sol[line];
        for(unsigned i=0;i<mat.data[line].data.size()-1;++i)
            v -= LMT::conj( mat.data[line].data[i] ) * res[ mat.data[line].indices[i] ];
        res[line] = v / LMT::conj( mat.data[line].data.back() );
    }

    //
    Vec<T,s2> tmpvec = res;
    while (nb_lines--) {
        T tmp = tmpvec[nb_lines] / mat.data[nb_lines].data.back();
        for(unsigned i=0;i<mat.data[nb_lines].data.size()-1;++i)
            tmpvec[ mat.data[nb_lines].indices[i] ] -= mat.data[nb_lines].data[i] * tmp;
        res[nb_lines] = tmp;
    }
}

template<class T,int s2> void solve_using_incomplete_chol_factorize( const Mat<T,Sym<>,SparseLine<> > &mp, const Mat<T,Sym<>,SparseLine<> > &A, const Vec<T> &b, Vec<T,s2> &x, double crit = 1e-4, bool disp_r = true ) {
    if ( x.size() <= A.nb_rows() )
        x.resize( A.nb_rows(), 0.0 );
    //
    Vec<T> r, d, q, s;
    
    r = b - A * x;
    for(unsigned i=0;;++i) { if ( i==r.size() ) return; if ( LMT::abs(r[i]) > crit ) break; }
    solve_using_chol_factorize( mp, r, d );
    
    T deltn = dot(r,d);
    unsigned cpt = 0;
    while ( true ) {
        T delto = deltn;
        
        q = A * d;
        T alpha = deltn / dot( d, q );
        x += alpha * d;
        r -= alpha * q; //r = b - A * x;
        for(unsigned i=0;;++i) { if ( i==r.size() ) return; if ( LMT::abs(r[i]) > crit ) break; }
        
        solve_using_chol_factorize( mp, r, s );
        deltn = dot( r, s );
        
        T beta = deltn / delto;
        d = s + beta * d;
        ++cpt;
        if ( disp_r )
            PRINT( max(abs(r)) );
    }
}


// ---------------------------------------- LU ----------------------------------------
/// in place...
template<class T> void lu_factorize( Mat<T,Gen<>,SparseLU> &m ) {
    unsigned n = m.nb_rows();
    for(unsigned line=0;line<n;++line) {
        // L
        for(unsigned ind=0;ind<m.L[line].indices.size();++ind) {
            // l_ij != 0
            unsigned col = m.L[line].indices[ind];
            m.L[line].data[ind] = ( m.L[line].data[ind] - dot_chol_factorize( m.U[col], m.L[line] ) ) / m.U[col].data.back();
            // l_ij == 0
            unsigned ie = line;
            if ( ind < m.L[line].indices.size()-1 )
                ie = m.L[line].indices[ind+1];
            while ( ++col < ie ) {
                T v = dot_chol_factorize( m.U[col], m.L[line] );
                if ( abs_indication( v ) ) {
                    unsigned os = m.L[line].indices.size();
                    m.L[line].indices.resize( os+1 );
                    m.L[line].data.resize( os+1 );
                    ++ind;
                    for(unsigned k=os;k>ind;--k) {
                        m.L[line].indices[k] = m.L[line].indices[k-1];
                        m.L[line].data[k] = m.L[line].data[k-1];
                    }
                    m.L[line].data[ind] = -v / m.U[col].data.back();
                    m.L[line].indices[ind] = col;
                }
            }
        }
        // U
        for(unsigned ind=0;ind<m.U[line].indices.size();++ind) {
            // u_ij != 0
            unsigned col = m.U[line].indices[ind];
            m.U[line].data[ind] = m.U[line].data[ind] - dot_chol_factorize( m.U[line], m.L[col] );
            // u_ij == 0
            unsigned ie = line;
            if ( ind < m.U[line].indices.size()-1 )
                ie = m.U[line].indices[ind+1];
            while ( ++col < ie ) {
                T v = dot_chol_factorize( m.U[line], m.L[col] );
                if ( abs_indication( v ) ) {
                    unsigned os = m.U[line].indices.size();
                    m.U[line].indices.resize( os+1 );
                    m.U[line].data.resize( os+1 );
                    ++ind;
                    for(unsigned k=os;k>ind;--k) {
                        m.U[line].indices[k] = m.U[line].indices[k-1];
                        m.U[line].data[k] = m.U[line].data[k-1];
                    }
                    m.U[line].data[ind] = -v;
                    m.U[line].indices[ind] = col;
                }
            }
        }
    }
}
// template<class T> void lu_factorize( Mat<T,Gen<>,SparseLU> &m ) {
//     int n = m.nb_rows();
//     for(int i=0;i<n;++i) {
//         for(int k=0;k<i;++k)
//             m.L[i][k] = ( m.L[i][k] - dot_chol_factorize( m.U[k], m.L[i] ) ) / m.U[k][k];
//         for(int k=0;k<=i;++k)
//             m.U[i][k] = ( m.U[i][k] - dot_chol_factorize( m.U[i], m.L[k] ) );
//     }
// }

/// m is assumed to be factorized
template<class T,int s,int s2> void solve_using_lu_factorize( const Mat<T,Gen<s>,SparseLU> &mat, const Vec<T> &sol, Vec<T,s2> &res ) {
    unsigned nb_lines = mat.nb_rows();
    //
    if ( res.size() <= nb_lines )
        res.resize( nb_lines, 0.0 );
    //
    for(unsigned line=0;line<nb_lines;++line) {
        T v = sol[line];
        for(unsigned i=0;i<mat.L[line].data.size();++i)
            v -= mat.L[line].data[i] * res[ mat.L[line].indices[i] ];
        res[line] = v;
    }
    //
    Vec<T,s2> tmpvec = res;
    while (nb_lines--) {
        assert( mat.U[nb_lines].data.size() );
        T tmp = tmpvec[nb_lines] / mat.U[nb_lines].data.back();
        for(unsigned i=0;i<mat.U[nb_lines].data.size()-1;++i)
            tmpvec[ mat.U[nb_lines].indices[i] ] -= mat.U[nb_lines].data[i] * tmp;
        res[nb_lines] = tmp;
    }
}

/// in place...
template<class T> void incomplete_lu_factorize( Mat<T,Gen<>,SparseLU> &m ) {
    unsigned n = m.nb_rows();
    for(unsigned line=0;line<n;++line) {
        // L
        for(unsigned ind=0;ind<m.L[line].indices.size();++ind) {
            // l_ij != 0
            unsigned col = m.L[line].indices[ind];
            m.L[line].data[ind] = ( m.L[line].data[ind] - dot_chol_factorize( m.U[col], m.L[line] ) ) / m.U[col].data.back();
        }
        // U
        for(unsigned ind=0;ind<m.U[line].indices.size();++ind) {
            // u_ij != 0
            unsigned col = m.U[line].indices[ind];
            m.U[line].data[ind] = m.U[line].data[ind] - dot_chol_factorize( m.U[line], m.L[col] );
        }
    }
}

template<class T,int s2> void solve_using_incomplete_lu_factorize( const Mat<T,Gen<>,SparseLU> &mp, const Mat<T,Gen<>,SparseLU> &A, const Vec<T> &b, Vec<T,s2> &x, T crit = 1e-4 ) {
    assert(0); /// TODO
//     Vec<T> r, d, q, s;
//     
//     r = b - A * x;
//     for(unsigned i=0;;++i) { if ( i==r.size() ) return; if ( abs(r[i]) > crit ) break; }
//     solve_using_lu_factorize( mp, r, d );
//     
//     T deltn = dot(r,d);
//     unsigned cpt = 0;
//     while ( true ) {
//         T delto = deltn;
//         
//         q = A * d;
//         T alpha = deltn / dot( d, q );
//         x += alpha * d;
//         r -= alpha * q; //r = b - A * x;
//         for(unsigned i=0;;++i) { if ( i==r.size() ) return; if ( abs(r[i]) > crit ) break; }
//         
//         solve_using_lu_factorize( mp, r, s );
//         deltn = dot( r, s );
//         
//         T beta = deltn / delto;
//         d = s + beta * d;
//         ++cpt;
//         //std::cout << max(abs(r)) << std::endl;
//     }
}

};

#endif // LMT_matinvsparse_HEADER

