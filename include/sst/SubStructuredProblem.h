#ifndef SUBSTRUCTURED_PROBLEM_H
#define SUBSTRUCTURED_PROBLEM_H

#include <containers/apply_ij.h>

namespace LMT {

struct SubStructureAncestor {
    unsigned number;
};

struct InterfaceAncestor {
    unsigned number;
};

template<class TM_>
struct InterfaceAncestorWoWOMesh : public InterfaceAncestor {
    typedef TM_ TM;
    static const bool has_mesh = true;
    
    TM mesh;
};

template<>
struct InterfaceAncestorWoWOMesh<void> : public InterfaceAncestor {
    static const bool has_mesh = false;
};

template<class TM_>
struct SubStructureAncestorWoWOMesh : public SubStructureAncestor {
    typedef TM_ TM;
    static const bool has_mesh = true;
    
    TM mesh;
    Vec<bool> used_skin_elem;
};

template<>
struct SubStructureAncestorWoWOMesh<void> : public InterfaceAncestor {
    static const bool has_mesh = false;
};


/*!

*/
template<class TData_>
struct SubStructure : TData_, SubStructureAncestorWoWOMesh<typename TData_::TM> {
    typedef TData_ TData;
    typedef typename TData_::TM TM;
    
    Vec<InterfaceAncestor *> interfaces;
};

/**

*/
template<class TData_,class SstData0,class SstData1=void>
struct Interface : TData_, InterfaceAncestorWoWOMesh<typename TData_::TM> {
    typedef SubStructure<SstData0> TSubStructure0;
    typedef SubStructure<SstData1> TSubStructure1;
    typedef TData_ TData;
    typedef typename TData_::TM TM;
    
    TSubStructure0 *sub_structure0;
    TSubStructure1 *sub_structure1;
    typename IntersectionCarac<typename TSubStructure0::TM::TSkin::TElemList,typename TM::TElemList>::T sst0_and_interf_element_pairs;
    typename IntersectionCarac<typename TSubStructure1::TM::TSkin::TElemList,typename TM::TElemList>::T sst1_and_interf_element_pairs;
};

/**

*/
template<class TData_,class SstData>
struct Interface<TData_,SstData> : TData_, InterfaceAncestorWoWOMesh<typename TData_::TM> {
    typedef SubStructure<SstData> TSubStructure;
    typedef TData_ TData;
    typedef typename TData_::TM TM;
    
    TSubStructure *sub_structure;
    typename IntersectionCarac<typename TSubStructure::TM::TSkin::TElemList,typename TM::TElemList>::T sst_and_interf_element_pairs;
};

/*!

*/
template<class SubStructuresData,class InternalInterfacesData,class ExternalInterfacesData>
struct SubStructuredProblem {
    //
    struct SubStructuresHeterogeneousCarac {
        template<unsigned n> struct SubType {
            typedef typename AlternativeOnType<
                AreSameType<typename SubStructuresData::template SubType<n>::T,void>::res,
                Splitted<SubStructure<typename SubStructuresData::template SubType<n>::T>,8>,
                void
            >::T T;
        };
    };
    //
    typedef Vec<Heterogeneous<SubStructuresHeterogeneousCarac> > TSubStructuresList;
    //
    static const unsigned nb_sub_structure_types = TSubStructuresList::nb_sub_type;
    
    
    //
    static const unsigned nb_internal_interface_data_types = NbSubTypes<InternalInterfacesData>::res;
    //
    static const unsigned nb_external_interface_data_types = NbSubTypes<ExternalInterfacesData>::res;
    //
    static const unsigned nb_interface_types = 
        nb_sub_structure_types * nb_sub_structure_types * nb_internal_interface_data_types +
        nb_sub_structure_types * nb_external_interface_data_types;
    
    //
    struct InterfacesHeterogeneousCarac {
        template<unsigned n> struct SubType {
            static const unsigned num_internal_sst_set    = n / nb_internal_interface_data_types;
            static const unsigned num_internal_inter_data = n % nb_internal_interface_data_types;
            static const unsigned num_external_sst_set    = ( n - nb_internal_interface_data_types ) / nb_external_interface_data_types;
            static const unsigned num_external_inter_data = ( n - nb_internal_interface_data_types ) % nb_external_interface_data_types;
            typedef typename AlternativeOnType<
                ( n >= nb_internal_interface_data_types ) + ( n >= nb_interface_types ),
                Splitted<Interface<
                    typename InternalInterfacesData::template SubType<num_internal_inter_data                      >::T,
                    typename SubStructuresData     ::template SubType<num_internal_sst_set / nb_sub_structure_types>::T,
                    typename SubStructuresData     ::template SubType<num_internal_sst_set % nb_sub_structure_types>::T
                >,8>,
                Splitted<Interface<
                    typename ExternalInterfacesData::template SubType<num_external_inter_data                      >::T,
                    typename SubStructuresData     ::template SubType<num_external_sst_set                         >::T,
                    void
                >,8>,
                void
            >::T T;
        };
    };
    //
    typedef Vec<Heterogeneous<InterfacesHeterogeneousCarac> > TInterfacesList;
    
