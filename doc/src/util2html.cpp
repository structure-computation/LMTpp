
#include "time.h"

#include "util2html.h"
#include "token.h"
#include "target.h"
#include "listtarget.h"


void generate_header( Target* src, string& path_root, ofstream& of,string &titre)
{
    string stmp,ssrc ;
    int start, end,pos,pos2,nb,i ;

    // <?xml version="1.0" encoding="UTF-8" ?>
    // <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
    // <html xmlns="http://www.w3.org/1999/xhtml">

    //of<<"<?xml version=\"1.0\" encoding=\"iso-8859-1\"?>"<<std::endl;
    //of<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"<<std::endl;
    of<<"<!DOCTYPE html"<<std::endl;
    of<<"   PUBLIC \"-//W3C//DTDXHTML 1.0 Strict//EN\" \"DTD/xhtml1-strict.dtd\">"<<std::endl;
    of<<"<html xmlns=\"http://www.w3.org/1999/xhtml\" xml:lang=\"fr\" lang=\"fr\">"<<std::endl;
    of<<"<head>"<<std::endl;

    of<<" <META HTTP-EQUIV=\"CONTENT-TYPE\" CONTENT=\"text/html; charset=utf-8\">"<<std::endl;

    start = 0 ;
    ssrc = src->reference() ;
    if (ssrc.size() > path_root.size()) 
        end = path_root.size() ;
    else
        end = ssrc.size() ;

    while (start<end) {
        if (chercher_motif( ssrc,"/",&pos,end,start ) && chercher_motif( path_root,"/",&pos2,end,start )) {
            if ((start == pos) || (start == pos2)) {
                start++ ;
            } else {
                if ((pos != pos2) || (!equal(ssrc,path_root,pos,start)))
                   break ;
                start = pos + 1 ;
            }
        } else
            break ;
    }
    // start pointe sur le premier caractère du premier répertoire différent.
    nb = compter_caractere( ssrc,'/',start ) ;
    for(i=0;i<nb;i++)
        stmp += "../" ;
    stmp += "classic.css" ;

    of<<"<link href=\"" << stmp << "\" rel=\"stylesheet\" type=\"text/css\" />"<<std::endl;
    of<<"<title> Documentation (Officielle) de la librairie LMT++ </title>"<<std::endl;
    of<<"</head>"<<std::endl;
    of<<"<body text=\"#000000\" bgcolor=\"#ffffff\" link=\"#0000cc\" vlink=\"#551a8b\" >"<<std::endl;

    /*
    REMARQUE : je ne parcours pas la liste des pages web pour générer cet en-tête.
    J'utilise les noms des pages web créées dans la fonction :
    void Documentation :: generate_webpage_generic_object_and_summary()
    */
    of << "<ul class=\"navigation\" >" << std::endl;
    stmp = path_root + "index.html" ;
    of << "<li> " << linkHTML(src->reference(),stmp,"Accueil") << "</li>" << std::endl;
//     stmp = path_root + "list_touteslesclasses.html" ;
//     of << "<li> " << linkHTML(src->reference(),stmp,"Toutes les classes") << "</li>" << std::endl;
//     stmp = path_root + "list_touteslesfonctions.html" ;
//     of << "<li> " << linkHTML(src->reference(),stmp,"Toutes les fonctions") << "</li>"<<std::endl;
    stmp = path_root + "list_touslesmot-cles.html" ;
    of << "<li> " << linkHTML(src->reference(),stmp,"Tous les MOT-CL&Eacute;S") <<" </li>"<<std::endl;
    stmp = path_root + "list_touslesexemples.html" ;
    of << "<li> " << linkHTML(src->reference(),stmp,"Tous les exemples") << " </li>"<<std::endl;
    stmp = path_root + "list_touslestutoriels.html" ;
    of << "<li> " << linkHTML(src->reference(),stmp,"Tous les tutoriels") <<" </li>"<<std::endl;
    stmp = path_root + "list_lesclassesprincipales.html" ;
    of << "<li> " << linkHTML(src->reference(),stmp,"Les classes principales") <<" </li>"<<std::endl;
    stmp = path_root + "list_lesfonctionsprincipales.html" ;
    of << "<li> " << linkHTML(src->reference(),stmp,"Les fonctions principales") <<" </li>"<<std::endl;
    of << "</ul>" <<std::endl;

 of<<std::endl;

 of<<"<h1 align=\"center\">"<< titre <<"</h1>"<<std::endl;
 of<<std::endl;
}

