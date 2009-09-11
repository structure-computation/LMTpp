#ifndef LMTPP_DISPLAY_GL_H
#define LMTPP_DISPLAY_GL_H

#include "mesh.h"
#include <GL/gl.h>

namespace LMT {

struct Triangle;

template<class TE>
void display_gl_elem( const TE &elem ) {
    // -> nothing
}

template<class TN,class TNG,class TD,unsigned NET>
void display_gl_elem( const Element<Triangle,TN,TNG,TD,NET> &elem ) {
    glBegin( GL_TRIANGLES );
    {
        glColor3f( 1.0, 1.0, 1.0 );
        if ( TNG::dim >= 3 ) {
            typename TNG::Pvec n = sample_normal( elem );
            glNormal3f( n[0], n[1], n[2] );
        }
        glVertex3f( elem.node(0)->pos[0], elem.node(0)->pos[1], TNG::dim >= 3 ? elem.node(0)->pos[2] : 0 );
        glVertex3f( elem.node(1)->pos[0], elem.node(1)->pos[1], TNG::dim >= 3 ? elem.node(1)->pos[2] : 0 );
        glVertex3f( elem.node(2)->pos[0], elem.node(2)->pos[1], TNG::dim >= 3 ? elem.node(2)->pos[2] : 0 );
    }
    glEnd();
}

///
struct DisplayGL {
    template<class TE> void operator()( const TE &elem ) const { display_gl_elem( elem ); }
};


namespace LMT_PRIVATE {
    template<class TM,unsigned nvi>
    void display_gl( const TM &mesh, Number<nvi> /*nvi*/ ) {
        apply( mesh.elem_list, DisplayGL() );
    }
    
    template<class TM>
    void display_gl( const TM &mesh, Number<3> /*nvi*/ ) {
        display_gl( mesh.skin, Number<2>() /*nvi*/ );
    }
}

///
template<class TM>
void display_gl( const TM &mesh ) {
    LMT_PRIVATE::display_gl( mesh, Number<TM::nvi>() );
}

}


#endif // LMTPP_DISPLAY_GL_H