    //
    struct UpdateNumber { template<class TS> void operator()( TS &s, unsigned &i ) const { s.number = i++; } };
    
    //
    template<class MyData>
    SubStructure<MyData> *new_sub_structure() {
        SubStructure<MyData> *res = sub_structures.new_elem( StructForType< SubStructure<MyData> >() );
        unsigned i = 0; apply( sub_structures, UpdateNumber(), i );
        return res;
    }
    
    //
    template<class MyData,class MySstData0,class MySstData1>
    Interface<MyData,MySstData0,MySstData1> *new_interface( SubStructure<MySstData0> *s0, SubStructure<MySstData1> *s1 ) {
        typedef Interface<MyData,MySstData0,MySstData1> TRes;
        TRes *res = interfaces.new_elem( StructForType<TRes>() );
        res->sub_structure0 = s0;
        res->sub_structure1 = s1;
        s0->interfaces.push_back( res );
        s1->interfaces.push_back( res );
        //
        unsigned i = 0; apply( interfaces, UpdateNumber(), i );
        return res;
    }
    
    //
    template<class MyData,class MySstData>
    Interface<MyData,MySstData> *new_interface( SubStructure<MySstData> *s0 ) {
        typedef Interface<MyData,MySstData> TRes;
        TRes *res = interfaces.new_elem( StructForType<TRes>() );
        res->sub_structure = s0;
        s0->interfaces.push_back( res );
        //
        unsigned i = 0; apply( interfaces, UpdateNumber(), i );
        return res;
    }
    
    struct FindInterfBetween {
        template<class TI> bool operator()() const {
        }
    };
    
    //
    template<class MyData,class MySstData0,class MySstData1>
    Interface<MyData,MySstData0,MySstData1> *interface( SubStructure<MySstData0> *s0, SubStructure<MySstData1> *s1 ) {
        typedef Interface<MyData,MySstData0,MySstData1> T;
        Vec<Splitted<T,8> > &v = interfaces.sub_vec( StructForType<Interface<MyData,MySstData0,MySstData1> >() );
        for(unsigned i=0;i<v.size();++i)
            if ( v[i].sub_structure0 == s0 and v[i].sub_structure1 == s1 )
                return &v[i];
        return new_interface<MyData>( s0, s1 );
    }
    
    
    void read_xml( XmlNode &xn ) {
    }
    
    //
    struct AddElementInInterface {
        //
        template<class TE,class Interf>
        typename Interf::TM::template TElem<typename TE::NE,typename TE::BE>::TE *add( const TE &elem, Interf *interface ) {
            unsigned node_numbers[ TE::nb_nodes ];
            for(unsigned i=0;i<TE::nb_nodes;++i) {
                if ( s_node_number_to_interface_node_number[ elem.node(i)->number ] < 0 ) {
                    s_node_number_to_interface_node_number[ elem.node(i)->number ] = interface->mesh.node_list.size(); 
                    interface->mesh.add_node( elem.node(i)->pos );
                }
                node_numbers[ i ] = s_node_number_to_interface_node_number[ elem.node(i)->number ];
            }
            typename Interf::TM::template TElem<typename TE::NE,typename TE::BE>::TE *res = interface->mesh.add_element( typename TE::NE(), typename TE::BE(), node_numbers );
            return res;
        }
        
        //
        template<class TE,class Interf> void operator()( const TE &elem, Interf *interface, Number<0> ) {}
        //
        template<class TE,class Interf>
        void operator()( TE &elem, Interf *interface, Number<1> ) {
            interface->sst_and_interf_element_pairs.push_back( std::make_pair( &elem, add( elem, interface ) ) );
        }
        /*
main_latin.cpp:88: instantiated from here
/usr/include/c++/4.3/bits/stl_pair.h:106: error: invalid conversion from '
LMT::Element<LMT::Triangle, LMT::DefaultBehavior, LMT::Node<3u, double, LMT::Mesh_carac_mon_probleme<double, 3u>::NodalStaticData>, LMT::Mesh_carac_mon_probleme<double, 3u>::ElementChoice<1u, 1u, 0u, 0u>::TData, 0u>*
LMT::Element<LMT::Triangle, LMT::DefaultBehavior, LMT::Node<3u, double, LMT::Mesh_carac_mon_probleme<double, 3u>::NodalStaticData>, LMT::Mesh_carac_mon_probleme<double, 3u>::ElementChoice<1u, 1u, 0u, 0u>::TData, 0u>*
scons: *** [main_latin.o] Error 1
scons: building terminated because of errors.
        
        */
        //
        template<class TE0,class TE1,class Interf> void operator()( const TE0 &elem_0, const TE1 &elem_1, Interf *interface, Number<0> ) {}
        //
        template<class TE0,class TE1,class Interf>
        void operator()( TE0 &elem_0, TE1 &elem_1, Interf *interface, Number<1> ) {
            typename Interf::TM::template TElem<typename TE0::NE,typename TE0::BE>::TE *res = add( elem_0, interface );
            interface->sst0_and_interf_element_pairs.push_back( std::make_pair( &elem_0, res ) );
            interface->sst1_and_interf_element_pairs.push_back( std::make_pair( &elem_1, res ) );
        }
        //
        Vec<int> s_node_number_to_interface_node_number;
    };
    
