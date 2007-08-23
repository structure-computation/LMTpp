from string import *
from vecgenhelp import *
from matgenhelp import *

print """
namespace LMT {

/**
    op(mat1,mat2...)
*/
template<class Op,unsigned nb_v,class TM1,bool br1,class TM2=void,bool br2=true,class TM3=void,bool br3=true>
struct MatOp {};

template<class Op,unsigned nb_v,class TM1,bool br1,class TM2,bool br2,class TM3,bool br3> struct IsMatOp<MatOp<Op,nb_v,TM1,br1,TM2,br2,TM3,br3> > { typedef int T; };
"""
for nb_v in [1,2,3]:
    def J(s,sep=','): return join([s%{'i':i} for i in range(nb_v)],sep)
    print """
template<class Op,class TM0,bool br0,class TM1,bool br1,class TM2,bool br2,class Structure,class Storage>
class Mat<MatOp<Op,"""+str(nb_v)+""",TM0,br0,TM1,br1,TM2,br2>,Structure,Storage,int> {
public:
    Mat("""+J('const TM%(i)i &mm%(i)i')+"""):"""+J('m%(i)i(mm%(i)i)')+""" {}
    
    """+J('typedef typename TM%(i)i::T T%(i)i;','\n    ')+"""
    typedef typename Op::template ReturnType<"""+J('T%(i)i')+""">::T T;
    
    typedef T& RetOp;
    typedef T RetOpConst;
    
    unsigned nb_rows() const { return m0.val.nb_rows(); }
    unsigned nb_cols() const { return m0.val.nb_cols(); }

    T operator()(unsigned i,unsigned j) const { return op("""+J('m%(i)i.val(i,j)')+"""); }

"""+GETDRC+"""
    
    """+J('StoreByRefIf<TM%(i)i,br%(i)i> m%(i)i;','\n    ')+"""
    Op op;
};
"""

print """
} // namespace LMT
"""
