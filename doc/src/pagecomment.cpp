#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <string.h>

using namespace std;

#include "token.h"
#include "bloc.h"
#include "templateparameter.h"
#include "parameter.h"
#include "pagecomment.h"
#include "typedef.h"
#include "classe.h"
#include "classemetil.h"
#include "functionmetil.h"
#include "struct.h"
#include "util2html.h"
#include "visitorbloc_getproperty.h"
                 
/// structures pour l'analyse de code Metil
#include "lexer.h"
#include "errorlist.h"

struct Classe;
//#define LENGTH_NAME_FILE 128

#define SIZE_TABLE_PREFIX_TAG 3

const char* PageComment::prefixTag[SIZE_TABLE_PREFIX_TAG] = {
    "%%%",  // pour commentaire précédent le morceau de code à commenter
    "%%@",  // pour commentaire suivant le morceau de code à commenter
    "%@@"   // pour commentaire example ou tutorial
};



PageComment::PageComment( const char* file) {
 nameFile = file;
 nameWithoutSuffix = enleve_suffix( nameFile ); 
}

PageComment::~PageComment( ) {

    int i;

    for(i=0;i<listComment.size();i++) 
        delete listComment[i];
}

string PageComment::getName()
{
 return nameWithoutSuffix;
}

string PageComment::getNameFile()
{
 return nameFile;
}

int PageComment::state( string& t,int end, int start ) {

    int pos,i;
    bool tag;
    
    if ( start >= end) return NOT_STATE_ID;
    if (chercher_motif( t,"namespace",&pos,end,start ))  return NAMESPACE_STATE_ID; 
    if (chercher_motif( t,"extern",&pos,end,start ))  return EXTERN_STATE_ID; 
    if (chercher_motif( t,"#",&pos,end,start ))  return PREPROCESSOR_STATE_ID; 
    if (chercher_motif( t,"template",&pos,end,start ))  return TEMPLATE_STATE_ID; 
    if (chercher_motif( t,"typedef",&pos,end,start ))  return TYPEDEF_STATE_ID; 
    if (chercher_motif( t,"struct",&pos,end,start ))  return STRUCT_STATE_ID; 
    if (chercher_motif( t,"class",&pos,end,start ))  return CLASS_STATE_ID; 
    tag = false;
    for(i=0;i<SIZE_TABLE_PREFIX_TAG;i++)
        tag |= chercher_motif( t,prefixTag[i],&pos,end,start );
    if (tag) return TAG_STATE_ID;

    if ((chercher_motif( t,"public",&pos,end,start )) || (chercher_motif( t,"protected",&pos,end,start )) || (chercher_motif( t,"private",&pos,end,start )))
        return PORTED_STATE_ID;
    if (chercher_motif( t,"(",&pos,end,start ))  return FUNCTION_STATE_ID; 
    return OPEN_STATE_ID; 
}

string PageComment::state_namespace( int* suivant, string& t ,int end, int start ) {

    string retour;
    int position[2];
    int pos,next,compteur;
    char delim;

    retour = "";
    compteur = 0;
    position[0] = -1;
    position[1] = -1;
    while ((pos = extraire_token(&next,&delim,"[]{}<>&*/:;()=\n \t",t,end,start )) >= 0 ) {
        if (t[pos] == ';') {
            *suivant = next;
            return ""; // probablement la std : on s'en moque
        }
    
        if (t[pos] == '{') {
            if (position[0] == -1) { 
                *suivant = next;
                return "";
            } else {
                *suivant = next;
                //cout << " eeeeeeeeeeeeeee = " << t.substr(position[0],position[1]-position[0] ) << endl;
                //cout << " pos = " << pos << endl;
                //cout << " next = " << next << endl;
                return t.substr(position[0],position[1]-position[0] );
            }
        }
        position[0] = pos;
        position[1] = next;
        start = next;
    }
    *suivant = start;
    return "";
}

// renvoie vrai si c'est un extern "C"
bool PageComment::state_extern( int* suivant, string& t ,int end, int start ) {

    int pos,next;
    char delim;

    if ((pos = extraire_token(&next,&delim,"[]{}<>&*/:;()=\n \t",t,end,start )) >= 0 ) {
        if (t.substr(pos,next-pos) == "\"C\"") {
            // on parse le bloc extern
            if (chercher_delimitateur(t,"{;",&pos,end,next)) {
                if (t[pos] == ';') {
                    *suivant = pos+1;
                    return true;
                } else {
                    get_block(suivant,"{}",t,end,pos+1);
                    return true;
                }
            }
        } else {
            *suivant = next;
            return false;
        }
    }
    else {
        *suivant = -1;
        return false;
    }

}

// Important : on suppose que start est l'indice du #
void PageComment::state_preprocessor( int* suivant, string& t ,int end, int start ) {

    int pos;

    while(true) {
        if (chercher_motif( t,"\n",&pos,end,start+1 )) {
            start = pos + 1;
            if (t[pos-1] != '\\')
                    break;
        } else { // c'est la fin du texte.
            start = end;
            break;
        }
    }
    *suivant = start;

}

/*
// tableau à 2k valeurs 2j est l'index de début du lexem j et 2j+1 l'index du caractère qui le suit 
void PageComment::extract_list_lexem( int* suivant, deque<int>& listeIndex,char* delim,const char* ldelim, string& t ,int end, int start ) {

    int pos,next,i,j,n;
    char local_delim;

    listeIndex.clear();
    n = strlen( ldelim );
    local_delim = 0;
    next = end;
    while (((pos = extraire_token(&next,&local_delim,t,end,start )) >= 0 ) && (start<end)){
        for(j=0;j<n;j++) {
            if (t[pos] == ldelim[j]) {
                    *delim = t[pos];
                    *suivant = next;
                    return;
            }
        }
        listeIndex.push_back(pos);
        listeIndex.push_back(next);
        start = next;
    }
    
    *delim = local_delim;
    *suivant = next;
}*/

void PageComment::state_typedef( int* suivant, Names& type, string& synonyme, string& t ,int end, int start ) {

    deque<int> localListIndex;
    string localtype;
    int next,i,n;
    char delim;


    extract_list_lexem( &next,localListIndex,&delim,";","[]{}<>&*/:;()=\t \n",t,end,start );

    for(i=0;i<localListIndex.size()-2;i += 2) {
        if (i<localListIndex.size()-4)
            localtype += t.substr(localListIndex[i],localListIndex[i+1]-localListIndex[i]) + ' ';
        else
            localtype += t.substr(localListIndex[i],localListIndex[i+1]-localListIndex[i]);
    }
    //if (localtype.size()>0)  localtype.erase(localtype.size()-1); // dommage que localtype.pop_back() ne marche pas!
    //cout << "LOCALTYPE == " << localtype << endl;
    //if (localList.size() > 0) cout << "SYNONYME == " << localList[localList.size()-1] << endl;
    type.name = localtype;
    type.principalName = principal_type_of( localtype );
    n = localListIndex.size() - 2;
    synonyme = t.substr(localListIndex[n],localListIndex[n+1]-localListIndex[n]);
    //cout << " type = " << localtype << endl;
    //cout << " synonyme = " << synonyme << endl;
    
    *suivant = next;
}

void PageComment::extract_ported( int* suivant, string& name, string& t ,int end, int start ) {

    string locals;
    int pos,next;
    char delim,c;

    pos = extraire_token(&next,&delim,"[]{}<>&*/:;()=\n \t",t,end,start );// l'obejectif de cet appel est de récupérer la portee
    name = t.substr( pos,next-pos );
    //cout << " portee = " << t.substr( pos,next-pos ) << endl;
    extraire_token(suivant,&delim,"[]{}<>&*/:;()=\n \t",t,end,next );// l'obejectif de cet appel est d'enlever le signe : attendu.

}

int PageComment::index_begin_signature( string& t ,int end, int start ) {

    int c_parenthese_fermante,i,pos;

        for(i=end-1;i>=start;i--)
            if (t[i] == ')') {
                c_parenthese_fermante = 1;
                break;
            }
        i--; // on saute le )
        for(;i>=start;i--) {
            if (t[i] == ')') c_parenthese_fermante++;
            if (t[i] == '(') c_parenthese_fermante--;
            if (c_parenthese_fermante == 0) {
                return i;
            }
        }
    return end;
}

