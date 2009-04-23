#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <deque>
#include <string.h>
using namespace std ;

//#include "token.h"
// la définition de LINE_VACUUM est en fait dans le fichier token.h alors attention si on change la valeur 
#define LINE_VACUUM -1

string enleve_suffix(const string& s) {
    string::size_type i = s.rfind('.') ;

    if (i == string::npos ) return s ; else return s.substr(0,i) ;
}

string suffix(const string& s) {

    string::size_type i = s.rfind('.') ;

    if (i != string::npos )
        return s.substr(i+1,s.length()-i) ;
    else
        return "" ;
}

string directory(const string& s) {

    string::size_type i = s.rfind('/') ;

    if (i == string::npos ) return s ; else return s.substr(0,i) ;
}

void tolower(string& s) {

    for(unsigned int i=0 ; i<s.size();i++) {
        s[i] = (char) tolower(s[i]);
    }
}

// fonction qui convertit un string en char*.
// renvoie 1 s'il y a dépassement et 0 sinon.
int string2chaine(char* res, int res_t, string& s )
{
 int ret = 0,i ;
 int l = s.length() ;
 if ( l > res_t-1) {
	l = res_t - 1 ;
	ret = 1 ;
	}
 for(i=0 ; i< l ; i++ ) res[i] = s[i] ;
 res[l] = '\0' ;

 return ret ;
}

// fonction qui renvoie vrai si elle trouve le motif motif avec la position en pos sinon
// elle renvoie faux avec la valeur -1 dans pos.
bool chercher_motif(const char* s, const char* motif,int* pos,int start=0  )
{
 int l,i=start,j ;
 int p=-1 ;

 *pos = -1 ;
 if (!strlen(motif)) return false ;
 if (start<0) start=0 ;

 while (s[i] != '\0') {
	if (motif[0] == s[i]) {
		p = i ;
		j = 1 ;
		while (motif[j] != '\0') {
			if ((s[p+j] == '\0') || (motif[j] != s[p+j])) break ;
			j++ ;
			}
		if (motif[j] == '\0') { *pos = p ; return true ; }
		}
	i++ ;
	}

 //cout << " (interne) p = " << p << endl ;
 //cout << " (interne) i = " << i << endl ;
 *pos = -1 ;
 return false ;
}

bool chercher_motif( const string& s, const char* motif, int* pos, int end, int start=0 )
{
    int l,i,j ;
    int p=-1 ;

    *pos = -1 ;
    if (!strlen(motif)) return false ;
    if (start<0) start=0 ;
    if (end > s.size()) end = s.size() ;

    for(i=start;i<end;i++) {
        if (motif[0] == s[i]) {
                p = i ;
                j = 1 ;
                while (motif[j] != '\0') {
                        if ((p+j == end) || (motif[j] != s[p+j])) break ;
                        j++ ;
                        }
                if (motif[j] == '\0') { *pos = p ; return true ; }
                }
    }

 //cout << " (interne) p = " << p << endl ;
 //cout << " (interne) i = " << i << endl ;
 *pos = -1 ;
 return false ;
/*
 int i ;
 i = s.find( motif,start ) ;
 *pos = i ;index_begin_signature
 if ((i<0) || (i>=end)) return false ;
	else return true ;
*/
}

bool chercher_delimitateur( const string& s, const char* liste_delimitateur,int* pos,int end, int start=0 ) {

   int i,j,l ;
   int p=-1 ;
   char c ;

    *pos = -1 ;
    l = strlen(liste_delimitateur) ;
    if (!l) return false ;
    if (start<0) start=0 ;
    if (end > s.size()) end = s.size() ;

    for(i=start;i<end;i++) {
        c = s[i] ;
        for(j=0;j<l;j++)
            if (c == liste_delimitateur[j]) {
                *pos = i ;
                return true ;
            }
    }

    //cout << " (interne) p = " << p << endl ;
    //cout << " (interne) i = " << i << endl ;
    return false ;
}

bool r_chercher_delimitateur( const string& s, const char* liste_delimitateur,int* pos,int end, int start=0 ) {

   int i,j,l ;
   int p=-1 ;
   char c ;

    *pos = -1 ;
    l = strlen(liste_delimitateur) ;
    if (!l) return false ;
    if (start<0) start=0 ;
    if (end > s.size()) end = s.size() ;

    for(i=end-1;i>=start;i--) {
        c = s[i] ;
        for(j=0;j<l;j++)
            if (c == liste_delimitateur[j]) {
                *pos = i ;
                return true ;
            }
    }

    //cout << " (interne) p = " << p << endl ;
    //cout << " (interne) i = " << i << endl ;
    return false ;
}

