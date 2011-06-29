#include "util/unit_test.h" /// pour la macro UNIT_TEST( )
#include <containers/mat.h>

using namespace LMT;


template <class M>
void generator_random_matrix( M& m ) {
    for( unsigned i = 0; i < m.nb_rows(); ++i )
        for( unsigned j = 0; j < m.nb_cols(); ++j )
            m( i, j ) = 5 - ( rand() % 10 );
}

template <class T, int r, int c, class Orientation>
void generator_random_matrix( Mat< T, Gen<r,c>, SparseLine<Orientation>, void > &m ) {
    for( unsigned i = 0; i < m.nb_rows(); ++i )
        for( unsigned j = 0; j < m.nb_cols(); ++j )
            if ( rand() % 3 == 0 )
                m( i, j ) = 5 - ( rand() % 10 );
}

template <class T, int s, class Sto>
void generator_random_matrix( Mat< T, Sym<s,false>, Sto, void > & m ) {
    for( unsigned i = 0; i < m.nb_rows(); ++i )
        for( unsigned j = 0; j <= i; ++j )
            m( i, j ) = 5 - ( rand() % 10 );
}

template <class T, int s, class Orientation>
void generator_random_matrix( Mat< T, Sym<s,false>, SparseLine<Orientation>, void > &m ) {
    for( unsigned i = 0; i < m.nb_rows(); ++i )
        for( unsigned j = 0; j <= i; ++j )
            if ( rand() % 2 == 0 )
                m( i, j ) = 5 - ( rand() % 10 );
}

int test_convert_sym_dense_time_gen_dense__unit_test() {

    typedef Mat< double,Sym<-1,false>,Dense<Col>,void > TMA;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMB;
    TMA A;
    TMB B, R, Rd;

    A.resize( 5 );
    B.resize( 5, 10 );
    generator_random_matrix( A );
    generator_random_matrix( B );
    R = A * B;

    Rd = abs( R - TMB( A ) * B );
    return max( Rd ) < 1e-7;
}

int test_convert_sym_dense_time_sparseline_dense__unit_test() {

    typedef Mat< double,Sym<-1,false>,Dense<Col>,void > TMA;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMB;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMD;
    TMA A;
    TMB B;
    TMD R, Rd;

    A.resize( 5 );
    B.resize( 5, 10 );
    generator_random_matrix( A );
    generator_random_matrix( B );
    
    R = A * B;

    Rd = abs( R - TMD( A ) * TMD( B ) );
    return max( Rd ) < 1e-10;
}

int test_convert_sym_sparseline_time_gen_dense__unit_test() {
    int s = 3;
    unsigned p;
    typedef Mat< double,Sym<-1,false>,SparseLine<Col>,void > TMA;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMB;
    TMA A;
    TMB B, Rref;
    TMB R;

    A.resize( s );
    B.resize( s, 2 * s );
    A( 0, 0 ) = 1; A( 1, 0 ) = 2; A( 1, 1 ) = -1; A( 2, 0 ) = 3; A( 2, 1 ) = 0; A( 2, 2 ) = 5;
    
    double Bcoef[ 18 ] = { 5, 4, 3, 2, 1, 0, 2, 1, -2, 7, 1, 7, 1, -5, 2, 1, 6, 4 };
    for( unsigned i = 0, p = 0; i < B.nb_rows(); ++i ) 
        for( unsigned j = 0; j < B.nb_cols(); ++j ) {
            B( i, j ) = Bcoef[ p ];
            p++;
        }
    
    double Rcoef[ 18 ] = { 12, -9, 5, 19, 21, 26, 8, 7, 8, -3, 1, -7, 20, -13, 19, 11, 33, 20 };
    Rref.resize( s, 2 * s );
    for( unsigned i = 0, p = 0; i < B.nb_rows(); ++i ) 
        for( unsigned j = 0; j < B.nb_cols(); ++j ) {
            Rref( i, j ) = Rcoef[ p ];
            p++;
        }
    
    R  = A * B;
    Rref = abs( R - Rref );
    return max( Rref ) < 1e-14; 
}

int test_convert_sym_sparseline_time_gen_dense_2__unit_test() {

    int s = 8;
    typedef Mat< double,Sym<-1,false>,SparseLine<Col>,void > TMA;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMB;
    TMA A;
    TMB B, Rd;
    TMB R;

    A.resize( s );
    B.resize( s, 2 * s );
    generator_random_matrix( A );
    generator_random_matrix( B );

    R  = A * B;
    Rd = TMB( A ) * B;
    Rd = abs( R - Rd );
    return  max( Rd ) < 1e-12;
}