void PageComment::extract_returnType_name( int* suivant ,const string& name_structure, Names& returnType, Names& name, string& t ,int end, int start ) {

    deque<int> localListIndex;
    string stmp;
    string localtype;
    string localname;
    int n,next,i,pos,ioperator,isignature;
    char delim,c,cnext;


    extract_list_lexem( &next,localListIndex,&delim,"","[]{}<>&*/:;()=\t \n",t,end,start ); // la chaîne vide signifie qu'on s'arrêtera à end.
    n = localListIndex.size();
    if (n==0)
         return;
    //cout << "liste des lexems" << endl;
    //for(i=0;i<n;i+=2)
    //    cout << "|||" << t.substr( localListIndex[i], localListIndex[i+1] - localListIndex[i] )  << "|||" << endl;

    // on commence par voir si c'est un constructeur puis si il a le symbole : qui pose problème
    if (name_structure.size() >0) {
        for(i=0;i<n;i+=2)
            if (t.substr( localListIndex[i], localListIndex[i+1] - localListIndex[i] ) == name_structure)
                break;
        if (i<n) {
            // on a trouvé un constructeur!
            ///cout << "on a trouvé un constructeur!" << endl;
            // on recherche s'il y a un symbole : tout seul à la fin
            for(i=n-2;i>=0;i-=2)
                if (t[localListIndex[i]] == ':') {
                    if (i>1) {
                        if (t[localListIndex[i-2]] != ':')
                            break;
                    }
                }
            if (i>=0) {
                end = localListIndex[i]; // on parsera le nom et le type jusqu'à ce symbole :
                n = i;
            }
        }

    }

    // on regarde si on a le mot clé throw ou __attribute__
    for(i=n-2;i>=0;i-=2) {
        stmp = t.substr( localListIndex[i], localListIndex[i+1] - localListIndex[i] );
        if ((stmp == "throw") || (stmp == "__attribute__")) {
            n = i;
            end = localListIndex[i];
            break;
        }
    }

    pos = index_begin_signature(t,end,start );
    //cout << " ****plouf =" << t.substr(start,pos-start ) << endl;
    //cout << " t[pos] = " << t[pos] << endl;
    *suivant = pos;
    for(i=n-2;i>=0;i-=2)
        if (localListIndex[i+1] <= pos)
            break;
    isignature = i + 2;
    //cout << " ****plouf ====|" << t.substr(localListIndex[0],localListIndex[isignature+1]-localListIndex[0] ) << "|===== " << endl;
    for(i=0;i< isignature;i+=2) {
        stmp = t.substr( localListIndex[i], localListIndex[i+1] - localListIndex[i] );
        if ((chercher_motif(stmp,"operator",&pos,localListIndex[i+1] - localListIndex[i] )) && (pos == 0)) // on a trouvé operator au début du lexem.
            break;
    }
    ioperator = i;

    if (ioperator < isignature ) {
        // c'est un opérateur
            for(i=ioperator;i<isignature;i+=2)
                localname += t.substr( localListIndex[i], localListIndex[i+1] - localListIndex[i] );
            cut_space( localname );
            name.name = localname;
            name.principalName = localname;
            for(i=0;i<ioperator;i+=2)
                localtype += t.substr( localListIndex[i], localListIndex[i+1] - localListIndex[i] ) + ' ';
            cut_space( localtype );
            returnType.name = localtype;
            returnType.principalName = principal_type_of( localtype );

    }
    else {
        // c'est un nom de fonction normale.
        if (isignature>=3) {
            localtype = t.substr( localListIndex[0], localListIndex[isignature-3] - localListIndex[0] );
            cut_space( localtype );
            returnType.name = localtype;
            returnType.principalName = principal_type_of( localtype );
        } else {
            returnType.name = "";
            returnType.principalName = "";
        }
            localname = t.substr( localListIndex[isignature-2], localListIndex[isignature-1] - localListIndex[isignature-2] );
            cut_space( localname );
            name.name = localname;
            name.principalName = principal_type_of( localname );
    }
}

// on suppose que le ( des paramètres a été passé
void PageComment::extract_parametersFunction( int* suivant, ListParameter& listeParam, string& t ,int end, int start ) {

    deque<int> localListIndex;
    string localtype;
    int n,next,i,j,nbBraket;
    Parameter p;
    char delim,c;

    
    extract_list_lexem( &next,localListIndex,&delim,");",";()[]<>&*/:=\t \n,",t,end,start );  // REMARQUE : j'ai ajouté  la virgule
    // normalement delim == )
    // normalemnet le ( du départ est déjà passé.
    listeParam.clear();
    if ( localListIndex.size() == 0 ) {
        *suivant = next;
        return;
    }
    //for(i=0;i<localListIndex.size(); i += 2 ) {
    //    cout << "tETEK ##|" << t.substr( localListIndex[i], localListIndex[i+1]-localListIndex[i] )  << "|##" << endl;
    //}

    while ( localListIndex.size() > 0 ){
        n = localListIndex.size();
        nbBraket = 0;
        //cout << " n = " << n << endl;
        c = 0;
        for(i=0;i<n; i += 2 ) {
            c = t[localListIndex[i]];
            if (c == '<') nbBraket++;
            if (c == '>') nbBraket--;
            if ((nbBraket == 0) && ((c == ',') || ((c == '=')) )) break;
        }
        p.clear();//ptr_p = new Parameter();
        if (c == 0) {
            // c'était la fin sans signe égal
            localtype = "";
            for(j=0;j<n-2; j += 2) {
                if (j < n-4)
                    localtype += t.substr( localListIndex[j], localListIndex[j+1]-localListIndex[j] ) + ' ';
                else 
                    localtype += t.substr( localListIndex[j], localListIndex[j+1]-localListIndex[j] );
            }
            //cout << " - 1 - localtype = " << localtype << endl; 
            p.type.name = localtype;
            p.type.principalName = principal_type_of( localtype );
            p.nameVariable = t.substr( localListIndex[n-2], localListIndex[n-1]-localListIndex[n-1] );
            //cout << " - 1 - nameVariable = " << t.substr( localListIndex[n-2], localListIndex[n-1]-localListIndex[n-1] ) << endl;
            listeParam.push_back( p );
            *suivant = next;
            return;
        } 
        else {
            localtype = "";
            for(j=0;j<i-2; j += 2) {
                if (j<i-4)
                    localtype += t.substr( localListIndex[j], localListIndex[j+1]-localListIndex[j] ) + ' ';
                else
                    localtype += t.substr( localListIndex[j], localListIndex[j+1]-localListIndex[j] );
            }
            //if (localtype.size() > 0) localtype.erase( localtype.size()-1 );
            p.type.name = localtype;
            p.type.principalName = principal_type_of( localtype );
            //cout << " - 2 - localtype = " << localtype << endl; 
            p.nameVariable = t.substr( localListIndex[i-2], localListIndex[i-1]-localListIndex[i-2] );
            //cout << " - 2 - nameVariable = " << t.substr( localListIndex[i-2], localListIndex[i-1]-localListIndex[i-2] ) << endl;
            if (c == '=') {
                i += 2;
                p.defaultType = t.substr( localListIndex[i], localListIndex[i+1]-localListIndex[i] );
                //cout << " - 1 - defaultType = " << t.substr( localListIndex[i], localListIndex[i+1]-localListIndex[i] ) << endl;
                i += 2;
            }
        }
        listeParam.push_back( p );
        if (i+1 <n) {
            for(j=0;j<=i+1;j++)
            localListIndex.pop_front();
        } else {
            for(j=0;j<=i-1;j++)
            localListIndex.pop_front();
        }
    }

    *suivant = next;
}


// on supposera que le ) est passé
void PageComment::extract_FinalAttributFunction( int* suivant, string& attrib, char* delimitateur, string& t ,int end, int start ) {

    deque<int> localListIndex;
    string localattr;
    int n,next,i,j;
    char delim,c;

    extract_list_lexem( &next,localListIndex,&delim,"{;","{;/\t \n",t,end,start );

        ///for(i=0;i<localListIndex.size(); i += 2 )
            ///cerr <<  "|" << t.substr(localListIndex[i], localListIndex[i+1]-localListIndex[i]) << "| ";
        ///cerr << endl;

    for(i=0;i<localListIndex.size(); i += 2 ) {
        if (i<localListIndex.size()-2)
            localattr += t.substr( localListIndex[i], localListIndex[i+1]-localListIndex[i] ) + ' ';
        else 
            localattr += t.substr( localListIndex[i], localListIndex[i+1]-localListIndex[i] );
    }
    //cout << " +-+-+-+- DELIM = " << delim << endl;
    //cout << " +-+-+-+- attr = " << localattr << endl;
    attrib = localattr;
    *delimitateur = delim;
    *suivant = next;
}

