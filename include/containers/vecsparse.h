/// file generated from vecsparse.h.py. Do not modify

namespace LMT {

template<class T> struct Sparse {};

template<class TT> struct IsVecOp<Sparse<TT> > { typedef int T; };

template<class TT> struct DelayedAssignementSparseSource {
    typedef TT T;
    TT get() const {
        if ( found ) return (*data)[pos];
        return TT(0);
    }
    template<class Op,class T2> void apply(const Op &op,const T2 &v) {
        if ( found ) {
            (*data)[pos] = op( (*data)[pos], v );
            if ( TT( (*data)[pos] ) == TT( 0 ) ) {
                for(;pos<indices->size()-1;++pos) {
                    (*data)[pos] = (*data)[pos+1];
                    (*indices)[pos] = (*indices)[pos+1];
                }
                data->pop_back();
                indices->pop_back();
            }
        }
        else  {
            TT r = op((TT)0,v);
            if ( r != TT( 0 ) ) {
                // creation
                indices->new_elem();
                data->new_elem();
                for(int e=indices->size()-1;e>(int)pos;--e) {
                    (*data)[e] = (*data)[e-1];
                    (*indices)[e] = (*indices)[e-1];
                }
                (*indices)[pos] = i;
                (*data)[pos] = op(TT(0),v);
                found = true;
            }
        }
    }
    Vec<unsigned> *indices;
    Vec<TT> *data;
    unsigned pos;
    bool found;
    unsigned i;
};

/*!
Cette classe permet de construire des vecteurs creux : cad si le vecteur a de nombreux éléments nuls, il est préférable de choisir ce format de stockage.
Voici un exemple d'utilisation :
    \code C/C++
        Vec<Sparse<float> > vs;
        Vec<Sparse<std::string>,10> vsf; // au plus dix éléments non nuls (nombre maximal fixé à la compilation).
        Vec<int> plage ;
        std::string residu;

        vsf.set(1000,"fee clochette");
        residu = vsf.get( 1000 ); // où bien residu = vsf[1000];




    \relates Vec
    \friend samir.amrouche@lmt.ens-cachan.fr
*/
template<class TT,int static_size_>
class Vec<Sparse<TT>,static_size_> {
public:
    template<unsigned n> struct SubType { typedef TT T; };
    static const unsigned nb_sub_type = 1;

    static const int static_size = static_size_;
    static const bool fixed_size = ( static_size_ >= 0 );
    static const int sparsity_rate = 2;

    struct inc_index_access {
        inc_index_access():j(0) {}
        DelayedAssignement<DelayedAssignementSparseSource<TT> > operator[](unsigned i) {
            DelayedAssignement<DelayedAssignementSparseSource<TT> > da;
            while ( j < vec->indices.size() && vec->indices[j] < i ) ++j;
            if ( j < vec->indices.size() && vec->indices[j] == i ) {
                da.source.data = &vec->data; da.source.indices = &vec->indices; da.source.pos = j; da.source.found = true; return da;
            }
            da.source.data = &vec->data; da.source.indices = &vec->indices; da.source.pos = j; da.source.found = false; da.source.i = i; return da;
        }
        TT operator[](unsigned i) const {
            while ( j < vec->indices.size() && vec->indices[j] < i ) ++j;
            if ( j < vec->indices.size() && vec->indices[j] == i ) return vec->data[j];
            return TT(0);
        }
        Vec *vec;
        mutable unsigned j;
    };
    struct inc_index_access_const {
        inc_index_access_const():j(0) {}
        TT operator[](unsigned i) const {
            while ( j < s && indices[j] < i ) ++j;
            if ( j < s && indices[j] == i ) return data[j];
            return TT(0);
        }
        const unsigned *indices;
        const TT *data;
        unsigned s;
        mutable unsigned j;
    };
    inc_index_access begin_inc_index_access() { inc_index_access res; res.vec = this; return res; } /// iter[i] gives the i-th element
    inc_index_access_const begin_inc_index_access_const() const { inc_index_access_const res; res.data=data.ptr(); res.indices=indices.ptr(); res.s=data.size(); return res; } /// iter[i] gives the i-th element

