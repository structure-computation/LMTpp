import string
from vecgenhelp import *

print 'namespace LMT {'

TP = ['class TNode']

TV = 'Vec<VecNodeList<TNode,false>,s,int>'
print_apply_ext('apply',TP,TV,'apply(v.hp,op,PARALIST);')
print_apply_ext('find' ,TP,TV,'return find(v.hp,op,PARALIST);',ret='bool')
print_apply_ext('apply_range',TP,TV, 'apply_range(v.hp,from,to,op,PARALIST);', suppar=['int from','int to'] )

TV = 'Vec<VecNodeList<TNode,true>,s,int>'
print_apply_ext('apply',TP,TV,'apply_ptr(v.hp,op,PARALIST);')
print_apply_ext('find' ,TP,TV,'return find_ptr(v.hp,op,PARALIST);',ret='bool')
print_apply_ext('apply_range',TP,TV, 'apply_range_ptr(v.hp,from,to,op,PARALIST);', suppar=['int from','int to'] )


print '} // namespace LMT'