void PageComment::extract_name_heritedClass( int* suivant, Names& name, ListParameter& lp , char* delimitateur, string& t ,int end, int start ) {

    deque<int> localListIndex;
    string localattr;
    string stmp;
    int n,next,i,j,nbBraket,k,i_inherited;
    Parameter p;
    char delim,c;

    extract_list_lexem( &next,localListIndex,&delim,"{;","{};[]<>&*/:()=\t \n",t,end,start );
    n = localListIndex.size();
    i_inherited = n;
    for(i=0;i<n; i += 2) {
        //cout << " <<< t[localListIndex[i]] = " << t[localListIndex[i]] << endl;
        //if (i+2<localListIndex.size()) 
            //cout << " <<< t[localListIndex[i+2]] = " << t[localListIndex[i+2]] << endl;
        if (t[localListIndex[i]] == ':')
            if ((i+2<n) && (t[localListIndex[i+2]] != ':')) {
                i_inherited = i;
                break;
            } else
                i += 2; // on saute le ::
    }

    //cout << " ___ i_inherited " << i_inherited << endl;
    //cout << " ___ localListIndex.size() " << localListIndex.size() << endl;
    //for(i=0;i<localListIndex.size(); i += 2 )
    //    cout << "___" << t.substr(localListIndex[i],localListIndex[i+1]-localListIndex[i]) << "|____"<< endl;

    // remarque :
    // si i_inherited = localListIndex.size()  alors il n' y a pas d'héritage
    // sinon on a détecté une liste d'héritage


    for(i=0;i< i_inherited; i += 2)
        localattr += t.substr( localListIndex[i], localListIndex[i+1]-localListIndex[i] );
        ///+       localattr += t.substr( localListIndex[i], localListIndex[i+1]-localListIndex[i] ) + ' ';

    //cut_space( localattr );
    name.name = localattr;
    name.principalName = principal_type_of( localattr );

    //for(i=0;i<lp.size();i++)
    //    delete lp[i];
    //lp.clear();
    j = i_inherited+2;
    nbBraket = 0;
    for(i= i_inherited+2;i<n; i += 2) {
        c = t[localListIndex[i]];
        if (c == '<') nbBraket++;
        if (c == '>') nbBraket--;
        if (((c == ',') || (i == n-2) ) && (nbBraket == 0)) {
            p.clear();//ptr_p = new Parameter();
            stmp = t.substr(localListIndex[j],localListIndex[j+1]-localListIndex[j]);
            if (stmp == "public") {
                p.listAttribut = "public";
                j += 2;
            }
            if (stmp == "protected") {
                p.listAttribut = "protected";
                j += 2;
            }
            if (stmp == "private") {
                p.listAttribut = "private";
                j += 2;
            }
            localattr.erase();
            if (c == ',') {
                for(k=j;k<i; k+= 2 ) {
                    localattr += t.substr(localListIndex[k],localListIndex[k+1]-localListIndex[k]);
                    /*+
                    if (k<i-2)
                        localattr += t.substr(localListIndex[k],localListIndex[k+1]-localListIndex[k]) + ' ';
                    else
                        localattr += t.substr(localListIndex[k],localListIndex[k+1]-localListIndex[k]);
                    */
                }
            }
            else {
                for(k=j;k<=i; k+= 2 ) {
                    localattr += t.substr(localListIndex[k],localListIndex[k+1]-localListIndex[k]);
                    /*+
                    if (k<i)
                        localattr += t.substr(localListIndex[k],localListIndex[k+1]-localListIndex[k]) + ' ';
                    else
                        localattr += t.substr(localListIndex[k],localListIndex[k+1]-localListIndex[k]);
                    */
                }
            }
            p.type.name = localattr;
            p.type.principalName = principal_type_of( localattr );
            lp.push_back( p );
            j = i+2;
            //continue;
        }
    }

    *delimitateur = delim;
    *suivant = next;
}


void PageComment::get_declaration( Parameter& p,string& t,int end, int start ) {

    deque<int> li;
    string localtype;
    int i,n,pos,iEgal,iOpenedBraket,next;
    char delim;
    bool newBraket; // pour tenir compte qu'une déclaration peut avoir plusieurs dimensions

    extract_list_lexem( &next,li,&delim,";","[]{}<>&*/:;()=\t \n",t,end,start );  /// ";" est modifié le 19/09/2008

    if (li.size() == 0) {
        p.type.name = "";
        p.type.principalName = "";
        p.nameVariable = "";
        p.defaultType = "";
        return;
    }
    
    iEgal = -1;
    iOpenedBraket = -1;
    newBraket = true;
    for(i=0;i<li.size(); i += 2) {
        //cout << "LL >>|" << t.substr( li[i],li[i+1]-li[i] ) << "|<<" << endl;
        if (t[li[i]] == '=') iEgal = i;
        if ((t[li[i]] == '[') && (newBraket)) {
            iOpenedBraket = i;
            newBraket = false;
        }
    }
    
    //cout << " iEgal         = " << iEgal << endl;
    //cout << " iOpenedBraket = " << iOpenedBraket << endl;
    
    if (iEgal >= 0) {
        // il y a un égal
        localtype = "";
        for(i=iEgal+2;i<li.size(); i += 2 ) {
            if (i<li.size()-2)
                localtype += t.substr( li[i],li[i+1]-li[i] ) + ' ';
            else
                localtype += t.substr( li[i],li[i+1]-li[i] );
        }
        //if (localtype.size() > 0) localtype.erase(localtype.size()-1);
        p.defaultType = localtype;
        if (iOpenedBraket >= 0) {
            // il y a au moins un crochet
            localtype = "";
            for(i=iOpenedBraket-2;i<iEgal; i +=2 ) {
                if (i<iEgal-2)
                    localtype += t.substr( li[i],li[i+1]-li[i] ) + ' ';
                else
                    localtype += t.substr( li[i],li[i+1]-li[i] );
            }
            //if (localtype.size() > 0) localtype.erase(localtype.size()-1);
            p.nameVariable = localtype;
            localtype = "";
            for(i=0;i<iOpenedBraket-2; i +=2 ) {
                if (i<iOpenedBraket-4)
                    localtype += t.substr( li[i],li[i+1]-li[i] ) + ' ';
                else
                    localtype += t.substr( li[i],li[i+1]-li[i] );
            }
            //if (localtype.size() > 0) localtype.erase(localtype.size()-1);
            p.type.name = localtype;
            p.type.principalName = principal_type_of( localtype );
        } else {
            p.nameVariable = t.substr( li[iEgal-2],li[iEgal-1]-li[iEgal-2] );
            localtype = "";
            for(i=0;i<iEgal-2; i +=2 ) {
                if (i<iEgal-4)
                    localtype += t.substr( li[i],li[i+1]-li[i] ) + ' ';
                else
                    localtype += t.substr( li[i],li[i+1]-li[i] );
            }
            //if (localtype.size() > 0) localtype.erase(localtype.size()-1);
            p.type.name = localtype;
            p.type.principalName = principal_type_of( localtype );
        }
    } else {
        // pas de égal
        p.defaultType = "";
        if (iOpenedBraket >= 0) {
            // il y a un crochet
            localtype = "";
            for(i=iOpenedBraket-2;i<li.size(); i +=2 ) {
                if (i<li.size()-2)
                    localtype += t.substr( li[i],li[i+1]-li[i] ) + ' ';
                else
                    localtype += t.substr( li[i],li[i+1]-li[i] );
            }
            //if (localtype.size() > 0) localtype.erase(localtype.size()-1);
            p.nameVariable = localtype;
            localtype = "";
            for(i=0;i<iOpenedBraket-2; i +=2 ) {
                if (i<iOpenedBraket-4)
                    localtype += t.substr( li[i],li[i+1]-li[i] ) + ' ';
                else
                    localtype += t.substr( li[i],li[i+1]-li[i] );
            }
            //if (localtype.size() > 0) localtype.erase(localtype.size()-1);
            p.type.name = localtype;
            p.type.principalName = principal_type_of( localtype );

        } else {
            // pas de crochet ni de signe égal : donc c'est simple...
            p.nameVariable = t.substr( li[li.size()-2],li[li.size()-1]-li[li.size()-2] );
            localtype = "";
            for(i = 0; i< li.size()-2; i+= 2) {
                if (i<li.size()-4)
                    localtype += t.substr( li[i],li[i+1]-li[i] ) + ' ';
                else
                    localtype += t.substr( li[i],li[i+1]-li[i] );
            }
            //if (localtype.size() > 0) localtype.erase(localtype.size()-1);
            p.type.name = localtype;
            p.type.principalName = principal_type_of( localtype );
        }
    }
}

/*
void PageComment::state_function( int* suivant, Function* f, string& t ,int end, int start ) {

}*/

void PageComment::state_template( int* suivant, ListTemplateParameter& listeParam, string& t ,int end, int start ) {

    vector<string> listeLexems;
    string locals;
    int pos,next,i,n,iEgal,nbOrder;
    TemplateParameter* ptr_tp;
    char delim,c;


    //listeParam.clear();
    nbOrder = 1;
    //cerr << "[[[" << t.substr(start,end-start) << "]]]" << endl;
    extraire_token(&start,&delim,"[]{}<>&*/:;()=\n \t",t,end,start );// l'objectif de cet appel es d'enlever le signe < attendu.

    while ((pos = extraire_token(&next,&delim,"<>&*:;=,\n \t",t,end,start )) >= 0 ) {
        c = t[pos];
        //cerr << "__|" << t.substr( pos,next-pos ) <<"|__" << endl;
        if (c == '<') { start = next; nbOrder++; }
        if (c == '>') { start = next; nbOrder--; }
        if ( ((c == ',') && (nbOrder == 1)) || ((c =='>') && (nbOrder == 0)) ) {
            if (listeLexems.size() > 0) {
                n = listeLexems.size();
                ptr_tp = new TemplateParameter();
                iEgal = -1;
                for(i=0;i<n;i++) 
                    if (listeLexems[i] == "=") {
                        iEgal = i;
                        break;
                    }
                if (iEgal>= 1) {
                    locals = "";
                    for(i=0;i<iEgal-1;i++) 
                        locals += listeLexems[i] + ' ';
                    cut_space( locals );
                    ptr_tp->type = locals;
                    //cout << "uuu|||" << ptr_tp->type << "|||uuu" << endl;
                    ptr_tp->name = listeLexems[iEgal-1];
                    locals = "";
                    for(i=iEgal+1;i<n;i++) 
                        locals += listeLexems[i] + ' ';
                    cut_space( locals );
                    ptr_tp->defaultType = locals;
                } else {
                    locals = "";
                    for(i=0;i<n-1;i++) 
                        locals += listeLexems[i] + ' ';
                    cut_space( locals );
                    ptr_tp->type = locals;
                    ptr_tp->name = listeLexems[n-1];
                }

                listeLexems.clear();
                listeParam.push_back( ptr_tp );
            } else {
                ptr_tp = new TemplateParameter();
                listeParam.push_back( ptr_tp );
            }
            if (c =='>') {
                *suivant = next;
                return;
            }
        } else {
            listeLexems.push_back(t.substr( pos,next-pos ));
        }
        start = next;
    }
}

