
namespace LMT {

/*!
\generic_comment generate

    Commme \a apply cette fonction permet d'appliquer un opérateur à tous les éléments d'un vecteur mais contrairement à \a apply elle ne modifie pas le vecteur et renvoie le vecteur résultat.
    Sa syntaxe générale est :
    \code
        vecteur generate( vecteur, opérateur, éventuellement un paramètre de l'opérateur) // opérateur unaire
        vecteur generate( vecteur1, vecteur2, opérateur, éventuellement un paramètre de l'opérateur)  // opérateur binaire
        vecteur generate( vecteur1, vecteur2, vecteur3, opérateur, éventuellement un paramètre de l'opérateur)  // opérateur ternaire

    Exemple de code :
    \code C/C++
        int main() {
            Vec<double> v = range( 20 );
            PRINT( generate( v, cast_int(_1) / 2 ) ); // convertit les éléments en int puis calcule le quotient de la division euclidienne et enfin renvoie le résultat dans un vecteur. _1 représente l'élément courant.
            apply( v, _1 -= sin(_1) ); // cette fois-ci, v est modifié.
            PRINT( v ); 
        }

    \relates Vec
    \relates apply 

    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \Author Hugo Leclerc
*/

/*!
\generic_comment lambda-calcul

    Avec toutes les fonctions de manipulation de vecteurs comme \a apply , \a generate , \a find , \a remove_if , etc...  on peut se passer de la création d'un opérateur en utilisant les variables _1, _2, ... et les opérations, fonctions standards  comme +, -, *, /, sin, etc...
        * _1 désigne l'élément courant,
        * _2 représente le premier paramètre de l'opérateur,
        * _3 représente le deuxième paramètre, etc...

    Sa syntaxe générale est :
    \code
        vecteur fonction( vecteur, expression avec _1, -2, ...  , éventuellement les paramètres de l'opérateur) 

    Exemple de code :
    \code C/C++
        remove_if(v, _1 > _2, 100); // cette instruction supprime tous les éléments supérieur à 100.


    \relates Vec
    \relates apply 

    \keyword lambda-calcul
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \Author Hugo Leclerc
*/


template<class Op,unsigned nb_v,class V1,bool br1,class V2=void,bool br2=true,class V3=void,bool br3=true> class VecOp {};

template<class Op,unsigned nb_v,class V1,bool br1,class V2,bool br2,class V3,bool br3> struct IsVecOp<VecOp<Op,nb_v,V1,br1,V2,br2,V3,br3> > { typedef int T; };


template<class OP,class V0,bool br0,int static_size_> struct VecSupportSIMD<Vec<VecOp<OP,1,V0,br0>,static_size_,int> > { static const unsigned res = OpSupportSIMD<OP>::res && VecSupportSIMD<V0>::res; };

/// range
template<class OP,class V0,bool br0,int static_size_>
class Vec<VecOp<OP,1,V0,br0>,static_size_,int> {
public:
    template<unsigned n,unsigned inner=0> struct SubType {
        typedef typename TypePromote<OP,typename V0::template SubType<n>::T>::T T;
    };
    template<unsigned inner> struct SubType<1,inner> { typedef void T; };
    static const unsigned nb_sub_type = V0::nb_sub_type;
    typedef typename SubType<0>::T T0;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size>=0);
    static const int sparsity_rate = ConserveZeroes<OP>::res * V0::sparsity_rate;
    
    int get_sparsity_rate() const { return sparsity_rate; }
    void resize(unsigned s) const { DEBUGASSERT( s == size() ); }
    
    Vec(const V0 &vv0,const OP &o=OP()):v0(vv0),op(o) {}
    Vec(V0 &vv0,const OP &o=OP()):v0(vv0),op(o) {}
    T0 operator[](unsigned i) const { return op(v0.val[i]); }
    T0 get(unsigned i) const { return op(v0.val[i]); }
    template<unsigned ne> SimdVec<T0,ne> simd(unsigned i,const Number<ne> &NE) const { return op(v0.val.simd(i,NE)); }
    
    unsigned size() const { return v0.val.size(); }

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
    


private:
//    template<class Op> struct ApplyNZ2 {
//        ApplyNZ2() {  }
//        template<class T1,class T2> void operator()(const T1 &val,unsigned i) {
//        }
//        Op *op;
//        inc_index_access_const ind;
//    };

public:

