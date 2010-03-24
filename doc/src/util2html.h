#ifndef UTIL2HTML_H
#define UTIL2HTML_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

//#include "target.h"
struct Target ;
struct ListTarget ;

using namespace std ;

void generate_header( Target* src, string& path_root, ofstream& of,string& titre) ;

// cette fonction convertit un nom en un identifiant web
string french2webID( const string& s) ;
// cette fonction convertit un nom en un chaine HTML
string french2HTML( const string& s) ;

// cette fonction produit un lien du chemin href_src vers href_target avec l'affichage name.
string linkHTML( const string& href_src, const string& href_target , const string& name ) ;

string linkImage( const string& href_src, const string& href_target , const string& texte ) ;

// cette fonction produit un lien vers une ancre.
string link_fragmentHTML( const string& s ) ;

// cette fonction produit une ancre HTML.
string ancreHTML( const string& s,bool display = false ) ;

// cette fonction renvoie vrai le texte compris entre start et end est un lien wb de la forme http.*, https.*, www.*, ftp.*. 
bool isURL(string& res, string& s,int end,int start=0) ;

// cette fonction convertit une chaine texte en un texte à la syntaxe HTML et avec la conversion de \a et \anchor en équivalent HTML et en faisant les liens HTML entre les noms répertoriés dans ptr_lt la page courante ptr_parent.
string text2HTML(string& s, Target* ptr_parent, ListTarget* ptr_lt ) ;

void feetPage(ofstream& pageWeb, bool withDate = true );

//unsigned hash_p ( const string& s ) ;
//unsigned hash_p ( const string& s,int end, int start ) ;
//string hash2string( unsigned h) ;
#endif

