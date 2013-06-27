
#include "vecasm_decl.h"
#include "matlabhelp.h"

namespace LMT {
    template<class T,int s> struct VecSupportSIMD<Vec<T,s,void> > { static const unsigned res = true; };
}


namespace LMT {

/**
    Full vector. Elements are contiguous.
    \warning during resize, pop_back, ... and so on, location of data in memory may be moved. Use SplittedVector if you are pointer stability.
*/
/*!
    \brief vecteur a element contigus. Si la taille change , on preferera le type SplittedVector qui assure que le vecteur ne sera pas deplace en memoire apres trop d'ajouts.
    Full vector. Elements are contiguous.
    <strong> IMORTANT : during resize, pop_back, ... and so on, location of data in memory may be moved. Use SplittedVector if you are pointer stability. </strong>
    \friend samir.amrouche@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/

template<class TT,int static_size_>
class Vec<TT,static_size_,void> {
public:
    template<unsigned n,unsigned inner=0> struct SubType { typedef TT T; };
    template<unsigned inner> struct SubType<1,inner> { typedef void T; };
    static const unsigned nb_sub_type = 1;
    typedef int ST;

    static const int static_size = static_size_;
    static const bool fixed_size = true;
    static const int sparsity_rate = 0;
    

    Vec() {}
    template<class T2> Vec(const T2 &v) { for(unsigned i=0;i<(unsigned)static_size;val[i++]=v); } /// copy val in all elements of *this
    void get_data_from_ptr(const TT *v) { for(unsigned i=0;i<(unsigned)static_size;++i) val[i]=v[i]; } /// copy val in all elements of *this
    void assign_and_complete_with_last(const TT &v0) { val[0]=v0; for(unsigned i=1;i<size();++i) val[i]=v0; }
    Vec(const TT &v0,const TT &v1) { DEBUGASSERT(static_size_==2); val[0]=v0; val[1]=v1; } /// static_size_ must == 2
    void assign_and_complete_with_last(const TT &v0,const TT &v1) { val[0]=v0; val[1]=v1; for(unsigned i=2;i<size();++i) val[i]=v1; }
    Vec(const TT &v0,const TT &v1,const TT &v2) { DEBUGASSERT(static_size_==3); val[0]=v0; val[1]=v1; val[2]=v2; } /// static_size_ must == 3
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2) { val[0]=v0; val[1]=v1; val[2]=v2; for(unsigned i=3;i<size();++i) val[i]=v2; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3) { DEBUGASSERT(static_size_==4); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; } /// static_size_ must == 4
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; for(unsigned i=4;i<size();++i) val[i]=v3; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4) { DEBUGASSERT(static_size_==5); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; } /// static_size_ must == 5
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; for(unsigned i=5;i<size();++i) val[i]=v4; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5) { DEBUGASSERT(static_size_==6); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; } /// static_size_ must == 6
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; for(unsigned i=6;i<size();++i) val[i]=v5; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6) { DEBUGASSERT(static_size_==7); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; } /// static_size_ must == 7
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; for(unsigned i=7;i<size();++i) val[i]=v6; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7) { DEBUGASSERT(static_size_==8); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; } /// static_size_ must == 8
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; for(unsigned i=8;i<size();++i) val[i]=v7; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8) { DEBUGASSERT(static_size_==9); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; } /// static_size_ must == 9
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; for(unsigned i=9;i<size();++i) val[i]=v8; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9) { DEBUGASSERT(static_size_==10); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; } /// static_size_ must == 10
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; for(unsigned i=10;i<size();++i) val[i]=v9; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10) { DEBUGASSERT(static_size_==11); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; } /// static_size_ must == 11
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; for(unsigned i=11;i<size();++i) val[i]=v10; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11) { DEBUGASSERT(static_size_==12); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; } /// static_size_ must == 12
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; for(unsigned i=12;i<size();++i) val[i]=v11; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12) { DEBUGASSERT(static_size_==13); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; } /// static_size_ must == 13
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; for(unsigned i=13;i<size();++i) val[i]=v12; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13) { DEBUGASSERT(static_size_==14); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; } /// static_size_ must == 14
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; for(unsigned i=14;i<size();++i) val[i]=v13; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14) { DEBUGASSERT(static_size_==15); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; } /// static_size_ must == 15
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; for(unsigned i=15;i<size();++i) val[i]=v14; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15) { DEBUGASSERT(static_size_==16); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; } /// static_size_ must == 16
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; for(unsigned i=16;i<size();++i) val[i]=v15; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16) { DEBUGASSERT(static_size_==17); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; } /// static_size_ must == 17
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; for(unsigned i=17;i<size();++i) val[i]=v16; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17) { DEBUGASSERT(static_size_==18); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; } /// static_size_ must == 18
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; for(unsigned i=18;i<size();++i) val[i]=v17; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18) { DEBUGASSERT(static_size_==19); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; } /// static_size_ must == 19
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; for(unsigned i=19;i<size();++i) val[i]=v18; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19) { DEBUGASSERT(static_size_==20); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; } /// static_size_ must == 20
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; for(unsigned i=20;i<size();++i) val[i]=v19; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20) { DEBUGASSERT(static_size_==21); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; } /// static_size_ must == 21
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; for(unsigned i=21;i<size();++i) val[i]=v20; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21) { DEBUGASSERT(static_size_==22); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; } /// static_size_ must == 22
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; for(unsigned i=22;i<size();++i) val[i]=v21; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22) { DEBUGASSERT(static_size_==23); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; } /// static_size_ must == 23
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; for(unsigned i=23;i<size();++i) val[i]=v22; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23) { DEBUGASSERT(static_size_==24); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; } /// static_size_ must == 24
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; for(unsigned i=24;i<size();++i) val[i]=v23; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24) { DEBUGASSERT(static_size_==25); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; } /// static_size_ must == 25
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; for(unsigned i=25;i<size();++i) val[i]=v24; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25) { DEBUGASSERT(static_size_==26); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; } /// static_size_ must == 26
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; for(unsigned i=26;i<size();++i) val[i]=v25; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26) { DEBUGASSERT(static_size_==27); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; } /// static_size_ must == 27
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; for(unsigned i=27;i<size();++i) val[i]=v26; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27) { DEBUGASSERT(static_size_==28); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; } /// static_size_ must == 28
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; for(unsigned i=28;i<size();++i) val[i]=v27; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28) { DEBUGASSERT(static_size_==29); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; } /// static_size_ must == 29
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; for(unsigned i=29;i<size();++i) val[i]=v28; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29) { DEBUGASSERT(static_size_==30); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; } /// static_size_ must == 30
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; for(unsigned i=30;i<size();++i) val[i]=v29; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30) { DEBUGASSERT(static_size_==31); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; } /// static_size_ must == 31
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; for(unsigned i=31;i<size();++i) val[i]=v30; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31) { DEBUGASSERT(static_size_==32); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; } /// static_size_ must == 32
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; for(unsigned i=32;i<size();++i) val[i]=v31; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32) { DEBUGASSERT(static_size_==33); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; } /// static_size_ must == 33
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; for(unsigned i=33;i<size();++i) val[i]=v32; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33) { DEBUGASSERT(static_size_==34); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; } /// static_size_ must == 34
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; for(unsigned i=34;i<size();++i) val[i]=v33; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33,const TT &v34) { DEBUGASSERT(static_size_==35); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; val[34]=v34; } /// static_size_ must == 35
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33,const TT &v34) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; val[34]=v34; for(unsigned i=35;i<size();++i) val[i]=v34; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33,const TT &v34,const TT &v35) { DEBUGASSERT(static_size_==36); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; val[34]=v34; val[35]=v35; } /// static_size_ must == 36
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33,const TT &v34,const TT &v35) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; val[34]=v34; val[35]=v35; for(unsigned i=36;i<size();++i) val[i]=v35; }
    Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33,const TT &v34,const TT &v35,const TT &v36) { DEBUGASSERT(static_size_==37); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; val[34]=v34; val[35]=v35; val[36]=v36; } /// static_size_ must == 37
    void assign_and_complete_with_last(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33,const TT &v34,const TT &v35,const TT &v36) { val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; val[34]=v34; val[35]=v35; val[36]=v36; for(unsigned i=37;i<size();++i) val[i]=v36; }


    TT &front() { return val[0]; } /// first element
    const TT &front() const { return val[0]; } /// first element
    TT &back() { return val[size()-1]; } /// last element
    const TT &back() const { return val[size()-1]; } /// last element
    const TT *ptr() const { return val; }
    TT *ptr() { return val; }
    const TT *begin() const { return val; }
    TT *begin() { return val; }
    const TT *end() const { return val+size(); }
    TT *end() { return val+size(); }

    struct SetVal {
        template<class T2> void operator()(const T2 &v,unsigned i,TT *val) const { val[i] = (TT)v; }
        template<class T2> void operator()(const T2 &v1,const T2 &v2,const T2 &v3,const T2 &v4,unsigned i,TT *val) const { val[i+3] = (TT)v1; val[i+2] = (TT)v2; val[i+1] = (TT)v3; val[i+0] = (TT)v4; }
        template<class T2,unsigned ne> void operator()(const SimdVec<T2,ne> &v,unsigned i,TT *val) const { reinterpret_cast<SimdVec<TT,ne> &>(val[i]) = v; }
        template<class T2,unsigned ne> void operator()(const SimdVec<T2,ne> &v1,const SimdVec<T2,ne> &v2,const SimdVec<T2,ne> &v3,const SimdVec<T2,ne> &v4,unsigned i,TT *val) const {
            reinterpret_cast<SimdVec<TT,ne> &>(val[i+3*ne]) = v1;
            reinterpret_cast<SimdVec<TT,ne> &>(val[i+2*ne]) = v2;
            reinterpret_cast<SimdVec<TT,ne> &>(val[i+1*ne]) = v3;
            reinterpret_cast<SimdVec<TT,ne> &>(val[i+0*ne]) = v4;
        }
    };

    template<class T2,int s1,class IO1> Vec(const Vec<T2,s1,IO1> &vec) { DEBUGASSERT(s1<0 or s1==static_size); DEBUGASSERT((unsigned)static_size==vec.size());
         if ( static_size>=0 ) {
             for(unsigned i=0;i<min((unsigned)static_size,vec.size());++i)
                 val[i] = (TT)vec[i];
         }
         else
            apply_simd_wi(vec,SetVal(),val);
    } /// copy constructor
    Vec(const Vec &vec) { init(); resize(vec.size()); for(unsigned i=0;i<size();++i) val[i] = vec[i]; } /// copy constructor
    template<class T2,int s1> Vec &operator=(const Vec<T2,s1> &vec) { DEBUGASSERT(s1<0 or s1==static_size); DEBUGASSERT((unsigned)static_size==vec.size());
        if ( static_size>=0 ) {
            for(unsigned i=0;i<min((unsigned)static_size,vec.size());++i)
                val[i] = (TT)vec[i];
        }
        else
            apply_simd_wi(vec,SetVal(),val);
        return *this;
    }
    Vec &operator=(const Vec &vec) { 
        if ( static_size>=0 ) {
            for(unsigned i=0;i<min((unsigned)static_size,vec.size());++i)
                val[i] = (TT)vec[i];
        }
        else
            apply_simd_wi(vec,SetVal(),val);
        return *this;
    }
    Vec(std::istream &is) { init(); is >> *this; } /// get data from stream
    // Vec(const std::string &s) { init(); std::istringstream is(s); is >> *this; } /// get data from string

    template<class T2>
    void set( const T2 &v ) { for(unsigned i=0;i<size();++i) operator[]( i ) = v; }

    #ifdef MATLAB_MEX_FILE
        explicit Vec(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }
            if ( fixed_size && static_size!=mxGetN(variable) ) {
                PRINTM( "Error : Vec<...,"+to_string<static_size>()+">(const mxArray *variable) must take a vector of size "+to_string<static_size>() );
                throw std::runtime_error("size error");
            }

            init();
            resize( mxGetN(variable) * mxGetM(variable) );

            double *pr;
            pr = mxGetPr(variable);
            for(unsigned i=0;i<size();++i)
                val[i] = (TT)pr[i];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<size();++i)
                    set_imag(val[i],pr[i]);
            }
        } /// matlab -> LMT::Vec
        Vec &operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }
            if ( fixed_size && static_size!=mxGetN(variable) ) {
                PRINTM( "Error : Vec<...,"+to_string<static_size>()+">(const mxArray *variable) must take a vector of size "+to_string<static_size>() );
                throw std::runtime_error("size error");
            }

            resize( mxGetN(variable) * mxGetM(variable) );

            double *pr;
            pr = mxGetPr(variable);
            for(unsigned i=0;i<size();++i)
                val[i] = (TT)pr[i];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<size();++i)
                    set_imag(val[i],pr[i]);
            }
	    return *this;
        } /// matlab -> LMT::Vec
    #endif

    
    inline void resize(unsigned s) const { DEBUGASSERT( static_size_==s ); }
    inline void resize(unsigned s,const TT &val) { DEBUGASSERT( static_size_==s ); *this = val; }
    

    unsigned size_in_bytes() const { return sizeof(TT) * size(); }

    TT &operator[](unsigned i) { DEBUGASSERT(i<size()); return val[i]; } /// access to element i
    const TT &operator[](unsigned i) const { DEBUGASSERT(i<size()); return val[i]; } /// access to element i
    const TT &get(unsigned i) const { DEBUGASSERT(i<size()); return val[i]; } /// calling get ensure that the const version is called (useful for SparseVec)
    void set(unsigned i,const TT &v) { DEBUGASSERT(i<size()); val[i] = v; } /// set element i

    template<class ST> SimdVec<TT,2> operator[]( const SimdVec<ST,2> &ind ) const { return SimdVec<TT,2>(val[ind[0]],val[ind[1]]); } /// access to element ind[0], ind[1]...


    template<unsigned nne> SimdVec<TT,nne> &simd(unsigned i,const Number<nne> &) { return reinterpret_cast<SimdVec<TT,nne> &>(val[i]); }
    template<unsigned nne> const SimdVec<TT,nne> &simd(unsigned i,const Number<nne> &) const { return reinterpret_cast<const SimdVec<TT,nne> &>(val[i]); }

    unsigned size() const { return static_size_; }

    Vec operator-() const { Vec res = generate(*this,Negate()); return res; }

    /*
    template<class T2> Vec &operator*=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Multiplies(),va); return *this; }
    template<class T2> Vec &operator/=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Divides   (),va); return *this; }
    template<class T2> Vec &operator%=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Modulus   (),va); return *this; }
    template<class T2> Vec &operator&=(const T2 &va) { apply_nz(*this,AssignSelfOp(),And       (),va); return *this; }

    template<class T2,int s2> Vec &operator*=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),Multiplies(),va); return *this; }
    template<class T2,int s2> Vec &operator/=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),Divides   (),va); return *this; }
    template<class T2,int s2> Vec &operator%=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),Modulus   (),va); return *this; }
    template<class T2,int s2> Vec &operator&=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),And       (),va); return *this; }

    template<class T2> Vec &operator+=(const T2 &val) { apply_simd( *this, AssignSelfOp(), Plus() , val ); return *this; }
    template<class T2> Vec &operator-=(const T2 &val) { apply_simd( *this, AssignSelfOp(), Minus(), val ); return *this; }
    template<class T2> Vec &operator^=(const T2 &val) { apply_simd( *this, AssignSelfOp(), Xor()  , val ); return *this; }
    template<class T2> Vec &operator|=(const T2 &val) { apply_simd( *this, AssignSelfOp(), Or()   , val ); return *this; }

    template<class T2,int s2> Vec &operator+=(const Vec<T2,s2> &val) { apply_simd_wi( *this, AssignSelfOp(), Plus() , val ); return *this; }
    template<class T2,int s2> Vec &operator-=(const Vec<T2,s2> &val) { apply_simd_wi( *this, AssignSelfOp(), Minus(), val ); return *this; }
    template<class T2,int s2> Vec &operator^=(const Vec<T2,s2> &val) { apply_simd_wi( *this, AssignSelfOp(), Xor()  , val ); return *this; }
    template<class T2,int s2> Vec &operator|=(const Vec<T2,s2> &val) { apply_simd_wi( *this, AssignSelfOp(), Or()   , val ); return *this; }
    */
                                                          
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
    

