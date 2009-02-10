#ifndef TARGET_H
#define TARGET_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

//struct Names ;
#include "names.h"

#define INIT -1
#define NOT_ID -2

// l'attribut id sert

struct Target {
    Target( ) { id = INIT ; suffix_reference = "html" ; ancestor = NULL ;}
    ~Target() { } 
    virtual string completName() { }
    virtual string reference() ;
    virtual bool of_function() { return false; }
    virtual bool of_class_or_struct() { return false; }
    virtual bool of_class() { return false; }
    virtual bool of_struct() { return false; }
    virtual bool of_example() { return false; }
    virtual bool of_tutorial() { return false; }
    virtual bool of_generic_comment() { return false; }
    virtual bool of_type_without_generic_comment() { return false; }
    friend std::ostream &operator<<( std::ostream &os, Target& t ) ;
    friend bool inferior( Target* t1, Target* t2 ) ;
    bool operator== ( const Target& t1 ) ;
    bool operator< ( const Target& t1 ) ;
    void setSuffix( const string su ) {suffix_reference = su ; }
    void initTarget() { id = INIT ; suffix_reference = "html" ; } 

    Names name ;
    string source_file ;
    string path ;
    string suffix_reference ;// suffix du fichier de référence
    // Pour un generic_comment , ancestor est un pointeur sur un objet dont le type est celui concerné par generic_comment.
    Target* ancestor ;
    // l'attribut id sert à diférencier les pages web d'objet différents mais ayant le même nom (e.g. les fonctions template)
    int id ;
    // certains à distinguer certains target par une propriété quelconque
    // *  = 0 signifie qu'elle ne la vérifie pas
    // *  != 0 signifie qu'elle vérifie la propriété
    int property;
} ;

bool inferior( Target* t1, Target* t2 ) ;

#endif

