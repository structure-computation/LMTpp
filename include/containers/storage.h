//
// C++ Interface: storage
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_storage_HEADER
#define LMT_storage_HEADER

namespace LMT {

/** used as parameter of storage styles (Dense, SkyLine, ...) */
struct Col {
    static const bool col_oriented = true;
    static const bool diag_oriented = false;
};
/** used as parameter of storage styles (Dense, SkyLine, ...) */
struct Row {
    static const bool col_oriented = false;
    static const bool diag_oriented = false;
};


/** type of storage. 
    \warning incompatible with Lapack in case of alignement != 0
*/
template<class Orientation = Col>
struct Dense {
    typedef Orientation TO;
    static const bool col_oriented = Orientation::col_oriented;
    static std::string name() { std::ostringstream os; os << "Dense col_oriented=" << col_oriented;  return os.str(); }
    static const bool dense = true;
    static const bool sparse = false;
    static const bool skyline = false;

    typedef Dense<
        typename AlternativeOnType<col_oriented,Col,Row>::T
    > Trans;
};

/** type of storage. 
*/
template<class Orientation = Col>
struct SparseLine {
    typedef Orientation TO;
    static const bool col_oriented = Orientation::col_oriented;
    static std::string name() { std::ostringstream os; os << "Sparse col_oriented=" << col_oriented;  return os.str(); }
    static const bool dense = false;
    static const bool sparse = true;
    static const bool skyline = false;

    typedef SparseLine<
        typename AlternativeOnType<col_oriented,Col,Row>::T
    > Trans;
};


/** type of storage. 
*/
template<class Orientation = Col>
struct SkyLine {
    typedef Orientation TO;
    static const bool col_oriented = Orientation::col_oriented;
    static std::string name() { std::ostringstream os; os << "Sky col_oriented=" << col_oriented;  return os.str(); }
    static const bool dense = false;
    static const bool sparse = false;
    static const bool skyline = true;

    typedef SkyLine<
        typename AlternativeOnType<col_oriented,Col,Row>::T
    > Trans;
};

/** type of storage. 
*/
struct SparseLU {
    typedef Col TO;
    static const bool col_oriented = true;
    static std::string name() { return "SparseLU"; }
    static const bool dense = false;
    static const bool sparse = true;
    static const bool skyline = false;

    typedef SparseLU Trans;
};


};

#endif // LMT_storage_HEADER