// à améliorer
void PageComment::copy_listTemplateParameter( ListTemplateParameter& res, ListTemplateParameter& src ) {

    int i;
    TemplateParameter* ptr_tp;

    // à améliorer
    res.clear();
    for(i=0;i<src.size(); i++) {
        ptr_tp = new TemplateParameter( src[i]->type, src[i]->name, src[i]->defaultType );
        res.push_back( ptr_tp );
    }
}

// cette fonction recherche s'il y a des mots écrits au début de la ligne à aprtir de la position start
bool PageComment::code_before_comment(string& t ,int start ) {

    bool reponse;
    char c;
    
    

    while(start >=0) {
        
        c = t[start];
        if (c == '\n') break;
        if ((c == ' ') || (c == '\t')) 
            start--; 
        else 
            return true;
    }
    return false;
}

void PageComment::addComment( Comment* c )
{
 listComment.push_back( c );
}

bool PageComment::comment_of_code( string& s) {

    string stmp;
    char lexem_example[16];
    char lexem_tutorial[16];
    int pos,next;
    char delim;

    
    lexem_example[0] = '\\';
    strcpy( lexem_example+1, Comment::keyword[6] );
    lexem_tutorial[0] = '\\';
    strcpy( lexem_tutorial+1, Comment::keyword[7] );
    if ((pos = extraire_token(&next,&delim," \t\n",s,s.size(),0)) >=0) {
        stmp = s.substr(pos,next-pos);
        //cerr << "premier lexem du commentaire = |" << stmp << "|" << endl;
        if ((stmp == lexem_example) || (stmp == lexem_tutorial))
            return false;
        else
            return true;
    }
//     reponse = !chercher_motif( s,lexem_example,&pos,s.size(),0 );
//     reponse = !chercher_motif( s,lexem_tutorial ,&pos,s.size(),0 ) & reponse;
    //cout << " lexem_example = " << lexem_example << endl;
    //cout << " lexem_tutorial = " << lexem_tutorial << endl;
    //cout << " reponse = " << reponse << endl;
    return true;
}

string PageComment::principal_type_of( string& na) {

    deque<int> localListIndex;
    string stmp;
    int k,end,next;
    char delim,c;

    end = na.size();
    if (end == 0) return "";
    extract_list_lexem( &next,localListIndex,&delim,"<","<>[]{}&*/:;()=\t \n",na,end,0 );
    if (delim == '<') {
        if (localListIndex.size() > 0) {
            k = localListIndex.size() -2;
            return na.substr( localListIndex[k], localListIndex[k+1]-localListIndex[k] );
        }
        else {
            return "";
        }
    }
    else {
        k = na.size()-1;
        while(k >= 0) {
            c = na[k];
            if ((c == '*') || (c == '&') || (c == '[') || (c == ']'))
                k--;
            else
                break;
        }
        stmp = na.substr(0, k+1 );
        cut_space( stmp );
        return stmp;
    }
}

/*!
    Recherche la fonction ou la classe qui contient _le
*/
// Lexem* PageComment::research_containerType(Lexem* _le) {
//     
//     if (_le) {
//         cerr << " parcours de "; _le->display_just_name_and_type(cerr);
//         while(true) {
//             if (_le->parent) {
//                 cerr << " a pour parent "; _le->parent->display_just_name_and_type(cerr);
//                 switch(_le->parent->type) {
//                     case STRING___class___NUM :
//                         return _le->parent;
//                     case STRING___def___NUM :
//                         return _le->parent;
//                 }
//                 _le = _le->parent;
//             } else {
//                 if (_le->prev) {
//                     cerr << " a pour prédécesseur "; _le->prev->display_just_name_and_type(cerr);
//                     _le = _le->prev;
//                 } else
//                     return NULL;
//             }
//         }
//         return NULL;
//     } else
//         return NULL;
// }

/*!
    Cette fonction renvoie l'adresse d'un asssign ou reassign dans le cas où _le a un enfant assign ou reassign sinon elle renvoie NULL
*/
Lexem* PageComment::research_if_assign_reassign_def_class(Lexem* _le) {
    
/*    if (_le)
        cerr << " parcours de "; _le->display_just_name_and_type(cerr);*/
    while(_le) {
        //cerr << " a pour enfant gauche "; _le->display_just_name_and_type(cerr);
        if ((_le->type == STRING_reassign_NUM) or (_le->type == STRING_assign_NUM)  or (_le->type == STRING___def___NUM)  or (_le->type == STRING___class___NUM))
            return _le;
        _le = _le->children[0];
    }
    return NULL;
}

/// ajoute la fonction pointée par _le à code
void PageComment::append_function( Bloc* code, Lexem* _le, const string& attr) {
    string stmp;
    FunctionMetil* fonction;
    LexemDefinition *def;
    const Lexem* le;
    const Lexem* le2;
    const Lexem* le3;
    deque<Comment_zone> list_comment;
    Comment* ptr_comment;
    int typeComment,pos,pos2;

    fonction = new FunctionMetil();
    fonction->source_file = nameFile;
    fonction->listAttribut = attr;
    def = _le->def;
    if (def) {
        //cerr << " la fonction a un def" << endl;
        if (def->tname) {
            le = def->tname;
            fonction->name.name.append(le->s,le->si);
            fonction->name.principalName.append(le->s,le->si);
        }
        /// pertinence
        if (def->pertinence) {
            le = def->pertinence;
            //cerr << "IIIIIIIIIIIII pertinence = "; cerr.write(le->s,le->si); cerr << endl;
        }
        //cerr << "IIIIIIIIIIIII pertinence par défaut = " << def->default_pertinence << endl;
        /// condition
        if (def->condition) {
            le = def->condition;
            if (le->children[0]) {
                le2 = leftmost_child(le->children[0]);
                le3 = rightmost_child(le->children[0]);
                stmp.append(le2->s,le3->s-le2->s+le3->si);
            }
            /// récupération de l'expression à droite
            if (le->children[1]) {
                switch(le->type) {
                    case STRING_or_boolean_NUM : stmp.append(" or "); break;
                    case STRING_and_boolean_NUM : stmp.append(" and "); break;
                    case STRING_xor_boolean_NUM : stmp.append(" xor "); break;
                    //case STRING_not_boolean_NUM : stmp.append(" not "); break;
                    case STRING_not_equal_NUM : stmp.append(" != "); break;
                    case STRING_equal_NUM : stmp.append(" == "); break;
                    case STRING_superior_equal_NUM : stmp.append(" >= "); break;
                    case STRING_inferior_equal_NUM : stmp.append(" <= "); break;
                    case STRING_superior_NUM : stmp.append(" > "); break;
                    case STRING_inferior_NUM : stmp.append(" < "); break;
                    case STRING___is_a___NUM : stmp.append(" is a "); break;
                    case STRING_concatenate_NUM : stmp.append(" + "); break;
                    //case STRING_range_NUM : stmp.append(" range "); break;
                    case STRING_triple_dots_NUM : stmp.append(" ... "); break;
                    case STRING_add_NUM : stmp.append(" + "); break;
                    case STRING_sub_NUM : stmp.append(" - "); break;
                    case STRING_mod_NUM : stmp.append(" mod "); break;
                    case STRING_mul_NUM : stmp.append(" x "); break;
                    case STRING_div_NUM : stmp.append(" / "); break;
                    case STRING_div_int_NUM : stmp.append(" // "); break;
                    case STRING_ml_div_NUM : stmp.append(" x/ "); break;
                    case STRING_pow_NUM : stmp.append(" ^ "); break;
                    case STRING___pow___NUM : stmp.append(" ^ "); break;
                    case STRING_not_bitwise_NUM : stmp.append(" not bitwise "); break;
                    case STRING_trans_NUM : stmp.append(" trans "); break;
                    case STRING_tensorial_product_NUM : stmp.append(" tx "); break;
                    case STRING_get_attr_ptr_NUM : stmp.append("->"); break;
                    case STRING_get_attr_NUM : stmp.push_back('.'); break;
                    default:
                        stmp.append(" unknow "); /// provisoire
                }
                le2 = leftmost_child(le->children[1]);
                le3 = rightmost_child(le->children[1]);
                stmp.append(le2->s,le3->s-le2->s+le3->si);
            }
            //cerr << "IIIIIIIIIIIII condition = " << stmp << endl;
            fonction->condition = stmp;
        }
        /// arguments
        for(int i=0;i<_le->def->arguments.size();++i) {
            Parameter p;//p.clear();
            if (def->arguments[i].tname) 
                p.nameVariable.append(def->arguments[i].tname->s,def->arguments[i].tname->si);
            if (def->arguments[i].type_constraint) {
                le = def->arguments[i].type_constraint;
                p.type.name.append(le->s,le->si);
                p.type.principalName.append(le->s,le->si);
            }
            if (def->arguments[i].default_value) {
                le = def->arguments[i].default_value;
                p.defaultType.append(le->s,le->si);
            }
            fonction->listParameter.push_back(p);
        }
        //cerr << " liste des paramètres de la fonction : ";
        //cerr << fonction->listParameter.size() << endl;
        if (def->return_type) {
            le = _le->def->return_type;
            fonction->returnType.name.append(le->s,le->si);
        }
    } //else
        //cerr << " la fonction " << fonction->name.name << " n' a pas de def" << endl;

    /** récupération des commentaires  **/
    doc_of(_le,list_comment);
    for(int i=0;i<list_comment.size();++i) {
        //cout << "comment function  " << list_comment[i] << endl;
        typeComment = findKeyword_(&pos,&pos2,list_comment[i].start,list_comment[i].size,0);
        if ((typeComment != COMMENT__EXAMPLE) and (typeComment != COMMENT__TUTORIAL) and (typeComment != COMMENT__GENERIC_COMMENT)) {
            ptr_comment = new Comment( nameFile );
            ptr_comment->parse( ptr_comment->items, list_comment[i].start, list_comment[i].size);
            fonction->listTag.push_back(ptr_comment);
        }
    }

    code->list_subType_function.push_back( fonction );
}

