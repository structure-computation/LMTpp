
#ifndef MATDENSE_H
#define MATDENSE_H
/// file generated from matdense.h.py. Do not modify

namespace LMT {

/*!
    \relates Mat
    goal : display data on one line (to be redefined for matrices, ...)
*/
template<class T,class Structure,class O,class OP>
std::ostream &line_output( std::ostream &s, const Mat<T,Structure,Dense<O>,OP> &m ) {
    s << m.data;
    return s;
}
/*!
    \relates Mat
    goal : get data from one line (to be redefined for matrices, ...)
*/
template<class T,class Structure,class O,class OP>
std::istream &line_input( std::istream &s, const Mat<T,Structure,Dense<O>,OP> &m ) {
    s >> m.data;
    return s;
}




template<class TT,int sr,int sc>
class Mat<TT,Gen<sr,sc>,Dense<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*sc : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef T& RetOp;
    typedef const T& RetOpConst;

    T &operator()(unsigned line,unsigned column) { return data[ line * real_nc.val + column ]; }
    const T &operator()(unsigned line,unsigned column) const { return data[ line * real_nc.val + column ]; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows); real_nr.set(default_nb_rows); this->nc.set(default_nb_cols); real_nc.set(default_nb_cols); resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows); real_nr.set(default_nb_rows); this->nc.set(default_nb_cols); real_nc.set(default_nb_cols); resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows); real_nr.set(default_nb_rows); this->nc.set(default_nb_cols); real_nc.set(default_nb_cols); resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows); real_nr.set(default_nb_rows); this->nc.set(default_nb_cols); real_nc.set(default_nb_cols); resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Gen<sr,sc>::need_diag and Gen<sr,sc>::need_upper==false and Gen<sr,sc>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Gen<sr,sc>::need_upper and Gen<sr,sc>::need_lower)==false and Gen<sr,sc>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Gen<sr,sc>::need_upper and Gen<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { 
        unsigned mc = min(nc,this->nc.val); 
        unsigned mr = min(nr,this->nr.val); 
        TV od = data; 
        unsigned o_r = real_nc.val; 
        unsigned rc=nc+alignement-1; 
        rc-=rc % alignement; 
        real_nc.set(rc); 
        real_nr.set(nr); 
        data.resize(real_nr.val*real_nc.val); 
        for(unsigned i=0;i<mr;++i) 
            for(unsigned j=0;j<mc;++j) 
                data[real_nc.val*i+j] = od[o_r*i+j]; 
        this->nr.set(nr);
        this->nc.set(nc); 
    }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sc> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sc> RetCol;
    typedef Vec<Ref<T,true >,sc> RetRowConst;
    typedef Vec<Ref<T,false>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<Ref<T,false>,sc> row(unsigned i) { return Vec<Ref<T,false>,sc>(data.ptr()+real_nc.val*i,nc.val); }
    Vec<Ref<T,true >,sc> row(unsigned i) const { return Vec<Ref<T,true >,sc>(data.ptr()+real_nc.val*i,nc.val); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sc> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sc> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sc>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Gen<sr,sc>,Dense<Col> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Gen<sr,sc>,Dense<Col> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Gen<sr,sc>,Dense<Col> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Gen<sr,sc>,Dense<Col> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Gen<sr,sc>,Dense<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Gen<sr,sc>,Dense<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Gen<sr,sc>,Dense<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Gen<sr,sc>,Dense<Col>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
    StaticValIf<unsigned,sr>=0,(unsigned)sr> real_nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> real_nc;
};


template<class TT,int sr,int sc>
class Mat<TT,Gen<sr,sc>,Dense<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*sc : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef T& RetOp;
    typedef const T& RetOpConst;

    T &operator()(unsigned line,unsigned column) { return data[ column * real_nr.val + line ]; }
    const T &operator()(unsigned line,unsigned column) const { return data[ column * real_nr.val + line ]; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows); real_nr.set(default_nb_rows); this->nc.set(default_nb_cols); real_nc.set(default_nb_cols); resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows); real_nr.set(default_nb_rows); this->nc.set(default_nb_cols); real_nc.set(default_nb_cols); resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows); real_nr.set(default_nb_rows); this->nc.set(default_nb_cols); real_nc.set(default_nb_cols); resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows); real_nr.set(default_nb_rows); this->nc.set(default_nb_cols); real_nc.set(default_nb_cols); resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Gen<sr,sc>::need_diag and Gen<sr,sc>::need_upper==false and Gen<sr,sc>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Gen<sr,sc>::need_upper and Gen<sr,sc>::need_lower)==false and Gen<sr,sc>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Gen<sr,sc>::need_upper and Gen<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned mr = min(nr,this->nr.val); unsigned mc = min(nc,this->nc.val); TV od = data; unsigned o_r = real_nr.val; unsigned rr=nr+alignement-1; rr-=rr % alignement; real_nr.set(rr); real_nc.set(nc); data.resize(real_nr.val*real_nc.val); for(unsigned i=0;i<mc;++i) for(unsigned j=0;j<mr;++j) data[real_nr.val*i+j] = od[o_r*i+j]; this->nr.set(nr); this->nc.set(nc); }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sc> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sc> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sc> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sc> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sc>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Gen<sr,sc>,Dense<Row> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Gen<sr,sc>,Dense<Row> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Gen<sr,sc>,Dense<Row> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Gen<sr,sc>,Dense<Row> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Gen<sr,sc>,Dense<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Gen<sr,sc>,Dense<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Gen<sr,sc>,Dense<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Gen<sr,sc>,Dense<Row>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
    StaticValIf<unsigned,sr>=0,(unsigned)sr> real_nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> real_nc;
};


