#include <correlation/DicCPU.h>
#include <mesh/calculate_measure.h>
#include <containers/gnuplot.h>
#include "pixelotomie.h"

using namespace LMT;

int main( int argc, char **argv ) {
    typedef DicCPU<double,2>::TM_exemple TM;
    typedef TM::Pvec Pvec;


    TM m;
    
    Pvec X0 = Pvec(510 ,124);
    Pvec X1 = Pvec(1200,910);
    
    make_rect( m, Quad(), X0, X1, (X1-X0) / 32 );
    
    ImgInterp<double,2> f( "plateblanche001_0078.png" );
    ImgInterp<double,2> g( "plateblanche001_0079.png" );
    
    DicCPU<double,2> dic;
    dic.div_pixel = 1;
    dic.display_norm_inf_dU = false;
    dic.display_norm_2_dU   = true;
    //dic.relaxation = 0.5;

    dic.min_norm_inf_dU = 1e-1;
    dic.exec_rigid_body( f, g, m, dep_DM(), lum_DM() );
    PRINT( dic.cpt_iter );
    
    dic.min_norm_inf_dU = 1e-2;
    dic.exec           ( f, g, m, dep_DM(), lum_DM() );
    PRINT( dic.cpt_iter );
    
    dic.display_residual_img( f, g, m, dep_DM(), lum_DM() );
    display_mesh( m );
}