string PageComment::getAttribut( Lexem* start, Lexem* end) {

    string stmp;

    /// récuparation des attributs
    while (start != end) {
        stmp.append(start->s,start->si);
        stmp.push_back(' ');
        start = start->children[0];
    }
    return stmp;
}

void PageComment::append_member( Bloc* code, Lexem* le, const string& attr) {
    Parameter p;
    const Lexem* le2;
    const Lexem* le3;
    deque<Comment_zone> list_comment;
    Comment* ptr_comment;
    int typeComment,pos,pos2;

    p.listAttribut = attr;
    /// récuparation du nom
    if (le->children[0]) {
        le2 = leftmost_child(le->children[0]);
        le3 = rightmost_child(le->children[0]);
        p.nameVariable.append(le2->s,le3->s-le2->s+le3->si);
    }
    p.op.append(le->s,le->si);/// devrait être soit = soit := soit ~=
    /// récupération de l'expression à droite
    if (le->children[1]) {
        le2 = leftmost_child(le->children[1]);
        le3 = rightmost_child(le->children[1]);
        p.defaultType.append(le2->s,le3->s-le2->s+le3->si);
        if (p.defaultType.size()==0) {
            //cerr << " p.defaultType = |" << p.defaultType << "|" << endl;
            //cerr << " le2->s =  " << (int) le2->s << " le2->si = " << le2->si << " le3->s = " << (int) le3->s << " le3->si = " << le3->si << endl;
            p.defaultType = "\"\""; /// A REVOIR...
        }
    }
    /** récupération des commentaires  **/
    doc_of(le,list_comment);
    for(int i=0;i<list_comment.size();++i) {
        //cout << "comment member " << list_comment[i] << endl;
        typeComment = findKeyword_(&pos,&pos2,list_comment[i].start,list_comment[i].size,0);
        if ((typeComment != COMMENT__EXAMPLE) and (typeComment != COMMENT__TUTORIAL) and (typeComment != COMMENT__GENERIC_COMMENT)) {
            ptr_comment = new Comment( nameFile );
            ptr_comment->parse( ptr_comment->items, list_comment[i].start, list_comment[i].size);
            p.listTag.push_back(ptr_comment);
        }
    }
    code->listMember.push_back(p);
}

void PageComment::append_property( Bloc* code, const Lexem* le) {
    Parameter p;
    VisitorBloc_getProperty visi;
    deque<Comment_zone> list_comment;
    Comment* ptr_comment;
    int typeComment,pos,pos2;

    code->exec( &visi);
    if ((visi.ptr_listProperty ) and (le->children[0])) {
        p.type.name.append(le->children[0]->s,le->children[0]->si);
        p.type.principalName.append(le->children[0]->s,le->children[0]->si);
        /** récupération des commentaires  **/
        doc_of(le,list_comment);
        for(int i=0;i<list_comment.size();++i) {
            //cout << list_comment[i] << endl;
            typeComment = findKeyword_(&pos,&pos2,list_comment[i].start,list_comment[i].size,0);
            if ((typeComment != COMMENT__EXAMPLE) and (typeComment != COMMENT__TUTORIAL) and (typeComment != COMMENT__GENERIC_COMMENT)) {
                ptr_comment = new Comment( nameFile );
                ptr_comment->parse( ptr_comment->items, list_comment[i].start, list_comment[i].size);
                p.listTag.push_back(ptr_comment);
            }
        }
        visi.ptr_listProperty->push_back(p);
    }
    
}

void PageComment::append_class( Bloc* code, Lexem* _le) {
    ClasseMetil* classe;
    TemplateParameter* ptr_tp;
    Parameter p;
    const Lexem* le;
    deque<Comment_zone> list_comment;
    Comment* ptr_comment;
    int typeComment,pos,pos2;

    classe = new ClasseMetil();
    classe->source_file = nameFile;
    if (_le->def) {
        le = _le->def->tname;
        classe->name.name.append(le->s,le->si);
        classe->name.principalName.append(le->s,le->si);
        /// héritage
        for(int i=0;i<_le->def->inheritance.size();++i) {
            p.clear();
            le = _le->def->inheritance[i];
            p.type.name.append(le->s,le->si);
            classe->listHerited.push_back(p);
        }
        /// arguments template
        for(int i=0;i<_le->def->arguments.size();++i) {
            ptr_tp = new TemplateParameter();
            if (_le->def->arguments[i].tname) 
                ptr_tp->name.append(_le->def->arguments[i].tname->s,_le->def->arguments[i].tname->si);
            if (_le->def->arguments[i].default_value) {
                le = _le->def->arguments[i].default_value;
                ptr_tp->defaultType.append(le->s,le->si);
            }
            classe->listTemplateParameter.push_back(ptr_tp);
        }
    }
    /** récupération des commentaires  **/
    doc_of(_le,list_comment);
    //cout << "== commentaires de " << fonction->name.name << endl;
    for(int i=0;i<list_comment.size();++i) {
        //cout << list_comment[i] << endl;
        typeComment = findKeyword_(&pos,&pos2,list_comment[i].start,list_comment[i].size,0);
        if ((typeComment != COMMENT__EXAMPLE) and (typeComment != COMMENT__TUTORIAL) and (typeComment != COMMENT__GENERIC_COMMENT)) {
            ptr_comment = new Comment( nameFile );
            ptr_comment->parse( ptr_comment->items, list_comment[i].start, list_comment[i].size);
            classe->listTag.push_back(ptr_comment);
        }
    }
    /// ensuite on parcourt via next toutes les "instructions"
    /// on commence par sauter le (-9)
    parse_language_Metil_rec(classe,_le->children[1]->children[0]);
    code->list_subType_function.push_back( classe );
}

void PageComment::parse_language_Metil_rec( Bloc* code, Lexem* le, const string& attr) {

    Lexem* ret;
    int indice;
    string stmp;
    
    while(le) {
        switch(le->type) {
            case STRING___class___NUM :
                //cerr << "{" << code->name.name << "} CLASS " ;le->display_just_name_and_type(cerr);
                append_class(code,le);
                break;
            case STRING___def___NUM :
                //cerr << "{" << code->name.name << "} DEF " ;le->display_just_name_and_type(cerr);
                append_function(code,le,attr);
                break;
            case STRING_assign_NUM : case STRING_reassign_NUM : case STRING_assign_type_NUM :
                //cerr << "{" << code->name.name << "} (RE)ASSIGN " ;le->display_just_name_and_type(cerr);
                append_member(code,le,attr);
                break;
            case STRING___static___NUM : case STRING___const___NUM : case STRING___virtual___NUM :
                ret = research_if_assign_reassign_def_class(le);
                if (ret) {
                    parse_language_Metil_rec(code,ret,getAttribut(le,ret));
                }
                break;
            case STRING___property___NUM :
                //cerr << "{" << code->name.name << "} PROPERTY " ;le->display_just_name_and_type(cerr);
                append_property(code,le);
                break;
            case STRING___import___NUM : case STRING___for___NUM : case STRING___if___NUM :
                /// mot-clés ignorés
                break;
            default :
                /// on ne sait pas trop ce que c'est. L'idée est de remonter les parents jusqu'à trouver un def, class ou (re)assign si c'est possible
                cerr << "{" << code->name.name << "} TRAITEMENT PAR DEFAUT DU " ;le->display_just_name_and_type(cerr); cerr << " du fichier " << nameFile << endl;
                //append_member(code,le);
                break;
        }
        //cerr << " ---> " << endl;
//         le->display_just_name_and_type(cerr);
        le = le->next;
    }
}

