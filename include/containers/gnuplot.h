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

#include "mat.h"
#include <sstream>

namespace LMT {

/*!
    classe servant d'interface avec le celebre programme gnuplot.
    \author Hugo Leclerc
    \author Camille Gouttebroze
    \friend hugo.leclerc@lmt.ens-cachan.fr
    \friend camille.gouttebroze@lmt.ens-cachan.fr
    \keyword Graphisme/2D
*/
class GnuPlot {
public:

    struct HD {

        HD() {}

        HD( Vec<> x_, std::string p_ ) { params=p_; x = x_;}

        template <class OPY>
        HD( Vec<> x_, OPY y_, std::string p_ ) {
            params=p_;
            x = x_;
            y.resize(x.size());
            for (int i=0;i<y.size();i++)
                y[i] = y_(x[i]);
        }

        HD( Vec<> x_, Vec<> y_, std::string p_ ) { params=p_; x = x_; y = y_; }

        template <class OPZ>
        HD( Vec<> x_, Vec<> y_, OPZ z_, std::string p_ ) {
            params=p_;
            x = x_;
            y = y_;
            z.resize(x.size());
            for (int i=0;i<z.size();i++)
                z[i] = z_(x[i],y[i]);
        }

        HD( Vec<> x_, Vec<> y_, Vec<> z_, std::string p_ ) { params=p_; x = x_; y = y_; z = z_; }

        std::string params;
        Vec<> x,y,z;

    };

    GnuPlot() {
        hold = false;
        if ((tube=popen("gnuplot","w"))==NULL) {
            std::cerr << "gnuplot impossible a ouvrir" << std::endl;
            exit(1);
        }
    }

    ~GnuPlot() {
        pclose(tube);
    }

    void print(const char *str = "") const {
        fprintf(tube,"%s",str);
        fflush(tube);
    }

    void set(const char *str = "") const { std::stringstream s; s << "set " << str << "\n"; print( s.str().c_str() ); } 
    void set_title(const char *str = "") const { std::stringstream s; s << "set title " << str << "\n"; print( s.str().c_str() ); } 
    void set_xlabel(const char *str = "") const { std::stringstream s; s << "set xlabel " << str << "\n"; print( s.str().c_str() ); } 
    void set_ylabel(const char *str = "") const { std::stringstream s; s << "set ylabel " << str << "\n"; print( s.str().c_str() ); } 
    void set_terminal(const char *str = "") const { std::stringstream s; s << "set_terminal " << str << "\n"; print( s.str().c_str() ); } 
    void set_terminal_epslatex(const char *str = "") const { std::stringstream s; s << "set_terminal_epslatex " << str << "\n"; print( s.str().c_str() ); } 
    void set_output(const char *str = "") const { std::stringstream s; s << "set_output " << str << "\n"; print( s.str().c_str() ); } 

    /// Pour effacer les courbes d'avant
    void reset() { print("reset\n\n"); }

    /// Attendre une touche
    void wait() {
        print("pause -1\n\n");
        std::cin.get();
    }

    struct Disp {
        template<class TX>
        void operator() (const TX &x, FILE *tube) const { fprintf(tube,"%10.6f\n",double(x)); }
        template<class TX,class TY>
        void operator() (const TX &x, unsigned i, const TY &y, FILE *tube) const { fprintf( tube, "%10.6f %10.6f\n", double(x), double(y(x)) ); }
        template<class TX, class T, int s, class O>
        void operator() (const TX &x, unsigned i, const Vec<T,s,O> &y, FILE *tube) const { fprintf( tube, "%10.6f %10.6f\n", double(x), double(y[i]) ); }
        template<class TX, class TY, int sy, class OY, class TZ>
        void operator() (const TX &x, unsigned i, const Vec<TY,sy,OY> &y, const TZ &z, FILE *tube) const { fprintf( tube, "%10.6f %10.6f %10.6f\n", double(x), double(y[i]), double(z(x,y[i])) ); }
        template<class TX, class TY, int sy, class OY, class TZ, int sz, class OZ>
        void operator() (const TX &x, unsigned i, const Vec<TY,sy,OY> &y, const Vec<TZ,sz,OZ> &z, FILE *tube) const { fprintf(tube,"%10.6f %10.6f %10.6f\n",double(x),double(y[i]),double(z[i]) ); }
    };
    /*!
        Cette fonction affiche un champ de vecteurs (vx,vy) discrétisé, défini aux points (x,y)

        mat doit etre une matrice de 4 colonnes au moins tel que :
            * la premiere colonne contient les x
            * la deuxieme colonne contient les y
            * la troisieme contient vx la premiere composante du vecteur
            * la quatrieme contient vy

        \friend pasquier@lmt.ens-cachan.fr
        \friend witz@lmt.ens-cachan.fr
    */
    template<class T,class STR,class STO>
    void plot_field(const Mat<T,STR,STO> &mat,const char *params="") {
        //fprintf(tube,"plot '-' using 1:2:(0.01*$3/sqrt($3*$3+$4*$4)):(0.01*$4/sqrt($3*$3+$4*$4)) title \"%s\" with vectors\n",params); // ne marche pas encore...
        fprintf(tube,"plot '-' using 1:2:3:4 title \"%s\" with vectors\n",params);
        std::ostringstream ss; ss << mat;
        fprintf(tube,"%s\ne\n",ss.str().c_str());
        fflush(tube);
    }

