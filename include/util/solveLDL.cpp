#include "solveLDL.h"
#include "containers/simd.h"
extern "C" {
#include "LDL/ldl.h"
}

using namespace LMT;

void LDL_solver::get_factorization( LMT::Mat<double,LMT::Sym<>,LMT::SparseLine<> > &m, bool want_free, bool want_semi_morse, bool want_amd_order ) {
    //     TicToc tt; tt.start();
    LMT::Mat<double,LMT::Gen<>,LMT::SparseLine<> > mat( m.nb_rows(), m.nb_rows() );
    
    unsigned max_per_line = 0;
    for(unsigned i=0;i<m.nb_rows();++i)
        max_per_line = std::max( max_per_line, m.data[i].indices.size() );
    max_per_line *= 2;
            
    for(unsigned i=0;i<mat.nb_rows();++i) {
        mat.data[i].indices.reserve( max_per_line );
        mat.data[i].data.reserve( max_per_line );
    
        mat.data[i].indices = m.data[i].indices;
        mat.data[i].data = m.data[i].data;
    }
    
    // fill-in
    for(unsigned i=0;i<mat.nb_rows();++i) {
        for(int j=0;j<(int)m.data[i].indices.size()-1;++j) {
            mat.data[ m.data[i].indices[j] ].indices.push_back( i );
            mat.data[ m.data[i].indices[j] ].data.push_back( m.data[i].data[j] );
        }
    }
    
    // std::cout << mat << std::endl;
    if ( want_free )
        m.free();
    get_factorization( mat, false, want_semi_morse, want_amd_order );
    
    //    tt.stop();
}
    
void LDL_solver::get_factorization( LMT::Mat<double,LMT::Gen<>,LMT::SparseLine<> > &mat, bool want_free, bool want_semi_morse, bool want_amd_order ) {
    n = mat.nb_rows();

    Flag.resize( n );
    
    Ap.resize( n+1 );
    unsigned cpt = 0;
    for(int i=0;i<n;++i) {
        Ap[i] = cpt;
        cpt += mat.data[i].indices.size();
    }
    Ap[ n ] = cpt;

    unsigned nz = 0;
    for(int i=0;i<n;++i)
        nz += mat.data[i].indices.size();
    Ai.resize( nz );
    Ax.resize( nz );
    for(int i=0,cpt=0;i<n;++i) {
        for(unsigned j=0;j<mat.data[i].indices.size();++j,++cpt) {
            Ai[cpt] = mat.data[i].indices[j];
            Ax[cpt] = mat.data[i].data[j];
        }
    }
    
    if ( want_free )
        mat.free();
    
    // permutation
    P = LMT::range(n);
    if ( want_amd_order and amd_order( n, Ap.ptr(), Ai.ptr(), P.ptr(), (double *) NULL, Info) != AMD_OK ) {
        std::cerr << "call to AMD failed" << std::endl;
        assert(0);
    }
    
    //amd_control((double *) NULL); // amd_info(Info);
    //amd_info (Info) ;
    
    if ( !ldl_valid_matrix (n, Ap.ptr(), Ai.ptr()) or not ldl_valid_perm (n, P.ptr(), Flag.ptr()) ) {
        std::cerr << "mauvaise matrice - solveLDL.cpp" << std::endl;
        return;
    }
    
    // memory allocation
    Pinv.resize(n);
    Y.resize(n);
    Pattern.resize(n);
    Lnz.resize(n);
    Lp.resize(n+1);
    Parent.resize(n);
    D.resize(n);
    B.resize(n);
    X.resize(n);
    
    //
    ldl_symbolic(n, Ap.ptr(), Ai.ptr(), Lp.ptr(), Parent.ptr(), Lnz.ptr(), Flag.ptr(), P.ptr(), Pinv.ptr());
    lnz = Lp[n];
    
    // allocate remainder of L, of size lnz */
    Li.resize( lnz );
    Lx.resize( lnz );
    
    // numeric factorization to get Li, Lx, and D */
    int d = ldl_numeric (n, Ap.ptr(), Ai.ptr(), Ax.ptr(), Lp.ptr(), Parent.ptr(), Lnz.ptr(), Li.ptr(),
                         Lx.ptr(), D.ptr(), Y.ptr(), Flag.ptr(), Pattern.ptr(), P.ptr(), Pinv.ptr());
    if (d != n) {
        std::cerr << "Ax=b not solved." << std::endl;
        assert(0);
    }

    if ( want_semi_morse ) {
        want_semi_morse_ = true;
        update_block_set_from_factorization();
    }
    else
        want_semi_morse_ = false;
}

