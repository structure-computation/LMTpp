#ifndef MESH_INTERPOLATION_H
#define MESH_INTERPOLATION_H

namespace LMT {

struct FindEnglobingElementAndReturnInterpolationException {
};

template<class TM,class NameDM>
struct TypeOfVariableInterpolationInMesh {
    typedef typename TM::TNode::template SubTypeByName0<NameDM>::TT TypeIfNodal;
    typedef typename TM::Carac::template ElementChoice<0,0,0,0>::TData::template SubTypeByName0<NameDM>::TT TypeIfElementary;
    static const int type_interpolation = AreSameType<TypeIfNodal,void>::res; // 0 -> nodal, 1 -> elementary
    typedef typename AlternativeOnType<
        type_interpolation,
        TypeIfNodal,
        TypeIfElementary
    >::T T;
    
    template<class TE,class TV>
    void interp( const TE &elem, const TV &var_inter, Number<0> ) { // nodal
        T val[TE::nb_nodes];
        ExtractDM<NameDM> extract_NameDM_value;
        for(int i=0;i<TE::nb_nodes;++i)
            val[ i ] = extract_NameDM_value( *elem.node(i) );
        get_interp( typename TE::NE(), Nodal(), var_inter, val, res );
    }
    
    template<class TE,class TV>
    void interp( const TE &elem, const TV &var_inter, Number<1> ) { // elementary
        ExtractDM<NameDM> extract_NameDM_value;
        res = extract_NameDM_value( elem );
    }
    
    template<class TE>
    bool operator()( const TE &elem, const typename TE::Pvec &pos ) {
        Vec<typename TE::T,TE::nb_var_inter> var_inter;
        get_var_inter( elem, pos, var_inter, 1e-4 );
        if ( var_inter_is_inside( typename TE::NE(), var_inter, 1e-6 ) ) {
            interp( elem, var_inter, Number<type_interpolation>() );
            return true;
        }
        return false;
    }
    
    T res;
};

template<class Carac,unsigned nvi_to_subs,unsigned skin,class NameDM,class Pvec>
typename TypeOfVariableInterpolationInMesh<MeshAncestor<Carac,nvi_to_subs,skin>,NameDM>::T interpolation( const MeshAncestor<Carac,nvi_to_subs,skin> &m, NameDM, const Pvec &pos ) {
    typedef TypeOfVariableInterpolationInMesh<MeshAncestor<Carac,nvi_to_subs,skin>,NameDM> Tof;
    Tof tof;
    if ( not find( m.elem_list, tof, pos ) )
        throw FindEnglobingElementAndReturnInterpolationException();
    return tof.res;
}

struct MatrixSimpleInterpolation {
    template<class TE,class Pvec,class V>
    bool operator()( const TE &elem, const Pvec &pos, V &row ) {
        Vec<typename TE::T,TE::nb_var_inter> var_inter;
        get_var_inter( elem, pos, var_inter, 1e-4 );
        if ( var_inter_is_inside( typename TE::NE(), var_inter, 1e-6 ) ) {
            Vec<typename TE::T,TE::nb_nodes> shape_functions;
            get_shape_functions( typename TE::NE(), var_inter, shape_functions );
            for(unsigned i=0;i<TE::nb_nodes;++i)
                row[ elem.node( i )->number ] = shape_functions[ i ];
            return true;
        }
        return false;
    }
};

/*
    find a such as m_left = A * m_right (simple collocation)
*/
template<class TM1,class TM2,class Mat>
void simple_interpolation_matrix( const TM1 &m_left, const TM2 &m_right, Mat &A ) {
    //     typedef typename TM1::TNode::template SubTypeByName0<NameDM>::TT TypeIfNodal1;
    //     typedef typename TM2::TNode::template SubTypeByName0<NameDM>::TT TypeIfNodal2;
    //     assert( not AreSameType<TypeIfNodal1,void>::res );
    //     assert( not AreSameType<TypeIfNodal2,void>::res );
    A.resize( m_left.node_list.size(), m_right.node_list.size() );
    MatrixSimpleInterpolation msi;
    for(unsigned i=0;i<m_left.node_list.size();++i) {
        if ( not find( m_right.elem_list, msi, m_left.node_list[i].pos, A.row( i ) ) )
            throw FindEnglobingElementAndReturnInterpolationException();
    }
}


} // namespace LMT

#endif // MESH_INTERPOLATION_H