    template<class T0, class T1>
    void plot( const T0 &data0, const T1 &data1, const char *params="",bool jump_lines = false) {
        if ( hold ) {
            holded_data.push_back( HD( data0, data1, params ) );
        }
        else {
            fprintf(tube,"plot '-' %s\n",params);
            if (jump_lines and data0.size()) {
                fprintf_jumping_lines( data0, data1 );
                fprintf(tube,"e\n");
            }
            else {
                apply_wi( data0, Disp(),  data1, tube );
                fprintf(tube,"e\n");
            }
            fflush(tube);
        }
    }

    template<class T0, class T1, class T2>
    void splot( const T0 &data0, const T1 &data1, const T2 &data2, const char *params="",bool jump_lines = false) {
        if ( hold ) {
            holded_data.push_back( HD( data0, data1, data2, params ) );
        }
        else {
            fprintf(tube,"splot '-' %s\n",params);
            if (jump_lines and data0.size()) {
                fprintf_jumping_lines( data0, data1, data2 );
                fprintf(tube,"e\n");
            }
            else {
                apply_wi( data0, Disp(),  data1, data2, tube );
                fprintf(tube,"e\n");
            }
            fflush(tube);
        }
    }

    template<class T0, class T1, class T2>
    void plot( const T0 &data0, const T1 &data1, const T2 &data2, const char *params="",bool jump_lines = false) {
        if ( hold ) {
            holded_data.push_back( HD( data0, data1, params ) );
            holded_data.push_back( HD( data0, data2, params ) );
        }
        else {
            fprintf(tube,"plot '-' %s, '-' %s\n",params,params);
            if (jump_lines and data0.size()) {
                fprintf_jumping_lines( data0, data1 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data2 );
                fprintf(tube,"e\n");
            }
            else {
                apply_wi( data0, Disp(),  data1, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data2, tube );
                fprintf(tube,"e\n");
            }
            fflush(tube);
        }
    }

    template<class T0, class T1, class T2, class T3>
    void splot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const char *params="",bool jump_lines = false) {
        if ( hold ) {
            holded_data.push_back( HD( data0, data1, data2, params ) );
            holded_data.push_back( HD( data0, data1, data3, params ) );
        }
        else {
            fprintf(tube,"splot '-' %s, '-' %s\n",params,params);
            if (jump_lines and data0.size()) {
                fprintf_jumping_lines( data0, data1, data2 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data1, data3 );
                fprintf(tube,"e\n");
            }
            else {
                apply_wi( data0, Disp(),  data1, data2, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data1, data3, tube );
                fprintf(tube,"e\n");
            }
            fflush(tube);
        }
    }