void LDL_solver::get_factorization( LMT::Mat<double,LMT::Sym<>,LMT::SparseLine<> > &m, LMT::Vec<LMT::Vec<double> > &Kernel, bool want_free, bool want_semi_morse, bool want_amd_order ) {
    //     TicToc tt; tt.start();
    LMT::Mat<double,LMT::Gen<>,LMT::SparseLine<> > mat( m.nb_rows(), m.nb_rows() );
    
    unsigned max_per_line = 0;
    for(unsigned i=0;i<m.nb_rows();++i)
        max_per_line = std::max( max_per_line, m.data[i].indices.size() );
    max_per_line *= 2;
            
    for(unsigned i=0;i<mat.nb_rows();++i) {
        mat.data[i].indices.reserve( max_per_line );
        mat.data[i].data.reserve( max_per_line );
    
        mat.data[i].indices = m.data[i].indices;
        mat.data[i].data = m.data[i].data;
    }
    
    // fill-in
    for(unsigned i=0;i<mat.nb_rows();++i) {
        for(int j=0;j<(int)m.data[i].indices.size()-1;++j) {
            mat.data[ m.data[i].indices[j] ].indices.push_back( i );
            mat.data[ m.data[i].indices[j] ].data.push_back( m.data[i].data[j] );
        }
    }
    
    // std::cout << mat << std::endl;
    if ( want_free )
        m.free();
    get_factorization( mat, Kernel, false, want_semi_morse, want_amd_order );
    
    //    tt.stop();
}
    
void LDL_solver::get_factorization( LMT::Mat<double,LMT::Gen<>,LMT::SparseLine<> > &mat, LMT::Vec<LMT::Vec<double> > &Kernel, bool want_free, bool want_semi_morse, bool want_amd_order ) {
    n = mat.nb_rows();

    Flag.resize( n );
    
    Ap.resize( n+1 );
    unsigned cpt = 0;
    for(int i=0;i<n;++i) {
        Ap[i] = cpt;
        cpt += mat.data[i].indices.size();
    }
    Ap[ n ] = cpt;

    unsigned nz = 0;
    for(int i=0;i<n;++i)
        nz += mat.data[i].indices.size();
    Ai.resize( nz );
    Ax.resize( nz );
    for(int i=0,cpt=0;i<n;++i) {
        for(unsigned j=0;j<mat.data[i].indices.size();++j,++cpt) {
            Ai[cpt] = mat.data[i].indices[j];
            Ax[cpt] = mat.data[i].data[j];
        }
    }
    
    if ( want_free )
        mat.free();
    
    // permutation
    P = LMT::range(n);
    if ( want_amd_order and amd_order( n, Ap.ptr(), Ai.ptr(), P.ptr(), (double *) NULL, Info) != AMD_OK ) {
        std::cerr << "call to AMD failed" << std::endl;
        assert(0);
    }
    
    //amd_control((double *) NULL); // amd_info(Info);
    //amd_info (Info) ;
    
    if ( !ldl_valid_matrix (n, Ap.ptr(), Ai.ptr()) or not ldl_valid_perm (n, P.ptr(), Flag.ptr()) ) {
        std::cerr << "mauvaise matrice - solveLDL.cpp" << std::endl;
        return;
    }
    
    // memory allocation
    Pinv.resize(n);
    Y.resize(n);
    Pattern.resize(n);
    Lnz.resize(n);
    Lp.resize(n+1);
    Parent.resize(n);
    D.resize(n);
    B.resize(n);
    X.resize(n);
    
    //
    ldl_symbolic(n, Ap.ptr(), Ai.ptr(), Lp.ptr(), Parent.ptr(), Lnz.ptr(), Flag.ptr(), P.ptr(), Pinv.ptr());
    lnz = Lp[n];
    
    // allocate remainder of L, of size lnz */
    Li.resize( lnz );
    Lx.resize( lnz );
    
    // numeric factorization to get Li, Lx, and D */

    // debut PK et PG
    pseudo_inverse=true;
    int Ksiz=0;
//    int maxkersiz=6; 
//    LMT::Vec<int> Knod; 
//    Knod.resize(maxkersiz);Knod.set(0);
    //Ker.resize(maxkersiz*n);Ker.set(0.);
    double *Ker_ptr = NULL;
    
//    int d = ldl_numeric (n, Ap.ptr(), Ai.ptr(), Ax.ptr(), Lp.ptr(), Parent.ptr(), Lnz.ptr(), Li.ptr(),
//                         Lx.ptr(), D.ptr(), Y.ptr(), Flag.ptr(), Pattern.ptr(), P.ptr(), Pinv.ptr());
    int d = ldl_numeric_pg (n, Ap.ptr(), Ai.ptr(), Ax.ptr(), Lp.ptr(), Parent.ptr(), Lnz.ptr(), Li.ptr(),
                            Lx.ptr(), D.ptr(), Y.ptr(), Flag.ptr(), Pattern.ptr(), P.ptr(), Pinv.ptr(),
                                   &Ksiz, &Ker_ptr );
    LMT::Vec<double> Ker; Ker.resize( n * Ksiz );
    for(int i=0;i<n * Ksiz;++i)
        Ker[i] = Ker_ptr[i];
    if ( Ker_ptr )
        free( Ker_ptr );
    
    //std::cout << "\t\t\t\ttaille du noyau : " << Ksiz << std::endl ;
   
  
    Kernel.resize(Ksiz) ;
    for (unsigned i=0;i<(unsigned)Ksiz;i++){
        Kernel[i].resize(n) ;
        Vec<unsigned> rep = range(i*n,(i+1)*n) ;
        Kernel[i] = Ker[rep] ;
    }

    //std::cout << " Ker : "<< Ker << std::endl ;

//    std::cout << " Kernel dimension :  " << Ksiz << " / null pivots : "<< Knod <<" / Kernel basis : "<< Kernel << std::endl ;
    // fin PK et PG

    if (d != n) {
        std::cerr << "Ax=b not solved." << std::endl;
        assert(0);
    }

    if ( want_semi_morse ) {
        want_semi_morse_ = true;
        update_block_set_from_factorization();
    }
    else
        want_semi_morse_ = false;
}

