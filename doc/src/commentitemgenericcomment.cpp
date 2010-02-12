#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

#include "commentitemgenericcomment.h"


CommentItemGenericComment :: CommentItemGenericComment( string& sref  ) {
   name.name = "generic_comment_" + sref ;
   name.principalName = sref ;
}

/*
void CommentItemGenericComment :: addTabulation_String( string& s ) {

    txt.push_back( s ) ;
}*/


void CommentItemGenericComment :: display( std::ostream &os ) {

    int i,n ;

    n = items.size() ;
    os << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl ;
    os << "!!!!!!!!!! CommentItemGenericComment : reference !" << name.name << " !!!!!!!!!!" << endl ;
    //os << "CommentItemGenericComment : language !" << name.name << endl ;
    //for(i=0;i<txt.size();i++)
    //    os  << txt[i] << endl ;
    os << " nombre d'items = " << n << endl ;
    for(i=0;i<n;i++) {
        os  << *items[i] << endl ;
    }
    os << "fin CommentItemGenericComment" << endl ;
}


