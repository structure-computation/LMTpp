
namespace LMT {

/*!
    mat * vec
*/
template<class TM,class TV>
struct VecMatVecMult {};

template<class TM,class TV> struct IsVecOp<VecMatVecMult<TM,TV> > { typedef int T; };
template<class TM,class TV,int s> struct CostAccess<Vec<VecMatVecMult<TM,TV>,s> > { static const unsigned res = 1000; };

    
template<class TM,class TV,int static_size_>
class Vec<VecMatVecMult<TM,TV>,static_size_,int> {
public:
    typedef typename TypePromote<Plus,typename TM::T,typename TV::template SubType<0>::T>::T T0;
    template<unsigned n> struct SubType { typedef T0 T; };
    static const unsigned nb_sub_type = 1;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 0;

    Vec(const TM &mm,const TV &vv):m(mm),v(vv) {}
    unsigned size() const { return m.nb_rows(); }

    T0 operator[](unsigned i) const { return dot( m.row(i), v ); }
    
    typedef T0 RetOpConst;
    typedef T0 RetOp;


    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,true >,s2> operator[](const Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,true>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2> operator[](const Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2> operator[](Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2> operator[](Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2>(*this,v2); }
    

    const TM &m;
    typename AlternativeOnType< ( CostAccess<TV>::res > 1 ),
        //const TV &,
        Vec<T0>,
        Vec<T0> 
    >::T v;
    
};

struct MulMatVecRow {
    template<class T,class TR,class T2> void operator()(const T &valc,unsigned i,TR &res,const T2 &mu) const {
        res[ i ] += mu * valc;
    }
};

/*!
    	odo replace apply_nz by a vectorial version
*/
template<class T,class Str,class Sto,class IO,class T2,int s2,class IO2>
Vec< typename TypePromote<Multiplies,typename Mat<T,Str,Sto,IO>::T,typename Vec<T2,s2,IO2>::template SubType<0>::T>::T , Str::static_nb_rows >
 mulmatvec(const Mat<T,Str,Sto,IO> &m, const Vec<T2,s2,IO2> &v,const Number<0> &nn) {
    typedef typename TypePromote<Multiplies,typename Mat<T,Str,Sto,IO>::T,typename Vec<T2,s2,IO2>::template SubType<0>::T>::T TR;
    Vec< TR, Str::static_nb_rows > res; res.resize( m.nb_rows(), TR(0) );
    
    for(unsigned i=0;i<m.nb_cols();++i)
        apply_nz_wi( m.col(i), MulMatVecRow(), res, v[i] );
    
    return res;
}

template<class T,class Str,class Sto,class IO,class T2,int s2,class IO2>
Vec< VecMatVecMult< Mat<T,Str,Sto,IO>,Vec<T2,s2,IO2> >, Str::static_nb_rows >
 mulmatvec(const Mat<T,Str,Sto,IO> &m, const Vec<T2,s2,IO2> &v,const Number<1> &nn) {
    return Vec<VecMatVecMult<Mat<T,Str,Sto,IO>,Vec<T2,s2,IO2> >, Str::static_nb_rows >( m, v );
}

template<class TM,class TV> struct ReturnTypeMatMultVec {};

template<class TT,class Str,class Sto,class IO,class T2,int s2,class IO2>
struct ReturnTypeMatMultVec<Mat<TT,Str,Sto,IO>,Vec<T2,s2,IO2> > {
    typedef typename AlternativeOnType<
        Sto::col_oriented,
        Vec< typename TypePromote<Multiplies,typename Mat<TT,Str,Sto,IO>::T,typename Vec<T2,s2,IO2>::template SubType<0>::T>::T, Str::static_nb_rows >,
        Vec< VecMatVecMult< Mat<TT,Str,Sto,IO>,Vec<T2,s2,IO2> >, Str::static_nb_rows >
    >::T T;
};

template<class T,class Str,class Sto,class IO,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<Mat<T,Str,Sto,IO>,Vec<T2,s2,IO2> >::T operator*(const Mat<T,Str,Sto,IO> &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return mulmatvec( m, v, Number<Sto::col_oriented>() );
}



/*!
    mat * vec
*/
template<class TM1,class TM2>
struct MatMultMat {};

template<class TM1,class TM2> struct IsMatOp<MatMultMat<TM1,TM2> > { typedef int T; };

template<class TM1,class TM2,class Structure,class Storage>
class Mat<MatMultMat<TM1,TM2>,Structure,Storage,int> {
public:
    typedef typename TypePromote<Multiplies,typename TM1::T,typename TM2::T>::T T;

    Mat(const TM1 &mm1,const TM2 &mm2):m1(mm1),m2(mm2) {}
    
    unsigned nb_rows() const { return m1.nb_rows(); }
    unsigned nb_cols() const { return m2.nb_cols(); }
    
    typedef T RetOpConst;
    typedef T RetOp;

    T operator()( unsigned i, unsigned j ) const { return dot( m1.row(i), m2.col(j) ); }


    typedef Vec<VecSubMat<Mat,false,ExtractDiag> > RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag> > RetDiagConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow > > RetRow;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow > > RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol > > RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol > > RetColConst;
    
    RetDiagConst diag() const { return *this; }
    RetDiag diag() { return *this; }
    RetRowConst row(unsigned i) const { return RetRowConst(*this,i); }
    RetRow row(unsigned i) { return RetRow(*this,i); }
    RetColConst col(unsigned i) const { return RetColConst(*this,i); }
    RetCol col(unsigned i) { return RetCol(*this,i); }



    const TM1 &m1;
    const TM2 &m2;
};

template<class T1,class STR1,class STO1,class O1,class T2,class STR2,class STO2,class O2>
Mat<MatMultMat<Mat<T1,STR1,STO1,O1>,Mat<T2,STR2,STO2,O2> > > operator*(const Mat<T1,STR1,STO1,O1> &m1,const Mat<T2,STR2,STO2,O2> &m2) {
    return Mat<MatMultMat<Mat<T1,STR1,STO1,O1>,Mat<T2,STR2,STO2,O2> > >( m1, m2 );
}

/*
// ----------------- m1 * m2 * v -----------------
template<class TM1,class TM2,class Str,class Sto,class IO,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<
    TM1,
    typename ReturnTypeMatMultVec<TM2,Vec<T2,s2,IO2> >::T
>::T
operator*(const Mat<MatMultMat<TM1,TM2>,Str,Sto,IO> &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return m.m1 * ( m.m2 * v );
}


// ----------------- m1 * m2 * m3 * v -----------------
template<class TM1,class TM2,class TM3,class Str,class Sto,class IO,class T2,int s2,class IO2,class Str3,class Sto3,class IO3>
Vec< VecMatVecMult< TM1,
    Vec< VecMatVecMult<TM2,
        Vec< VecMatVecMult<TM3,
            Vec<T2,s2,IO2>
        > >
    > >
> >
operator*(const Mat<MatMultMat<  Mat<MatMultMat<TM1,TM2>,Str3,Sto3,IO3>, TM3 >,Str,Sto,IO> &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return m.m1.m1 * ( m.m1.m2 * ( m.m2 * v ) );
}
*/


template<class TM0,class TM1,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,Vec<T2,s2,IO2> >::T>::T
operator*(const Mat<MatMultMat<TM0,TM1> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,Vec<T2,s2,IO2> >::T>::T( m.m1 * typename ReturnTypeMatMultVec<TM1,Vec<T2,s2,IO2> >::T(m.m2 * v) );
}
template<class TM0,class TM1,class TM2,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,Vec<T2,s2,IO2> >::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,TM1> > ,TM2> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,Vec<T2,s2,IO2> >::T>::T>::T( m.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM2,Vec<T2,s2,IO2> >::T(m.m2 * v)) );
}
template<class TM0,class TM1,class TM2,class TM3,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,Vec<T2,s2,IO2> >::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,TM2> > > > ,TM3> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,Vec<T2,s2,IO2> >::T>::T>::T>::T( m.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM3,Vec<T2,s2,IO2> >::T(m.m2 * v))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,TM3> > > > > > ,TM4> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T( m.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM4,Vec<T2,s2,IO2> >::T(m.m2 * v)))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class TM5,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,Mat<MatMultMat<TM3,TM4> > > > > > > > ,TM5> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T( m.m1.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM5,Vec<T2,s2,IO2> >::T(m.m2 * v))))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class TM5,class TM6,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,Mat<MatMultMat<TM3,Mat<MatMultMat<TM4,TM5> > > > > > > > > > ,TM6> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T( m.m1.m1.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM6,Vec<T2,s2,IO2> >::T(m.m2 * v)))))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class TM5,class TM6,class TM7,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,Mat<MatMultMat<TM3,Mat<MatMultMat<TM4,Mat<MatMultMat<TM5,TM6> > > > > > > > > > > > ,TM7> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T( m.m1.m1.m1.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM7,Vec<T2,s2,IO2> >::T(m.m2 * v))))))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class TM5,class TM6,class TM7,class TM8,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,Mat<MatMultMat<TM3,Mat<MatMultMat<TM4,Mat<MatMultMat<TM5,Mat<MatMultMat<TM6,TM7> > > > > > > > > > > > > > ,TM8> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T( m.m1.m1.m1.m1.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM8,Vec<T2,s2,IO2> >::T(m.m2 * v)))))))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class TM5,class TM6,class TM7,class TM8,class TM9,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,Mat<MatMultMat<TM3,Mat<MatMultMat<TM4,Mat<MatMultMat<TM5,Mat<MatMultMat<TM6,Mat<MatMultMat<TM7,TM8> > > > > > > > > > > > > > > > ,TM9> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T( m.m1.m1.m1.m1.m1.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM9,Vec<T2,s2,IO2> >::T(m.m2 * v))))))))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class TM5,class TM6,class TM7,class TM8,class TM9,class TM10,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,Mat<MatMultMat<TM3,Mat<MatMultMat<TM4,Mat<MatMultMat<TM5,Mat<MatMultMat<TM6,Mat<MatMultMat<TM7,Mat<MatMultMat<TM8,TM9> > > > > > > > > > > > > > > > > > ,TM10> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T( m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM10,Vec<T2,s2,IO2> >::T(m.m2 * v)))))))))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class TM5,class TM6,class TM7,class TM8,class TM9,class TM10,class TM11,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,Mat<MatMultMat<TM3,Mat<MatMultMat<TM4,Mat<MatMultMat<TM5,Mat<MatMultMat<TM6,Mat<MatMultMat<TM7,Mat<MatMultMat<TM8,Mat<MatMultMat<TM9,TM10> > > > > > > > > > > > > > > > > > > > ,TM11> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T( m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM11,Vec<T2,s2,IO2> >::T(m.m2 * v))))))))))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class TM5,class TM6,class TM7,class TM8,class TM9,class TM10,class TM11,class TM12,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,Mat<MatMultMat<TM3,Mat<MatMultMat<TM4,Mat<MatMultMat<TM5,Mat<MatMultMat<TM6,Mat<MatMultMat<TM7,Mat<MatMultMat<TM8,Mat<MatMultMat<TM9,Mat<MatMultMat<TM10,TM11> > > > > > > > > > > > > > > > > > > > > > ,TM12> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T( m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM12,Vec<T2,s2,IO2> >::T(m.m2 * v)))))))))))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class TM5,class TM6,class TM7,class TM8,class TM9,class TM10,class TM11,class TM12,class TM13,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,Mat<MatMultMat<TM3,Mat<MatMultMat<TM4,Mat<MatMultMat<TM5,Mat<MatMultMat<TM6,Mat<MatMultMat<TM7,Mat<MatMultMat<TM8,Mat<MatMultMat<TM9,Mat<MatMultMat<TM10,Mat<MatMultMat<TM11,TM12> > > > > > > > > > > > > > > > > > > > > > > > ,TM13> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T( m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM13,Vec<T2,s2,IO2> >::T(m.m2 * v))))))))))))) );
}
template<class TM0,class TM1,class TM2,class TM3,class TM4,class TM5,class TM6,class TM7,class TM8,class TM9,class TM10,class TM11,class TM12,class TM13,class TM14,class T2,int s2,class IO2>
typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T
operator*(const Mat<MatMultMat<Mat<MatMultMat<TM0,Mat<MatMultMat<TM1,Mat<MatMultMat<TM2,Mat<MatMultMat<TM3,Mat<MatMultMat<TM4,Mat<MatMultMat<TM5,Mat<MatMultMat<TM6,Mat<MatMultMat<TM7,Mat<MatMultMat<TM8,Mat<MatMultMat<TM9,Mat<MatMultMat<TM10,Mat<MatMultMat<TM11,Mat<MatMultMat<TM12,TM13> > > > > > > > > > > > > > > > > > > > > > > > > > ,TM14> > &m, const Vec<T2,s2,IO2> &v) {
    DEBUGASSERT( m.nb_cols()==v.size() );
    return typename ReturnTypeMatMultVec<TM0,typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T( m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1 * typename ReturnTypeMatMultVec<TM1,typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM2,typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM3,typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM4,typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM5,typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM6,typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM7,typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM8,typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM9,typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM10,typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T>::T(m.m1.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM11,typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T>::T(m.m1.m1.m1.m2 * typename ReturnTypeMatMultVec<TM12,typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T>::T(m.m1.m1.m2 * typename ReturnTypeMatMultVec<TM13,typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T>::T(m.m1.m2 * typename ReturnTypeMatMultVec<TM14,Vec<T2,s2,IO2> >::T(m.m2 * v)))))))))))))) );
}
} // namespace LMT 