    template<class Sst0,class Sst1,class MyData>
    struct UpdateInterfacesWithElements {
        typedef typename Sst0::TData SstData0;
        typedef typename Sst1::TData SstData1;
        typedef Interface<MyData,SstData0,SstData1> Interf;
        
        UpdateInterfacesWithElements() : interface( NULL ) {}
        
        template<class TE0,class TE1> void operator()( TE0 &e0, unsigned n0, TE1 &e1, unsigned n1, SubStructuredProblem &ssp ) {
            if ( length( center(e0) - center(e1) ) <= tol ) {
                if ( not interface )
                    interface = ssp.template interface<MyData>( s0, s1 );
                aii( e0, e1, interface, Number<Interf::has_mesh>() );
                //
                s0->used_skin_elem[ e0.absolute_number ] = true;
                s1->used_skin_elem[ e1.absolute_number ] = true;
            }
        }
       
        Sst0 *s0;
        Sst1 *s1;
        double tol;
        Interf *interface;
        AddElementInInterface aii;
    };
    
    template<class MyData>
    struct UpdateInterfaces {
        // 2 sst
        template<class Sst0,class Sst1> void operator()( Sst0 &s0, unsigned n0, Sst1 &s1, unsigned n1, SubStructuredProblem &ssp ) const {
            UpdateInterfacesWithElements<Sst0,Sst1,MyData> uiwe;
            uiwe.s0 = &s0;
            uiwe.s1 = &s1;
            uiwe.tol = tol;
            uiwe.aii.s_node_number_to_interface_node_number.resize( s0.mesh.node_list.size(), -1 );
            apply_ij( s0.mesh.skin.elem_list, s1.mesh.skin.elem_list, uiwe, ssp );
        }
        // 1 sst
        template<class Sst> void operator()( Sst &s, SubStructuredProblem &ssp ) const {
            typedef Interface<MyData,typename Sst::TData> Interf;
            //
            s.mesh.skin.update_elem_neighbours();
            for(unsigned num_front_skin_elem=0;;++num_front_skin_elem) {
                if ( num_front_skin_elem == s.used_skin_elem.size() )
                    return;
                //
                if ( s.used_skin_elem[ num_front_skin_elem ] ) 
                    continue;
                //
                Interf *interface = ssp.new_interface<MyData>( &s );
                AddElementInInterface aii;
                aii.s_node_number_to_interface_node_number.resize( s.mesh.node_list.size(), -1 );
                //
                typedef typename Sst::TM::TSkin::EA EA;
                Vec<EA *> front;
                front.push_back( s.mesh.skin.elem_list[ num_front_skin_elem ] );
                while ( front.size() ){
                    EA *elem = front.back(); front.pop_back();
                    s.used_skin_elem[ elem->absolute_number ] = true;
                    Sst::TM::TSkin::TElemList::apply_on_down_cast( elem, aii, interface, Number<Interf::has_mesh>() );
                    //
                    for(SimpleConstIterator<EA *> iter = s.mesh.skin.get_elem_neighbours_EA( elem ); iter; ++iter )
                        if ( s.used_skin_elem[ (*iter)->absolute_number ] == false and dot( elem->sample_normal_virtual(), (*iter)->sample_normal_virtual() ) >= 0.9 )
                            front.push_back( *iter );
                }
            }
        }
        //
        double tol;
    };
    
    struct UpdateSkinMesh {
        template<class Sst> void operator()( Sst &s ) const {
            s.mesh.update_skin();
            s.used_skin_elem.resize( s.mesh.skin.elem_list.size(), false );
            s.mesh.skin.absolute_number_update();
        }
    };
    
    /// -> crée des interfaces avec les données par défaut
    void update_interfaces( double tol = 1e-6 /*hum !!*/ ) {
        apply( sub_structures, UpdateSkinMesh() );
        // internal
        UpdateInterfaces<typename InternalInterfacesData::template SubType<0>::T> uii; uii.tol = tol;
        apply_i_sup_j( sub_structures, sub_structures, uii, *this );
        // external
        UpdateInterfaces<typename ExternalInterfacesData::template SubType<0>::T> uie; uie.tol = tol;
        apply( sub_structures, uie, *this );
    }
    
    //
    TSubStructuresList sub_structures;
    TInterfacesList    interfaces;
};


}

#endif //SUBSTRUCTURED_PROBLEM_H
