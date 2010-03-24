
#ifndef VEC_MT_H
#define VEC_MT_H
namespace LMT {


/*!
 \internal
*/
template<class TV,class Op>
struct Param_partial_apply_0 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_0(void *params) {
    Param_partial_apply_0<T,Op> &ppa( *static_cast<Param_partial_apply_0<T,Op> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_0<Vec<TT,s>,Op> *ppa = new Param_partial_apply_0<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_0<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_0<Vec<TT,s>,Op> *ppa = new Param_partial_apply_0<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_0<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_0_wi(void *params) {
    Param_partial_apply_0<T,Op> &ppa( *static_cast<Param_partial_apply_0<T,Op> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_0<Vec<TT,s>,Op> *ppa = new Param_partial_apply_0<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_0_wi<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_0<Vec<TT,s>,Op> *ppa = new Param_partial_apply_0<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_0_wi<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_0_with_num_thread(void *params) {
    Param_partial_apply_0<T,Op> &ppa( *static_cast<Param_partial_apply_0<T,Op> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_0<Vec<TT,s>,Op> *ppa = new Param_partial_apply_0<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_0_with_num_thread<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_0<Vec<TT,s>,Op> *ppa = new Param_partial_apply_0<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_0_with_num_thread<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op>
struct Param_partial_apply_1 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_1(void *params) {
    Param_partial_apply_1<T,Op> &ppa( *static_cast<Param_partial_apply_1<T,Op> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_1<Vec<TT,s>,Op> *ppa = new Param_partial_apply_1<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_1<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_1<Vec<TT,s>,Op> *ppa = new Param_partial_apply_1<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_1<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_1_wi(void *params) {
    Param_partial_apply_1<T,Op> &ppa( *static_cast<Param_partial_apply_1<T,Op> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_1<Vec<TT,s>,Op> *ppa = new Param_partial_apply_1<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_1_wi<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_1<Vec<TT,s>,Op> *ppa = new Param_partial_apply_1<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_1_wi<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_1_with_num_thread(void *params) {
    Param_partial_apply_1<T,Op> &ppa( *static_cast<Param_partial_apply_1<T,Op> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_1<Vec<TT,s>,Op> *ppa = new Param_partial_apply_1<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_1_with_num_thread<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_1<Vec<TT,s>,Op> *ppa = new Param_partial_apply_1<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_1_with_num_thread<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op>
struct Param_partial_apply_2 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_2(void *params) {
    Param_partial_apply_2<T,Op> &ppa( *static_cast<Param_partial_apply_2<T,Op> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_2<Vec<TT,s>,Op> *ppa = new Param_partial_apply_2<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_2<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_2<Vec<TT,s>,Op> *ppa = new Param_partial_apply_2<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_2<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_2_wi(void *params) {
    Param_partial_apply_2<T,Op> &ppa( *static_cast<Param_partial_apply_2<T,Op> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_2<Vec<TT,s>,Op> *ppa = new Param_partial_apply_2<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_2_wi<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_2<Vec<TT,s>,Op> *ppa = new Param_partial_apply_2<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_2_wi<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_2_with_num_thread(void *params) {
    Param_partial_apply_2<T,Op> &ppa( *static_cast<Param_partial_apply_2<T,Op> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_2<Vec<TT,s>,Op> *ppa = new Param_partial_apply_2<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_2_with_num_thread<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_2<Vec<TT,s>,Op> *ppa = new Param_partial_apply_2<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_2_with_num_thread<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op>
struct Param_partial_apply_3 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_3(void *params) {
    Param_partial_apply_3<T,Op> &ppa( *static_cast<Param_partial_apply_3<T,Op> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_3<Vec<TT,s>,Op> *ppa = new Param_partial_apply_3<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_3<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_3<Vec<TT,s>,Op> *ppa = new Param_partial_apply_3<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_3<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_3_wi(void *params) {
    Param_partial_apply_3<T,Op> &ppa( *static_cast<Param_partial_apply_3<T,Op> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_3<Vec<TT,s>,Op> *ppa = new Param_partial_apply_3<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_3_wi<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_3<Vec<TT,s>,Op> *ppa = new Param_partial_apply_3<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_3_wi<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op>
void *partial_apply_3_with_num_thread(void *params) {
    Param_partial_apply_3<T,Op> &ppa( *static_cast<Param_partial_apply_3<T,Op> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_3<Vec<TT,s>,Op> *ppa = new Param_partial_apply_3<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_3_with_num_thread<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_3<Vec<TT,s>,Op> *ppa = new Param_partial_apply_3<Vec<TT,s>,Op>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_3_with_num_thread<Vec<TT,s>,Op>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0>
struct Param_partial_apply_4 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
     TP0 *p0;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_4(void *params) {
    Param_partial_apply_4<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_4<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_4<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_4<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_4<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_4<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_4<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_4<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_4_wi(void *params) {
    Param_partial_apply_4<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_4<T,Op,TP0> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_4<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_4<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_4_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_4<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_4<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_4_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_4_with_num_thread(void *params) {
    Param_partial_apply_4<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_4<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_4<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_4<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_4_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_4<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_4<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_4_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0>
struct Param_partial_apply_5 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
     TP0 *p0;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_5(void *params) {
    Param_partial_apply_5<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_5<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_5<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_5<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_5<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_5<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_5<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_5<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_5_wi(void *params) {
    Param_partial_apply_5<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_5<T,Op,TP0> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_5<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_5<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_5_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_5<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_5<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_5_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_5_with_num_thread(void *params) {
    Param_partial_apply_5<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_5<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_5<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_5<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_5_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_5<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_5<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_5_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0>
struct Param_partial_apply_6 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
     TP0 *p0;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_6(void *params) {
    Param_partial_apply_6<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_6<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_6<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_6<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_6<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_6<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_6<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_6<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_6_wi(void *params) {
    Param_partial_apply_6<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_6<T,Op,TP0> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_6<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_6<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_6_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_6<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_6<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_6_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_6_with_num_thread(void *params) {
    Param_partial_apply_6<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_6<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_6<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_6<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_6_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_6<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_6<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_6_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0>
struct Param_partial_apply_7 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
     TP0 *p0;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_7(void *params) {
    Param_partial_apply_7<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_7<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_7<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_7<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_7<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_7<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_7<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_7<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_7_wi(void *params) {
    Param_partial_apply_7<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_7<T,Op,TP0> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_7<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_7<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_7_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_7<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_7<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_7_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_7_with_num_thread(void *params) {
    Param_partial_apply_7<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_7<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_7<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_7<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_7_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_7<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_7<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_7_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0>
struct Param_partial_apply_8 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
    const TP0 *p0;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_8(void *params) {
    Param_partial_apply_8<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_8<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_8<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_8<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_8<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_8<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_8<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_8<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_8_wi(void *params) {
    Param_partial_apply_8<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_8<T,Op,TP0> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_8<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_8<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_8_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_8<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_8<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_8_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_8_with_num_thread(void *params) {
    Param_partial_apply_8<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_8<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_8<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_8<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_8_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_8<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_8<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_8_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0>
struct Param_partial_apply_9 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
    const TP0 *p0;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_9(void *params) {
    Param_partial_apply_9<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_9<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_9<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_9<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_9<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_9<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_9<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_9<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_9_wi(void *params) {
    Param_partial_apply_9<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_9<T,Op,TP0> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_9<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_9<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_9_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_9<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_9<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_9_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_9_with_num_thread(void *params) {
    Param_partial_apply_9<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_9<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_9<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_9<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_9_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_9<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_9<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_9_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0>
struct Param_partial_apply_10 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
    const TP0 *p0;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_10(void *params) {
    Param_partial_apply_10<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_10<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_10<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_10<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_10<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_10<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_10<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_10<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_10_wi(void *params) {
    Param_partial_apply_10<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_10<T,Op,TP0> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_10<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_10<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_10_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_10<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_10<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_10_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_10_with_num_thread(void *params) {
    Param_partial_apply_10<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_10<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_10<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_10<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_10_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_10<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_10<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_10_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0>
struct Param_partial_apply_11 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
    const TP0 *p0;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_11(void *params) {
    Param_partial_apply_11<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_11<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_11<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_11<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_11<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_11<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_11<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_11<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_11_wi(void *params) {
    Param_partial_apply_11<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_11<T,Op,TP0> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_11<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_11<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_11_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_11<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_11<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_11_wi<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0>
void *partial_apply_11_with_num_thread(void *params) {
    Param_partial_apply_11<T,Op,TP0> &ppa( *static_cast<Param_partial_apply_11<T,Op,TP0> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_11<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_11<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_11_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_11<Vec<TT,s>,Op,TP0> *ppa = new Param_partial_apply_11<Vec<TT,s>,Op,TP0>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_11_with_num_thread<Vec<TT,s>,Op,TP0>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_12 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
     TP0 *p0;
     TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_12(void *params) {
    Param_partial_apply_12<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_12<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_12<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_12<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_12_wi(void *params) {
    Param_partial_apply_12<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_12<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_12_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_12_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_12_with_num_thread(void *params) {
    Param_partial_apply_12<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_12<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_12_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_12<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_12_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_13 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
     TP0 *p0;
     TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_13(void *params) {
    Param_partial_apply_13<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_13<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_13<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_13<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_13_wi(void *params) {
    Param_partial_apply_13<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_13<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_13_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_13_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_13_with_num_thread(void *params) {
    Param_partial_apply_13<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_13<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_13_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_13<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_13_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_14 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
     TP0 *p0;
     TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_14(void *params) {
    Param_partial_apply_14<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_14<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_14<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_14<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_14_wi(void *params) {
    Param_partial_apply_14<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_14<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_14_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_14_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_14_with_num_thread(void *params) {
    Param_partial_apply_14<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_14<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_14_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_14<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_14_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_15 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
     TP0 *p0;
     TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_15(void *params) {
    Param_partial_apply_15<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_15<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_15<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_15<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_15_wi(void *params) {
    Param_partial_apply_15<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_15<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_15_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_15_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_15_with_num_thread(void *params) {
    Param_partial_apply_15<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_15<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_15_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_15<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_15_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_16 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
    const TP0 *p0;
     TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_16(void *params) {
    Param_partial_apply_16<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_16<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_16<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_16<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_16_wi(void *params) {
    Param_partial_apply_16<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_16<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_16_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_16_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_16_with_num_thread(void *params) {
    Param_partial_apply_16<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_16<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_16_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_16<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_16_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_17 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
    const TP0 *p0;
     TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_17(void *params) {
    Param_partial_apply_17<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_17<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_17<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_17<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_17_wi(void *params) {
    Param_partial_apply_17<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_17<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_17_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_17_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_17_with_num_thread(void *params) {
    Param_partial_apply_17<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_17<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_17_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_17<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_17_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_18 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
    const TP0 *p0;
     TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_18(void *params) {
    Param_partial_apply_18<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_18<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_18<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_18<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_18_wi(void *params) {
    Param_partial_apply_18<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_18<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_18_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_18_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_18_with_num_thread(void *params) {
    Param_partial_apply_18<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_18<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_18_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_18<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_18_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_19 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
    const TP0 *p0;
     TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_19(void *params) {
    Param_partial_apply_19<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_19<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_19<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_19<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_19_wi(void *params) {
    Param_partial_apply_19<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_19<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_19_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_19_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_19_with_num_thread(void *params) {
    Param_partial_apply_19<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_19<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_19_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_19<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_19_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_20 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
     TP0 *p0;
    const TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_20(void *params) {
    Param_partial_apply_20<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_20<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_20<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_20<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_20_wi(void *params) {
    Param_partial_apply_20<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_20<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_20_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_20_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_20_with_num_thread(void *params) {
    Param_partial_apply_20<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_20<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_20_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_20<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_20_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_21 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
     TP0 *p0;
    const TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_21(void *params) {
    Param_partial_apply_21<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_21<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_21<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_21<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_21_wi(void *params) {
    Param_partial_apply_21<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_21<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_21_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_21_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_21_with_num_thread(void *params) {
    Param_partial_apply_21<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_21<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_21_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_21<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_21_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_22 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
     TP0 *p0;
    const TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_22(void *params) {
    Param_partial_apply_22<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_22<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_22<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_22<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_22_wi(void *params) {
    Param_partial_apply_22<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_22<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_22_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_22_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_22_with_num_thread(void *params) {
    Param_partial_apply_22<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_22<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_22_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_22<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_22_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_23 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
     TP0 *p0;
    const TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_23(void *params) {
    Param_partial_apply_23<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_23<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_23<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_23<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_23_wi(void *params) {
    Param_partial_apply_23<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_23<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_23_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_23_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_23_with_num_thread(void *params) {
    Param_partial_apply_23<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_23<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_23_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_23<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_23_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_24 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
    const TP0 *p0;
    const TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_24(void *params) {
    Param_partial_apply_24<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_24<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_24<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_24<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_24_wi(void *params) {
    Param_partial_apply_24<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_24<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_24_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_24_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_24_with_num_thread(void *params) {
    Param_partial_apply_24<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_24<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_24_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_24<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_24_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_25 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
    const TP0 *p0;
    const TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_25(void *params) {
    Param_partial_apply_25<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_25<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_25<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_25<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_25_wi(void *params) {
    Param_partial_apply_25<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_25<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_25_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_25_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_25_with_num_thread(void *params) {
    Param_partial_apply_25<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_25<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_25_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_25<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_25_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_26 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
    const TP0 *p0;
    const TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_26(void *params) {
    Param_partial_apply_26<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_26<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_26<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_26<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_26_wi(void *params) {
    Param_partial_apply_26<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_26<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_26_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_26_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_26_with_num_thread(void *params) {
    Param_partial_apply_26<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_26<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_26_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_26<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_26_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1>
struct Param_partial_apply_27 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
    const TP0 *p0;
    const TP1 *p1;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_27(void *params) {
    Param_partial_apply_27<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_27<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_27<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_27<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_27_wi(void *params) {
    Param_partial_apply_27<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_27<T,Op,TP0,TP1> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_27_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_27_wi<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1>
void *partial_apply_27_with_num_thread(void *params) {
    Param_partial_apply_27<T,Op,TP0,TP1> &ppa( *static_cast<Param_partial_apply_27<T,Op,TP0,TP1> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, ppa.num_thread, *ppa.p0, *ppa.p1 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_27_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1>
void apply_mt_stride_with_num_thread(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1> *ppa = new Param_partial_apply_27<Vec<TT,s>,Op,TP0,TP1>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_27_with_num_thread<Vec<TT,s>,Op,TP0,TP1>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,0,p0,p1);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_28 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
     TP0 *p0;
     TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_28(void *params) {
    Param_partial_apply_28<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_28<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_28<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_28<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_28<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_28<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_28<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_28<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_28_wi(void *params) {
    Param_partial_apply_28<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_28<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_28<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_28<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_28_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_28<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_28<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_28_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_29 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
     TP0 *p0;
     TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_29(void *params) {
    Param_partial_apply_29<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_29<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_29<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_29<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_29<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_29<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_29<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_29<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_29_wi(void *params) {
    Param_partial_apply_29<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_29<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_29<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_29<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_29_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_29<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_29<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_29_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_30 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
     TP0 *p0;
     TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_30(void *params) {
    Param_partial_apply_30<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_30<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_30<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_30<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_30<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_30<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_30<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_30<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_30_wi(void *params) {
    Param_partial_apply_30<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_30<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_30<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_30<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_30_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_30<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_30<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_30_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_31 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
     TP0 *p0;
     TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_31(void *params) {
    Param_partial_apply_31<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_31<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_31<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_31<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_31<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_31<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_31<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_31<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_31_wi(void *params) {
    Param_partial_apply_31<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_31<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_31<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_31<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_31_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_31<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_31<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_31_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_32 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
    const TP0 *p0;
     TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_32(void *params) {
    Param_partial_apply_32<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_32<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_32<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_32<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_32<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_32<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_32<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_32<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_32_wi(void *params) {
    Param_partial_apply_32<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_32<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_32<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_32<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_32_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_32<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_32<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_32_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_33 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
    const TP0 *p0;
     TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_33(void *params) {
    Param_partial_apply_33<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_33<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_33<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_33<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_33<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_33<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_33<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_33<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_33_wi(void *params) {
    Param_partial_apply_33<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_33<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_33<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_33<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_33_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_33<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_33<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_33_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_34 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
    const TP0 *p0;
     TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_34(void *params) {
    Param_partial_apply_34<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_34<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_34<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_34<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_34<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_34<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_34<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_34<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_34_wi(void *params) {
    Param_partial_apply_34<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_34<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_34<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_34<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_34_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_34<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_34<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_34_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_35 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
    const TP0 *p0;
     TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_35(void *params) {
    Param_partial_apply_35<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_35<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_35<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_35<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_35<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_35<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_35<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_35<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_35_wi(void *params) {
    Param_partial_apply_35<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_35<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_35<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_35<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_35_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_35<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_35<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_35_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_36 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
     TP0 *p0;
    const TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_36(void *params) {
    Param_partial_apply_36<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_36<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_36<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_36<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_36<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_36<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_36<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_36<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_36_wi(void *params) {
    Param_partial_apply_36<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_36<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_36<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_36<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_36_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_36<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_36<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_36_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_37 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
     TP0 *p0;
    const TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_37(void *params) {
    Param_partial_apply_37<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_37<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_37<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_37<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_37<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_37<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_37<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_37<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_37_wi(void *params) {
    Param_partial_apply_37<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_37<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_37<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_37<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_37_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_37<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_37<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_37_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_38 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
     TP0 *p0;
    const TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_38(void *params) {
    Param_partial_apply_38<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_38<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_38<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_38<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_38<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_38<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_38<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_38<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_38_wi(void *params) {
    Param_partial_apply_38<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_38<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_38<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_38<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_38_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_38<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_38<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_38_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_39 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
     TP0 *p0;
    const TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_39(void *params) {
    Param_partial_apply_39<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_39<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_39<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_39<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_39<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_39<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_39<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_39<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_39_wi(void *params) {
    Param_partial_apply_39<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_39<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_39<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_39<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_39_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_39<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_39<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_39_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_40 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
    const TP0 *p0;
    const TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_40(void *params) {
    Param_partial_apply_40<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_40<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_40<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_40<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_40<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_40<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_40<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_40<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_40_wi(void *params) {
    Param_partial_apply_40<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_40<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_40<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_40<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_40_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_40<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_40<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_40_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_41 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
    const TP0 *p0;
    const TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_41(void *params) {
    Param_partial_apply_41<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_41<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_41<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_41<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_41<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_41<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_41<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_41<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_41_wi(void *params) {
    Param_partial_apply_41<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_41<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_41<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_41<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_41_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_41<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_41<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_41_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_42 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
    const TP0 *p0;
    const TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_42(void *params) {
    Param_partial_apply_42<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_42<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_42<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_42<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_42<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_42<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_42<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_42<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_42_wi(void *params) {
    Param_partial_apply_42<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_42<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_42<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_42<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_42_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_42<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_42<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_42_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_43 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
    const TP0 *p0;
    const TP1 *p1;
     TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_43(void *params) {
    Param_partial_apply_43<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_43<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_43<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_43<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_43<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_43<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_43<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_43<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_43_wi(void *params) {
    Param_partial_apply_43<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_43<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_43<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_43<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_43_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1, TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_43<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_43<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_43_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_44 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
     TP0 *p0;
     TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_44(void *params) {
    Param_partial_apply_44<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_44<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_44<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_44<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_44<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_44<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_44<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_44<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_44_wi(void *params) {
    Param_partial_apply_44<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_44<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_44<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_44<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_44_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_44<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_44<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_44_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_45 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
     TP0 *p0;
     TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_45(void *params) {
    Param_partial_apply_45<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_45<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_45<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_45<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_45<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_45<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_45<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_45<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_45_wi(void *params) {
    Param_partial_apply_45<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_45<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_45<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_45<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_45_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_45<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_45<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_45_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_46 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
     TP0 *p0;
     TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_46(void *params) {
    Param_partial_apply_46<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_46<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_46<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_46<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_46<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_46<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_46<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_46<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_46_wi(void *params) {
    Param_partial_apply_46<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_46<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_46<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_46<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_46_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_46<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_46<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_46_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_47 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
     TP0 *p0;
     TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_47(void *params) {
    Param_partial_apply_47<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_47<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_47<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_47<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_47<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_47<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_47<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_47<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_47_wi(void *params) {
    Param_partial_apply_47<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_47<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_47<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_47<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_47_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_47<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_47<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_47_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_48 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
    const TP0 *p0;
     TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_48(void *params) {
    Param_partial_apply_48<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_48<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_48<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_48<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_48<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_48<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_48<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_48<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_48_wi(void *params) {
    Param_partial_apply_48<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_48<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_48<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_48<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_48_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_48<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_48<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_48_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_49 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
    const TP0 *p0;
     TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_49(void *params) {
    Param_partial_apply_49<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_49<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_49<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_49<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_49<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_49<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_49<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_49<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_49_wi(void *params) {
    Param_partial_apply_49<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_49<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_49<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_49<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_49_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_49<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_49<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_49_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_50 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
    const TP0 *p0;
     TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_50(void *params) {
    Param_partial_apply_50<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_50<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_50<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_50<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_50<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_50<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_50<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_50<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_50_wi(void *params) {
    Param_partial_apply_50<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_50<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_50<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_50<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_50_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_50<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_50<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_50_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_51 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
    const TP0 *p0;
     TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_51(void *params) {
    Param_partial_apply_51<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_51<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_51<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_51<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_51<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_51<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_51<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_51<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_51_wi(void *params) {
    Param_partial_apply_51<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_51<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_51<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_51<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_51_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0, TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_51<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_51<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_51_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_52 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
     TP0 *p0;
    const TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_52(void *params) {
    Param_partial_apply_52<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_52<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_52<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_52<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_52<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_52<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_52<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_52<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_52_wi(void *params) {
    Param_partial_apply_52<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_52<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_52<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_52<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_52_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_52<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_52<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_52_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_53 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
     TP0 *p0;
    const TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_53(void *params) {
    Param_partial_apply_53<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_53<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_53<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_53<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_53<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_53<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_53<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_53<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_53_wi(void *params) {
    Param_partial_apply_53<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_53<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_53<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_53<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_53_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_53<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_53<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_53_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_54 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
     TP0 *p0;
    const TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_54(void *params) {
    Param_partial_apply_54<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_54<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_54<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_54<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_54<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_54<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_54<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_54<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_54_wi(void *params) {
    Param_partial_apply_54<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_54<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_54<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_54<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_54_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_54<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_54<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_54_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_55 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
     TP0 *p0;
    const TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_55(void *params) {
    Param_partial_apply_55<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_55<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_55<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_55<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_55<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_55<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_55<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_55<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_55_wi(void *params) {
    Param_partial_apply_55<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_55<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_55<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_55<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_55_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op, TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_55<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_55<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_55_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_56 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
     Op *op;
    const TP0 *p0;
    const TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_56(void *params) {
    Param_partial_apply_56<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_56<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_56<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_56<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_56<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_56<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_56<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_56<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_56_wi(void *params) {
    Param_partial_apply_56<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_56<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_56<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_56<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_56_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_56<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_56<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_56_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_57 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
     Op *op;
    const TP0 *p0;
    const TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_57(void *params) {
    Param_partial_apply_57<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_57<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_57<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_57<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_57<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_57<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_57<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_57<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_57_wi(void *params) {
    Param_partial_apply_57<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_57<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_57<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_57<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_57_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads, Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_57<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_57<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_57_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_58 {
    unsigned begin, end, inc, num_thread;
     TV *vec;
    const Op *op;
    const TP0 *p0;
    const TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_58(void *params) {
    Param_partial_apply_58<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_58<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_58<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_58<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_58<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_58<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_58<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_58<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_58_wi(void *params) {
    Param_partial_apply_58<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_58<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_58<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_58<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_58_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi( Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_58<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_58<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_58_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    

/*!
 \internal
*/
template<class TV,class Op,class TP0,class TP1,class TP2>
struct Param_partial_apply_59 {
    unsigned begin, end, inc, num_thread;
    const TV *vec;
    const Op *op;
    const TP0 *p0;
    const TP1 *p1;
    const TP2 *p2;
};


/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_59(void *params) {
    Param_partial_apply_59<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_59<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_59<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_59<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_59<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_59<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_59<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_59<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply(v,op,p0,p1,p2);
    }
}
    

/*!
 \relates apply_mt()
 \internal
*/

template<class T,class Op,class TP0,class TP1,class TP2>
void *partial_apply_59_wi(void *params) {
    Param_partial_apply_59<T,Op,TP0,TP1,TP2> &ppa( *static_cast<Param_partial_apply_59<T,Op,TP0,TP1,TP2> *>(params) );
    apply_range_stride_wi( *ppa.vec, ppa.begin, ppa.end, ppa.inc, *ppa.op, *ppa.p0, *ppa.p1, *ppa.p2 );
    return (void *)NULL;
}

/*!
 \relates apply
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_59<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_59<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i*si/nb_threads;
            ppa[i].inc = 1;
            ppa[i].end = (i+1)*si/nb_threads;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_59_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
/*!
 \internal
*/
template<class TT,int s,class Op,class TP0,class TP1,class TP2>
void apply_mt_stride_wi(const Vec<TT,s> &v,unsigned nb_threads,const Op &op,const TP0 &p0,const TP1 &p1,const TP2 &p2) {
    if ( nb_threads > 1 && v.size() >= nb_threads ) {
        pthread_t *tid = new pthread_t[nb_threads];
        Param_partial_apply_59<Vec<TT,s>,Op,TP0,TP1,TP2> *ppa = new Param_partial_apply_59<Vec<TT,s>,Op,TP0,TP1,TP2>[nb_threads];
    
        unsigned si = v.size();
        for(unsigned i=0;i<nb_threads;++i) {
            ppa[i].begin = i;
            ppa[i].inc = nb_threads;
            ppa[i].end = si;
            ppa[i].num_thread = i;
            ppa[i].op = &op;
            ppa[i].p0 = &p0;
            ppa[i].p1 = &p1;
            ppa[i].p2 = &p2;
            ppa[i].vec = &v;
            pthread_create( &tid[i], NULL, partial_apply_59_wi<Vec<TT,s>,Op,TP0,TP1,TP2>, static_cast<void *>(ppa+i) );
        }
        for(unsigned i=0;i<nb_threads;++i)
            pthread_join(tid[i],(void **)ppa);
    
        delete [] tid;
        delete [] ppa;
    }
    else {
        apply_wi(v,op,p0,p1,p2);
    }
}
    
}

#endif //VEC_MT_H

