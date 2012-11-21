#ifndef vec_mat_tools_h
#define vec_mat_tools_h

#include <containers/mat.h>

///                                          ///////////////////////////
/// ---------------------------------------- /// for normal matrices ///
///                                          ///////////////////////////

/// --------------------------------------------- /// décompositions ///

template<class TM> TM sym_part_mat(const TM &M)
{
    return (M + LMT::trans(M)) / 2;
}

template<class TM> TM antisym_part_mat(const TM &M)
{
    return (M - LMT::trans(M)) / 2;
}

/// ------------------------------------------ /// produit contracté ///

template<class TM> typename TM::T prod_contr_mat(const TM &M1, const TM &M2)
{
    static const unsigned nb_dim = M1.nb_rows();

    typename TM::T res = 0.;
    for (unsigned i=0; i<nb_dim; ++i)
    {
        for (unsigned j=0; j<nb_dim; ++j)
        {
            res += M1(i,j) * M2(i,j);
        }
    }
    return res;
}

template<class TM> typename TM::T self_prod_contr_mat(const TM &M)
{
    return prod_contr_mat(M, M);
}

/// -------------------------------------------------- /// puissance ///

template<class TM> TM pow_mat_sym(TM M, const unsigned &p)
{
    static const unsigned nb_dim = M.nb_rows();

    LMT::Mat<typename TM::T, LMT::Sym<> > res; // must be sym because it is then used in mat_sym_to_vec_col
    res.resize(nb_dim);
    res.set(0.);
    res.diag() = 1.;
    for (unsigned k=0; k<p; ++k)
    {
        res *= M;
    }
    return res;
}

///      ///////////////////////////////////////////////////////////////
/// ---- /// for vectors representing second order symmetric tensors ///
///      ///////////////////////////////////////////////////////////////

/// ------------------------------------------------ /// conversions ///

template<class TV> TV vec_col_to_vec_col_with_sqr(TV V)
{
    static const unsigned nb_vec = V.size();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    for (unsigned i=nb_dim; i<nb_vec; ++i)
    {
        V[i] *= sqrt(2.);
    }
    return V;
}

template<class TV> TV vec_col_to_vec_col_with_two(TV V)
{
    static const unsigned nb_vec = V.size();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    for (unsigned i=nb_dim; i<nb_vec; ++i)
    {
        V[i] *= 2.;
    }
    return V;
}

template<class TV> TV vec_col_with_sqr_to_vec_col(TV V)
{
    static const unsigned nb_vec = V.size();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    for (unsigned i=nb_dim; i<nb_vec; ++i)
    {
        V[i] /= sqrt(2.);
    }
    return V;
}

template<class TV> TV vec_col_with_sqr_to_vec_col_with_two(TV V)
{
    static const unsigned nb_vec = V.size();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    for (unsigned i=nb_dim; i<nb_vec; ++i)
    {
        V[i] *= sqrt(2.);
    }
    return V;
}

template<class TV> TV vec_col_with_two_to_vec_col(TV V)
{
    static const unsigned nb_vec = V.size();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    for (unsigned i=nb_dim; i<nb_vec; ++i)
    {
        V[i] /= 2.;
    }
    return V;
}

template<class TV> TV vec_col_with_two_to_vec_col_with_sqr(TV V)
{
    static const unsigned nb_vec = V.size();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    for (unsigned i=nb_dim; i<nb_vec; ++i)
    {
        V[i] /= sqrt(2.);
    }
    return V;
}

template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > vec_col_to_mat_sym(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    static const unsigned nb_vec = V.size();

    LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > M;

    if (nb_vec == 3)
    {
        M.resize(2);
        M.set(0.);
        M(0, 0) = V[0];
        M(1, 1) = V[1];
        M(0, 1) = V[2];
        return M;
    }

    if (nb_vec == 6)
    {
        M.resize(3);
        M.set(0.);
        M(0, 0) = V[0];
        M(1, 1) = V[1];
        M(2, 2) = V[2];
        M(0, 1) = V[3];
        M(0, 2) = V[4];
        M(1, 2) = V[5];
        return M;
    }
}

template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > vec_col_with_sqr_to_mat_sym(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    static const unsigned nb_vec = V.size();

    LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > M;

    if (nb_vec == 3)
    {
        M.resize(2);
        M.set(0.);
        M(0, 0) = V[0];
        M(1, 1) = V[1];
        M(0, 1) = V[2]/sqrt(2.);
        return M;
    }

    if (nb_vec == 6)
    {
        M.resize(3);
        M.set(0.);
        M(0, 0) = V[0];
        M(1, 1) = V[1];
        M(2, 2) = V[2];
        M(0, 1) = V[3]/sqrt(2.);
        M(0, 2) = V[4]/sqrt(2.);
        M(1, 2) = V[5]/sqrt(2.);
        return M;
    }
}