    struct Assign { template<class T2> void operator()(const T2 &val,unsigned ind,Vec &th) const { if (val==0) return; th.indices.push_back(ind); th.data.push_back(val); } };
    friend struct Assign;
    template<class T2,int s2> Vec &operator=(const Vec<T2,s2> &v) { DEBUGASSERT(v.size()==size()); indices.free(); data.free(); apply_nz(v,Assign(),*this); return *this; }

    template<class T2> Vec(const Vec<Sparse<T2> > &v) { indices = v.indices; data = v.data; }

    typedef DelayedAssignement<DelayedAssignementSparseSource<TT> > RetOp;
    typedef TT RetOpConst;

    void throw_ref_and_clear( Vec &res ) {
        data   .throw_ref_and_clear( res.data    );
        indices.throw_ref_and_clear( res.indices );
        si     .throw_val_and_clear( res.si      );
    }

    RetOp operator[](unsigned i) {
        DEBUGASSERT( i < size() );

        RetOp da;
        unsigned b = 0, e = indices.size();
        while ( e-b > 3 ) {
            unsigned m = (b+e)/2;
            if ( indices[m] < i )      b = m;
            else if ( indices[m] > i ) e = m;
            else { da.source.data = &data; da.source.indices = &indices; da.source.pos = m; da.source.found = true; return da; }
        }
        for( ;b<e && indices[b]<=i; ++b ) {
            if ( indices[b] == i ) {
                da.source.data = &data; da.source.indices = &indices; da.source.pos = b; da.source.found = true; return da;
            }
        }
        da.source.found = false; da.source.data = &data; da.source.indices = &indices; da.source.pos = b; da.source.i = i;
        return da;
    } /// access to element i
    RetOpConst operator[](unsigned i) const {
        DEBUGASSERT( i < size() );
        unsigned b = 0, e = indices.size();
        while ( e-b > 3 ) {
            unsigned m = (b+e)/2;
            if ( indices[m] == i ) return data[ m ];
            if ( indices[m] > i ) e = m;
            else                  b = m;
        }
        for( ;b<e && indices[b]<=i; ++b )
            if ( indices[b] == i ) return data[ b ];
        return RetOpConst(0);
    } /// access to element i
    TT get(unsigned i) const { return operator[](i); } /// calling get() ensures that the this is the const version of operator[] which is called
    void set(unsigned i,const TT v) { operator[](i)=v; } /// set element i
    unsigned size() const { return si.val; }

    template<class T2>
    Vec &operator=( const Vec<T2> &v ) {
        for(unsigned i=0;i<v.size();++i)
            operator[]( i ) = v[ i ];
        return *this;
    }

    /// reserve n indices and n data
    void reserve(unsigned n) { indices.reserve(n); data.reserve(n); }

    template<class T2> Vec &operator*=(const T2 &v) { data *= v; return *this; }
    template<class T2> Vec &operator/=(const T2 &v) { data /= v; return *this; }
    template<class T2> Vec &operator%=(const T2 &v) { data %= v; return *this; }
    template<class T2> Vec &operator&=(const T2 &v) { data &= v; return *this; }

