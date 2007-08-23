#ifndef IMG_H
#define IMG_H

#include <Magick++.h>

namespace LMT {

template<class T> struct Magick_TypePixel {};
template<> struct Magick_TypePixel<float> { static const MagickLib::StorageType res = Magick::FloatPixel; };

template<unsigned dim,class T=float>
struct Img {
    Img(const char *filename) {
        data = NULL;
        load( filename );
    }
    
    void load(const char *filename) {
        if ( data )
            free( data );
        
        Magick::Image image;
        try {
            image.read( filename );
        } catch ( const Magick::WarningCoder &e ) { std::cerr << e.what() << std::endl; }
    
        Magick::Geometry geometry = image.boundingBox();
        size[0] = geometry.width();
        size[1] = geometry.height();
        
        data = (float *)memalign( 16, sizeof(T)*size[0]*size[1] );
        for(unsigned i=0;i<size[0]*size[1];++i)
            data[i] = 0.0;
        
        image.write( 0, 0, size[0], size[1], "R", Magick_TypePixel<float>::res, (void *)data );
    }
    
    ~Img() {
        free(data);
    }
    
    float *data;
    Vec<int,dim> size;
};

}

#endif // IMG_H
