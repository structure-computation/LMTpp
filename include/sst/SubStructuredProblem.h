#ifndef SUBSTRUCTURED_PROBLEM_H
#define SUBSTRUCTURED_PROBLEM_H

namespace LMT {

struct SubStructureAncestor {
};

struct InterfaceAncestor {
};

/**

*/
template<class TData>
struct SubStructure : TData, SubStructureAncestor {
    Vec<InterfaceAncestor *> interfaces;
};

/**

*/
template<class SstData0,class SstData1,class TData>
struct Interface : TData, InterfaceAncestor {
    typedef SubStructure<SstData0> TSubStructure0;
    typedef SubStructure<SstData1> TSubStructure1;
    
    TSubStructure0 *sub_structure0;
    TSubStructure1 *sub_structure1;
};

/**

*/
template<class SubStructuresData,class InternalInterfacesData,class ExternalInterfacesData>
struct SubStructuredProblem {
    //
    struct SubStructuresHeterogeneousCarac {
        template<unsigned n> struct SubType {
            typedef typename AlternativeOnType<
                AreSameType <typename SubStructuresData::template SubType<n>::T,void>::res,
                SubStructure<typename SubStructuresData::template SubType<n>::T>,
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
                Interface<
                    typename SubStructuresData     ::template SubType<num_internal_sst_set / nb_sub_structure_types>::T,
                    typename SubStructuresData     ::template SubType<num_internal_sst_set % nb_sub_structure_types>::T,
                    typename InternalInterfacesData::template SubType<num_internal_inter_data                      >::T
                >,
                Interface<
                    typename SubStructuresData     ::template SubType<num_external_sst_set                         >::T,
                    void,
                    typename ExternalInterfacesData::template SubType<num_external_inter_data                      >::T
                >,
                void
            >::T T; 
        };
    };
    //
    typedef Vec<Heterogeneous<InterfacesHeterogeneousCarac> > TInterfacesList;
    
    //
    template<class MyData>
    SubStructure<MyData> *new_sub_structure() { return sub_structures.new_elem( StructForType< SubStructure<MyData> >() ); }
    
    //
    template<class MyData,class MySstData0,class MySstData1>
    Interface<MySstData0,MySstData1,MyData> *new_interface( SubStructure<MySstData0> *s0, SubStructure<MySstData1> *s1 ) {
        typedef Interface<MySstData0,MySstData1,MyData> TRes;
        TRes *res = interfaces.new_elem( StructForType<TRes>() );
        res->sub_structure0 = s0;
        res->sub_structure1 = s1;
        s0->interfaces.push_back( res );
        s1->interfaces.push_back( res );
        return res;
    }
    
    //
    template<class MyData,class MySstData>
    Interface<MySstData,void,MyData> *new_interface( SubStructure<MySstData> *s0 ) {
        typedef Interface<MySstData,void,MyData> TRes;
        TRes *res = interfaces.new_elem( StructForType<TRes>() );
        res->sub_structure0 = s0;
        s0->interfaces.push_back( res );
        return res;
    }
    
    
    
    void read_xml( XmlNode &xn ) {
    }
    
    
    
    
    
    
    
    
    
    
    //
    TSubStructuresList sub_structures;
    TInterfacesList    interfaces;
};


}

#endif //SUBSTRUCTURED_PROBLEM_H
