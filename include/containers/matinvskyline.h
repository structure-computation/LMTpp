//
// C++ Interface: matinvskyline
//
// Description:
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matinvskyline_HEADER
#define LMT_matinvskyline_HEADER

namespace LMT {

// ------------------------------------------------------------------------------------------------------------------
// triangular
// ------------------------------------------------------------------------------------------------------------------
/** \relates Mat
    \todo OPTIMIZE
*/
template<class TT,int s,class O,class IO,class TF,class T3,int s3>
Vec< typename TypePromote< Multiplies, typename Mat<TT,TriUpper<s>,SkyLine<O>,IO>::T, typename Vec<T3,s3>::template SubType<0> ::T >::T, s >
solve_using_factorization( const Mat<TT,TriUpper<s>,SkyLine<O>,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    typedef typename TypePromote< Multiplies, typename Mat<TT,TriUpper<s>,SkyLine<O>,IO>::T, typename Vec<T3,s3>::template SubType<0>::T>::T TR;
    Vec<TR> res;
    if ( O::col_oriented ) {
        res.resize( mat.nb_rows() );
        for(int i=mat.nb_rows()-1;i>=0;--i) {
            TR ondiag = mat(i,i);

            TR tmp = b[i];
            for(unsigned j=i+1;j<mat.ubounds[i];++j)
                tmp -= mat(i,j) * res[ j ];
            res[i] = tmp / ondiag;
        }
    } else {
        res = b;
        for(int i=mat.nb_rows()-1;i>=0;--i) {
            TR ondiag = mat(i,i);

            TR tmp = res[i] / ondiag;
            res[i] = tmp;
            for(unsigned j=0;j<mat.ubounds[i];++j)
                res[ j ] -= mat(i,j) * tmp;
        }
    }

    return res;

}


/** \relates Mat
    \todo OPTIMIZE
*/
template<class TT,int s,class O,class IO,class TF,class T3,int s3>
Vec< typename TypePromote< Multiplies, typename Mat<TT,TriLower<s>,SkyLine<O>,IO>::T, typename Vec<T3,s3>::template SubType<0> ::T>::T ,s > solve_using_factorization( const Mat<TT,TriLower<s>,SkyLine<O>,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    typedef typename TypePromote< Multiplies, typename Mat<TT,TriLower<s>,SkyLine<O>,IO>::T, typename Vec<T3,s3>::template SubType<0>::T>::T TR;
    Vec<TR> res;
    res.resize( mat.nb_rows() );

    if ( O::col_oriented ) {
        res.resize( mat.nb_rows() );
        for(unsigned i=0;i<mat.nb_rows();++i) {
            TR ondiag = mat(i,i);

            TR tmp = b[i];
            for(unsigned j=mat.lbounds[i];j<i;++j)
                tmp -= mat(i,j) * res[ j ];
            res[i] = tmp / ondiag;
        }
    } else {
        res = b;
        for(unsigned i=0;i<mat.nb_rows();++i) {
            TR ondiag = mat(i,i);

            TR tmp = res[i] / ondiag;
            res[i] = tmp;
            for(unsigned j=i+1;j<mat.ubounds[i];++j)
                res[ j ] -= mat(i,j) * tmp;
        }
    }

    return res;
}


/** \relates Mat
    TRANS version
    \todo OPTIMIZE
*/
template<class TM,bool ctm,int s,class O,class IO,class TF,class T3,int s3>
Vec< typename TypePromote< Multiplies, typename TM::T, typename Vec<T3,s3>::template SubType<0> ::T>::T ,s >
solve_using_factorization( const Mat<MatTrans<TM,ctm>,TriLower<s>,SkyLine<O>,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    return solve_using_factorization( *reinterpret_cast<const Mat<typename TM::T,TriLower<s>,SkyLine<O> >*>(mat.ptr.val), fact, b );
}

/** \relates Mat
    TRANS version
    \todo OPTIMIZE
*/
template<class TM,bool ctm,int s,class O,class IO,class TF,class T3,int s3>
Vec< typename TypePromote< Multiplies, typename TM::T, typename Vec<T3,s3>::template SubType<0> ::T >::T ,s >
solve_using_factorization( const Mat<MatTrans<TM,ctm>,TriUpper<s>,SkyLine<O>,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    return solve_using_factorization( *reinterpret_cast<const Mat<typename TM::T,TriUpper<s>,SkyLine<O> >*>(mat.ptr.val), fact, b );
}

// ------------------------------------------------------------------------------------------------------------------
// sym
// ------------------------------------------------------------------------------------------------------------------
/** \relates Mat
*/
template<class T,int s,class TF,class IO>
bool get_factorization( const Mat<T,Sym<s,false>,SparseLine<Col>,IO> &m, TF &mat ) {
    //const unsigned defpos = true;
    // m -> mat (skyline)
    Vec<unsigned> lb;
    lb.resize( m.nb_rows() );
    for(unsigned i=0;i<m.nb_rows();++i) {
        if ( m.data[i].indices.size()==0 ) {
            std::cerr << "line " << i << " in sparse matrix does not have any non-zero terms (maybe a lonely node)." << std::endl;
            return false;
        }
        lb[i] = m.data[i].indices.front();
    }
    mat.resize( m.nb_rows(), m.nb_rows(), lb );
    //PRINT( lb );
    mat.values.set(T(0));
    for(unsigned i=0;i<m.nb_rows();++i)
        for(unsigned j=0;j<m.data[i].indices.size();++j)
            mat.cum_index[i][ m.data[i].indices[j] ] = m.data[i].data[j];

    //
    for(unsigned line=0;line<mat.nb_rows();++line) {
        // first step : factorization of a first triangle
        T *ptr = mat.cum_index[line];
        unsigned lbl = mat.lbounds[line];
        for(unsigned col=mat.lbounds[line];col<line;++col) {
            unsigned lb = max( mat.lbounds[col], lbl );
            ptr[col] = ( ptr[col] - dot_aligned_with_offset(mat.cum_index[col]+lb,ptr+lb,col-lb) ) / mat.cum_index[col][col];
        }
        T reg = ptr[line] - norm_2_p2( ptr + lbl, line - lbl );
        if (reg<=T(0))
            return false;
        ptr[line] = sqrt( reg );
    }
    return true;
//     //PRINTN(mat);
//     //
//     unsigned begin_col = 0;
//     unsigned nb_T_used = 0;
//     unsigned col;
//     for(unsigned line=0;line<mat.nb_rows();++line) {
//         // first step : factorization of a first triangle
//         T *ptr = mat.cum_index[line];
//         unsigned begin_col2 = max( mat.lbounds[line], begin_col );
//         for(col=begin_col2;col<line;++col) {
//             unsigned lb = max( mat.lbounds[col], begin_col2 );
//             T reg = ptr[col];
//             reg -= dot_aligned_with_offset(mat.cum_index[col]+lb,ptr+lb,col-lb);
//             reg /= mat.cum_index[col][col];
//             ptr[col] = reg;
//         }
//         T reg = ptr[line] - norm_2_p2( ptr + begin_col2, line-begin_col2 );
//         //PRINTN( norm_2_p2( ptr + begin_col2, line-begin_col2 ) );
//         if (reg<=(T)0.0) {
//             //std::cout << line << " "  << begin_col2 << std::endl;
//             //PRINTN( norm_2_p2( ptr + begin_col2, line-begin_col2 ) );
//             //for(unsigned i=0;i<line;++i) std::cout << ptr[i] << std::endl;
//             return false;
//         }
//         ptr[line] = sqrt( reg );
// 
//         nb_T_used += line-begin_col2;
// 
//         // second step : factorization of the sub rectangular area using the triangle
//         //  and partial factorization of the triangular areas on the right using the upper rectangular areas
//         if ( nb_T_used > LMT_FACT_TRI*LMT_L1_CACHE_SIZE/sizeof(T) ) {
//             ++line;
//             unsigned end_col = line;
// 
//             // calculation of the sub rectangular area down to the triangle (to the bottom)
//             for(;line<mat.nb_rows();++line) {
//                 ptr = mat.cum_index[line];
//                 begin_col2 = max( mat.lbounds[line], begin_col );
//                 for(col=begin_col2;col<end_col;++col) {
//                     unsigned lb = max( mat.lbounds[col], begin_col2 );
//                     ptr[col] = ( ptr[col] - dot_aligned_with_offset(mat.cum_index[col]+lb, ptr+lb, col-lb) ) / mat.cum_index[col][col];
//                 }
//             }
// 
//             // partial calculation of the triangular area on the right of the preceding rectangular area
//             nb_T_used = 0;
//             unsigned begin_block = end_col;
//             for(line=end_col;line<mat.nb_rows();++line) {
//                 if (mat.lbounds[line]>end_col)
//                     continue;
//                 begin_col2 = max( mat.lbounds[line], begin_col );
//                 ptr = mat.cum_index[line];
//                 for(col=begin_block;col<line;++col) {
//                     unsigned lb = max( mat.lbounds[col], begin_col2 );
//                     if (end_col>lb)
//                         ptr[col] -= dot_aligned_with_offset(mat.cum_index[col]+lb, ptr+lb, end_col-lb);
//                 }
//                 ptr[line] -= norm_2_p2( ptr + begin_col2, end_col-begin_col2 );
// 
//                 nb_T_used += end_col-begin_col2;
//                 // for the line2\in rest of the lines, sp( col\in [begin_block,line[, line2 )
//                 if ( nb_T_used > LMT_FACT_RECT*LMT_L1_CACHE_SIZE/sizeof(T) ) {
//                     for(unsigned line2=line+1;line2<mat.nb_rows();++line2) {
//                         begin_col2 = max( mat.lbounds[line2], begin_col );
//                         ptr = mat.cum_index[line2];
//                         for(col=begin_block;col<=line;++col) {
//                             unsigned lb = max( mat.lbounds[col], begin_col2 );
//                             if (end_col>lb)
//                                 ptr[col] -= dot_aligned_with_offset(mat.cum_index[col]+lb, ptr+lb, end_col-lb);
//                         }
//                     }
//                     begin_block = line+1;
//                     nb_T_used = 0;
//                 }
//             }
// 
//             line = end_col-1;
//             begin_col = end_col;
//             nb_T_used = 0;
//         }
// 
// 
//     }
//     return true;
}


/** \relates Mat
*/
template<class T,int s,class IO,class TF,class TV>
Vec< typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T ,s >
solve_using_factorization( const Mat<T,Sym<s,false>,SparseLine<Col>,IO> &mtoto, const TF &mat, const TV &b ) {
    typedef typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T TR;
    unsigned nb_lines=mat.nb_rows();
    
    Vec<TR,s> vec;
    vec.resize( nb_lines );
    for(unsigned i=0;i<b.size();++i)
        vec[i] = b[i];
    //
    for(unsigned line=0;line<mat.nb_rows();++line) {
        T *ptr = mat.cum_index[line];
        unsigned lb = mat.lbounds[line];
        vec[line] = ( vec[line] - dot_aligned_with_offset(ptr+lb,&vec[0]+lb,line-lb) ) / *(ptr+line);
    }

    //
    Vec<TR,s> tmpvec = vec;

    TR tmp;
    while (nb_lines--) {
        T *ptr = mat.cum_index[nb_lines];
        unsigned lb = mat.lbounds[nb_lines];
        tmp = tmpvec[nb_lines] / ptr[nb_lines];
        for(;lb<nb_lines;++lb)
            tmpvec[lb] -= ptr[lb] * tmp;
        vec[nb_lines] = tmp;
    }
    return vec;
}



// ------------------------------------------------------------------------------------------------------------------
// herm
// ------------------------------------------------------------------------------------------------------------------
/** \relates Mat
*/
template<class T,int s,class TF,class IO>
bool get_factorization( const Mat<T,Herm<s,false>,SparseLine<Col>,IO> &m, TF &mat ) {
    const unsigned defpos = true;
    // m -> mat (skyline)
    Vec<unsigned> lb;
    lb.resize( m.nb_rows() );
    for(unsigned i=0;i<m.nb_rows();++i) {
        lb[i] = m.data[i].indices.front();
    }
    mat.resize( m.nb_rows(), m.nb_rows(), lb );
    //PRINT( lb );
    mat.values.set(T(0));
    for(unsigned i=0;i<m.nb_rows();++i)
        for(unsigned j=0;j<m.data[i].indices.size();++j)
            mat.cum_index[i][ m.data[i].indices[j] ] = m.data[i].data[j];
    //
    unsigned begin_col = 0;
    unsigned nb_T_used = 0;
    unsigned col;
    for(unsigned line=0;line<mat.nb_rows();++line) {
        // first step : factorization of a first triangle
        T *ptr = mat.cum_index[line];
        unsigned begin_col2 = max( mat.lbounds[line], begin_col );
        for(col=begin_col2;col<line;++col) {
            unsigned lb = max( mat.lbounds[col], begin_col2 );
            T reg = ptr[col];
            reg -= dot_conj(ptr+lb,mat.cum_index[col]+lb,col-lb);
            reg /= mat.cum_index[col][col];
            ptr[col] = reg;
        }
        T reg = ptr[line] - norm_2_p2_conj( ptr + begin_col2, line-begin_col2 );
        ptr[line] = sqrt(real( reg ));

        nb_T_used += line-begin_col2;

        // second step : factorization of the sub rectangular area using the triangle
        //  and partial factorization of the triangular areas on the right using the upper rectangular areas
        if ( nb_T_used > LMT_FACT_TRI*LMT_L1_CACHE_SIZE/sizeof(T) ) {
            ++line;
            unsigned end_col = line;

            // calculation of the sub rectangular area down to the triangle (to the bottom)
            for(;line<mat.nb_rows();++line) {
                ptr = mat.cum_index[line];
                begin_col2 = max( mat.lbounds[line], begin_col );
                for(col=begin_col2;col<end_col;++col) {
                    unsigned lb = max( mat.lbounds[col], begin_col2 );
                    ptr[col] = ( ptr[col] - dot_conj(mat.cum_index[col]+lb, ptr+lb, col-lb) ) / mat.cum_index[col][col];
                }
            }

            // partial calculation of the triangular area on the right of the preceding rectangular area
            nb_T_used = 0;
            unsigned begin_block = end_col;
            for(line=end_col;line<mat.nb_rows();++line) {
                if (mat.lbounds[line]>end_col)
                    continue;
                begin_col2 = max( mat.lbounds[line], begin_col );
                ptr = mat.cum_index[line];
                for(col=begin_block;col<line;++col) {
                    unsigned lb = max( mat.lbounds[col], begin_col2 );
                    if (end_col>lb)
                        ptr[col] -= dot_conj(mat.cum_index[col]+lb, ptr+lb, end_col-lb);
                }
                ptr[line] -= norm_2_p2_conj( ptr + begin_col2, end_col-begin_col2 );

                nb_T_used += end_col-begin_col2;
                // for the line2\in rest of the lines, sp( col\in [begin_block,line[, line2 )
                if ( nb_T_used > LMT_FACT_RECT*LMT_L1_CACHE_SIZE/sizeof(T) ) {
                    for(unsigned line2=line+1;line2<mat.nb_rows();++line2) {
                        begin_col2 = max( mat.lbounds[line2], begin_col );
                        ptr = mat.cum_index[line2];
                        for(col=begin_block;col<=line;++col) {
                            unsigned lb = max( mat.lbounds[col], begin_col2 );
                            if (end_col>lb)
                                ptr[col] -= dot_conj(mat.cum_index[col]+lb, ptr+lb, end_col-lb);
                        }
                    }
                    begin_block = line+1;
                    nb_T_used = 0;
                }
            }

            line = end_col-1;
            begin_col = end_col;
            nb_T_used = 0;
        }


    }
    return true;
}


/** \relates Mat
*/
template<class T,int s,class IO,class TF,class TV>
Vec< typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T ,s >
solve_using_factorization( const Mat<T,Herm<s,false>,SparseLine<Col>,IO> &mtoto, const TF &mat, const TV &b ) {
    typedef typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T TR;
    unsigned nb_lines=mat.nb_rows();
    
    Vec<TR,s> vec;
    vec.resize( nb_lines );
    for(unsigned i=0;i<b.size();++i)
        vec[i] = b[i];
    //
    for(unsigned line=0;line<mat.nb_rows();++line) {
        T *ptr = mat.cum_index[line];
        unsigned lb = mat.lbounds[line];
        vec[line] = ( vec[line] - dot_conj(&vec[0]+lb,ptr+lb,line-lb) ) / *(ptr+line);
    }

    //
    Vec<TR,s> tmpvec = vec;

    TR tmp;
    while (nb_lines--) {
        T *ptr = mat.cum_index[nb_lines];
        unsigned lb = mat.lbounds[nb_lines];
        tmp = tmpvec[nb_lines] / ptr[nb_lines];
        for(;lb<nb_lines;++lb)
            tmpvec[lb] -= ptr[lb] * tmp;
        vec[nb_lines] = tmp;
    }
    return vec;
}

// ------------------------------------------------------------------------------------------------------------------
// herm skyline
// ------------------------------------------------------------------------------------------------------------------
/** \relates Mat
*/
template<class T,int s,class TF,class IO>
bool get_factorization( const Mat<T,Herm<s,false>,SkyLine<Col>,IO> &m, TF &mat ) {
    const unsigned defpos = true;
    // m -> mat (skyline)
    mat = m;
    //
    unsigned begin_col = 0;
    unsigned nb_T_used = 0;
    unsigned col;
    for(unsigned line=0;line<mat.nb_rows();++line) {
        // first step : factorization of a first triangle
        T *ptr = mat.cum_index[line];
        unsigned begin_col2 = max( mat.lbounds[line], begin_col );
        for(col=begin_col2;col<line;++col) {
            unsigned lb = max( mat.lbounds[col], begin_col2 );
            T reg = ptr[col];
            reg -= dot_conj(ptr+lb,mat.cum_index[col]+lb,col-lb);
            reg /= mat.cum_index[col][col];
            ptr[col] = reg;
        }
        T reg = ptr[line] - norm_2_p2_conj( ptr + begin_col2, line-begin_col2 );
        ptr[line] = sqrt(real( reg ));

        nb_T_used += line-begin_col2;

        // second step : factorization of the sub rectangular area using the triangle
        //  and partial factorization of the triangular areas on the right using the upper rectangular areas
        if ( nb_T_used > LMT_FACT_TRI*LMT_L1_CACHE_SIZE/sizeof(T) ) {
            ++line;
            unsigned end_col = line;

            // calculation of the sub rectangular area down to the triangle (to the bottom)
            for(;line<mat.nb_rows();++line) {
                ptr = mat.cum_index[line];
                begin_col2 = max( mat.lbounds[line], begin_col );
                for(col=begin_col2;col<end_col;++col) {
                    unsigned lb = max( mat.lbounds[col], begin_col2 );
                    ptr[col] = ( ptr[col] - dot_conj(mat.cum_index[col]+lb, ptr+lb, col-lb) ) / mat.cum_index[col][col];
                }
            }

            // partial calculation of the triangular area on the right of the preceding rectangular area
            nb_T_used = 0;
            unsigned begin_block = end_col;
            for(line=end_col;line<mat.nb_rows();++line) {
                if (mat.lbounds[line]>end_col)
                    continue;
                begin_col2 = max( mat.lbounds[line], begin_col );
                ptr = mat.cum_index[line];
                for(col=begin_block;col<line;++col) {
                    unsigned lb = max( mat.lbounds[col], begin_col2 );
                    if (end_col>lb)
                        ptr[col] -= dot_conj(mat.cum_index[col]+lb, ptr+lb, end_col-lb);
                }
                ptr[line] -= norm_2_p2_conj( ptr + begin_col2, end_col-begin_col2 );

                nb_T_used += end_col-begin_col2;
                // for the line2\in rest of the lines, sp( col\in [begin_block,line[, line2 )
                if ( nb_T_used > LMT_FACT_RECT*LMT_L1_CACHE_SIZE/sizeof(T) ) {
                    for(unsigned line2=line+1;line2<mat.nb_rows();++line2) {
                        begin_col2 = max( mat.lbounds[line2], begin_col );
                        ptr = mat.cum_index[line2];
                        for(col=begin_block;col<=line;++col) {
                            unsigned lb = max( mat.lbounds[col], begin_col2 );
                            if (end_col>lb)
                                ptr[col] -= dot_conj(mat.cum_index[col]+lb, ptr+lb, end_col-lb);
                        }
                    }
                    begin_block = line+1;
                    nb_T_used = 0;
                }
            }

            line = end_col-1;
            begin_col = end_col;
            nb_T_used = 0;
        }


    }
    return true;
}


/** \relates Mat
*/
template<class T,int s,class IO,class TF,class TV>
Vec< typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T ,s >
solve_using_factorization( const Mat<T,Herm<s,false>,SkyLine<Col>,IO> &m, const TF &mat, const TV &b ) {
    typedef typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T TR;
    unsigned nb_lines=mat.nb_rows();
    
    Vec<TR,s> vec;
    vec.resize( nb_lines );
    for(unsigned i=0;i<b.size();++i)
        vec[i] = b[i];
    //
    for(unsigned line=0;line<mat.nb_rows();++line) {
        T *ptr = mat.cum_index[line];
        unsigned lb = mat.lbounds[line];
        vec[line] = ( vec[line] - dot_conj(&vec[0]+lb,ptr+lb,line-lb) ) / *(ptr+line);
    }

    //
    Vec<TR,s> tmpvec = vec;

    TR tmp;
    while (nb_lines--) {
        T *ptr = mat.cum_index[nb_lines];
        unsigned lb = mat.lbounds[nb_lines];
        tmp = tmpvec[nb_lines] / ptr[nb_lines];
        for(;lb<nb_lines;++lb)
            tmpvec[lb] -= ptr[lb] * tmp;
        vec[nb_lines] = tmp;
    }
    return vec;
}

// ------------------------------------------------------------------------------------------------------------------
// sym skyline
// ------------------------------------------------------------------------------------------------------------------
/** \relates Mat
*/
template<class T,int s,class TF,class IO>
bool get_factorization( const Mat<T,Sym<s,false>,SkyLine<Col>,IO> &m, TF &mat ) {
    //const unsigned defpos = true;
    // m -> mat (skyline)
    mat = m;
    //
    unsigned begin_col = 0;
    unsigned nb_T_used = 0;
    unsigned col;
    for(unsigned line=0;line<mat.nb_rows();++line) {
        // first step : factorization of a first triangle
        T *ptr = mat.cum_index[line];
        unsigned begin_col2 = max( mat.lbounds[line], begin_col );
        for(col=begin_col2;col<line;++col) {
            unsigned lb = max( mat.lbounds[col], begin_col2 );
            T reg = ptr[col];
            reg -= dot_aligned_with_offset(ptr+lb,mat.cum_index[col]+lb,col-lb);
            reg /= mat.cum_index[col][col];
            ptr[col] = reg;
        }
        T reg = ptr[line] - norm_2_p2( ptr + begin_col2, line-begin_col2 );
        ptr[line] = sqrt(( reg ));

        nb_T_used += line-begin_col2;

        // second step : factorization of the sub rectangular area using the triangle
        //  and partial factorization of the triangular areas on the right using the upper rectangular areas
        if ( nb_T_used > LMT_FACT_TRI*LMT_L1_CACHE_SIZE/sizeof(T) ) {
            ++line;
            unsigned end_col = line;

            // calculation of the sub rectangular area down to the triangle (to the bottom)
            for(;line<mat.nb_rows();++line) {
                ptr = mat.cum_index[line];
                begin_col2 = max( mat.lbounds[line], begin_col );
                for(col=begin_col2;col<end_col;++col) {
                    unsigned lb = max( mat.lbounds[col], begin_col2 );
                    ptr[col] = ( ptr[col] - dot_aligned_with_offset(mat.cum_index[col]+lb, ptr+lb, col-lb) ) / mat.cum_index[col][col];
                }
            }

            // partial calculation of the triangular area on the right of the preceding rectangular area
            nb_T_used = 0;
            unsigned begin_block = end_col;
            for(line=end_col;line<mat.nb_rows();++line) {
                if (mat.lbounds[line]>end_col)
                    continue;
                begin_col2 = max( mat.lbounds[line], begin_col );
                ptr = mat.cum_index[line];
                for(col=begin_block;col<line;++col) {
                    unsigned lb = max( mat.lbounds[col], begin_col2 );
                    if (end_col>lb)
                        ptr[col] -= dot_aligned_with_offset(mat.cum_index[col]+lb, ptr+lb, end_col-lb);
                }
                ptr[line] -= norm_2_p2( ptr + begin_col2, end_col-begin_col2 );

                nb_T_used += end_col-begin_col2;
                // for the line2\in rest of the lines, sp( col\in [begin_block,line[, line2 )
                if ( nb_T_used > LMT_FACT_RECT*LMT_L1_CACHE_SIZE/sizeof(T) ) {
                    for(unsigned line2=line+1;line2<mat.nb_rows();++line2) {
                        begin_col2 = max( mat.lbounds[line2], begin_col );
                        ptr = mat.cum_index[line2];
                        for(col=begin_block;col<=line;++col) {
                            unsigned lb = max( mat.lbounds[col], begin_col2 );
                            if (end_col>lb)
                                ptr[col] -= dot_aligned_with_offset(mat.cum_index[col]+lb, ptr+lb, end_col-lb);
                        }
                    }
                    begin_block = line+1;
                    nb_T_used = 0;
                }
            }

            line = end_col-1;
            begin_col = end_col;
            nb_T_used = 0;
        }


    }
    return true;
}


/** \relates Mat
*/
template<class T,int s,class IO,class TF,class TV>
Vec< typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T ,s >
solve_using_factorization( const Mat<T,Sym<s,false>,SkyLine<Col>,IO> &mtoto, const TF &mat, const TV &b ) {
    typedef typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T TR;
    unsigned nb_lines=mat.nb_rows();
    
    Vec<TR,s> vec;
    vec.resize( nb_lines );
    for(unsigned i=0;i<b.size();++i)
        vec[i] = b[i];
    //
    for(unsigned line=0;line<mat.nb_rows();++line) {
        T *ptr = mat.cum_index[line];
        unsigned lb = mat.lbounds[line];
        vec[line] = ( vec[line] - dot_aligned_with_offset(&vec[0]+lb,ptr+lb,line-lb) ) / ptr[line];
    }

    //
    Vec<TR,s> tmpvec = vec;

    TR tmp;
    while (nb_lines--) {
        T *ptr = mat.cum_index[nb_lines];
        unsigned lb = mat.lbounds[nb_lines];
        tmp = tmpvec[nb_lines] / ptr[nb_lines];
        for(;lb<nb_lines;++lb)
            tmpvec[lb] -= ptr[lb] * tmp;
        vec[nb_lines] = tmp;
    }
    return vec;
}


};

#endif // LMT_matinvskyline_HEADER