    template<class T2> bool contains( const T2 &v ) const {
        for( unsigned i=0; i<size(); ++i )
            if ( val[i] == v )
                return true;
        return false;
    }
    
    template<class T2 > 
    unsigned find( const T2 &v ) const {
        for( unsigned i=0; i<size(); ++i )
            if ( val[i] == v )
                return i;
        return size();
    }

    template<class T2, class Cmp > 
    unsigned find( const T2 &v, Cmp cmp ) const {
        for( unsigned i=0; i<size(); ++i )
            if ( cmp( val[i], v ) )
                return i;
        return size();
    }

    Vec &set(const TT &v) { for(unsigned i=0;i<size();++i) val[i]=v; return *this; }

    /// return a Vec with random values in [0,1]. if s_dim==-1, user must specify size, else size must be = s_dim
    static Vec random() { Vec res;  for(unsigned  i = 0; i < res.size(); res[i++] = TT(rand()/(double)RAND_MAX) ); return res; }

    /*!
    return
    \latex
        $$ [ \frac{ v \& 2^i }{ 2^i } ]_i $$

    if s_dim==-1, user must specify size, else size must be = s_dim
    */
    static Vec binary_decomp(unsigned v) {
        Vec res; 
        for(unsigned i=0,p2i=1;i<res.size();++i,p2i*=2) res[i] = bool( v & p2i );
        return res;
    }
private:
    
