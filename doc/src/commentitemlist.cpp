#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

#include "commentitemlist.h"


CommentItemList :: CommentItemList( ) {
   //std::cout << "**toto**"<< std::endl;
}

    
void CommentItemList :: addCaracteristic( string& s,int nb_space,char c )  {
 txt.push_back( s );
 nb_espace.push_back( nb_space );
 type_list +=  c;
}


void CommentItemList :: display( std::ostream &os ) {

 int i;
 os << "CommentItemList : txt =" << endl;
 for(i=0;i<txt.size();i++)  os  << "(" << nb_espace[i] << ") "<< type_list[i] << " " << txt[i] << endl;
 os << "fin CommentItemList" << endl;
}


