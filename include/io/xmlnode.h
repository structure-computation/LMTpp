#ifndef DOUCXMLNODE_H
#define DOUCXMLNODE_H

#ifdef METIL_COMP_DIRECTIVE
#pragma lib_name xml2
#pragma cpp_path /usr/include/libxml2
#endif

#ifdef DONT_WANT_XML
// WITHOUT XML

class XmlNode {
public:
    bool has_attribute( const char *t ) const { return false; }
    template<class T> void get_attribute( const char *t, T &val ) const;
};

#else
// WITH XML



#include <sstream>
#include <libxml/tree.h>
#include "factory.h"
#include "lineoutput.h"

namespace LMT {

/**
helper class to extract data from a dom node

@author Hugo LECLERC
*/
class XmlNode {
public:
    struct ParseText { };
    struct ParseFile { };
    ///
    XmlNode();
    ///
    XmlNode(const char *file) { doc = NULL; parse_file(file); }
    ///
    XmlNode(const char *file,ParseFile) { doc = NULL; parse_file(file); }
    ///
    XmlNode(const char *text,ParseText) { doc = NULL; parse_text(text); }
    ///
    XmlNode(const XmlNode &XmlNode);
    ///
    ~XmlNode();
    ///
    XmlNode &operator=(const XmlNode &XmlNode);
    ///
    void parse_file(const char *file) throw (IoException);
    ///
    void parse_text(const char *text) throw (IoException);
    /// name of pointed element
    const char *get_name() const;
    /// number of sub elements
    unsigned nb_elements() const;
    /// number of sub elements named name_elem
    unsigned nb_elements(const char *nameElem) const;
    ///
    XmlNode get_element(const char *nameElem,unsigned number=0) const throw (IoException);
    ///
    XmlNode get_element_nb(unsigned number=0) const throw (IoException);
    /// true if has attribute
    bool has_attribute(const char *nameAttr) const;
    ///
    std::string get_attribute(const char *name_attr) const throw (IoException);
    ///
    template<class T>
    const XmlNode &get_attribute(const char *name,T &res) const throw (IoException) {
        std::string att( get_attribute(name) );
        std::istringstream is( att );
        line_input(is, res);
        if ( !is ) { throw IoException( "Error while reading attribute " + std::string( name ) + " value=" + att ); }
        return *this;
    }
    ///
    template<class T,class T2>
    const XmlNode &get_attribute(const char *name,T &res,T2 default_value) const throw (IoException) {
        if ( has_attribute(name) ) {
            std::string att( get_attribute(name) );
            std::istringstream is( att );
            line_input(is, res);
            if ( !is ) { throw IoException( "Error while reading attribute " + std::string( name ) + " value=" + att ); }
        }
        else
            res = default_value;
        return *this;
    }    ///
    std::string get_content() const throw (IoException);
    ///
    template<class T>
    const XmlNode &get_content(T &res) const throw (IoException) {
        std::string att( get_content() );
        std::istringstream is( att );
        line_input(is, res);
        if ( !is ) { throw IoException( "Error while reading content : " + att ); }
        return *this;
    }
    /// with unit
    template<class T>
    const XmlNode &get_attribute_with_unit(const char *name,const char *final_unit,T &res) const throw (IoException) {
        std::string att( get_attribute(name) ), unit;
        std::istringstream is( att );
        line_input(is, res);
        if ( !is ) { throw IoException( "Error while reading attribute " + std::string( name ) + " value=" + att ); }
        is >> unit;
        if ( is )
            res *= getUnitCoeff(unit.c_str()) / getUnitCoeff(final_unit);
        else
            is.clear();
        return *this;
    }
    /// with unit
    template<class T,class T2>
    const XmlNode &get_attribute_with_unit(const char *name,const char *final_unit,T &res,T2 default_value) const throw (IoException) {
        if ( this->has_attribute(name) ) {
            std::string att( get_attribute(name) ), unit;
            std::istringstream is( att );
            line_input(is, res);
            if ( !is ) { throw IoException( "Error while reading attribute " + std::string( name ) + " value=" + att ); }
            is >> unit;
            if ( is )
                res *= getUnitCoeff(unit.c_str()) / getUnitCoeff(final_unit);
            else
                is.clear();
        }
        else
            res = default_value;
        return *this;
    }

    ///
    template<class T>
    const XmlNode &get_object(T &res,const char *ancestor="") const throw (IoException) {
        res = reinterpret_cast<T>( factory.create(get_name(),ancestor) );
        res->read_xml_data(*this);
        return *this;
    }
    ///
    template<class T,class TPar>
    const XmlNode &get_object_with_parameter(T &res,TPar *par,const char *ancestor="") const throw (IoException) {
        res = reinterpret_cast<T>( factory.create(get_name(),ancestor) ); // ,reinterpret_cast<void *>(par)
        res->read_xml_data(*this,par);
        return *this;
    }


    // --------------------------- write ---------------------------
    ///
    XmlNode &set_attribute(const char *name,const char *val);
    ///
    template<class T>
    XmlNode &set_attribute(const char *name,const T &val) {
        std::ostringstream os;
        line_output( os, val );
        set_attribute( name, os.str().c_str() );
        return *this;
    }
    ///
    template<class T>
    XmlNode &set_attribute_with_unit(const char *name,const char *unit,const T &val) {
        std::ostringstream os;
        line_output( os, val );
        os << ' ' << unit;
        set_attribute( name, os.str().c_str() );
        return *this;
    }
    ///
    XmlNode add_element(const char *name);

    /// helper function
    static double getUnitCoeff(const char *coeff) throw(IoException);

    /// throw exception with a valid IoException
    void throwIoException(const std::string &msg) const throw(IoException);
private:
    ///
    mutable class Xml_doc_with_counter *doc;
    ///
    xmlNodePtr node;

    ///
    friend std::ostream &operator<<(std::ostream &os,const XmlNode &node);
};

std::ostream &operator<<(std::ostream &os,const XmlNode &node);

};

#endif // WITHOUT_XML

#endif