/// recherche le début et la fin d'un commentaire sur plusieurs lignes
Comment_zone PageComment::getComment_multiLine( char* s) {
    Comment_zone comment_zone;
    char *b;
    char* c;

    if (not(*s) or (*s == '#') or (*s == '~')) /// problème
        return comment_zone;
    /// reherche du début
    b = s-1;
    while(*b) {
        for( ; *b ; --b )
            if ((*b == '~') or (*b == '#'))
                break;
        if (not(*b))
            return comment_zone; /// problème
        b--;
        if (*b == '#') {
            comment_zone.start = b+2;
            break;
        } else
            continue;
    }
    /// recherche de la fin
    b = s+1;
    while(*b) {
        for( ; *b ; ++b )
            if ((*b == '~') or (*b == '#'))
                break;
        if (not(*b))
            return comment_zone; /// problème remarque : size == 0
        b++;
        if (*b == '#') {
            comment_zone.size = b-2-comment_zone.start;
            return comment_zone;
        } else
            continue;
    }
}

/// on cherche et analyse  les commentaires du type |tutorial, \example, \webpage et eventuellemnt \generic_comment
void PageComment::search_parse_special_comment(const char* s, int end) {
    Comment_zone comment_zone;
    int typeComment,pos,pos2,start,jump;
    Comment* ptr_comment;

    start = 0;
    while((typeComment = findKeyword_(&pos,&pos2,s,end,start)) >= 0) {
        switch(typeComment) {
            case COMMENT__EXAMPLE : case COMMENT__TUTORIAL : case COMMENT__WEBPAGE : case COMMENT__GENERIC_COMMENT :
                comment_zone = getComment_multiLine((char*)s+pos);
                if (comment_zone.size > 0) {
                    //cout << "~~~|" << comment_zone << "|~~~" << endl;
                    ptr_comment = new Comment( nameFile );
                    ptr_comment->parse( ptr_comment->items, comment_zone.start, comment_zone.size);
                    listComment.push_back(ptr_comment);
                    start = comment_zone.start - s + comment_zone.size + 2;
                } else
                    start = pos2;
                break;
            default:
                start = pos2;
        }
    }
}

void PageComment::parse_language_Metil(string& textOfCode) {

    char provenance[256];
    ErrorList error_list;

    Lexer lexer(textOfCode.c_str(),provenance,&error_list);
    //display_graph(lexer.root());
    parse_language_Metil_rec( &code,(Lexem*) lexer.root());
//     parse_language_Metil_rec(code,Lexer(textOfCode.c_str(),provenance,&error_list).root());
    /// on analyse ensuite les commentaires du type |tutorial, \example, \webpage et eventuellemnt \generic_comment
    search_parse_special_comment(textOfCode.c_str()+1,textOfCode.size()-1); /// +1 pour passer le \0 du début
}

void PageComment::parse_language_Cpp( string& textOfCode) {
    string tag,stmp;
    int i,pos,start,pos2,prefix;
    Comment* ptr_comment;
    char delim;
    vector<string> commentaire;
    stringstream ss;
    
    /// on recherche les commentaires que l'on veut parser
    /// on jette les commentaires normaux ou ceux de doxygen
    start = 0;
    while( chercher_motif( textOfCode, "/*", &pos, textOfCode.size(), start  ) ) {
        //cout << " CODE  ___|" << texte.substr(start,pos-start) << "|___" << endl;
        if (textOfCode[pos+2] == '!') { 
            /// c'est un bon commentaire. un vrai de vrai
            /// on regarde si du code précède ce commentaire.
            if (code_before_comment(textOfCode ,pos-1)) prefix = 1; else prefix = 0; 
            if (chercher_motif( textOfCode ,"*/",&pos2,textOfCode.size(),pos+3 )) {
                /// on a trouvé la fin du commentaire.
                if (pos+3 < pos2) {
                    /// on a un bout de vrai commentaire
                    stmp = textOfCode.substr(pos+3,pos2-pos-3);
                    commentaire.push_back( stmp );
                    if (comment_of_code( stmp )) {
                        if (code_before_comment(textOfCode,pos-1))
                            prefix = 1; 
                        else 
                            prefix = 0;
                    }
                    else
                        prefix = 2;
                    ss.str("");
                    ss << commentaire.size() - 1;
                    tag = prefixTag[prefix] + ss.str();
                    textOfCode.erase( pos, pos2 + 2 - pos ); /// on retire le commentaire
                    textOfCode.insert( pos, tag ); /// on met un tag en référence au commentaire
                }
                start = pos + 2;
            } else {
                /// on n' a pas trouvé la fin : ce qui n'est pas normal...
                cout << " Il manque la balise de fin de commentaire." << endl;
                //cout << " COMMENTAIRE  ---|" << texte.substr(pos,texte.size()-pos) << "|---" << endl;
                if ( pos + 3 < textOfCode.size() ) {
                    // on a un bout de vrai commentaire mais il n'y a pas de */ final...
                    pos2 = textOfCode.size();
                    stmp = textOfCode.substr( pos + 3, pos2 - pos2 - 3 );
                    commentaire.push_back( textOfCode.substr( pos + 3, pos2 - pos2 - 3 ) );
                    if (comment_of_code( stmp ) ) {
                        if (code_before_comment( textOfCode, pos - 1 ) )
                            prefix = 1; 
                        else 
                            prefix = 0;
                    }
                    else
                        prefix = 2;
                    ss.str("");
                    ss << commentaire.size() - 1;
                    tag = prefixTag[ prefix ] + ss.str();
                    textOfCode.erase( pos,pos2-pos ); /// on retire le commentaire
                    textOfCode.insert( pos, tag ); /// on met un tag en référence au commentaire
                }
                start = pos2;
            }
        } else {
            /// c'est un commentaire doxygen ou un commentaire normal et donc on passe à la suite
            if (chercher_motif( textOfCode,"*/",&pos2,textOfCode.size(),pos+2 )) {
                /// on a trouvé la fin du commentaire.
                textOfCode.erase( pos,pos2+2-pos );
                start = pos;
            } else {
                // on n' a pas trouvé la fin : ce qui n'est pas normal...
                cerr << " Il manque la fin d'un commentaire." << endl;
                pos2 = textOfCode.size();
                textOfCode.erase( pos,pos2-pos );
                start = pos2; //break; // oups !!!!!!!!
            }
        }
    }

    // on se débarasse des commentaires de fin de ligne du type // 
    start = 0;
    //n = texte.size();
    while(chercher_motif( textOfCode,"//",&pos,textOfCode.size(),start )) {
        if (textOfCode[pos+2] == '/') {
            //c'est un bon commentaire
            if (code_before_comment(textOfCode,pos-1)) prefix = 1; else prefix = 0; 
            if (chercher_motif( textOfCode,"\n",&pos2,textOfCode.size(),pos+3 )) 
                ;
            else 
                pos2 = textOfCode.size();

            stmp = textOfCode.substr(pos+3,pos2-pos-2);
            commentaire.push_back( stmp );
            if (comment_of_code( stmp )) {
                if (code_before_comment(textOfCode,pos-1))
                    prefix = 1; 
                else 
                    prefix = 0;
            }
            else
                prefix = 2;
            ss.str("");
            ss << commentaire.size() - 1;
            tag = prefixTag[prefix] + ss.str();
            //cout << " tttttttttag =" << tag << "|||" << endl;
            textOfCode.erase( pos,pos2-pos ); // on retire le commentaire
            textOfCode.insert( pos, tag ); // on met un tag en référence au commentaire
        }
        else
        {
            if (chercher_motif( textOfCode,"\n",&pos2,textOfCode.size(),pos+2 )) {
                // on va donc supprimer la fin de la ligne
                textOfCode.erase( pos,pos2-pos );
            } 
            else {
                // donc c'était la fin du fichier
                textOfCode.erase( pos,textOfCode.size()-pos );
            }
        }
        start = pos;
    }


//     cout << "------------------------- le code ---------------------------" << endl;
//     cout << texte << endl;
//     cout << "-------------------------------------------------------------" << endl;
//     cout << "-------------------------------------------------------------" << endl;
//     cout << "######### nombre de commentaire = "<< commentaire.size() << endl;
//     for(i=0;i<commentaire.size(); i++ ) {
//         cout << "#################### COMMENTAIRE  #############" << endl;
//         cout << commentaire[i] << endl; 
//         cout << "###############################################" << endl;
//     }

    for(i=0;i<commentaire.size(); i++ ) {
        ptr_comment = new Comment( nameFile );
        ptr_comment->parse( ptr_comment->items,commentaire[i],commentaire[i].size(),0 );
        listComment.push_back( ptr_comment );
        //cout << *ptr_comment << endl;
    }
    
    parse_language_Cpp_rec( &code,textOfCode,textOfCode.size(),0);
}

