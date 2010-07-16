# -*- coding: utf-8 -*-
# operators
lst1 = [
    ('Plus','+'),
    ('Minus','-'),
    ('Modulus','%'),
    ('Multiplies','*'),
    ('Divides','/'),
    ('Equal','=='),
    ('NotEqual','!='),
    ('Less','<'),
    ('Greater','>'),
    ('LessEq','<='),
    ('GreaterEq','>='),
    ('And','&'),
    ('Or','|'),
    ('Xor','^'),
    ('AndAnd','&&'),
    ('OrOr','||'),
#     ('ShiftLeft','<<'),
#     ('ShiftRight','>>'),
]
# funtions
lst2 = [
    ('Min','min'),
    ('Max','max'),
    ('Pow','pow'),
]

print 'namespace LMT {'
for op,sop in lst1 + lst2:
    print '/*! \\relates Vec */'
    print 'template<class T1,int s1,class TO1,class T2,int s2,class TO2>'
    RV = 'Vec<VecOp<'+op+',2,Vec<T1,s1,TO1>,true,Vec<T2,s2,TO2>,true>,MAX(s1,s2)>'
    print RV+' '+'operator'*(sop!='min' and sop!='max' and sop!='pow')+sop+'( const Vec<T1,s1,TO1> &v1,const Vec<T2,s2,TO2> &v2 ) {'
    print '    VECASSERTSAMESIZE(v1,v2); return '+RV+'(v1,v2);'
    print '}'
    print '/*! \\relates Vec */'
    print 'template<class T1,int s1,class TO1,class T2>'
    RV = 'Vec<VecOp< '+op+', 2, Vec<T1,s1,TO1>,true,Vec<VecCst<T2>,s1>,false>,s1>'
    print RV+' '+'operator'*(sop!='min' and sop!='max' and sop!='pow')+sop+'( const Vec<T1,s1,TO1> &v1,const T2 &v2 ) {'
    print '    return '+RV+'(v1, Vec<VecCst<T2>,s1>(v2,v1.size()));'
    print '}'
    print '/*! \\relates Vec */'
    print 'template<class T1,int s1,class TO1,class T2>'
    RV = 'Vec<VecOp< '+op+', 2, Vec<VecCst<T2>,s1>,false,Vec<T1,s1,TO1>,true>,s1>'
    print RV+' '+'operator'*(sop!='min' and sop!='max' and sop!='pow')+sop+'( const T2 &v2, const Vec<T1,s1,TO1> &v1 ) {'
    print '    return '+RV+'(Vec<VecCst<T2>,s1>(v2,v1.size()), v1);'
    print '}'
    print ''
    print ''

print """
/*! 
    version pour puissance entière
    \relates Vec
*/
template<class T1,int s1,class TO1>
Vec<VecOp< Pow, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<int>,s1>,false>,s1> pow( const Vec<T1,s1,TO1> &v1, int v2 ) {
    return Vec<VecOp< Pow, 2, Vec<T1,s1,TO1>,true,Vec<VecCst<int>,s1>,false>,s1>(v1, Vec<VecCst<int>,s1>(v2,v1.size()));
}
"""
print '};'
