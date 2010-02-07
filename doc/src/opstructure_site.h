#ifndef OP_STRUCTURE_SITE_H
#define OP_STRUCTURE_SITE_H

#include <map>
#include <string>

//#include "pagecomment.h"
#include "op.h"

struct PageComment ;
struct VisitorBloc_NameBaseClass ;
struct ListTarget ;



struct OpStructure_site : Op {
    OpStructure_site(map<string,string>* pt ) { ptr_tree = pt ; }
    virtual ~OpStructure_site() {}
    void initialize() ;
    virtual void operator()( PageComment* page ) ;
    //void setRepertory( const char* n) ;
    //void setRepertory( string& n) ;

    map<string,string>* ptr_tree ;
};

#endif

