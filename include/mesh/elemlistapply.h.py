import string
from vecgenhelp import *

print 'namespace LMT {'

TP = ['class MeshCarac','class TNode','unsigned nvi_to_subs','unsigned skin']
TV = 'Vec<VecElemList<MeshCarac,TNode,nvi_to_subs,skin>,s,int>'
print_apply_ext('apply',TP,TV,'apply(v.hp,op,PARALIST);')
# beware : i will be number in sub_vec
print_apply_ext('apply_wi',TP,TV,'apply_wi(v.hp,op,PARALIST);')
print_apply_ext('find' ,TP,TV,'return find(v.hp,op,PARALIST);',ret='bool')
print_apply_ext('apply_range',TP,TV, 'apply_range(v.hp,from,to,op,PARALIST);', suppar=['int from','int to'] )
print_apply_ext('apply_simd',TP,TV,'apply_simd(v.hp,op,PARALIST);')
print_apply_ext('apply_simd_wi',TP,TV,'apply_simd_wi(v.hp,op,PARALIST);')

print_apply_ext('apply_mt',TP,TV,'apply_mt(v.hp,nb_threads,op,PARALIST);', suppar=['unsigned nb_threads'] )


print '} // namespace LMT'
