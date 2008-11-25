#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

#include "commentitemcode.h"


CommentItemCode :: CommentItemCode( string& langue  ) {
   language = langue ;
}

    
void CommentItemCode :: addTabulation_String( int t,string& s ) {
 txt.push_back( s ) ;
 tabulation.push_back( t ) ;
}


void CommentItemCode :: display( std::ostream &os ) {

 int i,j ;

 os << "CommentItemCode : language =" << language << endl ;
 for(i=0;i<txt.size();i++) {
    for(j=0;j<tabulation[i];j++) os << "    " ;
    os  << txt[i] << endl ;
 }
 os << "fin CommentItemCode" << endl ;
}


