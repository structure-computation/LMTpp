//
// C++ Interface: apply_ij
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_apply_ij_HEADER
#define LMT_apply_ij_HEADER

#include "number.h"

namespace LMT {

namespace LMTPRIVATE {

/*!
    structure privée!
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \internal

*/
    struct Apply_IJB {
        template<class T2,class T1,class Op> void operator()(const T2 &t2,const T1 &t1,const Op &op) { op(t1,i,t2,j++); }
        template<class T2,class T1,class Op> void operator()(const T2 &t2,const T1 &t1,Op &op) { op(t1,i,t2,j++); }
        template<class T2,class T1,class Op> void operator()(const T2 &t2,T1 &t1,const Op &op) { op(t1,i,t2,j++); }
        template<class T2,class T1,class Op> void operator()(const T2 &t2,T1 &t1,Op &op) { op(t1,i,t2,j++); }
        template<class T2,class T1,class Op> void operator()(T2 &t2,const T1 &t1,const Op &op) { op(t1,i,t2,j++); }
        template<class T2,class T1,class Op> void operator()(T2 &t2,const T1 &t1,Op &op) { op(t1,i,t2,j++); }
        template<class T2,class T1,class Op> void operator()(T2 &t2,T1 &t1,const Op &op) { op(t1,i,t2,j++); }
        template<class T2,class T1,class Op> void operator()(T2 &t2,T1 &t1,Op &op) { op(t1,i,t2,j++); }
        
