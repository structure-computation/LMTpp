#ifndef PROBLEM_pb_correlation_basic
#define PROBLEM_pb_correlation_basic

#include "formulation/formulation.h"

#ifndef Mesh_carac_pb_correlation_basic_HEADER
#define Mesh_carac_pb_correlation_basic_HEADER
#include "mesh/displayparaview.h"
#include "mesh/triangle.h"
#include "mesh/triangle_6.h"
#include "mesh/quad.h"
#include "mesh/quad_9.h"
#include "mesh/tetra.h"
#include "mesh/hexa.h"
namespace LMT {

template<class TP,unsigned dim> struct Mesh_carac_pb_correlation_basic {};
#ifndef IFNDEF_dep_sens_DM
#define IFNDEF_dep_sens_DM
    struct dep_sens_DM { static std::string name() { return "dep_sens"; } };
#endif // IFNDEF_dep_sens_DM

#ifndef IFNDEF_dep_DM
#define IFNDEF_dep_DM
    struct dep_DM { static std::string name() { return "dep"; } };
#endif // IFNDEF_dep_DM

#ifndef IFNDEF_epsilon_DM
#define IFNDEF_epsilon_DM
    struct epsilon_DM { static std::string name() { return "epsilon"; } };
#endif // IFNDEF_epsilon_DM

#ifndef IFNDEF_normal_DM
#define IFNDEF_normal_DM
    struct normal_DM { static std::string name() { return "normal"; } };
#endif // IFNDEF_normal_DM

#ifndef IFNDEF_pos_DM
#define IFNDEF_pos_DM
    struct pos_DM { static std::string name() { return "pos"; } };
#endif // IFNDEF_pos_DM

#ifndef IFNDEF_is_on_skin_DM
#define IFNDEF_is_on_skin_DM
    struct is_on_skin_DM { static std::string name() { return "is_on_skin"; } };
#endif // IFNDEF_is_on_skin_DM

#ifndef IFNDEF_lum_DM
#define IFNDEF_lum_DM
    struct lum_DM { static std::string name() { return "lum"; } };
#endif // IFNDEF_lum_DM

template<class TP>
struct Mesh_carac_pb_correlation_basic<TP,2> {
    typedef TP Tpos;
    static const unsigned dim = 2;
    typedef Vec<TP,2> Pvec;
    struct NodalStaticData {
        typedef Tpos T1;
        typedef Vec<Tpos,2> T0;
        NodalStaticData():dep_sens(0.0),dep(0.0),normal(0.0),is_on_skin(0),lum(1.0) {}
        CARACDMEXTNAME( 0, T0, dep_sens, "m" );
        CARACDMEXTNAME( 1, T0, dep, "m" );
        CARACDMEXTNAME( 2, T0, normal, "1" );
        CARACDMEXTNAME( 3, T0, pos, "m" );
        CARACDMEXTNAME( 4, T1, is_on_skin, "" );
        CARACDMEXTNAME( 5, T1, lum, "1" );
        static const unsigned nb_params = 6;
        void dm_data_set_field( const std::string field_name, Tpos value ) {
            if ( field_name == "dep_sens" ) { dep_sens = value; return; }
            if ( field_name == "dep" ) { dep = value; return; }
            if ( field_name == "normal" ) { normal = value; return; }
            if ( field_name == "pos" ) { pos = value; return; }
            if ( field_name == "is_on_skin" ) { is_on_skin = value; return; }
            if ( field_name == "lum" ) { lum = value; return; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
            if ( field_name == "dep_sens" ) { dep_sens = value; return; }
            if ( field_name == "dep" ) { dep = value; return; }
            if ( field_name == "normal" ) { normal = value; return; }
            if ( field_name == "pos" ) { pos = value; return; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
            if ( field_name == "is_on_skin" ) { return is_on_skin; }
            if ( field_name == "lum" ) { return lum; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Tpos(0);
        }
        Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,1>();
        }
        Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
            if ( field_name == "dep_sens" ) { return dep_sens; }
            if ( field_name == "dep" ) { return dep; }
            if ( field_name == "normal" ) { return normal; }
            if ( field_name == "pos" ) { return pos; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,2>();
        }
        Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,3>();
        }
        Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,4>();
        }
        Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,5>();
        }
        Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,6>();
        }
        Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<1,1> >();
        }
        Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<2,2> >();
        }
        Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<3,3> >();
        }
        Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<4,4> >();
        }
        Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<5,5> >();
        }
        Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<6,6> >();
        }
        Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<1> >();
        }
        Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<2> >();
        }
        Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<3> >();
        }
    };
    struct GlobalStaticData {
        GlobalStaticData() {}
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Tpos(0);
        }
        Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,1>();
        }
        Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,2>();
        }
        Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,3>();
        }
        Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,4>();
        }
        Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,5>();
        }
        Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,6>();
        }
        Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<1,1> >();
        }
        Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<2,2> >();
        }
        Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<3,3> >();
        }
        Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<4,4> >();
        }
        Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<5,5> >();
        }
        Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<6,6> >();
        }
        Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<1> >();
        }
        Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<2> >();
        }
        Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<3> >();
        }
    };
    typedef Node<dim,Tpos,NodalStaticData> TNode;
    typedef ElementAncestor<TNode> EA;
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0> struct ElementChoice { typedef void NE; typedef DefaultBehavior BE; typedef VoidDMSet TData; };
    template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,0,inner> { typedef Triangle NE; typedef DefaultBehavior BE; 
        struct TData {
            typedef Vec<Vec<Tpos,3>,1> T0;
            TData():epsilon(0) {}
            CARACDMEXTNAME( 0, T0, epsilon, "1" );
            static const unsigned nb_params = 1;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                if ( field_name == "epsilon" ) { return epsilon[0]; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,1,inner> { typedef Triangle_6 NE; typedef DefaultBehavior BE; 
        struct TData {
            typedef Vec<Vec<Tpos,3>,1> T0;
            TData():epsilon(0) {}
            CARACDMEXTNAME( 0, T0, epsilon, "1" );
            static const unsigned nb_params = 1;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                if ( field_name == "epsilon" ) { return epsilon[0]; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,2,inner> { typedef Quad NE; typedef DefaultBehavior BE; 
        struct TData {
            typedef Vec<Vec<Tpos,3>,1> T0;
            TData():epsilon(0) {}
            CARACDMEXTNAME( 0, T0, epsilon, "1" );
            static const unsigned nb_params = 1;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                if ( field_name == "epsilon" ) { return epsilon[0]; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,3,inner> { typedef Quad_9 NE; typedef DefaultBehavior BE; 
        struct TData {
            typedef Vec<Vec<Tpos,3>,1> T0;
            TData():epsilon(0) {}
            CARACDMEXTNAME( 0, T0, epsilon, "1" );
            static const unsigned nb_params = 1;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                if ( field_name == "epsilon" ) { return epsilon[0]; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<1,skin,0,inner> { typedef Bar NE; typedef DefaultBehavior BE; 
        struct TData {
            TData() {}
            VOIDDMSET;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<1,skin,1,inner> { typedef Bar_3 NE; typedef DefaultBehavior BE; 
        struct TData {
            TData() {}
            VOIDDMSET;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<2,skin,0,inner> { typedef NodalElement NE; typedef DefaultBehavior BE; typedef VoidDMSet TData;    };
};
#ifndef IFNDEF_dep_sens_DM
#define IFNDEF_dep_sens_DM
    struct dep_sens_DM { static std::string name() { return "dep_sens"; } };
#endif // IFNDEF_dep_sens_DM

#ifndef IFNDEF_dep_DM
#define IFNDEF_dep_DM
    struct dep_DM { static std::string name() { return "dep"; } };
#endif // IFNDEF_dep_DM

#ifndef IFNDEF_epsilon_DM
#define IFNDEF_epsilon_DM
    struct epsilon_DM { static std::string name() { return "epsilon"; } };
#endif // IFNDEF_epsilon_DM

#ifndef IFNDEF_normal_DM
#define IFNDEF_normal_DM
    struct normal_DM { static std::string name() { return "normal"; } };
#endif // IFNDEF_normal_DM

#ifndef IFNDEF_pos_DM
#define IFNDEF_pos_DM
    struct pos_DM { static std::string name() { return "pos"; } };
#endif // IFNDEF_pos_DM

#ifndef IFNDEF_is_on_skin_DM
#define IFNDEF_is_on_skin_DM
    struct is_on_skin_DM { static std::string name() { return "is_on_skin"; } };
#endif // IFNDEF_is_on_skin_DM

#ifndef IFNDEF_lum_DM
#define IFNDEF_lum_DM
    struct lum_DM { static std::string name() { return "lum"; } };
#endif // IFNDEF_lum_DM

template<class TP>
struct Mesh_carac_pb_correlation_basic<TP,3> {
    typedef TP Tpos;
    static const unsigned dim = 3;
    typedef Vec<TP,3> Pvec;
    struct NodalStaticData {
        typedef Vec<Tpos,3> T0;
        typedef Tpos T1;
        NodalStaticData():dep_sens(0.0),dep(0.0),normal(0.0),is_on_skin(0),lum(1.0) {}
        CARACDMEXTNAME( 0, T0, dep_sens, "m" );
        CARACDMEXTNAME( 1, T0, dep, "m" );
        CARACDMEXTNAME( 2, T0, normal, "1" );
        CARACDMEXTNAME( 3, T0, pos, "m" );
        CARACDMEXTNAME( 4, T1, is_on_skin, "" );
        CARACDMEXTNAME( 5, T1, lum, "1" );
        static const unsigned nb_params = 6;
        void dm_data_set_field( const std::string field_name, Tpos value ) {
            if ( field_name == "dep_sens" ) { dep_sens = value; return; }
            if ( field_name == "dep" ) { dep = value; return; }
            if ( field_name == "normal" ) { normal = value; return; }
            if ( field_name == "pos" ) { pos = value; return; }
            if ( field_name == "is_on_skin" ) { is_on_skin = value; return; }
            if ( field_name == "lum" ) { lum = value; return; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
            if ( field_name == "dep_sens" ) { dep_sens = value; return; }
            if ( field_name == "dep" ) { dep = value; return; }
            if ( field_name == "normal" ) { normal = value; return; }
            if ( field_name == "pos" ) { pos = value; return; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
            if ( field_name == "is_on_skin" ) { return is_on_skin; }
            if ( field_name == "lum" ) { return lum; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Tpos(0);
        }
        Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,1>();
        }
        Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,2>();
        }
        Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
            if ( field_name == "dep_sens" ) { return dep_sens; }
            if ( field_name == "dep" ) { return dep; }
            if ( field_name == "normal" ) { return normal; }
            if ( field_name == "pos" ) { return pos; }
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,3>();
        }
        Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,4>();
        }
        Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,5>();
        }
        Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,6>();
        }
        Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<1,1> >();
        }
        Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<2,2> >();
        }
        Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<3,3> >();
        }
        Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<4,4> >();
        }
        Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<5,5> >();
        }
        Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<6,6> >();
        }
        Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<1> >();
        }
        Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<2> >();
        }
        Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<3> >();
        }
    };
    struct GlobalStaticData {
        GlobalStaticData() {}
        VOIDDMSET;
        void dm_data_set_field( const std::string field_name, Tpos value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
        }
        Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Tpos(0);
        }
        Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,1>();
        }
        Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,2>();
        }
        Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,3>();
        }
        Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,4>();
        }
        Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,5>();
        }
        Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Vec<Tpos,6>();
        }
        Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<1,1> >();
        }
        Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<2,2> >();
        }
        Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<3,3> >();
        }
        Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<4,4> >();
        }
        Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<5,5> >();
        }
        Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
            std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            return Mat<Tpos,Gen<6,6> >();
        }
        Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<1> >();
        }
        Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<2> >();
        }
        Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
            assert( 0 /*TODO*/ );
            return Mat<Tpos,Sym<3> >();
        }
    };
    typedef Node<dim,Tpos,NodalStaticData> TNode;
    typedef ElementAncestor<TNode> EA;
    template<unsigned nvi_to_subs,unsigned skin,unsigned num_sub_element,unsigned inner=0> struct ElementChoice { typedef void NE; typedef DefaultBehavior BE; typedef VoidDMSet TData; };
    template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,0,inner> { typedef Tetra NE; typedef DefaultBehavior BE; 
        struct TData {
            typedef Vec<Vec<Tpos,6>,1> T0;
            TData():epsilon(0) {}
            CARACDMEXTNAME( 0, T0, epsilon, "1" );
            static const unsigned nb_params = 1;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                if ( field_name == "epsilon" ) { return epsilon[0]; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<0,skin,1,inner> { typedef Hexa NE; typedef DefaultBehavior BE; 
        struct TData {
            typedef Vec<Vec<Tpos,6>,1> T0;
            TData():epsilon(0) {}
            CARACDMEXTNAME( 0, T0, epsilon, "1" );
            static const unsigned nb_params = 1;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                if ( field_name == "epsilon" ) { epsilon[0] = value; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                if ( field_name == "epsilon" ) { return epsilon[0]; } // hum
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<1,skin,0,inner> { typedef Triangle NE; typedef DefaultBehavior BE; 
        struct TData {
            TData() {}
            VOIDDMSET;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<1,skin,1,inner> { typedef Quad NE; typedef DefaultBehavior BE; 
        struct TData {
            TData() {}
            VOIDDMSET;
            void dm_data_set_field( const std::string field_name, Tpos value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,1> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,2> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,3> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,4> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,5> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Vec<Tpos,6> &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<1> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<2> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<3> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<4> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<5> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            void dm_data_set_field( const std::string field_name, const Mat<Tpos,Gen<6> > &value ) {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
            }
            Tpos dm_data_get_field( const std::string field_name, StructForType<Tpos> ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Tpos(0);
            }
            Vec<Tpos,1> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,1> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,1>();
            }
            Vec<Tpos,2> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,2> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,2>();
            }
            Vec<Tpos,3> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,3> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,3>();
            }
            Vec<Tpos,4> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,4> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,4>();
            }
            Vec<Tpos,5> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,5> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,5>();
            }
            Vec<Tpos,6> dm_data_get_field( const std::string field_name, StructForType<Vec<Tpos,6> > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Vec<Tpos,6>();
            }
            Mat<Tpos,Gen<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<1,1> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<1,1> >();
            }
            Mat<Tpos,Gen<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<2,2> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<2,2> >();
            }
            Mat<Tpos,Gen<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<3,3> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<3,3> >();
            }
            Mat<Tpos,Gen<4> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<4,4> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<4,4> >();
            }
            Mat<Tpos,Gen<5> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<5,5> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<5,5> >();
            }
            Mat<Tpos,Gen<6> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Gen<6,6> > > ) const {
                std::cerr << "There is no variable named " << field_name << " in data struct" << std::endl;
                return Mat<Tpos,Gen<6,6> >();
            }
            Mat<Tpos,Sym<1> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<1> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<1> >();
            }
            Mat<Tpos,Sym<2> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<2> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<2> >();
            }
            Mat<Tpos,Sym<3> > dm_data_get_field( const std::string field_name, StructForType<Mat<Tpos,Sym<3> > > ) const {
                assert( 0 /*TODO*/ );
                return Mat<Tpos,Sym<3> >();
            }
        };
    };
    template<unsigned skin,unsigned inner> struct ElementChoice<2,skin,0,inner> { typedef Bar NE; typedef DefaultBehavior BE; typedef VoidDMSet TData;    };
    template<unsigned skin,unsigned inner> struct ElementChoice<3,skin,0,inner> { typedef NodalElement NE; typedef DefaultBehavior BE; typedef VoidDMSet TData;    };
};
} // namespace LMT
#endif // Mesh_carac_pb_correlation_basic_HEADER


