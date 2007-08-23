//
// C++ Interface: gnuplot
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_gnuplot_HEADER
#define LMT_gnuplot_HEADER

#include "containers/mat.h"
#include <sstream>

namespace LMT {

class GnuPlot {
public:
    struct HD {
        HD() {}
        HD(Vec<> x_,Vec<> y_,std::string p_) { params=p_; x = x_; y = y_; }
        std::string params;
        Vec<> x;
        Vec<> y;
    };
    
    GnuPlot() {
        hold = false;
        if ((tube=popen("gnuplot","w"))==NULL) {
            std::cerr << "gnuplot impossible �ouvrir" << std::endl;
            exit(1);
        }
    }
    ~GnuPlot() {
        pclose(tube);
    }
    /// 
    void print(const char *str) {
        fprintf(tube,str);
        fflush(tube);
    }
    /// Pour effacer les courbes d'avant
    void reset() {
        print("reset\n\n");
    }
    /// Wait for a key
    void wait() {
        print("pause -1\n\n");
        std::cin.get();
    }
    struct Disp {
        template<class TX,class TY> void operator()(const TY &val,const TX &x,FILE *tube) const { fprintf(tube,"%10.6f %10.6f\n",(double)x,(double)val); }
        template<class TX,class TY> void operator()(const TX &val,unsigned i,const TY &y,FILE *tube) const { fprintf(tube,"%10.6f %10.6f\n",(double)val,(double)y[i]); }
    };
    /// Dans le cas o une seule variable est fournie. x=num�o. vec=ordonn�
    template<class T,int s,class O>
    void plot(const Vec<T,s,O> &vec,const char *params="") {
        if ( hold ) {
            holded_data.push_back( HD( range(vec.size()), vec, params ) );
        }
        else {
            fprintf(tube,"plot '-' %s\n",params);
            apply_wi( vec, Disp(), tube );
            fprintf(tube,"e\n");
            fflush(tube);
        }
    }
    /// Dans le cas o une seule variable est fournie. x=num�o. vec=ordonn�
    template<class T,class STR,class STO>
    void plot(const Mat<T,STR,STO> &mat,const char *params="") {
        fprintf(tube,"splot '-' matrix %s\n",params);
        std::ostringstream ss; ss << mat;
        fprintf(tube,"%s\ne\n",ss.str().c_str());
        fflush(tube);
    }
    /// Dans le cas o une seule variable est fournie. x=num�o. vec=ordonn�
    template<class T1,int s1,class O1,class T2,int s2,class O2>
    void plot(const Vec<T1,s1,O1> &x,const Vec<T2,s2,O2> &y,const char *params="") {
        if ( hold ) {
            holded_data.push_back( HD( x, y, params ) );
        }
        else {
            fprintf(tube,"plot '-' %s\n",params);
            apply_wi( x, Disp(), y, tube );
            fprintf(tube,"e\n");
            fflush(tube);
        }
    }
    /// Dans le cas o une seule variable est fournie. x=num�o. vec=ordonn�
    template<class T1,int s1,class O1,class T2,int s2,class O2>
    void plot(const Vec<T1,s1,O1> &x,const Vec<T2,s2,O2> &y1,const Vec<T2,s2,O2> &y2,const char *params="") {
        if ( hold ) {
            holded_data.push_back( HD( x, y1, params ) );
            holded_data.push_back( HD( x, y2, params ) );
        }
        else {
            fprintf(tube,"plot '-' %s, '-' %s\n",params,params);
            apply_wi( x, Disp(), y1, tube );
            fprintf(tube,"e\n");
            apply_wi( x, Disp(), y2, tube );
            fprintf(tube,"e\n");
            fflush(tube);
        }
    }
    
    ///
    void hold_on() { hold = true; }
    ///
    void hold_off() {
        if ( holded_data.size()==0 ) return;
        
        fprintf(tube,"plot ");
        for(unsigned i=0;i<holded_data.size();++i) {
            fprintf(tube," '-' %s",holded_data[i].params.c_str());
            fprintf(tube, ( i<holded_data.size()-1 ? "," : "\n" ) );
        }

        for(unsigned i=0;i<holded_data.size();++i) {
            for(unsigned j=0;j<holded_data[i].y.size();++j) {
                fprintf(tube,"%f %f\n", holded_data[i].x[j], holded_data[i].y[j] );
            }
            fprintf(tube,"e\n");
        }
        fflush(tube);
        holded_data.resize( 0 );
    }
    
    ///
    FILE *tube;
    ///
    bool hold;
    ///
    Vec<HD> holded_data;
};
/** plot and wait
*/
template<class T,int s,class O>
void plot(const Vec<T,s,O> &vec,const char *params="") {
    GnuPlot gp;
    gp.plot(vec,params);
    gp.wait();
}

/** plot and wait
*/
template<class T,class STR,class STO>
void plot(const Mat<T,STR,STO> &mat,const char *params="") {
    GnuPlot gp;
    gp.plot(mat,params);
    gp.wait();
}

};

#endif // LMT_gnuplot_HEADER
