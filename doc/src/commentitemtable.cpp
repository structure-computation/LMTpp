#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

#include "commentitemtable.h"
#include "token.h"

CommentItemTable :: CommentItemTable( string& header ) {

 titre = header ;
   //std::cout << "**toto**"<< std::endl;
}

    
void CommentItemTable :: addLine( string& s ) {

 //string token ;
 int p1 = 0,p2= 0,n=s.size() ;
 vector<string> ligne ;
 
 //cout << " |||" << s << "|" << endl ;
 
 while (p2 >= 0) {
    //cout << "p1= " << p1 << endl ;
    //cout << "p2= " << p2 << endl ;
    chercher_motif( s,"&",&p2,n,p1 ) ;
    //cout << "p2# " << p2 << endl ;
    if (p2 >= 0 ) { 
        //token = s.substr(p1,p2-p1) ;
        ligne.push_back( s.substr(p1,p2-p1) ) ;
        //cout << "---|" << token << "|---" << endl ;
        }
        else {
        //token = s.substr(p1,n-p1+1) ;
        ligne.push_back( s.substr(p1,n-p1+1) ) ;
        //cout << "___|" << token << "|___" << endl ;
    }
    p1 = p2 + 1 ;
 }
 
 tableau.push_back( ligne ) ;
}


void CommentItemTable :: display( std::ostream &os ) {

    int i,j ;

    os << "CommentItemTable : header =" << titre << endl ;
    for(i=0;i<tableau.size();i++) {
        os << endl ;
        for(j=0;j<tableau[i].size();j++) 
            if (tableau[i][j].size() > 0) 
                os  << tableau[i][j] << " " ; 
            else
                os << "VIDE " ;
    }
    os << endl << "fin CommentItemTable" << endl ;
}


