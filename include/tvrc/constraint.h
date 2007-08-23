//
// C++ Interface: constraint
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_constraint_HEADER
#define LMT_constraint_HEADER

namespace LMT {

/** Rq : this constraint only apply to \e points

    if \f$ \mathbf{d} \f$ is the result of get_dir and \f$ C \f$ is val, the goal is to obtain
    \f$ < \mathbf{d}, \sum_i \mathbf{M_i} > = C \f$ on each points of supporting element.
*/
template<unsigned dim,class T>
class Constraint_uniform {
public:
    typedef Vec<T,dim> Pvec;
    typedef Vec<T,dim-(dim==2)> Rvec;
    typedef std::complex<T> TC;
    
    void read_xml_data(const XmlNode &sn) throw(IoException) {
        sn.get_attribute_with_unit( "dir", "", dir );
        sn.get_attribute_with_unit( "val", "m", val );
    }
    /// used to read xml files
    static std::string name() { return "constraint_uniform"; }
    /// used only for numerical integration
    template<class TN> MaterialPoint<TC,dim> get_value(const TN &node) const { return MaterialPoint<TC,dim>( val * dir.dep, val * dir.rot ); }
    /// used only for numerical integration
    template<class TN> const MaterialPoint<TC,dim> &get_dir(const TN &node) const { return dir; }
    
    MaterialPoint<TC,dim> dir;
    TC val;
};

template<class T>
class Constraint_uniform_acoustic {
public:
    typedef std::complex<T> TC;
    
    void read_xml_data(const XmlNode &sn) throw(IoException) {
        sn.get_attribute_with_unit( "dir", "", dir );
        sn.get_attribute_with_unit( "val", "m", val );
    }
    /// used to read xml files
    static std::string name() { return "constraint_uniform_acoustic"; }
    /// used only for numerical integration
    template<class TN> Vec<TC,2> get_value(const TN &node) const { return val * dir; }
    /// used only for numerical integration
    template<class TN> const Vec<TC,2> &get_dir(const TN &node) const { return dir; }
    
    Vec<TC,2> dir;
    TC val;
};

};

#endif // LMT_constraint_HEADER
