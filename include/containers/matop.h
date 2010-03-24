
namespace LMT {

/**
    op(mat1,mat2...)
*/
template<class Op,unsigned nb_v,class TM1,bool br1,class TM2=void,bool br2=true,class TM3=void,bool br3=true>
struct MatOp {};

template<class Op,unsigned nb_v,class TM1,bool br1,class TM2,bool br2,class TM3,bool br3> struct IsMatOp<MatOp<Op,nb_v,TM1,br1,TM2,br2,TM3,br3> > { typedef int T; };


template<class Op,class TM0,bool br0,class TM1,bool br1,class TM2,bool br2,class Structure,class Storage>
class Mat<MatOp<Op,1,TM0,br0,TM1,br1,TM2,br2>,Structure,Storage,int> {
public:
    Mat(const TM0 &mm0):m0(mm0) {}
    
    typedef typename TM0::T T0;
    typedef typename Op::template ReturnType<T0>::T T;
    
    typedef T& RetOp;
    typedef T RetOpConst;
    
    unsigned nb_rows() const { return m0.val.nb_rows(); }
    unsigned nb_cols() const { return m0.val.nb_cols(); }

    T operator()(unsigned i,unsigned j) const { return op(m0.val(i,j)); }


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

    
    StoreByRefIf<TM0,br0> m0;
    Op op;
};


template<class Op,class TM0,bool br0,class TM1,bool br1,class TM2,bool br2,class Structure,class Storage>
class Mat<MatOp<Op,2,TM0,br0,TM1,br1,TM2,br2>,Structure,Storage,int> {
public:
    Mat(const TM0 &mm0,const TM1 &mm1):m0(mm0),m1(mm1) {}
    
    typedef typename TM0::T T0;
    typedef typename TM1::T T1;
    typedef typename Op::template ReturnType<T0,T1>::T T;
    
    typedef T& RetOp;
    typedef T RetOpConst;
    
    unsigned nb_rows() const { return m0.val.nb_rows(); }
    unsigned nb_cols() const { return m0.val.nb_cols(); }

    T operator()(unsigned i,unsigned j) const { return op(m0.val(i,j),m1.val(i,j)); }


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

    
    StoreByRefIf<TM0,br0> m0;
    StoreByRefIf<TM1,br1> m1;
    Op op;
};


template<class Op,class TM0,bool br0,class TM1,bool br1,class TM2,bool br2,class Structure,class Storage>
class Mat<MatOp<Op,3,TM0,br0,TM1,br1,TM2,br2>,Structure,Storage,int> {
public:
    Mat(const TM0 &mm0,const TM1 &mm1,const TM2 &mm2):m0(mm0),m1(mm1),m2(mm2) {}
    
    typedef typename TM0::T T0;
    typedef typename TM1::T T1;
    typedef typename TM2::T T2;
    typedef typename Op::template ReturnType<T0,T1,T2>::T T;
    
    typedef T& RetOp;
    typedef T RetOpConst;
    
    unsigned nb_rows() const { return m0.val.nb_rows(); }
    unsigned nb_cols() const { return m0.val.nb_cols(); }

    T operator()(unsigned i,unsigned j) const { return op(m0.val(i,j),m1.val(i,j),m2.val(i,j)); }


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

    
    StoreByRefIf<TM0,br0> m0;
    StoreByRefIf<TM1,br1> m1;
    StoreByRefIf<TM2,br2> m2;
    Op op;
};


} // namespace LMT

