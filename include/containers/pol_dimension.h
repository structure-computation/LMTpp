#ifndef pol_dimension_HEADER
#define pol_dimension_HEADER

namespace LMT {

template <unsigned nd, unsigned nx>
struct SommeDimPol;

template <unsigned nd, unsigned nx>
struct DimPol {
    static const unsigned valeur = SommeDimPol<nd,nx-1>::valeur;
};

template <unsigned nd>
struct DimPol<nd,1> {
    static const unsigned valeur = nd+1;
};

template <unsigned nd, unsigned nx>
struct SommeDimPol {
    static const unsigned valeur = DimPol<nd,nx>::valeur + SommeDimPol<nd-1,nx>::valeur;
};

template <unsigned nx>
struct SommeDimPol <0,nx> {
    static const unsigned valeur = 1 ;
};

template <unsigned N>
struct Deux_Puissance {
    static const unsigned valeur = 2 * Deux_Puissance<N-1>::valeur;
};

template <>
struct Deux_Puissance<0> {
    static const unsigned valeur = 1;
};

}

#endif // pol_dimension_HEADER
