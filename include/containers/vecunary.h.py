import string
lst = [
    'conj' ,
    'abs'  ,
    'acos' ,
    'asin' ,
    'atan' ,
    'cos'  ,
    'cosh' ,
    'exp'  ,
    'log'  ,
    'log10',
    'sin'  ,
    'sinh' ,
    'sqrt' ,
    'tan'  ,
    'tanh' ,
    'real' ,
    'imag' ,
]

print 'namespace LMT {'
for i in lst:
    I = string.capitalize(i)
    print '/** \\relates Vec */'
    print 'template<class T,int s>'
    print 'Vec<VecOp<'+I+',1,Vec<T,s>,true>,s> '+i+'(const Vec<T,s> &v) { return v; }'
 
print '};'
