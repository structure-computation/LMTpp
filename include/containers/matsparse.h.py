from string import *
from matstructure import *

def rep(r,m):
    res = r
    for k,v in m.items():
        tmp = res
        res = replace(tmp,k,v)
    return res

print """// file generated from matsparse.h.py. Do not modify

namespace LMT {

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
    typedef Vec<Sparse<TT>,"""+['static_cols','static_rows'][row_oriented]+"""> TVI;
    typedef typename TVI::template SubType<0>::T T;
    typedef Vec<TVI,"""+['static_rows','static_cols'][row_oriented]+"""> TV;

    void clear() { for(unsigned i=0;i<data.size();++i) { data[i].indices.free(); data[i].data.free(); } } /// set all values to 0
    
    """ + (structure=='Gen') * ("""
    typedef DelayedAssignement<DelayedAssignementSparseSource<TT> > RetOp;
    typedef T RetOpConst;
    
    RetOp operator()(unsigned line,unsigned column) { return data["""+['line','column'][row_oriented]+"""]["""+['line','column'][1-row_oriented]+"""]; }
    RetOpConst operator()(unsigned line,unsigned column) const { return data["""+['line','column'][row_oriented]+"""]["""+['line','column'][1-row_oriented]+"""]; }
    """) + (structure!='Gen') * ("""
    typedef MatElem<TV,STRUCTURE,STORAGE > RetOp;
    typedef T RetOpConst;
    
    MatElem<TV,STRUCTURE,STORAGE > operator()(unsigned line,unsigned column) {
        return MatElem<TV,STRUCTURE,STORAGE >(data,line,column);
    }
    RetOpConst operator()(unsigned line,unsigned column) const { RDATALC }
    """) + """

    unsigned nb_rows() const { return nr.val; }
    unsigned nb_cols() const { return """+['nr','nc'][nsquare]+""".val; }"""+"""
    unsigned size() const { return nr.val; }"""*(1-nsquare)+"""

    Mat() {}
    Mat(unsigned nr) { resize(nr,nr); }
    Mat(unsigned nr,unsigned nc) { resize(nr,nc); }

    Mat(const Mat &val) {
        resize( val.nb_rows(), val.nb_cols() );
        data = val.data;
    }
    
    template<class T2,class STR2,class STO2,class O2> Mat(const Mat<T2,STR2,STO2,O2> &val) {
        resize( val.nb_rows(), val.nb_cols() );
        if ( (STRUCTURE::need_upper and STRUCTURE::need_lower)==false and STRUCTURE::need_diag )
            for(unsigned i=0;i<nb_rows();++i)
                for(unsigned j=0;j<=i;++j) {
                    if ( /*LMT::*/abs_indication( val(i,j) ) )
                        operator()(i,j) = val(i,j);
                }
        else if ( (STRUCTURE::need_upper and STRUCTURE::need_lower)==false )
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
            data[i].data.resize( v[i].size(), 0.0 );
        }
    }
    
    void resize(unsigned nr) { resize( nr, nr ); }
    void resize(unsigned nr,unsigned nc) { this->nr.set(nr); """+'this->nc.set(nc);'*nsquare+"""
        data.resize("""+['nr','nc'][row_oriented]+""");
        for(unsigned i=0;i<"""+['nr','nc'][row_oriented]+""";++i)
            data[i].resize("""+['nr','nc'][1-row_oriented]+""");
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

    template<class T2> Mat &operator*=(const T2 &val) {
        for(unsigned r=0;r<data.size();++r)
            for(unsigned i=0;i<data[r].data.size();++i)
                data[r].data[i] *= val;
        return *this;
    }
    template<class T2> Mat &operator/=(const T2 &val) { data /= val; return *this; }

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

    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) const {
        return Mat<SubMat<Mat,true ,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    template<class TVEC1,int s1,class TVEC2,int s2> Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > > operator()(const Vec<TVEC1,s1> &v1,const Vec<TVEC2,s2> &v2) {
        return Mat<SubMat<Mat,false,Vec<TVEC1,s1>,Vec<TVEC2,s2> > >( *this, v1, v2 );
    }
    
    #ifdef MATLAB_MEX_FILE
         Mat(const mxArray *variable) /*throw(std::runtime_error)*/ {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\\n" );
                return;
            }
            if ( ! mxIsSparse(variable) ) {
                printf( "TODO : Mat<Sparse<> > m( another kind of matrix ) from MATLAB. Please contact David Violeau.\\n" );
                return;
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
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
    StaticValIf<unsigned,sr>=0,(unsigned)sr> nr;"""+"""
    StaticValIf<unsigned,sc>=0,(unsigned)sc> nc;"""*nsquare+"""
};
""" + (structure!='Gen') * ("""
template<class TV,int sr"""+',int sc'*nsquare+""">
struct MatElem<TV,STRUCTURE,STORAGE > {
    MatElem(TV &mm,unsigned i,unsigned j):data(mm),line(i),column(j) {}
    template<class T> operator T() const { RDATALC }
    typedef typename TV::template SubType<0>::T::template SubType<0>::T T0;
    T0 conv() const { return T0( *this ); }
    """ + join(['template<class T> MatElem &operator'+op+'=(const T &val) { MATELEM'+op+' return *this; }' for op in lst_op],'\n    ') + """
    TV &data;
    unsigned line,column;
};
""")

            # RDATALC
            if structure!='Gen':
                if structure=='Diag':
                    res = replace(res,'RDATALC','return (line==column ? (T)data[line][column] : (T)0 );')
                    for op in lst_op:
                        res = replace(res,'MATELEM'+op,'DEBUGASSERT(line==column); data[line][column] '+op+'= val;')
                elif structure in ['Sym','Herm','TriUpper','TriLower','AntiSym']:
                    IN = 'PREFIX (data[I1][I2]) POSTFIX'
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
                        R1 = 'if (line>column) return (T)0; return data[%s][%s];' % ( ['line','column'][row_oriented], ['line','column'][1-row_oriented] )
                        R2 = 'if (line<=column) { data[%s][%s] OP= val; }' % ( ['line','column'][row_oriented], ['line','column'][1-row_oriented] )
                    if structure == 'TriLower':
                        R1 = 'if (line<column) return (T)0; return data[%s][%s];' % ( ['line','column'][row_oriented], ['line','column'][1-row_oriented] )
                        R2 = 'if (line>=column) { data[%s][%s] OP= val; }' % ( ['line','column'][row_oriented], ['line','column'][1-row_oriented] )
                
                    res = replace(res,'RDATALC',R1)
                    for op in lst_op:
                        res = replace(res,'MATELEM'+op,replace(R2,'OP',op))

            # get diag
            ret = 'Vec<VecSubMat<Mat,CST,ExtractDiag>,'+['sr','MIN(sr,sc)'][nsquare]+'>'
            res = replace(res,'CONSTRETDIAG' , replace(ret,'CST','true ') )
            res = replace(res,'RETDIAG'      , replace(ret,'CST','false') )
            res = replace(res,'CONSTFORMDIAG', replace(ret,'CST','true ')+'(*this)' )
            res = replace(res,'FORMDIAG'     , replace(ret,'CST','false')+'(*this)' )
                            
            # get row
            if orientation=='Col' and structure=='Gen':
                ret = 'Vec<Sparse<TT>,'+['sr','sc'][nsquare]+'> &'
                res = replace(res,'CONSTRETROW' , 'const '+ret )
                res = replace(res,'RETROW'      , ret )
                res = replace(res,'CONSTFORMROW', 'data[i]' )
                res = replace(res,'FORMROW'     , 'data[i]' )
            else:
                ret = 'Vec<VecSubMat<Mat,CST,ExtractRow>,'+['sr','sc'][nsquare]+'>'
                res = replace(res,'CONSTRETROW' , replace(ret,'CST','true ') )
                res = replace(res,'RETROW'      , replace(ret,'CST','false') )
                res = replace(res,'CONSTFORMROW', replace(ret,'CST','true ')+'(*this,i)' )
                res = replace(res,'FORMROW'     , replace(ret,'CST','false')+'(*this,i)' )
            # get col
            if orientation!='Col' and structure=='Gen':
                ret = 'Vec<Sparse<TT>,sr> &'
                res = replace(res,'CONSTRETCOL' , 'const '+ret )
                res = replace(res,'RETCOL'      , ret )
                res = replace(res,'CONSTFORMCOL', 'data[i]' )
                res = replace(res,'FORMCOL'     , 'data[i]' )
            else:
                ret = 'Vec<VecSubMat<Mat,CST,ExtractCol>,sr>'
                res = replace(res,'CONSTRETCOL' , replace(ret,'CST','true ') )
                res = replace(res,'RETCOL'      , replace(ret,'CST','false') )
                res = replace(res,'CONSTFORMCOL', replace(ret,'CST','true ')+'(*this,i)' )
                res = replace(res,'FORMCOL'     , replace(ret,'CST','false')+'(*this,i)' )

            # STRUCTURE STORAGE
            res = rep(res,{
                # structure storage
                'STRUCTURE'      : structure+'<sr'+',sc'*nsquare+(','+str(upper_part))*(1-nsquare)+'>',
                'STORAGE'        : 'SparseLine<'+orientation+'>',
            })

            print res


print """
template<class T1,int s1,class T2_,int s2> Vec<typename TypePromote<Multiplies,T1,typename Vec<T2_,s2>::template SubType<0>::T>::T,MAX(s1,s2)> operator*( const Mat<T1,Sym<s1>,SparseLine<> > &m, const Vec<T2_,s2> &b ) {
    typedef typename TypePromote<Multiplies,T1,typename Vec<T2_,s2>::template SubType<0>::T>::T TR;
    Vec<TR,MAX(s1,s2)> res; res.resize( m.nb_rows() );
    for(unsigned i=0;i<m.nb_rows();++i) {
        TR r = TR(0.0);
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
    return res;
}
"""

print '#include "matsparseop.h"'
print '} // namespace LMT'