template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > vec_col_with_two_to_mat_sym(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    static const unsigned nb_vec = V.size();

    LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > M;

    if (nb_vec == 3)
    {
        M.resize(2);
        M.set(0.);
        M(0, 0) = V[0];
        M(1, 1) = V[1];
        M(0, 1) = V[2]/2.;
        return M;
    }

    if (nb_vec == 6)
    {
        M.resize(3);
        M.set(0.);
        M(0, 0) = V[0];
        M(1, 1) = V[1];
        M(2, 2) = V[2];
        M(0, 1) = V[3]/2.;
        M(0, 2) = V[4]/2.;
        M(1, 2) = V[5]/2.;
        return M;
    }
}

template<class TM> LMT::Vec<typename TM::T> mat_sym_to_vec_col(const TM &M)
{
    static const unsigned nb_dim = M.nb_cols();

    if (nb_dim == 2)
    {
        LMT::Vec<typename TM::T> V;
        V.resize(3);
        V[0] = M(0, 0);
        V[1] = M(1, 1);
        V[2] = M(0, 1);
        return V;
    }

    if (nb_dim == 3)
    {
        LMT::Vec<typename TM::T> V;
        V.resize(6);
        V[0] = M(0, 0);
        V[1] = M(1, 1);
        V[2] = M(2, 2);
        V[3] = M(0, 1);
        V[4] = M(0, 2);
        V[5] = M(1, 2);
        return V;
    }
}

template<class TM> LMT::Vec<typename TM::T> mat_sym_to_vec_col_with_sqr(const TM &M)
{
    static const unsigned nb_dim = M.nb_cols();

    if (nb_dim == 2)
    {
        LMT::Vec<typename TM::T> V;
        V.resize(3);
        V[0] = M(0, 0);
        V[1] = M(1, 1);
        V[2] = sqrt(2.) * M(0, 1);
        return V;
    }

    if (nb_dim == 3)
    {
        LMT::Vec<typename TM::T> V;
        V.resize(6);
        V[0] = M(0, 0);
        V[1] = M(1, 1);
        V[2] = M(2, 2);
        V[3] = sqrt(2.) * M(0, 1);
        V[4] = sqrt(2.) * M(0, 2);
        V[5] = sqrt(2.) * M(1, 2);
        return V;
    }
}

template<class TM> LMT::Vec<typename TM::T> mat_sym_to_vec_col_with_two(const TM &M)
{
    static const unsigned nb_dim = M.nb_cols();

    if (nb_dim == 2)
    {
        LMT::Vec<typename TM::T> V;
        V.resize(3);
        V[0] = M(0, 0);
        V[1] = M(1, 1);
        V[2] = 2. * M(0, 1);
        return V;
    }

    if (nb_dim == 3)
    {
        LMT::Vec<typename TM::T> V;
        V.resize(6);
        V[0] = M(0, 0);
        V[1] = M(1, 1);
        V[2] = M(2, 2);
        V[3] = 2. * M(0, 1);
        V[4] = 2. * M(0, 2);
        V[5] = 2. * M(1, 2);
        return V;
    }
}

/// ------------------------------------------------------ /// trace ///

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T trace_vec_col(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    static const unsigned nb_vec = V.size();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    typename LMT::TypeReduction<LMT::Multiplies, TV>::T res = 0.;
    for (unsigned i=0; i<nb_dim; ++i)
    {
        res += V[i];
    }
    return res;
}

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T trace_vec_col_with_sqr(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return trace_vec_col(V);
}

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T trace_vec_col_with_two(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return trace_vec_col(V);
}

/// ---------------------------------------------------- /// produit ///

// le produit de deux matrices symétriques n'est symétrique que si les deux matrices commutent
// ici on ne le définit que pour une matrice avec elle-même, auquel cas le produit est forcément symétrique

template<class TV> TV self_prod_vec_col(const TV &V)
{
    return mat_sym_to_vec_col(vec_col_to_mat_sym(V) * vec_col_to_mat_sym(V));
}

/// -------------------------------------------------- /// puissance ///

template<class TV> TV pow_vec_col(const TV &V, const unsigned &p)
{
    return mat_sym_to_vec_col(pow_mat_sym(vec_col_to_mat_sym(V), p));
}

template<class TV> TV pow_vec_col_with_sqr(const TV &V, const unsigned &p)
{
    return mat_sym_to_vec_col_with_sqr(pow_mat_sym(vec_col_with_sqr_to_mat_sym(V), p));
}

