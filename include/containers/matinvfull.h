//
// C++ Interface: matinvfull
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_matinvfull_HEADER
#define LMT_matinvfull_HEADER

namespace LMT {

// ------------------------------------------------------------------------------------------------------------------
// generic
// ------------------------------------------------------------------------------------------------------------------
/** \relates Mat
*/
template<class TT,int s,class Sto,class IO,class TF>
bool get_factorization( const Mat<TT,Gen<s,s>,Sto,IO> &m, TF &fact ) {
    typedef typename TF::first_type::T T;
    DEBUGASSERT( m.nb_rows()==m.nb_cols() );
    unsigned n = m.nb_rows();
    fact.first = m;
    fact.second = range(n);
    
    for(unsigned c=0;c<n;++c) {
        // find largest value in column c
        unsigned bl = c;
        for(unsigned j=c+1;j<n;++j)
            if ( LMT::abs_indication(fact.first(fact.second[j],c)) > LMT::abs_indication(fact.first(fact.second[bl],c)) )
                bl = j;
        swap( fact.second[c], fact.second[bl] );
        for(unsigned i=c+1;i<n;++i) {
            T f = fact.first( fact.second[i], c ) / fact.first( fact.second[c], c );
            fact.first.row( fact.second[i] )[ range(c+1,n) ] -= f * fact.first.row( fact.second[c] )[ range(c+1,n) ];
            fact.first( fact.second[i], c ) = f;
            
        }
    }
    return true;
}

template<class TT,int s,class Sto,class IO,class TF,class T3,int s3>
 Vec<typename TypePromote< Multiplies, typename Mat<TT,Gen<s,s>,Sto,IO>::T, typename Vec<T3,s3>::template SubType<0>::T>::T>
 solve_using_factorization( const Mat<TT,Gen<s,s>,Sto,IO> &mat, const TF &fact, const Vec<T3,s3> &b ) {
    typedef typename TypePromote< Multiplies, typename Mat<TT,Gen<s,s>,Sto,IO>::T, typename Vec<T3,s3>::template SubType<0>::T>::T TR;
    unsigned n = mat.nb_rows();
    Vec<TR> res; res.resize( n );
    for(unsigned it=0;it<n;++it) {
        unsigned i = fact.second[it];
        res[it] = b[ i ];
        for(unsigned j=0;j<it;++j)
            res[it] -= res[ j ] * fact.first( i, j );
    }
    for(int it=mat.nb_rows()-1;it>=0;--it) {
        TR tmp = res[it];
        unsigned i = fact.second[it];
        for(unsigned j=it+1;j<mat.nb_rows();++j)
            tmp -= fact.first(i,j) * res[j];
        res[it] = tmp / fact.first(i,it);
    }
    return res;
}

// ------------------------------------------------------------------------------------------------------------------
// symmetric
// ------------------------------------------------------------------------------------------------------------------
/** \relates Mat
*/
// template<class T,int s,class TF,class IO>
// bool get_factorization( const Mat<T,Sym<s,false>,Dense<Col>,IO> &m, TF &mat ) {
//     const unsigned defpos = true;
//     // m -> mat
//     mat = m;
//     //PRINTN(mat);
//     //
//     unsigned begin_col = 0;
//     unsigned nb_T_used = 0;
//     unsigned col;
//     for(unsigned line=0;line<mat.nb_rows();++line) {
//         // first step : factorization of a first triangle
//         T *ptr = &mat(line,0).ptr();
//         unsigned begin_col2 = begin_col;
//         for(col=begin_col2;col<line;++col) {
//             unsigned lb = begin_col2;
//             T reg = ptr[col];
//             reg -= dot_aligned_with_offset(&mat(col,0).ptr()+lb,ptr+lb,col-lb);
//             reg /= (T)mat(col,col);
//             ptr[col] = reg;
//         }
//         T reg = ptr[line] - norm_2_p2( ptr + begin_col2, line-begin_col2 );
//         //PRINTN( norm_2_p2( ptr + begin_col2, line-begin_col2 ) );
//         if (reg<=0.0) {
//             //std::cout << line << " "  << begin_col2 << std::endl;
//             std::cout << "bong" << std::endl;
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
//                 ptr = &mat(line,0).ptr();
//                 begin_col2 = begin_col;
//                 for(col=begin_col2;col<end_col;++col) {
//                     unsigned lb = begin_col2;
//                     ptr[col] = ( ptr[col] - dot_aligned_with_offset(mat.cum_index[col]+lb, ptr+lb, col-lb) ) / mat.cum_index[col][col];
//                 }
//             }
// 
//             // partial calculation of the triangular area on the right of the preceding rectangular area
//             nb_T_used = 0;
//             unsigned begin_block = end_col;
//             for(line=end_col;line<mat.nb_rows();++line) {
//                 begin_col2 = begin_col;
//                 ptr = &mat(line,0).ptr();
//                 for(col=begin_block;col<line;++col) {
//                     unsigned lb = max( mat.lbounds[col], begin_col2 );
//                     if (end_col>lb)
//                         ptr[col] -= dot_aligned_with_offset(&mat(col,0).ptr()+lb, ptr+lb, end_col-lb);
//                 }
//                 ptr[line] -= norm_2_p2( ptr + begin_col2, end_col-begin_col2 );
// 
//                 nb_T_used += end_col-begin_col2;
//                 // for the line2\in rest of the lines, sp( col\in [begin_block,line[, line2 )
//                 if ( nb_T_used > LMT_FACT_RECT*LMT_L1_CACHE_SIZE/sizeof(T) ) {
//                     for(unsigned line2=line+1;line2<mat.nb_rows();++line2) {
//                         begin_col2 = begin_col;
//                         ptr = &mat(line2,0).ptr();
//                         for(col=begin_block;col<=line;++col) {
//                             unsigned lb = max( &mat(col,0).ptr(), begin_col2 );
//                             if (end_col>lb)
//                                 ptr[col] -= dot_aligned_with_offset(&mat(col,0).ptr()+lb, ptr+lb, end_col-lb);
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
// }
// 
// 
// /** \relates Mat
// */
// template<class T,int s,class IO,class TF,class TV>
// Vec< typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T ,s >
// solve_using_factorization( const Mat<T,Sym<s,false>,Dense<Col>,IO> &m, const TF &mat, const TV &b ) {
//     typedef typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T TR;
//     unsigned nb_lines=mat.nb_rows();
//     
//     Vec<TR,s> vec;
//     vec.resize( nb_lines );
//     for(unsigned i=0;i<b.size();++i)
//         vec[i] = b[i];
//     //
//     for(unsigned line=0;line<mat.nb_rows();++line)
//         vec[line] = ( vec[line] - dot_aligned_with_offset(mat(line,range(line)),vec[range(line)]) ) / mat(line,line);
// 
//     //
//     Vec<TR,s> tmpvec = vec;
// 
//     TR tmp;
//     while (nb_lines--) {
//         T *ptr = &mat(nb_lines,0);
//         tmp = tmpvec[nb_lines] / ptr[nb_lines];
//         for(unsigned lb=0;lb<nb_lines;++lb)
//             tmpvec[lb] -= ptr[lb] * tmp;
//         vec[nb_lines] = tmp;
//     }
//     return vec;
// }
/// Cholesky
template<class T,int s,class TF,class IO>
bool get_factorization( const Mat<T,Herm<s,false>,Dense<Col>,IO> &m, TF &mat ) {
    // m -> mat
    mat.resize( m.nb_rows(), m.nb_cols() );
    for(unsigned line=0;line<mat.nb_rows();++line) {
        //
        for(unsigned col=0;col<line;++col) {
            T reg = m(line,col);
            for(unsigned i=0;i<col;++i)
                reg -= mat(line,i) * mat(col,i);
            mat(line,col) = reg / mat(col,col);
        }
        //
        T reg = m(line,line);
        for(unsigned i=0;i<line;++i)
            reg -= mat(line,i) * mat(line,i);
        mat(line,line) = sqrt( reg );
    }
    return true;
}


/**
    \relates Mat
*/
template<class T,int s,class IO,class TF,class TV>
Vec< typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T ,s >
solve_using_factorization( const Mat<T,Herm<s,false>,Dense<Col>,IO> &m, const TF &mat, const TV &b ) {
    typedef typename TypePromote< Multiplies, typename TF::T, typename TV::template SubType<0> ::T >::T TR;
    unsigned nb_lines=mat.nb_rows();
    
    Vec<TR,s> vec;
    vec.resize( nb_lines );
    for(unsigned i=0;i<b.size();++i)
        vec[i] = b[i];
    //
    for(unsigned line=0;line<mat.nb_rows();++line) {
        TR tmp = vec[line];
        for(unsigned col=0;col<line;++col)
            tmp -= mat(line,col) * vec[col];
        vec[line] = tmp / mat(line,line);
    }
    
    //
    Vec<TR,s> tmpvec = vec;

    while (nb_lines--) {
        TR tmp = tmpvec[nb_lines] / mat(nb_lines,nb_lines);
        for(unsigned lb=0;lb<nb_lines;++lb)
            tmpvec[lb] -= mat(nb_lines,lb) * tmp;
        vec[nb_lines] = tmp;
    }
    return vec;
}


};

#endif // LMT_matinvfull_HEADER