void PageComment::parse_language_Cpp_rec( Bloc* code, string& textOfCode, int end, int start ) {

    ListTemplateParameter listeTemplateParameter;
    ListParameter listeParameter;
    Names name;
    vector<Comment*> listTagLocal;
    Parameter* ptr_p;
    deque<int> listeIndexLexem; // tableau à 2k valeurs 2j est l'index de début du lexem j et 2j+1 l'index du caractère qui le suit 

    string stmp;
    string portee;
    int i,pos,suivant,n,etat,nbComment,suivant2,pos2,pos3;
    Classe* classeCourante;
    Struct* structCourant;
    Function* fonctionCourante;
    TagComment* tag;
    char* offset;
    bool isDeclaration;
    char delim;

    /*
    n = start;
    cout << " -------------------- " << code << endl;
    while ( (pos = extraire_token(&suivant,&delim,textOfCode,end,start )) >= 0) {
        if (delim != '\n') cout << "lexem ==|" << textOfCode.substr(pos,suivant-pos)  << "|=== " << "\t\t\t\t\t\t delim =||" <<  delim << "||" << endl;
        else cout << "lexem ==|" << textOfCode.substr(pos,suivant-pos)  << "|=== " << "\t\t\t\t\t\t delim =||" <<  'n' << "||" << endl;
        start = suivant;
    }
    start = n;
    */
    tag = NULL;

    while ( (pos = extraire_token(&suivant,&delim,"[]{}<>&*/:;()=\n \t",textOfCode,end,start )) >= 0) { // boucle principale de lecture des lexems
        //cout << "lexem ==|" << textOfCode.substr(pos,suivant-pos)  << "|=== " << "\t\t\t\t\t\t delim =||" <<  delim << "||" << endl;
        //cout << " start = " << start << endl;
        //cout << " end   = " << end << endl;
        etat = state( textOfCode,suivant,pos );
        //cout << " etat = " << etat << endl;
        //cout << " ============ BOUCLE ============== " << endl;
        switch(etat) {
            case PREPROCESSOR_STATE_ID :
                                        state_preprocessor(&start,textOfCode,end,pos);
                                        break;
            case EXTERN_STATE_ID :
                                        if (state_extern(&suivant,textOfCode,end,suivant))
                                           ;
                                            //parse_language_cpp( code,textOfCode,suivant,start  );
                                        if (suivant>=0) 
                                            start = suivant;
                                        else {
                                            suivant = end;
                                            cerr << " j'ai rencontré un problème de } " << endl;
                                        }
                                        break;
            case NAMESPACE_STATE_ID :
                                        code->_namespace = state_namespace( &start,textOfCode,end,suivant ); 
                                        break;

            case PORTED_STATE_ID :
                                        extract_ported( &start,portee,textOfCode,end,pos );
                                        break;

            case TEMPLATE_STATE_ID  :
                                        state_template( &start,listeTemplateParameter,textOfCode,end,suivant ); // extraction des paramètres template 
                                        // on examine le lexem suivant pour savoir si ce sont les paramètres d'une classe, d'une structure ou d'une fonction.
                                        pos = extraire_token(&suivant,&delim,"[]{}<>&*/:;()=\n \t",textOfCode,end,start );
                                        stmp = textOfCode.substr(pos,suivant-pos); // à améliorer : on peut se passer de stmp
                                        if (stmp == "struct") {
                                            extract_name_heritedClass( &start,name,listeParameter,&delim,textOfCode,end,suivant );
                                            if (delim == '{') {
                                                // en effet dans les .h on a besoin de déclarer les structures que l'on veut utiliser; e.g. class Toto; 
                                                structCourant = new Struct();
                                                structCourant->source_file = nameFile;
                                                structCourant->name = name;
                                                //structCourant->suffix_source = suffix_source;
                                                structCourant->listHerited = listeParameter;
                                                structCourant->listTemplateParameter = listeTemplateParameter;
                                                tag = structCourant;
                                                structCourant->listTag = listTagLocal;
                                                listTagLocal.clear();
                                                structCourant->portee = portee;
                                                //copy_listTemplateParameter( structCourant->listTemplateParameter, listeTemplateParameter );
                                                //extract_name_heritedClass( &start,structCourant->name,structCourant->listHerited,&delim,textOfCode,end,suivant );
                                                structCourant->_namespace = code->_namespace;
                                                code->list_subType_function.push_back( structCourant );
                                                get_block(&suivant,"{}",textOfCode,end,start );
                                                // appel récursif entre start et suivant  **************
                                                parse_language_Cpp_rec( structCourant,textOfCode,suivant,start  );
                                                start = suivant;
                                            }

                                        } else {
                                            if (stmp == "class") {
                                                extract_name_heritedClass( &start,name,listeParameter,&delim,textOfCode,end,suivant );
                                                if (delim == '{') {
                                                    classeCourante = new Classe();
                                                    classeCourante->source_file = nameFile;
                                                    ///classeCourante->suffix_source = suffix_source;
                                                    classeCourante->name = name;
                                                    classeCourante->listHerited = listeParameter;
                                                    classeCourante->listTemplateParameter = listeTemplateParameter;
                                                    tag = classeCourante;
                                                    classeCourante->listTag = listTagLocal;
                                                    listTagLocal.clear();
                                                    classeCourante->portee = portee;
                                                    //copy_listTemplateParameter( classeCourante->listTemplateParameter,listeTemplateParameter );
                                                    //extract_name_heritedClass( &start,classeCourante->name,classeCourante->listHerited,&delim,textOfCode,end,suivant );
                                                    classeCourante->_namespace = code->_namespace;
                                                    code->list_subType_function.push_back( classeCourante );
                                                    get_block(&suivant,"{}",textOfCode,end,start );
                                                    /// appel récursif entre start et suivant  **************
                                                    parse_language_Cpp_rec( classeCourante,textOfCode,suivant,start  );
                                                    start = suivant;
                                                }
                                            } else {
                                                /// ça doit être une fonction
                                                if (chercher_delimitateur( textOfCode,"{;",&pos,end,start )) {
                                                    fonctionCourante = new Function();
                                                    ///fonctionCourante->ancestor = code;
                                                    fonctionCourante->source_file = nameFile;
                                                    tag = fonctionCourante;
                                                    fonctionCourante->listTag = listTagLocal;
                                                    listTagLocal.clear();
                                                    fonctionCourante->portee = portee;
                                                    fonctionCourante->_namespace = code->_namespace;
                                                    //suivant2 = index_begin_signature(textOfCode,pos,start);
                                                    extract_returnType_name( &suivant2,code->name.principalName,fonctionCourante->returnType,fonctionCourante->name,textOfCode,pos,start );
                                                    extract_parametersFunction( &start,fonctionCourante->listParameter,textOfCode,pos,suivant2+1 ); // +1 pour sauter le (
                                                    ///fonctionCourante->signature = textOfCode.substr( suivant,start-suivant2 );
                                                    extract_FinalAttributFunction( &start,fonctionCourante->listAttribut,&delim,textOfCode,pos,start+1 );// +1 pour sauter le )
                                                    code->list_subType_function.push_back( fonctionCourante );
                                                    if (textOfCode[pos] == '{' )
                                                        get_block(&start,"{}",textOfCode,end,pos+1 ); // on saute le bloc de la fonction. Rem : +1 pour sauter le {
                                                } else {
                                                    cerr << " -- BUG PARSING : sorry !  what's the matter ?--" << endl;
                                                }
                                            }
                                        }
                                        listeTemplateParameter.clear();
                                        listeParameter.clear();
                                        break;

            case TYPEDEF_STATE_ID :
                                        ptr_p = new Parameter();
                                        tag = ptr_p;
                                        ptr_p->listTag = listTagLocal;
                                        listTagLocal.clear();
                                        state_typedef( &start,ptr_p->type,ptr_p->nameVariable,textOfCode,end,suivant ); // traite correctement uniquement les cas simples : 
                                                                                                       //pas les typedef struct {} A; 
                                        code->listTypedef.push_back( *ptr_p );
                                        break;

            case CLASS_STATE_ID :
                                        extract_name_heritedClass( &start,name,listeParameter,&delim,textOfCode,end,suivant );
                                        //cout << " classe non paramétrée "<< endl;
                                        if (delim == '{') { 
                                            classeCourante = new Classe();
                                            classeCourante->source_file = nameFile;
                                            ///classeCourante->suffix_source = suffix_source;
                                            classeCourante->name = name;
                                            classeCourante->listHerited = listeParameter;
                                            listeParameter.clear();
                                            tag = classeCourante;
                                            classeCourante->listTag = listTagLocal;
                                            listTagLocal.clear();
                                            classeCourante->portee = portee;
                                            classeCourante->_namespace = code->_namespace;
                                            code->list_subType_function.push_back( classeCourante );
                                            //extract_name_heritedClass( &start,classeCourante->name,classeCourante->listHerited,&delim,textOfCode,end,suivant );
                                            get_block(&suivant,"{}",textOfCode,end,start );
                                            /// appel récursif entre start et suivant  **************
                                            parse_language_Cpp_rec( classeCourante,textOfCode,suivant,start  );
                                            start = suivant;
                                        }
                                        break;
            case STRUCT_STATE_ID :

                                        extract_name_heritedClass( &start,name,listeParameter,&delim,textOfCode,end,suivant );
                                        //cout << " struct non paramétré "<< endl;
                                        if (delim == '{') { 
                                            structCourant = new Struct();
                                            ///structCourant->suffix_source = suffix_source;isDeclaration
                                            structCourant->source_file = nameFile;
                                            structCourant->name = name;
                                            structCourant->listHerited = listeParameter;
                                            listeParameter.clear();
                                            tag = structCourant;
                                            structCourant->listTag = listTagLocal;
                                            listTagLocal.clear();
                                            structCourant->portee = portee;
                                            structCourant->_namespace = code->_namespace;
                                            code->list_subType_function.push_back( structCourant );
                                            //extract_name_heritedClass( &start,structCourant->name,structCourant->listHerited,&delim,textOfCode,end,suivant );
                                            //cout << " delim = " << delim << endl;
                                            get_block(&suivant,"{}",textOfCode,end,start );
                                            /// appel récursif entre start et suivant  **************
                                            parse_language_Cpp_rec( structCourant,textOfCode,suivant,start  );
                                            start = suivant;
                                        }
                                        break;
            case OPEN_STATE_ID :
                                        //on récupère les lexems jusqu' à une ( ou un; 
                                        // dans cette branche, on s'attend à trouver une déclaration ou une fonction
                                        if ((textOfCode[pos] == ';') || (textOfCode[pos] == '}')) { // le } pour récupérer la fin des namespace... ce n'est pas très beau, je sais
                                            start = suivant; // on est tombé sur un; qui traîne
                                        } else {
                                            if (chercher_delimitateur( textOfCode,"{;",&pos,end,start )) {
                                                delim = textOfCode[pos];
                                                switch( delim ) {
                                                    case '{' : // c'est une fonction probablemisDeclarationent (i.e. on supposera que ce n'est pas une déclaration de tableau).
                                                            fonctionCourante = new Function();
                                                            ///fonctionCourante->ancestor = code;
                                                            fonctionCourante->source_file = nameFile;
                                                            tag = fonctionCourante;
                                                            fonctionCourante->listTag = listTagLocal;
                                                            listTagLocal.clear();
                                                            fonctionCourante->portee = portee;
                                                            fonctionCourante->_namespace = code->_namespace;
                                                            //suivant2 = index_begin_signature(textOfCode,pos,start);
                                                            //cout << " CODE FONCTION = " << textOfCode.substr(start,pos-start) << endl;
                                                            extract_returnType_name( &suivant2,code->name.principalName,fonctionCourante->returnType,fonctionCourante->name,textOfCode,pos,start );
                                                            extract_parametersFunction( &start,fonctionCourante->listParameter,textOfCode,pos,suivant2+1 ); // +1 pour sauter le (
                                                            extract_FinalAttributFunction( &start,fonctionCourante->listAttribut,&delim,textOfCode,pos,start+1 ); // +1 pour sauter le )
                                                            code->list_subType_function.push_back( fonctionCourante );
                                                            get_block(&start,"{}",textOfCode,end,pos+1 );
                                                            // on saute le bloc de la fonction

                                                            break;
                                                    case ';' : // c'est une déclaration ou une fonction (espérons-le!)

                                                            isDeclaration = true;
                                                            if (r_chercher_delimitateur( textOfCode,")",&pos2,pos,start )) {
                                                                suivant2 = index_begin_signature(textOfCode,pos2,start);
                                                                if ((pos3 = r_extraire_token(&suivant2,&delim," \t",textOfCode,suivant2,start)) >= 0) {
                                                                    if (textOfCode[pos3] == '=')
                                                                        isDeclaration = false;
                                                                    else {
                                                                        if ((pos3 = r_extraire_token(&suivant2,&delim," \t",textOfCode,suivant2,start)) >= 0) {
                                                                            if (textOfCode[pos3] == '=')
                                                                                isDeclaration = true;
                                                                            else
                                                                                isDeclaration = false;
                                                                        }
                                                                    }
                                                                }
//                                                                 if (r_chercher_delimitateur( textOfCode,"=",&pos3,suivant2,start ))
//                                                                     isDeclaration = true;
//                                                                 else
//                                                                     isDeclaration = false;
                                                            }
                                                            // A ce niveau on devrait tester s'il y a bien un symbole = ... il devrait y en avoir un;-)
                                                            if (isDeclaration) {
                                                                // c'est une déclaration
                                                                ptr_p = new Parameter();
                                                                tag = ptr_p;
                                                                ptr_p->listTag = listTagLocal;
                                                                listTagLocal.clear();
                                                                get_declaration( *ptr_p,textOfCode,pos,start );
                                                                ptr_p->listAttribut += portee;
                                                                code->listMember.push_back( *ptr_p );
                                                                start = pos + 1; // +1 pour sauter le;
                                                            } else {
                                                                fonctionCourante = new Function();
                                                                ///fonctionCourante->ancestor = code;
                                                                fonctionCourante->source_file = nameFile;
                                                                tag = fonctionCourante;
                                                                fonctionCourante->listTag = listTagLocal;
                                                                listTagLocal.clear();
                                                                fonctionCourante->portee = portee;
                                                                fonctionCourante->_namespace = code->_namespace;
                                                                extract_returnType_name( &suivant2,code->name.principalName,fonctionCourante->returnType,fonctionCourante->name,textOfCode,pos,start );
                                                                extract_parametersFunction( &start,fonctionCourante->listParameter,textOfCode,pos2,suivant2+1 ); // +1 pour sauter le (
                                                                ///fonctionCourante->signature = textOfCode.substr( suivant,start-suivant2 );
                                                                extract_FinalAttributFunction( &start,fonctionCourante->listAttribut,&delim,textOfCode,pos,pos2+1 ); 
#warning   vérifier le pos2 dans  extract_FinalAttributFunction
                                                                code->list_subType_function.push_back( fonctionCourante );
                                                            }
                                                            break;
                                                }
                                            } else {
                                                cerr << " -- BUG PARSING : sorry !  what's the matter ?--" << endl;
                                            }
                                        }
                                        break;
            case TAG_STATE_ID :
                                        stmp = textOfCode.substr(pos+3,suivant-pos-3);
                                        nbComment = strtol( stmp.c_str(),&offset,10 );
                                        stmp = textOfCode.substr(pos,3);
                                        if (stmp == prefixTag[2]) {  // c'est un tag example ou tutorial donc on passe
                                            start = suivant;
                                            continue;
                                        }
                                        if ((stmp == prefixTag[1]) && (tag != NULL)) tag->listTag.push_back( listComment[nbComment] ); 
                                            else listTagLocal.push_back( listComment[nbComment] );
                                        start = suivant; // pour repartir
                                        break;
            default : 
                                        cerr << " -- BUG PARSING : sorry ! --" << endl;
                                        start = suivant;
        }
    }


    //for(i=0;i<listeTemplateParameter.size();i++) 
    //    delete listeTemplateParameter[i];
}


