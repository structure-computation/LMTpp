//
// C++ Interface: structure
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_structure_HEADER
#define LMT_structure_HEADER

namespace LMT {

/*! Type of matrix structure. Generic square matrix
 */
template<int s_rows=-1,int s_cols=s_rows>
struct Gen {
    static const int static_nb_rows = s_rows;
    static const int static_nb_cols = s_cols;
    static const bool fixed_size = ( s_rows>=0 && s_cols>=0 ); 
    static std::string name() { return "Gen"; /*std::ostringstream os; os << "Gen " << s_rows << "x" << s_cols;  return os.str();*/ }
    
    static const bool need_diag = true;
    static const bool need_upper = true;
    static const bool need_lower = true;
    
    template<class V> inline typename V::T get_strutured(const V &t,unsigned line,unsigned column) const { return t(line,column); }
    template<class V,class T> inline void set_strutured(V &t,unsigned line,unsigned column,const T &val) const { t(line,column) = val; }
    
    template<class Op,class T0,class T1>
    static void apply( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r )
            for( unsigned c = 0; c < src.nb_cols(); ++c )
                op( r, c, res, src( r, c) );
    }
    
    template<class Op,class T0,class T1>
    static void apply_sparse_line( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r )
            for( unsigned i = 0; i < src.data[ r ].indices.size(); ++i )
                op( r, src.data[ r ].indices[ i ], res, src.data[ r ].data[ i ] );
    }
    
    static bool valid_position( unsigned r, unsigned c ) { return true; }
};

/*! Type of matrix structure. Symmetric matrix
*/
template<int size=-1,bool stored_in_upper_part_=false>
struct Sym {
    static const int static_nb_rows = size;
    static const int static_nb_cols = size;
    static const bool fixed_size = ( size>=0 );
    static const bool stored_in_upper_part = stored_in_upper_part_;
    static std::string name() { return "Sym"; /*std::ostringstream os; os << "Sym " << size << " upper part : " << stored_in_upper_part;  return os.str();*/ }

    static const bool need_diag = true;
    static const bool need_upper = stored_in_upper_part_;
    static const bool need_lower = not stored_in_upper_part_;
    
    template<class Op,class T0,class T1>
    static void apply( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r )
            for( unsigned c = 0; c <= r; ++c )
                op( r, c, res, src( r, c ) );
    }
    
    template<class Op,class T0,class T1>
    static void apply_sparse_line( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r ) {
            for( unsigned i = 0; i < src.data[ r ].indices.size(); ++i ) {
                unsigned c = src.data[ r ].indices[ i ];
                op( r, c, res, src.data[ r ].data[ i ] );
                if ( r != c )
                    op( c, r, res, src.data[ r ].data[ i ] );
            }
        }
    }
    
    static bool valid_position( unsigned r, unsigned c ) {
        return stored_in_upper_part_ ? r <= c : c <= r;
    }
};

/*! Type of matrix structure. Symmetric matrix
*/
template<int size=-1,bool stored_in_upper_part_=false>
struct Herm {
    static const int static_nb_rows = size;
    static const int static_nb_cols = size;
    static const bool fixed_size = ( size>=0 );
    static const bool stored_in_upper_part = stored_in_upper_part_;
    static std::string name() { return "Herm"; /*std::ostringstream os; os << "Herm " << size << " upper part : " << stored_in_upper_part;  return os.str();*/ }

    static const bool need_diag = true;
    static const bool need_upper = stored_in_upper_part_;
    static const bool need_lower = !stored_in_upper_part_;
    
    template<class Op,class T0,class T1>
    static void apply( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r )
            for( unsigned c = 0; c <= r; ++c )
                op( r, c, res, src( r, c) );
    }
    
    template<class Op,class T0,class T1>
    static void apply_sparse_line( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r ) {
            for( unsigned i = 0; i < src.data[ r ].indices.size(); ++i ) {
                unsigned c = src.data[ r ].indices[ i ];
                op( r, c, res, src.data[ r ].data[ i ] );
                if ( r != c )
                    op( c, r, res, conj( src.data[ r ].data[ i ] ) );
            }
        }
    }
    
    static bool valid_position( unsigned r, unsigned c ) {
        return stored_in_upper_part_ ? r <= c : c <= r;
    }
};


/*! Type of matrix structure. Antisymmetric matrix
*/
template<int size=-1,bool stored_in_upper_part_=false>
struct AntiSym {
    static const int static_nb_rows = size;
    static const int static_nb_cols = size;
    static const bool fixed_size = ( size>=0 );
    static const bool stored_in_upper_part = stored_in_upper_part_;
    static std::string name() { return "AntiSym"; /*std::ostringstream os; os << "AntiSym " << size << " upper part : " << stored_in_upper_part;  return os.str();*/ }

