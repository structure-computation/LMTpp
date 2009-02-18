import string
lst=[
    'abs',
    'conj',
    'real',
    'imag',
]

print 'namespace LMT {\n'

for t in lst:
    T = string.capitalize(t)
    print 'template <int nd, int nx, class T>'
    print 'Pol<nd,nx,typename TypePromote<'+T+',T>::T> '+t+'(const Pol<nd,nx,T> &P) {'
    print '    return Pol<nd,nx,typename TypePromote<'+T+',T>::T>('+t+'(P.coefficients()));'
    print '}\n'

print 'template <int nd, int nx, class T>'
print 'typename TypePromote<Abs,T>::T abs_indication(const Pol<nd,nx,T> &P) {'
print '    return abs(P.coefficients()[0]);'
print '}\n'

print 'template <int nd, int nx, class T>'
print 'Pol<nd,nx,T> sqrt (const Pol<nd,nx,T> &P) {'
print '    assert(0);'
print '    /* TODO */'
print '}\n'

print '}'