    template<class T0, class T1, class T2, class T3>
    void plot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const char *params="",bool jump_lines = false) {
        if ( hold ) {
            holded_data.push_back( HD( data0, data1, params ) );
            holded_data.push_back( HD( data0, data2, params ) );
            holded_data.push_back( HD( data0, data3, params ) );
        }
        else {
            fprintf(tube,"plot '-' %s, '-' %s, '-' %s\n",params,params,params);
            if (jump_lines and data0.size()) {
                fprintf_jumping_lines( data0, data1 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data2 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data3 );
                fprintf(tube,"e\n");
            }
            else {
                apply_wi( data0, Disp(),  data1, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data2, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data3, tube );
                fprintf(tube,"e\n");
            }
            fflush(tube);
        }
    }

    template<class T0, class T1, class T2, class T3, class T4>
    void splot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const T4 &data4, const char *params="",bool jump_lines = false) {
        if ( hold ) {
            holded_data.push_back( HD( data0, data1, data2, params ) );
            holded_data.push_back( HD( data0, data1, data3, params ) );
            holded_data.push_back( HD( data0, data1, data4, params ) );
        }
        else {
            fprintf(tube,"splot '-' %s, '-' %s, '-' %s\n",params,params,params);
            if (jump_lines and data0.size()) {
                fprintf_jumping_lines( data0, data1, data2 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data1, data3 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data1, data4 );
                fprintf(tube,"e\n");
            }
            else {
                apply_wi( data0, Disp(),  data1, data2, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data1, data3, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data1, data4, tube );
                fprintf(tube,"e\n");
            }
            fflush(tube);
        }
    }

    template<class T0, class T1, class T2, class T3, class T4>
    void plot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const T4 &data4, const char *params="",bool jump_lines = false) {
        if ( hold ) {
            holded_data.push_back( HD( data0, data1, params ) );
            holded_data.push_back( HD( data0, data2, params ) );
            holded_data.push_back( HD( data0, data3, params ) );
            holded_data.push_back( HD( data0, data4, params ) );
        }
        else {
            fprintf(tube,"plot '-' %s, '-' %s, '-' %s, '-' %s\n",params,params,params,params);
            if (jump_lines and data0.size()) {
                fprintf_jumping_lines( data0, data1 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data2 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data3 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data4 );
                fprintf(tube,"e\n");
            }
            else {
                apply_wi( data0, Disp(),  data1, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data2, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data3, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data4, tube );
                fprintf(tube,"e\n");
            }
            fflush(tube);
        }
    }

    template<class T0, class T1, class T2, class T3, class T4, class T5>
    void splot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const T4 &data4, const T5 &data5, const char *params="",bool jump_lines = false) {
        if ( hold ) {
            holded_data.push_back( HD( data0, data1, data2, params ) );
            holded_data.push_back( HD( data0, data1, data3, params ) );
            holded_data.push_back( HD( data0, data1, data4, params ) );
            holded_data.push_back( HD( data0, data1, data5, params ) );
        }
        else {
            fprintf(tube,"splot '-' %s, '-' %s, '-' %s, '-' %s\n",params,params,params,params);
            if (jump_lines and data0.size()) {
                fprintf_jumping_lines( data0, data1, data2 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data1, data3 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data1, data4 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data1, data5 );
                fprintf(tube,"e\n");
            }
            else {
                apply_wi( data0, Disp(),  data1, data2, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data1, data3, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data1, data4, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data1, data5, tube );
                fprintf(tube,"e\n");
            }
            fflush(tube);
        }
    }

    template<class T0, class T1, class T2, class T3, class T4, class T5>
    void plot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const T4 &data4, const T5 &data5, const char *params="",bool jump_lines = false) {
        if ( hold ) {
            holded_data.push_back( HD( data0, data1, params ) );
            holded_data.push_back( HD( data0, data2, params ) );
            holded_data.push_back( HD( data0, data3, params ) );
            holded_data.push_back( HD( data0, data4, params ) );
            holded_data.push_back( HD( data0, data5, params ) );
        }
        else {
            fprintf(tube,"plot '-' %s, '-' %s, '-' %s, '-' %s, '-' %s\n",params,params,params,params,params);
            if (jump_lines and data0.size()) {
                fprintf_jumping_lines( data0, data1 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data2 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data3 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data4 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data5 );
                fprintf(tube,"e\n");
            }
            else {
                apply_wi( data0, Disp(),  data1, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data2, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data3, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data4, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data5, tube );
                fprintf(tube,"e\n");
            }
            fflush(tube);
        }
    }

    template<class T0, class T1, class T2, class T3, class T4, class T5, class T6>
    void splot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const T4 &data4, const T5 &data5, const T6 &data6, const char *params="",bool jump_lines = false) {
        if ( hold ) {
            holded_data.push_back( HD( data0, data1, data2, params ) );
            holded_data.push_back( HD( data0, data1, data3, params ) );
            holded_data.push_back( HD( data0, data1, data4, params ) );
            holded_data.push_back( HD( data0, data1, data5, params ) );
            holded_data.push_back( HD( data0, data1, data6, params ) );
        }
        else {
            fprintf(tube,"splot '-' %s, '-' %s, '-' %s, '-' %s, '-' %s\n",params,params,params,params,params);
            if (jump_lines and data0.size()) {
                fprintf_jumping_lines( data0, data1, data2 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data1, data3 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data1, data4 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data1, data5 );
                fprintf(tube,"e\n");
                fprintf_jumping_lines( data0, data1, data6 );
                fprintf(tube,"e\n");
            }
            else {
                apply_wi( data0, Disp(),  data1, data2, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data1, data3, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data1, data4, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data1, data5, tube );
                fprintf(tube,"e\n");
                apply_wi( data0, Disp(),  data1, data6, tube );
                fprintf(tube,"e\n");
            }
            fflush(tube);
        }
    }

    template<class T,int s,class O>
    void plot(const Vec<T,s,O> &vec,const char *params="", bool jump_lines = false) {
        if ( hold )
            holded_data.push_back( HD ( vec, params )  );
        else {
            fprintf(tube,"plot '-' %s\n",params);
            apply( vec, Disp(), tube );
            fprintf(tube,"e\n");
            fflush(tube);
        }
    }

    template<class T,class STR,class STO>
    void splot(const Mat<T,STR,STO> &mat,const char *params="", bool jump_lines = false) {
        fprintf(tube,"splot '-' matrix %s\n",params);
        std::ostringstream ss; ss << mat;
        fprintf(tube,"%s\ne\n",ss.str().c_str());
        fflush(tube);
    }

    void hold_on() { hold = true; }

    void hold_off(bool jump_lines = false) {
        if ( holded_data.size()==0 ) return;

        if ( holded_data[0].z.size() )
            fprintf(tube,"splot ");
        else
            fprintf(tube,"plot ");
        for(unsigned i=0;i<holded_data.size();++i) {
            fprintf(tube," '-' %s",holded_data[i].params.c_str());
            fprintf(tube, ( i<holded_data.size()-1 ? "," : "\n" ) );
        }

        for(unsigned i=0;i<holded_data.size();++i) {
            if ( jump_lines and holded_data[i].x.size() )
                fprintf_jumping_lines( holded_data[i].x, holded_data[i].y, holded_data[i].z );
            else if ( holded_data[i].z.size() )
                apply_wi( holded_data[i].x, Disp(), holded_data[i].y, holded_data[i].z, tube );
            else if ( holded_data[i].y.size() )
                apply_wi( holded_data[i].x, Disp(), holded_data[i].y, tube );
            else
                apply( holded_data[i].x, Disp(), tube );
            fprintf(tube,"e\n");
        }
        fflush(tube);
        holded_data.resize( 0 );
    }

    template <class TY>
    void fprintf_jumping_lines ( const Vec<> &x, const TY &y ) {}

    template <class TZ>
    void fprintf_jumping_lines ( const Vec<> &x, const Vec<> &y, const TZ &z ) {
        double old_x = x[0];
        for (int i=0;i<x.size();i++) {
            if (x[i]!=old_x) {
                fprintf(tube,"\n");
                old_x = x[i];
            }
            fprintf(tube,"%10.6f %10.6f %10.6f\n",x[i],y[i],z(x[i],y[i]));
        }
    }

    void fprintf_jumping_lines ( const Vec<> &x, const Vec<> &y, const Vec<> &z ) {
        double old_x = x[0];
        for (int i=0;i<x.size();i++) {
            if (x[i]!=old_x) {
                fprintf(tube,"\n");
                old_x = x[i];
            }
            fprintf(tube,"%10.6f %10.6f %10.6f\n",x[i],y[i],z[i]);
        }
    }

    FILE *tube;
    bool hold;
    Vec<HD> holded_data;

};

