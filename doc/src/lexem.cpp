//
// C++ Implementation: lexem
//
// Description: 
//
//
// Author: Grover <hugo@gronordi>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "lexem.h"
#include "lexemdefinition.h"
#include <fstream>

#include<iostream>
//#include<cstdlib>
#include <string.h>
using namespace std ;


Lexem::Lexem() {
    children[0] = NULL;
    children[1] = NULL;
    parent = NULL;
    next = NULL;
    prev = NULL;
    sibling = NULL;
    def = NULL;
    number = NULL;
}

Lexem::~Lexem() {
}

std::ostream &operator<<( std::ostream &os, Lexem &le ) {
    le.display( os ) ;
    return os ;
}

void Lexem::display_just_name_and_type( std::ostream &os ) const {
    char* buff = new char[si+1];
    memcpy(buff,s,si);
    buff[si] = '\0';
    os << " LEXEM de nom = |" << buff << "|  et de type = " << type ;
    delete buff;
}

void Lexem::display( std::ostream &os, bool withChildren ) const {
    
    display_just_name_and_type(os);
    if (def) {
        os << "** LexemDefinition :"  << endl;
        if (def->tname)
            def->tname->display(os);
        os << "**" << endl;
        if (def->condition) {
            os << "** condition : " << endl;
            def->condition->display(os);
            os << "**" << endl;
        }
        if (def->return_type) {
            os << "** return type :" << endl;
            def->return_type->display(os);
            os << "**" << endl;
        }
        if (def->pertinence) {
            os << "** pertinence : " << endl;
            def->pertinence->display(os);
            os << "**" << endl;
        }
        os << "** nb argumetns = " << def->arguments.size() << endl;
        for(int i=0;i<def->arguments.size();i++) {
            if (def->arguments[i].tname) {
                os << " tname = " << endl;
                def->arguments[i].tname->display(os);
                if (def->arguments[i].tname->sibling) {
                    os << " tname->sibling = " << endl;
                    def->arguments[i].tname->sibling->display(os);
                    os << " fin tname->sibling" << endl;
                }
                os << " fin tname" << endl;
            }
            if (def->arguments[i].default_value) {
                os << " valeur par défaut = " << endl;
                def->arguments[i].default_value->display(os);
                os << " fin valeur par défaut" << endl;
            }
            if (def->arguments[i].type_constraint) {
                os << " contrainte = " << endl;
                def->arguments[i].type_constraint->display(os);
                os << " fin contrainte" << endl;
            }
        }
        os << "** inheritance" << endl;
        for(int i=0;i<def->inheritance.size();i++)
            if (def->inheritance[i])
                def->inheritance[i]->display(os);
//         os << "** parents" << endl;
//         for(int i=0;i<def->parents.size();i++)
//             if (def->parents[i])
//                 def->parents[i]->display(os);
        os << " default_pertinence = " << def->default_pertinence << endl;
        os << " methode  = " << def->method << endl;
        os << " is_class = " << def->is_class << endl;
        os << " self_as_arg = " << def->self_as_arg << endl;
        os << " varargs  = " << def->varargs << endl;
        os << " abstract  = " << def->abstract << endl;
        os << "********* fin def" << endl;
    }
    if ( withChildren ) {
        os << "~~ début des children"  << endl;
        if (children[0]) {
            os << "children[0]" << endl;
            children[0]->display(os);
        }
        if (children[1]) {
            os << "children[1]" << endl;
            children[1]->display(os);
        }
        os << "~~ fin des children"  << endl;
    }
    if (next) {
        os << "++ next" << endl;
        next->display_just_name_and_type(os);
        os << "++ fin next" << endl;
    }
    if (prev) {
        os << "++ prev" << endl;
        prev->display_just_name_and_type(os);
        os << "++ fin prev" << endl;
    }
}


const Lexem *leftmost_child(const Lexem *t) {
    if ( t->type==Lexem::APPLY or t->type==Lexem::SELECT or t->type==Lexem::CHANGE_BEHAVIOR )
        return leftmost_child( t->children[0] ); // a(15)
    if ( t->type > 0 )
        if ( ( t->num & 1 )/*need_left_arg*/ or ( ( t->num & 4 )/*MayNeedlarg*/ and t->children[0] ) )
            return leftmost_child( t->children[0] ); // a', a-b
    //     if ( t->type==Lexem::PAREN or t->children[0]==NULL or t->children[1]==NULL )
    return t;
    //     return leftmost_child( t->children[0] );
}

const Lexem *rightmost_child(const Lexem *t) {
    while ( t->next )
        t = t->next;
    
    if ( t->type==Lexem::PAREN or t->type==Lexem::APPLY or t->type==Lexem::SELECT or t->type==Lexem::CHANGE_BEHAVIOR )
        return t;
    
    if ( t->children[1] )
        return rightmost_child( t->children[1] );
    if ( t->children[0] and not ( t->type > 0 and (t->num & 1/*need_left_arg*/) ) ) // operators with 1 child are in left of there operand
        return rightmost_child( t->children[0] );
    return t;
}