string french2webID( const string& s) {

    string t ;
    int n = s.length(), i ;
    char c ;


    for(i=0;i<n;i++) {
        c = s[i] ;
        if ((c == ' ') || (c == '<') || (c == '>') )
            continue ;
        if (c == '/') {
            t+= "slash" ;
            continue ;
        }
        if((short)s[i] != -61) t  += tolower(s[i]) ;
                else {  // premier octet utf8
                switch((short) s[i+1]){
                        case -87 : t += "e" ; break ; // coresspond à la lettre é
                        case -96 : t += "a" ; break ; // coresspond à la lettre à
                        case -88 : t += "e" ; break ; // coresspond à la lettre è
                        case -86 : t += "e" ; break ; // coresspond à la lettre ê
                        case -89 : t += "c" ; break ; // coresspond à la lettre ç /// il manque le ù
                        default: t += "INCONNU" ;
                        }
                 i++ ; // pour sauter le deuxième octet
                }
    }
    return t ;
}

string french2HTML( const string& s) {

    string t,tmp ;
    int n = s.length(), i,j,pos ;
    char c ;


    for(i=0;i<n;i++) {
        c = s[i] ;
        //if (c == '<') {
        //    t += "&lt;" ;
        //    continue ;
        //}
        if (c == '<') {
            for (j= i+1;j<n;j++)
                if (s[j] == '>') 
                    break ;
            if (chercher_motif(s,"strong",&pos,j,i+1)) {   
                #warning PROVISOIRE <strong>
                t += s.substr(i,j-i+1) ;
                i = j + 1 ;
            } else {
                if (chercher_motif(s,"/strong",&pos,j,i+1)) {
                    t += s.substr(i,j-i+2) ;
                    i = j + 2 ;
                } else 
                    t += "&lt;" ;
            }
            continue ;
        }
        if (c == '>') {
            t += "&gt;" ;
            continue ;
        }
        if((short)s[i] != -61) t  += s[i] ;
            else {  // premier octet utf8
                switch((short) s[i+1]){
                        case -87 : t += "&eacute;" ; break ; // coresspond à la lettre é
                        case -96 : t += "&agrave;" ; break ; // coresspond à la lettre à
                        case -88 : t += "&egrave;" ; break ; // coresspond à la lettre è
                        case -86 : t += "&ecirc;" ; break ; // coresspond à la lettre ê
                        case -89 : t += "&ccedil;" ; break ; // coresspond à la lettre ç
                        case -71 : t += "&ugrave;" ; break ; // coresspond à la lettre ù
                        case -81 : t += "&iuml;" ; break ; // ï
                        case -85 : t += "&euml;" ; break ; // ë
                        case -82 : t += "&icirc;" ; break ; // î
                        case -94 : t += "&acirc;" ; break ; // â
                        case -76 : t += "&ocirc;" ; break ; // ô
                        case -69 : t += "&ucirc;" ; break ; // û
                        default: ;
                        }
                 i++ ; // pour sauter le deuxième octet
            }
    }
    return t ;
}


/* cette fonction retourne le chemin de la cible sous la forme d'un lien html <a href="blabla.html"> name </a>
en fonction de l'emplacement de la source et du nom...
*/
string linkHTML( const string& href_src,const string& href_target , const string& name ) {

    string stmp ;
    int start, end,pos,pos2,nb,i ;

    if (href_src.size() > href_target.size()) 
        end = href_target.size() ;
    else
        end = href_src.size() ;
    start = 0 ;

    //cerr << "DEBUG href_src    |" << href_src << "|" << endl;
    //cerr << "DEBUG href_target |" << href_target << "|" << endl;
    
    while (start<end) {
        if (chercher_motif( href_src,"/",&pos,end,start ) && chercher_motif( href_target,"/",&pos2,end,start )) {
            if ((start == pos) || (start == pos2)) {
                start++ ;
            } else {
                if ((pos != pos2) || (!equal(href_src,href_target,pos,start)))
                   break ;
                start = pos + 1 ;
            }
        } else
            break ;
    }
    /// start pointe sur le premier caractère du premier répertoire différent.
    nb = compter_caractere( href_src,'/',start ) ;
    //cerr << " nb = " << nb << endl;
    for(i=0;i<nb;i++)
        stmp += "../" ;
    stmp += href_target.substr(start, href_target.size()-start) ;
    return "<a href=\"" + stmp + "\" >" + french2HTML( name )   + "</a>" ;
}

