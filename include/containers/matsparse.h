// file generated from matsparse.h.py. Do not modify
#include <map>

namespace LMT {



template<class TT,int sr,int sc>
class Mat<TT,Gen<sr,sc>,SparseLine<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    typedef Vec<Sparse<TT>,static_cols> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_rows> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef DelayedAssignement<DelayedAssignementSparseSource<TT> > RetOp;
    typedef T RetOpConst;

    RetOp operator()(unsigned line,unsigned column) { return data[line][column]; }
    RetOpConst operator()(unsigned line,unsigned column) const { return data[line][column]; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Gen<sr,sc>,SparseLine<Col>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Gen<sr,sc>,SparseLine<Col>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Gen<sr,sc>::need_upper and Gen<sr,sc>::need_lower)==false and Gen<sr,sc>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Gen<sr,sc>::need_upper and Gen<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); this->nc.set(nc);
        data.resize(nr);
        for(unsigned i=0;i<nr;++i)
            data[i].resize(nc);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef const Vec<Sparse<TT>,sc> & RetRowConst;
    typedef Vec<Sparse<TT>,sc> & RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<Sparse<TT>,sc> & row(unsigned i) { return data[i]; }
    const Vec<Sparse<TT>,sc> & row(unsigned i) const { return data[i]; }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Gen<sr,sc>,SparseLine<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Gen<sr,sc>,SparseLine<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Gen<sr,sc>,SparseLine<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Gen<sr,sc>,SparseLine<Col>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};


template<class TT,int sr,int sc>
class Mat<TT,Gen<sr,sc>,SparseLine<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    typedef Vec<Sparse<TT>,static_rows> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_cols> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef DelayedAssignement<DelayedAssignementSparseSource<TT> > RetOp;
    typedef T RetOpConst;

    RetOp operator()(unsigned line,unsigned column) { return data[column][line]; }
    RetOpConst operator()(unsigned line,unsigned column) const { return data[column][line]; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Gen<sr,sc>,SparseLine<Row>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Gen<sr,sc>,SparseLine<Row>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Gen<sr,sc>::need_upper and Gen<sr,sc>::need_lower)==false and Gen<sr,sc>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Gen<sr,sc>::need_upper and Gen<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); this->nc.set(nc);
        data.resize(nc);
        for(unsigned i=0;i<nc;++i)
            data[i].resize(nr);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef const Vec<Sparse<TT>,sr> & RetColConst;
    typedef Vec<Sparse<TT>,sr> & RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<Sparse<TT>,sr> & col(unsigned i) { return data[i]; }
    const Vec<Sparse<TT>,sr> & col(unsigned i) const { return data[i]; }

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Gen<sr,sc>,SparseLine<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Gen<sr,sc>,SparseLine<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Gen<sr,sc>,SparseLine<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Gen<sr,sc>,SparseLine<Row>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};


