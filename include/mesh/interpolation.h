#ifndef MESH_INTERPOLATION_H
#define MESH_INTERPOLATION_H

namespace LMT {

struct FindEnglobingElementAndReturnInterpolationException {
};

template<class TRES,class NameDM>
struct FindEnglobingElementAndReturnInterpolation {
    template<class TE>
    bool operator()( const TE &elem, const typename TE::Pvec &pos ) {
        Vec<typename TE::T,TE::nb_var_inter> var_inter;
        get_var_inter( elem, pos, var_inter, 1e-4 );
        if ( var_inter_is_inside( typename TE::NE(), var_inter, 1e-6 ) ) {
            TRES val[TE::nb_nodes];
            ExtractDM<NameDM> extract_NameDM_value;
            for(int i=0;i<TE::nb_nodes;++i)
                val[ i ] = extract_NameDM_value( *elem.node(i) );
            get_interp( typename TE::NE(), Nodal(), var_inter, val, res );
            return true;
        }
        return false;
    }
    TRES res;
};

template<class Carac,unsigned nvi_to_subs,unsigned skin,class NameDM,class Pvec>
typename MeshAncestor<Carac,nvi_to_subs,skin>::TNode::template SubTypeByName0<NameDM>::TT interpolation( const MeshAncestor<Carac,nvi_to_subs,skin> &m, NameDM, const Pvec &pos ) {
    typedef MeshAncestor<Carac,nvi_to_subs,skin> TM;
    typedef FindEnglobingElementAndReturnInterpolation<typename TM::TNode::template SubTypeByName0<NameDM>::TT,NameDM> Fel;
    Fel fel;
    if ( not find( m.elem_list, fel, pos ) )
        throw FindEnglobingElementAndReturnInterpolationException();
    return fel.res;
}

} // namespace LMT

#endif // MESH_INTERPOLATION_H