string linkImage( const string& href_src, const string& href_target , const string& texte ) {

    string stmp ;
    int start, end,pos,pos2,nb,i ;

    if (href_src.size() > href_target.size()) 
        end = href_target.size() ;
    else
        end = href_src.size() ;
    start = 0 ;

    while (start<end) {
        if (chercher_motif( href_src,"/",&pos,end,start ) && chercher_motif( href_target,"/",&pos2,end,start )) {
            if ((start == pos) || (start == pos2)) {
                start++ ;
            } else {
                if ((pos != pos2) || (!equal(href_src,href_target,pos,start)))
                   break ;
                start = pos + 1 ;
            }
        } else
            break ;
    }
    // start pointe sur le premier caractère du premier répertoire différent.
    nb = compter_caractere( href_src,'/',start ) ;
    for(i=0;i<nb;i++)
        stmp += "../" ;
    stmp += href_target.substr(start, href_target.size()-start) ;
    return "<img alt=\""+ texte + "\" src=\"" + stmp + "\" />" ;
}

string link_fragmentHTML( const string& s ) {

    return "<a href=\"#" + french2webID( s ) + "\" > " + s  + " </a> " ;
}

string ancreHTML( const string& s,bool display ) {

    if (display)
        return "<a name=\"" + french2webID( s ) + "\" id=\"" + french2webID( s ) + "\" > " + french2HTML( s  ) + "</a> " ;
    else 
        return "<a name=\"" + french2webID( s ) + "\" id=\"" + french2webID( s ) + "\" > </a> " ;
}

bool isURL(string& res, string& s,int end,int start) {
    int pos ;
    if ( chercher_motif( s, "http:", &pos, end, start ) ) {
        //if ( pos < start + 3 ) {
        if ( pos == start ) {
            //res = s.substr(start,end-start) ;
            res = s.substr( pos, end - pos );
            return true;
        }
    }
    if (chercher_motif(s,"https:",&pos,end,start)) {
        //if (pos < start + 3 ) {
        if ( pos == start ) {
            //res = s.substr(start,end-start);
            res = s.substr( pos, end - pos );
            return true;
        }
    }
    if (chercher_motif(s,"ftp.",&pos,end,start)) {
        //if (pos < start + 3 ) {
        if ( pos == start ) {
            //res = s.substr(start,end-start);
            res = s.substr( pos, end - pos );
            return true;
        }
    }
    if (chercher_motif(s,"www.",&pos,end,start)) {
        //if ( pos < start + 3 ) {
        if ( pos == start ) {
            //res = "http://" + s.substr(start,end-start) ;
            res = "http://" + s.substr( pos, end - pos );
            return true;
        }
    }
    if (chercher_motif(s,"#",&pos,end,start)) {
        //if (pos < start + 3 ) {
        if ( pos == start ) {
            res = s.substr( pos, end - pos ) ;
            return true;
        }
    }
    return false ;
}


