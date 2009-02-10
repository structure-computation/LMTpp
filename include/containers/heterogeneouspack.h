//
// C++ Interface: heterogeneouspack
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2004
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_heterogeneouspack_HEADER
#define LMT_heterogeneouspack_HEADER

#include "number.h"

namespace LMT {

namespace LMTPRIVATE {
    template<class Carac,class T,unsigned n>
    class HeterogeneousPackPart {
    public:
        typedef HeterogeneousPackPart<Carac,typename Carac::template SubType<n+1>::T,n+1> TNext;
        struct NbSubTypes { static const unsigned res = TNext::NbSubTypes::res; };
                
        template<unsigned nn> typename Carac::template SubType<nn>::T &operator()(const Number<nn> &nnn) { return lm(nnn); }
        template<unsigned nn> typename Carac::template SubType<nn>::T &operator()(const Number<nn> &nnn) const { return lm(nnn); }
        T &operator()(const Number<n> &nn) { return val; }
        const T &operator()(const Number<n> &nn) const { return val; }

        /*
        def print_apply_heterpackp():
            for i in range(4):
                targs = ['Op'] + ['TP%s'%j for j in range(i)]
                nargs = ['op'] + ['par%s'%j for j in range(i)]
                
                macag1 = string.join(['val'] + nargs[1:],',')
                macag2 = string.join(['op'] + nargs[1:],',')
                for ptrstr,ptrop in [('',''),('_ptr','*')]:
                    for ci in range(2**(i+1)):
                        def Const(j): return ['const ',''][ ((2**j) & ci)/2**j ]
                        
                        tpar = string.join(map(lambda x:'class '+x,targs),',')
                        args = string.join(map(lambda (t,n,j):Const(j)+t+'& '+n,zip(targs,nargs,range(i+1))),',')
                        arg_mac = string.join([ptrop] + nargs[1:],',')
                        print '    template<'+tpar+'> void apply'+ptrstr+'('+args+') const { op('+ptrop+macag1+'); lm.apply'+ptrstr+'('+macag2+'); }'
                        print '    template<'+tpar+'> void apply'+ptrstr+'('+args+') { op('+ptrop+macag1+'); lm.apply'+ptrstr+'('+macag2+'); }'
        */
        template<class Op> void apply(const Op& op) const { op(val); lm.apply(op); }
        template<class Op> void apply(const Op& op) { op(val); lm.apply(op); }
        template<class Op> void apply(Op& op) const { op(val); lm.apply(op); }
        template<class Op> void apply(Op& op) { op(val); lm.apply(op); }
        template<class Op> void apply_ptr(const Op& op) const { op(*val); lm.apply_ptr(op); }
        template<class Op> void apply_ptr(const Op& op) { op(*val); lm.apply_ptr(op); }
        template<class Op> void apply_ptr(Op& op) const { op(*val); lm.apply_ptr(op); }
        template<class Op> void apply_ptr(Op& op) { op(*val); lm.apply_ptr(op); }
        template<class Op,class TP0> void apply(const Op& op,const TP0& par0) const { op(val,par0); lm.apply(op,par0); }
        template<class Op,class TP0> void apply(const Op& op,const TP0& par0) { op(val,par0); lm.apply(op,par0); }
        template<class Op,class TP0> void apply(Op& op,const TP0& par0) const { op(val,par0); lm.apply(op,par0); }
        template<class Op,class TP0> void apply(Op& op,const TP0& par0) { op(val,par0); lm.apply(op,par0); }
        template<class Op,class TP0> void apply(const Op& op,TP0& par0) const { op(val,par0); lm.apply(op,par0); }
        template<class Op,class TP0> void apply(const Op& op,TP0& par0) { op(val,par0); lm.apply(op,par0); }
        template<class Op,class TP0> void apply(Op& op,TP0& par0) const { op(val,par0); lm.apply(op,par0); }
        template<class Op,class TP0> void apply(Op& op,TP0& par0) { op(val,par0); lm.apply(op,par0); }
        template<class Op,class TP0> void apply_ptr(const Op& op,const TP0& par0) const { op(*val,par0); lm.apply_ptr(op,par0); }
        template<class Op,class TP0> void apply_ptr(const Op& op,const TP0& par0) { op(*val,par0); lm.apply_ptr(op,par0); }
        template<class Op,class TP0> void apply_ptr(Op& op,const TP0& par0) const { op(*val,par0); lm.apply_ptr(op,par0); }
        template<class Op,class TP0> void apply_ptr(Op& op,const TP0& par0) { op(*val,par0); lm.apply_ptr(op,par0); }
        template<class Op,class TP0> void apply_ptr(const Op& op,TP0& par0) const { op(*val,par0); lm.apply_ptr(op,par0); }
        template<class Op,class TP0> void apply_ptr(const Op& op,TP0& par0) { op(*val,par0); lm.apply_ptr(op,par0); }
        template<class Op,class TP0> void apply_ptr(Op& op,TP0& par0) const { op(*val,par0); lm.apply_ptr(op,par0); }
        template<class Op,class TP0> void apply_ptr(Op& op,TP0& par0) { op(*val,par0); lm.apply_ptr(op,par0); }
        template<class Op,class TP0,class TP1> void apply(const Op& op,const TP0& par0,const TP1& par1) const { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(const Op& op,const TP0& par0,const TP1& par1) { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(Op& op,const TP0& par0,const TP1& par1) const { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(Op& op,const TP0& par0,const TP1& par1) { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(const Op& op,TP0& par0,const TP1& par1) const { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(const Op& op,TP0& par0,const TP1& par1) { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(Op& op,TP0& par0,const TP1& par1) const { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(Op& op,TP0& par0,const TP1& par1) { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(const Op& op,const TP0& par0,TP1& par1) const { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(const Op& op,const TP0& par0,TP1& par1) { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(Op& op,const TP0& par0,TP1& par1) const { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(Op& op,const TP0& par0,TP1& par1) { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(const Op& op,TP0& par0,TP1& par1) const { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(const Op& op,TP0& par0,TP1& par1) { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(Op& op,TP0& par0,TP1& par1) const { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply(Op& op,TP0& par0,TP1& par1) { op(val,par0,par1); lm.apply(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1) const { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1) { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(Op& op,const TP0& par0,const TP1& par1) const { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(Op& op,const TP0& par0,const TP1& par1) { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,TP0& par0,const TP1& par1) const { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,TP0& par0,const TP1& par1) { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(Op& op,TP0& par0,const TP1& par1) const { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(Op& op,TP0& par0,const TP1& par1) { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,const TP0& par0,TP1& par1) const { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,const TP0& par0,TP1& par1) { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(Op& op,const TP0& par0,TP1& par1) const { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(Op& op,const TP0& par0,TP1& par1) { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,TP0& par0,TP1& par1) const { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,TP0& par0,TP1& par1) { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(Op& op,TP0& par0,TP1& par1) const { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1> void apply_ptr(Op& op,TP0& par0,TP1& par1) { op(*val,par0,par1); lm.apply_ptr(op,par0,par1); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,const TP1& par1,const TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,const TP1& par1,const TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,const TP1& par1,const TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,const TP1& par1,const TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,const TP1& par1,const TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,const TP1& par1,const TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,const TP1& par1,const TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,const TP1& par1,const TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,TP1& par1,const TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,TP1& par1,const TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,TP1& par1,const TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,TP1& par1,const TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,TP1& par1,const TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,TP1& par1,const TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,TP1& par1,const TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,TP1& par1,const TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,const TP1& par1,TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,const TP1& par1,TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,const TP1& par1,TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,const TP1& par1,TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,const TP1& par1,TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,const TP1& par1,TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,const TP1& par1,TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,const TP1& par1,TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,TP1& par1,TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,TP1& par1,TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,TP1& par1,TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,TP1& par1,TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,TP1& par1,TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,TP1& par1,TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,TP1& par1,TP2& par2) const { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,TP1& par1,TP2& par2) { op(val,par0,par1,par2); lm.apply(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1,const TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1,const TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,const TP1& par1,const TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,const TP1& par1,const TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,const TP1& par1,const TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,const TP1& par1,const TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,const TP1& par1,const TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,const TP1& par1,const TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,TP1& par1,const TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,TP1& par1,const TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,TP1& par1,const TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,TP1& par1,const TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,TP1& par1,const TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,TP1& par1,const TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,TP1& par1,const TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,TP1& par1,const TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1,TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1,TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,const TP1& par1,TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,const TP1& par1,TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,const TP1& par1,TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,const TP1& par1,TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,const TP1& par1,TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,const TP1& par1,TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,TP1& par1,TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,TP1& par1,TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,TP1& par1,TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,TP1& par1,TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,TP1& par1,TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,TP1& par1,TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,TP1& par1,TP2& par2) const { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,TP1& par1,TP2& par2) { op(*val,par0,par1,par2); lm.apply_ptr(op,par0,par1,par2); }
        
        #define HPAPPLY_W_PAR op(val,par,Number<n>()); lm.apply(op,par)
        template<class Op,class Par> void apply_and_cpt(Op &op,Par &par) { HPAPPLY_W_PAR; }
        template<class Op,class Par> void apply_and_cpt(const Op &op,Par &par) { HPAPPLY_W_PAR; }
        template<class Op,class Par> void apply_and_cpt(Op &op,Par &par) const { HPAPPLY_W_PAR; }
        template<class Op,class Par> void apply_and_cpt(const Op &op,Par &par) const { HPAPPLY_W_PAR; }
        template<class Op,class Par> void apply_and_cpt(Op &op,const Par &par) { HPAPPLY_W_PAR; }
        template<class Op,class Par> void apply_and_cpt(const Op &op,const Par &par) { HPAPPLY_W_PAR; }
        template<class Op,class Par> void apply_and_cpt(Op &op,const Par &par) const { HPAPPLY_W_PAR; }
        template<class Op,class Par> void apply_and_cpt(const Op &op,const Par &par) const { HPAPPLY_W_PAR; }
        #undef HPAPPLY_W_PAR
                
        T val;
        TNext lm;
    };
    template<class Carac,unsigned n>
    class HeterogeneousPackPart<Carac,void,n> {
    public:
        struct NbSubTypes { static const unsigned res = n; };
        template<class Op> void apply(const Op& op) const {}
        template<class Op> void apply_ptr(const Op& op) const {}
        template<class Op,class TP0> void apply(const Op& op,const TP0& par0) const {}
        template<class Op,class TP0> void apply_ptr(const Op& op,const TP0& par0) const {}
        template<class Op,class TP0,class TP1> void apply(const Op& op,const TP0& par0,const TP1& par1) const {}
        template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1) const {}
        template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,const TP1& par1,const TP2& par2) const {}
        template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1,const TP2& par2) const {}
        template<class Op,class Par> void apply_and_cpt(const Op &op,const Par &par) const {}
    };
}

/**
    Used to store heterogeneous data. Accessed using (Number<...>())
*/
template<class Carac>
class HeterogeneousPack {
public:
    typedef LMTPRIVATE::HeterogeneousPackPart<Carac,typename Carac::template SubType<0>::T,0> HP;
    static const unsigned nb_sub_types = HP::NbSubTypes::res;
    
    template<unsigned nn> typename Carac::template SubType<nn>::T &operator()( const Number<nn> &nnn = Number<nn>() ) { return hp(nnn); }
    template<unsigned nn> const typename Carac::template SubType<nn>::T &operator()( const Number<nn> &nnn = Number<nn>() ) const { return hp(nnn); }
    /*
    def print_apply_heterpack():
        for i in range(4):
            targs = ['Op'] + ['TP%s'%j for j in range(i)]
            nargs = ['op'] + ['par%s'%j for j in range(i)]
            
            macag1 = string.join(['op'] + nargs[1:],',')
            macag2 = string.join(['op'] + nargs[1:],',')
            for ptrstr,ptrop in [('',''),('_ptr','*')]:
                for ci in range(2**(i+1)):
                    def Const(j): return ['const ',''][ ((2**j) & ci)/2**j ]
                    
                    tpar = string.join(map(lambda x:'class '+x,targs),',')
                    args = string.join(map(lambda (t,n,j):Const(j)+t+'& '+n,zip(targs,nargs,range(i+1))),',')
                    arg_mac = string.join([ptrop] + nargs[1:],',')
                    print '    template<'+tpar+'> void apply'+ptrstr+'('+args+') const { hp.apply'+ptrstr+'('+macag2+'); }'
                    print '    template<'+tpar+'> void apply'+ptrstr+'('+args+') { hp.apply'+ptrstr+'('+macag2+'); }'
    */
    template<class Op> void apply(const Op& op) const { hp.apply(op); }
    template<class Op> void apply(const Op& op) { hp.apply(op); }
    template<class Op> void apply(Op& op) const { hp.apply(op); }
    template<class Op> void apply(Op& op) { hp.apply(op); }
    template<class Op> void apply_ptr(const Op& op) const { hp.apply_ptr(op); }
    template<class Op> void apply_ptr(const Op& op) { hp.apply_ptr(op); }
    template<class Op> void apply_ptr(Op& op) const { hp.apply_ptr(op); }
    template<class Op> void apply_ptr(Op& op) { hp.apply_ptr(op); }
    template<class Op,class TP0> void apply(const Op& op,const TP0& par0) const { hp.apply(op,par0); }
    template<class Op,class TP0> void apply(const Op& op,const TP0& par0) { hp.apply(op,par0); }
    template<class Op,class TP0> void apply(Op& op,const TP0& par0) const { hp.apply(op,par0); }
    template<class Op,class TP0> void apply(Op& op,const TP0& par0) { hp.apply(op,par0); }
    template<class Op,class TP0> void apply(const Op& op,TP0& par0) const { hp.apply(op,par0); }
    template<class Op,class TP0> void apply(const Op& op,TP0& par0) { hp.apply(op,par0); }
    template<class Op,class TP0> void apply(Op& op,TP0& par0) const { hp.apply(op,par0); }
    template<class Op,class TP0> void apply(Op& op,TP0& par0) { hp.apply(op,par0); }
    template<class Op,class TP0> void apply_ptr(const Op& op,const TP0& par0) const { hp.apply_ptr(op,par0); }
    template<class Op,class TP0> void apply_ptr(const Op& op,const TP0& par0) { hp.apply_ptr(op,par0); }
    template<class Op,class TP0> void apply_ptr(Op& op,const TP0& par0) const { hp.apply_ptr(op,par0); }
    template<class Op,class TP0> void apply_ptr(Op& op,const TP0& par0) { hp.apply_ptr(op,par0); }
    template<class Op,class TP0> void apply_ptr(const Op& op,TP0& par0) const { hp.apply_ptr(op,par0); }
    template<class Op,class TP0> void apply_ptr(const Op& op,TP0& par0) { hp.apply_ptr(op,par0); }
    template<class Op,class TP0> void apply_ptr(Op& op,TP0& par0) const { hp.apply_ptr(op,par0); }
    template<class Op,class TP0> void apply_ptr(Op& op,TP0& par0) { hp.apply_ptr(op,par0); }
    template<class Op,class TP0,class TP1> void apply(const Op& op,const TP0& par0,const TP1& par1) const { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(const Op& op,const TP0& par0,const TP1& par1) { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(Op& op,const TP0& par0,const TP1& par1) const { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(Op& op,const TP0& par0,const TP1& par1) { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(const Op& op,TP0& par0,const TP1& par1) const { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(const Op& op,TP0& par0,const TP1& par1) { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(Op& op,TP0& par0,const TP1& par1) const { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(Op& op,TP0& par0,const TP1& par1) { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(const Op& op,const TP0& par0,TP1& par1) const { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(const Op& op,const TP0& par0,TP1& par1) { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(Op& op,const TP0& par0,TP1& par1) const { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(Op& op,const TP0& par0,TP1& par1) { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(const Op& op,TP0& par0,TP1& par1) const { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(const Op& op,TP0& par0,TP1& par1) { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(Op& op,TP0& par0,TP1& par1) const { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply(Op& op,TP0& par0,TP1& par1) { hp.apply(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1) const { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1) { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(Op& op,const TP0& par0,const TP1& par1) const { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(Op& op,const TP0& par0,const TP1& par1) { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,TP0& par0,const TP1& par1) const { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,TP0& par0,const TP1& par1) { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(Op& op,TP0& par0,const TP1& par1) const { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(Op& op,TP0& par0,const TP1& par1) { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,const TP0& par0,TP1& par1) const { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,const TP0& par0,TP1& par1) { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(Op& op,const TP0& par0,TP1& par1) const { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(Op& op,const TP0& par0,TP1& par1) { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,TP0& par0,TP1& par1) const { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(const Op& op,TP0& par0,TP1& par1) { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(Op& op,TP0& par0,TP1& par1) const { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1> void apply_ptr(Op& op,TP0& par0,TP1& par1) { hp.apply_ptr(op,par0,par1); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,const TP1& par1,const TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,const TP1& par1,const TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,const TP1& par1,const TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,const TP1& par1,const TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,const TP1& par1,const TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,const TP1& par1,const TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,const TP1& par1,const TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,const TP1& par1,const TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,TP1& par1,const TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,TP1& par1,const TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,TP1& par1,const TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,TP1& par1,const TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,TP1& par1,const TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,TP1& par1,const TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,TP1& par1,const TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,TP1& par1,const TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,const TP1& par1,TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,const TP1& par1,TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,const TP1& par1,TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,const TP1& par1,TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,const TP1& par1,TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,const TP1& par1,TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,const TP1& par1,TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,const TP1& par1,TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,TP1& par1,TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,const TP0& par0,TP1& par1,TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,TP1& par1,TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,const TP0& par0,TP1& par1,TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,TP1& par1,TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(const Op& op,TP0& par0,TP1& par1,TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,TP1& par1,TP2& par2) const { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply(Op& op,TP0& par0,TP1& par1,TP2& par2) { hp.apply(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1,const TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1,const TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,const TP1& par1,const TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,const TP1& par1,const TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,const TP1& par1,const TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,const TP1& par1,const TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,const TP1& par1,const TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,const TP1& par1,const TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,TP1& par1,const TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,TP1& par1,const TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,TP1& par1,const TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,TP1& par1,const TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,TP1& par1,const TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,TP1& par1,const TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,TP1& par1,const TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,TP1& par1,const TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1,TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,const TP1& par1,TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,const TP1& par1,TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,const TP1& par1,TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,const TP1& par1,TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,const TP1& par1,TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,const TP1& par1,TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,const TP1& par1,TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,TP1& par1,TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,const TP0& par0,TP1& par1,TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,TP1& par1,TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,const TP0& par0,TP1& par1,TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,TP1& par1,TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(const Op& op,TP0& par0,TP1& par1,TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,TP1& par1,TP2& par2) const { hp.apply_ptr(op,par0,par1,par2); }
    template<class Op,class TP0,class TP1,class TP2> void apply_ptr(Op& op,TP0& par0,TP1& par1,TP2& par2) { hp.apply_ptr(op,par0,par1,par2); }
        
    HP hp;
};

};

#endif // LMT_heterogeneouspack_HEADER