    TT val[static_size_];
    inline void init() const {}
    
};
}


namespace LMT {

/**
    Full vector. Elements are contiguous.
    \warning during resize, pop_back, ... and so on, location of data in memory may be moved. Use SplittedVector if you are pointer stability.
*/
/*!
    \brief vecteur a element contigus. Si la taille change , on preferera le type SplittedVector qui assure que le vecteur ne sera pas deplace en memoire apres trop d'ajouts.
    Full vector. Elements are contiguous.
    <strong> IMORTANT : during resize, pop_back, ... and so on, location of data in memory may be moved. Use SplittedVector if you are pointer stability. </strong>
    \friend samir.amrouche@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr
*/

template<class TT>
class Vec<TT,-1,void> {
public:
    template<unsigned n,unsigned inner=0> struct SubType { typedef TT T; };
    template<unsigned inner> struct SubType<1,inner> { typedef void T; };
    static const unsigned nb_sub_type = 1;
    typedef int ST;

    static const int static_size = -1;
    static const bool fixed_size = false;
    static const int sparsity_rate = 0;
    typedef typename PreferredAllocator<TT>::T Allocator;

    Vec() { init(); }
    explicit Vec(const TT &v0) { init(); resize(1); val[0]=v0; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1) { init(); resize(2); val[0]=v0; val[1]=v1; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2) { init(); resize(3); val[0]=v0; val[1]=v1; val[2]=v2; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3) { init(); resize(4); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4) { init(); resize(5); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5) { init(); resize(6); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6) { init(); resize(7); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7) { init(); resize(8); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8) { init(); resize(9); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9) { init(); resize(10); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10) { init(); resize(11); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11) { init(); resize(12); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12) { init(); resize(13); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13) { init(); resize(14); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14) { init(); resize(15); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15) { init(); resize(16); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16) { init(); resize(17); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17) { init(); resize(18); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18) { init(); resize(19); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19) { init(); resize(20); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20) { init(); resize(21); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21) { init(); resize(22); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22) { init(); resize(23); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23) { init(); resize(24); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24) { init(); resize(25); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25) { init(); resize(26); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26) { init(); resize(27); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27) { init(); resize(28); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28) { init(); resize(29); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29) { init(); resize(30); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30) { init(); resize(31); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31) { init(); resize(32); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32) { init(); resize(33); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33) { init(); resize(34); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33,const TT &v34) { init(); resize(35); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; val[34]=v34; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33,const TT &v34,const TT &v35) { init(); resize(36); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; val[34]=v34; val[35]=v35; } /// declare a vector containing args
    explicit Vec(const TT &v0,const TT &v1,const TT &v2,const TT &v3,const TT &v4,const TT &v5,const TT &v6,const TT &v7,const TT &v8,const TT &v9,const TT &v10,const TT &v11,const TT &v12,const TT &v13,const TT &v14,const TT &v15,const TT &v16,const TT &v17,const TT &v18,const TT &v19,const TT &v20,const TT &v21,const TT &v22,const TT &v23,const TT &v24,const TT &v25,const TT &v26,const TT &v27,const TT &v28,const TT &v29,const TT &v30,const TT &v31,const TT &v32,const TT &v33,const TT &v34,const TT &v35,const TT &v36) { init(); resize(37); val[0]=v0; val[1]=v1; val[2]=v2; val[3]=v3; val[4]=v4; val[5]=v5; val[6]=v6; val[7]=v7; val[8]=v8; val[9]=v9; val[10]=v10; val[11]=v11; val[12]=v12; val[13]=v13; val[14]=v14; val[15]=v15; val[16]=v16; val[17]=v17; val[18]=v18; val[19]=v19; val[20]=v20; val[21]=v21; val[22]=v22; val[23]=v23; val[24]=v24; val[25]=v25; val[26]=v26; val[27]=v27; val[28]=v28; val[29]=v29; val[30]=v30; val[31]=v31; val[32]=v32; val[33]=v33; val[34]=v34; val[35]=v35; val[36]=v36; } /// declare a vector containing args


