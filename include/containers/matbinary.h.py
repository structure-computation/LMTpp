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
]

print """
namespace LMT {
"""
for op,sop in lst1+lst2:
    if sop!="*" and sop!="/":
        print '/** \\relates Vec */'
        print 'template<class T1,class STR1,class STO1,class T2,class STR2,class STO2>'
        RV = 'Mat<MatOp< '+op+', 2,Mat<T1,STR1,STO1>,true,Mat<T2,STR2,STO2>,true> >'
        print RV+' '+'operator'*(sop[1:]!='in')+sop+'( const Mat<T1,STR1,STO1> &v1, const Mat<T2,STR2,STO2> &v2 ) {'
        print '    return '+RV+'( v1, v2 );'
        print '}'
        print ''
        print ''
    

    print '/** \\relates Vec */'
    print 'template<class T1,class STR1,class STO1,class T2>'
    RV = 'Mat<MatOp< '+op+', 2,Mat<T1,STR1,STO1>,true,Mat<VecCst<T2> >,false>,typename StructureTypeWithOp<STR1,'+op+'>::T,STO1 >'
    print RV+' '+'operator'*(sop[1:]!='in')+sop+'( const Mat<T1,STR1,STO1> &v1, const T2 &v2 ) {'
    print '    return '+RV+'( v1, Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ) );'
    print '}'
    print ''
    print ''
    
    print '/** \\relates Vec */'
    print 'template<class T1,class STR1,class STO1,class T2>'
    RV = 'Mat<MatOp< '+op+', 2, Mat<VecCst<T2> >,false,Mat<T1,STR1,STO1>,true >,typename StructureTypeWithOp<STR1,'+op+'>::T,STO1 >'
    print RV+' '+'operator'*(sop[1:]!='in')+sop+'( const T2 &v2, const Mat<T1,STR1,STO1> &v1 ) {'
    print '    return '+RV+'(Mat<VecCst<T2> >(v1.nb_rows(),v1.nb_cols(), Vec<VecCst<T2> >(v2,1) ), v1);'
    print '}'
    print ''
    print ''


print '};'