string extraire_token(int* pos, string& s,int start=0 ) {
    int p,l,i ;
    char c ;

    l = s.size() ;
    // on saute les espaces ou les tabulations
    for( p = start ; p<l;p++) {
        c = s[p] ;
        if ((c != ' ') && (c != '\t'))
            break ;
    }
                                                // VERSION PLUS A JOUR
    for( i=p; i<l;i++) {
        c = s[i] ;
        if ((c == ' ') || (c == '\t') || (c == '[') || (c== ']') || (c== '{') || (c== '}') || (c== '<') || (c== '>') || (c== '&') || (c== '*') || (c== ','))
            break ;
    }
    *pos = i ;
    return s.substr(p,i-p) ;
}

// cette fonction extrait le premier token à partir du pointeur source et renvoie soit un pointeur sur le début du token soit NULL. Si elle a trouvé un token alors delimiteur contient soit '\0' pour une fin de ligne soit le délimitateur et *suite contient soit un pointeur sur la fin de ligne soit un pointeur sur le prochain cractère. 
char* extraire_token(char** suite,char* delimiteurTrouve,char* source) {

    char* retour ;
    int i ;
    char c,del ;

                                                // VERSION PLUS A JOUR
    i = 0 ;
    del = 0 ;
    retour = NULL ;
    while (c=source[i]) {
        // on saute les espaces ou les tabulations
        if ((c != ' ') && (c != '\t')) 
            break ;
        i++ ;
    }
    if (c == '\0') {
        *suite = source + i ;
        return NULL ; // aucun token trouvé
    }
    retour = source + i ;
    while (c=source[i]) { 
        if ((c == '\t') ||  (c == ' ') || (c == '[') || (c== ']') || (c== '{') || (c== '}') || (c== '<') || (c== '>') || (c== '&') || (c== '*') || (c== '/') || (c== ',')) {
            del = c ;
            break ;
        }
        i++ ;
    }
    if (del > 0) 
        *suite = source + i + 1 ; // ce n'est pas la fin de la ligne
        else
        *suite = source + i ; // et là, c'est la fin...
    return retour ;
}

/*
int extraire_token(int* suite,char* delimiteurTrouve,string& source,int end,int start ) {

    int retour ;
    int i ;
    char c,del,delParticulier ;

    del = 0 ;
    retour = -1 ;
    for(i=start;i<end;i++) {
        // on saute les espaces ou les tabulations ou les saut de ligne
        c=source[i] ;
        if ((c != ' ') && (c != '\t') && (c != '\n') && (c != 13))  // ces délimitateurs sont particuliers
            break ;
    }
    if (i == end) {
        *suite =  end ;
        return retour ; // aucun token trouvé
    }
    retour = i ;
    for(;i<end;i++) { 
        c=source[i] ;
        if ((c == '\t') ||  (c == ' ') || (c== '\n')) {
            del = c ;
            break ;
        }
        if ((c == '[') || (c== ']') || (c== '{') || (c== '}') || (c== '<') || (c== '>') || (c== '&') || (c== '*') || (c== '/') || (c== ',') || (c== '\n') || (c== ':') || (c== ';') || (c== '(') || (c== ')') || (c== '=') ) {
            //if ( (( c=='<') && (source[i+1] == '<')) || (( c=='>') && (source[i+1] == '>'))) continue ; // problème pour << ou >>
            delParticulier = c ;
            break ;
        }
    }

    if (i<end) {
        if (del == 0) { 
            if (retour == i) *suite = i+1 ; else *suite = i ;
            *delimiteurTrouve = delParticulier ;
        } else {
            *suite = i ; // et là, c'est la fin...
            *delimiteurTrouve = del ;
        }
    } else {
        *suite = i ;
        *delimiteurTrouve = 0 ;
    }
    return retour ;
}
*/
// liste ancienne  == "[]{}<>&*/:;()=\n"
int extraire_token(int* suite,char* delimiteurTrouve, const char* list_delimitateur, string& source,int end,int start ) {

    int retour ;
    int i,j,n ;
    char c,del,delParticulier ;

    del = 0 ;
    n = strlen(list_delimitateur) ;
    retour = -1 ;
    
/*
    if (start<end)
        cout << "~~~~~~~~~~~(" << source.substr(start,end-start) << ")" << endl ;
    else
        cout << "~~~~~~~~~~~()" << endl ;
    */
    for(i=start;i<end;i++) {
        // on saute les espaces ou les tabulations ou les saut de ligne
        c=source[i] ;
        if ((c != ' ') && (c != '\t') && (c != '\n') && (c != 13))  // ces délimitateurs sont particuliers
            break ;
    }
    if (i >= end) {
        *suite =  end ;
        return retour ; // aucun token trouvé
    }
    retour = i ;
    for(;i<end;i++) { 
        c=source[i] ;
        ///if ((c == '\t') ||  (c == ' ') || (c== '\n')) {
        ///    del = c ;
        ///    break ;
        ///}
        //cout << "~~~~~~~~~~~|" << c << "|  num = " << (int) c <<endl ;
        for(j=0;j<n;j++) {
            if (c==list_delimitateur[j]) {
                delParticulier = c ;
                break ;
            }
        }
        if (j<n)
            break ;
    }

    if (i<end) {
        if (del == 0) { 
            if (retour == i) *suite = i+1 ; else *suite = i ;
            *delimiteurTrouve = delParticulier ;
        } else {
            *suite = i ; // et là, c'est la fin...
            *delimiteurTrouve = del ;
        }
    } else {
        *suite = i ;
        *delimiteurTrouve = '\n' ;
    }
    return retour ;
}