    template<class T2,int s2> Vec &operator*=(const Vec<T2,s2> &v) { data *= v; return *this; }
    template<class T2,int s2> Vec &operator/=(const Vec<T2,s2> &v) { data /= v; return *this; }
    template<class T2,int s2> Vec &operator%=(const Vec<T2,s2> &v) { data %= v; return *this; }
    template<class T2,int s2> Vec &operator&=(const Vec<T2,s2> &v) { data &= v; return *this; }


    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,true >,s2> operator[](const Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,true>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2> operator[](const Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2> operator[](Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2> operator[](Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2>(*this,v2); }
    

    Vec() { si.set( fixed_size * static_size_ ); } ///
    Vec(const SetSize &ss,unsigned s) { si.set(s); } ///
    void resize(unsigned ns) {
        if ( ns < si.val ) {
            while ( indices.size() && indices.back()>=ns ) {
                indices.pop_back();
                data.pop_back();
            }
        }
        si.set( ns );
    }
    void free() { indices.free(); data.free(); si.set(0); }
    void clear() { indices.free(); data.free(); }

    unsigned nb_non_zeros() const { return indices.size(); }
    inline unsigned ind(unsigned i) const { DEBUGASSERT(i<indices.size()); return indices[i]; }
    inline const TT &non_zero(unsigned i) const { DEBUGASSERT(i<indices.size()); return data[i]; }
    inline TT &non_zero(unsigned i) { DEBUGASSERT(i<indices.size()); return data[i]; }

    Vec<unsigned> indices;
    Vec<TT> data;
    StaticValIf<unsigned,fixed_size,static_size_> si;
};
  template<class TT,int s,class Op> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i]);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0);
        }
        op(v.data.back());
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0);
    }
     }
  template<class TT,int s,class Op> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i]);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0);
        }
        op(v.data.back());
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0);
    }
     }
  template<class TT,int s,class Op,class TP0> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0);
        }
        op(v.data.back(),p0);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0);
    }
     }
  template<class TT,int s,class Op,class TP0> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0);
        }
        op(v.data.back(),p0);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0);
    }
     }
  template<class TT,int s,class Op,class TP0> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0);
        }
        op(v.data.back(),p0);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0);
    }
     }
  template<class TT,int s,class Op,class TP0> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0);
        }
        op(v.data.back(),p0);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1);
        }
        op(v.data.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1);
        }
        op(v.data.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1);
        }
        op(v.data.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1);
        }
        op(v.data.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1);
        }
        op(v.data.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1);
        }
        op(v.data.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1);
        }
        op(v.data.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1);
        }
        op(v.data.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,p0,p1,p2);
        }
        op(v.data.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,p0,p1,p2);
    }
     }

  template<class TT,int s,class Op> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i]);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j);
        }
        op(v.data.back(),v.indices.back());
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j);
    } }
  template<class TT,int s,class Op> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i]);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j);
        }
        op(v.data.back(),v.indices.back());
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0);
        }
        op(v.data.back(),v.indices.back(),p0);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0);
        }
        op(v.data.back(),v.indices.back(),p0);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0);
        }
        op(v.data.back(),v.indices.back(),p0);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0);
        }
        op(v.data.back(),v.indices.back(),p0);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1);
        }
        op(v.data.back(),v.indices.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1);
        }
        op(v.data.back(),v.indices.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1);
        }
        op(v.data.back(),v.indices.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1);
        }
        op(v.data.back(),v.indices.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1);
        }
        op(v.data.back(),v.indices.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1);
        }
        op(v.data.back(),v.indices.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1);
        }
        op(v.data.back(),v.indices.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1);
        }
        op(v.data.back(),v.indices.back(),p0,p1);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { 
    if ( v.indices.size()==0 )
        for(unsigned j=0;j<v.size();++j)
            op((TT)0,j,p0,p1,p2);
    else {
        for(unsigned j=0;j<v.indices[0];++j)
            op((TT)0,j,p0,p1,p2);
        for(unsigned i=0;i<v.indices.size()-1;++i) {
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<v.indices[i+1];++j)
                op(0,j,p0,p1,p2);
        }
        op(v.data.back(),v.indices.back(),p0,p1,p2);
        for(unsigned j=v.indices.back()+1;j<v.si.val;++j)
            op((TT)0,j,p0,p1,p2);
    } }

  template<class TT,int s,class Op> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op) { if (v.indices.size()<v.size() && op(0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i]) ) return true; return false; }
  template<class TT,int s,class Op> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op) { if (v.indices.size()<v.size() && op(0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i]) ) return true; return false; }
  template<class TT,int s,class Op> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op) { if (v.indices.size()<v.size() && op(0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i]) ) return true; return false; }
  template<class TT,int s,class Op> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op) { if (v.indices.size()<v.size() && op(0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i]) ) return true; return false; }
  template<class TT,int s,class Op,class TP0> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0) { if (v.indices.size()<v.size() && op(0,p0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) ) return true; return false; }
  template<class TT,int s,class Op,class TP0> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0) { if (v.indices.size()<v.size() && op(0,p0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) ) return true; return false; }
  template<class TT,int s,class Op,class TP0> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0) { if (v.indices.size()<v.size() && op(0,p0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) ) return true; return false; }
  template<class TT,int s,class Op,class TP0> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0) { if (v.indices.size()<v.size() && op(0,p0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) ) return true; return false; }
  template<class TT,int s,class Op,class TP0> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0) { if (v.indices.size()<v.size() && op(0,p0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) ) return true; return false; }
  template<class TT,int s,class Op,class TP0> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0) { if (v.indices.size()<v.size() && op(0,p0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) ) return true; return false; }
  template<class TT,int s,class Op,class TP0> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0) { if (v.indices.size()<v.size() && op(0,p0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) ) return true; return false; }
  template<class TT,int s,class Op,class TP0> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0) { if (v.indices.size()<v.size() && op(0,p0) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { if (v.indices.size()<v.size() && op(0,p0,p1) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline bool find(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { if (v.indices.size()<v.size() && op(0,p0,p1,p2) ) return true; for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) ) return true; return false; }

  template<class TT,int s,class Op> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i]);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0);
        }
        if ( v.indices[i] < to )
            op(v.data[i]);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0);
    } }
  template<class TT,int s,class Op> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i]);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0);
        }
        if ( v.indices[i] < to )
            op(v.data[i]);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0);
    } }
  template<class TT,int s,class Op> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i]);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0);
        }
        if ( v.indices[i] < to )
            op(v.data[i]);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0);
    } }
  template<class TT,int s,class Op> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i]);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0);
        }
        if ( v.indices[i] < to )
            op(v.data[i]);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,p0,p1,p2);
    } }

  template<class TT,int s,class Op> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i]);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i]);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j);
    } }
  template<class TT,int s,class Op> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i]);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i]);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j);
    } }
  template<class TT,int s,class Op> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i]);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i]);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j);
    } }
  template<class TT,int s,class Op> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i]);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i]);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(const Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_range_wi(Vec<Sparse<TT>,s,int> &v,int from,int to,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { DEBUGASSERT(to<v.si.val);
    if ( v.indices.size()==0 )
        for(;from<to;++from)
            op((TT)0,from,p0,p1,p2);
    else {
        unsigned i = 0;
        for(;i<v.indices.size() && v.indices[i]<from;++i);
        for(unsigned j=from;j<min(v.indices[i],to);++j)
            op((TT)0,j,p0,p1,p2);
        for(;i<v.indices.size()-1;++i) {
            if ( v.indices[i] >= to )
                break;
            op(v.data[i],v.indices[i],p0,p1,p2);
            for(unsigned j=v.indices[i]+1;j<min(v.indices[i+1],to);++j)
                op(0,j,p0,p1,p2);
        }
        if ( v.indices[i] < to )
            op(v.data[i],v.indices[i],p0,p1,p2);
        for(unsigned j=v.indices[i]+1;j<to;++j)
            op((TT)0,j,p0,p1,p2);
    } }

  template<class TT,int s,class Op> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i]); }
  template<class TT,int s,class Op> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i]); }
  template<class TT,int s,class Op> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i]); }
  template<class TT,int s,class Op> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i]); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],p0,p1,p2); }

  template<class TT,int s,class Op> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i]); }
  template<class TT,int s,class Op> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i]); }
  template<class TT,int s,class Op> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i]); }
  template<class TT,int s,class Op> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i]); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0); }
  template<class TT,int s,class Op,class TP0> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(const Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void apply_nz_wi(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) op(v.data[i],v.indices[i],p0,p1,p2); }

  template<class TT,int s,class Op> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i]) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i]) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }
  template<class TT,int s,class Op,class TP0,class TP1,class TP2> inline void filter_sp(Vec<Sparse<TT>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { for(unsigned i=0;i<v.indices.size();++i) if ( op(v.data[i],p0,p1,p2) == false ) { v.indices.erase_elem_nb(i); v.data.erase_elem_nb(i); }  }


/// ajout de Raphaël. Position provisoire
template<class TT > void swap(Vec<Sparse<TT> > &v1, Vec<Sparse<TT> > &v2) {
    swap( v1.indices      , v2.indices       );
    swap( v1.data        , v2.data         );
    swap( v1.si        , v2.si         );
}

}
