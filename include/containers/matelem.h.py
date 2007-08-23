import string

print """
//
// C++ Interface: matelem
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matelem_HEADER
#define LMT_matelem_HEADER

namespace LMT {

/**
*/
template<class TM,class Structure,class Storage,unsigned alignement=1,int nr=0>
struct MatElem;
"""
lst = [
    'conj' , 'abs' , 'acos' , 'asin' , 'atan' , 
    'cos'  , 'cosh' , 'exp'  , 'log'  , 'log10', 'sin'  , 'sinh' ,
    'sqrt' , 'tan'  , 'tanh' , 'real' , 'imag' ,
]
for i in lst:
    I = string.capitalize(i)
    print 'template<class TV,class Structure,class Storage,unsigned alignement,int nr>'
    print 'typename '+I+'::template ReturnType<typename TV::template SubType<0>::T>::T '+i+'(const MatElem<TV,Structure,Storage,alignement,nr> &me) {'
    print '    return '+i+'((typename TV::template SubType<0>::T)me);'
    print '}'

lst = [
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
]
for I,i in lst:
    print 'template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>'
    print 'typename '+I+'::template ReturnType<T1,typename MatElem<TV,Structure,Storage,alignement,nr>::T0>::T operator'+i+'(const T1 &v,const MatElem<TV,Structure,Storage,alignement,nr> &me) {'
    print '    return v '+i+' me.conv();'
    print '}'
    print 'template<class T1,class TV,class Structure,class Storage,unsigned alignement,int nr>'
    print 'typename '+I+'::template ReturnType<typename MatElem<TV,Structure,Storage,alignement,nr>::T0,T1>::T operator'+i+'(const MatElem<TV,Structure,Storage,alignement,nr> &me,const T1 &v) {'
    print '    return me.conv() '+i+' v;'
    print '}'
    print 'template<class TV1,class Structure1,class Storage1,unsigned alignement1,int nr1,class TV2,class Structure2,class Storage2,unsigned alignement2,int nr2>'
    print 'typename '+I+'::template ReturnType<typename MatElem<TV1,Structure1,Storage1,alignement1,nr1>::T0,typename MatElem<TV2,Structure2,Storage2,alignement2,nr2>::T0>::T operator'+i+'(const MatElem<TV1,Structure1,Storage1,alignement1,nr1> &m1,const MatElem<TV2,Structure2,Storage2,alignement2,nr2> &m2) {'
    print '    return m1.conv() '+i+' m2.conv();'
    print '}'
    
print """
};

#endif // LMT_matelem_HEADER

"""