string text2HTML(string& s,Target* ptr_parent, ListTarget* ptr_lt ) {

    int end,start,suite,pos,suite2,pos2 ;
    string stmp,stmp2 ;
    string html ;
    char c;
    Target* ptr_t ;

//     cerr << " ptr_parent = " << ptr_parent << endl ;
//     cerr << " ptr_lt = " << ptr_lt << endl ;

    //stmp = french2HTML( s ) ; // on a réglé le problème des é, ç, è, etc...
    //cerr << " anti slash a = " << (int) '\a' << endl ; 
    start = 0 ;
    end = s.size() ;
//     cerr << " s = " ;
//     for(int i=0;i<end;i++)
//         cerr << "|" << (int) s[i] ;
//     cerr << "|" << endl ;
    //cerr << " s = |" << s << "|  end =" << end << endl ;
    //cerr << " anti slash a = " << (int) '\a' << endl ; 
    /// parcours de s en lexems séparer par des blancs ou des espaces
    while((pos = extraire_token(&suite,&c," \t\n",s,end,start)) >= 0) {
        stmp = s.substr(pos,suite-pos) ;
        //cerr << "|" << stmp << "|" << endl ;
//         cerr << " stmp = " ;
//         for(int i=0;i<stmp.size();i++)
//             cerr << "|" << (int) stmp[i] ;
//         cerr << "|" << endl ;
        if (isURL(stmp2,s,suite,pos)) {
            html += linkHTML("",stmp2,stmp2) ;
            html.push_back(c) ;
            start = suite + 1 ;
            continue;
        }
        /// le lexem n'est pas une url donc soit c'est un mot, soit un mot-clé \anchor ou \a
        /// cf la page comment.cpp pour connaître tous les mots-clés.
        /// soit un lien wiki
        if (stmp == "\\a") {
            //cerr << "::|" << stmp << "|" << endl ;
            if ((pos = extraire_token(&suite,&c," \t\n[]",s,end,suite+1)) >= 0) {
                /// les différents cas possibles :
                /// * \a url
                /// * \a Mesh
                /// * \a [titre de la page]
                /// * \a [url] Texte de la balise
                /// * \a [href=url,type=val] Mesh  /// PAS FAIT
                /// * \a [type=val,href=url] Mesh  /// PAS FAIT
                stmp = s.substr(pos,suite-pos) ;
                //cerr << "<<|" << stmp << "|" << endl ;
                if (isURL(stmp2,s,suite,pos)) {
                    html += linkHTML("",stmp2,stmp2) ;
                    html.push_back(c) ;
                } else {
                    if (s[pos] == '[') {
                        get_block(&suite,"[]",s,end,pos+1); // +1 pour dépasser le [
                        if (isURL(stmp2,s,suite-1,pos+1)) {
                                html += linkHTML("",stmp2,stmp2) ;
                                html.push_back(' ') ;
                        } else {
                            /// soit c'est un titre , soit c'est une suite de id=val.
                            stmp = s.substr(pos+1,suite-pos-2);
                            cut_space( stmp ) ;
                            /// * un titre
                            //cerr << "<<||" << stmp << "||>>" << endl ;
                            ptr_t = ptr_lt->isName( stmp ) ;
                            if (ptr_t != NULL) {
                                html += linkHTML( ptr_parent->reference(), ptr_t->reference(), stmp ) ;
                                html.push_back(' ') ;
                            } else {
                                // * une suite de id=val
                                /// à faire...
                            }
                        }


                    } else {
                        /// c'est probablement un nom de fonction ou de classe.
                        ptr_t = ptr_lt->isName( stmp ) ;
                        if (ptr_t != NULL) {
                            html += linkHTML( ptr_parent->reference(), ptr_t->reference(), stmp ) ;
                            html.push_back(c) ;
                        }
                    }
                }
            }
            start = suite + 1 ;
            continue;
        }
        if (stmp == "\\anchor") {
            if ((pos = extraire_token(&suite,&c," \t\n",s,end,suite+1)) >= 0) {
                stmp = s.substr(pos,suite-pos) ;
                html += ancreHTML(stmp) ;
                html.push_back(c) ;
            }
            start = suite + 1 ;
            continue;
        }
        if ( (pos2 = stmp.find("[[")) == 0) {
            /// syntaxe wiki possible :
            /// * [[url]]   où url est de la forme : chemin/cible  avec chemin relatif ou absolue
            /// * [[url|étiquette]]
            /// * [[Mesh]]
            if ((suite2 = s.find("]]",pos+2)) != string::npos) {
                //cerr << "------ stmp = |" << stmp << "|  et pos2 = " << stmp.find('|') << endl; /// problème avec find...
                start = pos + 2;// on se met juste après les [[
                stmp = s.substr( start, suite2 - start );
                //cerr << "------ stmp = |" << stmp << "|" << endl;
                if ((pos2 = stmp.find('|')) == string::npos) {
                    if (isURL(stmp2,s,suite2,start)) {
                        html += linkHTML("",stmp2,stmp2) + " " ;
                        start = suite2 + 2 ;
                        continue;
                    } else {
                        stmp = s.substr(start,suite2-start);
                        /// c'est probablement un nom de fonction ou de classe.
                        ptr_t = ptr_lt->isName( stmp ) ;
                        if (ptr_t != NULL) {
                            html += linkHTML( ptr_parent->reference(), ptr_t->reference(), stmp ) + " ";
                        } else {
                            /// on traite le cas d'un fichier
                            html += linkHTML( ptr_parent->reference(), stmp, stmp ) + " ";
                        }
                        start = suite2 + 2 ;
                        continue;
                    }
                } else {
                    /// il y a un symbole |
                    stmp = s.substr( start + pos2 + 1, suite2 - pos2 - start - 1 );
                    if (isURL( stmp2, s, start+pos2, start ) ) {
                        html += linkHTML( "", stmp2, stmp ) + " ";
                        start = suite2 + 2 ;
                        continue;
                    } else {
                        /// c'est probablement un nom de fonction ou de classe.
                        stmp2 = s.substr( start, pos2 ); // stmp2 contient le A de [[A|B]]
                        ptr_t = ptr_lt->isName( stmp2 ) ;
                        if (ptr_t != NULL) {
                            if (stmp.size()==0)
                                html += linkHTML( ptr_parent->reference(), ptr_t->reference(), stmp2 ) + " ";
                            else 
                                html += linkHTML( ptr_parent->reference(), ptr_t->reference(), stmp ) + " ";
                        } else {
                            /// on traite le cas d'un fichier
                            if (stmp.size()==0)
                                html += linkHTML( ptr_parent->reference(), stmp2, stmp2 ) + " ";
                            else
                                html += linkHTML( ptr_parent->reference(), stmp2, stmp ) + " ";
                        }
                        start = suite2 + 2 ;
                        continue;
                    }
                }
            }
        }

        /// c'est un mot normal.
        html += french2HTML(stmp) ;
        html.push_back(c) ;
        start = suite + 1 ;
    }
    return html ;
}

