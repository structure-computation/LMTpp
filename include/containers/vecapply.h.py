import string
from vecgenhelp import *

print 'namespace LMT {'

# apply, find
for tt in ['void','int']:
    TT = ['class TT']
    TV = 'Vec<TT,s,'+tt+'>'
    print_apply_ext('apply'                ,TT,TV,'for(unsigned i=0;i<v.size();++i) op(v[i],PARALIST);')

    print_apply_ext('apply_nz'             ,TT,TV,'apply(v,op,PARALIST);')
    print_apply_ext('apply_nz_unique'      ,TT,TV,'apply_nz(v,op,PARALIST);')
    print_apply_ext('apply_range'          ,TT,TV,'DEBUGASSERT(to<=(int)v.size()); for(;from<to;++from) op(v[from],PARALIST);',suppar=['int from','int to'])
    print_apply_ext('apply_range_stride'   ,TT,TV,'DEBUGASSERT(to<=(int)v.size()); for(;from<to;from+=inc) op(v[from],PARALIST);',suppar=['int from','int to','int inc'])

    print_apply_ext('apply_wi'             ,TT,TV,'for(unsigned i=0;i<v.size();++i) op(v[i],i,PARALIST);')
    print_apply_ext('apply_nz_wi'          ,TT,TV,'apply_wi(v,op,PARALIST);')
    print_apply_ext('apply_range_wi'       ,TT,TV,'DEBUGASSERT(to<=(int)v.size()); for(;from<to;++from) op(v[from],from,PARALIST);',suppar=['int from','int to'])
    print_apply_ext('apply_range_stride_wi',TT,TV,'DEBUGASSERT(to<=(int)v.size()); for(;from<to;from+=inc) op(v[from],from,PARALIST);',suppar=['int from','int to','int inc'])

    print_apply_ext('find_w_wo_ind'        ,TT,TV,'return reduction( generate(v,op,PARALIST), Or() );',ret='bool',suppar=['const Number<0> &ni'])
    print_apply_ext('find_w_wo_ind'        ,TT,TV,'for(unsigned i=0;i<v.size();++i) if (op(v[i],PARALIST)) return true; return false;',ret='bool',suppar=['const Number<1> &ni'])
    
    print_apply_ext('find'                 ,TT,TV,'return find_w_wo_ind(v,Number<HasIndexAccess<TT>::res>(),op,PARALIST);',ret='bool')
    
    RET = 'typename '+TV+'::template SubType<0>::T'
    print_apply_ext( 'find_elem', TT, TV,
        'STATICASSERT((Vec<TT,s,'+tt+'>::nb_sub_type==1)); for(unsigned i=0;i<v.size();++i) if (op(v[i],PARALIST)) return &v[i]; return (CONSTK '+RET+' *)NULL;',
        ret='CONSTK '+RET+' *'
    )

# simd
    print_apply_ext(
      'apply_simd_w_wo_simd_method',TT+['unsigned ne'],TV,
      'apply(v,op,PARALIST);',
      nsp='LMTPRIVATE',suppar=['const Number<0> &,const Number<ne> &NE']
    )
    print_apply_ext(
      'apply_simd_w_wo_simd_method',TT+['unsigned ne'],TV,"""
        int i;
        for(i=0;i<int(v.size()-4*ne+1);i+=4*ne) op(get_simd(v,i+3*ne,NE),get_simd(v,i+2*ne,NE),get_simd(v,i+ne,NE),get_simd(v,i,NE),PARALIST);
        for(;i<int(v.size()-ne+1);i+=ne) op(get_simd(v,i,NE),PARALIST);
        for(;i<(int)v.size();++i) op(v[i],PARALIST);
    """,
      nsp='LMTPRIVATE',suppar=['const Number<1> &,const Number<ne> &NE']
    )
    print_apply_ext(
      'apply_simd_w_wo_simd_method',TT+['unsigned ne'],TV,"""
        int i;
        for(i=0;i<int(v.size()-4*ne+1);i+=4*ne) op(v.simd(i+3*ne,NE),v.simd(i+2*ne,NE),v.simd(i+ne,NE),v.simd(i,NE),PARALIST);
        for(;i<int(v.size()-ne+1);i+=ne) op(v.simd(i,NE),PARALIST);
        for(;i<(int)v.size();++i) op(v[i],PARALIST);
    """,
      nsp='LMTPRIVATE',suppar=['const Number<2> &,const Number<ne> &NE']
    )
    print_apply_ext('apply_simd',TT,TV,
        'LMTPRIVATE::apply_simd_w_wo_simd_method(v,Number<(VecSupportSIMD<%s >::res+1)*(s==-1||s>=16)>(),Number<SimdSizeForVec<%s >::res>(),op,PARALIST);'%(TV,TV)
    )

# sim_wi
    print_apply_ext(
      'apply_simd_wi_w_wo_simd_method',TT+['unsigned ne'],TV,
      'apply_wi(v,op,PARALIST);',
      nsp='LMTPRIVATE',suppar=['const Number<0> &,const Number<ne> &NE']
    )
    print_apply_ext(
      'apply_simd_wi_w_wo_simd_method',TT+['unsigned ne'],TV,"""
        int i;
        for(i=0;i<int(v.size()-4*ne+1);i+=4*ne) op(get_simd(v,i+3*ne,NE),get_simd(v,i+2*ne,NE),get_simd(v,i+ne,NE),get_simd(v,i,NE),i,PARALIST);
        for(;i<int(v.size()-ne+1);i+=ne) op(get_simd(v,i,NE),i,PARALIST);
        for(;i<(int)v.size();++i) op(v[i],i,PARALIST);
    """,
      nsp='LMTPRIVATE',suppar=['const Number<1> &,const Number<ne> &NE']
    )
    print_apply_ext(
      'apply_simd_wi_w_wo_simd_method',TT+['unsigned ne'],TV,"""
        int i;
        for(i=0;i<int(v.size()-4*ne+1);i+=4*ne) op(v.simd(i+3*ne,NE),v.simd(i+2*ne,NE),v.simd(i+ne,NE),v.simd(i,NE),i,PARALIST);
        for(;i<int(v.size()-ne+1);i+=ne) op(v.simd(i,NE),i,PARALIST);
        for(;i<(int)v.size();++i) op(v[i],i,PARALIST);
    """,
      nsp='LMTPRIVATE',suppar=['const Number<2> &,const Number<ne> &NE']
    )
    print_apply_ext('apply_simd_wi',TT,TV,
        'LMTPRIVATE::apply_simd_wi_w_wo_simd_method(v,Number<(VecSupportSIMD<%s >::res+1)*(s==-1||s>=16)>(),Number<SimdSizeForVec<%s >::res>(),op,PARALIST);'%(TV,TV)
    )

# remove_if
    print_apply_ext('remove_if',TT,TV,"""
        for(unsigned i=0;i<v.size();++i) {
            if ( op(v[i],PARALIST) ) {
                v[i--] = v.back();
                v.pop_back();
            }
        }
    """,onlyfornonconstvec=True)

print '}'
