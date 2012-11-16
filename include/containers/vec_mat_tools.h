#ifndef vec_mat_tools_h
#define vec_mat_tools_h

#include <containers/mat.h>

///
/// for normal matrices
///

/// antisym_part_mat
template<class TM> TM antisym_part_mat(const TM &M)
{
    return (M - LMT::trans(M)) / 2;
}

/// sym_part_mat
template<class TM> TM sym_part_mat(const TM &M)
{
    return (M + LMT::trans(M)) / 2;
}

/// norm_2_mat
template<class TM> typename TM::T norm_2_mat(const TM &M)
{
    return LMT::sqrt(self_prod_contr(M));
}

/// norm_inf_mat
template<class TM> typename TM::T norm_inf_mat(const TM &M)
{
    typename TM::T res = 0.;
    for(unsigned i=0; i<M.nb_rows(); ++i)
    {
        for(unsigned j=0; j<M.nb_cols(); ++j)
        {
            res = LMT::max(res, LMT::abs(M(i, j)));
        }
    }
    return res;
}

/// prod_contr
template<class TM> typename TM::T prod_contr(const TM &M1, const TM &M2)
{
    static const unsigned dim = M1.nb_rows();

    typename TM::T res = 0.;
    for(unsigned i=0; i<dim; ++i)
    {
        for(unsigned j=0; j<dim; ++j)
        {
            res += M1(i,j) * M2(i,j);
        }
    }
    return res;
}

/// self_prod_contr
template<class TM> typename TM::T self_prod_contr(const TM &M)
{
    return prod_contr(M, M);
}

/// pow_mat_sym
template<class TM> TM pow_mat_sym(TM M, const unsigned &p)
{
    static const unsigned dim = M.nb_rows();

    LMT::Mat<typename TM::T, LMT::Sym<> > res;
    res.resize(dim);
    res.set(0.);
    res.diag() = 1.;
    for(unsigned k=0; k<p; ++k)
    {
        res *= M;
    }
    return res;
}

///
/// for vectors representing second order symmetric tensors
///

/// vec_col_to_vec_col_with_sqr
template<class TV> TV vec_col_to_vec_col_with_sqr(TV V)
{
    static const unsigned dim_vec = V.size();
    static const unsigned dim = std::ceil(double(dim_vec)/2);

    for (unsigned i=dim; i<dim_vec; ++i)
    {
        V[i] *= sqrt(2.);
    }
    return V;
}

/// vec_col_to_vec_col_with_two
template<class TV> TV vec_col_to_vec_col_with_two(TV V)
{
    static const unsigned dim_vec = V.size();
    static const unsigned dim = std::ceil(double(dim_vec)/2);

    for (unsigned i=dim; i<dim_vec; ++i)
    {
        V[i] *= 2.;
    }
    return V;
}

/// vec_col_with_sqr_to_vec_col
template<class TV> TV vec_col_with_sqr_to_vec_col(TV V)
{
    static const unsigned dim_vec = V.size();
    static const unsigned dim = std::ceil(double(dim_vec)/2);

    for (unsigned i=dim; i<dim_vec; ++i)
    {
        V[i] /= sqrt(2.);
    }
    return V;
}

/// vec_col_with_sqr_to_vec_col_with_two
template<class TV> TV vec_col_with_sqr_to_vec_col_with_two(TV V)
{
    static const unsigned dim_vec = V.size();
    static const unsigned dim = std::ceil(double(dim_vec)/2);

    for (unsigned i=dim; i<dim_vec; ++i)
    {
        V[i] *= sqrt(2.);
    }
    return V;
}

/// vec_col_with_two_to_vec_col
template<class TV> TV vec_col_with_two_to_vec_col(TV V)
{
    static const unsigned dim_vec = V.size();
    static const unsigned dim = std::ceil(double(dim_vec)/2);

    for (unsigned i=dim; i<dim_vec; ++i)
    {
        V[i] /= 2.;
    }
    return V;
}

/// vec_col_with_two_to_vec_col_with_sqr
template<class TV> TV vec_col_with_two_to_vec_col_with_sqr(TV V)
{
    static const unsigned dim_vec = V.size();
    static const unsigned dim = std::ceil(double(dim_vec)/2);

    for (unsigned i=dim; i<dim_vec; ++i)
    {
        V[i] /= sqrt(2.);
    }
    return V;
}

