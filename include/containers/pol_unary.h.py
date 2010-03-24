import string

print 'namespace LMT {\n'

lst = [
    'abs',
    'conj',
    'real',
    'imag',
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
]

for t in lst:
    T = string.capitalize(t)
    print 'template <int nd, int nx, class T>'
    print 'Pol<nd,nx,typename TypePromote<'+T+',T>::T> '+t+'(const Pol<nd,nx,T> &p) {'
    print '    PolUnOp<'+T+',nd,nx> op;'
    print '    return Pol<nd,nx,typename TypePromote<'+T+',T>::T>( op(p.coefficients()) );'
    print '}\n'

print 'template <int nd, int nx, class T>'
print 'typename TypePromote<Abs,T>::T abs_indication(const Pol<nd,nx,T> &P) {'
print '    return abs(P.coefficients()[0]);'
print '}\n'

print '}'