int test_convert_sym_sparseline_time_gen_sparseline__unit_test() {

    int s = 10;
    typedef Mat< double,Sym<-1,false>,SparseLine<Col>,void > TMA;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMB;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMC;
    TMA A;
    TMB B;
    TMC R, Rd;

    A.resize( s );
    B.resize( s, 2 * s );
    generator_random_matrix( A );
    generator_random_matrix( B );

    R  = A * B;
    Rd = TMC( A ) * TMC( B );
    Rd = abs( R - Rd );
    return max( Rd ) < 1e-10;
}

int test_convert_sym_sparseline_to_gen_sparseline__unit_test() {
    int s = 6;
    unsigned p;
    typedef Mat< double,Sym<>, SparseLine<> > TMA;
    typedef Mat< double,Gen<>, SparseLine<> > TMB;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMT;
    TMA A;
    TMB B;

    A.resize( s );

    A( 1, 0 ) = 1;
    A( 2, 1 ) = 2;
    A( 2, 2 ) = 3;
    A( 3, 0 ) = 4;
    A( 3, 2 ) = 5;
    A( 4, 3 ) = 6;
    A( 5, 1 ) = 7;
    A( 5, 4 ) = 8;
    
    B = A;
    TMT Ad( A ), Bd( B ), R;
    R = abs( B - A ); 
    return max( R ) < 1e-7; 
}

int test_convert_sym_sparseline_time_sym_sparseline__unit_test() {

    typedef Mat< double,Sym<-1,false>, SparseLine<Col>,void > TMA;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMT;
    TMA A, B;
    TMT R, Rd;

    A.resize( 10 );
    B.resize( 10 );
    generator_random_matrix( A );
    generator_random_matrix( B );
    R = A * B;
    Rd = abs( R - TMT( A ) * TMT( B ) );
    return max( Rd ) < 1e-7;
}

int test_convert_gen_sparseline_time_sym_sparseline__unit_test() {

    typedef Mat< double,Gen<>, SparseLine<Col>,void > TMA;
    typedef Mat< double,Sym<-1,false>, SparseLine<Col>,void > TMB;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMT;
    TMA A, R;
    TMB B;
    TMT  Rd;

    A.resize( 20 );
    B.resize( 20 );
    generator_random_matrix( A );
    generator_random_matrix( B );
    R = A * B;
    Rd = abs( R - TMT( A ) * TMT( B ) );
    return max( Rd ) < 1e-7;
}

bool test_convert_three_times_00__unit_test() {

    int s = 10;
    typedef Mat< double,Sym<-1,false>,SparseLine<Col>,void > TMA;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMB;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMC;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMR;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMRD;
    TMA  A;
    TMB  B;
    TMC  C;
    TMR  R;
    TMRD Rd;

    A.resize( s );
    B.resize( s );
    C.resize( s );
    generator_random_matrix( A );
    generator_random_matrix( B );
    generator_random_matrix( C );

    R  = A * B * C;
    Rd = A * TMRD( B * C );
    Rd = abs( R - Rd );
    return max( Rd ) < 1e-10;
}

bool test_convert_three_times_01__unit_test() {

    int s = 10;
    typedef Mat< double,Sym<-1,false>,SparseLine<Col>,void > TMA;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMB;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMC;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMR;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMRD;
    TMA  A;
    TMB  B;
    TMC  C;
    TMR  R;
    TMRD Rd;

    A.resize( s );
    B.resize( s );
    C.resize( s );
    generator_random_matrix( A );
    generator_random_matrix( B );
    generator_random_matrix( C );

    R  = A * B * C;
    Rd = A * TMRD( B * C );
    Rd = abs( R - Rd );
    return max( Rd ) < 1e-10;
}

bool test_convert_three_times_02__unit_test() {

    int s = 10;
    typedef Mat< double,Sym<-1,false>,Dense<Col>,void > TMA;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMB;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMC;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMR;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMRD;
    TMA  A;
    TMB  B;
    TMC  C;
    TMR  R;
    TMRD Rd;

    A.resize( s );
    B.resize( s );
    C.resize( s );
    generator_random_matrix( A );
    generator_random_matrix( B );
    generator_random_matrix( C );

    R  = A * B * C;
    Rd = A * TMRD( B * C );
    Rd = abs( R - Rd );
    return max( Rd ) < 1e-10;
}

bool test_convert_three_times_03__unit_test() {

    int s = 10;
    typedef Mat< double,Sym<-1,false>,SparseLine<Col>,void > TMA;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMB;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMC;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMR;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMRD;
    TMA  A;
    TMB  B;
    TMC  C;
    TMR  R;
    TMRD Rd;

    A.resize( s );
    B.resize( s );
    C.resize( s );
    generator_random_matrix( A );
    generator_random_matrix( B );
    generator_random_matrix( C );

    R  = A * B * C;
    Rd = A * TMRD( B * C );
    Rd = abs( R - Rd );
    return max( Rd ) < 1e-10;
}