    static const bool need_diag = false;
    static const bool need_upper = stored_in_upper_part_;
    static const bool need_lower = !stored_in_upper_part_;
    
    template<class Op,class T0,class T1>
    static void apply( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r )
            for( unsigned c = 0; c <= r; ++c )
                op( r, c, res, src( r, c) );
    }
    
    template<class Op,class T0,class T1>
    static void apply_sparse_line( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r ) {
            for( unsigned i = 0; i < src.data[ r ].indices.size(); ++i ) {
                unsigned c = src.data[ r ].indices[ i ];
                op( r, c, res, src.data[ r ].data[ i ] );
                if ( r != c )
                    op( c, r, res, - src.data[ r ].data[ i ] );
            }
        }
    }
    
    static bool valid_position( unsigned r, unsigned c ) {
        return stored_in_upper_part_ ? r <= c : c <= r;
    }
};


/*! Type of matrix structure. Antisymmetric matrix
*/
template<int s_rows=-1,int s_cols=s_rows>
struct Diag {
    static const int static_nb_rows = s_rows;
    static const int static_nb_cols = s_cols;
    static const bool fixed_size = ( s_rows>=0 && s_cols>=0 ); 
    static std::string name() { return "Diag"; /*std::ostringstream os; os << "Diag " << s_rows << "x" << s_cols;  return os.str();*/ }

    static const bool need_diag = true;
    static const bool need_upper = false;
    static const bool need_lower = false;
    
    template<class Op,class T0,class T1>
    static void apply( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r )
            op( r, r, res, src( r, r ) );
    }
    
    template<class Op,class T0,class T1>
    static void apply_sparse_line( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r )
            op( r, r, res, src( r, r ) );
    }
    
    static bool valid_position( unsigned r, unsigned c ) {
        return r == c;
    }
};


/*! Type of matrix structure.
*/
template<int s_rows=-1,int s_cols=s_rows>
struct TriUpper {
    static const int static_nb_rows = s_rows;
    static const int static_nb_cols = s_cols;
    static const bool fixed_size = ( s_rows>=0 && s_cols>=0 ); 
    static std::string name() { return "TriUpper"; /*std::ostringstream os; os << "TriLower " << s_rows << "x" << s_cols;  return os.str();*/ }

    static const bool need_diag = true;
    static const bool need_upper = true;
    static const bool need_lower = false;
    
    template<class Op,class T0,class T1>
    static void apply( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r )
            for( unsigned c = r; c < src.nb_cols(); ++c )
                op( r, c, res, src );
    }
    
    static bool valid_position( unsigned r, unsigned c ) {
        return r <= c;
    }
};

/*! Type of matrix structure.
*/
template<int s_rows=-1,int s_cols=s_rows>
struct TriLower {
    static const int static_nb_rows = s_rows;
    static const int static_nb_cols = s_cols;
    static const bool fixed_size = ( s_rows>=0 && s_cols>=0 ); 
    static std::string name() { return "TriLower"; /*std::ostringstream os; os << "TriLower " << s_rows << "x" << s_cols;  return os.str();*/ }

    static const bool need_diag = true;
    static const bool need_upper = false;
    static const bool need_lower = true;
    
    template<class Op,class T0,class T1>
    static void apply( const Op &op, T0 &res, T1 &src ) {
        for( unsigned r = 0; r < src.nb_rows(); ++r )
            for( unsigned c = 0; c <= r; ++c )
                op( r, c, res, src );
    }
    
    static bool valid_position( unsigned r, unsigned c ) {
        return c <= r;
    }
};

/*!
    typedef ... T where ... is the transposed structure
*/
template<class STR> struct StructureTrans {};

template<int s1,int s2> struct StructureTrans<Gen<s1,s2> > { typedef Gen<s2,s1> T; };
template<int s,bool l> struct StructureTrans<Sym<s,l> > { typedef Sym<s,l> T; };
template<int s,bool l> struct StructureTrans<Herm<s,l> > { typedef Herm<s,l> T; };
template<int s,bool l> struct StructureTrans<AntiSym<s,l> > { typedef AntiSym<s,l> T; };
template<int s> struct StructureTrans<Diag<s> > { typedef Diag<s> T; };
template<int r,int c> struct StructureTrans<TriUpper<r,c> > { typedef TriLower<c,r> T; };
template<int r,int c> struct StructureTrans<TriLower<r,c> > { typedef TriUpper<c,r> T; };


};

#endif // LMT_structure_HEADER