        template<class T2,class T1,class Op,class P0> void operator()(const T2 &t2,const T1 &t1,const Op &op,const P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(const T2 &t2,const T1 &t1,Op &op,const P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(const T2 &t2,T1 &t1,const Op &op,const P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(const T2 &t2,T1 &t1,Op &op,const P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(T2 &t2,const T1 &t1,const Op &op,const P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(T2 &t2,const T1 &t1,Op &op,const P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(T2 &t2,T1 &t1,const Op &op,const P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(T2 &t2,T1 &t1,Op &op,const P0 &p0) { op(t1,i,t2,j++,p0); }
        
        template<class T2,class T1,class Op,class P0> void operator()(const T2 &t2,const T1 &t1,const Op &op,P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(const T2 &t2,const T1 &t1,Op &op,P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(const T2 &t2,T1 &t1,const Op &op,P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(const T2 &t2,T1 &t1,Op &op,P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(T2 &t2,const T1 &t1,const Op &op,P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(T2 &t2,const T1 &t1,Op &op,P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(T2 &t2,T1 &t1,const Op &op,P0 &p0) { op(t1,i,t2,j++,p0); }
        template<class T2,class T1,class Op,class P0> void operator()(T2 &t2,T1 &t1,Op &op,P0 &p0) { op(t1,i,t2,j++,p0); }
        unsigned i,j;
    };

/*!
    structure privée!
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \internal

*/
    struct Apply_IJ {
        Apply_IJ() { a.i=0; }
        //
        template<class T1,class HET2,class Op> void operator()(const T1 &t1,const HET2 &het2,const Op &op) { a.j=0; apply(het2,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(const T1 &t1,const HET2 &het2,Op &op) { a.j=0; apply(het2,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(const T1 &t1,HET2 &het2,const Op &op) { a.j=0; apply(het2,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(const T1 &t1,HET2 &het2,Op &op) { a.j=0; apply(het2,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(T1 &t1,const HET2 &het2,const Op &op) { a.j=0; apply(het2,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(T1 &t1,const HET2 &het2,Op &op) { a.j=0; apply(het2,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(T1 &t1,HET2 &het2,const Op &op) { a.j=0; apply(het2,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(T1 &t1,HET2 &het2,Op &op) { a.j=0; apply(het2,a,t1,op); ++a.i; }
        //
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,const HET2 &het2,const Op &op,const P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,const HET2 &het2,Op &op,const P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,HET2 &het2,const Op &op,const P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,HET2 &het2,Op &op,const P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,const HET2 &het2,const Op &op,const P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,const HET2 &het2,Op &op,const P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,HET2 &het2,const Op &op,const P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,HET2 &het2,Op &op,const P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        //
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,const HET2 &het2,const Op &op,P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,const HET2 &het2,Op &op,P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,HET2 &het2,const Op &op,P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,HET2 &het2,Op &op,P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,const HET2 &het2,const Op &op,P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,const HET2 &het2,Op &op,P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,HET2 &het2,const Op &op,P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,HET2 &het2,Op &op,P0 &p0) { a.j=0; apply(het2,a,t1,op,p0); ++a.i; }
        
        Apply_IJB a;
    };

/*!
    structure privée!
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \internal
*/
    template<bool eq> struct Apply_ISJ {
        Apply_ISJ() { a.i=0; }
        //
        template<class T1,class HET2,class Op> void operator()(const T1 &t1,const HET2 &het2,const Op &op) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(const T1 &t1,const HET2 &het2,Op &op) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(const T1 &t1,HET2 &het2,const Op &op) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(const T1 &t1,HET2 &het2,Op &op) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(T1 &t1,const HET2 &het2,const Op &op) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(T1 &t1,const HET2 &het2,Op &op) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(T1 &t1,HET2 &het2,const Op &op) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op); ++a.i; }
        template<class T1,class HET2,class Op> void operator()(T1 &t1,HET2 &het2,Op &op) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op); ++a.i; }
        //
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,const HET2 &het2,const Op &op,const P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,const HET2 &het2,Op &op,const P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,HET2 &het2,const Op &op,const P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,HET2 &het2,Op &op,const P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,const HET2 &het2,const Op &op,const P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,const HET2 &het2,Op &op,const P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,HET2 &het2,const Op &op,const P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,HET2 &het2,Op &op,const P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        //
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,const HET2 &het2,const Op &op,P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,const HET2 &het2,Op &op,P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,HET2 &het2,const Op &op,P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(const T1 &t1,HET2 &het2,Op &op,P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,const HET2 &het2,const Op &op,P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,const HET2 &het2,Op &op,P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,HET2 &het2,const Op &op,P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        template<class T1,class HET2,class Op,class P0> void operator()(T1 &t1,HET2 &het2,Op &op,P0 &p0) { a.j=0; unsigned cpt=a.i+eq; apply_range(het2,0,cpt,a,t1,op,p0); ++a.i; }
        
        Apply_IJB a;
    };
};

/*!
\generic_comment apply_ij

    Cette fonction permet d'appliquer un opérateur op sur deux conteneurs en même temps. Plus précisement l'opérateur agit sur toutes les paires possibles : donc cela revient à faire deux boucles imbriquées. Elle s'utilise comme la fonction \a apply . Voici un exemple de foncteur qui compare les centres des éléments respectifs à deux maillages et affiche l'indice des éléments dans le cas où ils sont presque confondus.
    \code C/C++
        struct PrintIndex {
            template< class E, class E2 >
            void operator()( E& e, unsigned i, E2 &e2, unsigned j ) const {
                typedef typename E::Pvec Pvec;
                typedef typename E2::Pvec Pvec2;                 
                
                Pvec  c  = center( e  );
                Pvec2 c2 = center( e2 );
                
                if ( length( c - c2 ) < 1e-5 ) {
                    PRINT( i );
                    PRINT( j );
                }
            }
        }; 
     
    Ce foncteur s'utiliserait ainsi :
    \code C/C++
        int maint() {
        
            typedef double T;
            typedef Mesh< MeshCaracStd< 3, 3, 0, double, 1 > > TM; /// maillage 3D de Tetra
        
            TM m, m2;
            
            /// on crée des maillages 
            make_rect( m , Tetra(), 0, 1, 10 );
            make_rect( m2, Tetra(), 0, 1, 20 );
        
            apply_ij( m.elem_list, m2.elem_list, PrintIndex() ); 
            
            return 0;
        
        }
    

 
    \relates Vec
    \relates apply
    \relates Mesh
    \relates Mat
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr

*/
template<class HET1,class HET2,class Op> void apply_ij(const HET1 &het1,const HET2 &het2,const Op &op) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_ij(const HET1 &het1,const HET2 &het2,Op &op) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_ij(const HET1 &het1,HET2 &het2,const Op &op) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_ij(const HET1 &het1,HET2 &het2,Op &op) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_ij(HET1 &het1,const HET2 &het2,const Op &op) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_ij(HET1 &het1,const HET2 &het2,Op &op) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_ij(HET1 &het1,HET2 &het2,const Op &op) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_ij(HET1 &het1,HET2 &het2,Op &op) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op); }
///
template<class HET1,class HET2,class Op,class P0> void apply_ij(const HET1 &het1,const HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(const HET1 &het1,const HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(const HET1 &het1,HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(const HET1 &het1,HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(HET1 &het1,const HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(HET1 &het1,const HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(HET1 &het1,HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(HET1 &het1,HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
///
template<class HET1,class HET2,class Op,class P0> void apply_ij(const HET1 &het1,const HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(const HET1 &het1,const HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(const HET1 &het1,HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(const HET1 &het1,HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(HET1 &het1,const HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(HET1 &het1,const HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(HET1 &het1,HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_ij(HET1 &het1,HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_IJ hva; apply(het1,hva,het2,op,p0); }


/*!
\generic_comment apply_i_supeq_j

    Cette fonction permet d'appliquer un opérateur op sur deux conteneurs en même temps avec l'indice du premier conteneur supérieur ou égal à l'indice du deuxième.

    \relates apply_ij
    \relates Vec
    \relates apply
    \relates Mesh
    \relates Mat
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr

*/
template<class HET1,class HET2,class Op> void apply_i_supeq_j(const HET1 &het1,const HET2 &het2,const Op &op) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_supeq_j(const HET1 &het1,const HET2 &het2,Op &op) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_supeq_j(const HET1 &het1,HET2 &het2,const Op &op) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_supeq_j(const HET1 &het1,HET2 &het2,Op &op) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_supeq_j(HET1 &het1,const HET2 &het2,const Op &op) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_supeq_j(HET1 &het1,const HET2 &het2,Op &op) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_supeq_j(HET1 &het1,HET2 &het2,const Op &op) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_supeq_j(HET1 &het1,HET2 &het2,Op &op) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op); }
///
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(const HET1 &het1,const HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(const HET1 &het1,const HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(const HET1 &het1,HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(const HET1 &het1,HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(HET1 &het1,const HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(HET1 &het1,const HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(HET1 &het1,HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(HET1 &het1,HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
///
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(const HET1 &het1,const HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(const HET1 &het1,const HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(const HET1 &het1,HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(const HET1 &het1,HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(HET1 &het1,const HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(HET1 &het1,const HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(HET1 &het1,HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_supeq_j(HET1 &het1,HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<true> hva; apply(het1,hva,het2,op,p0); }

/*!
\generic_comment apply_i_supeq_j

    Cette fonction permet d'appliquer un opérateur op sur deux conteneurs en même temps avec l'indice du premier conteneur supérieur  à l'indice du deuxième.

    \relates apply_ij
    \relates Vec
    \relates apply
    \relates Mesh
    \relates Mat
    \friend raphael.pasquier@lmt.ens-cachan.fr
    \friend hugo.leclerc@lmt.ens-cachan.fr

*/
template<class HET1,class HET2,class Op> void apply_i_sup_j(const HET1 &het1,const HET2 &het2,const Op &op) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_sup_j(const HET1 &het1,const HET2 &het2,Op &op) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_sup_j(const HET1 &het1,HET2 &het2,const Op &op) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_sup_j(const HET1 &het1,HET2 &het2,Op &op) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_sup_j(HET1 &het1,const HET2 &het2,const Op &op) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_sup_j(HET1 &het1,const HET2 &het2,Op &op) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_sup_j(HET1 &het1,HET2 &het2,const Op &op) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op); }
template<class HET1,class HET2,class Op> void apply_i_sup_j(HET1 &het1,HET2 &het2,Op &op) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op); }
///
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(const HET1 &het1,const HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(const HET1 &het1,const HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(const HET1 &het1,HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(const HET1 &het1,HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(HET1 &het1,const HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(HET1 &het1,const HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(HET1 &het1,HET2 &het2,const Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(HET1 &het1,HET2 &het2,Op &op,const P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
///
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(const HET1 &het1,const HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(const HET1 &het1,const HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(const HET1 &het1,HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(const HET1 &het1,HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(HET1 &het1,const HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(HET1 &het1,const HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(HET1 &het1,HET2 &het2,const Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }
template<class HET1,class HET2,class Op,class P0> void apply_i_sup_j(HET1 &het1,HET2 &het2,Op &op,P0 &p0) { LMTPRIVATE::Apply_ISJ<false> hva; apply(het1,hva,het2,op,p0); }


///
template<class Op>
struct MinOp {
    MinOp(const Op &o):op(o),init(false) {}
    template<class TM> void operator()(const TM &t) {
        if ( init ) res = min(op(t),res);
        else { res = op(t); init = true; }
    }
    typename Op::T res;
    const Op &op;
    bool init;
};
///
template<class Op>
struct MaxOp {
    MaxOp(const Op &o):op(o),init(false) {}
    template<class TM> void operator()(const TM &t) {
        if ( init ) res = max(op(t),res);
        else { res = op(t); init = true; }
    }
    typename Op::T res;
    const Op &op;
    bool init;
};


};

#endif // LMT_apply_ij_HEADER