bool test_convert_three_times_04__unit_test() {

    int s = 10;
    typedef Mat< double,Sym<-1,false>,Dense<Col>,void > TMA;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMB;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMC;
    typedef Mat< double,Gen<>,SparseLine<Col>,void > TMR;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMRD;
    TMA  A;
    TMB  B;
    TMC  C;
    TMR  R;
    TMRD Rd;

    A.resize( s );
    B.resize( s );
    C.resize( s );
    generator_random_matrix( A );
    generator_random_matrix( B );
    generator_random_matrix( C );

    R  = A * B * C;
    Rd = A * TMRD( B * C );
    Rd = abs( R - Rd );
    return max( Rd ) < 1e-10;
}

bool test_convert_three_times_05__unit_test() {

    static const int s  = 10;
    static const int s2 = 7;
    static const int s3 = 15;
    typedef Mat< double,Sym<s>,SparseLine<Col>,void > TMA;
    typedef Mat< double,Gen<s,s2>,SparseLine<Col>,void > TMB;
    typedef Mat< double,Gen<s2,s3>,SparseLine<Col>,void > TMC;
    typedef Mat< double,Gen<s,s3>,SparseLine<Col>,void > TMR;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMRD;
    TMA  A;
    TMB  B;
    TMC  C;
    TMR  R;
    TMRD Rd;
    
    generator_random_matrix( A );
    generator_random_matrix( B );
    generator_random_matrix( C );

    R  = A * B * C;
    Rd = A * TMRD( B * C );
    Rd = abs( R - Rd );
    return max( Rd ) < 1e-10;
}

bool test_convert_three_times_06__unit_test() {

    static const int s  = 10;
    static const int s2 = 7;
    typedef Mat< double,Gen<s,s2>,SparseLine<Col>,void > TMA;
    typedef Mat< double,Gen<s,s>,SparseLine<Col>,void > TMB;
    typedef Mat< double,Gen<s2,s2>,SparseLine<Col>,void > TMR;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMRD;
    TMA  A;
    TMB  B;
    TMR  R;
    TMRD Rd;
    
    generator_random_matrix( A );
    generator_random_matrix( B );

    R  = trans( A ) * B * A;
    Rd = trans( A ) * TMRD( B * A );
    Rd = abs( R - Rd );
    return max( Rd ) < 1e-10;
}

bool test_convert_three_times_07__unit_test() {

    static const int s  = 10;
    static const int s2 = 7;
    typedef Mat< double,Gen<s2,s>,SparseLine<Col>,void > TMA;
    typedef Mat< double,Gen<s,s>,SparseLine<Col>,void > TMB;
    typedef Mat< double,Gen<s2,s2>,SparseLine<Col>,void > TMR;
    typedef Mat< double,Gen<>,Dense<Col>,void > TMRD;
    TMA  A;
    TMB  B;
    TMR  R;
    TMRD Rd;
    
    generator_random_matrix( A );
    generator_random_matrix( B );

    R  = A * B * trans( A );
    Rd = A * TMRD( B * trans( A ) );
    Rd = abs( R - Rd );
    return max( Rd ) < 1e-10;
}

int main() {
    UNIT_TEST( test_convert_sym_dense_time_gen_dense__unit_test() );
    UNIT_TEST( test_convert_sym_dense_time_sparseline_dense__unit_test );
    UNIT_TEST( test_convert_sym_sparseline_time_gen_dense__unit_test() );
    UNIT_TEST( test_convert_sym_sparseline_time_gen_dense_2__unit_test() );
    UNIT_TEST( test_convert_sym_sparseline_time_gen_sparseline__unit_test() );
    UNIT_TEST( test_convert_sym_sparseline_to_gen_sparseline__unit_test() );
    UNIT_TEST( test_convert_sym_sparseline_time_sym_sparseline__unit_test() );
    UNIT_TEST( test_convert_gen_sparseline_time_sym_sparseline__unit_test() );
    UNIT_TEST( test_convert_three_times_00__unit_test() );
    UNIT_TEST( test_convert_three_times_01__unit_test() );
    UNIT_TEST( test_convert_three_times_02__unit_test() );
    UNIT_TEST( test_convert_three_times_03__unit_test() );
    UNIT_TEST( test_convert_three_times_04__unit_test() );
    UNIT_TEST( test_convert_three_times_05__unit_test() );
    UNIT_TEST( test_convert_three_times_06__unit_test() );
    UNIT_TEST( test_convert_three_times_07__unit_test() );
//    UNIT_TEST(  );
    return 0;
}