#include "formulation/formulation.h"
namespace LMT {
#ifndef CORRELATION_BASIC_2_NUM_0_CARAC_H
#define CORRELATION_BASIC_2_NUM_0_CARAC_H
#ifndef STRUCT_CORRELATION_BASIC
#define STRUCT_CORRELATION_BASIC
struct correlation_basic {
  static const char *name() { return "correlation_basic"; }
};
#endif // CORRELATION_BASIC

template<class P_T>
class CaracFormulation<correlation_basic,2,P_T>  {
public:
  typedef P_T T;
  static const char *name() { return "correlation_basic"; }
  static const bool matrix_will_be_definite_positive=true;
  static const bool has_nodal_matrix = false;
  static const bool has_IS_contact_matrix=false;
  static const bool need_skin_assembly=false;
  typedef Norm1_is_inf Name_convergence_criterium;
  static const unsigned nb_vectors = 4;
  static const unsigned nb_matrices = 1;
  static const unsigned auto_contact = false;
  static const bool friction_coeff_is_a_nodal_variable = 0;
  static const unsigned offset_of_pos_unknown=3;
  static const unsigned pos_is_an_unknown = false;
  static const unsigned nb_der_var = 0;
  template<class TF> static void add_to_der_vars( TF &f, const Vec<T> &v ) {
  }
  static bool is_unknown(const std::string &s) { return (s=="dep" || s=="lum"); }
  static unsigned num_in_vec_unknown(const std::string &s) { if ( s=="dep" )return 0; if ( s=="lum" )return 2; return 0;  }
  template<unsigned num_mat,unsigned inner=0> struct NodalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  template<unsigned num_mat,unsigned inner=0> struct GlobalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  
  static const unsigned nb_nodal_unknowns = 3;
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
    node.dep[1]=vecs[0][indice+1]; node.dep[0]=vecs[0][indice+0]; node.lum=vecs[0][indice+2];
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
    node.dep[0]=vecs[0][indice+0]; node.lum=vecs[0][indice+2]; node.dep[1]=vecs[0][indice+1];
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
    vecs[0][indice+0]=node.dep[0]; vecs[1][indice+0]=node.dep[0]; vecs[2][indice+0]=node.dep[0]; vecs[3][indice+0]=node.dep[0]; vecs[4][indice+0]=node.dep[0];
    vecs[0][indice+1]=node.dep[1]; vecs[1][indice+1]=node.dep[1]; vecs[2][indice+1]=node.dep[1]; vecs[3][indice+1]=node.dep[1]; vecs[4][indice+1]=node.dep[1];
    vecs[0][indice+2]=node.lum; vecs[1][indice+2]=node.lum; vecs[2][indice+2]=node.lum; vecs[3][indice+2]=node.lum; vecs[4][indice+2]=node.lum;
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    T reg0=vecs[1][indice+0]-vecs[0][indice+0]; T reg1=vecs[1][indice+1]-vecs[0][indice+1]; reg0=abs(reg0); reg1=abs(reg1); T reg2=vecs[1][indice+2]-vecs[0][indice+2];
    reg0=max(reg1,reg0); reg2=abs(reg2); return max(reg2,reg0);
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
    old_vec[indice+0]=vecs[1][indice+0]; old_vec[indice+1]=vecs[1][indice+1]; old_vec[indice+2]=vecs[1][indice+2];
  }
  
