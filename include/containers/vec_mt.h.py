# -*- coding: utf-8 -*-
import string

print """
#ifndef VEC_MT_H
#define VEC_MT_H

#ifdef METIL_COMP_DIRECTIVE
#pragma lib_name pthread
#endif

namespace LMT {
"""

cpt = 0
for nb_param in range(4):
    param = [ 'op' ] + [ 'p'+str(i) for i in range(nb_param) ]
    Tparam = [ 'Op' ] + [ 'TP'+str(i) for i in range(nb_param) ]
    for num_const in range(2**(nb_param+2)):
        Const = [ 'const'*((num_const & 2**i)!=0) for i in range(nb_param+2) ]
        ALL_T = string.join( map(lambda x:'class '+x, Tparam), ',' )
    
        print """
/*!
 \\internal
*/
template<class TV,"""+ALL_T+""">
struct Param_partial_apply_"""+str(cpt)+""" {
    unsigned begin, end, inc, num_thread;
    """+Const[0]+""" TV *vec;
    """+string.join( map(lambda (c,x,y):c+' '+x+' *'+y+';', zip(Const[1:],Tparam,param)), '\n    ' )+"""
};
"""
        for wi in ['','_wi','_with_num_thread']:
            if wi == '_with_num_thread' and nb_param==3:
                continue
            wi_ex = wi * ( wi == '_wi' )
            call_param = [ '*ppa.op' ] + ['ppa.num_thread'] * ( wi.find('_with_num_thread')>=0 ) + [ '*ppa.p'+str(i) for i in range(nb_param) ]
            simple_call_param = [ 'op' ] + ['0'] * ( wi.find('_with_num_thread')>=0 ) + [ 'p'+str(i) for i in range(nb_param) ]
            print """
/*!\n \\relates apply_mt()\n \\internal\n*/\n
template<class T,"""+ALL_T+""">
void *partial_apply_"""+str(cpt)+wi+"""(void *params) {
    Param_partial_apply_"""+str(cpt)+"""<T,"""+string.join(Tparam,',')+"""> &ppa( *static_cast<Param_partial_apply_"""+str(cpt)+"""<T,"""+string.join(Tparam,',')+"""> *>(params) );
    apply_range_stride"""+wi_ex+"""( *ppa.vec, ppa.begin, ppa.end, ppa.inc, """+string.join( call_param, ', ' )+""" );
    return (void *)NULL;
}

/*!
 \\relates apply
*/
template<class TT,int s,"""+ALL_T+""">
void apply_mt"""+wi+"""("""+Const[0]+""" Vec<TT,s> &v,unsigned nb_threads,"""+string.join( map(lambda (c,x,y):c+' '+x+' &'+y+'', zip(Const[1:],Tparam,param)), ',' )+""") {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_"""+str(cpt)+"""<Vec<TT,s>,"""+string.join(Tparam,',')+"""> *ppa = new Param_partial_apply_"""+str(cpt)+"""<Vec<TT,s>,"""+string.join(Tparam,',')+""">[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            """+string.join( map(lambda x:'ppa[i].'+x+' = &'+x+';', param), '\n            ' )+"""
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_"""+str(cpt)+wi+"""<Vec<TT,s>,"""+string.join(Tparam,',')+""">, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply"""+wi_ex+"""(v,"""+string.join( map(lambda (x):x,simple_call_param), ',' )+""");
    }
}
/*!
 \\internal
*/
template<class TT,int s,"""+ALL_T+""">
void apply_mt_stride"""+wi+"""("""+Const[0]+""" Vec<TT,s> &v,unsigned nb_threads,"""+string.join( map(lambda (c,x,y):c+' '+x+' &'+y+'', zip(Const[1:],Tparam,param)), ',' )+""") {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_"""+str(cpt)+"""<Vec<TT,s>,"""+string.join(Tparam,',')+"""> *ppa = new Param_partial_apply_"""+str(cpt)+"""<Vec<TT,s>,"""+string.join(Tparam,',')+""">[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            """+string.join( map(lambda x:'ppa[i].'+x+' = &'+x+';', param), '\n            ' )+"""
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_"""+str(cpt)+wi+"""<Vec<TT,s>,"""+string.join(Tparam,',')+""">, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply"""+wi_ex+"""(v,"""+string.join( map(lambda (x):x,simple_call_param), ',' )+""");
    }
}
    """
        cpt += 1


#print_apply_ext('apply_mt_with_num_thread',TP,TV,'apply_mt(v.vec,nb_threads,op,PARALIST); apply_mt(v.next,nb_threads,op,PARALIST);', suppar=['int nb_threads'] )


print '}'
print """
#endif //VEC_MT_H
"""


