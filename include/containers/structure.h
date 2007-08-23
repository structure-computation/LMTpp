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

/** Type of matrix structure. Generic square matrix
 */
template<int s_rows=-1,int s_cols=s_rows>
struct Gen {
    static const int static_nb_rows = s_rows;
    static const int static_nb_cols = s_cols;
    static const bool fixed_size = ( s_rows>=0 && s_cols>=0 ); 
    static std::string name() { std::ostringstream os; os << "Gen " << s_rows << "x" << s_cols;  return os.str(); }
    
    static const bool need_diag = true;
    static const bool need_upper = true;
    static const bool need_lower = true;
    
    template<class V> inline typename V::T get_strutured(const V &t,unsigned line,unsigned column) const { return t(line,column); }
    template<class V,class T> inline void set_strutured(V &t,unsigned line,unsigned column,const T &val) const { t(line,column) = val; }
};

/** Type of matrix structure. Symmetric matrix
*/
template<int size=-1,bool stored_in_upper_part_=false>
struct Sym {
    static const int static_nb_rows = size;
    static const int static_nb_cols = size;
    static const bool fixed_size = ( size>=0 );
    static const bool stored_in_upper_part = stored_in_upper_part_;
    static std::string name() { std::ostringstream os; os << "Sym " << size << " upper part : " << stored_in_upper_part;  return os.str(); }

    static const bool need_diag = true;
    static const bool need_upper = stored_in_upper_part_;
    static const bool need_lower = !stored_in_upper_part_;
};

/** Type of matrix structure. Symmetric matrix
*/
template<int size=-1,bool stored_in_upper_part_=false>
struct Herm {
    static const int static_nb_rows = size;
    static const int static_nb_cols = size;
    static const bool fixed_size = ( size>=0 );
    static const bool stored_in_upper_part = stored_in_upper_part_;
    static std::string name() { std::ostringstream os; os << "Herm " << size << " upper part : " << stored_in_upper_part;  return os.str(); }

    static const bool need_diag = true;
    static const bool need_upper = stored_in_upper_part_;
    static const bool need_lower = !stored_in_upper_part_;
};


/** Type of matrix structure. Antisymmetric matrix
*/
template<int size=-1,bool stored_in_upper_part_=false>
struct AntiSym {
    static const int static_nb_rows = size;
    static const int static_nb_cols = size;
    static const bool fixed_size = ( size>=0 );
    static const bool stored_in_upper_part = stored_in_upper_part_;
    static std::string name() { std::ostringstream os; os << "AntiSym " << size << " upper part : " << stored_in_upper_part;  return os.str(); }

    static const bool need_diag = false;
    static const bool need_upper = stored_in_upper_part_;
    static const bool need_lower = !stored_in_upper_part_;
};


/** Type of matrix structure. Antisymmetric matrix
*/
template<int s_rows=-1,int s_cols=s_rows>
struct Diag {
    static const int static_nb_rows = s_rows;
    static const int static_nb_cols = s_cols;
    static const bool fixed_size = ( s_rows>=0 && s_cols>=0 ); 
    static std::string name() { std::ostringstream os; os << "Diag " << s_rows << "x" << s_cols;  return os.str(); }

    static const bool need_diag = true;
    static const bool need_upper = false;
    static const bool need_lower = false;
};


/** Type of matrix structure.
*/
template<int s_rows=-1,int s_cols=s_rows>
struct TriUpper {
    static const int static_nb_rows = s_rows;
    static const int static_nb_cols = s_cols;
    static const bool fixed_size = ( s_rows>=0 && s_cols>=0 ); 
    static std::string name() { std::ostringstream os; os << "TriUpper " << s_rows << "x" << s_cols;  return os.str(); }

    static const bool need_diag = true;
    static const bool need_upper = true;
    static const bool need_lower = false;
};

/** Type of matrix structure.
*/
template<int s_rows=-1,int s_cols=s_rows>
struct TriLower {
    static const int static_nb_rows = s_rows;
    static const int static_nb_cols = s_cols;
    static const bool fixed_size = ( s_rows>=0 && s_cols>=0 ); 
    static std::string name() { std::ostringstream os; os << "TriLower " << s_rows << "x" << s_cols;  return os.str(); }

    static const bool need_diag = true;
    static const bool need_upper = false;
    static const bool need_lower = true;
};

/**
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