  static const unsigned nb_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_nodal_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};
#endif // CORRELATION_BASIC_2_NUM_0_CARAC_H
extern "C" void apply_on_elements_after_solve_0_correlation_basic_Triangle_0( double * );
extern "C" void apply_on_elements_after_solve_1_correlation_basic_Triangle_1( double * );
extern "C" void apply_on_elements_after_solve_2_correlation_basic_Triangle_2( double * );
extern "C" void apply_on_elements_after_solve_3_correlation_basic_Triangle_3( double * );
extern "C" void apply_on_elements_after_solve_4_correlation_basic_Triangle_4( double * );
extern "C" void apply_on_elements_after_solve_5_correlation_basic_Triangle_5( double * );
class Triangle;
template<unsigned A,class B,class C> class Node;
template<class A,class B,class C,class D,unsigned E> class Element;

// Carac for ...
template<class P_T_pos,class P_ND,class TED,unsigned nim,class TM,class T>
class CaracFormulationForElement<correlation_basic,Element<Triangle,DefaultBehavior,Node<2,P_T_pos,P_ND>,TED,nim>,TM,T> {
public:
    template<unsigned num_mat,unsigned inner=0> struct ElemMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
        static const bool linear = true;
    };
    static const unsigned order_integration = 0;
    static const bool has_elementary_matrix = false;
    static const bool has_skin_elementary_matrix = false;
    template<class TE,class TF, class TVEVE> static void after_solve(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[1]-elem.pos(0)[1]; T reg1=elem.pos(2)[0]-elem.pos(0)[0]; T reg2=elem.pos(1)[1]-elem.pos(0)[1]; T reg3=elem.pos(1)[0]-elem.pos(0)[0]; T reg4=reg3*reg0;
    T reg5=reg2*reg1; reg5=reg4-reg5; reg2=reg2/reg5; reg1=reg1/reg5; reg3=reg3/reg5;
    reg5=reg0/reg5; reg0=vectors[0][indices[1]+0]-vectors[0][indices[0]+0]; reg4=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; T reg6=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; T reg7=vectors[0][indices[1]+1]-vectors[0][indices[0]+1];
    T reg8=reg2*reg6; T reg9=reg5*reg7; T reg10=reg1*reg0; T reg11=reg3*reg4; reg8=reg9-reg8;
    reg10=reg11-reg10; reg8=reg10+reg8; reg7=reg1*reg7; reg6=reg3*reg6; reg4=reg2*reg4;
    reg0=reg5*reg0; elem.epsilon[0][1]=reg6-reg7; elem.epsilon[0][0]=reg0-reg4; elem.epsilon[0][2]=0.5*reg8;
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_2(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_3(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_4(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_5(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_6(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
  
  static const unsigned nb_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};

// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_true
#define ADD_NODAL_MATRIX_correlation_basic_false_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_true
#define ADD_NODAL_MATRIX_correlation_basic_true_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_false
#define ADD_NODAL_MATRIX_correlation_basic_false_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_false
#define ADD_NODAL_MATRIX_correlation_basic_true_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}

#ifndef correlation_basic_read_material_to_mesh
#define correlation_basic_read_material_to_mesh
template<class TM, class T, bool wont_add_nz>
void read_material_to_mesh_(const XmlNode &n, Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f){ 
  };
#endif // correlation_basic_read_material_to_mesh
} // namespace LMT


#include "formulation/formulation.h"
namespace LMT {
#ifndef CORRELATION_BASIC_2_NUM_0_CARAC_H
#define CORRELATION_BASIC_2_NUM_0_CARAC_H
#ifndef STRUCT_CORRELATION_BASIC
#define STRUCT_CORRELATION_BASIC
struct correlation_basic {
  static const char *name() { return "correlation_basic"; }
};
#endif // CORRELATION_BASIC

template<class P_T>
class CaracFormulation<correlation_basic,2,P_T>  {
public:
  typedef P_T T;
  static const char *name() { return "correlation_basic"; }
  static const bool matrix_will_be_definite_positive=true;
  static const bool has_nodal_matrix = false;
  static const bool has_IS_contact_matrix=false;
  static const bool need_skin_assembly=false;
  typedef Norm1_is_inf Name_convergence_criterium;
  static const unsigned nb_vectors = 4;
  static const unsigned nb_matrices = 1;
  static const unsigned auto_contact = false;
  static const bool friction_coeff_is_a_nodal_variable = 0;
  static const unsigned offset_of_pos_unknown=3;
  static const unsigned pos_is_an_unknown = false;
  static const unsigned nb_der_var = 0;
  template<class TF> static void add_to_der_vars( TF &f, const Vec<T> &v ) {
  }
  static bool is_unknown(const std::string &s) { return (s=="dep" || s=="lum"); }
  static unsigned num_in_vec_unknown(const std::string &s) { if ( s=="dep" )return 0; if ( s=="lum" )return 2; return 0;  }
  template<unsigned num_mat,unsigned inner=0> struct NodalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  template<unsigned num_mat,unsigned inner=0> struct GlobalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  
  static const unsigned nb_nodal_unknowns = 3;
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
    node.dep[1]=vecs[0][indice+1]; node.lum=vecs[0][indice+2]; node.dep[0]=vecs[0][indice+0];
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
    node.dep[1]=vecs[0][indice+1]; node.lum=vecs[0][indice+2]; node.dep[0]=vecs[0][indice+0];
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
    vecs[0][indice+2]=node.lum; vecs[1][indice+2]=node.lum; vecs[2][indice+2]=node.lum; vecs[3][indice+2]=node.lum; vecs[4][indice+2]=node.lum;
    vecs[0][indice+1]=node.dep[1]; vecs[1][indice+1]=node.dep[1]; vecs[2][indice+1]=node.dep[1]; vecs[3][indice+1]=node.dep[1]; vecs[4][indice+1]=node.dep[1];
    vecs[0][indice+0]=node.dep[0]; vecs[1][indice+0]=node.dep[0]; vecs[2][indice+0]=node.dep[0]; vecs[3][indice+0]=node.dep[0]; vecs[4][indice+0]=node.dep[0];
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    T reg0=vecs[1][indice+0]-vecs[0][indice+0]; T reg1=vecs[1][indice+1]-vecs[0][indice+1]; reg0=abs(reg0); reg1=abs(reg1); T reg2=vecs[1][indice+2]-vecs[0][indice+2];
    reg0=max(reg1,reg0); reg2=abs(reg2); return max(reg2,reg0);
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
    old_vec[indice+0]=vecs[1][indice+0]; old_vec[indice+2]=vecs[1][indice+2]; old_vec[indice+1]=vecs[1][indice+1];
  }
  
  static const unsigned nb_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_nodal_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};
#endif // CORRELATION_BASIC_2_NUM_0_CARAC_H
extern "C" void apply_on_elements_after_solve_0_correlation_basic_Triangle_6_0( double * );
extern "C" void apply_on_elements_after_solve_1_correlation_basic_Triangle_6_1( double * );
extern "C" void apply_on_elements_after_solve_2_correlation_basic_Triangle_6_2( double * );
extern "C" void apply_on_elements_after_solve_3_correlation_basic_Triangle_6_3( double * );
extern "C" void apply_on_elements_after_solve_4_correlation_basic_Triangle_6_4( double * );
extern "C" void apply_on_elements_after_solve_5_correlation_basic_Triangle_6_5( double * );
class Triangle_6;
template<unsigned A,class B,class C> class Node;
template<class A,class B,class C,class D,unsigned E> class Element;

// Carac for ...
template<class P_T_pos,class P_ND,class TED,unsigned nim,class TM,class T>
class CaracFormulationForElement<correlation_basic,Element<Triangle_6,DefaultBehavior,Node<2,P_T_pos,P_ND>,TED,nim>,TM,T> {
public:
    template<unsigned num_mat,unsigned inner=0> struct ElemMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
        static const bool linear = true;
    };
    static const unsigned order_integration = 2;
    static const bool has_elementary_matrix = false;
    static const bool has_skin_elementary_matrix = false;
    template<class TE,class TF, class TVEVE> static void after_solve(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(0)[0]+elem.pos(2)[0]; T reg1=elem.pos(0)[1]+elem.pos(1)[1]; T reg2=2*elem.pos(3)[0]; T reg3=elem.pos(0)[0]+elem.pos(1)[0]; T reg4=2*elem.pos(3)[1];
    T reg5=elem.pos(0)[1]+elem.pos(2)[1]; reg1=reg1-reg4; reg0=reg0-reg2; T reg6=2*elem.pos(4)[0]; reg3=reg3-reg2;
    T reg7=2*elem.pos(4)[1]; reg5=reg5-reg4; reg1=reg7+reg1; reg0=reg6+reg0; T reg8=2*elem.pos(5)[0];
    reg6=reg3+reg6; reg3=2*elem.pos(5)[1]; reg7=reg5+reg7; reg0=reg0-reg8; reg5=vectors[0][indices[0]+1]+vectors[0][indices[2]+1];
    T reg9=vectors[0][indices[0]+0]+vectors[0][indices[2]+0]; T reg10=vectors[0][indices[0]+1]+vectors[0][indices[1]+1]; T reg11=2*vectors[0][indices[3]+1]; T reg12=vectors[0][indices[0]+0]+vectors[0][indices[1]+0]; T reg13=2*vectors[0][indices[3]+0];
    reg7=reg7-reg3; reg6=reg6-reg8; reg1=reg1-reg3; reg10=reg10-reg11; T reg14=2*vectors[0][indices[4]+1];
    reg5=reg5-reg11; reg9=reg9-reg13; T reg15=reg7*reg6; T reg16=2*vectors[0][indices[4]+0]; T reg17=reg1*reg0;
    reg12=reg12-reg13; reg10=reg14+reg10; T reg18=2*vectors[0][indices[5]+1]; reg14=reg5+reg14; reg17=reg15-reg17;
    reg12=reg12+reg16; reg9=reg16+reg9; reg5=2*vectors[0][indices[5]+0]; reg6=reg6/reg17; reg9=reg9-reg5;
    reg7=reg7/reg17; reg1=reg1/reg17; reg14=reg14-reg18; reg17=reg0/reg17; reg12=reg12-reg5;
    reg10=reg10-reg18; reg0=reg1*reg14; reg15=reg7*reg10; reg16=reg12*reg17; T reg19=reg9*reg6;
    reg0=reg15-reg0; reg16=reg19-reg16; reg0=reg16+reg0; reg10=reg17*reg10; reg14=reg6*reg14;
    reg12=reg7*reg12; reg9=reg1*reg9; elem.epsilon[0][2]=0.5*reg0; elem.epsilon[0][1]=reg14-reg10; elem.epsilon[0][0]=reg12-reg9;
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_2(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_3(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_4(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_5(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_6(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
  
  static const unsigned nb_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};

// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_true
#define ADD_NODAL_MATRIX_correlation_basic_false_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_true
#define ADD_NODAL_MATRIX_correlation_basic_true_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_false
#define ADD_NODAL_MATRIX_correlation_basic_false_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_false
#define ADD_NODAL_MATRIX_correlation_basic_true_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Triangle_6,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}

#ifndef correlation_basic_read_material_to_mesh
#define correlation_basic_read_material_to_mesh
template<class TM, class T, bool wont_add_nz>
void read_material_to_mesh_(const XmlNode &n, Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f){ 
  };
#endif // correlation_basic_read_material_to_mesh
} // namespace LMT


#include "formulation/formulation.h"
namespace LMT {
#ifndef CORRELATION_BASIC_2_NUM_0_CARAC_H
#define CORRELATION_BASIC_2_NUM_0_CARAC_H
#ifndef STRUCT_CORRELATION_BASIC
#define STRUCT_CORRELATION_BASIC
struct correlation_basic {
  static const char *name() { return "correlation_basic"; }
};
#endif // CORRELATION_BASIC

template<class P_T>
class CaracFormulation<correlation_basic,2,P_T>  {
public:
  typedef P_T T;
  static const char *name() { return "correlation_basic"; }
  static const bool matrix_will_be_definite_positive=true;
  static const bool has_nodal_matrix = false;
  static const bool has_IS_contact_matrix=false;
  static const bool need_skin_assembly=false;
  typedef Norm1_is_inf Name_convergence_criterium;
  static const unsigned nb_vectors = 4;
  static const unsigned nb_matrices = 1;
  static const unsigned auto_contact = false;
  static const bool friction_coeff_is_a_nodal_variable = 0;
  static const unsigned offset_of_pos_unknown=3;
  static const unsigned pos_is_an_unknown = false;
  static const unsigned nb_der_var = 0;
  template<class TF> static void add_to_der_vars( TF &f, const Vec<T> &v ) {
  }
  static bool is_unknown(const std::string &s) { return (s=="dep" || s=="lum"); }
  static unsigned num_in_vec_unknown(const std::string &s) { if ( s=="dep" )return 0; if ( s=="lum" )return 2; return 0;  }
  template<unsigned num_mat,unsigned inner=0> struct NodalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  template<unsigned num_mat,unsigned inner=0> struct GlobalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  
  static const unsigned nb_nodal_unknowns = 3;
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
    node.dep[1]=vecs[0][indice+1]; node.dep[0]=vecs[0][indice+0]; node.lum=vecs[0][indice+2];
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
    node.dep[0]=vecs[0][indice+0]; node.lum=vecs[0][indice+2]; node.dep[1]=vecs[0][indice+1];
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
    vecs[0][indice+1]=node.dep[1]; vecs[1][indice+1]=node.dep[1]; vecs[2][indice+1]=node.dep[1]; vecs[3][indice+1]=node.dep[1]; vecs[4][indice+1]=node.dep[1];
    vecs[0][indice+0]=node.dep[0]; vecs[1][indice+0]=node.dep[0]; vecs[2][indice+0]=node.dep[0]; vecs[3][indice+0]=node.dep[0]; vecs[4][indice+0]=node.dep[0];
    vecs[0][indice+2]=node.lum; vecs[1][indice+2]=node.lum; vecs[2][indice+2]=node.lum; vecs[3][indice+2]=node.lum; vecs[4][indice+2]=node.lum;
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    T reg0=vecs[1][indice+1]-vecs[0][indice+1]; T reg1=vecs[1][indice+0]-vecs[0][indice+0]; reg1=abs(reg1); reg0=abs(reg0); T reg2=vecs[1][indice+2]-vecs[0][indice+2];
    reg1=max(reg0,reg1); reg2=abs(reg2); return max(reg2,reg1);
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
    old_vec[indice+2]=vecs[1][indice+2]; old_vec[indice+1]=vecs[1][indice+1]; old_vec[indice+0]=vecs[1][indice+0];
  }
  
  static const unsigned nb_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_nodal_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};
#endif // CORRELATION_BASIC_2_NUM_0_CARAC_H
extern "C" void apply_on_elements_after_solve_0_correlation_basic_Quad_0( double * );
extern "C" void apply_on_elements_after_solve_1_correlation_basic_Quad_1( double * );
extern "C" void apply_on_elements_after_solve_2_correlation_basic_Quad_2( double * );
extern "C" void apply_on_elements_after_solve_3_correlation_basic_Quad_3( double * );
extern "C" void apply_on_elements_after_solve_4_correlation_basic_Quad_4( double * );
extern "C" void apply_on_elements_after_solve_5_correlation_basic_Quad_5( double * );
class Quad;
template<unsigned A,class B,class C> class Node;
template<class A,class B,class C,class D,unsigned E> class Element;

// Carac for ...
template<class P_T_pos,class P_ND,class TED,unsigned nim,class TM,class T>
class CaracFormulationForElement<correlation_basic,Element<Quad,DefaultBehavior,Node<2,P_T_pos,P_ND>,TED,nim>,TM,T> {
public:
    template<unsigned num_mat,unsigned inner=0> struct ElemMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
        static const bool linear = true;
    };
    static const unsigned order_integration = 2;
    static const bool has_elementary_matrix = false;
    static const bool has_skin_elementary_matrix = false;
    template<class TE,class TF, class TVEVE> static void after_solve(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
    T reg0=0.5*elem.pos(0)[0]; T reg1=0.5*elem.pos(1)[0]; T reg2=0.5*elem.pos(1)[1]; T reg3=0.5*elem.pos(0)[1]; T reg4=reg2-reg3;
    T reg5=reg1+reg0; reg0=reg1-reg0; reg1=0.5*elem.pos(2)[1]; reg2=reg3+reg2; reg3=0.5*elem.pos(2)[0];
    reg4=reg1+reg4; reg5=reg3-reg5; T reg6=0.5*elem.pos(3)[0]; reg0=reg3+reg0; reg3=0.5*elem.pos(3)[1];
    reg2=reg1-reg2; reg5=reg6+reg5; reg1=0.5*vectors[0][indices[1]+0]; T reg7=0.5*vectors[0][indices[0]+0]; T reg8=0.5*vectors[0][indices[1]+1];
    T reg9=0.5*vectors[0][indices[0]+1]; reg4=reg4-reg3; reg6=reg0-reg6; reg3=reg2+reg3; reg0=0.5*vectors[0][indices[2]+1];
    reg2=reg1+reg7; T reg10=reg9+reg8; T reg11=0.5*vectors[0][indices[2]+0]; reg7=reg1-reg7; reg9=reg8-reg9;
    reg1=reg4*reg5; reg8=reg3*reg6; T reg12=0.5*vectors[0][indices[3]+1]; reg10=reg0-reg10; reg9=reg0+reg9;
    reg1=reg8-reg1; reg2=reg11-reg2; reg11=reg7+reg11; reg0=0.5*vectors[0][indices[3]+0]; reg9=reg9-reg12;
    reg3=reg3/reg1; reg5=reg5/reg1; reg12=reg10+reg12; reg11=reg11-reg0; reg4=reg4/reg1;
    reg1=reg6/reg1; reg2=reg0+reg2; reg0=reg2*reg1; reg6=reg11*reg5; reg7=reg3*reg9;
    reg8=reg4*reg12; reg6=reg0-reg6; reg8=reg7-reg8; reg11=reg3*reg11; reg12=reg1*reg12;
    reg2=reg4*reg2; reg9=reg5*reg9; reg8=reg6+reg8; elem.epsilon[0][2]=0.5*reg8; elem.epsilon[0][1]=reg12-reg9;
    elem.epsilon[0][0]=reg11-reg2;
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_2(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_3(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_4(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_5(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_6(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
  
  static const unsigned nb_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};

// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_true
#define ADD_NODAL_MATRIX_correlation_basic_false_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_true
#define ADD_NODAL_MATRIX_correlation_basic_true_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_false
#define ADD_NODAL_MATRIX_correlation_basic_false_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_false
#define ADD_NODAL_MATRIX_correlation_basic_true_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}

#ifndef correlation_basic_read_material_to_mesh
#define correlation_basic_read_material_to_mesh
template<class TM, class T, bool wont_add_nz>
void read_material_to_mesh_(const XmlNode &n, Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f){ 
  };
#endif // correlation_basic_read_material_to_mesh
} // namespace LMT


#include "formulation/formulation.h"
namespace LMT {
#ifndef CORRELATION_BASIC_2_NUM_0_CARAC_H
#define CORRELATION_BASIC_2_NUM_0_CARAC_H
#ifndef STRUCT_CORRELATION_BASIC
#define STRUCT_CORRELATION_BASIC
struct correlation_basic {
  static const char *name() { return "correlation_basic"; }
};
#endif // CORRELATION_BASIC

template<class P_T>
class CaracFormulation<correlation_basic,2,P_T>  {
public:
  typedef P_T T;
  static const char *name() { return "correlation_basic"; }
  static const bool matrix_will_be_definite_positive=true;
  static const bool has_nodal_matrix = false;
  static const bool has_IS_contact_matrix=false;
  static const bool need_skin_assembly=false;
  typedef Norm1_is_inf Name_convergence_criterium;
  static const unsigned nb_vectors = 4;
  static const unsigned nb_matrices = 1;
  static const unsigned auto_contact = false;
  static const bool friction_coeff_is_a_nodal_variable = 0;
  static const unsigned offset_of_pos_unknown=3;
  static const unsigned pos_is_an_unknown = false;
  static const unsigned nb_der_var = 0;
  template<class TF> static void add_to_der_vars( TF &f, const Vec<T> &v ) {
  }
  static bool is_unknown(const std::string &s) { return (s=="dep" || s=="lum"); }
  static unsigned num_in_vec_unknown(const std::string &s) { if ( s=="dep" )return 0; if ( s=="lum" )return 2; return 0;  }
  template<unsigned num_mat,unsigned inner=0> struct NodalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  template<unsigned num_mat,unsigned inner=0> struct GlobalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  
  static const unsigned nb_nodal_unknowns = 3;
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
    node.lum=vecs[0][indice+2]; node.dep[1]=vecs[0][indice+1]; node.dep[0]=vecs[0][indice+0];
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
    node.dep[0]=vecs[0][indice+0]; node.dep[1]=vecs[0][indice+1]; node.lum=vecs[0][indice+2];
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
    vecs[0][indice+0]=node.dep[0]; vecs[1][indice+0]=node.dep[0]; vecs[2][indice+0]=node.dep[0]; vecs[3][indice+0]=node.dep[0]; vecs[4][indice+0]=node.dep[0];
    vecs[0][indice+2]=node.lum; vecs[1][indice+2]=node.lum; vecs[2][indice+2]=node.lum; vecs[3][indice+2]=node.lum; vecs[4][indice+2]=node.lum;
    vecs[0][indice+1]=node.dep[1]; vecs[1][indice+1]=node.dep[1]; vecs[2][indice+1]=node.dep[1]; vecs[3][indice+1]=node.dep[1]; vecs[4][indice+1]=node.dep[1];
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    T reg0=vecs[1][indice+1]-vecs[0][indice+1]; T reg1=vecs[1][indice+0]-vecs[0][indice+0]; T reg2=vecs[1][indice+2]-vecs[0][indice+2]; reg0=abs(reg0); reg1=abs(reg1);
    reg2=abs(reg2); reg1=max(reg0,reg1); return max(reg2,reg1);
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
    old_vec[indice+0]=vecs[1][indice+0]; old_vec[indice+1]=vecs[1][indice+1]; old_vec[indice+2]=vecs[1][indice+2];
  }
  
  static const unsigned nb_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_nodal_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};
#endif // CORRELATION_BASIC_2_NUM_0_CARAC_H
extern "C" void apply_on_elements_after_solve_0_correlation_basic_Quad_9_0( double * );
extern "C" void apply_on_elements_after_solve_1_correlation_basic_Quad_9_1( double * );
extern "C" void apply_on_elements_after_solve_2_correlation_basic_Quad_9_2( double * );
extern "C" void apply_on_elements_after_solve_3_correlation_basic_Quad_9_3( double * );
extern "C" void apply_on_elements_after_solve_4_correlation_basic_Quad_9_4( double * );
extern "C" void apply_on_elements_after_solve_5_correlation_basic_Quad_9_5( double * );
class Quad_9;
template<unsigned A,class B,class C> class Node;
template<class A,class B,class C,class D,unsigned E> class Element;

// Carac for ...
template<class P_T_pos,class P_ND,class TED,unsigned nim,class TM,class T>
class CaracFormulationForElement<correlation_basic,Element<Quad_9,DefaultBehavior,Node<2,P_T_pos,P_ND>,TED,nim>,TM,T> {
public:
    template<unsigned num_mat,unsigned inner=0> struct ElemMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
        static const bool linear = true;
    };
    static const unsigned order_integration = 4;
    static const bool has_elementary_matrix = false;
    static const bool has_skin_elementary_matrix = false;
    template<class TE,class TF, class TVEVE> static void after_solve(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(6)[0]-elem.pos(4)[0]; T reg1=elem.pos(5)[1]-elem.pos(7)[1]; T reg2=elem.pos(5)[0]-elem.pos(7)[0]; T reg3=elem.pos(6)[1]-elem.pos(4)[1]; T reg4=reg1*reg0;
    T reg5=reg3*reg2; reg4=reg5-reg4; reg5=vectors[0][indices[5]+1]-vectors[0][indices[7]+1]; reg0=reg0/reg4; T reg6=vectors[0][indices[6]+1]-vectors[0][indices[4]+1];
    reg2=reg2/reg4; T reg7=vectors[0][indices[6]+0]-vectors[0][indices[4]+0]; reg1=reg1/reg4; T reg8=vectors[0][indices[5]+0]-vectors[0][indices[7]+0]; reg4=reg3/reg4;
    reg3=reg7*reg2; T reg9=reg8*reg0; T reg10=reg4*reg5; T reg11=reg1*reg6; reg9=reg3-reg9;
    reg11=reg10-reg11; reg7=reg1*reg7; reg8=reg4*reg8; reg6=reg2*reg6; reg5=reg0*reg5;
    reg11=reg9+reg11; elem.epsilon[0][2]=0.5*reg11; elem.epsilon[0][1]=reg6-reg5; elem.epsilon[0][0]=reg8-reg7;
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_2(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_3(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_4(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_5(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_6(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
  
  static const unsigned nb_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};

// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_true
#define ADD_NODAL_MATRIX_correlation_basic_false_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_true
#define ADD_NODAL_MATRIX_correlation_basic_true_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_false
#define ADD_NODAL_MATRIX_correlation_basic_false_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_false
#define ADD_NODAL_MATRIX_correlation_basic_true_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Quad_9,DefaultBehavior,Node<2,T_pos,ND>,ED,nim> &elem,
      const Element<Bar_3,DefaultBehavior,Node<2,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}

#ifndef correlation_basic_read_material_to_mesh
#define correlation_basic_read_material_to_mesh
template<class TM, class T, bool wont_add_nz>
void read_material_to_mesh_(const XmlNode &n, Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f){ 
  };
#endif // correlation_basic_read_material_to_mesh
} // namespace LMT


#include "formulation/formulation.h"
namespace LMT {
#ifndef CORRELATION_BASIC_3_NUM_0_CARAC_H
#define CORRELATION_BASIC_3_NUM_0_CARAC_H
#ifndef STRUCT_CORRELATION_BASIC
#define STRUCT_CORRELATION_BASIC
struct correlation_basic {
  static const char *name() { return "correlation_basic"; }
};
#endif // CORRELATION_BASIC

template<class P_T>
class CaracFormulation<correlation_basic,3,P_T>  {
public:
  typedef P_T T;
  static const char *name() { return "correlation_basic"; }
  static const bool matrix_will_be_definite_positive=true;
  static const bool has_nodal_matrix = false;
  static const bool has_IS_contact_matrix=false;
  static const bool need_skin_assembly=false;
  typedef Norm1_is_inf Name_convergence_criterium;
  static const unsigned nb_vectors = 4;
  static const unsigned nb_matrices = 1;
  static const unsigned auto_contact = false;
  static const bool friction_coeff_is_a_nodal_variable = 0;
  static const unsigned offset_of_pos_unknown=3;
  static const unsigned pos_is_an_unknown = false;
  static const unsigned nb_der_var = 0;
  template<class TF> static void add_to_der_vars( TF &f, const Vec<T> &v ) {
  }
  static bool is_unknown(const std::string &s) { return (s=="dep" || s=="lum"); }
  static unsigned num_in_vec_unknown(const std::string &s) { if ( s=="dep" )return 0; if ( s=="lum" )return 3; return 0;  }
  template<unsigned num_mat,unsigned inner=0> struct NodalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  template<unsigned num_mat,unsigned inner=0> struct GlobalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  
  static const unsigned nb_nodal_unknowns = 4;
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
    node.dep[1]=vecs[0][indice+1]; node.dep[2]=vecs[0][indice+2]; node.dep[0]=vecs[0][indice+0]; node.lum=vecs[0][indice+3];
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
    node.dep[0]=vecs[0][indice+0]; node.dep[1]=vecs[0][indice+1]; node.lum=vecs[0][indice+3]; node.dep[2]=vecs[0][indice+2];
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
    vecs[0][indice+0]=node.dep[0]; vecs[1][indice+0]=node.dep[0]; vecs[2][indice+0]=node.dep[0]; vecs[3][indice+0]=node.dep[0]; vecs[4][indice+0]=node.dep[0];
    vecs[0][indice+2]=node.dep[2]; vecs[1][indice+2]=node.dep[2]; vecs[2][indice+2]=node.dep[2]; vecs[3][indice+2]=node.dep[2]; vecs[4][indice+2]=node.dep[2];
    vecs[0][indice+3]=node.lum; vecs[1][indice+3]=node.lum; vecs[2][indice+3]=node.lum; vecs[3][indice+3]=node.lum; vecs[4][indice+3]=node.lum;
    vecs[0][indice+1]=node.dep[1]; vecs[1][indice+1]=node.dep[1]; vecs[2][indice+1]=node.dep[1]; vecs[3][indice+1]=node.dep[1]; vecs[4][indice+1]=node.dep[1];
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    T reg0=vecs[1][indice+1]-vecs[0][indice+1]; T reg1=vecs[1][indice+0]-vecs[0][indice+0]; reg0=abs(reg0); T reg2=vecs[1][indice+2]-vecs[0][indice+2]; reg1=abs(reg1);
    reg1=max(reg0,reg1); reg2=abs(reg2); reg0=vecs[1][indice+3]-vecs[0][indice+3]; reg1=max(reg2,reg1); reg0=abs(reg0);
    return max(reg0,reg1);
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
    old_vec[indice+2]=vecs[1][indice+2]; old_vec[indice+3]=vecs[1][indice+3]; old_vec[indice+1]=vecs[1][indice+1]; old_vec[indice+0]=vecs[1][indice+0];
  }
  
  static const unsigned nb_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_nodal_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};
#endif // CORRELATION_BASIC_3_NUM_0_CARAC_H
extern "C" void apply_on_elements_after_solve_0_correlation_basic_Tetra_0( double * );
extern "C" void apply_on_elements_after_solve_1_correlation_basic_Tetra_1( double * );
extern "C" void apply_on_elements_after_solve_2_correlation_basic_Tetra_2( double * );
extern "C" void apply_on_elements_after_solve_3_correlation_basic_Tetra_3( double * );
extern "C" void apply_on_elements_after_solve_4_correlation_basic_Tetra_4( double * );
extern "C" void apply_on_elements_after_solve_5_correlation_basic_Tetra_5( double * );
class Tetra;
template<unsigned A,class B,class C> class Node;
template<class A,class B,class C,class D,unsigned E> class Element;

// Carac for ...
template<class P_T_pos,class P_ND,class TED,unsigned nim,class TM,class T>
class CaracFormulationForElement<correlation_basic,Element<Tetra,DefaultBehavior,Node<3,P_T_pos,P_ND>,TED,nim>,TM,T> {
public:
    template<unsigned num_mat,unsigned inner=0> struct ElemMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
        static const bool linear = true;
    };
    static const unsigned order_integration = 0;
    static const bool has_elementary_matrix = false;
    static const bool has_skin_elementary_matrix = false;
    template<class TE,class TF, class TVEVE> static void after_solve(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
    T reg0=elem.pos(2)[1]-elem.pos(0)[1]; T reg1=elem.pos(2)[2]-elem.pos(0)[2]; T reg2=elem.pos(1)[2]-elem.pos(0)[2]; T reg3=elem.pos(1)[1]-elem.pos(0)[1]; T reg4=elem.pos(3)[2]-elem.pos(0)[2];
    T reg5=elem.pos(3)[1]-elem.pos(0)[1]; T reg6=reg0*reg4; T reg7=reg3*reg4; T reg8=reg1*reg5; T reg9=reg2*reg5;
    T reg10=elem.pos(2)[0]-elem.pos(0)[0]; T reg11=reg2*reg0; T reg12=elem.pos(1)[0]-elem.pos(0)[0]; T reg13=reg3*reg1; reg8=reg6-reg8;
    reg9=reg7-reg9; reg11=reg13-reg11; reg6=reg10*reg9; reg7=reg12*reg8; reg13=elem.pos(3)[0]-elem.pos(0)[0];
    T reg14=reg2*reg13; reg6=reg7-reg6; reg7=reg13*reg11; T reg15=reg3*reg13; T reg16=reg10*reg4;
    T reg17=reg1*reg13; T reg18=reg10*reg5; reg5=reg12*reg5; reg4=reg12*reg4; reg13=reg0*reg13;
    reg3=reg3*reg10; reg0=reg12*reg0; reg10=reg2*reg10; reg1=reg12*reg1; reg15=reg5-reg15;
    reg14=reg4-reg14; reg13=reg18-reg13; reg17=reg16-reg17; reg7=reg6+reg7; reg2=vectors[0][indices[2]+2]-vectors[0][indices[0]+2];
    reg4=vectors[0][indices[1]+2]-vectors[0][indices[0]+2]; reg5=vectors[0][indices[1]+1]-vectors[0][indices[0]+1]; reg6=vectors[0][indices[2]+1]-vectors[0][indices[0]+1]; reg12=vectors[0][indices[2]+0]-vectors[0][indices[0]+0]; reg16=vectors[0][indices[1]+0]-vectors[0][indices[0]+0];
    reg8=reg8/reg7; reg17=reg17/reg7; reg13=reg13/reg7; reg9=reg9/reg7; reg14=reg14/reg7;
    reg3=reg0-reg3; reg15=reg15/reg7; reg10=reg1-reg10; reg0=reg9*reg2; reg1=vectors[0][indices[3]+2]-vectors[0][indices[0]+2];
    reg18=reg8*reg4; reg11=reg11/reg7; reg10=reg10/reg7; T reg19=reg15*reg12; T reg20=reg13*reg16;
    T reg21=reg14*reg12; T reg22=reg17*reg16; T reg23=reg9*reg6; T reg24=reg8*reg5; reg7=reg3/reg7;
    reg3=reg17*reg4; T reg25=reg14*reg2; T reg26=vectors[0][indices[3]+0]-vectors[0][indices[0]+0]; T reg27=reg15*reg6; T reg28=reg13*reg5;
    T reg29=vectors[0][indices[3]+1]-vectors[0][indices[0]+1]; reg19=reg20-reg19; reg27=reg28-reg27; reg20=reg7*reg29; reg28=reg11*reg1;
    T reg30=reg7*reg26; reg0=reg18-reg0; reg18=reg11*reg29; reg23=reg24-reg23; reg3=reg25-reg3;
    reg24=reg10*reg1; reg25=reg10*reg26; reg22=reg21-reg22; reg24=reg3-reg24; reg16=reg8*reg16;
    reg12=reg9*reg12; reg27=reg20+reg27; reg6=reg14*reg6; reg5=reg17*reg5; reg28=reg0+reg28;
    reg19=reg30+reg19; reg4=reg13*reg4; reg2=reg15*reg2; reg25=reg22-reg25; reg18=reg23+reg18;
    reg1=reg7*reg1; reg29=reg10*reg29; reg5=reg6-reg5; reg28=reg19+reg28; reg24=reg27+reg24;
    reg2=reg4-reg2; reg26=reg11*reg26; reg12=reg16-reg12; reg18=reg25+reg18; elem.epsilon[0][5]=0.5*reg24;
    elem.epsilon[0][3]=0.5*reg18; elem.epsilon[0][0]=reg12+reg26; elem.epsilon[0][2]=reg1+reg2; elem.epsilon[0][4]=0.5*reg28; elem.epsilon[0][1]=reg5-reg29;
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_2(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_3(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_4(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_5(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_6(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
  
  static const unsigned nb_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};

// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_true
#define ADD_NODAL_MATRIX_correlation_basic_false_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_true
#define ADD_NODAL_MATRIX_correlation_basic_true_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_false
#define ADD_NODAL_MATRIX_correlation_basic_false_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_false
#define ADD_NODAL_MATRIX_correlation_basic_true_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Tetra,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Triangle,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}

#ifndef correlation_basic_read_material_to_mesh
#define correlation_basic_read_material_to_mesh
template<class TM, class T, bool wont_add_nz>
void read_material_to_mesh_(const XmlNode &n, Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f){ 
  };
#endif // correlation_basic_read_material_to_mesh
} // namespace LMT


#include "formulation/formulation.h"
namespace LMT {
#ifndef CORRELATION_BASIC_3_NUM_0_CARAC_H
#define CORRELATION_BASIC_3_NUM_0_CARAC_H
#ifndef STRUCT_CORRELATION_BASIC
#define STRUCT_CORRELATION_BASIC
struct correlation_basic {
  static const char *name() { return "correlation_basic"; }
};
#endif // CORRELATION_BASIC

template<class P_T>
class CaracFormulation<correlation_basic,3,P_T>  {
public:
  typedef P_T T;
  static const char *name() { return "correlation_basic"; }
  static const bool matrix_will_be_definite_positive=true;
  static const bool has_nodal_matrix = false;
  static const bool has_IS_contact_matrix=false;
  static const bool need_skin_assembly=false;
  typedef Norm1_is_inf Name_convergence_criterium;
  static const unsigned nb_vectors = 4;
  static const unsigned nb_matrices = 1;
  static const unsigned auto_contact = false;
  static const bool friction_coeff_is_a_nodal_variable = 0;
  static const unsigned offset_of_pos_unknown=3;
  static const unsigned pos_is_an_unknown = false;
  static const unsigned nb_der_var = 0;
  template<class TF> static void add_to_der_vars( TF &f, const Vec<T> &v ) {
  }
  static bool is_unknown(const std::string &s) { return (s=="dep" || s=="lum"); }
  static unsigned num_in_vec_unknown(const std::string &s) { if ( s=="dep" )return 0; if ( s=="lum" )return 3; return 0;  }
  template<unsigned num_mat,unsigned inner=0> struct NodalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  template<unsigned num_mat,unsigned inner=0> struct GlobalMatricesCarac {
      static const bool symm = 1;
      static const bool herm = false;
      static const bool diag = false;
  };
  
  static const unsigned nb_nodal_unknowns = 4;
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
    node.lum=vecs[0][indice+3]; node.dep[1]=vecs[0][indice+1]; node.dep[0]=vecs[0][indice+0]; node.dep[2]=vecs[0][indice+2];
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
    node.dep[0]=vecs[0][indice+0]; node.lum=vecs[0][indice+3]; node.dep[1]=vecs[0][indice+1]; node.dep[2]=vecs[0][indice+2];
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
    vecs[0][indice+0]=node.dep[0]; vecs[1][indice+0]=node.dep[0]; vecs[2][indice+0]=node.dep[0]; vecs[3][indice+0]=node.dep[0]; vecs[4][indice+0]=node.dep[0];
    vecs[0][indice+2]=node.dep[2]; vecs[1][indice+2]=node.dep[2]; vecs[2][indice+2]=node.dep[2]; vecs[3][indice+2]=node.dep[2]; vecs[4][indice+2]=node.dep[2];
    vecs[0][indice+1]=node.dep[1]; vecs[1][indice+1]=node.dep[1]; vecs[2][indice+1]=node.dep[1]; vecs[3][indice+1]=node.dep[1]; vecs[4][indice+1]=node.dep[1];
    vecs[0][indice+3]=node.lum; vecs[1][indice+3]=node.lum; vecs[2][indice+3]=node.lum; vecs[3][indice+3]=node.lum; vecs[4][indice+3]=node.lum;
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    T reg0=vecs[1][indice+0]-vecs[0][indice+0]; T reg1=vecs[1][indice+1]-vecs[0][indice+1]; reg1=abs(reg1); T reg2=vecs[1][indice+2]-vecs[0][indice+2]; reg0=abs(reg0);
    T reg3=vecs[1][indice+3]-vecs[0][indice+3]; reg2=abs(reg2); reg0=max(reg1,reg0); reg3=abs(reg3); reg0=max(reg2,reg0);
    return max(reg3,reg0);
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
    old_vec[indice+0]=vecs[1][indice+0]; old_vec[indice+1]=vecs[1][indice+1]; old_vec[indice+2]=vecs[1][indice+2]; old_vec[indice+3]=vecs[1][indice+3];
  }
  
  static const unsigned nb_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_nodal_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_nodal_unknowns(TE &node,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_nodal_initial_conditions(const TE &node,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_nodal_error(const TE &node,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_nodal(const TE &node,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_global_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_global_unknowns(TE &mesh,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_global_initial_conditions(const TE &mesh,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_global_error(const TE &mesh,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_global(const TE &mesh,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};
#endif // CORRELATION_BASIC_3_NUM_0_CARAC_H
extern "C" void apply_on_elements_after_solve_0_correlation_basic_Hexa_0( double * );
extern "C" void apply_on_elements_after_solve_1_correlation_basic_Hexa_1( double * );
extern "C" void apply_on_elements_after_solve_2_correlation_basic_Hexa_2( double * );
extern "C" void apply_on_elements_after_solve_3_correlation_basic_Hexa_3( double * );
extern "C" void apply_on_elements_after_solve_4_correlation_basic_Hexa_4( double * );
extern "C" void apply_on_elements_after_solve_5_correlation_basic_Hexa_5( double * );
class Hexa;
template<unsigned A,class B,class C> class Node;
template<class A,class B,class C,class D,unsigned E> class Element;

// Carac for ...
template<class P_T_pos,class P_ND,class TED,unsigned nim,class TM,class T>
class CaracFormulationForElement<correlation_basic,Element<Hexa,DefaultBehavior,Node<3,P_T_pos,P_ND>,TED,nim>,TM,T> {
public:
    template<unsigned num_mat,unsigned inner=0> struct ElemMatricesCarac {
        static const bool symm = true;
        static const bool herm = false;
        static const bool diag = false;
        static const bool linear = true;
    };
    static const unsigned order_integration = 2;
    static const bool has_elementary_matrix = false;
    static const bool has_skin_elementary_matrix = false;
    template<class TE,class TF, class TVEVE> static void after_solve(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
    T reg0=0.25*elem.pos(1)[1]; T reg1=0.25*elem.pos(0)[1]; T reg2=0.25*elem.pos(1)[2]; T reg3=0.25*elem.pos(0)[2]; T reg4=0.25*elem.pos(2)[2];
    T reg5=reg3+reg2; T reg6=reg0-reg1; reg3=reg2-reg3; reg2=0.25*elem.pos(2)[1]; reg0=reg1+reg0;
    reg1=0.25*elem.pos(3)[1]; reg3=reg4+reg3; T reg7=reg2-reg0; reg6=reg2+reg6; T reg8=0.25*elem.pos(0)[0];
    T reg9=reg5+reg4; reg0=reg2+reg0; reg5=reg4-reg5; reg2=0.25*elem.pos(1)[0]; reg4=0.25*elem.pos(3)[2];
    reg9=reg9+reg4; reg6=reg6-reg1; reg5=reg4+reg5; reg7=reg7+reg1; T reg10=0.25*elem.pos(4)[1];
    reg0=reg1+reg0; reg4=reg3-reg4; reg1=0.25*elem.pos(2)[0]; reg3=reg2-reg8; reg8=reg2+reg8;
    reg2=0.25*elem.pos(4)[2]; reg0=reg10-reg0; reg5=reg5-reg2; reg7=reg7-reg10; T reg11=0.25*elem.pos(5)[1];
    reg9=reg2-reg9; T reg12=0.25*elem.pos(5)[2]; reg10=reg6-reg10; reg3=reg3+reg1; reg6=0.25*elem.pos(3)[0];
    reg2=reg4-reg2; reg4=reg1-reg8; reg9=reg9+reg12; T reg13=0.25*elem.pos(6)[2]; reg4=reg6+reg4;
    reg5=reg5-reg12; reg0=reg11+reg0; reg10=reg11+reg10; reg3=reg3-reg6; reg8=reg1+reg8;
    reg11=reg7-reg11; reg1=0.25*elem.pos(6)[1]; reg2=reg12+reg2; reg7=0.25*elem.pos(4)[0]; reg12=0.25*vectors[0][indices[1]+0];
    T reg14=0.25*vectors[0][indices[0]+0]; T reg15=0.25*vectors[0][indices[0]+1]; reg3=reg3-reg7; T reg16=0.25*elem.pos(5)[0]; reg0=reg1+reg0;
    T reg17=0.25*vectors[0][indices[0]+2]; T reg18=0.25*vectors[0][indices[1]+2]; reg2=reg13+reg2; T reg19=0.25*vectors[0][indices[1]+1]; reg10=reg1+reg10;
    reg1=reg11+reg1; reg11=0.25*elem.pos(7)[1]; reg8=reg6+reg8; reg9=reg9+reg13; reg6=0.25*elem.pos(7)[2];
    reg5=reg13+reg5; reg4=reg4-reg7; reg10=reg10-reg11; reg8=reg7-reg8; reg4=reg4-reg16;
    reg2=reg2-reg6; reg7=reg17+reg18; reg13=0.25*vectors[0][indices[2]+2]; T reg20=reg15+reg19; reg15=reg19-reg15;
    reg19=reg12+reg14; reg17=reg18-reg17; reg18=0.25*vectors[0][indices[2]+1]; reg1=reg1+reg11; T reg21=0.25*vectors[0][indices[2]+0];
    reg9=reg9+reg6; reg14=reg12-reg14; reg5=reg6+reg5; reg0=reg11+reg0; reg3=reg3+reg16;
    reg6=0.25*elem.pos(6)[0]; reg11=reg21-reg19; reg12=0.25*vectors[0][indices[3]+1]; T reg22=reg18-reg20; reg15=reg18+reg15;
    T reg23=reg13-reg7; T reg24=0.25*vectors[0][indices[3]+0]; reg14=reg14+reg21; reg8=reg16+reg8; reg16=reg0*reg2;
    T reg25=reg9*reg10; reg4=reg6+reg4; T reg26=0.25*vectors[0][indices[3]+2]; T reg27=reg1*reg9; reg17=reg13+reg17;
    T reg28=0.25*elem.pos(7)[0]; T reg29=reg5*reg0; reg3=reg3+reg6; reg15=reg15-reg12; reg23=reg26+reg23;
    T reg30=0.25*vectors[0][indices[4]+1]; reg17=reg17-reg26; reg11=reg24+reg11; reg22=reg22+reg12; T reg31=0.25*vectors[0][indices[4]+0];
    reg19=reg21+reg19; reg14=reg14-reg24; reg29=reg27-reg29; reg20=reg18+reg20; reg18=0.25*vectors[0][indices[4]+2];
    reg21=reg1*reg2; reg27=reg5*reg10; reg3=reg3-reg28; reg8=reg6+reg8; reg13=reg7+reg13;
    reg4=reg28+reg4; reg16=reg25-reg16; reg23=reg23-reg18; reg22=reg22-reg30; reg6=0.25*vectors[0][indices[5]+1];
    reg15=reg15-reg30; reg20=reg12+reg20; reg26=reg13+reg26; reg7=0.25*vectors[0][indices[5]+2]; reg17=reg17-reg18;
    reg12=reg29*reg3; reg19=reg24+reg19; reg13=reg4*reg16; reg14=reg14-reg31; reg24=0.25*vectors[0][indices[5]+0];
    reg11=reg11-reg31; reg21=reg27-reg21; reg8=reg28+reg8; reg25=reg9*reg4; reg27=reg5*reg8;
    reg13=reg12-reg13; reg12=0.25*vectors[0][indices[6]+0]; reg14=reg14+reg24; reg15=reg6+reg15; reg28=reg8*reg21;
    T reg32=reg0*reg3; T reg33=reg10*reg8; reg20=reg30-reg20; reg19=reg31-reg19; reg23=reg23-reg7;
    reg9=reg9*reg3; reg30=reg2*reg8; reg8=reg1*reg8; reg0=reg0*reg4; reg17=reg7+reg17;
    reg31=0.25*vectors[0][indices[6]+2]; reg11=reg11-reg24; reg26=reg18-reg26; reg22=reg22-reg6; reg18=0.25*vectors[0][indices[6]+1];
    T reg34=0.25*vectors[0][indices[7]+2]; reg17=reg31+reg17; reg7=reg26+reg7; reg8=reg0-reg8; reg10=reg4*reg10;
    reg1=reg1*reg3; reg20=reg6+reg20; reg28=reg13+reg28; reg19=reg24+reg19; reg33=reg32-reg33;
    reg23=reg31+reg23; reg2=reg4*reg2; reg3=reg5*reg3; reg22=reg22+reg18; reg30=reg9-reg30;
    reg0=0.25*vectors[0][indices[7]+1]; reg11=reg12+reg11; reg4=0.25*vectors[0][indices[7]+0]; reg15=reg18+reg15; reg14=reg14+reg12;
    reg27=reg25-reg27; reg16=reg16/reg28; reg31=reg7+reg31; reg11=reg4+reg11; reg23=reg34+reg23;
    reg30=reg30/reg28; reg8=reg8/reg28; reg19=reg12+reg19; reg14=reg14-reg4; reg22=reg22+reg0;
    reg27=reg27/reg28; reg17=reg17-reg34; reg10=reg1-reg10; reg15=reg15-reg0; reg33=reg33/reg28;
    reg20=reg18+reg20; reg2=reg3-reg2; reg29=reg29/reg28; reg1=reg15*reg8; reg3=reg22*reg33;
    reg5=reg11*reg33; reg6=reg14*reg27; reg7=reg11*reg30; reg34=reg31+reg34; reg10=reg10/reg28;
    reg9=reg30*reg23; reg20=reg0+reg20; reg2=reg2/reg28; reg0=reg27*reg17; reg12=reg14*reg8;
    reg13=reg29*reg17; reg18=reg29*reg15; reg24=reg16*reg22; reg19=reg4+reg19; reg28=reg21/reg28;
    reg4=reg16*reg23; reg21=reg20*reg10; reg25=reg28*reg20; reg24=reg18-reg24; reg18=reg19*reg2;
    reg6=reg7-reg6; reg5=reg12-reg5; reg3=reg1-reg3; reg1=reg19*reg10; reg0=reg9-reg0;
    reg7=reg2*reg34; reg4=reg13-reg4; reg9=reg28*reg34; reg1=reg5+reg1; reg9=reg4+reg9;
    reg25=reg24+reg25; reg18=reg6-reg18; reg23=reg33*reg23; reg17=reg8*reg17; reg3=reg21+reg3;
    reg15=reg27*reg15; reg22=reg30*reg22; reg7=reg0-reg7; reg11=reg16*reg11; reg14=reg29*reg14;
    reg9=reg1+reg9; reg7=reg3+reg7; reg25=reg18+reg25; reg23=reg17-reg23; reg34=reg10*reg34;
    reg20=reg2*reg20; reg15=reg22-reg15; reg19=reg28*reg19; reg11=reg14-reg11; elem.epsilon[0][3]=0.5*reg25;
    elem.epsilon[0][4]=0.5*reg9; elem.epsilon[0][2]=reg34+reg23; elem.epsilon[0][1]=reg15-reg20; elem.epsilon[0][0]=reg11+reg19; elem.epsilon[0][5]=0.5*reg7;
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_2(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_3(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_4(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_5(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
    template<class TE,class TF, class TVEVE> static void after_solve_6(TE &elem,TF &f,TVEVE &vectors,const unsigned *indices) {
      #define PNODE(N) (*elem.node(N))
      #undef PNODE
    }
  
  static const unsigned nb_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
  
  static const unsigned nb_skin_elementary_unknowns = 0;
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void set_skin_elementary_unknowns(TE &elem,const TTs &f,const Tvec &vecs,unsigned indice,T partial_ts) {
  }
  template<class TE,class TTs,class Tvec>
  inline static void get_skin_elementary_initial_conditions(const TE &elem,const TTs &f,Tvec &vecs,unsigned indice) {
  }
  template<class TE,class TTs,class Tvec>
  inline static T max_skin_elementary_error(const TE &elem,const TTs &f,const Tvec &vecs,int indice) {
    return 0;
  }
  template<class TE,class TTs,class Tvecs,class Tvec>
  inline static void set_old_vec_skin_elementary(const TE &elem,const TTs &f,const Tvecs &vecs,Tvec &old_vec,int indice) {
  }
};

// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class T,class TM,bool wont_add_nz,class TMA,class TVE,class TVEVE,class T_pos,class ND,class ED,unsigned nim,unsigned symmetric_version>
void add_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const unsigned *indices){ 
  #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_true
#define ADD_NODAL_MATRIX_correlation_basic_false_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_true
#define ADD_NODAL_MATRIX_correlation_basic_true_true_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_false_true_false
#define ADD_NODAL_MATRIX_correlation_basic_false_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_true_true_false
#define ADD_NODAL_MATRIX_correlation_basic_true_true_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE >
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_true
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
#ifndef ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
#define ADD_NODAL_MATRIX_correlation_basic_symmetric_version_false_false
template<class TM,class T,bool wont_add_nz,class TMA,class TVE,class TVEVE ,unsigned symmetric_version>
void add_nodal_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const typename TM::TNode &node,
      const unsigned *indices){ 
  #define PNODE(N) node
  #undef PNODE
}
#endif
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<0> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<1> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<2> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<3> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<4> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<4> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<4> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<4> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<4> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<4> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<5> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<5> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<false> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<5> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<true> &matrix_is_sym,
      const Number<true> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<5> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<true> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<5> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}
// 
template<class TM,class T,bool wont_add_nz,class TMA, class TVE,class TVEVE, class T_pos, class ND,class ED, unsigned nim,class ED2,unsigned nim2,unsigned symmetric_version>
void add_skin_elem_matrix(
      Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f,
      TMA &matrix,
      TVE &sollicitation,
      TVEVE &vectors,
      const Number<symmetric_version> &matrix_is_sym,
      const Number<false> &assemble_mat,
      const Number<false> &assemble_vec,
      const Element<Hexa,DefaultBehavior,Node<3,T_pos,ND>,ED,nim> &elem,
      const Element<Quad,DefaultBehavior,Node<3,T_pos,ND>,ED2,nim2> &skin_elem,
      const Number<5> &num_child,
      const unsigned *indices){
   #define PNODE(N) (*elem.node(N))
  #undef PNODE
}

#ifndef correlation_basic_read_material_to_mesh
#define correlation_basic_read_material_to_mesh
template<class TM, class T, bool wont_add_nz>
void read_material_to_mesh_(const XmlNode &n, Formulation<TM,correlation_basic,DefaultBehavior,T,wont_add_nz> &f){ 
  };
#endif // correlation_basic_read_material_to_mesh
} // namespace LMT


#endif // PROBLEM_pb_correlation_basic