void display_graph_rec( std::ostream &os, const Lexem *t, unsigned level, unsigned &max_level ) {
    unsigned j;
    max_level = std::max( max_level, level );
    const Lexem *old_t = t;
    // nodes
    for(;t;t=t->next) {
        os << "{ rank = same; " << level << " node" << t << " [label=\"";
        for(unsigned i=0;i<t->si;++i) {
            if ( t->s[i]=='\n' )
                os << "\\n";
            else if ( t->s[i]=='"' )
                os << "\\\"";
            else
                os << t->s[i];
        }
        os << '(' << t->type << ')' << "\"] }\n";
        
        // children
        for(j=0;j<2;++j) {
            if ( t->children[j] ) {
                display_graph_rec( os, t->children[j], level+1, max_level );
                os << "  node" << t << " -> node" << t->children[j] << ";\n";
            }
        }
        // ascending edge
        if ( t->parent )
            os << "  node" << t << " -> node" << t->parent << " [color=red];\n";
    }
    // edges
    t = old_t;
    for(;t;t=t->next) {
        if ( t->next )
            os << "  node" << t << " -> node" << t->next << " [color=green];\n";
        if ( t->prev ) //
            os << "  node" << t << " -> node" << t->prev << " [color=yellow];\n";
    }
}

void display_graph(const Lexem *t,const char *file_name) {
    std::ofstream f(file_name);
    f << "digraph popoterie {";
    unsigned max_level = 1;
    display_graph_rec( f, t, 1, max_level );

    for(unsigned i=1;i<=max_level;++i)
        f << "  " << i << " [ shape=plaintext ];\n  ";
    for(unsigned i=1;i<=max_level;++i)
        f << i << ( i<max_level ? " -> " : ";" );
    
    f << "}";
    f.close();
    
    system( ("dot -Tps "+std::string(file_name)+" > "+std::string(file_name)+".eps && gv "+std::string(file_name)+".eps").c_str() );
}

char* first_next_doc_of( const Lexem *l) {
    char* b;
    
    for( b = (char*) l->s; *b and *b!='\n'; b++ ) 
        if ( *b=='#' )
            return b + 1;
    //cout << "first_next_doc_of() :: *b == |" << *(b-2) << *(b-1) <<*b << *(b+1) << *(b+2) << "|" << endl;
    return NULL;
}

char* first_previous_doc_of( const Lexem *l) {

    const char blanc[4] = " \t\n";
    char* b;

    for( b = (char*) (l->s-1); *b ; b-- )
        if (not(strchr(blanc,*b)))
            break;
    if (*b=='#')
        return b-1;
    //cout << "first_previous_doc_of() :: *b == |" << *(b-2) << *(b-1) <<*b << *(b+1) << *(b+2) << "|" << endl;
    return NULL;
}

void append_previous_comment(char* start, std::deque<Comment_zone>& list_comment) {

    const char blanc[4] = " \t\n";
    Comment_zone comment_zone;
    char* b;
    char* c;

    if (not(*start))
        return;

    if ((*start == '#') or (*start == '~')) {
        /// commentaire sur plusieurs lignes
        b = start-1;
        while(*b) {
            /// l'unique raison de la boucle while est la précense éventuelle des caracères ~ et # dans un commentaire sur plusieurs lignes
            for( ; *b ; --b )
                if ((*b=='~') or (*b == '#'))
                    break;
            if (*b) {
                if (*(b-1) == '#') {
                    comment_zone.start = b+1;
                    comment_zone.size  = start-b-1;
                    list_comment.push_front(comment_zone);
                    return;
                } else {
                    b--;
                    continue;
                }
            }
        }
        if (not(*b))
            std::cerr << "warning : bad syntax comment" << std::endl;
    }
}

/// hypothèse : start pointe sur le début d'un commentaire et *(start-1) == #
void append_next_comment(char* start, std::deque<Comment_zone>& list_comment) {

    const char blanc[4] = " \t\n";
    Comment_zone comment_zone;
    char *b;

    if (not(*start))
        return;

    if ((*start == '#') or (*start == '~')) {
        /// commentaire sur plusieurs lignes
        b = start + 1;
        while(*b) {
                /// l'unique raison de la boucle while est la précense éventuelle des caracères ~ et # dans un commentaire sur plusieurs lignes
            for( ; *b ; ++b )
                if ((*b=='~') or (*b == '#'))
                    break;
            if (*b) {
                if (*(b+1) == '#') {
                    comment_zone.start = start;
                    comment_zone.size  = b-start;
                    list_comment.push_back(comment_zone);
                    return;
                } else {
                    b++;
                    continue;
                }
            }
            if (not(*b))
                std::cerr << "warning : bad syntax comment" << std::endl;
        }
    } else {
        /// commentaire sur une seule ligne
        for( b = start ; *b; ++b ) 
            if (*b=='\n')
                break;
        comment_zone.start = start;
        comment_zone.size  = b-start;
        list_comment.push_back(comment_zone);
        /// on recherche un autre commentaire à la suite
        for( b++ ; *b; ++b )
            if (not(strchr(blanc,*b)))
                break;
        if (*b=='#')
            append_next_comment(b+1,list_comment);
    }
}

void doc_of( const Lexem *l, std::deque<Comment_zone>& list_comment ) {

    char* start;

    list_comment.clear();
    /// recherche de commentaires avant le lexem
    if (start = first_previous_doc_of(l)) 
        append_previous_comment(start,list_comment);
    /// recherche de commentaires après le lexem
    if (start = first_next_doc_of(l)) 
        append_next_comment(start,list_comment);
}


/// old version
int offset_to_doc_of( const Lexem *l, const char *sar_txt ) {
    // look at the end of the line
    for( const char *b = l->s; *b and *b!='\n'; ++b ) 
        if ( *b=='#' )
            return b - sar_txt;
    // else, go to the beginning of the previous ones while there are #s
    //     const char *b = l->s;
    //     bool double_comment = false;
    //     for( ; *b and *b!='\n'; --b )
    //         if ( *b=='#' )
    //             double_comment = true;
    //     for( bool cont; cont; ) {
    //         cont = false;
    //         for( ; *b and *b!='\n'; --b )
    //             cont |= ( *b == '#' );
    //     }
    
    return -1;
}
