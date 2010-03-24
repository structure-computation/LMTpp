#ifndef UPDATE_INTERFACES_H
#define UPDATE_INTERFACES_H

namespace LMT {

namespace UpdateInterfacesNS {
    struct GetSkinE {
        template<class TE,class TM,class RES> void operator()( TE &e, TM &m, RES &res ) const {
            if ( m.get_parents_of( e ).size() == 1 )
                res.push_back( &e );
        }
    };
}

template<class Carac>
void update_interfaces( SubStructuredProblem<Carac> &sspb ) {
    typedef typename SubStructuredProblem<Carac>::TM TM;
    typedef typename TM::template SubMesh<1>::T::TElemList::TListPtr TES;
    
    Vec<Splitted<TES,8> > skin_ptr;
    for(unsigned i=0;i<sspb.sub_structures.size();++i) {
        sspb.sub_structures[i].mesh.update_skin();
        apply( sspb.sub_structures[i].mesh.sub_mesh(Number<1>()).elem_list, UpdateInterfacesNS::GetSkinE() ,sspb.sub_structures[i].mesh.sub_mesh(Number<1>()), *skin_ptr.new_elem() );
        for(unsigned j=0;j<i;++j) {
        }
    }
}


}

#endif // UPDATE_INTERFACES_H
