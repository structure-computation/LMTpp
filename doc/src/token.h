#ifndef TOKEN_H
#define TOKEN_H

/// la définition de LINE_VACUUM est aussi dans le fichier token.cpp alors attention si on change la valeur 
#define LINE_VACUUM -1

#include<deque>
using namespace std ;

typedef struct { 
    string titre ;
    string nomHtml ;
} referenceWeb ;

string enleve_suffix(string& s) ;
string suffix(string& s) ;
string directory(string& s) ;

void tolower(string& s);

int string2chaine(char* res, int res_t, string& s ) ;
// fonction qui renvoie vrai si elle trouve le motif motif avec la position en pos dans la chaine s sinon
// elle renvoie faux avec la valeur -1 dans pos.

bool chercher_delimitateur( const string& s, const char* liste_delimitateur,int* pos,int end, int start=0 ) ;
bool r_chercher_delimitateur( const string& s, const char* liste_delimitateur,int* pos,int end, int start=0 ) ;

bool chercher_motif(const char* s, const char* motif,int* pos,int start=0 ) ;
bool chercher_motif( const string& s, const char* motif,int* pos,int end, int start=0 ) ;
// cette fonction recherche un token à partir de la position start. Elle retourne le token ou éventuellment une chaine vide et pos contient la position du premier charactère après le token. Les délimitateurs acceptés sont : espace, tabulation, [, ], {, }, <, >, &, *, /, ',', ';', (, )
string extraire_token(int* pos, string& s,int start=0 ) ;
// cette fonction renvoie soit un pointeur sur le début du premier token soit NULL. Les délimitateurs acceptés sont : espace, tabulation, [, ], {, }, <, >, &, *, /, ,. Si elle a trouvé un token alors delimiteur contient soit '\0' pour une fin de ligne soit le délimitateur et *suite contient soit un pointeur sur la fin de ligne soit un pointeur sur le prochain cractère.
char* extraire_token(char** suite,char* delimiteurTrouve,char* source) ;
// cette fonction recherche un token dans le string source à partir de l'indice start et jusqu'à end. Elle renvoie soit un index sur le début du premier token soit -1. Les délimitateurs acceptés sont : espace, tabulation, [, ], {, }, <, >, &, *, /, ,., = Si elle a trouvé un token alors delimiteur contient soit '\0' pour une 'fin de ligne' soit le délimitateur et *suite contient soit  size ou soit la position du prochain cractère.
int extraire_token(int* suite,char* delimiteurTrouve, const char* list_delimitateur, string& source,int end, int start=0) ;
int r_extraire_token(int* suite,char* delimiteurTrouve, const char* list_delimitateur, string& source,int end, int start=0) ;
int extraire_token_delimateur_blanc(int* suite,string& source,int end, int start=0) ;
// tableau à 2k valeurs 2j est l'index de début du lexem j et 2j+1 l'index du caractère qui le suit 
void extract_list_lexem( int* suivant, deque<int>& listeIndex,char* delim,const char* ldelim_terminal, const char* ldelim_lexem, string& t ,int end, int start ) ;

void get_block(int* suivant,const char* delim, string& t ,int end, int start ) ;

void cut_space( string& s) ;

// retourne le nombre de caractères c consécutifs à partir de la position start et retourne dans pos la position du premier caractère différent de c.
int compter_caractere_consecutif(int* pos,string& s, char c,int start=0 ) ;
// retourne le nombre de caractères c à partir de la position start 
int compter_caractere( const string& s, char c,int start=0 ) ;
// cette fonction sert à compter les blancs d'indentation. Dans le cas d'une ligne vide, la fonction renvoie la valeur LINE_VACUUM.
int indentation(int* pos,string& s,int start=0 ) ;
bool chercher_section( int* nb, string& s, int end,int start ) ;
bool chercher_liste( int* nb, char* type, string& s, int end,int start ) ;

bool equal( const string& s, const string& t,int end,int start ) ;

string extract_last_name_of_path( const string& s) ;
string replace_delimitateur( const string& s, const char old_delim, const char new_delim ) ;
string extract_path( const string& s) ;
string inter( const string& s, const string& s2 ) ;
void extract_list_lexem_of_path( int* suivant, deque<int>& listeIndex, string& t ,int end, int start ) ;
bool extract_name_of_path( string& name, const string& s, int level) ;

string somme(string& src); // fait un cheksum simple (somme modulo 2**32) puis renvoie le résultat dans la base 72 0--9A-Za-z

#endif