    StoreByRefIf<V0,br0> v0;
    OP op;
};

/*! Ex : generate( v0, _1 * 2 ) ( which can be written v*2 ). Usefull to generate a Vec<VecOp,s> without worrying about typedef and so on
    \relates Vec
*/
template<class TT0,int s0,class Op> Vec<VecOp<Op,1,Vec<TT0,s0>,true> >
generate( const Vec<TT0,s0> &v0,const Op &op ) {
    return Vec<VecOp<Op,1,Vec<TT0,s0>,true> >(v0,op);
}


template<class OP,class V0,bool br0,class V1,bool br1,int static_size_> struct VecSupportSIMD<Vec<VecOp<OP,2,V0,br0,V1,br1>,static_size_,int> > { static const unsigned res = OpSupportSIMD<OP>::res && VecSupportSIMD<V0>::res && VecSupportSIMD<V1>::res; };

/// range
template<class OP,class V0,bool br0,class V1,bool br1,int static_size_>
class Vec<VecOp<OP,2,V0,br0,V1,br1>,static_size_,int> {
public:
    template<unsigned n,unsigned inner=0> struct SubType {
        typedef typename TypePromote<OP,typename V0::template SubType<n>::T,typename V1::template SubType<n>::T>::T T;
    };
    template<unsigned inner> struct SubType<1,inner> { typedef void T; };
    static const unsigned nb_sub_type = V0::nb_sub_type;
    typedef typename SubType<0>::T T0;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size>=0);
    static const int sparsity_rate = (ConserveZeroes<OP>::res==0) * MIN(V0::sparsity_rate,V1::sparsity_rate) + (ConserveZeroes<OP>::res==1) * MAX(V0::sparsity_rate,V1::sparsity_rate);
    
    int get_sparsity_rate() const { return sparsity_rate; }
    void resize(unsigned s) const { DEBUGASSERT( s == size() ); }
    
    Vec(const V0 &vv0,const V1 &vv1,const OP &o=OP()):v0(vv0),v1(vv1),op(o) {}
    Vec(V0 &vv0,V1 &vv1,const OP &o=OP()):v0(vv0),v1(vv1),op(o) {}
    T0 operator[](unsigned i) const { return op(v0.val[i],v1.val[i]); }
    T0 get(unsigned i) const { return op(v0.val[i],v1.val[i]); }
    template<unsigned ne> SimdVec<T0,ne> simd(unsigned i,const Number<ne> &NE) const { return op(v0.val.simd(i,NE),v1.val.simd(i,NE)); }
    
    unsigned size() const { return v0.val.size(); }

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
    
    operator bool() const { return CastBool<OP>::cast_bool(*this,v0.val.size(),v1.val.size()); }

private:
//    template<class Op> struct ApplyNZ2 {
//        ApplyNZ2() {  }
//        template<class T1,class T2> void operator()(const T1 &val,unsigned i) {
//        }
//        Op *op;
//        inc_index_access_const ind;
//    };

public:

    StoreByRefIf<V0,br0> v0;
    StoreByRefIf<V1,br1> v1;
    OP op;
};

/*! Ex : generate( v0, v1, _1 * 2 ) ( which can be written v*2 ). Usefull to generate a Vec<VecOp,s> without worrying about typedef and so on
    \relates Vec
*/
template<class TT0,int s0,class TT1,int s1,class Op> Vec<VecOp<Op,2,Vec<TT0,s0>,true,Vec<TT1,s1>,true> >
generate( const Vec<TT0,s0> &v0,const Vec<TT1,s1> &v1,const Op &op ) {
    return Vec<VecOp<Op,2,Vec<TT0,s0>,true,Vec<TT1,s1>,true> >(v0,v1,op);
}


template<class OP,class V0,bool br0,class V1,bool br1,class V2,bool br2,int static_size_> struct VecSupportSIMD<Vec<VecOp<OP,3,V0,br0,V1,br1,V2,br2>,static_size_,int> > { static const unsigned res = OpSupportSIMD<OP>::res && VecSupportSIMD<V0>::res && VecSupportSIMD<V1>::res && VecSupportSIMD<V2>::res; };