/// vec_col_to_mat_sym
template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > vec_col_to_mat_sym(const TV &V)
{
    static const unsigned dim_vec = V.size();

    LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > M;

    if (dim_vec == 3)
    {
        M.resize(2);
        M.set(0.);
        M(0, 0) = V[0];
        M(1, 1) = V[1];
        M(0, 1) = V[2];
        return M;
    }

    if (dim_vec == 6)
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

/// vec_col_with_sqr_to_mat_sym
template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > vec_col_with_sqr_to_mat_sym(const TV &V)
{
    static const unsigned dim_vec = V.size();

    LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > M;

    if (dim_vec == 3)
    {
        M.resize(2);
        M.set(0.);
        M(0, 0) = V[0];
        M(1, 1) = V[1];
        M(0, 1) = V[2]/sqrt(2.);
        return M;
    }

    if (dim_vec == 6)
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

/// vec_col_with_two_to_mat_sym
template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > vec_col_with_two_to_mat_sym(const TV &V)
{
    static const unsigned dim_vec = V.size();

    LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T, LMT::Sym<> > M;

    if (dim_vec == 3)
    {
        M.resize(2);
        M.set(0.);
        M(0, 0) = V[0];
        M(1, 1) = V[1];
        M(0, 1) = V[2]/2.;
        return M;
    }

    if (dim_vec == 6)
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

/// trace_vec_col
template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T trace_vec_col(const TV &V)
{
    static const unsigned dim_vec = V.size();
    static const unsigned dim = std::ceil(double(dim_vec)/2);

    typename LMT::TypeReduction<LMT::Multiplies, TV>::T res = 0.;
    for (unsigned i=0; i<dim; ++i)
    {
        res += V[i];
    }
    return res;
}

/// trace_vec_col_with_sqr
template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T trace_vec_col_with_sqr(const TV &V)
{
    return trace_vec_col(V);
}

/// trace_vec_col_with_two
template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T trace_vec_col_with_two(const TV &V)
{
    return trace_vec_col(V);
}

/// trace_sym_vec_col
template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T trace_sym_vec_col(const TV &V1, const TV &V2)
{
    static const unsigned dim_vec = V1.size();
    static const unsigned dim = std::ceil(double(dim_vec)/2);

    typename LMT::TypeReduction<LMT::Multiplies, TV>::T res = 0.;
    for (unsigned i=0; i<dim; ++i)
    {
        res += V1[i] * V2[i];
    }
    for (unsigned i=dim; i<dim_vec; ++i)
    {
        res += 2 * V1[i] * V2[i];
    }
    return res;
}

/// trace_sym_vec_col_with_sqr
template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T trace_sym_vec_col_with_sqr(const TV &V1, const TV &V2)
{
    return dot(V1, V2);
}

/// self_trace_sym_vec_col
template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T self_trace_sym_vec_col(const TV &V)
{
    return trace_sym_vec_col(V, V);
}

/// self_trace_sym_vec_col_with_sqr
template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T self_trace_sym_vec_col_with_sqr(const TV &V)
{
    return trace_sym_vec_col_with_sqr(V, V);
}

/// norm_2_vec_col
template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T norm_2_vec_col(const TV &V)
{
    return LMT::sqrt(self_trace_sym_vec_col(V));
}

/// norm_2_vec_col_with_sqr
template<class TV> typename LMT::TypeReduction<LMT::Multiplies, TV>::T norm_2_vec_col_with_sqr(const TV &V)
{
    return LMT::sqrt(self_trace_sym_vec_col_with_sqr(V));
}

/// pow_vec_col
template<class TV> TV pow_vec_col(const TV &V, const unsigned &p)
{
    return mat_sym_to_vec_col(pow_mat_sym(vec_col_to_mat_sym(V), p));
}

/// pow_vec_col_with_sqr
template<class TV> TV pow_vec_col_with_sqr(const TV &V, const unsigned &p)
{
    return mat_sym_to_vec_col_with_sqr(pow_mat_sym(vec_col_with_sqr_to_mat_sym(V), p));
}

/// tens_prod_vec_col_with_sqr
template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T> tens_prod_vec_col_with_sqr(const TV &V1, const TV &V2) // pour le type on a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    static const unsigned dim = V1.size();

    LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T> res(dim);
    for(unsigned i=0; i<dim; ++i)
    {
        for (unsigned j=0; j<dim; ++j)
        {
            res(i, j) = V1[i] * V2[j];
        }
    }
    return res;
}

/// self_tens_prod_vec_col_with_sqr
template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T> self_tens_prod_vec_col_with_sqr(const TV &V) // pour le type on a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return tens_prod_vec_col_with_sqr(V, V);
}

/// tens_prod_vec_col
template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T> tens_prod_vec_col(const TV &V1, const TV &V2) // pour le type on a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return tens_prod_vec_col_with_sqr(vec_col_to_vec_col_with_sqr(V1), vec_col_to_vec_col_with_sqr(V2));
}

/// self_tens_prod_vec_col
template<class TV> LMT::Mat<typename LMT::TypeReduction<LMT::Multiplies, TV>::T> self_tens_prod_vec_col(const TV &V) // pour le type on a pas de typename TV::T car les vecteurs peuvent être hétérogènes
{
    return tens_prod_vec_col(V, V);
}

///
/// for matrices representing second order symmetric tensors
///

/// mat_sym_to_vec_col
template<class TM> LMT::Vec<typename TM::T> mat_sym_to_vec_col(const TM &M)
{
    static const unsigned dim = M.nb_cols();

    if (dim == 2)
    {
        LMT::Vec<typename TM::T> V;
        V.resize(3);
        V[0] = M(0, 0);
        V[1] = M(1, 1);
        V[2] = M(0, 1);
        return V;
    }

    if (dim == 3)
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

/// mat_sym_to_vec_col_with_sqr
template<class TM> LMT::Vec<typename TM::T> mat_sym_to_vec_col_with_sqr(const TM &M)
{
    static const unsigned dim = M.nb_cols();

    if (dim == 2)
    {
        LMT::Vec<typename TM::T> V;
        V.resize(3);
        V[0] = M(0, 0);
        V[1] = M(1, 1);
        V[2] = sqrt(2.) * M(0, 1);
        return V;
    }

    if (dim == 3)
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

/// mat_sym_to_vec_col_with_two
template<class TM> LMT::Vec<typename TM::T> mat_sym_to_vec_col_with_two(const TM &M)
{
    static const unsigned dim = M.nb_cols();

    if (dim == 2)
    {
        LMT::Vec<typename TM::T> V;
        V.resize(3);
        V[0] = M(0, 0);
        V[1] = M(1, 1);
        V[2] = 2. * M(0, 1);
        return V;
    }

    if (dim == 3)
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

#endif