    TT &front() { return val[0]; } /// first element
    const TT &front() const { return val[0]; } /// first element
    TT &back() { return val[size()-1]; } /// last element
    const TT &back() const { return val[size()-1]; } /// last element
    const TT *ptr() const { return val; }
    TT *ptr() { return val; }
    const TT *begin() const { return val; }
    TT *begin() { return val; }
    const TT *end() const { return val+size(); }
    TT *end() { return val+size(); }

    struct SetVal {
        template<class T2> void operator()(const T2 &v,unsigned i,TT *val) const { val[i] = (TT)v; }
        template<class T2> void operator()(const T2 &v1,const T2 &v2,const T2 &v3,const T2 &v4,unsigned i,TT *val) const { val[i+3] = (TT)v1; val[i+2] = (TT)v2; val[i+1] = (TT)v3; val[i+0] = (TT)v4; }
        template<class T2,unsigned ne> void operator()(const SimdVec<T2,ne> &v,unsigned i,TT *val) const { reinterpret_cast<SimdVec<TT,ne> &>(val[i]) = v; }
        template<class T2,unsigned ne> void operator()(const SimdVec<T2,ne> &v1,const SimdVec<T2,ne> &v2,const SimdVec<T2,ne> &v3,const SimdVec<T2,ne> &v4,unsigned i,TT *val) const {
            reinterpret_cast<SimdVec<TT,ne> &>(val[i+3*ne]) = v1;
            reinterpret_cast<SimdVec<TT,ne> &>(val[i+2*ne]) = v2;
            reinterpret_cast<SimdVec<TT,ne> &>(val[i+1*ne]) = v3;
            reinterpret_cast<SimdVec<TT,ne> &>(val[i+0*ne]) = v4;
        }
    };

