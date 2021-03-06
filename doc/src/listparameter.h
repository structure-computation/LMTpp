#ifndef LIST_PARAMETER_H
#define LIST_PARAMETER_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

#include "names.h"
#include "parameter.h"
//struct Parameter;
struct ListTarget;
struct Target;

struct ListParameter {
    ListParameter( ) { }
    ~ListParameter();
    int size() { return list.size(); }
    void clear();
    void push_back( Parameter& pp ) { list.push_back(pp); } // ajoute un paramètre à la liste.
    Parameter operator[] (const int i) { return list[i];}
    void display_parameter_to_HTML(ofstream* f, ListTarget* ptr_list_target, Target* pt);  // pour les signatures de fonctions
    friend std::ostream &operator<<( std::ostream &os, ListParameter& t );

    //private:
    vector<Parameter> list;
};


#endif

