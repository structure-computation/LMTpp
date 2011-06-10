namespace LMT {

template<class TT,class CONJ=Function<C_1> > struct DelayedAssignementSkyLineSource {
    DelayedAssignementSkyLineSource(bool ok_,bool conj__,TT &val_):ok(ok_),conj_(conj__),val(val_) {}
    typedef TT T;
    TT get() const {
        if ( ok ) {
            if ( conj_ ) return c(val);
            return val;
        }
        return (TT)0;
    }
    template<class Op,class T2> void apply(const Op &op,const T2 &v) {
        if ( ok ) {
            if ( conj_ ) val = LMT::conj( op( LMT::conj(val), v ) );
            val = op( val, v );
        }
        else { /*DEBUGASSERT( op(0,v) == (TT)0 );*/ }
    }
    bool ok;
    bool conj_;
    TT &val;
    CONJ c;
};

template<class TT,class STR,class O>
class Mat<TT,STR,SkyLine<O>,void> {
public:
    static const int static_rows = STR::static_nb_rows;
    static const int static_cols = STR::static_nb_cols;
    static const bool fixed_size = ( static_rows>=0 && static_cols>=0 );
    static const bool col_oriented = O::col_oriented;
    static const int static_nb_vec = ( col_oriented ? static_rows : static_cols );
    static const unsigned alignement = ( static_nb_vec>=0 ? 1 : SimdSize<TT>::res );
    typedef TT T;
    typedef STR Structure;
    typedef SkyLine<O> Storage;

    
    Mat() {}
    Mat(unsigned nr,const Vec<unsigned> &bounds) {
        resize(nr,nr,bounds);
    } /// symmetric bounds
    Mat(unsigned nr,unsigned nc,const Vec<unsigned> &lbounds,const Vec<unsigned> &ubounds=Vec<unsigned>()) {
        resize(nr,nc,lbounds,ubounds);
    } /// if upper bounds is not specified, assume that matrix is symmetric. data in [l,u[ (closed-open)
    Mat(const Mat &m) {
        resize( m.nb_rows(), m.nb_cols(), m.lbounds, m.ubounds );
        values = m.values;
    }
    Mat &operator=(const Mat &m) {
        resize( m.nb_rows(), m.nb_cols(), m.lbounds, m.ubounds );
        values = m.values;
        return *this;
    }
    void resize(unsigned nnr,unsigned nnc,const Vec<unsigned> &lbounds_,const Vec<unsigned> &ubounds_=Vec<unsigned>()) {
        nr.set( nnr ); nc.set( nnc );
        unsigned nb_vec = ( col_oriented ? nnr : nnc );
        //lbounds.resize( nb_vec ); ubounds.resize( nb_vec );
        lbounds = lbounds_;
        if ( ubounds_.size() )
            ubounds = ubounds_;
        else
            ubounds = range( nb_vec ) + 1;
        DEBUGASSERT( lbounds.size() == nb_vec and ubounds.size() == nb_vec );
        
        cum_index.resize( nb_vec );
        unsigned nb_elems = 0;
        for(unsigned i=0;i<nb_vec;++i) {
            unsigned nl = lbounds[i];
            nl -= nl % alignement;
            unsigned nu = ubounds[i];
            nu += ((alignement-(nu%alignement))%alignement);
            nb_elems += nu-nl;
        }
        values.resize(nb_elems);
        
        nb_elems=0;
        for(unsigned i=0;i<nb_vec;++i) {
            unsigned nl = lbounds[i];
            nl -= nl % alignement;
            unsigned nu = ubounds[i];
            nu += ((alignement-(nu%alignement))%alignement);
            cum_index[i] = values.ptr() + (nb_elems-nl);
            nb_elems += nu-nl;
        }
    }
    
    void clear() { values.set(0); } /// set all values to 0
    void set(const T &v) { values.set(v); } /// set all values to 0
    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return nc.val; }
    

    Vec< TT > values;
    StaticValIf< unsigned, static_rows>=0, (unsigned)static_rows > nr;
    StaticValIf< unsigned, static_cols>=0, (unsigned)static_cols > nc;
    Vec< unsigned, static_nb_vec > lbounds;
    Vec< unsigned, static_nb_vec > ubounds;
    Vec< TT *, static_nb_vec > cum_index;
    
    
    typedef DelayedAssignement<DelayedAssignementSkyLineSource<TT> > RetOp;
    typedef T RetOpConst;
    RetOp operator()(unsigned line,unsigned column) {
        if ( col_oriented==false ) swap(line,column);
        
        bool c = false;
        if ( (AreSameType<STR,Sym<static_rows,true> >::res or AreSameType<STR,Herm<static_rows,true> >::res) and line > column ) { // stored in upper part 
            swap( line, column );
            c = true;
        }
        else if ( (AreSameType<STR,Sym<static_rows,false> >::res or AreSameType<STR,Herm<static_rows,false> >::res) and line < column ) { // stored in lower part
            swap( line, column );
            c = true;
        }
                    
        return RetOp( DelayedAssignementSkyLineSource<TT>(column >= lbounds[line] and column < ubounds[line], c, cum_index[line][column]) );
    }
    RetOpConst operator()(unsigned line,unsigned column) const {
        if ( col_oriented==false ) swap(line,column);
        
        bool c = false;
        if ( (AreSameType<STR,Sym<static_rows,true> >::res or AreSameType<STR,Herm<static_rows,true> >::res) and line > column ) { // stored in upper part
            swap( line, column );
            c = true;
        }
        else if ( (AreSameType<STR,Sym<static_rows,false> >::res or AreSameType<STR,Herm<static_rows,false> >::res) and line < column ) { // stored in lower part
            swap( line, column );
            c = true;
        }        
        if ( column < lbounds[line] or column >= ubounds[line] ) return 0;
        if (c) return LMT::conj( cum_index[line][column] );
        return cum_index[line][column];
    }

    
    typedef Vec<VecSubMat<Mat,false,ExtractDiag>,MIN(static_rows,static_cols)> RetDiag;
    typedef Vec<VecSubMat<Mat,true ,ExtractDiag>,MIN(static_rows,static_cols)> RetDiagConst;
    typedef Vec<VecSubMat<Mat,true ,ExtractCol>,static_rows> RetColConst;
    typedef Vec<VecSubMat<Mat,false,ExtractCol>,static_rows> RetCol;
    typedef Vec<VecSubMat<Mat,true ,ExtractRow>,static_cols> RetRowConst;
    typedef Vec<VecSubMat<Mat,false,ExtractRow>,static_cols> RetRow;
    
    RetDiag diag() { return RetDiag(*this); }
    RetDiagConst diag() const { return RetDiagConst(*this); }
    RetCol col(unsigned i) { return RetCol(*this,i); }
    RetColConst col(unsigned i) const { return RetColConst(*this,i); }
    RetRow row(unsigned i) { return RetRow(*this,i); }
    RetRowConst row(unsigned i) const { return RetRowConst(*this,i); }

    
    template<class T2> Mat &operator*=(const T2 &val) { values *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { values /= val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,Gen<static_rows,static_cols>,SparseLine<Col>,int> operator[](const TVEC &v) const { return Mat<SubMat<Mat,true ,TVEC>,STR,SparseLine<Col>,int>( *this, v ); }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,Gen<static_rows,static_cols>,SparseLine<Col>,int> operator[](const TVEC &v) { return Mat<SubMat<Mat,false,TVEC>,STR,SparseLine<Col>,int>( *this, v ); }

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const { return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 ); }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) { return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 ); }
    
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
                    values[ indligne ].indices.push_back( c );
                    values[ indligne ].data.push_back( val );
                    
                    if ( mxIsComplex(variable) )
                        set_imag( values[ indligne ].data.back(), pi[l+rep] );
                }
                    
            }
            
            
        } /// matlab -> LMT::Vec
    #endif
    
    void free() {
        resize(0);
        values.free();
        lbounds.free();
        ubounds.free();
        cum_index.free();
    }

};

}
