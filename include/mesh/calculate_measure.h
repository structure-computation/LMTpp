//
// C++ Interface: calculate_volume
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_calculate_volume_HEADER
#define LMT_calculate_volume_HEADER

namespace LMT {

namespace LMTPRIVATE {
    struct GetMeasure {
        template<class TE,class T> void operator()(const TE &e,T &res) const { res += measure(e); }
        template<class TE,class T,unsigned n> void operator()(const TE &e,T &res,const Number<n> &nn) const { if (TE::nb_var_inter==n) res += measure(e); }
    };
    struct GetBarycenterCRho {
        template<class TE,class Pvec,class T> void operator()(const TE &e,Pvec &res,T &mea) const { T m = measure(e); res += m * center(e); mea += m; }
    };
}

/**
    sum of all measure
    \warning if elements do not share the same number of interpolation variables, you'll add areas to volumes and so on
    If it's the case, use measure( m, Number<nvi>() )
*/
template<class TM>
typename TM::Tpos measure(const TM &m) {
    typename TM::Tpos res = 0.0;
    apply( m.elem_list, LMTPRIVATE::GetMeasure(), res );
    return res;
}

/**
    sum of all measure
    \warning if elements do not share the same number of interpolation variables, you'll add areas to volumes and so on
    If it's the case, use measure( m, Number<nvi>() )
*/
template<class TM,unsigned n>
typename TM::Tpos measure(const TM &m,const Number<n> &nn) {
    typename TM::Tpos res = 0.0;
    apply( m.elem_list, LMTPRIVATE::GetMeasure(), res, nn );
    return res;
}


/**
    sum of all measure
    \warning if elements do not share the same number of interpolation variables, you'll add areas to volumes and so on
    If it's the case, use measure( m, Number<nvi>() )
*/
template<class TM>
typename TM::Pvec barycenter_constant_rho(const TM &m) {
    typename TM::Pvec res = 0.0;
    typename TM::Tpos mea = 0.0;
    apply( m.elem_list, LMTPRIVATE::GetBarycenterCRho(), res, mea );
    return res / mea;
}

};

#endif // LMT_calculate_volume_HEADER
