#ifndef COMMENT_ITEM_LIST_H
#define COMMENT_ITEM_LIST_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

//struct CommentItem ;
#include "commentitem.h"
#include "visitorcommentitem.h"

struct CommentItemList : public CommentItem { 
    CommentItemList() ;
    virtual void print( std::ostream &os ) const { /*os << txt << endl ;*/ }
    virtual void display( std::ostream &os ) ;
    //virtual void apply_on_related_to( const std::string &s, Op *op ) { op->apply( txt ); } ;
    virtual void execute_function( VisitorCommentItem *v ) { v->function_at_CommentItemList( this ) ;  }
    void addCaracteristic( string& s,int nb_space,char c ) ;
    virtual ~CommentItemList() {} ;
    //std::string name ;
    vector<string> txt ;
    vector<int> nb_espace ;
    string type_list ; // à chaque ligne de la liste correspond un élément de ce tableau.
};

#endif