/// range
template<class OP,class V0,bool br0,class V1,bool br1,class V2,bool br2,int static_size_>
class Vec<VecOp<OP,3,V0,br0,V1,br1,V2,br2>,static_size_,int> {
public:
    template<unsigned n,unsigned inner=0> struct SubType {
        typedef typename TypePromote<OP,typename V0::template SubType<n>::T,typename V1::template SubType<n>::T,typename V2::template SubType<n>::T>::T T;
    };
    template<unsigned inner> struct SubType<1,inner> { typedef void T; };
    static const unsigned nb_sub_type = V0::nb_sub_type;
    typedef typename SubType<0>::T T0;
    
    static const int static_size = static_size_;
    static const bool fixed_size = (static_size>=0);
    static const int sparsity_rate = MIN(V0::sparsity_rate,MIN(V1::sparsity_rate,V2::sparsity_rate));
    
    int get_sparsity_rate() const { return sparsity_rate; }
    void resize(unsigned s) const { DEBUGASSERT( s == size() ); }
    
    Vec(const V0 &vv0,const V1 &vv1,const V2 &vv2,const OP &o=OP()):v0(vv0),v1(vv1),v2(vv2),op(o) {}
    Vec(V0 &vv0,V1 &vv1,V2 &vv2,const OP &o=OP()):v0(vv0),v1(vv1),v2(vv2),op(o) {}
    T0 operator[](unsigned i) const { return op(v0.val[i],v1.val[i],v2.val[i]); }
    T0 get(unsigned i) const { return op(v0.val[i],v1.val[i],v2.val[i]); }
    template<unsigned ne> SimdVec<T0,ne> simd(unsigned i,const Number<ne> &NE) const { return op(v0.val.simd(i,NE),v1.val.simd(i,NE),v2.val.simd(i,NE)); }
    
    unsigned size() const { return v0.val.size(); }

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
    


private:
//    template<class Op> struct ApplyNZ2 {
//        ApplyNZ2() {  }
//        template<class T1,class T2> void operator()(const T1 &val,unsigned i) {
//        }
//        Op *op;
//        inc_index_access_const ind;
//    };

public:

    StoreByRefIf<V0,br0> v0;
    StoreByRefIf<V1,br1> v1;
    StoreByRefIf<V2,br2> v2;
    OP op;
};

/*! Ex : generate( v0, v1, v2, _1 * 2 ) ( which can be written v*2 ). Usefull to generate a Vec<VecOp,s> without worrying about typedef and so on
    \relates Vec
*/
template<class TT0,int s0,class TT1,int s1,class TT2,int s2,class Op> Vec<VecOp<Op,3,Vec<TT0,s0>,true,Vec<TT1,s1>,true,Vec<TT2,s2>,true> >
generate( const Vec<TT0,s0> &v0,const Vec<TT1,s1> &v1,const Vec<TT2,s2> &v2,const Op &op ) {
    return Vec<VecOp<Op,3,Vec<TT0,s0>,true,Vec<TT1,s1>,true,Vec<TT2,s2>,true> >(v0,v1,v2,op);
}


  template<class OP,class V0,bool const_v0,int s,class Op> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op)); }
  template<class OP,class V0,bool const_v0,int s,class Op> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op)); }
  template<class OP,class V0,bool const_v0,int s,class Op> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op)); }
  template<class OP,class V0,bool const_v0,int s,class Op> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op)); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,1,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { apply(v.v0.val,ALGOCompose1WithoutReturn<Op,0,OP,true>(op,v.op),p0,p1,p2); }

  template<class OP,class V0,bool const_v0,int s,class Op> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op) { OpWithIncrement<Op,1> opi(op); apply(v,opi); }
  template<class OP,class V0,bool const_v0,int s,class Op> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op) { OpWithIncrement<Op,1> opi(op); apply(v,opi); }
  template<class OP,class V0,bool const_v0,int s,class Op> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op) { OpWithIncrement<Op,0> opi(op); apply(v,opi); }
  template<class OP,class V0,bool const_v0,int s,class Op> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op) { OpWithIncrement<Op,0> opi(op); apply(v,opi); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,const TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,const TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,const TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,const Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,1> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(const Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }
  template<class OP,class V0,bool const_v0,int s,class Op,class TP0,class TP1,class TP2> inline void apply_wi(Vec<VecOp<OP,1,V0,const_v0>,s,int> &v,Op& op,TP0 &p0,TP1 &p1,TP2 &p2) { OpWithIncrement<Op,0> opi(op); apply(v,opi,p0,p1,p2); }

} // namespace LMT
