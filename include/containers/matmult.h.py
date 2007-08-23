from string import *
from vecgenhelp import *
from matgenhelp import *

# mat * vec
print """
namespace LMT {

/**
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

"""+GETRANGE+"""

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

/**
    \todo replace apply_nz by a vectorial version
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



/**
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

    T operator()(unsigned i,unsigned j) const { return dot( m1.row(i), m2.col(j) ); }

"""+GETDRC+"""


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

"""

for nb_par in range(2,16):
    def J(s,sep=',',n=nb_par): return join([s%{'i':i} for i in range(n)],sep)
    def print_rec_ret(val,end):
        if val==end: return 'Vec<T2,s2,IO2> '
        else: return 'typename ReturnTypeMatMultVec<TM'+str(val)+','+print_rec_ret(val+1,end)+'>::T'
    def print_rec_calc(val,end):
        if val>=end:
            return  'm.m2 * v'
        return 'm.'+J('m1','.',end-val)+'.m2 * '+print_rec_ret(val,nb_par)+'('+ print_rec_calc(val+1,end) +')'
    def print_ent(val,end):
        if val>=end: return 'TM'+str(val)
        return 'Mat<MatMultMat<TM'+str(val)+','+print_ent(val+1,end)+'> > ' # ,Str_'+str(val)+',Sto_'+str(val)+',IO_'+str(val)+'
    print 'template<'+J('class TM%(i)i')+0*','+0*J('class Str_%(i)i,class Sto_%(i)i,class IO_%(i)i',',',nb_par-1)+',class T2,int s2,class IO2>'
    retr = print_rec_ret(0,nb_par)
    print retr
    si = str(nb_par-1)
    print 'operator*(const Mat<MatMultMat<'+print_ent(0,nb_par-2)+',TM'+si+'> > &m, const Vec<T2,s2,IO2> &v) {'
    print '    DEBUGASSERT( m.nb_cols()==v.size() );'
    print '    return '+retr+'( m.'+J('m1','.',nb_par-1)+' * '+print_rec_ret(1,nb_par)+'('+print_rec_calc(2,nb_par)+') );' # Vec<'+retr+',TM1::static_rows>
    print '}'


print """} // namespace LMT """