template<class TT,int sr>
class Mat<TT,Sym<sr,0>,Dense<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2 : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,Sym<sr,0>,Dense<Col>,alignement> RetOp;
    typedef T RetOpConst;

    MatElem<TV,Sym<sr,0>,Dense<Col>,alignement> operator()(unsigned line,unsigned column) {
        return MatElem<TV,Sym<sr,0>,Dense<Col>,alignement>(
            data,
            line,
            column
            
            
        );
    }
    T operator()(unsigned line,unsigned column) const { if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Sym<sr,0>::need_diag and Sym<sr,0>::need_upper==false and Sym<sr,0>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Sym<sr,0>::need_upper and Sym<sr,0>::need_lower)==false and Sym<sr,0>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Sym<sr,0>::need_upper and Sym<sr,0>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Sym<sr,0>,Dense<Col> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Sym<sr,0>,Dense<Col> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Sym<sr,0>,Dense<Col> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Sym<sr,0>,Dense<Col> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Sym<sr,0>,Dense<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Sym<sr,0>,Dense<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Sym<sr,0>,Dense<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Sym<sr,0>,Dense<Col>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,Sym<sr,0>,Dense<Col>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        
        
    ):data(mm),line(i),column(j) {
        
        
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    T0 &ptr() { typedef T0 T; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    template<class T> operator T() const { if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    T0 conv() const { typedef T0 T; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) += val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) += (val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) -= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) -= (val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) *= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) *= (val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) /= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) /= (val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) %= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) %= (val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) &= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) &= (val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) |= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) |= (val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) <<= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) <<= (val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) >>= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) >>= (val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) = val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) = (val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,Sym<sr,1>,Dense<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2 : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,Sym<sr,1>,Dense<Col>,alignement,sr> RetOp;
    typedef T RetOpConst;

    MatElem<TV,Sym<sr,1>,Dense<Col>,alignement,sr> operator()(unsigned line,unsigned column) {
        return MatElem<TV,Sym<sr,1>,Dense<Col>,alignement,sr>(
            data,
            line,
            column
            ,nr.val
            ,off.val
        );
    }
    T operator()(unsigned line,unsigned column) const { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Sym<sr,1>::need_diag and Sym<sr,1>::need_upper==false and Sym<sr,1>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Sym<sr,1>::need_upper and Sym<sr,1>::need_lower)==false and Sym<sr,1>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Sym<sr,1>::need_upper and Sym<sr,1>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res);unsigned t=nr+alignement-1; off.set( res-1 ); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Sym<sr,1>,Dense<Col> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Sym<sr,1>,Dense<Col> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Sym<sr,1>,Dense<Col> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Sym<sr,1>,Dense<Col> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Sym<sr,1>,Dense<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Sym<sr,1>,Dense<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Sym<sr,1>,Dense<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Sym<sr,1>,Dense<Col>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2-1> off;
    
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,Sym<sr,1>,Dense<Col>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        ,unsigned ssr
        ,unsigned ova
    ):data(mm),line(i),column(j) {
        nr.set(ssr);
        off.set(ova);
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 &ptr() { typedef T0 T; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> operator T() const { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 conv() const { typedef T0 T; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += (val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= (val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= (val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= (val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= (val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= (val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= (val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= (val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= (val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = (val);}; return *this; }
    TV &data;
    unsigned line,column;
    StaticValIf<unsigned,nrs>=0,(unsigned)nrs> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2-1> off;
    
};


template<class TT,int sr>
class Mat<TT,Sym<sr,0>,Dense<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2 : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,Sym<sr,0>,Dense<Row>,alignement,sr> RetOp;
    typedef T RetOpConst;

    MatElem<TV,Sym<sr,0>,Dense<Row>,alignement,sr> operator()(unsigned line,unsigned column) {
        return MatElem<TV,Sym<sr,0>,Dense<Row>,alignement,sr>(
            data,
            line,
            column
            ,nr.val
            ,off.val
        );
    }
    T operator()(unsigned line,unsigned column) const { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Sym<sr,0>::need_diag and Sym<sr,0>::need_upper==false and Sym<sr,0>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Sym<sr,0>::need_upper and Sym<sr,0>::need_lower)==false and Sym<sr,0>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Sym<sr,0>::need_upper and Sym<sr,0>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res);unsigned t=nr+alignement-1; off.set( res-1 ); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Sym<sr,0>,Dense<Row> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Sym<sr,0>,Dense<Row> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Sym<sr,0>,Dense<Row> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Sym<sr,0>,Dense<Row> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Sym<sr,0>,Dense<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Sym<sr,0>,Dense<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Sym<sr,0>,Dense<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Sym<sr,0>,Dense<Row>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2-1> off;
    
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,Sym<sr,0>,Dense<Row>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        ,unsigned ssr
        ,unsigned ova
    ):data(mm),line(i),column(j) {
        nr.set(ssr);
        off.set(ova);
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 &ptr() { typedef T0 T; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> operator T() const { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 conv() const { typedef T0 T; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += (val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= (val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= (val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= (val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= (val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= (val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= (val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= (val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= (val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = (val);}; return *this; }
    TV &data;
    unsigned line,column;
    StaticValIf<unsigned,nrs>=0,(unsigned)nrs> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2-1> off;
    
};


template<class TT,int sr>
class Mat<TT,Sym<sr,1>,Dense<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2 : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,Sym<sr,1>,Dense<Row>,alignement> RetOp;
    typedef T RetOpConst;

    MatElem<TV,Sym<sr,1>,Dense<Row>,alignement> operator()(unsigned line,unsigned column) {
        return MatElem<TV,Sym<sr,1>,Dense<Row>,alignement>(
            data,
            line,
            column
            
            
        );
    }
    T operator()(unsigned line,unsigned column) const { if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Sym<sr,1>::need_diag and Sym<sr,1>::need_upper==false and Sym<sr,1>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Sym<sr,1>::need_upper and Sym<sr,1>::need_lower)==false and Sym<sr,1>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Sym<sr,1>::need_upper and Sym<sr,1>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Sym<sr,1>,Dense<Row> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Sym<sr,1>,Dense<Row> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Sym<sr,1>,Dense<Row> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Sym<sr,1>,Dense<Row> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Sym<sr,1>,Dense<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Sym<sr,1>,Dense<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Sym<sr,1>,Dense<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Sym<sr,1>,Dense<Row>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,Sym<sr,1>,Dense<Row>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        
        
    ):data(mm),line(i),column(j) {
        
        
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    T0 &ptr() { typedef T0 T; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    template<class T> operator T() const { if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    T0 conv() const { typedef T0 T; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) += val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) += (val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) -= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) -= (val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) *= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) *= (val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) /= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) /= (val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) %= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) %= (val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) &= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) &= (val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) |= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) |= (val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) <<= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) <<= (val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) >>= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) >>= (val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) = val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) = (val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,Herm<sr,0>,Dense<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2 : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,Herm<sr,0>,Dense<Col>,alignement> RetOp;
    typedef T RetOpConst;

    MatElem<TV,Herm<sr,0>,Dense<Col>,alignement> operator()(unsigned line,unsigned column) {
        return MatElem<TV,Herm<sr,0>,Dense<Col>,alignement>(
            data,
            line,
            column
            
            
        );
    }
    T operator()(unsigned line,unsigned column) const { if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return LMT::conj (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Herm<sr,0>::need_diag and Herm<sr,0>::need_upper==false and Herm<sr,0>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Herm<sr,0>::need_upper and Herm<sr,0>::need_lower)==false and Herm<sr,0>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Herm<sr,0>::need_upper and Herm<sr,0>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Herm<sr,0>,Dense<Col> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Herm<sr,0>,Dense<Col> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Herm<sr,0>,Dense<Col> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Herm<sr,0>,Dense<Col> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Herm<sr,0>,Dense<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Herm<sr,0>,Dense<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Herm<sr,0>,Dense<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Herm<sr,0>,Dense<Col>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,Herm<sr,0>,Dense<Col>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        
        
    ):data(mm),line(i),column(j) {
        
        
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return LMT::conj (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    T0 &ptr() { typedef T0 T; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return LMT::conj (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    template<class T> operator T() const { if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return LMT::conj (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    T0 conv() const { typedef T0 T; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return LMT::conj (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) += val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) += LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) -= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) -= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) *= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) *= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) /= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) /= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) %= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) %= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) &= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) &= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) |= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) |= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) <<= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) <<= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) >>= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) >>= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) = val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) = LMT::conj(val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,Herm<sr,1>,Dense<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2 : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,Herm<sr,1>,Dense<Col>,alignement,sr> RetOp;
    typedef T RetOpConst;

    MatElem<TV,Herm<sr,1>,Dense<Col>,alignement,sr> operator()(unsigned line,unsigned column) {
        return MatElem<TV,Herm<sr,1>,Dense<Col>,alignement,sr>(
            data,
            line,
            column
            ,nr.val
            ,off.val
        );
    }
    T operator()(unsigned line,unsigned column) const { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return LMT::conj (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Herm<sr,1>::need_diag and Herm<sr,1>::need_upper==false and Herm<sr,1>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Herm<sr,1>::need_upper and Herm<sr,1>::need_lower)==false and Herm<sr,1>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Herm<sr,1>::need_upper and Herm<sr,1>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res);unsigned t=nr+alignement-1; off.set( res-1 ); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Herm<sr,1>,Dense<Col> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Herm<sr,1>,Dense<Col> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Herm<sr,1>,Dense<Col> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Herm<sr,1>,Dense<Col> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Herm<sr,1>,Dense<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Herm<sr,1>,Dense<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Herm<sr,1>,Dense<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Herm<sr,1>,Dense<Col>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2-1> off;
    
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,Herm<sr,1>,Dense<Col>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        ,unsigned ssr
        ,unsigned ova
    ):data(mm),line(i),column(j) {
        nr.set(ssr);
        off.set(ova);
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return LMT::conj (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 &ptr() { typedef T0 T; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return LMT::conj (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> operator T() const { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return LMT::conj (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 conv() const { typedef T0 T; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return LMT::conj (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = LMT::conj(val);}; return *this; }
    TV &data;
    unsigned line,column;
    StaticValIf<unsigned,nrs>=0,(unsigned)nrs> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2-1> off;
    
};


template<class TT,int sr>
class Mat<TT,Herm<sr,0>,Dense<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2 : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,Herm<sr,0>,Dense<Row>,alignement,sr> RetOp;
    typedef T RetOpConst;

    MatElem<TV,Herm<sr,0>,Dense<Row>,alignement,sr> operator()(unsigned line,unsigned column) {
        return MatElem<TV,Herm<sr,0>,Dense<Row>,alignement,sr>(
            data,
            line,
            column
            ,nr.val
            ,off.val
        );
    }
    T operator()(unsigned line,unsigned column) const { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return LMT::conj (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Herm<sr,0>::need_diag and Herm<sr,0>::need_upper==false and Herm<sr,0>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Herm<sr,0>::need_upper and Herm<sr,0>::need_lower)==false and Herm<sr,0>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Herm<sr,0>::need_upper and Herm<sr,0>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res);unsigned t=nr+alignement-1; off.set( res-1 ); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Herm<sr,0>,Dense<Row> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Herm<sr,0>,Dense<Row> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Herm<sr,0>,Dense<Row> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Herm<sr,0>,Dense<Row> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Herm<sr,0>,Dense<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Herm<sr,0>,Dense<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Herm<sr,0>,Dense<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Herm<sr,0>,Dense<Row>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2-1> off;
    
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,Herm<sr,0>,Dense<Row>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        ,unsigned ssr
        ,unsigned ova
    ):data(mm),line(i),column(j) {
        nr.set(ssr);
        off.set(ova);
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return LMT::conj (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 &ptr() { typedef T0 T; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return LMT::conj (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> operator T() const { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return LMT::conj (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 conv() const { typedef T0 T; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return LMT::conj (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = LMT::conj(val);}; return *this; }
    TV &data;
    unsigned line,column;
    StaticValIf<unsigned,nrs>=0,(unsigned)nrs> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2-1> off;
    
};


template<class TT,int sr>
class Mat<TT,Herm<sr,1>,Dense<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2 : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,Herm<sr,1>,Dense<Row>,alignement> RetOp;
    typedef T RetOpConst;

    MatElem<TV,Herm<sr,1>,Dense<Row>,alignement> operator()(unsigned line,unsigned column) {
        return MatElem<TV,Herm<sr,1>,Dense<Row>,alignement>(
            data,
            line,
            column
            
            
        );
    }
    T operator()(unsigned line,unsigned column) const { if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return LMT::conj (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Herm<sr,1>::need_diag and Herm<sr,1>::need_upper==false and Herm<sr,1>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Herm<sr,1>::need_upper and Herm<sr,1>::need_lower)==false and Herm<sr,1>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Herm<sr,1>::need_upper and Herm<sr,1>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Herm<sr,1>,Dense<Row> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Herm<sr,1>,Dense<Row> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Herm<sr,1>,Dense<Row> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Herm<sr,1>,Dense<Row> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Herm<sr,1>,Dense<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Herm<sr,1>,Dense<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Herm<sr,1>,Dense<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Herm<sr,1>,Dense<Row>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,Herm<sr,1>,Dense<Row>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        
        
    ):data(mm),line(i),column(j) {
        
        
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return LMT::conj (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    T0 &ptr() { typedef T0 T; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return LMT::conj (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    template<class T> operator T() const { if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return LMT::conj (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    T0 conv() const { typedef T0 T; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return LMT::conj (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) += val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) += LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) -= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) -= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) *= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) *= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) /= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) /= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) %= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) %= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) &= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) &= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) |= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) |= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) <<= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) <<= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) >>= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) >>= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) = val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) = LMT::conj(val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,AntiSym<sr,0>,Dense<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? MAX(0,sr*(sr-1)/2) : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,AntiSym<sr,0>,Dense<Col>,alignement> RetOp;
    typedef T RetOpConst;

    MatElem<TV,AntiSym<sr,0>,Dense<Col>,alignement> operator()(unsigned line,unsigned column) {
        return MatElem<TV,AntiSym<sr,0>,Dense<Col>,alignement>(
            data,
            line,
            column
            
            
        );
    }
    T operator()(unsigned line,unsigned column) const { if (line==column) return (T)0; if ( line>=column ) {unsigned ri=(line-1)/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=(column-1)/alignement; return - (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( AntiSym<sr,0>::need_diag and AntiSym<sr,0>::need_upper==false and AntiSym<sr,0>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (AntiSym<sr,0>::need_upper and AntiSym<sr,0>::need_lower)==false and AntiSym<sr,0>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (AntiSym<sr,0>::need_upper and AntiSym<sr,0>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { nr-=(nr!=0); unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,AntiSym<sr,0>,Dense<Col> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,AntiSym<sr,0>,Dense<Col> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,AntiSym<sr,0>,Dense<Col> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,AntiSym<sr,0>,Dense<Col> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,0>,Dense<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,0>,Dense<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,0>,Dense<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,0>,Dense<Col>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,AntiSym<sr,0>,Dense<Col>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        
        
    ):data(mm),line(i),column(j) {
        
        
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if (line==column) return (T)0; if ( line>=column ) {unsigned ri=(line-1)/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=(column-1)/alignement; return - (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) ;}; }
    T0 &ptr() { typedef T0 T; if (line==column) return (T)0; if ( line>=column ) {unsigned ri=(line-1)/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=(column-1)/alignement; return - (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) ;}; }
    template<class T> operator T() const { if (line==column) return (T)0; if ( line>=column ) {unsigned ri=(line-1)/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=(column-1)/alignement; return - (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) ;}; }
    T0 conv() const { typedef T0 T; if (line==column) return (T)0; if ( line>=column ) {unsigned ri=(line-1)/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=(column-1)/alignement; return - (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line!=column) { if ( line>=column ) {unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) += val; } else { unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) += -(val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line!=column) { if ( line>=column ) {unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) -= val; } else { unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) -= -(val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line!=column) { if ( line>=column ) {unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) *= val; } else { unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) *= -(val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line!=column) { if ( line>=column ) {unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) /= val; } else { unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) /= -(val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line!=column) { if ( line>=column ) {unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) %= val; } else { unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) %= -(val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line!=column) { if ( line>=column ) {unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) &= val; } else { unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) &= -(val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line!=column) { if ( line>=column ) {unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) |= val; } else { unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) |= -(val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line!=column) { if ( line>=column ) {unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) <<= val; } else { unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) <<= -(val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line!=column) { if ( line>=column ) {unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) >>= val; } else { unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) >>= -(val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line!=column) { if ( line>=column ) {unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) = val; } else { unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) = -(val);}; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,AntiSym<sr,1>,Dense<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? MAX(0,sr*(sr-1)/2) : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,AntiSym<sr,1>,Dense<Col>,alignement,sr> RetOp;
    typedef T RetOpConst;

    MatElem<TV,AntiSym<sr,1>,Dense<Col>,alignement,sr> operator()(unsigned line,unsigned column) {
        return MatElem<TV,AntiSym<sr,1>,Dense<Col>,alignement,sr>(
            data,
            line,
            column
            ,nr.val
            ,off.val
        );
    }
    T operator()(unsigned line,unsigned column) const { if (line==column) return (T)0; if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return - (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( AntiSym<sr,1>::need_diag and AntiSym<sr,1>::need_upper==false and AntiSym<sr,1>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (AntiSym<sr,1>::need_upper and AntiSym<sr,1>::need_lower)==false and AntiSym<sr,1>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (AntiSym<sr,1>::need_upper and AntiSym<sr,1>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { nr-=(nr!=0); unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res);unsigned t=nr+alignement-1; off.set( res-1 ); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,AntiSym<sr,1>,Dense<Col> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,AntiSym<sr,1>,Dense<Col> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,AntiSym<sr,1>,Dense<Col> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,AntiSym<sr,1>,Dense<Col> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,1>,Dense<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,1>,Dense<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,1>,Dense<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,1>,Dense<Col>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)MAX(0,sr*(sr-1)/2)-1> off;
    
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,AntiSym<sr,1>,Dense<Col>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        ,unsigned ssr
        ,unsigned ova
    ):data(mm),line(i),column(j) {
        nr.set(ssr);
        off.set(ova);
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if (line==column) return (T)0; if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return - (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 &ptr() { typedef T0 T; if (line==column) return (T)0; if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return - (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> operator T() const { if (line==column) return (T)0; if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return - (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 conv() const { typedef T0 T; if (line==column) return (T)0; if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return - (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line!=column) { if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += val; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += -(val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line!=column) { if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= val; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= -(val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line!=column) { if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= val; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= -(val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line!=column) { if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= val; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= -(val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line!=column) { if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= val; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= -(val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line!=column) { if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= val; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= -(val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line!=column) { if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= val; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= -(val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line!=column) { if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= val; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= -(val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line!=column) { if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= val; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= -(val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line!=column) { if ( column>=line ) { unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = val; } else {  unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = -(val);}; } return *this; }
    TV &data;
    unsigned line,column;
    StaticValIf<unsigned,nrs>=0,(unsigned)nrs> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)MAX(0,sr*(sr-1)/2)-1> off;
    
};


template<class TT,int sr>
class Mat<TT,AntiSym<sr,0>,Dense<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? MAX(0,sr*(sr-1)/2) : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,AntiSym<sr,0>,Dense<Row>,alignement,sr> RetOp;
    typedef T RetOpConst;

    MatElem<TV,AntiSym<sr,0>,Dense<Row>,alignement,sr> operator()(unsigned line,unsigned column) {
        return MatElem<TV,AntiSym<sr,0>,Dense<Row>,alignement,sr>(
            data,
            line,
            column
            ,nr.val
            ,off.val
        );
    }
    T operator()(unsigned line,unsigned column) const { if (line==column) return (T)0; if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return - (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( AntiSym<sr,0>::need_diag and AntiSym<sr,0>::need_upper==false and AntiSym<sr,0>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (AntiSym<sr,0>::need_upper and AntiSym<sr,0>::need_lower)==false and AntiSym<sr,0>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (AntiSym<sr,0>::need_upper and AntiSym<sr,0>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { nr-=(nr!=0); unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res);unsigned t=nr+alignement-1; off.set( res-1 ); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,AntiSym<sr,0>,Dense<Row> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,AntiSym<sr,0>,Dense<Row> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,AntiSym<sr,0>,Dense<Row> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,AntiSym<sr,0>,Dense<Row> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,0>,Dense<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,0>,Dense<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,0>,Dense<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,0>,Dense<Row>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)MAX(0,sr*(sr-1)/2)-1> off;
    
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,AntiSym<sr,0>,Dense<Row>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        ,unsigned ssr
        ,unsigned ova
    ):data(mm),line(i),column(j) {
        nr.set(ssr);
        off.set(ova);
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if (line==column) return (T)0; if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return - (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 &ptr() { typedef T0 T; if (line==column) return (T)0; if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return - (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> operator T() const { if (line==column) return (T)0; if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return - (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 conv() const { typedef T0 T; if (line==column) return (T)0; if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return - (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line!=column) { if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += val; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += -(val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line!=column) { if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= val; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= -(val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line!=column) { if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= val; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= -(val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line!=column) { if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= val; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= -(val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line!=column) { if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= val; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= -(val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line!=column) { if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= val; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= -(val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line!=column) { if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= val; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= -(val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line!=column) { if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= val; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= -(val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line!=column) { if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= val; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= -(val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line!=column) { if ( line>=column ) { unsigned i1=nr.val-(column+1)-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = val; } else {  unsigned i1=nr.val-(line+1)-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = -(val);}; } return *this; }
    TV &data;
    unsigned line,column;
    StaticValIf<unsigned,nrs>=0,(unsigned)nrs> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)MAX(0,sr*(sr-1)/2)-1> off;
    
};


template<class TT,int sr>
class Mat<TT,AntiSym<sr,1>,Dense<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? MAX(0,sr*(sr-1)/2) : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,AntiSym<sr,1>,Dense<Row>,alignement> RetOp;
    typedef T RetOpConst;

    MatElem<TV,AntiSym<sr,1>,Dense<Row>,alignement> operator()(unsigned line,unsigned column) {
        return MatElem<TV,AntiSym<sr,1>,Dense<Row>,alignement>(
            data,
            line,
            column
            
            
        );
    }
    T operator()(unsigned line,unsigned column) const { if (line==column) return (T)0; if ( column>=line ) {unsigned ri=(column-1)/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=(line-1)/alignement; return - (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( AntiSym<sr,1>::need_diag and AntiSym<sr,1>::need_upper==false and AntiSym<sr,1>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (AntiSym<sr,1>::need_upper and AntiSym<sr,1>::need_lower)==false and AntiSym<sr,1>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (AntiSym<sr,1>::need_upper and AntiSym<sr,1>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { nr-=(nr!=0); unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res); this->nr.set(nr);  }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,sr> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sr> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sr> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,sr> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,sr>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,sr> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,sr>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sr> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sr> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sr>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,AntiSym<sr,1>,Dense<Row> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,AntiSym<sr,1>,Dense<Row> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,AntiSym<sr,1>,Dense<Row> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,AntiSym<sr,1>,Dense<Row> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,1>,Dense<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,1>,Dense<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,1>,Dense<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,1>,Dense<Row>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr,unsigned alignement,int nrs>
struct MatElem<TV,AntiSym<sr,1>,Dense<Row>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        
        
    ):data(mm),line(i),column(j) {
        
        
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if (line==column) return (T)0; if ( column>=line ) {unsigned ri=(column-1)/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=(line-1)/alignement; return - (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) ;}; }
    T0 &ptr() { typedef T0 T; if (line==column) return (T)0; if ( column>=line ) {unsigned ri=(column-1)/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=(line-1)/alignement; return - (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) ;}; }
    template<class T> operator T() const { if (line==column) return (T)0; if ( column>=line ) {unsigned ri=(column-1)/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=(line-1)/alignement; return - (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) ;}; }
    T0 conv() const { typedef T0 T; if (line==column) return (T)0; if ( column>=line ) {unsigned ri=(column-1)/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=(line-1)/alignement; return - (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line!=column) { if ( column>=line ) {unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) += val; } else { unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) += -(val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line!=column) { if ( column>=line ) {unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) -= val; } else { unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) -= -(val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line!=column) { if ( column>=line ) {unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) *= val; } else { unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) *= -(val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line!=column) { if ( column>=line ) {unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) /= val; } else { unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) /= -(val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line!=column) { if ( column>=line ) {unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) %= val; } else { unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) %= -(val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line!=column) { if ( column>=line ) {unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) &= val; } else { unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) &= -(val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line!=column) { if ( column>=line ) {unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) |= val; } else { unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) |= -(val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line!=column) { if ( column>=line ) {unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) <<= val; } else { unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) <<= -(val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line!=column) { if ( column>=line ) {unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) >>= val; } else { unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) >>= -(val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line!=column) { if ( column>=line ) {unsigned ri=(column-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((column-1) % alignement)*(ri+1)*alignement + line]) = val; } else { unsigned ri=(line-1)/alignement;  (data[ri*(ri+1)/2*alignement*alignement + ((line-1) % alignement)*(ri+1)*alignement + column]) = -(val);}; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr,int sc>
class Mat<TT,TriUpper<sr,sc>,Dense<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2+(sr-MIN(sr,sc))*sc+(sc-MIN(sr,sc))*sr : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,TriUpper<sr,sc>,Dense<Col>,alignement,sr> RetOp;
    typedef T RetOpConst;

    MatElem<TV,TriUpper<sr,sc>,Dense<Col>,alignement,sr> operator()(unsigned line,unsigned column) {
        return MatElem<TV,TriUpper<sr,sc>,Dense<Col>,alignement,sr>(
            data,
            line,
            column
            ,nr.val
            ,off.val
        );
    }
    T operator()(unsigned line,unsigned column) const { if (line>column) return (T)0; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( TriUpper<sr,sc>::need_diag and TriUpper<sr,sc>::need_upper==false and TriUpper<sr,sc>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (TriUpper<sr,sc>::need_upper and TriUpper<sr,sc>::need_lower)==false and TriUpper<sr,sc>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (TriUpper<sr,sc>::need_upper and TriUpper<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res);unsigned t=nr+alignement-1; off.set( res-1 ); this->nr.set(nr); this->nc.set(nc); }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sc> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sc> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sc> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sc> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sc>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,TriUpper<sr,sc>,Dense<Col> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,TriUpper<sr,sc>,Dense<Col> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,TriUpper<sr,sc>,Dense<Col> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,TriUpper<sr,sc>,Dense<Col> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,TriUpper<sr,sc>,Dense<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,TriUpper<sr,sc>,Dense<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,TriUpper<sr,sc>,Dense<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,TriUpper<sr,sc>,Dense<Col>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2+(sr-MIN(sr,sc))*sc+(sc-MIN(sr,sc))*sr-1> off;
    
};

template<class TV,int sr,int sc,unsigned alignement,int nrs>
struct MatElem<TV,TriUpper<sr,sc>,Dense<Col>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        ,unsigned ssr
        ,unsigned ova
    ):data(mm),line(i),column(j) {
        nr.set(ssr);
        off.set(ova);
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if (line>column) return (T)0; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 &ptr() { typedef T0 T; if (line>column) return (T)0; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> operator T() const { if (line>column) return (T)0; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 conv() const { typedef T0 T; if (line>column) return (T)0; if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line<=column) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += (val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line<=column) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= (val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line<=column) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= (val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line<=column) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= (val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line<=column) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= (val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line<=column) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= (val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line<=column) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= (val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line<=column) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= (val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line<=column) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= (val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line<=column) { if ( column>=line ) { unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = val; } else {  unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = (val);}; } return *this; }
    TV &data;
    unsigned line,column;
    StaticValIf<unsigned,nrs>=0,(unsigned)nrs> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2+(sr-MIN(sr,sc))*sc+(sc-MIN(sr,sc))*sr-1> off;
    
};


template<class TT,int sr,int sc>
class Mat<TT,TriUpper<sr,sc>,Dense<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2+(sr-MIN(sr,sc))*sc+(sc-MIN(sr,sc))*sr : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,TriUpper<sr,sc>,Dense<Row>,alignement> RetOp;
    typedef T RetOpConst;

    MatElem<TV,TriUpper<sr,sc>,Dense<Row>,alignement> operator()(unsigned line,unsigned column) {
        return MatElem<TV,TriUpper<sr,sc>,Dense<Row>,alignement>(
            data,
            line,
            column
            
            
        );
    }
    T operator()(unsigned line,unsigned column) const { if (line>column) return (T)0; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( TriUpper<sr,sc>::need_diag and TriUpper<sr,sc>::need_upper==false and TriUpper<sr,sc>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (TriUpper<sr,sc>::need_upper and TriUpper<sr,sc>::need_lower)==false and TriUpper<sr,sc>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (TriUpper<sr,sc>::need_upper and TriUpper<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res); this->nr.set(nr); this->nc.set(nc); }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sc> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sc> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sc> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sc> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sc>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,TriUpper<sr,sc>,Dense<Row> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,TriUpper<sr,sc>,Dense<Row> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,TriUpper<sr,sc>,Dense<Row> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,TriUpper<sr,sc>,Dense<Row> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,TriUpper<sr,sc>,Dense<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,TriUpper<sr,sc>,Dense<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,TriUpper<sr,sc>,Dense<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,TriUpper<sr,sc>,Dense<Row>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};

template<class TV,int sr,int sc,unsigned alignement,int nrs>
struct MatElem<TV,TriUpper<sr,sc>,Dense<Row>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        
        
    ):data(mm),line(i),column(j) {
        
        
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if (line>column) return (T)0; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    T0 &ptr() { typedef T0 T; if (line>column) return (T)0; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    template<class T> operator T() const { if (line>column) return (T)0; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    T0 conv() const { typedef T0 T; if (line>column) return (T)0; if ( column>=line ) {unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ; } else { unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line<=column) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) += val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) += (val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line<=column) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) -= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) -= (val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line<=column) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) *= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) *= (val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line<=column) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) /= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) /= (val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line<=column) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) %= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) %= (val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line<=column) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) &= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) &= (val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line<=column) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) |= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) |= (val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line<=column) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) <<= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) <<= (val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line<=column) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) >>= val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) >>= (val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line<=column) { if ( column>=line ) {unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) = val; } else { unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) = (val);}; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr,int sc>
class Mat<TT,TriLower<sr,sc>,Dense<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2+(sr-MIN(sr,sc))*sc+(sc-MIN(sr,sc))*sr : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,TriLower<sr,sc>,Dense<Col>,alignement> RetOp;
    typedef T RetOpConst;

    MatElem<TV,TriLower<sr,sc>,Dense<Col>,alignement> operator()(unsigned line,unsigned column) {
        return MatElem<TV,TriLower<sr,sc>,Dense<Col>,alignement>(
            data,
            line,
            column
            
            
        );
    }
    T operator()(unsigned line,unsigned column) const { if (line<column) return (T)0; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( TriLower<sr,sc>::need_diag and TriLower<sr,sc>::need_upper==false and TriLower<sr,sc>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (TriLower<sr,sc>::need_upper and TriLower<sr,sc>::need_lower)==false and TriLower<sr,sc>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (TriLower<sr,sc>::need_upper and TriLower<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res); this->nr.set(nr); this->nc.set(nc); }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sc> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sc> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sc> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sc> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sc>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,TriLower<sr,sc>,Dense<Col> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,TriLower<sr,sc>,Dense<Col> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,TriLower<sr,sc>,Dense<Col> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,TriLower<sr,sc>,Dense<Col> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,TriLower<sr,sc>,Dense<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,TriLower<sr,sc>,Dense<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,TriLower<sr,sc>,Dense<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,TriLower<sr,sc>,Dense<Col>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};

template<class TV,int sr,int sc,unsigned alignement,int nrs>
struct MatElem<TV,TriLower<sr,sc>,Dense<Col>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        
        
    ):data(mm),line(i),column(j) {
        
        
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if (line<column) return (T)0; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    T0 &ptr() { typedef T0 T; if (line<column) return (T)0; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    template<class T> operator T() const { if (line<column) return (T)0; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    T0 conv() const { typedef T0 T; if (line<column) return (T)0; if ( line>=column ) {unsigned ri=line/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) ; } else { unsigned ri=column/alignement; return  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line>=column) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) += val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) += (val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line>=column) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) -= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) -= (val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line>=column) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) *= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) *= (val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line>=column) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) /= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) /= (val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line>=column) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) %= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) %= (val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line>=column) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) &= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) &= (val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line>=column) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) |= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) |= (val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line>=column) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) <<= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) <<= (val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line>=column) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) >>= val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) >>= (val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line>=column) { if ( line>=column ) {unsigned ri=line/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (line % alignement)*(ri+1)*alignement + column]) = val; } else { unsigned ri=column/alignement;  (data[ri*(ri+1)/2*alignement*alignement + (column % alignement)*(ri+1)*alignement + line]) = (val);}; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr,int sc>
class Mat<TT,TriLower<sr,sc>,Dense<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? sr*(sr+1)/2+(sr-MIN(sr,sc))*sc+(sc-MIN(sr,sc))*sr : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,TriLower<sr,sc>,Dense<Row>,alignement,sr> RetOp;
    typedef T RetOpConst;

    MatElem<TV,TriLower<sr,sc>,Dense<Row>,alignement,sr> operator()(unsigned line,unsigned column) {
        return MatElem<TV,TriLower<sr,sc>,Dense<Row>,alignement,sr>(
            data,
            line,
            column
            ,nr.val
            ,off.val
        );
    }
    T operator()(unsigned line,unsigned column) const { if (line<column) return (T)0; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( TriLower<sr,sc>::need_diag and TriLower<sr,sc>::need_upper==false and TriLower<sr,sc>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (TriLower<sr,sc>::need_upper and TriLower<sr,sc>::need_lower)==false and TriLower<sr,sc>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (TriLower<sr,sc>::need_upper and TriLower<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res);unsigned t=nr+alignement-1; off.set( res-1 ); this->nr.set(nr); this->nc.set(nc); }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sc> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sc> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sc> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sc> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sc>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,TriLower<sr,sc>,Dense<Row> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,TriLower<sr,sc>,Dense<Row> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,TriLower<sr,sc>,Dense<Row> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,TriLower<sr,sc>,Dense<Row> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,TriLower<sr,sc>,Dense<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,TriLower<sr,sc>,Dense<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,TriLower<sr,sc>,Dense<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,TriLower<sr,sc>,Dense<Row>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2+(sr-MIN(sr,sc))*sc+(sc-MIN(sr,sc))*sr-1> off;
    
};

template<class TV,int sr,int sc,unsigned alignement,int nrs>
struct MatElem<TV,TriLower<sr,sc>,Dense<Row>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        ,unsigned ssr
        ,unsigned ova
    ):data(mm),line(i),column(j) {
        nr.set(ssr);
        off.set(ova);
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; if (line<column) return (T)0; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 &ptr() { typedef T0 T; if (line<column) return (T)0; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> operator T() const { if (line<column) return (T)0; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    T0 conv() const { typedef T0 T; if (line<column) return (T)0; if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement; return  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line>=column) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) += (val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line>=column) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) -= (val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line>=column) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) *= (val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line>=column) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) /= (val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line>=column) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) %= (val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line>=column) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) &= (val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line>=column) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) |= (val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line>=column) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) <<= (val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line>=column) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) >>= (val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line>=column) { if ( line>=column ) { unsigned i1=nr.val-column-1,i2=nr.val-line-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = val; } else {  unsigned i1=nr.val-line-1,i2=nr.val-column-1; unsigned ri=i1/alignement;  (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) = (val);}; } return *this; }
    TV &data;
    unsigned line,column;
    StaticValIf<unsigned,nrs>=0,(unsigned)nrs> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)sr*(sr+1)/2+(sr-MIN(sr,sc))*sc+(sc-MIN(sr,sc))*sr-1> off;
    
};