/*
int r_extraire_token(int* suite,char* delimiteurTrouve, const char* list_delimitateur, string& source,int end,int start ) {

    int retour ;
    int i,j,n ;
    char c,del,delParticulier ;

    del = 0 ;
    retour = -1 ;
    n = strlen(list_delimitateur) ;
    for(i=end-1;i>=start;i--) {
        // on saute les espaces ou les tabulations ou les saut de ligne
        c=source[i] ;
        if ((c != ' ') && (c != '\t') && (c != '\n') )  // ces délimitateurs sont particuliers
            break ;
    }
    if (i == start) {
        *suite =  end ;
        return retour ; // aucun token trouvé
    }
    retour = i ;
    for(;i>=start;i--) { 
        c=source[i] ;
        if ((c == '\t') ||  (c == ' ') || (c== '\n')) {
            del = c ;
            break ;
        }
        if ((c == '[') || (c== ']') || (c== '{') || (c== '}') || (c== '<') || (c== '>') || (c== '&') || (c== '*') || (c== '/') || (c== ',') || (c== '\n') || (c== ':') || (c== ';') || (c== '(') || (c== ')') || (c== '=') ) {
            //if ( (( c=='<') && (source[i+1] == '<')) || (( c=='>') && (source[i+1] == '>'))) continue ; // problème pour << ou >>
            delParticulier = c ;
            break ;
        }
    }

    if (i>=start) {
        if (del == 0) { 
            if (retour == i) *suite = i+1 ; else *suite = i ;
            *delimiteurTrouve = delParticulier ;
        } else {
            *suite = i ; // et là, c'est la fin...
            *delimiteurTrouve = del ;
        }
    } else {
        *suite = i ;
        *delimiteurTrouve = 0 ;
    }
    return retour ;
}
*/
int r_extraire_token(int* suite,char* delimiteurTrouve, const char* list_delimitateur, string& source,int end,int start ) {

    int retour ;
    int i,j,n ;
    char c,del,delParticulier ;

    del = 0 ;
    retour = -1 ;
    n = strlen(list_delimitateur) ;
    for(i=end-1;i>=start;i--) {
        // on saute les espaces ou les tabulations ou les saut de ligne
        c=source[i] ;
        if ((c != ' ') && (c != '\t') && (c != '\n') )  // ces délimitateurs sont particuliers
            break ;
    }
    if (i == start) {
        *suite =  end ;
        return retour ; // aucun token trouvé
    }
    retour = i ;
    for(;i>=start;i--) { 
        c=source[i] ;
        if ((c == '\t') ||  (c == ' ') || (c== '\n')) {
            del = c ;
            break ;
        }
        for(j=0;j<n;j++) {
            if (c==list_delimitateur[j]) {
                delParticulier = c ;
                break ;
            }
        }
        if (j<n)
            break ;
    }

    if (i>=start) {
        if (del == 0) { 
            if (retour == i) *suite = i+1 ; else *suite = i ;
            *delimiteurTrouve = delParticulier ;
        } else {
            *suite = i ; // et là, c'est la fin...
            *delimiteurTrouve = del ;
        }
    } else {
        *suite = i ;
        *delimiteurTrouve = 0 ;
    }
    return retour ;
}


