import string

structures = ''
functions = ''

for i in range(1,5):
    for ci in range(2**i):
        def Const(j): return ['const ',''][ ((2**j) & ci)/2**j ]
        tcl = string.join(['class T%s'%j for j in range(i)], ',')
        spe = string.join(['T%s'%j for j in range(i)], ',')
        args = string.join([Const(j)+'T%s &A%s'%(j,j) for j in range(i)], ',')
        constr = string.join(['a%s(A%s)'%(j,j) for j in range(i)], ',')
        struct = string.join([Const(j)+'T%s &a%s;'%(j,j) for j in range(i)], ' ')
        arc = string.join(['A%s'%j for j in range(i)], ',')
        
        namecl = 'ArgList'+str(i)+'_'+str(ci)
        
        structures += '/*!\n  \\internal\n */\n'
        structures += 'template<'+tcl+'> struct '+namecl+' { '+namecl+'('+args+'):'+constr+' {} '+struct+' };\n'
        
        functions += '/*!\n \\relates arglist\n  Convenience function to pass multiple parameters to apply\n \\internal\n */\n'
        functions += 'template<'+tcl+'> '+namecl+'<'+spe+'> arglist('+args+') { return '+namecl+'<'+spe+'>('+arc+'); }\n'
    
print '#ifndef LMT_arglist_HEADER'
print '#define LMT_arglist_HEADER'
print ''
print 'namespace LMT {'
print ''

print structures
print 
print functions

for i in range(2,5):
    for k in range(2**(i-1)):
        print '/*! \\relates arglist\n  Convenience function to pass multiple parameters to apply\n \\internal\n   */\n'
        tp  = string.join(['class T%i'%j for j in range(i)],',')
        ta  = string.join(['T%i'%j for j in range(i)],',')
        tab = string.join(['T%i'%j for j in range(i-1)],',')
        aa  = string.join(['al.a%i'%j for j in range(i-1)],',')
        print 'template<'+tp+'> ArgList'+str(i)+'_'+str(2*k)+'<'+ta+'> append_to_arglist(ArgList'+str(i-1)+'_'+str(k)+'<'+tab+'> al,const T'+str(i-1)+' &n) { return ArgList'+str(i)+'_'+str(k)+'<'+ta+'>('+aa+',n); }'
        print 'template<'+tp+'> ArgList'+str(i)+'_'+str(2*k+1)+'<'+ta+'> append_to_arglist(ArgList'+str(i-1)+'_'+str(k)+'<'+tab+'> al,      T'+str(i-1)+' &n) { return ArgList'+str(i)+'_'+str(k)+'<'+ta+'>('+aa+',n); }'


print '};'
print ''
print '#endif // LMT_arglist_HEADER'
