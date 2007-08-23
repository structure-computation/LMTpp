//
// C++ Interface: tvrcmodesurface
//
// Description: 
//
//
// Author: Hugo LECLERC <leclerc@lmt.ens-cachan.fr>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LMT_tvrcmodesurface_HEADER
#define LMT_tvrcmodesurface_HEADER

namespace LMT {


/// omly for surfaces. Convenience class ( for TvrcModeSurfacePlane )
/// parent class for plane modes (tension, ...).
/// \f$ a * \mathbf{d} e^{ k * \mathbf{p} . x + ||A(\mathbf{x}-\mathbf{x_c})|| } \f$
template<unsigned dim,class T>
class TvrcModeSurfacePlaneFlexionParent : public TvrcMode<dim,2,T> {
public:
    typedef typename TvrcMode<dim,2,T>::TC TC;
    typedef typename TvrcMode<dim,2,T>::Pvec Pvec;
    typedef typename TvrcMode<dim,2,T>::Tvi Tvi;
    
    T get_min_wave_length() const { return fabs(2.0*M_PI/k.imag()); }
    
    Tvi dir_propagation,delta_dir_propagation,delta_delta_dir_propagation; /// \f$ \mathbf{p} \f$
    TC k;
};

/// only for surfaces
template<unsigned dim,class T,unsigned pol_deg> class TvrcModeSurfacePlaneFlexion {};

/// only for surfaces
template<unsigned dim,class T>
class TvrcModeSurfacePlaneFlexion<dim,T,0> : public TvrcModeSurfacePlaneFlexionParent<dim,T> {
public:
    typedef TvrcMode<dim,2,T> TP;
    typedef typename TP::TC TC;
    typedef MaterialPoint<TC,dim> TD;
    typedef typename TP::Pvec Pvec;
    typedef typename TP::Rvec Rvec;
    typedef typename TP::Tvi Tvi;
    
    template<class TMat,class GeomEnt> void set_param_for_w(double w,const TMat &mat,const GeomEnt &geoment) {
        this->w = w;
        this->k = TC(
            0,
            2.0*M_PI*pow(12.0*(1.0-mat.poisson*mat.poisson)*mat.volumic_mass*w*w/pow(mat.thickness,2)/mat.young,0.25)
        );
    }
    template<class HV> static void push_dist(HV &hv,const XmlNode &sn) {
        unsigned nb;
        sn.get_attribute("nb_k",nb);
        T da = 2.0 * M_PI / nb;
        for(unsigned i=0;i<nb;++i) {
            T a = i * da;
            TvrcModeSurfacePlaneFlexion tv;
            tv.amplitude = 1.0;
            tv.dir_propagation = Tvi(cos(a),sin(a));
            tv.delta_dir_propagation = Tvi(cos(a),sin(a)) * da;
            tv.delta_delta_dir_propagation = Tvi(cos(a),sin(a)) * (cos(da)-1.0);
            hv.push_back( tv );
        }
    }
    
    template<class TN> TD get_value(const TN &node) const {
        typename TP::Rvec R( T(dim==2) );
        if ( dim==3 ) for(unsigned j=0;j<dim;++j) R += node.der_coords[0] * this->dir_propagation[1] - node.der_coords[1] * this->dir_propagation[0];
        R /= length(R,1e-40);
        
        TC d0 = this->k * dot(node.local_coords,this->dir_propagation);
        return TD(
            exp(d0) * node.der_coords[2],
            this->k * exp(d0) * R / (1e-2*w)
        );
        //         TC d0 = this->k * dot(node.local_coords,this->dir_propagation);
        //         TC d1 = this->k * dot(node.local_coords,this->delta_dir_propagation);
        //         //TC d2 = this->k * dot(node.local_coords,this->delta_delta_dir_propagation);
        //         //if ( d2==TC(0,0) )
        //         //    return exp(d0) * Z;
        //         //return exp(d0-sqrt(M_PI)*d1*d1/4.0/d2) * (erfi((d1+2.0*d2)/2.0/sqrt(d2))-erfi(d1/2.0/sqrt(d2)) )/ 2.0 / sqrt(d2) * Z;
        //         return MaterialPoint<typename TP::TC,dim>(
        //             (exp(d1)-1.0+TC(d1==TC(0,0))) / (d1+TC(d1==TC(0,0))) * exp(d0) * node.der_coords[dim-1],
        //             Rvec(0.0)
        //         );
    }
    static std::string name() { return "plane_flexion_p0"; }
    T w;
};


};

#endif // LMT_tvrcmodesurface_HEADER
