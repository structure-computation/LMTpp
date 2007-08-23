GETDRC = """
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
"""