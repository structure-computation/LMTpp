import string
from vecgenhelp import *

print """
namespace LMT {

struct ExtractDiag {};
struct ExtractRow {};
struct ExtractCol {};

/**
    TypeSubPart can be either Diag, Row or column
*/
template<class TM,bool const_tm,class TypeSubPart>
struct VecSubMat {};

template<class TM,bool const_tm,class TypeSubPart> struct IsVecOp<VecSubMat<TM,const_tm,TypeSubPart> > { typedef int T; };


"""
for typ,ntyp in zip(['ExtractDiag','ExtractRow','ExtractCol'],[0,1,2]):
    print """
template<class TM,bool const_tm,int static_size_>
class Vec<VecSubMat<TM,const_tm,"""+typ+""">,static_size_,int> {
public:
    typedef typename TM::T T0;
    template<unsigned n> struct SubType { typedef T0 T; };
    static const unsigned nb_sub_type = 1;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 0;

    typedef Vec& inc_index_access;
    typedef const Vec& inc_index_access_const;
    inc_index_access begin_inc_index_access() { return *this; } /// iter[i] gives the i-th element
    inc_index_access_const begin_inc_index_access_const() const { return *this; } /// iter[i] gives the i-th element
    
    Vec(const TM &mm"""+',unsigned nums'*(ntyp>0)+""") {
        m.val = &mm;
        """+'s = nums;'*(ntyp>0)+"""
    }
    Vec(TM &mm"""+',unsigned nums'*(ntyp>0)+""") {
        m.val = &mm;
        """+'s = nums;'*(ntyp>0)+"""
    }
    Vec( const Vec<VecSubMat<TM,false,"""+typ+""">,static_size_,int> &m2 ) { m.val=m2.m.val; """+'s = m2.s;'*(ntyp>0)+""" }
    
    
    unsigned size() const { return """+['min(m.val->nb_rows(),m.val->nb_cols())','m.val->nb_cols()','m.val->nb_rows()'][ntyp]+"""; }

    typename TM::RetOpConst operator[](unsigned i) const { return (*m.val)("""+[ 'i,i', 's,i', 'i,s' ][ntyp]+"""); }
    typename TM::RetOp operator[](unsigned i) { return (*m.val)("""+[ 'i,i', 's,i', 'i,s' ][ntyp]+"""); }
    // void set(unsigned i,const T &val) { (*m.val)("""+[ 'i,i', 's,i', 'i,s' ][ntyp]+""") = val; }
    
    Vec operator=(const Vec &v) { for(unsigned i=0;i<size();++i) operator[](i) = v[ i ]; return *this; }
    
    template<class T2> Vec operator=(const T2 &v) { for(unsigned i=0;i<size();++i) operator[](i) = v; return *this; }
    template<class T2,int s2,class IO> Vec operator=(const Vec<T2,s2,IO> &v) { for(unsigned i=0;i<size();++i) operator[](i) = v[i]; return *this; }

"""+SELFOP+"""
"""+GETRANGE+"""

    PtrConstIf<TM,const_tm> m;
    """+'unsigned s;'*(ntyp>0)+"""
};
"""


print """
} // namespace LMT
"""