template<class TT,int sr>
class Mat<TT,Sym<sr,0>,SparseLine<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_cols> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_rows> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,Sym<sr,0>,SparseLine<Col> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,Sym<sr,0>,SparseLine<Col> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,Sym<sr,0>,SparseLine<Col> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if ( line>=column ) {return  (data[line][column]) ; } else { return  (data[column][line]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Sym<sr,0>,SparseLine<Col>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Sym<sr,0>,SparseLine<Col>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Sym<sr,0>::need_upper and Sym<sr,0>::need_lower)==false and Sym<sr,0>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Sym<sr,0>::need_upper and Sym<sr,0>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nr);
        for(unsigned i=0;i<nr;++i)
            data[i].resize(nc);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Sym<sr,0>,SparseLine<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Sym<sr,0>,SparseLine<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Sym<sr,0>,SparseLine<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Sym<sr,0>,SparseLine<Col>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,Sym<sr,0>,SparseLine<Col> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if ( line>=column ) {return  (data[line][column]) ; } else { return  (data[column][line]) ;}; }
    T0 conv() const { if ( line>=column ) {return  (data[line][column]) ; } else { return  (data[column][line]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( line>=column ) { (data[line][column]) += val; } else {  (data[column][line]) += (val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( line>=column ) { (data[line][column]) -= val; } else {  (data[column][line]) -= (val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( line>=column ) { (data[line][column]) *= val; } else {  (data[column][line]) *= (val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( line>=column ) { (data[line][column]) /= val; } else {  (data[column][line]) /= (val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( line>=column ) { (data[line][column]) %= val; } else {  (data[column][line]) %= (val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( line>=column ) { (data[line][column]) &= val; } else {  (data[column][line]) &= (val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( line>=column ) { (data[line][column]) |= val; } else {  (data[column][line]) |= (val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( line>=column ) { (data[line][column]) <<= val; } else {  (data[column][line]) <<= (val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( line>=column ) { (data[line][column]) >>= val; } else {  (data[column][line]) >>= (val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( line>=column ) { (data[line][column]) = val; } else {  (data[column][line]) = (val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,Sym<sr,1>,SparseLine<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_cols> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_rows> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,Sym<sr,1>,SparseLine<Col> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,Sym<sr,1>,SparseLine<Col> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,Sym<sr,1>,SparseLine<Col> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if ( column>=line ) {return  (data[line][column]) ; } else { return  (data[column][line]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Sym<sr,1>,SparseLine<Col>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Sym<sr,1>,SparseLine<Col>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Sym<sr,1>::need_upper and Sym<sr,1>::need_lower)==false and Sym<sr,1>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Sym<sr,1>::need_upper and Sym<sr,1>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nr);
        for(unsigned i=0;i<nr;++i)
            data[i].resize(nc);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Sym<sr,1>,SparseLine<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Sym<sr,1>,SparseLine<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Sym<sr,1>,SparseLine<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Sym<sr,1>,SparseLine<Col>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,Sym<sr,1>,SparseLine<Col> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if ( column>=line ) {return  (data[line][column]) ; } else { return  (data[column][line]) ;}; }
    T0 conv() const { if ( column>=line ) {return  (data[line][column]) ; } else { return  (data[column][line]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( column>=line ) { (data[line][column]) += val; } else {  (data[column][line]) += (val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( column>=line ) { (data[line][column]) -= val; } else {  (data[column][line]) -= (val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( column>=line ) { (data[line][column]) *= val; } else {  (data[column][line]) *= (val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( column>=line ) { (data[line][column]) /= val; } else {  (data[column][line]) /= (val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( column>=line ) { (data[line][column]) %= val; } else {  (data[column][line]) %= (val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( column>=line ) { (data[line][column]) &= val; } else {  (data[column][line]) &= (val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( column>=line ) { (data[line][column]) |= val; } else {  (data[column][line]) |= (val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( column>=line ) { (data[line][column]) <<= val; } else {  (data[column][line]) <<= (val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( column>=line ) { (data[line][column]) >>= val; } else {  (data[column][line]) >>= (val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( column>=line ) { (data[line][column]) = val; } else {  (data[column][line]) = (val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,Sym<sr,0>,SparseLine<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_rows> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_cols> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,Sym<sr,0>,SparseLine<Row> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,Sym<sr,0>,SparseLine<Row> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,Sym<sr,0>,SparseLine<Row> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if ( line>=column ) {return  (data[column][line]) ; } else { return  (data[line][column]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Sym<sr,0>,SparseLine<Row>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Sym<sr,0>,SparseLine<Row>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Sym<sr,0>::need_upper and Sym<sr,0>::need_lower)==false and Sym<sr,0>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Sym<sr,0>::need_upper and Sym<sr,0>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nc);
        for(unsigned i=0;i<nc;++i)
            data[i].resize(nr);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Sym<sr,0>,SparseLine<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Sym<sr,0>,SparseLine<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Sym<sr,0>,SparseLine<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Sym<sr,0>,SparseLine<Row>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,Sym<sr,0>,SparseLine<Row> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if ( line>=column ) {return  (data[column][line]) ; } else { return  (data[line][column]) ;}; }
    T0 conv() const { if ( line>=column ) {return  (data[column][line]) ; } else { return  (data[line][column]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( line>=column ) { (data[column][line]) += val; } else {  (data[line][column]) += (val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( line>=column ) { (data[column][line]) -= val; } else {  (data[line][column]) -= (val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( line>=column ) { (data[column][line]) *= val; } else {  (data[line][column]) *= (val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( line>=column ) { (data[column][line]) /= val; } else {  (data[line][column]) /= (val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( line>=column ) { (data[column][line]) %= val; } else {  (data[line][column]) %= (val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( line>=column ) { (data[column][line]) &= val; } else {  (data[line][column]) &= (val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( line>=column ) { (data[column][line]) |= val; } else {  (data[line][column]) |= (val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( line>=column ) { (data[column][line]) <<= val; } else {  (data[line][column]) <<= (val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( line>=column ) { (data[column][line]) >>= val; } else {  (data[line][column]) >>= (val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( line>=column ) { (data[column][line]) = val; } else {  (data[line][column]) = (val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,Sym<sr,1>,SparseLine<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_rows> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_cols> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,Sym<sr,1>,SparseLine<Row> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,Sym<sr,1>,SparseLine<Row> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,Sym<sr,1>,SparseLine<Row> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if ( column>=line ) {return  (data[column][line]) ; } else { return  (data[line][column]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Sym<sr,1>,SparseLine<Row>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Sym<sr,1>,SparseLine<Row>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Sym<sr,1>::need_upper and Sym<sr,1>::need_lower)==false and Sym<sr,1>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Sym<sr,1>::need_upper and Sym<sr,1>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nc);
        for(unsigned i=0;i<nc;++i)
            data[i].resize(nr);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Sym<sr,1>,SparseLine<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Sym<sr,1>,SparseLine<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Sym<sr,1>,SparseLine<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Sym<sr,1>,SparseLine<Row>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,Sym<sr,1>,SparseLine<Row> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if ( column>=line ) {return  (data[column][line]) ; } else { return  (data[line][column]) ;}; }
    T0 conv() const { if ( column>=line ) {return  (data[column][line]) ; } else { return  (data[line][column]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( column>=line ) { (data[column][line]) += val; } else {  (data[line][column]) += (val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( column>=line ) { (data[column][line]) -= val; } else {  (data[line][column]) -= (val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( column>=line ) { (data[column][line]) *= val; } else {  (data[line][column]) *= (val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( column>=line ) { (data[column][line]) /= val; } else {  (data[line][column]) /= (val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( column>=line ) { (data[column][line]) %= val; } else {  (data[line][column]) %= (val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( column>=line ) { (data[column][line]) &= val; } else {  (data[line][column]) &= (val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( column>=line ) { (data[column][line]) |= val; } else {  (data[line][column]) |= (val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( column>=line ) { (data[column][line]) <<= val; } else {  (data[line][column]) <<= (val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( column>=line ) { (data[column][line]) >>= val; } else {  (data[line][column]) >>= (val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( column>=line ) { (data[column][line]) = val; } else {  (data[line][column]) = (val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,Herm<sr,0>,SparseLine<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_cols> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_rows> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,Herm<sr,0>,SparseLine<Col> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,Herm<sr,0>,SparseLine<Col> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,Herm<sr,0>,SparseLine<Col> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if ( line>=column ) {return  (data[line][column]) ; } else { return LMT::conj (data[column][line]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Herm<sr,0>,SparseLine<Col>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Herm<sr,0>,SparseLine<Col>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Herm<sr,0>::need_upper and Herm<sr,0>::need_lower)==false and Herm<sr,0>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Herm<sr,0>::need_upper and Herm<sr,0>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nr);
        for(unsigned i=0;i<nr;++i)
            data[i].resize(nc);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Herm<sr,0>,SparseLine<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Herm<sr,0>,SparseLine<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Herm<sr,0>,SparseLine<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Herm<sr,0>,SparseLine<Col>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,Herm<sr,0>,SparseLine<Col> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if ( line>=column ) {return  (data[line][column]) ; } else { return LMT::conj (data[column][line]) ;}; }
    T0 conv() const { if ( line>=column ) {return  (data[line][column]) ; } else { return LMT::conj (data[column][line]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( line>=column ) { (data[line][column]) += val; } else {  (data[column][line]) += LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( line>=column ) { (data[line][column]) -= val; } else {  (data[column][line]) -= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( line>=column ) { (data[line][column]) *= val; } else {  (data[column][line]) *= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( line>=column ) { (data[line][column]) /= val; } else {  (data[column][line]) /= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( line>=column ) { (data[line][column]) %= val; } else {  (data[column][line]) %= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( line>=column ) { (data[line][column]) &= val; } else {  (data[column][line]) &= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( line>=column ) { (data[line][column]) |= val; } else {  (data[column][line]) |= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( line>=column ) { (data[line][column]) <<= val; } else {  (data[column][line]) <<= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( line>=column ) { (data[line][column]) >>= val; } else {  (data[column][line]) >>= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( line>=column ) { (data[line][column]) = val; } else {  (data[column][line]) = LMT::conj(val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,Herm<sr,1>,SparseLine<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_cols> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_rows> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,Herm<sr,1>,SparseLine<Col> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,Herm<sr,1>,SparseLine<Col> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,Herm<sr,1>,SparseLine<Col> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if ( column>=line ) {return  (data[line][column]) ; } else { return LMT::conj (data[column][line]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Herm<sr,1>,SparseLine<Col>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Herm<sr,1>,SparseLine<Col>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Herm<sr,1>::need_upper and Herm<sr,1>::need_lower)==false and Herm<sr,1>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Herm<sr,1>::need_upper and Herm<sr,1>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nr);
        for(unsigned i=0;i<nr;++i)
            data[i].resize(nc);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Herm<sr,1>,SparseLine<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Herm<sr,1>,SparseLine<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Herm<sr,1>,SparseLine<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Herm<sr,1>,SparseLine<Col>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,Herm<sr,1>,SparseLine<Col> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if ( column>=line ) {return  (data[line][column]) ; } else { return LMT::conj (data[column][line]) ;}; }
    T0 conv() const { if ( column>=line ) {return  (data[line][column]) ; } else { return LMT::conj (data[column][line]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( column>=line ) { (data[line][column]) += val; } else {  (data[column][line]) += LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( column>=line ) { (data[line][column]) -= val; } else {  (data[column][line]) -= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( column>=line ) { (data[line][column]) *= val; } else {  (data[column][line]) *= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( column>=line ) { (data[line][column]) /= val; } else {  (data[column][line]) /= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( column>=line ) { (data[line][column]) %= val; } else {  (data[column][line]) %= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( column>=line ) { (data[line][column]) &= val; } else {  (data[column][line]) &= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( column>=line ) { (data[line][column]) |= val; } else {  (data[column][line]) |= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( column>=line ) { (data[line][column]) <<= val; } else {  (data[column][line]) <<= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( column>=line ) { (data[line][column]) >>= val; } else {  (data[column][line]) >>= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( column>=line ) { (data[line][column]) = val; } else {  (data[column][line]) = LMT::conj(val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,Herm<sr,0>,SparseLine<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_rows> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_cols> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,Herm<sr,0>,SparseLine<Row> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,Herm<sr,0>,SparseLine<Row> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,Herm<sr,0>,SparseLine<Row> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if ( line>=column ) {return  (data[column][line]) ; } else { return LMT::conj (data[line][column]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Herm<sr,0>,SparseLine<Row>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Herm<sr,0>,SparseLine<Row>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Herm<sr,0>::need_upper and Herm<sr,0>::need_lower)==false and Herm<sr,0>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Herm<sr,0>::need_upper and Herm<sr,0>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nc);
        for(unsigned i=0;i<nc;++i)
            data[i].resize(nr);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Herm<sr,0>,SparseLine<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Herm<sr,0>,SparseLine<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Herm<sr,0>,SparseLine<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Herm<sr,0>,SparseLine<Row>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,Herm<sr,0>,SparseLine<Row> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if ( line>=column ) {return  (data[column][line]) ; } else { return LMT::conj (data[line][column]) ;}; }
    T0 conv() const { if ( line>=column ) {return  (data[column][line]) ; } else { return LMT::conj (data[line][column]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( line>=column ) { (data[column][line]) += val; } else {  (data[line][column]) += LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( line>=column ) { (data[column][line]) -= val; } else {  (data[line][column]) -= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( line>=column ) { (data[column][line]) *= val; } else {  (data[line][column]) *= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( line>=column ) { (data[column][line]) /= val; } else {  (data[line][column]) /= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( line>=column ) { (data[column][line]) %= val; } else {  (data[line][column]) %= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( line>=column ) { (data[column][line]) &= val; } else {  (data[line][column]) &= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( line>=column ) { (data[column][line]) |= val; } else {  (data[line][column]) |= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( line>=column ) { (data[column][line]) <<= val; } else {  (data[line][column]) <<= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( line>=column ) { (data[column][line]) >>= val; } else {  (data[line][column]) >>= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( line>=column ) { (data[column][line]) = val; } else {  (data[line][column]) = LMT::conj(val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,Herm<sr,1>,SparseLine<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_rows> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_cols> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,Herm<sr,1>,SparseLine<Row> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,Herm<sr,1>,SparseLine<Row> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,Herm<sr,1>,SparseLine<Row> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if ( column>=line ) {return  (data[column][line]) ; } else { return LMT::conj (data[line][column]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Herm<sr,1>,SparseLine<Row>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Herm<sr,1>,SparseLine<Row>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Herm<sr,1>::need_upper and Herm<sr,1>::need_lower)==false and Herm<sr,1>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Herm<sr,1>::need_upper and Herm<sr,1>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nc);
        for(unsigned i=0;i<nc;++i)
            data[i].resize(nr);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Herm<sr,1>,SparseLine<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Herm<sr,1>,SparseLine<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Herm<sr,1>,SparseLine<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Herm<sr,1>,SparseLine<Row>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,Herm<sr,1>,SparseLine<Row> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if ( column>=line ) {return  (data[column][line]) ; } else { return LMT::conj (data[line][column]) ;}; }
    T0 conv() const { if ( column>=line ) {return  (data[column][line]) ; } else { return LMT::conj (data[line][column]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if ( column>=line ) { (data[column][line]) += val; } else {  (data[line][column]) += LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator-=(const T &val) { if ( column>=line ) { (data[column][line]) -= val; } else {  (data[line][column]) -= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator*=(const T &val) { if ( column>=line ) { (data[column][line]) *= val; } else {  (data[line][column]) *= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator/=(const T &val) { if ( column>=line ) { (data[column][line]) /= val; } else {  (data[line][column]) /= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator%=(const T &val) { if ( column>=line ) { (data[column][line]) %= val; } else {  (data[line][column]) %= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator&=(const T &val) { if ( column>=line ) { (data[column][line]) &= val; } else {  (data[line][column]) &= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator|=(const T &val) { if ( column>=line ) { (data[column][line]) |= val; } else {  (data[line][column]) |= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if ( column>=line ) { (data[column][line]) <<= val; } else {  (data[line][column]) <<= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if ( column>=line ) { (data[column][line]) >>= val; } else {  (data[line][column]) >>= LMT::conj(val);}; return *this; }
    template<class T> MatElem &operator=(const T &val) { if ( column>=line ) { (data[column][line]) = val; } else {  (data[line][column]) = LMT::conj(val);}; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,AntiSym<sr,0>,SparseLine<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_cols> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_rows> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,AntiSym<sr,0>,SparseLine<Col> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,AntiSym<sr,0>,SparseLine<Col> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,AntiSym<sr,0>,SparseLine<Col> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if (line==column) return (T0)0; if ( line>=column ) {return  (data[line][column]) ; } else { return - (data[column][line]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,AntiSym<sr,0>,SparseLine<Col>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,AntiSym<sr,0>,SparseLine<Col>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (AntiSym<sr,0>::need_upper and AntiSym<sr,0>::need_lower)==false and AntiSym<sr,0>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (AntiSym<sr,0>::need_upper and AntiSym<sr,0>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nr);
        for(unsigned i=0;i<nr;++i)
            data[i].resize(nc);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,0>,SparseLine<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,0>,SparseLine<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,0>,SparseLine<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,0>,SparseLine<Col>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,AntiSym<sr,0>,SparseLine<Col> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if (line==column) return (T0)0; if ( line>=column ) {return  (data[line][column]) ; } else { return - (data[column][line]) ;}; }
    T0 conv() const { if (line==column) return (T0)0; if ( line>=column ) {return  (data[line][column]) ; } else { return - (data[column][line]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line!=column) { if ( line>=column ) { (data[line][column]) += val; } else {  (data[column][line]) += -(val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line!=column) { if ( line>=column ) { (data[line][column]) -= val; } else {  (data[column][line]) -= -(val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line!=column) { if ( line>=column ) { (data[line][column]) *= val; } else {  (data[column][line]) *= -(val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line!=column) { if ( line>=column ) { (data[line][column]) /= val; } else {  (data[column][line]) /= -(val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line!=column) { if ( line>=column ) { (data[line][column]) %= val; } else {  (data[column][line]) %= -(val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line!=column) { if ( line>=column ) { (data[line][column]) &= val; } else {  (data[column][line]) &= -(val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line!=column) { if ( line>=column ) { (data[line][column]) |= val; } else {  (data[column][line]) |= -(val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line!=column) { if ( line>=column ) { (data[line][column]) <<= val; } else {  (data[column][line]) <<= -(val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line!=column) { if ( line>=column ) { (data[line][column]) >>= val; } else {  (data[column][line]) >>= -(val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line!=column) { if ( line>=column ) { (data[line][column]) = val; } else {  (data[column][line]) = -(val);}; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,AntiSym<sr,1>,SparseLine<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_cols> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_rows> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,AntiSym<sr,1>,SparseLine<Col> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,AntiSym<sr,1>,SparseLine<Col> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,AntiSym<sr,1>,SparseLine<Col> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if (line==column) return (T0)0; if ( column>=line ) {return  (data[line][column]) ; } else { return - (data[column][line]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,AntiSym<sr,1>,SparseLine<Col>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,AntiSym<sr,1>,SparseLine<Col>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (AntiSym<sr,1>::need_upper and AntiSym<sr,1>::need_lower)==false and AntiSym<sr,1>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (AntiSym<sr,1>::need_upper and AntiSym<sr,1>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nr);
        for(unsigned i=0;i<nr;++i)
            data[i].resize(nc);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,1>,SparseLine<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,1>,SparseLine<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,1>,SparseLine<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,1>,SparseLine<Col>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,AntiSym<sr,1>,SparseLine<Col> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if (line==column) return (T0)0; if ( column>=line ) {return  (data[line][column]) ; } else { return - (data[column][line]) ;}; }
    T0 conv() const { if (line==column) return (T0)0; if ( column>=line ) {return  (data[line][column]) ; } else { return - (data[column][line]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line!=column) { if ( column>=line ) { (data[line][column]) += val; } else {  (data[column][line]) += -(val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line!=column) { if ( column>=line ) { (data[line][column]) -= val; } else {  (data[column][line]) -= -(val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line!=column) { if ( column>=line ) { (data[line][column]) *= val; } else {  (data[column][line]) *= -(val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line!=column) { if ( column>=line ) { (data[line][column]) /= val; } else {  (data[column][line]) /= -(val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line!=column) { if ( column>=line ) { (data[line][column]) %= val; } else {  (data[column][line]) %= -(val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line!=column) { if ( column>=line ) { (data[line][column]) &= val; } else {  (data[column][line]) &= -(val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line!=column) { if ( column>=line ) { (data[line][column]) |= val; } else {  (data[column][line]) |= -(val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line!=column) { if ( column>=line ) { (data[line][column]) <<= val; } else {  (data[column][line]) <<= -(val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line!=column) { if ( column>=line ) { (data[line][column]) >>= val; } else {  (data[column][line]) >>= -(val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line!=column) { if ( column>=line ) { (data[line][column]) = val; } else {  (data[column][line]) = -(val);}; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,AntiSym<sr,0>,SparseLine<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_rows> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_cols> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,AntiSym<sr,0>,SparseLine<Row> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,AntiSym<sr,0>,SparseLine<Row> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,AntiSym<sr,0>,SparseLine<Row> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if (line==column) return (T0)0; if ( line>=column ) {return  (data[column][line]) ; } else { return - (data[line][column]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,AntiSym<sr,0>,SparseLine<Row>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,AntiSym<sr,0>,SparseLine<Row>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (AntiSym<sr,0>::need_upper and AntiSym<sr,0>::need_lower)==false and AntiSym<sr,0>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (AntiSym<sr,0>::need_upper and AntiSym<sr,0>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nc);
        for(unsigned i=0;i<nc;++i)
            data[i].resize(nr);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,0>,SparseLine<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,0>,SparseLine<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,0>,SparseLine<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,0>,SparseLine<Row>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,AntiSym<sr,0>,SparseLine<Row> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if (line==column) return (T0)0; if ( line>=column ) {return  (data[column][line]) ; } else { return - (data[line][column]) ;}; }
    T0 conv() const { if (line==column) return (T0)0; if ( line>=column ) {return  (data[column][line]) ; } else { return - (data[line][column]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line!=column) { if ( line>=column ) { (data[column][line]) += val; } else {  (data[line][column]) += -(val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line!=column) { if ( line>=column ) { (data[column][line]) -= val; } else {  (data[line][column]) -= -(val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line!=column) { if ( line>=column ) { (data[column][line]) *= val; } else {  (data[line][column]) *= -(val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line!=column) { if ( line>=column ) { (data[column][line]) /= val; } else {  (data[line][column]) /= -(val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line!=column) { if ( line>=column ) { (data[column][line]) %= val; } else {  (data[line][column]) %= -(val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line!=column) { if ( line>=column ) { (data[column][line]) &= val; } else {  (data[line][column]) &= -(val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line!=column) { if ( line>=column ) { (data[column][line]) |= val; } else {  (data[line][column]) |= -(val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line!=column) { if ( line>=column ) { (data[column][line]) <<= val; } else {  (data[line][column]) <<= -(val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line!=column) { if ( line>=column ) { (data[column][line]) >>= val; } else {  (data[line][column]) >>= -(val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line!=column) { if ( line>=column ) { (data[column][line]) = val; } else {  (data[line][column]) = -(val);}; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr>
class Mat<TT,AntiSym<sr,1>,SparseLine<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 );
    static const int static_rows = sr;
    static const int static_cols = sr;
    typedef Vec<Sparse<TT>,static_rows> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_cols> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,AntiSym<sr,1>,SparseLine<Row> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,AntiSym<sr,1>,SparseLine<Row> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,AntiSym<sr,1>,SparseLine<Row> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if (line==column) return (T0)0; if ( column>=line ) {return  (data[column][line]) ; } else { return - (data[line][column]) ;}; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nr.val; }
    unsigned size() const { return nr.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,AntiSym<sr,1>,SparseLine<Row>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,AntiSym<sr,1>,SparseLine<Row>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (AntiSym<sr,1>::need_upper and AntiSym<sr,1>::need_lower)==false and AntiSym<sr,1>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (AntiSym<sr,1>::need_upper and AntiSym<sr,1>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); 
        data.resize(nc);
        for(unsigned i=0;i<nc;++i)
            data[i].resize(nr);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,1>,SparseLine<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,AntiSym<sr,1>,SparseLine<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,1>,SparseLine<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,AntiSym<sr,1>,SparseLine<Row>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
};

template<class TV,int sr>
struct MatElem<TV,AntiSym<sr,1>,SparseLine<Row> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if (line==column) return (T0)0; if ( column>=line ) {return  (data[column][line]) ; } else { return - (data[line][column]) ;}; }
    T0 conv() const { if (line==column) return (T0)0; if ( column>=line ) {return  (data[column][line]) ; } else { return - (data[line][column]) ;}; }
    template<class T> MatElem &operator+=(const T &val) { if (line!=column) { if ( column>=line ) { (data[column][line]) += val; } else {  (data[line][column]) += -(val);}; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line!=column) { if ( column>=line ) { (data[column][line]) -= val; } else {  (data[line][column]) -= -(val);}; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line!=column) { if ( column>=line ) { (data[column][line]) *= val; } else {  (data[line][column]) *= -(val);}; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line!=column) { if ( column>=line ) { (data[column][line]) /= val; } else {  (data[line][column]) /= -(val);}; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line!=column) { if ( column>=line ) { (data[column][line]) %= val; } else {  (data[line][column]) %= -(val);}; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line!=column) { if ( column>=line ) { (data[column][line]) &= val; } else {  (data[line][column]) &= -(val);}; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line!=column) { if ( column>=line ) { (data[column][line]) |= val; } else {  (data[line][column]) |= -(val);}; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line!=column) { if ( column>=line ) { (data[column][line]) <<= val; } else {  (data[line][column]) <<= -(val);}; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line!=column) { if ( column>=line ) { (data[column][line]) >>= val; } else {  (data[line][column]) >>= -(val);}; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line!=column) { if ( column>=line ) { (data[column][line]) = val; } else {  (data[line][column]) = -(val);}; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr,int sc>
class Mat<TT,TriUpper<sr,sc>,SparseLine<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    typedef Vec<Sparse<TT>,static_cols> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_rows> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,TriUpper<sr,sc>,SparseLine<Col> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,TriUpper<sr,sc>,SparseLine<Col> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,TriUpper<sr,sc>,SparseLine<Col> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if (line>column) return (T0)0; return data[line][column]; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,TriUpper<sr,sc>,SparseLine<Col>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,TriUpper<sr,sc>,SparseLine<Col>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (TriUpper<sr,sc>::need_upper and TriUpper<sr,sc>::need_lower)==false and TriUpper<sr,sc>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (TriUpper<sr,sc>::need_upper and TriUpper<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); this->nc.set(nc);
        data.resize(nr);
        for(unsigned i=0;i<nr;++i)
            data[i].resize(nc);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,TriUpper<sr,sc>,SparseLine<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,TriUpper<sr,sc>,SparseLine<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,TriUpper<sr,sc>,SparseLine<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,TriUpper<sr,sc>,SparseLine<Col>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};

template<class TV,int sr,int sc>
struct MatElem<TV,TriUpper<sr,sc>,SparseLine<Col> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if (line>column) return (T0)0; return data[line][column]; }
    T0 conv() const { if (line>column) return (T0)0; return data[line][column]; }
    template<class T> MatElem &operator+=(const T &val) { if (line<=column) { data[line][column] += val; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line<=column) { data[line][column] -= val; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line<=column) { data[line][column] *= val; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line<=column) { data[line][column] /= val; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line<=column) { data[line][column] %= val; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line<=column) { data[line][column] &= val; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line<=column) { data[line][column] |= val; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line<=column) { data[line][column] <<= val; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line<=column) { data[line][column] >>= val; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line<=column) { data[line][column] = val; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr,int sc>
class Mat<TT,TriUpper<sr,sc>,SparseLine<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    typedef Vec<Sparse<TT>,static_rows> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_cols> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,TriUpper<sr,sc>,SparseLine<Row> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,TriUpper<sr,sc>,SparseLine<Row> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,TriUpper<sr,sc>,SparseLine<Row> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if (line>column) return (T0)0; return data[column][line]; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,TriUpper<sr,sc>,SparseLine<Row>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,TriUpper<sr,sc>,SparseLine<Row>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (TriUpper<sr,sc>::need_upper and TriUpper<sr,sc>::need_lower)==false and TriUpper<sr,sc>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (TriUpper<sr,sc>::need_upper and TriUpper<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); this->nc.set(nc);
        data.resize(nc);
        for(unsigned i=0;i<nc;++i)
            data[i].resize(nr);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,TriUpper<sr,sc>,SparseLine<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,TriUpper<sr,sc>,SparseLine<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,TriUpper<sr,sc>,SparseLine<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,TriUpper<sr,sc>,SparseLine<Row>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};

template<class TV,int sr,int sc>
struct MatElem<TV,TriUpper<sr,sc>,SparseLine<Row> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if (line>column) return (T0)0; return data[column][line]; }
    T0 conv() const { if (line>column) return (T0)0; return data[column][line]; }
    template<class T> MatElem &operator+=(const T &val) { if (line<=column) { data[column][line] += val; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line<=column) { data[column][line] -= val; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line<=column) { data[column][line] *= val; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line<=column) { data[column][line] /= val; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line<=column) { data[column][line] %= val; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line<=column) { data[column][line] &= val; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line<=column) { data[column][line] |= val; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line<=column) { data[column][line] <<= val; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line<=column) { data[column][line] >>= val; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line<=column) { data[column][line] = val; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr,int sc>
class Mat<TT,TriLower<sr,sc>,SparseLine<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    typedef Vec<Sparse<TT>,static_cols> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_rows> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,TriLower<sr,sc>,SparseLine<Col> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,TriLower<sr,sc>,SparseLine<Col> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,TriLower<sr,sc>,SparseLine<Col> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if (line<column) return (T0)0; return data[line][column]; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,TriLower<sr,sc>,SparseLine<Col>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,TriLower<sr,sc>,SparseLine<Col>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (TriLower<sr,sc>::need_upper and TriLower<sr,sc>::need_lower)==false and TriLower<sr,sc>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (TriLower<sr,sc>::need_upper and TriLower<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); this->nc.set(nc);
        data.resize(nr);
        for(unsigned i=0;i<nr;++i)
            data[i].resize(nc);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,TriLower<sr,sc>,SparseLine<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,TriLower<sr,sc>,SparseLine<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,TriLower<sr,sc>,SparseLine<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,TriLower<sr,sc>,SparseLine<Col>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};

template<class TV,int sr,int sc>
struct MatElem<TV,TriLower<sr,sc>,SparseLine<Col> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if (line<column) return (T0)0; return data[line][column]; }
    T0 conv() const { if (line<column) return (T0)0; return data[line][column]; }
    template<class T> MatElem &operator+=(const T &val) { if (line>=column) { data[line][column] += val; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line>=column) { data[line][column] -= val; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line>=column) { data[line][column] *= val; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line>=column) { data[line][column] /= val; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line>=column) { data[line][column] %= val; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line>=column) { data[line][column] &= val; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line>=column) { data[line][column] |= val; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line>=column) { data[line][column] <<= val; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line>=column) { data[line][column] >>= val; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line>=column) { data[line][column] = val; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr,int sc>
class Mat<TT,TriLower<sr,sc>,SparseLine<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    typedef Vec<Sparse<TT>,static_rows> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_cols> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,TriLower<sr,sc>,SparseLine<Row> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,TriLower<sr,sc>,SparseLine<Row> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,TriLower<sr,sc>,SparseLine<Row> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { if (line<column) return (T0)0; return data[column][line]; }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,TriLower<sr,sc>,SparseLine<Row>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,TriLower<sr,sc>,SparseLine<Row>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (TriLower<sr,sc>::need_upper and TriLower<sr,sc>::need_lower)==false and TriLower<sr,sc>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (TriLower<sr,sc>::need_upper and TriLower<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); this->nc.set(nc);
        data.resize(nc);
        for(unsigned i=0;i<nc;++i)
            data[i].resize(nr);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,TriLower<sr,sc>,SparseLine<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,TriLower<sr,sc>,SparseLine<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,TriLower<sr,sc>,SparseLine<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,TriLower<sr,sc>,SparseLine<Row>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};

template<class TV,int sr,int sc>
struct MatElem<TV,TriLower<sr,sc>,SparseLine<Row> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { if (line<column) return (T0)0; return data[column][line]; }
    T0 conv() const { if (line<column) return (T0)0; return data[column][line]; }
    template<class T> MatElem &operator+=(const T &val) { if (line>=column) { data[column][line] += val; } return *this; }
    template<class T> MatElem &operator-=(const T &val) { if (line>=column) { data[column][line] -= val; } return *this; }
    template<class T> MatElem &operator*=(const T &val) { if (line>=column) { data[column][line] *= val; } return *this; }
    template<class T> MatElem &operator/=(const T &val) { if (line>=column) { data[column][line] /= val; } return *this; }
    template<class T> MatElem &operator%=(const T &val) { if (line>=column) { data[column][line] %= val; } return *this; }
    template<class T> MatElem &operator&=(const T &val) { if (line>=column) { data[column][line] &= val; } return *this; }
    template<class T> MatElem &operator|=(const T &val) { if (line>=column) { data[column][line] |= val; } return *this; }
    template<class T> MatElem &operator<<=(const T &val) { if (line>=column) { data[column][line] <<= val; } return *this; }
    template<class T> MatElem &operator>>=(const T &val) { if (line>=column) { data[column][line] >>= val; } return *this; }
    template<class T> MatElem &operator=(const T &val) { if (line>=column) { data[column][line] = val; } return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr,int sc>
class Mat<TT,Diag<sr,sc>,SparseLine<Col>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    typedef Vec<Sparse<TT>,static_cols> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_rows> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,Diag<sr,sc>,SparseLine<Col> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,Diag<sr,sc>,SparseLine<Col> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,Diag<sr,sc>,SparseLine<Col> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { return (line==column ? (T0)data[line][column] : (T0)0 ); }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Diag<sr,sc>,SparseLine<Col>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Diag<sr,sc>,SparseLine<Col>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Diag<sr,sc>::need_upper and Diag<sr,sc>::need_lower)==false and Diag<sr,sc>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Diag<sr,sc>::need_upper and Diag<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); this->nc.set(nc);
        data.resize(nr);
        for(unsigned i=0;i<nr;++i)
            data[i].resize(nc);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Diag<sr,sc>,SparseLine<Col>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Diag<sr,sc>,SparseLine<Col>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Diag<sr,sc>,SparseLine<Col>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Diag<sr,sc>,SparseLine<Col>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};

template<class TV,int sr,int sc>
struct MatElem<TV,Diag<sr,sc>,SparseLine<Col> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { return (line==column ? (T0)data[line][column] : (T0)0 ); }
    T0 conv() const { return (line==column ? (T0)data[line][column] : (T0)0 ); }
    template<class T> MatElem &operator+=(const T &val) { DEBUGASSERT(line==column); data[line][column] += val; return *this; }
    template<class T> MatElem &operator-=(const T &val) { DEBUGASSERT(line==column); data[line][column] -= val; return *this; }
    template<class T> MatElem &operator*=(const T &val) { DEBUGASSERT(line==column); data[line][column] *= val; return *this; }
    template<class T> MatElem &operator/=(const T &val) { DEBUGASSERT(line==column); data[line][column] /= val; return *this; }
    template<class T> MatElem &operator%=(const T &val) { DEBUGASSERT(line==column); data[line][column] %= val; return *this; }
    template<class T> MatElem &operator&=(const T &val) { DEBUGASSERT(line==column); data[line][column] &= val; return *this; }
    template<class T> MatElem &operator|=(const T &val) { DEBUGASSERT(line==column); data[line][column] |= val; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { DEBUGASSERT(line==column); data[line][column] <<= val; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { DEBUGASSERT(line==column); data[line][column] >>= val; return *this; }
    template<class T> MatElem &operator=(const T &val) { DEBUGASSERT(line==column); data[line][column] = val; return *this; }
    TV &data;
    unsigned line,column;
};


template<class TT,int sr,int sc>
class Mat<TT,Diag<sr,sc>,SparseLine<Row>,void> {
public:
    static const bool fixed_size = ( sr>=0 && sc>=0 );
    static const int static_rows = sr;
    static const int static_cols = sc;
    typedef Vec<Sparse<TT>,static_rows> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef T T0;
    typedef Vec<TVI,static_cols> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    void clear_data_only() { for(unsigned i=0;i<data.size();++i) { data[i].data.set( 0 ); } } /// set all values to 0 but do not free indices

    
    typedef MatElem<TV,Diag<sr,sc>,SparseLine<Row> > RetOp;
    typedef T RetOpConst;

    MatElem<TV,Diag<sr,sc>,SparseLine<Row> > operator()(unsigned line,unsigned column) {
        return MatElem<TV,Diag<sr,sc>,SparseLine<Row> >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { return (line==column ? (T0)data[line][column] : (T0)0 ); }
    

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<class T2> Mat(const Mat<T2,Diag<sr,sc>,SparseLine<Row>,void> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }

    template<bool const_TM,class TVEC>
    Mat(const Mat<SubMat<Mat,const_TM,TVEC>,Diag<sr,sc>,SparseLine<Row>,int> &val) { // from SubMat
        resize( val.v.size(), val.v.size() );

        //
        std::map<int,int> val_set;
        for( unsigned i = 0; i < val.v.size(); ++i )
            val_set[ val.v[ i ] ] = i;

        //
        for( unsigned r = 0; r < data.size(); ++r ) {
            TVI &vec_sparse = val.m.val->data[ val.v[r] ];
            for( unsigned i = 0; i < vec_sparse.indices.size(); ++i )
                if ( val_set.count( vec_sparse.indices[i] ) )
                    operator()( r, val_set[ vec_sparse.indices[i] ] ) = vec_sparse.data[ i ];
        }
    }

    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (Diag<sr,sc>::need_upper and Diag<sr,sc>::need_lower)==false and Diag<sr,sc>::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (Diag<sr,sc>::need_upper and Diag<sr,sc>::need_lower)==false )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<nb_cols();++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
    }
    void allocate(const Vec<Vec<unsigned> > &v) {
        resize( v.size(), v.size() );
        for(unsigned i=0;i<nb_rows();++i) {
            data[i].indices = v[i];
            data[i].data.resize( v[i].size(), TT(0.0) );
        }
    }

    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); this->nc.set(nc);
        data.resize(nc);
        for(unsigned i=0;i<nc;++i)
            data[i].resize(nr);
    }
    void reserve(unsigned n) {
        for(unsigned i=0;i<nb_rows();++i)
            data[i].reserve(n);
    }

    void free() { resize(0); data.free(); }

    unsigned nb_nz() const {
        unsigned res = 0;
        for(unsigned i=0;i<data.size();++i)
            res += data[i].indices.size();
        return res;
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n> ) const {
        for(unsigned r=0;r<data.size();r+=n)
            sweep_by_rc_set( op, Number<n>(), r );
    }

    template<class Op,unsigned n>
    void sweep_by_rc_set( Op &op, Number<n>, unsigned r ) const {
        unsigned c[ n ];
        bool     v[ n ];
        // init
        for(unsigned i=0;i<n;++i) {
            v[i] = ( r+i < data.size() ? data[r+i].indices.size() : false );
            c[i] = 0;
        }
        // sweep
        while ( true ) {
            // min( ind )
            unsigned m = std::numeric_limits<unsigned>::max();
            for(unsigned i=0;i<n;++i)
                if ( v[i] )
                    m = min( m, data[r+i].indices[c[i]] );
            if ( m == std::numeric_limits<unsigned>::max() )
                return;
            //
            for(unsigned i=0;i<n;++i) {
                if ( v[i] and m == data[r+i].indices[c[i]] ) {
                    op( r+i, m, data[r+i].data[c[i]] );
                    v[ i ] = ++c[i] < data[r+i].indices.size();
                }
            }
        }
    }

    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,sr> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,sr> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,sc> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,sc> RetRow;

    // LINEVEC get_line() { return ; }
    Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)> diag() { return Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(sr,sc)>(*this); }
    Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)> diag() const { return Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(sr,sc)>(*this); }

    Vec<VecSubMat<Mat,false,ExtractRow>,sc> row(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractRow>,sc> row(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractRow>,sc>(*this,i); }
    Vec<VecSubMat<Mat,false,ExtractCol>,sr> col(unsigned i) { return Vec<VecSubMat<Mat,false,ExtractCol>,sr>(*this,i); }
    Vec<VecSubMat<Mat,true ,ExtractCol>,sr> col(unsigned i) const { return Vec<VecSubMat<Mat,true ,ExtractCol>,sr>(*this,i); }

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { for(unsigned r=0;r<data.size();++r) data[r].data /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Diag<sr,sc>,SparseLine<Row>,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,Diag<sr,sc>,SparseLine<Row>,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Diag<sr,sc>,SparseLine<Row>,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,Diag<sr,sc>,SparseLine<Row>,int>( *this, v );
    }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }

    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                return;
            }
        unsigned m=mxGetM(variable);
            unsigned n=mxGetN(variable);
            if ( fixed_size && ( static_rows!=m || static_cols!=n ) ) {
                printf("Size error");
                return;
            }

            resize( m, n );

            double *pr = mxGetPr(variable);
            int *irs = mxGetIr(variable); // vecteur des numeros de ligne taille nnz
            int *jcs = mxGetJc(variable); // vecteur de la taille n+1 contenant des pointeurs vers le 1er element non nul de irs ou point
            double *pi;
            if ( mxIsComplex(variable) )
                pi = mxGetPi(variable);
            for(unsigned c=0;c<n;++c) {
                // specif de la colonne de la matrice : c

                // reperage de la composante dans irs et valmat par JC[i];
                int rep=jcs[c];
                int nbelem=jcs[c+1]-jcs[c];
                for(unsigned l=0;l<nbelem;++l) {
                    unsigned indligne = irs[l+rep];
                    TT val = (TT)pr[l+rep];
                    data[ indligne ].indices.push_back( c );
                    data[ indligne ].data.push_back( val );

                    if ( mxIsComplex(variable) )
                        set_imag( data[ indligne ].data.back(), pi[l+rep] );
                }

            }


        } /// matlab -> LMT::Vec
    #endif


    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;
};

template<class TV,int sr,int sc>
struct MatElem<TV,Diag<sr,sc>,SparseLine<Row> > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    template<class T> operator T() const { return (line==column ? (T0)data[line][column] : (T0)0 ); }
    T0 conv() const { return (line==column ? (T0)data[line][column] : (T0)0 ); }
    template<class T> MatElem &operator+=(const T &val) { DEBUGASSERT(line==column); data[line][column] += val; return *this; }
    template<class T> MatElem &operator-=(const T &val) { DEBUGASSERT(line==column); data[line][column] -= val; return *this; }
    template<class T> MatElem &operator*=(const T &val) { DEBUGASSERT(line==column); data[line][column] *= val; return *this; }
    template<class T> MatElem &operator/=(const T &val) { DEBUGASSERT(line==column); data[line][column] /= val; return *this; }
    template<class T> MatElem &operator%=(const T &val) { DEBUGASSERT(line==column); data[line][column] %= val; return *this; }
    template<class T> MatElem &operator&=(const T &val) { DEBUGASSERT(line==column); data[line][column] &= val; return *this; }
    template<class T> MatElem &operator|=(const T &val) { DEBUGASSERT(line==column); data[line][column] |= val; return *this; }
    template<class T> MatElem &operator<<=(const T &val) { DEBUGASSERT(line==column); data[line][column] <<= val; return *this; }
    template<class T> MatElem &operator>>=(const T &val) { DEBUGASSERT(line==column); data[line][column] >>= val; return *this; }
    template<class T> MatElem &operator=(const T &val) { DEBUGASSERT(line==column); data[line][column] = val; return *this; }
    TV &data;
    unsigned line,column;
};


template<class T1,int s1,class T2,int s2,class T3,int s3> void partial_mul( const Mat<T1,Sym<s1>,SparseLine<> > &m, const Vec<T2,s2> &b, Vec<T3,s3> &res, unsigned num_thread, unsigned nb_threads ) {
    res.resize( m.nb_rows() );
    unsigned beg = m.nb_rows() * ( num_thread + 0 ) / nb_threads;
    unsigned end = m.nb_rows() * ( num_thread + 1 ) / nb_threads;
    for(unsigned i=beg;i<end;++i) {
        T3 r = T3(0.0);
        if ( m.data[i].indices.size() ) {
            unsigned j;
            for(j=0;j<m.data[i].indices.size()-1;++j) {
                r += m.data[i].data[j] * b[ m.data[i].indices[j] ];
                res[ m.data[i].indices[j] ] += m.data[i].data[j] * b[ i ];
            }
            r += m.data[i].data[j] * b[ m.data[i].indices[j] ];
        }
        res[i] = r;
    }
}

namespace LMT_PRIVATE {
struct PartialMul {
    template<class TM,class TV,class TR> void operator()( unsigned num_thread, const TM &m, const TV &v, TR &res ) const {
        partial_mul( m, v, res[num_thread], num_thread, nb_threads );
    }
    unsigned nb_threads;
};
}

template<class T1,int s1,class T2_,int s2> Vec<typename TypePromote<Multiplies,T1,T2_>::T,MAX(s1,s2)> mul( const Mat<T1,Sym<s1>,SparseLine<> > &m, const Vec<T2_,s2> &b, unsigned nb_threads ) {
    typedef typename TypePromote<Multiplies,T1,typename Vec<T2_,s2>::template SubType<0>::T>::T TR;
    Vec<Vec<TR,MAX(s1,s2)> > res; res.resize( nb_threads );
    LMT_PRIVATE::PartialMul pm; pm.nb_threads = nb_threads;
    apply_mt( range(nb_threads), nb_threads, pm, m, b, res );
    for(unsigned i=1;i<nb_threads;++i)
        res[0] += res[i];
    return res[0];
}


template<class T1,int s1,class T2_,int s2> Vec<typename TypePromote<Multiplies,T1,T2_>::T,MAX(s1,s2)> operator*( const Mat<T1,Sym<s1>,SparseLine<> > &m, const Vec<T2_,s2> &b ) {
    return mul( m, b, 1 );
}

#include "matsparseop.h"
} // namespace LMT
