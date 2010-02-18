
namespace LMT {
template<class TV,class TSV,bool const_TV=true,bool storebyref_TSV=false> struct SubVec {};

template<class TV,class TSV,bool const_TV,bool storebyref_TSV> struct IsVecOp<SubVec<TV,TSV,const_TV,storebyref_TSV> > { typedef int T; };

template<class TV,class TSV,bool const_TV,bool storebyref_TSV,int static_size_>
class Vec<SubVec<TV,TSV,const_TV,storebyref_TSV>,static_size_,int> {
public:
    template<unsigned n> struct SubType { typedef typename TV::template SubType<n>::T T; };
    static const unsigned nb_sub_type = TV::nb_sub_type;
    typedef typename TV::template SubType<0>::T T0;
    
    static const int static_size = TSV::static_size;
    static const bool fixed_size = TSV::fixed_size;
    static const int sparsity_rate = 0;

    struct inc_index_access {
        inc_index_access(PtrConstIf<TV,const_TV> &v,StoreByRefIf<TSV,storebyref_TSV> &sv):val(v),sval(sv) {}
        T0 &operator[](unsigned i) { DEBUGASSERT(nb_sub_type==1); return (*val.val)[(unsigned)sval.val[i]]; }
        T0 operator[](unsigned i) const { DEBUGASSERT(nb_sub_type==1); return (*val.val)[(unsigned)sval.val[i]]; }
        PtrConstIf<TV,const_TV> val;
        StoreByRefIf<TSV,storebyref_TSV> sval;
    };
    struct inc_index_access_const {
        T0 operator[](unsigned i) const { DEBUGASSERT(nb_sub_type==1); return (*val)[(*sval)[i]]; }
        const TV *val;
        const TSV *sval;
    };
    inc_index_access begin_inc_index_access() { inc_index_access res(val,sval); return res; } /// iter[i] gives the i-th element
    inc_index_access_const begin_inc_index_access_const() const { inc_index_access_const res; res.val=val.val; res.sval=&sval.val; return res; } /// iter[i] gives the i-th element
    
    Vec(const TV &v,const TSV &sv):sval(sv) { val.val = &v; }
    Vec(const TV &v,TSV &sv):sval(sv) { val.val = &v; }
    Vec(TV &v,const TSV &sv):sval(sv) { val.val = &v; }
    Vec(TV &v,TSV &sv):sval(sv) { val.val = &v; }

    template<class T2> Vec &operator=(const T2 &val) { for(unsigned i=0;i<size();++i) set(i,val); return *this; }
    template<class T2,int s2> Vec &operator=(const Vec<T2,s2> &vec) { VECASSERTSAMESIZETHAN(vec,s2); for(unsigned i=0;i<size();++i) set(i,vec[i]); return *this; }
    
    T0 &operator[](unsigned i) { DEBUGASSERT(nb_sub_type==1); DEBUGASSERT(i<size()); return (*val.val)[(unsigned)sval.val[i]]; } /// access to element i
    T0 operator[](unsigned i) const { DEBUGASSERT(nb_sub_type==1); DEBUGASSERT(i<size()); return (*val.val)[(unsigned)sval.val[i]]; } /// access to element i
    T0 get(unsigned i) const { DEBUGASSERT(nb_sub_type==1); DEBUGASSERT(i<size()); return (*val.val)[(unsigned)sval.val[i]]; } /// calling get ensure that the const version is called (useful for SparseVec)
    void set(unsigned i,const T0 &v) { DEBUGASSERT(nb_sub_type==1); DEBUGASSERT(i<size()); val.val->set((unsigned)sval.val[i], v); } /// set element i
    
    template<class TTT> void set(const TTT &v) { for(unsigned i=0;i<size();++i) set(i,val); } /// set element i
    
    unsigned size() const { return sval.val.size(); }
    
                                                          
    template<class T2> Vec &operator+=(const T2 &val) { apply( *this, AssignSelfOp(), Plus() , val ); return *this; }
    template<class T2> Vec &operator-=(const T2 &val) { apply( *this, AssignSelfOp(), Minus(), val ); return *this; }
    template<class T2> Vec &operator^=(const T2 &val) { apply( *this, AssignSelfOp(), Xor()  , val ); return *this; }
    template<class T2> Vec &operator|=(const T2 &val) { apply( *this, AssignSelfOp(), Or()   , val ); return *this; }

    template<class T2,int s2,class INNER> Vec &operator+=(const Vec<T2,s2,INNER> &val) { apply_wi( *this, AssignSelfOp(), Plus() , val ); return *this; }
    template<class T2,int s2,class INNER> Vec &operator-=(const Vec<T2,s2,INNER> &val) { apply_wi( *this, AssignSelfOp(), Minus(), val ); return *this; }
    template<class T2,int s2,class INNER> Vec &operator^=(const Vec<T2,s2,INNER> &val) { apply_wi( *this, AssignSelfOp(), Xor()  , val ); return *this; }
    template<class T2,int s2,class INNER> Vec &operator|=(const Vec<T2,s2,INNER> &val) { apply_wi( *this, AssignSelfOp(), Or()   , val ); return *this; }
    
    template<class T2> Vec &operator*=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Multiplies(),va); return *this; }
    template<class T2> Vec &operator/=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Divides   (),va); return *this; }
    template<class T2> Vec &operator%=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Modulus   (),va); return *this; }
    template<class T2> Vec &operator&=(const T2 &va) { apply_nz(*this,AssignSelfOp(),And       (),va); return *this; }
    
    template<class T2,int s2,class INNER> Vec &operator*=(const Vec<T2,s2,INNER> &va) { apply_nz_wi(*this,AssignSelfOp(),Multiplies(),va); return *this; }
    template<class T2,int s2,class INNER> Vec &operator/=(const Vec<T2,s2,INNER> &va) { apply_nz_wi(*this,AssignSelfOp(),Divides   (),va); return *this; }
    template<class T2,int s2,class INNER> Vec &operator%=(const Vec<T2,s2,INNER> &va) { apply_nz_wi(*this,AssignSelfOp(),Modulus   (),va); return *this; }
    template<class T2,int s2,class INNER> Vec &operator&=(const Vec<T2,s2,INNER> &va) { apply_nz_wi(*this,AssignSelfOp(),And       (),va); return *this; }
    


    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,true >,s2> operator[](const Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,true>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2> operator[](const Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,true >,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2> operator[](Vec<TST,s2> &v2) { return Vec<SubVec<Vec,Vec<TST,s2>,false,false>,s2>(*this,v2); }
    template<class TST,int s2> Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2> operator[](Vec<TST,s2> &v2) const { return Vec<SubVec<Vec,Vec<TST,s2>,true ,false>,s2>(*this,v2); }
    

    // template<class T0,class Op> void operator()(const T0 &val,unsigned i,const Op &op) const { op((*val.val)[i]); }

    PtrConstIf<TV,const_TV> val;
    StoreByRefIf<TSV,storebyref_TSV> sval;
};


} // namespace LMT
