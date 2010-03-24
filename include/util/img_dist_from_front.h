#ifndef IMG_DIST_FROM_FRONT_H
#define IMG_DIST_FROM_FRONT_H

namespace LMT {

/*!
    \keyword Traitement_dimages
    
*/
template<class TM>
Mat<double> img_dist_from_front( const TM &mat, int max_dist, double diff_pix ) {
    typedef double T;
    typedef Vec<int,2> P;
    
    int h = mat.nb_rows();
    int w = mat.nb_cols();
    
    // diff_pix = 10;
    
    Mat<T> dist( h, w );
    dist.set( max_dist );
    Vec<P> front;
    for(int x=1;x<w;++x) {
        for(int y=1;y<h;++y) {
            if ( abs( mat(y,x) - mat(y-1,x) ) >= diff_pix or abs( mat(y,x) - mat(y,x-1) ) >= diff_pix or abs( mat(y,x) - mat(y-1,x-1) ) >= diff_pix ) {
                front.push_back( P( y, x ) );
                dist( y, x ) = 0.0;
            }
        }
    }
    
    //
    unsigned of_front = 0;
    while ( of_front < front.size() ) {
        P p = front[ of_front++ ];
        int y = p[0];
        int x = p[1];
        for(int ox=-1;ox<=1;++ox) {
            for(int oy=-1;oy<=1;++oy) {
                if ( ox == 0 and oy == 0 )
                    continue;
                if ( y+oy >= 0 and x+ox >= 0 and x+ox < w and y+oy < h ) {
                    T ndist = dist( y, x ) + sqrt( ox * ox + oy * oy );
                    if ( ndist < dist( y+oy, x+ox ) ) {
                        front.push_back( P( y+oy, x+ox ) );
                        dist( y+oy, x+ox ) = ndist;
                    }
                }
            }
        }
    }
    
    return dist;
}

}

#endif // IMG_DIST_FROM_FRONT_H
