#ifndef vec_mat_tools_h
#define vec_mat_tools_h

#include <containers/mat.h>

///      ///////////////////////////////////////////////////////////////
/// ---- /// for vectors representing second order symmetric tensors ///
///      ///////////////////////////////////////////////////////////////

/// ------------------- /// conversions between vectors and matrices ///

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

template<class TM> LMT::Vec<typename TM::T> mat_sym_to_vec_col(const TM &M)
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

/// ------------------------------------------------------ /// trace ///

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T trace_vec_col(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    static const unsigned nb_vec = V.size();
    static const unsigned nb_dim = std::ceil(double(nb_vec)/2);

    typename LMT::TypeReduction<LMT::Multiplies, TV>::T res = 0.;
    for (unsigned int i=0; i<nb_dim; ++i)
    {
        res += V[i];
    }
    return res;
}

/// ------------------------------------------- /// produit scalaire ///

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T dot_vec_col(const TV &V1, const TV &V2)
{
    return LMT::dot(V1, V2);
}

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T self_dot_vec_col(const TV &V)
{
    return LMT::dot(V, V);
}

/// ---------------------------------------------------- /// produit ///

// le produit de deux matrices symétriques n'est symétrique que si les deux matrices commutent
// ici on ne le définit que pour une matrice avec elle-même, auquel cas le produit est forcément symétrique

template<class TV> TV self_prod_vec_col(const TV &V)
{
    return mat_sym_to_vec_col(vec_col_to_mat_sym(V) * vec_col_to_mat_sym(V));
}

template<class TV> TV double_prod_vec_col(const TV &V1, const TV &V2)
{
    return mat_sym_to_vec_col(vec_col_to_mat_sym(V2) * vec_col_to_mat_sym(V1) * vec_col_to_mat_sym(V2));
}

/// -------------------------------------------------- /// puissance ///

template<class TM> TM pow_mat_sym(TM M, const unsigned &p)
{
    static const unsigned nb_dim = M.nb_rows();

    TM res;
    res.resize(nb_dim);
    res.set(0.);
    res.diag() = 1.;
    for (unsigned int k=0; k<p; ++k)
    {
        res *= M;
    }
    return res;
}

template<class TV> TV pow_vec_col(const TV &V, const unsigned &p)
{
    return mat_sym_to_vec_col(pow_mat_sym(vec_col_to_mat_sym(V), p));
}

/// ------------------------------------------ /// produit tensoriel ///

template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Gen<> > tens_prod_vec_col(const TV &V1, const TV &V2) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    static const unsigned nb_vec = V1.size();

    LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T> res(nb_vec);
    for (unsigned int i=0; i<nb_vec; ++i)
    for (unsigned int j=0; j<nb_vec; ++j)
    {
        res(i,j) = V1[i] * V2[j];
    }
    return res;
}

template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > self_tens_prod_vec_col(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return tens_prod_vec_col(V, V);
}

/// -------------------------------- /// produit tensoriel symétrisé ///