template<class TT,int sr,int sc>
class Mat<TT,Diag<sr,sc>,Dense<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? MIN(sr,sc) : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,Diag<sr,sc>,Dense<Col>,alignement> RetOp;
    typedef T RetOpConst;

    MatElem<TV,Diag<sr,sc>,Dense<Col>,alignement> operator()(unsigned line,unsigned column) {
        return MatElem<TV,Diag<sr,sc>,Dense<Col>,alignement>(
            data,
            line,
            column
            
            
        );
    }
    T operator()(unsigned line,unsigned column) const { return (line==column ? (T)data[line] : (T)0 ); }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Diag<sr,sc>::need_diag and Diag<sr,sc>::need_upper==false and Diag<sr,sc>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Diag<sr,sc>::need_upper and Diag<sr,sc>::need_lower)==false and Diag<sr,sc>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Diag<sr,sc>::need_upper and Diag<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { data.resize(nr); this->nr.set(nr); this->nc.set(nc); }

    typedef TV & RetDiag;
    typedef const TV & RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sc> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sc> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    TV & diag() { return data; }
    const TV & diag() const { return data; }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sc> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sc> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sc>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Diag<sr,sc>,Dense<Col> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Diag<sr,sc>,Dense<Col> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Diag<sr,sc>,Dense<Col> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Diag<sr,sc>,Dense<Col> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Diag<sr,sc>,Dense<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Diag<sr,sc>,Dense<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Diag<sr,sc>,Dense<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Diag<sr,sc>,Dense<Col>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};

