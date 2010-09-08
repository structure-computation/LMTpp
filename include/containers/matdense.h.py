from string import *
from matstructure import *

def rep(r,m):
    res = r
    for k,v in m.items():
        tmp = res
        res = replace(tmp,k,v)
    return res

print """// file generated from matdense.h.py. Do not modify

namespace LMT {

/**
    \relates Mat
    goal : display data on one line (to be redefined for matrices, ...)
*/
template<class T,class Structure,class O,class OP>
std::ostream &line_output( std::ostream &s, const Mat<T,Structure,Dense<O>,OP> &m ) {
    s << m.data;
    return s;
}
/**
    \relates Mat
    goal : get data from one line (to be redefined for matrices, ...)
*/
template<class T,class Structure,class O,class OP>
std::istream &line_input( std::istream &s, const Mat<T,Structure,Dense<O>,OP> &m ) {
    s >> m.data;
    return s;
}


"""


lst_op = ['+','-','*','/','%','&','|','<<','>>','']

for structure in ['Gen','Sym','Herm','AntiSym','TriUpper','TriLower','Diag']:
    nsquare = not (structure in ['Sym','Herm','AntiSym'])
    for orientation,row_oriented in zip(['Col','Row'],[0,1]):
        for upper_part in range(2-nsquare): # only if choice
            if nsquare and structure=='TriUpper':  upper_part=1
            res = """
template<class TT,int sr"""+',int sc'*nsquare+""">
class Mat<TT,STRUCTURE,STORAGE,void> {
public:
    static const bool fixed_size = ( sr>=0"""+' && sc>=0'*nsquare+""" );
    static const int static_rows = sr;
    static const int static_cols = """+['sr','sc'][nsquare]+""";
    static const int default_nb_rows = MAX( static_rows, 0 );
    static const int default_nb_cols = MAX( static_cols, 0 );
    static const int static_data_size = ( fixed_size ? STATICDATASIZE : -1 );
    typedef Vec<TT,static_data_size> TV;
    typedef typename TV::template SubType<0>::T T;
    static const unsigned alignement = ( fixed_size ? 1 : SimdSize<T>::res );

    #ifdef MATLAB_MEX_FILE
        Mat(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
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
                printf( "Error : LMT::Mat(mxArray *) need a Matrix\\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
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

    """ + (structure=='Gen') * """
    typedef T& RetOp;
    typedef const T& RetOpConst;

    T &operator()(unsigned line,unsigned column) { return data[ INDEX ]; }
    const T &operator()(unsigned line,unsigned column) const { return data[ INDEX ]; }
    """ + (structure!='Gen') * ("""
    typedef MatElem<TV,STRUCTURE,STORAGE,alignement"""+',sr'*(upper_part!=row_oriented)+"""> RetOp;
    typedef T RetOpConst;

    MatElem<TV,STRUCTURE,STORAGE,alignement"""+',sr'*(upper_part!=row_oriented)+"""> operator()(unsigned line,unsigned column) {
        return MatElem<TV,STRUCTURE,STORAGE,alignement"""+',sr'*(upper_part!=row_oriented)+""">(
            data,
            line,
            column
            """+',nr.val'*(upper_part!=row_oriented)+"""
            """+',off.val'*(upper_part!=row_oriented and structure!='Gen')+"""
        );
    }
    T operator()(unsigned line,unsigned column) const { RDATALC }
    """) + """

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return """+['nr','nc'][nsquare]+""".val; }"""+"""
    unsigned size() const { return nr.val; }"""*(1-nsquare)+"""

    Mat() {}
    explicit Mat(unsigned nr) { this->nr.set(default_nb_rows); """+"real_nr.set(default_nb_rows);"*(structure=='Gen')+(" this->nc.set(default_nb_cols); "+"real_nc.set(default_nb_cols);"*(structure=='Gen'))*nsquare+""" resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { this->nr.set(default_nb_rows); """+"real_nr.set(default_nb_rows);"*(structure=='Gen')+(" this->nc.set(default_nb_cols); "+"real_nc.set(default_nb_cols);"*(structure=='Gen'))*nsquare+""" resize(nr,nc); }
    Mat(unsigned nr,unsigned nc,const TT &val) { this->nr.set(default_nb_rows); """+"real_nr.set(default_nb_rows);"*(structure=='Gen')+(" this->nc.set(default_nb_cols); "+"real_nc.set(default_nb_cols);"*(structure=='Gen'))*nsquare+""" resize(nr,nc); set(val); }
    template<class T2,int s2> Mat(unsigned r,unsigned c,const Vec<T2,s2> &v):data(v) { this->nr.set(default_nb_rows); """+"real_nr.set(default_nb_rows);"*(structure=='Gen')+(" this->nc.set(default_nb_cols); "+"real_nc.set(default_nb_cols);"*(structure=='Gen'))*nsquare+""" resize(r,c); }

    /*template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        if ( fixed_size==false )
            resize( val.nb_rows(), val.nb_cols() );
        if ( STRUCTURE::need_diag and STRUCTURE::need_upper==false and STRUCTURE::need_lower==false )
            for(unsigned i=0;i<val.nb_rows();++i)
                operator()(i, i) = val(i, i);
        else if ( (STRUCTURE::need_upper and STRUCTURE::need_lower)==false and STRUCTURE::need_diag )
            for(unsigned i=0;i<val.nb_rows();++i)
                for(unsigned j=0;j<=i;++j)
                    operator()(i, j) = val(i, j);
        else if ( (STRUCTURE::need_upper and STRUCTURE::need_lower)==false )
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
    void resize(unsigned nr,unsigned nc) { SETDYNDATASIZE this->nr.set(nr); """+'this->nc.set(nc);'*nsquare+""" }

    typedef RETDIAG RetDiag;
    typedef CONSTRETDIAG RetDiagConst;
    typedef CONSTRETCOL RetColConst;
    typedef RETCOL RetCol;
    typedef CONSTRETROW RetRowConst;
    typedef RETROW RetRow;

    // LINEVEC get_line() { return ; }
    RETDIAG diag() { return FORMDIAG; }
    CONSTRETDIAG diag() const { return CONSTFORMDIAG; }

    RETROW row(unsigned i) { return FORMROW; }
    CONSTRETROW row(unsigned i) const { return CONSTFORMROW; }
    RETCOL col(unsigned i) { return FORMCOL; }
    CONSTRETCOL col(unsigned i) const { return CONSTFORMCOL; }

    template<class T2> void set(const T2 &v) { data.set(v); }

    //template<class T2> Mat(const T2 &val) { DEBUGASSERT(fixed_size==true); data = val; }

    //template<class T2> Mat &operator=(const T2 &val) { data.set((T)val); return *this; }
    Mat &operator=(int val) { data.set(val); return *this; }

    template<class T2> Mat &operator+=(const T2 &val) { data += val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { data -= val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { data *= val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

    template<class T2> Mat &operator+=(const Mat<T2,STRUCTURE,STORAGE > &val) { data += val.data; return *this; }
    template<class T2> Mat &operator-=(const Mat<T2,STRUCTURE,STORAGE > &val) { data -= val.data; return *this; }
    template<class T2> Mat &operator*=(const Mat<T2,STRUCTURE,STORAGE > &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const Mat<T2,STRUCTURE,STORAGE > &val) { *this = *this / val; return *this; }

    template<class T2,class STR2,class STO2> Mat &operator+=(const Mat<T2,STR2,STO2> &val) { *this = *this + val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator-=(const Mat<T2,STR2,STO2> &val) { *this = *this - val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator*=(const Mat<T2,STR2,STO2> &val) { *this = *this * val; return *this; }
    template<class T2,class STR2,class STO2> Mat &operator/=(const Mat<T2,STR2,STO2> &val) { *this = *this / val; return *this; }

    template<class TVEC> Mat<SubMat<Mat,true ,TVEC>,STRUCTURE,STORAGE,int> operator[](const TVEC &v) const {
        return Mat<SubMat<Mat,true ,TVEC>,STRUCTURE,STORAGE,int>( *this, v );
    }
    template<class TVEC> Mat<SubMat<Mat,false,TVEC>,STRUCTURE,STORAGE,int> operator[](const TVEC &v) {
        return Mat<SubMat<Mat,false,TVEC>,STRUCTURE,STORAGE,int>( *this, v );
    }

    void free() { resize(0,0); data.free(); } /// free data

    """+"""
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }"""*(structure=='Gen')+"""

    TV data;
private:
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;"""+"""
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;"""*nsquare+"""
    StaticValIf<unsigned,sr>=0,(unsigned)sr> real_nr;
    StaticValIf<unsigned,sc>=0,(unsigned)sc> real_nc;"""*(structure=='Gen')+("""
    StaticValIf<unsigned,sr>=0,(unsigned)STATICDATASIZE-1> off;
    """) * (upper_part!=row_oriented and structure!='Gen') + """
};
""" + (structure!='Gen') * ("""
template<class TV,int sr"""+',int sc'*nsquare+""",unsigned alignement,int nrs>
struct MatElem<TV,STRUCTURE,STORAGE,alignement,nrs> {
    MatElem(
        TV &mm,
        unsigned i,
        unsigned j
        """+',unsigned ssr'*(upper_part!=row_oriented)+"""
        """+',unsigned ova'*(upper_part!=row_oriented and structure!='Gen')+"""
    ):data(mm),line(i),column(j) {
        """+'nr.set(ssr);'*(upper_part!=row_oriented)+"""
        """+'off.set(ova);'*(upper_part!=row_oriented and structure!='Gen')+"""
    }
    typedef typename TV::template SubType<0>::T T0;
    const T0 &ptr() const { typedef T0 T; RDATALC }
    T0 &ptr() { typedef T0 T; RDATALC }
    template<class T> operator T() const { RDATALC }
    T0 conv() const { typedef T0 T; RDATALC }
    """ + join(['template<class T> MatElem &operator'+op+'=(const T &val) { MATELEM'+op+' return *this; }' for op in lst_op],'\n    ') + """
    TV &data;
    unsigned line,column;"""+"""
    StaticValIf<unsigned,nrs>=0,(unsigned)nrs> nr;"""*(upper_part!=row_oriented)+ ("""
    StaticValIf<unsigned,sr>=0,(unsigned)STATICDATASIZE-1> off;
    """) * (upper_part!=row_oriented and structure!='Gen') + """
};
""")

            # RDATALC
            if structure=='Gen':
                res = rep(res,{ 'INDEX' : ['line * real_nc.val + column','column * real_nr.val + line'][row_oriented] })
            else:
                if structure=='Diag':
                    res = replace(res,'RDATALC','return (line==column ? (T)data[line] : (T)0 );')
                    for op in lst_op:
                        res = replace(res,'MATELEM'+op,'DEBUGASSERT(line==column); data[line] '+op+'= val;')
                elif structure in ['Sym','Herm','TriUpper','TriLower','AntiSym']:
                    if upper_part==row_oriented:
                        IN = 'unsigned ri=I1/alignement; PREFIX (data[ri*(ri+1)/2*alignement*alignement + (I1 % alignement)*(ri+1)*alignement + I2]) POSTFIX'
                        if structure=='AntiSym': IN = replace(IN,'I1','(I1-1)')
                    else:
                        IN = ' unsigned i1=nr.val-I1-1,i2=nr.val-I2-1; unsigned ri=i1/alignement; ' + \
                             'PREFIX (data[ off.val - ri*(ri+1)/2*alignement*alignement - (i1 % alignement)*(ri+1)*alignement - i2 ]) POSTFIX'
                        if structure=='AntiSym': IN = replace(IN,'I1','(I1+1)')
                    I1 = ['line','column'][row_oriented]
                    I2 = ['line','column'][1-row_oriented]
                    IN1 = rep(IN, {'I2':I2, 'I1':I1} )
                    IN2 = rep(IN, {'I2':I1, 'I1':I2} )

                    I1 = ['line','column'][upper_part]
                    I2 = ['line','column'][1-upper_part]

                    CONJ = '-'*(structure=='AntiSym') + 'LMT::conj'*(structure=='Herm')
                    R1 = 'if ( '+I1+'>='+I2+' ) {' + rep( IN1, {'POSTFIX':';', 'PREFIX':'return '}) + ' } else { ' + rep( IN2, {'POSTFIX':';', 'PREFIX':'return '+CONJ} ) + '};'
                    R2 = 'if ( '+I1+'>='+I2+' ) {' + rep( IN1, {'POSTFIX':'OP= val;', 'PREFIX':''}) + ' } else { ' + rep( IN2, {'POSTFIX':'OP= '+CONJ+'(val);', 'PREFIX':''} ) + '};'
                    if structure == 'AntiSym':
                        R1 = 'if (line==column) return (T)0; ' + R1
                        R2 = 'if (line!=column) { ' + R2 + ' }'
                    if structure == 'TriUpper':
                        R1 = 'if (line>column) return (T)0; ' + R1
                        R2 = 'if (line<=column) { ' + R2 + ' }'
                    if structure == 'TriLower':
                        R1 = 'if (line<column) return (T)0; ' + R1
                        R2 = 'if (line>=column) { ' + R2 + ' }'

                    res = replace(res,'RDATALC',R1)
                    for op in lst_op:
                        res = replace(res,'MATELEM'+op,replace(R2,'OP',op))

            # get diag, rox and col
            if structure=='Diag':
                res = replace(res,'CONSTRETDIAG' ,'const TV &')
                res = replace(res,'RETDIAG'      ,'TV &')
                res = replace(res,'CONSTFORMDIAG','data')
                res = replace(res,'FORMDIAG'     ,'data')
            else:
                ret = 'Vec<VecSubMat<Mat,CST,ExtractDiag>,'+['sr','MIN(sr,sc)'][nsquare]+'>'
                res = replace(res,'CONSTRETDIAG' , replace(ret,'CST','true ') )
                res = replace(res,'RETDIAG'      , replace(ret,'CST','false') )
                res = replace(res,'CONSTFORMDIAG', replace(ret,'CST','true ')+'(*this)' )
                res = replace(res,'FORMDIAG'     , replace(ret,'CST','false')+'(*this)' )
            if structure=='Gen' and orientation=='Col':
                ret = 'Vec<Ref<T,CST>,'+['sr','sc'][nsquare]+'>'
                res = replace(res,'CONSTRETROW' , replace(ret,'CST','true ') )
                res = replace(res,'RETROW'      , replace(ret,'CST','false') )
                res = replace(res,'CONSTFORMROW', replace(ret,'CST','true ')+'(data.ptr()+real_nc.val*i,nc.val)' )
                res = replace(res,'FORMROW'     , replace(ret,'CST','false')+'(data.ptr()+real_nc.val*i,nc.val)' )
            else:
                ret = 'Vec<VecSubMat<Mat,CST,ExtractRow>,'+['sr','sc'][nsquare]+'>'
                res = replace(res,'CONSTRETROW' , replace(ret,'CST','true ') )
                res = replace(res,'RETROW'      , replace(ret,'CST','false') )
                res = replace(res,'CONSTFORMROW', replace(ret,'CST','true ')+'(*this,i)' )
                res = replace(res,'FORMROW'     , replace(ret,'CST','false')+'(*this,i)' )

            ret = 'Vec<VecSubMat<Mat,CST,ExtractCol>,'+['sr','sc'][nsquare]+'>'
            res = replace(res,'CONSTRETCOL' , replace(ret,'CST','true ') )
            res = replace(res,'RETCOL'      , replace(ret,'CST','false') )
            res = replace(res,'CONSTFORMCOL', replace(ret,'CST','true ')+'(*this,i)' )
            res = replace(res,'FORMCOL'     , replace(ret,'CST','false')+'(*this,i)' )

            # STRUCTURE STORAGE
            ab = { 'a' : ['r','c'][1-row_oriented], 'b' : ['r','c'][row_oriented] }
            mi = 'unsigned m%(a)s = min(n%(a)s,this->n%(a)s.val); unsigned m%(b)s = min(n%(b)s,this->n%(b)s.val); ' % ab
            RNR = ''
            if upper_part!=row_oriented and structure!='Gen':
                RNR = 'unsigned t=nr+alignement-1; off.set( res-1 );' # '+'-1'*(structure=='AntiSym')+'
            res = rep(res,{
                # structure storage
                'STRUCTURE'      : structure+'<sr'+',sc'*nsquare+(','+str(upper_part))*(1-nsquare)+'>',
                'STORAGE'        : 'Dense<'+orientation+'>',
                # static size
                'STATICDATASIZE' : 'sr*sc' * (structure=='Gen') + \
                                   'sr*(sr+1)/2' * (structure in ['Sym','Herm','TriUpper','TriLower']) + \
                                   '+(sr-MIN(sr,sc))*sc+(sc-MIN(sr,sc))*sr' * (structure in ['TriUpper','TriLower']) + \
                                   'MAX(0,sr*(sr-1)/2)' * ( structure=='AntiSym' ) + \
                                   'MIN(sr,sc)' * (structure=='Diag'),
                # static size
                'SETDYNDATASIZE' : (mi+'TV od = data; unsigned o_r = real_n%(a)s.val; unsigned r%(a)s=n%(a)s+alignement-1; r%(a)s-=r%(a)s %% alignement; real_n%(a)s.set(r%(a)s); real_n%(b)s.set(n%(b)s); data.resize(real_nr.val*real_nc.val); for(unsigned i=0;i<m%(b)s;++i) for(unsigned j=0;j<m%(a)s;++j) data[real_n%(a)s.val*i+j] = od[o_r*i+j];'%ab) * (structure=='Gen') + \
                                   ('unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; '+ \
                                    'unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res);'+RNR) * (structure in ['Sym','Herm','TriUpper','TriLower']
                                   ) + \
                                   ('nr-=(nr!=0); unsigned ri=nr/alignement; unsigned res=ri*(ri+1)/2*alignement*alignement+(nr % alignement)*(ri+1)*alignement; '+ \
                                    'unsigned o=nr+alignement-1; o-=o % alignement; res -= o-nr; data.resize(res);'+RNR) * ( structure=='AntiSym' ) + \
                                   ('data.resize(nr);') * (structure=='Diag'),
            })

            print res

print '} // namespace LMT'