void LDL_solver::solve( LMT::Vec<double> &B ) {
    //    TicToc tt; tt.start();    
    
    ldl_perm( n, Y.ptr(), B.ptr(), P.ptr() ) ;                    /* y = Pb */
    if ( want_semi_morse_ )
        semi_morse_lsolve( Y );
    else
        ldl_lsolve( n, Y.ptr(), Lp.ptr(), Li.ptr(), Lx.ptr()) ;   /* y = L\y */
    if ( pseudo_inverse )
        ldl_dsolve_pg( n, Y.ptr(), D.ptr() );                     /*PK&PG pseudo inverse */ 
    else
        ldl_dsolve( n, Y.ptr(), D.ptr() );                        /*normal inversion*/    
    if ( want_semi_morse_ )
        semi_morse_ltsolve( Y );
    else
        ldl_ltsolve( n, Y.ptr(), Lp.ptr(), Li.ptr(), Lx.ptr() ) ; /* y = L'\y */
    ldl_permt( n, B.ptr(), Y.ptr(), P.ptr() ) ;                   /* x = P'y */
    
    //     tt.stop();
}
    
void LDL_solver::update_block_set_from_factorization() {
    static const unsigned al = SimdSize<T>::res;
    
    unsigned cpt_data = 0;
    data_for_block_set.resize( Lx.size() * al ); // first coarse approx
    beep_lines.free();
    for(int i=0;i<(int)Lp.size()-1;++i) {
        LineOfBeeps *lob = beep_lines.new_elem();
        if ( Lp[i] == Lp[i+1] ) // void line
            continue;
        // else
        for(int beg = Lp[i], j = beg+1; ; ++j ) {
            if ( j == Lp[i+1] or Li[j] != Li[j-1]+1 ) {
                int size = j - beg;
                if ( size < 16 ) {
                    Beep b;
                    b.data = &data_for_block_set[ cpt_data ];
                    b.col = Li[beg];
                    b.size = size;
                    lob->small_size_beeps.push_back( b );
                }
                else {
                    Beep b;
                    while ( cpt_data % al != Li[beg] % al ) { data_for_block_set[cpt_data++] = 0; }
                    b.data = &data_for_block_set[ cpt_data ];
                    b.col = Li[beg];
                    b.size = size;
                    lob->large_size_beeps.push_back( b );
                }
                
                for(int k=0;k<size;++k)
                    data_for_block_set[cpt_data++] = Lx[beg+k];
                
                if ( j == Lp[i+1] )
                    break;
                beg = j;
            }
        }
    }

    Flag.free();
    Ap.free();
    Ai.free();
    Ax.free();
    Pinv.free();
    Pattern.free();
    Lnz.free();
    Lp.free();
    Parent.free();
    B.free();
    X.free();
    Li.free();
    Lx.free();
}

void LDL_solver::semi_morse_lsolve( LMT::Vec<double> &Y ) {
    semi_morse_lsolve_( Y.ptr(), beep_lines.size(), beep_lines.ptr() );
}

void LDL_solver::semi_morse_ltsolve( LMT::Vec<double> &Y ) {
    semi_morse_ltsolve_( Y.ptr(), beep_lines.size(), beep_lines.ptr() );
}