template<class TV,int sr,int sc,unsigned alignement,int nrs>
struct MatElem<TV,Diag<sr,sc>,Dense<Col>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        
        
    ):data(mm),line(i),column(j) {
        
        
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; return (line==column ? (T)data[line] : (T)0 ); }
    T0 &ptr() { typedef T0 T; return (line==column ? (T)data[line] : (T)0 ); }
    template<class T> operator T() const { return (line==column ? (T)data[line] : (T)0 ); }
    T0 conv() const { typedef T0 T; return (line==column ? (T)data[line] : (T)0 ); }
    template<class T> MatElem &operator+=(const T &val) { DEBUGASSERT(line==column); data[line] += val; return *this; }
    template<class T> MatElem &operator-=(const T &val) { DEBUGASSERT(line==column); data[line] -= val; return *this; }
    template<class T> MatElem &operator*=(const T &val) { DEBUGASSERT(line==column); data[line] *= val; return *this; }
    template<class T> MatElem &operator/=(const T &val) { DEBUGASSERT(line==column); data[line] /= val; return *this; }
    template<class T> MatElem &operator%=(const T &val) { DEBUGASSERT(line==column); data[line] %= val; return *this; }
    template<class T> MatElem &operator&=(const T &val) { DEBUGASSERT(line==column); data[line] &= val; return *this; }
    template<class T> MatElem &operator|=(const T &val) { DEBUGASSERT(line==column); data[line] |= val; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { DEBUGASSERT(line==column); data[line] <<= val; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { DEBUGASSERT(line==column); data[line] >>= val; return *this; }
    template<class T> MatElem &operator=(const T &val) { DEBUGASSERT(line==column); data[line] = val; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr,int sc>
class Mat<TT,Diag<sr,sc>,Dense<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? MIN(sr,sc) : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
        Mat operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }

            unsigned m = mxGetM(variable) , n = mxGetN(variable); // dimensions de la matrice
            if ( fixed_size && (static_rows!=m || static_cols != n) ) {
                PRINTM( "Error : Mat<...>(const mxArray *variable) must take a vector of size " );
                throw std::runtime_error("size error");
            }

            resize( m, n );

            double *pr;
            pr = mxGetPr(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        operator()(i,j) = (TT)pr[i+j*m];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<m;++i)
                    for(unsigned j=0;j<n;++j)
                        set_imag(operator()(i,j),pr[i+j*m]);
            }

        }
    #endif

    TT &operator[](unsigned index) { return data[ index ]; }
    const TT &operator[](unsigned index) const { return data[ index ]; }

    TT &operator[](int index) { return data[ index ]; }
    const TT &operator[](int index) const { return data[ index ]; }

    void clear() { data.set((TT)0); } /// set all values to 0

    TT trace() const
    {
        TT tmp = 0;
        for (unsigned k=0; k<nb_rows(); ++k)
            tmp += operator()(k,k);
        return tmp;
    }

    
    typedef MatElem<TV,Diag<sr,sc>,Dense<Row>,alignement,sr> RetOp;
    typedef T RetOpConst;

    MatElem<TV,Diag<sr,sc>,Dense<Row>,alignement,sr> operator()(unsigned line,unsigned column) {
        return MatElem<TV,Diag<sr,sc>,Dense<Row>,alignement,sr>(
            data,
            line,
            column
            ,nr.val
            ,off.val
        );
    }
    T operator()(unsigned line,unsigned column) const { return (line==column ? (T)data[line] : (T)0 ); }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows);  this->nc.set(default_nb_cols);  resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( Diag<sr,sc>::need_diag and Diag<sr,sc>::need_upper==false and Diag<sr,sc>::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (Diag<sr,sc>::need_upper and Diag<sr,sc>::need_lower)==false and Diag<sr,sc>::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (Diag<sr,sc>::need_upper and Diag<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<i;++j)
                    operator()(i, j) = val(i, j);
        else
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<val.nb_cols();++j)
                    operator()(i, j) = val(i, j);
    }*/
    template<class T2,class STR2,class STO2,class O2> Mat( const Mat<T2,STR2,STO2,O2> &val ) {
        construct_matrix( *this, val );
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { data.resize(nr); this->nr.set(nr); this->nc.set(nc); }

    typedef TV & RetDiag;
    typedef const TV & RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sc> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sc> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    TV & diag() { return data; }
    const TV & diag() const { return data; }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sc> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sc> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sc>(*this,i); }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,Diag<sr,sc>,Dense<Row> > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,Diag<sr,sc>,Dense<Row> > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,Diag<sr,sc>,Dense<Row> > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,Diag<sr,sc>,Dense<Row> > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Diag<sr,sc>,Dense<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Diag<sr,sc>,Dense<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Diag<sr,sc>,Dense<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Diag<sr,sc>,Dense<Row>,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
    StaticValIf<unsigned,sr>=0,(unsigned)MIN(sr,sc)-1> off;
    
};

