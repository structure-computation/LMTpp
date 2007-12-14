from string import *
from vecgenhelp import *

print """
namespace LMT {
template<class Op,unsigned nb_v,class V1,bool br1,class V2=void,bool br2=true,class V3=void,bool br3=true> class VecOp {};

template<class Op,unsigned nb_v,class V1,bool br1,class V2,bool br2,class V3,bool br3> struct IsVecOp<VecOp<Op,nb_v,V1,br1,V2,br2,V3,br3> > { typedef int T; };

"""
for nb_par in [1,2,3]:
    lst_tpar = ['class OP']
    for i in range(nb_par): lst_tpar += ['class V%i'%i,'bool br%i'%i]
    lst_par = ['OP',str(nb_par)]
    for i in range(nb_par): lst_par += ['V%i'%i,'br%i'%i]

    VECOP = 'VecOp<'+join(lst_par,',')+'>'
    lstcond = ['VecSupportSIMD<V%i>::res'%i for i in range(nb_par)]

    def J(s,sep=','): return join([s%{'i':i} for i in range(nb_par)],sep)


    # the code     
    print 'template<'+join(lst_tpar,',')+',int static_size_> struct VecSupportSIMD<Vec<'+VECOP+',static_size_,int> > { static const unsigned res = OpSupportSIMD<OP>::res && '+join(lstcond,' && ')+'; };'

    size = 'v0.val.size()'

    print """
/// range
template<""" + join(lst_tpar,',') + """,int static_size_>
class Vec<VecOp<"""+join(lst_par,',')+""">,static_size_,int> {
public:
    template<unsigned n,unsigned inner=0> struct SubType {
        typedef typename TypePromote<OP,"""+J('typename V%(i)i::template SubType<n>::T')+""">::T T;
    };
    template<unsigned inner> struct SubType<1,inner> { typedef void T; };
    static const unsigned nb_sub_type = V0::nb_sub_type;
    typedef typename SubType<0>::T T0;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size>=0);
    static const int sparsity_rate = """+ [
        'ConserveZeroes<OP>::res * V0::sparsity_rate',
        '(ConserveZeroes<OP>::res==0) * MIN(V0::sparsity_rate,V1::sparsity_rate) + (ConserveZeroes<OP>::res==1) * MAX(V0::sparsity_rate,V1::sparsity_rate)',
        'MIN(V0::sparsity_rate,MIN(V1::sparsity_rate,V2::sparsity_rate))',
    ][nb_par-1] +""";
    
    int get_sparsity_rate() const { return sparsity_rate; }
    void resize(unsigned s) const { DEBUGASSERT( s == size() ); }
    
    Vec("""+J('const V%(i)i &vv%(i)i')+""",const OP &o=OP()):"""+J('v%(i)i(vv%(i)i)')+""",op(o) {}
    Vec("""+J('V%(i)i &vv%(i)i')+""",const OP &o=OP()):"""+J('v%(i)i(vv%(i)i)')+""",op(o) {}
    T0 operator[](unsigned i) const { return op("""+J('v%(i)i.val[i]')+"""); }
    T0 get(unsigned i) const { return op("""+J('v%(i)i.val[i]')+"""); }
    template<unsigned ne> SimdVec<T0,ne> simd(unsigned i,const Number<ne> &NE) const { return op("""+J('v%(i)i.val.simd(i,NE)')+"""); }
    
    unsigned size() const { return """+size+"""; }
"""+SELFOPC+"""
"""+GETRANGE+"""
"""+'    operator bool() const { return CastBool<OP>::cast_bool(*this,v0.val.size(),v1.val.size()); }'*(nb_par==2)+"""

private:
//    template<class Op> struct ApplyNZ2 {
//        ApplyNZ2() {  }
//        template<class T1,class T2> void operator()(const T1 &val,unsigned i) {
//        }
//        Op *op;
//        inc_index_access_const ind;
//    };

public:

    """+J('StoreByRefIf<V%(i)i,br%(i)i> v%(i)i;','\n    ')+"""
    OP op;
};

/** Ex : generate( """+J('v%(i)i',', ')+""", _1 * 2 ) ( which can be written v*2 ). Usefull to generate a Vec<VecOp,s> without worrying about typedef and so on
    \\relates Vec
*/
template<"""+J('class TT%(i)i,int s%(i)i')+""",class Op> Vec<VecOp<Op,"""+str(nb_par)+""","""+J('Vec<TT%(i)i,s%(i)i>,true')+"""> >
generate( """+J('const Vec<TT%(i)i,s%(i)i> &v%(i)i')+""",const Op &op ) {
    return Vec<VecOp<Op,"""+str(nb_par)+""","""+J('Vec<TT%(i)i,s%(i)i>,true')+"""> >("""+J('v%(i)i')+""",op);
}

"""

TT = ['class OP','class V0','bool const_v0']
TV = 'Vec<VecOp<OP,1,V0,const_v0>,s,int>'

print_apply_ext('apply',TT,TV,'apply(v.v0.val,ALGOCompose1WithoutReturn<Op,ONEIFCONSTOP,OP,true>(op,v.op),PARALIST);')
print_apply_ext('apply_wi',TT,TV,'OpWithIncrement<Op,ONEIFCONSTOP> opi(op); apply(v,opi,PARALIST);')


print """} // namespace LMT"""

