#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

#include "commentitemlatex.h"
#include "commentitem.h"
#include "visitorcommentitem.h"
#include "token.h"

CommentItemLaTex::CommentItemLaTex( string& option ) {

    name.name = "image_latex_";
    name.principalName = "image_LaTex";
    suffix_reference = "tex";
    multipage = option;
    cout << "CommentItemLaTex::multipage = |" << option << "|--" << endl;
}

void CommentItemLaTex::addTxt(string& s,int end,int start ) {

    txt += s.substr( start, end - start );
    //cerr << " txt = |" << txt << "| somme = " << somme(txt) << endl;
    name.name += somme( txt );
}

void CommentItemLaTex::addTxt(const char* s,int size ) {

    txt.append(s,size);
    name.name += somme( txt );
}

void CommentItemLaTex::display( std::ostream &os ) {

    os << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
    os << "OOOOOOOOOO CommentItemLaTex : reference =" << name.name << " OOOOOOOOOOO" << endl;
    os << " txt = |" << txt << "|" <<endl;
    os << "fin CommentItemLaTex" << endl;
}

CommentItemLaTex::~CommentItemLaTex() { }
