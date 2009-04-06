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


} // namespace LMT

#endif // MESH_INTERPOLATION_H
