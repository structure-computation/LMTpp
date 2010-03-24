//
// C++ Interface: tvrcmodeacoustic
//
// Description: 
//
//
// Author: Hugo LECLERC <hugo.leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_tvrcmodeacoustic_HEADER
#define LMT_tvrcmodeacoustic_HEADER

extern double points_sphere_subdivision[];
extern unsigned nb_points_sphere_subdivision[];

namespace LMT {

/** omly for beams
    \todo right value in k
 */
template<unsigned dim,class T>
class TvrcModeAcoustic : public TvrcMode<dim,dim,T> {
public:
    typedef TvrcMode<dim,dim,T> TP;
    typedef typename TP::TC TC;
    typedef Vec<TC,2> TD;
    /// return min wave length
    T get_min_wave_length() const { return fabs(2.0*M_PI/k.imag()); }
    ///
    template<class TMat,class GeomEnt> void set_param_for_w(double w,const TMat &mat,const GeomEnt &geoment) {
        k = TC(
            0,
            2.0 * M_PI * w // TODO right values
        );
    }
    ///
    template<class HV> static void push_dist(HV &hv,const XmlNode &sn) {
        unsigned nb;
        sn.get_attribute("nb_k",nb);
        
        TvrcModeAcoustic tv;
        for(unsigned i=0;i<nb;++i) {
            for(unsigned d=0;d<dim;++d) tv.dir[d] = points_sphere_subdivision[i*3+d];
            hv.push_back( tv );
        }
    }
    
    /// return displacement and rotation
    template<class TN> TD get_value(const TN &node) const {
        TC cc = exp( k * dot( dir, node.pos ) );
        return Vec<TC,2>( cc, k * cc );
    }
    ///
    static std::string name() { return "acoustic"; }
    ///
    typename TP::TC k;
    Vec<T,dim> dir;
};


};

#endif // LMT_tvrcmodeacoustic_HEADER
