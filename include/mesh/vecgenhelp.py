import string

# -------
SELFOPC = """
    template<class T2> Vec &operator*=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Multiplies(),va); return *this; }
    template<class T2> Vec &operator/=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Divides   (),va); return *this; }
    template<class T2> Vec &operator%=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Modulus   (),va); return *this; }
    template<class T2> Vec &operator&=(const T2 &va) { apply_nz(*this,AssignSelfOp(),And       (),va); return *this; }
    
    template<class T2,int s2> Vec &operator*=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),Multiplies(),va); return *this; }
    template<class T2,int s2> Vec &operator/=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),Divides   (),va); return *this; }
    template<class T2,int s2> Vec &operator%=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),Modulus   (),va); return *this; }
    template<class T2,int s2> Vec &operator&=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),And       (),va); return *this; }
    """

SELFOP = """                                                          
    template<class T2> Vec &operator+=(const T2 &val) { apply( *this, AssignSelfOp(), Plus() , val ); return *this; }
    template<class T2> Vec &operator-=(const T2 &val) { apply( *this, AssignSelfOp(), Minus(), val ); return *this; }
    template<class T2> Vec &operator^=(const T2 &val) { apply( *this, AssignSelfOp(), Xor()  , val ); return *this; }
    template<class T2> Vec &operator|=(const T2 &val) { apply( *this, AssignSelfOp(), Or()   , val ); return *this; }

    template<class T2,int s2> Vec &operator+=(const Vec<T2,s2> &val) { apply_wi( *this, AssignSelfOp(), Plus() , val ); return *this; }
    template<class T2,int s2> Vec &operator-=(const Vec<T2,s2> &val) { apply_wi( *this, AssignSelfOp(), Minus(), val ); return *this; }
    template<class T2,int s2> Vec &operator^=(const Vec<T2,s2> &val) { apply_wi( *this, AssignSelfOp(), Xor()  , val ); return *this; }
    template<class T2,int s2> Vec &operator|=(const Vec<T2,s2> &val) { apply_wi( *this, AssignSelfOp(), Or()   , val ); return *this; }
    """ + SELFOPC

GETRANGE = """
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,true >,s2> operator[](const Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,true>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2> operator[](const Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2> operator[](Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2> operator[](Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2>(*this,v2); }
    """

# -------
def print_apply(name,code,ret='void',onlyforconstvec=False,onlyfornonconstvec=False,suppar=[]):
    res = ''
    for nb_par in range(4):
        template_par = string.join( ['class Op'] + [ 'class TP%i'%i for i in range(nb_par) ] ,',')
        fun_par = ['Op& op'] + [ 'TP%i &p%i'%(i,i) for i in range(nb_par) ]
        coder = string.replace( code, ',PARALIST', string.join([',p%i'%i for i in range(nb_par)],'') )
        for j in range( 2**(len(fun_par)+1) ):
            if onlyforconstvec and (j&1)!=0: continue
            if onlyfornonconstvec and (j&1)==0: continue
            fun_par2 = ['const '*((2**(k+1) & j)==0)+fp for fp,k in zip(fun_par,range(len(fun_par)))]
            stf = string.join( fun_par2[:1]+suppar+fun_par2[1:] ,',')
            coderr  = string.replace( coder , 'CONSTV', '_const'*((j&1)==0) )
            coderrr = string.replace( coderr, 'CONSTK ', 'const '*((j&1)==0) )
            res += '    template<'+template_par+'> inline '+ret+' '+name+'('+stf+') '+'const '*((j&1)==0)+'{ '+coderrr+' }\n'
    res += '\n'
    return res

# -------
def print_apply_ext(name,templ,namevec,code_,ret='void',onlyforconstvec=False,onlyfornonconstvec=False,suppar=[],nsp='',allconst=False):
    if nsp: print '  namespace '+nsp+' {'
    code = string.replace( code_, 'NAMEVEC', namevec )
    for nb_par in range(4):
        template_par = string.join( templ+['int s','class Op'] + [ 'class TP%i'%i for i in range(nb_par) ] ,',')
        fun_par = [namevec+' &v','Op& op'] + [ 'TP%i &p%i'%(i,i) for i in range(nb_par) ]
        coder = string.replace( code, ',PARALIST', string.join([',p%i'%i for i in range(nb_par)],'') )
        for j in range( 2**(len(fun_par)) ):
            if onlyforconstvec and (j&1)!=0: continue
            if onlyfornonconstvec and (j&1)==0: continue
            if allconst and j: continue
            fun_par2 = ['const '*((2**k & j)==0)+fp for fp,k in zip(fun_par,range(len(fun_par)))]
            stf = string.join( fun_par2[:1]+suppar+fun_par2[1:] ,',')
            coderr  = string.replace( coder , 'CONSTV', '_const'*((j&1)==0) )
            coderrr = string.replace( coderr, 'CONSTK ', 'const '*((j&1)==0) )
            coderrrr = string.replace( coderrr, 'ONEIFCONSTOP', str( 1-(j&2)/2 ) )
            rett = string.replace( ret, 'CONSTK ', 'const '*((j&1)==0) )
            print '  template<'+template_par+'> inline '+rett+' '+name+'('+stf+') { '+coderrrr+' }' #  /// \\relates Vec
    if nsp: print '  } // namespace '+nsp
    print 
