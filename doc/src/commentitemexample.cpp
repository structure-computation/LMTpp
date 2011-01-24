#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

#include "commentitemexample.h"
#include "commentitem.h"
#include "visitorcommentitem.h"

CommentItemExample::CommentItemExample( string& ref  ) {
   name.name = ref;
   name.principalName = ref;
}


void CommentItemExample::display( std::ostream &os ) {

    int i,n;

    n = items.size();
    os << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO" << endl;
    os << "OOOOOOOOOO CommentItemExample : reference =" << name.name << " OOOOOOOOOOO" << endl;
    os << " nombre d'items = " << n << endl;
    for(i=0;i<n;i++) {
        os  << *items[i] << endl;
    }
 os << "fin CommentItemExample" << endl;
}

CommentItemExample::~CommentItemExample() {

    int i,n;

    n = items.size();
    for(i=0;i<n;i++)
        delete items[i];

}