int extraire_token_delimateur_blanc(int* suite,string& source,int end, int start=0) {

    int retour ;
    int i ;
    char c,del,delParticulier ;

    del = 0 ;
    retour = -1 ;
    for(i=start;i<end;i++) {
        // on saute les espaces ou les tabulations ou les saut de ligne
        c=source[i] ;
        if ((c != ' ') && (c != '\t') && (c != '\n') )  // ces délimitateurs sont particuliers
            break ;
    }
    if (i == end) {
        *suite =  end ;
        return retour ; // aucun token trouvé
    }
    retour = i ;
    for(;i<end;i++) { 
        c=source[i] ;
        if ((c == '\t') ||  (c == ' ') || (c== '\n')) {
            del = c ;
            break ;
        }
    }

    if (i<end) {
        if (del == 0) { 
            if (retour == i) *suite = i+1 ; else *suite = i ;
        } else {
            *suite = i ; // et là, c'est la fin...
        }
    } else {
        *suite = i ;
    }
    return retour ;

}

bool equal( const string& s, const string& t,int end,int start ) {

    int i ;

    for(i=start;i<end;i++) {
        if (s[i] != t[i])
            return false ;
    }
    return true ;
}


// enlève les espaces avant et après
void cut_space( string& s) {

    int i,n,start,end ;

    n = s.size() ;
    for(i=0;i<n;i++)
        if (s[i] != ' ')
            break ;
    start = i ;
    for(i=n-1;i>=0;i--)
        if (s[i] != ' ')
            break ;
    end = i+1 ;
    if (start >= end)
        return ;
    s.resize(end) ; //s.erase(end,s.size()-end ) ;
    s.erase(0,start) ;
}

int compter_caractere_consecutif(int* pos,string& s, char c,int start=0  )
{
    int l,co,p ;

    l = s.size() ;
    co = 0 ;
    for( p = start ; p<l;p++)
        if (s[p] == c ) co++ ; else break ;
    *pos = p ;
    return co ;
}

int compter_caractere( const string& s, char c,int start=0 ) {

    int l,co,p ;

    l = s.size() ;
    co = 0 ;
    for( p = start ; p<l;p++)
        if (s[p] == c ) co++ ;
    return co ;
}

int indentation(int* pos,string& s,int start=0 ) {

    int l,co,p ;

    l = s.size() ;
    co = 0 ;
    for( p = start ; p<l;p++)
        if (s[p] == ' ') co++ ; else break ;
    *pos = p ;
    if (p ==l)
        return co ;
    if (s[p] == '\n')
        return LINE_VACUUM ;
    else 
        return co ;
}

// tableau à 2k valeurs. 2j est l'index de début du lexem j et 2j+1 l'index du caractère qui le suit 
void extract_list_lexem( int* suivant, deque<int>& listeIndex,char* delim,const char* ldelim_terminal,const char* ldelim_lexem, string& t ,int end, int start ) {

    string stmp ;
    int pos,next,i,j,n ;
    char local_delim ;
    //char* ldelim ;

    listeIndex.clear() ;
    n = strlen( ldelim_terminal ) ;
    //ldelim = (char*) malloc(n+strlen(ldelim_lexem)+1) ;
    //memcpy(ldelim,ldelim_lexem,strlen(ldelim_lexem));
    //strcpy(ldelim+strlen(ldelim_lexem),ldelim_terminal);
    local_delim = 0 ;
    next = end ;
    // "[]{}<>&*/:;()=\t \n"
    while (((pos = extraire_token(&next,&local_delim,ldelim_lexem,t,end,start )) >= 0 ) && (start<end)){
        for(j=0;j<n;j++) {
            if (t[pos] == ldelim_terminal[j]) {
                    *delim = t[pos];
                    *suivant = next ;
                    //free( delim) ;
                    return ;
            }
        }
        listeIndex.push_back(pos) ;
        listeIndex.push_back(next) ;
        start = next ;
    }
    
    *delim = local_delim ;
    *suivant = next ;
    //free( delim) ;
}

