//
// C++ Interface: factory
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMTFACTORY_H
#define LMTFACTORY_H

#include "ioexception.h"
#include "../containers/vec.h"
#include "../containers/arglist.h"

namespace LMT {

/**
Generic factory able to instantiate a class using a name

@author Hugo LECLERC
*/
class Factory {
public:
    /// Ancestor of registered elements
    class AncestorElementFactory {
    public:
        template<class AL> bool operator==(const AL &al) const {
            if ( ancestors.size() && al.a1.size() )
                return ( type==al.a0 && find( ancestors, Equal(), al.a1 ) );
            return ( type==al.a0 );
        }
        virtual void *create( const void *parameter ) const throw(IoException) = 0;
        virtual ~AncestorElementFactory() {}
        std::string type;
        Vec<std::string> ancestors;
    };
    /// A registered element
    template<class T,class Op,class TPar>
    class ElementFactory : public AncestorElementFactory {
    public:
        ElementFactory(const std::string &t,const std::string &a) { type = t; ancestors = tokenize(a,':'); }
        virtual ~ElementFactory() {}
        virtual void *create( const void *parameter ) const throw(IoException) {
            T *n = new T;
            //op( *n, reinterpret_cast<const TPar *>(parameter) );
            return reinterpret_cast<void *>(n);
        }
        Op op;
    };
    ~Factory() { for(unsigned i=0;i<lst.size();++i) delete lst[i]; }
    
    /// ancestors must be specified as ancestor1:ancestor2:ancestor3...
    template<class T,class Op,class TPararameter>
    void reg(const std::string &type,const std::string &ancestors="") {
        lst.push_back( new ElementFactory<T,Op,TPararameter>(type,ancestors) );
    }

    ///
    void *create(const std::string &type,const std::string &ancestor="",void *parameter = NULL) throw(IoException) {
        //const AncestorElementFactory * const *a = find_elem( lst, *_1 == arglist(type,ancestor) ); <- intel compiler does not like
        const AncestorElementFactory * const *a = NULL;
        for(unsigned i=0;i<lst.size();++i)
            if ( *lst[i] == arglist(type,ancestor) )
                a = &lst[i];
        if ( a )
            return (*a)->create( parameter );
        throw IoException( std::string("Object <b>")+type+"</b> has not been registered in Factory." );
    }
    ///
    bool has_obj_of_type(const std::string &type) const {
        for(unsigned i=0;i<lst.size();++i)
            if ( lst[i]->type==type )
                return true;
        return false;
    }

    Vec<AncestorElementFactory *> lst;
};

extern Factory factory;

};

#endif
