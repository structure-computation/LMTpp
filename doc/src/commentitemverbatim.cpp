#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

#include "commentitemverbatim.h"

void CommentItemVerbatim :: addTabulation_String( int t,string& s ) {
 txt.push_back( s );
 tabulation.push_back( t );
}


void CommentItemVerbatim :: display( std::ostream &os ) {

 int i,j;

 os << "CommentItemVerbatim " << endl;
 for(i=0;i<txt.size();i++) {
    for(j=0;j<tabulation[i];j++) os << "    ";
    os  << txt[i] << endl;
 }
 os << "fin CommentItemVerbatim" << endl;
}


