#ifndef LMTPP_DISPLAY_GL_H
#define LMTPP_DISPLAY_GL_H

#include "mesh.h"
#include <GL/gl.h>

namespace LMT {

struct Triangle;
struct Quad;

template<class TE>
void display_gl_elem( const TE &elem ) {
    // -> nothing
}

/*!
\keyword Visualisation/3D
*/
template<class TN,class TNG,class TD,unsigned NET>
void display_gl_elem( const Element<Triangle,TN,TNG,TD,NET> &elem ) {
    glBegin( GL_TRIANGLES );
    {
        if ( TNG::dim >= 3 ) {
            typename TNG::Pvec n = sample_normal( elem );
            glNormal3f( n[0], n[1], n[2] );
        }
        glColor3f( elem.node(0)->pos[0], 1.0, 1.0 );
        glVertex3f( elem.node(0)->pos[0], elem.node(0)->pos[1], TNG::dim >= 3 ? elem.node(0)->pos[2] : 0 );
        glColor3f( elem.node(1)->pos[0], 1.0, 1.0 );
        glVertex3f( elem.node(1)->pos[0], elem.node(1)->pos[1], TNG::dim >= 3 ? elem.node(1)->pos[2] : 0 );
        glColor3f( elem.node(1)->pos[0], 1.0, 1.0 );
        glVertex3f( elem.node(2)->pos[0], elem.node(2)->pos[1], TNG::dim >= 3 ? elem.node(2)->pos[2] : 0 );
    }
    glEnd();
}

/*!

\keyword Visualisation/3D
*/
template<class TN,class TNG,class TD,unsigned NET>
void display_gl_elem( const Element<Quad,TN,TNG,TD,NET> &elem ) {
    glBegin( GL_QUADS );
    {
        if ( TNG::dim >= 3 ) {
            typename TNG::Pvec n = sample_normal( elem );
            glNormal3f( n[0], n[1], n[2] );
        }
        typename TNG::Pvec P0 = elem.node(0)->pos;
        typename TNG::Pvec P1 = elem.node(1)->pos;
        typename TNG::Pvec P2 = elem.node(2)->pos;
        typename TNG::Pvec P3 = elem.node(3)->pos;
//         typename TNG::Pvec P4 = 0.25 * ( P0 + P1 + P2 + P3 );
//         P0 = 0.8 * P0 + 0.2 * P4;
//         P1 = 0.8 * P1 + 0.2 * P4;
//         P2 = 0.8 * P2 + 0.2 * P4;
//         P3 = 0.8 * P3 + 0.2 * P4;
        glColor3f( elem.node(0)->pos[0], 1.0, 1.0 );
        glVertex3f( P0[0], P0[1], TNG::dim >= 3 ? P0[2] : 0 );
        glColor3f( elem.node(1)->pos[0], 1.0, 1.0 );
        glVertex3f( P1[0], P1[1], TNG::dim >= 3 ? P1[2] : 0 );
        glColor3f( elem.node(2)->pos[0], 1.0, 1.0 );
        glVertex3f( P2[0], P2[1], TNG::dim >= 3 ? P2[2] : 0 );
        glColor3f( elem.node(3)->pos[0], 1.0, 1.0 );
        glVertex3f( P3[0], P3[1], TNG::dim >= 3 ? P3[2] : 0 );
    }
    glEnd();
}

/*!
\keyword Visualisation/3D
*/
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

/*!
\keyword Visualisation/3D
*/
template<class TM>
void display_gl( const TM &mesh ) {
    LMT_PRIVATE::display_gl( mesh, Number<TM::nvi>() );
}

}


#endif // LMTPP_DISPLAY_GL_H
