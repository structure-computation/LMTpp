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
    print 'template<class T,class STR,class STO>'
    print 'Mat<MatOp<'+I+',1,Mat<T,STR,STO>,true>,STR,STO> '+i+'(const Mat<T,STR,STO> &v) { return v; }'
 
print '};'