void feetPage(ofstream& pageWeb, bool withDate ) {

    int NB_FINAL_LINE = 7,j;
    time_t rawtime;
    struct tm * timeinfo;

    pageWeb << "<hr />" << std::endl ;
    if (withDate) {
        time( &rawtime );
        timeinfo = localtime( &rawtime );
        pageWeb << asctime (timeinfo);
    }
    for(j=0;j<NB_FINAL_LINE;j++)
        pageWeb << "<br>" << std::endl ;
    pageWeb << "</body>" << std::endl ;
    pageWeb << "</html>" << std::endl ;
    pageWeb << std::endl;
}

/*
unsigned hash_p ( const string& s ) {

    int i,n ;
    unsigned a,t,r ;

    n = s.size()-1 ;
    if (n<0) return 0 ;

    r = 26 * 26 * 26 ;
    a = s[n] ;
    a %= r ;
    for(i=n-1;i>=0;i--) {
        t = (a*256) % r ;
        a = s[i] ;
        a = (t + a) % r ; 
    }
    return a ;
}

// calcul le hash pour les caractère de l'intervalle semi-ouvert [start ; end [
unsigned hash_p ( const string& s,int end, int start ) {

    int i ;
    unsigned a,t ;
    //unsigned r ;

    if (end<=start) return 0 ;

    //r = 26 * 26 * 26 ;
    a = s[0] ;
    //a %= r ;
    for(i=1;i<end;i++) {
        t = a*256 ; //t = (a*256) % r ;
        a = s[i] ;
        a = t + a ; //a = (t + a) % r ; 
    }
    return a ;
}

string hash2string( unsigned h) {

    string rep ;
    int i ;
    char c ;
    
    for(i=0;i<8;i++) {
        c = 'a' + + (h % 26) ;
        rep.push_back( c ) ;
        h /= 26 ;
    }
    return rep ;
 }
*/











