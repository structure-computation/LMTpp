#include <iostream>
#include <string>
#include <vector>


using namespace std ;
#include "token.h"
#include "names.h"
#include "listparameter.h"
#include "parameter.h"
#include "listtarget.h"
#include "util2html.h"

ListParameter :: ~ListParameter() {

//     int i,n ;
// 
//     n = list.size();
//     for(i=0;i<n;i++)
//         delete list[i] ;
}

/*
void ListTarget :: push_back( Parameter* pp) {

}
*/

void ListParameter :: clear() {

//     int i,n ;
// 
//     n = list.size();
//     for(i=0;i<n;i++)
//         delete list[i] ;
    list.clear() ;
}

void ListParameter :: display_parameter_to_HTML(ofstream* f, ListTarget* ptr_list_target, Target* pt) {

    string stmp,stmp2 ;
    Target* ptr_t ;
    int j,m ;

    m = list.size() ;
    for(j=0;j<m;j++) {
        stmp = list[j].type.name ;
        if ((ptr_t = ptr_list_target->isName( stmp )) != 0 )
            stmp2 = linkHTML( pt->reference(), ptr_t->reference(),stmp ) ;
        else
            stmp2 = french2HTML( stmp ) ;
        *f << " <strong> " <<  list[j].listAttribut << " " << stmp2 << " </strong> " ;
        *f << list[j].nameVariable ;
        stmp = list[j].defaultType ;
        if (stmp.size() > 0 ) {
            *f << " = " << french2HTML( stmp ) << " " ;
        }
        if (j != m-1)
            *f << ", " ;
    }

}


/*inline*/ std::ostream &operator<<( std::ostream &os, ListParameter& t ) { 

    int i,n ;

    n = t.list.size() ;
    for(i=0;i<n;i++) {
        os << "vvvvvvvvvvvvvvvvvv PARAMETRE vvvvvvvvvvvvvvvvvv" << endl ;
        os << t.list[i];
    }
    return os ;
} ;