/// ------------------------------------------ /// produit contracté ///

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T prod_contr_vec_col_with_sqr(const TV &V1, const TV &V2)
{
    return dot(V1, V2);
}

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T self_prod_contr_vec_col_with_sqr(const TV &V)
{
    return prod_contr_vec_col_with_sqr(V, V);
}

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T prod_contr_vec_col(const TV &V1, const TV &V2)
{
    return prod_contr_vec_col_with_sqr(vec_col_to_vec_col_with_sqr(V1), vec_col_to_vec_col_with_sqr(V2));
}

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T self_prod_contr_vec_col(const TV &V)
{
    return prod_contr_vec_col(V, V);
}

/// ------------------------------------------ /// produit tensoriel ///

template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T> prod_tens_vec_col(const TV &V1, const TV &V2) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    static const unsigned nb_dim = V1.size();

    LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T> res(nb_dim);
    for (unsigned i=0; i<nb_dim; ++i)
    {
        for (unsigned j=0; j<nb_dim; ++j)
        {
            res(i, j) = V1[i] * V2[j];
        }
    }
    return res;
}

template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T> self_prod_tens_vec_col(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return prod_tens_vec_col(V, V);
}

/// ----------------------------------------------------- /// normes ///

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T norm_2_vec_col(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return LMT::sqrt(self_prod_contr_vec_col(V));
}

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T norm_2_vec_col_with_sqr(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return LMT::sqrt(self_prod_contr_vec_col_with_sqr(V));
}

///     ////////////////////////////////////////////////////////////////
/// --- /// for matrices representing fourth order symmetric tensors ///
///     ////////////////////////////////////////////////////////////////

// only small symmetries are required for the representation of fourth order tensors as matrices
// large symmetry implies that the representation matrix is symmetric

/// ---------------------------------------------------- /// produit ///

template<class TM> TM prod_mat_col(const TM &M1, const TM &M2)
{
    static const unsigned nb_vec = M1.nb_rows();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    LMT::Mat<typename TM::T> res; // must be gen since the product of two (even completely symmetric) tensors is not always symmetric (small symmetries are induced by the small symmetries of the original tensors, but the large symmetry is not)
    res.set(0.);
    for (unsigned i=0; i<nb_vec; ++i)
    for (unsigned j=0; j<nb_vec; ++j)
    {
        for (unsigned k=0; k<nb_dim; ++k)
        {
            res(i, j) += M1(i,k) * M2(k,j);
        }
        for (unsigned k=nb_dim; k<nb_vec; ++k)
        {
            res(i, j) += 2. * M1(i,k) * M2(k,j);
        }
    }
    return res;
}

/// ------------------------------- /// produit simplement contracté ///

template<class TM, class TV> TV prod_mat_vec_col(const TM &M, const TV &V)
{
    static const unsigned nb_vec = V.size();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    TV res;
    res.set(0.);
    for (unsigned i=0; i<nb_vec; ++i)
    {
        for (unsigned k=0; k<nb_dim; ++k)
        {
            res[i] += M(i,k) * V[k];
        }
        for (unsigned k=nb_dim; k<nb_vec; ++k)
        {
            res[i] += 2. * M(i,k) * V[k];
        }
    }
    return res;
}

/// ------------------------------- /// produit doublement contracté ///

template<class TM> typename TM::T prod_contr_mat_col(const TM &M1, const TM &M2)
{
    static const unsigned nb_vec = M1.nb_rows();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    typename TM::T res = 0.;
    for (unsigned i=0; i<nb_dim; ++i)
    {
        for (unsigned j=0; j<nb_dim; ++j)
        {
            res += M1(i,j) * M2(i,j);
        }
        for (unsigned j=nb_dim; j<nb_vec; ++j)
        {
            res += 2. * M1(i,j) * M2(i,j);
        }
    }
    for (unsigned i=nb_dim; i<nb_vec; ++i)
    {
        for (unsigned j=0; j<nb_dim; ++j)
        {
            res += 2. * M1(i,j) * M2(i,j);
        }
        for (unsigned j=0; j<nb_dim; ++j)
        {
            res += 4. * M1(i,j) * M2(i,j);
        }
    }
    return res;
}

template<class TM> typename TM::T self_prod_contr_mat_col(const TM &M)
{
    return prod_contr_mat_col(M, M);
}

/// ----------------------------------------------------- /// normes ///

template<class TM> typename TM::T norm_2_mat_col(const TM &M)
{
    return LMT::sqrt(self_prod_contr_mat_col(M));
}

#endif
