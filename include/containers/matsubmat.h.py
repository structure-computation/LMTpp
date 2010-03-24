from string import *
from vecgenhelp import *
from matgenhelp import *

print """
namespace LMT {

/**
    op(mat1,mat2...)
*/
template<class TM,bool const_tm,class TV1,class TV2>
struct SubMat {};

template<class TM,bool const_tm,class TV1,class TV2> struct IsMatOp<SubMat<TM,const_tm,TV1,TV2> > { typedef int T; };

template<class TM,bool const_tm,class TV1,class Structure,class Storage>
class Mat<SubMat<TM,const_tm,TV1,void>,Structure,Storage,int> {
public:
    typedef typename TM::T T;
    
    Mat(const TM &mm,const TV1 &vv):v(vv) { m.val = &mm; }
    Mat(TM &mm,const TV1 &vv):v(vv) { m.val = &mm; }

    unsigned nb_rows() const { return v.size(); }
    unsigned nb_cols() const { return v.size(); }

    typedef typename TM::RetOp RetOp;
    typedef typename TM::RetOpConst RetOpConst;
    
    RetOpConst operator()(unsigned i,unsigned j) const { return (*m.val)( (unsigned)v[i], (unsigned)v[j] ); }
    RetOp operator()(unsigned i,unsigned j) { return (*m.val)( (unsigned)v[i], (unsigned)v[j] ); }

    template<class T2> Mat &operator+=(const T2 &val) { *this = *this + val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { *this = *this - val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { *this = *this / val; return *this; }

    template<class T2> Mat &operator=(const T2 &val) {
        for(unsigned i=0;i<v.size();++i)
            for(unsigned j=0;j<v.size();++j)
                (*m.val)( (unsigned)v[i], (unsigned)v[j] ) = val;
    }
    template<class T2,class STR2,class STO2> Mat &operator=(const Mat<T2,STR2,STO2> &val) {
        if ( (Structure::need_upper and Structure::need_lower)==false and Structure::need_diag )
            for(unsigned i=0;i<v.size();++i)
                for(unsigned j=0;j<=i;++j)
                    (*m.val)( (unsigned)v[i], (unsigned)v[j] ) = val(i,j);
        else if ( (Structure::need_upper and Structure::need_lower)==false )
            for(unsigned i=0;i<v.size();++i)
                for(unsigned j=0;j<i;++j)
                    (*m.val)( (unsigned)v[i], (unsigned)v[j] ) = val(i,j);
        else
            for(unsigned i=0;i<v.size();++i)
                for(unsigned j=0;j<v.size();++j)
                    (*m.val)( (unsigned)v[i], (unsigned)v[j] ) = val(i,j);
        return *this;
    }
    
"""+GETDRC+"""
    
    PtrConstIf<TM,const_tm> m;
    TV1 v;
};

template<class TM,bool const_tm,class TV1,class TV2,class Structure,class Storage>
class Mat<SubMat<TM,const_tm,TV1,TV2>,Structure,Storage,int> {
public:
    typedef typename TM::T T;
    
    Mat(const TM &mm,const TV1 &vv1,const TV2 &vv2):v1(vv1),v2(vv2) { m.val = &mm; }
    Mat(TM &mm,const TV1 &vv1,const TV2 &vv2):v1(vv1),v2(vv2) { m.val = &mm; }
    
    typedef typename TM::RetOp RetOp;
    typedef typename TM::RetOpConst RetOpConst;
    
    unsigned nb_rows() const { return v1.size(); }
    unsigned nb_cols() const { return v2.size(); }

    typename TM::RetOpConst operator()(unsigned i,unsigned j) const { return (*m.val)( (unsigned)v1[i], (unsigned)v2[j] ); }
    typename TM::RetOp operator()(unsigned i,unsigned j) { return (*m.val)( (unsigned)v1[i], (unsigned)v2[j] ); }

    template<class T2> Mat &operator+=(const T2 &val) { *this = *this + val; return *this; }
    template<class T2> Mat &operator-=(const T2 &val) { *this = *this - val; return *this; }
    template<class T2> Mat &operator*=(const T2 &val) { *this = *this * val; return *this; }
    template<class T2> Mat &operator/=(const T2 &val) { *this = *this / val; return *this; }

    template<class T2> Mat &operator=(const T2 &val) {
        for(unsigned i=0;i<v1.size();++i)
            for(unsigned j=0;j<v2.size();++j)
                (*m.val)( (unsigned)v1[i], (unsigned)v2[j] ) = val;
    }
    template<class T2,class STR2,class STO2> Mat &operator=(const Mat<T2,STR2,STO2> &val) {
        if ( (Structure::need_upper and Structure::need_lower)==false and Structure::need_diag )
            for(unsigned i=0;i<v1.size();++i)
                for(unsigned j=0;j<=i;++j)
                    (*m.val)( (unsigned)v1[i], (unsigned)v2[j] ) = val(i,j);
        else if ( (Structure::need_upper and Structure::need_lower)==false )
            for(unsigned i=0;i<v1.size();++i)
                for(unsigned j=0;j<i;++j)
                    (*m.val)( (unsigned)v1[i], (unsigned)v2[j] ) = val(i,j);
        else
            for(unsigned i=0;i<v1.size();++i)
                for(unsigned j=0;j<v2.size();++j)
                    (*m.val)( (unsigned)v1[i], (unsigned)v2[j] ) = val(i,j);
        return *this;
    }
    
"""+GETDRC+"""

    PtrConstIf<TM,const_tm> m;
    TV1 v1;
    TV2 v2;
};


} // namespace LMT
"""