    template<class T2,int s1,class IO1> Vec(const Vec<T2,s1,IO1> &vec) { init(); resize(vec.size());
         if ( static_size>=0 ) {
             for(unsigned i=0;i<min((unsigned)static_size,vec.size());++i)
                 val[i] = (TT)vec[i];
         }
         else
            apply_simd_wi(vec,SetVal(),val);
    } /// copy constructor
    Vec(const Vec &vec) { init(); resize(vec.size()); for(unsigned i=0;i<size();++i) val[i] = vec[i]; } /// copy constructor
    template<class T2,int s1> Vec &operator=(const Vec<T2,s1> &vec) { resize(vec.size());
        if ( static_size>=0 ) {
            for(unsigned i=0;i<min((unsigned)static_size,vec.size());++i)
                val[i] = (TT)vec[i];
        }
        else
            apply_simd_wi(vec,SetVal(),val);
        return *this;
    }
    Vec &operator=(const Vec &vec) { resize(vec.size());
        if ( static_size>=0 ) {
            for(unsigned i=0;i<min((unsigned)static_size,vec.size());++i)
                val[i] = (TT)vec[i];
        }
        else
            apply_simd_wi(vec,SetVal(),val);
        return *this;
    }
    Vec(std::istream &is) { init(); is >> *this; } /// get data from stream
    // Vec(const std::string &s) { init(); std::istringstream is(s); is >> *this; } /// get data from string