string extract_last_name_of_path( const string& s)  {

    int pos ;
    
    if (r_chercher_delimitateur(s,"/",&pos,s.size()))
        return s.substr(pos+1,s.size()-pos-1) ;
    else
        return s ;
}

string replace_delimitateur( const string& s, const char old_delim, const char new_delim ) {

    string tmp ;
    int end,pos,start ;
    char ld[2] ;

    end = s.size() ;
    ld[0] = old_delim ;
    ld[1] = '\0' ;
    start = 0 ;
    while(true) {
        if (chercher_delimitateur(s,ld,&pos,end,start)) {
            tmp += s.substr(start,pos-start);
            tmp += new_delim ;
            start = pos + 1 ;
        } else {
            tmp += s.substr(start,end-start) ;
            break ;
        }
    }
    return tmp ;
}

string extract_path( const string& s) {

    int end,pos,start,end_path ;

    end = s.size() ;
    start = 0 ;
    end_path = 0 ;
    while(true) {
        if (chercher_delimitateur(s,"/",&pos,end,start)) {
            start = pos + 1 ;
            end_path = pos ;
        } else {
            return s.substr(0,end_path) ;
        }
    }
}

string inter( const string& s, const string& s2 ) {

    int end = min(s.size(),s2.size()) ;
    int i ;

    for(i=0;i<end;i++)
        if (s[i] != s2[i])
            break ;
    return s.substr(0,i) ;
}

void extract_list_lexem_of_path( int* suivant, deque<int>& listeIndex, string& t ,int end, int start ) {

    int pos,next,i,j,n ;
    char local_delim ;

    listeIndex.clear() ;
    local_delim = 0 ;
    //next = end ;
    while (((pos = extraire_token(&next,&local_delim,"/\n",t,end,start )) >= 0 ) && (start<end)){
        listeIndex.push_back(pos) ;
        listeIndex.push_back(next) ;
        start = next + 1 ; // + 1 pour sauter le /
    }

    *suivant = next ;
}

/*
    cette fonction lit une chaine de la forme A/B/C/D/E.
    elle renvoie vrai si on demande le niveau 4 (i.e. E) dans cet exemple et faux sinon
    si on demande un niveau supérieur au dernier niveau, la fonction renvoie la chaine vide dans name sinon elle renvoie le nom au niveau l (i.e. si level == 1, elle renvoie B)

*/
bool extract_name_of_path( string& name, const string& s, int level) {

    int end,pos,start,l ;

    end = s.size() ;
    start = 0 ;
    for( l = 0; l<level;l++) {
        if (chercher_delimitateur(s,"/",&pos,end,start)) {
            start = pos + 1 ; // + 1 pour sauter le /
        } else {
            break ;
        }
    }
    if (l<level) {
        name = "" ;
        return false ;
    }
    if (chercher_delimitateur(s,"/",&pos,end,start)) {
        name = s.substr(start,pos-start) ;
        return false ;
    } else {
        name = s.substr(start,end-start) ;
        return true ;
    }
}

// on suppose que le premier delim[0] est déjà passé.
// Exemple :delim == "{}"
void get_block(int* suivant, const char* delim, string& t ,int end, int start ) {
    
    int pos,next,n,nbBraket ;
    char delimi,c ;
    
    //cout << "9999999999999" << endl ;
    // on suppose que le premier { est déjà passé.
    nbBraket = 1 ;
    while ((pos = extraire_token(&next,&delimi,"[]{}<>&*/:;()=\n \t",t,end,start )) >= 0 ) {
        c = t[pos] ;
        if (c == delim[0]) nbBraket++ ;
        if (c == delim[1]) nbBraket-- ;
        //cout << "********* |" << t.substr(pos,next-pos) << "|***" << endl ;
        if (nbBraket == 0) break ;
        start = next ;
    }
    *suivant = next ;
}

string somme(  string& src) {

    string stmp;
    unsigned int s,t ;
    int i,n;

    s = 0;
    n = src.size();
    for(i=0;i<n;i++) {
        s += src[i];
    }
    i = 0;
    //cerr << " s = " << s << endl;
    while(s>0) {
        t = s % 62;
        if (t<10)
            stmp.push_back('0'+t);
        else {
            if (t<36) {
                t -= 10;
                stmp.push_back('a' + t);
            } else {
                t -= 36 ; 
                stmp.push_back('A' + t);
            }
        }
        i++;
        s /= 72;
    }
    return stmp;
}





