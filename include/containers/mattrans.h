
namespace LMT {

/*!
    mat * vec
*/
template<class TM,bool const_tm>
struct MatTrans {};

template<class TM,bool const_tm> struct IsMatOp<MatTrans<TM,const_tm> > { typedef int T; };

template<class TM,bool const_tm,class _Structure,class _Storage>
class Mat<MatTrans<TM,const_tm>,_Structure,_Storage,int> {
public:
    typedef typename TM::T T;
    typedef _Structure Structure;
    typedef _Storage Storage;
    
    
    unsigned nb_rows() const { return ptr.val->nb_cols(); }
    unsigned nb_cols() const { return ptr.val->nb_rows(); }

    typedef typename TM::RetDiagConst RetDiagConst;
    typedef typename TM::RetDiag RetDiag;

    typedef typename TM::RetColConst RetRowConst;
    typedef typename TM::RetCol RetRow;
    
    typedef typename TM::RetRowConst RetColConst;
    typedef typename TM::RetRow RetCol;
    
    typedef typename TM::RetOp RetOp;
    typedef typename TM::RetOpConst RetOpConst;

    RetOp operator()(unsigned i,unsigned j) { return (*ptr.val)(j,i); }
    RetOpConst operator()(unsigned i,unsigned j) const { return (*ptr.val)(j,i); }
    
    RetDiag diag() { return ptr.val->diag(); }
    RetDiagConst diag() const { return ptr.val->diag(); }
    
    RetRowConst row(unsigned i) const { return RetRowConst(ptr.val->col(i)); }
    RetRow row(unsigned i) { return ptr.val->col(i); }
    
    RetColConst col(unsigned i) const { return ptr.val->row(i); }
    RetCol col(unsigned i) { return ptr.val->row(i); }
    
    PtrConstIf<TM,const_tm> ptr;
};

template<class TT,class STR,class STO,class IO> Mat<MatTrans<Mat<TT,STR,STO,IO>,true>,typename StructureTrans<STR>::T,typename STO::Trans>
 trans(const Mat<TT,STR,STO,IO> &m) {
    Mat<MatTrans<Mat<TT,STR,STO,IO>,true>,typename StructureTrans<STR>::T,typename STO::Trans> res; res.ptr.val = &m; return res;
}
template<class TT,class STR,class STO,class IO> Mat<MatTrans<Mat<TT,STR,STO,IO>,false>,typename StructureTrans<STR>::T,typename STO::Trans>
 trans(Mat<TT,STR,STO,IO> &m) {
    Mat<MatTrans<Mat<TT,STR,STO,IO>,false>,typename StructureTrans<STR>::T,typename STO::Trans> res; res.ptr.val = &m; return res;
}


} // namespace LMT


