#ifndef LIST_TARGET_COMMENT_ITEM_H
#define LIST_TARGET_COMMENT_ITEM_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;

#include "target.h"
#include "token.h"


struct CommentItem ;
struct CommentItemKeyword ;
struct ListParameter;

// template<class COMMENT_ITEM> struct Target_CommentItem {
// 
//     Target* pt ;
//     vector<COMMENT_ITEM*> listCommentItem ;
// } ;

template<class COMMENT_ITEM, class S> struct Target_CommentItem {

    Target* pt ;
    vector<COMMENT_ITEM*> listCommentItem ;
    S* ptr_info ;
} ;

template<class COMMENT_ITEM> struct Target_CommentItem<COMMENT_ITEM,void> {

    Target* pt ;
    vector<COMMENT_ITEM*> listCommentItem ;
} ;


template<class COMMENT_ITEM> struct ListTargetCommentItem {
    ListTargetCommentItem( ) {  }
    ~ListTargetCommentItem() { int i,n = target_items.size() ; for(i=0;i<n;i++) delete target_items[i] ; }
    int size() { return target_items.size() ; }
    Target_CommentItem<COMMENT_ITEM,void>* operator[]( int i ) { return target_items[i] ; }
    void clear() {

        int i,n = target_items.size() ;
        for(i=0;i<n;i++) 
            delete target_items[i] ; 
        target_items.clear() ;
    }
    void display() { 
        int i,n,m,j ;

        n = target_items.size() ; 
        for(i=0;i<n;i++) {
            cout << "++++++++++++++++++++++++++++++++++++++" << endl ;
            cout << *(target_items[i]->pt) << std::endl ;
            cout << "+++++++++ listCommentItem ++++++++++++" << endl ;
            m = target_items[i]->listCommentItem.size() ;
            for(j=0;j<m;j++)
                cout << target_items[i]->listCommentItem[j] << endl ;
        }
    }
    bool contain_generic_comment() {

        int i,n,pos ;
        n = target_items.size() ;
        for(i=0;i<n;i++) {
            if (chercher_motif( target_items[i]->pt->name.name,"generic_comment_",&pos,target_items[i]->pt->name.name.size())) {
                return true ;
            }
        }
        return false ;
    }
    //friend std::ostream &operator<<( std::ostream &os, ListTargetCommentItem& t ) ;


    vector<Target_CommentItem<COMMENT_ITEM,void>* > target_items ;

} ;

template<class COMMENT_ITEM, class S> struct ListTargetCommentItemInfo {
    ListTargetCommentItemInfo( ) {  }
    ~ListTargetCommentItemInfo() { int i,n = target_items.size() ; for(i=0;i<n;i++) delete target_items[i] ; }
    int size() { return target_items.size() ; }
    Target_CommentItem<COMMENT_ITEM,S>* operator[]( int i ) { return target_items[i] ; }
    void clear() {

        int i,n = target_items.size() ;
        for(i=0;i<n;i++) 
            delete target_items[i] ; 
        target_items.clear() ;
    }
    void display() { 
        int i,n,m,j ;

        n = target_items.size() ; 
        for(i=0;i<n;i++) {
            cout << "++++++++++++++++++++++++++++++++++++++" << endl ;
            cout << *(target_items[i]->pt) << std::endl ;
            cout << "+++++++++ listCommentItem ++++++++++++" << endl ;
            m = target_items[i]->listCommentItem.size() ;
            for(j=0;j<m;j++)
                cout << target_items[i]->listCommentItem[j] << endl ;
        }
    }
    bool contain_generic_comment() {

        int i,n,pos ;
        n = target_items.size() ;
        for(i=0;i<n;i++) {
            if (chercher_motif( target_items[i]->pt->name.name,"generic_comment_",&pos,target_items[i]->pt->name.name.size())) {
                return true ;
            }
        }
        return false ;
    }
    //friend std::ostream &operator<<( std::ostream &os, ListTargetCommentItem& t ) ;


    vector<Target_CommentItem<COMMENT_ITEM,S>* > target_items ;

} ;


#endif