    template<class T2>
    void set( const T2 &v ) { for(unsigned i=0;i<size();++i) operator[]( i ) = v; }

    #ifdef MATLAB_MEX_FILE
        explicit Vec(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }
            if ( fixed_size && static_size!=mxGetN(variable) ) {
                PRINTM( "Error : Vec<...,"+to_string<static_size>()+">(const mxArray *variable) must take a vector of size "+to_string<static_size>() );
                throw std::runtime_error("size error");
            }

            init();
            resize( mxGetN(variable) * mxGetM(variable) );

            double *pr;
            pr = mxGetPr(variable);
            for(unsigned i=0;i<size();++i)
                val[i] = (TT)pr[i];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<size();++i)
                    set_imag(val[i],pr[i]);
            }
        } /// matlab -> LMT::Vec
        Vec &operator=(const mxArray *variable) throw(std::runtime_error) {
            if ( mxIsEmpty(variable) ) {
                printf( "Error : LMT::Vec(mxArray *) need a Matrix\n" );
                throw std::runtime_error("LMT::Vec(mxArray *) need a Matrix");
            }
            if ( ! mxArrayGoodtype<TT>::res(variable) ) {
                printf( "Error : constructor LMT::Vec<%s>(mxArray *) needs a %s Matrix\n", TypeInformation<TT>::type().c_str(), TypeInformation<typename mxArrayGoodtype<TT>::needed>::type().c_str() );
                throw std::runtime_error("constructor LMT::Vec<"+TypeInformation<TT>::type()+">(mxArray *) needs a "+TypeInformation<typename mxArrayGoodtype<TT>::needed>::type()+" Matrix");
            }
            if ( fixed_size && static_size!=mxGetN(variable) ) {
                PRINTM( "Error : Vec<...,"+to_string<static_size>()+">(const mxArray *variable) must take a vector of size "+to_string<static_size>() );
                throw std::runtime_error("size error");
            }

            resize( mxGetN(variable) * mxGetM(variable) );

            double *pr;
            pr = mxGetPr(variable);
            for(unsigned i=0;i<size();++i)
                val[i] = (TT)pr[i];
            if ( mxIsComplex(variable) ) {
                pr = mxGetPi(variable);
                for(unsigned i=0;i<size();++i)
                    set_imag(val[i],pr[i]);
            }
	    return *this;
        } /// matlab -> LMT::Vec
    #endif

    ~Vec() { allocator.free_mem(val); }
    Vec(const SetSize &ss,unsigned s) { init(); resize(s); } ///
    Vec(const SetSize &ss,unsigned s,const TT &val) { init(); resize(s,val); } ///

    unsigned reserved() const { return r; }

    template<class T2,int s1> Vec &append(const Vec<T2,s1> &vec) { unsigned os=size(); resize(size()+vec.size()); for(unsigned i=0;i<vec.size();++i,++os) val[os] = (TT)vec[i]; return *this; }
    TT *new_elem() { if ( r==0 ) reserve(1); else if ( s==r ) reserve(2*r); return &val[s++]; } /// resize *this if necessary and return address to last element
    Vec &operator<<( const TT &val ) { push_back( val ); return *this; }
    TT &push_back(const TT &val) { TT &res = *new_elem(); res = val; return res; } /// Add a copy of val as a new element.
    TT &push_back_in_reserved(const TT &v) { val[s] = v; return val[s++]; } /// Add a copy of val as a new element. Assumes that room for val is already reserved. Only for dynamic vectors.
    TT &push_back_unique(const TT &v) { for(unsigned i=0;i<size();++i) if ( val[i] == v ) return val[i]; return push_back( v ); } /// Add a copy of val as a new element. Assumes that room for val is already reserved. Only for dynamic vectors.
    TT& pop_back() { --s; return val[s]; } /// remove the last element.
    void pop_back(unsigned nb_val) { s -= nb_val; } /// remove the nb_val elements at end.
    void fit_memory() { reserve(size()); } /// if size() is lesser than reserved, reallocate memory with 'right' size.
    void erase_elem_nb(unsigned i) { for(unsigned j=i;j<s-1;++j) val[j]=val[j+1]; pop_back(); } /// erase element number i. This procedure maintains the order of elements
    void erase_elem_strip(unsigned i,unsigned j) {
        if ( j > i ) {
            unsigned d = j - i;
            s -= d;
            for(unsigned k=i;k<s;++k)
                val[k]=val[k+d];
        }
    } /// erase elements from number i to number j (excluded). This procedure maintains the order of elements
    template<class T2> void erase_first(const T2 &v) { for(unsigned i=0;i<size();++i) if (val[i]==v) { val[i]=back(); pop_back(); } } /// erase first element==v. This procedure DOES NOT maintain the order of elements
    void erase_elem_nb_unordered(unsigned i) { val[i] = val[--s]; } /// erase element number i. This procedure does not maintain the order of elements

    void resize(unsigned ns) { if ( ns > r ) reserve(ns); s = ns; }
    void resize(unsigned ns,const TT &v) { unsigned os=s; resize(ns); if (ns>os) copy_vec_value_aligned(v,val+os,ns-os); }

    void reserve(unsigned ns) {
        Allocator nallocator;
        TT *nvec = nallocator.allocate(ns);
        s = min( s, ns );
        copy_vec_aligned(val,nvec,s);
        allocator.free_mem(val);
        val = nvec;
        allocator = nallocator;
        r = ns;
    } /// Reserve room for new elements if ns > size. If ns is lesser than size, resize *this.

    void free() { allocator.free_mem(val); init(); }

    TT *make_room_to_insert( ST from, ST n ) {
        ST os = s;
        resize( s + n );
        for( ST i = os - 1; i >= from; --i )
            val[ i + n ] = val[ i ];
        return val + from;
    }

    void insert_before( ST i, const TT &v ) {
        *make_room_to_insert( i, 1 ) = v;
    }

    TT *insert_ordered( const TT &v ) {
        ST i=0;
        for( ; i < size() and val[ i ] < v; ++i );
        TT *res = make_room_to_insert( i, 1 );
        *res = v;
        return res;
    }

    // res will contain data of this and this is cleared.
    void throw_ref_and_clear( Vec &res ) {
        res.free();
        res.val = val;
        res.s = s;
        res.r = r;
        res.allocator = allocator;
        //
        val = NULL;
        s = 0;
        r = 0;
        allocator.clear();
    }

    

    unsigned size_in_bytes() const { return sizeof(TT) * size(); }

    TT &operator[](unsigned i) { DEBUGASSERT(i<size()); return val[i]; } /// access to element i
    const TT &operator[](unsigned i) const { DEBUGASSERT(i<size()); return val[i]; } /// access to element i
    const TT &get(unsigned i) const { DEBUGASSERT(i<size()); return val[i]; } /// calling get ensure that the const version is called (useful for SparseVec)
    void set(unsigned i,const TT &v) { DEBUGASSERT(i<size()); val[i] = v; } /// set element i

    template<class ST> SimdVec<TT,2> operator[]( const SimdVec<ST,2> &ind ) const { return SimdVec<TT,2>(val[ind[0]],val[ind[1]]); } /// access to element ind[0], ind[1]...


    template<unsigned nne> SimdVec<TT,nne> &simd(unsigned i,const Number<nne> &) { return reinterpret_cast<SimdVec<TT,nne> &>(val[i]); }
    template<unsigned nne> const SimdVec<TT,nne> &simd(unsigned i,const Number<nne> &) const { return reinterpret_cast<const SimdVec<TT,nne> &>(val[i]); }

    unsigned size() const { return s; }

    Vec operator-() const { Vec res = generate(*this,Negate()); return res; }

    /*
    template<class T2> Vec &operator*=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Multiplies(),va); return *this; }
    template<class T2> Vec &operator/=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Divides   (),va); return *this; }
    template<class T2> Vec &operator%=(const T2 &va) { apply_nz(*this,AssignSelfOp(),Modulus   (),va); return *this; }
    template<class T2> Vec &operator&=(const T2 &va) { apply_nz(*this,AssignSelfOp(),And       (),va); return *this; }

    template<class T2,int s2> Vec &operator*=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),Multiplies(),va); return *this; }
    template<class T2,int s2> Vec &operator/=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),Divides   (),va); return *this; }
    template<class T2,int s2> Vec &operator%=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),Modulus   (),va); return *this; }
    template<class T2,int s2> Vec &operator&=(const Vec<T2,s2> &va) { apply_nz_wi(*this,AssignSelfOp(),And       (),va); return *this; }

    template<class T2> Vec &operator+=(const T2 &val) { apply_simd( *this, AssignSelfOp(), Plus() , val ); return *this; }
    template<class T2> Vec &operator-=(const T2 &val) { apply_simd( *this, AssignSelfOp(), Minus(), val ); return *this; }
    template<class T2> Vec &operator^=(const T2 &val) { apply_simd( *this, AssignSelfOp(), Xor()  , val ); return *this; }
    template<class T2> Vec &operator|=(const T2 &val) { apply_simd( *this, AssignSelfOp(), Or()   , val ); return *this; }

    template<class T2,int s2> Vec &operator+=(const Vec<T2,s2> &val) { apply_simd_wi( *this, AssignSelfOp(), Plus() , val ); return *this; }
    template<class T2,int s2> Vec &operator-=(const Vec<T2,s2> &val) { apply_simd_wi( *this, AssignSelfOp(), Minus(), val ); return *this; }
    template<class T2,int s2> Vec &operator^=(const Vec<T2,s2> &val) { apply_simd_wi( *this, AssignSelfOp(), Xor()  , val ); return *this; }
    template<class T2,int s2> Vec &operator|=(const Vec<T2,s2> &val) { apply_simd_wi( *this, AssignSelfOp(), Or()   , val ); return *this; }
    */
                                                          
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
    

    template<class T2> bool contains( const T2 &v ) const {
        for( unsigned i=0; i<size(); ++i )
            if ( val[i] == v )
                return true;
        return false;
    }
    
    template<class T2 > 
    unsigned find( const T2 &v ) const {
        for( unsigned i=0; i<size(); ++i )
            if ( val[i] == v )
                return i;
        return size();
    }

    template<class T2, class Cmp > 
    unsigned find( const T2 &v, Cmp cmp ) const {
        for( unsigned i=0; i<size(); ++i )
            if ( cmp( val[i], v ) )
                return i;
        return size();
    }

    Vec &set(const TT &v) { for(unsigned i=0;i<size();++i) val[i]=v; return *this; }

    /// return a Vec with random values in [0,1]. if s_dim==-1, user must specify size, else size must be = s_dim
    static Vec random(unsigned size_vec) { Vec res; res.resize(size_vec); for(unsigned  i = 0; i < res.size(); res[i++] = TT(rand()/(double)RAND_MAX) ); return res; }

    /*!
    return
    \latex
        $$ [ \frac{ v \& 2^i }{ 2^i } ]_i $$

    if s_dim==-1, user must specify size, else size must be = s_dim
    */
    static Vec binary_decomp(unsigned v,unsigned size_vec) {
        Vec res; res.resize(size_vec);
        for(unsigned i=0,p2i=1;i<res.size();++i,p2i*=2) res[i] = bool( v & p2i );
        return res;
    }
private:
    
    inline void init() { val=(TT *)0; s=0; r=0; }

    TT *val;
    unsigned s,r;
    Allocator allocator;

    template<class U> friend void swap(Vec<U> &v1,Vec<U> &v2);

    
};
}


namespace LMT {
template<class T> void swap(Vec<T> &v1,Vec<T> &v2) {
    swap( v1.val      , v2.val       );
    swap( v1.s        , v2.s         );
    swap( v1.r        , v2.r         );
    swap( v1.allocator, v2.allocator );
}
}


