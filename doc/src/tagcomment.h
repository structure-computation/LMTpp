#ifndef TAG_COMMENT_H
#define TAG_COMMENT_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std ;


#include "comment.h"
//struct Comment ;


struct TagComment {
    TagComment( ) { }
    ~TagComment() { } 

    vector<Comment*> listTag ;
} ;


#endif