template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Gen<> > sym_tens_prod_vec_col(const TV &V1, const TV &V2) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    static const unsigned nb_vec = V1.size();

    LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Gen<> > res(nb_vec);
    if (nb_vec == 3)
    {
        res(0,0) = V1[0] * V2[0];
        res(0,1) = V1[2] * V2[2];

        res(0,2) = (sqrt(2.)/2) * (V1[0] * V2[2] + V1[2] * V2[0]);

        res(1,0) = V1[2] * V2[2];
        res(1,1) = V1[1] * V2[1];

        res(1,2) = (sqrt(2.)/2) * (V1[2] * V2[1] + V1[1] * V2[2]);

        res(2,0) = sqrt(2) * V1[0] * V2[2];
        res(2,1) = sqrt(2) * V1[2] * V2[1];

        res(2,2) = V1[0] * V2[1] + V1[2] * V2[2];
    }

    if (nb_vec == 6)
    {
        res(0,0) = V1[0] * V2[0];
        res(0,1) = V1[3] * V2[3];
        res(0,2) = V1[4] * V2[4];

        res(0,3) = (sqrt(2.)/2) * (V1[0] * V2[3] + V1[3] * V2[0]);
        res(0,4) = (sqrt(2.)/2) * (V1[0] * V2[4] + V1[4] * V2[0]);
        res(0,5) = (sqrt(2.)/2) * (V1[3] * V2[4] + V1[4] * V2[3]);

        res(1,0) = V1[3] * V2[3];
        res(1,1) = V1[1] * V2[1];
        res(1,2) = V1[5] * V2[5];

        res(1,3) = (sqrt(2.)/2) * (V1[3] * V2[1] + V1[1] * V2[3]);
        res(1,4) = (sqrt(2.)/2) * (V1[3] * V2[5] + V1[5] * V2[3]);
        res(1,5) = (sqrt(2.)/2) * (V1[1] * V2[5] + V1[5] * V2[1]);

        res(2,0) = V1[4] * V2[4];
        res(2,1) = V1[5] * V2[5];
        res(2,2) = V1[2] * V2[2];

        res(2,3) = (sqrt(2.)/2) * (V1[4] * V2[5] + V1[5] * V2[4]);
        res(2,4) = (sqrt(2.)/2) * (V1[4] * V2[2] + V1[2] * V2[4]);
        res(2,5) = (sqrt(2.)/2) * (V1[5] * V2[2] + V1[2] * V2[5]);

        res(3,0) = sqrt(2.) * V1[0] * V2[3];
        res(3,1) = sqrt(2.) * V1[3] * V2[1];
        res(3,2) = sqrt(2.) * V1[4] * V2[5];

        res(3,3) = V1[0] * V2[1] + V1[3] * V2[3];
        res(3,4) = V1[0] * V2[5] + V1[4] * V2[3];
        res(3,5) = V1[3] * V2[5] + V1[4] * V2[1];

        res(4,0) = sqrt(2.) * V1[0] * V2[4];
        res(4,1) = sqrt(2.) * V1[3] * V2[5];
        res(4,2) = sqrt(2.) * V1[4] * V2[2];

        res(4,3) = V1[0] * V2[5] + V1[3] * V2[4];
        res(4,4) = V1[0] * V2[2] + V1[4] * V2[4];
        res(4,5) = V1[3] * V2[2] + V1[4] * V2[5];

        res(5,0) = sqrt(2.) * V1[3] * V2[4];
        res(5,1) = sqrt(2.) * V1[1] * V2[5];
        res(5,2) = sqrt(2.) * V1[5] * V2[2];

        res(5,3) = V1[3] * V2[5] + V1[1] * V2[4];
        res(5,4) = V1[3] * V2[2] + V1[5] * V2[4];
        res(5,5) = V1[1] * V2[2] + V1[5] * V2[5];
    }
    return res;
}

template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > self_sym_tens_prod_vec_col(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return sym_tens_prod_vec_col(V, V);
}

/// ----------------------------------------------------- /// normes ///

template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T norm_2_vec_col(const TV &V) // pour le type on n'a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return sqrt(self_dot_vec_col(V));
}

///     ////////////////////////////////////////////////////////////////
/// --- /// for matrices representing fourth order symmetric tensors ///
///     ////////////////////////////////////////////////////////////////

// only small symmetries are required for the representation of fourth order tensors as matrices
// large symmetry implies that the representation matrix is symmetric

/// ------------------------------------------- /// produit scalaire ///

template<class TM> typename TM::T dot_mat_col(const TM &M1, const TM &M2)
{
    static const unsigned nb_vec = M1.nb_rows();

    typename TM::T res = 0.;
    for (unsigned int i=0; i<nb_vec; ++i)
    {
        for (unsigned int j=0; j<nb_vec; ++j)
        {
            res += M1(i,j) * M2(i,j);
        }
    }
    return res;
}

template<class TM> typename TM::T self_dot_mat_col(const TM &M)
{
    return dot_mat_col(M, M);
}

/// --------------------------------------------- /// double produit ///

template<class TM, class TV> typename TM::T double_prod_mat_vec_col(const TM &M, const TV &V)
{
    TV tmp = M * V;
    return dot_vec_col(V, tmp);
}

/// ----------------------------------------------------- /// normes ///

template<class TM> typename TM::T norm_2_mat_col(const TM &M)
{
    return sqrt(self_dot_mat_col(M));
}

#endif
