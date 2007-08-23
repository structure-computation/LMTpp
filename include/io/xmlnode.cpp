/* *
 *   Copyright (C) 2004 by Hugo LECLERC                                    *
 *   hugo_lec@club-internet.fr                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "xmlnode.h"
#include "units.h"
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

namespace LMT {

///
struct Xml_doc_with_counter {
    ///
    xmlDocPtr doc;
    ///
    unsigned count;
    ///
    Xml_doc_with_counter(xmlDocPtr leDoc=(xmlDocPtr)NULL):doc(leDoc),count(1) {}
    ~Xml_doc_with_counter() {
        if ( doc )
            xmlFreeDoc(doc);
    }
    unsigned operator++() {
        return ++count;
    }
    unsigned operator--() {
        if (--count)
            return count;
        delete this;
        return 0;
    }
};


XmlNode::XmlNode() {
    doc = new Xml_doc_with_counter;
    parse_text("<root></root>");
}
///
XmlNode::XmlNode(const XmlNode &XmlNode):doc(XmlNode.doc) {
    ++(*doc);
    this->node = XmlNode.node;
}

XmlNode &XmlNode::operator=(const XmlNode &XmlNode) {
    if ( doc != XmlNode.doc ) {
        --(*doc);
        this->doc = XmlNode.doc;
        this->node = XmlNode.node;
        ++(*doc);
    }
    return *this;
}

///
void XmlNode::parse_file(const char *file) throw (IoException) {
    xmlDocPtr tmp_doc = xmlParseFile(file);
    if ( tmp_doc == NULL )
        throw( IoException( "error parsing XML file "+std::string(file)+"." ));
    node = xmlDocGetRootElement( tmp_doc );
    if ( node == NULL) {
        xmlFreeDoc( tmp_doc );
        throw( IoException( "XML file "+std::string(file)+" is empty." ));
    }

    --(*doc);
    doc = new Xml_doc_with_counter( tmp_doc );
}

///
void XmlNode::parse_text(const char *text) throw (IoException) {
    xmlDocPtr tmp_doc = xmlParseDoc((xmlChar *)text);
    if ( tmp_doc == NULL )
        throw( IoException( "error parsing XML text "+std::string((const char *)text)+"." ));
    node = xmlDocGetRootElement( tmp_doc );
    if ( node == NULL) {
        xmlFreeDoc( tmp_doc );
        throw( IoException( "XML text "+std::string((const char *)text)+" is empty." ));
    }

    --(*doc);
    doc = new Xml_doc_with_counter( tmp_doc );
}

/// number of sub elements
unsigned XmlNode::nb_elements() const {
    xmlNodePtr cur = node->xmlChildrenNode;
    unsigned res = 0;
    while (cur != NULL) {
        res += (cur->type==XML_ELEMENT_NODE);
        cur = cur->next;
    }
    return res;
}

///
unsigned XmlNode::nb_elements(const char *name_elem) const {
    xmlNodePtr cur = node->xmlChildrenNode;
    unsigned res = 0;
    while (cur != NULL) {
        res += ( xmlStrcmp(cur->name, (const xmlChar *)name_elem) == 0 );
        cur = cur->next;
    }
    return res;
}

///
XmlNode XmlNode::get_element(const char *name_elem,unsigned number) const throw (IoException) {
    xmlNodePtr cur = node->xmlChildrenNode;
    unsigned cpt = 0;
    while (cur != NULL) {
        cpt += ( xmlStrcmp(cur->name, (const xmlChar *)name_elem) == 0 );
        if ( cpt > number ) {
            XmlNode res(*this);
            res.node = cur;
            return res;
        }
        cur = cur->next;
    }
    throw( IoException( "Not enough elements of kind "+std::string(name_elem)+" in element "+get_name()+"." ));
}

///
XmlNode XmlNode::get_element_nb(unsigned number) const throw (IoException) {
    xmlNodePtr cur = node->xmlChildrenNode;
    unsigned cpt = 0;
    while (cur != NULL) {
        cpt += ( cur->type == XML_ELEMENT_NODE );
        if ( cpt > number ) {
            XmlNode res(*this);
            res.node = cur;
            return res;
        }
        cur = cur->next;
    }
    throw( IoException( std::string("Not enough elements in node ")+get_name()+" in element "+get_name()+"." ));
}

/// true if has attribute
bool XmlNode::has_attribute(const char *name_attr) const {
    return xmlHasProp(node, (const xmlChar *)name_attr);
}

///
std::string XmlNode::get_attribute(const char *name_attr) const throw (IoException) {
    xmlChar *uri = xmlGetProp(node, (const xmlChar *)name_attr);
    if ( uri == (xmlChar *)NULL )
        throw IoException( std::string("Element ")+get_name()+" has no attribute "+name_attr );
    std::string res( (const char *)uri );
    xmlFree( uri );
    return res;
}

/// name of pointed element
const char *XmlNode::get_name() const {
    return (const char *)node->name;
}

///
double XmlNode::getUnitCoeff(const char *coeff) throw(IoException) {
    double res = units.getCoeff(coeff);
    if ( res < 0.0 )
        throw IoException( std::string("Unit <b>")+coeff+"</b> is not known." );
    return res;
}

///
XmlNode &XmlNode::set_attribute(const char *name,const char *val) {
    xmlNewProp(node, (const xmlChar *)name, (const xmlChar *)val);
    return *this;
}

///
XmlNode XmlNode::add_element(const char *name) {
    XmlNode res(*this);
    res.node = xmlNewTextChild(node, NULL, (const xmlChar *)name, NULL);
    return res;
}

///
void XmlNode::throwIoException(const std::string &msg) const throw(IoException) {
    throw IoException(msg);
}

///
std::ostream &operator<<(std::ostream &os,const XmlNode &node) {
    xmlChar *mem;
    int size;
    // xmlIndentTreeOutput = 1;
    xmlDocDumpFormatMemory( node.doc->doc, &mem, &size, 1);
    mem[size] = 0;
    os << (const char *)mem;
    return os;
}


};