template < class T0>
void plot( const T0 &data0, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.plot( data0, params, jump_lines);
    gp.wait();
}

template < class T0>
void splot( const T0 &data0, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.splot( data0, params, jump_lines);
    gp.wait();
}

template < class T0, class T1>
void plot( const T0 &data0, const T1 &data1, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.plot( data0, data1, params, jump_lines);
    gp.wait();
}

template < class T0, class T1>
void splot( const T0 &data0, const T1 &data1, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.splot( data0, data1, params, jump_lines);
    gp.wait();
}

template < class T0, class T1, class T2>
void plot( const T0 &data0, const T1 &data1, const T2 &data2, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.plot( data0, data1, data2, params, jump_lines);
    gp.wait();
}

template < class T0, class T1, class T2>
void splot( const T0 &data0, const T1 &data1, const T2 &data2, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.splot( data0, data1, data2, params, jump_lines);
    gp.wait();
}

template < class T0, class T1, class T2, class T3>
void plot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.plot( data0, data1, data2, data3, params, jump_lines);
    gp.wait();
}

template < class T0, class T1, class T2, class T3>
void splot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.splot( data0, data1, data2, data3, params, jump_lines);
    gp.wait();
}

template < class T0, class T1, class T2, class T3, class T4>
void plot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const T4 &data4, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.plot( data0, data1, data2, data3, data4, params, jump_lines);
    gp.wait();
}

template < class T0, class T1, class T2, class T3, class T4>
void splot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const T4 &data4, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.splot( data0, data1, data2, data3, data4, params, jump_lines);
    gp.wait();
}

template < class T0, class T1, class T2, class T3, class T4, class T5>
void plot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const T4 &data4, const T5 &data5, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.plot( data0, data1, data2, data3, data4, data5, params, jump_lines);
    gp.wait();
}

template < class T0, class T1, class T2, class T3, class T4, class T5>
void splot( const T0 &data0, const T1 &data1, const T2 &data2, const T3 &data3, const T4 &data4, const T5 &data5, const char *params="", bool jump_lines = false) {
    GnuPlot gp;
    gp.splot( data0, data1, data2, data3, data4, data5, params, jump_lines);
    gp.wait();
}

};

#endif // LMT_gnuplot_HEADER
