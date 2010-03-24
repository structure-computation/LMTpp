
namespace LMT {

struct ExtractDiag {};
struct ExtractRow {};
struct ExtractCol {};

/**
    TypeSubPart can be either Diag, Row or column
*/
template<class TM,bool const_tm,class TypeSubPart>
struct VecSubMat {};

template<class TM,bool const_tm,class TypeSubPart> struct IsVecOp<VecSubMat<TM,const_tm,TypeSubPart> > { typedef int T; };




template<class TM,bool const_tm,int static_size_>
class Vec<VecSubMat<TM,const_tm,ExtractDiag>,static_size_,int> {
public:
    typedef typename TM::T T0;
    template<unsigned n> struct SubType { typedef T0 T; };
    static const unsigned nb_sub_type = 1;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 0;

    typedef Vec& inc_index_access;
    typedef const Vec& inc_index_access_const;
    inc_index_access begin_inc_index_access() { return *this; } /// iter[i] gives the i-th element
    inc_index_access_const begin_inc_index_access_const() const { return *this; } /// iter[i] gives the i-th element
    
    Vec(const TM &mm) {
        m.val = &mm;
        
    }
    Vec(TM &mm) {
        m.val = &mm;
        
    }
    Vec( const Vec<VecSubMat<TM,false,ExtractDiag>,static_size_,int> &m2 ) { m.val=m2.m.val;  }
    
    
    unsigned size() const { return min(m.val->nb_rows(),m.val->nb_cols()); }

    typename TM::RetOpConst operator[](unsigned i) const { return (*m.val)(i,i); }
    typename TM::RetOp operator[](unsigned i) { return (*m.val)(i,i); }
    // void set(unsigned i,const T &val) { (*m.val)(i,i) = val; }
    
    Vec operator=(const Vec &v) { for(unsigned i=0;i<size();++i) operator[](i) = v[ i ]; return *this; }
    
    template<class T2> Vec operator=(const T2 &v) { for(unsigned i=0;i<size();++i) operator[](i) = v; return *this; }
    template<class T2,int s2,class IO> Vec operator=(const Vec<T2,s2,IO> &v) { for(unsigned i=0;i<size();++i) operator[](i) = v[i]; return *this; }

                                                          
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
    

    PtrConstIf<TM,const_tm> m;
    
};


template<class TM,bool const_tm,int static_size_>
class Vec<VecSubMat<TM,const_tm,ExtractRow>,static_size_,int> {
public:
    typedef typename TM::T T0;
    template<unsigned n> struct SubType { typedef T0 T; };
    static const unsigned nb_sub_type = 1;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 0;

    typedef Vec& inc_index_access;
    typedef const Vec& inc_index_access_const;
    inc_index_access begin_inc_index_access() { return *this; } /// iter[i] gives the i-th element
    inc_index_access_const begin_inc_index_access_const() const { return *this; } /// iter[i] gives the i-th element
    
    Vec(const TM &mm,unsigned nums) {
        m.val = &mm;
        s = nums;
    }
    Vec(TM &mm,unsigned nums) {
        m.val = &mm;
        s = nums;
    }
    Vec( const Vec<VecSubMat<TM,false,ExtractRow>,static_size_,int> &m2 ) { m.val=m2.m.val; s = m2.s; }
    
    
    unsigned size() const { return m.val->nb_cols(); }

    typename TM::RetOpConst operator[](unsigned i) const { return (*m.val)(s,i); }
    typename TM::RetOp operator[](unsigned i) { return (*m.val)(s,i); }
    // void set(unsigned i,const T &val) { (*m.val)(s,i) = val; }
    
    Vec operator=(const Vec &v) { for(unsigned i=0;i<size();++i) operator[](i) = v[ i ]; return *this; }
    
    template<class T2> Vec operator=(const T2 &v) { for(unsigned i=0;i<size();++i) operator[](i) = v; return *this; }
    template<class T2,int s2,class IO> Vec operator=(const Vec<T2,s2,IO> &v) { for(unsigned i=0;i<size();++i) operator[](i) = v[i]; return *this; }

                                                          
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
    

    PtrConstIf<TM,const_tm> m;
    unsigned s;
};


template<class TM,bool const_tm,int static_size_>
class Vec<VecSubMat<TM,const_tm,ExtractCol>,static_size_,int> {
public:
    typedef typename TM::T T0;
    template<unsigned n> struct SubType { typedef T0 T; };
    static const unsigned nb_sub_type = 1;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size_>=0);
    static const int sparsity_rate = 0;

    typedef Vec& inc_index_access;
    typedef const Vec& inc_index_access_const;
    inc_index_access begin_inc_index_access() { return *this; } /// iter[i] gives the i-th element
    inc_index_access_const begin_inc_index_access_const() const { return *this; } /// iter[i] gives the i-th element
    
    Vec(const TM &mm,unsigned nums) {
        m.val = &mm;
        s = nums;
    }
    Vec(TM &mm,unsigned nums) {
        m.val = &mm;
        s = nums;
    }
    Vec( const Vec<VecSubMat<TM,false,ExtractCol>,static_size_,int> &m2 ) { m.val=m2.m.val; s = m2.s; }
    
    
    unsigned size() const { return m.val->nb_rows(); }

    typename TM::RetOpConst operator[](unsigned i) const { return (*m.val)(i,s); }
    typename TM::RetOp operator[](unsigned i) { return (*m.val)(i,s); }
    // void set(unsigned i,const T &val) { (*m.val)(i,s) = val; }
    
    Vec operator=(const Vec &v) { for(unsigned i=0;i<size();++i) operator[](i) = v[ i ]; return *this; }
    
    template<class T2> Vec operator=(const T2 &v) { for(unsigned i=0;i<size();++i) operator[](i) = v; return *this; }
    template<class T2,int s2,class IO> Vec operator=(const Vec<T2,s2,IO> &v) { for(unsigned i=0;i<size();++i) operator[](i) = v[i]; return *this; }

                                                          
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
    

    PtrConstIf<TM,const_tm> m;
    unsigned s;
};


} // namespace LMT