void PageComment::parse( Language_id id ) {
    string str,texte;

    texte.reserve( 65536 );
    str.reserve( 65536 );
    ifstream entree( nameFile.c_str() , ios::in );

    if (! entree) {
        cerr << " impossible d' ouvrir le fichier "  << nameFile << " pour PageComment::parse() " << endl;
        return;
    }

    if (id == Metil_language)  /// cela est nécessaire pour le parser de Metil
        texte.push_back('\0');

    while ( true ) { /// boucle sur la lecture de lignes
        str.clear();
        getline(entree, str ); 
        if ( !entree.good() )
            break;
        texte += str;
        texte.push_back('\n');
    }

    //cout << "texte = |||" << texte << "|||" << endl;

    code.name.name = "";
    code.name.principalName = "";
    /// *** Ce n'est uniquement ici qu'on "switch" sur l' id. ***
    switch(id) {
        case C_Cpp_language : parse_language_Cpp(texte); break;
        case Metil_language : parse_language_Metil(texte); break;
    }
}

std::ostream &operator<<( std::ostream &os, PageComment &c ) {

    int i;
    
    os << "*******************************************************************************************************" << endl;
    os << " nom de la page = " << c.nameWithoutSuffix << endl;
    os << " nom du fichier = " << c.nameFile << endl;
    os << " suffix_source  = " << c.suffix_source << endl;
    os << "*******************************************************************************************************" << endl;
    os << "*******************************************************************************************************" << endl;
    os << " le code de la page " << endl;
    os << "*******************************************************************************************************" << endl;
    os << "*******************************************************************************************************" << endl;
    //for(int i=0;i<c.listComment.size();++i)  os << *c.listComment[i] << endl;
    os << c.code << endl;
    os << "*******************************************************************************************************" << endl;
    os << "*******************************************************************************************************" << endl;
    for(i=0;i<c.listComment.size(); i++ ) {
        cout << *c.listComment[i] << endl;
        os << "*******************************************************************************************************" << endl;
    }

    //c.code.display( os );
    return os;
}

/*
void PageComment::generateHTML() {

 for(int i=0;i<listComment.size();++i)  listComment[i]->generateHTML( name );
}
*/