template<class TV,int sr,int sc,unsigned alignement,int nrs>
struct MatElem<TV,Diag<sr,sc>,Dense<Row>,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        ,unsigned ssr
        ,unsigned ova
    ):data(mm),line(i),column(j) {
        nr.set(ssr);
        off.set(ova);
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; return (line==column ? (T)data[line] : (T)0 ); }
    T0 &ptr() { typedef T0 T; return (line==column ? (T)data[line] : (T)0 ); }
    template<class T> operator T() const { return (line==column ? (T)data[line] : (T)0 ); }
    T0 conv() const { typedef T0 T; return (line==column ? (T)data[line] : (T)0 ); }
    template<class T> MatElem &operator+=(const T &val) { DEBUGASSERT(line==column); data[line] += val; return *this; }
    template<class T> MatElem &operator-=(const T &val) { DEBUGASSERT(line==column); data[line] -= val; return *this; }
    template<class T> MatElem &operator*=(const T &val) { DEBUGASSERT(line==column); data[line] *= val; return *this; }
    template<class T> MatElem &operator/=(const T &val) { DEBUGASSERT(line==column); data[line] /= val; return *this; }
    template<class T> MatElem &operator%=(const T &val) { DEBUGASSERT(line==column); data[line] %= val; return *this; }
    template<class T> MatElem &operator&=(const T &val) { DEBUGASSERT(line==column); data[line] &= val; return *this; }
    template<class T> MatElem &operator|=(const T &val) { DEBUGASSERT(line==column); data[line] |= val; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { DEBUGASSERT(line==column); data[line] <<= val; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { DEBUGASSERT(line==column); data[line] >>= val; return *this; }
    template<class T> MatElem &operator=(const T &val) { DEBUGASSERT(line==column); data[line] = val; return *this; }
    TV &data;
    unsigned line,column;
    StaticValIf<unsigned,nrs>=0,(unsigned)nrs> nr;
    StaticValIf<unsigned,sr>=0,(unsigned)MIN(sr,sc)-1> off;
    
};

} // namespace LMT

#endif /// MATDENSE_H

